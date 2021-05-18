# Top-level Makefile for DINA

all: dina controllers interface fc2k

dina:
	make -C src/scenario

controllers:
	make -C src/controllers/kavin_controller
	make -C src/controllers/kavin_controller_1a
	make -C src/controllers/kavin_controller_1b

interface: dina controllers
	make -C imas/astra_transp
	make -C imas/eq_test
	make -C imas/interface

fc2k: interface
	make -C imas/fc2k

clean:
	make -C src/scenario clean
	make -C src/controllers/kavin_controller clean
	make -C src/controllers/kavin_controller_1a clean
	make -C src/controllers/kavin_controller_1b clean
	make -C imas/astra_transp clean
	make -C imas/eq_test clean
	make -C imas/interface clean
	make -C imas/fc2k clean

distclean:
	make -C src/scenario distclean
	make -C imas/interface distclean
