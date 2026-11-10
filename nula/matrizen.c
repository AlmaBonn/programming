
#include <stdio.h>


struct s_matrix
{
  int m;
  int n;

  /* Array mit m * n eintraegen */
  double *eintraege;
};

/* Abkuerzung: typedef <alter Typ> <neuer Name> */
typedef struct s_matrix sma;


/* Input: matrix A, quadratisch, wird nicht veraendert */
/* Output: matrix Ainv = inv (A), Werte werden ueberschrieben
           und muss on input schon A->m x A->n sein */
/* Fehlerfaelle:


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


int
main (int argc, char **argv) {

  double eintraegeA[4] = { 1, 5, 3, 2 };
  double eintraegeInv[4];

  sma meinA;
  sma meinInv;
  int result;

  meinA.m = meinA.n = 2;
  meinA.eintraege = eintraegeA;

  meinInv.m = meinInv.n = 2;
  meinInv.eintraege = eintraegeInv;

  result = invertiere (&meinA, &meinInv);
  if (result != 0) {
    printf ("Fehler Invertierung\n");
    return 1;
  }

  return 0;
}
