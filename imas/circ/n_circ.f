                                                                        
	subroutine equil()                                                     
      include 'double.inc'

	include 'new_com.inc'                                                  
                                                                        
	call equil_c(                                                          

     *  k_help,dfmax,dfmax0,bt0,beta,brad,

     *  xbound,ybound,errm,i_en2,key_eq,power_ech,q,
     *  i_ech,q_test,omg_ppx,key_ext,int_2000,it_ext,tokc,i_en3,k_efit,
     *  te0,eps_vel,key_equil,vchopper,pf,i_gen,ajb,betj,i_new,key_ne,
     *  tpl0,i_pres,i_bound,fdd,fdd0,pll,i_exit,n_pas,npf,pfres,tt1,
     *  a,ha,elong,k_dm0,tcam,ncam,udd)

	return                                                                 

	end                                                                    

                                                                        

                                                                        

                                                                        

	subroutine  equil_c(                                                   

     *  k_help,dfmax,dfmax0,bt0,beta,brad,

     *  xbound,ybound,errm,i_en2,key_eq,power_ech,q,
     *  i_ech,q_test,omg_ppx,key_ext,int_2000,it_ext,tokc,i_en3,k_efit,
     *  te0,eps_vel,key_equil,vchopper,pf,i_gen,ajb,betj,i_new,key_ne,
     *  tpl0,i_pres,i_bound,fdd,fdd0,pll,i_exit,n_pas,npf,pfres,tt1,
     *  a,ha,elong,k_dm0,tcam,ncam,udd)

      	include 'double.inc'

      dimension xbound(*),ybound(*),q(*),te0(*),vchopper(*),pf(*),
     *  ajb(*),pfres(*),tcam(*)

                                                                        

	include 'parf0'                                                        

	common                                                                 

     *	/n_m/n,m,mp                                                      

	common                                                                 

     *	/keys1/i_graph                                                   

     *	/keys2/key_b                                                     

     *	/keys3/kzero,iread,iwrite                                        

     *  /keys4/k_ener,k_uv                                              

     *  /keys5/next                                                     

     *  /keys6/i_svd,i_cal,kpf                                          

     *  /keys7/i_c                                                      

     *  /keys8/ndh                                                      

     *  /keys9/i_d3d,i_iter,i_smal                                      

     *  /keys10/ngra                                                    

     *  /keys11/i_ramp                                                  

     *  /keys12/i_v                                                     

     *  /keys13/i_con,i_act                                             

     *  /keys14/i_beta,i_gap5                                           

     *  /keys15/i_br                                                    

     *  /keys17/i_feed,i_ecoil                                          

	common                                                                 

     *	/con1/gain,ta,zref,kzref                                         

     *  /con2/rref,krref,bvert                                          

     *  /con3/i_pf                                                      

     *  /con5/n_exp,k_cont                                              

	common                                                                 

     *  /pol4/ UM,VM,UK(ntet),VK(ntet)                                  

	common                                                                 

     *	/ge1/pi                                                          

     *	/ge1e/rs0,tpl                                                    

     *  /ge2/NTAY,TAY,TT                                                

     *  /ge2e/t_end                                                     

     *  /ge4/EPS1,EPS2,EPS0                                             

     *  /ge4e/it_v,it_pf                                                

     *  /ge5/kpr                                                        

	common                                                                 

     *  /cont13/zmag,zvel,delrmag,delzmag                               

     *  /cont13e/zmag0,rmag,rmag0,rvel                                  

	common                                                                 

     *	/efit4/coef                                                      

     *	/efit5/it1,it2                                                   

	common                                                                 

     *  /DFM2/PSI(npo),PFI(npo),DM0(npo),DMN(npo)                       

	common                                                                 

     *  /mid2/vi(npo),spo(npo)                                          

     *  /mid3/GRA1(npo),GRA2(npo)                                       

	common                                                                 

     *  /en6/Vn(npo)                                                    

     *  /en14/EMOE,EMOQ,NDOP,QDE0(npo),QDQ0(npo)                        

     *  /en14e/t_dop                                                    

     *  /en33/anom_e,anom_i,key_t11,kcchp                               

	common                                                                 

     *	/point1/r0,z0                                                    

	common                                                                 

     *  /halo1/c_h,d_halo,fmax_in,tpl_in                                

     *  /halo2/kmaj,k_q,k_d,kaxis,ndisrup                               

     *  /halo2e/next0,li_drop,n_li,n_dif,nmix                           

     *  /halo3/tay_00,tay_th,t_disr,d_tpl,tpl_end                       

     *  /halo4/expfg,avalb,w_h,del_r,al0                                

     *  /halo5/q_vde,q_95,del_f,i_halo                                  

     *  /halo9/fluxt,fluxt0                                             

     *  /halo10/fves,fves0,self_v                                       

        common                                                          

     *	/ge7/eu,rs,zout,eksk                                             

     *  /ge7e/eu_u                                                      

        common                                                          

     *	/fluxc12/r00,z00,eu00                                            

     *  /fluxc18/alf_tok,int_tok                                        

      common 
     * /c_imas_t_end2/t_end2

	common /c_data_in_time2/i_c_data,i_c_data1       

	dimension df_help(npo),dm_help(npo),uk_help(ntet),

     *  vk_help(ntet),v_help(100)

                                                                        

	dimension dfmax(*),dfmax0(*),a(*),ha(*),tcam_help(300)   

                                                                        
	real *8 tt_in

                                                                        

	character *30 apr                                                      

	dimension a_print(200),a_print1(200)

