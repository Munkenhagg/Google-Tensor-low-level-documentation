#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libusb-1.0/libusb.h>

#define VID 0x18d1
#define PID 0x4f00

#define EP_OUT 0x02
#define EP_IN  0x81
#define CHUNK_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s bl2.img\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if (!f) {
        perror("fopen");
        return 1;
    }

    libusb_context *ctx = NULL;
    libusb_device_handle *dev = NULL;
    int r, transferred;

    unsigned char buf[CHUNK_SIZE];
    memset(buf, 0, sizeof(buf));

    printf("Initializing libusb...\n");
    r = libusb_init(&ctx);
    if (r < 0) { printf("libusb init failed\n"); return 1; }

    dev = libusb_open_device_with_vid_pid(ctx, VID, PID);
    if (!dev) { printf("Device not found\n"); return 1; }

    if (libusb_kernel_driver_active(dev, 0) == 1) {
        printf("Detaching kernel driver...\n");
        libusb_detach_kernel_driver(dev, 0);
    }

    printf("Claiming interface 0\n");
    libusb_claim_interface(dev, 0);

    printf("Sending BL2 in %d-byte chunks...\n", CHUNK_SIZE);

    size_t n;
    while ((n = fread(buf, 1, CHUNK_SIZE, f)) > 0) {
        r = libusb_bulk_transfer(dev, EP_OUT, buf, n, &transferred, 5000);
        if (r != 0 || transferred != n) {
            printf("Send failed: %d, sent %d/%zu bytes\n", r, transferred, n);
            break;
        }
        printf(".");
        fflush(stdout);
    }

    printf("\nFinished sending BL2\n");
    printf("Reading...\n")
    r = libusb_bulk_transfer(dev, EP_IN, buf, sizeof(buf), &transferred, 5000);
    if (r == 0) {
        printf("BL1 responded with %d bytes:\n", transferred);
        for (int i = 0; i < transferred; i++) printf("%02X ", buf[i]);
        printf("\n");
    } else {
        printf("No response or read failed: %d\n", r);
    }

    libusb_release_interface(dev, 0);
    libusb_close(dev);
    libusb_exit(ctx);
    fclose(f);

    return 0;
}