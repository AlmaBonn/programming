
alleziele: nurfakultaet.o testdatei

nurfakultaet.o: nurfakultaet.c
	gcc -Wall -c nurfakultaet.c

testdatei:
	echo "Dies ist eine Testdatei." > testdatei

.PHONY: alleziele