c______________________________                                         


	i_en2=i_en2+1            

	if(i_en2.eq.1)then	

        open (unit=1,file='kpr.dat',form='formatted')
        read (1,*)
        read (1,*)kpr

        if(kpr.eq.1)print *,' i_en2== kpr ',i_en2,kpr
        
!              i_con=3

        close ( unit=1)       


      	ARG=1.d0                                     
	  pi=4.d0*datan(ARG) 
	  coef=10.d0/(4.d0*pi)      
	  amu0=0.4*pi

!      	call read_data() 

           open (unit=41,file='time_circ.dat',form='formatted') 
           read (41,*)
           read (41,*)tay,t_end 
           close (41)
	     
	     t_end=tt+t_end

	if(kpr.eq.1)print *,' tay t_end ==',
     *  tay,t_end
     

      i_flat_ext=0
      
!      print *,' i_flat==',i_flat_ext
       
      if(i_flat_ext.eq.1)then
        call flat_ext()

      i_c=0
	call movem(i_c)

      end if

!      call shape_pfres()
	if(i_gen.eq.0)call inv_gen()

	if(i_gen.eq.1)call inv_gen_pf()

	if(i_gen.eq.0)call gen() 
	if(i_gen.eq.1)call gen_pf() 

	call time_gen()                                                        

      return

      end if


!      call shape_pfres()
      if(i_gen.eq.0)call gen()              
	if(i_gen.eq.1)call gen_pf()              

	call time_gen()                                                       

      if(tt.gt.t_end)then
	print *,' tt t_end=',tt,t_end
      stop      
      end if



71	FORMAT(5X,A10/,(2x,6(1PE11.3)))                                      

	return                                                                 

	end                                                                    

	subroutine flat_ext()
	include 'double.inc'
	include 'new_com.inc'

	call flat_ext_c(
     *  nwnh,nr,nz,npf,ncam,pf,tcam,fluxarre,vesarre,
     *  kf,mu,pfind,pfc,pmj,pfres,rcam,
     *  xu,yu,ke,
     *  nloop,nprobe,kloop,kprobe,
     *  pfgreen,vesgreen,
     *  pfprobe,vesprobe,
     *  pslgreene,bprgreene,
     *  re,ze,x,y,dr,dz,dx,dy)                       
	
	return
	end



	subroutine flat_ext_c(
     *  nwnh,nr,nz,npf,ncam,pf,tcam,
     *  fluxarr,vesarr,
     *  kf,mu,pfind,pfc,pmj,pfres,rcam,
     *  xu,yu,ke,
     *  nloop,nprobe,kloop,kprobe,
     *  pfgreen,vesgreen,
     *  pfprobe,vesprobe,
     *  pslgreen,bprgreen,
     *  re,ze,x,y,dr,dz,dx,dy)                       

	include 'double.inc'

	dimension pf(*),tcam(*),fluxarr(nwnh,*),
     *  vesarr(nwnh,*),
     *  pfind(kf,*),pfc(mu,*),pmj(mu,*),pfres(*),rcam(*),
     *  xu(*),yu(*),
     *  pfgreen(nloop,*),vesgreen(nloop,*),
     *  pfprobe(nprobe,*),vesprobe(nprobe,*),
     *  pslgreen(nwnh,*),bprgreen(nwnh,*),                       
     *  re(*),ze(*),x(*),y(*)                       

	dimension ttt(500)

      common
     *  /ge5/kpr

	character *200 f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,
     * f11,f12,f13,f14,f15,f16
