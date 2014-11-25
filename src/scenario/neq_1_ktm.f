c	include 'fgraph.fi'
	subroutine graphic(it1,nrad)
	include 'double.inc'
c	include 'fgraph.fd'

        include 'parf0'
        include 'parf1'
        include 'parf2'
        include 'parf7'
        include 'parf8'
        include 'parf2e'

	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *	/fluxc5/nhalo,xtest(nwnh),ytest(nwnh)
	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nn),y(MM),dx,dy
     *  /eq1g/psi_g(nr,nz)
c------------------------>
     *  /eq1e/psext(nwnh),re(nre),ze(nze),dr,dz
c------------------------>
     *  /eq2/ke,xu(mu_l),yu(mu_l)
c------------------------>
     *  /eq2e/kex,xue(mu),yue(mu)
     *  /eq8/jbound,xbound(ntet),ybound(ntet),alfa0
     *  /eq15/pll,zsep,rsep,zsepup,rsepup,zsepdw,rsepdw
c-------------------------->
	common
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *	/ge1e/rs0,tpl
     *  /ge2/NTAY,TAY,TT
     *  /ge5/kpr
     *  /ge7/eu,rout,zout,elong
     *  /ge12/nps,rps(ntet),zps(ntet)
	common
     *  /dfm4/Q(npo),ANU(npo),P(npo),F(npo),PP(npo),PFF(npo)
     *  /dfm12/betj,dlint,bett,bet2,betpc,tk,tkp,tkf
     *  /dfm15/uli

	common
     *	/fluxc1/xp1(50,mu1),yp1(50,mu1)
     *  /fluxc2/delta0,pom(ntet)
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
	common
     *  /cont6/cip1,cip2,time1,time2
     *	/cont9/brad,kefit
     *  /cont13/zmag,zvel,delrmag,delzmag
     *  /cont13e/zmag0,rmag,rmag0,rvel
     *  /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
     *  /cont21/n_ga,n_int

	common
     *  /abcdx/x_c(kf_c),x0_c(kf_c),gaps0(kf_c),d_gaps(kf_c)

	common
     *  /keys7/i_c
     *  /keys9/i_d3d,i_iter,i_smal

	common
     *  /vic_rz_cur/r_cur,z_cur,z_cur0
     *  /vic_002/elong_p

	common
     *	/con1/gain,ta,zref,kzref
     *  /con2/rref,krref,bvert


      common/vic_uli/del_li,uli_p,ch_k,ulivel

     *  /fluxc4/mcurve_fil,x11(mu1),y11(mu1)


	dimension ind1(50),xp(mu1),yp(mu1)

	dimension pf_vs(kf)

	parameter ( k_sep=1000 )
	common /c_tsp1/r_sep(k_sep),z_sep(k_sep)
	common /c_tsp2/nn_sep

      common /sep_points/n_sep,x_sep(mu1),y_sep(mu1)

      include 'par_fil'

	common
     *  /efil_3/r_fil(k_fil),z_fil(k_fil)
     *  /efil_4/n_fil
  

	character *28 filename
        character*20 yy,xx

	call f_40()
c ----->
c	do i=1,nr
c	do j=1,nz
c	kk=(i-1)*nz+j
c	psi0=pspl(kk)+psext(kk)
cccc!!!	psi0=omega*psi0+(1.-omega)*pspl0(kk)
c	psi(i,j)=psi0
c	psi(i,j)=psi(i,j)+brad*y(j)
c	end do
c	end do

	call erasvm
	call region(330,40,300,600)
c#	call region(40,40,600,600)

c        call region(2.5,0.5,2.5+7.,0.5+21.,1.,1,1)
        x_l=re(1)
        x_r=re(nre)
        y_l=ze(1)
        y_r=ze(nze)
	call limits(x_l,x_r,y_l,y_r)
        dx_g=(x_r-x_l)/nre*2.
        dy_g=(y_r-y_l)/nze*2.
