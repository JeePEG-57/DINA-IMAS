	subroutine cam_t()
c---------------------------------------
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	include 'parf1'
c
	common
     *  /ge2/NTAY,TAY,TT
     *  /ge5/kpr
	common
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves3/b(mu,mu),pmj(mu,mu)
     *  /ves4/rcam(mu)
c
	dimension a(mu,mu),d(mu,mu)
c--------------------------------------
	do i=1,ncam
	do j=1,ncam
	a(i,j)=pmj(i,j)
	end do
	a(i,i)=a(i,i)+tay*rcam(i)*1.e5
	end do
c
	call obrm(a,b,d,mu,ncam)
	j=1
c	if(kpr.eq.1)print 71,apr,(pmj(j,i),i=1,ncam)
71	format(20x,a6/,(6(1x,1pe10.3)))
	return
	end



