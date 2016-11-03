	subroutine ptoke0()
	include 'double.inc'
c	implicit real *8 (a-h,o-z)
c
	include 'parf0'
	include 'parf1'
	include 'parf2'
	include 'parf2e'
c
	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nn),y(MM),dx,dy
     *  /eq1g/psi_g(nr,nz)
     *  /eq1e/psext(nwnh),re(nre),ze(nze),dr,dz
     *  /eq3/FLUXARR(nwnh,kf)
     *  /eq10/vesarr(nwnh,mu)
     *  /eq12/omega,pspl0(nwnh)
c
	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ge1/pi
     *	/ge1e/rs0,tpl
     *  /ge5/kpr
     *  /ge7/eu,rout,zout,elong
c
	common
     *	/point1/r0,z0
c
	common
     *	/bunemn/nww,nhh,drdz2,rgrid1,delr,delz

	common
     *	/fluxc3/u(nwnh),work(nwnh),sib(nwnh)
     *	/fluxc7/coef,coef1,api

	 dimension f(nwnh),f_h(nwnh)
c++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	nww=nr-1
	nhh=nz-1
	rgrid1=x(1)
	delr=dx
	delz=dy
	drdz2=(delr/delz)**2
c++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	n=nn
	m=mm
	n1=n-1
	m1=m-1
c
	curd=tpl/(pi*eu**2)
c_________________________________________________
	COEF=10./(4.*PI)
	api=1./(2.*pi)
	coef1=dx*dy*coef

	if(kpr.eq.1)print *,'r0= ',r0,'  z0',z0, ' eu',eu

c  	call print3(' r0 z0 eu==',r0,z0,eu)

	tok=0.
c
	dist_min=1.e5
	DO I=1,N
	DO J=1,M
	kk=(i-1)*nz+j
	work(kk)=0.
	dist=sqrt( (x(i)-r0)**2+(y(j)-z0)**2)
	if(dist.le.dist_min )dist_min=dist
	if(dist.gt.eu )go to 9
	work(kk)=curd
	TOK=TOK+work(kk)
9	CONTINUE
	END DO
	END DO
74	format (20i2)
C
	TOK=TOK*COEF*dx*dy
C
	if(kpr.eq.1)print *,'TOK tpl dist_min= ',TOK,tpl,dist_min
c  	call print3(' TOK tpl dist_min==',TOK,tpl,dist_min)
C
c
	 al1=tpl/tok

	 tok=0.
	 do i=1,n
	 do j=1,m
 	 kk=(i-1)*nz+j
	 work(kk)=work(kk)*al1
	 f(kk)=work(kk)
	 tok=tok+f(kk)
	 end do
	 end do

	TOK=TOK*COEF*dx*dy

	if(kpr.eq.1)print *,'TOK tpl = ',TOK,tpl


	call pl_out(f)
!!!	call pl_out(f_h)

C   CALCULATE BOUNDARY PSIPL
C
	p_min=1.e10
	p_max=-1.e10

	k=0
	DO I=1,N
	DO J=1,M,M1
	k=k+1
	kk2=(i-1)*nz+j
c   calculations ---
	fpl=tpl*fp(r0,x(i),z0,y(j))
	pspl(kk2)=fpl/(2.*pi)
	
c	print *,' kk2 pspl',kk2,pspl(kk2)

	p_min=dmin1(p_min,pspl(kk2))
	p_max=dmax1(p_max,pspl(kk2))

	end do
	end do
c
C
	DO I=1,N,N1
	DO J=1,M
	kk2=(i-1)*nz+j
	k=k+1
c   calculations ---
	fpl=tpl*fp(r0,x(i),z0,y(j))
	pspl(kk2)=fpl/(2.*pi)

	p_min=dmin1(p_min,pspl(kk2))
	p_max=dmax1(p_max,pspl(kk2))
c
	END DO
	END DO

	if(kpr.eq.1)print *,' ** p_min p_max',p_min,p_max
C
C END PLASMA BOUNDARY
c
	DO I=1,N
	DO J=1,M
	kk=(i-1)*nz+j
	work(kk)=-work(kk)*X(I)
	U(kk)=PSPL(kk)
	END DO
	END DO
c++++++++++++++++++++++++++++++++++++++++++++++
	DO I=1,N
	DO J=1,M,M1
	kk=(i-1)*nz+j
	sib(kk)=-pspl(kk)
	end do
	end do
c
	DO I=1,N,N1
	DO J=1,M
	kk=(i-1)*nz+j
	sib(kk)=-pspl(kk)
	end do
	end do
c
	do i=2,nr-1
	do j=2,nz-1
	kk=(i-1)*nz+j
	sib(kk)=0.5*work(kk)*delz**2
	end do
	end do
c--
	call buneto(sib,nr,nz,work,nwnh)
