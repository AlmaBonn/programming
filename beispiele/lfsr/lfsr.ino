
/* Shift-XOR-Demo using a linear-feedback shift register */
/* https://de.wikipedia.org/wiki/Linear_r%C3%BCckgekoppeltes_Schieberegister */

/* Kontextvariablen fuer die Zeitmessung */
const unsigned int duration = 100;
unsigned int led_millis;

/* Fuehre einen LFSR-Schritt aus und gebe das hoechste Bit zurueck */
uint16_t lfsr_schritt (void) {

        /* static-Wert bleibt über mehrere Aufrufe erhalten */
        static uint16_t wort = 1;

        /* lokale Variablen werden in jedem Aufruf neu erstellt */
        uint16_t msb, zwi;

        /* gebe MSB aus */
        msb = wort >> 15;
        Serial.println (msb);

        /* bereche naechsten Wert fuers LSB */
        zwi = (msb ^
               (wort >> 13) ^
               (wort >> 12) ^
               (wort >> 10)) & 1;

        /* schiebe nach links und update LSB */
        wort = (wort << 1) | zwi;

        /* Rueckgabewert */
        return msb;
}

void setup ( /* hier könnte void stehen, die Arduino IDE gibt das aber
                bei der setup-Funktion standardmaessig nicht vor */)
{
        /* eingebaute LED aktivieren und anschalten */
        pinMode (LED_BUILTIN, OUTPUT);
        digitalWrite (LED_BUILTIN, HIGH);

        /* initialisieren der Konsolenausgabe */
        Serial.begin (9600);

        /* warte ein wenig und schalte die LED wieder aus */
        delay (500);
        digitalWrite (LED_BUILTIN, LOW);

        /* aktuelle Systemzeit in ms modulo 1000 */
        led_millis = millis ();

        /* ------- Mögliches Todo ------- */
        /* Invertieren Sie die Funktion lfsr_schritt. Schreiben Sie also eine
           Funktion, die nach einem Aufruf von lfsr_schritt den gleichen Bit
           noch ein Mal zurückgibt und den Wert der Variable wort wieder auf den
           Ursprungswert zurücksetzt. Dafür muss wort zu einer globalen Variable
           gemacht werden (siehe Präsenzvorschlag 1). */
}

void loop ( /* hier könnte void stehen, die Arduino IDE gibt das aber
               bei der loop-Funktion standardmäßig nicht vor */ )
{
        /* wieviel Zeit ist vergangen seit dem letzten loop */
        const unsigned int led_diff = millis () - led_millis;
        if (led_diff >= duration) {
                /* unsigned mit wohldefiniertem overflow */
                led_millis += duration;

                /* schritt ausfuehren und rueckgabe auswerten */
                if (lfsr_schritt ()) {
                        digitalWrite (LED_BUILTIN, HIGH);
                }
                else {
                        digitalWrite (LED_BUILTIN, LOW);
                }
        }
}
