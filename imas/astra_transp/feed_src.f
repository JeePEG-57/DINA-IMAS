	subroutine feed_src(gPuff,pcch_xx,pcchp_src,tt_in)

cDEC$ ATTRIBUTES DLLEXPORT::  feed_src

      include 'double.inc'
	include 'new_com.inc'                                                  

	character *20 apr,filename
      
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      tt0=tt
      tt=tt_in*1.d3
      tay=tt-tt0
      
      pcch0=pcch
      pcch=pcch_xx
      
!------------------------------------inputs
      i_en=i_en+1
      if(i_en.eq.1)then
c---  we think ....???
	ARG=1.
	pi=4.*atan(ARG)
        gPuff0=0.

        open (unit=1,file='external_data.dat',form='formatted')
        read (1,*)
        read (1,*)kpr
        read (1,*)
        read (1,*)gPuff_uu,d_gPuff_uu,tay1_uu,coefI_uu

        read (1,*)
        read (1,*)gPuff,d_gPuff,tay1,coefI
        gPuff0=gPuff
           
      end if

       
       if(kpr.eq.1)print *,' ---CALL feed_src'
      
      call den_read()

      if(i_en.eq.1)then
      close (1)
      end if
      
      
      del=pcch-pcchp
      del0=pcch-pcch0
      del_int=del_int+del
      V=del0/tay
      dgPuff=-d_gPuff*( del+V*tay1 )-coefI*del_int

      if(kpr.eq.1)print *,' gPuff0 pcch0 --',gPuff0,pcch0
      if(kpr.eq.1)print *,' coefI del_int-',coefI,del_int

      gPuff=dgPuff
!      gPuff=gPuff0+dgPuff
      if(gPuff.le.0.)gPuff=0.

      if(kpr.eq.1)print *,' pcchp  pcch',pcchp,pcch
      if(kpr.eq.1)print *,' gPuff  del',gPuff,del
      if(kpr.eq.1)print *,' d_gPuff dgPuff',d_gPuff,dgPuff
      pcchp_src=pcchp
      
      gPuff0=gPuff
      
      return
      end
	subroutine den_read()
	include 'double.inc'
	include 'new_com.inc'

	call den_read_c(
     *  tt,pcchp,ntay,tay)
	
	return
	end

	subroutine den_read_c(
     *  tt,pcchp,ntay,tay)

	include 'double.inc'
 	include 'parf_mike' 

        common
     *  /ge5/kpr

	dimension t_t(ntime),den_t(ntime)


	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
!           open (unit=41,file='dens.dat',form='formatted') 
           read (1,*) 
           read (1,*)n_t 
           read (1,*) 

 	 if(kpr.eq.1)print *,' tay tt n_t===',tay,tt,n_t 

           do i=1,n_t 
              read (1,*)t_t(i),den_t(i)
              t_t(i)=t_t(i)*1000. 
           end do 
           
           apr='-t_t-' 
           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 

           apr='-den_t-' 
           if(kpr.eq.1)print 71,apr,(den_t(i),i=1,n_t) 

        !   close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

	   if(ntay.le.2)then
c*vic!!!	      den_t(1)=pcchp
!!!	      t_t(1)=tt-tay
	   end if


           apr='-den_t22' 
           if(kpr.eq.1)print 71,apr,(den_t(i),i=1,n_t) 


      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 den=den_t(i-1)+t_coef*(den_t(i)-den_t(i-1))
c
	 end if

	 end do

!	   if(ntay.gt.2)pcchp=den

	pcchp=den

c	if(kpr.eq.1)print *,' from den_read  pcchp den ntay',pcchp,den,ntay
c	pause 'from den_read'


       return 
       end 
