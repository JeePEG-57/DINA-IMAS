      SUBROUTINE DOPP_in()
     	include 'double.inc'
	include 'new_com.inc'
	
	call DOPP_in_c(
     * tene_e,uact,key_ext,
     * tene,ptot_dop,vs_res,vs_ext,
     * betj,pf_turns,r_tok,z_tok,
     * rmag,xleft,xright,tec,tqc,pcch,pion,psi_pf,vs_pf,vs_tot,
     * zvconverter,u_kd,tpl)



	return
	end

      SUBROUTINE DOPP_in_c(
     * tene_e,uact,key_ext,
     * tene,ptot,vs_res,vs_ext,
     * betj,pf_turns,r_tok,z_tok,
     * rmag,xleft,xright,tec,tqc,pcch,pion,psi_pf,vs_pf,vs_tot,
     * zvconverter,u_kd,tpl)

    	include 'double.inc'
c-------------------------------------------------                      
c  calculate energy confinement time and print all values               
c-------------------------------------------------------                
c       implicit real*8 (a-h,o-z)                                       
c                                                                       
      include 'parf0'                                                   
      include 'parf1'                                                   
      include 'parf3'                                                   
      include 'parf8'                                                   
c                                                                       
      
	dimension pf_turns(kf),zvconverter(kf),gaps(kf),gaps0(kf),
     *  d_gaps(kf),u_1(kf),u_kd(kf),u_ffw(kf)

	dimension te0(npo),tq0(npo),q(npo)
	                                                                  
	common                                                                 
     */ge2/NTAY,TAY,TT                                                  
	common                                                                 
     */pf1/npf,pf(kf),pf0(kf)                                           
	common                                                                 
     *  /cont1/vchopper(kf),veps                                        

	character *10 mgr(iy),mt(iy)  

	common /c_data_in_time2/i_c_data,i_c_data1
     *  /vic_psi_av/psipl_av,psiext_av
     * /ge7/eu,rout,zout,elong

	                                         


	character *30 apr                                                      
	character *12 yy(iy)                                                   
	character *50 tmp                                                      
      dimension a_print(200)  
               
       dimension dNB_xx(24)
c                                                                       
4010    format(6e12.3)                                                  

	i_en=i_en+1
	if(i_en.eq.1)then

	s_plasma=0.

	xleft=rmag-0.5*eu
	xright=rmag+0.5*eu

      tec=1.e-2
      tqc=1.e-2
      pcch=1.e-5
      
      te0(1)=1.e-2
      tq0(1)=1.e-2
      
      zeff_a=0.
      
!      print *,' rmag,eu,xleft,xright',rmag,eu,xleft,xright

!      stop


	call vic_turn()

	do i=1,npf
	a_print(i)=pf_turns(i)
	end do

	n_pr=npf

	apr='pf_turns '
	num=30
	if(kpr.eq.1)call out42(n_pr,a_print,num,apr)

	end if

	i_c_data=2

	psi_pf=vs_pf
	pmag_out_1=vs_tot

      psiext_av=vs_ext
      
c******  Calculation of Ivs3, Uvs3, Ivs1, Uvs1

	 num_coils=12
c   Calculation of Ivs3 (in kA)
        Curr_vs3=pf(num_coils)/4.

c   Calculation of Uvs3 (in kV)
        U_vs3=u_kd(num_coils)*4.*1.e-3

c   Calculation of Ivs1 (in kA)
        Curr_vs1=-pf(7)/pf_turns(7)-pf(8)/pf_turns(8)+
     *            pf(9)/pf_turns(9)+pf(10)/pf_turns(10)

c   Calculation of Uvs1 (in kV)
        U_vs1=-u_kd(7)*pf_turns(7)*1.e-3

      eu_xx=eu
      rout_xx=rout
      rmag_xx=rmag
      
      eu=0.
      rout=0.
      rmag=0.
 
      p_hl=1.
      
       if(kpr.eq.1)print*,'eu_xx rmag_xx ',z_1,z_2,tec


c***********************************
      call write_data_in_time(
     *	tt,tpl,betpj,eu,uli,r_cur,z_cur,p_sep,wel,wio,eksk,
c     *	pcch,zeff_a,tec,te0(1),tqc,tq0(1),tene,zsep,c_e_old,c_e_new,
     *	pcch,zeff_a,tec,te0(1),tqc,tq0(1),tene,zsep,rsep,c_e_old,c_e_new,
c     *  rmag,gamma,vs,q_95,q(2),zvel*10.,psi_pf,pmag_out,uact,
     *  rmag,gamma,vs,q_95,q(2),zvel*10.,psi_pf,pmag_out_1,uact,
     *  pf(1)/pf_turns(1),pf(2)/pf_turns(2),pf(3)/pf_turns(3),
     *  pf(4)/pf_turns(4),pf(5)/pf_turns(5),
     *  pf(6)/pf_turns(6),pf(7)/pf_turns(7),pf(8)/pf_turns(8),
     *  pf(9)/pf_turns(9),pf(10)/pf_turns(10),pf(11)/pf_turns(11),
     *  pf(12)/pf_turns(12),
     *  zvconverter(1)*pf_turns(1)*1.e-3,
     *	zvconverter(2)*pf_turns(2)*1.e-3,
     *  zvconverter(3)*pf_turns(3)*1.e-3,
     *	zvconverter(4)*pf_turns(4)*1.e-3,
     *  zvconverter(5)*pf_turns(5)*1.e-3,
     *	zvconverter(6)*pf_turns(6)*1.e-3,
     *  zvconverter(7)*pf_turns(7)*1.e-3,
     *	zvconverter(8)*pf_turns(8)*1.e-3,
     *  zvconverter(9)*pf_turns(9)*1.e-3,
     *	zvconverter(10)*pf_turns(10)*1.e-3,
     *  zvconverter(11)*pf_turns(11)*1.e-3,
     *	U_vs1,U_vs3,Curr_vs1,Curr_vs3,
     *  r_lh,wdop,qtep,w_fusion,wae+waq,s_plasma_xx,p_sum,P_HL,zmag_xx,
     *  wtp,wtor,qc,w_imp,gfus,p_sep_tot,
     *  dist_min_xx,Rdist_min_xx,Zdist_min_xx,
     *  dNB_xx)
c     *  wdop,qtep,w_fusion,
c     *  pf(2)/1.e3,pf(6)/1.e3,pf(8)/1.e3,pf(9)/1.e3,pf(11)/1.e3,
c     *  volume,z_tok,tokc)

      eu=eu_xx
      rout=rout_xx
      rmag=rmag_xx


71 	FORMAT(20X,A6/,(12(1pE10.3)))                                       
72 	FORMAT(5X,A60/,(1x,6(1pE11.3)))                                     
		                                                          
                                                                        
        return                                                          
      END                                                               
                                                                        
                                                                        
                                                                        
      SUBROUTINE DOPP_kav()
     	include 'double.inc'
	include 'new_com.inc'
	
	call DOPP_kav_c(
     * tene_e,uact,key_ext,
     * tene,ptot_dop,vs_res,
     * betj,pf_turns,r_tok,z_tok,s_plasma,pion,zvconverter,u_kd,
     *  r_cur,z_cur,wdh,vs_start)



	return
	end

      SUBROUTINE DOPP_kav_c(
     * tene_e,uact,key_ext,
     * tene,ptot,vs_res,
     * betj,pf_turns,r_tok,z_tok,s_plasma,pion,zvconverter,u_kd,
     *  r_cur,z_cur,wdh,vs_start)

    	include 'double.inc'
c-------------------------------------------------                      
c  calculate energy confinement time and print all values               
c-------------------------------------------------------                
c       implicit real*8 (a-h,o-z)                                       
c                                                                       
      include 'parf0'                                                   
      include 'parf1'                                                   
      include 'parf3'                                                   
      include 'parf8'                                                   
c                                                                       
      
	dimension pf_turns(kf),zvconverter(kf),gaps(kf),gaps0(kf),
     *  d_gaps(kf),u_1(kf),u_kd(kf),u_ffw(kf)
	                                                                  
      common                                                            
     *  /eq15e/pll0,tpl0,udd                                            
      common                                                            
     *  /en9e/volt(npo)                                                 
                                                                        
c        common                                                          
c     *  /abcdx/x(kf_c),x0(kf_c),gaps0(kf_c),d_gaps(kf_c)                
	common                                                                 
     *  /dop1/volt_sum,volt_tot(kf),volt_pl(kf),volt_ves(kf)            
	common                                                                 
     *  /time1e/pf_ex(kf)                                               
	common                                                                 
     *  /fluxc9/fdd,fdd0                                                
     *  /fluxc13/volt_sec(kf)                                           
     *  /fluxc14/vs_pf,vs_pl,vs_tot                                     
     *  /fluxc17/f_index                                                
     *  /fluxc18/alf_tok,int_tok                                        
                                                                        
                                                                        
                                                                        
        common /temp_al/cal                                             
	common                                                                 
     *	/ge1e/rs0,tpl                                                    
     *  /ge7e/eu_u                                                      
	common                                                                 
     *	/n_m/n,m,mp                                                      
	common                                                                 
     */igr/ygr(iy,ny),tgr(ny),igr                                       
	common                                                                 
     *	/ng_igr/ng                                                       
	common                                                                 
     *  /eq11/psval(npo),psval0(npo)                                    
                                                                        
	common                                                                 
     *	/keys4/k_ener,k_uv                                               
     *  /keys5/next                                                     
     *  /keys9/i_d3d,i_iter,i_smal                                      
     *  /keys11/i_ramp                                                  
     *  /keys12/i_v                                                     
                                                                        
	character *10 mgr(iy),mt(iy)  
	                                         
	character *30 apr                                                      
	character *12 yy(iy)                                                   
	character *50 tmp                                                      
      dimension a_print(200)                                                                 
