      subroutine mag_axis(imax_xx,jmax_xx)
	include 'double.inc'
      include 'new_com.inc'

      call mag_axis_c(imax_xx,jmax_xx,x,y,psi,nr,nz,
     *  rmag,zmag,pmag,dx,dy)

      return
      end

      subroutine mag_axis_c(imax,jmax,r,z,u,nr,nz,
     *  rm,zm,um,dx,dy)

	include 'double.inc'
      dimension r(nr),z(nz),u(nr,nz)

c---definition of Um - poloidal flux function value on magn. axes.

          parameter(nshp=10)

          real*8 xs(nshp),ys(nshp),fun(nshp),dp(5),dp1(5),dp2(5)

          data errt/1.e-14/

          imax1=(1.0+errt)*(1.0+(rm-r(1))/dx)
          jmax1=(1.0+errt)*(1.0+(zm-z(1))/dy)

!          if(kpr.eq.1)print *,' imax imax1 rm ',imax,imax1,rm
!          if(kpr.eq.1)print *,' jmax jmax1 zm ',jmax,jmax1,zm


          nsh=1
          xs(nsh)=r(imax)
          ys(nsh)=z(jmax)
         fun(nsh)=u(imax,jmax)

        do 200 k=-1,1

          i= imax+k

        do 210 l=-1,1

          j= jmax+l

          if(i.eq.imax .AND. j.eq.jmax) go to 210
          nsh=nsh+1
          xs(nsh)=r(i)
          ys(nsh)=z(j)
         fun(nsh)=u(i,j)

 210    continue
 200    continue

      k_stop=0
      
	do i=2,nsh
	if(fun(i).ge.fun(1))then
	rm=xs(1)
	zm=ys(1)
	um=fun(1)
	
!	if(kpr.eq.1)print *,' i fun fun(1)=',i,fun(i),fun(1)
	
	k_stop=1
	
!	return
	end if

	end do

      
      if(k_stop.eq.1)then
      
      if(kpr.eq.1)print *,' kstop=1 from PET',kstop
      stop
      end if
        

          call deriv5(xs,ys,fun,nsh,5,dp)

        DET = dp(3)*dp(5) - dp(4)**2
          rmold=rm
          zmold=zm
        Rm = Xs(1) + ( dp(2)*dp(4) - dp(1)*dp(5) )/DET
        Zm = Ys(1) + ( dp(1)*dp(4) - dp(2)*dp(3) )/DET

          errm=sqrt( (rm-rmold)**2+(zm-zmold)**2 )

           rmi=r(imax)
           zmj=z(jmax)

           umold=um

       um=fun(1)+ dp(1)*(rm-rmi) + dp(2)*(zm-zmj)
     +          + 0.5*dp(3)*(rm-rmi)*(rm-rmi)
     +          +     dp(4)*(rm-rmi)*(zm-zmj)
     +          + 0.5*dp(5)*(zm-zmj)*(zm-zmj)


c       if(kpr.eq.1)print *,' fun from PET',(fun(i),i=1,nsh)
        if(kpr.eq.1)print *,' rm zm um umold from PET',rm,zm,um,umold


       return
       end
        SUBROUTINE DERIV5(X,Y,F,M,N,U)
C
C...    DEFINITON OF THE FIRST AND SECOND DERIVATIONS.
C
C
        IMPLICIT REAL*8(A-H,O-Z)
C
        DIMENSION X(1),Y(1),F(1),U(1)
        DIMENSION A(5,5),B(5),S(5)
        DIMENSION AA(5,5),W1(5),W2(5)
        DIMENSION IP(5)
C
         SQRT(R)=DSQRT(R)
C
C
            SDX2  = 0.
            SDY2  = 0.
            SDXDY = 0.
            SDX3  = 0.
            SDX2DY= 0.
            SDXDY2= 0.
            SDY3  = 0.
            SDX4  = 0.
            SDX3DY= 0.
            SDX2Y2= 0.
            SDXDY3= 0.
            SDY4  = 0.
