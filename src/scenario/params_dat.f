!> dina_data_read is the main subroutine to read the input
!! dina_data.dat and general_data.dat files

        subroutine tokamakdata_read()
	include 'double.inc'
c-----------------------------------------
c	implicit real*8 (a-h,o-z)
	include 'parf1'
 	include 'parf_mike' 
        common
     *  /ge5/kpr
	common                                                                 
     *	/n_m/n,m,mp                                                      

      common /c_tokamak_config1/
     * npf_c,
     * npf_res_c,
     * ncam_c,
     * kloop_c,
     * kprobe_c,kpb_c,
     * ke_c

      common /c_tokamak_config2/
     * nr_c(mu),nz_c(mu),nt_c(mu),n_pf_num_c(mu),
     * R_c_c(mu),Z_c_c(mu),dr_c(mu),dz_c(mu),alpha_c(mu),beta_c(mu),
     * pfres_c(mu),
     * ndl_ves_c(mu),ndh_ves_c(mu),nt_ves_c(mu),n_ves_num_c(mu),
     * Rc_c(mu),Zc_c(mu),dl_c(mu),hl_c(mu),alpha_ves_c(mu),
     * beta_ves_c(mu),
     * rcam_c(mu),
     * Rl_c(mu),Zl_c(mu),
     * R_prob_c(mu),Z_prob_c(mu),anglep_c(mu),smp_c(mu),
     * xu_c(mu),yu_c(mu),
     * r00_c,rk_c,
     * z00_c,zk_c





      common /c_k_jetto/ih_imas_c
      common /c_time_eq/time_eq_c

      common /c_jetto_ids/pulse_c,run_c
      
      common /c_kpr/kpr_c

      common /c_for002_kav/tay_c,rs0_c,bt0_c,key_t11_c
      common /c_for002_kav2/n_c

      common /c_gaps_data_ramp/x_gaps_c(mu),y_gaps_c(mu),n_ga_c

      common /c_tran_times/tt_dina_c

      common /c_pfres/t_t_c1(ntime),pf_t_c1(kf,ntime),n_t_c1,npf_c1


      common /c_ech_c2/t_t_c2(ntime),udd_sol_t_c2(ntime),n_t_c2

      common /c_nd_c3/t_t_c3(ntime),pn_d_t_c3(ntime),n_t_c3


      common /c_gamma_z_c4/t_t_c4(ntime),pn_d_t_c4(ntime),
     *  n_t_c4,nz_imp_c4

      common /c_gamma_z2_c5/t_t_c5(ntime),pn_d_t_c5(ntime),
     *  n_t_c5,nz_imp2_c5

      common /c_init_c6/p_c6,T_e_c6,T_i_c6,gam_c6,g_gain_c6


      common /c_emo_c7/t_t_c7(ntime),emoe_t_c7(ntime),emoq_t_c7(ntime),
     *  n_t_c7

      common /c_dens_c8/t_t_c8(ntime),den_t_c8(ntime),n_t_c8

      common /c_gamma_z1_c9/t_t_c9(ntime),pn_d_t_c9(ntime),
     *  n_t_c9,nz_imp1_c9

      common /c_gamma_z3_c10/t_t_c10(ntime),pn_d_t_c10(ntime),
     *  n_t_c10,nz_imp3_c10

      common /c_gamma_z4_c11/t_t_c11(ntime),pn_d_t_c11(ntime),
     *  n_t_c11,nz_imp4_c11



      common /c_bohm_gbohm_c12/k_Bohm_c12
      common /c_tay_simul_c13/tay_simul_c13
      common /c_dw_c14/tay_dw_c14
      common /c_pcchp_end_c15/pcchp_end_c15
      common /c_ext_c16/k_ener_ext_c16,k_dens_ext_c16,k_ajb_ext_c16

      common /c_tt_kavin2_c1/tt_rampup_c1,dt_end_sim_c1,
     * dtpl_term_l_c1,cIp_end_c1,CS1_eob_c1,rms_noise_c1
      
