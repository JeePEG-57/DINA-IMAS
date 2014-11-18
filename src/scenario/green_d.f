        subroutine read_psgrid()
	include 'double.inc'
	include 'parf2'
	include 'parf2e'

        common
     *  /ge5/kpr
	common
     *  /eq1/psi(nwnh),pspl(nwnh),x(NR),y(NZ),dx,dy
     *  /eq16/psgrid(nwnh,ngrid)
c
	common /fluxc8/
     *  work(nwnhe)
c
	character *200 f1,f2,f3
c
c-----------
	open (unit=40,file='flux.fl',form='formatted')
	read (40,*)
	read (40,74)f1
	read (40,*)
	read (40,74)f2
	read (40,*)
	read (40,74)f3
74	format(a110)
	close (40)
c----
	open (unit=2,file=f3,form='unformatted')

	do k=1,ngrid
	read (2) work
	do i=1,nwnhe
	psgrid(i,k)=work(i)

c        if(kpr.eq.1)print *,' i psgrid==',i,psgrid(i,k)
	end do
	end do

	if(kpr.eq.1)print *,' end of reading psgrid  '

	close (unit=2)
	return
	end
        subroutine read_flux()
	include 'double.inc'
	include 'parf1'
	include 'parf2'
	include 'parf4'
	include 'parf2e'

c	implicit real *8 (a-h,o-z)
        common
     *  /ge5/kpr
	COMMON
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /eq1e/psext(nwnh),re(nre),ze(nze),dr,dz
     *  /eq3e/FLUXARRE(nwnhe,kf)
     *  /eq10e/vesarre(nwnhe,mu)
	common
     *  /ves2/ncam,rc(mu),zc(mu)
c
	common
     *	/loop1/kloop,rl(nloop),zl(nloop),psloop(nloop)
     *	/loop5e/pslgreene(nwnhe,nloop)
c
	common
     *	/probe1/kprobe,bprobe(nprobe)
     *	/probe4e/bprgreene(nwnhe,nprobe)
c
	common /fluxc8/
     *  work(nwnhe)
c
	character *200 f1,f2
c
c-----------
	open (unit=40,file='flux.fl',form='formatted')
	read (40,*)
	read (40,74)f1
	read (40,*)
	read (40,74)f2
74	format(a110)
	close (40)
c----
	open (unit=1,file=f1,form='unformatted')
	open (unit=2,file=f2,form='unformatted')
	read(1) z0,dz,r0,dr

	if(kpr.eq.1)print *,' npf nre nze nwnhe',npf,nre,nze,nwnhe
	if(kpr.eq.1)print *,' ncam  kloop kprobe ',ncam,kloop,kprobe

	do k=1,npf
	read (1) work
	do i=1,nwnhe
	fluxarre(i,k)=work(i)
	end do
	end do

	do k=1,ncam
	read (1) work
	do i=1,nwnhe
	vesarre(i,k)=work(i)
	end do

	end do
	if(kloop.gt.0)then
	do k=1,kloop
	read (2) work
	do i=1,nwnhe
	pslgreene(i,k)=work(i)
	end do

	end do
	end if

	if(kprobe.gt.0)then
	do k=1,kprobe
	read (2) work
	do i=1,nwnhe
	bprgreene(i,k)=work(i)
	end do


c        if(k.eq.1)then
c           if(kpr.eq.1)print*,'!!!!!'
c           if(kpr.eq.1)print*,(work(i),i=1,10)
c        end if


	end do
	end if

	close (unit=1)
	close (unit=2)

	if(kpr.eq.1)print *,'z0,  dz,  r0,  dr,  nz,  nr,   npf'
	if(kpr.eq.1)print *,z0,dz,r0,dr,nz,nr,npf
c
	do i=1,nre
	re(i)=r0+(i-1)*dr
	end do
	do i=1,nze
	ze(i)=z0+(i-1)*dz
	end do
	if(kpr.eq.1)print *,'z1,   zk,    r1,     rk'
	if(kpr.eq.1)print *,ze(1),ze(nze),re(1),re(nre)

	return
	end




c
