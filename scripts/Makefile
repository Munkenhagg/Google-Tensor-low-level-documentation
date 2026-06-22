CC     = gcc
CFLAGS = -O2 -Wall -Wextra
LIBS   = -lusb-1.0
SRC    = functions.c
OUTD   = out/
ALL    = probe_bl1 read_packet send_packet send_packet_wo

all: $(ALL)

%: %.c $(SRC) $(OUTD)
	$(CC) $(CFLAGS) $@.c $(SRC) -o out/$@ $(LIBS)

clean:
	rm -rf out/

$(OUTD):
	mkdir -p $@
