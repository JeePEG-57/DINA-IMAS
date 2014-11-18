	subroutine equil()

	include 'double.inc'
	include 'new_com.inc'

	call equil_c(
     *  ncam,tcam,tcam0,pf,npf,nps,rps,zps,rout,bt0,pll,	
     *  rref_p,q,tay_simul,int_2000,int_2005,
     *       z_cur,z_cur0,r_cur,tt_1,tt_2,i_wr,
     *       ksepa,ksepa_0,gaps0,i_bound,
     &       r_tok,z_tok,r_tok0,z_tok0,zvel_tok,
     *       del_ramp,omega,
     *       ro_bar,alf_bar,vchopper,pf0,pf_p,key_lh,key_h_to_l,
     *       tt_dw,tt_h,betp_flat,coef_kessel_1,vs_start,tt_emo,omg_ppx,
     *       fdd,fdd0,tau_p,xu,yu,xu_dist,yu_dist,ke)

	return
	end


	subroutine equil_c(
     *  ncam,tcam,tcam0,pf,npf,nps,rps,zps,rout,bt0,pll,
     *  rref_p,q,tay_simul,int_2000,int_2005,
     *       z_cur,z_cur0,r_cur,tt_1,tt_2,i_wr,
     *       ksepa,ksepa_0,gaps0,i_bound,
     &       r_tok,z_tok,r_tok0,z_tok0,zvel_tok,
     *       del_ramp,omega,
     *       ro_bar,alf_bar,vchopper,pf0,pf_p,key_lh,key_h_to_l,
     *       tt_dw,tt_h,betp_flat,coef_kessel_1,vs_start,tt_emo,omg_ppx,
     *       fdd,fdd0,tau_p,xu,yu,xu_dist,yu_dist,ke)

	include 'double.inc'
	include 'parf0'
	include 'parf1'

	dimension pf(*),q(*),gaps0(*),vchopper(*),pf0(*),pf_p(*)
	dimension xu(*),yu(*),xu_dist(*),yu_dist(*)

	common

     *  /ge6e/zeff_a,zeff_b

     *	/n_m/n,m,mp
	common
     *	/keys1/i_graph
     *	/keys2/key_b
     *	/keys3/kzero,iread,iwrite
     *  /keys4/k_ener,k_uv
     *  /keys5/next
     *  /keys7/i_c
     *  /keys8/ndh
     *  /keys9/i_d3d,i_iter,i_smal
     *  /keys10/ngra
     *  /keys11/i_ramp
     *  /keys12/i_v
     *  /keys13/i_con,i_act
     *  /keys14/i_beta,i_gap5
     *  /keys15/i_br
     *  /keys17/i_feed,i_ecoil
	common
     *	/con1/gain,ta,zref,kzref
     *  /con2/rref,krref,bvert
     *  /con3/i_pf
     *  /con5/n_exp,k_cont
     *  /con6/ind_r(2),ind_z(2)
	common
     *  /pol4/ UM,VM,UK(ntet),VK(ntet)
	common
     *	/ge1/pi
     *	/ge1e/rs0,tpl
     *  /ge2/NTAY,TAY,TT
     *  /ge2e/t_end
     *  /ge4/EPS1,EPS2,EPS0
     *  /ge4e/it_v,it_pf
     *  /ge5/kpr
	common
     *  /cont13/zmag,zvel,delrmag,delzmag
     *  /cont13e/zmag0,rmag,rmag0,rvel
	common
     *	/efit4/coef
     *	/efit5/it1,it2
	common
     *  /DFM2/PSI(npo),PFI(npo),DM0(npo),DMN(npo)
	common
     *  /mid2/vi(npo),spo(npo)
     *  /mid3/GRA1(npo),GRA2(npo)
	common
     *  /en6/Vn(npo)
     *  /en14/EMOE,EMOQ,NDOP,QDE0(npo),QDQ0(npo)
     *  /en14e/t_dop
     *  /en33/anom_e,anom_i,key_t11,kcchp
	common
     *	/point1/r0,z0
     *  /halo2/kmaj,k_q,k_d,kaxis,ndisrup
     *  /halo2e/next0,li_drop,n_li,n_dif,nmix
     *  /halo3/tay_00,tay_th,t_disr,d_tpl,tpl_end
     *  /halo4/expfg,avalb,w_h,del_r,al0
     *  /halo5/q_vde,q_95,del_f,i_halo
     *  /halo9/fluxt,fluxt0
     *  /halo10/fves,fves0,self_v
        common
     *	/ge7/eu,rs,zout,eksk
     *  /ge7e/eu_u
        common
     *	/fluxc12/r00,z00,eu00
	common
     *	/cont18/t_vde,time_disr

	common
     *  /cont4/ZPP,RPP,WVSPIP,ZXP,ELP,SHAPE,GAPINP,
     *  DFZP, DFZP0
     *	/cont9/brad,kefit_old
     *	/efit0/kefit
	common
     *  /ef_0/key_ef
	common
     *  /c_con8/key_con

        common/vic_vic/coef_port

	dimension tcam(*),tcam0(*),ind(kf),pfhelp(kf)

	dimension uk_help(ntet),vk_help(ntet)
	dimension uk_help1(ntet),vk_help1(ntet)
	dimension uk_help2(ntet),vk_help2(ntet)

	character *20 apr

        kpr=1


c  ro edge barier
      ro_bar=0.9
c  alf of edge thermal barier

!	alf_bar=0.1
	alf_bar=1.

c      i_matlab=0 old case 
c      i_matlab=1 matlab greens reading 

	i_matlab=1

c  i_fil=0 old case without reconstruction
c  i_fil=1  reconstruction with Polar rmag.zmag
c  i_fil=2  reconstruction with OLD rectangular grid rmag.zmag
c  i_fil=3  reconstruction with rgeom.zgeom from filament reconstruction

	i_fil=0
	i_old=0

	i_map=1
ccc	i_map=0

c   del_psi from boundary...

	del_ramp=0.1

c---  we think ....???
	ARG=1.
	pi=4.*atan(ARG)
	coef=10./(4.*pi)
	ntay=0
c---

	call bet_li_dat()


	call read_data()
c	call shape_d3d()

	rref=r0

          open (unit=40,file='zvel_max.dat',form='formatted') 
          read (40,*) 
          read (40,*)zv_max
          read (40,*) 
          read (40,*)n_svd
          read (40,*) 
          read (40,*)i_avr
          read (40,*) 
          read (40,*)i_filter
          read (40,*) 
          read (40,*)tau_p
          
          if(kpr.eq.1)print *,' zv_max,n_svd,i_avr,i_filter,tau_p',
     *    zv_max,n_svd,i_avr,i_filter,tau_p
          
           close (40)

	   zv_max_help=zv_max
	   zv_max=1.e10


c  	call shape_f9a() 

c	if(kpr.eq.1)print *,' ENTER'
c	read (*,*)

	if(kpr.eq.1)print *,' END of READfor002'

	if(i_graph.eq.1)call initvm(10,10,800,780)
c	call initvm(10,10,800,780)

	call anglep()
	call angl_p()
	call ONE2()
c	call pl_bound_p()
	call pl_bound()

c!!!!!	call read_gaps()


	if(kpr.eq.1)print *,' i_matlab',i_matlab
c	read (*,*)

	if(i_matlab.eq.0)then

	CALL TOK()
	call shape_pf_iam() 
c	if(kpr.eq.1)print*,(pf(i),i=1,npf)
c	read(*,*)


        if(ntay.gt.next)call vic_shape_ip_iam()

c!!!!!!!!!!!!!!!!
      call brz_vec_r()

	call limiter()
	call vessel()
	call res_ves()
	call ves_pf_r()
	call cam_t()

      call pf_ind()
c--------------
c  here we multiply by c_pf_res all PF coils resistances...
	call coef_pf_res()
      call inv()
      if(kpr.eq.1)print *,' call to inv==='

      end if

	

	if(i_matlab.eq.1)then
c----------------------  FLAT files reading.....
        call flat_ext()
c----------------------  end of FLAT files reading.....
	call shape_pf_iam() 
      call brz_vec_r()

	else

	call read_flux()
	call loop_r()
	call prob_r()

	end if


c###	call inv_gen()
	call cam_t()
!      call inv()
	call inv_gen_pf()


	call f_40()
	if(i_fil.ge.1)then
	call read_fwt()
	call read_fwt_coef()
	end if


	i_bound=0


c!!!!!!!! NEW call....

	call plasma_bz()

	i_sh=1
	if(i_sh.eq.1.and.tt.lt.5000.)then
c$
           open (unit=40,file='I_v3a.dat',form='formatted') 
	   read (40,*)(tcam(i),i=1,ncam)
           close (40)
	do i=1,ncam
	   tcam(i)=tcam(i)*1000.
c	   if(kpr.eq.1)print*,tcam(i)
c	   read(*,*)
	end do

	call tcam_w()
c$
	call tcam_r()

	end if




  	call s_zpp()
  	call shape_rpp()
	rref=rref_p
	r0=rref
	z0=zref

	um=r0
	vm=z0

	if(ntay.le.next)call shape_ip()

c	if(kpr.eq.1)print*,(pf(i),i=1,npf)
c	pause


c!!!	call shape_volt()
c!!!	call shape_pow()

	call shape_emo()

c	if(i_iter.eq.1)	call f_40()

!!!	call read_flux()

c*** Input of PF turns - must be consistent with 'koor' file!
        call vic_turn()

