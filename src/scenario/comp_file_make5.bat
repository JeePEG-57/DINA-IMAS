
objects=		 bisplee.obj bispl.obj bispla.obj bunema.obj bispl_new.obj \
                bound.obj camloop.obj camlxt.obj ddunew0.obj diter.obj disr_ae.obj dina_add.obj \
                dop_pet.obj eni_ae.obj etspxhi.obj fit.obj flux_pl.obj gen.obj green_d.obj \
                inh.obj move.obj neq0_new.obj neqm.obj ndop_4.obj ndop1_new.obj oosep_4.obj \
                obrm.obj pp0.obj progonu.obj uuu.obj zu0.obj zcam_d3d.obj zcamit.obj zyb0.obj \
                sh_tcv.obj w_vic.obj pet_1.obj dens_prof.obj spline.obj svd0m.obj svd_tcv.obj \
                svd2.obj pf_t.obj \
                add_eqb.obj b_eqb_rus.obj b_grid.obj b_metric.obj b_rig_rus.obj b_sol.obj \
                b_wrd.obj promat_e_i.obj pet.obj solver.obj rft.obj urs.obj nag.obj \
                dina_new.obj  svd.obj \
                atsv.obj break_new.obj elem_i.obj write_eqdsk_c.obj
    
dina_v90.dll:   $(objects)



bisplee.obj:	bisplee.f
		mex -v  -c bisplee.f -f df60opts.bat
bispl.obj:	bispl.f
		mex -v  -c bispl.f -f df60opts.bat
bispla.obj:	bispla.f
		mex -v  -c bispla.f -f df60opts.bat
bunema.obj:	bunema.f
		mex -v  -c bunema.f -f df60opts.bat
bispl_new.obj:	bispl_new.f
		mex -v  -c bispl_new.f -f df60opts.bat
bound.obj:	bound.f
		mex -v  -c bound.f -f df60opts.bat
camloop.obj:	camloop.f
		mex -v  -c camloop.f -f df60opts.bat
camlxt.obj:	camlxt.f
		mex -v  -c camlxt.f -f df60opts.bat
ddunew0.obj:	ddunew0.f
		mex -v  -c ddunew0.f -f df60opts.bat
diter.obj:	diter.f
		mex -v  -c diter.f -f df60opts.bat
disr_ae.obj:	disr_ae.f
		mex -v  -c disr_ae.f -f df60opts.bat
dina_add.obj:	dina_add.f
		mex -v  -c dina_add.f -f df60opts.bat
dop_pet.obj:	dop_pet.f
		mex -v  -c dop_pet.f -f df60opts.bat
eni_ae.obj:	eni_ae.f
		mex -v  -c eni_ae.f -f df60opts.bat
etspxhi.obj:	etspxhi.f
		mex -v  -c etspxhi.f -f df60opts.bat
fit.obj:	fit.f
		mex -v  -c fit.f -f df60opts.bat
flux_pl.obj:	flux_pl.f
		mex -v  -c flux_pl.f -f df60opts.bat
gen.obj:	gen.f
		mex -v  -c gen.f -f df60opts.bat
green_d.obj:	green_d.f
		mex -v  -c green_d.f -f df60opts.bat
inh.obj:	inh.f
		mex -v  -c inh.f -f df60opts.bat
move.obj:	move.f
		mex -v  -c move.f -f df60opts.bat
neq0_new.obj:	neq0_new.f
		mex -v  -c neq0_new.f -f df60opts.bat
neqm.obj:	neqm.f
		mex -v  -c neqm.f -f df60opts.bat
ndop_4.obj:	ndop_4.f
		mex -v  -c ndop_4.f -f df60opts.bat
ndop1_new.obj:	ndop1_new.f
		mex -v  -c ndop1_new.f -f df60opts.bat
oosep_4.obj:	oosep_4.f
		mex -v  -c oosep_4.f -f df60opts.bat
obrm.obj:	obrm.f
		mex -v  -c obrm.f -f df60opts.bat
pp0.obj:	pp0.f
		mex -v  -c pp0.f -f df60opts.bat
progonu.obj:	progonu.f
		mex -v  -c progonu.f -f df60opts.bat
uuu.obj:	uuu.f
		mex -v  -c uuu.f -f df60opts.bat
zu0.obj:	zu0.f
		mex -v  -c zu0.f -f df60opts.bat
zcam_d3d.obj:	zcam_d3d.f
		mex -v  -c zcam_d3d.f -f df60opts.bat
zcamit.obj:	zcamit.f
		mex -v  -c zcamit.f -f df60opts.bat
zyb0.obj:	zyb0.f
		mex -v  -c zyb0.f -f df60opts.bat
sh_tcv.obj:	sh_tcv.f
		mex -v  -c sh_tcv.f -f df60opts.bat
w_vic.obj:	w_vic.f
		mex -v  -c w_vic.f -f df60opts.bat
pet_1.obj:	pet_1.f
		mex -v  -c pet_1.f -f df60opts.bat
dens_prof.obj:	dens_prof.f
            mex -v  -c dens_prof.f -f df60opts.bat
spline.obj:	spline.f
		mex -v  -c spline.f -f df60opts.bat
svd0m.obj:	svd0m.f
		mex -v  -c svd0m.f -f df60opts.bat
svd_tcv.obj:	svd_tcv.f
		mex -v  -c svd_tcv.f -f df60opts.bat
svd2.obj:	svd2.f
		mex -v  -c svd2.f -f df60opts.bat
pf_t.obj:	pf_t.f
		mex -v  -c pf_t.f -f df60opts.bat
add_eqb.obj:	add_eqb.f
		mex -v  -c add_eqb.f -f df60opts.bat
b_eqb_rus.obj:	b_eqb_rus.f
		mex -v  -c b_eqb_rus.f -f df60opts.bat
b_grid.obj:	b_grid.f
		mex -v  -c b_grid.f -f df60opts.bat
b_metric.obj:	b_metric.f
		mex -v  -c b_metric.f -f df60opts.bat
b_rig_rus.obj:	b_rig_rus.f
		mex -v  -c b_rig_rus.f -f df60opts.bat
b_sol.obj:	b_sol.f
		mex -v  -c b_sol.f -f df60opts.bat
b_wrd.obj:	b_wrd.f
		mex -v  -c b_wrd.f -f df60opts.bat
promat_e_i.obj:	promat_e_i.f
		mex -v  -c promat_e_i.f -f df60opts.bat
pet.obj:	pet.f
		mex -v  -c pet.f -f df60opts.bat
solver.obj:	solver.f
		mex -v  -c solver.f -f df60opts.bat
rft.obj:	rft.f
		mex -v  -c rft.f -f df60opts.bat
urs.obj:	urs.f
		mex -v  -c urs.f -f df60opts.bat
nag.obj:	nag.f
		mex -v  -c nag.f -f df60opts.bat
dina_new.obj:	dina_new.f
		mex -v  -c dina_new.f -f df60opts.bat
svd.obj:	svd.f
		mex -v  -c svd.f -f df60opts.bat
atsv.obj:	atsv.for
		mex -v  -c atsv.for -f df60opts.bat
break_new.obj:	break_new.f
		mex -v  -c break_new.f -f df60opts.bat
elem_i.obj:	elem_i.for
		mex -v  -c elem_i.for -f df60opts.bat
write_eqdsk_c.obj:	write_eqdsk_c.f
		mex -v  -c write_eqdsk_c.f -f df60opts.bat
