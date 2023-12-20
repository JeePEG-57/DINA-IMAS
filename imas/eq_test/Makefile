
PACKAGES =
PACKAGES += imas-$(FCOMPILER)

F90=$(FCOMPILER)
FFLAGS ?= -w -fdefault-real-8 -fPIC -fno-second-underscore -ffree-line-length-none
FFLAGS += `pkg-config $(PACKAGES) --cflags`
LDFLAGS = `pkg-config $(PACKAGES) --libs`

#XLIB= /usr/X11R6/lib


FC= $(FCOMPILER) -w -ffixed-line-length-none -fno-automatic -fPIC -g -ffpe-trap=invalid,zero



S=./
V=$(S)



os=		a_dina_equi.o \
		bispl.o bispla.o bound.o brz.o  bunema.o \
		diter_1.o fit.o flux_pl.o gr_psi_d_pc.o green_imas.o inh.o \
		map.o n_dina_imas.o n_equi.o ndop_4.o neq0_sep_lim_32.o neqm.o obrm.o \
		oosep_4.o out42_for.o pet.o pid.o pers2.o sh.o sh1_n2.o\
		sh_d3d.o uuu.o zca_tsp.o zcam_d3d.o zcamit.o
		 

all:	p_equi dina_equil.a test_equil

dina_equil.a: dina_equil.o $(os)
	@echo "   * $^ -> $@"
	ar -rcs dina_equil.a dina_equil.o $(os)

test_equil: test_dina_equil.o dina_equil.o $(os)
	@echo "   * $^ -> $@"
	$(F90) -o $@ $^ $(LDFLAGS)


%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90) $(FFLAGS) -c -o $@ $^

p_equi: a_main_equi.o $(os)
	@echo "   * $^ -> $@"
	$(F90) -o $@ $^ $(LDFLAGS)


a_main_equi.o:	$(S)a_main_equi.f
		$(FC) -c   -w   $(S)a_main_equi.f

a_dina_equi.o:	$(S)a_dina_equi.f
		$(FC) -c   -w   $(S)a_dina_equi.f

bispl.o:	$(S)bispl.f
		$(FC) -c   -w    $(S)bispl.f

bispla.o:	$(S)bispla.f
		$(FC) -c   -w    $(S)bispla.f

bound.o:	$(S)bound.f
		$(FC) -c   -w    $(S)bound.f

brz.o:		$(S)brz.f
		$(FC) -c   -w    $(S)brz.f

bunema.o:	$(S)bunema.f
		$(FC) -c   -w    $(S)bunema.f

diter_1.o:	$(S)diter_1.f
		$(FC) -c   -w    $(S)diter_1.f

fit.o:		$(S)fit.f
		$(FC) -c   -w    $(S)fit.f
flux_pl.o:	$(S)flux_pl.f
		$(FC) -c   -w    $(S)flux_pl.f
gr_psi_d_pc.o:	$(S)gr_psi_d_pc.f
		$(FC) -c   -w    $(S)gr_psi_d_pc.f

green_imas.o:	$(S)green_imas.f
		$(FC) -c   -w    $(S)green_imas.f


inh.o:		$(S)inh.f
		$(FC) -c   -w    $(S)inh.f
map.o:		$(S)map.f
		$(FC) -c   -w    $(S)map.f
n_equi.o:	n_equi.f new_com.inc
		$(FC) -c  -w  n_equi.f
n_dina_imas.o:	n_dina_imas.f new_com.inc
		$(FC) -c  -w  n_dina_imas.f
ndop_4.o:	$(S)ndop_4.f
		$(FC) -c   -w    $(S)ndop_4.f
neq0_sep_lim_32.o:	$(S)neq0_sep_lim_32.f
		$(FC) -c   -w    $(S)neq0_sep_lim_32.f
neqm.o:		$(S)neqm.f
		$(FC) -c   -w    $(S)neqm.f
obrm.o:		$(S)obrm.f
		$(FC) -c   -w    $(S)obrm.f
oosep_4.o:	$(S)oosep_4.f
		$(FC) -c   -w    $(S)oosep_4.f
out42_for.o:	$(S)out42_for.f
		$(FC) -c   -w    $(S)out42_for.f
pet.o:		$(S)pet.f
		$(FC) -c   -w    $(S)pet.f
pers2.o:	$(S)pers2.f
		$(FC) -c   -w    $(S)pers2.f
pid.o:		$(S)pid.f
		$(FC) -c   -w    $(S)pid.f
sh.o:		$(S)sh.f
		$(FC) -c   -w    $(S)sh.f
sh1_n2.o:	$(S)sh1_n2.f
		$(FC) -c   -w    $(S)sh1_n2.f
sh_d3d.o:	$(S)sh_d3d.f
		$(FC) -c   -w    $(S)sh_d3d.f
uuu.o:		$(S)uuu.f
		$(FC) -c   -w    $(S)uuu.f
zca_tsp.o:	$(S)zca_tsp.f
		$(FC) -c   -w    $(S)zca_tsp.f
zcam_d3d.o:	$(S)zcam_d3d.f
		$(FC) -c   -w    $(S)zcam_d3d.f
zcamit.o:	$(S)zcamit.f
		$(FC) -c   -w    $(S)zcamit.f

clean:
	rm -f *.o
	rm -f *.a
	rm -f p_equi


