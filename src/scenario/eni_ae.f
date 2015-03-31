      SUBROUTINE ENIT_kav(N_x)
      	include 'double.inc'
	include 'new_com.inc'

	call ENIT_kav_c(N_x,
     *  i_ech,ro_bar,alf_bar,
     *  dxe_ext,dxq_ext,ajb_ext,ext_transp,key_ext,
     *  x_e_neo,x_i_neo,ft,
     *  dxe0,dxq0,ajb0)                                    

	return
	end
 
        SUBROUTINE ENIT_kav_c(N,
     *  i_ech,ro_bar,alf_bar,
     *  dxe_ext,dxq_ext,ajb_ext,ext_transp,key_ext,
     *  x_e_neo,x_i_neo,ft_i,
     *  dxe0,dxq0,ajb0)                                    
    	include 'double.inc'
        dimension dxe_ext(*),dxq_ext(*),ajb_ext(*),ext_transp(*),
     *  x_e_neo(*),x_i_neo(*),ft_i(*)

	dimension dxe0(*),dxq0(*),ajb0(*)
c--------------------------------------------
c   sources for energy equation and heat conductivities
c--------------------------------------------------
c        implicit real*8 (a-h,o-z)
	include 'parf0'
c
	common
     *  /mid2/vi(npo),spo(npo)
     *  /mid3/GRA1(npo),GRA2(npo)
     *  /mid6/bp_0(npo),a_m(npo),r_m(npo)
     *  /mid7/bsq(npo),bsqi(npo),fasp(npo)
	common
     *  /dfm2/PSI(npo),PFI(npo),DM0(npo),DMN(npo)
     *  /dfm3/dfmax(npo),dfmax0(npo)
     *  /dfm4/Q(npo),ANU(npo),P(npo),F(npo),PP(npo),PFF(npo)
     *  /dfm7/BT,UIND
     *  /dfm8/ajb(npo),sigk(npo)
     *  /dfm8e/ajbn(npo)
	common
     *  /ge1/PI
     *  /ge2/ntay,tay,ttb
     *  /ge3/AI(npo),AA0(npo),HA2(npo),a(npo),ha(npo)
     *  /ge5/kpr
     *  /ge6/zeff(npo),qpr(npo),ppr(npo),pr0,prg,zar
     *  /ge7/eu,rs,zact,elong
c
	COMMON
     *  /en1/PNE(npo),PD0(npo),PT0(npo),PH0(npo),PDN(npo),
     *  PTN(npo),PHN(npo)
     *  /en2/TE0(npo),TQ0(npo),TEN(npo),TQN(npo),WE0(npo),WQ0(npo)
     *  /en9/QE0(npo),QQ0(npo),QDG(npo)
     *  /en10/GGE(npo),GGEN(npo),DXE(npo),DXQ(npo),WU(npo),
     *  UG(npo),VG(npo)
     *  /en11/un(4),zn(2),ll,ken,ken1,ken2,noit
     *  /en12/pnal(npo),pnaln(npo),zalfa,talfa
     *  /en14/EMOE,EMOQ,NDOP,QDE0(npo),QDQ0(npo)
     *  /en15/QNET(npo)
     *  /en16/QTOR(npo),QDH(npo),QpE(npo),QpQ(npo)
     *  /en16e/qbeam(npo)
	common
     *  /en17/QAE(npo),QAQ(npo),SAL(npo),NAL
     *  /en18/pin(npo),pin0(npo),q11(npo),pal(npo)
     *  /en19/DD,DT,DH,SIN0,SINK,ALPY,Sss,Ppp,Eee
     *  /en20/PJ(npo),SB(npo)
     *  /en21/qce(npo)
     *  /en22/XII(npo)
     *  /en23/kk,tn0,pna,wie(npo),wcx(npo),tn(npo),pn(npo),pn0(npo)
     *  /en24/qen1,qen2,sumn,wen1,wen2
     *  /en25/zhib,tego
     *  /en26/del(npo)
     *  /en27/nij
     *  /en32/x_e(npo),x_i(npo)
     *  /en33/anom_e,anom_i,key_t11,kcchp
	common
     *  /keys8/ndh
c
	dimension pbe(npo),pbi(npo),dxei(npo),dxqi(npo),ajbi(npo),
     *  psi_nor(npo),dpsi(npo)

	dimension a_print(200)
	character *30 apr


c  ===
c   here the noclassical parameters are calculated
	flog1(pnx,tx)=23.4-1.15*13.*dlog10(pnx)+3.45*dlog10(tx)
	flog2(pnx,tx)=25.3-1.15*13.*dlog10(pnx)+2.3*dlog10(tx)
	fk1(z)=2.94333-0.75*z+0.106667*z**2
	fa1(z)=1.20333-0.21*z+2.66667e-2*z**2
	fb1(z)=1.8-0.869999*z+0.14*z**2
	fc1(z)=1.64333-0.669999*z+9.66665e-2*z**2
c
	fk2(z)=4.91334-0.850001*z+0.126667*z**2
	fa2(z)=0.64-8.00003e-2*z+0.01*z**2
	fb2(z)=1.05667-0.535*z+8.83333e-2*z**2
	fc2(z)=0.96-0.41*z+5.99999e-2*z**2
c
	fk3(z)=2.23333-0.47*z+6.66667e-2*z**2
	fa3(z)=0.85-0.195*z+0.025*z**2
	fb3(z)=0.42-0.115*z+0.015*z**2
	fc3(z)=0.77-0.125*z+0.015*z**2
c
	fkmn(fk0,fa0,fb0,fc0,ve0,epi)=fk0/(1.+fa0*dsqrt(ve0)+
     *  fb0*ve0)/(1.+fc0*ve0*epi**1.5)
c=======
      N2=N-1
      QE0(1)=0.
      QQ0(1)=0.
      DEL(1)=0.
	i=n/3

	do i=1,n                                                               
	dxei(i)=dxe(i)
	dxqi(i)=dxq(i)
	ajbi(i)=ajb(i)
	end do




	a_print(1)=bt
	a_print(2)=rs
	a_print(3)=eu
		
	n_pr=3
	apr='bt rs eu'
	num=25
c	call out42(n_pr,a_print,num,apr)


	do i=1,n
	a_print(i)=q(i)
	end do
		
	n_pr=n
	apr='q'
	num=25
c	call out42(n_pr,a_print,num,apr)


	do i=1,n
	a_print(i)=psi(i)
	end do
		
	n_pr=n
	apr='psi'
	num=25
c	call out42(n_pr,a_print,num,apr)



	do i=1,n 
	   psi_nor(i)=(dm0(1)-dm0(i))/(dm0(1)-dm0(n))
	end do

	do i=1,n
	a_print(i)=te0(i)
	end do
		
	n_pr=n
	apr='te0'
	num=25
!	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	do i=1,n
c	a_print(i)=tq0(i)
	end do
		
	n_pr=n
	apr='ti0'
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

c	return


	apr='te0'
c        print 71,apr,(te0(i),i=1,n)
	apr='tq0'
c        print 71,apr,(tq0(i),i=1,n)
	apr='pne'
