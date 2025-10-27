/* 1. Beispielprogramm zu Variablen und Funktionen */

/* diese Funktion sollte strenggenommen 'static' sein */
void wir (void) {
  /* hier arbeiten wir das wesentliche Programm ab */

  /* in C stehen alle Variablendeklarationen vor den Anweisungen */
  int a;
  int c[187];

/*
 * Der Praeprozessor verarbeitet vor dem eigentlichen Compilieren
 * spezielle Anweisungen, die mit '#' beginnen.
 * Damit lassen sich Teile des Programms vor dem Compiler verstecken.
 * Es lassen sich auch textuelle Ersetzungen definieren.
 *
 * Wenn wir diesen Code aktivieren, bekommen wir eine Warnung,
 * da wir die Variable b und d im Programm gar nicht benutzen.
 */
#if 0
  const int b = 1;
  char d = 'A';
#endif
  /* Variable fuer eine Zeichenkette */
  char zeile[72];

  /* wir warten bis der Serial Monitor geoeffnet wird */
  Serial.begin (9600);
  while (!Serial) { /* leerer Block zum Warten */ }

  /* wir benutzen die oben deklarierte Variable a zum Zaehlen */
  for (a = 0; a < 10; a = a + 1) {
    /* Zuweisung zu einem Element des Arrays c */
    c[a] = 18 + a;
  }

  /* weitere Details dazu siehe 'man 3 printf' */
  snprintf (zeile, 72, "Hallo wir haben %d und %d\n",
            a, c[5]);

  /* nachdem wir die Zeile befuellt haben, geben wir sie aus */
  Serial.write (zeile);
}

void setup (void) {
  /* put your code here to run once: */

  /* dies ist ein Funktionsaufruf ohne Argumente */
  wir ();
}

void loop (void) {
  /* we ignore the content of this function for our class */
}
