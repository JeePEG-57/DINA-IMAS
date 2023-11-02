! main test
! test the DINA_IMAS
! Jo Lister, August 2013

program DINA_Workflow

use ids_schemas
use ids_routines

use f90_file_reader, only: file2buffer
use xml2eg_mdl, only: xml2eg_parse_memory, xml2eg_get, type_xml2eg_document, xml2eg_free_doc

implicit none



interface
  subroutine dina_green(&
  & pf_active0, pf_passive0, magnetics0,&
  & em_coupling, equilibrium)

    use ids_schemas
    use ids_routines


    type (ids_pf_active), INTENT(IN)   :: pf_active0
    type (ids_pf_passive), INTENT(IN)  :: pf_passive0
    type (ids_magnetics), INTENT(IN)   :: magnetics0
    type (ids_em_coupling), INTENT(OUT) :: em_coupling
    type (ids_equilibrium), INTENT(OUT) :: equilibrium

  end subroutine


  subroutine dina_imas(&
    &  em_coupling0, equilibrium0, magnetics0, pf_active0, pf_passive0, wall0, core_profiles0, core_sources0 &
    & ,bndcond_in &
    & ,pulse_schedule &
    & ,equilibrium, magnetics, pf_active, pf_passive, core_profiles, core_sources, core_transport &
    & ,summary &
    & ,arr_in1, arr_out1 )
    
    use ids_schemas
    use ids_routines


    type (ids_em_coupling), INTENT(IN)  :: em_coupling0
    type (ids_equilibrium), INTENT(IN) :: equilibrium0
    type (ids_magnetics), INTENT(IN)   :: magnetics0
    type (ids_pf_active), INTENT(IN)   :: pf_active0
    type (ids_pf_passive), INTENT(IN)   :: pf_passive0
    type (ids_wall), INTENT(IN) :: wall0
    type (ids_core_profiles), INTENT(IN)   :: core_profiles0
    type (ids_core_sources), INTENT(IN)   :: core_sources0
    type (ids_transport_solver_numerics), INTENT(IN) :: bndcond_in
    type (ids_pulse_schedule), INTENT(IN)   :: pulse_schedule


    type (ids_equilibrium), INTENT(OUT) :: equilibrium
    type (ids_magnetics), INTENT(OUT)   :: magnetics
    type (ids_pf_active), INTENT(OUT)   :: pf_active
    type (ids_pf_passive), INTENT(OUT)   :: pf_passive
    type (ids_core_profiles), INTENT(OUT)   :: core_profiles
    type (ids_core_transport), INTENT(OUT)   :: core_transport
    type (ids_core_sources), INTENT(OUT)   :: core_sources
    type (ids_summary), INTENT(OUT) :: summary


    real (ids_real), INTENT(IN) :: arr_in1(*)
    real (ids_real), INTENT(OUT) :: arr_out1(*)

  end subroutine
    


  subroutine dina_contr(pulse_schedule, pulse_schedule_term, equilibrium0, pf_active0, pf_active, arr_in1, arr_out1)
  use ids_schemas
    type (ids_pulse_schedule), intent(IN) :: pulse_schedule, pulse_schedule_term
    type (ids_pf_active), intent(IN) :: pf_active0
    type (ids_pf_active), intent(OUT) :: pf_active
    type (ids_equilibrium), intent(IN) :: equilibrium0
    
    real (ids_real), intent(IN) :: arr_in1(*)
    real (ids_real), intent(OUT) :: arr_out1(*)
  end subroutine
end interface


type (ids_em_coupling) :: em_coupling
type (ids_equilibrium) :: equilibrium0, equilibrium_green, equilibrium
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

character (len=255) :: user_out='', database_out
integer :: pulse_out=-1, run_out=-1

character (len=255) :: user_pfa='', database_pfa
integer :: pulse_pfa=-1, run_pfa=-1

character (len=255) :: user_pfp='', database_pfp
integer :: pulse_pfp=-1, run_pfp=-1

character (len=255) :: user_mag='', database_mag
integer :: pulse_mag=-1, run_mag=-1

character (len=255) :: user_wll='', database_wll
integer :: pulse_wll=-1, run_wll=-1

character (len=255) :: user_prs='', database_prs
integer :: pulse_prs=-1, run_prs=-1

character (len=255) :: user_psch='', database_psch
integer :: pulse_psch=-1, run_psch=-1

character (len=255) :: user_transp='', database_transp=''
integer :: pulse_transp=-1, run_transp=-1

! Workflow parameters
real (ids_real) :: time_start=0.0, time_stop=10000.0
integer :: idec, imax
integer :: ext_transp, restart=0

