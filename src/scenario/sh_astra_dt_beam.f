

	subroutine prof_astra()
	include 'double.inc'
      include 'new_com.inc'

      common
     *  /dfm10/ajf(npo),aje1(npo),aje(npo)
      
      character *20 apr,filename
      
!      return

      i_en=i_en+1

      kpr_a=kpr

      if(n.eq.0)then
      n=10
      do i=1,n
      a(i)=float(i-1)/float(n-1)
      end do
      
      end if
      
      if(i_en.eq.1)then

          open (unit=40,file='elm.dat',form='formatted') 
          read (40,*) 
          read (40,*)tt_elm
          read (40,*) 

      if(tt_elm. le.0.d0)then
      tt_elm=dabs(tt_elm)
      k_elm=1
      end if
      

	  close (40)
      
      end if
      
      if(kpr.eq.1)print *,' kpr k_elm==',kpr,k_elm
      if(kpr.eq.1)print *,' tt_elm tt_dw=',tt_elm,tt_dw
      
      tt_prof=tt
	if(tt.ge.tt_elm-tay)then
	   tt_prof=tt_elm-tay
      end if
      
	if(tt.ge.tt_dw)then
	   tt_prof=tt+tt_elm-tt_dw
      end if

	if(k_elm.eq.1)then
!	   tt_prof=tt-(75.d0-70.d0)*1.d3	   
      end if
      
      if(tt_prof.le.1.d-1)then
      tt_prof=1.d-1
      end if
      
!      kpr=0
      apr='+ai-' 
      if(kpr.eq.1)print 71,apr,(ai(i),i=1,n) 

     	call prof_astra_sigma(tt_prof,n,sigma_jetto,ai,num,kpr)


	call prof_astra_nb(tt_prof,n,aj0,a,num,kpr)

	call prof_astra_ecd(tt_prof,n,ajae,a,num,kpr)
      
      tt_astra=tt

	call prof_astra_te(tt_prof,n,te0,a,num,kpr)
	call prof_astra_ti(tt_prof,n,tq0,a,num,kpr)

      apr='&&te-' 
      if(kpr.eq.1) print 71,apr,(te0(i),i=1,n) 
      apr='&&ti-' 
      if(kpr.eq.1) print 71,apr,(tq0(i),i=1,n) 

	call prof_astra_zeff(tt_prof,n,zeff,a,num,kpr)
	call prof_astra_ndt(tt_prof,n,pne,a,num,kpr)
      do i=1,n
      pd0(i)=0.5*pne(i)
      pt0(i)=0.5*pne(i)
      end do

	call prof_astra_ne(tt_prof,n,pne,a,num,kpr)

!	print*,'from astra_prof_HL'
      if(kpr.eq.1)print*,'tt tt_prof=',tt,tt_prof


      i_pres=1
      if(i_pres.eq.1)then

!      kpr=1

      do i=1,n
      p(i)=(pd0(i)+pt0(i))*tq0(i)+pne(i)*te0(i)
      end do

      apr='&&pne-' 
 !     if(kpr.eq.1) print 71,apr,(pne(i),i=1,n) 
      apr='&&pd0-' 
 !     if(kpr.eq.1) print 71,apr,(pd0(i),i=1,n) 
      apr='&&pt0-' 
      if(kpr.eq.1) print 71,apr,(pt0(i),i=1,n) 

      apr='&& p-' 
      if(kpr.eq.-1) print 71,apr,(p(i),i=1,n) 

	call prof_astra_pres(tt_prof,n,p,a,num,kpr)

      apr='++p-' 
      if(kpr.eq.1) print 71,apr,(p(i),i=1,n) 


      do i=1,n
      
!      p(i)=p(i)*1.1
      p_th=(pd0(i)+pt0(i))*tq0(i)+pne(i)*te0(i)

!      ppr(i)=0.1*( p(i)-p_th )/tq0(i)
!      ppr(i)=( p(i)-p_th )/tq0(i)
      
      end do

      do i=1,n
      p(i)=p(i)*200.*1.e-6
      end do

      apr='++pne-' 
 !     if(kpr.eq.1) print 71,apr,(pne(i),i=1,n) 

      apr='++pd0-' 
!      if(kpr.eq.1) print 71,apr,(pd0(i),i=1,n) 
      apr='++ppr-' 
