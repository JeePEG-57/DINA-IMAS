objects= 	a_dina.obj add.obj atsv.obj \
		bispl.obj bispla.obj bisplee.obj Bohm_gyroBohm_L.obj \
		bound.obj bp_gribov_1.obj bpol3.obj  brz.obj bunema.obj \
		camloop.obj camlxt.obj con_fil.obj con_mike.obj \
		con_vs3_17_ch10.obj cons_func.obj ddunew0_test.obj disr.obj\
		diter_1.obj dop_jetto.obj edf.obj efi_fil.obj efi_ves.obj\
		eni_BgB_CT.obj etspxhi2.obj fit.obj flux_pl.obj\
		forces_for_control.obj g_gaps_rus.obj gen.obj gr_psi_d_pc.obj\
		green_br_N.obj green_d.obj inh.obj map.obj\
		min_distance_1cm_1.obj min_distance_pfw_1cm.obj\
		move.obj n_matlab.obj n_dina_imas.obj ndop1_new2_400_beam.obj\
		ndop_4_avr.obj neq0_jetto.obj neqm.obj obrm.obj oosep_4.obj\
		out42_for.obj pet.obj pf_t.obj pfsvd11x.obj \
		pid.obj pp0.obj progonu.obj\
		read_por.obj sh.obj sh1_N2.obj sh_astra_dt_beam.obj\
		sh_br.obj sh_d3d.obj svd.obj svd0m.obj svd2.obj uuu.obj\
		victor_HL.obj write_eqdsk_scen_tok.obj write_jetto.obj\
		write_plasma_W.obj zca_tsp.obj zcam_d3d.obj zcamit.obj\
		zrad.obj zu0.obj zyb0_0.obj

dina_v90.dll:   $(objects)


a_dina.obj:     a_dina.f
		mex    -v  -c   a_dina.f -f df60opts.bat

add.obj:	add.f
		mex    -v  -c   add.f -f df60opts.bat

atsv.obj:	atsv.f
		mex    -v  -c      atsv.f -f df60opts.bat

bispl.obj:	bispl.f
		mex    -v  -c     bispl.f -f df60opts.bat

bispla.obj:	bispla.f
		mex    -v  -c    bispla.f -f df60opts.bat

bisplee.obj:	bisplee.f
		mex    -v  -c    bisplee.f -f df60opts.bat

Bohm_gyroBohm_L.obj:	Bohm_gyroBohm_L.f
			mex    -v  -c      Bohm_gyroBohm_L.f -f df60opts.bat

bound.obj:	bound.f
		mex    -v  -c   bound.f -f df60opts.bat

bp_gribov_1.obj: bp_gribov_1.f
		mex    -v  -c     bp_gribov_1.f -f df60opts.bat

bpol3.obj:	bpol3.f
		mex    -v  -c      bpol3.f -f df60opts.bat

brz.obj:		brz.f
		mex   -v  -c brz.f -f df60opts.bat

bunema.obj:	bunema.f
		mex    -v  -c    bunema.f -f df60opts.bat

camloop.obj:	camloop.f
		mex   -v  -c   camloop.f -f df60opts.bat

camlxt.obj:	camlxt.f 
		mex    -v  -c    camlxt.f -f df60opts.bat

con_fil.obj:	con_fil.f
		mex   -v  -c con_fil.f -f df60opts.bat

con_mike.obj:	con_mike.f parf8
		mex    -v  -c    con_mike.f -f df60opts.bat

con_vs3_17_ch10.obj:	con_vs3_17_ch10.f 
		mex   -v  -c con_vs3_17_ch10.f -f df60opts.bat

cons_func.obj:	cons_func.f 
		mex   -v  -c cons_func.f -f df60opts.bat

ddunew0_test.obj: ddunew0_test.f
		mex   -v  -c ddunew0_test.f -f df60opts.bat

disr.obj:	disr.f
		mex   -v  -c  disr.f -f df60opts.bat

diter_1.obj:	diter_1.f
		mex    -v  -c   diter_1.f -f df60opts.bat

dop_jetto.obj:	dop_jetto.f dop_vs_pfw_1.inc  new_com.inc
		mex   -v  -c  dop_jetto.f -f df60opts.bat

edf.obj:	edf.f
		mex    -v  -c    edf.f -f df60opts.bat

efi_fil.obj:	efi_fil.f
		mex    -v  -c   efi_fil.f -f df60opts.bat

efi_ves.obj:	efi_ves.f
		mex    -v  -c   efi_ves.f -f df60opts.bat

eni_BgB_CT.obj:	eni_BgB_CT.f
		mex    -v  -c   eni_BgB_CT.f -f df60opts.bat

etspxhi2.obj:	etspxhi2.f
		mex    -v  -c  etspxhi2.f -f df60opts.bat

fit.obj:	fit.f
		mex    -v  -c   fit.f -f df60opts.bat

flux_pl.obj:	flux_pl.f
		mex    -v  -c  flux_pl.f -f df60opts.bat

forces_for_control.obj:	forces_for_control.f
		mex    -v  -c      forces_for_control.f -f df60opts.bat

g_gaps_rus.obj:	g_gaps_rus.f
		mex   -v  -c  g_gaps_rus.f -f df60opts.bat

