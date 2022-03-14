	subroutine ids_prof_jintrac()

        integer :: pulse, run
        real*8 :: coeff = 1.d0

!        open(unit=2,file='jetto_ids.dat',form='formatted',action='read')

        read(49,*)
        read(49,*) pulse
        read(49,*)
        read(49,*) run

!        close(2)

        write(*,*) 'jetto_ids: pulse, run =',pulse,run
        

	call wr_prof_astra_bs(pulse, run, coeff)
        call wr_prof_astra_sigma(pulse, run, coeff)	
	call wr_prof_astra_nb(pulse, run, coeff)
	call wr_prof_astra_ecd(pulse, run, coeff)
	call wr_prof_astra_te(pulse, run, coeff)
	call wr_prof_astra_ti(pulse, run, coeff)
	call wr_prof_astra_ne(pulse, run, coeff)
	call wr_prof_astra_ndt(pulse, run, coeff)
	call wr_prof_astra_zeff(pulse, run, coeff)
	call wr_prof_astra_pres(pulse, run, coeff)
	return
    end

	    subroutine ids_prof_jetto()

        integer :: pulse, run
        real*8 :: coeff
    
        integer   ::  ih_imas
        common /c_imas_is/ih_imas
        common /c_jetto_ids/pulse_c,run_c

!        open(unit=2,file='jetto_ids.dat',form='formatted',action='read')

  !      read(49,*)
  !      read(49,*) pulse
        pulse=pulse_c
!        read(49,*)
!        read(49,*) run
        run=run_c

!        close(2)

        write(*,*) 'jetto_ids: pulse, run =',pulse,run
        write(*,*) 'jetto_ids: k_jetto =',ih_imas


       if(ih_imas.eq.0)return
       
        coeff = 1.d-7
	call wr_prof_astra_bs(pulse, run, coeff)
	
	coeff = 1.d0
        call wr_prof_astra_sigma(pulse, run, coeff)
        
        coeff = 1.d-7
	call wr_prof_astra_nb(pulse, run, coeff)
	
	coeff = 1.d-7
	call wr_prof_astra_ecd(pulse, run, coeff)
	
	coeff = 1.d0
	call wr_prof_astra_te(pulse, run, coeff)
	
	coeff = 1.d0
	call wr_prof_astra_ti(pulse, run, coeff)
	
	coeff = 1.d-19
	call wr_prof_astra_ne(pulse, run, coeff)
	
	coeff = 1.d-19
	call wr_prof_astra_ndt(pulse, run, coeff)
	
	coeff = 1.d0
	call wr_prof_astra_zeff(pulse, run, coeff)
	
	coeff = 1.d0 ! Calculated in DINA in [Pa]
	call wr_prof_astra_pres(pulse, run, coeff) 
	return
    end

	subroutine wr_prof_astra_bs(pulse, run, coeff)

	use ids_schemas
    use ids_routines	

	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 
    include 'imas_interface.inc'
	

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
	
	if(kpr.eq.1)print *,' tpl_dir	 nnb n_tb==',tpl_dir,nn_b,n_tb
	
	
    do it=1,nt
	  t_tb(it) = cp%time(it)*1.d3
	  nr = size(cp%profiles_1d(it)%j_bootstrap)
	  te0_tb(1:nr,it) = cp%profiles_1d(it)%j_bootstrap(1:nr)*coeff*tpl_dir		
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

	if(kpr.eq.1)print *,' nnb n_tb== coef',nn_b,n_tb,coeff
	
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

    flush(6)

	return
	end
	
	
	
	subroutine wr_prof_astra_nb(pulse, run, coeff)


	use ids_schemas
    use ids_routines	
	
	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 
    include 'imas_interface.inc'

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
    flush(6)
	
