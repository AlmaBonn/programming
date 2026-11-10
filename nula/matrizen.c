
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
/* Output: matrix Ainv = inv (A), Werte werden ueberschrieben */
/* Fehlerfaelle:


 * Rueckgabe: 0 ohne Fehler, negativ sonst
 */
int
invertiere (sma *A, sma *Ainv)
{


  return -1;
}


int
main (int argc, char **argv) {

  double eintraegeA[4] = { 1, 5, 3, 2 };

  sma meinA;
  meinA.m = meinA.n = 2;
  meinA.eintraege = eintraegeA;

  return 0;
}
