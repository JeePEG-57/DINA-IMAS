module hybctrl_types_mod
    use iso_c_binding
    implicit none

!=======================================================================
!  LOW-LEVEL CHAR TYPES FOR EXACT C LAYOUT
!=======================================================================

    ! Wraps char[5]
    type, bind(C) :: cell_wrap_0_type
        character(kind=c_char) :: f1(5)
    end type cell_wrap_0_type

    !===================================================================
    ! HUGE MATLAB-CODER GENERATED CELL_1 (117 different string fields)
    !===================================================================
    type, bind(C) :: cell_1_type
        character(c_char) :: f1(6)
        character(c_char) :: f2(7)
        character(c_char) :: f3(7)
        character(c_char) :: f4(7)
        character(c_char) :: f5(7)
        character(c_char) :: f6(7)
        character(c_char) :: f7(7)
        character(c_char) :: f8(7)
        character(c_char) :: f9(7)
        character(c_char) :: f10(7)
        character(c_char) :: f11(7)
        character(c_char) :: f12(7)
        character(c_char) :: f13(7)
        character(c_char) :: f14(7)
        character(c_char) :: f15(7)
        character(c_char) :: f16(7)
        character(c_char) :: f17(7)
        character(c_char) :: f18(7)
        character(c_char) :: f19(7)
        character(c_char) :: f20(7)
        character(c_char) :: f21(7)
        character(c_char) :: f22(7)
        character(c_char) :: f23(7)
        character(c_char) :: f24(7)
        character(c_char) :: f25(7)
        character(c_char) :: f26(7)
        character(c_char) :: f27(7)
        character(c_char) :: f28(7)
        character(c_char) :: f29(7)
        character(c_char) :: f30(7)
        character(c_char) :: f31(7)
        character(c_char) :: f32(7)
        character(c_char) :: f33(7)
        character(c_char) :: f34(7)
        character(c_char) :: f35(7)
        character(c_char) :: f36(7)
        character(c_char) :: f37(7)
        character(c_char) :: f38(7)
        character(c_char) :: f39(6)
        character(c_char) :: f40(6)
        character(c_char) :: f41(6)
        character(c_char) :: f42(6)
        character(c_char) :: f43(6)
        character(c_char) :: f44(6)
        character(c_char) :: f45(6)
        character(c_char) :: f46(6)
        character(c_char) :: f47(6)
        character(c_char) :: f48(6)
        character(c_char) :: f49(6)
        character(c_char) :: f50(6)
        character(c_char) :: f51(6)
        character(c_char) :: f52(6)
        character(c_char) :: f53(6)
        character(c_char) :: f54(6)
        character(c_char) :: f55(6)
        character(c_char) :: f56(6)
        character(c_char) :: f57(6)
        character(c_char) :: f58(6)
        character(c_char) :: f59(6)
        character(c_char) :: f60(6)
        character(c_char) :: f61(6)
        character(c_char) :: f62(6)
        character(c_char) :: f63(6)
        character(c_char) :: f64(6)
        character(c_char) :: f65(6)
        character(c_char) :: f66(6)
        character(c_char) :: f67(6)
        character(c_char) :: f68(6)
        character(c_char) :: f69(6)
        character(c_char) :: f70(6)
        character(c_char) :: f71(6)
        character(c_char) :: f72(6)
        character(c_char) :: f73(6)
        character(c_char) :: f74(6)
        character(c_char) :: f75(6)
        character(c_char) :: f76(6)
        character(c_char) :: f77(8)
        character(c_char) :: f78(8)
        character(c_char) :: f79(8)
        character(c_char) :: f80(8)
        character(c_char) :: f81(8)
        character(c_char) :: f82(8)
        character(c_char) :: f83(8)
        character(c_char) :: f84(8)
        character(c_char) :: f85(8)
        character(c_char) :: f86(8)
        character(c_char) :: f87(8)
        character(c_char) :: f88(8)
        character(c_char) :: f89(8)
        character(c_char) :: f90(8)
        character(c_char) :: f91(8)
        character(c_char) :: f92(8)
        character(c_char) :: f93(9)
        character(c_char) :: f94(9)
        character(c_char) :: f95(6)
        character(c_char) :: f96(6)
        character(c_char) :: f97(6)
        character(c_char) :: f98(6)
        character(c_char) :: f99(6)
        character(c_char) :: f100(6)
        character(c_char) :: f101(6)
        character(c_char) :: f102(6)
        character(c_char) :: f103(6)
        character(c_char) :: f104(6)
        character(c_char) :: f105(6)
        character(c_char) :: f106(6)
        character(c_char) :: f107(6)
        character(c_char) :: f108(6)
        character(c_char) :: f109(6)
        character(c_char) :: f110(6)
        character(c_char) :: f111(6)
        character(c_char) :: f112(6)
        character(c_char) :: f113(6)
        character(c_char) :: f114(6)
        character(c_char) :: f115(10)
        character(c_char) :: f116(8)
        character(c_char) :: f117(6)
    end type cell_1_type

    !===================================================================
    ! MATLAB "cell_2" → 26 fields
    !===================================================================
    type, bind(C) :: cell_2_type
        character(c_char) :: f1(5)
        character(c_char) :: f2(7)
        character(c_char) :: f3(5)
        character(c_char) :: f4(7)
        character(c_char) :: f5(7)
        character(c_char) :: f6(7)
        character(c_char) :: f7(7)
        character(c_char) :: f8(7)
        character(c_char) :: f9(7)
        character(c_char) :: f10(7)
        character(c_char) :: f11(7)
        character(c_char) :: f12(7)
        character(c_char) :: f13(7)
        character(c_char) :: f14(7)
        character(c_char) :: f15(7)
        character(c_char) :: f16(7)
        character(c_char) :: f17(14)
        character(c_char) :: f18(13)
        character(c_char) :: f19(8)
        character(c_char) :: f20(10)
        character(c_char) :: f21(10)
        character(c_char) :: f22(6)
        character(c_char) :: f23(6)
        character(c_char) :: f24(6)
        character(c_char) :: f25(7)
        character(c_char) :: f26(7)
    end type cell_2_type

    !===================================================================
    ! MATLAB cell_4: 40 entries
    !===================================================================
    type, bind(C) :: cell_4_type
        character(c_char) :: f1(5)
        character(c_char) :: f2(5)
        character(c_char) :: f3(5)
        character(c_char) :: f4(5)
        character(c_char) :: f5(5)
        character(c_char) :: f6(5)
        character(c_char) :: f7(5)
        character(c_char) :: f8(5)
        character(c_char) :: f9(5)
        character(c_char) :: f10(5)
        character(c_char) :: f11(5)
        character(c_char) :: f12(5)
        character(c_char) :: f13(5)
        character(c_char) :: f14(5)
        character(c_char) :: f15(5)
        character(c_char) :: f16(5)
        character(c_char) :: f17(5)
        character(c_char) :: f18(5)
        character(c_char) :: f19(5)
        character(c_char) :: f20(5)
        character(c_char) :: f21(5)
        character(c_char) :: f22(5)
        character(c_char) :: f23(8)
        character(c_char) :: f24(8)
        character(c_char) :: f25(8)
        character(c_char) :: f26(8)
        character(c_char) :: f27(8)
        character(c_char) :: f28(8)
        character(c_char) :: f29(8)
        character(c_char) :: f30(8)
        character(c_char) :: f31(8)
        character(c_char) :: f32(8)
        character(c_char) :: f33(8)
        character(c_char) :: f34(8)
        character(c_char) :: f35(8)
        character(c_char) :: f36(8)
        character(c_char) :: f37(8)
        character(c_char) :: f38(8)
        character(c_char) :: f39(9)
        character(c_char) :: f40(9)
    end type cell_4_type

    !===================================================================
    ! MATLAB cell_5 (dimout 19 fields)
    !===================================================================
    type, bind(C) :: cell_5_type
        character(c_char) :: f1(8)
        character(c_char) :: f2(8)
        character(c_char) :: f3(8)
        character(c_char) :: f4(8)
        character(c_char) :: f5(8)
        character(c_char) :: f6(8)
        character(c_char) :: f7(8)
        character(c_char) :: f8(8)
        character(c_char) :: f9(8)
        character(c_char) :: f10(8)
        character(c_char) :: f11(8)
        character(c_char) :: f12(8)
        character(c_char) :: f13(8)
        character(c_char) :: f14(8)
        character(c_char) :: f15(8)
        character(c_char) :: f16(8)
        character(c_char) :: f17(9)
        character(c_char) :: f18(9)
        character(c_char) :: f19(8)
    end type cell_5_type

