	subroutine shape(tt,rmag_p,p_p,el_p,tpl_p,bt0_p,eu_p,z_p)
	include 'double.inc'
c
c-------
	parameter (ntime=10)
c------
        common
     *  /ge5/kpr

	dimension t_p(ntime),rmag_t(ntime),p_t(ntime),
     *  el_t(ntime),tpl_t(ntime),bt0_t(ntime),eu_t(ntime),
     *  z_t(ntime)

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
	 open (unit=41,file='t_gen',form='formatted')
	 read (41,*)
	 read (41,*)n_t
	 read (41,*)
	 read (41,*)(t_p(i),i=1,n_t)
c
	 read (41,*)
	 read (41,*)(rmag_t(i),i=1,n_t)
	 read (41,*)
	 read (41,*)(p_t(i),i=1,n_t)
	 read (41,*)
	 read (41,*)(el_t(i),i=1,n_t)
	 read (41,*)
	 read (41,*)(tpl_t(i),i=1,n_t)
	 read (41,*)
	 read (41,*)(bt0_t(i),i=1,n_t)
	 read (41,*)
	 read (41,*)(eu_t(i),i=1,n_t)
	 read (41,*)
	 read (41,*)(z_t(i),i=1,n_t)
c
	 close (unit=41)
	 end if

      do i=2,n_t
      if( (tt-t_p(i-1))*(tt-t_p(i)).le.0.)then
c==================
	 t_coef=(tt-t_p(i-1))/( t_p(i)-t_p(i-1) )
c=================
c 9) ---- rmag_p ----
	 rmag_p=rmag_t(i-1)+t_coef*(rmag_t(i)-rmag_t(i-1))
c
c 10) ---- p_p ----
	 p_p=p_t(i-1)+t_coef*(p_t(i)-p_t(i-1))
c
c 11) ---- el_p ----
	 el_p=el_t(i-1)+t_coef*(el_t(i)-el_t(i-1))
c 11) ---- tpl_p ----
	 tpl_p=tpl_t(i-1)+t_coef*(tpl_t(i)-tpl_t(i-1))
c 11) ---- bt0_p ----
	 bt0_p=bt0_t(i-1)+t_coef*(bt0_t(i)-bt0_t(i-1))
c 11) ---- eu_p ----
	 eu_p=eu_t(i-1)+t_coef*(eu_t(i)-eu_t(i-1))
c 11) ---- z_p ----
	 z_p=z_t(i-1)+t_coef*(z_t(i)-z_t(i-1))
c
	 end if
	 end do
	 
c	 if(kpr.eq.1)print *,'FROM SHAPE  z_p rmag_p ',z_p,rmag_p

      return
      end
c






	subroutine read_fwt()
	include 'double.inc'
	include 'new_com.inc'

	call read_fwt_c(
     *  kloop,kprobe,
     *  fwtp,fwtb)
	
	return
	end

	subroutine read_fwt_c(
     *  kloop,kprobe,
     *  fwtp,fwtb)

	include 'double.inc'
        dimension fwtp(*),fwtb(*)

	character*12 apr
	character*110 tmp,fshot


c---
	i_sh=i_sh+1
	if(i_sh.eq.1)then

     	open(unit=2,file='fwt.fl',status='old',form='formatted')
	read (2,*)
	read (2,74)tmp
	if(kpr.eq.1)print *,tmp
	close (2)
c---
	open (unit=41,file=tmp,form='formatted')
	read (41,*)
	read (41,*)(fwtp(i),i=1,kloop)
	read (41,*)
	read (41,*)(fwtb(i),i=1,kprobe)
	close (41)

74	format(a110)

        end if

	apr='fwtp'
	if(kpr.eq.1)print 71,apr,(fwtp(i),i=1,kloop)
	apr='fwtb'
	if(kpr.eq.1)print 71,apr,(fwtb(i),i=1,kprobe)


