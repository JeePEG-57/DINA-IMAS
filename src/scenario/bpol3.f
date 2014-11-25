!Эта подпрограмма для вычисления полей Br, Bz от катушки прямоугольного сечения с единичным током в точках rp, zp.
!Входные данные: 
!r1 - радиальная координата центра катушки,
!z1 - вертикальная координата центра катушки,
!dr - радиальный размер катушки,
!dz - вертикальный размер катушки,
!Выходные данные: 
!brs - радиальное поле в точке rp,zp,
!bzs - вертикальное поле в точке rp,zp.



        subroutine bpol3(r1,z1,dr,dz,rp,zp,brs,bzs)

!        real*8 r1,z1,dr,dz,rp,zp,brs,bzs

c        real*8 abr,abz,sr,sz,s1r,s1z,sa,sb,pi2,hi,sfr,sfz,fpi(51),
c     >  dcs,dsn
        include 'double.inc'
        
	dimension tet(6,5),aa(6,5)
        dimension fpi(51)
	data tet/-.57735,.57735,4*0.,
     ,	-.774597,0.,.774597,3*0.,
     ,	-.861136,-.339981,.339981,.861136,2*0.,
     ,	-.90618,-.538469,0.,.538469,.90618,0.,
     ,	-.93247,-.6612094,-.2386192,.2386192,.6612094,.93247/,
     ,	aa/2*1.,4*0.,
     ,	.555556,.888889,.555556,3*0.,
     ,	.347855,.652145,.652145,.347855,2*0.,
     ,	.236927,.478629,.568889,.478629,.236927,0.,
     ,	.1713245,.3607616,.4679139,.4679139,.3607616,.1713245/

c	data ng/50000/,ngg/6/,eps/1d-4/

        data ng/30/,ngg/6/,eps/1d-4/
c     >	,fpi/0d0, 1d-5, 1d-4, 1d-3, 2.5d-3, 5d-3, 7.5d-3, 1d-2,
c     >      43*0d0/
     >	,fpi/0d0, 1d-4, 1d-3, 2.5d-3, 5d-3, 7.5d-3, 1d-2, 5d-2,
     >      43*0d0/

        pi2=asin(1d0)*2d0
c        pi2=3.14159265359d0

c        do i=1,ng
c        fpi(i)=(i-1)*pi2/ng
c        enddo


c	 write(6,'(" r1,z1,dr,dz,rp,zp  ", 5(1pe13.6))'),
c     *  r1,z1,dr,dz,rp,zp


        do i=9,ng
        fpi(i)=fpi(8)+(i-8)*(pi2-fpi(8))/(ng-7)
        enddo
        fpi(ng+1)=pi2

        r2i=r1+dr*.5
        r1i=r1-dr*.5
        zneg=zp-z1-dz*.5
        zpos=zp-z1+dz*.5

        sr=0d0
        sz=0d0

	if(abs(r2i-rp) .lt. eps .and. abs(zneg) .lt. eps) then
        sr=-8d0*r2i/3d0+r2i*(pi2*alog(dble(r2i))+0.58214d0)
        sz=-r2i*pi2
	endif
	
	if(abs(r2i-rp) .lt. eps .and. abs(zpos) .lt. eps) then
        sr= 8d0*r2i/3d0-r2i*(pi2*alog(dble(r2i))+0.58214d0)
        sz= r2i*pi2
	endif
	
	if(abs(r1i-rp) .lt. eps .and. abs(zneg) .lt. eps) then
        sr= 8d0*r1i/3d0-r1i*(pi2*alog(dble(r1i))+0.58214d0)
        sz= r1i*pi2
	endif
	
	if(abs(r1i-rp) .lt. eps .and. abs(zpos) .lt. eps) then
        sr=-8d0*r1i/3d0+r1i*(pi2*alog(dble(r1i))+0.58214d0)
        sz=-r1i*pi2
	endif
	
	do 5 i1=1,ng
c	do 5 i1=1,ng+1

	sb=(fpi(i1+1)-fpi(i1))*.5d0
	sa=sb+fpi(i1)
        s1r=0.
        s1z=0.

	do 10 i=1,ngg
	hi=sb*tet(i,ngg-1)+sa

        dcs=cos(hi)
        dsn=sin(hi)
        sfr=abr(r2i,r1i,rp,zneg,zpos,dcs,eps)
        sfz=abz(r2i,r1i,rp,zneg,zpos,dcs,dsn,eps)

        s1r=s1r+sb*sfr*aa(i,ngg-1)
10      s1z=s1z+sb*sfz*aa(i,ngg-1)

cc	s1=abr(r2i,r1i,rp,zneg,zpos,fpi(i1),eps)*fpi(2)
cc	if(i1 .eq. 1 .or. i1 .eq. ng+1) s1=s1/2d0

        sr=sr+s1r
        sz=sz+s1z
5	continue

        brs=sr*1e-7/dr/dz
        bzs=sz*1e-7/dr/dz

	return
	end

        real*8 function abr(r2,r1,rp,zp1,zp2,dcs,eps)
        include 'double.inc'
ccc        implicit real*8 (a-h,o-z)
        common/p1/r1zp1,r1zp2,r2zp1,r2zp2
