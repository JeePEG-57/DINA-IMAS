#include "fintrf.h"
!======================================================================
! Commonly used subroutines


module mexUtilIDS

interface 
      subroutine SetFieldReal0D(str_ptr,fieldname,Data)

      implicit none

      mwPointer :: str_ptr
      real*8 :: Data
      character*(*) :: fieldname

      end subroutine

      subroutine SetFieldReal1D(str_ptr,fieldname,Data,IsRow)

      implicit none

      mwPointer :: str_ptr
      real*8,dimension(:) :: Data
      character*(*) :: fieldname

      integer :: IsRow

      end subroutine

      subroutine SetFieldReal2D(str_ptr,fieldname,Data)

      implicit none

      mwPointer :: str_ptr
      real*8,dimension(:,:) :: Data
      character*(*) :: fieldname

      end subroutine

!       subroutine SetFieldStructure(str_ptr,fieldname,Data)
! 
!       implicit none
! 
!       mwPointer :: str_ptr
!       real*8,dimension(:,:) :: Data
!       character*(*) :: fieldname
! 
!       end subroutine
end interface 

end module mexUtilIDS


!======================================================================

      subroutine SetFieldReal0D(str_ptr,fieldname,Data)

      !use mexUtilIDS

      implicit none

      mwPointer :: str_ptr
      real*8 :: Data
      character*(*) :: fieldname

      mwPointer mxGetPr
      mwPointer mxCreateDoubleMatrix
      mwPointer mxGetM, mxGetN
      integer*4 mexPrintf

      mwPointer :: h_ptr, h1_ptr
      mwSize :: mrows, ncols, ysize
      integer*4 :: trash
      mwSize, parameter :: OneRow=1, OneCol=1


      h_ptr = mxCreateDoubleMatrix(OneRow, OneCol, 0)


      h1_ptr = mxGetPr(h_ptr)

      mrows = mxGetM(h_ptr)
      ncols = mxGetN(h_ptr)
      ysize = mrows*ncols


      call mxCopyReal8ToPtr(Data,h1_ptr,ysize)

      call mxSetField(str_ptr, 1, fieldname, h_ptr)

      return
      end


      subroutine SetFieldReal1D(str_ptr,fieldname,Data,IsRow)

      implicit none

      mwPointer :: str_ptr
      real*8,dimension(:) :: Data
      character*(*) :: fieldname

      integer :: IsRow

      mwPointer mxGetPr
      mwPointer mxCreateDoubleMatrix
      mwPointer mxGetM, mxGetN
      integer*4 mexPrintf

      mwPointer :: h_ptr, h1_ptr
      mwSize :: ashape(1), mrows, ncols, ysize
      integer*4 :: trash
      mwSize, parameter :: OneRow=1, OneCol=1


      ashape = shape(Data)

      if (IsRow.eq.1) then
      	h_ptr = mxCreateDoubleMatrix(OneRow,ashape(1),0)
      else
      	h_ptr = mxCreateDoubleMatrix(ashape(1),OneCol,0)
      endif

      h1_ptr = mxGetPr(h_ptr)

      mrows = mxGetM(h_ptr)
      ncols = mxGetN(h_ptr)
      ysize = mrows*ncols
      call mxCopyReal8ToPtr(Data,h1_ptr,ysize)

      call mxSetField(str_ptr, 1, fieldname, h_ptr)

      return
      end



      subroutine SetFieldReal2D(str_ptr,fieldname,Data)

      implicit none

      mwPointer :: str_ptr
      real*8,dimension(:,:) :: Data
      character*(*) :: fieldname

      mwPointer mxGetPr
      mwPointer mxCreateDoubleMatrix
      mwPointer mxGetM, mxGetN
      integer*4 mexPrintf

      mwPointer :: h_ptr, h1_ptr
      mwSize :: ashape(2), mrows, ncols, ysize
      integer*4 :: trash
      mwSize, parameter :: OneRow=1, OneCol=1


      ashape = shape(Data)

      h_ptr = mxCreateDoubleMatrix(ashape(1),ashape(2),0)

      h1_ptr = mxGetPr(h_ptr)

      mrows = mxGetM(h_ptr)
      ncols = mxGetN(h_ptr)
      ysize = mrows*ncols
      call mxCopyReal8ToPtr(Data,h1_ptr,ysize)

      call mxSetField(str_ptr, 1, fieldname, h_ptr)

      return
      end



	subroutine WriteLog(d,flag_start)

	implicit none

	real*8 :: d
	integer :: flag_start
	integer*4 :: trash

	integer*4 mexPrintf
        CHARACTER*(*), PARAMETER  :: FormatFile = "(4(1x,1pe14.7))", FormatConsole = "(1pe14.7,a)"
	character*50 :: strlog

	if (flag_start.eq.1) call system("rm LoadIDSmex_log.txt")

	open (unit=62,file='LoadIDSmex_log.txt',access='append',form='formatted')

	if (flag_start.eq.1) then
!Write header
!		write(62,*) "     Step    ","     Absolute"
	end if

	write (62, FormatFile) d
	write (strlog, FormatConsole) d, '\n'
	trash = mexPrintf(strlog)


        close (62)

	return
	end

