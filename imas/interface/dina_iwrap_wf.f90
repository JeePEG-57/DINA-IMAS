! main test
! test the DINA_IMAS
! Jo Lister, August 2013


module mod_dina_iwrap_wf

use ids_schemas
use ids_routines


implicit none

type (ids_em_coupling) :: em_coupling
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_magnetics) :: magnetics, magnetics0
type (ids_pf_active) :: pf_active, pf_active1, pf_active0
type (ids_pf_passive) :: pf_passive, pf_passive0
type (ids_core_profiles)   :: core_profiles0, core_profiles
type (ids_core_sources)   :: core_sources0, core_sources
type (ids_core_transport)   :: core_transport
type (ids_transport_solver_numerics) :: bndcond
type (ids_pulse_schedule)   :: pulse_schedule, pulse_schedule_term
type (ids_dataset_description) :: data_description
type (ids_summary) :: summary
type (ids_wall) :: wall

real (ids_real) :: arr_in1(501), arr_out1(501)

! IDS location data
character (len=255) :: user_default
character (len=255) :: user_out, database_out
character (len=255) :: user_prs, database_prs
character (len=255) :: user_psch, database_psch
character (len=255) :: user_transp='', database_transp=''
integer :: pulse_prs=-1, run_prs=-1
integer :: pulse_out=-1, run_out=-1
integer :: pulse_psch=-1, run_psch=-1
integer :: pulse_transp=-1, run_transp=-1

! Workflow parameters
real (ids_real) :: time_start=0.0, time_stop=10000.0
integer :: idec, imax
integer :: ext_transp, restart=0

! Local variables
integer :: i, iloop
integer :: idx, idx0, err
!integer :: nact,npass,ngrid
integer :: interp_start = 1, interp_transp = 1
real (ids_real) ::time_get,time_ext, current_pf_stop

!character(len=30) :: ConfigFile
!character(len=132), pointer :: buffer(:) => NULL()
!integer :: io_unit = 1
logical :: errorflag
integer :: code_state

! For timing tests
INTEGER :: clock_start,clock_end,clock_rate


