C======================================================================|
	double precision function 
     .			svdtnt(yEBEAM,yABEAM,yNEJ,yTEJ,yTIJ,yAi,yTION)
C	For probability for D(T) with energy Ebeam to burn out on Maxwellian T(D)
C 	p = svdtnb 
C	d + t -> alpha(3518 keV) + n (14072 keV)
C		crossection by	H-S. Bosch, G.M. Hale
C		NF, V 32 , N 4, (1992) p 611-631
C	Corrected for finit ion temperature according to:
C		D.R.Mikkelsen, NF V 29, N 7, (1989) p 1113-1115
C		
C	Use: heating from alphas from T(D) beam + D(T)	
C		Pdtbt = Pbeam*svdtnb*3520/EBEAM	[MW/m3]
C	     14,1MeV neutron source 
C  		Sdt14 = Pbeam*svdtnb*625/EBEAM*Ndeut(Ntrit)	[10^-19/m^3/s]
C	
C		Polevoy		06-JUL-99,08-JUN-07,24-MAY-11
c	input:	yEBEAM[energy,keV],yABEAM[mass, a.u.],
C		yNEJ[Ne,10^19m-3],yTEJ[Te,keV],yAi[amain, mass, a.u.]
C.......Logarithm e
c	YLE	=15.85+LOG(TE(J)/SQRT(NE(J)))
c	2 TauES = 2.d0*yABEAM)*TE(J)^1.5/LnE/NE(J
c	V0	=
!==========================================================
	implicit none
        double precision yEBEAM,yABEAM,yNEJ,yTEJ,yTIJ,yAi
        double precision YX3,YX2,YX,YE,YECM,YSQ,
     ,			YS2,YSIG,YXC3,YECDEB,YDS,YLE,YLI
	double precision YA1,YA2,YA3,YA4,YB1,YB2,YB3,YB4,YBG,
     ,	YA0,YB0,YAS,YBS,YMb,YMt,YMU,YGAM,YBET,
     ,	YB,Vth2,MVth2,MVth24,Vb,YVs,YS,YSS,YR,YD,Y27,VtdVb2,YVB,YV,
     ,	Y13,Y23,YEMIN,YTMIN,YRMD3,YRPD3,YVb0,YCOEF,yTION
	integer jk,jend
	data YA1/6.927d4/,YA2/7.454d8/,YA3/2.05d6/,YA4/5.2002d4/
     .	,YB1/63.8d0/,YB2/-.995d0/,YB3/6.981d-5/,YB4/1.728d-4/
     .	,YBG/34.3827d0/,YTMIN/.01d0/,YCOEF/1.d0/
!========================================================================
	if(yABEAM.ne.2.d0.or.yABEAM.ne.3.d0.or.yEBEAM.le.0.d0) then
		svdtnt	=0.d0
		return
	endif
	IF(yABEAM.eq.2.d0) then 
		YECM	=0.6*yEBEAM
		YMt	=3.d0	!bulk thermal T
	endif

	IF(yABEAM.eq.3.d0) then
		YECM	=0.4*yEBEAM
		YMt	=2.d0	!bulk thermal D
	endif
		YMb	=yABEAM
		yMU 	=YMb*YMt/(YMb+YMt)
		YBG	=31.4d0*DSQRT(yMU)	! B	=44.4d0
	if(yTIJ.ge.YTMIN) then
		y13	=1.d0/3.d0
		Y27 	=1.d0/27.d0
		Vth2	=2.d0*yTIJ/YMt
		MVth2	=yMU*Vth2
		MVth24	=MVth2/4.d0
		YVB	=DSQRT(2.d0*yEBEAM/yABEAM)
		VtdVb2	=Vth2/YVB**2
		YB	=22.2*VtdVb2/YVb	! bet =YB/Vb^3
		YEMIN	=yTIJ
	else
		YEMIN	=YTMIN
	endif

! Coulomb Log Le,Li==========================================
		YLE=(15.85d0+DLOG(yTEJ/DSQRT(yNEJ)))
	IF(yEBEAM.GT.100.d0*yABEAM)	THEN
		YLI=23.7d0+dLOG(yAi/(yAi+yABEAM)*
     *             dSQRT(1.d-3*yABEAM*yEBEAM*yTEJ/yNEJ))
				ELSE
		YLI=25.4d0+LOG(1.d-3*yEBEAM*yAi/
     /		  (yAi+yABEAM)*dSQRT(yTEJ/yNEJ))
				ENDIF
!======================================================		
		YSQ	=dSQRT(YECM)
		jend=1000
		YDS=(1.d0/jend)	
		svdtnt	=0.d0

c	  YECDEB =14.6*yTEJ*yABEAM/(Ai)**(2/3)/EBEAM
	  YECDEB  = 14.6d0*yTEJ*yABEAM/yEBEAM/(YLE*yAi/YLI)**0.667
	  YXC3 =YECDEB*dSQRT(YECDEB)
	DO 	JK = 1,jend
		YX	=YDS*JK
		YX2	=YX*YX
		YX3	=YX2*YX
	if(YECM*YX2.gt.YEMIN) then
	if(yTIJ.ge.YTMIN.and.yTION.lt.1.5d0) then
		yBET	=YB/YX3
		YR	=yBET/2.d0+Y27
		YD	=DSQRT(YBET*(yBET/4.d0+Y27))
		YRMD3	=(YR-YD)**Y13
		YRPD3	=(YR+YD)**Y13
		YVb0	=(Y13+YRMD3+YRPD3)
		YVS	=YX*YVb0
		YGAM	=3.0d0-2.0/YVb0
		YE	=YECM*YVS**2
		YA0	=YA1+YE*(YA2+YE*(YA3+YE*YA4))
    		YB0	=1.d0+YE*(YB1+YE*(YB2+YE*(YB3+YE*YB4)))
		YAS	=YA2+YE*(2.d0*YA3+YE*3.d0*YA4)
		YBS	=YB1+YE*(2.d0*YB2+YE*(3.d0*YB3+4.d0*YE*YB4))
		YSS	=YAS/YA0-YBS/YB0

	Ycoef	= dexp(-YX2*(YVb0-1.d0)**2/VtdVb2)*yVb0/DSQRT(YGAM)
     .		*(1.d0+MVth24*YSS/YGAM
     .		+1.5d0*(1.d0-1.d0/yVb0)/YGAM**2
     .		*(MVth2*YSS-VtdVb2/YVS**2))

	else
		YE	=YECM*YX2
		YVS	=YX
		YA0	=YA1+YE*(YA2+YE*(YA3+YE*YA4))
    		YB0	=1.d0+YE*(YB1+YE*(YB2+YE*(YB3+YE*YB4)))
		Ycoef	=1.d0
	endif
		YSIG	=dEXP(-YBG/YVS/YSQ)/YE*YA0/YB0*Ycoef	
      		svdtnt	=svdtnt+ YSIG/(1.+YXC3/YX3)
	endif
	 enddo
	svdtnt	=svdtnt*YDS*1.d-3*
     * 	4.38d-4*DSQRT(yEBEAM/yABEAM)*
     *	2.d0*yABEAM/yNEJ*yTEJ*DSQRT(yTEJ)/YLE
	return
	end
!===================================================================


C======================================================================|
	double precision function 
     .			svddnp1(yEBEAM,yABEAM,yNEJ,yTEJ,yTIJ,yAi,yTION)
C============================================= Polevoi = 30-May-2011,16-JUL-13
C <SigmaV dt> probability for d with EBEAM keV to burn out on maxwellian d 
C	with Ti  during the slowing down to Ti in reaction:	
C	d(Ebeam) + d(Ti) -> He3(870 keV) + n (2450 keV) 
C=====================================================================
C	Crossection by	H-S. Bosch, G.M. Hale
C		NF, V 32 , N 4, (1992) p 611-631
C	Corrected for finit ion temperature according to:
C		D.R.Mikkelsen, NF V 29, N 7, (1989) p 1113-1115
C	+ second derivative is addedd S' -> S'+ 2 E S''(16-JUL-13)	
C		
C	Use: 
C  		Sdt245[10^-19/m^3/s] = 
C			=Pbeam[MW]*svddnb2*625/EBEAM[keV]*Ndeut[10^19m-3]	
C	
c	input:	yEBEAM[energy,keV],yABEAM[mass, a.u.],
C		yNEJ[Ne,10^19m-3],yTEJ[Te,keV],yAi[amain, mass, a.u.]
C.......Logarithm e
c		YLE	=15.85+LOG(TE(J)/SQRT(NE(J)))
c		TauES = 2.d0*yABEAM*TE(J)^1.5/LnE/NE(J)
c		V	= Sqrt(2 T/M)
!==========================================================
	implicit none
        double precision yEBEAM,yABEAM,yNEJ,yTEJ,yTIJ,yAi
        double precision YX3,YX2,YX,YE,YECM,YSQ,YASS,YBSS,YSS2,
     ,			YS2,YSIG,YXC3,YECDEB,YDS,YLE,YLI
	double precision YA1,YA2,YA3,YA4,YA5,YB1,YB2,YB3,YB4,YBG,
     ,	YA0,YB0,YAS,YBS,YMb,YMt,YMU,YGAM,YBET,
     ,	YB,Vth2,MVth2,MVth24,Vb,YVs,YS,YSS,YR,YD,Y27,VtdVb2,YVB,YV,
     ,	Y13,Y23,YEMIN,YTMIN,YRMD3,YRPD3,YVb0,YCOEF,YSIG1,yTION
	integer jk,jend
	data YA1/5.3701d4/,YA2/3.3027d2/,YA3/-.12706d0/,YA4/2.9327d-5/
     . 	,YA5/-2.5151d-9/
     .	,YB1/0.d0/,YB2/0.d0/,YB3/0.d0/,YB4/0.d0/
     .	,YBG/31.397d0/,YTMIN/.01d0/,YCOEF/1.d0/
!========================================================================
	if(yABEAM.ne.2.d0.or.yEBEAM.le.0.d0) then
		svddnp1	=0.d0
		return
	endif
!======================================== 
		YMb	=yABEAM
		YMt	=2.d0	!D(Ebeam) bulk thermal D(Ti) D(d,n)3He
		yMU 	=YMb*YMt/(YMb+YMt)
		YBG	=31.397d0*DSQRT(yMU)	! B	=44.4d0
		YECM	=0.5*yEBEAM
		YSQ	=DSQRT(YECM)
!==============================================
	if(yTIJ.ge.YTMIN) then
		y13	=1.d0/3.d0
		Y27 	=1.d0/27.d0
		Vth2	=2.d0*yTIJ/YMt
		MVth2	=yMU*Vth2
		MVth24	=MVth2/4.d0
		YVB	=DSQRT(2.d0*yEBEAM/yABEAM)
		VtdVb2	= Vth2/YVB**2
		YB	=22.2d0*VtdVb2/YVb	! bet =YB/Vb^3
		YEMIN	=yTIJ
	else
		YEMIN	=YTMIN
	endif

! Coulomb Log Le,Li==========================================
		YLE=(15.85d0+DLOG(yTEJ/DSQRT(yNEJ)))
	IF(yEBEAM.GT.100.d0*yABEAM)	THEN
		YLI=23.7d0+dLOG(yAi/(yAi+yABEAM)*
     *             dSQRT(1.d-3*yABEAM*yEBEAM*yTEJ/yNEJ))
				ELSE
		YLI=25.4d0+LOG(1.d-3*yEBEAM*yAi/
     /		  (yAi+yABEAM)*dSQRT(yTEJ/yNEJ))
				ENDIF
!======================================================		
		jend=1000
		YDS=(1.d0/jend)	
		svddnp1	=0.d0
c	  YECDEB =14.6*yTEJ*yABEAM/(Ai)**(2/3)/EBEAM
	  YECDEB  = 14.6d0*yTEJ*yABEAM/yEBEAM/(YLE*yAi/YLI)**0.667
	  YXC3 =YECDEB*dSQRT(YECDEB)
	DO 	JK = 1,jend
		YX	=(YDS*JK)
		YX2	=YX*YX
		YX3	=YX2*YX
		YE	=YECM*YX2
	if(YEBEAM*YX2.gt.YEMIN) then
	if(yTIJ.ge.YTMIN.and.yTION.lt.1.5d0) then
		yBET	=YB/YX3
		YR	=yBET/2.d0+Y27
		YD	=DSQRT(YBET*(yBET/4.d0+Y27))
		YRMD3	=(YR-YD)**Y13
		YRPD3	=(YR+YD)**Y13
		YVb0	=(Y13+YRMD3+YRPD3)
		YVS	=YX*YVb0
		YGAM	=3.0d0-2.0/YVb0
		YE	=YECM*YVS**2
		YA0	=YA1+YE*(YA2+YE*(YA3+YE*(YA4+YE*YA5)))
    		YB0	=1.d0+YE*(YB1+YE*(YB2+YE*(YB3+YE*YB4)))
		YAS	=YA2+YE*(2.d0*YA3+YE*(3.d0*YA4+4.d0*YE*YA5))
		YBS	=YB1+YE*(2.d0*YB2+YE*(3.d0*YB3+4.d0*YE*YB4))
		YASS	=2.d0*(YA3+3.d0*YE*(YA4+2.d0*YE*YA5))
		YBSS	=2.d0*(YB2+3.d0*YE*(YB3+2.d0*YE*YB4))
		YSS	=(YAS/YA0-YBS/YB0)
		YSS2	=YSS
     *	*(1.d0-4.d0*YE*YBS/YB0)+2.d0*YE*(YASS/YA0-YBSS/YB0)

!	write(*,*) 'YE,YA0,YB0,YAS,YBS,YVS',YE,YA0,YB0,YAS,YBS,YVS
!	write(*,*) 'exp,yvb0',
!     .	dexp(-YX2*(YVb0-1.d0)**2/VtdVb2)*yVb0/DSQRT(YGAM),yVb0
	Ycoef	= dexp(-YX2*(YVb0-1.d0)**2/VtdVb2)*yVb0/DSQRT(YGAM)
     .		*(1.d0+MVth24*YSS2/YGAM
     .		+1.5d0*(1.d0-1.d0/yVb0)/YGAM**2
     .		*(MVth2*YSS-VtdVb2/YVS**2))
		YSIG	=dEXP(-YBG/YVS/YSQ)/YE*YA0/YB0*yVb0*Ycoef
	else
		YVS	=YX
		YE	=YECM*YX2
		YA0	=YA1+YE*(YA2+YE*(YA3+YE*(YA4+YE*YA5)))
    		YB0	=1.d0+YE*(YB1+YE*(YB2+YE*(YB3+YE*YB4)))
		YSIG	=dEXP(-YBG/YVS/YSQ)/YE*YA0/YB0
	endif
      		svddnp1	=svddnp1+ YSIG/(1.+YXC3/YX3)
	endif
	 enddo 
!======================================================== Test
!
	goto 99			!No test print
		YX	=1.d0
		YE	=YECM*YX2
		YA0	=YA1+YE*(YA2+YE*(YA3+YE*(YA4+YE*YA5)))
    		YB0	=1.d0+YE*(YB1+YE*(YB2+YE*(YB3+YE*YB4)))
		YSIG1	=dEXP(-YBG/YX/YSQ)/YE*YA0/YB0*YX
!=Svt0 = Sigma*V(Ebeam) [10^-24 m3/s]
	write(*,*) 'TE,TI,EBEAM,Svt/Svt0,Svt0=',
     .	yTEj,yTIj,yEBEAM,Ysig/Ysig1,Ysig1
     .	*4.38d-2*DSQRT(yEBEAM/yABEAM)	
!========================================================
 99	svddnp1	=svddnp1*YDS*1.d-3*
     * 	4.38d-4*DSQRT(yEBEAM/yABEAM)*
     *	2.d0*yABEAM/yNEJ*yTEJ*DSQRT(yTEJ)/YLE
	return
	end
!===================================================================
C======================================================================|
	double precision function 
     .			svddnp2(yEBEAM,yABEAM,yNEJ,yTEJ,yTIJ,yAi,yTION)
C======================================== Polevoi = 13-Mar-2013, 16-JUL-13
C <SigmaV dt> probability for d with EBEAM keV to burn out on maxwellian d 
C	with Ti  during the slowing down to Ti in reaction:	
C	d(Ebeam) + d(Ti) -> t(1008 keV) + p(3025 keV) 
C=====================================================================
C	Crossection by	H-S. Bosch, G.M. Hale
C		NF, V 32 , N 4, (1992) p 611-631
C	Corrected for finit ion temperature according to:
C		D.R.Mikkelsen, NF V 29, N 7, (1989) p 1113-1115
C	+ second derivative is addedd S' -> S'+ 2 E S''(16-JUL-13)			
C	Use: 
C  		St1008[10^-19/m^3/s] = 
C			=Pbeam[MW]*svddnb1*625/EBEAM[keV]*Ndeut[10^19m-3]	
C	
c	input:	yEBEAM[energy,keV],yABEAM[mass, a.u.],
C		yNEJ[Ne,10^19m-3],yTEJ[Te,keV],yAi[amain, mass, a.u.]
C.......Logarithm e
c		YLE	=15.85+LOG(TE(J)/SQRT(NE(J)))
c		TauES = 2.d0*yABEAM*TE(J)^1.5/LnE/NE(J)
c		V	= Sqrt(2 T/M)
!==========================================================
	implicit none
        double precision yEBEAM,yABEAM,yNEJ,yTEJ,yTIJ,yAi
        double precision YX3,YX2,YX,YE,YECM,YSQ,YASS,YBSS,YSS2,
     ,			YS2,YSIG,YXC3,YECDEB,YDS,YLE,YLI
	double precision YA1,YA2,YA3,YA4,YA5,YB1,YB2,YB3,YB4,YBG,
     ,	YA0,YB0,YAS,YBS,YMb,YMt,YMU,YGAM,YBET,
     ,	YB,Vth2,MVth2,MVth24,Vb,YVs,YS,YSS,YR,YD,Y27,VtdVb2,YVB,YV,
     ,	Y13,Y23,YEMIN,YTMIN,YRMD3,YRPD3,YVb0,YCOEF,YSIG1,yTION
	integer jk,jend
	data YA1/5.5576d4/,YA2/2.1054d2/,YA3/-3.2638d-2/,YA4/1.4987d-6/
     . 	,YA5/1.1881d-10/
     .	,YB1/0.d0/,YB2/0.d0/,YB3/0.d0/,YB4/0.d0/
     .	,YBG/31.397d0/,YTMIN/.01d0/,YCOEF/1.d0/
!========================================================================
	if(yABEAM.ne.2.d0.or.yEBEAM.le.0.d0) then
		svddnp2	=0.d0
		return
	endif
!======================================== 
		YMb	=yABEAM
		YMt	=2.d0	!D(Ebeam) bulk thermal D(Ti) D(d,n)3He
		yMU 	=YMb*YMt/(YMb+YMt)
		YBG	=31.397d0*DSQRT(yMU)	! B	=44.4d0
		YECM	=0.5*yEBEAM
		YSQ	=DSQRT(YECM)
!==============================================
	if(yTIJ.ge.YTMIN) then
		y13	=1.d0/3.d0
		Y27 	=1.d0/27.d0
		Vth2	=2.d0*yTIJ/YMt
		MVth2	=yMU*Vth2
		MVth24	=MVth2/4.d0
		YVB	=DSQRT(2.d0*yEBEAM/yABEAM)
		VtdVb2	= Vth2/YVB**2
		YB	=22.2d0*VtdVb2/YVb	! bet =YB/Vb^3
		YEMIN	=yTIJ
	else
		YEMIN	=YTMIN
	endif

! Coulomb Log Le,Li==========================================
		YLE=(15.85d0+DLOG(yTEJ/DSQRT(yNEJ)))
	IF(yEBEAM.GT.100.d0*yABEAM)	THEN
		YLI=23.7d0+LOG(yAi/(yAi+yABEAM)*
     *             dSQRT(1.d-3*yABEAM*yEBEAM*yTEJ/yNEJ))
				ELSE
		YLI=25.4d0+LOG(1.d-3*yEBEAM*yAi/
     /		  (yAi+yABEAM)*dSQRT(yTEJ/yNEJ))
				ENDIF
!======================================================		
		jend=1000
		YDS=(1.d0/jend)	
		svddnp2	=0.d0
c	  YECDEB =14.6*yTEJ*yABEAM/(Ai)**(2/3)/EBEAM
	  YECDEB  = 14.6d0*yTEJ*yABEAM/yEBEAM/(YLE*yAi/YLI)**0.667
	  YXC3 =YECDEB*dSQRT(YECDEB)
	DO 	JK = 1,jend
		YX	=(YDS*JK)
		YX2	=YX*YX
		YX3	=YX2*YX
		YE	=YECM*YX2
	if(YEBEAM*YX2.gt.YEMIN) then
	if(yTIJ.ge.YTMIN.and.yTION.lt.1.5d0) then
		yBET	=YB/YX3
		YR	=yBET/2.d0+Y27
		YD	=DSQRT(YBET*(yBET/4.d0+Y27))
		YRMD3	=(YR-YD)**Y13
		YRPD3	=(YR+YD)**Y13
		YVb0	=(Y13+YRMD3+YRPD3)
		YVS	=YX*YVb0
		YGAM	=3.0d0-2.0/YVb0
		YE	=YECM*YVS**2
		YA0	=YA1+YE*(YA2+YE*(YA3+YE*(YA4+YE*YA5)))
    		YB0	=1.d0+YE*(YB1+YE*(YB2+YE*(YB3+YE*YB4)))
		YAS	=YA2+YE*(2.d0*YA3+YE*(3.d0*YA4+4.d0*YE*YA5))
		YBS	=YB1+YE*(2.d0*YB2+YE*(3.d0*YB3+4.d0*YE*YB4))
		YASS	=2.d0*(YA3+3.d0*YE*(YA4+2.d0*YE*YA5))
		YBSS	=2.d0*(YB2+3.d0*YE*(YB3+2.d0*YE*YB4))
		YSS	=(YAS/YA0-YBS/YB0)
		YSS2	=YSS
     *	*(1.d0-4.d0*YE*YBS/YB0)+2.d0*YE*(YASS/YA0-YBSS/YB0)
!	write(*,*) 'YE,YA0,YB0,YAS,YBS,YVS',YE,YA0,YB0,YAS,YBS,YVS
!	write(*,*) 'exp,yvb0',
!     .	dexp(-YX2*(YVb0-1.d0)**2/VtdVb2)*yVb0/DSQRT(YGAM),yVb0
	Ycoef	= dexp(-YX2*(YVb0-1.d0)**2/VtdVb2)*yVb0/DSQRT(YGAM)
     .		*(1.d0+MVth24*YSS2/YGAM
     .		+1.5d0*(1.d0-1.d0/yVb0)/YGAM**2
     .		*(MVth2*YSS-VtdVb2/YVS**2))
		YSIG	=dEXP(-YBG/YVS/YSQ)/YE*YA0/YB0*yVb0*Ycoef
	else
		YVS	=YX
		YE	=YECM*YX2
		YA0	=YA1+YE*(YA2+YE*(YA3+YE*(YA4+YE*YA5)))
    		YB0	=1.d0+YE*(YB1+YE*(YB2+YE*(YB3+YE*YB4)))
		YSIG	=dEXP(-YBG/YVS/YSQ)/YE*YA0/YB0
	endif
      		svddnp2	=svddnp2+ YSIG/(1.+YXC3/YX3)
	endif
	 enddo 
!======================================================== Test
!
	goto 99			!No test print
		YX	=1.d0
		YE	=YECM*YX2
		YA0	=YA1+YE*(YA2+YE*(YA3+YE*(YA4+YE*YA5)))
    		YB0	=1.d0+YE*(YB1+YE*(YB2+YE*(YB3+YE*YB4)))
		YSIG1	=dEXP(-YBG/YX/YSQ)/YE*YA0/YB0
!=Svt0 = Sigma*V(Ebeam) [10^-24 m3/s]
	write(*,*) 'TE,TI,EBEAM,Svt/Svt0,Svt0=',
     .	yTEj,yTIj,yEBEAM,Ysig/Ysig1,Ysig1
     .	*4.38d-2*DSQRT(yEBEAM/yABEAM)	
!========================================================
 99	svddnp2	=svddnp2*YDS*1.d-3*
     * 	4.38d-4*DSQRT(yEBEAM/yABEAM)*
     *	2.d0*yABEAM/yNEJ*yTEJ*DSQRT(yTEJ)/YLE
	return
	end
!===================================================================
	double precision function 
     .			svdtbp(yEBEAM,yABEAM,yNEJ,yTEJ,yTIJ,yAi,yTION)
C=========================================== Polevoi = 30-May-2011, 07-JAN-14
C <SigmaV dt> probability for d(t) with EBEAM keV to burn out on maxwellian d 
C	with Ti  during the slowing down to Ti in reaction:	
C	d(t)(Ebeam) + t(d)(Ti) -> He4(3524 keV) + n(14072 keV) 
C=====================================================================
C	Crossection by	H-S. Bosch, G.M. Hale
C		NF, V 32 , N 4, (1992) p 611-631
C	Corrected for finit ion temperature according to:
C		D.R.Mikkelsen, NF V 29, N 7, (1989) p 1113-1115
C	+ second derivative is addedd S' -> S'+ 2 E S''(16-JUL-13)	
C	Use: 
C  		Sn14[10^-19/m^3/s] = 
C			=Pbeam[MW]*svdtbp*625/EBEAM[keV]*Ndeut[10^19m-3]	
C	
c	input:	yEBEAM[energy,keV],yABEAM[mass, a.u.],
C		yNEJ[Ne,10^19m-3],yTEJ[Te,keV],yAi[amain, mass, a.u.]
C.......Logarithm e
c		YLE	=15.85+LOG(TE(J)/SQRT(NE(J)))
c		TauES = 2.d0*yABEAM*TE(J)^1.5/LnE/NE(J)
c		V	= Sqrt(2 T/M)
!==========================================================
	implicit none
        double precision yEBEAM,yABEAM,yNEJ,yTEJ,yTIJ,yAi
        double precision YX3,YX2,YX,YE,YECM,YSQ,YASS,YBSS,YSS2,
     ,			YS2,YSIG,YXC3,YECDEB,YDS,YLE,YLI
	double precision YA1,YA2,YA3,YA4,YA5,YB1,YB2,YB3,YB4,YBG,
     ,	YA0,YB0,YAS,YBS,YMb,YMt,YMU,YGAM,YBET,
     ,	YB,Vth2,MVth2,MVth24,Vb,YVs,YS,YSS,YR,YD,Y27,VtdVb2,YVB,YV,
     ,	Y13,Y23,YEMIN,YTMIN,YRMD3,YRPD3,YVb0,YCOEF,YSIG1,yTION
	integer jk,jend
	data YA1/6.927d4/,YA2/7.454d8/,YA3/2.05d6/,YA4/5.2002d4/
     . 	,YA5/0.d0/
     	data YB1/63.8d0/,YB2/-.995d0/,YB3/6.981d-5/,YB4/1.728d-4/
     .	,YBG/34.3827d0/,YTMIN/.01d0/,YCOEF/1.d0/,YSIG/0.d0/
!========================================================================
	if(yABEAM.lt.2.d0.or.yABEAM.gt.3.d0.or.yEBEAM.le.0.d0) then
		svdtbp	=0.d0
		return
	endif
!	write(*,*) 'yEBEAM,yABEAM,yNEJ,yTEJ,yTIJ,yAi',
!     . 	yEBEAM,yABEAM,yNEJ,yTEJ,yTIJ,yAi
!======================================== 
		YMb	=yABEAM
	if(yABEAM.eq.3.d0) then
		YMt	=2.d0	!t(Ebeam) bulk thermal d(Ti) 
	else
		YMt	=3.d0	!d(Ebeam) bulk thermal t(Ti) 	
	endif
		yMU 	=YMb*YMt/(YMb+YMt)
		YBG	=31.397d0*DSQRT(yMU)	! B	=44.4d0
		YECM	=yMU/yABEAM*yEBEAM
		YSQ	=DSQRT(YECM)
!==============================================
	if(yTIJ.ge.YTMIN) then
		y13	=1.d0/3.d0
		Y27 	=1.d0/27.d0
		Vth2	=2.d0*yTIJ/YMt
		MVth2	=yMU*Vth2
		MVth24	=MVth2/4.d0
		YVB	=DSQRT(2.d0*yEBEAM/yABEAM)
		VtdVb2	= Vth2/YVB**2
		YB	=22.2d0*VtdVb2/YVb	! bet =YB/Vb^3
		YEMIN	=yTIJ
	else
		YEMIN	=YTMIN
	endif

! Coulomb Log Le,Li==========================================
		YLE=(15.85d0+DLOG(yTEJ/DSQRT(yNEJ)))
	IF(yEBEAM.GT.100.d0*yABEAM)	THEN
		YLI=23.7d0+dLOG(yAi/(yAi+yABEAM)*
     *             dSQRT(1.d-3*yABEAM*yEBEAM*yTEJ/yNEJ))
				ELSE
		YLI=25.4d0+dLOG(1.d-3*yEBEAM*yAi/
     /		  (yAi+yABEAM)*dSQRT(yTEJ/yNEJ))
				ENDIF
!======================================================		
		jend=1000
		YDS=(1.d0/jend)	
		svdtbp	=0.d0
c	  YECDEB =14.6*yTEJ*yABEAM/(Ai)**(2/3)/EBEAM
	  YECDEB  = 14.6d0*yTEJ*yABEAM/yEBEAM/(YLE*yAi/YLI)**0.667
	  YXC3 =YECDEB*dSQRT(YECDEB)
	DO 	JK = 1,jend
		YX	=(YDS*JK)
		YX2	=YX*YX
		YX3	=YX2*YX
		YE	=YECM*YX2
	if(YEBEAM*YX2.gt.YEMIN) then
	if(yTIJ.ge.YTMIN.and.yTION.lt.1.5d0) then
		yBET	=YB/YX3
		YR	=yBET/2.d0+Y27
		YD	=DSQRT(YBET*(yBET/4.d0+Y27))
		YRMD3	=(YR-YD)**Y13
		YRPD3	=(YR+YD)**Y13
		YVb0	=(Y13+YRMD3+YRPD3)
		YVS	=YX*YVb0
		YGAM	=3.0d0-2.0/YVb0
		YE	=YECM*YVS**2
		YA0	=YA1+YE*(YA2+YE*(YA3+YE*(YA4+YE*YA5)))
    		YB0	=1.d0+YE*(YB1+YE*(YB2+YE*(YB3+YE*YB4)))
		YAS	=YA2+YE*(2.d0*YA3+YE*(3.d0*YA4+4.d0*YE*YA5))
		YBS	=YB1+YE*(2.d0*YB2+YE*(3.d0*YB3+4.d0*YE*YB4))
		YASS	=2.d0*(YA3+3.d0*YE*(YA4+2.d0*YE*YA5))
		YBSS	=2.d0*(YB2+3.d0*YE*(YB3+2.d0*YE*YB4))
		YSS	=(YAS/YA0-YBS/YB0)
		YSS2	=YSS
     *	*(1.d0-4.d0*YE*YBS/YB0)+2.d0*YE*(YASS/YA0-YBSS/YB0)
!	write(*,*) 'YE,YA0,YB0,YAS,YBS,YVS',YE,YA0,YB0,YAS,YBS,YVS
!	write(*,*) 'exp,yvb0',
!    .	dexp(-YX2*(YVb0-1.d0)**2/VtdVb2)*yVb0/DSQRT(YGAM),yVb0
	Ycoef	= dexp(-YX2*(YVb0-1.d0)**2/VtdVb2)*yVb0/DSQRT(YGAM)
     .		*(1.d0+MVth24*YSS2/YGAM
     .		+1.5d0*(1.d0-1.d0/yVb0)/YGAM**2
     .		*(MVth2*YSS-VtdVb2/YVS**2))
		YSIG	=dEXP(-YBG/YVS/YSQ)/YE*YA0/YB0*yVb0*Ycoef	!!!
	else
		YVS	=YX
		YE	=YECM*YX2
		YA0	=YA1+YE*(YA2+YE*(YA3+YE*(YA4+YE*YA5)))
    		YB0	=1.d0+YE*(YB1+YE*(YB2+YE*(YB3+YE*YB4)))
		YSIG	=dEXP(-YBG/YVS/YSQ)/YE*YA0/YB0
	endif
      		svdtbp	=svdtbp+ YSIG/(1.+YXC3/YX3)
	endif
	 enddo 
!======================================================== Test
!
	goto 99			!No test print
		YX	=1.d0
		YE	=YECM*YX2
		YA0	=YA1+YE*(YA2+YE*(YA3+YE*(YA4+YE*YA5)))
    		YB0	=1.d0+YE*(YB1+YE*(YB2+YE*(YB3+YE*YB4)))
		YSIG1	=dEXP(-YBG/YX/YSQ)/YE*YA0/YB0*YX
!!=Svt0 = Sigma*V(Ebeam) [10^-24 m3/s]
	write(*,*) 'TE,TI,EBEAM,Svt/Svt0,Svt0=',
     .	yTEj,yTIj,yEBEAM,Ysig/Ysig1,Ysig1
     .	*4.38d-2*DSQRT(yEBEAM/yABEAM)	
!========================================================
  99	svdtbp	=svdtbp*YDS*1.d-3*
     * 	4.38d-4*DSQRT(yEBEAM/yABEAM)*
     *	2.d0*yABEAM/yNEJ*yTEJ*DSQRT(yTEJ)/YLE
	return
	end
!===================================================================
C=======================================================================
C VINT:	Volume integral {0,R} of any array
C Only a radially dependent array may be the 1st parameter of the function
C Examples:
C    out\Vint(CAR3)	!Radial profile of CAR3 volume integral
C    out_Vint(CAR3,Ro); !Volume integral {0,Ro} of CAR3
C    out_Vint(CAR3B)    !Total volume integral of CAR3 (0,ROC)
C			(Yushmanov 26-DEC-90)
	double precision function VINT(ARR,YR)
	implicit none
	double precision	ARR(*)
	include	'for/parameter.inc'
!	include 'for/const.inc'
!	include 'for/status.inc'
	include 'for/solsrs_IMAS.inc'
!	include 'for/yrjkdr.inc'
Changed 12.05.2009 (Pereverzev)
	double precision	YR,YDR,YR1
	integer JK,J 

	VINT=0.
	do 1 J=1,NA1
 1	VINT=VINT+ARR(J)*VR(J)
	VINT=HRO*VINT
	end
C======================================================================|
	subroutine	SMOOTH(ALFA,NO,FO,XO,N,FN,XN)
C----------------------------------------------------------------------|
	implicit none
	include	'for/parameter.inc'
	integer	NO,N,J,I
	double precision	ALFA,XO(*),FO(*),XN(*),FN(*),P(NRD)
	double precision	YF,YX,YP,YQ,YD,FJ
	if (N .gt. NRD .or. NO .le. 0)	then
		write(*,*)' >>> SMOOTH: array is out of limits'
		return
	endif
	if (NO .eq. 1)	then
	   do	j=1,N
		FN(j) = FO(1)
	   enddo
	   return
	endif
	if (NO .eq. 2)	then
	  do	j=1,N
	   FN(j)=(FO(2)*(XN(j)-XO(1))-FO(1)*(XN(j)-XO(2)))/(XO(2)-XO(1))
	  enddo
	  return
	endif
	if (N .lt. 2)	then
		write(*,*)' >>> SMOOTH: no output grid is provided'
!		call	a_stop
	    return
	endif
	if (abs(XO(NO)-XN(N)) .gt. XN(N)/N)	then
	    write(*,*)'>>> SMOOTH: grids are not aligned'
	    write(*,'(1A23,I4,F8.4)')'     Old grid size/edge',NO,XO(NO)
	    write(*,'(1A23,I4,F8.4)')'     New grid size/edge',N,XN(N)
!call	a_stop
            return
	endif
	do	1	j=2,N
	   YP = (XN(j)-XN(j-1))
	   if (YP .le. 0.d0)	then
	write(*,*)'>>> SMOOTH: new grid is not increasing monotonically'
	      write(*,'(A,I4,A,F8.4)')'Node ',j-1,'   Value',XN(j-1)
	      write(*,'(A,I4,A,F8.4)')'Node ',j,  '   Value',XN(j)
	      return
	   endif
	   P(j)	=ALFA/YP/XO(NO)**2
 1	continue
	P(1)	=0.
	FN(1)	=0.
	I	=1
	YF	=(FO(2)-FO(1))/(XO(2)-XO(1))
	YX	=2./(XN(2)+XN(1))
	YP	=0.
	YQ	=0.
	do	5	j=1,N-1
		if(XO(I) .gt. XN(j))	GO TO 4
 3		I	=I+1
		if(I .gt. NO)	I=NO
		if(I .ne. NO .and. XO(I) .lt. XN(j))	GOTO	3
		YF	=(FO(I)-FO(I-1))/(XO(I)-XO(I-1))
 4		FJ	=FO(I)+YF*(XN(j)-XO(I))
		YD=1.+YX*(YP+P(j+1))
		P(j)	=YX*P(j+1)/YD
		FN(j)	=(FJ+YX*YQ)/YD
		if (j .eq. N-1)	goto	5
		YX	=2./(XN(j+2)-XN(j))
		YP	=(1.-P(j))*P(j+1)
		YQ	=FN(j)*P(j+1)
 5	continue
	FN(N)	=FO(NO)
	do	6	j=N-1,1,-1
		FN(j)	=P(j)*FN(j+1)+FN(j)
 6	continue
	end
C======================================================================|


