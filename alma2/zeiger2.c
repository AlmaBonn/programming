
/* as usual prepare for printing console output */
#include <stdio.h>

int
main (int argc, char *argv[])
{
  int a;
  int *b;
  int c[3];
  int d[3][3];
  int **e;

  /* a regular variable with implicit memory location */
  a = 4;
  printf ("a ist %d\n", a);

  /* b is assigned the memory address of the variable a */
  /* The address is obtained with the operator & */
  b = &a;
  printf ("*b ist %d\n", *b);

  /* An array variable is a pointer to the first element */
  c[0] = 3;
  c[1] = 5;
  c[2] = 8;
  printf ("c ist %d %d %d\n", c[0], c[1], c[2]);

  /* One pointer variable is assigned to another */
  /* The variable pointed to is obtained with the operator * */
  b = c;
  printf ("*b ist %d\n", *b);

  /* Each d[i] is an array of length 3, thus a pointer */
  d[1][2] = 9;
  printf ("d12 ist %d\n", d[1][2]);

  /* One pointer is assigned to another */
  /* A pointer can be reassigned to another array positien */
  d[0][0] = 18;
  b = d[0];
  b[1] = 5;
  printf ("d01 ist %d\n", d[0][1]);

  /* Pointers are memory locations that store an address */
  /* The address of this location is a pointer to a pointer */
  e = &b;
  printf ("**e ist %d\n", e[0][0]);

  /* cleanly exit the program */
  return 0;
}
