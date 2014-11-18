c************************************************************
c
c	subroutine SCEN_CONTROL
c	
c		USER ROUTINE FOR SCENARIO SIMULATIONS WITH In-vessel COILS
c	
c	COILS order: CSU3 CSU2 CS1 CSL2 CS3L PF1->PF6 In_ves

        subroutine SCEN_CONTROL(key_h_to_l_xx)
	  include 'double.inc'
        include 'new_com2.inc'

c  u_kd should be 1:12, num_coils=12, npf=15, pf_turns(12)=1.


        call SCEN_CONTROL_c(key_h_to_l_xx,
     &       tpl,cip1,zref,rref,
     &       npf,vchopper,r_cur,z_cur,
     &       u_1,u_kd,d_gaps,zvel,elong,tt,gaps,gaps0,
     &       pf,pf_p,ksepa,
     &       state,state_old,pf_turns,zvconverter,zvresist,
     &       u_ffw,state_vert,state_old_vert,rmag,zmag,pf_lim,kpr,
     &       elong_p,tt_dw,xleft,xright,uk,t_end,tt_errIp,
     &       rsep,n_pasc,key_lh)


        return
        end

        subroutine SCEN_CONTROL_c(key_h_to_l,
     &       tpl,cip1,zref,rref,
     &       npf,vchopper,r_cur,z_cur,
     &       u_1,u_kd,error,zvel_in,elong,tt,gaps_in,gaps_ref_p,
     &       pf,curr_ref_p,klim,
     &       state,state_old,pf_turns,zvconverter,zvresist,
     &       u_help,state_vert,state_old_vert,rmag,zmag,pf_lim,kpr,
     &       elong_p,tt_dw,xleft,xright,uk,t_end,tt_errIp,
     &       rsep,n_pasc,key_lh)

c	SET PARAMETERS AND VARIABLES

	include 'double.inc'
        include 'parf8'

	parameter(num_coils=12)
	parameter(num_states_vert=9)
	parameter(num_inputs_lim=19, num_states_lim=50)

        parameter(num_inputs_div=19,num_states_div=50)
	parameter(num_gaps=7)

	dimension a_vert(num_states_vert,num_states_vert),
     &  b_vert(num_states_vert,2),
     &  c_vert(num_coils,num_states_vert),c_vert2(2,num_states_vert),
     &  d_vert(num_coils,2),d_vert2(2,2)

	dimension a_lim(num_states_lim,num_states_lim),
     &  b_lim(num_states_lim,num_inputs_lim),
     &  c_lim(num_coils,num_states_lim),
     &  d_lim(num_coils,num_inputs_lim)

	dimension a_div(num_states_div, num_states_div),
     &  b_div(num_states_div, num_inputs_div),
     &  c_div(num_coils,num_states_div),
     &  d_div(num_coils,num_inputs_div)


	dimension error(kf_c)
	dimension u_1(*),u_kd(*),pf_lim(*),coef_pf_lim(30)
	dimension uk(*)

	dimension gaps_in(*),gaps_ref_p(*),gaps_refXPF(num_gaps)
	dimension pf(*),curr_ref_p(*),curr_refXPF(30)

        dimension gaps_ref(30),curr_ref(30),curr_ref_md(30),
     *            gaps_ref_eob(30),gaps(30)

	dimension vchopper(*),u_help(30)

	dimension state(*),state_old(*),pf_turns(*)
	dimension state_vert(*),state_old_vert(*)

        dimension zresist(30),zvboost(30),zvresist(30),u_term(30),
     *  zsatpf(30),ztotsat(30),zvconverter(30),u_10(30),u_rd(30),
     *  t_vde(30),u_kd_vde(30),zvde_max(30),z_switch_vs1(30)

        dimension curr_max(30),curr_gain(30),curr_max_t(30)
        
        common /vic_g7_ref/g7_ref

	LOGICAL diverted,using_lim,using_div,on_transition
	real XPFtime,V_sat_imb(30),LIMtime
	real ak(kf_c,kf_c),bk(kf_c,kf_c),ck(kf_c,kf_c),dk(kf_c,kf_c)
	integer num_states,num_inputs

	character *20 apr

c*** tt is DINA time in ms
        time=tt*1.e-3

	i_en=i_en+1
c************************************
c PART DONE AT FIRST ITERATION ONLY *
c************************************

        if(i_en.eq.1)then
