                                                                        
	subroutine equil()                                                     
      include 'double.inc'

	include 'new_com.inc'                                                  
                                                                        
	call equil_c(                                                          

     *  k_help,dfmax,dfmax0,bt0,beta,brad,

     *  xbound,ybound,errm,i_en2,key_eq,power_ech,q,
     *  i_ech,q_test,omg_ppx,key_ext,int_2000,it_ext,tokc,i_en3,k_efit,
     *  te0,eps_vel,key_equil,vchopper,pf,i_gen,ajb,betj,i_new,key_ne,
     *  tpl0,i_pres,i_bound,fdd,fdd0,pll,i_exit,n_pas,npf,pfres,tt1,
     *  a,ha,elong,k_dm0,tcam,ncam,udd,pf0)

	return                                                                 

	end                                                                    

                                                                        

                                                                        

                                                                        

	subroutine  equil_c(                                                   

     *  k_help,dfmax,dfmax0,bt0,beta,brad,

     *  xbound,ybound,errm,i_en2,key_eq,power_ech,q,
     *  i_ech,q_test,omg_ppx,key_ext,int_2000,it_ext,tokc,i_en3,k_efit,
     *  te0,eps_vel,key_equil,vchopper,pf,i_gen,ajb,betj,i_new,key_ne,
     *  tpl0,i_pres,i_bound,fdd,fdd0,pll,i_exit,n_pas,npf,pfres,tt1,
     *  a,ha,elong,k_dm0,tcam,ncam,udd,pf0)

      	include 'double.inc'

      dimension xbound(*),ybound(*),q(*),te0(*),vchopper(*),pf(*),
     *  ajb(*),pfres(*),tcam(*),pf0(*)

                                                                        

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


!       call fp_test() 

!      stop

	i_en2=i_en2+1            



        open (unit=1,file='kpr.dat',form='formatted')
        read (1,*)
        read (1,*)kpr

        if(kpr.eq.1)print *,'  kpr ',kpr


      	ARG=1.d0                                     
	  pi=4.d0*datan(ARG) 
	  coef=10.d0/(4.d0*pi)      
	  amu0=0.4*pi

        	call read_data() 
 

	    call anglep_kav()
          call angl_p()
      	  call ONE2()
  	    
  	    call pl_bound()

      i_flat_ext=1
      
!      print *,' i_flat==',i_flat_ext
       
      if(i_flat_ext.eq.1)then
        call flat_ext()

      i_c=0
	call movem(i_c)

      end if

	                                              
	call cur_prof()  

!      call prof_in()
!      call shape_pf() 
!      call shape_tcam() 

      call read_equil()

      do i=1,npf
      pf0(i)=pf(i)
      end do

!     	call ppx_pffx_tab()         

	call lim_mesh()

	call ptoke0() 

      rref=rmag
      zref=zmag

	
1	continue                                                              

                                                                        

!	if(kpr.eq.1)print *,'zref==',zref                                     

                                                                        

	niter=niter+1                                                          

                                                                       
	call ptoke1()                                                          

	rmag_eq=rmag
	zmag_eq=zmag
                                                                        
	if(kpr.eq.1)print *,' --um vm--niter it1',
     *  um,vm,niter,it1           

	a_print(1)=rmag
	a_print(2)=zmag
	a_print(3)=brad
	a_print(4)=bvert
	a_print(5)=niter

	n_pr=5

	apr='rm zm br bz niter'

	num=20

!	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)

                                                                        
	if(it1.ne.0.and.niter.lt.20)go to 1      

      goto 45

      goto 44

!      rref=(0.75*rref+0.25*rmag0)

      rref=rmag
      zref=zmag
      
      print *,' rref zref=',rmag0,zmag0
      print *,' kkk rref zref=',kkk,rref,zref
      
      niter=0

      kkk1=kkk1+1

      kzref=1
      krref=4
      if(kkk1.lt.2)goto 1

!       call write_equil()
       call read_equil()
     
!      stop
 
      rref=rmag+8.
      zref=zmag+5.

44    continue

      kzref=1
      krref=1

 
      niter=0
      
2	continue                                                              

	niter=niter+1                                                          
                                                                       
	call ptoke1()                                                          
                                                                        
	if(kpr.eq.1)print *,' --um vm--niter it1',
     *  um,vm,niter,it1           
                                                                        
	if(it1.ne.0.and.niter.lt.20)go to 2      

45    continue

      kzref=1
      krref=1

         eps2_help=eps2
	   eps2=1.d-6
         call stab(ich,i_graph)

       call  write_surf()

           kzref=0
           krref=0
	   eps2=eps2_help

	call map_tor()
	call eq_res_ps()
      CALL BTA(n,mp,RS0)
		
         call  write_surf()


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

      if(kpr.eq.1)print *,' dr dz=',dr,dz
      if(kpr.eq.1)print *,' x1 y1=',x1,y1
      if(kpr.eq.1)print *,' x1 y1=',x1,y1


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
	return
	end

	subroutine pl_bound()

        include 'double.inc'
	include 'parf0'
	character *20 yy
	common
     *	/n_m/n,m,mp
	common
     *  /keys5/next
	common
     *	/ge1e/rs0,tpl
     *  /ge2/NTAY,TAY,TT
     *	/ge3/AI(npo),A0(npo),HA2(npo),a(npo),ha(npo)
     *  /ge5/kpr
     *	/ge7/eu,rs,zout,eksk
     *  /ge8/pcch
     *  /ge8e/pcchp
	common
     *  /pol4/UM,VM,UK(ntet),VK(ntet)
	common
     *  /eq7e/tet_p(ntet)
        common
     *	/efit6/tpl_p
	common
     *	/point1/r0,z0

