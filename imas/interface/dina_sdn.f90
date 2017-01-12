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
  allocate(sdn%signal(74)) !36input+38output
  allocate(sdn%topic_list(2))
  allocate(sdn%topic_list(1)%indices(36))
  allocate(sdn%topic_list(1)%names(1))
  sdn%topic_list(1)%names(1) = 'Input SDN'
  do i=1,36 !indices in arrin
    sdn%topic_list(1)%indices(i)=i
    sdn%signal(i)%ip_normalise = 0
    sdn%signal(i)%allocated_position = sdn%topic_list(1)%indices(i)
    allocate(sdn%signal(i)%value(1))
  enddo
  allocate(sdn%topic_list(2)%indices(38))
  allocate(sdn%topic_list(2)%names(1))
  sdn%topic_list(2)%names(1) = 'Output SDN'
  i = size(sdn%topic_list(1)%indices)
  do k=1,38 !indices in arrout
    sdn%topic_list(2)%indices(k)=k+2
    i = k+size(sdn%topic_list(1)%indices)
    sdn%signal(i)%ip_normalise = 0
    sdn%signal(i)%allocated_position = sdn%topic_list(2)%indices(k)
    allocate(sdn%signal(i)%value(1))
  enddo

  !input names
  i=1
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'Z coordinate of the plasma current centroid, m'
  i=2
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'Z coordinate of the plasma magnetic axis, m'
  i=3
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'Plasma elongation'
  i=4
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'Plasma current, A'
  i=5
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'Marker of the limiter plasma configuration'
  i=6
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'R coordinate of the left plasma boundary point in mid-plane, m'
  i=7
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'R coordinate of the right plasma boundary point in mid-plane, m'
  i=8
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'R coordinate of the separatrix point or plasma limiter touching point, m'
  i=9
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'time, ms'
  i=10
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'Z coordinate of the separatrix point or plasma limiter touching point, m'
  i=11
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'number of PF coils including contours of VS3, triangular support, copper cladding and divertor inboard rail (= 15)'
  i=12
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'number of controlled gaps between plasma boundary and first wall (= 6)'
  i=13
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'current number of time step'
  i=14
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'number of vacuum vessel filaments (= 100)'
  i=15
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'internal flag'
  i=16
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'gaps between plasma and limiter (6 inputs), m'
  i=22
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'currents in the poloidal field coils, internal coils and copper cladding (15 inputs), A'

  !output names
  k=1
  i = k+size(sdn%topic_list(1)%indices)
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'voltages in the poloidal field coils (11 outputs), V'
  k=12
  i = k+size(sdn%topic_list(1)%indices)
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'voltage in VS3 coils (1 output), V'
  k=13
  i = k+size(sdn%topic_list(1)%indices)
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'voltage in triangular support (1 output), V'
  k=14
  i = k+size(sdn%topic_list(1)%indices)
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'voltage in copper cladding (1 output), V'
  k=15
  i = k+size(sdn%topic_list(1)%indices)
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'voltage in divertor inboard rail (1 output), V'
  k=16
  i = k+size(sdn%topic_list(1)%indices)
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'voltages in main converters (11 outputs), V'
  k=27
  i = k+size(sdn%topic_list(1)%indices)
  allocate(sdn%signal(i)%name(1))
  sdn%signal(i)%name(1) = 'voltages in vertical stabilization converters (12 outputs), V'

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
  do i=1,size(sdn%topic_list(1)%indices)
    sdn%signal(i)%value(1) = arrinout(sdn%signal(i)%allocated_position)
    !write(*,*) 'size(value) value ', size(sdn%signal(i)%value), sdn%signal(i)%value
  enddo

  !put input time
  sdn%time(1)=sdn%signal(9)%value(1)*1e-3

else if (ioswitch.eq.1) then

  write(*,*) 'Output SDN data ', size(sdn%signal)
  i = size(sdn%topic_list(1)%indices)
  do k=1,size(sdn%topic_list(2)%indices)
    sdn%signal(i+k)%value(1) = arrinout(sdn%signal(i+k)%allocated_position)
  enddo

endif

return
end subroutine
