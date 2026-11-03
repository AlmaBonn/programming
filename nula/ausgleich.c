
/*
  Lese von der Standardeingabe beliebig viele Pärchen
  (t_i, b_i) und berechne eine lineare Regression.
 */

#include <stdio.h>

int
main (int argc, char **argv) {

  int n;
  float ti, bi;

  do {

    n = scanf ("%g %g", &ti, &bi);

    printf ("Eingabe mit %d: %f %f\n", n, ti, bi);

  } while (n == 2);

  return 0;
}
