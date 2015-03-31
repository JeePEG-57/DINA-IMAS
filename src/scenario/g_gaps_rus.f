        subroutine get_gaps()
	  
		call get_gaps_s()
		call get_gaps_b()
		
        call get_gaps_45
        
	  call get_gaps_2x()

        return
        end


        subroutine get_gaps_s()
	include 'double.inc'
        include 'new_com.inc'

        call get_gaps_s_c(rmag,zmag)

        return
        end

        subroutine get_gaps_s_c(
     *  rmag,zmag)

	include 'double.inc'
	include 'parf1'
	include 'parf2'
	include 'parf8'
        common
     *  /ge2/NTAY,TAY,TT
        common
     *  /ge5/kpr

	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nn),y(MM),dx,dy
     *  /eq1g/psi_g(nr,nz)
	common 
     *  /pf1/npf,pf(kf),pf0(kf)
	common 
     *  /dfm5/pt01,pt02
        common
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
	common
     *  /halo2e/next0,li_drop,n_li,n_dif,nmix
c
	dimension xp1(50,mu1),yp1(50,mu1),ind1(50),ind(mu1),
     *  x11(mu1),y11(mu1),xp(mu1),yp(mu1)
c
	common /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
     *  /cont21/n_ga,n_int

        common /sep_points/n_sep,x_sep(mu1),y_sep(mu1)

        common 
     *  /test_p1/x_test(100),y_test(100)

	character*70  apr

c
	dimension pdd(6),znak(2)
c


c!!!        call get_gaps_oo()



c	call graphic(it1,nrad)

!!!            call arc_x_bnd(nt,nbtab,rbtab,zbtab)


	delta0=sqrt(dx**2+dy**2)
c
	do k=1,2
           gaps(k)=1.e5
      end do

c-------

      do k=1,2

c!!!!!!!              if(i0.gt.1.and.k.gt.2)go to 11

              d_min=1.e5
              do j=2,n_sep
                 dist=sqrt( (x_sep(j)-x_gaps(k))**2+
     *                (y_sep(j)-y_gaps(k))**2 )

                 if(dist.le.d_min)then
                    urr=x_sep(j)
                    vrr=y_sep(j)
c  VECTOR CHECK
                    scal=( urr-x_gaps(k))*(rmag-x_gaps(k))
     *                   +(vrr-y_gaps(k))*(zmag-y_gaps(k))

ccc                    if(scal.ge.0.and.k.gt.2)then
                    if(scal.ge.0.or.k.le.2)then
                       d_min=dist
                       j_min=j
                    end if
                 end if
              end do
              gaps(k)=amin1(gaps(k),d_min)
      end do


           if(kpr.eq.1)print *,' i0=== mu1 n_sep',i0,mu1,n_sep

           apr='GAPS 00'
           if(kpr.eq.1)print 71,apr,(gaps(i),i=1,n_ga)

           if(n_sep.ge.mu1)stop

c  Temporarily go to 11
           
c!!!!!!!!!!           go to 11

	k_d=0

      do j=2,n_sep

              x1=x_sep(j-1)
              x2=x_sep(j)
              y1=y_sep(j-1)
              y2=y_sep(j)

              delta=-( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) )

              dist=sqrt( (x2-x1)**2+(y2-y1)**2 )

c	 write(6,'(" j  n_sep  delta dist delta0== ", 2i4,6(1pe12.5))'),
c     *  j,n_sep,delta,dist,delta0

 
              if(abs(dist).gt.2.*delta0)then

	k_d=k_d+1
                if(kpr.eq.-1)
     *          print *,' ntay delta delta0',ntay,delta,2*delta0
                go to 11
               end if

 
              if(abs(dist).lt.0.1)then
			   go to 11
               end if


              
			
		do k=1,2
                 dis_ga=1.e5
                 f1=x_gaps(k)*(x2-x1)+y_gaps(k)*(y2-y1)
                 f2=-y1*(x2-x1)+x1*(y2-y1)

                 urr=(-f1*(x2-x1)-f2*(y2-y1))/delta
                 vrr=( f2*(x2-x1)-f1*(y2-y1))/delta

                 d1=sqrt( (urr-x1)**2+(vrr-y1)**2 )
                 d2=sqrt( (urr-x2)**2+(vrr-y2)**2 )
                 d12=sqrt( (x1-x2)**2+(y1-y2)**2 )
                 d22=d1+d2

