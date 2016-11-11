	subroutine dina_0(time_8,tt_8,tay_8,key_mat,vec_mat,
     *	p_input_1,p_input_2,p_input_3,
     *	output_1,output_2,output_3,output_4,ng)


	include 'double.inc'
!	include 'new_com.inc'

      common
     *  /ge5/kpr

	real *8 time_8, tay_8
	real *8 tt_8 

	real *8 vec_mat(*)
		
	dimension key_mat(*) 

	real *8 p_input_1(*),p_input_2(*),p_input_3(*)

	real *8 output_1(*)
	real *8 output_2(*)
	real *8 output_3(*)
	real *8 output_4(*)


	real *8 a_print(200)
	
      parameter (kint=500)
      
      dimension c_input1(kint),c_input2(kint)
      dimension c_output1(kint),c_output2(kint),c_output3(kint)

	character *25 apr


c =================================================================

c	print *,' ok1 '

c =================================================================

	i_en0=i_en0+1    

      ng=i_en0

!      kpr=key_mat(4)

 !     kpr=0

      if(kpr.eq.1)print *,' kpr===',kpr
      

      do i=1,6
!	a_print(i)=key_mat(i)
      end do
      
	n_pr=6
	apr='  key'
	num=6
!	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)
                                                                        


      n_input1=2
      do i=1,n_input1
          c_input1(i)=p_input_1(i)
      end do

      do i=1,n_input1
!	a_print(i)=c_input1(i)
      end do
      
	n_pr=n_input1
	apr='  c_input1'
	num=10
!	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

!      n_input2=15
      n_input2=38
      
     
      do i=1,n_input2
        c_input2(i)=p_input_2(i)
      end do

      do i=1,n_input2
!	a_print(i)=c_input2(i)
      end do
      
	n_pr=n_input2
	apr='  c_input2'
	num=10
!	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


  !      c_input1(1)=tpl

 !       goto 5

      n_output3=32

      do i=1,n_output3
!	a_print(i)=c_output3(i)
      end do
      
	n_pr=n_output3
	apr='  output3'
	num=10
!	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)



	  call dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3)

c ============ outputs ==============================================


5     continue


      n_output1=15
      do i=1,n_output1
		output_1(i)=c_output1(i)
        end do

      do i=1,n_output1
!	a_print(i)=output_1(i)
      end do
      
	n_pr=n_output1
	apr='  output1'
	num=10
!	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

      npf=15
      n_gaps=6
      ncam=100
      
      n_output2=n_gaps+npf+ncam
      
      n_output3=32
      
	a_print(1)=n_gaps
	a_print(2)=npf
	a_print(3)=ncam
      
	n_pr=3
	apr='  n_ga npf ncam '
	num=10
	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)
              
        do i=1,n_output2
        output_2(i)=c_output2(i)
        end do

      do i=1,n_output2
!	a_print(i)=output_2(i)
      end do
      
	n_pr=n_output2
	apr='  output2'
	num=10
!	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)

        do i=1,n_output3
 !       output_3(i)=c_output3(i)
        end do

      do i=1,n_output3
!	a_print(i)=c_output3(i)
      end do
      
	n_pr=n_output3
	apr='  output3'
	num=10
!	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)





      return
      end


      
	subroutine dina_outp(n_xx,
     * tpl_xx,uli_xx,v_xx,s_plasma_xx,psi_ax_xx,rmag_xx,zmag_xx,
     * q_ax_xx,q_95_xx,rs0_xx,bt0_xx,wen2_xx,tt_xx,
     * ai_xx,te0_xx,tq0_xx,pne_xx,tok1_xx,q_xx,
     * x_xx,y_xx,psi_xx,psi_bnd_xx,
     * pd0_xx,pt0_xx,sigk_xx,jbut_xx,aj0_xx,qe0_xx,qq0_xx)


	include 'double.inc'
	include 'new_com.inc'

	dimension ai_xx(*),te0_xx(*),tq0_xx(*),pne_xx(*),tok1_xx(*),
     *  q_xx(*),x_xx(*),y_xx(*)
	dimension pd0_xx(*),pt0_xx(*),sigk_xx(*),jbut_xx(*),
     *  aj0_xx(*),qe0_xx(*),qq0_xx(*)
     
	dimension psi_xx(nr,nz)


      n_xx=n

!	pi=3.14159
	
	tpl_xx=tpl*1000.
	
!	print *,' n_xx tpl_xx=',n_xx,tpl_xx
	
!	return
	
	uli_xx=uli
	v_xx=volume
	s_plasma_xx=s_plasma
	psi_ax_xx=pmag*1.e-5*2.*pi
	psi_bnd_xx=pbound*1.e-5*2.*pi
	rmag_xx=rmag/100.
	zmag_xx=zmag/100.
	q_ax_xx=q(2)
	rs0_xx=rs0/100.
	bt0_xx=bt0/10.
	wen2_xx=wen2*1.e6
	tt_xx=tt/1000.

