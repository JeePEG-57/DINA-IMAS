! main test
! test the DINA_IMAS
! Jo Lister, August 2013

use ids_schemas
use ids_routines
implicit none

interface 
! Declaration of the dina_imas subroutine
    subroutine dina_imas ( em_coupling0_in, equilibrium0_in,  &
 & pf_active0_in, pf_passive0_in, core_profiles0_in, pulse_schedule_in, equilibrium_in, &
 & magnetics_in, pf_active_in, pf_passive_in, core_profiles_in, &
 & arr_in1,arr_out1)
 
     use ids_schemas
! note that IDS0 are all prescribed, the others are dynamic
!      type (ids_dina) :: dina0_in, dina_in
      type (ids_em_coupling) :: em_coupling0_in
      type (ids_equilibrium) :: equilibrium0_in, equilibrium_in
      type (ids_magnetics) :: magnetics_in
      type (ids_pf_active) :: pf_active0_in, pf_active_in
      type (ids_pf_passive) :: pf_passive0_in, pf_passive_in
      type (ids_core_profiles)   :: core_profiles0_in, core_profiles_in
      type (ids_pulse_schedule)   :: pulse_schedule_in

    real (DP) :: arr_in1(501), arr_out1(501)

    end subroutine
end interface

interface 
! Declaration of the dina_imas subroutine
    subroutine dina_contr (arr_in1,arr_out1)
     use ids_schemas
    real (DP) :: arr_in1(501), arr_out1(501)
    end subroutine
    
end interface


!type (ids_dina) :: dina0, dina
type (ids_em_coupling) :: em_coupling0
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_magnetics) :: magnetics
type (ids_pf_active) :: pf_active0, pf_active
type (ids_pf_passive) :: pf_passive0, pf_passive
type (ids_core_profiles)   :: core_profiles0, core_profiles
type (ids_pulse_schedule)   :: pulse_schedule0

real (DP) :: arr_in1(501), arr_out1(501)

! define the pulse and run numbers for testing, will be done later outside
integer :: pulse=170, run=2, prescribedpulse=170, prescribedrun=1

! define local variables
integer :: time_loop, key(25), indpf(12), ext_transp, i, iloop
real (DP) :: uff1(14) = (/1,2,3,2,1,2,3,2,1,2,3,2,1,2/),temp(50)
integer :: idx, idx0, err
integer :: nact,npass,ngrid,nbpol,nflux,nrad,npolar,ncronos,nr,nz

! for timing tests
INTEGER :: clock_start,clock_end,clock_rate


print *,' Enter pulse number'
!read (*,*)prescribedpulse
prescribedpulse=170

print *,' pulse number',prescribedpulse
pulse=prescribedpulse

print *,' Enter run number'
!read (*,*)prescribedrun
prescribedrun=1
print *,' run number',prescribedrun

write(*,*) 'The file'

write(*,*) 'Reading the prescribed IDS'
call imas_open('ids',prescribedpulse,prescribedrun,idx0) 

call ids_get(idx0,"em_coupling",em_coupling0)
call ids_get(idx0,"equilibrium",equilibrium0)
call ids_get(idx0,"pf_active",pf_active0)
call ids_get(idx0,"pf_passive",pf_passive0)
call ids_get(idx0,"core_profiles",core_profiles0)
call ids_get(idx0,"pulse_schedule",pulse_schedule0)

write(*,*) 'Finished reading the prescribed IDS'
call imas_close(idx0)


arr_in1(1:31)=1
arr_out1(1:31)=0

do iloop=1,4000

write(*,*) 'call DINA_IMAS i =',iloop

call dina_imas( em_coupling0, equilibrium0,   &
 & pf_active0,  pf_passive0, core_profiles0, pulse_schedule0,  equilibrium, &
 & magnetics, pf_active, pf_passive, core_profiles, &
 & arr_in1,arr_out1)

write(*,*) "Controller work"

call dina_contr(arr_out1,arr_in1)


! if (iloop == 1) then
! write(*,*)  'Put non-timed'
! 
!   call ids_put(idx,"pf_active",pf_active)
!   call ids_put(idx,"pf_passive",pf_passive)
! 
!   call ids_put(idx,"equilibrium",equilibrium)
!   call ids_put(idx,"core_profiles",core_profiles)
! 
! else
! 
! write(*,*)  'Put slices'
! 
! !magnetics%time(1) = 123
! !call ids_put_slice(idx,"magnetics",magnetics)
! 
! write(*,*)  'Put pf_active'
! call ids_put_slice(idx,"pf_active",pf_active)
! 
! write(*,*)  'Put pf_passive'
! call ids_put_slice(idx,"pf_passive",pf_passive)
! 
! write(*,*)  'Put equilibrium'
! call ids_put_slice(idx,"equilibrium",equilibrium)
! 
! write(*,*)  'Put core_profiles'
! call ids_put_slice(idx,"core_profiles",core_profiles)
! 
! write(*,*)  'Slices put'
! 
! endif


call dina_put_slice(pf_active, pf_passive, equilibrium, core_profiles, &
& pulse, run, iloop, err)


call ids_deallocate(pf_active0)
call ids_deallocate(pf_passive0)
call ids_deallocate(equilibrium0)
call ids_deallocate(core_profiles0)


call ids_copy(pf_active, pf_active0)
call ids_copy(pf_passive, pf_passive0)
call ids_copy(equilibrium, equilibrium0)
call ids_copy(core_profiles, core_profiles0)

end do

!call imas_close(idx)

!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
write(*,*) 'DINA_IMAS loop finished, clean up'

write(*,*) 'Deallocate static IDS'
call ids_deallocate(em_coupling0)
call ids_deallocate(equilibrium0)
call ids_deallocate(pf_active0)
call ids_deallocate(pf_passive0)
call ids_deallocate(pulse_schedule0)
call ids_deallocate(core_profiles0)

call ids_deallocate(pf_active)
call ids_deallocate(pf_passive)
call ids_deallocate(equilibrium)
call ids_deallocate(magnetics)
call ids_deallocate(core_profiles)

! write(*,*) 'Read back full dynamic IDS as a test'
! 
! call imas_open('ids',pulse,run,idx)
! !call ids_get(idx,"magnetics",magnetics)
! call ids_get(idx,"pf_active",pf_active)
! call ids_get(idx,"pf_passive",pf_passive)
! 
! call imas_close(idx)
! 
! write(*,*) "coil 1 current = ",pf_active%coil(1)%current%data
! !write(*,*) "outline = ", pf_active%coil(5)%element(1)%geometry%outline%r
! !write(*,*) "shape1",dina%output_group_7%shape%data(1,:)
! write(*,*) "loop 1 current = ",pf_passive%loop(1)%current


write(*,*) 'DINA_IMAS Exiting cleanly'

end 
