

	subroutine prof_astra()
	include 'double.inc'
      include 'new_com.inc'

      common
     *  /dfm10/ajf(npo),aje1(npo),aje(npo)
      
      character *20 apr,filename
      
!      return

      kpr_a=kpr

	dt_prof=639.e3-490.e3
	if(tt.ge.490.e3)then
	   tt_prof=tt+dt_prof
	else
	   tt_prof=tt
	end if
      
      kpr=0

     	call prof_astra_sigma(tt_prof,n,sigma_jetto,ai,num,kpr)


	call prof_astra_nb(tt_prof,n,aj0,a,num,kpr)
      
      tt_astra=tt

	call prof_astra_te(tt_prof,n,te0,a,num,kpr)
	call prof_astra_ti(tt_prof,n,tq0,a,num,kpr)
	call prof_astra_zeff(tt_prof,n,zeff,a,num,kpr)
	call prof_astra_ndt(tt_prof,n,pne,a,num,kpr)
      do i=1,n
      pd0(i)=0.5*pne(i)
      pt0(i)=0.5*pne(i)
      end do

	call prof_astra_ne(tt_prof,n,pne,a,num,kpr)


      i_pres=1
      if(i_pres.eq.1)then

!      kpr=1

      do i=1,n
      p(i)=(pd0(i)+pt0(i))*tq0(i)+pne(i)*te0(i)
      end do

      apr='&&pne-' 
      if(kpr.eq.1) print 71,apr,(pne(i),i=1,n) 
      apr='&&pd0-' 
      if(kpr.eq.1) print 71,apr,(pd0(i),i=1,n) 
      apr='&&pt0-' 
      if(kpr.eq.1) print 71,apr,(pt0(i),i=1,n) 

      apr='&& p-' 
      if(kpr.eq.1) print 71,apr,(p(i),i=1,n) 

	call prof_astra_pres(tt_prof,n,p,a,num,kpr)

      apr='++p-' 
      if(kpr.eq.1) print 71,apr,(p(i),i=1,n) 


      do i=1,n
      
!      p(i)=p(i)*1.1
      p_th=(pd0(i)+pt0(i))*tq0(i)+pne(i)*te0(i)

!      ppr(i)=0.1*( p(i)-p_th )/tq0(i)
      ppr(i)=( p(i)-p_th )/tq0(i)
      
      end do

      apr='++pne-' 
      if(kpr.eq.1) print 71,apr,(pne(i),i=1,n) 

      apr='++pd0-' 
      if(kpr.eq.1) print 71,apr,(pd0(i),i=1,n) 
      apr='++ppr-' 
      if(kpr.eq.1) print 71,apr,(ppr(i),i=1,n) 

      end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))


!      kpr=1

      num=5
      if(num.eq.5)then
      
      coef_astra=1.28
	call prof_astra_bs_c(tt_prof,n,aje1,ai,num,kpr)
      do i=1,n
      ajb(i)=aje1(i)*coef_astra
      end do
      
      end if
            
            
      kpr=kpr_a
      
	return
	end

	subroutine prof_astra_bs()
	include 'double.inc'
      include 'new_com.inc'

      common
     *  /dfm10/ajf(npo),aje1(npo),aje(npo)

      coef_astra=1.28
      do i=1,n
      ajb(i)=aje1(i)*coef_astra
      end do
      
	return
	end

	subroutine prof_astra_bs_c(tt,n,te0,a,num,kpr)
	include 'double.inc'

	dimension te0(*),a(*)

 	include 'parf0' 
 	include 'parf_mike' 

	dimension t_t(ntime),te0_t(npo,ntime),poa(npo),ppz(npo)

	character *20 apr,filename


	i_sh=i_sh+1

	if(i_sh.eq.1)then

      n_t=9999
      
!      filename='tin1scenar-7_BS.dat'

      coef=1.d-1
      filename='Jbs_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=1,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           if(kpr.eq.1)print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	if(kpr.eq.1)print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 

	

	do i=1,n_t
           apr='-den_t-' 
c           if(kpr.eq.1)print 71,apr,(den_t(iprof,i),iprof=1,nprof) 
	end do


2000	continue

      nprof=nn 
         
	n_t=k

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(n_t)

       close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))


      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

      i_time=i

	do iprof=1,nn
	ppz(iprof)=te0_t(iprof,i-1)+t_coef*(te0_t(iprof,i)-
     *  te0_t(iprof,i-1))
      ppz(iprof)=ppz(iprof)*coef
	end do

