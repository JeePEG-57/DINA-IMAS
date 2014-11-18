subroutine dina_imas(em_coupling0,equilibrium0, pf_active0, &
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


nact=size(em_coupling0%mutual_grid_active,2)
print *,'size em_coupling0%mutual_grid_active',nact
npass=size(em_coupling0%mutual_grid_passive,2)
print *,'size em_coupling0%mutual_grid_passive',npass

nflux=size(em_coupling0%mutual_loops_grid,1)
print *,'em_coupling0%mutual_loops_grid 1',nflux
nbpol=size(em_coupling0%field_probes_grid,1)
print *,'em_coupling0%field_probes_grid 1',nbpol

ke=size(equilibrium0%coordinate_system%r,1)
print *,'equilibrium0%coordinate_system%r 1',ke


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

print *,' before imas_open'

call imas_open('ids',prescribedpulse,prescribedrun,idx0) 
print *,' before ids_get idx0',idx0

!call ids_get(idx0,"dina/1",dina0)
call ids_get(idx0,"pf_active",pf_active)

call imas_close(idx0)

print *,' close imas'


  write(*,*) 'Shapes '
  write(*,100) shape(em_coupling0%mutual_grid_active),shape(em_coupling0%mutual_grid_passive)

write(*,*) 'Shapes '
write(*,100) shape(em_coupling0%mutual_loops_grid),shape(em_coupling0%field_probes_grid)

fluxarr = em_coupling0%mutual_grid_active
vesarr = em_coupling0%mutual_grid_passive

pslgreen = transpose(em_coupling0%mutual_loops_grid)
bprgreen = transpose(em_coupling0%field_probes_grid)

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

print *,pf_active0%coil(1:nact)%resistance

i=size(pf_passive0%loop%resistance)
print *,'pf_passive0%loop%resistance',i
print *,pf_passive0%loop(1:nact)%resistance

write(*,100) shape(pf_active0%coil%resistance),shape(pf_passive0%loop%resistance)


pfres(1:nact) = pf_active0%coil(1:nact)%resistance
rcam(1:npass) = pf_passive0%loop(1:npass)%resistance


xu(1:ke)=equilibrium0%coordinate_system%r(1:ke,1,1)
yu(1:ke)=equilibrium0%coordinate_system%z(1:ke,1,1)

x(1:nr)=equilibrium0%coordinate_system%grid%dim1(1:nr,1) ![m]
y(1:nz)=equilibrium0%coordinate_system%grid%dim2(1:nz,1) ![m]

gridrange(1)=y(1)
gridrange(2)=y(nz)
gridrange(3)=x(1)
gridrange(4)=x(nr)


write(*,*) "End of static data extraction"

  write(*,*) "pfres(1:3)=",pfres(1:3)
  write(*,*) "rcam(1:3)=",rcam(1:3)
  write(*,*) "limiterxu(1:3)=", xu(1:3)
  write(*,*) "limiteryu(1:3)=", yu(1:3)
  write(*,*) "gridrange=",gridrange

100 format (2I5, 4x,2I5, 4x, 2I5, 4x,2I5)

        npf=nact
        ncam=npass
        kloop=nflux
        kprobe=nbpol

     call  dina_v96_in(ncam,npf,kloop,kprobe,&
& 	gridrange,nact,npass,&
&	fluxarr,vesarr, pslgreen,bprgreen,&
&	pfind,pmj,pfc, pfres,rcam,&
&	xu,yu,ke,key,&
&   pfgreen,vesgreen,pfprobe,&
&   vesprobe,ngrid)


first_call = first_call+1 ! cancel the initialisation for the next call


!stop

end if ! end of first_call



loop_count = loop_count + 1 ! number of times the iterative routine was entered

write(*,*) 'dina_imas loop, first_call = ', first_call, loop_count

      n_input1=2
      n_input2=15

do i=1,n_input1
input_1(i)=arr_in1(i)
!print *,' i input_1=',i,input_1(i)
end do
do i=1,n_input2
input_2(i)=arr_in1(n_input1+i)
!print *,' i input_2 arr2=',i,input_2(i),arr_in1(n_input1+i)
end do


	call dina_0(time_8,tt_8,tay_8,key,vec, &
     &	input_1,input_2,input_3, &
     &	output_1,output_2,output_3,output_4,ng)

!    write(*,*) 'dina_imas loop, first_call = ', first_call, loop_count



	call dina_outp(n,  &
     & tpl,uli,v,s_plasma,psi_ax,rmag,zmag,  &
     & q_ax,q_95,rs0,bt0,wen2,tt,  &
     & ai,te0,tq0,pne,tok1,q,  &
     & x,y,psi)

    dina_time=tt
    write(*,*) 'dina_outp call n tpl tt= ', n,tpl,tt


!write(*,*) "output_1",output_1


      n_output1=15
      do i=1,n_output1
	  arr_out1(i)=output_1(i)
      end do

      npf=15
      n_gaps=6

      n_output2=npf+n_gaps+npf
      
      do i=1,n_output2
	  arr_out1(n_output1+i)=output_2(i)
      end do


!write(*,*) "-dina inp=",arr_in1(1:n_input1+n_input2)
!write(*,*) "dina out=",arr_out1(1:n_output1+n_output2)
    
    
    pf_active%ids_properties%homogeneous_time = 1
    allocate(pf_active%time(1))

    print *,' nact=',nact
    allocate(pf_active%coil(nact))
    
    do i=1,nact

!    print *,' i act= o_1 i_1',i,output_1(i),input_1(i)
    
      allocate(pf_active%coil(i)%current%data(1))
!      allocate(pf_active%coil(i)%current%time(1))
      pf_active%coil(i)%current%data(1) = 0.5
!      pf_active%coil(i)%current%time(1) = dina_time
      allocate(pf_active%coil(i)%voltage%data(1))
!      allocate(pf_active%coil(i)%voltage%time(1))
      pf_active%coil(i)%voltage%data(1) = 100.
!      pf_active%coil(i)%voltage%time(1) = dina_time

 !   print *,' pf_ac',i,pf_active%coil(i)%voltage%data(1),pf_active%coil(i)%current%data(1)


    end do


    pf_active%time(1) = dina_time
    pf_passive%ids_properties%homogeneous_time = 1

    print *,' npass=',npass
      allocate(pf_passive%loop(npass))
      allocate(pf_passive%time(1))
    do i=1,npass
!    print *,' i pass=',i
      allocate(pf_passive%loop(i)%current(1))
      pf_passive%loop(i)%current(1) = 1.
    end do
      pf_passive%time(1) = dina_time

   
! Work with IDS

    TimeSteps = 1 ! One time step filled for put_slice function
    CurTimeStep = 1

! Allocations equilibrium

    allocate(equilibrium%global_quantities%ip(TimeSteps))
  
    allocate(equilibrium%global_quantities%li_3(TimeSteps))
  
    allocate(equilibrium%global_quantities%volume(TimeSteps))
  
    allocate(equilibrium%global_quantities%area(TimeSteps))
  
    allocate(equilibrium%global_quantities%psi_axis(TimeSteps))
  
    allocate(equilibrium%global_quantities%magnetic_axis%r(TimeSteps))
    allocate(equilibrium%global_quantities%magnetic_axis%z(TimeSteps))
  
    allocate(equilibrium%global_quantities%q_axis(TimeSteps))  
    allocate(equilibrium%global_quantities%q_95(TimeSteps))
  
!    allocate(equilibrium%global_quantities%vacuum_toroidal_field%r0(TimeSteps)) - time independed
    allocate(equilibrium%global_quantities%vacuum_toroidal_field%b0(TimeSteps))
  
    allocate(equilibrium%global_quantities%w_mhd(TimeSteps))
  
    
    n1 = nr
    n2 = nz

    allocate(equilibrium%coordinate_system%grid%dim1(n1,TimeSteps))
    allocate(equilibrium%coordinate_system%grid%dim2(n2,TimeSteps))
    allocate(equilibrium%coordinate_system%r(n1,n2,TimeSteps))
    allocate(equilibrium%coordinate_system%z(n1,n2,TimeSteps))
  
    allocate(equilibrium%profiles_2d(1))
    allocate(equilibrium%profiles_2d(1)%psi(n1,n2,TimeSteps))
    
    
    allocate(equilibrium%time(TimeSteps))
  
! Filling equilibrium 

    equilibrium%ids_properties%homogeneous_time = 1
    
    
    equilibrium%global_quantities%ip(CurTimeStep) = tpl ![A]
	equilibrium%global_quantities%li_3(CurTimeStep) = uli
	equilibrium%global_quantities%volume(CurTimeStep) = v ![m3]
	equilibrium%global_quantities%area(CurTimeStep) = s_plasma ![m2]
	equilibrium%global_quantities%psi_axis(CurTimeStep) = psi_ax ![Wb]
	equilibrium%global_quantities%magnetic_axis%r(CurTimeStep) = rmag ![m]
	equilibrium%global_quantities%magnetic_axis%z(CurTimeStep) = zmag ![m]
	equilibrium%global_quantities%q_axis(CurTimeStep) = q_ax
	equilibrium%global_quantities%q_95(CurTimeStep) = q_95
	equilibrium%global_quantities%vacuum_toroidal_field%r0 = rs0 ![m], time independed
	equilibrium%global_quantities%vacuum_toroidal_field%b0(CurTimeStep) = bt0 ![T]
	equilibrium%global_quantities%w_mhd(CurTimeStep) = wen2 ![J]

    
    equilibrium%coordinate_system%grid%dim1(1:n1,CurTimeStep)=x(1:n1) ![m]
    equilibrium%coordinate_system%grid%dim2(1:n2,CurTimeStep)=y(1:n2) ![m]
    do i=1,n1
    do j=1,n2
    equilibrium%profiles_2d(1)%psi(i,j,CurTimeStep)=psi(i,j)
    enddo
    enddo
    
    equilibrium%profiles_2d(1)%psi(1:n1,1:n2,CurTimeStep)=psi(1:n1,1:n2)

    equilibrium%time(CurTimeStep) = tt ![s]
    
! Allocations core_profiles    

    allocate(core_profiles%rho_tor_norm(n,TimeSteps))
    allocate(core_profiles%t_e(n,TimeSteps))
    allocate(core_profiles%t_i_average(n,TimeSteps))
    allocate(core_profiles%n_e(n,TimeSteps))
    allocate(core_profiles%j_tor(n,TimeSteps))
    allocate(core_profiles%q(n,TimeSteps))
    
    
    allocate(core_profiles%time(TimeSteps))
 
! Filling core_profiles  

    core_profiles%ids_properties%homogeneous_time = 1
    
    
    core_profiles%rho_tor_norm(1:n, CurTimeStep) = ai(1:n)
	core_profiles%t_e(1:n, CurTimeStep) = te0(1:n)
	core_profiles%t_i_average(1:n, CurTimeStep) = tq0(1:n)
	core_profiles%n_e(1:n, CurTimeStep) = pne(1:n)
	core_profiles%j_tor(1:n, CurTimeStep) = tok1(1:n) ![A/m2]
	core_profiles%q(1:n, CurTimeStep) = q(1:n)
    
    
    core_profiles%time(CurTimeStep) = tt ![s]
    
    
  !  write(*,*) "psi = ", (equilibrium%profiles_2d(1)%psi(i,1:n2,CurTimeStep),i=1,n1)

    

return
end subroutine


