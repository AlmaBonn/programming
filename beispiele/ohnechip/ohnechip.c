
/* Demo zu for-Schleifen in Standard-C
   ===================================

 * Dieses Programm variiert unser for-Schleifen-Beispiel so,
 * dass es mit einem beliebigen C-Compiler uebersetzt werden kann.
 * Alle Spezialisierungen auf die Arduino-Umgebung sind entfernt.
 * Die Sprache C an sich ist unveraendert.
 *
 * Kommentare koennen alle Zeichen enthalten, insbesondere *.
   Oder sie enthalten auch mal keine Sternchen.
 *
 * Die Einrueckung durch Leerzeichen ist in C irrelevant.
 * Sie dient allein dem Menschen zur Uebersicht.
 * Es gibt eine Vielfalt an Konventionen.
 */

/* Dieses Programm uebersetzen Sie mit dem gcc-Compiler wie folgt:

     gcc -Wall -Wextra -o ohnechip ohnechip.c

   Wahlweise können Sie das beigefügte `Makefile` ausnutzen, indem Sie
   auf der Kommandozeile `make` eintippen, siehe unsere Wikiseite dazu.
   Durch die `-W`-Optionen aktivieren Sie eine grosse Menge an Warnungen.
   Sie lassen das erzeugte Programm laufen mit

     ./ohnechip
 */

/* Die printf-Funktion ist sehr maechtig und flexibel.
   Im Wesentlichen ersetzt sie in einer Zeichenkette bestimmte
   Sequenzen (beginnend mit %) durch den Wert einer Variablen.
   Beliebt sind %d fuer int und %s fuer Zeichenketten-Variablen.
   Siehe die man-Page dazu, die Sie sich anzeigen koennen mit

     man 3 printf

 */
#include <stdio.h> /* wir verwenden Funktionen zum Ausgeben */
#include <stdlib.h> /* wir verwenden EXIT_SUCCESS statt 0 */

/* diese Funktion ist static und damit nur in dieser Datei sichtbar */
static void
run_forschleife (void) {

        /* Zaehlvariablen ohne besondere Anforderungen
           nennt man gerne i, j, k, l, das ist aber nicht vorgegeben */
        /* Sie koennen in C Variablen nennen, wie sie wollen, solange diese
           - mit einem Buchstaben oder Unterstrich _ beginnen
           - alle folgenden Zeichen ein Buchstabe, eine Zahl oder _ sind.
         */
        int i;

        /*************************************/
        printf ("Erstes for-Beispiel\n"); /* '\n' ist ein Zeilenumbruch */
        /*************************************/

        for (i = 0; /* der erste der drei Ausdrücke laeuft vor Beginn */
             i < 7; /* der zweite wird vor jeder Iteration ausgewertet
                       und beendet die Schleife, wenn er false ist, das
                       bedeutet, hinter ihren Körper zu springen. */
             i = i + 1 /* der dritte Ausdruck laeuft nach jeder Iteration,
                          danach geht es weiter mit dem zweiten */)
        { /* dies ist der Schleifenkoerper, den wir solange ausfuehren,
             wie der zweite Ausdruck im for-Konstrukt wahr ist */

                /* Variable i zum drucken und dann einen Zeilenumbruch */
                printf ("Anfang Schleifenkoerper mit Zaehler i = %d\n", i);
        }

        /* was ist der Wert von i nach Ende der Schleife? */
        printf ("Nach der Schleife ist i = %d\n", i);

        /**************************************/
        printf ("Zweites for-Beispiel\n");
        /**************************************/

        /* Es ist erlaubt, Ausdrücke im for-Konstrukt wegzulassen */
        for (; i < 4; ) {
                /* da noch i >= 4 ist, wird dieser Block nicht ausgefuhrt */
                printf ("Dies darf nicht erscheinen\n");
        }

        /* Wir ueberspringen jetzt bestimmte Zaehler, alles ist erlaubt */
        for (i = 3; i < 17; i = i + 5) {
                printf ("Anfang Schleifenkoerper mit Zaehler i = %d\n", i);
        }
        printf ("Nach der Schleife ist i = %d\n", i);

        /**************************************/
        printf ("Drittes for-Beispiel\n");
        /**************************************/

        /* Wir verwenden unsere eigene Kontroll-Logik */
        /* Hier verwenden wir zwei reservierte Woerter in C:
           'continue' springt direkt zum dritten Ausdruck im for-Konstrukt.
                      Danach geht es wie sonst auch weiter mit der
                      Ueberpruefung der zweiten Bedingung.
           'break' beendet die Schleife sofort und springt hinter den Koerper.
         */
        for (i = 6;;) {
                printf ("Anfang Schleifenkoerper mit Zaehler i = %d\n", i);

                if (i < 9) {
                        i = i + 1; /* erhoehe um eins */
                        continue; /* springt zum dritten Ausdruck im for */
                }
                if (i < 14) {
                        i = i + 3; /* erhoehe nun um drei */
                        continue; /* springt zum dritten Ausdruck im for */
                }
                i = i + 4; /* andernfalls erhoehe um vier */

                /* eine Abbruchbedingung brauchen wir noch */
                if (i >= 29) {
                        break; /* springt sofort hinter den Schleifenkoerper */
                }

                /* wie immer geht es von hier zum dritten Ausdruck im for */
        }
        printf ("Nach der Schleife ist i = %d\n", i);
}

int
main (void)
{
        /* rufe unser eigentliches Programm auf */
        run_forschleife ();

        /* der Rueckgabewert des Programms an die Shell */
        return EXIT_SUCCESS;
}
