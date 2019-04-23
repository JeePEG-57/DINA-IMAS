
	include 'parf0'
	include 'parf1'
 	parameter ( NPFC=KF-4)
	include 'parf2'
	include 'parf2e'
	include 'parf3'
	include 'parf4'
	include 'parf5'

	include 'parf7'

	include 'parf_b~1'

        include 'parf_m~1'

	include 'parf8'


	common
     *	/n_m/n,m,mp

	common
     *  /igr/ygr(iy,ny),tgr(ny),igr
	common
     *	/ng_igr/ng

	common
     *	/ge1/pi
     *	/ge1e/rs0,tpl
     *  /ge2/NTAY,TAY,TT
     *  /ge2e/t_end
     *	/ge3/AI(npo),A0(npo),HA2(npo),a(npo),ha(npo)
     *  /ge4/EPS1,EPS2,EPS0
     *  /ge5/kpr
     *  /ge6/zeff(npo),qpr(npo),ppr(npo),pr0,prg,zar
     *  /ge6a/ppr0(npo)
     *  /ge6e/zeff_a,zeff_b
     *  /ge7/eu,rout,zout,elong
     *  /ge7e/eu_u
     *  /ge8/pcch
     *  /ge8e/pcchp
     *  /ge12/nps,rps(ntet),zps(ntet)
     *  /ge12e/indpf(kf),seps1,seps2,seps3
     *  /ge12_e/seps_ps(ntet)


	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nr),y(nz),dx,dy
     *  /eq1g/psi_g(nr,nz)
     *  /eq1e/psext(nwnh),re(nre),ze(nze),dr,dz
     *  /eq2/ke,xu(mu_l),yu(mu_l)
     *  /eq2e/kex,xue(mu),yue(mu)
     *  /eq3/FLUXARR(nwnh,kf)
     *  /eq3e/FLUXARRE(nwnhe,kf)
     *  /eq4/xpl(npo,ntet),ypl(npo,ntet)
     *  /eq6/sinus(ntet),cosin(ntet)
     *  /eq7/tet(ntet),ht(ntet)
     *  /eq7q/tetq(ntet),htq(ntet)
     *  /eq7e/tet_p(ntet)
     *  /eq8/jbound,xbound(ntet),ybound(ntet),alfa0
     *  /eq10/vesarr(nwnh,mu)
     *  /eq10e/vesarre(nwnhe,mu)
     *  /eq11/psval(npo),psval0(npo)
     *  /eq12/omega,pspl0(nwnh)
     *  /eq15/pll,zsep,rsep,zsepup,rsepup,zsepdw,rsepdw
     *  /eq15e/pll0,tpl0,udd
     *  /eq15d/pvv,pvv0,tvv,tvv0,udd_ves

	common
     *  /DFM1/UDM,ZDM,L3,SIG0
     *  /DFM2/PSI8(npo),PFI(npo),DM0(npo),DMN(npo)
     *  /dfm3e/dfmaxc(npo),dfmaxh(npo)
     *  /dfm3/dfmax(npo),dfmax0(npo)
     *  /dfm4/Q(npo),ANU(npo),P(npo),F(npo),PP(npo),PFF(npo)
     *  /dfm5/pt01,pt02
     *  /dfm7/bt0,uind
     *  /dfm7e/bt0_0,f_na
     *  /dfm8/ajb(npo),sigk(npo)
     *  /dfm9/aj0(npo)
     *  /dfm10/ajf(npo),aje1(npo),aje(npo)
     *  /dfm11/c20(npo),tok1(npo),tok2(npo)
     *  /dfm12/betj,dlint,bett,bet2,betpc,tk,tkp,tkf
     *  /dfm13/tokel,tokfi,tokbut
     *  /dfm13e/tokuv
     *  /dfm14/tokae,ajae(npo),ajae0(npo),enae
     *	/dfm15/uli

	common
     *  /pol1/RO(npo,ntet),AJ(npo,ntet)
     *  /pol2/Qx(npo),ANUx(npo),Px(npo),Fx(npo),
     *   PPxx(npo),PFFxx(npo)
     *  /pol4/UM,VM,UK(ntet),VK(ntet)
     *  /pol5/psend
     *  /pol6/ppx(npo),pffx(npo)
     *  /pol6d/ppxd(npo),pffxd(npo)

	common
     *	/efit0/kefit
     *	/efit1/alfax(2),betax(2)
     *	/efit2/alfa_0,beta,alfa1
     *	/efit3/pw_1,pw_2
     *	/efit4/coef_efit
     *	/efit5/it1,it2
     *	/efit6/tpl_p

	common
     *  /en1/PNE(npo),PD0(npo),PT0(npo),PH0(npo),PDN(npo),
     *  PTN(npo),PHN(npo)
     *  /en1e/te_a,ti_a,te_b,ti_b,pw_e
     *  /en1d/te_a0
     *  /en2/TE0(npo),TQ0(npo),TEN(npo),TQN(npo),WE0(npo),
     *  WQ0(npo)
     *  /en2e/pd0_a,pt0_a,pd0_b,pt0_b,pw_p
     *  /en5/SD0(npo),ST0(npo),SH0(npo)
     *  /en4/WD0(npo),WT0(npo),WH0(npo),VD(npo),DIF(npo),
     *  GGT(npo),GGTN(npo)
     *  /en6/Vn(npo)
     *  /en9/QE0(npo),QQ0(npo),QDG(npo)
     *  /en9e/volt(npo)
     *  /en10/GGE(npo),GGEN(npo),DXE(npo),DXQ(npo),WU(npo),
     *  UG(npo),VG(npo)
     *  /en11/un(4),zn(2),ll,ken,ken1,ken2,noit
     *  /en12/pnal(npo),pnaln(npo),zalfa,talfa
     *  /en13/kpin,vpin,alp1,pot,skor
     *  /en14e/t_dop
     *  /en14/EMOE,EMOQ,NDOP,QDE0(npo),QDQ0(npo)
     *  /en16/QTOR(npo),QDH(npo),QpE(npo),QpQ(npo)
     *  /en17/QAE(npo),QAQ(npo),SAL(npo),NAL
     *  /en19/DD,DT,DH,SIN0,SINK,ALPY,Sss,Ppp,Eee
     *  /en20/pj(npo),sb0(npo)  
     *  /en23/kk,tn0,pna,wie(npo),wcx(npo),tn(npo),pn(npo),pn0(npo)
     *  /en25/zhib,teoh
     *	/en28/wen1,wen2
     *  /en33/anom_e,anom_i,key_t11,kcchp



      common
     *  /cont1/vchopper(kf),veps
     *  /CONT5/	FCOM(NPFC)
     *  /cont6/cip1,cip2,time1,time2
     *	/cont9/brad,kefit_bad
     *  /cont13/zmag,zvel,delrmag,delzmag
     *  /cont13e/zmag0,rmag,rmag0,rvel
     *	/cont18/t_vde,time_disr

	common
     *	/point1/r0,z0




	common
     *	/keys1/i_graph
     *	/keys2/key_b
     *	/keys3/kzero,iread,iwrite
     *  /keys4/k_ener,k_uv
     *  /keys5/next
     *  /keys6/i_svd,i_cal,kpf
     *  /keys7/i_c
     *  /keys9/i_d3d,i_iter,i_smal
     *  /keys10/ngra 
     *  /keys11/i_ramp
     *  /keys12/i_v
     *  /keys13/i_con,i_act
     *  /keys14/i_beta,i_gap5
     *  /keys15/i_br
	

	common
     *  /halo1/c_h,d_halo,fmax_in,tpl_in
     *  /halo2/kmaj,k_q,k_d,kaxis,ndisrup
     *  /halo2e/next0,li_drop,n_li,n_dif,nmix
     *  /halo3/tay_00,tay_th,t_disr,d_tpl,tpl_end
     *  /halo4/expfg,avalb,w_h,del_r,al0
     *  /halo4e/w_h0,delaval0,pshalo0,te_h0
     *  /halo5/q_vde,q_95,del_f,i_halo
     *  /halo5e/pshalo
     *  /halo6/thalo,thalo0
     *  /halo9/fluxt,fluxt0
     *  /halo10/fves,fves0,self_v
     *  /halo12/te_h
     *  /halo15/e_sep,nsep

        common
     *	/con1/gain,ta,zref,kzref
     *  /con2/rref,krref,bvert
     *  /con6/ind_r(2),ind_z(2)
	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf3/nmx(kf),turn(kf)
     *  /pf4/rvert(kf),svert(kf)
     *  /pf7/plasma(kf),plasma0(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)
     *  /pf9/zvert(kf)
         
        common 
     *  /sh1/dind(kf,10)
     *  /sh2/ps(10),n_ps
     *  /sh2e/ps0(10)
     *  /sh3/k_feed,time_vde
     *  /sh4/s_int,s_int0
     *  /sh5/dis(10),dis0(10),vel(10),sint(10),sint0(10)
     *  /sh6/rref_p,zref_p


	common
     *  /point_brz/r_point,z_point

	common
     *	/fluxc0/ind1(50)
     *	/fluxc1/xp1(50,mu1),yp1(50,mu1)
     *  /fluxc2/delta0,pom(ntet)
     *	/fluxc3/u(nwnh),work(nwnh),sib(nwnh)
     *  /fluxc4/mcurve,x11(mu1),y11(mu1)
     *	/fluxc5/nhalo,xtest(nwnh),ytest(nwnh)
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
     *	/fluxc7/coef,coef1,api
     *  /fluxc9/fdd,fdd0
     *  /fluxc11/npl,pl_cur(nwnh),x_cur(nwnh),y_cur(nwnh)
     *	/fluxc10/x1,y1,dx1,dy1
     *  /fluxc13/volt_sec(kf)
     *  /fluxc14/vs_pf,vs_pl,vs_tot
     *	/fluxc16/tor_flh,tor_flp,tor_fl
     *  /fluxc17/f_index
     *  /fluxc18/alf_tok,int_tok
     *  /fluxc19/int_2000
     *  /fluxc20/vs_ves,v_ves

       	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves2e/dl(mu),hl(mu)
     *  /ves3/b(mu,mu),pmj(mu,mu)
     *  /ves4/rcam(mu)
     *  /ves5/pfc(mu,kf)
     *  /ves9/tokc,tokc0

	common /fwt/fwtp(nloop),fwtb(nprobe)

	common
     *  /svd1/psloop_e(nloop),bprobe_e(nprobe)
     *  /svd2/pf_e(kf)


	common
     *	/loop1/kloop,rl(nloop),zl(nloop),psloop(nloop)
     *  /loop2/pfgreen(nloop,kf),vesgreen(nloop,mu)
     *  /loop3/vloop,psf1a,psf1a0
     *	/loop5/pslgreen(nwnh,nloop)
     *  /loop6/psloopp(nloop)
     *	/loop5e/pslgreene(nwnhe,nloop)
	common
     *	/probe1/kprobe,bprobe(nprobe)
     *  /probe2/pfprobe(nprobe,kf),vesprobe(nprobe,mu)
     *  /probe3/kpb,Rprobe(nprobe,npb),
     *  Zprobe(nprobe,npb),cosa(nprobe),sina(nprobe)
     *	/probe4/bprgreen(nwnh,nprobe)
     *	/probe4e/bprgreene(nwnhe,nprobe)
     *  /probe5/bprobep(nprobe)

