!> reading tokamak config from dat file



        subroutine tokamakdata_read_1()
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
