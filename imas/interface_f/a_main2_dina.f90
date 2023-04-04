	include 'double.inc'

	character *20 yy

      parameter (kint=300)
      
      dimension c_input1(kint),c_input2(kint)
      dimension c_output1(kint),c_output2(kint),c_output3(kint)

! define local fixed size variables
integer,save :: i, k, j, isrc, ion
integer,save :: first_call = 1, loop_count = 0, ntime = 0
integer,save :: kloop,kprobe, ke=57, ngrid2
integer,save :: nact=30, npass=300 , nelem = 1
integer,save :: n_input1, n_input2, ng
integer,save :: n_output1, n_output2
          
integer ::  kpr
      common /ge5/kpr
integer   ::  ih_imas
     common /c_imas_is/ih_imas
integer   ::  ih_imas_c
     common /c_k_jetto/ih_imas_c

integer,save :: key(27)=(/ (0,i=1,27) /)

! static and prescribed data expressed in DINA terms
real *8,save :: dina_time=0
real *8,save :: time_8,tt_8,tay_8

real *8 ::time_eq

     common /c_imas_time_eq/time_eq
      common /c_time_eq/time_eq_c
      
real *8 ::time_eq_c

! DINA parameters
    integer,parameter :: npo = 310, ntet = 134 ! parf0
    integer,parameter :: mu1 = 1500 ! parf2
    integer,parameter :: nr = 65, nz = 129, ngrid = nr*nz ! parf2
    integer,parameter :: npf = 15, ncam = 100 ! parf1 - kf, mu
    integer,parameter :: npfa = 12, npfx = npf-npfa, npfp = npfx+ncam
    integer,parameter :: nflux=41, nbpol=60 ! parf4
    integer,parameter :: n_ions=7
    integer,parameter ::  n_gaps=6
    
    integer :: ksepa,key_lh,n_bnd,n_sep,n_sep2,n_ga_dina


real *8,save :: vec(npo) = (/ (0,i=1,npo) /)

! dynamic inputs and outputs groups
real *8,save :: input_1(npo) = (/ (0,i=1,npo) /)
real *8,save :: input_2(npo) = (/ (0,i=1,npo) /)
real *8,save :: input_3(npo) = (/ (0,i=1,npo) /)

real *8,save :: output_1(npo) = (/ (0,i=1,npo) /)
real *8,save :: output_2(npo) = (/ (0,i=1,npo) /)
real *8,save :: output_3(npo) = (/ (0,i=1,npo) /)
real *8,save :: output_4(npo) = (/ (0,i=1,npo) /)

    
    real *8,save :: tpl = 1000.0, tt = 0.0d0
    real *8,save :: psi_ax,psi_bnd,psi_sep,psi_sep2
    real *8,save :: rs0 = 1000.0, bt0 = 1000.0
    real *8,save :: betap, betat
    real *8,save :: tene,teit_98
    real *8,save :: pec
    real *8,save :: rmag, zmag

    real *8,save :: x(nr),y(nz),psi(nr,nz),psi1(nr,nz),curr_d(nr,nz)

    real *8,save :: a(npo),ai(npo),psi_tr(npo),psi_eq(npo),phi_1D(npo),tok1(npo),q(npo)

    real *8,save :: pd0(npo),pt0(npo),pne(npo),te0(npo),tq0(npo),press(npo),qe0(npo),qq0(npo)
    real *8,save :: sigma(npo),jbut(npo),aj0(npo),ajae(npo),zeff(npo)
    
    real *8,save :: xbound(ntet),ybound(ntet),x_sep(mu1),y_sep(mu1),x_sep2(mu1),y_sep2(mu1)
    real *8,save :: gaps(n_gaps)
    
    real *8,save :: vchopper(npf),pf(npf),tcam(ncam)

    real *8,save :: fpol(npo),pptab(npo),fptab(npo)

    real *8,save :: wr_imas(150)

!    real *8,save,parameter :: pi = 3.14159265358979323846
!    real *8,save :: coef_ppx,coef_pffx,pmu0
    
    real *8,save :: bprobe(nbpol), psloop(nflux)
    
    real *8,save :: surface_1d(npo),volume_1d(npo),area_1d(npo)
    
    real *8,save :: dsep_ref


  integer :: TimeSteps, CurTimeStep
  
  integer :: n1, n2, n ,i_wr

real *8,save ::  gridrange(4)
real*8, dimension(:,:), ALLOCATABLE,save :: fluxarr,vesarr,pslgreen,bprgreen,pfind,pmj
real*8, dimension(:,:), ALLOCATABLE,save :: pfc,pfgreen,vesgreen,pfprobe,vesprobe
real*8, dimension(:), ALLOCATABLE,save :: pfres, rcam, xu, yu

real*8,save :: cpu_old = 0.d0, cpu_new

real *8,save :: yfluxd_xx,yfluxt_xx,yfluxe_xx,yfluxi_xx,ysbound_xx

real *8,save :: pne_cop(npo),pd0_cop(npo),pt0_cop(npo)
 
	character *20 apr

	
