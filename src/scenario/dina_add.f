
	subroutine power_ech_read()
		include 'double.inc'
	include 'new_com.inc'

	call power_ech_read_c(
     *  tt,power_ech,ntay,tay)
	
	return
	end

	subroutine power_ech_read_c(
     *  tt,power_ech,ntay,tay)
    	include 'double.inc'
 	include 'parf_mike' 

	dimension t_t(ntime),power_ech_t(ntime)


	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='power_ech.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 
           read (41,*) 

 	 print *,' power_ech tay tt n_t===',power_ech,tay,tt,n_t 

           do i=1,n_t 
              read (41,*)t_t(i),power_ech_t(i)
              t_t(i)=t_t(i)*1000. 
           end do 
           
           apr='-t_t-' 
           print 71,apr,(t_t(i),i=1,n_t) 

           apr='-power_ech_t-' 
           print 71,apr,(power_ech_t(i),i=1,n_t) 

           close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 power_ech=power_ech_t(i-1)+t_coef*(power_ech_t(i)-
     *  power_ech_t(i-1))
c
	 end if

	 end do

	print *,' from power_ech_read  power_ech ntay',power_ech,ntay

       return 
       end 

        subroutine ip_ech()
        	include 'double.inc'
	include 'new_com.inc'

        call ip_ech_c(n,
     *  aj0_ech,sb_ech,ai,power_ech,tt,pne,tpl_ech,
     *  te0,spo,vi,ha,rs0,pi,a_m,yr0,gam_eccd)

	return
	end

        subroutine ip_ech_c(n,
     *  aj0_ech,sb_ech,ai,power_ech,tt,pne,tpl_ech,
     *  te0,spo,vi,ha,rs0,pi,a_m,yr0,gam_eccd)
    	include 'double.inc'
	dimension aj0_ech(*),sb_ech(*),ai(*),pne(*),te0(*),
     *  spo(*),vi(*),ha(*),a_m(*)

	character *20 apr

c  Modified for DINA by Khayrutdinov--------------

C-----------------------------------------Polevoy 27-JUL-99

C	ECR Heating for ITER by Zvonkov (Programmed by Polevoy)

C	YR0 	distance from plasma centre [m]

C	YDR	half width [m]	~0.085 for edge 140GHz IAM 

C		(0.25 for central 170GHz IAM)

C	YQ	ECH Power [MW]

C	YP(r)	ECR power density [MW/m3] ~ Q*exp(-((r-r0)/Dr)**2)

C	YC(r)	ECR current density [MA/m2]

C	YEFF	ECR current drive efficiency [A/W]

c YQ[MW], YP[MW/m3], YC[MA/m2] 
c TE[keV], ne[19], AMETR[m]



c*** Input of yr0 is in vic_yr0_read subroutine in time 
c	i_en=i_en+1
c	if(i_en.eq.1)then

c	 open (unit=41,file='ech.dat',form='formatted')
c	 read (41,*)
c	 read (41,*)yr0,tt_uv


c         print *,'yr0 tt_uv',yr0,tt_uv

c	end if

c	if(tt.le.tt_uv)return


	yq=power_ech

	JRES=1

	NA1=n-1

 	DO  J=2,NA1

	J1=J-1

	IF((a_m(J)-YR0)*(a_m(J1)-YR0).LE.0.) JRES=J

	end do

	IF(JRES.GE.NA1) JRES=N

	te_res=TE0(JRES)*1.e-3
	pne_res=pne(JRES)

c        print *,' == te_res pne_res yq na1 ===',te_res,pne_res,yq,na1

c### 	YEFF	=.042*TE_RES/50.*10./PNE_RES*YQ

c OLD 	YEFF	=.042*TE_RES/50.*10./PNE_RES

 	YEFF	=gam_eccd*TE_RES/50.*10./PNE_RES

	YDR	=

     *  (4.95+37.6*EXP(-TE_RES/10.2)+10.76/PNE_RES)/100.

