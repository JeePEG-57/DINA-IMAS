!>  write_data_in_time is a subroutine to output the 0D DINA-IMAS parameters
!>  through the internal array wr:
!>  wr(1)-time,[s]
!>  wr(2)-plasma current,[MA]
!>  wr(3)-plasma major radius,[m]
!>  wr(4)-plasma minor radius,[m]
!>  wr(5)-plasma elongation
!>  wr(6)-plasma triangularity
!>  wr(7)-plasma volume,[m3]
!>  wr(8)-plasma poloidal cross section,[m2]
!>  wr(9)-plasma surface area,[m2]
!>  wr(10)-R coordinate of the plasma current center,[m]
!>  wr(11)-Z coordinate of the plasma current center,[m]
!>  wr(12)-vertical speed of the plasma current center,[m*s^-1]
!>  wr(13)-R coordinate of the magnetic axis,[m]
!>  wr(14)-Z coordinate of the magnetic axis,[m]
!>  wr(15)-in case of divertor plasma-R coordinate of the X-point and in  
!! case of limiter plasma-R coordinate of the plasma-wall touching point,[m]
!>  wr(16)-in case of divertor plasma-Z coordinate of the X-point and in  
!!  case of limiter plasma-Z coordinate of the plasma-wall touching point,[m]
!>  wr(17)-the value of q on the magnetic surface where PSI/PSIbnd=0.95
!>  wr(18)-the value of q on the magnetic axis
!>  wr(19)-li(3)
!>  wr(20)-BETA poloidal
!>  wr(21)-volume averaged electron density,[19m^-3]
!>  wr(22)-Greenwald ratio
!>  wr(23)-volume averaged density of the main ion species,[19m^-3]
!>  wr(24)-volume averaged electron temperature,[keV]
!>  wr(25)-picking factor of the electron temperature
!>  wr(26)-volume averaged ion temperature,[keV]
!>  wr(27)-picking factor of the ion temperature
!>  wr(28)-Zeff
!>  wr(29)-plasma loop voltage
!>  wr(30)-resistive losses of the poloidal magnetic flux,[Wb]
!>  wr(31)-Ejima coefficient
!>  wr(32)-averaged over the plasma poloidal magnetic flux, produced
!! by all external circuits,[Wb]
!>  wr(33)-averaged over the plasma poloidal magnetic flux, produced
!! by the CS and PF coils,[Wb]
!>  wr(34)-averaged over the plasma poloidal magnetic flux, produced
!! by all extrenal circuits and plasma,[Wb]
!>  wr(35)-current in the coil CS3U,[kA]
!>  wr(36)-current in the coil CS2U,[kA]
!>  wr(37)-current in the coils CS1U and CS1L connected in series,[kA]
!>  wr(38)-current in the coil CS2L,[kA]
!>  wr(39)-current in the coil CS3L,[kA]
!>  wr(40)-current in the coil PF1,[kA]
!>  wr(41)-current in the coil PF2,[kA]
!>  wr(42)-current in the coil PF3,[kA]
!>  wr(43)-current in the coil PF4,[kA]
!>  wr(44)-current in the coil PF5,[kA]
!>  wr(45)-current in the coil PF6,[kA]
!>  wr(46)-voltage produced by the converter CS3U,[kV]
!>  wr(47)-voltage produced by the converter CS2U,[kV]
!>  wr(48)-voltage produced by the converter CS1U and CS1L connected 
!! in series,[kV]
!>  wr(49)-voltage produced by the converter CS2L,[kV]
!>  wr(50)-voltage produced by the converter CS3L,[kV]
!>  wr(51)-voltage produced by the converter PF1,[kV]
!>  wr(52)-voltage produced by the converter PF2,[kV]
!>  wr(53)-voltage produced by the converter PF3,[kV]
!>  wr(54)-voltage produced by the converter PF4,[kV]
!>  wr(55)-voltage produced by the converter PF5,[kV]
!>  wr(56)-voltage produced by the converter PF6,[kV]
!>  wr(57)-current of the converter VS1,[kA]
!>  wr(58)-current of the converter VS2,[kA]
!>  wr(59)-current of the converter VS3,[kA]
!>  wr(60)-voltage produced by the converter VS1,[kV]
!>  wr(61)-voltage produced by the converter VS2,[kV]
!>  wr(62)-voltage produced by the converter VS3,[kV]
!>  wr(63)-total power of the converters in the circuits CS,PF,VS1 and VS2,[MW]
!>  wr(64)-power requested from the electric grid,[MW]
!>  wr(65)-power of the Ohmic heating,[MW]
!>  wr(66)-power of the auxiliary heating,[MW]
!>  wr(67)-power of theplasma heating by alfa-particle,[MW]
!>  wr(68)-fusion power,[MW]
!>  wr(69)-neutron fluence,[MW*h]
!>  wr(70)-power gain Q
!>  wr(71)-total heating power,[MW]
!>  wr(72)-power threshold for L to H mode transition Plh,[MW]
!>  wr(73)-ratio Psep/Plh
!>  wr(74)-plasma magnetic energy,[MJ]
!>  wr(75)-plasma inductance,[H]
!>  wr(76)-plasma thermal energy,[MJ]
!>  wr(77)-plasma resistance,[mkOhm]
!>  wr(78)-L/R plasma current decay time,[s]
!>  wr(79)-content of He
!>  wr(80)-content of Be
!>  wr(81)-content of W
!>  wr(82)-content of Ar
!>  wr(83)-content of Ne
!>  wr(84)-power of the bremsstrahlung radiation,[MW]
!>  wr(85)-power of the cyclotron radiation,[MW]
!>  wr(86)-power of Be radiation,[MW]
!>  wr(87)-power of W radiation,[MW]
!>  wr(88)-power of Ar radiation,[MW]
!>  wr(89)-power of Ne radiation,[MW]
!>  wr(90)-total power of the impurity radiation,[MW]
!>  wr(91)-total power of the radiation,[MW]
!>  wr(92)-power loss through the plasma boundary due to conductivity 
!! and convection,[MW]
!>  wr(93)-plasma energy confinement time,[s]
!>  wr(94)-in divertor phase R coordinate of the upper X-point (belonging 
!! to the outer separatrix); in limiter phase =0
!>  wr(95)-in divertor phase Z coordinate of the upper X-point (belonging 
!! to the outer separatrix); in limiter phase =0
!>  wr(96)-in divertor phase is the distance between the inner and outer 
!! separatrix in the plasma mid plane (in the outboard region); <0 when 
!! the inner separatrix has upper X-point; in limiter phase =0
!>  wr(97)-in divertor phase, if the upper X-point is located inside of 
!! first wall, is R coordinate of the outer strike point; otherwise =0,[m]
!>  wr(98)-in divertor phase, if the upper X-point is located inside of 
!! first wall, is Z coordinate of the outer strike point; otherwise =0,[m]
!>  wr(99)-vertical component of the poloidal magnetic field in the inboard 
!! points of the plasma boundary belonging to the plane Z=Zmag,[T] 
!>  wr(100)-vertical component of the poloidal magnetic field in the outboard 
!! points of the plasma boundary belonging to the plane Z=Zmag,[T] 
!>  wr(101)-minimum distance between the plasma boundary and the first wall,[m]
!>  wr(102)-R coordinate of the point of the first wall which is the 
!! closest to plasma boundary,[m]  
!>  wr(103)-Z coordinate of the point of the first wall which is the 
!! closest to plasma boundary,[m]
!>  wr(104)-distance between the separatrix inner strike point and the bottom 
!! of the divertor inner vertical target plate; =0 means that the separatrix 
!! inner leg strikes the inner reflector plate,[m]   
!>  wr(105)-distance between the separatrix inner strike point and the bottom 
!! of the divertor outer vertical target plate; =0 means that the separatrix 
!! inner leg strikes the outer reflector plate,[m]
!>  wr(106)-wr(129)- additional gaps between plasma boundary and 
!! fixed points,[m]   

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
        include 'parf0'
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

     *  /c_br4/wdh,p_oh
     *  /vic_psi_av/psipl_av,psiext_av
	  common                                                                 
     *  /ge2/NTAY,TAY,TT_com                                                  
     *  /ge5/kpr                                                        
     *  /ge7/eu,rout,zout,elong

        common
     *  /graf1/tri,tri_up,tri_dw,el_up,el_dw
     *  /dfm13/tokel,tokfi,tokbut
     *  /dfm13e/tokuv
     *  /dfm14/tokae,ajae(npo),ajae0(npo),enae

	common
     *  /c_grib2/rp1,zp1,dist1,rp2,zp2,dist2
     *  /vic_018/r_lh_new
     *  /maksim_03/wr(150),wr_imas(150)
      common 
     * /c_imas_t_end2/t_end2
        
        !include 'imas_interface.inc'
        
        
        dimension dNB_xx(24)


        
