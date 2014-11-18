subroutine dina_to_imas(em_coupling0,equilibrium0, pf_active0, &
    & pf_passive0, equilibrium, magnetics,  pf_active, pf_passive , core_profiles, &
    & arr_in1,arr_out1)


use ids_schemas
use ids_routines
implicit none

! trees are static or dynamic; if not defined, they are static
type (ids_dina) :: dina0, dina
type (ids_em_coupling)  :: em_coupling0
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_magnetics)   :: magnetics
type (ids_pf_active)   :: pf_active0, pf_active
type (ids_pf_passive)   :: pf_passive0, pf_passive
type (ids_core_profiles)   :: core_profiles

real (DP) :: arr_in1(*), arr_out1(*)


! define local fixed size variables
integer,save :: i, k,  j
integer,save :: first_call = 1, loop_count = 0, ntime = 0

integer,save :: ncam,npf,kloop,kprobe, ke=57

integer,save :: nact=30, npass=300 , nflux=60, nbpol=70

integer,save :: nwnh, kf, mu, nloop, nprobe

integer,save :: n_input1, n_input2, ng
integer,save :: n_output1, n_output2

integer,save ::  n_gaps=6
          
integer :: pulse=109, run=1, prescribedpulse=150, prescribedrun=1

integer :: idx, idx0


integer,save :: key(27)=(/ (0,i=1,27) /)

! static and prescribed data expressed in DINA terms
real (DP),save :: dina_time=0
real (DP),save :: time_8,tt_8,tay_8

integer ::  npo

parameter ( npo=100)

real (DP),save :: vec(npo) = (/ (0,i=1,npo) /)

! dynamic inputs and outputs groups
real (DP),save :: input_1(npo) = (/ (0,i=1,npo) /)
real (DP),save :: input_2(npo) = (/ (0,i=1,npo) /)
real (DP),save :: input_3(npo) = (/ (0,i=1,npo) /)

real (DP),save :: output_1(npo) = (/ (0,i=1,npo) /)
real (DP),save :: output_2(npo) = (/ (0,i=1,npo) /)
real (DP),save :: output_3(npo) = (/ (0,i=1,npo) /)
real (DP),save :: output_4(npo) = (/ (0,i=1,npo) /)


! DINA parameters
    integer,parameter :: nr = 65, nz = 65, ngrid=nr*nz
    
    real(DP) :: tpl=1000.0,uli=1000.0,v=1000.0,s_plasma=1000.0,psi_ax=1000.0,rmag=1000.0,zmag=1000.0 &
    ,q_ax=1000.0,q_95=1000.0,rs0=1000.0,bt0=1000.0,wen2=1000.0,tt = 1.0

    real(DP) :: x(nr),y(nz),psi(nr,nz)

    real(DP) :: ai(npo),te0(npo),tq0(npo),pne(npo),tok1(npo),q(npo)
    
    real(DP),parameter :: pi = 3.14159265358979323846


  integer :: TimeSteps, CurTimeStep
  
  integer :: n1, n2, n 

real (DP),save ::  gridrange(4)
real(DP), dimension(:,:), ALLOCATABLE,save :: fluxarr,vesarr,pslgreen,bprgreen,pfind,pmj
real(DP), dimension(:,:), ALLOCATABLE,save :: pfc,pfgreen,vesgreen,pfprobe,vesprobe
real(DP), dimension(:), ALLOCATABLE,save :: pfres, rcam, xu, yu


if (first_call == 1) then ! convert input trees to local variables before calling dina


ALLOCATE(fluxarr(ngrid,nact))
ALLOCATE(vesarr(ngrid,npass))
ALLOCATE(pslgreen(ngrid,nflux))
ALLOCATE(bprgreen(ngrid,nbpol))

ALLOCATE(vesgreen(nflux,npass))
ALLOCATE(vesprobe(nbpol,npass))

