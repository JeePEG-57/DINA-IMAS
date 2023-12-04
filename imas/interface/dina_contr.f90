subroutine dina_contr(pulse_schedule, pulse_schedule_term, equilibrium0, pf_active0, pf_active)

use ids_schemas
use ids_routines
implicit none

include 'imas_interface.inc'

type (ids_pulse_schedule), intent(IN) :: pulse_schedule, pulse_schedule_term
type (ids_equilibrium), intent(IN) :: equilibrium0
type (ids_pf_active), intent(IN) :: pf_active0
type (ids_pf_active), intent(OUT) :: pf_active


integer :: kpr
      common /ge5/kpr

integer :: i, kk
integer,save :: loop_count = 0

integer,parameter :: npf=15, n_gaps=6, ncam=100;
integer,parameter :: n_input1=15, n_input2=n_gaps+npf+ncam
integer,parameter :: n_output1=2, n_output2=38

integer,parameter :: nact=12, npfa=14

! dynamic inputs and outputs groups
integer, parameter ::  kint=200
real*8 :: input_1(kint), input_2(kint)
real*8 :: output_1(kint), output_2(kint)


real*8 :: pf(npf)
integer :: ncirc(npf), dircirc(npf)
real*8 :: vmult(npf)
real*8 :: pf_turn(nact)
data ncirc(1:14) /1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12/
data dircirc(1:14) /1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1/
data vmult(1:14) /1, 1, 0.5d0, 0.5d0, 1, 1, 1, 1, 1, 1, 1, 1, 0.5d0, -0.5d0/
data pf_turn(1:12) /554., 554., 554. ,554., 554. ,248.6, 115.2, 185.9, 169.9, 216.8, 459.4, 4.0/


  if (loop_count.eq.0) then
    write(*,*) 'Controller parameters initialization...'
    call contr_data_read_imas(pulse_schedule, pulse_schedule_term)
  endif

  loop_count = loop_count + 1 ! number of times the iterative routine was entered

  write(*,*) 'Entering dina_contr loop, loop_count = ', loop_count



  input_1(1)=equilibrium0%time_slice(1)%global_quantities%current_centre%z
  input_1(2)=equilibrium0%time_slice(1)%global_quantities%magnetic_axis%z ! Not used
  input_1(3)=equilibrium0%time_slice(1)%boundary%elongation
  input_1(4)=tpl_dir*equilibrium0%time_slice(1)%global_quantities%ip
  input_1(5)=equilibrium0%time_slice(1)%boundary%type
  input_1(6)=equilibrium0%time_slice(1)%boundary%geometric_axis%r - equilibrium0%time_slice(1)%boundary%minor_radius ! xleft
  input_1(7)=equilibrium0%time_slice(1)%boundary%geometric_axis%r + equilibrium0%time_slice(1)%boundary%minor_radius ! xright
  input_1(8)=0.d0 ! rsep
  input_1(9)=1.d3*equilibrium0%time_slice(1)%time
  input_1(10)=0.d0 ! zsep

  ! In fact the values 11-15 are not used
  input_1(11)=npf
  input_1(12)=n_gaps
  input_1(13)=1.d0 ! ntay
  input_1(14)=ncam
  input_1(15)=0.d0 ! i_wr




  pf(1:npf) = 0.d0
  do i=1,npfa
    pf(ncirc(i)) = tpl_dir*dircirc(i)*pf_active0%coil(i)%current%data(1)*pf_turn(ncirc(i))
  enddo

  kk=0
  do i=1,n_gaps
    kk=kk+1
    input_2(kk) = equilibrium0%time_slice(1)%boundary_separatrix%gap(24+i)%value
  end do
    
  do i=1,npf
    kk=kk+1
    input_2(kk)=pf(i)
  end do

  do i=kk+1,n_input2
    input_2(i) = 0.d0
  enddo

  if (kpr.eq.1) then
    write(*,*) 'kav_contr n_input1 n_input2 = ',n_input1,n_input2
    print*, 'i  input_1(i)'
    do i=1,n_input1
      print*, i, input_1(i)
    enddo
    print*, 'i  input_2(i)'
    do i=1,n_input2
      print*, i, input_2(i)
    enddo
  endif


  call kav_contr(input_1,input_2, &
      &  output_1,output_2)


  call ids_copy(pf_active0, pf_active)


  !pf_active%ids_properties%homogeneous_time = 1
  !if (.NOT.associated(pf_active%time)) allocate(pf_active%time(1))
  !pf_active%time(1) = tt
      

  do i=1,npfa
    if (.NOT.associated(pf_active%coil(i)%voltage%data)) allocate(pf_active%coil(i)%voltage%data(1))
    pf_active%coil(i)%voltage%data(1) = tpl_dir*vmult(i)*output_2(ncirc(i))*pf_turn(ncirc(i))
  enddo


return
end subroutine


