
!============================================================================
	subroutine solpsz3(
     .			YMU,YPsol,YPalp,YSeng,YdNdt,YAim,Ycnim,YPedPi,
     .			YGdt,YGpuf,YGpel,YGhe,YGsol,YGsep,
     .			Ypn,Yqpk,Yndt,YnHe,Yne,YTe,YTi
     .		,yGELM,yGLFS)
	implicit none
!===========================================================================
! update  to H.D. Pacher et al, Jorn. of Nucl. Materials 463 (2015) 591-595
! A.R. Polevoi version 19-05-2016
!======================================================================= Input
!	YPsol, 	[MW] power to SOL 
!	YPalp,	[MW] power source from He in fusion
! 	YSeng, 	[m3/s] pumping speed 
! 	YAIM,	[a.u.] sort of imp. in atomic units
!	Ycnim,	nim/ne fraction of impurity at sep.
!	YPedPi, [a.u.]	Pe/Pi
!	YGsol,	[10^19/s] sink of DT to the SOL by diffusion
!	YGELM,  [10^19/s] sink of DT to the SOL with ELMs
!	yGLFS,	[10^19/s] sink of DT to the SOL from LFS pellet drift (ideal)
!solpsz3	yGpuf,	[10^19/s] gas puf to the SOL 
!======================================================================= Output
!solpsz3	YMU, 	[a.u.], 0.2<mu<1 in SOLPS mu=1 corresponds to attachment  
! 	YdNdt,	[10^19/s] speed of change of the numer of plasma prtcls
!	YGdt,	[10^19/s] particle flux to the pump
!	YGpel,	[10^19/s] core fuelling by pellets 
!	YGhe,	[10^19/s] core fuelling by He through separatrix
!	YGsep,	[10^19/s] core fuelling due to gas penetration
!  	Ypn,	[Pa]	pressure of neurtals at pump
!	Yqpk,	[MW/m2]	heat load to the plate
!	Yndt,	[10^19m-3] sep. D+T density 
!	YnHe,	[10^19m-3] sep He density
!	Yne,	[10^19m-3] sep e density
!	YTe,	[keV] sep. el. termperature
!	YTi	[keV] sep. ion temperature
!========================================
! the same in SOLPS units P_= P/100, Sn =Seng/56.6 
!     .			MU,P_,Sn,dNdt,AIM,cnim,PedPi,
!     .			Gdt,Gpuf,Gpel,Ghe,Gsol,
!     .			pn,qpk,ndt,nHe,Te,Ti
!==================================================
	real*8	
     .		YMU,YPsol,YPalp,Yalp,YSeng,YdNdt,YAIM,Ycnim,YPedPi,
     .			YGdt,YGpuf,YGpel,YGhe,YGsol,YGsep,
     .			Ypn,Yqpk,Yndt,YnHe,Yne,YTe,YTi
     .		,yGELM,yGLFS
	real*8
     .			MU,P_,Sn,dNdt,AIM,cnim,PedPi,
     .			Gdt,Gpuf,Gpel,Ghe,Gsol,Gsep,
     .			pn,qpk,ndt,nHe,ne,Te,Ti,Diff,nim
     .		,GELM,GLFS
	integer	iimp,nimp
	parameter(nimp=3)
	real*4 CZsep_,CZsep,fmu,fHe,knZ,kHeint,kHehigh,facZ,
     .	CN,CG,CMU,CT,Zim,ndtZ,y1,y2,y3,y4,yZ

		CN	=10.
		CT	=1000.
		CG	=54.
!==========================================
	if(Yaim.lt.11.d0.or.Yaim.gt.21.d0) then
		write(*,*) 'No data for Aim = ',Aim	
		return
	endif

!=============================================
!solpsz3 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
!solpsz3	if(ymu.le.2.d0.or.ymu.ge..2d0) then
!solpsz3		mu	=ymu
!solpsz3	else 
!solpsz3		write(*,*) 'YMU =',YMU,' is out of (0.2-2)'
!solpsz3		write(*,*) 'continue with YMU = 1'
!solpsz3		mu	=1.d0
!solpsz3	endif
!============================================================
		P_ 	= max(YPsol,.001d0)/100.d0	
		Sn 	= YSeng/57.	! 19-05
		Sn	= max(Sn,1.d-10)
