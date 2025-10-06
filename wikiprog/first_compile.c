#include <stdio.h>
#include <stdlib.h>
static int verdoppeln (int a) { return 2 * a; }
int main (void) {
    int wert = 5;
    wert = verdoppeln (wert);
    wert = verdoppeln (3 * wert);
    printf ("Der Wert ist am Ende %d\n", wert);
    return EXIT_SUCCESS;
}