c                                                                       
	dimension pmas(npo)                                                    
c                                                                       
	common                                                                 
     */pf1/npf,pf(kf),pf0(kf)                                           
      COMMON                                                            
     */en1/PNE(npo),PD0(npo),PT0(npo),PH0(npo),                         
     *PDN(npo),PTN(npo),PHN(npo)                                        
     */en2/TE0(npo),TQ0(npo),TEN(npo),TQN(npo),                         
     *WE0(npo),WQ0(npo)                                                 
     */en4/WD0(npo),WT0(npo),WH0(npo),VD(npo),DIF(npo),                 
     *GGT(npo),GGTN(npo)                                                
     */en5/SD0(npo),ST0(npo),SH0(npo)                                   
     */en6/VN(npo)                                                      
     */en7/UD,ZD,UT,ZT,UH,ZH,LT,LD,LH,ID,IT,IH ,KTP,NNT                 
     */en9/QE0(npo),QQ0(npo),QDG(npo)                                   
     */en10/GGE(npo),GGEN(npo),DXE(npo),DXQ(npo),WU(npo),               
     *UG(npo),VG(npo)                                                   
     */en11/UN(4),ZN(2),LL,KEN,KEN1,KEN2,NNE                            
	common                                                                 
     */en12/pnal(npo),pnaln(npo),zalfa,talfa                            
     */en13/KPIN,VPIN,ALP1,pot,skor                                     
     */en14/EMOE,EMOQ,NDOP,QDE0(npo),QDQ0(npo)                          
     */en15/QNET(npo)                                                   
     */en16/QTOR(npo),QDH(npo),QpE(npo),QpQ(npo)                        
     */en17/QAE(npo),QAQ(npo),SAL(npo),NAL                              
     */en19/DD,DT,DH,SIN0,SINK,ALPY,Sss,Ppp,Eee                         
     */en21/qce(npo)                                                    
     */en22/XII(npo)                                                    
     */en23/kk,tn0,pna,wie(npo),wcx(npo),tn(npo),                       
     *pn(npo),pn0(npo)                                                  
     */en25/zhib,teoh                                                   
     */en27/NIJ                                                         
     */en28/wen1,wen2                                                   
     */en29/d_zvel                                                      
     */en31/dpsi_ax                                                     
     */en33/anom_e,anom_i,key_t11,kcchp                                 
	common                                                                 
     */ves9/tokc,tokc0                                                  
     */ves11/tokcup,tokcdw                                              
	common                                                                 
     */disr/ndis                                                        
	common                                                                 
     *  /loop3/vloop,psf1a,psf1a0                                       
     *  /loop7/vloop1,vlooppf,vloop18,vloopv,vloope,vlooppl             
c                                                                       
      COMMON                                                            
     */ge1/PI                                                           
     */ge2/NTAY,TAY,TT                                                  
     */ge3/AI(npo),A0(npo),HA2(npo),a(npo),ha(npo)                      
     */ge4/EPS1,EPS2,EPS0                                               
     *  /ge5/kpr                                                        
     */ge6/zeff(npo),qpr(npo),ppr(npo),pr0,prg,zar                      
     */ge7/eu,rs,zact,eksk                                              
     */ge8/pcch                                                         
	common                                                                 
     */mid1/C1(npo),C2(npo),C3(npo)                                     
     */mid2/VI(npo),spo(npo)                                            
     */mid3/GRA1(npo),GRA2(npo)                                         
     */mid5/d1,d2                                                       
	common                                                                 
     */pol4/UM,VM,UK(ntet),VK(ntet)                                     
	common                                                                 
     */dfm1/UDM,ZDM,LM,SIG0                                             
     */dfm2/PSI(npo),PFI(npo),DM0(npo),DMN(npo)                         
     *  /dfm3/dfmax(npo),dfmax0(npo)                                    
     */dfm4/Q(npo),ANU(npo),P(npo),F(npo),                              
     *PP(npo),PFF(npo)                                                  
     */dfm5/PT01,PT02                                                   
     */dfm7/BT,UIND                                                     
     */dfm11/c20(npo),tok1(npo),tok2(npo)                               
     */dfm12/betpj,dlint,bett,bet2,betpc,tk,tkp,tkf                     
     */dfm13/tokel,tokfi,tokbut                                         
     *  /dfm13e/tokuv                                                   
     *  /dfm14/tokae,ajae(npo),ajae0(npo),enae                          
     */dfm15/uli                                                        
     */dfm17/betpi,betp2                                                
	common                                                                 
     *  /eq15/pll,zsep,rsep,zsepup,rsepup,zsepdw,rsepdw                 
     *  /eq23/xleft,xright                                              
     *  /eq24/psi_ax0,psi_ax                                            
     *  /eq25/rps(ntet),zps(ntet)                                       
	common                                                                 
     *  /cont1/vchopper(kf),veps                                        
     *  /cont7/zp,gapin                                                 
     *  /cont11/pr1,sdiv,dfzx,dfz,dfr                                   
     *  /cont12/zmax,zmin                                               
     *  /cont13/zmag,zvel,delrs,delzmag                                 
     *  /cont13e/zmag0,rmag,rmag0,rvel                                  
     *  /cont14/p_pl,p_ves,p_pf,p_mes                                   
     *  /cont15/p_pas                                                   
	common /pas10/c_p1,c_p2                                                
     *  /curs1/	t_ps,t_bs,t_dia,t_beam                                  
	common                                                                 
     *  /halo4/expfg,avalb,w_h,del_r,al0                                
     *  /halo4e/w_h0,delaval0,pshalo0,te_h0                             
     *  /halo5/q_vde,q_95,del_f,i_halo                                  
     *  /halo5e/pshalo                                                  
     *  /halo6/thalo,thalo0                                             
     *  /halo8/ftot_r,ftot_z,ftot_t                                     

	common /c_data_in_time2/i_c_data,i_c_data1
                                                                        
	common /c_imp_out4/p_ohm0,p_loss0,qen2_0

	common
     *  /c_kav2/epol,vol_pl
     *  /c_vs3/Pvs3, P_rg
c*********************************************************
     *  /maksim_01/tqc,Emag

      dimension dNB_xx(24)

      dimension res(3),te_zrad(3)

       real te_zrad,res

c                                                                       
4010    format(6e12.3)                                                  
ccccc      WDR=(WD0(N)+WT0(N)+WH0(N))*2.5                               

	i_en=i_en+1
	if(i_en.eq.1)then
	
	s_plasma=1.e4
	
	xleft=rmag-0.5*eu
	xright=rmag+0.5*eu
	
	call vic_turn()

	do i=1,npf
	a_print(i)=pf_turns(i)
	end do

	n_pr=npf

	apr='pf_turns '
	num=30
	if(kpr.eq.1)call out42(n_pr,a_print,num,apr)

	end if

!      r_cur=r_tok
!      z_cur=z_tok

	wdre=0.                                                                
	wdrq=0.                                                                
	do i=2,n                                                               
        WDRE=WDRE+ken2*(pne(i)*TE0(i)-pne(i-1)*TE0(i-1))*vg(i)          
        WDRQ=WDRQ+ken2*(pne(i)*TQ0(i)-pne(i-1)*TQ0(i-1))*vg(i)          
	end do                                                                 
                                                                        
	wdr=2.5*ug(n)                                                          
      WDRE=WDRE+WDR*0.5*(TE0(N-1)+TE0(N))                               
      WDRQ=WDRE+WDR*0.5*(TQ0(N-1)+TQ0(N))                               
                                                                        
                                                                        
      WELT=2.*PI*WE0(N)/VN(N)*VI(N)                                     
      WIOT=2.*PI*WQ0(N)/VN(N)*VI(N)                                     
      WELP=2.*PI*WDRE/VN(N)*VI(N)                                       
      WIOP=2.*PI*WDRQ/VN(N)*VI(N)                                       
      WEL=WELT+WELP                                                     
      WIO=WIOT+WIOP                                                     
      WEN2=0.                                                           
c-------                                                                
      WEN_e=0.                                                          
      WEN_i=0.                                                          
c------                                                                 
      QEN2=0.                                                           
      PNOR=6.25E8                                                       
      WAE=0.                                                            
      WAQ=0.                                                            
      WPE=0.                                                            
      WPQ=0.                                                            
      WTOR=0.                                                           
      WDH=0.                                                            
      WDE=0.                                                            
      WDQ=0.                                                            
      WNET=0.                                                           
      PPch=0.                                                           
	pion=0.                                                                
	pion_d=0.
	pion_t=0.
      VV=0.                                                             
	wtec=0.                                                                
	wtqc=0.                                                                
      TEC=0.                                                            
      TQC=0.                                                            
      PHH=0.                                                            
      WEE=0.                                                            
      WQW=0.                                                            
      PRIM=0.                                                           
	wion=0.                                                                
	wper=0.                                                                
	pist=0.                                                                
	QC=0.                                                                  
        en_ae=0.                                                        
      DO 11 I=2,N                                                       
      DQD=PI*VI(I)*HA(I)                                                
	if(i.eq.n)                                                             
     *DQD=PI*VI(I)*HA(I)*0.5                                            
      PHH=PHH+DQD*(PH0(I)+PH0(I-1))                                     
      QC=QC+DQD*2.*QCE(I)                                               
      WAE=WAE+DQD*2.*QAE(I)                                             
      WAQ=WAQ+DQD*2.*QAQ(I)                                             
      WPE=WPE+DQD*2.*QpE(I)                                             
      WPQ=WPQ+DQD*2.*QpQ(I)                                             
      WTOR=WTOR+DQD*2.*QTOR(I)                                          
      PRIM=PRIM+DQD*2.*QPR(I)                                           
      WION=WION+DQD*2.*WIE(I)                                           
      WPER=WPER+DQD*2.*WCX(I)                                           
      WDH=WDH+DQD*2.*QDH(I)                                             
      WDE=WDE+DQD*2.*QDE0(I)                                            
      WDQ=WDQ+DQD*2.*QDQ0(I)                                            
      WNET=WNET+DQD*2.*QNET(I)                                          
      WEN2=WEN2+DQD*(TE0(I)+TQ0(I)+TE0(I-1)+TQ0(I-1))*                  
     *1.5*0.5*(PNE(I)+PNE(I-1))                                         
