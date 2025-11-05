
# Kommentare beginnen mit #, dieses Zeichen
# muß neu in jeder Kommentarzeile stehen.

# Im Makefile kann man nach Belieben Variablen definieren.
# Eine Variablendefinition bewirkt für sich noch nichts.
ZIELE = justsome ohnechip

# Hier die erste Definition einer Abhängigkeit über den Doppelpunkt.
# Die Syntax ist Ziel: Quelle(n), letztere getrennt durch Leerzeichen.
#
# Beim Aufruf von `make` ohne Argumente wird das erste Ziel im
# Makefile erzeugt.  Alle Abhängigkeiten werden rekursiv erzeugt.
# In unserem Fall bewirken `make` und `make ziel` das gleiche.
#
# Der Inhalt der Variablen ZIELE wird hier als Quelle(n) eingesetzt.
# Das Ziel `ziel` ist real keine Datei, das Ziel `ohnechip` schon.
# Beides ist erlaubt, für nicht-Datei-Ziele siehe unten zu .PHONY.
ziel: $(ZIELE)

# Eine weitere Definition einer Abhängigkeit über den Doppelpunkt.
# Die Reihenfolge ist wieder Ziel: Quelle(n).
# Dieses Ziel ist unsere ausführbare Datei.
ohnechip: ohnechip.c
# Die Zeile(n) direkt unter der Abhängigkeit gehören dazu und enthalten
# alle benoetigten Aufrufe zum Erzeugen des Ziels aus seinen Quellen.
# Diese Aufruf-Zeilen *müssen* mit einem TAB-Zeichen beginnen!
# Manche Editoren wandeln TABs in Leerzeichen um, das gilt es zu verhindern.
	gcc -Wall -Wextra $^ -o $@

# Eine weitere Abhaengigkeit dieser Art.
justsome: justsome.c
	gcc -Wall -Wextra $^ -o $@

# Wir haben in der obigen Regel zwei der internen Variablen abgerufen:
# $@ setzt das Ziel ein.  Das Symbol ähnelt optisch einer Zielscheibe!
# $< setzt die erste Quelle ein.  Das Symbol zeigt sozusagen darauf.
# $^ setzt alle Quellen ein.  Eselsbrücke ist "alles von dort oben."

# .PHONY ist ein spezielles vordefiniertes Ziel von make.
# Hier sollte man alle Ziele auflisten, die *kein* Dateiname sind.
# Ansonsten würde make versuchen, die Dateien `ziel` oder `clean`
# zu konstruieren.  Durch diese Regel wird das verhindert.
.PHONY: ziel clean

# Wir fügen noch ein nicht-Datei Ziel hinzu zum weiteren Automatisieren.
# In diesem Fall hat das Ziel keine Abhängigkeit, sondern ruft `rm` auf.
# Wenn man `make clean` aufruft, löscht das die erzeugten Zieldateien.
clean:
	rm -f $(ZIELE)
