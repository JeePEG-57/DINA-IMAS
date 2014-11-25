	subroutine dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2)

      include 'double.inc'
	include 'new_com.inc'                                                  

      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*)

      parameter (kint=200)

	dimension pf_xx(kint),gaps_xx(kint),pf_turns_xx(kint)

	dimension vchopper_x2(kint)

!-----------------------------------  inputs---
!     *  vchopper_x2,tpl_x2,tt_dw_x2)

	
      i_en=i_en+1
      if(i_en.gt.2)then

        tpl_x2=c_input1(1)      
        tt_dw_x2=c_input1(2)   
        
        if(kpr.eq.1)print *,'   tpl_x2==',tpl_x2 
      
        do i=1,npf
        vchopper_x2(i)=c_input2(i)
        end do
      

!      if(kpr.eq.1)print *,'  +zvel==',zvel


      call get_contr_signals(vchopper_x2,tpl_x2,tt_dw_x2)
      end if

!      if(kpr.eq.1)print *,'  ++zvel==',zvel

      
 	call equil()
c  i_fil=0  old case without reconstruction....

!      if(kpr.eq.1)print *,'  2++zvel==',zvel

	call separ_coor()                                                
	call separ_coor2()                                                
      call get_gaps()

!      if(kpr.eq.1)print *,'  3++zvel==',zvel

	ntay=ntay+1
	tt=tt+tay


	if(kpr.eq.1)print*,'!!!tt tay ntay',tt,tay,ntay

!	if(kpr.eq.1)print*,'@@@@@from main  next',next

	if(kpr.eq.1)print*,'put_signals'

	call put_dina_signals(z_cur_xx,elong_xx,xleft_xx,
     *  xright_xx,tpl_xx,tt_xx,
     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
     *  ntay_xx,next_xx,zvel_xx,pf_turns_xx,rsep_xx,klim_xx,
     *  t_end_xx,i_wr_xx)

!------------------------------------outputs
!     *  z_cur_xx,elong_xx,xleft_xx,
!     *  xright_xx,tpl_xx,tt_xx,
!     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
!     *  ntay_xx,next_xx,zvel_xx,pf_turns_xx,rsep_xx,klim_xx,
!     *  t_end_xx,i_wr_xx,

        c_output1(1)=z_cur_xx
        c_output1(2)=elong_xx
        c_output1(3)=xleft_xx
        c_output1(4)=xright_xx
        c_output1(5)=tpl_xx
        c_output1(6)=tt_xx
        c_output1(7)=npf_xx
        c_output1(8)=n_gaps_xx
        c_output1(9)=ntay_xx
        c_output1(10)=next_xx
        c_output1(11)=zvel_xx
        
!        if(kpr.eq.1)print *,'  ++zvel_xx==',zvel_xx

        c_output1(12)=rsep_xx
        c_output1(13)=klim_xx
        c_output1(14)=t_end_xx
        c_output1(15)=i_wr_xx

      kk=0
      do i=1,npf_xx
      kk=kk+1
      c_output2(kk)=pf_xx(i)
      end do
      do i=1,n_gaps_xx
      kk=kk+1
      c_output2(kk)=gaps_xx(i)
      end do
      do i=1,npf_xx
      kk=kk+1
      c_output2(kk)=pf_turns_xx(i)
      end do

      return  	 
      END
	subroutine put_dina_signals(z_cur_xx,elong_xx,xleft_xx,
     *  xright_xx,tpl_xx,tt_xx,
     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
     *  ntay_xx,next_xx,zvel_xx,pf_turns_xx,rsep_xx,klim_xx,
     *  t_end_xx,i_wr_xx)
     
      include 'double.inc'
	include 'new_com.inc'                                                  

	dimension pf_xx(*),gaps_xx(*),pf_turns_xx(*)

	character*70 apr

71	format(20x,a6/,(6(1pe10.3)))

 !     kpr=1

c------------
      i_wr_xx=i_wr
      klim_xx=klim
      t_end_xx=t_end
      
      if(kpr.eq.1)print*,'klim t_end ',klim,t_end
      
      rsep_xx=rsep
      zvel_xx=zvel
      if(kpr.eq.1)print*,'rsep zvel ',rsep,zvel
      
      z_cur_xx=z_cur
      elong_xx=elong
      if(kpr.eq.1)print*,'z_cur elong ',z_cur,elong

      xleft_xx=xleft
      xright_xx=xright

      if(kpr.eq.1)print*,'xleft xright ',xleft,xright

      n_gaps=n_ga
      n_gaps_xx=n_gaps
      
      tpl_xx=tpl      
      tt_xx=tt
      if(kpr.eq.1)print*,'tt tpl',tt,tpl 
    
      npf_xx=npf
      if(kpr.eq.1)print*,'npf n_ga',npf,n_ga

       ntay_xx=ntay
       next_xx=next

      if(kpr.eq.1)print*,'ntay next i_wr',ntay,next,i_wr
       
      do i=1,npf
        pf_xx(i)=pf(i)
        pf_turns_xx(i)=pf_turns(i)
!        if(kpr.eq.1)print *,' i pf pf_turns-',i,pf(i),pf_turns(i)
      end do

      do i=1,n_gaps
      gaps_xx(i)=gaps(i)
!        if(kpr.eq.1)print *,' i gaps-',i,gaps(i)
      end do

 1000 continue
 5000 format (50(1pe14.5))

	return
      end
	subroutine get_contr_signals(vchopper_xx,tpl_xx,tt_dw_xx)

      include 'double.inc'
	include 'new_com.inc'                                                  

	dimension vchopper_xx(*)
     
      do i=1,npf
        vchopper(i)=vchopper_xx(i)
      end do

      tpl=tpl_xx
      tt_dw=tt_dw_xx

      
      
 1000 continue
 5000 format (50(1pe14.5))

      if(kpr.eq.1)print*,'END of reading contr_signals'

	return
      end
