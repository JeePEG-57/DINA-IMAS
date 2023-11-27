subroutine dina_contr(pulse_schedule, pulse_schedule_term, equilibrium0, pf_active0, pf_active, arr_in1, arr_out1)

use ids_schemas
use ids_routines
implicit none

include 'imas_interface.inc'

type (ids_pulse_schedule), intent(IN) :: pulse_schedule, pulse_schedule_term
type (ids_pf_active), intent(IN) :: pf_active0
type (ids_pf_active), intent(OUT) :: pf_active
type (ids_equilibrium), intent(IN) :: equilibrium0

real (ids_real), intent(IN) :: arr_in1(*)
real (ids_real), intent(OUT) :: arr_out1(*)


integer,save :: i, kk
integer,save :: first_call = 1, loop_count = 0, ntime = 0

real (ids_real) :: pf(30)


integer,save :: n_input1, n_input2, ng
integer,save :: n_output1, n_output2

integer,save ::  npf=15, n_gaps=6, ncam=100;
integer :: nact=12, npfa=14

integer ::  npo
parameter ( npo=500)

integer,save :: key(27)=(/ (0,i=1,27) /)
real (ids_real),save :: vec(npo) = (/ (0,i=1,npo) /)

! static and prescribed data expressed in DINA terms
real (ids_real),save :: dina_time=0
real (ids_real),save :: time_8,tt_8,tay_8



integer :: ncirc(30), dircirc(30)
real (ids_real) :: vmult(30)
data ncirc(1:14) /1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12/
data dircirc(1:14) /1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1/
data vmult(1:14) /1, 1, 0.5d0, 0.5d0, 1, 1, 1, 1, 1, 1, 1, 1, 0.5d0, -0.5d0/


! dynamic inputs and outputs groups
real (ids_real),save :: input_1(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: input_2(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: input_3(npo) = (/ (0,i=1,npo) /)

real (ids_real),save :: output_1(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: output_2(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: output_3(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: output_4(npo) = (/ (0,i=1,npo) /)



real (ids_real),save :: input_1_new(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: input_2_new(npo) = (/ (0,i=1,npo) /)



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
   !n_input2=123
      

do i=1,n_input1
input_1(i)=arr_in1(i)
!print *,' i input_1=',i,input_1(i)
end do
do i=1,n_input2
input_2(i)=arr_in1(n_input1+i)
!print *,' i input_2 arr2=',i,input_2(i),arr_in1(n_input1+i)
end do




input_1_new(1)=equilibrium0%time_slice(1)%global_quantities%current_centre%z
input_1_new(2)=equilibrium0%time_slice(1)%global_quantities%magnetic_axis%z ! Not used
input_1_new(3)=equilibrium0%time_slice(1)%boundary%elongation
input_1_new(4)=tpl_dir*equilibrium0%time_slice(1)%global_quantities%ip
input_1_new(5)=equilibrium0%time_slice(1)%boundary%type
input_1_new(6)=equilibrium0%time_slice(1)%boundary%geometric_axis%r - equilibrium0%time_slice(1)%boundary%minor_radius ! xleft
input_1_new(7)=equilibrium0%time_slice(1)%boundary%geometric_axis%r + equilibrium0%time_slice(1)%boundary%minor_radius ! xright
input_1_new(8)=0.d0 ! rsep
input_1_new(9)=1.d3*equilibrium0%time_slice(1)%time
input_1_new(10)=0.d0 ! zsep

! In fact the values 11-15 are not used
input_1_new(11)=npf
input_1_new(12)=n_gaps
input_1_new(13)=1.d0 ! ntay
input_1_new(14)=ncam
input_1_new(15)=0.d0 ! i_wr




pf(1:npf) = 0.d0
do i=1,npfa
  pf(ncirc(i)) = tpl_dir*dircirc(i)*pf_active0%coil(i)%current%data(1)*pf_active0%coil(i)%element(1)%turns_with_sign
enddo

kk=0
do i=1,n_gaps
  kk=kk+1
  input_2_new(kk) = equilibrium0%time_slice(1)%boundary_separatrix%gap(24+i)%value
end do
  
do i=1,npf
  kk=kk+1
  input_2_new(kk)=pf(i)
end do

do i=kk+1,n_input2
  input_2_new(i) = 0.d0
enddo


write(*,*) 'eq_ech n_inp1 n_inp2 = ',n_input1,n_input2


print*, 'i  input_1(i)  input_1_new(i)'
do i=1,n_input1
  print*, i, input_1(i), input_1_new(i)
enddo
print*, 'i  input_2(i)  input_2_new(i)'
do i=1,n_input2
  print*, i, input_2(i), input_2_new(i)
enddo


! do i=1,n_input1
!   input_1(i) = input_1_new(i)
! enddo
! do i=1,n_input2
!   input_2(i) = input_2_new(i)
! enddo


	call eq_ech(time_8,tt_8,tay_8,key,vec, &
     &	input_1_new,input_2_new,input_3, &
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



      !pf_active%ids_properties%homogeneous_time = 1
      !if (.NOT.associated(pf_active%time)) allocate(pf_active%time(1))
      !pf_active%time(1) = tt
        

      
      do i=1,npfa
        if (.NOT.associated(pf_active%coil(i)%voltage%data)) allocate(pf_active%coil(i)%voltage%data(1))
          pf_active%coil(i)%voltage%data(1) = tpl_dir*vmult(i)*output_2(ncirc(i))*dabs(pf_active%coil(i)%element(1)%turns_with_sign)
      enddo


return
end subroutine


