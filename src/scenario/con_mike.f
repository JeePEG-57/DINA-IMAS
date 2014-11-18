c  %W% %G%

	subroutine read_gaps()

C  reads information needed for Verta and Vertb calculation
C  n_inta is number of internal variables for Verta 
C  n_intb is number of internal variables for Vertb
C  n_gaps is 1, resposible for dfz variable 
C	call inv_con_a()  calculates inversion of matrix for Verta
C	call inv_con_b()  calculates inversion of matrix for Vertb

	include 'double.inc'
        include 'parf8'
        common
     *  /c_con1/n_inta,n_intb
	common
     *  /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
	common /ge5/kpr
c
	open(unit=40,file='gaps_data',form='formatted')
	read (40,*)
	read (40,*)n_inta,n_intb,n_gaps
c---
	if(kpr.eq.1) print *,' n_inta,n_intb,n_gaps- ',n_inta,n_intb,n_gaps
c--
	close (unit=40)
c---------------
	call inv_con_a()
	call inv_con_b()
c-------------
        return
        end
c
	subroutine c_verta(verta,dfz)

C  calculates Verta, input is dfz 
C  n_inta is number of internal variables for Verta 
C  n_gaps is 1, resposible for dfz variable 
C  x_a is vector of internal variables, 
C  x0_a is vector of internal variables from previous time step 
C  b_a is B matrix
C  c_a is C matrix
C  a1_a is  inverse matrix
C  tay is time step in msec

C  dx/dt=A*x+B*dfz
C  verta=C*x
C  (x-x0)/tay=A*x+B*dfz
C   x/tay-A*x=x0/tay+B*dfz
C   x*(1/tay-A)=x0/tay+B*dfz
C   x=A1*(x0/tay+B*dfz)
C   A1=inv(1./tay-A)


	include 'double.inc'
	include 'parf1'
	include 'parf8'
c
	common
     *  /ge2/ntay,tay,tt
c	
	common
     *  /c_con_a/a_a(kf_c,kf_c),b_a(kf_c,kf_c),
     *  c_a(kf_c,kf_c),d_a(kf_c,kf_c),a_1a(kf_c,kf_c)

	common
     *  /abcdx_a/x_a(kf_c),x0_a(kf_c)

	common
     *  /abcdx/x(kf_c),x0(kf_c),gaps0(kf_c),d_gaps(kf_c)
c

	common
     *  /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps

     *  /c_con1/n_inta,n_intb
c
	dimension fu(kf_c)
c
	character *70 apr

	do j=1,n_gaps
	   d_gaps(j)=dfz
	end do

c
	do i=1,n_inta
	fu(i)=x0_a(i)/(tay*1.e-3)
	do j=1,n_gaps
	fu(i)=fu(i)+b_a(i,j)*d_gaps(j)
	end do
	end do
c
	do i=1,n_inta
	x_a(i)=0.
	do j=1,n_inta
	x_a(i)=x_a(i)+a_1a(i,j)*fu(j)
	end do
	end do
c
	apr='x_a'
	if(kpr.eq.1) print 71,apr,(x_a(i),i=1,n_inta)

	verta=0.
	i=1
	do k=1,n_inta
	verta=verta+c_a(i,k)*x_a(k)
	end do	

c
71	format(5x,a70/,(1X,6(1pe11.3)))
	return
	end

	subroutine c_vertb(vertb,dfz)

C  calculates Vertb, input is dfz 
C  n_intb is number of internal variables for Vertb 
C  n_gaps is 1, resposible for dfz variable 
C  x_b is vector of internal variables, 
C  x0_b is vector of internal variables from previous time step 
C  b_b is B matrix
C  c_b is C matrix
C  a1_b is  inverse matrix
C  tay is time step in msec

C  dx/dt=A*x+B*dfz
C  vertb=C*x
C  (x-x0)/tay=A*x+B*dfz
C   x/tay-A*x=x0/tay+B*dfz
C   x*(1/tay-A)=x0/tay+B*dfz
C   x=A1*(x0/tay+B*dfz)
C   A1=inv(1./tay-A)

	include 'double.inc'
	include 'parf1'
	include 'parf8'
c
	common
     *  /ge2/ntay,tay,tt
c	
c
     *  /c_con_b/a_b(kf_c,kf_c),b_b(kf_c,kf_c),
     *  c_b(kf_c,kf_c),d_b(kf_c,kf_c),a_1b(kf_c,kf_c)


	common
     *  /abcdx/x(kf_c),x0(kf_c),gaps0(kf_c),d_gaps(kf_c)

	common
     *  /abcdx_b/x_b(kf_c),x0_b(kf_c)
c

	common
     *  /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
        common
     *  /c_con1/n_inta,n_intb


	dimension fu(kf_c)
