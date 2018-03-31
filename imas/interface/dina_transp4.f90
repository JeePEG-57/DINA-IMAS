subroutine dina_transp4(equilibrium0, core_profiles0, core_profiles)

use ids_schemas
use ids_routines
implicit none


type (ids_equilibrium) :: equilibrium0
type (ids_core_profiles) :: core_profiles0, core_profiles


integer :: i,n,npo

parameter (npo=500)

!integer, parameter :: DP = kind(1.0d0)
real(ids_real) :: ai(npo),aj0(npo)

real(ids_real) :: c_input1(npo),c_input2(npo)
real(ids_real) :: c_output1(npo),c_output2(npo),c_output3(npo)


call ids_copy(core_profiles0,core_profiles)


      call transp40( &
!-----------------------------------  inputs---
     &  c_input1,c_input2, &
!------------------------------------outputs
     &  c_output1,c_output2)

n = size(core_profiles%profiles_1d(1)%grid%rho_tor_norm)

    	aj0=c_output1*1.d7

!7000	format(1x,1pe14.7)

! open (unit=61,file='dina_transp4.dat',action='read',form='formatted')
! 
! read (61,*)n
! 
! write(*,*) 'dina_transp4, n=,', n
! 
! do i=1,n
! read (61,*) ai(i)
! enddo
! do i=1,n
! read (61,*) aj0(i)
! enddo
! 
! 
! close (61)

! allocate(core_profiles%profiles_1d(1)%grid%rho_tor_norm(n))
!  core_profiles%profiles_1d(1)%grid%rho_tor_norm(1:n) = ai(1:n)

allocate(core_profiles%profiles_1d(1)%j_non_inductive(n))
 core_profiles%profiles_1d(1)%j_non_inductive(1:n) = aj0(1:n) + core_profiles%profiles_1d(1)%j_bootstrap(1:n)



return
end subroutine
