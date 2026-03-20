#include "common.h"

int main(int argc, char *argv[]) {
    mainInit();
    lusbInit();
    lusbDeviceAttach();
    command2packet(argc, argv);
    sendBytes();
    printf("Waiting for response...\n");
    recieveBytes();
    lusbExit();
    return 0;
}