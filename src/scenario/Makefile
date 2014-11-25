# Makefile for compilation of DINA components

AR = ar
ARFLAGS = -ru
FC = gfortran
FFLAGS = -w -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC

DINASRC = \
a_dina.f  add.f atsv.f\
bispl.f bispla.f bisplee.f Bohm_gyroBohm_L.f\
bound.f bp_gribov_1.f bpol3.f  brz.f bunema.f\
camloop.f camlxt.f con_fil.f con_mike.f\
con_vs3_17_ch10.f ddunew0_test.f disr.f diter_1.f\
dop_jetto.f edf.f efi_fil.f efi_ves.f\
eni_BgB_CT.f etspxhi2.f fit.f flux_pl.f\
forces_for_control.f g_gaps_rus.f gen.f gr_psi_d_pc.f\
green_br_N.f green_d.f inh.f map.f\
min_distance_1cm_1.f min_distance_pfw_1cm.f\
move.f n_matlab.f ndop1_new2_400_beam.f\
ndop_4_avr.f neq0_jetto.f neqm.f obrm.f oosep_4.f\
out42_for.f pet.f pf_t.f pfsvd11x.f pid.f pp0.f progonu.f\
read_por.f sh.f sh1_N2.f sh_astra_dt_beam.f\
sh_br.f sh_d3d.f svd.f svd0m.f svd2.f uuu.f\
victor_HL.f write_eqdsk_scen_tok.f write_jetto.f\
write_plasma_W.f zca_tsp.f zcam_d3d.f zcamit.f\
zrad.f zu0.f zyb0_0.f

DINAOBJ = $(DINASRC:.f=.o)

CONTROLSRC = add_dll.f con_vs3_17_ch10.f field_dina.f

CONTROLOBJ = $(CONTROLSRC:.f=.o)

all: dina_99.a dina_kav.a

dina_99.a: $(DINAOBJ)
	$(AR) $(ARFLAGS) $@ $(DINAOBJ)

dina_kav.a: $(CONTROLOBJ)
	$(AR) $(ARFLAGS) $@ $(CONTROLOBJ)

%.o: %.f
	$(FC) $(FFLAGS) -c $<

clean:
	-rm -f *.o

distclean:
	-rm -f *.o *.a