71	format(5x,a10/,(1X,6(1pe11.3)))
5000	format(4(1x,1pe14.7))

	return
	end






	subroutine read_fwt_coef()
	include 'double.inc'
	include 'new_com.inc'

	call read_fwt_coef_c(
     *  kloop,kprobe,time_dis,
     *  alf_loop,alf_probe)
	
	return
	end

	subroutine read_fwt_coef_c(
     *  kloop,kprobe,time_dis,
     *  alf_loop,alf_probe)

	include 'double.inc'
        dimension alf_loop(*),alf_probe(*)

	character*12 apr
	character*110 tmp,fshot


c---
	i_sh=i_sh+1
	if(i_sh.eq.1)then

     	open(unit=2,file='fwt_coef.fl',status='old',form='formatted')
	read (2,*)
	read (2,74)tmp
	if(kpr.eq.1)print *,tmp
	close (2)
c---

	open (unit=41,file=tmp,form='formatted')


	read (41,*)
	read (41,*)time_dis

	if(kpr.eq.1)print *,' time_dis==',time_dis

	read (41,*)
	read (41,*)(alf_loop(i),i=1,kloop)
	read (41,*)
	read (41,*)(alf_probe(i),i=1,kprobe)
	close (41)

74	format(a110)

        end if

	apr='alf_loop'
	if(kpr.eq.1)print 71,apr,(alf_loop(i),i=1,kloop)
	apr='alf_probe'
	if(kpr.eq.1)print 71,apr,(alf_probe(i),i=1,kprobe)


71	format(5x,a10/,(1X,6(1pe11.3)))
5000	format(4(1x,1pe14.7))

	return
	end




	subroutine fwt_coef()
	include 'double.inc'
	include 'new_com.inc'

	call fwt_coef_c(
     *  kloop,kprobe,time_dis,tt,
     *  psloop,bprobe,
     *  alf_loop,alf_probe)
	
	return
	end

	subroutine fwt_coef_c(
     *  kloop,kprobe,time_dis,tt,
     *  psloop,bprobe,
     *  alf_loop,alf_probe)

	include 'double.inc'
        dimension alf_loop(*),alf_probe(*),
     *  psloop(*),bprobe(*)

	character*12 apr
	character*110 tmp,fshot


c	if(kpr.eq.1)print *,' tt time_dis==',tt,time_dis

	if(tt.gt.time_dis)then

	do i=1,kloop
	psloop(i)=psloop(i)*alf_loop(i)

c	if(kpr.eq.1)print *,' alf_loop psloop',alf_loop(i),psloop(i)
	end do

	do i=1,kprobe
	bprobe(i)=bprobe(i)*alf_probe(i)
	end do

	end if



71	format(5x,a10/,(1X,6(1pe11.3)))
5000	format(4(1x,1pe14.7))

	return
	end



	
	
	subroutine wr_tabppf()
	include 'double.inc'
	include 'new_com.inc'

         call wr_tabppf_c(
     *   rs0,
     *   n,ppx,pffx,
     *   pi,kpr,tt)

         return
         end

         subroutine wr_tabppf_c(
     *   rs0,
     *   nutab,pptab,fptab,
     *   pi,kpr,tt)

	include 'double.inc'
c	 implicit real *8 (a-h,o-z)

         dimension pptab(*),fptab(*)

	character *20 apr

71	FORMAT(5X,A10/,(2x,6(1PE11.3)))

	i_en=i_en+1
	if(i_en.eq.1)then
	ntime=9999
      open (unit=43,file='tabppf2.txt',form='formatted')
	else
      open (unit=43,file='tabppf2.txt',access='append',
     * form='formatted')
	end if


5000    format (6(1pe14.6))

        write (43,*)nutab,tt,tpl,i_en
        write (43,5000)(pptab(i),i=1,nutab)
        write (43,5000)(fptab(i),i=1,nutab)

	close(43)

	if(kpr.eq.1)print *,' tt tabppf2.txt is written',tt

	return
	end




	subroutine prof_in()
	include 'double.inc'
      include 'new_com.inc'

	call prof_in_c(tt,tpl1,n,ppx,pffx)

	return
	end

	subroutine prof_in_c(tt,tpl,n,ppx,pffx)
	include 'double.inc'

	dimension ppx(*),pffx(*)


 	include 'parf0' 
 	include 'parf_mike' 

	dimension t_t(ntime),tpl_t(ntime),
     *  ppx_t(npo,ntime),pffx_t(npo,ntime)

	character *12 apr


	i_sh=i_sh+1

	if(i_sh.eq.1)then