c--------                                                               
      WEN_e=WEN_e+DQD*( TE0(I)+TE0(I-1) )*                              
     *1.5*0.5*(PNE(I)+PNE(I-1))                                         
      WEN_i=WEN_i+DQD*(TQ0(I)+TQ0(I-1))*                                
     *1.5*0.5*(PNE(I)+PNE(I-1))                                         
c---------                                                              
      QEN2=QEN2+1.0*DQD*2*(QE0(I)+QQ0(I))                               
      TQC=TQC+PI*(TQ0(I)+TQ0(I-1))*VI(I)*HA(I)                          
      TEC=TEC+PI*(TE0(I)+TE0(I-1))*VI(I)*HA(I)                          
c	wtec=wtec+dqd*(te0(i)+te0(i-1))*0.5*(pne(i)+pne(i-1))                 
c	wtqc=wtqc+dqd*(tq0(i)+tq0(i-1))*0.5*(pne(i)+pne(i-1))                 
      PPch=PPch+PI*(PNE(I)+PNE(I-1))*VI(I)*HA(I)                        
	pion=pion+dqd*(pd0(i)+pd0(i-1)+pt0(i)+pt0(i-1)                         
     *+ph0(i)+ph0(i-1))                                                 
	pion_d=pion_d+dqd*(pd0(i)+pd0(i-1))
	pion_t=pion_t+dqd*(pt0(i)+pt0(i-1))
	pist=pist+dqd*2.*(sd0(i)+st0(i)+sh0(i))                                
        en_ae=en_ae+ajae(i)*2.*pi*vi(i)*ha(I)                           
   11 VV=VV+VI(I)*HA(I)                                                 
                                                                        
      en_ae=en_ae*12.5*1.e-7/3.                                         
             
                                                                        
      IF(NTAY.EQ.0)QEN1=QEN2                                            
      VV=2.*PI*VV                                                       
c	tec=wtec/ppch                                                         
c	tqc=wtqc/ppch                                                         
                                                                        
      pion=pion/VV
      pion_d=pion_d/VV
      pion_t=pion_t/VV
                                                              
      TQC=TQC/VV                                                        
      TEC=TEC/VV                                                        
      PCch=PPch/VV                                                      
                                                                        
      WNET=WNET/PNOR                                                    
      SUMN=SUMN+TAY*WNET*1.E-3          
                                      
      WEN2=WEN2/PNOR  
      
      WEN2=WEN2*.1e-3



        nz_imp=4

c        nz_imp=74
        te_zrad(1)=tec*1.e-3
!           call zrad1(nz_imp,2,1,te_zrad,RES)
           call zrad(nz_imp,2,1,te_zrad,RES)
           z_1=res(1)
!           call zrad1(nz_imp,3,1,te_zrad,RES)
           call zrad(nz_imp,3,1,te_zrad,RES)
           z_2=res(1)

       if(kpr.eq.1)print*,'z_1 z_2 tec ',z_1,z_2,tec


c----------------------------
      
!     	call print4(' tec tqc ne wen2=',tec,tqc,pcch,wen2)
                                                        
c-----                                                                  
      WEN_e=WEN_e/PNOR                                                  
      WEN_i=WEN_i/PNOR                                                  
c----                                                                   
      QEN2=QEN2/PNOR                                                    
c      TENE=WEN2/(QEN2-(WEN2-WEN1)/TAY)                                 
       WAE=WAE/PNOR                                                     
	qc=qc/pnor                                                             
      WAQ=WAQ/PNOR                                                      
      WPE=WPE/PNOR                                                      
      WPQ=WPQ/PNOR                                                      
      WTOR=WTOR/PNOR                                                    
      WDH=WDH/PNOR                                                      
      PRIM=PRIM/PNOR                                                    
      WION=WION/PNOR                                                    
      WPER=WPER/PNOR                                                    
      WDE=WDE/PNOR                                                      
      WDQ=WDQ/PNOR   


	WDH1=0.d0
	v_tot1=0.d0
      DO  I=2,N                                                       
      DQD=PI*VI(I)*HA(I)                                                
	v_tot1=v_tot1+2.d0*DQD
	if(i.eq.n)                                                             
     *DQD=PI*VI(I)*HA(I)*0.5                                            
      WDH1=WDH1+DQD*2.*QDG(I)                                             
	end do

	WDH1=WDH1/pnor

c	call print2(' Wdh vv==',wdh,vv)
c	call print2(' Wdh1 v_tot1==',wdh1,v_tot1)


	do i=1,n
	a_print(i)=qdh(i)
	end do	
	n_pr=n
	apr='qdh'
	num=25
c	call out42(n_pr,a_print,num,apr)

	                                                   
	ptot=(wae+waq+wde+wdq+wpe+wpq) 
	
	ptot_help=ptot 
	                                       
	ptot=ptot+abs(wdh)
	
	                                                     
	if(abs(ptot).lt.1.e-5)ptot=1.e-5 
	
	                                      
      WW1=1.5*0.5*(TE0(N)+TE0(N-1))*UG(N)                               
      WW2=1.5*0.5*(TE0(N)+TE0(N-1))*UG(N)                               
      WEL=WEL/PNOR                                                      
      WIO=WIO/PNOR                                                      
      WELT=WELT/PNOR                                                    
      WIOT=WIOT/PNOR                                                    
      WELP=WELP/PNOR                                                    
      WIOP=WIOP/PNOR                                                    
c--------------------------                                             
c here balance of heat---(wen2-wen1)/tay=qen2-wel-wio                   
	wb_l=(wen2-wen1)/tay                                                   
	wb_r=qen2-wel-wio                                                      
c	if(kpr.eq.1)print *,' welt welp wiot wiop==',welt,welp,wiot,wiop      
c	if(kpr.eq.1)print *,' wen2 wen1 tay=======',wen2,wen1,tay             
c	if(kpr.eq.1)print *,' qen2 wel wio=======',qen2,wel,wio               
c	if(kpr.eq.1)print *,' wb_l wb_r ken2=======',wb_l,wb_r,ken2           
	wsum=wnet+wel+wio+wtor+qc+prim                                         
	wl=wtor+qc+prim                                                        
	wa=wae+waq                                                             
	wtp=wel+wio                                                            
c	if(kpr.eq.1)print *,' Q_el  Q_ion  Q_lin',wel,                        
c    *	wio,wl                                                           


        tene=1.
        tene_e=1.
        tene_i=1.

      if(k_ener.eq.1)	then
 	tene=wen2/(welt+wiot+1.e-8)                                            
                                                                        
        WEN1=WEN2                                                       
c------                                                                 
	tene_e=wen_e/(welt+1.e-8)                                              
                                                                        
c	tene_e=400.                                                           
	tene_i=wen_i/(wiot+1.e-8) 

	end if

	if(kpr.eq.1)print *,' *** wen_e welt  ',wen_e,welt
	if(kpr.eq.1)print *,' *** wen_i wiot  ',wen_i,wiot

c#
c------
	if(kpr.eq.1)print *,' *** tene tene_e tene_i ',tene,tene_e,tene_i
c----------------------------------------------------
	talfa=0.2*tene
c==========================================================================
c-- teKA=0.067*I^0.85*P^-0.5*R_0^0.85*a^0.3*k^0.25*n_20^0.1*B_0^0.3*A_i^0.5
	pot=0.5*(2.+3.)
c    pot=0.5*(mD+mT)
	duh1=0.001**0.85*0.01**0.85*0.01**0.3*0.1**0.1*0.1**0.3*1.e3
	alfa1=0.067*duh1*tpl**0.85*rs**0.85*eu**0.3*eksk**0.25*pcch**0.1*
     *  bt**0.3*pot**0.5
c---------> KEY ''all'' teka
	teka=alfa1**2/wen2
ccc        teka=alfa1/sqrt(qen2+1.e-8)

	duh2=0.001**0.85*0.01**1.2*0.01**0.3*0.1**0.1*0.1**0.2*1.e3
	alfa2=0.048*duh2*tpl**0.85*rs**1.2*eu**0.3*eksk**0.5*pcch**0.1*
     *  bt**0.2*pot**0.5
c-----> ITER scaling teit

	teit=alfa2**2/wen2

c!!!	teit=alfa2**2/wen_e

	teit_l=alfa2/sqrt(ptot)
c       teit=alfa1/sqrt(qen2+1.e-8)
c
	duh3=0.001**1.24*0.01**1.65*0.01**(-0.49)*
     *  0.1**0.26*0.1**(-0.09)*1.e3
	alfa3=0.055*duh3*tpl**1.24*rs**1.65*eu**(-0.49)*
     *  eksk**0.28*pcch**0.26*
     *  bt**(-0.09)*(pot/1.5)**0.5
c----> key-goldtstone scaling L-mode tekg
c       tekg=alfa3/qen2**0.58
	tekg=(alfa3/wen2**0.58)**(1./0.42)
c
	duh4=0.001*0.01**1.75*0.01**(-0.37)*1.e3
	alfa4=0.037*duh4*tpl*rs**1.75*eu**(-0.37)*eksk**0.5*(pot/1.5)**0.5
