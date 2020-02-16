subroutine dina_transp_heatsrc(equilibrium0, core_sources0, core_sources)

use ids_schemas
use ids_routines
implicit none


type (ids_equilibrium) :: equilibrium0
type (ids_core_sources) :: core_sources0, core_sources


integer :: i,n,npo

parameter (npo=500)

!integer, parameter :: DP = kind(1.0d0)
real(ids_real) :: ai(npo),qe0(npo),qq0(npo)

real(ids_real) :: c_input1(npo),c_input2(npo)
real(ids_real) :: c_output1(npo),c_output2(npo),c_output3(npo)

	character *20 apr

call ids_copy(core_sources0,core_sources)

      call transp50( &
!-----------------------------------  inputs---
     &  c_input1,c_input2, &
!------------------------------------outputs
     &  c_output1,c_output2)


n = size(core_sources%source(1)%profiles_1d(1)%grid%rho_tor_norm)

    print *,' transp50   n=',n

    	qe0=c_output1
    	qq0=c_output2

      apr='--qe0-' 
      print 71,apr,(qe0(i),i=1,n) 

      apr='--qq0-' 
      print 71,apr,(qq0(i),i=1,n) 

    71 FORMAT(20X,A20/,(6(1pE10.3)))


allocate(core_sources%source(1)%profiles_1d(1)%electrons%energy(n))
 core_sources%source(1)%profiles_1d(1)%electrons%energy(1:n) = qe0(1:n)

allocate(core_sources%source(1)%profiles_1d(1)%total_ion_energy(n))
 core_sources%source(1)%profiles_1d(1)%total_ion_energy(1:n) = qq0(1:n)

 qe0(1:n) = core_sources%source(1)%profiles_1d(1)%electrons%energy(1:n)
      apr='--qe0-' 
      print 71,apr,(qe0(i),i=1,n) 
 
 qq0(1:n) = core_sources%source(1)%profiles_1d(1)%total_ion_energy(1:n)
 
      apr='--qq0-' 
      print 71,apr,(qq0(i),i=1,n) 

    print *,' END transp50   n=',n


return
end subroutine
