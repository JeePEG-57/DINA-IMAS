


	subroutine B_SPLN ( x, b ,xx,n,k)
      IMPLICIT REAL*8(A-H,O-Z)
	include 'parf0'
	dimension t(npo),x(*),b(*),bb(npo,4)

c	if(kpr.eq.1)print *,' xx x(1)=',xx,x(1)
c	stop

	do j=1,4
	t(j)=x(1)

c	if(kpr.eq.1)print *,' j t=',j,t(j)
	end do

	do i=2,n
	t(i+3)=x(i)
	end do

	do i=n+1,n+3
	t(i+3)=x(n)
	ii=i+3
c	if(kpr.eq.1)print *,' i ii  t=',i,ii,t(ii)


	end do


	n3=n+3
	n4=n+4

	ii=4
	do i=2,n
	if(xx.ge.x(i-1))ii=i-1+3
	end do


c	if(kpr.eq.1)print *,' ii n=',ii,n

	do i=1,n4
	bb(i,1)=0.d0
	bb(i,2)=0.d0
	bb(i,3)=0.d0
	bb(i,4)=0.d0
	end do

	bb(ii,1)=1.d0

	do i=ii-3,ii

	del_ti1=(t(i+1)-t(i))+1.d-15
	del_ti2=(t(i+2)-t(i+1))+1.d-15

	bb(i,2)=(xx-t(i))/del_ti1*bb(i,1)+
     * (t(i+2)-xx)/del_ti2*bb(i+1,1)

c	if(kpr.eq.1)print *,' i bb(2)',i,bb(i,2)

	end do


	do i=ii-3,ii

	del_ti2=(t(i+2)-t(i))+1.d-15
	del_ti3=(t(i+3)-t(i+1))+1.d-15


	bb(i,3)=(xx-t(i))/del_ti2*bb(i,2)+
     *  (t(i+3)-xx)/del_ti3*bb(i+1,2)

c	if(kpr.eq.1)print *,' i bb(3)',i,bb(i,3)


	end do


	do i=ii-3,ii

	del_ti3=(t(i+3)-t(i))+1.d-15
	del_ti4=(t(i+4)-t(i+1))+1.d-15

	bb(i,4)=(xx-t(i))/del_ti3*bb(i,3)+
     *  (t(i+4)-xx)/del_ti4*bb(i+1,3)

c		if(kpr.eq.1)print *,' i bb(4)',i,bb(i,4)

	end do



c	if(kpr.eq.1)print *,' ii+4 t=',ii+4,t(ii+4)


	sum=0.
	do i=ii-3,ii
	k=i
	b(k)=bb(i,4)
	sum=sum+b(k)

c	if(kpr.eq.1)print *,' k b(k)=',k,b(k)

	end do

c	if(kpr.eq.1)print *,' sum=',sum


c b(i,1)=1   if t(i) < x < t(i+1) 	
c b(i,2)=(x-t(i))/(t(i+1)-t(i))*b(i,1)+(t(i+2)-x)/(t(i+2)-t(i+1))*b(i+1,1)	
c b(i,3)=(x-t(i))/(t(i+2)-t(i))*b(i,2)+(t(i+3)-x)/(t(i+3)-t(i+1))*b(i+1,2)	
c b(i,4)=(x-t(i))/(t(i+3)-t(i))*b(i,3)+(t(i+4)-x)/(t(i+4)-t(i+1))*b(i+1,3)	




	return
	end



	subroutine svd_bspline(
     *  n,n_pol,poa,pffx)

        IMPLICIT REAL*8(A-H,O-Z)
        
        dimension poa(*),pffx(*)

!!!	real poa,pffx

	include 'parf0'
	include 'parf5'

      dimension a_pol(npo)

	dimension amat(nx,mx),y(nx),
     *  sig(nx),a(mx)

	character *8 apr
c
	dimension yw(nx),b(npo),a_b(npo)

c	real xx,b,a_b


c
71	format(20x,a6/,(6(1pe10.3)))


c	n_b=20
c	n_b=n-6

	n_b=n_pol

	do i=1,n_b
!	a_b(i)=float(i-1)/float(n_b-1)
	a_b(i)=dfloat(i-1)/dfloat(n_b-1)
	end do


	xx=0.00000

c	call B_SPLN (a_b,b,xx,n_b,k)

	xx=0.000001

c	call B_SPLN (a_b,b,xx,n_b,k)

	xx=0.5

c	call B_SPLN (a_b,b,xx,n_b,k)




	xx=0.99999

c	call B_SPLN (a_b,b,xx,n_b,k)

	xx=1.0

c	call B_SPLN (a_b,b,xx,n_b,k)

	
c	stop

      kpr=0