c  here new coomon block values begin.....

	common
     *  /c_ge1/b_tor(nr,nz)
     *  /c_ge2/kp
     *  /c_ge3/dmo
     *  /c_ge4/rmag_in,zmag_in
     *  /c_ge5/ksepa 
     *  /c_ge6/time_on,time_off
     *  /c_ge7/coef_pf
     *  /c_ge8/zvel_0

	common
     *  /c_keys1/i_comp,i_ma,k_sh,k_force,k_magn
     *  /c_keys2/i_st


c control keys...
	common
     *  /con_keys1/k_dm0

c  new_halo common blocks...
	common
     *  /c_new_halo1/volt_tor(npo),volt_pol(npo),q_eq(npo)
     *  /c_new_halo2/aval,v_sol
     *  /c_new_halo3/n_sol
     *  /c_new_halo4/dfmaxc0(npo)

     *  /c_new_halo5/pprime,fprime,urr,vrr,sq_sel
     *  /c_new_halo6/u_h(nwnh)

     *  /c_new_halo7/fdd_ax,fdd0_ax,pll_ax,pll0_ax
     *  /c_new_halo8/fsol,fsol0,alf_dis
     *  /c_new_halo9/psext_0(nwnh)
     *  /c_new_halo10/dpsi_ax

     *  /c_new_halo11/c_pl(npo,ntet),s_pl(npo,ntet),
     *  r_pl(npo,ntet),z_pl(npo,ntet)

     *  /c_new_halo12/uext(nwnh),uext0(nwnh)
     *  /c_new_halo13/i_e(nwnh)
     *  /c_new_halo14/p_pl(nr,nz),p_pl0(nr,nz)
     *  /c_new_halo15/ps_sol,ps_sol0

     *  /c_new_halo16/s_help(npo)
     *  /c_new_halo17/fmax,fmax0
     *  /c_new_halo18/k_help
     *  /c_new_halo19/cur_tor(npo)
     *  /c_new_halo20/sp_t,sp_ves,sp_pl
     *  /c_new_halo21/w_time
     *  /c_new_halo22/xcur(2*npo),torcur(2*npo)

        COMMON
     *  /mid1/C1(npo),C2(npo),C3(npo)
     *  /mid2/vi(npo),spo(npo)
     *  /mid2_0/vi0(npo),pfi0(npo)
     *  /mid2e/vol(npo),spov(npo),pcur(npo)
     *  /mid3/GRA1(npo),GRA2(npo)
     *  /mid4/xpp(npo),xpff(npo),ba(npo)
     *  /mid6/bp_0(npo),a_m(npo),r_m(npo)
     *  /mid7/bsq(npo),bsqi(npo),fasp(npo)
     *  /mid8/ppx_r(npo),pffx_r(npo)




