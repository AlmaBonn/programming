#define L 10

/* Wir geben eine b-adische Zahl zur Basis 5 vor und speichern ihre Ziffern als Array.
   Hier ist zu beachten, dass der Array von 'links nach rechts' initialisiert wird,
   das heißt z_0 wird hier auf 4 und nicht auf 0 gesetzt. Das entspricht also
   nicht der zum Beispiel vom Dezimalsystem gewohnten Darstellung (z_{L-1},...,z_0)_b */
int input[L] = {4, 4, 4, 3, 0, 2, 1, 1, 3, 0};
/* Output enthält für den Fall von Übertrag einen Wert mehr.
   Die Initialisierung ist strenggenommen nicht noetig. */
int output[L+1] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int input_laenge (void) {
  /* Variable fuer rueckwaerts laufende Schleife.
     Vorsicht: der Wert -1 kommt vor, daher darf diese Variable
               auf keinen Fall von einem unsigned-Typ sein. */
  int i;

  /* Wir suchen die *letzte* Ziffer ungleich 0, daher iterieren wir von hinten nach vorne. */
  int l = 0;
  for (i = L - 1; i >= 0; i--) {
    if (input[i] != 0) {
      l = i + 1; /* Wir addieren 1, da input[i] != 0 noch eine relevante Ziffer ist. */
      break; /* Wir brechen unsere Suche ab. */
    }
  }

  /* Die max-Funktion liegt in der Arduino-Umgebung vor. */
  return max (l, 1); /* Die Zahl 0 hat Länge 1, obwohl alle Ziffern 0 sind. */
}

void inkrement (int l) {

  /* Variable fuer vorwaerts laufende Schleife. */
  int i;

  /* Das Inkrement entspricht der Addition von 1.
     Wir iterieren über alle relevanten Ziffern 0 bis l - 1 und betrachten den Übertrag.
     Auch wenn es keinen Übertrag mehr gibt, müssen wir die Ziffern noch von Input nach Output kopieren. */
  int uebertrag = 1; /* Wir initialisieren den Übertrag auf 1, das stellt die gewünschte Addition von 1 dar.*/
  for (i = 0; i < l; i++) {
    if (input[i] == 4 && uebertrag == 1) {
      /* Es gab einen Übertrag von 1 und die aktuelle Ziffer ist 4, es wird also wieder Übertrag geben.*/
      output[i] = 0;
    } else {
      /* Wir wenden den Übertrag an. Da entweder input[i] < 4 oder uebertrag < 1 gibt es keinen neuen Übertrag. */
      output[i] = input[i] + uebertrag;
      uebertrag = 0;
    }
  }
  /* Wir wenden einen eventuell verbleibenden Übertrag auf Ziffer output[l] an. */
  output[l] = uebertrag;
}

void print_arrays (void) {
  int i;

  /* Wir geben den input array im Serial Monitor aus. 
     Da eine b-adische Zahl üblicherweise in der Form (z_{L-1},...,z_0)_b ausgegeben wird starten wir mit
     dem höchsten Array-Index. */
  Serial.print ("input  =   ("); /* Ein paar extra Leerzeichen, um leichter mit output zu vergleichen.*/
  for (i = L - 1; i >= 0; i--) { /* Diese Schleife läuft rückwärts von L-1 zu 0. */
    Serial.print (input[i]);
    if (i != 0) {
      Serial.print (" ");
    }
  }
  Serial.println(")_5");

  /* Wir geben den output array im Serial Monitor aus. */
  Serial.print ("output = (");
  for (i = L; i >= 0; i--) { /* Diese Schleife läuft rückwärts von L zu 0. */
    Serial.print (output[i]);
    if (i != 0) {
      Serial.print (" ");
    }
  }
  Serial.println(")_5");
}

int verifiziere_werte (int l) {
  int i;

  /* Wir berechnen zunächst den Zahlenwert unserer Input Arrays mit dem
     Horner-Schema, welches der Musterlösung aus Aufgabe 2 b) von Theorieblatt 0
     entspricht.
     Wir verwenden eine uint32_t, um die Darstellbarkeit des Ergebnis zu garantieren. */
  uint32_t wert = input[l-1]; /* Wir fangen mit der letzten Nicht-Null Ziffer an.*/
  for (i = l - 2; i >= 0; i--) {
    wert = 5 * wert + input[i];
  }
  Serial.print ("Die Input-Zahl  hat den Wert ");
  Serial.println (wert);

  /* Wir berechnen den Zahlenwert des Output-Arrays, wieder mit dem Horner-Schema. */
  uint32_t ink_wert = output[l]; /* Wir fangen mit der letzten Ziffer an.*/
  for (i = l - 1; i >= 0; i--) {
    ink_wert = 5 * ink_wert + output[i];
  }
  Serial.print ("Die Output-Zahl hat den Wert ");
  Serial.println (ink_wert);

  /* Wir geben zurück, ob der Wert des Inkrements wirklich dem Ursprungswert + 1 entspricht.*/
  return wert + 1 == ink_wert;
}

void run (void) {
  /* Wir bestimmen die Länge von unserer Zahl. Dafür suchen wir die letzten Ziffer ungleich 0. */
  int l = input_laenge();
  Serial.print ("Länge von input ist ");
  Serial.println (l);

  /* Wir rufen mit der bestimmten Länge die Nachfolger-Funktion auf. */
  inkrement (l);

  /* Wir geben beide Arrays im Serial Monitor aus. */
  print_arrays ();

  /* Wir verifizieren unsere Implementation indem wir die Werte vergleichen. */
  int erfolg = verifiziere_werte (l);
  if (erfolg) {
    Serial.println ("Unser Test war erfolgreich.");
  } else {
    Serial.println ("Unser Test war nicht erfolgreich.");
  }
}

/* Der Code in der setup-Funktion wird genau einmal ausgeführt. */
void setup () {
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
void loop () {
  /* Wir führen nichts in dieser Funktion aus.
   * Wenn wir Code wiederholt ausführen möchten, verwenden wir
   * eine Schleife (for oder while) in der run-Funktion.
   */
   return;
}
