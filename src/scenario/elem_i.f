	function svcx(t,p)
c charge exchange for hydrogen atom on hydrogen ion
c in OUR UNITS
c temperatures if ion and neutral are equal to t!
c	real*8 svcx

	implicit real*8(a-h,o-z)
c
	i_ue=1

	if(i_ue.eq.0)then

	tot=2.*t
	vv=1.56*sqrt(tot/p)
	xx=dlog10(1.27*tot)
	svcx=(7.6-1.06*xx)**2*vv
	svcx=svcx*1.e-3
c	print *,' t vv xx svcx',t,vv,xx,svcx

	else
	t0=t/p
         a = 0.3*t0 
         rcx = 1.7e-1 * a**0.333
	svcx=rcx
	end if

c	print *,'t t0 svcx',t,t0,svcx
c
	return
	end
c
	function svie(t,dene)
c sigma*v for hydrogen atom ionization by electron
c in OUR UNITS
c t - electron temperature
c	real*8 svie

	implicit real*8(a-h,o-z)
c
	i_ue=1

	if(i_ue.eq.0)then

	xx=dlog10(t)
	if(t.lt.20.)then
	svie=10.**(-3.054*xx-15.72*exp(-xx)+
     *	1.603*dexp(-xx*xx)+10.)
	svie=svie*1.e-3
	goto99
	end if
	svie=10.**(-0.5151*xx-2.563/xx-5.231+10.)
	svie=svie*1.e-3

99	continue
c	print *,' t svie',t,svie
c
	else
	dene_in=dene*1.e13
c	print *,' dene_in ',dene_in
	a=rsa_y (t, dene_in)
	svie=a*1.e7
c	print *,' t dene svie',t,dene,svie
	end if

	return
	end
c
	function svr(t,dene)
c sigma*V for recombination in our units
c t - electron temperature
c	real*8 svr

	implicit real*8(a-h,o-z)
c
	i_ue=1

	if(i_ue.eq.0)then

	tot=13.6/t
	svr=1.27*sqrt(tot**3)/(tot+0.59)
	svr=svr*1.e-6
c
c	print *,' t svr',t,svr
c
	else
	dene_in=dene*1.e13
c	print *,' dene_in ',dene_in
	a=rra_y (t, dene_in)
	svr=a*1.e7
c	print *,' t dene svr',t,dene,svr
	end if

	return
	end

c++++++++++++++++++++++++++++++++++++++++++

      function rin(tmpe,jz)
	implicit real*8(a-h,o-z)

        iza=jz

c maximum impurity charge
	izamax=6
c impurity nuclear charge
	izn=6

        tmpn=1.

	call mcrates_y(tmpe,tmpn,iza,izamax,izn,rion,rrec,rcxr)
c rates rion,rrec,rcxr are in m**3/s. To obtain our units it is
c necessary to multiply by 1.e13

	rin=rion*1.e13

c	write(6,'(" iza tmpe,tmpn rin",
c     *  i4,6(1pe12.5))'),
c     *  iza,tmpe,tmpn,rin


c	rrec=rrec*1.e13
c	rcxr=rcxr*1.e13

        return
        end

        function rre(tmpe,jz)
	implicit real*8(a-h,o-z)

        tmpn=1.


        iza=jz

c maximum impurity charge
	izamax=6
c impurity nuclear charge
	izn=6

	call mcrates_y(tmpe,tmpn,iza,izamax,izn,rion,rrec,rcxr)
c rates rion,rrec,rcxr are in m**3/s. To obtain our units it is
c necessary to multiply by 1.e13
c	rion=rion*1.e13
	rre=rrec*1.e13
c	rcxr=rcxr*1.e13

        return
        end

      	function rcx(tmpn,jz)
	implicit real*8(a-h,o-z)
        tmpe=1.

        iza=jz

c maximum impurity charge
	izamax=6
c impurity nuclear charge
	izn=6

	call mcrates_y(tmpe,tmpn,iza,izamax,izn,rion,rrec,rcxr)
c rates rion,rrec,rcxr are in m**3/s. To obtain our units it is
c necessary to multiply by 1.e13
c	rion=rion*1.e13
c	rrec=rrec*1.e13

	rcx=rcxr*1.e13

        return
        end


      subroutine mcrates_y(tmpe,tmpi,za,zamax,zn,rion,rrec,rcxr)
	implicit real*8(a-h,o-z)
	include 'comm_i.inc'
c      real tmpe,tmpi
      integer za,zamax,zn
c      real rion, rrec, rcxr
c
c ... Inputs are:
c        electron temperature, tmpe;
c        neutral hydrogen temperature, tmpi;
c        atomic charge state, za;
c        maximum atomic charge state, zamax;
c        nuclear charge state, zn;

c ... Outputs are:
c        rate parameters (sigma*v) for ionization, recombination,
c        and charge-exchange recombination on neutral hydrogen
c
c     The tables used in this subroutine are generated with a code
c     supplied by Bas Braams.  The data file it produces is called
c     'b2frates' by default.  This gives rates that may depend on both
c     density and temperature.  Here, we use only the rates given
c     for the lowest density in the table.
c
c     Input electron temperature is in [eV].
c     Input temperature for neutral hydrogen is given in [ev].
c     Table temperatures are given in [eV].
c     Output and table rates are all given in [m**3/s].
c
c
      integer i1e,i1i,i,ii