c JT control commons...
	common
     *  /c_jt1/p_cur(kf,kf),d_cur(kf,kf),
     *  p_volt(kf,kf),d_volt(kf,kf)

     *  /c_jt2/con_par(kf),con_par0(kf)
     *  /c_jt3/n_con_par
     *  /c_jt4/con_pre(kf),con_pre0(kf),con_exp(kf)
     *  /c_jt5/vchopper0(kf)
     *  /c_jt6/t_prog(ntime,kf)
     *  /c_jt7/key_prog(ntime,kf),n_prog(kf)



	common
     *  /c_caet1/k_caet,xm(500),ym(500)
     *  /c_caet2/k_print


	common
     *  /c_mit_r1/heli

c  FeedForward Voltages...	
	common
     *  /c_ff1/volt_ff(kf)
     *  /c_ff2/n_ip0




c  here new common blocks Victor has done...

	common
     *	/v_keys1/time_svd
     *	/v_keys2/en_run,en_run1,v_run
     *	/v_keys3/dip_dt,del_before_th,del_after_th,w_loss,
     *		key_te,dtor,tec,key_re,alf_core,te_core,
     *		w_h_0,n_th,tt_00,tpl_00,alf_exp,alf_te,bet_te
     *	/v_surface/surface
     *	/v_p_sep/p_sep	
     *	/v_rz_tok/r_tok,z_tok
     *	/v_zeff_sugihara/zeff_sugihara
     *	/v_plats/i_plats
     *	/v_hel_0/hel_0
