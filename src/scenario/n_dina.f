
c	call pau()

      call cpu_time(t_start)


	if(i_exit.eq.1)then 
	i_en10=i_en100+1
	a_print(1)=i_exit
	apr=' i_exit==='
	num=20
	n_pr=1
	if(kpr.eq.3.and.i_en100.eq.1)call out42(n_pr,a_print,num,apr)

c	   call pau()
	return
	end if

	i_en0=i_en0+1    

	if(i_en0.eq.1)then
	call read_data() 
	eu=vec_mat(4)*100.d0
	if(eu.le.20.d0)eu=20.d0
	end if

	
	if(i_en0.gt.1.and.i_model_1.eq.10)return


	n=key_mat(16)

c  i_con=1  to control vertical Z position

	i_con=key_mat(21)

c	print *,' i_con===',i_con

	it_ext=key_mat(22)

	key_ne=key_mat(23)

c	print *,' key_ne== key_mat(23)',key_ne,key_mat(23)


c	read (*,*)


c	if(i_model.eq.63)key_ne=0
c	if(i_model.eq.71)key_ne=0


	if(i_en0.eq.1)then	
		key_equil=key_mat(24)
	end if

	i_gen=key_mat(25)
c	i_gen=0

	i_new=0
	if(key_ne.eq.3)i_new=1
	if(key_ne.eq.32)i_new=2
	if(key_ne.eq.33)i_new=3

	if(key_ne.gt.30)key_ne=3

c        print *,' key_equil====',key_equil


c	print *,' key_ne== i_new',key_ne,i_new

c	read (*,*)


	key_p_turb=key_mat(20)


	kf43=0



        if(nr.ne.key_mat(5))then

           if(kpr.eq.1)print *,' NR NE key_mat(5)',nr,key_mat(5)

        end if



        if(nz.ne.key_mat(6))then

           if(kpr.eq.1)print *,' NZ NE key_mat(6)',nr,key_mat(6)

        end if



c	print *,' key_mat',(key_mat(i),i=1,6)

       



c        print * ,' npts_mat',npts_mat


 	apr=' ech_data'

c        print 73 ,apr,(ech_data(i),i=1,54)



        npts_mat=key_mat(12)



        kcchp=key_mat(13)

	  key_t11=key_mat(14)

c---- coeficients for KTM power system...

      n_pas=0



        npts=npts_mat

c        do i=1,2*npts

c           contpts(i)=contpts_mat(i)*100.

c        end do




!!!	tay_min=vec_mat(11)*1000.

c	e_sep=vec_mat(11);

c	if(e_sep.le.5.d-3)e_sep=5.d-3
c	if(e_sep.gt.5.d-2)e_sep=5.d-2

	e_sep=5.d-3
c	e_sep=2.d-3


	tay_min=1.e-9



	time=vec_mat(18)
	


      do iii=1,npf
	a_print(iii)=contpts_mat(iii)
      end do

        if(i_en0.eq.1.and.i_gen.eq.1)then
           open (unit=41,file='pf_index.dat',form='formatted')
           read (41,*)
           read (41,*)(index(i),i=1,npf)
           close (41)
        end if



c!	i_graph=1                                                            


        if(i_en0.eq.1.and.i_con.gt.0.and.i_con.ne.5)then
           open (unit=41,file='rz_index.dat',form='formatted')
           read (41,*)
           read (41,*)(ind_r(i),i=1,2)
           read (41,*)
           read (41,*)(ind_z(i),i=1,2)
           close (41)
        end if



	do i=1,npf

	vchopper(i)=contpts_mat(i)

	if(i_gen.eq.1)then
	if(index(i).eq.0)then
	   pf(i)=vchopper(i)*1.d-3
	a_print(i)=pf(i)
	end if
	end if


c	a_print(i)=contpts_mat(i)

	end do



	n_pr=npf

	apr='Volt'

	if(i_gen.eq.1)apr=' PF'
	num=20

	num=4

	if(kpr.eq.1)call out42(n_pr,a_print,num,apr)


!!!      do i=1,7

	kk=0
      do i=7,10
	kk=kk+1
	a_print(kk)=vchopper(i)

      end do
	n_pr=kk
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

                                                                        

c	i_graph=1                                                             



        key_eq=key_mat(7)



c	call c_ctime('dina',4)                                                 

                                                                        

!	kpr=1                                                                 

      kpr=key_mat(4)




      if(i_en0.eq.-1)then                                              
	n_key=23
	n_vec=30
      call  write3_to_mat(key_mat,vec_mat,kpr,n_key,n_vec)                       
	call  write_pf_mat(   
     *  pf_mat,npf)   
	call write_tcam_mat(                                       
     *  tcam_mat,ncam)                                                    
      end if                                                          


                                                                        

        if(i_en.eq.-1)then                                              

           open ( unit=41,file='kpr.dat',form='formatted')              

           read (41,*)                                                  

           read (41,*)kpr                                               

!           if(kpr.eq.1)print *,'kpr===',kpr                            

	   close (41)                                                          

	end if                                                                 

                                                                        

c        open(unit=43,file='f43',form='formatted')       

                                                                        

                                                                        

	k_ener=key_mat(2)                                                      

	if(i_en0.eq.1)next=key_mat(3)      
!!!	if(i_en0.eq.1)next=3000                                                        

                                                                        


                                                                        
	eps_vel=vec_mat(13)
                                                                        
	if(dabs(eps_vel).gt.1.e-1)eps_vel=5.e-2
	if(dabs(eps_vel).le.1.e-5)eps_vel=5.e-3

        if(kpr.eq.1)print *,'k_energy next eps_vel',
     *  k_ener,next,eps_vel              


	kefit_mat=key_mat(1)                                                   

                                                                        

	if(kefit_mat.eq.0)then                                                 

	   beta_mat=vec_mat(1)                                                 

	   pw_1_mat=vec_mat(2)                                                 

	   pw_2_mat=vec_mat(3)                                                 

	end if                                                                 

                                                                        

	if(kefit_mat.eq.1)then                                                 

	   do i=1,2                                                            

	      alfax_mat(i)=vec_mat(i)                                          

	      betax_mat(i)=vec_mat(i+2)                                        

	   end do                                                              

	end if                                                                 

	if(kefit_mat.eq.20)then                                                 

	   do i=1,2                                                            

	      alfax_mat(i)=vec_mat(i)                                          

	      betax_mat(i)=vec_mat(i+2)                                        

	   end do                                                              

	end if                                                                 

                                                                        

	if(kefit_mat.eq.2)then                                                 

	   beta_mat=vec_mat(1)                                                 

	   alfa1_mat=vec_mat(2)                                                

	end if                                                                 

                                                                        

	rmag_mat=vec_mat(5)

	if(key_mat(1).eq.20)then

	rmag_mat=vec_mat(5)*0.99

	   
	end if


	zmag_mat=vec_mat(6)                                                    

                                                                        

	rs0_mat=vec_mat(7)                                                     


!	rmag_mat=rs0_mat


	bt0_mat=vec_mat(8)                                                     
c	bt0_mat=vec_mat(22)

                                                                        

!!!	tpl_mat=vec_mat(9) 

	tpl_mat=vec_mat(19)                                                     

!cccccccccccccccccccccccccc temporarily...
	if(key_p_turb.eq.10)then	                                                    
c	tpl_mat=vec_mat(19)                                                     
	end if

c	print *,' vec_mat(19) key_p_turb',vec_mat(19),key_p_turb

c	read (*,*)
                                                                        

	tay_mat=vec_mat(10)                                                    



c	print *,' tay_mat==key(24)',tay_mat,key_mat(24)


c        power_ech=vec_mat(12)
        alp1=vec_mat(12)



c        print *,' power_ech====',power_ech



c!        yr0=vec_mat(13)*1.d2



	r_eccd=vec_mat(13)*1.d2

	z_eccd=vec_mat(14)*1.d2



c        te_a=te_mat



c	print *,' vec_mat_27============',vec_mat(27)

        c_pcchp=vec_mat(27)
	if(dabs(c_pcchp).le.1.e-3)c_pcchp=1.e-3

!!!        pcchp=c_pcchp*vec_mat(16)

        pcchp=vec_mat(16)

c!!!	  if(i_en0.gt.5)call pcchp_filter() 



        c11=vec_mat(19)

      if(i_en0.gt.5)then 
	   p_turb=p_turb*c11
	else
	   p_turb=1.
	end if

	if(p_turb.le.0.05)p_turb=0.05
	if(p_turb.ge.20.)p_turb=20.

!	if(p_turb.le.0.001)p_turb=0.001
!	if(p_turb.ge.100.)p_turb=100.
c---------------------------------

	if(key_p_turb.eq.2)then 
	   p_turb=c11
c	   print *,' key_p_turb p_turb ==',key_p_turb,p_turb
	end if

	if(key_p_turb.eq.0.or.key_p_turb.eq.10)then 
	   p_turb=1.
c	   print *,' key_p_turb p_turb ==',key_p_turb,p_turb
	end if
c---------------------------

c	if(power_ech2.le.1.e-1)p_turb=1;

	if(kpr.eq.1)print *,' power_ech2 p_turb=======',
     *  power_ech2,p_turb


	del_ech0=vec_mat(20)
	anom_e=vec_mat(21)

	q_test=vec_mat(22)
c	q_test=0.95d0

	pd0_a=vec_mat(27)
	pd0_b=vec_mat(23)

	if(pd0_a.le.pd0_b*0.1d0)pd0_a=pd0_b*0.1d0

	pw_p=vec_mat(28)
	pw_e=vec_mat(29)

	eps2=vec_mat(30)

c	ves_coef=vec_mat(22)

	ves_coef=1.

	ro_bar=vec_mat(24)

	alf_bar=vec_mat(25)

	eff_cd=vec_mat(26)
c
	a_print(1)=vec_mat(21)
	a_print(2)=vec_mat(22)
	a_print(3)=vec_mat(23)
	a_print(4)=vec_mat(24)
	n_pr=4
	apr='anom_e q_axis pd0_b ro_aux'
	num=25
	if(kpr.eq.1)call out42(n_pr,a_print,num,apr)

	a_print(1)=vec_mat(25)
	a_print(2)=vec_mat(26)
	n_pr=2
	apr='tran_bar eff_ECCD'
	num=25
	if(kpr.eq.1)call out42(n_pr,a_print,num,apr)


c        gam_eccd=0.042 ! default value...


	do i=1,30
	a_print(i)=vec_mat(i)
	end do
	n_pr=30
	apr='vec_mat'
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,25
	a_print(i)=key_mat(i)
	end do
	n_pr=25
	apr='key_mat'
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,npf
	a_print(i)=pf_mat(i)
	end do

	n_pr=npf
	apr='pf_mat'
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


!        gam_eccd=vec_mat(17)


	if(kpr.eq.2)print *,' time anom_res eps int_tok int_2000',
     *  'key_anom_res*==',
     *  tt,p_turb,eps_vel,int_tok,int_2000,key_p_turb



      if(kpr.eq.1)print *,' pcchp pcch del_ech0 p_turb',
     * pcchp,pcch,del_ech0,p_turb

                                                                        

	rs0=rs0_mat*100.                                                       

                                                                        

	bt0=bt0_mat*10.                                                        

	if(ntay.le.next)tpl=tpl_mat*1.d-3                                      

      if(kpr.eq.1)print *,' tpl ntay next=',tpl,ntay,next    
 
                                                                        

	tay=tay_mat*1.e3                                                       

                                                                        

      if(kpr.eq.1)print *,' tay_mat vec_mat(10)==',tay_mat,vec_mat(10) 

c	if(kf43.eq.1)write(43,*)'key_mat===',(key_mat(i),i=1,3)                             

c	if(kf43.eq.1)write(43,*)'vec_mat===',(vec_mat(i),i=1,10)                            

                                                                        

                                                                        

c	if(kf43.eq.1)write(43,*)'npf===',npf                                                

c	if(kf43.eq.1)write(43,*)'tay=== i_en0 ',tay,i_en0                                                




	if(i_en0.eq.1)then

        te_b=vec_mat(14)
        te_a=vec_mat(15)
	ti_a=te_a
	ti_b=te_b

	a_print(1)=te_a

	a_print(2)=te_b

	a_print(3)=eps2

	a_print(4)=key_ne

	n_pr=4

	apr='te_a te_b eps2 key_ne'

	num=25


	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


c	print *,' te_a te_b====',te_a,te_b

	do i=1,npf                                                             
	   pf(i)=pf_mat(i)*0.001d0  
	end do                                                       


	if(key_mat(15).eq.1)then
	   i_svd=0
	end if
	if(key_mat(15).eq.2)then
	   i_svd=0
	do i=1,npf                                                             
	   pf(i)=pf_exp_mat(i)*0.001d0
	end do
 	apr=' pf_mat'
c        print 73 ,apr,(pf_mat(i),i=1,npf)
 	apr=' pf_exp_mat'
c        print 73 ,apr,(pf_exp_mat(i),i=1,npf)


	end if
	if(key_mat(15).eq.3)then
	   i_svd=3
	   i_ves=1
	do i=1,npf                                                             
	   indpf(i)=indpf_mat(i)
	   pf(i)=pf_exp_mat(i)*0.001d0
	end do
	end if
	if(key_mat(15).eq.4)then
	   i_svd=3
	   i_ves=0
	do i=1,npf                                                             
	   indpf(i)=indpf_mat(i)
	   pf(i)=pf_exp_mat(i)*0.001d0
	end do
	end if

      end if

	if(key_mat(15).eq.5)then
	   i_svd=1
	do i=1,npf                                                             
	   pf0(i)=pf(i)
	end do

	end if


        tokc=0.                                              
	do i=1,ncam                      
	   if(i_en0.eq.1)tcam(i)=tcam_mat(i)*0.001d0
	   tokc=tokc+tcam(i)
	end do                                                                 

	if(kpr.eq.1)print *,' i_en0 tokc ves_coef',i_en0,tokc,ves_coef

	power_el=aux_heat(1)
	ro_el=aux_heat(2)
	del_el=aux_heat(3)

	power_ion=aux_heat(4)
	ro_ion=aux_heat(5)
	del_ion=aux_heat(6)

	do i=1,6
	a_print(i)=aux_heat(i)
	end do
	n_pr=6

	apr='aux_heat'

	num=4

c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	do i=1,n
	p_e(i)=aux_prof(i)
	p_i(i)=aux_prof(i+n)
	aj_cd(i)=aux_prof(i+2*n)
	pne_ext(i)=aux_prof(i+3*n)
	te_ext(i)=aux_prof(i+4*n)
	ti_ext(i)=aux_prof(i+5*n)
	end do

	if(i_model_1.eq.92.or.i_model_1.eq.93)then

	sigma_coef=9.d0/(12.d3)

	do i=1,n
	sigma_ext(i)=aux_prof(i+6*n)
	end do

	do i=1,6
	a_print(i)=sigma_ext(i)
	end do
	n_pr=6

	apr='sigma_ext'

	num=4

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,n
	sigma_ext(i)=sigma_ext(i)*sigma_coef
	end do


	call sigm_ext()



	end if

	if(i_model_1.eq.93)then

	pres_max=0.d0
	do i=1,n
	p_ext(i)=aux_prof(i+7*n)
	if(p_ext(i).gt.pres_max)pres_max=p_ext(i)
	end do

	do i=1,6
	a_print(i)=p_ext(i)
	end do
	n_pr=6

	apr='-p_ext-'

	num=4

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	i_pres=0
	if(pres_max.gt.1.d-9)i_pres=1

c	key_ne=5

	do i=1,n
	p_ext(i)=p_ext(i)/1.d16
	end do


	end if





	PNOR=6.25E8
	   
	do i=1,n 
      aj_cd(i)=aj_cd(i)*1.e-7
      p_e(i)=p_e(i)*pnor*1.e-6
      p_i(i)=p_i(i)*pnor*1.e-6
	end do

	i_deb=0

	if(i_deb.eq.1)then



	do i=1,6
	a_print(i)=p_e(i)
	end do
	n_pr=6

	apr='p_e'

	num=4

c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,6
	a_print(i)=p_i(i)
	end do
	n_pr=6
	apr='p_i'
	num=4

c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,6
	a_print(i)=aj_cd(i)
	end do
	n_pr=6

	apr='aj_cd'
	num=4
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,6
	a_print(i)=pne_ext(i)
	end do
	n_pr=6

	apr='n_ext'
	num=4
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	do i=1,6
	a_print(i)=te_ext(i)
	end do
	n_pr=6

	apr='te_ext'
	num=4
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,6
	a_print(i)=ti_ext(i)
	end do
	n_pr=6

	apr='ti_ext'
	num=4
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	end if


	k_equ=0

	if(tay.ge.tay_min.or.i_en0.eq.1)then

	k_equ=1

	end if

	                                                           

	if(dabs(tay_last-tay).gt.0.001*tay.and.k_equ.eq.1)then

c   	call cam_t()                                                           

	a_print(1)=tay
	a_print(2)=tay_last
	a_print(3)=tt
	a_print(4)=q_test
	n_pr=4

	apr='-- tay tay_l tim q_ax'

	num=25


	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

c	i_gen=1
	if(i_gen.eq.0)call inv_gen()
	if(i_gen.eq.1)call inv_gen_pf()

c	if(i_ktm.eq.1)call tcam_corr()

	end if                                                                 

                                                                        

c	call gen_mat()                                                         





c        close (43) 



	a_print(1)=tokc

	a_print(2)=tay

	a_print(3)=tay_min

	a_print(4)=time

	a_print(5)=i_en0

	n_pr=5

	apr='tokc tay t_mi time i_en0'

	num=25


c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


c	print *,' k_equ===',k_equ


	if(k_equ.eq.1)then

	a_print(1)=tokc

	a_print(2)=tay

	a_print(3)=tay_min

	a_print(4)=time

	a_print(5)=q_test


	n_pr=5

	apr='tokc tay tay_m tim q_test '

	num=25

c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,9
	n_next=0
	c_e2(i)=ech_data(n_next+i)
	n_next=n_next+9
	p_e2(i)=ech_data(n_next+i)*1.e-6
	n_next=n_next+9
	r_e2(i)=ech_data(n_next+i)*1.e2
	n_next=n_next+9
	z_e2(i)=ech_data(n_next+i)*1.e2
	n_next=n_next+9
	dr_e2(i)=ech_data(n_next+i)*1.e2
	n_next=n_next+9
	dz_e2(i)=ech_data(n_next+i)*1.e2
	end do

 	apr=' c_e2'
c        if(kpr.eq.1)print 73 ,apr,(c_e2(i),i=1,9)
 	apr=' p_e2'
c        print 73 ,apr,(p_e2(i),i=1,9)
 	apr=' r_e2'
c        print 73 ,apr,(r_e2(i),i=1,9)
 	apr=' z_e2'
c        print 73 ,apr,(z_e2(i),i=1,9)
 	apr=' dr_e2'
c        print 73 ,apr,(dr_e2(i),i=1,9)
 	apr=' dz_e2'
c        print 73 ,apr,(dz_e2(i),i=1,9)


	do i=1,kprobe
	bp_exp(i)=bp_exp_mat(i)
	end do

	do i=1,kloop
	ps_exp(i)=ps_exp_mat(i)
	end do

	do i=1,npf
	pf_exp(i)=pf_exp_mat(i)
	end do

	i_asdex=0
	if(i_asdex.eq.1)call asdex_test()


c------------------------------------------------------

	key_ext=key_mat(19)

	if(i_model.eq.63)key_ext=0

	if(key_ext.eq.1)then
	do i=1,n
	   k=i
	   diff_ext(i)=c_prof_mat(k)
	   k=i+n
	   dxe_ext(i)=c_prof_mat(k)
	   k=i+2*n
	   dxq_ext(i)=c_prof_mat(k)
	   k=i+3*n
	   ajb_ext(i)=c_prof_mat(k)
	   k=i+4*n
	   psin_ext(i)=c_prof_mat(k)
	   k=i+5*n
	   vd_ext(i)=c_prof_mat(k)
	end do
 	apr=' ext_transp_mat'
c        print 73 ,apr,(ext_transp_mat(i),i=1,5)

	do i=1,6
	   ext_transp(i)=ext_transp_mat(i)
	end do

	end if
c---------------------------
	
!	call pau()


	if(key_ext.eq.-1)then
	num=20

	do i=1,10
	a_print(i)=diff_ext(i)
	end do
	n_pr=10
	apr='diff_ext '
	call out42(n_pr,a_print,num,apr)

	do i=1,10
	a_print(i)=dxe_ext(i)
	end do
	n_pr=10
	apr='dxe_ext '
	call out42(n_pr,a_print,num,apr)

	do i=1,10
	a_print(i)=dxq_ext(i)
	end do
	n_pr=10
	apr='dxq_ext '
	call out42(n_pr,a_print,num,apr)

	do i=1,10
	a_print(i)=ajb_ext(i)
	end do
	n_pr=10
	apr='ajb_ext '
c	call out42(n_pr,a_print,num,apr)

	do i=1,10
	a_print(i)=psin_ext(i)
	end do
	n_pr=10
	apr='psin_ext '
c	call out42(n_pr,a_print,num,apr)

	do i=1,10
	a_print(i)=vd_ext(i)
	end do
	n_pr=10
	apr='vd_ext '
c	call out42(n_pr,a_print,num,apr)

	end if

110	continue


	do i=1,n
	zeff(i)=vec_mat(17)
	end do



	do i=1,1
	a_print(i)=vec_mat(17)
	end do

	n_pr=1
	apr='zeff '
c	call out42(n_pr,a_print,num,apr)




	pd0_b=vec_mat(23)

	pw_p=vec_mat(28)
	pw_e=vec_mat(29)



!!!      do i=1,7

	kk=0
      do i=1,npf
	kk=kk+1
	a_print(kk)=vchopper(i)

      end do
	n_pr=kk
	apr='Vchopp '
	if(kpr.eq.-3)call out42(n_pr,a_print,num,apr)

	kk=0
      do i=1,npf
	kk=kk+1
	a_print(kk)=pf(i)

      end do
	n_pr=kk
	apr='pf '
	if(kpr.eq.-3)call out42(n_pr,a_print,num,apr)


	a_print(1)=ntay
	a_print(2)=next
	a_print(3)=tpl
	a_print(4)=tpl_mat

	n_pr=4
	num=25

	apr='ntay next tpl tpl_mat '
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)



 	if(key_ext.eq.1.and.i_en0.eq.-2)then
	a_print(1)=key_ext 
	a_print(2)=i_en0
	n_pr=2
	apr=' WE DO NOT CALL EQUIL '
	num=25
	call out42(n_pr,a_print,num,apr)
c	   print *,' WE DO NOT CALL ONES EQUIL---------------------'
	else
	   call equil()
	end if


	kk=0
      do i=1,npf
	kk=kk+1
	a_print(kk)=pf(i)

      end do
	n_pr=kk
	apr='--pf '
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)



        if(i_en0.eq.-1)then

	res_ves=0.
	do i=24,npf                                                            
	res_ves=res_ves+1./pfres(i)
	end do

	res_ves=1./res_ves

	a_print(1)=rsep
	a_print(2)=zsep
	a_print(3)=eu
	a_print(4)=rmag
	a_print(5)=zmag
	a_print(6)=elong
	a_print(7)=res_ves

	n_pr=7
	num=25

	apr='rx zx a rm zm k r_v '
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

        end if


c 	print *,' HYU'

	if(i_exit.eq.1)then 
	
	a_print(1)=i_exit

	n_pr=1
	num=25

	apr='i_exit=== '
	call out42(n_pr,a_print,num,apr)

	
	return
	end if




	do i=1,n
c	a_print(i)=ajb(i)
	end do
	n_pr=n
	num=25

	apr='--ajb '
c	call out42(n_pr,a_print,num,apr)


	tay_last=tay

c		go to 111

	if(key_equil.eq.2.or.key_equil.eq.3)then

	do i=1,npf                                                             
	   d_pf_mat(i)=1000.d0*pf(i)
	end do                                                                 
	do i=1,ncam                                                            
	   d_tcam_mat(i)=1000.d0*tcam(i)
	end do                                                                 

	if(kloop.gt.0)then                                                     
	   do k=1,kloop                                                        
	      pl_loop_mat(k)=psloop(k)
	   end do                                                              
	end if                                                                 
c                                                                       
	if(kprobe.gt.0)then                                                    
	   do k=1,kprobe                                                       
	      pl_probe_mat(k)=bprobe(k)
	   end do                                                              
	end if                                                                 


	go to 1001

	return
	end if                                                                 
              



                    
	i_surf=1
	if(i_model.eq.63)i_surf=0
	if(i_model.eq.71)i_surf=0


	if(i_surf.eq.1)then


	call map_ps()

	kk=0

