      subroutine congig_calc()
       
	include 'parf1'
	include 'double.inc'
	common
     *  /ge1/pi
     *  /ge5/kpr
     *  /c_ves4/r_ves(nmax,mu),z_ves(nmax,mu),a_ves(nmax,mu),
     *  turn_ves(nmax,mu)
     *  /ves7/n_div

      kpr=0

	arg=1.d0

	pi=4.d0*datan(ARG)

	call edim1

       if(kpr.eq.1)print *,' CALL ELKE...'

      call config_coor()

	call cam_ves()

	   call imas_loops()
	   if(kpr.eq.1)print *,' loopdat_ves'
	   call imas_probes()
	   if(kpr.eq.1)print *,' probepdat_ves'

      call zero_ves()
      call pfind_pf()
     	call flat_write()
      

	if(kpr.eq.1)print *,' press ENTER'

!	read (*,*)


!	stop
	return
	end
	
	subroutine cam_ves()
	include 'double.inc'
c-----------------------------------------
c  calculate vessel resistance, vessel mutuals, vessel-PF
c  mutuals...
c---------------------------------------
c	implicit real*8 (a-h,o-z)
	include 'parf1'
	include 'parf4'
c
	common
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves3/b(mu,mu),pmj(mu,mu)
     *  /ves5/pfc(mu,kf)

     *  /c_ves3/nmx_ves(mu)
     *  /c_ves4/r_ves(nmax,mu),z_ves(nmax,mu),a_ves(nmax,mu),
     *  turn_ves(nmax,mu)

	common
     *  /ge1/pi
     *  /ge5/kpr
	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf3/nmx(kf),turn(kf)
     *  /pf4/rvert(kf),svert(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)
     *  /pf9/zvert(kf)
c
	dimension a(mu,mu),d(mu,mu),ppm(mu),ed(mu,mu),
     *  urr(100,mu),vrr(100,mu),avert(100,mu)
c
	dimension f(mu),f_help(mu)

	character *8 apr
c
      PSF(X,hr,hz)=4.*PI/10.*X*(dlog(16.*X/SQRT(HZ**2+HR**2))
     *-0.5-0.5*(HR/HZ*DATAN(HZ/HR)+HZ/HR*DATAN(HR/HZ)))
      PSF1(X,y)=4.d0*PI/10.d0*X*(dlog(8.d0*X/y)-1.5d0)

c--------------------------------------------
c calculate vessel mutuals --- pmj...


	do i=1,ncam
	   do j=1,ncam
	      pmj(i,j)=0.
	   end do
	end do

	do i=1,ncam
	   do j=1,ncam
	      f_help(j)=0.
	   end do

	 n_div=nmx_ves(i)

       do ii=1,n_div
c	call is1(f,rc(i),zc(i))
	      call is_ves(f,r_ves(ii,i),z_ves(ii,i))
	      do j=1,ncam
      		 f_help(j)=f_help(j)+f(j)/n_div
	      end do
       end do
	   
	 do j=1,ncam
	      pmj(i,j)=f_help(j)
	 end do
	apr='f_help'
c	if(kpr.eq.1)print 71,apr,(f_help(j),j=1,ncam)
	end do

	if(kpr.eq.1)print *,' PMJ Mutuals o-kay'

c calculate vessel to PF mutuals --- pfc...


	do i=1,ncam
	   do j=1,npf
	      f_help(j)=0.
	   end do
	n_div=nmx_ves(i)
	   do ii=1,n_div
c	call is1(f,rc(i),zc(i))
	      call is1(f,r_ves(ii,i),z_ves(ii,i))
	      do j=1,npf
	    	 f_help(j)=f_help(j)+f(j)/n_div
	      end do
	   end do
	   
	   do j=1,npf
	      pfc(i,j)=f_help(j)
	   end do
	apr='f_help'
c	if(kpr.eq.1)print 71,apr,(f_help(j),j=1,npf)
	end do

	if(kpr.eq.1)print *,' PFC Mutuals o-kay'

71	format(20x,a6/,(6(1x,1pe10.3)))
c----
	return
	end
c
	subroutine edim1
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	parameter(np=50001)
	common/eldim/ n1,eki(np),eei(np)
	n=np-1
	n1=n-1

	do i=1,n1
	x=dfloat(i-1)/dfloat(n1)

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
	y=1.d0+x*n1
	ie=int(y)
	ek=(y-ie)*(eki(ie+1)-eki(ie))+eki(ie)
	ee=(y-ie)*(eei(ie+1)-eei(ie))+eei(ie)
	return
	end
	subroutine ellipd(x,ek,ee)
	include 'double.inc'
	real * 8 x,ek,ee

c	implicit real*8 (a-h,o-z)
	parameter(np=50001)
	common/eldim/ n1,eki(np),eei(np)
	y=1.+x*n1
	ie=int(y)
	ek=(y-ie)*(eki(ie+1)-eki(ie))+eki(ie)
	ee=(y-ie)*(eei(ie+1)-eei(ie))+eei(ie)
	return
	end

      SUBROUTINE IS_VES(F,R,Z)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	include 'parf1'
	common
     *	/ge1/pi
      COMMON
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves2e/dl(mu),hl(mu)

     *  /c_ves3/nmx_ves(mu)
     *  /c_ves4/r_ves(nmax,mu),z_ves(nmax,mu),a_ves(nmax,mu),
     *  turn_ves(nmax,mu)
c
	dimension f(*)

!      PSF1(X,y)=4.*PI/10.*X*(dlog(8.*X/y)-2.)

      PSF(X,hr,hz)=4.*PI/10.*X*(dlog(16.*X/SQRT(HZ**2+HR**2))
     *-0.5-0.5*(HR/HZ*DATAN(HZ/HR)+HZ/HR*DATAN(HR/HZ)))

      PSF1(X,y)=4.*PI/10.*X*(dlog(8.*X/y)-1.5)
c
	do i=1,ncam
	f(i)=0.
	end do

	do i=1,ncam
!	if(kpr.eq.1)print *,' i nmx turn ===',i,nmx_ves(i),turn_ves(1,i)
	do j=1,NMX_ves(i)

	dist=sqrt((r_ves(j,i)-r)**2+((z_ves(j,i)-z)**2))

	igreen=1
	if(dist.le.0.01)then
	igreen=0
c	   if(kpr.eq.1)print *,' i j dist ',i,j,dist
c	   if(kpr.eq.1)print *,' urr1 urr2 vrr1 vrr2 ',r_ves(j,i),r,
c     *   r_ves(j,i),z
	end if


!	if(igreen.eq.0)fgreen=psf1(r_ves(j,i),a_ves(j,i))
	if(igreen.eq.0)then
!	hr=sqrt(pi)*a_ves(j,i)
	hr=dsqrt(a_ves(j,i))
	hz=hr
	fgreen=psf(r_ves(j,i),hr,hz)
	end if
	if(igreen.eq.1)fgreen=FP(R_ves(j,I),R,Z_ves(j,I),Z)

      F(i)=F(i)+turn_ves(j,i)*fgreen
	end do
	end do

      RETURN
      END
      SUBROUTINE BISA_ves(BRR,BZZ,R,Z)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	include 'parf1'
      COMMON
     *  /ves2/ncam,rc(mu),zc(mu)

     *  /c_ves3/nmx_ves(mu)
     *  /c_ves4/r_ves(nmax,mu),z_ves(nmax,mu),a_ves(nmax,mu),
     *  turn_ves(nmax,mu)

	DIMENSION BRR(*),BZZ(*)
c
      DO  I=1,ncam
	BRR(I)=0.
	BZZ(I)=0.
	do j=1,NMX_ves(i)
      CALL BRZ(BR0,BZ0,R,R_ves(j,I),Z,Z_ves(j,i))
      BR=BR0*turn_ves(j,i)
      BZ=BZ0*turn_ves(j,i)
	BRR(I)=BR+BRR(I)
	BZZ(I)=BZ+BZZ(I)
	end do
	end do