c******* Begin of Sign changing ******
        tpl_imas=tpl*(-1)

        pf1_imas=pf1*(-1)
        pf2_imas=pf2*(-1)
        pf3_imas=pf3*(-1)
        pf4_imas=pf4*(-1)
        pf5_imas=pf5*(-1)
        pf6_imas=pf6*(-1)
        pf7_imas=pf7*(-1)
        pf8_imas=pf8*(-1)
        pf9_imas=pf9*(-1)
        pf10_imas=pf10*(-1)
        pf11_imas=pf11*(-1)

        zv1_imas=zv1*(-1)
        zv2_imas=zv2*(-1)
        zv3_imas=zv3*(-1)
        zv4_imas=zv4*(-1)
        zv5_imas=zv5*(-1)
        zv6_imas=zv6*(-1)
        zv7_imas=zv7*(-1)
        zv8_imas=zv8*(-1)
        zv9_imas=zv9*(-1)
        zv10_imas=zv10*(-1)
        zv11_imas=zv11*(-1)

        Curr_vs1_imas=Curr_vs1*(-1)
        Curr_vs2_imas=Curr_vs2*(-1)

        U_vs1_imas=U_vs1*(-1)
        U_vs2_imas=U_vs2*(-1)
        
        
        uact_imas = -uact
        