c	if(k.le.2)write(6,'(" j   k   d1 d2 d12== ", 2i4,6(1pe12.5))'),
c     *  j,k,d1,d2,d12


         if(abs(d12-d1-d2).lt.1.e-1)then
c  VECTOR CHECK
         scal=( urr-x_gaps(k))*(rmag-x_gaps(k))
     *  +(vrr-y_gaps(k))*(zmag-y_gaps(k))


c	if(k.le.2)write(6,'(" k -------j  scal  ", 2i4,6(1pe12.5))'),
c     *  k,j,scal

ccc         if(scal.ge.0.and.k.gt.2)then


         if(scal.ge.0.and.k.gt.2)then

         dis_ga=sqrt( (urr-x_gaps(k))**2+(vrr-y_gaps(k))**2 )
         if(kpr.eq.-1)
     *   print *,'j k dis_ga gaps',j,k,dis_ga,gaps(k) 

         gaps_k=amin1(gaps(k),dis_ga)
         gaps(k)=amin1(gaps(k),dis_ga)

         if(kpr.eq.-1)
     *   print *,'j k gaps_k gaps',j,k,gaps_k,gaps(k) 

         end if




         if(k.le.2)then
         dis_ga=sqrt( (urr-x_gaps(k))**2+(vrr-y_gaps(k))**2 )
         if(kpr.eq.-1)
     *   print *,'j k dis_ga gaps',j,k,dis_ga,gaps(k) 

	    vecpro = (urr - rmag)*(y_gaps(k) - zmag) -
     *	 (vrr - zmag)*(x_gaps(k) - rmag)
	
	    if(vecpro.lt.0.)s_vecpro=-1.d0
	    if(vecpro.ge.0.)s_vecpro=1.d0

	    if(dis_ga.le.gaps(k))then
	     gaps(k)=dis_ga
		   p=(k-1.5)
	     znak(k)=p/abs(p)*s_vecpro
		end if

         if(kpr.eq.1)
     *   print *,'j k  gaps znak',j,k,gaps(k),znak(k),
     *  x_gaps(k),y_gaps(k) 
         end if

         end if
      end do

 11     continue


      end do


	do i=1,2
		gaps(i)=gaps(i)*znak(i)
	end do



ccc        if(ntay.ge.li_drop)then
        apr='GAPS--'
        if(kpr.eq.1)print 71,apr,(gaps(i),i=1,n_ga)
ccc        end if

        if(kpr.eq.1)print *,'k_d==',k_d


c        read (*,*)
        

 71     format(20x,a70/,(6(1x,1pe10.3)))
	return
	end


        subroutine get_gaps_old()
	include 'double.inc'
        include 'new_com.inc'

        call get_gaps_old_c(rmag,zmag)

        return
        end

        subroutine get_gaps_old_c(
     *  rmag,zmag)

	include 'double.inc'
	include 'parf1'
	include 'parf2'
	include 'parf8'
        common
     *  /ge2/NTAY,TAY,TT
        common
     *  /ge5/kpr

	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nn),y(MM),dx,dy
     *  /eq1g/psi_g(nr,nz)
	common 
     *  /pf1/npf,pf(kf),pf0(kf)
	common 
     *  /dfm5/pt01,pt02
        common
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
	common
     *  /halo2e/next0,li_drop,n_li,n_dif,nmix
c
	dimension xp1(50,mu1),yp1(50,mu1),ind1(50),ind(mu1),
     *  x11(mu1),y11(mu1),xp(mu1),yp(mu1)
c
	common /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
     *  /cont21/n_ga,n_int

        common /sep_points/n_sep,x_sep(mu1),y_sep(mu1)

        common 
     *  /test_p1/x_test(100),y_test(100)

	character*70  apr

c
	dimension pdd(6),znak(2)
c


c!!!        call get_gaps_oo()



c	call graphic(it1,nrad)

!!!            call arc_x_bnd(nt,nbtab,rbtab,zbtab)


	delta0=sqrt(dx**2+dy**2)
c
	do k=1,n_ga
           gaps(k)=1.e5
      end do

c-------

      do k=1,n_ga

c!!!!!!!              if(i0.gt.1.and.k.gt.2)go to 11

              d_min=1.e5
              do j=2,n_sep
                 dist=sqrt( (x_sep(j)-x_gaps(k))**2+
     *                (y_sep(j)-y_gaps(k))**2 )

                 if(dist.le.d_min)then
                    urr=x_sep(j)
                    vrr=y_sep(j)
