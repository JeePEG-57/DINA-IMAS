c=====================================================================
c  DIAGNOSTIC PATCH -- FF' (as produced by the DIFMF_1 chain) logging
c
c  IMPORTANT CORRECTION vs. the literal request "log ff' at the end of
c  DIFMF_1": difmf_1_c (src/scenario/ddunew0.f) never computes PP/PFF at
c  all. It only solves the 1D current-diffusion equation for DM0(npo) and
c  derives PSI(npo)/PFI(npo)/Q(npo) (all in COMMON /DFM2/ and /dfm4/) --
c  none of those is p' or FF'. The actual FF'(a) array, PFF(npo), is built
c  immediately afterwards by TOKK (src/scenario/diter_1.f), called from
c  pff_calc() (src/scenario/ndop1_new2_400.f), by combining DIFMF_1's PSI
c  array with the independently-computed pressure gradient PP(npo) (from
c  pp_calc()). So "FF' as it comes out of the DIFMF_1 step" really means:
c  right after TOKK returns inside pff_calc, on the SAME per-timestep call
c  that immediately follows DIFMF_1's solve. That is the hook point below.
c
c  File to edit : src/scenario/ndop1_new2_400.f
c  Subroutine   : pff_calc
c
c  STEP 1 -- add /ge2/ to pff_calc's COMMON block list (ntay/tt are not
c  currently visible inside pff_calc; this common block is declared
c  identically all over this same file, e.g. at line 825, so this is a
c  pure drop-in addition, no risk of a COMMON mismatch). Find this block
c  near the top of pff_calc (ndop1_new2_400.f, around line 2086-2090):
c
c        common
c     *	/ge1/pi
c     *	/ge1e/rs0,tpl
c     *	/ge3/AI(npo),A0(npo),HA2(npo),a(npo),ha(npo)
c     *  /ge5/kpr
c
c  and change it to:
c
c        common
c     *	/ge1/pi
c     *	/ge1e/rs0,tpl
c     *	/ge2/ntay,tay,tt
c     *	/ge3/AI(npo),A0(npo),HA2(npo),a(npo),ha(npo)
c     *  /ge5/kpr
c
c  STEP 2 -- insert the logging block below RIGHT AFTER this existing line
c  (ndop1_new2_400.f, around line 2097):
c
c        CALL TOKK(N,RS0)
c
c        <<< PASTE THE BLOCK BELOW RIGHT HERE >>>
c
c        c                                   <-- (existing blank/comment line,
c                                                  just shows you the "stop" point)
c        tok=0.
c        z_cur=0.
c        ...
c
c  Why here: at this exact point PFF(1:n) has just been fully computed by
c  TOKK for this pass (the do-33 loop inside TOKK, diter_1.f, already ran to
c  completion before returning), on the fixed grid a(1:n) (COMMON /ge3/,
c  already in pff_calc's common list -- same physical grid ppx/pffx live on
c  elsewhere, just locally called "a" here instead of "poa"). n itself comes
c  from /n_m/n,m,mp, also already in scope.
c
c  Cadence note: pff_calc (and therefore this log) is called roughly ONCE
c  PER OUTER DIFFUSION/GS-CONVERGENCE PASS -- i.e. after the inner ptoke1
c  Picard loop for that pass has already converged -- NOT once per ptoke1
c  iteration. So this log will have far FEWER rows than p_prime.log /
c  ff_prime.log (which log every single ptoke1_c call). That is expected:
c  it lets you compare "FF' input freshly produced by the diffusion solve"
c  against "FF' actually being iterated on by ptoke1" from the other log.
c
c  al1/errm placeholders: pff_calc has no equivalent of ptoke1_c's al1
c  (current-normalization multiplier) or errm (Picard residual) -- those
c  only exist inside ptoke1_c. To keep this log file readable by the SAME
c  notebook parser used for p_prime.log/ff_prime.log (which expects 5
c  leading columns: iter ntay tt al1 errm), those two columns are written
c  as a fixed 0.0 here. Only iter/ntay/tt and the pff_1..pff_n profile are
c  meaningful in this file.
c
c  iter: pff_calc has no persistent global counter like i_bound (that only
c  lives in the higher-level driver files, not in pff_calc/TOKK). A local
c  SAVE'd counter, incremented once per pff_calc call, is used instead --
c  it is monotonic across the whole run just like i_bound, it just counts
c  "outer passes that reached pff_calc" rather than "ptoke1_c calls".
c
c  Unit 93 is used here (91/92 are already taken by the p'/FF' Picard log
c  patch). Bump to e.g. 94 if you get a "unit already connected" error.
c=====================================================================

	logical logfirst_pff
	integer call_idx_pff
	save logfirst_pff, call_idx_pff
	data logfirst_pff /.true./
	data call_idx_pff /0/

	call_idx_pff = call_idx_pff + 1

	if (logfirst_pff) then
	   open(unit=93,file='ff_prime_difmf1.log', status='replace',
     *          form='formatted')
	   write(93,'(A)') '# DINA FF'' (DIFMF_1/TOKK output) log -- '//
     *          'one row per pff_calc call (roughly once per outer '//
     *          'diffusion/GS pass, NOT per ptoke1 Picard iteration)'
	   write(93,'(A,I6)') '# n = ',n
	   write(93,'(A,400(1x,1pe14.6))') '# grid_a',(a(i),i=1,n)
	   write(93,'(A)') '# columns: iter ntay tt al1 errm '//
     *          'pff_1 ... pff_n  (al1,errm are unused placeholders '//
     *          '(always 0.0) -- pff_calc has no equivalent quantity)'
	   logfirst_pff=.false.
	end if

	write(93,'(I8,1x,I8,1x,1pe14.6,1x,1pe14.6,1x,1pe14.6,
     *          400(1x,1pe14.6))')
     *          call_idx_pff,ntay,tt,0.d0,0.d0,(pff(i),i=1,n)

	flush(93)

c=====================================================================
c  END OF DIAGNOSTIC PATCH
c=====================================================================