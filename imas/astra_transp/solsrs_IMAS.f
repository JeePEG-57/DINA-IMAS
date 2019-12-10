	subroutine solsrs_IMAS(
     1  yMu,Ycnim,ySeng,yGsol,yPsol_,yPalp,yGNBI,
     2  yL_OH,
     2  yNe,yndt,ynHe,yTe,yTi,yGdt,yGHFS,yGELM,ySpel,
     3  yGpuf,yGsep,ySsep,yqpk)
     

! Total particle source for pellet+puffing in permanent pellet/ELM approximation for ITER
!================================ 05-03-2015, 29-07-2015, 11-12-2015, 20-05-2016
!             GHFS for dNdt =0.
!	extended to H-L-OH confinement
!		yL_OH =0(1) L&OH (H)
! 		yMod = 0.4 (1) OH and L-mode (H-mode)
!	Current and L/OH dependence is included
!		Lq ~ 1/Ip/sqrt(chiL/chiH)
!==========================================================
! IN:
!	yMu	[a.u.]	normalised pressure in the div. (must be < 1)
!	ySeng	[m3/s]		engineering pumping speed (must be < 75)
! 	yGsol	[10^19/s]	diffusive flux to the SOL 
! (note that for stable simulation we suggest to use a preset target value, rather than istanteneouse)
!	yPsol_	[MW] 		power to SOL (we used Palp+Paux-Prad)
!	yPalp	[MW]		fusion source in alphas
!	Ycnim	nimp/nes	fraction of Ne at the edge (should be 0.02-0.002)
!	yGNBI	[10^19/s]	particle source-sink (GNBI - recombination)  
!	yL_OH	[a.u.]		=0(1)switch betwee OH&L mode (H-mode)
! OUT:
!	yNe	[10^19m-3]	separatrix electron density 
!	Yndt,	[10^19m-3] 	separatrix (d+t+h) density
!	YnHe,	[10^19m-3] 	separatrix He density
!	yTe	[keV]		separatrix temperature (electrons)
!	yTi	[keV]		separatrix temperature (ions)
!	yGdt	[10^19/s]	ion troughput (must be < 10800 (200Pam3/spumping limit)) 
!	yGHFS	[10^19/s]	source from HFS pellet fuelling ,ySpel,yGpuf,yGsep,yqpk,ySsep,
!	yGELM	[10^19/s]	sink with ELMs (H-mode only)
!	ySpel	[10^19/s/m3]	voulmetric source from pellets - sink with ELMs
!	yGpuf	[10^19/s]	divertor fuelling to provide chosen detachment conrol yMu (must be > 0)
!	yGsep	[10^19/s]	source from the edge neutrals which penetrate to the core
!	ySsep	[10^19/s/m3]	voulmetric source from the edge neutrals which penetrate to the core
!	yqpk	[MW/m2]		peaked power load on the divertor plate
!================================================Polevoi ver 11-12-2014
!	yNeped	[10^19m-3]	pedestal density (is calulated inside solsrs from ne at the point predicrted by EPED1 scaling)
!================================================================
! Wrapper for SOLPS for Ne with EPED1 pedestal
!====================================================================== 
	implicit none
	include	'for/parameter.inc'
	include 'tmp/declar.fnc'
	include 'tmp/declar.fml'

        include 'for/solsrs_IMAS.inc'
!	include 'for/const.inc'
!	include 'for/status.inc'

      common
     *  /ge5/kpr

        
	real*8	
     .			YMU,YPsol,YPalp,YSeng,YdNdt,YAim,Ycnim,YPedPi,
     .			YGdt,YGpuf,YGpel,YGhe,YGsol,YGsep,
     .			Ypn,Yqpk,Yndt,YnHe,Yne,YTe,YTi,Yneped,
     .			YSn,ynBe,ynH,yGH,yGHe_,yGH_, 
     .			yGHeS,yGHS,yGBeS,YPsol_,yT,yni
	real*8
     .		ySLATB,yDSOL,yPped,yIpl,yBtor,yAmain,yneaver,
     .		yxeff,YDiff,yPLH,yneold,ynerr,ynHep
	real*8
     .		yVOLUME,yDWELM,yALP,yfpel,yGELM,yVpel,yNpel,yfHFS,
     .		yGLFS,yGHFS,yswitch
	real*8
     .	yNpelH,yNpelL,yVpelH,yVpelL,yGNBI,ySRS0,YDABL,YDDEP,
     .	ySsep(nrd),ySpel(*)
	character*12 varnam(21),varnam1(13),varnam2(3)
	character*17 filnam
	real*8
     .		yELONG,yABC,yTauE,yTaup,yCoef,yTAUOH,yRTOR,yL_OH,yMod,yGHFS1

	integer j,jiter,niter,jneped,jmu,jpsol,kpr

