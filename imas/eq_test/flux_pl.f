	subroutine flux_pl(fpl,r,z,nrad,mplasma)
        include 'double.inc'
	include 'parf0'
c	implicit real *8 (a-h,o-z)
	dimension pdd(6),psc(12)
        dimension dpd(8)
c-------------------
        common/inte3/pa(4),qa(4),qda(4),ain(4),dpsda,
     *	rin(4,4),zin(4,4),
     *  tin(4),papt(4,4),pt(4)
c-----------------------------
	common/bo1/ rbo1(ntet,3),zbo1(ntet,3),dpsdn(ntet,3)
	common
     *  /ge1/pi
     *  /ge3/AI(npo),A0(npo),HA2(npo),a1(npo),ha(npo)
     *  /ge5/kpr
        common
     *  /eq4/xpl(npo,ntet),ypl(npo,ntet)
     *  /eq7e/tet(ntet)
	common
     *  /pol4/UM,VM,UK(ntet),VK(ntet)
     *  /pol5/psend
	common
     *  /dfm5/PT01,PT02
	common/nrad/n4,n5
c--------------------------------------
	jbound=mplasma-1
c--------------------------
	n4=nrad-4
	rt=r
	zt=z
c-------------------
	do i=1,4
	ain(i)=a1(n4+i)
	end do
	awant=1.
	call thir(pa,ain)
	call abat3(qa,qda,ain,awant)

	dpsda=psend/(2.*pi)
c	if(kpr.eq.1)print *,'RT ZT',rt,zt
c	if(kpr.eq.1)print *,'dpsda nrad jbound',dpsda,nrad,jbound
	ako=sqrt(rt)/pi
	do i=1,4
	xpl(n4+i,1)=xpl(n4+i,jbound)
	ypl(n4+i,1)=ypl(n4+i,jbound)

	xpl(n4+i,mplasma)=xpl(n4+i,2)
	ypl(n4+i,mplasma)=ypl(n4+i,2)

	xpl(n4+i,mplasma+1)=xpl(n4+i,3)
	ypl(n4+i,mplasma+1)=ypl(n4+i,3)
	end do

	tet(mplasma+1)=tet(mplasma)+(tet(3)-tet(2))
	tet(mplasma+1)=tet(mplasma)+(tet(3)-tet(2))
c	if(kpr.eq.1)print *,' tet 1 2...',tet(1),tet(2)
c	if(kpr.eq.1)print *,' tet jbound mplasma mplasma+1',
c     *	tet(jbound),tet(mplasma),tet(mplasma+1)
c	read (*,*)


	j=1
	r2=uk(j)
	z2=vk(j)
	fpl=0.
	i=1
	do j=2,jbound

	r1=r2
	z1=z2
	r2=uk(j)
	z2=vk(j)
	call prel3(j)
c	if(kpr.eq.1)print *,' call prel3 j ',j

	rj12=(r2+r1)/2.
	zj12=(z2+z1)/2.
	a=-(z1-z2)
	b=-(r2-r1)
	amode=sqrt(a*a+b*b)
	er=-a/amode
	ez=-b/amode
	teta=0.5*( tin(2)+tin(3) )

	call grad3(dpd,teta)
c	if(kpr.eq.1)print *,' call grad3 dpd2 dpd3 teta',dpd(2),dpd(3),teta
c----------------------------------------------------
	dpsdn(j,i)=dpd(2)*er+dpd(3)*ez
c-----------------------------------
c	if(kpr.eq.1)print *,' rt r1 r2',rt,r1,r2
c	if(kpr.eq.1)print *,' zt z1 z2',zt,z1,z2

c	call boxi(rt,r1,r2,zt,z1,z2,psc)

	dpnor=dpsdn(j,i)
c	if(kpr.eq.1)print *,'  dpnor===',dpnor
c	fpl1=psc(1)*dpnor*ako
	fpl2=dpnor*amode/rj12*fp(rt,rj12,zt,zj12)
	fpl=fpl+fpl2
c	if(kpr.eq.1)print *,' fpl fpl2',fpl,fpl2
c	read (*,*)
	end do
	return
	end

	subroutine thir(p4,tin)
        include 'double.inc'
c	implicit real *8 (a-h,o-z)
	dimension p4(4),tin(4),x(4,4)
	do i=1,4
	do j=i+1,4
	x(i,j)=tin(i)-tin(j)
	end do
	end do
	p4(1)=x(1,2)*x(1,3)*x(1,4)
	p4(2)=-x(1,2)*x(2,3)*x(2,4)
	p4(3)=x(1,3)*x(2,3)*x(3,4)
	p4(4)=-x(1,4)*x(2,4)*x(3,4)
