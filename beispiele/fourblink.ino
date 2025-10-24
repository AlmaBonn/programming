
#define LED_PIN LED_BUILTIN

static unsigned int led_millis;

void
setup (void)
{
	Serial.begin (9600);

	pinMode (LED_PIN, OUTPUT);
	led_millis = millis ();
}

void
loop (void)
{
	static unsigned char step;
	static const unsigned char numsteps = 4;
	static const unsigned int duration[numsteps] = { 700, 20, 130, 150 };

	const unsigned int led_diff = millis () - led_millis;
	if (led_diff >= duration[step]) {
		led_millis += duration[step];

		switch (step & 1) {
			case 0:
				digitalWrite (LED_PIN, HIGH);
				break;
			case 1:
				digitalWrite (LED_PIN, LOW);
				break;
		}
		if  (++step == numsteps) {
			step = 0;
			//Serial.write ("Another sequence done.\n");
		}
	}
}
