	subroutine svd_d3d()
	include 'double.inc'
	include 'parf1'
	dimension indpf(kf)
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ef_0/key_ef

	CHARACTER*120 fshot,tmp

	k_svd=k_svd+1

74      format(a110)                                                           
	if(k_svd.eq.1)then
c---
     	open(unit=2,file='for040.fl',status='old',form='formatted')
	read (2,*)
	read (2,74)tmp
	close (2)
c---
     	open(unit=41,status='old',file=tmp,form='formatted')
	read (41,*)
	read (41,*)(indpf(i),i=1,npf)
	read (41,*)
	read (41,*)seps1,seps2,seps3
c	read (41,*)
c	read (41,*)i_svd,i_cal
c	if(kpr.eq.1)print *,'i_svd i_cal',i_svd,i_cal
	close (41)
	end if
	
	if(kpr.eq.1)print *,' KEY_EF==',key_ef
c	read (*,*)

	if(key_ef.eq.0)call gsvd(indpf,seps1,seps2,seps3)
	if(key_ef.eq.1)call gsvd_ef(indpf,seps1,seps2,seps3)

	return
	end
	subroutine gsvd(indpf,seps1,seps2,seps3)
	include 'double.inc'
c	implicit real *8 (a-h,o-z)
c====================

	include 'parf1'
	include 'parf4'
	include 'parf5'

	dimension amat(nx,mx),y(nx),indpf(kf),
     *  jpf(kf),sig(nx),a(kf)
	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /fwt/fwtp(nloop),fwtb(nprobe)
	common
     *  /probe1/kprobe,bprobe(nprobe)
     *  /probe2/pfprobe(nprobe,kf),vesprobe(nprobe,mu)
     *  /probe3/kpb,Rprobe(nprobe,npb),
     *  zprobe(nprobe,npb),cosa(nprobe),sina(nprobe)
     *  /probe5/bprobep(nprobe)
	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *  /loop1/kloop,RL(nloop),ZL(nloop),psloop(nloop)
     *  /loop2/pfgreen(nloop,kf),vesgreen(nloop,mu)
     *  /loop3/vloop,psf1a,psf1a0
     *  /loop4/psloopg(nloop),psloopg0(nloop)
     *  /loop6/psloopp(nloop)
	common
     *  /ge1/pi
	common
     *  /svd1/psloop_e(nloop),bprobe_e(nprobe)
     *  /svd2/pf_e(kf)
c
	character*70 apr
c
	dimension pfc(kf)
c
71	format(20x,a6/,(6(1pe10.3)))
c
c   transformation to api=volt*second/2pi

	api=1.e-5/(2.*pi)
c  icam=0 no vesse icam=1 vessel presented
	icam=1
c---
	do i=1,npf
c	pfc(i)=0.
c	pfc(i)=pf(i)
	pfc(i)=pf_e(i)
	end do
c
	k=0
	do i=1,npf
	k=k+indpf(i)
	if(indpf(i).ne.0)jpf(k)=i
	end do
	ma=k
	ma1=ma
ccc	ndata=kloop+ma1
	ndata=kloop+ma1+kprobe
c
c	if(kpr.eq.1)print *,' ma ndata ',ma,ndata
c
	do i=1,ndata
	do j=1,ma
	amat(i,j)=0.
	end do	
	end do
c
c   here start loops....
	psmax=0.
	k_l=0
	do ii=1,kloop
	if(fwtp(ii).gt.0)then
	k_l=k_l+1
	y(ii)=psloop_e(ii)
	if(abs(y(ii)).gt.psmax)psmax=abs(y(ii))
	end if
	end do
	bsmax=0.
	k_b=0
	do ii=1,kprobe
	if(fwtb(ii).gt.0)then
	k_b=k_b+1
	y(ii)=bprobe_e(ii)
	if(abs(y(ii)).gt.bsmax)bsmax=abs(y(ii))
	end if
	end do
	if(kpr.eq.1)print *,' kloop k_l kprobe k_b psmax bsmax',kloop,
     *  k_l,kprobe,k_b,psmax,bsmax
	pfmax=0.
	do k=1,ma1
	kjj=jpf(k)
	if(pfmax.lt.abs(pfc(kjj)))pfmax=abs(pfc(kjj))
	end do
	if(kpr.eq.1)print *,' psmax bsmax pfmax',psmax,bsmax,pfmax
	kk=0
	do 100 ii=1,kloop
	if(fwtp(ii).lt.1.)go to 100
	kk=kk+1
