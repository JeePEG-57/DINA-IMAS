       subroutine main_astra(a_dina,pd0,pt0,pne,te0,tq0,n_dina,
     *  sd0_p,sd0_n,GHFS)
      
      	implicit none
	include  'for/parameter.inc'
	include 'for/solsrs_IMAS.inc'
      
      common
     *  /ge5/kpr
     
       common /c_solps1/yndt,yNe,yTe,yTi

	real*8	
     .	YMU,YPsol,YPalp,YSeng,YdNdt,YAim,Ycnim,YPedPi,
     .	YGdt,YGpuf,YGpel,YGhe,YGsol,YGsep,YGHFS,yGELM,
     .	Ypn,Yqpk,Yndt,YnHe,Yne,YTe,YTi,Yneped,
     .	YSn,ynBe,ynH,yGH,yGHe_,yGH_,yL_OH,yGNBI,yFniz1,
     .	yGHeS,yGHS,yGBeS,YPsol_,yT,yni,ySHe3,yFniz2,yFniz3,
     .	ySsep(nrd),ySpel(nrd),yPfus(nrd),
     .	ySd,ySt,ySh,ySHe,ySNe,ySBe,yPd,yPt,yPh,yFd,yFt,yFh
     
         integer j,i,i_en, na11, kpr
         
        double precision VINT
        
        real *8 a_dina(*),pd0(*),pt0(*),pne(*),te0(*),tq0(*),
     *  sd0_p(*),sd0_n(*)
     
        real *8 psn,ro_astra(nrd),pni(nrd),sdt(nrd),GHFS
        integer n_dina
        
!===============================
          GP=3.141592
          
          i_en=i_en+1
          
          if(i_en.eq.1)then
          
                  call srs_control_in(
     1  yMu,Ycnim,ySeng, yL_OH,
     2  yGsol,yPsol,yPalp,yGNBI,
     3  ySd,ySt,ySh,ySHe,yShe3,ySNe,ySBe,yPd,yPt,yPh,
     4  yFd,yFt,yFh,yFniz1,yFniz3)
!             write(*,*) 'passed srs_control_in'     
         call equilibrium_in(        
     3	BTOR,RTOR,ABC,AB,ROC,SHIFT,UPDWN,HRO,HROA,NA1,NB1,NAB,NA,
     4	VR,SHIF, SHIV, ELON, TRIA,
     5  AMETR,RHO,FP,MU,IPL)
     
        do i=1,na1
        ro_astra(i)=AMETR(i)/AMETR(na1)
        end do
        

          if(kpr.eq.1)  write(*,*) 'passed equilibrium_in'   
	call core_profiles_in(
     1	F0,F1,F2,F3,F4,
     2	F5,F6,F7,F8,F9, 
     3	ZIM1,ZIM2,ZIM3,TE,TI,NE,NI,
     4	NIBM,SNEBM,SNNBM,PBEAM,PFUS,
     5  EBEAM,ABEAM,
     6	AIM1,AIM2,AIM3,AMJ,ZMJ,AMAIN,ZMAIN,
     7  NA1,
     8  NHYDR,NDEUT,NTRIT,NALF,NHE3,NIZ1,NIZ2,NIZ3,
     9  ENCL,ENWM,NNWM,NNCL,yPalp,yGNBI,ROC)
       
         if(kpr.eq.1)  write(*,*) 'passed core_profiles_in' 
!          write(*,*) TE(1:na1)
!   	  write(*,*) TI(1:na1) 
!          write(*,*) NE(1:na1)
!   	  write(*,*) NI(1:na1)
   	  if(kpr.eq.1)write(*,*) 'ENWM,ENCL =', ENWM,ENCL


          do i=1,na1
!          te(i)=0.05*te(i)
!          ti(i)=0.05*ti(i)
!          ne(i)=0.01*ne(i)
!          ni(i)=0.01*ni(i)
          end do


      end if

        
        do i=1,na1
        pni(i)=pd0(i)+pt0(i)
        end do

