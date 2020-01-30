subroutine astra_transp_src(equilibrium0, core_profiles0, core_sources)

use ids_schemas
use ids_routines
implicit none


type (ids_equilibrium) :: equilibrium0
type (ids_core_profiles) :: core_profiles0
type (ids_core_sources) :: core_sources

integer :: i,n,n2,npo

! used npo as kint in transp2
parameter (npo=200)

!integer, parameter :: DP = kind(1.0d0)
real(ids_real) :: ai(npo),pne(npo),pd0(npo),pt0(npo)

real(ids_real) :: c_input1(npo),c_input2(npo)
real(ids_real) :: c_output1(npo),c_output2(npo),c_output3(npo)
real(ids_real) :: te0(npo),tq0(npo)

real(ids_real) :: tt


n = size(core_profiles0%profiles_1d(1)%grid%rho_tor_norm)
ai(1:n) = core_profiles0%profiles_1d(1)%grid%rho_tor_norm(1:n)


tt = core_profiles0%time(1)


! te0(1:n) = core_profiles0%profiles_1d(1)%electrons%temperature(1:n)
! tq0(1:n) = core_profiles0%profiles_1d(1)%t_i_average(1:n)

 

      call transp7( &
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


  core_sources%ids_properties%homogeneous_time = 1

   
allocate(core_sources%time(1))   
    
    
allocate(core_sources%source(1))    
allocate(core_sources%source(1)%profiles_1d(1)) 
 
allocate(core_sources%source(1)%profiles_1d(1)%grid%rho_tor_norm(n))
 core_sources%source(1)%profiles_1d(1)%grid%rho_tor_norm(1:n) = ai(1:n)

!Electrons
allocate(core_sources%source(1)%profiles_1d(1)%electrons%particles(n))
 core_sources%source(1)%profiles_1d(1)%electrons%particles(1:n) = pne(1:n)


! Ions 
allocate(core_sources%source(1)%profiles_1d(1)%ion(2))

! Deuterium
allocate(core_sources%source(1)%profiles_1d(1)%ion(1)%element(1))
 core_sources%source(1)%profiles_1d(1)%ion(1)%element(1)%a = 2
 core_sources%source(1)%profiles_1d(1)%ion(1)%z_ion = 1
 core_sources%source(1)%profiles_1d(1)%ion(1)%element(1)%z_n = 1
!core_sources%source(1)%profiles_1d(1)%ion(1)%label = 'D+'
allocate(core_sources%source(1)%profiles_1d(1)%ion(1)%particles(n))
 core_sources%source(1)%profiles_1d(1)%ion(1)%particles(1:n) = pd0(1:n)

! Tritium
allocate(core_sources%source(1)%profiles_1d(1)%ion(2)%element(1))
 core_sources%source(1)%profiles_1d(1)%ion(2)%element(1)%a = 3
 core_sources%source(1)%profiles_1d(1)%ion(2)%z_ion = 1
 core_sources%source(1)%profiles_1d(1)%ion(2)%element(1)%z_n = 1
!core_sources%source(1)%profiles_1d(1)%ion(2)%label = 'T+'
allocate(core_sources%source(1)%profiles_1d(1)%ion(2)%particles(n))
 core_sources%source(1)%profiles_1d(1)%ion(2)%particles(1:n) = pt0(1:n)

 
    core_sources%source(1)%profiles_1d(1)%time = tt
    core_sources%time(1) = tt ![s]
    
    
return
end subroutine
