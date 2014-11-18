	include 'parf0'
	include 'parf1'
	parameter ( NPFC=KF-4)
	include 'parf2'
	include 'parf2e'
	include 'parf3'
	include 'parf4'
	include 'parf5'

	include 'parf7'
	include 'parf8'

	common
     *	/n_m/n,m,mp

	common
     *  /igr/ygr(iy,ny),tgr(ny),igr

	common
     *	/ge1/pi
     *	/ge1e/rs0,tpl
     *  /ge2/NTAY,TAY,TT
     *  /ge2e/t_end
     *	/ge3/AI(npo),A0(npo),HA2(npo),a(npo),ha(npo)
     *  /ge4/EPS1,EPS2,EPS0
     *  /ge5/kpr
     *  /ge6/zeff(npo),qpr(npo),ppr(npo),pr0,prg,zar
     *  /ge6e/zeff_a,zeff_b
     *  /ge7/eu,rout,zout,elong
     *  /ge7e/eu_u
     *  /ge8/pcch
     *  /ge8e/pcchp
     *  /ge12e/indpf(kf),seps1,seps2,seps3

	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nr),y(nz),dx,dy
     *  /eq1e/psext(nwnh),re(nre),ze(nze),dr,dz
     *  /eq4/xpl(npo,ntet),ypl(npo,ntet)
     *  /eq6/sinus(ntet),cosin(ntet)
     *  /eq11/psval(npo),psval0(npo)
     *  /eq15/pll,zsep,rsep,zsepup,rsepup,zsepdw,rsepdw
     *  /eq15e/pll0,tpl0,udd

	common
     *  /DFM2/PSI8(npo),PFI(npo),DM0(npo),DMN(npo)
     *  /dfm3e/dfmaxc(npo),dfmaxh(npo)
     *  /dfm3/dfmax(npo),dfmax0(npo)
     *  /dfm4/Q(npo),ANU(npo),P(npo),F(npo),PP(npo),PFF(npo)
     *  /dfm5/pt01,pt02
     *  /dfm7/bt0,uind
     *  /dfm11/c20(npo),tok1(npo),tok2(npo)

	common
     *  /pol2/Qx(npo),ANUx(npo),Px(npo),Fx(npo),
     *   PPxx(npo),PFFxx(npo)
     *  /pol4/UM,VM,UK(ntet),VK(ntet)
     *  /pol5/psend
     *  /pol6/ppx(npo),pffx(npo)

	common
     *	/efit4/coef_efit
     *	/efit5/it1,it2

	common
     *  /en1/PNE(npo),PD0(npo),PT0(npo),PH0(npo),PDN(npo),
     *  PTN(npo),PHN(npo)
     *  /en1e/te_a,ti_a,te_b,ti_b,pw_e
     *  /en1d/te_a0
     *  /en2/TE0(npo),TQ0(npo),TEN(npo),TQN(npo),WE0(npo),
     *  WQ0(npo)
     *  /en2e/pd0_a,pt0_a,pd0_b,pt0_b,pw_p
     *  /en6/Vn(npo)
     *  /en14e/t_dop
     *  /en14/EMOE,EMOQ,NDOP,QDE0(npo),QDQ0(npo)
     *  /en33/anom_e,anom_i,key_t11,kcchp



	common
     *  /cont1/vchopper(kf),veps
     *  /CONT5/	FCOM(NPFC)
     *  /cont6/cip1,cip2,time1,time2
     *	/cont9/brad,kefit
     *  /cont13/zmag,zvel,delrmag,delzmag
     *  /cont13e/zmag0,rmag,rmag0,rvel
     *	/cont18/t_vde,time_disr
     *  /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
     *  /cont21/n_ga,n_int

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
     *  /keys10/ngra
     *  /keys12/i_v
	

	common
     *  /halo2/kmaj,k_q,k_d,kaxis,ndisrup
     *  /halo2e/next0,li_drop,n_li,n_dif,nmix
     *  /halo3/tay_00,tay_th,t_disr,d_tpl,tpl_end
     *  /halo4/expfg,avalb,w_h,del_r,al0
     *  /halo10/fves,fves0,self_v

        common
     *	/con1/gain,ta,zref,kzref
     *  /con2/rref,krref,bvert
	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf7/plasma(kf),plasma0(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)
         
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
     *  /fluxc11/npl,pl_cur(nwnh),x_cur(nwnh),y_cur(nwnh)
     *	/fluxc10/x1,y1,dx1,dy1
     *  /fluxc18/alf_tok,int_tok


       	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves3/b(mu,mu),pmj(mu,mu)
     *  /ves4/rcam(mu)
     *  /ves5/pfc(mu,kf)
     *  /ves6/pind(mu),pind0(mu),pindn(mu)
     *  /ves9/tokc,tokc0

	common
     *  /loop1/kloop,RL(nloop),ZL(nloop),psloop(nloop)
     *  /loop2/pfgreen(nloop,kf),vesgreen(nloop,mu)
     *  /loop3/vloop,psf1a,psf1a0
     *  /loop6/psloopp(nloop)
	common
     *  /probe1/kprobe,bprobe(nprobe)
     *  /probe2/pfprobe(nprobe,kf),vesprobe(nprobe,mu)
     *	/probe4e/bprgreene(nwnhe,nprobe)
     *  /probe5/bprobep(nprobe)

c  here new coomon block values begin.....

	common
     *  /c_ge1/b_tor(nr,nz)
     *  /c_ge2/kp
     *  /c_ge3/dmo
     *  /c_ge4/rmag_in,zmag_in
     *  /c_ge5/ksepa 

	common
     *  /c_keys1/i_comp,i_ma,k_sh,k_force,k_magn
     *  /c_keys2/i_st