c-------------------------------
           open (unit=41,file='prof_curr.dat',form='formatted') 

	k=0
      do i=1,99999
	k=k+1
	        read (41,*,err=2000,end=2000)n,t_t(i),tpl_t(i)
              read (41,*,err=2000,end=2000)(ppx_t(iprof,i),iprof=1,n)
              read (41,*,err=2000,end=2000)(pffx_t(iprof,i),iprof=1,n)
              
              nprof=n
              
         end do

2000	continue

	n_t=k-1

      close (unit=41) 

       n_t=n_t+1
      
       i=n_t
       
       if(i.gt.ntime)then
             if(kpr.eq.1)print *,' i gt ntime',i,ntime
       stop
       end if
       
       
       
	 t_t(i)=t_t(i-1)+1.d5
	 
	 tpl_t(i)=tpl_t(i-1)
	 
	 do k=1,npf
	    ppx_t(k,i)=ppx_t(k,i-1)
	    pffx_t(k,i)=pffx_t(k,i-1)
	 end do



      end if

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))


      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 tpl=tpl_t(i-1)+t_coef*(tpl_t(i)-tpl_t(i-1))
	 
	 i_kk=i

	do iprof=1,nprof

	 ppx(iprof)=ppx_t(iprof,i-1)+t_coef*(ppx_t(iprof,i)-
     *  ppx_t(iprof,i-1))

	 pffx(iprof)=pffx_t(iprof,i-1)+t_coef*(pffx_t(iprof,i)-
     *  pffx_t(iprof,i-1))

	end do

c
	 end if

	 end do

c--------------

	if(kpr.eq.1)print *,' FROM prof_curr.dat ='

	if(kpr.eq.1)print *,' tt t_t ==',tt,t_t(n_t)
	if(kpr.eq.1)print *,' n_t i_kk=',n_t,i_kk

      apr='++ppx-' 
      if(kpr.eq.1)print 71,apr,(ppx(i),i=1,n) 

      apr='++pffx-' 
      if(kpr.eq.1)print 71,apr,(pffx(i),i=1,n) 



c----------------

5001    format(4i4)
5000    format (6(1pe14.6e3))

	return
	end

   	subroutine shape_pf() 
	include 'double.inc'
 	include 'parf1' 
 	parameter ( NPFC=KF-4) 

 	include 'parf_mike' 

c 	parameter (ntime=20)
 
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ge2/ntay,tay,tt
     *  /ge5/kpr

	dimension t_t(ntime),pf_t(kf,ntime)

	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='fc.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 

           if(kpr.eq.1)print *,' n_t==',n_t
 
           read (41,*) 

	k=0
      do i=1,99999
	k=k+1
              read (41,*,err=2000,end=2000)t_t(i),(pf_t(kk,i),kk=1,npf)
!              if(kpr.eq.1)print *,' k t==',k,t_t(i)
	   n_t=k
         end do

2000	continue

       close (unit=41) 


       n_t=n_t+1
      
       i=n_t

       if(i.gt.ntime)then
             if(kpr.eq.1)print *,' i gt ntime',i,ntime
       stop
       end if
       
	 t_t(i)=t_t(i-1)+1.d5

	 do k=1,npf
	    pf_t(k,i)=pf_t(k,i-1)
	 end do

c


           apr='-t_t-' 
          if(kpr.eq.-1)print 71,apr,(t_t(i),i=1,n_t) 

           apr='-pf_t1-'
           kk=1 
           if(kpr.eq.-1)print 71,apr,(pf_t(kk,i),i=1,n_t) 
           apr='-pf_t2-'
           kk=2 
           if(kpr.eq.-1)print 71,apr,(pf_t(kk,i),i=1,n_t) 

    !  stop
      
       end if

	   if(kpr.eq.1)print *,' tt npf n_t===',tt,npf,n_t



