      subroutine min_dist(dist_min_xx,Rdist_min_xx,Zdist_min_xx)
	include 'double.inc'
	include 'new_com.inc'

!	common
!     *  /eq8/jbound,xbound(ntet),ybound(ntet),alfa0_xx

        call min_dist_c(jbound,xbound,ybound,
     &       xu,yu,ke,
     &       dist_min_xx,Rdist_min_xx,Zdist_min_xx,tt)

        return
        end
    

        subroutine min_dist_c(NB,Rbound,Zbound,
     &       Rlim,Zlim,Nlim,
     &       dist_min,Rdist_min,Zdist_min,tt)
	include 'double.inc'

	parameter(Nlim_max=5000, Nbound_max=1000, ds=1.d0)


	dimension Rbound(NB),Zbound(NB),
     &  Rlim(Nlim),Zlim(Nlim),
     &  Rlim2(Nlim_max),Zlim2(Nlim_max),
     &  dNB(Nbound_max),
     &  RNB_min(Nbound_max),ZNB_min(Nbound_max)


      i_lim_wr=0
      if(i_lim_wr.eq.1)then

	open (unit=20,file='limiter',access='append',
     *  form='formatted')
	open (unit=21,file='boundary',access='append',
     *  form='formatted')
	open (unit=22,file='lim2',access='append',
     *  form='formatted')
     
      end if
     
     
!      if(kpr.eq.1)print *,' ENTER='
!      stop
     

5000	format(4(1x,1pe14.7))

c	write (20,*)Nlim,tt
c        do i=1,Nlim
c	write (20,5000)Rlim(i),Zlim(i)
c        end do

c        if(tt.gt.48000.)then

c	write (21,*)NB,tt
c        do i=1,NB
c	write (21,5000)Rbound(i),Zbound(i)
c        end do
c        stop
c        end if


        if(i_en.eq.0)then
           i_en=i_en+1

         k=0
         do i=1,Nlim-1
           d=sqrt((Rlim(i+1)-Rlim(i))**2+(Zlim(i+1)-Zlim(i))**2)
           nd=d/ds

c           if(kpr.eq.1)print*,'!!!i nd d ds',i,nd,d,ds

           do j=1,nd
           Rlim2(k+j)=Rlim(i)+(Rlim(i+1)-Rlim(i))*(j-1)/nd
           Zlim2(k+j)=Zlim(i)+(Zlim(i+1)-Zlim(i))*(j-1)/nd
           
c           if(kpr.eq.1)print*,'k+j',k+j
c           if(kpr.eq.1)print*,'Rlim(i) Zlim(i)',Rlim(i),Zlim(i)
c           if(kpr.eq.1)print*,'Rlim(i+1) Zlim(i+1)',Rlim(i+1),Zlim(i+1)
c           if(kpr.eq.1)print*,'Rlim2(k+j) Zlim2(k+j)',Rlim2(k+j),Zlim2(k+j)

           enddo
           k=k+nd

         end do

         k=k+1
         Rlim2(k)=Rlim(Nlim)
         Zlim2(k)=Zlim(Nlim)

         end if

c	write (22,*)k,tt
c        do i=1,k
c	write (22,5000)Rlim2(i),Zlim2(i)
c        end do

c        close (20)
c        close (21)
c        close (22)




         dist_min=1e8
         ds1=0.1d0

         do i=1,NB-1

           d=sqrt((Rbound(i+1)-Rbound(i))**2+(Zbound(i+1)-Zbound(i))**2)
!           nd=d/ds
           nd=d/ds
           pnd=float(nd)
           
!           if(kpr.eq.1)print*,'!!!i nd d ds',i,nd,d,ds

           do jj=1,nd
           
           Rbb=Rbound(i)+(Rbound(i+1)-Rbound(i))*float(jj-1)/pnd
           Zbb=Zbound(i)+(Zbound(i+1)-Zbound(i))*float(jj-1)/pnd

           do j=1,k
           d=sqrt((Rbb-Rlim2(j))**2+(Zbb-Zlim2(j))**2)
           if(d .lt. dist_min) then
           j_min=j
           jj_min=jj
           dist_min=d
           Rdist_min=Rlim2(j)
           Zdist_min=Zlim2(j)
           endif
           enddo
         enddo

         enddo


         if(kpr.eq.1)print*,'!!!j jj k dist_min Rdist_min Zdist_min',
     *   j_min,jj_min,k,dist_min,Rdist_min,Zdist_min
         
        return
        end
