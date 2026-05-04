
ZIELE = nueberk fakultaet wuerfeln testdatei

alleziele: $(ZIELE)

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
