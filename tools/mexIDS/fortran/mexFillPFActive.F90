#include "fintrf.h"

!#include "mexFillIDSUtil.F90"
!======================================================================
!     Fills PFActive and returns it to LoadIDS.

      subroutine FillPFActive(cpo_ptr, cpo)

      use ids_schemas
      use ids_routines

      use mexUtilIDS

!     Declarations
      implicit none

!     Arguments
      mwPointer :: cpo_ptr
      type (ids_pf_active) :: cpo

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
      mwPointer Coil_ptr, Element_ptr
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
      integer*4 :: nfield, trash, ncoil, nelem
      character*20 :: fieldnames(1)
      mwSize, parameter :: OneRow=1, OneCol=1



!     Create Matlab structure for the pf_active
      nfields = 1
      fieldnames(1) = 'ids_properties'
      cpo_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
      nfield = mxAddField(cpo_ptr, 'coil')
      nfield = mxAddField(cpo_ptr, 'time')

!     Create Matlab cell array for the coils
	tshape = shape(cpo%coil)
	ncoil = tshape(1)
	Coil_ptr = mxCreateCellMatrix(1, ncoil)
        call mxSetField(cpo_ptr, 1, 'coil', Coil_ptr)

!	call WriteLog(159.0,0)


! Coil {
      do i=1,ncoil

      	nfields = 1
      	fieldnames(1) = 'current'
      	h1_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	  call mxSetCell(Coil_ptr, i, h1_ptr)
	  nfield = mxAddField(h1_ptr, 'voltage')
	  nfield = mxAddField(h1_ptr, 'resistance')
	  nfield = mxAddField(h1_ptr, 'element')


! Current {
	  nfields = 1
	  fieldnames(1) = 'data'
	  h2_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	  call mxSetField(h1_ptr, 1, 'current',h2_ptr)

	  call SetFieldReal1D(h2_ptr, 'data', cpo%coil(i)%current%data, 0)
! Current }

! Voltage {
	  nfields = 1
	  fieldnames(1) = 'data'
	  h2_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	  call mxSetField(h1_ptr, 1, 'voltage',h2_ptr)

	  call SetFieldReal1D(h2_ptr, 'data', cpo%coil(i)%voltage%data, 0)
! Voltage }

! Resistance
	call SetFieldReal0D(h1_ptr, 'resistance', cpo%coil(i)%resistance)


! Element {
      	tshape = shape(cpo%coil(i)%element)
      	nelem = tshape(1)
      	Element_ptr = mxCreateCellMatrix(OneRow, nelem)
	  call mxSetField(h1_ptr, 1, 'element', Element_ptr)

      	do j=1,nelem


	  nfields = 1
	  fieldnames(1) = 'area'
	  h2_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	  call mxSetCell(Element_ptr, j, h2_ptr)
	  nfield = mxAddField(h2_ptr, 'turns_with_sign')
	  nfield = mxAddField(h2_ptr, 'geometry')



	  call SetFieldReal0D(h2_ptr, 'turns_with_sign',&
		& DBLE(cpo%coil(i)%element(j)%turns_with_sign))
	  call SetFieldReal0D(h2_ptr, 'area', cpo%coil(i)%element(j)%area)

! Element.Geometry {
	  nfields = 1
	  fieldnames(1) = 'geometry_type'
	  h3_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	  call mxSetField(h2_ptr, 1, 'geometry', h3_ptr)
	  nfield = mxAddField(h3_ptr, 'outline')
	  nfield = mxAddField(h3_ptr, 'oblique')
	  nfield = mxAddField(h3_ptr, 'rectangle')


	  call SetFieldReal0D(h3_ptr, 'geometry_type', &
	&	DBLE(cpo%coil(i)%element(j)%geometry%geometry_type))

! Outline {
	  nfields = 1
	  fieldnames(1) = 'r'
	  h4_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	  call mxSetField(h3_ptr, 1, 'outline', h4_ptr)
	  nfield = mxAddField(h4_ptr, 'z')
	  call SetFieldReal1D(h4_ptr, 'r', cpo%coil(i)%element(j)%geometry%outline%r, 0)
	  call SetFieldReal1D(h4_ptr, 'z', cpo%coil(i)%element(j)%geometry%outline%z, 0)
! Outline }

! Oblique {
	  nfields = 1
	  fieldnames(1) = 'r'
	  h4_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	  call mxSetField(h3_ptr, 1, 'oblique', h4_ptr)
	  nfield = mxAddField(h4_ptr, 'z')
	  nfield = mxAddField(h4_ptr, 'length')
	  nfield = mxAddField(h4_ptr, 'thickness')
	  nfield = mxAddField(h4_ptr, 'alpha')
	  nfield = mxAddField(h4_ptr, 'beta')

	  call SetFieldReal0D(h4_ptr, 'r', cpo%coil(i)%element(j)%geometry%oblique%r)
	  call SetFieldReal0D(h4_ptr, 'z', cpo%coil(i)%element(j)%geometry%oblique%z)
	  call SetFieldReal0D(h4_ptr, 'length', cpo%coil(i)%element(j)%geometry%oblique%length)
	  call SetFieldReal0D(h4_ptr, 'thickness', cpo%coil(i)%element(j)%geometry%oblique%thickness)
	  call SetFieldReal0D(h4_ptr, 'alpha', cpo%coil(i)%element(j)%geometry%oblique%alpha)
	  call SetFieldReal0D(h4_ptr, 'beta', cpo%coil(i)%element(j)%geometry%oblique%beta)
! Oblique }

! Rectangle {
	  nfields = 1
	  fieldnames(1) = 'r'
	  h4_ptr = mxCreateStructMatrix(OneRow, OneCol, nfields, fieldnames)
	  call mxSetField(h3_ptr, 1, 'rectangle', h4_ptr)
	  nfield = mxAddField(h4_ptr, 'z')
	  nfield = mxAddField(h4_ptr, 'width')
	  nfield = mxAddField(h4_ptr, 'height')

	  call SetFieldReal0D(h4_ptr, 'r', cpo%coil(i)%element(j)%geometry%rectangle%r)
	  call SetFieldReal0D(h4_ptr, 'z', cpo%coil(i)%element(j)%geometry%rectangle%z)
	  call SetFieldReal0D(h4_ptr, 'width', cpo%coil(i)%element(j)%geometry%rectangle%width)
	  call SetFieldReal0D(h4_ptr, 'height', cpo%coil(i)%element(j)%geometry%rectangle%height)
! Rectangle }

      	enddo
! Element }

      enddo
! Coil }

      !call WriteLog(4.0,0)
! Time array {
      call SetFieldReal1D(cpo_ptr, 'time', cpo%time, 0)
! Time array }

      return
      end
 
