# List of endpoints SoC bootROM exposes

- **EP 1 IN**: **bulk** endpoint, for **data**, max **512** bytes at a time - used for the pixel to send data to the host(computer)

- **EP 2 OUT**: **bulk** endpoint, for **data**, max **512** bytes at a time - used for sending data from the host(computer) to the pixel

- **EP 3 IN**: **Interrupt** endpoint, for **data**, max 10 bytes at a time - used for signaling like error codes
