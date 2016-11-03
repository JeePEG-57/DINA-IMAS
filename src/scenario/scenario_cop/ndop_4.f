	subroutine caet2(um,vm,rt,zt,ita,ke,xu,yu)
c----------------------------------------------------------------------
c  calculate is point inside vessel
c------------------------------------------------------------------------
	include 'double.inc'
c	implicit real*8(a-h,o-z)
        common
     *  /ge5/kpr
	dimension  xu(ke),yu(ke),xm(500),ym(500)
71 	FORMAT(20X,A6/,(12E10.3))
c
	ita=0
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
c	if(kpr.eq.1)print *,' k==',k
	np=k
	k=0
	do i=1,np
	d1=sqrt( (xm(i)-um)**2+(ym(i)-vm)**2)
	d2=sqrt( (xm(i)-rt)**2+(ym(i)-zt)**2)
	d3=sqrt((rt-um)**2+(zt-vm)**2)
	d12=d1+d2
	if(abs( d3-(d1+d2) ).lt.0.01)then
	k=k+1
c	if(kpr.eq.1)print *,' i k d1+d2 d3',i,k,d12,d3

	xm(k)=xm(i)
	ym(k)=ym(i)

	end if
	end do
c
	k_1=0
	np=k
	do i=1,np
	do j=1,np
	dist=sqrt( (xm(i)-xm(j))**2+(ym(i)-ym(j))**2)
	if(i.ne.j.and.dist.le.0.01)then
	k_1=k_1+1
c	if(kpr.eq.1)print *,' the same points'
c	if(kpr.eq.1)print *,' k_1 k i j xm(i),xm(j) ym(i) ym(j)',k_1,k,i,j,
c     *  xm(i),xm(j),ym(i),ym(j)
c	if(kpr.eq.1)print *,' enter ===='
c	read (*,*)
	end if
	end do
	end do

	k=k-k_1

c	if(kpr.eq.1)print *,' k====',k
cc	if(k.eq.2*(k/2).and.k.ne.0)ita=1
	if(k.eq.2*(k/2))ita=1
c	if(kpr.eq.1)print *,' enter ===='
c	read (*,*)
	return
	end
c
c-------------
	subroutine test_pr(xp,yp,n,k)
	include 'double.inc'
	dimension xp(n),yp(n)
	k_t=k
	do i=1,k-1
	dist=sqrt( (xp(i)-xp(k))**2+(yp(i)-yp(k))**2 )
	if(dist.le.0.01) k_t=k_t-1
	end do
	k=k_t
	return
	end

	subroutine fluxcont(n,m,PSI,aval,x,y,
     *	xp1,yp1,num,ind1,delta0,dacur)
	include 'double.inc'
c	implicit real *8 (a-h,o-z)
        common
     *  /ge5/kpr

c	parameter (mu1=400)
!	parameter (mu1=800)
	parameter (mu1=2000)

	dimension xp1(50,mu1),yp1(50,mu1),ind1(50),ind(mu1)
	DIMENSION psi(n,m),x(n),y(m),xp(mu1),yp(mu1),index(mu1)
	CHARACTER*10 MPR
c
	n1=n-1
	m1=m-1
	k=0
c
	do j=1,m
	do i=1,n
	if(psi(i,j).eq.aval)then
	k=k+1
	xp(k)=x(i)
	yp(k)=y(j)
	call test_pr(xp,yp,mu1,k)
	end if
	end do
	end do
c
	do j=1,m
	do i=1,n1
	if( (aval-psi(i+1,j))*(aval-psi(i,j)).ge.0.)go to 11
	if(abs(psi(i,j)-aval).le.dacur*abs(aval) ) then
	k=k+1
	yp(k)=y(j)
	xp(k)=x(i)
	call test_pr(xp,yp,mu1,k)
	go to 11
	end if
	if(abs(psi(i+1,j)-aval).le.dacur*abs(aval) ) then
	k=k+1
	yp(k)=y(j)
	xp(k)=x(i+1)
	call test_pr(xp,yp,mu1,k)
	go to 11
	end if
c
	if( (i-1)*(i-n1).lt.0) then
	k=k+1
	yp(k)=y(j)
	xp(k)=x(i)
	call fit(2,x(i-1),x(i),x(i+1),x(i+2),psi(i-1,j),
     *  psi(i,j),psi(i+1,j),psi(i+2,j),xp(k),aval,yq)
	call test_pr(xp,yp,mu1,k)
	end if
