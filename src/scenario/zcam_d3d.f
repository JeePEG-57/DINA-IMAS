	subroutine loopflux()
	include 'double.inc'
c	implicit real *8(a-h,o-z)
	include 'parf1'
	include 'parf4'
        common
     *  /ge1/pi
     *  /ge2/ntay,tay,tt
     *  /ge5/kpr
	common
     *  /svd1/psloop_e(nloop),bprobe_e(nprobe)
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
	common
     *  /loop1/kloop,RL(nloop),ZL(nloop),psloop(nloop)
     *  /loop2/pfgreen(nloop,kf),vesgreen(nloop,mu)
     *  /loop3/vloop,psf1a,psf1a0
     *  /loop6/psloopp(nloop)
	character*70 apr
c
c   vessel currents
	apr='psi by PLASMA'
c	if(kpr.eq.1)print 71,apr,(psloopp(i),i=1,kloop)

	do i=1,kloop
	psloop(i)=psloopp(i)

	do j=1,ncam
	psloop(i)=psloop(i)+vesgreen(i,j)*tcam(j)
	end do
	end do
	apr='psi by PLASMA+VES'
c	if(kpr.eq.1)print 71,apr,(psloop(i),i=1,kloop)
c===============================
c   pf coils
	do i=1,kloop
	do j=1,npf
	psloop(i)=psloop(i)+pfgreen(i,j)*pf(j)
	end do
	end do
	apr='psi by PLASMA+VES+PF'
c	if(kpr.eq.1)print 71,apr,(psloop(i),i=1,kloop)

c   transformation to volt*second/2pi
	do i=1,kloop
	psloop(i)=psloop(i)*1.e-5/(2.*pi)
	end do
c
	apr='psi in loops by pl+cam+coils,V*s/2pi (loopflux)'
c	if(kpr.eq.1)print 71,apr,(psloop(i),i=1,kloop)
	apr='psi in loops EXP'
c	if(kpr.eq.1)print 71,apr,(psloop_e(i),i=1,kloop)

C  SUBSTRACT PSF1A FLUX
	PSF1A=PSLOOP(1)
	DO I=1,KLOOP
!!!	PSLOOP(I)=PSLOOP(I)-PSF1A
	END DO

        vloop=2.*pi*(psf1a-psf1a0)/(tay*1.e-3)

71	format(5x,a70/,(1X,6(1pe11.3)))
	return
	end

	subroutine probefield()
	include 'double.inc'
c	implicit real *8(a-h,o-z)
	include 'parf1'
	include 'parf4'
	common
     *  /svd1/psloop_e(nloop),bprobe_e(nprobe)
        common
     *  /ge1/pi
     *  /ge5/kpr
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *  /probe1/kprobe,bprobe(nprobe)
     *  /probe2/pfprobe(nprobe,kf),vesprobe(nprobe,mu)
     *  /probe5/bprobep(nprobe)
	character*70 apr,ms

	do i=1,kprobe
c   plasma
	bprobe(i)=bprobep(i)
c   pf coils
	do j=1,npf
	bprobe(i)=bprobe(i)+pfprobe(i,j)*pf(j)
	end do
	end do
c
c
c***********************
c   vessel currents
	do i=1,kprobe
	do j=1,ncam
	bprobe(i)=bprobe(i)+vesprobe(i,j)*tcam(j)
	end do
	end do
c   transformation to tesla
	do i=1,kprobe
	bprobe(i)=bprobe(i)*0.1
	end do
	apr='bprobe'
c	if(kpr.eq.1)print 71,apr,(bprobe(i),i=1,kprobe)
	apr='bp_e'
c	if(kpr.eq.1)print 71,apr,(bprobe_e(i),i=1,kprobe)
c===============================
71	format(5x,a70/,(1X,6(1pe11.3)))
	return
	end


	subroutine read_sh_for()
	include 'double.inc'
	include 'parf1'
	include 'parf4'

c
	common
     *  /ge1e/rs0,tpl
     *  /ge2/ntay,tay,tt
	common
     *  /svd1/psloop_e(nloop),bprobe_e(nprobe)
     *  /svd2/pf_e(kf)

	common /fwt/fwtp(nloop),fwtb(nprobe)

	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /probe1/kprobe,bprobe(nprobe)
	common
     *  /loop1/kloop,RL(nloop),ZL(nloop),psloop(nloop)

	dimension pfexp(kf,2),psloop_ex(nloop,2),
     *  bprobe_ex(nprobe,2)
c
	character*70 apr
	character*110 tmp,fshot
