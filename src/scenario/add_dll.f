  	subroutine shape_ip() 
	include 'double.inc'
 	include 'parf1' 
 	parameter ( NPFC=KF-4) 

 	include 'parf_mike' 

c 	parameter (ntime=20)
 
	common
     *  /ge2/ntay,tay,tt
     *	/ge1e/rs0,tpl
        common
     *  /ge5/kpr

	common
     *  /keys5/next

	dimension t_t(ntime),tpl_t(ntime)

	character *12 apr

	if(next.ne.9999)return

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='ip.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 

 	 if(kpr.eq.1)print *,' tt n_t===',tt,n_t 
           
c!!!           read (41,*) 
           do i=1,n_t 
              read (41,*)t_t(i),tpl_t(i)
              t_t(i)=t_t(i)*1000. 
           end do 
           
           apr='-t_t-' 
c           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 
           close (unit=41) 
        end if
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 tpl=tpl_t(i-1)+t_coef*(tpl_t(i)-tpl_t(i-1))

	 tpl=tpl*1.e-3
c
	 end if

	 end do
	if(kpr.eq.1)print *,' from SHAPE IP tpl',tpl

       return 
       end 

c****************************************************
     	subroutine vic_shape_elong()
	include 'double.inc'
	include 'new_com2.inc'

	call vic_shape_elong_c(
     * elong_p,tt)

	return
	end

	subroutine vic_shape_elong_c(
     * elong_p,tt)
	include 'double.inc'

 	include 'parf_mike' 
	dimension t_t(ntime),elong_t(ntime)

	character *12 apr

	i_sh=i_sh+1
	if(i_sh.eq.1)then
c-------
           open (unit=41,file='elong.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 
           read (41,*) 

 	 if(kpr.eq.1)print *,' tt n_t===',tt,n_t 

           do i=1,n_t 
              read (41,*)t_t(i),elong_t(i)
              t_t(i)=t_t(i)*1000. 
           end do 
           
           apr='-t_t-' 
c           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 
           close (unit=41) 
        end if
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 elong_p=elong_t(i-1)+t_coef*(elong_t(i)-elong_t(i-1))

c
	 end if

	 end do

 	if(kpr.eq.1)print *,' from SHAPE ELONG tt elong_p',tt,elong_p

       return 
       end 

c************************************************
c**************************************************
  	subroutine vic_shape_ip_iam() 
	include 'double.inc'
        include 'new_com2.inc'

        call vic_shape_ip_iam_c(
     *       pf_p)

        return
        end

  	subroutine vic_shape_ip_iam_c(
     *       pf_p)

	include 'double.inc'
 	include 'parf1' 

 	include 'parf_mike' 

c 	parameter (ntime=20)
 
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /cont6/cip1,cip2,time1,time2

	common
     *  /keys5/next

	common
     *	/ge1e/rs0,tpl
     *  /ge2/ntay,tay,tt
        common
     *  /ge5/kpr


	dimension t_t(ntime),pf_t(kf,ntime),tpl_t(ntime)
        dimension pf_p(*)

	character *20 apr

71	FORMAT(20X,A20/,(6(1X,1PE10.3)))

	dimension a(140)

	i_en=i_en+1
	if(i_en.eq.1)then
	   open (unit=40,file='scr_data',form='formatted')
	   read (40,*,err=1,end=1)

	   n_t=0
	   do j=1,10000
	      read (40,*,err=1,end=1)(a(i),i=1,13)

	      n_t=n_t+1

	      t_t(n_t)=a(1)*1.e3
	      tpl_t(n_t)=a(2)*1.e3

	      do k=1,npf
		 pf_t(k,n_t)=a(2+k)*1.e3
	      end do

	      if(kpr.eq.1)
     *  print *,' ++npf n_t===  ntime== t_t',npf,n_t,ntime,
     *  t_t(n_t),tpl_t(n_t)

c	      if(kpr.eq.1)print*,'from vic_shape_ip_iam'
c	      if(kpr.eq.1)print*,(a(i),i=1,2)
c	      if(kpr.eq.1)print*,(a(i),i=3,13)
c	      read(*,*)
	   end do

 1	   continue

	   if(kpr.eq.1)print *,' ++n_t===  ntime==',n_t,ntime
	   if(n_t.gt.ntime)stop

	   close (40)

	   open (unit=40,file='pf_ref.dat',form='formatted')
	   write (40,*)' n_t'
	   write (40,*)n_t
	   write (40,*)' tt  tpl   pf1 - pf12'
	do i=1,n_t
	write (40,5000)t_t(i),tpl_t(i),(pf_t(k,i),k=1,11)
	end do

	write (40,*)'   '




5000    format (8(1pe14.6))
	


	end if
	
	do i=2,n_t
	   if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	      t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )
	 
	      do k=1,npf
		 pf_p(k)=pf_t(k,i-1)+t_coef*(pf_t(k,i)-pf_t(k,i-1))
	      end do

		 tpl_p=tpl_t(i-1)+t_coef*(tpl_t(i)-tpl_t(i-1))