!      kpr=1

      if(i_data2.eq.1)then
     	open(unit=49,file='dina_data2.dat',
     *  form='formatted')
          read (49,*) 
          read (49,*)n_c
      close (49)      
      end if
      
!      n=n_c
      n_c=50
      n=n_c
      
      if(kpr.eq.1)print *,'n n_c ',n,n_c
      
      ! Initializing 1D grid
      call one2d()
      
     	open(unit=49,file='tokamak_config.dat',
     *  form='formatted')
	if(kpr.eq.1)print *,' opened file tokamak_config.dat'
	read(49,*)
	if(kpr.eq.1)print *,' 1'
	read(49,*)npf_c
	if(kpr.eq.1)print *,'npf ',npf_c
	do I=1,npf_c
	read(49,*)
	read(49,*)nr_c(i),nz_c(i),nt_c(i),n_pf_num_c(i)
c
	if(kpr.eq.1)PRINT*,'i Nr Nz nt pf_num',i,Nr_c(I),nz_c(i),
     *  nt_c(i),n_pf_num_c(i)
	read(49,*)R_c_c(I),Z_c_c(I),dr_c(i),dz_c(i),alpha_c(i),beta_c(i)
	if(kpr.eq.1)print *,'r_c z_c dr dz alpha beta ',
     * r_c_c(i),z_c_c(i),dr_c(i),dz_c(i),alpha_c(i),beta_c(i)
	END DO


	read(49,*)
	if(kpr.eq.1)print *,' res_pf'
	read(49,*)npf_res_c
	if(kpr.eq.1)print *,'npf_res ',npf_res_c
	do I=1,npf_res_c
	read(49,*)pfres_c(i)
	if(kpr.eq.1)print *,' i pfres(i)',i,pfres_c(i)
      end do
      
	read(49,*)
	if(kpr.eq.1)print *,' Vessel'
	read(49,*)ncam_c
	if(kpr.eq.1)print *,'ncam ',ncam_c
	do I=1,ncam_c
	read(49,*)
	read(49,*)ndl_ves_c(i),ndh_ves_c(i),nt_ves_c(i),n_ves_num_c(i)
c
	if(kpr.eq.1)PRINT*,'i N M nt ves_n',i,Ndl_ves_c(I),
     *  ndh_ves_c(i),nt_ves_c(i),n_ves_num_c(i)
	read(49,*)Rc_c(I),Zc_c(I),dl_c(i),hl_c(i),alpha_ves_c(i),beta_ves_c(i)
	if(kpr.eq.1)print *,'r_c z_c dr dz alpha beta ',
     * rc_c(i),zc_c(i),dl_c(i),hl_c(i),alpha_ves_c(i),beta_ves_c(i)
	END DO


	read(49,*)
	if(kpr.eq.1)print *,' res_ves'
	read(49,*)ncam_c
	if(kpr.eq.1)print *,'ncam ',ncam_c
	do I=1,ncam_c
	read(49,*)rcam_c(i)
	if(kpr.eq.1)print *,' i rcam(i)',i,rcam_c(i)
      end do


	read(49,*)
	if(kpr.eq.1)print *,' Flux loops'
	read(49,*)kloop_c
	if(kpr.eq.1)print *,'kloop ',kloop_c
	do I=1,kloop_c

	read(49,*)Rl_c(I),Zl_c(I)
	if(kpr.eq.1)print *,'r_l z_l ',rl_c(i),zl_c(i)
	END DO


	read(49,*)
	if(kpr.eq.1)print *,' Probe'
	read(49,*)kprobe_c,kpb_c
	if(kpr.eq.1)print *,'kprobe,kpb ',kprobe_c,kpb_c
	do I=1,kprobe_c
	read(49,*)R_prob_c(I),Z_prob_c(I),anglep_c(i),smp_c(i)
	if(kpr.eq.1)print *,'r_pr z_pr alpha smp ',
     * R_prob_c(I),Z_prob_c(I),anglep_c(i),smp_c(i)
	END DO

	read(49,*)
	if(kpr.eq.1)print *,' limiter'
	read(49,*)ke_c
	if(kpr.eq.1)print *,'ke ',ke_c
	do I=1,ke_c

	read(49,*)xu_c(I),yu_c(I)
	if(kpr.eq.1)print *,'xu yu ',xu_c(I),yu_c(I)
	END DO

      read(49,*)    
	read(49,*)r00_c,rk_c
      read(49,*)z00_c,zk_c
	if(kpr.eq.1)print *,'r00,rk ',r00_c,rk_c
	if(kpr.eq.1)print *,'z00,zk ',z00_c,zk_c


        return
        end


        subroutine dina_data_read()
	include 'double.inc'
