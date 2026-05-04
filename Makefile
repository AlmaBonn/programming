
ZIELE = nueberk fakultaet wuerfeln testdatei ergebnis.pdf

alleziele: $(ZIELE)

ergebnis.pdf: wuerfelplot ergebnis
	gnuplot $<

ergebnis: wuerfeln
	./wuerfeln 10000000 | grep '^ERGEBNIS' > ergebnis

wuerfeln: wuerfeln.o
	gcc -o $@ $^

nueberk: nueberk.o nurfakultaet.o
	gcc -o $@ $^

fakultaet: kombinationen.o nurfakultaet.o
	gcc -o $@ $^

.c.o:
	gcc -Wall -c $<

testdatei:
	echo "Dies ist eine Testdatei." > $@

clean:
	rm -f *.o $(ZIELE)

.PHONY: alleziele clean
