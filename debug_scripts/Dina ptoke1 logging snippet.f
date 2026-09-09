c=====================================================================
c  DIAGNOSTIC PATCH -- p'/FF' iteration logging
c
c  File to edit : src/scenario/neq0_sep_lim_32.f
c  Subroutine   : ptoke1_c
c  Insert AFTER the existing block that rescales ppx/pffx by al1:
c
c        alfa0=alfa0*al1
c
c        do i=1,n
c        ppx(i)=ppx(i)*al1
c        pffx(i)=pffx(i)*al1
c
c        pptab(i)=pptab(i)*al1
c        fptab(i)=fptab(i)*al1
c
c        end do
c
c        <<< PASTE THE BLOCK BELOW RIGHT HERE >>>
c
c        c        fdd_1=fdd            <-- (existing comment line, unchanged,
c                                            just shows you the "stop" point)
c
c  Why here: ppx(1:n)/pffx(1:n) are the equilibrium's p'(a)/FF'(a) tables on
c  the fixed transport-grid coordinate "poa" (== the global "a(npo)" array,
c  aliased locally here through /ge3/), and this is the point in every single
c  Picard iteration of ptoke1_c (i.e. every equilibrium iteration, from ANY of
c  the calling loops in n_matlab_kav.f / n_matlab_kav2.f) where they take their
c  final value for this iteration. al1 and errm are already computed by this
c  point too, so they're logged alongside for free -- al1 is the current-
c  normalization multiplier and errm is DINA's own Picard convergence residual,
c  both very useful context for diagnosing "weird" p'/FF' behaviour.
c
c  i_bound is a dummy argument of ptoke1_c that is incremented once per call
c  and persists across the WHOLE run (all time steps, all calling loops), so
c  it is a safe, monotonically increasing global iteration counter to log
c  against -- no extra plumbing needed.
c
c  Units 91/92 are just two numbers unlikely to collide with anything else in
c  DINA. If you get a "unit already connected"-type runtime error, bump them
c  to e.g. 93/94 and re-run.
c=====================================================================

	logical logfirst
	data logfirst /.true./

	if (logfirst) then
	   open(unit=91,file='p_prime.log', status='replace',
     *          form='formatted')
	   open(unit=92,file='ff_prime.log',status='replace',
     *          form='formatted')
	   write(91,'(A)') '# DINA p'' profile log -- one row per '//
     *          'equilibrium Picard iteration (every ptoke1_c call)'
	   write(91,'(A,I6)') '# n = ',n
	   write(91,'(A,400(1x,1pe14.6))') '# grid_a',(poa(i),i=1,n)
	   write(91,'(A)') '# columns: iter ntay tt al1 errm '//
     *          'ppx_1 ... ppx_n'
	   write(92,'(A)') '# DINA FF'' profile log -- one row per '//
     *          'equilibrium Picard iteration (every ptoke1_c call)'
	   write(92,'(A,I6)') '# n = ',n
	   write(92,'(A,400(1x,1pe14.6))') '# grid_a',(poa(i),i=1,n)
	   write(92,'(A)') '# columns: iter ntay tt al1 errm '//
     *          'pffx_1 ... pffx_n'
	   logfirst=.false.
	end if

	write(91,'(I8,1x,I8,1x,1pe14.6,1x,1pe14.6,1x,1pe14.6,
     *          400(1x,1pe14.6))')
     *          i_bound,ntay,tt,al1,errm,(ppx(i),i=1,n)
	write(92,'(I8,1x,I8,1x,1pe14.6,1x,1pe14.6,1x,1pe14.6,
     *          400(1x,1pe14.6))')
     *          i_bound,ntay,tt,al1,errm,(pffx(i),i=1,n)

	flush(91)
	flush(92)

c=====================================================================
c  END OF DIAGNOSTIC PATCH
c=====================================================================