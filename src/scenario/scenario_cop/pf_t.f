	subroutine svd_0()
	include 'double.inc'
	include 'parf0'
	include 'parf1'
	include 'parf2'
	include 'parf5'
	common
     *  /ge1/pi
	common
     *  /ge12/nps,rps(ntet),zps(ntet)
     *  /ge12e/indpf(kf),seps1,seps2,seps3

	common
     *  /eq1/psi(nr,nz),pspl(nwnh),r(nr),z(nz),dr,dz

	dimension amat(nx,mx),y(nx),
     *  jpf(kf),sig(nx),a(kf)

	character *8 mpr,apr
c
	dimension psi_c(nx),work(nwnh),yw(nx)
c
71	format(20x,a6/,(6(1pe10.3)))

c-------------------------

	open(unit=41,file='test_b',form='formatted')
	read (41,*)
	read (41,*)x1,y1
	read (41,*)
	read (41,*)rmag,zmag
	read (41,*)
	read (41,*)rref,zref
	read (41,*)
	read (41,*)i_1,j_1,seps1,seps2
	close (41)

	alfa=rmag
	beta=zmag

	ma=4
	nps=9
	ndata=nps+2

	if(kpr.eq.1)print *,'nps ma ndata ',nps,ma,ndata
	if(kpr.eq.1)print *,' i j seps1 ',i_1,j_1,seps1
	if(kpr.eq.1)print *,' alfa beta ',alfa,beta

c
	do i=1,ndata
	do j=1,ma
	amat(i,j)=0.
	end do
	end do

	i=i_1
	j=j_1

	do ii=1,nps
	if(ii.eq.1)then
	psi_c(ii)=psi(i,j)
	rps(ii)=r(i)
	zps(ii)=z(j)
	end if
	if(ii.eq.2)then
	psi_c(ii)=psi(i+1,j)
	rps(ii)=r(i+1)
	zps(ii)=z(j)
	end if
	if(ii.eq.3)then
	psi_c(ii)=psi(i+1,j+1)
	rps(ii)=r(i+1)
	zps(ii)=z(j+1)
	end if
	if(ii.eq.4)then
	psi_c(ii)=psi(i,j+1)
	rps(ii)=r(i)
	zps(ii)=z(j+1)
	end if
	if(ii.eq.5)then
	psi_c(ii)=psi(i-1,j+1)
	rps(ii)=r(i-1)
	zps(ii)=z(j+1)
	end if
	if(ii.eq.6)then
	psi_c(ii)=psi(i-1,j)
	rps(ii)=r(i-1)
	zps(ii)=z(j)
	end if
	if(ii.eq.7)then
	psi_c(ii)=psi(i-1,j-1)
	rps(ii)=r(i-1)
	zps(ii)=z(j-1)
	end if
	if(ii.eq.8)then
	psi_c(ii)=psi(i,j-1)
	rps(ii)=r(i)
	zps(ii)=z(j-1)
	end if
	if(ii.eq.9)then
	psi_c(ii)=psi(i+1,j-1)
	rps(ii)=r(i+1)
	zps(ii)=z(j-1)
	end if

	psi_c(ii)=(rps(ii)-alfa)**2/x1+(zps(ii)-beta)**2/y1

	end do

	psmax=0.
c
c   here start npoints of given flux....

	do ii=1,nps
	urr=rps(ii)
	vrr=zps(ii)
	if(kpr.eq.1)print *,'ii rps zps psi',ii,rps(ii),zps(ii),psi_c(ii)
c
	y(ii)=psi_c(ii)
	yw(ii)=y(ii)

	if( psmax.lt.abs(y(ii)) )psmax=abs( y(ii) )
c
	do 100 jj=1,ma
	if(jj.eq.1)amat(ii,jj)=urr**2
	if(jj.eq.2)amat(ii,jj)=alfa-2.*urr
	if(jj.eq.3)amat(ii,jj)=vrr**2
	if(jj.eq.4)amat(ii,jj)=beta-2.*vrr

