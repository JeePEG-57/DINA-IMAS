C  The black is called from the subroutines AREFF and ZIMPUR (or ZIMP)
c
            subroutine ATSV(IZ,IS,II,MI,TE10,SV10,DS10)
c................Author: V.E.Zhogolev (01.06.2000), modification (29.12.2004)
c Purpose: 
c     To calculate by splane algoritm 1 of 3 set rate coefficient (...)
c     of ionization, recombination or energy losses 
c     for the impurity element in the plasma.
c Output:
c     SV10(i)=alog10(...), 
c     DV10(i)=d_SV10(i)/d_TE10;
c Input: 
c     TE10=alog10(Te[eV]);
c     MI,II - integer parameters:
c     Charge state number of ions (k) is variated as k=II+i-1, (i=1,MI).
c
c     IS -  integer parameter specifying the set of rate coefficient: 
c  if IS=3 then 10**SV10  corresponds to  
c           coefficient of energy losses [10**(-8) cm**3 eV/s],
c  if IS=2 then 10**SV10 corresponds to 
c     rate coefficient of recombination [10**(-8) cm**3/s],
c  if IS=1 then 10**SV10 corresponds to 
c     rate coefficient of ionization [10**(-8) cm**3/s],
c  if IS=0 then SV10 corresponds to ionization potencial [eV].
c
c     IZ - the atomic number of impurity element (for Argon  IZ=18)
c
c ADDITIONAL DATA:
c     necessary data files 'sp*.dat' should be located 
c     in the working directory (...) or in the subdirectory '...\IMP'.
c
c ENTRY:SPNUL or it's equvalent ATMEM(imem), ('imem'is unused parameter)
c     To define the caunter of read new set impurity elements  
c     to initial state.
c....................................................................
c           Maximum number of simulteneucly used impurity elements is 10,
c     jm - maximum total number of atom/ion facility.
c!!!          implicit none
c!!!        integer jm,jms
	include 'double.inc'
      parameter (jm=200)
      parameter (jms=jm*108)
c!!!      real SX(36),SY(jms),EIN(jm)
      dimension SX(36),SY(jms),EIN(jm)
c!!!    	    integer IZ,IS,II,MI
c!!!      real TE10(*),SV10(*),DS10(*)
      dimension TE10(*),SV10(*),DS10(*)
c!!!      integer LZN(4,10)
      dimension LZN(4,10)
c!!!!!!!!!!!!!!!!!        save LZN,SX,SY,EIN
c!!!      integer NZ,LM,i,j   ,i20,l,m,n,k
c!!!!!!!!!!!!!!!!!         save NZ,LM,i,j
      data NZ,LM/0,18/
      data LZN/2*0,2*1,36*0/
      data i,j/1,2/
      if(NZ.eq.0) go to 3
    4 continue  
      do 1 m=1,NZ
      if(LZN(1,m).eq.IZ) go to 2
    1 continue  
      go to 3
    2 continue  
            if(IS.eq.0) then
      do 12 i20=1,MI
      SV10(i20)=EIN( LZN(4,m)-1+II+i20 )
   12 continue  
            return
            endif
      l=6*LM
      n=(LZN(3,m)-1)*LM+1
      k=((LZN(4,m)-1+II)*6+IS+IS-2)*LM+1

c      if(kpr.eq.1)print*,'n sx(n)',n,sx(n)

      call S_INDEIJ(i,j,1,LZN(2,m),LZN(2,m),TE10,SX(n))
      call S_INTER3(l,MI,i,j,TE10,SX(n),SY(k),SY(k+LM),SV10,DS10)
      return
    3 continue
      m=NZ+1
      if(m.eq.1) go to 5
      LZN(3,m)=LZN(3,NZ)+1
      LZN(4,m)=LZN(4,NZ)+LZN(1,NZ)+1  
    5 k=((LZN(4,m)-1)*6)*LM+1
      n=(LZN(3,m)-1)*LM+1
      i20=0
      call SPREAD(IZ,LM,SY(k),SX(n),EIN(LZN(4,m)),i20)
      if(i20.eq.0) go to 6
      if(i20.lt.0) go to 8
      if(i20.gt.LM) go to 7
      LZN(1,m)=IZ  
      LZN(2,m)=i20  
      if(m.eq.1) go to 9
      if(i20.ne.LZN(2,NZ)) go to 9
      k=(LZN(3,NZ)-1)*LM+1
      do 11 i20=1,LZN(2,NZ)
      if(SX(n-1+i20).ne.SX(k-1+i20)) go to 9
   11 continue
      LZN(3,m)=LZN(3,NZ)
    9 NZ=m
      go to 4
    7 LM=i20
      NZ=0
      go to 3  
    6 write(*,*) 'There is no data file for element namber',IZ
      stop
    8 write(*,*) 'Data file is not appropriate for element namber',IZ
      stop           
            entry SPNUL
      NZ=0
      LZN(3,1)=1
      LZN(4,1)=1  
      LM=18
            return
      end
            subroutine SPREAD(NF,LM,SPSV,TEM,EI,i20)
	include 'double.inc'
c        implicit none      
c!!!      real EI(*),TEM(*),SPSV(LM,6,1)
      dimension EI(*),TEM(*),SPSV(LM,6,1)
      character*8 NFILE