c  VECTOR CHECK
                    scal=( urr-x_gaps(k))*(rmag-x_gaps(k))
     *                   +(vrr-y_gaps(k))*(zmag-y_gaps(k))

ccc                    if(scal.ge.0.and.k.gt.2)then
                    if(scal.ge.0.or.k.le.2)then
                       d_min=dist
                       j_min=j
                    end if
                 end if
              end do
              gaps(k)=amin1(gaps(k),d_min)
      end do


           if(kpr.eq.1)print *,' i0=== mu1 n_sep',i0,mu1,n_sep

           apr='GAPS 00'
           if(kpr.eq.1)print 71,apr,(gaps(i),i=1,n_ga)

           if(n_sep.ge.mu1)stop

c  Temporarily go to 11
           
c!!!!!!!!!!           go to 11

	k_d=0

      do j=2,n_sep

              x1=x_sep(j-1)
              x2=x_sep(j)
              y1=y_sep(j-1)
              y2=y_sep(j)

              delta=-( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) )

              dist=sqrt( (x2-x1)**2+(y2-y1)**2 )

c	 write(6,'(" j  n_sep  delta dist delta0== ", 2i4,6(1pe12.5))'),
c     *  j,n_sep,delta,dist,delta0

 
              if(abs(dist).gt.2.*delta0)then

	k_d=k_d+1
                if(kpr.eq.-1)
     *          print *,' ntay delta delta0',ntay,delta,2*delta0
                go to 11
               end if

 
              if(abs(dist).lt.0.1)then
			   go to 11
               end if


              
			
		do k=1,n_ga
                 dis_ga=1.e5
                 f1=x_gaps(k)*(x2-x1)+y_gaps(k)*(y2-y1)
                 f2=-y1*(x2-x1)+x1*(y2-y1)

                 urr=(-f1*(x2-x1)-f2*(y2-y1))/delta
                 vrr=( f2*(x2-x1)-f1*(y2-y1))/delta

                 d1=sqrt( (urr-x1)**2+(vrr-y1)**2 )
                 d2=sqrt( (urr-x2)**2+(vrr-y2)**2 )
                 d12=sqrt( (x1-x2)**2+(y1-y2)**2 )
                 d22=d1+d2

c	if(k.le.2)write(6,'(" j   k   d1 d2 d12== ", 2i4,6(1pe12.5))'),
c     *  j,k,d1,d2,d12


         if(abs(d12-d1-d2).lt.1.e-1)then
c  VECTOR CHECK
         scal=( urr-x_gaps(k))*(rmag-x_gaps(k))
     *  +(vrr-y_gaps(k))*(zmag-y_gaps(k))


c	if(k.le.2)write(6,'(" k -------j  scal  ", 2i4,6(1pe12.5))'),
c     *  k,j,scal

ccc         if(scal.ge.0.and.k.gt.2)then


         if(scal.ge.0.and.k.gt.2)then

         dis_ga=sqrt( (urr-x_gaps(k))**2+(vrr-y_gaps(k))**2 )
         if(kpr.eq.-1)
     *   print *,'j k dis_ga gaps',j,k,dis_ga,gaps(k) 

         gaps_k=amin1(gaps(k),dis_ga)
         gaps(k)=amin1(gaps(k),dis_ga)

         if(kpr.eq.-1)
     *   print *,'j k gaps_k gaps',j,k,gaps_k,gaps(k) 

         end if




         if(k.le.2)then
         dis_ga=sqrt( (urr-x_gaps(k))**2+(vrr-y_gaps(k))**2 )
         if(kpr.eq.-1)
     *   print *,'j k dis_ga gaps',j,k,dis_ga,gaps(k) 

	    vecpro = (urr - rmag)*(y_gaps(k) - zmag) -
     *	 (vrr - zmag)*(x_gaps(k) - rmag)
	
	    if(vecpro.lt.0.)s_vecpro=-1.d0
	    if(vecpro.ge.0.)s_vecpro=1.d0

	    if(dis_ga.le.gaps(k))then
	     gaps(k)=dis_ga
		   p=(k-1.5)
	     znak(k)=p/abs(p)*s_vecpro
		end if

         if(kpr.eq.1)
     *   print *,'j k  gaps znak',j,k,gaps(k),znak(k),
     *  x_gaps(k),y_gaps(k) 
         end if

         end if
      end do

 11     continue


      end do


	do i=1,2
		gaps(i)=gaps(i)*znak(i)
	end do