c	if(jj.eq.1)amat(ii,jj)=urr**2+alfa**2
c	if(jj.eq.2)amat(ii,jj)=-2.*urr
c	if(jj.eq.3)amat(ii,jj)=vrr**2+beta**2
c	if(jj.eq.4)amat(ii,jj)=-2.*vrr
100	continue

	end do

	ii=ii+1
	amat(ii,1)=alfa
	amat(ii,2)=-1.
	y(ii)=0.
	ii=ii+1
	amat(ii,3)=beta
	amat(ii,4)=-1.
	y(ii)=0.

	if(kpr.eq.1)print *,' psmax==',psmax
c  here sigmas to npoints.....
	do i=1,nps
c	sig(i)=seps1*psmax
	sig(i)=seps1*abs(y(i))
c	sig(i)=1.
	end do

	do i=nps+1,nps+2
c	sig(i)=seps1*psmax
	sig(i)=seps2
	end do
	namat=nx
	call svdfit(amat,y,sig,ndata,a,ma,namat)

	alfa1=a(2)/a(1)
	beta1=a(4)/a(3)

	if(kpr.eq.1)print *,' alfa alfa1',alfa,alfa1

	if(kpr.eq.1)print *,' beta beta1',beta,beta1

	do ii=1,ndata
	flux=0.
	do jj=1,ma
	flux=flux+amat(ii,jj)*a(jj)
	end do
	if(kpr.eq.1)print *,'ii flux y sig  ',ii,flux,yw(ii),sig(ii)
	end do
	apr='a'
	if(kpr.eq.1)print 71,apr,(a(i),i=1,ma)
c
	read (*,*)
c
	return
	end
c
c*** without X-points **********************
	subroutine gsvd_0()
	include 'double.inc'
	include 'parf0'
	include 'parf1'
	include 'parf2'
	include 'parf5'
	common
     *  /ge1/pi
     *  /ge2/NTAY,TAY,TT
     *  /ge5/kpr
	common
     *  /ge12/nps,rps(ntet),zps(ntet)
     *  /ge12e/indpf(kf),seps1,seps2,seps3
     *  /ge12e1/seps_pf(kf),pf_max(kf)
	common
     *	/keys6/i_svd,i_cal,kpf
        common
     *  /time1e/pf_ex(kf)
c=====================
	common
     *  /eq1/psi(nr,nz),pspl(nwnh),r(nr),z(nz),dr,dz
     *  /eq3/FLUXARR(nwnh,kf)
     *  /eq10/vesarr(nwnh,mu)
c  for tac_8 ---[
     *  /eq14e/rsep_pf,zsep_pf
     *  /eq15/pll,zsep,rsep,zsepup,rsepup,zsepdw,rsepdw
c  for tac_8 ---]
	common
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *  /pf1/npf,pf(kf),pf0(kf)
c
	dimension amat(nx,mx),y(nx),
     *  jpf(kf),sig(nx),a(kf)
	character *8 mpr,apr
c
	dimension pdd(6),pfc(kf)
	dimension work(nwnh),yw(nx)
c
71	format(20x,a6/,(6(1pe10.3)))
c
	api=1./(2.*pi)
	do i=1,npf
	if(kpf.eq.0)pfc(i)=0.
	if(kpf.eq.1)pfc(i)=pf_ex(i)
	end do
c	dpomax1=1./dpomax
	dpomax1=1.e-4
c---------------------
        if(ntay.gt.2)then
	rps(nps)=rsep_pf
        zps(nps)=zsep_pf
        end if
c-------------------
c
	k=0
	do i=1,npf
	k=k+indpf(i)
	if(indpf(i).ne.0)jpf(k)=i
	end do
	ma=k+1
	ma1=ma-1
	ndata=nps+ma1
c
c    additional condition for separatrix
c
c	ndata=ndata+2
c    additional condition for second separatrix
c
c	ndata=ndata+2
c--------------------------------------
	if(kpr.eq.1)print *,'nps ma ndata ',nps,ma,ndata
c
	do i=1,ndata
	do j=1,ma
	amat(i,j)=0.
	end do
	end do