c--- in cm---
	ydr=ydr*100.

c        print *,' == jres yr0 yeff ydr ===',jres,yr0,yeff,ydr

	yp_v=0.
	yp_s=0.

	apr='a_m='
c	print 71,apr,(a_m(i),i=1,n)

	DO  J	=1,NA1

c!!!!	YP(J)=exp(-((a_m(J)-YR0)/YDR)**2)

	sb_ech(J)=exp(-((a_m(J)-YR0)/YDR)**2)

	yp_v=yp_v+sb_ech(j)*2.*pi*vi(j)*ha(j)

	yp_s=yp_s+sb_ech(j)*spo(j)*ha(j)

c	print *,' j sb_ech yp_v yp_s',j,sb_ech(j),yp_v,yp_s

	end do

c-----------------------------

c        print *,' == yp_v yp_s pi  rs0 ===',yp_v,yp_s,pi,rs0

	tok_ech=0.
	do i=2,n
	   aj0_ech(i)=sb_ech(i)*yeff/yp_s*yq*1.e3
	   sb_ech(i)=sb_ech(i)/yp_v*yq
	   tok_ech=tok_ech+aj0_ech(i)*spo(i)*ha(i)
	end do

	apr='aj0_ech='
c	print 71,apr,(aj0_ech(i),i=1,n)

	p_ech=0.
	do i=2,n
	p_ech=p_ech+sb_ech(i)*2.*pi*vi(i)*ha(i)
	end do

	PNOR=6.25E8


	do i=2,n
	sb_ech(i)=sb_ech(i)*pnor
	end do

	apr='sb_ech='
c	print 71,apr,(sb_ech(i),i=1,n)

71	FORMAT(5X,A10/,(2x,6(1PE11.3)))

c        print *,' == power_ech tok_ech===',p_ech,tok_ech

	tpl_ech=tok_ech

c	stop

	return
	end
	subroutine bound_h2()                                                  
    	include 'double.inc'                                                                        
	include 'new_com.inc'                                                  
                                                                        
	call bound_h2_c(                                                       
     *  mp,del_r,eu,eu_u,um,vm,uk,vk,kpr)                               
	                                                                       
	return                                                                 
	end                                                                    
                                                                        
                                                                        
	subroutine bound_h2_c(                                                 
     *  mp,del_r,eu,eu_u,um,vm,uk,vk,kpr)                               
    	include 'double.inc'                                                                        
        dimension uk(*),vk(*)                                           
                                                                        
                                                                        
      SP=0.                                                             
      DO 710 J=2,mp-1                                                   
      SP=SP+UK(J)*(VK(J+1)-VK(J-1))                                     
  710 CONTINUE                                                          
      SP=SP*0.5                                                         
      sp_pl=sp                                                          
                                                                        
c!!!	al1=1.+del_r/eu                                                    
	al1=1.+del_r/sqrt(sp_pl)                                               
                                                                        
	do j=1,mp                                                              
	d_u=(uk(j)-um)                                                         
	d_v=(vk(j)-vm)                                                         
	uk(j)=um+al1*d_u                                                       
	vk(j)=vm+al1*d_v                                                       
	end do                                                                 
                                                                        
	rmax_u=-10000.                                                         
	rmin_u=10000.                                                          
                                                                        
      DO J=2,mp-1                                                       
	rmax_u=dmax1(rmax_u,uk(j))                                             
	rmin_u=dmax1(rmin_u,uk(j))                                             
  	end do                                                               
                                                                        
	eu_u=0.5*(rmax_u-rmin_u)                                               
                                                                        
D	if(kpr.eq.1)print *,' --eu eu_u-sp_pl ',eu,eu_u,sp_pl                 
	return                                                                 
	end                                                                    
	subroutine delr_filter()  
		include 'double.inc'
	include 'new_com.inc'                                                  
                                                                        
	call delr_filter_c(                                                    
     *  del_r,ntay,tay,tt,kpr)                                          
                                                                        
	return                                                                 
	end                                                                    
                                                                        
	subroutine delr_filter_c(                                              
     *  del_r,ntay,tay,tt,kpr)                                          
    	include 'double.inc'                                                                        
