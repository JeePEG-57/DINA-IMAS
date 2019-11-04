
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


print *,'Pulse, run =', pulse, run
write(*,*) 'Opening the prescribed IDS'
! call imas_open('ids', pulse, run, idx)
call imas_open_env('ids', pulse, run, idx,user,'test','3') 

print *,'imas opened', idx0

call ids_get(idx0,"equilibrium",eq)
call ids_get(idx0,"core_profiles",cp)
call ids_get(idx0,"core_sources",cs)

write(*,*) 'Finished reading the prescribed IDS'
call imas_close(idx0)


	nt = size(cp%time,1)
	nr = size(cp%profiles_1d(1)%grid%rho_tor_norm,1)

print *,'nt, nr =', nt, nr

    allocate(tt(nt))
    allocate(rr(nr))

    allocate(x01(nt,nr))
    allocate(x02(nt,nr))
    allocate(x03(nt,nr))
    allocate(x04(nt,nr))
    allocate(x05(nt,nr))
    allocate(x06(nt,nr))
    allocate(x07(nt,nr))
    allocate(x08(nt,nr))
    allocate(x09(nt,nr))
    allocate(x10(nt,nr))
    allocate(x11(nt,nr))
    allocate(x12(nt,nr))
    allocate(x13(nt,nr))

print *,'Allocations complete'

    rr(1:nr) = cp%profiles_1d(1)%grid%rho_tor_norm

print *,'rr set'

	do it = 1,nt 
!	  if (allocated(cp%profiles_1d(it)%electrons%temperature)) 
            x03(it,1:nr) = cp%profiles_1d(it)%electrons%temperature
!	  if (allocated(cp%profiles_1d(it)%t_i_average))
	    x04(it,1:nr) = cp%profiles_1d(it)%t_i_average
!	  if (allocated(cp%profiles_1d(it)%electrons%density))
	    x01(it,1:nr) = cp%profiles_1d(it)%electrons%density
!	  if (allocated(cp%profiles_1d(it)%ion(1)%density))
	    x02(it,1:nr) = cp%profiles_1d(it)%ion(1)%density + cp%profiles_1d(it)%ion(2)%density
!	  if (allocated(cp%profiles_1d(it)%j_bootstrap))
	    x08(it,1:nr) = cp%profiles_1d(it)%j_bootstrap
!	  if (allocated(cp%profiles_1d(it)%j_ohmic))
	    x09(it,1:nr) = cp%profiles_1d(it)%j_ohmic
!	  if (allocated(cp%profiles_1d(it)%j_total))
	    x10(it,1:nr) = cp%profiles_1d(it)%j_total
!	  if (allocated(cp%profiles_1d(it)%conductivity_parallel))
	    x13(it,1:nr) = cp%profiles_1d(it)%conductivity_parallel
!	  if (allocated(cp%profiles_1d(it)%zeff))
	    x06(it,1:nr) = cp%profiles_1d(it)%zeff
!	  if (allocated(cp%profiles_1d(it)%q))
	    x07(it,1:nr) = cp%profiles_1d(it)%q
!	  if (allocated(cs%source(1)%profiles_1d(it)%j_parallel))
	    x11(it,1:nr) = cs%source(1)%profiles_1d(it)%j_parallel
!	  if (allocated(cs%source(2)%profiles_1d(it)%j_parallel))
	    x12(it,1:nr) = cs%source(2)%profiles_1d(it)%j_parallel
!	  if (allocated(eq%time_slice(it)%profiles_1d%pressure))
	    x05(it,1:nr) = eq%time_slice(it)%profiles_1d%pressure

	  tt(it) = cp%time(it)
	enddo

print*, 'nt, nr =', nt, nr
print*, 'r =', rr
print*, 't1, tend =', tt(1), tt(nt)
print*, cp%profiles_1d(1)%j_bootstrap
print*, cp%profiles_1d(nt)%j_bootstrap


call ids_deallocate(eq)
call ids_deallocate(cp)
call ids_deallocate(cs)



print *, 'Files writing...'

	call prof_write(filename01,tt,rr,x01)
	call prof_write(filename02,tt,rr,x02)
	call prof_write(filename03,tt,rr,x03)
	call prof_write(filename04,tt,rr,x04)
	call prof_write(filename05,tt,rr,x05)
	call prof_write(filename06,tt,rr,x06)
	call prof_write(filename07,tt,rr,x07)
	call prof_write(filename08,tt,rr,x08)
	call prof_write(filename09,tt,rr,x09)
	call prof_write(filename10,tt,rr,x10)
	call prof_write(filename11,tt,rr,x11)
	call prof_write(filename12,tt,rr,x12)
	call prof_write(filename13,tt,rr,x13)

print *, 'Files written successful'


write(*,*) 'DINA_IMAS Exiting cleanly'

end 
