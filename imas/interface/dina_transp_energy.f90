subroutine dina_transp_energy(equilibrium0, core_profiles0, core_sources0, bndcond_in, core_profiles, core_sources)

use ids_schemas
use ids_routines
implicit none


type (ids_equilibrium) :: equilibrium0
type (ids_core_profiles) :: core_profiles0, core_profiles
type (ids_core_sources) :: core_sources0, core_sources
type (ids_transport_solver_numerics) :: bndcond_in

integer :: i,m,n,npo

parameter (npo=500)

!integer, parameter :: DP = kind(1.0d0)
real(ids_real) :: ai(npo),te0(npo),tq0(npo)

real(ids_real) :: c_input1(npo),c_input2(npo)
real(ids_real) :: c_output1(npo),c_output2(npo),c_output3(npo)
real(ids_real) :: qe0(npo),qq0(npo)
 
 real *8 te_b2,ti_b2

      common /cc_tran1/te_b2,ti_b2

	character *20 apr



call ids_copy(core_profiles0,core_profiles)
call ids_copy(core_sources0,core_sources)


n = size(core_sources0%source(1)%profiles_1d(1)%grid%rho_tor_norm)


!Maybe *1.d-3 needed? Remember that below entire profile assignment will overwrite n-th value
 if (associated(bndcond_in%solver_1d)) then
     write(*,*) 'dina_transp_energy : boundary conditions are found'
  te0(n) = bndcond_in%solver_1d(1)%equation(1)%boundary_condition(1)%value(1)
  tq0(n) = bndcond_in%solver_1d(1)%equation(3)%boundary_condition(1)%value(1)
!  
      write(*,*) 'te0(n) tq0(n)= ', te0(n), tq0(n)
! 

    te_b2= te0(n)
    ti_b2=tq0(n)
    
 end if


    print *,' --te_b2 ti_b2',te_b2,ti_b2
    print *,' ENERGY== n',n

! Transp1
 te0(1:n) = core_profiles%profiles_1d(1)%electrons%temperature(1:n)
 tq0(1:n) = core_profiles%profiles_1d(1)%t_i_average(1:n)
 
      apr='--te0-' 
      print 71,apr,(te0(i),i=1,n) 
      apr='--tq0-' 
      print 71,apr,(tq0(i),i=1,n) 
    71 FORMAT(20X,A20/,(6(1pE10.3)))
       

    

 qe0(1:n) = core_sources%source(1)%profiles_1d(1)%electrons%energy(1:n)
 qq0(1:n) = core_sources%source(1)%profiles_1d(1)%total_ion_energy(1:n)
 
 c_input1(1:n)=qe0(1:n)
 c_input2(1:n)=qq0(1:n)

      apr='--qe0-' 
      print 71,apr,(qe0(i),i=1,n) 

      apr='--qq0-' 
      print 71,apr,(qq0(i),i=1,n) 



! do i=1,n
!   c_input1(i)=qe0(i)
!   c_input2(i)=qq0(i)
! enddo

      call transp10( &
!-----------------------------------  inputs---
     &  c_input1,c_input2, & 
!------------------------------------outputs
     &  c_output1,c_output2)



    	te0=c_output1
    	tq0=c_output2


!7000	format(1x,1pe14.7)

! open (unit=61,file='dina_transp1.dat',action='read',form='formatted')
! 
! read (61,*)n
! 
! write(*,*) 'dina_transp1, n=,', n
! 
! do i=1,n
! read (61,*) ai(i)
! enddo
! do i=1,n
! read (61,*) te0(i)
! enddo
! do i=1,n
! read (61,*) tq0(i)
! enddo
! 
! close (61)


! if (.not.allocated(core_profiles%profiles_1d(1)%grid%rho_tor_norm)) then
!     allocate(core_profiles%profiles_1d(1)%grid%rho_tor_norm(n))
! end if
! if (.not.allocated(core_profiles%profiles_1d(1)%t_e)) then
    allocate(core_profiles%profiles_1d(1)%electrons%temperature(n))
! end if
! if (.not.allocated(core_profiles%profiles_1d(1)%t_i_average)) then
     allocate(core_profiles%profiles_1d(1)%t_i_average(n))
! end if


!  core_profiles%profiles_1d(1)%grid%rho_tor_norm(1:n) = ai(1:n)
 core_profiles%profiles_1d(1)%electrons%temperature(1:n) = te0(1:n)
 core_profiles%profiles_1d(1)%t_i_average(1:n) = tq0(1:n)

!if (allocated(core_profiles%profiles_1d(1)%ion)) then
m = size(core_profiles%profiles_1d(1)%ion)
do i=1,m
	allocate(core_profiles%profiles_1d(1)%ion(m)%temperature(n))
	core_profiles%profiles_1d(1)%ion(m)%temperature(1:n) = tq0(1:n)
end do
!end if


! Transp1
 te0(1:n) = core_profiles%profiles_1d(1)%electrons%temperature(1:n)
 !tq0(1:n) = core_profiles%profiles_1d(1)%ion(m)%temperature(1:n)
 tq0(1:n) = core_profiles%profiles_1d(1)%t_i_average(1:n)
 
      apr='--te0-' 
      print 71,apr,(te0(i),i=1,n) 
      apr='--tq0-' 
      print 71,apr,(tQ0(i),i=1,n) 

 qe0(1:n) = core_sources%source(1)%profiles_1d(1)%electrons%energy(1:n)
 qq0(1:n) = core_sources%source(1)%profiles_1d(1)%total_ion_energy(1:n)



      apr='--qe0-' 
      print 71,apr,(qe0(i),i=1,n) 

      apr='--qq0-' 
      print 71,apr,(qq0(i),i=1,n) 



    return


return
end subroutine