c
	character *70 apr

	do j=1,n_gaps
	   d_gaps(j)=dfz
	end do

c
	do i=1,n_intb
	fu(i)=x0_b(i)/(tay*1.e-3)
c	fu(i)=x0_b(i)/(tay*1.e-0)
	do j=1,n_gaps
	fu(i)=fu(i)+b_b(i,j)*d_gaps(j)
	end do
	end do
c
	do i=1,n_intb
	x_b(i)=0.
	do j=1,n_intb
	x_b(i)=x_b(i)+a_1b(i,j)*fu(j)
	end do
	end do
c
	apr='x'
c	if(kpr.eq.1) print 71,apr,(x(i),i=1,n_int)

	apr='x_b'
	if(kpr.eq.1) print 71,apr,(x_b(i),i=1,n_intb)

	vertb=0.
	i=1
	do k=1,n_intb
	vertb=vertb+c_b(i,k)*x_b(k)
	end do	

c!!!
c	vertb=-vertb
c!!!!

c
71	format(5x,a70/,(1X,6(1pe11.3)))
	return
	end

	subroutine inv_con_a()
C  calculates inverse matrix for Verta calculation
C  reads A B C D matrixes
C  n_inta is number of internal variables for Verta 
C  n_gaps is 1, resposible for dfz variable 
C  a_a is A matrix
C  b_a is B matrix
C  c_a is C matrix
C  d_a is D matrix
C  a1_a is  inverse matrix
C  tay is time step in msec

C  dx/dt=A*x+B*dfz
C  vertb=C*x
C  (x-x0)/tay=A*x+B*dfz
C   x/tay-A*x=x0/tay+B*dfz
C   x*(1/tay-A)=x0/tay+B*dfz
C   x=A1*(x0/tay+B*dfz)
C   A1=inv(1./tay-A)
c---------------------------------------
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	include 'parf1'
	include 'parf8'
	common
     *  /ge2/ntay,tay,tt
     *  /ge5/kpr
c
     *  /c_con_a/a_a(kf_c,kf_c),b_a(kf_c,kf_c),
     *  c_a(kf_c,kf_c),d_a(kf_c,kf_c),a_1a(kf_c,kf_c)
c
	common /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
        common
     *  /c_con1/n_inta,n_intb
c
	dimension a(kf_c,kf_c),d(kf_c,kf_c),ed(kf_c,kf_c),ppm(kf_c),
     *  a_1(kf_c,kf_c)
	
	real *8 a,d,a_1
c
	character*70  apr
c
	open (unit=41,file='a_verta.flat',form='formatted')

	if(kpr.eq.1) print *,' a_a----------------'

	do i=1,n_inta
	read (41,*)(a_a(i,j),j=1,n_inta)
	if(kpr.eq.1) print *,(a_a(i,j),j=1,n_inta)
	end do

	close (41)
c-----
	open (unit=41,file='b_verta.flat',form='formatted')
	if(kpr.eq.1) print *,' b_a----------------'
	do i=1,n_inta
	read (41,*)(b_a(i,j),j=1,n_gaps)
	if(kpr.eq.1) print *,(b_a(i,j),j=1,n_gaps)
	end do

	close (41)
c-----
	open (unit=41,file='c_verta.flat',form='formatted')
c
	if(kpr.eq.1) print *,' c_a----------------'
	do i=1,1
	read (41,*)(c_a(i,j),j=1,n_inta)
	if(kpr.eq.1) print *,(c_a(i,j),j=1,n_inta)
	end do

	close (41)
c-----
	open (unit=41,file='d_verta.flat',form='formatted')

	if(kpr.eq.1) print *,' d_a----------------'

	do i=1,1
	read (41,*)(d_a(i,j),j=1,n_gaps)
	if(kpr.eq.1) print *,(d_a(i,j),j=1,n_gaps)
	end do

	close (41)

	do i=1,n_inta
	do j=1,n_inta
	a(i,j)=-a_a(i,j)
	end do
	a(i,i)=1./(tay*1.e-3)+a(i,i)
c	a(i,i)=a(i,i)+1./(tay*1.)
	end do
c	
	call obrm(a,a_1a,d,kf_c,n_inta)
	call obrm_8(a,a_1,d,kf_c,n_inta)
c
	if(kpr.eq.1) print*,'o ++ kay A_1a npf===',npf