c------>  Goldstone scaling L-mode
c       tego=alfa4/sqrt(qen2)
	tego=alfa4**2/wen2
c---->  Lackner-Gottardi Scaling For Low Aspect Ratios
	epi=eu/rs
	delta=sqrt(2.*epi/(1.+epi))
	telg=0.21*(tpl*1.e-3)**(4./5.)*(pcch*0.1/ptot)**(3./5.)*
     *  q(n)**(2./5.)*(rs*1.e-2)*(eu*1.e-2)**(6./5.)*eksk**(7./5.)/
     *  ( delta**(8./5.)*(1.+epi)**(4./5.)*(1.+eksk**2)**(4./5.) )
c anomalous factor anom_e for electrons ...
	telg=telg*1.e+3
c==========================================================================
	te11=3.5e-5*(eu/rs)**0.25*q(n)*pcch*rs**3/sqrt(tec)
	if(kpr.eq.1)print *,' ** telg ptot anom_e anom_i**',
     *telg,ptot,anom_e,anom_i


c---->  ITER (Scaling L-mode,95) tay95=0.023*Ip**0.96*R**1.89*a**(-0.06)*
c   n_e**0.4*B_t0**0.03*k**0.64*A_i**0.2*P**(-0.73)

        teit_95=0.023*(tpl*1.e-3)**(0.96)*(rs*1.e-2)**(1.83)*
     *  (rs/eu)**(-0.06)*(pcch)**(0.4)*(bt*0.1)**(0.03)*
     *  eksk**(0.64)*pot**(0.2)/(wen2)**0.73*1000.

        TEIT_95=TEIT_95**(1./(1.-0.73))





c------>  NEO-Alcator teoh
	teoh=7.e-6*pcch*rs*rs*eu*q(n)
c	teoh=50.
	tepr=teoh

ccc	tepr=te11
c
c        tepr=telg
c
c        if(i_iter.eq.1)tepr=teit_l

c
c----        tepr=teka
c
c        tepr=tego
c


        tepr=teit_95


        tepr=teit_l

c	if(tt.gt.260.) tepr=tepr/anom_e
        
        
	if(kpr.eq.1)print *,' ** teit teit_l teit_95 teoh**',
     *  teit,teit_l,teit_95,teoh

       if(tepr.gt.teoh)tepr=teoh

c-----
	if(ntay.lt.1)tepr=teoh

c*********************************************************************

c here balance of heat---(wen2-wen1)/tay=qen2-wel-wio ITER.txt (start)

	wb_l=(wen_2-wen_20)/tay

	wb_r=qen2-wel-wio

c*** Power across separatrix, MW
c!!!!!!!        p_sep=qen2-(wen2-wen1)/tay
        p_sep=qen2

      p_sep=qen2_0

!	call print3(' qen2_0 p_ohm0 p_loss0==',
!     *  qen2_0,p_ohm0,p_loss0)



	p_sep_a=abs(p_sep)

	if(kpr.eq.1)print *,' welt welp wiot wiop==',welt,welp,wiot,wiop
	if(kpr.eq.1)print *,' wpe  wpq wdh',wpe,wpq,wdh
	if(kpr.eq.1)print *,' q_e q_i==',q_e,q_i
	if(kpr.eq.1)print *,' wen2 wen1 tay=======',wen2,wen1,tay
	if(kpr.eq.1)print *,' qen2 wel wio=======',qen2,wel,wio
	if(kpr.eq.1)print *,' wb_l wb_r ken2=======',wb_l,wb_r,ken2
	wsum=wnet+wel+wio+wtor+qc+prim
	wl=wtor+qc+prim
	wa=wae+waq
	wtp=wel+wio
	if(kpr.eq.1)print *,' Q_el  Q_ion  Q_lin',wel,
     *	wio,wl
	tene=wen2/(welt+wiot+1.e-8)

c------
c	tene_e=wen_e/(q_e+1.e-8)

 	tene_e=wen_e/(welt+1.e-8)

c	tene_e=400.
	tene_i=wen_i/(wiot+1.e-8)
	if(kpr.eq.1)print *,' *** tene tene_e tene_i ',tene,tene_e,tene_i
c----------------------------------------------------
	talfa=0.2*tene
c================================================================

c-- teKA=0.067*I^0.85*P^-0.5*R_0^0.85*a^0.3*k^0.25*n_20^0.1*B_0^0.3*A_i^0.5

	pot=0.5*(2.+3.)
c    pot=0.5*(mD+mT)
	duh1=0.001**0.85*0.01**0.85*0.01**0.3*0.1**0.1*0.1**0.3*1.e3
	alfa1=0.067*duh1*tpl**0.85*rs**0.85*eu**0.3*eksk**0.25*pcch**0.1*
     *  bt**0.3*pot**0.5


        alfa1=alfa1/anom_e

c---------> KEY ''all'' teka
	teka=alfa1**2/wen2


	duh2=0.001**0.85*0.01**1.2*0.01**0.3*0.1**0.1*0.1**0.2*1.e3

	alfa2=0.048*duh2*tpl**0.85*rs**1.2*eu**0.3*eksk**0.5*pcch**0.1*
     *  bt**0.2*pot**0.5

c-----> ITER 89_l scaling teit

        alfa2=alfa2/anom_e

        teit_l=alfa2**2/wen_e
c        teit_l=alfa2**2/wen2

        teit=alfa2/sqrt(ptot)

        ptot_cor=ptot

	duh3=0.001**1.24*0.01**1.65*0.01**(-0.49)*
     *  0.1**0.26*0.1**(-0.09)*1.e3

	alfa3=0.055*duh3*tpl**1.24*rs**1.65*eu**(-0.49)*
     *  eksk**0.28*pcch**0.26*
     *  bt**(-0.09)*(pot/1.5)**0.5

c----> key-goldtstone scaling L-mode tekg

        alfa3=alfa3/anom_e

	tekg=(alfa3/wen2**0.58)**(1./(1.-0.58))

c
	duh4=0.001*0.01**1.75*0.01**(-0.37)*1.e3
	alfa4=0.037*duh4*tpl*rs**1.75*eu**(-0.37)*eksk**0.5*(pot/1.5)**0.5
c------>  Goldstone scaling L-mode

        alfa4=alfa4/anom_e

	tego=alfa4**2/wen2

        if(kpr.eq.1)print *,'teka tekg tego',teka,tekg,tego

c---->  Lackner-Gottardi Scaling For Low Aspect Ratios
	epi=eu/rs
	delta=sqrt(2.*epi/(1.+epi))

        telg=0.21*(tpl*1.e-3)**(4./5.)*(pcch*0.1/(wen2*1.e-3))**(3./5.)*
     *  q(n)**(2./5.)*(rs*1.e-2)*(eu*1.e-2)**(6./5.)*eksk**(7./5.)/
     *  ( delta**(8./5.)*(1.+epi)**(4./5.)*(1.+eksk**2)**(4./5.) )

        telg=telg/anom_e

        telg=telg**(1./(1.-3./5.))*1.e3



c anomalous factor anom_e for electrons ...
c==========================================================================

	te11=3.5e-5*(eu/rs)**0.25*q(n)*pcch*rs**3/sqrt(tec)

        te11=te11/anom_e

	if(kpr.eq.1)print *,' ** telg ptot anom_e anom_i**',
     *telg,ptot,anom_e,anom_i

c---->  ITER Scaling (OH,L-mode) tay96=0.058*Ip**0.96*R**1.89*a**(-0.06)*
c   n_e**0.4*B_t0**0.3*k**0.64*A_i**0.2*P**(-0.73)

        teit_96=0.058*(tpl*1.e-3)**(0.96)*(rs*1.e-2)**(1.89)*
     *  (eu*1.e-2)**(-0.06)*(pcch*0.1)**(0.4)*(bt*0.1)**(0.3)*
     *  eksk**(0.64)*pot**(0.2)/(wen2*1.e-3)**0.73

        teit_96=teit_96/anom_e

        teit_96=teit_96**(1./(1.-0.73))*1.e3


c---->  ITER Scaling ( H-mode) tay97=0.073*Ip**0.9*R**1.84*a**(0.19)*
c   n_e**0.4*B_t0**0.2*k**0.92*A_i**0.2*P**(-0.66)

        teit_97=0.073*(tpl*1.e-3)**(0.9)*(rs*1.e-2)**(1.84)*
     *  (eu*1.e-2)**(0.19)*(pcch*0.1)**(0.4)*(bt*0.1)**(0.2)*
     *  eksk**(0.92)*pot**(0.2)/(wen2*1.e-3)**0.66

        teit_97=teit_97/anom_e

        TEIT_97=TEIT_97**(1./(1.-0.66))*1.e3


c---->  ITER (Scaling L-mode,95) tay95=0.023*Ip**0.96*R**1.89*a**(-0.06)*
c   n_e**0.4*B_t0**0.03*k**0.64*A_i**0.2*P**(-0.73)

        teit_95=0.023*(tpl*1.e-3)**(0.96)*(rs*1.e-2)**(1.89)*
     *  (eu*1.e-2)**(-0.06)*(pcch)**(0.4)*(bt*0.1)**(0.03)*
     *  eksk**(0.64)*pot**(0.2)/(wen2*1.e-3)**0.73

        teit_95=teit_95/anom_e

        TEIT_95=TEIT_95**(1./(1.-0.73))*1.e3

c---->  ITER (Scaling H-mode,98, ELMy) tay95=0.0365*Ip**0.97*R**1.7*
c   a**(0.23)*n_e**0.4*B_t0**0.08*k**0.67*A_i**0.2*P**(-0.63)

        teit_98=0.0365*(tpl*1.e-3)**(0.97)*(rs*1.e-2)**(1.7)*
     *  (eu*1.e-2)**(0.23)*(pcch)**(0.41)*(bt*0.1)**(0.08)*
     *  eksk**(0.67)*pot**(0.2)/(wen2*1.e-3)**0.63

        teit_98=teit_98/anom_e

        TEIT_98=TEIT_98**(1./(1.-0.63))*1.e3

        if(kpr.eq.1)print *,' ** teit_95 teit_96  ',teit_95,teit_96