c	print *,' tt tay del_r----',tt,tay,del_r                              
                                                                        
	if(time.lt.tt-0.5*tay)then                                             
c  saving for the next time_step...                                     
	e1 = f9a                                                               
	v1 = f9af                                                              
	time1 = time                                                           
	end if                                                                 
                                                                        
                                                                        
	time=tt                                                                
                                                                        
	f9a=del_r                                                              
                                                                        
        i_en=i_en+1                                                     
	if(i_en.eq.1)then                                                      
           e1 = f9a                                                     
           f9af=e1                                                      
           v1 = f9af                                                    
           time1 = time                                                 
        end if                                                          
                                                                        
c	qqp = 0.5 * 5.0e-5 * (time - time1)*1.e3                              
                                                                        
c!!!	qqp = 0.5 * 5.0e-2 * (time - time1)                                
c    ;  /* 1/taup = 1/20.0e3 = 5.0e-5 */                                
c	qqp = 0.5 * 5.0e-2 * (time - time1)                                   
                                                                        
c    ;  /* 1/taup = 1/20.0 = 5.0e-2 */                                  
c    ;  /* 1/taup = 1/0.5 = 2. */                                       
                                                                        
	taup=5.*tay                                                            
                                                                        
	qqp = 0.5 * (time - time1)/taup                                        
                                                                        
c    ;  /* 1/taup = 1/1. = 1. */                                        
                                                                        
	f9af =(qqp * (f9a + e1) - (qqp - 1.0) * v1) / (qqp + 1.0)              
                                                                        
c	print *,' qqp e1 v1 ----',qqp,e1,v1                                   
c	print *,'   f9a f9af----',f9a,f9af                                    
                                                                        
	del_r=f9af                                                             
                                                                        
                                                                        
	return                                                                 
	end                                                                    
	subroutine fmax_filter()  
		include 'double.inc'
	include 'new_com.inc'                                                  
                                                                        
	call fmax_filter_c(                                                    
     *  fmax,ntay,tay,tt,kpr)                                           
                                                                        
	return                                                                 
	end                                                                    
                                                                        
	subroutine fmax_filter_c(                                              
     *  fmax,ntay,tay,tt,kpr)                                           
    	include 'double.inc'                                                                        
D	if(kpr.eq.1)print *,' tt tay fmax----',tt,tay,fmax                    
                                                                        
	if(time.lt.tt-0.5*tay)then                                             
c  saving for the next time_step...                                     
	e1 = f9a                                                               
	v1 = f9af                                                              
	time1 = time                                                           
	end if                                                                 
                                                                        
                                                                        
	time=tt                                                                
                                                                        
	f9a=fmax                                                               
                                                                        
        i_en=i_en+1                                                     
	if(i_en.eq.1)then                                                      
           e1 = f9a                                                     
           f9af=e1                                                      
           v1 = f9af                                                    
           time1 = time                                                 
        end if                                                          
                                                                        
c	qqp = 0.5 * 5.0e-5 * (time - time1)*1.e3                              
                                                                        
c!!!	qqp = 0.5 * 5.0e-2 * (time - time1)                                
c    ;  /* 1/taup = 1/20.0e3 = 5.0e-5 */                                
c	qqp = 0.5 * 5.0e-2 * (time - time1)                                   
                                                                        
c    ;  /* 1/taup = 1/20.0 = 5.0e-2 */                                  
c    ;  /* 1/taup = 1/0.5 = 2. */                                       
                                                                        
	taup=20.*tay                                                           
                                                                        
	qqp = 0.5 * (time - time1)/taup                                        
                                                                        
c    ;  /* 1/taup = 1/1. = 1. */                                        
                                                                        
	f9af =(qqp * (f9a + e1) - (qqp - 1.0) * v1) / (qqp + 1.0)              
                                                                        