c
	 end if

	 end do

        apr='++poa-' 
 !       if(kpr.eq.1)print 71,apr,(poa(i),i=1,nn) 

      apr='++ppz-' 
!      if(kpr.eq.1)print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))

      end do
      
        apr='++ajb-' 
      if(kpr.eq.1)  print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' i_time tt t_coef==',i_time,tt,t_coef
	
c	read (*,*)

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end

	subroutine prof_astra_sigma(tt,n,te0,a,num,kpr)
	include 'double.inc'

	dimension te0(*),a(*)

 	include 'parf0' 
 	include 'parf_mike' 

	dimension t_t(ntime),te0_t(npo,ntime),poa(npo),ppz(npo)

	character *20 apr,filename


	i_sh=i_sh+1

	if(i_sh.eq.1)then

      n_t=9999
      
!      filename='tin1scenar-7_BS.dat'

      coef=1.d-0
      filename='Sigm_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=1,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           	do iprof=1,nn
	       te0_t(iprof,i)=dabs(te0_t(iprof,i))
            end do
            
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           if(kpr.eq.1)print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	if(kpr.eq.1)print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 

	

	do i=1,n_t
           apr='-den_t-' 
c           if(kpr.eq.1)print 71,apr,(den_t(iprof,i),iprof=1,nprof) 
	end do


2000	continue

      nprof=nn 
         
	n_t=k

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(n_t)

       close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))


      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

      i_time=i

	do iprof=1,nn
	ppz(iprof)=te0_t(iprof,i-1)+t_coef*(te0_t(iprof,i)-
     *  te0_t(iprof,i-1))
      ppz(iprof)=ppz(iprof)*coef
	end do

c
	 end if

	 end do

        apr='++poa-' 
 !       if(kpr.eq.1)print 71,apr,(poa(i),i=1,nn) 

      apr='++ppz-' 
      if(kpr.eq.1)print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
      
	do i=2,n
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++sigma-' 
      if(kpr.eq.1)  print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' i_time tt t_coef==',i_time,tt,t_coef
	
c	read (*,*)

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end


	subroutine prof_astra_nb(tt,n,te0,a,num,kpr)
	include 'double.inc'

	dimension te0(*),a(*)

 	include 'parf0' 
 	include 'parf_mike' 

	dimension t_t(ntime),te0_t(npo,ntime),poa(npo),ppz(npo)

	character *20 apr,filename


	i_sh=i_sh+1

	if(i_sh.eq.1)then

      n_t=9999
      
!      filename='tin1scenar-7_BS.dat'

      coef=1.d-1
      filename='Jznb_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=1,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           if(kpr.eq.1)print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	if(kpr.eq.1)print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 

	

	do i=1,n_t
           apr='-den_t-' 
c           if(kpr.eq.1)print 71,apr,(den_t(iprof,i),iprof=1,nprof) 
	end do


2000	continue

      nprof=nn 
         
	n_t=k

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(n_t)

       close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))


      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

      i_time=i

	do iprof=1,nn
	ppz(iprof)=te0_t(iprof,i-1)+t_coef*(te0_t(iprof,i)-
     *  te0_t(iprof,i-1))
      ppz(iprof)=ppz(iprof)*coef
	end do

c
	 end if

	 end do

        apr='++poa-' 
 !       if(kpr.eq.1)print 71,apr,(poa(i),i=1,nn) 

      apr='++ppz-' 
!      if(kpr.eq.1)print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++aj0_b-' 
      if(kpr.eq.1)  print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' i_time tt t_coef==',i_time,tt,t_coef
	
c	read (*,*)

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end


	subroutine prof_astra_te(tt,n,te0,a,num,kpr)
	include 'double.inc'

	dimension te0(*),a(*)

 	include 'parf0' 
 	include 'parf_mike' 

	dimension t_t(ntime),te0_t(npo,ntime),poa(npo),ppz(npo)

	character *20 apr,filename


	i_sh=i_sh+1

	if(i_sh.eq.1)then

      n_t=9999
      
!      filename='tin1scenar-7_TE.dat'
      filename='Te_prof.txt'
      coef=1.d3

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=1,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           if(kpr.eq.1)print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	if(kpr.eq.1)print *,' i== nn t_t(i) ',i,nn,t_t(i)
	
