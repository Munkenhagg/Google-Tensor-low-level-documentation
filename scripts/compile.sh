for f in send_packet send_packet_wo read_packet probe_bl1; do
    gcc $f.c -o $f -lusb-1.0 || sudo gcc $f.c -o $f -lusb-1.0
done
#gcc upload_bl2.c -o upload_bl2 -lusb-1.0 | sudo gcc upload_bl2.c -o upload_bl2 -lusb-1.0 # for the future