c
	if( i.eq.1) then
	k=k+1
	yp(k)=y(j)
	xp(k)=x(i)
	call fit(2,x(i),x(i+1),x(i+2),x(i+3),psi(i,j),
     *  psi(i+1,j),psi(i+2,j),psi(i+3,j),xp(k),aval,yq)
	call test_pr(xp,yp,mu1,k)
	end if
c
	if( i.eq.n1) then
	k=k+1
	yp(k)=y(j)
	xp(k)=x(i)
	call fit(2,x(i-2),x(i-1),x(i),x(i+1),psi(i-2,j),
     *  psi(i-1,j),psi(i,j),psi(i+1,j),xp(k),aval,yq)
	call test_pr(xp,yp,mu1,k)
	end if
c
11	continue
	end do
	end do
c
	do i=1,n
	do j=1,m1
	if( (aval-psi(i,j+1))*(aval-psi(i,j)).ge.0.)go to 12
	if(abs(psi(i,j)-aval).le.dacur*abs(aval) ) then
	k=k+1
	yp(k)=y(j)
	xp(k)=x(i)
	call test_pr(xp,yp,mu1,k)
	go to 12
	end if
	if(abs(psi(i,j+1)-aval).le.dacur*abs(aval) ) then
	k=k+1
	yp(k)=y(j+1)
	xp(k)=x(i)
	call test_pr(xp,yp,mu1,k)
	go to 12
	end if
c
	if( (j-1)*(j-m1).lt.0) then
	k=k+1
	yp(k)=y(j)
	xp(k)=x(i)
	call fit(2,y(j-1),y(j),y(j+1),y(j+2),psi(i,j-1),
     *  psi(i,j),psi(i,j+1),psi(i,j+2),yp(k),aval,xq)
	call test_pr(xp,yp,mu1,k)
	end if
c
	if( j.eq.1) then
	k=k+1
	yp(k)=y(j)
	xp(k)=x(i)
	call fit(2,y(j),y(j+1),y(j+2),y(j+3),psi(i,j),
     *  psi(i,j+1),psi(i,j+2),psi(i,j+3),yp(k),aval,xq)
	call test_pr(xp,yp,mu1,k)
	end if
c
	if( j.eq.m1) then
	k=k+1
	yp(k)=y(j)
	xp(k)=x(i)
	call fit(2,y(j-2),y(j-1),y(j),y(j+1),psi(i,j-2),
     *  psi(i,j-1),psi(i,j),psi(i,j+1),yp(k),aval,xq)
	call test_pr(xp,yp,mu1,k)
	end if
c
12	continue
	end do
	end do

	MPR='xp'
c	IF(KPR.EQ.1)PRINT 71,MPR,(xp(I),I=1,k)
	MPR='yp'
c	IF(KPR.EQ.1)PRINT 71,MPR,(yp(I),I=1,k)

	if(k.gt.mu1)then
	if(kpr.eq.1)print *,' --- k GT MU1 ------------',k,mu1
	stop
	end if

	call sort(k,xp,yp,xp1,yp1,ind,num,ind1,delta0)
c
71	FORMAT(20X,A10/,(6(1x,1PE10.3)))
	return
	end
	subroutine feet(n,PSI8,aval8,x8,xp8)
c	subroutine feet(n,PSI8,aval8,x8,xp8,jpr)
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	dimension psi8(n),x8(n),xp8(n)
        common
     *  /ge5/kpr
	parameter (n4=1000)
	DIMENSION psi(n4),x(n4),xp(n4)
	character *16 apr
	do i=1,n
	psi(i)=psi8(i)
	x(i)=x8(i)
	end do
	aval=aval8
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))
c
	n1=n-1
	k=0
c
	do i=1,n
	if(psi(i).eq.aval)then
	k=k+1
	xp(k)=x(i)
	xp8(k)=xp(k)
c	if(jpr.eq.1)if(kpr.eq.1)print *,'exact k i x ',k,i,xp8(k)
	return
	end if
	end do
