#include <stdio.h>
#include <stdlib.h>

/* Wer demonstrieren in diesem Programm Funktionsvariablen.
   Diese lassen sich genauso in Arrays fassen wie Zahlen. */

/* Ein Schloss, das sich gar nicht öffnen läßt */
static int
oeffnetnicht (int [], int) {
  return 0;
}

/* Ein Schloss öffnet mit (1, 3, 4, 0) */
static int
oeffnet1340 (int c[], int n) {
  static const int oeffnet[4] = { 1, 3, 4, 0 };
  int i;
  if (n != 4) {
    return 0;
  }
  for (i = 0; i < 4; ++i) {
    if (c[i] != oeffnet[i]) { return 0; }
  }
  return 1;
}

/* Definiere alle Testläufe */
#define MAXRINGE 4
#define NTESTS 3
static const int N[NTESTS] = { 2, 3, 4 };
static const int B[NTESTS] = { 3, 6, 7 };
static int (*oeffnet[NTESTS]) (int [], int) =
  { oeffnetnicht, oeffnet1340, oeffnet1340 };

/* Das Zahlenschloss hat n Ringe mit je b Ziffern.
   Aufruf mit einem Array der Laenge n, ein Element pro Ring.
   Die Funktionsvariable "oeffnet" testet eine Kombination.

   Gebe 1 zurueck, wenn sich das Schloss oeffnen laesst.
   In diesem Fall enthaelt das Array c die Kombination.
 */
int zahlenschloss (int c[], int n, int b,
                   int (*oeffnet) (int [], int)) {
  int i; /* lokale Zaehlvariable */
  for (i = 0; i < n; ++i) { c[i] = 0; } /* setze erste Kombination */
  for (;; /* wiederhole bis auf Weiteres */) {
    if (oeffnet (c, n)) { return 1; }
    for (i = 0; i < n; ++i) {
      if (++c[i] < b) { break; } /* springe hinter diese Schleife */
      c[i] = 0; /* sonst ist Ring wieder 0 und gehe zum naechsten */
    }
    if (i == n) { /* keine Kombination hat geoeffnet */ return 0; }
  } /* Per Konstruktion gelangt das Programm nie hierhin. */ }

/* Die main-Funktion testet alle vorgegebenen Schlösser. */
int
main (void) {
  int i;
  int c[MAXRINGE];

  printf ("Teste %d verschiedene Schloesser\n", NTESTS);
  for (i = 0; i < NTESTS; ++i) {
    int n = N[i];
    printf ("Test %d mit %d Ziffern: ", i, n);
    if (n > MAXRINGE) {
      printf ("Test %d hat eine ungültige Anzahl Ringe\n", i);
      continue;
    }

    /* rufe den Algorithmus zum Durchprobieren auf */
    if (zahlenschloss (c, n, B[i], oeffnet[i])) {
      char combostring[MAXRINGE + 1];
      int j;
      for (j = 0; j < n; ++j) {
        combostring[j] = '0' + c[j];
      }
      combostring[n] = '\0';
      printf ("Schloss %d oeffnet mit %s\n", i, combostring);
    }
    else {
      printf ("Schloss %d oeffnet nicht\n", i);
    }
  }
  return EXIT_SUCCESS;
}