c******* End of Sign changing ******

	  i_en=i_en+1


c        if(kpr.eq.1)print*,'from write coef_imp1 coef_imp2',coef_imp1,coef_imp2
c        if(kpr.eq.1)print*,'w_imp w_imp2 w_imp3',w_imp,w_imp2,w_imp3


c--------------------

        tpl_but=tokbut*1.e-3
        tpl_beam=tokuv*1.e-3
        tpl_ecd=tokae*1.e-3

        tpl_ohm=tpl*1.e-3-( tpl_but+tpl_beam+tpl_ecd)
        
!        tpl_ohm=-tokel*1.e-3

!        r_lh_new=(wdop+w_alfa+Pohm-w_imp-wtor-qc)/p_hl
        r_lh_new=p_sep_tot/p_hl
        if(kpr.eq.1)print*,'r_lh_new=',r_lh_new
        
        if(kpr.eq.1)print*,'tpl_but tpl_beam tpl_ecd tpl_ohm ',
     *  tpl_but,tpl_beam,tpl_ecd,tpl_ohm
        
        if(i_plasma1.eq.1)then
        
        if(i_en.eq.1)then
           open (unit=41,file='plasma1.dat',form='formatted')
           write(41,*)'tt,tpl,tpl_ohm,tpl_but,tpl_ecd,tpl_beam'
        else
           open (unit=41,file='plasma1.dat',access='append',
     *     form='formatted')           
        end if
           write (41,5002)tt*1.d-3,tpl*1.d-3,tpl_ohm,tpl_but,
     *   tpl_ecd,tpl_beam
           close (41)

        end if
        
c-----------------


	call tri_filter(tri)


	t=tt/1.e3
	p_cond=wel+wio
        coef_He=palf/pcch

        if(wdop.lt.1.e-5)qtep=0.
        
        pohm=wdh

c*** Begin of sign changing ***
        psiext_av_imas=psiext_av*(-1)
        psi_pf_imas=psi_pf*(-1)
        psi_ax_imas=psi_ax*(-1)
