program TCV_controller_test

    use ids_schemas
    use ids_routines
    use f90_file_reader, only: file2buffer
    use xml2eg_mdl, only: xml2eg_parse_memory, xml2eg_get, type_xml2eg_document, xml2eg_free_doc
    use tcv_controller, only: tcv_contr_step
    implicit none

    INTEGER :: status
    INTERFACE
        INTEGER FUNCTION putenv(string) BIND(C, NAME="putenv")
            USE, INTRINSIC :: ISO_C_BINDING
            CHARACTER(KIND=C_CHAR), DIMENSION(*), INTENT(IN) :: string
        END FUNCTION putenv
    END INTERFACE
    ! ----------------- VARIABLES ---------------
    type (ids_magnetics) :: magnetics0
    type (ids_pf_active) :: pf_active, pf_active0
    ! IDS Inputs 
    integer :: ibackend = 13
    integer  :: kpr
    common kpr
    character (len=255) :: user_default
    character (len=255) :: user_in='', database_in
    integer :: pulse_in=-1, run_in=-1
    character (len=255) :: user_out='', database_out
    integer :: pulse_out=-1, run_out=-1
    integer :: interp_start = 1
    ! Input files
    character(len=30) :: ConfigFile, CodeParamsFile
    type(type_xml2eg_document) :: doc
    character(len=132), pointer :: buffer(:) => NULL()
    integer :: io_unit = 1
    ! Integers
    integer :: i, imax = 100
    integer :: idx_in, idx_out
    ! Timing 
    real (ids_real) :: time_start, time_sim, time_get, time_stop, time_increment



    ! ----------------- READ INPUTS ---------------
    if (.not.(command_argument_count().eq.2)) then
        print *,'Two arguments must be provided. First argument must be the name of a workflow config XML file, second argument is a code parameters XML file.'
        stop
    endif
    call get_command_argument(1, ConfigFile)
    call get_command_argument(2, CodeParamsFile)
    print *,' Using workflow config file: ', ConfigFile
    
    ! ----------------- INITIALISATION ---------------
    call getenv("USER", user_default)
    ! Open XML config file 
    call file2buffer(ConfigFile, io_unit, buffer)
    call xml2eg_parse_memory(buffer, doc)
    ! Read input DB location
    call xml2eg_get(doc, 'input_scenario/user', user_in)
    call xml2eg_get(doc, 'input_scenario/database', database_in)
    call xml2eg_get(doc, 'input_scenario/pulse', pulse_in)
    call xml2eg_get(doc, 'input_scenario/run', run_in)
    ! Read output DB location
    call xml2eg_get(doc, 'output/user', user_out)
    call xml2eg_get(doc, 'output/database', database_out)
    call xml2eg_get(doc, 'output/pulse', pulse_out)
    call xml2eg_get(doc, 'output/run', run_out)
    ! Read simulation start time 
    call xml2eg_get(doc, 'time_start', time_start)
    call xml2eg_get(doc, 'time_sim', time_sim)
    call xml2eg_get(doc, 'time_increment', time_increment)
    ! Read debugging verbosity
    call xml2eg_get(doc, 'kpr', kpr)
    ! Close XML config file
    call xml2eg_free_doc(doc)
    deallocate(buffer)
    ! Set simulation times 
    time_stop = time_start + time_sim
    time_get = time_start    
    print *, 'Simulation start, end and increment in [s]: ', time_start, time_stop, time_increment
    ! Set IDS DB variables 
    if (trim(user_in).eq.'') user_in = user_default
    if (trim(user_out).eq.'') user_out = user_default
    print *,' Input:  user, database, pulse, run =', trim(user_in), trim(database_in), pulse_in, run_in
    print *,' Output: user, database, pulse, run =', trim(user_out), trim(database_out), pulse_out, run_out
    ! Set IMAS backend to HDF5
    status = putenv("IMAS_AL_DEFAULT_BACKEND=13"//C_NULL_CHAR) ! 13 for HDF5 backend



    ! ----------------- PREPARE OUTPUT DB ---------------
    call imas_create_env('ids',pulse_out,run_out,1,1,idx_out,user_out,database_out,'3')
    print *, 'Output database is created'



    ! ----------------- OPEN INPUT DB ---------------
    ! Open DB
    call imas_open_env('ids',pulse_in,run_in,idx_in,user_in,database_in,'3')



    ! ----------------- DO SIMULATION ---------------
    print *, 'Start TCV controller test'
    do i = 1,imax
        if (time_get.gt.time_stop) exit
        print *, 'i, time_get, ', i, time_get
        ! Get data 
        call ids_get_slice(idx_in,"magnetics",magnetics0, time_get, interp_start)
        call ids_get_slice(idx_in,"pf_active",pf_active0, time_get, interp_start)
        ! Step controller  
        call  tcv_contr_step(magnetics0, pf_active0, &
                           &  pf_active)
        ! Store output
        print *,  'Put pf_active'
        call ids_put_slice(idx_out,"pf_active",pf_active)
        call ids_put_slice(idx_out,"pf_active/1",pf_active0)
        call ids_put_slice(idx_out,"magnetics/1",magnetics0)
        ! Update time 
        time_get = time_get + time_increment ! advance by 1 ms
        ! Deallocate previous IDSs
        call ids_deallocate(magnetics0)
        call ids_deallocate(pf_active0)
        call ids_deallocate(pf_active)
    enddo 



    ! ----------------- EXIT CLEANLY ---------------
    call imas_close(idx_in)	
    call imas_close(idx_out)
        
    print *, 'IDS deallocated'
    print *, 'Test TCV controller file exiting cleanly'
end program TCV_controller_test