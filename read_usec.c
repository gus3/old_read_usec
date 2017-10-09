#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <bcm_host.h>
#include "read_usec.h"

#define ST_BASE (bcm_host_get_peripheral_address()+0x3000)
#define TIMER_OFFSET (4)

unsigned long long int read_usec(void) {
	static int fd;
	static void *st_base;

	if (!fd) {
		if (-1 == (fd = open("/dev/mem", O_RDONLY))) {
			fprintf(stderr, "open() failed in read_usec() Are you root?.\n");
			exit(255);
		}
		if (MAP_FAILED == (st_base = mmap(NULL, 4096, PROT_READ, MAP_SHARED, fd, ST_BASE))) {
			fprintf(stderr, "mmap() failed in read_usec().\n");
			exit(254);
		}
	}

	return *(long long int *)((unsigned char *)st_base + TIMER_OFFSET);
}
