
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[]) {

	int n = 0;

	if (argc > 1) {

		n = atoi (argv[1]);

	}

	printf ("Fakultät von %d ist y\n", n);


	return 0;
}