!	n_pol=n-5

	n_pol=n

	ma=n_b+2

	nps=n

!	ndata=nps+ma
	ndata=nps

        seps1=1.e-1
        seps2=1000.

	if(kpr.eq.1)print *,'nps ma ndata ',nps,ma,ndata
c	if(kpr.eq.1)print *,' seps1  seps2',seps1,seps2

c
	do i=1,ndata
	do j=1,ma
	amat(i,j)=0.
	end do
	end do

        psmax=0.
	do ii=1,nps
	y(ii)=pffx(ii)
	yw(ii)=y(ii)

	if( psmax.lt.dabs(y(ii)) )psmax=dabs( y(ii) )
c
!!!	xx=(1.-poa(ii))
	xx=poa(ii)
	call B_SPLN (a_b,b,xx,n_b,k)

	do  jj=k-3,k
	amat(ii,jj)=b(jj)
c	if(kpr.eq.1.and.ii.le.5)print *,' i j amat=',ii,jj,amat(ii,jj)
        end do
	end do

c	if(kpr.eq.1)print *,' psmax==',psmax


c  here sigmas to npoints.....
	do i=1,nps
	sig(i)=seps1*(1.e-2*psmax+dabs(y(i)))
c	sig(i)=1.
	end do

c	stop



	namat=nx
	call svdfit(amat,y,sig,ndata,a,ma,namat)

	do ii=1,ndata
	do jj=1,ma

c      if(kpr.eq.1.and.ii.le.2)print *,' i j amat=',ii,jj,amat(ii,jj)

	end do
	end do
c




	apr='a'
c	if(kpr.eq.1)print 71,apr,(a(i),i=1,ma)



	apr='pffx'
c	if(kpr.eq.1)print 71,apr,(pffx(i),i=1,n)

	do ii=1,ndata
	flux=0.
	do jj=1,ma

      if(kpr.eq.1.and.ii.le.2)print *,' i j amat=',ii,jj,amat(ii,jj)

	flux=flux+amat(ii,jj)*a(jj)
	end do

	pffx(ii)=flux
c	if(kpr.eq.1)print *,'ii flux y   ',ii,flux,yw(ii)
c	if(kpr.eq.1)print *,'ii flux  sig  ',ii,flux,sig(ii)
c	if(kpr.eq.1)print *,'ii flux y sig  ',ii,flux,yw(ii),sig(ii)
	end do
c	stop

	apr='pffx'
c	if(kpr.eq.1)print 71,apr,(pffx(i),i=1,n)

c	stop


	do i=1,ma
	   a_pol(i)=a(i)
	end do

	do i=1,n

      xx=poa(i)
	call B_SPLN (a_b,b,xx,n_b,k)

      fpl=0.d0
	do  jj=k-3,k
	      fpl=fpl+b(jj)*a(jj)

	if(kpr.eq.1.and.i.le.4)then
c	print *,' i jj b amat',i,jj,b(jj),amat(i,jj)
	end if

	   end do

	   pffx(i)=fpl
	end do

	apr='pffx'
c	if(kpr.eq.1)print 71,apr,(pffx(i),i=1,n)


c	stop

	return
	end


c






	subroutine svd_test(
     *  n,n_pol,poa,pffx)

        IMPLICIT REAL*8(A-H,O-Z)
        
        dimension poa(*),pffx(*)

!!!	real poa,pffx

	include 'parf0'
	include 'parf5'

      dimension a_pol(npo)

	dimension amat(nx,mx),y(nx),
     *  sig(nx),a(mx)

	character *8 apr
c
	dimension yw(nx)
c
71	format(20x,a6/,(6(1pe10.3)))


        kpr=0

!	n_pol=n-5

	n_pol=n

	ma=n_pol


	nps=n

!	ndata=nps+ma
	ndata=nps

        seps1=1.e-4
        seps2=1000.

c	if(kpr.eq.1)print *,'nps ma ndata ',nps,ma,ndata
c	if(kpr.eq.1)print *,' seps1  seps2',seps1,seps2

c
	do i=1,ndata
	do j=1,ma
	amat(i,j)=0.
	end do
	end do

        psmax=0.
	do ii=1,nps
	y(ii)=pffx(ii)
	yw(ii)=y(ii)

	if( psmax.lt.dabs(y(ii)) )psmax=dabs( y(ii) )
c
!!!	xx=(1.-poa(ii))
	xx=poa(ii)

	jj=1
	amat(ii,jj)=1.
	do  jj=2,ma
	amat(ii,jj)=xx**float(jj-1)
c	if(kpr.eq.1)print *,' i j amat=',ii,jj,amat(ii,jj)
        end do
	end do

c	if(kpr.eq.1)print *,' psmax==',psmax