C
	p_min=1.e10
	p_max=-1.e10

	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	u(kk)=-sib(kk)
	end do
	end do
	DO I=2,N1
	DO J=2,M1
	kk=(i-1)*nz+j
	pspl(kk)=u(kk)
	p_min=dmin1(p_min,pspl(kk))
	p_max=dmax1(p_max,pspl(kk))
	END DO
	END DO

	if(kpr.eq.1)print *,' ** p_min p_max',p_min,p_max
c
	p_min=1.e10
	p_max=-1.e10

	p_mi=1.e10
	p_ma=-1.e10

	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	PSEXT0=0.
	DO K=1,NPF
	psext0=psext0+PF(K)*FLUXARR(kk,K)
!	if(kpr.eq.1)print *,'kk k  pf FLUXARR ',kk,k,pf(k),FLUXARR(kk,K)
	END DO


	pscam=0.
	DO K=1,ncam
	pscam=pscam+tcam(K)*vesarr(kk,K)
	END DO
	psext0=psext0+pscam


	psext(kk)=psext0*api
	p_mi=dmin1(p_mi,psext(kk))
	p_ma=dmax1(p_ma,psext(kk))



	psi(i,j)=pspl(kk)+psext(kk)
	
c	print *,' kk psi pspl psext',kk,psi(i,j),pspl(kk),psext(kk)
	psi_g(i,j)=psi(i,j)
	pspl0(kk)=psi(i,j)
	p_min=dmin1(p_min,psi(i,j))
	p_max=dmax1(p_max,psi(i,j))
	end do
	end do

	if(kpr.eq.1)print *,' p_min p_max',p_min,p_max
c  	call print2(' p_min p_max==',p_min,p_max)
	if(kpr.eq.1)print *,' p_mi p_ma',p_mi,p_ma
c  	call print2('p_mi p_ma==',p_mi,p_ma)

!      stop

	return
	end




c


	subroutine ptoke0_old()
	include 'double.inc'
c	implicit real *8 (a-h,o-z)                                            
c                                                                       
	include 'parf0'                                                        
	include 'parf1'                                                        
	include 'parf2'                                                        
	include 'parf2e'                                                       
c                                                                       
	common                                                                 
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nn),y(MM),dx,dy                    
     *  /eq1g/psi_g(nr,nz)                                              
     *  /eq1e/psext(nwnh),re(nre),ze(nze),dr,dz                         
     *  /eq3/FLUXARR(nwnh,kf)                                           
     *  /eq12/omega,pspl0(nwnh)                                         
c                                                                       
	common                                                                 
     *  /pf1/npf,pf(kf),pf0(kf)                                         
	common                                                                 
     *  /ge1/pi                                                         
     *	/ge1e/rs0,tpl                                                    
     *  /ge5/kpr                                                        
     *  /ge7/eu,rout,zout,elong                                         
c                                                                       
	common                                                                 
     *	/point1/r0,z0                                                    
c                                                                       
	common                                                                 
     *	/bunemn/nww,nhh,drdz2,rgrid1,delr,delz                           
                                                                        
	common                                                                 
     *	/fluxc3/u(nwnh),work(nwnh),sib(nwnh)                             
c++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
	nww=nr-1                                                               
	nhh=nz-1                                                               
	rgrid1=x(1)                                                            
	delr=dx                                                                
	delz=dy                                                                
	drdz2=(delr/delz)**2                                                   
c++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
	n=nn                                                                   
	m=mm                                                                   
	n1=n-1                                                                 
	m1=m-1                                                                 
c                                                                       
	curd=tpl/(pi*eu**2)                                                    
c_________________________________________________                      
	COEF=10./(4.*PI)                                                       
	api=1./(2.*pi)                                                         
                                                                        
	if(kpr.eq.1)print *,'r0= ',r0,'  z0',z0, ' eu',eu                     
	tok=0.                                                                 
c                                                                       
	dist_min=1.e5                                                          
	DO I=2,N1                                                              
	DO J=2,M1                                                              
	kk=(i-1)*nz+j                                                          
	work(kk)=0.                                                            
	dist=sqrt( (x(i)-r0)**2+(y(j)-z0)**2)                                  
	if(dist.le.dist_min )dist_min=dist                                     
	if(dist.gt.eu )go to 9                                                 
	work(kk)=curd                                                          
	TOK=TOK+work(kk)                                                       
9	CONTINUE                                                              
	END DO                                                                 
	END DO                                                                 
74	format (20i2)                                                        
C                                                                       
	TOK=TOK*COEF*dx*dy                                                     
C                                                                       
	if(kpr.eq.1)print *,'TOK tpl dist_min= ',TOK,tpl,dist_min             
C                                                                       
c                                                                       
	 al1=tpl/tok                                                           
                                                                        
	 do i=1,n                                                              
	 do j=1,m                                                              
 	 kk=(i-1)*nz+j                                                        
	 work(kk)=work(kk)*al1                                                 
	 end do                                                                
	 end do                                                                