!!!     *  /v_int_2000/int_2000

     *	/v_com1/halo_res,halo_res_avr,out_res
     *	/v_com2/i_tab2
     *	/v_com3/alf_halo,time_mix
     *	/v_com4/energy_pla,psi_pl_avr
     *	/v_com5/tt_after_tqh,z_total_imp
     *	/v_com6/coef_l_mode,key_version_imp
     *	/v_com7/pne_vic(npo)
     *	/v_com8/q_halo,q_stop_re
     *	/v_com9/d_rsep,p_sep2
     *	/v_com10/rsep0,zsep0,dl_dt,dl_dt_avr,pow_re
     *  /v_com11/ppr_imp(npo),ppr_neut(npo)









c----  for PET subroutines...

	common
     *  /c_wrk1/wrk(nwnh)

	common
     *  /c_pet1/coef_pet
     *  /c_pet2/ui(nr,nz)
     *  /c_pet3/rwork(nbndp),zwork(nbndp)
     *  /c_pet4/ind(nbndp)
     *  /c_pet5/ngav

	common
     *  /c_bound1/x_b(nbndp),y_b(nbndp),c_b(nbndp)
     *  /c_bound2/green_b(nbnd,nbnd),green_ves(nbnd*mu)
     *  /c_bound3/g(nr,nz),dgdn(nbndp),psi_bound(nbndp)

	common
     *  /c_ves1/ind_ves(mu)
     *  /c_ves2/itok_ves(mu),jtok_ves(mu)
     *  /c_ves3/nmx_ves(mu)
     *  /c_ves4/r_ves(nmax,mu),z_ves(nmax,mu),a_ves(nmax,mu),
     *  turn_ves(nmax,mu)


	common
     *  /c_map1/x_map(npo,ntet),y_map(npo,ntet)
     *  /c_map2/p_nor(npo)
     *  /c_map3/k_map
     *  /c_map5/e_pol(npo),dl_pol(npo)
     *  /c_map6/dfdpsi(npo)
     *  /c_map7/psi_volt(npo),c_pp(npo)
     *  /c_map8/tok_pl
     *  /c_map9/c_2(npo),c_3(npo),v_i(npo),cur_pol(npo)
     *  /c_map10/w(nr,nz),w0(nr,nz),psi0(nr,nz),pspl_0(nr,nz)
     *  /c_map11/fff(nr,nz)
     *  /c_map12/fdm(npo)


        common
     *  /graf1/tri,tri_up,tri_dw,el_up,el_dw
     *  /graf2/q_99

	common
     *  /c_tab1/pstab(npo),pptab(npo),fptab(npo),qtab(npo)
     *  /c_tab2/nutab
     *  /c_tab3/pptab0(npo),fptab0(npo)




       	common
     *  /c_vec1/vec_br(kf),vec_bz(kf)


	include 'parf_tcv'


       	common
     *  /c_tcv1/pf_exp(kf),t_exp(ntime)
     *  /c_tcv2/n_time
     *  /c_tcv3/bp_exp(nprobe),ps_exp(nloop)

     *  /c_tcv4/k_inp,k_out,k_est,k_int

     *  /c_tcv5/cp_ref(n_inp),cp(n_inp),cp_exp(n_inp),g_cont(n_inp)
     *  /c_tcv6/r_comp(kf),extra_res(kf)
     *  /c_tcv7/tay_p(kf)
     *  /c_tcv8/v_prog(kf),v_ful(kf)
     *  /c_tcv9/est(n_inp,n_est)
     *  /c_tcv10/a_mat(n_int,n_int),b_mat(n_int,n_inp),
     *  c_mat(n_out,n_int),d_mat(n_out,n_inp)
     *  /c_tcv11/a_1(n_int,n_int)

     *  /c_tcv12/x_cont(n_int),x0_cont(n_int)
     *  /c_tcv13/u_cont(n_out)

     *  /c_tcv14/vch0(kf),pf_ref(kf)
     *  /c_tcv15/cp_calc(n_inp)
     *  /c_tcv16/u0_cont(n_out)
     *  /c_tcv17/v_ful_2(kf)
