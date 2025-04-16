      subroutine buneto(psi,nwb,nhb,sia,nwnh)
	  include 'double.inc'
c**********************************************************************
c**                                                                  **
c**     MAIN PROGRAM:  MHD FITTING CODE                              **
c**                                                                  **
c**                                                                  **
c**     SUBPROGRAM DESCRIPTION:                                      **
c**          buneto sets up the appropriate arrays for the           **
c**          Buneman's solver.                                       **
c**                                                                  **
c**     CALLING ARGUMENTS:                                           **
c**                                                                  **
c**     REFERENCES:                                                  **
c**          (1)                                                     **
c**          (2)                                                     **
c**                                                                  **
c**     RECORD OF MODIFICATION:                                      **
c**          05 03/85..........first created                         **
c**          16 04/25..........refactored (loops improved)            **
c**                                                                  **
c**********************************************************************
      
      dimension   psi(nwnh), sia(nwnh)
      common/bunemn/m,n,s,shift,dr,dz

c     copy psi into sia rowwise                                          --
      do i = 1,nwb
         ii = (i-1)*nhb + 1
         do j = 1, nhb
            sia(i+j*nwb-nwb) = psi(ii-1+j)
         end do
      end do   
      ia = nwb+nwb
      ju = n*nwb

c     set up for rzpois
      do i = ia,ju,nwb
         sia(i-m+1) = sia(i-m+1)+(.5+.25/(1.+shift/dr))*sia(i-m)/s
         sia(i-1) = sia(i-1)+(.5-.25/(m-1+shift/dr))*sia(i)/s
      end do 
      call rzpois(sia,nwnh)
      nwhbb = nwb*nhb

c     copy sia back into psi columnwise                                          --
      do i = 2,n
         ii = (i-1)*nwb + 1
         do j = 2,m
            psi(i+j*nhb-nhb) = sia(ii-1+j)
         end do 
      end do   
 
      return
      end


      subroutine rzpois(q,nwnh)
c**********************************************************************
c**                                                                  **
c**     MAIN PROGRAM:  MHD FITTING CODE                              **
c**                                                                  **
c**                                                                  **
c**     SUBPROGRAM DESCRIPTION:                                      **
c**          rzpois solves for the poloidal flux using the           **
c**          Buneman's method.                                       **
c**                                                                  **
c**     CALLING ARGUMENTS:                                           **
c**                                                                  **
c**     REFERENCES:                                                  **
c**          (1)                                                     **
c**          (2)                                                     **
c**                                                                  **
c**     RECORD OF MODIFICATION:                                      **
c**          05 03/85..........first created                         **
c**          16 04/25..........refactored (goto removed)             **
c**                                                                  **
c**********************************************************************
	implicit real *8 (a-h,o-z)

      common/bunemn/m,n,s,shift,dr,dz
      dimension g(300),p(300),c(300),d(300),temp(300)
      dimension q(nwnh)
      include 'double_bunema.inc'

c     Initialize arrays
      do i = 1,300
         g(i) = 0.
         p(i) = 0.
         d(i) = 0.
      end do 
      do i = 1,300
         temp(i) = 0.
         c(i) = 0.
      end do

c     Compute temp array values
      shftdr = shift/dr
      do i = 2,m
         temp(i) = 1. - .5/(i+shftdr-1.)
      end do
   
      ju = (n-1)*(m+1)
      n222 = n/2
      c(n222) = 0.
      lo = n/2

c     Compute c array values
      call compute_c(c,lo,n,s)
   
      lo = n/2
      ko = 2
      id = 1
      
      iflag_do=1