C
            DAVER2= 0.
C
            FDX   = 0.
            FDY   = 0.
            FDX2  = 0.
            FDXDY = 0.
            FDY2  = 0.
C
C  THE MAIN LOOP
C
         DO 1 I=2,M
            DX=X(I)-X(1)
            DY=Y(I)-Y(1)
            DF=F(I)-F(1)
            DX2=DX*DX
            DY2=DY*DY
C
            SDX2  =SDX2   + DX2
            SDY2  =SDY2   + DY2
            SDXDY =SDXDY  + DX   *DY
            SDX3  =SDX3   + DX2  *DX
            SDX2DY=SDX2DY + DX2  *DY
            SDXDY2=SDXDY2 + DX   *DY2
            SDY3  =SDY3   + DY2  *DY
            SDX4  =SDX4   + DX2  *DX2
            SDX3DY=SDX3DY + DX2  *DX  *DY
            SDX2Y2=SDX2Y2 + DX2  *DY2
            SDXDY3=SDXDY3 + DX   *DY2 *DY
            SDY4  =SDY4   + DY2  *DY2
C
            DAVER2=DAVER2 + DX2  +   DY2
C
            FDX   =FDX    + DF   *DX
            FDY   =FDY    + DF   *DY
            FDX2  =FDX2   + DF   *DX2
            FDXDY =FDXDY  + DF   *DX  *DY
            FDY2  =FDY2   + DF   *DY2
C
 1       CONTINUE
C
C   THE CREATION THE MATRIX A:
C
         A(1,1) = SDX2
         A(1,2) = SDXDY
         A(1,3) = SDX3   * 0.5
         A(1,4) = SDX2DY
         A(1,5) = SDXDY2 * 0.5
         A(2,1) = SDXDY
         A(2,2) = SDY2
         A(2,3) = SDX2DY * 0.5
         A(2,4) = SDXDY2
         A(2,5) = SDY3   * 0.5
         A(3,1) = SDX3
         A(3,2) = SDX2DY
         A(3,3) = SDX4   * 0.5
         A(3,4) = SDX3DY
         A(3,5) = SDX2Y2 * 0.5
         A(4,1) = SDX2DY
         A(4,2) = SDXDY2
         A(4,3) = SDX3DY * 0.5
         A(4,4) = SDX2Y2
         A(4,5) = SDXDY3 * 0.5
         A(5,1) = SDXDY2
         A(5,2) = SDY3
         A(5,3) = SDX2Y2 * 0.5
         A(5,4) = SDXDY3
         A(5,5) = SDY4   * 0.5
C
C   THE CREATION THE RIGHT HAND B:
C
         B(1) = FDX
         B(2) = FDY
         B(3) = FDX2
         B(4) = FDXDY
         B(5) = FDY2
C
C  THE WEIGHTS S(I):
C
         DAVER=SQRT(DAVER2)
C
         S(1) = 1./SQRT(SDX2)/DAVER
         S(2) = 1./SQRT(SDY2)/DAVER
         S(3) = 1./SDX2/DAVER
         S(4) = 1./SQRT(SDX2*SDY2)/DAVER
         S(5) = 1./SDY2/DAVER
C
         DO 2 I=1,N
         DO 3 J=1,N
            A(I,J)=S(I)*A(I,J)
 3       CONTINUE
            B(I)=S(I)*B(I)
 2       CONTINUE
C
C  THE SOLUTION THE MATRIX EQUATION AU=B.
C
         IFAIL=0
C
ccccc    CALL F04ATF(A,5,B,N,U,AA,5,W1,W2,IFAIL)
         CALL GE(5,5,A,B,U,IP)
C
ccccc    IF( IFAIL .NE. 0 ) WRITE (6,*)' IFAIL= ',IFAIL
C
         RETURN
         END

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        SUBROUTINE GE(N,NZ,A,X,Y,IP)
C
C...    GAUSS ELIMINATION
C
        IMPLICIT REAL*8(A-H,O-Z)