c!        print *,' ** teit_97 teit_98  ',teit_97,teit_98

        if(kpr.eq.1)print *,' ** KEY_T11 te11 teit ',KEY_T11,te11,teit

c---->  TOR_Supra(Scaling L-mode) te_sup=0.019*Ip**0.96*R**1.82*
c   n_e**0.43*B_t0**0.2*P**(-0.75)

        te_sup=0.019*(tpl*1.e-3)**(0.96)*(rs*1.e-2)**(1.82)*
     *  (pcch)**(0.43)*(bt*0.1)**(0.2)/(wen2*1.e-3)**0.75

        te_sup=te_sup/anom_e

        te_sup=te_sup**(1./(1.-0.75))*1.e3


c------------------------

        te_sup_p=0.019*(tpl*1.e-3)**(0.96)*(rs*1.e-2)**(1.82)*
     *  (pcch)**(0.43)*(bt*0.1)**(0.2)*ptot**(-0.75)


        te_sup_p=te_sup_p/anom_e

        te_sup_p=te_sup_p*1.e3

c------>  NEO-Alcator teoh

        teoh=70.*(pcch*0.1)*(rs*1.e-2)**2*(eu*1.e-2)*q(n)

        teoh=teoh/anom_e

        te_shim=70.*(eu*1.e-2)*(rs*1.e-2)*(bt*0.1)*sqrt(pot*eksk/2.)

        te_shim=te_shim/anom_e

c  RLW 
        rlwcst=0.012*(tpl*1.e-3)*( rs*0.01*(eu*0.01)**2*eksk )**0.5/
     *  zeff(2)**0.5

        te_rlw=2.6e-2*pcch**0.75*zeff(2)**0.25*(bt*0.1)**0.5*
     *  (tpl*1.e-3)**0.5*( rs*0.01*(eu*0.01)**2*eksk )**(11./12.)/
     *  ptot+rlwcst

	te_rlw=te_rlw*1.e3

c        if(ptot_dop.ge.0.1)te_rlw=te_rlw/anom_e
        te_rlw=te_rlw/anom_e


	if(kpr.eq.1)print *,' ** te_rlw rlwcst ptot_dop',
     *  te_rlw,rlwcst*1.e3,ptot_dop

c******** Additional stuff by Victor
c-----> P_LH power threshold  P_LH=2.84*A_i**(-1)*B_t0**0.82*
c       (0.1*n_e)**0.58*R*eu**0.81, MW

        p_lh=2.84/pot*(bt*0.1)**(0.82)*(0.1*pcch)**0.58*
     *  (rs*1.e-2)*(eu*1.e-2)**0.81
        r_lh=p_sep_a/p_lh

c----> ITER (Scaling H-mode,98) tay98=0.0562*Ip**0.93*B_t0**0.15*
c     P**(-0.69)*n_e**0.41*A_i**0.19*R**1.97*eps**0.58*k_a**0.78
cccc      k_a=S/(pi*a**2) >>>> made in Naka

        teit_98=0.0562*(tpl*1.e-3)**(0.93)*(bt*0.1)**(0.15)*
     *  (pcch)**(0.41)*pot**(0.19)*(rs*1.e-2)**(1.97)*
     *  (eu/rs)**(0.58)*(eksk)**(0.78)/(ptot)**(0.69)*1.e3
     
          
c! WDH+ptot 
c! *1.e3

        teit_98_2=teit_98
        teit_98=teit_98/anom_e

c!        TEIT_98=TEIT_98**(1./(1.-0.69))
c!        TEIT_98=TEIT_98*1.e3
c!


	  key_zhib=0							                                              
        if(key_t11.eq.0.or.key_t11.eq.2.or.key_t11.eq.3)then              
        key_zhib=1                                 
        end if                                                          

	k_rlw=0
        if(key_zhib.eq.1)k_rlw=1
        if(k_rlw.eq.1)tepr=te_rlw

	k_t11=0
	  if(key_t11.eq.4)k_t11=1
        if(k_t11.eq.1)tepr=te11

	k_lg=0
	  if(key_t11.eq.5)k_lg=1
        if(k_lg.eq.1)tepr=telg

c##        if(k_it89.eq.1)tepr=teit_l

	k_it89=0
	  if(key_t11.eq.6)k_it89=1
        if(k_it89.eq.1)tepr=teit


	k_sup=0
	  if(key_t11.eq.7)k_sup=1
        if(k_sup.eq.1)tepr=te_sup

	k_shim=0
	  if(key_t11.eq.8)k_shim=1
        if(k_shim.eq.1)tepr=te_shim

	k_ka=0
	  if(key_t11.eq.9)k_ka=1
        if(k_ka.eq.1)tepr=teka

	k_kg=0
	  if(key_t11.eq.10)k_kg=1
        if(k_kg.eq.1)tepr=tego
        
	k_it95=0
	  if(key_t11.eq.11)k_it95=1
        if(k_it95.eq.1)tepr=teit_95

	k_it97=0
	  if(key_t11.eq.12)k_it97=1
        if(k_it97.eq.1)tepr=teit_97

	k_it98=0
	  if(key_t11.eq.13)k_it98=1
        if(k_it98.eq.1)tepr=teit_98

	  k_oh=0
	  if(key_t11.eq.14)k_oh=1
        if(k_oh.eq.1)tepr=teoh
c

c-----                                                                  
	if(ntay.lt.3)tepr=teoh                                                 
	if(tepr.le.1)tepr=1.                                          
                                                                        
        zhib0=zhib                                                      
                                                                        
!        if(kpr.eq.1)print *,' ntay k_ener key_t11 ==',ntay,k_ener,key_t

        if(tene_e.le.0.)tene_e=tepr
        if(tene.le.0.)tene=tepr
                           
c	if(key_ext.eq.0)then						 
	
        if(tepr.gt.1.e5)tepr=1.e5
        if(tene_e.gt.tepr)tene_e=tepr
        if(zhib.gt.100.)zhib=100.
        
        if(kpr.eq.1)print *,' zhib tene_e tepr ==',zhib,tene_e,tepr


        zhib0=zhib

        if(ntay.gt.1.and.k_ener.eq.1.and.key_t11.ne.1)then
c!!!        zhib=zhib*(0.5+0.5*tene/tepr)

         zhib=zhib*(0.5+0.5*tene_e/tepr)
c        zhib=zhib*(0.5+0.5*tene/tepr)

c###        zhib=zhib*tene_e/tepr

        zhib=0.5*(zhib0+zhib)
        end if



c        end if
	                                                                   
c        if(kpr.eq.1)print *,' zhib ==',zhib          
                                                                        
55      continue                                                        

        if(ntay.le.3)tene_e=tepr
        if(ntay.le.3)tene_i=tepr
        if(ntay.le.3)tene=tepr

	a_print(1)=key_t11
	a_print(2)=tene_e
	a_print(3)=tene_i
	a_print(4)=tepr
	a_print(5)=zhib
	a_print(6)=welt
	a_print(7)=tene




	n_pr=7

	apr='k_11 t_e t_i tepr z wlt tene '
	num=30
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

        wznam=(Wde+Wdq+Wpe+wpq+wdh)                                     
c	wznam=(Wde+Wdq+Wpe+wpq+1.e-5)                                         
c       print *,'wdh wznam',wdh,wznam                                   
c       if(dabs(wznam).lt.1.e-10)return                                 
c        QTEP=Wsum/wznam                                                
ccc        QTEP=Wsum/ptot                                               
ccc        wsum=wnet+wel+wio+wtor+qc+prim                               
ccc        ptot=(wae+waq+wde+wdq+wpe+wpq)                               
        QTEP=(wnet+wae+waq)/(wde+wdq+1.e-5)                             
	hii=dxq(10)*1.e3/gra2(10)                                              
	hie=dxe(10)*1.e3/gra2(10)                                              

!!!	UACT=WDH/TPL*1.E3

	a_print(1)=wdh
	a_print(2)=uact
	a_print(3)=tpl

	n_pr=3

	apr='wdh uact tpl '
	num=30
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

 

	if(kpr.eq.1)print *,' ** UACT te_rlw rlwcst ',
     *  uact,te_rlw,rlwcst*1.e3

	vs_res=vs_res+uact*tay*1.e-3   
	vs=vs_res

      vs_start=vs
      
	a_print(1)=vs_pf
	a_print(2)=vs_pl
	a_print(3)=vs_res
	a_print(4)=vs_tot
	a_print(5)=uact
	n_pr=5

	apr='vs_pf vs_pl vs_res vs_tot u '
	num=30
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

c********************* 00 **********************************

	igr=1

c       ------I plasma---------
	ygr(1,igr)=tpl/1.e3
	yy(1)='I_pl[MA]'
c       ----beta p(2) --
	ygr(2,igr)=betpj
	yy(2)='BETAp'
c       ------a minor-----
	ygr(3,igr)=eu
	yy(3)='a[cm]'
c       -----L(3)----
	ygr(4,igr)=uli
	yy(4)='l_i(3)'
c*********************************************************
c       ---- rmag ------
	ygr(5,igr)=rmag
	yy(5)='Rmag[cm]'
c	ygr(5,igr)=r_cur
c	yy(5)='Rcur[cm]'
c	----Zmag-----
	ygr(6,igr)=zmag
	yy(6)='Zmag[cm]'
