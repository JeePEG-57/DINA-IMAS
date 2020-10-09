	subroutine transp20(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!     *  te0,tq0,pd0,pt0,ph0,pne,q,zeff,dm0,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3,
     *  tt_in,pcch_xx,n_xx)

cDEC$ ATTRIBUTES DLLEXPORT::  transp20

      include 'double.inc'
	include 'new_com.inc'                                                  

      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*),c_output3(*)

      parameter (kint=200)

	dimension pf_xx(kint),gaps_xx(kint),pf_turns_xx(kint)

	dimension vchopper_x2(kint)

	character *20 apr,filename


      common /c_GHFS/GHFS
        common /c_src1/dif_coef
        common /c_src2/src1,src2,sd0_p(npo),sd0_n(npo)

      common /cc_tran2/pd_b,pt_b
      
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

!------------------------------------inputs

      tt0=tt
      tt=tt_in*1.d3
      tay=tt-tt0



      if(kpr.eq.1)print *,' tt_in tt=',tt_in,tt
      if(kpr.eq.1)print *,' pd_b,pt_b=',pd_b,pt_b


      i_en=i_en+1
      if(i_en.eq.1)then
      
 	ARG=1.
	pi=4.*atan(ARG)
!      call read_data2()

      nij=1

!        open (unit=1,file='kpr.dat',form='formatted')
        open (unit=1,file='external_data.dat',form='formatted')
        read (1,*)
        read (1,*)kpr
        read (1,*)
        read (1,*)GHFS,d_GHFS,tay1

        read (1,*)
        read (1,*)GHFS_uu,d_GHFS_uu,tay1_uu
      
!        close ( unit=1)       

      dif_coef=1.
      tay=5.
      eu=160.
      rout=620.
      ktp=1
      kd2=1
      dd=1.
      it=1
      id=1
      end if

 
      
      
      filename='metric.dat'

      n=n_xx
      nn2=n
      if(kpr.eq.1)print *,' CALL TRANSP20 n==',n

      do i=1,nn2
      sd0_p(i)=c_input1(i)
      sd0_n(i)=c_input2(i)
	end do

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
      
      if(i_en.eq.1)then
      pd_b=pd0(n)
      pt_b=pt0(n)
      end if
       
        if(i_en.gt.1)then
        do i=1,nn2
        pd0(i)=pdn(i)
        pt0(i)=ptn(i)
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
      
      call den_read()

      if(i_en.eq.1)then
!      read (1,*)
      close (unit=1)
      end if
      
      if(i_en.eq.1)then
      call time_step_tran()
      end if


      pd0(n)=pd_b
      pt0(n)=pt_b

      print *,' pd_b pt_b',pd_b,pt_b


      apr='pdn-' 
      if(kpr.eq.1)print 71,apr,(pdn(i),i=1,nn2) 
      apr='ptn-' 
      if(kpr.eq.1)print 71,apr,(ptn(i),i=1,nn2) 

      do i=1,nn2
      pne(i)=pd0(i)+pt0(i)
	end do

      apr='pne-' 
      if(kpr.eq.1)print 71,apr,(pne(i),i=1,nn2) 
     

!      call main_astra(a,pd0,pt0,pne,te0,tq0,n,
!     *  sd0_p,sd0_n,GHFS)

      st0(1)=0.
      sd0(1)=0.
      
      do i=2,nn2
      sd0(i)=sd0_p(i)+sd0_n(i)
      if(sd0(i).lt.0)sd0(i)=0.
      sd0(i)=0.5d0*sd0(i)*1.d-3
      st0(i)=sd0(i)
	end do

      do i=1,5
      sd0(i)=sd0(6)
      st0(i)=sd0(i)
	end do

       apr='sd0_p-' 
      if(kpr.eq.1)print 71,apr,(sd0_p(i),i=1,nn2) 
       apr='sd0_n-' 
      if(kpr.eq.1)print 71,apr,(sd0_n(i),i=1,nn2) 

      apr='sd0-' 
      if(kpr.eq.1)print 71,apr,(sd0(i),i=1,nn2) 

      CALL TP(N)
      apr='pd0-' 
      if(kpr.eq.1)print 71,apr,(pd0(i),i=1,nn2) 
      apr='pt0-' 
      if(kpr.eq.1)print 71,apr,(pt0(i),i=1,nn2) 

      call den_read()
	call dens_prog()
      
      del=pcch-pcchp
      V=del/tay
!      dGHFS=-d_GHFS*( del+V*tay1 )
!      GHFS=GHFS+dGHFS
!      if(GHFS.le.GHFS0)GHFS=GHFS0
      
!      if(kpr.eq.1)print *,' pcchp  pcch',pcchp,pcch
!      if(kpr.eq.1)print *,' GHFS  del',GHFS,del
!      if(kpr.eq.1)print *,' d_GHFS tay1',d_GHFS,tay1

      call time_step_tran()

!      ntay=ntay+1

      DO I=1,n
    	c_output1(I)=pd0(i)
    	c_output2(I)=pt0(i)
   	c_output3(I)=pne(i)
	end do

      call DOPP()
      call time_out()

!        tt=tt+tay
        ntay=ntay+1
         pcch_xx=pcch
 !     stop      

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
       open (unit=42,file='for045',
     *       form='formatted')
       else
c       open (unit=42,file='for042',status='old',
       open (unit=42,file='for045',access='append',
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
        common /c_src2/src1,src2,sd0_p(npo),st0_n(npo)

	character *10 mgr(iy),mt(iy)
	character *70 apr,apr2
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
	ygr(3,igr)=src1
	yy(3)=' S pel'
	
	if(kpr.eq.1)print *,' S0==',src
	
c       -----te average-----
	ygr(4,igr)=src2
	yy(4)=' S puff'

      ng=4
      
      i_en3=i_en3+1
      
         if(i_en3.eq.1)then
         open (unit=1,file='source_ext.dat',form='formatted')
         apr2='tt[s]	S_pel[19m-3s-1]		S_puf[19m-3s-1]'
         
         write (1,*)apr2
         end if
         if(i_en3.gt.1)then
         open (unit=1,file='source_ext.dat',
     *  access='append',form='formatted')
         end if
         
      write (1,*)tt*1.e-3,src1,src2
      
      close(1)

	 


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