!		dNdt 	= YdNdt/CG
	if(Ycnim.lt..002d0) then
		write(*,*) 
     .	'nim/ne = ',Ycnim,
     .	'is out of range 0.002-0.02.'
		if(Ycnim.lt..0001d0) then
		write(*,*) 
     .	'continue with 0.0001'
		Ycnim	=0.0001
		endif
	endif
	if(Ycnim.gt..02d0) then
		write(*,*) 
     .	'nim/ne = ',Ycnim,
     .	'is out of range 0.002-0.02. continue with 0.02'
		Ycnim	=0.02
	endif

		cnim 	= Ycnim
		CZsep	=cnim
		CZsep_	=CZsep/0.004	
!		neped	= Yneped/CN
		Gpel	= YGpel/CG
		Gsol	= YGsol/CG
		GELM	= yGELM/CG
		GLFS	= yGLFS/CG
		
!solpsz3				!31-07-2020
!solpsz3 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
		GPUF	=yGPUF/CG
		Gdt	= Gpuf + Gsol + GELM +GLFS	
! 31-07-2020 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		PedPi	= YPedPi
		fHe	= 1.05*Ypalp/Ypsol
	if(Yaim.lt.13.d0.and.Yaim.gt.11.d0) then
! Carbon
		CMU	= 5.	!?????????????????
		knZ	=.34
		yZ	=2.5
		facZ	=0.
!solpsz3				!31-07-2020
!solpsz3 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
		MU	=(Gdt/127.)**.825/P_**.52
		pn	=5.*MU*P_**.34
!solpsz3		Gdt	=18.*Sn*pn**1.212*P_**.22
! 31-07-2020 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
! MU	=(Gdt/127.)**.825/P_**.52
	else
! Ne, N
!solpsz3				!31-07-2020
!solpsz3 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
		MU	=(Gdt/254.)**.825/P_**.52
		pn	=8.98*MU*P_**.39
! 31-07-2020 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
!solpsz3		Gdt	=17.7*Sn*pn**1.212*P_**.16
! MU	=(Gdt/254.)**.825/P_**.52
		CMU	= 8.98
		yZ	=5.0
	endif
!====================================================
!!		Gdt	= 18.87*Sn*mu*CMU
!!		pn	=Gdt/(18.87*Sn)
C- 05-03-2015		Gpuf	= Gdt - Gsol
!solpsz3		Gpuf	= Gdt - Gsol - GELM -GLFS	!05-03-2015
		
	if(Gpuf.lt.0d0) then
	write(*,*) 'Gsol+GELM+GLFS =', Gsol+GELM+GLFS,'> Gdt =',Gdt
		Gpuf=0.d0
!		return	! 15-JAN-2016
	endif
	if(Yaim.lt.15.d0.and.Yaim.gt.13.d0) then
!		Nitrogen
		Zim	=7.
		kHeint	=.024
		kHehigh =.014
		knZ	=.57
		facZ	= 40.
	else
! Neon
		Zim	=10.
		kHeint	=.008
		kHehigh =.0055
		knZ	=.68
		facZ	=80.

	endif
!============================================
	if(mu.ge.1.d0) 
     . 		fmu	=mu**.03
	if(Yaim.lt.13.d0.and.Yaim.gt.11.d0) then	! Carbon
		nHe	=.0055*P_**0.6/mu**1.75*fHe/Sn
		GHe	=.0062/P_**.6/mu**1.18*fHe/Sn
	if(mu.lt.1.d0) then
		y1	=-.75*(abs(log(mu)/log(10.)))**2.5
		fmu	=10.**y1
	endif
	else
		y1	=kHeint/mu**.46/CZsep_**.57	! 19-05-2015
		y2	=kHehigh*P_**1.18/mu**1.42
		y3	=.0016/mu**1.9/CZsep_**.35	! 19-05-2015
		y4	=min(y1,y2)
		nHe	=max(y3,y4)*fHe/Sn**.93		! 19-05-2015

		GHe	=2.*nHe/P_/mu**.33*CZsep_**.35	! 19-05-2015

		if(mu.lt.1.d0) then
			y1	=-.75*(abs(log(mu)/log(10.)))**5
			fmu	=10.**y1
		endif

	endif
		ndtZ	=knZ*fmu*P_**.7*(1.+.15*Gsol/Gdt)*Sn**.07 ! 19-05-2015
		ne	= (ndtZ+2.*nHe)/(1.+cnim*(facZ-Zim))
		nim	=cnim*ne
		ndt	=ndtZ-facZ*nim


	if(Yaim.lt.13.d0.and.Yaim.gt.11.d0) then
		Gsep	=.031/P_**1.4/mu**.27			
		qpk	=6.66*P_**1.5/mu**.6
		Te	=pedpi**.05*165.*P_**.33/mu**.063
		Ti	=280.*P_**.31/mu**.12
     .			/pedpi**.13/(1.+.008*(Gsol/Gdt))

	else
	if(Yaim.lt.15.d0.and.Yaim.gt.13.d0) then
