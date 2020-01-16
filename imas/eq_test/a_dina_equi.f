       subroutine dina_input(tt_xx,tpl_xx, n_xx,pstab_xx, pptab_xx,fptab_xx, 
     *  ncam_xx,tcam_xx, npf_xx,pf_xx)
     
      include 'double.inc'
      include 'new_com.inc'
      
                  
      dimension pstab_xx(*),pptab_xx(*),fptab_xx(*),tcam_xx(*),pf_xx(*)
      
      n = n_xx
      nutab = n_xx
      ncam = ncam_xx
      npf = npf_xx
      tt = tt_xx
      tpl = tpl_xx
      
      do i=1,nutab
        pstab(i) = pstab_xx(i)
        pptab(i) = pptab_xx(i)
        fptab(i) = fptab_xx(i)
      end do      
      
      do i=1,ncam
        tcam(i) = tcam_xx(i)   
      enddo
      do i=1,npf
         pf(i) = pf_xx(i)
      enddo
      
      
      
      
      do i=1,n
        ppx(i)=pptab(i)
        pffx(i)=fptab(i)
      end do      
      
      do i=1,nutab
        a(i) = pstab(i)
      end do
      
      return
      end



	subroutine dina_outp(n_xx,
     * tpl_xx,uli_xx,v_xx,parea_xx,psi_ax_xx,rmag_xx,zmag_xx,
     * q_ax_xx,q_95_xx,rs0_xx,bt0_xx,wen2_xx,tt_xx,
     * ai_xx,te0_xx,tq0_xx,pne_xx,tok1_xx,q_xx,
     * x_xx,y_xx,psi_xx,psi_bnd_xx,curr_d_xx,
     * xbound_xx,ybound_xx,rmajor_xx,rminor_xx,elong_xx,tri_xx,
     * pd0_xx,pt0_xx,sigk_xx,ajb_xx,aj0_xx,qe0_xx,qq0_xx,
     * betap_xx,betat_xx,tec_xx,tqc_xx,pec_xx,pic_xx,zeff_xx,vloop_xx,
     * tene_xx,wfus_xx,emag_xx,
     * vchopper_xx,pf_xx,tcam_xx,
     * pptab_xx,fptab_xx)


	include 'double.inc'
	include 'new_com.inc'

        common /c_imas_curr_d/curr_d(nr,nz)

	dimension ai_xx(*),te0_xx(*),tq0_xx(*),pne_xx(*),tok1_xx(*),
     *  q_xx(*),x_xx(*),y_xx(*)
	dimension pd0_xx(*),pt0_xx(*),sigk_xx(*),ajb_xx(*),
     *  aj0_xx(*),qe0_xx(*),qq0_xx(*)
     
	dimension psi_xx(nr,nz),curr_d_xx(nr,nz)
        dimension xbound_xx(*),ybound_xx(*)
        dimension vchopper_xx(*),pf_xx(*),tcam_xx(*)
        dimension pptab_xx(*),fptab_xx(*)


      n_xx=n

!	pi=3.14159
	
	tpl_xx=tpl*1000.d0
	
!	print *,' n_xx tpl_xx=',n_xx,tpl_xx
	
!	return
	
	uli_xx=uli
	v_xx=volume
	parea_xx=surface
	psi_ax_xx=pmag*1.d-5*2.*pi
	psi_bnd_xx=pbound*1.d-5*2.*pi
	rmag_xx=rmag/100.d0
	zmag_xx=zmag/100.d0
	q_ax_xx=q(2)
        q_95_xx=q_95
	rs0_xx=rs0/100.d0
	bt0_xx=bt0/10.d0
	wen2_xx=wen2*1.d6
	tt_xx=tt/1000.d0

        betap_xx = betj
        betat_xx = bett

	emag_xx = emag*1.d6

        rmajor_xx = rout/100.d0
        rminor_xx = eu/100.d0
        elong_xx = elong
        tri_xx = tri

        do i=1,ntet
           xbound_xx(i) = xbound(i)*1.d-2
           ybound_xx(i) = ybound(i)*1.d-2
        end do