c
      RETURN
      END
	subroutine elke(x,ellick,ellice)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	t=1.-x*x
	dd=dlog(t)
	ellice=((4.0905094e-2*t+8.5099193e-2)*t+0.44479204)*t+
     *  1.-dd*(((1.382999e-2*t+8.150224e-2)*t+0.24969795)*t)
	ellick=((3.2024666e-2*t+5.4544409e-2)*t+9.7932891e-2)*t+
     *  1.3862944-dd*(((1.0944912e-2*t+6.0118519e-2)*t+
     *  0.12475074)*t+0.5)
	return
	end


      FUNCTION FP_pet(R,R1,Z,Z1)
	include 'double.inc'
      real*8 greeni,rr,rrk,zz,zzk

	parameter(pi=3.14159265358d0, coef_pet=4.d0*pi/5.d0)

	rr=r
	rrk=r1
	zz=z
	zzk=z1
      green=coef_pet*greeni(rr,zz,rrk,zzk)
      FP_pet=GREEN
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
	real *4 x,x1,y,y1,fp
	common/kfp/kfp

        REAL MU0,K,K2,LAMBDA
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
        real*4 p1,p2,g1

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
  	subroutine pfind_pf()
	include 'double.inc'
c-------------------------------------------
c  read PF coil coordinates
c-----------------------------------------
c	implicit real*8 (a-h,o-z)
	include 'parf1'
      COMMON
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf2/R(nmax,KF),Z(nmax,KF),pw(nmax,KF)
     *  /pf3/nmx(kf),turn(kf)
     *  /pf4/rvert(kf),svert(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)
	common
     *  /ge1/pi
	dimension pf_res(kf),zvert(kf)

	common /c_pf4/turn_pf(nmax,kf),avert_pf(nmax,kf)

	character *12 name(kf),mq,mx
c
      PSF(X,hr,hz)=4.*PI/10.*X*(dlog(16.*X/SQRT(HZ**2+HR**2))
     *-0.5-0.5*(HR/HZ*DATAN(HZ/HR)+HZ/HR*DATAN(HR/HZ)))

	PSF1(X,y)=4.*PI/10.*X*(dLOG(8.*X/y)-1.5)


c=========
c   calculate test mutuals
	do i=1,npf
	do ik=1,npf
	pfind(i,ik)=0.
	end do
	end do
c
	do i=1,npf
	do j=1,nmx(i)
	do 11 ik=1,npf
	do 11 jk=1,nmx(ik)
	igreen=1
	if(i.eq.ik.and.j.eq.jk)igreen=0

	dist=dsqrt( (r(j,i)-r(jk,ik))**2+(z(j,i)-z(jk,ik))**2 )

	if(dist.le.1.e-2.and.igreen.eq.1)then
	   igreen=0
	   if(kpr.eq.1)print *,' dsit < 1.e-2 i ik',dist,i,ik
	end if


	if(igreen.eq.0)then 
!	fgreen=psf1(r(j,i),avert_pf(j,i))

	hr=dsqrt(avert_pf(j,i))
!	hr=avert_pf(j,i)
!	hr=dsqrt(pi)*avert(j,i)
	hz=hr
	fgreen=psf(r(j,i),hr,hz)
	if(kpr.eq.1)print *,' i j hr r gre=',i,j,hr,r(j,i),fgreen
	end if

	if(igreen.eq.1)fgreen=fp(r(j,i),r(jk,ik),z(j,i),
     *  z(jk,ik))

11	pfind(i,ik)=pfind(i,ik)+fgreen*turn_pf(j,i)*turn_pf(jk,ik)

	end do
	end do

	mq='pfind*'

	do i=1,npf
	if(kpr.eq.1)print 71,mq,(pfind(i,j),j=1,npf)
	end do
c_______________________________________
c   calculation of average R coordinates of PF coils
	do i=1,npf
	rvert(i)=0.
	zvert(i)=0.
	do j=1,nmx(i)
	rvert(i)=rvert(i)+r(j,i)
	zvert(i)=zvert(i)+z(j,i)
	end do
	rvert(i)=rvert(i)/nmx(i)
	zvert(i)=zvert(i)/nmx(i)

	if(kpr.eq.1)print*,'i rvert zvert ',i,rvert(i),zvert(i)

	end do
c---------------------------------------------
c
71 	format (20x,a6/,(6(1pe10.3)))
72	format(20x,a6/,(24i4))
c----
c===================================================
c
	
5000	format(4(1x,1pe14.7))
c----

	mx='pfind'

	do i=1,npf
	if(kpr.eq.1)print 71,mx,(pfind(i,j),j=1,npf)
	end do

	RETURN
	END
	subroutine zero_ves()
	include 'double.inc'
	include 'parf1'
	include 'parf2'
	include 'parf4'
	include 'parf2e'
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
	common
     *	/loop1/kloop,rl(nloop),zl(nloop),psloop(nloop)
     *	/loop5e/pslgreene(nwnhe,nloop)
	common
     *	/probe1/kprobe,bprobe(nprobe)
     *  /probe3/kpb,Rprobe(nprobe,npb),
     *  Zprobe(nprobe,npb),cosa(nprobe),sina(nprobe)
     *	/probe4e/bprgreene(nwnhe,nprobe)
c

	common /c_help1/i_print
        common
     *  /c_area/r0,rk,z0,zk

      dimension F(mu)

	character *200 tmp



c--------------------------------------
	dz=(zk-z0)/(nze-1.)
	dr=(rk-r0)/(nre-1.)
c----
	do i=1,nre
	r=r0+(i-1)*dr
	re(i)=r
	do j=1,nze
	z=z0+(j-1)*dz
	ze(j)=z
	kk=(i-1)*nze+j

	i_print=0
	if(kk.le.5)i_print=0

	call is1(f,r,z)
	do k=1,npf
	fluxarre(kk,k)=f(k)

	if(k.eq.2.and.kk.le.5)then
c	if(kpr.eq.1)print *,' r z j kk f==',r,z,j,kk,f(k)
	end if


	end  do
c
	call is_ves(f,r,z)
	do k=1,ncam
	vesarre(kk,k)=f(k)
	end do
c
	if(kloop.gt.0)then
	do k=1,kloop
	pslgreene(kk,k)=fp(r,rl(k),z,zl(k))
	end do
c	if(kpr.eq.1)print *,' pslgreene ...'
	end if
c
	if(kprobe.gt.0)then
	do k=1,kprobe
	bprgreene(kk,k)=0.
	do jk=1,kpb
        CALL BRZ(BR0,BZ0,rprobe(k,jk),r,zprobe(k,jk),z)
	bprgreene(kk,k)=bprgreene(kk,k)+
     *  (br0*cosa(k)+bz0*sina(k))/kpb
	end do

	end do

c	if(kpr.eq.1)print *,' bprgreene ...'
	end if

c
	end do
	end do
c
	if(kpr.eq.1)print *,' all greens...'

	if(kpr.eq.1)print *,' re==',(re(k),k=1,4)
	if(kpr.eq.1)print *,' ze==',(ze(k),k=1,4)

	if(kpr.eq.1)print *,' rloop==',(rl(k),k=1,4)
	if(kpr.eq.1)print *,' zloop==',(zl(k),k=1,4)


	if(kpr.eq.1)print *,' fluxarr==',(fluxarre(k,1),k=1,5)
	if(kpr.eq.1)print *,' fluxarr==',(fluxarre(k,2),k=1,5)

	if(kpr.eq.1)print *,' vesarr==',(vesarre(k,1),k=1,5)
	if(kpr.eq.1)print *,' pslgreene==',(pslgreene(k,1),k=1,5)
	if(kpr.eq.1)print *,' bprgreene==',(bprgreene(k,1),k=1,5)


	return
	end



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

	dist=sqrt( (r-r1)**2+(z-z1)**2 )

	if(dist.le.0.5)then
c	   if(kpr.eq.1)print *,' BRZ DIST===',dist
	   CALL ellip(GK,YK,YE)
	else
	   CALL elke(GK,YK,YE)
	end if

      BR=0.2*zz1/(R*sr1)*(-YK+YE*(R12+R2
     *+zz2)/rz1)
      BZ=0.2/sr1*(YK+YE*(R12-R2-ZZ2)/
     *rz1)
      RETURN
      END
      FUNCTION FP_rus(R,R1,Z,Z1)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	common
     *  /ge1/pi
	
	common /c_help2/i_print
c
	RR=R+R1
	ZZ=Z-Z1
	R0=R*R1
      GK=4.*R0/(RR*RR+ZZ*ZZ)
      GK=SQRT(GK)

	dist=sqrt( (r-r1)**2+(z-z1)**2 )

	if(dist.le.0.5)then
