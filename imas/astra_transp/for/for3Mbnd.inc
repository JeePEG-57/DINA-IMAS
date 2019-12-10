c============================= global for 3M solver
		yrmax=-99999.d0
		yrmin=99999.d0
		yzmax=-99999.d0
		yzmin=99999.d0
	do j=1,NBND
		if(yzmin.ge.BNDARR(2*j+1)) then 
			yzmin=BNDARR(2*j+1)
			yrzmin=BNDARR(2*j)
		endif
		if(yzmax.le.BNDARR(2*j+1)) then 
			yzmax=BNDARR(2*j+1)
			yrzmax=BNDARR(2*j)
		endif
		if(yrmin.ge.BNDARR(2*j)) then 
			yrmin=BNDARR(2*j)

		endif
		if(yrmax.le.BNDARR(2*j)) then 
			yrmax=BNDARR(2*j)
		endif
	enddo
		yrr=.5d0*(yrmax+yrmin)
		SHIFT=yrr-RTOR
		ABC=.5d0*(yrmax-yrmin)
	if(ABC.le.0.d0) then
	write(*,*) 'error in boundary '//FILENA,' Rmax-Rmin < 0'
	write(*,*) 'continue with Rmax-Rmin = 1 m'
		ABC=1.d0
	endif
		elong=.5d0*(yzmax-yzmin)/ABC
	if(elong.le.0.d0) then
	write(*,*) 'Zmax, Zmin =', yzmax,yzmin
	write(*,*) 'error in boundary '//FILENA,' Zmax-Zmin < 0'
	write(*,*) 'continue with Zmax-Zmin = ',ABC
		elong=1.d0
	endif
		updwn=.5d0*(yzmin+yzmax)
		TRIAN=(yrr-0.5d0*(yrzmin+yrzmax))/ABC
C============================= global for 3M end