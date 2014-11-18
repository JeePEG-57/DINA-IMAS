
       SUBROUTINE DIFMF_1()
	include 'double.inc'
       include 'new_com.inc'


      call difmf_1_c(n,
     *rs0,next,sigma_jetto,sigma_dina)

      return
      end



      SUBROUTINE DIFMF_1_c(n,
     *rs0,next,sigma_jetto,sigma_dina)

c$$$            SUBROUTINE DIFMF_1(N)

cc----------------------------------------
c   magnetic field diffusion
c--------------------------------------------
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	include 'parf0'
      COMMON
     *  /DFM1/UDM,ZDM,L3,SIG0
     *  /DFM2/PSI(npo),PFI(npo),DM0(npo),DMN(npo)
     *  /dfm3/dfmax(npo),dfmax0(npo)
     *  /DFM4/Q(npo),ANU(npo),P(npo),Fx(npo),
     *  PP(npo),PFF(npo)
     *  /dfm7/bt,uind
     *  /dfm8/ajb(npo),sigk(npo)
     *  /dfm9/aj0(npo)
     *  /dfm10/ajf(npo),aje1(npo),aje(npo)
     *  /dfm11/c20(npo),tok1(npo),tok2(npo)
     *  /dfm13/tokel,tokfi,tokbut
     *  /dfm13e/tokuv
     *  /dfm14/tokae,ajae(npo),ajae0(npo),enae
	common
     *  /en2/TE0(npo),TQ0(npo),TEN(npo),
     *  TQN(npo),WE0(npo),WQ0(npo)
	common
     *  /mid1/C1(npo),C2(npo),C3(npo)
     *  /mid2/vi(npo),spo(npo)
     *  /mid6/bp_0(npo),a_m(npo),r_m(npo)
	common
     *  /ge1/pi
     *  /ge2/NTAY,TAY,TT
     *  /ge3/AI(npo),A0(npo),HA2(npo),a1(npo),ha(npo)
     *  /ge4/EPS1,EPS2,EPS0
     *  /ge5/kpr
     *  /ge6/zeff(npo),qpr(npo),ppr(npo),pr0,prg,zar
     *  /en9e/volt(npo)
     *  /sig/sig

	common /keys4/k_ener,k_uv
	common
     *	/efit6/tpl_p
c
	dimension UG(npo),VG(npo),HG(npo),GG(npo),
     *  WDM0(npo),FDM0(npo),A(npo),B(npo),C(npo),
     *  TETA(npo),GK(npo),
     *  U(npo),B0(npo),Z(npo),DM(npo),WDM(npo),SIG(npo),
     *  AGK(npo),FDM(npo),DH1(npo),dh2(npo),fz(npo)
c
	dimension fji(npo),tsig(npo),f(npo),fbut(npo),
     *  fuv(npo),fae(npo),tsig_0(npo),dfma(npo),fi_dot(npo)
c
	character *50 mps

        dimension dm_help(npo),df_help(npo),cur_tor(npo)

      dimension sigma_jetto(*),sigma_dina(*),sigk_jetto(npo)
      dimension sigk_jetto1(npo),aj0_help(npo),b_corr(npo)

        sig0_new=9./(4.*pi*sig0)*1.e4

        if(kpr.eq.1)print *,' n rs0 next==',n,rs0,next

        if(kpr.eq.1)print *,' sig0_new==',sig0_new

	do i=1,n
	dm_help(i)=dmn(i)
	end do

        i_old=1

	  ptor=0.

        if(ntay.gt.1.and.i_old.eq.1)ptor=1


!      	ptor=0.



        if(ntay.gt.1.and.i_old.eq.0)then

c!!        if(ntay.gt.2)then

      n2=n+3
      
      d_a0=a1(n)-a1(n-1)
      
	do i=n+1,n2	
	a1(i)=a1(i-1)+d_a0
	dfmax0(i)=dfmax0(n)*a1(i)**2

 	ateta=a1(i)
      call inter_h0(dmn,a1,n,ateta,val)
	dmn(i)=val

	dm_help(i)=dmn(i)

      end do      

	do i=2,n

c           df_temp=0.5*(dfmax(i)+dfmax0(i))
           df_temp=dfmax(i)

!           if(df_temp.le.dfmax0(n))then

c	call feet_p(n,pffz,pffx(i),aiz,a(i))

c              call feeti(n,dm_help,dmn(i),dfmax0,df_temp)

              call linear(n2,dm_help,dmn(i),dfmax0,df_temp)

