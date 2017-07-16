      SUBROUTINE srs_feed()
c------------------------------------
c   diffusion coeficient and particles sources
c----------------------------------------------
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	include 'parf0'
	common
     *	/n_m/n,m,mp
        common
     *  /ge2/NTAY,TAY,TT
     *  /ge3/AI(npo),A0(npo),HA2(npo),a(npo),ha(npo)
     *  /ge5/kpr
     *  /ge8/pcch
     *  /ge8e/pcchp
      COMMON
     *  /en5/SD0(npo),ST0(npo),SH0(npo)
     *  /en6/VI(npo)

        character *20 apr


      i_en=i_en+1
      
      if(i_en.eq.1)coef=1.d0
      
	src=0.
	src2=0.
      alf=(pcchp-pcch)/tay

      ro_ech=0.8d0
      del_ech=0.25d0

      ro_ech=0.8d0
      del_ech=0.25d0
      

	if(kpr.eq.1)print *,' pcchp pcch=',pcchp,pcch
	if(kpr.eq.1)print *,' ro_ech del_ech=',ro_ech,del_ech
      
      coef=coef+alf*tay
      vol=0.d0

      if(coef.le.0.d0)coef=0.d0
      
      DO I=2,N
!	sd0(i)=(1-ai(i)**2)*1.e-2*coef
!	st0(i)=(1-ai(i)**2)*1.e-2*coef

	sd0(i)=exp( -( (ai(i)-ro_ech)/del_ech )**2 )*1.e-2*coef
	st0(i)=exp( -( (ai(i)-ro_ech)/del_ech )**2 )*1.e-2*coef

!	sd0(i)=(1-ai(i)**2)*1.e-2*coef
	src=src+sd0(i)*vi(i)*ha(i)
	src2=src2+st0(i)*vi(i)*ha(i)
	vol=vol+vi(i)*ha(i)
      end do
      src=src/vol
      src2=src2/vol

!      alf1=alf/(src+ src2)

      apr='sd0 TP'
      if(kpr.eq.1)PRINT 71,apr,(sd0(i),i=1,n)
      apr='st0 TP'
      if(kpr.eq.1)PRINT 71,apr,(st0(i),i=1,n)

   71 FORMAT(20X,A6/,(8E10.3))

	if(kpr.eq.1)print *,' src coef==',(src+src2),coef
	if(kpr.eq.1)print *,' alf alf1==',alf,alf1

	
      RETURN
      END


      subroutine solpsz()
	include 'double.inc'

      include 'parf0'

	common
     *	/n_m/n,m,mp

	common 
     *  /c_temp4/wdrp
!     *  /c_temp5/YTe,YTi,YGsep,Yne,YGsol
!     *  /c_temp6/YPsol,Ycnim,YSeng,Yqpk,Yndt
     *  /c_temp5/YMU,YPsol,YPalp,YSeng,YdNdt,YAim,Ycnim,YPedPi,
     .	YGdt,YGpuf,YGpel,YGhe,YGsol,YGsep,
     .	Ypn,Yqpk,Yndt,YnHe,Yne,YTe,YTi,
     .	yGELM,yGLFS


     */en2/TE0(npo),TQ0(npo),TEN(npo),TQN(npo),
     *WE0(npo),WQ0(npo)

     			YMU=0.8d0
!            YPsol=10.d0
            YPalp=0.d0
            YSeng=57.d0
            YAim=20.d0
            Ycnim=0.02d0
            YPedPi=1.d0


!            WDRp=(WD0(N)+WT0(N)+WH0(N))*2.*PI

     			YGsol=wdrp*1.d3
     			
     			if(kpr.eq.1)print *,' YGsol YPsol=',YGsol,YPsol
     			
     			yGELM=0.d0
     			yGLFS=0.d0

!     YMU, 	[a.u.], 0.2<mu<1 in SOLPS mu=1 corresponds to attachment - =0.8 - comment by Victor 
!	YPsol, 	[MW] power to SOL 
!	YPalp,	[MW] power in alpha particle -----comment by victor from Pacher 
! 	YSeng, 	[m3/s] pumping speed - =57 - comment by Victor
! 	YAIM,	[a.u.] sort of imp. in atomic units - =20 for Neon - comment by Victor
!	Ycnim,	nim/ne fraction of impurity at sep.
!	YPedPi, [a.u.]	Pe/Pi=1 by Polevoi - comment by Victor
!	YGsol,	[10^19/s] sink of DT to the SOL by diffusion
!	YGELM,  [10^19/s] sink of DT to the SOL with ELMs =0 still now - comment by Victor
!	yGLFS,	[10^19/s] sink of DT to the SOL from LFS pellet drift (ideal) =0 - comment by Victor

	call solpsz2(
     .			YMU,YPsol,YPalp,YSeng,YdNdt,YAim,Ycnim,YPedPi,
     .			YGdt,YGpuf,YGpel,YGhe,YGsol,YGsep,
     .			Ypn,Yqpk,Yndt,YnHe,Yne,YTe,YTi
     .		,yGELM,yGLFS)


     			if(kpr.eq.1)print *,' YTe,YTi=',YTe,YTi
     			if(kpr.eq.1)print *,' YGsep,Yne=',YGsep,Yne

      te0(n)=YTe*1.d3
      tq0(n)=YTi*1.d3

	return
	end