c************************************
            k_err=1
            k_intvde=0

         open (unit=41,file='control_data_ch.dat',form='formatted')
           read (41,*)
           read (41,*) n_pasc,ng_lim,switch_delay,refval_ramptime,
     *      tt_eob,tt_rd,v_coef,coef_lim,amp_noise
           tt_rd=tt_rd*1e3
           tt_eob=tt_eob*1e3
            tt_HL=tt_eob
           tt_dw=tt_eob
           read (41,*)
           read (41,*) Vvs1_sat,Vvs3_sat,Vcs_sat,Vpf_sat

           read (41,*)
           read (41,*) c_a_tpl1,c_a_tpl1_eob,c_a_tpl2,c_a_tpl_min,
     *                 y0,c1_y0,c2_y0

           read (41,*)
           read (41,*) time_res,res_CS1

           read (41,*)
           read (41,*) t_ch,h_ch,V_ch,dz_ch,c_err45_ch

           read (41,*)
           read (41,*) t_errIp,dt_term,dtpl_term_h,dtpl_term_l
           tt_errIp=t_errIp*1.e3

           read (41,*)
           read (41,*) c_cur_max,(curr_max_t(i),i=1,npf-n_pasc)

           read (41,*)
           read (41,*) n_t_vde,time_vde,ck_zupdown
           read (41,*)
           read (41,*) (t_vde(i),i=1,n_t_vde)
           read (41,*)
           read (41,*) (zvde_max(i),i=1,n_t_vde)
           read (41,*)
           read (41,*) (z_switch_vs1(i),i=1,n_t_vde)

           close (41)

c	Read Controller Matrices
c
c LIMITER phase CONTROLLER

           open (unit=41,file='a_div_lim.flat',form='formatted')
           do i = 1, num_states_lim
              read(41,*)(a_lim(i,j),j=1,num_states_lim)
           end do
           close (41)
 
           open (unit=41,file='b_div_lim.flat',form='formatted')
           do i = 1, num_states_lim
              read(41,*)(b_lim(i,j),j=1,num_inputs_lim)
           end do
           close (41)

           open (unit=41,file='c_div_lim.flat',form='formatted')
           do i = 1, num_coils-1
              read(41,*)(c_lim(i,j),j=1,num_states_lim)
           end do
           close (41)

           open (unit=41,file='d_div_lim.flat',form='formatted')
           do i = 1, num_coils-1
              read(41,*)( d_lim(i,j),j=1,num_inputs_lim)
           end do
           close (41)

c DIVERTOR phase CONTROLLER


           open (unit=41,file='a_div.flat',form='formatted')
           do i = 1, num_states_div
              read(41,*)(a_div(i,j),j=1,num_states_div)
           end do
           close (41)
           open (unit=41,file='b_div.flat',form='formatted')
           do i = 1, num_states_div
              read(41,*)(b_div(i,j),j=1,num_inputs_div)
           end do
           close (41)
           open (unit=41,file='c_div.flat',form='formatted')
           do i = 1, num_coils-1
              read(41,*)(c_div(i,j),j=1,num_states_div)
           end do
           close (41)
           open (unit=41,file='d_div.flat',form='formatted')
           do i = 1, num_coils-1
              read(41,*)(d_div(i,j),j=1,num_inputs_div)
           end do
           close (41)

c	STABILIZING CONTROLLER (always on)

	open (unit=41, file='Avert.flat',form='formatted')
	do i=1,num_states_vert
	read(41,*)(a_vert(i,j),j=1,num_states_vert)
	end do
	close (41)
	open (unit=41, file='Bvert.flat',form='formatted')
	do i=1,num_states_vert
	read(41,*)(b_vert(i,j),j=1,2)
	end do
	close (41)
	open (unit=41, file='Cvert.flat',form='formatted')
	do i=1, num_coils
	read(41,*)(c_vert(i,j),j=1,num_states_vert)
	end do
	close (41)
	open (unit=41, file='Dvert.flat',form='formatted')
	do i=1, num_coils
	read(41,*)(d_vert(i,j),j=1,2)
	end do
	close (41)


c    VOLTAGE SATURATIONS

      do i=1,num_coils
         V_sat_imb(i)=0.
      end do
      do i=7,10
      
!      if(kpr.eq.1)print *,' i pf_turns',i,pf_turns(i)
      
        V_sat_imb(i)=Vvs1_sat/pf_turns(i)
      end do
      V_sat_imb(num_coils)=Vvs3_sat/pf_turns(num_coils)

C First controller: limiter

           diverted=.false.
           on_transition=.false.
           using_lim=.true.
           using_div=.false.
           num_states=num_states_lim
           num_inputs=num_inputs_lim

         do i=1,num_states
           state_old(i)=0.
         end do

        do  i = 1,num_states
           do j=1,num_states
              ak(i,j)=a_lim(i,j)
           end do
        end do

        do  i = 1,num_states
           do j=1,num_inputs
              bk(i,j)=b_lim(i,j)
           end do
        end do

        do  i = 1,num_coils-1
           do j=1,num_states
              ck(i,j)=c_lim(i,j)
           end do
        end do

        do  i = 1,num_coils-1
           do j=1,num_inputs
              dk(i,j)=d_lim(i,j)
           end do
        end do


      end if

