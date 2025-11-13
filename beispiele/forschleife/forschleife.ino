
/* Demo zu for-Schleifen
   =====================

 * Die for-Schleife eignet sich besonders zum Hochzaehlen.
 *
 * Dieses Programm enthaelt drei Beispiele.
 * Am besten kopieren Sie es, loeschen, was Sie nicht interessiert,
 * und experimentieren mit dem Rest durch spielerische Modifikation.
 *
 * Kommentare koennen alle Zeichen enthalten, insbesondere *.
   Oder sie enthalten auch mal keine Sternchen.
 *
 * Die Einrueckung durch Leerzeichen ist in C irrelevant.
 * Sie dient allein dem Menschen zur Uebersicht.
 * Es gibt eine Vielfalt an Konventionen.
 */

/* diese Funktion sollte strenggenommen static sein */
void run_forschleife (void) {

        /* Zaehlvariablen ohne besondere Anforderungen
           nennt man gerne i, j, k, l, das ist aber nicht vorgegeben */
        /* Sie koennen in C Variablen nennen, wie sie wollen, solange diese
           - mit einem Buchstaben oder Unterstrich _ beginnen
           - alle folgenden Zeichen ein Buchstabe, eine Zahl oder _ sind.
         */
        int i;

        /*************************************/
        Serial.println ("Erstes for-Beispiel");
        /*************************************/

        for (i = 0; /* der erste der drei Ausdrücke laeuft vor Beginn */
             i < 7; /* der zweite wird vor jeder Iteration ausgewertet
                       und beendet die Schleife, wenn er false ist, das
                       bedeutet, hinter ihren Körper zu springen. */
             i = i + 1 /* der dritte Ausdruck laeuft nach jeder Iteration,
                          danach geht es weiter mit dem zweiten */)
        { /* dies ist der Schleifenkoerper, den wir solange ausfuehren,
             wie der zweite Ausdruck im for-Konstrukt wahr ist */

                /* wir geben eine feste Zeichenkette zum Serial Monitor */
                Serial.print ("Anfang Schleifenkoerper mit Zaehler i = ");

                /* Variable i zum Serial Monitor und einen Zeilenumbruch */
                Serial.println (i);

                /* Verzoegere eine Zehntelsekunde fuers Auge */
                delay (100);
        }

        /* was ist der Wert von i nach Ende der Schleife? */
        Serial.print ("Nach der Schleife ist i = ");
        Serial.println (i);

        /**************************************/
        Serial.println ("Zweites for-Beispiel");
        /**************************************/

        /* Es ist erlaubt, Ausdrücke im for-Konstrukt wegzulassen */
        for (; i < 4; ) {
                /* da noch i >= 4 ist, wird dieser Block nicht ausgefuhrt */
                Serial.println ("Dies darf nicht erscheinen");
        }

        /* Wir ueberspringen jetzt bestimmte Zaehler, alles ist erlaubt */
        for (i = 3; i < 17; i = i + 5) {
                Serial.print ("Anfang Schleifenkoerper mit Zaehler i = ");
                Serial.println (i);
                delay (100);
        }
        Serial.print ("Nach der Schleife ist i = ");
        Serial.println (i);

        /**************************************/
        Serial.println ("Drittes for-Beispiel");
        /**************************************/

        /* Wir verwenden unsere eigene Kontroll-Logik */
        /* Hier verwenden wir zwei reservierte Woerter in C:
           'continue' springt direkt zum dritten Ausdruck im for-Konstrukt.
                      Danach geht es wie sonst auch weiter mit der
                      Ueberpruefung der zweiten Bedingung.
           'break' beendet die Schleife sofort und springt hinter den Koerper.
         */
        for (i = 6;; delay (100)) {
                Serial.print ("Anfang Schleifenkoerper mit Zaehler i = ");
                Serial.println (i);

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
                        /* Interessant: wir eliminieren so das finale Delay */
                }

                /* wie immer geht es von hier zum dritten Ausdruck im for */
        }
        Serial.print ("Nach der Schleife ist i = ");
        Serial.println (i);
}

void setup (/* hier könnte void stehen, die Arduino IDE macht das aber standardmäßig nicht */) {

        /* warte drei Sekunden zur Sicherheit, siehe
           https://github.com/AlmaBonn/programming/wiki/Wichtige-Hinweise-zum-Mikrochip#delay */
        delay (3000);

        /* eingebaute LED aktivieren, sie ist zunaechst aus */
        pinMode (LED_BUILTIN, OUTPUT);

        /* initialisieren und warten auf den Serial Monitor */
        Serial.begin (9600);
        while (!Serial);

        /* rufe unser eigentliches Programm auf */
        run_forschleife ();

        /* wir sind fertig, die Lampe geht an und bleibt dann an */
        digitalWrite (LED_BUILTIN, HIGH);
}

void loop (/* hier könnte void stehen, die Arduino IDE macht das aber standardmäßig nicht */) {
        /* in dieser Funktion machen wir gar nichts */
}
