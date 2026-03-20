#include "common.h"

int main(int argc, char *argv[]) {
    mainInit();
    lusbInit();
    lusbDeviceAttach();
    printf("Waiting for response...\n");
    recieveBytes();
    lusbExit();
    return 0;
}