c
	pbound1=pbound*dpomax1
	if(kpr.eq.1)print *,'pbound1=',pbound1
	psmax=0.
c
c   here start npoints of constant flux....
	do ii=1,nps
	urr=rps(ii)
	vrr=zps(ii)
	if(kpr.eq.1)print *,'ii rps zps',ii,rps(ii),zps(ii)
c
	y(ii)=0.
c
	do 99 jj=1,npf
c
	if(indpf(jj).eq.0)then
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,jj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
	y(ii)=y(ii)-pdd(1)*pf(jj)*dpomax1
c
	end if
99	continue
c
	i_c=0
	if (i_c.eq.1)then
	DO 66 K=1,ncam
c
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*vesarr(kk,K)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	y(ii)=y(ii)-pdd(1)*tcam(K)*dpomax1
66	continue
c
	end if
	i_c=1
	if (i_c.eq.1)then

c
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
        pscam=0.
	DO 67 K=1,ncam
	pscam=pscam+api*vesarr(kk,K)*tcam(k)
67	continue
	work(kk1)=pscam
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	y(ii)=y(ii)-pdd(1)*dpomax1
c
	end if
c
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=pspl(kk)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
c
	y(ii)=y(ii)-pdd(1)*dpomax1
	yw(ii)=y(ii)
	if( psmax.lt.abs(y(ii)) )psmax=abs( y(ii) )
c
	do 100 jj=1,ma1
	kjj=jpf(jj)
c	if(kpr.eq.1)print *,'ii jj kjj',ii,jj,kjj
c-----------------------
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,kjj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
c----------------------------
c   here we determine A matrix
	amat(ii,jj)=fint*dpomax1
100	continue
c
c   here boundary flux value----
	amat(ii,ma)=-1.
c------------------------
	end do
c  here sigmas to npoints.....
	do i=1,nps
	sig(i)=seps1*psmax
c	sig(i)=1.
	end do
c---------------------------------------------
c
c
	k=0
	pfmax=0.
	do i=nps+1,nps+ma1
	k=k+1
	kjj=jpf(k)
	y(i)=pfc(kjj)
c------------------------------
	sig(i)=seps2*seps_pf(kjj)*pf_max(kjj)
c-----------------------------
	if(pfmax.lt.abs(pf(kjj)))pfmax=abs(pf(kjj))
	amat(nps+k,k)=1.
	end do
c-----------------------------------
c   here sigmas to ma1 PF-current points (nps+ma1)
	do i=nps+1,nps+ma1
c	sig(i)=seps2*pfmax
c	sig(i)=1.
	end do
c-------------------------------------------
c
	namat=nx
	call svdfit(amat,y,sig,ndata,a,ma,namat)
	apr='pf'
c	if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf)
	do k=1,ma1
	kjj=jpf(k)
	if(kpr.eq.1)print *,'k jpf pf_ex a pf_max',k,jpf(k),
     *  pf_ex(kjj),a(k),pf_max(kjj)
	pf(kjj)=a(k)
	end do
	pboundc=a(ma)
	if(kpr.eq.1)print *,'pboundc=',pboundc
c
	do ii=1,nps
	flux=0.
	do jj=1,ma1
	flux=flux+amat(ii,jj)*a(jj)
	end do
	flux=flux-yw(ii)
	if(kpr.eq.1)print *,'ii flux a ',ii,flux,a(ma)
	end do
c
c
	return
	end
c

c
c***** double X-points ***************
	subroutine gsvd2()
	include 'double.inc'
c	implicit real *8 (a-h,o-z)
c
	include 'parf0'
	include 'parf1'
	include 'parf2'
	include 'parf5'
	common
     *  /ge1/pi
     *  /ge5/kpr
	common
     *  /ge12/nps,rps(ntet),zps(ntet)
     *  /ge12e/indpf(kf),seps1,seps2,seps3
	common
     *	/keys6/i_svd,i_cal,kpf
