	subroutine pfcur()
c--------------------------------------------
c  calculate pf currents
c--------------------------------------------
	include 'double.inc'
	include 'parf1'
	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf6/pves(kf),pves0(kf)
     *  /pf7/plasma(kf),plasma0(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)
	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves5/pfc(mu,kf)
c
	common
     *  /dop1/volt_sum,volt_tot(kf),volt_pl(kf),volt_ves(kf)
c
	common
     *  /ge2/ntay,tay,tt
     *  /ge5/kpr
	common
     *  /cont1/vchopper(kf),veps
c
	dimension fu(kf),f(kf),pfhelp(kf)
	character *70 apr
	beta=1.
	alf=1.

c	beta=0.
c	alf=0.
c***********************
c   vessel flux   ****************
	do i=1,npf
	pves(i)=0.
	end do
	do j=1,npf
	do i=1,ncam
	pves(j)=pves(j)+pfc(i,j)*tcam(i)
	end do
	end do
c
	apr='pves'
c	if(kpr.eq.1)print 71,apr,(pves(j),j=1,npf)
	apr='pves0'
c	if(kpr.eq.1)print 71,apr,(pves0(j),j=1,npf)

c******
	if(ntay.lt.2)return
c

	do i=1,npf
	fu(i)=0.
	volt_pl(i)=-beta*(plasma(i)-plasma0(i))/(tay*100.)
	volt_ves(i)=-alf*(pves(i)-pves0(i))/(tay*100.)
c
	do j=1,npf
	fu(i)=fu(i)+pfind(i,j)*pf0(j)
	end do
c
	fu(i)=fu(i)-beta*(plasma(i)-plasma0(i))-alf*(pves(i)-pves0(i))
	end do
c***************************************************************
c    chopper voltage
c
	do i=1,npf
	fu(i)=fu(i)+vchopper(i)*100.*tay
	end do
c*****************************************************************
c
	apr='pf=1'
c	if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf)
	apr='pf=0'
c	if(kpr.eq.1)print 71,apr,(pf0(i),i=1,npf)
	do i=1,npf
	pfhelp(i)=0.
	do k=1,npf
	pfhelp(i)=pfhelp(i)+a1(i,k)*fu(k)
	pf(i)=pfhelp(i)
	end do
	end do

71	format(5x,a70/,(1X,6(1pe11.3)))

	apr='pf*'
c	if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf)
	apr='pf0'
c	if(kpr.eq.1)print 71,apr,(pf0(i),i=1,npf)
	volt_sum=0.
	do k=1,npf
	volt_tot(k)=volt_ves(k)+volt_pl(k)
	volt_sum=volt_sum+volt_tot(k)
	end do

c	if(kpr.eq.1)then
	apr='volt_pl'
c	print 71,apr,(volt_pl(i),i=1,npf)
	apr='volt_ves'
c	print 71,apr,(volt_ves(i),i=1,npf)
	apr='volt_ch'
c	print 71,apr,(vchopper(i),i=1,npf)
c	print *,' VOLT_SUM=',volt_sum
	apr='volt_tot'
c	print 71,apr,(volt_tot(i),i=1,npf)
c       end if


	return
	end
	subroutine inv()
c---------------------------------------
	include 'double.inc'
c	implicit real*8 (a-h,o-z)
	include 'parf1'
	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)

	common
     *  /ge2/ntay,tay,tt
     *  /ge5/kpr
c
	dimension a(kf,kf),d(kf,kf),ed(kf,kf),ppm(kf)
	character*70  apr
c
	do i=1,npf
	do j=1,npf
	a(i,j)=pfind(i,j)
	end do
	a(i,i)=a(i,i)+tay*pfres(i)*1.e5
	end do
c
	call obrm(a,a1,d,kf,npf)
	if(kpr.eq.1) print*,'o ++ kay pf'