c=================================================

	do i=1,n
	   ai_xx(i)=ai(i)

	   tok1_xx(i)=tok1(i)*1.d7
	   q_xx(i)=q(i)

	end do
	

c=================================================

	do i=1,nr
	   x_xx(i)=x(i)/100.d0
	end do

	do i=1,nz
	   y_xx(i)=y(i)/100.d0
	end do


	do i=1,nr
	   do j=1,nz
	      psi_xx(i,j)=psi(i,j)*1.d-5*2.*pi

	   end do
	end do


    
      return
      end



	subroutine dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3)

      include 'double.inc'
	include 'new_com.inc'                                                  

      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*),c_output3(*)

      parameter (kint=300)

	dimension pf_xx(kint),gaps_xx(kint),tcam_xx(kint)

	dimension vchopper_x2(kint),shape_out(kint)

	character *30 apr                                                      
	dimension a_print(300)

	common /c_data_in_time2/i_c_data,i_c_data1       

      common /c_imas_is/ih_imas

!-----------------------------------  inputs---
!     *  vchopper_x2,tpl_x2,tt_dw_x2)

	
      i_en=i_en+1
      
      if(i_en.eq.1.and.kpr.eq.1)then
!           Iopen=0
!      call OpenCloseConsole(Iopen) 
      end if

      if(i_en.gt.2)then

        tpl_x2=c_input1(1)      
        tt_dw_x2=c_input1(2)   
        
        if(kpr.eq.1)print *,'   tpl_x2==',tpl_x2 
      
        do i=1,npf
        vchopper_x2(i)=c_input2(i)
        end do


      call get_contr_signals(vchopper_x2,tpl_x2,tt_dw_x2)
      end if
      
      
      print *,' kpr==',kpr
      
      omega=1.d0
 	call equil()

	ntay=ntay+1
	tt=tt+tay

	if(kpr.eq.1)print*,'!!!tt tay ntay',tt,tay,ntay

	if(kpr.eq.1)print*,'@@@@@from main  next k_jetto',next,k_jetto

	if(kpr.eq.1)print*,'put_signals'

	  call put_dina_signals(z_cur_xx,elong_xx,xleft_xx,
     *  xright_xx,tpl_xx,tt_xx,
     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
     *  ntay_xx,ncam_xx,zvel_xx,tcam_xx,rsep_xx,klim_xx,
     *  zsep_xx,i_wr_xx)

!------------------------------------outputs
!     *  z_cur_xx,elong_xx,xleft_xx,
!     *  xright_xx,tpl_xx,tt_xx,
!     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
!     *  ntay_xx,next_xx,zvel_xx,pf_turns_xx,rsep_xx,klim_xx,
!     *  t_end_xx,i_wr_xx,

        c_output1(1)=z_cur_xx
        c_output1(2)=zvel_xx
        c_output1(3)=elong_xx
        c_output1(4)=tpl_xx
        c_output1(5)=klim_xx
        c_output1(6)=xleft_xx
        c_output1(7)=xright_xx
        c_output1(8)=rsep_xx
        c_output1(9)=tt_xx
        c_output1(10)=zsep_xx

        c_output1(11)=npf_xx
        c_output1(12)=n_gaps_xx
        c_output1(13)=ntay_xx
        c_output1(14)=ncam_xx
        c_output1(15)=i_wr_xx


      kk=0
      do i=1,n_gaps_xx
      kk=kk+1
      c_output2(kk)=gaps_xx(i)
      end do
      do i=1,npf_xx
      kk=kk+1
      c_output2(kk)=pf_xx(i)
      end do
      do i=1,ncam_xx
      kk=kk+1
      c_output2(kk)=tcam_xx(i)
     	a_print(i)=tcam_xx(i)
      end do

	n_pr=ncam_xx

	apr='tcam_xx'

	num=10

!	call out42(n_pr,a_print,num,apr)


     	a_print(1)=ncam_xx
     	a_print(2)=kk

	n_pr=2

	apr='ncam_xx kk '

	num=10

!	call out42(n_pr,a_print,num,apr)

c----------------------



                                                                        

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

!	shape_out(8)=shafra(1)                                                  

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


      shape_out(23)=tt      !  q at R,Z location o ECCD 

