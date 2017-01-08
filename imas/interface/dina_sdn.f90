subroutine dina_sdn(sdnin,arrinout,ioswitch,sdn)

use ids_schemas
use ids_routines
implicit none

type (ids_sdn)   :: sdnin,sdn
real(DP) arrinout(*)
integer :: ioswitch

integer :: i, k, j, idx
integer,save :: ifirst = 1

write(*,*) 'dina_sdn ', ifirst, ioswitch
if (ifirst.eq.1) then

!if (ioswitch.eq.0) then
!  if (ifirst.ne.1) then
!    deallocate(sdn%signal)
!    deallocate(sdn%topic_list)
!    deallocate(sdn%time)
!  endif 

  write(*,*) 'Static SDN setup'
  allocate(sdn%signal(71)) !36input+35output
  allocate(sdn%topic_list(2))
  allocate(sdn%topic_list(1)%indices(36))
  do i=1,36 !indices in arrin
    sdn%topic_list(1)%indices(i)=i
  enddo
  allocate(sdn%topic_list(2)%indices(35))
  do k=1,35 !indices in arrout
    sdn%topic_list(2)%indices(k)=k+2
  enddo
  !input time
  i=9
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'time in ms'
  sdn%signal(i)%ip_normalise = 0
  sdn%signal(i)%allocated_position = i
  allocate(sdn%signal(i)%value(1))

  !output PF currents
  k=1
  i = k+size(sdn%topic_list(1)%indices)
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'PF coil voltages 1:11 in V'
  sdn%signal(i)%ip_normalise = 0
  do j=1,11
    sdn%signal(i+j-1)%allocated_position = k+2+j-1
    allocate(sdn%signal(i+j-1)%value(1))
  enddo

  sdn%ids_properties%homogeneous_time=1
  allocate(sdn%time(1))
  sdn%time(1)=0
  allocate(sdn%ids_properties%comment(1))
  sdn%ids_properties%comment(1)='DINA SDN'
  ifirst = ifirst+1
else
  call ids_copy(sdnin,sdn)
endif

if (ioswitch.eq.0) then

  write(*,*) 'Input SDN data ', size(sdn%signal)
  i = 9
  !deallocate(sdn%signal(i)%value)
  !allocate(sdn%signal(i)%value(1))
  sdn%signal(i)%value(1) = arrinout(sdn%signal(i)%allocated_position)
  write(*,*) 'size(value) value ', size(sdn%signal(i)%value), sdn%signal(i)%value
  !put input time
  sdn%time(1)=sdn%signal(9)%value(1)*1e-3

else if (ioswitch.eq.1) then

  write(*,*) 'Output SDN data ', size(sdn%signal)
  k = 1
  i = k+size(sdn%topic_list(1)%indices)
  do j=1,11
    sdn%signal(i+j-1)%value(1) = arrinout(sdn%signal(i+j-1)%allocated_position)
    write(*,*) 'size(value) value ', size(sdn%signal(i+j-1)%value), sdn%signal(i+j-1)%value
  enddo

endif

return
end subroutine