c
	do jj=1,mp
	uk(jj)=rs+eu*cos(tet_p(jj))
	vk(jj)=zout+eksk*eu*sin(tet_p(jj))
	end do
	v_min=vk(1)
	v_max=vk(1)
	do j=1,mp
	v_min=amin1(v_min,vk(j))
	v_max=amax1(v_max,vk(j))
	end do

	if(kpr.eq.1)print *,' rs eu eksk',rs,eu,eksk
	if(kpr.eq.1)print *,' v_min v_max',v_min,v_max

	return
	end

	subroutine angl_p()
        include 'double.inc'
c	implicit real *8 (a-h,o-z)
	include 'parf0'
c---
	common
     *	/n_m/n,m,mp
	common
     *	/ge1/pi
     *  /ge5/kpr
	common
     *  /eq7/tet(ntet),ht(ntet)
     *  /eq7e/tet_p(ntet)
	character *12 apr

	mp1=mp-1
	do jj=2,mp
!	j=2.*jj-2
	j=jj
	tet_p(jj)=tet(j)
	end do
	tet_p(1)=tet_p(2)-(tet_p(mp)-tet_p(mp1))
	if(kpr.eq.1)print *,' tet 1 2',tet_p(1),tet_p(2)
	if(kpr.eq.1)print *,' tet mp1 mp',tet_p(mp1),tet_p(mp)
	return
	end

	subroutine anglep()
        include 'double.inc'
c	implicit real *8 (a-h,o-z)
	include 'parf0'
c---
	common
     *	/n_m/n,m,mp
	common
     *	/ge1/pi
     *  /ge5/kpr
	common
     *  /eq6/sinus(ntet),cosin(ntet)
     *  /eq7/tet(ntet),ht(ntet)
	character *12 apr
c---

	m1=m-1
	if(kpr.eq.1)print *,' n m mp m1 pi',n,m,mp,m1,pi
      TETM=2.*PI
      H2=TETM/(M-2)
      DO 15 J=2,M
   15 TET(J)=(J-2)*H2
	tet(1)=tet(m1)
c
      DO 16 J=3,M
   16 HT(J)=TET(J)-TET(J-1)
      HT(2)=HT(M)
c
c  here we change tet(j) dependence.
	alftet=0.95
	alftet1=1./alftet
	kj=3
	kji=kj
	do j=kji,m
	if(tet(j).le.0.5*pi+0.001)then
	ht(j)=ht(j-1)*alftet
c	if(kpr.eq.1)print *,'j tet(j) ht(j)',j,tet(j),ht(j)
	kj=kj+1
	end if
	end do
	ht(kj)=ht(kj-1)
c	if(kpr.eq.1)print *,'j tet(j) ht(j)',kj,tet(kj),ht(kj)
	kj=kj+1
c______________________________________
	kji=kj
	do j=kji,m
	if(tet(j).gt.0.5*pi.and.tet(j).le.pi+0.001)then
	ht(j)=ht(j-1)*alftet1
c	if(kpr.eq.1)print *,'j tet(j) ht(j)',j,tet(j),ht(j)
	kj=kj+1
	end if
	end do
	ht(kj)=ht(kj-1)
c	if(kpr.eq.1)print *,'j tet(j) ht(j)',kj,tet(kj),ht(kj)
	kj=kj+1
c______________________________________
	kji=kj
	do j=kji,m
	if(tet(j).gt.pi.and.tet(j).le.1.5*pi+0.001)then
	ht(j)=ht(j-1)*alftet
c	if(kpr.eq.1)print *,'j tet(j) ht(j)',j,tet(j),ht(j)
	kj=kj+1
	end if
	end do
	ht(kj)=ht(kj-1)
c	if(kpr.eq.1)print *,'j tet(j) ht(j)',kj,tet(kj),ht(kj)
	kj=kj+1
c______________________________________
	kji=kj
	do j=kji,m
	if(tet(j).gt.1.5*pi)then
	ht(j)=ht(j-1)*alftet1
c	if(kpr.eq.1)print *,'j tet(j) ht(j)',j,tet(j),ht(j)
	kj=kj+1
	end if
	end do
c	if(kpr.eq.1)print *,'kj=',kj
c
	tetsum=0.
	do j=3,m
	tetsum=tetsum+ht(j)
	end do
	alftet=(2.*pi/tetsum)
c	if(kpr.eq.1)print *,'alftet=',alftet
	do j=3,m
	ht(j)=ht(j)*alftet
	tet(j)=tet(j-1)+ht(j)
	end do
	tet(1)=tet(m1)
	ht(2)=ht(m)
c______________________________________
	tetsum=0.
	do j=3,m
	tetsum=tetsum+ht(j)
	end do
	alftet=(2.*pi/tetsum)