gen.obj:	gen.f
		mex   -v  -c  gen.f -f df60opts.bat

gr_psi_d_pc.obj: gr_psi_d_pc.f 
		mex     -v  -c   gr_psi_d_pc.f -f df60opts.bat

green_br_N.obj:	green_br_N.f
		mex   -v  -c  green_br_N.f -f df60opts.bat

green_d.obj:	green_d.f
		mex    -v  -c    green_d.f -f df60opts.bat

inh.obj:	inh.f
		mex    -v  -c   inh.f -f df60opts.bat

map.obj:	map.f
		mex    -v  -c      map.f -f df60opts.bat

min_distance_1cm_1.obj:	 min_distance_1cm_1.f
		mex    -v  -c      min_distance_1cm_1.f -f df60opts.bat

min_distance_pfw_1cm.obj:min_distance_pfw_1cm.f
		mex    -v  -c      min_distance_pfw_1cm.f -f df60opts.bat

move.obj:	move.f
		mex    -v  -c    move.f -f df60opts.bat

n_matlab.obj:	n_matlab.f new_com.inc
		mex   -v  -c  n_matlab.f -f df60opts.bat

n_dina_imas.obj:	n_dina_imas.f 
		mex   -v  -c  n_dina_imas.f -f df60opts.bat


ndop1_new2_400_beam.obj:	ndop1_new2_400_beam.f parf8
		mex   -v  -c ndop1_new2_400_beam.f -f df60opts.bat

ndop_4_avr.obj:	ndop_4_avr.f
		mex   -v  -c ndop_4_avr.f -f df60opts.bat

neq0_jetto.obj:	neq0_jetto.f new_com.inc
		mex   -v  -c neq0_jetto.f -f df60opts.bat

neqm.obj:	neqm.f
		mex    -v  -c    neqm.f -f df60opts.bat

obrm.obj:	obrm.f
		mex    -v  -c    obrm.f -f df60opts.bat

oosep_4.obj:	oosep_4.f
		mex    -v  -c    oosep_4.f -f df60opts.bat

out42_for.obj:	out42_for.f
		mex   -v -c out42_for.f -f df60opts.bat

pet.obj:	pet.f
		mex    -v  -c     pet.f -f df60opts.bat

pf_t.obj:	pf_t.f
		mex    -v  -c     pf_t.f -f df60opts.bat

pfsvd11x.obj:	pfsvd11x.f
		mex    -v  -c    pfsvd11x.f -f df60opts.bat

pid.obj:	pid.f new_com.inc
		mex   -v  -c  pid.f -f df60opts.bat

pp0.obj:	pp0.f
		mex    -v  -c    pp0.f -f df60opts.bat

progonu.obj:	progonu.f
		mex    -v  -c    progonu.f -f df60opts.bat

read_por.obj:	read_por.f
		mex    -v  -c    read_por.f -f df60opts.bat

sh.obj:		sh.f
		mex    -v  -c   sh.f -f df60opts.bat

sh1_N2.obj:	sh1_N2.f
		mex   -v  -c  sh1_N2.f -f df60opts.bat

sh_astra_dt_beam.obj:		sh_astra_dt_beam.f
		mex    -v  -c   sh_astra_dt_beam.f -f df60opts.bat

sh_br.obj:	sh_br.f
		mex    -v  -c    sh_br.f -f df60opts.bat

sh_d3d.obj:	sh_d3d.f
		mex   -v  -c sh_d3d.f -f df60opts.bat

svd.obj:	svd.f
		mex    -v  -c    svd.f -f df60opts.bat

svd0m.obj:	svd0m.f
		mex    -v  -c    svd0m.f -f df60opts.bat

svd2.obj:	svd2.f
		mex    -v  -c    svd2.f -f df60opts.bat

uuu.obj:	uuu.f
		mex    -v  -c      uuu.f -f df60opts.bat

victor_HL.obj:	victor_HL.f new_com.inc
		mex   -v  -c victor_HL.f -f df60opts.bat

write_eqdsk_scen_tok.obj:	write_eqdsk_scen_tok.f
		mex    -v  -c      write_eqdsk_scen_tok.f -f df60opts.bat

write_jetto.obj:	$(V)write_jetto.f 
		mex   -v  -c $(V)write_jetto.f -f df60opts.bat

write_plasma_W.obj:	write_plasma_W.f
		mex    -v  -c      write_plasma_W.f -f df60opts.bat

zca_tsp.obj:	zca_tsp.f new_com.inc  chop_chx.inc  
		mex   -v  -c zca_tsp.f -f df60opts.bat

zcam_d3d.obj:	zcam_d3d.f
		mex   -v  -c zcam_d3d.f -f df60opts.bat

zcamit.obj:	zcamit.f
		mex    -v  -c     zcamit.f -f df60opts.bat

zrad.obj:	zrad.f
		mex    -v  -c      zrad.f -f df60opts.bat

zu0.obj:	zu0.f
		mex    -v  -c    zu0.f -f df60opts.bat

zyb0_0.obj:	zyb0_0.f
		mex    -v  -c    zyb0_0.f -f df60opts.bat