c
	do i=1,n1
	if( (aval-psi(i+1))*(aval-psi(i)).ge.0.)go to 11
	if(abs(psi(i)-aval).le.1.e-7*abs(aval) ) then
	k=k+1
	xp(k)=x(i)
	xp8(k)=xp(k)
c	if(jpr.eq.1)if(kpr.eq.1)print *,'k i xp8',k,i,xp8(k)
	return
c	if(kpr.eq.1)print *,'xp==* i *',xp(k)
	go to 11
	end if
	if(abs(psi(i+1)-aval).le.1.e-7*abs(aval) ) then
	k=k+1
	xp(k)=x(i+1)
	xp8(k)=xp(k)
c	if(jpr.eq.1)print *,'k i xp8',k,i,xp8(k)
	return
c	if(kpr.eq.1)print *,'xp==* i+1 *',xp(k)
	go to 11
	end if
c
	if( (i-1)*(i-n1).lt.0) then
	k=k+1
c	if(jpr.eq.1)then
c	if(kpr.eq.1)print *,'k i',k,i
c	apr='xii'
c	if(kpr.eq.1)print 71,apr,(x(ij),ij=i-1,i+2)
c	end if
	xp(k)=x(i)
	call fit(2,x(i-1),x(i),x(i+1),x(i+2),psi(i-1),
     *  psi(i),psi(i+1),psi(i+2),xp(k),aval,yq)
	xp8(k)=xp(k)
c	if(jpr.eq.1)print *,'k i xp8',k,i,xp8(k)
	return
	end if
c
	if( i.eq.1) then
	k=k+1
c	if(jpr.eq.1)then
c	if(kpr.eq.1)print *,'k i',k,i
c	apr='xii'
c	if(kpr.eq.1)print 71,apr,(x(ij),ij=i-1,i+2)
c	end if
c	if(kpr.eq.1)print *,'k i',k,i
	xp(k)=x(i)
	call fit(2,x(i),x(i+1),x(i+2),x(i+3),psi(i),
     *  psi(i+1),psi(i+2),psi(i+3),xp(k),aval,yq)
	xp8(k)=xp(k)
c	if(jpr.eq.1)print *,'k i xp8',k,i,xp8(k)
	return
	end if
c
	if( i.eq.n1) then
	k=k+1
c	if(jpr.eq.1)then
c	if(kpr.eq.1)print *,'k i',k,i
c	apr='xii'
c	if(kpr.eq.1)print 71,apr,(x(ij),ij=i-1,i+2)
c	end if
c	if(kpr.eq.1)print *,'k i',k,i
	xp(k)=x(i)
	call fit(2,x(i-2),x(i-1),x(i),x(i+1),psi(i-2),
     *  psi(i-1),psi(i),psi(i+1),xp(k),aval,yq)
	xp8(k)=xp(k)
c	if(jpr.eq.1)print *,'k i xp8',k,i,xp8(k)
	end if
c
11	continue
	end do
	return
	end
	subroutine sort(k,xp,yp,xp1,yp1,ind,num,ind1,delta0)
	include 'double.inc'
c       implicit real *8 (a-h,o-z)
c	parameter (mu1=400)
	parameter (mu1=800)
	dimension xp(mu1),yp(mu1),xp1(50,mu1),yp1(50,mu1),
     *	ind1(50),ind(mu1)
        common
     *  /ge5/kpr
	common
     *  /point1/r0,z0
c
	ki=0
c   here we adjust 1 point
	deltamin=1.e10
	do i=1,k
	delta=sqrt( (xp(i)-r0)**2+(yp(i)-z0)**2 )
	if(delta.le.deltamin)then
	deltamin=delta
	kj=i
	end if
	end do
c
	num=1
	do i=1,k
	ind(i)=0
	end do
c
c
10      ki=ki+1
c       if(kpr.eq.1)print *,'num ki',num,ki
c       if(kpr.eq.1)print *,'kj xp yp',kj,xp(kj),yp(kj)
c
	xp1(num,ki)=xp(kj)
	yp1(num,ki)=yp(kj)
	ind(kj)=1
c
	deltamin=1.e10
	do 2 j=1,k
	if(ind(j).eq.1)go to 2
	delta=sqrt( (xp(j)-xp1(num,ki))**2+(yp(j)-yp1(num,ki))**2 )
	if(delta.le.deltamin)then
	deltamin=delta
	kj=j
	end if
