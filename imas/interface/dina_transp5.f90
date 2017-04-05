subroutine dina_transp5(equilibrium0, core_profiles0, core_profiles)

use ids_schemas
use ids_routines
implicit none


type (ids_equilibrium) :: equilibrium0
type (ids_core_profiles) :: core_profiles0, core_profiles


integer :: i,n,npo

parameter (npo=500)

!integer, parameter :: DP = kind(1.0d0)
real(ids_real) :: ai(npo),qe0(npo),qq0(npo)

real(ids_real) :: c_input1(npo),c_input2(npo)
real(ids_real) :: c_output1(npo),c_output2(npo),c_output3(npo)


call ids_copy(core_profiles0,core_profiles)

      call transp50( &
!-----------------------------------  inputs---
     &  c_input1,c_input2, &
!------------------------------------outputs
     &  c_output1,c_output2)


n = size(core_profiles%profiles_1d(1)%grid%rho_tor_norm)


    	qe0=c_output1
    	qq0=c_output2


! !7000	format(1x,1pe14.7)
! 
! open (unit=61,file='dina_transp5.dat',action='read',form='formatted')
! 
! read (61,*)n
! 
! write(*,*) 'dina_transp5, n=,', n
! 
! do i=1,n
! read (61,*) ai(i)
! enddo
! do i=1,n
! read (61,*) qe0(i)
! enddo
! do i=1,n
! read (61,*) qq0(i)
! enddo
! 
! close (61)


! allocate(core_profiles%profiles_1d(1)%grid%rho_tor_norm(n))
!  core_profiles%profiles_1d(1)%grid%rho_tor_norm(1:n) = ai(1:n)

allocate(core_profiles%profiles_1d(1)%electrons%pressure(n))
 core_profiles%profiles_1d(1)%electrons%pressure(1:n) = qe0(1:n)

allocate(core_profiles%profiles_1d(1)%pressure_ion_total(n))
 core_profiles%profiles_1d(1)%pressure_ion_total(1:n) = qq0(1:n)


return
end subroutine