!      if(kpr.eq.1) print 71,apr,(ppr(i),i=1,n) 

      end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))


!      kpr=1

      num=5
      if(num.eq.5)then
      
ccccccc      coef_astra=1.28
      coef_astra=1.
	call prof_astra_bs_c(tt_prof,n,aje1,ai,num,kpr)
      do i=1,n
      ajb(i)=aje1(i)*coef_astra
      end do
      
      end if
            
            
      kpr=kpr_a
      
 !     stop
!      print *,' end'
      
	return
	end

	subroutine prof_astra_bs()
	include 'double.inc'
      include 'new_com.inc'

      common
     *  /dfm10/ajf(npo),aje1(npo),aje(npo)

ccccccc      coef_astra=1.28
      coef_astra=1.
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
      
      common /c_imas_ajb/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_ajb1/nn_b,n_tb
      
      common /c_imas_is/ih_imas
      
      equivalence (nn_b,nn)
      equivalence (n_tb,n_t)

      equivalence (poa_b,poa)
      equivalence (t_tb,t_t)
      equivalence (te0_tb,te0_t)

	character *20 apr,filename


	i_sh=i_sh+1
	if(i_sh.eq.1)then
	i_sh=i_sh+ih_imas
      end if

      coef=1.d-1

	if(i_sh.eq.1)then

      n_t=9999
      
!      filename='tin1scenar-7_BS.dat'

      filename='Jbs_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=2,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           print 71,apr,(t_t(i),i=1,n_t) 

	

	do i=1,n_t
           apr='-den_t-' 
c           print 71,apr,(den_t(iprof,i),iprof=1,nprof) 
	end do


2000	continue

      nprof=nn 
         
	n_t=k

      t_t(1)=0.d0

      i=2
	do iprof=1,nn
	te0_t(iprof,i-1)=te0_t(iprof,i)
	end do

	n_t=n_t+1
      i=n_t
      t_t(i)=t_t(i-1)+1000.e3
      
	do iprof=1,nn
	te0_t(iprof,i)=te0_t(iprof,i-1)
	end do

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(2)
	if(kpr.eq.1)print *,' ++ n_t== t_t(n-1) t_t(n) ',t_t(n_t-1),t_t(n_t)

       close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

	if(ih_imas.eq.0)then
	return
      end if

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
 !       print 71,apr,(poa(i),i=1,nn) 

      apr='++ppz-' 
!      print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))

      end do
      
      apr='++ajb-' 
      if(kpr.eq.1)  print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' n t_1 t_2==',n,t_t(i_time-1),t_t(i_time)
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
      common /c_imas_sigma/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_sigma1/nn_b,n_tb
      common /c_imas_is/ih_imas
      
      equivalence (nn_b,nn)
      equivalence (poa_b,poa)
      equivalence (n_tb,n_t)
      equivalence (t_tb,t_t)
      equivalence (te0_tb,te0_t)

	character *20 apr,filename


	i_sh=i_sh+1
	if(i_sh.eq.1)then
	i_sh=i_sh+ih_imas
      end if

    	if(kpr.eq.1)print *,' nn_b,n_tb ',nn_b,n_tb
    	if(kpr.eq.1)print *,' nn,n_t ',nn,n_t
    	if(kpr.eq.1)print *,' ih_imas ,i_sh ',ih_imas,i_sh
    	



      coef=1.d-0
	if(i_sh.eq.1)then

      n_t=9999
      
!      filename='tin1scenar-7_BS.dat'

      filename='Sigm_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=2,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           	do iprof=1,nn
	       te0_t(iprof,i)=dabs(te0_t(iprof,i))
            end do
            
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           print 71,apr,(t_t(i),i=1,n_t) 

	

	do i=1,n_t
           apr='-den_t-' 
c           print 71,apr,(den_t(iprof,i),iprof=1,nprof) 
	end do