c
	   end if

	end do

	if(i_en.eq.1)then
	   tpl=tpl_p
	end if

	cip1=tpl_p
	
	if(ntay.le.next)tpl=cip1

	if(kpr.eq.1)
     *       print *,' from SHAPE PF tt tpl tpl_p===',tt,tpl,tpl_p

	apr='pf from shape_ip_iam' 
	if(kpr.eq.1)print 71,apr,(pf_p(i),i=1,npf) 

c        pause 'from shape_ip_iam'

	return
	end
c*******************************************
c*********************************************
	subroutine r_tok_p()

	include 'double.inc'
	include 'new_com2.inc'

	call  r_tok_p_c(
     *  tt,npf,pf_p)
	
	return
	end

	subroutine r_tok_p_c(
     *  tt,npf,pf_p)
	
	include 'double.inc'
        common
     *  /ge5/kpr

	include 'parf1'
	dimension pf_p(*),cur1(kf),cur2(kf)

	character *12 apr

	open (unit=41,file='pfc.dat',form='formatted')

	t2=-1.

	 read (41,*,err=1,end=1)

      do ii=1,10000

	 t1=t2
	 do k=1,npf
	    cur1(k)=cur2(k)
	 end do

	 read (41,*,err=1,end=1) t2,(cur2(i),i=1,npf)
	 t2=t2+1.e-3

	 if( (tt-t1)*(tt-t2).le.0.)then
c==================

	    t_coef=(tt-t1)/(t2-t1)
	 
	    do k=1,npf
	       pf_p(k)=cur1(k)+t_coef*(cur2(k)-cur1(k))
	    end do

	    go to 1
c
	 end if

	end do

 1      continue
	    if(kpr.eq.1)print *,' t1 tt t2 ===',t1,tt,t2

	apr='pf_p'
	if(kpr.eq.1)print 71,apr,(pf_p(i),i=1,npf)
	apr='cur2'
	if(kpr.eq.1)print 71,apr,(cur2(i),i=1,npf)
	apr='cur1'
	if(kpr.eq.1)print 71,apr,(cur1(i),i=1,npf)
	close (unit=41)

c        pause 'from r_tok_p'


71 	format (20x,a6/,(6(1pe10.3)))

	return
	end
c******************************************
        subroutine vic_gaps0_read()
	include 'double.inc'
	include 'new_com2.inc'

	call vic_gaps0_read_c(
     *       tt,gaps0,n_ga)

	return
	end

        subroutine vic_gaps0_read_c(
     *       tt,gaps0,n_ga)

	include 'double.inc'
 	include 'parf_mike' 

        common
     *  /ge5/kpr

        dimension gaps0(*)
	dimension t_t(6,ntime),gaps0_t(6,ntime)
        dimension t_t1(ntime),n_t(6)

     	character *20 apr
     	character *20 apr1(6)

     	data apr1 /'g1.dat','g2.dat','g3.dat','g4.dat',
     *  'g5.dat','g6.dat'/

	i_sh=i_sh+1




	if(i_sh.eq.1)then