!!!!     *  /c_tcv18/t_vde

c*** Victor's common blocks
     *   /vic_1/uact
      

c  control....

	common 
     *  /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
     *  /cont21/n_ga,n_int_c

	common 
     *  /c_ktm_1/vs_bound


	common
     *	/c_index1/index_li(nwnh)
     *	/c_index2/index_ves(nwnh)
     *	/c_index3/index_pl(nwnh)
     *	/c_index4/ind_halo(nwnh)
     *	/c_index5/ind_shape(kf),i_ip


c  here Gen subroutine common blocks
	common
     *  /gen1/n_gen
     *  /gen2/a1_gen(mu,mu)
     *  /gen3/a_gen(mu,mu)
     *  /gen5/t_gen(mu),t_gen0(mu)
     *  /gen6/d0(mu),d1(mu),d2(mu)

     *  /gen7/n_gen2
     *  /gen8/b1_gen(mu,mu)
     *  /gen9/index(kf)
     *  /gen10/res_gen(mu)
	
	common
     *	/c_add1/omg_ppx
     *	/c_add2/pf_ohm(kf)
     *	/c_add3/rsep2,zsep2,psep2
     *	/c_add4/alf_ves
     *	/c_add5/f_tor(npo),f_tor0(npo),ps_tor(npo)
     *	/c_add6/p_mag,pmag0,p_bound,pbound0

     *	/c_add7/psi_val(nwnh),pff_val(nwnh)
     *	/c_add8/n_val
     *  /c_add9/f_cur(nwnh)

     *	/c_add10/n_pol,n_pol_fi
     *  /c_add11/a_pol(npo),a_pol_fi(npo)
     *	/c_add12/n_tor