c      real tmpenonz,tmpinonz,xte,xti,dlogt,fxte,fxti
c
c      real rcxr_zn6_y, rcxr_zn6b_y
      external rcxr_zn6_y, rcxr_zn6b_y
c
      rion = 0.
      rrec = 0.
      rcxr = 0.
c
c	print*,tmpe,tmpi,za,zamax,zn
	cutlo=1.e-10
      tmpenonz = max(tmpe, cutlo)
      tmpinonz = max(tmpi, cutlo)
      xte = log(tmpenonz)
      xti = log(tmpinonz)
      dlogt = rtlt(2) - rtlt(1)
c	print*,xte,xti,dlogt
c
c ... Find index i1 in temperature table such that
c                 rtlt(i1) .le. xt .lt. rtlt(i1+1)
c     or, equivalently,
c                  rtt(i1) .le. tmp .lt. rtt(i1+1).
c
      i1e = int( (xte-rtlt(1))/dlogt )+1
      i1i = int( (xti-rtlt(1))/dlogt )+1
c
c ... For temperatures below minimum table temperature, extrapolate
c     downwards from table entries 0 and 1.
c
      i1e = max(1, i1e)
      i1i = max(1, i1i)
c
c ... For temperatures above maximum table temperature, extrapolate
c     upwards from table entries rtnt-1 and rtnt.
c
      i1e = min(irtnt, i1e)
      i1i = min(irtnt, i1i)
c	print*,i1e,i1i
c
c ... Compute coefficient for linear interpolation.
c
      fxte = (xte-rtlt(i1e))/(rtlt(i1e+1)-rtlt(i1e))
      fxti = (xti-rtlt(i1i))/(rtlt(i1i+1)-rtlt(i1i))
c
c
	ii=-1
	do i=1,irtns
	if(zn.eq.int(rtzn(i)).and.za.eq.int(rtza(i))) then
	ii=i
	endif
	enddo
c	print*,ii

c     Compute rate parameters for transitions from table species ii.
c
      if (za .lt. zamax) then
         rion = exp((1-fxte)*rtlsa(i1e,1,ii)+fxte*rtlsa(i1e+1,1,ii))
         if (za .eq. 0) return
      endif
         rrec = exp((1-fxte)*rtlra(i1e,1,ii)+fxte*rtlra(i1e+1,1,ii))
         rcxr = exp((1-fxti)*rtlcx(i1i,1,ii)+fxti*rtlcx(i1i+1,1,ii))
c
c     Use special analytic fit for carbon c-x on neutral hydrogen.
c
c      if ( (iscxfit .gt. 0) .and.
c     .     (zn .eq. 6) .and. (za .le. zamax) ) then
c         if (iscxfit.ge.1. .and. iscxfit.le.2.) then
c            rcxr = (2.-iscxfit)*rcxr_zn6 (tmpi, za) +
c     .             (iscxfit-1.)*rcxr_zn6b(tmpi, za)
c         endif
        rcxr = rcxr_zn6_y (tmpi, za)
ccc         if (iscxfit .eq. 1) rcxr = rcxr_zn6 (tmpi, za)
ccc         if (iscxfit .eq. 2) rcxr = rcxr_zn6b (tmpi, za)
c      endif
c
      return
      end

c-----End of subroutine mcrates----------------------------------------

      function rcxr_zn6_y (tmp, za)
	implicit real*8(a-h,o-z)
c      real tmp
      integer za
c
c     Charge exchange rate parameter for carbon on neutral hydrogen.
c     Input (neutral hydrogen) temperature, tmp, is in [eV].
c     Initial carbon charge state is za.
c     Output rate parameter (sigma-v) is in [m**3/sec].
c
c     This power-law fit was derived by Tom Rognlien from Figure 8.1
c     of a PhD thesis by C.F. Maggi on "Measurement and Interpretation
c     of Spectral Emission from JET Divertor Plasmas", January 1997,
c     JET report JET-IR(96)05.
c
c     local variables --
      real*8 x, m0(6), m1(6), m2(6)
      data m0/-16.104,-18.27,-14.48,-14.85,-14.213,-17.576/
      data m1/0.5335,2.3657,0.05715,0.5219,0.42193,1.8758/
      data m2/-0.0009571,-0.29616,0.080947,0.048885,-0.033125,-0.095951/

	cutlo=1.e-10
	ev2=1.
      x = log10(max(tmp, cutlo)/ev2)
      rcxr_zn6_y = 10**( m0(za) + m1(za)*x + m2(za)*x*x )
c
      return
      end
c
c-------End of function rcxr_zn6---------------------------------------

      function rcxr_zn6b_y (tmp, za)
	implicit real*8(a-h,o-z)
c	real tmp
      integer za
