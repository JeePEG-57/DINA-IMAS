
      subroutine ves_green()

 	include 'double.inc'
	include 'parf1'
	include 'parf2'
	include 'parf4'

	common
     *  /ves2/ncam,rc(mu),zc(mu)
     *  /ves9/tokc,tokc0

	common
     *	/loop1/kloop,rl(nloop),zl(nloop),psloop(nloop)
     *  /loop2/pfgreen(nloop,kf),vesgreen(nloop,mu)
c
	common
     *	/probe1/kprobe,bprobe(nprobe)
     *  /probe2/pfprobe(nprobe,kf),vesprobe(nprobe,mu)

        include 'parf_ves'
	common
     *  /ves_ef_1/ves_loop(nloop,k_ves),ves_probe(nprobe,k_ves)
     *  /ves_ef_2/tok_ves(k_ves)
     *  /ves_ef_3/n_ves
     *  /ves_ef_4/ind_ves(mu)
	common
     *  /ge5/kpr

c   == vessel to loops...

        i_en=i_en+1
        
        if(i_en.gt.1)return

        open(unit=41,file='ves_index.dat',form='formatted')
        read (41,*)
        read (41,*)(ind_ves(k),k=1,ncam)
        close (41)

        open(unit=41,file='tokc.dat',form='formatted')
        read (41,*)
        read (41,*)tokc
        close (41)

        do ii=1,kloop
           kk=0
           DO  k=1,ncam
              if(ind_ves(k).eq.1)then
                 kk=kk+1
                 ves_loop(ii,kk)=vesgreen(ii,k)
              end if
           end do
	end do

c   == vessel to probes...

        kk=0
        DO  k=1,ncam
           if(ind_ves(k).eq.1)then
              kk=kk+1
              do ii=1,kprobe
                 ves_probe(ii,kk)=vesprobe(ii,k)
              end do
           end if
        end do

        n_ves=kk

        if(kpr.eq.1)
     *   print *,' n_ves ncam kloop kprobe==',n_ves,ncam,kloop,kprobe

        return
        end
        subroutine ves_green_fur()
 	include 'double.inc'
        include 'new_com.inc'

        call ves_green_fur_c(
     *  ncam,rc,zc,kloop,kprobe,vesgreen,vesprobe,
     *  ves_vec,n_ves,ves_loop,ves_probe,
     *  r0,z0,pi)

        return
        end

        subroutine ves_green_fur_c(
     *  ncam,rc,zc,kloop,kprobe,vesgreen,vesprobe,
     *  ves_vec,n_ves,ves_loop,ves_probe,
     *  r0,z0,pi)

 	include 'double.inc'
	include 'parf_ves'
	include 'parf0'
	include 'parf1'
	include 'parf2'
	include 'parf4'

        dimension rc(*),zc(*),vesgreen(nloop,*),vesprobe(nprobe,*),
     *  ves_vec(mu,*),
     *  ves_loop(nloop,*),ves_probe(nprobe,*)

        common
     *  /ves9/tokc,tokc0

	character*70 apr

c   == vessel to loops...

        i_en=i_en+1
        
        if(i_en.gt.1)return
        
        open(unit=41,file='tokc.dat',form='formatted')
        read (41,*)
        read (41,*)tokc
        close (41)

        if(kpr.eq.1)print *,' tokc from tokc.dat',tokc

        do i=1,ncam
           dist=sqrt( ( rc(i)-r0)**2+(zc(i)-z0)**2 )
           cos_tet=(rc(i)-r0)/dist
           sin_tet=(zc(i)-z0)/dist
           tet_ves=acos(cos_tet)
           if(sin_tet.lt.0.)tet_ves=2.*pi-tet_ves
           
