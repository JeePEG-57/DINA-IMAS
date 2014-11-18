
c  MATLAB common blocks...

	common
     *	/mat_efit0/kefit_mat
     *	/mat_efit1/alfax_mat(2),betax_mat(2)
     *	/mat_efit2/alfa0_mat,beta_mat,alfa1_mat
     *	/mat_efit3/pw_1_mat,pw_2_mat

     *	/mat_efit4/rmag_mat,zmag_mat,rs0_mat,bt0_mat
     *	/mat_efit5/tpl_mat,tay_mat

     *	/mat_efit6/te_mat


c  Energy commons

        common /c_ener1/tene_e

        common /c_ener3/diff_ext(npo),dxe_ext(npo),
     *  dxq_ext(npo),ajb_ext(npo),psin_ext(npo),
     *  vd_ext(npo)

        common /c_ener4/key_ext
        common /c_ener5/tene,ptot_dop
        common /c_ener6/vd_bound,v_ext
        common /c_ener7/ext_transp(npo)
        common /c_ener8/x_e_neo(npo),x_i_neo(npo)
        common /c_ener9/ft(npo)

        common /c_ener10/power_el,pow_el,ro_el,del_el
        common /c_ener11/power_ion,pow_ion,ro_ion,del_ion
        common /c_ener12/p_e(npo),p_i(npo),
     *  aj_cd(npo),pne_ext(npo)
        common /c_ener13/te_ext(npo),ti_ext(npo)
        common /c_ener14/sigma_ext(npo)
        common /c_ener15/p_ext(npo)

        common /c_ener16/qe0_ext(npo),qq0_ext(npo),
     *  del_ext(npo)
        common /c_ener17/sigk_ext(npo)