real *8,save :: cocos_psi = -1.d0

 !     kpr=1

      print *,' -------- a_main=',a_main

      call dina_data_read()
      call general_data_read()

      call congig_calc()

       call  read_green_params(&
     &       npass,nact,kloop,kprobe,ke,ngrid2)

        

      print *,'npass',npass
      print *,'nact',nact
      print *,'kloop',kloop
      print *,'kprobe',kprobe
      print *,'ke',ke

      print *,'ngrid ngrid2',ngrid,ngrid2



ALLOCATE(fluxarr(ngrid,nact))
ALLOCATE(vesarr(ngrid,npass))
ALLOCATE(pslgreen(ngrid,kloop))
ALLOCATE(bprgreen(ngrid,kprobe))

ALLOCATE(vesgreen(kloop,npass))
ALLOCATE(vesprobe(kprobe,npass))

ALLOCATE(pfgreen(kloop,nact))
ALLOCATE(pfprobe(kprobe,nact))

ALLOCATE(pfind(nact,nact))
ALLOCATE(pmj(npass,npass))
ALLOCATE(pfc(npass,nact))

ALLOCATE(pfres(nact))
ALLOCATE(rcam(npass))

ALLOCATE(xu(ke))
ALLOCATE(yu(ke))


  write(*,*) 'Shapes of locally allocated arrays'
  write(*,100) shape(fluxarr),shape(vesarr),shape(pslgreen),shape(bprgreen)
  write(*,100) shape(pfgreen),shape(vesgreen),shape(pfprobe),shape(vesprobe)
  write(*,100) shape(pfind),shape(pmj),shape(pfc)
  write(*,100) shape(pfres),shape(rcam),shape(xu),shape(yu)

100 format (2I5, 4x,2I5, 4x, 2I5, 4x,2I5)




	call read_greens(npass,nact,kloop,kprobe,ngrid2,&
& 	x,y,&
&	fluxarr,vesarr, pslgreen,bprgreen,&
&	pfind,pmj,pfc, pfres,rcam,&
&	xu,yu,ke,&
&   pfgreen,vesgreen,pfprobe,&
&   vesprobe)


    write(*,*) "fluxarr(1:3)=",fluxarr(1,1:3)
  write(*,*) "vesarr(1:3)=",vesarr(1,1:3)
  write(*,*) "pslgreen(1:3)=",pslgreen(1,1:3)
  write(*,*) "bprgreen(1:3)=",bprgreen(1,1:3)
  write(*,*) "pfres(1:3)=",pfres(1:3)
  write(*,*) "rcam(1:3)=",rcam(1:3)

gridrange(1)=y(1)
gridrange(2)=y(nz)
gridrange(3)=x(1)
gridrange(4)=x(nr)


  write(*,*) "limiterxu(1:3)=", xu(1:3)
  write(*,*) "limiteryu(1:3)=", yu(1:3)
  write(*,*) "gridrange=",gridrange

flush(6)

     ncam2=npass
     npf2=nact
     
     call  dina_v96_in(ncam2,npf2,kloop,kprobe,&
& 	gridrange,nact,npass,&
&	fluxarr,vesarr, pslgreen,bprgreen,&
&	pfind,pmj,pfc, pfres,rcam,&
&	xu,yu,ke,key,&
&   pfgreen,vesgreen,pfprobe,&
&   vesprobe,ngrid)


          ih_imas=ih_imas_c
 !        close (49)
         
        print *,'from k_jetto.dat  ih_imas =',ih_imas

! 		 open (unit=40,file='time_eq.dat',form='formatted') 
!          read (49,*) 
!          read (49,*)time_eq
          time_eq=time_eq_c
!         close (41)
         
        print *,'from time_eq.dat  time_eq =',time_eq

	  open(11,file='restart.dat')
      read (11,*)	  
      read (11,*)i_restart,tt_restart
      read (11,*)	  
      read (11,*)time1,time2,nstep


      print *,'i_restart tt_restart =',i_restart,tt_restart
      print *,'time1,time2,nstep =',time1,time2,nstep

	  close(11)



    rs0=620.e-2 
    bt0=53.e-1;
    
    if(i_restart.eq.1)then

!    tt=4917.6978120551245e-3

    tt=tt_restart
    print *,'i_restart tt =',i_restart,tt

!	tt = %time
!	tpl =ip
!	n = %rho_tor_norm
!	a(1:n) =profiles_1d%rho_tor_norm(1:n)
!	psi_tr(1:n) = cocos_psi *%psi(1:n)
!    bt0 = %b0(1)
!	rs0 = %r0
!	rmag=%magnetic_axis%r ![m]
!    zmag=%magnetic_axis%z ![m]

!	pptab(1:n) = cocos_psi * %dpressure_dpsi(1:n)
!	fptab(1:n) = cocos_psi * %f_df_dpsi(1:n)
  
!	do i=1,npf
!	  pf(i) =  %current%data(CurTimeStep)
!	 print *,' i pf==',i,pf(i)
!	enddo