c	do i=1,n
c	do j=1,m
c	kk=kk+1
c	surf_mat(kk)=xpl(i,j)*1.e-2
c	end do
c	end do

c	do i=1,n
c	do j=1,m
c	kk=kk+1
c	surf_mat(kk)=ypl(i,j)*1.e-2
c	end do
c	end do

	do i=1,n

	do j=1,m
	kk=kk+1
	surf_mat(kk)=xpl(i,j)*1.e-2
	end do
	do j=1,m
	kk=kk+1
	surf_mat(kk)=ypl(i,j)*1.e-2
	end do

	end do


	do i=1,nr
	   do j=1,nz
	      kk=(i-1)*nz+j
	      surf_psi(kk)=2.*pi*(psi_g(i,j)-psep)*1.e-5
c	      surf_psi(kk)=psi_g(i,j)
	   end do
	end do


	tok_pl=0.d0
	do i=1,nwnh
	surf_cur(i)=pl_cur(i)*1.e7/(dx*dy)
	tok_pl=tok_pl+surf_cur(i)
	end do

	dxy=dx*dy

	a_print(1)=tok_pl
	a_print(2)=dxy
	a_print(3)=tok_pl*dxy
	n_pr=3
	apr=' tok_pl dxy tok '
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)





	do i=1,nr
	   do j=1,nz
	      kk=(i-1)*nz+j
	      p_pl(i,j)=surf_cur(kk)
	   end do
	end do


	kk=0
	do i=1,n

c      psix=(psval(i)-psval(1))/(psval(n)-psval(1))                
                                                                        
c      psix=dsqrt(psix)                                                    
                                                                        
c	call fit_pp_pff(psix,pprime,fprime) 
		                               
	do j=1,m
	kk=kk+1
	urr=xpl(i,j)
	vrr=ypl(i,j)
!!!	call boxdl_pl(fint,urr,vrr)

	pprime=ppx(i)
	fprime=pffx(i)


	f_pp=-PPRIME*urr/rS0                                                     
                                                                        
	f_pff=-0.5d0*FPRIME*rS0/urr                                                
                                                                        
	fint=f_pp+f_pff                                                         

	polar_cur(kk)=coef*fint*1.e7

	a_print(1)=i
	a_print(2)=j
	a_print(3)=kk
	a_print(4)=urr
	a_print(5)=vrr
	a_print(6)=fint
	n_pr=6
	apr=' i j kk r z f '
c	call out42(n_pr,a_print,num,apr)

	end do
	end do


	a_print(1)=kk
	n_pr=1
	apr='kk=== '
c	call out42(n_pr,a_print,num,apr)

	do i=1,m
	a_print(i)=ypl(n,i)*1.e-2
	end do
	n_pr=m
	apr='ypl '
c	call out42(n_pr,a_print,num,apr)
	end if



	end if






c	i_eqb=2

	i_eqb=1

c	stop
			
	if(i_eqb.eq.0)then
	call map_tor()
	call eq_res_ps()
!!	call polar_tor_in()
	end if

c	call transf_data_test()

        key_eqb=0
	if(i_eqb.eq.1.and.i_en0.eq.1)then
           key_eqb=1
        end if
	if(i_eqb.eq.1.and.key_eq.eq.0)then
           key_eqb=1
        end if
	if(i_eqb.eq.1.and.key_eq.eq.2)then
           key_eqb=1
        end if

	if(key_eqb.eq.1)then

c	call pau()
c	call dfdpsi_get()
c	call dp_df_calc
c	call pau()
c      call retab_L
c	call pau()
	call map_eqb()     
	call grid_ini()
	call tpl_out()

c	ngav=3
	ngav=1
c	ngav=2
	call pll_get(pll)
      call bongri
	psi_eav=fdd*1.d-5/(2.d0*pi)
	ntay2=2
	call eqb_rus(ngav,psi_eav,ntay2)
!!!	call transf_data_out()
	call ro_get()

	end if

	i_map=0

	if(i_map.eq.1)then

	call map_ps()

	call tab_to_pet()

	call presol_map()
c	call move_mapp()

c	call presol_map()
c	call move_mapp()

c	call presol_map()
c	call move_mapp()


	call map_tor_in()

	end if



	if(key_mat(18).eq.1)call pau()

	

c###	call equil()                                                           

                                                                        

cFUL	call gen_dina()

                                                        

c        open(unit=43,file='f43',form='formatted',access='append')       

c        open(unit=43,file='f43',form='formatted')       



c        do k=1,npts_mat

c           if(kf43.eq.1)write(43,*)' k contvals',k,contvals_mat(k),

c     *  contvals_mat(k+npts_mat),

c     *  contvals_mat(k+2*npts_mat)

c        end do



                                                                        

	do i=1,npf                                                             

	   d_pf_mat(i)=1.d3*pf(i)



c	   if(kf43.eq.1)write(43,*)'i pf pf_mat0 d_pf_mat  ',

c     *  i,pf(i)*1000.,pf_mat(i),d_pf_mat(i)                               



	end do                                                                 

                                                                        

	do i=1,ncam                                                            

	   d_tcam_mat(i)=1.d3*tcam(i)

         

c	   if(kf43.eq.1)write(43,*)'i tcam tcam0 d_tcam',

c     *  i,tcam(i)*1000.,tcam_mat(i),d_tcam_mat(i)                               

	end do                                                                 



111	continue

                                                                        

	if(i_model.eq.63)call pl_diag_63(                                                          
     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)

	if(i_model.eq.71)call pl_diag_71(                                                          
     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)

	if(i_model.eq.80)call pl_diag_71(                                                          
     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)
						                                                  
c	if(i_model.eq.90)call pl_diag_71(                                                          
c     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)

	if(i_model.eq.90)call pl_diag_90(                                                          
     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)



c	return

	if(i_model.eq.91.and.i_model_1.eq.0)call pl_diag_90(
     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)

	if(i_model.eq.91.and.i_model_1.eq.92)call pl_diag_90(
     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)


	if(i_model.eq.91.and.i_model_1.eq.93)call pl_diag_91(
     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)

	if(i_model.eq.91)then

	i_save=1
	call prof_save(i_save)

c	call map_tor()
c	call eq_res_ps()

	if(i_model_1.eq.0.or.i_model_1.eq.92)then
	call cronos_metric(
     *  cronos_prof)          
        end if



	if(i_model_1.eq.93)then
	call cronos_metric_93(
     *  cronos_prof)          
        end if


	call fields_calc(
     *  cronos_fields)                  

	i_save=0
	call prof_save(i_save)

c	call pau()	


	end if



			                                                          

c	call time_iterp(time,

c     *  pl_loop_mat,pl_probe_mat,

c     *  d_pf_mat)



c----                                                                   

1001	continue
                                                                        

	if(kpr.eq.-3)call print3(' tt tpl_mat tpl==',tt,tpl_mat,tpl)


	tpl_mat=tpl*1.d3                                                       

                                                                        

c	vec_mat(9)=tpl_mat                                                    

                                                                        

c----                                                                   

c                                                                       

c	shape_out(1) PLASMA CURRENT [A]                                       

c	shape_out(2) RMAG [m]                                                 

c	shape_out(3) ZMAG [m]                                                 

c	shape_out(4) a [m]                                                    

c	shape_out(5) elong                                                    

c	shape_out(6) elong_upper                                              

c	shape_out(7) elong_down                                               

c	shape_out(8) triangularity                                            

c	shape_out(9) triangularity_upper                                      

c	shape_out(10) triangularity_down                                      

                                                                        

c	shape_out(11) beta_pol                                                

c	shape_out(12) li(3)                                                   

c	shape_out(13) q_axis                                                  

c	shape_out(14) q_bound                                                 

c	shape_out(15) T_e axis [ Ev]                                          

c       shape_out(16) r_X1point [m]  (dominanat X-point)

c       shape_out(17) z_X1point [m]

c	shape_out(18) r_X2point [m] (non-dominant X-point)

c	shape_out(19) z_X2point [m]

c	shape_out(20) psi_axis [Wb]

c	shape_out(21) psi_bound [Wb]



c        shape_out(22)=tpl_ech*1.e3  !  ECCD driven current [A]

c        shape_out(23)=q_rz        !  q at R,Z location of ECCD 



c       shape_out(last_num+1) num of bdry pts(=mp/n_ext) last_num=23 now

c       !!! n_ext=2 will be determinated below 

c       shape_out(last_num+1+(1:shape_out(last_num+1))) 

c       r-coords of boundary [m]

c       shape_out((end_of_previous+1):end) z-cordinates of boundary [m] 



                                                                        

	shape_out(1)=tpl_mat                                                   

	shape_out(2)=rmag*1.d-2                                                

	shape_out(3)=zmag*1.d-2                                                

	shape_out(4)=eu*1.d-2 
	                                                 
!!!	shape_out(4)=eu_95*1.d-2

c$	call trian()

	shape_out(5)=elong  
	                                                
!!!	shape_out(5)=elong_95

c	shape_out(6)=el_up                                                     
c	shape_out(6)=el_up_95

c	shape_out(7)=el_dw
c	shape_out(7)=el_dw_95


	shape_out(6)=bz_pl

!	shape_out(7)=bz_ext
	shape_out(7)=br_pl

	shape_out(8)=shafra(1)                                                  

c	shape_out(8)=tri_95                                                  

!!!	shape_out(9)=tri_up                                                    


	shape_out(9)=udd
c	shape_out(9)=tri_up_95

c	shape_out(10)=ptot

!!!	shape_out(10)=tri
	shape_out(10)=f_index

c ***  **********
	a_print(1)= shape_out(6)
	a_print(2)= shape_out(7)
	a_print(3)= shape_out(10)
	
	n_pr=3
	apr='shape_out(6,7-10)'
	num=25
c	call out42(n_pr,a_print,num,apr)
c ***  **********                                                                        

	shape_out(11)=betj                                                     

	shape_out(12)=uli                                                      

	shape_out(13)=q(2)                                                     

	shape_out(14)=q(n)

!!!	shape_out(14)=q_95


c        print *,' q_a q_b',q(2),q(n)

                                                     

	  shape_out(15)=te0(1)

c        shape_out(16)=rsep*1.e-2


      if(tene.le.1000.)then 
 	shape_out(16)=tene*1.d-3
	else
 	shape_out(16)=1000.*1.d-3
	end if

	if(kpr.eq.1)print *,' tene_e===',tene_e

c!!!        shape_out(17)=zsep*1.e-2

        shape_out(17)=uact

c---------------------- We are changing here----

        shape_out(18)=tq0(1)

        shape_out(19)=pcch*1.d19

c-------------------------------------------------------

c        shape_out(20)=pmag*1.e-5

!!        shape_out(20)=power_ech2*1.e6
!!!        shape_out(20)=ptot_dop*1.d6
        shape_out(20)=q_ech

c        shape_out(21)=psep*1.e-5
	
!!!        shape_out(21)=tokbut*1.d3

       shape_out(21)=qlos_imp

!!!        shape_out(22)=tokuv*1.d3
       shape_out(22)=zeff(1)

        if(i_eccd.ne.0)q_rz=q(i_eccd)



        if(kpr.eq.1)print *,' i_eccd q_rz==',i_eccd,q_rz



c        shape_out(23)=q_rz        !  q at R,Z location o ECCD 


      shape_out(23)=time        !  q at R,Z location o ECCD 

!!!	shape_out(24)=p_turb                                                
	shape_out(24)=ratio_imp                                                

	k_out_dina=24

	if(i_model.eq.90)then
	shape_out(25)=rsep                                                
	shape_out(26)=zsep 
	k_out_dina=26

c TEMPORARILY FOR Medvedev..

c	shape_out(16)=rsep                                                
c	shape_out(17)=zsep 

	end if

	if(i_model.eq.91)then
	shape_out(25)=rsep                                                
	shape_out(26)=zsep 
	k_out_dina=26
	end if

c  EXTRA for KTM

	shape_out(27)=vs_pf                                                
	shape_out(28)=vs_pl                                               
	shape_out(29)=vs_res                                                
	shape_out(30)=vs_tot

	shape_out(31)=fdd*1.d-5

	shape_out(32)=vs_ext
 
	if(i_c_data.eq.0)then                                                                        
!	call print3(' psi_pf,psipl_av,psiext_av==',
!     *  psi_pf,psipl_av,psiext_av)
!
!	call print3(' vs_pf,vs_pl,vs_ext==',
!     *  vs_pf,vs_pl,vs_ext)

	shape_out(27)=psi_pf                                               
	shape_out(28)=psipl_av                                               
	shape_out(32)=psiext_av

	end if


!!!      shape_out(20)=psipl_av 


!!!	shape_out(32)=pll*tpl*1.d-5

	k_out_dina=32

	a_print(1)=vs_pf
	a_print(2)=vs_pl
	a_print(3)=vs_res
	a_print(4)=fdd*1.d-5
	a_print(5)=pll*tpl*1.d-5
	n_pr=5

	apr='v_pfa v_pla vs_res vs_pf vs_pl '
	num=30
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	a_print(1)=vs_ext
	a_print(2)=vs_tot
	a_print(3)=vs_ext+vs_pl
	n_pr=3

	apr='vs_ext vs_tot vs_tot1 '
	num=40
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

!!!	call write_shape(shape_out,k_out_dina,i_dop,kpr)


c	call  control_new(shape_out,k_out_dina)

        do i=1,npts_mat
           contvals_mat(i)=0.d0
        end do

	i_bndr=0
	if(i_bndr.eq.1)then

        n_ext=2
        mpb=int(mp/n_ext)

!	contvals_mat(1)=mpb

c    mpb=45


        do i=1,mpb
	   contvals_mat(i)=uk(2*i)*1.d-2
	   contvals_mat(i+mpb)=vk(2*i)*1.d-2
	enddo


	else

	if(mcurve.le.2)mcurve=2

	contvals_mat(1)=mcurve

	do i=1,mcurve
	contvals_mat(i+1)=x11(i)*1.d-2
	contvals_mat(i+1+mcurve)=y11(i)*1.d-2
	end do

	a_print(1)=mcurve
	a_print(2)=x11(1)
	a_print(3)=x11(mcurve-1)
	a_print(4)=y11(1)
	a_print(5)=y11(mcurve-1)

	a_print(6)=0

	a_print(6)=kkk

	n_pr=6

	apr='mc x11 x11 y11 y11 kkk'

	num=30

c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	end if

	if(k_equ.eq.-1)then

	call time_save(time,

     *  kloop,kprobe,npf,

     *  pl_loop_mat,pl_probe_mat,

     *  d_pf_mat,

     *  shape_out)                  


	end if

c	call pau()


5000    format (6(1pe14.6))  

c!!!	include 'shape.inc'


      call cpu_time(t_finish)

	a_print(1)=t_finish-t_start
	n_pr=1
	num=25

	apr='-time_calc_of_step-'
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)



	return                                                                 

	end                                                                    


	subroutine fields_calc(cronos_fields)
	include 'double.inc'
	real *8  cronos_fields(*)

	include 'new_com.inc'

	call fields_calc_c(cronos_fields,
     *  n,m,npo,xpl,ypl,b_r,b_z,b_fi,f,rs0,kpr)

	return
	end

	subroutine fields_calc_c(cronos_fields,
     *  n,m,npo,xpl,ypl,b_r,b_z,b_fi,f,rs0,kpr)

	include 'double.inc'
	dimension xpl(npo,*),ypl(npo,*),b_r(npo,*),b_z(npo,*),
     *  b_fi(npo,*),f(*)

	real *8  cronos_fields(*)

	dimension pdd(6)

	character *20 apr                                                      

	dimension a_print(100)

	a_print(1)=n
	a_print(2)=m
	n_pr=2
	apr='  **n m **'
	num=20
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,n
	do j=1,m

	urr=xpl(i,j)
	vrr=ypl(i,j)

	call boxd(urr,vrr,pdd,ier)

      psi_r=pdd(2)
      b_z(i,j)=psi_r/urr*0.1d0

      psi_z=pdd(3)
	b_r(i,j)=-psi_z/urr*0.1d0

	b_fi(i,j)=f(i)*rs0/urr*0.1d0

	end do
	end do

	kk=0
	do i=1,n
	do j=1,m
	kk=kk+1
	cronos_fields(kk)=b_r(i,j)
	end do
	end do

	do i=1,n
	do j=1,m
	kk=kk+1
	cronos_fields(kk)=b_z(i,j)
	end do
	end do

	do i=1,n
	do j=1,m
	kk=kk+1
	cronos_fields(kk)=b_fi(i,j)
	end do
	end do

	do i=1,6
	a_print(i)=b_r(i,2)
	end do
	n_pr=6
	apr='  ** b_r **'
	num=20
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,6
	a_print(i)=b_z(i,2)
	end do
	n_pr=6
	apr='  ** b_z **'
	num=20
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,6
	a_print(i)=b_fi(i,2)
	end do
	n_pr=6
	apr='  ** b_fi **'
	num=20
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	return
	end


      

	subroutine time_iterp(time,

     *  pl_loop_mat,pl_probe_mat,

     *  d_pf_mat,

     *  shape_out  )

c      	include 'double.inc'
	

	implicit real *8 (a-h,o-z)

	

	dimension pl_loop_mat(*),pl_probe_mat(*),

     *  d_pf_mat(*),shape_out(*)

	

	include 'parf1'

	include 'parf4'



	common /c_time_interp1/

     *  pl_loop(nloop,3),pl_probe(nprobe,3),

     *  d_pf(kf,3)

	common /c_time_interp2/

     *  kloop,kprobe,npf

	common /c_time_interp3/

     *  t(3),count

	common /c_time_interp4/

     *  sh_out(100,3)



	dimension a_print(100)

                                                   

	character *20 apr





c	if(count.lt.3)return





	do i=1,kloop


	f_2=pl_loop(i,3)		


	pl_loop_mat(i)=f_2

	end do



	do i=1,kprobe


	f_2=pl_probe(i,3)		


	pl_probe_mat(i)=f_2

	end do



	do i=1,npf


	f_2=d_pf(i,3)		


	d_pf_mat(i)=f_2

	end do



	do i=1,3


	f_2=sh_out(i,3)		


	shape_out(i)=f_2

	end do


	return                                                                 

	end                                                                    

	subroutine time_iterp_old(time,

     *  pl_loop_mat,pl_probe_mat,

     *  d_pf_mat,

     *  shape_out  )

c      	include 'double.inc'
	

	implicit real *8 (a-h,o-z)

	

	dimension pl_loop_mat(*),pl_probe_mat(*),

     *  d_pf_mat(*),shape_out(*)

	

	include 'parf1'

	include 'parf4'



	common /c_time_interp1/

     *  pl_loop(nloop,3),pl_probe(nprobe,3),

     *  d_pf(kf,3)

	common /c_time_interp2/

     *  kloop,kprobe,npf

	common /c_time_interp3/

     *  t(3),count

	common /c_time_interp4/

     *  sh_out(100,3)



	dimension a_print(200)

                                                   

	character *20 apr





	if(count.lt.3)return



	a_0=t(1)

	a_1=t(2)

	a_2=t(3)



	teta=time



	do i=1,kloop

	f_0=pl_loop(i,1)	

	f_1=pl_loop(i,2)	

	f_2=pl_loop(i,3)		

	call inter_2p(f_0,f_1,f_2,a_0,a_1,a_2,teta,val)

	pl_loop_mat(i)=val

	end do



	do i=1,kprobe

	f_0=pl_probe(i,1)	

	f_1=pl_probe(i,2)	

	f_2=pl_probe(i,3)		

	call inter_2p(f_0,f_1,f_2,a_0,a_1,a_2,teta,val)

	pl_probe_mat(i)=val

	end do



	do i=1,npf

	f_0=d_pf(i,1)	

	f_1=d_pf(i,2)	

	f_2=d_pf(i,3)		

	call inter_2p(f_0,f_1,f_2,a_0,a_1,a_2,teta,val)

	d_pf_mat(i)=val

	end do



	do i=1,3

	f_0=sh_out(i,1)	

	f_1=sh_out(i,2)	

	f_2=sh_out(i,3)		

	call inter_2p(f_0,f_1,f_2,a_0,a_1,a_2,teta,val)

	shape_out(i)=val

	end do



	i_pr=0

	if(i_pr.eq.1)then



	a_print(1)=t(1)

	a_print(2)=t(2)

	a_print(3)=t(3)

	a_print(4)=time

	n_pr=4

	apr='t 1 -3 time'

	num=20

	i=1

!	if(kpr.eq.1)call out42(n_pr,a_print,num,apr)



	a_print(1)=pl_loop(i,1)

	a_print(2)=pl_loop(i,2)

	a_print(3)=pl_loop(i,3)

	a_print(4)=pl_loop_mat(i)

	n_pr=4

	apr='pl_loop 1*3 pl_loop_mat'

	num=20

	i=1

!	if(kpr.eq.1)call out42(n_pr,a_print,num,apr)

	a_print(1)=pl_probe(i,1)

	a_print(2)=pl_probe(i,2)

	a_print(3)=pl_probe(i,3)

	a_print(4)=pl_probe_mat(i)

	n_pr=4

	apr='pl_probe 1*3 pl_probe_mat'

	num=20

	i=1

!	if(kpr.eq.1)call out42(n_pr,a_print,num,apr)



	a_print(1)=d_pf(i,1)

	a_print(2)=d_pf(i,2)

	a_print(3)=d_pf(i,3)

	a_print(4)=d_pf_mat(i)

	n_pr=4

	apr='d_pf 1 -3 d_pf_mat'

	num=20

!	if(kpr.eq.1)call out42(n_pr,a_print,num,apr)



	end if



c	call inter_2p(f_0,f_1,f_2,a_0,a_1,a_2,teta,val)



	return                                                                 

	end                                                                    



	subroutine time_save(time,

     *  kloop_mat,kprobe_mat,npf_mat,

     *  pl_loop_mat,pl_probe_mat,

     *  d_pf_mat,

     *  shape_out)

	

	implicit real *8 (a-h,o-z)

	

	dimension pl_loop_mat(*),pl_probe_mat(*),

     *  d_pf_mat(*),shape_out(*)

	

	include 'parf1'

	include 'parf4'



	common /c_time_interp1/

     *  pl_loop(nloop,3),pl_probe(nprobe,3),

     *  d_pf(kf,3)

	common /c_time_interp2/

     *  kloop,kprobe,npf

	common /c_time_interp3/

     *  t(3),count

	common /c_time_interp4/

     *  sh_out(100,3)

	common

     *	/c_add0/i_en0



	dimension a_print(200)

                                                   

	character *20 apr



	if(i_en0.eq.1)count=0



	count=count+1



	kloop=kloop_mat

	kprobe=kprobe_mat

	npf=npf_mat



	t(1)=t(2)

	t(2)=t(3)

	t(3)=time



	do i=1,kloop

	pl_loop(i,1)=pl_loop(i,2)	

	pl_loop(i,2)=pl_loop(i,3)	

	pl_loop(i,3)=pl_loop_mat(i)		

	end do



	do i=1,kprobe

	pl_probe(i,1)=pl_probe(i,2)	

	pl_probe(i,2)=pl_probe(i,3)	

	pl_probe(i,3)=pl_probe_mat(i)

	end do



	do i=1,npf

	d_pf(i,1)=d_pf(i,2)	

	d_pf(i,2)=d_pf(i,3)	

	d_pf(i,3)=d_pf_mat(i)		

	end do



	do i=1,3

	sh_out(i,1)=sh_out(i,2)	

	sh_out(i,2)=sh_out(i,3)	

	sh_out(i,3)=shape_out(i)		

	end do



	a_print(1)=t(1)

	a_print(2)=t(2)

	a_print(3)=t(3)

	a_print(4)=time

	n_pr=4

	apr='t 1*3 time'

	num=20



	i=1

c	call out42(n_pr,a_print,num,apr)



	a_print(1)=pl_loop(i,1)

	a_print(2)=pl_loop(i,2)

	a_print(3)=pl_loop(i,3)

	a_print(4)=pl_loop_mat(i)

	n_pr=4

	apr='pl_loop 1*3 pl_loop_mat'

	num=20

	i=1

!	if(kpr.eq.1)call out42(n_pr,a_print,num,apr)

	a_print(1)=pl_probe(i,1)

	a_print(2)=pl_probe(i,2)

	a_print(3)=pl_probe(i,3)

	a_print(4)=pl_probe_mat(i)

	n_pr=4

	apr='pl_probe 1*3 pl_probe_mat'

	num=20

	i=1

!	if(kpr.eq.1)call out42(n_pr,a_print,num,apr)

	a_print(1)=d_pf(i,1)

	a_print(2)=d_pf(i,2)

	a_print(3)=d_pf(i,3)

	a_print(4)=d_pf_mat(i)

	n_pr=4

	apr='d_pf 1*3 d_pf_mat'

	num=20

