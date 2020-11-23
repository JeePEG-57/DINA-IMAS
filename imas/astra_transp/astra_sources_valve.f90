subroutine astra_sources_valve(equilibrium0, core_profiles0, ctrl_in, src_out)

use ids_schemas
use ids_routines
implicit none


type (ids_equilibrium) :: equilibrium0
type (ids_core_profiles) :: core_profiles0
!type (ids_core_sources) :: core_sources0, core_sources
real (ids_real) :: src_out(*)
real (ids_real) :: ctrl_in(*)

integer :: i,n,n2,npo

! used npo as kint in transp2
parameter (npo=200)

!integer, parameter :: DP = kind(1.0d0)
real(ids_real) :: ai(npo),pne(npo),pd0(npo),pt0(npo)

real(ids_real) :: c_input1(npo),c_input2(npo)
real(ids_real) :: c_output1(npo),c_output2(npo),c_output3(npo)
real(ids_real) :: te0(npo),tq0(npo)

real(ids_real) :: tt
real(ids_real) :: tt_in,yGpuf
integer :: n_xx,kpr_xx

        character *20 apr


n = size(core_profiles0%profiles_1d(1)%grid%rho_tor_norm)
ai(1:n) = core_profiles0%profiles_1d(1)%grid%rho_tor_norm(1:n)


tt = core_profiles0%time(1)
tt_in=tt
kpr_xx=1

print *,'  Astra sources tt n',tt,n


 te0(1:n) = core_profiles0%profiles_1d(1)%electrons%temperature(1:n)
 tq0(1:n) = core_profiles0%profiles_1d(1)%t_i_average(1:n)

      apr='--te0-' 
      print 71,apr,(te0(i),i=1,n) 
      apr='--tq0-' 
      print 71,apr,(tq0(i),i=1,n) 

   71 FORMAT(20X,A20/,(6(1pE10.3)))


!call ids_copy(core_sources0,core_sources)

 pne(1:n) = core_profiles0%profiles_1d(1)%electrons%density(1:n)*1.d-19
 pd0(1:n) = core_profiles0%profiles_1d(1)%ion(1)%density(1:n)*1.d-19
 pt0(1:n) = core_profiles0%profiles_1d(1)%ion(2)%density(1:n)*1.d-19

      apr='--pne-' 
      print 71,apr,(pne(i),i=1,n) 
      apr='--pd0-' 
      print 71,apr,(pd0(i),i=1,n) 
      apr='--pt0-' 
      print 71,apr,(pt0(i),i=1,n) 

        do i=1,n
        c_input1(i)=pd0(i)
        c_input2(i)=pt0(i)
        end do
        
        yGpuf= ctrl_in(2)
        n_xx=n

    print *,'  tran_neut --> n_xx kpr_xx',n_xx,kpr_xx

      call tran_neut( &
!-----------------------------------  inputs---
     &  c_input1,c_input2, &
!------------------------------------outputs
     &  c_output1,c_output2,c_output3, &
     &  tt_in,yGpuf,n_xx,kpr_xx)
 	

!      call transp7( &
!-----------------------------------  inputs---
 !    &  c_input1,c_input2, &
!------------------------------------outputs
 !    &  c_output1,c_output2,c_output3, &
 !    &  tt)




        pd0(1:n)=c_output1(1:n)
        pt0(1:n)=c_output2(1:n)
        pne(1:n)=c_output3(1:n)


      apr='--sd0_p-' 
      print 71,apr,(pd0(i),i=1,n) 
      apr='--sd0_n-' 
      print 71,apr,(pt0(i),i=1,n) 

src_out(1:n) = pd0(1:n)
src_out(n+1:2*n) = pt0(1:n)
src_out(2*n+1:3*n) =2.
    

!src_out(1:n) = 10.
!src_out(n+1:2*n) = 20.
!src_out(2*n+1:3*n) =2.


    
return
end subroutine
