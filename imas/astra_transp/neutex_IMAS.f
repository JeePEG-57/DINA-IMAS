	subroutine	NEUTEX_IMAS
C-------------------------------------- Pereverzev ---------07.09.07---|
C	Input:	ABC, NA1, NB1, NNCX
C		AMETR(j), AMAIN(j), TE(j), TI(j), NE(j), NI(j), SNNBM(j)
C		ENCL, ENWM or wall neutral distribution
C		NNCL, NNWM
C	Warning:	ENCL > 0.5;	ENWM =/= 0 if NNWM =/= 0
C	Output:	  NN,	TN,   ALBPL
C----------------------------------------------------------------------|
	implicit none
	include	'for/parameter.inc'
	include 'for/solsrs_IMAS.inc'
!	include 'for/const.inc'
!	include 'for/status.inc'
	integer j,jj,JI,JNN,JNA,jcall
	double precision
     1		AKDLT,SVIE,SVII,SVREC,SVCX,YAB,
     2		YV1,YV2,YN0,YZ1,YZ2,YHA,YH1,YG1,YH2,YG2,YY1,YY2,YE1,YE2,
     3		YF(NRD),YC(NRD),YS(NRD),YA(NRD),YR(NRD),YX(NRD),YV(NRD),
     4		YN(NRD),YT(NRD),YK(NRD,NRD)
C The length of WORK1 is set accordingly to NEUT
	double precision	WORK1(NRD,2*NRD+7),WORK(NRD,2*NRD)

	equivalence (WORK1(1,1),YF(1)),   (WORK1(1,2),YC(1)),
     1		    (WORK1(1,3),YS(1)),   (WORK1(1,4),YA(1)),
     2		    (WORK1(1,5),YR(1)),	  (WORK1(1,6),YX(1)),
     3		    (WORK1(1,7),YN(1)),	  (WORK1(1,8),YT(1)), 
     4		    (WORK1(1,9),YV(1)),	  (WORK1(1,10),YK(1,1))
	data jcall/0/
	save jcall  
C----------------------------------------------------------------------|
!          write(*,*) 'neutex ENWM,ENCL ',ENWM,ENCL,NNCL,NNWM 
        JNA = NA1			! Entry NEUTEX (ignore SOL)
	goto	2
C	entry	NEUTAB
	JNA = NAB			! Entry NEUTAB (include SOL)
 2	continue
C	JNN = NRD
	JNN = NB1
	YAB = AMETR(JNA)		! ABC(NEUTEX) or AB(NEUTAB)
	YHA = YAB/(JNN-1.)
C-------------------------------       Set the internal grid
	do	j=1,JNN
	   YA(j) = (j-1.)/(JNN-1.)
	enddo
	do	j=1,JNA
	   YR(j) = AMETR(j)/AMETR(JNA)
	   YS(j) = 2.52d5*SQRT(max(TI(j),1.d-3)/AMAIN(j)) ! v_Ti/sqrt(3)
	enddo
	call	SMOOTH(1.d-3,JNA,YS,YR,JNN,YV,YA)
C-------------------------------	Some checks
	if (ENCL .lt. 0.0001)	then
	   write(*,'(A,F6.3,A)')
     1	      ">>> NEUT >>> Too low energy of incoming neutrals ENCL ="
     2	      ,1000.*ENCL,"eV"
	   write(*,*) "             Setting ENCL = 2 eV"
	   ENCL = 0.002
	endif
	if (ENWM .lt. 0.002)	then
	   write(*,'(A,F6.3,A)')
     1	      ">>> NEUT >>> Too low energy of incoming neutrals ENWM ="
     2	      ,1000.*ENWM,"eV"
	   write(*,*) "             Setting ENWM = 2 eV"
	   ENWM = 0.002
	endif
C-------------------------------	Atomic reaction rates:
	do	j=1,JNA
	   include 'fml/svrec'
	   YC(j) = SVREC*NE(j)*NI(j)+SNNBM(j)
	   include 'fml/svcx'
	   YN(j) = SVCX*NI(j)
	   include 'fml/svie'
	   include 'fml/svii'
	   YX(j) = YN(j)+SVIE*NE(j)+SVII*NI(j)		! YX=s(a)
	enddo
	call	SMOOTH(1.d-3,JNA,YX,YR,JNN,YS,YA)	! YS=s(x)
	YZ1 = 0.5*YHA
	YX(1) = 0.
	do	j=1,JNN-1
	   YX(j+1) = YX(j)+(YS(j)+YS(j+1))*YZ1		! YX(j)=X(j)
	enddo
