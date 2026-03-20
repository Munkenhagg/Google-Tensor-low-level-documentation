CC     = gcc
CFLAGS = -O2 -Wall
LIBS   = -lusb-1.0
SRC    = functions.c
ALL    = probe_bl1 read_packet send_packet send_packet_wo

all: $(ALL)

%: %.c $(SRC)
	$(CC) $(CFLAGS) $@.c $(SRC) -o $@ $(LIBS)