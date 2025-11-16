
/* Blink the LED with a configurable 4-cycle */

/* The Arduino IDE defines LED_BUILTIN as the output connected to the LED */
#define LED_PIN LED_BUILTIN

/* We're using a rollover-timer with an accuracy of 2 bytes */
unsigned int led_millis;

void setup ( /* hier könnte void stehen, die Arduino IDE gibt das aber
                bei der setup-Funktion standardmäßig nicht vor */ )
{
/* Dieses Programm ist zur Demonstration und soll sofort anfangen zu
   blinken, auch wenn der Chip z. B. nur mit einem USB-Netzteil verbunden
   ist.  Daher deaktivierenn wir den zeitverzögerten Programmstart. */
#if 0
        /* Warte drei Sekunden mit einem funktionierenden USB-Input */
        delay (3000);

        /* Konsolenoutput aufsetzen */
        Serial.begin (9600);

        /* Wir warten noch ein wenig, laufen aber auch ohne den Monitor */
        delay (500);

/* das Gegenstück zum obigen #if 0 */
#endif

        /* Einmalig ausgefuehrter Vorbereitungscode */
        pinMode (LED_PIN, OUTPUT);
        led_millis = millis ();
}

void loop ( /* hier könnte void stehen, die Arduino IDE gibt das aber
               bei der loop-Funktion standardmäßig nicht vor */ )
{
        /* lokale statische Variablen behalten ihren Wert über mehrere Aufrufe */
        /* dies hält unsere Logik über mehrere loop-Aufrufe hinweg am Leben */
        static unsigned char step;
        static const unsigned char numsteps = 4;
        static const unsigned int duration[numsteps] = { 700, 20, 130, 150 };

        /* konstante Variablen erlauben keine weitere Zuweisung */
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

/* in diesem Programm nutzen wir keinen Output */
#if 0
                        Serial.println ("Another sequence done.");
#endif
                }
        }
}