! Local variables
integer :: i, iloop
integer :: idx_a, idx_p, idx_m, idx, idx0, err
!integer :: nact,npass,ngrid
integer :: interp_start = 1, interp_transp = 1
real (ids_real) ::time_get,time_ext, current_pf_stop

character(len=30) :: ConfigFile
type(type_xml2eg_document) :: doc
character(len=132), pointer :: buffer(:) => NULL()
integer :: io_unit = 1
logical :: errorflag

! For timing tests
INTEGER :: clock_start,clock_end,clock_rate


call getenv("USER", user_default)


ext_transp=0

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

  call xml2eg_get(doc, 'pulse_schedule/user', user_psch)
  call xml2eg_get(doc, 'pulse_schedule/database', database_psch)
  call xml2eg_get(doc, 'pulse_schedule/pulse', pulse_psch)
  call xml2eg_get(doc, 'pulse_schedule/run', run_psch)
  
  call xml2eg_get(doc, 'input_pf_active/user', user_pfa)
  call xml2eg_get(doc, 'input_pf_active/database', database_pfa)
  call xml2eg_get(doc, 'input_pf_active/pulse', pulse_pfa)
  call xml2eg_get(doc, 'input_pf_active/run', run_pfa)

  call xml2eg_get(doc, 'input_pf_passive/user', user_pfp)
  call xml2eg_get(doc, 'input_pf_passive/database', database_pfp)
  call xml2eg_get(doc, 'input_pf_passive/pulse', pulse_pfp)
  call xml2eg_get(doc, 'input_pf_passive/run', run_pfp)

  call xml2eg_get(doc, 'input_magnetics/user', user_mag)
  call xml2eg_get(doc, 'input_magnetics/database', database_mag)
  call xml2eg_get(doc, 'input_magnetics/pulse', pulse_mag)
  call xml2eg_get(doc, 'input_magnetics/run', run_mag)

  call xml2eg_get(doc, 'input_wall/user', user_wll)
  call xml2eg_get(doc, 'input_wall/database', database_wll)
  call xml2eg_get(doc, 'input_wall/pulse', pulse_wll)
  call xml2eg_get(doc, 'input_wall/run', run_wll)

  call xml2eg_get(doc, 'input_start/user', user_prs)
  call xml2eg_get(doc, 'input_start/database', database_prs)
  call xml2eg_get(doc, 'input_start/pulse', pulse_prs)
  call xml2eg_get(doc, 'input_start/run', run_prs)
  call xml2eg_get(doc, 'input_start/time_start', time_start)
  call xml2eg_get(doc, 'input_start/interp_mode', interp_start)

  call xml2eg_get(doc, 'output/user', user_out)
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
deallocate(buffer)


if (trim(user_pfa).eq.'') user_pfa = user_default
if (trim(user_pfp).eq.'') user_pfp = user_default
if (trim(user_mag).eq.'') user_mag = user_default
if (trim(user_wll).eq.'') user_wll = user_default
if (trim(user_prs).eq.'') user_prs = user_default
if (trim(user_psch).eq.'') user_psch = user_default
if (trim(user_transp).eq.'') user_transp = user_default
if (trim(user_out).eq.'') user_out = user_default


print *,' Pulse schedule user, database, pulse, run =', trim(user_psch), trim(database_psch), pulse_psch, run_psch

print *,' PF Active user, database, pulse, run =', trim(user_pfa), trim(database_pfa), pulse_pfa, run_pfa
print *,' PF Passive user, database, pulse, run =', trim(user_pfp), trim(database_pfp), pulse_pfp, run_pfp
print *,' Magnetics user, database, pulse, run =', trim(user_mag), trim(database_mag), pulse_mag, run_mag
print *,' Wall user, database, pulse, run =', trim(user_wll), trim(database_wll), pulse_wll, run_wll

print *,' Start user, database, pulse, run =', trim(user_prs), trim(database_prs), pulse_prs, run_prs
print *,' Start time, s =', time_start
print *,' Start interpolation =', interp_start

print *,' Transp user, database, pulse, run =', trim(user_transp), trim(database_transp), pulse_transp, run_transp
print *,' Transp interpolation =', interp_transp

print *,' Output user =', trim(user_out), trim(database_out), pulse_out, run_out
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
  
  !call ids_get_slice(idx0,"em_coupling",em_coupling, time_get, interp_start)
  !call ids_get_slice(idx0,"magnetics",magnetics0, time_get, interp_start)
  call ids_get_slice(idx0,"equilibrium",equilibrium0, time_get, interp_start)
  !call ids_get_slice(idx0,"pf_active",pf_active0, time_get, interp_start)
  !call ids_get_slice(idx0,"pf_passive",pf_passive0, time_get, interp_start)
  call ids_get_slice(idx0,"core_profiles",core_profiles0, time_get, interp_start)
  call ids_get_slice(idx0,"core_sources",core_sources0, time_get, interp_start)
  call ids_get_slice(idx0,"transport_solver_numerics",bndcond, time_get, interp_start)

  write(*,*) 'Finished reading the prescribed IDS'
  call imas_close(idx0)

  write(*,*) 'Restart from plasma current, A = ', core_profiles0%global_quantities%ip