c

	if(kpr.eq.1)print *,' nwnh=',nwnh


c-----------
	open (unit=40,file='flux_flat.fl',form='formatted')
	read (40,*)
	read (40,74)f0
	read (40,*)
	read (40,74)f1
	read (40,*)
	read (40,74)f2
	read (40,*)
	read (40,74)f3
	read (40,*)
	read (40,74)f4
	read (40,*)
	read (40,74)f5
	read (40,*)
	read (40,74)f6
	read (40,*)
	read (40,74)f7
	read (40,*)
	read (40,74)f8
	read (40,*)
	read (40,74)f9
	read (40,*)
	read (40,74)f10
	read (40,*)
	read (40,74)f11
	read (40,*)
	read (40,74)f12
	read (40,*)
	read (40,74)f13
	read (40,*)
	read (40,74)f14
	read (40,*)
	read (40,74)f15
	read (40,*)
	read (40,74)f16

74	format(a110)
	close (40)


	if(kpr.eq.1)print *,f0
	open (unit=41,file=f0,form='formatted')                  
!!!	open (unit=41,file='glcoeff_mat.flat',form='formatted')                    

	read (41,*)npf,ncam,kloop,kprobe                                                    
	close (41)                                                             

	if(kpr.eq.1)print *,' npf ncam=',npf,ncam
	if(kpr.eq.1)print *,' kloop,kprobe=',kloop,kprobe

      
	open (unit=41,file=f1,form='formatted')                    
!	open (unit=41,file='pmj_mat.flat',form='formatted')                    

	read (41,*)ncam_mat                                                    

	read (41,*)                                                            

      if(ncam.ne.ncam_mat)then

	if(kpr.eq.1)print *,' ncam.ne.ncam_mat=',ncam,ncam_mat

	read (*,*)
	
	end if
	                                                                  

	do kk=1,ncam                                                       

	   do k=1,ncam                                                    

	      read (41,*)pmj(k,kk)
		     pmj(k,kk)=pmj(k,kk)*1.d8    
	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file=f2,form='formatted')                    
!	open (unit=41,file='pfc_mat.flat',form='formatted')                    

                                                                        

	read (41,*)ncam_mat                                                    

	read (41,*)npf_mat                                                     

                                                                        

	do kk=1,npf                                                        

	   do k=1,ncam                                                     

	   read (41,*)pfc(k,kk)                                            
	pfc(k,kk)=pfc(k,kk)*1.d8
	end do                                                                 

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        
	if(kpr.eq.1)print *,f3

	open (unit=41,file=f3,form='formatted')                  
!!!	open (unit=41,file='pfres_mat.flat',form='formatted')                  

                                                                        

	read (41,*)npf_mat                                                     

	if(kpr.eq.1)print *,' npf_mat npf==',npf_mat,npf

	read (41,*)                                                            

	do k=1,npf                                                        

	   read (41,*)pfres(k)                                             

	end do                                                                 

 	res_ves=0.
	do i=1,npf
	   res_ves=res_ves+1./pfres(i)
	end do
	   res_ves=1./res_ves

	if(kpr.eq.1)print *,'npf pf_res ',ncam,res_ves
                                                                        

	close (41)                                                             

                                                                        

	if(kpr.eq.1)print *,f4

	open (unit=41,file=f4,form='formatted')                   
!	open (unit=41,file='rcam_mat.flat',form='formatted')                   

                                                                        

	read (41,*)ncam_mat                                                    

	read (41,*)                                                            



	do k=1,ncam                                                        

	read (41,*)rcam(k)                                                 

	end do                                                                 

 	res_ves=0.
	do i=1,ncam
	
!	rcam(i)=rcam(i)*2.
	
	   res_ves=res_ves+1./rcam(i)
	end do
	   res_ves=1./res_ves

	if(kpr.eq.1)print *,'ncam res_ves ',ncam,res_ves
                                                                       

	close (41)                                           

                                                                        


	if(kpr.eq.1)print *,f5
	open (unit=41,file=f5,form='formatted')                  
!	open (unit=41,file='pfind_mat.flat',form='formatted')                  

                                                                        

	read (41,*)npf_mat                                                     

	read (41,*)                                                            

	do kk=1,npf                                                       

	   do k=1,npf                                                      

	      read (41,*)pfind(k,kk)
		  pfind(k,kk)=pfind(k,kk)*1.d8                                       
	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        


	if(kpr.eq.1)print *,f6

	open (unit=41,file=f6,form='formatted')                 
