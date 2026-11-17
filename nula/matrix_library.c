
/* Library C-file */
/* Experimentiere mit der Übergabe von Matrizen an Funktionen */

/* Für Datei- und I/O-Funktionen */
#include <stdio.h>

/* Für main-Fehlercodes und malloc, free etc. */
#include <stdlib.h>

#include "matrix_library.h"

/* Alloziere eine Matrix-Struktur vorgegebener Dimensionierung
 * mit allozierten Einträgen (von undefinierten Werten). */
sma *
matrix_allozieren (int m, int n)
{
  sma *matr;

  matr = (sma *) malloc (1 * sizeof (sma));
  matr->m = m;
  matr->n = n;
  matr->eintraege = (double *) malloc (m * n * sizeof (double));

  return matr;
}

/* Gebe allozierten Speicher der Struktur wieder frei. */
void
matrix_freigeben (sma *matr)
{
  /* Die Einträge freigeben, solange mir sie noch erreichen können. */
  free (matr->eintraege);

  /* Nach dem free ist der ursprüngliche Speicherbereich undefiniert. */
  free (matr);
}
