Constants controlling reading data from exp/... and udb/...
C*Polevoi 25-NOV-2009 (see NBDMAX)
C  NCONST   max No. of the simple variables & constants 
C		(both lists are in the file "const.inc")
C	    which can be initialized from a data (exp/...) file
C	    and are recognizable by the Astra Compiler
C		Increase of NCONST beyond 256 requires
C		changes in the Astra Compiler "nambuf.inc"
C  NARRX    No. of arrays readable from a data file (common block A_CARX)
C  NRD	    max No. of radial points in the transport grid
C  NRDX	    max No. of radial points in exp data
C  NTIMES   max No. of stored time slices for output in mode 6
C  NRW	    max No. of radial and time curves for output
C  NBDMAX   max No. of poloidal points (must be consistent with ntp in SPIDER)
	integer NRD,NRW,NCONST,NARRX,NRDX,NTVAR,NTARR,NEQNS,NSBMX
	integer NBDMAX,NBDTMAX
	parameter(NRD=601, NRW=128, NCONST=256, NARRX=67, NSBMX=20)
C  NTVAR total No. of the time slices for all variables in a data file
C  NTARR total No. of the time slices for all arrays in a data file
C  NEQNS max. total No. of eqns in a model, is used in .srv/tmpbuf.inc
C  NBDMAX max number for boundary (poloidal)
C  NBDTMAX max number for boundary (time slices) must be > 13
C  (2*NBDMAX+1)*10 points are reserved for equilibrium output
	parameter(NRDX=200, NTVAR=25000, NTARR=25000, NEQNS=19)
	parameter(NBDMAX=256,NBDTMAX=50)