c----
        call axes(5,'Z_coor,cm',9,5,'R_coor,cm',9)
c        if(kpr.eq.1)print *,' ke====',ke
        call disp(yu,xu,ke,0)

	if(i_c.eq.1)then
        call disp(yue,xue,kex,0)
	end if

	yy='time='
	ttt=tt*1.e-3
	call ltext(60,200,yy,ttt)     

	yy='Rm='
	ttt=rmag
	call ltext(60,220,yy,ttt)     

	yy='Rm_r='
	ttt=rref
	call ltext(60,240,yy,ttt)     

	yy='g6='
	ttt=gaps(6)
	call ltext(60,260,yy,ttt)     

	yy='g6_r='
	ttt=gaps0(6)
	call ltext(60,280,yy,ttt)     

	yy='Zm='
	ttt=zmag
	call ltext(60,300,yy,ttt)     
	yy='Zc='
	ttt=z_cur
	call ltext(60,320,yy,ttt)     

	yy='Z_r='
	ttt=zref
	call ltext(60,340,yy,ttt)     

	yy='K='
	ttt=elong
	call ltext(60,360,yy,ttt)     

	yy='K_r='
	ttt=elong_p
	call ltext(60,380,yy,ttt)     

	yy='Ip='
	ttt=tpl*1.e-3
	call ltext(60,400,yy,ttt)     

	yy='Ip_r='
	ttt=cip1*1.e-3
	call ltext(60,420,yy,ttt)     

	yy='li='
	ttt=uli
	call ltext(60,440,yy,ttt)     

	yy='del_li='
	ttt=del_li
	call ltext(60,460,yy,ttt)     

	yy='uli_p='
	ttt=uli_p
	call ltext(60,480,yy,ttt)     

	yy='ch_k='
	ttt=ch_k
	call ltext(60,500,yy,ttt)     

	yy='li_vel='
	ttt=ulivel
	call ltext(60,520,yy,ttt)     

c        call disp(ybound,xbound,jbound,0)


        call exam_3(rc,zc,ncam,0,0.2*dx_g,0.2*dy_g)

c        call exam_3(r_sep,z_sep,n_sep,0,0.2*dx_g,0.2*dy_g)

c        if(kpr.eq.1)print *,' nvam====',ncam
        if(nhalo.gt.0)then
c!!!!!!!!!!!!     	call exam_5(xtest,ytest,nhalo,0,0.2*dx,0.2*dy)
     	end if
        if(i_iter.eq.1)then
c@@@@@@@     	call exam_5(rps,zps,nps,0,0.5*dx_g,0.5*dy_g)
c@@@@@@@     	call exam_5(x_gaps,y_gaps,n_ga,0,0.2*dx_g,0.2*dy_g)
     	call exam_5(x_gaps,y_gaps,n_ga,0,0.5*dx_g,0.5*dy_g)
     	end if
 	
        call exam_4(dx_g,dy_g)
        
c        call exam_3_i(r_pf,z_pf,npf,0,dr_pf,dz_pf)
c
c	if(kpr.eq.1)print *,' ENTER i_mc==='c
c	read (*,*)i_mc
	
	i_mc=4
	
        n_g=6
	d1=1./(n_g-2.)*delaval
	avalb=pmag

c!!!        do ii=1,n_g
        do ii=1,n_g-1
        avalb=avalb-d1
        if(ii.eq.n_g)avalb=p_s
        if(ii.eq.n_g-1)avalb=pbound
c        if(ii.eq.3)avalb=fint
c	if(avalb.le.pbound)avalb=pbound
cc
	do i0=1,i_mc
	ind1(i0)=0
	end do
