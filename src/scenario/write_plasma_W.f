      subroutine write_data_in_time(
     *	tt,tpl,betpj,eu,uli,r_cur,z_cur,p_sep,wel,wio,eksk,
c     *	pcch,zeff_a,tec,te_ax,tqc,tq_ax,tene,zsep,c_e_old,c_e_new,
     *	pcch,zeff_a,tec,te_ax,tqc,tq_ax,tene,zsep,rsep,c_e_old,c_e_new,
     *  rmag,gamma,vs,q_95,q_ax,zvel,psi_pf,psi_ax,uact,
     *  pf1,pf2,pf3,pf4,pf5,pf6,pf7,pf8,pf9,pf10,pf11,
     *  pf12,
     *  zv1,zv2,zv3,zv4,zv5,zv6,zv7,zv8,zv9,zv10,zv11,
     *  U_vs1,U_vs3,Curr_vs1,Curr_vs3,
     *  r_lh,wdop,
     *  qtep,w_fusion,w_alfa,s_plasma,p_sum,P_HL,zmag,
     *  wtp,wtor,qc,w_imp,gfus,p_sep_tot,
     *  dist_min_xx,Rdist_min_xx,Zdist_min_xx,
     *  dNB_xx)

c     *  wdop,qtep,w_fusion,
c     *  pf2,pf6,cs2L,cs1,cs2U,volume,z_tok,tokc,zvel_out)

	include 'double.inc'
        include 'parf8'

        common
     *  /c_ramp2/rsep2,zsep2,psep2
     *  /en28/wen1,wen2
     *  /v_surface/s,v
     *  /v_epol/epol
     *  /cont21/n_ga,n_int
     *  /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
     *  /vic_008/rsep2_gr,zsep2_gr,rsep2_l,zsep2_l,
     *           rsep2_r,zsep2_r
     *  /vic_012/pion,palf,w_imp2,w_imp3,w_imp4,w_imp5
     *  /vic_imp/coef_imp,nz_imp
     *  /vic_imp1/coef_imp1,nz_imp1
     *  /vic_imp2/coef_imp2,nz_imp2
     *  /vic_imp3/coef_imp3,nz_imp3
     *  /vic_imp4/coef_imp4,nz_imp4

        dimension dNB_xx(24)

c        if(kpr.eq.1)print*,'from write coef_imp1 coef_imp2',coef_imp1,coef_imp2
c        if(kpr.eq.1)print*,'w_imp w_imp2 w_imp3',w_imp,w_imp2,w_imp3

	t=tt/1.e3
	p_cond=wel+wio
        coef_He=palf/pcch

        if(kpr.eq.1)print*,'from write_plasma coef_He=',coef_He

        if(kpr.eq.1)print*,'!!!w_imp2,w_imp3,w_imp4,w_imp5',
     *   w_imp2,w_imp3,w_imp4,w_imp5

        w_Be=w_imp2
        w_W=w_imp3
        w_Ar=w_imp4
        w_Ne=w_imp5

        Pvs1=Curr_vs1*U_vs1
        Pvs3=Curr_vs3*U_vs3
        Ptotal=Pvs1+Pvs2+Pvs3+pf1*zv1+pf2*zv2+pf3*zv3+pf4*zv4+
     *  pf5*zv5+pf6*zv6+pf7*zv7+pf8*zv8+pf9*zv9+pf10*zv10+pf11*zv11

	call bp_gribov(bz_left,bz_right)

	   open (unit=65,file='plasma.dat',
     *	access='append',form='formatted')

	i_en=i_en+1
        if(i_en.eq.1)then

	   write(65,*)
     *'t,tpl/1000.,betpj,eu,uli,r_cur,z_cur,p_sep,eksk, 
     * pcch,pion,zeff_a,tec,te_ax/tec,tqc,tq_ax/tqc,zsep,rsep,c_e,
     * rmag,zmag,gamma,vs,q_95,q_ax,zvel,psi_pf,psi_ax,uact,
     *  pf1,pf2,pf3,pf4,pf5,pf6,pf7,pf8,pf9,pf10,pf11,
     *  zv1,zv2,zv3,zv4,zv5,zv6,zv7,zv8,zv9,zv10,zv11,
     *  U_vs1,U_vs2,U_vs3,Curr_vs1,Curr_vs2,Curr_vs3,
     *  tene,r_lh,wdop,qtep,w_fusion,w_alfa,s_plasma,p_sum,P_HL,
     *  v,epol,wen2,gfus,p_sep_tot,
     *  bz_left,bz_right,
     *  dist_min_xx,Rdist_min_xx,Zdist_min_xx,
     *  coef_He,coef_imp1,coef_imp2,
     *  dNB_xx'

c     * wdop,qtep,w_fusion,pf2,pf6,cs2L,cs1,cs2U,volume 
c     * tokc zvel'

	end if

        write(65,5002)
     *	t,tpl/1000.,betpj,eu,uli,r_cur,z_cur,p_sep,eksk,
ccc     * pcch,zeff_a,tec,te_ax/tec,tqc,tq_ax/tqc,zsep,c_e_old,c_e_new,
c     * pcch,zeff_a,tec,te_ax/tec,tqc,tq_ax/tqc,zsep,c_e_old,
     * pcch,pion,zeff_a,tec,te_ax/tec,tqc,tq_ax/tqc,zsep,rsep,c_e_old,
     * rmag,zmag,gamma,vs,q_95,q_ax,zvel,psi_pf,psi_ax,uact,
     *  pf1,pf2,pf3,pf4,pf5,pf6,pf7,pf8,pf9,pf10,pf11,
     *  zv1,zv2,zv3,zv4,zv5,zv6,zv7,zv8,zv9,zv10,zv11,
     *  U_vs1,U_vs2,U_vs3,Curr_vs1,Curr_vs2,Curr_vs3,
     *  Ptotal,Pvs1,Pvs2,Pvs3,
     *  tene/1000.,r_lh,wdop,qtep,w_fusion,w_alfa,s_plasma,p_sum,P_HL,
     *  v,epol,wen2/1.e3,
c     *  wtp,wtor,qc,w_imp,gfus,rsep2,zsep2,gaps(n_ga+1),
     *  wtp,wtor,qc,w_imp,w_Be,w_W,w_Ar,w_Ne,gfus,rsep2,zsep2,
     *  gaps(n_ga+1),
     *  rsep2_r,zsep2_r,p_sep_tot,
     *  bz_left,bz_right,
     *  dist_min_xx,Rdist_min_xx,Zdist_min_xx,
     *  coef_He,coef_imp1,coef_imp2,coef_imp3,coef_imp4,
     *  dNB_xx

c     *  cs3u,cs2u,cs1,cs2l,cs3l,pf1,pf2
c     * 	wdop,qtep,w_fusion,pf2,pf6,cs2L,cs1,cs2U,volume,
c     *  tokc,zvel

c	if(kpr.eq.1)print*,'from victor_N'
c	if(kpr.eq.1)print*,'tt pf10',tt,pf10
c	read(*,*)


 5002   format (150(1pe14.6))

	close (65)


	return
	end

