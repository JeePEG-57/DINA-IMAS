	subroutine prof(y,tgraf,ngraf,yy)	
	include 'double.inc'
	common /n_pr/n_pr
	common /i_time/i_t     
	common /coord/ixx,iyy,iw,ih 
	dimension y(ngraf),tgraf(ngraf)
      character*20 yy,xx,ch
	dimension ttt(10)
	xx=' XRo coor '
      nigr=ngraf
c     
c      call  initvm(10,10,400,340)
c
      namegr=n_pr
	if(kpr.eq.1)print *,' n_pr==========================',n_pr
c
	do i=1,1     
         namegr=namegr+1
c
	call minmax(y,tgraf,nigr)
c
	if(namegr.eq.1)then
	call region (60,40,200,120)
	call axes(5,yy,17,3,xx,10)
	end if
c
	if(namegr.eq.2)then
	call region (60,220,200,120)
	call axes(5,yy,17,3,xx,10)
	end if
c
	if(namegr.eq.3)then
	call region (60,400,200,120)
	call axes(5,yy,17,5,xx,10)
	end if
	if(namegr.eq.4)then
	call region (60,580,200,120)
	call axes(5,yy,17,5,xx,10)
	end if
c
c	lin=namegr-1
	lin=0
         call disp(y,tgraf,nigr,lin)
         call redraw
	end do
c
         n_p=50000*i_t
	do i=1,i_t
           do j=1,n_p
	x_t=exp( 5.d0)
	end do
        end do
c        pause ' call endprogram'
c     
c      call endvm
      return
      end
      subroutine minmax(f,x,n)
	include 'double.inc'
	common /min_max/xmn,xmx,fmn,fmx
      dimension f(n),x(n)
	call minmax_o(fmn,fmx,f,n)
	call minmax_o(xmn,xmx,x,n)
      end
c=======================================================================
c
	subroutine minmax_o(fmn,fmx,f,n)
	include 'double.inc'
	dimension f(n)
      fmx=-1.e+16
      fmn=1e+16
      do i=1,n
         if(fmx.lt.f(i)) fmx=f(i)
         if(fmn.gt.f(i)) fmn=f(i)
      enddo
      if(abs(fmx)+abs(fmn).lt.1.e-15) then
         fmn=-1.
         fmx=1.
      else
c         if(abs(fmx-fmn)/(abs(fmn)+abs(fmx)).lt.1e-3) then
         if(abs(fmx-fmn)/(abs(fmn)+abs(fmx)).lt.1e-6) then
            if(fmx.gt.0.) then
               fmn=0.
               fmx=2.*fmx
            else
               fmn=2.*fmx
               fmx=0.
            endif
         endif
      endif
c
	return
        end
	subroutine prof_t(y,tgraf,ngraf,yy)	
	include 'double.inc'
	common /i_time/i_t     
	common /coord/ixx,iyy,iw,ih 
	dimension y(ngraf),tgraf(ngraf)
      character*20 yy,xx,ch
	xx=' time, ms '
      nigr=ngraf
c     
      call  initvm(10,10,800,680)
c
      namegr=0
c
	do i=1,3     
         namegr=namegr+1
c
	call minmax(y,tgraf,nigr)
c
	if(namegr.eq.1)then
	call region (60,40,200,200)
	call axes(5,yy,17,3,xx,10)
	end if
c
	if(namegr.eq.2)then
	call region (200,300,170,340)
	call axes(5,yy,17,3,xx,10)
	end if
c
	if(namegr.eq.3)then
	call region (430,40,300,600)
	call axes(5,yy,17,5,xx,10)
	end if
c
	lin=namegr-1
         call disp(y,tgraf,nigr,lin)
         call redraw
	end do
c
	do k=1,4
	yy='t_1='
	ttt=1000.	
	if(k.eq.1) call ltext(30,320,yy,ttt)     
	if(k.eq.2) call ltext(30,370,yy,ttt)     
	if(k.eq.1) call ltext(30,420,yy,ttt)     
	if(k.eq.1) call ltext(30,470,yy,ttt)     
	end do
         call redraw
c
         n_p=50000*i_t
	do i=1,i_t
           do j=1,n_p
	x_t=exp( 5.d0)
	end do
        end do
