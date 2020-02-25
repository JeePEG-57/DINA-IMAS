!> dina_equil is the main subroutine to reproduce DANA equilibrium
!> As a result of call dina_v96_in the Green Functions are being transmitted to DINA from IDSs
!> After call dina_input the initial kinetic profiles are being transmitted to DINA from IDSs   
!> As a result of call dina2 the DINA modeling in one time step is being produced
!> After call dina_outp the output data are being recorded to IDS and dat files


subroutine dina_equil(&
  &  em_coupling0, equilibrium0, pf_active0, pf_passive0 &
  & ,equilibrium)


use ids_schemas
use ids_routines
implicit none


! trees are static or dynamic; if not defined, they are static
type (ids_em_coupling)  :: em_coupling0
type (ids_equilibrium) :: equilibrium0, equilibrium
type (ids_pf_active)   :: pf_active0
type (ids_pf_passive)   :: pf_passive0


! define local fixed size variables
integer,save :: i, k,  j, its
integer,save :: first_call = 1, loop_count = 0, ntime = 0

integer,save :: kloop,kprobe, ke=57, ngrid2

integer,save :: nact=30, npass=300 , nflux=60, nbpol=70, nelem = 1

integer,save :: n_input1, n_input2, ng
integer,save :: n_output1, n_output2

integer,save ::  n_gaps=6
          
integer ::  kpr

      common /ge5/kpr

integer   ::  ih_imas
     common /c_imas_is/ih_imas


integer,save :: key(27)=(/ (0,i=1,27) /)

! static and prescribed data expressed in DINA terms
real (ids_real),save :: dina_time=0
real (ids_real),save :: time_8,tt_8,tay_8

real(ids_real) ::time_eq

     common /c_imas_time_eq/time_eq

! DINA parameters
    integer,parameter :: npo = 500
    integer,parameter :: ntet = 134
    integer,parameter :: nr = 65, nz = 129, ngrid = nr*nz
    integer,parameter :: npf = 15, ncam = 100

    
      integer,parameter :: kint=200      
      real (ids_real),dimension(:) :: c_input1(kint),c_input2(kint)
      real (ids_real),dimension(:) :: c_output1(kint),c_output2(kint),c_output3(kint)
      
      
real (ids_real),save :: vec(npo) = (/ (0,i=1,npo) /)