c*******************************************
c END OF PART DONE AT FIRST ITERATION ONLY *
c*******************************************


      do i=1,30
      gaps(i)=gaps_in(i)
      end do

        if(tt.gt.tt_rd.and.key_rd.eq.0)then
           key_rd=1

           num_states_div1=40
           num_states=num_states_div1

           open (unit=41,file='a_div_rd.flat',form='formatted')
           do i = 1, num_states_div1
              read(41,*)(ak(i,j),j=1,num_states_div1)
           end do
           close (41)
           open (unit=41,file='b_div_rd.flat',form='formatted')
           do i = 1, num_states_div1
              read(41,*)(bk(i,j),j=1,num_inputs_div)
           end do
           close (41)
           open (unit=41,file='c_div_rd.flat',form='formatted')
           do i = 1, num_coils-1
              read(41,*)(ck(i,j),j=1,num_states_div1)
           end do
           close (41)
           open (unit=41,file='d_div_rd.flat',form='formatted')
           do i = 1, num_coils-1
              read(41,*)(dk(i,j),j=1,num_inputs_div)
           end do
           close (41)
c---
         do i=1,num_states
           state_old(i)=0.
         end do
c---
        end if

c555555555555555555555555555555555555555555555555
        if(tt.gt.t_end.and.key_term.eq.0)then
           key_term=1

           num_states_div1=40
           num_states=num_states_div1

           open (unit=41,file='a_cur_term_4.flat',form='formatted')
           do i = 1, num_states_div1
              read(41,*)(ak(i,j),j=1,num_states_div1)
           end do
           close (41)
           open (unit=41,file='b_cur_term_4.flat',form='formatted')
           do i = 1, num_states_div1
              read(41,*)(bk(i,j),j=1,num_inputs_div)
           end do
           close (41)
           open (unit=41,file='c_cur_term_4.flat',form='formatted')
           do i = 1, num_coils-1
              read(41,*)(ck(i,j),j=1,num_states_div1)
           end do
           close (41)
           open (unit=41,file='d_cur_term_4.flat',form='formatted')
           do i = 1, num_coils-1
              read(41,*)(dk(i,j),j=1,num_inputs_div)
           end do
           close (41)
c---
         do i=1,num_states
           state_old(i)=0.
         end do
        do i=1,num_states_vert
           state_old_vert(i)=0.
        end do
c---
        end if
c55555555555555555555555555555555555555555555555

c ==> Get Feedforward Voltages (u_help)
c  npf should be equal 15
           if(tt.gt.t_end) v_coef=0.
        do i=1,npf-n_pasc
           u_help(i)=vchopper(i)*v_coef
!       if(kpr.eq.1)print *,' i  v_coef u_help=',i,v_coef,u_help(i)
        end do

c ==> SWITCHING BETWEEN CONTROLLERS
c at the first transition from limiter to diverted plasma

        if (.not.diverted.and.time.ge.switch_delay) then
           XPFtime=time
        end if

        if (time.ge.switch_delay) then
           diverted=.true.
        end if

        if (diverted.and.klim.eq.0 .and. tt.gt.tt_eob
     >      .and.klim_2.ne.1) then
           LIMtime=time
        end if

        if (klim.eq.0 .and. tt.gt.tt_eob) then
               klim_2=1
        end if

c switch controller with delay after XPF
        if(using_lim.and.diverted.and.time.ge.XPFtime)then

           using_div=.true.
           using_lim=.false.
           num_inputs=num_inputs_div
           num_states=num_states_div

           do i=1,num_coils-1
           u_10(i)=u_1(i)
           end do

         do i=1,num_states
           state_old(i)=0.
         end do

        do  i = 1,num_states
           do j=1,num_states
              ak(i,j)=a_div(i,j)
           end do
        end do

        do  i = 1,num_states
           do j=1,num_inputs
              bk(i,j)=b_div(i,j)
           end do
        end do

        do  i = 1,num_coils-1
           do j=1,num_states
              ck(i,j)=c_div(i,j)
           end do
        end do

        do  i = 1,num_coils-1
           do j=1,num_inputs
              dk(i,j)=d_div(i,j)
           end do
        end do

        end if

c Signal of transient in controller switching
        if(using_div.and.time.lt.(XPFtime+refval_ramptime))then
           on_transition=.true.
        else
           on_transition=.false.
        end if

c RAMPING OF REFERENCE VALUES FOR SMOOTH CONTROLLER SWITCHING
        if(on_transition) then
         alfa=1e0-(time-XPFtime)/refval_ramptime
         if(alfa .le. 0e0) alfa=0e0
         if(alfa .ge. 1e0) alfa=1e0
         else
         alfa=0e0
        end if

c*********
           do i=1,num_gaps-1
              gaps_ref(i)=gaps_ref_p(i)
           end do
           do i=1,num_coils-1
              curr_ref(i)=curr_ref_p(i)              

           end do
c*********
c centroid velosity with noise
        zvel=zvel_in+((rand(0)-0.5)*2.)*amp_noise/10.

	if(using_lim) then

c Kavin's insert
              gaps(6)=xleft
              gaps(3)=xright
c end Kavin's insert

              if(xleft.lt.rsep) then
              gaps(6)=xleft
              else
              gaps(6)=rsep
              endif

           error(3)=(gaps(ng_lim)-gaps_ref(ng_lim))/1.e2*coef_lim

           error(1)=-(elong-elong_p)*coef_lim
