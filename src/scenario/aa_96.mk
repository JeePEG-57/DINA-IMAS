
# Makefile to create the archive library dina.a which can be used to build
# the dina S-function by:
#	mex dina.c dina.a

#XLIB= /usr/X11R6/lib
XLIB= /usr/lib/X11R5/libX11.a

DINA_DIR1 = ./
DINA_DIR = ./
#DINA_DIR = /u/dokouka/DINA_00/DINA_SN/


f2c= gfortran -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC -fno-omit-frame-pointer

CC = cc -fPIC -fno-omit-frame-pointer  -ansi -D_GNU_SOUTCE -pthread

nn=c 
nx=c 

os=		bisplee.o 	\
		bispl.o bispla.o bunema.o \
		bispl_new.o \
		bound.o \
		camloop.o camlxt.o \
		ddunew0.o diter.o disr_ae.o \
		dina_add.o \
		dop_pet.o \
		eni_ae.o fit.o flux_pl.o  \
		gen.o green_d.o inh.o \
		move.o n_dina_95.o \
		neq0_new.o neqm.o ndop_4.o \
		ndop1_new.o oosep_4.o obrm.o \
		pp0.o progonu.o \
		zu0.o zcam_d3d.o zcamit.o zyb0.o \
		gr_psi.o \
		uuu.o \
		cl.o out42_for.o \
		etspxhi.o \
		sh_tcv.o w_vic.o \
		pet_1.o dens_prof.o spline.o svd_tcv.o svd2.o svd.o\
		svd0m.o pf_t.o \
		add_eqb.o b_eqb_rus.o b_grid.o b_metric.o b_rig_rus.o \
		b_sol.o b_wrd.o promat_e_i.o pet.o solver.o rft.o urs.o \
		nag.o dina_new.o equil_96.o aaa.o dina_c.o


dina_95.a: $(os)
	ar -ru dina_95.a $(os)

#p_dina:		$(os)
#	        f77  -o p_dina $(os) -lm -L $(XLIB) 

#init_dina.o:	init_dina.f $(os)
#		$(f2c) -w -c -$(nn) -$(nx) init_dina.f

bisplee.o:	$(DINA_DIR)bisplee.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)bisplee.f
#		$(CC)  -w -c    bisplee.c
bispl.o:	$(DINA_DIR)bispl.f
		$(f2c)   -w -c -$(nn) -$(nx)     $(DINA_DIR)bispl.f
#		$(CC)  -w -c    bispl.c
bispla.o:	$(DINA_DIR)bispla.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)bispla.f
#		$(CC)  -w -c    bispla.c
bispl_new.o:	$(DINA_DIR)bispl_new.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)bispl_new.f
#		$(CC)  -w -c   bispl_new.c
bound.o:	$(DINA_DIR)bound.f
		$(f2c)   -w -c -$(nn) -$(nx)     $(DINA_DIR)bound.f
#		$(CC)  -w -c    bound.c
bunema.o:	$(DINA_DIR)bunema.f
		$(f2c)   -w -c -$(nn) -$(nx)     $(DINA_DIR)bunema.f
#		$(CC)  -w -c   bunema.c
camloop.o:	$(DINA_DIR)camloop.f
		$(f2c)   -w -c -$(nn) -$(nx)   $(DINA_DIR)camloop.f
#		$(CC)  -w -c   camloop.c
camlxt.o:	$(DINA_DIR)camlxt.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)camlxt.f
#		$(CC)  -w -c    camlxt.c
ddunew0.o:	$(DINA_DIR)ddunew0.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)ddunew0.f
#		$(CC)  -w -c   ddunew0.c
diter.o:	$(DINA_DIR)diter.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)diter.f
#		$(CC)  -w -c   diter.c
disr_ae.o:	$(DINA_DIR)disr_ae.f
		$(f2c)   -w -c -$(nn) -$(nx)     $(DINA_DIR)disr_ae.f
#		$(CC)  -w -c   disr_ae.c
dina_add.o:	$(DINA_DIR)dina_add.f
		$(f2c)   -w -c -$(nn) -$(nx)     $(DINA_DIR)dina_add.f
#		$(CC)  -w -c   disr_ae.c
dop_pet.o:	$(DINA_DIR)dop_pet.f $(DINA_DIR)dop_pet.inc
		$(f2c)   -w -c -$(nn) -$(nx)   $(DINA_DIR)dop_pet.f
