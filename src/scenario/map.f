	SUBROUTINE TOK_calc()
	include 'double.inc'
	include 'new_com.inc'

	call TOKK_calc_c(N,RS0)

	return
	end

	SUBROUTINE TOKK_calc_c(N,RS0)
	include 'double.inc'
c       implicit real*8 (a-h,o-z)
	include 'parf0'
      COMMON
     *  /mid1/C1(npo),C2(npo),C3(npo)
     *  /mid2/VI(npo),s(npo)
     *  /mid4/xpp(npo),xpff(npo),scur(npo)
	common
     *  /ge1/PI
     *  /ge3/ai(npo),a0(npo),ha2(npo),a(npo),ha(npo)
     *  /ge5/kpr
	common
     *  /DFM2/PSI(npo),PFI(npo),DM0(npo),DMN(npo)
     *  /dfm4/Q(npo),ANU(npo),P(npo),F(npo),PP(npo),PFF(npo)
     *  /dfm5/PT01,PT02
     *  /dfm8/ajb(npo),sigk(npo)
     *  /dfm11/c20(npo),tok1(npo),tok2(npo)
	common
     *  /en2/TE0(npo),TQ0(npo),TEN(npo),
     *  TQN(npo),WE0(npo),WQ0(npo)
     *  /en9/QE0(npo),QQ0(npo),QDG(npo)
     *  /en9e/volt(npo)
	common/temp/n_p
c
	CHARACTER *70 APR
	dimension aak(npo),bbk(npo),cck(npo),ohm(npo)

c----------------------------------------------------------
c	if(kpr.eq.1)print *,' -- n pi',n,pi
	DKOF=10./(4.*PI)
	c20(1)=0.
	do i=1,n-1
	c20(i+1)=-c2(i+1)*psi(i+1)
	end do
	call interp(c20,ai,aak,bbk,cck,n)
	do i=2,n
	tok1(i)=dkof*( 2.*aak(i)*ai(i)+bbk(i) )/s(i)
	end do
c       tok1(2)=dkof*c20(2)/(0.5*s(2)*ha(2))
	tok1(1)=tok1(2)
c
	tok=0.
	do i=2,n
	tok=tok+tok1(i)*s(i)*ha(i)
	end do
	tok=tok-0.5*tok1(n)*s(n)*ha(n)


	return
	end



	subroutine tab_w()
      include 'double.inc'
	include 'new_com.inc'

         call tab_w_c(
     *   rs0,pi,
     *   n,ppx,pffx,ai,a,q,
     *   tt,tpl,kpr,ntay,ngra,
     *   mp,uk,vk,rmag,zmag,tok1,ajb)

         return
         end

         subroutine tab_w_c(
     *   rs0,pi,
     *   n,ppx,pffx,ai,a,q,
     *   tt,tpl,kpr,ntay,ngra,
     *   mp,uk,vk,rmag,zmag,tok1,ajb)

      include 'double.inc'

      dimension ppx(*),pffx(*),ai(*),q(*),a(*),uk(*),vk(*),
     * tok1(*),ajb(*)


	include 'parf0'

	dimension pp(npo),pff(npo)

	character *20 apr

71	FORMAT(5X,A10/,(2x,6(1PE11.3)))

	amu0=4.*pi*1.d-7
	COEF=10./(4.*PI)

	call TOK_calc()
	
	do i=1,n
	   pp(i)=-ppx(i)/( (rs0*1.d-2)*amu0 )*coef
	   pff(i)=-0.5d0*pffx(i)*(rs0*1.e-2)*coef
	end do

         open (unit=41,file='tabppf.dat',
     *	form='formatted')

         write (41,*)n
         do i=1,n
            write (41,5000)a(i),pp(i),pff(i)
         enddo

         close (41)

         open (unit=41,file='tabqjb.dat',
     *	form='formatted')

         write (41,*)n
         do i=1,n
            write (41,5000)ai(i),q(i),tok1(i),ajb(i)
         enddo

         close (41)

         open (unit=41,file='plasma_par.dat',
     *	form='formatted')
         write (41,*)tt*1.d-3,tpl,tokbut
         write (41,*)rmag,zmag
         write (41,*)mp
         do i=1,mp
            write (41,5000)uk(i),vk(i)
         enddo
         write (41,*)' end'



         close (41)