c	if(kpr.eq.1)print *,'alftet=',alftet
	apr='tet(j)'
c	if(kpr.eq.1)print 71,apr,(tet(j),j=1,m)
c
c==========================
	do j=1,m
	sinus(j)=sin(tet(j))
	cosin(j)=cos(tet(j))
	end do
c================================
	apr='cos(j)'
c	if(kpr.eq.1)print 71,apr,(cosin(j),j=1,m)
c
	apr='sin(j)'
c	if(kpr.eq.1)print 71,apr,(sinus(j),j=1,m)
	return
	end
	subroutine anglep_kav()
	include 'double.inc'
c	implicit real *8 (a-h,o-z)                                            
	include 'parf0'                                                        
c---                                                                    
	common                                                                 
     *	/n_m/n,m,mp                                                      
	common                                                                 
     *	/ge1/pi                                                          
     *  /ge5/kpr                                                        
	common                                                                 
     *  /eq6/sinus(ntet),cosin(ntet)                                    
     *  /eq7/tet(ntet),ht(ntet)                                         
	character *30 apr                                                      
	dimension a_print(200)
c---                                                                    
                                                                        
	m1=m-1                                                                 
!	if(kpr.eq.1)print *,' n m mp m1 pi',n,m,mp,m1,pi                      
      TETM=2.*PI                                                        
      H2=TETM/(M-2)                                                     
      DO 15 J=2,M                                                       
   15 TET(J)=(J-2)*H2                                                   
	tet(1)=tet(m1)                                                         
c                                                                       
      DO 16 J=3,M                                                       
   16 HT(J)=TET(J)-TET(J-1)                                             
      HT(2)=HT(M)                                                       
c                                                                       
c  here we change tet(j) dependence.    

	tet_sep=pi+0.645*0.5*pi
	d_tet_sep=0.4*pi

	a_print(1)=tet_sep
	a_print(2)=d_tet_sep
	a_print(3)=pi
	apr=' ** tet_sep  d_tet_sep pi**'

	n_pr=3

	num=25

c	call out42(n_pr,a_print,num,apr)




                                
c	alftet=0.85                                                            
	alftet=1.d0                                                            
	alftet1=1.d0/alftet                                                      

	do j=3,m                                                             
	if(tet(j).gt.tet_sep-d_tet_sep.and.tet(j).le.tet_sep)then                                         
	ht(j)=ht(j-1)*alftet                                                   

	end if                                                                 

	if(tet(j).lt.tet_sep+d_tet_sep.and.tet(j).gt.tet_sep)then                        
	ht(j)=ht(j-1)*alftet1                                                  



	end if   
	                                                              



	end do                                                                 

	tetsum=0.                                                              
	do j=3,m                                                               
	tetsum=tetsum+ht(j)                                                    
	end do                                                                 
	alftet=(2.*pi/tetsum)                                                  
c	print *,'alftet=',alftet                                              
	do j=3,m                                                               
	ht(j)=ht(j)*alftet                                                     
	tet(j)=tet(j-1)+ht(j)  
	
	a_print(1)=j
	a_print(2)=tet(j)
	a_print(3)=ht(j)
	apr=' ** j tet ht**'

	n_pr=3

	num=25

c	call out42(n_pr,a_print,num,apr)


	                                                
	end do                                                                 
	tet(1)=tet(m1)                                                         
	ht(2)=ht(m)                                                            
c______________________________________                                 
	tetsum=0.                                                              
	do j=3,m                                                               
	tetsum=tetsum+ht(j)                                                    
	end do                                                                 
	alftet=(2.*pi/tetsum)                                                  
c	print *,'alftet=',alftet                                              
	apr='tet(j)'                                                           
c	print 71,apr,(tet(j),j=1,m)                                           
c                                                                       
c==========================                                             
	do j=1,m                                                               
	sinus(j)=dsin(tet(j))                                                   
	cosin(j)=dcos(tet(j))                                                   
	end do                                                                 
c================================                                       
	apr='cos(j)'                                                           
c	print 71,apr,(cosin(j),j=1,m)                                         
c                                                                       
	apr='sin(j)'                                                           
c	print 71,apr,(sinus(j),j=1,m)                                         
	return                                                                 
	end                                                                    

      SUBROUTINE ONE2()
c-------------------------------------
c   initial values and profiles
c-----------------------------------
        include 'double.inc'
c	implicit real*8 (a-h,o-z)
	include 'parf0'
	common
     *	/n_m/n,m,mp
      COMMON
     *	/ge3/AI(npo),A0(npo),HA2(npo),a(npo),ha(npo)
     *  /ge5/kpr
	common
     *	/pol1/ro(npo,ntet),aj(npo,ntet)
     *	/pol3/Ax(npo),TET(ntet),HAx(npo),HT(ntet)
	character *12 apr

c
c
      AI(1)=0.
      HA(1)=0.
      N1=N-1
      M1=M-1
      A0(1)=0.
      A(1)=0.
      A0(2)=0.

      DO 11 I=2,N

	xx=i-1.5
	a(i)=xx/(n-1.5)

!	xx=i-1.d0                                                               
!	a(i)=xx/(n-1.d0)                                                        

	a0(i)=a(i)