71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

       i_coef=0

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )
	 
	 do k=1,npf
	    pf(k)=pf_t(k,i-1)+t_coef*(pf_t(k,i)-pf_t(k,i-1))
	 end do

       i_coef=i
c
	 end if

	 end do

	if(kpr.eq.1)print *,' from shape_pf i_coef',i_coef
	apr='PF'
      if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf) 

       return 
       end 



   	subroutine wr_pf() 
	include 'double.inc'
 	include 'parf1' 
 
	common
     *  /pf1/npf,pf(kf),pf0(kf)
	common
     *  /ge2/ntay,tay,tt
     *  /ge5/kpr

	character *12 apr

	i_sh=i_sh+1
	if(i_sh.eq.1)then
       open (unit=41,file='fc.txt',form='formatted') 
       write(41,*)'n_t' 
       write(41,*)i_sh 

       if(kpr.eq.1)print *,' tt npf n_t===',tt,npf,n_t
 
       write(41,*)'PF(i),i=1,npf'
       else
       open (unit=41,file='fc.txt',form='formatted',access='append') 
       end if
       write(41,5000)tt,(pf(k),k=1,npf)

       close (unit=41) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

5000    format (16(1p,1e16.7e3))

	if(kpr.eq.1)print *,' from write_pf',pf(1),pf(8)

       return 
       end 
	subroutine shape_tcam()
	include 'double.inc'
	include 'new_com.inc'

	call shape_tcam_c(
     *  tt,ncam,tcam,tpl,kpr)
	
	return
	end

	subroutine shape_tcam_c(
     *  tt,ncam,tcam,tpl,kpr)

	include 'double.inc'
 	include 'parf_mike' 
 	include 'parf1' 
	dimension t_t(ntime),tcam_t(mu,ntime),tpl_t(ntime)

      dimension tcam(*)

	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then
c-------
           open (unit=41,file='tcam2.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 

           if(kpr.eq.1)print *,' n_t==',n_t
 
           read (41,*) 

	k=0
      do i=1,99999
	k=k+1
      read (41,*,err=2000,end=2000)t_t(i),tpl_t(i),
     *  (tcam_t(kk,i),kk=1,ncam)
!              if(kpr.eq.1)print *,' k t==',k,t_t(i)
	   n_t=k
         end do

2000	continue

       close (unit=41) 


       n_t=n_t+1
      
       i=n_t

       if(i.gt.ntime)then
             if(kpr.eq.1)print *,' i gt ntime',i,ntime
       stop
       end if
       
	 t_t(i)=t_t(i-1)+1.d5

	 do k=1,ncam
	    tcam_t(k,i)=tcam_t(k,i-1)
	 end do

c


           apr='-t_t-' 
          if(kpr.eq.-1)print 71,apr,(t_t(i),i=1,n_t) 

           apr='-pf_t1-'
           kk=1 
           if(kpr.eq.-1)print 71,apr,(tcam_t(kk,i),i=1,n_t) 
           apr='-pf_t2-'
           kk=2 
           if(kpr.eq.-1)print 71,apr,(tcam_t(kk,i),i=1,n_t) 

    !  stop
      
       end if

	   if(kpr.eq.1)print *,' tt ncam n_t===',tt,ncam,n_t



71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      i_coef=0
      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )
	 
	    tpl=tpl_t(i-1)+t_coef*(tpl_t(i)-tpl_t(i-1))

	 do k=1,ncam
	    tcam(k)=tcam_t(k,i-1)+t_coef*(tcam_t(k,i)-tcam_t(k,i-1))
	 end do
	 
	 i_coef=i