! dynamic inputs and outputs groups
real (ids_real),save :: input_1(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: input_2(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: input_3(npo) = (/ (0,i=1,npo) /)

real (ids_real),save :: output_1(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: output_2(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: output_3(npo) = (/ (0,i=1,npo) /)
real (ids_real),save :: output_4(npo) = (/ (0,i=1,npo) /)

    
    real(ids_real) :: tpl=1000.0,uli=1000.0,v=1000.0,parea=1000.0,psi_ax=1000.0,rmag=1000.0,zmag=1000.0 &
  & ,q_ax=1000.0,q_95=1000.0,rs0=1000.0,bt0=1000.0,wen2=1000.0,tt = 1.0,psi_bnd = 1000.0 &
  & ,rmajor,rminor,elong,tri
    real(ids_real) :: betap,betat,tec,tqc,pec,pic,zeff,vloop,tene,wfus,emag

    real(ids_real) :: x(nr),y(nz),psi(nr,nz),psi1(nr,nz),curr_d(nr,nz)

    real(ids_real) :: ai(npo),te0(npo),tq0(npo),pne(npo),tok1(npo),q(npo)

    real(ids_real) :: pd0(npo),pt0(npo),sigk(npo),jbut(npo),aj0(npo),qe0(npo),qq0(npo)
    
    real(ids_real) :: xbound(ntet),ybound(ntet)
    
    real(ids_real) :: vchopper(npf),pf(npf),tcam(ncam)
    
    real(ids_real) :: pstab(npo), pptab(npo),fptab(npo)

    real(ids_real),parameter :: pi = 3.14159265358979323846


  integer :: TimeSteps, CurTimeStep
  
  integer :: n1, n2, n ,i_wr

real (ids_real),save ::  gridrange(4)
real(ids_real), dimension(:,:), ALLOCATABLE,save :: fluxarr,vesarr,pslgreen,bprgreen,pfind,pmj
real(ids_real), dimension(:,:), ALLOCATABLE,save :: pfc,pfgreen,vesgreen,pfprobe,vesprobe
real(ids_real), dimension(:), ALLOCATABLE,save :: pfres, rcam, xu, yu

real(ids_real),save :: cpu_old = 0.d0, cpu_new

real(ids_real) :: yfluxd_xx,yfluxt_xx,yfluxe_xx,yfluxi_xx,ysbound_xx


print *,'DINA_EQUIL Enter'
flush(6)


if (first_call == 1) then 



100 format (2I5, 4x,2I5, 4x, 2I5, 4x,2I5)



first_call = first_call+1 ! cancel the initialisation for the next call

else


end if ! end of first_call



loop_count = loop_count + 1 ! number of times the iterative routine was entered

write(*,*) 'dina_imas loop, first_call = ', first_call, loop_count



if (equilibrium0%time_slice(1)%global_quantities%ip .gt. 2.e3) then


      n_input1=2
!      n_input2=15
      n_input2=38


     its = 1
     
	tt = equilibrium0%time_slice(its)%time
	tpl = equilibrium0%time_slice(its)%global_quantities%ip
	n = size(equilibrium0%time_slice(its)%profiles_1d%rho_tor_norm)
	pstab(1:n) = equilibrium0%time_slice(its)%profiles_1d%rho_tor_norm(1:n)
	pptab(1:n) = equilibrium0%time_slice(its)%profiles_1d%dpressure_dpsi(1:n)
	
	fptab(1:n) = equilibrium0%time_slice(its)%profiles_1d%f_df_dpsi(1:n)
	
	!ncam = size(pf_passive0%loop, 1)
	do i=1,ncam
	  tcam(i) = pf_passive0%loop(i)%current(1)
	enddo
	
	!npf = size(pf_active0%coil, 1)
	do i=1,npf
	  pf(i) =  pf_active0%coil(i)%current%data(1)
	enddo
     
     
     call dina_input(tt,tpl, n,pstab, pptab,fptab &
     & , ncam,tcam, npf,pf)
     
     
     call dina2(&
!-----------------------------------  inputs---
     &  c_input1,c_input2,&
!------------------------------------outputs
     &  c_output1,c_output2,c_output3)
     
     
write(*,*) '!!!dina_outp enter'
	call dina_outp(n,  &
     & tpl,uli,v,parea,psi_ax,rmag,zmag,  &
     & q_ax,q_95,rs0,bt0,wen2,tt,  &
     & ai,te0,tq0,pne,tok1,q,  &
     & x,y,psi,psi_bnd,curr_d,  &
     & xbound,ybound,rmajor,rminor,elong,tri, &
     & pd0,pt0,sigk,jbut,aj0,qe0,qq0, &
     & betap,betat,tec,tqc,pec,pic,zeff,vloop,tene,wfus,emag, &
     & vchopper,pf,tcam)
     

    dina_time=tt
 
    write(*,*) 'dina_outp call n tpl tt= ', n,tpl,tt


    flush(6)
    

	call cpu_time(cpu_new)

	write(*,*) 'CPUTime = ', cpu_new-cpu_old

	call write_cputime(cpu_new-cpu_old, cpu_new, 0)

	cpu_old = cpu_new



! Allocations equilibrium

    allocate(equilibrium%time_slice(TimeSteps))
    allocate(equilibrium%time(TimeSteps))
  
    
    n1 = nz
    n2 = nr

    !allocate(equilibrium%coordinate_system%grid%dim1(n1,TimeSteps))
    !allocate(equilibrium%coordinate_system%grid%dim2(n2,TimeSteps))
    allocate(equilibrium%time_slice(CurTimeStep)%coordinate_system%r(ke,1))
    allocate(equilibrium%time_slice(CurTimeStep)%coordinate_system%z(ke,1))


    allocate(equilibrium%time_slice(CurTimeStep)%profiles_1d%rho_tor_norm(n))
    allocate(equilibrium%time_slice(CurTimeStep)%profiles_1d%surface(n))
    allocate(equilibrium%time_slice(CurTimeStep)%boundary%outline%r(ntet))
    allocate(equilibrium%time_slice(CurTimeStep)%boundary%outline%z(ntet))
    allocate(equilibrium%time_slice(CurTimeStep)%boundary%lcfs%r(ntet))
    allocate(equilibrium%time_slice(CurTimeStep)%boundary%lcfs%z(ntet))


    allocate(equilibrium%time_slice(CurTimeStep)%profiles_2d(1))
    allocate(equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%psi(nz,nr))
    allocate(equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%j_tor(nz,nr))
    
    allocate(equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%grid%dim1(nz))
    allocate(equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%grid%dim2(nr))
    
    
    allocate(equilibrium%vacuum_toroidal_field%b0(TimeSteps))
  
! Filling equilibrium 

    equilibrium%ids_properties%homogeneous_time = 1
    equilibrium%time_slice(CurTimeStep)%profiles_1d%rho_tor_norm(1:n) = ai(1:n)
    
    
    equilibrium%time_slice(CurTimeStep)%global_quantities%ip = tpl ![A]
	equilibrium%time_slice(CurTimeStep)%global_quantities%li_3 = uli
	equilibrium%time_slice(CurTimeStep)%global_quantities%volume = v ![m3]
	equilibrium%time_slice(CurTimeStep)%global_quantities%area = parea ![m2]
	equilibrium%time_slice(CurTimeStep)%global_quantities%psi_axis= psi_ax ![Wb]
	equilibrium%time_slice(CurTimeStep)%global_quantities%psi_boundary = psi_bnd ![Wb]
	equilibrium%time_slice(CurTimeStep)%global_quantities%magnetic_axis%r = rmag ![m]
	equilibrium%time_slice(CurTimeStep)%global_quantities%magnetic_axis%z = zmag ![m]
	equilibrium%time_slice(CurTimeStep)%global_quantities%q_axis = q_ax
	equilibrium%time_slice(CurTimeStep)%global_quantities%q_95 = q_95
	equilibrium%time_slice(CurTimeStep)%global_quantities%w_mhd = wen2 ![J]

        equilibrium%time_slice(CurTimeStep)%boundary%geometric_axis%r = rmajor
        equilibrium%time_slice(CurTimeStep)%boundary%minor_radius = rminor
        equilibrium%time_slice(CurTimeStep)%boundary%elongation = elong
        equilibrium%time_slice(CurTimeStep)%boundary%triangularity = tri

        equilibrium%time_slice(CurTimeStep)%global_quantities%surface = ysbound_xx
        equilibrium%time_slice(CurTimeStep)%profiles_1d%surface(n) = ysbound_xx

	equilibrium%vacuum_toroidal_field%r0 = rs0 ![m]
	equilibrium%vacuum_toroidal_field%b0(CurTimeStep) = bt0 ![T]
    
    equilibrium%time_slice(CurTimeStep)%boundary%outline%r(1:ntet) = xbound(1:ntet)
    equilibrium%time_slice(CurTimeStep)%boundary%outline%z(1:ntet) = ybound(1:ntet)
    equilibrium%time_slice(CurTimeStep)%boundary%lcfs%r(1:ntet) = xbound(1:ntet)
    equilibrium%time_slice(CurTimeStep)%boundary%lcfs%z(1:ntet) = ybound(1:ntet)

    !equilibrium%time_slice(CurTimeStep)%coordinate_system%grid%dim1(1:n1)=x(1:n1) ![m]
    !equilibrium%time_slice(CurTimeStep)%coordinate_system%grid%dim2(1:n2)=y(1:n2) ![m]

    equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%grid%dim1(1:nz)=y(1:nz)
    equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%grid%dim2(1:nr)=x(1:nr)


  !  call write_graf_imas0(nr,nz,ke, &
  !   &	0.01d0,0.01d0,tt,&
  !   &  psi,x,y,xu,yu,&
  !   &  psi_ax,psi_bnd,psi_bnd,0.d0,0.d0) 



    do i=1,nz
    do j=1,nr
      equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%psi(i,j)=psi(j,i)
      equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%j_tor(i,j)=curr_d(j,i)
    enddo
    enddo
    

    do i=1,nz
    do j=1,nr
      psi1(j,i) = equilibrium%time_slice(CurTimeStep)%profiles_2d(1)%psi(i,j)
    enddo
    enddo

    i_wr=0
    if(i_wr.eq.1)then


    call write_graf_imas(nr,nz,ke, &
     &	0.01d0,0.01d0,tt,&
     &  psi1,x,y,xu,yu,&
     &  psi_ax,psi_bnd,psi_bnd,0.d0,0.d0) 

    end if
    

    equilibrium%time_slice(CurTimeStep)%coordinate_system%r(1:ke,1) = xu(1:ke)
    equilibrium%time_slice(CurTimeStep)%coordinate_system%z(1:ke,1) = yu(1:ke)


    equilibrium%time_slice(CurTimeStep)%time = tt
    equilibrium%time(CurTimeStep) = tt ![s]
    

    
flush(6)


else

call ids_copy(equilibrium0, equilibrium)

endif

    
return
end subroutine



	subroutine write_graf_imas(nr,nz,ke,&
     &	dx,dy,ttt,&
     &  psi,x,y,xu,yu,&
     &  pmag,pbound,p_s,um,vm) 

        integer :: nr,nz,ke
	real*8,dimension(:,:) :: psi(nr,nz)
	real*8,dimension(:) :: x(nr),y(nz),xu(ke),yu(ke)

	real(8) :: dx,dy,ttt,pmag,pbound,p_s,um,vm
	

5000	format(4(1x,1pe14.7))
	
	write(*,*) 'Write Graph Enter...'

	open (unit=61,file='psi_data_imas',access='append',form='formatted')



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

	subroutine write_graf_imas0(nr,nz,ke,&
     &	dx,dy,ttt,&
     &  psi,x,y,xu,yu,&
     &  pmag,pbound,p_s,um,vm) 

        integer :: nr,nz,ke
	real*8,dimension(:,:) :: psi(nr,nz)
	real*8,dimension(:) :: x(nr),y(nz),xu(ke),yu(ke)

	real(8) :: dx,dy,ttt,pmag,pbound,p_s,um,vm
	

5000	format(4(1x,1pe14.7))
	
	write(*,*) 'Write Graph Enter0...'

	open (unit=61,file='psi_data_imas0',access='append',form='formatted')



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


	subroutine write_cputime(deltatime, time, flag_start)

	real(8) :: deltatime, time
	integer :: flag_start

6000	format(4(1x,1pe14.7))
	
	write(*,*) 'Write CPU time...'

	if (flag_start.eq.1) call system("rm cputime_dinaimas")

	open (unit=62,file='cputime_dinaimas',access='append',form='formatted')

	if (flag_start.eq.1) then
		write(62,*) "     Step    ","     Absolute"
	else
		write (62,6000) deltatime, time
	end if

        close (62)

        
        
	return
	end


subroutine schedulefiles(schedule,equil)
use ids_schemas
use ids_routines
implicit none
type (ids_equilibrium) :: equil
type (ids_pulse_schedule) :: schedule
integer :: i,nt,io,iv, n_z
real(8) :: t, v, u

integer :: n1,n2,n3,n4,n5,n6,n7,n8
real(8) :: x1,x2,x3,x4,x5,x6,x7,x8

7000	format(4(1x,1pe14.7))


open(unit=44,file='ech.dat',action='write',access='sequential')
nt=size(schedule%ec%launcher(1)%power%reference%time)

print *,' nt==',nt

write(44,*) 'Time points'
write(44,*) nt
write(44,*) 'Time  Power'
do i=1,nt
t = schedule%ec%launcher(1)%power%reference%time(i)
print *,'i t',i,t
v = schedule%ec%launcher(1)%power%reference%data(i)*1.d-6
print *,' v==',v
write(44,*) t, v
enddo
close(44)


open(unit=44,file='emo.dat',action='write',access='sequential')
nt=size(schedule%ec%launcher(2)%power%reference%time)
write(44,*) 'Time points'
write(44,*) nt
write(44,*) 'Time  Power'
do i=1,nt
t = schedule%ec%launcher(2)%power%reference%time(i)
v = schedule%ec%launcher(2)%power%reference%data(i)*1.d-6
u = schedule%ec%launcher(3)%power%reference%data(i)*1.d-6
write(44,*) t, v, u
enddo
close(44)


open(unit=44,file='dens.dat',action='write',access='sequential')
nt=size(schedule%density_control%valve(1)%flow_rate%reference%time)
write(44,*) 'Time points'
write(44,*) nt
write(44,*) 'Time  Density'
do i=1,nt
t = schedule%density_control%valve(1)%flow_rate%reference%time(i)
v = schedule%density_control%valve(1)%flow_rate%reference%data(i)
write(44,*) t, v
enddo
close(44)


open(unit=44,file='n_d.dat',action='write',access='sequential')
nt=size(schedule%density_control%valve(7)%flow_rate%reference%time)
write(44,*) 'Time_points  t_bar'
write(44,*) nt
write(44,*) 'Time  Density'
do i=1,nt
t = schedule%density_control%valve(7)%flow_rate%reference%time(i)
v = schedule%density_control%valve(7)%flow_rate%reference%data(i)
write(44,*) t, v
enddo
close(44)


iv = 2
open(unit=44,file='gamma_z.dat',action='write',access='sequential')
nt=size(schedule%density_control%valve(iv)%flow_rate%reference%time)
n_z=schedule%density_control%valve(iv)%species(1)%element(1)%z_n
write(44,*) 'Time_points  t_bar'
write(44,*) nt, n_z
write(44,*) 'Time  Density'
do i=1,nt
t = schedule%density_control%valve(iv)%flow_rate%reference%time(i)
v = schedule%density_control%valve(iv)%flow_rate%reference%data(i)
write(44,*) t, v
enddo
close(44)


iv = 3
open(unit=44,file='gamma_z1.dat',action='write',access='sequential')
nt=size(schedule%density_control%valve(iv)%flow_rate%reference%time)
n_z=schedule%density_control%valve(iv)%species(1)%element(1)%z_n
write(44,*) 'Time_points  t_bar'
write(44,*) nt, n_z
write(44,*) 'Time  Density'
do i=1,nt
t = schedule%density_control%valve(iv)%flow_rate%reference%time(i)
v = schedule%density_control%valve(iv)%flow_rate%reference%data(i)
write(44,*) t, v
enddo
close(44)


iv = 4
open(unit=44,file='gamma_z2.dat',action='write',access='sequential')
nt=size(schedule%density_control%valve(iv)%flow_rate%reference%time)
n_z=schedule%density_control%valve(iv)%species(1)%element(1)%z_n
write(44,*) 'Time_points  t_bar'
write(44,*) nt, n_z
write(44,*) 'Time  Density'
do i=1,nt
t = schedule%density_control%valve(iv)%flow_rate%reference%time(i)
v = schedule%density_control%valve(iv)%flow_rate%reference%data(i)
write(44,*) t, v
enddo
close(44)


iv = 5
open(unit=44,file='gamma_z3.dat',action='write',access='sequential')
nt=size(schedule%density_control%valve(iv)%flow_rate%reference%time)
n_z=schedule%density_control%valve(iv)%species(1)%element(1)%z_n
write(44,*) 'Time_points  t_bar'
write(44,*) nt, n_z
write(44,*) 'Time  Density'
do i=1,nt
t = schedule%density_control%valve(iv)%flow_rate%reference%time(i)
v = schedule%density_control%valve(iv)%flow_rate%reference%data(i)
write(44,*) t, v
enddo
close(44)


iv = 6
open(unit=44,file='gamma_z4.dat',action='write',access='sequential')
nt=size(schedule%density_control%valve(iv)%flow_rate%reference%time)
n_z=schedule%density_control%valve(iv)%species(1)%element(1)%z_n
write(44,*) 'Time_points  t_bar'
write(44,*) nt, n_z
write(44,*) 'Time  Density'
do i=1,nt
t = schedule%density_control%valve(iv)%flow_rate%reference%time(i)
v = schedule%density_control%valve(iv)%flow_rate%reference%data(i)
write(44,*) t, v
enddo
close(44)



v = equil%vacuum_toroidal_field%r0*1.d2 !meters to sm
u = equil%vacuum_toroidal_field%b0(1)*1.d1 !Tesla to kG

     	open(unit=44,file='for002_tmp',action='write',access='sequential')

	open(unit=2,file='for002',form='formatted',action='read')
        print *,' begin for002 reading'

	read (2,*) ; write(44,*) 'nrad(24)       mplasma    next(15)'
	read (2,*)n1,n2,n3 ; write(44,*) n1,n2,n3
	read (2,*) ; write(44,*) 'tt(2500.)    tay        t_end(900.)      RS0       psend'
	read (2,*)x1,x2,x3,x4,x5 ; write(44,*) x1,x2,x3,v,x5 !x4 is R for toroidal field
	read (2,*) ; write (44,*) 'i_graph'
	read (2,*)n1 ; write (44,*) n1
	read (2,*) ; write (44,*) 'ALFA0      BETA (0.01)     alfa1 (-1.3)  omega(0.33)'
	read (2,*)x1,x2,x3,x4 ; write(44,*) x1,x2,x3,x4
	read (2,*) ; write (44,*) 'iread      kzero      IWRITE     kEFIT'
	read (2,*)n1,n2,n3,n4 ; write(44,*) n1,n2,n3,n4
	read (2,*) ; write (44,*) 'alfax1     alfax2     betax1     betax2'
	read (2,*)x1,x2,x3,x4 ; write(44,*) x1,x2,x3,x4
	read (2,*) ; write (44,*) 'pw_1       pw_2'
	read (2,*)x1,x2 ; write(44,*) x1,x2
	read (2,*) ; write (44,*) 'te_a       ti_a       te_b      ti_b    pw_e'
	read (2,*)x1,x2,x3,x4,x5 ; write(44,*) x1,x2,x3,x4,x5
	read (2,*) ; write (44,*) 'pd0_a      pt0_a      pd0_b     pt0_b   pw_p'
	read (2,*)x1,x2,x3,x4,x5 ; write(44,*) x1,x2,x3,x4,x5
	read (2,*) ; write (44,*) 'zeff_a    zeff_b'
	read (2,*)x1,x2 ; write(44,*) x1,x2
	read (2,*) ; write (44,*) 'SIG0'
	read (2,*)x1 ; write(44,*) x1
	read (2,*) ; write (44,*) 'zhib,tego,zalfa,talfa,alp1'
	read (2,*)x1,x2,x3,x4,x5 ; write(44,*) x1,x2,x3,x4,x5
	read (2,*) ; write (44,*) 'ktp,kpin,ken,ken1,ken2,kd2,nal'
	read (2,*)n1,n2,n3,n4,n5,n6,n7 ; write(44,*) n1,n2,n3,n4,n5,n6,n7
	read (2,*) ; write (44,*) 'alpy,   ppp,    eee,    dd,     dt,     dh,     df'
	read (2,*)x1,x2,x3,x4,x5,x6,x7 ; write(44,*) x1,x2,x3,x4,x5,x6,x7
	read (2,*) ; write (44,*) 'lt,     ld,   lh,   ll, lm, it, id, ih'
	read (2,*)n1,n2,n3,n4,n5,n6,n7,n8 ; write(44,*) n1,n2,n3,n4,n5,n6,n7,n8
	read (2,*) ; write (44,*) 'eps0,eps1,eps2'
	read (2,*)x1,x2,x3 ; write(44,*) x1,x2,x3
	read (2,*) ; write (44,*) 'anom_e,anom_i,key_t11,kcchp'
	read (2,*)x1,x2,n1,n2 ; write(44,*) x1,x2,n1,n2
	read (2,*) ; write (44,*) 'edope   edopi'
	read (2,*)x1,x2 ; write(44,*) x1,x2
	read (2,*) ; write (44,*) 'udd'
	read (2,*)x1 ; write(44,*) x1
	read (2,*) ; write (44,*) 'k_ener    k_uv'
	read (2,*)n1,n2 ; write(44,*) n1,n2
	read (2,*) ; write (44,*) 't_dop'
	read (2,*)x1 ; write(44,*) x1
	read (2,*) ; write (44,*) 'r0,z0,zref'
	read (2,*)x1,x2,x3 ; write(44,*) x1,x2,x3
	read (2,*) ; write (44,*) 'kzref    krref(2)   key_b  i_pf'
	read (2,*)n1,n2,n3,n4 ; write(44,*) n1,n2,n3,n4
	read (2,*) ; write (44,*) 'i_c'
	read (2,*)n1 ; write(44,*) n1
	read (2,*) ; write (44,*) 'q_vde'
	read (2,*)x1 ; write(44,*) x1
	read (2,*) ; write (44,*) 'tay_00,tay_th,t_disr'
	read (2,*)x1,x2,x3 ; write(44,*) x1,x2,x3
	read (2,*) ; write (44,*) 'd_tpl,tpl_end'
	read (2,*)x1,x2 ; write(44,*) x1,x2
	read (2,*) ; write (44,*) 'c_h,d_halo'
	read (2,*)x1,x2 ; write(44,*) x1,x2
	read (2,*) ; write (44,*) 'kmaj,li_drop,ndisrup,n_dif,nmix'
	read (2,*)n1,n2,n3,n4,n5 ; write(44,*) n1,n2,n3,n4,n5
	read (2,*) ; write (44,*) 'hpart,te_h'
	read (2,*)x1,x2 ; write(44,*) x1,x2
	read (2,*) ; write (44,*) 'i_d3d,i_iter,i_smal'
	read (2,*)n1,n2,n3 ; write(44,*) n1,n2,n3
	read (2,*) ; write (44,*) 'ngra,i_ramp,i_v,i_con'
	read (2,*)n1,n2,n3,n4 ; write(44,*) n1,n2,n3,n4
	read (2,*) ; write (44,*) 'tpl     bt0    eu(200 or 50)  elong'
	read (2,*)x1,x2,x3,x4 ; write(44,*) x1,u,x3,x4 !x2 is toroidal field
	read (2,*) ; write (44,*) 'e_sep'
	read (2,*)x1 ; write(44,*) x1
	read (2,*) ; write (44,*) 'i_beta,i_gap5'
	read (2,*)n1,n2 ; write(44,*) n1,n2
	read (2,*) ; write (44,*) 'i_br'
	read (2,*)n1 ; write(44,*) n1
	read (2,*) ; write (44,*) 'ind_r1  ind_r2  ind_z1   ind_z2'
	read (2,*)n1,n2,n3,n4 ; write(44,*) n1,n2,n3,n4
	read (2,*) ; write (44,*) 'key_ef'
	read (2,*)n1 ; write(44,*) n1
	read (2,*) ; write (44,*) 'res_coef'
	read (2,*)x1 ; write(44,*) x1
	read (2,*) ; write (44,*) 'n_polar'
	read (2,*)n1 ; write(44,*) n1

io = 0
do 
	read (2,*,iostat=io)
	if (io.eq.0) then
		write(44,*)
	else
		exit
	endif
enddo
	close(2)

	close(44)

call system("cp for002_tmp for002")
call system("rm for002_tmp")


return
end
