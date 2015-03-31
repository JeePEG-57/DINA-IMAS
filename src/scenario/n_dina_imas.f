	subroutine dina(time_8,tt_8,tay_8,key_mat,vec_mat,
     *	p_input_1,p_input_2,p_input_3,
     *	output_1,output_2,output_3,output_4,ng)


	include 'double.inc'
	include 'new_com.inc'

	real *8 time_8, tay_8
	real *8 tt_8 

	real *8 vec_mat(*)
		
	dimension key_mat(*) 

	real *8 p_input_1(*),p_input_2(*),p_input_3(*)

	real *8 output_1(*)
	real *8 output_2(*)
	real *8 output_3(*)
	real *8 output_4(*)


	real *8 a_print(200)
	
      parameter (kint=200)
      
      dimension c_input1(kint),c_input2(kint)
      dimension c_output1(kint),c_output2(kint),c_output3(kint)

	character *25 apr


c =================================================================

c	print *,' ok1 '

c =================================================================

	i_en0=i_en0+1    

      ng=i_en0

      kpr=key_mat(4)

      do i=1,6
	a_print(i)=key_mat(i)
      end do
      
	n_pr=6
	apr='  key'
	num=6
!	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)
                                                                        



      if(i_en0.eq.1.and.kpr.eq.1)then
!      if(i_en0.eq.1)then
!      bret=AllocConsole() ;

!      Iopen=1
!      call OpenCloseConsole(Iopen) 
          
      end if


!key_imas(4)=3;  % print

!key_imas(6)=2;  % input1
!key_imas(7)=15;  % input2
!key_imas(8)=54;  % input3


!key_imas(11)=15;       %  output1
!key_imas(12)=n_gaps+npf+ncam+2;  %  output2



      n_input1=key_mat(6)
      do i=1,n_input1
      c_input1(i)=p_input_1(i)
      end do

      do i=1,n_input1
	a_print(i)=c_input1(i)
      end do
      
	n_pr=n_input1
	apr='  c_input1'
	num=10
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


      n_input2=key_mat(7)
      
     
      do i=1,n_input2
      c_input2(i)=p_input_2(i)
      end do

      do i=1,n_input2
	a_print(i)=c_input2(i)
      end do
      
	n_pr=n_input2
	apr='  c_input2'
	num=10
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


  !      c_input1(1)=tpl

 !       goto 5

	  call dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2,c_output3)

c ============ outputs ==============================================

5     continue


      n_output1=key_mat(11)
      do i=1,n_output1
		output_1(i)=c_output1(i)
        end do

      do i=1,n_output1
	a_print(i)=output_1(i)
      end do
      
	n_pr=n_output1
	apr='  output1'
	num=10
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

      n_output2=key_mat(12)
      
	a_print(1)=npf
	a_print(2)=n_gaps
      
	n_pr=2
	apr='  npf n_ga'
	num=10
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)
              
        do i=1,n_output2
        output_2(i)=c_output2(i)
        end do

      do i=1,n_output2
	a_print(i)=output_2(i)
      end do
      
	n_pr=n_output2
	apr='  output2'
	num=10
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

      n_output3=key_mat(13)

        do i=1,n_output3
        output_3(i)=c_output3(i)
        end do

      do i=1,n_output3
	a_print(i)=output_3(i)
      end do
      
	n_pr=n_output3
	apr='  output3'
	num=10
	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


      return
      end