c!!!!!	end if

        if(kpr.eq.1)print *,' rs0 n ==',rs0,n

	apr=' pp'
	if(kpr.eq.1)print 71,apr,(pp(i),i=1,n)
	apr=' pff'
	if(kpr.eq.1)print 71,apr,(pff(i),i=1,n)

	apr='tok1'
	if(kpr.eq.1)print 71,apr,(tok1(i),i=1,n)

	apr='ajb'
	if(kpr.eq.1)print 71,apr,(ajb(i),i=1,n)

	apr=' q'
	if(kpr.eq.1)print 71,apr,(q(i),i=1,n)

5000    format (6(1pe14.6))


	return
	end


	subroutine pet_tab_w()
      include 'double.inc'
	include 'new_com.inc'

         call pet_tab_w_c(
     *   rs0,
     *   n,ppx,pffx,ai,a,pi,q,
     *   nutab,pstab,pptab,fptab,npf,pf,tt,tpl,kpr,ntay,ngra)

         return
         end

         subroutine pet_tab_w_c(
     *   rs0,
     *   n,ppx,pffx,ai,a,pi,q,
     *   nutab,pstab,pptab,fptab,npf,pf,tt,tpl,kpr,ntay,ngra)

      include 'double.inc'

         dimension ppx(*),pffx(*),ai(*),q(*),a(*)

         dimension pstab(*),pptab(*),fptab(*),pf(*)


	include 'parf0'

	dimension pai(npo),q_h(npo)

	character *20 apr

71	FORMAT(5X,A10/,(2x,6(1PE11.3)))

c!!!!!	if(ntay.eq.ngra*(ntay/ngra).or.ntay.eq.0)then
c	if(tt.le.45000.)then
	i_en=i_en+1

	if(i_en.le.1)then
         open (unit=42,file='tabppf.dat',form='formatted')
         read (42,*)nutab
         do i=1,nutab
            read (42,*)pstab(i),qqq,qqq,qqq
         enddo
         close (42)
	end if


	ai(n+1)=1.
	pai(n+1)=1.

 	ateta=1.
        call inter_h0(q,ai,n,ateta,val)
	q(n+1)=val
	
	coef=7.17
	
	do i=1,n
	   ppx(i)=-ppx(i)/( (rs0*1.e-2)*4.e-7*pi )*coef
	   pffx(i)=-0.5*pffx(i)*(rs0*1.e-2)*coef
	end do

	do i=2,nutab-1
	   psn=sqrt(pstab(i))
	   call feeti(n,ppx,pptab(i),a,psn)
 	   call feeti(n,pffx,fptab(i),a,psn)
 	   call feeti(n+1,q,q_h(i),ai,psn)
	end do

	pptab(nutab)=ppx(n)
	pptab(1)=ppx(1)

	fptab(nutab)=pffx(n)
	fptab(1)=pffx(1)

 	q_h(nutab)=q(n+1)
	q_h(1)=q(1)

c        open (unit=41,file='tabppf.new',access='append',
c     *	form='formatted')
	if(i_en.le.1)
     *  open (unit=41,file='tabppf.new',status='new',
     *	form='formatted')

	if(i_en.gt.1)
     *    open (unit=41,file='tabppf.new',status='old',
     *	form='formatted')

         write (41,*)nutab
         do i=1,nutab
            write (41,5000)pstab(i),q_h(i),pptab(i),fptab(i)
         enddo

            write (41,5000)(pf(i),i=1,npf)
         write (41,*)tt,tpl

         close (41)

c!!!!!	end if

        if(kpr.eq.1)print *,' rs0 n ==',rs0,n

	apr=' pptab'
	if(kpr.eq.1)print 71,apr,(pptab(i),i=1,nutab)

	apr=' fptab'
	if(kpr.eq.1)print 71,apr,(fptab(i),i=1,nutab)

	apr=' q_h '
	if(kpr.eq.1)print 71,apr,(q_h(i),i=1,nutab)

	apr=' q'
	if(kpr.eq.1)print 71,apr,(q(i),i=1,n)