c*** Input of Zeff waveform ***
        if(k_ener.eq.1)call vic_zeff_read()
        if(k_ener.eq.0)call prof_astra()
	call cur_prof()


	if(kefit.eq.5)call pet_tab()

      if(kefit.eq.4)then
      call prof_in()
      call shape_pf()
      call shape_tcam()
      call shape_rpp2()
      call shape_zpp2()
      
     	rref=rmag
     	zref=zmag
     	
	r0=rref
	z0=zref

	um=r0
	vm=z0
      end if


c	call read_sh()
c	call contr_r()
c------------

c	CALL TOK()

c----

	k_avr=1
	eu_a=amax1(eu,eu_u)
	call avr(r0,z0,1.5*eu,k_avr)
	call movem(i_c)
	i_bound=0

	if(key_b.eq.1)call read_psgrid()

c	call choppers()
c	read (*,*)


ccc!!!	zref=vm

c!!!	if(i_smal.eq.1)call prog_val()

	if(kpr.eq.1)print *,' i_ramp=',i_ramp

c        kpr=0

        ntay_h=ntay

        ntay=0

        if(i_ter.eq.1.and.i_c.eq.1)then
           eu_00=eu
           um_00=um
           vm_00=vm
        end if



c	if(i_smal.eq.1)call movem(i_c)

c	call flat_ext2()

	if(kpr.eq.1)print *,' call ptoke0=============='
	call ptoke0()
	pt0z=-tpl
	it1=1
	if(iread.eq.1)	then
           call read_write()
	call movem(i_c)
		i_bound=0

        end if

	int=0
	niter=1
	call ves_pind()
	self_v=0.2*fluxt0
	if(kpr.eq.1)print *,' sef_v===',self_v
c	read (*,*)
c	kpr=1

c*** reading of mode.dat file to chose mode of simulations
        call vic_wr()        
c        if(kpr.eq.1)print*,'i_wr=',i_wr
c        pause 'from main'

c!!!!!	i_wr=0
cccccc	i_wr=1
c	call shape_pf_iam() 
	if(i_wr.eq.0)call r_tokk()

c	if(kpr.eq.1)print*,(pf(i),i=1,npf)
c	pause


c*** vic Gaps_data for ramp-up stuff
        call vic_read_gaps()

 	if(i_fil.ge.1)then
	   call fil_dis_cir()
	end if

	if(tt.gt.2000.)go to 1
c	if(tt.gt.1000.)go to 1

	tt_1=tt

	tt=0.
	do i=1,10000
	   tt=tt+tay
	   
	   if(tt.ge.tt_1)go to 1

	   call shape_pf_iam() 
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!! Transfer PF_DINA_order to PF=PF_original_order !!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if(i_wr.eq.0)call r_tokk()

	   call ful()

c@@@	   call pf_volt()

c	   call DOPP()

	   call time_step()


	end do


1	continue

        do i=1,npf
           if(kpr.eq.1)print*,i,pf(i)
        end do
c        pause 'from main'
c*******************************

	if(kpr.eq.1)print *,' call ptoke1=============='
	niter=niter+1

        apr= 'pf 111 '
        if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf)

	if(kpr.eq.1)print *,' ZPP RPP BEFORE ptoke1',zpp,rpp
	call ptoke1()
	
	if(i_iter.eq.1.and.i_ramp.eq.0) then                                   
c        call gsvd0()
        end if
 

	if(i_c.eq.1)then

	if(niter.gt.2.and.niter.eq.3*(niter/3))then
	k_avr=1
	call avr(rout,zmag,eu,k_avr)

	call movem(i_c)
		i_bound=0

	end if

	if(niter.gt.1.and.niter.lt.5)then
	k_avr=1
	call avr(rout,zmag,eu,k_avr)

	call movem(i_c)
		i_bound=0

	end if

	end if

	if(kpr.eq.1)print *,' --um vm eu niter ntay',um,vm,eu,niter,ntay
c----------
c  plot magnetic surfaces...
	if(i_graph.eq.1) call graphic(it1,n)

	if(it1.ne.0)go to 1


      call ppx_pffx_save(1)
      
        call loopflux()                                                       
        call probefield()

 	call q_calc()
c
      if(kefit.eq.4)then
       kzref=0
        krref=0
      end if


      if(kzref.eq.1.and.krref.eq.1)then
	   eps2_help=eps2
	   eps2=1.d-5
         call stab(ich,i_graph)

         call ppx_pffx_save(1)

	if(i_c.eq.1)then
      k_avr=1
	call avr(rout,zmag,eu,k_avr)
      call movem(i_c)
      i_bound=0
	end if

      call stab(ich,i_graph)

	if(i_c.eq.1)then
      k_avr=1
	call avr(rout,zmag,eu,k_avr)
      call movem(i_c)
      i_bound=0
      call stab(ich,i_graph)
	end if


           kzref=0
           krref=0
	   eps2=eps2_help

      call ppx_pffx_save(1)
		
	end if

	if(i_graph.eq.1) call graphic(it1,n)

c	stop


c        call kpl_out()

c        read (*,*)

	int=int+1
	call polar_data()
	kp=1

	if(i_map.eq.0)then

      CALL POLAR1(n,mp,rs0,kp,pt0z)
	call polar_res()
	CALL BTA(n,mp,RS0)
	end if

	if(i_map.eq.1)then
	call map_tor()
	CALL BTA(n,mp,RS0)
!!!	call tab_w()
	end if
	
  	do j=1,mp
	   uk_help(j)=uk(j)
	   vk_help(j)=vk(j)
	end do
	um_help=um
	vm_help=vm
	
	
c	stop

	if(i_fil.ge.1)then
	call read_exp()
	call svd_fil()
	call ptoke1_fil_0()

	if(i_fil.eq.1)then
	call polar_fil()
	z_tok_pol=z_tok
	end if

	end if


c	if(int.eq.1)go to 1

c	call pfves_d3d()
c	call pfves()

c        ntay=ntay_h

        if(kpr.eq.1)print *,' ntay===',ntay

c        kzref=0

c        read (*,*)

	if(iwrite.eq.1)	then
	call read_write()
	stop
	end if

c	call pll_calc()
c----------------------------------
c  toroidal coordinates...

	call den_read()
c**** pcchp calculations with regards Greenwald limit
        call vic_dens()

c*** Here we are doing te0(n)=tq0(n)=g_edge*tec !!!
!!!        call vic_t_edge()

	if(i_map.eq.0)then
	call transf_data()
	else
	call transf_data_new()
	end if

      	VMAX=1.E5
      	DO I=1,n
    	VN(I)=VI(I)/VMAX
	end do

	if(k_ener.eq.1)call dens_prog()
	call pp_calc()

	if(k_ener.eq.1)CALL ENERGY(N)
	if(k_ener.ne.1)call enit(n)
      if(k_ener.eq.0)call prof_astra()
	call pp_calc()



c!!!	CALL BTA(n,mp,RS0)
	call DOPP()


c	call gen()

	call gen_pf()

	call ful()

c	call d3d_corr_pf()

c	call d3d_corr()
	call time_gen()
	call time_step()
	call time_st_ppx_pffx()

	call time_out()

	eps20=eps2

	rmag_in=rmag
	zmag_in=zmag
	del_r=0.
	next0=next
	k_q=0
	k_d=0
	kaxis=0
	i_di=0

	call ful()

	do i=1,npf
	   pfhelp(i)=pf(i)
	end do
c* vic  To read tay_simul
        call vic_tay()

        eps20_mem=eps20
c        kpr=0

c        if(kpr.eq.1)print*,'beginning!!!!!!!!!!!'
c        if(kpr.eq.1)print*,'rmag zmag',rmag,zmag
c        if(kpr.eq.1)print*,'r_cur z_cur',r_cur,z_cur
c        pause 'from main'

c	omega=1.

	key_h_to_l=0
	tt_h_to_l=1.e8

          open (unit=40,file='scen_data_3.dat',form='formatted') 
          read (40,*) 
          read (40,*)tt_emo,tt_h,tt_avr,betp_flat,coef_kessel_1,vs_start
           close (40)
c	   if(kpr.eq.1)print*,tt_dw,tt_h,betp_flat,coef_kessel_1,vs_start
c	   read(*,*)

	   omg_ppx=1.d0

         zref=zmag0


  	do j=1,mp
	   uk_help2(j)=uk_help(j)
	   vk_help2(j)=vk_help(j)
        end do

	um_help2=um_help
	vm_help2=vm_help

	del_tt=0.
	i_lim=0
	
	time_to=20.d6
	time_back=200.d6
	
	do i=1,ke
	   xu_dist(i)=xu(i)
	   yu_dist(i)=yu(i)
	end do

	if(kpr.eq.1)print *,' time_to time_back=',time_to,time_back

	call wr_tabppf()
        call wr_pf()
        call wr_tcam()
      call wr_rpp()
      call wr_zpp()

          open (unit=40,file='elm.dat',form='formatted') 
          read (40,*) 
          read (40,*)tt_elm,tay_elm
          read (40,*) 

	  close (40)


2323	continue


	tt=tt+tay
	ntay=ntay+1

      

      if(tt.gt.time_to.and.tt.le.time_back.and.i_lim.eq.0)then
      i_lim=1
	call new_lim(i_lim)
	end if
      if(tt.gt.time_back.and.i_lim.eq.1)then
      i_lim=2
	call new_lim(i_lim)
	end if
	



	if(tt.ge.93.41e3.and.tt.le.93.44e3)then
