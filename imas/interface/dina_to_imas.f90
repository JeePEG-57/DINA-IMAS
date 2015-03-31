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

integer,save :: i1=11, i2=8

integer,save :: n_input1, n_input2, ng
integer,save :: n_output1, n_output2

integer,save ::  n_gaps=6
          
integer :: pulse=109, run=1, prescribedpulse=150, prescribedrun=8

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
    integer,parameter :: nr = 65, nz = 129, ngrid=nr*nz
    
    real(DP) :: tpl=1000.0,uli=1000.0,v=1000.0,s_plasma=1000.0,psi_ax=1000.0,rmag=1000.0,zmag=1000.0 &
    ,q_ax=1000.0,q_95=1000.0,rs0=1000.0,bt0=1000.0,wen2=1000.0,tt = 1.0

    real(DP) :: x(nr),y(nz),psi(nr,nz)

    real(DP) :: ai(npo),te0(npo),tq0(npo),pne(npo),tok1(npo),q(npo)
    
    real(DP),parameter :: pi = 3.14159265358979323846


  integer,save :: TimeSteps=1, CurTimeStep=1
  
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


write(*,*) 'True File'
write(*,*) 'Entering DINA_IMAS, first_call = ', first_call

flush(6)

        nwnh=ngrid
        kf=nact
        mu=npass
        nloop=nflux
        nprobe=nbpol
        
        write(*,*) 'nr nz nwnh = ', nr,nz,nwnh

        
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


  write(*,*) 'npf ncam kloop kprobe ',npf,ncam,kloop,kprobe


        nact=npf
        npass=ncam
        nflux=kloop
        nbpol=kprobe



gridrange(1)=x(1)
gridrange(2)=x(nr)
gridrange(3)=y(1)
gridrange(4)=y(nz)

  write(*,*) 'gridrange ',gridrange
!  write(*,*) 'x ',x
!  write(*,*) 'y ',y

print *,' pfres',pfres(1:npf)

write(*,*) 'DINAIMAS - TestElements: '
write(*,*) fluxarr(i1,i2) 
write(*,*) vesarr(i1,i2)

write(*,*) vesgreen(i1,i2)
write(*,*) vesprobe(i1,i2)

write(*,*) pfgreen(i1,i2)
write(*,*) pfprobe(i1,i2)

write(*,*) pfind(i1,i2)
write(*,*) pmj(i1,i2) 
write(*,*) pfc(i1,i2)




allocate(em_coupling0%mutual_grid_active(ngrid,nact))
allocate(em_coupling0%mutual_grid_passive(ngrid,npass))

allocate(em_coupling0%mutual_loops_passive(nflux,npass))
allocate(em_coupling0%field_probes_passive(nbpol,npass))

allocate(em_coupling0%mutual_loops_active(nflux,nact))
allocate(em_coupling0%field_probes_active(nbpol,nact))

allocate(em_coupling0%mutual_active_active(nact,nact))
allocate(em_coupling0%mutual_passive_passive(npass,npass))
allocate(em_coupling0%mutual_passive_active(npass,nact))

allocate(em_coupling0%mutual_loops_grid(nflux,ngrid))
allocate(em_coupling0%field_probes_grid(nbpol,ngrid))


allocate(em_coupling0%time(1))


print *,' end allocation em_coupling'

em_coupling0%ids_properties%homogeneous_time = 1




em_coupling0%mutual_grid_active = fluxarr(1:ngrid,1:nact)
em_coupling0%mutual_grid_passive = vesarr(1:ngrid,1:npass)

em_coupling0%mutual_loops_passive = vesgreen(1:nflux,1:npass)
em_coupling0%field_probes_passive = vesprobe(1:nbpol,1:npass)

em_coupling0%mutual_loops_active = pfgreen(1:nflux,1:nact)
em_coupling0%field_probes_active = pfprobe(1:nbpol,1:nact)

em_coupling0%mutual_active_active = pfind(1:nact,1:nact) 
em_coupling0%mutual_passive_passive = pmj(1:npass,1:npass)
em_coupling0%mutual_passive_active = pfc(1:npass,1:nact)

