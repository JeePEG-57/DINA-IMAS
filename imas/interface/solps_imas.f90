subroutine solps_imas(equilibrium,core_transport,bndcond_out)

use ids_schemas
use ids_routines

type (ids_transport_solver_numerics) :: bndcond_out
type (ids_core_transport) :: core_transport
type (ids_equilibrium) :: equilibrium

integer, parameter :: kpr = 1
integer :: nrho_eq, nrho, flag

real (ids_real) :: Pe,Pi,Dpflux,Tpflux,rho_tor_norm,time

real*8 :: YMU,YPsol,YPalp,Yalp,YSeng,YdNdt,YAIM,Ycnim,YPedPi &
     	&,YGdt,YGpuf,YGpel,YGhe,YGsol,YGsep &
     	&,Ypn,Yqpk,Yndt,YnHe,Yne,YTe,YTi &
     	&,yGELM,yGLFS


! Fixed parameters
YPedPi=1.d0
YMU=0.8d0
YPalp=0.d0
YSeng=57.d0
YAim=20.d0
Ycnim=0.02d0
yGELM = 0.d0
yGLFS = 0.d0


    if (associated(equilibrium%time_slice(1)%profiles_1d%surface)) then
      nrho_eq = size(equilibrium%time_slice(1)%profiles_1d%surface)
      flag = 0
    else
      write(*,*) 'Radial grid of Equilibrium not set ! Exiting...'
      flag = -1
      return
    end if

    nrho = size(core_transport%model(1)%profiles_1d(1)%grid_d%rho_tor_norm)
    rho_tor_norm = core_transport%model(1)%profiles_1d(1)%grid_d%rho_tor_norm(nrho)
    tt = core_transport%model(1)%profiles_1d(1)%time
    
    ! The PSOL is in MW and the flux on IDSs is in MW/m^2 so i need to
    ! multiply by the surface area of the flux surface !!!
    Pe = core_transport%model(1)%profiles_1d(1)%electrons%energy%flux(nrho)* &
	    equilibrium%time_slice(1)%profiles_1d%surface(nrho_eq)
   
    Pi = core_transport%model(1)%profiles_1d(1)%total_ion_energy%flux(nrho)* &
	    equilibrium%time_slice(1)%profiles_1d%surface(nrho_eq)
      
    Dpflux = core_transport%model(1)%profiles_1d(1)%ion(1)%particles%flux(nrho)* &
	    equilibrium%time_slice(1)%profiles_1d%surface(nrho_eq)

    Tpflux = core_transport%model(1)%profiles_1d(1)%ion(2)%particles%flux(nrho)* &
	    equilibrium%time_slice(1)%profiles_1d%surface(nrho_eq)
    


!    YPedPi = Pe/Pi
    YPsol = (Pe + Pi)*1.0e-6    
    YGsol = (Dpflux + Tpflux)*1.0e-19

     			
     if(kpr.eq.1)print *,'SOLPS-IMAS: YGsol YPsol=',YGsol,YPsol
     			


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


	call solpsz2( &
     & YMU,YPsol,YPalp,YSeng,YdNdt,YAim,Ycnim,YPedPi &
     &,YGdt,YGpuf,YGpel,YGhe,YGsol,YGsep &
     &,Ypn,Yqpk,Yndt,YnHe,Yne,YTe,YTi &
     &,yGELM,yGLFS)


     	if(kpr.eq.1)print *,' YTe,YTi=',YTe,YTi
     	if(kpr.eq.1)print *,' YGsep,Yne=',YGsep,Yne



!Write boundary conditions to ids
allocate(bndcond_out%profiles_1d(1))
allocate(bndcond_out%time(1))

    bndcond_out%ids_properties%homogeneous_time = 1
    bndcond_out%profiles_1d(1)%time = tt
    bndcond_out%time(1) = tt ![s]


bndcond_out%profiles_1d(1)%electrons%energy%boundary_condition%identifier%index = 1
bndcond_out%profiles_1d(1)%electrons%energy%boundary_condition%rho_tor_norm = rho_tor_norm
    allocate(bndcond_out%profiles_1d(1)%electrons%energy%boundary_condition%value(1))
    bndcond_out%profiles_1d(1)%electrons%energy%boundary_condition%value(1) = YTe*1.d3


bndcond_out%profiles_1d(1)%energy_ion_total%boundary_condition%identifier%index = 1
bndcond_out%profiles_1d(1)%energy_ion_total%boundary_condition%rho_tor_norm = rho_tor_norm
    allocate(bndcond_out%profiles_1d(1)%energy_ion_total%boundary_condition%value(1))
    bndcond_out%profiles_1d(1)%energy_ion_total%boundary_condition%value(1) = YTi*1.d3


return
end