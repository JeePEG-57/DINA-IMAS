       SUBROUTINE POLAR1(n,m,rs0,kp,pt01)
	implicit real*8 (a-h,o-z)
	include 'parf0'
      COMMON /pol1/ RO(npo,ntet),AJ(npo,ntet)
      COMMON /pol2/ Q(npo),ANU(npo),P(npo),F(npo),
     *PP(npo),PFF(npo)
      COMMON /pol3/ A(npo),TET(ntet),HA(npo),HT(ntet)
      COMMON /pol4/ UM,VM,UK(ntet),VK(ntet)
	common /pol5/psend
	common
     *  /ge1/pi
     *  /ge5/kpr
c=======================================================
        include 'double_pp0_1.inc'
c==================================================
c
	dimension Y(ntet),Y0(ntet)
	dimension RAJH(ntet),RAJH0(ntet)
	dimension AU(ntet),BU(ntet),CU(ntet),FU(ntet)
	dimension DRQ0(ntet),HAAJ0(ntet),HATJ0(ntet),FI0(ntet)
C
      DIMENSION HAAJ(ntet),HATJ(ntet),FI(ntet)
C
     *,UR(NPO,NTET),VZ(NPO,NTET),UC(NPO,NTET),VC(NPO,NTET),
     * UT1(NPO,NTET),VT1(NPO,NTET),UT(NPO,NTET),VT(NPO,NTET),
     * DS(NPO,NTET),UA1(NPO,NTET),VA1(NPO,NTET),UA(NPO,NTET),
     * VA(NPO,NTET)
      DIMENSION DRR(ntet),DRQ(ntet)
      DIMENSION ROSG(npo),e2(npo,ntet)
	character *4 ma
c
	n1=n-1
	m1=m-1
	kpp=1
	kpf=1
	dr=0.5
	anun=1.
	eps=5.e-4
	epsk=5.e-4
	nht=9
	alfa0=1.
	tetm=2.*pi
	q(1)=q(2)
c	
C
c      US=1./DKRI0
cc      us=2*rs0
	us=rs0
      NPW=0
      NH=0
C      By~iClEHiE plO}Adi KOvYXA
      UK(M)=UK(2)  
      UK(1)=UK(M1)
      VK(M)=VK(2)  
      VK(1)=VK(M1)
      SP=0.
      DO 710 J=2,M1
      SP=SP+UK(J)*(VK(J+1)-VK(J-1))
  710 CONTINUE
      SP=SP*0.5
C
c      KP=KPP*KPF
c	if(kpr.eq.1)print*,'kp=',kp
C
C----------------------------------------------------------------------
C
1001	CONTINUE
C      HA~AlO PAC~ETA
C
c	
c	if(anun.gt.0.1)alfa0=0.5*(alfa0/anun+alfa0)
      NS=0
      NS1=0
      NST=3
      DE1=0.
      DE2=0.	
      DE3=0.
      DE5=0.
C      OKAjMlEHiE
      DO 9 I=1,N
      RO(I,M)=RO(I,2)  
      RO(I,1)=RO(I,M1)
      AJ(I,M)=AJ(I,2)  
      AJ(I,1)=AJ(I,M1)
  9   CONTINUE
      DO 19 J=2,M1
      DRR(J)=DR*
     *    SQRT(((UK(J)+UK(J-1))*0.5-UM)**2+
     *((VK(J)+VK(J-1))*0.5-VM)**2)
 19   CONTINUE
