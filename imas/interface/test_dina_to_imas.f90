! main test
! test the DINA_IMAS
! Jo Lister, August 2013

use ids_schemas
use ids_routines
implicit none

interface 
! Declaration of the dina_imas subroutine
    subroutine dina_to_imas( em_coupling0_in, equilibrium0_in,  &
 & pf_active0_in, pf_passive0_in, core_profiles0_in)
 
     use ids_schemas
! note that IDS0 are all prescribed, the others are dynamic
      type (ids_em_coupling) :: em_coupling0_in
      type (ids_equilibrium) :: equilibrium0_in
      type (ids_pf_active) :: pf_active0_in
      type (ids_pf_passive) :: pf_passive0_in
      type (ids_core_profiles)   :: core_profiles0_in

    end subroutine
end interface


type (ids_em_coupling) :: em_coupling0, em_coupling1
type (ids_equilibrium) :: equilibrium0, equilibrium,equilibrium1
type (ids_magnetics) :: magnetics
type (ids_pf_active) :: pf_active0, pf_active,pf_active1
type (ids_pf_passive) :: pf_passive0, pf_passive, pf_passive1
type (ids_core_profiles)   :: core_profiles0, core_profiles,core_profiles1


! define the pulse and run numbers to save initial data, will be done later outside
integer ::  prescribedpulse=170, prescribedrun=1

! define local variables
integer :: time_loop, key(25), indpf(12), ext_transp, i, iloop
!integer, parameter :: DP = kind(1.0d0)
real (ids_real) :: uff1(14) = (/1,2,3,2,1,2,3,2,1,2,3,2,1,2/),temp(50)
integer :: idx, idx0
integer :: nact,npass,ngrid,nbpol,nflux,nrad,npolar,ncronos,nr,nz
! main test
integer,save :: i1=11, i2=8, ke=57

! for timing tests
INTEGER :: clock_start,clock_end,clock_rate


print *,' Enter pulse number'
!read (*,*)prescribedpulse
prescribedpulse=170
print *,' pulse number',prescribedpulse


print *,' Enter run number'
!read (*,*)prescribedrun
prescribedrun=1
print *,' run number',prescribedrun


call imas_create('ids',prescribedpulse,prescribedrun,1,1,idx0)
write(*,*) 'created'


call ids_get(idx0,'em_coupling',em_coupling0)
call ids_get(idx0,'equilibrium',equilibrium0)
call ids_get(idx0,'pf_active',pf_active0)
call ids_get(idx0,'pf_passive',pf_passive0)
call ids_get(idx0,'core_profiles',core_profiles0)


call dina_to_imas( em_coupling0, equilibrium0,   &
  & pf_active0,  pf_passive0, core_profiles0)



  write(*,*) 'Shapes - testdinaimas'
  write(*,100) shape(em_coupling0%mutual_grid_active),shape(em_coupling0%mutual_grid_passive)

write(*,*) 'Shapes - testdinaimas'
write(*,100) shape(em_coupling0%mutual_loops_active),shape(em_coupling0%mutual_passive_active)

100 format (2I5, 4x,2I5, 4x, 2I5, 4x,2I5)

write(*,*)  'write_ids'

call ids_put(idx0,"em_coupling",em_coupling0)
write(*,*)  'em_coupling is written'

call ids_put(idx0,"pf_active",pf_active0)
write(*,*)  'pf_active is written'
!write(*,*)  '!!!ids_copy pf_active'
!write(*,*)  size(pf_active0%coil)
!do i=1,size(pf_active0%coil)
!        allocate(pf_active0%coil(i)%current%data(1))
!                allocate(pf_active0%coil(i)%voltage%data(1))
!        allocate(pf_active0%coil(i)%current%time(1))
!                allocate(pf_active0%coil(i)%voltage%time(1))
!enddo
!                allocate(pf_active0%time(1))
!                pf_active0%ids_properties%homogeneous_time = 1
!do i=1,size(pf_active0%coil)
!                    pf_active0%coil(i)%current%data(1) = 0.5
!                        !pf_active0%coil(i)%current%time(1) = 1.0
!                    pf_active0%coil(i)%voltage%data(1) = 100.
!                        !pf_active0%coil(i)%voltage%time(1) = 1.0
!end do
!                pf_active0%time(1) = 1.0
!call ids_copy(pf_active0,pf_active)
!write(*,*)  '!!!ids_copy pf_active done'