c        print 71,apr,(pne(i),i=1,n)
	apr='pd0'
c        print 71,apr,(pd0(i),i=1,n)
	apr='pt0'
c        print 71,apr,(pt0(i),i=1,n)
	apr='ph0'
c        print 71,apr,(ph0(i),i=1,n)
	apr='tq0'
c        print 71,apr,(tq0(i),i=1,n)
	apr='zeff'
c        print 71,apr,(zeff(i),i=1,n)
	apr='q'
c        print 71,apr,(q(i),i=1,n)
c       zhib1=zhib*(0.1+ai(i)**2)
c ---->  Auxiliary heating power calculated (only in 17 point is deposited)
	summ=0.
	do i=2,n
	summ=summ+(1.-ai(i)**2)*2.*pi*vi(i)*ha(i)
	end do
	aemoe=emoe/summ
	aemoq=emoq/summ
c
	do i=2,n
           QDE0(I)=aEMOE*(1.-ai(I)**2)
           QDQ0(I)=aEMOQ*(1.-ai(i)**2)
c	if(ai(i).le.0.8)n_f=i
	end do

c-----------------------

C  HERE WE include ECH HEATING....


        if(i_ech.eq.1)then

c	print *,' call ECH1 and ECH2 here'

 	call ech1_heat()
        call ech2_heat()
	end if

	if(i_ech.eq.2)call ech0_heat()


	call aux_prof()
	call aux_prof_80()

ccc	open (unit=41,file='boot.dat',form='formatted')

ccc        write (41,*)n


        tok_b=0.
        tok_bo=0.
        tok_b1=0.
        tok_b2=0.
        tok_bs=0.
        s_plas=0.



c----------
	do i=1,n
	pbe(i)=pne(i)*te0(i)
	pbi(i)=(pd0(i)+pt0(i)+ph0(i))*tq0(i)
	end do

      DO 1 I=2,N
	dpbe=(pbe(i)-pbe(i-1))/( (pbe(i)+pbe(i-1))*0.5*ha(i))
	dpbi=(pbi(i)-pbi(i-1))/( (pbi(i)+pbi(i-1))*0.5*ha(i))
	dtbe=(te0(i)-te0(i-1))/( (te0(i)+te0(i-1))*0.5*ha(i))
	dtbi=(tq0(i)-tq0(i-1))/( (tq0(i)+tq0(i-1))*0.5*ha(i))
cccc	zeff(i)=(pd0(i)+pt0(i)+zar**2*ppr(i)+4.*pnal(i))/pne(i)
      PG=0.5*(PNE(I)+PNE(I-1))
      TGE=0.5*(TE0(I)+TE0(I-1))
      if(tge.le.0.)tge=1.
      if(pg.le.0.)pg=1.
	if(tgE.le.50.)qlog=flog1(pg,tgE)
	if(tgE.gt.50.)qlog=flog2(pg,tgE)
c------------
	qlog=16.
c--------------
c
C       ej=-0.267*rs*1.48*sqrt(eu/rs*ai(i))/psi(i)*1.e-3
C       ajb(i)=ej*(tgE*(pne(i)-pne(i-1))/ha(i)+0.285*pg*(te0(i)-te0(i-1))
C     */ha(i)-0.175*pg*(tq0(i)-tq0(i-1))/ha(i))

c
c
      POT=(2.*PD0(I)+3.*PT0(I)+1.*PH0(I))/PNE(I)
      TGI=0.5*(TQ0(I)+TQ0(I-1))
c--- V_ii term ....
c      VII=7.2E6/(SQRT(POT)*ABS(TGI)**1.5)*PG*zeff(i)**4*qlog/15.
      VII=7.2E6/(dSQRT(POT)*dABS(TGI)**1.5)*PG*qlog/15.
c---V-ei term ....
c	vei=vii*sqrt(1836.)*(tgi/tgE)**1.5/zeff(i)**2
	vei=vii*dsqrt(1836.d0)*(tgi/tgE)**1.5
c---V-ee term ....
	vee=vei/zeff(i)**2
c---
c  inverse aspect EPI ...
        EPI_0=AI(I)*eu/rs
c
	epi_m=a_m(i)/r_m(i)
      EPI=epi_m
c  W_i frequency ....
c      WI=9.57E3*BT*zeff(i)/POT*1.E3
      WI=9.57E3*BT/POT*1.E3
c  W_e frequency ....
      WE=1.76e7*BT*1.E3
c  V_i ion velocity ...
      VTI=dSQRT(1.9*dABS(TGI)/POT)*1.E6
c  v_e electrons velocity ...
	vte=dsqrt(1836.*tgE/tgi)*vti
c  V_i/W_i
      RI=VTI/WI
c
	bp0=-psi(i)/(2.*pi*rs)*gra1(i)
ccc      DI=RI**2*Q(I)**2/EPI**1.5*VII
	Q_I=epi*bt/bp0
c	print *,' q_i q(i)',q_i,q(i)
      DI=RI**2*Q_I**2/EPI**1.5*VII
c
      VI0=dSQRT(2.d0)*Q(I)*RS*VII/(VTI*EPI**1.5)
c
c  V_e/W_e
      RE=VTE/WE
c
      DE=RE**2*Q(I)**2/EPI**1.5*VEE
c
c****   ve0=sqrt(2.)*q(i)*rs*vei/(vte*epi**1.5)
	ve0=dsqrt(2.d0)*q(i)*rs*vee/(vte*epi**1.5)
c
	a1e=dpbe-2.5*dtbe+tgi/tgE/zeff(i)*(dpbi-1.17/(
     *1.+ve0**2*epi**2)*dtbi)
	bp0=-psi(i)/(2.*pi*rs)*gra1(i)
	bp0_d=epi*bt/q(i)

c	print *,' i epi_0 epi_m',i,epi_0,epi_m
c	print *,' i bp0 bp0_d=bp_0(i)=',i,bp0,bp0_d,bp_0(i)
c
	z=zeff(i)
	fk0=fk1(z)
	fa0=fa1(z)
	fb0=fb1(z)
	fc0=fc1(z)
	kpe=0
	if(ve0.lt.0.)kpe=1
	if(kpe.eq.0)go to 700

	apr='kpe'
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

c	print *,'rs epi eu',rs,epi,eu
c	print*,'vei',vei,'vte',vte,'ve0',ve0,'epi',epi
c	print*,'vii',vii,'pg',pg,'glog',qlog
700     continue
	fk13=fkmn(fk0,fa0,fb0,fc0,ve0,epi)
c
	fk0=fk2(z)
	fa0=fa2(z)
	fb0=fb2(z)
	fc0=fc2(z)
	fk23=fkmn(fk0,fa0,fb0,fc0,ve0,epi)
c
	fk0=fk3(z)
	fa0=fa3(z)
	fb0=fb3(z)
	fc0=fc3(z)
	fk33=fkmn(fk0,fa0,fb0,fc0,ve0,epi)
c
	dup=fk33*dsqrt(epi)
