
use ids_schemas
use ids_routines
implicit none


!   module jetto
      interface prof_read
         subroutine prof_read(filename, tt, rr, x)
         implicit none
	real(8),dimension(:),allocatable :: tt, rr
	real(8),dimension(:,:),allocatable :: x
	integer :: nn, it
	character(len=100) :: filename
         end subroutine prof_read
      end interface

      interface prof_write
         subroutine prof_write(filename, tt, rr, x)
         implicit none
	real(8),dimension(:),allocatable :: tt, rr
	real(8),dimension(:,:),allocatable :: x
	integer :: nn, it
	character(len=100) :: filename
         end subroutine prof_write
      end interface
 !  end module jetto


type (ids_equilibrium) :: eq
type (ids_core_sources) :: cs
type (ids_core_profiles) :: cp
integer :: pulse, run, idx, idx0
integer it,ir,nt,nr
real(8),dimension(:), allocatable :: tt, rr
real(8),dimension(:,:), allocatable :: x01,x02,x03,x04,x05,x06,x07,x08,x09,x10,x11,x12,x13
!character(LEN=100) :: profdir = "."
character(LEN=100) :: filename01,filename02,filename03,filename04,filename05 &
&,filename06,filename07,filename08,filename09,filename10 &
&,filename11,filename12,filename13

character (len=255) :: user
call getenv("USER", user)

print *,' Enter pulse number'
read (*,*) pulse
!pulse=170

print *,' Enter run number'
read (*,*) run
!run=2


!         open(unit=2,file='jetto_ids.dat',form='formatted',action='read')
! 
!         read(2,*)
!         read(2,*) pulse
!         read(2,*)
!         read(2,*) run
! 
!         close(2)
! 
!         write(*,*) 'jetto_ids: pulse, run =',pulse,run



	filename01 = 'Ne_prof.txt'
	filename02 = 'Ndt_prof.txt'
	filename03 = 'Te_prof.txt'
	filename04 = 'Ti_prof.txt'
	filename05 = 'pres_prof.txt'
	filename06 = 'Zeff_prof.txt'
	filename07 = 'q_prof.txt'
	filename08 = 'Jbs_prof.txt'
	filename09 = 'Joh_prof.txt'
	filename10 = 'Jtot_prof.txt'
	filename11 = 'Jznb_prof.txt'
	filename12 = 'Jzec_prof.txt'
	filename13 = 'Sigm_prof.txt'

!	cp/profiles_1d(itime)/j_bootstrap filename=Ibs_prof.txt

!	cp/profiles_1d(itime)/conductivity_parallel Sigm_prof.txt

!	core_sources/source(i1)/profiles_1d(itime)/j_parallel Iznb_prof.txt
!(defined as <j_NBI.B>/B0; source index i1 corresponding to source entry with !core_sources/source(i1)/identifier/name = "nbi" or "ic_nbi")  

!	core_sources/source(i1)/profiles_1d(itime)/j_parallel Izec_prof.txt
!(defined as <j_EC.B>/B0; source index i1 corresponding to source entry with !core_sources/source(i1)/identifier/name = "ec")

!	cp/profiles_1d(itime)/electrons/temperature Te_prof.txt

!	cp/profiles_1d(itime)/t_i_average Ti_prof.txt

!	cp/profiles_1d(itime)/electrons/density_thermal Ne_prof.txt

!sum of cp/profiles_1d(itime)/ion(i1)/density_thermal Ndt_prof.txt
!for i1 = 1 and 2 (cp/profiles_1d(itime)/ion(i1)/label should be !equal to "D" or "T") 

!	cp/profiles_1d(itime)/zeff Zeff_prof.txt

!	equilibrium/time_slice(itime)/profiles_1d/pressure pres_prof.txt

print *, 'Files reading...'

	call prof_read(filename01,tt,rr,x01)
	call prof_read(filename02,tt,rr,x02)
	call prof_read(filename03,tt,rr,x03)
	call prof_read(filename04,tt,rr,x04)
	call prof_read(filename05,tt,rr,x05)
	call prof_read(filename06,tt,rr,x06)
	call prof_read(filename07,tt,rr,x07)
	call prof_read(filename08,tt,rr,x08)
	call prof_read(filename09,tt,rr,x09)
	call prof_read(filename10,tt,rr,x10)
	call prof_read(filename11,tt,rr,x11)
	call prof_read(filename12,tt,rr,x12)
	call prof_read(filename13,tt,rr,x13)

print *, 'Files read successful'

	nt = size(tt,1)
	nr = size(rr,1)

    allocate(cp%profiles_1d(nt))
    allocate(cp%time(nt))

    allocate(cs%source(2))
    allocate(cs%source(1)%profiles_1d(nt))
    allocate(cs%source(2)%profiles_1d(nt))
    allocate(cs%time(nt))

    allocate(eq%time_slice(nt))
    allocate(eq%time(nt))


    cp%ids_properties%homogeneous_time = 1
    cs%ids_properties%homogeneous_time = 1
    eq%ids_properties%homogeneous_time = 1

	do it = 1,nt 
	  allocate(cp%profiles_1d(it)%grid%rho_tor_norm(nr))
	  allocate(cs%source(1)%profiles_1d(it)%grid%rho_tor_norm(nr))
	  allocate(cs%source(2)%profiles_1d(it)%grid%rho_tor_norm(nr))
	  allocate(eq%time_slice(it)%profiles_1d%rho_tor_norm(nr))
	  cp%profiles_1d(it)%grid%rho_tor_norm(1:nr) = rr(1:nr)
	  cs%source(1)%profiles_1d(it)%grid%rho_tor_norm(1:nr) = rr(1:nr)
	  cs%source(2)%profiles_1d(it)%grid%rho_tor_norm(1:nr) = rr(1:nr)
	  eq%time_slice(it)%profiles_1d%rho_tor_norm(1:nr) = rr(1:nr)


	  allocate(cp%profiles_1d(it)%electrons%temperature(nr))
	  allocate(cp%profiles_1d(it)%electrons%density(nr))
	  allocate(cp%profiles_1d(it)%t_i_average(nr))

