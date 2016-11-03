	subroutine transp10(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!     *  te0,tq0,pd0,pt0,ph0,pne,q,zeff,dm0,
!------------------------------------outputs
     *  c_output1,c_output2)


      include 'double.inc'
	include 'new_com.inc'                                                  

      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*)

      parameter (kint=200)

	dimension pf_xx(kint),gaps_xx(kint),pf_turns_xx(kint)

	dimension vchopper_x2(kint)

	character *20 apr,filename

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

!------------------------------------inputs
      
      print *,' CALL TRANSP1---- t_end',t_end
      
      ntay_h=ntay
      
      i_en=i_en+1
      if(i_en.eq.1)then

        open (unit=1,file='kpr.dat',form='formatted')
        read (1,*)
        read (1,*)kpr
        close ( unit=1)       

        open (unit=1,file='tran_times.dat',form='formatted')
        read (1,*)
        read (1,*)tt_dina
        read (1,*)
        read (1,*)t_ret
        close ( unit=1)       


c---  we think ....???
	ARG=1.
	pi=4.*atan(ARG)
      call read_data3()

      end if

      tt_1=tt_1+tay
      
      
      print *,' CALL TRANSP1 tt_1 tay t_end=',tt_1,tay,t_end
      
      if(tt_1.le.t_ret)return

      
      nn2=n
      
      
      filename='metric.dat'

c-------
           open (unit=41,file=filename,form='formatted')           
           read (41,*,err=2000,end=2000)(a(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(te0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(tq0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(pd0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(pt0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(ph0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(pne(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(q(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(zeff(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(dm0(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(dfmax(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(vi(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(a_m(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(r_m(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(gra1(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(gra2(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(bsq(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(fasp(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(volt(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(tok1(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(f(i),i=1,nn2)
           read (41,*,err=2000,end=2000)(spo(i),i=1,nn2)

           close (41)
           
2000	continue


      do i=2,n
      ha(i)=a(i)-a(i-1)
      psi8(i)=(dm0(i)-dm0(i-1))/ha(i)
	end do

      DO 31 I=2,N
      AI(I)=0.5*(A(I)+A(I-1))
	ha2(i-1)=ai(i)-ai(i-1)
31	continue
      HA2(N)=a(n)-ai(n)

      VMAX=1.E5
      DO I=1,n
    	VN(I)=VI(I)/VMAX
	end do
      
      kpr2=0
      if(kpr2.eq.1)then
      
      apr='vi-' 
      if(kpr.eq.1)print 71,apr,(vi(i),i=1,nn2) 
      apr='dm0-' 
      if(kpr.eq.1)print 71,apr,(dm0(i),i=1,nn2) 
      apr='psi-' 
      if(kpr.eq.1)print 71,apr,(psi8(i),i=1,nn2) 
      apr='ha-' 
      if(kpr.eq.1)print 71,apr,(ha(i),i=1,nn2) 
      apr='tok1-' 
      if(kpr.eq.1)print 71,apr,(tok1(i),i=1,nn2) 
      apr='volt-' 
      if(kpr.eq.1)print 71,apr,(volt(i),i=1,nn2) 
      apr='bsq-' 
      if(kpr.eq.1)print 71,apr,(bsq(i),i=1,nn2) 
      apr='fasp-' 
      if(kpr.eq.1)print 71,apr,(fasp(i),i=1,nn2) 
      
      end if
      
      DO I=1,n
    	qde0(i)=c_input1(i)
    	qdq0(i)=c_input2(i)
	end do

      if(i_en.eq.1)then
      call time_step_tran()
      end if

      apr='qde0-' 
      if(kpr.eq.1)print 71,apr,(qde0(i),i=1,nn2) 
      apr='qdq0-' 
      if(kpr.eq.1)print 71,apr,(qdq0(i),i=1,nn2) 


      apr='ten-' 
      if(kpr.eq.1)print 71,apr,(ten(i),i=1,nn2) 
      apr='tqn-' 
      if(kpr.eq.1)print 71,apr,(tqn(i),i=1,nn2) 

     
      ntay=ntay_1

      print *,' CAL ENERGY2(N) ntay_1',ntay_1

      call ENERGY2(N)
      apr='te0-' 
      if(kpr.eq.1)print 71,apr,(te0(i),i=1,nn2) 
      apr='tq0-' 
      if(kpr.eq.1)print 71,apr,(tq0(i),i=1,nn2) 
      call time_step_tran()

      ntay_1=ntay_1+1
 
      DO I=1,n
    	c_output1(I)=te0(i)
    	c_output2(I)=tq0(i)
	end do


      ntay=ntay_h

5000  format (50(1pe14.5))


      open (unit=61,file='dina_transp1.dat',form='formatted')

      write (61,*)n
      write(*,*) 'dina_transp1, n=,', n

      do i=1,n
      write (61,*) ai(i)
      enddo

      do i=1,n
      write (61,*) te0(i)
      enddo
      do i=1,n
      write (61,*) tq0(i)
      enddo

      close (61)

      return
      end



