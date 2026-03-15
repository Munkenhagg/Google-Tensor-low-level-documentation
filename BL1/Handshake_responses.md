# Handshake Responses

## this is what all different BL1 Handshake Responses mean

- **0x00** - Idle / No response - happens when bootloader is stuck processing it
- **0x01** - STALL - happens when the bootloader tries to, but cant process something.
- **0x04** - RST - bootloader wants to reset the communication. shows a problem. usually seen at handshake
- **0x06** - ACK - bootloader "acknowledged" what you sent. can be said as success
- **0x15** - NAK - bootloader did not acknowledge what you sent.
- **Read failed -7** - ? - probably expecting more data, looking into it right now

## these are the handshake responses i have gotten from sending different packets using the send_packet.c script

- **01 00 00 00**: 0x06 - seems to be a way to test connection. like a ping
- **01 01 00 00**: 0x06 - 01 seems to allow arguments.
- **02 00 00 00**: none, read failed -7. timeout - i think it is asking for more data like total size and bl2.img. working on finding out
- **03 00 00 00**: 0x15
- **04 00 00 00**: 0x06 - maybe retry boot? no idea yet
- **05 00 00 00**: 0x15
- **06 00 00 00**: 0x15
- **02 00 00 00** then immedietly **00 30 00 00** when it finishes: two read timeouts. could it maybe be expecting 02 00 00 00 then the full bl2.img. i have tried 02 00 00 00 then sending 64 byte chunks and immedietly send fail. same happens when uploading bl1 with bs under 512 tho. it might also expect 512 byte chunks
