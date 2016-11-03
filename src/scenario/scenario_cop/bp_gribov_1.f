c
      subroutine bp_gribov(bz_left_xx,bz_right_xx)
	include 'double.inc'
      	include 'new_com.inc'


!      print *,' xleft xright zmag=',xleft,xright,zmag
      
      call bp_gribov_c(xleft,xright,zmag,bz_left_xx,bz_right_xx)
      
      return
      end

      subroutine bp_gribov_c(xleft,xright,zmag,bz_left,bz_right)

	include 'double.inc'

	dimension pdd(6)
	
        do i=1,2
           vrr=zmag
           if(i.eq.1)then
              urr=xleft
           else
              urr=xright
           end if
c           if(kpr.eq.1)print*,'!!! urr vrr',urr vrr
	   call boxd(urr,vrr,pdd,ier)          
c---------------
	   psi_r=pdd(2)
	   b_z=psi_r/urr*0.1
 
           if(i.eq.1)bz_left=b_z
           if(i.eq.2)bz_right=b_z
          
c	   psi_z=pdd(3)
c	   b_r=-psi_z/urr*0.1

	end do

	return
	end

