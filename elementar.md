
# Der elementare Ansatz zum Programmieren

Die folgenden Aussagen sind teils verkürzt und bruchstückhaft,
aber durchaus geeignet, ein Bild unseres Ansatzes vermitteln.

## Betrachtung moderne CPU und modernes Betriebssystem

 - Die CPU hat mehrere Rechenkerne, jeder führt ein unabhängiges Programm
   (besser einen Prozess) aus.
 - Das Betriebssystem weist die aktiven Prozesse abwechselnd den Kernen zu.
   Wenn ein Prozess z. B. auf eine Tastatureingabe wartet, wird er
   schlafengelegt und das Betriebssystem aktiviert einen anderen Prozess.
   Es gibt also eigentlich nur maximal soviel laufende Programme wie Kerne.
   Der Rest schläft, zwangsweise oder freiwillig.
 - Die reale Laufzeit eines Programms zu messen ist dementsprechend nicht
   ohne Weiteres möglich.  Wenn es ausreichend viele Kerne gibt, so daß der
   untersuchte Prozess nicht schlafen muß sondern durchlaufen kann, ist die
   real gemessene Laufzeit zumindest eine vernünftige Approximation.

Das Betriebssystem ist selbst ein Prozess (oder eine Sammlung von mehreren),
der idealerweise nur minimale Rechenzeit benötigt, grundsätzlich aber andere
Prozesse verdrängt, sobald er tätig wird.

Die theoretische Laufzeit eines Algorithmus kann man abschätzen, indem man
die Anzahl Rechenoperationen zählt, beispielsweise alle Multiplikationen.
Meist ist bekannt, wieviele Taktzyklen ein CPU-Kern für die Bearbeitung
einer Multiplikation braucht.  Eine Division ist jedoch bereits teurer und
muß im Grunde separat gezählt und veranschlagt werden.

Moderne CPUs arbeiten als Pipeline:  Wenn eine Berechnung mehrere Taktzyklen
dauert, wird ein Fließband entsprechender Länge angelegt und an jeder
Station eine Recheneinheit für die passende Unteroperation plaziert.  Wenn
sich das Fließband um einen Schritt fortbewegt, führen alle Recheneinheiten
ihren Schritt aus, jeweils auf einer anderen Variablen, so daß die
Bearbeitungszeit pro Variable auf nur einen Taktzyklus schrumpft.  Dies
funktioniert aber nur, wenn es überhaupt genug Input-Variablen zur selben
Rechenoperation gibt und diese Inputs alle rechtzeitig aus dem Speicher
geholt und die Outputs wieder dort hingeschrieben werden können.  Die
Pipeline-Verarbeitung erschwert also die theoretische Vorhersage der
Laufzeit, da die Vorbedingungen nicht vorhersehbar sind.

Die meisten klassischen CPUs arbeiten als CISC-Maschinen, also mit einem
Satz von Instruktionen, die von einem komplexen Hardware-Decoder in
Unterschritte zerlegt werden, und nur die Unterschritte sind einzeln in
Hardware abgebildet.  Dagegen arbeiten RISC-Maschinen mit einem reduzierten
Instruktionssatz, der direkt in Hardware ausgeführt wird.  Die
Bearbeitungsdauer von RISC-Befehlen ist im Allgemeinen klar definiert.

Speicherzugriffe laufen in modernen Computern durch eine Hierarchie von
Zwischenspeichern, die bei der CPU angefangen klein und schnell sind, und in
Richtung realem Hauptspeicher größer und langsamer.  Wenn auf eine Variable
mehrmals kurz hintereinander zugegriffen wird, liegt sie wahrscheinlich noch
im schnellen Zwischenspeicher.
Wenn der letzte Zugriff allerdings lange her ist, muß sie
aus dem langsameren Hauptspeicher geholt werden.  Variablenzugriffe sind
also unterschiedlich schnell auf eine nicht vorhersehbare Weise.

## Betrachtung eines minimalen Mikrocontrollers

Wir stellen nun einen modernen Computer in CISC-Architektur einem minimalen
Mikrocontroller in RISC-Architektur gegenüber.
Im Wesentlichen fehlen letzterem alle obigen Features: es gibt nur einen
Kern und und einen Prozess insgesamt, kein Betriebssystem, keine Pipeline,
keine Speicherhierarchie und keine Befehlsdecoder.
Diese Reduktion soll nicht darüber hinwegtäuschen, daß solche Chips extrem
nützlich und verbreitet sind:  Ihre Konstruktion wird von den Herstellern ab
und an aktualisiert und sie werden nach wie vor produziert.

Der Kern eines 8-bit RISC-Mikrocontrollers besteht aus etwa 80000
Transistoren.
Ein moderner 64-Bit CISC Kern besteht aus fast 7 Milliarden, das ist etwa
hunderttausendmal mehr.
Wichtiger ist, daß ein moderner Computer eine unübersehbare Anzahl und tiefe
Hierarchie an Systemen zwischen Input und Output schaltet, die wir alle
nicht wirklich verstehen.
Dagegen ist die Laufzeit aller Instruktionen des Mikrocontrollers exakt
bekannt.

Ein Hauptspeicherzugriff einer modernen CPU dauert bis zu 100mal so lange
wie eine Rechenoperation.
Man mißt also im Wesentlichen die Anzahl der Speicherzugriffe eines
Algorithmus und nicht seine Rechenzeit.
Bei einem Mikrocontroller mit simpler Speicherarchitektur ist das Verhältnis
dagegen etwa 1:1, so daß die tatsächliche Rechenzeit signifikant in die
Laufzeit eingeht.

## Vorläufiges Fazit

Da wir in dieser Vorlesung elementar arbeiten wollen, beginnen wir also mit
einem vergleichsweise limitierten Chip, dem `ATMega32U4`, den wir dafür
komplett verstehen können.
Die genutzte Hardware ist damit für uns alle identisch.
