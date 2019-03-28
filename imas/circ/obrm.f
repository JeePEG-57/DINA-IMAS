	subroutine obrm_8(a,b,d,mu,n)
c-----------------------------------------
c   inverse matrix calculation
c-------------------------------- 
	implicit real*8 (a-h,o-z)
	dimension a(mu,n),b(mu,n),d(mu,n)
71	format(20x,a6/,12e10.3)
	do 1 i=1,n
	do 1 j=1,n
1	d(i,j)=a(i,j)
c
	do 40 i=1,n
	x=d(i,i)
	d(i,i)=1.
	do 10 j=1,n
10	d(i,j)=d(i,j)/x
	do 40 k=1,n
	if(k-i)20,40,20
20	x=d(k,i)
	d(k,i)=0.
	do 30 j=1,n
	d(k,j)=d(k,j)-x*d(i,j)	
30	continue
40	continue
	do 2 i=1,n
	do 2 j=1,n
2	b(i,j)=d(i,j)
	return
	end

	subroutine obrm(a,b,d,mu,n)
c-----------------------------------------
c   inverse matrix calculation
c-------------------------------- 
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	dimension a(mu,n),b(mu,n),d(mu,n)
71	format(20x,a6/,12e10.3)
	do 1 i=1,n
	do 1 j=1,n
1	d(i,j)=a(i,j)
c
	do 40 i=1,n
	x=d(i,i)
	d(i,i)=1.
	do 10 j=1,n
10	d(i,j)=d(i,j)/x
	do 40 k=1,n
	if(k-i)20,40,20
20	x=d(k,i)
	d(k,i)=0.
	do 30 j=1,n
	d(k,j)=d(k,j)-x*d(i,j)	
30	continue
40	continue
	do 2 i=1,n
	do 2 j=1,n
2	b(i,j)=d(i,j)
	return
	end







