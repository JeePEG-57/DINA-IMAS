subroutine dina_imas(dina0, em_coupling0,equilibrium0, pf_active0, &
    & pf_passive0, dina, equilibrium, magnetics, pf_active, pf_passive)

! IMAS wrapper around the DINA-CH code
! Jo Lister, Rustam Khayrutdinov September 2013
! Note for IMAS - if the variable is dynamic, then the data are XXX%data, otherwise just XXX
! Status of unpacking DINA-CH output
! static group 1 Extracted, OK
! static group 2 Extracted, OK a couple missing
! dynamic input 1 Waiting for data
! dynamic input 2 Zero, not used OK
! dynamic input 3 Copy of the PF voltages, OK
! dynamic input 4 Waiting for data
! dynamic input 5 Waiting for data
! dynamic input 6 Not used
! dynamic output 1 Copy into pf_active OK
! dynamic output 2 Copy into pf_passive OK
! dynamic output 3 Copy into magnetics OK
! dynamic output 4 Copy into magnetics OK
! dynamic output 5 Copy into storage OK
! dynamic output 6 Copy into data items, some are OK
! dynamic output 7 Copy into shape OK
! dynamic output 8 Not copied yet ? IDS design ?
! dynamic output 9 Not copied
! dynamic output 10 Copied  OK
! dynamic output 11 Copied OK
! dynamic output 12 Not copied
! dynamic output 13 Not copied
! dynamic output 14 Not copied
! dynamic output 15 Not copied
! dynamic output 16 Not copied

use ids_schemas
use ids_routines
implicit none

! trees are static or dynamic; if not defined, they are static
type (ids_dina) :: dina0, dina
type (ids_em_coupling)  :: em_coupling0
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_magnetics)   :: magnetics
type (ids_pf_active)    :: pf_active0, pf_active
type (ids_pf_passive)   :: pf_passive0, pf_passive
type (ids_core_profiles)   :: core_profiles

! define local fixed size variables
integer,save :: i, key(26), indpf(12), ext_transp(4), nact, npass, ngrid, nbpol, nflux, nrad, npolar, ncronos,nr,nz
integer,save :: first_call = 1, loop_count = 0, ntime = 0
integer,save :: subsampling(20), sub

integer,save :: ncam,npf,kloop,kprobe,ke,k

integer,save ::  nwnh,ncam_mat,npf_mat,&   
& n_surf,n_surf_psi,n_surf_cur,n_polar_cur,n_cronos_prof,&
& n_cronos_field,n_restart,n_grid


integer,save :: n_prof= 26, n_cronos=30, NINPUTS=6,&

&       NOUTPUTS=15,N_SHAPE_OUT=37, N_BOUND_OUT=1000,&
&       N_SURF_OUT=100*90, n_vec=31,n_key=27,&
&       n_port1=14, n_port2=54, n_port3=19,&
&       n_port4=12, n_bound_arr=182,&
&       K_AUX=6, N_MAT=100,KF_MAT=120,MU_MAT=401,&
&       NLOOP_MAT=50,NPROBE_MAT=80,MU_L_MAT=403 


! static and prescribed data expressed in DINA terms
real (DP),save :: vec(31), gridrange(4), dina_time=0
real(DP), dimension(:,:), ALLOCATABLE,save :: fluxarr,vesarr,pslgreen,bprgreen,pfind,pmj,pfc,pfgreen,vesgreen,pfprobe,vesprobe
real(DP), dimension(:), ALLOCATABLE,save :: pfres, pf0, rcam, tcam0,xu, yu, bp_exp
real(DP), dimension(:), ALLOCATABLE,save :: pf_exp, ps_exp 

! dynamic inputs and outputs groups
real (DP),save :: input_1(14) = (/ (0,i=1,14) /)
real (DP),save :: input_2(54) = (/ (0,i=1,54) /)
real (DP), dimension(:), ALLOCATABLE,save :: input_3
real (DP), dimension(:,:), ALLOCATABLE,save :: input_4, input_5,aux_prof
real (DP),save :: input_6(182) = (/ (0,i=1,182) /)
real (DP), dimension(:), ALLOCATABLE,save :: output_1, output_2, output_3, output_4
real (DP),save ::  output_5(12)
real (DP), dimension(:,:), ALLOCATABLE,save ::  output_6
real (DP),save :: output_7(42), output_8(1000)
real (DP), dimension(:,:), ALLOCATABLE,save ::  output_9
real (DP), dimension(:), ALLOCATABLE ,save:: output_10, output_11, output_15 
real (DP), dimension(:,:), ALLOCATABLE,save ::  output_12, output_13
real (DP), dimension(:,:), ALLOCATABLE,save ::  output_14, output_16

