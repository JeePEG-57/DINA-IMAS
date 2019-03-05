      subroutine bohm_gb()
 	include 'double.inc'

	include 'new_com.inc'
C
!	common
!     *  /mid6/bp_0(npo),a_m(npo),r_m(npo)
C
	common
     *  /bohm/he_bgb(npo),xi_bgb(npo)	! block for transport coefficients
C	
        call bohm_gb_c(
     *  n,bt0,a_m,r_m,dfmax,te0,pne,q,he_bgb,xi_bgb)
C
      return
      end
C
C ********************************************************************
C
	subroutine bohm_gb_c(
     *  n,bt,a_m,r_m,dfmax,te0,pne,q,he_bgb,xi_bgb)
C
C ********************************************************************
C
C	My own case of Bohm_gyroBohm_erba model !!!  
C	M.Erba et al. JET-R(95)02
C	M.Erba et al. JET-P(96)10
C
C	V.Parail's comments 
C	To include ion neo-clasical transport dxq(i)  
C
C	Usage: he = hiBohm + higBohm
C	Usage: xi = 2*hiBohm + 0.5*higBohm + dxq(i)
C
C ********************************************************************
C
C		te(n)		- electron temperature, [eV]		
C		pne(n)		- electron density, [m^-3](19)
C		q(n)		- safety factor 
C		flux(n)		- transport grid toroidal flux, [Wb]
C		btor		- vacuum toroidal magnetic field, [T]
C		r_in		- minimal radial position of plasma boundary,[m]
C		r_out		- maximal radial position of plasma boundary,[m]
C		hi_Bohm		- Heat conductivity Bohm-like model, [m^2/s]
C		hi_gBohm	- Heat conductivity gyroBohm model, [m^2/s]  
C 
	include 'double.inc'
C	
	include 'parf0'
C	
      dimension a_m(*),r_m(*),dfmax(*),te0(*),pne(*),q(*)
	dimension he_bgb(*),xi_bgb(*)
	dimension flux(npo)		! Toroidal flux, [Wb]	
	dimension zhibohm(npo),zhigbohm(npo)  
C	
	character*70 apr
C
C ====================================================================
C
C	Preparing Inputs for Bohm/gyroBohm model 
C
C ====================================================================
C	xleft  = 1.e6
C	xright = 1.e-6
C	do i = 1,mp
C		xleft  = min(uk(i),xleft)
C		xright = max(uk(i),xright)
C	end do
C --------------------------------------------------------------------
C
	xleft  = r_m(n) - a_m(n)		! minimal radial position of plasma boundary,[cm]
	xright = r_m(n) + a_m(n)		! maximal radial position of plasma boundary,[cm]
C
	r_in  = 1.0e-2 * xleft			! cm ---> m
	r_out = 1.0e-2 * xright			! cm ---> m
	btor  = 0.1 * bt				! kGs ---> T
C
	do i=1,n
		flux(i) = dfmax(i)*1.e-5	! kGs*cm^2 ---> Wb
	end do
C	
	kpr = 0
C
	if(kpr.eq.1) then

		if(kpr.eq.1)print *, ' btor [T] == ',btor 
		if(kpr.eq.1)print *, ' r_in [m] r_out [m] == ',r_in,r_out

		apr =' array -te0- for Bohm/gyroBohm ' 
		if(kpr.eq.1)print 71,apr,(te0(i), i = 1,n)

		apr =' array -pne- for Bohm/gyroBohm ' 
		if(kpr.eq.1)print 71,apr,(pne(i), i = 1,n)
		
		apr =' array -q- for Bohm/gyroBohm ' 
		if(kpr.eq.1)print 71,apr,(q(i), i = 1,n)

		apr =' array -flux- for Bohm/gyroBohm ' 
		if(kpr.eq.1)print 71,apr,(flux(i), i = 1,n)
	end if
C
	ibohm = 1		! Bohm/gyroBohm model for L-mode 
C
C =================== Bohm/gyroBohm model for L-mode =================
	do i=1,n 
		zhibohm(i) = hi_Bohm(te0,pne,q,flux,btor,r_in,r_out,ibohm,i,n)
		zhigbohm(i) = hi_gBohm(te0,flux,btor,i,n)
C		
		he_bohm = zhibohm(i) + zhigbohm(i)					! in m^2/s
		xi_bohm = 2.0 * zhibohm(i) + 0.5 * zhigbohm(i)		! in m^2/s
		he_bgb(i) = he_bohm
		xi_bgb(i) = xi_bohm
	end do


	do i=1,n 
		he_bgb(i) = he_bgb(i)+1.d-5
		xi_bgb(i) = xi_bgb(i)+1.d-5
	end do


