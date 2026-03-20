#include "common.h"

int main(int argc, char *argv[]) {
    mainInit();
    lusbInit();
    lusbDeviceAttach();
    command2packet(argc, argv);
    sendBytes();
    lusbExit();
    return 0;
}