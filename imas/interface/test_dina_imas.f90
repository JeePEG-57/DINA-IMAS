! main test
! test the DINA_IMAS
! Jo Lister, August 2013

use ids_schemas
use ids_routines
implicit none

interface 
! Declaration of the dina_imas subroutine
subroutine dina_imas(&
  &  em_coupling0, equilibrium0, magnetics0, pf_active0, pf_passive0, core_profiles0, core_sources0 &
  & ,bndcond_in &
  & ,pulse_schedule &
  & ,em_coupling,equilibrium, magnetics, pf_active, pf_passive, core_profiles, core_sources, core_transport &
  & ,summary &
  & ,arr_in1, arr_out1 )
  


use ids_schemas
use ids_routines
implicit none


! trees are static or dynamic; if not defined, they are static
type (ids_em_coupling)  :: em_coupling0, em_coupling
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_magnetics)   :: magnetics0, magnetics
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


type (ids_em_coupling) :: em_coupling, em_coupling0
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_magnetics) :: magnetics, magnetics0
type (ids_pf_active) :: pf_active, pf_active0
type (ids_pf_passive) :: pf_passive, pf_passive0
type (ids_core_profiles)   :: core_profiles0, core_profiles
type (ids_core_sources)   :: core_sources0, core_sources
type (ids_core_transport)   :: core_transport
type (ids_transport_solver_numerics) :: bndcond
type (ids_pulse_schedule)   :: pulse_schedule
type (ids_dataset_description) :: data_description
type (ids_summary) :: summary
type (ids_wall) :: wall

real (ids_real) :: arr_in1(501), arr_out1(501)

! IDS location data
character (len=255) :: user, database
character (len=255) :: user_prs, database_prs
integer :: pulse_prs=170, run_prs=399
integer :: pulse=170, run=402

! Workflow parameters
real (ids_real) :: time_start=0.0, time_stop=10000.0
integer :: idec, imax
integer :: ext_transp, restart=0

! Local variables
integer :: i, iloop
integer :: idx, idx0, err
!integer :: nact,npass,ngrid
integer :: interpol = 0
real (ids_real) ::time_get,time_ext, current_pf_stop

! For timing tests
INTEGER :: clock_start,clock_end,clock_rate


call getenv("USER", user)


    open(unit=41,file='fortranworkflow.dat',form='formatted')
	print *,' Opened file fortranworkflow.dat'
	read(41,*)
	read(41,*) user_prs, database_prs, pulse_prs, run_prs
	read(41,*)
	read(41,*) database, pulse, run
	read(41,*)
	read(41,*) time_start, time_ext, time_stop
        read(41,*)
	read(41,*) idec, imax
    close (41)

    ext_transp=0

!user_prs = user


print *,' Input user =', trim(user_prs)
print *,' Input database =', trim(database_prs)
print *,' Input pulse, run =', pulse_prs, run_prs
print *,' Start time, s =', time_start
print *,' Output user =', trim(user)
print *,' Output database =', trim(database)
print *,' Output pulse, run =', pulse, run
print *,' Maximum time steps amount =', imax
print *,' Maximum simulation time, s =', time_stop
print *,' Database put decimation =', idec

if (time_start.gt.0.d0) then
  restart = 1
endif

write(*,*) 'Reading the prescribed IDS'
call imas_open_env('ids',pulse_prs,run_prs,idx0,user_prs,database_prs,'3')

if (restart.eq.1) then

  write(*,*) 'Restart from t=', time_start
  time_get = time_start
  interpol = 1 ! CLOSEST_INTERP
  call ids_get_slice(idx0,"em_coupling",em_coupling0, time_get, interpol)
  call ids_get_slice(idx0,"magnetics",magnetics0, time_get, interpol)
  call ids_get_slice(idx0,"equilibrium",equilibrium0, time_get, interpol)
  call ids_get_slice(idx0,"pf_active",pf_active0, time_get, interpol)
  call ids_get_slice(idx0,"pf_passive",pf_passive0, time_get, interpol)
  call ids_get_slice(idx0,"core_profiles",core_profiles0, time_get, interpol)
  call ids_get_slice(idx0,"core_sources",core_sources0, time_get, interpol)
  call ids_get_slice(idx0,"transport_solver_numerics",bndcond, time_get, interpol)

  write(*,*) 'Restart from plasma current, A = ', core_profiles0%global_quantities%ip

else

  write(*,*) 'Start from t=0'
  call ids_get(idx0,"em_coupling",em_coupling0)
  call ids_get(idx0,"magnetics",magnetics0)
  call ids_get(idx0,"equilibrium",equilibrium0)
  call ids_get(idx0,"pf_active",pf_active0)
  call ids_get(idx0,"pf_passive",pf_passive0)
  call ids_get(idx0,"core_profiles",core_profiles0)
  call ids_get(idx0,"core_sources",core_sources0)
  call ids_get(idx0,"transport_solver_numerics",bndcond)
  
endif

call ids_get(idx0,"wall",wall)
call ids_get(idx0,"dataset_description",data_description)
call ids_get(idx0,"pulse_schedule",pulse_schedule)
  
write(*,*) 'Finished reading the prescribed IDS'
call imas_close(idx0)



