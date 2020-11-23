	subroutine tran_neut(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!     *  te0,tq0,pd0,pt0,ph0,pne,q,zeff,dm0,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3,
     *  tt_in,yGpuf,n_xx,kpr_xx)

cDEC$ ATTRIBUTES DLLEXPORT::  tran_neut

      include 'double.inc'
	include 'new_com.inc'                                                  

      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*),c_output3(*)

      parameter (kint=200)

	dimension pf_xx(kint),gaps_xx(kint),pf_turns_xx(kint)

	dimension vchopper_x2(kint),sd0_p(kint),sd0_n(kint)

	character *20 apr,filename


      common /c_GHFS/GHFS
        common /c_src1/dif_coef
      
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

!------------------------------------inputs
            
      tt=tt_in*1.d3
      n=n_xx
      
      kpr=kpr_xx

      i_en=i_en+1

c---  we think ....???

	ARG=1.
	pi=4.*atan(ARG)
!      call read_data2()

      if(kpr.eq.1)print *,' tt_in tt=',tt_in,tt

       if(kpr.eq.1)print *,' ---CALL TRAN_NEUT'
      
      
      filename='metric.dat'

      nn2=n

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


        if(i_en.gt.1)then
!        if(i_en.lt.-1)then

        do i=1,nn2
        pd0(i)=c_input1(i)
        pt0(i)=c_input2(i)
	  end do

       end if


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
      
!      call den_read()


      apr='pd0-' 
      if(kpr.eq.1)print 71,apr,(pd0(i),i=1,nn2) 
      apr='pt0-' 
      if(kpr.eq.1)print 71,apr,(pt0(i),i=1,nn2) 


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
      pne(i)=pd0(i)+pt0(i)
	end do

      apr='pne-' 
      if(kpr.eq.1)print 71,apr,(pne(i),i=1,nn2) 
     
      if(kpr.eq.1)print *,' tran_src> main_astra yGpuf GHFS=',yGpuf,GHFS

      call main_astra(a,pd0,pt0,pne,te0,tq0,n,
     *  sd0_p,sd0_n,GHFS,yGpuf)

      if(kpr.eq.1)print *,' AFTER main_astra'


      st0(1)=0.
      sd0(1)=0.
      
      do i=1,nn2
      if(sd0_p(i).lt.0)sd0_p(i)=0.
      if(sd0_n(i).lt.0)sd0_n(i)=0.
      sd0(i)=sd0_p(i)+sd0_n(i)
!      if(sd0(i).lt.0)sd0(i)=0.
      sd0(i)=0.5d0*sd0(i)*1.d-3
      st0(i)=sd0(i)
	end do

      apr='sd0_p-' 
      if(kpr.eq.1)print 71,apr,(sd0_p(i),i=1,nn2) 
      apr='sd0_n-' 
      if(kpr.eq.1)print 71,apr,(sd0_n(i),i=1,nn2) 

      apr='sd0-' 
!      if(kpr.eq.1)print 71,apr,(sd0(i),i=1,nn2) 

      DO I=1,n
    	c_output1(I)=sd0_p(i)
    	c_output2(I)=sd0_n(i)
   	c_output3(I)=sd0(i)
	end do


   	return
      end
       subroutine time_out()
       include 'double.inc'

       include 'parf0'
        include 'parf3'
c
       common
     *       /igr/ygr(iy,ny),tgr(ny),igr
       common
     *       /ng_igr/ng

       character *12 fstatus
        common
     *  /ge5/kpr
       character *12 apr

       i_dop=i_dop+1

c       open (unit=42,file='for042',access='append',
       if(i_dop.eq.1)then 
       open (unit=42,file='for046',
     *       form='formatted')
       else
c       open (unit=42,file='for042',status='old',
       open (unit=42,file='for046',access='append',
     *       form='formatted')
       end if

c
       if(kpr.eq.1)print*,'!!! i_dop igr ng',i_dop,igr,ng

       if(igr.gt.0)then
       write (42,5001)igr,ng
c
       write (42,5000) ((ygr(i,j),j=1,igr),i=1,ng),
     *(tgr(j),j=1,igr)
       
       apr='tgr'
       if(kpr.eq.1)print 71,apr,(tgr(j),j=1,igr)
       apr='ygr'
       j=igr
c       if(kpr.eq.1)print 71,apr,(ygr(i,j),i=1,ng)


c       call out42(igr,ng,ygr,tgr)
71       FORMAT(20X,A8/,(6(1X,1PE10.3)))

       igr=0
c
       if(kpr.eq.1)print *,'writing "for042",here igr ng=',igr,ng
       end if
       close (unit=42)
5001    format(4i4)
5000    format (6(1pe15.7e3))

c       stop


       return
       end
      SUBROUTINE DOPP()
	include 'double.inc'
      include 'new_com.inc'

      
      call DOPP_c(
     *	tt,pcchp,pcch)

      return
      end

      SUBROUTINE DOPP_c(
     *	tt,pcchp,pcch)


	include 'double.inc'

      include 'parf0'
      include 'parf1'
      include 'parf3'
      include 'parf8'
c
        common /c_src/src
      common /c_GHFS/GHFS

	common
     *	/n_m/n,m,mp
	common
     */igr/ygr(iy,ny),tgr(ny),igr
	common
     *	/ng_igr/ng

	character *10 mgr(iy),mt(iy)
	character *70 apr
	character *18 yy(iy)
	character *50 tmp



 1      continue

	igr=igr+1
	tgr(igr)=tt

c********************* 00 **********************************
c       ------I plasma---------
	ygr(1,igr)=pcch
	yy(1)=' N '
c
c       -------ne average-----
	ygr(2,igr)=pcchp
	yy(2)='N prog'
c
c       -----te average-----
	ygr(3,igr)=src
	yy(3)=' S0'
	
	print *,' S0==',src
	
c       -----te average-----
	ygr(4,igr)=GHFS
	yy(4)=' GHFS'

      ng=4


	tmp='names_md5'

        i_en=i_en+1
	if(i_en.eq.1)then
	open (unit=41, file=tmp,form='formatted')
	write (41,*)ng
	do i=1,ng
	write (41,*)yy(i)
	end do
	close (41)
	end if
      RETURN
      END