c ----> here neoclassical conductiviy is calculated. ## dup is correction #
c       sigk(i)=1.-dup
c-----------------------------------------------------------
	ft=1.-(1.-epi)**2/(dsqrt(1.-epi**2)*(1.+1.46*dsqrt(epi)))
	enu=0.6913*qlog*rs*q(i)*pg/(tge**2*epi*dsqrt(epi))
	cr=0.56/zeff(i)*(3.-zeff(i))/(3.+zeff(i))
	xsi=0.58+0.2*zeff(i)
	ale=3.4/zeff(i)*(1.13+zeff(i))/(2.67+zeff(i))
	sigk(i)=0.5*ale*(1.-ft/(1.+xsi*enu))
     *  *(1.-cr/(1.+xsi*enu))
c       sigk(i)=1.-1.31*1.48*sqrt(eu/rs*ai(i))
c
c
c
c-----> bootstreap current density
	ajb(i)=-0.16e-3*pg*tge*dsqrt(epi)/bp0*(fk13*a1e+fk23*
     *dtbe)*2.*pi*rs*1.e-4/2.

c===================

c===================
c  pressure and derivatives ...
	p_e=0.5*(pbe(i)+pbe(i-1))
	p_i=0.5*(pbi(i)+pbi(i-1))
	p_ed=(pbe(i)-pbe(i-1))/(psi(i)*ha(i))
	p_id=(pbi(i)-pbi(i-1))/(psi(i)*ha(i))
c temperature and derivatives ....
	t_e=0.5*(te0(i)+te0(i-1))
	t_i=0.5*(tq0(i)+tq0(i-1))
	t_ed=(te0(i)-te0(i-1))/(psi(i)*ha(i))
	t_id=(tq0(i)-tq0(i-1))/(psi(i)*ha(i))
c density
	d_e=0.5*(pne(i)+pne(i-1))
	d_i=d_e

	d_ed=(pne(i)-pne(i-1))/(psi(i)*ha(i))
	d_id=d_ed

c
	xft=ft/(1.-ft)
	dxft=1.414*zeff(i)+zeff(i)**2+xft*(0.754+2.657*zeff(i)+
     *  2.*zeff(i)**2)+xft**2*(0.348+1.243*zeff(i)+zeff(i)**2)
	alft=-1.172/(1.+0.462*xft)
	pl31=(0.745+2.21*zeff(i)+zeff(i)**2+xft*(0.348+1.243*zeff(i)+
     *  zeff(i)**2))/dxft
	pl32=(0.884+2.074*zeff(i))/dxft
	a1e=p_ed/p_e
	a1i=p_id/p_i
	a2e=t_ed/t_e
	a2i=t_id/t_i

c!!! OLD	cinv=1./(zeff(i)*t_e/t_i)


	cinv=p_i/p_e


c  F---f(i)*rs*1.e-3
	pl310=pl31*(f(i)*rs*1.e-3)*p_e*xft
	pl320=-pl32*(f(i)*rs*1.e-3)*p_e*xft
c
	a13=0.027*zeff(i)**2-0.211*zeff(i)+1.204
	a23=0.01*zeff(i)**2-0.008*zeff(i)+0.64
	b13=0.14*zeff(i)**2-0.87*zeff(i)+1.8
	b23=0.088*zeff(i)**2-0.535*zeff(i)+1.057
	c13=0.097*zeff(i)**2-0.67*zeff(i)+1.643
	c23=0.06*zeff(i)**2-0.41*zeff(i)+0.96
c
	ve0h=ve0*epi**1.5
	vi0h=vi0*epi**1.5
c
	f1=(1.+a13*dsqrt(ve0)+b13*ve0)*(1.+c13*ve0h)
	pl31=pl310/f1
	f2=(1.+a23*dsqrt(ve0)+b23*ve0)*(1.+c23*ve0h)
	pl32=(pl320+2.5*pl310)/f2-2.5*pl31
	fa=(1.+vi0h**2)*(1.+ve0h**2)
	alfi=( (alft+0.35*dsqrt(vi0))/(1.+0.7*dsqrt(vi0))+
     *  2.1*vi0h**2)/fa
c
	bstrap=(pl31*( a1e+cinv*(a1i+alfi*a2i) )+pl32*a2e)
c= = = = =
	ajbn(i)=pl310*(a1e+cinv*(a1i+alft*a2i))+pl320*a2e
c  p-- 1.6 psi-- 1.*pi*1.e5 ...
	ajbn(i)=ajbn(i)*(1.6*2.*pi*1.e+5)
	bstrap=bstrap*(1.6*2.*pi*1.e+5)
c  [ a/m**2*Tl] --> [kA/cm**2*kG] 1.e-3/1.e+4*10. --
	ajbn(i)=ajbn(i)*(1.e-7*10.)
	bstrap=bstrap*(1.e-7*10.)
c
	ajbn(i)=ajbn(i)/bt
	bstrap=bstrap/bt
	ajbn(1)=0.
	ajbn(2)=0.5*ajbn(3)
cc        print *,'i ajb ajbn bstrap',i,ajb(i),ajbn(i),bstrap
c	ajb(i)=ajbn(i)
c	ajb(2)=ajbn(2)
c


c-----------------------------  NEW BOOTSTREAP---

      pzion=zeff(i)

      pR=r_m(i)*0.01
c      pft=1.-ft
      pft=ft

      ft_i(i)=ft

c R_pe=p_e/p
      r_pe=p_e/(p_e+p_i)


      pl31_h=pl31

      call BSCOEFF(pft,q(i),pR,epi,t_e,d_e,t_i,
     * d_i,zeff(i),pzion, 
     * pl31,pl32,pl34,palfa,
     * znuestar,znuistar)

c      print *,' i pl31,pl31_h pl31_hh',
c     *pl31,pl31_h,pl31_hh

c      print *,' i pl31,pl32,pl34,palfa ',
c     *pl31,pl32,pl34,palfa

c      print *,' i sigk',i,sigk(i)

        
        c_boot=2.*pi*1.6*0.01
c        c_boot=5.*1.6*0.01


      ajb_n=c_boot*(0.1*f(i)*rs*0.01)*(p_e+p_i)*pl31*d_ed/d_e

      ajb_te=c_boot*(0.1*f(i)*rs*0.01)*(p_e+p_i)*
     * r_pe*(pl31+pl32)*t_ed/t_e

      ajb_ti=c_boot*(0.1*f(i)*rs*0.01)*(p_e+p_i)*
     *(1.-r_pe)*(1.+pl34/pl31*palfa)*pl31*t_id/t_i 

      ajb_sa=c_boot*(0.1*f(i)*rs*0.01)*(p_e+p_i)*(pl31*d_ed/d_e+
     * r_pe*(pl31+pl32)*t_ed/t_e+
     *(1.-r_pe)*(1.+pl34/pl31*palfa)*pl31*t_id/t_i )




      ajb_n=ajb_n/(bt*0.1)
      ajb_te=ajb_te/(bt*0.1)
      ajb_ti=ajb_ti/(bt*0.1)
      ajb_sa=ajb_sa/(bt*0.1)


	a_print(1)=i
	a_print(2)=pbi(i)
	a_print(3)=pbe(i)
	a_print(4)=pne(i)
	a_print(5)=pd0(i)
	a_print(6)=pt0(i)
		
	n_pr=6
	apr='i pbi pbe pne pd0 pt0=='
	num=25