c == experimental psloop_e...
	y(kk)=psloop_e(ii)
ccc	if(abs(y(kk)).gt.psmax)psmax=abs(y(kk))
	sig(kk)=seps1*psmax
c   == plasma to loops...
	y(kk)=y(kk)-psloopp(ii)*api
c   == pf to loops...
	do  k=1,npf
	if(indpf(k).eq.0)then
	fint=pfgreen(ii,k)*pf(k)
	y(kk)=y(kk)-fint*api
	end if
	end do
c   == vessel to loops...
	if(icam.eq.1)then
	DO  K=1,ncam
	fint=vesgreen(ii,k)*tcam(k)
	y(kk)=y(kk)-fint*api
	end do
	end if
c
	do jj=1,ma1
	kjj=jpf(jj)	
c   here we determine A matrix
	fint=pfgreen(ii,kjj)
	amat(kk,jj)=fint*api
	end do
c
100	continue
	if(kpr.eq.1)print *,' kk kloop',kk,kloop
c	if(kpr.eq.1)print *,'psmax=',psmax
c	do i=1,kloop
ccc	sig(i)=seps1*psmax
c	sig(i)=1.
c	end do	
c---------------------------------------------
c	go to 800
c
c   here start probes....
c   == transform to Tesla *0.1
	api=0.1
	do 101 ii=1,kprobe
	if(fwtb(ii).lt.1.0)go to 101
	kk=kk+1
c == experimental bprobe_e...
	y(kk)=bprobe_e(ii)
ccc	if(abs(y(kk)).gt.bsmax)bsmax=abs(y(kk))
	sig(kk)=seps2*bsmax
c   == plasma to loops...
	y(kk)=y(kk)-bprobep(ii)*api
c   == pf to loops...
	do  k=1,npf
	if(indpf(k).eq.0)then
	fint=pfprobe(ii,k)*pf(k)
	y(kk)=y(kk)-fint*api
	end if
	end do
c   == vessel to loops...
	if(icam.eq.1)then
	DO  K=1,ncam
	fint=vesprobe(ii,k)*tcam(k)
	y(kk)=y(kk)-fint*api
	end do
	end if
c
	do jj=1,ma1
	kjj=jpf(jj)	
c   here we determine A matrix
	fint=pfprobe(ii,kjj)
	amat(kk,jj)=fint*api
	end do
c
101	continue
800	continue
	nps=kloop+kprobe
c	if(kpr.eq.1)print *,'bsmax=',bsmax
	do i=kloop+1,nps
ccc	sig(i)=seps1*bsmax
c	sig(i)=1.
	end do	
c---------------------------------------------
c
c
	do k=1,ma1
	kk=kk+1
	kjj=jpf(k)
	y(kk)=pfc(kjj)
	sig(kk)=seps3*pfmax
	amat(kk,k)=1.
	end do
c-----------------------------------
c   here sigmas to ma1 PF-current points (nps+ma1)
c	if(kpr.eq.1)print *,'pfmax=',pfmax
	do i=nps+1,nps+ma1
cccc	sig(i)=seps2*pfmax
c	sig(i)=1.
	end do	
c=====================================================
	namat=nx
	if(kpr.eq.1)print *,' ndata kk',ndata,kk
	ndata=kk
	call svdfit(amat,y,sig,ndata,a,ma,namat)
	apr='pf'
c	if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf)
	do k=1,ma1
	kjj=jpf(k)
c	if(kpr.eq.1)print *,'k jpf pfc a',k,jpf(k),pfc(kjj),a(k)
	pf(kjj)=a(k)
	end do
c
	api=0.1
	kk=0
c	do 102 ii=1,kprobe
c---
c	kk=kk+1
c	y(kk)=bprobe_e(ii)
c---
c	if(fwtb(ii).eq.0)go to 102
c == experimental bprobe_e...
c   == plasma to loops...
c	y(kk)=y(kk)-bprobep(ii)*api
c   == pf to loops...
c	do  k=1,npf
c	fint=pfprobe(ii,k)*pf(k)
c	y(kk)=y(kk)-fint*api
c	end do
c   == vessel to loops...
c	DO  K=1,ncam
c	fint=vesprobe(ii,k)*tcam(k)
c	y(kk)=y(kk)-fint*api
c	end do
cccc	if(kpr.eq.1)print *,' kk fwt bprobe_e yy',kk,fwtb(ii),bprobe_e(ii),y(kk)
c
102	continue
c	pause ' svd'
	return
	end
c
