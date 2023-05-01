	include 'double.inc'

	character *20 yy

      parameter (kint=300)
      
      dimension c_input1(kint),c_input2(kint)
      dimension c_output1(kint),c_output2(kint),c_output3(kint)

! define local fixed size variables
      integer :: i, k, j, isrc, ion
      integer :: kloop,kprobe, ke=57, ngrid2
      integer :: nact=30, npass=300 , nelem = 1
      integer :: n_input1, n_input2, ng
      integer :: n_output1, n_output2
          
      integer ::  kpr
      common /ge5/kpr
      integer   ::  ih_imas
      common /c_imas_is/ih_imas
      integer   ::  ih_imas_c
      common /c_k_jetto/ih_imas_c


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
        
     
      call  dina_v96_in(ncam2,npf2,kloop,kprobe,
     * gridrange,nact,npass,
     * fluxarr,vesarr, pslgreen,bprgreen,
     * pfind,pmj,pfc, pfres,rcam,
     * xu,yu,ke,key,
     * pfgreen,vesgreen,pfprobe,
     * vesprobe,ngrid)


       call dina_input2(tt,tpl, n,a, pptab,fptab,
     * ncam2,tcam, npf2,pf,rmag,zmag,psi_tr,rs0,bt0)


       call dina_input(te0,tq0,pne,
     * pd0,pt0,sigma,jbut,aj0,qe0,qq0)

    

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))
      
      
       call dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3)


	call dina_outp(n, tpl, tt, 
     * a, ai,
     * rs0,bt0,
     * x,y,psi,curr_d,
     * psi_tr,psi_eq,phi_1D,
     * fpol,pptab,fptab,
     * tok1,q,
     * vchopper,pf,tcam,
     * te0,tq0,press,zeff,
     * qe0,qq0,
     * pne,pd0,pt0,
     * sigma,jbut,aj0,ajae,
     * bprobe,psloop,
     * psi_ax, psi_bnd, psi_sep, psi_sep2,
     * ksepa,key_lh,
     * surface_1d,volume_1d,area_1d,
     * n_bnd,xbound,ybound,
     * n_sep,x_sep,y_sep,
     * n_sep2,x_sep2,y_sep2,
     * n_ga_dina,gaps,
     * betap,betat,
     * tene,teit_98)
     

        call dina_wr_output(wr_imas)


      end
      