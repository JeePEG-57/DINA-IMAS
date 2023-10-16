!> dina_green is the subroutine to calculate electromagnetic coupling matrices
!> Inputs: 
!>   pf_active0, pf_passive0, magnetics0 - contain geometry data
!> Outputs: 
!>   em_coupling contains coupling matrices
!>   equilibrium contains r(nr),z(nz) arrays of used 2D grid



subroutine dina_green(&
  & pf_active0, pf_passive0, magnetics0,&
  & em_coupling, equilibrium)


use ids_schemas
use ids_routines
!implicit none


type (ids_pf_active), INTENT(IN)   :: pf_active0
type (ids_pf_passive), INTENT(IN)  :: pf_passive0
type (ids_magnetics), INTENT(IN)   :: magnetics0
type (ids_em_coupling), INTENT(OUT) :: em_coupling
type (ids_equilibrium), INTENT(OUT) :: equilibrium


integer:: i, j, k

integer:: kloop, kprobe, ke=57, ngrid2=-1
integer,parameter:: nr = 65, nz = 129, ngrid = nr*nz ! parf2
integer:: nact = -1, npass = -1 ! parf1 - kf, mu

real(ids_real) :: x(nr),y(nz)
real(ids_real), dimension(:,:), ALLOCATABLE :: fluxarr,vesarr,pslgreen,bprgreen,pfind,pmj
real(ids_real), dimension(:,:), ALLOCATABLE :: pfc,pfgreen,vesgreen,pfprobe,vesprobe
real(ids_real), dimension(:), ALLOCATABLE :: pfres, rcam, xu, yu
real(ids_real)::  gridrange(4)
real(ids_real), dimension(:), allocatable::  pf_turns

	character *20 apr
	



	include 'parf1'
 	include 'parf_mike'

                                                      

    common /c_tokamak_config1/&
     & npf_c,&
     & npf_res_c,&
     & ncam_c,&
     & kloop_c,&
     & kprobe_c,kpb_c,&
     & ke_c

    common /c_tokamak_config2/&
     & nr_c(mu),nz_c(mu),nt_c(mu),n_pf_num_c(mu),&
     & R_c_c(mu),Z_c_c(mu),dr_c(mu),dz_c(mu),alpha_c(mu),beta_c(mu),&
     & pfres_c(mu),&
     & ndl_ves_c(mu),ndh_ves_c(mu),nt_ves_c(mu),n_ves_num_c(mu),&
     & Rc_c(mu),Zc_c(mu),dl_c(mu),hl_c(mu),alpha_ves_c(mu),&
     & beta_ves_c(mu),&
     & rcam_c(mu),&
     & Rl_c(mu),Zl_c(mu),&
     & R_prob_c(mu),Z_prob_c(mu),anglep_c(mu),smp_c(mu),&
     & xu_c(mu),yu_c(mu),&
     & r00_c,rk_c,&
     & z00_c,zk_c




common &
&  /ge5/kpr

integer:: kpr

!kpr = 1

print *,'DINA GREEN: read tokamak data...'
flush(6)
 !call tokamakdata_read_1()
 call tokamakdata_read_ids(pf_active0, pf_passive0, magnetics0)

 print *,'DINA GREEN: Calculation...'
 flush(6)
 call congig_calc()

 print *,'DINA GREEN: Mapping matrices...'
 flush(6)
 call read_green_params(npass,nact,kloop,kprobe,ke,ngrid2)


print *,'DINA GREEN:'
print *,'nact, npass =', nact,npass
print *,'kloop, kprobe =', kloop,kprobe
print *,'ngrid ngrid2 =', ngrid,ngrid2
print *,'ke =', ke


ALLOCATE(fluxarr(ngrid,nact))
ALLOCATE(vesarr(ngrid,npass))
ALLOCATE(pslgreen(ngrid,kloop))
ALLOCATE(bprgreen(ngrid,kprobe))

ALLOCATE(vesgreen(kloop,npass))
ALLOCATE(vesprobe(kprobe,npass))

ALLOCATE(pfgreen(kloop,nact))
ALLOCATE(pfprobe(kprobe,nact))

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