c=====================
	common
     *  /eq1/psi(nr,nz),pspl(nwnh),r(nr),z(nz),dr,dz
     *  /eq3/FLUXARR(nwnh,kf)
     *  /eq10/vesarr(nwnh,mu)
	common
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *  /pf1/npf,pf(kf),pf0(kf)
c
	character *8 mpr,apr
c
	dimension amat(nx,mx),y(nx),jpf(kf),sig(nx),a(kf)
	dimension pdd(6),pfc(kf)
	dimension work(nwnh),yw(nx)

c
71	format(20x,a6/,(6(1pe10.3)))
c
	api=1./(2.*pi)
	do i=1,npf
	if(kpf.eq.0)pfc(i)=0.
	if(kpf.eq.1)pfc(i)=pf0(i)
	end do
c	dpomax1=1./dpomax
	dpomax1=1.e-4
c
	k=0
	do i=1,npf
	k=k+indpf(i)
	if(indpf(i).ne.0)jpf(k)=i
	end do
	ma=k+1
	ma1=ma-1
	ndata=nps+ma1
c
c    additional condition for separatrix
c
	ndata=ndata+2
c    additional condition for second separatrix
c
	ndata=ndata+2
c--------------------------------------
	if(kpr.eq.1)print *,'nps ma ndata ',nps,ma,ndata
c
	do i=1,ndata
	do j=1,ma
	amat(i,j)=0.
	end do
	end do
c
	pbound1=pbound*dpomax1
	if(kpr.eq.1)print *,'pbound1=',pbound1
	psmax=0.
c
c   here start npoints of constant flux....
	do ii=1,nps
	urr=rps(ii)
	vrr=zps(ii)
	if(kpr.eq.1)print *,'ii rps zps',ii,rps(ii),zps(ii)
c
	y(ii)=0.
c
	do 99 jj=1,npf
c
	if(indpf(jj).eq.0)then
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,jj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
	y(ii)=y(ii)-pdd(1)*pf(jj)*dpomax1
c
	end if
99	continue
c
	DO 66 K=1,ncam
c
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*vesarr(kk,K)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	y(ii)=y(ii)-pdd(1)*tcam(K)*dpomax1
66	continue
c
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=pspl(kk)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
c
	y(ii)=y(ii)-pdd(1)*dpomax1
	yw(ii)=y(ii)
	if( psmax.lt.abs(y(ii)) )psmax=abs( y(ii) )
c
	do 100 jj=1,ma1
	kjj=jpf(jj)
c	if(kpr.eq.1)print *,'ii jj kjj',ii,jj,kjj
c-----------------------
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,kjj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
c----------------------------
c   here we determine A matrix
	amat(ii,jj)=fint*dpomax1
100	continue
c
c   here boundary flux value----
	amat(ii,ma)=-1.
c------------------------
	end do
c  here sigmas to npoints.....
	do i=1,nps
	sig(i)=seps1*psmax
c	sig(i)=1.
	end do
c---------------------------------------------
c
c
	k=0
	pfmax=0.
	do i=nps+1,nps+ma1
	k=k+1
	kjj=jpf(k)
	y(i)=pfc(kjj)
	if(pfmax.lt.abs(pf(kjj)))pfmax=abs(pf(kjj))
	amat(nps+k,k)=1.
	end do
c************************************************
c	pfmax=5000.
c-----------------------------------
c   here sigmas to ma1 PF-current points (nps+ma1)
	do i=nps+1,nps+ma1
	sig(i)=seps2*pfmax
c	sig(i)=1.
	end do
c-------------------------------------------
c
c   here condition to separatrix points
c
	ii=nps+ma1+1
	ii=ii-2
	do 50 ksep=1,2
	ii=ii+2
c------------------------------
c   here coordinates of separatix.....
	if(ksep.eq.1)then
	urr=rps(2)
	vrr=zps(2)
	end if
c
	if(ksep.eq.2)then
	urr=rps(nps)
	vrr=zps(nps)
	end if
c---------------------------------
	y(ii)=0.
	y(ii+1)=0.
	psmax=0.
c
	do 98 jj=1,npf