c        pause ' call endprogram'
c     
c      call endvm
      return
      end
c
	subroutine ltext(i0,j0,yy,ttt)     
	include 'double.inc'
        character *20 ch,yy(*)
ccc	call textvm(i0,j0,yy,4)
	call textvm(i0,j0,yy,5)
c	write(ch(1:8),'(f8.3)' )ttt
	write(ch(1:11),'(f11.3)' )ttt
ccc	write(ch(1:18),'(f18.8)' )ttt
	call textvm(i0+40,j0,ch,11)
ccc	call textvm(i0+40,j0,ch,18)
	return
	end
c-------------
	subroutine region (i0,j0,idx,jdy)
	include 'double.inc'
	common /coord/ixx,iyy,iw,ih 
c
	 ixx=i0
         iyy=j0
c
         iw=idx
         ih=jdy
	return
	end
c----------
      subroutine axes(n_y,txt,ntxt,n_x,xx,n_xx)
	include 'double.inc'
	common /coord/ixx,iyy,iw,ih 
	common /min_max/xmn,xmx,fmn,fmx
      character ch*6,txt(*),xx(*)

c!!!	call correct()

c---------
c         ixx  iyy   iw   ih 
c-----------
      dx=iw/(xmx-xmn)
      dy=ih/(fmx-fmn)
c
      call setlin(0,0)
      call color(15)
      iPx=8
      call dfnfnt(0,iPx,0)
      call rectvm(ixx-6*iPx,iyy-18,iw+6*iPx+12,ih+30,1)
      call color(0)
      call rectvm(ixx,iyy,iw,ih,0)
      call setlin(2,0)
      call color(12)
c      n_x=5
c      if(iw.gt.400) n_tk=10
      gdx=1./n_x
      do i=1,n_x+1
         s=xmn+(xmx-xmn)*(i-1)*gdx
         call numstr(s,ch,4)
         jx2=ixx+dx*(s-xmn)
         call textvm(jx2-3*iPx,iyy+ih+12,ch,4)
         if(i.gt.1.and.i.le.n_x)
     &        call drawvm(jx2,iyy,jx2,iyy+ih)
      enddo
c	n_y=5
      gdy=1./n_y
      do i=1,n_y+1
         s=fmn+(fmx-fmn)*(i-1)*gdy
         call numstr(s,ch,6)
         jy2=iyy+ih-dy*(s-fmn)
         call textvm(ixx-6*iPx,jy2+1,ch,6)
         if(i.ne.1) call drawvm(ixx,jy2,ixx+iw,jy2)
      enddo
c
      iPx=9
      call dfnfnt(0,iPx,0)
	ix_t=ixx+0.5*iw-12
	iy_t=iyy-5
      call textvm(ix_t,iy_t,txt,ntxt)
      iPx=9
      call dfnfnt(0,iPx,0)
	ix_t=ixx+0.5*iw-15
	iy_t=iyy+ih+12+16
      call textvm(ix_t,iy_t,xx,n_xx)
      end
c
c
      subroutine exam_4(d_x,d_y)
	include 'double.inc'
	common /coord/ixx,iyy,iw,ih 
	common /min_max/xmn,xmx,fmn,fmx
      dimension wx(100),wy(100)
c
	include 'parf1'
      COMMON
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf2/RR(nmax,KF),ZZ(nmax,KF),pw(nmax,kf)
     *  /pf2e/rg(4,kf),zg(4,kf)
     *  /pf3/nmx(kf),turn(kf)
c
c
      dx=iw/(xmx-xmn)
      dy=ih/(fmx-fmn)
c         if(kpr.eq.1)print*,'namegr i2 i1 ixx iyy',namegr,i2,i1,ixx,iyy
      call color(0)
c--------
        call setlin(0,0)
c=====
	do i=1,npf
	j=1
	rg(1,i)=rr(j,i)
	zg(1,i)=zz(j,i)
c
	do k=2,4
	rg(k,i)=rg(1,i)
	zg(k,i)=zg(1,i)
	end do
c
	do j=2,nmx(i)
	rg(1,i)=amin1(rr(j,i),rg(1,i))
	zg(1,i)=amin1(zz(j,i),zg(1,i))
