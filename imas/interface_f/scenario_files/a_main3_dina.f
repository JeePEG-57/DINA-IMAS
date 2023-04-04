        subroutine dina3(
!-----------------------------------  inputs---
     * c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3)

! DINA parameters
        parameter ( npo = 310, ntet = 134) ! parf0)
        parameter ( mu1 = 1500) ! parf2)
        parameter ( nr = 65, nz = 129, ngrid = nr*nz) ! parf2)
        parameter ( npf = 15, ncam = 100) ! parf1 - kf, mu)
        parameter ( npfa = 12, npfx = npf-npfa, npfp = npfx+ncam)
        parameter ( nflux=41, nbpol=60) ! parf4)
!        parameter ( n_ions=7, nloop=60, nprobe=60, ne=100)
        parameter ( n_ions=7, nloop=61, nprobe=90, ne=100)
        parameter (  n_gaps=6)

	include 'double.inc'

	character *20 yy

!      parameter (kint=300)
      
      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*),c_output3(*)

      common /ge5/kpr
      common /c_imas_is/ih_imas
      common /c_k_jetto/ih_imas_c
      common /c_imas_time_eq/time_eq
      common /c_time_eq/time_eq_c
      common /c_restart/time1,time2,nstep

    
!      real *8 tpl = 1000.0, tt = 0.0d0
!      real *8 psi_ax,psi_bnd,psi_sep,psi_sep2
!      real *8 rs0 = 1000.0, bt0 = 1000.0
!      real *8 betap, betat
!      real *8 tene,teit_98
!      real *8 pec
!      real *8 rmag, zmag

      dimension x(nr),y(nz),psi(nr,nz),psi1(nr,nz),curr_d(nr,nz)

      dimension a(npo),ai(npo),psi_tr(npo),psi_eq(npo),phi_1D(npo),
     * tok1(npo),q(npo)

      dimension pd0(npo),pt0(npo),pne(npo),te0(npo),tq0(npo),
     * press(npo),qe0(npo),qq0(npo)
      dimension sigma(npo),aj0(npo),ajae(npo),zeff(npo)
      real *8 jbut(npo)
    
      dimension xbound(ntet),ybound(ntet),x_sep(mu1),
     * y_sep(mu1),x_sep2(mu1),y_sep2(mu1)
      dimension gaps(n_gaps)
    
      dimension vchopper(npf),pf(npf),tcam(ncam)

      dimension fpol(npo),pptab(npo),fptab(npo)

      dimension wr_imas(150)
    
      dimension bprobe(nbpol), psloop(nflux)
    
      dimension surface_1d(npo),volume_1d(npo),area_1d(npo)

      dimension  gridrange(4)

      
      dimension fluxarr(ngrid,npf),vesarr(ngrid,ncam),
     * pslgreen(ngrid,nloop),
     * bprgreen(ngrid,nprobe),pfind(npf,npf),pmj(ncam,ncam)

      dimension pfc(ncam,npf),pfgreen(nloop,npf),
     * vesgreen(nloop,ncam),pfprobe(nprobe,npf),vesprobe(nprobe,ncam)
      dimension pfres(npf), rcam(ncam), xu(ne), yu(ne)

      dimension pne_cop(npo),pd0_cop(npo),pt0_cop(npo)
 
	character *20 apr

	
      cocos_psi = -1.d0



 !     kpr=1

      if(k.gt.0)goto 2323        

      print *,' -------- a_main  k=',k
      flush(6)
      
      call dina_data_read()
      call general_data_read()

      call congig_calc()

       call  read_green_params(
     &       npass,nact,kloop,kprobe,ke,ngrid2)

        

      print *,'npass',npass
      print *,'nact',nact
      print *,'kloop',kloop
      print *,'kprobe',kprobe
      print *,'ke',ke

      print *,'ngrid ngrid2',ngrid,ngrid2



 

       write(*,*) 'Shapes of locally allocated arrays'
       write(*,100) shape(fluxarr),shape(vesarr),
     *  shape(pslgreen),shape(bprgreen)
       write(*,100) shape(pfgreen),shape(vesgreen),
     *  shape(pfprobe),shape(vesprobe)
       write(*,100) shape(pfind),shape(pmj),shape(pfc)
       write(*,100) shape(pfres),shape(rcam),shape(xu),shape(yu)