c
	if(indpf(jj).eq.0)then
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,jj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	psi_r=pdd(2)
	psi_z=pdd(3)
	y(ii)=y(ii)-psi_r*pf(jj)*dpomax1
	y(ii+1)=y(ii+1)-psi_z*pf(jj)*dpomax1
c
	end if
98	continue
c
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=pspl(kk)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	psi_r=pdd(2)
	psi_z=pdd(3)
	y(ii)=y(ii)-psi_r*dpomax1
	y(ii+1)=y(ii+1)-psi_z*dpomax1
	yw(ii)=y(ii)
	yw(ii+1)=y(ii+1)
c
	if( psmax.lt.abs(y(ii)) )psmax=abs( y(ii) )
c
	do 101 jj=1,ma1
	kjj=jpf(jj)
c	if(kpr.eq.1)print *,'ii jj kjj',ii,jj,kjj
c-----------------------
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,kjj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
c
	psi_r=pdd(2)
	psi_z=pdd(3)
c----------------------------
c   here we determine A matrix
	amat(ii,jj)=psi_r*dpomax1
	amat(ii+1,jj)=psi_z*dpomax1
101	continue
c   here sigma for separatrix.....
c
	sig(ii)=seps1*psmax
	sig(ii+1)=seps1*psmax
50	continue
c
	namat=nx
	call svdfit(amat,y,sig,ndata,a,ma,namat)
	apr='pf'
c	if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf)
	do k=1,ma1
	kjj=jpf(k)
	if(kpr.eq.1)print *,'k jpf pf0 a',k,jpf(k),pf0(kjj),a(k)
	pf(kjj)=a(k)
	end do
	pboundc=a(ma)
	if(kpr.eq.1)print *,'pboundc=',pboundc
c
	do ii=1,nps
	flux=0.
	do jj=1,ma1
	flux=flux+amat(ii,jj)*a(jj)
	end do
	flux=flux-yw(ii)
	if(kpr.eq.1)print *,'ii flux a ',ii,flux,a(ma)
	end do
c
	do ii=nps+ma1+1,nps+ma1+4
c
	flux=0.
	do jj=1,ma1
	flux=flux+amat(ii,jj)*a(jj)
	end do
	flux=flux-yw(ii)
	if(kpr.eq.1)print *,'ii gradpsi  ',ii,flux
	end do
c
	return
	end
c
c*** single X-point **********************
	subroutine gsvd1()
	include 'double.inc'
	include 'parf0'
	include 'parf1'
	include 'parf2'
	include 'parf5'
	common
     *  /ge1/pi
	common
     *  /ge5/kpr
     *  /ge12/nps,rps(ntet),zps(ntet)
     *  /ge12e/indpf(kf),seps1,seps2,seps3
	common
     *	/keys6/i_svd,i_cal,kpf
c=====================
	common
     *  /eq1/psi(nr,nz),pspl(nwnh),r(nr),z(nz),dr,dz
     *  /eq3/FLUXARR(nwnh,kf)
     *  /eq10/vesarr(nwnh,mu)
	common
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *  /pf1/npf,pf(kf),pf0(kf)
c
	dimension amat(nx,mx),y(nx),
     *  jpf(kf),sig(nx),a(kf),pmax(nx)
	character *8 mpr,apr
c
	dimension pdd(6),pfc(kf)
	dimension work(nwnh),yw(nx)
c------------------------------------
71	format(20x,a6/,(6(1pe10.3)))
c
	api=1./(2.*pi)
	do i=1,npf
	if(kpf.eq.0)pfc(i)=0.
	if(kpf.eq.1)pfc(i)=pf0(i)
	end do
c	dpomax1=1./dpomax
	dpomax1=1.e-4
c
	k=0
	do i=1,npf
	k=k+indpf(i)
	if(indpf(i).ne.0)jpf(k)=i
	end do
	ma=k+1
	ma1=ma-1
	ndata=nps+ma1
c
c    additional condition for separatrix
c
	ndata=ndata+2
c    additional condition for second separatrix
c
c	ndata=ndata+2
c--------------------------------------
	if(kpr.eq.1)print *,'nps ma ndata ',nps,ma,ndata