c  here sigmas to npoints.....
	do i=1,nps
	sig(i)=seps1*(1.e-1*psmax+dabs(y(i)))
c	sig(i)=1.
	end do


	namat=nx
	call svdfit(amat,y,sig,ndata,a,ma,namat)

	do ii=1,ndata
	flux=0.
	do jj=1,ma
	flux=flux+amat(ii,jj)*a(jj)
	end do
	if(kpr.eq.1)print *,'ii flux y sig  ',ii,flux,yw(ii),sig(ii)
	end do
	apr='a'
	if(kpr.eq.1)print 71,apr,(a(i),i=1,ma)

	apr='pffx'
c	if(kpr.eq.1)print 71,apr,(pffx(i),i=1,n)

	do i=1,ma
	   a_pol(i)=a(i)
	end do

	do i=1,n
	   j=1
	   fpl=a_pol(j)
!	   xx=(1.-poa(i))
	   xx=poa(i)
	   do j=2,ma
	      fpl=fpl+a_pol(j)*xx**(float(j-1))
	   end do

	   pffx(i)=fpl
	end do

	apr='pffx'
c	if(kpr.eq.1)print 71,apr,(pffx(i),i=1,n)


c	stop

	return
	end
c





	subroutine svd_test_old(
     *  n,n_pol,poa,pffx)

        IMPLICIT REAL*8(A-H,O-Z)
        
        dimension poa(*),pffx(*)

!!!	real poa,pffx

	include 'parf0'
	include 'parf5'

      dimension a_pol(npo)

	dimension amat(nx,mx),y(nx),
     *  sig(nx),a(mx)

	character *8 apr
c
	dimension yw(nx)
c
71	format(20x,a6/,(6(1pe10.3)))


        kpr=0

!	n_pol=n-5
!	n_pol=5

	ma=n_pol
	nps=n
	ndata=nps+ma

        seps1=1.e-2
        seps2=1000.

c	if(kpr.eq.1)print *,'nps ma ndata ',nps,ma,ndata
c	if(kpr.eq.1)print *,' seps1  seps2',seps1,seps2

c
	do i=1,ndata
	do j=1,ma
	amat(i,j)=0.
	end do
	end do

        psmax=0.
	do ii=1,nps
	y(ii)=pffx(ii)
	yw(ii)=y(ii)

	if( psmax.lt.dabs(y(ii)) )psmax=dabs( y(ii) )
c
!!!	xx=(1.-poa(ii))
	xx=poa(ii)

	jj=1
	amat(ii,jj)=1.
	do  jj=2,ma
	amat(ii,jj)=xx**float(jj-1)
c	if(kpr.eq.1)print *,' i j amat=',ii,jj,amat(ii,jj)
        end do
	end do

c	if(kpr.eq.1)print *,' psmax==',psmax

        k=0
	do i=nps+1,ndata
           y(i)=0.
           yw(i)=0.
           k=k+1
           amat(i,k)=1.
c	if(kpr.eq.1)print *,' i k amat=',i,k,amat(i,k)
	end do

c  here sigmas to npoints.....
	do i=1,nps
	sig(i)=seps1*(1.e-1*psmax+dabs(y(i)))
c	sig(i)=1.
	end do

	do i=nps+1,ndata
c	sig(i)=seps*psmax
	sig(i)=seps2
	end do

	apr='poa'
c	if(kpr.eq.1)print 71,apr,(poa(i),i=1,nps)
	apr='y'
c	if(kpr.eq.1)print 71,apr,(y(i),i=1,ndata)
	apr='sig'
c	if(kpr.eq.1)print 71,apr,(sig(i),i=1,ndata)

	namat=nx
	call svdfit(amat,y,sig,ndata,a,ma,namat)

	do ii=1,ndata
	flux=0.
	do jj=1,ma
	flux=flux+amat(ii,jj)*a(jj)
	end do
c	if(kpr.eq.1)print *,'ii flux y sig  ',ii,flux,yw(ii),sig(ii)
	end do
	apr='a'
c	if(kpr.eq.1)print 71,apr,(a(i),i=1,ma)

	apr='pffx'
c	if(kpr.eq.1)print 71,apr,(pffx(i),i=1,n)

	do i=1,ma
	   a_pol(i)=a(i)
	end do

	do i=1,n
	   j=1
	   fpl=a_pol(j)
!	   xx=(1.-poa(i))
	   xx=poa(i)
	   do j=2,ma
	      fpl=fpl+a_pol(j)*xx**(float(j-1))
	   end do

	   pffx(i)=fpl
	end do

	apr='pffx'
c	if(kpr.eq.1)print 71,apr,(pffx(i),i=1,n)

	return
	end
c





