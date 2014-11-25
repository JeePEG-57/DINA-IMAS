c	include 'fgraph.fi'
	include 'double.inc'
	include 'new_com.inc'

	character *20 yy

      kpr=1

  	 call equil()
c  i_fil=0  old case without reconstruction....
	call separ_coor()                                                
	call separ_coor2()                                                
      call get_gaps()

      n_gaps=n_ga

1     continue      


	ntay=ntay+1
	tt=tt+tay


	if(kpr.eq.1)print*,'!!!tt tay ntay',tt,tay,ntay

	if(kpr.eq.1)print*,'@@@@@from main  next',next

	if(kpr.eq.1)print*,'put_signals'


	call put_signals(z_cur,elong,xleft,
     *  xright,tpl,tt,
     *  npf,pf,n_ga,gaps,ntay,next,zvel,pf_turns,rsep,
     *  klim,t_end,i_wr)

!      print *,' gaps1',(gaps(i),i=1,n_ga)

      call get_signals(vchopper,tpl,tt_dw,gaps)

!      print *,' gaps2',(gaps(i),i=1,n_ga)

c-----------------------

      do i=1,npf
!      if(kpr.eq.1)print *,' i vchopper',i,vchopper(i)
      end do

  	 call equil()
c  i_fil=0  old case without reconstruction....
	call separ_coor()                                                
	call separ_coor2()                                                
      call get_gaps()

  	 go to 1
  	 
      END