c	call out42(n_pr,a_print,num,apr)


	a_print(1)=pft
	a_print(2)=q(i)
	a_print(3)=pr
	a_print(4)=epi
	a_print(5)=t_e
	a_print(6)=d_e
	a_print(7)=t_i
	a_print(8)=d_ed
	a_print(9)=zeff(i)
	a_print(10)=pl31
	a_print(11)=pl32
	a_print(12)=pl34
	a_print(13)=palfa
		
	n_pr=13
	apr='pft,q(i),pR,epi,t_e,d_e,t_i,d_ed'
	num=25

c	call out42(n_pr,a_print,num,apr)

c      write (41,5000)pft,q(i),pR,epi,t_e,d_e,t_i,d_ed,
c     * zeff(i),pl31,pl32,pl34,palfa,
c     * znuestar,znuistar

c      write (41,5000)f(i),rs,p_e,p_i,r_pe,t_ed,t_id,ajb_sa


	a_print(1)=f(i)
	a_print(2)=rs
	a_print(3)=p_e
	a_print(4)=p_i
	a_print(5)=r_pe
	a_print(6)=d_e
	a_print(7)=t_ed
	a_print(8)=t_id
	a_print(9)=ajb_sa
		
	n_pr=9
	apr='f(i),rs,p_e,p_i,r_pe,t_ed,t_id,ajb_sa'
	num=25

c	call out42(n_pr,a_print,num,apr)




c      print *,' i ajb_n ajb_te ajb_ti ',
c     * i,ajb_n,ajb_te,ajb_ti


c      print *,' i ajb_sa ajb ajbn bstrap',
c     * i,ajb_sa,ajb(i),ajbn(i),bstrap

c      ajb(i)=ajbn(i)


      tok_bs=tok_bs+ajb_sa*spo(i)*ha(i)

      s_plas=s_plas+spo(i)*ha(i)

      tok_b=tok_b+ajb(i)*spo(i)*ha(i)
      tok_b1=tok_b1+ajbn(i)*spo(i)*ha(i)
      tok_b2=tok_b2+bstrap*spo(i)*ha(i)

      ajb(i)=ajb_sa

      tok_bo=tok_bo+ajb(i)*spo(i)*ha(i)

c      ajb(i)=ajbn(i)

      if(ajb(i).le.0.)ajb(i)=0.

c



c
c=========================
c
c
c
c
c neoclassical ions ....
      PKI_old=0.66*(1./(1.+1.03*dSQRT(VI0)+0.31*VI0)+1.77*EPI**1.5*
     *VI0/(1.+0.74*EPI**1.5*VI0))
c----
      PKIS=(0.66+1.88*dsqrt(epi)-1.54*epi)*bsq(i)
      PKI=0.66*( pkis/0.66/(1.+1.03*dSQRT(VI0)+0.31*VI0)+1.77*EPI**1.5*
     *VI0*fasp(i)/(1.+0.74*EPI**1.5*VI0))
c----->  neoclassical ion heat conductivity DXQ
      DXQ(I)=1.5*zeff(i)*PKI*DI*1.E-3*GRA2(I)
c  in m2/s----++++
      x_i_neo(I)=0.1*1.5*zeff(i)*PKI*DI*1.E-3
      x_i(I)=0.1*PKI*DI*1.E-3
c      print *,' i epi pki_o pki  x_i =',i,epi,pki_old,pki,x_i(i)
c
c  anomalous factor anom_i for ions...
      DXQ(i)=anom_i*DXQ(i)
      x_i(i)=anom_i*x_i(i)
c
c
      PKE=0.66*(1./(1.+1.03*dSQRT(VE0)+0.31*VE0)+1.77*EPI**3*
     *VE0/(1.+0.74*EPI**1.5*VE0))

c  in m2/s----++++
      x_e_neo(I)=0.1*PKE*DE*1.E-3

c----->  neoclassical electrons ...
      if(key_t11.eq.1.or.key_t11.eq.2)then
      DXE(I)=PKE*DE*1.E-3*GRA2(I)
c  in m2/s----++++
      x_e(I)=0.1*PKE*DE*1.E-3
      end if
c
c
c----->  TAY_ei exchange term
      DEL(I)=700.*PG**2*zeff(i)**2/POT/dABS(TGE)**1.5

c      DEL(I)=0.d0


c
c
c-----> joul heating term QDH
c        QDH(I)=QDG(I)/ABS(TGE)**1.5/sigk(i)
         QDH(I)=QDG(I)
c
c
c----> breamstruggling power QTOR
      QTOR(I)=1.E-3*PG**2*dSQRT(dABS(TGE))*ZEFF(i)**2
c
c
	xt=710.*eu/(rs*dsqrt(tgE))
	fi=2.e-8*tgE**1.5*dsqrt(bt/(eu*pne(i)))*dsqrt(1.+xt)
c-----> cyclotron power qce
	qce(i)=0.265e-5*bt*bT*tgE*fi
C*****************
      TETI=TQ0(I)/93800.
      Sech=2.56*TQ0(I)**(-2./3.)*
     *(1.+7.*TETI**(3./4.))/(1.+242.*TETI**
     *(13./4.))**0.5*dEXP(-200./TQ0(I)**(1./3.))
c------> alfa particle source SAL
      SAL(I)=SEch*PD0(I)*PT0(I)
	pnal(i)=(sal(i)+pnaln(i)/tay)/(1./tay+1./talfa)
c
c----->  neutron power QNET
      QNET(I)=14.6E6*SAL(I)
c
      ZA1=4./POT**(2./3.)
      Z1=(DD*2.+DT*3.+DH*1.)/POT**(2./3.)
      ENA1=14.8*TE0(I)*ZA1
      EN1=14.8*TE0(I)*Z1
      uA=ENA1/3.5E6
      u=EN1/Eee
      uAS=DSQRT(uA)
      uS=DSQRT(u)
      AAl=uA*(0.6+1./3.*dLOG((1.-uAS+uA)/(1.+uAS)**2)+1.1547*
     *DATAN((2.-uAS)/DSQRT(3.d0)/uAS))
      Al=u*(0.6+1./3.*DlOG((1.-uS+u)/(1.+uS)**2)+1.1547*
     *DATAN((2.-uS)/DSQRT(3.d0)/uS))
c
c-----> retardation of Alfa particles is calculated
	ts=6.27e-2/qlog*tge**1.5/pg
	pin(i)=(pin0(i)+sal(i)*tay)/(1.+2.*tay/ts)
	q11(i)=3.5e6/ts*2.*pin(i)
	pal(i)=2./3.*q11(i)*ts
c-------> alfa particles power transfer to electrons QAE
cccc       QAE(I)=(1.-AAl)*q11(I)
c
c-------> alfa particles power transfer to ions QAQ
cccc       QAQ(I)=AAl*q11(I)
c
       QAE(I)=3.5E6*(1.-AAl)*SAL(I)
       QAQ(I)=3.5E6*AAl*SAL(I)