C
        DIMENSION A(NZ,NZ),X(N),Y(N),IP(N)
C
        ABS(XARG)=DABS(XARG)
C
        DO 90 I=1,N
          IP(I)=I
 90     CONTINUE
C
        DO 100 I=1,N-1
C...      MAX ROW ELEMENT SEARCH
          RM=ABS(A(I,I))
          JM=I
          DO 101 J=I,N
            ABA=ABS(A(I,J))
            IF(ABA.GT.RM) THEN
              RM=ABA
              JM=J
            ENDIF
 101      CONTINUE
C...      PERMUTATIONS
          IPE=IP(I)
          IP(I)=IP(JM)
          IP(JM)=IPE
          DO 102 K=1,N
            APE=A(K,I)
            A(K,I)=A(K,JM)
            A(K,JM)=APE
 102      CONTINUE
          AD=1./A(I,I)
          DO 100 K=I+1,N
            AM=A(K,I)*AD
            X(K)=X(K)-AM*X(I)
            DO 100 J=I,N
              A(K,J)=A(K,J)-AM*A(I,J)
 100    CONTINUE
C
        Y(N)=X(N)/A(N,N)
        DO 200 I=N-1,1,-1
          AD=1./A(I,I)
          Y(I)=X(I)
          DO 201 J=N,I+1,-1
            Y(I)=Y(I)-A(I,J)*Y(J)
 201      CONTINUE
          Y(I)=Y(I)*AD
 200    CONTINUE
C
C...    BACK PERMUTATION
        DO 300 I=1,N
          X(IP(I))=Y(I)
 300    CONTINUE
        DO 400 I=1,N
          Y(I)=X(I)
 400    CONTINUE
C
        RETURN
        END


      subroutine b_temp()
      include 'double.inc'
      include 'new_com.inc'

      call b_temp_c(
     *  nr,nz,pspl,ui)

      return
      end

      subroutine b_temp_c(
     *  nr,nz,pspl,ui)
        include 'double.inc'
      dimension pspl(*),ui(nr,nz)
	k=0

        m1=nz-1
        n1=nr-1

	DO I=1,nr
	DO J=1,nz,M1
	k=k+1
	kk2=(i-1)*nz+j
        al1=pspl(kk2)/ui(i,j)
c	if(kpr.eq.1)print *,' al1 pspl ui',al1,pspl(kk2),ui(i,j)
        pspl(kk2)=ui(i,j)
	end do
	end do
c
C
	DO I=1,nr,N1
	DO J=1,nz
	k=k+1
	kk2=(i-1)*nz+j
        al1=pspl(kk2)/ui(i,j)
c 	if(kpr.eq.1)print *,' al1 pspl ui',al1,pspl(kk2),ui(i,j)
        pspl(kk2)=ui(i,j)
c
	END DO
	END DO

      return
      end


	subroutine g_calc(al1_xx,f_xx)
	include 'double.inc'
        include 'new_com.inc'

        dimension f_xx(*)

	call g_calc_c(al1_xx,f_xx,
     *  x,nr,nz,
     *  work,sib,g,nwnh)
        
        return
        end
        
	subroutine g_calc_c(al1,f,
     *  x,nr,nz,
     *  work,sib,g,nwnh)
        include 'double.inc'
	dimension f(*)

	dimension x(*),work(*),sib(*),g(nr,nz)

	common
     *	/bunemn/nww,nhh,drdz2,rgrid1,delr,delz

c   CALCULATE g function..
c
	n1=nr-1
	m1=nz-1

c        if(kpr.eq.1)print *,' al1 n1 m1 nwnh delz ',al1,n1,m1,nwnh,delz

	DO I=1,nr