c=================================================

	do i=1,n
	   ai_xx(i)=ai(i)
	   te0_xx(i)=te0(i)
	   tq0_xx(i)=tq0(i)
!	   pne_xx(i)=pne(i)*1.e19
	   pne_xx(i)=pne(i)
	   tok1_xx(i)=tok1(i)*1.e7
	   q_xx(i)=q(i)
	end do
	
	do i=1,n
	   pd0_xx(i)=pd0(i)
	   pt0_xx(i)=pt0(i)
	   sigk_xx(i)=sigk(i)
	   jbut_xx(i)=ajb(i)
	   aj0_xx(i)=aj0(i)
	   qe0_xx(i)=qe0(i)
	   qq0_xx(i)=qq0(i)
	end do

c=================================================

	do i=1,nr
	   x_xx(i)=x(i)/100.
	end do

	do i=1,nz
	   y_xx(i)=y(i)/100.
	end do


	do i=1,nr
	   do j=1,nz
	      psi_xx(i,j)=psi(i,j)*1.e-5*2.*pi
	   end do
	end do


	if(kpr.eq.1)print *,' tt t_vde=',tt,t_vde

      if(tt.gt.t_vde)then
	print *,' tt t_vde=',tt,t_vde
      stop      
      end if
      


      return
      end


	subroutine dina_input(te0_xx,tq0_xx,pne_xx,
     * pd0_xx,pt0_xx,sigk_xx,ajb_xx,aj0_xx,qe0_xx,qq0_xx)

	include 'double.inc'

	dimension te0_xx(*),tq0_xx(*),pne_xx(*)
	dimension pd0_xx(*),pt0_xx(*),sigk_xx(*),ajb_xx(*),
     *  aj0_xx(*),qe0_xx(*),qq0_xx(*)

	include 'parf0'
     
      common /c_input1/te0(npo),tq0(npo),pne(npo),
     *  pd0(npo),pt0(npo),sigk(npo),ajb(npo),
     *  aj0(npo),qe0(npo),qq0(npo)

	common
     *	/n_m/n,m,mp
     */ge2/NTAY,TAY,TT

	character *20 apr

c=================================================

      i_en=i_en+1
      if(i_en.eq.1)then

        open (unit=1,file='kpr.dat',form='formatted')
        read (1,*)
        read (1,*)kpr
        close ( unit=1)       

        open (unit=1,file='tran_times.dat',form='formatted')
        read (1,*)
        read (1,*)tt_dina
        read (1,*)
        read (1,*)t_ret
        close ( unit=1)       


      end if

      tt_1=tt_1+tay
      
      
      print *,' CALL dina_input tt_1 tay t_ret=',tt_1,tay,t_ret
      
      if(tt_1.le.t_ret)return

	do i=1,n
	   te0(i)=te0_xx(i)
	   tq0(i)=tq0_xx(i)
	   pne(i)=pne_xx(i)
	end do

      apr='--te0-' 
      if(kpr.eq.1)print 71,apr,(te0(i),i=1,n) 
      apr='--tq0-' 
      if(kpr.eq.1)print 71,apr,(tq0(i),i=1,n) 
      apr='--pne-' 
      if(kpr.eq.1)print 71,apr,(pne(i),i=1,n) 

   71 FORMAT(20X,A20/,(6(1pE10.3)))
	
	do i=1,n
	   pd0(i)=pd0_xx(i)
	   pt0(i)=pt0_xx(i)
	   sigk(i)=sigk_xx(i)
	   ajb(i)=ajb_xx(i)
	   aj0(i)=aj0_xx(i)
	   qe0(i)=qe0_xx(i)
	   qq0(i)=qq0_xx(i)
	end do

      apr='--pd0-' 
      if(kpr.eq.1)print 71,apr,(pd0(i),i=1,n) 
      apr='--qe0-' 
      if(kpr.eq.1)print 71,apr,(qe0(i),i=1,n) 
      apr='--ajb-' 
      if(kpr.eq.1)print 71,apr,(ajb(i),i=1,n) 

      return
      end




        subroutine  dina_v96_in(

     *  ncam_mat,npf_mat,kloop_mat,kprobe_mat,

     *  gridrange,

     *  kf_mat,mu_mat,

     *  fluxarr_mat,vesarr_mat,

     *  pslgreen_mat,bprgreen_mat,

     *	pfind_mat,pmj_mat,pfc_mat,

     *  pfres_mat,rcam_mat,        

     *  xu_mat,yu_mat,ke_mat,key_mat,

     *  pfgreen_mat,vesgreen_mat,

     *  pfprobe_mat,vesprobe_mat,ngrid2)

      	include 'double.inc'

	include 'parf2'

                                         
        real*8 fluxarr_mat(ngrid2,*),vesarr_mat(ngrid2,*),  

     *	pslgreen_mat(ngrid2,*),bprgreen_mat(ngrid2,*),       

     *	pfind_mat(kf_mat,*),pmj_mat(mu_mat,*),                           

     *  pfc_mat(mu_mat,*),                                              

     *  pfres_mat(*),rcam_mat(*),                                       

     *  xu_mat(*),yu_mat(*),

     *  pfgreen_mat(kloop_mat,*),vesgreen_mat(kloop_mat,*),

     *  pfprobe_mat(kprobe_mat,*),vesprobe_mat(kprobe_mat,*),
     
     * gridrange(*)

	real *8 z_l,z_r,r_l,r_r                                                


	include 'parf1'                                                        
                                                                     
	include 'parf2e'                                                       
                                                                        

	include 'parf4'                                                        

                                                                        

	include 'parf7'                                                        

                                                                        