c
c     Charge exchange rate parameter for carbon on neutral hydrogen.
c     Input (neutral hydrogen) temperature, tmp, is in [eV].
c     Initial carbon charge state is za.
c     Output rate parameter (sigma-v) is in [m**3/sec].
c
c     This is a modified of the function rcxr_zn6; only za=1 case is
c     changed to use a (lower) fit guided by plots from A. Pigarov.
c     Other za's same as for rxcr_zn6 from thesis by C.F. Maggi (fit
c     by T. Rognlien)
c
c     local variables --
      real*8 x, m0(6), m1(6), m2(6)
      data m0/-20.027,-18.27,-14.48,-14.85,-14.213,-17.576/
      data m1/3.6433,2.3657,0.05715,0.5219,0.42193,1.8758/
      data m2/-0.59189,-0.29616,0.080947,0.048885,-0.033125,-0.095951/

	cutlo=1.e-10
	ev2=1.
      x = log10(max(tmp, cutlo)/ev2)
      rcxr_zn6b_y = 10**( m0(za) + m1(za)*x + m2(za)*x*x )
c
      return
      end
c
c-------End of function rcxr_zn6b---------------------------------------

      subroutine readmc_y
	implicit real*8(a-h,o-z)
	include 'comm_i.inc'

      open (unit=10, file='c_rate.dat', form='formatted')
      read(10,*)
      read(10,*)
      read(10,*)
      read (10,*) irtnt,irtnn,irtns
      kstart=1
      nget=10
c      print*, irtnt,irtnn,irtns
c	stop
      call readmc1_y (nget,kstart)

      close (10)

      return
      end

c-----------------------------------------------------------------------

      subroutine readmc1_y (nget,kstart)
	implicit real*8(a-h,o-z)
	include 'comm_i.inc'
	read(nget,*)
      read (nget,*) (rtza(k),k=kstart,irtns)
      read(nget,*)
      read (nget,*) (rtzn(k),k=kstart,irtns)
      read(nget,*)
      read (nget,*) (rtza2(k),k=kstart,irtns)
      read(nget,*)
      read (nget,*) (rtt(i),i=1,irtnt+1)
      read(nget,*)
      read (nget,*) (rtn(j),j=1,irtnn+1)
      read(nget,*)
      read (nget,*) (rtlt(i),i=1,irtnt+1)
      read(nget,*)
      read (nget,*) (rtln(j),j=1,irtnn+1)
      read(nget,*)
      read (nget,*) (((rtlsa(i,j,k),i=1,irtnt+1),j=1,irtnn+1),
     .                              k=kstart,irtns)
      read(nget,*)
      read (nget,*) (((rtlra(i,j,k),i=1,irtnt+1),j=1,irtnn+1),
     .                              k=kstart,irtns)
      read(nget,*)
      read (nget,*) (((rtlqa(i,j,k),i=1,irtnt+1),j=1,irtnn+1),
     .                              k=kstart,irtns)
      read(nget,*)
      read (nget,*) (((rtlcx(i,j,k),i=1,irtnt+1),j=1,irtnn+1),
     .                              k=kstart,irtns)

c
      return
      end
c
      subroutine radmc_y( jzmax,jznuc,te,dene,denz,radz,tot_los)
	implicit real*8(a-h,o-z)
	include 'comm_i.inc'		
	
c ... input args
c     jzmax - number of charge states
c	jnuc - nuclear charge
      dimension denz(jzmax),radz(jzmax)

c
c ... Compute the radiation rates, radz(0:zmax), for all charge states
c     of an impurity with nuclear charge, znuc, and return the total 
c     electron energy loss rate, radmc, including both the radiation
c     and binding energy contributions.
c
c     The tables used in this subroutine are generated with a code
c     supplied by Bas Braams.  The data file it produces is called
c     'b2frates' by default.  This gives rates that depend on both
c     density and temperature.  Here, we use only the rates given
c     for the lowest density in the table.
c
c ... Input temperature te is in [eV].
c     Output rates are in [eV/m**3/s].
c     Table temperatures are in [eV].
c     Table rate parameters are in [m**3/s] and [eV*m**3/s].
c

c
c      real ebindz
c      external ebindz
c

c
	cutlo=1.e-10
      te = max(te, cutlo)      
	ev2=1.
      xt = log(te/ev2)
      dlogt = rtlt(2) - rtlt(1)
c
c ... Find index i1 in table such that rtlt(i1) .le. xt .lt. rtlt(i1+1)
c     or, equivalently, rtt(i1) .le. te .lt. rtt(i1+1).
c
      i1 = int( (xt-rtlt(1))/dlogt )+1

c

c ... For temperatures below minimum table temperature, extrapolate
c     downwards from table entries 0 and 1.

      i1 = max(1, i1)
c
c ... For temperatures above maximum table temperature, extrapolate
c     upwards from table entries rtnt-1 and rtnt.

      i1 = min(irtnt, i1)
c
c ... Compute coefficient for linear interpolation.

      fxt = (xt-rtlt(i1))/(rtlt(i1+1)-rtlt(i1))

c	print*,'fxt'
c	print*,fxt

c     Compute rates for each charge state and total rate:

c     First, find the species index of the neutral impurity atom
c      k0 = -1
c      do k=0,rtnsd-1
c        if ((nint(rtzn(k)) .eq. znuc) .and. (nint(rtza(k)) .eq. 0)) then
c           k0 = k
c           break
c        endif
c      enddo

      tot_los = 0.	! total electron energy loss rate
      do k=1,irtns
         rionz = exp((1-fxt)*rtlsa(i1,1,k)+fxt*rtlsa(i1+1,1,k))
         rrecz = exp((1-fxt)*rtlra(i1,1,k)+fxt*rtlra(i1+1,1,k))
         reelz = exp((1-fxt)*rtlqa(i1,1,k)+fxt*rtlqa(i1+1,1,k))
         radz(k) = dene*denz(k)*reelz*ev2
         tot_los  = tot_los  + radz(k)