c
	do i=1,npf
	do j=1,npf
	ed(i,j)=0.
	do k=1,npf
	ed(i,j)=ed(i,j)+a(i,k)*a1(k,j)
	end do
	end do
	end do
	apr='e{i} (pf) [inv]'
	do i=1,npf
	ppm(i)=ed(i,i)
	end do
c	if(kpr.eq.1)print 71,apr,(ppm(i),i=1,npf)
	apr='e{j} (pf) [inv]'
	do j=1,npf
c	if(kpr.eq.1)print *,'j=',j
c	if(kpr.eq.1)print 71,apr,(ed(j,i),i=1,npf)
	end do
	apr='rpf'
c	if(kpr.eq.1) print 71,apr,(pfres(i),i=1,npf)
	apr='l{i}'
	do i=1,npf
	ppm(i)=pfind(i,i)*1.e-8
	end do
c	if(kpr.eq.1) print 71,apr,(ppm(i),i=1,npf)
	apr='l{j}'
	j=1
c	if(kpr.eq.1) print 71,apr,(pfind(j,i),i=1,npf)
71	format(20x,a70/,(6(1x,1pe10.3)))
	return
	end

	subroutine pfcur_d3d()
c--------------------------------------------
c  calculate pf currents
c--------------------------------------------
	include 'double.inc'
c	implicit real *8(a-h,o-z)

	include 'parf1'
	common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf6/pves(kf),pves0(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)
	common
     *  /ves1/psp(mu),psp0(mu),tcam(mu),tcam0(mu)
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves5/pfc(mu,kf)
	common
     *  /pf7/plasma(kf),plasma0(kf)
c
	common
     *  /ge2/ntay,tay,tt
     *  /ge5/kpr
	common
     *  /cont1/vchopper(kf),veps
c
	dimension fu(kf),f(kf),d0(kf),d1(kf),d2(kf)
	dimension fupl(kf),fuves(kf),fuch(kf),fupf(kf)
	character *70 apr
	beta=1.
	alf=1.
	if(ntay.lt.4)alf=0.
	beta=0.
	alf=0.
c
c
c***********************
c   vessel flux   ****************
	do i=1,npf
	pves(i)=0.
	end do
	do j=1,npf
	do i=1,ncam
	pves(j)=pves(j)+pfc(i,j)*tcam(i)
	end do
	end do
c
c******
	apr='plasma'
c	if(kpr.eq.1) print 71,apr,(plasma(i),i=1,npf)
	apr='plasm0'
c	if(kpr.eq.1) print 71,apr,(plasma0(i),i=1,npf)
	apr='pves'
c	if(kpr.eq.1) print 71,apr,(pves(i),i=1,npf)
	apr='pve0'
c	if(kpr.eq.1) print 71,apr,(pves0(i),i=1,npf)
c____________________________________________
	if(ntay.lt.2)return
c_____________________________________________
	do i=1,npf
	fu(i)=0.
c
	do j=1,npf
	fu(i)=fu(i)+pfind(i,j)*pf0(j)
	end do
c
	fupl(i)=-(plasma(i)-plasma0(i))/(100.*tay)
	fuves(i)=-(pves(i)-pves0(i))/(100.*tay)
	fuch(i)=vchopper(i)*100.*tay/(100.*tay)
	fu(i)=fu(i)-beta*(plasma(i)-plasma0(i))-alf*(pves(i)-pves0(i))
	end do
c***************************************************************
	apr='V in coils by pl,V (pfcurrent)'
	if(kpr.eq.1) print 71,apr,(fupl(i),i=1,npf)
	apr='V in coils by cam,V (pfcurrent)'
	if(kpr.eq.1) print 71,apr,(fuves(i),i=1,npf)
	apr='V in coils by choppers,V (pfcurrent)'
	if(kpr.eq.1) print 71,apr,(fuch(i),i=1,npf)
c    chopper voltage
	do i=1,npf
	fu(i)=fu(i)+vchopper(i)*100.*tay
	end do
	apr='fu c'
