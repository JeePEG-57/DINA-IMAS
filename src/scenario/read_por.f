
	subroutine prog_br()

	include 'double.inc'
	include 'parf0'
	include 'parf1'
	include 'parft'
     
	common 
     *  /time1/pf_e(n_t,kf)
     *  /time1e/pf_ex(kf)
     *  /ptime5/time_e(n_t)
     *  /time16/volt_e(n_t,kf)
     *  /time17/res_e(n_t,kf)


    	common 
     *  /pkey_time1/n_time

	common
     *  /cont1/vchopper(kf),veps
     
	common
     *  /ge2/NTAY,TAY,TT
     *  /ge5/kpr
        common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)

	character *20 apr

        if(kpr.eq.1)print *,' PROG_VOLT ntay',ntay

	do i=2,n_time
	
        if( (tt-time_e(i-1))*(tt-time_e(i)).le.0.)then
c==================
	 t_coef=(tt-time_e(i-1))/( time_e(i)-time_e(i-1) )
c=================
	 
	if(kpr.eq.1)print *,' tt time_e1 time_e_2',
     *  tt,time_e(i-1),time_e(i)
        i_pfe=i_pfe+1
	if(kpr.eq.1)print *,'  from SHAPE i_pfe',i_pfe


	do k=1,npf

	pf_ex(k)=pf_e(i-1,k)+t_coef*(pf_e(i,k)-pf_e(i-1,k))
	pf_ex(k)=pf_ex(k)*1.e+3

        if(i_pfe.eq.1)pf(k)=pf_ex(k)


	vchopper(k)=volt_e(i-1,k)+t_coef*(volt_e(i,k)-volt_e(i-1,k))

c	if(k.eq.npf)vchopper(k)=-10.

	end do
	apr='PF_ex'
	if(kpr.eq.1)print 71,apr,(pf_ex(k),k=1,npf)
	apr='PF'
	if(kpr.eq.1)print 71,apr,(pf(k),k=1,npf)
	
	apr='VOLT'
	if(kpr.eq.1)print 71,apr,(vchopper(k),k=1,npf)
	apr='RES'
	if(kpr.eq.1)print 71,apr,(pfres(k),k=1,npf)
	
	end if
	end do

71	format(20x,a6/,(6(1pe10.3)))
	return
	end

	subroutine read_time_p()
		
	include 'double.inc'
    	common 
     *  /pkey_time1/n_time

        open(unit=41,file='add_data_p',form='formatted')
        read (41,*)
        read (41,*)n_time
        close (41)
c----------------------------  	   	
	call pf_file()
	call v_file()
	call res_file()
	call time_file()
c----------------------------

	return
	end	
	
	subroutine res_file()
	
	include 'double.inc'
	include 'parft'
	include 'parf1'
	
	common 
     *  /time17/res_e(n_t,kf)
    	common 
     *  /pkey_time1/n_time
        common
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf8/pfind(kf,kf),pfres(kf),a1(kf,kf),e1(kf),e2(kf)
     
     	dimension x(n_t)
     
     	character *20 apr
     	data apr /'resistors.txt'/
          			
	open (unit=41,file=apr,form='formatted')
	
 	do k=1,1
           do i=1,npf
              read (41,*)res_e(k,i)
           end do
 	end do

 	do k=2,n_time
           do i=1,npf
              res_e(k,i)=res_e(1,i)
              pfres(i)=res_e(1,i)*1.e-6
           end do
 	end do
 	
	close (41)		

	if(kpr.eq.1)print *,' n_time apr',n_time,apr		
 	
	if(kpr.eq.1)print *,' n_time apr',n_time,apr		
c	if(kpr.eq.1)print *,' time_e1 e2 e3',time_e(1),time_e(2),time_e(3)
c 	read (*,*)
 	
	return
	end
	
	
	subroutine time_file()
	
	include 'double.inc'
	include 'parft'
	
	common 
     *  /ptime5/time_e(n_t)
    	common 
     *  /pkey_time1/n_time
     
     	dimension x(n_t)
     
     	character *20 apr
     	data apr /'time.txt'/
	
 	call r_file(apr,x,n_time)
 	do k=1,n_time
 	time_e(k)=x(k)
 	end do
 	
	if(kpr.eq.1)print *,' n_time apr',n_time,apr		
c	if(kpr.eq.1)print *,' time_e1 e2 e3',time_e(1),time_e(2),time_e(3)
c 	read (*,*)
 	
	return
	end
	

	subroutine pf_file()
	include 'double.inc'
	include 'parft'
	include 'parf1'
 	common 
     *  /time1/pf_e(n_t,kf)
    	common 
     *  /pkey_time1/n_time

        common
     *  /pf1/npf,pf(kf),pf0(kf)
     
     	character *20 apr

     	data apr /'icoilsshort.txt'/
          			
	open (unit=41,file=apr,form='formatted')
	
 	do k=1,n_time
	read (41,*)(pf_e(k,i),i=1,npf)

	apr='PF_e'
c	if(kpr.eq.1)print 71,apr,(pf_e(k,i),i=1,npf)
 	end do
 	
	close (41)		

	if(kpr.eq.1)print *,' n_time apr',n_time,apr		

71	format(20x,a6/,(6(1pe10.3)))

	return
	end
	
	
	subroutine v_file()
	
	include 'double.inc'
	include 'parf1'
	include 'parft'
	
	common 
     *  /time16/volt_e(n_t,kf)
    	common 
     *  /pkey_time1/n_time

        common
     *  /pf1/npf,pf(kf),pf0(kf)
     
     	dimension x(n_t)
     
     	character *20 apr
     	data apr /'vcoils.txt'/
          			          			
	open (unit=41,file=apr,form='formatted')
	
 	do k=1,n_time
           read (41,*)(volt_e(k,i),i=1,npf)
	apr='volt_e'
c	if(kpr.eq.1)print 71,apr,(volt_e(k,i),i=1,npf)
 	end do
 	
	close (41)		

	if(kpr.eq.1)print *,' n_time apr',n_time,apr		
c 	read (*,*)
		
71	format(20x,a6/,(6(1pe10.3)))
	return
	end
	
	subroutine r_file(apr,x,n)
     
	include 'double.inc'
     	dimension x(n)
     
     	character *20 apr
     	
	
	open (unit=41,file=apr,form='formatted')

 	do k=1,n
	read (41,*)x(k)
 	end do
 	
	close (41)		
	
	return
	end


	subroutine pf_waits()

	include 'double.inc'
	include 'parf1'

        common
     *  /ge5/kpr
     *  /ge12e1/seps_pf(kf),pf_max(kf)

        COMMON
     *  /pf1/npf,pf(kf),pf0(kf)
     *  /pf3/nmx(kf),turn(kf)
     
     	character *20 apr
     	data apr /'pf_waits'/          				
	
	
	open (unit=41,file=apr,form='formatted')
	
	read (41,*)
	read (41,*)(pf_max(i),i=1,npf)
	read (41,*)
        read (41,*)(seps_pf(i),i=1,npf)
 	
	close (41)		
		
        do k=1,npf
	pf_max(k)=pf_max(k)*1.e+3/turn(k)
        end do

	return
	end