c
	do i=1,ndata
	do j=1,ma
	amat(i,j)=0.
	end do
	end do
c
	pbound1=pbound*dpomax1
	if(kpr.eq.1)print *,'pbound1=',pbound1
	psmax=0.
c
c   here start npoints of constant flux....
	do ii=1,nps
	urr=rps(ii)
	vrr=zps(ii)
	if(kpr.eq.1)print *,'ii rps zps',ii,rps(ii),zps(ii)
c
	y(ii)=0.
c
	do 99 jj=1,npf
c
	if(indpf(jj).eq.0)then
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,jj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
	y(ii)=y(ii)-pdd(1)*pf(jj)*dpomax1
c
	end if
99	continue
c
	icam=1
	if(icam.eq.1)then
	DO 66 K=1,ncam
c
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*vesarr(kk,K)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	y(ii)=y(ii)-pdd(1)*tcam(K)*dpomax1
66	continue
	end if
c
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=pspl(kk)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
c
	y(ii)=y(ii)-pdd(1)*dpomax1
	yw(ii)=y(ii)
	if( psmax.le.abs(y(ii)) )psmax=abs( y(ii) )
	pmax(ii)=abs( y(ii) )
	if(pmax(ii).le.1.e-3)then
	if(kpr.eq.1)print *,' ii pmax',ii,pmax(ii)
	pmax(ii)=1.e-3
	end if
c
	do 100 jj=1,ma1
	kjj=jpf(jj)
c	if(kpr.eq.1)print *,'ii jj kjj',ii,jj,kjj
c-----------------------
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,kjj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
c----------------------------
c   here we determine A matrix
	amat(ii,jj)=fint*dpomax1
100	continue
c
c   here boundary flux value----
	amat(ii,ma)=-1.
c------------------------
	end do
c  here sigmas to npoints.....
	do i=1,nps
	sig(i)=seps1*psmax
c	sig(i)=seps1*pmax(i)
c	sig(i)=1.
	end do
c---------------------------------------------
c
c
	k=0
	pfmax=0.
	do i=nps+1,nps+ma1
	k=k+1
	kjj=jpf(k)
	y(i)=pfc(kjj)
	if(pfmax.le.abs(pf(kjj)))pfmax=abs(pf(kjj))
	pmax(i)=abs( pf(kjj) )
	if(pmax(i).le.1.e-3)then
	if(kpr.eq.1)print *,' i pmax',i,pmax(i)
	pmax(i)=1.e-3
	end if
	amat(nps+k,k)=1.
	end do
c************************************************
c	pfmax=5000.
c-----------------------------------
c   here sigmas to ma1 PF-current points (nps+ma1)
	do i=nps+1,nps+ma1
	sig(i)=seps2*pfmax
c	sig(i)=seps2*pmax(i)
c	sig(i)=1.
	end do
c-------------------------------------------
c
c   here condition to separatrix points
c
	ii=nps+ma1+1
c	ii=ii-2
c	do 50 ksep=1,2
c	ii=ii+2
c------------------------------
c   here coordinates of separatix.....
c	if(ksep.eq.1)then
	urr=rps(nps)
	vrr=zps(nps)
c	end if
c
c	if(ksep.eq.2)then
c	urr=rps(nps)
c	vrr=zps(nps)
c	end if
c---------------------------------
	y(ii)=0.
	y(ii+1)=0.
	psmax=0.
c
	do 98 jj=1,npf
c
	if(indpf(jj).eq.0)then
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,jj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	psi_r=pdd(2)
	psi_z=pdd(3)
	y(ii)=y(ii)-psi_r*pf(jj)*dpomax1
	y(ii+1)=y(ii+1)-psi_z*pf(jj)*dpomax1
c
	end if
98	continue
c
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=pspl(kk)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	psi_r=pdd(2)
	psi_z=pdd(3)
	y(ii)=y(ii)-psi_r*dpomax1
	y(ii+1)=y(ii+1)-psi_z*dpomax1
	yw(ii)=y(ii)
	yw(ii+1)=y(ii+1)