c
	dcur=1.e-11*(abs(avalb)+1.)
	call fluxcont(nn,mm,psi_g,avalb,x,y,
c	call fluxcont(nn,mm,psi,avalb,x,y,
     *  xp1,yp1,num,ind1,delta0,dcur)
c
	do i0=1,i_mc
	mcurve=ind1(i0)
c----------------------------------------
	if(mcurve.gt.0)then
	do j=1,mcurve
	xp(j)=xp1(i0,j)
	yp(j)=yp1(i0,j)
	end do
c       call exam_2(x_l,y_l,x_r,y_r,mcurve,xp,yp)
        call disp(yp,xp,mcurve,0)
c        if(kpr.eq.1)print *,' mcurve====',mcurve
        end if
        end do
c
	end do

c@@@@@@@@     	call exam_5(xtest,ytest,nhalo,0,0.15*dx_g,0.15*dy_g)

c@@@@@@@@     	call exam_5(x11,y11,mcurve_fil,0,0.15*dx_g,0.15*dy_g)

c@@@@@@@     	call exam_5(xbound,ybound,jbound,0,0.15*dx_g,0.15*dy_g)

c@@@@@@@     	call exam_5(x_sep,y_sep,n_sep,0,0.15*dx_g,0.15*dy_g)
c@@@@@@@     	call exam_5(r_fil,z_fil,n_fil,0,0.5*dx_g,0.5*dy_g)

	if(kpr.eq.1)print *,' mcurve_fil==',mcurve_fil


	call redraw
c	if(kpr.eq.1)print*,'n_fil=',n_fil
c!!!	read(*,*)
c
	return
	end




	subroutine gr_dir_fil(it1_xx,nrad_xx)
	include 'double.inc'
        include 'new_com.inc'

	call gr_dir_fil_c(it1_xx,nrad_xx,
     *  expfg,thalo,del_r,tokc,thalo0,num_shot,
     *  w_h0,rmag,zmag,uli)
        
        return
        end



	subroutine gr_dir_fil_c(it1,nrad,
     *  expfg,thalo,del_r,tokc,thalo0,num_shot,
     *  w_h0,rmag,zmag,uli)

c	include 'fgraph.fd'

	include 'double.inc'
        include 'parf0'
        include 'parf1'
        include 'parf2'
        include 'parf7'
        include 'parf2e'

        include 'parf4'

        common
     *  /graf2/q_95,q_99
        common
     *	/fluxc16/tor_flh,tor_flp,tor_fl

	common
     *  /probe1/kprobe,bprobe(nprobe)
        dimension rprobe(nprobe),zprobe(nprobe)

	common
     *  /loop1/kloop,RL(nloop),ZL(nloop),psloop(nloop)

	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *	/fluxc5/nhalo,xtest(nwnh),ytest(nwnh)
	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nn),y(MM),dx,dy
     *  /eq1g/psi_g(nr,nz)
c------------------------>
     *  /eq1e/psext(nwnh),re(nre),ze(nze),dr,dz
c------------------------>
     *  /eq2/ke,xu(mu_l),yu(mu_l)
c------------------------>
     *  /eq2e/kex,xue(mu),yue(mu)

	common
     *  /eq8/jbound,xbound(ntet),ybound(ntet),alfa0_xx


c-------------------------->
	common
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *	/ge1e/rs0,tpl
     *  /ge2/NTAY,TAY,TT
     *  /ge5/kpr
     *  /ge7/eu,rout,zout,elong
     *  /ge12/nps,rps(ntet),zps(ntet)
	common
     *  /dfm4/Q(npo),ANU(npo),P(npo),F(npo),PP(npo),PFF(npo)
     *  /dfm12/betj,dlint,bett,bet2,betpc,tk,tkp,tkf

	common
     *	/fluxc1/xp1(50,mu1),yp1(50,mu1)
     *  /fluxc2/delta0,pom(ntet)
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
	common
     *	/cont9/brad,kefit
	common
     *  /keys7/i_c
     *  /keys9/i_d3d,i_iter,i_smal
        common
     *  /efil_7/chi_sqr,chi_ps,chi_bp,chi_pf

	dimension ind1(50),xp(mu1),yp(mu1)
	dimension pf_vs(kf)

	character *28 filename

        character*20 yy,xx,ch