!   	  write(*,*) 'Ro_astra ='
!   	  write(*,*) ro_astra(1:na1)

	do i=2,na1-1
	   psn=ro_astra(i)
	   call feeti(n_dina,pne,NE(i),a_dina,psn)
	   call feeti(n_dina,pni,Ni(i),a_dina,psn)
	   call feeti(n_dina,te0,TE(i),a_dina,psn)
	   te(i)=te(i)*1.d-3
	end do

	ne(na1)=pne(n_dina)
	ne(1)=pne(1)

	ni(na1)=pni(n_dina)
	ni(1)=pni(1)


	te(na1)=te0(n_dina)*1.d-3
	te(1)=te0(1)*1.d-3

!   	  write(*,*) 'NE='
!          write(*,*) NE(1:na1)


 !  	  write(*,*) 'TE='
 !               write(*,*) TE(1:na1)

!	yGHFS=yGHFS+1.
	
 35   continue	
	
	yGHFS=GHFS
	
!	yGHFS=2000.
	

      na11=na1
!	  open(1,file='te_data.dat')
!       	read(1,*)na11
       	if(kpr.eq.1)print *,' na1 na11=',na1,na11
!      	read(1,*)(te(i),i=1,na1)
!      	close (1) 

        if(kpr.eq.1)print *,'TE2 TI2==',te(2),ti(2)
        if(kpr.eq.1)print *,'TE TI==',te(90),ti(90)
        if(kpr.eq.1)print *,'TE TI==',te(na1),ti(na1)

        yL_OH=0.

      if(kpr.eq.1)print *,' i_en,yGHFS= yL_OH=',i_en,yGHFS,yL_OH
        
        call solsrs_IMAS( 
     1  yMu,Ycnim,ySeng,yGsol,yPsol,yPalp,yGNBI,
     2  yL_OH,
     2  yNe,yndt,ynHe,yTe,yTi,yGdt,yGHFS,yGELM,ySpel,
     3  yGpuf,yGsep,ySsep,yqpk)
     
!solsrs(yMu,Ycnim,ySeng,yGsol,yPsol,yPalp,yGNBI,yL_OH,yNe,ynHe,yTe,yTi,yGdt,yGHFS,yGELM,ySpel,yGpuf,yGsep,ySsep,yqpk)::.001;
!            write(*,*) 'passed solsrs_IMAS' 
!               	  write(*,*) 'NNWM,NNCL =', NNWM,NNCL
!               	   write(*,*) 'Sep',VINT(ySsep,ROC)
!               	   write(*,*) 'Spel',VINT(ySpel,ROC) 
!               	   write(*,*) 'SepR',ySsep(1:na1)
!               	   write(*,*) 'SpelR',ySpel(1:na1)
      if(kpr.eq.1)print *,' yndt== yNe ',yndt,yNe
      if(kpr.eq.1)print *,' yTe== yTi ',yTe,yTi
      
!      print *,'ySpel',(ySpel(i),i=1,na1)
!      print *,'ySsep',(ySsep(i),i=1,na1)

        if(kpr.eq.1)print *,'NE2 NI2==',ne(2),ni(2)
        if(kpr.eq.1)print *,'NE NI==',ne(90),ni(90)

        if(kpr.eq.1)print *,'TE2 TI2==',te(2),ti(2)
        if(kpr.eq.1)print *,'TE TI==',te(90),ti(90)

!	  open(1,file='te_data.dat')

!       	write(1,*)na1
!      	write(1,*)(te(i),i=1,na1)
      	
!      	close (1) 

        if(kpr.eq.1)print *,'ySpel ySsep==',ySpel(2),ySsep(2)
        if(kpr.eq.1)print *,'ySpel ySsep==',ySpel(90),ySsep(90)


        do i=1,na1
        sdt(i)=ySpel(i)
!        sdt(i)=0.5d0*sdt(i)*1.d-3
        end do


      	do i=2,n_dina-1
	   psn=a_dina(i)
	   call feeti(na1,sdt,sd0_p(i),ro_astra,psn)
	end do

	sd0_p(n_dina)=sdt(na1)
	sd0_p(1)=sdt(1)

        do i=1,na1
        sdt(i)=ySsep(i)
!        sdt(i)=0.5d0*sdt(i)*1.d-3
        end do


      	do i=2,n_dina-1
	   psn=a_dina(i)
	   call feeti(na1,sdt,sd0_n(i),ro_astra,psn)
	end do

	sd0_n(n_dina)=sdt(na1)
	sd0_n(1)=sdt(1)

      
