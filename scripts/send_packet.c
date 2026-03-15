#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libusb-1.0/libusb.h>

#define VID 0x18d1
#define PID 0x4f00

#define EP_OUT 0x02
#define EP_IN  0x81

// COMPILE USING sudo gcc probe_bl1.c -o probe_bl1 -lusb-1.0

int main(int argc, char *argv[]) {
    libusb_context *ctx = NULL;
    libusb_device_handle *dev = NULL;
    int r;
    int transferred;

    unsigned char outbuf[512];
    unsigned char inbuf[512];

    memset(outbuf, 0, sizeof(outbuf));
    memset(inbuf, 0, sizeof(inbuf));

    printf("Initializing libusb...\n");
    r = libusb_init(&ctx);
    if (r < 0) {
        printf("libusb init failed\n");
        return 1;
    }

    printf("Opening device %04x:%04x\n", VID, PID);
    dev = libusb_open_device_with_vid_pid(ctx, VID, PID);
    if (!dev) {
        printf("Device not found\n");
        return 1;
    }
    if (libusb_kernel_driver_active(dev, 0) == 1) {
        printf("Detaching kernel driver...\n");
        libusb_detach_kernel_driver(dev, 0);
    }
    printf("Claiming interface 0\n");
    libusb_claim_interface(dev, 0);

    // Convert cmd args into packet
    for (int i = 1; i < argc && i <= 64; i++) {
        outbuf[i-1] = (unsigned char)strtol(argv[i], NULL, 16);
    }
    printf("Sending probe packet...\n");

    r = libusb_bulk_transfer(
        dev,
        EP_OUT,
        outbuf,
        64,
        &transferred,
        2000
    );

    if (r != 0) {
        printf("Send failed: %d\n", r);
    } else {
        printf("Sent %d bytes\n", transferred);
    }

    printf("Waiting for response...\n");

    r = libusb_bulk_transfer(
        dev,
        EP_IN,
        inbuf,
        sizeof(inbuf),
        &transferred,
        2000
    );

    if (r == 0) {
        printf("Received %d bytes\n", transferred);

        for (int i = 0; i < transferred; i++) {
            printf("%02X ", inbuf[i]);
        }
        printf("\n");
    } else {
        printf("Read failed: %d\n", r);
    }

    libusb_release_interface(dev, 0);
    libusb_close(dev);
    libusb_exit(ctx);

    return 0;
}