  	subroutine shape_13() 
	include 'double.inc'
 	include 'parf1' 
 	parameter ( NPFC=KF-4) 

 	include 'parf_mike' 

c 	parameter (ntime=20)
 
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ge2/ntay,tay,tt

	dimension t_t(ntime),pf_t(ntime)

	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='13.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 

 	 if(kpr.eq.1)print *,' tt n_t===',tt,n_t 
           read (41,*) 

           do i=1,n_t 
              read (41,*)t_t(i),pf_t(i)
              t_t(i)=t_t(i)*1000. 
           end do 
           
           apr='-t_t-' 
c           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 
           close (unit=41) 
        end if
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 pf(13)=pf_t(i-1)+t_coef*(pf_t(i)-pf_t(i-1))

c
	 end if

	 end do
	if(kpr.eq.1)print *,' from SHAPE 13',pf(13)

       return 
       end 
  	subroutine shape_15() 
	include 'double.inc'
 	include 'parf1' 
 	parameter ( NPFC=KF-4) 

 	include 'parf_mike' 

c 	parameter (ntime=20)
 
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ge2/ntay,tay,tt

	dimension t_t(ntime),pf_t(ntime)

	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='15.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 

 	 if(kpr.eq.1)print *,' tt n_t===',tt,n_t 
           read (41,*) 

           do i=1,n_t 
              read (41,*)t_t(i),pf_t(i)
              t_t(i)=t_t(i)*1000. 
           end do 
           
           apr='-t_t-' 
c           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 
           close (unit=41) 
        end if
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 pf(15)=pf_t(i-1)+t_coef*(pf_t(i)-pf_t(i-1))

c
	 end if

	 end do
	if(kpr.eq.1)print *,' from SHAPE 15',pf(15)

       return 
       end 
  	subroutine shape_16() 
	include 'double.inc'
 	include 'parf1' 
 	parameter ( NPFC=KF-4) 

 	include 'parf_mike' 

c 	parameter (ntime=20)
 
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ge2/ntay,tay,tt

	dimension t_t(ntime),pf_t(ntime)

	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='16.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 

 	 if(kpr.eq.1)print *,' tt n_t===',tt,n_t 
           read (41,*) 

           do i=1,n_t 
              read (41,*)t_t(i),pf_t(i)
              t_t(i)=t_t(i)*1000. 
           end do 
           
           apr='-t_t-' 
c           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 
           close (unit=41) 
        end if
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 pf(16)=pf_t(i-1)+t_coef*(pf_t(i)-pf_t(i-1))

c
	 end if

	 end do
	if(kpr.eq.1)print *,' from SHAPE 16',pf(16)

       return 
       end 
  	subroutine shape_17() 
	include 'double.inc'
 	include 'parf1' 
 	parameter ( NPFC=KF-4) 

 	include 'parf_mike' 

c 	parameter (ntime=20)
 
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ge2/ntay,tay,tt

	dimension t_t(ntime),pf_t(ntime)

	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='17.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 

 	 if(kpr.eq.1)print *,' tt n_t===',tt,n_t 
           read (41,*) 

           do i=1,n_t 
              read (41,*)t_t(i),pf_t(i)
              t_t(i)=t_t(i)*1000. 
           end do 
           
           apr='-t_t-' 
c           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 
           close (unit=41) 
        end if
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 pf(17)=pf_t(i-1)+t_coef*(pf_t(i)-pf_t(i-1))

c
	 end if

	 end do
	if(kpr.eq.1)print *,' from SHAPE 17',pf(17)

       return 
       end 
  	subroutine shape_18() 
	include 'double.inc'
 	include 'parf1' 
 	parameter ( NPFC=KF-4) 

 	include 'parf_mike' 

c 	parameter (ntime=20)
 
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ge2/ntay,tay,tt

	dimension t_t(ntime),pf_t(ntime)

	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='18.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 

 	 if(kpr.eq.1)print *,' tt n_t===',tt,n_t 
           read (41,*) 

           do i=1,n_t 
              read (41,*)t_t(i),pf_t(i)
              t_t(i)=t_t(i)*1000. 
           end do 
           
           apr='-t_t-' 
c           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 
           close (unit=41) 
        end if
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 pf(18)=pf_t(i-1)+t_coef*(pf_t(i)-pf_t(i-1))

c
	 end if

	 end do
	if(kpr.eq.1)print *,' from SHAPE 18',pf(18)

       return 
       end 

  	subroutine shape_14() 
	include 'double.inc'
 	include 'parf1' 
 	parameter ( NPFC=KF-4) 

 	include 'parf_mike' 

c 	parameter (ntime=20)
 
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ge2/ntay,tay,tt

	dimension t_t(ntime),pf_t(ntime)

	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='14.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 

 	 if(kpr.eq.1)print *,' tt n_t===',tt,n_t 
           read (41,*) 

           do i=1,n_t 
              read (41,*)t_t(i),pf_t(i)
              t_t(i)=t_t(i)*1000. 
           end do 
           
           apr='-t_t-' 
c           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 
           close (unit=41) 
        end if
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 pf(14)=pf_t(i-1)+t_coef*(pf_t(i)-pf_t(i-1))

c
	 end if

	 end do
	if(kpr.eq.1)print *,' from SHAPE 14',pf(14)

       return 
       end 

