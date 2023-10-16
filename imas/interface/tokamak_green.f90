!> reading tokamak config from IMAS ids's 




subroutine tokamakdata_read_ids(pf_active, pf_passive, magnetics)

    use ids_schemas
    use ids_routines
    !implicit none
    include 'double.inc'

    
    type (ids_pf_active), INTENT(IN)   :: pf_active
    type (ids_pf_passive), INTENT(IN)  :: pf_passive
    type (ids_magnetics), INTENT(IN)   :: magnetics


	include 'parf1'
 	include 'parf_mike'


    common &
     &  /ge5/kpr
	common &                                                           
     &	/n_m/n,m,mp                                                      

    common /c_tokamak_config1/&
     & npf_c,&
     & npf_res_c,&
     & ncam_c,&
     & kloop_c,&
     & kprobe_c,kpb_c,&
     & ke_c

    common /c_tokamak_config2/&
     & nr_c(mu),nz_c(mu),nt_c(mu),n_pf_num_c(mu),&
     & R_c_c(mu),Z_c_c(mu),dr_c(mu),dz_c(mu),alpha_c(mu),beta_c(mu),&
     & pfres_c(mu),&
     & ndl_ves_c(mu),ndh_ves_c(mu),nt_ves_c(mu),n_ves_num_c(mu),&
     & Rc_c(mu),Zc_c(mu),dl_c(mu),hl_c(mu),alpha_ves_c(mu),&
     & beta_ves_c(mu),&
     & rcam_c(mu),&
     & Rl_c(mu),Zl_c(mu),&
     & R_prob_c(mu),Z_prob_c(mu),anglep_c(mu),smp_c(mu),&
     & xu_c(mu),yu_c(mu),&
     & r00_c,rk_c,&
     & z00_c,zk_c
    
     real*8, parameter:: PI2 = 1.57079632679490d0
      

    !open(unit=49,file='tokamak_config.dat',  form='formatted')
	if(kpr.eq.1)print *,'Reading tokamakdata from IDS'
	!read(49,*)
	if(kpr.eq.1)print *,' 1'
    flush(6)
    
	!read(49,*)npf_c
    !npf_c = size(pf_active%coil)
    ncoil = size(pf_active%coil)
    ncoil = 14
    i = 0
	do ic=1,ncoil
        ! Name of the coil
	    !read(49,*)

        nelem = size(pf_active%coil(ic)%element)
        do ie=1,nelem
            i = i + 1

            nr_c(i) = 20 
            nz_c(i) = 20 
            if (pf_active%coil(ic)%element(ie)%turns_with_sign.gt.0) then
                nt_c(i) = 1
            else
                nt_c(i) = -1
            endif
            n_pf_num_c(i) = ic
            !read(49,*)nr_c(i),nz_c(i),nt_c(i),n_pf_num_c(i)
            if(kpr.eq.1)PRINT*,'i Nr Nz nt pf_num',i,Nr_c(I),nz_c(i),nt_c(i),n_pf_num_c(i)
            if (pf_active%coil(ic)%element(ie)%geometry%geometry_type.eq.2) then
                ! Rectangle
                R_c_c(i) = pf_active%coil(ic)%element(ie)%geometry%rectangle%r
                Z_c_c(i) = pf_active%coil(ic)%element(ie)%geometry%rectangle%z
                dr_c(i) = pf_active%coil(ic)%element(ie)%geometry%rectangle%width
                dz_c(i) = pf_active%coil(ic)%element(ie)%geometry%rectangle%height
                alpha_c(i) = PI2
                beta_c(i) = 0.d0
            elseif (pf_active%coil(ic)%element(ie)%geometry%geometry_type.eq.3) then
                ! Oblique
                alpha = PI2 + pf_active%coil(ic)%element(ie)%geometry%oblique%beta
                beta = pf_active%coil(ic)%element(ie)%geometry%oblique%alpha
                dlength = pf_active%coil(ic)%element(ie)%geometry%oblique%length_alpha
                dheight = pf_active%coil(ic)%element(ie)%geometry%oblique%length_beta
                
                R_c_c(i) = pf_active%coil(ic)%element(ie)%geometry%oblique%r &
                & + 0.5d0*(dlength*cos(beta) + dheight*cos(alpha))
                Z_c_c(i) = pf_active%coil(ic)%element(ie)%geometry%oblique%z &
                & + 0.5d0*(dlenght*sin(beta) + dheight*sin(alpha))
                dr_c(i) = dlength
                dz_c(i) = dheight
                alpha_c(i) = alpha
                beta_c(i) = beta
            elseif (pf_active%coil(ic)%element(ie)%geometry%geometry_type.eq.5) then
                ! Annulus
                R_c_c(i) = pf_active%coil(ic)%element(ie)%geometry%annulus%r
                Z_c_c(i) = pf_active%coil(ic)%element(ie)%geometry%annulus%z
                dr_c(i) = pf_active%coil(ic)%element(ie)%geometry%annulus%radius_outer*2.d0
                dz_c(i) = pf_active%coil(ic)%element(ie)%geometry%annulus%radius_outer*2.d0
                alpha_c(i) = PI2
                beta_c(i) = 0.d0
            else
                print *,'Unsupported geometry type =', pf_active%coil(ic)%element(ie)%geometry%geometry_type, ' for coil, element= ', ic, ie
            endif
            !read(49,*)R_c_c(I),Z_c_c(I),dr_c(i),dz_c(i),alpha_c(i),beta_c(i)
            if(kpr.eq.1)print *,'r_c z_c dr dz alpha beta ', r_c_c(i),z_c_c(i),dr_c(i),dz_c(i),alpha_c(i),beta_c(i)
        enddo

	END DO
    npf_c = i
    if(kpr.eq.1)print *,'npf ',npf_c

	!read(49,*)
	if(kpr.eq.1)print *,' res_pf'
	!read(49,*)npf_res_c
    npf_res_c = ncoil
	if(kpr.eq.1)print *,'npf_res ',npf_res_c
	do I=1,npf_res_c
        !read(49,*)pfres_c(i)
        pfres_c(i) = 0.d0
        if(kpr.eq.1)print *,' i pfres(i)',i,pfres_c(i)
    end do
      
    
	!read(49,*)
	if(kpr.eq.1)print *,' Vessel'
	!read(49,*)ncam_c
    ncam_c = size(pf_passive%loop)
	if(kpr.eq.1)print *,'ncam ',ncam_c
	do i=1,ncam_c
        !Name of the loop
        !read(49,*)
        !read(49,*)ndl_ves_c(i),ndh_ves_c(i),nt_ves_c(i),n_ves_num_c(i)
        ndl_ves_c(i) = 1
        ndh_ves_c(i) = 5
        nt_ves_c(i) = 1
        n_ves_num_c(i) = i
        if(kpr.eq.1)PRINT*,'i N M nt ves_n',i,Ndl_ves_c(I),ndh_ves_c(i),nt_ves_c(i),n_ves_num_c(i)

        !read(49,*)Rc_c(I),Zc_c(I),dl_c(i),hl_c(i),alpha_ves_c(i),beta_ves_c(i)
        if (pf_passive%loop(i)%element(1)%geometry%geometry_type.eq.2) then
            ! Rectangle
            Rc_c(i) = pf_passive%loop(i)%element(1)%geometry%rectangle%r
            Zc_c(I) = pf_passive%loop(i)%element(1)%geometry%rectangle%z
            dl_c(i) = pf_passive%loop(i)%element(1)%geometry%rectangle%width
            hl_c(i) = pf_passive%loop(i)%element(1)%geometry%rectangle%height
            alpha_ves_c(i) = PI2
            beta_ves_c(i) = 0.d0
        elseif (pf_passive%loop(i)%element(1)%geometry%geometry_type.eq.3) then
            ! Oblique
            alpha = PI2 + pf_passive%loop(i)%element(1)%geometry%oblique%beta
            beta = pf_passive%loop(i)%element(1)%geometry%oblique%alpha
            dlength = pf_passive%loop(i)%element(1)%geometry%oblique%length_alpha
            dheight = pf_passive%loop(i)%element(1)%geometry%oblique%length_beta
            Rc_c(i) = pf_passive%loop(i)%element(1)%geometry%oblique%r &
            & + 0.5d0*(dlength*cos(beta) + dheight*cos(alpha))
            Zc_c(I) = pf_passive%loop(i)%element(1)%geometry%oblique%z &
            & + 0.5d0*(dlenght*sin(beta) + dheight*sin(alpha))
            dl_c(i) = dlength
            hl_c(i) = dheight
            alpha_ves_c(i) = alpha
            beta_ves_c(i) = beta
        else
            print *,'Unsupported geometry type =', pf_passive%loop(i)%element(1)%geometry%geometry_type, ' for loop ', i
        endif
        if(kpr.eq.1)print *,'r_c z_c dr dz alpha beta ', rc_c(i),zc_c(i),dl_c(i),hl_c(i),alpha_ves_c(i),beta_ves_c(i)
	END DO


	!read(49,*)
	if(kpr.eq.1)print *,' res_ves'
	!read(49,*)ncam_c
	if(kpr.eq.1)print *,'ncam ',ncam_c
	do I=1,ncam_c
	    !read(49,*)rcam_c(i)
        rcam_c(i) = 0.d0
	    if(kpr.eq.1)print *,' i rcam(i)',i,rcam_c(i)
    end do


	!read(49,*)
	if(kpr.eq.1)print *,' Flux loops'
	!read(49,*)kloop_c
    kloop_c = size(magnetics%flux_loop)
	if(kpr.eq.1)print *,'kloop ',kloop_c
	do I=1,kloop_c
        !read(49,*)Rl_c(I),Zl_c(I)
        Rl_c(I) = magnetics%flux_loop(i)%position(1)%r
        Zl_c(I) = magnetics%flux_loop(i)%position(1)%z
        if(kpr.eq.1)print *,'r_l z_l ',rl_c(i),zl_c(i)
	END DO


	!read(49,*)
	if(kpr.eq.1)print *,' Probe'
	!read(49,*)kprobe_c,kpb_c
    kprobe_c = size(magnetics%b_field_pol_probe)
    kpb_c = 3
	if(kpr.eq.1)print *,'kprobe,kpb ',kprobe_c,kpb_c
	do I=1,kprobe_c
        !read(49,*)R_prob_c(I),Z_prob_c(I),anglep_c(i),smp_c(i)
        R_prob_c(I) = magnetics%b_field_pol_probe(i)%position%r
        Z_prob_c(I) = magnetics%b_field_pol_probe(i)%position%z
        anglep_c(i) = -magnetics%b_field_pol_probe(i)%poloidal_angle
        smp_c(i) = magnetics%b_field_pol_probe(i)%length
        if(kpr.eq.1)print *,'r_pr z_pr alpha smp ', R_prob_c(I),Z_prob_c(I),anglep_c(i),smp_c(i)
	END DO

	!read(49,*)
	if(kpr.eq.1)print *,' limiter'
	!read(49,*)ke_c
    ke_c = 56
	if(kpr.eq.1)print *,'ke ',ke_c
	do I=1,ke_c
	    !read(49,*)xu_c(I),yu_c(I)
        xu_c(I) = 6.d0 + cos(i*6.d0/ke_c)
        yu_c(I) = 0.d0 + dsin(i*6.d0/ke_c)
	    if(kpr.eq.1)print *,'xu yu ',xu_c(I),yu_c(I)
	END DO

    ! Equilibrium 2D grid
    !read(49,*)    
	!read(49,*)r00_c,rk_c
    !read(49,*)z00_c,zk_c
    r00_c = 3.d0
    rk_c = 9.d0
    z00_c = -6.d0
    zk_c = 6.d0


	if(kpr.eq.1)print *,'r00,rk ',r00_c,rk_c
	if(kpr.eq.1)print *,'z00,zk ',z00_c,zk_c

    return
    end


! subroutine read_geometry(rc, zc, dlength, dheight, alpha, beta, geometry)
!
!     if (geometry%geometry_type.eq.2) then 
!         rc = geometry%rectangle%r
!         zc = geometry%rectangle%z
!         dlength = geometry%rectangle%width
!         dheight = geometry%rectangle%height
!         alpha = PI2
!         beta = 0.d0
!     elseif (geometry%geometry_type.eq.3) then
!         alpha = PI2 + geometry%oblique%beta
!         beta = geometry%oblique%alpha
!         dlength = geometry%oblique%length_alpha
!         dheight = geometry%oblique%length_beta
!         rc = geometry%oblique%r &
!         & + 0.5d0*(dlength*cos(beta) + dheight*cos(alpha))
!         zc = geometry%oblique%z &
!         & + 0.5d0*(dlenght*sin(beta) + dheight*sin(alpha))
!     else
!         print *,'Unsupported geometry type =', geometry%geometry_type, '
!     endif
!     return
! end
