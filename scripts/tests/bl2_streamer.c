#include "common.h"
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
    unsigned char buf[CHUNK_SIZE];
    memset(buf, 0, sizeof(buf));
    lusbDeviceOpen();
    printf("Sending BL2 in %d-byte chunks...\n", CHUNK_SIZE);

    size_t n;
    while ((n = fread(buf, 1, CHUNK_SIZE, f)) > 0) {
        r = libusb_bulk_transfer(dev, EP_OUT, buf, n, &transferred, 5000);
        if (r != 0 || transferred != n) {
            printf("Send failed: %d, sent %d/%zu bytes\n", r, transferred, n);
            break;
        }
        printf("\n");
        fflush(stdout);
    }

    printf("\nFinished sending BL2\n");
    printf("Waiting for response...\n")
    recieveBytes();
    lusbExit();
    fclose(f);

    return 0;
}