c	call out42(n_pr,a_print,num,apr)







	return                                                                 

	end                                                                    



                                                                        

	

	subroutine  cur_prof_data()                                            
      	include 'double.inc'

	include 'new_com.inc'                                                  

                            

c!!        te_a=te_mat

        

!        print *,' te_mat===',te_mat

                                            

	rmag=rmag_mat*100.                                                     

	zmag=zmag_mat*100.                                                     

                                                                        

	r0=rmag                                                                

	z0=zmag                                                                

	rout=r0
	zout=z0


	um=rmag

	vm=zmag





c        print *,' from cur_progf zref zmag',zref,zmag

                                                                        

	zref=z0                                                                
	rref=r0
                                                                        

	rs0=rs0_mat*100.                                                       

                                                                        

	bt0=bt0_mat*10.                                                        

                                                                        

	tpl=tpl_mat*1.e-3                                                      

                                                                        

                                                                        

	tay=tay_mat*1.e3                                                       

                                                                        

                                                                        

                                                                        

	k_efit=kefit_mat                                                       

	if(kefit_mat.eq.0)then                                                 

	   beta=beta_mat                                                       

	   pw_1=pw_1_mat                                                       

	   pw_2=pw_2_mat                                                       

	end if                                                                 

                                                                        

	if(kefit_mat.eq.1.or.kefit_mat.eq.20)then                                                 

	   do i=1,2                                                            

	      alfax(i)=alfax_mat(i)                                            

	      betax(i)=betax_mat(i)                                            

	   end do                                                              

	end if                                                                 

                                                                        

	if(kefit_mat.eq.2)then                                                 

	   beta=beta_mat                                                       

	   alfa1=alfa1_mat                                                     

	end if                                                                 

                                                                        

	if(kpr.eq.1)then                                                      

	   print*,' KEFIT= beta alaf1',k_efit,beta,alfa1                                         

	   print *,' rmag zmag r0 z0 zref ',rmag,zmag,r0,z0,zref              

	   print *,' rs0 bt0 tpl tay',rs0,bt0,tpl,tay                         

	end if                                                                

                                                                        

                                                                        

	return                                                                 

	end                                                                    

                                                                        

	subroutine read_data()                                                 
      	include 'double.inc'

	include 'new_com.inc'                                                  

                                                                        

	call read_data_c(                                                      

     *  alf_dis,
     *  i_up,i_dw,r_bge,index,npf,i_gen)

                                                                        

	return                                                                 

	end                                                                    

                                                                        

	subroutine read_data_c(                                                

     *  alf_dis,
     *  i_up,i_dw,r_bge,index,npf,i_gen)
      	include 'double.inc'

	dimension index(*)

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

     *  /en1d/te_a0                                                     

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

                                                                        

c     	open(unit=2,file='for002',form='formatted')                      

!        if(kpr.eq.1)print *,' begin for002 reading'                    

                                                                        

                                                                        

                                                                        

c	n=36                                                                   

c	m=90                                                                   

c--------------------



c!	n=24

c	m=64

	m=90


c	next=4                                                                


	tay=0.1                                                                

!!!	t_end=100.                                                             

	rs0=86.                                                                

	psend=-1.e4                                                            

                                                                        

c temporarily	                                                                        
!	ind_z(1)=6
!	ind_z(2)=100






	alfa0=4.E-2                                                            

	beta=0.5                                                               

	alfa1=-0.1                                                             



                                                                        

c	omega=0.5 

	omega=1.

 

	iread=0                                                                

	kzero=0                                                                

	iwrite=0                                                               

	kefit=2                                                                

                                                                        

	pw_1=10.                                                               

	pw_2=2.                                                                

c	te_a=1000.                                                             
c	ti_a=1000.                                                             
c	te_b=10.                                                               
c	ti_b=10.                                                               

!	pw_e=0.4                                                               
!	pw_e=8.                                                              
!	pw_e=2.                                                              

!!	pd0_a=1. 

c!!	pd0_b=0.2

	pt0_a=pd0_a
	pt0_b=pd0_b

!	pw_p=2.                                                                

	zeff_a=1.
	zeff_b=1.

	zeff_a=1.                                                             
	zeff_b=1.                                                              

	sig0=5.3715E3                                                          
                                                                        

	zhib=4.5e-0                                                            

	tego=100.                                                              

	zalfa=4.                                                               

	talfa=500.                                                             

c	alp1=1.                                                                

                                                                        

	ktp=  1                                                                

	kpin= 1                                                                

	ken=  0                                                                

	ken1= 0                                                                

	ken2= 1                                                                

	kd2=  0                                                                

	nal=  1                                                                

                                                                        

	edop=20.                                                               

	ppp=1.e-0                                                              

	eee=40.e3                                                              

	dd= 1.                                                                 

	dt=0.                                                                  

	dh=0.                                                                  

	df=0.                                                                  

                                                                        

	lt=1                                                                   

	ld=1

                                                                        

c	lt=3                                                                   

c	ld=3                                                                   

	lh=1                                                                   

	ll=1                                                                   

	lm=3                                                                   

	it=1                                                                   

	id=1                                                                   

	ih=0                                                                   

                                                                        

	eps0=1.e-8                                                             

	eps1=1.e-3                                                             

!	eps2=1.e-3
                                                             
!	eps2=1.e-4                                                             

c	eps2=4.e-4                                                             


	anom_e=1.
                                                              
	anom_i=1.                                                              

c	key_t11=1



c###	kcchp=0                                                                

                                                                        

	emoe=0.                                                                

	emoq=0.                                                                

                                                                        

	udd=0.                                                                 

                                                                        

c###	k_ener=1                                                              

	k_uv=0                                                                 

                                                                        

	t_dop=1.e5                                                             

                                                                        

c	r0=80.                                                                 

c	z0=13.3                                                                

cc	zref=14.                                                               

                                                                        

	kzref=1                                                                

	krref=1                                                               

	key_b=2                                                                

	i_pf=5                                                                 

                                                                        

	i_c=0                                                                  

                                                                        

	q_vde=0.1                                                              

                                                                        

	tay_00=0.1                                                             

	tay_th=10.                                                             

	t_disr=2.                                                              

                                                                        

	d_tpl=1000.                                                            

	tpl_end=24100.                                                         

                                                                        

	c_h=5.                                                                 

	d_halo=150.                                                            

                                                                        

	kmaj=0                                                                 

	li_drop=99999                                                          

	ndisrup=99999                                                          

	n_dif=0                                                                

	nmix=20                                                                

                                                                        

	hpart=1.25                                                             

	te_h=5.                                                                

                                                                        

	i_d3d=0                                                                

	i_iter=1                                                               

	i_smal=0                                                               

                                                                        

	ngra=100

	i_ramp=0                                                               

	i_v=1                                                                  

!	i_con=0                                                                

                                                                        

c	tpl=750.                                                               

c	bt0=10.                                                                

!!!	eu=20.                                                                 

	eksk=1.5                                                               

                                                                        

c	e_sep=5.e-3

c	e_sep=2.e-2                                                            

                                                                        

	i_beta=0                                                               

	i_gap5=0                                                               

                                                                        

	i_br=0                                                                 

                                                                        

                                                                        

	i_feed=0                                                               

	i_ecoil=0                                                              

c*********************************************                          

                                                                        

	te_a0=6.                                                               

                                                                        

	alf_dis=1.                                                             

                                                                        

!        if(kpr.eq.1)print *,' end for002 reading'                      

                                                                        

                                                                        

	call edim1                                                             

                                                                        

!        if(kpr.eq.1)print *,' CALL ELKE...'                            

c        read (*,*)                                                     

                                                                        

	pnor=6.25e8                                                            

	emoe=emoe*pnor                                                         

	emoq=emoq*pnor                                                         

                                                                        

	ndh=1                                                                  

                                                                        

                                                                        

c	close(2)                                                              

                                                                        

c##	mp=(m-2)/2+2                                                        

                                                                        

	mp=m                                                                   

                                                                        

!	if(kpr.eq.1)print *,' n m mp',n,m,mp                                  

c	read (*,*)                                                            

                                                                        

                                                                        

c        rs=r0                                                           

c        zout=z0                                                         

c	um=r0                                                                  

c	vm=z0                                                                  

c	rmag=um                                                                

c	zmag=vm                                                                

                                                                        

!	if(kpr.eq.1)print *,' um vm eu elong',um,vm,eu,eksk                   

                                                                        

        if(kmag.eq.0.or.kmaj.eq.1)then                                  

                                                                        

c     	open(unit=2,file='halo',form='formatted')                        

                                                                        

!        if(kpr.eq.1)print *,' begin halo reading'                      

                                                                        

                                                                        

	w_h0=0.0                                                               

	te_h0=5.                                                               

                                                                        

!        if(kpr.eq.1)print *,' w_h0  te_h0==',w_h0,te_h0                

c	close(2)                                                              

                                                                        

        end if                                                          

c	print *,' read D i_con===',i_con

	if(i_con.eq.2)then

c ASDEX additional information for PSL coils...

	i_up=10	
	i_dw=11	
	r_bge=250.e-6


	if(kpr.eq.1)print *,' ASDEX data i_up i_dw r_bge==',
     *  i_up,i_dw,r_bge


c ASDEX additional information for index...
           k=0                                                          
           do j=1,npf 
	      index(j)=1
              if(index(j).ne.0)then                                     
                 k=k+1                                                  
                 index(j)=k                                             
              end if                                                    
           end do                                                       
                                                                        
       if(kpr.eq.1)print *,' index ',(index(k),k=1,npf)

	end if

        if(i_gen.eq.1)then
           open (unit=41,file='pf_index.dat',form='formatted')
           read (41,*)
           read (41,*)(index(i),i=1,npf)
           close (41)

        if(kpr.eq.1)print *,' index ',(index(k),k=1,npf)

        end if


c-------------------------------------------
                                                                        

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

c                                                                       

       subroutine  tran_to_dina_old(

     *  ncam_mat,npf_mat,kloop_mat,kprobe_mat,

     *  z_l,z_r,r_l,r_r,

     *  kf_mat,mu_mat,

     *  fluxarr_mat,vesarr_mat,

     *  pslgreen_mat,bprgreen_mat,

     *	pfind_mat,pmj_mat,pfc_mat,

     *  pfres_mat,rcam_mat,        

     *  xu_mat,yu_mat,ke_mat,key_mat)

      	include 'double.inc'


	include 'parf2'

                                           

        real*8 fluxarr_mat(nwnh,*),vesarr_mat(nwnh,*),                  

     *	pslgreen_mat(nwnh,*),bprgreen_mat(nwnh,*),                       

     *	pfind_mat(kf_mat,*),pmj_mat(mu_mat,*),                           

     *  pfc_mat(mu_mat,*),                                              

     *  pfres_mat(*),rcam_mat(*),                                       

     *  xu_mat(*),yu_mat(*)

                                   

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



        i_en0=0

        i_en2=0

        i_en3=0

        i_en4=0

                                                                

c        open(unit=41,file='f41',form='formatted')                  

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

                                                                        

c        write(41,*)' nre nze ',nre,nze                                  

                                                                        

c        write (41,*)' dx dy ',dx,dy                                     

                                                                        

                                                                        

	do i=1,nr                                                              

	x(i)=re(i)                                                             

c        write(41,*)' i x ',i,x(i)                                       

	end do                                                                 

                                                                        

	do i=1,nz                                                              

	   y(i)=ze(i)                                                          

c        write(41,*)' i y ',i,y(i)                                       

	end do                                                                 

                                                                        

c---------------------------------                                      

	ncam=ncam_mat                                                          

	npf=npf_mat                                                            

                                                                        

	kloop=kloop_mat                                                        

	kprobe=kprobe_mat                                                      

                                                                        

	ke=ke_mat                                                              

                                                                        

c       write(41,*)' ncam npf kloop kprobe ke',ncam,npf,kloop,kprobe,ke  

                                                                        

                                                                        

	do k=1,ke                                                              

	   xu(k)=xu_mat(k)*100.                                                

	   yu(k)=yu_mat(k)*100.                                                

c        write(41,*)' k xu yu ',k,xu(k),yu(k)                            

	end do                                                                 

                                                                        

                                                                        

	do k=1,ncam                                                            

	   rcam(k)=rcam_mat(k)                                                 

	   do kk=1,ncam                                                        

	      pmj(k,kk)=pmj_mat(k,kk)*1.e8                                     

	   end do                                                              

c        write(41,*)' k rcam pmj ',k,rcam(k),pmj(k,k)                    

	end do                                                                 

                                                                        

                                                                        

	do k=1,ncam                                                            

	   do kk=1,npf                                                         

	      pfc(k,kk)=pfc_mat(k,kk)*1.e8                                     

	   end do                                                              

c        write(41,*)' k pfc ',k,pfc(k,1),pfc(k,2),pfc(k,3)               

	end do                                                                 

                                                                        

	do k=1,npf                                                             

	      pfres(k)=pfres_mat(k)                                            

	   do kk=1,npf                                                         

	      pfind(k,kk)=pfind_mat(k,kk)*1.e8                                 

	   end do                                                              

c        write(41,*)' k pfres pfind ',k,pfres(k),pfind(k,k)              

	end do                                                                 

                                                                        

                                                                        

                                                                        

	do k=1,ncam                                                            

	   do kk=1,nwnh                                                        

	      vesarr(kk,k)=vesarr_mat(kk,k)*1.e8                               

	   end do                                                              

c        write(41,*)' k vesarr ',k,vesarr(1,k),vesarr(2,k),vesarr(3,k)   

	end do                                                                 

	do k=1,npf                                                             

	   do kk=1,nwnh                                                        

	      fluxarr(kk,k)=fluxarr_mat(kk,k)*1.e8                        

	   end do                                                              

c        write(41,*)'k fluxarr',k,fluxarr(1,k),                          

c     *  fluxarr(2,k),fluxarr(3,k)                                       

	end do                                                                 

	if(kloop.gt.0)then                                                     

	   do k=1,kloop                                                        

	      do kk=1,nwnh                                                     

		 pslgreen(kk,k)=pslgreen_mat(kk,k)*1.e8

	      end do

c        write(41,*)'k pslgreen ',k,pslgreen(1,k),                       

c     *  pslgreen(2,k),pslgreen(3,k)                                     

	   end do                                                              

	end if                                                                 

                                                                        

	if(kprobe.gt.0)then                                                    

	   do k=1,kprobe                                                       

	      do kk=1,nwnh                                                     

		 bprgreen(kk,k)=bprgreen_mat(kk,k)*1.e4

	      end do

c        write(41,*)'k bprgreen ',k,bprgreen(1,k),                       

c     *  bprgreen(2,k),bprgreen(3,k)                                     

	   end do                                                              

	end if                                                                 

c       	close (41)                                                      

c                                                                       

        RETURN                                                          

        END                                                             

c                                                                       

      subroutine  write_pf_mat(                                       

     *  pf_mat,npf_mat)                                                 
      	include 'double.inc'

	real*8 pf_mat(*)                                                       

                                                                        
	open (unit=41,file='cc0.fla',form='formatted')                        

                                                                        

	write (41,*)npf_mat                                                     

	write(41,*)'  npf_mat'                                                            

	do k=1,npf_mat                                                         

	   write (41,*)pf_mat(k)                                                

	end do                                                                 

	write(41,*)'  '
	
	  
                                                                        


c	open (unit=41,file='pf_temp.dat',form='unformatted')                   

c	write (41)(pf_mat(k),k=1,npf_mat)                                      

	close (41)                                                             

                                                                        

	return                                                                 

	end                                                                    

      subroutine  write_tcam_mat(                                       

     *  tcam_mat,ncam_mat)                                                 
      	include 'double.inc'

	real*8 tcam_mat(*)                                                       

                                                                        
	open (unit=41,file='tcam.fla',form='formatted')                        

                                                                        

	write (41,*)ncam_mat                                                     

	write(41,*)'  ncam_mat'                                                            

	do k=1,ncam_mat                                                         

	   write (41,*)tcam_mat(k)                                                

	end do                                                                 

	write(41,*)'  '
	
	  
                                                                        


c	open (unit=41,file='pf_temp.dat',form='unformatted')                   

c	write (41)(pf_mat(k),k=1,npf_mat)                                      

	close (41)                                                             

                                                                        

	return                                                                 

	end                                                                    



       subroutine  read_pf_mat(                                        

     *  pf_mat,npf_mat)                                                 
      	include 'double.inc'

	real*8 pf_mat(*)                                                       

                                                                        

	open (unit=41,file='cc0.flat',form='formatted')                        

                                                                        

	read (41,*)npf_mat                                                     

	read (41,*)                                                            

	do k=1,npf_mat                                                         

	   read (41,*)pf_mat(k)                                                

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

c        open (unit=41,file='pf_temp.dat',form='unformatted')           

c        read (41)(pf_mat(k),k=1,npf_mat)                               

c        close (41)                                                     

                                                                        

	return                                                                 

	end                                                                    
        subroutine  read_to_mat(                                        

     *  ncam_mat,npf_mat,kloop_mat,kprobe_mat,                          

     *  z_l,z_r,r_l,r_r,                                                

     *  kf_mat,mu_mat,                                                  

     *  fluxarr_mat,vesarr_mat,                                         

     *  pslgreen_mat,bprgreen_mat,                                      

     *	pfind_mat,pmj_mat,pfc_mat,                                       

     *  pfres_mat,rcam_mat,                                             

     *  xu_mat,yu_mat,ke_mat,                                           

     *  pf_mat)                                                         

      	include 'double.inc'
                                                                        

	include 'parf2'                                                        

                                                                        

        real*8 fluxarr_mat(nwnh,*),vesarr_mat(nwnh,*),                  

     *	pslgreen_mat(nwnh,*),bprgreen_mat(nwnh,*),                       

     *	pfind_mat(kf_mat,*),pmj_mat(mu_mat,*),                           

     *  pfc_mat(mu_mat,*),                                              

     *  pfres_mat(*),rcam_mat(*),                                       

     *  xu_mat(*),yu_mat(*),                                            

     *  pf_mat(*)                                                       

                                                                        

	real *8 z_l,z_r,r_l,r_r                                                

                                                                        

                                                                        

!!!	open (unit=41,file='mat_temp.dat',form='unformatted')                  
	open (unit=41,file='mat_temp.dat',form='formatted')                  

5000    format (6(1pe14.7))
                                                                        

	read (41,*)z_l,z_r,r_l,r_r                                               

	read (41,*)ncam_mat,npf_mat,ke_mat                                       

	read (41,*)kloop_mat,kprobe_mat                                          

                                                                        

c	print *,' z_l z_r r_l r_r==',z_l,z_r,r_l,r_r                          

c	print *,' ncam_mat,npf_mat,ke_mat',ncam_mat,npf_mat,ke_mat            

c	print *,' kloop_mat,kprobe_mat',kloop_mat,kprobe_mat                  

                                                                        

	read (41,5000)(xu_mat(k),yu_mat(k),k=1,ke_mat)                              

c	print *,' here'
                                                                        

	read (41,5000)(rcam_mat(k),k=1,ncam_mat)                                    

c	call pau()	
c	stop                                                                        

	do kk=1,ncam_mat                                                       

	   read (41,5000)(pmj_mat(k,kk),k=1,ncam_mat)                               

	end do                                                                 

	                                                                        

	do kk=1,npf_mat                                                        

	   read (41,5000)(pfc_mat(k,kk),k=1,ncam_mat)                               

	end do                                                                 

                                                                        

                                                                        

	read (41,5000)(pfres_mat(k),k=1,npf_mat)                                    

                                                                        

	do kk=1,npf_mat                                                        

	   read (41,5000)(pfind_mat(k,kk),k=1,npf_mat)                              

	end do                                                                 

                                                                        

                                                                        

	do kk=1,nwnh                                                           

	   read (41,5000)(vesarr_mat(kk,k),k=1,ncam_mat)                            

	end do                                                                 

                                                                        

	do kk=1,nwnh                                                           

	   read (41,5000)(fluxarr_mat(kk,k),k=1,npf_mat)                            

	end do                                                                 

                                                                        

	do kk=1,nwnh                                                           

	   read (41,5000)(pslgreen_mat(kk,k),k=1,kloop_mat)                         

	end do                                                                 

                                                                        

	do kk=1,nwnh                                                           

	   read (41,5000)(bprgreen_mat(kk,k),k=1,kprobe_mat)                        

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

                                                                        

