
# Kommentare beginnen mit #, dieses
# Zeichen muß neu in jeder Zeile stehen

# Variablen können beliebig definiert werden
ZIEL = ohnechip

# Eine Definition einer Abhängikeit über den Doppelpunkt.
# Die Reihenfolge ist Ziel: Quelle(n).
ohnechip: ohnechip.c
# Die Zeile(n) direkt darunter enthalten alle Aufrufe
# zum Erzeugen des Ziels aus den Quellen.
# Diese *müssen* mit einem TAB-Zeichen beginnen!
# Manche Editoren wandeln TABs in Leerzeichen um, das gilt es zu verhindern.
	gcc -Wall -Wextra $^ -o $@

# Wir haben in der obigen Regel zwei Variablen eingesetzt:
# $@ setzt das Ziel ein.  Das Symbol ähnelt optisch einer Zielscheibe!
# $^ setzt die erste Quelle ein.  Das Symbol zeigt sozusagen darauf.
# $< setzt alle Quellen ein.  Eselsbrücke ist die allgemeine Eingabe.
