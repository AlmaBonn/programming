
#include "nurfakultaet.h"

/* Eine Funktion, um die Fakultaet zu berechnen, von Index k an. */
static long
fakultaetabk (int n, int k) {

	int i;
	long faku = 1;

	for (i = k; i <= n; ++i) {

		faku *= i;

	}

	return faku;

}

long
fakultaet (int n) {

	return fakultaetabk (n, 2);
}

long
nueberk (int n, int k) {

	if (n < 0) return -1;
	if (k < 0 || n < k) return 0;

	return fakultaetabk (n, k + 1) / fakultaet (n - k);
}