!	open (unit=41,file='vesarr_mat.flat',form='formatted')                 

                                                                       
	read (41,*)                                                            

	read (41,*)                                                            

	do k=1,ncam                                                        

	   do kk=1,nwnh                                                        

	      read (41,*)vesarr(kk,k)
		  vesarr(kk,k)=vesarr(kk,k)*1.d8 
c		  if(kpr.eq.1)print *,' k kk vesarr=',k,kk,vesarr(kk,k)                                     

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	if(kpr.eq.1)print *,f7
     	open (unit=41,file=f7,form='formatted')                
!	open (unit=41,file='fluxarr_mat.flat',form='formatted')

c----------------------------------
                                                                        
	read (41,*)                                                            

	read (41,*)                                                            

	do k=1,npf                                                        

	   do kk=1,nwnh                                                        

	   read (41,*)fluxarr(kk,k)                                     
	   fluxarr(kk,k)=fluxarr(kk,k)*1.d8
	   end do                                                              
	
	
	j=1
	do i=1,nr+nz	
	ttt(i)=fluxarr(i,k)
	end do

      if(kpr.eq.1)then
	write(6,'(" k ttt ",
     *  i4,6(1pe12.5))'),
     *  k,(ttt(i),i=1,nr+nz)
      end if
      

	end do                                                                 

                                                                        

	close (41)                                                             

	if(kpr.eq.1)print *,f8
     	open (unit=41,file=f8,form='formatted')                
!!!	open (unit=41,file='pslgreen_mat.flat',form='formatted')               

                                                                        

	read (41,*)                                                            

	read (41,*)                                                   

	do k=1,kloop                                                       

	   do kk=1,nwnh                                                        

	   read (41,*)pslgreen(kk,k)                                       
	   pslgreen(kk,k)=pslgreen(kk,k)*1.d8

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             



	if(kpr.eq.1)print *,f9
     	open (unit=41,file=f9,form='formatted')                
!!!	open (unit=41,file='pfgreen_mat.flat',form='formatted')               

	read (41,*)

	read (41,*)

	do k=1,kloop                                                       

	   do kk=1,npf

	   read (41,*)pfgreen(k,kk)                                       
	   pfgreen(k,kk)=pfgreen(k,kk)*1.d8 

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	if(kpr.eq.1)print *,f10
     	open (unit=41,file=f10,form='formatted')                
!!!	open (unit=41,file='vesgreen_mat.flat',form='formatted')               

	read (41,*)

	read (41,*)

	do k=1,kloop                                                       

	   do kk=1,ncam

	   read (41,*)vesgreen(k,kk)                                       
	   vesgreen(k,kk)=vesgreen(k,kk)*1.d8 

	   end do                                                              

	end do                                                                 

	close (41)                                                             



                                                                        

	if(kpr.eq.1)print *,f11
     	open (unit=41,file=f11,form='formatted')                
!!!	open (unit=41,file='bprgreen_mat.flat',form='formatted')               

                                                                        

	read (41,*)                                                            

	read (41,*)                                                  

	do k=1,kprobe                                                 

	   do kk=1,nwnh                                                        

	   read (41,*)bprgreen(kk,k)                                       
		 bprgreen(kk,k)=bprgreen(kk,k)*1.d4

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             



	if(kpr.eq.1)print *,f12
     	open (unit=41,file=f12,form='formatted')                
!!!	open (unit=41,file='pfprobe_mat.flat',form='formatted')               

	read (41,*)
	read (41,*)
	do k=1,kprobe
	   do kk=1,npf
	   read (41,*)pfprobe(k,kk)                                       
		 pfprobe(k,kk)=pfprobe(k,kk)*1.d4
	   end do                                                              
	end do                                                                 

	close (41)                                                             



	if(kpr.eq.1)print *,f13
     	open (unit=41,file=f13,form='formatted')                
!!!	open (unit=41,file='vesprobe_mat.flat',form='formatted')               

	read (41,*)
	read (41,*)
	do k=1,kprobe
	   do kk=1,ncam
	   read (41,*)vesprobe(k,kk)                                       
		 vesprobe(k,kk)=vesprobe(k,kk)*1.d4
	   end do                                                              
	end do                                                                 

	close (41)                                                             

                                                                        




	if(kpr.eq.1)print *,f14
     	open (unit=41,file=f14,form='formatted')                