2       continue
	if(deltamin.le.delta0)go to 10
c_______________________________________________
	ind1(num)=ki
c
c
100     continue
	deltamin=1.e10
	do 22 j=1,k
	if(ind(j).eq.1)go to 22
	delta=sqrt( (xp(j)-xp1(num,1))**2+(yp(j)-yp1(num,1))**2 )
	if(delta.le.deltamin)then
	deltamin=delta
	kj=j
	end if
22      continue
	if(deltamin.le.delta0)then
	ki=ki+1
	do i0=2,ki
	i=ki-i0+2
	xp1(num,i)=xp1(num,i-1)
	yp1(num,i)=yp1(num,i-1)
	end do
c       if(kpr.eq.1)print *,'* kj* xp yp',kj,xp(kj),yp(kj)
	xp1(num,1)=xp(kj)
	yp1(num,1)=yp(kj)
	ind(kj)=1
	ind1(num)=ki
	go to 100
	end if
c_______________________________________________
c       array is reodered
	do i=2,ki-1
	xvec0=xp1(num,i)-xp1(num,i-1)
	yvec0=yp1(num,i)-yp1(num,i-1)
c
	xvec=xp1(num,i+1)-xp1(num,i)
	yvec=yp1(num,i+1)-yp1(num,i)
c
	p=xvec*xvec0+yvec*yvec0
c       if(kpr.eq.1)print *,'i p==',i,p
c
	if(p.lt.0.)then
	xhelp=xp1(num,i)
	yhelp=yp1(num,i)
	xp1(num,i)=xp1(num,i-1)
	yp1(num,i)=yp1(num,i-1)
c
	xp1(num,i-1)=xhelp
	yp1(num,i-1)=yhelp
	end if
c
	end do
c__________________________________________________
	do j=1,k
	if(ind(j).eq.0)then
	num=num+1
	ki=0
	kj=j
	go to 10
	end if
	end do
c
c	return
c
	do i=1,num
	delta=sqrt( ( xp1(i,1)-xp1(i,ind1(i)) )**2+
     *  ( yp1(i,1)-yp1(i,ind1(i)) )**2 )
	if(delta.le.delta0)then
	ind1(i)=ind1(i)+1
	xp1(i,ind1(i))=xp1(i,1)
	yp1(i,ind1(i))=yp1(i,1)
	end if
	end do
c
c
c       if(kpr.eq.1)print *,'num==',num
c       if(kpr.eq.1)print *,'ind1==',(ind1(i),i=1,num)
	return
	end
      subroutine SEC(X,Y,x1,X2,Y1,y2,U1,U2,V1,V2)

	include 'double.inc'
	common
     *  /ge5/kpr
      real *8 a1,b1,c1,a2,b2,c2,del
c----------------------------------------------------
cc calculate intersection of two lines
c-----------------------------------------------
c	implicit real*8 (a-h,o-z)
	kv=1
	ky=1
	ku=1
	kx=1
	if(abs(v2-v1).lt.1.e-13)then
	a1=0.
	b1=1.
	c1=v1
	kv=0
	end if
c
	if(abs(u2-u1).lt.1.e-13)then
	a1=1.
	b1=0.
	c1=u1
	ku=0
	end if
c
	if(abs(y2-y1).lt.1.e-13)then
	a2=0.
	b2=1.
	c2=y1
	ky=0
	end if
c
	if(abs(x2-x1).lt.1.e-13)then
	a2=1.
	b2=0.
	c2=x1
	kx=0
	end if
c
	if(ku.eq.1.and.kv.eq.1)then
	a1=1./(u2-u1)
	b1=-1./(v2-v1)
	c1=a1*u1+b1*v1
	end if
c
	if(kx.eq.1.and.ky.eq.1)then
	a2=1./(x2-x1)
	b2=-1./(y2-y1)
	c2=a2*x1+b2*y1
	end if
	if(ku.eq.0.and.kx.eq.0)then
	x=1000.
	y=1000.
	return
	end if
c
	if(kv.eq.0.and.ky.eq.0)then
	x=1000.
	y=1000.
	return
	end if
