
#include "nurfakultaet.h"

/* Eine Funktion, um die Fakultaet zu berechnen */
long
fakultaet (int n) {

	int i;
	long faku = 1;

	for (i = 2; i <= n; ++i) {

		faku *= i;

	}

	return faku;

}

long
nueberk (int n, int k) {

	return fakultaet (n) /
	       (fakultaet (k) * fakultaet (n - k));
}