c  here new common blocks Victor has done...

	common
     *	/v_keys1/time_svd

c control keys...
	common
     *  /con_keys1/k_dm0


	common
     *  /c_avr1/int_2000

c  here Gen subroutine common blocks
	common
     *  /gen1/n_gen
     *  /gen2/a1_gen(mu,mu)
     *  /gen3/a_gen(mu,mu)
     *  /gen6/d0(mu),d1(mu),d2(mu)

     *  /gen7/n_gen2
     *  /gen8/b1_gen(mu,mu)
     *  /gen9/index(kf)

	common
     *  /c_con4/vps(npfc),kvert(npfc)
     *  /c_con7/volt(kf)

c  here we start D3D control keys------
	common
     *  /c_cont1/r_r,r_l1,r_l2,r_3
     *  /c_cont2/v_e
     *  /c_cont3/tau_p,tau_i,tau_d,ECOIL_GP,ECOIL_GD,ECOIL_GI,
     *  /c_cont4/e_inp,p_out
     *  /c_cont5/v_out,vecoil
     *  /c_cont6/key_time,int_read
     *  /c_cont7/tt_ext,tay_ext
     *  /c_cont8/key_con_ext

     *  /c_cont9/g_r_p(2),g_r_d(2),g_r_i(2)
     *  /c_cont10/g_z_p(2),g_z_d(2),g_z_i(2)
     *  /c_cont11/z_vel,t_zvel
     *  /c_cont12/r_vel,t_rvel

     *  /c_cont13/ps_com(kf),ps_out(kf)
     *  /c_cont14/volt_chop(kf)
     *  /c_cont15/eps_com
     *  /c_cont16/n_pcs
     *  /c_cont17/fcom_pcs(kf)



c  new_halo common blocks...
	common
     *  /c_new_halo1/volt_tor(npo),volt_pol(npo),q_eq(npo)
     *  /c_new_halo6/u_h(nwnh)
     *  /c_new_halo8/fsol,fsol0,alf_dis

     *  /c_new_halo19/cur_tor(npo)


c  d3d common blocks...
	common
     *  /c_d3d_1/tpl_exp
     *  /c_d3d_2/taup,v_offset


c  d3d smal common blocks...
	common
     *  /c_smal_1/bz_tot,bz_pf,bz_ves,bz_pl
     *  /c_smal_2/dbz_tot,dbz_pf,dbz_ves,dbz_pl
     *  /c_smal_3/f_index_br,f_index_pf,f_index_ves
     *  /c_smal_4/pf_volts(kf)
     *  /c_smal_5/c_pf_res(kf)
     *  /c_smal_6/key_volt6,key_volt7
     *  /c_smal_7/bzz_pl

        include 'parf_mike1'

        common
     *  /c_d3d_mike1/pr(n_mat1,n_mat),pvm(n_mat,n_mat),
     *  pvr(n_mat,n_mat),pvv(n_mat,n_vec)
     *  /c_d3d_mike2/a1_mat(n_mat,n_mat)
     *  /c_d3d_mike3/volt_mat(n_vec),t_cur(n_mat1)
     *  /c_d3d_mike4/t_vec(n_mat),t_vec0(n_mat)

        common
     *  /c_verta1/verta,vertb,delta


       	common
     *  /c_ves1/res_coef
     *  /c_ves2/tok_tf

       	common
     *  /c_polar1/n_polar


	include 'parf_mario'


c*** new Victor's block 3 Sept. 1999
	common
     *	/v_jp/f_jp(nwnh)
     *	/v_t_edge/tec
c*** Turns of PF coils consistent with koor file!!!
     *	/v_turn/pf_turns(kf)
c*** new Victor's block June 2000
     *	/v_wr/i_wr	
     *	/v_surface/surface
     *	/v_ffw/u_ffw(kf)
     *  /v_delta_time/delta_time
     *	/v_r_lh/r_lh


c** it is used in cur, dop_port.inc, victor.f
     *  /vic_rz_cur/r_cur,z_cur,z_cur0
     *  /vic_kavin/u_1(num_coils),u_kd(num_coils)
     *	/vic_tay_simul/tay_simul,tt_1,tt_2
     *	/vic_elong_ref/elong_ref
     *	/vic_pf_p/pf_p(kf)
     *	/vic_mario_filt/state(kf_c),state_old(kf_c)
     *	/vic_mario_filt1/state_vert(kf_c),state_old_vert(kf_c)
     *	/vic_int_2005/int_2005
     *  /vic_satur/zvconverter(30),zvresist(30)
     *	/vic_mario_ksepa/ksepa_0
     *  /vic_elong/elong_sep
     *  /vic_rref/rref_0



	common
     *	/c_vec1/vec_br(kf),vec_bz(kf)

	common
     *  /abcdx/x_c(kf_c),x0_c(kf_c),gaps0(kf_c),d_gaps(kf_c)





	common
     *  /c_map1/x_map(npo,ntet),y_map(npo,ntet)
     *  /c_map2/p_nor(npo)
     *  /c_map3/k_map

        COMMON
     *  /mid1/C1(npo),C2(npo),C3(npo)
     *  /mid2/vi(npo),spo(npo)
     *  /mid2_0/vi0(npo),pfi0(npo)
     *  /mid2e/vol(npo),spov(npo),pcur(npo)
     *  /mid3/GRA1(npo),GRA2(npo)


	common
     *  /c_mit_r1/heli
     *  /c_mit_r2/t_beta,alf_beta
     *  /c_mit_r3/t_li