c	implicit real *8 (a-h,o-z)                                            

                                                                        

       	common                                                          

     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)                       

     *  /ves2/ncam,rc(mu),zc(mu)                                        

     *  /ves3/b(mu,mu),pmj(mu,mu)                                       

     *  /ves4/rcam(mu)                                                  

     *  /ves5/pfc(mu,kf)                                                

                                                                        

	common                                                                 

     *  /eq1/psip(nr,nz),pspl(nwnh),x(nr),y(nz),dx,dy                   

     *  /eq1e/psext(nwnh),re(nre),ze(nze),dr,dz                         

     *  /eq3/FLUXARR(nwnh,kf)                                           

     *  /eq10/vesarr(nwnh,mu)                                           

                                                                        

                                                                        

	common                                                                 

     *  /pf1/npf,pf(kf),pf0(kf)                                         

     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)             

                                                                        

	common                                                                 

     *	/loop1/kloop,rl(nloop),zl(nloop),psloop(nloop)                   

     *  /loop2/pfgreen(nloop,kf),vesgreen(nloop,mu)                     

     *	/loop5/pslgreen(nwnh,nloop)                                      

                                                                        

	common                                                                 

     *	/probe1/kprobe,bprobe(nprobe)                                    

     *  /probe2/pfprobe(nprobe,kf),vesprobe(nprobe,mu)                  

     *	/probe4/bprgreen(nwnh,nprobe)                                    

                                                                        

	common                                                                 

     *  /eq2/ke,xu(mu_l),yu(mu_l)                                       



	common

     *	/c_add0/i_en0

     *	/c_add2/i_en2

     *	/c_add3/i_en3

     *	/c_add7/i_en4


	real*8 pf_mat(kf),tcam_mat(mu)                                                                        
	dimension a_print(100)
	character *20 apr



        i_en0=0

        i_en2=0

        i_en3=0

        i_en4=0

                                                                
      z_l=gridrange(1)
      z_r=gridrange(2)
      r_l=gridrange(3)
      r_r=gridrange(4)

      z0=z_l*100.d0    
	zk=z_r*100.d0
                                                                       
	r0=r_l*100.d0
	rk=r_r*100.d0
                                                                       
	dz=(zk-z0)/(nze-1.)                                              

	dr=(rk-r0)/(nre-1.)                                                    

c----                                                                   

	do i=1,nre                                                             

	re(i)=r0+(i-1)*dr                                                      

	end do                                                                 

                                                                        

	do j=1,nze                                                             

	ze(j)=z0+(j-1)*dz                                                      

	end do                                                                 

                                                                        

	dx=dr                                                                  

	dy=dz                                                                  

                                                                        

        write(41,*)' nre nze ',nre,nze                                  

                                                                        

        write (41,*)' dx dy ',dx,dy                                     

                                                                        

                                                                        

	do i=1,nr                                                              

	x(i)=re(i)                                                             

        write(41,*)' i x ',i,x(i)                                       

	end do                                                                 

                                                                        

	do i=1,nz                                                              

	   y(i)=ze(i)                                                          

        write(41,*)' i y ',i,y(i)                                       

	end do                                                                 

                                                                        

c---------------------------------                                      

	ncam=ncam_mat                                                          

	npf=npf_mat                                                            

                                                                        

	kloop=kloop_mat                                                        

	kprobe=kprobe_mat                                                      

                                                                        

	ke=ke_mat                                                              

	a_print(1)=ncam

	a_print(2)=npf

	a_print(3)=kloop

	a_print(4)=kprobe

	a_print(5)=ke

	a_print(6)=nwnh

	n_pr=6

	apr='  tran_to'

	num=6