allocate(cp%profiles_1d(it)%ion(2))
allocate(cp%profiles_1d(it)%ion(1)%element(1))
 cp%profiles_1d(it)%ion(1)%element(1)%a = 2
 cp%profiles_1d(it)%ion(1)%z_ion = 1
 cp%profiles_1d(it)%ion(1)%element(1)%z_n = 1
!cp%profiles_1d(it)%ion(1)%label = 'D+'
allocate(cp%profiles_1d(it)%ion(2)%element(1))
 cp%profiles_1d(it)%ion(2)%element(1)%a = 3
 cp%profiles_1d(it)%ion(2)%z_ion = 1
 cp%profiles_1d(it)%ion(2)%element(1)%z_n = 1
!cp%profiles_1d(it)%ion(1)%label = 'T+'
allocate(cp%profiles_1d(it)%ion(1)%density(nr))
allocate(cp%profiles_1d(it)%ion(2)%density(nr))
! end if

	  allocate(cp%profiles_1d(it)%j_bootstrap(nr))
	  allocate(cp%profiles_1d(it)%j_ohmic(nr))
	  allocate(cp%profiles_1d(it)%j_total(nr))
	  allocate(cp%profiles_1d(it)%conductivity_parallel(nr))
	  allocate(cp%profiles_1d(it)%zeff(nr))
	  allocate(cp%profiles_1d(it)%q(nr))
	  allocate(cs%source(1)%profiles_1d(it)%j_parallel(nr))
	  allocate(cs%source(2)%profiles_1d(it)%j_parallel(nr))
	  allocate(eq%time_slice(it)%profiles_1d%pressure(nr))

          
	  if (allocated(x03)) cp%profiles_1d(it)%electrons%temperature = x03(it,1:nr)
	  if (allocated(x04)) cp%profiles_1d(it)%t_i_average = x04(it,1:nr)
	  if (allocated(x01)) cp%profiles_1d(it)%electrons%density = x01(it,1:nr)
	  if (allocated(x02)) cp%profiles_1d(it)%ion(1)%density = 0.5d0*x02(it,1:nr)
	  if (allocated(x02)) cp%profiles_1d(it)%ion(2)%density = 0.5d0*x02(it,1:nr)
	  if (allocated(x08)) cp%profiles_1d(it)%j_bootstrap = x08(it,1:nr)
	  if (allocated(x09)) cp%profiles_1d(it)%j_ohmic = x09(it,1:nr)
	  if (allocated(x10)) cp%profiles_1d(it)%j_total = x10(it,1:nr)
	  if (allocated(x13)) cp%profiles_1d(it)%conductivity_parallel = x13(it,1:nr)
	  if (allocated(x06)) cp%profiles_1d(it)%zeff = x06(it,1:nr)
	  if (allocated(x07)) cp%profiles_1d(it)%q = x07(it,1:nr)
	  if (allocated(x11)) cs%source(1)%profiles_1d(it)%j_parallel = x11(it,1:nr)
	  if (allocated(x12)) cs%source(2)%profiles_1d(it)%j_parallel = x12(it,1:nr)
	  if (allocated(x05)) eq%time_slice(it)%profiles_1d%pressure = x05(it,1:nr)

	  cp%profiles_1d(it)%time = tt(it)
	  cs%source(1)%profiles_1d(it)%time = tt(it)
	  cs%source(2)%profiles_1d(it)%time = tt(it)
	  eq%time_slice(it)%time = tt(it)

	  cp%time(it) = tt(it)
	  cs%time(it) = tt(it)
	  eq%time(it) = tt(it)
	enddo

print*, 'nt, nr =', nt, nr
print*, 'r =', rr
print*, 't1, tend =', tt(1), tt(nt)
print*, cp%profiles_1d(1)%j_bootstrap
print*, cp%profiles_1d(nt)%j_bootstrap

print*, 'File read successfull'


! call imas_create('ids',pulse,run,1,1,idx0)
call imas_create_env('ids',pulse,run,1,1,idx0,user,'test','3') 

print *,'Pulse, run =', pulse, run
write(*,*) 'Opening the prescribed IDS'
! call imas_open('ids', pulse, run, idx)
call imas_open_env('ids', pulse, run, idx,user,'test','3') 

print *,'imas opened', idx0

call ids_put(idx0,"equilibrium",eq)
call ids_put(idx0,"core_profiles",cp)
call ids_put(idx0,"core_sources",cs)

write(*,*) 'Finished writing the prescribed IDS'
call imas_close(idx0)


call ids_deallocate(eq)
call ids_deallocate(cp)
call ids_deallocate(cs)


write(*,*) 'DINA_IMAS Exiting cleanly'

end 