c           if(kpr.eq.1)print *,' i x ===',i,x(i)
	DO J=1,nz
	kk=(i-1)*nz+j
	work(kk)=-f(kk)*al1*X(I)
	END DO
	END DO
c
	DO I=1,nr
	DO J=1,nz,M1
	kk=(i-1)*nz+j
	sib(kk)=0.
	end do
	end do
c
	DO I=1,nr,N1
	DO J=1,nz
	kk=(i-1)*nz+j
	sib(kk)=0.
	end do
	end do
c
	do i=2,n1
	do j=2,m1
	kk=(i-1)*nz+j
	sib(kk)=0.5*work(kk)*delz**2
	end do
	end do

c        if(kpr.eq.1)print *,' bunema * '

	call buneto(sib,nr,nz,work,nwnh)

c        if(kpr.eq.1)print *,' after bunema * '
C

	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	g(i,j)=-sib(kk)
	end do
	end do

	return
	end

      subroutine bound_pet()
      include 'double.inc'
      include 'new_com.inc'

      call bound_pet_c(
     *  x,nr,nz,dx,dy,
     *  dgdn,g,green_b,nbnd,
     *  psi_bound,ui)

      return
      end

      subroutine bound_pet_c(
     *  r,ni,nj,dr,dz,
     *  dgdn,g,green_b,nbnd,
     *  psib,ui)
        include 'double.inc'

      dimension r(ni),dgdn(*),g(ni,nj),
     *  green_b(nbnd,nbnd),psib(*),ui(ni,nj)

c--- array dgdn initialization (calculation dg/dn)

        real *8 zpsi

        ni1=ni-1
        nj1=nj-1


        ib=1

        dgdn(ib)=0.d0
        g(1,1)=0.d0

        do 10 i=2,ni1

        ib=ib+1
c  FROM PET...        dgdn(ib) = g(i,2)/dz(1)/r(i)
        dgdn(ib) = g(i,2)/(dz*r(i))
        g(i,1)=0.d0

 10     continue

        ib=ib+1
        dgdn(ib)=0.d0
        g(ni,1)=0.d0

        r12=0.5*(r(ni)+r(ni1))

        do 20 j=2,nj1

        ib=ib+1
c  FROM PET...         dgdn(ib) = g(ni1,j)/( dr(ni1)*r12(ni1))
        dgdn(ib) = g(ni1,j)/(dr*r12)

        g(ni,j)=0.d0

 20     continue

        ib=ib+1
        dgdn(ib)=0.d0
        g(ni,nj)=0.d0

        do 30 i=ni1,2,-1

        ib=ib+1
c FROM PET...        dgdn(ib) = g(i,nj1)/dz(nj1)/r(i)
        dgdn(ib) = g(i,nj1)/(dz*r(i))
        g(i,nj)=0.d0

 30     continue

        ib=ib+1
        dgdn(ib)=0.d0
        g(1,nj)=0.d0

        r12=0.5*(r(1)+r(2))

        do 40 j=nj1,2,-1

        ib=ib+1

c  FROM PET...        dgdn(ib) = g(2,j)/(dr(1)*r12(1))
        dgdn(ib) = g(2,j)/(dr*r12)
        g(1,j)=0.d0

 40     continue

        ib=ib+1
        dgdn(ib)=0.d0

        do 100 ib=1,nbnd
        dgdn(ib)= (dgdn(ib)+dgdn(ib+1))*0.5
 100    continue

        do 110 ib=1,nbnd
         zpsi=0.d0
         do 111 ibc=1,nbnd

         zpsi= zpsi+dgdn(ibc)*green_b(ibc,ib)

 111    continue

        psib(ib)=zpsi

 110    continue