C	call	SMOOTH(1.d-3,JNN,YS,YA,JNA,CAR(1,29),YR)
C	call	SMOOTH(1.d-3,JNN,YX,YA,JNA,CAR(1,30),YR)
C-------------------------------	Compute kernel:
	do	jj=1,JNN				! jj -> x
	   YH2 = 0.
	   YG2 = 0.
	   YZ2 = abs(YX(1)-YX(jj))/YV(1)		! h(x_jj,\xi_1)
	   YE2 = AKDLT(YZ2)
	   do	 j=1,JNN				! j  -> \xi
	      YH1 = YH2
	      YG1 = YG2
	      YZ1 = YZ2
	      YE1 = YE2
	      if (j .lt. JNN)	then
		 YZ2 = abs(YX(j+1)-YX(jj))/YV(j+1)	! g(x_jj,\xi_{j+1})
		 YE2 = AKDLT(YZ2)			! exp{-g}
		 YH2 = (YE2-YE1)/(YZ2-YZ1)
		 YG2 = YHA/(YZ2-YZ1)			! 1/g'_{i+1/2}
	      else
		 YG2 = 0.
	      endif
	      YY1 = YG1*(YE1+YH1)			! H_j 1st term
	      YY2 = YG2*(YE1+YH2)			! G_j 1st term
	      YK(jj,j) = YY2-YY1
	   enddo
	enddo
	do	jj=1,JNN
	   YH2 = 0.
	   YG2 = 0.
	   YZ2 = (YX(1)+YX(jj))/YV(1)			! h(x_jj,\xi_1)
	   YE2 = AKDLT(YZ2)
	   do	 j=1,JNN
	      YH1 = YH2
	      YG1 = YG2
	      YZ1 = YZ2
	      YE1 = YE2
	      if (j .lt. JNN)	then
		 YZ2 = (YX(j+1)+YX(jj))/YV(j+1)		! h(x_jj,\xi_{j+1})
		 YE2 = AKDLT(YZ2)			! exp{-h}
	         YH2 = (YE2-YE1)/(YZ2-YZ1)		! d[e^(-h)]/dh
	         YG2 = YHA/(YZ2-YZ1)			! 1/h'_{j+1/2}(x_jj)
	      else
		 YG2 = 0.
	      endif
	      YY1 = YG1*(YE1+YH1)			! H_j 2nd term
	      YY2 = YG2*(YE1+YH2)			! G_j 2nd term
	      YK(jj,j) = YK(jj,j)+YY2-YY1		! G_j(x_jj)-H_j(x_jj)
	   enddo
	enddo			! YK(jj,j)=K(x_jj,\xi_j) - intermediate result
C	jj = 1
C	do	j=1,20
C	   call	SMOOTH(1.d-3,JNN,YK(1,jj),YA,JNA,CAR(1,j),YR)
C	   jj = jj+2
C	enddo
C---------------------------------	Zero guess N_0(x)+R(x)
	YN0 = NNCL+NNWM+1.d-11
	YY1 = (NNCL+1.d-11)/YN0
	YY2 = NNWM/YN0
	YV1  = 4.37d5*SQRT(ENCL/AMJ)
	YV2  = 4.37d5*SQRT(ENWM/AMJ)
	call	SMOOTH(1.d-3,JNA,TI,YR,JNN,YT,YA)	! T_i -> Int. grid
	call	SMOOTH(1.d-3,JNA,YN,YR,JNN,YF,YA)	! YF=svcx*n_i
	call	SMOOTH(1.d-3,JNA,YC,YR,JNN,YS,YA)	! YS =svrec*n_e*n_i
 	do	j=1,JNN
	   YF(j) = 0.5*YF(j)/YV(j)			! F(j) factor in kernel
	   YS(j) = 0.5*YS(j)/YV(j)			! Factor in R(j)
	enddo
	do	j=1,JNN					! x_j
	   YZ1 = (YX(JNN)+YX(j))/YV1
	   YZ2 = (YX(JNN)-YX(j))/YV1
	   YH1 = YY1*(AKDLT(YZ1)+AKDLT(YZ2))		! K(x,a,v_1)
	   NN(j) = YH1				! 1st species, 0th generation
	   TN(j) = ENCL*YH1
	   if (NNWM .le. 0.)	goto	9
	   YZ1 = (YX(JNN)+YX(j))/YV2
	   YZ2 = (YX(JNN)-YX(j))/YV2
	   YH2 = YY2*(AKDLT(YZ1)+AKDLT(YZ2))		! K(x,a,v_2)
	   NN(j) = NN(j)+YH2			! 2nd species, 0th generation
	   TN(j) = TN(j)+ENWM*YH2
 9	   continue
	   YG1 = 0.
	   YG2 = 0.
	   do	jj=1,JNN
	      YZ1 = YS(jj)*YK(j,jj)		! YS=[<sv^rec>*n_e*n_i/(2v_Ti)]
	      YG1 = YG1+YZ1
	      YG2 = YG2+YZ1*YT(jj)
	   enddo
	   NN(j) = NN(j)+YG1/YN0		! NN_j=N_0(x_j)
	   TN(j) = TN(j)+YG2/YN0		! TN_j=T_0(x_j)
	enddo