c                                                                       

        RETURN                                                          

        END                                                             
        subroutine  tran_to_mat(                                        

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

      	include 'double.inc'


	include 'parf2'                                                        

                                                                        

        real*8 fluxarr_mat(nwnh,*),vesarr_mat(nwnh,*),                  

     *	pslgreen_mat(nwnh,*),bprgreen_mat(nwnh,*),                       

     *	pfind_mat(kf_mat,*),pmj_mat(mu_mat,*),                           

     *  pfc_mat(mu_mat,*),                                              

     *  pfres_mat(*),rcam_mat(*),                                       

     *  xu_mat(*),yu_mat(*),                                            

     *  pf_mat(*),tcam_mat(*),

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

                                                                        

                                                                        

	z_l=ze(1)*0.01                                                         

	z_r=ze(nze)*0.01                                                       

                                                                        

	r_l=re(1)*0.01                                                         

	r_r=re(nre)*0.01                                                       



c        print *,' r_l r_r z_l z_r ',r_l,r_r,z_l,z_r

                                                                        

c---------------------------------                                      

                                                                        

	ncam_mat=ncam                                                          

	npf_mat=npf                                                            

                                                                        

	ke_mat=ke                                                              

                                                                        

	do k=1,npf                                                             

	   pf_mat(k)=pf(k)*1.e3                                                

	end do                                                                 

                                                                        

	do k=1,ke                                                              

	   xu_mat(k)=xu(k)*0.01                                                

	   yu_mat(k)=yu(k)*0.01                                                

	end do                                                                 

                                                                        

                                                                        

	kloop_mat=kloop                                                        

	kprobe_mat=kprobe                                                      

                                                                        

	do k=1,ncam                                                            

	   rcam_mat(k)=rcam(k)                                                 

	   tcam_mat(k)=tcam(k)*1.e3               

	   do kk=1,ncam                                                        

	      pmj_mat(k,kk)=pmj(k,kk)*1.e-8                                    

	   end do                                                              

	end do                                                                 

                                                                        

	do k=1,ncam                                                            

	   do kk=1,npf                                                         

	      pfc_mat(k,kk)=pfc(k,kk)*1.e-8                                    

	   end do                                                              

	end do                                                                 

                                                                        

	do k=1,npf                                                             

	      pfres_mat(k)=pfres(k)                                            

	   do kk=1,npf                                                         

	      pfind_mat(k,kk)=pfind(k,kk)*1.e-8                                

	   end do                                                              

	end do                                                                 

                                                                        

	do k=1,ncam                                                            

	   do kk=1,nwnh                                                        

	      vesarr_mat(kk,k)=vesarr(kk,k)*1.e-8                              

	   end do                                                              

	end do                                                                 

                                                                        

	do k=1,npf                                                             

	   do kk=1,nwnh                                                        

	      fluxarr_mat(kk,k)=fluxarr(kk,k)*1.e-8                            

	   end do                                                              

	end do                                                                 

                                                                        

	if(kloop.gt.0)then                                                     

	   do k=1,kloop                                                        

	      do kk=1,nwnh                                                     

		 pslgreen_mat(kk,k)=pslgreen(kk,k)*1.e-8

	      end do                                                           

	      do kk=1,npf

		 pfgreen_mat(k,kk)=pfgreen(k,kk)*1.e-8 

	      end do                                                           

	      do kk=1,ncam

		 vesgreen_mat(k,kk)=vesgreen(k,kk)*1.e-8 

	      end do                                                           

	   end do                                                              

	end if                                                                 

                                                                        

	if(kprobe.gt.0)then                                                    

	   do k=1,kprobe

	      do kk=1,nwnh                                                     

		 bprgreen_mat(kk,k)=bprgreen(kk,k)*1.e-4

	      end do                                                           

	      do kk=1,npf

		 pfprobe_mat(k,kk)=pfprobe(k,kk)*1.e-4

	      end do                                                           

	      do kk=1,ncam

		 vesprobe_mat(k,kk)=vesprobe(k,kk)*1.e-4

	      end do                                                           

	   end do                                                              

	end if                                                                 

                                                                        

c       print *,'k kk vesgreen(k,kk)',k,kk,vesgreen(k,kk)

                                                                        

	open (unit=41,file='mat_temp.dat',                                     

     *  form='formatted')                                             

5000    format (6(1pe14.7))
                                                                        

	write (41,5000)z_l,z_r,r_l,r_r                                              

	write (41,*)ncam_mat,npf_mat,ke_mat                                      

	write (41,*)kloop_mat,kprobe_mat                                         

                                                                        

	write (41,5000)(xu_mat(k),yu_mat(k),k=1,ke_mat)                             

                                                                        

	write (41,5000)(rcam_mat(k),k=1,ncam_mat)                                   

                                                                        

	do kk=1,ncam_mat                                                       

	   write (41,5000)(pmj_mat(k,kk),k=1,ncam_mat)                              

	end do                                                                 

                                                                        

	do kk=1,npf_mat                                                        

	   write (41,5000)(pfc_mat(k,kk),k=1,ncam_mat)                              

	end do                                                                 

                                                                        

                                                                        

	write (41,5000)(pfres_mat(k),k=1,npf_mat)                                   

                                                                        

	do kk=1,npf_mat                                                        

	   write (41,5000)(pfind_mat(k,kk),k=1,npf_mat)                             

	end do                                                                 

                                                                        

                                                                        

	do kk=1,nwnh                                                           

	   write (41,5000)(vesarr_mat(kk,k),k=1,ncam_mat)                           

	end do                                                                 

                                                                        

	do kk=1,nwnh                                                           

	   write (41,5000)(fluxarr_mat(kk,k),k=1,npf_mat)                           

	end do                                                                 

                                                                        

	do kk=1,nwnh                                                           

	   write (41,5000)(pslgreen_mat(kk,k),k=1,kloop_mat)                        

	end do                                                                 

                                                                        

	do kk=1,nwnh                                                           

	   write (41,5000)(bprgreen_mat(kk,k),k=1,kprobe_mat)                       

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

c                                                                       

        RETURN                                                          

        END                                                             

c                                                                       

                                                                        

	subroutine gen_mat()                                                   

      	include 'double.inc'
                                                                        

	include 'new_com.inc'                                                  

                                                                        

	do i=1,ncam                                                            

	   t_gen(i)=tcam(i)                                                    

	end do                                                                 

                                                                        

	do i=1,npf                                                             

	   t_gen(i+ncam)=pf(i)                                                 

	end do                                                                 

                                                                        

	return                                                                 

	end                                                                    

	subroutine gen_dina()                                                  

      	include 'double.inc'
                                                                        

	include 'new_com.inc'                                                  

                                                                        

	do i=1,ncam                                                            

	   tcam(i)=t_gen(i)                                                    

	end do                                                                 

                                                                        

	do i=1,npf                                                             

	   pf(i)=t_gen(i+ncam)                                                 

	end do                                                                 

                                                                        

	return                                                                 

	end                                                                    

	subroutine pl_diag_63(                                                    

     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)                  

      	include 'double.inc'
                                                                        

	real*8 pl_loop_mat(*),pl_probe_mat(*),                                 

     *  pl_pf_mat(*),pl_ves_mat(*)                                      

                                                                        

                                                                        

	include 'new_com.inc'                                                  

                                                                        

	character *12 apr                                                      
c                                                                       
	dimension dh1(npo),dh2(npo),q_xx(npo),e_xx(npo),tok1_xx(npo),
     *  ajb_xx(npo),aje_xx(npo),sb_xx(npo),psi_xx(npo),gra1_xx(npo)
c                                                                       

                                                                        
!	if(kpr.eq.1)print *,' n===',n


	do i=2,n-1
	   dh1(i)=ha(i)/(ha(i)+ha(i+1))
	   dh2(i)=ha(i+1)/(ha(i)+ha(i+1))    
	end do                                      

c	   te0(1)=te0(2)
c	   tq0(1)=tq0(2)
	   q(1)=q(2)
	   volt(1)=volt(2)
	   pne(1)=pne(2)
	   ajb(1)=ajb(2)
	   aj0_ech2(1)=aj0_ech2(2)
	   sb_ech2(1)=sb_ech2(2)

	do i=1,n
	      tok1_xx(i)=tok1(i)
	end do

	   do i=2,n-1
	      q_xx(i)=q(i+1)*dh1(i)+q(i)*dh2(i)
	      e_xx(i)=(volt(i+1)*dh1(i)+volt(i)*dh2(i))
	      ajb_xx(i)=ajb(i+1)*dh1(i)+ajb(i)*dh2(i)
	      aje_xx(i)=aj0_ech2(i+1)*dh1(i)+aj0_ech2(i)*dh2(i)
	      sb_xx(i)=sb_ech2(i+1)*dh1(i)+sb_ech2(i)*dh2(i)

	      gra1_xx(i)=gra1(i+1)*dh1(i)+gra1(i)*dh2(i)

	   end do

	   q_xx(1)=q_xx(2)
	   e_xx(1)=e_xx(2)
	   ajb_xx(1)=ajb_xx(2)
	   aje_xx(1)=aje_xx(2)
	   sb_xx(1)=sb_xx(2)

	   gra1_xx(1)=0.;

 	teta_xx=1.
        call inter_h0(q,ai,n,teta_xx,val)
	q_xx(n)=val

        call inter_h0(volt,ai,n,teta_xx,val)
	e_xx(n)=val

        call inter_h0(ajb,ai,n,teta_xx,val)
	ajb_xx(n)=val


        call inter_h0(aj0_ech2,ai,n,teta_xx,val)
	aje_xx(n)=val

        call inter_h0(sb_ech2,ai,n,teta_xx,val)
	sb_xx(n)=val

        call inter_h0(gra1,ai,n,teta_xx,val)
	gra1_xx(n)=val

	   psi_xx(1)=0.                                    
	   do i=2,n 
	      psi_xxi= (dm0(i)-dm0(1))/(dm0(n)-dm0(1))
	      psi_xx(i)=sqrt(psi_xxi) 
	   end do

	PNOR=6.25E8
	   
	   do i=1,n 
	      e_xx(i)=e_xx(i)/(2.*pi*rmag*1.e-2)
	      vol(i)=vol(i)*1.e-6
	      spov(i)=spov(i)*1.e-4

c!	      tok1_xx(i)=tok1_xx(i)*0.1
	      tok1_xx(i)=tok1(i)*1.e7

	      q_xx(i)=q(i)

c	      ajb_xx(i)=ajb_xx(i)*1.e7
	      ajb_xx(i)=ajb(i)*1.e7

c	      aje_xx(i)=aje_xx(i)*1.e7
	      aje_xx(i)=aj0_ech2(i)*1.e7

c	      sb_xx(i)=sb_xx(i)/pnor*1.e6
	      sb_xx(i)=sb_ech2(i)/pnor*1.e6

	      gra1_xx(i)=gra1(i)*1.e2
	   end do


        call inter_axis(q,ai,4,teta_xx,val)
	q_xx(1)=val

        call inter_axis(volt,ai,4,teta_xx,val)
	e_xx(1)=val

        call inter_axis(ajb,ai,4,teta_xx,val)
	ajb_xx(1)=val


        call inter_axis(aj0_ech2,ai,4,teta_xx,val)
	aje_xx(1)=val

        call inter_axis(sb_ech2,ai,4,teta_xx,val)
	sb_xx(1)=val


        call inter_axis(gra1,ai,4,teta_xx,val)
	gra1_xx(1)=val





	do k=1,n
	   i=k
	   pl_ves_mat(i)=te0(k)
	   i=n+k
	   pl_ves_mat(i)=tq0(k)
	   i=2*n+k
	   pl_ves_mat(i)=q_xx(k)
	   i=3*n+k
	   pl_ves_mat(i)=e_xx(k)
	   i=4*n+k
	   pl_ves_mat(i)=pne(k)*1.e19
	   i=5*n+k
	   pl_ves_mat(i)=tok1_xx(k)
	   i=6*n+k
	   pl_ves_mat(i)=ajb_xx(k)
	   i=7*n+k
	   pl_ves_mat(i)=aje_xx(k)
	   i=8*n+k
	   pl_ves_mat(i)=sb_xx(k)
	   i=9*n+k
	   pl_ves_mat(i)=psi_xx(k)
	   i=10*n+k
	   pl_ves_mat(i)=gra1_xx(k)
	   i=11*n+k

	DKOF=10./(4.*PI)                                                       
!!!!	   pl_ves_mat(i)=dkof*c20(k)

	   pl_ves_mat(i)=vol(k)
c	   pl_ves_mat(i)=dxe(k)
	end do             


	apr=' gra1--'                                                       
c	print 71,apr,(gra1(j),j=1,n)


	if(kpr.eq.-3)then
	apr=' te0--'
	print 71,apr,(pl_ves_mat(j),j=1,n)
	apr=' tq0--'                                                       
	print 71,apr,(pl_ves_mat(j),j=n+1,n+n)
	apr=' q--'                                                       
	print 71,apr,(pl_ves_mat(j),j=2*n+1,2*n+n)
	apr=' volt--'                                                       
	print 71,apr,(pl_ves_mat(j),j=3*n+1,3*n+n)
	apr=' pne--'                                                       
	print 71,apr,(pl_ves_mat(j),j=4*n+1,4*n+n)
	apr=' tok1--'                                                       
	print 71,apr,(pl_ves_mat(j),j=5*n+1,5*n+n)
	apr=' ajb--'                                                       
	print 71,apr,(pl_ves_mat(j),j=6*n+1,6*n+n)
	apr=' aje--'                                                       
	print 71,apr,(pl_ves_mat(j),j=7*n+1,8*n)
	apr=' sb--'                                                       
	print 71,apr,(pl_ves_mat(j),j=8*n+1,9*n)
	apr=' psi_nor--'                                                       
	print 71,apr,(pl_ves_mat(j),j=9*n+1,10*n)
	apr=' gra1--'                                                       
	print 71,apr,(pl_ves_mat(j),j=10*n+1,11*n)
	apr=' vol--'                                                       
	print 71,apr,(pl_ves_mat(j),j=11*n+1,12*n)

	end if

	apr=' vol--'                                                       
c	print 71,apr,(pl_ves_mat(j),j=11*n+1,12*n)

	
	if(kloop.gt.0)then                                                     

	   do k=1,kloop                                                        

c OLD	      pl_loop_mat(k)=psloopp(k)*1.e-5                                  

	      pl_loop_mat(k)=psloop(k)

	   end do                                                              

	end if                                                                 

c                                                                       

	if(kprobe.gt.0)then                                                    

	   do k=1,kprobe                                                       

c OLD	      pl_probe_mat(k)=bprobep(k)*0.1                                   

	      pl_probe_mat(k)=bprobe(k)

	   end do                                                              

	end if                                                                 

                                                                        

c                                                                       

	do k=1,npf                                                             

	   pl_pf_mat(k)=pl_pf_volt(k)                                        

	end do                                                                 

c                                                                       

c	do k=1,ncam                                                            

c	   pl_ves_mat(k)=psp(k)*1.e-5                                          

c	   pl_ves_mat(k)=pl_ves_volt(k)

c	end do                                                                 

                                                                        

	apr='pl_loop'                                                          

!	if(kpr.eq.1)print 71,apr,(pl_loop_mat(j),j=1,kloop)                   

	apr='pl_probe'                                                         

!	if(kpr.eq.1)print 71,apr,(pl_probe_mat(j),j=1,kprobe)                 

                      

c        if(kpr.eq.1)then                                          

c	apr='pl_pf_mat'                                                        

c	print 71,apr,(pl_pf_mat(j),j=1,npf)                       

                                                                        

c	apr='pl_ves_mat'                                                       

c	print 71,apr,(pl_ves_mat(j),j=1,ncam)

c        endif

                                                                        

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))                                      

                                                                        

	return                                                                 

	end                                                                    

	subroutine pl_diag_71(
     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)                  

      	include 'double.inc'
                                                                        

	real*8 pl_loop_mat(*),pl_probe_mat(*),                                 

     *  pl_pf_mat(*),pl_ves_mat(*)                  

	include 'new_com.inc'                                                  

                                                                        

	character *12 apr                                                      
c                                                                       
	dimension dh1(npo),dh2(npo),q_xx(npo),e_xx(npo),tok1_xx(npo),
     *  ajb_xx(npo),aje_xx(npo),sb_xx(npo),psi_xx(npo),gra1_xx(npo),
     *  a_m_xx(npo),r_m_xx(npo),x_e_neo_xx(npo),x_i_neo_xx(npo),
     *  f_xx(npo),ft_xx(npo)
c                                                                       

                                                                        
!	if(kpr.eq.1)print *,' n===',n



	do i=2,n-1
	   dh1(i)=ha(i)/(ha(i)+ha(i+1))
	   dh2(i)=ha(i+1)/(ha(i)+ha(i+1))    
	end do                                      

!	   te0(1)=te0(2)
!	   tq0(1)=tq0(2)
	   q(1)=q(2)
	   volt(1)=volt(2)
	   pne(1)=pne(2)
	   ajb(1)=ajb(2)
	   aj0_ech2(1)=aj0_ech2(2)
	   sb_ech2(1)=sb_ech2(2)

c---------------------------------------
	do i=1,n
	      tok1_xx(i)=tok1(i)
	end do

	   i_inter=0
	   if(i_inter.eq.1)then

	   do i=2,n-1
	      q_xx(i)=q(i+1)*dh1(i)+q(i)*dh2(i)
	      e_xx(i)=(volt(i+1)*dh1(i)+volt(i)*dh2(i))
	      ajb_xx(i)=ajb(i+1)*dh1(i)+ajb(i)*dh2(i)
	      aje_xx(i)=aj0_ech2(i+1)*dh1(i)+aj0_ech2(i)*dh2(i)
	      sb_xx(i)=sb_ech2(i+1)*dh1(i)+sb_ech2(i)*dh2(i)

	      gra1_xx(i)=gra1(i+1)*dh1(i)+gra1(i)*dh2(i)
	      x_e_neo_xx(i)=x_e_neo(i+1)*dh1(i)+x_e_neo(i)*dh2(i)
	      x_i_neo_xx(i)=x_i_neo(i+1)*dh1(i)+x_i_neo(i)*dh2(i)
	      ft_xx(i)=ft(i+1)*dh1(i)+ft(i)*dh2(i)
	      f_xx(i)=f(i+1)*dh1(i)+f(i)*dh2(i)

	   end do

	   else


	   do i=2,n
	      q_xx(i)=q(i)
	      e_xx(i)=volt(i)
	      ajb_xx(i)=ajb(i)
	      aje_xx(i)=aj0_ech2(i)
	      sb_xx(i)=sb_ech2(i)

	      gra1_xx(i)=gra1(i)
	      x_e_neo_xx(i)=x_e_neo(i)
	      x_i_neo_xx(i)=x_i_neo(i)
	      ft_xx(i)=ft(i)
	      f_xx(i)=f(i)

	   end do

	   end if


	   do i=2,n
	      a_m_xx(i)=a_m(i)*1.e-2
	      r_m_xx(i)=r_m(i)*1.e-2
	   end do
	   
	   a_m_xx(1)=0.
	   r_m_xx(1)=r_m_xx(2)
	   
	   q_xx(1)=q_xx(2)
	   e_xx(1)=e_xx(2)
	   ajb_xx(1)=ajb_xx(2)
	   aje_xx(1)=aje_xx(2)
	   sb_xx(1)=sb_xx(2)

	if(i_inter.eq.1)then
	      
 	teta_xx=1.
        call inter_h0(q,ai,n,teta_xx,val)
	q_xx(n)=val

        call inter_h0(volt,ai,n,teta_xx,val)
	e_xx(n)=val

        call inter_h0(ajb,ai,n,teta_xx,val)
	ajb_xx(n)=val


        call inter_h0(aj0_ech2,ai,n,teta_xx,val)
	aje_xx(n)=val

        call inter_h0(sb_ech2,ai,n,teta_xx,val)
	sb_xx(n)=val

        call inter_h0(gra1,ai,n,teta_xx,val)
	gra1_xx(n)=val

        call inter_h0(x_e_neo,ai,n,teta_xx,val)
	x_e_neo_xx(n)=val

        call inter_h0(x_i_neo,ai,n,teta_xx,val)
	x_i_neo_xx(n)=val

        call inter_h0(ft,ai,n,teta_xx,val)
	ft_xx(n)=val

        call inter_h0(f,ai,n,teta_xx,val)
	f_xx(n)=val

	end if



        call inter_axis(q,ai,4,teta_xx,val)
	q_xx(1)=val

        call inter_axis(volt,ai,4,teta_xx,val)
	e_xx(1)=val

        call inter_axis(ajb,ai,4,teta_xx,val)
	ajb_xx(1)=val


        call inter_axis(aj0_ech2,ai,4,teta_xx,val)
	aje_xx(1)=val

        call inter_axis(sb_ech2,ai,4,teta_xx,val)
	sb_xx(1)=val


        call inter_axis(gra1,ai,4,teta_xx,val)
	gra1_xx(1)=val

        call inter_axis(x_e_neo,ai,4,teta_xx,val)
	x_e_neo_xx(1)=val

        call inter_axis(x_i_neo,ai,4,teta_xx,val)
	x_i_neo_xx(1)=val

        call inter_axis(ft,ai,4,teta_xx,val)
	ft_xx(1)=val

        call inter_axis(f,ai,4,teta_xx,val)
	f_xx(1)=val


	i_debug=0
	if(i_debug.eq.1)then

 	print *,' ai',(ai(i),i=1,4)
 	print *,' gra1',(gra1_xx(i),i=1,4)
 	print *,' x_e_neo_xx',(x_e_neo_xx(i),i=1,2),(x_e_neo_xx(i),i=n-2,n)
 	print *,' x_i_neo_xx',(x_i_neo_xx(i),i=1,2),(x_i_neo_xx(i),i=n-2,n)

 	print *,' x_e_neo',(x_e_neo(i),i=1,2),(x_e_neo(i),i=n-2,n)
 	print *,' x_i_neo',(x_i_neo(i),i=1,2),(x_i_neo(i),i=n-2,n)

 	print *,' ft',(ft(i),i=1,2),(ft(i),i=n-2,n)
 	print *,' f',(f(i),i=1,2),(f(i),i=n-2,n)


 	print *,' te0',(te0(i),i=1,3)
 	print *,' tq0',(tq0(i),i=1,3)
 	print *,' pne',(pne(i),i=1,3)

	end if


c	   psi_xx(1)=0.                                    
c	   do i=2,n 
c	      psi_xxi= (dm0(i)-dm0(1))/(dm0(n)-dm0(1))
c	      psi_xx(i)=sqrt(psi_xxi) 
c	   end do


	do i=1,n 
	   f_xx(i)=f_xx(i)*(rs0*0.01)*0.1
	end do


	do i=1,n 
c	   psi_xx(i)=(dm0(1)-dm0(i))/(dm0(1)-dm0(n))

	   psi_xx(i)=dm0(i)*1.e-5

c	   psi_xx(i)=sqrt(psi_xx(i)) 
	end do

c	do i=1,n 
c	   psi_xx(i)=( psval(1)+psi_xx(i)*
c     *  (psval(n)-psval(1))  )*2.*pi*1.e-5
c	end do

	PNOR=6.25E8
	   
	   do i=1,n 
	      e_xx(i)=e_xx(i)/(2.*pi*rmag*1.e-2)
	      vol(i)=vol(i)*1.e-6
	      spov(i)=spov(i)*1.e-4

	      tok1_xx(i)=tok1_xx(i)*1.e7
c!!	      tok1_xx(i)=tok1(i)*1.e7

c!!	      q_xx(i)=q(i)

	      ajb_xx(i)=ajb_xx(i)*1.e7
c	      ajb_xx(i)=ajb(i)*1.e7

	      aje_xx(i)=aje_xx(i)*1.e7
c	      aje_xx(i)=aj0_ech2(i)*1.e7

	      sb_xx(i)=sb_xx(i)/pnor*1.e6
c	      sb_xx(i)=sb_ech2(i)/pnor*1.e6

c	      gra1_xx(i)=gra1(i)*1.e2
	      gra1_xx(i)=gra1_xx(i)*1.e2
	   end do

	do k=1,n
	   i=k
	   pl_ves_mat(i)=te0(k)
	   i=n+k
	   pl_ves_mat(i)=tq0(k)
	   i=2*n+k
	   pl_ves_mat(i)=q_xx(k)
	   i=3*n+k
	   pl_ves_mat(i)=gra1_xx(k)
	   i=4*n+k
	   pl_ves_mat(i)=psi_xx(k)
	   i=5*n+k
	   pl_ves_mat(i)=zeff(k)
	   i=6*n+k
	   pl_ves_mat(i)=x_e_neo_xx(k)
	   i=7*n+k
	   pl_ves_mat(i)=x_i_neo_xx(k)
	   i=8*n+k
	   pl_ves_mat(i)=a_m_xx(k)
	   i=9*n+k
	   pl_ves_mat(i)=r_m_xx(k)
	   i=10*n+k
	   pl_ves_mat(i)=pne(k)*1.e19
	   i=11*n+k
	   pl_ves_mat(i)=ft_xx(k)
	   i=12*n+k
	   pl_ves_mat(i)=f_xx(k)

c-----------------------

	   i=13*n+k
	   pl_ves_mat(i)=e_xx(k)
	   i=14*n+k
	   pl_ves_mat(i)=tok1_xx(k)
	   i=15*n+k
	   pl_ves_mat(i)=ajb_xx(k)
	   i=16*n+k
	   pl_ves_mat(i)=aje_xx(k)
	   i=17*n+k
	   pl_ves_mat(i)=sb_xx(k)
	   i=18*n+k
	   pl_ves_mat(i)=vol(k)


	end do             

	apr=' psi_xx--'                                                       
c	print 71,apr,(psi_xx(j),j=1,n)


	if(kpr.eq.-1)then
	apr=' te0--'
	print 71,apr,(pl_ves_mat(j),j=1,n)
	apr=' tq0--'                                                       
	print 71,apr,(pl_ves_mat(j),j=n+1,n+n)
	apr=' q--'                                                       
	print 71,apr,(pl_ves_mat(j),j=2*n+1,2*n+n)
	apr=' gra1--'                                                       
	print 71,apr,(pl_ves_mat(j),j=3*n+1,3*n+n)
	apr=' psi_nor--'                                                       
	print 71,apr,(pl_ves_mat(j),j=4*n+1,4*n+n)
	apr=' zeff--'                                                       
	print 71,apr,(pl_ves_mat(j),j=5*n+1,5*n+n)
	apr=' x_e_neo--'                                                       
	print 71,apr,(pl_ves_mat(j),j=6*n+1,6*n+n)
	apr=' x_i_neo--'                                                       
	print 71,apr,(pl_ves_mat(j),j=7*n+1,8*n)
	apr=' a_m--'                                                       
	print 71,apr,(pl_ves_mat(j),j=8*n+1,9*n)
	apr=' r_m--'                                                       
	print 71,apr,(pl_ves_mat(j),j=9*n+1,10*n)
	apr=' n_e--'                                                       
	print 71,apr,(pl_ves_mat(j),j=10*n+1,11*n)
	apr=' ft--'                                                       
	print 71,apr,(pl_ves_mat(j),j=11*n+1,12*n)
	apr=' f--'                                                       
	print 71,apr,(pl_ves_mat(j),j=12*n+1,13*n)
	apr=' e--'                                                       
	print 71,apr,(pl_ves_mat(j),j=13*n+1,14*n)

	end if

	apr=' ft--'                                                       
c	print 71,apr,(pl_ves_mat(j),j=11*n+1,12*n)
	apr=' f--'                                                       
c	print 71,apr,(pl_ves_mat(j),j=12*n+1,13*n)

	
	if(kloop.gt.0)then                                                     

	   do k=1,kloop                                                        

c OLD	      pl_loop_mat(k)=psloopp(k)*1.e-5                                  

	      pl_loop_mat(k)=psloop(k)

	   end do                                                              

	end if                                                                 

c                                                                       

	if(kprobe.gt.0)then                                                    

	   do k=1,kprobe                                                       

c OLD	      pl_probe_mat(k)=bprobep(k)*0.1                                   

	      pl_probe_mat(k)=bprobe(k)

	   end do                                                              

	end if                                                                 

                                                                        

c  HERE WE began output of Physical parameters


	   pl_pf_mat(1)=tpl*1.e3   !  I_pl in A
	   pl_pf_mat(2)=rs0*1.e-2   !  R major radius in M
	   pl_pf_mat(3)=eu*1.e-2   !  a minor radius in M
	   pl_pf_mat(4)=elong       !  elongation
	   pl_pf_mat(5)=pcch*1.e19   !  average density
	   pl_pf_mat(6)=bt0*0.1     !  toroidal magnetic at Rs 
	   pl_pf_mat(7)=ptot_dop*1.e6     !  Total Power in W
	   pl_pf_mat(8)=wen2*1.e-3     !  Total Energy in J
	   pl_pf_mat(9)=zhib
	   pl_pf_mat(10)=tene_e*1.e-3     !  Tay_e electrons in sec
	   pl_pf_mat(11)=tene*1.e-3     !  Tay_e in sec
	   pl_pf_mat(12)=anom_e        !  anom_e

	apr=' params--'                                                       
