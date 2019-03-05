        subroutine movem(i_c)

	include 'double.inc'
	include 'parf0'
	include 'parf1'
	include 'parf2'
	include 'parf4'
	include 'parf2e'

c	implicit real *8 (a-h,o-z)
	common
     *  /ge5/kpr
     *  /ge7/eu,rout,zout,elong
	common
     *  /pol4/ UM,VM,UK(ntet),VK(ntet)
	COMMON
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /eq1/psip(nr,nz),pspl(nwnh),x(nr),y(nz),dx,dy
     *  /eq1e/psext(nwnh),re(nre),ze(nze),dr,dz
     *  /eq3/FLUXARR(nwnh,kf)
     *  /eq3e/FLUXARRE(nwnhe,kf)
     *  /eq10/vesarr(nwnh,mu)
     *  /eq10e/vesarre(nwnhe,mu)
	common
     *  /ves2/ncam,rc(mu),zc(mu)
c
	common
     *	/loop1/kloop,rl(nloop),zl(nloop),psloop(nloop)
     *	/loop5/pslgreen(nwnh,nloop)
     *	/loop5e/pslgreene(nwnhe,nloop)
c
	common
     *	/probe1/kprobe,bprobe(nprobe)
     *	/probe4/bprgreen(nwnh,nprobe)
     *	/probe4e/bprgreene(nwnhe,nprobe)
	common
     *	/fluxc10/x1,y1,dx1,dy1
     *	/fluxc12/r00,z00,eu00

c------------------------
        if(kpr.eq.1)print *,' r00 z00 eu00 i_c=',r00,z00,eu00,i_c

	r1=re(1)
	rk=re(nre)
	z1=ze(1)
	zk=ze(nze)
c------------------------
	x1=re(1)
	y1=ze(1)
	dx1=1./dr
	dy1=1./dz
c--------------------------

        if(i_c.eq.0)go to 1000


c	alf=1.6
	alf=1.8
c###	alf=1.6

	r1a=r00-alf*eu00
	if(r1a.le.re(1))r1a=re(1)
	rka=r00+alf*eu00
	if(rka.ge.re(nre))rka=re(nre)
	r1=r1a
	rk=rka

c
	z1a=z00-elong*alf*eu00
	if(z1a.le.ze(1))z1a=ze(1)
	zka=z00+elong*alf*eu00
	if(zka.ge.ze(nze))zka=ze(nze)
	z1=z1a
	zk=zka

c        end if


	dx=(rk-r1)/(nr-1.)
	dy=(zk-z1)/(nz-1.)
c
	if(kpr.eq.1)print *,'um vm eu',r00,z00,eu00
c        read (*,*)

	if(kpr.eq.1)print *,'r1 rk z1 zk',r1,rk,z1,zk
	if(kpr.eq.1)print *,'r1a rka z1a zka',r1a,rka,z1a,zka
	if(kpr.eq.1)print *,'dx dy',dx,dy
	if(kpr.eq.1)print *,'dr dz',dr,dz
c---------------------------------------
	do i=1,nr
	x(i)=r1+(i-1)*dx
	end do
	do i=1,nz
	y(i)=z1+(i-1)*dy
	end do
c-------------------------------
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	urr=x(i)
	vrr=y(j)
	call boxde_1(urr,vrr,c00,c10,c01,c11,ij,i1j,ij1,i1j1)

	do k=1,ncam
	fint=c00*vesarre(ij,k) + c10*vesarre(i1j,k) +
     *  c01*vesarre(ij1,k)+ c11*vesarre(i1j1,k)
	vesarr(kk,k)=fint
	end do

	do k=1,npf
	fint=c00*fluxarre(ij,k) + c10*fluxarre(i1j,k) +
     *  c01*fluxarre(ij1,k)+ c11*fluxarre(i1j1,k)
	fluxarr(kk,k)=fint
	end do

	if(kloop.gt.0)then
	do k=1,kloop
	fint=c00*pslgreene(ij,k) + c10*pslgreene(i1j,k) +
     *  c01*pslgreene(ij1,k)+ c11*pslgreene(i1j1,k)
	pslgreen(kk,k)=fint
	end do
	end if
	if(kprobe.gt.0)then
	do k=1,nprobe
	fint=c00*bprgreene(ij,k) + c10*bprgreene(i1j,k) +
     *  c01*bprgreene(ij1,k)+ c11*bprgreene(i1j1,k)
	bprgreen(kk,k)=fint
	end do
	end if



	end do
	end do


	return

1000	continue

        i_en=i_en+1
        if(i_en.gt.1)return



	dx=dr
	dy=dz

	do i=1,nr
	x(i)=re(i)
	end do
	do i=1,nz
	y(i)=ze(i)
	end do

	do k=1,ncam
c---begin psicam
	do i=1,nre
	do j=1,nze
	kk=(i-1)*nze+j
c	kk1=(j-1)*nre+i
	vesarr(kk,k)=vesarre(kk,k)
	end do
	end do
	end do

	do k=1,npf
	do i=1,nre
	do j=1,nze
	kk=(i-1)*nze+j
c	kk1=(j-1)*nre+i
	fluxarr(kk,k)=fluxarre(kk,k)
	end do
	end do
	end do
	if(kloop.gt.0)then
	do k=1,kloop
	do i=1,nre
	do j=1,nze
	kk=(i-1)*nze+j
c	kk1=(j-1)*nre+i
	pslgreen(kk,k)=pslgreene(kk,k)
	end do
	end do
	end do
	end if
	if(kprobe.gt.0)then
	do k=1,nprobe
	do i=1,nre
	do j=1,nze
	kk=(i-1)*nze+j
c	kk1=(j-1)*nre+i
	bprgreen(kk,k)=bprgreene(kk,k)
	end do
	end do
	end do
	end if

c
        RETURN
        END
c

	subroutine avr(rmag,zmag,eu,k)
	include 'double.inc'
	common
     *	/fluxc12/r00,z00,eu00
	common
     *  /ge5/kpr

	dimension r(100),z(100),a(100)

	if(k.eq.1)then
	r00=rmag
	z00=zmag
	eu00=eu
	return
	end if

	i_e=i_e+1
	if(i_e.eq.1)then
	do i=1,k
	r(i)=rmag
	z(i)=zmag
	a(i)=eu
	end do
	if(kpr.eq.1)print *,' i_e k==',i_e,k
	end if

	do i=2,k
	r(i-1)=r(i)
	z(i-1)=z(i)
	a(i-1)=a(i)
	end do
	i=k
	r(i)=rmag
	z(i)=zmag
	a(i)=eu

	r00=0.
	z00=0.
	eu00=0.
	do i=1,k
	r00=r00+r(i)/k
	z00=z00+z(i)/k
	eu00=eu00+a(i)/k
	end do

	if(kpr.eq.1)print *,' r00 z00 eu00',r00,z00,eu00
c	read (*,*)
	return
	end

	subroutine avr_fdd(fdd,k)
	include 'double.inc'
	dimension fd(100)
	common
     *  /ge5/kpr

	i_e=i_e+1
	if(i_e.eq.1)then
	do i=1,k
	fd(i)=fdd
	end do
	if(kpr.eq.1)print *,' i_e k==',i_e,k
	end if

	do i=2,k
	fd(i-1)=fd(i)
	end do
	i=k
	fd(i)=fdd

	fdd=0.
	do i=1,k
	fdd=fdd+fd(i)/k
	end do

	if(kpr.eq.1)print *,' fdd================= ',fdd
	return
	end




