	subroutine kav_contr(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2)

cDEC$ ATTRIBUTES DLLEXPORT::  kav_contr

      include 'double.inc'
	include 'new_com2.inc'                                                  

      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*)

      parameter (kint=200)

	dimension pf_xx(kint),gaps_xx(kint),pf_turns_xx(kint)

	dimension vchopper_x2(kint)


!------------------------------------inputs
!     *  z_cur_xx,elong_xx,xleft_xx,
!     *  xright_xx,tpl_xx,tt_xx,
!     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
!     *  ntay_xx,next_xx,zvel_xx,pf_turns_xx,rsep_xx,klim_xx,
!     *  t_end_xx,i_wr_xx,

        z_cur_xx=c_input1(1)
        elong_xx=c_input1(2)
        xleft_xx=c_input1(3)
        xright_xx=c_input1(4)
        tpl_xx=c_input1(5)
        tt_xx=c_input1(6)
        npf_xx=c_input1(7)
        n_gaps_xx=c_input1(8)
        ntay_xx=c_input1(9)
        next_xx=c_input1(10)
        zvel_xx=c_input1(11)
        rsep_xx=c_input1(12)
        klim_xx=c_input1(13)
        t_end_xx=c_input1(14)
        i_wr_xx=c_input1(15)

      kk=0
      do i=1,npf_xx
      kk=kk+1
      pf_xx(i)=c_input2(kk)
      end do
      do i=1,n_gaps_xx
      kk=kk+1
      gaps_xx(i)=c_input2(kk)
      end do
      do i=1,npf_xx
      kk=kk+1
      pf_turns_xx(i)=c_input2(kk)
      end do


	 call put_signals(z_cur_xx,elong_xx,xleft_xx,
     *  xright_xx,tpl_xx,tt_xx,
     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
     *  ntay_xx,next_xx,zvel_xx,pf_turns_xx,rsep_xx,klim_xx,
     *  t_end_xx,i_wr_xx)

	call get_signals(vchopper_x2,tpl_x2,tt_dw_x2)

        c_output1(1)=tpl_x2      
        c_output1(2)=tt_dw_x2      
      
        do i=1,npf
        c_output2(i)=vchopper_x2(i)
        end do


!-----------------------------------  outputs---
!     *  vchopper_x2,tpl_x2,tt_dw_x2)

      return
      end



	subroutine put_signals(z_cur_xx,elong_xx,xleft_xx,
     *  xright_xx,tpl_xx,tt_xx,
     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
     *  ntay_xx,next_xx,zvel_xx,pf_turns_xx,rsep_xx,klim_xx,
     *  t_end_xx,i_wr_xx)
     

      include 'double.inc'
	include 'new_com2.inc'                                                  


	dimension pf_xx(*),gaps_xx(*),pf_turns_xx(*)

	character*70 apr

71	format(20x,a6/,(6(1pe10.3)))

!      kpr=1

c------------
      i_wr=i_wr_xx
      klim=klim_xx
      t_end=t_end_xx
      if(kpr.eq.1)print*,'klim t_end ',klim,t_end
      
      rsep=rsep_xx
      zvel=zvel_xx
      if(kpr.eq.1)print*,'rsep zvel ',rsep,zvel
      
      z_cur=z_cur_xx
      elong=elong_xx
      if(kpr.eq.1)print*,'z_cur elong ',z_cur,elong

      xleft=xleft_xx
      xright=xright_xx

      if(kpr.eq.1)print*,'xleft xright ',xleft,xright

      n_gaps=n_gaps_xx
      n_ga=n_gaps
      
      tpl=tpl_xx      
      tt=tt_xx
      if(kpr.eq.1)print*,'tt tpl',tt,tpl 
    
      npf=npf_xx
      if(kpr.eq.1)print*,'npf n_ga',npf,n_ga

       ntay=ntay_xx
       next=next_xx

      if(kpr.eq.1)print*,'ntay next i_wr',ntay,next,i_wr
       
      do i=1,npf
        pf(i)=pf_xx(i)
        pf_turns(i)=pf_turns_xx(i)
!        if(kpr.eq.1)print *,' i pf pf_turns-',i,pf(i),pf_turns(i)
      end do

      do i=1,n_gaps
      gaps(i)=gaps_xx(i)
!        if(kpr.eq.1)print *,' i gaps-',i,gaps(i)
      end do

	call vic_shape_elong()
	if(ntay.le.next)call shape_ip()

      call vic_shape_ip_iam()
	if(i_wr.eq.0.and.ntay.gt.next)call r_tok_p()

        call r_volt()
        
!        print *,'  vic_gaps0_read()'
        
        call vic_gaps0_read()



ccc	if(ntay.gt.next.and.tt.gt.tt_h_to_l)key_h_to_l=1
	if(kpr.eq.1)print*,'!!!tt tt_h_to_l key_h_to_l',tt,tt_h_to_l,key_h_to_l

        apr='-vchopper' 
        if(kpr.eq.1)print 71,apr,(vchopper(k),k=1,npf) 

        if(ntay.gt.next)call SCEN_CONTROL(key_h_to_l)

        apr='+vchopper' 
        if(kpr.eq.1)print 71,apr,(vchopper(k),k=1,npf) 

        call time_step_dll()



 1000 continue
 5000 format (50(1pe14.5))

      if(kpr.eq.1)print*,'END of reading signals'

	return
      end
      
	subroutine get_signals(vchopper_xx,tpl_xx,tt_dw_xx)

      include 'double.inc'
	include 'new_com2.inc'                                                  

	dimension vchopper_xx(*)
     
      do i=1,npf
        vchopper_xx(i)=vchopper(i)
      end do

      tpl_xx=tpl
      tt_dw_xx=tt_dw

      
      
 1000 continue
 5000 format (50(1pe14.5))

      if(kpr.eq.1)print*,'END of reading signals'

	return
      end
