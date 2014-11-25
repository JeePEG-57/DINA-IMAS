	subroutine svdcmp(a,m,n,mp,np,w,v)
	implicit real*8 (a-h,o-z)
c	  Given a matrix A, with logical dimensions M by N and 
c	  physical dimensions MP by NP, this routine computes its
c	  singular value decomposition, A=U*W*V**T. The matrix U
c	  replaces A on output. The diagonal matrix of singular
c	  values W is output as a vector W. The matrix V (not the
c	  transpose V**T) is output as V. M must be greater or equal
c	  to N; if it is smaller, then A should be filled up to
c	  square with zero rows.
	parameter (nmax=300)
c	  Maximum anticipated value of N.
	dimension a(mp,np),w(np),v(np,np),rv1(nmax)
	common
     *  /ge5/kpr
	if(m.lt.n.and.kpr.eq.1)
     *   print *, 'You must augment A with extra zero rows.'
c	  Householder reduction to bidiagonal form.
	g=0.0
	scale=0.0
	anorm=0.0
	do 25 i=1,n
	l=i+1
	rv1(i)=scale*g
	g=0.0
	s=0.0
	scale=0.0
	if (i.le.m) then
	do 11 k=i,m
	scale=scale+abs(a(k,i))
11	continue
!	if (scale.ne.0.0) then
	if ( abs(scale-0.0).gt.1.d-10) then
	do 12 k=i,m
	a(k,i)=a(k,i)/scale
	s=s+a(k,i)*a(k,i)
12	continue
	f=a(i,i)
	g=-sign(sqrt(s),f)
	h=f*g-s
	a(i,i)=f-g
	if (i.ne.n) then
	do 15 j=l,n
	s=0.0
	do 13 k=i,m
	s=s+a(k,i)*a(k,j)
13	continue
	f=s/h
	do 14 k=i,m
	a(k,j)=a(k,j)+f*a(k,i)
14	continue
15	continue
	endif
	do 16 k=i,m
	a(k,i)=scale*a(k,i)
16	continue
	endif
	endif
	w(i)=scale*g
	g=0.0
	s=0.0
	scale=0.0
	if ((i.le.m).and.(i.ne.n)) then
	do 17 k=l,n
	scale=scale+abs(a(i,k))
17	continue
!	if (scale.ne.0.0) then
	if ( abs(scale-0.0).gt.1.d-10) then
	do 18 k=l,n
	a(i,k)=a(i,k)/scale
	s=s+a(i,k)*a(i,k)
18	continue
	f=a(i,l)
	g=-sign(sqrt(s),f)
	h=f*g-s
	a(i,l)=f-g
	do 19 k=l,n
	rv1(k)=a(i,k)/h
19	continue
	if (i.ne.m) then
	do 23 j=l,m
	s=0.0
	do 21 k=l,n
	s=s+a(j,k)*a(i,k)
21	continue
	do 22 k=l,n
	a(j,k)=a(j,k)+s*rv1(k)
22	continue
23	continue
	endif
	do 24 k=l,n
	a(i,k)=scale*a(i,k)
24	continue
	endif
	endif
	anorm=max(anorm,(abs(w(i))+abs(rv1(i))))
25	continue
c	  Accumulation of right-hand transformations.
	do 32 i=n,1,-1
	if (i.lt.n) then
!	if (g.ne.0.0) then
	if ( abs(g-0.0).gt.1.d-10) then
	do 26 j=l,n
c	  Double division to anoid possible underflow:
	v(j,i)=(a(i,j)/a(i,l))/g
26	 continue
	do 29 j=l,n
	s=0.0
	do 27 k=l,n
	s=s+a(i,k)*v(k,j)
27	continue
	do 28 k=l,n
	v(k,j)=v(k,j)+s*v(k,i)
28	continue
29	continue
	endif
	do 31 j=l,n
	v(i,j)=0.0
	v(j,i)=0.0
31	continue
	endif
	v(i,i)=1.0
	g=rv1(i)
	l=i
32	continue
c	  Accumulation of left-hand transformations.
	do 39 i=n,1,-1
	l=i+1
	g=w(i)
	if(i.lt.n) then
	do 33 j=l,n
	a(i,j)=0.0
33	continue
	endif