c!!!      integer LM,i20   ,I,J,K,IY      
      if(NF.ge.10) WRITE(NFILE,'(A2,I2,A4)')'sp', NF,'.dat'
      if(NF.lt.10) WRITE(NFILE,'(A2,I1,A4)')'sp', NF,'.dat'
c!!!      OPEN(33,FILE='/home/zhogolev/astra/imp/'
c!!!     # //NFILE,status='old',err=707)
ccc      if(kpr.eq.1)print*,NFILE
      open(unit=33,file=NFILE,form='formatted')
      go to 701
  707 continue  
      OPEN(33,FILE='imp/'//NFILE,status='old',err=706)
      go to 701
  706 OPEN(33,FILE=NFILE,status='old',err=704)
  701 READ(33,710,err=704) IY,i20 
  710 format(1x,2I6)
      if(NF.ne.IY-1) go to 705 
      if(i20.gt.LM)  go to 703 
      READ(33,720,err=705) (EI(I),I=1,IY) 
  720 format(8x,5E12.5) 
      READ(33,720,err=705) (TEM(I),I=1,i20) 
      DO 702 I=1,IY
      DO 702 K=1,6
      READ(33,720,err=705) (SPSV(J,K,I),J=1,i20) 
  702 CONTINUE
      go to 703
  704 i20=0
  705 i20=-i20
  703 CLOSE(33)
      return
      end
C S_INTER3
            SUBROUTINE S_INTER3(NI,N,I,J,X,XX,Y,DY,W,DW)
	include 'double.inc'
      DIMENSION XX(NI),Y(NI,N),DY(NI,N),W(N),DW(N)
      GO TO 5
            ENTRY S_INTCH3(NI,N,I,J,X,XX,Y,DY,W,DW)
      CALL S_INDEIJ(I,J,1,NI,NI,X,XX)
      GO TO 6
    5 CONTINUE
      IF(I.LT.1) I=1
      IF(J.LT.1) J=1
      IF(I.GT.NI) I=NI
      IF(J.GT.NI) J=NI
    6 CONTINUE
      IJ=I
      IF(I.EQ.J) GO TO 11
      DX=X-XX(I)
      IF(DX.EQ.0.) GO TO 11
      DXO=XX(J)-XX(I)
      IF(DXO.EQ.0.) GO TO 13
      IF(DXO.EQ.DX) GO TO 12
      ODX=1./DXO
      U=ODX*DX-0.5
      DO 1 L=1,N
      A=0.5*(Y(J,L)+Y(I,L))
      B=Y(J,L)-Y(I,L)
      C=0.5*(DY(J,L)-DY(I,L))*DXO
      D=DXO*(DY(J,L)+DY(I,L))-B-B
      A=A-C*0.25
      B=B-0.25*D
      IF(U.EQ.0.) GO TO 2
      DW(L)=ODX*(B+U*(C+C+U*D*3.))
      W(L)=A+U*(B+U*(C+U*D))
      GO TO 1
    2 DW(L)=ODX*B
      W(L)=A
    1 CONTINUE
      RETURN
   13 DO 3 L=1,N
      DW(L)=0.5*(DY(J,L)+DY(I,L))
    3 W(L)=0.5*(Y(J,L)+Y(I,L))
      RETURN
   12 IJ=J
   11 DO 4 L=1,N
      DW(L)=DY(IJ,L)
    4 W(L)=Y(IJ,L)
      RETURN
      END
            SUBROUTINE S_INDEIJ(I,J,L1,L2,L,X,XX)
	include 'double.inc'
      DIMENSION XX(L)

c      if(kpr.eq.1)print*,'L=',L
c      if(kpr.eq.1)print*,xx
c      read(*,*)

      IF(L1.GT.L2) RETURN
      IF(L1.LT.1) RETURN
      IF(L2.GT.L) RETURN
      IF(I.LE.J) GO TO 9
      J1=J
      J=I
      I=J1
    9 IF(I.LT.L1) I=L1
      IF(J.LT.I) J=I
      IF(J.GT.L2) J=L2
      IF(I.GT.J) I=J
      IF(X-XX(J)) 8,7,6
    7 I=J
      IF(J.EQ.L2) RETURN 
      J=J+1
      RETURN
    6 I=J
      IF(J.EQ.L2) RETURN 
      J1=J+1
      DO 5 J=J1,L2
      IF(XX(J).GT.X) RETURN
    5 I=J
      J=L2
      RETURN
    8 IF(X-XX(I)) 18,17,16
   17 J=I+1
      RETURN
   16 J1=J-1
      IF(I.EQ.J1) RETURN
      I1=I+1
      DO 15 J=I1,J1
      IF(XX(J).GT.X) RETURN
   15 I=J
      RETURN
   18 IF(X.GE.XX(L1)) GO TO 14
      I=L1
      J=L1
      RETURN
   14 J=I
      I=I-1
      IF(X-XX(I)) 19,17,16
   19 J1=I
      I1=L1+1
      I=L1
      DO 21 J=I1,J1
      IF(XX(J).GT.X) RETURN
   21 I=J
      RETURN
      END