c	   del_tt=del_tt+tay
c	   if(del_tt.ge.1000.)then
c	      del_tt=0.
	      open (unit=70,file='tcam_kavin.dat',access='append',
     *      form='formatted') 
	      write (70,*)tt
	      write (70,5002)(tcam(i),i=1,ncam)
	      write (70,5002)(pf(i),i=13,15)
	      close (70)
c	   end if
	end if

 5002   format (150(1pe12.4))
c============================================================

	if(tt.gt.30.e3)zv_max=zv_max_help

c++++++++++++++++++++++++++++++++++++
c	if(tt.ge.150.e3)then
c	   call bp_gribov()
c	   stop
c	end if
c++++++++++++++++++++++++++++++++++++


c	if(kpr.eq.1)print *,' t_end==',t_end

c	if(kpr.eq.1)print*,(pf(i),i=1,npf)
c	if(kpr.eq.1)print*,'!!!!!'
c	read(*,*)


c        if(tt.gt.1020000.)kpr=1
c        kpr=1

        ksepa_0=ksepa

c        if(kpr.eq.1)print*,'ntay=',ntay
c        pause 'from main'

c****************
        eps20=eps20_mem
c        if(tt.gt.tt_1.and.tt.lt.tt_2)eps20=1.e-3
c****************

c	if(ntay.eq.100*(ntay/100).and.i_graph.eq.1)call endvm
c	if(ntay.eq.100*(ntay/100).and.i_graph.eq.1)call initvm(10,10,800,780)

c        coef_port=150.
c        if(tt.gt.25000.)read(*,*)coef_port


c*vic To read elong_ref
c        call vic_elong_read() 

c*vic
c        call r_volt()
c	if(ntay.gt.next+1)then
c	   call vic_portone()
c	end if

c	tt_elm=68.e3
ccc	tt_elm=69.98e3
ccc	tay_elm=1.

c	if(ntay.gt.next+1.and.tay.lt.99)then
!	if(ntay.gt.next+1.and.tay.lt.tay_simul*0.99.and.krref.eq.0)then
	if(ntay.gt.next+1.and.tay.lt.tay_simul*0.99
     *   .and.tt.lt.tt_elm)then
	   tay=tay*1.2
	if(kpr.eq.1)print *,' HERE tay has chaged tay==',tay
c*vic	   if(tay.gt.100.)tay=100.
c	   if(tay.gt.20.)tay=20.
c	   if(tay.gt.10.)tay=10.
	   if(tay.gt.tay_simul)tay=tay_simul
c	   if(tay.gt.5.)tay=5.
      	call cam_t()
!         call inv()
	   call inv_gen_pf()
	end if

c****** tay decreasing ******
	   if(tt.ge.tt_elm)then
c	      tay=tay/1.2
	      tay=tay/1.5
	      if(tay.lt.tay_elm)tay=tay_elm
	      call cam_t()
	      call inv_gen_pf()
	   end if
c***************************
	
c	if(kpr.eq.1)print *,' 2323 ntay tt=',ntay,tt
c	read(*,*)

c	if(ntay.eq.ngra*(ntay/ngra))then



	if(tt.gt.time_disr)i_di=i_di+1
	if(i_di.eq.1)ndisrup=ntay

	if(kpr.eq.1)print *,' ndisrup=== ntay ',ndisrup,ntay

c!!!	call index_calc()

	if(kpr.eq.1)print *,' END index==='

	if(i_c.eq.1)then	
	k_avr=1
	eu_a=amax1(eu,eu_u)
        zmag_0=0.
	call avr(rout,zmag,eu_a,k_avr)

	call movem(i_c)
		i_bound=0
	end if

	if(kpr.eq.1)print *,' END movem==='

!	if(ntay.ge.next)tt=tt+tay

	if(kpr.eq.1)print *,' ntay ndisrup tt tay===========',ntay,
     *	ndisrup,tt,tay

	int_dif=0

	if(tt.ge.t_dop)ndop=1

	int_2000=0

	i_sh=0

  	call s_zpp()
  	call shape_rpp() 
	rref=rref_p

	call vic_shape_elong()

	if(ntay.le.next)call shape_ip()

c!!!	call shape_volt()
c!!!	call shape_pow()

c**********************
c	if(tt.ge.tt_dw)then
c	   emoe_help=emoe
c	   emoq_help=emoq 
c	end if
c**********************	


	call den_read()
c**** pcchp calculations with regards Greenwald limit
        call vic_dens()
c*** Input of Zeff waveform and ***
        if(k_ener.eq.1)call vic_zeff_read()
c$
c*vic  	call shape_pf_iam() 
  
c*** To read Ip and PF_p preprogrammed waveforms (in DINA order)
c*** from scr_data file 
	if(kpr.eq.1)print*,'@@@@@from main'

      call vic_shape_ip_iam()
	if(i_wr.eq.0.and.ntay.gt.next)call r_tok_p()

c	if(kpr.eq.1)print*,(pf(i),i=1,npf)
c	if(kpr.eq.1)print*,'111'
c	read(*,*)

c	call shape_3() 
c	call shape_4() 

c	call gen_cor()

	if(ntay.gt.next)then
c	   kzref=0
	end if

c	if(kzref.eq.0)call v_act()

	if(tpl.lt.-1000.)i_tpl=1

	if(i_tpl.eq.1)then
	   krref=0
	end if

!	bt0=bt0*rs0/rout
!	rs0=rout

c	if(kpr.eq.1)print *,' bt0 rs0==',bt0,rs0

c	call shape_ipp()

cc	if(ntay.gt.next+5)then
cc           call ip_it_feed()
cc	end if

c*** Forces for control calculations ***
ccc	if(ntay.gt.next)call f_cs()

	call li_d()

	call tem_con2()
	   
        call r_volt()

        call vic_gaps0_read()
	
	if(i_fil.ge.1)then

	z_tok0=z_tok

	call fil_dis_cir()

	call fwt_coef()
	call read_exp()

	call svd_fil()

	call ptoke1_fil_0()
      call get_gaps()


 	 zvel_tok=(z_tok-z_tok0)/tay

c	if(kpr.eq.1)print *,' i_fil==',i_fil

	if(ntay.gt.next.and.i_fil.eq.1)then 
	z_tok0=z_tok_pol
	call polar_fil()

	zvel_tok=(z_tok-z_tok0)/tay
	z_tok_pol=z_tok

c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!! Save PF to PF_original_order !!!!!!!!!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!! Transfer PF to PF_DINA_order !!!!!!!!!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	call SCEN_CONTROL_fil()
	end if

	if(ntay.gt.next.and.i_fil.eq.2)call SCEN_CONTROL(key_h_to_l)

	if(ntay.gt.next.and.i_fil.eq.3)then 
	call SCEN_CONTROL_fil()
	end if

	else

c  i_fil=0  old case without reconstruction....
	call separ_coor()                                                
	call separ_coor2()                                                
      call get_gaps()

ccc	if(ntay.gt.next.and.tt.gt.tt_h_to_l)key_h_to_l=1
	if(kpr.eq.1)print*,'!!!tt tt_h_to_l key_h_to_l',tt,tt_h_to_l,key_h_to_l

	if(ntay.gt.next)call SCEN_CONTROL(key_h_to_l)
ccc	if(ntay.gt.next.and.tt.lt.tt_h_to_l)call SCEN_CONTROL()
c!!!	if(tt.gt.tt_h_to_l+80.)call SCEN_CONTROL()

	end if





	call shape_emo()

c*************
	pnor=6.25e8
	if(tt.gt.tt_dw+20.)emoe=15.*pnor
	if(tt.gt.tt_dw+40.)emoe=0.
c*************

	if(kpr.eq.1)print*,'emoe=',emoe
	if(kpr.eq.1)print*,'!!!! tt tt_dw=',tt,tt_dw



c	if(kpr.eq.1)print*,'!!!!!tt key_lh key_h_to_l',
c     *       tt,key_lh,key_h_to_l

c!!!!!!!!!	if(ntay.gt.15)call vic_feed_aux()
ccccc	if(ntay.gt.15.and.key_lh.eq.1.and.tt.le.tt_h_to_l)
	if(ntay.gt.15.and.key_lh.eq.1.and.key_h_to_l.eq.0)
c	if(ntay.gt.15.and.key_lh.eq.1.and.tt.lt.tt_dw)
c	if(ntay.gt.15.and.key_lh.eq.1)
     *   call vic_feed_aux()

c	if(tt.ge.tt_dw)then
c	   emoe=emoe_help
c	   emoq=emoq_help 
c	end if


	if(tt.gt.200000..and.key_h_to_l.eq.1)then
	   emoe=0.
	   emoq=0.
	end if
c	if(kpr.eq.1)print*,'!!!tt emoe emoq',tt,emoe,emoq
c$




      i_kavin=0
      if(i_kavin.eq.1)then
      
c-------  calculate...


      int_2005=0
      
      it1=1
      
2006  continue
      
      int_2005=int_2005+1
         
	   call ppx_pffx()
	       
           kzref=1
           krref=2
           zref=zmag0
           rref=rmag0 
                     
           call ptoke1()
     
	if(int_2005.gt.10)eps2=eps2*1.5
	if(it1.ne.0.and.int_2005.lt.20)go to 2006

	if(kpr.eq.1)print *,'-+int_2005 eps2  ',int_2005,eps2

      end if !  for_kavin
      

c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!! Transfer PF_original_order to PF !!!!!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!! Transfer VCHOPPER_DINA_order to VCHOPPER !!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c*** Br, Bz in any point ***
c!!!!!	call vic_br_bz()

	it1=1
c----------
c  plot magnetic surfaces...
	if(i_graph.eq.1) call graphic(it1,n)
c--------------------