c	ygr(6,igr)=z_cur
c	yy(6)='Zcur[cm]'
c       ---- vessel current ------
c	ygr(7,igr)=tokc
c	yy(7)='Ivv[kA]'
c*** Power across separatrix with thermoconductivity + dQ/dt, MW
	ygr(7,igr)=p_sep
	yy(7)='Psep[MW]'
c       ---- elong ------
	ygr(8,igr)=eksk
c	yy(8)='k_99'
	yy(8)='k_bnd'
c*******************************************************
c       -------ne average-----
	ygr(9,igr)=pcch/10.
	yy(9)='Ne_avr[20]'
c       ---- gamma ------
	gamma=(pcch/10.)*pi*eu**2*1.e-4/(tpl/1.e3)
	ygr(10,igr)=gamma
	yy(10)='Gamma'
c       -------Zeff_a-----
	ygr(11,igr)=zeff_a
	yy(11)='Zeff_a'
c       -------Zeff_b-----
c	ygr(12,igr)=zeff_b
c	yy(12)='Zeff_b'
c	ygr(12,igr)=teoh
c	yy(12)='TAYoh,ms'
c	ygr(12,igr)=psipl_av
c	yy(12)='psipl_av,vs'
	ygr(12,igr)=psiext_av
	yy(12)='psiext_av,vs'
c********************************************************
c       -----te average-----
	ygr(13,igr)=tec
	yy(13)='Te_avr[eV]'
c       -----ti average----
	ygr(14,igr)=tqc
	yy(14)='Ti_avr[eV]'
c       -----te axis-----
	ygr(15,igr)=te0(1)
	yy(15)='Te_ax[eV]'
c       -----ti axis-----
	ygr(16,igr)=tq0(1)
	yy(16)='Ti_ax[eV]'
c***********************************************************
c       ---- wdop ------
        wdop=wde+wdq
ccc	wdop=wdop+wpe+wpq
	ygr(17,igr)=wdop
	yy(17)='P_aux,MW'
c       -----q bound---
c	ygr(13,igr)=q(n)
c	yy(13)='q_bn'
	ygr(18,igr)=q_95
	yy(18)='q_95'
c       ---- q_ax ------
	ygr(19,igr)=q(2)
	yy(19)='q_ax'
c       ---- uact ------
	ygr(20,igr)=vs
	yy(20)='VS_res[Wb]'
c*********************************************************
c	---- tay_e -----
	ygr(21,igr)=tene
	yy(21)='Tay_E[ms]'
c       ---- rsep ------
c	ygr(23,igr)=rsep
c	yy(23)='Rsep[cm]'
c       ---- zsep ------
	ygr(22,igr)=zsep
	yy(22)='Zsep[cm]'
c	---- Ce -----
c!!!!!	c_e=vs/(0.1*4*pi*rmag*1.e-2*tpl*1.e-3)
	ce_0=0.25
	if(ntay.eq.next)vs_0=ce_0*(0.1*4*pi*rmag*1.e-2*tpl*1.e-3)
	c_e_old=(vs_0+vs)/(0.1*4*pi*rmag*1.e-2*tpl*1.e-3)
	c_e_new=vs/(0.1*4*pi*rmag*1.e-2*tpl*1.e-3)
	ygr(23,igr)=c_e_old
	yy(23)='C_Ejima'
c       ---- W_sum ------
	w_pf=0.
	do i=1,npf
	w_pf=w_pf+vchopper(i)*pf(i)*1.e3*1.e-6
	end do
c	ygr(24,igr)=w_pf
c	yy(24)='P_PF[MW]'
        pmag_out=pmag*1.e-5*2.*pi
	ygr(24,igr)=pmag_out
	yy(24)='Pmag[Vs]'
c************************************************************
c           if(tt.gt.t_end)then
c              print*,'!!!tt t_end',tt,t_end
c	      print*,'d_gaps pf'
c	      do mmm=9,20
c	      print*,d_gaps(mmm),pf(mmm)/1.e3
c	      end do
c	   end if

	ygr(25,igr)=d_gaps(1)
	yy(25)='error_01'

	ygr(26,igr)=d_gaps(2)
	yy(26)='error_02'

	ygr(27,igr)=d_gaps(3)
	yy(27)='error_03'

	ygr(28,igr)=d_gaps(4)
	yy(28)='error_04'
c***********************************************
	ygr(29,igr)=d_gaps(5)
	yy(29)='error_05'

	ygr(30,igr)=d_gaps(6)
	yy(30)='error_06'

	ygr(31,igr)=d_gaps(7)
	yy(31)='error_07'

	ygr(32,igr)=d_gaps(8)
	yy(32)='error_08'
c***********************************************
	ygr(33,igr)=d_gaps(9)
	yy(33)='error_09'

	ygr(34,igr)=d_gaps(10)
	yy(34)='error_10'

	ygr(35,igr)=d_gaps(11)
	yy(35)='error_11'

	ygr(36,igr)=d_gaps(12)
	yy(36)='error_12'
c***********************************************
	ygr(37,igr)=d_gaps(13)
	yy(37)='error_13'

	ygr(38,igr)=d_gaps(14)
	yy(38)='error_14'

	ygr(39,igr)=d_gaps(15)
	yy(39)='error_15'

	ygr(40,igr)=d_gaps(16)
	yy(40)='error_16'
c***********************************************
	ygr(41,igr)=d_gaps(17)
	yy(41)='error_17'

	ygr(42,igr)=d_gaps(18)
	yy(42)='error_18'

	ygr(43,igr)=d_gaps(19)
	yy(43)='error_19'

	ygr(44,igr)=d_gaps(20)
	yy(44)='error_20'
c***********************************************
	i=1
	ggg=gaps(i)-gaps0(i)
	ygr(45,igr)=ggg
	yy(45)='del_g1[cm]'

	i=2
	ggg=gaps(i)-gaps0(i)
	ygr(46,igr)=ggg
	yy(46)='del_g2[cm]'

	i=3
	ggg=gaps(i)-gaps0(i)
	ygr(47,igr)=ggg
	yy(47)='del_g3[cm]'

	i=4
	ggg=gaps(i)-gaps0(i)
	ygr(48,igr)=ggg
	yy(48)='del_g4[cm]'
c************************************************
	i=5
	ggg=gaps(i)-gaps0(i)
	ygr(49,igr)=ggg
	yy(49)='del_g5[cm]'

	i=6
	ggg=gaps(i)-gaps0(i)
	ygr(50,igr)=ggg
	yy(50)='del_g6[cm]'

	ygr(51,igr)=pf(1)/1.e3
	yy(51)='CS3U[MA]'

	ygr(52,igr)=vchopper(1)
	yy(52)='V_CS3U[V]'
c************************************************
	ygr(53,igr)=pf(2)/1.e3
	yy(53)='CS2U[MA]'

	ygr(54,igr)=vchopper(2)
	yy(54)='V_CS2U[V]'

	ygr(55,igr)=pf(3)/1.e3
	yy(55)='CS1[MA]'

	ygr(56,igr)=vchopper(3)
	yy(56)='V_CS1[V]'
c************************************************************
	ygr(57,igr)=pf(4)/1.e3
	yy(57)='CS2L[MA]'

	ygr(58,igr)=vchopper(4)
	yy(58)='V_CS2L[V]'

	ygr(59,igr)=pf(5)/1.e3
	yy(59)='CS3L[MA]'

	ygr(60,igr)=vchopper(5)
	yy(60)='V_CS3L[V]'
c************************************************************
	ygr(61,igr)=pf(6)/1.e3
	yy(61)='PF1[MA]'

	ygr(62,igr)=vchopper(6)
	yy(62)='V_1[V]'

	ygr(63,igr)=pf(7)/1.e3
	yy(63)='PF2[MA]'

	ygr(64,igr)=vchopper(7)
	yy(64)='V_2[V]'
c*************************************************************
	ygr(65,igr)=pf(8)/1.e3
	yy(65)='PF3[MA]'

	ygr(66,igr)=vchopper(8)
	yy(66)='V_3[V]'

	ygr(67,igr)=pf(9)/1.e3
	yy(67)='PF4[MA]'

	ygr(68,igr)=vchopper(9)
	yy(68)='V_4[V]'
c*************************************************************
	ygr(69,igr)=pf(10)/1.e3
	yy(69)='PF5'

	ygr(70,igr)=vchopper(10)
	yy(70)='V_5[V]'

	ygr(71,igr)=pf(11)/1.e3
	yy(71)='PF6[MA]'

	ygr(72,igr)=vchopper(11)
	yy(72)='V_6[V]'
c***********************************************************
	ygr(73,igr)=pf(12)/1.e3
	yy(73)='I_VS[MA]'

	ygr(74,igr)=vchopper(12)
	yy(74)='V_VS[V]'

	ygr(75,igr)=zvconverter(1)*pf_turns(1)
	yy(75)='zvc(1)[V]'

	ygr(76,igr)=zvconverter(2)*pf_turns(2)
	yy(76)='zvc(2)[V]'
c************************************************************
	ygr(77,igr)=zvconverter(3)*pf_turns(3)
	yy(77)='zvc(3)[V]'

	ygr(78,igr)=zvconverter(4)*pf_turns(4)
	yy(78)='zvc(4)[V]'

	ygr(79,igr)=zvconverter(5)*pf_turns(5)
	yy(79)='zvc(5)[V]'

	ygr(80,igr)=zvconverter(6)*pf_turns(6)
	yy(80)='zvc(6)[V]'
c***********************************************
	ygr(81,igr)=zvconverter(7)*pf_turns(7)
	yy(81)='zvc(7)[V]'

	ygr(82,igr)=zvconverter(8)*pf_turns(8)
	yy(82)='zvc(8)[V]'

	ygr(83,igr)=zvconverter(9)*pf_turns(9)
	yy(83)='zvc(9)[V]'

	ygr(84,igr)=zvconverter(10)*pf_turns(10)
	yy(84)='zvc(10)[V]'