c*** End of sign changing ***

cc        psi_ext=psiext_av
        psi_ext=psiext_av_imas
        
        Emag=psipl_av*tpl/1000./2.

        pl_inductance=2.*Emag/tpl**2

c        print*,'emag  pl_inductance=',Emag,pl_inductance
c        print*,'tri=',tri

c        read(*,*)

      

!        if(kpr.eq.1)print*,'!!!w_imp2,w_imp3,w_imp4,w_imp5',
!     *   w_imp2,w_imp3,w_imp4,w_imp5

        w_Be=w_imp2
        w_W=w_imp3
        w_Ar=w_imp4
        w_Ne=w_imp5

        Pvs1=Curr_vs1*U_vs1
!        Pvs3=Curr_vs3*U_vs3
        Ptotal=Pvs1+Pvs2+pf1*zv1+pf2*zv2+pf3*zv3+pf4*zv4+
     *  pf5*zv5+pf6*zv6+pf7*zv7+pf8*zv8+pf9*zv9+pf10*zv10+pf11*zv11


        if(i_en.eq.1)then
!           open (unit=41,file='Pvs3.dat',form='formatted')
!           read(41,*)
           Pvs3=0.
 !          close (41)
        end if


        if(kpr.eq.1)print*,'Curr_vs3 U_vs3 Pvs3',Curr_vs3,U_vs3,Pvs3
c        read(*,*)


      Pvs30= Pvs3
 
      Tf=0.05

      coef_t=Tf/(tay*1.e-3)

 !     (Pvs3-Pvs30)*coef_t+Pvs3= Curr_vs3*U_vs3

      Pvs3=(Pvs30*coef_t+ Curr_vs3*U_vs3)/(1.+coef_t)
      
      
      Pvs3_rg=Pvs3
      
      if(Pvs3_rg .gt. 5.)Pvs3_rg=5.
      if(Pvs3_rg .lt. 0.)Pvs3_rg=0.
      
        if(kpr.eq.1)print*,' Pvs3 Pvs3_rg=',Pvs3,Pvs3_rg

      P_rg=Ptotal+Pvs3_rg

c	open (unit=41,file='Pvs3.dat',
c     *	form='formatted')
c	write(41,*)'Pvs3 '
c	write (41,*)Pvs3
c	close (41)


	call bp_gribov(bz_left,bz_right)

        if(kpr.eq.1)print*,' bz_left,bz_right=',bz_left,bz_right

        if(i_en.gt.1)then
	   open (unit=65,file='plasma.dat',
     *	access='append',form='formatted')
        end if
        
        if(i_en.eq.1)then
	   open (unit=65,file='plasma.dat',
     *	form='formatted')

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
     *  dNB_xx,dist2,dist1'

c     * wdop,qtep,w_fusion,pf2,pf6,cs2L,cs1,cs2U,volume 
c     * tokc zvel'

	end if

		do i=1,24
			dNB_xx(i)=dNB_xx(i)/100.
		end do	
					
	wr(1)=t
	wr(2)=tpl_imas/1000.
	wr(3)=rout/100.
	wr(4)=eu/100.
	wr(5)=eksk
	wr(6)=tri   !! %%% one needs to do it 
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
	wr(29)=uact_imas
	wr(30)=vs
	wr(31)=c_e_old
	wr(32)=psi_ext !!!! %%% one needs to need to add tcam to psi_pf 
	wr(33)=psi_pf_imas
	wr(34)=psi_ax_imas
	wr(35)=pf1_imas
	wr(36)=pf2_imas
	wr(37)=pf3_imas
	wr(38)=pf4_imas
	wr(39)=pf5_imas
	wr(40)=pf6_imas
	wr(41)=pf7_imas
	wr(42)=pf8_imas
	wr(43)=pf9_imas
	wr(44)=pf10_imas
	wr(45)=pf11_imas
	wr(46)=zv1_imas
	wr(47)=zv2_imas
	wr(48)=zv3_imas
	wr(49)=zv4_imas
	wr(50)=zv5_imas
	wr(51)=zv6_imas
	wr(52)=zv7_imas
	wr(53)=zv8_imas
	wr(54)=zv9_imas
	wr(55)=zv10_imas
	wr(56)=zv11_imas
	wr(57)=Curr_vs1_imas
	wr(58)=Curr_vs2_imas
	wr(59)=Curr_vs3
	wr(60)=U_vs1_imas
	wr(61)=U_vs2_imas
	wr(62)=U_vs3
	wr(63)=Ptotal
	wr(64)=P_rg   !!!!! we will do it later
	wr(65)=Pohm     !!!! %%% one needs to add Ohmic power in MW
	wr(66)=wdop
	wr(67)=w_alfa
	wr(68)=w_fusion
	wr(69)=gfus
	wr(70)=qtep
	wr(71)=wdop+w_alfa+Pohm   !!! take care about Pohm !
	wr(72)=p_hl
