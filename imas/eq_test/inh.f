
	subroutine inter_h1(f,aii,n,teta,val)
	
	include 'double.inc'
	dimension f(n),aii(n)
	include 'parf0'
	dimension aak(npo),bbk(npo),cck(npo)
	real *8 ai(npo),delt
	i=n-1
	ai(i-1)=aii(i-1)
	ai(i)=aii(i)
	ai(i+1)=aii(i+1)
c       if)kpr.eq.1)print *,'i n npo',i,n,npo
c       if)kpr.eq.1)print*,'ai(i-1) ai(i) ai(i+1)',ai(i-1),ai(i),ai(i+1)
	delt=ai(i+1)**2*ai(i)+ai(i)**2*ai(i-1)+
     *  ai(i-1)**2*ai(i+1)-
     *  ai(i-1)**2*ai(i)-ai(i)**2*ai(i+1)-ai(i+1)**2*ai(i-1)
c
c       if(abs(delt).lt.1.e-7)then
c       if)kpr.eq.1)print*,'delt=',delt
c       if)kpr.eq.1)print*,'ai(i-1) ai(i) ai(i+1)',ai(i-1),ai(i),ai(i+1)
c       if)kpr.eq.1)print*,'?????????????????????????????????????'
c
	aak(i)=(f(i+1)*ai(i)+f(i)*ai(i-1)+f(i-1)*ai(i+1)-
     *  f(i-1)*ai(i)-f(i)*ai(i+1)-f(i+1)*ai(i-1))/delt
	bbk(i)=(ai(i+1)**2*f(i)+ai(i)**2*f(i-1)+ai(i-1)**2
     *  *f(i+1)-
     *  ai(i-1)**2*f(i)-ai(i)**2*f(i+1)-ai(i+1)**2
     *  *f(i-1))/delt
	cck(i)=f(i)-aak(i)*ai(i)**2-bbk(i)*ai(i)
c        val=aak(i)*teta*teta+bbk(i)*teta+cck(I)
	val=2.*aak(i)*teta+bbk(i)
	return
	end
	subroutine inter_h0(f,aii,n,teta,val)
	include 'double.inc'
	dimension f(n),aii(n)
	include 'parf0'
	dimension aak(npo),bbk(npo),cck(npo)
	real *8 ai(npo),delt
	i=n-1
	ai(i-1)=aii(i-1)
	ai(i)=aii(i)
	ai(i+1)=aii(i+1)
c       if)kpr.eq.1)print *,'i n npo',i,n,npo
c       if)kpr.eq.1)print*,'ai(i-1) ai(i) ai(i+1)',ai(i-1),ai(i),ai(i+1)
	delt=ai(i+1)**2*ai(i)+ai(i)**2*ai(i-1)+
     *  ai(i-1)**2*ai(i+1)-
     *  ai(i-1)**2*ai(i)-ai(i)**2*ai(i+1)-ai(i+1)**2*ai(i-1)
c
c       if(abs(delt).lt.1.e-7)then
c       if)kpr.eq.1)print*,'delt=',delt
c       if)kpr.eq.1)print*,'ai(i-1) ai(i) ai(i+1)',ai(i-1),ai(i),ai(i+1)
c       if)kpr.eq.1)print*,'?????????????????????????????????????'
c
	aak(i)=(f(i+1)*ai(i)+f(i)*ai(i-1)+f(i-1)*ai(i+1)-
     *  f(i-1)*ai(i)-f(i)*ai(i+1)-f(i+1)*ai(i-1))/delt
	bbk(i)=(ai(i+1)**2*f(i)+ai(i)**2*f(i-1)+ai(i-1)**2
     *  *f(i+1)-
     *  ai(i-1)**2*f(i)-ai(i)**2*f(i+1)-ai(i+1)**2
     *  *f(i-1))/delt
	cck(i)=f(i)-aak(i)*ai(i)**2-bbk(i)*ai(i)
	val=aak(i)*teta*teta+bbk(i)*teta+cck(I)
c        val=2.*aak(i)*teta+bbk(i)
	return
	end