!!!	open (unit=41,file='gridrange.flat',form='formatted')                  

	read (41,*)                                                            
	read (41,*)                                                            
	read (41,*)z_l                                                         
	read (41,*)z_r                                                         
	read (41,*)r_l                                                         
	read (41,*)r_r                                                         
c	if(kpr.eq.1)print *,' z_l z_r r_l r_r==',z_l,z_r,r_l,r_r                           

	close (41)                                                             

                                                                        

	if(kpr.eq.1)print *,f15
     	open (unit=41,file=f15,form='formatted')                
!!!	open (unit=41,file='xu_mat.flat',form='formatted')                     

	read (41,*)ke_mat                                                      
	read (41,*)                                                            
     	do k=1,ke_mat                                                          
	read (41,*)xu(k)                                                   
	end do                                                                 

	close (41)                                                             

	if(kpr.eq.1)print *,f16
     	open (unit=41,file=f16,form='formatted')                
!!!	open (unit=41,file='yu_mat.flat',form='formatted')                     

	read (41,*)ke_mat                                                      
	read (41,*)                                                            
	do k=1,ke_mat                                                          
	read (41,*)yu(k)                                                   
	end do                                                                 

	close (41) 
	
	ke=ke_mat                                                            

	do k=1,ke                                                              

	   xu(k)=xu(k)*100.d0                                                

	   yu(k)=yu(k)*100.d0                                                

c        write(41,*)' k xu yu ',k,xu(k),yu(k)                            

	end do                                                                 


	z0=z_l*100.d0                                                            

	zk=z_r*100.d0                                                            

                                                                        

	r0=r_l*100.d0                                                            

	rk=r_r*100.d0 

                                                                        

	dz=(zk-z0)/(nz-1.)                                                    

	dr=(rk-r0)/(nr-1.)                                                    

c----                                                                   

	do i=1,nr                                                             

	re(i)=r0+(i-1)*dr                                                      

	end do                                                                 

                                                                        

	do j=1,nz                                                             

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

	if(kpr.eq.1)print *,'z1,   zk,    r1,     rk'
	if(kpr.eq.1)print *,ze(1),ze(nz),re(1),re(nr)


	return
	end
  	subroutine shape_pfres() 
	include 'double.inc'
 	include 'parf1' 
 	include 'parf_mike' 
 
	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)
	common
     *  /ge2/ntay,tay,tt
        common
     *  /ge5/kpr


	dimension t_t(ntime),pf_t(kf,ntime)

      character*70 apr
	character *30 apr1
	dimension a_print(200)

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='pfres.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 

 	 if(kpr.eq.1)print *,' tt n_t===',tt,n_t 
           read (41,*) 

           do i=1,n_t 
              read (41,*)t_t(i),(pf_t(k,i),k=1,npf)
              t_t(i)=t_t(i)*1000. 
           end do 

      do i=1,npf
	a_print(i)=pfres(i)
	end do
	
	n_pr=npf
	apr1='pfres'
	num=20
	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr1)

      do i=1,n_t
	a_print(i)=t_t(i)
	end do
	
	n_pr=n_t
	apr1='t_t'
	num=20
	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr1)

           
           apr='-t_t-' 
c           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 
           close (unit=41) 
        end if
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))


      k_inv=0
      
      do i=1,n_t

      t1=t_t(i)-0.49d0*tay
      t2=t_t(i)+0.51d0*tay
      
	 a_print(1)=t1
	 a_print(2)=tt
	 a_print(3)=t2
	 a_print(4)=tay
	
	 n_pr=4
	 apr1='t1 tt t2 tay'
	 num=20
!	 if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr1)

      if( (tt-t1)*(tt-t2).le.0.)then


	 n_pr=4
	 apr1='t1 tt t2 tay'
	 num=20
	 if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr1)
	 
	 	 do k=1,npf
	    pfres(k)=pf_t(k,i)
	 end do

       k_inv=1
       tt_inv=t_t(i)
       
	 end if

	 end do
	 
	 if(k_inv.eq.1)then

	 a_print(1)=k_inv
	 a_print(2)=tt_inv
	 a_print(3)=tt
	
	 n_pr=3
	 apr1='k_inv t_inv tt'
	 num=20
	 if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr1)
	 if(kpr.eq.1)print *,' k_inv2 t_inv tt',k_inv,t_inv,tt
	 
	 call inv_gen()

      do i=1,npf
	a_print(i)=pfres(i)
	end do
	
	n_pr=npf
	apr1='pfres'
	num=20
	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr1)


	 end if
	 
	 if(kpr.eq.1)print *,' from SHAPE k_in pfres',k_inv,pfres(3)

       return 
       end 
        subroutine movem(i_c)

	include 'double.inc'
	include 'parf0'
	include 'parf1'
	include 'parf2'
	include 'parf4'
	include 'parf2e'