5000    format (6(1pe14.6))


	return
	end
	subroutine map_psi()
      include 'double.inc'
	include 'new_com.inc'

	call map_psi_c(
     *  n,ha,a,psval,ppx,pffx,
     *  k_map,pi,psi8,
     *  pp,pff,q,qx,
     *  pfi,f,fx)

	return
	end


	subroutine map_psi_c(
     *  n,ha,poa,psval,ppx,pffx,
     *  k_map,pi,psi8,
     *  pp,pff,q,qx,
     *  pfi,f,fx)

      include 'double.inc'

	dimension ha(*),poa(*),psval(*),ppx(*),pffx(*),
     *  psi8(*),pp(*),pff(*),q(*),qx(*),
     *  pfi(*),f(*),fx(*)

	include 'parf0'

	dimension psi(npo),work(npo),ppx_w(npo),pffx_w(npo)

	dimension psi_h(npo),pp_h(npo),pff_h(npo),q_h(npo),
     *  pfi_h(npo),f_h(npo),fx_h(npo),qx_h(npo),ppx_h(npo),pffx_h(npo)

	character * 20 apr

	k_map=0


	if(kpr.eq.1)print *,' MAP_PSI=='

	do i=1,n

	pp_h(i)=pp(i)
	pff_h(i)=pff(i)
	q_h(i)=q(i)
	qx_h(i)=qx(i)
	psi_h(i)=psi8(i)
	f_h(i)=f(i)
	fx_h(i)=fx(i)

	ppx_h(i)=ppx(i)
	pffx_h(i)=pffx(i)

	end do

         do i=2,n


            psix=(psval(i)-psval(1))/(psval(n)-psval(1))

	    psix=sqrt(psix)

	    call fit_pp_pff(psix,pprime,fprime)
	    pffx(i)=fprime
	    ppx(i)=pprime
	    
         end do

	 ppx(1)=ppx(2)
	 pffx(1)=pffx(2)

	 call map()

c	 call eq_res_p()
	 call eq_res()
	 call pet_tab_w()

	do i=1,n
	pp(i)=pp_h(i)
	pff(i)=pff_h(i)
	q(i)=q_h(i)
	qx(i)=qx_h(i)

	psi8(i)=psi_h(i)
	f(i)=f_h(i)
	fx(i)=fx_h(i)

	ppx(i)=ppx_h(i)
	pffx(i)=pffx_h(i)

	end do



71 	FORMAT(20X,A6/,(12E10.3))

         return
         end

	subroutine map()
      include 'double.inc'
	include 'new_com.inc'

	call map_c(m,n,
     *  sinus,cosin,pbound,x_map,y_map,rmag,zmag,delta0,
     *  psval,k_map)

	return
	end


	subroutine map_c(m,n,
     *  sinus,cosin,pbound,x_map,y_map,um,vm,delta0,
     *  psval,k_map)

