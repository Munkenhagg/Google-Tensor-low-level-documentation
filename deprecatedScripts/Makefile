CC = gcc
LIBS = -lusb-1.0
TARGETS = send_packet send_packet_wo read_packet probe_bl1

all: $(TARGETS)

%: %.c
	$(CC) $< -o $@ $(LIBS)
