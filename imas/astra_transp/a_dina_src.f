	subroutine dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3)

      include 'double.inc'
	include 'new_com.inc'                                                  

      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*),c_output3(*)

      parameter (kint=200)

	dimension pf_xx(kint),gaps_xx(kint),tcam_xx(kint)

	dimension vchopper_x2(kint),shape_out(kint)

	character *30 apr                                                      
	dimension a_print(200)

	common /c_data_in_time2/i_c_data,i_c_data1       

      common /c_tran2/k_ener_ext,k_dens_ext,k_ajb_ext
!-----------------------------------  inputs---
!     *  vchopper_x2,tpl_x2,tt_dw_x2)

!	kpr=1
	
      i_en=i_en+1
      
      k_ener_ext=1
      k_dens_ext=1
      k_ajb_ext=1


      call transp7(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3)
 	
	do i=1,n
	
	pd0(I)=c_output1(i)
	pt0(I)=c_output2(i)
	pne(I)=c_output3(i)
	
      pd0_tran(I)=pd0(I)
	pt0_tran(I)=pt0(I)
	pne_tran(I)=pne(I)
	
      end do


!      call write_tran1()


	if(kpr.eq.1)print*,'!!!tt tay ntay',tt,tay,ntay

!	if(kpr.eq.1)print*,'@@@@@from main  next n ',next,n

!	if(kpr.eq.1)print*,'put_signals'
                                                                        

	shape_out(1)=tpl_mat                                                   

	shape_out(2)=rmag*1.d-2                                                

	shape_out(3)=zmag*1.d-2                                                

	shape_out(4)=eu*1.d-2 
	                                                 
!!!	shape_out(4)=eu_95*1.d-2

c$	call trian()

	shape_out(5)=elong  
	                                                
!!!	shape_out(5)=elong_95

c	shape_out(6)=el_up                                                     
c	shape_out(6)=el_up_95

c	shape_out(7)=el_dw
c	shape_out(7)=el_dw_95


	shape_out(6)=bz_pl

!	shape_out(7)=bz_ext
	shape_out(7)=br_pl

!	shape_out(8)=shafra(1)                                                  

c	shape_out(8)=tri_95                                                  

!!!	shape_out(9)=tri_up                                                    


	shape_out(9)=udd
c	shape_out(9)=tri_up_95

c	shape_out(10)=ptot

!!!	shape_out(10)=tri
	shape_out(10)=f_index

c ***  **********
	a_print(1)= shape_out(6)
	a_print(2)= shape_out(7)
	a_print(3)= shape_out(10)
	
	n_pr=3
	apr='shape_out(6,7-10)'
	num=25
c	call out42(n_pr,a_print,num,apr)
c ***  **********                                                                        

	shape_out(11)=betj                                                     

	shape_out(12)=uli                                                      

	shape_out(13)=q(2)                                                     

	shape_out(14)=q(n)

!!!	shape_out(14)=q_95


c        print *,' q_a q_b',q(2),q(n)

                                                     

	  shape_out(15)=te0(1)

c        shape_out(16)=rsep*1.e-2


      if(tene.le.1000.)then 
 	shape_out(16)=tene*1.d-3
	else
 	shape_out(16)=1000.*1.d-3
	end if

!	if(kpr.eq.1)print *,' tene_e===',tene_e

c!!!        shape_out(17)=zsep*1.e-2

        shape_out(17)=uact

c---------------------- We are changing here----

        shape_out(18)=tq0(1)

        shape_out(19)=pcch*1.d19

c-------------------------------------------------------

c        shape_out(20)=pmag*1.e-5

!!        shape_out(20)=power_ech2*1.e6
!!!        shape_out(20)=ptot_dop*1.d6
        shape_out(20)=q_ech

c        shape_out(21)=psep*1.e-5
	
!!!        shape_out(21)=tokbut*1.d3

       shape_out(21)=qlos_imp

!!!        shape_out(22)=tokuv*1.d3
       shape_out(22)=zeff(1)

        if(i_eccd.ne.0)q_rz=q(i_eccd)



