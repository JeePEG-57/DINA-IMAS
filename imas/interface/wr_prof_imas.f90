	subroutine ids_prof_jintrac()

        integer :: pulse, run

        open(unit=2,file='jetto_ids.dat',form='formatted',action='read')

        read(2,*)
        read(2,*) pulse
        read(2,*)
        read(2,*) run

        close(2)

        write(*,*) 'jetto_ids: pulse, run =',pulse,run

	call wr_prof_astra_bs(pulse, run, 1.d0)
        call wr_prof_astra_sigma(pulse, run, 1.d0)	
	call wr_prof_astra_nb(pulse, run, 1.d0)
	call wr_prof_astra_ecd(pulse, run, 1.d0)
	call wr_prof_astra_te(pulse, run, 1.d0)
	call wr_prof_astra_ti(pulse, run, 1.d0)
	call wr_prof_astra_ne(pulse, run, 1.d0)
	call wr_prof_astra_ndt(pulse, run, 1.d0)
	call wr_prof_astra_zeff(pulse, run, 1.d0)
	call wr_prof_astra_pres(pulse, run, 1.d0)
	return
    end

	subroutine ids_prof_jetto()

        integer :: pulse, run

        open(unit=2,file='jetto_ids.dat',form='formatted',action='read')

        read(2,*)
        read(2,*) pulse
        read(2,*)
        read(2,*) run

        close(2)

        write(*,*) 'jetto_ids: pulse, run =',pulse,run

	call wr_prof_astra_bs(pulse, run, 1.d-7)
        call wr_prof_astra_sigma(pulse, run, 1.d0)	
	call wr_prof_astra_nb(pulse, run, 1.d-7)
	call wr_prof_astra_ecd(pulse, run, 1.d-7)
	call wr_prof_astra_te(pulse, run, 1.d0)
	call wr_prof_astra_ti(pulse, run, 1.d0)
	call wr_prof_astra_ne(pulse, run, 1.d-19)
	call wr_prof_astra_ndt(pulse, run, 1.d-19)
	call wr_prof_astra_zeff(pulse, run, 1.d0)
	call wr_prof_astra_pres(pulse, run, 1.0d0) ! Calculated in DINA in [Pa]
	return
    end

	subroutine wr_prof_astra_bs(pulse, run, coeff)

	use ids_schemas
    use ids_routines	

	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 
	

     common /c_imas_ajb/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_ajb1/nn_b,n_tb
     
	character *20 apr,filename

	type (ids_core_profiles) :: cp	
    integer :: pulse, run, idx
	integer :: it, ir, nt, nr, kpr

	real(ids_real) :: coeff
	
      common/ge5/kpr
          
      character (len=255) :: user
      call getenv("USER", user)
	
!    kpr=1
	
! 	call imas_open('ids', pulse, run, idx)
	call imas_open_env('ids', pulse, run, idx,user,'test','3') 
	call ids_get(idx, 'core_profiles', cp)
	call imas_close(idx)
	
	nt = size(cp%time)

	it = 1
    nr = size(cp%profiles_1d(it)%grid%rho_tor_norm)  
	poa_b(1:nr) = cp%profiles_1d(it)%grid%rho_tor_norm(1:nr)
	
	nn_b = nr
	n_tb = nt	
	
	if(kpr.eq.1)print *,' nnb n_tb==',nn_b,n_tb
	
	
    do it=1,nt
	  t_tb(it) = cp%time(it)*1.d3
	  nr = size(cp%profiles_1d(it)%j_bootstrap)
	  te0_tb(1:nr,it) = cp%profiles_1d(it)%j_bootstrap(1:nr)*coeff	
	end do
    
    call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)
    
	call ids_deallocate(cp)
	 
        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

       apr='++ajb-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      