c           error(1)=(elong-elong_p)*coef_lim

           error(2)=0.

              error(4)=(gaps(4)-gaps_ref(4))/1.e2*coef_lim
              error(5)=(gaps(5)-gaps_ref(5))/1.e2*coef_lim
              error(6)=(gaps(6)-gaps_ref(6))/1.e2*coef_lim
           error(num_gaps)=0.

           error(num_gaps+1)=(tpl-cip1)/1.e3*coef_lim

           do i=1,num_coils-1
              error(num_gaps+1+i)=(pf(i)-curr_ref(i))/1e3
!            if(kpr.eq.1)print *,' i error(i)-',i,error(i),curr_ref(i)
           end do


      do i=1,num_gaps-1
!        if(kpr.eq.1)print *,' i gaps-',i,gaps(i),gaps_ref(i)
      end do



	end if
c==========end using_lim======================================

	if(using_div) then

c Kavin's insert
              gaps(3)=xright
c              gaps(6)=xleft

              if(xleft.lt.rsep) then
              gaps(6)=xleft
              else
              gaps(6)=rsep
              endif
c end Kavin's insert

           do i=1,num_gaps-1
              error(i)=(gaps(i)-gaps_ref(i))/1e2
           end do



           error(num_gaps)=0.
c==================================================

              error(num_gaps+1)=(tpl-cip1)/1e3

           if(time.ge.t_errIp .and. time .le. tt_eob*1e-3) 
     >     error(num_gaps+1)=0.

c--------------------------
         call error_corr(error,num_gaps)
c---------------------------

        if(key_h_to_l.eq.1)key1=key1+1
        if(key1.eq.1)tt_HL=tt
c*********
              a_curr_ref=1.
           do i=1,num_coils-1
           error(num_gaps+1+i)=(pf(i)-curr_ref(i)*a_curr_ref)/1e3
           end do

         if(tt.lt.tt_eob) then
           do i=1,num_gaps-1
           gaps_ref_eob(i)=gaps(i)
           end do
         endif

         if(tt.gt.tt_eob) then
       call gaps_ref_hl_1(tt,tt_eob,dt_term,gaps_ref_eob,gaps_ref)
       do i=1,num_gaps-1
          error(i)=(gaps(i)-gaps_ref(i))/1e2
       end do

        if(key_lh.eq.0 .and. key_h_to_l .eq. 0) then
        a_curr_ref=1.-(time-tt_eob*1e-3)/dtpl_term_l
        endif
        if(key_lh.eq.1) then
        a_curr_ref=1.-(time-tt_eob*1e-3)/dtpl_term_h
        a_curr_ref_h=a_curr_ref
        endif
        if(key_lh.eq.0 .and. key_h_to_l .eq. 1) then
        a_curr_ref=a_curr_ref_h*(1.-(tt-tt_HL)*1e-3/dtpl_term_l)
        endif

        if(a_curr_ref .lt. 0.) a_curr_ref=0.

       cip1=cip1_eob*a_curr_ref
       error(num_gaps+1)=(tpl-cip1)/1e3

           if(tt.gt.t_end) a_curr_ref=0.
       do i=1,num_coils-1
       error(num_gaps+1+i)=(pf(i)-curr_ref_md(i)*a_curr_ref)/1e3
       enddo

         else
       cip1_eob=cip1
       do i=1,num_coils-1
       curr_ref_md(i)=curr_ref(i)              
       end do
         endif

	end if
c==============end using_div=============================

c------------------sim VDE

       do i=1,n_t_vde
       if((time.ge.t_vde(i) .and. time .lt. t_vde(i)+time_vde)
     >                      .and. k_vde.eq.0) then
          zvde=z_cur*1e-2
          k_vde=1
          k_intvde=i
       endif
       enddo

       if(k_vde.eq.1 .and. k_vde2.eq.0) then
          if(abs(z_cur*1e-2-zvde) .lt. zvde_max(k_intvde)) then

            if(abs(z_cur*1e-2-zvde) .lt. z_switch_vs1(k_intvde)) then
             u_kd_vde(7)=V_sat_imb(7)*ck_zupdown
             u_kd_vde(8)=V_sat_imb(8)*ck_zupdown
             u_kd_vde(9)=-V_sat_imb(9)*ck_zupdown
             u_kd_vde(10)=-V_sat_imb(10)*ck_zupdown
            else
             do i=1,num_coils-1
             u_kd_vde(i)=0.
             enddo
            endif

            do j=1,num_states_vert
            state_old_vert(j)=0.
            end do
c            do j=1,num_states
c            state_old(j)=0.
c            end do
            k_err=0
           else
            k_vde2=1
            k_err=1
          endif
       endif

       if(k_intvde .ne. 0) then
         if(time .ge. t_vde(k_intvde)+time_vde) then
          k_vde=0
          k_vde2=0
         endif
       endif

c---------------end sim VDE