!        if(kpr.eq.1)print *,' i_eccd q_rz==',i_eccd,q_rz



c        shape_out(23)=q_rz        !  q at R,Z location o ECCD 


      shape_out(23)=tt      !  q at R,Z location o ECCD 

!!!	shape_out(24)=p_turb                                                
	shape_out(24)=ratio_imp                                                

	k_out_dina=24

	shape_out(25)=rsep                                                
	shape_out(26)=zsep 

	k_out_dina=26

c  EXTRA for KTM

	shape_out(27)=vs_pf                                                
	shape_out(28)=vs_pl                                               
	shape_out(29)=vs_res                                                
	shape_out(30)=vs_tot

	shape_out(31)=fdd*1.d-5

	shape_out(32)=vs_ext
 
	if(i_c_data.eq.0)then                 
!	call print3(' psi_pf,psipl_av,psiext_av==',
!     *  psi_pf,psipl_av,psiext_av)
!
!	call print3(' vs_pf,vs_pl,vs_ext==',
!     *  vs_pf,vs_pl,vs_ext)

	shape_out(27)=psi_pf                                               
	shape_out(28)=psipl_av                                               
	shape_out(32)=psiext_av

	end if


!!!	shape_out(32)=pll*tpl*1.d-5

	k_out_dina=32

      return  	 
      END
	subroutine put_dina_signals(z_cur_xx,elong_xx,xleft_xx,
     *  xright_xx,tpl_xx,tt_xx,
     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
     *  ntay_xx,ncam_xx,zvel_xx,tcam_xx,rsep_xx,klim_xx,
     *  zsep_xx,i_wr_xx)
     
      include 'double.inc'
	include 'new_com.inc'                                                  

	dimension pf_xx(*),gaps_xx(*),tcam_xx(*)

	character*70 apr

71	format(20x,a6/,(6(1pe10.3)))

 !     kpr=1

c------------
      i_wr_xx=i_wr
      klim_xx=klim
      zsep_xx=zsep
      
      if(kpr.eq.1)print*,'klim zsep ',klim,zsep
      
      rsep_xx=rsep*1.d-2
!!!      zvel_xx=zvel
      zvel_xx=zmag*1.d-2
      if(kpr.eq.1)print*,'rsep zvel ',rsep,zvel
      
      z_cur_xx=z_cur*1.d-2
      elong_xx=elong
      if(kpr.eq.1)print*,'z_cur elong ',z_cur,elong

      xleft_xx=xleft*1.d-2
      xright_xx=xright*1.d-2

      if(kpr.eq.1)print*,'xleft xright ',xleft,xright

      if(n_ga.eq.0)n_ga=6
      
      n_gaps=n_ga
      n_gaps_xx=n_gaps
      
      tpl_xx=tpl*1.d+3      
      tt_xx=tt
      if(kpr.eq.1)print*,'tt tpl',tt,tpl 
    
      npf_xx=npf
      if(kpr.eq.1)print*,'npf n_ga',npf,n_ga

       ntay_xx=ntay
       ncam_xx=ncam

      if(kpr.eq.1)print*,'ntay ncam i_wr',ntay,ncam,i_wr

      do i=1,n_gaps
      gaps_xx(i)=gaps(i)*1.d-2
!        if(kpr.eq.1)print *,' i gaps-',i,gaps(i)
      end do
       
      do i=1,npf
        pf_xx(i)=pf(i)*1.d+3
!        if(kpr.eq.1)print *,' i pf pf_turns-',i,pf(i),pf_turns(i)
      end do

      do i=1,ncam
        tcam_xx(i)=tcam(i)*1.d+3
!        if(kpr.eq.1)print *,' i pf pf_turns-',i,pf(i),pf_turns(i)
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

!      tpl=tpl_xx
!      tt_dw=tt_dw_xx

      
      
 1000 continue
 5000 format (50(1pe14.5))

      if(kpr.eq.1)print*,'END of reading contr_signals'

	return
      end


	subroutine write_tran1()
      
      include 'double.inc'
	include 'new_com.inc'                                                  

	character * 20 apr,filename

71	format(20x,a6/,(6(1pe10.3)))


      filename='metric.dat'

      nn2=n
