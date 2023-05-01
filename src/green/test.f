	program circ_test

	character *20 yy
        
        integer :: nact=-1, npass=-1
        integer :: kloop=-1,kprobe=-1, ke=-1, ngrid=-1
 
	character *20 apr


 !     kpr=1

      print *,'circ test...'

      call tokamakdata_read_1()

      call congig_calc()

      call read_green_params(npass,nact,kloop,kprobe,ke,ngrid)
        
      print *,'npass',npass
      print *,'nact',nact
      print *,'kloop',kloop
      print *,'kprobe',kprobe
      print *,'ke',ke
      print *,'ngrid',ngrid

      end
      