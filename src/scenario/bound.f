	subroutine bound(dpsi,ib,n)
	include 'double.inc'
	dimension ain3(4),pa3(4),qa3(4),qda3(4),dm0(4)
	dimension dpsi(n)
	include 'parf2'
        common
     *  /ge5/kpr
	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nn),y(MM),dx,dy
c
c	pause 'ib=1'
	if(ib.eq.1)then
	do ip=1,n
c
	do i=1,4
        ain3(i)=y(i)
	dm0(i)=psi(ip,i)
	end do
        awant=ain3(1)
c        awant=0.5*(ain3(1)+ain3(2))
        call thir(pa3,ain3)
        call abat3(qa3,qda3,ain3,awant)
	dpsda3=0.
	do i=1,4
        dpsda3=dpsda3+qda3(i)/pa3(i)*dm0(i)
	end do
	dpsda3=-dpsda3
	psend=-(psi(ip,2)-psi(ip,1))/dy
ccc	dpsda3=0.5*(psend+dpsda3)
	dpsi(ip)=dpsda3
c	if(kpr.eq.1)print *,'psend dpsda3',psend,dpsda3
	end do
	return
	end if
c
c	pause 'ib=3'
	if(ib.eq.3)then
c
	do ip=1,n
	n4=nz-4
	do i=1,4
        ain3(i)=y(n4+i)
	dm0(i)=psi(ip,n4+i)
	end do
        awant=ain3(4)
c        awant=0.5*(ain3(4)+ain3(3))
        call thir(pa3,ain3)
        call abat3(qa3,qda3,ain3,awant)
	dpsda3=0.
	do i=1,4
        dpsda3=dpsda3+qda3(i)/pa3(i)*dm0(i)
	end do
	psend=(psi(ip,nz)-psi(ip,nz-1))/dy
c	dpsda3=0.5*(psend+dpsda3)
	dpsi(ip)=dpsda3
c	if(kpr.eq.1)print *,'psend dpsda3',psend,dpsda3
	end do
	return
	end if
c
c	pause 'ib=2'
	if(ib.eq.2)then
c
	do ip=1,n
	do i=1,4
        ain3(i)=x(i)
	dm0(i)=psi(i,ip)
	end do
        awant=ain3(1)
c        awant=0.5*(ain3(1)+ain3(2))
        call thir(pa3,ain3)
        call abat3(qa3,qda3,ain3,awant)
	dpsda3=0.
	do i=1,4
        dpsda3=dpsda3+qda3(i)/pa3(i)*dm0(i)
	end do
	dpsda3=-dpsda3
	psend=-(psi(2,ip)-psi(1,ip))/dx
c	dpsda3=0.5*(psend+dpsda3)
	dpsi(ip)=dpsda3
c	if(kpr.eq.1)print *,'psend dpsda3',psend,dpsda3
	end do
	return
	end if
c
c	pause 'ib=4'
	if(ib.eq.4)then
c
	do ip=1,n
	n4=nr-4
	do i=1,4
        ain3(i)=x(n4+i)
	dm0(i)=psi(n4+i,ip)
	end do
        awant=ain3(4)
c        awant=0.5*(ain3(4)+ain3(3))
        call thir(pa3,ain3)
        call abat3(qa3,qda3,ain3,awant)
	dpsda3=0.
	do i=1,4
        dpsda3=dpsda3+qda3(i)/pa3(i)*dm0(i)
	end do
	psend=(psi(nr,ip)-psi(nr-1,ip))/dx
c	dpsda3=0.5*(psend+dpsda3)
	dpsi(ip)=dpsda3
c	if(kpr.eq.1)print *,'psend dpsda3',psend,dpsda3
	end do
	return
	end if
c
	end