C---------------------------------	Auxiliary output
C	call	SMOOTH(1.d-5,JNN,NN,YA,JNA,CAR(1,31),YR)
C	call	SMOOTH(1.d-5,JNN,TN,YA,JNA,CAR(1,32),YR)
C---------------------------------	Finalize the kernel \tilde{K} = F*K
 	do	j=1,JNN
	   do	jj=1,JNN
	      YK(jj,j) = YF(j)*YK(jj,j)		! \tilde{K} = F*K
	   enddo
	   YS(j)  = NN(j)			! YS=NN_(0)
C	   YS(j)  = 1.				! Check convergence
	enddo
C---------------------------------	Kernel is ready
C---------------------------------	Iterations:
	do	10	JI=1,NNCX
	   do	j=1,JNN
	      YN(j)  = YS(j)			! YN=NN_{i}
	   enddo
C	   if (ji .le. 20)
C     >		call	SMOOTH(1.d-5,JNN,YN,YA,JNA,CAR(1,JI),YR)
	   YY2 = 0.
	   do	j=1,JNN
	      YY1 = 0.
	      do       jj=1,JNN
		 YY1 = YY1+YN(jj)*YK(j,jj)	! YN=NN_(i-1)
	      enddo
	      YS(j) = YY1			! YS=NN_(i)
	      YY2 = max(YY2,YY1)
	   enddo
	   YZ1 = YZ2
	   YZ2 = YY2
	   do	j=1,JNN
	      NN(j)  = NN(j)+YS(j)		! NN(1:) at the internal grid
	   enddo
	   if (JI .eq. 1)	YN0 = YZ2
	   if (JI .eq. 1)	YZ1 = YZ2
	   if (abs(YZ2/YN0) .lt. 1.d-12)	goto	11
C	   write(*,'(1I5,1P,4E12.3)')JI,YZ2/YN0,YZ2/YZ1,YZ1,YZ2
 10	continue
	if (abs(YZ2/YN0) .gt. 1.d-4)	goto	12
 11	continue
C	write(*,100)JI,'    Accuracy =',YZ2/YZ1,YZ2/YN0
 100	format('Number of iterations = ',I4,A,1P,5E12.3)
C---------------------------------	End of iterations
	do	j=1,JNN
	   YS(j) = YT(j)*NN(j)			! T_i*N
	enddo
	do	j=1,JNN
	   YY1	= 0.
	   do	jj=1,JNN
	      YY1  = YY1+YS(jj)*YK(j,jj)
	   enddo
	   YX(j) = (TN(j)+YY1)/NN(j)
C	   TN(j) = max(0.d0,YT(j))
	   YN(j) = NN(j)
	enddo

C albpl: [d/l]	Plasma albedo
C		Pereverzev	15-05-95
C (Neutral_outflux)/(Neutral_influx) =
C	= sqrt{(NN-N1-N2)(NN*TN-N1*E1-N2*E2)}/(N1*sqrt(E1)+N2*sqrt(E2))
	ALBPL=sqrt((NNCL+NNWM)*(YN(JNN)-1)*
     .		((NNCL+NNWM)*YN(JNN)*YX(JNN)-NNCL*ENCL-NNWM*ENWM))/
     .		(NNCL*sqrt(ENCL)+NNWM*sqrt(ENWM))
	call	SMOOTH(1.d-5,JNN,YX,YA,JNA,TN,YR)
	call	SMOOTH(1.d-5,JNN,YN,YA,JNA,NN,YR)
C	write(*,'(1P,6E12.5)')(ABC*YA(j),j=JNN-5,JNN)
C	write(*,'(1P,6E12.5)')(YN(j),j=JNN-5,JNN)
C	stop
	return
 12	write(*,101)TIME
	if (jcall .eq. -1)	return
	write(*,*)"                        Increase NNCX can help"
	jcall = -1
 101	format(' >>> NEUTEX  Warning >>> Poor iteration convergence',
     >		' @ TIME =',1P,4E12.3)
	end
C======================================================================|
	double precision function AKDLT(X)
	double precision X
	if (X .gt. 50.)	then
	   AKDLT = 0.
	   return
	else
	   AKDLT = exp(-X)
	endif
	end
C======================================================================|