c	implicit real *8 (a-h,o-z)
	common
     *  /ge5/kpr
     *  /ge7/eu,rout,zout,elong
	common
     *  /pol4/ UM,VM,UK(ntet),VK(ntet)
	COMMON
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /eq1/psip(nr,nz),pspl(nwnh),x(nr),y(nz),dx,dy
     *  /eq1e/psext(nwnh),re(nre),ze(nze),dr,dz
     *  /eq3/FLUXARR(nwnh,kf)
     *  /eq3e/FLUXARRE(nwnhe,kf)
     *  /eq10/vesarr(nwnh,mu)
     *  /eq10e/vesarre(nwnhe,mu)
	common
     *  /ves2/ncam,rc(mu),zc(mu)
c
	common
     *	/loop1/kloop,rl(nloop),zl(nloop),psloop(nloop)
     *	/loop5/pslgreen(nwnh,nloop)
     *	/loop5e/pslgreene(nwnhe,nloop)
c
	common
     *	/probe1/kprobe,bprobe(nprobe)
     *	/probe4/bprgreen(nwnh,nprobe)
     *	/probe4e/bprgreene(nwnhe,nprobe)
	common
     *	/fluxc10/x1,y1,dx1,dy1
     *	/fluxc12/r00,z00,eu00

c------------------------
        if(kpr.eq.1)print *,' r00 z00 eu00 i_c=',r00,z00,eu00,i_c

	r1=re(1)
	rk=re(nre)
	z1=ze(1)
	zk=ze(nze)
c------------------------
	x1=re(1)
	y1=ze(1)
	dx1=1./dr
	dy1=1./dz
c--------------------------


	dx=dr
	dy=dz

	do i=1,nr
	x(i)=re(i)
	end do
	do i=1,nz
	y(i)=ze(i)
	end do

	do k=1,ncam
c---begin psicam
	do i=1,nre
	do j=1,nze
	kk=(i-1)*nze+j
c	kk1=(j-1)*nre+i
	vesarr(kk,k)=vesarre(kk,k)
	end do
	end do
	end do

	do k=1,npf
	do i=1,nre
	do j=1,nze
	kk=(i-1)*nze+j
c	kk1=(j-1)*nre+i
	fluxarr(kk,k)=fluxarre(kk,k)
	end do
	end do
	end do
	if(kloop.gt.0)then
	do k=1,kloop
	do i=1,nre
	do j=1,nze
	kk=(i-1)*nze+j
c	kk1=(j-1)*nre+i
	pslgreen(kk,k)=pslgreene(kk,k)
	end do
	end do
	end do
	end if
	if(kprobe.gt.0)then
	do k=1,nprobe
	do i=1,nre
	do j=1,nze
	kk=(i-1)*nze+j
c	kk1=(j-1)*nre+i
	bprgreen(kk,k)=bprgreene(kk,k)
	end do
	end do
	end do
	end if

