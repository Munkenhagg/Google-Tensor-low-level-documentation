#include "common.h"

int main(void) {
    mainInit();
    lusbInit();
    lusbDeviceAttach();
    printf("Waiting for response...\n");
    recieveBytes();
    lusbExit();
    return 0;
}
