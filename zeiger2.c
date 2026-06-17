
#include <stdio.h>


int
main (int argc, char *argv[])
{
  int a;
  int *b;
  int c[3];
  int d[3][3];
  int **e;

  a = 4;
  printf ("a ist %d\n", a);

  b = &a;
  printf ("*b ist %d\n", *b);

  c[0] = 3;
  c[1] = 5;
  c[2] = 8;
  printf ("c ist %d %d %d\n", c[0], c[1], c[2]);

  b = c;
  printf ("*b ist %d\n", *b);

  d[1][2] = 9;
  printf ("d12 ist %d\n", d[1][2]);

  d[0][0] = 18;
  b = d[0];
  b[1] = 5;
  printf ("d01 ist %d\n", d[0][1]);

  e = &b;
  printf ("**e ist %d\n", e[0][0]);


  return 0;
}