c	call w_sep_data()

          open (unit=40,file='time_ngra.dat',form='formatted') 
          read (40,*) 
          read (40,*)time1,time2
          read (40,*) 

	  close (40)

	  if(tt.ge.time1.and.key_ngra.eq.0)then
	     key_ngra=1
	     ngra_help=ngra
	     ngra=1
	  end if

	  if(tt.ge.time2)ngra=ngra_help

	if(ntay.eq.ngra*(ntay/ngra).or.ntay.eq.0)then
!!!	   call write_prof()
	   call write_prof0()
	if(kpr.eq.1)print *,' END write_prof '
         call  write_surf()
c         call  write_surf_eq()
	 call write_tok()
ccc	 call write_separ_coor()
ccc	 call write_separ_coor2()
	if(kpr.eq.1)print *,' END write_surf '

c	if(kpr.eq.1)print*,(pf(i),i=1,11)
c	read(*,*)

ccc           call kpl_out()
	end if

	if(tt.ge.93.43e5.and.k_cur_tor.eq.0)then
	   k_cur_tor=k_cur_tor+1
	   call cur_tor_out()
c	   stop
	end if
c	if(tt.ge.93.42e3.and.k_cur_tor.eq.1)then
c	   k_cur_tor=k_cur_tor+1
c	   call cur_tor_out()
c	   stop
c	end if

c%%%%%%% eqdsk writing %%%%%%%%%

	if(tt.ge.130.062e3.and.k_eqdsk.eq.0)then
	   k_eqdsk=k_eqdsk+1
	   call equidsk_write(k_eqdsk)
	   call te0_write(k_eqdsk)
	   call write_separ_coor()
	   call write_separ_coor2()
c	   stop
	end if

	if(tt.ge.130.0906e3.and.k_eqdsk.eq.1)then
	   k_eqdsk=k_eqdsk+1
	   call equidsk_write(k_eqdsk)
	   call write_separ_coor()
	   call write_separ_coor2()
c	   stop
	end if

	if(tt.ge.658.e3.and.k_eqdsk.eq.2)then
	   k_eqdsk=k_eqdsk+1
c	   call equidsk_write(k_eqdsk)
	   call write_separ_coor()
	   call write_separ_coor2()
	end if

	if(tt.ge.618.6e3.and.k_eqdsk.eq.3)then
	   k_eqdsk=k_eqdsk+1
c	   call equidsk_write(k_eqdsk)
	end if

	if(tt.ge.624.5e3.and.k_eqdsk.eq.4)then
	   k_eqdsk=k_eqdsk+1
c	   call equidsk_write(k_eqdsk)
	end if

	if(tt.ge.629.2e3.and.k_eqdsk.eq.5)then
	   k_eqdsk=k_eqdsk+1
c	   call equidsk_write(k_eqdsk)
	end if

      call ppx_pffx_save(2)

!	if(ntay.gt.20)then


      if(tt.le.61.66e9)then
      kzref=0	
      krref=0	

      if(kpr.eq.1)print *,' ++kzref tt',kzref,tt

      end if

!      n_svd=2
!      n_svd=20
       
      ntay1=ntay-1
      if( ntay1.eq.n_svd*( ntay1/n_svd ))then
	k_svd=0
     	do j=1,mp
	   uk_help1(j)=uk_help2(j)
	   vk_help1(j)=vk_help2(j)

	   uk_help2(j)=uk_help(j)
	   vk_help2(j)=vk_help(j)
        end do

	um_help1=um_help2
	vm_help1=vm_help2

	um_help2=um_help
	vm_help2=vm_help

      end if
      
      i_zvel=0

      k_svd=k_svd+1
      if(kpr.eq.1)print *,'k_svd ntay n_svd=',k_svd,ntay,n_svd




2000	continue
	int_2000=int_2000+1

      if(int_2000.le.2)then
	call gen_pf()
      end if

c	if(krref.eq.3)call pp_calc()

c	k_zyb=0
!!!	if(k_zyb.eq.0)then
!!!	if(k_zyb.eq.0.and.int_2000.eq.1)then

      
c
	if(k_zyb.eq.0)then


      call ppx_pffx_save(2)

      ngra2=1
	if(ntay.eq.ngra2*(ntay/ngra2).and.ntay.gt.20)then

      omg_ppx=omg_ppx*0.99
      if(omg_ppx.le.0.5d0)omg_ppx=0.5d0
 
!      omg_ppx=0.d0
     
      if(tt.lt.56930e9)then
	   call ppx_pffx()
	   call avr_ppx_pffx2()
	   
!         call ppx_pffx_corr2()

         call ppx_pffx_corr4()

      end if

	   else
!	   omg_ppx=1.d0
	end if


 
!	   call ppx_pffx()


ccc	   if(krref.eq.0.and.key_lh.eq.1)then 
c	   if(tt.gt.tt_h.and.tt.le.120.d3)then 
	   if(krref.eq.0.and.tt.gt.tt_avr)then 
c	   if(krref.eq.0.and.tt.gt.tt_h)then 
c*** Spline of plasma current

!	      call ppx_pffx_corr2()


c***    Plasma current averaging 
!!!	      call avr_ppx_pffx()
	   end if
	   	      
	end if

	zvel_0=zvel

	eps2=eps20
	int_2005=0

	if(krref.eq.-3)then
	   it1=0
	   go to 2001
	   end if



2005	continue
	int_2005=int_2005+1
c        if(i_iter.eq.1.and.i_ramp.eq.0.and.ntay.le.1)then                      
c        call gsvd0()
c        end if
c	call svd_d3d()

	if(kpr.eq.1)print *,' call ptoke1 i_bound',i_bound
	if(kpr.eq.1)print *,' ZPP RPP BEFORE ptoke1',zpp,rpp
	
	if(kpr.eq.1)print *,' kzref krref BEFORE ptoke1',kzref,krref

	do i=1,ncam
c	   tcam(i)=0.5*(tcam0(i)+tcam(i))
	end do


	call ptoke1()

	  call loopflux()                                                       
        call probefield()

c
c	call gen()

	call index_calc()

        rmag=um
        zmag=vm

c	call v_feed()

c*vic
c!!!!!!!!!!!!!        call r_volt()
c!!!!!!!!!!!!!        call get_gaps()
c	if(kpr.eq.1)print*,'z_cur r_cur',z_cur,r_cur
c        pause 'from main'
c        call vic_gaps0_read()

	if(ntay.gt.next)then
c! 	   kzref=0
c!c	   krref=0
c	   kzref=0
c	   krref=0
	brad=0.
	bvert=0.
c!!!	   call vic_z_feed()

c***
ccccccccccccccccccc           call SCEN_CONTROL()
c***

c!!!!!!!	   call vic_portone()
c	   call z_feed()
c	   call r_feed()
	end if

c	if(i_tpl.eq.1)then
c	   call r_feed()
c	end if

!!!	if(ntay.gt.next)call gen_pf()

c*** Setting currents mode !!!!! ***
c	if(kpr.eq.1)print*,pf0(5),ntay
c	vchopper(5)=1000.*pf0(5)*1.e3
c	if(ntay.gt.next)vchopper(5)=1000.*pf_p(5)*1.e3
c	if(kpr.eq.1)print*,'vchopper(5)=',vchopper(5)
c	if(kpr.eq.1)print*,'pf0(5) pf_p(5)',pf0(5),pf_p(5)
ccc	read(*,*)
c***********************************

	if(tt.ge.70.e6)then
	   do i=1,npf
	      vchopper(i)=0.
	      end do
        end if

	call ful()

c	if(kpr.eq.1)print*,'!!!!!!!!!tt=',tt
c	if(kpr.eq.1)print*,(pf(i),i=1,npf)
c	read(*,*)

c        call loopflux()                                                       

c        call probefield()

c	call pfves_d3d()
c	call pfves()

c###	if(ntay.gt.next)call gen()

c	call d3d_corr_pf()

c	call d3d_corr()


c----------------

!	eps2=eps2*2.

	zvel=(zmag-zmag0)/tay	

      if(tt.ge.60.7e9)then
      i_zvel=1
      end if
      

	if(dabs(zvel).gt.zv_max.and.i_zvel.eq.0)then
!	if(ntay.gt.0)then
!      kzref=3

      i_zvel=1
      
      kzref=1
      krref=2
      if(zvel.gt.0)then
      zref=zmag0+zv_max*tay
!      zref=zmag0
      else
      zref=zmag0-zv_max*tay      
!      zref=zmag0      
      end if
      
      rref=0.5*(rmag+rmag0)
!      rref=rmag0
      
      if(kpr.eq.1)print *,' ++zref zmag0 zvel',zref,zmag0,zvel
      if(kpr.eq.1)print *,' ++rref rmag0 rvel',rref,rmag0,rvel
      
	else
!      kzref=0	
!      krref=0	
	end if

	
	if(int_2005.gt.10)eps2=eps2*1.5


      if(int_2005.gt.50)go to 6666

	if(it1.ne.0)go to 2005

c----------------
	delzmag=zmag-zmag_in
	delrmag=rmag-rmag_in

	zvel=(zmag-zmag0)/tay	
	
	zvel_tran=zvel

c	zcur=z_cur

c	call z_cur_filter(zcur)

c	if(kpr.eq.1)print *,' zcur z_cur=',zcur,z_cur

c	z_cur=0.5*(z_cur+z_cur0)

