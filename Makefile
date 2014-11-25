# Top-level Makefile for DINA

all:
	cd src/scenario ; make
	cd imas/interface ; make -f make_dina_lib

clean:
	cd src/scenario ; make clean
	cd imas/interface ; make -f make_dina_lib clean

distclean:
	cd src/scenario ; make distclean
	cd imas/interface ; make -f make_dina_lib distclean
