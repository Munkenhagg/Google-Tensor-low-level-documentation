# Here is my progress on reverse engineering the BL1 protocol

- I am able to send "command" packets to it using the [probe_bl1 script](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/scripts/probe_bl1.c) which also works with my new [script which sends the commandline arguments as the packet](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/scripts/send_packet.c). see [Handshake Responses](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/BL1/Handshake_responses.md) for more information

i realized sending 02 00 00 00 seems to put the bootloader in a waiting state. it could be wanting the raw bl2.img or maybe a size?

when i upload BL1, /dev/ttyACM0 still exists after. but i noticed that when i send 02 00 00 00 using my new [write only tool](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/scripts/send_packet_wo.c)(doesnt read EP 1 IN, just sends the packet) it disappears forever until i release the power button. 02 00 00 00 must put it in some sort of dowwnload mode state
