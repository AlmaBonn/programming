
# Dieses Makefile erzeugt ein Diagramm aus einer Regression.

# Makefiles koennen Variablen definieren
# Variablen sind aber an sich keine Ziele
CFLAGS = -Wall
EINGABE = eingaben.txt
ZIELE = ausgleich matrizen

# Das erste angegebene Ziel wird erzeugt durch ein einfaches 'make'.
meinziel: matrizen

# Ein Ziel ist immer definiert über den Doppelpunkt am Ende ':'
alles: report matrizen

# Das Ziel 'report' entspricht keiner Datei, sondern strukturiert nur.
report: ausgleich $(EINGABE)
	cat $(EINGABE) | ./ausgleich

# Erzeuge mehrere Hauptprogramme aus Maschinencode
ausgleich: ausgleich.o
	gcc -o $@ $^

matrizen: matrizen.o
	gcc -o $@ $^

# Erzeuge Maschinencode aus einer C-Programmdatei
# Dies wird wiederholt für jede Datei dieser Endung.
.c.o:
	gcc $(CFLAGS) -c $<

# Lösche generierte Dateien außer Plots
mostlyclean:

# Lösche wirklich alle generierten Dateien
clean: mostlyclean
	rm -f *.o $(ZIELE)

# Ziele (Knoten im Abhängkeitswald), die keine Datei dieses Namens sind.
.PHONY: alles report mostlyclean clean