c	a(i)=(1.-dexp(-alf*a(i)))/(1.-dexp(-alf))
c     	a(i)=a(i)**(1.5-0.5*a(i))*(1.-dexp(-alf*a(i)))/(1.-dexp(-alf))
c	a(i)=a(i)**(1.5-0.5*a(i))
c	a(i)=(i-1.)/(n2-1)*0.995
c      A(I)=SQRT(A(I))
	ha(i)=a(i)-a(i-1)
   11 CONTINUE
c	alf=0.95
	alf=0.95d0
!	alf=1.
	do i=2,n
	if(i.ge.n/2)ha(i)=ha(i-1)*alf
	end do
c	do i0=2,n
c	i=n-i0+2
c	if(i.le.n/3)ha(i-1)=ha(i)*alf
c	end do
	sum=0.
	do i=2,n
	sum=sum+ha(i)
	end do
	al1=1./sum
	do i=2,n
	ha(i)=ha(i)*al1
	a(i)=a(i-1)+ha(i)
	end do
c
      A(N)=1.
	apr='a(i)'
	if(kpr.eq.1)print 71,apr,(a(i),i=1,n)
c
      DO 1 I=2,N
	a0(i)=a(i-1)
      HA(I)=A(I)-A(I-1)
    1 CONTINUE
	apr='ha'
	if(kpr.eq.1)print 71,apr,(ha(i),i=1,n)
	ai(2)=0.
      DO 31 I=3,N
      AI(I)=0.5*(A(I)+A(I-1))
	ha2(i-1)=ai(i)-ai(i-1)
31	continue
	ai(2)=0.5*a(2)
      HA2(N)=a(n)-ai(n)
	apr='ai'
	if(kpr.eq.1)print 71,apr,(ai(i),i=1,n)
	apr='ha2'
	if(kpr.eq.1)print 71,apr,(ha2(i),i=1,n)
	do i=1,n
	ax(i)=a(i)
	hax(i)=ha(i)
	end do
	apr='hax'
	if(kpr.eq.1)print 71,apr,(hax(i),i=1,n)
c
c   initial ro(i,j)
	do i=1,n
	do j=1,m
	ro(i,j)=a(i)
	end do
	end do
c
c==========================
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))
101	continue
      RETURN
      END

	subroutine cur_prof()
        include 'double.inc'
	include 'parf0'
	common
     *	/n_m/n,m,mp
	common
     *	/ge1e/rs0,tpl
     *	/ge3/AI(npo),A0(npo),HA2(npo),a(npo),ha(npo)
     *  /ge5/kpr
     *  /ge6/zeff(npo),qpr(npo),ppr(npo),pr0,prg,zar
     *  /ge6e/zeff_a,zeff_b
	common
     *  /pol6/ppx(npo),pffx(npo)
	common
     *	/efit0/kefit
     *	/efit1/alfax(2),betax(2)
     *	/efit2/alfa0,beta,alfa1
     *	/efit3/pw_1,pw_2
	common
     *  /dfm4/Q(npo),ANU(npo),P(npo),F(npo),PP(npo),PFF(npo)
	common
     *  /en1/PNE(npo),PD0(npo),PT0(npo),PH0(npo),PDN(npo),
     *  PTN(npo),PHN(npo)
     *  /en1e/te_a,ti_a,te_b,ti_b,pw_e
     *  /en2e/pd0_a,pt0_a,pd0_b,pt0_b,pw_p
     *  /en2/TE0(npo),TQ0(npo),TEN(npo),TQN(npo),WE0(npo),
     *  WQ0(npo)

	character *20 yy,apr

	if(kpr.eq.1)print *,' alfa0 beta alfa1 rs0',alfa0,beta,alfa1,rs0

	if(kpr.eq.1)print *,' KEFIT++++++++++++++++',kefit

	do i=1,n
c____________________________________________________
	xpsi=a(i)**2
	if(kEFIT.eq.1) then
        ppx(i)=alfax(1)+alfax(2)*xpsi-(alfax(1)+alfax(2))*xpsi**2
	ppx(i)=-alfa0*ppx(i)*rs0*1.e-2
	pffx(i)=betax(1)+betax(2)*xpsi-
     *  (betax(1)+betax(2))*xpsi**2
	pffx(i)=-alfa0*2.*pffx(i)/(rs0*1.e-2)
	end if
c________________________________________________
	if(kEFIT.eq.0) then
	ppx(i)=-alfa0*beta*(1.-a(i)**pw_1)
	pffx(i)=-2.*alfa0*(1.-beta)*(1.-a(i)**pw_1)**pw_2
	end if
c
	if(kEFIT.eq.2) then
	expa=exp(alfa1)
	expx=exp(alfa1*(1.-xpsi))
	expon=(expx-1.)/(expa-1.)
	ppx(i)=-alfa0*beta*expon
	pffx(i)=-2.*alfa0*(1.-beta)*expon
	end if
	end do
c
	ppx(1)=ppx(2)
	pffx(1)=pffx(2)

	do i=1,n
	psix=a(i)
c	pd0(i)=pd0_b+(1.-psix**pw_p)*(pd0_a-pd0_b)
c	pt0(i)=pt0_b+(1.-psix**pw_p)*(pt0_a-pt0_b)
        ppp=1.
	pd0(i)=pd0_b+((1.-psix**pw_p))**ppp*(pd0_a-pd0_b)