!========================================
	data 	
     .	YAim/20.d0/,YPedPi/1.d0/
	data 
     .	yGpel/0.d0/,
     .	yGhe/0.d0/,
     .	ypn/0.d0/,ydndt/0.d0/
	data filnam/'dat/solFuel.out'/

!================================== Pellet size for HFS and LFS mm3:
	yVpelH	=33.d0
	yVpelL	=33.d0	
!=============================================
!
!	write(*,*) 'start'
	  if(yL_OH.lt.0.5) then 
		yMod	=0.4
	else
		yMod	=1.
	endif
		yPsol	= yPsol_*yMod*(15./IPL)
!===================================

		yBtor	=BTOR	!5.3	!Btor, T
		yIpl	=IPL	!15.	! Ipl, MA

		yPped	=130.*(yIpl/15.*(yBtor/5.3)**.84) !EPED1 pressure Ptop, kPa
!		yDSOL	=ROC*.056*1.5*sqrt(yPped/1.28)/yIPL	!EPED1 ped. width, (Rhoc=2.6) m
		yDSOL	=.056*1.5*sqrt(yPped/1.28)/yIPL		!EPED1 scaling for DpedNorm
!	j=0.9*NA1
	j=(1.-yDSOL)*NA1
		yNeped	= NE(j)	!NECHR(0.01d0)
!		yAmain	=AMAIN(1)	!2.5	! Amain a.u.
!		ySLATB	=SLAT(NA1) !672.	!external surface, m2
!		yxeff	=yDSOL/ySLATB*1.d3/yPped !(xe+xi)/2/Psol, m2/s
!============================================== for pellet
!		yVOLUME	=VOLUME	!800.	! V, m3
		yDWELM	=0.6	! DWELM, MJ
		yALP	=0.2	! DWELMxfpel	= yALPxPsol
		yNpel	=6.*0.9*yVpel	!10^19 Number of pel prtcls after 10 % loss
		yNpelH	=6.*0.9*yVpelH	!10^19 Number of pel prtcls after 10 % loss
		yNpelL	=6.*0.9*yVpelL	!10^19 Number of pel prtcls after 10 % loss
		yELONG	=ELONG
		yABC	=ABC
		yRTOR	=RTOR


! initial itteration
		jmu	=0
 991	format(1I1)
 992	format(1I2)

!ymu=1.d0,0.2d0,-.2d0
!		ymu=0.8		!1.d0-.2d0*(jmu-1)
!======================================================= fixed mu

		ynerr	=.001
		yNe	=.2d0	!initial guess about the nesep
		jiter	=0
		niter	= 100
	yGsep=0.
 1		jiter	=jiter + 1
		yneold	=yne
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(yneped.lt.yne) then
!	write(*,*) 'Warning:	solped: nped=',yneped,' < nsep '
!	write(*,*) jiter,'		increase nped to ',
!     .	yne	
		yneped	=yne	
		endif
!>>>>>>>>>>>>>>>>>>>>>>>>>>>>> for DINA
!	  ENWM=yTi
!	  ENCL=yTi


!>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 
	if(yL_OH.lt.0.5d0) then				! L,OH-mode
!!!		yGHFS	= max((yGsol-yGNBI-yGsep),0.d0)
		yfHFS	= yGHFS/yNpelH
		yfpel	= yfHFS
		yGLFS	= 0.
		yGELM	=0.
	else						! H-mode
!==================================
! pellets only for fuelling
		yGELM	= yALP*yPsol*yneped/1.5*(1.d3/yPped)	! New
!!!		yGHFS	= max((yGELM+yGsol-yGsep-yGNBI),.0d0)
         
		 yGHFS1=216.*54.
         if(kpr.eq.1)print *,' yGHFS yGHFS1=',yGHFS,yGHFS1
         
		if(yGHFS.gt.(216.*54.)) then
		yGHFS=216.*54.
		if(kpr.eq.1)then
		write(*,*) 
     .  'required pellet fuelling exceeds the maximum Gpel=216 PAm3/s ',
     .  'pellet fuelling was set at maximum GHFS=216 PAm3/s'
        end if
		endif
		yfHFS	= max((yGHFS/yNpelH),.0d0) 
		yGLFS	= 0.d0
		yfpel	= yfHFS	 
!	write(*,*) 'yGELM,yGHFS,yGsol,yGsep,yfHS= ',
!     .	yGELM,yGHFS,yGsol,yGsep,yfHFS
	endif