!           end if

	end do

	mps='a0'
        if(kpr.eq.-1)print 71,mps,(a1(i),i=1,n2)

	mps='dm_help'
        if(kpr.eq.-1)print 71,mps,(dm_help(i),i=1,n2)

	mps='dmn'
        if(kpr.eq.-1)print 71,mps,(dmn(i),i=1,n)
	mps='dfmax0'
        if(kpr.eq.-1)print 71,mps,(dfmax0(i),i=1,n2)
	mps='dfmax'
        if(kpr.eq.-1)print 71,mps,(dfmax(i),i=1,n)

        end if


      if(k_ener.eq.0)then

	mps='sigma_jetto'
        if(kpr.eq.-1)print 71,mps,(sigma_jetto(i),i=1,n)
      
ccccc      ov_zeff=1./zeff(1)
        coef_sigm=1.
ccc        if(tt.gt.50.e3)coef_sigm=1.5

      ov_zeff=1./zeff(1)*coef_sigm
      if(kpr.eq.1)print *,' ov_zeff=',ov_zeff
      
      sigk(1)=ov_zeff      

	mps='sigk'
!      if(kpr.eq.1)print 71,mps,(sigk(i),i=1,n)
 

      TXX=TE0(1)
      sigk_jetto(1)=sigma_jetto(1)/(txx**1.5)
	do i=2,n
      TXX=0.5*(TE0(I)+TE0(I-1))
      sigk_jetto(i)=sigma_jetto(i)/(txx**1.5)
	sigma_dina(i)=1.2d4/9.*(txx**1.5)*sigk(i)
      end do      

	mps='1 sigma_dina'
      if(kpr.eq.-1)print 71,mps,(sigma_dina(i),i=1,n)
      
	do i=2,n
	sigk_jetto(i)=sigk_jetto(i)/sigk_jetto(1)*ov_zeff
      end do      
      
      sigk_jetto(1)=ov_zeff

	mps='sigk_jetto'
      if(kpr.eq.1)print 71,mps,(sigk_jetto(i),i=1,n)

	do i=1,n
	sigma_dina(i)=sigma_jetto(i)*sigk(i)/sigk_jetto(i)
      end do      

	mps='sigma_dina'
      if(kpr.eq.-1)print 71,mps,(sigma_dina(i),i=1,n)

      end if ! k_ener=0
      

c
c
	ajb(2)=0.5*ajb(3)
c        if(kpr.eq.1)print *,'*** bt=',bt
c
	kuv=1
      kbu=1
	kae=1

ccc	if(ntay.lt.999999)kbu=0

!      nnn=99979


      nnn=4

      if(tt.gt.61.5e9)then
      nnn=ntay+2
      if(kpr.eq.1)print *,' ++tt nnn ntay=',tt,nnn,ntay
      end if
     
	if(ntay.lt.nnn)kbu=0
	if(ntay.lt.nnn)kuv=0
	if(ntay.lt.nnn)kae=0


	do i=2,n
	f(i)=fx(i)
	pfi(i)=2.*pi*rs0*c3(I)*fx(i)

      aj0_help(i)=kbu*ajb(i)+kuv*aj0(i)+kae*ajae(i)

      b_corr(i)=sqrt( 1.d0+bp_0(i)**2/f(i)**2 )

	aj0_help(i)=aj0_help(i)*b_corr(i)

      
c       f(i)=0.5*(fx(i)+fx(i-1))
	end do
c

	mps='b_corr'
        if(kpr.eq.-1)print 71,mps,(b_corr(i),i=1,n)
	mps='bp_0'
      if(kpr.eq.-1)print 71,mps,(bp_0(i),i=1,n)

      if(kpr.eq.1)print *,' b_co bp_0=',b_corr(n),bp_0(n)

      if(k_ener.eq.0)then
      
        TXX=TE0(1)
        sigk_jetto1(1)=sigma_jetto(1)*1.2566e-7*sig0/txx**1.5

      end if      ! k_ener=0
      
      N2=N-1
	do i=2,n
      TXX=0.5*(TE0(I)+TE0(I-1))
c
c	if(ntay.lt.15)txx=10.+(100.-10.)*(1.-a1(i))
c
        if(abs(sigk(i)).le.1.e-3)sigk(i)=1./zeff(i)

c	sigk(i)=1./zeff(i)
c       sigk(i)=1.

c==========================================
      if(k_ener.eq.0)then

        sigk_jetto1(i)=sigma_jetto(i)*1.2566e-7*sig0/(txx**1.5)

      if(ai(i).le.1.95)then
!	tsig(i)=txx**1.5*sigk_jetto(i)
         tsig(i)=txx**1.5*sigk_jetto1(i)
	else
	tsig(i)=txx**1.5*sigk_jetto(i)*1.e-7
	end if