c	print 71,apr,(pl_pf_mat(j),j=1,12)


c	do k=1,npf                                                             

c	   pl_pf_mat(k)=pl_pf_volt(k)                                        

c	end do                                                                 

                                                                        

	apr='pl_loop'                                                          

!	if(kpr.eq.1)print 71,apr,(pl_loop_mat(j),j=1,kloop)                   

	apr='pl_probe'                                                         

!	if(kpr.eq.1)print 71,apr,(pl_probe_mat(j),j=1,kprobe)                 

                      

c        if(kpr.eq.1)then                                          

c	apr='pl_pf_mat'                                                        

c	print 71,apr,(pl_pf_mat(j),j=1,npf)                       

                                                                        

c	apr='pl_ves_mat'                                                       

c	print 71,apr,(pl_ves_mat(j),j=1,ncam)

c        endif

                                                                        

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))                                      

                                                                        

	return                                                                 

	end      
	                                                              
	subroutine pl_diag_90(
     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)                  

      	include 'double.inc'
                                                                        

	real*8 pl_loop_mat(*),pl_probe_mat(*),                                 

     *  pl_pf_mat(*),pl_ves_mat(*)                  

	include 'new_com.inc'
	                                                  
	common /c_pet_temp1/ppx_h(npo),pffx_h(npo)

                                                                        

	dimension a_print(200)
	character *30 apr
c                                                                       
	dimension dh1(npo),dh2(npo),q_xx(npo),e_xx(npo),tok1_xx(npo),
     *  ajb_xx(npo),aje_xx(npo),sb_xx(npo),psi_xx(npo),gra1_xx(npo),
     *  a_m_xx(npo),r_m_xx(npo),x_e_neo_xx(npo),x_i_neo_xx(npo),
     *  f_xx(npo),ft_xx(npo)
c                                                                       

                                                                        
!	if(kpr.eq.1)print *,' n===',n

	do i=1,n
	a_print(i)=ajb(i)
	end do
	n_pr=n
	num=25

	apr='--ajb '
c	call out42(n_pr,a_print,num,apr)


	do i=2,n-1
	   dh1(i)=ha(i)/(ha(i)+ha(i+1))
	   dh2(i)=ha(i+1)/(ha(i)+ha(i+1))    
	end do                                      


	   q(1)=q(2)
	   volt(1)=volt(2)
	   ajb(1)=ajb(2)
	   aj0_ech2(1)=aj0_ech2(2)
	   sb_ech2(1)=sb_ech2(2)

c---------------------------------------
	do i=1,n
	      tok1_xx(i)=tok1(i)
	end do

	   i_inter=1
	   if(i_inter.eq.1)then

	   do i=2,n-1
	      q_xx(i)=q(i+1)*dh1(i)+q(i)*dh2(i)
	      e_xx(i)=(volt(i+1)*dh1(i)+volt(i)*dh2(i))
	      ajb_xx(i)=ajb(i+1)*dh1(i)+ajb(i)*dh2(i)
	      aje_xx(i)=aj0_ech2(i+1)*dh1(i)+aj0_ech2(i)*dh2(i)
	      sb_xx(i)=sb_ech2(i+1)*dh1(i)+sb_ech2(i)*dh2(i)

	      gra1_xx(i)=gra1(i+1)*dh1(i)+gra1(i)*dh2(i)
	      x_e_neo_xx(i)=x_e_neo(i+1)*dh1(i)+x_e_neo(i)*dh2(i)
	      x_i_neo_xx(i)=x_i_neo(i+1)*dh1(i)+x_i_neo(i)*dh2(i)
	      ft_xx(i)=ft(i+1)*dh1(i)+ft(i)*dh2(i)
	      f_xx(i)=f(i+1)*dh1(i)+f(i)*dh2(i)

	   end do

	   else


	   do i=2,n
	      q_xx(i)=q(i)
	      e_xx(i)=volt(i)
	      ajb_xx(i)=ajb(i)
	      aje_xx(i)=aj0_ech2(i)
	      sb_xx(i)=sb_ech2(i)

	      gra1_xx(i)=gra1(i)
	      x_e_neo_xx(i)=x_e_neo(i)
	      x_i_neo_xx(i)=x_i_neo(i)
	      ft_xx(i)=ft(i)
	      f_xx(i)=f(i)

	   end do

	   end if


	   do i=2,n
	      a_m_xx(i)=a_m(i)*1.e-2
	      r_m_xx(i)=r_m(i)*1.e-2
	   end do
	   
	   a_m_xx(1)=0.
	   r_m_xx(1)=r_m_xx(2)
	   
	   q_xx(1)=q_xx(2)
	   e_xx(1)=e_xx(2)
	   ajb_xx(1)=ajb_xx(2)
	   aje_xx(1)=aje_xx(2)
	   sb_xx(1)=sb_xx(2)

	if(i_inter.eq.1)then
	      
 	teta_xx=1.
        call inter_h0(q,ai,n,teta_xx,val)
	q_xx(n)=val

        call inter_h0(volt,ai,n,teta_xx,val)
	e_xx(n)=val

        call inter_h0(ajb,ai,n,teta_xx,val)
	ajb_xx(n)=val


        call inter_h0(aj0_ech2,ai,n,teta_xx,val)
	aje_xx(n)=val

        call inter_h0(sb_ech2,ai,n,teta_xx,val)
	sb_xx(n)=val

        call inter_h0(gra1,ai,n,teta_xx,val)
	gra1_xx(n)=val

        call inter_h0(x_e_neo,ai,n,teta_xx,val)
	x_e_neo_xx(n)=val

        call inter_h0(x_i_neo,ai,n,teta_xx,val)
	x_i_neo_xx(n)=val

        call inter_h0(ft,ai,n,teta_xx,val)
	ft_xx(n)=val

        call inter_h0(f,ai,n,teta_xx,val)
	f_xx(n)=val

	end if

        call inter_axis(q,ai,4,teta_xx,val)
	q_xx(1)=val

        call inter_axis(volt,ai,4,teta_xx,val)
	e_xx(1)=val

        call inter_axis(ajb,ai,4,teta_xx,val)
	ajb_xx(1)=val


        call inter_axis(aj0_ech2,ai,4,teta_xx,val)
	aje_xx(1)=val

        call inter_axis(sb_ech2,ai,4,teta_xx,val)
	sb_xx(1)=val


        call inter_axis(gra1,ai,4,teta_xx,val)
	gra1_xx(1)=val

        call inter_axis(x_e_neo,ai,4,teta_xx,val)
	x_e_neo_xx(1)=val

        call inter_axis(x_i_neo,ai,4,teta_xx,val)
	x_i_neo_xx(1)=val

        call inter_axis(ft,ai,4,teta_xx,val)
	ft_xx(1)=val

        call inter_axis(f,ai,4,teta_xx,val)
	f_xx(1)=val

	i_debug=0
	if(i_debug.eq.1)then

 	print *,' ai',(ai(i),i=1,4)
 	print *,' gra1',(gra1_xx(i),i=1,4)
 	print *,' x_e_neo_xx',(x_e_neo_xx(i),i=1,2),(x_e_neo_xx(i),i=n-2,n)
 	print *,' x_i_neo_xx',(x_i_neo_xx(i),i=1,2),(x_i_neo_xx(i),i=n-2,n)

 	print *,' x_e_neo',(x_e_neo(i),i=1,2),(x_e_neo(i),i=n-2,n)
 	print *,' x_i_neo',(x_i_neo(i),i=1,2),(x_i_neo(i),i=n-2,n)

 	print *,' ft',(ft(i),i=1,2),(ft(i),i=n-2,n)
 	print *,' f',(f(i),i=1,2),(f(i),i=n-2,n)


 	print *,' te0',(te0(i),i=1,3)
 	print *,' tq0',(tq0(i),i=1,3)
 	print *,' pne',(pne(i),i=1,3)

	end if


c	   psi_xx(1)=0.                                    
c	   do i=2,n 
c	      psi_xxi= (dm0(i)-dm0(1))/(dm0(n)-dm0(1))
c	      psi_xx(i)=sqrt(psi_xxi) 
c	   end do


	do i=1,n 
	   f_xx(i)=f_xx(i)*(rs0*0.01)*0.1
	end do


	do i=1,n 
c	   psi_xx(i)=(dm0(1)-dm0(i))/(dm0(1)-dm0(n))

	   psi_xx(i)=dm0(i)*1.e-5

c	   psi_xx(i)=ai(i)
!!!	   psi_xx(i)=a(i)

c	   psi_xx(i)=sqrt(psi_xx(i)) 
	end do

c	do i=1,n 
c	   psi_xx(i)=( psval(1)+psi_xx(i)*
c     *  (psval(n)-psval(1))  )*2.*pi*1.e-5
c	end do

	PNOR=6.25E8
	   
	   do i=1,n 
	      e_xx(i)=e_xx(i)/(2.*pi*rmag*1.e-2)
	      vol(i)=vol(i)*1.e-6
	      spov(i)=spov(i)*1.e-4

	      tok1_xx(i)=tok1_xx(i)*1.e7
c!!	      tok1_xx(i)=tok1(i)*1.e7

c!!	      q_xx(i)=q(i)

	      ajb_xx(i)=ajb_xx(i)*1.e7
c	      ajb_xx(i)=ajb(i)*1.e7

	      aje_xx(i)=aje_xx(i)*1.e7
c	      aje_xx(i)=aj0_ech2(i)*1.e7

	      sb_xx(i)=sb_xx(i)/pnor*1.e6
c	      sb_xx(i)=sb_ech2(i)/pnor*1.e6

c	      gra1_xx(i)=gra1(i)*1.e2
	      gra1_xx(i)=gra1_xx(i)*1.e2
	   end do




	do k=1,n
	   i=k
	   pl_ves_mat(i)=te0(k)
	   i=n+k
	   pl_ves_mat(i)=tq0(k)
	   i=2*n+k
	   pl_ves_mat(i)=q_xx(k)
	   i=3*n+k
	   pl_ves_mat(i)=gra1_xx(k)
	   i=4*n+k

c	   pl_ves_mat(i)=psi_xx(k)
	   pl_ves_mat(i)=a(k)

	   i=5*n+k
	   pl_ves_mat(i)=zeff(k)
	   i=6*n+k
	   pl_ves_mat(i)=x_e_neo_xx(k)
	   i=7*n+k
	   pl_ves_mat(i)=x_i_neo_xx(k)
	   i=8*n+k
	   pl_ves_mat(i)=a_m_xx(k)
	   i=9*n+k
	   pl_ves_mat(i)=r_m_xx(k)
	   i=10*n+k
	   pl_ves_mat(i)=pne(k)*1.e19
	   i=11*n+k
	   pl_ves_mat(i)=ft_xx(k)
	   i=12*n+k
	   pl_ves_mat(i)=f_xx(k)

c-----------------------

	   i=13*n+k
	   pl_ves_mat(i)=e_xx(k)
	   i=14*n+k
	   pl_ves_mat(i)=tok1_xx(k)
	   i=15*n+k
	   pl_ves_mat(i)=ajb_xx(k)
	   i=16*n+k
c	   pl_ves_mat(i)=aje_xx(k)
	   pl_ves_mat(i)=p(k)
	   i=17*n+k
	   pl_ves_mat(i)=pptab(k)
c	   pl_ves_mat(i)=sb_xx(k)
c	   pl_ves_mat(i)=pff(k)
	   i=18*n+k
	   pl_ves_mat(i)=fptab(k)
	   i=19*n+k
c	   pl_ves_mat(i)=psval(k)*2.d0*pi*1.e-5
	   pl_ves_mat(i)=spov(k)

	end do             

	if(i_ipm.eq.1)then

	do i=1,n
	a_print(i)=ppx_h(i)
	end do	
	n_pr=n
	apr='pp_h'
	num=25
	call out42(n_pr,a_print,num,apr)


	do k=1,n
	   i=k
	   pl_ves_mat(i)=te0(k)
	   i=n+k
	   pl_ves_mat(i)=tq0(k)
	   i=2*n+k
	   pl_ves_mat(i)=q_xx(k)
	   i=3*n+k
	   pl_ves_mat(i)=gra1_xx(k)
	   i=4*n+k
	   pl_ves_mat(i)=psi_xx(k)
	   i=5*n+k
	   pl_ves_mat(i)=zeff(k)
	   i=6*n+k
	   pl_ves_mat(i)=x_e_neo_xx(k)
	   i=7*n+k
	   pl_ves_mat(i)=x_i_neo_xx(k)
	   i=8*n+k
	   pl_ves_mat(i)=a_m_xx(k)
	   i=9*n+k
	   pl_ves_mat(i)=r_m_xx(k)
	   i=10*n+k
	   pl_ves_mat(i)=pne(k)*1.e19
	   i=11*n+k
	   pl_ves_mat(i)=ft_xx(k)
	   i=12*n+k
	   pl_ves_mat(i)=f_xx(k)

c-----------------------

	   i=13*n+k
	   pl_ves_mat(i)=e_xx(k)
	   i=14*n+k
	   pl_ves_mat(i)=tok1_xx(k)
	   i=15*n+k
	   pl_ves_mat(i)=ajb_xx(k)
	   i=16*n+k
	   pl_ves_mat(i)=aje_xx(k)
	   i=17*n+k
c	   pl_ves_mat(i)=sb_xx(k)


	   pptabi=-ppx_h(k)/(rs0*1.d-2)*10.d0

	   pl_ves_mat(i)=pptabi
	   i=18*n+k
c	   pl_ves_mat(i)=vol(k)

	   fptabi=-0.5d0*pffx_h(k)*(rs0*1.d-2)*10.d0
	   pl_ves_mat(i)=fptabi

	   i=19*n+k
c	   pl_ves_mat(i)=psval(k)*2.d0*pi*1.e-5
	   pl_ves_mat(i)=spov(k)

	end do             

	end if


c	 do k=1,nkin
c	   i=17*nkin+k
c	   pl_ves_mat(i)=pp_pet(k)
c	 enddo

c	 do k=1,nkin
c	   i=18*nkin+k
c	   pl_ves_mat(i)=pff_pet(k)
c	 enddo



	apr=' psi_xx--'                                                       
c	print 71,apr,(psi_xx(j),j=1,n)


	if(kpr.eq.-1)then
	apr=' te0--'
	print 71,apr,(pl_ves_mat(j),j=1,n)
	apr=' tq0--'                                                       
	print 71,apr,(pl_ves_mat(j),j=n+1,n+n)
	apr=' q--'                                                       
	print 71,apr,(pl_ves_mat(j),j=2*n+1,2*n+n)
	apr=' gra1--'                                                       
	print 71,apr,(pl_ves_mat(j),j=3*n+1,3*n+n)
	apr=' psi_nor--'                                                       
	print 71,apr,(pl_ves_mat(j),j=4*n+1,4*n+n)
	apr=' zeff--'                                                       
	print 71,apr,(pl_ves_mat(j),j=5*n+1,5*n+n)
	apr=' x_e_neo--'                                                       
	print 71,apr,(pl_ves_mat(j),j=6*n+1,6*n+n)
	apr=' x_i_neo--'                                                       
	print 71,apr,(pl_ves_mat(j),j=7*n+1,8*n)
	apr=' a_m--'                                                       
	print 71,apr,(pl_ves_mat(j),j=8*n+1,9*n)
	apr=' r_m--'                                                       
	print 71,apr,(pl_ves_mat(j),j=9*n+1,10*n)
	apr=' n_e--'                                                       
	print 71,apr,(pl_ves_mat(j),j=10*n+1,11*n)
	apr=' ft--'                                                       
	print 71,apr,(pl_ves_mat(j),j=11*n+1,12*n)
	apr=' f--'                                                       
	print 71,apr,(pl_ves_mat(j),j=12*n+1,13*n)
	apr=' e--'                                                       
	print 71,apr,(pl_ves_mat(j),j=13*n+1,14*n)

	end if

	apr=' ft--'                                                       
c	print 71,apr,(pl_ves_mat(j),j=11*n+1,12*n)
	apr=' f--'                                                       
c	print 71,apr,(pl_ves_mat(j),j=12*n+1,13*n)

	
	if(kloop.gt.0)then                                                     

	   do k=1,kloop                                                        

c OLD	      pl_loop_mat(k)=psloopp(k)*1.e-5                                  

	      pl_loop_mat(k)=psloop(k)

	   end do                                                              

	end if                                                                 

c                                                                       

	if(kprobe.gt.0)then                                                    

	   do k=1,kprobe                                                       

c OLD	      pl_probe_mat(k)=bprobep(k)*0.1                                   

	      pl_probe_mat(k)=bprobe(k)

	   end do                                                              

	end if                                                                 

                                                                        

c  HERE WE began output of Physical parameters


	   pl_pf_mat(1)=tpl*1.e3   !  I_pl in A
	   pl_pf_mat(2)=rs0*1.e-2   !  R major radius in M
	   pl_pf_mat(3)=eu*1.e-2   !  a minor radius in M
	   pl_pf_mat(4)=elong       !  elongation
	   pl_pf_mat(5)=pcch*1.e19   !  average density
	   pl_pf_mat(6)=bt0*0.1     !  toroidal magnetic at Rs 
	   pl_pf_mat(7)=ptot_dop*1.e6     !  Total Power in W
	   pl_pf_mat(8)=wen2*1.e-3     !  Total Energy in J
	   pl_pf_mat(9)=zhib
	   pl_pf_mat(10)=tene_e*1.e-3     !  Tay_e electrons in sec
	   pl_pf_mat(11)=tene*1.e-3     !  Tay_e in sec
	   pl_pf_mat(12)=anom_e        !  anom_e

	apr=' params--'                                                       
c	print 71,apr,(pl_pf_mat(j),j=1,12)


c	do k=1,npf                                                             

c	   pl_pf_mat(k)=pl_pf_volt(k)                                        

c	end do                                                                 

                                                                        

	apr='pl_loop'                                                          

!	if(kpr.eq.1)print 71,apr,(pl_loop_mat(j),j=1,kloop)                   

	apr='pl_probe'                                                         

!	if(kpr.eq.1)print 71,apr,(pl_probe_mat(j),j=1,kprobe)                 

                      

c        if(kpr.eq.1)then                                          

c	apr='pl_pf_mat'                                                        

c	print 71,apr,(pl_pf_mat(j),j=1,npf)                       

                                                                        

c	apr='pl_ves_mat'                                                       

c	print 71,apr,(pl_ves_mat(j),j=1,ncam)

c        endif

                                                                        

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))                                      

                                                                        

	return                                                                 

	end                                                                    
	subroutine pl_diag_91(
     *  pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat)                  

      	include 'double.inc'
                                                                        

	real*8 pl_loop_mat(*),pl_probe_mat(*),                                 

     *  pl_pf_mat(*),pl_ves_mat(*)                  

	include 'new_com.inc'
	                                                  
	common /c_pet_temp1/ppx_h(npo),pffx_h(npo)
	common /c_pet_temp2/ppx_h2(npo),pffx_h2(npo),poa_h2(npo)
                                                                        

	dimension a_print(200)
	character *30 apr
c                                                                       
	dimension dh1(npo),dh2(npo),q_xx(npo),e_xx(npo),tok1_xx(npo),
     *  ajb_xx(npo),aje_xx(npo),sb_xx(npo),psi_xx(npo),gra1_xx(npo),
     *  a_m_xx(npo),r_m_xx(npo),x_e_neo_xx(npo),x_i_neo_xx(npo),
     *  f_xx(npo),ft_xx(npo)
c                                                                       

                                                                        
!	if(kpr.eq.1)print *,' n===',n

	do i=1,n
	a_print(i)=ajb(i)
	end do
	n_pr=n
	num=25

	apr='--ajb '
c	call out42(n_pr,a_print,num,apr)


	do i=2,n-1
	   dh1(i)=ha(i)/(ha(i)+ha(i+1))
	   dh2(i)=ha(i+1)/(ha(i)+ha(i+1))    
	end do                                      


	   q(1)=q(2)
	   volt(1)=volt(2)
	   ajb(1)=ajb(2)
	   aj0_ech2(1)=aj0_ech2(2)
	   sb_ech2(1)=sb_ech2(2)

	do i=1,n
	      tok1_xx(i)=tok1(i)
	end do
c---------------------------------------

	   i_inter=1
	   if(i_inter.eq.1)then

	   do i=2,n-1
	      q_xx(i)=q(i+1)*dh1(i)+q(i)*dh2(i)
	      e_xx(i)=(volt(i+1)*dh1(i)+volt(i)*dh2(i))
	      ajb_xx(i)=ajb(i+1)*dh1(i)+ajb(i)*dh2(i)
	      aje_xx(i)=aj0_ech2(i+1)*dh1(i)+aj0_ech2(i)*dh2(i)
	      sb_xx(i)=sb_ech2(i+1)*dh1(i)+sb_ech2(i)*dh2(i)

	      gra1_xx(i)=gra1(i+1)*dh1(i)+gra1(i)*dh2(i)
	      x_e_neo_xx(i)=x_e_neo(i+1)*dh1(i)+x_e_neo(i)*dh2(i)
	      x_i_neo_xx(i)=x_i_neo(i+1)*dh1(i)+x_i_neo(i)*dh2(i)
	      ft_xx(i)=ft(i+1)*dh1(i)+ft(i)*dh2(i)
	      f_xx(i)=f(i+1)*dh1(i)+f(i)*dh2(i)

	   end do

	   else


	   do i=2,n
	      q_xx(i)=q(i)
	      e_xx(i)=volt(i)
	      ajb_xx(i)=ajb(i)
	      aje_xx(i)=aj0_ech2(i)
	      sb_xx(i)=sb_ech2(i)

	      gra1_xx(i)=gra1(i)
	      x_e_neo_xx(i)=x_e_neo(i)
	      x_i_neo_xx(i)=x_i_neo(i)
	      ft_xx(i)=ft(i)
	      f_xx(i)=f(i)

	   end do

	   end if


	   do i=2,n
	      a_m_xx(i)=a_m(i)*1.e-2
	      r_m_xx(i)=r_m(i)*1.e-2
	   end do
	   
	   a_m_xx(1)=0.
	   r_m_xx(1)=r_m_xx(2)
	   
	   q_xx(1)=q_xx(2)
	   e_xx(1)=e_xx(2)
	   ajb_xx(1)=ajb_xx(2)
	   aje_xx(1)=aje_xx(2)
	   sb_xx(1)=sb_xx(2)

	if(i_inter.eq.1)then
	      
 	teta_xx=1.
        call inter_h0(q,ai,n,teta_xx,val)
	q_xx(n)=val

        call inter_h0(volt,ai,n,teta_xx,val)
	e_xx(n)=val

        call inter_h0(ajb,ai,n,teta_xx,val)
	ajb_xx(n)=val


        call inter_h0(aj0_ech2,ai,n,teta_xx,val)
	aje_xx(n)=val

        call inter_h0(sb_ech2,ai,n,teta_xx,val)
	sb_xx(n)=val

        call inter_h0(gra1,ai,n,teta_xx,val)
	gra1_xx(n)=val

        call inter_h0(x_e_neo,ai,n,teta_xx,val)
	x_e_neo_xx(n)=val

        call inter_h0(x_i_neo,ai,n,teta_xx,val)
	x_i_neo_xx(n)=val

        call inter_h0(ft,ai,n,teta_xx,val)
	ft_xx(n)=val

        call inter_h0(f,ai,n,teta_xx,val)
	f_xx(n)=val

	end if

        call inter_axis(q,ai,4,teta_xx,val)
	q_xx(1)=val

        call inter_axis(volt,ai,4,teta_xx,val)
	e_xx(1)=val

        call inter_axis(ajb,ai,4,teta_xx,val)
	ajb_xx(1)=val

        call inter_axis(aj0_ech2,ai,4,teta_xx,val)
	aje_xx(1)=val

        call inter_axis(sb_ech2,ai,4,teta_xx,val)
	sb_xx(1)=val


        call inter_axis(gra1,ai,4,teta_xx,val)
	gra1_xx(1)=val

        call inter_axis(x_e_neo,ai,4,teta_xx,val)
	x_e_neo_xx(1)=val

        call inter_axis(x_i_neo,ai,4,teta_xx,val)
	x_i_neo_xx(1)=val

        call inter_axis(ft,ai,4,teta_xx,val)
	ft_xx(1)=val

        call inter_axis(f,ai,4,teta_xx,val)
	f_xx(1)=val

	i_debug=0
	if(i_debug.eq.1)then

 	print *,' ai',(ai(i),i=1,4)
 	print *,' gra1',(gra1_xx(i),i=1,4)
 	print *,' x_e_neo_xx',(x_e_neo_xx(i),i=1,2),(x_e_neo_xx(i),i=n-2,n)
 	print *,' x_i_neo_xx',(x_i_neo_xx(i),i=1,2),(x_i_neo_xx(i),i=n-2,n)

 	print *,' x_e_neo',(x_e_neo(i),i=1,2),(x_e_neo(i),i=n-2,n)
 	print *,' x_i_neo',(x_i_neo(i),i=1,2),(x_i_neo(i),i=n-2,n)

 	print *,' ft',(ft(i),i=1,2),(ft(i),i=n-2,n)
 	print *,' f',(f(i),i=1,2),(f(i),i=n-2,n)


 	print *,' te0',(te0(i),i=1,3)
 	print *,' tq0',(tq0(i),i=1,3)
 	print *,' pne',(pne(i),i=1,3)

	end if


