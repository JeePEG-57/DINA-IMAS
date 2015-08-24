#include "fintrf.h"

!#include "mexFillIDSUtil.F90"
!======================================================================
!     Fills CoreProfiles and returns it to LoadIDS.

      subroutine FillCoreProfiles(cpo_ptr, cpo)

      use ids_schemas
      use ids_routines

      use mexUtilIDS

!     Declarations
      implicit none

!     Arguments
      mwPointer :: cpo_ptr
      type (ids_core_profiles) :: cpo

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
      mwPointer Profiles1d_ptr, Grid_ptr
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
      integer*4 :: nfield, trash
      character*20 :: fieldnames(1)
      character*20 :: idsname = 'pf_active'
      mwSize, parameter :: OneRow=1, OneCol=1



!     Create Matlab structure for the core_profiles
      nfields = 1
      fieldnames(1) = 'ids_properties'
      cpo_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
      nfield = mxAddField(cpo_ptr, 'profiles_1d')
      nfield = mxAddField(cpo_ptr, 'time')


!     Create Matlab cell array for the profiles_1d
	tshape = shape(cpo%profiles_1d)
	ntime = tshape(1)
	Profiles1D_ptr = mxCreateCellMatrix(1, ntime)
        call mxSetField(cpo_ptr, 1, 'profiles_1d', Profiles1D_ptr)

!	call WriteLog(159.0,0)


! Profiles_1d {
      do i=1,ntime

      	nfields = 1
      	fieldnames(1) = 'grid'
      	h1_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	call mxSetCell(Profiles1D_ptr, i, h1_ptr)
        nfield = mxAddField(h1_ptr, 't_e')
        nfield = mxAddField(h1_ptr, 't_i_average')
        nfield = mxAddField(h1_ptr, 'n_e')
        nfield = mxAddField(h1_ptr, 'j_tor')
        nfield = mxAddField(h1_ptr, 'q')
        nfield = mxAddField(h1_ptr, 'time')

! Profiles_1d.Grid {
	nfields = 1
	fieldnames(1) = 'rho_tor_norm'
	Grid_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	call mxSetField(h1_ptr, 1, 'grid', Grid_ptr)

	call SetFieldReal1D(Grid_ptr, 'rho_tor_norm', &
	&	cpo%profiles_1d(i)%grid%rho_tor_norm, 0)
! Profiles_1d.Grid }

	call SetFieldReal0D(h1_ptr, 'time', &
	&	cpo%profiles_1d(i)%time)

	call SetFieldReal1D(h1_ptr, 't_e', &
	&	cpo%profiles_1d(i)%t_e, 0)

	call SetFieldReal1D(h1_ptr, 't_i_average', &
	&	cpo%profiles_1d(i)%t_i_average, 0)

	call SetFieldReal1D(h1_ptr, 'n_e', &
	&	cpo%profiles_1d(i)%n_e, 0)

	call SetFieldReal1D(h1_ptr, 'j_tor', &
	&	cpo%profiles_1d(i)%j_tor, 0)

	call SetFieldReal1D(h1_ptr, 'q', &
	&	cpo%profiles_1d(i)%q, 0)
      enddo
! Profiles_1d }


      !call WriteLog(4.0,0)
!     Create Matlab double array for the time
      call SetFieldReal1D(cpo_ptr, 'time', cpo%time, 0)


      return
      end
 
