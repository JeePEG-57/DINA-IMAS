! hybctrl_c_interface_mod.f90: module for interfacing C-generated code to TCV controller module tcv_controller.f90  
module hybctrl_c_interface_mod
    use iso_c_binding
    use hybctrl_types_mod
    implicit none

    interface
        subroutine hybctrl_step_IDS(t, magnetics, pf_active, Arefs, cpar, cstate, cout ) &
                   bind(C, name="hybctrl_step_IDS")
        
            use iso_c_binding
            use hybctrl_types_mod
            implicit none

            real(c_double), value               :: t
            type(magn_type),   intent(in)       :: magnetics
            type(pfa_type),    intent(in)       :: pf_active
            real(c_double),    intent(in)       :: Arefs(24)
            type(cpar_type),   intent(in)       :: cpar
            type(cstate_type), intent(inout)    :: cstate
            real(c_double),    intent(out)      :: cout(19)  ! hardcoded size 19. Should match size in C code
        end subroutine hybctrl_step_IDS

        subroutine hybctrl_step_IDS_initialize() bind(C)
        end subroutine
        
        subroutine hybctrl_step_IDS_terminate() bind(C)
        end subroutine


    end interface

end module hybctrl_c_interface_mod