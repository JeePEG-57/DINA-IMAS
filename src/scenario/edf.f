	subroutine efit_eq()
 	include 'double.inc'
	include 'parf0'
	dimension adata(10)

	common
     *  /con1/gain,ta,zref,kzref                                               
	common
     *  /point1/r0,z0                                                          
 	common
     *  /ge2/NTAY,TAY,TT
        common                                                                 
     *  /ge1e/rs0,tpl
	common
     *  /pol4/UM,VM,UK(ntet),VK(ntet)                                          
	common
     *  /cont13/zmag,zvel,delrmag,delzmag
     *  /cont13e/zmag0,rmag,rmag0,rvel                                         
	common
     *  /efit1/alfax(2),betax(2)
 	common
     *  /ge7/eu,rs,zout,eksk
     *  /ge5/kpr

c---
	call edf(10,adata)
c---
	tt=adata(1)
	rs=adata(2)
	eu=adata(3)
	tpl=adata(4)
	zmag=adata(5)
	rmag=adata(10)
c---
	um=rmag
	vm=zmag

c	r0=um
c	z0=vm

	rref=rmag
	zref=zmag
c----
	if(kpr.eq.1)
     *  print *,' tt rs0 eu tpl zmag rmag',tt,rs0,eu,tpl,zmag,rmag
c
	alfax(1)=adata(5+1)
	alfax(2)=adata(5+2)
	betax(1)=adata(5+3)
	betax(2)=adata(5+4)
	if(kpr.eq.1)print *,'alfax betax',alfax,betax
	return
	end

	subroutine edf(ndata,adata)
 	include 'double.inc'
	dimension adata(ndata)

	include 'parf1'
	include 'parf4'

	dimension alfax(2),betax(2),temp(9)
	character *5000 apr,apr1,apr2
	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /loop1/kloop,RL(nloop),ZL(nloop),psloop(nloop)
     *  /ge5/kpr
c-------------
	npf=20
	kloop=41
c------------------

c	write (*,*)'enter number of iterations in EFIT'
c	read (*,*)iter
	npfc=npf-2
	open(unit=41,file='fit_efit.dat',form='formatted')
	open(unit=40,file='fit.dat',form='formatted')
	kount=0
	ncoef=1009
c---
70	format(a80)
69	format(a60)
68	format(a200)
	do i0=1,ncoef
	read (41,70)apr
c	write (40,70)apr
c	if(kpr.eq.1)print 69,apr
	if(apr(1:3).eq.' sh')then
	write (40,70)apr
	end if
	if(apr(1:3).eq.' vo')then
	write (40,70)apr
	end if
	if(apr(1:3).eq.' a(')then
	write (40,70)apr
	end if
	if(apr(23:25).eq.'F-c')then
c	if(kpr.eq.1)print *,apr(23:25)	
	write (40,70)apr
	do i=1,5
	read (41,70)apr
	write (40,70)apr
	end do
	do i=1,18
	read (41,70)apr
	end do
	end if
	if(apr(23:25).eq.'pla')then
c	if(kpr.eq.1)print *,apr(23:25)	
	write (40,70)apr
	read (41,70)apr
	write (40,70)apr
	do i=1,5
	read (41,70)apr
	end do
	end if
	if(apr(23:25).eq.'E-c')then
c	if(kpr.eq.1)print *,apr(23:25)	
	write (40,70)apr
	read (41,70)apr
	write (40,70)apr
	do i=1,15
	read (41,70)apr
	end do
	end if
	if(apr(24:30).eq.'ted psi')then
c	if(kpr.eq.1)print *,apr(24:30)	
	write (40,70)apr
	do i=1,11
	read (41,70)apr
	write (40,70)apr
	end do
	end if
	if(apr(26:38).eq.'total plasma')then
c	if(kpr.eq.1)print *,apr(26:38)	
	write (40,70)apr
	read (41,70)apr
	write (40,70)apr
	end if
	if(apr(8:14).eq.'ion sum')then
c	if(kpr.eq.1)print *,apr(8:14)	
	write (40,70)apr
	do i=1,20
	i_last=i
	read (41,68)apr
	write (40,68)apr
	if(apr(1:4).eq.'    ')go to 100
	end do
	read (41,68)apr
	write (40,68)apr
	go to 100
	end if
	if(apr(1:6).eq.'  32  ')then
c	if(kpr.eq.1)print *,' end of calculations'
	stop
	end if
	end do
100	continue
72	format(a12,e10.3,a12,e10.3,a12,e10.3)
	close (unit=41)
	close (unit=40)
c---
	open(unit=41,file='fit.dat',form='formatted')
	read (41,72)apr,x1,apr1,tt,apr2,x2
	if(kpr.eq.1)print *,'x1  time x2',x1,tt,x2
	read (41,72)apr,x1,apr1,rs0,apr2,x2
	if(kpr.eq.1)print *,'x1  rs0 x2',x1,rs0,x2
	read (41,72)apr,eu,apr1,x1,apr2,x2
	if(kpr.eq.1)print *,'a=  x1  x2',eu,x1,x2
	read (41,*)
	read (41,*)(pf(i),i=1,npfc)
	do i=1,npfc
	pf(i)=pf(i)*1.e-3
	end do
	if(kpr.eq.1)print *,'pf===',pf
	read (41,*)
	read (41,*)(alfax(i),i=1,2),(betax(i),i=1,2)
	if(kpr.eq.1)print *,'alfa',alfax
	if(kpr.eq.1)print *,'beta',betax
	read (41,*)
	read (41,*)(pf(i),i=19,20)
	do i=19,20
	pf(i)=pf(i)*1.e-3
	end do
	if(kpr.eq.1)print *,'ecoils cur=',(pf(i),i=19,20)
	read (41,*)
	read (41,*)(psloop(i),i=1,nloop)
	read (41,*)
	read (41,*)tpl
	if(kpr.eq.1)print *,' tpl===',tpl
	do i=1,i_last-1
	read (41,*)
	end do
	read (41,*)it,(temp(i),i=1,6)
	kount=kount+1
73	format(i5)
	close (unit=41)
	zmag=temp(6)
	rmag=temp(5)
	if(kpr.eq.1)print *,' it, rmag zmag===',it,rmag,zmag
	adata(1)=tt*1.e3
	adata(2)=rs0
	adata(3)=eu
	adata(4)=tpl*1.e-3
	adata(5)=zmag
c
	adata(5+1)=alfax(1)
	adata(5+2)=alfax(2)
	adata(5+3)=betax(1)
	adata(5+4)=betax(2)
	adata(5+5)=rmag
	if(kpr.eq.1)print *,' adata=',(adata(i),i=1,10)
	npf=22
	return
	end


