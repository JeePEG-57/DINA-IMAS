          subroutine svdfit(amat,y,sig,ndata,a,ma,namat)

          implicit real *8 (a-h,o-z)

c	  Use X**2 minimization to determine the MA
c	  coefficients A of the fitting function F=sum{A(J)*AFUNC(J)}
c	  Arrays U,V,W provide workspace on input, on output they define
c	  the singular value decomposition, and can be used to obtain
c	  the covariance matrix. MP,NP are the physical dimensions of
c	  the matices U,V,W as indicated below. It is necessary that
c	  MP>NDATA,NP>MA. The program returns values for the MA fit
c	  parameters A, and X**2, CHISQ. The user supplies a subroutine
c
	include 'parf0'
	include 'parf5'

	parameter(tol=1.e-6)


	parameter (mp=nx, np=mx )
c	  Max expected NDATA and MA.
c-------------------------------------

	common /cont22/chisq

        common
     *  /c_svd1/chi(1000)
        common
     *  /ge5/kpr
        
        include 'double_svd0m.inc'

c-------------------------------
	dimension y(ndata),sig(ndata),a(ma),amat(namat,ma),v(np,np),
     *  u(mp,np),w(np),b(nx)

	character *8 mpr,apr
c
71	format(20x,a6/,(6(1pe10.3)))

	apr='sig'
c	if(kpr.eq.1)print 71,apr,(sig(i),i=1,ndata)

	do 12 i=1,ndata
	tmp=1./sig(i)
	do 11 j=1,ma
	u(i,j)=amat(i,j)*tmp
c	if(kpr.eq.1)print*,'i j amat(i,j)',i,j,amat(i,j)
11	continue
	b(i)=y(i)*tmp
12	continue
c

        if(kpr.eq.1)print*,'before svdcmp'

	call svdcmp(u,ndata,ma,mp,np,w,v)

        if(kpr.eq.1)print*,'after svdcmp'

c	  Singular value decomposition.

	wmax=w(1)
	wmin=w(1)

c	  Edit the singular values, given TOL from the parameter
c	  statement, between here...

	do13 j=1,ma
	if(kpr.eq.1)print *,'j w(j)',j,w(j)
	if(w(j).gt.wmax)wmax=w(j)
	if(w(j).lt.wmin)wmin=w(j)
13	continue

        condn=wmax/wmin

        if(kpr.eq.1)print *,' condn===================',condn

	thresh=tol*wmax
	do14 j=1,ma
	if(w(j).lt.thresh)then
	w(j)=0.
c	if(kpr.eq.1)print *,'j w(j)',j,w(j)
	end if
14	continue
c	  ...and here.
	call svbksb(u,w,v,ndata,ma,mp,np,b,a)
	chisq=0.
c	  Evalute chi-square.
	do 16 i=1,ndata
	sum=0.
	do15 j=1,ma
        sum=sum+amat(i,j)*a(j)
15	continue
	chisq=chisq+((y(i)-sum)/sig(i))**2

	chi(i)=((y(i)-sum)/sig(i))**2

	dels=y(i)-sum
c	if(kpr.eq.1)print*,'i=',i
c	if(kpr.eq.1)print *,' y(i) yc(i) dels sig',y(i),sum,dels,sig(i)
16	continue
	if(kpr.eq.1)print *,'chisq=',chisq
	do18 j=1,ma
c        if(kpr.eq.1)print *,'j a(j)',j,a(j)
18	continue
	return
	end
c===========================================
c	subroutine flopy(x,p,np)
	subroutine funcs(x,p,np)
	include 'double.inc'
c	  Fitting routine for a polynomial of degree NP-1,
c	  with NP coefficients.
	dimension p(np)
	p(1)=1.
	do11 j=2,np
	p(j)=p(j-1)*x
11	continue
	return
	end
c=========================================
	subroutine fleg(x,pl,nl)
	include 'double.inc'
c	  Fitting routine for an expansion with NL Legendre
c	  polynomials PL,evaluated using the reccurence
c	  relation as in paragraf 4.5.
	dimension pl(nl)
	pl(1)=1.
	pl(2)=x
	if(nl.gt.2) then
	twox=2.*x
	f2=x
	d=1.
	do11 j=3,nl
	f1=d
	f2=f2+twox
	d=d+1.
	pl(j)=(f2*pl(j-1)-f1*pl(j-2))/d
11	continue
	endif
	return
	end
c================================================
	subroutine svbksb(u,w,v,m,n,mp,np,b,x)

        implicit real *8 (a-h,o-z)

c	  Solves A*X=B for a vector X, where A is specified by
c	  the arrays U,W,V as returned by SVDCMP.M and N are the
c	  logical dimensions of A, and will be equal for square
c	  matrices. MP and NP are the physical dimensions of A. B
c	  is the input right-hand side. X is the output solution vector,
c	  No input quantities are destroyed, so the routine may be
c	  called sequentially with different B's.
	parameter (nmax=300)
c	  Maximum anticipated value of N.
c--------------------------------------
c-----------------------------------------
	dimension u(mp,np),w(np),v(np,np),b(mp),x(np),tmp(nmax)
	do12 j=1,n
c	  Calculate U**T*B.
	s=0.
	if(w(j).ne.0.)then
c	  Nonzero result only if w(j) is nonzero.
	do11 i=1,m
	s=s+u(i,j)*b(i)
11	continue
	s=s/w(j)
c	  This is the divide by w(j).
	endif
	tmp(j)=s
12	continue
	do14 j=1,n
c	  Matrix multiply V to get answer.
	s=0.
	do 13 jj=1,n
	s=s+v(j,jj)*tmp(jj)
13	continue
	x(j)=s
14	continue
	return
	end