if (first_call == 1) then ! convert input trees to local variables before calling dina
write(*,*) 'Entering DINA_IMAS, first_call = ', first_call, loop_count, dina_time
flush(6)

! group 1 
key = dina0%static_group_1%key
key(4)=1

vec = dina0%static_group_1%vec
indpf = dina0%static_group_1%indpf
if(key(4)>0) then
 write(*,*) "key=",key
 write(*,*) "vec=",vec
 write(*,*) "indpf=",indpf
 flush(6)
end if

! define the dimensions from key
nact = key(8)
npass = key(9)
ngrid = key(5)*key(6)
nbpol = key(11)
nflux = key(10)
nrad = key(16)
nr = key(5)
nz = key(6)

ke=57  !!!  RK - number of limiter points


call  read3_to_mat(key,vec,key(4))   

key(8)=nact 
key(9)=npass 

key(11)=nbpol 
key(10)=nflux 
key(16)=nrad  
key(5)=nr 
key(6)=nz  



if(key(4) > 0) then
  write(*,*) 'Sizes: Active,passive,probes,loops',nact,npass,nbpol,nflux
  write(*,*) 'Grids: nR, nZ, nrad,npolar: ', nr,nz,nrad,npolar
  flush(6)
end if

! allocate all variables to pass to DINA
ALLOCATE(fluxarr(ngrid,nact))
ALLOCATE(vesarr(ngrid,npass))
ALLOCATE(pslgreen(ngrid,nflux))
ALLOCATE(bprgreen(nbpol,ngrid))
ALLOCATE(pfind(nact,nact))
ALLOCATE(pmj(npass,npass))
ALLOCATE(pfc(npass,nact))
ALLOCATE(pfres(nact))
ALLOCATE(pf0(nact))
ALLOCATE(rcam(npass))
ALLOCATE(tcam0(npass))
ALLOCATE(xu(ke))
ALLOCATE(yu(ke))
ALLOCATE(pfgreen(nflux,nact))
ALLOCATE(vesgreen(nflux,npass))
ALLOCATE(pfprobe(nbpol,nact))
ALLOCATE(vesprobe(nbpol,npass))
ALLOCATE(bp_exp(nbpol))
ALLOCATE(pf_exp(nact))
ALLOCATE(ps_exp(nflux))
ALLOCATE(input_3(nact))
ALLOCATE(input_4(nrad,6))
ALLOCATE(input_5(nrad,9))
ALLOCATE(aux_prof(nrad,9))


ALLOCATE(output_1(nact))
ALLOCATE(output_2(npass))
ALLOCATE(output_3(nflux))
ALLOCATE(output_4(nbpol))

      n_cronos=30  
      nwnh=ngrid 
      ncam_mat=npass
      npf_mat=nact
      n_grid=nrad



      !   ssSetOutputPortWidth(S,4,n_port4);		
      !   ssSetOutputPortWidth(S,5,nprof_mat);		/* kinetics */
      !   ssSetOutputPortWidth(S,6,N_SHAPE_OUT);	/* shape_out */
      !  ssSetOutputPortWidth(S,7,N_BOUND_OUT);	/* shape_bound */
      !   ssSetOutputPortWidth(S,8,n_surf);	/* SURFACES */
      !   ssSetOutputPortWidth(S,9,n_surf_psi);  /* psi */
      !   ssSetOutputPortWidth(S,10,n_surf_cur);  /* currents */
      !   ssSetOutputPortWidth(S,11,n_polar_cur);  /* polar currents */
      !   ssSetOutputPortWidth(S,12,n_cronos_prof);  /* total cronos profiles */
      !   ssSetOutputPortWidth(S,13,n_cronos_field);  /* total cronos fields */
      !   ssSetOutputPortWidth(S,14,n_restart);  /* total cronos fields */


!      nprof_mat = key_mat(16+1) 
ALLOCATE(output_6(nrad,42))

      n_surf = nrad*2*90
      npolar = nrad*2
ALLOCATE(output_9(90,npolar))

      n_surf_psi = nwnh
ALLOCATE(output_10(ngrid))
      n_surf_cur = nwnh