c---------------------------------------------------------
c  calculate psi_map (
c-------------------------------------------------------------------
c
	parameter ( n_map=1000)
	include 'parf0'
      include 'double.inc'
	
	dimension sinus(m),cosin(m),x_map(npo,m),y_map(npo,m),
     *  psval(n)

	dimension ps_map(n_map,ntet),a_map(n_map,ntet),ps_ma(n_map),
     *  a_ma(n_map),index(ntet)

	dimension pdd(6)
	character * 20 apr


c	real pdd(6)
c

	pocoef=0.5*delta0

c	pocoef=0.25*delta0

c	pocoef=0.1*delta0

c	call c_ctime('init',4)

c	if(kpr.eq.1)print *,' k_map==',k_map

	if(k_map.eq.1)go to 1000


	call boxd(um,vm,pdd,ier)
	fint=pdd(1)

c	fint=psval(1)


c	call boxd_pp(um,vm,fint)


	ix=1
	
	do i=1,m
	   ps_map(ix,i)=fint
	   a_map(ix,i)=0.
	end do

c	if(kpr.eq.1)print *,' MAP psval fint delta0',psval(1),fint,delta0


c	if(kpr.eq.1)print *,' MAP um vm  pdd1 pdd2 ',um,vm,pdd(2),pdd(3)

c
	do i=1,m

	x_map(1,i)=um
	y_map(1,i)=vm

	dpo=pocoef

	poi=0.

	ix=1

901	continue

	poi=poi+dpo

	re=um+poi*cosin(i)
	ze=vm+poi*sinus(i)

c	if(kpr.eq.1)print *,' i um vm poi   ',i,um,vm,poi
c
c	if(poi.le.1.5*delta0)then
	   call boxd(re,ze,pdd,ier)
	   fint=pdd(1)
c	else
c	   call boxdl(fint,re,ze)
c	end if

c	call boxd_pp(re,ze,fint)

	if(ix.le.-3)then
	if(kpr.eq.1)print *,' i psi psval pdd1 pdd2 ',i,fint,psval(1),pdd(2),pdd(3)
	end if


c
        ps=fint
c
	   ix=ix+1
	   ps_map(ix,i)=ps
	   a_map(ix,i)=poi
	   index(i)=ix

           i_901=1
           if(ps.gt.ps_map(ix-1,i)) then
           ps_map(ix,i)=pbound
           i_901=0
           end if

        if(ps.gt.pbound.and.i_901.eq.1) go to 901

c###	if(ps.gt.pbound) go to 901
	
	end do


 1000	continue



	do i=1,m

	   ix=index(i)

c	if(kpr.eq.1)print *,' i ix==',i,ix


	   do ii=1,ix
	      ps_ma(ii)=ps_map(ii,i)
	      a_ma(ii)=a_map(ii,i)
	   end do

	apr='psval'
c 	if(kpr.eq.1)PRINT 71,apr,(psval(ii),ii=1,n)

	apr='ps_ma'
c	if(kpr.eq.1)PRINT 71,apr,(ps_ma(ii),ii=1,ix)

	apr='a_ma'
c	if(kpr.eq.1)PRINT 71,apr,(a_ma(ii),ii=1,ix)


	do ii=2,n
	if(psval(ii).ge.psval(ii-1))then
	if(kpr.eq.1)PRINT *,' II psval ',ii,psval(ii),psval(ii-1)
	stop
	end if
	end do

	do ii=2,ix
	if(ps_ma(ii).ge.ps_ma(ii-1))then
	if(kpr.eq.1)PRINT *,' II ps_ma ',ii,ps_ma(ii),ps_ma(ii-1)
	stop
	end if
	end do



71 	FORMAT(20X,A6/,(6(1pE14.7)))

	   do ii=2,n

	      if(ii.le.n)then
		 call feet_in(ps_ma,a_ma,ix,psval(ii),xp)
	      else
		 call feet_lin(ps_ma,a_ma,ix,psval(ii),xp)
	      end if

c	if(kpr.eq.1)print *,' ii ix psval xp',ii,ix,psval(ii),xp

	re=um+xp*cosin(i)
	ze=vm+xp*sinus(i)

	if(ii.le.-3)then

	call boxd(re,ze,pdd,ier)

	if(kpr.eq.1)print *,' i ii pdd psval',i,ii,pdd(1),psval(ii)

	end if


	x_map(ii,i)=re
	y_map(ii,i)=ze

c	if(kpr.eq.1)print *,' ii i ix x_map y_map',ii,i,ix,x_map(ii,i),y_map(ii,i)

	end do

	end do



	n_in=2
	n_mp=n
c	call surf(x_map,y_map,n_in,n_mp,m,npo)


c	call c_ctime('map_time= ',10)

	return
	end

	subroutine map_tor()
      include 'double.inc'
	include 'new_com.inc'

	call map_tor_c(
     *  n,ha,a,psval,ppx,pffx,dfmax,dfmaxc,
     *  k_map,pi,q)

	return
	end


	subroutine map_tor_c(
     *  n,ha,poa,psval,ppx,pffx,dfmax,dfmaxc,
     *  k_map,pi,q)


      include 'double.inc'
	dimension ha(*),poa(*),psval(*),ppx(*),pffx(*),dfmax(*),
     *  dfmaxc(*),q(*)

	include 'parf0'

	dimension psi(npo),work(npo),ppx_w(npo),pffx_w(npo)

	character * 20 apr

	i_old=1
	nrad=n

         if(kpr.eq.1)print *,' map_tor'


      do i=1,n
	ppx_w(i)=ppx(i)
	pffx_w(i)=pffx(i)
	end do

	psi(1)=0.

      do i=2,n

      psi(i)=(psval(i)-psval(1))/(psval(n)-psval(1))

	psix=sqrt(psi(i))

	if(i_old.eq.1)then
	call feeti(nrad,ppx_w,pprime,poa,psix)
	call feeti(nrad,pffx_w,fprime,poa,psix)

c	call feet_p(nrad,ppx,pprime,poa,psix)
c	call feet_p(nrad,pffx,fprime,poa,psix)

      else

	call fit_pp_pff(psix,pprime,fprime)
	end if

	pffx(i)=fprime
	ppx(i)=pprime
	    
      end do

	 ppx(1)=ppx(2)
	 pffx(1)=pffx(2)

	apr='psval'
c	if(kpr.eq.1)PRINT 71,apr,(psval(i),i=1,n)

	apr='poa'
c	if(kpr.eq.1)PRINT 71,apr,(poa(i),i=1,n)

	apr='psi'
c	if(kpr.eq.1)PRINT 71,apr,(psi(i),i=1,n)


	apr='ppx'
c	if(kpr.eq.1)PRINT 71,apr,(ppx(i),i=1,n)

	apr='pffx'
c	if(kpr.eq.1)PRINT 71,apr,(pffx(i),i=1,n)

	k_map=0

	call map()

	call eq_res()

	apr='dfmaxc'
c	if(kpr.eq.1)PRINT 71,apr,(dfmaxc(i),i=1,n)

         if(kpr.eq.1)print *,' map_tor NEXT'


	it_int=0

 1       continue

	 k_map=1

         fmax=dfmaxc(n)

c	 if(kpr.eq.1)print *,' fmax==',fmax

	 f_8=0.

	 i=2
	 dh1_2=2.*ha(i)/(2.*ha(i)+ha(i+1))


         do i=2,n-1

	    psn=0.5*(poa(i)+poa(i-1))

c            f_8=f_8+2.*psn*fmax*ha(i)

            f_8=poa(i)**2*fmax

c            call feeti(n,psi,psix,dfmaxc,f_8)



	    call feet_lin(dfmaxc,psi,n,f_8,psix)


	    if(i.le.5)then

	       psi_i=2.*pi*(psval(i)-psval(i-1))/ha(i)
	       psi_3=2.*pi*(psval(i+1)-psval(i))/ha(i+1)

	       psi_22=0.5*dh1_2*psi_3

	       pfi_i=(dfmaxc(i)-dfmaxc(i-1))/ha(i)
	       pfi_2=2.*psn*fmax
	       
	       q_1=-pfi_i/psi_i
	       q_2=-pfi_2/psi_i
	       
	       
c	       if(kpr.eq.1)print *,' i f_8 dfmaxc q_1 q_2',i,f_8,dfmaxc(i),q_1,q_2

c	       if(kpr.eq.1)print *,' i psi_i psi_22 ',i,psi_i,psi_22

	    end if

            work(i)=psix

         end do

	apr='work'
c	if(kpr.eq.1)PRINT 71,apr,(work(i),i=1,n)

         err=0.

         do i=2,n-1

            derr=abs(psi(i)-work(i))

            psi(i)=work(i)

            err=amax1(err,derr)
	    
	    psval(i)=psval(1)+psi(i)*(psval(n)-psval(1))

	    psix=sqrt(psi(i))
	    call fit_pp_pff(psix,pprime,fprime)
	    pffx(i)=fprime
	    ppx(i)=pprime

         end do

	 ppx(1)=ppx(2)
	 pffx(1)=pffx(2)

	apr='ppx'
c	if(kpr.eq.1)PRINT 71,apr,(ppx(i),i=1,n)

	apr='pffx'
c	if(kpr.eq.1)PRINT 71,apr,(pffx(i),i=1,n)


         call map()


	 call eq_res()

         if(kpr.eq.1)print *,' err fmax it_int',err,fmax,it_int

         it_int=it_int+1

         if(err.gt.1.e-5.and.it_int.le.10)go to 1

         do i=2,n
            psi(i)=(psval(i)-psval(1))/(psval(n)-psval(1))

	    psix=sqrt(psi(i))
	    call fit_pp_pff(psix,pprime,fprime)
	    pffx(i)=fprime
	    ppx(i)=pprime
	    
         end do

	 ppx(1)=ppx(2)
	 pffx(1)=pffx(2)

	call eq_res()

         do i=1,n
	    dfmax(i)=dfmaxc(i)
         end do


	k_map=0


	apr='--q++'
	if(kpr.eq.1)PRINT 71,apr,(q(i),i=1,n)


71 	FORMAT(20X,A6/,(12E10.3))

         return
         end

	subroutine eq_res()
      include 'double.inc'
	include 'new_com.inc'

	call eq_res_c(
     *  n,mp,npo,
     *  q,dfmaxc,pp,pff,ppx,pffx,
     *  p,f,psval,ha,psi8,fx,pfi,c2,c3,
     *  bt0,f_na,i_halo,pi,
     *	expfg,rs0,tpl,q_95,
     *  xpl,ypl,x_map,y_map,
     *  dm0)

	return
	end


	subroutine eq_res_c(
     *  n,mp,npo,
     *  q,dfmaxc,pp,pff,ppx,pffx,
     *  p,f,psval,ha,psi,fx,pfi,c2,c3,
     *  bt0,f_na,i_halo,pi,
     *	expfg,rs0,tpl,q_95,
     *  xpl,ypl,x_map,y_map,
     *  dm0)

      include 'double.inc'
c------------
	dimension q(*),dfmaxc(*),p(*),f(*),psval(*),
     *  pp(*),pff(*),ppx(*),pffx(*),
     *  pfi(*),c2(*),c3(*),ha(*),psi(*),fx(*),
     *  xpl(npo,*),ypl(npo,*),x_map(npo,*),y_map(npo,*),
     *  dm0(*)

	character *12 apr

        if(kpr.eq.1)print *,' pi n mp rs0',pi,n,mp,rs0

	i=2
	dh1_2=2.*ha(i)/(2.*ha(i)+ha(i+1))

	f(n)=bt0

	fsqrt0=f(n)**2
	
	psi(1)=0.

	do i0=2,n
	i=n-i0+2
	fprime=-0.5*(pffx(i)+pffx(i-1))

	psi(i)=2.*pi*(psval(i)-psval(i-1))/ha(i)

c#######################

	if(i.eq.2)psi(2)=0.5*dh1_2*psi(3)

c#######################


	fhelp=fprime*(psi(i)/(2.*pi*rs0))

	fsqrt=fsqrt0-fhelp*ha(i)

	fsqrt0=fsqrt

	f(i-1)=sqrt(fsqrt)

	end do
c
	apr='-f-'
c	if(kpr.eq.1)print 71,apr,(f(i),i=1,n)

	apr='-psi-'
c	if(kpr.eq.1)print 71,apr,(psi(i),i=1,n)

	do i=2,n
	pp(i)=0.5*(ppx(i)+ppx(i-1))
	pff(i)=0.5*(pffx(i)+pffx(i-1))
	end do

	pp(1)=ppx(1)
	pff(1)=pffx(1)

c	p(n)=0.

	fsqrt0=p(n)
	do i0=2,n
	i=n-i0+2
	pprime=-pp(i)
	fhelp=pprime*(psi(i)/(2.*pi*rs0))
	fsqrt=fsqrt0-fhelp*ha(i)
	fsqrt0=fsqrt
	p(i-1)=fsqrt
	end do
c-----------------

	do i=1,n
	do j=1,mp
	xpl(i,j)=x_map(i,j)
	ypl(i,j)=y_map(i,j)
	end do
	end do
c
	call midc(n,mp,rs0)

	coef=10./(4.*pi)

	tpl_1=-coef*c2(n)*psi(n)

	if(kpr.eq.1)print *,'tpl  tpl_1 ',tpl,tpl_1

c---->  Fx(I) variable...
c
	do i=2,n
	fx(i)=0.5*(f(i)+f(i-1))
	end do

	fx(1)=fx(2)
	do i=2,n
	f(i)=fx(i)
	pfi(i)=2.*pi*rs0*c3(I)*f(i)
	q(i)=-pfi(i)/psi(i)
	dfmaxc(i)=dfmaxc(i-1)+pfi(i)*ha(i)

	end do

	q(1)=q(2)

	apr='-m-pp-'
	if(kpr.eq.1)print 71,apr,(pp(i),i=1,n)
	apr='-pff-'
	if(kpr.eq.1)print 71,apr,(pff(i),i=1,n)
	apr='-q-'
c	if(kpr.eq.1)print 71,apr,(q(i),i=1,n)

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))
c

	return
	end