c          if(kpr.eq.1)print *,' i cos_tet sin_tet tet_ves',i,cos_tet,
c     *  sin_tet,tet_ves

        ves_vec(i,1)=1.

	kk_ves=5

           do k=1,kk_ves
              cos_ves=cos(k*tet_ves)
              ves_vec(i,k+1)=cos_ves

              sin_ves=sin(k*tet_ves)
              ves_vec(i,k+1+kk_ves)=sin_ves
           end do

        end do
c
71	format(20x,a6/,(6(1pe10.3)))
72      format(20x,a6/,(6(i4)))

        n_ves=2*kk_ves+1

	apr='ves_vec'
        do k=1,ncam
c	if(kpr.eq.1)print 71,apr,(ves_vec(k,i),i=1,n_ves)
        end do
        
c        stop


        do ii=1,kloop
        DO  kk=1,n_ves
           ves_loop(ii,kk)=0.
           DO  k=1,ncam
           ves_loop(ii,kk)=ves_loop(ii,kk)+vesgreen(ii,k)*ves_vec(k,kk)
           end do
	end do
	end do

c   == vessel to probes...

        do ii=1,kprobe
        DO  kk=1,n_ves
           ves_probe(ii,kk)=0.
           DO  k=1,ncam
           ves_probe(ii,kk)=ves_probe(ii,kk)+
     *  vesprobe(ii,k)*ves_vec(k,kk)
           end do
	end do
	end do

        if(kpr.eq.1)
     *   print *,' n_ves ncam kloop kprobe==',n_ves,ncam,kloop,kprobe

        return
        end
        subroutine ves_cur_fur()
 	include 'double.inc'
        include 'new_com.inc'

        call ves_cur_fur_c(
     *  ncam,tcam,tokc,ves_vec,tok_ves,n_ves,
     *  mu,k_ves)

        return
        end

        subroutine ves_cur_fur_c(
     *  ncam,tcam,tokc,ves_vec,tok_ves,n_ves,
     *  mu,k_ves)

 	include 'double.inc'
        dimension tcam(*),tok_ves(*),ves_vec(mu,k_ves)

	character*70 apr
c
71	format(20x,a6/,(6(1pe10.3)))
72      format(20x,a6/,(6(i4)))

	apr='tok_ves'
	if(kpr.eq.1)print 71,apr,(tok_ves(i),i=1,n_ves)

c	apr='ves_vec'
c        do k=1,ncam
c	if(kpr.eq.1)print 71,apr,(ves_vec(k,i),i=1,n_ves)
c        end do

        tokc=0.
        do i=1,ncam
           tcam(i)=0.
           do kk=1,n_ves
              tcam(i)=tcam(i)+ves_vec(i,kk)*tok_ves(kk)
           end do
           tokc=tokc+tcam(i)
        end do

        if(kpr.eq.1)print *,' n_ves ncam= tokc',n_ves,ncam,tokc

        return
        end
        subroutine ves_cur_exp()
 	include 'double.inc'
        include 'new_com.inc'

        call ves_cur_exp_c(
     *  ncam,ves_curr,tokc,ves_vec,tok_ves,n_ves,
     *  mu,k_ves)

        return
        end

        subroutine ves_cur_exp_c(
     *  ncam,ves_curr,tokc,ves_vec,tok_ves,n_ves,
     *  mu,k_ves)

 	include 'double.inc'

        dimension ves_curr(*),tok_ves(*),ves_vec(mu,k_ves)

	character*70 apr
c
71	format(20x,a6/,(6(1pe10.3)))
72      format(20x,a6/,(6(i4)))

	apr='tok_ves'
	if(kpr.eq.1)print 71,apr,(tok_ves(i),i=1,n_ves)

        tokc=0.
        do kk=1,n_ves
           ves_curr(kk)=0.
           do i=1,ncam
              ves_curr(kk)=ves_curr(kk)+ves_vec(i,kk)
           end do
           tokc=tokc+ves_curr(kk)*tok_ves(kk)
        end do

        if(kpr.eq.1)print *,' n_ves ncam= ** tokc',n_ves,ncam,tokc

        return
        end




