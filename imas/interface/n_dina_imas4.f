	subroutine flat_ext_read_c(
     *  nwnh,nr,nz,npf,ncam,
     *  fluxarr,vesarr,
     *  kf,mu,pfind,pfc,pmj,pfres,rcam,
     *  xu,yu,ke,
     *  nloop,nprobe,kloop,kprobe,
     *  pfgreen,vesgreen,
     *  pfprobe,vesprobe,
     *  pslgreen,bprgreen,
     *  x,y)                       

	include 'double.inc'

	dimension fluxarr(nwnh,*),
     *  vesarr(nwnh,*),
     *  pfind(kf,*),pfc(mu,*),pmj(mu,*),pfres(*),rcam(*),
     *  xu(*),yu(*),
     *  pfgreen(nloop,*),vesgreen(nloop,*),
     *  pfprobe(nprobe,*),vesprobe(nprobe,*),
     *  pslgreen(nwnh,*),bprgreen(nwnh,*),                       
     *  x(*),y(*)                       

	dimension ttt(500)

	character *200 f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,
     * f11,f12,f13,f14,f15,f16
c


      kpr=0
      
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
!		     pmj(k,kk)=pmj(k,kk)*1.d8    
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
!	pfc(k,kk)=pfc(k,kk)*1.d8
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

!	print *,'k pf_res ',k,pfres(k)

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

!	print *,'k rcam ',k,rcam(k)

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
!		  pfind(k,kk)=pfind(k,kk)*1.d8                                       
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
!		  vesarr(kk,k)=vesarr(kk,k)*1.d8 
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
!	   fluxarr(kk,k)=fluxarr(kk,k)*1.d8
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
!	   pslgreen(kk,k)=pslgreen(kk,k)*1.d8

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
!	   pfgreen(k,kk)=pfgreen(k,kk)*1.d8 

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
!	   vesgreen(k,kk)=vesgreen(k,kk)*1.d8 

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
!		 bprgreen(kk,k)=bprgreen(kk,k)*1.d4

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
!		 pfprobe(k,kk)=pfprobe(k,kk)*1.d4
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
!		 vesprobe(k,kk)=vesprobe(k,kk)*1.d4
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

	   !xu(k)=xu(k)*100.d0                                                

	   !yu(k)=yu(k)*100.d0                                                

c        write(41,*)' k xu yu ',k,xu(k),yu(k)                            

	end do                                                                 


	z0=z_l

	zk=z_r

                                                                        

	r0=r_l

	rk=r_r

                                                                     

	dz=(zk-z0)/(nz-1.)                                                    

	dr=(rk-r0)/(nr-1.)                                                    

c----                                                                   

	do i=1,nr                                                             

	x(i)=r0+(i-1)*dr                                                      

	end do                                                                 

                                                                        

	do j=1,nz                                                             

	y(j)=z0+(j-1)*dz                                                      

	end do                                                                 

                                                                        

	dx=dr                                                                  

	dy=dz                                                                  

                                                                        

c!        write(41,*)' nre nze ',nre,nze                                  

                                                                        

c!        write (41,*)' dx dy ',dx,dy                                     

                                                                        

	if(kpr.eq.1)print *,'z1,   zk,    r1,     rk'
	if(kpr.eq.1)print *,y(1),y(nz),x(1),x(nr)


	return
	end