c
c
	subroutine feet_in(psi,x,n,aval,xp)

      include 'double.inc'
	dimension psi(*),x(*)

	character *20 apr

71 	FORMAT(20X,A6/,(6E11.4))

	k=0
	n1=n-1
	
	apr='psi'
c	if(kpr.eq.1)print 71,apr,(psi(i),i=1,n)

	apr='x'
c	if(kpr.eq.1)print 71,apr,(x(i),i=1,n)

c	if(kpr.eq.1)print *,' n1 aval',n1,aval

	do i=1,n1


	if(abs(psi(i)-aval).le.1.e-5*abs(aval))then
	call feet_lin(psi,x,n,aval,xp)
	return
	end if

	if( (aval-psi(i+1))*(aval-psi(i)).ge.0.)go to 11

	if( (i-1)*(i-n1).lt.0) then
	k=k+1

	xp=x(i)
	

	call fit(2,x(i-1),x(i),x(i+1),x(i+2),psi(i-1),
     *  psi(i),psi(i+1),psi(i+2),xp,aval,yq)

c	if(kpr.eq.1)print *,' i x(i) xp psi',i,x(i),xp,psi(i)

	end if
c
	if( i.eq.1) then
	k=k+1

	xp=x(i)

	call fit(2,x(i),x(i+1),x(i+2),x(i+3),psi(i),
     *  psi(i+1),psi(i+2),psi(i+3),xp,aval,yq)