ccc To set up sigk_jetto one needs to make comment of next line

c!!!!!!!!!!	if(tt.gt.150.e3)tsig(i)=txx**1.5*sigk(i)


      end if  ! k_ener=0


      if(k_ener.eq.1)then
!	sigk(i)=1./zeff(i)
      end if
      

      if(k_ener.eq.1)then
      tsig(i)=txx**1.5*sigk(i)
      end if  ! k_ener=1

	end do

      if(k_ener.eq.-1)then
	mps='sigm'
       if(kpr.eq.1)print 71,mps,(sigk(i),i=1,n)
	mps='tsig'
       if(kpr.eq.1)print 71,mps,(tsig(i),i=1,n)

      end if
      
	mps='sigk_1'
      if(kpr.eq.-1)print 71,mps,(sigk_jetto1(i),i=1,n)

	mps='sigm'
c       if(kpr.eq.1)print 71,mps,(sigk(i),i=1,n)
c____________________________________________
      ALFA=1.
      BETA=0.
	i=2
      VG(i)=0.
      UG(i)=0.
      HG(i)=1.
      GG(i)=1.
      SIG(i)=0.
      fz(i)=0.
	fji(i)=0.
      TETA(i)=1./HA2(i)
	i=2
	dh1(i)=2.*ha(i)/(2.*ha(i)+ha(i+1))
	dh2(i)=ha(i+1)/(2.*ha(i)+ha(i+1))
	do i=3,n2
	dh1(i)=ha(i)/(ha(i)+ha(i+1))
	dh2(i)=ha(i+1)/(ha(i)+ha(i+1))
	end do
	
      alf_a=0.d0
      alf_b=2.d0-alf_a

	
	
      DO 1 I=3,N
cccc    c_fi=9.e3/(1.2*tsig(i)*pfi(i))*2.*pi*vi(i)*bt/sigk(i)
      SIG(I)=SIG0/tsig(i)/C3(I)*f(i)
      GK(I)=-C2(I)/f(i)
      GG(I)=1.
      UG(I)=0.
      HG(I)=1.
      fz(I)=1./SIG(I)
      TETA(I)=1./HA2(I)
	fji(i)=kuv*aj0_help(i)*9.e3/
     *(sig0_new*tsig(i)*pfi(i))
c###     **2.*pi*vi(i)*bt/sigk(i)

     **2.*pi*spo(i)*rs0*f(i)



	dfma(i)=-ptor*(dfmax(i)-dfmax0(I))/tay

      fi_dot(i)=alf_b*dfma(i)


      VG(I)=1./pfi(i)*fz(I)
    1 CONTINUE
c
      DO I=3,N2

      !         alf_a=a(i)

     	   fi_dotp=0.5d0*( fi_dot(i)+alf_a*dabs(fi_dot(i)))
	   fi_dotm=0.5d0*( fi_dot(i)-alf_a*dabs(fi_dot(i)))

      A(I)=-UG(I)/(2.*ha2(i))*beta*(dh1(i)+dh2(i))
      b(I)=(ug(i+1)-UG(I))/(2.*ha2(i))*beta*
     *(dh1(i)+dh2(i))
      c(I)=UG(I+1)/(2.*ha2(i))*beta*(dh1(i)+dh2(i))
      B(I)=B(I)+ ALFA*(dh2(i)*fz(I)*GG(I)+dh1(i)*
     *fz(I+1)*GG(I+1))/TAY
c
	a(i)=a(i)-hg(i-1)/ha(i)*vg(i)*dh2(i)*fi_dotm
	c(i)=c(i)+hg(i+1)/ha(i+1)*vg(i+1)*dh1(i)*fi_dotp
	
	b(i)=b(i)+hg(i)/ha(i)*vg(i)*dh2(i)*fi_dotm-hg(i)/
     *ha(i+1)*vg(i+1)*dh1(i)*fi_dotp
c
	end do
	
	i=2

	dfma(i)=-ptor*(dfmax(i)-dfmax0(I))/tay
	dfma(i)=0.d0
	
      fi_dot(i)=alf_b*dfma(i)

     	   fi_dotp=0.5d0*( fi_dot(i)+alf_a*dabs(fi_dot(i)))
	   fi_dotm=0.5d0*( fi_dot(i)-alf_a*dabs(fi_dot(i)))

	
      A(2)=0.
      b(I)=ug(i+1)/(2.*ha2(i))*beta*(dh1(i)+dh2(i))
      c(I)=ug(i+1)/(2.*ha2(i))*beta*(dh1(i)+dh2(i))
      B(I)=B(I)+ ALFA*(dh2(i)*fz(I)*GG(I)+dh1(i)*
     *fz(I+1)*GG(I+1))/TAY
