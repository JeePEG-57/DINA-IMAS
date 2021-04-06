subroutine dina_put_slice( pf_active, pf_passive , equilibrium, core_profiles, &
    & core_sources, core_transport, bndcond, summary, wall, &
    & pulse, run, iloop, trig)


use ids_schemas
use ids_routines
implicit none
type (ids_equilibrium) :: equilibrium
type (ids_pf_active)   :: pf_active
type (ids_pf_passive)   :: pf_passive
type (ids_core_profiles)   :: core_profiles
type (ids_core_transport)   :: core_transport
type (ids_core_sources)   :: core_sources
type (ids_transport_solver_numerics) :: bndcond
type (ids_summary) :: summary
type (ids_wall) :: wall


integer :: pulse, run, iloop, trig



integer :: i, k, j, idx
integer :: nr, nz, n1, n2, ke, i_wr

integer :: TimeSteps, CurTimeStep

integer, parameter :: DP = kind(1.0d0)
real(DP),dimension(:),allocatable :: xu, yu, x, y
real(DP),dimension(:,:),allocatable :: psi

real(DP) :: tt,psi_ax,psi_bnd

character (len=255) :: user
call getenv("USER", user)

if (iloop == 1) then


  write(*,*) 'Create new pulse file...'
!   call imas_create('ids',pulse,run,1,1,idx)
  call imas_create_env('ids',pulse,run,1,1,idx,user,'test','3')
  write(*,*) 'Pulse file is created, put non-timed...'


  call ids_put(idx,"pf_active",pf_active)
  call ids_put(idx,"pf_passive",pf_passive)

  call ids_put(idx,"equilibrium",equilibrium)
  call ids_put(idx,"core_profiles",core_profiles)
  call ids_put(idx,"core_sources",core_sources)
  call ids_put(idx,"core_transport",core_transport)

  call ids_put(idx,"transport_solver_numerics",bndcond)
  call ids_put(idx,"summary",summary)
  
  call ids_put(idx,"wall",wall)

  write(*,*)  'Pulse put!'

else

  write(*,*) 'Open pulse file...'
!   call imas_open('ids',pulse,run,idx) 
  call imas_open_env('ids',pulse,run,idx,user,'test','3') 
  write(*,*)  'Pulse file is opened, put slices'

  write(*,*)  'Put pf_active'
  call ids_put_slice(idx,"pf_active",pf_active)

  write(*,*)  'Put pf_passive'
  call ids_put_slice(idx,"pf_passive",pf_passive)

  write(*,*)  'Put equilibrium'
  call ids_put_slice(idx,"equilibrium",equilibrium)

  write(*,*)  'Put core_profiles'
  call ids_put_slice(idx,"core_profiles",core_profiles)

  write(*,*)  'Put core_sources'
  call ids_put_slice(idx,"core_sources",core_sources)

  write(*,*)  'Put core_transport'
  call ids_put_slice(idx,"core_transport",core_transport)

  write(*,*)  'Put transport_solver_numerics'
  call ids_put_slice(idx,"transport_solver_numerics",bndcond)

  write(*,*)  'Put summary'
  call ids_put_slice(idx,"summary",summary)

  write(*,*)  'Put wall'
  call ids_put_slice(idx,"wall",wall)  
  
  write(*,*)  'Slices put!'

endif


call imas_close(idx)



	TimeSteps = size(equilibrium%time_slice)
	CurTimeStep = 1

nz = size(equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%grid%dim1(:))
nr = size(equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%grid%dim2(:))
ke = size(wall%description_2d(1)%limiter%unit(1)%outline%r)

write(*,*) 'nr nz ke = ',nr,nz,ke

allocate(x(nr))
allocate(y(nz))
allocate(psi(nr,nz))
allocate(xu(ke))
allocate(yu(ke))

!write(*,*) 'test1'
x(1:nr) = equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%grid%dim1(1:nr)
y(1:nz) = equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%grid%dim2(1:nz)


!write(*,*) 'test2'

    !do i=1,nz
    !do j=1,nr
    !  psi(j,i) = equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%psi(i,j)
    !enddo
    !enddo
    psi = equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%psi

!write(*,*) 'test3'
xu(1:ke) = wall%description_2d(1)%limiter%unit(1)%outline%r(1:ke)
!xu(1:ke) = equilibrium%time_slice(CurTimeStep)%coordinate_system%r(1:ke,1)

!write(*,*) 'test4'
yu(1:ke) = wall%description_2d(1)%limiter%unit(1)%outline%z(1:ke)
!yu(1:ke) = equilibrium%time_slice(CurTimeStep)%coordinate_system%z(1:ke,1)

!write(*,*) 'test5'

tt = equilibrium%time(CurTimeStep)


psi_ax = equilibrium%time_slice(CurTimeStep)%global_quantities%psi_axis
psi_bnd = equilibrium%time_slice(CurTimeStep)%global_quantities%psi_boundary

    i_wr=0
    if(i_wr.eq.1)then

    call write_graf_imas2(nr,nz,ke, &
     &	0.01d0,0.01d0,tt,&
     &  psi,x,y,xu,yu,&
     &  psi_ax,psi_bnd,psi_bnd,0.d0,0.d0) 

    end if
    

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