c	print *,' qqp e1 v1 ----',qqp,e1,v1                                   
c	print *,'   f9a f9af----',f9a,f9af                                    
                                                                        
	fmax=f9af                                                              
                                                                        
                                                                        
	return                                                                 
	end                                                                    
                                                                        
c************************************************
	subroutine pcchp_filter() 
		include 'double.inc'
	include 'new_com.inc'                                                  
                                                                        
	call pcchp_filter_c(                                                    
     *  pcchp,ntay,tay,tt,kpr)                                           
                                                                        
	return                                                                 
	end                                                                    
                                                                        
	subroutine pcchp_filter_c(                                              
     *  pcchp,ntay,tay,tt,kpr)                                           
    	include 'double.inc'                                                                        
D	if(kpr.eq.1)print *,' tt tay fmax----',tt,tay,fmax                    
                                                                        
	if(time.lt.tt-0.5*tay)then                                             
c  saving for the next time_step...                                     
	e1 = f9a                                                               
	v1 = f9af                                                              
	time1 = time                                                           
	end if                                                                 
                                                                        
                                                                        
	time=tt                                                                
                                                                        
	f9a=pcchp                                                               
                                                                        
        i_en=i_en+1                                                     
	if(i_en.eq.1)then                                                      
           e1 = f9a                                                     
           f9af=e1                                                      
           v1 = f9af                                                    
           time1 = time                                                 
        end if                                                          
                                                                        
c	qqp = 0.5 * 5.0e-5 * (time - time1)*1.e3                              
                                                                        
c!!!	qqp = 0.5 * 5.0e-2 * (time - time1)                                
c    ;  /* 1/taup = 1/20.0e3 = 5.0e-5 */                                
c	qqp = 0.5 * 5.0e-2 * (time - time1)                                   
                                                                        
c    ;  /* 1/taup = 1/20.0 = 5.0e-2 */                                  
c    ;  /* 1/taup = 1/0.5 = 2. */                                       
                                                                        
	taup=20.*tay                                                           
                                                                        
	qqp = 0.5 * (time - time1)/taup                                        
                                                                        
c    ;  /* 1/taup = 1/1. = 1. */                                        
                                                                        
	f9af =(qqp * (f9a + e1) - (qqp - 1.0) * v1) / (qqp + 1.0)              
                                                                        
c	print *,' qqp e1 v1 ----',qqp,e1,v1                                   
c	print *,'   f9a f9af----',f9a,f9af                                    
                                                                        
	pcchp=f9af                                                              
                                                                        
                                                                        
	return                                                                 
	end                                                                    
                                                                        
c************************************************
	subroutine vic_yr0_read()
    	include 'double.inc'
      include 'new_com.inc'
      
      call vic_yr0_read_c(
     *     tt,yr0)
      
      return
      end
      

      subroutine vic_yr0_read_c(
     *     tt,yr0)

    	include 'double.inc'
 	include 'parf_mike' 

	dimension t_t(ntime),yr0_t(ntime)

	character *12 apr
	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='yr0_ech.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 
           read (41,*) 

 	 print *,' yr0 tt n_t===',yr0,tt,n_t 

           do i=1,n_t 
              read (41,*)t_t(i),yr0_t(i)
              t_t(i)=t_t(i)*1000. 
           end do 
           
           apr='-t_t-' 
           print 71,apr,(t_t(i),i=1,n_t) 

           apr='-yr0_t-' 
           print 71,apr,(yr0_t(i),i=1,n_t) 

           close (unit=41) 
        end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 yr0=yr0_t(i-1)+t_coef*(yr0_t(i)-yr0_t(i-1))
c
	 end if

	 end do

	print *,' from vic_yr0_read  yr0 ntay',yr0,ntay

       return 
       end 

c---------------------------------------------------------------
c---------------------------------------------------------------
	subroutine yr0_calc()
		include 'double.inc'