C-----------------------------------------------------------------------
C
C
C
C  HA~AlxHyj {Ag: OpPEdElEHiE Y(1.5,J), I=2
C
	DO I=1,N
	DO J=1,M
      UR(I,J)=UM+RO(I,J)*(UK(J)-UM)
      VZ(I,J)=VM+RO(I,J)*(VK(J)-VM)
	END DO
	END DO
C
	DO I=2,N
	DO J=1,M
C
	UA1(I,J)=UR(I,J)-UR(I-1,J)
	VA1(I,J)=VZ(I,J)-VZ(I-1,J)
	END DO
	END DO
C
	DO I=1,N
	DO J=2,M
C
	UT1(I,J)=UR(I,J)-UR(I,J-1)
	VT1(I,J)=VZ(I,J)-VZ(I,J-1)
	END DO
	END DO
C
C
	DO I=2,N
	DO J=2,M
	UC(I,J)=0.25*(UR(I,J)+UR(I-1,J)+UR(I,J-1)+UR(I-1,J-1))
	VC(I,J)=0.25*(VZ(I,J)+VZ(I-1,J)+VZ(I,J-1)+VZ(I-1,J-1))
C
	UA(I,J)= UA1(I,J)+UA1(I,J-1) 
	VA(I,J)= VA1(I,J)+VA1(I,J-1) 
C
	UT(I,J)= UT1(I,J)+UT1(I-1,J) 
	VT(I,J)= VT1(I,J)+VT1(I-1,J) 
      DS(I,J)=UA(I,J)*VT(I,J)-VA(I,J)*UT(I,J)
	END DO
	END DO
	tok1=0.
	tok2=0.
      I=2
C
      DO 1 J=2,M1
       DDD=SQRT((UC(I,J)-UM)**2+(VC(I,J)-VM)**2)
      DRQ(J)=4.*HA(I)*DRR(J)*DDD/DS(I,J)
      A11=US/UC(I,J)
      A22=A11
      HATJ(J)=(-A11*VA(I,J)*VT(I,J)-A22*UA(I,J)*UT(I,J))/
     *DS(I,J)*HA(I)
      UT2=2.*(UT1(I,J)**2+UT1(I-1,J)**2)
      VT2=2.*(VT1(I,J)**2+VT1(I-1,J)**2)
      UVT=2.*(UT1(I,J)*VT1(I,J)+UT1(I-1,J)*VT1(I-1,J))
      HAAJ(J)=(A11*VT2+A22*UT2)/DS(I,J)*HA(I)
c	ppi=0.5*(pp(i)+pp(i-1))*alfa0
c	pffi=0.5*(pff(i)+pff(i-1))*alfa0
	ppi=pp(i)
	pffi=pff(i)
      FI(J)=-(PPI*UC(I,J)/US+kp*0.5*pffi*us/uc(i,j))*DS(I,J)*0.25
      tok2=tok2-(0.5*pffi*us/uc(i,j))*DS(I,J)*0.25
	tok1=tok1+fi(j)
C  QQQQQQQQQQ
      RAJH(J)=DS(I,J)/(UC(I,J)*4.*HA(I))
  1   CONTINUE
C
C  OKAjMlEHiE
      DRQ(1)=DRQ(M1)
      DRQ(M)=DRQ(2)
      HAAJ(1)=HAAJ(M1)
      HAAJ(M)=HAAJ(2)
      HATJ(1)=HATJ(M1)
      HATJ(M)=HATJ(2)
      FI(1)=FI(M1)
      FI(M)=FI(2)
C  QQQQQQQQQQQQQQQQQQQQQ
      RAJH(1)=RAJH(M1)
      RAJH(M)=RAJH(2)
      RSJ=0.
      DO 7 J=2,M1
      RSJ=RSJ+RAJH(J)
  7   CONTINUE
      RSJ=US/RSJ
C
C  HAXOdiM Y(1.5,J)
      SF=0.
      SD=0.
      DO 2 J=2,M1
      SF=SF+FI(J)
      SD=SD+HAAJ(J)
  2   CONTINUE
      SF=0.5*SF
      YY=SF/SD
c
	if (kp.eq.1)go to 1002
c
      QC=TETM*(Q(1)+Q(2))/2.*US
      QR=TETM*Q(2)*RSJ/US
      YY=ANU(2)
      F(2)=YY*QR
      F(1)=((SD+QC*QR)*YY-SF)/QC
1002  CONTINUE
C
C>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
C   TO~HOCTi   TO~HOCTi   TO~HOCTi <<<<<<<<<<<<<<<<<<
      DE5=dabs(1.-ANUN*ANU(2)/YY)
      DO 3 J=1,M
      Y(J)=YY
      AJ(I,J)=YY
  3   CONTINUE
C
C-----------------------------------------------------------------------
C
C  C~ET pO KAvdOj pOBEPXHOCTi A(I)=CONST, I=3,N
C
      DO 10 I=3,N
C
C  pEPEpPiCBAiBAHiE zHA~EHij, pOlY~EHHyX HA pPEdydY}Ej pOBEPXHOCTi
      DO   11 J=1,M
      DRQ0(J)=DRQ(J)
      HAAJ0(J)=HAAJ(J)
      HATJ0(J)=HATJ(J)
      FI0(J)=FI(J)
      Y0(J)=Y(J)
