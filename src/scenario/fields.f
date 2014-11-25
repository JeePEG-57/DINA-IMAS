	subroutine put_signals(z_cur_xx,elong_xx,xleft_xx,
     *  xright_xx,tpl_xx,tt_xx,
     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
     *  ntay_xx,next_xx,zvel_xx,pf_turns_xx,rsep_xx,klim_xx,
     *  t_end_xx,i_wr_xx)
     
cDEC$ ATTRIBUTES DLLEXPORT::  put_signals

      include 'double.inc'
	include 'new_com.inc'                                                  


	dimension pf_xx(*),gaps_xx(*),pf_turns_xx(*)

	character*70 apr

71	format(20x,a6/,(6(1pe10.3)))

      kpr=1

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
        call vic_gaps0_read()



ccc	if(ntay.gt.next.and.tt.gt.tt_h_to_l)key_h_to_l=1
	if(kpr.eq.1)print*,'!!!tt tt_h_to_l key_h_to_l',tt,tt_h_to_l,key_h_to_l

        apr='-vchopper' 
        if(kpr.eq.-1)print 71,apr,(vchopper(k),k=1,npf) 

!      print *,' -gaps1',(gaps(i),i=1,n_ga)

        if(ntay.gt.next)call SCEN_CONTROL(key_h_to_l)
!      print *,' -gaps1',(gaps(i),i=1,n_ga)

        apr='+vchopper' 
        if(kpr.eq.-1)print 71,apr,(vchopper(k),k=1,npf) 

        call time_step_dll()



 1000 continue
 5000 format (50(1pe14.5))

      if(kpr.eq.1)print*,'END of reading signals'

	return
      end
      
	subroutine get_signals(vchopper_xx,tpl_xx,tt_dw_xx,gaps_xx)
cDEC$ ATTRIBUTES DLLEXPORT::  get_signals

      include 'double.inc'
	include 'new_com.inc'                                                  

	dimension vchopper_xx(*),gaps_xx(*)
     
      do i=1,npf
        vchopper_xx(i)=vchopper(i)
      end do

      tpl_xx=tpl
      tt_dw_xx=tt_dw

      do i=1,npf
        gaps_xx(i)=gaps(i)
      end do
      
      
 1000 continue
 5000 format (50(1pe14.5))

      if(kpr.eq.1)print*,'END of reading signals'

	return
      end