c	   psi_xx(1)=0.                                    
c	   do i=2,n 
c	      psi_xxi= (dm0(i)-dm0(1))/(dm0(n)-dm0(1))
c	      psi_xx(i)=sqrt(psi_xxi) 
c	   end do


	do i=1,n 
	   f_xx(i)=f_xx(i)*(rs0*0.01)*0.1
	end do


	do i=1,n 
c	   psi_xx(i)=(dm0(1)-dm0(i))/(dm0(1)-dm0(n))

	   psi_xx(i)=dm0(i)*1.e-5

c	   psi_xx(i)=ai(i)
!!!	   psi_xx(i)=a(i)

c	   psi_xx(i)=sqrt(psi_xx(i)) 
	end do

c	do i=1,n 
c	   psi_xx(i)=( psval(1)+psi_xx(i)*
c     *  (psval(n)-psval(1))  )*2.*pi*1.e-5
c	end do

	PNOR=6.25E8
	   
	   do i=1,n 
	      e_xx(i)=e_xx(i)/(2.*pi*rmag*1.e-2)
	      vol(i)=vol(i)*1.e-6
	      spov(i)=spov(i)*1.e-4

	      tok1_xx(i)=tok1_xx(i)*1.e7
c!!	      tok1_xx(i)=tok1(i)*1.e7

c!!	      q_xx(i)=q(i)

	      ajb_xx(i)=ajb_xx(i)*1.e7
c	      ajb_xx(i)=ajb(i)*1.e7

	      aje_xx(i)=aje_xx(i)*1.e7
c	      aje_xx(i)=aj0_ech2(i)*1.e7

	      sb_xx(i)=sb_xx(i)/pnor*1.e6
c	      sb_xx(i)=sb_ech2(i)/pnor*1.e6

c	      gra1_xx(i)=gra1(i)*1.e2
	      gra1_xx(i)=gra1_xx(i)*1.e2
	   end do




	do k=1,n
	   i=k
	   pl_ves_mat(i)=te0(k)
	   i=n+k
	   pl_ves_mat(i)=tq0(k)
	   i=2*n+k
	   pl_ves_mat(i)=q_xx(k)
	   i=3*n+k
	   pl_ves_mat(i)=gra1_xx(k)
	   i=4*n+k
	   pl_ves_mat(i)=psi_xx(k)
	   i=5*n+k
	   pl_ves_mat(i)=zeff(k)
	   i=6*n+k
	   pl_ves_mat(i)=x_e_neo_xx(k)
	   i=7*n+k
	   pl_ves_mat(i)=x_i_neo_xx(k)
	   i=8*n+k
	   pl_ves_mat(i)=a_m_xx(k)
	   i=9*n+k
	   pl_ves_mat(i)=r_m_xx(k)
	   i=10*n+k
	   pl_ves_mat(i)=pne(k)*1.e19
	   i=11*n+k
	   pl_ves_mat(i)=ft_xx(k)
	   i=12*n+k
	   pl_ves_mat(i)=f_xx(k)

c-----------------------

	   i=13*n+k
	   pl_ves_mat(i)=e_xx(k)
	   i=14*n+k
	   pl_ves_mat(i)=tok1_xx(k)
	   i=15*n+k
	   pl_ves_mat(i)=ajb_xx(k)
	   i=16*n+k
c	   pl_ves_mat(i)=aje_xx(k)
	   pl_ves_mat(i)=ppr(k)


c	   pl_ves_mat(i)=pp(k)
	   i=17*n+k

	   pl_ves_mat(i)=a(k)


c	   pl_ves_mat(i)=sb_xx(k)
c	   pl_ves_mat(i)=pff(k)
	   i=18*n+k
	   pl_ves_mat(i)=vol(k)
	   i=19*n+k
c	   pl_ves_mat(i)=psval(k)*2.d0*pi*1.e-5
	   pl_ves_mat(i)=spov(k)


c   THESE are profiles for continuation

	   i=20*n+k
	   pl_ves_mat(i)=poa_h2(k)

	   i=21*n+k
	   pl_ves_mat(i)=ppx_h2(k)

	   i=22*n+k
	   pl_ves_mat(i)=pffx_h2(k)




	   i=23*n+k
	   pl_ves_mat(i)=dmn(k)


c---------------------------------------------



	end do             

	apr=' dmn***--'                                                       
c	print 71,apr,(dmn(j),j=1,n)



	if(i_ipm.eq.1)then

	do i=1,n
	a_print(i)=ppx_h(i)
	end do	
	n_pr=n
	apr='pp_h'
	num=25
	call out42(n_pr,a_print,num,apr)


	do k=1,n
	   i=k
	   pl_ves_mat(i)=te0(k)
	   i=n+k
	   pl_ves_mat(i)=tq0(k)
	   i=2*n+k
	   pl_ves_mat(i)=q_xx(k)
	   i=3*n+k
	   pl_ves_mat(i)=gra1_xx(k)
	   i=4*n+k
	   pl_ves_mat(i)=psi_xx(k)
	   i=5*n+k
	   pl_ves_mat(i)=zeff(k)
	   i=6*n+k
	   pl_ves_mat(i)=x_e_neo_xx(k)
	   i=7*n+k
	   pl_ves_mat(i)=x_i_neo_xx(k)
	   i=8*n+k
	   pl_ves_mat(i)=a_m_xx(k)
	   i=9*n+k
	   pl_ves_mat(i)=r_m_xx(k)
	   i=10*n+k
	   pl_ves_mat(i)=pne(k)*1.e19
	   i=11*n+k
	   pl_ves_mat(i)=ft_xx(k)
	   i=12*n+k
	   pl_ves_mat(i)=f_xx(k)

c-----------------------

	   i=13*n+k
	   pl_ves_mat(i)=e_xx(k)
	   i=14*n+k
	   pl_ves_mat(i)=tok1_xx(k)
	   i=15*n+k
	   pl_ves_mat(i)=ajb_xx(k)
	   i=16*n+k
	   pl_ves_mat(i)=aje_xx(k)
	   i=17*n+k
c	   pl_ves_mat(i)=sb_xx(k)


	   pptabi=-ppx_h(k)/(rs0*1.d-2)*10.d0

	   pl_ves_mat(i)=pptabi
	   i=18*n+k
c	   pl_ves_mat(i)=vol(k)

	   fptabi=-0.5d0*pffx_h(k)*(rs0*1.d-2)*10.d0
	   pl_ves_mat(i)=fptabi

	   i=19*n+k
c	   pl_ves_mat(i)=psval(k)*2.d0*pi*1.e-5
	   pl_ves_mat(i)=spov(k)


	end do             

	end if


c	 do k=1,nkin
c	   i=17*nkin+k
c	   pl_ves_mat(i)=pp_pet(k)
c	 enddo

c	 do k=1,nkin
c	   i=18*nkin+k
c	   pl_ves_mat(i)=pff_pet(k)
c	 enddo



	apr=' psi_xx--'                                                       
c	print 71,apr,(psi_xx(j),j=1,n)


	if(kpr.eq.-1)then
	apr=' te0--'
	print 71,apr,(pl_ves_mat(j),j=1,n)
	apr=' tq0--'                                                       
	print 71,apr,(pl_ves_mat(j),j=n+1,n+n)
	apr=' q--'                                                       
	print 71,apr,(pl_ves_mat(j),j=2*n+1,2*n+n)
	apr=' gra1--'                                                       
	print 71,apr,(pl_ves_mat(j),j=3*n+1,3*n+n)
	apr=' psi_nor--'                                                       
	print 71,apr,(pl_ves_mat(j),j=4*n+1,4*n+n)
	apr=' zeff--'                                                       
	print 71,apr,(pl_ves_mat(j),j=5*n+1,5*n+n)
	apr=' x_e_neo--'                                                       
	print 71,apr,(pl_ves_mat(j),j=6*n+1,6*n+n)
	apr=' x_i_neo--'                                                       
	print 71,apr,(pl_ves_mat(j),j=7*n+1,8*n)
	apr=' a_m--'                                                       
	print 71,apr,(pl_ves_mat(j),j=8*n+1,9*n)
	apr=' r_m--'                                                       
	print 71,apr,(pl_ves_mat(j),j=9*n+1,10*n)
	apr=' n_e--'                                                       
	print 71,apr,(pl_ves_mat(j),j=10*n+1,11*n)
	apr=' ft--'                                                       
	print 71,apr,(pl_ves_mat(j),j=11*n+1,12*n)
	apr=' f--'                                                       
	print 71,apr,(pl_ves_mat(j),j=12*n+1,13*n)
	apr=' e--'                                                       
	print 71,apr,(pl_ves_mat(j),j=13*n+1,14*n)

	end if

	apr=' ft--'                                                       
c	print 71,apr,(pl_ves_mat(j),j=11*n+1,12*n)
	apr=' f--'                                                       
c	print 71,apr,(pl_ves_mat(j),j=12*n+1,13*n)

	
	if(kloop.gt.0)then                                                     

	   do k=1,kloop                                                        

c OLD	      pl_loop_mat(k)=psloopp(k)*1.e-5                                  

	      pl_loop_mat(k)=psloop(k)

	   end do                                                              

	end if                                                                 

c                                                                       

	if(kprobe.gt.0)then                                                    

	   do k=1,kprobe                                                       

c OLD	      pl_probe_mat(k)=bprobep(k)*0.1                                   

	      pl_probe_mat(k)=bprobe(k)

	   end do                                                              

	end if                                                                 

                                                                        

c  HERE WE began output of Physical parameters


	   pl_pf_mat(1)=tpl*1.e3   !  I_pl in A
	   pl_pf_mat(2)=rs0*1.e-2   !  R major radius in M
	   pl_pf_mat(3)=eu*1.e-2   !  a minor radius in M
	   pl_pf_mat(4)=elong       !  elongation
	   pl_pf_mat(5)=pcch*1.e19   !  average density
	   pl_pf_mat(6)=bt0*0.1     !  toroidal magnetic at Rs 
	   pl_pf_mat(7)=ptot_dop*1.e6     !  Total Power in W
	   pl_pf_mat(8)=wen2*1.e-3     !  Total Energy in J
	   pl_pf_mat(9)=zhib
	   pl_pf_mat(10)=tene_e*1.e-3     !  Tay_e electrons in sec
	   pl_pf_mat(11)=tene*1.e-3     !  Tay_e in sec
	   pl_pf_mat(12)=anom_e        !  anom_e

	apr=' params--'                                                       
c	print 71,apr,(pl_pf_mat(j),j=1,12)


c	do k=1,npf                                                             

c	   pl_pf_mat(k)=pl_pf_volt(k)                                        

c	end do                                                                 

                                                                        

	apr='pl_loop'                                                          

!	if(kpr.eq.1)print 71,apr,(pl_loop_mat(j),j=1,kloop)                   

	apr='pl_probe'                                                         

!	if(kpr.eq.1)print 71,apr,(pl_probe_mat(j),j=1,kprobe)                 

                      

c        if(kpr.eq.1)then                                          

c	apr='pl_pf_mat'                                                        

c	print 71,apr,(pl_pf_mat(j),j=1,npf)                       

                                                                        

c	apr='pl_ves_mat'                                                       

c	print 71,apr,(pl_ves_mat(j),j=1,ncam)

c        endif

                                                                        

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))                                      

                                                                        

	return                                                                 

	end                                                                    
	subroutine cronos_metric(
     *  cronos_prof)                  

      include 'double.inc'
                                                                        

	real*8 cronos_prof(*)


	include 'new_com.inc'                                                  

c                                                                       
	dimension dh1(npo),dh2(npo),tok1_xx(npo),
     *  gra1_xx(npo),gra2_xx(npo),
     *  gra2_r2_xx(npo),one_r2_xx(npo),gra1_r_xx(npo),r_av_xx(npo),
     *  one_r_xx(npo),r2_av_xx(npo),b2_av_xx(npo),
     *  vi_xx(npo),spo_xx(npo),one_r2_vi(npo),one_r2_vi_xx(npo),
     *  ft_xx(npo),f_xx(npo),q_xx(npo), gra2_b2_xx(npo),one_b2_xx(npo),
     *  e_xx(npo)

	dimension a_print(200)
	character *30 apr  

	i_en=i_en+1

	do i=2,n-1
	   dh1(i)=ha(i)/(ha(i)+ha(i+1))
	   dh2(i)=ha(i+1)/(ha(i)+ha(i+1))    
	end do                                      

	do i=1,n
	   one_r2_vi(i)=one_r2(i)*vi(i)
		dv_dro=2.d0*pi*vi(i)*1.d-4
	   gra2_r2(i)=gra2_r2(i)*dv_dro
	end do                                      


c	call TOK_KK(N,RS0)


        call inter_axis(gra1,ai,4,teta_xx,val)
	gra1(1)=val

        call inter_axis(gra2,ai,4,teta_xx,val)
	gra2(1)=val

        call inter_axis(gra1_r,ai,4,teta_xx,val)
	gra1_r(1)=val

        call inter_axis(gra2_r2,ai,4,teta_xx,val)
	gra2_r2(1)=val


        call inter_axis(one_r,ai,4,teta_xx,val)
	one_r(1)=val

        call inter_axis(one_r2,ai,4,teta_xx,val)
	one_r2(1)=val

        call inter_axis(r_av,ai,4,teta_xx,val)
	r_av(1)=val

        call inter_axis(r2_av,ai,4,teta_xx,val)
	r2_av(1)=val

        call inter_axis(b2_av,ai,4,teta_xx,val)
	b2_av(1)=val

        call inter_axis(ft,ai,4,teta_xx,val)
c	ft(1)=val

c        call inter_axis(fasp,ai,4,teta_xx,val)
c	fasp(1)=val

        call inter_axis(f,ai,4,teta_xx,val)
	f(1)=val

        call inter_axis(q,ai,4,teta_xx,val)
	q_xx(1)=val

        call inter_axis(elonga,ai,4,teta_xx,val)
	elonga(1)=val



        call inter_axis(shafra,ai,4,teta_xx,val)
	shafra(1)=val

        call inter_axis(gra2_b2,ai,4,teta_xx,val)
	gra2_b2(1)=val

        call inter_axis(one_b2,ai,4,teta_xx,val)
	one_b2(1)=val

        call inter_axis(volt,ai,4,teta_xx,val)
	volt(1)=val

	do i=1,n
	      tok1_xx(i)=tok1(i)
	end do

	   do i=2,n-1
	      gra1_xx(i)=gra1(i+1)*dh1(i)+gra1(i)*dh2(i)
	      gra2_xx(i)=gra2(i+1)*dh1(i)+gra2(i)*dh2(i)
	      gra1_r_xx(i)=gra1_r(i+1)*dh1(i)+gra1_r(i)*dh2(i)
	      gra2_r2_xx(i)=gra2_r2(i+1)*dh1(i)+gra2_r2(i)*dh2(i)
	      one_r_xx(i)=one_r(i+1)*dh1(i)+one_r(i)*dh2(i)
	      one_r2_xx(i)=one_r2(i+1)*dh1(i)+one_r2(i)*dh2(i)
	      r_av_xx(i)=r_av(i+1)*dh1(i)+r_av(i)*dh2(i)
	      r2_av_xx(i)=r2_av(i+1)*dh1(i)+r2_av(i)*dh2(i)
	      vi_xx(i)=vi(i+1)*dh1(i)+vi(i)*dh2(i)
	      spo_xx(i)=spo(i+1)*dh1(i)+spo(i)*dh2(i)
	      b2_av_xx(i)=b2_av(i+1)*dh1(i)+b2_av(i)*dh2(i)
	      one_r2_vi_xx(i)=one_r2_vi(i+1)*dh1(i)+
     *  one_r2_vi(i)*dh2(i)


	      ft_xx(i)=ft(i+1)*dh1(i)+ft(i)*dh2(i)
c	      ft_xx(i)=fasp(i+1)*dh1(i)+fasp(i)*dh2(i)

	      f_xx(i)=f(i+1)*dh1(i)+f(i)*dh2(i)
	      q_xx(i)=q(i+1)*dh1(i)+q(i)*dh2(i)

	      gra2_b2_xx(i)=gra2_b2(i+1)*dh1(i)+gra2_b2(i)*dh2(i)
	      one_b2_xx(i)=one_b2(i+1)*dh1(i)+one_b2(i)*dh2(i)

	      e_xx(i)=(volt(i+1)*dh1(i)+volt(i)*dh2(i))


	   end do


	      gra1_xx(1)=gra1(1)
	      gra2_xx(1)=gra2(1)
	      gra1_r_xx(1)=gra1_r(1)
	      gra2_r2_xx(1)=gra2_r2(1)
	      one_r_xx(1)=one_r(1)
	      one_r2_xx(1)=one_r2(1)
	      r_av_xx(1)=r_av(1)
	      r2_av_xx(1)=r2_av(1)
	      vi_xx(1)=vi(1)
	      spo_xx(1)=spo(1)
	      b2_av_xx(1)=b2_av(1)
	      ft_xx(1)=ft(1)
c	      ft_xx(1)=fasp(1)
	      f_xx(1)=f(1)
	      f_xx(n)=f(n)

	      gra2_b2_xx(1)=gra2_b2(1)
	      one_b2_xx(1)=one_b2(1)

	      e_xx(1)=volt(1)

 	teta_xx=1.d0


        call inter_h0(gra1,ai,n,teta_xx,val)
	gra1_xx(n)=val

        call inter_h0(gra2,ai,n,teta_xx,val)
	gra2_xx(n)=val

        call inter_h0(gra1_r,ai,n,teta_xx,val)
	gra1_r_xx(n)=val

        call inter_h0(gra2_r2,ai,n,teta_xx,val)
	gra2_r2_xx(n)=val

        call inter_h0(one_r,ai,n,teta_xx,val)
	one_r_xx(n)=val

        call inter_h0(one_r2,ai,n,teta_xx,val)
	one_r2_xx(n)=val

        call inter_h0(r_av,ai,n,teta_xx,val)
	r_av_xx(n)=val

        call inter_h0(r2_av,ai,n,teta_xx,val)
	r2_av_xx(n)=val

        call inter_h0(vi,ai,n,teta_xx,val)
	vi_xx(n)=val

        call inter_h0(spo,ai,n,teta_xx,val)
	spo_xx(n)=val

        call inter_h0(b2_av,ai,n,teta_xx,val)
	b2_av_xx(n)=val

        call inter_h0(one_r2_vi,ai,n,teta_xx,val)
	one_r2_vi_xx(n)=val


 	teta_xx=1.
        call inter_h0(ft,ai,n,teta_xx,val)
	ft_xx(n)=val

c 	teta_xx=1.
c        call inter_h0(fasp,ai,n,teta_xx,val)
c	ft_xx(n)=val

 	teta_xx=1.
        call inter_h0(q,ai,n,teta_xx,val)
	q_xx(n)=val

        call inter_h0(gra2_b2,ai,n,teta_xx,val)
	gra2_b2_xx(n)=val

        call inter_h0(one_b2,ai,n,teta_xx,val)
	one_b2_xx(n)=val

        call inter_h0(volt,ai,n,teta_xx,val)
	e_xx(n)=val


	if(kpr.eq.1)then
	apr=' tok1--'
	print 71,apr,(tok1(j),j=1,n)
	apr=' tok1_xx--'
	print 71,apr,(tok1_xx(j),j=1,n)

	apr=' gra1--'
	print 71,apr,(gra1(j),j=1,n)
	apr=' gra1--'
	print 71,apr,(gra1_xx(j),j=1,n)

	apr=' gra2--'
	print 71,apr,(gra2(j),j=1,n)
	apr=' gra2_xx--'
	print 71,apr,(gra2_xx(j),j=1,n)

	apr=' gra1_r--'
	print 71,apr,(gra1_r(j),j=1,n)
	apr=' gra1_r_xx--'
	print 71,apr,(gra1_r_xx(j),j=1,n)

	apr=' gra2_r2--'
	print 71,apr,(gra2_r2(j),j=1,n)
	apr=' gra2_r2_xx--'
	print 71,apr,(gra2_r2_xx(j),j=1,n)

	apr=' one_r--'
	print 71,apr,(one_r(j),j=1,n)
	apr=' one_r_xx--'
	print 71,apr,(one_r_xx(j),j=1,n)

	apr=' one_r2--'
	print 71,apr,(one_r2(j),j=1,n)
	apr=' one_r2_xx--'
	print 71,apr,(one_r2_xx(j),j=1,n)

	apr=' r_av--'
	print 71,apr,(r_av(j),j=1,n)
	apr=' r_av_xx--'
	print 71,apr,(r_av_xx(j),j=1,n)

	apr=' r2_av--'
	print 71,apr,(r2_av(j),j=1,n)
	apr=' r2_av_xx--'
	print 71,apr,(r2_av_xx(j),j=1,n)


	apr=' vi--'
	print 71,apr,(vi(j),j=1,n)
	apr=' vi_xx--'
	print 71,apr,(vi_xx(j),j=1,n)

	apr=' spo--'
	print 71,apr,(spo(j),j=1,n)
	apr=' spo_xx--'
	print 71,apr,(spo_xx(j),j=1,n)


	apr=' b2_av--'
	print 71,apr,(b2_av(j),j=1,n)
	apr=' b2_av_xx--'
	print 71,apr,(b2_av_xx(j),j=1,n)


	apr=' one_r2_vi--'
	print 71,apr,(one_r2_vi(j),j=1,n)
	apr=' one_r2_vi_xx--'
	print 71,apr,(one_r2_vi_xx(j),j=1,n)
	
	end if


	bt_cron=bt0*rs0/r_m(n)


	ro_max=dsqrt(dfmax(n)/(pi*bt_cron))

c	print *,' rs0 r_m==',rs0,r_m(n)
c	print *,' bt0 bt_cron==',bt0,bt_cron


 	teta=1.d0
      call inter_h0(ppx,a,n-1,teta,val)

	ppx(n)=val

 	teta=1.d0
	call inter_h0(pffx,a,n-1,teta,val)

	pffx(n)=val



	do i=1,n 
	   f_xx(i)=f_xx(i)*(rs0*0.01d0)*0.1d0
	   e_xx(i)=e_xx(i)/(2.d0*pi*rmag*1.d-2)
	end do

	if(kpr.eq.3)then
	do i=1,10
	a_print(i)=p(i)
	end do	
	n_pr=10
	apr='-- p_cr --'
	num=25
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)
	end if


	do k=1,n
	   i=k

	   cronos_prof(i)=dm0(k)*1.d-5

