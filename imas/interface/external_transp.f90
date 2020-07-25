subroutine external_transp(equilibrium0, core_profiles0, core_sources0, equilibrium, core_profiles, core_sources)

use ids_schemas
use ids_routines
implicit none


type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_core_profiles) :: core_profiles0, core_profiles
type (ids_core_sources) :: core_sources0, core_sources

integer :: i,m,n,npo

parameter (npo=500)

real(ids_real) :: ai(npo),te0(npo),tq0(npo),qe0(npo),qq0(npo)
real(ids_real) :: pne(npo),pd0(npo),pt0(npo),pres(npo)
real(ids_real) :: jbut(npo),sigk(npo),aj0(npo)


call ids_copy(equilibrium0,equilibrium)
call ids_copy(core_profiles0,core_profiles)
call ids_copy(core_sources0,core_sources)


n = size(core_sources0%source(1)%profiles_1d(1)%grid%rho_tor_norm)


! open (unit=61,file='dina_transp5.dat',action='read',form='formatted')
! 
! read (61,*)n
! 
! write(*,*) 'dina_transp5, n=,', n
! 
! do i=1,n
! read (61,*) ai(i)
! enddo
! do i=1,n
! read (61,*) qe0(i)
! enddo
! do i=1,n
! read (61,*) qq0(i)
! enddo
! 
! close (61)


!7000	format(1x,1pe14.7)

! open (unit=61,file='dina_transp1.dat',action='read',form='formatted')
! 
! read (61,*)n
! 
! write(*,*) 'dina_transp1, n=,', n
! 
! do i=1,n
! read (61,*) ai(i)
! enddo
! do i=1,n
! read (61,*) te0(i)
! enddo
! do i=1,n
! read (61,*) tq0(i)
! enddo
! 
! close (61)




do i=1,n
	te0(i) = core_profiles%profiles_1d(1)%electrons%temperature(i)
	tq0(i) = core_profiles%profiles_1d(1)%t_i_average(i)
	pne(i) = core_profiles%profiles_1d(1)%electrons%density(i)
	pd0(i) = core_profiles%profiles_1d(1)%ion(1)%density(i)
	pt0(i) = core_profiles%profiles_1d(1)%ion(2)%density(i)
	jbut(i) = core_profiles%profiles_1d(1)%j_bootstrap(i)
	sigk(i) = core_profiles%profiles_1d(1)%conductivity_parallel(i)
	aj0(i) = core_profiles%profiles_1d(1)%j_total(i)
	qe0(i) = core_sources%source(1)%profiles_1d(1)%electrons%energy(i)
	qq0(i) = core_sources%source(1)%profiles_1d(1)%total_ion_energy(i)
	pres(i) = 0.d0
enddo



! if (.not.allocated(core_profiles%profiles_1d(1)%grid%rho_tor_norm)) then
!     allocate(core_profiles%profiles_1d(1)%grid%rho_tor_norm(n))
! end if
! if (.not.allocated(core_profiles%profiles_1d(1)%t_e)) then
    allocate(core_profiles%profiles_1d(1)%electrons%temperature(n))
! end if
! if (.not.allocated(core_profiles%profiles_1d(1)%t_i_average)) then
     allocate(core_profiles%profiles_1d(1)%t_i_average(n))
! end if


!  core_profiles%profiles_1d(1)%grid%rho_tor_norm(1:n) = ai(1:n)
 core_profiles%profiles_1d(1)%electrons%temperature(1:n) = te0(1:n)
 core_profiles%profiles_1d(1)%t_i_average(1:n) = tq0(1:n)

!if (allocated(core_profiles%profiles_1d(1)%ion)) then
m = size(core_profiles%profiles_1d(1)%ion)
do i=1,m
	allocate(core_profiles%profiles_1d(1)%ion(m)%temperature(n))
	core_profiles%profiles_1d(1)%ion(m)%temperature(1:n) = tq0(1:n)
end do
!end if



!Electrons
allocate(core_profiles%profiles_1d(1)%electrons%density(n))
 core_profiles%profiles_1d(1)%electrons%density(1:n) = pne(1:n)

!if (.not. allocated(core_profiles%profiles_1d(1)%ion)) then
   allocate(core_profiles%profiles_1d(1)%ion(2))
!end if

! Deuterium
allocate(core_profiles%profiles_1d(1)%ion(1)%element(1))
 core_profiles%profiles_1d(1)%ion(1)%element(1)%a = 2
 core_profiles%profiles_1d(1)%ion(1)%z_ion = 1
 core_profiles%profiles_1d(1)%ion(1)%element(1)%z_n = 1
!core_profiles%profiles_1d(1)%ion(1)%label = 'D+'
! if (.not. allocated(core_profiles%profiles_1d(1)%ion(1)%n_i)) then
allocate(core_profiles%profiles_1d(1)%ion(1)%density(n))
! end if
 core_profiles%profiles_1d(1)%ion(1)%density(1:n) = pd0(1:n)

! Tritium
allocate(core_profiles%profiles_1d(1)%ion(2)%element(1))
 core_profiles%profiles_1d(1)%ion(2)%element(1)%a = 3
 core_profiles%profiles_1d(1)%ion(2)%z_ion = 1
 core_profiles%profiles_1d(1)%ion(2)%element(1)%z_n = 1
