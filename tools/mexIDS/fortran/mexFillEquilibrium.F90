#include "fintrf.h"

!#include "mexFillIDSUtil.F90"
!======================================================================
!     Fills Equilibrium and returns it to LoadIDS.

      subroutine FillEquilibrium(eq_ptr, equilibrium)

      use ids_schemas
      use ids_routines

      use mexUtilIDS

!     Declarations
      implicit none

!     Arguments
      mwPointer :: eq_ptr
      type (ids_equilibrium) :: equilibrium

!     Function declarations:
      mwPointer mxGetPr
      mwPointer mxCreateDoubleMatrix
      mwPointer mxCreateStructMatrix
      mwPointer mxCreateCellMatrix
      integer*4 mxAddField, mexPrintf, mxGetString
      integer mxIsNumeric, mxIsChar
      mwPointer mxGetM, mxGetN

!     Pointers to input/output mxArrays:
      mwPointer shot_ptr, run_ptr
      mwPointer TimeSlice_ptr, Profiles2d_ptr, Grid_ptr
      mwPointer h_ptr, h1_ptr, h2_ptr, h3_ptr

!     Array information:
      mwPointer mrows, ncols
      mwSize shotsize,runsize,idsnamesize,ysize

!     Arguments for computational routine:
      real*8 :: dshot,drun
      integer :: shot,run
      integer :: idx
      mwSize :: ntime,mtime,timeshape(1),tshape(1)

      integer :: i,j,k,l,m,n,nfields
      integer*4 :: nfield, trash, nprof
      character*20 :: fieldnames(1)
      character*20 :: idsname = 'pf_active'
      mwSize, parameter :: OneRow=1, OneCol=1



!     Create Matlab structure for the equilibrium
      nfields = 1
      fieldnames(1) = 'ids_properties'
      eq_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
      nfield = mxAddField(eq_ptr, 'time_slice')
      nfield = mxAddField(eq_ptr, 'vacuum_toroidal_field')
      nfield = mxAddField(eq_ptr, 'time')


!     Create Matlab structure for the equilibrium.vacuum_toroidal_field
	  nfields = 1
	  fieldnames(1) = 'b0'
	  h1_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	  call mxSetField(eq_ptr, 1, 'vacuum_toroidal_field', h1_ptr)
	  nfield = mxAddField(h1_ptr, 'r0')

	  call SetFieldReal0D(h1_ptr, 'r0', equilibrium%vacuum_toroidal_field%r0)
	  call SetFieldReal1D(h1_ptr, 'b0', equilibrium%vacuum_toroidal_field%b0, 0)


!     Create Matlab cell array for the equilibrium.time_slice
	tshape = shape(equilibrium%time_slice)
	ntime = tshape(1)
	TimeSlice_ptr = mxCreateCellMatrix(1, ntime)
        call mxSetField(eq_ptr, 1, 'time_slice', TimeSlice_ptr)

!	call WriteLog(159.0,0)

      do i=1,ntime

      	nfields = 1
      	fieldnames(1) = 'time'
      	h1_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	call mxSetCell(TimeSlice_ptr, i, h1_ptr)
	nfield = mxAddField(h1_ptr, 'global_quantities')
      	nfield = mxAddField(h1_ptr, 'profiles_2d')
	nfield = mxAddField(h1_ptr, 'coordinate_system')

! Profiles_2d {
      	tshape = shape(equilibrium%time_slice(i)%profiles_2d)
      	nprof = tshape(1)
      	Profiles2d_ptr = mxCreateCellMatrix(OneRow, nprof)
      	call mxSetField(h1_ptr, 1, 'profiles_2d', Profiles2d_ptr)

      	do j=1,nprof

! Profiles_2d.Psi {
	  nfields = 1
	  fieldnames(1) = 'psi'
	  h2_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	  call mxSetCell(Profiles2d_ptr, j, h2_ptr)
	  nfield = mxAddField(h2_ptr, 'grid')

	  call SetFieldReal2D(h2_ptr, 'psi', equilibrium%time_slice(i)%profiles_2d(j)%psi)
! Profiles_2d.Psi }

! Profiles_2d.Grid {

	  nfields = 1
	  fieldnames(1) = 'dim1'
	  Grid_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	  call mxSetField(h2_ptr, 1, 'grid', Grid_ptr)
	  nfield = mxAddField(Grid_ptr, 'dim2')

	  call SetFieldReal1D(Grid_ptr, 'dim1', equilibrium%time_slice(i)%profiles_2d(j)%grid%dim1, 0)
	  call SetFieldReal1D(Grid_ptr, 'dim2', equilibrium%time_slice(i)%profiles_2d(j)%grid%dim2, 0)

! Profiles_2d.Grid }

      	enddo

! Profiles_2d }

