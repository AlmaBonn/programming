
/* Berechne die Fibonacci-Zahlen (höchst suboptimal) über Rekursion */

/* Dieses Programm ist um ein Vielfaches länger als der Pseudocode,
   da wir verschiedene praktische Sicherheitsüberprüfungen hinzufügen */

/* Kontextvariable fuer die momentane Rekursionstiefe */
static int rtiefe;

/* Wir halten für eine Berechnung fest, ob die Maximaltiefe erreicht wurde */
static int reicht;

/* Wir brechen die Berechnung ab, wenn wir die Maximaltiefe erreichen */
static const int rtimax = 100;

/* Ein 32-Bit-Wort erlaubt Zahlen bis über 4 Milliarden */
uint32_t
fibonacci (int i) {

        /* Zwischenergebnis */
        uint32_t fibo;

        /* pruefe korrekten Funktionsaufruf zur Sicherheit */
        if (i < 0) {
                Serial.println ("Negativer Index ist nicht erlaubt");
                return 0; /* kehrt sofort mit Wert 0 aus der Funktion zurück */
        }

        /* begrenze die Rekursionstiefe */
        if (reicht || rtiefe + 1 >= rtimax) {
                Serial.println ("Maximale Rekursionstiefe erreicht");
                reicht = 1;
                return 0;
        }

        /* andernfalls berechnen wir das Ergebnis direkt */
        if (i == 0 || i == 1) {
                return 1;
        }

        /* Wer kommen hier nur an, wenn bisher kein return aufgerufen wurde */

        /* Rufe Rekursion auf und zaehle dabei unseren eigenen Aufruf mit */
        ++rtiefe;
        fibo = fibonacci (i - 1) + fibonacci (i - 2);

        /* und geben das Ergebnis zurück und neutralisieren die Tiefe */
        --rtiefe;
        return fibo;
}

void
setup (void)
{
        uint32_t fibo;

        /* initialisieren der Konsolenausgabe */
        Serial.begin (9600);
        while (!Serial);

        /* berechne verschiedene Fibonacci-Zahlen per Rekursion */
        reicht = 0;
        for (i = 0; !reicht; ++i) {

                /* die Tiefe initialisieren wir für jede Fibonacci-Zahl neu */
                rtiefe = 0;
                fibo = fibonacci (i);
                /* wenn wir korrekt programmiert haben, ist rtiefe wieder 0 */

                Serial.print ("Fibonacci-Zahl ");
                Serial.print (i);
                if (!reicht) {
                        /* die Berechnung lief bis zum Ende durch */
                        Serial.print (" ist korrekterweise ");
                }
                else {
                        /* wir haben mit maximaler Tiefe abgebrochen */
                        Serial.print (" ist vermutlich falsch mit ");
                }
                Serial.println (fibo);
        }
}

void
loop (void)
{
        /* mache hier nichts */
}
