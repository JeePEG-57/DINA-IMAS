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

1     continue      


	ntay=ntay+1
	tt=tt+tay


	if(kpr.eq.1)print*,'!!!tt tay ntay',tt,tay,ntay

	if(kpr.eq.1)print*,'@@@@@from main  next i_wr',next,i_wr

	call vic_shape_elong()
	if(ntay.le.next)call shape_ip()

      call vic_shape_ip_iam()
	if(i_wr.eq.0.and.ntay.gt.next)call r_tok_p()

        call r_volt()
        call vic_gaps0_read()

      do i=1,n_ga
      if(kpr.eq.1)print *,' i gaps-',i,gaps(i)
      end do

ccc	if(ntay.gt.next.and.tt.gt.tt_h_to_l)key_h_to_l=1
	if(kpr.eq.1)print*,'!!!tt tt_h_to_l key_h_to_l',tt,tt_h_to_l,key_h_to_l

	if(ntay.gt.next)call SCEN_CONTROL(key_h_to_l)
ccc	if(ntay.gt.next.and.tt.lt.tt_h_to_l)call SCEN_CONTROL()
c!!!	if(tt.gt.tt_h_to_l+80.)call SCEN_CONTROL()

  	 call equil()
c  i_fil=0  old case without reconstruction....
	call separ_coor()                                                
	call separ_coor2()                                                
      call get_gaps()

  	 go to 1
  	 
      END