!=======================================================================
! NUMERICAL STRUCTS
!=======================================================================

    type, bind(C) :: addr_type
        real(c_double) :: time(10)
        real(c_double) :: data(10)
    end type addr_type

    type, bind(C) :: amat_type
        real(c_double) :: data(3042)
        type(cell_1_type) :: dimin
        type(cell_2_type) :: dimout
        logical(c_bool) :: lhyb(26)
    end type amat_type

    type, bind(C) :: mmat_type
        real(c_double) :: data(760)
        type(cell_4_type) :: dimin
        type(cell_5_type) :: dimout
        logical(c_bool) :: lhyb(19)
    end type mmat_type

    type, bind(C) :: gmat_type
        type(addr_type) :: addr
        real(c_double) :: G1I(5720)
        real(c_double) :: G2P(5720)
        real(c_double) :: G3D(5720)
        type(cell_2_type) :: dimin
        type(cell_wrap_0_type) :: dimout(22)
    end type gmat_type

    type, bind(C) :: ssPID_type
        real(c_double) :: a(10816)
        real(c_double) :: b(2704)
        real(c_double) :: c(8112)
        real(c_double) :: d(2028)
    end type ssPID_type

    type, bind(C) :: cpar_type
        type(amat_type) :: Amat
        type(mmat_type) :: Mmat
        type(gmat_type) :: Gmat
        logical(c_bool) :: iEin(40)
        logical(c_bool) :: iFin(40)
        logical(c_bool) :: iOHin(40)
        logical(c_bool) :: iGOin(40)
        type(ssPID_type) :: ssPIDd
    end type cpar_type

!=======================================================================
! OTHER FORTRAN-ONLY TYPES
!=======================================================================

    type, bind(C) :: cstate_type
        real(c_double) :: hyb(104)
    end type cstate_type

    type, bind(C) :: magn_type
        real(c_double) :: time
        real(c_double) :: Bm(38)
        real(c_double) :: Ff(38)
    end type magn_type

    type, bind(C) :: pfa_type
        real(c_double) :: time
        real(c_double) :: Ia(29)
        type(cell_wrap_0_type) :: names(29)
    end type pfa_type

    ! Fortran-managed Arefs (not C compatible)
    type :: Arefs_type
        integer(c_int) :: Nt
        integer(c_int) :: Nref
        real(c_double), pointer :: time(:)
        real(c_double), pointer :: data(:,:)
    end type Arefs_type

    type :: ffs_type
        integer(c_int) :: Nt
        integer(c_int) :: Nffs
        real(c_double), pointer :: time(:)
        real(c_double), pointer :: data(:,:)
    end type ffs_type
end module hybctrl_types_mod
