

#include <stdio.h>

#define LED_PIN LED_BUILTIN

static unsigned int led_millis;

static uint16_t wort = 1;

uint16_t
schritt (void) {

	uint16_t msb, zwi;

        /* gebe MSB aus */
        msb = (wort >> 15);
        Serial.println (msb);

	/* bereche naechsten Wert fuers LSB */
	zwi = (msb ^
               (wort >> 13) ^
               (wort >> 12) ^
               (wort >> 10)) & 1;

        /* schiebe links und update LSB */
        wort = (wort << 1) | zwi;

        /* rueckgabe */
        return msb;
}

void
setup (void)
{
	Serial.begin (9600);
	while (!Serial) ;

	pinMode (LED_PIN, OUTPUT);
	led_millis = millis ();
}

void
loop (void)
{
	static unsigned char step;
	static const unsigned char numsteps = 1;
	static const unsigned int duration[numsteps] = { 100 };
        uint16_t msb;

	const unsigned int led_diff = millis () - led_millis;
	if (led_diff >= duration[step]) {
		led_millis += duration[step];

		/* schritt ausfuehren */
                msb = schritt ();

		if (msb) {
			digitalWrite (LED_PIN, HIGH);
                }
                else {
		        digitalWrite (LED_PIN, LOW);
		}
	}
}