C  QQQQQQQQQQQQQQQQQQQQQ
      RAJH0(J)=RAJH(J)
 11   CONTINUE
C QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
      RSJ0=RSJ
C
C
      DO 12 J=2,M1
       DDD=SQRT((UC(I,J)-UM)**2+(VC(I,J)-VM)**2)
      DRQ(J)=4.*HA(I)*DRR(J)*DDD/DS(I,J)
      A11=US/UC(I,J)
      A22=A11
      HATJ(J)=(-A11*VA(I,J)*VT(I,J)-A22*UA(I,J)*UT(I,J))/
     *DS(I,J)*HA(I)
      UT2=2.*(UT1(I,J)**2+UT1(I-1,J)**2)
      VT2=2.*(VT1(I,J)**2+VT1(I-1,J)**2)
      UVT=2.*(UT1(I,J)*VT1(I,J)+UT1(I-1,J)*VT1(I-1,J))
      HAAJ(J)=(A11*VT2+A22*UT2)/DS(I,J)*HA(I)
c	ppi=0.5*(pp(i)+pp(i-1))*alfa0
c	pffi=0.5*(pff(i)+pff(i-1))*alfa0
	ppi=pp(i)
	pffi=pff(i)
      FI(J)=-(PPI*UC(I,J)/US+kp*0.5*pffi*us/uc(i,j))*DS(I,J)*0.25
      tok2=tok2-(0.5*pffi*us/uc(i,j))*DS(I,J)*0.25
	tok1=tok1+fi(j)
	if(i.eq.n)tok1=tok1-0.5*fi(j)
C  QQQQQQQQQQ
      RAJH(J)=DS(I,J)/(UC(I,J)*4.*HA(I))
 12   CONTINUE
C
C  OKAjMlEHiE
      DRQ(1)=DRQ(M1)
      DRQ(M)=DRQ(2)
      HAAJ(1)=HAAJ(M1)
      HAAJ(M)=HAAJ(2)
      HATJ(1)=HATJ(M1)
      HATJ(M)=HATJ(2)
      FI(1)=FI(M1)
      FI(M)=FI(2)
C   QQQQQQQQQQQQQQQQQ
      RAJH(1)=RAJH(M1)
      RAJH(M)=RAJH(2)
      RSJ=0.
      DO 17 J=2,M1
      RSJ=RSJ+RAJH(J)
 17   CONTINUE
      RSJ=US/RSJ
