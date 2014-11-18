	subroutine dina_0(time_8,tt_8,tay_8,key_mat,vec_mat,
     *	p_input_1,p_input_2,p_input_3,
     *	output_1,output_2,output_3,output_4,ng)


	include 'double.inc'
!	include 'new_com.inc'

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
      dimension c_output1(kint),c_output2(kint)

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
                                                                        


      n_input1=2
      do i=1,n_input1
      c_input1(i)=p_input_1(i)
      end do

      do i=1,n_input1
	a_print(i)=c_input1(i)
      end do
      
	n_pr=n_input1
	apr='  c_input1'
	num=10
!	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

      n_input2=15
      
     
      do i=1,n_input2
      c_input2(i)=p_input_2(i)
      end do

      do i=1,n_input2
	a_print(i)=c_input2(i)
      end do
      
	n_pr=n_input2
	apr='  c_input2'
	num=10
!	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


  !      c_input1(1)=tpl

 !       goto 5

	  call dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2)

c ============ outputs ==============================================

5     continue


      n_output1=15
      do i=1,n_output1
		output_1(i)=c_output1(i)
        end do

      do i=1,n_output1
	a_print(i)=output_1(i)
      end do
      
	n_pr=n_output1
	apr='  output1'
	num=10
!	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)

      npf=12
      n_gaps=6

      n_output2=npf+n_gaps+npf
      
	a_print(1)=npf
	a_print(2)=n_gaps
      
	n_pr=2
	apr='  npf n_ga'
	num=10
!	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)
              
        do i=1,n_output2
        output_2(i)=c_output2(i)
        end do

      do i=1,n_output2
	a_print(i)=output_2(i)
      end do
      
	n_pr=n_output2
	apr='  output2'
	num=10
!	if(kpr.eq.3)call out42(n_pr,a_print,num,apr)


      return
      end
      
         subroutine  dina_v96_in(ncam,npf,kloop,kprobe,
     & 	gridrange,nact,npass,
     &	fluxarr,vesarr, pslgreen,bprgreen,
     &	pfind,pmj,pfc, pfres,rcam,
     &	xu,yu,ke,key,
     &   pfgreen,vesgreen,pfprobe,
     &   vesprobe,ngrid)

	   include 'double.inc'


      return
      end


	subroutine dina2(
!-----------------------------------  inputs---
     *  c_input1,c_input2,
!------------------------------------outputs
     *  c_output1,c_output2)

      include 'double.inc'

      dimension c_input1(*),c_input2(*)
      dimension c_output1(*),c_output2(*)


      n_output1=15
      do i=1,n_output1
	  c_output1(i)=i
!	  print *,' i c_output1=',i,c_output1(i)

      end do

      npf=12
      n_gaps=6
      
      n_output2=npf+n_gaps+npf
      
      do i=1,n_output2
	  c_output2(i)=2*i
!	  print *,' i c_output2=',i,c_output2(i)
      end do

      return
      end