33	format (3x,5e12.5)
	return
	end
	subroutine frz3(r,z,rin,zin,tin,teta,p3)
        include 'double.inc'
c	implicit real *8 (a-h,o-z)
	dimension p3(4),tin(4),x(4),rin(4,4),zin(4,4),q(4)
	do i=1,4
	x(i)=teta-tin(i)
	end do
	s12=x(1)*x(2)
	s13=x(1)*x(3)
	s14=x(1)*x(4)
	s23=x(2)*x(3)
	s24=x(2)*x(4)
	s34=x(3)*x(4)
	q(1)=x(2)*s34
	q(2)=x(1)*s34
	q(3)=s12*x(4)
	q(4)=s12*x(3)
c	if(kpr.eq.1)print 34,s123,x(5)
c	if(kpr.eq.1)print 34,q
	r=0.
	z=0.
	do i=1,4
	coe=q(i)/p3(i)
	r=r+coe*rin(4,i)
	z=z+coe*zin(4,i)
	end do
34	format(3x,7e11.3)
	return
	end
c
	subroutine prel3(jt)
        include 'double.inc'
	include 'parf0'
c	implicit real *8 (a-h,o-z)
c__________________________________________
	common
     *  /eq4/xpl(npo,ntet),ypl(npo,ntet)
cccc     *  /eq7/tet(ntet),ht(ntet)
     *  /eq7e/tet(ntet)
	common/nrad/n4,n5
c-------------------
        common/inte3/pa(4),qa(4),qda(4),ain(4),dpsda,
     *	rin(4,4),zin(4,4),
     *  tin(4),papt(4,4),pt(4)
c-----------------------------
	common
     *  /ge1/pi

c----
	do j=1,4
	do i=1,4
	rin(i,j)=xpl(n4+i,jt-2+j)
	zin(i,j)=ypl(n4+i,jt-2+j)
	end do
	tin(j)=tet(jt-2+j)
	end do
4	continue
	call thir(pt,tin)
	do i=1,4
	do j=1,4
	papt(i,j)=pa(i)*pt(j)
	end do
	end do
33	format (3x,5e12.5)
	return
	end
	subroutine grad3(dpd,teta)
	include 'double.inc'
c	implicit real *8 (a-h,o-z)
        common/inte3/pa(4),qa(4),qda(4),ain(4),dpsda,
     *	rin(4,4),zin(4,4),
     *  tin(4),papt(4,4),pt(4)

	dimension qt(4),qdt(4),dpd(8)
	call abat3(qt,qdt,tin,teta)
	drda=0.
	dzda=0.
	do i=1,4
	do j=1,4
	coe=qda(i)*qt(j)/papt(i,j)
	drda=drda+coe*rin(i,j)
	dzda=dzda+coe*zin(i,j)
	end do
	end do
	drdt=0.
	dzdt=0.
	do i=1,4
	do j=1,4
	coe=qa(i)*qdt(j)/papt(i,j)
	drdt=drdt+coe*rin(i,j)
	dzdt=dzdt+coe*zin(i,j)
	end do
	end do
c	if(kpr.eq.1)print 33,drda,dzda
c	if(kpr.eq.1)print 33,drdt,dzdt
	yak=drda*dzdt-dzda*drdt
	dadz=-drdt/yak
	dadr=dzdt/yak
	dpd(2)=dpsda*dadr
	dpd(3)=dpsda*dadz
33	format (3x,5e12.5)
	return
	end
c
	subroutine abat3(q,qd,tin,teta)
	include 'double.inc'
c	implicit real *8 (a-h,o-z)
	dimension q(4),qd(4),tin(4),x(4)
	do i=1,4
	x(i)=teta-tin(i)
	end do
	s12=x(1)*x(2)
	s13=x(1)*x(3)
	s14=x(1)*x(4)
	s23=x(2)*x(3)
	s24=x(2)*x(4)
	s34=x(3)*x(4)
	qd(1)=s34+s23+s24
	qd(2)=s34+s13+s14
	qd(3)=s24+s12+s14
	qd(4)=s23+s12+s13
	q(1)=x(2)*s34
	q(2)=x(1)*s34
	q(3)=s12*x(4)
	q(4)=s12*x(3)
c	if(kpr.eq.1)print 34,s123,x(5)
c	if(kpr.eq.1)print 34,q
34	format(3x,7e11.3)
	return
	end
c