c ----->
c	do i=1,nr
c	do j=1,nz
c	kk=(i-1)*nz+j
c	psi0=pspl(kk)+psext(kk)
cccc!!!	psi0=omega*psi0+(1.-omega)*pspl0(kk)
c	psi(i,j)=psi0
c	psi(i,j)=psi(i,j)+brad*y(j)
c	end do
c	end do

	call erasvm
c        call region(2.5,0.5,2.5+7.,0.5+21.,1.,1,1)

c        x_l=210.
c        x_r=470.
c        y_l=-200.
c        y_r=200.

        i_jt=0
        if(i_jt.eq.1)then
        x_l=re(1)
        x_r=re(nre)
        y_l=ze(1)
        y_r=ze(nze)
        end if

	i_en=i_en+1
	if(i_en.eq.1)then
	   open (unit=41,file='reg_data',form='formatted')
	   read (41,*)
	   read (41,*)x_l,x_r
	   read (41,*)
	   read (41,*)y_l,y_r

	   if(kpr.eq.1)print *,' x_l x_r',x_l,x_r
	   if(kpr.eq.1)print *,' y_l y_r',y_l,y_r

	   close (41)
	end if

  	call region(330,200,300,400)


	call limits(x_l,x_r,y_l,y_r)
        dx_g=(x_r-x_l)/nre*2.
        dy_g=(y_r-y_l)/nze*2.
c----
        call axes(4,'Z_coor,cm',9,4,'R_coor,cm',9)
c        if(kpr.eq.1)print *,' ke====',ke
        call disp(yu,xu,ke,0)

c!!!     	call exam_5(xu,yu,ke,0,0.6*dx,0.6*dy)
        call exam_3(xu,yu,ke,0,0.5*dx_g,0.5*dy_g)

	if(i_c.eq.1)then
        call disp(yue,xue,kex,0)
	end if


     	call exam_5(xbound,ybound,jbound,0,0.2*dx,0.2*dy)

        call exam_3(rc,zc,ncam,0,0.2*dx_g,0.2*dy_g)
c        if(kpr.eq.1)print *,' nvam====',ncam

        if(nhalo.gt.0)then
     	call exam_5(xtest,ytest,nhalo,0,0.2*dx,0.2*dy)
     	end if

c           key_gr=0

c	call probe_koor(key_gr,kprobe,k_gr,rprobe,zprobe)

c        if(kprobe.gt.0)then
c     	call exam_5(rprobe,zprobe,k_gr,0,dx,dy)
c     	end if

c	call loop_koor(kloop,rl,zl)

c        if(kloop.gt.0)then
c     	call exam_5(rl,zl,kloop,0,1.5*dx,1.5*dy)
c     	end if

        if(i_iter.eq.1)then
     	call exam_5(rps,zps,nps,0,0.2*dx_g,0.2*dy_g)
     	end if
 	
	rps(1)=rmag
	zps(1)=zmag

        nps=1
        call exam_5(rps,zps,nps,0,dx_g,dy_g)

c        call exam_4(dx_g,dy_g)
        
c        call exam_3_i(r_pf,z_pf,npf,0,dr_pf,dz_pf)
c
c	if(kpr.eq.1)print *,' ENTER i_mc==='c
c	read (*,*)i_mc
	
	i_mc=4
	
        n_g=20
c        n_g=10

	d1=1./(n_g-2.)*delaval
	avalb=pmag

c--- FOR JT ONLY...

        delaval=pmag-p_s

	d1=1./(n_g-3.)*delaval

	avalb=pmag



        do ii=1,n_g
        avalb=avalb-d1
        if(ii.eq.n_g)avalb=p_s
        if(ii.eq.n_g-1)avalb=pbound
c        if(ii.eq.3)avalb=fint
c	if(avalb.le.pbound)avalb=pbound
cc
	do i0=1,i_mc
	ind1(i0)=0
	end do