c
        RETURN
        END
	subroutine read_data()
	include 'double.inc'
	include 'new_com.inc'


	call read_data_c(
     *  res_coef,n_polar,
     *  k_ion)

	return
	end
	subroutine read_data_c(
     *  res_coef,n_polar,
     *  k_ion)

	include 'double.inc'
        include 'parf0'
	include 'parf2'
	common
     *  /cont13/zmag,zvel,delrmag,delzmag
     *  /cont13e/zmag0,rmag,rmag0,rvel
	common
     *	/n_m/n,m,mp
	common
     *  /eq12/omega,pspl0(nwnh)
	common
     *	/ge1e/rs0,tpl
     *  /ge2/NTAY,TAY,TT
     *  /ge2e/t_end
     *  /ge4/EPS1,EPS2,EPS0
     *  /ge5/kpr
     *  /ge6e/zeff_a,zeff_b
     *	/ge7/eu,rs,zout,eksk
	common
     *  /DFM1/UDM,ZDM,L3,SIG0
     *  /dfm7/bt0,uind
	common
     *	/efit0/kefit
     *	/efit1/alfax(2),betax(2)
     *	/efit2/alfa0,beta,alfa1
     *	/efit3/pw_1,pw_2
	common
     *  /pol5/psend
	common
     *  /en1e/te_a,ti_a,te_b,ti_b,pw_e
     *  /en2e/pd0_a,pt0_a,pd0_b,pt0_b,pw_p
     *  /en7/UD,ZD,UT,ZT,UH,ZH,LD,LT,LH,ID,IT,IH,KTP,Neng
     *  /en11/un(4),zn(2),ll,ken,ken1,ken2,noit
     *  /en12/pnal(npo),pnaln(npo),zalfa,talfa
     *  /en13/KPIN,VPIN,ALP1,POT,SKOR
     *  /en14/EMOE,EMOQ,NDOP,QDE0(npo),QDQ0(npo)
     *  /en14e/t_dop
     *  /eq15e/pll0,tpl0,udd
     *  /en19/DD,DT,DH,SIN0,SINK,ALPY,Sss,Ppp,Eee
     *  /en33/anom_e,anom_i,key_t11,kcchp
     *  /en25/zhib,tego

	common
     *	/keys1/i_graph
     *	/keys2/key_b
     *	/keys3/kzero,iread,iwrite
     *  /keys4/k_ener,k_uv
     *  /keys5/next
     *  /keys7/i_c
     *  /keys8/ndh
     *  /keys9/i_d3d,i_iter,i_smal
     *  /keys10/ngra
     *  /keys11/i_ramp
     *  /keys12/i_v
     *  /keys13/i_con,i_act
     *  /keys14/i_beta,i_gap5
     *  /keys15/i_br
     *  /keys17/i_feed,i_ecoil
	common
     *	/con1/gain,ta,zref,kzref
     *  /con2/rref,krref,bvert
     *  /con3/i_pf
     *  /con5/n_exp,k_cont
     *  /con6/ind_r(2),ind_z(2)
	common
     *	/point1/r0,z0
	common
     *  /halo1/c_h,d_halo,fmax_in,tpl_in
     *  /halo2/kmaj,k_q,k_d,kaxis,ndisrup
     *  /halo2e/next0,li_drop,n_li,n_dif,nmix
     *  /halo3/tay_00,tay_th,t_disr,d_tpl,tpl_end
     *  /halo4e/w_h0,delaval0,pshalo0,te_h0
     *  /halo5/q_vde,q_95,del_f,i_halo
     *  /halo12/te_h
     *  /halo14/hpart
     *  /halo15/e_sep,nsep
	common
     *  /pol4/UM,VM,UK(ntet),VK(ntet)
	common
     *	/cont18/t_vde,time_disr
	common
     *  /ef_0/key_ef
     
       

     	open(unit=2,file='for002_kav',form='formatted')
        if(kpr.eq.1)print *,' begin for002_kav reading'

	read (2,*)
	read (2,*)n,m,next
	read (2,*)
	read (2,*)tt,tay,t_end,rs0,psend
	read (2,*)
	read (2,*)i_graph
	read (2,*)
	read (2,*)alfa0,beta,alfa1,omega
	read (2,*)
	read (2,*)iread,kzero,iwrite,kefit
	read (2,*)
	read (2,*)alfax,betax
	read (2,*)
	read (2,*)pw_1,pw_2
	read (2,*)
	read (2,*)te_a,ti_a,te_b,ti_b,pw_e
	read (2,*)
	read (2,*)pd0_a,pt0_a,pd0_b,pt0_b,pw_p
	read (2,*)
	read (2,*)zeff_a,zeff_b
	read (2,*)
	read (2,*)sig0
	read (2,*)
	read (2,*)zhib,tego,zalfa,talfa,alp1
	read (2,*)
	read(2,*)ktp,kpin,ken,ken1,ken2,kd2,nal
	read (2,*)
	read(2,*)edop,ppp,eee,dd,dt,dh,df
	read (2,*)
	read(2,*)lt,ld,lh,ll,lm,it,id,ih
	read (2,*)
	read(2,*)eps0,eps1,eps2
	read (2,*)
	read (2,*)anom_e,anom_i,key_t11,kcchp
	read (2,*)
	read (2,*)emoe,emoq
	read (2,*)
	read (2,*)udd
	read (2,*)
	read (2,*)k_ener,k_uv
	read (2,*)
	read (2,*)t_dop
	read (2,*)
	read (2,*)r0,z0,zref
	read (2,*)
	read (2,*)kzref,krref,key_b,i_pf
	read (2,*)
	read (2,*)i_c
	read (2,*)
	read (2,*)q_vde
	read (2,*)
	read (2,*)tay_00,tay_th,t_disr
	read (2,*)
	read (2,*)d_tpl,tpl_end
	read (2,*)
	read (2,*)c_h,d_halo
	read (2,*)
	read (2,*)kmaj,li_drop,ndisrup,n_dif,nmix
	read (2,*)
	read (2,*)hpart,te_h
	read (2,*)
	read (2,*)i_d3d,i_iter,i_smal
	read (2,*)
	read (2,*)ngra,i_ramp,i_v,i_con
	read (2,*)
	read (2,*)tpl,bt0,eu,eksk
	read (2,*)
	read (2,*)e_sep
	read (2,*)
	read (2,*)i_beta,i_gap5
	read (2,*)
	read (2,*)i_br
	read (2,*)
	read (2,*)ind_r,ind_z
	read (2,*)
	read (2,*)key_ef
	read (2,*)
	read (2,*)res_coef
	read (2,*)
	read (2,*)n_polar
