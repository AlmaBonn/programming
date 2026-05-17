
#include <stdio.h>

int
main (int argc, char **argv)
{
  int i, j;

  int a, *b;
  int c[3] = { 1, 5, 7 };
  int *d[3];
  int (*e)[3];
  int f[3], g[3], h[3];
  int l[3][3];

  a = 4;
  printf ("Variable a %d, c[] %d %d %d\n", a, c[0], c[1], c[2]);

  b = &a;
  printf ("Variable *b %d\n", *b);

  b = c;
  printf ("Variable *b %d\n", *b);

  b = &c[1];
  printf ("Variable *b %d b[1] %d\n", *b, b[1]);

  b = c + 2;
  printf ("Variable *b %d\n", *b);

  d[0] = &a;
  d[1] = b;
  d[2] = &c[1];
  printf ("Variable *d[] %d %d %d\n", *d[0], *d[1], *d[2]);

  e = &c;
  printf ("Variable (*e)[] %d %d %d\n", e[0][0], e[0][1], (*e)[2]);

  d[0] = f;
  d[1] = g;
  d[2] = h;
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      l[i][j] = d[i][j] = 2 * i + 13 * (j + 1);
    }
  }
  printf ("Variable f[] %d %d %d\n", f[0], f[1], f[2]);
  printf ("Variable g[] %d %d %d\n", g[0], g[1], g[2]);
  printf ("Variable h[] %d %d %d\n", h[0], h[1], h[2]);

  printf ("Variable l[2][] %d %d %d\n", l[2][0], l[2][1], l[2][2]);

  return 0;
}

