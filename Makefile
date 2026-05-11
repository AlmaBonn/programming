
# Dieses Makefile erzeugt ein Diagramm aus einer Wuerfelsimulation.
# Die Anzahl der Würfe läßt sich über die Variable WN festlegen.
# Beispielsweise kann man aufrufen: make WN=6000000

# Makefiles koennen Variablen
CFLAGS = -Wall

# Anzahl der Wuerfe, sofern nicht per Kommandozeile überschrieben
WN = 6000

ZIELE = nueberk fakultaet wuerfeln testdatei

# $(WN) muss ueberall gleichermassen angehangen werden
plot: ergebnis_$(WN).pdf

alles: $(ZIELE) plot

ergebnis_$(WN).pdf: wuerfelplot ergebnis_$(WN).temp
	cp -f ergebnis_$(WN).temp ergebnis.temp
	gnuplot $<
	rm -f ergebnis.temp
	mv -f ergebnis.pdf $@

ergebnis_$(WN).temp: wuerfeln
	./wuerfeln $(WN) | grep '^ERGEBNIS' > $@

wuerfeln: wuerfeln.o
	gcc -o $@ $^

nueberk: nueberk.o nurfakultaet.o
	gcc -o $@ $^

fakultaet: kombinationen.o nurfakultaet.o
	gcc -o $@ $^

.c.o:
	gcc $(CFLAGS) -c $<

testdatei:
	echo "Dies ist eine Testdatei." > $@

# Vielleicht möchte man die Plots erhalten
mostlyclean:
	rm -f *.o $(ZIELE) ergebnis*.temp

# Lösche wirklich alle generierten Dateien
clean: mostlyclean
	rm -f ergebnis_*.pdf

.PHONY: alles clean mostlyclean plot