!      print *,'sdt',(sdt(i),i=1,na1)
	
        call all_out(
     2  yGdt,yGHFS,yGELM,ySpel,
     3  yGpuf,yGsep,ySsep,yqpk,Ycnim,yNe,ynDT,ynHe,yTe,yTi,
     4  ySd,ySt,ySh,ySHe,yShe3,ySNe,ySBe,yPd,yPt,yPh,
     5  yFd,yFt,yFh,yFniz1,yFniz3)
          if(kpr.eq.1)  write(*,*) 'passed all_out' 
            
  !          stop
            
        end
!========================
        subroutine core_profiles_in(
     1	F0,F1,F2,F3,F4, 
     2	F5,F6,F7,F8,F9,
     3	ZIM1,ZIM2,ZIM3,TE,TI,NE,NI,
     4	NIBM,SNEBM,SNNBM,PBEAM,PFUS,
     5  EBEAM,ABEAM,
     6	AIM1,AIM2,AIM3,AMJ,ZMJ,AMAIN,ZMAIN,
     7  NA1,
     8  NHYDR,NDEUT,NTRIT,NALF,NHE3,NIZ1,NIZ2,NIZ3,
     9  ENCL,ENWM,NNWM,NNCL,yPalp,yGNBI,ROC)
        implicit none
!	include  'for/parameter.inc'
!	include 'for/solsrs_IMAS.inc'
        double precision
     1	F0(*),F1(*),F2(*),F3(*),F4(*),
     2	F5(*),F6(*),F7(*),F8(*),F9(*),
     3	ZIM1(*),ZIM2(*),ZIM3(*),TE(*),TI(*),NE(*),NI(*),
     4	NIBM(*),SNEBM(*),SNNBM(*),PBEAM(*),PFUS(*),
     5  EBEAM,ABEAM,ENCL,ENWM,NNWM,NNCL,
     6	AIM1,AIM2,AIM3,AMJ,ZMJ,AMAIN(*),ZMAIN(*),x,xx,
     7  NHYDR(*),NDEUT(*),NTRIT(*),NALF(*),NHE3(*),ROC,
     8  NIZ1(*),NIZ2(*),NIZ3(*),yPalp,yGNBI,vint
        integer na1,j,j1, kpr
! Units
! All densities, Fi,Ni,Ne [10^19m-3]
! All power densities, P [MW/m3]
! All powers , yP [MW]
! All temperatures and energies, T [keV]
! All particle sources densities, S [10^19/m3/s]
! All particle sources (fluxes), G,yG [10^19/s]
! All masses Ai =Mi/Mp in proton units
	EBEAM=1000.
	ABEAM=2.
! 3 impurities are foreseen, all masses shold be precsribed Ai > =1
	AIM1=9.
	AIM2=20.
	AIM3=9.
! main plasma
	AMJ=2.5
	ZMJ=1.
! cold neutrals (2 energy components)
    	   ENCL=0.002
	   ENWM=max(ENCL,TI(na1))
	   NNCL=1.d-3
	   NNWM=0. 
	xx=1./na1
!    	  write(*,*) 'read of prfl_in.dat is finished'
!  	  write(*,*) 'EBEAM,ABEAM,na1',EBEAM,ABEAM,na1
    	  do j=1,na1
    	  AMAIN(j) = AMJ
     	  ZMAIN(j) = ZMJ

    	  x=1.01-(j*xx)**2
    	  F0(j) = 10.*x ! thermal electrons
! Fi = thermal ion density 10^19m-3

     	  F1(j) = 0.1*x
     	  F2(j) = 5.*x
     	  F3(j) = 5.*x
     	  F4(j) = 0.1*x 
     	  F5(j) = 0.05*x
   	  F6(j) = 0.02*x
     	  F7(j) = 0.01*x
     	  F8(j) = 0.01*x
   	  F9(j) = 0.
! NBI parameters should be calculated by your NBI
   	  PBEAM(j) = 0.1*x ! MW/m3
   	  SNEBM(j) =PBEAM(J)/1.6/EBEAM ! 10^19/s
   	  NIBM(j) = 0.5*x
     	  SNNBM(j) = 0.	! source of neutrals from NBI CX
! initial guess froo densities
     	  NHYDR(j) = F1(j)
        if(ABEAM.eq.1.d0)  NHYDR(j) = F1(j)+NIBM(j)
     	  NDEUT(j) = F2(j)
        if(ABEAM.eq.2.d0)  NDEUT(j) = F2(j)+NIBM(j)    	  
     	  NTRIT(j) = F3(j)
     	  NALF(j) = F4(j)
     	  NHE3(j) = F5(j)