c-------
           do k=1,n_ga
              open (unit=41,file=apr1(k),form='formatted') 

              if(kpr.eq.1)print*,k,apr1(k)

              read (41,*) 
              read (41,*)n_t(k) 
              read (41,*) 
              
              if(kpr.eq.1)print *,'tt n_t===',tt,n_t(k) 
              
              do i=1,n_t(k) 
                 read (41,*)t_t1(i),gaps0_t(k,i)
                 t_t(k,i)=t_t1(i)*1000. 
              end do 
           end do 
           
                      
           do k=1,n_ga
              apr='-t_t-' 
              if(kpr.eq.1)print 71,apr,(t_t(k,i),i=1,n_t(k)) 
              apr='-gaps0_t-' 
              if(kpr.eq.1)print 71,apr,(gaps0_t(k,i),i=1,n_t(k)) 
           end do
           
           close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))


        do k=1,n_ga
           do i=2,n_t(k)

              if((tt-t_t(k,i-1))*(tt-t_t(k,i)).le.0.)then
c==================
                 t_coef=(tt-t_t(k,i-1))/( t_t(k,i)-t_t(k,i-1) )
              
                 gaps0(k)=gaps0_t(k,i-1)+t_coef*
     *                (gaps0_t(k,i)-gaps0_t(k,i-1))
c     
              end if
           end do
        end do

        if(kpr.eq.1)print*,'tt=',tt
        apr='gaps0' 
        if(kpr.eq.1)print 71,apr,(gaps0(k),k=1,n_ga) 
c        pause 'from vic_gaps_read'

        return
        end

	subroutine r_volt()

	include 'double.inc'
	include 'new_com2.inc'

	call  r_volt_c(
     *  tt,npf,vchopper)
	
	return
	end

	subroutine r_volt_c(
     *  tt,npf,vchopper)
	
	include 'double.inc'
	include 'parf1'
	dimension vchopper(*),v1(kf),v2(kf)
        common
     *  /ge5/kpr

	character *12 apr


	open (unit=41,file='volt.dat',form='formatted')


	t2=-1.

	 read (41,*,err=1,end=1)

      do ii=1,10000

	 t1=t2
	 do k=1,npf
	    v1(k)=v2(k)
	 end do

	 read (41,*,err=1,end=1) t2,(v2(i),i=1,npf)
	 t2=t2+1.e-3

	 if( (tt-t1)*(tt-t2).le.0.)then
c==================

	    t_coef=(tt-t1)/(t2-t1)
	 
	    do k=1,npf
	       vchopper(k)=v1(k)+t_coef*(v2(k)-v1(k))
	    end do

	    go to 1
c
	 end if

	end do


 1	continue

	    if(kpr.eq.1)print *,' t1 tt t2 ===',t1,tt,t2

	apr='vchopper'
	if(kpr.eq.1)print 71,apr,(vchopper(i),i=1,npf)
	apr='v2'
	if(kpr.eq.1)print 71,apr,(v2(i),i=1,npf)
	apr='v1'
	if(kpr.eq.1)print 71,apr,(v1(i),i=1,npf)
	close (unit=41)

c        pause 'from r_volt'


71 	format (20x,a6/,(6(1pe10.3)))

	return
	end

	subroutine error_corr(error_xx,num_gaps_xx)
	include 'double.inc' 
	include 'new_com2.inc'
	
	call error_corr_c(error_xx,num_gaps_xx,
     * tt,t_end,zvel,tpl)

	return
	end

c--------------------------

	subroutine error_corr_c(error,num_gaps,
     * tt,t_end,zvel,tpl)

	include 'double.inc' 

	dimension error(*)

	if( tt.gt.t_end)then

	do i=1,num_gaps+1

	error(i)=0.d0

	end do

	zvel=0.
	tpl=1.e-8

	end if

