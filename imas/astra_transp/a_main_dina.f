c	include 'fgraph.fi'
	include 'double.inc'
!	include 'new_com.inc'

	character *20 yy

      parameter (kint=200)
      
      dimension c_input1(kint),c_input2(kint)
      dimension c_output1(kint),c_output2(kint),c_output3(kint)

      kpr1=1

      if(kpr1.eq.1)print *,' -------- a_main kpr==',a_main,kpr

!      tay=10.
!      t_vde=1000.

        open (unit=49,file='tay_time.dat',form='formatted')
        read (49,*)
        read (49,*)tay,tt_end
        
        close ( unit=49)       

      if(kpr1.eq.1)print *,' - tay  tt_end==',tay,tt_end

      do k=1,999993

     
	  call dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3)


	ntay=ntay+1
	tt=tt+tay
       
       if(kpr1.gt.0)print *,' -------- k tt tt_end=',k,tt,tt_end


       if(tt.gt.tt_end)then
       stop
       end if
       
       

!	  call kav_contr(
!-----------------------------------  inputs---
!     *  c_output1,c_output2,
!------------------------------------outputs
!     *  c_input1,c_input2)


      end do


      end

