	subroutine transp6(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!     *  te0,tq0,pd0,pt0,ph0,pne,q,zeff,dm0,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3)

cDEC$ ATTRIBUTES DLLEXPORT::  transp6

      include 'double.inc'
	include 'new_com.inc'                                                  

      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*),c_output3(*)

      parameter (kint=200)

	dimension pf_xx(kint),gaps_xx(kint),pf_turns_xx(kint)

	dimension vchopper_x2(kint)

	character *20 apr,filename

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

!------------------------------------inputs


       if(kp.eq.1)print *,' CALL TRANSP6'

      i_en=i_en+1
      if(i_en.eq.1)then
        open (unit=1,file='kpr.dat',form='formatted')
        read (1,*)
        read (1,*)kpr
        close ( unit=1)       
c---  we think ....???
	ARG=1.
	pi=4.*atan(ARG)
      call read_data2()

      nij=1

           GHFS=200.

      end if

      nn2=n
      
      
      filename='metric.dat'

c-------
           open (unit=41,file=filename,form='formatted')           
           read (41,*,err=2000,end=2000)(a(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(te0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(tq0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(pd0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(pt0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(ph0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(pne(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(q(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(zeff(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(dm0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(dfmax(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(vi(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(a_m(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(r_m(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(gra1(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(gra2(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(bsq(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(fasp(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(volt(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(tok1(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(f(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(spo(i),i=1,nn2)

           close (41)
           

           
2000	continue


      do i=2,n
      ha(i)=a(i)-a(i-1)
      psi8(i)=(dm0(i)-dm0(i-1))/ha(i)
	end do

      DO 31 I=2,N
      AI(I)=0.5*(A(I)+A(I-1))
	ha2(i-1)=ai(i)-ai(i-1)
31	continue
      HA2(N)=a(n)-ai(n)

      VMAX=1.E5
      DO I=1,n
    	VN(I)=VI(I)/VMAX
	end do
      
      kpr2=0
      if(kpr2.eq.1)then
      
      apr='vi-' 
      if(kpr.eq.1)print 71,apr,(vi(i),i=1,nn2) 
      apr='dm0-' 
      if(kpr.eq.1)print 71,apr,(dm0(i),i=1,nn2) 
      apr='psi-' 
      if(kpr.eq.1)print 71,apr,(psi8(i),i=1,nn2) 
      apr='ha-' 
      if(kpr.eq.1)print 71,apr,(ha(i),i=1,nn2) 
      apr='tok1-' 
      if(kpr.eq.1)print 71,apr,(tok1(i),i=1,nn2) 
      apr='volt-' 
      if(kpr.eq.1)print 71,apr,(volt(i),i=1,nn2) 
      apr='bsq-' 
      if(kpr.eq.1)print 71,apr,(bsq(i),i=1,nn2) 
      apr='fasp-' 
      if(kpr.eq.1)print 71,apr,(fasp(i),i=1,nn2) 
      
      
      
      end if
      

      if(i_en.eq.1)then
      call time_step_tran()
      end if

      apr='pdn-' 
      if(kpr.eq.1)print 71,apr,(pdn(i),i=1,nn2) 
      apr='ptn-' 
      if(kpr.eq.1)print 71,apr,(ptn(i),i=1,nn2) 


! IN:
!	yMu	[a.u.]	normalised pressure in the div. (must be < 1)
!	ySeng	[m3/s]		engineering pumping speed (must be < 75)
! 	yGsol	[10^19/s]	diffusive flux to the SOL 
! (note that for stable simulation we suggest to use a preset target value, rather than istanteneouse)
!	yPsol_	[MW] 		power to SOL (we used Palp+Paux-Prad)
!	yPalp	[MW]		fusion source in alphas
!	Ycnim	nimp/nes	fraction of Ne at the edge (should be 0.02-0.002)
!	yGNBI	[10^19/s]	particle source-sink (GNBI - recombination)  
!	yL_OH	[a.u.]		=0(1)switch betwee OH&L mode (H-mode)

      yMu=0.2
      ySeng=30.
      yGsol=0.2
      yPsol_=10.
      yPalp=10.
      Ycnim=0.01
      yGNBI=0.1
      yL_OH=0

      do i=1,nn2
      pne(i)=pdn(i)+ptn(i)
	end do

      apr='pne-' 
      if(kpr.eq.1)print 71,apr,(pne(i),i=1,nn2) 
     

      call main_astra(a,pd0,pt0,pne,te0,tq0,n,sd0,GHFS)

      st0(1)=0.
      sd0(1)=0.
      
      do i=2,nn2
      st0(i)=sd0(i)
	end do


      apr='sd0-' 
      if(kpr.eq.1)print 71,apr,(sd0(i),i=1,nn2) 

      CALL TP(N)
      apr='pd0-' 
      if(kpr.eq.1)print 71,apr,(pd0(i),i=1,nn2) 
      apr='pt0-' 
      if(kpr.eq.1)print 71,apr,(pt0(i),i=1,nn2) 

      call den_read()
	call dens_prog()
      
      al1=pcchp/pcch
      
      dGHFS=1.d2*(al1-1.d0)*tay
      GHFS=GHFS+dGHFS
      
      if(kpr.eq.1)print *,' pcchp  pcch',pcchp,pcch
      if(kpr.eq.1)print *,' GHFS  al1',GHFS,al1
      if(kpr.eq.1)print *,' dGHFS  tay',dGHFS,tay

      call time_step_tran()

!      ntay=ntay+1

      DO I=1,n
    	c_output1(I)=pd0(i)
    	c_output2(I)=pt0(i)
   	c_output3(I)=pne(i)
	end do

 !     stop      

      return
      
      
      

      kk=0
      do i=1,n
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

!        c_output1(1)=tpl_x2      
!        c_output1(2)=tt_dw_x2      
      
        do i=1,npf
!        c_output2(i)=vchopper_x2(i)
        end do


      return
      end



	subroutine put_signals(z_cur_xx,elong_xx,xleft_xx,
     *  xright_xx,tpl_xx,tt_xx,
     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
     *  ntay_xx,next_xx,zvel_xx,pf_turns_xx,rsep_xx,klim_xx,
     *  t_end_xx,i_wr_xx)
     

      include 'double.inc'
	include 'new_com.inc'                                                  


	dimension pf_xx(*),gaps_xx(*),pf_turns_xx(*)

	character*70 apr

71	format(20x,a6/,(6(1pe10.3)))

!      kpr=1



 1000 continue
 5000 format (50(1pe14.5))

      if(kpr.eq.1)print*,'END of reading signals'

	return
      end
      
	subroutine get_signals(vchopper_xx,tpl_xx,tt_dw_xx)

      include 'double.inc'
	include 'new_com.inc'                                                  

	dimension vchopper_xx(*)
     
      do i=1,npf
!        vchopper_xx(i)=vchopper(i)
      end do

!      tpl_xx=tpl
!      tt_dw_xx=tt_dw

      
      
 1000 continue
 5000 format (50(1pe14.5))

      if(kpr.eq.1)print*,'END of reading signals'

	return
      end
