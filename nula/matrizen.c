
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
sma *matrix_alloziere (int m, int n)
{
  sma *matr;

  matr = (sma *) malloc (1 * sizeof (sma));
  matr->m = m;
  matr->n = n;
  matr->eintraege = (double *) malloc (m * n * sizeof (double));

  return matr;
}

/* Gebe allozierten Speicher der Struktur wieder frei. */
void matrix_freigeben (sma *matr)
{
  /* Die Einträge freigeben, solange mir sie noch erreichen können. */
  free (matr->eintraege);

  /* Nach dem free ist der ursprüngliche Speicherbereich undefiniert. */
  free (matr);
}

/* Input: matrix A, quadratisch, wird nicht verändert.
 * Output: matrix Ainv = inv (A), Werte werden überschrieben
 *         und muss on input schon A->m x A->n sein.
 *
 * Fehlerfälle:
 *
 *  - Aktuell wird nur eine 2x2 Matrix korrekt bearbeitet.
 *    Andernfalls wird ein Fehler zurückgegeben.
 *  - Eingabe- und Ausgabematrix müssen gleich dimensioniert sein.
 *  - Die Eingabematrix muß invertierbar sein.
 *
 * Rückgabe: 0 ohne Fehler, negativ sonst
 */
int
invertiere (sma *A, sma *Ainv)
{
  double Adet, invdet;

  if (A->m != 2 || A->n != 2) {
    printf ("Falscher Fall: Matrix ist nicht 2x2\n");
    return -1;
  }

  if (Ainv->m != A->m || Ainv->n != A->n) {
    printf ("Programmierfehler: Matrizen ungleich dimensioniert\n");
    return -1;
  }

  Adet = A->eintraege[0] * A->eintraege[3] -
         A->eintraege[1] * A->eintraege[2];
  if (Adet == 0.) {
    printf ("Matrix singulär\n");
    return -1;
  }
  invdet = 1. / Adet;

  Ainv->eintraege[0] = invdet * A->eintraege[3];
  Ainv->eintraege[3] = invdet * A->eintraege[0];
  Ainv->eintraege[1] = -invdet * A->eintraege[1];
  Ainv->eintraege[2] = -invdet * A->eintraege[2];
  return 0;
}

/* Hauptprogramm ignoriert z. Z. seine Kommandozeilen-Argumente */
int
main (int argc, char **argv)
{
  int i;

  /* Eingabewerte für die Matrixeinträge */
  const double eintraegeA[4] = { 1, 5, 3, 2 };

  /* Speicher für die beiden Matrix-Objekte */
  sma *meinA;
  sma *meinInv;

  /* Rückgabewert */
  int result;

  /* Alloziere Eingabematrix */
  meinA = matrix_alloziere (2, 2);

  /* Initialisiere Eingabematrix */
  for (i = 0; i < 2 * 2; ++i) {
    meinA->eintraege[i] = eintraegeA[i];
  }

  /* Initialisiere Ausgabematrix */
  meinInv = matrix_alloziere (2, 2);

  /* Invertiere Matrix und fange Fehlerfälle ab */
  result = invertiere (meinA, meinInv);
  if (result != 0) {
    printf ("Fehler bei der Invertierung\n");
    return EXIT_FAILURE;
  }

  /* Speicher wieder freigeben! */
  matrix_freigeben (meinInv);
  matrix_freigeben (meinA);

  /* Programm lief fehlerfrei durch */
  return EXIT_SUCCESS;
}
