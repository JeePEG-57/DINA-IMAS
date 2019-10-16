XLIB= /usr/X11R6/lib

#f2c= g77 -ff2c -fno-automatic
f2c= gfortran -w  -ffixed-line-length-none -fno-automatic 


S=./
V=$(S)



os=		a_main_equi.o a_dina_equi.o \
		bispl.o bispla.o bound.o brz.o  bunema.o \
		diter_1.o fit.o flux_pl.o gr_psi_d_pc.o green_imas.o inh.o \
		map.o n_equi.o ndop_4.o neq0_sep_lim_32.o neqm.o obrm.o \
		oosep_4.o out42_for.o pet.o pid.o pers2.o sh.o sh1_n2.o\
		sh_d3d.o uuu.o zca_tsp.o zcam_d3d.o zcamit.o
		 

p_equi:		$(os)

		gfortran -o p_equi $(os) -lm -L$(XLIB) -lX11


a_main_equi.o:	$(S)a_main_equi.f
		$(f2c) -c   -w   $(S)a_main_equi.f

a_dina_equi.o:	$(S)a_dina_equi.f
		$(f2c) -c   -w   $(S)a_dina_equi.f

bispl.o:	$(S)bispl.f
		$(f2c) -c   -w    $(S)bispl.f

bispla.o:	$(S)bispla.f
		$(f2c) -c   -w    $(S)bispla.f

bound.o:	$(S)bound.f
		$(f2c) -c   -w    $(S)bound.f

brz.o:		$(S)brz.f
		$(f2c) -c   -w    $(S)brz.f

bunema.o:	$(S)bunema.f
		$(f2c) -c   -w    $(S)bunema.f

diter_1.o:	$(S)diter_1.f
		$(f2c) -c   -w    $(S)diter_1.f

fit.o:		$(S)fit.f
		$(f2c) -c   -w    $(S)fit.f
flux_pl.o:	$(S)flux_pl.f
		$(f2c) -c   -w    $(S)flux_pl.f
gr_psi_d_pc.o:	$(S)gr_psi_d_pc.f
		$(f2c) -c   -w    $(S)gr_psi_d_pc.f

green_imas.o:	$(S)green_imas.f
		$(f2c) -c   -w    $(S)green_imas.f


inh.o:		$(S)inh.f
		$(f2c) -c   -w    $(S)inh.f
map.o:		$(S)map.f
		$(f2c) -c   -w    $(S)map.f
n_equi.o:	n_equi.f new_com.inc
		$(f2c) -c  -w  n_equi.f

ndop_4.o:	$(S)ndop_4.f
		$(f2c) -c   -w    $(S)ndop_4.f
neq0_sep_lim_32.o:	$(S)neq0_sep_lim_32.f
		$(f2c) -c   -w    $(S)neq0_sep_lim_32.f
neqm.o:		$(S)neqm.f
		$(f2c) -c   -w    $(S)neqm.f
obrm.o:		$(S)obrm.f
		$(f2c) -c   -w    $(S)obrm.f
oosep_4.o:	$(S)oosep_4.f
		$(f2c) -c   -w    $(S)oosep_4.f
out42_for.o:	$(S)out42_for.f
		$(f2c) -c   -w    $(S)out42_for.f
pet.o:		$(S)pet.f
		$(f2c) -c   -w    $(S)pet.f
pers2.o:	$(S)pers2.f
		$(f2c) -c   -w    $(S)pers2.f
pid.o:		$(S)pid.f
		$(f2c) -c   -w    $(S)pid.f
sh.o:		$(S)sh.f
		$(f2c) -c   -w    $(S)sh.f
sh1_n2.o:	$(S)sh1_n2.f
		$(f2c) -c   -w    $(S)sh1_n2.f
sh_d3d.o:	$(S)sh_d3d.f
		$(f2c) -c   -w    $(S)sh_d3d.f
uuu.o:		$(S)uuu.f
		$(f2c) -c   -w    $(S)uuu.f
zca_tsp.o:	$(S)zca_tsp.f
		$(f2c) -c   -w    $(S)zca_tsp.f
zcam_d3d.o:	$(S)zcam_d3d.f
		$(f2c) -c   -w    $(S)zcam_d3d.f
zcamit.o:	$(S)zcamit.f
		$(f2c) -c   -w    $(S)zcamit.f