c	   if(kpr.eq.1)print *,' FP DIST===',dist
	   CALL ellip(GK,YK,YE)
	else
	   CALL elke(GK,YK,YE)
	end if

      GREEN=0.8*pi/GK*SQRT(R0)*((1.-GK*GK*0.5)*YK-YE)

      FP_rus=GREEN

	if(i_print.eq.1)then 
	t1=((1.-GK*GK*0.5)*YK-YE)
	t2=(1.-GK*GK*0.5)*YK
	t3=YE
	if(kpr.eq.1)print *,'t1 t2 t3',t1,t2,t3

	if(kpr.eq.1)print *,' r r1 z z1 gk yk ye r0 pi green',
     * r,r1,z,z1,gk,yk,ye,r0,pi,green
	end if

      RETURN
      END
      FUNCTION FP2(R,R1,Z,Z1)
 	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	common
     *  /ge1/pi
     *  /ge2/NTAY,TAY,TT
     *  /ge5/kpr


!	if(ntay.gt.ntay1)i_en=0
!	ntay1=ntay

	if(ntay.gt.10)then
	k_el=1
	else
	k_el=0
	end if

!	k_el=0

	aaa=0.5d0
c
	RR=R+R1
	ZZ=Z-Z1
	R0=R*R1
      GK=4.d0*R0/(RR*RR+ZZ*ZZ)

	if(kpr.eq.-1)print *,' r r1 z z1 ',r,r1,z,z1

      GK=dSQRT(GK)

	dist=dsqrt( (r-r1)**2+(z-z1)**2 )

	if(dist.le.0.1*aaa.or.k_el.eq.1)then
	   CALL elke(GK,YK1,YE1)
	   CALL ellip(GK,YK,YE)
	   print *,' DIST yk yk1===',dist,yk,yk1
	else

!	i_en=i_en+1

	   CALL elke(GK,YK,YE)
      if(kpr.eq.-1)print *,' k_el ntay DIST yk===',
     *  k_el,ntay,dist,yk

	end if

      GREEN=0.8d0*pi/GK*SQRT(R0)*((1.d0-GK*GK*0.5d0)*YK-YE)
      FP=GREEN

      if(kpr.eq.-1)print *,' gk r0===',
     *  gk,r0

      if(kpr.eq.-1)print *,' fp ye  yk===',
     *  fp,ye,yk


      RETURN
      END

      FUNCTION FP(R,R1,Z,Z1)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	common
     *  /ge1/pi

      real*8 PK2,r_d,z_d,r1_d,z1_d

	parameter( dist0=1.d0)

      PSF1(X,y)=4.d0*PI/10.d0*X*(dlog(8.d0*X/y)-1.5d0)

	r_d=r
	r1_d=r1
	z_d=z
	z1_d=z1
	
c
	RR=R+R1
	ZZ=Z-Z1
	R0=R*R1
      GK=4.d0*R0/(RR*RR+ZZ*ZZ)
	PK2=GK
      GK=DSQRT(GK)

	dist=dsqrt( (r-r1)**2+(z-z1)**2 )

	if(dist.le.dist0)then
	green=psf1(r,dist0)	
	else
	   CALL elke(GK,YK,YE)
      i_new=1
      if(i_new.eq.1)then
	YK=ELK(PK2)
	YE=ELE(PK2)
	end if
      GREEN=0.8*pi/GK*SQRT(R0)*((1.-GK*GK*0.5)*YK-YE)
	end if

      FP=GREEN

c	fint1=fp_pet(R,R1,Z,Z1)
c	fint2=fp_rus(R,R1,Z,Z1)

c	if(kpr.eq.1)print *,' fp fint1 fint2==',fp,fint1,fint2


      RETURN
      END


      FUNCTION FP_b(R,R1,Z,Z1)
	include 'double.inc'

	parameter( dist0=1.d-0)

c       implicit real*8 (a-h,o-z)
	common
     *  /ge1/pi

      real*8 PK2,r_d,z_d,r1_d,z1_d


      PSF1(X,y)=4.d0*PI/10.d0*X*(dlog(8.d0*X/y)-1.5d0)

	r_d=r
	r1_d=r1
	z_d=z
	z1_d=z1
	
c
	RR=R+R1
	ZZ=Z-Z1
	R0=R*R1
      GK=4.d0*R0/(RR*RR+ZZ*ZZ)
	PK2=GK
      GK=DSQRT(GK)

	dist=dsqrt( (r-r1)**2+(z-z1)**2 )

	if(dist.le.dist0)then
	green=psf1(r,dist0)	
	else
	   CALL elke(GK,YK,YE)
      i_new=1
      if(i_new.eq.1)then
	YK=ELK(PK2)
	YE=ELE(PK2)
	end if
      GREEN=0.8*pi/GK*SQRT(R0)*((1.-GK*GK*0.5)*YK-YE)
	end if

      FP_b=GREEN

      RETURN
      END



        subroutine  write2_to_mat(                                       

     *  ncam_mat,npf_mat,kloop_mat,kprobe_mat,                          

     *  z_l,z_r,r_l,r_r,                                                

     *  kf_mat,mu_mat,                                                  

     *  fluxarr_mat,vesarr_mat,                                         

     *  pslgreen_mat,bprgreen_mat,                                      

     *	pfind_mat,pmj_mat,pfc_mat,                                       

     *  pfres_mat,rcam_mat,                                             

     *  xu_mat,yu_mat,ke_mat,                                           

!     *  pf_mat,tcam_mat,

     *  pfgreen_mat,vesgreen_mat,

     *  pfprobe_mat,vesprobe_mat)

      	include 'double.inc'
                                                                        

	include 'parf2'                                                        
	include 'parf4'                                                        

                                                                        

        real*8 fluxarr_mat(nwnh,*),vesarr_mat(nwnh,*),                  

     *	pslgreen_mat(nwnh,*),bprgreen_mat(nwnh,*),                       

     *	pfind_mat(kf_mat,*),pmj_mat(mu_mat,*),                           

     *  pfc_mat(mu_mat,*),                                              

     *  pfres_mat(*),rcam_mat(*),                                       

     *  xu_mat(*),yu_mat(*),                                            

!     *  pf_mat(*),tcam_mat(*),

     *  pfgreen_mat(nloop,*),vesgreen_mat(nloop,*),

     *  pfprobe_mat(nprobe,*),vesprobe_mat(nprobe,*)

                                                                        

	real *8 z_l,z_r,r_l,r_r                                                

 	dimension a_print(200)
	character *30 apr
                                                                       

	z_l=z_l*1.d-2                                                            

	z_r=z_r*1.d-2                                                            

                                                                        

	r_l=r_l*1.d-2                                                            

	r_r=r_r*1.d-2                                                            


	ncam=ncam_mat                                                          
	npf=npf_mat                                                            
                                                                        
	kloop=kloop_mat 
	
	kprobe=kprobe_mat



                                                                  

	ke=ke_mat                                                              

	a_print(1)=ncam

	a_print(2)=npf

	a_print(3)=kloop

	a_print(4)=kprobe

	a_print(5)=ke

	a_print(6)=nwnh


	if(kpr.eq.1)print *,' ncam npf ke nwnh==',ncam,npf,ke,nwnh


	n_pr=6

	apr='  tran_to'

	num=6

c	call out42(n_pr,a_print,num,apr)
                                                                        

c!       write(41,*)' ncam npf kloop kprobe ke',ncam,npf,kloop,kprobe,ke  

                                                                        

                                                                        

	do k=1,ke                                                              

	   xu_mat(k)=xu_mat(k)*1.d-2                                                

	   yu_mat(k)=yu_mat(k)*1.d-2                                                

	end do                                                                 


	do k=1,ncam                                                            


	   do kk=1,ncam                                                        

	      pmj_mat(k,kk)=pmj_mat(k,kk)*1.d-8                                     

	   end do                                                              

c!        write(41,*)' k rcam pmj ',k,rcam(k),pmj(k,k)                    

	end do                                                                 

                                                                        
	apr='  pmj '
c	call out42(n_pr,a_print,num,apr)

                                                                        

	do k=1,ncam                                                            

	   do kk=1,npf                                                         

	      pfc_mat(k,kk)=pfc_mat(k,kk)*1.d-8                                     

	   end do                                                              

c!        write(41,*)' k pfc ',k,pfc(k,1),pfc(k,2),pfc(k,3)               

	end do                                                                 


	apr='  pfc'