c---> power transfer from neutral beam to electrons QPE
ccc      QpE(I)=Eee*(1.-Al)*SB(I)
      QpE(I)=(1.-Al)*qbeam(I)
c----> power transfer from neutral beam to ions QPQ
ccc      QpQ(I)=Eee*Al*SB(I)
      QpQ(I)=Al*qbeam(I)
c
c---> electrons energy source
	nal=1
c	print *,' nal ndop ',nal,ndop

        QE0(I)=ndh*QDH(I)-QTOR(I)+QpE(I)*NIJ+
     *  QAE(I)*NAL+QDE0(I)*NDOP
c---> ions energy source
      QQ0(I)=QpQ(I)*NIJ +QAQ(I)*NAL+QDQ0(I)*NDOP
c******************************************
c   here tego is only parameter
c-----> parabolic profile in heat conductivity
c       if(i.ge.n/3)higo=zhib/tego*(0.1+ai(i)**2)*eu*eu


	higo=zhib/tego*(0.3+ai(i)**2)*eu*eu

c	higo=zhib/tego*ai(i)**2*eu*eu


c-----> heat coductivity is constant
c       if(i.lt.n/3)higo=zhib1/tego*eu*eu

c!!!        higo=zhib/tego*eu*eu


c**********************************************************
	if(key_t11.eq.0.or.key_t11.gt.3)then
c	higo=zhib/tego*ai(i)*eu*eu
	higo=zhib/tego*(0.3+ai(i)**2)*eu*eu
c	higo=zhib/tego*ai(i)**2*eu*eu
	xig=higo
	x_e(i)=0.1*xig
	dxe(i)=xig*gra2(i)
	end if


	if(key_t11.eq.3)then
	higo2=zhib/tego*ai(i)**2*eu*eu*(te0(i)/te0(1))
	xig2=higo2
	x_e(i)=0.1*xig2
	dxe(i)=xig2*gra2(i)

	end if

c
c---------  RADIAL DEPENDENT T-11 SCALING for X_e..
c       te11=3.5e-5*(ai(i)*eu/rs)**0.25*q(n)*pcch*rs**3/sqrt(tec)
c


c	i02=0.1*n
c	if(i.ge.i01)then 
c         x11=1.e4*sqrt(tge/pot)*((ai(i)*eu/rs)**1.75)/(q(i)*pg*rs)
c	else
c         x11=1.e4*sqrt(tge/pot)*((ai(i02)*eu/rs)**1.75)/(q(i)*pg*rs)
c	end if

!	x11=1.e4*sqrt(tge/pot)*((ai(i)*eu/rs)**1.75)/(q(i)*pg*rs)

        a_mi=0.5*(a_m(i)+a_m(i-1))
        r_mi=0.5*(r_m(i)+r_m(i-1))
        qi=0.5*(q(i)+q(i-1))
	x11=1.e4*dsqrt(tge/pot)*((a_mi/r_mi)**1.75)/(qi*pg*r_mi)

	if(psi_nor(i).ge.ro_bar)then 
           i05=1
        else
           i05=0
        end if

c	i05=ro_bar*n

	if(i05.eq.1)x11=x11*alf_bar

c	if(i05.eq.1)ajb(i)=0.




c
c  in m2/s
	if(key_t11.eq.1)then
	x11=x11*anom_e
	x_e(i)=0.1*x11+3.*x_e(i)
	dxe(i)=x11*gra2(i)+3.*dxe(i)
	end if

	if(key_t11.eq.2)then
	x_e(i)=0.1*x11+3.*x_e(i)
	dxe(i)=x11*gra2(i)+3.*dxe(i)

	dxe(i)=dxe(i)*zhib

	end if
c        print *,'i dxe dxq',i,dxe(i),dxq(i)
c
c---------
c-----> duffusivity is xii=dxe*0.2 to use real transport ...
	XII(I)=DXE(I)
c-----> duffusivity is DXe*1.e-5 to use give profiles
	if(kcchp.eq.1)XII(I)=DXE(I)*1.e-1
c	if(kcchp.eq.1)XII(I)=DXE(I)
c----->ion heat conductivity is equal to electron heat conductivity
c      dxq(i)=dxe(i)
c----->ion h cond is equal to elec +2* neocl.
c       dxq(i)=dxe(i)+2.*dxq(i)
c
    1 CONTINUE
c       here cold neutals included CALL NETR
c       if(noit.eq.0)
c     * CALL NETR(PNA,TN0,WIE,WCX,TN,PN,PN0,N,KK)
	do i=2,n
c       if(te0(i).ge.20.)qu=7.3e5*dexp(-0.094*te0(i))/16.
c       if(te0(i).lt.20.)qu=1.e2*dexp(0.35*te0(i))/16.
c electron ionization ligt wie (cold neutrals)
	wie(i)=0.
c change-exange on  ions (cold neutrals)
	wcx(i)=0.
c---> impurity ligh qpr (here oxigen)
c       qpr(i)=qu*ppr(i)*pne(i)
c       qe0(i)=qe0(i)-qpr(i)
c       qe0(i)=qe0(i)-wie(i)
c       qq0(i)=qq0(i)-wcx(i)
	end do
   71 FORMAT(20X,A6/,(6(1pE10.3)))
c   increased heat conductivity
	do i=n-3,n
c       dxe(i)=(1.+ai(i)*1.e2)*dxe(i)
c       dxq(i)=(1.+ai(i)*1.e2)*dxe(i)
	end do
c
	do i=2,n
	   if(ai(i).gt.0.3)then
	      nf=i
	      go to 5
	      end if
	end do
 5      continue
c
c	x_e(1)=x_e(2)
c	x_i(1)=x_i(2)
c	do i=2,nf
c       x_e(i)=x_e(nf)
c        dxe(i)=x_e(i)*10.*gra2(i)
c	end do
c
	apr='del'
c        print 71,apr,(del(i),i=1,n)
	apr='dxe'
c        print 71,apr,(dxe(i),i=1,n)
	apr='dxq'
c        print 71,apr,(dxq(i),i=1,n)
	apr='Qe0'
c        print 71,apr,(qe0(i),i=1,n)
	apr='Qq0'
c        print 71,apr,(qq0(i),i=1,n)

        if(kpr.eq.1)print *,' ro_bar alf_bar ',ro_bar,alf_bar


        if(kpr.eq.1)print *,' tok_bs tok_b tok_b1 tok_b2 ',tok_bs,tok_b,
     *  tok_b1,tok_b2

        ajb(2)=0.5*ajb(3)

        
        do i=2,n
c           QE0(I)=ndh*QDH(I)
        end do
c        print *,' key_ext ext_trans 2 3 4',key_ext,(ext_transp(i),i=2,4)

	if(key_ext.eq.0)then

	do i=1,n                                                               
	dxe0(i)=dxe(i)
	dxq0(i)=dxq(i)
	ajb0(i)=ajb(i)
	end do

	do i=1,n                                                               
!	dxe(i)=dxei(i)
!	dxq(i)=dxqi(i)
!	ajb(i)=ajbi(i)
	end do
	

	end if




      if(key_ext.eq.1)then

	apr='x_e'