c	   cronos_prof(i)=(psval(k)-psval(1))*2.d0*pi*1.d-5


	   i=1*n+k
	   cronos_prof(i)=dfmax(k)*1.d-5
	   i=2*n+k
	   cronos_prof(i)=tok1_xx(k)*1.d7
	   i=3*n+k
	   cronos_prof(i)=gra1_xx(k)*ro_max
	   i=4*n+k
	   cronos_prof(i)=gra2_xx(k)*ro_max**2
	   i=5*n+k
	   cronos_prof(i)=gra1_r_xx(k)*ro_max*1.d2
	   i=6*n+k


	   cronos_prof(i)=gra2_r2_xx(k)*1.d+4*ro_max**2/ro_max
	   i=7*n+k
	   cronos_prof(i)=one_r_xx(k)*1.d2
	   i=8*n+k
	   cronos_prof(i)=one_r2_xx(k)*1.d4
	   i=9*n+k
	   cronos_prof(i)=r_av_xx(k)*1.d-2
	   i=10*n+k
	   cronos_prof(i)=r2_av_xx(k)*1.d-4
	   i=11*n+k

           dv_dro=2.d0*pi*vi_xx(k)*1.d-4/ro_max

	   cronos_prof(i)=dv_dro
	   i=12*n+k
	   cronos_prof(i)=spo_xx(k)*1.d-2/ro_max
	   i=13*n+k

	   cronos_prof(i)=p(k)/( 200.*1.d-6 )*1.d16
	   i=14*n+k
	   cronos_prof(i)=b2_av_xx(k)*1.d-2
	   i=15*n+k
	   cronos_prof(i)=2.d0*pi*one_r2_vi_xx(k)/ro_max


	end do             


	if(kpr.eq.1)then
	apr='  psi--'
	print 71,apr,(cronos_prof(j),j=1,n)
	apr='  fi--'                                                       
	print 71,apr,(cronos_prof(j),j=n+1,n+n)
	apr=' tok1--'                                                       
	print 71,apr,(cronos_prof(j),j=2*n+1,2*n+n)
	apr=' gra1--'                                                       
	print 71,apr,(cronos_prof(j),j=3*n+1,3*n+n)
	apr='  gra2'                                                       
	print 71,apr,(cronos_prof(j),j=4*n+1,4*n+n)
	apr=' gra1_r--'                                                       
	print 71,apr,(cronos_prof(j),j=5*n+1,5*n+n)
	apr=' gra2_r2-'                                                       
	print 71,apr,(cronos_prof(j),j=6*n+1,6*n+n)
	apr=' one_r--'                                                       
	print 71,apr,(cronos_prof(j),j=7*n+1,7*n+n)
	apr=' one_r2--'                                                       
	print 71,apr,(cronos_prof(j),j=8*n+1,8*n+n)
	apr=' r_av--'                                                       
	print 71,apr,(cronos_prof(j),j=9*n+1,9*n+n)
	apr=' r2_av--'                                                       
	print 71,apr,(cronos_prof(j),j=10*n+1,10*n+n)
	apr=' vi--'                                                       
	print 71,apr,(cronos_prof(j),j=11*n+1,11*n+n)
	apr=' spo--'                                                       
	print 71,apr,(cronos_prof(j),j=12*n+1,12*n+n)
	apr=' p--'                                                       
	print 71,apr,(cronos_prof(j),j=13*n+1,13*n+n)
	apr=' b2_av--'                                                       
	print 71,apr,(cronos_prof(j),j=14*n+1,14*n+n)
	apr=' one_r2_vi'                                                       
	print 71,apr,(cronos_prof(j),j=15*n+1,15*n+n)

	end if

                                                                        

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))                                      

                                                                        

	return                                                                 

	end                                                                    
	subroutine cronos_metric_93(
     *  cronos_prof)                  

      include 'double.inc'
                                                                        

	real*8 cronos_prof(*)


	include 'new_com.inc'                                                  

c                                                                       
	dimension dh1(npo),dh2(npo),tok1_xx(npo),
     *  gra1_xx(npo),gra2_xx(npo),
     *  gra2_r2_xx(npo),one_r2_xx(npo),gra1_r_xx(npo),r_av_xx(npo),
     *  one_r_xx(npo),r2_av_xx(npo),b2_av_xx(npo),
     *  vi_xx(npo),spo_xx(npo),one_r2_vi(npo),one_r2_vi_xx(npo),
     *  ft_xx(npo),f_xx(npo),q_xx(npo), gra2_b2_xx(npo),one_b2_xx(npo),
     *  e_xx(npo)

	dimension a_print(200)
	character *30 apr  
                                                    

	i_en=i_en+1

	do i=2,n-1
	   dh1(i)=ha(i)/(ha(i)+ha(i+1))
	   dh2(i)=ha(i+1)/(ha(i)+ha(i+1))    
	end do                                      

	do i=1,n
	   one_r2_vi(i)=one_r2(i)*vi(i)
		dv_dro=2.d0*pi*vi(i)*1.d-4
	   gra2_r2(i)=gra2_r2(i)*dv_dro
	end do                                      


        call inter_axis(gra1,ai,4,teta_xx,val)
	gra1(1)=val

        call inter_axis(gra2,ai,4,teta_xx,val)
	gra2(1)=val

        call inter_axis(gra1_r,ai,4,teta_xx,val)
	gra1_r(1)=val

        call inter_axis(gra2_r2,ai,4,teta_xx,val)
	gra2_r2(1)=val


        call inter_axis(one_r,ai,4,teta_xx,val)
	one_r(1)=val

        call inter_axis(one_r2,ai,4,teta_xx,val)
	one_r2(1)=val

        call inter_axis(r_av,ai,4,teta_xx,val)
	r_av(1)=val

        call inter_axis(r2_av,ai,4,teta_xx,val)
	r2_av(1)=val

        call inter_axis(b2_av,ai,4,teta_xx,val)
	b2_av(1)=val

        call inter_axis(ft,ai,4,teta_xx,val)
c	ft(1)=val

c        call inter_axis(fasp,ai,4,teta_xx,val)
c	fasp(1)=val

        call inter_axis(f,ai,4,teta_xx,val)
	f(1)=val

        call inter_axis(q,ai,4,teta_xx,val)
	q_xx(1)=val

        call inter_axis(elonga,ai,4,teta_xx,val)
	elonga(1)=val



        call inter_axis(shafra,ai,4,teta_xx,val)
	shafra(1)=val

        call inter_axis(gra2_b2,ai,4,teta_xx,val)
	gra2_b2(1)=val

        call inter_axis(one_b2,ai,4,teta_xx,val)
	one_b2(1)=val

        call inter_axis(volt,ai,4,teta_xx,val)
	volt(1)=val


	do i=1,n
		tok1_xx(i)=tok1(i)
	end do

	   do i=2,n-1

	      gra1_xx(i)=gra1(i+1)*dh1(i)+gra1(i)*dh2(i)
	      gra2_xx(i)=gra2(i+1)*dh1(i)+gra2(i)*dh2(i)
	      gra1_r_xx(i)=gra1_r(i+1)*dh1(i)+gra1_r(i)*dh2(i)
	      gra2_r2_xx(i)=gra2_r2(i+1)*dh1(i)+gra2_r2(i)*dh2(i)
	      one_r_xx(i)=one_r(i+1)*dh1(i)+one_r(i)*dh2(i)
	      one_r2_xx(i)=one_r2(i+1)*dh1(i)+one_r2(i)*dh2(i)
	      r_av_xx(i)=r_av(i+1)*dh1(i)+r_av(i)*dh2(i)
	      r2_av_xx(i)=r2_av(i+1)*dh1(i)+r2_av(i)*dh2(i)
	      vi_xx(i)=vi(i+1)*dh1(i)+vi(i)*dh2(i)
	      spo_xx(i)=spo(i+1)*dh1(i)+spo(i)*dh2(i)
	      b2_av_xx(i)=b2_av(i+1)*dh1(i)+b2_av(i)*dh2(i)
	      one_r2_vi_xx(i)=one_r2_vi(i+1)*dh1(i)+
     *  one_r2_vi(i)*dh2(i)


	      ft_xx(i)=ft(i+1)*dh1(i)+ft(i)*dh2(i)
c	      ft_xx(i)=fasp(i+1)*dh1(i)+fasp(i)*dh2(i)

	      f_xx(i)=f(i+1)*dh1(i)+f(i)*dh2(i)
	      q_xx(i)=q(i+1)*dh1(i)+q(i)*dh2(i)

	      gra2_b2_xx(i)=gra2_b2(i+1)*dh1(i)+gra2_b2(i)*dh2(i)
	      one_b2_xx(i)=one_b2(i+1)*dh1(i)+one_b2(i)*dh2(i)

	      e_xx(i)=(volt(i+1)*dh1(i)+volt(i)*dh2(i))


	   end do


	      gra1_xx(1)=gra1(1)
	      gra2_xx(1)=gra2(1)
	      gra1_r_xx(1)=gra1_r(1)
	      gra2_r2_xx(1)=gra2_r2(1)
	      one_r_xx(1)=one_r(1)
	      one_r2_xx(1)=one_r2(1)
	      r_av_xx(1)=r_av(1)
	      r2_av_xx(1)=r2_av(1)
	      vi_xx(1)=vi(1)
	      spo_xx(1)=spo(1)
	      b2_av_xx(1)=b2_av(1)
	      ft_xx(1)=ft(1)
c	      ft_xx(1)=fasp(1)
	      f_xx(1)=f(1)
	      f_xx(n)=f(n)

	      gra2_b2_xx(1)=gra2_b2(1)
	      one_b2_xx(1)=one_b2(1)

	      e_xx(1)=volt(1)

 	teta_xx=1.


        call inter_h0(gra1,ai,n,teta_xx,val)
	gra1_xx(n)=val

        call inter_h0(gra2,ai,n,teta_xx,val)
	gra2_xx(n)=val

        call inter_h0(gra1_r,ai,n,teta_xx,val)
	gra1_r_xx(n)=val

        call inter_h0(gra2_r2,ai,n,teta_xx,val)
	gra2_r2_xx(n)=val

        call inter_h0(one_r,ai,n,teta_xx,val)
	one_r_xx(n)=val

        call inter_h0(one_r2,ai,n,teta_xx,val)
	one_r2_xx(n)=val

        call inter_h0(r_av,ai,n,teta_xx,val)
	r_av_xx(n)=val

        call inter_h0(r2_av,ai,n,teta_xx,val)
	r2_av_xx(n)=val

        call inter_h0(vi,ai,n,teta_xx,val)
	vi_xx(n)=val

        call inter_h0(spo,ai,n,teta_xx,val)
	spo_xx(n)=val

        call inter_h0(b2_av,ai,n,teta_xx,val)
	b2_av_xx(n)=val

        call inter_h0(one_r2_vi,ai,n,teta_xx,val)
	one_r2_vi_xx(n)=val


 	teta_xx=1.
        call inter_h0(ft,ai,n,teta_xx,val)
	ft_xx(n)=val

c 	teta_xx=1.
c        call inter_h0(fasp,ai,n,teta_xx,val)
c	ft_xx(n)=val

 	teta_xx=1.
        call inter_h0(q,ai,n,teta_xx,val)
	q_xx(n)=val

        call inter_h0(gra2_b2,ai,n,teta_xx,val)
	gra2_b2_xx(n)=val

        call inter_h0(one_b2,ai,n,teta_xx,val)
	one_b2_xx(n)=val

        call inter_h0(volt,ai,n,teta_xx,val)
	e_xx(n)=val


	if(kpr.eq.1)then
	apr=' tok1--'
	print 71,apr,(tok1(j),j=1,n)
	apr=' tok1_xx--'
	print 71,apr,(tok1_xx(j),j=1,n)

	apr=' gra1--'
	print 71,apr,(gra1(j),j=1,n)
	apr=' gra1--'
	print 71,apr,(gra1_xx(j),j=1,n)

	apr=' gra2--'
	print 71,apr,(gra2(j),j=1,n)
	apr=' gra2_xx--'
	print 71,apr,(gra2_xx(j),j=1,n)

	apr=' gra1_r--'
	print 71,apr,(gra1_r(j),j=1,n)
	apr=' gra1_r_xx--'
	print 71,apr,(gra1_r_xx(j),j=1,n)

	apr=' gra2_r2--'
	print 71,apr,(gra2_r2(j),j=1,n)
	apr=' gra2_r2_xx--'
	print 71,apr,(gra2_r2_xx(j),j=1,n)

	apr=' one_r--'
	print 71,apr,(one_r(j),j=1,n)
	apr=' one_r_xx--'
	print 71,apr,(one_r_xx(j),j=1,n)

	apr=' one_r2--'
	print 71,apr,(one_r2(j),j=1,n)
	apr=' one_r2_xx--'
	print 71,apr,(one_r2_xx(j),j=1,n)

	apr=' r_av--'
	print 71,apr,(r_av(j),j=1,n)
	apr=' r_av_xx--'
	print 71,apr,(r_av_xx(j),j=1,n)

	apr=' r2_av--'
	print 71,apr,(r2_av(j),j=1,n)
	apr=' r2_av_xx--'
	print 71,apr,(r2_av_xx(j),j=1,n)


	apr=' vi--'
	print 71,apr,(vi(j),j=1,n)
	apr=' vi_xx--'
	print 71,apr,(vi_xx(j),j=1,n)

	apr=' spo--'
	print 71,apr,(spo(j),j=1,n)
	apr=' spo_xx--'
	print 71,apr,(spo_xx(j),j=1,n)


	apr=' b2_av--'
	print 71,apr,(b2_av(j),j=1,n)
	apr=' b2_av_xx--'
	print 71,apr,(b2_av_xx(j),j=1,n)


	apr=' one_r2_vi--'
	print 71,apr,(one_r2_vi(j),j=1,n)
	apr=' one_r2_vi_xx--'
	print 71,apr,(one_r2_vi_xx(j),j=1,n)
	
	end if


	bt_cron=bt0*rs0/r_m(n)


	ro_max=dsqrt(dfmax(n)/(pi*bt_cron))

c	print *,' rs0 r_m==',rs0,r_m(n)
c	print *,' bt0 bt_cron==',bt0,bt_cron


 	teta=1.d0
      call inter_h0(ppx,a,n-1,teta,val)

	ppx(n)=val

 	teta=1.d0
	call inter_h0(pffx,a,n-1,teta,val)

	pffx(n)=val



	do i=1,n 
	   f_xx(i)=f_xx(i)*(rs0*0.01d0)*0.1d0
	   e_xx(i)=e_xx(i)/(2.d0*pi*rmag*1.d-2)
	end do

	if(kpr.eq.3)then
	do i=1,10
	a_print(i)=p(i)
	end do	
	n_pr=10
	apr='-- p_cr --'
	num=25
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)
	end if


	do k=1,n
	   i=k

	   cronos_prof(i)=dm0(k)*1.d-5
c	   cronos_prof(i)=dsqrt(poa_h2(k))
c	   cronos_prof(i)=poa_h2(k)

c	   cronos_prof(i)=(psval(k)-psval(1))*2.d0*pi*1.d-5


	   i=1*n+k
	   cronos_prof(i)=dfmax(k)*1.d-5
	   i=2*n+k
	   cronos_prof(i)=tok1_xx(k)*1.d7
	   i=3*n+k
	   cronos_prof(i)=gra1_xx(k)*ro_max
	   i=4*n+k
	   cronos_prof(i)=gra2_xx(k)*ro_max**2
	   i=5*n+k
	   cronos_prof(i)=gra1_r_xx(k)*ro_max*1.d2
	   i=6*n+k


	   cronos_prof(i)=gra2_r2_xx(k)*1.d+4*ro_max**2/ro_max
	   i=7*n+k
	   cronos_prof(i)=one_r_xx(k)*1.d2
	   i=8*n+k
	   cronos_prof(i)=one_r2_xx(k)*1.d4
	   i=9*n+k
	   cronos_prof(i)=r_av_xx(k)*1.d-2
	   i=10*n+k
	   cronos_prof(i)=r2_av_xx(k)*1.d-4
	   i=11*n+k

           dv_dro=2.d0*pi*vi_xx(k)*1.d-4/ro_max

	   cronos_prof(i)=dv_dro
	   i=12*n+k
	   cronos_prof(i)=spo_xx(k)*1.d-2/ro_max
	   i=13*n+k

	   cronos_prof(i)=p(k)/( 200.*1.d-6 )*1.d16
	   i=14*n+k
	   cronos_prof(i)=b2_av_xx(k)*1.d-2
	   i=15*n+k
	   cronos_prof(i)=2.d0*pi*one_r2_vi_xx(k)/ro_max

	   pptabi=-ppx(k)/(rs0*1.d-2)*10.d0

	   i=16*n+k
	   cronos_prof(i)=pptabi

	   fptabi=-0.5d0*pffx(k)*(rs0*1.d-2)*10.d0

	   i=17*n+k
	   cronos_prof(i)=fptabi

c additional data for Cronos....
	   
	   i=18*n+k
	   cronos_prof(i)=ft_xx(k)

	   i=19*n+k
	   cronos_prof(i)=f_xx(k)

	   i=20*n+k
	   cronos_prof(i)=q_xx(k)

	   i=21*n+k
	   cronos_prof(i)=gra2_b2_xx(k)*1.d+2*ro_max**2

	   i=22*n+k

cccc	   cronos_prof(i)=a(k)

           ro_maxk=dsqrt(dfmax(k)*1.d-5/(pi*bt_cron*1.d-1))

	   cronos_prof(i)=ro_maxk

	   i=23*n+k
	   cronos_prof(i)=one_b2_xx(k)*1.d2

	   i=24*n+k
	   cronos_prof(i)=shafra(k)

	   i=25*n+k
	   cronos_prof(i)=elonga(k)

	   i=26*n+k
	   cronos_prof(i)=tria_up(k)

	   i=27*n+k
	   cronos_prof(i)=tria_dw(k)


	   i=28*n+k
	   cronos_prof(i)=volt_pol(k)

	   i=29*n+k
	   cronos_prof(i)=e_xx(k)

	end do             



	if(kpr.eq.1)then
	apr='  psi--'
	print 71,apr,(cronos_prof(j),j=1,n)
	apr='  fi--'                                                       
	print 71,apr,(cronos_prof(j),j=n+1,n+n)
	apr=' tok1--'                                                       
	print 71,apr,(cronos_prof(j),j=2*n+1,2*n+n)
	apr=' gra1--'                                                       
	print 71,apr,(cronos_prof(j),j=3*n+1,3*n+n)
	apr='  gra2'                                                       
	print 71,apr,(cronos_prof(j),j=4*n+1,4*n+n)
	apr=' gra1_r--'                                                       
	print 71,apr,(cronos_prof(j),j=5*n+1,5*n+n)
	apr=' gra2_r2-'                                                       
	print 71,apr,(cronos_prof(j),j=6*n+1,6*n+n)
	apr=' one_r--'                                                       
	print 71,apr,(cronos_prof(j),j=7*n+1,7*n+n)
	apr=' one_r2--'                                                       
	print 71,apr,(cronos_prof(j),j=8*n+1,8*n+n)
	apr=' r_av--'                                                       
	print 71,apr,(cronos_prof(j),j=9*n+1,9*n+n)
	apr=' r2_av--'                                                       
	print 71,apr,(cronos_prof(j),j=10*n+1,10*n+n)
	apr=' vi--'                                                       
	print 71,apr,(cronos_prof(j),j=11*n+1,11*n+n)
	apr=' spo--'                                                       
	print 71,apr,(cronos_prof(j),j=12*n+1,12*n+n)
	apr=' p--'                                                       
	print 71,apr,(cronos_prof(j),j=13*n+1,13*n+n)
	apr=' b2_av--'                                                       
	print 71,apr,(cronos_prof(j),j=14*n+1,14*n+n)
	apr=' one_r2_vi'                                                       
	print 71,apr,(cronos_prof(j),j=15*n+1,15*n+n)

	end if

                                                                        

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))                                      

                                                                        

	return                                                                 

	end                                                                    



      subroutine  write3_to_mat(key_mat,vec_mat,kpr,n_key,n_vec) 

      	include 'double.inc'
                                                                        

	dimension key_mat(*)                                                   

                                                                        

	real *8 vec_mat(*)                                                     


	open (unit=41,file='key_mat.fla',form='formatted')                    

	k_mat=n_key 

	write (41,*)' k_mat '

	write(41,*)k_mat                                                       
                                                                        
	do k=1,k_mat                                                           
           write (41,*)key_mat(k)
	end do                                                                 

	write (41,*)'    '
	
	close (41)                                                             

                                                                        

c	print *,' k_mat of KEY_MAT',k_mat        

                              

c	print *,' key_mat',(key_mat(i),i=1,k_mat)

                                                                        
	k_mat=n_vec

	open (unit=41,file='vec_mat.fla',form='formatted')                    

	write (41,*)' k_mat '

	write(41,*)k_mat                                                       
                                                                        
	do k=1,k_mat                                                           
           write (41,*)vec_mat(k)
	end do                                                                 

	write (41,*)'    '
	
	close (41)                                                             

	close (41)                                                             


	if(kpr.eq.1)print *,' k_mat of VEC_MAT',k_mat


	return                                                                 

	end 


        subroutine  read3_to_mat(key_mat,vec_mat,kpr)
      	include 'double.inc'

	dimension key_mat(*)

	real *8 vec_mat(*)                                                     

                                                                        

                                                                        

	open (unit=41,file='key_mat.flat',form='formatted')                    

                                                                        

	read (41,*)                                                            

	read (41,*)k_mat                                                       

                                                                        

	do k=1,k_mat                                                           

           read (41,*)p

           key_mat(k)=p

	end do                                                                 

                                                 

	close (41)                                                             

                                                                        

c	print *,' k_mat of KEY_MAT',k_mat        

                              

c	print *,' key_mat',(key_mat(i),i=1,k_mat)

                                                                        

	open (unit=41,file='vec_mat.flat',form='formatted')                    

                                                                        

	read (41,*)                                                            

	read (41,*)k_mat                                                       

                                                                        

	do k=1,k_mat                                                           

	read (41,*)vec_mat(k)                                                  

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	if(kpr.eq.1)print *,' k_mat of VEC_MAT',k_mat                                      

                                                                        

	return                                                                 

	end                                                                    

        subroutine  read2_to_mat(                                       

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

      	include 'double.inc'


	include 'parf2'                                                        

                                                                        

        real*8 fluxarr_mat(nwnh,*),vesarr_mat(nwnh,*),                  

     *	pslgreen_mat(nwnh,*),bprgreen_mat(nwnh,*),                       

     *	pfind_mat(kf_mat,*),pmj_mat(mu_mat,*),                           

     *  pfc_mat(mu_mat,*),                                              

     *  pfres_mat(*),rcam_mat(*),                                       

     *  xu_mat(*),yu_mat(*),

     *  pf_mat(*),tcam_mat(*),

     *  pfgreen_mat(kloop_mat,*),vesgreen_mat(kloop_mat,*),

     *  pfprobe_mat(kprobe_mat,*),vesprobe_mat(kprobe_mat,*)

                                               

	real *8 z_l,z_r,r_l,r_r                                                

                                                                        

                                                                        

	open (unit=41,file='gridrange.flat',form='formatted')                  

                                                                        

	read (41,*)                                                            

	read (41,*)                                                            

                                                                        

	read (41,*)z_l                                                         

	read (41,*)z_r                                                         

	read (41,*)r_l                                                         

	read (41,*)r_r                                                         

c	print *,' z_l z_r r_l r_r==',z_l,z_r,r_l,r_r                           

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='xu_mat.flat',form='formatted')                     

                                                                        

	read (41,*)ke_mat                                                      

	read (41,*)                                                            

                                                                        

	do k=1,ke_mat                                                          

	read (41,*)xu_mat(k)                                                   

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='yu_mat.flat',form='formatted')                     

                                                                        

	read (41,*)ke_mat                                                      

	read (41,*)                                                            

                                                                        

	do k=1,ke_mat                                                          

	read (41,*)yu_mat(k)                                                   

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='rcam_mat.flat',form='formatted')                   

                                                                        

	read (41,*)ncam_mat                                                    

	read (41,*)                                                            

	do k=1,ncam_mat                                                        

	read (41,*)rcam_mat(k)                                                 

	end do                                                                 

                                                                        

	close (41)                                           



                  

	open (unit=41,file='tcam_mat.flat',form='formatted')          

                                                                        

	read (41,*)ncam_mat                                                    

	read (41,*)                                                            

	do k=1,ncam_mat                                                        

	read (41,*)tcam_mat(k)                                                 

	end do                                                                 

	close (41)                                                             

	if(tcam_mat(1).gt.1.e8)then

	do k=1,ncam_mat                                                        

	tcam_mat(k)=0.                                                 

	end do                                                                 
                                                                        
	end if

	open (unit=41,file='pmj_mat.flat',form='formatted')                    

                                                                        

	read (41,*)ncam_mat                                                    

	read (41,*)                                                            

                                                                        

	do kk=1,ncam_mat                                                       

	   do k=1,ncam_mat                                                     

	      read (41,*)pmj_mat(k,kk)                                         

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='pfc_mat.flat',form='formatted')                    

                                                                        

	read (41,*)ncam_mat                                                    

	read (41,*)npf_mat                                                     

                                                                        

	do kk=1,npf_mat                                                        

	   do k=1,ncam_mat                                                     

	   read (41,*)pfc_mat(k,kk)                                            

	end do                                                                 

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='pfres_mat.flat',form='formatted')                  

                                                                        

	read (41,*)npf_mat                                                     

	read (41,*)                                                            

	do k=1,npf_mat                                                         

	   read (41,*)pfres_mat(k)                                             

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

                                                                        

	open (unit=41,file='pfind_mat.flat',form='formatted')                  

                                                                        

	read (41,*)npf_mat                                                     

	read (41,*)                                                            

	do kk=1,npf_mat                                                        

	   do k=1,npf_mat                                                      

	      read (41,*)pfind_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

                                                                        

	open (unit=41,file='vesarr_mat.flat',form='formatted')                 

                                                                        

	read (41,*)                                                            

	read (41,*)                                                            

	do k=1,ncam_mat                                                        

	   do kk=1,nwnh                                                        

	      read (41,*)vesarr_mat(kk,k)                                      

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='fluxarr_mat.flat',form='formatted')                

                                                                        

	read (41,*)                                                            

	read (41,*)                                                            

	do k=1,npf_mat                                                         

	   do kk=1,nwnh                                                        

	      read (41,*)fluxarr_mat(kk,k)                                     

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='pslgreen_mat.flat',form='formatted')               

                                                                        

	read (41,*)                                                            

	read (41,*)kloop_mat                                                   

	do k=1,kloop_mat                                                       

	   do kk=1,nwnh                                                        

	   read (41,*)pslgreen_mat(kk,k)                                       

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             



	open (unit=41,file='pfgreen_mat.flat',form='formatted')               

	read (41,*)

	read (41,*)

	do k=1,kloop_mat                                                       

	   do kk=1,npf_mat

	   read (41,*)pfgreen_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='vesgreen_mat.flat',form='formatted')               

	read (41,*)

	read (41,*)

	do k=1,kloop_mat                                                       

	   do kk=1,ncam_mat

	   read (41,*)vesgreen_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             



                                                                        

	open (unit=41,file='bprgreen_mat.flat',form='formatted')               

                                                                        

	read (41,*)                                                            

	read (41,*)kprobe_mat                                                  

	do k=1,kprobe_mat                                                      

	   do kk=1,nwnh                                                        

	   read (41,*)bprgreen_mat(kk,k)                                       

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             



	open (unit=41,file='pfprobe_mat.flat',form='formatted')               

	read (41,*)

	read (41,*)

	do k=1,kprobe_mat                                                      

	   do kk=1,npf_mat

	   read (41,*)pfprobe_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             



	open (unit=41,file='vesprobe_mat.flat',form='formatted')               

	read (41,*)

	read (41,*)

	do k=1,kprobe_mat                                                      

	   do kk=1,ncam_mat

	   read (41,*)vesprobe_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='cc0.flat',form='formatted')                        

                                                                        

	read (41,*)npf_mat                                                     

	read (41,*)                                                            

	do k=1,npf_mat                                                         

	   read (41,*)pf_mat(k)                                                

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