!	pt0(i)=pt0_b+((1.-psix**pw_p))**ppp*(pt0_a-pt0_b)
	pne(i)=pd0(i)+pt0(i)
	te0(i)=te_b+(1.-psix**pw_e)*(te_a-te_b)
	tq0(i)=ti_b+(1.-psix**pw_e)*(ti_a-ti_b)
     	zeff(i)=zeff_a+(zeff_b-zeff_a)*psix
	end do


	apr='ppx'
	if(kpr.eq.1)print 71,apr,(ppx(j),j=1,n)
	apr='pffx'
	if(kpr.eq.1)print 71,apr,(pffx(j),j=1,n)


c        pause 'from cur_prof'



71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

	i=n
	p(i)=(te0(i)+tq0(I))*(pd0(i)+pt0(I))*200.*1.e-6
	yy='te0'
c	call prof(te0,a,n,yy)
	yy='tq0'
c	call prof(tq0,a,n,yy)
	yy='pne'
c	call prof(pne,a,n,yy)
	yy='pd0'
c	call prof(pd0,a,n,yy)
	yy='pt0'
c	call prof(pt0,a,n,yy)

	return
	end


	subroutine feet_p(n,PSI,aval,x,xp)
        include 'double.inc'
	DIMENSION psi(n),x(n)
c
	n1=n-1

	do i=1,n1
	if( (xp-x(i+1))*(xp-x(i)).gt.0.)go to 11
c
	if(i.ne.1) then
	call fit_p(psi,x,n,i,xp,aval)
	return
	end if
c
	if( i.eq.1) then
	call fit_p(psi,x,n,i+1,xp,aval)
	return
	end if
11	continue
	end do
	return
	end
	subroutine fit_p(f,ai,n,i,x,y)
        include 'double.inc'
        common
     *  /ge5/kpr
c---------------------------------------------
c  quadratic polinomial interpolation for array
c  from transport to equilibrium
c-----------------------------------------------
c       implicit real*8 (a-h,o-z)

	dimension f(n),ai(n)

	data err /1.e-14/

	delt=ai(i+1)**2*ai(i)+ai(i)**2*ai(i-1)+
     *  ai(i-1)**2*ai(i+1)-
     *  ai(i-1)**2*ai(i)-ai(i)**2*ai(i+1)-ai(i+1)**2*ai(i-1)

	if(abs(delt).lt.err)then
	   if(kpr.eq.1)print *,' i ai',i,ai(i-1),ai(i),ai(i+1)

 	call linear(n,f,y,ai,x)

	return
	end if


	aak=(f(i+1)*ai(i)+f(i)*ai(i-1)+f(i-1)*ai(i+1)-
     *  f(i-1)*ai(i)-f(i)*ai(i+1)-f(i+1)*ai(i-1))/delt

	bbk=(ai(i+1)**2*f(i)+ai(i)**2*f(i-1)+ai(i-1)**2
     *  *f(i+1)-
     *  ai(i-1)**2*f(i)-ai(i)**2*f(i+1)-ai(i+1)**2
     *  *f(i-1))/delt

	cck=f(i)-aak*ai(i)**2-bbk*ai(i)

	y=aak*x*x+bbk*x+cck

	return
	end


 	subroutine linear(n,PSI,aval,x,xp)
        include 'double.inc'
c	implicit real *8 (a-h,o-z)
	dimension  psi(n),x(n)
c
	n1=n-1
c
	do i=1,n1
	if( (xp-x(i+1))*(xp-x(i)).gt.0.)go to 11
c
	aval=psi(i)+(xp-x(i))*(psi(i+1)-psi(i))/(x(i+1)-x(i))

11	continue
	end do
	return
	end
	subroutine feeti(n,PSI,aval,x,xp)
        include 'double.inc'
	DIMENSION psi(n),x(n)
c
	n1=n-1
c
c
	do i=1,n1
	if( (xp-x(i+1))*(xp-x(i)).gt.0.)go to 11
c
	if( (i-1)*(i-n1).lt.0) then
	call fit(1,x(i-1),x(i),x(i+1),x(i+2),psi(i-1),
     *  psi(i),psi(i+1),psi(i+2),xp,aval,yq)
	return
	end if
c
	if( i.eq.1) then
	call fit(1,x(i),x(i+1),x(i+2),x(i+3),psi(i),
     *  psi(i+1),psi(i+2),psi(i+3),xp,aval,yq)
	aval=aval
	yq=yq
	return
	end if
c
	if( i.eq.n1) then
	call fit(1,x(i-2),x(i-1),x(i),x(i+1),psi(i-2),
     *  psi(i-1),psi(i),psi(i+1),xp,aval,yq)
	aval=aval
	yq=yq
	end if
11	continue
	end do
	return
	end

	subroutine pau()
	include 'double.inc'

	return
	end

	subroutine inv_gen()
c---------------------------------------
        include 'double.inc'
c	implicit real*8 (a-h,o-z)
	include 'parf1'