c-------
           open (unit=41,file=filename,form='formatted')           
           write (41,5000)(a(i),i=1,nn2)
           write (41,5000)(te0(i),i=1,nn2)
           write (41,5000)(tq0(i),i=1,nn2)
           write (41,5000)(pd0(i),i=1,nn2)
           write (41,5000)(pt0(i),i=1,nn2)
           write (41,5000)(ph0(i),i=1,nn2)
           write (41,5000)(pne(i),i=1,nn2)
           write (41,5000)(q(i),i=1,nn2)
           write (41,5000)(zeff(i),i=1,nn2)
           write (41,5000)(dm0(i),i=1,nn2)
           write (41,5000)(dfmax(i),i=1,nn2)
           write (41,5000)(vi(i),i=1,nn2)
           write (41,5000)(a_m(i),i=1,nn2)
           write (41,5000)(r_m(i),i=1,nn2)
           write (41,5000)(gra1(i),i=1,nn2)
           write (41,5000)(gra2(i),i=1,nn2)
           write (41,5000)(bsq(i),i=1,nn2)
           write (41,5000)(fasp(i),i=1,nn2)
           write (41,5000)(volt(i),i=1,nn2)
           write (41,5000)(tok1(i),i=1,nn2)
           write (41,5000)(f(i),i=1,nn2)
           write (41,5000)(spo(i),i=1,nn2)

           close (41)

      apr='a-' 
      if(kpr.eq.1)print 71,apr,(a(i),i=1,nn2) 
      apr='te0-' 
      if(kpr.eq.1)print 71,apr,(te0(i),i=1,nn2) 
      apr='tq0-' 
      if(kpr.eq.1)print 71,apr,(tq0(i),i=1,nn2) 
      apr='pd0-' 
      if(kpr.eq.1)print 71,apr,(pd0(i),i=1,nn2) 
      apr='pt0-' 
      if(kpr.eq.1)print 71,apr,(pt0(i),i=1,nn2) 
      apr='ph0-' 
      if(kpr.eq.1)print 71,apr,(ph0(i),i=1,nn2) 
      apr='pne-' 
      if(kpr.eq.1)print 71,apr,(pne(i),i=1,nn2) 
      apr='q-' 
      if(kpr.eq.1)print 71,apr,(q(i),i=1,nn2) 
      apr='zeff-' 
      if(kpr.eq.1)print 71,apr,(zeff(i),i=1,nn2) 
      apr='dm0-' 
      if(kpr.eq.1)print 71,apr,(dm0(i),i=1,nn2) 
      apr='dfmax-' 
      if(kpr.eq.1)print 71,apr,(dfmax(i),i=1,nn2) 
      apr='vi-' 
      if(kpr.eq.1)print 71,apr,(vi(i),i=1,nn2) 
      apr='a_m-' 
      if(kpr.eq.1)print 71,apr,(a_m(i),i=1,nn2) 
      apr='r_m-' 
      if(kpr.eq.1)print 71,apr,(r_m(i),i=1,nn2) 
      apr='gra1-' 
      if(kpr.eq.1)print 71,apr,(gra1(i),i=1,nn2) 
      apr='gra2-' 
      if(kpr.eq.1)print 71,apr,(gra2(i),i=1,nn2) 
      apr='bsq-' 
      if(kpr.eq.1)print 71,apr,(bsq(i),i=1,nn2) 
      apr='fasp-' 
      if(kpr.eq.1)print 71,apr,(fasp(i),i=1,nn2) 
      apr='volt-' 
      if(kpr.eq.1)print 71,apr,(volt(i),i=1,nn2) 
      apr='tok1-' 
      if(kpr.eq.1)print 71,apr,(tok1(i),i=1,nn2) 
      apr='f-' 
      if(kpr.eq.1)print 71,apr,(f(i),i=1,nn2) 
      apr='spo-' 
      if(kpr.eq.1)print 71,apr,(spo(i),i=1,nn2) 

 5000 format (50(1pe14.5))

      if(kpr.eq.1)print*,'END of writing tran1'

	return
      end