ALLOCATE(output_11(ngrid))
      n_polar_cur = nrad*90
ALLOCATE(output_12(90,nrad))
     
     n_cronos=3*n_cronos 
     
     ncronos = nrad
     n_cronos_prof = nrad*n_cronos      
ALLOCATE(output_13(nrad,n_cronos))
     
!     npolar = nrad*3
     npolar = nrad*8
     n_cronos_field=nrad*3*90
ALLOCATE(output_14(90,npolar))

  n_restart = nwnh+90*nrad+ncam_mat+npf_mat+2+4*n_grid+1

ALLOCATE(output_15(n_restart))


write(*,*) "Static allocation done"

if (key(4) > 0) then
  write(*,*) 'Shapes of locally allocated arrays'
  write(*,100) shape(fluxarr),shape(vesarr),shape(pslgreen),shape(bprgreen),shape(pfind),shape(pmj),shape(pfc)
  write(*,100) shape(pfres),shape(pf0),shape(rcam),shape(tcam0),shape(xu),shape(yu),shape(pfgreen),shape(vesgreen)
  write(*,100) shape(pfprobe),shape(vesprobe),shape(bp_exp),shape(pf_exp)
  write(*,100) shape(input_1),shape(input_2),shape(input_3),shape(input_4),shape(input_5)
  write(*,100) shape(output_1),shape(output_2),shape(output_3),shape(output_4),shape(output_5),shape(output_6)
  write(*,100) shape(output_7),shape(output_8),shape(output_9),shape(output_10),shape(output_11),shape(output_12)
  write(*,100) shape(output_13),shape(output_14),shape(output_15),shape(output_16)
100 format (2I5, 4x,2I5, 4x, 2I5, 4x,2I5)
end if

! Note we do not test for the existence of these nodes; if they do not exist, failure is guaranteed!!
gridrange = dina0%static_group_2%rectangular_grid_limits 
fluxarr = transpose(em_coupling0%mutual_grid_active)
vesarr = transpose(em_coupling0%mutual_grid_passive)
pslgreen = transpose(em_coupling0%mutual_loops_grid)
bprgreen = transpose(em_coupling0%field_probes_grid)
pfind = em_coupling0%mutual_active_active
pmj = em_coupling0%mutual_passive_passive
pfc = em_coupling0%mutual_passive_active
pfgreen = em_coupling0%mutual_loops_active
vesgreen = em_coupling0%mutual_loops_passive
pfprobe = em_coupling0%field_probes_active
vesprobe = em_coupling0%field_probes_passive
pfres(1:nact) = pf_active0%coil(1:nact)%resistance
pf0(1:nact) = dina0%static_group_2%active0(1:nact)
rcam(1:npass) = pf_passive0%loop(1:npass)%resistance
tcam0(1:npass) = dina0%static_group_2%passive0(1:npass)
xu = dina0%static_group_2%limiter_rz(1:57,1)
yu = dina0%static_group_2%limiter_rz(1:57,2)
ext_transp = dina0%static_group_2%ext_transp
write(*,*) "End of static data extraction"

if (key(4) > 0) then
  write(*,*) "pfres(1:3)=",pfres(1:3)
  write(*,*) "pf0(1:3)=",pf0(1:3)
  write(*,*) "rcam(1:3)=",rcam(1:3)
  write(*,*) "tcam0(1:3)=",tcam0(1:3)
  write(*,*) "limiterxu(1:3)=", xu(1:3)
  write(*,*) "limiteryu(1:3)=", yu(1:3)
  write(*,*) "gridrange=",gridrange
  write(*,*) "ext_transp=",ext_transp
end if

output_1 = pf0

! I think these are not used - JO
bp_exp(1:nbpol) = 1
ps_exp(1:nflux) = 1 
pf_exp(1:nact) = 1 

if (key(4) > 0) then
! Use this for progressively testing 2-D initialisation arrays
  do i = 1,3
    write(*,*) "pfind",pfind(i,1:3)
  enddo
  do i = 1,3
    write(*,*) "pfc",pfc(i,1:3)
  enddo
  do i = 1,3
    write(*,*) "pslgreen",pslgreen(i,1:3)
  enddo
  do i = 1,3
    write(*,*) "vesarr",vesarr(i,1:3)
  enddo
end if