c---
	open (unit=40,file='shot.fl',form='formatted')
	read (40,*)
	read (40,74)fshot
74	format(a110)
	if(kpr.eq.1)print *,' ----  ',fshot

	close (40)

c


	open (unit=50,file=fshot,form='unformatted')

	open (unit=51,file='sh_form',status='old',
     *  form='formatted')

c-------------------------------
	read (51,*)ktime,npf_e,kloop_e,kprobe_e	
	if(kpr.eq.1)print *,'ktime,npf_e,kloop_e,kprobe_e',ktime,
     *  npf_e,kloop_e,kprobe_e

	write (50)ktime,npf_e,kloop_e,kprobe_e	
	if(kpr.eq.1)print *,'ktime,npf_e,kloop_e,kprobe_e',ktime,
     *  npf_e,kloop_e,kprobe_e

	do  jt=1,ktime
c
	read (51,*)time_e,tpl_e,(pfexp(i,2),i=1,npf_e),(psloop_ex(i,2),
     *  i=1,kloop_e),(bprobe_ex(i,2),i=1,kprobe_e)
c
	write (50)time_e,tpl_e,(pfexp(i,2),i=1,npf_e),(psloop_ex(i,2),
     *  i=1,kloop_e),(bprobe_ex(i,2),i=1,kprobe_e)

	end do


	close (50)
	close (51)


71	format(5x,a10/,(1X,6(1pe11.3)))

	return
	end

	subroutine read_sh()
	include 'double.inc'
	include 'new_com.inc'

	if(kpr.eq.1)print *,' tpl_exp===',tpl_exp
	call read_sh_c(
     *  tpl_exp)

	if(kpr.eq.1)print *,' tpl_exp===',tpl_exp
	
	return
	end

	subroutine read_sh_c(
     *  tpl_exp)

	include 'double.inc'
	include 'parf1'
	include 'parf4'

c
	common
     *  /ge1e/rs0,tpl
     *  /ge2/ntay,tay,tt
	common
     *  /svd1/psloop_e(nloop),bprobe_e(nprobe)
     *  /svd2/pf_e(kf)

	common /fwt/fwtp(nloop),fwtb(nprobe)

	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /probe1/kprobe,bprobe(nprobe)
	common
     *  /loop1/kloop,RL(nloop),ZL(nloop),psloop(nloop)

	dimension pfexp(kf,2),psloop_ex(nloop,2),
     *  bprobe_ex(nprobe,2)
c
	character*70 apr
	character*110 tmp,fshot
c---
	i_sh=i_sh+1
	if(i_sh.eq.1)then

     	open(unit=2,file='fwt.fl',status='old',form='formatted')
	read (2,*)
	read (2,74)tmp
	if(kpr.eq.1)print *,tmp
	close (2)
c---
	open (unit=41,file=tmp,form='formatted')
	read (41,*)
	read (41,*)(fwtp(i),i=1,kloop)
	read (41,*)
	read (41,*)(fwtb(i),i=1,kprobe)
	close (41)


	open (unit=40,file='shot.fl',form='formatted')
	read (40,*)
	read (40,74)fshot
74	format(a110)
	if(kpr.eq.1)print *,' ----  ',fshot
	close (40)
	end if
c
	open (unit=50,file=fshot,status='old',
     *  form='unformatted')
c-------------------------------
	read (50)ktime,npf_e,kloop_e,kprobe_e	
	if(kpr.eq.1)print *,'ktime,npf_e,kloop_e,kprobe_e',ktime,
     *  npf_e,kloop_e,kprobe_e

	do  jt=1,ktime
c
	do i=1,npf
	pfexp(i,1)=pfexp(i,2)
	end do

	do i=1,kloop
	psloop_ex(i,1)=psloop_ex(i,2)
	end do

	do i=1,kprobe
	bprobe_ex(i,1)=bprobe_ex(i,2)
	end do
c
	time_e1=time_e
	tpl_e1=tpl_e
c
	read (50)time_e,tpl_e,(pfexp(i,2),i=1,npf_e),(psloop_ex(i,2),
     *  i=1,kloop),(bprobe_ex(i,2),i=1,kprobe)
	if(time_e.gt.tt) go to 800
	end do

