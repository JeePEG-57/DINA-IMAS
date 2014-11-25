
      subroutine dina_v96(t,key_mat,vec_mat,pf_mat0,tcam_mat0,
     *   bp_exp_mat,ps_exp_mat,pf_exp_mat,indpf_mat,ext_transp_mat,
      
     * input_1,input_2, input_3, input_4,input_5, 
     * output_1, output_2, output_3, output_4, output_5, 
     * output_6, output_7,output_8, output_9, output_10, 
     * output_11, output_12, output_13, output_14, 
     * output_15, output_16)
     
    	include 'double.inc'
    	
    	real *8 input_1,input_2, input_3, input_4,input_5
       
      parameter( n_prof= 26, n_cronos=30, NINPUTS=6,

     *  NOUTPUTS=15,N_SHAPE_OUT=37, N_BOUND_OUT=1000,
     *  N_SURF_OUT=100*90, n_vec=31,n_key=27,
     *  n_port1=14, n_port2=54, n_port3=19,
     *  n_port4=12,n_bound_arr=182,
     *  K_AUX=6, N_MAT=100,KF_MAT=120,MU_MAT=401,
     *  NLOOP_MAT=50,NPROBE_MAT=80,MU_L_MAT=403 )

      dimension 
     *   key_mat(*),vec_mat(*)

      dimension 
     *   pf_mat0(*),tcam_mat0(*)

      dimension 
     *   bp_exp_mat(*),ps_exp_mat(*),pf_exp_mat(*),
     *   indpf_mat(*),ext_transp_mat(*)

      dimension 
     * input_1(*),input_2(*), input_3(*), input_4(*),input_5(*), 
     * output_1(*), output_2(*), output_3(*), output_4(*), output_5(*), 
     * output_6(*), output_7(*),output_8(*), output_9(*), output_10(*), 
     * output_11(*), output_12(*), output_13(*), output_14(*), 
     * output_15(*), output_16(*)
     
      dimension aux_heat(6),pf_mat(14)
           
      integer n_grid,npf_mat,ncam_mat
      integer nprof_mat	!	/* actual number output profiles */
      integer n_inp_prof !		/* actual number output profiles */
      integer n_aux_prof !	/* actual number aux profiles */
      integer n_surf   !		/* actual number of output surfaces */
      integer n_surf_psi !		/* actual number of psi- surfaces */
      integer n_surf_cur !	/* actual number of cur-surfaces */
      integer n_polar_cur !		/* actual number of polar-cur-surfaces */
      integer n_cronos_prof ! actual number of cronos output profiles*/
      integer n_cronos_field !/* actual number of cronos output fields*/
      integer n_restart ! /* actual number of restart variables */
      integer kloop_mat !		/* actual number of flux loops */
      integer kprobe_mat !		/* actual number of B probes   */
      integer npts_mat !		/* number of control points */
      integer ke_mat !		/* number of points in limiter */

  !    npf_mat = key_mat(7+1)
  !    ncam_mat = key_mat(8+1)
  !    kloop_mat = key_mat(9+1)
  !    kprobe_mat = key_mat(10+1)
  !    npts_mat = key_mat(11+1)
  !    npts_mat = N_BOUND_OUT
  !    n_grid = key_mat(15+1) 
  !    nprof_mat = key_mat(16+1) 
  !    n_inp_prof = key_mat(15+1)*6
  !    n_aux_prof = key_mat(15+1)*9
  !    n_surf = key_mat(15+1)*2*90
  !    n_surf_psi = nwnh
  !    n_surf_cur = nwnh
  !    n_polar_cur = key_mat(15+1)*90
  !    n_cronos_prof = key_mat(15+1)*n_cronos
  !    n_cronos_field=key_mat(15+1)*3*90
  !    n_restart = nwnh+key_mat(15+1)*90+ncam_mat+npf_mat+2+4*n_grid+1

    
!  Dynamic inputs...

      !   ssSetInputPortWidth (S, 0, n_port1);	
      !   ssSetInputPortWidth (S, 1, n_port2);	
      !   ssSetInputPortWidth (S, 2, npf_mat);	
      !   ssSetInputPortWidth (S, 3, n_inp_prof);	
      !   ssSetInputPortWidth (S, 4, n_aux_prof);	
      !   ssSetInputPortWidth (S, 5, n_bound_arr);	

!   pf_mat = (double *)&(U1(0)); 
!   tcam_mat = (double *)&(U2(0));
!   contpts_mat = (double *)&(U3(0));
!   c_prof_mat = (double *)&(U4(0));
!   aux_prof = (double *)&(U5(0));
!   bound_arr = (double *)&(U6(0));