do j=1,nflux
em_coupling0%mutual_loops_grid(j,1:ngrid)=pslgreen(1:ngrid,j)
end do
do j=1,nbpol
em_coupling0%field_probes_grid(j,1:ngrid)=bprgreen(1:ngrid,j)
end do

em_coupling0%time(1) = 0.35



  write(*,*) 'Shapes - dinaimas'
  write(*,100) shape(em_coupling0%mutual_grid_active),shape(em_coupling0%mutual_grid_passive)

write(*,*) 'Shapes - dinaimas'
write(*,100) shape(em_coupling0%mutual_loops_active),shape(em_coupling0%mutual_passive_active)




write(*,*) 'DINAIMAS - TestElements: '
write(*,*) em_coupling0%mutual_grid_active(i1,i2)
write(*,*) em_coupling0%mutual_grid_passive(i1,i2)

write(*,*) em_coupling0%mutual_loops_passive(i1,i2)
write(*,*) em_coupling0%field_probes_passive(i1,i2) 

write(*,*) em_coupling0%mutual_loops_active(i1,i2)
write(*,*) em_coupling0%field_probes_active(i1,i2)

write(*,*) em_coupling0%mutual_active_active(i1,i2)
write(*,*) em_coupling0%mutual_passive_passive(i1,i2)
write(*,*) em_coupling0%mutual_passive_active(i1,i2)


write(*,*) "pfs resistances"
write(*,*) pfres(1:npf)
write(*,*) rcam(1:16)

allocate(pf_active%coil(nact))
allocate(pf_passive%loop(npass))

allocate(pf_active%time(1))
allocate(pf_passive%time(1))

pf_active%ids_properties%homogeneous_time = 1
pf_passive%ids_properties%homogeneous_time = 1

pf_active%coil(1:nact)%resistance = pfres(1:nact)
pf_passive%loop(1:npass)%resistance = rcam(1:npass)


pf_active%time(1) = 0.35
pf_passive%time(1) = 0.35

write(*,*) "pfs resistances"

    
write(*,*) pf_active%coil(1:npf)%resistance
write(*,*) pf_passive%loop(1:16)%resistance


 write(*,*) "Before limiter"

! xu = dina0%static_group_2%limiter_rz(1:57,1)
! yu = dina0%static_group_2%limiter_rz(1:57,2)



! write(*,*) 'DINAIMAS - Limiter Elements: '
! write(*,*) xu(14)
! write(*,*) yu(14)
! 
! 
! 	allocate(equilibrium%???)

allocate(equilibrium%time(1))
! 
! 
equilibrium%ids_properties%homogeneous_time = 1
! 
! 
! 	equilibrium%???(1:nr) = x(1:nr)
! 	equilibrium%???(1:nz) = y(1:nz)
! 
equilibrium%time(1) = 0.35

    allocate(equilibrium%coordinate_system%grid%dim1(nr,TimeSteps))
    allocate(equilibrium%coordinate_system%grid%dim2(nz,TimeSteps))

    equilibrium%coordinate_system%grid%dim1(1:nr,1)=x(1:nr) ![m]
    equilibrium%coordinate_system%grid%dim2(1:nz,1)=y(1:nz) ![m]

    allocate(equilibrium%coordinate_system%r(ke,1,TimeSteps))
    allocate(equilibrium%coordinate_system%z(ke,1,TimeSteps))

    write(*,*) "ke==",ke


    equilibrium%coordinate_system%r(1:ke,1,1)=xu(1:ke)
    equilibrium%coordinate_system%z(1:ke,1,1)=yu(1:ke)

! 
! 
! 
! write(*,*) 'DINAIMAS - CoreProfiles Elements: '
! write(*,*) core_profiles%magnetic_shear(1,14)
! write(*,*) core_profiles%magnetic_shear(2,14)



 write(*,*) "After limiter"

! write(*,*) "End of static data extraction"
! 
!   write(*,*) "pfres(1:3)=",pfres(1:3)
!   write(*,*) "rcam(1:3)=",rcam(1:3)
!   write(*,*) "limiterxu(1:3)=", xu(1:3)
!   write(*,*) "limiteryu(1:3)=", yu(1:3)
!   write(*,*) "gridrange=",gridrange

100 format (2I5, 4x,2I5, 4x, 2I5, 4x,2I5)



!stop

end if ! end of first_call



    

return
end subroutine