c
	 end if

	 end do

	if(kpr.eq.1)print *,' from shape_tcam  tpl i_coef',tpl,i_coef
	apr='tcam'
      if(kpr.eq.1)print 71,apr,(tcam(i),i=1,ncam) 


	return
	end


   	subroutine wr_tcam() 
	include 'double.inc'
	include 'new_com.inc'

	call wr_tcam_c(
     *  tt,ncam,tcam,tpl,kpr)
	
	return
	end

	subroutine wr_tcam_c(
     *  tt,ncam,tcam,tpl,kpr)

	include 'double.inc'
      
      dimension tcam(*)

	character *12 apr

	i_sh=i_sh+1
	if(i_sh.eq.1)then
       open (unit=41,file='tcam.txt',form='formatted') 
       write(41,*)'n_t' 
       write(41,*)i_sh 

       if(kpr.eq.1)print *,' tt ncam n_t===',tt,ncam,n_t
 
       write(41,*)'tcam(i),i=1,ncam'
       else
       open (unit=41,file='tcam.txt',form='formatted',access='append') 
       end if
       write(41,5000)tt,tpl,(tcam(k),k=1,ncam)

       close (unit=41) 

71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

5000    format (16(1p,1e16.7e3))

	if(kpr.eq.1)print *,' from write_tcam tpl',tpl
	if(kpr.eq.1)print *,' from write_tcam',tcam(1),tcam(8)

       return 
       end 
	subroutine wr_rpp()
	include 'double.inc'
	include 'new_com.inc'

	call wr_rpp_c(
     * rmag,tt)

	return
	end

	subroutine wr_rpp_c(
     * rmag,tt)
	include 'double.inc'

	
	i_en=i_en+1
	if(i_en.eq.1)then
	ntime=9999
      open (unit=43,file='rpp.txt',form='formatted')
      write (43,*)' ktime'
      write (43,*)ntime
      write (43,*)' time [S], rpp'

	else
      open (unit=43,file='rpp.txt',access='append',
     * form='formatted')
	end if


5000    format (6(1pe14.6))
        write (43,*)tt*1.e-3,rmag,i_en

	close(43)

      if(kpr.eq.1)print *,' tt rmag =',tt,rmag

	return
	end

	subroutine wr_zpp()
	include 'double.inc'
	include 'new_com.inc'

	call wr_zpp_c(
     * zmag,tt)

	return
	end

	subroutine wr_zpp_c(
     * zmag,tt)
	include 'double.inc'

	
	i_en=i_en+1
	if(i_en.eq.1)then
	ntime=9999
      open (unit=43,file='zpp.txt',form='formatted')
      write (43,*)' ktime'
      write (43,*)ntime
      write (43,*)' time [S], zpp'

	else
      open (unit=43,file='zpp.txt',access='append',
     * form='formatted')
	end if


5000    format (6(1pe14.6))
        write (43,*)tt*1.e-3,zmag,i_en

	close(43)

      if(kpr.eq.1)print *,' tt rmag =',tt,zmag

	return
	end
  	subroutine shape_rpp2() 
	include 'double.inc'
	include 'new_com.inc'

  	call shape_rpp2_c(
     *  rmag,tt,kpr) 

	return
	end

  	subroutine shape_rpp2_c(
     *  rref_p,tt,kpr) 
	include 'double.inc'

 	include 'parf_mike' 

	dimension t_t(ntime),rp_t(ntime)

	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then


