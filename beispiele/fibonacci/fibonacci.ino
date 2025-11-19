
/* Berechne die Fibonacci-Zahlen (höchst suboptimal) über Rekursion */

/* Dieses Programm ist um ein Vielfaches länger als der Pseudocode,
   da wir verschiedene praktische Sicherheitsüberprüfungen hinzufügen */

/* Kontextvariable fuer die momentane Rekursionstiefe */
int rtiefe;

/* Wir halten für eine Berechnung fest, ob die Maximaltiefe erreicht ist */
int reicht;

/* Wir brechen die Berechnung ab, wenn wir die Maximaltiefe erreichen */
const int rtimax = 100;

/* Ein 32-Bit-Wort erlaubt Zahlen bis über 4 Milliarden */
uint32_t fibonacci (int i) {

        /* Zwischenergebnis */
        uint32_t fibo;

        /* pruefe korrekten Funktionsaufruf zur Sicherheit */
        if (i < 0) {
                Serial.println ("Negativer Index ist nicht erlaubt");
                /* kehrt sofort mit Wert 0 aus der Funktion zurück */
                return 0;
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

        /* wir kommen hier nur an, wenn bisher kein return aufgerufen
           wurde */

        /* zaehle unseren eigenen Aufruf und gehe dann in die Rekursion */
        ++rtiefe;
        /* auch andere Rekursionsvorschriften sollten immer zwischen
           ++rtiefe und --rtiefe implementiert werden */
        fibo = fibonacci (i - 1) + fibonacci (i - 2);

        /* gebe das Ergebnis zurück und neutralisiere unseren Aufruf */
        --rtiefe;
        return fibo;
}

void setup (/* hier könnte void stehen, die Arduino IDE gibt das aber
               bei der setup-Funktion standardmäßig nicht vor */) {
        int i;
        uint32_t fibo;
        unsigned long time_start, time;

        /* warte drei Sekunden zur Sicherheit, siehe
           https://github.com/AlmaBonn/programming/wiki/
             Wichtige-Hinweise-zum-Mikrochip#delay */
        delay (3000);

        /* initialisieren der Konsolenausgabe */
        Serial.begin (9600);
        while (!Serial);

        /* berechne verschiedene Fibonacci-Zahlen per Rekursion */
        reicht = 0;
        for (i = 0; !reicht; ++i) {

                /* rtiefe initialisieren wir für jede Fibonacci-Zahl neu */
                rtiefe = 0;
                /* Laufzeitmessung in Mikrosekunden */
                time_start = micros ();
                fibo = fibonacci (i);
                /* wenn wir korrekt programmiert haben, ist rtiefe
                   wieder 0 */
                /* solange die Differenz als unsigned long darstellbar ist,
                   können wir die Zeit korrekt messen, also bis zu ca.
                   70 Minuten */
                time = micros () - time_start;

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
                Serial.print (fibo);
                Serial.print (" und hat ");
                Serial.print (time);
                Serial.println (" Mikrosekunden benötigt.");
        }
}

void loop (/* hier könnte void stehen, die Arduino IDE gibt das aber
              bei der loop-Funktion standardmäßig nicht vor */) {
        /* mache hier nichts */
}
