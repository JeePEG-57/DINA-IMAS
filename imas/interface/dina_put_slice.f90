subroutine dina_put_slice( pf_active, pf_passive , equilibrium, core_profiles, &
    & pulse, run, iloop, trig)


use ids_schemas
use ids_routines
implicit none


type (ids_equilibrium) :: equilibrium
type (ids_pf_active)   :: pf_active
type (ids_pf_passive)   :: pf_passive
type (ids_core_profiles)   :: core_profiles

integer :: pulse, run, iloop, trig



integer :: i, k, j, idx
integer :: nr, nz, n1, n2, ke

integer :: TimeSteps, CurTimeStep

real(DP),dimension(:),allocatable :: xu, yu, x, y
real(DP),dimension(:,:),allocatable :: psi

real(DP) :: tt,psi_ax,psi_bnd



call imas_open('ids',pulse,run,idx) 
 

if (iloop == 1) then

write(*,*)  'Put non-timed'

  call ids_put(idx,"pf_active",pf_active)
  call ids_put(idx,"pf_passive",pf_passive)

  call ids_put(idx,"equilibrium",equilibrium)
  call ids_put(idx,"core_profiles",core_profiles)

else

write(*,*)  'Put slices'

write(*,*)  'Put pf_active'
call ids_put_slice(idx,"pf_active",pf_active)

write(*,*)  'Put pf_passive'
call ids_put_slice(idx,"pf_passive",pf_passive)

write(*,*)  'Put equilibrium'
call ids_put_slice(idx,"equilibrium",equilibrium)

write(*,*)  'Put core_profiles'
call ids_put_slice(idx,"core_profiles",core_profiles)

write(*,*)  'Slices put'

endif


call imas_close(idx)



	TimeSteps = size(equilibrium%time)
	CurTimeStep = 1

nr = size(equilibrium%profiles_2d(1)%grid%dim1(:,CurTimeStep))
nz = size(equilibrium%profiles_2d(1)%grid%dim2(:,CurTimeStep))
ke = size(equilibrium%coordinate_system%r(:,1,CurTimeStep))

write(*,*) 'nr nz ke = ',nr,nz,ke

allocate(x(nr))
allocate(y(nz))
allocate(psi(nz,nr))
allocate(xu(ke))
allocate(yu(ke))

!write(*,*) 'test1'
x(1:nr) = equilibrium%profiles_2d(1)%grid%dim1(1:nr,CurTimeStep)
y(1:nz) = equilibrium%profiles_2d(1)%grid%dim2(1:nz,CurTimeStep)


!write(*,*) 'test2'

    do i=1,nr
    do j=1,nz
      psi(j,i) = equilibrium%profiles_2d(1)%psi(i,j,CurTimeStep)
    enddo
    enddo

!write(*,*) 'test3'

xu(1:ke) = equilibrium%coordinate_system%r(1:ke,1,CurTimeStep)

!write(*,*) 'test4'
yu(1:ke) = equilibrium%coordinate_system%z(1:ke,1,CurTimeStep)

!write(*,*) 'test5'

tt = equilibrium%time(CurTimeStep)


psi_ax = equilibrium%global_quantities%psi_axis(CurTimeStep)
psi_bnd = equilibrium%global_quantities%psi_boundary(CurTimeStep)

    call write_graf_imas2(nr,nz,ke, &
     &	0.01d0,0.01d0,tt,&
     &  psi,x,y,xu,yu,&
     &  psi_ax,psi_bnd,psi_bnd,0.d0,0.d0) 



trig = 0

return
end subroutine



	subroutine write_graf_imas2(nr,nz,ke,&
     &	dx,dy,ttt,&
     &  psi,x,y,xu,yu,&
     &  pmag,pbound,p_s,um,vm) 

        integer :: nr,nz,ke
	real*8,dimension(:,:) :: psi(nr,nz)
	real*8,dimension(:) :: x(nr),y(nz),xu(ke),yu(ke)

	real(8) :: dx,dy,ttt,pmag,pbound,p_s,um,vm
	

5000	format(4(1x,1pe14.7))
	
	write(*,*) 'Write Graph Enter...'

	open (unit=61,file='psi_data_imas2',access='append',form='formatted')



           write (61,*)ke,1,1,1,1

           write (61,5000)0.d0
           write (61,5000)0.d0
           write (61,5000)(xu(i),i=1,ke)
           write (61,5000)(yu(i),i=1,ke)
   
           write (61,5000)dx,dy,pmag,pbound,p_s,um,vm,ttt
           
           write (61,5000)((psi(i,j),i=1,nr),j=1,nz)
           write (61,5000)(x(i),i=1,nr)
           write (61,5000)(y(i),i=1,nz)
           write (61,5000)0.d0
           write (61,5000)0.d0
           write (61,5000)0.d0
           write (61,5000)0.d0




           close (61)

        
        
	return
	end
