#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern libusb_context *ctx;
extern libusb_device_handle *dev;
extern int r;
extern int transferred;
extern unsigned char outbuf[512];
extern unsigned char inbuf[512];

void recieveBytes();
void sendBytes();
void lusbExit();
void lusbDeviceAttach();
void lusbInit();
void command2packet(int argc, char *argv[]);
void mainInit();
#endif