5001    format(4i4)
5000    format (6(1pe14.6e3))


	return
	end
	
	
	
	
	subroutine wr_prof_astra_sigma(pulse, run, coeff)


	use ids_schemas
    use ids_routines	

	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 
	

      common /c_imas_sigma/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_sigma1/nn_b,n_tb
      
	character *20 apr,filename

	type (ids_core_profiles) :: cp	
    integer :: pulse, run, idx
	integer :: it, ir, nt, nr, kpr
      common/ge5/kpr
      
      character (len=255) :: user
      call getenv("USER", user)
	
!     kpr=1
	
! 	call imas_open('ids', pulse, run, idx)
	call imas_open_env('ids', pulse, run, idx,user,'test','3') 
	call ids_get(idx, 'core_profiles', cp)
	call imas_close(idx)
	
	nt = size(cp%time)

	it = 1
    nr = size(cp%profiles_1d(it)%grid%rho_tor_norm)  
	poa_b(1:nr) = cp%profiles_1d(it)%grid%rho_tor_norm(1:nr)
	
	nn_b = nr
	n_tb = nt	

	if(kpr.eq.1)print *,' nnb n_tb==',nn_b,n_tb
	
    do it=1,nt
	  t_tb(it) = cp%time(it)*1.d3
	  nr = size(cp%profiles_1d(it)%conductivity_parallel)
	  te0_tb(1:nr,it) = cp%profiles_1d(it)%conductivity_parallel(1:nr)*coeff	
	end do
    
	    call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)

	call ids_deallocate(cp)
	 
        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

       apr='++sigma-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      
5001    format(4i4)
5000    format (6(1pe14.6e3))


	return
	end
	
	
	
	subroutine wr_prof_astra_nb(pulse, run, coeff)


	use ids_schemas
    use ids_routines	
	
	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 

      common /c_imas_nb/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_nb1/nn_b,n_tb
      
	character *20 apr,filename

	type (ids_core_sources) :: cs	
    integer :: pulse, run, idx
	integer :: it, ir, nt, nr, kpr
      common/ge5/kpr
      
      character (len=255) :: user
      call getenv("USER", user)	

!	    kpr=1


	if(kpr.eq.1)print *,' imas open== pulse run ',pulse,run
	
! 	call imas_open('ids', pulse, run, idx)
	call imas_open_env('ids', pulse, run, idx,user,'test','3') 
	call ids_get(idx, 'core_sources', cs)
	call imas_close(idx)
	
	nt = size(cs%time)
	if(kpr.eq.1)print *,' nt==',nt

	it = 1
    nr = size(cs%source(1)%profiles_1d(it)%grid%rho_tor_norm)  

	if(kpr.eq.1)print *,' nr==',nr


	poa_b(1:nr) = cs%source(1)%profiles_1d(it)%grid%rho_tor_norm(1:nr)
	
	nn_b = nr
	n_tb = nt
	
	if(kpr.eq.1)print *,' nnb n_tb==',nn_b,n_tb

    do it=1,nt
	  t_tb(it) = cs%time(it)*1.d3
	  nr = size(cs%source(1)%profiles_1d(it)%j_parallel)
	  te0_tb(1:nr,it) = cs%source(1)%profiles_1d(it)%j_parallel(1:nr)*coeff	
	end do

        call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)

	call ids_deallocate(cs)
	 
        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

       apr='++nb-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      
5001    format(4i4)
5000    format (6(1pe14.6e3))


	return
	end

	
	subroutine wr_prof_astra_ecd(pulse, run, coeff)


	use ids_schemas
    use ids_routines	
	
	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 

      common /c_imas_ecd/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_ecd1/nn_b,n_tb
      
	character *20 apr,filename

	type (ids_core_sources) :: cs	
    integer :: pulse, run, idx
	integer :: it, ir, nt, nr ,kpr
      common/ge5/kpr
      
      character (len=255) :: user
      call getenv("USER", user)
		