ncam=npass
npf=nact
kloop=nflux
kprobe=nbpol

     call  dina_v96_in(ncam,npf,kloop,kprobe,&
& 	gridrange,nact,npass,&
&	fluxarr,vesarr, pslgreen,bprgreen,&
&	pfind,pmj,pfc, pfres,rcam,&
&	xu,yu,ke,key,&
&   pfgreen,vesgreen,pfprobe,&
&   vesprobe,ngrid)

!! DINA INIT FIRST CALL !!! CALL DINA with static and prescribed inputs
!dina(key,vec, pf0,tcam0,d_pf,d_tcam,
!pl_loop,pl_probe,pl_pf,pl_ves,shape_out,&k_out_dina,
!contpts,contvals,npts,tcam,
!bp_exp,ps_exp,pf_exp,indpf,ext_transp,
!c_prof_mat,aux_heat,aux_prof,surf_mat);

first_call = 0 ! cancel the initialisation for the next call
dina_time = dina0%time(1) ! remember the starting time
write(*,*) 'DINA_IMAS finishing setup t=', dina0%time, dina_time
end if ! end of first_call

!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
loop_count = loop_count + 1 ! number of times the iterative routine was entered
dina_time = dina_time + vec(10) ! run - elapsed time
dina%time = dina_time

write(*,*) 'Entering dina_imas loop, first_call = ', first_call, loop_count, dina_time
flush(6)

!Unpack the dynamical input groups, done for every loop 

!input_group_1 is taken temporarily from from dina0
input_1(1)  = dina0%input_group_1%plasma_density(1)
input_1(2)  = dina0%input_group_1%ohmic_compensation(1)
input_1(3)  = dina0%input_group_1%boundary_density_ratio(1)
input_1(12) = dina0%input_group_1%itb_rho(1)
input_1(13) = dina0%input_group_1%tau_e_anomaly(1)
input_1(14) = dina0%input_group_1%sawtooth_q0(1)
!write(*,*) 'input_1',input_1

! copy the coil voltages into the input_group_3
do i=1,nact
!  input_3(i) = pf_active%coil(i)%voltage%data(1)
  input_3(i) = 0.d0
end do
write(*,*) 'input_3',input_3

input_4(1:nrad,1) = dina%input_group_4%particle_diffusion(1:nrad,1)
input_4(1:nrad,2) = dina%input_group_4%chi_electrons(1:nrad,1)
input_4(1:nrad,3) = dina%input_group_4%chi_ions(1:nrad,1)
input_4(1:nrad,4) = dina%input_group_4%bootstrap_current(1:nrad,1)
input_4(1:nrad,5) = dina%input_group_4%psi_normalised(1:nrad,1)
input_4(1:nrad,6) = dina%input_group_4%inward_pinch_velocity(1:nrad,1)

input_5(1:nrad,1) = dina%input_group_5%p_e(1:nrad,1)
input_5(1:nrad,2) = dina%input_group_5%p_i(1:nrad,1)
input_5(1:nrad,3) = dina%input_group_5%j_cd(1:nrad,1)
input_5(1:nrad,4) = dina%input_group_5%n_ex(1:nrad,1)
input_5(1:nrad,5) = dina%input_group_5%t_e_ex(1:nrad,1)
input_5(1:nrad,6) = dina%input_group_5%t_i_ex(1:nrad,1)

!input_5(1:nrad,7) = dina%input_group_5%sigma_ex(1:nrad,1)
!input_5(1:nrad,8) = dina%input_group_5%p_ex(1:nrad,1)
!input_5(1:nrad,9) = dina%input_group_5%ro_ex(1:nrad,1)

if(loop_count.eq.1)then
call aux_prof_in(nrad,aux_prof)
!call aux_prof_in(nrad,input_5)
end if

do i=1,nrad
do k=1,6
input_5(i,k) =aux_prof(i,k)
end do
end do

do i=1,nrad
input_5(i,7) =0.d0
input_5(i,8) =0.d0
input_5(i,9) =(dfloat(i)-1.d0)/(dfloat(nrad)-1.d0)
end do


