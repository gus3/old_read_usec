#! /usr/bin/env python

from mmap import mmap, MAP_SHARED, PROT_READ
from time import sleep
from struct import unpack

# The I/O page is the Linux page containing the 1MHz clock.
# On BCM2835-based boards (original RPi and RPi Zero) the
# I/O page you want is at 0x20003000.
iopage = 0x3f003000

timer_file = open("/dev/mem", "r")
map = mmap(timer_file.fileno(), 4096, MAP_SHARED, PROT_READ, 0, iopage)

def read_timer():
    # the clock itself sits in the 8 bytes, offset 4
    return unpack('Q', map[4:12])[0]

new = read_timer()
sleep(1)

while not False:
    old, new = new, read_timer()
    print ('Timer diff = ', new - old)
    sleep(1)