c
	rg(3,i)=amax1(rr(j,i),rg(3,i))
	zg(3,i)=amax1(zz(j,i),zg(3,i))
	end do
	rg(2,i)=rg(1,i)
	zg(2,i)=zg(3,i)
c
	rg(4,i)=rg(3,i)
	zg(4,i)=zg(1,i)
c
	do j=1,4
c  begin PF coils......
c
	wx(j)=rg(j,i)
	wy(j)=zg(j,i)
	end do
	wx(5)=wx(1)
	wy(5)=wy(1)
c----------
      k=1
      jx2=ixx+dx*(wx(k)-xmn)
      jy2=iyy+ih-dy*(wy(k)-fmn)
      do k=2,5
         jx1=jx2
         jy1=jy2
         jx2=ixx+dx*(wx(k)-xmn)
         jy2=iyy+ih-dy*(wy(k)-fmn)
         call drawvm(jx1,jy1,jx2,jy2)
      enddo
c
	end do
      return
      end
c
      subroutine exam_5(r,z,n,lin,d_x,d_y)
	include 'double.inc'
	common /coord/ixx,iyy,iw,ih 
	common /min_max/xmn,xmx,fmn,fmx
      dimension r(n),z(n),wx(100),wy(100)
c
      dx=iw/(xmx-xmn)
      dy=ih/(fmx-fmn)
c         if(kpr.eq.1)print*,'namegr i2 i1 ixx iyy',namegr,i2,i1,ixx,iyy
      call color(0)
c--------
	if(lin.eq.0)lin1=0
	if(lin.eq.1)lin1=1
	if(lin.eq.2)lin1=2
	if(lin.eq.3)lin1=3
c
        call setlin(lin1,0)
c
	do ii=1,n
c  begin nps.....
        r_c=r(ii)
	z_c=z(ii)
c
	wx(1)=r_c-0.5*d_x
	wy(1)=z_c-0.5*d_y
c
	wx(2)=r_c+0.5*d_x
	wy(2)=z_c+0.5*d_y
c
	wx(3)=r_c+0.5*d_x
	wy(3)=z_c-0.5*d_y
c
	wx(4)=r_c-0.5*d_x
	wy(4)=z_c+0.5*d_y
c----------
      i=1
      jx2=ixx+dx*(wx(i)-xmn)
      jy2=iyy+ih-dy*(wy(i)-fmn)
         jx1=jx2
         jy1=jy2
      i=2	
      jx2=ixx+dx*(wx(i)-xmn)
      jy2=iyy+ih-dy*(wy(i)-fmn)
         call drawvm(jx1,jy1,jx2,jy2)
      i=3
      jx2=ixx+dx*(wx(i)-xmn)
      jy2=iyy+ih-dy*(wy(i)-fmn)
         jx1=jx2
         jy1=jy2
      i=4	
      jx2=ixx+dx*(wx(i)-xmn)
      jy2=iyy+ih-dy*(wy(i)-fmn)
         call drawvm(jx1,jy1,jx2,jy2)
	end do
      return
      end
c
      subroutine exam_3(r,z,n,lin,d_x,d_y)
	include 'double.inc'
	common /coord/ixx,iyy,iw,ih 
	common /min_max/xmn,xmx,fmn,fmx
      dimension r(n),z(n),wx(100),wy(100)
c
      dx=iw/(xmx-xmn)
      dy=ih/(fmx-fmn)
c         if(kpr.eq.1)print*,'namegr i2 i1 ixx iyy',namegr,i2,i1,ixx,iyy
      call color(0)
c--------
	if(lin.eq.0)lin1=0
	if(lin.eq.1)lin1=1
	if(lin.eq.2)lin1=2
	if(lin.eq.3)lin1=3
c
        call setlin(lin1,0)
c
	do ii=1,n
c  begin vessel.....
        r_c=r(ii)
	z_c=z(ii)
c
	wx(1)=r_c-0.5*d_x
	wy(1)=z_c-0.5*d_y
c
	wx(2)=r_c-0.5*d_x
	wy(2)=z_c+0.5*d_y
c
	wx(3)=r_c+0.5*d_x
	wy(3)=z_c+0.5*d_y
c
	wx(4)=r_c+0.5*d_x
	wy(4)=z_c-0.5*d_y
c
	wx(5)=wx(1)
	wy(5)=wy(1)