c
	common
     *  /ge2/NTAY,TAY,TT
     *  /ge5/kpr
	common
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves3/b(mu,mu),pmj(mu,mu)
     *  /ves4/rcam(mu)
     *  /ves5/pfc(mu,kf)

	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)

	common
     *  /gen1/n_gen
     *  /gen2/a1_gen(mu,mu)
     *  /gen3/a_gen(mu,mu)
     *  /gen6/d0(mu),d1(mu),d2(mu)

        character *12 apr
c
	dimension a(mu,mu),d(mu,mu),ed(mu,mu),a_1(mu,mu)
        
        real *8 a,d,a_1

c--------------------------------------
	do i=1,ncam
	do j=1,ncam
	a(i,j)=pmj(i,j)
	a_gen(i,j)=pmj(i,j)
	end do
	a(i,i)=a(i,i)+tay*rcam(i)*1.e5
	end do

c  here we add PF coils staff....

	do i=1,ncam
	do j=1,npf
	a(i,ncam+j)=pfc(i,j)
	a_gen(i,ncam+j)=pfc(i,j)
	end do
	end do
c
	do i=1,npf
	do j=1,ncam
	a(i+ncam,j)=pfc(j,i)
	a_gen(i+ncam,j)=pfc(j,i)
	end do
	end do
c
	do i=1,npf
	do j=1,npf
	a(i+ncam,j+ncam)=pfind(i,j)
	a_gen(i+ncam,j+ncam)=pfind(i,j)
	end do
	a(i+ncam,i+ncam)=a(i+ncam,i+ncam)+tay*pfres(i)*1.e5
	end do

        n_gen=ncam+npf
c
c!!!	call obrm(a,a1_gen,d,mu,n_gen)
	call obrm_8(a,a_1,d,mu,n_gen)

	if(kpr.eq.1)print*,'o ++ kay GEN n_gen',n_gen

 	do i=1,n_gen
	do j=1,n_gen
	a1_gen(i,j)=a_1(i,j)
	end do
	end do
c
 	do i=1,n_gen
	do j=1,n_gen
	ed(i,j)=0.
	do k=1,n_gen
	ed(i,j)=ed(i,j)+a(i,k)*a1_gen(k,j)
	end do
	end do
	end do

	apr='e{i} (GEN) [inv]'
	if(kpr.eq.1)print 71,apr,(ed(i,i),i=1,n_gen)
	apr='e{j} (GEN) [inv]'
	do j=1,2
	if(kpr.eq.1)print *,'j=',j
	if(kpr.eq.1)print 71,apr,(ed(j,i),i=1,n_gen)
	end do

	do j=n_gen-1,n_gen
	if(kpr.eq.1)print *,'j=',j
	if(kpr.eq.1)print 71,apr,(ed(j,i),i=1,n_gen)
	end do


c        read (*,*)
c        stop

71	format(20x,a70/,(6(1x,1pe10.3)))
	return
	end



	subroutine stab(ich_xx,i_graph_xx)
      	include 'double.inc'

	include 'new_com.inc'



	call stab_c(ich_xx,i_graph_xx,

     *  rref,zref,bvert,brad,it1,dx,dy,

     *  rmag,zmag,pmag,psep,zsep,kpr)

      

	return

	end





	subroutine stab_c(ich,i_graph,

     *  rl,zl,clr,clz,it1,dx,dy,

     *  rmag,zmag,pmag,psep,zsep,kpr)

      	include 'double.inc'


	character *30 apr

	dimension a_print(200)



	pbound=psep

	iter=0

!	ceps=0.1

c	ceps=0.02

	ceps=0.02

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	n_pr=4

	apr=' clr clz zl rl ENTER '

	num=30

	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)


 1000	continue

      

	it1=1





	if(ich.eq.0) then  


	   rl0=rl                                

	   zl0=zl                                

	 

	   clr0=clr                              

	   clz0=clz                              

                                                       

	   ddzl=dy*ceps



	   zl=zl0+ddzl                            

	   int_it=0

	   if(kpr.eq.1)print *,' ich== rl0 zl0',ich,rl0,zl0
	   if(kpr.eq.1)print *,' ich== rl zl',ich,rl,zl


 1	   continue

	   int_it=int_it+1

c	      call cur_prof()

	      call ptoke1()

	      if(int_it.gt.40)it1=0

	      if(it1.eq.1)go to 1

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	a_print(5)=ich

	a_print(6)=int_it

	a_print(7)=iter

	n_pr=6

	apr=' clr clz zl rl ich int '

	num=30

	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)

      ich=ich+1                             


	endif                                   



	it1=1



	if(kpr.eq.1)print *,' ich==',ich



c	if(i_graph.eq.1)call graphic(it1,n)

                                                       

	if(ich.eq.1) then  

	   clr1=clr                              

	   clz1=clz                              

	   ddrl=dx*ceps



!!!	   rl=rl+ddrl
	   rl=rl0+ddrl

	   zl=zl0  

	   if(kpr.eq.1)print *,' ich== rl0 zl0',ich,rl0,zl0
	   if(kpr.eq.1)print *,' ich== rl zl',ich,rl,zl
	                                 
	   int_it=0

 2	   continue

	   int_it=int_it+1