c	implicit real*8(a-h,o-z)
	include 'new_com.inc'

	call yr0_calc_c(
     *  tetq,n,m,um,vm,xpl,ypl,npo,pi,r_eccd,z_eccd,i_eccd)
	return
	end

	subroutine yr0_calc_c(
     *  tet,n,m,um,vm,xpl,ypl,npo,pi,r_eccd,z_eccd,i_eccd)
     	include 'double.inc'
c	implicit real*8(a-h,o-z)

	dimension tet(*),xpl(npo,*),ypl(npo,*)

	character * 20 apr
71 	FORMAT(20X,A6/,(6(1pE10.3)))
c-------------------------------------

	r=r_eccd
	z=z_eccd

c	print *,' n m ',n,m

c	print *,' um vm',um,vm

c	print *,' R Z',r,z
c
	tet(1)=tet(2)-tet(3)

	apr='tet'
c	print 71,apr,(tet(i),i=1,m)
c
	i=0
	ro_p=sqrt((R-um)**2+(Z-vm)**2)
	cos1=(R-um)/ro_p
	sin1=(Z-vm)/ro_p
	alfa1=acos(cos1)
	if(sin1.lt.0.)alfa1=2.*pi-alfa1

	i_p=0
	j_p=0

	do  j=2,m
	   if( (alfa1-tet(j) )*(alfa1-tet(j-1) ).le.0.) then
	      do i=2,n

		 dist1=sqrt((xpl(i-1,j)-um)**2+(ypl(i-1,j)-vm)**2)
		 dist2=sqrt((xpl(i,j)-um)**2+(ypl(i,j)-vm)**2)

		 if( (ro_p-dist2 )*(ro_p-dist1 ).le.0.) then
		    i_p=i
		    j_p=j
		    dist_1=dist1
		    dist_2=dist2
		 end if
	      end do
	   end if
	end do

c	print *,' i_p j_p alfa1',i_p,j_p,alfa1

	i_eccd=i_p

c--------------------
c	print *,' i_eccd ro_p dist_1 dist_2',i_eccd,ro_p,dist_1,dist_2
c--------------------

	apr='pom'
c	print 71,apr,(pom(i),i=1,m)
c	print *,' pausa'
c	read (*,*)
c
	return
	end

	subroutine tem_con_d()
    	include 'double.inc'
	include 'parf0'                                                        
	common                                                                 
     *	/n_m/n,m,mp                                                      
        common                                                          
     *  /keys4/k_ener,k_uv                                              

	common                                                                 
     *  /en1e/te_a,ti_a,te_b,ti_b,pw_e                                  
     *  /en2/TE0(npo),TQ0(npo),TEN(npo),TQN(npo),WE0(npo),              
     *  WQ0(npo)                                                        
	common                                                                 
     *  /ge3/AI(npo),A0(npo),HA2(npo),a(npo),ha(npo)                     
                                                                         
	dimension a_print(100)

	character *20 apr                                                      
c--------------------------------------------------------               
                                                                        
      if(k_ener.eq.1)return                                           
                                                                        
	do i=2,n-1                                                               
	psix=a(i)                                                             
	te0(i)=te_b+(1.d0-psix**pw_e)*(te_a-te_b)                                
 	end do 

	te0(1)=te_a
	te0(n)=te_b

	do i=1,n                                                              
	tq0(i)=te0(i)                               
 	end do 

	a_print(1)=te_a
	a_print(2)=te_b

	n_pr=2

	apr='-te_a-te_b'
	num=20
c	call out42(n_pr,a_print,num,apr)
c
c#$	print *,' n te_a t_b==',n,te_a,te_b

	apr='** te0-'
c	print 71,apr,(te0(i),i=1,n)

                                                                        
71	FORMAT(5X,A10/,(2x,6(1PE11.3)))                                      
	return                                                                 
	end                                                                    
        subroutine q_calc()
        	include 'double.inc'