c        print 71,apr,(x_e(i),i=1,n)
	apr='dxe_ext'
c        print 71,apr,(dxe_ext(i),i=1,n)
	apr='x_i'
c        print 71,apr,(x_i(i),i=1,n)
	apr='dxq_ext'
c        print 71,apr,(dxq_ext(i),i=1,n)

	apr='ajb'
c        print 71,apr,(ajb(i),i=1,n)

        if(ext_transp(2).gt.0.)then
           do i=1,n
              dxei(i)=dxe(i)
              dxe(i)=10.*dxe_ext(i)*gra2(i)
           end do
	apr='dxei'
c        print 71,apr,(dxei(i),i=1,n)
	apr='dxe'
c        print 71,apr,(dxe(i),i=1,n)
        end if
        if(ext_transp(3).gt.0.)then
           do i=1,n
              dxqi(i)=dxq(i)
              dxq(i)=10.*dxq_ext(i)*gra2(i)*anom_i
           end do
	apr='dxqi'
c        print 71,apr,(dxqi(i),i=1,n)
	apr='dxq'
c        print 71,apr,(dxq(i),i=1,n)
        end if
        if(ext_transp(4).gt.0.)then
           do i=1,n
              ajb(i)=ajb_ext(i)
           end do
        end if
c        if(ext_transp(6).gt.0.)then
c           do i=1,n
c              dxe(i)=dxe(i)*zhib
c           end do
c        end if
           


        end if

	apr='ajb_ext'
c        print 71,apr,(ajb_ext(i),i=1,n)
 	apr='ajb'
c        print 71,apr,(ajb(i),i=1,n)
 	apr='te0'
c        print 71,apr,(te0(i),i=1,n)
 	apr='tq0'
c        print 71,apr,(tq0(i),i=1,n)
 	apr='pne'
c        print 71,apr,(pne(i),i=1,n)


	do i=1,n
	a_print(i)=ajb(i)
	end do
	n_pr=n
	apr='ajb '
c	call out42(n_pr,a_print,num,apr)


 	apr='dpsi'
c        print 71,apr,(dpsi(i),i=1,n)

!	if(key_ext.eq.1)then
	if(key_ext.eq.-1)then
	num=20


	do i=1,n
	a_print(i)=dxe(i)
	end do
	n_pr=n
	apr='dxe '
c	call out42(n_pr,a_print,num,apr)

	do i=1,n
	a_print(i)=dxq(i)
	end do
	n_pr=n
	apr='dxq '
c	call out42(n_pr,a_print,num,apr)

	do i=1,n
	a_print(i)=ajb(i)
	end do
	n_pr=n
	apr='ajb '
c	call out42(n_pr,a_print,num,apr)

	end if

5000    format (6(1pe14.6))                                             

c      close(41)



      RETURN
      END
c
      subroutine ech0_heat()
      	include 'double.inc'
      include 'new_com.inc'

      call ech0_heat_c(n,
     *  qde0,sb_ech)

      return
      end


      subroutine ech0_heat_c(n,
     *  qde0,sb_ech)
      	include 'double.inc'

      dimension qde0(*),sb_ech(*)

      character*20 apr

      do i=2,n
         qde0(i)=qde0(i)+sb_ech(i)
      end do

      apr='sb_ech'
c      print 71,apr,(sb_ech(i),i=1,n)

      apr='qde0'
c      print 71,apr,(qde0(i),i=1,n)

   71 FORMAT(20X,A6/,(6(1pE10.3)))
      
      return
      end
      subroutine ech1_heat()
      	include 'double.inc'
      include 'new_com.inc'

      call ech1_heat_c(n,
     *  qde0,sb_ech1)

      return
      end


      subroutine ech1_heat_c(n,
     *  qde0,sb_ech1)
    	include 'double.inc'
      dimension qde0(*),sb_ech1(*)

      character*20 apr

      do i=2,n
         qde0(i)=qde0(i)+sb_ech1(i)
      end do

      apr='sb_ech1'
c      print 71,apr,(sb_ech1(i),i=1,n)

      apr='qde0'
c      print 71,apr,(qde0(i),i=1,n)

   71 FORMAT(20X,A6/,(6(1pE10.3)))
      
      return
      end
      subroutine ech2_heat()
      	include 'double.inc'
      include 'new_com.inc'

      call ech2_heat_c(n,
     *  qde0,sb_ech2)

      return
      end


      subroutine ech2_heat_c(n,
     *  qde0,sb_ech2)
    	include 'double.inc'
      dimension qde0(*),sb_ech2(*)

      character*20 apr

      do i=2,n
         qde0(i)=qde0(i)+sb_ech2(i)
      end do

      apr='sb_ech2'
c      print 71,apr,(sb_ech2(i),i=1,n)

      apr='qde0'
c      print 71,apr,(qde0(i),i=1,n)

   71 FORMAT(20X,A8/,(6(1pE10.3)))
      
      return
      end

      SUBROUTINE BSCOEFF(pft,pq,pR,peps,pte,pne,pti,pni,pzeff,pzion, 
     * pl31,pl32,pl34,palfa,
     * znuestar, znuistar)
    	include 'double.inc'
c     * pl31_0,pl32_0,palfa_0,pl31,pl32,pl34,palfa)
!
!     WARNING: in MKSA
!
!     Compute Bootstrap coefficients using formulas from 
! O. Sauter et al, Phys. Plasmas 7 (1999) 2834.
!
!     Assumes to compute on a single flux surface with:
! Inputs:
!     pft   : trapped fraction
!     pq    : safety factor
!     pR    : Geometrical center of given flux surface in [m]
!     peps  : Inverse aspect ratio of given flux surface
!     pte   : Electron temperature [eV]
!     pne   : Electron density [1/m**3]*1.e-19
!     pti   : Ion temperature [eV]
!     pni   : Main ion density [1/m**3]*1.e-19
!     pzeff : Effective charge (used for Z in electronic terms)
!     pzion : Main ion charge
! Outputs:

!     pl31_0  : L31 coefficient assuming nuestar=0
!     pl32_0  : L32 coefficient assuming nuestar=0
!     palfa_0 : Alfa coefficient assuming nuestar=0

!     pl31    : L31 coefficient
!     pl32    : L32 coefficient
!     pl34    : L34 coefficient (L34 for nuestar=0 is identical to L31_0)
!     palfa   : Alfa coefficient
!
!
        include 'double_eni_ae1.inc'
!     
!     basic parameters
!
      zlnlam_e = 17.
      IF (pne.gt.0. .AND. pte.gt.0.) THEN
         zlnlam_e = 31.3 - dlog(dsqrt(1.e19*pne)/pte)
      ENDIF

      zlnlam_i = 17.
      IF (pni.gt.0. .AND. pti.gt.0.) THEN
         zlnlam_i = 30. - dlog(pzion**3.*dsqrt(1.e19*pni)/
     *  dABS(pti)**1.5)
      ENDIF