c	zvel=(z_cur-z_cur0)/tay

	rvel=(rmag-rmag0)/tay
	if(kpr.eq.1)
     *	print *,' delzmag delrmag rvel',delzmag,delrmag,rvel

	d_zvel=abs(zvel-zvel_0)/(abs(zvel)+1.e-4)
	if(kpr.eq.1)
     *	print *,' ZVEL d_zvel INT_2000',zvel,d_zvel,int_2000

	if(kpr.eq.1)print *,' int_2005 eps2 i_zvel ',int_2005,eps2,i_zvel

	if(kpr.eq.1)print *,' delzmag delrmag',delzmag,delrmag
        if(kpr.eq.1)print*,'zmag zref zmag0 zvel',zmag,zref,zmag0,zvel
        if(kpr.eq.1)print*,'rmag rref rmag0 rvel',rmag,rref,rmag0,rvel
c        if(ntay.gt.next)pause 'from main'


 6666   continue


!      kzref=0
!      krref=0


      call ppx_pffx_save(1)

	if(abs(zvel-zvel_0).gt.(0.05*abs(zvel)+1.e-3).and.int_2000.lt.11)then
	it1=1
	end if

	if(ntay.lt.-1)then
	call polar_data()
        CALL POLAR1(n,mp,rs0,kp,pt0z)
	call polar_res()
	CALL BTA(n,mp,RS0)

c  toroidal coordinates...
	call transf_data()
	end if



	if(i_map.eq.1)then


	call map_ps()

      call li_calc()

  	do j=1,mp
	   uk_help(j)=uk(j)
	   vk_help(j)=vk(j)
	end do
	um_help=um
	vm_help=vm
	
	
!	c*** If i_avr=1 >>>>> plasma boundary averaging
!	i_avr=0
	if(i_avr.eq.1)then

	 do j=1,mp
	   uk(j)=uk_help1(j)+( uk_help2(j)-uk_help1(j) )*
     *  float(k_svd)/float(n_svd)

	   vk(j)=vk_help1(j)+( vk_help2(j)-vk_help1(j) )*
     *  float(k_svd)/float(n_svd)
     
       end do

	   um=um_help1+( um_help2-um_help1 )*
     *  float(k_svd)/float(n_svd)

	   vm=vm_help1+( vm_help2-vm_help1 )*
     *  float(k_svd)/float(n_svd)

	end if

c!!! If call ro_tran() the tansport is doing p' & ff' to the initial surfaces
c!!! so transport does not know about time evolution of surfaces 
	
!      call ro_tran()
	call transf_b_tor()

!!!	call tab_w()

	end if

 2001	continue

	if(krref.eq.3)call transf_b_tor()

	if(i_map.eq.0)then

	if(ntay.ge.-1)then

	if(i_old.eq.1)then
	call ptoke_res()
	call polar_tor()
	call tor_data()
	else

	call polar_data_tor()
      call transf_b_tor()

	end if

	end if

	CALL BTA(n,mp,RS0)

	end if
 
	dmo=dm0(n)

	tpl_it=tpl

	next_help=next
	
	if(krref.eq.3)then
	   next=ntay+1
	   end if

      if(k_ener.eq.0)call prof_astra_bs()


	if(tt.ge.59.0e9)then
        fdd0=fdd
        end if

      if(i_filter.eq.1)call fdd_filter()

	call tpl_cal()
	next=next_help

c!	call tpl_calc()

	call pp_calc()
	call pff_calc()

	call z_cur_calc()
ccc	zvel_tran=(z_cur-z_cur0)/tay


	errd=2.*abs(dmo-dm0(n))/( abs(dmo)+abs(dm0(n)) )
	int_dif=int_dif+1


c	call v_ec()

	err_tpl=2.*abs(tpl-tpl_it)/( abs(tpl)+abs(tpl_it) )

	if(kpr.eq.1)print *,' -it1 errdifmf- err_tpl int_2000',
     *  it1,errd,err_tpl,int_2000

c**vic************
        if(int_2000.gt.50)go to 5555
c************

!	if(errd.gt.1.e-3.and.int_dif.lt.4) it1=1
!	if(err_tpl.gt.1.e-3) it1=1

	CALL BTA(n,mp,RS0)



	int_dif=0

      call ppx_pffx_save(2)

	if(it1.ne.0)go to 2000

	call wr_tabppf()
        call wr_pf()
        call wr_tcam()
      call wr_rpp()
      call wr_zpp()

	zvel=zvel_tran

 5555   continue

	CALL BTA(n,mp,RS0)

	do i=1,npf
	   pfhelp(i)=pf(i)
	end do

c-----------------------------
c   vessel cuurents taken after convergance of equilibrium---

c----------------------------

c
      	VMAX=1.E5
      	DO I=1,n
    	VN(I)=VI(I)/VMAX
	end do
	if(kpr.eq.1)
     *	print *,' -----k_ener t_dop-- q(2)',k_ener,t_dop,q(2)
	if(k_ener.eq.1)	CALL ENERGY(N)
	if(k_ener.ne.1)call enit(n)
      if(k_ener.eq.0)call prof_astra()

c	if(q(2).le.0.7)call zyb(n,ires)
c	if(q(2).le.0.8)call zyb(n,ires)

c**********************************************
ccc	q_test=0.90
c	q_test=0.96
	q_test=0.97
cccccccc	q_test=0.8
c	q_test=0.7
c	q_test=0.98
	i_min=0
	q_min=q(2)

c-----------------------

	do i=3,n
	   if(q(i).le.q_min)then
	      i_min=i
	      q_min=q(i)
	      if(kpr.eq.1)print *,' i i_min q(i) q_min',i,i_min,q(i),q_min
	   end if
	end do

	if(kpr.eq.1)print *,' q(2)*** q_test',q(2),q_test
	if(kpr.eq.1)print *,' k_zyb==',k_zyb

	i_oldd=1

	k_zyb=0

	if(i_oldd.eq.1.and.ntay.gt.10)then
	if(q_min.le.q_test)then
	if(kpr.eq.1)print *,' q_min==== q_test ntay',q_min,q_test,ntay
	if(kpr.eq.1)print *,' call zyb'
	      if(kpr.eq.1)print*,(q(ii),ii=1,n)
c	   call zyb(n,ires,q_test)

	   call zyb(n,ires)
		k_zyb=1

c	      if(kpr.eq.1)print*,(q(ii),ii=1,n)
c	      read(*,*)
	   call pp_calc()
	   call pff_calc()
	end if
	end if
c**********************************************



ccc	if(q(2).le.0.9.and.ntay.gt.next+10)call zyb(n,ires)
ccc	if(q(2).le.0.92.and.ntay.gt.next+10)call zyb(n,ires)

c*** H-mode switching in case of Coppi-Tang model ***
        key_lh=0

cccccc        tt_h=80100.
c        tt_h=70100.
c        tt_h=50100.
cccccccc        tt_h_to_l=600000.
	if(kpr.eq.1)print*,'!!!tt key_h_to_l tt_h_to_l ntay',tt,key_h_to_l,tt_h_to_l,ntay 

	if(key_h_to_l.eq.1)tt_h_to_l=tt
c
        if(tt.gt.tt_h)key_lh=1
        if(key_h_to_l.eq.1)key_lh=0

	if(kpr.eq.1)print*,'!!!tt tt_h tt_h_to_l',tt,tt_h,tt_h_to_l
	if(kpr.eq.1)print*,'!!!key_h_to_l key_lh',key_h_to_l,key_lh
c****************************************************
	
	if(k_ener.eq.1)then
	
	if(tt.gt.tt_h-500.)then
	   call vic_prof_chg()
	end if

	if(tt.gt.tt_h_to_l-500.)then
	   call vic_prof_chg1()
	end if
	
		call dens_prog()

      end if
      
	if(ntay.eq.next)call gen_pf()

c****** PF current limits checking ***********
        call vic_pf_limits()
c*********************************************

c###	if(ntay.eq.next)call gen()

c@@@	call pf_volt()

c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!! Save PF to PF_original_order !!!!!!!!!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!! Transfer PF to PF_DINA_order !!!!!!!!!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!! Save VCHOPPER to VCHOPPER_original_order !!!!!!!!!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!! Transfer VCHOPPER to VCHOPPER_DINA_order !!!!!!!!!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c**** pfc_new.dat and volt_new.dat files writing ***
           call wr_tok_new()
           call wr_volt_new()

	call v_sec()

	call q_calc()

	call DOPP()
c	do i=1,npf
c	   if(kpr.eq.1)print*,pf0(i),pf(i)
c	end do
c	if(kpr.eq.1)print*,'from main 333 tt',tt
c	read(*,*)
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!! Transfer PF_DINA_order to PF_original_order !!!!!!!!!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c!!!!! Transfer VCHOPPER_DINA_order to VCHOPPER_original_order !!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c*** Here we are doing te0(n)=tq0(n)=g_edge*tec !!!
        call vic_t_edge()

c  	call shape_f9a() 
c	call filter()

	call time_gen()

c	if(i_fil.ge.1)then
c 	 zvel_tok=(z_tok-z_tok0)/tay
c       if(kpr.eq.1)print*,'r_tok z_tok',r_tok,z_tok
c       if(kpr.eq.1)print*,'r_tok0 z_tok0',r_tok0,z_tok0
c      if(kpr.eq.1)print*,'zvel zvel_tok',zvel,zvel_tok

c	end if


	call time_step()

      call ppx_pffx_save(2)
	call time_st_ppx_pffx()

c*vic Writing of kavin.dat file
c!!!        call wr_kavin() 

	if(kpr.eq.1)print *,' END time step==='

	if(ntay.ge.next)call time_out()

	if(kpr.eq.1)print *,' END time out==='