#		$(CC)  -w -c  dop_pet.c
etspxhi.o:	$(DINA_DIR)etspxhi.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)etspxhi.f
#		$(CC)  -w -c  etspxhi.c
eni_ae.o:	$(DINA_DIR)eni_ae.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)eni_ae.f
#		$(CC)  -w -c  eni_ae.c
fit.o:		$(DINA_DIR)fit.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)fit.f
#		$(CC)  -w -c  fit.c
flux_pl.o:	$(DINA_DIR)flux_pl.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)flux_pl.f
#		$(CC)  -w -c   flux_pl.c
gen.o:		$(DINA_DIR)gen.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)gen.f
#		$(CC)  -w -c   gen.c
green_d.o:	$(DINA_DIR)green_d.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)green_d.f
#		$(CC)  -w -c  green_d.c
inh.o:		$(DINA_DIR)inh.f
		$(f2c)   -w -c -$(nn) -$(nx)   $(DINA_DIR)inh.f
#		$(CC)  -w -c   inh.c
graf9410.o:	$(DINA_DIR)graf9410.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)graf9410.f
#		$(CC)  -w -c -$(nn) -$(nx)    graf9410.c
move.o:		$(DINA_DIR)move.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)move.f
#		$(CC)  -w -c -$(nn) -$(nx)    move.c
n_dina_95.o:	$(DINA_DIR)n_dina_95.f $(DINA_DIR)new_com.inc n_dina.f
		$(f2c)   -w -c -$(nn) -$(nx)  $(DINA_DIR)n_dina_95.f 
#		$(f2c)   -w -c -$(nn) -$(nx) +R  n_dina.f > temp.temp
#		$(CC)  -w -c -$(nn) -$(nx)     n_dina.c
n_diag.o:	$(DINA_DIR)n_diag.f
		$(f2c)   -w -c -$(nn) -$(nx)     $(DINA_DIR)n_diag.f
#		$(CC)  -w -c -$(nn) -$(nx)     n_diag.c
neq_1.o:	$(DINA_DIR)neq_1.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)neq_1.f
#		$(CC)  -w -c -$(nn) -$(nx)    neq_1.c
neq0_new.o:	$(DINA_DIR)neq0_new.f $(DINA_DIR)new_com.inc
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)neq0_new.f
#		$(CC)  -w -c -$(nn) -$(nx)   neq0_new.c
neqm.o:		$(DINA_DIR)neqm.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)neqm.f
#		$(CC)  -w -c -$(nn) -$(nx)    neqm.c
ndop_4.o:	$(DINA_DIR)ndop_4.f 
		$(f2c)   -w -c -$(nn) -$(nx)     $(DINA_DIR)ndop_4.f
#		$(CC)  -w -c -$(nn) -$(nx)     ndop_4.c
ndop1_new.o:	$(DINA_DIR)ndop1_new.f $(DINA_DIR)parf8 $(DINA_DIR)new_com.inc
		$(f2c)   -w -c -$(nn) -$(nx)     $(DINA_DIR)ndop1_new.f
#		$(CC)  -w -c -$(nn) -$(nx)     ndop1_new.c
oosep_4.o:	$(DINA_DIR)oosep_4.f
		$(f2c)   -w -c -$(nn) -$(nx)   $(DINA_DIR)oosep_4.f
#		$(CC)  -w -c -$(nn) -$(nx)    oosep_4.c
obrm.o:		$(DINA_DIR)obrm.f
		$(f2c)   -w -c -$(nn) -$(nx)   $(DINA_DIR)obrm.f
#		$(CC)  -w -c -$(nn) -$(nx)    obrm.c
pp0.o:		$(DINA_DIR)pp0.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)pp0.f
#		$(CC)  -w -c -$(nn) -$(nx)    pp0.c
progonu.o:	$(DINA_DIR)progonu.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)progonu.f
#		$(CC)  -w -c -$(nn) -$(nx)    progonu.c
zu0.o:		$(DINA_DIR)zu0.f
		$(f2c)   -w -c -$(nn) -$(nx)    $(DINA_DIR)zu0.f
#		$(CC)  -w -c   zu0.c
zcam_d3d.o:	$(DINA_DIR)zcam_d3d.f
		$(f2c)   -w -c -$(nn) -$(nx)     $(DINA_DIR)zcam_d3d.f