c...boundary condition for ui

        ib=0

        do 200 i=1,ni

        ib=ib+1
        ui(i,1)=psib(ib)

 200    continue


        do 300 j=2,nj

        ib=ib+1
        ui(ni,j)=psib(ib)

 300    continue

        do 210 i=ni1,1,-1

        ib=ib+1
        ui(i,nj)=psib(ib)

 210    continue

        do 310 j=nj1,2,-1

        ib=ib+1
        ui(1,j)=psib(ib)

 310    continue

        return
        end

         subroutine bndmat()
         include 'double.inc'
         include 'new_com.inc'
      
         call bndmat_c(
     *  x,y,nr,nz,dx,dy,pi,coef_pet,
     *  x_bb,y_bb,green_b,nbnd)
         
         return
         end

         subroutine bndmat_c(
     *  r,z,ni,nj,dr,dz,pi,coef_pet,
     *  xk,yk,green_b,nbnd)

	include 'double.inc'
c      implicit real *8 (a-h,o-z)
c        include 'double_pet_1.inc'

      dimension r(ni),z(nj),
     *  xk(*),yk(*),green_b(nbnd,nbnd)

      real *8 rr,zz,R0,Z0,r1,z1,Fint

c
        ni1=ni-1
        nj1=nj-1
c
        ib=1


        xk(ib)=r(1)
        yk(ib)=z(1)

c        if(kpr.eq.1)print *,' ib xk yk r z ',ib,xk(ib),yk(ib),r(1),z(1)

        do 10 i=2,ni1

        ib=ib+1
        xk(ib)=r(i)
        yk(ib)=z(1)

c        if(kpr.eq.1)print *,' ib xk yk r z ',ib,xk(ib),yk(ib),r(i),z(1)

 10     continue

        ib=ib+1
        xk(ib)=r(ni)
        yk(ib)=z(1)

c        if(kpr.eq.1)print *,' ib xk yk r z ',ib,xk(ib),yk(ib),r(ni),z(1)

        do 20 j=2,nj1

        ib=ib+1
        xk(ib)=r(ni)
        yk(ib)=z(j)
c        if(kpr.eq.1)print *,' ib xk yk r z ',ib,xk(ib),yk(ib),r(ni),z(j)

 20     continue

        ib=ib+1
        xk(ib)=r(ni)
        yk(ib)=z(nj)

c        if(kpr.eq.1)print *,' ib xk yk r z ',ib,xk(ib),yk(ib),r(ni),z(j)

        do 30 i=ni1,2,-1

        ib=ib+1
        xk(ib)=r(i)
        yk(ib)=z(nj)

c        if(kpr.eq.1)print *,' ib xk yk r z ',ib,xk(ib),yk(ib),r(i),z(nj)

 30     continue

        ib=ib+1
        xk(ib)=r(1)
        yk(ib)=z(nj)

c        if(kpr.eq.1)print *,' ib xk yk r z ',ib,xk(ib),yk(ib),r(1),z(j)

        do 40 j=nj1,2,-1

        ib=ib+1
        xk(ib)=r(1)
        yk(ib)=z(j)

c        if(kpr.eq.1)print *,' ib xk yk r z ',ib,xk(ib),yk(ib),r(1),z(j)

 40     continue

        ib=ib+1
        xk(ib)=r(1)
        yk(ib)=z(1)

c        if(kpr.eq.1)print *,' ib xk yk r z ',ib,xk(ib),yk(ib),r(1),z(1)

        if(kpr.eq.1)print *,' nbnd===',nbnd

        nbnd_c=ib


        do ib=1,nbnd
        rr=xk(ib)
        zz=yk(ib)
        do 100 ibc=1,nbnd

        r0=xk(ibc)
        z0=yk(ibc)

        r1=xk(ibc+1)
        z1=yk(ibc+1)

c        if(kpr.eq.1)print *,' ib ibc rr zz r0 z0 r1 z1 ',ib,ibc,rr,zz,r0,z0,r1,z1

        call bint(rr,zz,R0,Z0,r1,z1,Fint,1)

        green_b(ibc,ib)=fint

 100    continue
	  
   	 ibc=5