! impurities
     	  NIZ1(j) = F6(j)
      	  NIZ2(j) = F7(j)
     	  NIZ3(j) = F8(j)
! in SOLPS only N and Ne are foreseen for DIV control. Be is assumed ~ 2%   	  
     	  ZIM1(j) = 4.
     	  ZIM2(j) = 10.
   	  ZIM3(j) = 4.
! temperatures
     	  TE(j) = 20.*x
     	  TI(j) = 20.*x

!  power in alphas
     	  PFUS(j) = 1.*x ! 
   	      	  
    	  NI(j) = F1(j)+F2(j)+F3(J)+F4(J)+F5(J)+
     +            F6(J)+F7(J)+F8(J)+NIBM(J)
    	  NE(j) = F1(j)+F2(j)+F3(J)+2.*(F4(J)+F5(J))+
     +            F6(J)*ZIM1(J)+F7(J)*ZIM2(j)+F8(J)*ZIM3(J)+NIBM(J)
    	  
    	  enddo
	   yPalp=VINT(Pfus,ROC)			! total power in alphas
	   yGNBI=VINT(PBEAM,ROC)/1.6/EBEAM	!! electron source from NBI


!    	  write(*,*) 'F2in'
!    	  write(*,*) (F0(j),j=1,na1)
!    	  write(*,*) F3(1:na1)
!   	  write(*,*) TE(1:na1)
!    	  write(*,*) TI(1:na1)
    	  
	return
 2	write(*,*) 'problem in reading of prfl_in.dat'
	  close(1)
	return      

!================================================Polevoi ver 11-12-2014

	end
 
!========================
        subroutine  equilibrium_in(        
     3	BTOR,RTOR,ABC,AB,ROC,SHIFT,UPDWN,HRO,HROA,NA1,NB1,NAB,NA,
     4	VR,SHIF, SHIV, ELON, TRIA,
     5  AMETR,RHO,FP,MU,IPL)
      	implicit none
!	include  'for/parameter.inc'
!	include 'for/solsrs_IMAS.inc'
        double precision
     3	BTOR,RTOR,ABC,AB,ROC,SHIFT,UPDWN,HRO,HROA,
     4	VR(*),SHIF(*),SHIV(*),ELON(*),TRIA(*),
     5  AMETR(*),RHO(*),FP(*),MU(*),IPL
        integer NA1,NB1,NAB,NA,j,j1,kpr

!	  open(1,file='equil_in.dat',err=2)

	  	read(1,*,err=2,end=2)
     3	BTOR,RTOR,ABC,AB,ROC,SHIFT,UPDWN,HRO,NA1,NB1,
     4	VR(1:na1),SHIF(1:na1),SHIV(1:na1),ELON(1:na1),TRIA(1:na1),
     5  AMETR(1:na1),RHO(1:na1),FP(1:na1),MU(1:na1),IPL
!	  		  close(1)
	  		  NA=NA1-1
	  		  HROA=ROC-RHO(NA)
!	  write(*,*) BTOR,RTOR,ABC,AB,ROC,SHIFT,UPDWN,HRO,NA1,NB1 
!	  write(*,*) 'VR',(VR(j),j=1,na1) 
!	  write(*,*) (ametR(j),j=1,na1)
!	  write(*,*) 'FP',(FP(j),j=1,na1) 
!	  	write(*,*) 'read of equil_in.dat is finished'
        if(kpr.eq.1)print *,' RO=='
	  if(kpr.eq.1)write(*,*) (rho(j),j=1,na1)


		  return
 2	write(*,*) 'problem in reading of equil_in.dat'

!	  close(1)
	return
	end 
 
