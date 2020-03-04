subroutine dina_transp_density_test0(equilibrium0, core_profiles0, core_profiles)
!subroutine dina_transp_density(equilibrium0, core_profiles0,  core_profiles)

use ids_schemas
use ids_routines
implicit none


type (ids_equilibrium) :: equilibrium0
type (ids_core_profiles) :: core_profiles0, core_profiles
!type (ids_core_sources) :: core_sources0

integer :: i,n,n2,npo

parameter (npo=500)

!integer, parameter :: DP = kind(1.0d0)
real(ids_real) :: ai(npo),pne(npo),pd0(npo),pt0(npo)
real(ids_real), dimension(:) :: qqe(npo), qqd(npo), qqt(npo)

real(ids_real) :: c_input1(npo),c_input2(npo)
real(ids_real) :: c_output1(npo),c_output2(npo),c_output3(npo)

real(ids_real) :: tt

	character *20 apr



!tt = core_sources0%source(1)%profiles_1d(1)%time

!qqe(1:n) = core_sources0%source(1)%profiles_1d(1)%electrons%particles(1:n)
!qqd(1:n) = core_sources0%source(1)%profiles_1d(1)%ion(1)%particles(1:n)
!qqt(1:n) = core_sources0%source(1)%profiles_1d(1)%ion(2)%particles(1:n)

call ids_copy(core_profiles0,core_profiles)

n = size(core_profiles%profiles_1d(1)%grid%rho_tor_norm)

 print *,' transp20== n',n

!Transp2
 pne(1:n) = core_profiles%profiles_1d(1)%electrons%density(1:n)*1.d-19
 pd0(1:n) = core_profiles%profiles_1d(1)%ion(1)%density(1:n)*1.d-19
 pt0(1:n) = core_profiles%profiles_1d(1)%ion(2)%density(1:n)*1.d-19

      apr='--pne-' 
      print 71,apr,(pne(i),i=1,n) 
      apr='--pd0-' 
      print 71,apr,(pd0(i),i=1,n) 
      apr='--pt0-' 
      print 71,apr,(pt0(i),i=1,n) 
   71 FORMAT(20X,A20/,(6(1pE10.3)))
        

    do i=1,npo
    c_input1(i)=0.1
    c_input2(i)=0.3
    end do

!pd0(1:n)=core_sources0%source(1)%profiles_1d(1)%ion(1)%particles(1:n)
!pt0(1:n)=core_sources0%source(1)%profiles_1d(1)%ion(2)%particles(1:n)
    
      apr='--sd0-' 
      print 71,apr,(pd0(i),i=1,n) 
      apr='--st0-' 
      print 71,apr,(pt0(i),i=1,n) 
    
      call transp20( &
!-----------------------------------  inputs---
     &  c_input1,c_input2, &
!------------------------------------outputs
     &  c_output1,c_output2,c_output3)




!7000	format(1x,1pe14.7)

! open (unit=61,file='dina_transp2.dat',action='read',form='formatted')
! 
! read (61,*)n2



! write(*,*) 'dina_transp2, n,n2=,', n, n2
! 
! do i=1,n2
! read (61,*) ai(i)
! enddo
! do i=1,n2
! read (61,*) pne(i)
! enddo
! do i=1,n2
! read (61,*) pd0(i)
! enddo
! do i=1,n2
! read (61,*) pt0(i)
! enddo
! 
! close (61)


! do i=1,n
!     	pd0(i)=c_output1(i)
!     	pt0(i)=c_output2(i)
!     	pne(i)=c_output3(i)
! enddo

    	pd0=c_output1
    	pt0=c_output2
    	pne=c_output3

!allocate(core_profiles%profiles_1d(1)%grid%rho_tor_norm(n))
 !core_profiles%profiles_1d(1)%grid%rho_tor_norm(1:n) = ai(1:n)

!Electrons
allocate(core_profiles%profiles_1d(1)%electrons%density(n))
 core_profiles%profiles_1d(1)%electrons%density(1:n) = pne(1:n)*1.d19

!if (.not. allocated(core_profiles%profiles_1d(1)%ion)) then
   allocate(core_profiles%profiles_1d(1)%ion(2))
!end if

! Deuterium
allocate(core_profiles%profiles_1d(1)%ion(1)%element(1))
 core_profiles%profiles_1d(1)%ion(1)%element(1)%a = 2
 core_profiles%profiles_1d(1)%ion(1)%z_ion = 1
 core_profiles%profiles_1d(1)%ion(1)%element(1)%z_n = 1
!core_profiles%profiles_1d(1)%ion(1)%label = 'D+'
! if (.not. allocated(core_profiles%profiles_1d(1)%ion(1)%n_i)) then
allocate(core_profiles%profiles_1d(1)%ion(1)%density(n))
! end if
 core_profiles%profiles_1d(1)%ion(1)%density(1:n) = pd0(1:n)*1.d19

! Tritium
allocate(core_profiles%profiles_1d(1)%ion(2)%element(1))
 core_profiles%profiles_1d(1)%ion(2)%element(1)%a = 3
 core_profiles%profiles_1d(1)%ion(2)%z_ion = 1
 core_profiles%profiles_1d(1)%ion(2)%element(1)%z_n = 1
!core_profiles%profiles_1d(1)%ion(2)%label = 'T+'
allocate(core_profiles%profiles_1d(1)%ion(2)%density(n))
 core_profiles%profiles_1d(1)%ion(2)%density(1:n) = pt0(1:n)*1.d19
 
 pd0(1:n) = core_profiles%profiles_1d(1)%ion(1)%density(1:n)*1.d-19
 pt0(1:n) = core_profiles%profiles_1d(1)%ion(2)%density(1:n)*1.d-19

      apr='--pd0-' 
      print 71,apr,(pd0(i),i=1,n) 
      apr='--pt0-' 
      print 71,apr,(pt0(i),i=1,n) 
 
 print *,' end transp_density'

return
end subroutine
