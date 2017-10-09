#include <stdio.h>
#include <unistd.h>
#include "read_usec.h"

int main(int argc, char *argv[]) {
	int i;
	unsigned int t1, t2;

	t2 = read_usec();
	for (i = 1; i < 10; i++) {
		t1 = t2;
		sleep(1);
		t2 = read_usec();
		printf("%d\n", t2 - t1);
	}
	return 0;
}
