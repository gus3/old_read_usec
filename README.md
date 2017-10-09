# read_usec
Reading the microsecond timer on a Raspberry Pi

To build the C version, simply type "make". You will need
the firmware support files for your model under /opt/vc.

The Python version runs stand-alone. Be sure to read the
comment on lines 7-9 regarding iobase.

Both versions require root privileges to access /dev/mem.
