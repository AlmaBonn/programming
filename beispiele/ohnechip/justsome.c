
/* Dies ist ein Kommentar.
   Der Compiler ignoriert ihn. */

/* Dieses Beispiel hat keinen besonderen Sinn.
   Es kann jedoch als Vorlage dienen. */

/* Eine C-Besonderheit ist das Einbinden weiterer Dateien */
#include <stdio.h> /* In dieser Datei ist printf definiert */
#include <stdlib.h> /* In dieser EXIT_SUCCESS */

/* Die Formatierung ueber Leerzeichen ist beliebig. */
static int verdoppeln (int a) { return 2 * a; }
int main (void) {
    int wert = 5;
    wert = verdoppeln (wert);
    wert = verdoppeln (3 * wert);
    printf ("Der Wert ist am Ende %d\n", wert);
    return EXIT_SUCCESS;
}
