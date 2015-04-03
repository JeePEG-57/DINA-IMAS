      program main
      
      common /cb/ i, j, k
      integer i, j, k
           
      integer status

	interface
!      subroutine t15_2_initialize(firstTime)
      subroutine t15_2_initialize(a_in,a_out)
       real *8 a_in, a_out

cDEC$ ATTRIBUTES DLLIMPORT, stdcall::  t15_2_initialize
cDEC$ ATTRIBUTES ALIAS:'_t15_2_initialize'::t15_2_initialize
cDEC$ ATTRIBUTES VALUE :: a_in,a_out
      end subroutine 
      end interface


	interface
      subroutine t15_2_terminate()
cDEC$ ATTRIBUTES DLLIMPORT, stdcall::  t15_2_terminate
cDEC$ ATTRIBUTES ALIAS:'_t15_2_terminate'::t15_2_terminate
      end subroutine 
      end interface


	interface
      subroutine t15_2_output(k_in, a_in,
     *  k_out, a_out)
cDEC$ ATTRIBUTES DLLIMPORT, stdcall::  t15_2_output
cDEC$ ATTRIBUTES ALIAS:'_t15_2_output'::t15_2_output
cDEC$ ATTRIBUTES VALUE :: k_in,k_out
cDEC$ ATTRIBUTES REFERENCE :: a_in,a_out

       integer k_in,k_out
       real *8 a_in(*), a_out(*)
        
       end subroutine 
      end interface

	interface
      subroutine t15_2_output2() 
cDEC$ ATTRIBUTES DLLIMPORT, stdcall::  t15_2_output2
cDEC$ ATTRIBUTES ALIAS:'_t15_2_output2'::t15_2_output2
      end subroutine 
      end interface


!     pointer (p2, sub2)
 !     pointer (p3, sub3)
      
      character(80) dll_name
	logical aa2
          
      real *8 a, b, a_in(200),a_out(100)
      real *8 EqTime,SimStep

	print * ,' T15--initi'

      
!       call t15_2_initialize(aa2)

	EqTime=1.5
	SimStep=1.


       call t15_2_initialize(EqTime,SimStep)
     	 print *,'EqTime,SimStep',EqTime,SimStep


      k_in=15+123
      k_out=13
      
      do i=1,15
      a_in(i)=1.
      end do
      do i=15+1,100
      a_in(i)=-30.
      end do

      do i=100+1,123
      a_in(i)=10.
      end do

    
      	print * ,' k_in a_in',k_in,a_in(1:24)
      
      do i=1,5
      
      call t15_2_output(k_in, a_in,
     *  k_out, a_out) 

      	print * ,' k_out a_out',k_out,a_out(1:15)
      end do
      
!      call t15_2_output2() 

      call t15_2_terminate()
      
  !     call sub3(a,b)

 !     status = freelibrary(p2) 
 !     status = freelibrary(p3) 

      end

      subroutine sub1
      common /cb/ i, j, k
      integer i, j, k
      print *,i,j,k
      return
      end
