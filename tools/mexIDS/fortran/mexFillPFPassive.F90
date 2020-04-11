#include "fintrf.h"

!#include "mexFillIDSUtil.F90"
!======================================================================
!     Fills PFPassive and returns it to LoadIDS.

      subroutine FillPFPassive(cpo_ptr, cpo)

      use ids_schemas
      use ids_routines

      use mexUtilIDS

!     Declarations
      implicit none

!     Arguments
      mwPointer :: cpo_ptr
      type (ids_pf_passive) :: cpo

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
      mwPointer Loop_ptr
      mwPointer h_ptr, h1_ptr, h2_ptr, h3_ptr, h4_ptr

!     Array information:
      mwPointer mrows, ncols
      mwSize shotsize,runsize,idsnamesize,ysize

!     Arguments for computational routine:
      real*8 :: dshot,drun
      integer :: shot,run
      integer :: idx
      mwSize :: ntime,mtime,timeshape(1),tshape(1)

      integer :: i,j,k,l,m,n,nfields
      integer*4 :: nfield, trash, nloop
      character*20 :: fieldnames(1)
      mwSize, parameter :: OneRow=1, OneCol=1

      mwIndex :: ind1, ind2, ind3
      mwIndex, parameter :: StructOne = 1


!     Create Matlab structure for the pf_passive
      nfields = 1
      fieldnames(1) = 'ids_properties'
      cpo_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
      nfield = mxAddField(cpo_ptr, 'loop')
      nfield = mxAddField(cpo_ptr, 'time')


!     Create Matlab cell array for the loops
	tshape = shape(cpo%loop)
	nloop = tshape(1)
	Loop_ptr = mxCreateCellMatrix(OneRow, nloop)
        call mxSetField(cpo_ptr, StructOne, 'loop', Loop_ptr)

!	call WriteLog(159.0,0)


! Loop {
      do i=1,nloop

      	nfields = 1
      	fieldnames(1) = 'current'
      	h1_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
        ind1 = i;
	  call mxSetCell(Loop_ptr, ind1, h1_ptr)
	  nfield = mxAddField(h1_ptr, 'resistance')
	  nfield = mxAddField(h1_ptr, 'geometry')
	  nfield = mxAddField(h1_ptr, 'area')

! Current {
	  call SetFieldReal1D(h1_ptr, 'current', cpo%loop(i)%current, 0)
! Current }


! Resistance
	  call SetFieldReal0D(h1_ptr, 'resistance', cpo%loop(i)%resistance)


	  !call SetFieldReal0D(h1_ptr, 'area', cpo%loop(i)%area)

! ! Geometry {
! 	  nfields = 1
! 	  fieldnames(1) = 'geometry_type'
! 	  h3_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
! 	  call mxSetField(h1_ptr, StructOne, 'geometry', h3_ptr)
! 	  nfield = mxAddField(h3_ptr, 'outline')
! 	  nfield = mxAddField(h3_ptr, 'oblique')
! 	  nfield = mxAddField(h3_ptr, 'rectangle')
! 
! 	  call SetFieldReal0D(h3_ptr, 'geometry_type', DBLE(cpo%loop(i)%geometry%geometry_type))
! 
! ! Outline {
! 	  nfields = 1
! 	  fieldnames(1) = 'r'
! 	  h4_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
! 	  call mxSetField(h3_ptr, StructOne, 'outline', h4_ptr)
! 	  nfield = mxAddField(h4_ptr, 'z')
! 	  call SetFieldReal1D(h4_ptr, 'r', cpo%loop(i)%geometry%outline%r, 0)
! 	  call SetFieldReal1D(h4_ptr, 'z', cpo%loop(i)%geometry%outline%z, 0)
! ! Outline }
! 
! ! Oblique {
! 	  nfields = 1
! 	  fieldnames(1) = 'r'
! 	  h4_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
! 	  call mxSetField(h3_ptr, StructOne, 'oblique', h4_ptr)
! 	  nfield = mxAddField(h4_ptr, 'z')
! 	  nfield = mxAddField(h4_ptr, 'length')
! 	  nfield = mxAddField(h4_ptr, 'thickness')
! 	  nfield = mxAddField(h4_ptr, 'alpha')
! 	  nfield = mxAddField(h4_ptr, 'beta')
! 
! 	  call SetFieldReal0D(h4_ptr, 'r', cpo%loop(i)%geometry%oblique%r)
! 	  call SetFieldReal0D(h4_ptr, 'z', cpo%loop(i)%geometry%oblique%z)
! 	  call SetFieldReal0D(h4_ptr, 'length', cpo%loop(i)%geometry%oblique%length)
! 	  call SetFieldReal0D(h4_ptr, 'thickness', cpo%loop(i)%geometry%oblique%thickness)
! 	  call SetFieldReal0D(h4_ptr, 'alpha', cpo%loop(i)%geometry%oblique%alpha)
! 	  call SetFieldReal0D(h4_ptr, 'beta', cpo%loop(i)%geometry%oblique%beta)
! ! Oblique }
! 
! ! Rectangle {
! 	  nfields = 1
! 	  fieldnames(1) = 'r'
! 	  h4_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
! 	  call mxSetField(h3_ptr, StructOne, 'rectangle', h4_ptr)
! 	  nfield = mxAddField(h4_ptr, 'z')
! 	  nfield = mxAddField(h4_ptr, 'width')
! 	  nfield = mxAddField(h4_ptr, 'height')
! 
! 	  call SetFieldReal0D(h4_ptr, 'r', cpo%loop(i)%geometry%rectangle%r)
! 	  call SetFieldReal0D(h4_ptr, 'z', cpo%loop(i)%geometry%rectangle%z)
! 	  call SetFieldReal0D(h4_ptr, 'width', cpo%loop(i)%geometry%rectangle%width)
! 	  call SetFieldReal0D(h4_ptr, 'height', cpo%loop(i)%geometry%rectangle%height)
! ! Rectangle }
! 
! ! Geometry }
      enddo
! Loop }

      !call WriteLog(4.0,0)
! Time array {
      call SetFieldReal1D(cpo_ptr, 'time', cpo%time, 0)
! Time array }

      return
      end
 