c	print *,' ncam_mat,npf_mat,ke_mat',ncam_mat,npf_mat,ke_mat             

c	print *,' kloop_mat,kprobe_mat',kloop_mat,kprobe_mat                   

                                                                        

                                                                        

c                                                                       

        RETURN                                                          

        END                                                             
        subroutine  write2_to_mat(                                       

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

      	include 'double.inc'
                                                                        

	include 'parf2'                                                        

                                                                        

        real*8 fluxarr_mat(nwnh,*),vesarr_mat(nwnh,*),                  

     *	pslgreen_mat(nwnh,*),bprgreen_mat(nwnh,*),                       

     *	pfind_mat(kf_mat,*),pmj_mat(mu_mat,*),                           

     *  pfc_mat(mu_mat,*),                                              

     *  pfres_mat(*),rcam_mat(*),                                       

     *  xu_mat(*),yu_mat(*),                                            

     *  pf_mat(*),tcam_mat(*),

     *  pfgreen_mat(kloop_mat,*),vesgreen_mat(kloop_mat,*),

     *  pfprobe_mat(kprobe_mat,*),vesprobe_mat(kprobe_mat,*)

                                                                        

	real *8 z_l,z_r,r_l,r_r                                                

                                                                        

                                                                        

	open (unit=41,file='gridrange.flat',form='formatted')                  

                                                                        

	write (41,*)' 1 '                                                            

	write (41,*) ' 4 '                                                            

                                                                        

	write (41,*)z_l                                                         

	write (41,*)z_r                                                         

	write (41,*)r_l                                                         

	write (41,*)r_r                                                         

c	print *,' z_l z_r r_l r_r==',z_l,z_r,r_l,r_r                           

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='xu_mat.flat',form='formatted')                     

                                                                        

	write (41,*)ke_mat                                                      

	write (41,*)' 1  '                                                            

                                                                        

	do k=1,ke_mat                                                          

	write (41,*)xu_mat(k)                                                   

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='yu_mat.flat',form='formatted')                     

                                                                        

	write (41,*)ke_mat                                                      

	write (41,*)' 1 '                                                            

                                                                        

	do k=1,ke_mat                                                          

	write (41,*)yu_mat(k)                                                   

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='rcam_mat.flat',form='formatted')                   

                                                                        

	write (41,*)ncam_mat                                                    

	write (41,*)' 1 '                                                            

	do k=1,ncam_mat                                                        

	write (41,*)rcam_mat(k)                                                 

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                               
                                                                        

	open (unit=41,file='pmj_mat.flat',form='formatted')                    

                                                                        

	write (41,*)ncam_mat                                                    

	write (41,*)' 1 '                                                            

                                                                        

	do kk=1,ncam_mat                                                       

	   do k=1,ncam_mat                                                     

	      write (41,*)pmj_mat(k,kk)                                         

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='pfc_mat.flat',form='formatted')                    

                                                                        

	write (41,*)ncam_mat                                                    

	write (41,*)npf_mat                                                     

                                                                        

	do kk=1,npf_mat                                                        

	   do k=1,ncam_mat                                                     

	   write (41,*)pfc_mat(k,kk)                                            

	end do                                                                 

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='pfres_mat.flat',form='formatted')                  

                                                                        

	write (41,*)npf_mat                                                     

	write (41,*)' 1 '                                                            

	do k=1,npf_mat                                                         

	   write (41,*)pfres_mat(k)                                             

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

                                                                        

	open (unit=41,file='pfind_mat.flat',form='formatted')                  

                                                                        

	write (41,*)npf_mat                                                     

	write (41,*)'20 '

      

	do kk=1,npf_mat                                                        

	   do k=1,npf_mat                                                      

	      write (41,*)pfind_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

                                                                        

	open (unit=41,file='vesarr_mat.flat',form='formatted')                 

                                                                        

	write (41,*)nwnh                                                         

	write (41,*)ncam_mat                                                         

	do k=1,ncam_mat                                                        

	   do kk=1,nwnh                                                        

	      write (41,*)vesarr_mat(kk,k)                                      

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='fluxarr_mat.flat',form='formatted')                

                                                                        

	write (41,*)nwnh                                                          

	write (41,*)npf_mat                                                   

	do k=1,npf_mat                                                         

	   do kk=1,nwnh                                                        

	      write(41,*)fluxarr_mat(kk,k)                                     

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='pslgreen_mat.flat',form='formatted')               

                                                                        

	write (41,*)nwnh                                                         

	write (41,*)kloop_mat                                                   

	do k=1,kloop_mat                                                       

	   do kk=1,nwnh                                                        

	   write (41,*)pslgreen_mat(kk,k)                                       

	   end do                                                              

	end do                                                                 

                                                                        

	close (41)                                                             

                                                                        

	open (unit=41,file='pfgreen_mat.flat',form='formatted')               

	write (41,*)npf_mat       

	write (41,*)kloop_mat                                                   

	do k=1,kloop_mat                                                       

	   do kk=1,npf_mat

	   write (41,*)pfgreen_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='vesgreen_mat.flat',form='formatted')               

	write (41,*)ncam_mat       

	write (41,*)kloop_mat                                                   

	do k=1,kloop_mat                                                       

	   do kk=1,ncam_mat

	   write (41,*)vesgreen_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        

	open (unit=41,file='bprgreen_mat.flat',form='formatted')               

	write (41,*) nwnh

	write (41,*)kprobe_mat                                                  

	do k=1,kprobe_mat                                                      

	   do kk=1,nwnh                                                        

	   write (41,*)bprgreen_mat(kk,k)                                       

	   end do                                                              

	end do                                                                 

	close (41)



	open (unit=41,file='pfprobe_mat.flat',form='formatted')               

	write (41,*)npf_mat

	write (41,*)kprobe_mat                                                  

	do k=1,kprobe_mat                                                      

	   do kk=1,npf_mat

	   write (41,*)pfprobe_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             



	open (unit=41,file='vesprobe_mat.flat',form='formatted')               

	write (41,*)ncam_mat

	write (41,*)kprobe_mat                                                  

	do k=1,kprobe_mat                                                      

	   do kk=1,ncam_mat

	   write (41,*)vesprobe_mat(k,kk)                                       

	   end do                                                              

	end do                                                                 

	close (41)                                                             

                                                                        
                                                                        

c	print *,' ncam_mat,npf_mat,ke_mat',ncam_mat,npf_mat,ke_mat             

c	print *,' kloop_mat,kprobe_mat',kloop_mat,kprobe_mat                   

                                                                        

                                                                        

c                                                                       

        RETURN                                                          

        END                                                             
	subroutine stabz(ich_xx,i_graph_xx)
      	include 'double.inc'

	include 'new_com.inc'



	call stabz_c(ich_xx,i_graph_xx,

     *  rref,zref,bvert,brad,it1,dx,dy,

     *  rmag,zmag,zmag0,pmag,psep,eu)

      

	return

	end





	subroutine stabz_c(ich,i_graph,

     *  rl,zl,clr,clz,it1,dx,dy,

     *  rmag,zmag,zmag0,pmag,psep,eu)

      include 'double.inc'

	character *30 apr

	dimension a_print(200)


	pbound=psep





	it_tot=0



 23	continue



c	zl=2.*zl-zmag0



	zl=1.5d0*zl-0.5d0*zmag0



c	print *,' zmag zmag0 zl clz int_it',

c     *  zmag,zmag0,zl,clz,int_it



c        open(unit=43,file='f43',form='formatted',access='append')       

c	write(43,*)' zmag zmag0 zl clz int_it',

c     *  zmag,zmag0,zl,clz,int_it

c        close (43)



	int_it=0



 22	   continue



	   int_it=int_it+1

	      call ptoke1()

c	      if(int_it.gt.20)it1=0

	   if(it1.eq.1)go to 22



c	   if(i_graph.eq.1)call graphic(it1,n)



	   crz=dabs(clz*eu/(pmag-pbound))

	

	   it_tot=it_tot+1



c        open(unit=43,file='f43',form='formatted',access='append')       

c           open(unit=43,file='f43',form='formatted')       

	a_print(1)=clz

	a_print(2)=crz

	a_print(3)=int_it

	a_print(4)=it_tot


	n_pr=4

	apr=' clr crz int_it it_tot '

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	if(dabs(crz).gt.1.e-4)go to 23

           

	   return

                                                       

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

c	ceps=0.1

	ceps=0.04

!	ceps=0.02

	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl

	n_pr=4

	apr=' clr clz zl rl ENTER '

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


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

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

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

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

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

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	   if(dll .gt. dllim) then                  

                                                       

	      nstp=dll/dllim                       

                                                       

	      ddrr=delrl/nstp                      

	      ddzz=delzl/nstp                      




	      if(nstp.ge.5)nstp=5

!	      if(nstp.ge.3)nstp=3

!	      if(nstp.ge.10)nstp=10

c	      if(nstp.ge.2)nstp=2

c	      if(nstp.ge.50)nstp=50



	      do  istep=1,nstp                  

                                                       

          if(kpr.eq.1)write(6,*) 'slow shift',istep,nstp   

	a_print(1)=istep

	a_print(2)=nstep

	n_pr=2

	apr=' slow shift istep nstep '

	num=30

c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

                                                       

		 rl=rl0+ ddrr*istep                   

		 zl=zl0+ ddzz*istep



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

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)



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

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)
		

	   else                                     

                                                       

	      rl=rl0+ delrl                         

	      zl=zl0+ delzl



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

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	   endif                                    


	   ich=0


	endif                                    



c	ceps=ceps*0.5



        crz=dabs(clr*rmag/(pmag-pbound))+

     *  dabs(clz*(zmag-zsep)/(pmag-pbound))



	

	iter=iter+1



	if(kpr.eq.1)print *,' ITER pmag pbound zsep==',pmag,pbound,zsep

	if(kpr.eq.1)print *,' ITER clr clz crz==',iter,clr,clz,crz




	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=iter

	n_pr=3

	apr=' clr clz iter'

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	if(dabs(crz).gt.1.e-5.and.iter.le.11)go to 1000

!	if(dabs(crz).gt.1.e-5.and.iter.le.10)go to 1000

c	if(dabs(crz).gt.1.e-5)go to 1000

c	if(dabs(crz).gt.1.e-3)go to 1000



	a_print(1)=crz

	a_print(2)=clr

	a_print(3)=clz

	a_print(4)=zl

	a_print(5)=rl

	a_print(6)=iter

	n_pr=6

	apr='crz clr clz zl rl ITER'

	num=20

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

c	stop

                                                       

	return

	end


	subroutine write_shape(shape_out,k_out,i_dop,kpr)
      	include 'double.inc'
	real *8  shape_out(*)

	i_dop=i_dop+1
	igr=1

	if(i_dop.eq.1)then 
	open (unit=42,file='for042.txt',
     *	form='formatted')
	else
	open (unit=42,file='for042.txt',access='append',
     *	form='formatted')
	end if

c
	if(kpr.eq.1)print*,'!!! i_dop k_out',i_dop,k_out

	write (42,5001)igr,k_out
c
	
c	shape_out(1)=shape_out(1)*1.d-6
	shape_out(23)=shape_out(23)*1.d3

	write (42,5000) (shape_out(i),i=1,k_out),shape_out(23)
	

	close (unit=42)

5001    format(4i4)
5000    format (6(1pe14.6))

	return
	end

	subroutine tt_init(tt_xx)
      	include 'double.inc'
	
	real *8 tt_xx
	include 'new_com.inc'

	tt=tt_xx*1.e3

c	tt=700.1

	return

	end

	subroutine asdex_test()
      	include 'double.inc'
	include 'new_com.inc'

	i_stop=0
	if(npf.ne.13)i_stop=1
	if(kloop.ne.36)i_stop=1
	if(kprobe.ne.59)i_stop=1
	if(ncam.ne.60)i_stop=1

	if(i_stop.eq.1)then
	   print *,' THIS IS NOT ASDEX MASHINE STOP!!!'
	   stop
	end if
	return

	end



	subroutine tcam_test()
      	include 'double.inc'
	include 'new_com.inc'

	dimension a_print(100)

     	character *20 apr



        tokc=0.                                              
	do i=1,ncam                      
	   tokc=tokc+tcam(i)
	end do                                                                 

	a_print(1)=tokc

	n_pr=1

	apr='+++++ tokc  '

	num=25

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	return
	end


	subroutine prof_save(i_save)
	include 'double.inc'
	include 'new_com.inc'

	call prof_save_c(i_save,
     *  n,dm0,f,pp,pff,psi8,kpr)

	return
	end

	subroutine prof_save_c(i_save,
     *  n,dm0,f,pp,pff,psi8,kpr)

	include 'double.inc'
	dimension dm0(*),f(*),pp(*),pff(*),psi8(*)

	include 'parf0'

	dimension dm0_help(npo),f_help(npo),pp_help(npo),
     *  pff_help(npo),psi8_help(npo)

	character *20 apr                                                      

	dimension a_print(100)

	a_print(1)=n
	a_print(2)=i_save
	n_pr=2
	apr='   n i_save **'
	num=20
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	if(i_save.eq.1)then
	do i=1,n
	dm0_help(i)=dm0(i)
	f_help(i)=f(i)
	pff_help(i)=pff(i)
	pp_help(i)=pp(i)
	psi8_help(i)=psi8(i)
	end do
	else
	do i=1,n
	dm0(i)=dm0_help(i)
	f(i)=f_help(i)
	pff(i)=pff_help(i)
	pp(i)=pp_help(i)
	psi8(i)=psi8_help(i)
	end do
	end if


	return
	end



c	include 'control_new.f'                                                  



	subroutine stab_test(ich_xx,i_graph_xx)
      	include 'double.inc'

	include 'new_com.inc'



	call stab_test_c(ich_xx,i_graph_xx,

     *  rref,zref,bvert,brad,it1,dx,dy,

     *  rmag,zmag,pmag,psep,zsep,kpr)

      

	return

	end





	subroutine stab_test_c(ich,i_graph,

     *  rl,zl,clr,clz,it1,dx,dy,

     *  rmag,zmag,pmag,psep,zsep,kpr)

      include 'double.inc'


	character *30 apr

	dimension a_print(100)



	pbound=psep


c	print *,' clr clz rl zl==',clr,clz,rl,zl


c	ceps=0.2

	ceps=0.02

c	ceps=0.02


      int_it=0
	iter=0
	it1=1

	ni=10
	nj=10

	ddrr=6.
	ddzz=6.

	rl0=rmag
	zl0=zmag

	do  i=1,ni                  
	do  j=1,nj                  
	rl=rl0-0.5*ddrr+i*ddrr/ni
	zl=zl0-0.5*ddzz+ j*ddzz/nj

c	print *,' i j rl zl ',i,j,rl,zl

      int_it=0
778	continue

	int_it=int_it+1
      call ptoke1()

	if(int_it.eq.100)then 
c	print *,' int_it==',int_it
	it1=0
	end if


	if(it1.ne.0)go to 778

	a_print(1)=i

	a_print(2)=j

	a_print(3)=rl

	a_print(4)=zl

	a_print(5)=clr

	a_print(6)=clz


	n_pr=6

	apr=' i j  rl zl clr clz '

	num=30

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)
c      write(6,'("i j  rl  zl", 2i4,4(1pe13.6))'),
c     *  i,j,rl,zl,clr,clz
c	call pau()
c	read (*,*)


	end do

c	read (*,*)
!!!      call  write_surf_eq()
	end do

c	stop

	return

	end





	subroutine stab_rz_test(ich_xx,i_graph_xx)
      	include 'double.inc'

	include 'new_com.inc'



	call stab_rz_test_c(ich_xx,i_graph_xx,

     *  rref,zref,bvert,brad,it1,dx,dy,

     *  rmag,zmag,rmag0,zmag0,kpr,

     *  pmag,pbound,zsep)

      

	return

	end





	subroutine stab_rz_test_c(ich,i_graph,

     *  rl,zl,clr,clz,it1,dx,dy,

     *  rmag,zmag,rmag0,zmag0,kpr,

     *  pmag,pbound,zsep)

      	include 'double.inc'


	character *20 apr

	dimension a_print(200)



	pbound=psep

	iter=0

c	ceps=0.1

	ceps=0.02


	b_min=1.d15

	n_kk=7

c	delr=3*dx
	delr=5*dx

c	rl0=rmag-0.5d0*delr

	iter=0

 23	   continue
     
	iter=iter+1


	rl0=rmag-0.5d0*delr

	do kk=1,n_kk-1

	rl=rl0+kk*delr/n_kk




	   int_it=0

 22	   continue



	   int_it=int_it+1

	      call ptoke1()

	    if(int_it.gt.40)it1=0

	   if(it1.eq.1)go to 22



	a_print(1)=clr

	a_print(2)=clz

	a_print(3)=zl

	a_print(4)=rl


	n_pr=4

	apr=' clr clz zl rl '

	num=20

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	if(kpr.eq.1)write(6,'(" zmag zmag0 zl clz==",6(1pe12.5))'),
     *  zmag,zmag0,zl,clz
	if(kpr.eq.1)write(6,'(" rmag rmag0 rl clr==",6(1pe12.5))'),
     *  rmag,rmag0,rl,clr



	if(dabs(clr).le.b_min)then
	b_min=dabs(clr)
	bz_min=clz
	r_min=rl
	z_min=zl
	r_min=rl

       crz_min=abs(clr*rmag/(pmag-pbound))+
     *  abs(clz*(zmag-zsep)/(pmag-pbound))


	end if



	end do

	delr=delr*0.5d0
	rmag=r_min

	if(kpr.eq.1)write(6,'(" rmag b_min delr,dx",6(1pe12.5))'),
     *  rmag,b_min,delr,dx


	a_print(1)=crz_min

	a_print(2)=b_min

	a_print(3)=bz_min

	a_print(4)=z_min

	a_print(5)=r_min

	a_print(6)=iter

	n_pr=6

	apr='crz clr clz zl rl ITER'

	num=20

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	if(iter.le.5)go to 23

c	zl=2.*zl-zmag0

	rl=rmag

	   int_it=0

 24	   continue



	   int_it=int_it+1

	      call ptoke1()

	    if(int_it.gt.40)it1=0

	   if(it1.eq.1)go to 24


	if(kpr.eq.1)write(6,'(" zmag zmag0 zl clz==",6(1pe12.5))'),
     *  zmag,zmag0,zl,clz
	if(kpr.eq.1)write(6,'(" rmag rmag0 rl clr==",6(1pe12.5))'),
     *  rmag,rmag0,rl,clr



c	zl=2d0*zl-1.0d0*zmag0





c	stop


	   crz=dabs( clr**2+clz**2 )

	
	   iter=iter+1


c	   print *,' ITER clz clr crz int_it ',iter,clz,clr,crz,int_it

c	   if(dabs(crz).gt.0.1)go to 23

       crz=abs(clr*rmag/(pmag-pbound))+
     *  abs(clz*(zmag-zsep)/(pmag-pbound))

	if(kpr.eq.1)write(6,'(" ITER clr clz crz==",i4,6(1pe12.5))'),
     *  iter,clr,clz,crz



	a_print(1)=crz

	a_print(2)=clr

	a_print(3)=clz

	a_print(4)=zl

	a_print(5)=rl

	a_print(6)=iter

	n_pr=6

	apr='crz clr clz zl rl ITER'

	num=20

	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

c	if(abs(crz).gt.1.d-4.and.iter.lt.250)go to 23


c	end do


c	stop

c

	return

	end


	subroutine stop_fort();

	include 'double.inc'
	include 'new_com.inc'

	character *30 apr

	dimension a_print(200)


	i_exit=1
	a_print(1)=i_exit

	n_pr=1

	apr='-- STOP Simulation or crash--'

	num=20

	call out42(n_pr,a_print,num,apr)


	return

	end




	subroutine print1(apr1,ygr)
		
	include 'double.inc'

	character apr1(*)
	character apr(30)

	dimension a_print(200)

	num=25
	do i=1,25
	apr(i)= apr1(i)
	if(apr1(i).eq.'=')then
	num=i
	goto 1
	end if
	end do

1	continue

c	print *,' num ygr',num,ygr

	a_print(1)=ygr

	n_pr=1
	
	call out42(n_pr,a_print,num,apr)

	return
      END


	subroutine print2(apr1,ygr1,ygr2)
		
	include 'double.inc'

	character apr1(*)
	character apr(30)
	dimension a_print(200)

	num=25
	do i=1,25
	apr(i)= apr1(i)
c	print *,apr1(i)
	if(apr1(i).eq.'=')then
	num=i
	goto 1
	end if
	end do

1	continue

c	print *,' num ygr1 ygr2',num,ygr1,ygr2

	a_print(1)=ygr1
	a_print(2)=ygr2

	n_pr=2

	call out42(n_pr,a_print,num,apr)

	return
      END

	subroutine print3(apr1,ygr1,ygr2,ygr3)
		
	include 'double.inc'

	character apr1(*)
	character apr(30)
	dimension a_print(200)

	num=25
	do i=1,25
	apr(i)= apr1(i)
	if(apr1(i).eq.'=')then
	num=i
	goto 1
	end if
	end do

1	continue

c	print *,' num ygr1 ygr2 ygr3',num,ygr1,ygr2,ygr3

	a_print(1)=ygr1
	a_print(2)=ygr2
	a_print(3)=ygr3

	n_pr=3

	call out42(n_pr,a_print,num,apr)

	return
      END


	subroutine print4(apr1,ygr1,ygr2,ygr3,ygr4)
		
	include 'double.inc'

	character apr1(*)
	character apr(30)
	dimension a_print(200)

	num=25
	do i=1,25
	apr(i)= apr1(i)
	if(apr1(i).eq.'=')then
	num=i
	goto 1
	end if
	end do

1	continue

c	print *,' num ygr1 ygr2 ygr3 ,ygr4',num,ygr1,ygr2,ygr3,ygr4

	a_print(1)=ygr1
	a_print(2)=ygr2
	a_print(3)=ygr3
	a_print(4)=ygr4

	n_pr=4

	call out42(n_pr,a_print,num,apr)

	return
      END

	subroutine printa(apr1,ygr,n)
		
	include 'double.inc'

	character apr1(*)
	character apr(30)
	dimension a_print(200),ygr(*)

	num=25
	do i=1,25
	apr(i)= apr1(i)
	if(apr1(i).eq.'=')then
	num=i
	goto 1
	end if
	end do

1	continue

c	print *,' num n ',num,n

	do i=1,n
	a_print(i)=ygr(i)
	end do

	n_pr=n

	call out42(n_pr,a_print,num,apr)

	return
      END

