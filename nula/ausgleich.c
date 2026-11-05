
/*
  Lese von der Standardeingabe beliebig viele Pärchen
  (t_i, b_i) und berechne eine lineare Regression.
 */

#include <stdio.h>

int
main (int argc, char **argv) {

  int m;
  int retval;
  float ti, bi;

  float sum_t, sum_b, sum_tt, sum_tb;

  m = 0;
  sum_t = sum_b = sum_tt = sum_tb = 0.;
  for (;;) {

    retval = scanf ("%g %g", &ti, &bi);
    printf ("Eingabe mit %d: %f %f\n", retval, ti, bi);

    if (retval == 2) {

      sum_t += ti;
      sum_b += bi;
      sum_tt += ti * ti;
      sum_tb += ti * bi;

      ++m;

    }
    else {

      break;
    }

  };

  return 0;
}