C
C	kpr = 1
C
	if(kpr.eq.1) then
		apr =' array -zhibohm- for Bohm/gyroBohm ' 
		if(kpr.eq.1)print 71,apr,(zhibohm(i), i = 1,n)

		apr =' array -zhigbohm- for Bohm/gyroBohm ' 
		if(kpr.eq.1)print 71,apr,(zhigbohm(i), i = 1,n)

		apr =' array -he_bgb- for Bohm/gyroBohm ' 
		if(kpr.eq.1)print 71,apr,(he_bgb(i), i = 1,n)

		apr =' array -xi_bgb- for Bohm/gyroBohm ' 
		if(kpr.eq.1)print 71,apr,(xi_bgb(i), i = 1,n)
	end if
C
C =====================================================================
C 
C					end of Bohm/gyroBohm 
C
C =====================================================================
C
 71   format(10x,a70/,(6(1pe11.3)))
	return
	end

	function hi_Bohm(te,ane,q,flux,btor,r_in,r_out,ibohm,j,n)
C
C *******************************************************************
C
C hi_Bohm [m^2/s]: Heat conductivity Bohm-like model
C Source: M.Erba et al. JET-P(96)10
C Comments: V.Parail, F.Koach
C
C hi_Bohm = 2x10^(-4)*(a0/B0)*(dpe/drho)*a/ane*q^2
C a0 = (r_out - r_in)/2
C rh0 = sqrt(Toroidal Flux/2*pi/Bref)
C 
C All quantities are in SI units 
C except for Te which is in eV and pe in eV m^(-3)
C
C ********************************************************************
C
C Input variables:
C ----------------
C		r_in	- Minimal radial position of plasma boundary, [m]
C		r_out	- Maximal radial position  of plasma boundary, [m]
C		j		- radial index 
C		n		- size of input arrays used 
C
C Internal control variables:
C --------------------------- 
C		ibohm:	
C				1 - L-mode 
C Input arrays:
C -------------
C		te(n)	- electron temperature, [eV]		
C		ane(n)	- electron density, [m^-3] 
C		flux(n)	- transport grid toroidal flux, [Wb]
C		rho(n)	- effective minor radius, [m] 
C		btor	- vacuum toroidal magnetic field, [T]
C 
C Output:
C -------
C		hi_Bohm	- Heat conductivity Bohm-like model, [m^2/s]  
C
C ********************************************************************
C
	include 'double.inc'
C
	dimension te(*),ane(*),q(*),flux(*)
C
	pi = 4.0 * atan(1.0d0)
	pibtor = pi * btor
	a0 = 0.5 * ( r_out - r_in )
C	
	if( ibohm.ne.1 ) then
		if(kpr.eq.1)print *, 'not L-mode' 
	endif
C      
	if( J.eq.1 ) then
		YLP = 0.
	else
		rho = sqrt( flux(j) / pibtor )
		rhom = sqrt( flux(j-1) / pibtor )
		drho = rho - rhom
		zne = 0.5 * ( ane(j) + ane(j-1) )
		YLP = abs(ane(j) * te(j) - ane(j-1) * te(j-1)) / (drho * zne) 
		a0Bt = a0 / btor  
	endif
C
	Bohm = 2.0e-4
C
	hi_Bohm = Bohm * a0Bt * YLP * q(j)**2		! [m^2/s]
C
C	if(kpr.eq.1)print *, 'hi_Bohm - ok'
C
	if (j.eq.n-1) then
		if(kpr.eq.1)print *, ' *** j te ane q flux hi_Bohm ***'
		if(kpr.eq.1)print *, j,te(j),ane(j),q(j),flux(j),hi_bohm
	end if
	return
	end

	function hi_gBohm(te,flux,btor,j,n)
C
C *******************************************************************
C
C hi_gBohm [m^2/s]: Heat conductivity gyroBohm model
C Source: M.Erba et al. JET-P(96)10
C Comments: V.Parail, F.Koach
C
C hi_gBohm = 5x10^(-6)*sqrt(Te)/B0^2*(dTe/drho)
C 
C All quantities are in SI units except for Te which is in eV 
C
C ********************************************************************
C
C Input variables:
C ----------------
C		j		- radial index 
C		n		- size of input arrays used 
C
C Input arrays:
C -------------
C		te(n)	- electron temperature, [eV]		
C		flux(n)	- transport grid toroidal flux, [Wb]
C		btor	- vacuum toroidal magnetic field, [T]
C 
C Output:
C -------
C		hi_gBohm	- Heat conductivity gBohm model, [m^2/s]  
C
C ********************************************************************
C
	include 'double.inc'

	dimension te(*),flux(*)
C
	pi = 4.0 * atan(1.0d0)
	pibtor = pi * btor
C
	if( J.eq.1 ) then
		YLT = 0.
	else
		rho = sqrt( flux(j) / pibtor )			! rho(j)
		rhom = sqrt( flux(j-1) / pibtor )		! rho(j-1)
		drho = rho - rhom
		YLT = abs( (te(j) - te(j-1) ) / drho )
	endif
C	
	gBohm = 5.0e-6
C
	XLR	= sqrt( te(j) ) / btor**2		
C
	hi_gBohm = gBohm * YLT * XLR				! [m^2/s]
C	
	return
	end
