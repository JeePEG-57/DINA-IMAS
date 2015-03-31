      subroutine write_data_in_time(
     *	tt,tpl,betpj,eu_xx,uli,r_cur,z_cur,p_sep,wel,wio,eksk,
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
     * /ge7/eu,rout,zout,elong

     *  /c_br4/wdh,p_oh
     *  /vic_psi_av/psipl_av,psiext_av


        dimension dNB_xx(24),wr(150)

c        if(kpr.eq.1)print*,'from write coef_imp1 coef_imp2',coef_imp1,coef_imp2
c        if(kpr.eq.1)print*,'w_imp w_imp2 w_imp3',w_imp,w_imp2,w_imp3

	t=tt/1.e3
	p_cond=wel+wio
        coef_He=palf/pcch
        
        pohm=wdh
        psi_ext=psiext_av

        if(kpr.eq.1)print*,'from write_plasma coef_He=',coef_He

        if(kpr.eq.1)print*,'!!!w_imp2,w_imp3,w_imp4,w_imp5',
     *   w_imp2,w_imp3,w_imp4,w_imp5

        w_Be=w_imp2
        w_W=w_imp3
        w_Ar=w_imp4
        w_Ne=w_imp5

        Pvs1=Curr_vs1*U_vs1
!        Pvs3=Curr_vs3*U_vs3
        Ptotal=Pvs1+Pvs2+pf1*zv1+pf2*zv2+pf3*zv3+pf4*zv4+
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

		do i=1,24
			dNB_xx(i)=dNB_xx(i)/100.
		end do	
					
	wr(1)=t
	wr(2)=tpl/1000.
	wr(3)=rout/100.
	wr(4)=eu/100.
	wr(5)=eksk
	wr(6)=triangularity !! %%% one needs to do it 
	wr(7)=v
	wr(8)=s
	wr(9)=s_plasma
	wr(10)=r_cur/100.
	wr(11)=z_cur/100.
	wr(12)=zvel
	wr(13)=rmag/100.
	wr(14)=zmag/100.
	wr(15)=rsep/100.
	wr(16)=zsep/100.
	wr(17)=q_95
	wr(18)=q_ax
	wr(19)=uli   !!! %%% one needs to divide into rout
	wr(20)=betpj
	wr(21)=pcch
	wr(22)=gamma
	wr(23)=pion
	wr(24)=tec/1000.
	wr(25)=te_ax/tec
	wr(26)=tqc/1000.
	wr(27)=tq_ax/tqc
	wr(28)=zeff_a
	wr(29)=uact
	wr(30)=vs
	wr(31)=c_e_old
	wr(32)=psi_ext !!!! %%% one needs to need to add tcam to psi_pf 
	wr(33)=psi_pf
	wr(34)=psi_ax
	wr(35)=pf1
	wr(36)=pf2
	wr(37)=pf3
	wr(38)=pf4
	wr(39)=pf5
	wr(40)=pf6
	wr(41)=pf7
	wr(42)=pf8
	wr(43)=pf9
	wr(44)=pf10
	wr(45)=pf11
	wr(46)=zv1
	wr(47)=zv2
	wr(48)=zv3
	wr(49)=zv4
	wr(50)=zv5
	wr(51)=zv6
	wr(52)=zv7
	wr(53)=zv8
	wr(54)=zv9
	wr(55)=zv10
	wr(56)=zv11
	wr(57)=Curr_vs1
	wr(58)=Curr_vs2
	wr(59)=Curr_vs3
	wr(60)=U_vs1
	wr(61)=U_vs2
	wr(62)=U_vs3
	wr(63)=Ptotal
	wr(64)=Pgrid   !!!!! we will do it later
	wr(65)=Pohm     !!!! %%% one needs to add Ohmic power in MW
	wr(66)=wdop
	wr(67)=w_alfa
	wr(68)=w_fusion
	wr(69)=gfus
	wr(70)=qtep
	wr(71)=wdop+w_alfa+Pohm   !!! take care about Pohm !
	wr(72)=p_hl
	wr(73)=r_lh
	wr(74)=Emag  !!! we will do it later
	wr(75)=pl_inductance !!! we will do it later 
	wr(76)=wen2/1000.
	wr(77)=coef_He
	wr(78)=coef_imp1
	wr(79)=coef_imp2
	wr(80)=coef_imp3
	wr(81)=coef_imp4
	wr(82)=wtor
	wr(83)=qc
	wr(84)=w_Be
	wr(85)=w_W
	wr(86)=w_Ar
	wr(87)=w_Ne
	wr(88)=w_imp
	wr(89)=w_imp+wtor+qc
	wr(90)=qtep
	wr(91)=tene/1000.
	wr(92)=rsep2/100.
	wr(93)=zsep2/100.
	wr(94)=gaps(n_ga+1)/100.
	wr(95)=rsep2_r/100.
	wr(96)=zsep2_r/100.
	wr(97)=bz_left
	wr(98)=bz_right
	wr(99)=dist_min_xx/100.
	wr(100)=Rdist_min_xx/100.
	wr(101)=Zdist_min_xx/100.

        write(65,5002)(wr(i),i=1,101),dNB_xx

 5002   format (150(1pe14.6))

	close (65)


	return
	end

