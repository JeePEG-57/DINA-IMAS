c	include 'fgraph.fi'
	include 'double.inc'
	include 'new_com.inc'

	character *20 yy

      parameter (kint=200)
      
      dimension c_input1(kint),c_input2(kint)
      dimension c_output1(kint),c_output2(kint)

      kpr=1

      do k=1,9993
      
!      if(kpr.eq.1)print *,'  +zvel_01==',zvel

	  call dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2)

!      if(kpr.eq.1)print *,'  +zvel_02==',zvel

	  call kav_contr(
!-----------------------------------  inputs---
     *  c_output1,c_output2,
!------------------------------------outputs
     *  c_input1,c_input2)

!      if(kpr.eq.1)print *,'  +zvel_03==',zvel

      end do

      end