c----------
      i=1
      jx2=ixx+dx*(wx(i)-xmn)
      jy2=iyy+ih-dy*(wy(i)-fmn)
      do i=2,5
         jx1=jx2
         jy1=jy2
         jx2=ixx+dx*(wx(i)-xmn)
         jy2=iyy+ih-dy*(wy(i)-fmn)
         call drawvm(jx1,jy1,jx2,jy2)
      enddo
	end do
      return
      end
c
      subroutine disp(f,x,n,lin)
	include 'double.inc'
	common /coord/ixx,iyy,iw,ih 
	common /min_max/xmn,xmx,fmn,fmx
      dimension f(n),x(n)
c
      dx=iw/(xmx-xmn)
      dy=ih/(fmx-fmn)
c         if(kpr.eq.1)print*,'namegr i2 i1 ixx iyy',namegr,i2,i1,ixx,iyy
      call color(0)
c--------
	if(lin.eq.0)lin1=0
	if(lin.eq.1)lin1=1
	if(lin.eq.2)lin1=2
	if(lin.eq.3)lin1=3
        call setlin(lin1,0)
c----------
      i=1
      jx2=ixx+dx*(x(i)-xmn)
      jy2=iyy+ih-dy*(f(i)-fmn)
      do i=2,n
         jx1=jx2
         jy1=jy2
         jx2=ixx+dx*(x(i)-xmn)
         jy2=iyy+ih-dy*(f(i)-fmn)
         call drawvm(jx1,jy1,jx2,jy2)
      enddo
      return
      end
c
      subroutine exam_3_i(r,z,n,lin,d_r,d_z)
	include 'double.inc'
	common /coord/ixx,iyy,iw,ih 
	common /min_max/xmn,xmx,fmn,fmx
      dimension r(n),z(n),d_r(n),d_z(n),wx(100),wy(100)
c
      dx=iw/(xmx-xmn)
      dy=ih/(fmx-fmn)
c         if(kpr.eq.1)print*,'namegr i2 i1 ixx iyy',namegr,i2,i1,ixx,iyy
      call color(0)
c--------
	if(lin.eq.0)lin1=0
	if(lin.eq.1)lin1=1
	if(lin.eq.2)lin1=2
	if(lin.eq.3)lin1=3
c
        call setlin(lin1,0)
c
	do ii=1,n
c  begin vessel.....
        r_c=r(ii)
	z_c=z(ii)
        d_x=d_r(ii)
	d_y=d_z(ii)
c
	wx(1)=r_c-0.5*d_x
	wy(1)=z_c-0.5*d_y
c
	wx(2)=r_c-0.5*d_x
	wy(2)=z_c+0.5*d_y
c
	wx(3)=r_c+0.5*d_x
	wy(3)=z_c+0.5*d_y
c
	wx(4)=r_c+0.5*d_x
	wy(4)=z_c-0.5*d_y
c
	wx(5)=wx(1)
	wy(5)=wy(1)
c----------
      i=1
      jx2=ixx+dx*(wx(i)-xmn)
      jy2=iyy+ih-dy*(wy(i)-fmn)
      do i=2,5
         jx1=jx2
         jy1=jy2
         jx2=ixx+dx*(wx(i)-xmn)
         jy2=iyy+ih-dy*(wy(i)-fmn)
         call drawvm(jx1,jy1,jx2,jy2)
      enddo
	end do
      return
      end
      
	subroutine ltext_jt(i0,j0,yy,kyy,ttt)     
	include 'double.inc'
        character *20 ch,yy(*)

	call textvm(i0,j0,yy,kyy)

	if(ttt.lt.1000.)then
           write(ch(1:11),'(f11.6)' )ttt
           call textvm(i0+70,j0,ch,11)
        end if
           
	if(ttt.ge.1000.)then
           write(ch(1:14),'(1pe14.7)' )ttt
           call textvm(i0+70,j0,ch,14)
        end if

	return
	end


c
      subroutine limits(x_l,x_r,y_l,y_r)
	include 'double.inc'
	common /min_max/xmn,xmx,fmn,fmx
c
      fmn=y_l
      fmx=y_r
         xmn=x_l
         xmx=x_r
      return
      end
	include 'graf9603.inc'