c	if(tt.lt.t_end)go to 2323
c	stop

	if(tt.lt.100.e3.or.tpl.gt.tpl_end)go to 2323

	t_end=tt
	t_vde=t_end+250.e3

c	if(kpr.eq.1)print*,'before 3323'
c	if(kpr.eq.1)print*,'tt tpl t_end t_vde',tt,tpl,t_end,t_vde

3323	continue

	ntay=ntay+1

	tt=tt+tay

c*** To read Ip and PF_p preprogrammed waveforms (in DINA order)
c*** from scr_data file 
      call vic_shape_ip_iam()
	   
        call r_volt()

        call vic_gaps0_read()
	call SCEN_CONTROL(key_h_to_l)

	  call loopflux()
                                                      
        call probefield()

        call gen_pf()
      	call ful()

c****** PF current limits checking ***********
        call vic_pf_limits()
c*********************************************
c!!!!! Transfer VCHOPPER to VCHOPPER_DINA_order !!!!!!!!!!!!!!!!!!
c!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
c**** pfc_new.dat and volt_new.dat files writing ***
           call wr_tok_new()
           call wr_volt_new()

	call v_sec()

	call DOPP_2()

	call time_gen()

	call time_step()

	call time_out()

	if(tt.lt.t_vde)go to 3323

c-----------------------------------


	stop
71	FORMAT(5X,A10/,(2x,6(1PE11.3)))
	return
	end
	subroutine read_data()
	include 'double.inc'
	include 'new_com.inc'

	common
     *  /c_tran1/k_ion,pow_el,pow_ion

	call read_data_c(
     *  res_coef,n_polar,
     *  k_ion)

	return
	end
	subroutine read_data_c(
     *  res_coef,n_polar,
     *  k_ion)

	include 'double.inc'
        include 'parf0'
	include 'parf2'
	common
     *  /cont13/zmag,zvel,delrmag,delzmag
     *  /cont13e/zmag0,rmag,rmag0,rvel
	common
     *	/n_m/n,m,mp
	common
     *  /eq12/omega,pspl0(nwnh)
	common
     *	/ge1e/rs0,tpl
     *  /ge2/NTAY,TAY,TT
     *  /ge2e/t_end
     *  /ge4/EPS1,EPS2,EPS0
     *  /ge5/kpr
     *  /ge6e/zeff_a,zeff_b
     *	/ge7/eu,rs,zout,eksk
	common
     *  /DFM1/UDM,ZDM,L3,SIG0
     *  /dfm7/bt0,uind
	common
     *	/efit0/kefit
     *	/efit1/alfax(2),betax(2)
     *	/efit2/alfa0,beta,alfa1
     *	/efit3/pw_1,pw_2
	common
     *  /pol5/psend
	common
     *  /en1e/te_a,ti_a,te_b,ti_b,pw_e
     *  /en2e/pd0_a,pt0_a,pd0_b,pt0_b,pw_p
     *  /en7/UD,ZD,UT,ZT,UH,ZH,LD,LT,LH,ID,IT,IH,KTP,Neng
     *  /en11/un(4),zn(2),ll,ken,ken1,ken2,noit
     *  /en12/pnal(npo),pnaln(npo),zalfa,talfa
     *  /en13/KPIN,VPIN,ALP1,POT,SKOR
     *  /en14/EMOE,EMOQ,NDOP,QDE0(npo),QDQ0(npo)
     *  /en14e/t_dop
     *  /eq15e/pll0,tpl0,udd
     *  /en19/DD,DT,DH,SIN0,SINK,ALPY,Sss,Ppp,Eee
     *  /en33/anom_e,anom_i,key_t11,kcchp
     *  /en25/zhib,tego

	common
     *	/keys1/i_graph
     *	/keys2/key_b
     *	/keys3/kzero,iread,iwrite
     *  /keys4/k_ener,k_uv
     *  /keys5/next
     *  /keys7/i_c
     *  /keys8/ndh
     *  /keys9/i_d3d,i_iter,i_smal
     *  /keys10/ngra
     *  /keys11/i_ramp
     *  /keys12/i_v
     *  /keys13/i_con,i_act
     *  /keys14/i_beta,i_gap5
     *  /keys15/i_br
     *  /keys17/i_feed,i_ecoil
	common
     *	/con1/gain,ta,zref,kzref
     *  /con2/rref,krref,bvert
     *  /con3/i_pf
     *  /con5/n_exp,k_cont
     *  /con6/ind_r(2),ind_z(2)
	common
     *	/point1/r0,z0
	common
     *  /halo1/c_h,d_halo,fmax_in,tpl_in
     *  /halo2/kmaj,k_q,k_d,kaxis,ndisrup
     *  /halo2e/next0,li_drop,n_li,n_dif,nmix
     *  /halo3/tay_00,tay_th,t_disr,d_tpl,tpl_end
     *  /halo4e/w_h0,delaval0,pshalo0,te_h0
     *  /halo5/q_vde,q_95,del_f,i_halo
     *  /halo12/te_h
     *  /halo14/hpart
     *  /halo15/e_sep,nsep
	common
     *  /pol4/UM,VM,UK(ntet),VK(ntet)
	common
     *	/cont18/t_vde,time_disr
	common
     *  /ef_0/key_ef

     	open(unit=2,file='for002',form='formatted')
        if(kpr.eq.1)print *,' begin for002 reading'

	read (2,*)
	read (2,*)n,m,next
	read (2,*)
	read (2,*)tt,tay,t_end,rs0,psend
	read (2,*)
	read (2,*)i_graph
	read (2,*)
	read (2,*)alfa0,beta,alfa1,omega
	read (2,*)
	read (2,*)iread,kzero,iwrite,kefit
	read (2,*)
	read (2,*)alfax,betax
	read (2,*)
	read (2,*)pw_1,pw_2
	read (2,*)
	read (2,*)te_a,ti_a,te_b,ti_b,pw_e
	read (2,*)
	read (2,*)pd0_a,pt0_a,pd0_b,pt0_b,pw_p
	read (2,*)
	read (2,*)zeff_a,zeff_b
	read (2,*)
	read (2,*)sig0
	read (2,*)
	read (2,*)zhib,tego,zalfa,talfa,alp1
	read (2,*)
	read(2,*)ktp,kpin,ken,ken1,ken2,kd2,nal
	read (2,*)
	read(2,*)edop,ppp,eee,dd,dt,dh,df
	read (2,*)
	read(2,*)lt,ld,lh,ll,lm,it,id,ih
	read (2,*)
	read(2,*)eps0,eps1,eps2
	read (2,*)
	read (2,*)anom_e,anom_i,key_t11,kcchp
	read (2,*)
	read (2,*)emoe,emoq
	read (2,*)
	read (2,*)udd
	read (2,*)
	read (2,*)k_ener,k_uv
	read (2,*)
	read (2,*)t_dop
	read (2,*)
	read (2,*)r0,z0,zref
	read (2,*)
	read (2,*)kzref,krref,key_b,i_pf
	read (2,*)
	read (2,*)i_c
	read (2,*)
	read (2,*)q_vde
	read (2,*)
	read (2,*)tay_00,tay_th,t_disr
	read (2,*)
	read (2,*)d_tpl,tpl_end
	read (2,*)
	read (2,*)c_h,d_halo
	read (2,*)
	read (2,*)kmaj,li_drop,ndisrup,n_dif,nmix
	read (2,*)
	read (2,*)hpart,te_h
	read (2,*)
	read (2,*)i_d3d,i_iter,i_smal
	read (2,*)
	read (2,*)ngra,i_ramp,i_v,i_con
	read (2,*)
	read (2,*)tpl,bt0,eu,eksk
	read (2,*)
	read (2,*)e_sep
	read (2,*)
	read (2,*)i_beta,i_gap5
	read (2,*)
	read (2,*)i_br
	read (2,*)
	read (2,*)ind_r,ind_z
	read (2,*)
	read (2,*)key_ef
	read (2,*)
	read (2,*)res_coef
	read (2,*)
	read (2,*)n_polar
c	read (2,*)
c        read (2,*)k_ion,pow_el,pow_ion


	if(kpr.eq.1)then
	   print *,' key_ef ===',key_ef
	   print *,' res_coef===',res_coef
	   print *,' n_polar===',n_polar
	   print *,' k_ion===',k_ion
	   print *,' pow_el pow_ion===',pow_el,pow_ion
	   print*,'tt=',tt
	   
	   print *,' end for002 reading'
	end if


	call edim1

        if(kpr.eq.1)print *,' CALL ELKE...'
c        read (*,*)

	pnor=6.25e8
	emoe=emoe*pnor
	emoq=emoq*pnor

	ndh=1


	close(2)

c##	mp=(m-2)/2+2
	mp=m
	if(kpr.eq.1)print *,' n m mp',n,m,mp
c	read (*,*)


        rs=r0
        zout=z0
	um=r0
	vm=z0
	rmag=um
	zmag=vm

	if(kpr.eq.1)print *,' um vm eu elong',um,vm,eu,eksk

        if(kmaj.eq.1)then

     	open(unit=2,file='halo',form='formatted')
        if(kpr.eq.1)print *,' begin halo reading'

	read (2,*)
	read (2,*)w_h0,te_h0
        if(kpr.eq.1)print *,' w_h0  te_h0==',w_h0,te_h0
	close(2)

        end if


     	open(unit=2,file='time',form='formatted')
        if(kpr.eq.1)print *,' begin time reading'

	read (2,*)
	read (2,*)t_vde,time_disr
        if(kpr.eq.1)print *,' t_vde time_disr',t_vde,time_disr

	close(2)

	return
	end


	subroutine gsvd_ef(indpf,seps1,seps2,seps3)
	return
	end