c	read (2,*)
c        read (2,*)k_ion,pow_el,pow_ion


	if(kpr.eq.1)then
	   print *,' i_con ===',i_con
	   print *,' key_ef ===',key_ef
	   print *,' res_coef===',res_coef
	   print *,' n_polar===',n_polar
	   print *,' k_ion===',k_ion
	   print *,' pow_el pow_ion===',pow_el,pow_ion
	   print*,'tt=',tt
	   print*,'tpl=',tpl
 	   print *,' -----k_ener t_dop---',k_ener,t_dop              

	   print *,' end for002 reading'
	end if


	call edim1

        if(kpr.eq.1)print *,' CALL ELKE...'
c        read (*,*)

	pnor=6.25e8
	emoe=emoe*pnor
	emoq=emoq*pnor

	ndh=1


	close(2)

c##	mp=(m-2)/2+2
	mp=m
	if(kpr.eq.1)print *,' n m mp',n,m,mp
c	read (*,*)


        rs=r0
        zout=z0
	um=r0
	vm=z0
	rmag=um
	zmag=vm

	if(kpr.eq.1)print *,' um vm eu elong',um,vm,eu,eksk

        if(kmaj.eq.1)then

     	open(unit=2,file='halo',form='formatted')
        if(kpr.eq.1)print *,' begin halo reading'

	read (2,*)
	read (2,*)w_h0,te_h0
        if(kpr.eq.1)print *,' w_h0  te_h0==',w_h0,te_h0
	close(2)

        end if


     	open(unit=2,file='time',form='formatted')
        if(kpr.eq.1)print *,' begin time reading'

	read (2,*)
	read (2,*)t_vde,time_disr
        if(kpr.eq.1)print *,' t_vde time_disr',t_vde,time_disr

	close(2)

	return
	end


	subroutine edim1
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	parameter(np=50001)
	common/eldim/ n1,eki(np),eei(np)
	n=np-1
	n1=n-1
	do i=1,n1
	x=(i-1.)/n1
	call elke(x,ellick,ellice)
	eki(i)=ellick
	eei(i)=ellice
	end do
	eki(n)=eki(n-1)
	eei(n)=eei(n-1)
	eki(n+1)=eki(n-1)
	eei(n+1)=eei(n-1)
	return
	end

	subroutine ellip(x,ek,ee)
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	parameter(np=50001)
	common/eldim/ n1,eki(np),eei(np)
	y=1.+x*n1
	ie=int(y)
	ek=(y-ie)*(eki(ie+1)-eki(ie))+eki(ie)
	ee=(y-ie)*(eei(ie+1)-eei(ie))+eei(ie)
	return
	end
	subroutine elke(x,ellick,ellice)
 	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	t=1.d0-x*x
	dd=dlog(t)
	ellice=((4.0905094d-2*t+8.5099193d-2)*t+0.44479204d0)*t+
     *  1.d0-dd*(((1.382999d-2*t+8.150224d-2)*t+0.24969795d0)*t)
	ellick=((3.2024666d-2*t+5.4544409d-2)*t+9.7932891d-2)*t+
     *  1.3862944d0-dd*(((1.0944912d-2*t+6.0118519d-2)*t+
     *  0.12475074d0)*t+0.5d0)
	return
	end