ccc        real*4 r2,r1,rp,zp1,zp2,eps

	if(abs(r2-rp) .lt. eps .and. abs(zp1) .lt. eps) then
        r1zp1=abr2(r1,rp,zp1,dcs)
        r2zp2=abr2(r2,rp,zp2,dcs)
        r1zp2=abr2(r1,rp,zp2,dcs)
        abr= 
     >  -abr1(r1,rp,zp1,dcs)
     >  -r1zp1*2d0*rp*dcs*dcs
     >  -abr1(r2,rp,zp2,dcs)
     >  +abr1(r1,rp,zp2,dcs)
     >  -r2zp2*2d0*rp*dcs*dcs
     >  +r1zp2*2d0*rp*dcs*dcs
        return
	endif
	if(abs(r2-rp) .lt. eps .and. abs(zp2) .lt. eps) then
        r2zp1=abr2(r2,rp,zp1,dcs)
        r1zp1=abr2(r1,rp,zp1,dcs)
        r1zp2=abr2(r1,rp,zp2,dcs)
        abr= abr1(r2,rp,zp1,dcs)
     >  -abr1(r1,rp,zp1,dcs)
     >  +r2zp1*2d0*rp*dcs*dcs
     >  -r1zp1*2d0*rp*dcs*dcs
     >  +abr1(r1,rp,zp2,dcs)
     >  +r1zp2*2d0*rp*dcs*dcs
        return
	endif
	if(abs(r1-rp) .lt. eps .and. abs(zp1) .lt. eps) then
        r2zp1=abr2(r2,rp,zp1,dcs)
        r2zp2=abr2(r2,rp,zp2,dcs)
        r1zp2=abr2(r1,rp,zp2,dcs)
        abr= abr1(r2,rp,zp1,dcs)
     >  +r2zp1*2d0*rp*dcs*dcs
     >  -abr1(r2,rp,zp2,dcs)
     >  +abr1(r1,rp,zp2,dcs)
     >  -r2zp2*2d0*rp*dcs*dcs
     >  +r1zp2*2d0*rp*dcs*dcs
        return
	endif
	if(abs(r1-rp) .lt. eps .and. abs(zp2) .lt. eps) then
        r2zp1=abr2(r2,rp,zp1,dcs)
        r1zp1=abr2(r1,rp,zp1,dcs)
        r2zp2=abr2(r2,rp,zp2,dcs)
        abr= abr1(r2,rp,zp1,dcs)
     >  -abr1(r1,rp,zp1,dcs)
     >  +r2zp1*2d0*rp*dcs*dcs
     >  -r1zp1*2d0*rp*dcs*dcs
     >  -abr1(r2,rp,zp2,dcs)
     >  -r2zp2*2d0*rp*dcs*dcs
        return
	endif

        r2zp1=abr2(r2,rp,zp1,dcs)
        r1zp2=abr2(r1,rp,zp2,dcs)
        r1zp1=abr2(r1,rp,zp1,dcs)
        r2zp2=abr2(r2,rp,zp2,dcs)
        abr= abr1(r2,rp,zp1,dcs)
     >  -abr1(r1,rp,zp1,dcs)
     >  +r2zp1*2d0*rp*dcs*dcs
     >  -r1zp1*2d0*rp*dcs*dcs
     >  -abr1(r2,rp,zp2,dcs)
     >  +abr1(r1,rp,zp2,dcs)
     >  -r2zp2*2d0*rp*dcs*dcs
     >  +r1zp2*2d0*rp*dcs*dcs

        return
        end

        real*8 function abr1(r2,rp,zp,dcs)
        include 'double.inc'
ccc        implicit real*8 (a-h,o-z)
ccc        real*4 r2,rp,zp

        abr1=2d0*dcs*sqrt(r2**2-2d0*r2*rp*dcs+rp**2+zp**2)

        return
        end

        real*8 function abr2(r2,rp,zp,dcs)
        include 'double.inc'
ccccc        implicit real*8 (a-h,o-z)
ccccc        real*4 r2,rp,zp

c        abr2=2d0*rp*dcs**2*
c     >  dlog(dabs(r2-rp*dcs+dsqrt(r2**2-2d0*r2*rp*dcs+rp**2+zp**2)))
        abr2=
     >   dlog(abs(r2-rp*dcs+sqrt(r2**2-2d0*r2*rp*dcs+rp**2+zp**2)))

        return
        end

        real*8 function abz(r2,r1,rp,zp1,zp2,dcs,dsn,eps)
        include 'double.inc'
ccc        implicit real*8 (a-h,o-z)
        common/p1/r1zp1,r1zp2,r2zp1,r2zp2
ccc        real*4 r2,r1,rp,zp1,zp2,eps

	if(abs(r2-rp) .lt. eps .and. abs(zp1) .lt. eps) then
        abz= r2zp2*2d0*zp2
     >  -abz2(r2,rp,zp2,dcs)
     >  -abz3(r2,rp,zp2,dcs,dsn)
cc     >  -abz1(r2,rp,zp1,dcs)
     >  +abz3(r2,rp,zp1,dcs,dsn)