2000	continue

      nprof=nn 
         
	n_t=k

      t_t(1)=0.d0

      i=2
	do iprof=1,nn
	te0_t(iprof,i-1)=te0_t(iprof,i)
	end do

	n_t=n_t+1
      i=n_t
      t_t(i)=t_t(i-1)+1000.e3
      
	do iprof=1,nn
	te0_t(iprof,i)=te0_t(iprof,i-1)
	end do

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(2)
	if(kpr.eq.1)print *,' ++ n_t== t_t(n-1) t_t(n) ',t_t(n_t-1),t_t(n_t)

       close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))
	if(ih_imas.eq.0)then
	return
      end if


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
        print 71,apr,(poa(i),i=1,nn) 

      apr='++ppz_sigma-' 
      if(kpr.eq.1)print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
      
	do i=2,n
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++a-' 
      if(kpr.eq.1)  print 71,apr,(a(i),i=1,n) 
        apr='++sigma-' 
      if(kpr.eq.1)  print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' n t_1 t_2==',n,t_t(i_time-1),t_t(i_time)
	if(kpr.eq.1)print *,' i_time tt t_coef==',i_time,tt,t_coef
    	if(kpr.eq.1)print *,' nn,n ',nn,n
	
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
      common /c_imas_nb/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_nb1/nn_b,n_tb
      common /c_imas_is/ih_imas
      
      equivalence (nn_b,nn)
      equivalence (n_tb,n_t)
      
      equivalence (poa_b,poa)
      equivalence (t_tb,t_t)
      equivalence (te0_tb,te0_t)

	character *20 apr,filename


	i_sh=i_sh+1
	if(i_sh.eq.1)then
	i_sh=i_sh+ih_imas
      end if

      coef=1.d-1
	if(i_sh.eq.1)then

      n_t=9999
      
!      filename='tin1scenar-7_BS.dat'

      filename='Jznb_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=2,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           print 71,apr,(t_t(i),i=1,n_t) 

	

	do i=1,n_t
           apr='-den_t-' 
c           print 71,apr,(den_t(iprof,i),iprof=1,nprof) 
	end do


2000	continue

      nprof=nn 
         
	n_t=k

      t_t(1)=0.d0

      i=2
	do iprof=1,nn
	te0_t(iprof,i-1)=te0_t(iprof,i)
	end do

	n_t=n_t+1
      i=n_t
      t_t(i)=t_t(i-1)+1000.e3
      
	do iprof=1,nn
	te0_t(iprof,i)=te0_t(iprof,i-1)
	end do

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(2)
	if(kpr.eq.1)print *,' ++ n_t== t_t(n-1) t_t(n) ',t_t(n_t-1),t_t(n_t)

       close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

	if(ih_imas.eq.0)then
	return
      end if

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
 !       print 71,apr,(poa(i),i=1,nn) 

      apr='++ppz-' 
!      print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++aj0_b-' 
      if(kpr.eq.1)  print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' n t_1 t_2==',n,t_t(i_time-1),t_t(i_time)
	if(kpr.eq.1)print *,' i_time tt t_coef==',i_time,tt,t_coef
	
c	read (*,*)

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end

	subroutine prof_astra_ecd(tt,n,te0,a,num,kpr)
	include 'double.inc'

	dimension te0(*),a(*)

 	include 'parf0' 
 	include 'parf_mike' 

	dimension t_t(ntime),te0_t(npo,ntime),poa(npo),ppz(npo)
      common /c_imas_ecd/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_ecd1/nn_b,n_tb
      common /c_imas_is/ih_imas
      
      equivalence (nn_b,nn)
      equivalence (n_tb,n_t)
      
      equivalence (poa_b,poa)
      equivalence (t_tb,t_t)
      equivalence (te0_tb,te0_t)

	character *20 apr,filename


	i_sh=i_sh+1
	if(i_sh.eq.1)then
	i_sh=i_sh+ih_imas
      end if

      coef=1.d-1
	if(i_sh.eq.1)then

      n_t=9999
      
!      filename='tin1scenar-7_BS.dat'

      filename='Jzec_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=2,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           print 71,apr,(t_t(i),i=1,n_t) 

	

	do i=1,n_t
           apr='-den_t-' 
c           print 71,apr,(den_t(iprof,i),iprof=1,nprof) 
	end do


2000	continue

      nprof=nn 
         
	n_t=k

      t_t(1)=0.d0

      i=2
	do iprof=1,nn
	te0_t(iprof,i-1)=te0_t(iprof,i)
	end do

	n_t=n_t+1
      i=n_t
      t_t(i)=t_t(i-1)+1000.e3
      
	do iprof=1,nn
	te0_t(iprof,i)=te0_t(iprof,i-1)
	end do

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(2)
	if(kpr.eq.1)print *,' ++ n_t== t_t(n-1) t_t(n) ',t_t(n_t-1),t_t(n_t)

       close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))
	if(ih_imas.eq.0)then
	return
      end if


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
 !       print 71,apr,(poa(i),i=1,nn) 

      apr='++ppz-' 