c	if(kpr.eq.1)print *,' i x(i) xp psi',i,x(i),xp,psi(i)


	end if
c
	if( i.eq.n1) then
	k=k+1

	xp=x(i)

	call fit(2,x(i-2),x(i-1),x(i),x(i+1),psi(i-2),
     *  psi(i-1),psi(i),psi(i+1),xp,aval,yq)

c	if(kpr.eq.1)print *,' i x(i) xp psi',i,x(i),xp,psi(i)


	end if
c
11	continue

	end do

	if(k.gt.1)then
	   if(kpr.eq.1)print *,' k GT 1 ==',k

	call feet_lin(psi,x,n,aval,xp)

c!!!	   read (*,*)
	end if

	return
	end

	subroutine feet_lin(psi,x,n,aval,xp)

      include 'double.inc'
	dimension psi(*),x(*)

	xzer(x1,x2,v1,v2) = (x1*v2-x2*v1)/(v2-v1+1.d-15)

	do i=1,n-1

	u1=psi(i)-aval
	u2=psi(i+1)-aval

	if(u2*u1.le.0.) then

	   xp = xzer(x(i+1),x(i),u2,u1)

	end if
	
	end do


	return
	end
	subroutine c_ctime(apr,n)
	character *20 apr
c	t_t2=c_time()
	t_t=t_t2-t_t1
	t_t1=t_t2

	if(kpr.eq.1)print *,apr(1:n),' time=',t_t
	return
	end