C	if(kpr.eq.1) print 71,apr,(fu(i),i=1,npf)
c*****************************************************************
	apr='e1'
C	if(kpr.eq.1) print 71,apr,(e1(i),i=1,npf)
	apr='e2'
C	if(kpr.eq.1) print 71,apr,(e2(i),i=1,npf)
	do i=1,npf
	d0(i)=0.
	d1(i)=0.
	d2(i)=0.
	do k=1,npf
	d0(i)=d0(i)+a1(i,k)*fu(k)
	d1(i)=d1(i)+a1(i,k)*e1(k)
	d2(i)=d2(i)+a1(i,k)*e2(k)
	end do
	end do
	apr='d0'
	if(kpr.eq.1)print 71,apr,(d0(i),i=1,npf)
	apr='d1'
	if(kpr.eq.1)print 71,apr,(d1(i),i=1,npf)
	apr='d2'
	if(kpr.eq.1)print 71,apr,(d2(i),i=1,npf)
c
	sum0=0.
	sum1=0.
	sum2=0.
	do i=1,5
	k=i+9
	sum0=sum0+d0(i)+d0(k)
	sum1=sum1+d1(i)+d1(k)
	sum2=sum2+d2(i)+d2(k)
	end do
c
	do i=8,9
	k=i+9
	sum0=sum0+d0(i)+d0(k)
	sum1=sum1+d1(i)+d1(k)
	sum2=sum2+d2(i)+d2(k)
	end do
c_____________________________________________________
	veps1=veps*100.*tay
	v0=-(sum0+veps1*sum2)/sum1
c	if(ntay.le.100)v0=0.1*v0
	v0prin=v0/(100.*tay)
	if(kpr.eq.1) print *,'v0 veps[V]',v0prin,veps
c
	do i=1,npf
	pf(i)=d0(i)+v0*d1(i)+veps1*d2(i)
	end do
	sum0=0.
	do i=1,5
	k=i+9
	sum0=sum0+pf(i)+pf(k)
	end do
c
	do i=8,9
	k=i+9
	sum0=sum0+pf(i)+pf(k)
	end do
c	if(kpr.eq.1)print *,'total pf coil currents=',sum0,' kA'
	apr='pf0 1-18,kA'
	if(kpr.eq.1) print 71,apr,(pf0(i),i=1,18)
	apr='pf 1-18,kA'
	if(kpr.eq.1) print 71,apr,(pf(i),i=1,18)
	fu(1)=pf0(19)
	fu(2)=pf0(20)
c
	fu(3)=pf(19)
	fu(4)=pf(20)
	apr='pf e-coils,kA'
	if(kpr.eq.1) print 71,apr,(fu(i),i=1,4)
	do i=1,npf
	fupf(i)=0.
c
	do j=1,npf
	fupf(i)=fupf(i)-pfind(i,j)*(pf(j)-pf0(j))/(100.*tay)
	end do
	end do
	apr='Upf mutual,V'
	if(kpr.eq.1) print 71,apr,(fupf(i),i=1,npf)
c
	do i=1,npf
	fu(i)=fupf(i)+fupl(i)+fuves(i)+fuch(i)+
     *  v0prin*e1(i)+veps*e2(i)
	end do
c
	apr='Upf sum,V'
	if(kpr.eq.1) print 71,apr,(fu(i),i=1,npf)
	do i=1,npf
	fu(i)=beta*fupl(i)+alf*fuves(i)+fuch(i)+
     *  v0prin*e1(i)+veps*e2(i)
	end do
	apr='Upf ext,V'
	if(kpr.eq.1) print 71,apr,(fu(i),i=1,npf)
c
	do i=1,npf
      	fu(i)= pfres(i)*pf(i)*1.e+3
	end do
	apr='Rpf * Ipf,V'
	if(kpr.eq.1) print 71,apr,(fu(i),i=1,npf)
c
c===============================
71	format(5x,a70/,(1X,6(1pe11.3)))
	return
	end
