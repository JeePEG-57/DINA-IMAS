	subroutine gr_curr(n,x,y,kpr,x11,y11,tt ) 

	include 'double.inc'
	dimension x(kpr,n),y(kpr,n)
	dimension x11(n),y11(n),tt(kpr)
	common /min_max/xmin,xmax,ymin,ymax

        character*20 yy,xx

c	if(kpr.eq.1)print *,' KPR from CUR n==',kpr,n

	do kk=1,kpr

	ttt=tt(kk)	

	do i=1,n
	x11(i)=x(kk,i)
	y11(i)=y(kk,i)
	end do

	call minmax(y11,x11,n)

	if(kpr.eq.1)print *,' xmin xmax ymin ymax==',xmin,xmax,ymin,ymax

	if(kk.eq.1)then
	x_l=xmin
	x_r=xmax
	y_l=ymin
	y_r=ymax
	end if

	x_l=amin1(x_l,xmin)	
	x_r=amax1(x_r,xmax)	
	y_l=amin1(y_l,ymin)	
	y_r=amax1(y_r,ymax)	


	if(kk.eq.1)then
	yy='t_1='
	call ltext(60,300,yy,ttt)     
	end if


	if(kk.eq.2)then
	yy='t_2='
	call ltext(60,330,yy,ttt)     
	end if

	if(kk.eq.3)then
	yy='t_3='
	call ltext(60,360,yy,ttt)     
	end if

	if(kk.eq.4)then
	yy='t_4='
	call ltext(60,390,yy,ttt)     
	end if
	end do

	if(kpr.eq.1)print *,' x_l x_r y_l y_r==',x_l,x_r,y_l,y_r

	call limits(x_l,x_r,y_l,y_r)

c

	yy='J_t [KA]/cm**2'
	xx=' R [cm] '
	call region (80,40,200,200)
	call axes(4,yy,14,4,xx,8)

	do kk=1,kpr

	do i=1,n
	x11(i)=x(kk,i)
	y11(i)=y(kk,i)
	end do

	lin=kk-1

        call disp(y11,x11,n,lin)

	end do
	
	return
	end
c


	subroutine gr_bound(
     *  num_gr,
     *	nr,nz,ke,ncam,npf,jbound,
     *	r1,r2,z1,z2,dx,dy,
     *  xu,yu,rc,zc,
     *  r_pf,z_pf,dr_pf,dz_pf,
     *  xbound,ybound ) 

	include 'double.inc'
        common
     *  /ge5/kpr

	dimension
     *  xu(ke),yu(ke),
     *  rc(ncam),zc(ncam),
     *  r_pf(npf),z_pf(npf),dr_pf(npf),dz_pf(npf),
     *  xbound(jbound),ybound(jbound)

	if(num_gr.eq.1)then

	scale=(r2-r1)/(z2-z1)
	if(kpr.eq.1)print *,' ntest= scale=',ntest,scale

	i_y=300
	i_x=i_y*scale

	call region(80,420,i_x,i_y)
c
        x_l=r1
        x_r=r2
        y_l=z1
        y_r=z2

	call limits(x_l,x_r,y_l,y_r)
c
        dx_g=(x_r-x_l)/nr*2.
        dy_g=(y_r-y_l)/nz*2.
c----
        call axes(4,'Z_coor,cm',9,4,'R_coor,cm',9)
        call disp(yu,xu,ke,0)


c        call disp(yue,xue,kex,0)
         call exam_3(rc,zc,ncam,0,0.2*dx_g,0.2*dy_g)
c        call exam_3_i(r_pf,z_pf,npf,0,dr_pf,dz_pf)

c        call exam_4(dx_g,dy_g)
c        call exam_5(rps,zps,nps,0,dx,dy)
	end if

        call disp(ybound,xbound,jbound,0)

	call redraw
c  *** END GRAPHICS..
	return
	end
c
	subroutine gr_psi(
     *	nr,nz,ke,ncam,nwnh,npf,
     *	r1,r2,z1,z2,dx,dy,
     *  psi,x,y,xu,yu,rc,zc,indpl,
     *  r_pf,z_pf,dr_pf,dz_pf,
     *  pmag,pbound,p_s,um,vm )
 
	include 'double.inc'
        common
     *  /ge5/kpr

	common /point/r0,z0
c
	PARAMETER ( mu1=400, nxt=4000 )
	dimension xp1(50,mu1),yp1(50,mu1),ind1(50),
     *  xp(mu1),yp(mu1),xtest(nxt),ytest(nxt)

	dimension
     *  psi(nr,nz),x(nr),y(nz),xu(ke),yu(ke),
     *  rc(ncam),zc(ncam),indpl(nwnh),
     *  r_pf(npf),z_pf(npf),dr_pf(npf),dz_pf(npf)