c
c	if(kpr.eq.1)print*,'a1 a2',a1,a2
c	if(kpr.eq.1)print*,'b1 b2',b1,b2
c	if(kpr.eq.1)print*,'c1 c2',c1,c2
	del=a1*b2-a2*b1
	x=(c1*b2-b1*c2)/del
	y=(a1*c2-c1*a2)/del
c	if(kpr.eq.1)print*,'x y',x,y
	return
	end
c
	subroutine separatrix1 (i1,i2,i3,m,uk,vk,um,vm,pom,
     *  sinus,cosin,pocoef,psep,rsep,zsep,isep,ksep,kc)
c---------------------------------------------------------
c  calculate separatrix or limiter fluxes and  their coordinates
c-------------------------------------------------------------------
c
	include 'double.inc'
	common
     *  /ge5/kpr
	dimension uk(m),vk(m),pom(m),sinus(m),cosin(m)
	dimension pdd(6)
c
	p_min=psep
c
	do  900 i0=i1,i2
	i=i0+i3-i1
	if(i.gt.i2)i=i-i2+1
c
	ps=1.e19
c
	po=sqrt((uk(i)-um)**2+(vk(i)-vm)**2)
c
	dpo=pocoef
c
	poi=0.9*po
	re=um+poi*cosin(i)
	ze=vm+poi*sinus(i)
	poi=poi-dpo
901	continue
	poi=poi+dpo
	klm=0
	if(poi.ge.pom(i))then
	poi=pom(i)
	klm=1
c	if(kpr.eq.1)print*,'*** klm  **',klm
	end if
c
	re_0=re
	ze_0=ze
c
	re=um+poi*cosin(i)
	ze=vm+poi*sinus(i)
c
	call boxdl(fint,re,ze)
c
	ps_0=ps
        ps=fint
c
	if(ps.gt.ps_0)klm=0
	if(klm.eq.1)go to 61
	if(ps.lt.p_min)go to 900
	if(ps.lt.ps_0)go to 901
c   loop in i_th ray -901 -
	re=re_0
	ze=ze_0
	ps=ps_0
	p_min=ps
	rsep=re
	zsep=ze
	isep=i
	ksep=1
	psep=p_min
	go to 900
61	continue
c
	if(ps.ge.p_min)then
	p_min=ps
	rsep=re
	zsep=ze
	isep=i
	ksep=-1
	psep=p_min
	end if
900	continue
	return
	end

	subroutine boxdl(fint,urr,vrr)
c
	include 'double.inc'
	include 'parf2'
c
	common
     *  /eq1/psi(nr,nz),pspl(nr,nz),x(nr),y(nz),dx,dy


c  starting calculate flux
c
c Locate the grid square, zero-based.
	ri= (URR-x(1))/dx
	zj= (VRR-y(1))/dy
c Get t and u
	ii=aint(ri)
	jj=aint(zj)
	tt=ri-ii
	uu=zj-jj
c	type *,'i,j,t,u',i,j,t,u
c Convert to 1-base arrays
	ii=ii+1
	jj=jj+1
c Calculate the 4 coefficients.
	c00=(1.-tt)*(1.-uu)
	c10=tt*(1.-uu)
	c01=(1.-tt)*uu
	c11=tt*uu
c Loop through the coils.
	fint=c00*psi(ii,jj) + c10*psi(ii+1,jj) +
     *  c01*psi(ii,jj+1)+ c11*psi(ii+1,jj+1)
C
	return
	end



	subroutine fdd_filter()
	include 'double.inc'
	include 'new_com.inc'

      if(kpr.eq.1)write(6,'(" 00 tt tay fdd taup  ", 6(1pe12.5))'),
     *  tt,tay,fdd,tau_p


	call fdd_filter_c(
     *  fdd,ntay,tay,tt,tau_p)




	return
	end

	subroutine fdd_filter_c(
     *  fdd,ntay,tay,tt,tau_p)

	include 'double.inc'
	common
     *  /ge5/kpr


	if(time.lt.tt-0.5*tay)then
c  saving for the next time_step...
	e1 = f9a
	v1 = f9af
	time1 = time
	end if


	time=tt

	f9a=fdd

        i_en=i_en+1
	if(i_en.eq.1)then
           e1 = f9a
           f9af=e1
           v1 = f9af
           time1 = time
        end if

c	qqp = 0.5 * 5.0e-5 * (time - time1)*1.e3

