subroutine dina_transp_energy(equilibrium0, core_profiles0, core_sources0, core_profiles, core_sources)

use ids_schemas
use ids_routines
implicit none


type (ids_equilibrium) :: equilibrium0
type (ids_core_profiles) :: core_profiles0, core_profiles
type (ids_core_sources) :: core_sources0, core_sources

integer :: i,m,n,npo

parameter (npo=500)

!integer, parameter :: DP = kind(1.0d0)
real(ids_real) :: ai(npo),te0(npo),tq0(npo)

real(ids_real) :: c_input1(npo),c_input2(npo)
real(ids_real) :: c_output1(npo),c_output2(npo),c_output3(npo)
real(ids_real) :: qe0(npo),qq0(npo)


call ids_copy(core_profiles0,core_profiles)
call ids_copy(core_sources0,core_sources)


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

n = size(core_sources0%source(1)%profiles_1d(1)%grid%rho_tor_norm)

 qe0(1:n) = core_sources0%source(1)%profiles_1d(1)%electrons%energy(1:n)
 qq0(1:n) = core_sources0%source(1)%profiles_1d(1)%total_ion_energy(1:n)
 c_input1(1:n)=qe0(1:n)
 c_input2(1:n)=qq0(1:n)

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

return
end subroutine

