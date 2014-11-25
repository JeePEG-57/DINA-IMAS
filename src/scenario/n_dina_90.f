
	subroutine  dina(key_mat,vec_mat,                                      

     *  pf_mat,tcam_mat,d_pf_mat,                                       

     *  d_tcam_mat,                                                     

     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat,                  

     *  shape_out,k_out_dina,

     *  contpts_mat,contvals_mat,kkk,

     *  ech_data,

     *  bp_exp_mat,ps_exp_mat,pf_exp_mat,indpf_mat

c---------------------------------------------------
c	open this lines fot V90
c---------------------------------------------------

     *  ,ext_transp_mat,
     *  c_prof_mat,
     *  aux_heat,
     *  aux_prof,
     *  surf_mat,
     *  surf_psi,
     *  surf_cur,
     *  polar_cur)

	 include 'double.inc'

       real *8 ext_transp_mat(*)
       real *8 c_prof_mat(*)                
       real *8 aux_heat(*),aux_prof(*)
       real *8 surf_mat(*)                
       real *8 surf_psi(*)                
       real *8 surf_cur(*)                
       real *8 polar_cur(*)                

c-------------------------------------


       real *8 cronos_prof(100)                
       real *8 cronos_fields(100)                


        real *8  pf_mat(*),tcam_mat(*),                                 

     *  d_pf_mat(*),d_tcam_mat(*)                                       

                                                                        

	real*8 pl_loop_mat(*),pl_probe_mat(*),                                 

     *  pl_pf_mat(*),pl_ves_mat(*)                                      

                                                                        

	dimension key_mat(*)

                                                                        

	real *8 vec_mat(*),shape_out(*) 



        real *8 contpts_mat(*),contvals_mat(*)


        real *8 ech_data(*)


        real *8 pf_exp_mat(*),ps_exp_mat(*),bp_exp_mat(*)

                             
	real *8 time

       real     timeb, timee,t_start, t_finish


	include 'new_com.inc'
	include 'new_com_m.inc'


        real *8 indpf_mat(*)

	dimension a_print(200)

                                                

	character *40 apr

      parameter (kint=200)
      
      dimension c_input1(kint),c_input2(kint)
      dimension c_output1(kint),c_output2(kint)



73	FORMAT(5X,A10/,(1x,9(1PE10.3)))                                      


c	return

	i_model=90

!	include 'n_dina.f'                                                  
c	call pau()

      call cpu_time(t_start)


	if(i_exit.eq.1)then 
!      Iopen=0
!      call OpenCloseConsole(Iopen) 
c	   call pau()
	return
	end if

	i_en0=i_en0+1    

      kpr=key_mat(4)


      if(i_en0.eq.1.and.kpr.eq.1)then
!      bret=AllocConsole() ;

!      Iopen=1
!      call OpenCloseConsole(Iopen) 
      end if


        c_input1(1)=tpl

	  call dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2)


5000    format (6(1pe14.6))  


	return                                                                 
	end                                                                    

        subroutine  tran_to_dina(

     *  ncam_mat,npf_mat,kloop_mat,kprobe_mat,

     *  z_l,z_r,r_l,r_r,

     *  kf_mat,mu_mat,

     *  fluxarr_mat,vesarr_mat,

     *  pslgreen_mat,bprgreen_mat,

     *	pfind_mat,pmj_mat,pfc_mat,

     *  pfres_mat,rcam_mat,        

     *  xu_mat,yu_mat,ke_mat,key_mat,

     *  pfgreen_mat,vesgreen_mat,

     *  pfprobe_mat,vesprobe_mat)

      	include 'double.inc'



	include 'parf2'

                                           

        real*8 fluxarr_mat(nwnh,*),vesarr_mat(nwnh,*),                  

     *	pslgreen_mat(nwnh,*),bprgreen_mat(nwnh,*),                       

     *	pfind_mat(kf_mat,*),pmj_mat(mu_mat,*),                           
c     *	pfind_mat(npf_mat,*),pmj_mat(ncam_mat,*),                           

     *  pfc_mat(mu_mat,*),                                              
c     *  pfc_mat(ncam_mat,*),                                              

     *  pfres_mat(*),rcam_mat(*),                                       

     *  xu_mat(*),yu_mat(*),

     *  pfgreen_mat(kloop_mat,*),vesgreen_mat(kloop_mat,*),

     *  pfprobe_mat(kprobe_mat,*),vesprobe_mat(kprobe_mat,*)

                                   

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



      return

        i_en0=0

        i_en2=0

        i_en3=0

        i_en4=0

	i_read=0
	if(i_read.eq.1)then
        call read_to_mat(                                        

     *  ncam_mat,npf_mat,kloop_mat,kprobe_mat,                          

     *  z_l,z_r,r_l,r_r,                                                

     *  kf_mat,mu_mat,                                                  

     *  fluxarr_mat,vesarr_mat,                                         

     *  pslgreen_mat,bprgreen_mat,                                      

     *	pfind_mat,pmj_mat,pfc_mat,                                       

     *  pfres_mat,rcam_mat,                                             

     *  xu_mat,yu_mat,ke_mat,                                           

     *  pf_mat)                                                         

	end if
                                                                