c	if(kpr.eq.1)print *,' nr nz ke ncam nwnh',nr,nz,ke,ncam,nwnh

c	if(kpr.eq.1)print *,' r1 r2 z1 z2 dx dy',r1,r2,z1,z2,dx,dy

c	if(kpr.eq.1)print *,' pmag pbound p_s',pmag,pbound,p_s

c	if(kpr.eq.1)print *,' um vm',um,vm

	r0=um
	z0=vm

	nn=nr
	mm=nz

	n1=nr-1
	m1=nz-1

	delta0=1.0*sqrt(dx**2+dy**2)

	delaval=pmag-pbound

	npoint=0
	do in=1,nr
	do jn=1,nz
	kk2=(in-1)*nz+jn
	indpl(kk2)=0
        call caet2(um,vm,x(in),y(jn),ipoint,ke,xu,yu)
	if(ipoint.eq.1)then
	INDPL(kk2)=1
	npoint=npoint+1
	end if
	end do
	end do

	ntest=0
c
	DO I=2,N1
	DO J=2,M1
	kk=(i-1)*nz+j
	if(indpl(kk).eq.0) go to 1004
C
	PSIX=PSI(i,j)
	IF( (PSIX-pbound)*(PSIX-p_s).LE.0.)THEN
	ntest=ntest+1
	xtest(ntest)=x(i)
	ytest(ntest)=y(j)
	END IF
1004	CONTINUE
	END DO
	END DO

	scale=(r2-r1)/(z2-z1)
	if(kpr.eq.1)print *,' ntest= scale=',ntest,scale

	i_y=580
	i_x=i_y*scale

	call region(350,40,i_x,i_y)
c
        x_l=r1
        x_r=r2
        y_l=z1
        y_r=z2

	call limits(x_l,x_r,y_l,y_r)
c
        dx_g=(x_r-x_l)/nr*2.
        dy_g=(y_r-y_l)/nz*2.
c----
        call axes(4,'Z_coor,cm',9,4,'R_coor,cm',9)
        call disp(yu,xu,ke,0)
c        call disp(yue,xue,kex,0)
        call exam_3(rc,zc,ncam,0,0.2*dx_g,0.2*dy_g)
        call exam_3_i(r_pf,z_pf,npf,0,dr_pf,dz_pf)

c        call exam_4(dx_g,dy_g)
c        call exam_5(rps,zps,nps,0,dx,dy)

	if(ntest.gt.0)then
        call exam_5(xtest,ytest,ntest,0,0.3*dx,0.3*dy)
	end if
c
        n_g=7
	d1=1./(n_g-2.)*delaval
c!!!	avalb=pmag
	avalb=pbound+10*d1
            do ii=1,n_g
            avalb=avalb-d1
c        do ii=1,2
        if(ii.eq.n_g)avalb=pbound
        if(ii.eq.n_g-1)avalb=p_s
cc
	do i0=1,4
	ind1(i0)=0
	end do
c
	dcur=1.e-11*(abs(avalb)+1.)

	call fluxcont(nn,mm,PSI,avalb,x,y,
     *  xp1,yp1,num,ind1,delta0,dcur)
c
	do i0=1,4
	mcurve=ind1(i0)
c----------------------------------------
	if(mcurve.gt.0)then
	do j=1,mcurve
	xp(j)=xp1(i0,j)
	yp(j)=yp1(i0,j)
	end do

        if(ii.ge.n_g-1) call disp(yp,xp,mcurve,0)
	if(ii.lt.n_g-1) call disp(yp,xp,mcurve,1)
	if(kpr.eq.1)print *,' mcurve===',mcurve
	end if
	end do
c
	end do
	call redraw
c  *** END GRAPHICS..
	return
	end
c
	subroutine write_graf(
     *	nr,nz,ke,ncam,nwnh,npf,jbound,iprof,
     *	dx,dy,ttt,
     *  psi,x,y,xu,yu,rc,zc,
     *  pmag,pbound,p_s,um,vm,
     *  xbound,ybound,xcur,torcur ) 
c$
	include 'double.inc'
	include 'parf0'
c#
        common
     *  /ge5/kpr
c$
	common
     *  /mid6/bp_0(npo),a_m(npo),r_m(npo)
    	common
     *	/n_m/n,m,mp
c#
	dimension
     *  psi(nr,nz),x(nr),y(nz),xu(ke),yu(ke),
     *  rc(ncam),zc(ncam),
     *  xbound(jbound),ybound(jbound),
     *  xcur(iprof),torcur(iprof)

	dimension
     *  agraf(2*npo)


	ntay=ntay+1

c$
	ml=mp/2+1
	i=0
	do k0=1,2
	if(k0.eq.1)j=ml
	if(k0.eq.2)j=2
	do i0=2,n
	if(k0.eq.1)k=n-i0+2
	if(k0.eq.2)k=i0
	i=i+1
	agraf(i)=a_m(k)
	end do
	end do	