cccccc	wr(73)=r_lh
	wr(73)=r_lh_new
	wr(74)=Emag  !!! we will do it later
	wr(75)=pl_inductance !!! we will do it later 
	wr(76)=wen2/1000.
        wr(77)=-(uact+1.e-8)/wr(2)
        wr(78)=wr(75)/wr(77)*1.e6

	wr(79)=coef_He
	wr(80)=coef_imp1
	wr(81)=coef_imp2
	wr(82)=coef_imp3
	wr(83)=coef_imp4
	wr(84)=wtor
	wr(85)=qc
	wr(86)=w_Be
	wr(87)=w_W
	wr(88)=w_Ar
	wr(89)=w_Ne
	wr(90)=w_imp
	wr(91)=w_imp+wtor+qc
	wr(92)=p_sep_tot
	wr(93)=tene/1000.
	wr(94)=rsep2/100.
	wr(95)=zsep2/100.
	wr(96)=gaps(n_ga+1)/100.
	wr(97)=rsep2_r/100.
	wr(98)=zsep2_r/100.
	wr(99)=bz_left
	wr(100)=bz_right
	wr(101)=dist_min_xx/100.
	wr(102)=Rdist_min_xx/100.
	wr(103)=Zdist_min_xx/100.
	wr(104)=dist2/100.
	wr(105)=dist1/100.
        
        write(65,5002)(wr(i),i=1,105),dNB_xx

 5002   format (150(1pe14.6))

	close (65)

	
	
        wr_imas(1)=t
        wr_imas(2)=tpl_imas*1000.
        wr_imas(3)=rout/100.
        wr_imas(4)=eu/100.
        wr_imas(5)=eksk
        wr_imas(6)=tri   !! %%% one needs to do it 
        wr_imas(7)=v
        wr_imas(8)=s
        wr_imas(9)=s_plasma
        wr_imas(10)=r_cur/100.
        wr_imas(11)=z_cur/100.
        wr_imas(12)=zvel
        wr_imas(13)=rmag/100.
        wr_imas(14)=zmag/100.
        wr_imas(15)=rsep/100.
        wr_imas(16)=zsep/100.
        wr_imas(17)=q_95
        wr_imas(18)=q_ax
        wr_imas(19)=uli   !!! %%% one needs to divide into rout
        wr_imas(20)=betpj
        wr_imas(21)=pcch*1.d19
        wr_imas(22)=gamma
        wr_imas(23)=pion*1.d19
        wr_imas(24)=tec
        wr_imas(25)=te_ax/tec
        wr_imas(26)=tqc
        wr_imas(27)=tq_ax/tqc
        wr_imas(28)=zeff_a
        wr_imas(29)=uact
        wr_imas(30)=vs
        wr_imas(31)=c_e_old
        wr_imas(32)=psi_ext !!!! %%% one needs to need to add tcam to psi_pf 
        wr_imas(33)=psi_pf_imas
        wr_imas(34)=psi_ax_imas
        wr_imas(35)=pf1_imas*1.d3
        wr_imas(36)=pf2_imas*1.d3
        wr_imas(37)=pf3_imas*1.d3
        wr_imas(38)=pf4_imas*1.d3
        wr_imas(39)=pf5_imas*1.d3
        wr_imas(40)=pf6_imas*1.d3
        wr_imas(41)=pf7_imas*1.d3
        wr_imas(42)=pf8_imas*1.d3
        wr_imas(43)=pf9_imas*1.d3
        wr_imas(44)=pf10_imas*1.d3
        wr_imas(45)=pf11_imas*1.d3
        wr_imas(46)=zv1_imas*1.d3
        wr_imas(47)=zv2_imas*1.d3
        wr_imas(48)=zv3_imas*1.d3
        wr_imas(49)=zv4_imas*1.d3
        wr_imas(50)=zv5_imas*1.d3
        wr_imas(51)=zv6_imas*1.d3
        wr_imas(52)=zv7_imas*1.d3
        wr_imas(53)=zv8_imas*1.d3
        wr_imas(54)=zv9_imas*1.d3
        wr_imas(55)=zv10_imas*1.d3
        wr_imas(56)=zv11_imas*1.d3
        wr_imas(57)=Curr_vs1_imas*1.d3
        wr_imas(58)=Curr_vs2_imas*1.d3
        wr_imas(59)=Curr_vs3*1.d3
        wr_imas(60)=U_vs1_imas*1.d3
        wr_imas(61)=U_vs2_imas*1.d3
        wr_imas(62)=U_vs3*1.d3
        wr_imas(63)=Ptotal*1.d6
        wr_imas(64)=P_rg*1.d6   !!!!! we will do it later
        wr_imas(65)=Pohm*1.d6     !!!! %%% one needs to add Ohmic power in MW
        wr_imas(66)=wdop*1.d6
        wr_imas(67)=w_alfa*1.d6
        wr_imas(68)=w_fusion*1.d6
        wr_imas(69)=gfus*(1.d6/3.6d3)
        wr_imas(70)=qtep
        wr_imas(71)=(wdop+w_alfa+Pohm)*1.d6   !!! take care about Pohm !
        wr_imas(72)=p_hl*1.d6
