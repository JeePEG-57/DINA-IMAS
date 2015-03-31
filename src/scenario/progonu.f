	subroutine progb(y,a,b,c,f,alfa,beta,n,
     *  i_b,x1,x2,x3)

	implicit real * 8 (a-h,o-z)
	dimension y(n),a(n),b(n),c(n),f(n),alfa(n),beta(n)


c------------------------

c	print *,' i_b=',i_b

        if(i_b.eq.3)then
	   x1=1.
	   x2=-alfa(n-1)
	   x3=beta(n-1)
        end if

	do i=2,n-1

	d1=1./(b(i)+a(i)*alfa(i-1))

	alfa(i)=-c(i)*d1

	beta(i)=(f(i)-a(i)*beta(i-1))*d1

	end do
c

        if(i_b.eq.3)then

        det=(x1*alfa(n-1)+x2)

        if(dabs(det).le.1.d-14)then
           print *,' det le 1.e-14',det
           stop
        end if

        y(n)=(x3-x1*beta(n-1))/det
        
        end if

	do i=n-1,1,-1
	y(i)=alfa(i)*y(i+1)+beta(i)
	end do

	return
	end

      SUBROUTINE PROGP(N,A,B,C,TT1,ALF,U,B0,T,
     *Z,W,F,ZN,UN,EPS0,LL)
c-------------------------------------------------
c calculate tridiagonal matrix in particle transport
c----------------------------------------------

	include 'double.inc'
c       implicit real*8 (a-h,o-z)
      common
     *  /ge5/kpr
      DIMENSION A(N),B(N),C(N),TT1(N),ALF(N),
     *U(N),B0(N),T(N),Z(N),W(N),F(N)
      U(2)=0.
      Z(2)=0. 
      D1=0.
      N2=N-1
      DO 1 I=2,N2
      R1=A(I)+B(I)+C(I)
      E1=C(I)/ALF(I+1)+TT1(I)
      IF(abs(E1).GT.EPS0)GOTO 5
      if(kpr.eq.1)PRINT 6,E1
    6 FORMAT(20X,'E1 MALO PROGP **',E10.3)
	stop
    5 CONTINUE
      IF(I.NE.2)D1=A(I)/ALF(I)+TT1(I)
      G1=D1*U(I)-R1
      BB=1./(E1+G1/ALF(I+1))
      U(I+1)=BB*G1
      Z(I+1)=BB*(F(I)+D1*Z(I))
    1 CONTINUE
      IF(LL.NE.3)GO TO 9
      T(N)=(ZN-Z(N))/(U(N)-UN)
    9 CONTINUE
      W(N)=U(N)*T(N)+Z(N)
      DO 101 K=3,N
      I=N-K+3
      T(I-1)=T(I)-W(I)/alf(i)
  101 W(I-1)=U(I-1)*T(I-1)+Z(I-1)
      RETURN
      END
      SUBROUTINE PROGPM(N,ZN,UN,LL,M,M1)
c------------------------------------------
c  tridiagonal matrix in energy
c------------------------------------------
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	include 'parf0'
	PARAMETER(nu=npo)
        common
     *  /ge5/kpr
	common 
     *  /en3/ A(nu,4),B(nu,4),C(nu,4),
     *  TT1(nu,4),ALF(nu,4),
     *  U(nu,4),T(nu,2),Z(nu,2),W(nu,2),F(nu,2)
c
	DIMENSION ALM1(4),ALG(4),ALG1(4),UU(4),AA(4),
     *  CC(4),RR(4),DD(4),EE(4),SUM(4),sum2(4),GG(4),
     *  GG1(4),SS(2),TT(2),WW(2),
     *  VV(4),VV1(4),FF(2),ZZ(2)
c
	DIMENSION ZN(2),UN(4)