C
C
C-----------------------------------------------------------------------
C
C  pOlY~EHiE KO|fficiEHTOB AU, BU, CU, FU dlq PAzHOCTHyX YPABHEHij
C  YPABHEHiq PE{A\TCq METOdOM pPOgOHKi
C
      DO 13 J=2,M1
      AU(J)=-0.25*HATJ(J+1)
      BU(J)=0.25*HATJ(J)
      CU(J)=0.5*(HAAJ(J+1)+HAAJ(J))-AU(J)-BU(J)
      X1=Y0(J)*0.5*(HAAJ0(J+1)+HAAJ0(J))
      X2=-0.25*HATJ0(J+1)*(Y0(J+1)+Y0(J))
      X3=0.25*HATJ0(J)*(Y0(J)+Y0(J-1))
      FU(J)=0.25*(FI(J)+FI(J+1)+FI0(J)+FI0(J+1))+X1+X2+X3
C   BBEdEHiE BqzKOCTi  (DRQ(J),DRQ0(J)=0 pPi DR=0)
      AU(J)=AU(J)+DRQ(J+1)
      BU(J)=BU(J)+DRQ(J)
      CU(J)=CU(J)+DRQ(J)+DRQ(J+1)
      FU(J)=FU(J)-DRQ0(J+1)*(Y0(J+1)-Y0(J))+DRQ0(J)*
     *(Y0(J)-Y0(J-1))
 13   CONTINUE
C----------------------------------------------------------------------
c
C  OpPEdElEHiE Y(I+0.5,J)
	if(kp.eq.1) CALL PROGC(AU,BU,CU,FU,Y,M)
c	if(i.eq.3.and.kpr.eq.1)print *,'quval=='
	if(kp.eq.0)call QUVAL(i,m,m1,tetm,ns,ns1,nst,epsk,y,y0,
     *  rsj,rsj0,rajh,rajh0,au,bu,cu,fu)
c	if(i.eq.3.and.kpr.eq.1)print *,'after ** quval=='
c	e5=0.
c      DO  J=2,M1
c      Z1=0.5*((HAAJ(J+1)+HAAJ(J))*ANU(I)-
c     *(HAAJ0(J+1)+HAAJ0(J))*ANU(I-1))
c      Z2=0.5*(HATJ(J+1)-HATJ(J))*ANU(I)
c      Z3=0.5*(HATJ0(J+1)-HATJ0(J))*ANU(I-1)
c      ZF=0.25*(FI(J)+FI(J+1)+FI0(J)+FI0(J+1))
c      E5=e5+ABS(1-ANUN*(Z1+Z2+Z3)/ZF)
c	end do
c	e5=e5/(m1-2+1.)
c	if(kpr.eq.1)print *,'i= e5=',i,e5
c
	YY=0.
	YCON=0.
	DO J=2,M1
	YY=YY+Y(J)
	YCON=YCON+1.
	END DO
	YY=YY/YCON
c	if(i.eq.n.and.kpr.eq.1)print*,'yy=',yy
      DO 200 J=2,M1
	arg=(AJ(I,J)-Y(J))/AJ(I,J)
      E1=dabs(arg)
      IF(E1.GT.DE1) DE1=E1
C >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
C
      AJ(I,J)=Y(J)
  200 CONTINUE
C
 10   CONTINUE
C-----------------------------------------------------------------------
C      PE{EHiE YPABHEHiq dlq RO(A,TETA)
C
	tok1=tok1*10./(4.*pi)
	tok2=tok2*10./(4.*pi)

c	if(kpr.eq.1)print *,'tok1 tok2',tok1,tok2
	if(kp.eq.1.and.pt01.gt.0.)then
	al1=pt01/tok1
	do i=2,n
	pp(i)=0.5*(pp(i)*al1+pp(i))
	pff(i)=0.5*(pff(i)*al1+pff(i))
	end do
	end if
c
       AN0=ANUN
      ANUN=0.
      ROSG(1)=0.
      DO 500 J=2,M1
      RO(1,J)=0.
      DO 510 I=2,N
      DRO=RO(I,J)-RO(I-1,J)
      AJA=ANU(I)/AJ(I,J)*DRO
      ROSG(I)=ROSG(I-1)+AJA
510   CONTINUE
      DO 520 I=2,N
      ROS=RO(I,J)
C   TO~HOCTi   TO~HOCTi   TO~HOCTi<<<<<
      RO(I,J)=ROSG(I)/ROSG(N)
	arg=ROS-RO(I,J)
      E2(i,j)=dabs(arg)
c      IF(E2.GT.DE2) DE2=E2
520   CONTINUE
      Y(J)=((UK(J)-UM)*(VK(J+1)-VK(J-1))-
     *(VK(J)-VM)*(UK(J+1)-UK(J-1)))*ROSG(N)
      ANUN=ANUN+Y(J)
500   CONTINUE
      ANUN=4.*SP/ANUN
C   TO~HOCTi   TO~HOCTi   TO~HOCTi<<<<<
      DE0=dabs((AN0-ANUN)/ANUN)
C
C   TO~HOCTi   TO~HOCTi   TO~HOCTi <<<<<<<<<<<<<<<<<<
c
c
C      OpPEdElEHiE MAgHiTHOj OCi
C      OpPEdElEHiE TO~Ki |KCTPEMYMA
      CHA=1./sqrt(HA(2))
      DUM=0.     
      DVM=0.
      DFUV=0.
       DO 86 J=2,M1
      SIGM=(RO(2,J)*CHA)**3*Y(J)*ANUN
      DUM=DUM+UK(J)*SIGM
      DVM=DVM+VK(J)*SIGM
      DFUV=DFUV+SIGM
 86    CONTINUE
      UM=DUM/DFUV
      VM=DVM/DFUV
C
C-----------------------------------------------------------------------
C
C  C~ET ~iClA iTEPAcij
      NH=NH+1
C
C  pPOBEPKi HA OKOH~AHiE
C
 22   CONTINUE
      IF(NH.GT.2*NHT)GO TO 24
      IF(DE1.GT.EPS) GO TO 1001
	do j=2,m1
	do i=2,n
	if(e2(i,j).gt.de2)de2=e2(i,j)
	end do
	end do
      IF(DE2.GT.EPS) GO TO 1001
C   OKOH~ATElxHAq BydA~A
 24   CONTINUE
      if(kpr.eq.1)PRINT 36, UM,VM,anun,nh
 36   FORMAT(10X,'UM=',1pE10.3,',VM=',1pE10.3,
     *',anun=',1pe10.3,',nh=',i4)
      DO  I=1,N
      RO(I,M)=RO(I,2)  
      RO(I,1)=RO(I,M1)
	end do
c	if(kpr.eq.1)print 71,ma,c2,c3
71	format(20x,a6/,(8(1pe10.3)))
	pt02=tok1
c	if(kpr.eq.1)print *,'tok1==',tok1
	psend=-yy*2.*pi*rs0
      RETURN
      END
      SUBROUTINE PROGC(A,B,C,F,U,M)
	implicit real*8 (a-h,o-z)
	include 'parf0'
      DIMENSION A(M),B(M),C(M),F(M),U(M)
      DIMENSION U0(ntet),F0(ntet),ALF(ntet),BET(ntet)
      M1=M-1
      NP=1
      U0(2)=0
      U0(M)=0
      DO 10 K=2,M1
10    F0(K)=F(K)
100   CONTINUE
      ALF(3)=0.
      BET(3)=U0(2)
      DO 20 K=3,M1
      DK=C(K)-ALF(K)*B(K)
      ALF(K+1)=A(K)/DK
20    BET(K+1)=(F0(K)+BET(K)*B(K))/DK
      DO 30 J=3,M1
      K=M+2-J
30    U0(K)=ALF(K+1)*U0(K+1)+BET(K+1)
      IF(NP.EQ.2) GO TO 200
      DO 40 K=2,M
      F0(K)=0.
40    U(K)=U0(K)
      U0(2)=1.
      U0(M)=1.
      NP=NP+1
      GO TO 100
200   CONTINUE
      U(1)=U(M1)
      U0(1)=U0(M1)
      FI20=A(2)*U0(3)-C(2)*U0(2)+B(2)*U0(1)
      FI2=A(2)*U(3)-C(2)*U(2)+B(2)*U(1)
      D=-(F(2)+FI2)/FI20
      DO 300 K=1,M
      U(K)=U(K)+D*U0(K)
300   CONTINUE
      RETURN
      END
       SUBROUTINE QUVAL(i,m,m1,tetm,ns,ns1,nst,epsk,y,y0,
     *  rsj,rsj0,rajh,rajh0,au,bu,cu,fu)
	implicit real*8 (a-h,o-z)
	include 'parf0'
        common
     *  /ge5/kpr
      COMMON /pol1/ RO(npo,ntet),AJ(npo,ntet)
      COMMON /pol2/ Q(npo),ANU(npo),P(npo),F(npo),
     *PP(npo),PFF(npo)
c====================================================
      include 'double_pp0_2.inc'
c===================================================
	dimension Y(m),Y0(m),RAJH(m),RAJH0(m),AU(m),BU(m),
     *  CU(m),FU(m)
	dimension BET(ntet),AUQ(ntet),BUQ(ntet),FUQ(ntet)
C
      NS0=NS1
c	if(kpr.eq.1)print *,'i ns1',i,ns1
      NS1=0
C   MACCiB Y(J) CHA~AlA - KAK BCpOMOgATElxHyj
      DO 1 J=2,M1
      Y(J)=AJ(I,J)
  1   CONTINUE
C
C  OKAjMlEHiE AU,BU
      AU(1)=AU(M1)
      AU(M)=AU(2)
      BU(1)=BU(M1)
      BU(M)=BU(2)
C
      DO 4510 J=2,M1
      BET(J)=0.25*TETM*(Q(I-1)*RSJ0*
     *(RAJH0(J)+RAJH0(J+1))+
     *      Q(I)*RSJ*(RAJH(J)+RAJH(J+1)))
4510   CONTINUE
      FF=F(I-1)
      QQ=Q(I)
C
C
C----------------------------------------------------------------------
C ECli ~iClO iTEPAcij BHYTPi 'QUVAL' HA pPEdydY}Ej iTEPAcii 'POLAR'
C   bylO BEliKO, TO HA~. pPiblivEHiE - C pPEdydY}EgO ClOq (T.E. Y0)
C   TEKY}Ej iTEPAcii 'POLAR',  ECli HET,
C   TO HA~. pPiblivEHiE - C pPEdydY}Ej iTEPAcii 'POLAR' (T.E. AJ(I,J))
      IF(NS0.GT.NST) GO TO 11