c!!!	qqp = 0.5 * 5.0e-2 * (time - time1)
c    ;  /* 1/taup = 1/20.0e3 = 5.0e-5 */
c	qqp = 0.5 * 5.0e-2 * (time - time1)

c    ;  /* 1/taup = 1/20.0 = 5.0e-2 */
c    ;  /* 1/taup = 1/0.5 = 2. */
      if(taup.le.tay)then
      taup=tay
      else
	taup=tay_p
	end if
	
	
	qqp = 0.5 * (time - time1)/taup

c    ;  /* 1/taup = 1/1. = 1. */

	f9af =(qqp * (f9a + e1) - (qqp - 1.0) * v1) / (qqp + 1.0)

c	if(kpr.eq.1)print *,' qqp e1 v1 ----',qqp,e1,v1
c	if(kpr.eq.1)print *,'   f9a f9af----',f9a,f9af

	fdd=f9af

      if(kpr.eq.1)write(6,'(" tt tay fdd taup  ", 6(1pe12.5))'),
     *  tt,tay,fdd,taup


	return
	end

	subroutine udd_filter()
	include 'double.inc'
	include 'new_com.inc'

	call udd_filter_c(
     *  udd,ntay,tay,tt)

	return
	end

	subroutine udd_filter_c(
     *  udd,ntay,tay,tt)

	include 'double.inc'
	common
     *  /ge5/kpr
c	if(kpr.eq.1)print *,' tt tay udd----',tt,tay,udd

	if(time.lt.tt-0.5*tay)then
c  saving for the next time_step...
	e1 = f9a
	v1 = f9af
	time1 = time
	end if


	time=tt

	f9a=udd

        i_en=i_en+1
	if(i_en.eq.1)then
           e1 = f9a
           f9af=e1
           v1 = f9af
           time1 = time
        end if

c	qqp = 0.5 * 5.0e-5 * (time - time1)*1.e3

c!!!	qqp = 0.5 * 5.0e-2 * (time - time1)
c    ;  /* 1/taup = 1/20.0e3 = 5.0e-5 */
c	qqp = 0.5 * 5.0e-2 * (time - time1)

c    ;  /* 1/taup = 1/20.0 = 5.0e-2 */
c    ;  /* 1/taup = 1/0.5 = 2. */

	taup=5.*tay
	qqp = 0.5 * (time - time1)/taup

c    ;  /* 1/taup = 1/1. = 1. */

	f9af =(qqp * (f9a + e1) - (qqp - 1.0) * v1) / (qqp + 1.0)

c	if(kpr.eq.1)print *,' qqp e1 v1 ----',qqp,e1,v1
c	if(kpr.eq.1)print *,'   f9a f9af----',f9a,f9af

	udd=f9af


	return
	end

	subroutine tri_sq(r_1,z_1,r_2,z_2,r_3,z_3,s_123)

	include 'double.inc'
	s_123=0.5*abs( (r_1-r_3)*(z_2-z_3)-(r_2-r_3)*(z_1-z_3))

	

	return
	end


                                                                        
	subroutine map_ps()
	include 'double.inc'
	include 'new_com.inc'                                           

	call map_ps_c(     
     *  n,psval,ppx,pffx,                           
     *  k_map,                                                       
     *  kpr)                                                            
                                                                        
	return       
	end                                                                    


	subroutine map_ps_c(    
     *  n,psval,ppx,pffx,                           
     *  k_map,                                                       
     *  kpr)                                                            
        include 'double.inc'  
        dimension psval(*),ppx(*),pffx(*)	


        include 'parf0'  
        dimension poax(npo),ppx_w(npo),pffx_w(npo)                  
        character * 20 apr                                                 

      do i=1,n
	ppx_w(i)=ppx(i)
	pffx_w(i)=pffx(i)
	end do

	k_map=0                                                            
                                                                        
          poax(n)=1.d0
                                                                        
         do i=2,n                                                       
                                                                        
          psix=(psval(i)-psval(1))/(psval(n)-psval(1))                
                                                                        
		poax(i)=psix            
	    psix=sqrt(psix)                                        
                                                                         
	    call fit_pp_pff(psix,pprime,fprime)                                
	    pffx(i)=fprime                                                     
	    ppx(i)=pprime                                                      
	                                                                       
         end do                                                         
                                                                        
	 ppx(1)=ppx(2)                                                         
	 pffx(1)=pffx(2)    
	                                                    
	apr='-psval-'                                                            