cccccc  wr_imas(73)=r_lh
        wr_imas(73)=r_lh_new
        wr_imas(74)=Emag*1.d6  !!! we will do it later
        wr_imas(75)=pl_inductance !!! we will do it later 
        wr_imas(76)=wen2*1000.
        wr_imas(77)=wr_imas(29)/wr_imas(2)
        wr_imas(78)=wr_imas(75)/wr_imas(77)

        wr_imas(79)=coef_He
        wr_imas(80)=coef_imp1
        wr_imas(81)=coef_imp2
        wr_imas(82)=coef_imp3
        wr_imas(83)=coef_imp4
        wr_imas(84)=wtor*1.d6
        wr_imas(85)=qc*1.d6
        wr_imas(86)=w_Be*1.d6
        wr_imas(87)=w_W*1.d6
        wr_imas(88)=w_Ar*1.d6
        wr_imas(89)=w_Ne*1.d6
        wr_imas(90)=w_imp*1.d6
        wr_imas(91)=(w_imp+wtor+qc)*1.d6
        wr_imas(92)=p_sep_tot*1.d6
        wr_imas(93)=tene/1000.
        wr_imas(94)=rsep2/100.
        wr_imas(95)=zsep2/100.
        wr_imas(96)=gaps(n_ga+1)/100.
        wr_imas(97)=rsep2_r/100.
        wr_imas(98)=zsep2_r/100.
        wr_imas(99)=bz_left
        wr_imas(100)=bz_right
        wr_imas(101)=dist_min_xx/100.
        wr_imas(102)=Rdist_min_xx/100.
        wr_imas(103)=Zdist_min_xx/100.
        wr_imas(104)=dist2/100.
        wr_imas(105)=dist1/100.
	
        do i=1,24
           wr_imas(105+i)=dNB_xx(i)
        end do  

        if(tt.gt.t_end2)then
           do i=3,34
              wr_imas(i)=0.
           end do

           do j=65,150
              wr_imas(j)=0.
           end do
        end if
        

	return
	end