c-------
           open (unit=41,file='rpp2.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 
           read (41,*) 


	k=0
      do i=1,99999
	k=k+1
              read (41,*,err=2000,end=2000)t_t(i),rp_t(i)
              t_t(i)=t_t(i)*1000. 
                n_t=k
           end do 

2000	continue
           
 	 if(kpr.eq.1)print *,' tt n_t===',tt,n_t 

           apr='-t_t-' 
c           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 
           close (unit=41) 
        end if
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 rpp=rp_t(i-1)+t_coef*(rp_t(i)-rp_t(i-1))

c
	 end if

	 end do
	 
	 rref_p=rpp


 	if(kpr.eq.1)print *,' from SHAPE RPP2 rmag',rref_p

       return 
       end 
  	subroutine shape_zpp2() 
	include 'double.inc'
	include 'new_com.inc'

  	call shape_zpp2_c(
     *  zmag,tt,kpr) 

	return
	end

  	subroutine shape_zpp2_c(
     *  rref_p,tt,kpr) 
	include 'double.inc'

 	include 'parf_mike' 

	dimension t_t(ntime),rp_t(ntime)

	character *12 apr

	i_sh=i_sh+1

	if(i_sh.eq.1)then


c-------
           open (unit=41,file='zpp2.dat',form='formatted') 
           read (41,*) 
           read (41,*)n_t 
           read (41,*) 


	k=0
      do i=1,99999
	k=k+1
              read (41,*,err=2000,end=2000)t_t(i),rp_t(i)
              t_t(i)=t_t(i)*1000. 
                n_t=k
           end do 

2000	continue
           
 	 if(kpr.eq.1)print *,' tt n_t===',tt,n_t 

           apr='-t_t-' 
c           if(kpr.eq.1)print 71,apr,(t_t(i),i=1,n_t) 
           close (unit=41) 
        end if
71	FORMAT(20X,A8/,(6(1X,1PE10.3)))

      do i=2,n_t
      if( (tt-t_t(i-1))*(tt-t_t(i)).le.0.)then
c==================
	 t_coef=(tt-t_t(i-1))/( t_t(i)-t_t(i-1) )

	 rpp=rp_t(i-1)+t_coef*(rp_t(i)-rp_t(i-1))

c
	 end if

	 end do
	 
	 rref_p=rpp


 	if(kpr.eq.1)print *,' from SHAPE ZPP2 rmag',rref_p

       return 
       end 


	subroutine write_equil()
	include 'double.inc'
	include 'new_com.inc'

         call write_equil_c(
     *   rs0,
     *   nutab,pstab,ppx,pffx,
     *   pi,kpr,tt,tpl,
     *   ncam,tcam,
     *   npf,pf)

         return
         end

         subroutine write_equil_c(
     *   rs0,
     *   nutab,pstab,pptab,fptab,
     *   pi,kpr,tt,tpl,
     *   ncam,tcam,
     *   npf,pf)

	include 'double.inc'
c	 implicit real *8 (a-h,o-z)

         dimension pstab(*),pptab(*),fptab(*)
      dimension tcam(*),pf(*)

	character *20 apr

71	FORMAT(5X,A10/,(2x,6(1PE11.3)))

      open (unit=43,file='equil.txt',form='formatted')

5000    format (6(1pe14.6))

        write (43,*)tt,tpl
        write (43,*)nutab
        write (43,5000)(pstab(i),i=1,nutab)
        write (43,5000)(pptab(i),i=1,nutab)
        write (43,5000)(fptab(i),i=1,nutab)
        write (43,*)ncam
        write(43,5000)(tcam(k),k=1,ncam)
        write (43,*)npf
        write(43,5000)(pf(k),k=1,npf)


	close(43)

	if(kpr.eq.1)print *,' tt equil.txt is written',tt

	return
	end


	subroutine read_equil()
      include 'double.inc'
	include 'new_com.inc'

         call read_equil_c(
     *   rs0,
     *   n,ppx,pffx,a,pi,
     *   nutab,pstab,pptab,fptab,npf,pf,
     *   ncam,tcam,tt,tpl,kpr)

         return
         end

         subroutine read_equil_c(
     *   rs0,
     *   n,ppx,pffx,a,pi,
     *   nutab,pstab,pptab,fptab,npf,pf,
     *   ncam,tcam,tt,tpl,kpr)

      include 'double.inc'

      parameter ( nn=1000)
      
         dimension ppx(*),pffx(*),a(*)

         dimension pstab(*),pptab(*),fptab(*),tcam(*),pf(*)

      common /c_read_equil/pstab_c(nn),pptab_c(nn),
     *  fptab_c(nn),tcam_c(nn),pf_c(nn),tt_c,tpl_c  

      common /c_read_equil2/npf_c,ncam_c
        

	include 'parf0'

	dimension pai(npo),q_h(npo)

	character *20 apr

71	FORMAT(5X,A10/,(2x,6(1PE14.6)))

      i_en=i_en+1

	apr='-pptab-'                                              
!	if(kpr.eq.1)print 71,apr,(pptab(i),i=1,nutab)
	apr='-fptab-'                                               
	if(kpr.eq.1)print 71,apr,(fptab(i),i=1,nutab)
	apr='--pf-'                                              
	if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf)

      print *,' --tpl==',tpl
      if(i_en.eq.-1)then
      
         open (unit=42,file='equil.txt',form='formatted')
            read (42,*)tt,tpl
            read (42,*)nutab
            read (42,*)(pstab(i),i=1,nutab)
            read (42,*)(pptab(i),i=1,nutab)
            read (42,*)(fptab(i),i=1,nutab)
            read (42,*)ncam
            read (42,*)(tcam(k),k=1,ncam)
            read (42,*)npf
            read (42,*)(pf(k),k=1,npf)
            
         close (42)

      print *,' ++tpl==',tpl

	apr='++pptab-'                                              