!!!	shape_out(24)=p_turb                                                
	shape_out(24)=ratio_imp                                                

	k_out_dina=24

	shape_out(25)=rsep                                                
	shape_out(26)=zsep 

	k_out_dina=26

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
	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)

	a_print(1)=vs_ext
	a_print(2)=vs_tot
	a_print(3)=vs_ext+vs_pl
	a_print(4)=tt
	n_pr=4

	apr='vs_ext vs_t vs_t1 tt '
	num=30
	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)


       do i=1,k_out_dina
       c_output3(i)=shape_out(i)
       end do


	a_print(1)=k_out_dina
	a_print(2)=tt
	n_pr=2

	apr='k_out_dina tt '
	num=15
	if(kpr.eq.3.or.kpr.eq.1)call out42(n_pr,a_print,num,apr)

      

      if(tt.gt.1900.e3)then 
      
      if(kpr.eq.1)print *,' tt STOP',tt
      	
      stop
      end if
      

      return  	 
      END
	subroutine put_dina_signals(z_cur_xx,elong_xx,xleft_xx,
     *  xright_xx,tpl_xx,tt_xx,
     *  npf_xx,pf_xx,n_gaps_xx,gaps_xx,
     *  ntay_xx,ncam_xx,zvel_xx,tcam_xx,rsep_xx,klim_xx,
     *  zsep_xx,i_wr_xx)
     
      include 'double.inc'
	include 'new_com.inc'                                                  

	dimension pf_xx(*),gaps_xx(*),tcam_xx(*)

	character*70 apr

71	format(20x,a6/,(6(1pe10.3)))

 !     kpr=1

c------------
      i_wr_xx=i_wr
      klim_xx=klim
      zsep_xx=zsep
      
      if(kpr.eq.1)print*,'klim zsep ',klim,zsep
      
      rsep_xx=rsep*1.d-2
!!!      zvel_xx=zvel
      zvel_xx=zmag*1.d-2
      if(kpr.eq.1)print*,'rsep zvel ',rsep,zvel
      
      z_cur_xx=z_cur*1.d-2
      elong_xx=elong
      if(kpr.eq.1)print*,'z_cur elong ',z_cur,elong

      xleft_xx=xleft*1.d-2
      xright_xx=xright*1.d-2

      if(kpr.eq.1)print*,'xleft xright ',xleft,xright

      if(n_ga.eq.0)n_ga=6
      
      n_gaps=n_ga
      n_gaps_xx=n_gaps
      
      tpl_xx=tpl*1.d+3      
      tt_xx=tt
      if(kpr.eq.1)print*,'tt tpl',tt,tpl 
    
      npf_xx=npf
      if(kpr.eq.1)print*,'npf n_ga',npf,n_ga

       ntay_xx=ntay
       ncam_xx=ncam

      if(kpr.eq.1)print*,'ntay ncam i_wr',ntay,ncam,i_wr

      do i=1,n_gaps
      gaps_xx(i)=gaps(i)*1.d-2
!        if(kpr.eq.1)print *,' i gaps-',i,gaps(i)
      end do
       
      do i=1,npf
        pf_xx(i)=pf(i)*1.d+3
!        if(kpr.eq.1)print *,' i pf pf_turns-',i,pf(i),pf_turns(i)
      end do

      do i=1,ncam
        tcam_xx(i)=tcam(i)*1.d+3
!        if(kpr.eq.1)print *,' i pf pf_turns-',i,pf(i),pf_turns(i)
      end do



 1000 continue
 5000 format (50(1pe14.5))

	return
      end
	subroutine get_contr_signals(vchopper_xx,tpl_xx,tt_dw_xx)

      include 'double.inc'
	include 'new_com.inc'                                                  

	dimension vchopper_xx(*)
     
      do i=1,npf
        vchopper(i)=vchopper_xx(i)
      end do

!      tpl=tpl_xx
!      tt_dw=tt_dw_xx

      
      
 1000 continue
 5000 format (50(1pe14.5))

      if(kpr.eq.1)print*,'END of reading contr_signals'

	return
      end