! 	call imas_open('ids', pulse, run, idx)
	call imas_open_env('ids', pulse, run, idx,user,'test','3') 
	call ids_get(idx, 'core_sources', cs)
	call imas_close(idx)
	
	nt = size(cs%time)
	if(kpr.eq.1)print *,' nt==',nt
    flush(6)

	it = 1
    nr = size(cs%source(1)%profiles_1d(it)%grid%rho_tor_norm)  
    
    nr=50
    
	if(kpr.eq.1)print *,' nr==',nr
    flush(6)


	poa_b(1:nr) = cs%source(1)%profiles_1d(it)%grid%rho_tor_norm(1:nr)
	
	nn_b = nr
	n_tb = nt
	
	if(kpr.eq.1)print *,' tpl_dir nnb n_tb==',tpl_dir,nn_b,n_tb

        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

    flush(6)

    do it=1,nt
	  t_tb(it) = cs%time(it)*1.d3
	  nr = size(cs%source(1)%profiles_1d(it)%j_parallel)
    !   print *,' it==nr t_tb(it)',it,nr,t_tb(it)
    !flush(6)

	  te0_tb(1:nr,it) = cs%source(1)%profiles_1d(it)%j_parallel(1:nr)*coeff*tpl_dir		

    !   apr='++nb-' 
    !   if(kpr.eq.1)print 71,apr,(te0_tb(iprof,it),iprof=1,nr) 
    !flush(6)

	end do
!       apr='++nb-' 
!       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 
!    flush(6)

        call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)

	call ids_deallocate(cs)
	 

       apr='++nb-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 
    flush(6)

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
    include 'imas_interface.inc'

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
	
	if(kpr.eq.1)print *,' tpl_dir nnb n_tb==',tpl_dir,nn_b,n_tb

    do it=1,nt
	  t_tb(it) = cs%time(it)*1.d3
	  nr = size(cs%source(2)%profiles_1d(it)%j_parallel)
	  te0_tb(1:nr,it) = cs%source(2)%profiles_1d(it)%j_parallel(1:nr)*coeff*tpl_dir	
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


	if(kpr.eq.1)print *,' TE pulse, run==',pulse, run

	
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
	 
       apr='++t_tb-' 
       if(kpr.eq.1)print 71,apr,(t_tb(it),it=1,nt) 

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
       apr='++ndt2-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,n_tb-1),iprof=1,nr) 

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

	if(kpr.eq.1)print *,' nnb n_tb coeff==',nn_b,n_tb, coeff
	
    do it=1,nt
	  t_tb(it) = cp%time(it)*1.d3
	  nr = size(cp%profiles_1d(it)%electrons%density)
	  te0_tb(1:nr,it) = cp%profiles_1d(it)%electrons%density(1:nr)*1.d-19
	end do

	
        apr='++poa-' 
       if(kpr.eq.1)print 71,apr,(poa_b(i),i=1,nr) 

       apr='++N_e-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,2),iprof=1,nr) 
       apr='++N_e2-' 
       if(kpr.eq.1)print 71,apr,(te0_tb(iprof,n_tb-1),iprof=1,nr) 	
	
	
 	    call prof_sort(nn_b,n_tb,te0_tb,t_tb,kpr)
   
	
	call ids_deallocate(cp)
	 


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


	    subroutine equil_data()

        integer :: pulse, run
        real*8 :: coeff
    
        integer   ::  ih_imas
        common /c_imas_is/ih_imas
        common /c_jetto_ids/pulse_c,run_c
        common /c_tran_times/tt_dina_c

!        open(unit=2,file='jetto_ids.dat',form='formatted',action='read')

  !      read(49,*)
  !      read(49,*) pulse
        pulse=pulse_c
!        read(49,*)
!        read(49,*) run
        run=run_c

!        close(2)

        write(*,*) 'equil_data= tt_dina_c ',tt_dina_c
        write(*,*) 'jetto_ids: pulse, run =',pulse,run
        write(*,*) 'jetto_ids: k_jetto =',ih_imas


    if(ih_imas.eq.0)return
    	coeff = 1.d0 !
	    call equil_data_c(pulse, run, coeff, tt_dina_c) 
	return
    end

	subroutine equil_data_c(pulse, run, coeff, tt_dina)


	use ids_schemas
    use ids_routines	
	
	include 'double.inc'
 	include 'parf0' 
 	include 'parf_mike' 
    include 'imas_interface.inc'
      
	character *20 apr,filename

    type (ids_em_coupling)  :: em_coupling0
    type (ids_equilibrium) :: equilibrium0, equilibrium
    type (ids_pf_active)   :: pf_active0, pf_active
    type (ids_pf_passive)   :: pf_passive0, pf_passive
    type (ids_core_profiles)   :: core_profiles0,core_profiles

    integer :: pulse, run, idx0
	integer :: it, ir, nt, nr ,kpr
	real(ids_real) ::time_get

    real(ids_real) :: pstab(npo), pptab(npo),fptab(npo)
    real(ids_real),parameter :: pi = 3.14159265358979323846
    real(ids_real) :: coef_ppx,coef_pffx,pmu0,tokc
    real(ids_real) :: tpl,rs0,tt,rmag,zmag
	integer :: n,npf0,ncam0
    integer,parameter :: npf = 15, ncam = 100
	integer,parameter :: npfa = 12, npfx = npf-npfa
    real(ids_real) :: vchopper(npf),pf(npf),tcam(ncam),dmn(npo)

      common/ge5/kpr
      
      character (len=255) :: user
      call getenv("USER", user)
		
		