c!        open(unit=41,file='f41',form='formatted')                  

	z0=z_l*100.                                                            

	zk=z_r*100.                                                            

                                                                        

	r0=r_l*100.                                                            

	rk=r_r*100.                                                            

                                                                        

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

                                                                        

c!        write(41,*)' nre nze ',nre,nze                                  

                                                                        

c!        write (41,*)' dx dy ',dx,dy                                     

                                                                        

                                                                        

	do i=1,nr                                                              

	x(i)=re(i)                                                             

c!        write(41,*)' i x ',i,x(i)                                       

	end do                                                                 

                                                                        

	do i=1,nz                                                              

	   y(i)=ze(i)                                                          

c!        write(41,*)' i y ',i,y(i)                                       

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
                                                                        

c!       write(41,*)' ncam npf kloop kprobe ke',ncam,npf,kloop,kprobe,ke  

                                                                        

                                                                        

	do k=1,ke                                                              

	   xu(k)=xu_mat(k)*100.                                                

	   yu(k)=yu_mat(k)*100.                                                

c!        write(41,*)' k xu yu ',k,xu(k),yu(k)                            

	end do                                                                 

                                                                        

	apr='  xu'
c	call out42(n_pr,a_print,num,apr)
                                                                        

	do k=1,ncam                                                            

	   rcam(k)=rcam_mat(k)                                                 

	   do kk=1,ncam                                                        

	      pmj(k,kk)=pmj_mat(k,kk)*1.e8                                     

	   end do                                                              

c!        write(41,*)' k rcam pmj ',k,rcam(k),pmj(k,k)                    

	end do                                                                 

                                                                        
	apr='  pmj '
c	call out42(n_pr,a_print,num,apr)

                                                                        

	do k=1,ncam                                                            

	   do kk=1,npf                                                         

	      pfc(k,kk)=pfc_mat(k,kk)*1.e8                                     

	   end do                                                              

c!        write(41,*)' k pfc ',k,pfc(k,1),pfc(k,2),pfc(k,3)               

	end do                                                                 


	apr='  pfc'
c	call out42(n_pr,a_print,num,apr)
                                                                        

	do k=1,npf                                                             

	      pfres(k)=pfres_mat(k)                                            

	   do kk=1,npf                                                         

	      pfind(k,kk)=pfind_mat(k,kk)*1.e8                                 

	   end do                                                              

c!        write(41,*)' k pfres pfind ',k,pfres(k),pfind(k,k)              

	end do                                                                 

                                                                        
	apr='  pfind'
c	call out42(n_pr,a_print,num,apr)

                                                                        

                                                                        

	do k=1,ncam                                                            

	   do kk=1,nwnh                                                        

	      vesarr(kk,k)=vesarr_mat(kk,k)*1.e8                               

	   end do                                                              

c!        write(41,*)' k vesarr ',k,vesarr(1,k),vesarr(2,k),vesarr(3,k)   

	end do                                                                 

	apr='  vesarr'
c	call out42(n_pr,a_print,num,apr)



	do k=1,npf                                                             

	   do kk=1,nwnh                                                        

	      fluxarr(kk,k)=fluxarr_mat(kk,k)*1.e8                        

	   end do                                                              

c        write(41,*)'k fluxarr',k,fluxarr(1,k),                          

c     *  fluxarr(2,k),fluxarr(3,k)                                       

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

c       	close (41)                                                      

c                                                                       
	i_write=0
	if(i_write.eq.1)then
	call write2_to_mat(                                       

     *  ncam_mat,npf_mat,kloop_mat,kprobe_mat,                          

     *  z_l,z_r,r_l,r_r,                                                

     *  kf_mat,mu_mat,                                                  

     *  fluxarr_mat,vesarr_mat,                                         

     *  pslgreen_mat,bprgreen_mat,                                      

     *	pfind_mat,pmj_mat,pfc_mat,                                       

     *  pfres_mat,rcam_mat,                                             

     *  xu_mat,yu_mat,ke_mat,                                           

     *  pf_mat,tcam_mat,

     *  pfgreen_mat,vesgreen_mat,

     *  pfprobe_mat,vesprobe_mat)

	end if

	i_write=0
	if(i_write.eq.1)then
	call tran_to_mat(                                        

     *  ncam_mat,npf_mat,kloop_mat,kprobe_mat,                          

     *  z_l,z_r,r_l,r_r,                                                

     *  kf_mat,mu_mat,                                                  

     *  fluxarr_mat,vesarr_mat,                                         

     *  pslgreen_mat,bprgreen_mat,                                      

     *	pfind_mat,pmj_mat,pfc_mat,                                       

     *  pfres_mat,rcam_mat,                                             

     *  xu_mat,yu_mat,ke_mat,                                           

     *  pf_mat,tcam_mat,

     *  pfgreen_mat,vesgreen_mat,

     *  pfprobe_mat,vesprobe_mat)
	
	stop
	end if


        RETURN                                                          

        END                                                             