c




  	subroutine read_exp() 
	include 'double.inc'
	include 'new_com.inc'

	call read_exp_c(
     *  kloop,kprobe,npf,	
     *  psloop_e,bprobe_e,pf_e,
     *  psloop,bprobe,pf)

	return
	end

c

	subroutine read_exp_c(
     *  kloop,kprobe,npf,	
     *  psloop_e,bprobe_e,pf_e,
     *  psloop,bprobe,pf)

	include 'double.inc'
	dimension psloop_e(*),bprobe_e(*),pf_e(*)
	dimension psloop(*),bprobe(*),pf(*)


	do i=1,npf
	pf_e(i)=pf(i)
	end do

	do i=1,kloop
	psloop_e(i)=psloop(i)
	end do

	do i=1,kprobe
	bprobe_e(i)=bprobe(i)
	end do

	return
	end

   
	subroutine ptoke1_fil_0()
	include 'double.inc'
        include 'parf0'
        include 'parf2'
	common
     *	/n_m/n,m,mp
	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nn),y(MM),dx,dy
     *  /eq1g/psi_g(nr,nz)
     *  /eq8/jbound,xbound(ntet),ybound(ntet),alfa0_xx
     *  /eq15/pll,zsep,rsep,zsepup,rsepup,zsepdw,rsepdw
	common
     *  /pol4/ UM,VM,UK(ntet),VK(ntet)
     *  /pol5/psend
     *  /pol6/ppx(npo),pffx(npo)
	common
     *  /ge1/pi
     *	/ge1e/rs0,tpl
     *  /ge2/NTAY,TAY,TT
     *  /ge3/AI(npo),poA0(npo),HA2(npo),poa(npo),ha(npo)
     *  /ge4/EPS1,EPS2,EPS0
     *  /ge5/kpr
	common
     *	/fluxc2/delta0,pom(ntet)
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
     *	/fluxc7/coef,coef1,api
     *  /fluxc9/fdd,fdd0


	common
     *	/point1/r0,z0
	common
     *  /halo4/expfg,avalb,w_h,del_r,al0
     *  /halo4e/w_h0,delaval0,pshalo0,te_h0
     *  /halo5e/pshalo
     *  /halo15/e_sep,nsep
	common
     *  /eq11/psval(npo),psval0(npo)
	common
     *	/keys1/i_graph
     *	/keys2/key_b
     *  /keys11/i_ramp
        common
     *	/efit2/alfa0,beta,alfa1
	common
     *	/efit5/it1,it2
        common
     *  /ves9/tokc,tokc0
	common
     *  /ef_0/key_ef
        common
     *  /efil_6/psi_min,psi_max
     *  /efil_10/plasma_coef
	common
     *  /cont13/zmag,zvel,delrmag,delzmag
     *  /cont13e/zmag0,rmag,rmag0,rvel
c----------
	dimension f(nwnh),pspl_help(nwnh)

	rmag_help=rmag
	zmag_help=zmag

	pmag_help=pmag

	rsep_help=rsep
	zsep_help=zsep
	psep_help=psep

	do i=1,nwnh
	pspl_help(i)=pspl(i)
	end do

	delta0=sqrt(dx**2+dy**2)
	COEF=10./(4.*PI)
	api=1./(2.*pi)

	nw_h=10
	n1=nr-1
	m1=nz-1
c------------------------------------
c calc.psi(i,j)
	if(kpr.eq.1)print *,' call to psi_tot_fil--'

	call psi_fil()

	coef1=dx*dy*coef
c	call psi_fil_pl()

	call psi_tot_fil()

c	call li_calc()



c   call to plasma-limiter contact...
	if(kpr.eq.1)print *,' call to pom_lim--'
	call pom_lim()
c--------------------------
c calc. boundary values...
	if(kpr.eq.1)print *,' call to psi_b--'
	call psi_b_fil(psep,rsep,zsep,ksepa)
	if(kpr.eq.1)print *,'  psep rsep zsep',psep,rsep,zsep

	call bound_fil()
	call separ_coor()                                                
	call separ_coor2()                                                


	do i=1,nwnh
	pspl(i)=pspl_help(i)
	end do

	rmag=rmag_help
	zmag=zmag_help
	pmag=pmag_help

	rsep=rsep_help
	zsep=zsep_help
	psep=psep_help

c      call q_b_calc()


71	format(20x,a6/,(6(1pe10.3)))
	return
	end


	subroutine psi_b_fil(psep,rsep,zsep,ksepa)
	include 'double.inc'
        include 'parf0'
	common
     *	/n_m/n,m,mp
	common
     *  /eq6/sinus(ntet),cosin(ntet)
     *  /eq14e/rsep_pf,zsep_pf
	common
     *  /pol4/ UM,VM,UK(ntet),VK(ntet)
	common
     *  /ge5/kpr
     *  /ge7/eu,rout,zout,elong

	common
     *	/fluxc2/delta0,pom(ntet)

	dimension pdd(6)
	dimension  vkref(ntet),ukref(ntet)


c!!!	abeg=eu
	abeg=0.8*eu

	do j=1,m
	ukref(j)=um+ABEG*cosin(j)
	vkref(j)=vm+elong*ABEG*sinus(j)
	end do

71	format(20x,a6/,(6(1pe10.3)))

	i1=2
	i2=m-1
c---------
	pom_m=pom(2)
	i3=2
	do i=3,m-1
	if(pom(i).lt.pom_m)i3=i
	end do
c	i1=2
c	i2=m-1
c	i3=2
	pocoef=0.1*delta0
	kc=1
	psepa=-1.e14
c-----------------------------------------------
c PSEPA(from separatrix1) - max psi in limiter
c RSEPA,ZSEPA - coordinates of this point

	call separatrix1 (i1,i2,i3,m,ukref,vkref,um,vm,pom,
     *  sinus,cosin,pocoef,psepa,rsepa,zsepa,isep,ksepa,kc)
	if(kpr.eq.1)print *,'psepa***=',psepa
	if(kpr.eq.1)print *,'zsepa rsepa',zsepa,rsepa
	posepa=sqrt( (rsepa-um)**2+(zsepa-vm)**2 )
	ksepa=1
	do i=2,m-1
	if(abs(posepa-pom(i)).lt.1.e-4)then
	if(kpr.eq.1)print *,'i posepa pom(i)',i,posepa,pom(i)
c
	if(kpr.eq.1)print *,' plasma touchs limiter'
	ksepa=0
	urr=rsepa
	vrr=zsepa

	rsep_pf=rsepa
	zsep_pf=zsepa

	call boxd(urr,vrr,pdd,ier)
	psepa=pdd(1)
	end if
	end do
c__________________________
c  search for separatrix...
	ksep=2
	psep=-1.e12
	psep1=-1.e12
	if(ksepa.ne.0)then
	xw=rsepa
	yw=zsepa
	call spoint(ksep,xw,yw,fint,rmag,zmag,pmag,
     *  rsep,zsep,psep,rsep1,zsep1,psep1)
	end if
c__________________________
c
	if(psepa.gt.psep.and.ksepa.eq.0)then
c	if(kpr.eq.1)print *,'***psepa gt psep---',psepa,psep
	psep=psepa
	rsep=rsepa
	zsep=zsepa
	end if
	if(abs(psep).gt.1.e10)then
	psep=psepa
	rsep=rsepa
	zsep=zsepa
	end if
c------------------------------------
	return
	end



	subroutine stab(ich_xx,i_graph_xx)
      	include 'double.inc'

	include 'new_com.inc'



	call stab_c(ich_xx,i_graph_xx,

     *  rref,zref,bvert,brad,it1,dx,dy,

     *  rmag,zmag,pmag,psep,zsep,kpr)

      

	return

	end





	subroutine stab_c(ich,i_graph,

     *  rl,zl,clr,clz,it1,dx,dy,

     *  rmag,zmag,pmag,psep,zsep,kpr)

      	include 'double.inc'


	character *30 apr

	dimension a_print(200)



	pbound=psep

	iter=0

c	ceps=0.1

c	ceps=0.02

	ceps=0.02

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	n_pr=4

	apr=' clr clz zl rl ENTER '

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


 1000	continue

      

	it1=1





	if(ich.eq.0) then  


	   rl0=rl                                

	   zl0=zl                                

	 

	   clr0=clr                              

	   clz0=clz                              

                                                       

	   ddzl=dy*ceps



	   zl=zl0+ddzl                            

	   int_it=0



 1	   continue

	   int_it=int_it+1

c	      call cur_prof()

	      call ptoke1()

	      if(int_it.gt.40)it1=0

	      if(it1.eq.1)go to 1

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	a_print(5)=ich

	a_print(6)=int_it

	a_print(7)=iter

	n_pr=6

	apr=' clr clz zl rl ich int '

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

      ich=ich+1                             


	endif                                   



	it1=1



	if(kpr.eq.1)print *,' ich==',ich



c	if(i_graph.eq.1)call graphic(it1,n)

                                                       

	if(ich.eq.1) then  

	   clr1=clr                              

	   clz1=clz                              

	   ddrl=dx*ceps



!!!	   rl=rl+ddrl
	   rl=rl0+ddrl

	   zl=zl0  
	                                 
	   int_it=0

 2	   continue

	   int_it=int_it+1

c	      call cur_prof()

	      call ptoke1()

	      if(int_it.gt.40)it1=0

	   if(it1.eq.1)go to 2

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	a_print(5)=ich

	a_print(6)=int_it

	a_print(7)=iter

	n_pr=6

	apr=' clr clz zl rl ich int '

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

      ich=ich+1                             

	endif                                   