flush(6)


	call read_greens(npass,nact,kloop,kprobe,ngrid,&
& 	x,y,&
&	fluxarr,vesarr, pslgreen,bprgreen,&
&	pfind,pmj,pfc, pfres,rcam,&
&	xu,yu,ke,&
&   pfgreen,vesgreen,pfprobe,&
&   vesprobe)
  
  
    
  
  write(*,*) "fluxarr(1:3)=",fluxarr(1,1:3)
  write(*,*) "vesarr(1:3)=",vesarr(1,1:3)
  write(*,*) "pslgreen(1:3)=",pslgreen(1,1:3)
  write(*,*) "bprgreen(1:3)=",bprgreen(1,1:3)
  write(*,*) "pfres(1:3)=",pfres(1:3)
  write(*,*) "rcam(1:3)=",rcam(1:3)

gridrange(1)=y(1)
gridrange(2)=y(nz)
gridrange(3)=x(1)
gridrange(4)=x(nr)

  write(*,*) "gridrange=", gridrange

flush(6)



i=size(pf_active0%coil)
print *,'pf_active0%coil%resistance',i
print *,pf_active0%coil(1:i)%resistance

i=size(pf_passive0%loop)
print *,'pf_passive0%loop%resistance',i
print *,pf_passive0%loop(1:i)%resistance

write(*,100) shape(pf_active0%coil),shape(pf_passive0%loop)

100 format (2I5, 4x,2I5, 4x, 2I5, 4x,2I5)
    
    
    
! Allocation em_coupling

allocate(em_coupling%mutual_passive_passive(npass,npass))
allocate(em_coupling%mutual_grid_passive(ngrid,npass))
allocate(em_coupling%mutual_loops_passive(kloop,npass))
allocate(em_coupling%field_probes_passive(kprobe,npass))

allocate(em_coupling%mutual_active_active(nact,nact))
allocate(em_coupling%mutual_grid_active(ngrid,nact))
allocate(em_coupling%mutual_loops_active(kloop,nact))
allocate(em_coupling%field_probes_active(kprobe,nact))

allocate(em_coupling%mutual_passive_active(npass,nact))

allocate(em_coupling%mutual_loops_grid(kloop,ngrid))
allocate(em_coupling%field_probes_grid(kprobe,ngrid))



em_coupling%ids_properties%homogeneous_time = 1
allocate(em_coupling%time(1))
em_coupling%time(1) = 0.d0

print *,' end allocation em_coupling'

flush(6)
  


em_coupling%mutual_passive_passive = pmj(1:npass,1:npass)
em_coupling%mutual_grid_passive = vesarr(1:ngrid,1:npass)
em_coupling%mutual_loops_passive = vesgreen(1:kloop,1:npass)
em_coupling%field_probes_passive = vesprobe(1:kprobe,1:npass)
do j=1,kloop
  em_coupling%mutual_loops_grid(j,1:ngrid)=pslgreen(1:ngrid,j)
end do
do j=1,kprobe
  em_coupling%field_probes_grid(j,1:ngrid)=bprgreen(1:ngrid,j)
end do



allocate(pf_turns(nact))
pf_turns(1:nact) = 0.d0
do i=1,nact
  pf_turns(i) = dabs(pf_active0%coil(i)%element(1)%turns_with_sign)
enddo


do i=1,nact
  do j=1,nact
    em_coupling%mutual_active_active(i,j) = pfind(i,j)*pf_turns(i)*pf_turns(j)
  enddo

  em_coupling%mutual_grid_active(:,i) = fluxarr(1:ngrid,i)*pf_turns(i)
  em_coupling%mutual_loops_active(:,i) = pfgreen(1:kloop,i)*pf_turns(i)
  em_coupling%field_probes_active(:,i) = pfprobe(1:kprobe,i)*pf_turns(i)
  em_coupling%mutual_passive_active(:,i) = pfc(1:npass,i)*pf_turns(i)
enddo




print *,' em_coupling filled'
flush(6)	

  
! Filling equilibrium
allocate(equilibrium%time_slice(1))
allocate(equilibrium%time(1))
equilibrium%ids_properties%homogeneous_time = 1
equilibrium%time_slice(1)%time = 0.d0
equilibrium%time(1) = 0.d0
  
! Grid dimensions
allocate(equilibrium%time_slice(1)%profiles_2d(1))
equilibrium%time_slice(1)%profiles_2d(1)%grid_type%index = 1 ! Rectangular a la eqdsk   
allocate(equilibrium%time_slice(1)%profiles_2d(1)%grid%dim1(nr))
allocate(equilibrium%time_slice(1)%profiles_2d(1)%grid%dim2(nz))        
  equilibrium%time_slice(1)%profiles_2d(1)%grid%dim1(1:nr)=x(1:nr)
  equilibrium%time_slice(1)%profiles_2d(1)%grid%dim2(1:nz)=y(1:nz)
  
  
return
end