!========================
        subroutine   srs_control_in(
     1  yMu,Ycnim,ySeng, yL_OH,
     2  yGsol,yPsol,yPalp,yGNBI,
     3  ySd,ySt,ySh,ySHe,yShe3,ySNe,ySBe,yPd,yPt,yPh,
     4  yFd,yFt,yFh,yFniz1,yFniz3)
 
     	implicit none 
	include  'for/parameter.inc'
	include 'for/solsrs_IMAS.inc'
	double precision function vint
	double precision
     1  yMu,Ycnim,ySeng, yL_OH,
     2  yGsol,yPsol,yPalp,yGNBI,
     3  ySd,ySt,ySh,ySHe,yShe3,ySNe,ySBe,yPd,yPt,yPh,
     4  yFd,yFt,yFh,yFniz1,yFniz3,vint
     
  
	  yMu=0.7	!Normalised pressure in DIV range in ITER: 0-1 (detached)
	  Ycnim = 0.01	! nNe(a)/ne(a) in SOLPS (range in SOLPS 0.002-0.02)
!!!	  Yseng=57.	! engennering pumping [m3/s] range in ITER: 0-75
	  Yseng=37.	! engennering pumping [m3/s] range in ITER: 0-75



!	  
	  yL_OH =1.	! H-mode with pellet ELM pacing (33 mm3, 300m/s)

! isotope fraction in puffing SUM(ySi) =1.!
	  ySd = 0.5
	  ySt = 0.5
	  ySh = 0.
	  ySHe = 0. 
	  yShe3 =0.
	  ySNe =0.
	  ySBe	=0.
! isotope fraction in pellet SUM(yPi) = 1.!
	  yPd =0.5
	  yPt =0.5
	  yPh =0.
! isotope fraction in the hydrogen isotop edge density (prescribed or calulated in transport code): 
! SOLPS predicts total ndt: nd(a)=ndt*yFd,nt(a)=ndt*yFt ,nh(a)=ndt*yFh
! keep sum(yFdi) =1
	  yFd =0.499
	  yFt =0.499
	  yFh =0.002	! hydrogen is one fo the fusion products and hydrogen NBI
	  yFniz1 =0.02 	! nBe(a)/ne(a)
	  yFniz3 =0.	! no 3rd impurity
! fluxes to SOL	  (prescribed or calculated in transport code)
	  yGsol= 500.	! diffusive partuicle flux to SOL [10^19/s]
	  yPsol= 100.	! power to SOL [MW]
! itterations in neutx
	  NNCX=200
	  CNBI4=1.	! 0(1) cold ion(finite Ti)
	return
	end

!========================
        subroutine  all_out(
     2  yGdt,yGHFS,yGELM,ySpel,
     3  yGpuf,yGsep,ySsep,yqpk,Ycnim,yNe,ynDT,ynHe,yTe,yTi,
     4  ySd,ySt,ySh,ySHe,yShe3,ySNe,ySBe,yPd,yPt,yPh,
     5  yFd,yFt,yFh,yFniz2,yFniz3)
     	implicit none
     	include  'for/parameter.inc'
	include 'for/solsrs_IMAS.inc'
	include 'tmp/declar.fml'
	include 'tmp/declar.fnc'
	double precision
     1  car4x(nrd),car5x(nrd),car6x(nrd),car7x(nrd),
     2  car9x(nrd),car11x(nrd),car12x(nrd),car13x(nrd),
     3  car17x(nrd),car24x(nrd),car24(nrd)
	double precision svdtbp,svddnp1,svddnp2
	double precision 
     2  yGdt,yGHFS,yGELM,ySpel(*),
     3  yGpuf,yGsep,ySsep(*),yqpk,yndt,ySNe,ySBe,
     4	yTaus,yTs0,ynZ2dnAi,yEC1,yTe,yTi,yNe,
     5  ySd,ySt,ySh,ySHe,yShe3,yPd,yPt,yPh,Ycnim,ynHe,
     6  yFd,yFt,yFh,yFniz1,yFniz2,yFniz3,ysvd,Z,T,
     7  ySF4(NRD),ySF5(NRD),ySF4t,ySF5t,y,ysvdt
        integer j,jiter,jniter