c	call out42(n_pr,a_print,num,apr)
                                                                        

	do k=1,npf                                                             

	   do kk=1,npf                                                         

	      pfind_mat(k,kk)=pfind_mat(k,kk)*1.d-8                                 

	   end do                                                              

	end do                                                                 

                                                                        
	apr='  pfind'
c	call out42(n_pr,a_print,num,apr)

                                                                        

                                                                        

	do k=1,ncam                                                            

	   do kk=1,nwnh                                                        

	      vesarr_mat(kk,k)=vesarr_mat(kk,k)*1.d-8                               

	   end do                                                              

c!        write(41,*)' k vesarr ',k,vesarr(1,k),vesarr(2,k),vesarr(3,k)   

	end do                                                                 

	apr='  vesarr'
c	call out42(n_pr,a_print,num,apr)



	do k=1,npf                                                             

	   do kk=1,nwnh                                                        

	      fluxarr_mat(kk,k)=fluxarr_mat(kk,k)*1.d-8                        

	   end do                                                              

c        write(41,*)'k fluxarr',k,fluxarr(1,k),                          

c     *  fluxarr(2,k),fluxarr(3,k)                                       

	end do                                                                 

	apr='  fluxarr'
c	call out42(n_pr,a_print,num,apr)


	if(kloop.gt.0)then                                                     

	   do k=1,kloop                                                        

	      do kk=1,nwnh                                                     

		 pslgreen_mat(kk,k)=pslgreen_mat(kk,k)*1.d-8

	      end do
	   end do 

	apr='  pslgreen '
c	call out42(n_pr,a_print,num,apr)

	   do k=1,kloop                                                        
	      do kk=1,npf

		 pfgreen_mat(k,kk)=pfgreen_mat(k,kk)*1.d-8 

	      end do                                                           
	   end do                                                              

	apr='  pfgreen '
c	call out42(n_pr,a_print,num,apr)

	   do k=1,kloop                                                        
	      do kk=1,ncam

		 vesgreen_mat(k,kk)=vesgreen_mat(k,kk)*1.d-8 

	      end do                                                           

	   end do                                                              
	apr='  vesgreen '
c	call out42(n_pr,a_print,num,apr)

	end if                                                                 

                                                                        

	if(kprobe.gt.0)then                                                    
	a_print(4)=kprobe
	apr='  kprobe '
c	call out42(n_pr,a_print,num,apr)

	   do k=1,kprobe                                                       

	apr='  k '
	a_print(1)=k
	n_pr=1
c	call out42(n_pr,a_print,num,apr)
	      do kk=1,nwnh                                                     

		 bprgreen_mat(kk,k)=bprgreen_mat(kk,k)*1.d-4

	      end do
	   end do                                                              
	apr='  bprgreen '
c	call out42(n_pr,a_print,num,apr)

	   do k=1,kprobe                                                       
	      do kk=1,npf

		 pfprobe_mat(k,kk)=pfprobe_mat(k,kk)*1.d-4

	      end do                                                           
	   end do                                                              
	apr='  pfprobe '
c	call out42(n_pr,a_print,num,apr)

	   do k=1,kprobe                                                       
	      do kk=1,ncam

		 vesprobe_mat(k,kk)=vesprobe_mat(k,kk)*1.d-4

	      end do                                                           
	   end do                                                              
	apr='  vesprobe '
c	call out42(n_pr,a_print,num,apr)
c                                                                       

	end if
                                                                        

      return
      

	open (unit=41,file='glcoeff_mat.flat',form='formatted') 
	write (41,*)npf,ncam,kloop,kprobe         
	write (41,*)' end of file '         
	close (41)                                                             



	open (unit=41,file='gridrange.flat',form='formatted')                  

                                                                        

	write (41,*)' 1 '                      

	write (41,*) ' 4 '                      

                                                                        

	write (41,*)z_l           

	write (41,*)z_r            

	write (41,*)r_l           

	write (41,*)r_r           

c	if(kpr.eq.1)print *,' z_l z_r r_l r_r==',z_l,z_r,r_l,r_r                           

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='xu_mat.flat',form='formatted')                     

                                                                        

	write (41,*)ke_mat                                                      

	write (41,*)' 1  '                             

                                                                        

	do k=1,ke_mat                                                          

	write (41,*)xu_mat(k)                                                   

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='yu_mat.flat',form='formatted')                     

                                                                        

	write (41,*)ke_mat                                                      

	write (41,*)' 1 '                                                            

                                                                        

	do k=1,ke_mat                                                          

	write (41,*)yu_mat(k)                                                   

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='rcam_mat.flat',form='formatted')                   

                                                                        

	write (41,*)ncam_mat                                                    

	write (41,*)' 1 '                                                            

	do k=1,ncam_mat                                                        

	write (41,*)rcam_mat(k)                                                 

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                               
                                                                        

	open (unit=41,file='pmj_mat.flat',form='formatted')                    

                                                                        

	write (41,*)ncam_mat                                                    

	write (41,*)' 1 '                                                            

                                                                        

	do kk=1,ncam_mat                                                       

	   do k=1,ncam_mat                                                     

	      write (41,*)pmj_mat(k,kk)                                         

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='pfc_mat.flat',form='formatted')                    

                                                                        

	write (41,*)ncam_mat                                                    

	write (41,*)npf_mat                                                     

                                                                        

	do kk=1,npf_mat                                                        

	   do k=1,ncam_mat                                                     

	   write (41,*)pfc_mat(k,kk)                                            

	end do                                                                 

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='pfres_mat.flat',form='formatted')                  

                                                                        

	write (41,*)npf_mat                                                     

	write (41,*)' 1 '                                                            

	do k=1,npf_mat                                                         

	   write (41,*)pfres_mat(k)                                             

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

                                                                        

	open (unit=41,file='pfind_mat.flat',form='formatted')                  

                                                                        

	write (41,*)npf_mat                                                     

	write (41,*)npf_mat

      

	do kk=1,npf_mat                                                        

	   do k=1,npf_mat                                                      

	      write (41,*)pfind_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

                                                                        

	open (unit=41,file='vesarr_mat.flat',form='formatted')                 

                                                                        

	write (41,*)ncam_mat                                                         
	write (41,*)nwnh                                                         


	do k=1,ncam_mat                                                        

	   do kk=1,nwnh                                                        

	      write (41,*)vesarr_mat(kk,k)                                      

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='fluxarr_mat.flat',form='formatted')                

                                                                        


	write (41,*)npf_mat                                                   
	write (41,*)nwnh                                                          

	do k=1,npf_mat                                                         

	   do kk=1,nwnh                                                        

	      write(41,*)fluxarr_mat(kk,k)                                     

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='pslgreen_mat.flat',form='formatted')               

                                                                        

	write (41,*)nwnh                                                         

	write (41,*)kloop_mat                                                   

	do k=1,kloop_mat                                                       

	   do kk=1,nwnh                                                        

	   write (41,*)pslgreen_mat(kk,k)                                       

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='pfgreen_mat.flat',form='formatted')               

	write (41,*)npf_mat       

	write (41,*)kloop_mat                                                   

	do k=1,kloop_mat                                                       

	   do kk=1,npf_mat

	   write (41,*)pfgreen_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='vesgreen_mat.flat',form='formatted')               

	write (41,*)ncam_mat       

	write (41,*)kloop_mat                                                   

	do k=1,kloop_mat                                                       

	   do kk=1,ncam_mat

	   write (41,*)vesgreen_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='bprgreen_mat.flat',form='formatted')               

	write (41,*) nwnh

	write (41,*)kprobe_mat                                                  

	do k=1,kprobe_mat                                                      

	   do kk=1,nwnh                                                        

	   write (41,*)bprgreen_mat(kk,k)                                       

	   end do                                                              

	end do                                                                 

	close (41)



	open (unit=41,file='pfprobe_mat.flat',form='formatted')               

	write (41,*)npf_mat

	write (41,*)kprobe_mat                                                  

	do k=1,kprobe_mat                                                      

	   do kk=1,npf_mat

	   write (41,*)pfprobe_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             



	open (unit=41,file='vesprobe_mat.flat',form='formatted')               

	write (41,*)ncam_mat

	write (41,*)kprobe_mat                                                  

	do k=1,kprobe_mat                                                      

	   do kk=1,ncam_mat

	   write (41,*)vesprobe_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        
                                                                        