c
	if( psmax.le.abs(y(ii)) )psmax=abs( y(ii) )
	pmax(ii)=abs( y(ii) )
	if(pmax(ii).le.1.e-3)then
	if(kpr.eq.1)print *,' ii pmax',ii,pmax(ii)
	pmax(ii)=1.e-3
	end if
c
	if( psmax.le.abs(y(ii+1)) )psmax=abs( y(ii+1) )
	pmax(ii+1)=abs( y(ii+1) )
	if(pmax(ii+1).le.1.e-3)then
	if(kpr.eq.1)print *,' ii+1 pmax',ii+1,pmax(ii+1)
	pmax(ii+1)=1.e-3
	end if
c
	do 101 jj=1,ma1
	kjj=jpf(jj)
c	if(kpr.eq.1)print *,'ii jj kjj',ii,jj,kjj
c-----------------------
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,kjj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
c
	psi_r=pdd(2)
	psi_z=pdd(3)
c----------------------------
c   here we determine A matrix
	amat(ii,jj)=psi_r*dpomax1
	amat(ii+1,jj)=psi_z*dpomax1
101	continue
c   here sigma for separatrix.....
c
	sig(ii)=seps3*psmax
	sig(ii+1)=seps3*psmax
c	sig(ii)=seps3*pmax(ii)
c	sig(ii+1)=seps3*pmax(ii+1)
c50	continue
c
	namat=nx
	call svdfit(amat,y,sig,ndata,a,ma,namat)
	apr='pf'
c	if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf)
	do k=1,ma1
	kjj=jpf(k)
	if(kpr.eq.1)print *,'k jpf pf0 a',k,jpf(k),pf0(kjj),a(k)
	pf(kjj)=a(k)
	end do
	pboundc=a(ma)
	if(kpr.eq.1)print *,'pboundc=',pboundc
c
	do ii=1,nps
	flux=0.
	do jj=1,ma1
	flux=flux+amat(ii,jj)*a(jj)
	end do
	flux=flux-yw(ii)
	if(kpr.eq.1)print *,'ii flux a ',ii,flux,a(ma)
	end do
c
c	do ii=nps+ma1+1,nps+ma1+4
	do ii=ndata-1,ndata
c
	flux=0.
	do jj=1,ma1
	flux=flux+amat(ii,jj)*a(jj)
	end do
	flux=flux-yw(ii)
	if(kpr.eq.1)print *,'ii gradpsi  ',ii,flux
	end do
c
	return
	end
c
c*** without X-points **********************
	subroutine gsvd0()
	include 'double.inc'
	include 'parf0'
	include 'parf1'
	include 'parf2'
	include 'parf5'
	common
     *  /ge1/pi
     *  /ge5/kpr
	common
     *  /ge12/nps,rps(ntet),zps(ntet)
     *  /ge12e/indpf(kf),seps1,seps2,seps3
	common
     *	/keys6/i_svd,i_cal,kpf
c=====================
	common
     *  /eq1/psi(nr,nz),pspl(nwnh),r(nr),z(nz),dr,dz
     *  /eq3/FLUXARR(nwnh,kf)
     *  /eq10/vesarr(nwnh,mu)
c  for tac_8 ---[
     *  /eq15/pll,zsep,rsep,zsepup,rsepup,zsepdw,rsepdw
c  for tac_8 ---]
	common
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
	common
     *  /pf1/npf,pf(kf),pf0(kf)
c
	dimension amat(nx,mx),y(nx),
     *  jpf(kf),sig(nx),a(kf)
	character *8 mpr,apr
c
	dimension pdd(6),pfc(kf)
	dimension work(nwnh),yw(nx)
c
71	format(20x,a6/,(6(1pe10.3)))
c  for tac_8 ---[
c----
c	rps(nps)=rsep
c	zps(nps)=zsep

c	if(zsepdw.le.zsep)then
c	rps(nps)=rsepdw
c	zps(nps)=zsepdw
c	end if
c
c  for tac_8 ---]
c-----
c
	api=1./(2.*pi)
	do i=1,npf
	if(kpf.eq.0)pfc(i)=0.
	if(kpf.eq.1)pfc(i)=pf0(i)
	end do

