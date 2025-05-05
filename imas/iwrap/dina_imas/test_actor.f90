
program DINA_IMAS_test

use ids_schemas
use ids_routines

use f90_file_reader, only: file2buffer
use xml2eg_mdl, only: xml2eg_parse_memory, xml2eg_get, type_xml2eg_document, xml2eg_free_doc

use dina_imas

implicit none




type (ids_em_coupling) :: em_coupling
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_magnetics) :: magnetics, magnetics0
type (ids_pf_active) :: pf_active, pf_active0
type (ids_pf_passive) :: pf_passive, pf_passive0
type (ids_core_profiles)   :: core_profiles0, core_profiles
type (ids_core_sources)   :: core_sources0, core_sources
type (ids_core_transport)   :: core_transport
type (ids_transport_solver_numerics) :: bndcond
type (ids_pulse_schedule)   :: pulse_schedule
type (ids_summary) :: summary
type (ids_wall) :: wall

integer :: ibackend = 12


! IDS location data
character (len=255) :: user_default

character (len=255) :: user_out='', database_out
integer :: pulse_out=-1, run_out=-1

character (len=255) :: user_eq='', database_eq
integer :: pulse_eq=-1, run_eq=-1



integer :: i

integer :: idx_a, idx_p, idx_m, idx_e, idx
integer :: interp_start = 1
real (ids_real) :: time_start

character(len=30) :: ConfigFile
type(type_xml2eg_document) :: doc
character(len=132), pointer :: buffer(:) => NULL()
integer :: io_unit = 1

! For timing tests
INTEGER :: clock_start,clock_end,clock_rate


 type(ids_parameters_input) :: codeparam
 integer :: error_flag
 character(len=:), pointer :: error_message




call getenv("USER", user_default)



if (command_argument_count().eq.0) then
  print *,'Not enough arguments. First argument must be the name of a workflow config XML file!'
  stop
endif

do i = 1, command_argument_count()
  call get_command_argument(i, ConfigFile)
end do


print *,' Using workflow config file: ', ConfigFile


call file2buffer(ConfigFile, io_unit, buffer)
call xml2eg_parse_memory(buffer, doc)
  
  call xml2eg_get(doc, 'input_scenario/user', user_eq)
  call xml2eg_get(doc, 'input_scenario/database', database_eq)
  call xml2eg_get(doc, 'input_scenario/pulse', pulse_eq)
  call xml2eg_get(doc, 'input_scenario/run', run_eq)
  call xml2eg_get(doc, 'input_scenario/time_start', time_start)

  call xml2eg_get(doc, 'output/user', user_out)
  call xml2eg_get(doc, 'output/database', database_out)
  call xml2eg_get(doc, 'output/pulse', pulse_out)
  call xml2eg_get(doc, 'output/run', run_out)


call xml2eg_free_doc(doc)
deallocate(buffer)


if (trim(user_eq).eq.'') user_eq = user_default
if (trim(user_out).eq.'') user_out = user_default


print *,' Equilibrium user, database, pulse, run =', trim(user_eq), trim(database_eq), pulse_eq, run_eq
print *,' Output user =', trim(user_out), trim(database_out), pulse_out, run_out



interp_start = 1
time_start = 0.d0

call imas_open_env('ids',pulse_eq,run_eq,idx_e,user_eq,database_eq,'3')
call ids_get_slice(idx_e,"equilibrium",equilibrium0, time_start, interp_start)
call ids_get_slice(idx_e,"core_profiles",core_profiles0, time_start, interp_start)
call ids_get_slice(idx_e,"core_sources",core_sources0, time_start, interp_start)
call ids_get(idx_e,"pulse_schedule",pulse_schedule)
call ids_get_slice(idx_e,"em_coupling",em_coupling, time_start, interp_start)
call ids_get_slice(idx_e,"pf_active",pf_active0, time_start, interp_start)
call ids_get_slice(idx_e,"pf_passive",pf_passive0, time_start, interp_start)
call ids_get_slice(idx_e,"wall",wall, time_start, interp_start)
call ids_get_slice(idx_e,"magnetics",magnetics0, time_start, interp_start)
call imas_close(idx_e)


flush(6)


! Get code parameters
call file2buffer('code_parameters.xml', io_unit, codeparam%parameters_value)

call dina_step( &
 &   em_coupling, equilibrium0, magnetics0, pf_active0, pf_passive0, wall, core_profiles0, core_sources0 &
 & , bndcond &
 & , pulse_schedule &
 & , equilibrium, magnetics, pf_active, pf_passive, core_profiles, core_sources, core_transport &
 & , summary &
 & , codeparam, error_flag, error_message)


write(*,*) 'dina_step error_flag =', error_flag
if (associated(error_message) .and. error_flag.ne.0) then 
write(*,*) 'dina_step error_message =', error_message
endif

flush(6)



  call imas_create_env('ids',pulse_out,run_out,1,1,idx,user_out,database_out,'3')
  write(*,*) 'Output database is created'


    write(*,*)  'Put em_coupling'
    call ids_put(idx,"em_coupling",em_coupling)

    write(*,*)  'Put pf_active'
    call ids_put(idx,"pf_active",pf_active)
    
    write(*,*)  'Put pf_passive'
    call ids_put(idx,"pf_passive",pf_passive)
  
    write(*,*)  'Put equilibrium'
    call ids_put(idx,"equilibrium",equilibrium)
  
    write(*,*)  'Put core_profiles'
    call ids_put(idx,"core_profiles",core_profiles)
  
    write(*,*)  'Put core_sources'
    call ids_put(idx,"core_sources",core_sources)
  
    write(*,*)  'Put core_transport'
    call ids_put(idx,"core_transport",core_transport)
  
    write(*,*)  'Put summary'
    call ids_put(idx,"summary",summary)
  
    write(*,*)  'Put wall'
    call ids_put(idx,"wall",wall)
  
    write(*,*)  'Put pulse_schedule'
    call ids_put(idx,"pulse_schedule",pulse_schedule)
  
    write(*,*)  'Put magnetics'
    call ids_put(idx,"magnetics",magnetics)
	
  call imas_close(idx)
	
	
call ids_deallocate(em_coupling)
call ids_deallocate(wall)
call ids_deallocate(pulse_schedule)
call ids_deallocate(pf_active)
call ids_deallocate(pf_passive)
call ids_deallocate(equilibrium)
call ids_deallocate(magnetics)
write(*,*) 'IDS deallocated'
flush(6)

write(*,*) 'DINA_IMAS Exiting cleanly'

end program DINA_IMAS_test