ccc        if(ntay.ge.li_drop)then
        apr='GAPS--'
        if(kpr.eq.1)print 71,apr,(gaps(i),i=1,n_ga)
ccc        end if

        if(kpr.eq.1)print *,'k_d==',k_d


c        read (*,*)
        

 71     format(20x,a70/,(6(1x,1pe10.3)))
	return
	end

        subroutine get_gaps_45()
	include 'double.inc'
        include 'new_com.inc'

        call get_gaps_45_c(rmag,zmag)

        return
        end

        subroutine get_gaps_45_c(
     *  rmag,zmag)

	include 'double.inc'
	include 'parf1'
	include 'parf2'
	include 'parf8'
        common
     *  /ge2/NTAY,TAY,TT
        common
     *  /ge5/kpr

	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nn),y(MM),dx,dy
     *  /eq1g/psi_g(nr,nz)
	common 
     *  /pf1/npf,pf(kf),pf0(kf)
	common 
     *  /dfm5/pt01,pt02
        common
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
	common
     *  /halo2e/next0,li_drop,n_li,n_dif,nmix
c
	dimension xp1(50,mu1),yp1(50,mu1),ind1(50),ind(mu1),
     *  x11(mu1),y11(mu1),xp(mu1),yp(mu1)
c
	common /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
     *  /cont21/n_ga,n_int

        common /sep_points/n_sep,x_sep(mu1),y_sep(mu1)

        common 
     *  /test_p1/x_test(100),y_test(100)

	character*70  apr

c
	dimension pdd(6),znak(2)
c


c!!!        call get_gaps_oo()



c	call graphic(it1,nrad)

!!!            call arc_x_bnd(nt,nbtab,rbtab,zbtab)


	delta0=sqrt(dx**2+dy**2)
c
	do k=4,5
           gaps(k)=1.e5
      end do
c-------

      do k=4,5

c!!!!!!!              if(i0.gt.1.and.k.gt.2)go to 11

              d_min=1.e5
              do j=2,n_sep
                 dist=sqrt( (x_sep(j)-x_gaps(k))**2+
     *                (y_sep(j)-y_gaps(k))**2 )

                 if(dist.le.d_min)then
                    urr=x_sep(j)
                    vrr=y_sep(j)
c  VECTOR CHECK
                    scal=( urr-x_gaps(k))*(rmag-x_gaps(k))
     *                   +(vrr-y_gaps(k))*(zmag-y_gaps(k))

ccc                    if(scal.ge.0.and.k.gt.2)then
                    if(scal.ge.0.or.k.le.2)then
                       d_min=dist
                       j_min=j
                    end if
                 end if
              end do
              gaps(k)=amin1(gaps(k),d_min)
      end do


           if(kpr.eq.1)print *,' i0=== mu1 n_sep',i0,mu1,n_sep

           apr='GAPS 045'
           if(kpr.eq.1)print 71,apr,(gaps(i),i=1,n_ga)

           if(n_sep.ge.mu1)stop

c  Temporarily go to 11
           
c!!!!!!!!!!           go to 11

	k_d=0

      do j=2,n_sep

              x1=x_sep(j-1)
              x2=x_sep(j)
              y1=y_sep(j-1)
              y2=y_sep(j)

              delta=-( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) )

              dist=sqrt( (x2-x1)**2+(y2-y1)**2 )

c	 write(6,'(" j  n_sep  delta dist delta0== ", 2i4,6(1pe12.5))'),
c     *  j,n_sep,delta,dist,delta0

 
              if(abs(dist).gt.2.*delta0)then

	k_d=k_d+1
                if(kpr.eq.-1)
     *          print *,' ntay delta delta0',ntay,delta,2*delta0
                go to 11
               end if

 
              if(abs(dist).lt.0.1)then
			   go to 11
               end if


              
			
		do k=4,5
                 dis_ga=1.e5
                 f1=x_gaps(k)*(x2-x1)+y_gaps(k)*(y2-y1)
                 f2=-y1*(x2-x1)+x1*(y2-y1)

                 urr=(-f1*(x2-x1)-f2*(y2-y1))/delta
                 vrr=( f2*(x2-x1)-f1*(y2-y1))/delta

                 d1=sqrt( (urr-x1)**2+(vrr-y1)**2 )
                 d2=sqrt( (urr-x2)**2+(vrr-y2)**2 )
                 d12=sqrt( (x1-x2)**2+(y1-y2)**2 )
                 d22=d1+d2