c	if(i_graph.eq.1)call graphic(it1,n)


                                                       

	if(kpr.eq.1)print *,' ich==',ich



	if(ich.eq.2) then  





	   dcrdr=(clr-clr0)/ddrl                 

	   dczdr=(clz-clz0)/ddrl                 



	   if(kpr.eq.1)print *,' clr clr0  ddrl',clr,clr0,ddrl

	   if(kpr.eq.1)print *,' clz clz0  ddrl',clz,clz0,ddrl



                 

	   dcrdz=(clr1-clr0)/ddzl                

	   dczdz=(clz1-clz0)/ddzl                

                 

	   if(kpr.eq.1)print *,' clr1 clr0  ddzl',clr1,clr0,ddzl

	   if(kpr.eq.1)print *,' clz1 clz0  ddzl',clz1,clz0,ddzl



	   det=dcrdr*dczdz-dczdr*dcrdz           

               

	   if(kpr.eq.1)then

	   print *,' det dcrdr dczdz dczdr dcrdr',

     *      det,dcrdr,dczdz,dczdr,dcrdr

	   end if



      delrl0=delrl
	delzl0=delzl
	
	         

	   delrl= (clz0*dcrdz-clr0*dczdz)/det       

	   delzl= (clr0*dczdr-clz0*dcrdr)/det       

	if(iter.gt.2)then
c	delrl=0.5d0*(delrl+delrl0)
c	delzl=0.5d0*(delzl+delzl0)
	end if


	   if(kpr.eq.1)print *,' delrl delzl',delrl,delzl

                                                       

	   dll=sqrt(delrl**2 + delzl**2)           

	 

	   dllim=0.5*sqrt(dx**2+dy**2)

                          

	   if(kpr.eq.1)print *,' dll dllim',dll,dllim

	a_print(1)=delrl

	a_print(2)=delzl

	a_print(3)=dll

	a_print(4)=dllim

	a_print(5)=dcrdr

	a_print(6)=dczdr

	a_print(7)=dcrdz

	a_print(8)=dczdz



	n_pr=8

	apr=' delr delz dll dllim dcrdr dczdr dcrdz dczdz '

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	   if(dll .gt. dllim) then                  

                                                       

	      nstp=dll/dllim                       

                                                       

	      ddrr=delrl/nstp                      

	      ddzz=delzl/nstp                      



	      if(nstp.ge.5)nstp=5

c	      if(nstp.ge.2)nstp=2

c	      if(nstp.ge.50)nstp=50



	      do  istep=1,nstp                  

                                                       

          if(kpr.eq.1)write(6,*) 'slow shift',istep,nstp   

                                                       

		 rl=rl0+ ddrr*istep                   

		 zl=zl0+ ddzz*istep



		 it1=1




	   int_it=0


 3		 continue

		 int_it=int_it+1

c		    call cur_prof()

		    call ptoke1()

		    if(int_it.gt.40)it1=0

		    if(it1.eq.1)go to 3



c	if(i_graph.eq.1)call graphic(it1,n)

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	a_print(5)=istep

	a_print(6)=int_it


	n_pr=6

	apr=' CLR  CLZ zl rl ISTEP int '

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)



	      end do

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	a_print(5)=ich

	a_print(6)=int_it

	a_print(7)=iter

	n_pr=6

	apr=' clr clz zl rl ich int '

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)
		

	   else                                     

                                                       

	      rl=rl0+ delrl                         

	      zl=zl0+ delzl



	      it1=1



	   int_it=0



 4	      continue

	      int_it=int_it+1

c		 call cur_prof()

		 call ptoke1()

		 if(int_it.gt.40)it1=0

		 if(it1.eq.1)go to 4



c	if(i_graph.eq.1)call graphic(it1,n)

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	a_print(5)=ich

	a_print(6)=int_it

	a_print(7)=iter

	n_pr=6

	apr=' clr clz zl rl ich int '

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	   endif                                    


	   ich=0


	endif                                    



c	ceps=ceps*0.5



        crz=abs(clr*rmag/(pmag-pbound))+

     *  abs(clz*(zmag-zsep)/(pmag-pbound))



	

	iter=iter+1



	if(kpr.eq.1)print *,' ITER pmag pbound zsep==',pmag,pbound,zsep

	if(kpr.eq.1)print *,' ITER clr clz crz==',iter,clr,clz,crz




	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=iter

	n_pr=3

	apr=' clr clz iter'

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

c	if(abs(crz).gt.1.d-5.and.iter.le.25)go to 1000
	if(abs(crz).gt.1.d-5.and.iter.le.10)go to 1000

c	if(abs(crz).gt.1.d-5)go to 1000

c	if(dabs(crz).gt.1.d-3)go to 1000



	a_print(1)=crz

	a_print(2)=clr

	a_print(3)=clz

	a_print(4)=zl

	a_print(5)=rl

	a_print(6)=iter

	n_pr=6

	apr='crz clr clz zl rl ITER'

	num=20

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

c	stop

                                                       

	return

	end




	subroutine flat_ext2()
	include 'double.inc'
	include 'new_com.inc'

	call flat_ext2_c(
     *  nwnh,nr,nz,npf,ncam,pf,tcam,
     *  fluxarr,vesarr,
     *  kf,mu,
     *  xu,yu,ke)
	
	return
	end



	subroutine flat_ext2_c(
     *  nwnh,nr,nz,npf,ncam,pf,tcam,
     *  fluxarr,vesarr,
     *  kf,mu,
     *  xu,yu,ke)

	include 'double.inc'

	dimension pf(*),tcam(*),fluxarr(nwnh,*),
     *  vesarr(nwnh,*),xu(*),yu(*)

	dimension ttt(100)

74	format(a110)

	open (unit=41,file='test_data.dat',form='formatted')                  
	read (41,*)npf,ncam,kloop,kprobe,ke

	read (41,5000)(xu(k),k=1,ke)                                                   
	read (41,5000)(yu(k),k=1,ke)                                                   

	read (41,5000)(pf(k),k=1,npf)                                                   
	read (41,5000)(tcam(k),k=1,ncam)                                                   

	do k=1,npf                                                        
	   read (41,5000)(fluxarr(kk,k),kk=1,nwnh)                                     
	end do                                                                 

	do k=1,ncam                                                        
	      read (41,5000)(vesarr(kk,k),kk=1,nwnh)
	end do                                                                 


	close (41)

5000    format (6(1pe14.7))

	return
	end






                                                                        
	subroutine flat_ext2_wr()
	include 'double.inc'
	include 'new_com.inc'

	call flat_ext2_wr_c(
     *  nwnh,nr,nz,npf,ncam,pf,tcam,
     *  fluxarr,vesarr,
     *  kf,mu,
     *  xu,yu,ke)
	
	return
	end



	subroutine flat_ext2_wr_c(
     *  nwnh,nr,nz,npf,ncam,pf,tcam,
     *  fluxarr,vesarr,
     *  kf,mu,
     *  xu,yu,ke)

	include 'double.inc'

	dimension pf(*),tcam(*),fluxarr(nwnh,*),
     *  vesarr(nwnh,*),xu(*),yu(*)

	dimension ttt(100)

74	format(a110)



	open (unit=41,file='test_data.dat',form='formatted')                  

	write (41,*)npf,ncam,kloop,kprobe,ke

	write (41,5000)(xu(k),k=1,ke)                                                   
	write (41,5000)(yu(k),k=1,ke)                                                   

	write (41,5000)(pf(k),k=1,npf)                                                   
	write (41,5000)(tcam(k),k=1,ncam)                                                   

	do k=1,npf                                                        
	   write (41,5000)(fluxarr(kk,k),kk=1,nwnh)                                     
	end do                                                                 

	do k=1,ncam                                                        
	      write (41,5000)(vesarr(kk,k),kk=1,nwnh)
	end do                                                                 


	close (41)

5000    format (6(1pe14.7))


	return
	end






                                                                        


	subroutine new_lim(i_lim)
	include 'double.inc'
        include 'parf0'
        include 'parf1'
        include 'parf2'
        include 'parf7'

	common
     *	/n_m/n,m,mp
	common
     *  /ge1/pi
     *  /ge5/kpr
	common
     *  /pol4/ UM,VM,UK(ntet),VK(ntet)
	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nr),y(nz),dx,dy
     *  /eq2/ke,xu(mu_l),yu(mu_l)
     *  /eq2e/kex,xue(mu),yue(mu)
     *  /eq7/tetq(ntet),htq(ntet)
	common
     *	/fluxc2/delta0,pom(ntet)
	common
     *  /keys7/i_c

	parameter ( k_sep=1000 )
	common /c_tsp1/r_sep(k_sep),z_sep(k_sep)
	common /c_tsp2/n_sep

	dimension  pom_1(ntet),xu_help(mu),yu_help(mu)
	
	character *20 apr

      i_en=i_en+1
      if(i_en.eq.1)then

      ke_help=kex
      
      do i=1,ke
      xu_help(i)=xu(i)
      yu_help(i)=yu(i)
      end do
            
      end if
      


      if(i_lim.eq.1)then

c----------------------

      ke=kex
      do i=1,ke
      xu(i)=xue(i)
      yu(i)=yue(i)
      end do
      
c------------------------      

      else
      
      ke=ke_help
      
      do i=1,ke
      xu(i)=xu_help(i)
      yu(i)=yu_help(i)
      end do
            
      end if
      

      return
      end
      