c
	do i=1,n_inta
	do j=1,n_inta
	a_1a(i,j)=a_1(i,j)
	end do
	end do

	do i=1,n_inta
	do j=1,n_inta
	ed(i,j)=0.
	do k=1,n_inta
	ed(i,j)=ed(i,j)+a(i,k)*a_1a(k,j)
	end do
	end do
	end do
	apr='e{i}'
	do i=1,n_inta
	ppm(i)=ed(i,i)
	end do
	if(kpr.eq.1) print 71,apr,(ppm(i),i=1,n_inta)
	apr='e{j} [inter]'
	do j=1,1
	if(kpr.eq.1) print *,'j=',j
	if(kpr.eq.1) print 71,apr,(ed(j,i),i=1,n_inta)
	end do
71	format(20x,a70/,(6(1x,1pe10.3)))
	return
	end
	subroutine inv_con_b()
C  calculates inverse matrix for Vertb calculation
C  reads A B C D matrixes
C  n_intb is number of internal variables for Vertb
C  n_gaps is 1, resposible for dfz variable 
C  a_b is A matrix
C  b_b is B matrix
C  c_b is C matrix
C  d_b is D matrix
C  a1_b is  inverse matrix
C  tay is time step in msec

C  dx/dt=A*x+B*dfz
C  vertb=C*x
C  (x-x0)/tay=A*x+B*dfz
C   x/tay-A*x=x0/tay+B*dfz
C   x*(1/tay-A)=x0/tay+B*dfz
C   x=A1*(x0/tay+B*dfz)
C   A1=inv(1./tay-A)
c---------------------------------------

	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	include 'parf1'
	include 'parf8'
	common
     *  /ge2/ntay,tay,tt
     *  /ge5/kpr
c
     *  /c_con_b/a_b(kf_c,kf_c),b_b(kf_c,kf_c),
     *  c_b(kf_c,kf_c),d_b(kf_c,kf_c),a_1b(kf_c,kf_c)
c
	common 
     *  /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps

        common
     *  /c_con1/n_inta,n_intb
c
	dimension a(kf_c,kf_c),d(kf_c,kf_c),ed(kf_c,kf_c),ppm(kf_c),
     *  a_1(kf_c,kf_c)

	real *8 a,d,a_1
c
	character*70  apr
c
	open (unit=41,file='a_vertb.flat',form='formatted')

	if(kpr.eq.1) print *,' a_b----------------'

	do i=1,n_intb
	read (41,*)(a_b(i,j),j=1,n_intb)
	if(kpr.eq.1) print *,(a_b(i,j),j=1,n_intb)
	end do
	close (41)
c-----
	open (unit=41,file='b_vertb.flat',form='formatted')

	if(kpr.eq.1) print *,' b_b----------------'

	do i=1,n_intb
	read (41,*)(b_b(i,j),j=1,n_gaps)
	if(kpr.eq.1) print *,(b_b(i,j),j=1,n_gaps)
	end do

	close (41)
c-----
	open (unit=41,file='c_vertb.flat',form='formatted')
c
	if(kpr.eq.1) print *,' c_b----------------'

	do i=1,1
	read (41,*)(c_b(i,j),j=1,n_intb)
	if(kpr.eq.1) print *,(c_b(i,j),j=1,n_intb)
	end do

	close (41)
c-----
	open (unit=41,file='d_vertb.flat',form='formatted')

	if(kpr.eq.1) print *,' d_b----------------'
	do i=1,1
	read (41,*)(d_b(i,j),j=1,n_gaps)
	if(kpr.eq.1) print *,(d_b(i,j),j=1,n_gaps)
	end do

	close (41)

	do i=1,n_intb
	do j=1,n_intb
	a(i,j)=-a_b(i,j)
	end do
	a(i,i)=1./(tay*1.e-3)+a(i,i)
c	a(i,i)=1./(tay*1.e-0)+a(i,i)
c	a(i,i)=a(i,i)+1./(tay*1.)
	end do
c	
	call obrm(a,a_1b,d,kf_c,n_intb)
	call obrm_8(a,a_1,d,kf_c,n_intb)
c
c
	if(kpr.eq.1) print*,'o ++ kay A_1b ==='
c
	do i=1,n_intb
	do j=1,n_intb
	a_1b(i,j)=a_1(i,j)
	end do
	end do
c
	do i=1,n_intb
	do j=1,n_intb
	ed(i,j)=0.
	do k=1,n_intb
	ed(i,j)=ed(i,j)+a(i,k)*a_1b(k,j)
	end do
	end do
	end do
	apr='e{i}'
	do i=1,n_intb
	ppm(i)=ed(i,i)
	end do
	if(kpr.eq.1) print 71,apr,(ppm(i),i=1,n_intb)
	apr='e{j} [inter]'
	do j=1,1
	if(kpr.eq.1) print *,'j=',j
	if(kpr.eq.1) print 71,apr,(ed(j,i),i=1,n_intb)
	end do
71	format(20x,a70/,(6(1x,1pe10.3)))
	return
	end
