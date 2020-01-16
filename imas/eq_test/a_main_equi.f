c	include 'fgraph.fi'
	include 'double.inc'
	include 'new_com.inc'

	character *20 yy

      parameter (kint=200)
      
      dimension c_input1(kint),c_input2(kint)
      dimension c_output1(kint),c_output2(kint),c_output3(kint)

      kpr=1

      print *,' -------- a_main=',a_main

  
      call read_equil()
      
      
	  call dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3)


      end
      