c	print 71,apr,(psval(i),i=1,n)                               
  	apr='-poax-'                       
c 	print 71,apr,(poax(i),i=1,n)                               
                                                                       
!	 call map()                                                            
	 call map_kav()                                                            
                                                                        
	 call eq_res_ps()   

      do i=1,n
	ppx(i)=ppx_w(i)
	pffx(i)=pffx_w(i)
	end do
                                                                   
                                                                        
71	FORMAT(20X,A8/,(6(1X,1PE11.4)))
                                                                        
         return                                                         
         end                                                            
	subroutine eq_res_ps()
	include 'double.inc'
	include 'new_com.inc'                                                  
                                                                        
	call eq_res_ps_c(                                                       
     *  n,mp,npo,                                                       
     *  xpl,ypl,x_map,y_map,                                            
     *  rmag,zmag,ro,uk,vk,                                           
     *  kpr,cosin,sinus)                                                            
                                                                        
	return                                                                 
	end                                                                    
                                                                        
                                                                        
	subroutine eq_res_ps_c(                                                 
     *  n,mp,npo,                                                       
     *  xpl,ypl,x_map,y_map, 
     *  um,vm,ro,uk,vk,                                           
     *  kpr,cosin,sinus) 
                                                                
      include 'double.inc'                                                       
c------------                                                           
	dimension 
     *  xpl(npo,*),ypl(npo,*),x_map(npo,*),y_map(npo,*),
     *  ro(npo,*),uk(*),vk(*),cosin(*),sinus(*)
                                                                        
	character *12 apr                                                      




	errp=0.
	do i=1,n                                                               
	do j=1,mp                                                              
	err=dabs(ypl(i,j)-y_map(i,j))
!	errp=dmax1(err,errp) 
	if(err.gt.errp)then
c	print *,' i j err y ',i,j,err,ypl(i,j),y_map(i,j)
	errp=err
	end if


	err=dabs(xpl(i,j)-x_map(i,j))
!	errp=dmax1(err,errp) 
	if(err.gt.errp)then
c	print *,' i j err ',i,j,err
	errp=err
	end if


	end do                                                                 
	end do                                                                

	errp_in=errp

	i=n
	do j=1,mp                                                              
	uk(j)=x_map(i,j)                                                    
	vk(j)=y_map(i,j)                                                    
	end do                                                                 

                                                                        
	do i=1,n                                                               
	do j=1,mp                                                              
	xpl(i,j)=x_map(i,j)                                                    
	ypl(i,j)=y_map(i,j)                                                    
	end do                                                                 
	end do                                                                


	um=xpl(1,1)
	vm=ypl(1,1)


	errp=0.
	do i=1,n                                                               
	do j=1,mp                                                              
	rox=( (xpl(i,j)-um)**2+(ypl(i,j)-vm)**2 )                                                    
	roy=( (uk(j)-um)**2+(vk(j)-vm)**2 )                                                    
	ro(i,j)=dsqrt( rox/roy )
	ypl(i,j)=vm+ro(i,j)*(vk(j)-vm)                                         
	err=dabs(ypl(i,j)-y_map(i,j))
!	errp=dmax1(err,errp) 
	if(err.gt.errp)then
c	print *,' i j err ',i,j,err
	errp=err
	end if

	end do                                                                 
	end do                                                                

	i_test=0
	if(i_test.eq.1)then
	errp=0.
	do j=1,mp                                                              
	err=dabs(1.-(cosin(j)**2+sinus(j)**2) )
!	errp=dmax1(err,errp) 
	if(err.gt.errp)then
	if(kpr.eq.1)print *,' j err ',j,err
	errp=err
	end if

	end do                                                                 
                                                        
	end if

	if(kpr.eq.1)print *,' n mp errp : eq_res_ps==',n,mp,errp
	if(kpr.eq.1)print *,' um vm errp_in ==',um,vm,errp_in
	 
c	apr='-pff-'                                                            
c	if(kpr.eq.1)print 71,apr,(pff(i),i=1,n)                               
                                                                        
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))                                      
c                                                                       
                                                                        
	return                                                                 
	end                                                                    