!!!     *	/c_add13/sp_t0
!!!     *	/c_add14/i_tab
 	common 
     *	/c_add13/sp_t0,c_halo_corr
     *  /c_add14/i_tab,i_halo_corr


     *	/c_add15/psi_min,psi_max


c TRANSPORT COMMONS....

	common
     *  /c_tran1/k_ion,pow_el,pow_ion
     *  /c_tran2/tbs(2*npo+2)
     *  /c_tran3/q_e,q_i
     *  /c_tran4/aj0_uv(npo)
     *  /c_tran5/pin_b(npo),pin_b0(npo),p_beam(npo)
     *  /c_tran6/tpl_uv
     *  /c_tran7/k_tran
     *  /c_tran8/tqc

c  Pellet Commons...

	
     *  /c_pel3/time_pel

c  BEAM Commons...

	common
     *  /inj0/i_beam
     *  /inj2/klz0,z_0,ab
     *  /inj3/t_inj
     *  /inj4/aj0_b(npo)
     *  /inj5/b_shape(npo)
     *  /inj6/pn_beam(npo)
     *  /inj7/p_b_par(npo),p_b_per(npo)
     *  /inj8/r_py
     *  /inj9/i_null
     *  /inj10/tpl_beam
     *  /inj11/s_beam(npo)
     *  /inj12/eee2,sb2(npo),s_beam2(npo)
     *  /inj13/power_beam
     *  /inj14/coef_beam_loss
     *  /inj15/aj0_ion(npo),aj0_el_cor(npo),pow_b_el(npo),pow_b_ion(npo)


c  D3D BEAM Commons...

	parameter ( n_ie=3, n_ib=8)

	common
     *  /d_inj0/p_b_tot(n_ib),frac_b(n_ie,n_ib)
     *  /d_inj1/e_b(n_ie,n_ib),p_b(n_ie,n_ib)
     *  /d_inj2/angl_b(n_ib),r_b(n_ib)
     *  /d_inj3/key_beam(n_ib)
     *  /d_inj4/ie_b,ib_b
     *  /d_inj5/sb_b(n_ie,n_ib,npo),ajb_b(n_ie,n_ib,npo)

c LOWER Hybrid

	common
     *  /c_lh0/i_lh
     *  /c_lh1/power_lh,tpl_lh
     *  /c_lh2/aj0_lh(npo),sb_lh(npo)

c ECH

	common
     *  /c_ech0/i_ech
     *  /c_ech1/power_ech1,tpl_ech1
     *  /c_ech2/aj0_ech1(npo),sb_ech1(npo)
     *  /c_ech3/power_ech2,tpl_ech2
     *  /c_ech4/aj0_ech2(npo),sb_ech2(npo)

     *  /c_ech5/power_ech,tpl_ech
     *  /c_ech6/aj0_ech(npo),sb_ech(npo)
     *  /c_ech7/p_e1,r_e1,z_e1,dz_e1,dr_e1
     *  /c_ech8/p_e2(10),r_e2(10),z_e2(10),dz_e2(10),dr_e2(10)
     *  /c_ech9/key_ech,k_bu
     *  /c_ech10/ro_ech,del_ech
     *  /c_ech11/num_ech

     *  /c_ech12/power_ech3,tpl_ech3
     *  /c_ech13/aj0_ech3(npo),sb_ech3(npo)
     *  /c_ech14/c_e2(10)
     *  /c_ech15/del_ech0
     *  /c_ech16/aj0_ech_1(npo),sb_ech_1(npo)
     *  /c_ech17/tpl_ech_1,power_ech_1

c zyb commons

        common /c_zyb1/q_min,i_min

c eni_st commons

        common 
     *  /c_eni1/dxe_ref(npo)
     *  /c_eni2/te_can(npo),tq_can(npo)