#		$(CC)  -w -c   zcam_d3d.c
zcamit.o:	$(DINA_DIR)zcamit.f
		$(f2c)   -w -c -$(nn) -$(nx)     $(DINA_DIR)zcamit.f
#		$(CC)  -w -c   zcamit.c
uuu.o:		$(DINA_DIR)uuu.f
		$(f2c)   -w -c -$(nn) -$(nx)      $(DINA_DIR)uuu.f
#		$(CC)  -w -c     uuu.c
graf9603.o:	$(DINA_DIR)graf9603.f $(DINA_DIR)graf9603.inc
		$(f2c)    -w -c -$(nn) -$(nx)   -w -c -$(nn) -$(nx) $(DINA_DIR)graf9603.f
#		$(CC)   -w -c  graf9603.c
gr_psi.o:	$(DINA_DIR)gr_psi.f 
		$(f2c)    -w -c -$(nn) -$(nx)   -w -c -$(nn) -$(nx) $(DINA_DIR)gr_psi.f
#		$(CC)   -w -c  $(DINA_DIR)gr_psi.c
out42_for.o:	$(DINA_DIR)out42_for.f
		$(f2c) -w -c -$(nn) -$(nx) $(DINA_DIR)out42_for.f
cl.o:		$(DINA_DIR)cl.c
		$(CC) -c    $(DINA_DIR)cl.c
zyb0.o:		$(DINA_DIR)zyb0.f
		$(f2c) -w -c -$(nn) -$(nx) $(DINA_DIR)zyb0.f

sh_tcv.o:	$(DINA_DIR)sh_tcv.f
		$(f2c) -w -c -$(nn) -$(nx) $(DINA_DIR)sh_tcv.f
w_vic.o:	$(DINA_DIR)w_vic.f
		$(f2c) -w -c -$(nn) -$(nx) $(DINA_DIR)w_vic.f
pet_1.o:	$(DINA_DIR)pet_1.f
		$(f2c) -w -c -$(nn) -$(nx) $(DINA_DIR)pet_1.f
dens_prof.o: 	$(DINA_DIR)dens_prof.f
		$(f2c) -w -c -$(nn) -$(nx) $(DINA_DIR)dens_prof.f
spline.o:	$(DINA_DIR)spline.f
		$(f2c) -w -c -$(nn) -$(nx) $(DINA_DIR)spline.f

svd0m.o:	svd0m.f
		$(f2c)   -w -c        svd0m.f
svd_tcv.o:	svd_tcv.f
		$(f2c)   -w -c   svd_tcv.f
svd2.o:		svd2.f
		$(f2c)   -w -c        svd2.f
svd.o:		svd.f
		$(f2c)   -w -c        svd.f
pf_t.o:		pf_t.f
		$(f2c)   -w -c 	pf_t.f

add_eqb.o:		add_eqb.f
		$(f2c)   -w -c 	add_eqb.f
b_eqb_rus.o:	b_eqb_rus.f
		$(f2c)   -w -c 	b_eqb_rus.f

b_grid.o:	b_grid.f
		$(f2c)   -w -c 	b_grid.f

b_metric.o:	b_metric.f
		$(f2c)   -w -c 	b_metric.f

b_rig_rus.o:	b_rig_rus.f
		$(f2c)   -w -c 	b_rig_rus.f

b_sol.o:	b_sol.f
		$(f2c)   -w -c 	b_sol.f

b_wrd.o:	b_wrd.f
		$(f2c)   -w -c 	b_wrd.f

promat_e_i.o:	promat_e_i.f
		$(f2c)   -w -c 	promat_e_i.f

pet.o:	pet.f
		$(f2c)   -w -c 	pet.f

solver.o:	solver.f
		$(f2c)   -w -c 	solver.f

rft.o:	rft.f
		$(f2c)   -w -c 	rft.f

urs.o:	urs.f
		$(f2c)   -w -c 	urs.f

nag.o:	nag.f
		$(f2c)   -w -c 	nag.f

dina_new.o:	dina_new.f
		$(f2c)   -w -c 	dina_new.f

equil_96.o:	equil_96.f
		$(f2c)   -w -c 	equil_96.f
aaa.o:		aaa.f
		$(f2c)   -w -c 	aaa.f
dina_c.o:	dina_c.f
		$(f2c)   -w -c 	dina_c.f

		  
		 







