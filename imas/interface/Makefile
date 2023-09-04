DINADIR := ../../src/scenario
GREENDIR := ../../src/green
CONTROLDIR := ../../src/controllers
ASTRADIR := ../astra_transp


PACKAGES =
PACKAGES += imas-$(FCOMPILER)
PACKAGES += libxml-2.0
PACKAGES += xmllib

F90_gfortran=$(FCOMPILER) -w -I$(DINADIR)
COPTS_gfortran = -freal-4-real-8 -cpp -fPIC -fno-second-underscore -ffree-line-length-none `pkg-config $(PACKAGES) --cflags` -g
#COPTS_gfortran += -traceback -check-all -fp-stack-check
LIBS_gfortran=`pkg-config $(PACKAGES) --libs`


f2c= $(FCOMPILER) -w -I$(DINADIR) -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC -g
#f2c+= -traceback -check all -fp-stack-check

DINATRANSP = dina_transp1.o tran1.o dina_transp2.o tran2.o dina_transp3.o tran3.o dina_transp4.o tran4.o dina_transp5.o tran5.o

FORTRANWF = test_dina_to_imas test_dina test_dina_pfpo1a test_dina_pfpo1b test_dina_2madiv
TARGETS += $(FORTRANWF) dina_imas.a dina_sdn.a kmc.a kmc_pfpo1_1a.a kmc_pfpo1_1b.a kmc_2madiv.a dina_transp_energy.a dina_transp_density.a dina_transp_density_test.a dina_transp_density_test0.a dina_transp_bootcond.a dina_transp_curdrive.a dina_transp_heatsrc.a solps_imas.a


LIB_SOURCEDINA := dina_imas.o params_imas.o

LIB_SOURCECTRL := dina_contr.o n_kav.o out42_for.o main_1l.o contr_params_imas.o



all: $(TARGETS)

test_dina: test_dina_imas.o dina_green.a dina_imas.a kmc.a solps_imas.a
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

test_dina_pfpo1a: test_dina_imas.o dina_green.a dina_imas.a kmc_pfpo1_1a.a solps_imas.a
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

test_dina_pfpo1b: test_dina_imas.o dina_green.a dina_imas.a kmc_pfpo1_1b.a solps_imas.a
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

test_dina_pfpo1c: test_dina_imas.o dina_green.a dina_imas.a kmc_pfpo1_1a.a solps_imas.a
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

test_dina_2madiv: test_dina_imas.o dina_green.a dina_imas.a kmc_2madiv.a solps_imas.a
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

test_dina_astra: test_dina_imas_astra.o dina_green.a dina_imas.a kmc.a solps_imas.a astra_transp_density.a
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

astra_transp_density.a: $(ASTRADIR)/astra_transp_density.a
	@echo "   * $^ -> $@"
	@cp $< $@

test_dina_to_imas: test_dina_to_imas.o n_dina_imas4.o dina_to_imas.o
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

test_wr_prof: test_wr_prof.o wr_prof_imas.o n_dina_imas3.o
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90_gfortran) $(COPTS_gfortran) -c -o $@ $^

wr_prof_imas.o: wr_prof_imas.f90
	@echo "   * $^ -> $@"
	$(F90_gfortran) $(COPTS_gfortran) -I$(DINADIR) -c -o $@ $^

%.o: %.f
	@echo "   * $^ -> $@"
	$(f2c) -c $<

dina_green.a: $(GREENDIR)/green.a dina_green.o tokamak_green.o
	@echo "   * $^ -> $@"
	@cp $< $@
	ar -rcs $@ dina_green.o tokamak_green.o

dina_imas.a: $(DINADIR)/dina_99.a $(LIB_SOURCEDINA)
	@echo "   * $^ -> $@"
	@cp $< $@
	ar -rcs $@ $(LIB_SOURCEDINA)

kmc.a: $(CONTROLDIR)/kmc/kmc.a $(LIB_SOURCECTRL)
	@echo "   * $^ -> $@"
	@cp $< $@
	ar -rcs $@ $(LIB_SOURCECTRL)

kmc_pfpo1_1a.a: $(CONTROLDIR)/kmc_pfpo1_1a/kmc.a $(LIB_SOURCECTRL)
	@echo "   * $^ -> $@"
	@cp $< $@
	ar -rcs $@ $(LIB_SOURCECTRL)

kmc_pfpo1_1b.a: $(CONTROLDIR)/kmc_pfpo1_1b/kmc.a $(LIB_SOURCECTRL)
	@echo "   * $^ -> $@"
	@cp $< $@
	ar -rcs $@ $(LIB_SOURCECTRL)

kmc_2madiv.a: $(CONTROLDIR)/kmc_2madiv/kmc.a $(LIB_SOURCECTRL)
	@echo "   * $^ -> $@"
	@cp $< $@
	ar -rcs $@ $(LIB_SOURCECTRL)

dina_transp_energy.a: dina_transp_energy.o tran1.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs $@ $^

dina_transp_density.a: dina_transp_density.o tran2.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs $@ $^

dina_transp_density_test.a: dina_transp_density_test.o tran2.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs $@ $^

dina_transp_density_test0.a: dina_transp_density_test0.o tran2.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs $@ $^

dina_transp_bootcond.a: dina_transp_bootcond.o tran3.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs $@ $^

dina_transp_curdrive.a: dina_transp_curdrive.o tran4.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs $@ $^

dina_transp_heatsrc.a: dina_transp_heatsrc.o tran5.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs $@ $^

dina_sdn.a: dina_sdn.o
	@echo "   * $^ -> $@"
	ar -rcs $@ $^

solps_imas.a: $(DINADIR)/solpsz2_vic.o solps_imas.o
	@echo "   * $^ -> $@"
	ar -rcs $@ $^

external_transp.a: external_transp.o
	@echo "   * $^ -> $@"
	ar -rcs $@ $^

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.exe
	rm -f $(TARGETS)