c*****************************************************
	ygr(85,igr)=zvconverter(11)*pf_turns(11)
	yy(85)='zvc(11)[V]'

	ygr(86,igr)=zvconverter(12)*pf_turns(12)
	yy(86)='zvc(12)[V]'

	ygr(87,igr)=u_1(1)
	yy(87)='u_1(1)[V]'

	ygr(88,igr)=u_1(2)
	yy(88)='u_1(2)[V]'
c*****************************************************
	ygr(89,igr)=u_1(3)
	yy(89)='u_1(3)[V]'

	ygr(90,igr)=u_1(4)
	yy(90)='u_1(4)[V]'
c******************************************************
	ygr(91,igr)=u_1(5)
	yy(91)='u_1(5)[V]'

	ygr(92,igr)=u_1(6)
	yy(92)='u_1(6)[V]'

	ygr(93,igr)=u_1(7)
	yy(93)='u_1(7)[V]'

	ygr(94,igr)=u_1(8)
	yy(94)='u_1(8)[V]'
c*****************************************************
	ygr(95,igr)=u_1(9)
	yy(95)='u_1(9)[V]'

	ygr(96,igr)=u_1(10)
	yy(96)='u_1(10)[V]'

	ygr(97,igr)=u_1(11)
	yy(97)='u_1(11)[V]'

	ygr(98,igr)=u_1(12)
	yy(98)='u_1(12)[V]'
c*****************************************************
	ygr(99,igr)=u_kd(1)
	yy(99)='u_kd(1)[V]'

	ygr(100,igr)=u_kd(2)
	yy(100)='u_kd(2)[V]'

	ygr(101,igr)=u_kd(3)
	yy(101)='u_kd(3)[V]'

	ygr(102,igr)=u_kd(4)
	yy(102)='u_kd(4)[V]'
c**********************************************************
	ygr(103,igr)=u_kd(5)
	yy(103)='u_kd(5)[V]'

	ygr(104,igr)=u_kd(6)
	yy(104)='u_kd(6)[V]'

	ygr(105,igr)=u_kd(7)
	yy(105)='u_kd(7)[V]'

	ygr(106,igr)=u_kd(8)
	yy(106)='u_kd(8)[V]'
c*****************************************************
	ygr(107,igr)=u_kd(9)
	yy(107)='u_kd(9)[V]'

	ygr(108,igr)=u_kd(10)
	yy(108)='u_kd(10)[V]'

	ygr(109,igr)=u_kd(11)
	yy(109)='u_kd(11)[V]'

	ygr(110,igr)=u_kd(12)
	yy(110)='u_kd(12)[V]'
c****************************************************
	ygr(111,igr)=rsep
	yy(111)='Rsep[cm]'

	ygr(112,igr)=teit_95
	yy(112)='tay_L[ms]'
	
	ygr(113,igr)=teit_98
	yy(113)='tay_H[ms]'
	
	ygr(114,igr)=r_lh
	yy(114)='r_LH'
	
c*****************************************************
	if(ksepa.eq.0)then
		ell=eksk
	else
		ell=elong_sep
	end if		
	ygr(115,igr)=ell
	yy(115)='k_sep'

	ygr(116,igr)=u_ffw(1)
	yy(116)='u_ffw(1)[V]'

	ygr(117,igr)=u_ffw(2)
	yy(117)='u_ffw(2)[V]'

	ygr(118,igr)=u_ffw(3)
	yy(118)='u_ffw(3)[V]'
c*****************************************************
	ygr(119,igr)=u_ffw(4)
	yy(119)='u_ffw(4)[V]'

	ygr(120,igr)=u_ffw(5)
	yy(120)='u_ffw(5)[V]'

	ygr(121,igr)=u_ffw(6)
	yy(121)='u_ffw(6)[V]'

	ygr(122,igr)=u_ffw(7)
	yy(122)='u_ffw(7)[V]'

c***************************************************
	ygr(123,igr)=u_ffw(8)
	yy(123)='u_ffw(8)[V]'

	ygr(124,igr)=u_ffw(9)
	yy(124)='u_ffw(9)[V]'

	ygr(125,igr)=u_ffw(10)
	yy(125)='u_ffw(10)[V]'

	ygr(126,igr)=u_ffw(11)
	yy(126)='u_ffw(11)[V]'
c***************************************************
	i=1
	ygr(127,igr)=gaps(i)
	yy(127)='gap_1[cm]'

	i=1
	ygr(128,igr)=gaps0(i)
	yy(128)='gap0_1[cm]'

	i=2
	ygr(129,igr)=gaps(i)
	yy(129)='gap_2[cm]'

	i=2
	ygr(130,igr)=gaps0(i)
	yy(130)='gap0_2[cm]'
c************************************************
	i=3
	ygr(131,igr)=gaps(i)
	yy(131)='gap_3[cm]'

	i=3
	ygr(132,igr)=gaps0(i)
	yy(132)='gap0_3[cm]'

	i=4
	ygr(133,igr)=gaps(i)
	yy(133)='gap_4[cm]'

	i=4
	ygr(134,igr)=gaps0(i)
	yy(134)='gap0_4[cm]'
c************************************************
	i=5
	ygr(135,igr)=gaps(i)
	yy(135)='gap_5[cm]'

	i=5
	ygr(136,igr)=gaps0(i)
	yy(136)='gap0_5[cm]'

	i=6
	ygr(137,igr)=gaps(i)
	yy(137)='gap_6[cm]'

	i=6
	ygr(138,igr)=gaps0(i)
	yy(138)='gap0_6[cm]'
c************************************************
        ygr(139,igr)=qc
	yy(139)='qc,MW'

        ygr(140,igr)=wtor
	yy(140)='wtor,MW'

        ygr(141,igr)=w_imp
	yy(141)='w_imp,MW'

        ygr(142,igr)=coef_imp
	yy(142)='coef_imp'
c*******************************************
        ygr(143,igr)=wae+waq
	yy(143)='W_alpha,MW'

c	call s_calc()
        ygr(144,igr)=s_plasma/1.e4
	yy(144)='s_plasma,m2'

        ygr(145,igr)=qtep
	yy(145)='Q'

        w_fusion=wnet+wae+waq
        ygr(146,igr)=w_fusion
	yy(146)='Wfus,MW'
c****************************************************
	p_sum=wae+waq+wdop
	    ygr(147,igr)=p_sum
		yy(147)='Psum,MW'

	P_HL=0.082/2.5*(pcch/10.)**0.73*5.3**0.74*(s_plasma/1.e4)**0.98
	    ygr(148,igr)=P_HL
		yy(148)='P_HL,MW'

!!!	pmag_out_1=dm0(1)*1.e-5

!	dm0_1_help=dm0(1)

      if(abs(dm0(1)).le.1.e-5)dm0(1)=vs_tot*1.e5
      
c	   ygr(149,igr)=pmag_out_1
c		yy(149)='Pmag Tr'

c	    ygr(148,igr)=zvel
c		yy(148)='zvel'

c**************************************************
	    ygr(149,igr)=dist_min_xx
		yy(149)='dist_min'

	    ygr(150,igr)=Rdist_min_xx
		yy(150)='Rdist_min'

	    ygr(151,igr)=Zdist_min_xx
		yy(151)='Zdist_min'

	    ygr(152,igr)=Zdist_min_xx
		yy(152)='Zdist_min'


        do i=112,176
        ygr(i,igr)=0.
        end do


        do i=153,176
        yy(i)='   '
        end do
        
	tgr(igr)=tt

!		ng=152
		ng=176

      if(kpr.eq.1)print *,' ng1=igr =',ng1,igr

	tmp='na_ramp'
	if(i_en.eq.1)then
	open (unit=41, file=tmp,form='formatted')
	write (41,*)ng
	do i=1,ng
	write (41,*)yy(i)
	end do
	close (41)
	end if


c
c	shape_out(27)=vs_pf                                                
c	shape_out(28)=vs_pl                                               
c	shape_out(29)=vs_res                                                
c	shape_out(30)=vs_tot
	
c	shape_out(31)=fdd*1.d-5

c	shape_out(32)=vs_ext


	call get_data_in_time(pcch,tene,wdop,
     *  p_sum,p_loss)

      wde=wdop
      wdq=0.

      call get_start_data(wdop,tene,wdh)

      wde=wdop
      wdq=0.

	if(kpr.eq.1)print *,' pion_d ==pion_t=====',pion_d,pion_t
	if(kpr.eq.1)print *,' pion==wdop=====',pion,wdop
	if(kpr.eq.1)print *,' tene,wdh====',tene,wdh
	if(kpr.eq.1)print *,' ++p_loss====',p_loss

	open (unit=41,file='te_ti.dat',
     *	form='formatted')
	write(41,*)'te_a   ti_a  zeff_a '
	write (41,*)te0(1),tq0(1),zeff(1)
	write(41,*)' dens vs_res p_loss'
	write (41,*)pcch,vs_res,p_loss
	write(41,*)' rmag zmag'
	write (41,*)rmag,zmag
	close (41)

	open (unit=41,file='Pvs3.dat',
     *	form='formatted')
	write(41,*)'Pvs3 P_rg'
	write (41,*)Pvs3,P_rg
	close (41)

	tene=tene*1.d3

	psi_pf=vs_pf
	zeff_a=zeff(1)
	vs=vs_res

!	r_cur=r_tok
!	z_cur=z_tok


	a_print(1)=wdop
	a_print(2)=p_sum
	a_print(3)=tene
	a_print(4)=pcch
	a_print(5)=p_loss