!	if (g.ne.0.0) then
	if ( abs(g-0.0).gt.1.d-10) then
	g=1.0/g
	if (i.ne.n) then
	do 36 j=l,n
	s=0.0
	do 34 k=l,m
	s=s+a(k,i)*a(k,j)
34	continue
	f=(s/a(i,i))*g
	do 35 k=i,m
	a(k,j)=a(k,j)+f*a(k,i)
35	continue
36	continue
	endif
	do 37 j=i,m
	a(j,i)=a(j,i)*g
37	continue
	else
	do 38 j=i,m
	a(j,i)=0.0
38	continue
	endif
	a(i,i)=a(i,i)+1.0
39	continue
c	  Diagonalization of the bidiagonal form.
	do49 k=n,1,-1
c	  Loop over singular values.
	do48 its=1,30

	its1=its

c	  Loop over allowed iterations.
	do 41 l=k,1,-1
c	  Test for splitting:
	nm=l-1
c	  Note that RV1(1) is always zero.

	if ( abs( (abs(rv1(l))+anorm)-anorm ).lt.1.d-10) go to 2


c	if ((abs(rv1(l))+anorm).eq.anorm) go to 2

c	if ((abs(w(nm))+anorm).eq.anorm) go to 1
	if ( abs( (abs(w(nm))+anorm)-anorm).lt.1.d-10) go to 1
41	continue
1	c=0.0
c	  Cancellation of RV1(L), if L>1:
	s=1.0
	do43 i=l,k
	f=s*rv1(i)
!	if ((abs(f)+anorm).ne.anorm) then
	if ( abs((abs(f)+anorm)-anorm).gt.1.d-10) then
	g=w(i)
	h=sqrt(f*f+g*g)
	w(i)=h
	h=1.0/h
	c= (g*h)
	s=-(f*h)
	do42 j=1,m
	y=a(j,nm)
	z=a(j,i)
	a(j,nm)=(y*c)+(z*s)
	a(j,i)=-(y*s)+(z*c)
42	continue
	endif
43	continue
2	z=w(k)
	if (l.eq.k) then
c	  Convergence.
	if (z.lt.0.0) then
c	  Singular value is made nonnegative.
	w(k)=-z
	do44 j=1,n
	v(j,k)=-v(j,k)
44	continue
	endif
	go to 3
	endif
	if (its.eq.30.and.kpr.eq.1) 
     *   print *, 'No convergence in 30 iterations'
	if (its.gt.50) stop
	x=w(l)
c	  Shift from bottom 2-by-2 minor:
	nm=k-1
	y=w(nm)
	g=rv1(nm)
	h=rv1(k)
	f=((y-z)*(y+z)+(g-h)*(g+h))/(2.0*h*y)
	g=sqrt(f*f+1.0)
	f=((x-z)*(x+z)+h*((y/(f+sign(g,f)))-h))/x
c	  Next QR transformation:
	c=1.0
	s=1.0
	do47 j=l,nm
	i=j+1
	g=rv1(i)
	y=w(i)
	h=s*g
	g=c*g
	z=sqrt(f*f+h*h)
	rv1(j)=z
	c=f/z
	s=h/z
	f= (x*c)+(g*s)
	g=-(x*s)+(g*c)
	h=y*s
	y=y*c
	do45 jj=1,n
	x=v(jj,j)
	z=v(jj,i)
	v(jj,j)= (x*c)+(z*s)
	v(jj,i)=-(x*s)+(z*c)
45	continue
	z=sqrt(f*f+h*h)
	w(j)=z
c	 Rotation can be arbitrary if Z=0.
!	if (z.ne.0.0) then
	if ( abs(z-0.0).gt.1.d-10) then
	z=1.0/z
	c=f*z
	s=h*z
	endif
	f= (c*g)+(s*y)
	x=-(s*g)+(c*y)
	do46 jj=1,m
	y=a(jj,j)
	z=a(jj,i)
	a(jj,j)= (y*c)+(z*s)
	a(jj,i)=-(y*s)+(z*c)
46	continue
47	continue
	rv1(l)=0.0
	rv1(k)=f
	w(k)=x
48	continue
3	continue
49	continue


	if(kpr.eq.1)print *, 'iterations',its1


	return
	end




