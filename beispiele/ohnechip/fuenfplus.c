
/* Berechne das Inkrement einer B-adischen Zahl */

#include <stdio.h> /* In dieser Datei ist printf definiert */
#include <stdint.h> /* Unsigned-Typen fester Bitbreite */
#include <stdlib.h> /* In dieser EXIT_SUCCESS */

/* Breite der Eingabezahl in Stellen */
#define L 4

/* Wir rechnen im B-adischen System */
#define B 5

/* Wir erwarten Input der Breite L und Output der Breite L + 1 */
static void
pluseins (const int input[], int output[])
{
    int i;
    int erg;
    int uebertrag = 1;

    for (i = 0; i < L; ++i) {
        erg = input[i] + uebertrag;
        if (erg >= B) {
            output[i] = 0;
            uebertrag = 1;
        }
        else {
            output[i] = erg;
            uebertrag = 0;
        }
    }
}

/* Wir erwarten Input mit parametrisierter Breite */
static uint32_t
hornerschema (const int input[], int breite)
{
    int i;
    uint32_t horner = 0;

    /* Wir verschenken eine Multiplikation mit 0 fuer einfachen Code */
    for (i = 0; i < breite; ++i) {
        horner = B * horner + input[i];
    }
    return horner;
}

static void
run (void) {

    /* Vorsicht: Indexfolge 0, 1, 2, 3 */
    int zahl[L] = { 4, 3, 0, 1 };

    /* Vorsicht: noch undefiniert */
    int resultat[L + 1];

    uint32_t wertalt, wertneu;

    /* Inkrementiere out-of-place */
    pluseins (zahl, resultat);

    /* Verifiziere die Rechnung */
    wertalt = hornerschema (zahl, L);
    wertneu = hornerschema (resultat, L + 1);
}

int
main (void) {
    run ();
    return EXIT_SUCCESS;
}
