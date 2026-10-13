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



    ! ----------------- COPY BIN FILES ---------------
    call copy_bin_files(uri_in)


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
        time_get = time_get + time_increment ! advance 
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



    contains
    subroutine copy_bin_files(uri_read)
        character(len=255) :: src, dst
        character(len=255), dimension(:), allocatable :: filePathsBin
        integer :: i, nFiles=3
        integer :: pos, pos2, start
        character(len=255) :: pathval
        character(len=255), intent(in) :: uri_read

        ! Extract the path component after "path=" in uri_read
        print *, 'Extracting path from uri_read: ', uri_read
        pos = index(uri_read, 'path=')
        if (pos > 0) then
            start = pos + 5  ! right after "path="
            pos2 = index(uri_read(start:), '&') ! & --> end of string
            if (pos2 > 0) then
                pathval = adjustl(uri_read(start:start+pos2-2))
            else
                pathval = adjustl(trim(uri_read(start:)))
            end if
            ! strip surrounding quotes if present
            if (len_trim(pathval) >= 2) then
                if ((pathval(1:1) == '"' .and. pathval(len_trim(pathval):len_trim(pathval)) == '"') .or. &
                    (pathval(1:1) == "'" .and. pathval(len_trim(pathval):len_trim(pathval)) == "'")) then
                    pathval = pathval(2:len_trim(pathval)-1)
                else
                    pathval = pathval(:len_trim(pathval))
                end if
            else
                pathval = pathval(:len_trim(pathval))
            end if
        else
            pathval = ''
        end if

        ! Use extracted path as source directory
        if (len_trim(pathval) > 0) then
            src = trim(pathval)
            print *, 'Extracted path from uri_read:', src
        else
            print *, 'No path= found in uri_read; src left empty'
            src = ''
        end if

        ! Define the list of BIN files to copy (this should be set according to your needs)
        allocate(filePathsBin(nFiles))
        filePathsBin(1) = trim(src)//'/cpar.bin'
        filePathsBin(2) = trim(src)//'/Arefs.bin'
        filePathsBin(3) = trim(src)//'/ffs.bin'

        do i = 1, nFiles
            ! Check file exists; if not, skip this iteration
            open(unit=100, file=trim(filePathsBin(i)), status='old', action='read', iostat=pos2)
            if (pos2 /= 0) then
                print *,'File does not exist, skipping: ', trim(filePathsBin(i))
                pos2 = 0
                cycle
            else
                close(100, iostat=pos2)
                pos2 = 0
            end if
            src = trim(filePathsBin(i))
            dst = './'
            ! Copy file using system 'cp' command and check exit status (POSIX)
            call execute_command_line('cp "'//trim(src)//'" "'//trim(dst)//'"', wait=.true., exitstat=pos2)
            if (pos2 == 0) then
                print *, 'Copied BIN file:', src
            else
                print *, 'Failed to copy BIN file:', src, ' exit status=', pos2
            end if
        end do
    end subroutine copy_bin_files
end program TCV_controller_test