100    format (2I5, 4x,2I5, 4x, 2I5, 4x,2I5)




	call read_greens(npass,nact,kloop,kprobe,ngrid2,
     & 	x,y,
     &	fluxarr,vesarr, pslgreen,bprgreen,
     &	pfind,pmj,pfc, pfres,rcam,
     &	xu,yu,ke,
     &   pfgreen,vesgreen,pfprobe,
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

         call  dina_v96_in(ncam2,npf2,kloop,kprobe,
     & 	gridrange,nact,npass,
     &	fluxarr,vesarr, pslgreen,bprgreen,
     &	pfind,pmj,pfc, pfres,rcam,
     &	xu,yu,ke,key,
     &   pfgreen,vesgreen,pfprobe,
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

        call shape_equil2_c(
     &  tt,n,pptab,fptab,
     &  npf2,pf,
     &  ncam2,tcam,tpl,kpr,
     &  rmag,zmag,
     &  psi_tr)

       apr='--pptab-' 
      print 71,apr,(pptab(i),i=1,n) 

 !     stop

       call dina_input2(tt,tpl, n,a, pptab,fptab 
     & , ncam2,tcam, npf2,pf,rmag,zmag,psi_tr,rs0,bt0)

      print *,'tt tpl=',tt,tpl

 !     stop
      
	    call prof_in_test2_c(tt,n,
     &  te0,tq0,pne,
     &  pd0,pt0,sigma,jbut,aj0,qe0,qq0,kpr)

      	call dina_input(te0,tq0,pne, 
     &  pd0,pt0,sigma,jbut,aj0,qe0,qq0)

      end if
    

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

!      do k=1,999993
 
 2323      continue
 
      k=k+1
      
      if(k.gt.1)then          

        if(i_restart.eq.1)then


	    call prof_in_test2_c(tt,n,
     &  te0,tq0,pne,
     &  pd0,pt0,sigma,jbut,aj0,qe0,qq0,kpr)

      end if
      
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


      	call dina_input(te0,tq0,pne, 
     & pd0,pt0,sigma,jbut,aj0,qe0,qq0)
     
      end if
      
      
	  call dina2(
!-----------------------------------  inputs---
     &  c_input1,c_input2,
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
	call dina_outp(n, tpl, tt, 
     & a, ai,
     & rs0,bt0,
     & x,y,psi,curr_d,
     & psi_tr,psi_eq,phi_1D,
     & fpol,pptab,fptab,
     & tok1,q,
     & vchopper,pf,tcam,
     & te0,tq0,press,zeff,
     & qe0,qq0,
     & pne,pd0,pt0,
     & sigma,jbut,aj0,ajae,
     & bprobe,psloop,
     & psi_ax, psi_bnd, psi_sep, psi_sep2,
     & ksepa,key_lh,
     & surface_1d,volume_1d,area_1d,
     & n_bnd,xbound,ybound,
     & n_sep,x_sep,y_sep,
     & n_sep2,x_sep2,y_sep2,
     & n_ga_dina,gaps,
     & betap,betat,
     & tene,teit_98)
     
      n1=n

        call dina_wr_output(wr_imas)

!        %magnetic_axis%r = wr_imas(13) ![m]
!        %magnetic_axis%z = wr_imas(14) ![m]

        rmag = wr_imas(13) ![m]
        zmag = wr_imas(14) ![m]

        if(kpr.gt.0)print *,' -------- k tt tpl=',k,tt,tpl

	write(6,'("  k time1 tt time2= ",
     *  i4,6(1pe12.5))'),
     *  k,time1,tt,time2

      if(time1.le.tt.and.tt.le.time2)then
      

         kstep=kstep+1

        	if(kstep.eq.nstep*(kstep/nstep).or.kstep.eq.1)then

	write(6,'("  kstep  time1 tt time2= ",
     *  i4,6(1pe12.5))'),
     *  kstep,time1,tt,time2


	    call wr_equil_c(
     &  tt,n,pptab,fptab,
     &  npf,pf,
     &  ncam,tcam,tpl,kpr,
     &  rmag,zmag,
     &  psi_tr)

	    call prof_out_test2_c(tt,n,
     &  te0,tq0,pne,
     &  pd0,pt0,sigma,jbut,aj0,qe0,qq0)
        
        end if
        end if

        if(tt.gt.t_vde)then
       stop
       end if


!      end do

      return
      end

	subroutine dina4(
!-----------------------------------  inputs---
     &  c_input1,c_input2,
!------------------------------------outputs
     &  c_output1,c_output2,c_output3)

      include 'double.inc'

      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*),c_output3(*)
      
      
      return
      end
      