c	dpomax1=1./dpomax
	dpomax1=1.e-4
c
	k=0
	do i=1,npf
	k=k+indpf(i)
	if(indpf(i).ne.0)jpf(k)=i
	end do
	ma=k+1
	ma1=ma-1
	ndata=nps+ma1
c
c    additional condition for separatrix
c
c	ndata=ndata+2
c    additional condition for second separatrix
c
c	ndata=ndata+2
c--------------------------------------
	if(kpr.eq.1)print *,'nps ma ndata ',nps,ma,ndata
c
	do i=1,ndata
	do j=1,ma
	amat(i,j)=0.
	end do
	end do
c
	pbound1=pbound*dpomax1
	if(kpr.eq.1)print *,'pbound1=',pbound1
	psmax=0.
c
c   here start npoints of constant flux....
	do ii=1,nps
	urr=rps(ii)
	vrr=zps(ii)
	if(kpr.eq.1)print *,'ii rps zps',ii,rps(ii),zps(ii)
c
	y(ii)=0.
c
	do 99 jj=1,npf
c
	if(indpf(jj).eq.0)then
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,jj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
	y(ii)=y(ii)-pdd(1)*pf(jj)*dpomax1
c
	end if
99	continue
c
	i_c=1
	if (i_c.eq.1)then
	DO 66 K=1,ncam
c
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*vesarr(kk,K)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	y(ii)=y(ii)-pdd(1)*tcam(K)*dpomax1
66	continue
c
	end if
c
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=pspl(kk)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
c
	y(ii)=y(ii)-pdd(1)*dpomax1
	yw(ii)=y(ii)
	if( psmax.lt.abs(y(ii)) )psmax=abs( y(ii) )
c
	do 100 jj=1,ma1
	kjj=jpf(jj)
c	if(kpr.eq.1)print *,'ii jj kjj',ii,jj,kjj
c-----------------------
	do i=1,nr
	do j=1,nz
	kk=(i-1)*nz+j
	kk1=(j-1)*nr+i
	work(kk1)=api*fluxarr(kk,kjj)
	end do
	end do
c
	call boxda(work,urr,vrr,pdd,ier)
	fint=pdd(1)
c----------------------------
c   here we determine A matrix
	amat(ii,jj)=fint*dpomax1
100	continue
c
c   here boundary flux value----
	amat(ii,ma)=-1.
c------------------------
	end do
c  here sigmas to npoints.....
	do i=1,nps
	sig(i)=seps1*psmax
c	sig(i)=1.
	end do
c---------------------------------------------
c
c
	k=0
	pfmax=0.
	do i=nps+1,nps+ma1
	k=k+1
	kjj=jpf(k)
	y(i)=pfc(kjj)
	if(pfmax.lt.abs(pf(kjj)))pfmax=abs(pf(kjj))
	amat(nps+k,k)=1.
	end do
c************************************************
c	pfmax=5000.
c-----------------------------------
c   here sigmas to ma1 PF-current points (nps+ma1)
	do i=nps+1,nps+ma1
	sig(i)=seps2*pfmax
c	sig(i)=1.
	end do
c-------------------------------------------
c
	namat=nx
	call svdfit(amat,y,sig,ndata,a,ma,namat)
	apr='pf'
c	if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf)
	do k=1,ma1
	kjj=jpf(k)
	if(kpr.eq.1)print *,'k jpf pf0 a',k,jpf(k),pf0(kjj),a(k)
	pf(kjj)=a(k)
	end do
	pboundc=a(ma)
	if(kpr.eq.1)print *,'pboundc=',pboundc
c
	do ii=1,nps
	flux=0.
	do jj=1,ma1
	flux=flux+amat(ii,jj)*a(jj)
	end do
	flux=flux-yw(ii)
	if(kpr.eq.1)print *,'ii flux a ',ii,flux,a(ma)
	end do
c
c
	return
	end




c