c     Main computation loop
      do while (iflag_do == 1)
 
         li = 2*lo
         k4 = 2*ko-li/n
         jd = (m+1)*n/li
         jh = (m+1)*(n/(2*li))
         jt = jd+jh
         ji = 2*jd
         jo = jd*ko

          do j = jo,ju,ji
             j2 = j+2
             iu = j+m

             select case (k4)
                case (4)
                    call case_28(q,p,j2,iu,jt,jh,jd,j)   
                case (3)
                    call case_26(q,p,j2,iu,jd,j)   
                case (2)
                    call case_24(q,p,j2,iu,jh,jd,j) 
                case (1)
                    call case_20(q,p,j2,iu,jd,j)
            end select

c           Update arrays
            call update_arrays(g, p, d, temp, c, lo, n, li, m, s, id)

            do i = j2,iu
               q(i) = q(i)+p(i-j)
            end do

         end do
         
         iflag_do=0
         select case (ko)
            case (2)
               lo = lo/2
               if(lo == 1) ko = 1
               iflag_do = 1  
            case (1)
               lo = 2 * lo
               if (lo < n) iflag_do = 1
         end select

      end do 
      return
      end

      subroutine compute_c(c,lo,n,s)
         dimension c(300)

         i1=1
         do while(i1>=0)
            if(i1>0) then
               l = lo/2
               c(l) = sqrt(2.+c(lo))
               lo = l
               c(n-l) = -c(l)
               l = l+2*lo
               i1 = (2*l/n)*(2*lo-3)
            else if(i1==0) then
               c(n-l) = -c(l)
               l = l+2*lo
               i1 = (2*l/n)*(2*lo-3)
            end if

            if (i1==0) then
               c(l) = (c(l+lo)+c(l-lo))/c(lo)
            end if      
         end do

         do l = 2,n
            c(l-1) = 1./(2.+s*(2.-c(l-1)))
         end do

      end

      subroutine case_28(q,p,j2,iu,jt,jh,jd,j)
         dimension q(300),p(300)
         do i = j2,iu
            pi = q(i)-q(i+jt)-q(i-jt)
            q(i) = q(i)-q(i+jh)-q(i-jh)+q(i+jd)+q(i-jd)
            p(i-j) = pi+q(i)
         end do
      end

      subroutine case_26(q,p,j2,iu,jd,j)
         dimension q(300),p(300)
         do i = j2,iu
            p(i-j) = 2.*q(i)
            q(i) = q(i+jd)+q(i-jd)
         end do
      end

      subroutine case_24(q,p,j2,iu,jh,jd,j)
         dimension q(300),p(300)
         do i = j2,iu
            p(i-j) = 2.*q(i)+q(i+jd)+q(i-jd)
            q(i) = q(i)-q(i+jh)-q(i-jh)
         end do
      end

      subroutine case_20(q,p,j2,iu,jd,j)
         dimension q(300),p(300)
         do i = j2,iu
           p(i-j) = 2.*q(i)+q(i+jd)+q(i-jd)
           q(i) = 0.
         end do
      end

      subroutine update_arrays(g, p, d, temp, c, lo, n, li, m, s, id)
         dimension g(300),p(300),c(300),d(300),temp(300)
         do l = lo, n, li
           a = c(l)
           as = a * s
           do i = 2, m
              p(i) = as * p(i)
              d(i) = a * temp(i)
              g(i) = 2 * a - d(i)
           end do
           g(2) = 0.
           d(m) = 0.
          
           do while (id - m / 2 < 0)
              ii = 2 * id
              io = ii + 1
              do i = io, m, ii
                 a = 1. / (1. - d(i) * g(i + id) - g(i) * d(i - id))
                 p(i) = a * (p(i) + d(i) * p(i + id) + g(i) * p(i - id))
                 d(i) = d(i) * d(i + id) * a
                 g(i) = g(i) * g(i - id) * a
              end do
              id = ii
           end do
        
           do while (id > 1)
              id = ii / 2
              io = id + 1
              do i = io, m, ii
                 p(i) = p(i) + d(i) * p(i + id) + g(i) * p(i - id)
              end do
              ii = id
           end do
         end do
      end subroutine update_arrays



