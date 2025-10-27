
/* Kontextvariablen fuer die Zeitmessung */
static const unsigned int duration = 100;
static unsigned int led_millis;

uint16_t
lfsr_schritt (void) {

        /* Wert bleibt über mehrere Aufrufe erhalten */
        static uint16_t wort = 1;

        /* lokale Variablen in jedem Aufruf neu */
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
        delay (500);

        /* eingebaute LED aktivieren */
	pinMode (LED_BUILTIN, OUTPUT);

        /* aktuelle Systemzeit in ms modulo 1000 */
	led_millis = millis ();
}

void
loop (void)
{
        /* wieviel Zeit ist vergangen */
	const unsigned int led_diff = millis () - led_millis;
	if (led_diff >= duration) {
                /* unsigned mit wohldefiniertem overflow */
		led_millis += duration;

		/* schritt ausfuehren und rueckgabe auswerten */
		if (lfsr_schritt ()) {
			digitalWrite (LED_PIN, HIGH);
                }
                else {
		        digitalWrite (LED_PIN, LOW);
		}
	}
}