!      print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++aj0_ecd-' 
      if(kpr.eq.1)  print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' n t_1 t_2==',n,t_t(i_time-1),t_t(i_time)
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
      common /c_imas_te/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_te1/nn_b,n_tb
      common /c_imas_is/ih_imas
      
      equivalence (nn_b,nn)
      equivalence (n_tb,n_t)
      
      equivalence (poa_b,poa)
      equivalence (t_tb,t_t)
      equivalence (te0_tb,te0_t)

	character *20 apr,filename


	i_sh=i_sh+1
	if(i_sh.eq.1)then
	i_sh=i_sh+ih_imas
      end if

      coef=1.d3
	if(i_sh.eq.1)then

      n_t=9999
      
!      filename='tin1scenar-7_TE.dat'
      filename='Te_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=2,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	print *,' i== nn t_t(i) ',i,nn,t_t(i)
	
!	  apr='++poa-' 
!        print 71,apr,(poa(ii),ii=1,nn) 


c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           print 71,apr,(t_t(i),i=1,n_t) 




2000	continue

      nprof=nn 
         
	n_t=k

      t_t(1)=0.d0

      i=2
	do iprof=1,nn
	te0_t(iprof,i-1)=te0_t(iprof,i)
	end do

	n_t=n_t+1
      i=n_t
      t_t(i)=t_t(i-1)+1000.e3
      
	do iprof=1,nn
	te0_t(iprof,i)=te0_t(iprof,i-1)
	end do

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(2)
	if(kpr.eq.1)print *,' ++ n_t== t_t(n-1) t_t(n) ',t_t(n_t-1),t_t(n_t)

       close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))
	if(ih_imas.eq.0)then
	return
      end if

	do i=1,n_t
!           apr='-te0_t-' 
!           print 71,apr,(te0_t(iprof,i),iprof=1,nprof) 
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
      if(kpr.eq.-1)print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++te0-' 
      if(kpr.eq.1)  print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' n t_1 t_2==',n,t_t(i_time-1),t_t(i_time)
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
      common /c_imas_ti/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_ti1/nn_b,n_tb
      common /c_imas_is/ih_imas
      
      equivalence (nn_b,nn)
      equivalence (n_tb,n_t)
      
      equivalence (poa_b,poa)
      equivalence (t_tb,t_t)
      equivalence (te0_tb,te0_t)

	character *20 apr,filename


	i_sh=i_sh+1

	if(i_sh.eq.1)then
	i_sh=i_sh+ih_imas
      end if

      coef=1.d3

	if(i_sh.eq.1)then

      n_t=9999
      
!      filename='tin1scenar-7_TI.dat'
      filename='Ti_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=2,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           print 71,apr,(t_t(i),i=1,n_t) 

	

	do i=1,n_t
           apr='-den_t-' 
c           print 71,apr,(den_t(iprof,i),iprof=1,nprof) 
	end do


2000	continue

      nprof=nn 
         
	n_t=k

      t_t(1)=0.d0

      i=2
	do iprof=1,nn
	te0_t(iprof,i-1)=te0_t(iprof,i)
	end do

	n_t=n_t+1
      i=n_t
      t_t(i)=t_t(i-1)+1000.e3
      
	do iprof=1,nn
	te0_t(iprof,i)=te0_t(iprof,i-1)
	end do

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(2)
	if(kpr.eq.1)print *,' ++ n_t== t_t(n-1) t_t(n) ',t_t(n_t-1),t_t(n_t)
       close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))
	if(ih_imas.eq.0)then
	return
      end if


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
 !       print 71,apr,(poa(i),i=1,nn) 
      apr='++ppz-' 
 !     print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++tq0-' 
      if(kpr.eq.1)  print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' n t_1 t_2==',n,t_t(i_time-1),t_t(i_time)
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
      common /c_imas_ne/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_ne1/nn_b,n_tb
      common /c_imas_is/ih_imas
      
      equivalence (nn_b,nn)
      equivalence (n_tb,n_t)
      
      equivalence (poa_b,poa)
      equivalence (t_tb,t_t)
      equivalence (te0_tb,te0_t)

	character *20 apr,filename


	i_sh=i_sh+1
	if(i_sh.eq.1)then
	i_sh=i_sh+ih_imas
      end if

      coef=1.d0

	if(i_sh.eq.1)then

      n_t=9999