! Nitrogen
		Gsep	=.0053/P_**1.6/mu**.65*CZsep_**.58/Sn**.38 ! 19-05-2015
		y2	=3.45*P_**1.44/mu**.825
		y3	=5.819*P_**1.12/mu**.319/CZsep_**.19
		qpk	=max(y2,y3)
		y1	=140./mu**.093*CZsep_**.037
		y2	=150.*CZsep_**.063
		Te	=pedpi**.05*max(y2,y1)*P_**.31	!19-05-2015
		y1	=200./mu**.19*CZsep_**.12		!19-05-2015
		y2	=230.*CZsep_**.105
		Ti	=max(y2,y1)*P_**.27
     .			/pedpi**.13/(1.+.08*(Gsol/Gdt))	! 19-05-2015

	else
! Neon
		Gsep	=.0053/P_**1.6/mu**.65*CZsep_**.86/Sn**.38 ! 19-05-2015
!	write(*,*) 1/P_**1.6,1/mu**.65,CZsep_**.86,(Gdt+.25*Gsol)
		y2	=4.011*P_**1.44/mu**.825
		y3	=5.819*P_**1.12/mu**.319/CZsep_**.29
		qpk	=max(y2,y3)
		y1	=140./mu**.093*CZsep_**.046
		y2	=150.*CZsep_**.092
		Te	=pedpi**.05*max(y2,y1)*P_**.31	!19-05-2015
		y1	=200./mu**.19*CZsep_**.23		!19-05-2015
		y2	=230.*CZsep_**.105
		Ti	=max(y2,y1)*P_**.27
     .			/pedpi**.13/(1.+.08*(Gsol/Gdt))	! 19-05-2015
	endif
	endif
!!	if(Gsep.lt..5d0) then
!!		write(*,*) 'Gsep is out interpolation range'
!!		Gsep=0.5
!!	endif	
		Gsep	=Gsep*(Gdt+.25*Gsol)
!!	write(*,*) 'P_,mu,CZsep_,Sn=',P_,mu,CZsep_,Sn
!!	write(*,*) 'Gsep,Gsol,Gdt=',Gsep,Gsol,Gdt
	if(Gsep.lt..5d0) then
		write(*,*) 'Gsep is out interpolation range'
		Gsep=0.5
	endif	

		
!======================
C- 05-03-2015	
		dNdt	= Gpel + Gsep - Gsol - GELM
		
		write(*,*) 'Gsep is out interpolation range'

!========== out
		YdNdt 	= dNdt*CG
		YGdt	= Gdt*CG
		YGpuf	= Gpuf*CG
		YGsep	= Gsep*CG
		YGhe	= Ghe*CG/2. ! molecular
		YGsol	= Gsol*CG
		Ypn	= pn
		YnHe	= nHe*CN
		Yne	= ne*CN
		Yndt	= ndt*CN
		Yqpk	= qpk
		Yte	= Te/CT
		YTi	= Ti/CT
!solpsz3 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
		ymu	=mu

!  	Ypn,	[Pa]	pressure of neurtals at pump
!	Yqpk,	[MW/m2]	heat load to the plate
!	Yndt,	[10^19m-3] sep. D+T density 
!	YnHe,	[10^19m-3] sep He density
!	Yne,	[10^19m-3] sep e density
!	YTe,	[keV] sep. el. termperature
!	YTi	[keV] sep. ion temperature
!==================================================
	return
	end