c      print *,' zlnlam_e zlnlam_i=',zlnlam_e,zlnlam_i

      znuestar = 6.921E+1 * pq*pR*pne*pzeff*zlnlam_e 
     */ (pte*pte*peps**1.5)

      znuistar = 4.900E+1 * pq*pR*pni*pzion**4*zlnlam_i 
     */ (pti*pti*peps**1.5)

c      print *,' znuestar=',znuestar
c      print *,' znuistar=',znuistar


!     finite nustar
      call neobscoeff(pl31,pl32,pl34,palfa,pft,pzeff,znuestar,znuistar)

c      call sigmaneo(signeo,sigsptz,znuestar,pft,pne,pte,pzeff,
c     * pq,pR,peps)

c      print *,' signeo sigsptz =',signeo,sigsptz

     

!
      return
      end


!
!      MODULE neobscoeffmod
!
! Compute neoclassical bootstrap current coefficients for given 
! collisionalities using formula in Ref.1:
!             O. Sauter et al, Phys. Plasmas 6 (1999) 2834.
! Inputs:
!    ft: trapped fraction ft (Note, one can use formula in 
! YR Lin-Liu et al, Phys. Plasmas 2 (1995) 1666.)
! Optionals:
!    Zeff : effective charge (default = 2. if omitted)
!    nuestar : local electron collisionality (Eq. 18b of Ref. 1 
! or 0. for comparison) (0. if omitted)
!    nuistar : local ion collisionality (Eq. 18c of Ref. 1 or 0. 
! for comparison) (0. if omitted)
!    Nin : number of input values (if not given assumes dim. of input 
! arrays for vectors or 1 for scalars)
!
! Outputs:
!    L31, L32, L34, alfa : as defined in Ref.1, Eqs. (14-17)
!
! examples of calls:
!
! call neobscoeff(L31, L32, L34, alfa, ft, Zeff)
! call neobscoeff(L31, L32, L34, alfa, ft, Zeff, nuestar, nuistar)
! call neobscoeff(L31, L32, L34, alfa, ft, Zeff, Nin)
! call neobscoeff(L31, L32, L34, alfa, ft, NUESTAR=nuestar,NIN=Nin)
!
! To use this module in a routine, include the follwing statement 
! at the beginning of the routine:
! USE neobscoeffmod
!
      
      SUBROUTINE neobscoeff(L31, L32, L34, ALFA, ft, 
     *  Zeff, nuestar, nuistar)
        include 'double.inc'
    
! CASE: all are scalar input variables (nin not used)
!       Note: if called with arg as ft(i), it is a scalar 
! and goes through this routine

       include 'double_eni_ae2.inc'

      ZZ = zeff
      znuestar = nuestar
      znuistar = nuistar
!
      zsqnuest = dsqrt(znuestar)
!
!  effective trapped fractions
!
      zsqnuest = dsqrt(znuestar)

      zft31eff = ft / (1.+(1.-0.1*ft)*zsqnuest 
     * + 0.5*(1.-ft)*znuestar/ZZ)

      zft32ee_eff = ft / (1. + 0.26*(1.-ft)*zsqnuest 
     * + 0.18*(1.-0.37*ft)*znuestar/dsqrt(ZZ))

      zft32ei_eff = ft / (1. + (1.+0.6*ft)*zsqnuest 
     * + 0.85*(1.-0.37*ft)*znuestar*(1.+ZZ))

      zft34eff = ft / (1.+(1.-0.1*ft)*zsqnuest 
     * + 0.5*(1.-0.5*ft)*znuestar/ZZ)

      zalfa0 = - 1.17*(1.-ft) / (1.-0.22*ft-0.19*ft**2)
!
!coefficients
!
      zeffp1 = ZZ+1.

      L31 = zft31eff * ( (1.+1.4/zeffp1) 
     * - zft31eff* (1.9/zeffp1 - zft31eff * (0.3/zeffp1 + 
     * 0.2/zeffp1 * zft31eff)))

      L32 = (0.05+0.62*ZZ)/ZZ/(1.+0.44*ZZ)*(zft32ee_eff-
     *  zft32ee_eff**4) 
     * +  zft32ee_eff**2*(1.-1.2*zft32ee_eff+0.2*zft32ee_eff**2) 
     * /(1.+0.22*ZZ) 
     * - (0.56+1.93*ZZ)/ZZ/(1.+0.44*ZZ)*(zft32ei_eff-zft32ei_eff**4) 
     * +  zft32ei_eff**2*(1.-0.55*zft32ei_eff-0.45*zft32ei_eff**2) 
     * * 4.95/(1.+2.48*ZZ)

c  This lines were added in June 2003 in CRPP by RRK

     * + 1.2/ (1.+0.5*ZZ) * (zft32ee_eff**4-zft32ei_eff**4)



      L34 = zft34eff * ( (1.+1.4/zeffp1) 
     *  - zft34eff* (1.9/zeffp1 - zft34eff * (0.3/zeffp1 + 
     *  0.2/zeffp1 * zft34eff)))

      zsqnui = dsqrt(znuistar)

      znui2ft6 = znuistar**2 * ft**6

      ALFA = ((zalfa0 + 0.25*(1.-ft**2)*zsqnui) 
c!!!!!!  OLD VERSION     * / (1.+0.5*zsqnui) - 0.315*znui2ft6) 
     * / (1.+0.5*zsqnui) + 0.315*znui2ft6) 


     * / (1. + 0.15*znui2ft6)
!
      return
      END 
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  ! MODULE sigmaneomod
  !
  ! Compute neoclassical conductivity using formula in Ref.1: 
  !O. Sauter et al, Phys. Plasmas 6 (1999) 2834.
  !
  ! Outputs:
  !    signeo : neoclassical conductivity at each value of the input parameters
  !    sigsptz: Spitzer conductivity
  !    nuestar: electron collisionality (default set to 0.01 if q, R, eps 
  !not given)
  !
  ! Inputs:
  !  Required:
  !    ft()   : trapped fraction (Note, can use formula in 
  ! Lin-Liu et al, Phys. Plasmas 2 (1995) 1666.)
  !    ne()   : local electron density
  !    Te()   : Local electron temperature
  !  Optionals:
  !    Zeff() : effective charge (default is 2.)
  !    q()    : Local safety factor (if q, R or eps is not given, 
  ! nuestar set to 0.01)
  !    R()    : geometrical center of local flux surface (si q for def)
  !    eps()  : local inverse aspect ratio (a/R) (si q for def)
  !    Nin    : number of input values (default to size(ft) if 
  ! args are arrays but nin omitted)
  !
  ! Note: q, R and eps are used to compute nue* according to 
  !Eqs.(18b and 18d) of Ref.1
  !
  ! examples of calls:
  !
  ! call sigmaneo(signeo,sigsptz,nuestar,ft,ne,te) 
  ! (defaults : zeff=1.5, nuestar=0.01)
  ! call sigmaneo(signeo,sigsptz,nuestar,ft,ne,te,zeff) 
  ! (default for nuestar=0.01)
  ! call sigmaneo(signeo,sigsptz,nuestar,ft,ne,te,zeff,q,R,eps)
  ! call sigmaneo(signeo,sigsptz,nuestar,ft,ne,te,NIN=nin) 
  ! (defaults : zeff=1.5, nuestar=0.01)
  !
  !
      SUBROUTINE sigmaneo(signeo,sigsptz,nuestar,ft,ne,te,zeff,q,R,eps)
      include 'double.inc'

    ! CASE: all are scalar input variables (or ft(i) in argument, 
    !as is interpreted as scalar)
    ! te in [eV], ne in [m**-3], R in [m]

        include 'double_eni_ae3.inc'

        z_zeff = 2.0
      z_zeff = zeff