!	  apr='++poa-' 
!        if(kpr.eq.1)print 71,apr,(poa(ii),ii=1,nn) 


c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 




2000	continue

      nprof=nn 
         
	n_t=k

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(n_t)

       close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

	do i=1,n_t
!           apr='-te0_t-' 
!           if(kpr.eq.1)print 71,apr,(te0_t(iprof,i),iprof=1,nprof) 
	end do

!      stop

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

      i_time=i

	do iprof=1,nn
	ppz(iprof)=te0_t(iprof,i-1)+t_coef*(te0_t(iprof,i)-
     *  te0_t(iprof,i-1))
      ppz(iprof)=ppz(iprof)*coef
	end do

c
	 end if

	 end do


      apr='++ppz-' 
      if(kpr.eq.1)print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++te0-' 
      if(kpr.eq.1)  print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' i_time n_t tt t_coef==',i_time,n_t,tt,t_coef
	
c	read (*,*)

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end

	subroutine prof_astra_ti(tt,n,te0,a,num,kpr)
	include 'double.inc'

	dimension te0(*),a(*)

 	include 'parf0' 
 	include 'parf_mike' 

	dimension t_t(ntime),te0_t(npo,ntime),poa(npo),ppz(npo)

	character *20 apr,filename


	i_sh=i_sh+1



	if(i_sh.eq.1)then

      n_t=9999
      
!      filename='tin1scenar-7_TI.dat'
      filename='Ti_prof.txt'
      coef=1.d3

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=1,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           if(kpr.eq.1)print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	if(kpr.eq.1)print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 

	

	do i=1,n_t
           apr='-den_t-' 
c           if(kpr.eq.1)print 71,apr,(den_t(iprof,i),iprof=1,nprof) 
	end do


2000	continue

      nprof=nn 
         
	n_t=k

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(n_t)

       close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))


      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

      i_time=i

	do iprof=1,nn
	ppz(iprof)=te0_t(iprof,i-1)+t_coef*(te0_t(iprof,i)-
     *  te0_t(iprof,i-1))
      ppz(iprof)=ppz(iprof)*coef
	end do

c
	 end if

	 end do

        apr='++poa-' 
!       if(kpr.eq.1)print 71,apr,(poa(i),i=1,nn) 
      apr='++ppz-' 
!     if(kpr.eq.1)print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++tq0-' 
      if(kpr.eq.1)  print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' i_time tt t_coef==',i_time,tt,t_coef
	
c	read (*,*)

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end


	subroutine prof_astra_ne(tt,n,te0,a,num,kpr)
	include 'double.inc'

	dimension te0(*),a(*)

 	include 'parf0' 
 	include 'parf_mike' 

	dimension t_t(ntime),te0_t(npo,ntime),poa(npo),ppz(npo)

	character *20 apr,filename


	i_sh=i_sh+1


	if(i_sh.eq.1)then

      n_t=9999
!      filename='tin1scenar-7_NE.dat'
      coef=1.d0
      filename='Ne_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=1,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           if(kpr.eq.1)print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	if(kpr.eq.1)print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 

	



2000	continue

      nprof=nn 
         
	n_t=k

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2',n_t,t_t(1),t_t(n_t)

       close (unit=41) 
        end if

	do i=300,305
           apr='-den_t-' 
!          if(kpr.eq.1)print 71,apr,(te0_t(iprof,i),iprof=1,nprof) 
	end do



71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      i_time=0
      
      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

      i_time=i

	do iprof=1,nn
	ppz(iprof)=te0_t(iprof,i-1)+t_coef*(te0_t(iprof,i)-
     *  te0_t(iprof,i-1))
      ppz(iprof)=ppz(iprof)*coef
	end do

c
	 end if

	 end do

        apr='++poa-' 
!        if(kpr.eq.1)print 71,apr,(poa(i),i=1,nn) 
      apr='++ppz-' 
!      if(kpr.eq.1)print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++pne-' 
       if(kpr.eq.1) print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' i_time tt t_coef==',i_time,tt,t_coef
	
!	stop
	
c	read (*,*)

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end

	subroutine prof_astra_ndt(tt,n,te0,a,num,kpr)
	include 'double.inc'

	dimension te0(*),a(*)

 	include 'parf0' 
 	include 'parf_mike' 

	dimension t_t(ntime),te0_t(npo,ntime),poa(npo),ppz(npo)

	character *20 apr,filename


	i_sh=i_sh+1


	if(i_sh.eq.1)then

      n_t=9999
