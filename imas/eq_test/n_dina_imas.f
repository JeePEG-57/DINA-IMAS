!> dina_v96_in is the subroutine to write Green Functions from IDSs to DINA in DINA units

        subroutine  dina_v96_in(

     *  ncam_mat,npf_mat,kloop_mat,kprobe_mat,

     *  gridrange,

     *  kf_mat,mu_mat,

     *  fluxarr_mat,vesarr_mat,

     *  pslgreen_mat,bprgreen_mat,

     *  pfind_mat,pmj_mat,pfc_mat,

     *  pfres_mat,rcam_mat,        

     *  xu_mat,yu_mat,ke_mat,key_mat,

     *  pfgreen_mat,vesgreen_mat,

     *  pfprobe_mat,vesprobe_mat,ngrid2)

        include 'double.inc'

        include 'parf2'

                                         
        real*8 fluxarr_mat(ngrid2,*),vesarr_mat(ngrid2,*),  

     *  pslgreen_mat(ngrid2,*),bprgreen_mat(ngrid2,*),       

     *  pfind_mat(kf_mat,*),pmj_mat(mu_mat,*),                           

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

                                                                        

c       implicit real *8 (a-h,o-z)                                            

                                                                        

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

     *  /loop1/kloop,rl(nloop),zl(nloop),psloop(nloop)                   

     *  /loop2/pfgreen(nloop,kf),vesgreen(nloop,mu)                     

     *  /loop5/pslgreen(nwnh,nloop)                                      

                                                                        

        common                                                                 

     *  /probe1/kprobe,bprobe(nprobe)                                    

     *  /probe2/pfprobe(nprobe,kf),vesprobe(nprobe,mu)                  

     *  /probe4/bprgreen(nwnh,nprobe)                                    

                                                                        

        common                                                                 

     *  /eq2/ke,xu(mu_l),yu(mu_l)                                       



        common

     *  /c_add0/i_en0

     *  /c_add2/i_en2

     *  /c_add3/i_en3

     *  /c_add7/i_en4


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

                                                                        

!        write(41,*)' nre nze ',nre,nze                                  

                                                                        

!        write (41,*)' dx dy ',dx,dy                                     

                                                                        

                                                                        

        do i=1,nr                                                              

        x(i)=re(i)                                                             

!        write(41,*)' i x ',i,x(i)                                       

        end do                                                                 

                                                                        

        do i=1,nz                                                              

           y(i)=ze(i)                                                          

!        write(41,*)' i y ',i,y(i)                                       

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

c       call out42(n_pr,a_print,num,apr)
                                                                        

!       write(41,*)' ncam npf kloop kprobe ke',ncam,npf,kloop,kprobe,ke  

                                                                        

                                                                        

        do k=1,ke                                                              

           xu(k)=xu_mat(k)*100.                                                

           yu(k)=yu_mat(k)*100.                                                

!        write(41,*)' k xu yu ',k,xu(k),yu(k)                            

        end do                                                                 

                                                                        

        apr='  xu'
c       call out42(n_pr,a_print,num,apr)
                                                                        

        do k=1,ncam                                                            

           rcam(k)=rcam_mat(k)                                                 

           do kk=1,ncam                                                        

              pmj(k,kk)=pmj_mat(k,kk)*1.e8                                     

           end do                                                              

!        write(41,*)' k rcam pmj ',k,rcam(k),pmj(k,k)                    

        end do                                                                 

                                                                        
        apr='  pmj '
c       call out42(n_pr,a_print,num,apr)

                                                                        

        do k=1,ncam                                                            

           do kk=1,npf                                                         

              pfc(k,kk)=pfc_mat(k,kk)*1.e8                                     

           end do                                                              

!        write(41,*)' k pfc ',k,pfc(k,1),pfc(k,2),pfc(k,3)               

        end do                                                                 


        apr='  pfc'
c       call out42(n_pr,a_print,num,apr)
                                                                        

        do k=1,npf                                                             

              pfres(k)=pfres_mat(k)                                            

           do kk=1,npf                                                         

              pfind(k,kk)=pfind_mat(k,kk)*1.e8                                 

           end do                                                              

!        write(41,*)' k pfres pfind ',k,pfres(k),pfind(k,k)              

        end do                                                                 

                                                                        
        apr='  pfind'
c       call out42(n_pr,a_print,num,apr)

                                                                        

                                                                        

        do k=1,ncam                                                            

           do kk=1,nwnh                                                        

              vesarr(kk,k)=vesarr_mat(kk,k)*1.e8                               

           end do                                                              

!        write(41,*)' k vesarr ',k,vesarr(1,k),vesarr(2,k),vesarr(3,k)   

        end do                                                                 

        apr='  vesarr'
c       call out42(n_pr,a_print,num,apr)



        do k=1,npf                                                             

           do kk=1,nwnh                                                        

              fluxarr(kk,k)=fluxarr_mat(kk,k)*1.e8                        

           end do                                                              

!        write(41,*)'k fluxarr',k,fluxarr(1,k),                          

!     *  fluxarr(2,k),fluxarr(3,k)                                       

        end do                                                                 

        apr='  fluxarr'
c       call out42(n_pr,a_print,num,apr)


        if(kloop.gt.0)then                                                     

           do k=1,kloop                                                        

              do kk=1,nwnh                                                     

                 pslgreen(kk,k)=pslgreen_mat(kk,k)*1.e8

              end do
           end do 

        apr='  pslgreen '
c       call out42(n_pr,a_print,num,apr)

           do k=1,kloop                                                        
              do kk=1,npf

                 pfgreen(k,kk)=pfgreen_mat(k,kk)*1.e8 

              end do                                                           
           end do                                                              

        apr='  pfgreen '
c       call out42(n_pr,a_print,num,apr)

           do k=1,kloop                                                        
              do kk=1,ncam

                 vesgreen(k,kk)=vesgreen_mat(k,kk)*1.e8 

              end do                                                           

           end do                                                              
        apr='  vesgreen '
c       call out42(n_pr,a_print,num,apr)

        end if                                                                 

                                                                        

        if(kprobe.gt.0)then                                                    
        a_print(4)=kprobe
        apr='  kprobe '
c       call out42(n_pr,a_print,num,apr)

           do k=1,kprobe                                                       

        apr='  k '
        a_print(1)=k
        n_pr=1
c       call out42(n_pr,a_print,num,apr)
              do kk=1,nwnh                                                     

                 bprgreen(kk,k)=bprgreen_mat(kk,k)*1.e4

              end do
           end do                                                              
        apr='  bprgreen '
c       call out42(n_pr,a_print,num,apr)

           do k=1,kprobe                                                       
              do kk=1,npf

                 pfprobe(k,kk)=pfprobe_mat(k,kk)*1.e4

              end do                                                           
           end do                                                              
        apr='  pfprobe '
c       call out42(n_pr,a_print,num,apr)

           do k=1,kprobe                                                       
              do kk=1,ncam

                 vesprobe(k,kk)=vesprobe_mat(k,kk)*1.e4

              end do                                                           
           end do                                                              

        apr='  vesprobe '
c       call out42(n_pr,a_print,num,apr)

        end if                                                                 

        RETURN                                                          

        END   