if (key(4) >= 1) then 
!  write(*,*) 'input_1',input_1
  write(6,'("input_1",6(1pe13.6))'),(input_1(i),i=1,12)

  write(*,*) 'input_2',input_2
  write(*,*) "nact=",nact
  write(*,*) 'input_3',input_3
  write(*,*) 'input_41',input_4(1:50:5,1)
  write(*,*) 'input_42',input_4(1:50:5,2)
  write(*,*) 'input_43',input_4(1:50:5,3)
  write(*,*) 'input_44',input_4(1:50:5,4)
  write(*,*) 'input_45',input_4(1:50:5,5)
  write(*,*) 'input_46',input_4(1:50:5,6)
  write(*,*) 'input_51',input_5(1:50:5,1)
  write(*,*) 'input_52',input_5(1:50:5,2)
  write(*,*) 'input_53',input_5(1:50:5,3)
  write(*,*) 'input_54',input_5(1:50:5,4)
  write(*,*) 'input_55',input_5(1:50:5,5)
  write(*,*) 'input_56',input_5(1:50:5,6)

  write(*,*) 'input_57',input_5(1:50:5,7)
  write(*,*) 'input_58',input_5(1:50:5,8)
  write(*,*) 'input_59',input_5(1:50:5,9)

end if


!! CALL looping DINA with inputs and outputs


  write(*,*) "dina_time=",dina_time

  write(6,'("input_1",6(1pe13.6))'),(input_1(i),i=1,12)

  write(6,'("key=",6(1pi4))'),(key(i),i=1,26)
  write(6,'("vec",6(1pe13.6))'),(vec(i),i=1,31)

      call dina_v96(dina_time,key,vec,pf0,tcam0, &
&        bp_exp,ps_exp,pf_exp,indpf,ext_transp,&
      
&      input_1,input_2, input_3, input_4,input_5, &
&      output_1, output_2, output_3, output_4, output_5, & 
&      output_6, output_7,output_8, output_9, output_10, &
&      output_11, output_12, output_13, output_14, &
&      output_15, output_16)


output_1 = output_1 + input_3 * vec(10)
write(*,*) "output_1",output_1

! now store the dynamical output groups in the IDS
! These cannot be vectorised, due to the vector notation at the end
! The output store depends on the sampling
write(*,*)"Store outputs"

! sub-sample pf_control - ipf, ipass
!write(*,*) "A1"
sub = 1 !These are all allocated outside
if (mod(loop_count-1,sub) == 0 ) then
    !allocate(pf_active%coil(nact))
    do i=1,nact
      !allocate(pf_active%coil(i)%current%data(1))
      !allocate(pf_active%coil(i)%current%time(1))
      pf_active%coil(i)%current%data(1) = output_1(i)
      pf_active%coil(i)%current%time(1) = dina_time
      !allocate(pf_active%coil(i)%voltage%data(1))
      !allocate(pf_active%coil(i)%voltage%time(1))
      pf_active%coil(i)%voltage%data(1) = input_1(i)
      pf_active%coil(i)%voltage%time(1) = dina_time
    end do
      !allocate(pf_passive%loop(npass))
      !allocate(pf_passive%time(1))
    do i=1,npass
      !allocate(pf_passive%loop(i)%current(1))
      pf_passive%loop(i)%current(1) = output_2(i)
    end do
      pf_passive%time(1) = dina_time
else if (mod(loop_count-1,sub) == 1) then
      !deallocate(pf_active%coil)
      !deallocate(pf_passive%loop)
end if


! sub-sample magnetics diagnostics
!write(*,*) "A2"
sub = 2 ! These are outputs and can be subsampled
if (mod(loop_count-1,sub) == 0 ) then ! the sample times
    allocate(magnetics%flux_loop(nflux))! the put_slice works if the data are allocated
    do i=1,nflux
      allocate(magnetics%flux_loop(i)%flux%data(1))
      allocate(magnetics%flux_loop(i)%flux%time(1))
      magnetics%flux_loop(i)%flux%data(1) = i*6!output_3(i) ! JBL dummy
      magnetics%flux_loop(i)%flux%time(1) = dina_time
    end do
    allocate(magnetics%bpol_probe(nbpol))
    do i=1,nbpol
      allocate(magnetics%bpol_probe(i)%field%data(1))
      allocate(magnetics%bpol_probe(i)%field%time(1))
      magnetics%bpol_probe(i)%field%data(1) = i*5!output_4(i)
      magnetics%bpol_probe(i)%field%time(1) = dina_time
    end do
else if (mod(loop_count-1,sub) == 1) then ! this is the first non-sampled point
    deallocate(magnetics%bpol_probe) ! no put will be performed
    deallocate(magnetics%flux_loop)
end if