cc     >  +abz1(r1,rp,zp1,dcs)
     >  -abz2(r1,rp,zp1,dcs)
     >  -abz3(r1,rp,zp1,dcs,dsn)
     >  -r1zp2*2d0*zp2
     >  +abz2(r1,rp,zp2,dcs)
     >  +abz3(r1,rp,zp2,dcs,dsn)
        return
	endif
	if(abs(r2-rp) .lt. eps .and. abs(zp2) .lt. eps) then
        abz=
cc     >   abz1(r2,rp,zp2,dcs)
     >  -abz3(r2,rp,zp2,dcs,dsn)
     >  -r2zp1*2d0*zp1
     >  +abz2(r2,rp,zp1,dcs)
     >  +abz3(r2,rp,zp1,dcs,dsn)
cc     >  -abz1(r1,rp,zp2,dcs)
     >  +abz2(r1,rp,zp2,dcs)
     >  +abz3(r1,rp,zp2,dcs,dsn)
     >  +r1zp1*2d0*zp1
     >  -abz2(r1,rp,zp1,dcs)
     >  -abz3(r1,rp,zp1,dcs,dsn)
        return
	endif
	if(abs(r1-rp) .lt. eps .and. abs(zp1) .lt. eps) then
        abz= r2zp2*2d0*zp2
     >  -abz2(r2,rp,zp2,dcs)
     >  -abz3(r2,rp,zp2,dcs,dsn)
cc     >  -abz1(r2,rp,zp1,dcs)
     >  +abz2(r2,rp,zp1,dcs)
     >  +abz3(r2,rp,zp1,dcs,dsn)
     >  -r1zp2*2d0*zp2
     >  +abz2(r1,rp,zp2,dcs)
     >  +abz3(r1,rp,zp2,dcs,dsn)
cc     >  +abz1(r1,rp,zp1,dcs)
     >  -abz3(r1,rp,zp1,dcs,dsn)
        return
	endif
	if(abs(r1-rp) .lt. eps .and. abs(zp2) .lt. eps) then
        abz=
cc     >   abz1(r2,rp,zp2,dcs)
     >  -abz2(r2,rp,zp2,dcs)
     >  -abz3(r2,rp,zp2,dcs,dsn)
     >  -r2zp1*2d0*zp1
     >  +abz2(r2,rp,zp1,dcs)
     >  +abz3(r2,rp,zp1,dcs,dsn)
cc     >  -abz1(r1,rp,zp2,dcs)
     >  +abz3(r1,rp,zp2,dcs,dsn)
     >  +r1zp1*2d0*zp1
     >  -abz2(r1,rp,zp1,dcs)
     >  -abz3(r1,rp,zp1,dcs,dsn)
        return
	endif

        abz= 2d0*zp2*r2zp2
     >  -abz2(r2,rp,zp2,dcs)
     >  -abz3(r2,rp,zp2,dcs,dsn)
     >  -2d0*zp1*r2zp1
     >  +abz2(r2,rp,zp1,dcs)
     >  +abz3(r2,rp,zp1,dcs,dsn)
     >  -2d0*zp2*r1zp2
     >  +abz2(r1,rp,zp2,dcs)
     >  +abz3(r1,rp,zp2,dcs,dsn)
     >  +2d0*zp1*r1zp1
     >  -abz2(r1,rp,zp1,dcs)
     >  -abz3(r1,rp,zp1,dcs,dsn)

        return
        end

c        real*8 function abz1(r2,rp,zp,dcs)
c        implicit real*8 (a-h,o-z)
c        real*4 r2,rp,zp

c	if(dabs(zp) .lt. 1e-4) then
c	abz1=0d0
c	else
c	abz1=2d0*zp*
c     >  dlog(dabs(r2-rp*dcs+dsqrt(r2**2-2d0*r2*rp*dcs+rp**2+zp**2)))
c	endif

c        return
c        end

        real*8 function abz2(r2,rp,zp,dcs)
        include 'double.inc'
ccccc        implicit real*8 (a-h,o-z)
ccccc        real*4 r2,rp,zp

        abz2=2d0*rp*dcs*
     >  alog(abs(zp+sqrt(r2**2-2d0*r2*rp*dcs+rp**2+zp**2)))

        return
        end

        real*8 function abz3(r2,rp,zp,dcs,dsn)
        include 'double.inc'
ccccc        implicit real*8 (a-h,o-z)
ccccc        real*4 r2,rp,zp

c	if(dabs(dsn) .lt. 1d-3) then
c	abz3=0d0
c	else
	a2=r2-rp*dcs
	b2=sqrt(r2**2-2d0*r2*rp*dcs+rp**2)
	b2z=sqrt(b2**2+zp**2)
c	x=(a2*b2z+b2**2)/(a2*b2+b2*b2z)
	x=(a2*b2z/b2+b2)/(a2+b2z)
	if(abs(x) .gt. 1d0) x=sign(1d0,x)
	if(zp .gt. 0d0) then
        abz3=2d0*rp*dsn*asin(x)
        else
        abz3=-2d0*rp*dsn*asin(x)
        endif
c        endif

        return
        end