interface
! Declaration of the dina_imas subroutine
subroutine dina_imas(&
  &  em_coupling0, equilibrium0, magnetics0, pf_active0, pf_passive0, wall0, core_profiles0, core_sources0 &
  & ,bndcond_in &
  & ,pulse_schedule &
  & ,equilibrium, magnetics, pf_active, pf_passive, core_profiles, core_sources, core_transport &
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
type (ids_wall) :: wall0
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
! Declaration of the dina_contr subroutine
subroutine dina_contr(pulse_schedule, pulse_schedule_term, equilibrium0, pf_active0, pf_active, arr_in1,arr_out1)
use ids_schemas
type (ids_pulse_schedule)   :: pulse_schedule, pulse_schedule_term
type (ids_pf_active)   :: pf_active0, pf_active
type (ids_equilibrium) :: equilibrium0
real (ids_real):: arr_in1(*), arr_out1(*)
end subroutine
end interface


contains

subroutine assign_codeparam(codeparam_string)
!    use f90_file_reader, only: file2buffer
!    use xml2eg_mdl, only: xml2eg_parse_memory, xml2eg_get, type_xml2eg_document, xml2eg_free_doc

    use xml2eg_mdl, only: xml2eg_parse_memory, xml2eg_get, type_xml2eg_document, xml2eg_free_doc, set_verbose

    ! Internal
    type(type_xml2eg_document) :: doc

    ! Input/Output
    character(len=132), pointer :: codeparam_string(:)
    

!call file2buffer(ConfigFile, io_unit, buffer)

character(len=255) :: cwd
call getcwd(cwd)
!print *,' Using workflow config file: ', codeparam_string // 'in' // cwd


call xml2eg_parse_memory(codeparam_string, doc)
call set_verbose(.TRUE.) ! Only needed if you want to see what's going on in the parsing

  call xml2eg_get(doc, 'pulse_schedule/user', user_psch)
  call xml2eg_get(doc, 'pulse_schedule/database', database_psch)
  call xml2eg_get(doc, 'pulse_schedule/pulse', pulse_psch)
  call xml2eg_get(doc, 'pulse_schedule/run', run_psch)
  
  call xml2eg_get(doc, 'input_start/user', user_prs)
  call xml2eg_get(doc, 'input_start/database', database_prs)
  call xml2eg_get(doc, 'input_start/pulse', pulse_prs)
  call xml2eg_get(doc, 'input_start/run', run_prs)
  call xml2eg_get(doc, 'input_start/time_start', time_start)
  call xml2eg_get(doc, 'input_start/interp_mode', interp_start)

  call xml2eg_get(doc, 'output/database', database_out)
  call xml2eg_get(doc, 'output/pulse', pulse_out)
  call xml2eg_get(doc, 'output/run', run_out)
  call xml2eg_get(doc, 'output/decimation', idec)

  call xml2eg_get(doc, 'input_transp/user', user_transp)
  call xml2eg_get(doc, 'input_transp/database', database_transp)
  call xml2eg_get(doc, 'input_transp/pulse', pulse_transp)
  call xml2eg_get(doc, 'input_transp/run', run_transp)
  call xml2eg_get(doc, 'input_transp/interp_mode', interp_transp)

  call xml2eg_get(doc, 'time_stop', time_stop)
  call xml2eg_get(doc, 'time_ext', time_ext)
  call xml2eg_get(doc, 'step_max', imax)


call xml2eg_free_doc(doc)
!deallocate(buffer)

end subroutine assign_codeparam


subroutine init(dina_wf_code_params,  status_code, status_msg)

implicit none

type(ids_parameters_input) :: dina_wf_code_params
integer, intent(out) :: status_code
character(len=:), pointer, intent(out) :: status_msg

call getenv("USER", user_default)


ext_transp=0

!if (command_argument_count().eq.0) then
!  print *,'Not enough arguments. First argument must be the name of a workflow config XML file!'
!  stop
!endif
!
!do i = 1, command_argument_count()
!  call get_command_argument(i, ConfigFile)
!end do
!ConfigFile = 'wfconfig.xml'

call assign_codeparam(dina_wf_code_params%parameters_value)



! open(unit=41,file=trim(ConfigFile),form='formatted')
!     print *,' Opened file ', ConfigFile
!     read(41,*)
!     read(41,*) user_prs, database_prs, pulse_prs, run_prs, time_start, interp_start
!     read(41,*)
!     read(41,*) database_out, pulse_out, run_out, idec
!     read(41,*)
!     read(41,*) user_transp, database_transp, pulse_transp, run_transp, interp_transp
!     read(41,*)
!     read(41,*) time_ext, time_stop, imax
! close(41)





if (trim(user_prs).eq.'') user_prs = user_default
if (trim(user_psch).eq.'') user_psch = user_default
if (trim(user_transp).eq.'') user_transp = user_default
user_out = user_default


print *,' Start user =', trim(user_prs)
print *,' Start database =', trim(database_prs)
print *,' Start pulse, run =', pulse_prs, run_prs
print *,' Start time, s =', time_start
print *,' Start interpolation =', interp_start

print *,' Transp user =', trim(user_transp)
print *,' Transp database =', trim(database_transp)
print *,' Transp pulse, run =', pulse_transp, run_transp
print *,' Transp interpolation =', interp_transp

print *,' Output user =', trim(user_out)
print *,' Output database =', trim(database_out)
print *,' Output pulse, run =', pulse_out, run_out
print *,' Output put decimation =', idec

print *,' External transport time, s =', time_ext
print *,' Maximum time steps amount =', imax
print *,' Maximum simulation time, s =', time_stop



if (time_start.gt.0.d0) then
  restart = 1
endif


write(*,*) 'Reading the prescribed IDS'
call imas_open_env('ids',pulse_prs,run_prs,idx0,user_prs,database_prs,'3')

if (restart.eq.1) then

  write(*,*) 'Restart from t=', time_start
  time_get = time_start
  
  call ids_get_slice(idx0,"em_coupling",em_coupling, time_get, interp_start)
  call ids_get_slice(idx0,"magnetics",magnetics0, time_get, interp_start)
  call ids_get_slice(idx0,"equilibrium",equilibrium0, time_get, interp_start)
  call ids_get_slice(idx0,"pf_active",pf_active0, time_get, interp_start)
  call ids_get_slice(idx0,"pf_passive",pf_passive0, time_get, interp_start)
  call ids_get_slice(idx0,"core_profiles",core_profiles0, time_get, interp_start)
  call ids_get_slice(idx0,"core_sources",core_sources0, time_get, interp_start)
  call ids_get_slice(idx0,"transport_solver_numerics",bndcond, time_get, interp_start)

  write(*,*) 'Restart from plasma current, A = ', core_profiles0%global_quantities%ip

else

  write(*,*) 'Start from t=0'
  !call ids_get(idx0,"em_coupling",em_coupling)
  call ids_get(idx0,"magnetics",magnetics0)
  !call ids_get(idx0,"equilibrium",equilibrium0)
  call ids_get(idx0,"pf_active",pf_active0)
  call ids_get(idx0,"pf_passive",pf_passive0)
  call ids_get(idx0,"core_profiles",core_profiles0)
  call ids_get(idx0,"core_sources",core_sources0)
  call ids_get(idx0,"transport_solver_numerics",bndcond)
  
  call dina_green(pf_active0, pf_passive0, magnetics0, em_coupling, equilibrium0)
  
endif

call ids_get(idx0,"wall",wall)
call ids_get(idx0,"dataset_description",data_description)

write(*,*) 'Finished reading the prescribed IDS'
call imas_close(idx0)


write(*,*) 'Reading the pulse schedule'
call imas_open_env('ids',pulse_psch,run_psch,idx0,user_psch,database_psch,'3')

call ids_get(idx0,"pulse_schedule",pulse_schedule)
call ids_get(idx0,"pulse_schedule/1",pulse_schedule_term)

call imas_close(idx0)

!print *,'Press any key to begin simulation...'
!read (*,*)



arr_in1(1:31)=1
arr_out1(1:31)=0



  !call imas_create_env('ids',pulse_out,run_out,1,1,idx,user_out,database_out,'3')
  !write(*,*) 'Pulse file is created'

  !call ids_put(idx,"wall",wall)
  !call ids_put(idx,"em_coupling",em_coupling)
  !call ids_put(idx,"dataset_description",data_description)
  !call ids_put(idx,"pulse_schedule",pulse_schedule)
  !call ids_put(idx,"pulse_schedule/1",pulse_schedule_term)

  allocate(character(50):: status_msg)
  status_msg = 'DINA initialized'
  status_code = 0
  code_state = 0
  iloop = 1

end subroutine init


subroutine step(pf_active_out, summary_out, magnetics_out, pf_passive_out, equilibrium_out, core_profiles_out, core_sources_out, core_transport_out, bndcond_out, codeparam, status_code, status_message )
use ids_schemas, only: ids_summary,ids_equilibrium,ids_parameters_input,ids_is_valid
use ids_routines, only: ids_copy

type (ids_pf_active)   :: pf_active_out
type (ids_summary) :: summary_out
type (ids_magnetics)   :: magnetics_out
type (ids_pf_passive)   :: pf_passive_out
type (ids_equilibrium) :: equilibrium_out
type (ids_core_profiles)   :: core_profiles_out
type (ids_core_transport)   :: core_transport_out
type (ids_core_sources)   :: core_sources_out
type (ids_transport_solver_numerics) :: bndcond_out
type (ids_pulse_schedule)   :: pulse_schedule_out


type(ids_parameters_input) :: codeparam

integer, intent(out) :: status_code
character(len=:), pointer, intent(out) :: status_message
allocate(character(50):: status_message)


!do iloop=1,imax

write(*,*) 'call DINA_IMAS i =',iloop
flush(6)


call dina_imas( &
 &   em_coupling, equilibrium0, magnetics0, pf_active0, pf_passive0, wall, core_profiles0, core_sources0 &
 & , bndcond &
 & , pulse_schedule &
 & , equilibrium, magnetics, pf_active1, pf_passive, core_profiles, core_sources, core_transport &
 & , summary &
 & , arr_in1,arr_out1)

 
write(*,*) "DINA_IMAS finished"
flush(6)


call ids_deallocate(pf_active0)
call ids_deallocate(pf_passive0)
call ids_deallocate(equilibrium0)
call ids_deallocate(magnetics0)
call ids_deallocate(core_profiles0)
call ids_deallocate(core_sources0)
write(*,*) "DINA_IMAS inputs deallocated"
flush(6)


call dina_contr(pulse_schedule, pulse_schedule_term, equilibrium, pf_active1, pf_active, arr_out1, arr_in1)

call ids_deallocate(pf_active1)


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

  !call ids_put_slice(idx,"pf_active",pf_active)
  !call ids_put_slice(idx,"summary",summary)
  call ids_copy(pf_active, pf_active_out)
  call ids_copy(summary, summary_out)

  !if (mod(iloop,idec).eq.0 .or. iloop.eq.1) then
  
    write(*,*) 'Put ids slice to database, iloop = ', iloop
    flush(6)
    
    write(*,*)  'Put magnetics'
    !call ids_put_slice(idx,"magnetics",magnetics)
    call ids_copy(magnetics, magnetics_out)
    
    write(*,*)  'Put pf_passive'
    !call ids_put_slice(idx,"pf_passive",pf_passive)
    call ids_copy(pf_passive, pf_passive_out)
  
    write(*,*)  'Put equilibrium'
    !call ids_put_slice(idx,"equilibrium",equilibrium)
    call ids_copy(equilibrium, equilibrium_out)
  
    write(*,*)  'Put core_profiles'
    !call ids_put_slice(idx,"core_profiles",core_profiles)
    call ids_copy(core_profiles, core_profiles_out)
  
    write(*,*)  'Put core_sources'
    !call ids_put_slice(idx,"core_sources",core_sources)
    call ids_copy(core_sources, core_sources_out)
  
    write(*,*)  'Put core_transport'
    !call ids_put_slice(idx,"core_transport",core_transport)
    call ids_copy(core_transport, core_transport_out)
  
    write(*,*)  'Put transport_solver_numerics'
    !call ids_put_slice(idx,"transport_solver_numerics",bndcond)
    call ids_copy(bndcond, bndcond_out)
  
  !endif


write(*,*) 'Copy magnetics'
flush(6)
call ids_copy(magnetics, magnetics0)
write(*,*) 'Copy pf_active'
flush(6)
call ids_copy(pf_active, pf_active0)
write(*,*) 'Copy pf_passive'
flush(6)
call ids_copy(pf_passive, pf_passive0)


time_get = summary%time(1)

flush(6)
write(*,*) 'time_get time_ext==',time_get,time_ext

if(time_get.ge.time_ext)then
write(*,*) 'Using prescribed transport'
ext_transp=1
end if

if (ext_transp.eq.1) then
write(*,*) 'Using prescribed transport'

  time_get = summary%time(1)
  
  call imas_open_env('ids',pulse_transp,run_transp,idx0,user_transp,database_transp,'3')
  
  call ids_get_slice(idx0,"core_profiles",core_profiles0, time_get, interp_transp)
  call ids_get_slice(idx0,"core_sources",core_sources0, time_get, interp_transp)
  
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

if (summary%time(1).gt.time_stop .or. (dabs(summary%global_quantities%ip%value(1)).lt.1.d3 .and. current_pf_stop.lt.1.d3)) then
  code_state = 2
  status_code = 0
  status_message = 'DINA completed'
  return
end if


write(*,*) 'Deallocate IDS '
flush(6)
call ids_deallocate(pf_active)
call ids_deallocate(pf_passive)
call ids_deallocate(equilibrium)
call ids_deallocate(magnetics)
call ids_deallocate(core_profiles)
call ids_deallocate(core_sources)
call ids_deallocate(core_transport)
call ids_deallocate(summary)
write(*,*) 'IDS deallocated'
flush(6)

status_code = 0
status_message = 'DINA step finished'
code_state = 1
iloop = iloop + 1

end subroutine step


subroutine finalize(status_code, status_message)

integer, intent(out) :: status_code
character(len=:), pointer, intent(out) :: status_message
allocate(character(50):: status_message)


!call imas_close(idx)

!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
write(*,*) 'DINA_IMAS loop finished, clean up'

write(*,*) 'Deallocate static IDS'

call ids_deallocate(em_coupling)
call ids_deallocate(wall)
call ids_deallocate(pulse_schedule)
call ids_deallocate(data_description)

write(*,*) 'DINA_IMAS Exiting cleanly'

status_code = 0
status_message = 'DINA finished'
code_state = 3
end subroutine finalize


subroutine get_status(state_str, status_code, status_message)
  implicit none
  character(len=:), allocatable, intent(out) :: state_str
  integer, intent(out) :: status_code
  character(len=:), pointer, intent(out) :: status_message

  status_message = 'OK'
  status_code = 0
  allocate(character(50):: state_str)
  write(state_str,*) code_state
end subroutine

subroutine loop()
! call init()
!do iloop=1,imax
!  call step()
!end do
!call finalize()
end subroutine loop

end module mod_dina_iwrap_wf

!program DINA_Workflow
!use mod_dina_iwrap
!call loop
!end program DINA_Workflow