c	      call cur_prof()

	      call ptoke1()

	      if(int_it.gt.40)it1=0

	   if(it1.eq.1)go to 2

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	a_print(5)=ich

	a_print(6)=int_it

	a_print(7)=iter

	n_pr=6

	apr=' clr clz zl rl ich int '

	num=30

	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)

      ich=ich+1                             

	endif                                   



c	if(i_graph.eq.1)call graphic(it1,n)


                                                       

	if(kpr.eq.1)print *,' ich==',ich



	if(ich.eq.2) then  





	   dcrdr=(clr-clr0)/ddrl                 

	   dczdr=(clz-clz0)/ddrl                 



	   if(kpr.eq.1)print *,' clr clr0  ddrl',clr,clr0,ddrl

	   if(kpr.eq.1)print *,' clz clz0  ddrl',clz,clz0,ddrl



                 

	   dcrdz=(clr1-clr0)/ddzl                

	   dczdz=(clz1-clz0)/ddzl                

                 

	   if(kpr.eq.1)print *,' clr1 clr0  ddzl',clr1,clr0,ddzl

	   if(kpr.eq.1)print *,' clz1 clz0  ddzl',clz1,clz0,ddzl



	   det=dcrdr*dczdz-dczdr*dcrdz           

               

	   if(kpr.eq.1)then

	   print *,' det dcrdr dczdz dczdr dcrdr',

     *      det,dcrdr,dczdz,dczdr,dcrdr

	   end if



      delrl0=delrl
	delzl0=delzl
	
	         

	   delrl= (clz0*dcrdz-clr0*dczdz)/det       

	   delzl= (clr0*dczdr-clz0*dcrdr)/det       

	if(iter.gt.2)then
c	delrl=0.5d0*(delrl+delrl0)
c	delzl=0.5d0*(delzl+delzl0)
	end if


	   if(kpr.eq.1)print *,' delrl delzl',delrl,delzl

                                                       

	   dll=sqrt(delrl**2 + delzl**2)           

	 

	   dllim=0.5*sqrt(dx**2+dy**2)

                          

	   if(kpr.eq.1)print *,' dll dllim',dll,dllim

	a_print(1)=delrl

	a_print(2)=delzl

	a_print(3)=dll

	a_print(4)=dllim

	a_print(5)=dcrdr

	a_print(6)=dczdr

	a_print(7)=dcrdz

	a_print(8)=dczdz



	n_pr=8

	apr=' delr delz dll dllim dcrdr dczdr dcrdz dczdz '

	num=30

	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)


	   if(dll .gt. dllim) then                  

                                                       

	      nstp=dll/dllim                       
            
            al1=0.5*dllim/dll 

!            al1=1.*dllim/dll 

!	      ddrr=delrl/nstp                      

!	      ddzz=delzl/nstp                      

	      ddrr=delrl*al1                      

	      ddzz=delzl*al1                      

!	      ddrr=0.5*(delrl+delrl0)*al1                      

!	      ddzz=0.5*(delzl+delzl0)*al1                      


	      if(nstp.ge.5)nstp=5

c	      if(nstp.ge.2)nstp=2

c	      if(nstp.ge.50)nstp=50


            nstp=1
	      do  istep=1,nstp                  

                                                       

          if(kpr.eq.1)write(6,*) 'slow shift',istep,nstp   

                                                       

		 rl=rl0+ ddrr*istep                   

		 zl=zl0+ ddzz*istep

            if(kpr.eq.1)print *,' -- RL RL0=',rl,rl0
            if(kpr.eq.1)print *,' -- ZL ZL0=',zl,zl0


		 it1=1




	   int_it=0


 3		 continue

		 int_it=int_it+1

c		    call cur_prof()

		    call ptoke1()

		    if(int_it.gt.40)it1=0

		    if(it1.eq.1)go to 3



c	if(i_graph.eq.1)call graphic(it1,n)

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	a_print(5)=istep

	a_print(6)=int_it


	n_pr=6

	apr=' CLR  CLZ zl rl ISTEP int '

	num=30

	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)



	      end do

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	a_print(5)=ich

	a_print(6)=int_it

	a_print(7)=iter

	n_pr=6

	apr=' clr clz zl rl ich int '

	num=30

	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)
		

	   else                                     

                                                       

	      rl=rl0+ delrl                         

	      zl=zl0+ delzl

            if(kpr.eq.1)print *,' RL RL0=',rl,rl0
            if(kpr.eq.1)print *,' ZL ZL0=',zl,zl0


	      it1=1



	   int_it=0



 4	      continue

	      int_it=int_it+1

c		 call cur_prof()

		 call ptoke1()

		 if(int_it.gt.40)it1=0

		 if(it1.eq.1)go to 4



c	if(i_graph.eq.1)call graphic(it1,n)

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	a_print(5)=ich

	a_print(6)=int_it

	a_print(7)=iter

	n_pr=6

	apr=' clr clz zl rl ich int '

	num=30

	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)


	   endif                                    


	   ich=0


	endif                                    



c	ceps=ceps*0.5



        crz=abs(clr*rmag/(pmag-pbound))+

     *  abs(clz*(zmag-zsep)/(pmag-pbound))



	

	iter=iter+1



	if(kpr.eq.1)print *,' ITER pmag pbound zsep==',pmag,pbound,zsep

	if(kpr.eq.1)print *,' ITER clr clz crz==',iter,clr,clz,crz




	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=iter

	n_pr=3

	apr=' clr clz iter'

	num=30

	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)

	if(abs(crz).gt.1.d-5.and.iter.le.95)go to 1000