c	if(k.le.2)write(6,'(" j   k   d1 d2 d12== ", 2i4,6(1pe12.5))'),
c     *  j,k,d1,d2,d12


         if(abs(d12-d1-d2).lt.1.e-1)then
c  VECTOR CHECK
         scal=( urr-x_gaps(k))*(rmag-x_gaps(k))
     *  +(vrr-y_gaps(k))*(zmag-y_gaps(k))


c	if(k.le.2)write(6,'(" k -------j  scal  ", 2i4,6(1pe12.5))'),
c     *  k,j,scal

ccc         if(scal.ge.0.and.k.gt.2)then


         if(scal.ge.0.and.k.gt.2)then

         dis_ga=sqrt( (urr-x_gaps(k))**2+(vrr-y_gaps(k))**2 )
         if(kpr.eq.-1)
     *   print *,'j k dis_ga gaps',j,k,dis_ga,gaps(k) 

         gaps_k=amin1(gaps(k),dis_ga)
         gaps(k)=amin1(gaps(k),dis_ga)

         if(kpr.eq.-1)
     *   print *,'j k gaps_k gaps',j,k,gaps_k,gaps(k) 

         end if




         if(k.le.2)then
         dis_ga=sqrt( (urr-x_gaps(k))**2+(vrr-y_gaps(k))**2 )
         if(kpr.eq.-1)
     *   print *,'j k dis_ga gaps',j,k,dis_ga,gaps(k) 

	    vecpro = (urr - rmag)*(y_gaps(k) - zmag) -
     *	 (vrr - zmag)*(x_gaps(k) - rmag)
	
	    if(vecpro.lt.0.)s_vecpro=-1.d0
	    if(vecpro.ge.0.)s_vecpro=1.d0

	    if(dis_ga.le.gaps(k))then
	     gaps(k)=dis_ga
		   p=(k-1.5)
	     znak(k)=p/abs(p)*s_vecpro
		end if

         if(kpr.eq.1)
     *   print *,'j k  gaps znak',j,k,gaps(k),znak(k),
     *  x_gaps(k),y_gaps(k) 
         end if

         end if
      end do

 11     continue


      end do



ccc        if(ntay.ge.li_drop)then
        apr='GAPS-45-'
        if(kpr.eq.1)print 71,apr,(gaps(i),i=1,n_ga)
ccc        end if

        if(kpr.eq.1)print *,'k_d==',k_d

c        read (*,*)
        

 71     format(20x,a70/,(6(1x,1pe10.3)))
	return
	end



       subroutine get_gaps_b()
	include 'double.inc'
        include 'new_com.inc'

        call get_gaps_b_c(rmag,zmag,uk,vk,m)

        return
        end

        subroutine get_gaps_b_c(
     *  rmag,zmag,uk,vk,m)

	include 'double.inc'
	include 'parf1'
	include 'parf2'
	include 'parf8'
        common
     *  /ge2/NTAY,TAY,TT
        common
     *  /ge5/kpr

	common
     *  /eq1/psi(nr,nz),pspl(nwnh),x(nn),y(MM),dx,dy
     *  /eq1g/psi_g(nr,nz)
	common 
     *  /pf1/npf,pf(kf),pf0(kf)
	common 
     *  /dfm5/pt01,pt02
        common
     *	/fluxc6/pmag,pbound,psep,p_s,delaval,dr_h
	common
     *  /halo2e/next0,li_drop,n_li,n_dif,nmix
c
	dimension xp1(50,mu1),yp1(50,mu1),ind1(50),ind(mu1),
     *  x11(mu1),y11(mu1),xp(mu1),yp(mu1)
c
	common /cont20/x_gaps(kf_c),y_gaps(kf_c),gaps(kf_c),n_gaps
     *  /cont21/n_ga,n_int


        dimension x_sep(300),y_sep(300)

        common 
     *  /test_p1/x_test(100),y_test(100)

	character*70  apr

c
	dimension pdd(6),znak(2),uk(*),vk(*)
