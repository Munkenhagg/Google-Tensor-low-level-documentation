# these are some weird / interesting behaviours i have found in the BL1 protocol

## the download mode packet

As mentioned in [Handshake Responses](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/BL1/Handshake_responses.md), sending 02 00 00 00 with my [Send Packet script](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/scripts/send_packet.c) seems to put the bootloader in a download mode like state. and it always fails after a packet. for example i can do:
02 00 00 00 - no handshake response
AB AB AB AB - no handshake response yet again
AB AB AB AB - yet no handshake response, but also send failed -7.
same happens when i try [streaming it in 512 or 1024 byte chunks](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/scripts/tests/bl2_streamer.c) after sending 02 00 00 00, always send fail on the second packet. however if i spam AB AB AB AB without sending 02 00 00 00 nothing happens, i just get NAK(handshake response 15). same happens

## 02 then streaming

when i send 02 00 00 00, then stream bl2 in 1024 byte chunks, the BL1 responds with

```output
24+0 records in
24+0 records out
12288 bytes (12 kB, 12 KiB) copied, 0.0820808 s, 150 kB/s

Initializing libusb...
Opening device 18d1:4f00
Detaching kernel driver...
Claiming interface 0
Sending probe packet...
Sent 64 bytes
Waiting for response...
Read failed: -7

Initializing libusb...
Claiming interface 0
Sending BL2 in 1024-byte chunks...
Send failed: -7, sent 0/1024 bytes

Finished sending BL2
BL1 responded with 1 bytes:
06
```

this could mean it wants 2048 byte or more chunks maybe? because the behaviour is similar to the [bootROM behaviour](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/bootROM/sizes.md) when it comes to block sizes
