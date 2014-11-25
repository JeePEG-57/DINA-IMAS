	subroutine correct()
C
	include 'double.inc'
	character * 12 apr

	common /min_max/xmn,xmx,fmn,fmx

        real *8 xmin,xmax,unitx

72	format(20x,a6/,(1x,8(i4)))
71	format(20x,a6/,(1X,8(1pe10.3)))

c        xmin_1=-1.e-2
c        xmax_1=0.16

        xmin=fmn
        xmax=fmx
        
        if(kpr.eq.1)print *,' xmin xmax',xmin,xmax

c!!!        call u_choice(xmin,imin,xmax,imax,unitx)
c       double*xmin,*xmax,*unitx;
 
        if(kpr.eq.1)print *,' xmin xmax unitx ',xmin,xmax,unitx

        fmn=xmin
        fmx=xmax
	return

        end