c
	c(i)=c(i)+hg(i+1)/ha(i+1)*vg(i+1)*dh1(i)*fi_dotm
	b(i)=b(i)-hg(i)/ha(i+1)*vg(i+1)*dh1(i)*fi_dotp
c
      DO 9 I=3,N
      AGK(I)=GK(I)/HA(I)
    9 CONTINUE
    
       coef_rh=0.d0

      DO I=2,N
      B(I)=B(I)-coef_rh*(fz(i)*fji(i)*dh2(i)+fz(i+1)*fji(i+1)*dh1(i))/
     *  dmn(i)
      end do
          

	do i=2,n2
      FDM(I)=ALFA*(fz(I)*GG(I)*dh2(i)+fz(I+1)*
     *GG(I+1)*dh1(i))/TAY*dmn(I)+(1.d0-coef_rh)*
     *fz(i)*fji(i)*dh2(i)+fz(i+1)*fji(i+1)*dh1(i)
c      FDM(I)=fdm(i)-ktor1*(fz(I)*GG(I)*dh2(i)/q(i)+fz(I+1)*
c     *GG(I+1)*dh1(i)/q(i+1))/TAY*(dfmax(i)-dfmax0(i))
	end do
   71 FORMAT(5X,A60/,(6(1pE11.3)))
      DM(N)=dm0(n)
    2 CONTINUE
c       if(kpr.eq.1)print *,'l3 udm zdm',l3,udm,zdm
      CALL PROGP(N,A,B,C,TETA,AGK,U,B0,DM,Z,WDM,FDM,
     *ZDM,UDM,EPS0,L3)
      DO 5 I=2,N
      dm0(I)=DM(I)
      WDM0(I)=WDM(I)
    5 CONTINUE
c
	do i=3,n-1
	f_r=a(i)*dm0(i-1)+b(i)*dm0(i)+c(i)*dm0(i+1)+
     *	(wdm0(i+1)-wdm0(i))/ha2(i)
c	if(kpr.eq.1)print *,' i f_r fdm(i)',i,f_r,fdm(i)
	end do
c

      DO 88 I=3,N
        psi(i)=WDM0(I)/GK(I)
	dm(i)=(dm0(i)-dm0(i-1))/ha(i)
   88 Q(I)=-PFI(I)/PSI(I)
	do i=2,n-1
	
!         alf_a=1.d0

     	   fi_dotp=0.5d0*( fi_dot(i)+alf_a*dabs(fi_dot(i)))
	   fi_dotm=0.5d0*( fi_dot(i)-alf_a*dabs(fi_dot(i)))

	
	aje(i)=+ALFA*(fz(I)*GG(I)*dh2(i)+fz(I+1)*
     *GG(I+1)*dh1(i))/TAY*( dm0(i)-dmn(I) )
c
	ajf(i)=	( dm0(i+1)-dm0(i) )/ha(i+1)*vg(i+1)*dh1(i)*fi_dotp+
     *	( dm0(i)-dm0(i-1) )/ha(i)*vg(i)*dh2(i)*fi_dotm
c
	volt(i)=-(aje(i)+ajf(i))/100./
     *  ( fz(I)*GG(I)*dh2(i)+fz(I+1)*GG(I+1)*dh1(i) )
c
	c_fi=9.e3/(sig0_new*tsig(i)*pfi(i))*2.*pi*spo(i)*rs0*
     *  f(i)
	c_fi1=9.e3/(sig0_new*tsig(i+1)*pfi(i+1))*2.*pi*spo(i+1)*
     *  rs0*f(i)
c--
	fbut(i)=fz(i)*ajb(i)*c_fi*dh2(i)+fz(i+1)*ajb(i+1)*c_fi1*dh1(i)
	fuv(i)=fz(i)*aj0(i)*c_fi*dh2(i)+fz(i+1)*aj0(i+1)*c_fi1*dh1(i)
	fae(i)=fz(i)*ajae(i)*c_fi*dh2(i)+fz(i+1)*ajae(i+1)*c_fi1*dh1(i)
c
	w_r=(wdm0(i+1)-wdm0(i))/ha2(i)
	f_r=(kbu*fbut(i)+kuv*fuv(i)+kae*fae(i))-aje(i)-ajf(i)
	
	if(i.eq.2.and.kpr.eq.1)print *,' i tsig(i) pfi',tsig(i),pfi(i)
c
	end do
 	ateta=1.
        call inter_h0(volt,a1,n-1,ateta,val)
	volt(n)=val
