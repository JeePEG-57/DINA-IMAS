	subroutine pomin_m (pom,tet,m,um,vm,xu,yu,ke,pi)
c----------------------------------------------------------------------
c  calculate distances from plasma centre to limiter POM(j) along J rays
c------------------------------------------------------------------------
	include 'double.inc'
c	implicit real*8(a-h,o-z)
	dimension pom(m),tet(m),xu(ke),yu(ke),xm(100),ym(100)
	character * 20 apr

	common /ge7/eu,rout,zout,elong

71 	FORMAT(20X,A6/,(6(1pE10.3)))
c-------------------------------------
	m1=m-1
c	if(kpr.eq.1)print *,' m m1',m,m1
c	if(kpr.eq.1)print *,' um vm',um,vm
c
	apr='xu'
c	if(kpr.eq.1)print 71,apr,(xu(i),i=1,ke)
	apr='yu'
c	if(kpr.eq.1)print 71,apr,(yu(i),i=1,ke)
c
	tet(1)=tet(2)-tet(3)
	apr='tet'
c	if(kpr.eq.1)print 71,apr,(tet(i),i=1,m)
c	if(kpr.eq.1)print *,' m===',m
c
	do j=1,m
	pom(j)=2.e5
	end do

	eu_r=0.1*eu
c
	do ii=2,m1

	rt=um+eu_r*cos(tet(ii))
	zt=vm+eu_r*sin(tet(ii))
c
	k=0
c
	do 30 i=2,ke
c
	call SEC(r,z,xu(i),Xu(i-1),Yu(i),yu(i-1),rt,Um,zt,Vm)

	if(r.gt.0.)then

	d1=sqrt( (xu(i)-r)**2+(yu(i)-z)**2)
	d2=sqrt( (xu(i-1)-r)**2+(yu(i-1)-z)**2)
	d3=sqrt( (xu(i)-xu(i-1) )**2+(yu(i)-yu(i-1) )**2)
	d12=d1+d2
c	if(kpr.eq.1)print *,' i d1+d2 d3',i,d12,d3
	if( abs(d3-d12).lt.0.01)then
	k=k+1
	xm(k)=r
	ym(k)=z
c	if(kpr.eq.1)print *,' i r z rt zt ',i,r,z,rt,zt
c	if(kpr.eq.1)print *,' i xu xu_ yu yu_r  ',i,xu(i),xu(i-1),yu(i),yu(i-1)
	end if
c
	end if

30	continue
c	if(kpr.eq.1)print *,' k= 1 =x y ',k,(xm(i),ym(i),i=1,k)
	np=k
	k=0
	do i=1,np
	d1=sqrt((rt-um)**2+(zt-vm)**2)
	d2=sqrt( (xm(i)-rt)**2+(ym(i)-zt)**2)
	d3=sqrt( (xm(i)-um)**2+(ym(i)-vm)**2)
	d12=d1+d2
	if(abs( d3-(d1+d2) ).lt.0.01)then
	k=k+1
	xm(k)=xm(i)
	ym(k)=ym(i)
	end if
	end do
c	if(kpr.eq.1)print *,' k= 2 =',k
	np=k
	k_1=0
	do i=1,np
c  ab is vector scalar product---
	ab=-1.
        ab=(xm(i)-um)*(rt-um)+(ym(i)-vm)*(zt-vm) 
	if(ab.gt.0.)then
c	if(kpr.eq.1)print *,' i d1+d2 d3',i,d12,d3
	k_1=k_1+1
	d1=sqrt( (xm(i)-um)**2+(ym(i)-vm)**2 )
	pom(ii)=amin1(pom(ii),d1)
	end if
	end do
c
c	if(kpr.eq.1)print *,' ii k k_1 pom(ii)',ii,k,k_1,pom(ii)

c--- end ii loop--
	end do
c
	pom(1)=pom(m1)
	pom(m)=pom(2)

	apr='pom'
c	if(kpr.eq.1)print 71,apr,(pom(i),i=1,m)
c	if(kpr.eq.1)print *,' pausa'
c	read (*,*)
c
	return
	end
	subroutine pomin_mo (pom,tet,m,um,vm,xu,yu,ke,pi)
c----------------------------------------------------------------------
c  calculate distances from plasma centre to limiter POM(j) along J rays
c------------------------------------------------------------------------
	include 'double.inc'
c	implicit real*8(a-h,o-z)
	dimension pom(m),tet(m),xu(ke),yu(ke)
	character * 20 apr
71 	FORMAT(20X,A6/,(6(1pE10.3)))
c-------------------------------------
	m1=m-1