! sub-sample shape outputs
!write(*,*) "A3"
sub = 1 ! These are outputs and can be subsampled
if (mod(loop_count-1,sub) == 0 ) then
    allocate(dina%output_group_7%shape%data(1:42,1))
    allocate(dina%output_group_7%shape%time(1))
    dina%output_group_7%shape%data(1:42,1) = output_7(1:42)
    dina%output_group_7%shape%time(1) = dina_time
else if (mod(loop_count-1,sub) == 1) then
    deallocate(dina%output_group_7%shape%data)
    deallocate(dina%output_group_7%shape%time)
end if

! sub-sample external transport module parameters
!write(*,*) "A4"
sub = 1 ! These are outputs and can be subsampled
if (mod(loop_count-1,sub) == 0 ) then
    allocate(dina%output_group_5%storage%data(1:12,1))
    allocate(dina%output_group_5%storage%time(1))
    do i=1,12
      dina%output_group_5%storage%data(i,1) = output_5(i) ! compact this
    end do
    dina%output_group_5%storage%time(1) = dina_time
else if (mod(loop_count-1,sub) == 1) then
    deallocate(dina%output_group_5%storage%time)
    deallocate(dina%output_group_5%storage%time)
end if


! sub-sample 1D profiles
!write(*,*) "A5"
sub = 1 ! These are outputs and can be subsampled
if (mod(loop_count-1,sub) == 0 ) then
!    allocate(dina%output_group_6%t_e%data(1,1))
!    allocate(dina%output_group_6%t_e%time(1))
!    dina%output_group_6%t_e%data(1,1) = output_6(1)
!    dina%output_group_6%t_e%time(1) = dina_time
!    allocate(dina%output_group_6%t_i%data(1,1))
!    allocate(dina%output_group_6%t_i%time(1))
!    dina%output_group_6%t_i%data(1,1) = output_6(2)
!    dina%output_group_6%t_i%time(1) = dina_time
!    allocate(dina%output_group_6%q%data(1,1))
!    allocate(dina%output_group_6%q%time(1))
!    dina%output_group_6%q%data(1,1) = output_6(3)
!    dina%output_group_6%q%time(1) = dina_time
else if (mod(loop_count-1,sub) == 1) then
!    deallocate(dina%output_group_6%t_e)
!    deallocate(dina%output_group_6%t_e%time)
!    deallocate(dina%output_group_6%t_i)
!    deallocate(dina%output_group_6%t_i%time)
!    deallocate(dina%output_group_6%q)
!    deallocate(dina%output_group_6%q%time)
end if

! sub-sample boundary
!write(*,*) "A6"
sub = 1 ! These are outputs and can be subsampled
if (mod(loop_count-1,sub) == 0 ) then
else if (mod(loop_count-1,sub) == 1) then
end if

! sub-sample RZ current and flux
!write(*,*) "A7"
sub = 1 ! These are outputs and can be subsampled
if (mod(loop_count-1,sub) == 0 ) then
    allocate(equilibrium%profiles_2d(1))
    allocate(equilibrium%profiles_2d(1)%psi(nr,nz,1))
    allocate(equilibrium%time(1))
    equilibrium%profiles_2d(1)%psi(1:nr,1:nz,1) = reshape(output_10(1:ngrid),(/nr,nz/))
    equilibrium%time(1) = dina_time
    allocate(equilibrium%profiles_2d(1)%j_tor(nr,nz,1))
    equilibrium%profiles_2d(1)%j_tor(1:nr,1:nz,1) = reshape(output_11(1:ngrid),(/nr,nz/))
else if (mod(loop_count-1,sub) == 1) then
    deallocate(equilibrium%profiles_2d)
end if

!write(*,*) "A8" ! JBL the rest will be done when the first test works...

! now we continue with data stored for each sample

!equilibrium%profiles_1d%trapped_fraction(1:nrad) = output_6(1:nrad,21) 