c     binding energy contributions:
         if (k .lt. irtns) then		! ionization
          radz(k) = radz(k) - dene*denz(k)*rionz*ebindz(k+1,jznuc)*ev2
         endif
         if (k .gt. 1) then		! recombination
          radz(k) = radz(k) + dene*denz(k)*rrecz*ebindz(k,jznuc)*ev2
         endif
      enddo

	tot_los  = tot_los*1.e13
      do k=1,irtns
	radz(k) = radz(k)*1.e13
	end do 

      return
      end

c----------------------------------------------------------------------c

      function ebindz(jzatomic, jznuclear)
	implicit real*8(a-h,o-z)


c     This function returns the ionization energy (eV) for an atom
c     with atomic charge, jzatomic, and nuclear charge, jznuclear.

c 
      if (jznuclear .eq. 2) then	! helium
         if (jzatomic .eq. 0) then
            ebindz=24.58741
         elseif (jzatomic .eq. 1) then
            ebindz=54.41778
         endif
      elseif (jznuclear .eq. 3) then	! lithium
         if (jzatomic .eq. 0) then
            ebindz=5.39172
         elseif (jzatomic .eq. 1) then
            ebindz=75.64018
         elseif (jzatomic .eq. 2) then
            ebindz=122.45429
         endif
      elseif (jznuclear .eq. 4) then	! beryllium
         if (jzatomic .eq. 0) then
            ebindz=9.32263
         elseif (jzatomic .eq. 1) then
            ebindz=18.21116
         elseif (jzatomic .eq. 2) then
            ebindz=153.89661
         elseif (jzatomic .eq. 3) then
            ebindz=217.71865
         endif
      elseif (jznuclear .eq. 5) then	! boron
         if (jzatomic .eq. 0) then
            ebindz=8.29803
         elseif (jzatomic .eq. 1) then
            ebindz=25.15484
         elseif (jzatomic .eq. 2) then
            ebindz=37.93064
         elseif (jzatomic .eq. 3) then
            ebindz=259.37521
         elseif (jzatomic .eq. 4) then
            ebindz=340.22580
         endif
      elseif (jznuclear .eq. 6) then	! carbon
         if (jzatomic .eq. 0) then
            ebindz=11.26030
         elseif (jzatomic .eq. 1) then
            ebindz=24.38332
         elseif (jzatomic .eq. 2) then
            ebindz=47.8878
         elseif (jzatomic .eq. 3) then
            ebindz=64.4939
         elseif (jzatomic .eq. 4) then
            ebindz=392.087
         elseif (jzatomic .eq. 5) then
            ebindz=489.99334
         endif
      elseif (jznuclear .eq. 7) then	! nitrogen
         if (jzatomic .eq. 0) then
            ebindz=14.53414
         elseif (jzatomic .eq. 1) then
            ebindz=29.6013
         elseif (jzatomic .eq. 2) then
            ebindz=47.44924
         elseif (jzatomic .eq. 3) then
            ebindz=77.4735
         elseif (jzatomic .eq. 4) then
            ebindz=97.8902
         elseif (jzatomic .eq. 5) then
            ebindz=552.0718
         elseif (jzatomic .eq. 6) then
            ebindz=667.046
         endif
      elseif (jznuclear .eq. 8) then	! oxygen
         if (jzatomic .eq. 0) then
            ebindz=13.61806
         elseif (jzatomic .eq. 1) then
            ebindz=35.11730
         elseif (jzatomic .eq. 2) then
            ebindz=54.9355
         elseif (jzatomic .eq. 3) then
            ebindz=77.41353
         elseif (jzatomic .eq. 4) then
            ebindz=113.8990
         elseif (jzatomic .eq. 5) then
            ebindz=138.1197
         elseif (jzatomic .eq. 6) then
            ebindz=739.29
         elseif (jzatomic .eq. 7) then
            ebindz=871.4101
         endif
      elseif (jznuclear .eq. 9) then	! fluorine
         if (jzatomic .eq. 0) then
            ebindz=17.42282
         elseif (jzatomic .eq. 1) then
            ebindz=34.97082
         elseif (jzatomic .eq. 2) then
            ebindz=62.7084
         elseif (jzatomic .eq. 3) then
            ebindz=87.1398
         elseif (jzatomic .eq. 4) then
            ebindz=114.2428
         elseif (jzatomic .eq. 5) then
            ebindz=157.1651
         elseif (jzatomic .eq. 6) then
            ebindz=185.186
         elseif (jzatomic .eq. 7) then
            ebindz=953.9112
         elseif (jzatomic .eq. 8) then
            ebindz=1103.1176
         endif
      elseif (jznuclear .eq. 10) then	! neon
         if (jzatomic .eq. 0) then
            ebindz=21.56454
         elseif (jzatomic .eq. 1) then
            ebindz=40.96328
         elseif (jzatomic .eq. 2) then
            ebindz=63.45
         elseif (jzatomic .eq. 3) then
            ebindz=97.12
         elseif (jzatomic .eq. 4) then
            ebindz=126.21
         elseif (jzatomic .eq. 5) then
            ebindz=157.93
         elseif (jzatomic .eq. 6) then
            ebindz=207.2759
         elseif (jzatomic .eq. 7) then
            ebindz=239.0989
         elseif (jzatomic .eq. 8) then
            ebindz=1195.8286
         elseif (jzatomic .eq. 9) then
            ebindz=1362.1995
         endif
      elseif (jznuclear .eq. 18) then	! argon
         if (jzatomic .eq. 0) then
            ebindz=15.75962
         elseif (jzatomic .eq. 1) then
            ebindz=27.62967
         elseif (jzatomic .eq. 2) then
            ebindz=40.74
         elseif (jzatomic .eq. 3) then
            ebindz=59.81
         elseif (jzatomic .eq. 4) then
            ebindz=75.02
         elseif (jzatomic .eq. 5) then
            ebindz=91.009
         elseif (jzatomic .eq. 6) then
            ebindz=124.323
         elseif (jzatomic .eq. 7) then
            ebindz=143.460
         elseif (jzatomic .eq. 8) then
            ebindz=422.45
         elseif (jzatomic .eq. 9) then
            ebindz=478.69
         elseif (jzatomic .eq. 10) then
            ebindz=538.96
         elseif (jzatomic .eq. 11) then
            ebindz=618.26
         elseif (jzatomic .eq. 12) then
            ebindz=686.10
         elseif (jzatomic .eq. 13) then
            ebindz=755.74
         elseif (jzatomic .eq. 14) then
            ebindz=854.77
         elseif (jzatomic .eq. 15) then
            ebindz=918.03
         elseif (jzatomic .eq. 16) then
            ebindz=4120.8857
         elseif (jzatomic .eq. 17) then
            ebindz=4426.2296
         endif

      endif

      return
      end