c
	dcur=1.e-11*(abs(avalb)+1.)

	delta0=1.2*sqrt(dx**2+dy**2)

	call fluxcont(nn,mm,psi_g,avalb,x,y,
c	call fluxcont(nn,mm,psi,avalb,x,y,
     *  xp1,yp1,num,ind1,delta0,dcur)
c
	do i0=1,i_mc
	mcurve=ind1(i0)
c----------------------------------------
	if(mcurve.gt.0)then
	do j=1,mcurve
	xp(j)=xp1(i0,j)
	yp(j)=yp1(i0,j)
	end do
c       call exam_2(x_l,y_l,x_r,y_r,mcurve,xp,yp)

        if(avalb.gt.pbound)call disp(yp,xp,mcurve,1)
        if(avalb.le.pbound)call disp(yp,xp,mcurve,1)

        if(kpr.eq.1)print *,' mcurve====',mcurve

        end if
        end do
c
	end do

        iy_h=400

        kyy=9

        yy='shot #'
        ttt=num_shot

	call ltext(30,iy_h,yy,ttt)     
c	call ltext_jt(30,iy_h,yy,kyy,ttt)

        yy='time='
        ttt=tt
	call ltext_jt(30,iy_h+20,yy,kyy,ttt)

        yy='I_pl '
        ttt=tpl
	call ltext_jt(30,iy_h+40,yy,kyy,ttt)

        yy='I_h_pol '
        ttt=expfg
	call ltext_jt(30,iy_h+60,yy,kyy,ttt)

        yy='I_h_tor '
        
c        if(kpr.eq.1)print *,'thalo==',thalo

        ttt=thalo
	call ltext_jt(30,iy_h+80,yy,kyy,ttt)
     
        yy='l_i     '
        ttt=uli
	call ltext_jt(30,iy_h+100,yy,kyy,ttt)

        yy='q_bound '
        ttt=q_99
	call ltext_jt(30,iy_h+120,yy,kyy,ttt)

c        yy='Halo_W '
c        ttt=abs(w_h0)

        yy='bet_p '
        ttt=betj
	call ltext_jt(30,iy_h+140,yy,kyy,ttt)

        yy='I_vessel'
        ttt=tokc
	call ltext_jt(30,iy_h+160,yy,kyy,ttt)


c        yy='I_h_P_exp'
        yy='Elong'
c        ttt=thalo0
        ttt=elong
	call ltext_jt(30,iy_h+180,yy,kyy,ttt)

        yy='TOR_FL'
        ttt=tor_fl
	call ltext_jt(30,iy_h+200,yy,kyy,ttt)

        yy='CHI_sqr'
        ttt=chi_sqr
	call ltext_jt(30,iy_h+220,yy,kyy,ttt)

        yy='CHI_ps'
        ttt=chi_ps
	call ltext_jt(30,iy_h+240,yy,kyy,ttt)


        yy='CHI_bp'
        ttt=chi_bp
	call ltext_jt(30,iy_h+260,yy,kyy,ttt)


        yy='CHI_pf'
        ttt=chi_pf
	call ltext_jt(30,iy_h+280,yy,kyy,ttt)


        yy='EN_POL'
        ttt=epol
	call ltext_jt(30,iy_h+300,yy,kyy,ttt)






	call redraw

	return


	if(it1.eq.0)then
	   
	call surf_bound()

	call  write_surf()
	
c	open (unit=41,file='psi_data',position='append',
	open (unit=41,file='psi_data',access='append',
     *  form='formatted')

c	open ( unit=41,file='jt_eq.dat',form='formatted')
        write (41,*)num_shot
        write (41,*)tt
        write (41,*)tpl
        write (41,*)expfg
        write (41,*)thalo
        write (41,*)uli
        write (41,*)q_99
        write (41,*)del_r
        write (41,*)tokc
        write (41,*)thalo0
        write (41,*)tor_fl
        write (41,*)chi_sqr
        write (41,*)chi_ps
        write (41,*)chi_bp
        write (41,*)chi_pf
        write (41,*)epol

	close (41)

c	read (*,*)

	end if
c
	return
	end

