
/* Berechne das Inkrement einer B-adischen Zahl. */

#include <stdio.h> /* In dieser Datei ist printf definiert */
#include <stdlib.h> /* In dieser EXIT_SUCCESS */

#define L 4
#define B 5

/* Wir erwarten Input der Laenge L und Output der Laenge L + 1 */
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

static void
run (void) {

    /* Vorsicht: Indexfolge 0, 1, 2, 3 */
    int zahl[L] = { 4, 3, 0, 1 };

    /* Vorsicht: noch undefiniert */
    int resultat[L + 1];

    /* Inkrementiere out-of-place */
    pluseins (zahl, resultat);

}

int
main (void) {
    run ();
    return EXIT_SUCCESS;
}