c
      DO 11 J=1,4
      U(2,J)=0.
   11 ALG1(J)=0.
      ZZ(1)=0. 
      ZZ(2)=0.
      N2=N-1
      DO 1 I=2,N2
      DO 13 J=1,4
      RR(J)=A(I,J)+B(I,J)+C(I,J)
      CC(J)=C(I,J)
      AA(J)=A(I,J)
      ALG(J)=ALF(I+1,J)
      ALM1(J)=ALG1(J)
      UU(J)=U(I,J)
   13 CONTINUE
      DO 16  J=1,2
      FF(J)=F(I,J)
      ZZ(J)=Z(I,J)
   16 CONTINUE
      CALL OBR(ALG1,ALG)
      DO 14 J=1,4
   14 ALF(I+1,J)=ALG1(J)
      CALL YMH(DD,AA,ALM1)
      CALL YMH(EE,CC,ALG1)
      DO 15 J=1,4
      EE(J)=EE(J)+TT1(I,J)
   15 DD(J)=DD(J)+TT1(I,J)
      CALL YMH(SUM2,dd,UU)
	do j=1,4
	sum(j)=sum2(j)-rr(j)
	end do
      CALL YMH(SUM2,sum,alg1)
      DO 18  J=1,4
   18 VV(J)=Ee(J)+SUM2(J)
      CALL  OBR(VV1,VV)
      CALL YMHB(SS,dd,zz)
      DO 21 J=1,2
21    ss(J)=SS(J)+ff(J)
      CALL YMHB(zz,vv1,ss)
      CALL YMH(uu,vv1,SUM)
	do j=1,4
	u(i+1,j)=uu(j)
	end do
	do j=1,2
	z(i+1,j)=zz(j)
	end do
    1 CONTINUE
      IF(LL.NE.3)GO  TO 9
      DO 28 J=1,4
	uu(j)=u(n,j)
   28 GG(J)=UN(J)-UU(J)
      CALL OBR(GG1,GG)
      DO 29 J=1,2
   29 ZZ(J)=Z(N,J)-ZN(J)
      CALL YMHB(TT,GG1,ZZ)
      DO 30 J=1,2
  30  T(N,J)=TT(J)
    9 CONTINUE
	do j=1,4
	uu(j)=u(n,j)
	end do
	do j=1,2
	tt(j)=t(n,j)
	end do
	call YMHB(ss,uu,tt)
	do j=1,2
	w(n,j)=ss(j)+z(n,j)
	end do
      DO 101 K=3,N
      I=N-K+3
	do j=1,2
	ww(j)=w(i,j)
	end do
      DO 32 J=1,4
      ALG1(J)=ALF(I,J)
   32 UU(J)=U(I,J)
      CALL YMHB(SS,alg1,ww)
	do j=1,2
	zz(j)=z(i-1,j)
	tt(j)=t(i,j)-ss(j)
	end do
	do j=1,4
	uu(j)=u(i-1,j)
	end do
	call ymHB(ss,uu,tt)
      DO 34 J=1,2
	ww(j)=ss(j)+zz(j)
	t(i-1,j)=tt(j)
   34 W(I-1,J)=ww(J)
  101 CONTINUE
      RETURN
      END
      SUBROUTINE YMH(A,C,D)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
      DIMENSION A(4),C(4),D(4)
      A(1)=C(1)*D(1)+C(2)*D(3)
      A(2)=C(1)*D(2)+C(2)*D(4)
      A(3)=C(3)*D(1)+C(4)*D(3)
      A(4)=C(3)*D(2)+C(4)*D(4)
      RETURN
      END
      SUBROUTINE YMHB(C,A,B)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
      DIMENSION C(2),A(4),B(2)
      C(1)=A(1)*B(1)+A(2)*B(2)
      C(2)=A(3)*B(1)+A(4)*B(2)
      RETURN
      END
      SUBROUTINE OBR(B,A)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
      common
     *  /ge5/kpr
      DIMENSION A(4),B(4)
	data eps/1.e-18/
      DEL=A(1)*A(4)-A(2)*A(3)
      IF(abs(DEL).GT.EPS)GO TO 1
      if(kpr.eq.1)PRINT 2,DEL
	stop
    2 FORMAT(20X,'EI MALO MATRIX',E10.3)
    1 B(1)=A(4)/DEL
      B(2)=-A(2)/DEL
      B(3)=-A(3)/DEL
      B(4)=A(1)/DEL
      RETURN
      END




