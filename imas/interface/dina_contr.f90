subroutine dina_contr(arr_in1,arr_out1)

use ids_schemas
use ids_routines
implicit none

! trees are static or dynamic; if not defined, they are static
type (ids_dina) :: dina0, dina
type (ids_em_coupling)  :: em_coupling0
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_magnetics)   :: magnetics
type (ids_pf_active)   :: pf_active0, pf_active
type (ids_pf_active) , save  :: pf_active_out, pf_active_out2
type (ids_pf_passive)   :: pf_passive0, pf_passive
type (ids_core_profiles)   :: core_profiles

integer,save :: i
integer,save :: first_call = 1, loop_count = 0, ntime = 0

integer :: idx, idx0

real (DP):: arr_in1(*), arr_out1(*)

integer,save :: n_input1, n_input2, ng
integer,save :: n_output1, n_output2

integer,save ::  npf=15, n_gaps=6


integer,save :: key(27)=(/ (0,i=1,27) /)

! static and prescribed data expressed in DINA terms
real (DP),save :: dina_time=0
real (DP),save :: time_8,tt_8,tay_8

integer ::  npo

parameter ( npo=100)

real (DP),save :: vec(npo) = (/ (0,i=1,npo) /)

! dynamic inputs and outputs groups
real (DP),save :: input_1(npo) = (/ (0,i=1,npo) /)
real (DP),save :: input_2(npo) = (/ (0,i=1,npo) /)
real (DP),save :: input_3(npo) = (/ (0,i=1,npo) /)

real (DP),save :: output_1(npo) = (/ (0,i=1,npo) /)
real (DP),save :: output_2(npo) = (/ (0,i=1,npo) /)
real (DP),save :: output_3(npo) = (/ (0,i=1,npo) /)
real (DP),save :: output_4(npo) = (/ (0,i=1,npo) /)


loop_count = loop_count + 1 ! number of times the iterative routine was entered

write(*,*) 'Entering dina_contr loop, first_call = ', first_call, loop_count

first_call=first_call+1


   npf=15
   n_gaps=6

   n_input1=15
   n_input2=npf+n_gaps+npf
      

do i=1,n_input1
input_1(i)=arr_in1(i)
!print *,' i input_1=',i,input_1(i)
end do
do i=1,n_input2
input_2(i)=arr_in1(n_input1+i)
!print *,' i input_2 arr2=',i,input_2(i),arr_in1(n_input1+i)
end do


	call eq_ech(time_8,tt_8,tay_8,key,vec, &
     &	input_1,input_2,input_3, &
     &	output_1,output_2,output_3,output_4,ng)

      n_output1=2
      n_output2=15

      do i=1,n_output1
	  arr_out1(i)=output_1(i)
      end do
      
      do i=1,n_output2
	  arr_out1(n_output1+i)=output_2(i)
      end do


!write(*,*) "c inp=",arr_in1(1:25)
!write(*,*) "c out=",arr_out1(1:25)

!stop

return
end subroutine