!      call dina(key_mat,vec_mat, pf_mat0,tcam_mat0,
!     *   d_pf_mat,d_tcam_mat,
!     *   pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat,shape_out,
!     *   k_out_dina,
!     *   contpts_mat,contvals_mat,npts_mat,tcam_mat,
!     *   bp_exp_mat,ps_exp_mat,pf_exp_mat,indpf_mat,ext_transp_mat,
!     *   c_prof_mat,aux_heat,aux_prof,surf_mat,surf_psi,surf_cur,
!     *   polar_cur,cronos_prof,cronos_field,bound_arr,array_con);
     

      ! vec_mat[k]	= vec_mat_in[k];
      ! vec_mat[9]=vec_mat_in[9]; 
	! vec_mat[17]=t;
      ! vec_mat[9]=vec_mat_in[9]; 
      
      !	vec_mat[17]=t;
      ! vec_mat[15]=pf_mat[0]*1.e-19; /* n_e -density */
      ! vec_mat[18]=pf_mat[1]; /* anom_res */
      ! vec_mat[19]=pf_mat[11]; 
      ! vec_mat[20]=pf_mat[12]; 
      ! vec_mat[21]=pf_mat[13]; 
      ! vec_mat[22]=pf_mat[2]; /* ratio_n */

      do i=1,n_port1
      pf_mat(i)=input_1(i)
      print *,' i pf_mat',i,pf_mat(i)
      end do

      vec_mat(17+1)=t
      vec_mat(15+1)=pf_mat(0+1)*1.e-19
      vec_mat(18+1)=pf_mat(1+1)
      vec_mat(19+1)=pf_mat(11+1)
      vec_mat(20+1)=pf_mat(12+1)
      vec_mat(21+1)=pf_mat(13+1)
      vec_mat(22+1)=pf_mat(2+1)

      !   for (k=0; k< 6; k++) { 
      !	aux_heat[k]=pf_mat[k+3];

      do k=1,6
      aux_heat(k)=pf_mat(k+3);
      end do
      
      call dina(key_mat,vec_mat, pf_mat0,tcam_mat0,
      
     *   output_1,output_2,
     *   output_3,output_4,output_5,output_6,output_7,
     *   k_out_dina,
     *   input_3,output_8,npts_mat,input_2,
     
     *   bp_exp_mat,ps_exp_mat,pf_exp_mat,indpf_mat,ext_transp_mat,

     *   input_4,aux_heat,input_5,output_9,output_10,output_11,
     *   output_12,output_13,output_14,input_6,output_15);
     

      !   ssSetOutputPortWidth(S,0,npf_mat);		/* d_pf_mat */
      !   ssSetOutputPortWidth(S,1,ncam_mat); 		/* d_tcam_mat */
      !   ssSetOutputPortWidth(S,2,kloop_mat);		/* pl_loop_mat */
      !   ssSetOutputPortWidth(S,3,kprobe_mat);	/* pl_probe_mat */
      !   ssSetOutputPortWidth(S,4,n_port4);		
      !   ssSetOutputPortWidth(S,5,nprof_mat);		/* kinetics */
      !   ssSetOutputPortWidth(S,6,N_SHAPE_OUT);	/* shape_out */
      !  ssSetOutputPortWidth(S,7,N_BOUND_OUT);	/* shape_bound */
      !   ssSetOutputPortWidth(S,8,n_surf);	/* SURFACES */
      !   ssSetOutputPortWidth(S,9,n_surf_psi);  /* psi */
      !   ssSetOutputPortWidth(S,10,n_surf_cur);  /* currents */
      !   ssSetOutputPortWidth(S,11,n_polar_cur);  /* polar currents */
      !   ssSetOutputPortWidth(S,12,n_cronos_prof);  /* total cronos profiles */
      !   ssSetOutputPortWidth(S,13,n_cronos_field);  /* total cronos fields */
      !   ssSetOutputPortWidth(S,14,n_restart);  /* total cronos fields */

! Dynamic outputs...
!      do  k=1,npf_mat
!      output_1(k)=d_pf_mat(k)
!      end do
      
      !	for (k=0; k<ncam_mat; k++) { 
      !	c_1[k]=d_tcam_mat[k];

      !	for (k=0; k<kloop_mat; k++) { 
      !	c_2[k]=pl_loop_mat[k];

      !	for (k=0; k<kprobe_mat; k++) { 
      !	c_3[k]=pl_probe_mat[k];

      !	for (k=0; k<npf_mat; k++) { 
      !	c_4[k]=pl_pf_mat[k];

      !	for (k=0; k< nprof_mat; k++) { 
      !	c_5[k]=pl_ves_mat[k];

   
      !	for (k=0; k<N_SHAPE_OUT; k++) { 
      !	c_6[k]=shape_out[k];

      !	for (k=0; k<N_BOUND_OUT	; k++) { 
      !	c_7[k]=contvals_mat[k];

	
      !   for (k=0; k< n_surf; k++) { 
      !	c_8[k]=surf_mat[k];

      !   for (k=0; k< n_surf_psi; k++) { 
      !	c_9[k]=surf_psi[k];

   
      !   for (k=0; k< n_surf_cur; k++) { 
	! c_10[k]=surf_cur[k];

      !for (k=0; k< n_polar_cur; k++) { 
      !	c_11[k]=polar_cur[k];


      !   for (k=0; k< n_cronos_prof; k++) { 
	! c_12[k]=cronos_prof[k];

      !   for (k=0; k< n_cronos_field; k++) { 
      !	c_13[k]=cronos_field[k];

      !   for (k=0; k< n_restart; k++) { 
      !	c_14[k]=array_con[k];

   
     
       print *,' dina_v96 call'

        RETURN                                                          
        END                                                             

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

         subroutine dina_new(key_mat,vec_mat, pf_mat0,tcam_mat0,
      
     *   output_1,output_2,
     *   output_3,output_4,output_5,output_6,output_7,
     *   k_out_dina,
     *   input_3,output_8,npts_mat,input_2,
     
     *   bp_exp_mat,ps_exp_mat,pf_exp_mat,indpf_mat,ext_transp_mat,

     *   input_4,aux_heat,input_5,output_9,output_10,output_11,
     *   output_12,output_13,output_14,input_6,output_15);


      print *,' HERE DINA CALL'
      
   !   stop

        RETURN                                                          
        END                                                             