c
        include 'parf0'
        include 'parf2'
	common
     *  /ge1/pi
     *	/ge1e/rs0,tpl
	common
     *	/n_m/n,m,mp
	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nr),y(nz),dx,dy
	common
     *	/fluxc1/xp1(50,mu1),yp1(50,mu1)
     *  /fluxc2/delta0,pom(ntet)
     *  /fluxc4/mcurve,x11(mu1),y11(mu1)
        common
     *  /eq11/psval(npo),psval0(npo)
        common
     *  /pol6/ppx(npo),pffx(npo)
        common
     *  /dfm7/bt0,uind
        common
     *  /graf2/q_99
	common
     *  /halo5/q_vde,q_95,del_f,i_halo

        dimension ind1(50),f8(npo),dhal(mu1),dint2(mu1),q8(npo)

	dimension pdd(6)

	dimension a_print(100)

	character *20 apr

        nrad=n

        f8(nrad)=bt0

	fsqrt0=f8(nrad)**2
	i=nrad
	a_print(i)=f8(i)
	ps_1=0.5*(psval(i)+psval(i-1))
	nrad1=nrad-1
	do i0=2,nrad1
	i=nrad1-i0+2
	fprime=-pffx(i)
	ps_0=ps_1
	ps_1=0.5*(psval(i)+psval(i-1))
	psi_i=ps_0-ps_1
	fsqrt=fsqrt0-fprime*psi_i/rs0
	fsqrt0=fsqrt
	f8(i)=sqrt(fsqrt)
	a_print(i)=f8(i)
	end do

	n_pr=nrad

	apr='--f8--'
	num=20
c	call out42(n_pr,a_print,num,apr)

        apr= 'f8 '
c        print 71,apr,(f8(i),i=2,nrad)

71	format(20x,a6/,(6(1pe10.3)))
c----------------------------


        do ii=1,2

c        do ii=1,nrad

        aval=psval(ii)

        if(ii.eq.1)aval=psval(1)-0.95*(psval(1)-psval(n))
        if(ii.eq.2)aval=psval(1)-0.99*(psval(1)-psval(n))

        call feet_p(nrad,f8,f8_i,psval,aval)
c        print *,' ii f8_i',ii,f8_i
c
	do i0=1,5
	ind1(i0)=0
	end do
c
	dcur=1.e-11*(abs(aval)+1.)
	call fluxcont(nn,mm,PSI,aval,x,y,xp1,yp1,num,ind1,delta0,dcur)
c
	i=1
	mcurve=ind1(i)
        DO  J=1,mcurve
           x11(J)=xp1(i,j)
           y11(J)=yp1(i,j)
        end do
	k=0
        do j=1,mcurve
c
	k=k+1
        urr=x11(j)
        vrr=y11(j)

        if(j.gt.1)dhal(j)=sqrt( (x11(j)-x11(j-1))**2+(y11(j)-
     *  y11(j-1))**2 )

	call boxd(urr,vrr,pdd,ier)
	gradpsi=sqrt( pdd(2)**2+pdd(3)**2 )
	psi_r=pdd(2)
	psi_z=pdd(3)
c
	dint0=1./(2.*pi*urr)
	dint2(j)=dint0/gradpsi
c
	end do

	c3_i=0.
        do j=2,mcurve
        c3_i=c3_i+0.5*(dint2(j)+dint2(j-1))*dhal(j)
	end do

        pfi=rs0*c3_i*f8_i
	q_i=pfi
        q8(ii)=q_i

c        print *,' x11 1 mcurve===',x11(1),x11(mcurve)
c        print *,' y11 1 mcurve===',y11(1),y11(mcurve)
c	print *,' q_i===',q_i

        if(ii.eq.1)q_95=q_i
        if(ii.eq.2)q_99=q_i

        end do

!	print *,' q_95 q_99===',q_95,q_99


c        apr= 'q8 '
c        print 71,apr,(q8(i),i=nrad-5,nrad)

