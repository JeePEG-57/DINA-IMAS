subroutine dina_contr(pulse_schedule, pulse_schedule_term, equilibrium0, pf_active0, pf_active, arr_in1,arr_out1)

use ids_schemas
use ids_routines
implicit none


type (ids_pulse_schedule)   :: pulse_schedule, pulse_schedule_term
type (ids_pf_active)   :: pf_active0, pf_active
type (ids_equilibrium) :: equilibrium0

integer,save :: i
integer,save :: first_call = 1, loop_count = 0, ntime = 0

integer :: idx, idx0

!integer, parameter :: DP = kind(1.0d0)
real (ids_real):: arr_in1(*), arr_out1(*)

integer,save :: n_input1, n_input2, ng
integer,save :: n_output1, n_output2

integer,save ::  npf=15, n_gaps=6, ncam=100;


integer,save :: key(27)=(/ (0,i=1,27) /)

! static and prescribed data expressed in DINA terms
real (ids_real),save :: dina_time=0
real (ids_real),save :: time_8,tt_8,tay_8

integer ::  npo

parameter ( npo=500)

real (ids_real),save :: vec(npo) = (/ (0,i=1,npo) /)

! dynamic inputs and outputs groups
real (ids_real),save :: input_1(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: input_2(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: input_3(npo) = (/ (0,i=1,npo) /)

real (ids_real),save :: output_1(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: output_2(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: output_3(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: output_4(npo) = (/ (0,i=1,npo) /)



call ids_copy(pf_active0, pf_active)


if (loop_count.eq.0) then
  write(*,*) 'Controller parameters initialization...'
  call contr_data_read_imas(pulse_schedule, pulse_schedule_term)
endif

loop_count = loop_count + 1 ! number of times the iterative routine was entered

write(*,*) 'Entering dina_contr loop, first_call = ', first_call, loop_count

first_call=first_call+1


   npf=15
   n_gaps=6
   ncam=100
    
   n_input1=15
   n_input2=npf+n_gaps+ncam
      

do i=1,n_input1
input_1(i)=arr_in1(i)
!print *,' i input_1=',i,input_1(i)
end do
do i=1,n_input2
input_2(i)=arr_in1(n_input1+i)
!print *,' i input_2 arr2=',i,input_2(i),arr_in1(n_input1+i)
end do

write(*,*) 'eq_ech n_inp1 n_inp2 = ',n_input1,n_input2


	call eq_ech(time_8,tt_8,tay_8,key,vec, &
     &	input_1,input_2,input_3, &
     &	output_1,output_2,output_3,output_4,ng)

      n_output1=2
      n_output2=38

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