c-----------------------------------------
c	implicit real*8 (a-h,o-z)
	include 'parf1'
 	include 'parf_mike' 
        common
     *  /ge5/kpr
	common                                                                 
     *	/n_m/n,m,mp                                                      




      common /c_tokamak_config1/
     * npf_c,
     * npf_res_c,
     * ncam_c,
     * kloop_c,
     * kprobe_c,kpb_c,
     * ke_c

      common /c_tokamak_config2/
     * nr_c(mu),nz_c(mu),nt_c(mu),n_pf_num_c(mu),
     * R_c_c(mu),Z_c_c(mu),dr_c(mu),dz_c(mu),alpha_c(mu),beta_c(mu),
     * pfres_c(mu),
     * ndl_ves_c(mu),ndh_ves_c(mu),nt_ves_c(mu),n_ves_num_c(mu),
     * Rc_c(mu),Zc_c(mu),dl_c(mu),hl_c(mu),alpha_ves_c(mu),
     * beta_ves_c(mu),
     * rcam_c(mu),
     * Rl_c(mu),Zl_c(mu),
     * R_prob_c(mu),Z_prob_c(mu),anglep_c(mu),smp_c(mu),
     * xu_c(mu),yu_c(mu),
     * r00_c,rk_c,
     * z00_c,zk_c



      common /c_k_jetto/ih_imas_c
      common /c_time_eq/time_eq_c

      common /c_jetto_ids/pulse_c,run_c
      
      common /c_kpr/kpr_c

      common /c_for002_kav/tay_c,rs0_c,bt0_c,key_t11_c
      common /c_for002_kav2/n_c

      common /c_gaps_data_ramp/x_gaps_c(mu),y_gaps_c(mu),n_ga_c

      common /c_tran_times/tt_dina_c

      common /c_pfres/t_t_c1(ntime),pf_t_c1(kf,ntime),n_t_c1,npf_c1


      common /c_ech_c2/t_t_c2(ntime),udd_sol_t_c2(ntime),n_t_c2

      common /c_nd_c3/t_t_c3(ntime),pn_d_t_c3(ntime),n_t_c3


      common /c_gamma_z_c4/t_t_c4(ntime),pn_d_t_c4(ntime),
     *  n_t_c4,nz_imp_c4

      common /c_gamma_z2_c5/t_t_c5(ntime),pn_d_t_c5(ntime),
     *  n_t_c5,nz_imp2_c5

      common /c_init_c6/p_c6,T_e_c6,T_i_c6,gam_c6,g_gain_c6


      common /c_emo_c7/t_t_c7(ntime),emoe_t_c7(ntime),emoq_t_c7(ntime),
     *  n_t_c7

      common /c_dens_c8/t_t_c8(ntime),den_t_c8(ntime),n_t_c8

      common /c_gamma_z1_c9/t_t_c9(ntime),pn_d_t_c9(ntime),
     *  n_t_c9,nz_imp1_c9

      common /c_gamma_z3_c10/t_t_c10(ntime),pn_d_t_c10(ntime),
     *  n_t_c10,nz_imp3_c10

      common /c_gamma_z4_c11/t_t_c11(ntime),pn_d_t_c11(ntime),
     *  n_t_c11,nz_imp4_c11



      common /c_bohm_gbohm_c12/k_Bohm_c12
      common /c_tay_simul_c13/tay_simul_c13
      common /c_dw_c14/tay_dw_c14
      common /c_pcchp_end_c15/pcchp_end_c15
      common /c_ext_c16/k_ener_ext_c16,k_dens_ext_c16,k_ajb_ext_c16

      common /c_tt_kavin2_c1/tt_rampup_c1,dt_end_sim_c1,
     * dtpl_term_l_c1,cIp_end_c1,CS1_eob_c1,rms_noise_c1
     
     
     
        open(unit=49,file='dina_data.dat',
     *  form='formatted')