C   CALCULATE BOUNDARY PSIPL                                            
C                                                                       
	p_min=1.e10                                                            
	p_max=-1.e10                                                           
                                                                        
	k=0                                                                    
	DO I=1,N                                                               
	DO J=1,M,M1                                                            
	k=k+1                                                                  
	kk2=(i-1)*nz+j                                                         
c   calculations ---                                                    
	fpl=tpl*fp(r0,x(i),z0,y(j))                                            
	pspl(kk2)=fpl/(2.*pi)                                                  
                                                                        
	p_min=dmin1(p_min,pspl(kk2))                                           
	p_max=dmax1(p_max,pspl(kk2))                                           
                                                                        
	end do                                                                 
	end do                                                                 
c                                                                       
C                                                                       
	DO I=1,N,N1                                                            
	DO J=1,M                                                               
	kk2=(i-1)*nz+j                                                         
	k=k+1                                                                  
c   calculations ---                                                    
	fpl=tpl*fp(r0,x(i),z0,y(j))                                            
	pspl(kk2)=fpl/(2.*pi)                                                  
                                                                        
	p_min=dmin1(p_min,pspl(kk2))                                           
	p_max=dmax1(p_max,pspl(kk2))                                           
c                                                                       
	END DO                                                                 
	END DO                                                                 
                                                                        
	if(kpr.eq.1)print *,' ** p_min p_max',p_min,p_max                     
C                                                                       
C END PLASMA BOUNDARY                                                   
c                                                                       
	DO I=1,N                                                               
	DO J=1,M                                                               
	kk=(i-1)*nz+j                                                          
	work(kk)=-work(kk)*X(I)                                                
	U(kk)=PSPL(kk)                                                         
	END DO                                                                 
	END DO                                                                 
c++++++++++++++++++++++++++++++++++++++++++++++                         
	DO I=1,N                                                               
	DO J=1,M,M1                                                            
	kk=(i-1)*nz+j                                                          
	sib(kk)=-pspl(kk)                                                      
	end do                                                                 
	end do                                                                 
c                                                                       
	DO I=1,N,N1                                                            
	DO J=1,M                                                               
	kk=(i-1)*nz+j                                                          
	sib(kk)=-pspl(kk)                                                      
	end do                                                                 
	end do                                                                 
c                                                                       
	do i=2,nr-1                                                            
	do j=2,nz-1                                                            
	kk=(i-1)*nz+j                                                          
	sib(kk)=0.5*work(kk)*delz**2                                           
	end do                                                                 
	end do                                                                 
c--                                                                     
	call buneto(sib,nr,nz,work,nwnh)                                       
C                                                                       
	p_min=1.e10                                                            
	p_max=-1.e10                                                           
                                                                        
	do i=1,nr                                                              
	do j=1,nz                                                              
	kk=(i-1)*nz+j                                                          
	u(kk)=-sib(kk)                                                         
	end do                                                                 
	end do                                                                 
	DO I=2,N1                                                              
	DO J=2,M1                                                              
	kk=(i-1)*nz+j                                                          
	pspl(kk)=u(kk)                                                         
	p_min=dmin1(p_min,pspl(kk))                                            
	p_max=dmax1(p_max,pspl(kk))                                            
	END DO                                                                 
	END DO                                                                 
                                                                        
	if(kpr.eq.1)print *,' ** p_min p_max',p_min,p_max                     
c                                                                       
	p_min=1.e10                                                            
	p_max=-1.e10                                                           
                                                                        
	p_mi=1.e10                                                             
	p_ma=-1.e10                                                            
                                                                        
	do i=1,nr                                                              
	do j=1,nz                                                              
	kk=(i-1)*nz+j                                                          
	PSEXT0=0.                                                              
	DO K=1,NPF                                                             
	psext0=psext0+PF(K)*FLUXARR(kk,K)                                      
	END DO                                                                 
	psext(kk)=psext0*api                                                   
	p_mi=dmin1(p_mi,psext(kk))                                             
	p_ma=dmax1(p_ma,psext(kk))                                             
	psi(i,j)=pspl(kk)+psext(kk)                                            
	psi_g(i,j)=psi(i,j)                                                    
	pspl0(kk)=psi(i,j)                                                     
	p_min=dmin1(p_min,psi(i,j))                                            
	p_max=dmax1(p_max,psi(i,j))                                            
	end do                                                                 
	end do                                                                 
	if(kpr.eq.1)print *,' p_min p_max',p_min,p_max                        
	if(kpr.eq.1)print *,' p_mi p_ma',p_mi,p_ma                            
	return                                                                 
	end                                                                    
                                                                        
                                                                        
                                                                        
                                                                        
c                                                                       
                                                                        
                                                                        
                                                                        
                                                                        
                                                                        
  