c	call out42(n_pr,a_print,num,apr)
                                                                        

       write(41,*)' ncam npf kloop kprobe ke',ncam,npf,kloop,kprobe,ke  

                                                                        

                                                                        

	do k=1,ke                                                              

	   xu(k)=xu_mat(k)*100.                                                

	   yu(k)=yu_mat(k)*100.                                                

        write(41,*)' k xu yu ',k,xu(k),yu(k)                            

	end do                                                                 

                                                                        

	apr='  xu'
c	call out42(n_pr,a_print,num,apr)
                                                                        

	do k=1,ncam                                                            

	   rcam(k)=rcam_mat(k)                                                 

	   do kk=1,ncam                                                        

	      pmj(k,kk)=pmj_mat(k,kk)*1.e8                                     

	   end do                                                              

        write(41,*)' k rcam pmj ',k,rcam(k),pmj(k,k)                    

	end do                                                                 

                                                                        
	apr='  pmj '
c	call out42(n_pr,a_print,num,apr)

                                                                        

	do k=1,ncam                                                            

	   do kk=1,npf                                                         

	      pfc(k,kk)=pfc_mat(k,kk)*1.e8                                     

	   end do                                                              

        write(41,*)' k pfc ',k,pfc(k,1),pfc(k,2),pfc(k,3)               

	end do                                                                 


	apr='  pfc'
c	call out42(n_pr,a_print,num,apr)
                                                                        

	do k=1,npf                                                             

	      pfres(k)=pfres_mat(k)                                            

	   do kk=1,npf                                                         

	      pfind(k,kk)=pfind_mat(k,kk)*1.e8                                 

	   end do                                                              

        write(41,*)' k pfres pfind ',k,pfres(k),pfind(k,k)              

	end do                                                                 

                                                                        
	apr='  pfind'
c	call out42(n_pr,a_print,num,apr)

                                                                        

                                                                        

	do k=1,ncam                                                            

	   do kk=1,nwnh                                                        

	      vesarr(kk,k)=vesarr_mat(kk,k)*1.e8                               

	   end do                                                              

        write(41,*)' k vesarr ',k,vesarr(1,k),vesarr(2,k),vesarr(3,k)   

	end do                                                                 

	apr='  vesarr'
c	call out42(n_pr,a_print,num,apr)



	do k=1,npf                                                             

	   do kk=1,nwnh                                                        

	      fluxarr(kk,k)=fluxarr_mat(kk,k)*1.e8                        

	   end do                                                              

        write(41,*)'k fluxarr',k,fluxarr(1,k),                          

     *  fluxarr(2,k),fluxarr(3,k)                                       

	end do                                                                 

	apr='  fluxarr'
c	call out42(n_pr,a_print,num,apr)


	if(kloop.gt.0)then                                                     

	   do k=1,kloop                                                        

	      do kk=1,nwnh                                                     

		 pslgreen(kk,k)=pslgreen_mat(kk,k)*1.e8

	      end do
	   end do 

	apr='  pslgreen '
c	call out42(n_pr,a_print,num,apr)

	   do k=1,kloop                                                        
	      do kk=1,npf

		 pfgreen(k,kk)=pfgreen_mat(k,kk)*1.e8 

	      end do                                                           
	   end do                                                              

	apr='  pfgreen '
c	call out42(n_pr,a_print,num,apr)

	   do k=1,kloop                                                        
	      do kk=1,ncam

		 vesgreen(k,kk)=vesgreen_mat(k,kk)*1.e8 

	      end do                                                           

	   end do                                                              
	apr='  vesgreen '
c	call out42(n_pr,a_print,num,apr)

	end if                                                                 

                                                                        

	if(kprobe.gt.0)then                                                    
	a_print(4)=kprobe
	apr='  kprobe '
c	call out42(n_pr,a_print,num,apr)

	   do k=1,kprobe                                                       

	apr='  k '
	a_print(1)=k
	n_pr=1
c	call out42(n_pr,a_print,num,apr)
	      do kk=1,nwnh                                                     

		 bprgreen(kk,k)=bprgreen_mat(kk,k)*1.e4

	      end do
	   end do                                                              
	apr='  bprgreen '
c	call out42(n_pr,a_print,num,apr)

	   do k=1,kprobe                                                       
	      do kk=1,npf

		 pfprobe(k,kk)=pfprobe_mat(k,kk)*1.e4

	      end do                                                           
	   end do                                                              
	apr='  pfprobe '
c	call out42(n_pr,a_print,num,apr)

	   do k=1,kprobe                                                       
	      do kk=1,ncam

		 vesprobe(k,kk)=vesprobe_mat(k,kk)*1.e4

	      end do                                                           
	   end do                                                              

	apr='  vesprobe '
c	call out42(n_pr,a_print,num,apr)

	end if                                                                 

        RETURN                                                          

        END                                                             