!	do i=1,ncam
!	  tcam(i) = %current(CurTimeStep)
!	enddo	

    call shape_equil2_c(&
     &  tt,n,pptab,fptab,&
     &  npf2,pf,&
     &  ncam2,tcam,tpl,kpr,&
     &  rmag,zmag,&
     &  psi_tr)

       apr='--pptab-' 
      print 71,apr,(pptab(i),i=1,n) 

 !     stop

       call dina_input2(tt,tpl, n,a, pptab,fptab &
     & , ncam2,tcam, npf2,pf,rmag,zmag,psi_tr,rs0,bt0)

      print *,'tt tpl=',tt,tpl

 !     stop
      
	    call prof_in_test2_c(tt,n,&
     &  te0,tq0,pne,&
     &  pd0,pt0,sigma,jbut,aj0,qe0,qq0,kpr)

      	call dina_input(te0,tq0,pne, &
     &  pd0,pt0,sigma,jbut,aj0,qe0,qq0)

    end if
    

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do k=1,999993

      if(k.gt.1)then          

	    call prof_in_test2_c(tt,n,&
     &  te0,tq0,pne,&
     &  pd0,pt0,sigma,jbut,aj0,qe0,qq0,kpr)

      apr='--te0-' 
      print 71,apr,(te0(i),i=1,n1) 
      apr='--tq0-' 
      print 71,apr,(tq0(i),i=1,n1) 

      apr='--&pne-' 
      print 71,apr,(pne(i),i=1,n1) 
      apr='--&pd0-' 
      print 71,apr,(pd0(i),i=1,n1) 
      apr='--&pt0-' 
      print 71,apr,(pt0(i),i=1,n1) 

      apr='--qe0-' 
      print 71,apr,(qe0(i),i=1,n1) 
      apr='--qq0-' 
      print 71,apr,(qq0(i),i=1,n1) 


      	call dina_input(te0,tq0,pne, &
     & pd0,pt0,sigma,jbut,aj0,qe0,qq0)
      end if
      
      
	  call dina2(&
!-----------------------------------  inputs---
     &  c_input1,c_input2,&
!------------------------------------outputs
     &  c_output1,c_output2,c_output3)


       if(kpr.gt.0)print *,' -------- k tt t_vde=',k,tt,t_vde

       if(k.gt.700000)then
       stop
       end if
       
       t_vde=80.e3
       
       
        write(*,*) "DINA_IMAS inputs deallocated"
      flush(6)


write(*,*) '!!!dina_outp enter'
	call dina_outp(n, tpl, tt, &
     & a, ai,&
     & rs0,bt0,&
     & x,y,psi,curr_d,&
     & psi_tr,psi_eq,phi_1D,&
     & fpol,pptab,fptab,&
     & tok1,q,&
     & vchopper,pf,tcam,&
     & te0,tq0,press,zeff,&
     & qe0,qq0,&
     & pne,pd0,pt0,&
     & sigma,jbut,aj0,ajae,&
     & bprobe,psloop,&
     & psi_ax, psi_bnd, psi_sep, psi_sep2,&
     & ksepa,key_lh,&
     & surface_1d,volume_1d,area_1d,&
     & n_bnd,xbound,ybound,&
     & n_sep,x_sep,y_sep,&
     & n_sep2,x_sep2,y_sep2,&
     & n_ga_dina,gaps,&
     & betap,betat,&
     & tene,teit_98)
     
     n1=n

        call dina_wr_output(wr_imas)

!        %magnetic_axis%r = wr_imas(13) ![m]
!        %magnetic_axis%z = wr_imas(14) ![m]

        rmag = wr_imas(13) ![m]
        zmag = wr_imas(14) ![m]

        if(kpr.gt.0)print *,' -------- k tt tpl=',k,tt,tpl
  	  
  	  write(6,'("  k time1 tt time2= ",i4,6(1pe12.5))'), &
     &  k,time1,tt,time2 

      if(time1.le.tt.and.tt.le.time2)then
      

         kstep=kstep+1

        	if(kstep.eq.nstep*(kstep/nstep).or.kstep.eq.1)then

	    write(6,'("  kstep  time1 tt time2= ",i4,6(1pe12.5))'), &
     &  kstep,time1,tt,time2



	    call wr_equil_c(&
     &  tt,n,pptab,fptab,&
     &  npf,pf,&
     &  ncam,tcam,tpl,kpr,&
     &  rmag,zmag,&
     &  psi_tr)

	    call prof_out_test2_c(tt,n,&
     &  te0,tq0,pne,&
     &  pd0,pt0,sigma,jbut,aj0,qe0,qq0)

        end if
        end if

        if(tt.gt.t_vde)then
       stop
       end if


      end do


      end

	subroutine dina4(&
!-----------------------------------  inputs---
     &  c_input1,c_input2,&
!------------------------------------outputs
     &  c_output1,c_output2,c_output3)

      include 'double.inc'

      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*),c_output3(*)
      
      
      return
      end
      