800	continue
	close (50)

	do i=1,kloop
	psloop_e(i)=t_inter( tt,time_e1,time_e,
     *  psloop_ex(i,1),psloop_ex(i,2) )
	end do

	do i=1,kprobe
	bprobe_e(i)=t_inter( tt,time_e1,time_e,
     *  bprobe_ex(i,1),bprobe_ex(i,2) )
	end do

	do i=1,npf
	pf_e(i)=t_inter( tt,time_e1,time_e,
     *  pfexp(i,1),pfexp(i,2) )

	pf(i)=pf_e(i)

	end do

	tpl=t_inter( tt,time_e1,time_e,
     *  tpl_e1,tpl_e )
	tpl=tpl*1.e-3
	
	tpl_exp=tpl
	
	if(kpr.eq.1)print *,'time_e tt time_e1 ',
     *  time_e,tt,time_e1
	if(kpr.eq.1)print *,' tpl_e tpl_e1 tpl',
     *  tpl_e,tpl_e1,tpl

c	pause ' tpl======'
	apr='pf'
	if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf)
	apr='psloop'
	if(kpr.eq.1)print 71,apr,(psloop_e(i),i=1,kloop)
	apr='bprobe'
	if(kpr.eq.1)print 71,apr,(bprobe_e(i),i=1,kprobe)

	kloop=kloop_e
	kprobe=kprobe_e
c
	if(kpr.eq.1)print *,' kloop kprobe tpl_exp',kloop,kprobe,tpl_exp

71	format(5x,a10/,(1X,6(1pe11.3)))

	return
	end


	subroutine ful()
c--------------------------------------------
c  calculate vessel currents
c--------------------------------------------
	include 'double.inc'
	include 'parf1'
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves3/b(mu,mu),pmj(mu,mu)
     *  /ves4/rcam(mu)
     *  /ves5/pfc(mu,kf)
     *  /ves6/pind(mu),pind0(mu),pindn(mu)
     *  /ves9/tokc,tokc0
	common
     *  /ge2/ntay,tay,tt
     *  /ge5/kpr

	dimension fu(mu),ttest(mu),pfil(mu)
	character*70 apr
	DIMENSION f(kf)
c
c
	beta=1.
c	beta=0.
	alf=1.

	do i=1,ncam
	pind(i)=0.
	end do
	do i=1,ncam
c	call is(f,rc(i),zc(i))
	do j=1,npf
	f(j)=pfc(i,j)
	pind(i)=pind(i)+f(j)*pf(j)
	end do
	end do
c____________________________________________
	apr='psp'
c	if(kpr.eq.1)print 71,apr,(psp(j),j=1,ncam)

	apr='pind'
c	if(kpr.eq.1)print 71,apr,(pind(j),j=1,ncam)
	apr='pind0'
c	if(kpr.eq.1)print 71,apr,(pind0(j),j=1,ncam)

	i_en=i_en+1

	if(i_en.le.1)return
c_____________________________________________
        volt_pf=0.
        volt_pl=0.

	do i=1,ncam
	fu(i)=0.

	volt_pf=volt_pf-alf*(pind(i)-pind0(i))/(tay*100.)
	volt_pl=volt_pl-beta*(psp(i)-psp0(i))/(tay*100.)
c
	do j=1,ncam
	fu(i)=fu(i)+pmj(i,j)*tcam0(j)
	end do
c
	fu(i)=fu(i)-beta*(psp(i)-psp0(i))-alf*(pind(i)-pind0(i))
	end do
c***************************************************************

	volt_pf=volt_pf/ncam
	volt_pl=volt_pl/ncam

	do i=1,ncam
	tcam(i)=0.
	ttest(i)=(-beta*(psp(i)-psp0(i))-alf*(pind(i)-pind0(i)))
     *  /tay*1.e-2/rcam(i)*1.e-3
	do k=1,ncam
	tcam(i)=tcam(i)+b(i,k)*fu(k)
	end do
	end do
c
	apr='tcm0, kA (ful)'
c	if(kpr.eq.1)print 71,apr,(tcam0(j),j=1,ncam)
c
	apr='tcam, kA (ful)'
c	if(kpr.eq.1)print 71,apr,(tcam(j),j=1,ncam)
	apr='test, kA (ful)'
c	if(kpr.eq.1)print 71,apr,(ttest(i),i=1,ncam)
	tokc=0.
	tokc0=0.
	tok_t=0.
	do i=1,ncam
	tokc=tokc+tcam(i)
	tokc0=tokc0+tcam0(i)
	tok_t=tok_t+ttest(i)
	end do
c	if(kpr.eq.1)print *,'TOKC=tokc0 tok_t----------------',TOKC,tokc0,tok_t
c	if(kpr.eq.1)print *,'volt_pf volt_pl-----------',volt_pf,volt_pl
c        read (*,*)
c
c===============================
71	format(5x,a10/,(1X,6(1pe11.3)))
	return
	end

