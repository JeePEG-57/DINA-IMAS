
	subroutine out42_c(ng,ygr,num,name)
	include 'double.inc'

	dimension ygr(*)
	character *20 name

!!!	if(kpr.eq.1)print '(a20,(20(1p,e12.5)))',name,(ygr(i),i=1,ng)
	if(kpr.eq.1)print '(a20/,(6(1p,e12.5)))',name,(ygr(i),i=1,ng)

	return
	end


	subroutine out42(n_pr,a_print,num,apr)
	include 'double.inc'
	dimension a_print(*)
	character *20 apr

	call out42_c(n_pr,a_print,num,apr)


	return
	end






	subroutine pau()
	include 'double.inc'

	return
	end