c----------------------------------------------------------------------c
	function rin_o(te,jz)
	implicit real*8(a-h,o-z)
c te electron temperature(eV), jz - ion charge, jz < 6
c approximate ionization rate for carbon from Dnestrovskij (111),p.264
c in OUR units ([n]=10e13, [t]=10e-6, [v]=10e6)
c
	ei(x)=dlog(1.+(0.562+1.4*x)/(x*(1.+1.4*x)))

	if(jz.ge.6)then
           print *,' jz > 5 STOP'
	   stop
	end if

	ry=13.6
c
	if(jz.eq.0)then
	ej=16.6
	qj=2.8
	goto 1
	end if

	if(jz.eq.1)then
	ej=28.2
	qj=2.8
	goto 1
	end if

	if(jz.eq.2)then
	ej=61.3
	qj=2.
	goto 1
	end if

	if(jz.eq.3)then
	ej=102.
	qj=2.2
	goto 1
	end if

	if(jz.eq.4)then
	ej=392.
	qj=2.
	goto 1
	end if

	if(jz.eq.5)then
	ej=490.
	qj=1.
	goto 1
	end if
c
1	continue
c
	betj=ej/te
c	rin=5.9e-1*qj*(dsqrt(ry/ej))**3*dsqrt(betj)*ei(betj)
	rin_o=5.9e-1*qj*(dsqrt(ry/ej))**3*dsqrt(betj)
c
	return
	end
c
	function rre_o(te,jz)
	implicit real*8(a-h,o-z)
c te electron temperature(eV), jz - ion charge
c approximate recombination rate for carbon from Dnestrovskij (112),
c (114), p.264-265
c in OUR units ([n]=10e13, [t]=10e-6, [v]=10e6)
c
	ei(x)=dlog(1.+(0.562+1.4*x)/(x*(1.+1.4*x)))

	if(jz.ge.7)then
           print *,' jz > 6 STOP'
	   stop
	end if

	ry=13.6
c
 	if(jz.eq.1)then
	ej=16.6
	goto 1
	end if

 	if(jz.eq.2)then
	ej=28.2
	goto 1
	end if

	if(jz.eq.3)then
	ej=61.3
	goto 1
	end if

	if(jz.eq.4)then
	ej=102.
	goto 1
	end if

	if(jz.eq.5)then
	ej=392.
	goto 1
	end if

	if(jz.eq.6)then
	ej=490.
	goto 1
	end if
c
1	continue
c
	betj=ej/te
c radiation recombination (AT LOW temperatures FORMULA incorrect)
c	rre=5.2e-7*(jz-1)*sqrt(betj**3)*exp(betj)*ei(betj)
c	rre=5.2e-7*(jz-1)*sqrt(betj**3)*exp(betj)
c
c add dielectron recombination
	a1=0.219
	a2=0.117
	e1j=ry*(jz*a1+a2)
	bet1=e1j/te
c	rre=rre+1.e-2*dsqrt(bet1**3)*dexp(-bet1)
	rre_o=1.e-2*dsqrt(bet1**3)*dexp(-bet1)
c
	return
	end
c
	function rcx_o(tn,jz)
	implicit real*8(a-h,o-z)