!	    kpr=1

	
! 	call imas_open('ids', pulse, run, idx)
	call imas_open_env('ids', pulse, run, idx,user,'test','3') 
	call ids_get(idx, 'core_sources', cs)
	call imas_close(idx)
	
	nt = size(cs%time)

	it = 1
    nr = size(cs%source(2)%profiles_1d(it)%grid%rho_tor_norm)  
	poa_b(1:nr) = cs%source(2)%profiles_1d(it)%grid%rho_tor_norm(1:nr)
	
	nn_b = nr
	n_tb = nt
	
	if(kpr.eq.1)print *,' nnb n_tb==',nn_b,n_tb

    do it=1,nt
	  t_tb(it) = cs%time(it)*1.d3
	  nr = size(cs%source(2)%profiles_1d(it)%j_parallel)
	  te0_tb(1:nr,it) = cs%source(2)%profiles_1d(it)%j_parallel(1:nr)*coeff	
	end do

        call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)

	call ids_deallocate(cs)
	 
        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

       apr='++ecd-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      
5001    format(4i4)
5000    format (6(1pe14.6e3))


	return
	end


	subroutine wr_prof_astra_te(pulse, run, coeff)


	use ids_schemas
    use ids_routines	
	
	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 

      common /c_imas_te/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_te1/nn_b,n_tb
      
	character *20 apr,filename

	type (ids_core_profiles) :: cp	
    integer :: pulse, run, idx
	integer :: it, ir, nt, nr, kpr
      common/ge5/kpr
      
      character (len=255) :: user
      call getenv("USER", user)
		
!	    kpr=1

	
! 	call imas_open('ids', pulse, run, idx)
	call imas_open_env('ids', pulse, run, idx,user,'test','3') 
	call ids_get(idx, 'core_profiles', cp)
	call imas_close(idx)
	
	nt = size(cp%time)

	it = 1
    nr = size(cp%profiles_1d(it)%grid%rho_tor_norm)  
	poa_b(1:nr) = cp%profiles_1d(it)%grid%rho_tor_norm(1:nr)
	
	nn_b = nr
	n_tb = nt	

	if(kpr.eq.1)print *,' nnb n_tb==',nn_b,n_tb
	
    do it=1,nt
	  t_tb(it) = cp%time(it)*1.d3
	  nr = size(cp%profiles_1d(it)%electrons%temperature)
	  te0_tb(1:nr,it) = cp%profiles_1d(it)%electrons%temperature(1:nr)*coeff	
	end do
    
        call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)

	
	call ids_deallocate(cp)
	 
        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

       apr='++te-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      
5001    format(4i4)
5000    format (6(1pe14.6e3))


	return
	end
	
	
	subroutine wr_prof_astra_ti(pulse, run, coeff)


	use ids_schemas
    use ids_routines	
	
	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 

      common /c_imas_ti/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_ti1/nn_b,n_tb
      
	character *20 apr,filename

	type (ids_core_profiles) :: cp	
    integer :: pulse, run, idx
	integer :: it, ir, nt, nr, kpr
      common /ge5/kpr
      
      character (len=255) :: user
      call getenv("USER", user)
		
!	    kpr=1

	
! 	call imas_open('ids', pulse, run, idx)
	call imas_open_env('ids', pulse, run, idx,user,'test','3') 
	call ids_get(idx, 'core_profiles', cp)
	call imas_close(idx)
	
	nt = size(cp%time)

    it = 1	
    nr = size(cp%profiles_1d(it)%grid%rho_tor_norm)  
	poa_b(1:nr) = cp%profiles_1d(it)%grid%rho_tor_norm(1:nr)
	
	nn_b = nr
	n_tb = nt	
	if(kpr.eq.1)print *,' nnb n_tb==',nn_b,n_tb
	
    do it=1,nt
	  t_tb(it) = cp%time(it)*1.d3
	  nr = size(cp%profiles_1d(it)%t_i_average)
	  te0_tb(1:nr,it) = cp%profiles_1d(it)%t_i_average(1:nr)*coeff	
	end do
        call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)

	
	call ids_deallocate(cp)
	 
        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

       apr='++ti-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      