!	if(abs(crz).gt.1.d-5.and.iter.le.10)go to 1000

c	if(abs(crz).gt.1.d-5)go to 1000

c	if(dabs(crz).gt.1.d-3)go to 1000



	a_print(1)=crz

	a_print(2)=clr

	a_print(3)=clz

	a_print(4)=zl

	a_print(5)=rl

	a_print(6)=iter

	n_pr=6

	apr='crz clr clz zl rl ITER'

	num=20

	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)

c	stop

                                                       

	return

	end

	subroutine ppx_pffx_tab()      
	include 'double.inc'
	include 'new_com.inc'                                                   
                                                                        
         call ppx_pffx_tab_c(                                           
     *   nutab,                                                         
     *   pstab,pptab,fptab,                                             
     *   n,ppx,pffx,a,kpr)                                              
                                                                        
         return                                                         
         end                                                            
                                                                        
         subroutine ppx_pffx_tab_c(                                     
     *   nutab,                                                         
     *   pstab,pptab,fptab,                                             
     *   n,ppx,pffx,a,kpr)                                              
        include 'double.inc'              
                                                                        
         dimension pstab(*),pptab(*),fptab(*),                          
     *   ppx(*),pffx(*),a(*)                                            
                
                
       	character *30 apr 

      	dimension a_print(200)
                                                        
	 nutab=n                                                               
                
      a_print(1)=n
      n_pr=1      
      num=20
      apr='n=='
      
!	call out42(n_pr,a_print,num,apr)
             
                                                                        
!	 if(kpr.eq.1)print *,' n nutab==',n,nutab                             
                                                                        
	do i=1,n                                                               
	   pstab(i)=a(i)                                                       
	   pptab(i)=ppx(i)                                                     
	   fptab(i)=pffx(i)                                                    
	end do                                                                 
                                                                        
	return                                                                 
	end                                                                    
	subroutine lim_mesh() 
    	include 'double.inc'
	include 'new_com.inc'                                                  
                                                                        
	call lim_mesh_c(                                                       
     *  kex,xue,yue,                                                    
     *  nr,nz,x,y)                                                      
                                                                        
        return                                                          
        end                                                             
                                                                        
	subroutine lim_mesh_c(                                                 
     *  kex,xue,yue,                                                    
     *  nr,nz,x,y)                                                      
          include 'double.inc'              
        dimension xue(*),yue(*),x(*),y(*)                               
                                                                        
c  new quasy limiter kex, xue, yue ...                                  
                                                                        
	xue(1)=x(nr-2)                                                         
	yue(1)=y(nz-2)                                                         
	xue(2)=x(3)                                                            
	yue(2)=y(nz-2)                                                         
	xue(3)=x(3)                                                            
	yue(3)=y(3)                                                            
	xue(4)=x(nr-2)                                                         
	yue(4)=y(3)                                                            
	xue(5)=xue(1)                                                          
	yue(5)=yue(1)                                                          
                                                                        
	kex=5                                                                  
                                                                        
        return                                                          
        end                                                             
      subroutine fp_test() 
 	include 'double.inc'
 	
 	 x1 =   300.00000000000000 
 	 y1 =   -600.00000000000000     
       xn=    900.00000000000000
       ym =   600.00000000000000     
       
       r0=    588.00000000000000       
       z0=   0.0000000000000000
 
     	fpl1=fp(r0,x1,z0,y1)
     	fpl2=fp(r0,xn,z0,ym)

	if(kpr.eq.1)print *,'x1 y1 = ',x1,y1
	if(kpr.eq.1)print *,'xn ym = ',xn,ym
	if(kpr.eq.1)print *,'fpl1 fpl2 = ',fpl1,fpl2

 
 
      return
      end


      SUBROUTINE IS1(F,R,Z)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	include 'parf1'
      COMMON
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf2/RR(nmax,KF),ZZ(nmax,KF),pw(nmax,kf)
     *  /pf3/nmx(kf),turn(kf)
c
	dimension f(kf)
c
	do i=1,npf
	f(i)=0.
	end do
	do i=1,npf
	do j=1,NMX(i)
      F(i)=F(i)+pw(j,i)*FP(RR(j,I),R,ZZ(j,I),Z)
	end do
	end do
      RETURN
      END
      SUBROUTINE BISA(BRR,BZZ,R,Z)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	include 'parf1'
      COMMON
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf2/RR(nmax,KF),ZZ(nmax,KF),pw(nmax,KF)
     *  /pf3/nmx(kf),turn(kf)
	DIMENSION BRR(KF),BZZ(KF)
c

      DO  I=1,npf
	BRR(I)=0.
	BZZ(I)=0.
	do j=1,NMX(i)
      CALL BRZ(BR0,BZ0,R,RR(j,I),Z,ZZ(j,i))
      BR=BR0*pw(j,i)
      BZ=BZ0*pw(j,i)
	BRR(I)=BR+BRR(I)
	BZZ(I)=BZ+BZZ(I)
	end do
	end do
c
      RETURN
      END
