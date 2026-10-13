module tcv_controller_state_mod
    use iso_c_binding
    use hybctrl_types_mod
    implicit none

    ! Indicate whether constants were loaded already
    logical, save :: is_initialized = .false.

    ! Persistent controller parameters
    type(cpar_type),  save :: cpar ! controller parameters
    type(Arefs_type), save :: Arefs ! References
    type(ffs_type), save    :: ffs ! feedforwards
    ! Controller internal state of hybrid controller
    type(cstate_type), save :: cstate
    ! Persistent coil system parameters
    real *8, allocatable, save  :: V_pfa2coil(:) ! Voltage rescaling for active2coil mapping
    integer, allocatable, save  :: active2coil_map(:,:) ! active2coil mapping matrix
    real *8, allocatable, save  :: PS_voltageLim_upper(:) ! PS Saturation parameters
    real *8, allocatable, save  :: PS_voltageLim_lower(:) ! PS Saturation parameters




    
end module tcv_controller_state_mod