C
C----------------------------------------------------------------------
C   HA~AlO iTEPAcij
 10   CONTINUE
      DO 2 J=2,M1
      Y0(J)=Y(J)
  2   CONTINUE
C
C   C~ET~iK BHYTPEHHiX iTEPAcij
 11    NS1=NS1+1
C
       ALFS=0.
       DO 4010 J=2,M1
       ALFR=0.5*(RAJH(J+1)+RAJH(J))/Y0(J)
       ALFS=ALFS+ALFR
       ALF=ALFR/Y0(J)
       AUQ(J)=BU(J+1)
       BUQ(J)=AU(J-1)
       FUQ(J)=ALF
 4010   CONTINUE
       CALL PROGC (AUQ,BUQ,CU,FUQ,Y,M)
       ALFS=TETM*QQ/ALFS**2
       X1=0.     
       X2=0.
       DO 4020 J=2,M1
       X1=X1+BET(J)*Y(J)
       X2= X2+FU(J)*Y(J)
 4020   CONTINUE
       X1=X1*ALFS
       X2=X2*ALFS
       X=(FF*X1+X2)/(1.+X1)
       DSU=FF-X
       DO 4030 J=2,M1
       FUQ(J)=FU(J)+BET(J)*DSU
 4030   CONTINUE
       CALL PROGC(AU,BU,CU,FUQ,Y,M)
C
C----------------------------------------------------------------------
C   pPOBEPKA HA OKOH~AHiE
	if(ns1.gt.100)then
	if(kpr.eq.1)print *,'ns1 gt 100------'
	go to 30
	end if
       DO 4040 J=2,M1
      IF(dabs((Y(J)-Y0(J))/Y(J)).GT.EPSK) GO TO 10
 4040   CONTINUE
30	continue
      F(I)=X
      NS=MAX0(NS,NS1)
C
      RETURN
      END
c