! 		 open (unit=41,file='k_jetto.dat',form='formatted') 
       read (49,*) 
       read (49,*)ih_imas_c
          
! 		 open (unit=40,file='time_eq.dat',form='formatted') 
        read (49,*) 
        read (49,*)time_eq_c
          
!        open(unit=2,file='jetto_ids.dat',form='formatted',action='read')
        read(49,*)
        read(49,*) pulse_c
        read(49,*)
        read(49,*) run_c

!        open (unit=1,file='kpr.dat',form='formatted')

        read (49,*)
        read (49,*)kpr_c

!     	open(unit=2,file='for002_kav',form='formatted')

	read (49,*)
	read (49,*)tay_c,rs0_c,key_t11_c,bt0_c

!	open(unit=40,status='old',file='gaps_data_ramp',form='formatted')
	read (49,*)
	read (49,*)n_ga_c
	read (49,*)
	read (49,*)(x_gaps_c(i),i=1,n_ga_c)
	read (49,*)
	read (49,*)(y_gaps_c(i),i=1,n_ga_c)

!        open (unit=1,file='tran_times.dat',form='formatted')
        read (49,*)
        read (49,*)tt_dina_c

!           open (unit=41,file='pfres.dat',form='formatted') 
           read (49,*) 
           read (49,*)n_t_c1 

           read (49,*) 

          npf_c1=npf_res_c
           do i=1,n_t_c1 
              read (49,*)t_t_c1(i),(pf_t_c1(k,i),k=1,npf_c1)
           end do 

!           open (unit=41,file='ech.dat',form='formatted') 
           read (49,*) 
           read (49,*)n_t_c2 
           read (49,*) 


           do i=1,n_t_c2 
              read (49,*)t_t_c2(i),udd_sol_t_c2(i)
           end do 

!           open (unit=41,file='n_d.dat',form='formatted') 
           read (49,*) 
           read (49,*)n_t_c3 
           read (49,*) 
           
           
           do i=1,n_t_c3 
              read (49,*)t_t_c3(i),pn_d_t_c3(i)
           end do 

!           open (unit=41,file='gamma_z.dat',form='formatted') 
           read (49,*) 
           read (49,*)n_t_c4,nz_imp_c4 
           read (49,*) 
           
           do i=1,n_t_c4 
              read (49,*)t_t_c4(i),pn_d_t_c4(i)
           end do 

!           open (unit=41,file='gamma_z2.dat',form='formatted') 
           read (49,*) 
           read (49,*)n_t_c5,nz_imp2_c5 
           read (49,*) 
           
           do i=1,n_t_c5 
              read (49,*)t_t_c5(i),pn_d_t_c5(i)
           end do 

!	open (unit=41,file='init.dat',form='formatted')
        read (49,*)p_c6
        read (49,*)T_e_c6
        read (49,*)T_i_c6
        read (49,*)gam_c6
        read (49,*)g_gain_c6

!           open (unit=41,file='emo.dat',form='formatted') 
           read (49,*) 
           read (49,*)n_t_c7 
           
           read (49,*) 
           do i=1,n_t_c7 
              read (49,*)t_t_c7(i),emoe_t_c7(i),emoq_t_c7(i)
           end do 

!           open (unit=41,file='dens.dat',form='formatted') 
           read (49,*) 
           read (49,*)n_t_c8 
           read (49,*) 

           do i=1,n_t_c8 
              read (49,*)t_t_c8(i),den_t_c8(i)
           end do 