c	if(kpr.eq.1)print *,' ncam_mat,npf_mat,ke_mat',ncam_mat,npf_mat,ke_mat             

c	if(kpr.eq.1)print *,' kloop_mat,kprobe_mat',kloop_mat,kprobe_mat                   

                                                                        

                                                                        

c                                                                       

        RETURN                                                          

        END   
                                                                  
        subroutine  read_green_params(

     *  ncam_mat,npf_mat,kloop_mat,kprobe_mat,ke_mat,nwnh_mat)

	include 'double.inc'
	include 'new_com.inc'

      kpr=1
      
	ncam_mat=ncam                                                          
	npf_mat=npf                                                            
	kloop_mat=kloop 	
	kprobe_mat=kprobe
	ke_mat=ke                                                              
      nwnh_mat=nwnh
      
	if(kpr.eq.1)print *,' ncam npf ke nwnh==',ncam,npf,ke,nwnh
	if(kpr.eq.1)print *,' kloop kprobe ==',kloop,kprobe
      
        return
        end
        
      
        subroutine  read_greens(                                       

     *  mu_mat,kf_mat,nloop_mat,nprobe_mat,nwnh_mat,

     *  x_mat,y_mat, 

     *  fluxarr_mat,vesarr_mat,                                         

     *  pslgreen_mat,bprgreen_mat,                                      

     *	pfind_mat,pmj_mat,pfc_mat,                                       

     *  pfres_mat,rcam_mat,                                             

     *  xu_mat,yu_mat,ke_mat,                                           

     *  pfgreen_mat,vesgreen_mat,

     *  pfprobe_mat,vesprobe_mat)

	include 'double.inc'
	include 'new_com.inc'

        real*8 fluxarr_mat(nwnh_mat,*),vesarr_mat(nwnh_mat,*),

     *	pslgreen_mat(nwnh_mat,*),bprgreen_mat(nwnh_mat,*),

     *	pfind_mat(kf_mat,*),pmj_mat(mu_mat,*),                           

     *  pfc_mat(mu_mat,*),                                              

     *  pfres_mat(*),rcam_mat(*),                                       

     *  xu_mat(*),yu_mat(*),                                            

     *  pfgreen_mat(nloop_mat,*),vesgreen_mat(nloop_mat,*),

     *  pfprobe_mat(nprobe_mat,*),vesprobe_mat(nprobe_mat,*),
     
     *  x_mat(*),y_mat(*)


	real *8 z_l0,z_r0,r_l0,r_r0

 	dimension a_print(200)
	character *30 apr

      do i=1,nre
      x_mat(i)=re(i)*1.d-2
      end do
      
      do i=1,nze
      y_mat(i)=ze(i)*1.d-2
      end do

	r_l0=re(1)
	r_r0=re(nre)

	z_l0=ze(1)
	z_r0=ze(nze)

      if(kpr.eq.1)print *,'r_l0 r_r0 ',r_l0,r_r0
      if(kpr.eq.1)print *,'z_l0 z_r0 ',z_l0,z_r0


      if(kpr.eq.1)print *,'x(1) x(nr) ',x_mat(1),x_mat(nre)
      if(kpr.eq.1)print *,'y(1) y(nz) ',y_mat(1),y_mat(nze)

      if(kpr.eq.1)print *,'mu_mat,kf_mat,nloop_mat,nprobe_mat ',
     *  mu_mat,kf_mat,nloop_mat,nprobe_mat

     
      if(kpr.eq.1)print *,'ke_mat,nwnh_mat ',
     *  ke_mat,nwnh_mat


	ncam=mu_mat                                                          
	npf=kf_mat                                                            
	kloop=nloop_mat 
	kprobe=nprobe_mat
	ke=ke_mat                                                              

	if(kpr.eq.1)print *,' ncam npf ke nwnh==',ncam,npf,ke,nwnh
	if(kpr.eq.1)print *,' kloop kprobe ==',kloop,kprobe


	do k=1,ke                                                              

	   xu_mat(k)=xu(k)

	   yu_mat(k)=yu(k)

	end do                                                                 


	do k=1,ncam                                                            


	   do kk=1,ncam                                                        

	      pmj_mat(k,kk)=pmj(k,kk)

	   end do                                                              


	end do                                                                 
                                                                        

	do k=1,ncam                                                            

	   do kk=1,npf                                                         

	      pfc_mat(k,kk)=pfc(k,kk)

	   end do                                                              

	end do                                                                 


	do k=1,npf                                                             

	   do kk=1,npf                                                         

	      pfind_mat(k,kk)=pfind(k,kk)

	   end do                                                              

	end do                                                                 
                                                                        

	do k=1,ncam                                                            

	   do kk=1,nwnh                                                        

	      vesarr_mat(kk,k)=vesarre(kk,k)

	   end do                                                              


	end do                                                                 




	do k=1,npf                                                             

	   do kk=1,nwnh                                                        

	      fluxarr_mat(kk,k)=fluxarre(kk,k)

	   end do                                                              


	end do                                                                 



	if(kloop.gt.0)then                                                     

	   do k=1,kloop                                                        

	      do kk=1,nwnh                                                     

		 pslgreen_mat(kk,k)=pslgreene(kk,k)

	      end do
	   end do 



	   do k=1,kloop                                                        
	      do kk=1,npf

		 pfgreen_mat(k,kk)=pfgreen(k,kk)

	      end do                                                           
	   end do                                                              


	   do k=1,kloop                                                        
	      do kk=1,ncam

		 vesgreen_mat(k,kk)=vesgreen(k,kk)

	      end do                                                           

	   end do                                                              

	end if                                                                 

                                                                        

	if(kprobe.gt.0)then                                                    

	   do k=1,kprobe                                                       

	      do kk=1,nwnh                                                     

		 bprgreen_mat(kk,k)=bprgreene(kk,k)

	      end do
	   end do                                                              

	   do k=1,kprobe                                                       
	      do kk=1,npf

		 pfprobe_mat(k,kk)=pfprobe(k,kk)

	      end do                                                           
	   end do                                                              

	   do k=1,kprobe                                                       
	      do kk=1,ncam

		 vesprobe_mat(k,kk)=vesprobe(k,kk)

	      end do                                                           
	   end do                                                              

	end if

     	do k=1,npf       

	pfres_mat(k)=pfres(k)                                             

	end do                                                                 
                                                                   
	do k=1,ncam                                                        

	rcam_mat(k)=rcam(k)                                                 

	end do                                                                 

      return

	open (unit=41,file='glcoeff_mat.flat',form='formatted') 
	write (41,*)npf,ncam,kloop,kprobe         
	write (41,*)' end of file '         
	close (41)                                                             



	open (unit=41,file='gridrange.flat',form='formatted')                  

                                                                        

	write (41,*)' 1 '                      

	write (41,*) ' 4 '                      

                                                                        

	write (41,*)z_l           

	write (41,*)z_r            

	write (41,*)r_l           

	write (41,*)r_r           

