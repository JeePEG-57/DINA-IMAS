#include "fintrf.h"
!======================================================================
!     Loads ids and returns it to MatLab.

!======================================================================
!     Gateway routine
      subroutine mexFunction(nlhs, plhs, nrhs, prhs)

      use ids_schemas
      use ids_routines

!      use mexFillIDS

!     Declarations
      implicit none



!     mexFunction arguments:
      mwPointer plhs(*), prhs(*)
      integer nlhs, nrhs

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

      type (ids_equilibrium) :: equilibrium
      type (ids_pf_active) :: pf_active
      type (ids_pf_passive) :: pf_passive
      type (ids_core_profiles) :: core_profiles

      integer :: i,j,k,l,m,n,nfields
      integer*4 :: nfield, trash, nprof
      character*20 :: fieldnames(1)
      character*20 :: idsname = 'ids'
      mwSize, parameter :: OneRow=1, OneCol=1


!-----------------------------------------------------------------------
!     Check for proper number of arguments. 
      if(nrhs .ne. 3) then
         call mexErrMsgIdAndTxt ('MATLAB:LoadIDS:nInput',&
     & 'Bad number of input arguments. (Must be 3: numShot, run, idsname)')
      elseif(nlhs .gt. 1) then
         call mexErrMsgIdAndTxt ('MATLAB:LoadIDS:nOutput',&
     &                           'Too many output arguments.')
      endif

!     Validate inputs
!     Check that the input #1 is a number.
      if(mxIsNumeric(prhs(1)) .eq. 0) then
         call mexErrMsgIdAndTxt ('MATLAB:LoadIDS:NonNumeric',&
     &                           'First input must be a number.')
      endif

!     Check that the input #2 is a number.
      if(mxIsNumeric(prhs(2)) .eq. 0) then
         call mexErrMsgIdAndTxt ('MATLAB:LoadIDS:NonNumeric',&
     &                           'Second input must be a number.')
      endif

!     Check that the input #3 is a string.
       if(mxIsChar(prhs(3)) .eq. 0) then
          call mexErrMsgIdAndTxt ('MATLAB:LoadIDS:NonChar',&
      &                           'Third input must be a string.')
       endif

!     Check that input #1 is a scalar.
      m = mxGetM(prhs(1))
      n = mxGetN(prhs(1))
      if(n .ne. 1 .or. m .ne. 1) then
         call mexErrMsgIdAndTxt ('MATLAB:LoadIDS:NonScalar',&
     &                           'Input #1 is not a scalar.')
      endif

!     Check that input #2 is a scalar.
      m = mxGetM(prhs(2))
      n = mxGetN(prhs(2))
      if(n .ne. 1 .or. m .ne. 1) then
         call mexErrMsgIdAndTxt ('MATLAB:LoadIDS:NonScalar',&
     &                           'Input #2 is not a scalar.')
      endif

!      call WriteLog(1.0,1)

!     Get the size of the input array.
      mrows = mxGetM(prhs(1))
      ncols = mxGetN(prhs(1))
      shotsize = mrows*ncols

      mrows = mxGetM(prhs(2))
      ncols = mxGetN(prhs(2))
      runsize = mrows*ncols

      shot_ptr = mxGetPr(prhs(1))
      run_ptr = mxGetPr(prhs(2))
      call mxCopyPtrToReal8(shot_ptr,dshot,shotsize)
      call mxCopyPtrToReal8(run_ptr,drun,runsize)


      mrows = mxGetM(prhs(3))
      ncols = mxGetN(prhs(3))
      idsnamesize = mrows*ncols
!      idsname_ptr = mxGetPr(prhs(3))
!      call mxCopyPtrToCharacter(idsname_ptr,idsname,idsnamesize)
      trash = mxGetString(prhs(3), idsname, idsnamesize)
!	trash = mexPrintf(idsname)
!	trash = mexPrintf('\n')


      shot = idnint(dshot)
      run = idnint(drun)


      if (idsname.eq.'equilibrium') then

        call imas_open('ids',shot,run,idx)
        call ids_get(idx,'equilibrium',equilibrium)
        call imas_close(idx)
        call FillEquilibrium(plhs(1),equilibrium)
        call ids_deallocate(equilibrium)

      elseif (idsname.eq.'pf_active') then

        call imas_open('ids',shot,run,idx)
        call ids_get(idx,'pf_active',pf_active)
        call imas_close(idx)
        call FillPFActive(plhs(1),pf_active)
        call ids_deallocate(pf_active)

      elseif (idsname.eq.'pf_passive') then

        call imas_open('ids',shot,run,idx)
        call ids_get(idx,'pf_passive',pf_passive)
        call imas_close(idx)
        call FillPFPassive(plhs(1),pf_passive)
        call ids_deallocate(pf_passive)

      elseif (idsname.eq.'core_profiles') then

        call imas_open('ids',shot,run,idx)
        call ids_get(idx,'core_profiles',core_profiles)
        call imas_close(idx)
        call FillCoreProfiles(plhs(1),core_profiles)
        call ids_deallocate(core_profiles)

      else
         call mexErrMsgIdAndTxt ('MATLAB:LoadIDS:NoIDS',&
     &               'The name of IDS do not supported.')
      endif


      return
      end
