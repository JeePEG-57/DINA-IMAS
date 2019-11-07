! main test
! test the DINA_IMAS
! Jo Lister, August 2013

use ids_schemas
use ids_routines
implicit none

interface 
! Declaration of the dina_imas subroutine
subroutine dina_imas_circ(&
  &  em_coupling0, equilibrium0, pf_active0, pf_passive0, core_profiles0, core_sources0 &
  & ,bndcond_in &
  & ,pulse_schedule &
  & ,equilibrium, magnetics, pf_active, pf_passive, core_profiles, core_sources, core_transport &
  & ,summary &
  & ,arr_in1, arr_out1 )
 
     use ids_schemas
! note that IDS0 are all prescribed, the others are dynamic
type (ids_em_coupling)  :: em_coupling0
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_magnetics)   :: magnetics
type (ids_pf_active)   :: pf_active0, pf_active
type (ids_pf_passive)   :: pf_passive0, pf_passive
type (ids_core_profiles)   :: core_profiles0, core_profiles
type (ids_core_transport)   :: core_transport
type (ids_core_sources)   :: core_sources0, core_sources
type (ids_transport_solver_numerics) :: bndcond_in
type (ids_pulse_schedule)   :: pulse_schedule
type (ids_summary) :: summary

    real (ids_real) :: arr_in1(501), arr_out1(501)

    end subroutine
end interface

interface 
! Declaration of the dina_imas subroutine
    subroutine dina_contr (arr_in1,arr_out1)
     use ids_schemas
    real (ids_real) :: arr_in1(501), arr_out1(501)
    end subroutine
    
end interface


type (ids_em_coupling) :: em_coupling0 
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_magnetics) :: magnetics
type (ids_pf_active) :: pf_active0, pf_active, pf_active_a
type (ids_pf_passive) :: pf_passive0, pf_passive
type (ids_core_profiles)   :: core_profiles0, core_profiles
type (ids_core_sources)   :: core_sources0, core_sources
type (ids_core_transport)   :: core_transport
type (ids_transport_solver_numerics) :: bndcond
type (ids_pulse_schedule)   :: pulse_schedule
type (ids_summary) :: summary

real (ids_real) :: arr_in1(501), arr_out1(501)

! define the pulse and run numbers for testing, will be done later outside
integer :: pulse=170, run=8, prescribedpulse=170, prescribedrun=6
real (ids_real) :: tt, StopTime = 750.d0

! define local variables
integer :: time_loop, key(25), indpf(12), ext_transp, i, iloop, imax=1000, nloop, nt
real (ids_real) :: uff1(14) = (/1,2,3,2,1,2,3,2,1,2,3,2,1,2/),temp(50)
integer :: idx, idx0, idxc, err
integer :: nact,npass,ngrid,nbpol,nflux,nrad,npolar,ncronos,nr,nz
real (ids_real) :: tact_err(15), tpass_err, tmaxa

! for timing tests
INTEGER :: clock_start,clock_end,clock_rate

character (len=255) :: user
call getenv("USER", user)

print *,' Enter pulse number'
!read (*,*)prescribedpulse

print *,' pulse number',prescribedpulse
!read (*,*)pulse

print *,' Enter run number'
!read (*,*)prescribedrun

print *,' run number',prescribedrun

print *,' Enter maximum steps number'
!read (*,*)imax
! imax=10
imax=9
print *,' imax',imax

write(*,*) 'The file'


! call imas_open('ids',170,1,idx)
call imas_open_env('ids',170,1,idx,user,'test','3') 

call ids_get(idx,"em_coupling",em_coupling0)
!call ids_get(idx,"pulse_schedule",pulse_schedule)
call ids_get(idx,"equilibrium",equilibrium0)
call imas_close(idx)
write(*,*) 'Transferred non-timed IDSs'


write(*,*) 'Reading the prescribed IDS'
! call imas_open('ids',prescribedpulse,prescribedrun,idx0) 
call imas_open_env('ids',prescribedpulse,prescribedrun,idx0,user,'test','3') 

!call ids_get(idx0,"em_coupling",em_coupling0)
!call ids_get(idx0,"pulse_schedule",pulse_schedule)


call ids_get(idx0,"pf_active",pf_active_a)

! call imas_create('ids',pulse,run,1,1,idxc)
call imas_create_env('ids',pulse,run,1,1,idxc,user,'test','3')

write(*,*) 'Finished reading the prescribed IDS'


arr_in1(1:31)=1
arr_out1(1:31)=0



nt = size(pf_active_a%time,1)
nloop = min(imax,nt)
write(*,*) 'nloop, nt =', nloop, nt


do iloop=1,nloop

write(*,*) 'call DINA_CIRC i =',iloop

tt = pf_active_a%time(iloop)


nact = size(pf_active_a%coil,1)
do i=1,nact
  write(*,*) 'coil voltage =', i, pf_active_a%coil(i)%voltage%data(iloop)
  arr_in1(2+i) = pf_active_a%coil(i)%voltage%data(iloop)
enddo



!call ids_get_slice(idx0,"transport_solver_numerics",bndcond,tt,1)
!call ids_get_slice(idx0,"equilibrium",equilibrium0,tt,1)

