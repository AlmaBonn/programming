
/* Shift-XOR-Demo using a linear-feedback shift register */
/* https://de.wikipedia.org/wiki/Linear_r%C3%BCckgekoppeltes_Schieberegister */

/* Kontextvariablen fuer die Zeitmessung */
static const unsigned int duration = 100;
static unsigned int led_millis;

/* diese Funktion sollte strenggenommen static sein */
uint16_t
lfsr_schritt (void) {

        /* static Wert bleibt über mehrere Aufrufe erhalten */
        static uint16_t wort = 1;

        /* lokale Variablen in jedem Aufruf neu erstellt */
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

        /* rueckgabewert */
        return msb;
}

void
setup (void)
{
        /* initialisieren der Konsolenausgabe */
        Serial.begin (9600);

        /* warte ein wenig, aber blockiere nicht ohne IDE */
        delay (500);

        /* eingebaute LED aktivieren */
        pinMode (LED_BUILTIN, OUTPUT);

        /* aktuelle Systemzeit in ms modulo 1000 */
        led_millis = millis ();
}

void
loop (void)
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
