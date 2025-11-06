void run () {
  /* Schreiben Sie hier Ihren Code. Schreiben Sie keine main-Funktion! */
  Serial.println ("Hello World!");
}

/* Der Code in der setup-Funktion wird genau einmal ausgeführt. */
void setup () {
  /* Initialisiere Konsole mit der Datenrate von 9600 Bits pro Sekunde. */
  Serial.begin (9600);
  /* Wir warten bis die USB-Verbindung besteht. */
  while (!Serial) { /* warten */ }
  run ();
}

/* Der Code in der loop-Funktion wird wiederholt ausgeführt. */
void loop () {
  /* Wir führen nichts in dieser Funktion aus.
   * Wenn wir Code wiederholt ausführen möchten, verwenden wir
   * eine Schleife (for oder while) in der run-Funktion.
   */
   return;
}
