
/*
  Lese von der Standardeingabe beliebig viele Pärchen
  (t_i, b_i) und berechne eine lineare Regression.
 */

#include <stdio.h>

int
main (int argc, char **argv) {

  int m;
  float ti, bi;
  float det, idet;
  float a, c;  /* Suche b(t) =? a*t + c */

  float sum_t, sum_b, sum_tt, sum_tb;

  m = 0;
  sum_t = sum_b = sum_tt = sum_tb = 0.;
  for (;;) {

    int retval = scanf ("%g %g", &ti, &bi);
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

  det = m * sum_tt - sum_t * sum_t;

  if (det <= 0.) {
    printf ("Insufficient data\n");
    return 1;
  }
  idet = 1. / det;

  c = idet * (sum_b * sum_tt - sum_t * sum_tb);
  a = idet * (m * sum_tb - sum_t * sum_b);

  printf ("Wir haben at + c mit a = %g, c = %g\n", a, c);

  return 0;
}