!	return
		
		
	call imas_open_env('ids', pulse, run, idx0,user,'test','3') 




interpol = 1

time_get=tt_dina*1.e-3

write(*,*) 'get slice time_get =', time_get
flush(6)

call ids_get_slice(idx0,"em_coupling",em_coupling0, time_get, interpol)
call ids_get_slice(idx0,"equilibrium",equilibrium0, time_get, interpol)
call ids_get_slice(idx0,"pf_active",pf_active0, time_get, interpol)
call ids_get_slice(idx0,"pf_passive",pf_passive0, time_get, interpol)
call ids_get_slice(idx0,"core_profiles",core_profiles0, time_get, interpol)

write(*,*) 'Finished reading the prescribed IDS'



     its = 1
     
	tt = equilibrium0%time_slice(its)%time
	tpl = equilibrium0%time_slice(its)%global_quantities%ip
	n = size(equilibrium0%time_slice(its)%profiles_1d%rho_tor_norm)
	pstab(1:n) = equilibrium0%time_slice(its)%profiles_1d%rho_tor_norm(1:n)
	
	dmn(1:n)=core_profiles0%profiles_1d(its)%grid%psi(1:n)
	
	rs0=equilibrium0%vacuum_toroidal_field%r0
	rmag=equilibrium0%time_slice(its)%global_quantities%magnetic_axis%r ![m]
    zmag=equilibrium0%time_slice(its)%global_quantities%magnetic_axis%z ![m]

		 print *,' ++tt tpl==',tt,tpl

	
	
	pmu0=4.d0*pi*1.d-7
    coef_ppx=1./(2*pi)/(rs0)*10./pmu0
    coef_pffx=1./(2*pi)*0.5d0*(rs0)*10.
    
    print *,' coef_ppx coef_pffx rs0 pmu0=',coef_ppx,coef_pffx,rs0,pmu0
    
!    equilibrium%time_slice(CurTimeStep)%profiles_1d%dpressure_dpsi(1:n) = coef_ppx*pptab(1:n)
!    equilibrium%time_slice(CurTimeStep)%profiles_1d %f_df_dpsi(1:n) = coef_pffx*fptab(1:n)

	pptab(1:n) = equilibrium0%time_slice(its)%profiles_1d%dpressure_dpsi(1:n)/coef_ppx
	
	fptab(1:n) = equilibrium0%time_slice(its)%profiles_1d%f_df_dpsi(1:n)/coef_pffx
	
	npf0 = size(pf_active0%coil, 1)
	do i=1,npf0
	  pf(i) =  pf_active0%coil(i)%current%data(1)
	  
	 print *,' i pf==',i,pf(i)
	 
	enddo
	
 	ncam0 = size(pf_passive0%loop, 1)
 	!first 3 passive --> last 3 active
	do i=1,npfx
	  pf(npf0+i) = pf_passive0%loop(i)%current(1)
!	 print *,' i pf==',npf0+i,pf(npf0+i)
	enddo
	tokc=0.
	do i=1,ncam0-npfx
	  tcam(i) = pf_passive0%loop(npfx+i)%current(1)
	  tokc=tokc+tcam(i)
	enddo	
 
 	 print *,' ++ tokc==',tokc
 	 print *,' ++ rmag zmag==',rmag,zmag

 
nact=size(em_coupling0%mutual_grid_active,2)
print *,'size em_coupling0%mutual_grid_active',nact
npass=size(em_coupling0%mutual_grid_passive,2)
print *,'size em_coupling0%mutual_grid_passive',npass



     call dina_input2(tt,tpl, n,pstab, pptab,fptab &
     & , ncam,tcam, npf,pf,rmag,zmag,dmn)




call imas_close(idx0)


71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      
5001    format(4i4)
5000    format (6(1pe14.6e3))


!    stop

	return
	end

