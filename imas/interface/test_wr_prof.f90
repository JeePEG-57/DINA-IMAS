      program test_wr_prof

	integer :: kpr
	common/ge5/kpr

	kpr = 1

      call ids_prof_jetto()

      return
      end