c        do i=6,nrad
c           q8(i)=0.5*(q8(i)+q8(i-1))
c        end do

c        apr= 'q8 '
c        print 71,apr,(q8(i),i=2,nrad)
c
	return
	end

	subroutine tcam_r()
    	include 'double.inc'
	include 'new_com.inc'

	call tcam_r_c(
     *  tt,ncam,tcam)

	
	return
	end

	subroutine tcam_r_c(
     *  tt,ncam,tcam)
    	include 'double.inc'
        dimension tcam(*)

     	open(unit=41,file='tcam_out.dat',form='formatted')
	read(41,*)
	read (41,*)tt,ncam
c
	read (41,*)(tcam(i),i=1,ncam)
5000    format (6(1pe14.6))

	close(41)
	tokc=0.
	do i=1,ncam
	   tokc=tokc+tcam(i)
	end do
	print *,'tt ncam tokc===',tt,ncam,tokc

	



	if(tt.lt.0.)then
	   do i=1,ncam
	      tcam(i)=0.
	   end do
	   tt=-tt
	end if




	return
	end

        subroutine ip_ech_1()
        	include 'double.inc'
	include 'new_com.inc'

        call ip_ech_1_c(n,
     *  aj0_ech1,sb_ech1,ai,power_ech1,tt,pne,tpl_ech1,
     *  te0,spo,vi,ha,rs0,pi,tpl_cd,p_e1,kpr)

	return
	end

        subroutine ip_ech_1_c(n,
     *  aj0_ech1,sb_ech1,ai,power_ech1,tt,pne,tpl_ech1,
     *  te0,spo,vi,ha,rs0,pi,tpl_cd,p_e1,kpr)
    	include 'double.inc'
	dimension aj0_ech1(*),sb_ech1(*),ai(*),pne(*),te0(*),
     *  spo(*),vi(*),ha(*)

	character *20 apr

	i_en=i_en+1
	if(i_en.eq.-1)then

	 open (unit=41,file='eff_x2.dat',form='formatted')
	 read (41,*)
	 read (41,*)alfa_ech1

	close (41)


        if(kpr.eq.1)print *,'alfa_ech1',alfa_ech1

	end if

	if(p_e1.le.1.e-5)return
	if(abs(tpl_ech1).le.1.e-5)return

	PNOR=6.25E8

	yp_v=0.

	yp_s=0.

	do i=2,n

	yp_v=yp_v+sb_ech1(i)*2.*pi*vi(i)*ha(i)

	yp_s=yp_s+sb_ech1(i)*spo(i)*ha(i)

	end do

c-----------------------------


	alfa_ech1=1.e15
	yeff=alfa_ech1*1.e-19

        if(kpr.eq.1)print *,' == yp_v  yeff rs0 ===',yp_v,yeff,rs0
c--------------

 	tok_ech=0.

	do i=2,n

	   aj0_ech1(i)=0.1*(sb_ech1(i)*1.e6)*yeff*te0(i)/pne(i)
c TCV definition 
	   aj0_ech1(i)=aj0_ech1(i)*yp_v/yp_s*1.e-2

	   aj0_ech1(i)=aj0_ech1(i)/pnor

	   tok_ech=tok_ech+aj0_ech1(i)*spo(i)*ha(i)
	end do

c********************

	al1=tpl_ech1/tok_ech
	tok_ech1=tok_ech

 	tok_ech=0.
	do i=2,n
	   aj0_ech1(i)=aj0_ech1(i)*al1
	   tok_ech=tok_ech+aj0_ech1(i)*spo(i)*ha(i)
	end do

	if(kpr.eq.1)print*,' tpl_ech1 tok_ech tok_ech1',
     *  tpl_ech1,tok_ech,tok_ech1

c********************

	apr='aj0_ech1='
c	print 71,apr,(aj0_ech1(i),i=1,n)

71	FORMAT(5X,A10/,(2x,6(1PE11.3)))


	return
	end