!core_profiles%profiles_1d(1)%ion(2)%label = 'T+'
allocate(core_profiles%profiles_1d(1)%ion(2)%density(n))
 core_profiles%profiles_1d(1)%ion(2)%density(1:n) = pt0(1:n)



allocate(core_profiles%profiles_1d(1)%j_bootstrap(n))
 core_profiles%profiles_1d(1)%j_bootstrap(1:n) = jbut(1:n)

allocate(core_profiles%profiles_1d(1)%conductivity_parallel(n))
 core_profiles%profiles_1d(1)%conductivity_parallel(1:n) = sigk(1:n)


allocate(core_profiles%profiles_1d(1)%j_total(n))
 core_profiles%profiles_1d(1)%j_total(1:n) = aj0(1:n)


allocate(core_sources%source(1)%profiles_1d(1)%electrons%energy(n))
 core_sources%source(1)%profiles_1d(1)%electrons%energy(1:n) = qe0(1:n)

allocate(core_sources%source(1)%profiles_1d(1)%total_ion_energy(n))
 core_sources%source(1)%profiles_1d(1)%total_ion_energy(1:n) = qq0(1:n)


allocate(equilibrium%time_slice(1)%profiles_1d%pressure(n))
 equilibrium%time_slice(1)%profiles_1d%pressure(1:n) = pres(1:n)

return
end subroutine




subroutine external_transp(equilibrium, core_profiles, core_sources)

use ids_schemas
use ids_routines
implicit none

include 'double.inc'
include 'parf0'
include 'parf_mike'

type (ids_equilibrium) :: equilibrium0
type (ids_core_profiles) :: core_profiles0
type (ids_core_sources) :: core_sources0

integer :: i,m,n,npo

parameter (npo=500)

real(ids_real) :: ai(npo),te0(npo),tq0(npo),qe0(npo),qq0(npo)
real(ids_real) :: pne(npo),pd0(npo),pt0(npo),pres(npo)
real(ids_real) :: jbut(npo),sigk(npo),aj0(npo)

      common /c_imas_pres1/nn_b,n_tb

      common /c_imas_ajb/tt_ajb(ntime),prof_ajb(npo,ntime),rr_ajb(ntime)
      common /c_imas_sigma/tt_sigma(ntime),prof_sigma(npo,ntime),rr_sigma(ntime)
      common /c_imas_nb/tt_nb(ntime),prof_nb(npo,ntime),rr_nb(ntime)
      common /c_imas_ecd/tt_ecd(ntime),prof_ecd(npo,ntime),rr_ecd(ntime)
      common /c_imas_te/tt_te(ntime),prof_te(npo,ntime),rr_te(ntime)
      common /c_imas_ti/tt_ti(ntime),prof_ti(npo,ntime),rr_ti(ntime)
      common /c_imas_ne/tt_ne(ntime),prof_ne(npo,ntime),rr_ne(ntime)
      common /c_imas_ndt/tt_ndt(ntime),prof_ndt(npo,ntime),rr_ndt(ntime)
      common /c_imas_zeff/tt_zeff(ntime),prof_zeff(npo,ntime),rr_zeff(ntime)
      common /c_imas_pres/tt_pres(ntime),prof_pres(npo,ntime),rr_pres(ntime)

n = size(core_sources%source(1)%profiles_1d(1)%grid%rho_tor_norm)


! open (unit=61,file='dina_transp5.dat',action='read',form='formatted')
! 
! read (61,*)n
! 
! write(*,*) 'dina_transp5, n=,', n
! 
! do i=1,n
! read (61,*) ai(i)
! enddo
! do i=1,n
! read (61,*) qe0(i)
! enddo
! do i=1,n
! read (61,*) qq0(i)
! enddo
! 
! close (61)


!7000	format(1x,1pe14.7)

! open (unit=61,file='dina_transp1.dat',action='read',form='formatted')
! 
! read (61,*)n
! 
! write(*,*) 'dina_transp1, n=,', n
! 
! do i=1,n
! read (61,*) ai(i)
! enddo
! do i=1,n
! read (61,*) te0(i)
! enddo
! do i=1,n
! read (61,*) tq0(i)
! enddo
! 
! close (61)




do it=1,nt

do ir=1,nr
	te0(ir,it) = core_profiles%profiles_1d(1)%electrons%temperature(i)
	tq0(ir,it) = core_profiles%profiles_1d(1)%t_i_average(i)
	pne(ir,it) = core_profiles%profiles_1d(1)%electrons%density(i)
	pd0(ir,it) = core_profiles%profiles_1d(1)%ion(1)%density(i)
	pt0(ir,it) = core_profiles%profiles_1d(1)%ion(2)%density(i)
	jbut(ir,it) = core_profiles%profiles_1d(1)%j_bootstrap(i)
	sigk(ir,it) = core_profiles%profiles_1d(1)%conductivity_parallel(i)
	aj0(ir,it) = core_profiles%profiles_1d(1)%j_total(i)
	qe0(ir,it) = core_sources%source(1)%profiles_1d(1)%electrons%energy(i)
	qq0(ir,it) = core_sources%source(1)%profiles_1d(1)%total_ion_energy(i)
	pres(ir,it) = 0.d0
enddo
enddo




return
end subroutine
