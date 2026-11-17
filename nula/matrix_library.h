
#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

/* Library Header-file */
/* Experimentiere mit der Übergabe von Matrizen an Funktionen */

/* Für Datei- und I/O-Funktionen */
#include <stdio.h>

/* Für main-Fehlercodes und malloc, free etc. */
#include <stdlib.h>

/* Wir führen einen user-defined zusammengesetzten Typen ein */
struct s_matrix
{
  int m;
  int n;

  /* Nach unserer Konvention ein Array mit m * n Einträgen */
  double *eintraege;
};

/* Abkürzung: typedef <alter Typ> <neuer Name dafür> */
typedef struct s_matrix sma;

/* Alloziere eine Matrix-Struktur vorgegebener Dimensionierung
 * mit allozierten Einträgen (von undefinierten Werten). */
sma *
matrix_allozieren (int m, int n);

/* Gebe allozierten Speicher der Struktur wieder frei. */
void
matrix_freigeben (sma *matr);

#endif
