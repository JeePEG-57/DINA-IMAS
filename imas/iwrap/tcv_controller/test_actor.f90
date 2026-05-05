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
    ! IDS inputs - outputs
    character (len=255) :: uri_in, uri_out
    integer :: interp_start = 1
    integer :: error_flag
    integer :: idx_in, idx_out
    character(len=:), pointer :: error_message
    ! Workflow config file
    character(len=30) :: ConfigFile
    type(type_xml2eg_document) :: doc
    character(len=132), pointer :: buffer(:) => NULL()
    integer :: io_unit = 1
    ! Integers
    integer :: i, imax = 100
    
    ! Timing 
    real (ids_real) :: time_start, time_sim, time_get, time_stop, time_increment



    ! ----------------- READ INPUTS ---------------
    if (.not.(command_argument_count().eq.1)) then
        print *,'One argument must be provided. The argument must be the name of a workflow config XML file.'
        stop
    endif
    call get_command_argument(1, ConfigFile)
    print *,' Using workflow config file: ', ConfigFile
    
    ! ----------------- INITIALISATION ---------------
    ! Open XML config file 
    call file2buffer(ConfigFile, io_unit, buffer)
    call xml2eg_parse_memory(buffer, doc)

    ! Read input DB location
    call xml2eg_get(doc, 'input_scenario/uri', uri_in)
    uri_in = trim(uri_in) ! remove trailing spaces
    print *, 'Input DB URI: ', uri_in

    ! Read output DB location
    call xml2eg_get(doc, 'output/uri', uri_out)
    uri_out = trim(uri_out) ! remove trailing spaces
    print *, 'Output DB URI: ', uri_out

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




    ! ----------------- PREPARE OUTPUT DB ---------------
    call imas_open(uri_out, CREATE_PULSE, idx_out, error_flag)
    print *, 'Output database is created'
    
    ! ----------------- OPEN INPUT DB ---------------
    ! Open DB
    call imas_open(uri_in, OPEN_PULSE, idx_in, error_flag)
    if (error_flag.eq.0) then
        print *, 'Input database is created'
    else
        print *, 'Error creating input database: ', error_message
        stop
    end if


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
        print *,  'Put pf_active/1'
        call ids_put_slice(idx_out,"pf_active/1",pf_active0)
        print *,  'Put magnetics/1'
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