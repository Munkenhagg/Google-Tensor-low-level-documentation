# this is what all different BL1 Handshake Responses mean:

- **0x00** - Idle / No response - happens when bootloader is stuck processing it
- **0x01** - STALL - happens when the bootloader tries to, but cant process something.
- **0x04** - RST - bootloader wants to reset the communication. shows a problem. usually seen at handshake 
- **0x06** - ACK - bootloader "acknowledged" what you sent. can be said as success
- **0x15** - NAK - bootloader did not acknowledge what you sent.