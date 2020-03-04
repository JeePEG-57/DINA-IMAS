! test the DINA_EQUIL
! Jo Lister, August 2013

use ids_schemas
use ids_routines
implicit none

interface 
! Declaration of the dina_equil subroutine 
subroutine dina_equil(&
  &  em_coupling0, equilibrium0, pf_active0, pf_passive0 &
  & ,equilibrium) 
 
     use ids_schemas
! note that IDS0 are all prescribed, the others are dynamic
type (ids_em_coupling)  :: em_coupling0
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_pf_active)   :: pf_active0
type (ids_pf_passive)   :: pf_passive0

    end subroutine
end interface


type (ids_em_coupling) :: em_coupling0
type (ids_equilibrium) :: equilibrium_ref, equilibrium0, equilibrium
type (ids_magnetics) :: magnetics
type (ids_pf_active) :: pf_active0, pf_active
type (ids_pf_passive) :: pf_passive0, pf_passive
type (ids_core_profiles)   :: core_profiles0, core_profiles
type (ids_core_sources)   :: core_sources0, core_sources


! define the pulse and run numbers for testing, will be done later outside
integer :: pulse=171, run=7, prescribedpulse=170, prescribedrun=7

! define local variables
integer :: time_loop, i, iloop, idec, imax, nt, interpol = 0
real (ids_real) :: time_max, time_get, tpl_last, time_get1, time_i
integer :: idx, idx0, err, i_get
integer :: nact,npass,ngrid,nbpol,nflux,nrad,npolar,ncronos,nr,nz
character (len=255) :: user


! for timing tests
INTEGER :: clock_start,clock_end,clock_rate


call getenv("USER", user)
print *,' User name is ', user


write(*,*) 'Reading the prescribed IDS pulse, run ==', prescribedpulse, prescribedrun 
! call imas_open('ids',prescribedpulse,prescribedrun,idx0) 
call imas_open_env('ids',prescribedpulse,prescribedrun,idx0,user,'test','3') 


call ids_get(idx0,"equilibrium",equilibrium_ref)
nt = size(equilibrium_ref%time_slice, 1)
time_max = equilibrium_ref%time_slice(nt)%time
tpl_last = equilibrium_ref%time_slice(nt)%global_quantities%ip

write(*,*) 'ref ids nt, time_max, tpl_last =', nt, time_max, tpl_last

!time_get = time_max

time_get1 = 3.95
do i=1,nt
time_i = equilibrium_ref%time_slice(i)%time
if(time_i .ge.time_get1)then
i_get=i
time_get=time_i
goto 2
end if
end do

  2     continue

write(*,*) 'i_get time_get1 time_get =', i_get,time_get1,time_get


interpol = 1

write(*,*) 'get slice time_get =', time_get
flush(6)

call ids_get_slice(idx0,"equilibrium",equilibrium0, time_get, interpol)
call ids_get_slice(idx0,"em_coupling",em_coupling0, time_get, interpol)
call ids_get_slice(idx0,"pf_active",pf_active0, time_get, interpol)
call ids_get_slice(idx0,"pf_passive",pf_passive0, time_get, interpol)



write(*,*) 'Finished reading the prescribed IDS'
call imas_close(idx0)

write(*,*) 'Output pulse, run ==', pulse, run 


flush(6)

call dina_equil(em_coupling0, equilibrium0, pf_active0, pf_passive0, equilibrium)

write(*,*) "DINA_EQUIL finished"
flush(6)

call imas_open_env('ids',pulse,run,idx,user,'test','3') 


write(*,*) 'Put calculated equilibrium...'

   call ids_put(idx,"equilibrium",equilibrium)
 
write(*,*) 'Put input data...'
   call ids_put(idx,"pf_active",pf_active0)
   call ids_put(idx,"pf_passive",pf_passive0)   
   call ids_put(idx,"core_profiles",em_coupling0)

call imas_close(idx)


write(*,*) 'Deallocate IDS...'
flush(6)

call ids_deallocate(em_coupling0)
call ids_deallocate(pf_active0)
call ids_deallocate(pf_passive0)
call ids_deallocate(equilibrium0)
call ids_deallocate(equilibrium)


write(*,*) 'TEST_DINA_EQUIL Exiting cleanly'

end 