! Global quantities {
	nfields = 1
	fieldnames(1) = 'psi_axis'
	h2_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	call mxSetField(h1_ptr, 1, 'global_quantities', h2_ptr)
	nfield = mxAddField(h2_ptr, 'psi_boundary')
        nfield = mxAddField(h2_ptr, 'ip')
	nfield = mxAddField(h2_ptr, 'li_3')
	nfield = mxAddField(h2_ptr, 'volume')
	nfield = mxAddField(h2_ptr, 'area')
	nfield = mxAddField(h2_ptr, 'magnetic_axis')
	nfield = mxAddField(h2_ptr, 'q_95')
	nfield = mxAddField(h2_ptr, 'q_axis')
	nfield = mxAddField(h2_ptr, 'w_mhd')

	call SetFieldReal0D(h2_ptr, 'psi_axis', &
	&	equilibrium%time_slice(i)%global_quantities%psi_axis)
	call SetFieldReal0D(h2_ptr, 'psi_boundary', &
	&	equilibrium%time_slice(i)%global_quantities%psi_boundary)
        call SetFieldReal0D(h2_ptr, 'ip', equilibrium%time_slice(i)%global_quantities%ip)
	call SetFieldReal0D(h2_ptr, 'li_3', equilibrium%time_slice(i)%global_quantities%li_3)
	call SetFieldReal0D(h2_ptr, 'volume', equilibrium%time_slice(i)%global_quantities%volume)
        call SetFieldReal0D(h2_ptr, 'area', equilibrium%time_slice(i)%global_quantities%area)
        call SetFieldReal0D(h2_ptr, 'q_95', equilibrium%time_slice(i)%global_quantities%q_95)
        call SetFieldReal0D(h2_ptr, 'q_axis', equilibrium%time_slice(i)%global_quantities%q_axis)
        call SetFieldReal0D(h2_ptr, 'w_mhd', equilibrium%time_slice(i)%global_quantities%w_mhd)

! Magnetic Axis {
	nfields = 1
	fieldnames(1) = 'r'
	h3_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	call mxSetField(h2_ptr, 1, 'magnetic_axis', h3_ptr)
	nfield = mxAddField(h3_ptr, 'z')

	call SetFieldReal0D(h3_ptr, 'r', &
	&	 equilibrium%time_slice(i)%global_quantities%magnetic_axis%r)
	call SetFieldReal0D(h3_ptr, 'z', &
	&	 equilibrium%time_slice(i)%global_quantities%magnetic_axis%z)
! Magnetic Axis }

! Global quantities }

! Coordinate System {
	nfields = 1
	fieldnames(1) = 'r'
	h2_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	call mxSetField(h1_ptr, 1, 'coordinate_system', h2_ptr)
	nfield = mxAddField(h2_ptr, 'z')

	call SetFieldReal2D(h2_ptr, 'r', equilibrium%time_slice(i)%coordinate_system%r)
	call SetFieldReal2D(h2_ptr, 'z', equilibrium%time_slice(i)%coordinate_system%z)

! Coordinate System }

	call SetFieldReal0D(h1_ptr, 'time', equilibrium%time_slice(i)%time)

      enddo

      !call WriteLog(4.0,0)
!     Create Matlab double array for the equilibrium.time

      call SetFieldReal1D(eq_ptr, 'time', equilibrium%time, 0)

      return
      end
 
