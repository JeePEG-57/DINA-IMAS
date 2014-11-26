# Top-level Makefile for DINA

all: dina interface fc2k

dina:
	make -C src/scenario

interface: dina
	make -C imas/interface -f make_dina_lib

fc2k: interface
	make -C imas/fc2k
	make -C imas/fc2k fc2k

clean:
	make -C src/scenario clean
	make -C imas/interface -f make_dina_lib clean

distclean:
	make -C src/scenario distclean
	make -C imas/interface -f make_dina_lib distclean