!      filename='tin1scenar-7_NE.dat'
      coef=1.d0
      filename='Ndt_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=1,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           if(kpr.eq.1)print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	if(kpr.eq.1)print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 

	



2000	continue

      nprof=nn 
         
	n_t=k

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(n_t)

       close (unit=41) 
        end if

	do i=300,305
           apr='-den_t-' 
 !          print 71,apr,(te0_t(iprof,i),iprof=1,nprof) 
	end do



71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      i_time=0
      
      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

      i_time=i

	do iprof=1,nn
	ppz(iprof)=te0_t(iprof,i-1)+t_coef*(te0_t(iprof,i)-
     *  te0_t(iprof,i-1))
      ppz(iprof)=ppz(iprof)*coef
	end do

c
	 end if

	 end do

        apr='++poa-' 
!       if(kpr.eq.1)print 71,apr,(poa(i),i=1,nn) 
      apr='++ppz-' 
!     if(kpr.eq.1)print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++ndt-' 
       if(kpr.eq.1) print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' i_time tt t_coef==',i_time,tt,t_coef
	
!	stop
	
c	read (*,*)

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end


	subroutine prof_astra_zeff(tt,n,te0,a,num,kpr)
	include 'double.inc'

	dimension te0(*),a(*)

 	include 'parf0' 
 	include 'parf_mike' 

	dimension t_t(ntime),te0_t(npo,ntime),poa(npo),ppz(npo)

	character *20 apr,filename


	i_sh=i_sh+1


	if(i_sh.eq.1)then

      n_t=9999
!      filename='tin1scenar-7_NE.dat'
      coef=1.d0
      filename='Zeff_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=1,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           if(kpr.eq.1)print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	if(kpr.eq.1)print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 

	



2000	continue

      nprof=nn 
         
	n_t=k

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(n_t)

       close (unit=41) 
        end if

	do i=300,305
           apr='-den_t-' 
 !          if(kpr.eq.1)print 71,apr,(te0_t(iprof,i),iprof=1,nprof) 
	end do



71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      i_time=0
      
      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

      i_time=i

	do iprof=1,nn
	ppz(iprof)=te0_t(iprof,i-1)+t_coef*(te0_t(iprof,i)-
     *  te0_t(iprof,i-1))
      ppz(iprof)=ppz(iprof)*coef
	end do

c
	 end if

	 end do

        apr='++poa-' 
!        if(kpr.eq.1)print 71,apr,(poa(i),i=1,nn) 
      apr='++ppz-' 
!      if(kpr.eq.1)print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++zeff-' 
      if(kpr.eq.1)print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' i_time tt t_coef==',i_time,tt,t_coef
	
!	stop
	
c	read (*,*)

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end




	subroutine prof_astra_pres(tt,n,te0,a,num,kpr)
	include 'double.inc'

	dimension te0(*),a(*)

 	include 'parf0' 
 	include 'parf_mike' 

	dimension t_t(ntime),te0_t(npo,ntime),poa(npo),ppz(npo)

	character *20 apr,filename


	i_sh=i_sh+1


	if(i_sh.eq.1)then

      n_t=9999

      coef=1.d6/1.6d0
!     filename='Ptot_prof.txt'

      coef=1.d0/1.6d0
      filename='pres_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=1,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           if(kpr.eq.1)print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	if(kpr.eq.1)print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 

	



2000	continue

      nprof=nn 
         
	n_t=k

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2',n_t,t_t(1),t_t(n_t)

       close (unit=41) 
        end if

	do i=300,305
           apr='-den_t-' 
 !          print 71,apr,(te0_t(iprof,i),iprof=1,nprof) 
	end do



71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      i_time=0
      
      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

      i_time=i

	do iprof=1,nn
	ppz(iprof)=te0_t(iprof,i-1)+t_coef*(te0_t(iprof,i)-
     *  te0_t(iprof,i-1))
      ppz(iprof)=ppz(iprof)*coef
	end do

c
	 end if

	 end do

        apr='++poa-' 
!        if(kpr.eq.1)print 71,apr,(poa(i),i=1,nn) 
      apr='++ppz-' 
      if(kpr.eq.1)print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++p-' 
       if(kpr.eq.1) print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' coef==',coef
	if(kpr.eq.1)print *,' i_time tt t_coef==',i_time,tt,t_coef
	
!	stop
	
c	read (*,*)

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end