!call ids_deallocate(pf_active0)
call ids_get_slice(idx0,"pf_active",pf_active0,tt,1)
! call ids_deallocate(pf_passive0)
call ids_get_slice(idx0,"pf_passive",pf_passive0,tt,1)

!call ids_get_slice(idx0,"core_profiles",core_profiles0,tt,1)
!call ids_get_slice(idx0,"core_sources",core_sources0,tt,1)



call dina_imas_circ( em_coupling0, equilibrium0 &
 & , pf_active0,  pf_passive0, core_profiles0, core_sources0 &
 & , bndcond &
 & , pulse_schedule &
 & ,  equilibrium, &
 & magnetics, pf_active, pf_passive, core_profiles, core_sources, core_transport &
 & , summary &
 & , arr_in1,arr_out1)

!write(*,*) "Controller work"
!call dina_contr(arr_out1,arr_in1)

!call dina_transp1(equilibrium0, core_profiles0, core_sources0, core_profiles, core_sources)
!call dina_transp2(equilibrium0, core_profiles0, core_profiles)
!call dina_transp3(equilibrium0, core_profiles0, core_profiles)
!call dina_transp4(equilibrium0, core_profiles0, core_profiles)
!call dina_transp5(equilibrium0, core_sources0, core_sources)

!call solps_imas(equilibrium, core_transport, bndcond)

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


nact = size(pf_active%coil, 1)
tmaxa = 0.d0
do i=1,nact
  tact_err(i) = pf_active%coil(i)%current%data(1) - pf_active0%coil(i)%current%data(1)
  tmaxa = max(tmaxa,abs(pf_active0%coil(i)%current%data(1)))
enddo
write(*,*) 'PF currents error', tact_err
write(*,*) 'PF currents reler', tact_err/tmaxa
write(*,*) 'PF currents max relative error', maxval(abs(tact_err/tmaxa))

tpass_err = 0.d0
tmaxa = 0d0
npass = size(pf_passive%loop, 1)
do i=1,npass
  tpass_err = tpass_err + abs(pf_passive%loop(i)%current(1) - pf_passive0%loop(i)%current(1))
  tmaxa = max(tmaxa,abs(pf_passive0%loop(i)%current(1)))
enddo
write(*,*) 'Passive currents sum abs error', tpass_err
write(*,*) 'Passive currents relative error', tpass_err/tmaxa


!call dina_put_slice(pf_active, pf_passive, equilibrium, core_profiles, &
! & core_sources, core_transport, bndcond, summary, &
!& pulse, run, iloop, err)

if (iloop == 1) then

do i=1,nact
  if(associated(pf_active%coil(i)%current%time)) deallocate(pf_active%coil(i)%current%time)
  if(associated(pf_active%coil(i)%voltage%time)) deallocate(pf_active%coil(i)%voltage%time)
enddo
call ids_put(idxc,"pf_active",pf_active)
if(associated(pf_passive%loop)) then
  call ids_put(idxc,"pf_passive",pf_passive)
endif

else

do i=1,nact
  if(associated(pf_active%coil(i)%current%time)) deallocate(pf_active%coil(i)%current%time)
  if(associated(pf_active%coil(i)%voltage%time)) deallocate(pf_active%coil(i)%voltage%time)
enddo
call ids_put_slice(idxc,"pf_active",pf_active)
if(associated(pf_passive%loop)) then
  call ids_put_slice(idxc,"pf_passive",pf_passive)
endif

endif

! call ids_deallocate(pf_active0)
! call ids_deallocate(pf_passive0)

!call ids_deallocate(equilibrium0)
!call ids_deallocate(core_profiles0)
!call ids_deallocate(core_sources0)

! call ids_copy(pf_active, pf_active0)
! call ids_copy(pf_passive, pf_passive0)
do i=1,nact
  pf_active0%coil(i)%current%data(1) = pf_active%coil(i)%current%data(1)
enddo
do i=1,npass
  pf_passive0%loop(i)%current(1) = pf_passive%loop(i)%current(1)
enddo

!call ids_copy(equilibrium, equilibrium0)
!call ids_copy(core_profiles, core_profiles0)
!call ids_copy(core_sources, core_sources0)


write(*,*) '****** Pulse time =',summary%time(1),'/',StopTime
if (summary%time(1).gt.StopTime) exit

end do


call imas_close(idx0)
call imas_close(idxc)

!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
write(*,*) 'DINA_IMAS loop finished, clean up'

! write(*,*) 'Deallocate static IDS'
! call ids_deallocate(em_coupling0)
! call ids_deallocate(equilibrium0)
! call ids_deallocate(pf_active0)
! call ids_deallocate(pf_passive0)
! call ids_deallocate(pulse_schedule)
! call ids_deallocate(core_profiles0)
! call ids_deallocate(core_sources0)
! 
! call ids_deallocate(pf_active)
! call ids_deallocate(pf_passive)
! !call ids_deallocate(equilibrium)
! call ids_deallocate(magnetics)
! call ids_deallocate(core_profiles)

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