!      filename='tin1scenar-7_NE.dat'
      filename='Ne_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=2,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           print 71,apr,(t_t(i),i=1,n_t) 

	



2000	continue

      nprof=nn 
         
	n_t=k

      t_t(1)=0.d0

      i=2
	do iprof=1,nn
	te0_t(iprof,i-1)=te0_t(iprof,i)
	end do

	n_t=n_t+1
      i=n_t
      t_t(i)=t_t(i-1)+1000.e3
      
	do iprof=1,nn
	te0_t(iprof,i)=te0_t(iprof,i-1)
	end do

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(2)
	if(kpr.eq.1)print *,' ++ n_t== t_t(n-1) t_t(n) ',t_t(n_t-1),t_t(n_t)

       close (unit=41) 
        end if

	do i=300,305
           apr='-den_t-' 
 !          print 71,apr,(te0_t(iprof,i),iprof=1,nprof) 
	end do



71	FORMAT(20X,A8/,(6(1X,1PE10.3)))
	if(ih_imas.eq.0)then
	return
      end if

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
!        print 71,apr,(poa(i),i=1,nn) 
      apr='++ppz-' 
!      print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++pne-' 
       if(kpr.eq.1) print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' n t_1 t_2==',n,t_t(i_time-1),t_t(i_time)
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
      common /c_imas_ndt/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_ndt1/nn_b,n_tb
      common /c_imas_is/ih_imas
      
      equivalence (nn_b,nn)
      equivalence (n_tb,n_t)
      
      equivalence (poa_b,poa)
      equivalence (t_tb,t_t)
      equivalence (te0_tb,te0_t)

	character *20 apr,filename


	i_sh=i_sh+1
	if(i_sh.eq.1)then
	i_sh=i_sh+ih_imas
      end if

      coef=1.d0

	if(i_sh.eq.1)then

      n_t=9999
!      filename='tin1scenar-7_NE.dat'
      filename='Ndt_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=2,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           print 71,apr,(t_t(i),i=1,n_t) 

	



2000	continue

      nprof=nn 
         
	n_t=k

      t_t(1)=0.d0

      i=2
	do iprof=1,nn
	te0_t(iprof,i-1)=te0_t(iprof,i)
	end do

	n_t=n_t+1
      i=n_t
      t_t(i)=t_t(i-1)+1000.e3
      
	do iprof=1,nn
	te0_t(iprof,i)=te0_t(iprof,i-1)
	end do

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(2)
	if(kpr.eq.1)print *,' ++ n_t== t_t(n-1) t_t(n) ',t_t(n_t-1),t_t(n_t)
       close (unit=41) 
        end if

	do i=300,305
           apr='-den_t-' 
 !          print 71,apr,(te0_t(iprof,i),iprof=1,nprof) 
	end do



71	FORMAT(20X,A8/,(6(1X,1PE10.3)))
	if(ih_imas.eq.0)then
	return
      end if

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
 !       print 71,apr,(poa(i),i=1,nn) 
      apr='++ppz-' 
 !     print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++ndt-' 
       if(kpr.eq.1) print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' n t_1 t_2==',n,t_t(i_time-1),t_t(i_time)
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
      common /c_imas_zeff/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_zeff1/nn_b,n_tb
      common /c_imas_is/ih_imas
      
      equivalence (nn_b,nn)
      equivalence (n_tb,n_t)
      
      equivalence (poa_b,poa)
      equivalence (t_tb,t_t)
      equivalence (te0_tb,te0_t)

	character *20 apr,filename


	i_sh=i_sh+1

	if(i_sh.eq.1)then
	i_sh=i_sh+ih_imas
      end if

      coef=1.d0
	if(i_sh.eq.1)then

      n_t=9999
!      filename='tin1scenar-7_NE.dat'
      filename='Zeff_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=2,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           print 71,apr,(t_t(i),i=1,n_t) 

	



