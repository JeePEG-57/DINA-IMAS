subroutine density_control_pellet(summary_in, ctrl_out)

use ids_schemas
use ids_routines
implicit none


type (ids_summary) :: summary_in
real (ids_real) :: ctrl_out(*)

integer :: i,npo

! used npo as kint in transp2
parameter (npo=200)

!integer, parameter :: DP = kind(1.0d0)

real(ids_real) :: Ne, Ni


real(ids_real) :: tt

real(ids_real) :: tt_in,GHFS,pcch,pcchp_pel

	character *20 apr


tt = summary_in%time(1)

Ne = summary_in%volume_average%n_e%value(1)
Ni = summary_in%volume_average%n_i_total%value(1)

print *,'  Density controller tt Ne Ni',tt,Ne,Ni

call system(" pwd")
call system(" ls -ll general_data1.dat")

   71 FORMAT(20X,A20/,(6(1pE10.3)))
   
tt_in=tt
pcch=Ni*1.d-19

      call feed_pel(GHFS,pcch,pcchp_pel,tt_in)


    
ctrl_out(1) = GHFS
ctrl_out(2) = 1.d0    
    
print *,'  Density controller GHFS,pcch,pcchp_pel',GHFS,pcch,pcchp_pel
    
return
end subroutine
