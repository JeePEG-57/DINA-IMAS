c	include 'fgraph.fi'
	include 'double.inc'
	common /i_time/i_t
	include 'parf0'
	dimension a(npo),t(npo)
	character *20 yy
	n=npo
ccc	if(kpr.eq.1)print *,'i_t reading'
c	read (*,*)i_t
ccc	if(kpr.eq.1)print *,'i_t=',i_t
	do i=1,n
	t(i)=1.*i
	a(i)=t(i)
	end do
	yy='test'
c	call prof(a,t,n,yy)
        aa=1.
        bb=30.
	pi=3.14159
        dtet=2.*pi/npo
	tet=-dtet
        do i=1,npo
	tet=tet+dtet
        a(i)=aa*cos(tet)
        t(i)=bb*sin(tet)
	end do
c        call prof(a,t,npo,yy)
	call equil()
       stop
      END