!============================================================================

	if(jiter.eq.1) YGpel=0.
!	data YDL /1.46d0, 1.46d0, 1.53d0, 1.58d0, 1.5d0/	! U0 50 grad
!	data YCOS0/0.68d0, 0.94d0, 0.652d0, 0.85d0, 0.86d0/	! U0 50 grad
!	data YDL /1.46d0, 1.46d0, 1.66d0, 1.67d0, 1.5d0/	! U,L 53 grad
!	data YCOS0/0.68d0, 0.94d0, 0.6d0, 0.80d0, 0.86d0/	! U,L 53 grad

!	call pelsrs(YAM,YVP,YVOL,YCOS0,YEFF,YDL,YDABL,YDDEP,YPELSRS)
! source from pellet
	yswitch=-1.	!permanent ELM
!	write(*,*) 'before pelsrs1_IMAS'
	call pelsrs1_IMAS
     .	(1.d0,0.3d0,YVpelH,0.8d0,1.d0,1.67d0,YDABL,YDDEP,ySpel,yswitch)
		ySRS0	=VINT(ySpel,ROC)
!	write(*,*) 'ySpel', (ySpel(j),j=1,na1)
!	   write(*,*) 'ENCL,ENWM,Spel =',ENCL,ENWM,ySRS0
!	
! Source from the edge
!	write(*,*) 'before neutex_imas'
	call neutex_imas
!=========================
	do j=1,na1 
!	include 'fml/snneu'
	include	'fml/svie'
	include	'fml/svii'
	include	'fml/svrec'
!	SNNEU = (SVIE+SVII*NI(J)/NE(J))*(NNCL+NNWM)*NN(J)-SVREC*NI(J)
		ySsep(j)	=ne(j)
     >	*(SVIE+SVII*NI(J)/NE(J))*NN(J)
	if(ySRS0.le.0.d0) then
		ySpel(j)	=0.d0
			else
		ySpel(j)	=ySpel(j)/ySRS0*(yGHFS-yGELM)
	endif		
	enddo
		ySRS0	=VINT(ySsep,ROC)
!	if(ySRS0.gt.0.d0.and.yGsep.gt.0.d0) NNCL=NNCL*yGsep/ySRS0
	if(ySRS0.gt.0.d0.and.yGsep.gt.0.d0) NNCL=yGsep/ySRS0
	do j=1,NA1
		ySsep(j)	=ySsep(j)*NNCL
	enddo
!		write(*,*) 'before solpsz2'


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	call 	solpsz2(
     .			YMU,YPsol,YPalp,YSeng,YdNdt,YAim,Ycnim,YPedPi,
     .			YGdt,YGpuf,YGHFS,YGhe,YGsol,YGsep,
     .			Ypn,Yqpk,Yndt,YnHe,Yne,YTe,YTi
     .		,yGELM,yGLFS)
!          new
         ENCL=max(ENCL,YTi)
         ENWM=ENCL
!	write(*,*) 'neped,ne	= ',Yneped,yne	
	if(jiter.eq.niter) write(*,*) 
     .	'no covergency for MU,Psol,neped =',yMU,yPsol,yneped
	if(abs((yneold-yne)/yne).gt.ynerr.and.jiter.lt.niter) goto 1 
!	write(*,*) 'yne,jiter,niter= ',yne,jiter,niter
!=======================================================================

	if(yqpk.gt.10.d0) 
     .	write(*,*) 'div. load, qpk=',yqpk,' > 10 MA/m2'
	if(yGpuf.lt.0.d0) 
     .	write(*,*) 'Gpuf =',yGpuf/54,' < 0'
	if(yGdt/54.d0.gt.200.d0) then
     	write(*,*) 'Gdt =',yGdt/54,' > 200 Pam3/s'
        write(*,*) 'Gdt ~ Seng*yMu^1.2 ',
     .   'reduce pumping Seng (0- 75) or/and yMU (0.01-1)'
        endif
	if((yGHFS+yGLFS)/54.d0.gt.216.d0) 
     .	write(*,*) 'Gpel =',(yGHFS+yGLFS)/54,' > 240x0.9 Pam3/s'
!		write(*,*) 'after solpsz2'
!==============================================
!       edge density can be reduced by increase of impurity Ynim (< 0.02)
         
 888	format(2x,21(1xA8))
!	format(1X,21(1xA12))
 999	format(21(2xF7.3))
! 999	format(5(2xF7.3),1(1xF8.3),15(2xF7.3))
!	format(1X,21(1x1pE12.4))
!	stop
	return
	end
!============================================================================

