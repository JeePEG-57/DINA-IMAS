module tcv_controller
    use ids_schemas
    use ids_routines
    use iso_c_binding
    use hybctrl_types_mod
    use hybctrl_c_interface_mod
    use tcv_controller_state_mod ! persistent controller state, parameters and variables stored in this module

    implicit none

contains

    subroutine tcv_contr_step(magnetics0, pf_active0, &
                           &  pf_active)
    ! Documentation goes here: 


        implicit none
        !----------------- INPUTS/OUTPUTS -----------------
        type (ids_magnetics), intent(IN) :: magnetics0
        type (ids_pf_active), intent(IN) :: pf_active0
        type (ids_pf_active), intent(OUT) :: pf_active
        
        
        !----------------- VARIABLES -----------------
        ! Controller inputs
        real(c_double)          :: t
        type(magn_type)         :: magn
        type(pfa_type)          :: pfa
        real(c_double)          :: Arefs_step(24) ! hardcoded size 24. Should match size in C code
        real(c_double)          :: cout(19)  ! hardcoded size 19. Should match size in C code
        real(c_double)          :: ffs_step(19) ! hardcoded size 19. Should match cout size
        

        ! Local variables
        integer :: i, j, npfa, ncoils, nBm, nFf, kpr
        common kpr !verbositiy for debugging
        real *8, allocatable        :: VCOIL(:) ! Voltage to put in the coils


        !----------------- INITIALISATION OF VARIABLES -----------------
        if (kpr.eq.1) print *, 'Entering TCV controller'
        npfa = size(pf_active0%circuit) ! #circuits
        ncoils = size(pf_active0%coil) ! #coils
        nBm = size(magnetics0%b_field_pol_probe) ! #magnetic probes
        nFf = size(magnetics0%flux_loop) ! #flux loops
        ! Initialize output voltage
        if (.not.allocated(VCOIL)) allocate(VCOIL(ncoils)); 
        do i=1,ncoils
            VCOIL(i) = 0.0d0
        enddo
        ! current time 
        if (magnetics0%ids_properties%homogeneous_time == 1) then
            t = magnetics0%time(1)
        elseif (magnetics0%ids_properties%homogeneous_time == 0) then 
            t = magnetics0%flux_loop(1)%flux%time(1)
        endif
        ! pfa 
        pfa%time = t
        do i=1,ncoils
            pfa%Ia(i) = pf_active0%coil(i)%current%data(1) ! In [A]
            pfa%names(i)%f1 = [ ( pf_active0%coil(i)%name(1)(j:j), j=1,5 ) ]
        enddo
        !magn 
        magn%time = t
        do i = 1,nBm
            magn%Bm(i) = magnetics0%b_field_pol_probe(i)%field%data(1) ! In [T]
        enddo
        do i = 1,nFf
            magn%Ff(i) = magnetics0%flux_loop(i)%flux%data(1) ! In [Wb]
        enddo
        ! For debugging
        if (kpr.eq.1) then 
            print *, 'Current time t: ', pfa%time
            print *, 'Current coil currents ICoil: ', pfa%Ia(1:ncoils)
            do j = 1,ncoils
                print *, 'Current coil names: ', pfa%names(j)%f1(:)
            enddo
            print *, 'Current time t: ', magn%time
            print *, 'Poloidal probes: ', magn%Bm(1:nBm)
            print *, 'Flux loops: ', magn%Ff(1:nFf)
        endif

        !----------------- INITIALISATION AT FIRST CALL OF CONTROLLER -----------------
        if (.not.is_initialized) then
            print *, 'First call to tcv_contr_step: initializing'
            ! Active circuits 2 coil mapping
            allocate(active2coil_map(ncoils,npfa))
            call get_active2coil_mapping(active2coil_map)
            ! Voltage mapping coeffs
            allocate(V_pfa2coil(npfa))
            V_pfa2coil(:) = sum(active2coil_map, dim=1)
            V_pfa2coil = 1.0d0 / V_pfa2coil(:)  ! Invert to get mapping coefficients
            !cpar 
            call load_cpar(cpar)
            print *, 'cpar loaded'
            !Arefs
            call load_Arefs(Arefs)
            print *, 'Arefs loaded'
            print *, 'Size of Arefs(i1, i2): ', size(Arefs%data,1), size(Arefs%data,2)
            call data_interpolate(Arefs%data, Arefs%time, t, Arefs_step)
            !ffs
            call load_ffs(ffs)
            print *, 'ffs loaded'
            print *, 'Size of Ffs(i1, i2): ', size(ffs%data,1), size(ffs%data,2)
            call data_interpolate(ffs%data, ffs%time, t, ffs_step)
            ! cstate
            cstate%hyb(:) = 0.0d0
            print *, 'cstate initialized to zero'
            ! PS saturation limits
            allocate(PS_voltageLim_upper(npfa))
            allocate(PS_voltageLim_lower(npfa))
            call get_saturation_limits(PS_voltageLim_upper,PS_voltageLim_lower)
            print *, 'PS saturation limits loaded'
            ! Change state of initialization
            is_initialized = .true.
            print *, 'Initialization complete.'
            if (kpr.eq.1) then 
                print *, '---------- Active to Coil mapping matrix:----------'
                do i = 1,ncoils 
                    print *, (active2coil_map(i,j), j = 1,npfa)
                enddo
                print *, '---------- Voltage coefficients -----------------'
                print *, V_pfa2coil(:)
                print *, '---------- Voltage limits -----------------'
                print *, 'Upper limits: ', PS_voltageLim_upper(:)
                print *, 'Lower limits: ', PS_voltageLim_lower(:)
            endif
            

        else 
            call data_interpolate(Arefs%data, Arefs%time, t, Arefs_step)
            call data_interpolate(ffs%data, ffs%time, t, ffs_step)
        endif
       


        !----------------- CALL CONTROLLER STEPPER -----------------
        call hybctrl_step_IDS(t, magn, pfa, Arefs_step, cpar, cstate, cout)

        !----------------- PROCESS CONTROLLER STEPPER OUTPUT  -----------------
        j = 0
        do i = 1,ncoils
            j = findloc(active2coil_map(i,:), 1, dim=1)
            VCOIL(i) = V_pfa2coil(j) * ( cout(j) + ffs_step(j) )
        enddo


        !----------------- CALL POWER SUPPLY STEPPER  -----------------
        ! TO DO:


        !----------------- PROCESS POWER SUPPLY STEPPER OUTPUT  -----------------
        ! TO DO: 



        !----------------- SET PS SATURATION LIMITS  -----------------
        do i = 1,ncoils
            j = findloc(active2coil_map(i,:), 1, dim=1)
            ! set upper limit
            if (VCOIL(i) > PS_voltageLim_upper(j)*V_pfa2coil(j)) then
                VCOIL(i) = PS_voltageLim_upper(j)*V_pfa2coil(j)
                ! print *, 'Warning: VCOIL(', i, ') exceeded voltage upper limit and was clamped.'
            ! set lower limit
            else if (VCOIL(i) < PS_voltageLim_lower(j)*V_pfa2coil(j)) then
                VCOIL(i) = PS_voltageLim_lower(j)*V_pfa2coil(j)
                ! print *, 'Warning: VCOIL(', i, ') exceeded voltage lower limit and was clamped.'
            end if
        enddo
        
        !----------------- DEAL WITH NaNs  -----------------
        do i = 1,ncoils
            if (.not.(VCOIL(i) == VCOIL(i))) then ! check for NaN
                VCOIL(i) = 0.0d0
                print *, 'Warning: VCOIL(', i, ') is NaN. Setting to zero.'
            end if
        enddo


        !----------------- SET OUTPUT IDS -----------------
        call ids_copy(pf_active0, pf_active)
        do i=1,ncoils
            if (.NOT.associated(pf_active%coil(i)%voltage%data)) allocate(pf_active%coil(i)%voltage%data(1))
            if (.NOT.associated(pf_active%coil(i)%voltage%time)) allocate(pf_active%coil(i)%voltage%time(1))
            pf_active%coil(i)%voltage%data(1) = VCOIL(i)  
            pf_active%coil(i)%voltage%time(1) = t
            if (kpr.eq.1) print *, 'VCOIL i=', i, ' is: ', pf_active%coil(i)%voltage%data(1)
        enddo


        print*, 'Exiting TCV controller step'
    end subroutine tcv_contr_step






    subroutine get_active2coil_mapping(mapping_matrix)
        ! Mapping of controller stepper voltage output cout, to coil voltages. 
        ! cout order is: E(8), F(8), OH1(1), OH2(1), G(1)
        ! coil order is: A(1), B(2), C(2), D(2), E(8), F(8), G(6)
        implicit none 
        integer, allocatable, intent(out) :: mapping_matrix(:,:)

        allocate(mapping_matrix(29,19))
        mapping_matrix = transpose(reshape(  &
                      (/& ! E1 E2 E3 E4 E5 E6 E7 E8 F1 F2 F3 F4 F5 F6 F7 F8 O1 O2 G 
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, & !A1 - OH1
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, & !B1 - OH2   
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, & !B2 - OH2
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, & !C1 - OH2
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, & !C2 - OH2
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, & !D1 - OH2
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, & !D2 - OH2
                            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, & !E1 - E1
                            0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, & !E2 - E2
                            0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, & !E3 - E3
                            0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, & !E4 - E4
                            0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, & !E5 - E5
                            0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, & !E6 - E6
                            0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, & !E7 - E7
                            0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, & !E8 - E8
                            0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, & !F1 - F1
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, & !F2 - F2
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, & !F3 - F3
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, & !F4 - F4
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, & !F5 - F5
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, & !F6 - F6
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, & !F7 - F7
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, & !F8 - F8
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, & !G1 - G
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, & !G2 - G
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, & !G3 - G
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, & !G4 - G
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, & !G5 - G
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1  & !G6 - G
                            /), (/ size(mapping_matrix,2),  size(mapping_matrix,1) /) ) )
    end subroutine get_active2coil_mapping

    subroutine get_saturation_limits(PS_voltageLim_upper_out,PS_voltageLim_lower_out)
        ! Create saturation limits for the power supplies. For now, these are hardcoded, but they could be read from
        ! a file or from the IDs in the future. Taken from SPCwiki>JSI_table. Voltage limits are assymetrical:
        ! Upper limits are nominal. Lower limits are limited to ~cos150° ~ -0.866*Unom  due to how the rectifier works.
        ! Output size is npfa (number of active circuits). Should then be mapped to coil (ncoil) saturation limits
        ! using the active2coil mapping.
        implicit none
        real *8, allocatable, intent(out) :: PS_voltageLim_upper_out(:)
        real *8, allocatable, intent(out) :: PS_voltageLim_lower_out(:)
        real *8  E_upper, F_upper, OH_upper, G_upper
        real *8  E_lower, F_lower, OH_lower, G_lower
        integer :: i
        allocate(PS_voltageLim_upper_out(19)) ! hardcoded size 19. Should match npfa
        allocate(PS_voltageLim_lower_out(19)) ! hardcoded size 19. Should match npfa
        ! Upper limits in [V]
        ! Order is: E, F, OH, G circuits
        E_upper = 648.0;    E_lower = -0.866*E_upper;
        F_upper = 1250.0;    F_lower = -0.866*F_upper;
        OH_upper = 1400.0;   OH_lower = -0.866*OH_upper;
        ! No know limits for G circuit. SPCwiki>FPS>documents show ~+-566V. --> Set to 550V. 
        G_upper = 550.0;     G_lower = -550.0;
        PS_voltageLim_upper_out(:) = [ (E_upper, i=1,8), (F_upper, i=1,8), (OH_upper, i=1,2), (G_upper, i=1,1) ]
        PS_voltageLim_lower_out(:) = [ (E_lower, i=1,8), (F_lower, i=1,8), (OH_lower, i=1,2), (G_lower, i=1,1) ]

    end subroutine get_saturation_limits

    subroutine load_Arefs(Arefs_out)
        use iso_c_binding
        use hybctrl_types_mod
        implicit none

        type(Arefs_type), intent(out) :: Arefs_out
        integer(c_int) :: Nt, Nref
        integer :: iunit

        open(newunit=iunit, file="Arefs.bin", access="stream", form="unformatted", status="old")
        ! Read Nt, Nref
        read(iunit) Nt
        read(iunit) Nref

        Arefs_out%Nt = Nt
        Arefs_out%Nref = Nref

        allocate(Arefs_out%time(Nt))
        allocate(Arefs_out%data(Nref,Nt))

        ! Read arrays
        read(iunit) Arefs_out%time
        read(iunit) Arefs_out%data

        close(iunit)
    end subroutine load_Arefs

    subroutine load_cpar(cpar_out)
        use iso_c_binding
        use hybctrl_types_mod
        implicit none

        type(cpar_type), intent(out) :: cpar_out
        integer :: iunit

        open(newunit=iunit, file="cpar.bin", access="stream", form="unformatted", status="old")

        ! === Amat ===
        read(iunit) cpar_out%Amat%data
        read(iunit) cpar_out%Amat%dimin
        read(iunit) cpar_out%Amat%dimout
        read(iunit) cpar_out%Amat%lhyb

        ! === Mmat ===
        read(iunit) cpar_out%Mmat%data
        read(iunit) cpar_out%Mmat%dimin
        read(iunit) cpar_out%Mmat%dimout
        read(iunit) cpar_out%Mmat%lhyb

        ! === Gmat ===
        read(iunit) cpar_out%Gmat%addr%time
        read(iunit) cpar_out%Gmat%addr%data
        read(iunit) cpar_out%Gmat%G1I
        read(iunit) cpar_out%Gmat%G2P
        read(iunit) cpar_out%Gmat%G3D
        read(iunit) cpar_out%Gmat%dimin
        read(iunit) cpar_out%Gmat%dimout

        ! logicals (stored as uint8 in file, but Fortran will reinterpret OK)
        read(iunit) cpar_out%iEin
        read(iunit) cpar_out%iFin
        read(iunit) cpar_out%iOHin
        read(iunit) cpar_out%iGOin

        ! === ssPIDd ===
        read(iunit) cpar_out%ssPIDd%a
        read(iunit) cpar_out%ssPIDd%b
        read(iunit) cpar_out%ssPIDd%c
        read(iunit) cpar_out%ssPIDd%d

        close(iunit)
    end subroutine load_cpar

    subroutine load_ffs(ffs_out)
        use iso_c_binding
        use hybctrl_types_mod
        implicit none

        type(ffs_type), intent(out) :: ffs_out
        integer(c_int) :: Nt, Nffs
        integer :: iunit

        open(newunit=iunit, file="ffs.bin", access="stream", form="unformatted", status="old")

        ! Read ffs data
        read(iunit) Nt
        read(iunit) Nffs

        ffs_out%Nt = Nt
        ffs_out%Nffs = Nffs

        allocate(ffs_out%time(Nt))
        allocate(ffs_out%data(Nffs,Nt))

        ! Read arrays
        read(iunit) ffs_out%time
        read(iunit) ffs_out%data

        close(iunit)
    end subroutine load_ffs

    subroutine data_interpolate(data_in, time_in, t, data_out)
        ! Interpolates data_in (size: nchan x Nt) at time t, given time_in (size Nt)
        ! Linear interpolation is used. Extrapolation is constant (hold last value).
        ! Output is size (nchan x 1)
        
        use iso_c_binding
        use hybctrl_types_mod
        implicit none

        real(c_double), intent(in)   :: data_in(:,:)
        real(c_double), intent(in)   :: time_in(:)
        real(c_double), intent(in)   :: t
        real(c_double), intent(out)  :: data_out(size(data_in,1)) 

        integer :: i, idx, Nt
        real(c_double) :: t1, t2, w

        Nt = size(time_in)
        ! Sanity check
        if (size(data_in,2) /= Nt) then
            print *, "Error: data_in and time_in size mismatch"
            stop
        end if

        ! t below time(1) 
        if (t <= time_in(1)) then
            data_out = data_in(:,1)
            return
        end if
        
        ! t above time(end) 
        if (t >= time_in(Nt)) then
            data_out = data_in(:,Nt)
            return
        end if

        ! t between time(1) and time(end)
        ! find interval time(i) <= t < time(i+1)
        do i=1, Nt-1
            if (t >= time_in(i) .and. t < time_in(i+1)) then
                idx = i
                exit
            end if
        end do

        ! compute linear weight
        t1 = time_in(idx)
        t2 = time_in(idx+1)
        w = (t - t1) / (t2 - t1)

        ! linear interpolation for each data channel
        data_out = (1.0d0-w)*data_in(:,idx) + w*data_in(:,idx+1)
    end subroutine data_interpolate

end module tcv_controller
