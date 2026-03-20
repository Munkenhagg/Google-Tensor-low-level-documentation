#include "common.h"

libusb_context *ctx = NULL;
libusb_device_handle *dev = NULL;
int r;
int transferred;
unsigned char outbuf[512];
unsigned char inbuf[512];

void recieveBytes() {
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
}
void sendBytes() {
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
}
void lusbExit() {
    libusb_release_interface(dev, 0);
    libusb_close(dev);
    libusb_exit(ctx);
}
void lusbDeviceAttach() {
    printf("Opening device %04x:%04x\n", VID, PID);
    dev = libusb_open_device_with_vid_pid(ctx, VID, PID);
    if (!dev) {
        printf("Device not found\n");
        exit(1);
    }
    if (libusb_kernel_driver_active(dev, 0) == 1) {
        printf("Detaching kernel driver...\n");
        libusb_detach_kernel_driver(dev, 0);
    }
    printf("Claiming interface 0\n");
    libusb_claim_interface(dev, 0);
}
void lusbInit() {
    printf("Initializing libusb...\n");
    r = libusb_init(&ctx);
    if (r < 0) {
        printf("libusb init failed\n");
        exit(1);
    }
}
void command2packet(int argc, char *argv[]) {
    for (int i = 1; i < argc && i <= 64; i++) {
        outbuf[i-1] = (unsigned char)strtol(argv[i], NULL, 16);
    }
}
void mainInit() {
    memset(outbuf, 0, sizeof(outbuf));
    memset(inbuf, 0, sizeof(inbuf));
}