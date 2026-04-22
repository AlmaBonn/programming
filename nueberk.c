
/* Dieses Programm soll n ueber k berechnen. */

#include <stdio.h>
#include <stdlib.h>

/* Eine Funktion, um die Fakultaet zu berechnen */
long
fakultaet (int n);

static long
nueberk (int n, int k) {

	return fakultaet (n) /
	       (fakultaet (k) * fakultaet (n - k));
}

/* Die main-Funktion kann zwei Argumente bearbeiten:
 * Das erste (hier genannt argc) ist die Anzahl
 *    Woerter auf der Kommandozeile (inklusive des Programmnamens)
 * und das zweite ein Array mit genau diesen Woertern.
 */
int
main (int argc, char *argv[]) {

	int n = 0;
	int k = -1;
	long faku = -1;

	if (argc > 1) {
		n = atoi (argv[1]);
	}
	if (argc > 2) {
		k = atoi (argv[2]);
	}

	faku = nueberk (n, k);

	printf ("n ueber k von %d %d ist %ld\n", n, k, faku);

	return 0;
}
