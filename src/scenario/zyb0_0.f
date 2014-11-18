	subroutine zyb(n,ires)
c-------------------------------------------
c   sawtooth oscilation mixing (Kadomsev model)
c--------------------------------------------
	include 'double.inc'
c       implicit real*8(a-h,o-z)
	include 'parf0'
	common
     *  /en1/PNE(npo),PD0(npo),PT0(npo),PH0(npo),PDN(npo),
     *  PTN(npo),PHN(npo)
     *  /en2/TE0(npo),TQ0(npo),TEN(npo),TQN(npo),WE0(npo),
     *  WQ0(npo)
	common
     *  /DFM2/PSI(npo),PFI(npo),DM0(npo),DMN(npo)
     *  /dfm3/dfmax(npo),dfmax0(npo)
     *  /DFM4/Q(npo),ANU(npo),P(npo),F(npo),
     *  PP(npo),PFF(npo)
	common
     *  /mid2/vi(npo),spo(npo)
	common
     *  /ge3/AI(npo),A0(npo),HA2(npo),a(npo),ha(npo)
     *  /ge5/kpr
     *  /ge6/zeff(npo),qpr(npo),ppr(npo),pr0,prg,zar
	common /eq18/kzybpr
	dimension ps(npo),ps1(npo),h0(npo),po1(npo),po(npo)
c
c       
	character *40 mq

	if(kpr.eq.1)print*,'in zyb before running'
	mq='q '
	if(kpr.eq.1)print 71,mq,(q(i),i=1,n)
	mq='te0 '
       if(kpr.eq.1)print 71,mq,(te0(i),i=1,n)
	mq='tq0 '
       if(kpr.eq.1) print 71,mq,(tq0(i),i=1,n)


	fmax=dfmax(n)
	if(kpr.eq.1)print *,'fmax=',fmax,' [zyb]'
	dm0(1)=dm0(2)-psi(2)*ha(2)
	do i=1,n
	ps(i)=dm0(i)+a(i)*a(i)*fmax
c       ps(i)=dm0(i)+dfmax(i)
	end do
	mq='psi* [zyb]'
	if(kpr.eq.1)print 71,mq,(ps(i),i=1,n)
	psm=ps(1)
	do i=1,n
	if(ps(i).le.psm)then
	psm=ps(i)
	imin=i
	end if
	end do
	ires=-1
	if(imin.lt.3)return
c
	if(kpr.eq.1)print *,'imin psm [zyb]',imin,psm
	do i=imin+1,n
c
	if(ps(i).ge.ps(2))then
c       imax=i-1
	imax=i
	go to 1
	end if
	end do
1       continue
	if(kpr.eq.1)print *,'imax=',imax
c       if(imax.le.imin+1)return
c       do i=4,n
c       if(q(i).lt.q(3))then
c       if(kpr.eq.1)print *,'i q(i) gt q(3)',i,q(3)
c       return
c       end if
c       end do
c
	ires=1
	kzybpr=kzybpr+1
	if(kzybpr.gt.2)then
	if(kpr.eq.1)print *,'____111_____- kzybpr_________',kzybpr
	if(kpr.eq.1)print *,'imin imax',imin,imax
	mq='q [zyb]'
       if(kpr.eq.1) print 71,mq,(q(i),i=1,n)
	mq='ps [zyb]'
       if(kpr.eq.1) print 71,mq,(ps(i),i=1,n)
	mq='dm0 [zyb]'
       if(kpr.eq.1)print 71,mq,(dm0(i),i=1,n)
	mq='psi [zyb]'
       if(kpr.eq.1)print 71,mq,(psi(i),i=1,n)
	end if
71      format(4x,a60/,(8(1pe10.3)))
	j=1
	po1(j)=a(imin-j+1)
	ps1(j)=ps(imin-j+1)
c
c
	do j=2,imin
	po1(j)=a(imin-j+1)
	ps1(j)=ps(imin-j+1)
	end do
	po(1)=0.
	do j=2,imin
	do i=imin,imax
	if(ps(i).le.ps1(j).and.ps1(j).le.ps(i+1))then
	deps=(ps1(j)-ps(i))/(ps(i+1)-ps(i))
	po2=a(i)+deps*(a(i+1)-a(i))
	po(j)=sqrt(po2**2-po1(j)**2)
	end if
	end do
	end do
	do j=2,imin
	h0(j)=po(j)-po(j-1)
	end do

	i_dif=1
	if(i_dif.eq.1)then