5001    format(4i4)
5000    format (6(1pe14.6e3))


	return
	end
	
	
	subroutine wr_prof_astra_ndt(pulse, run, coeff)


	use ids_schemas
    use ids_routines	
	
	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 

      common /c_imas_ndt/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_ndt1/nn_b,n_tb
      
	character *20 apr,filename

	type (ids_core_profiles) :: cp	
    integer :: pulse, run, idx
	integer :: it, ir, nt, nr , kpr 
      common/ge5/kpr
      
      character (len=255) :: user
      call getenv("USER", user)	
	
!	    kpr=1
	
! 	call imas_open('ids', pulse, run, idx)
	call imas_open_env('ids', pulse, run, idx,user,'test','3') 
	call ids_get(idx, 'core_profiles', cp)
	call imas_close(idx)
	
	nt = size(cp%time)
	
    it = 1
    nr = size(cp%profiles_1d(it)%grid%rho_tor_norm)  
	poa_b(1:nr) = cp%profiles_1d(it)%grid%rho_tor_norm(1:nr)
	
	nn_b = nr
	n_tb = nt	
	if(kpr.eq.1)print *,' nnb n_tb==',nn_b,n_tb
	
    do it=1,nt
	  t_tb(it) = cp%time(it)*1.d3
	  nr = size(cp%profiles_1d(it)%ion(1)%density)
	  te0_tb(1:nr,it) = (cp%profiles_1d(it)%ion(1)%density(1:nr) &
	  & + cp%profiles_1d(it)%ion(2)%density(1:nr))*coeff
	end do
    
        call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)

	
	call ids_deallocate(cp)
	 
        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

       apr='++ndt-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      
5001    format(4i4)
5000    format (6(1pe14.6e3))


	return
	end
	
	
	
	subroutine wr_prof_astra_zeff(pulse, run, coeff)


	use ids_schemas
    use ids_routines	
	
	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 

      common /c_imas_zeff/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_zeff1/nn_b,n_tb
      
	character *20 apr,filename

	type (ids_core_profiles) :: cp	
    integer :: pulse, run, idx
	integer :: it, ir, nt, nr, kpr
      common/ge5/kpr
      
      character (len=255) :: user
      call getenv("USER", user)
		
!	kpr=1
	
! 	call imas_open('ids', pulse, run, idx)
	call imas_open_env('ids', pulse, run, idx,user,'test','3') 
	call ids_get(idx, 'core_profiles', cp)
	call imas_close(idx)
	
	nt = size(cp%time)
	
    it = 1
    nr = size(cp%profiles_1d(it)%grid%rho_tor_norm)  
	poa_b(1:nr) = cp%profiles_1d(it)%grid%rho_tor_norm(1:nr)
	
	nn_b = nr
	n_tb = nt	
	if(kpr.eq.1)print *,' nnb n_tb==',nn_b,n_tb
	
    do it=1,nt
	  t_tb(it) = cp%time(it)*1.d3
	  nr = size(cp%profiles_1d(it)%zeff)
	  te0_tb(1:nr,it) = cp%profiles_1d(it)%zeff(1:nr)*coeff	
	end do
    
	    call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)

	call ids_deallocate(cp)
	 
        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

       apr='++zeff-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      
5001    format(4i4)
5000    format (6(1pe14.6e3))


	return
	end
	
	
	subroutine wr_prof_astra_pres(pulse, run, coeff)


	use ids_schemas
    use ids_routines	
	
	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 

      common /c_imas_pres/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_pres1/nn_b,n_tb
      
	character *20 apr,filename

	type (ids_equilibrium) :: eq	
    integer :: pulse, run, idx
	integer :: it, ir, nt, nr, kpr
      common/ge5/kpr
      
      character (len=255) :: user
      call getenv("USER", user)
	
!     kpr=1
	