c#

c----------- write  graphics data ---
c*** i_form=1 to do formatted writing
	i_form=1

5000	format(4(1x,1pe14.7))
	
	if(i_form.eq.0)then

c	open (unit=61,file='psi_data',access='append',
c     *  form='unformatted')
           if(ntay.le.1)then
              open (unit=61,file='psi_data',status='new',
     *             form='unformatted')
           end if

           if(ntay.gt.1)then
              open (unit=61,file='psi_data',status='old',
     *             form='unformatted')
           end if
c$

           write (61)ke,ncam,npf,jbound,iprof
c#
           write (61)(rc(i),i=1,ncam)
           write (61)(zc(i),i=1,ncam)
           write (61)(xu(i),i=1,ke)
           write (61)(yu(i),i=1,ke)
c
           write (61)dx,dy,pmag,pbound,p_s,um,vm,ttt
           
           write (61)((psi(i,j),i=1,nr),j=1,nz)
           write (61)(x(i),i=1,nr)
           write (61)(y(i),i=1,nz)
           write (61)(xbound(i),i=1,jbound)
           write (61)(ybound(i),i=1,jbound)
           write (61)(xcur(i),i=1,iprof)
           write (61)(torcur(i),i=1,iprof)
c$
c!!!	write (61)(agraf(i),i=1,iprof)
c#	
c	if(kpr.eq.1)print*,(agraf(i),i=1,iprof)
c	read(*,*)


           close (61)

	else

	open (unit=61,file='psi_data',access='append',
     *  form='formatted')
c           if(ntay.le.1)then
c              open (unit=61,file='psi_data',status='new',
c     *             form='formatted')
c           end if

c           if(ntay.gt.1)then
c              open (unit=61,file='psi_data',status='old',
c     *             form='formatted')
c           end if
c$

           write (61,*)ke,ncam,npf,jbound,iprof
c#    
           write (61,5000)(rc(i),i=1,ncam)
           write (61,5000)(zc(i),i=1,ncam)
           write (61,5000)(xu(i),i=1,ke)
           write (61,5000)(yu(i),i=1,ke)
c     
           write (61,5000)dx,dy,pmag,pbound,p_s,um,vm,ttt
           
           write (61,5000)((psi(i,j),i=1,nr),j=1,nz)
           write (61,5000)(x(i),i=1,nr)
           write (61,5000)(y(i),i=1,nz)
           write (61,5000)(xbound(i),i=1,jbound)
           write (61,5000)(ybound(i),i=1,jbound)
           write (61,5000)(xcur(i),i=1,iprof)
           write (61,5000)(torcur(i),i=1,iprof)
c$
c!!!!	write (61,5000)(agraf(i),i=1,iprof)
c#	
c	if(kpr.eq.1)print*,(agraf(i),i=1,iprof)
c	read(*,*)


           close (61)

	end if
        
        
	return
	end




	subroutine surf(x_map,y_map,n_in,n,m,npo1)

        include 'parf0'
        include 'parf1'
        include 'parf2'
        include 'parf7'
        include 'parf2e'

      include 'double.inc'
	dimension x_map(npo,m),y_map(npo,m)

	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nn),y(MM),dx,dy
c------------------------>
     *  /eq1e/psext(nwnh),re(nre),ze(nze),dr,dz
c------------------------>
     *  /eq2/ke,xu(mu_l),yu(mu_l)
c------------------------>
     *  /eq2e/kex,xue(mu),yue(mu)
c-------------------------->
	common
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *  /keys7/i_c

	dimension x11(mu),y11(mu)

	character *28 filename

	call initvm(10,10,800,780)

c	call region(80,200,300,300)
	call region(20,20,750,740)

        x_l=x(1)
        x_r=x(nr)
        y_l=y(1)
        y_r=y(nz)
	call limits(x_l,x_r,y_l,y_r)
        dx_g=(x_r-x_l)/nr*2.
        dy_g=(y_r-y_l)/nz*2.

        dx_g=dx
        dy_g=dy
c----
        call axes(5,'Z_coor,cm',9,5,'R_coor,cm',9)

        do i=1,ke
        if(kpr.eq.1)print *,' xu yu i==',xu(i),yu(i),i
        end do

        call disp(yu,xu,ke,0)

	if(i_c.eq.1)then
        call disp(yue,xue,kex,0)
	end if

	if(kpr.eq.1)print *,' n m  ',n,m
	
	do ii=n_in,n
	   do j=1,m
	      x11(j)=x_map(ii,j)
	      y11(j)=y_map(ii,j)
	   end do

        call disp(y11,x11,m,0)

	end do

c
	call redraw

	read (*,*)
	
	call endvm

	return
	end