!===============================
! OUTPUT:
!	F0B-F9B,TeB,TiB	! boundary conditions [10^19m-3,keV]
!	F1F-F9F		! fast ion densities [10^19m-3]
!	SF1-SF9		! explicit part of ion sources [10^19/m3/s]
!	SFF1-SFF9	! imlicit part of ion sources [1/s] Stot=SFi+Ni*SFFi
!	SF1F-SF9F	! fast ion sources [10^19/m3/s]
!	NHYDR-NIZ3	! total densities of ion species [10^19m-3]
! in present version exchange is organized by common block:
!      	include 'for/solsrs_IMAS.inc'
! and are written to 'out_data.dat'
!===============================
	jniter =2 ! two itteraftions for densities with fast particles
	  TE(na1)=yTe
	  TI(na1)=yTi
	  F0(na1)=yNe
	  F1(na1)=yndt*yFh
	  F2(na1)=yndt*yFd
	  F3(na1)=yndt*yFt
	  F4(na1)=ynHe
	  F5(na1)=0.
	  F6(na1)=yNe*yFniz1	
	  F7(na1)=yNe*Ycnim	! edge density of Neon NIZ1 in ASTRA
	  F8(na1)=yNe*yFniz3
	  F9(na1)=0.
	do j=1,na1
	  F1F(j)=0.
	  F2F(j)=0.
	  F3F(j)=0. 
	  F4F(j)=0.
	  F5F(j)=0.
	  F6F(j)=0.
	  F7F(j)=0.
	  F8F(j)=0.
	  F9F(j)=0.
	  SF1F(j)=0.
	  SF2F(j)=0.
	  SF3F(j)=0.
	  SF4F(j)=0.
	  SF5F(j)=0.
	  SF6F(j)=0.
	  SF7F(j)=0.
	  SF8F(j)=0.
	  SF9F(j)=0.
	  
	  do jiter=1,jniter