! 	call imas_open('ids', pulse, run, idx)
	call imas_open_env('ids', pulse, run, idx,user,'test','3') 
	call ids_get(idx, 'equilibrium', eq)
	call imas_close(idx)
	
	nt = size(eq%time)

	it = 1
    nr = size(eq%time_slice(it)%profiles_1d%rho_tor_norm)  
	poa_b(1:nr) = eq%time_slice(it)%profiles_1d%rho_tor_norm(1:nr)
	
	nn_b = nr
	n_tb = nt	
	if(kpr.eq.1)print *,' nnb n_tb==',nn_b,n_tb
	
    do it=1,nt
	  t_tb(it) = eq%time(it)*1.d3
	  nr = size(eq%time_slice(it)%profiles_1d%pressure)
	  te0_tb(1:nr,it) = eq%time_slice(it)%profiles_1d%pressure(1:nr)*coeff	
	end do
    
	    call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)

	call ids_deallocate(eq)
	 
        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

       apr='++pres-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      
5001    format(4i4)
5000    format (6(1pe14.6e3))


	return
	end
	
	subroutine wr_prof_astra_ne(pulse, run, coeff)


	use ids_schemas
    use ids_routines	
	
	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 

      common /c_imas_ne/t_tb(ntime),te0_tb(npo,ntime),poa_b(npo)
      common /c_imas_ne1/nn_b,n_tb
      
	character *20 apr,filename

	type (ids_core_profiles) :: cp	
    integer :: pulse, run, idx
	integer :: it, ir, nt, nr, kpr
      common/ge5/kpr	
      
      character (len=255) :: user
      call getenv("USER", user)
		
! 	call imas_open('ids', pulse, run, idx)
	call imas_open_env('ids', pulse, run, idx,user,'test','3') 
	call ids_get(idx, 'core_profiles', cp)
	call imas_close(idx)
	
	nt = size(cp%time)

	it = 1
    nr = size(cp%profiles_1d(it)%grid%rho_tor_norm)  
	poa_b(1:nr) = cp%profiles_1d(it)%grid%rho_tor_norm(1:nr)
	
	nn_b = nr
	n_tb = nt	

	if(kpr.eq.1)print *,' nnb n_tb==',nn_b,n_tb
	
    do it=1,nt
	  t_tb(it) = cp%time(it)*1.d3
	  nr = size(cp%profiles_1d(it)%electrons%density)
	  te0_tb(1:nr,it) = cp%profiles_1d(it)%electrons%density(1:nr)*coeff	
	end do

 	    call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)
   
	
	call ids_deallocate(cp)
	 
        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

       apr='++N_e-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      
5001    format(4i4)
5000    format (6(1pe14.6e3))


	return
	end



    subroutine prof_sort(nn,n_t1,te0_t1,t_t1,kpr)
	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 

	dimension te0_t1(npo,*),t_t1(*)

	dimension t_t(ntime),te0_t(npo,ntime)
	     
    t_t(1)=0.d0
	do iprof=1,nn
	te0_t(iprof,1)=te0_t1(iprof,2)
	end do

	do i=1,n_t1
	t_t(i+1)=t_t1(i)
	do iprof=1,nn
	te0_t(iprof,i+1)=te0_t1(iprof,i)
	end do
	end do

	n_t=n_t1+2
	i=n_t
    t_t(i)=t_t(i-1)+1000.e3      
	do iprof=1,nn
	te0_t(iprof,i)=te0_t(iprof,i-1)
	end do


	if(kpr.eq.1)print *,' ++ n_t== t_t1 t_t2 ',n_t,t_t(1),t_t(2)
	if(kpr.eq.1)print *,' ++ n_t== t_t(n-1) t_t(n) ',t_t(n_t-1),t_t(n_t)

    n_t1=n_t

	do i=1,n_t1
	t_t1(i)=t_t(i)
	do iprof=1,nn
	te0_t1(iprof,i)=te0_t(iprof,i)
	end do
	end do

	if(kpr.eq.1)print *,' && n_t1== t_t1 t_t2 ',n_t1,t_t1(1),t_t1(2)
	if(kpr.eq.1)print *,' && n_t1== t_t(n-1) t_t(n) ',t_t1(n_t-1),t_t1(n_t)

    return
    end

