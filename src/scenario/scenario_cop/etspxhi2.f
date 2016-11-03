	subroutine edim1
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	parameter(np=50001)
	common/eldim/ n1,eki(np),eei(np)
	n=np-1
	n1=n-1
	do i=1,n1
	x=(i-1.)/n1
	call elke(x,ellick,ellice)
	eki(i)=ellick
	eei(i)=ellice
	end do
	eki(n)=eki(n-1)
	eei(n)=eei(n-1)
	eki(n+1)=eki(n-1)
	eei(n+1)=eei(n-1)
	return
	end

	subroutine ellip(x,ek,ee)
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	parameter(np=50001)
	common/eldim/ n1,eki(np),eei(np)
	y=1.+x*n1
	ie=int(y)
	ek=(y-ie)*(eki(ie+1)-eki(ie))+eki(ie)
	ee=(y-ie)*(eei(ie+1)-eei(ie))+eei(ie)
	return
	end

	subroutine elke(x,ellick,ellice)
 	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	t=1.d0-x*x
	dd=dlog(t)
	ellice=((4.0905094d-2*t+8.5099193d-2)*t+0.44479204d0)*t+
     *  1.d0-dd*(((1.382999d-2*t+8.150224d-2)*t+0.24969795d0)*t)
	ellick=((3.2024666d-2*t+5.4544409d-2)*t+9.7932891d-2)*t+
     *  1.3862944d0-dd*(((1.0944912d-2*t+6.0118519d-2)*t+
     *  0.12475074d0)*t+0.5d0)
	return
	end


      FUNCTION FP(R,R1,Z,Z1)
 	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	common
     *  /ge1/pi
     *  /ge2/NTAY,TAY,TT


	if(ntay.gt.ntay1)i_en=0
	ntay1=ntay

	if(ntay.gt.10)then
	k_el=1
	else
	k_el=0
	end if


	aaa=0.5d0
c
	RR=R+R1
	ZZ=Z-Z1
	R0=R*R1
      GK=4.d0*R0/(RR*RR+ZZ*ZZ)

!	if(kpr.eq.1)print *,' r r1 z z1 ',r,r1,z,z1
      GK=dSQRT(GK)

	dist=dsqrt( (r-r1)**2+(z-z1)**2 )

	if(dist.le.0.5*aaa.or.k_el.eq.1)then
c	   if(kpr.eq.1)print *,' FP DIST===',dist
	   CALL ellip(GK,YK,YE)
	else

	i_en=i_en+1
      if(i_en.le.2.and.kpr.eq.1)print *,' ntay FP DIST===',ntay,dist

	   CALL elke(GK,YK,YE)
	end if

      GREEN=0.8d0*pi/GK*SQRT(R0)*((1.d0-GK*GK*0.5d0)*YK-YE)
      FP=GREEN
      RETURN
      END


      FUNCTION FP_old(R,R1,Z,Z1)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	common
     *  /ge1/pi
c
	RR=R+R1
	ZZ=Z-Z1
	R0=R*R1
      GK=4.*R0/(RR*RR+ZZ*ZZ)
      GK=SQRT(GK)
	CALL ellip(GK,YK,YE)
c       CALL elke(GK,YK,YE)
      GREEN=0.8*pi/GK*SQRT(R0)*((1.-GK*GK*0.5)*YK-YE)
      FP_old=GREEN
      RETURN
      END
      SUBROUTINE BRZ(BR,BZ,R,R1,Z,Z1)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
c
	zz1=z-z1
	zz2=zz1*zz1
	rr2=(r+r1)**2
	rr1=(r-r1)**2
	r12=r1*r1
	r2=r*r
	rz=rr2+zz2
	rz1=rr1+zz2
	sr1=sqrt(rz)
      GK=4.*R*R1/rz
      GK=SQRT(GK)
	CALL ellip(GK,YK,YE)
c       CALL elke(GK,YK,YE)
      BR=0.2*zz1/(R*sr1)*(-YK+YE*(R12+R2
     *+zz2)/rz1)
      BZ=0.2/sr1*(YK+YE*(R12-R2-ZZ2)/
     *rz1)
      RETURN
      END
      SUBROUTINE ARZ(AR,AZ,R,R1,Z,Z1,rs0,coef)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
c
	zz1=z-z1
	zz2=zz1*zz1
	rr2=(r+r1)**2
	rr1=(r-r1)**2
	r12=r1*r1
	r2=r*r
	rz=rr2+zz2
	rz1=rr1+zz2
	sr1=sqrt(rz)
      GK=4.*R*R1/rz
      GK=SQRT(GK)
	CALL ellip(GK,YK,YE)
c       CALL elke(GK,YK,YE)
      AR=0.2*zz1/(R*sr1)*(-YK+YE*(R12+R2
     *+zz2)/rz1)
      AZ=0.2/sr1*(YK+YE*(R12-R2-ZZ2)/
     *rz1)
c
	AR=AR*rs0/R1*coef
	AZ=AZ*rs0/R1*coef
      RETURN
      END
        FUNCTION FPp10(x,x1,y,y1)
c The fast Greens function routine.  Note the use of ASF statements.
c The coefficients are presented to this precision so that
c conversion to double precision is easy.  I don't really
c believe all those digits are significant, but at least the
c first 14 or so should be.
	include 'double.inc'
	common/kfp/kfp

        REAL *8 MU0,K,K2,LAMBDA
        PARAMETER (PI=3.1415926535, TWOPI=2.*PI, FOURPI=4.*PI,
     +             MU0=FOURPI*0.1)


c To see how well fortran compiles ASF statements, write a simple
c subroutine that takes one argument x and returns g1(x).
c Compile it /list/mach to get the machine code.  It will be about 30 lines
c of vax Macro.  Note the use of register arithmetic and in-line operands.

	r=x
	rprime=x1
	z=y
	zprime=y1
	kfp=kfp+1

        K2=4.*R*RPRIME/((R+RPRIME)**2+(Z-ZPRIME)**2)
        K=SQRT(K2)

c        if (k .eq. 1.) gpsi=mu0*r*((1.+radc**2/(8*r**2))
c     1    *log(8*r/radc)+(radc**2)/(24.*r**2) - 1.75)
c
c        if (k .ne. 1.)
	if(k2.ge.1.)print*,'k2',k2
        FPp10=MU0*SQRT(R*RPRIME)*g1(K2)/K
        RETURN
        END
	function g1(u)
	include 'double.inc'

        p1(x)=  -0.6137056388799999873E+00 +          (
     1        0.5964550039823199590E+00 +        (
     2        0.7352340966463088989E-02 +     (
     3       -0.2182110771536827087E-01 +  (
     4        0.1720747072249650955E-01 +
     5        0.1451196242123842239E-01 *  x)*x)*x)*x)*x


c That was c1.  Now c2
        p2(x)=  0.5000000000000000000E+00 +            (
     1       0.1250185668468475342E+00 +          (
     2       0.9784810245037078857E-02 +       (
     3       0.2069208770990371704E-01 +    (
     4       0.2717243134975433350E-01 +
     5       0.4417870193719863892E-02 *   x)*x)*x)*x)*x

        g1=p1(1.-u)-p2(1.-u)*log(1.-u)
	return
	end