c        if(kpr.eq.1)print *,' ib ibc green_b(ibc,ib) ',ib,ibc,green_b(ibc,ib)

	
	end do

        return
        end


C  GREEN'S FUNCTION FOR TOROIDAL CURRENT LOOP IN INFINITY AREA.
C
      FUNCTION GREENI(R,Z,RP,ZP)
C
	include 'double.inc'
c      IMPLICIT REAL*8(A-H,O-Z)
c       include 'double_pet_2.inc'

	real *8 greeni,R,Z,RP,ZP

	parameter(pi=3.14159265358d0)

	coef_pet=4.d0*pi/5.d0

c	coef_pet=2.5

	rr=r
	rrk=rp
	zz=z
	zzk=zp
C
      GREENI =fp(rr,rrk,zz,zzk)/coef_pet
C
      RETURN
      END
C
C********************************************************************
      SUBROUTINE bint(X,Y,R0,Z0,r1,z1,F,I)
      IMPLICIT REAL*8(A-H,O-Z)
C
C===============FUNCTIONS===============FUNCTIONS================C
C
c$      SQRT(X)=DSQRT(X)
c$      ALOG(X)=DLOG(X)
C
C======================SPECIAL FUNCTIONS=========================C
C
      D(X1,Y1,X2,Y2)=  DSQRT( (X1-X2)**2 + (Y1-Y2)**2 )
C
      TINT(T)=(T-PSCAL)*(0.5*DLOG(PVEC**2+(T-PSCAL)**2+EPS**2)-1.) +
     +         PVEC*DATAN((T-PSCAL)/(PVEC+EPS))
C
C===============FUNCTIONS===============FUNCTIONS================C
C
      EPSH=1.E-8
      F=0.

        W=0.
        H=D(R0,Z0,R1,Z1)
        EPS=EPSH*H
C
C  INTEGRAL ALONG THE EDGE OF REGION
C
        RM=0.5*(R0+R1)
        ZM=0.5*(Z0+Z1)
        DTM=D(X,Y,RM,ZM)
        DFM=D(-X,Y,RM,ZM)
C
        IF( I .NE. 0 ) THEN
C
          PSCAL=( (-X-R0)*(R1-R0) + (Y-Z0)*(Z1-Z0) )/H
          PVEC= ( (-X-R0)*(Z1-Z0) - (Y-Z0)*(R1-R0) )/H
C
          W = TINT(H)-TINT(0.D0)
C
          PSCAL=( (X-R0)*(R1-R0) + (Y-Z0)*(Z1-Z0) )/H
          PVEC= ( (X-R0)*(Z1-Z0) - (Y-Z0)*(R1-R0) )/H
C
          W = W - (TINT(H)-TINT(0.D0))
C
          IF( DTM .LT. 0.25*H ) THEN
              DFJ =D(-X,Y,R0,Z0)
              DFJ1=D(-X,Y,R1,Z1)
              DTJ =D( X,Y,R0,Z0)
              DTJ1=D( X,Y,R1,Z1)
C
C+++          W = W - H * ALOG( DFJ*DFJ1/(D(X,Y,R0,Z0)*D(X,Y,R1,Z1)) )
C
              W = W*DFM - 0.5*H*(DLOG(DFJ/DTJ)*DFJ+DLOG(DFJ1/DTJ1)*DFJ1)
C
           ELSE
C
C+++          W = W - H * ALOG( DFM / DTM )
C
              W = ( W - H * DLOG( DFM / DTM ) ) * DFM
C
           ENDIF
         ENDIF
C
        IF( DTM .LT. 0.25*H ) THEN
C
            E  = 0.5 * ( GREENI(X,Y,R0,Z0) + GREENI(X,Y,R1,Z1) )
C
        ELSE
C
            E  =  GREENI(X,Y,RM,ZM)
C
        ENDIF
C
        F =  E*H + 0.25D0*W
C
      F = F /3.14159265358
C
       RETURN
      END








