void run (void) {
  /* Schreiben Sie hier Ihren Code. Schreiben Sie keine main-Funktion! */
  Serial.println ("Hello World!");
}

/* Der Code in der setup-Funktion wird genau einmal ausgeführt. */
void setup (/* hier könnte void stehen, die Arduino IDE macht das aber standardmäßig nicht */) {
  /* warte drei Sekunden zur Sicherheit, siehe
     https://github.com/AlmaBonn/programming/wiki/Wichtige-Hinweise-zum-Mikrochip#delay */
  delay (3000);

  /* Initialisiere Konsole mit der Datenrate von 9600 Bits pro Sekunde. */
  Serial.begin (9600);
  /* Wir warten bis die USB-Verbindung besteht. */
  while (!Serial) { /* warten */ }
  run ();
}

/* Der Code in der loop-Funktion wird wiederholt ausgeführt. */
void loop (/* hier könnte void stehen, die Arduino IDE macht das aber standardmäßig nicht */) {
  /* Wir führen nichts in dieser Funktion aus.
   * Wenn wir Code wiederholt ausführen möchten, verwenden wir
   * eine Schleife (for oder while) in der run-Funktion.
   */
   return;
}
