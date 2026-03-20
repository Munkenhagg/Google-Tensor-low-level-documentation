#include "common.h"

int main() {
    mainInit();
    lusbInit();
    lusbDeviceAttach();
    outbuf[0] = 0x01;
    outbuf[1] = 0x00;
    outbuf[2] = 0x00;
    outbuf[3] = 0x00;
    sendBytes();
    printf("Waiting for response...\n");
    recieveBytes();
    lusbExit();
    return 0;
}