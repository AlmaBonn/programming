
/* Dieses Programm soll wuerfeln und ausgeben */

#include <stdio.h>
#include <stdlib.h>

/* Die main-Funktion kann ein Argument bearbeiten:
 * Die Anzahl Wuerfe eines Wuerfels.
 */
int
main (int argc, char *argv[]) {

	int n = 0;
	int i;
	int anzahlen[6];

	if (argc > 1) {

		n = atoi (argv[1]);

	}
	printf ("Wuerfele %d mal\n", n);

	for (i = 0; i < 6; ++i) {
		anzahlen[i] = 0;
        }

	for (i = 0; i < n; ++i) {
		int wuerfelwert = rand () / (RAND_MAX + 1.) * 6;
		if (!(0 <= wuerfelwert && wuerfelwert < 6)) {
			printf ("Hilfe falscher Wert\n");
			exit (1);
		}
                ++anzahlen[wuerfelwert];
	}

	for (i = 0; i < 6; ++i) {
                printf ("ERGEBNIS %d %d\n", i, anzahlen[i]);
	}

	return 0;
}
