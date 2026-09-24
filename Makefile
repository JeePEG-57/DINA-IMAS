# Top-level Makefile for DINA

all: dina interface

dina:
	make -C src/green
	make -C src/scenario



interface: dina
	make -C imas/iwrap/dina_green
	make -C imas/iwrap/dina_imas
	make -C imas/iwrap/tcv_controller
	make -C imas/iwrap/wf_iter
	make -C imas/iwrap/wf_tcv

clean:
	make -C src/scenario clean
	make -C src/green clean
	make -C src/controllers/kmc clean
	make -C src/controllers/kmc_contr_4 clean
	make -C src/controllers/kmc_2madiv clean
	make -C src/controllers/kmc_pfpo1_1a clean
	make -C src/controllers/kmc_pfpo1_1b clean
	make -C imas/astra_transp clean
	make -C imas/eq_test clean
	make -C imas/circ clean
	make -C imas/interface clean
	make -C imas/iwrap/dina_green clean
	make -C imas/iwrap/dina_imas clean
	make -C imas/iwrap/kmc clean
	make -C imas/iwrap/kmc_contr_4 clean
	make -C imas/iwrap/wf_iter clean
	make -C imas/iwrap/wf_vde clean
	make -C imas/iwrap/tcv_controller clean
	make -C imas/iwrap/wf_tcv clean