c

	n_sep=m
      do j=1,n_sep
	x_sep(j)=uk(j)
	y_sep(j)=vk(j)
	end do

 

c!!!        call get_gaps_oo()



c	call graphic(it1,nrad)

!!!            call arc_x_bnd(nt,nbtab,rbtab,zbtab)


	delta0=sqrt(dx**2+dy**2)
c
	do k=3,n_ga
           gaps(k)=1.e5
      end do

c-------

      do k=3,n_ga

c!!!!!!!              if(i0.gt.1.and.k.gt.2)go to 11

              d_min=1.e5
              do j=2,n_sep
                 dist=sqrt( (x_sep(j)-x_gaps(k))**2+
     *                (y_sep(j)-y_gaps(k))**2 )

                 if(dist.le.d_min)then
                    urr=x_sep(j)
                    vrr=y_sep(j)
c  VECTOR CHECK
                    scal=( urr-x_gaps(k))*(rmag-x_gaps(k))
     *                   +(vrr-y_gaps(k))*(zmag-y_gaps(k))

ccc                    if(scal.ge.0.and.k.gt.2)then
                    if(scal.ge.0.or.k.le.2)then
                       d_min=dist
                       j_min=j
                    end if
                 end if
              end do
              gaps(k)=amin1(gaps(k),d_min)
      end do


           if(kpr.eq.1)print *,' i0=== mu1 n_sep',i0,mu1,n_sep

           apr='GAPS 00'
           if(kpr.eq.1)print 71,apr,(gaps(i),i=1,n_ga)

           if(n_sep.ge.mu1)stop

c  Temporarily go to 11
           
c!!!!!!!!!!           go to 11

	k_d=0

      do j=2,n_sep

              x1=x_sep(j-1)
              x2=x_sep(j)
              y1=y_sep(j-1)
              y2=y_sep(j)

              delta=-( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) )

              dist=sqrt( (x2-x1)**2+(y2-y1)**2 )

c	 write(6,'(" j  n_sep  delta dist delta0== ", 2i4,6(1pe12.5))'),
c     *  j,n_sep,delta,dist,delta0

 
              if(abs(dist).gt.2.*delta0)then

	k_d=k_d+1
                if(kpr.eq.-1)
     *          print *,' ntay delta delta0',ntay,delta,2*delta0
                go to 11
               end if

 
              if(abs(dist).lt.0.1)then
			   go to 11
               end if


              
			
		do k=3,n_ga
                 dis_ga=1.e5
                 f1=x_gaps(k)*(x2-x1)+y_gaps(k)*(y2-y1)
                 f2=-y1*(x2-x1)+x1*(y2-y1)

                 urr=(-f1*(x2-x1)-f2*(y2-y1))/delta
                 vrr=( f2*(x2-x1)-f1*(y2-y1))/delta

                 d1=sqrt( (urr-x1)**2+(vrr-y1)**2 )
                 d2=sqrt( (urr-x2)**2+(vrr-y2)**2 )
                 d12=sqrt( (x1-x2)**2+(y1-y2)**2 )
                 d22=d1+d2

c	if(k.le.2)write(6,'(" j   k   d1 d2 d12== ", 2i4,6(1pe12.5))'),
c     *  j,k,d1,d2,d12


         if(abs(d12-d1-d2).lt.1.e-1)then
c  VECTOR CHECK
         scal=( urr-x_gaps(k))*(rmag-x_gaps(k))
     *  +(vrr-y_gaps(k))*(zmag-y_gaps(k))


c	if(k.le.2)write(6,'(" k -------j  scal  ", 2i4,6(1pe12.5))'),
c     *  k,j,scal