!           open (unit=41,file='gamma_z1.dat',form='formatted') 
           read (49,*) 
           read (49,*)n_t_c9,nz_imp1_c9 
           read (49,*) 
           
           do i=1,n_t_c9 
              read (49,*)t_t_c9(i),pn_d_t_c9(i)
           end do 
           
!           open (unit=41,file='gamma_z3.dat',form='formatted') 
           read (49,*) 
           read (49,*)n_t_c10,nz_imp3_c10 
           read (49,*) 
           
           do i=1,n_t_c10 
              read (49,*)t_t_c10(i),pn_d_t_c10(i)
           end do 
!           open (unit=41,file='gamma_z4.dat',form='formatted') 
           read (49,*) 
           read (49,*)n_t_c11,nz_imp4_c11 
           read (49,*) 
           
           do i=1,n_t_c11 
              read (49,*)t_t_c11(i),pn_d_t_c11(i)
           end do 

!                 open (unit=41,file='bohm_gbohm.dat',form='formatted')
                read (49,*)
                read (49,*) k_Bohm_c12
!           open (unit=41,file='tay_simul.dat',form='formatted') 
           read (49,*) 
           read (49,*)tay_simul_c13

!          open (unit=40,file='dw.dat',form='formatted') 
          read (49,*) 
!          read (40,*)tt_dw,tay_dw
          read (49,*)tay_dw_c14

!           open (unit=40,file='pcchp_end.dat',form='formatted') 
        read (49,*)
        read (49,*)pcchp_end_c15

          read (49,*) 
          read (49,*)k_ener_ext_c16, k_dens_ext_c16,k_ajb_ext_c16

!          open (unit=40,file='tt_kavin2.dat',form='formatted') 
          read (49,*) 
          read (49,*)tt_rampup
          read (49,*) 
          read (49,*)dt_end_sim,dtpl_term_l,cIp_end
          
          tt_rampup_c1=tt_rampup
          dt_end_sim_c1=dt_end_sim
          dtpl_term_l_c1=dtpl_term_l
          cIp_end_c1=cIp_end

          dtpl_term_h=0
          
          read (49,*) 
          read (49,*)CS1_eob,rms_noise


          CS1_eob_c1=CS1_eob
          rms_noise_c1=rms_noise
          

	close(49)

2	FORMAT(/,2(2x,1PE10.3))


71 	format (20x,a6/,(6(1pe10.3)))
      RETURN
      END
      
      
      
	subroutine general_data_read()
c------------------------------------
c  read PF coil currents
c----------------------------------
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	include 'parf1'
        COMMON
     *  /pf1/npf,pf(kf),pf0(kf)
        common
     *  /ge5/kpr
	CHARACTER*120 fshot,tmp
	dimension a(190)

      common /c_scr_data_c1/pf_c1(kf)
      
      

      kpr_help=kpr
      kpr=1
      npf_2=13
      
	if(kpr.eq.1)PRINT*,'Open scr_data from TOK'
      open (unit=39,file='scr_data.dat',form='formatted')

!      read (39,*)
!      read (39,*)nn
      read (39,*)
      read (39,*)(a(i),i=1,npf_2)
c
	do i=1,11
          pf(i)=a(2+i)*1.e3
	  pf0(i)=pf(i)
          pf_c1(i)=pf(i)

	end do
c
      if(kpr.eq.1)print *,' nn npf=npf_2',nn,npf,npf_2
      
	if(kpr.eq.1)PRINT*,'CURRENTS'
	if(kpr.eq.1)PRINT 7,(Pf(i),i=1,11)
	if(kpr.eq.1)PRINT 7,(Pf_c1(i),i=1,11)
7 	format (20(1p,E14.6))


      kpr=kpr_help
	 close(39)

         return

5000    format (8(1pe14.6))
71 	format (20x,a6/,(8(1pe10.3)))

	RETURN
	END