c tn neutral temperature(eV), jz - ion charge
c approximate charge exchange rate from Dnestrovskij (115),p.265
c in OUR units ([n]=10e13, [t]=10e-6, [v]=10e6)
c
	rcx_o=1.5*1.e-2*jz*dsqrt(tn)
c
	return
	end

	function rcx_zo(tn,jz)
	implicit real*8(a-h,o-z)
c tn neutral temperature(eV), jz - ion charge
c approximate charge exchange rate from Dnestrovskij (115),p.265
c in OUR units ([n]=10e13, [t]=10e-6, [v]=10e6)
c
      real  AMz,TI,amd
      real ZSVCX

	TI=tn*1.e-3
	
	AMz=2.*jz
	amd=2.

	coef=0.1

	rcx_zo=coef* 1.e-5*ZSVCX( float(jz),TI,AMz,AMd)

	return
	end


	function	SEIV(TE)
C------------------------------------------ <S*Ve> [10#-13 cm3/s]
C	The electron velocity weighted Maxwellian average for
C	neutral beam ionization cross section by electrons
C	TE [keV] -  electron temperature
C------------------------------------------- Polevoy A.R. 21.03.91

        include 'double.inc'

		Y	=13.6E-3/TE
	if(TE.LT..02)	THEN
		SEIV	=0.61E6*EXP(-Y)/(SQRT((1.+Y)/Y)*(Y+0.73))
			ELSE
		Y	=dLOG10(TE)+3.
		SEIV	=10.**(7.769-0.5151*Y-2.563/Y)
			ENDIF
	return
	END
	function	SPII(E)
C---------------------------------------------- Spii [10#-13 cm2]
C	Neutral beam ionization cross section by proton impact
C	Reviere A.C //Nucl.Fusion.v.11(1971).p.363
C	E [kev] = Ebeam*Mp/Mi
C------------------------------------------- Polevoy A.R. 21.03.91

        include 'double.inc'

		Y1	=dLOG10(E)+3.
		Y2	=0.
	IF(E.GT.3..AND.E.LT.150.) Y2=10**((-0.8712*Y1+8.156)*Y1-21.833)
	IF(E.GE.150.)	Y2=36.E-3*(dLOG10(0.1666*E)+3.)/E
			SPII	=Y2
	return
	END

	function	SPEX(E)
        include 'double.inc'

	Y	=E*1.e3

	SPEX	=0.06937*(1.-0.155*dLOG10(Y))**2/(1.+0.1112E-14*Y**3.3)
c        print *,' e y spex',e,y,spex
	return
	END
C----------------------------------------	Artiphitial exponent
	FUNCTION	YEXP(X)
	YEXP	=0.
	IF(X.GT.-30.)	YEXP=EXP(X)
	RETURN
	END


c-------------------------------------------------------------------
	function elos_h_i(te, dene)
	implicit real*8(a-h,o-z)
	dene_in=dene*1.e13
	a=erl1_y (te, dene_in)
	elos_h_i=a*1.e6/1.602d1
	return
	end
c
	function elos_h_r(te, dene)
	implicit real*8(a-h,o-z)
	dene_in=dene*1.e13
	a=erl2_y (te, dene_in)
	elos_h_r=a*1.e6/1.602d1
	return
	end
c
      function erl1_y (te, dene)
	implicit real*8(a-h,o-z)
	include 'comm_i.inc'		


c  Te(jt) = 10**(-1.2 + (jt-1)/10) jt=1,60
c    dene(jn) = 10**(10 + 0.5*(jn-1)) jn=1,15 

c-------------------------------------------------------------------
	istabon=10
c
c     Compute electron radiation loss rate per neutral H atom due to
c "ionization" processes - D. Stotler's "coupling to the ground state"
c     te [eV]          = electron temperature
c     dene [/cm**3]      = electron density
c     erl2 [erg/sec]    = radiation rate

c-------------------------------------------------------------------
c-------------------------------------------------------------------
      if (istabon .eq. 8 .or. istabon .eq. 9) then 
c	# linear interpolation

c     compute abscissae --
         zloge=dlog(te)
         rle=max(rlemin, min(zloge,rlemax))
         zlogd=dlog10(dene)
         rld=max(rldmin, min(zlogd,rldmax))
c     table indicies for interpolation --
         je=int((rle-rlemin)/delekpt) + 1
         je=min(je,mpe-1)
         jd=int((rld-rldmin)/deldkpt) + 1
         jd=min(jd,mpd-1)
c     fractional parts of intervals (je,je+1) and (jd,jd+1) --
         fje=(rle-ekpt(je))/(ekpt(je+1)-ekpt(je))
         fjd=(rld-dkpt(jd))/(dkpt(jd+1)-dkpt(jd))
c     radiation rate --
         erl111=welms1(je,jd)
         erl112=welms1(je,jd+1)
         erl121=welms1(je+1,jd)
         erl122=welms1(je+1,jd+1)
         erl11=erl111+fjd*(erl112-erl111)
         erl12=erl121+fjd*(erl122-erl121)
         erl1_y = erl11 + fje*(erl12-erl11)

c-------------------------------------------------------------------
      elseif (istabon .eq. 10) then 
c # logarithmic interpolation on Stotler-95

c     compute abscissae --
         zloge=dlog(te)
         rle=max(rlemin, min(zloge,rlemax))
c         print*,'zloge, rlemin,rlemax',zloge, rlemin,rlemax
	   zlogd=dlog10(dene)
         rld=max(rldmin, min(zlogd,rldmax))
c     table indicies for interpolation --
         je=int((rle-rlemin)/delekpt) + 1
         je=min(je,mpe-1)
         jd=int((rld-rldmin)/deldkpt) + 1
         jd=min(jd,mpd-1)
c	print*,'jd,je',jd,je
c     fractional parts of intervals (je,je+1) and (jd,jd+1) --
         fje=(rle-ekpt(je))/(ekpt(je+1)-ekpt(je))
         fjd=(rld-dkpt(jd))/(dkpt(jd+1)-dkpt(jd))
c     radiation rate --
         erl111=dlog( welms1(je,jd) )
         erl112=dlog( welms1(je,jd+1) )
         erl121=dlog( welms1(je+1,jd) )
         erl122=dlog( welms1(je+1,jd+1) )
         erl11=erl111+fjd*(erl112-erl111)
         erl12=erl121+fjd*(erl122-erl121)
         erl1_y = dexp( erl11 + fje*(erl12-erl11) )

c-------------------------------------------------------------------
      endif

      return
      end

c--------------------------------------------------------------------
      function erl2_y (te, dene)
	implicit real*8(a-h,o-z)
	include 'comm_i.inc'		

c     Compute electron radiation loss rate per H ion due to
c  recombination" processes - D. Stotler's "coupling to the continuum"
c     te [eV]          = electron temperature
c     dene [/cm**3]      = electron density
c     erl2 [erg/sec]    = radiation rate

c  Te(jt) = 10**(-1.2 + (jt-1)/10) jt=1,60
c    dene(jn) = 10**(10 + 0.5*(jn-1)) jn=1,15 

c-------------------------------------------------------------------c
	istabon=10
c

c-------------------------------------------------------------------c
      if (istabon .eq. 8 .or. istabon .eq. 9) then 
c linear interpolation
c     compute abscissae --
         zloge=dlog(te)
         rle=max(rlemin, min(zloge,rlemax))
         zlogd=dlog10(dene)
         rld=max(rldmin, min(zlogd,rldmax))
c     table indicies for interpolation --
         je=int((rle-rlemin)/delekpt) + 1
         je=min(je,mpe-1)
         jd=int((rld-rldmin)/deldkpt) + 1
         jd=min(jd,mpd-1)
c     fractional parts of intervals (je,je+1) and (jd,jd+1) --
         fje=(rle-ekpt(je))/(ekpt(je+1)-ekpt(je))
         fjd=(rld-dkpt(jd))/(dkpt(jd+1)-dkpt(jd))
c     radiation rate --
         erl211=welms2(je,jd)
         erl212=welms2(je,jd+1)
         erl221=welms2(je+1,jd)
         erl222=welms2(je+1,jd+1)
         erl21=erl211+fjd*(erl212-erl211)
         erl22=erl221+fjd*(erl222-erl221)
         erl2_y = erl21 + fje*(erl22-erl21)

c-------------------------------------------------------------------c
      elseif (istabon .eq. 10) then 
c# logarithmic interpolation of Stotler-95

c     compute abscissae --
         zloge=dlog(te)
         rle=max(rlemin, min(zloge,rlemax))
         zlogd=dlog10(dene)
         rld=max(rldmin, min(zlogd,rldmax))
c     table indicies for interpolation --
         je=int((rle-rlemin)/delekpt) + 1
         je=min(je,mpe-1)
         jd=int((rld-rldmin)/deldkpt) + 1
         jd=min(jd,mpd-1)
c     fractional parts of intervals (je,je+1) and (jd,jd+1) --
         fje=(rle-ekpt(je))/(ekpt(je+1)-ekpt(je))
         fjd=(rld-dkpt(jd))/(dkpt(jd+1)-dkpt(jd))
c     radiation rate --  now logarithm of rate
         erl211=dlog( welms2(je,jd) )
         erl212=dlog( welms2(je,jd+1) )
         erl221=dlog( welms2(je+1,jd) )
         erl222=dlog( welms2(je+1,jd+1) )
         erl21=erl211+fjd*(erl212-erl211)
         erl22=erl221+fjd*(erl222-erl221)
         erl2_y = dexp( erl21 + fje*(erl22-erl21) )
c---------------------------------------------------------

      endif

      return
      end

c---------------------------------------------------------------------
      subroutine readehr1_y 

	implicit real*8(a-h,o-z)
	include 'comm_i.inc'		
c---------------------------------------------------------------------
c     Read density-dependent hydrogenic rate file, e.g., 'ehr1.dat'
c---------------------------------------------------------------------
c istabon =9 or 10
	mpd=15
	mpe=60
      open (unit=10, file='ehr2.dat', status='old', form='formatted')
c     ionization rate (cm**3/sec):
      do 12 jd=1,mpd
      read(10,*) 
      read(10,*) 
         read(10,*)(wsveh(jt,jd),jt=1,mpe)
 12   continue
c     recombination rate (cm**3/sec):
      read(10,*) 
      do 14 jd=1,mpd
      read(10,*) 
      read(10,*) 
      read(10,*)(wsveh0(jt,jd),jt=1,mpe)
 14   continue
c     neutral-electron radiation loss rate (erg/sec):
      read(10,*) 
      do 16 jd=1,mpd
      read(10,*) 
      read(10,*) 
         read(10,*) (welms1(jt,jd),jt=1,mpe)
 16   continue
c     continuum-electron radiation loss rate (erg/sec):
      read(10,*) 
      do 18 jd=1,mpd
      read(10,*) 
	read(10,*) 
            read(10,*) (welms2(jt,jd),jt=1,mpe)
 18   continue

      close (10)
	call setauxvar_y
      return
      end
c--------------------------------------------------------------------
      subroutine setauxvar_y

	implicit real*8(a-h,o-z)
	include 'comm_i.inc'		      
	
c--------------------------------------------------------------------
c  Set density and temperature data for DEGAS and POST93 rate tables
c--------------------------------------------------------------------

c     local variables --
      integer jd,je

c     dkpt = log10 of density(/cm**3) :
      dkpt(1)=10.0
      do jd=2,mpd
         dkpt(jd)=dkpt(jd-1)+0.5
      enddo
      rldmin=dkpt(1)
      rldmax=dkpt(mpd)
      drefmin=10.0**rldmin
      drefmax=10.0**rldmax
      deldkpt=(rldmax-rldmin)/real(mpd-1)

c     ekpt = natural log of temperature(eV) :

       ekpt(1)=-1.2*log(10.0)	! new tables start at .06 eV
      
      do je=2,mpe
         ekpt(je)=ekpt(je-1)+0.1*log(10.0)
      enddo
      rlemin=ekpt(1)
      rlemax=ekpt(mpe)
      erefmin=exp(rlemin)
      erefmax=exp(rlemax)
      delekpt=(rlemax-rlemin)/real(mpe-1)

      return
      end

c-----------------------------------------------------------------------
      function rsa_y (te, dene)

	implicit real*8(a-h,o-z)
	include 'comm_i.inc'		            
	
	
c     te [eV]          = electron temperature
c     ne [/cm**3]      = electron density
c     rsa [cm**3/sec]  = <sigma v>

c----------------------------------------------------------------------c
	istabon=10
      if (istabon .eq. 10) then  ! logarithmic interp on Stotler-95 tables

c     compute abscissae --
         zloge=dlog(te)
         rle=max(rlemin, min(zloge,rlemax))
         zlogd=dlog10(dene)
         rld=max(rldmin, min(zlogd,rldmax))
c     table indicies for interpolation --
         je=int((rle-rlemin)/delekpt) + 1
         je=min(je,mpe-1)
         jd=int((rld-rldmin)/deldkpt) + 1
         jd=min(jd,mpd-1)
c     fractional parts of intervals (je,je+1) and (jd,jd+1) --
         fje=(rle-ekpt(je))/(ekpt(je+1)-ekpt(je))
         fjd=(rld-dkpt(jd))/(dkpt(jd+1)-dkpt(jd))
c     ionization rate parameter -- now logarithm of rates
         rsa11=dlog( wsveh(je,jd) )
         rsa12=dlog( wsveh(je,jd+1) )
         rsa21=dlog( wsveh(je+1,jd) )
         rsa22=dlog( wsveh(je+1,jd+1) )
         rsa1=rsa11 + fjd*(rsa12-rsa11) 
         rsa2=rsa21 + fjd*(rsa22-rsa21) 
         rsa_y = dexp( rsa1 + fje*(rsa2-rsa1) )

c----------------------------------------------------------------------c
      endif

      return
      end

c----------------------------------------------------------------------c
      function rra_y (te,dene)
      

	implicit real*8(a-h,o-z)
	include 'comm_i.inc'		            	
	

c     Compute rate parameter for  recombination
c     te [eV]          = electron temperature
c     ne [/cm**3]      = electron density
c     rra [cm**3/sec]  = <sigma v>

c----------------------------------------------------------------------c
	istabon=10

      if (istabon .eq. 10) then  ! use logarithmic interp on Stotler-95
c     compute abscissae --
         zloge=dlog(te)
         rle=max(rlemin, min(zloge,rlemax))
         zlogd=dlog10(dene)
         rld=max(rldmin, min(zlogd,rldmax))
c     table indicies for interpolation --
         je=int((rle-rlemin)/delekpt) + 1
         je=min(je,mpe-1)
         jd=int((rld-rldmin)/deldkpt) + 1
         jd=min(jd,mpd-1)
c     fractional parts of intervals (je,je+1) and (jd,jd+1) --
         fje=(rle-ekpt(je))/(ekpt(je+1)-ekpt(je))
         fjd=(rld-dkpt(jd))/(dkpt(jd+1)-dkpt(jd))
c     recombination rate parameter --
         rra11=dlog( wsveh0(je,jd) )
         rra12=dlog( wsveh0(je,jd+1) )
         rra21=dlog( wsveh0(je+1,jd) )
         rra22=dlog( wsveh0(je+1,jd+1) )
         rra1=rra11+fjd*(rra12-rra11)
         rra2=rra21+fjd*(rra22-rra21)
         rra_y = dexp( rra1 + fje*(rra2-rra1) )

c----------------------------------------------------------------------c
      endif

      return
      end
c-----------------------------------------------------------------------