ALLOCATE(pfgreen(nflux,nact))
ALLOCATE(pfprobe(nbpol,nact))

ALLOCATE(pfind(nact,nact))
ALLOCATE(pmj(npass,npass))
ALLOCATE(pfc(npass,nact))

ALLOCATE(pfres(nact))
ALLOCATE(rcam(npass))

ALLOCATE(xu(ke))
ALLOCATE(yu(ke))


  write(*,*) 'Shapes of locally allocated arrays'
  write(*,100) shape(fluxarr),shape(vesarr),shape(pslgreen),shape(bprgreen)
  write(*,100) shape(pfgreen),shape(vesgreen),shape(pfprobe),shape(vesprobe)
  write(*,100) shape(pfind),shape(pmj),shape(pfc)
  write(*,100) shape(pfres),shape(rcam),shape(xu),shape(yu)


write(*,*) 'Entering DINA_IMAS, first_call = ', first_call, loop_count, dina_time

flush(6)

        nwnh=ngrid
        kf=nact
        mu=npass
        nloop=nflux
        nprobe=nbpol
        
	    call flat_ext_read_c( &
     &  nwnh,nr,nz,npf,ncam, &
     &  fluxarr,vesarr, &
     &  kf,mu,pfind,pfc,pmj,pfres,rcam, &
     &  xu,yu,ke, &
     &  nloop,nprobe,kloop,kprobe, &
     &  pfgreen,vesgreen, &
     &  pfprobe,vesprobe, &
     &  pslgreen,bprgreen, &
     &  x,y)                       


gridrange(1)=x(1)
gridrange(2)=x(nr)
gridrange(3)=y(1)
gridrange(4)=y(nz)

stop


  write(*,*) 'Shapes '
  write(*,100) shape(em_coupling0%mutual_grid_active),shape(em_coupling0%mutual_grid_passive)

write(*,*) 'Shapes '
write(*,100) shape(em_coupling0%mutual_loops_grid),shape(em_coupling0%field_probes_grid)

fluxarr = em_coupling0%mutual_grid_active
vesarr = em_coupling0%mutual_grid_passive

!pslgreen = em_coupling0%mutual_loops_grid
!bprgreen = em_coupling0%field_probes_grid

i=size(em_coupling0%mutual_loops_grid,1)
print *,'em_coupling0%mutual_loops_grid',i

i=size(em_coupling0%field_probes_grid,1)
print *,'em_coupling0%field_probes_grid',i

vesgreen = em_coupling0%mutual_loops_passive
vesprobe = em_coupling0%field_probes_passive

pfgreen = em_coupling0%mutual_loops_active
pfprobe = em_coupling0%field_probes_active

pfind = em_coupling0%mutual_active_active
pmj = em_coupling0%mutual_passive_passive
pfc = em_coupling0%mutual_passive_active

i=size(pf_active0%coil%resistance)
print *,'pf_active0%coil%resistance',i

i=size(pf_passive0%loop%resistance)
print *,'pf_passive0%loop%resistance',i

write(*,100) shape(pf_active0%coil%resistance),shape(pf_passive0%loop%resistance)


pfres(1:nact) = pf_active0%coil(1:nact)%resistance
rcam(1:npass) = pf_passive0%loop(1:npass)%resistance

xu = dina0%static_group_2%limiter_rz(1:57,1)
yu = dina0%static_group_2%limiter_rz(1:57,2)

write(*,*) "End of static data extraction"

  write(*,*) "pfres(1:3)=",pfres(1:3)
  write(*,*) "rcam(1:3)=",rcam(1:3)
  write(*,*) "limiterxu(1:3)=", xu(1:3)
  write(*,*) "limiteryu(1:3)=", yu(1:3)
  write(*,*) "gridrange=",gridrange

100 format (2I5, 4x,2I5, 4x, 2I5, 4x,2I5)



stop

end if ! end of first_call



    

return
end subroutine