c	if(kpr.eq.1)print *,' z_l z_r r_l r_r==',z_l,z_r,r_l,r_r                           

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='xu_mat.flat',form='formatted')                     

                                                                        

	write (41,*)ke_mat                                                      

	write (41,*)' 1  '                             

                                                                        

	do k=1,ke_mat                                                          

	write (41,*)xu_mat(k)                                                   

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='yu_mat.flat',form='formatted')                     

                                                                        

	write (41,*)ke_mat                                                      

	write (41,*)' 1 '                                                            

                                                                        

	do k=1,ke_mat                                                          

	write (41,*)yu_mat(k)                                                   

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='rcam_mat.flat',form='formatted')                   

                                                                        

	write (41,*)ncam_mat                                                    

	write (41,*)' 1 '                                                            

	do k=1,ncam_mat                                                        

	write (41,*)rcam_mat(k)                                                 

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                               
                                                                        

	open (unit=41,file='pmj_mat.flat',form='formatted')                    

                                                                        

	write (41,*)ncam_mat                                                    

	write (41,*)' 1 '                                                            

                                                                        

	do kk=1,ncam_mat                                                       

	   do k=1,ncam_mat                                                     

	      write (41,*)pmj_mat(k,kk)                                         

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='pfc_mat.flat',form='formatted')                    

                                                                        

	write (41,*)ncam_mat                                                    

	write (41,*)npf_mat                                                     

                                                                        

	do kk=1,npf_mat                                                        

	   do k=1,ncam_mat                                                     

	   write (41,*)pfc_mat(k,kk)                                            

	end do                                                                 

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='pfres_mat.flat',form='formatted')                  

                                                                        

	write (41,*)npf_mat                                                     

	write (41,*)' 1 '                                                            

	do k=1,npf_mat                                                         

	   write (41,*)pfres_mat(k)                                             

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

                                                                        

	open (unit=41,file='pfind_mat.flat',form='formatted')                  

                                                                        

	write (41,*)npf_mat                                                     

	write (41,*)npf_mat

      

	do kk=1,npf_mat                                                        

	   do k=1,npf_mat                                                      

	      write (41,*)pfind_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

                                                                        

	open (unit=41,file='vesarr_mat.flat',form='formatted')                 

                                                                        

	write (41,*)ncam_mat                                                         
	write (41,*)nwnh                                                         


	do k=1,ncam_mat                                                        

	   do kk=1,nwnh                                                        

	      write (41,*)vesarr_mat(kk,k)                                      

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='fluxarr_mat.flat',form='formatted')                

                                                                        


	write (41,*)npf_mat                                                   
	write (41,*)nwnh                                                          

	do k=1,npf_mat                                                         

	   do kk=1,nwnh                                                        

	      write(41,*)fluxarr_mat(kk,k)                                     

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='pslgreen_mat.flat',form='formatted')               

                                                                        

	write (41,*)nwnh                                                         

	write (41,*)kloop_mat                                                   

	do k=1,kloop_mat                                                       

	   do kk=1,nwnh                                                        

	   write (41,*)pslgreen_mat(kk,k)                                       

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='pfgreen_mat.flat',form='formatted')               

	write (41,*)npf_mat       

	write (41,*)kloop_mat                                                   

	do k=1,kloop_mat                                                       

	   do kk=1,npf_mat

	   write (41,*)pfgreen_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='vesgreen_mat.flat',form='formatted')               

	write (41,*)ncam_mat       

	write (41,*)kloop_mat                                                   

	do k=1,kloop_mat                                                       

	   do kk=1,ncam_mat

	   write (41,*)vesgreen_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='bprgreen_mat.flat',form='formatted')               

	write (41,*) nwnh

	write (41,*)kprobe_mat                                                  

	do k=1,kprobe_mat                                                      

	   do kk=1,nwnh                                                        

	   write (41,*)bprgreen_mat(kk,k)                                       

	   end do                                                              

	end do                                                                 

	close (41)



	open (unit=41,file='pfprobe_mat.flat',form='formatted')               

	write (41,*)npf_mat

	write (41,*)kprobe_mat                                                  

	do k=1,kprobe_mat                                                      

	   do kk=1,npf_mat

	   write (41,*)pfprobe_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             



	open (unit=41,file='vesprobe_mat.flat',form='formatted')               

	write (41,*)ncam_mat

	write (41,*)kprobe_mat                                                  

	do k=1,kprobe_mat                                                      

	   do kk=1,ncam_mat

	   write (41,*)vesprobe_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        
                                                                        

c	if(kpr.eq.1)print *,' ncam_mat,npf_mat,ke_mat',ncam_mat,npf_mat,ke_mat             

c	if(kpr.eq.1)print *,' kloop_mat,kprobe_mat',kloop_mat,kprobe_mat                   

                                                                        

                                                                        

c                                                                       

        RETURN                                                          

        END                                                             


	subroutine flat_write()

	include 'double.inc'
	include 'new_com.inc'

	r_l=re(1)
	r_r=re(nre)

	z_l=ze(1)
	z_r=ze(nze)

      if(kpr.eq.1)print *,'r_l r_r ',r_l,r_r
      if(kpr.eq.1)print *,'z_l z_r ',z_l,z_r


      if(kpr.eq.1)print *,'write2_to_mat',ncam,npf,kloop,kprobe,kf,mu

	call write2_to_mat(                                       

     *  ncam,npf,kloop,kprobe,                          

     *  z_l,z_r,r_l,r_r,                                                

     *  kf,mu,                                                  

     *  fluxarre,vesarre,                                         

     *  pslgreene,bprgreene,                                      

     *  pfind,pmj,pfc,                                       

     *  pfres,rcam,                                             

     *  xu,yu,ke,                                           

!     *  pf,tcam,

     *  pfgreen,vesgreen,

     *  pfprobe,vesprobe)

        RETURN                                                          

        END                                                             
  	subroutine config_coor()
	include 'double.inc'
c-------------------------------------------
c  read PF coil coordinates
c-----------------------------------------
c	implicit real*8 (a-h,o-z)
	include 'parf1'
	include 'parf4'
	include 'parf7'
      COMMON
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf2/R(nmax,KF),Z(nmax,KF),pw(nmax,KF)
     *  /pf3/nmx(kf),turn(kf)
     *  /c_pf2/R_c(KF),Z_c(KF),DR(KF),DZ(KF),
     *  alpha(KF),beta(KF)
     *  /c_pf3/nr(kf),nz(kf),nt(kf),n_pf_num(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)

	common /c_pf4/turn_pf(nmax,kf),avert_pf(nmax,kf)

	common
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves2e/dl(mu),hl(mu)
     *  /ves4/rcam(mu)
     *  /c_ves2/ndl_ves(mu),ndh_ves(mu),nt_ves(mu),n_ves_num(mu)
     *  /c_ves2e/alpha_ves(mu),beta_ves(mu)
     *  /c_ves3/nmx_ves(mu)
     *  /c_ves4/r_ves(nmax,mu),z_ves(nmax,mu),a_ves(nmax,mu),
     *  turn_ves(nmax,mu)


	common
     *	/loop1/kloop,rl(nloop),zl(nloop),psloop(nloop)
	common
     *	/probe1/kprobe,bprobe(nprobe)
     *  /probe3/kpb,Rprobe(nprobe,npb),
     *  Zprobe(nprobe,npb),cosa(nprobe),sina(nprobe)
     *  /c_probe3/r_prob(nprobe),z_prob(nprobe),
     *  anglep(nprobe),smp(nprobe)

	common
     *  /eq2/ke,xu(mu_l),yu(mu_l)

        common
     *  /ge5/kpr
        common
     *  /c_area/r00,rk,z00,zk
           
        parameter ( n_max=100)
       dimension x(n_max,n_max),y(n_max,n_max),r0(n_max),z0(n_max)
       
       dimension r_new(nmax,mu),z_new(nmax,mu),avert_new(nmax,mu),
     *  turn_new(nmax,mu),nmx_new(mu)


	CHARACTER*20 fshot,tmp

