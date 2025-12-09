
/* Wir approximieren die Exponentialfunktion für kleine Argumente */

#include <math.h> /* wir verwendend mathematische Funktionen */
#include <stdio.h> /* wir verwenden Funktionen zum Ausgeben */
#include <stdlib.h> /* wir verwenden EXIT_SUCCESS statt 0 */

static void
test_epower (double x) {

  int p, j;
  double laste = 1.;
  double exact = exp (x);

  /* wir testen eine ganze Reihe von Iterationen */
  for (p = 0; p <= 10; ++p) {

    double q;
    double xp;
    double erro;

    printf ("For x %8.6g iter %2d", x, p);

    /* bestimme x' / 2**p und Reihenentwicklung von e(x') */
    xp = x * (1./1024.) * (1 << (10 - p));
    q =  1. + xp *
        (1. + xp * (1./2.) *
        (1. + xp * (1./3.) *
        (1. + xp * (1./4.) )));
    for (j = 0; j < p; ++j) { q *= q; }

    /* bestimme relativen Fehler und Faktor zur vorherigen Iteration */
    erro = fabs (q / exact - 1.);
    printf (" res %8.6f exact %.3f error %8.3g fact %4.1f\n",
            q, exact, erro, laste / erro);
    laste = erro;
  }
}

static void
run_epower (void) {
  double x;

  /* bis auf Weiteres: hardcode Testwert von x */
  x = log (8.);

  test_epower (x);
}

int
main (void)
{
        /* rufe unser eigentliches Programm auf */
        run_epower ();

        /* der Rueckgabewert des Programms an die Shell */
        return EXIT_SUCCESS;
}