c
	dm0(1)=ps1(2)
	do j=2,imin
	do i=2,imax
	if(po(j-1).le.a(i).and.a(I).le.po(j))then
	deps=(a(i)-po(j-1))/h0(j)
	dm0(i)=ps1(j-1)+deps*(ps1(j)-ps1(j-1))-
     *  a(i)*a(i)*fmax
	end if
	end do
	end do

	ii=imax+1

	do i=2,ii
	psi(i)=(dm0(i)-dm0(i-1))/ha(i)
	q(i)=-2.*ai(i)*fmax/psi(i)
	end do

c	do i=2,ii
c	q(i)=q(ii)
c	psi(i)=-2.*ai(i)*fmax/q(i)
c	end do

c	do i=ii,2
c	dm0(i-1)=dm0(i)-psi(i)*ha(i)
c	end do

	i=2
	dh1=2.*ha(i)/(2.*ha(i)+ha(i+1))
	psi(2)=0.5*dh1*psi(3)
	q(2)=q(3)
	q(1)=q(2)
	dm0(1)=dm0(2)-psi(2)*ha(2)
	mq='q new [zyb]'
	if(kpr.eq.1)print 71,mq,(q(i),i=1,n)
	mq='dm0 new [zyb]'
	if(kpr.eq.1)print 71,mq,(dm0(i),i=1,n)
	mq='psi new [zyb]'
	if(kpr.eq.1)print 71,mq,(psi(i),i=1,n)

	end if

c------------------------------------
	eni=0.
	ene=0.
	pav=0.
	vol=0.
c       if(kpr.eq.1)print *,'ii',ii 
	do i=2,ii
	pdc=0.5*(pd0(i)+pd0(i-1))
	ptc=0.5*(pt0(i)+pt0(i-1))
	phc=0.5*(ph0(i)+ph0(i-1))
	dens=(pdc+ptc+phc)*vi(i)*ha(i)
	pavt=pavt+ptc*vi(i)*ha(i)
	pavd=pavd+pdc*vi(i)*ha(i)
	pavh=pavh+phc*vi(i)*ha(i)
	pav=pav+dens
	vol=vol+vi(i)*ha(i)
	eni=eni+dens*0.5*(tq0(I)+tq0(i-1))
	ene=ene+dens*0.5*(te0(I)+te0(i-1))
	end do
	tec=ene/pav
	tqc=eni/pav

	do i=1,ii
	te0(i)=tec
	tq0(i)=tqc
c	te0(i)=0.96*tec
c	tq0(i)=0.96*tqc
	te0(i)=0.99*tec
	tq0(i)=0.99*tqc

cc	ten(i)=0.95*tec
cc	tqn(i)=0.95*tqc
!	ten(i)=0.97*tec
!	tqn(i)=0.97*tqc

c       pd0(i)=pavd/vol
c       pt0(i)=pavt/vol
c       ph0(i)=pavh/vol
	end do
c       if(kpr.eq.1)print *,'i mix [zyb]',ii
c       if(kpr.eq.1)print *,'--tec tqc [zyb]--',tec,tqc
	if(kpr.eq.1)print *,'i mix [zyb]',ii



	mq='te0 new'
       if(kpr.eq.1)print 71,mq,(te0(i),i=1,n)
	mq='tq0 new '
       if(kpr.eq.1) print 71,mq,(tq0(i),i=1,n)


c------------------------------------
	if(kzybpr.gt.2)then
	if(kpr.eq.1)print *,'____222_____- kzybpr_________',kzybpr
	if(kpr.eq.1)print *,'imin imax',imin,imax
	mq='q [zyb]'
       if(kpr.eq.1) print 71,mq,(q(i),i=1,n)
	mq='ps [zyb]'
       if(kpr.eq.1) print 71,mq,(ps(i),i=1,n)
	mq='dm0 [zyb]'
       if(kpr.eq.1)print 71,mq,(dm0(i),i=1,n)
	mq='psi [zyb]'
       if(kpr.eq.1)print 71,mq,(psi(i),i=1,n)
	end if

	if(kpr.eq.1)print*,'after zyb running'
c	read(*,*)

	return
	end