ccc         if(scal.ge.0.and.k.gt.2)then


         if(scal.ge.0.and.k.gt.2)then

         dis_ga=sqrt( (urr-x_gaps(k))**2+(vrr-y_gaps(k))**2 )
         if(kpr.eq.-1)
     *   print *,'j k dis_ga gaps',j,k,dis_ga,gaps(k) 

         gaps_k=amin1(gaps(k),dis_ga)
         gaps(k)=amin1(gaps(k),dis_ga)

         if(kpr.eq.-1)
     *   print *,'j k gaps_k gaps',j,k,gaps_k,gaps(k) 

         end if




         if(k.le.2)then
         dis_ga=sqrt( (urr-x_gaps(k))**2+(vrr-y_gaps(k))**2 )
         if(kpr.eq.-1)
     *   print *,'j k dis_ga gaps',j,k,dis_ga,gaps(k) 

	    vecpro = (urr - rmag)*(y_gaps(k) - zmag) -
     *	 (vrr - zmag)*(x_gaps(k) - rmag)
	
	    if(vecpro.lt.0.)s_vecpro=-1.d0
	    if(vecpro.ge.0.)s_vecpro=1.d0

	    if(dis_ga.le.gaps(k))then
	     gaps(k)=dis_ga
		   p=(k-1.5)
	     znak(k)=p/abs(p)*s_vecpro
		end if

         if(kpr.eq.1)
     *   print *,'j k  gaps znak',j,k,gaps(k),znak(k),
     *  x_gaps(k),y_gaps(k) 
         end if

         end if
      end do

 11     continue


      end do


	do i=1,2
c		gaps(i)=gaps(i)*znak(i)
	end do



ccc        if(ntay.ge.li_drop)then
        apr='GAPS--'
        if(kpr.eq.1)print 71,apr,(gaps(i),i=1,n_ga)
ccc        end if

        if(kpr.eq.1)print *,'k_d==',k_d


c        read (*,*)
        

 71     format(20x,a70/,(6(1x,1pe10.3)))
	return
	end




        subroutine get_gaps_2x()
	include 'double.inc'
        include 'new_com.inc'

        call get_gaps_2x_c(
     *  rmag,zmag,kpr,
     *  n_sep,x_sep,y_sep,
     *  n_sep2,x_sep2,y_sep2,
     *  n_ga,gaps,rsep,zsep,rsep2,zsep2)

        return
        end

        subroutine get_gaps_2x_c(
     *  rmag,zmag,kpr,
     *  n_sep,x_sep,y_sep,
     *  n_sep2,x_sep2,y_sep2,
     *  n_ga,gaps,rsep,zsep,rsep2,zsep2)

	include 'double.inc'
	character*70  apr
	dimension x_sep(*),y_sep(*)
	dimension x_sep2(*),y_sep2(*)
	dimension gaps(*)

      common
     *  /c_ge5/ksepa 



      if(n_sep2.eq.0)then
      d_min2=0.d0
	gaps(n_ga+1)=d_min2

           apr='GAPS 22222'
           if(kpr.eq.1)print 71,apr,(gaps(i),i=1,n_ga+1)
           
      return
      end if
      
      

      if(kpr.eq.1)print *,' rsep zsep rsep2 zsep2 ',
     * rsep,zsep,rsep2,zsep2
     
      if(kpr.eq.1)print *,' rmag zmag',rmag,zmag
      if(kpr.eq.1)print *,' n_sep n_sep2 ksepa',n_sep,n_sep2,ksepa

      d_min=1.e5
      do j=1,n_sep

      dist=sqrt( (y_sep(j)-zmag)**2 )

c      if(kpr.eq.1)print *,' dist x_sep rmag ',dist,x_sep(j),rmag

	if(dist.le.d_min.and.x_sep(j).gt.rmag)then
	         d_min=dist
               urr=x_sep(j)
               vrr=y_sep(j)
	end if
		
      end do


      if(kpr.eq.1)print *,' d_min urr vrr',d_min,urr,vrr

      d_min2=1.e5
      do j=1,n_sep2

      dist=sqrt(  (x_sep2(j)-urr)**2+(y_sep2(j)-vrr)**2 )

c      if(kpr.eq.1)print *,' dist d_min2 y_sep2 vrr ',
c     *  dist,d_min2,y_sep2(j),vrr

	if(dist.le.d_min2)then
	         d_min2=dist
               urr2=x_sep2(j)
               vrr2=y_sep2(j)
	end if
		
      end do

      if(zsep.gt.0.d0)then
      d_min2=-d_min2
      end if
      
      if(kpr.eq.1)print *,' d_min2 urr2 vrr2',d_min2,urr2,vrr2

      if(ksepa.ne.1)then
      d_min2=0.d0
      end if
      
      if(kpr.eq.1)print *,' d_min2 urr2 vrr2',d_min2,urr2,vrr2


	gaps(n_ga+1)=d_min2

           apr='GAPS 22222'
           if(kpr.eq.1)print 71,apr,(gaps(i),i=1,n_ga+1)
c           read(*,*)

 71     format(20x,a70/,(6(1x,1pe10.3)))
	return
	end













