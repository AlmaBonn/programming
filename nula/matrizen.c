
/* Experimentiere mit der Übergabe von Matrizen an Funktionen */

/* Für Datei- und I/O-Funktionen */
#include <stdio.h>

/* Für main-Fehlercodes */
#include <stdlib.h>

/* Wir führen einen user-defined zusammengesetzten Typen ein */
struct s_matrix
{
  int m;
  int n;

  /* Array mit m * n Einträgen */
  double *eintraege;
};

/* Abkürzung: typedef <alter Typ> <neuer Name dafür> */
typedef struct s_matrix sma;

/* Alloziere eine Matrix-Struktur vorgegebener Dimensionierung,
 * mit allozierten Eintraegen (von undefinierten Werten). */
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
  free (matr->eintraege);
  free (matr);
}

/* Input: matrix A, quadratisch, wird nicht veraendert.
 * Output: matrix Ainv = inv (A), Werte werden überschrieben
 *         und muss on input schon A->m x A->n sein.
 *
 * Fehlerfaelle:
 *
 * Aktuell wird nur eine 2x2 Matrix korrekt bearbeitet.
 * Andernfalls wird ein Fehler zurückgegeben.
 * Eingabe- und Ausgabematrix müssen gleich dimensioniert sein.
 * Die Eingabematrix muß invertierbar seit.
 *
 * Rueckgabe: 0 ohne Fehler, negativ sonst
 */
int
invertiere (sma *A, sma *Ainv)
{
  double Adet, invdet;

  if (A->m != 2 || A->n != 2) {
    printf ("Matrix falsch dimensioniert\n");
    return -1;
  }

  if (Ainv->m != A->m || Ainv->n != A->n) {
    printf ("Programmierfehler: Matrizen ungleich dimensioniert\n");
    return -1;
  }

  Adet = A->eintraege[0] * A->eintraege[3] -
         A->eintraege[1] * A->eintraege[2];
  if (Adet == 0.) {
    printf ("Matrix singulaer\n");
    return -1;
  }
  invdet = 1. / Adet;

  Ainv->eintraege[0] = invdet * A->eintraege[3];
  Ainv->eintraege[3] = invdet * A->eintraege[1];
  Ainv->eintraege[1] = -invdet * A->eintraege[1];
  Ainv->eintraege[2] = -invdet * A->eintraege[2];
  return 0;
}

/* Hauptprogramm ignoriert z. Z. seine Kommandozeilen-Argumente */
int
main (int argc, char **argv)
{

  /* Speicher für die Matrixeinträge */
  double eintraegeA[4] = { 1, 5, 3, 2 };
  double eintraegeInv[4];

  /* Speicher für die Matrix-Metadaten */
  sma meinA;
  sma meinInv;

  /* Rückgabewert */
  int result;

  /* Initialisiere Eingabematrix */
  meinA.m = meinA.n = 2;
  meinA.eintraege = eintraegeA;

  /* Initialisiere Ausgabematrix */
  meinInv.m = meinInv.n = 2;
  meinInv.eintraege = eintraegeInv;

  /* Invertiere Matrix und fange Fehlerfälle ab */
  result = invertiere (&meinA, &meinInv);
  if (result != 0) {
    printf ("Fehler Invertierung\n");
    return EXIT_FAILURE;
  }

  /* Programm lief fehlerfrei durch */
  return EXIT_SUCCESS;
}