! for fast ion species:
! Pb =Eb*Sb
! nb =Sb*Ts*ln(1.+(Eb/Ec)**1.5
! Ec =Ab*EC1	: EC1=14.8*Te*Sum(niZi2/Ai/ne)
! Ts = Ts0 * Ab/Zb**2 :Ts0=2 Te**1.5/ne/Lambda
! 	Sum(niZi2/Ai/ne)
	ynZ2dnAi=(
     >	  	NHYDR(J)+NDEUT(J)/2.+NTRIT(J)/3.+
     +		4.*(NALF(J)/4.+NHE3(J)/3.))
	if(NIZ1(j)*AIM1.ne.0.)
     >		ynZ2dnAi=ynZ2dnAi+ZIM1(j)**2*NIZ1(J)/AIM1
 	if(NIZ2(j)*AIM2.ne.0.)
     >		ynZ2dnAi=ynZ2dnAi+ZIM2(j)**2*NIZ2(J)/AIM2
	if(NIZ3(j)*AIM3.ne.0.)
     >		ynZ2dnAi=ynZ2dnAi+ZIM3(j)**2*NIZ3(J)/AIM3
     		ynZ2dnAi=ynZ2dnAi/NE(J)
! 2 Te**1.5/ne/Lambda
	 yTs0	=2.0*Te(j)**1.5/ne(j)/(14.78 + log(Te(j)))
	 yEC1	=14.8*Te(j)*ynZ2dnAi
!====================  Particle transport ===================================
	  car7x(j)	=stbrn*F2(j)
!st1bd/3.52*CFUS4;		! probability for 1.008 MeV T to burn out during slowing down
	if(ABEAM.eq.2.d0) then
		include 'fml/s1dbd'
		include 'fml/s2dbd'
		include 'fml/sd1tp'
	  car24x(j)	=F2(j)*s1dbd*Pbeam(j)/1.6	! 2.452 MeV n (=0.87MeV He3) source 10^19 m-3/s from 1 MeV D NBI
	  car24(j)	=F2(j)*s2dbd*Pbeam(j)/1.6	! t source 10^19 m-3/s from 1 MeV D NBI
	  car12x(j)	=F3(j)*sd1tp*Pbeam(j)/1.6;	! 14.1 MeV n source 10^19 m-3/s D-beam, T-thermal
	else
	  car24x(j)	=0.
	  car24(j)	=0.
	  car12x(j)	=0.
	endif
		include 'fml/svd2'
		include 'fml/svd1'
		include 'fml/svdhe'
		include 'fml/p3dd'
	  car6x(j)	=F2(j)*F2(j)*svd2/2+car24(j)		! (3MeV p) = (1MeV t) source 10^19 m-3/s
	  car4x(j)	=F2(j)*F2(j)*svd1/2+car24x(j)	! (2.452 MeV n) = (0.87MeV He3) source 10^19 m-3/s
	  car17x(j)	=NDEUT(j)*NHE3(j)*svdhe ! (3.6 MeV He4) = (14.7 MeV p) source 10^19 m-3/s

	include 'fml/svdt'

        car11x(j)	=F2(j)*F3(j)*svdt	! (14.1 MeV n) = (3.52 MeV He4) source 10^19 m-3/s thermal
        car13x(j)	=car6x(j)*car7x(j) 	! (14.1 MeV n) = (3.52 MeV He4) 10^19 m-3/s from T-1.008 MeV, D-thermal
        car5x(j)	=car11x(j)+car13x(j)+car12x(j) 	! (14.1 MeV n) = (3.52 MeV He4) source 10^19 m-3/s total
        car9x(j)	=car6x(j)-car5x(j)	! total T source - DT sink 10^19 m-3/s


! for each of species particle source = SFi(j) + SFFi(j)*Ni(j)  
	include 'fml/snneu'

        SN(j)	=SNEBM(j)+ySpel(j)	
        SNN(j)	=SNNEU	! Particle source from wall  neutrals
!----------------------------------------------------------------------------
!--------------------- Hydrogen transport -------------------------------------
	SF1F(j)	=car6x(j)+car17x(j)
	F1F(j)	= yTs0*(
     >		car6x(j)*log(1.+(3000./yEC1)**1.5)+
     +  	car17x(j) *log(1.+(14700./yEC1)**1.5))	
! full slowing down and full confinement is assumed
	SF1(j)	=SF1F(j)	+ ySpel(j)*yPh		! Hydr source from D-D reaction
	if(ABEAM.eq.1.d0) then
	  SF1(j)	=SF1(j)+SNEBM(j)
	  F1F(j)	=yTs0*SNEBM(j)*log(1.+(EBEAM/yEC1)**1.5)
	endif
	SFF1(j)		=SNN(j)*ySh			! Hydrogen puffing;
!NDEUT*(NDEUT*SVD2+NHE3*SVDHE);! Hydr source from D-D reaction
	NHYDR(j) 	= F1(j)+F1F(j)
!----------------------------------------------------------------------------
!--------------------- deuterium transport -------------------------------------
	include 'fml/svdhe'
	SF2(j)	= ySpel(j)*yPd	
     .	-car24x(j)-car24(j)-car12x(j)-car7x(j)-car17x(j) ! D pellet -sink from DD,DT, DH3 reaction
	if(ABEAM.eq.2.d0) then
	  SF2(j)=SF2(j)+SNEBM(j)
 	  F2F(j)=2.*yTs0*SNEBM(j)*log(1.+(EBEAM/2./yEC1)**1.5)
	endif
	SFF2(j)	=SNN(j)*ySd			! Deut. puffing. 
	NDEUT(j)=F2(J) +  F2F(j)
!--------------------- Tritium transport -------------------------------------
	SF3F(j)	=car9x(j)
	F3F(j)	=3.*yTs0*car9x(j)*log(1.+(1008./3./yEC1)**1.5)
	SF3(j)	=SF3F(j)	+ ySpel(j)*yPt	! T source/sink from D-D reaction+secondary D+T(1MeV)
	SFF3(j) =SNN(j)*ySt		! T puffing
	NTRIT(j) = F3(j)+ F3F(j)
!----------------------------------------------------------------------------
!--------------------- Helium transport -------------------------------------
	SF4F(j) = car5x(j)+car17x(j)	
	F4F(j)	= yTs0*(
     >	car5x(j)*log(1.+(3520./4./yEC1)**1.5)+
     +  car17x(j) *log(1.+(3600./4./yEC1)**1.5))	
	SF4(j) 	= SF4F(j)			! He source from D-T reaction	
	SFF4(j)	= SVIE*(NNCL+NNWM)*NN(J)*ySHe	! He puffing
	ySF4(j)	= SF4(j) + SFF4(j)*F4(j)
	NALF(j) = F4(j) + F4F(j)
!----------------------------------------------------------------------------
!--------------------- He3 transport (F5 - thermal He3)-------------------------------------
	SF5F(j)	=car4x(j)
	F5F(j)	=0.75*yTs0*car4x(j)*log(1.+(870./3./yEC1)**1.5)
	SF5(j)	=SF5F(j)-car17x(j)	! He3 source - sink from D-He3 reaction
	SFF5(j)	=SVIE*(NNCL+NNWM)*NN(J)*yShe3			! He3 puffing;
	ySF5(j)	=SF5(j) + SFF5(j)*F4(j)
	NHE3(j) =F5(j) + F5F(j)
!----------------------------------------------------------------------------
!--------------------- Ne transport (F6 - thermal Ne)-----------------------

        SFF6(j) = SVIE*(NNCL+NNWM)*NN(J)*ySNe
        
!--------------------- Ne transport (F7 - thermal Be)-----------------------
        SFF7(j) = SVIE*(NNCL+NNWM)*NN(J)*ySBe
!--------------------------------------------- thermal electron source
        include 'fml/zineo'
        include 'fml/zibe'
        SF0(j) = SN(j) + 
     +	2.*(SF5(j)+SF4(j)+ SFF5(j)*F5(j)+SFF4(j)*F4(j))+
     +  ZIBE*SFF7(j)*F7(j)+ ZINEO*SFF6(j)*F6(j)
        SFF0(j) = SNN(j)
     	  NI(j) = F1(j)+F2(j)+F3(J)+F4(J)+F5(J)+
     +            F6(J)+F7(J)+F8(J)+NIBM(J)+
     +            F1F(j)+F2F(j)+F3F(J)+F4F(J)+F5F(J)+
     +            F6F(J)+F7F(J)+F8F(J)
    	  NE(j) = F1(j)+F2(j)+F3(J)+2.*(F4(J)+F5(J))+
     +            F6(J)*ZIM1(J)+F7(J)*ZIM2(j)+F8(J)*ZIM3(J)+NIBM(J)+
     +            F1F(j)+F2F(j)+F3F(J)+2.*(F4F(J)+F5F(J))+
     +            ZIM1(J)*F6F(J)+ZIM2(J)*F7F(J)+ZIM3(J)*F8F(J)

     

	  enddo ! jiter=jniter
        enddo ! j=na1
! output boundary conditions        
	  ySF4t	=VINT(ySF4,ROC)
	  ySF5t	=VINT(ySF5,ROC)
        if((ySF4t+ySF5t).gt.0.) then
	  F4(na1)	=ynHe*ySF4t/(ySF4t+ySF5t)
	  F5(na1)	=ynHe*ySF5t/(ySF4t+ySF5t)
	  NALF(na1)	=F4(na1)+F4F(na1)
	  NHE3(na1)	=F5(na1)+F5F(na1)
        endif

	  F0B=F0(na1)
	  F1B=F1(na1)
	  F2F=F2(na1)
	  F3B=F3(na1)
	  F4B=F4(na1)
	  F5B=F5(na1)
	  F6B=F6(na1)
	  F7B=F7(na1)
	  F8B=F8(na1)
	  F9B=F9(na1)
  	  TEB 	=TE(na1)
	  TIB	=TI(na1)      

	return	

	open(1,file='out_data.dat')
	write(1,*) F0B,F1B,F2B,F3B,F4B,F5B,F6B,F7B,F8B,F9B,TIB,TEB
	write(1,*) 
     .  F0(1:na1),F1(1:na1),F2(1:na1),F3(1:na1),
     .	F4(1:na1),F5(1:na1),F6(1:na1),F7(1:na1),
     .  F8(1:na1),F9(1:na1)
	write(1,*) 
     .  F0F(1:na1),F1F(1:na1),F2F(1:na1),F3F(1:na1),
     .	F4F(1:na1),F5F(1:na1),F6F(1:na1),F7F(1:na1),
     .  F8F(1:na1),F9F(1:na1)
	write(1,*)     
     .  SF0(1:na1),SF1(1:na1),SF2(1:na1),SF3(1:na1),
     .	SF4(1:na1),SF5(1:na1),SF6(1:na1),SF7(1:na1),
     .  SF8(1:na1),SF9(1:na1)	
	write(1,*)     
     .  SFF0(1:na1),SFF1(1:na1),SFF2(1:na1),SFF3(1:na1),
     .	SFF4(1:na1),SFF5(1:na1),SFF6(1:na1),SFF7(1:na1),
     .  SFF8(1:na1),SFF9(1:na1)
	write(1,*)     
     .  NHYDR(1:na1),NDEUT(1:na1),NTRIT(1:na1),NHE3(1:na1),
     .	NIZ1(1:na1),NIZ2(1:na1),NIZ3(1:na1),NE(1:na1),Ni(1:na1)

	close(1)
	return	
	end


