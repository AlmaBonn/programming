
#include <stdio.h>
#include <stdlib.h>

/* Eine lokale Funktion, um die Fakultaet zu berechnen */
static int
fakultaet (int n) {

	int i;
	int faku = 1;

	for (i = 1; i <= n; ++i) {

		faku = faku * i;

	}

	return faku;
}

/* Die main-Funktion kann zwei Argumente bearbeiten:
 * Das erste (hier genannt argc) ist die Anzahl
 *    Woerter auf der Kommandozeile (inklusive des Programmnamens)
 * und das zweite ein Array mit genau diesen Woertern.
 */
int
main (int argc, char *argv[]) {

	int n = 0;
	int faku = -1;

	if (argc > 1) {

		n = atoi (argv[1]);

	}

	faku = fakultaet (n);

	printf ("Fakultät von %d ist %d\n", n, faku);

	return 0;
}