call ids_put(idx0,"pf_passive",pf_passive0)
write(*,*)  'pf_passive is written'

    write(*,*) 'x EQ'
    write(*,*)equilibrium0%time_slice(1)%coordinate_system%grid%dim1(1:10)
    write(*,*) 'y EQ'
    write(*,*)equilibrium0%time_slice(1)%coordinate_system%grid%dim2(1:10)

    write(*,*) 'xu EQ'
    write(*,*)equilibrium0%time_slice(1)%coordinate_system%r(1:ke,1)
    write(*,*) 'yu EQ'
    write(*,*)equilibrium0%time_slice(1)%coordinate_system%z(1:ke,1)

call ids_put(idx0,"equilibrium",equilibrium0)
write(*,*) 'ids_put OK!'

call ids_put(idx0,"core_profiles",core_profiles0)

call imas_close(idx0)

write(*,*) 'Deallocate ids'
call ids_deallocate(em_coupling0)
call ids_deallocate(pf_active0)
call ids_deallocate(pf_passive0)
call ids_deallocate(equilibrium0)
call ids_deallocate(core_profiles0)


write(*,*) 'DINA_IMAS Exiting cleanly'


write(*,*) 'Reading saved data...'

call imas_open('ids',prescribedpulse,prescribedrun,idx0) 
call ids_get(idx0,'em_coupling',em_coupling1)

write(*,*) 'TestDINAIMAS - TestElements: '
write(*,*) em_coupling1%mutual_grid_active(i1,i2)
write(*,*) em_coupling1%mutual_grid_passive(i1,i2)

write(*,*) em_coupling1%mutual_loops_passive(i1,i2)
write(*,*) em_coupling1%field_probes_passive(i1,i2) 

write(*,*) em_coupling1%mutual_loops_active(i1,i2)
write(*,*) em_coupling1%field_probes_active(i1,i2)

write(*,*) em_coupling1%mutual_active_active(i1,i2)
write(*,*) em_coupling1%mutual_passive_passive(i1,i2)
write(*,*) em_coupling1%mutual_passive_active(i1,i2)


call ids_get(idx0,'pf_active',pf_active1)
!write(*,*)  '!!!ids_copy pf_active'
!write(*,*)  size(pf_active1%coil)
!do i=1,size(pf_active1%coil)
!        allocate(pf_active1%coil(i)%current%data(1))
!                allocate(pf_active1%coil(i)%voltage%data(1))
!        allocate(pf_active1%coil(i)%current%time(1))
!                allocate(pf_active1%coil(i)%voltage%time(1))
!enddo
!                allocate(pf_active1%time(1))
!                pf_active1%ids_properties%homogeneous_time = 1
!do i=1,size(pf_active1%coil)
!                    pf_active1%coil(i)%current%data(1) = 0.5
!                        pf_active1%coil(i)%voltage%data(1) = 100.
!end do
!                pf_active1%time(1) = 1.0
!write(*,*)  size(pf_active1%coil)
!call ids_copy(pf_active1,pf_active)
!write(*,*)  '!!!ids_copy pf_active done'
call ids_get(idx0,'pf_passive',pf_passive1)

write(*,*) 'pfs resistances'
write(*,*) pf_active1%coil(6)%resistance
write(*,*) pf_passive1%loop(16)%resistance


write(*,*) 'Get equilibrium'
call ids_get(idx0,'equilibrium',equilibrium1)

write(*,*) 'Close DB'
call imas_close(idx0)

    write(*,*) 'x EQ'
    write(*,*)equilibrium1%time_slice(1)%coordinate_system%grid%dim1(1:10)
    write(*,*) 'y EQ'
    write(*,*)equilibrium1%time_slice(1)%coordinate_system%grid%dim2(1:10)

    write(*,*) 'xu EQ'
    write(*,*)equilibrium1%time_slice(1)%coordinate_system%r(1:ke,1)
    write(*,*) 'yu EQ'
    write(*,*)equilibrium1%time_slice(1)%coordinate_system%z(1:ke,1)


write(*,*) 'Deallocate ids'
call ids_deallocate(em_coupling1)
call ids_deallocate(pf_active1)
call ids_deallocate(pf_passive1)
call ids_deallocate(equilibrium1)


write(*,*) 'All finished.'

end 