c*** from Victor

	common 
     *  /c_vic1/q_pr,r_lh,k_rlw

c  For ECH and ECH3 
     *  /c_vic2/key_dir,key_dir3
     *  /c_vic3/yr0,yr03,dyr0,dyr03
     *  /c_vic4/ro_uv_ech,del_uv_ech,pow_uv_ech
     *  /c_vic5/ro_uv_ech3,del_uv_ech3,pow_uv_ech3


c Runaway
	common
     *  /c_ae3/sp_p,sp_p0,r_avr,d_aev,d_enae
     *  /c_ae4/paj(npo),paj0(npo)



c  passive twin loops Commons...

	common
     *  /c_pas1/n_pas
     *  /c_pas2/n_pas1,n_pas2,n_pas3
     *  /c_pas3/alf_pas1,alf_pas2,alf_pas3

c ASDEX 
	common
     *  /c_asdex1/d_beta
     *  /c_asdex2/i_up,i_dw
     *  /c_asdex3/r_bge

	common
     *  /ef_6/num_shot    

c*** Victor's common
	common/c_sol_vic1/x_up,y_up,x_dw,y_dw
	common /c_sol_vic2/ dcur_dl1(10),dcur_dl2(10),rcur1(10),
     *  zcur1(10),rcur2(10),zcur2(10)
	common/c_sol_vic4/k_e,k_tch,k_i,r_e,z_e,r_i,z_i

c  Feedback additinal
     *  /c_feed1/n_push


C---- ohwaki mod '04/03/21 ----

      common

c---- for sugihara subroutine in sugihara.f

     &     /ohwaki_1/ resist_ohwaki,Zave_ohwaki,

     &     dnH0_ohwaki,dnH_ohwaki,dnz0_ohwaki,dnz_ohwaki,dne_ohwaki,

     &     cl_ohwaki,csH0_ohwaki,csz0_ohwaki

c---- for difmf_1 subroutine in ddunew0.f

     &     /ohwaki_2/ key_ohwaki_1

C---- ohwaki mod '04/03/21 ----






	common /c_green1/pl_mut(npo,ntet)
	common /c_green2/psi_new(npo),psi_new0(npo)
	common /c_green3/f_ppx(nwnh),f_pffx(nwnh)
	common /c_green4/pspl_ppx(nwnh),pspl_pffx(nwnh)
	common /c_green5/work_ppx(nwnh),work_pffx(nwnh)

	common /c_green6/v_lim(mu_l),volt_lim(mu_l),volt_lim0(mu_l)
	common /c_green7/psi_norm(nwnh),ind_norm(nwnh)

	common /c_green8/pl_green(10*ntet),psex_green(10*ntet)
	common /c_green9/r_green(10*ntet),z_green(10*ntet)
	common /c_green10/n_green
	common /c_green11/key_fil


c  d3d smal common blocks...
	common
     *  /c_smal_1/bz_tot,bz_pf,bz_ves,bz_pl
     *  /c_smal_2/dbz_tot,dbz_pf,dbz_ves,dbz_pl
     *  /c_smal_3/f_index_br,f_index_pf,f_index_ves
     *  /c_smal_4/pf_volts(kf)
     *  /c_smal_5/br_tot,br_pf,br_ves,br_pl

	common
     *  /c_vs1/fdd_ext,pll_ext
     *  /c_vs2/fdd_ext0,pll_ext0
c*** for CHEARS

	common
     *  /c_tug1/s_int_al(npo),s_int_b(npo)
     *  /c_tug2/den_b(npo),den_b2(npo)


c*** from Volodia Dokuka
	common
     *  /c_vol1/QNET_B(npo),SAL_B(npo)
     *  /c_vol2/betj_b
     *  /c_vol3/ro_pl(npo,ntet)
     *  /neutral/a_neut(npo)


	common
     *  /c_br1/i_fil(nwnh,npo)
     *  /c_br2/pspl_pp(nwnh),f_pp(nwnh)
     *  /c_br3/ps_pl(nwnh,npo),pff_fil(nwnh,npo)
     *  /c_br4/wdh,p_oh
     *  /c_br5/u_res,res_t
     *  /c_br6/i_av,pll_av
     *  /c_br7/pll_2,pll_20,fdd_2,fdd_20,udd_ext
     *  /c_br8/udd_ex,udd_sol,vs_ex,vs_sol

	common 
     *  /c_psi_95/
     *  eu_95,el_up_95,el_dw_95,elong_95,tri_up_95,
     *  tri_dw_95,tri_95,rout_95,zout_95,asp_95


	