c-------------------------------

	return
	end

      function rand(a)
      real *8 rand,a
      rand=0.5
      end
      
	subroutine time_step_dll()
        include 'double.inc'
	include 'new_com2.inc'

	call time_step_dll_c(
     *  r_tok,z_tok,r_tok0,z_tok0)


	return
	end

	subroutine time_step_dll_c(
     *  r_tok,z_tok,r_tok0,z_tok0)


        include 'double.inc'
	include 'parf0'
	include 'parf1'
	include 'parf8'
	common
     *	/n_m/n,m,mp
	common
     *  /DFM2/PSI(npo),PFI(npo),DM0(npo),DMN(npo)
     *  /dfm3/dfmax(npo),dfmax0(npo)
     *  /dfm7/bt0,uind
     *  /dfm7e/bt0_0,f_na
     *  /dfm14/tokae,ajae(npo),ajae0(npo),enae
	common
     *  /en1/PNE(npo),PD0(npo),PT0(npo),PH0(npo),PDN(npo),
     *  PTN(npo),PHN(npo)
     *  /en2/TE0(npo),TQ0(npo),TEN(npo),TQN(npo),WE0(npo),
     *  WQ0(npo)
     *  /en4/WD0(npo),WT0(npo),WH0(npo),VD(npo),DIF(npo),
     *  GGT(npo),GGTN(npo)
     *  /en5/SD0(npo),ST0(npo),SH0(npo)
     *  /en10/GGE(npo),GGEN(npo),DXE(npo),DXQ(npo),WU(npo),
     *  UG(npo),VG(npo)
	common
     *  /en12/pnal(npo),pnaln(npo),zalfa,talfa
     *  /en18/pin(npo),pin0(npo),q11(npo),pal(npo)
     *	/en28/wen1,wen2
     *  /eq15/pll,zsep,rsep,zmax,rmax,zmin,rmin
     *  /eq15e/pll0,tpl0,udd
	common
     *  /fluxc9/fdd,fdd0
     *  /fluxc9e/pf_volt(kf),pf_fdd(kf),pf_fdd0(kf)
     *  /fluxc10e/ves_fdd,ves_fdd0
	common
     *  /eq11/psval(npo),psval0(npo)

        common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf6/pves(kf),pves0(kf)
     *  /pf7/plasma(kf),plasma0(kf)

	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves6/pind(mu),pind0(mu),pindn(mu)
     *  /ves9/tokc,tokc0
	common
     *  /cont4/ZPP,RPP,WVSPIP,ZXP,ELP,SHAPE,GAPINP,
     *  DFZP, DFZP0
     *  /cont7/zp,gapin
     *  /cont8/zp00
     *  /cont13/zmag,zvel,delrmag,delzmag
     *  /cont13e/zmag0,rmag,rmag0,rvel
c
	common
     *	/ge1e/rs0,tpl
     *  /ge2/NTAY,TAY,TT
     *  /ge5/kpr

	common
     *  /halo10/fves,fves0,self_v
     *  /halo11/fmaxv,fmaxv0

        common
     *  /con2/rref,krref,bvert


	common
     *  /abcdx_a/x_a(kf_c),x0_a(kf_c)
	common
     *  /abcdx_b/x_b(kf_c),x0_b(kf_c)

	common
     *  /abcdx/x_c(kf_c),x0_c(kf_c),gaps0(kf_c),d_gaps(kf_c)
        common
     *  /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
     *  /cont21/n_ga,n_int
     *  /cont23/v_gaps(kf_c),d_gaps0(kf_c)

        common
     *  /keys13/i_con,i_act

        common
     *  /loop3/vloop,psf1a,psf1a0

	common
     *  /mid2/vi(npo),spo(npo)
     *  /mid2_0/vi0(npo),pfi0(npo)
c***vic for SCEN_CONTROL
     *	/vic_mario_filt/state(kf_c),state_old(kf_c)
     *	/vic_mario_filt1/state_vert(kf_c),state_old_vert(kf_c)
     *  /vic_rz_cur/r_cur,z_cur,z_cur0
     *  /vic_rref/rref_0

	character *52 apr

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))


c  control parameters---
!	zp00=zp
!	DFZP0=DFZP
!	psf1a0=psf1a

!	z_cur0=z_cur
c

	DO I=1,kf_c
!	x0_c(i)=x_c(i)
!	x0_a(i)=x_a(i)
!	x0_b(i)=x_b(i)
	END DO
c-----------
        do i=1,kf_c
           state_old(i)=state(i)
           state_old_vert(i)=state_vert(i)
        end do
c-----------

	DO I=1,n_gaps

!	d_gaps0(i)=d_gaps(i)

	END DO

!        if(kpr.eq.1)print *,' i_con  n_gaps',i_con,n_gaps

c        end if

c----------------

	return
	end
