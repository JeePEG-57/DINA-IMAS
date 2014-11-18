c---------------------------------------------------------
	subroutine spoint(ksep,xw,yw,fint,rmag,zmag,pmag,
     *  rsep,zsep,psep,rsep1,zsep1,psep1)
c----------------------------------------------------------
c--
	include 'double.inc'
	include 'parf0'
	include 'parf2'
c
c       Here     nr= dimension of r grid
c                nz= dimension of z grid
c
        common
     *  /ge5/kpr
	common /eq1/psip(nwnh),pspl(nwnh),x(nr),y(nz),dx,dy
c
	common /eq8/jbound,xbound(ntet),ybound(ntet),alfa0
c
	dimension pds(6)
c
	xs=xw
	ys=yw
	if(ksep.eq.-1)go to 56
56	continue
c
	dxy=sqrt(dx**2+dy**2)
c
c
	if(ksep.eq.-1)then
	pmag=-1.e12
	rwant=rmag
	zwant=zmag
	end if
	if(ksep.ne.-1)then
	psep=-1.e12
	rwant=xs
	zwant=ys
	end if
c--------------------->>>>
        xerr0=0.
        yerr0=0.

	do 1300 jj=1,100
	if(rwant.le.x(2).or.rwant.ge.x(nr-1))go to 1306
	if(zwant.le.y(2).or.zwant.ge.y(nz-1))go to 1306
c--------     pds(1)=fun
c--------     pds(2)=(dfdr)
c--------     pds(3)=(dfdz)
c--------     pds(4)=(dfdr)dz
c--------     pds(5)=(dfdr)dr
c--------     pds(6)=(dfdz)dz
c______________________________________________
c
	call boxd(rwant,zwant,pds,ier)
c
c	if(kpr.eq.1)print *,'jj r z',jj,rwant,zwant
c
	det=pds(5)*pds(6)-pds(4)*pds(4)
	if(abs(det).lt.1.e-15)go to 1305
c

	xerr=(-pds(2)*pds(6)+pds(4)*pds(3))/det
	yerr=(-pds(5)*pds(3)+pds(2)*pds(4))/det
	derr=sqrt(xerr*xerr+yerr*yerr)
c
	if(abs(derr).gt.dxy)then
	al1=dxy/derr
	xerr=xerr*al1
	yerr=yerr*al1
	end if
c
	rwant=rwant+0.5*(xerr+xerr0)
	zwant=zwant+0.5*(yerr+yerr0)

c	rwant=rwant+xerr
c	zwant=zwant+yerr

        xerr0=xerr
        yerr0=yerr
c--
        if(jj.gt.100)then
c--
	if(kpr.eq.1)print *,' psi_r psi_z ',jj,pds(2),pds(3)
	if(kpr.eq.1)print *,' jj zwant yerr yerr0',jj,zwant,yerr,yerr0
c--
	if(kpr.eq.1)print *,' jj rwant xerr xerr0',jj,rwant,xerr,xerr0
	if(kpr.eq.1)print *,' jj zwant yerr yerr0',jj,zwant,yerr,yerr0
c--
        end if
c--
	if(derr.lt.1.e-7*dxy)go to 1310
1300	continue
	go to 1310
1306	if(kpr.eq.1)print *,'--point out of grid--'
	pds(1)=-1.e12
	go to 1310
1305	continue
	if(kpr.eq.1)print *,'** determinant is zero =**',det
	if(kpr.eq.1)print *,'rwant=',rwant,' zwant=',zwant
	if(kpr.eq.1)print *,'stop calculation'
	stop
1310	continue
	bpolmin=pds(2)**2+pds(3)**2
c---
	if(ksep.eq.-1)then
	rmag=rwant
	zmag=zwant
	pmag=pds(1)
	end if
	if(ksep.ne.-1)then
	rsep=rwant
	zsep=zwant
	psep=pds(1)
c
	rsep1=rwant
	zsep1=zwant
	psep1=pds(1)

	dels=sqrt( (rsep-rmag)**2+(zsep-zmag)**2)
	if(dels.le.1.25*dxy)then
	psep=-1.e12
	if(kpr.eq.1)print *,' first separatrix near magnetic axis'
	end if
	end if
c      this is it. Good luck with it
        return
        end