!	open (unit=40,file='config.fl',form='formatted')
!	read (40,*)
!	read (40,74)tmp
74	format(a20)
!	close (40)
!    	open(unit=41,status='old',file=tmp,form='formatted')

      kpr=0

     	open(unit=49,file='dina_data.dat',
!!!     	open(unit=41,file='tokamak_config.dat',
     *  form='formatted')
	if(kpr.eq.1)print *,' opened file tokamak_config.dat'
	read(49,*)
	if(kpr.eq.1)print *,' 1'
	read(49,*)npf
	if(kpr.eq.1)print *,'npf ',npf
	do I=1,npf
	read(49,*)
	read(49,*)nr(i),nz(i),nt(i),n_pf_num(i)
c
	if(kpr.eq.1)PRINT*,'i Nr Nz nt pf_num',i,Nr(I),nz(i),nt(i),n_pf_num(i)
	read(49,*)R_c(I),Z_c(I),dr(i),dz(i),alpha(i),beta(i)
	if(kpr.eq.1)print *,'r_c z_c dr dz alpha beta ',
     * r_c(i),z_c(i),dr(i),dz(i),alpha(i),beta(i)
	END DO


	read(49,*)
	if(kpr.eq.1)print *,' res_pf'
	read(49,*)npf_res
	if(kpr.eq.1)print *,'npf_res ',npf_res
	do I=1,npf_res
	read(49,*)pfres(i)
	if(kpr.eq.1)print *,' i pfres(i)',i,pfres(i)
      end do
      
	read(49,*)
	if(kpr.eq.1)print *,' Vessel'
	read(49,*)ncam
	if(kpr.eq.1)print *,'ncam ',ncam
	do I=1,ncam
	read(49,*)
	read(49,*)ndl_ves(i),ndh_ves(i),nt_ves(i),n_ves_num(i)
c
	if(kpr.eq.1)PRINT*,'i N M nt ves_n',i,Ndl_ves(I),
     *  ndh_ves(i),nt_ves(i),n_ves_num(i)
	read(49,*)Rc(I),Zc(I),dl(i),hl(i),alpha_ves(i),beta_ves(i)
	if(kpr.eq.1)print *,'r_c z_c dr dz alpha beta ',
     * rc(i),zc(i),dl(i),hl(i),alpha_ves(i),beta_ves(i)
	END DO


	read(49,*)
	if(kpr.eq.1)print *,' res_ves'
	read(49,*)ncam
	if(kpr.eq.1)print *,'ncam ',ncam
	do I=1,ncam
	read(49,*)rcam(i)
	if(kpr.eq.1)print *,' i rcam(i)',i,rcam(i)
      end do


	read(49,*)
	if(kpr.eq.1)print *,' Flux loops'
	read(49,*)kloop
	if(kpr.eq.1)print *,'kloop ',kloop
	do I=1,kloop

	read(49,*)Rl(I),Zl(I)
	if(kpr.eq.1)print *,'r_l z_l ',rl(i),zl(i)
	END DO


	read(49,*)
	if(kpr.eq.1)print *,' Probe'
	read(49,*)kprobe,kpb
	if(kpr.eq.1)print *,'kprobe,kpb ',kprobe,kpb
	do I=1,kprobe
	read(49,*)R_prob(I),Z_prob(I),anglep(i),smp(i)
	if(kpr.eq.1)print *,'r_pr z_pr alpha smp ',
     * R_prob(I),Z_prob(I),anglep(i),smp(i)
	END DO

	read(49,*)
	if(kpr.eq.1)print *,' limiter'
	read(49,*)ke
	if(kpr.eq.1)print *,'ke ',ke
	do I=1,ke

	read(49,*)xu(I),yu(I)
	xu(I)=xu(I)*100.d0
	yu(I)=yu(I)*100.d0
	if(kpr.eq.1)print *,'xu yu ',xu(I),yu(I)
	END DO

      read(49,*)    
	read(49,*)r00,rk
	r00=r00*100.d0
	rk=rk*100.d0
      read(49,*)z00,zk
	z00=z00*100.d0
	zk=zk*100.d0
	if(kpr.eq.1)print *,'r00,rk ',r00,rk
	if(kpr.eq.1)print *,'z00,zk ',z00,zk

!	close(41)

2	FORMAT(/,2(2x,1PE10.3))


      do i=1,npf

!      R_c(I),Z_c(I),dr(i),dz(i),alpha(i),beta(i)
!      alpha(i)=3.14159265358979d0/2.d0
      r_lb=R_c(I)-1.*0.5*(dr(i)*cos(beta(i))+dz(i)*cos(alpha(i)) )
      z_lb=z_c(i)-1.*0.5*(dr(i)*sin(beta(i))+dz(i)*sin(alpha(i)) )

      if(kpr.eq.1)print *,' i nr nz dr dz al bet=',
     * i,nr(i),nz(i),dr(i),dz(i),
     * alpha(i),beta(i)
      
! coils.r(i)=coils.r(i)-0.5*(coils.dl(i)*cos(beta(i))+coils.dh(i)*cos(alpha(i)));
! coils.z(i)=coils.z(i)-0.5*(coils.dl(i)*sin(beta(i))+coils.dh(i)*sin(alpha(i)));

! coil(r_lb,z_lb,n,m,dl_alpha,dl_beta,alpha_degree,beta_degree);

       
      call coils(r_lb,z_lb,dz(i),dr(i),nz(i),nr(i),alpha(i),beta(i),
     * n_max,x,y,r0,z0,ss)


        if(kpr.eq.1)print *,' i ss=',i,ss
        
!         if(kpr.eq.1)print *,'r0=',(r0(j),j=1,nz(i))

!         if(kpr.eq.1)print *,'x_1=',(x(j,1),j=1,nz(i))
!         if(kpr.eq.1)print *,'x_2=',(x(j,2),j=1,nz(i))


       kk=0
       ntot=nr(i)*nz(i)
       nmx(i)=ntot
      do j=1,nz(i)
        do k=1,nr(i)
            kk=kk+1;
            r(kk,i)=x(j,k)*100.;
            z(kk,i)=y(j,k)*100.;
            
!            if(kpr.eq.1)print *,' i j k',i,j,k
!            if(kpr.eq.1)print *,'x=',x(j,k)
!            read (*,*)
            
            avert_pf(kk,i)=dabs(ss)*1.d4;
!            avert(kk,i)=sqrt(ss);
            turn_pf(kk,i)=float(nt(i))/float(ntot);            
         end do
       end do  
      
      end do

      if(i_wr.eq.1)then
	open(unit=4,file='koor_jt_old',form='formatted')

	do i=1,npf
	   write(4,*)i
	   write(4,*)nmx(i)
	   do j=1,nmx(i)
	   write (4,*)r(j,i),z(j,i),turn_pf(j,i),
     *     avert_pf(j,i)
	   end do
	end do

	close(4)

      end if
      
      do ii=1,npf
      	npf_max=max(npf_max,n_pf_num(ii));
      end do
      
      
      do ii=1,npf_max
	   kk=0
	   do i=1,npf
	      do jj=1,nmx(i)
		 if(n_pf_num(i).eq.ii)then
		    kk=kk+1
		    r_new(kk,ii)=r(jj,i)
		    z_new(kk,ii)=z(jj,i)
		    turn_new(kk,ii)=turn_pf(jj,i)
		    avert_new(kk,ii)=avert_pf(jj,i)
		 end if 
	      end do 
       end do

	   nmx_new(ii)=kk

       if(kpr.eq.1)print *,' ii nmx_new==',ii,nmx_new(ii)

       end do

	npf=npf_max

      if(kpr.eq.1)print *,' npf_max==',npf_max

	do i=1,npf
	   nmx(i)=nmx_new(i)
	   do j=1,nmx(i)
	   r(j,i)=r_new(j,i)
	   z(j,i)=z_new(j,i)
	   turn_pf(j,i)=turn_new(j,i)
	   avert_pf(j,i)=avert_new(j,i)
	   end do
	end do

      if(i_wr.eq.1)then

	open(unit=4,file='koor_jt',form='formatted')

	do i=1,npf
	   write(4,*)i
	   write(4,*)nmx(i)
	   do j=1,nmx(i)
	   write (4,*)r(j,i),z(j,i),turn_pf(j,i),
     *     avert_pf(j,i)
	   end do
	end do

	close(4)
      end if
      
	do i=1,npf
	DO J=1,nmx(i)
	pw(j,i)=turn_pf(j,i)
	end do
	END DO


      do i=1,ncam

!rc(i),zc(i),dl(i),hl(i),alpha_ves(i),beta_ves(i)


      r_lb=Rc(I)-0.5*( dl(i)*cos(beta_ves(i))+hl(i)*cos(alpha_ves(i)) )
      z_lb=zc(i)-0.5*( dl(i)*sin(beta_ves(i))+hl(i)*sin(alpha_ves(i)) )

         if(kpr.eq.1)print *,'i ndh ndl=',i,ndh_ves(i),ndl_ves(i)
      
        call coils(r_lb,z_lb,hl(i),dl(i),
     *  ndh_ves(i),ndl_ves(i),alpha_ves(i),beta_ves(i),
     *  n_max,x,y,r0,z0,ss)

         if(kpr.eq.1)print *,'ndh ndl=',ndh_ves(i),ndl_ves(i)
         
         if(kpr.eq.1)print *,'r0=',(r0(j),j=1,ndh_ves(i))

         if(kpr.eq.1)print *,'x_1=',(x(j,1),j=1,ndh_ves(i))
         if(kpr.eq.1)print *,'x_2=',(x(j,2),j=1,ndh_ves(i))

       kk=0
       ntot=ndl_ves(i)*ndh_ves(i)
       nmx_ves(i)=ntot
      do j=1,ndh_ves(i)
        do k=1,ndl_ves(i)
            kk=kk+1;
            r_ves(kk,i)=x(j,k)*100.d0;
            z_ves(kk,i)=y(j,k)*100.d0;
            a_ves(kk,i)=dabs(ss)*1.d4;
!            avert(kk,i)=sqrt(ss);
            turn_ves(kk,i)=float(nt_ves(i))/float(ntot);            
         end do
       end do  
      
      end do

      if(i_wr.eq.1)then

	open(unit=4,file='koor_ves',form='formatted')

	do i=1,ncam
	   write(4,*)i
	   write(4,*)nmx_ves(i)
	   do j=1,nmx_ves(i)
	   write (4,*)r_ves(j,i),z_ves(j,i),turn_ves(j,i),
     *     a_ves(j,i)
	   end do
	end do

	close(4)
      end if
      
!      stop
c
71 	format (20x,a6/,(6(1pe10.3)))
      RETURN
      END
      
      subroutine coils(r_lb,z_lb,dl_alpha,dl_beta,n,m,alpha,beta,
     * nmax,x,y,r0,z0,ss)
	include 'double.inc'

       dimension  x(nmax,*),y(nmax,*),r0(*),z0(*)
        common
     *  /ge5/kpr
   

	dr=dl_alpha/dfloat(n)

	p_ii=0.5d0
	do i=1,n
		r0(i)=r_lb+dr*p_ii*dcos(alpha)
		z0(i)=z_lb+dr*p_ii*dsin(alpha)
		p_ii=p_ii+1.d0
      end do
      
	ddr=dl_beta/dfloat(m)

	if(kpr.eq.1)print *,'  ddr=',ddr

	k=0;
	do i=1,n
		p_jj=0.5d0
		do j=1,m
			y(i,j)=z0(i)+ddr*p_jj*dsin(beta)
			x(i,j)=r0(i)+ddr*p_jj*dcos(beta)
			p_jj=p_jj+1.d0
			
!			if(kpr.eq.1)print *,' i j x y=',i,j,x(j,i),y(j,i)
			
        end do
!        read (*,*)
        
       end do

         if(kpr.eq.1)print *,'** x_1=',(x(j,1),j=1,n)
         if(kpr.eq.1)print *,'** x_2=',(x(j,2),j=1,n)
       
       ss=dabs(dr*ddr*dsin(alpha-beta))

		if(kpr.eq.1)print *,' ss dr ddr=',ss,dr,ddr
       
      RETURN
      END
 
	subroutine imas_loops()
	include 'double.inc'
c-----------------------------------------
c  input loops coordinates
c  calculate greens from PF and vessel...
c---------------------------------------
c	implicit real*8 (a-h,o-z)

	include 'parf1'
	include 'parf4'
c
	common
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *  /ge1/pi
     *  /ge5/kpr
	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf3/nmx(kf),turn(kf)
	common
     *  /loop1/kloop,RL(nloop),ZL(nloop),psloop(nloop)
     *  /loop2/pfgreen(nloop,kf),vesgreen(nloop,mu)
     *  /loop4/psloopg(nloop),psloopg0(nloop)
c
	dimension f(mu)

	character *8 apr
	CHARACTER*120 fshot,tmp
c------------------------------



	do i=1,kloop
	rl(i)=rl(i)*1.e2
	zl(i)=zl(i)*1.e2
	end do
c***********************
	apr='r loop'
	if(kpr.eq.1)print 71,apr,(rl(i),i=1,kloop)
	apr='z loop'
	if(kpr.eq.1)print 71,apr,(zl(i),i=1,kloop)

      i_calc=1
	if(i_calc.eq.1)then
c-----------------------------
c   calculate green functions PF to loops...
	do i=1,kloop
	call is1(f,rl(i),zl(i))
	do j=1,npf
	pfgreen(i,j)=f(j)
	end do
	end do
	apr='pf gre'
	do i=1,kloop
	if(kpr.eq.1)print *,'iloop',i
	if(kpr.eq.1)print 71,apr,(pfgreen(i,j),j=1,npf)
	end do
	end if
c--------------------------------
c  calculate vessel to loops green functions...
	do i=1,kloop
	call is_ves(f,rl(i),zl(i))
	if(kpr.eq.1)print *,' i rl zl==ncam ',i,rl(i),zl(i),ncam

	do j=1,ncam
	vesgreen(i,j)=f(j)
	end do
	end do
	apr='ves gre'
	do i=1,kloop
	if(kpr.eq.1)print *,'iloop',i
	if(kpr.eq.1)print 71,apr,(vesgreen(i,j),j=1,ncam)
	end do
71	format(20x,a6/,(6(1x,1pe10.3)))
	return
	end
c

	subroutine imas_probes()
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	include 'parf1'
	include 'parf4'
	common
     *  /ge1/pi
     *  /ge5/kpr
	common
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf3/nmx(kf),turn(kf)
	common
     *  /probe1/kprobe,bprobe(nprobe)
     *  /probe2/pfprobe(nprobe,kf),vesprobe(nprobe,mu)
     *  /probe3/kpb,Rprobe(nprobe,npb),
     *  Zprobe(nprobe,npb),cosa(nprobe),sina(nprobe)
      common
     *  /c_probe3/r_prob(nprobe),z_prob(nprobe),
     *  anglep(nprobe),smp(nprobe)
c
	dimension f(mu),f0(kf)
	DIMENSION BRR(mu),BZZ(mu),pfprobe1(nprobe,kf)
	character *8 apr
	CHARACTER*120 fshot,tmp
cc



	do i=1,kprobe
!	anglep(i)=anglep(i)*pi/180.
	rprobe(i,1)=r_prob(i)*1.e2
	zprobe(i,1)=z_prob(i)*1.e2
	smp(i)=smp(i)*1.e2
	end do
c
	do i=1,kprobe
	do j=1,ncam
	vesprobe(i,j)=0.
	end do
	do k=1,npf
	pfprobe(i,k)=0.
	end do
	end do

	apr='r probe'
	if(kpr.eq.1)print 71,apr,(rprobe(i,1),i=1,kprobe)
	apr='z probe'
	if(kpr.eq.1)print 71,apr,(zprobe(i,1),i=1,kprobe)
	apr='angle'
	if(kpr.eq.1)print 71,apr,(anglep(i),i=1,kprobe)
	apr='smp'
	if(kpr.eq.1)print 71,apr,(smp(i),i=1,kprobe)

	do i=1,kprobe
	cosa(i)=cos(anglep(i))
	sina(i)=sin(anglep(i))
	r1=rprobe(i,1)-smp(i)/2.*cosa(i)
	z1=zprobe(i,1)-smp(i)/2.*sina(i)
c
c
	do j=1,kpb
	rprobe(i,j)=r1+(j-1.)/(kpb-1.)*smp(i)*cosa(i)
	zprobe(i,j)=z1+(j-1.)/(kpb-1.)*smp(i)*sina(i)
c
c  ------------------------------
c   calculate vessel to probe unit field...
c-----------------------
	call bisa_ves(brr,bzz,rprobe(i,j),zprobe(i,j))
	do k=1,ncam
	vesprobe(i,k)=vesprobe(i,k)+(brr(k)*cosa(i)+bzz(k)*sina(i))/kpb
	end do
c
c  ------------------------------
c   calculate PF  to probe unit field...
c-----------------------
      
	call bisa(brr,bzz,rprobe(i,j),zprobe(i,j))
	do k=1,npf
	pfprobe(i,k)=pfprobe(i,k)+(brr(k)*cosa(i)+
     *  bzz(k)*sina(i))/kpb
	end do

	end do
	end do
c***********************
	apr='r probe'
c	do i=1,kprobe
c	if(kpr.eq.1)print *,'iprobe',i
c	if(kpr.eq.1)print 71,apr,(rprobe(i,j),j=1,kpb)
c	end do
c	apr='z probe'
c	do i=1,kprobe
c	if(kpr.eq.1)print *,'iprobe',i
c	if(kpr.eq.1)print 71,apr,(zprobe(i,j),j=1,kpb)
c	end do
	apr='anglep'
c	if(kpr.eq.1)print 71,apr,(anglep(i),i=1,kprobe)
	apr='smp'
c	if(kpr.eq.1)print 71,apr,(smp(i),i=1,kprobe)
	do i=1,kprobe
	if(kpr.eq.1)print *,'iprobe',i
	apr='pfprobe'
	if(kpr.eq.1)print 71,apr,(pfprobe(i,j),j=1,npf)
	apr='ves pr'
	if(kpr.eq.1)print 71,apr,(vesprobe(i,j),j=1,ncam)
	end do

!      stop
      
c
71	format(20x,a8/,(6(1x,1pe10.3)))
72	format(20x,a8/,(3(3x,1pe10.3,1x,1pe10.3)))
	return
	end

      