!  dina%output_group_6%gra1(1:nrad,ntime) = output_6(1:nrad,4) 
!  dina%output_group_6%psi_tran(1:nrad,ntime) = output_6(1:nrad,5) 
!  dina%output_group_6%zeff(i) = output_6(1:nrad,6) 
!  dina%output_group_6%che_neo(1:nrad,ntime) = output_6(1:nrad,7) 
!  dina%output_group_6%chi_neo(i) = output_6(1:nrad,8) 
!  dina%output_group_6%a_m(1:nrad,ntime) = output_6(1:nrad,9) 
!  dina%output_group_6%r_m(i) = output_6(1:nrad,10) 
!  dina%output_group_6%n_e(1:nrad,ntime) = output_6(1:nrad,11) 
!  equilibrium%profiles_1d%f(1:nrad,ntime) = output_6(1:nrad,13) 
!  core_profiles%e_field_parallel(1:nrad,ntime) = output_6(1:nrad,14) 
!  equilibrium%profiles_1d%j_tor(1:nrad,ntime) = output_6(1:nrad,15) 
!  core_profiles%j_bootstrap(1:nrad,ntime) = output_6(1:nrad,16) 
!  dina%output_group_6%j_ech%data(1:nrad,ntime) = output_6(1:nrad,17) 
!  dina%output_group_6%ro_nor%data(1:nrad,ntime) = output_6(1:nrad,18) 
!  equilibrium%profiles_1d%volume(1:nrad,ntime) = output_6(1:nrad,19) 
!  equilibrium%profiles_1d%area(1:nrad,ntime) = output_6(1:nrad,20) 
!  dina%output_group_6%ro_con%data(1:nrad,ntime) = output_6(1:nrad,21) 
!  dina%output_group_6%ppx_con%data(1:nrad,ntime) = output_6(1:nrad,22) 
!  dina%output_group_6%pffx_con%data(1:nrad,ntime) = output_6(1:nrad,23) 
!  dina%output_group_6%dmn_con%data(1:nrad,ntime) = output_6(1:nrad,24) 
!  dina%output_group_6%pdo_con%data(1:nrad,ntime) = output_6(1:nrad,25) 
!  dina%output_group_6%pto_con%data(1:nrad,ntime) = output_6(1:nrad,26) 
!  dina%output_group_6%gge_con%data(1:nrad,ntime) = output_6(1:nrad,27) 
!  dina%output_group_6%ggt_con%data(1:nrad,ntime) = output_6(1:nrad,28) 
!  dina%output_group_6%pprime_dina%data(1:nrad,ntime) = output_6(1:nrad,29) 
!  dina%output_group_6%ffprime_dina%data(1:nrad,ntime) = output_6(1:nrad,30) 
!  equilibrium%profiles_1d%dpressure_dpsi(1:nrad,ntime) = output_6(1:nrad,31) 
!  equilibrium%profiles_1d%f_df_dpsi(1:nrad,ntime) = output_6(1:nrad,32) 
!  dina%output_group_6%p_e%data(1:nrad,ntime) = output_6(1:nrad,33) 
!  dina%output_group_6%p_i%data(1:nrad,ntime) = output_6(1:nrad,34) 
!  dina%output_group_6%n_ex%data(1:nrad,ntime) = output_6(1:nrad,36) 
!  dina%output_group_6%t_e_ex%data(1:nrad,ntime) = output_6(1:nrad,37) 
!  dina%output_group_6%t_i_ex%data(1:nrad,ntime) = output_6(1:nrad,38) 
!  dina%output_group_6%p_ex%data(1:nrad,ntime) = output_6(1:nrad,39) 
!  dina%output_group_6%sigma_ex%data(1:nrad,ntime) = output_6(1:nrad,40) 
!  dina%output_group_6%j_ohm%data(1:nrad,ntime) = output_6(1:nrad,41) 
!  dina%output_group_6%p_ohm%data(1:nrad,ntime) = output_6(1:nrad,42) 

!equilibrium%global_quantities%ip(ntime) = output_7(1)
!equilibrium%global_quantities%magnetic_axis%r(ntime) = output_7(2)
!equilibrium%global_quantities%magnetic_axis%z(ntime) = output_7(3)
!equilibrium%boundary%elongation(ntime) = output_7(6)
!equilibrium%boundary%elongation_lower(ntime) = output_7(7)
!equilibrium%boundary%triangularity_lower(ntime) = output_7(10)
!equilibrium%global_quantities%beta_pol(ntime) = output_7(11)
!equilibrium%global_quantities%li_3(ntime) = output_7(12)
!equilibrium%global_quantities%q_axis(ntime) = output_7(13)
!equilibrium%global_quantities%q_95(ntime) = output_7(14)
!equilibrium%global_quantities%psi_axis(ntime) = output_7(31)
!equilibrium%global_quantities%psi_boundary(ntime) = output_7(32)

write(*,*) 'DINA_IMAS returning cleanly after subsequent calls'

return
end subroutine