c	if(kpr.eq.1)print *,' m m1',m,m1
c	if(kpr.eq.1)print *,' um vm',um,vm
c
	apr='xu'
c	if(kpr.eq.1)print 71,apr,(xu(i),i=1,ke)
	apr='yu'
c	if(kpr.eq.1)print 71,apr,(yu(i),i=1,ke)
c	pause 'from pomin_mo'
c
	tet(1)=tet(2)-tet(3)
	apr='tet'
c	if(kpr.eq.1)print 71,apr,(tet(i),i=1,m)
c	if(kpr.eq.1)print *,' m===',m
c
	do j=1,m
	pom(j)=2.e5
	end do
c
c
	i=0
	d=sqrt((xu(i+1)-um)**2+(yu(i+1)-vm)**2)
	cos1=(xu(i+1)-um)/d
	sin1=(yu(i+1)-vm)/d
	alfa1=acos(cos1)
	if(sin1.lt.0.)alfa1=2.*pi-alfa1
c
	do  i=1,ke-1
	d=sqrt((xu(i+1)-um)**2+(yu(i+1)-vm)**2)
	alfa0=alfa1
	cos1=(xu(i+1)-um)/d
	sin1=(yu(i+1)-vm)/d
	alfa1=acos(cos1)
	if(sin1.lt.0.)alfa1=2.*pi-alfa1
cc	if(kpr.eq.1)print *,' i alfa0 alfa1',i,alfa0,alfa1,pi
c
	alfmin=alfa0
	alfmax=alfa1
	i_min=i
	i_max=i+1
	if(alfa0.gt.alfa1)then
	alfmin=alfa1
	alfmax=alfa0
	i_min=i+1
	i_max=i
	end if
	if(alfa0.gt.alfa1.and.alfa0-alfa1.gt.pi)then
	alfmin=alfa0
	alfmax=alfa1+2.*pi
	i_min=i
	i_max=i+1
	end if
	if(alfa1.gt.alfa0.and.alfa1-alfa0.gt.pi)then
	alfmin=alfa1
	alfmax=alfa0+2.*pi
	i_min=i+1
	i_max=i
	end if
c	if(kpr.eq.1)print *,' i alfmin alfmax ',i,alfmin,alfmax
c
c	if(alfmax.gt.2.*pi)then
c	alfmax=alfmax-2.*pi
c	alfmin=alfmin-2.*pi
c	end if
c
c	if(kpr.eq.1)print *,' i_f alfmin alfmax ',i,alfmin,alfmax
c------------
c	if(kpr.eq.1)print *,' i_min i_max',i_min,i_max
c
c
	do 30 j=1,m
	if( (alfmin-tet(j) )*(alfmax-tet(j) ).gt.0.) go to 30	
	r=xu(i_min)+(tet(j)-alfmin)*(xu(i_max)-xu(i_min))/(alfmax-alfmin)
	z=yu(i_min)+(tet(j)-alfmin)*(yu(i_max)-yu(i_min))/(alfmax-alfmin)
c
	d=sqrt((r-um)**2+(z-vm)**2)
c
	if( d.le.pom(j) )pom(j)=d
c	if(kpr.eq.1)print*,'j pom',j,pom(j)
30	continue
c
	if(alfmax.gt.2.*pi)then
	alfmax=alfmax-2.*pi
	alfmin=alfmin-2.*pi
c
cc	if(kpr.eq.1)print *,' i_s alfmin alfmax ',i,alfmin,alfmax
c
	do 31 j=1,m
	if( (alfmin-tet(j) )*(alfmax-tet(j) ).gt.0.) go to 31	
	r=xu(i_min)+(tet(j)-alfmin)*(xu(i_max)-xu(i_min))/(alfmax-alfmin)
	z=yu(i_min)+(tet(j)-alfmin)*(yu(i_max)-yu(i_min))/(alfmax-alfmin)
	d=sqrt((r-um)**2+(z-vm)**2)
c
	if( d.le.pom(j) )pom(j)=d
c	if(kpr.eq.1)print*,'j pom',j,pom(j)
31	continue
	end if

c	if(kpr.eq.1)print *,' pausa'
c	read (*,*)
c
	end do
c
	if(abs(pom(2)).gt.1.e+5) pom(2)=pom(m)
	if(abs(pom(m)).gt.1.e+5) pom(m)=pom(2)
c
	if(abs(pom(1)).gt.1.e+5) pom(1)=pom(m1)
	if(abs(pom(m1)).gt.1.e+5) pom(m1)=pom(1)
c
	apr='pom'
c	if(kpr.eq.1)print 71,apr,(pom(i),i=1,m)
c	if(kpr.eq.1)print *,' pausa'
c	read (*,*)
c
	return
	end