!
      zNZ = 0.58 + 0.74 / (0.76 + z_zeff)
      zlnL = 17.

      IF (ne.gt.0. .and. te.gt.0.) THEN
         zlnL = 31.3 - dlog(dsqrt(1.e19*ne)/te)
      ENDIF

      sigsptz = 1.9012E+04 * dABS(te)**1.5 / (z_zeff * zNZ * zlnL)
!

      nuestar = 6.921E+1 * q * R * ne * z_zeff * zlnL / 
     * (te*te * eps**1.5)

!

      zft33eff = ft / 
     * (1.+(0.55-0.1*ft)*dsqrt(nuestar) 
     * + 0.45*(1.-ft)*nuestar/z_zeff**1.5)

c      signeo = sigsptz * (1. - zft33eff*(1.+0.36/z_zeff 
c     * - zft33eff*(0.59/z_zeff - 0.23/z_zeff*zft33eff)))

c______ Popravka neoklassicheskay

      signeo = 1. * (1. - zft33eff*(1.+0.36/z_zeff 
     * - zft33eff*(0.59/z_zeff - 0.23/z_zeff*zft33eff))) /z_zeff
!
      return
      END 

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

      subroutine aux_prof()
	include 'double.inc'
      include 'new_com.inc'

      call aux_prof_c(
     *  pi,n,ai,ha,vi,
     *  qde0,qdq0,
     *  power_el,pow_el,ro_el,del_el,
     *  power_ion,pow_ion,ro_ion,del_ion,
     *  kpr)

      return
      end


      subroutine aux_prof_c(
     *  pi,n,ai,ha,vi,
     *  qde0,qdq0,
     *  power_el,pow_el,ro_el,del_el,
     *  power_ion,pow_ion,ro_ion,del_ion,
     *  kpr)

	include 'double.inc'
	include 'parf0'

      dimension qde0(*),qdq0(*),ai(*),ha(*),vi(*)
      dimension qde(npo)

	dimension a_print(100)
	character *30 apr

!	sb_ech(J)=dexp(-((a_m(J)-YR0)/YDR)**2)

      PNOR=6.25E8

	pow_el=2.
	pow_ion=2.

	a_print(1)=ro_el
	a_print(2)=del_el
	a_print(3)=ro_ion
	a_print(4)=del_ion
		
	n_pr=4
	apr='ro_el del_el ro_ion del_ion'
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	a_print(1)=pi
	a_print(2)=n
	a_print(3)=ai(n)
	a_print(4)=vi(n)
	a_print(5)=ha(n)
		
	n_pr=5
	apr='pi n ai vi ha'
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

	a_print(1)=power_el
	a_print(2)=power_ion
		
	n_pr=2
	apr='power_el  power_ion '
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


c  Electrons heating....

	if(power_el.gt.1.e-8)then
	summ=0.
	do i=2,n
           qde(i)=0.
           arg=dabs((ro_el-ai(i))/del_el)**pow_el
		 qde(i)=dexp(-arg)
           summ=summ+qde(i)*2.*pi*vi(i)*ha(i)
      end do

	al1=power_el/summ

	do i=2,n
           qde(i)=qde(i)*al1*pnor
      end do

	summ=0.
	do i=2,n
           summ=summ+qde(i)*2.*pi*vi(i)*ha(i)
      end do

	summ1=summ/pnor


	do i=2,n
           qde0(i)=qde0(i)+qde(i)
      end do



	end if

	if(power_ion.gt.1.e-8)then
c  Ions heating....

	summ=0.
	do i=2,n
           qde(i)=0.
           arg=dabs((ro_ion-ai(i))/del_ion)**pow_ion
		 qde(i)=dexp(-arg)
           summ=summ+qde(i)*2.*pi*vi(i)*ha(i)
      end do

	al1=power_ion/summ

	do i=2,n
           qde(i)=qde(i)*al1*pnor
      end do

	summ=0.
	do i=2,n
           summ=summ+qde(i)*2.*pi*vi(i)*ha(i)
      end do

	summ2=summ/pnor


	do i=2,n
           qdq0(i)=qdq0(i)+qde(i)
      end do

	end if

	a_print(1)=power_el
	a_print(2)=summ1
	a_print(3)=power_ion
	a_print(4)=summ2
		
	n_pr=4
	apr='power_el summ1 power_ion summ2'
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


	do i=2,n
	a_print(i)=qde0(i)
      end do
		
	n_pr=n
	apr='--q_el-- '
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)




	do i=2,n
	a_print(i)=qdq0(i)
      end do
		
	n_pr=n
	apr='--q_ion-- '
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


c
   71 FORMAT(20X,A6/,(6(1pE10.3)))

!!!	call pau()
      return
      end




!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

      subroutine aux_prof_80()
	include 'double.inc'
      include 'new_com.inc'

      call aux_prof_80_c(
     *  pi,n,ai,ha,vi,
     *  qde0,qdq0,
     *   p_e,p_i,
     *  kpr)

      return
      end


      subroutine aux_prof_80_c(
     *  pi,n,ai,ha,vi,
     *  qde0,qdq0,
     *   p_e,p_i,
     *  kpr)

	include 'double.inc'
	include 'parf0'

      dimension qde0(*),qdq0(*),ai(*),ha(*),vi(*)
      dimension p_e(*),p_i(*)
      dimension qde(npo)

	dimension a_print(100)
	character *30 apr

!	sb_ech(J)=dexp(-((a_m(J)-YR0)/YDR)**2)

      PNOR=6.25E8


	a_print(1)=pi
	a_print(2)=n
	a_print(3)=ai(n)
	a_print(4)=vi(n)
	a_print(5)=ha(n)
		
	n_pr=5
	apr='pi n ai vi ha'
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)



c  Electrons heating....

	summ=0.
	do i=2,n
           qde(i)=p_e(i)
           summ=summ+qde(i)*2.*pi*vi(i)*ha(i)
      end do
	summ_e=summ/pnor

	do i=2,n
           qde0(i)=qde0(i)+qde(i)
      end do

c  Ions heating....

	summ=0.
	do i=2,n
           qde(i)=p_i(i)
           summ=summ+qde(i)*2.*pi*vi(i)*ha(i)
      end do

	summ_i=summ/pnor


	do i=2,n
           qdq0(i)=qdq0(i)+qde(i)
      end do

	a_print(1)=summ_e
	a_print(2)=summ_i
		
	n_pr=2
	apr='summ_e  summ_i'
	num=25
c	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


c
   71 FORMAT(20X,A6/,(6(1pE10.3)))

!!!	call pau()
      return
      end






