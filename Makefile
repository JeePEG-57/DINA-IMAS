# Top-level Makefile for DINA

all: dina interface fc2k

dina:
	make -C src/scenario
	make -C src/scenario/kavin_controller clean
	make -C src/scenario/kavin_controller
	make -C src/scenario/kavin_controller_1a clean
	make -C src/scenario/kavin_controller_1a
	make -C src/scenario/kavin_controller_1b clean
	make -C src/scenario/kavin_controller_1b

interface: dina
	make -C imas/astra_transp
	make -C imas/eq_test
	make -C imas/interface

fc2k: interface
	make -C imas/fc2k

clean:
	make -C src/scenario clean
	make -C imas/astra_transp clean
	make -C imas/eq_test clean
	make -C imas/interface clean
	make -C imas/fc2k clean

distclean:
	make -C src/scenario distclean
	make -C imas/interface distclean