c-------chopper controller
       if(time .ge. t_ch .and. i_ch.eq.0) then

        do i=1,num_states_vert
           state_old_vert(i)=0.
           b_vert(i,1)=0.
           b_vert(i,2)=0.
        do j=1,num_states_vert
           a_vert(i,j)=0.
        enddo
        enddo

        do i=1,num_coils
           d_vert(i,1)=0.
           d_vert(i,2)=0.
        do j=1,num_states_vert
           c_vert(i,j)=0.
        enddo
        enddo

        open (unit=41, file='cont_vs3vs1_ch10.flat',form='formatted')
             read(41,*) nvs

          do i=1,nvs
          read(41,*)(a_vert(i,j),j=1,nvs),b_vert(i,1),b_vert(i,2)
          enddo

          do i=1,2
          read(41,*)(c_vert2(i,j),j=1,nvs),d_vert2(i,1),d_vert2(i,2)
          enddo

        close (41)

             do i=7,10
             do j=1,nvs
             if(i .le. 8) then
             c_vert(i,j)=-c_vert2(2,j)/pf_turns(i)
             else
             c_vert(i,j)=c_vert2(2,j)/pf_turns(i)
             endif
             enddo
             enddo

             do j=1,nvs
             c_vert(num_coils,j)=c_vert2(1,j)/pf_turns(num_coils)
             enddo

             do i=7,10
             do j=1,2
             if(i .le. 8) then
             d_vert(i,j)=-d_vert2(2,j)/pf_turns(i)
             else
             d_vert(i,j)=d_vert2(2,j)/pf_turns(i)
             endif
             enddo
             enddo

             do j=1,2
             d_vert(num_coils,j)=d_vert2(1,j)/pf_turns(num_coils)
             enddo

c  2.0000000e+000
c  3.6787944e-001  0.0000000e+000  0.0000000e+000  1.6366649e+000
c  0.0000000e+000  3.6787944e-001  1.2786445e-002  0.0000000e+000
c  0.0000000e+000 -9.3750000e+003 -1.1036383e+002  1.6500000e+001
c -1.2207031e+003  0.0000000e+000  0.0000000e+000 -1.8393972e+003

	i_ch=1

       endif	

       if(time .lt. t_ch) then
c        z_ch=zmag+dz_ch
        z_ch=gaps(5)+dz_ch
       endif

c-------end chopper controller

c ===>  CONTROLLER IMPLEMENTATION

c STABILIZING CONTROLLER
c The centroid velocity is in cm/ms in Dina => is needed 
c to multiply by ten to get m/s

c  ===> zeroing internal variables ...

        do i=1,num_coils
           u_kd(i)=0.
        end do


        do i=1,num_states_vert
           state_vert(i)=0.
        end do

c  ===> compute state vector ...

        do i=1,num_states_vert
           do j=1,num_states_vert
            state_vert(i)=state_vert(i)+a_vert(i,j)*state_old_vert(j)
           end do
        end do
        do i=1,num_states_vert

        if(time .lt. t_ch) then
        state_vert(i)=state_vert(i)+(b_vert(i,1)*10.*zvel+
     *                b_vert(i,2)*pf(num_coils)/1e3)*k_err
        else