c	pause
	tokel=0.
	tokfi=0.
	tokbut=0.
	tokuv=0.
	tokae=0.
	enae=0.
	do i=2,n-1
	tokbut=tokbut+fbut(i)*ha2(i)
	tokuv=tokuv+fuv(i)*ha2(i)
	tokae=tokae+fae(i)*ha2(i)
	tokel=tokel+aje(i)*ha2(i)
	enae=enae+fae(i)*ha2(I)/spo(i)*2.*pi*spo(i)*rs0
	tokfi=tokfi+ajf(i)*ha2(I)
	end do
        tok_b=0.
        do i=2,n
        tok_b=tok_b+ajb(i)*spo(i)*ha(i)
        end do

	coef=10./(4.*pi)

        tok_b2=tok_b*coef

        tok_ae=0.
        do i=2,n
        tok_ae=tok_ae+ajae(i)*spo(i)*ha(i)
        end do

        tok_ae2=tok_ae*coef

c
	tokbut=tokbut*coef*f(n)
	tokuv=tokuv*coef*f(n)
	tokae=tokae*coef*f(n)
	enae=enae*coef*f(n)*3.2e-8*10.
c
	tokel=tokel*coef*f(n)
	tokfi=tokfi*coef*f(n)
	tok=-tokel-ptor*tokfi+kbu*tokbut+kuv*tokuv+kae*tokae
c
        if(kpr.eq.1)
     *	print *,'tokel tokfi bt',tokel,tokfi,bt,' kA (difmf)'
        if(kpr.eq.1)
     *	print *,'tokbut tok_b tokuv',tokbut,tok_b,tokuv,' kA (difmf)'
	if(kpr.eq.1)
     *	print *,'tok  tokae tokae2 ',tok,tokae,tok_ae2,' kA (difmf)'
c
	psi(2)=0.5*dh1(2)*psi(3)
	dm0(1)=dm0(2)-psi(2)*ha(2)
c	q(2)=q(3)
	q(2)=-pfi(2)/psi(2)
        
        c20(1)=0.

        do i=2,n
           c20(i)=-c2(i)*psi(i)
        end do

        

	do i=3,n-1
           aje(i)=coef*( c20(i)*dh2(i)+c20(I+1)*dh1(i) )
        end do

        aje(1)=0.

        i=2

 	ateta=a1(2)
        n_1=3
        call inter_h0(c20,ai,n_1,ateta,val)

        aje(i)=coef*val

	do i=2,n-1
          tok2(i)=(aje(i)-aje(i-1))/(spo(i)*ha(i))
        end do

        i=3
        tok2(i)=coef*wdm0(3)*f(3)/(ha(2)+0.5*ha(3))/(spo(i)*dh1(2))
        
        tok2(1)=tok2(2)

c***************************************
	mps='volt'
	if(kpr.eq.1)print 71,mps,(volt(i),i=1,n)
	q(1)=q(2)
	do i=2,n
	dm(i)=-(dfmax(i)-dfmax0(i))/tay*1.e-2
	end do
	mps='V in i`s magnetic surface by dfi/dt,V (difmf)'
c	if(kpr.eq.1)print 71,mps,(dm(i),i=1,n)
	do i=2,n
	dm(i)=-(dm0(i)-dmn(i))/tay*1.e-2
	end do
	mps='V dpsi/dt,V (difmf)'
	if(kpr.eq.-1)print 71,mps,(dm(i),i=1,n)
	mps='psi*'
c	if(kpr.eq.1)print 71,mps,(psi(i),i=1,n)
	mps='psi-'
c	if(kpr.eq.1)print 71,mps,(dm(i),i=1,n)
	mps='ajb, kA/cm**2 (difmf)'
c        if(kpr.eq.1)print 71,mps,(ajb(i),i=1,n)
	mps='tok2, kA/cm**2 (difmf)'
c        if(kpr.eq.1)print 71,mps,(tok2(i),i=1,n)

c	mps='ajae, kA/cm**2 (difmf)'
c	if(kpr.eq.1)print 71,mps,(ajae(i),i=1,n)

	mps='fbut'
	if(kpr.eq.-1)print 71,mps,(fbut(i),i=1,n)

	mps='fz'
c	if(kpr.eq.1)print 71,mps,(fz(i),i=1,n)

	mps='q***'
	if(kpr.eq.-1)print 71,mps,(q(i),i=1,n)
c
	do i=2,n
	dmn(i)=dm_help(i)
	end do

	do i=1,n
	df_help(i)=dfmax(i)
	end do

      RETURN
      END
c