c tpl_uv commons

        common /temp_ptot1/ptot_uv
        common /temp_ptot2/ptot
        common /temp_ptot3/wel,wio
        common /temp_ptot4/coef_prim
        common /temp_ptot5/p_avr_he,p_avr_imp

c  Additional commons for open field lines

	common /c_open1/um0,vm0,uk0(ntet),vk0(ntet)
	common /c_open2/uk_open(ntet),vk_open(ntet)
	common /c_open3/k_open

c  Additional commons for helisity ramp

	common /c_hel1/hel_step

c  Additional commons for NSTX

		common
     *  /c_nstx1/i_nstx
     *  /c_nstx2/psi_axis
     *  /c_nstx3/x2

        common 
     *  /c_ener2/ro_bar,alf_bar
     *  /c_ener3/plasma_coef
     *  /c_ener4/r_mid,z_mid

c  Additional commons for Forces

        common 
     *  /c_force1/f_ves_r,f_ves_z,f_pf_r,f_pf_z




	common 
     *  /c_lim1/r_lim(4),z_lim(4),psi_lim(4)
     *  /c_lim2/r_cur(4),z_cur(4),tok_cur(4)


         common /c_v71_2/key_ne,key_equil



!        common 
!     *  /c_imp1/sel(npo)

c  FEFE commons------

	    include 'parf2.inc'
    	parameter ( nbw_max=200)

        common 
     *  /c_fele1/psi_fe(npo,ntet),igr_fe(nyz),plcur_fe(nyz),fi(nyz)
     *  /c_fele2/kyz,klg
     *  /c_fele3/nel,nel4,nbw
     *  /c_fele4/aj_fe(2*nyz+2*nyz*(nbw_max))
     *  /c_fele5/ia(nyz),ja(2*nyz+2*nyz*(nbw_max))
!!!     *  /c_fele6/difx(nyz),dify(nyz),cond(nyz),fin(nyz),ds_fe(nyz)


	common /setka/xx(nyz),yy(nyz),ne(nyz,4),ng_fe(nyz,4),ns(nyz,4)


     *  /c_par1/ro_field(npo,ntet)
     *  /c_par2/a_field(npo,ntet),a_field0(npo,ntet),cur_den(npo,ntet),
     *  sigma(npo,ntet),a_fieldn(npo,ntet),cur_fi(npo,ntet),
     *  a_ext(npo,ntet),a_int(npo,ntet),a_int0(npo,ntet)
     *  /c_par3/uc(npo,ntet),vc(npo,ntet),curc(npo,ntet),ds(npo,ntet)
	
c CD

	parameter ( n_cd=5)

	common
     *  /c_cd0/i_cd,k_cd,key_cd(n_cd)
     *  /c_cd1/power_cd(n_cd),tpl_cd(n_cd)
     *  /c_cd2/ro_cd(n_cd),del_cd(n_cd),pow_cd(n_cd)
     *  /c_cd3/aj_cd(npo,n_cd),sb0_cd(npo)
     *  /c_cd4/aj0_cd(npo)
     *  /c_cd4/tpl0_cd,power0_cd



c  additional  for runaways..
	common
     *  /c_run1/e_par(npo)
     *  /c_run2/cur_ohm(npo)
     *  /c_run3/qdg_ohm(npo),qdg_crit(npo)

	common
     *  /c_run4/pne_psi(npo),te0_psi(npo),zeff_psi(npo),
     * ajae_psi(npo),e_par_psi(npo),tok1_psi(npo),ro_psi(npo)

	common /c_imp_out4/qe0_av_prim,qe0_av_plas,pd0_av,
     * pt0_av,pn_av,pn1_av,pn0_av,ppr_imp_av

	common /c_imp_out5/pn0_av_imp,
     *  vt0_imp,prog_n0_imp

	common /c_imp_out6/pn_beam_av

	common
     *	/c_i_sym/i_sym



