!	a_print(5)=r_tok
!	a_print(6)=z_tok


	n_pr=5

	apr='w_d w_s taye ne wd '
	num=30
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	if(i_c_data.eq.1)then
!	pmag_out_1=0.d0
	P_HL=0.d0
	r_lh=0.d0
	p_sum=wdop
	p_sep=p_loss
	end if

	if(i_c_data1.eq.1)then
	wen2=0.d0
	end if

!	p_sep=0.d0
	p_sum=wdop
	r_lh=0.d0


	a_print(1)=p_sep
	a_print(2)=p_sum
	a_print(3)=r_lh
	a_print(4)=i_c_data
	a_print(5)=pmag_out_1


!	a_print(5)=r_tok
!	a_print(6)=z_tok


	n_pr=5

	apr='p_s w_s r_l i_c psi_a '
	num=30
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	a_print(1)=wdop
	a_print(2)=p_sum
	a_print(3)=tene
	a_print(4)=pcch
	a_print(5)=p_loss


!	a_print(5)=r_tok
!	a_print(6)=z_tok


	n_pr=5

	apr='w_d w_s taye ne wd '
	num=30
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

      do i=1,npf
!      if(kpr.eq.1)print *,'pf_turns(i)=',pf_turns(i)
      end do


      if(tq0(1).lt.tqc)then
	if(kpr.eq.1)print *,' tqc tq0=======',tqc,tq0(1)
	if(kpr.eq.1)print *,' tec te0=======',tec,te0(1)
!	stop
      end if
      
      
      


	include 'dop_vs_pfw_1.inc'

!	dm0(1)=dm0_1_help


      return
      
      
c***********************************
      call write_data_in_time2(
     *	tt,tpl,betpj,eu,uli,r_cur,z_cur,p_sep,wel,wio,eksk,
     *	pcch,zeff_a,tec,te0(1),tqc,tq0(1),tene,zsep,c_e_old,c_e_new,
c     *  rmag,gamma,vs,q_95,q(2),zvel*10.,psi_pf,pmag_out,uact,
     *  rmag,gamma,vs,q_95,q(2),zvel*10.,psi_pf,pmag_out_1,uact,
     *  pf(1)/pf_turns(1),pf(2)/pf_turns(2),pf(3)/pf_turns(3),
     *  pf(4)/pf_turns(4),pf(5)/pf_turns(5),
     *  pf(6)/pf_turns(6),pf(7)/pf_turns(7),pf(8)/pf_turns(8),
     *  pf(9)/pf_turns(9),pf(10)/pf_turns(10),pf(11)/pf_turns(11),
     *  pf(12)/pf_turns(12),
     *  vchopper(1)*pf_turns(1)/1.e3,vchopper(2)*pf_turns(2)/1.e3,
     *  vchopper(3)*pf_turns(3)/1.e3,vchopper(4)*pf_turns(4)/1.e3,
     *  vchopper(5)*pf_turns(5)/1.e3,
     *  vchopper(6)*pf_turns(6)/1.e3,vchopper(7)*pf_turns(7)/1.e3,
     *  vchopper(8)*pf_turns(8)/1.e3,vchopper(9)*pf_turns(9)/1.e3,
     *  vchopper(10)*pf_turns(10)/1.e3,vchopper(11)*pf_turns(11)/1.e3,
     *  vchopper(12)/1.e3,
     *  r_lh,wdop,qtep,w_fusion,wae+waq,s_plasma/1.e4,p_sum,P_HL,zmag,
     *  vol_pl,epol,wen2)



c     *  wdop,qtep,w_fusion,
c     *  pf(2)/1.e3,pf(6)/1.e3,pf(8)/1.e3,pf(9)/1.e3,pf(11)/1.e3,
c     *  volume,z_tok,tokc)

c           print*,'from dop_port'
c           print*,'tt pf(10)/pf_turns(10) pf(10)/1000',
c     *  tt,pf(10)/pf_turns(10),pf(10)/1000
c	   read(*,*)


	
	                                   
        CAL=ptot/(WTOR+qc+WEL+WIO)                                      
71 	FORMAT(20X,A6/,(12(1pE10.3)))                                       
72 	FORMAT(5X,A60/,(1x,6(1pE11.3)))                                     
                
			  
	ptot=ptot_help
	if(abs(ptot).lt.1.e-5)ptot=0.d0
		                                                          
                                                                        
        return                                                          
      END                                                               
                                                                        
                                                                        
                                                                        
                                                                        
                                                                        
                                                                        
                                                                        
                                                                        
  
c********************************************************
      subroutine write_data_in_time2(
     *	tt,tpl,betpj,eu,uli,r_cur,z_cur,p_sep,wel,wio,eksk,
     *	pcch,zeff_a,tec,te_ax,tqc,tq_ax,tene,zsep,c_e_old,c_e_new,
     *  rmag,gamma,vs,q_95,q_ax,zvel,psi_pf,psi_ax,uact,
     *  pf1,pf2,pf3,pf4,pf5,pf6,pf7,pf8,pf9,pf10,pf11,
     *  pf12,
     *  v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,r_lh,wdop,
     *  qtep,w_fusion,w_alfa,s_plasma,p_sum,P_HL,zmag,
     *  vol_pl,epol,wen2)

c     *  wdop,qtep,w_fusion,
c     *  pf2,pf6,cs2L,cs1,cs2U,volume,z_tok,tokc,zvel_out)

	include 'double.inc'

	common /c_data_in_time2/i_c_data,i_c_data1
	                                 

	dimension uu(24)
	dimension uu1(5),uu2(17),uu3(6),uu4(5),dNB_xx(24)

	t=tt/1.e3
	p_cond=wel+wio


	i_en=i_en+1
        if(i_en.eq.1)then

	   open (unit=65,file='plasma.dat',
     *	form='formatted')

	   write(65,*)
     *'t,tpl/1000.,betpj,eu,uli,r_cur,z_cur,p_sep,eksk, 
     * pcch,zeff_a,tec,te_ax/tec,tqc,tq_ax/tqc,zsep,rsep,c_e,
     * rmag,zmag,gamma,vs,q_95,q_ax,zvel,psi_pf,psi_ax,uact,
     *  pf1,pf2,pf3,pf4,pf5,pf6,pf7,pf8,pf9,pf10,pf11,pf12,
     *  v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,
     *  tene,r_lh,wdop,qtep,w_fusion,w_alfa,s_plasma,p_sum,P_HL'

c     * wdop,qtep,w_fusion,pf2,pf6,cs2L,cs1,cs2U,volume 
c     * tokc zvel'
	else

		   open (unit=65,file='plasma.dat',
     *	access='append',form='formatted')


	end if

!	P_HL=9999

      do i=1,17
      uu2(i)=9.999e09
      end do

	if(i_c_data1.eq.1)then
	te_ratio=1.9146 
	tq_ratio=1.9054
	eksk=1.
	gamma=0.
	end if

	if(i_c_data1.eq.0)then
	te_ratio=te_ax/tec
	tq_ratio=tq_ax/tqc
	end if


        write(65,5002)
     *	t,tpl/1000.,betpj,eu,uli,r_cur,z_cur,p_sep,eksk, !=9
ccc     * pcch,zeff_a,tec,te_ax/tec,tqc,tq_ax/tqc,zsep,c_e_old,c_e_new,
     * pcch,pion,zeff_a,tec,te_ratio,tqc,tq_ratio,zsep,rsep,c_e_old,!=19
     * rmag,zmag,gamma,vs,q_95,q_ax,zvel,psi_pf,psi_ax,uact,!=29
     *  pf1,pf2,pf3,pf4,pf5,pf6,pf7,pf8,pf9,pf10,pf11,!=40
     *  zv1,zv2,zv3,zv4,zv5,zv6,zv7,zv8,zv9,zv10,zv11,  !51
     *  U_vs1,U_vs2,U_vs3,Curr_vs1,Curr_vs2,Curr_vs3,   !=57
     *  Ptotal,Pvs1,Pvs2,Pvs3, !=61

     *  tene/1000.,r_lh,wdop,qtep,w_fusion,w_alfa,s_plasma,p_sum,P_HL, !=70
     *  vol_pl,epol,wen2, !=73

     *  wtp,wtor,qc,w_imp,w_Be,w_W,w_Ar,w_Ne,gfus,rsep2,zsep2, !=84
     *  gaps_nga1,  !=85
     *  rsep2_r,zsep2_r,p_sep_tot,  !=88
     *  bz_left,bz_right,  !=90
     *  dist_min_xx,Rdist_min_xx,Zdist_min_xx,  !=93
     *  coef_He,coef_imp1,coef_imp2,coef_imp3,coef_imp4,  !=98
     *  dNB_xx  ! 

!     dNB_xx(24)

!!!     *  uu,uu1,uu3,uu4 !+55


c     *  cs3u,cs2u,cs1,cs2l,cs3l,pf1,pf2
c     * 	wdop,qtep,w_fusion,pf2,pf6,cs2L,cs1,cs2U,volume,
c     *  tokc,zvel

c	print*,'from victor_N'
c	print*,'tt pf10',tt,pf10
c	read(*,*)


!!! 5002   format (87(1pe12.4))
 5002   format (192(1x,1pe12.4e3))
!5002   format (87(1x,1pe12.4e3))
!6(1pe14.6e3)
	close (65)


!	call print3('vol_pl,epol,wen2=',vol_pl,epol,wen2)



	return
	end


      subroutine get_start_data(wdop_xx,tene_xx,wdh_xx)
      include 'double.inc'
      include 'new_com.inc'
      include 'br_com.inc'

        include 'par_imp.inc'
        include 'new_imp.inc'

	character *30 apr                                                      
	dimension a_print(200)
	
	wdop_xx=q_ech
	tene_xx=tay_ee
	wdh_xx=P_oh*v_p

	return
	end