!print *,'Press any key to begin simulation...'
!read (*,*)



arr_in1(1:31)=1
arr_out1(1:31)=0



  call imas_create_env('ids',pulse,run,1,1,idx,user,database,'3')
  write(*,*) 'Pulse file is created'

  call ids_put(idx,"dataset_description",data_description)
  call ids_put(idx,"pulse_schedule",pulse_schedule)





do iloop=1,imax

write(*,*) 'call DINA_IMAS i =',iloop
flush(6)


call dina_imas( &
 &   em_coupling0, equilibrium0, magnetics0, pf_active0, pf_passive0, core_profiles0, core_sources0 &
 & , bndcond &
 & , pulse_schedule &
 & , em_coupling, equilibrium, &
 & magnetics, pf_active, pf_passive, core_profiles, core_sources, core_transport &
 & , summary &
 & , arr_in1,arr_out1)

 
write(*,*) "DINA_IMAS finished"
flush(6)


call ids_deallocate(pf_active0)
call ids_deallocate(pf_passive0)
call ids_deallocate(em_coupling0)
call ids_deallocate(equilibrium0)
call ids_deallocate(magnetics0)
call ids_deallocate(core_profiles0)
call ids_deallocate(core_sources0)
write(*,*) "DINA_IMAS inputs deallocated"
flush(6)


call dina_contr(arr_out1,arr_in1)

write(*,*) "Controller finished"
flush(6)

!call dina_transp1(equilibrium0, core_profiles0, core_sources0, core_profiles, core_sources)
!call dina_transp2(equilibrium0, core_profiles0, core_profiles)
!call dina_transp3(equilibrium0, core_profiles0, core_profiles)
!call dina_transp4(equilibrium0, core_profiles0, core_profiles)
!call dina_transp5(equilibrium0, core_sources0, core_sources)

call ids_deallocate(bndcond)
call solps_imas(equilibrium, core_transport, bndcond)

write(*,*) "SOLPS finished"
flush(6)

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

if (mod(iloop,idec).eq.0 .or. iloop.eq.1) then

write(*,*) 'Put ids to database, iloop = ', iloop
flush(6)

call dina_put_slice(pf_active, pf_passive, equilibrium, core_profiles, &
 & core_sources, core_transport, bndcond, summary, wall, em_coupling, magnetics, &
& pulse, run, idx, iloop, err)


endif


write(*,*) 'Copy magnetics'
flush(6)
call ids_copy(magnetics, magnetics0)
write(*,*) 'Copy pf_active'
flush(6)
call ids_copy(pf_active, pf_active0)
write(*,*) 'Copy pf_passive'
flush(6)
call ids_copy(pf_passive, pf_passive0)
write(*,*) 'Copy core_profiles'
flush(6)

time_get = summary%time(1)

write(*,*) 'time_get time_ext==',time_get,time_ext

if(time_get.ge.time_ext)then
write(*,*) 'Using prescribed transport'
ext_transp=1
end if

if (ext_transp.eq.1) then
write(*,*) 'Using prescribed transport'

  time_get = summary%time(1)
  interpol = 3 ! LINEAR_INTERP
  
  call imas_open_env('ids',pulse_prs,run_prs,idx0,user_prs,database_prs,'3')
  
  call ids_get_slice(idx0,"core_profiles",core_profiles0, time_get, interpol)
  call ids_get_slice(idx0,"core_sources",core_sources0, time_get, interpol)
  
  call imas_close(idx0)
  
else
write(*,*) 'Using DINA transport'

  call ids_copy(core_profiles, core_profiles0)
  write(*,*) 'Copy core_sources'
  flush(6)
  call ids_copy(core_sources, core_sources0)

endif



write(*,*) '****** Pulsetime =',summary%time(1),'/',time_stop
flush(6)

  current_pf_stop = 0.d0
do i=1,11
  current_pf_stop = current_pf_stop + dabs(pf_active%coil(i)%current%data(1))
enddo

if (summary%time(1).gt.time_stop .or. (dabs(summary%global_quantities%ip%value(1)).lt.1.d3 .and. current_pf_stop.lt.1.d3)) exit


write(*,*) 'Deallocate IDS '
flush(6)
call ids_deallocate(pf_active)
call ids_deallocate(pf_passive)
call ids_deallocate(em_coupling)
call ids_deallocate(equilibrium)
call ids_deallocate(magnetics)
call ids_deallocate(core_profiles)
call ids_deallocate(core_sources)
call ids_deallocate(core_transport)
call ids_deallocate(summary)
write(*,*) 'IDS deallocated'
flush(6)


end do

call imas_close(idx)

!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
write(*,*) 'DINA_IMAS loop finished, clean up'

!write(*,*) 'Deallocate static IDS'
!call ids_deallocate(em_coupling0)
!call ids_deallocate(equilibrium0)
!call ids_deallocate(pf_active0)
!call ids_deallocate(pf_passive0)
!call ids_deallocate(pulse_schedule)
!call ids_deallocate(core_profiles0)
!call ids_deallocate(core_sources0)

!call ids_deallocate(pf_active)
!call ids_deallocate(pf_passive)
!call ids_deallocate(equilibrium)
!call ids_deallocate(magnetics)
!call ids_deallocate(core_profiles)

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