c        state_vert(i)=state_vert(i)+(b_vert(i,1)*(zmag-z_ch)*1e-2+
        state_vert(i)=state_vert(i)+(b_vert(i,1)*(z_ch-gaps(5))*1e-2+
     *                b_vert(i,2)*pf(num_coils)/1e3)*k_err
        endif

        end do


c  ===> compute control vector (without saturation)...

c con_1

        a_tpl1=tpl/15e3*c_a_tpl1

        if(using_lim) a_tpl1=tpl/15e3*c_a_tpl1_eob

c        a_tpl2=c_a_tpl2
        a_tpl2=tpl/15e3*c_a_tpl2

ccc t >= t_eob
        if(time .ge. tt_eob*1e-3) then
c         a_tpl1=tpl/15e3*c_a_tpl1_eob
c        if(a_tpl1 .lt. c_a_tpl_min) a_tpl1=c_a_tpl_min
c        a_tpl2=1e0

        a_tpl2=1e0
        a_tpl1=tpl/15e3
        if(time .ge. tt_rd*1e-3) a_tpl1=tpl/15e3*c_a_tpl1_eob
        if(a_tpl1 .lt. c_a_tpl_min) a_tpl1=c_a_tpl_min
        endif
ccc end t >= t_eob

        if(a_tpl1 .gt. 1e0) a_tpl1=1e0
        if(a_tpl2 .gt. 1e0) a_tpl2=1e0

        if(tt.gt.t_end) a_tpl1=0e0

        do i=1,num_coils
           do j=1,num_states_vert
            u_kd(i)=u_kd(i)+a_tpl1*c_vert(i,j)*state_old_vert(j)
           end do
        end do

        do i=1,num_coils

        if(time .lt. t_ch) then
        u_kd(i)=u_kd(i)+a_tpl1*(d_vert(i,1)*10.*zvel+
     *          d_vert(i,2)*pf(num_coils)/1e3)*k_err+u_kd_vde(i)
        else
c        u_kd(i)=u_kd(i)+a_tpl1*(d_vert(i,1)*(zmag-z_ch)*1e-2+
        u_kd(i)=u_kd(i)+a_tpl1*(d_vert(i,1)*(z_ch-gaps(5))*1e-2+
     *          d_vert(i,2)*pf(num_coils)/1e3)*k_err+u_kd_vde(i)
        endif

        end do

c  ===> update state vector ...
c We are doing it outside

c POSITION/SHAPE CONTROLLER
c  ===> zeroing internal variables ...

        do i=1,num_coils-1
           u_1(i)=0.
        end do


        do i=1,num_states
           state(i)=0.
        end do

c  ===> compute state vector ...

        do i=1,num_states
           do j=1,num_states
              state(i)=state(i)+ak(i,j)*state_old(j)
           end do
        end do

       if(time .gt. t_ch) then
           do i=1,num_inputs_div

c           if(i .ne. num_gaps+1) then
c           if(i .eq. 4 .or. i.eq.5 .or. i.ge.9) then

c           if(i .eq. 4 .or. i.eq.5) then
c           error(i)=error(i)/c_err45_ch
c           endif

           if(i.le.8 .or. i.eq.10 .or. i.eq.13) then
           else
c           error(i)=0.
           endif

           enddo

c         error(4)=(gaps(4)-gaps_ref(4))/1e2/c_err45_ch
         error(5)=(gaps(5)-gaps_ref(5))/1e2/c_err45_ch

       endif

        do i=1,num_states
           do j=1,num_inputs
              state(i)=state(i)+bk(i,j)*error(j)
           end do
        end do


c  ===> compute control vector (without saturation)...
c  Kavin's insert (tpl in kA)

        a_div_cont=1.

        if(tt.gt.tt_eob)then

        if(tt .ge. tt_rd .and. tt .le. tt_rd+refval_ramptime*1e3) then
        a_div_cont=(tt-tt_rd)/(refval_ramptime*1e3)
        alfa_rd=1.-a_div_cont
        a_div_cont=a_div_cont*((cip1-c1_y0)/(c2_y0-c1_y0)*(1e0-y0)+y0)
        else
        alfa_rd=0.
        a_div_cont=(cip1-c1_y0)/(c2_y0-c1_y0)*(1e0-y0)+y0
        if(a_div_cont .lt. y0) a_div_cont=y0
        endif

        if(a_div_cont .gt. 1e0) a_div_cont=1e0

        end if

        if(tt.gt.t_end)then
        if(tt .ge. t_end .and. tt .le. t_end+refval_ramptime*1e3) then
        alfa_term=1.-(tt-t_end)/(refval_ramptime*1e3)
        a_div_cont=1.-alfa_term
        else
        a_div_cont=1.
        alfa_term=0.
        endif
        if(alfa_term .gt. 1e0) alfa_term=1e0
        if(alfa_term .lt. 0.)  alfa_term=0.
        endif
c------------------------------

        do i=1,num_coils-1
           do j=1,num_states

	if(using_lim) then
              u_1(i)=u_1(i)+ck(i,j)*state_old(j)
   !     if(kpr.eq.1)print *,' i j u1 ck =',i,j,u_1(i),ck(i,j),state_old(j)

	else
c   using_div

           u_1(i)=u_1(i)+a_tpl2*ck(i,j)*state_old(j)*a_div_cont
	end if

           end do
        end do

        do i=1,num_coils-1
           do j=1,num_inputs

	if(using_lim) then
              u_1(i)=u_1(i)+dk(i,j)*error(j)
              
   !     if(kpr.eq.1)print *,' i j u1 e dk =',i,j,u_1(i),error(j),dk(i,j)

	else
c   using_div

           u_1(i)=u_1(i)+a_tpl2*dk(i,j)*error(j)*a_div_cont

	end if

           end do

!        if(kpr.eq.1)print *,' i u1 =',i,u_1(i)
        
        u_1(i)=u_1(i)*(1.-alfa)+u_10(i)*alfa

        if(tt .lt. tt_rd) then
        u_rd(i)=u_1(i)
        else
        u_1(i)=u_1(i)+u_rd(i)*alfa_rd
        endif

        if(tt .lt. t_end) then
        u_term(i)=u_1(i)
        else
        u_1(i)=u_1(i)+u_term(i)*alfa_term
        endif

        end do

!        if(kpr.eq.1)print *,' using_lim num_coils =',using_lim,num_coils

        do j=1,num_inputs
  !      if(kpr.eq.1)print *,' j error(j) =',j,error(j)
        end do
      

c  ===> update state vector ...
c We are doing it outside
c		do i=1,num_states
c		  state_old(i)=state(i)
c		end do

c	SATURATION ON IMBALANCE CONVERTER

       do j=7,10
         if(abs(u_kd(j)).gt.V_sat_imb(j))then
           u_kd(j)=(u_kd(j)/abs(u_kd(j)))*V_sat_imb(j)
         end if
       end do

         if(time .ge. t_ch) then
         Ts1=time-t_prev
         call chopper(u_kd(num_coils),Ts1,h_ch,sign_V)
         u_kd(num_coils)=V_ch*sign_V
         endif
        t_prev=time

         if(abs(u_kd(num_coils)).gt.V_sat_imb(num_coils))then
           u_kd(num_coils)=(u_kd(num_coils)/abs(u_kd(num_coils)))*
     *                        V_sat_imb(num_coils)
         end if

c	SNU RESISTORS AND BOOSTERS

       do i=1,npf-n_pasc
           zvresist(i)=0.
           zresist(i)=0.
           zvboost(i)=0.
           zsatpf(i)=Vcs_sat/pf_turns(i)
           if(i.eq.3)zsatpf(i)=Vcs_sat*2./pf_turns(i)
           if(i.ge.7 .and. i.le.10) zsatpf(i)=Vpf_sat/pf_turns(i)
        end do
c&&&&&&&&&&
        
c*** Resistors ***
           if(time.le.time_res) zresist(3)=res_CS1

        do i=1,npf-n_pasc
           zvresist(i)=-(zresist(i)/pf_turns(i))*
     *          (pf(i)*1.e3/pf_turns(i))
           if(zvresist(i).gt.0)zvresist(i)=0.
        end do

C	CALCULATE FEEDFORWARD + FEEDBACK (SLOW LOOP ONLY)
        
        do i=1,npf-n_pasc
           vchopper(i)=u_1(i)+u_help(i) 
 !      if(kpr.eq.1)print *,' i  u1 u_help=',i,u_1(i),u_help(i)

       end do

C	SATURATIONS ON MAIN CONVERTERS

	do i=1,npf-n_pasc

c*******
           curr_max(i)=curr_max_t(i)*pf_turns(i)

           curr_gain(i)=curr_max(i)*c_cur_max

           if(abs(pf(i)).ge.curr_gain(i))then
              coef_pf_lim(i)=((curr_max(i)-abs(pf(i)))/
     &        (curr_max(i)-curr_gain(i)))**3
           else
              coef_pf_lim(i)=1.
           end if
c*******

           ztotsat(i)=zsatpf(i)+zvboost(i)

c     feedback on current with gain Rsnu
           zvconverter(i)=vchopper(i)-zvresist(i)*0.

           if(abs(zvconverter(i)).gt.ztotsat(i))
     * zvconverter(i)=(zvconverter(i)/abs(zvconverter(i)))*ztotsat(i)

c Kavin insert
           
           if(abs(pf(i)).ge.curr_gain(i))then
         if(pf(i).gt.0e0 .and. zvconverter(i).le.0e0) coef_pf_lim(i)=1e0
         if(pf(i).lt.0e0 .and. zvconverter(i).ge.0e0) coef_pf_lim(i)=1e0
           endif

c end Kavin insert

        zvconverter(i)=coef_pf_lim(i)*zvconverter(i)
        vchopper(i)=zvconverter(i)+zvresist(i)+u_kd(i)

        end do

        zvconverter(num_coils)=u_kd(num_coils)
        vchopper(num_coils)=zvconverter(num_coils)

        do i=num_coils+1,npf
           vchopper(i)=0.
        end do

71	FORMAT(5X,A20/,(2x,6(1PE11.3)))

        return
        end

c******************************************

       subroutine gaps_ref_hl_1(tt,tt_HL,dt,gaps_ref_eob,gaps_ref)
	include 'double.inc'

       dimension gaps_ref(*),gaps_ref_eob(*),t_HL_f(100),
     *   gaps_ref_hl(100)

       open (unit=41,file='g1_0s_term.dat',form='formatted')
       read (41,*)
       read (41,*) n_gaps
       read (41,*)
       read (41,*) (t_HL_f(i),gaps_ref_hl(i),i=1,n_gaps)
       close(41)
       gaps_ref_hl(1)=gaps_ref_eob(1)
       do i=1,n_gaps
       t_HL_f(i)=t_HL_f(i)*dt/t_HL_f(n_gaps)
       t_HL_f(i)=t_HL_f(i)+tt_HL*1e-3
       enddo
       call linvolt3(n_gaps,t_HL_f,tt*1e-3,gaps_ref_hl,PFVOL2)
       gaps_ref(1)=PFVOL2

       open (unit=41,file='g2_0s_term.dat',form='formatted')
       read (41,*)
       read (41,*) n_gaps
       read (41,*)
       read (41,*) (t_HL_f(i),gaps_ref_hl(i),i=1,n_gaps)
       close(41)
       gaps_ref_hl(1)=gaps_ref_eob(2)
       do i=1,n_gaps
       t_HL_f(i)=t_HL_f(i)*dt/t_HL_f(n_gaps)
       t_HL_f(i)=t_HL_f(i)+tt_HL*1e-3
       enddo
       call linvolt3(n_gaps,t_HL_f,tt*1e-3,gaps_ref_hl,PFVOL2)
       gaps_ref(2)=PFVOL2

       open (unit=41,file='g3_0s_term.dat',form='formatted')
       read (41,*)
       read (41,*) n_gaps
       read (41,*)
       read (41,*) (t_HL_f(i),gaps_ref_hl(i),i=1,n_gaps)
       close(41)
       gaps_ref_hl(1)=gaps_ref_eob(3)
       do i=1,n_gaps
       t_HL_f(i)=t_HL_f(i)*dt/t_HL_f(n_gaps)
       t_HL_f(i)=t_HL_f(i)+tt_HL*1e-3
       enddo
       call linvolt3(n_gaps,t_HL_f,tt*1e-3,gaps_ref_hl,PFVOL2)
       gaps_ref(3)=PFVOL2

       open (unit=41,file='g4_0s_term.dat',form='formatted')
       read (41,*)
       read (41,*) n_gaps
       read (41,*)
       read (41,*) (t_HL_f(i),gaps_ref_hl(i),i=1,n_gaps)
       close(41)
       gaps_ref_hl(1)=gaps_ref_eob(4)
       do i=1,n_gaps
       t_HL_f(i)=t_HL_f(i)*dt/t_HL_f(n_gaps)
       t_HL_f(i)=t_HL_f(i)+tt_HL*1e-3
       enddo
       call linvolt3(n_gaps,t_HL_f,tt*1e-3,gaps_ref_hl,PFVOL2)
       gaps_ref(4)=PFVOL2

       open (unit=41,file='g5_0s_term.dat',form='formatted')
       read (41,*)
       read (41,*) n_gaps
       read (41,*)
       read (41,*) (t_HL_f(i),gaps_ref_hl(i),i=1,n_gaps)
       close(41)
       gaps_ref_hl(1)=gaps_ref_eob(5)
       do i=1,n_gaps
       t_HL_f(i)=t_HL_f(i)*dt/t_HL_f(n_gaps)
       t_HL_f(i)=t_HL_f(i)+tt_HL*1e-3
       enddo
       call linvolt3(n_gaps,t_HL_f,tt*1e-3,gaps_ref_hl,PFVOL2)
       gaps_ref(5)=PFVOL2

       open (unit=41,file='g6_0s_term.dat',form='formatted')
       read (41,*)
       read (41,*) n_gaps
       read (41,*)
       read (41,*) (t_HL_f(i),gaps_ref_hl(i),i=1,n_gaps)
       close(41)
       gaps_ref_hl(1)=gaps_ref_eob(6)
       do i=1,n_gaps
       t_HL_f(i)=t_HL_f(i)*dt/t_HL_f(n_gaps)
       t_HL_f(i)=t_HL_f(i)+tt_HL*1e-3
       enddo
       call linvolt3(n_gaps,t_HL_f,tt*1e-3,gaps_ref_hl,PFVOL2)
       gaps_ref(6)=PFVOL2

        return
        end
C**********************************************************
       SUBROUTINE  linvolt3(n_gaps,tu,timev,gaps_ref_hl,PFVOL2)
	include 'double.inc'

       DIMENSION  tu(n_gaps),gaps_ref_hl(n_gaps)

               i=1
	do j=1,n_gaps
	if(timev .gt. tu(j)) i=j+1
	enddo
	if(i .eq. 1) then
        PFVOL2=gaps_ref_hl(1)+(gaps_ref_hl(2)-gaps_ref_hl(1))*
     >         (timev-tu(1))/(tu(2)-tu(1))
	else
	if(i .gt. n_gaps) i=i-1
        PFVOL2=gaps_ref_hl(i-1)+(gaps_ref_hl(i)-
     >         gaps_ref_hl(i-1))*(timev-tu(i-1))/(tu(i)-tu(i-1))
	endif
          RETURN
          END
C**********************************************************
       subroutine chopper(u,Ts1,tchop,sys)
	include 'double.inc'

       k_ch=k_ch+1

      if(k_ch .le. 1)then
	  kchop=2
	  dtchop=0
	  sys=0
	return
      endif

       if(kchop .eq. 2) then
        dtchop=0
        sys=0
        endif

       if(kchop .eq. 1 .and. dtchop .le. 0.5/tchop) then
         dtchop=dtchop+Ts1
         sys=1
         return
       endif
       if(kchop .eq. 0 .and. dtchop .le. 0.5/tchop) then
        dtchop=dtchop+Ts1
        sys=0
        return
       endif
       if(kchop .eq. -1 .and. dtchop .le. 0.5/tchop) then
        dtchop=dtchop+Ts1
        sys=-1
        return
       endif

       if(u .gt. 0) then
        if(kchop .eq. 1) then
         dtchop=dtchop+Ts1
         kchop=1
         sys=1
         return
         endif
c  3 positions
c     if kchop == -1, dtchop=0; kchop=0; sys=0; return; end;
        dtchop=0
        kchop=1
        sys=1
        return
       endif

       if(dabs(u) .le. 0) then
         if(kchop .eq. 2) then
           dtchop=0
           sys=0
           return
         endif
         if(kchop .eq. 0) then
           dtchop=dtchop+Ts1
           else
           dtchop=0
         endif
        kchop=0
        sys=0
        return
       endif

         if(u .lt. 0) then
           if(kchop .eq. -1) then
             dtchop=dtchop+Ts1
             kchop=-1
             sys=-1
             return
           endif
c  3 positions
c      if kchop == 1, dtchop=0; kchop=0; sys=0; return; end;
           dtchop=0
           kchop=-1
           sys=-1
           return
         endif

          end
C**********************************************************