!	if(kpr.eq.1)print 71,apr,(pptab(i),i=1,nutab)
	apr='++fptab-'                                               
	if(kpr.eq.1)print 71,apr,(fptab(i),i=1,nutab)
	apr='++pf-'                                              
	if(kpr.eq.1)print 71,apr,(pf(i),i=1,npf)

        end if

        if(i_en.eq.1)then    
            tt_c=tt
            tpl_c=tpl
            npf_c=npf
            ncam_c=ncam
            nutab_c=nutab

      do i=1,nutab
        pptab_c(i)=pptab(i)
        fptab_c(i)=fptab(i)
      end do

      do i=1,ncam
        tcam_c(i)=tcam(i)
      end do

      do i=1,npf
        pf_c(i)=pf(i)
      end do
      
      end if
      
            tt=tt_c
            tpl=tpl_c
            npf=npf_c
            ncam=ncam_c
            nutab=nutab_c

      do i=1,nutab_c
        pptab(i)=pptab_c(i)
        fptab(i)=fptab_c(i)
      end do

      do i=1,ncam_c
        tcam(i)=tcam_c(i)
      end do

      do i=1,npf_c
        pf(i)=pf_c(i)
      end do

      do i=1,n
        ppx(i)=pptab(i)
        pffx(i)=fptab(i)
      end do




      goto 5
      
      do i=1,nutab
        pstab(i)=a(i)
      end do
      
	amu0=4.*pi*1.d-7
      
      if(kpr.eq.1)print *,' tt tpl==',tt,tpl 

	kpr_help=kpr
c	kpr=1
      if(kpr.eq.1)print *,' rs0 amu0 n nutab==',rs0,amu0,n,nutab   
	apr='-pstab-'                                               
	if(kpr.eq.1)print 71,apr,(pstab(i),i=1,nutab)
	apr='-pptab-'                                              
	if(kpr.eq.1)print 71,apr,(pptab(i),i=1,nutab)
	apr='-fptab-'                                               
	if(kpr.eq.1)print 71,apr,(fptab(i),i=1,nutab)
                                                                        
	do i=2,n-1                                                             
	   psn=a(i)                                                       
	   call feeti(nutab,pptab,ppx(i),pstab,psn)                            
	   call feeti(nutab,fptab,pffx(i),pstab,psn)                           
c	   call linear(nutab,pptab,ppx(i),pstab,psn)
c	   call linear(nutab,fptab,pffx(i),pstab,psn)
	end do                                                                 
                                                                        
	ppx(n)=pptab(nutab)                                                    
	ppx(1)=pptab(1)                                                        
                                                                        
	pffx(n)=fptab(nutab)                                                   
	pffx(1)=fptab(1)                                                       
                                                                        
                                                                        
	do i=1,n                                                               
!	ppx(i)=-ppx(i)*(rs0*1.d-2)*amu0                                         
!	pffx(i)=-2.*pffx(i)/(rs0*1.d-2)                                      
	end do                                                                 


	apr='-a-'                                                              
	if(kpr.eq.1)print 71,apr,(a(i),i=1,n)
	apr='-ppx-'                                              
	if(kpr.eq.1)print 71,apr,(ppx(i),i=1,n)
	apr='-pffx-'                                             
	
	if(kpr.eq.1)print 71,apr,(pffx(i),i=1,n)

5     continue

5000    format (6(1pe14.6))


	return
	end