else

  write(*,*) 'Start from t=0'


  !call ids_get(idx0,"em_coupling",em_coupling)
  !call ids_get(idx0,"equilibrium",equilibrium0)


  !call ids_get(idx0,"core_profiles",core_profiles0)
  !call ids_get(idx0,"core_sources",core_sources0)
  !call ids_get(idx0,"transport_solver_numerics",bndcond)

  
endif


call imas_open_env('ids',pulse_pfa,run_pfa,idx_a,user_pfa,database_pfa,'3')
call ids_get_slice(idx_a,"pf_active",pf_active0, time_start, interp_start)
call imas_close(idx_a)

call imas_open_env('ids',pulse_pfp,run_pfp,idx_p,user_pfp,database_pfp,'3')
call ids_get_slice(idx_p,"pf_passive",pf_passive0, time_start, interp_start)
call imas_close(idx_p)

call imas_open_env('ids',pulse_mag,run_mag,idx_m,user_mag,database_mag,'3')
call ids_get_slice(idx_m,"magnetics",magnetics0, time_start, interp_start)
call imas_close(idx_m)

call imas_open_env('ids',pulse_wll,run_wll,idx0,user_wll,database_wll,'3')
call ids_get_slice(idx0,"wall",wall, time_start, interp_start)
call imas_close(idx0)




call dina_green(pf_active0, pf_passive0, magnetics0, em_coupling, equilibrium_green)

if (.NOT.associated(equilibrium0%time_slice)) then
  equilibrium0 = equilibrium_green
endif



write(*,*) 'Reading the pulse schedule'
call imas_open_env('ids',pulse_psch,run_psch,idx0,user_psch,database_psch,'3')

call ids_get(idx0,"pulse_schedule",pulse_schedule)
call ids_get(idx0,"pulse_schedule/1",pulse_schedule_term)

call imas_close(idx0)

!print *,'Press any key to begin simulation...'
!read (*,*)



arr_in1(1:31)=1
arr_out1(1:31)=0



  call imas_create_env('ids',pulse_out,run_out,1,1,idx,user_out,database_out,'3')
  write(*,*) 'Pulse file is created'

  call ids_put(idx,"wall",wall)
  call ids_put(idx,"em_coupling",em_coupling)
  !call ids_put(idx,"dataset_description",data_description)
  call ids_put(idx,"pulse_schedule",pulse_schedule)
  call ids_put(idx,"pulse_schedule/1",pulse_schedule_term)




do iloop=1,imax

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

  call ids_put_slice(idx,"pf_active",pf_active)
  call ids_put_slice(idx,"summary",summary)

  if (mod(iloop,idec).eq.0 .or. iloop.eq.1) then
  
    write(*,*) 'Put ids slice to database, iloop = ', iloop
    flush(6)
    
    write(*,*)  'Put magnetics'
    call ids_put_slice(idx,"magnetics",magnetics)
    
    write(*,*)  'Put pf_passive'
    call ids_put_slice(idx,"pf_passive",pf_passive)
  
    write(*,*)  'Put equilibrium'
    call ids_put_slice(idx,"equilibrium",equilibrium)
  
    write(*,*)  'Put core_profiles'
    call ids_put_slice(idx,"core_profiles",core_profiles)
  
    write(*,*)  'Put core_sources'
    call ids_put_slice(idx,"core_sources",core_sources)
  
    write(*,*)  'Put core_transport'
    call ids_put_slice(idx,"core_transport",core_transport)
  
    write(*,*)  'Put transport_solver_numerics'
    call ids_put_slice(idx,"transport_solver_numerics",bndcond)
  
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

if (summary%time(1).gt.time_stop .or. (dabs(summary%global_quantities%ip%value(1)).lt.1.d3 .and. current_pf_stop.lt.1.d3)) exit


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


end do

call imas_close(idx)

!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
write(*,*) 'DINA_IMAS loop finished, clean up'

write(*,*) 'Deallocate static IDS'

call ids_deallocate(em_coupling)
call ids_deallocate(wall)
call ids_deallocate(pulse_schedule)
call ids_deallocate(data_description)


write(*,*) 'DINA_IMAS Exiting cleanly'

end program DINA_Workflow