2000	continue

      nprof=nn 
         
	n_t=k

      t_t(1)=0.d0

      i=2
	do iprof=1,nn
	te0_t(iprof,i-1)=te0_t(iprof,i)
	end do

	n_t=n_t+1
      i=n_t
      t_t(i)=t_t(i-1)+1000.e3
      
	do iprof=1,nn
	te0_t(iprof,i)=te0_t(iprof,i-1)
	end do

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(2)
	if(kpr.eq.1)print *,' ++ n_t== t_t(n-1) t_t(n) ',t_t(n_t-1),t_t(n_t)

       close (unit=41) 
        end if

	do i=300,305
           apr='-den_t-' 
 !          print 71,apr,(te0_t(iprof,i),iprof=1,nprof) 
	end do



71	FORMAT(20X,A8/,(6(1X,1PE10.3)))
	if(ih_imas.eq.0)then
	return
      end if

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
!        print 71,apr,(poa(i),i=1,nn) 
      apr='++ppz-' 
!      print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++zeff-' 
      if(kpr.eq.1)print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' n t_1 t_2==',n,t_t(i_time-1),t_t(i_time)
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
      common /c_imas_pres/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_pres1/nn_b,n_tb
       
      common /c_imas_is/ih_imas
       
      equivalence (nn_b,nn)
      equivalence (n_tb,n_t)
      
      equivalence (nn_b,nn)
      equivalence (n_tb,n_t)

      equivalence (poa_b,poa)
      equivalence (t_tb,t_t)
      equivalence (te0_tb,te0_t)

	character *20 apr,filename


	i_sh=i_sh+1

	if(i_sh.eq.1)then
	i_sh=i_sh+ih_imas
      end if

      coef=1.d6/1.6d0
	if(i_sh.eq.1)then

      n_t=9999

!     filename='Ptot_prof.txt'

      coef=1.d0/1.6d0
      filename='pres_prof.txt'

c-------
           open (unit=41,file=filename,form='formatted') 
          
           read (41,*)nn,(poa(ii),ii=1,nn)

           k=0
           do i=2,n_t 
           read (41,*,err=2000,end=2000)t_t(i),
     *    (te0_t(iprof,i),iprof=1,nn)
           
           k=k+1
           t_t(i)=t_t(i)*1.d3
           
           apr='-pne_t-' 
c           print 71,apr,(pne_t(iprof,i),iprof=1,n) 


!	print *,' i== n t_t(i) ',i,n,t_t(i)

c	read (*,*)
           end do 
           

c	read (*,*)

           apr='-t_t-' 
!           print 71,apr,(t_t(i),i=1,n_t) 

	



2000	continue

      nprof=nn 
         
	n_t=k

      t_t(1)=0.d0

      i=2
	do iprof=1,nn
	te0_t(iprof,i-1)=te0_t(iprof,i)
	end do

	n_t=n_t+1
      i=n_t
      t_t(i)=t_t(i-1)+1000.e3
      
	do iprof=1,nn
	te0_t(iprof,i)=te0_t(iprof,i-1)
	end do

	if(kpr.eq.1)print *,' nprof n_t== t_t ',nprof,n_t,t_t(n_t)

!	t_t(1)=-0.1
!	t_t(n_t)=1.d5
c
	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(2)
	if(kpr.eq.1)print *,' ++ n_t== t_t(n-1) t_t(n) ',t_t(n_t-1),t_t(n_t)

       close (unit=41) 
        end if

	do i=300,305
           apr='-den_t-' 
 !          print 71,apr,(te0_t(iprof,i),iprof=1,nprof) 
	end do



71	FORMAT(20X,A8/,(6(1X,1PE10.3)))


	if(ih_imas.eq.0)then
	return
      end if

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
!        print 71,apr,(poa(i),i=1,nn) 
      apr='++ppz-' 
      !print 71,apr,(ppz(i),i=1,nn) 

      te0(1)=ppz(1)
      te0(n)=ppz(nn)
	do i=2,n-1
!           call feeti(nn,ppz,te0(i),poa,a(i))
           call linear(nn,ppz,te0(i),poa,a(i))
      end do
      
        apr='++p-' 
       if(kpr.eq.1) print 71,apr,(te0(i),i=1,n) 

	if(kpr.eq.1)print *,' coef==',coef
	if(kpr.eq.1)print *,' n t_1 t_2==',n,t_t(i_time-1),t_t(i_time)
	if(kpr.eq.1)print *,' i_time tt t_coef==',i_time,tt,t_coef
	
!	stop
	
c	read (*,*)

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end



