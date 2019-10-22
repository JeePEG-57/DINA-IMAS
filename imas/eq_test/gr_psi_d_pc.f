	subroutine write_graf(
     *	nr,nz,ke,ncam,nwnh,npf,jbound,iprof,
     *	dx,dy,ttt,
     *  psi,x,y,xu,yu,rc,zc,
     *  pmag,pbound,p_s,um,vm,
     *  xbound,ybound,xcur,torcur ) 
c$
	include 'double.inc'
	include 'parf0'
c#
        common
     *  /ge5/kpr
c$
	common
     *  /mid6/bp_0(npo),a_m(npo),r_m(npo)
    	common
     *	/n_m/n,m,mp
c#
	dimension
     *  psi(nr,nz),x(nr),y(nz),xu(ke),yu(ke),
     *  rc(ncam),zc(ncam),
     *  xbound(jbound),ybound(jbound),
     *  xcur(iprof),torcur(iprof)

	dimension
     *  agraf(2*npo)


	ntay=ntay+1

c$
	ml=mp/2+1
	i=0
	do k0=1,2
	if(k0.eq.1)j=ml
	if(k0.eq.2)j=2
	do i0=2,n
	if(k0.eq.1)k=n-i0+2
	if(k0.eq.2)k=i0
	i=i+1
	agraf(i)=a_m(k)
	end do
	end do	
c#

c----------- write  graphics data ---
c*** i_form=1 to do formatted writing
	i_form=1

5000	format(4(1x,1pe14.7))
	
	if(i_form.eq.0)then

c	open (unit=61,file='psi_data',access='append',
c     *  form='unformatted')
           if(ntay.le.1)then
              open (unit=61,file='psi_data',status='new',
     *             form='unformatted')
           end if

           if(ntay.gt.1)then
              open (unit=61,file='psi_data',status='old',
     *             form='unformatted')
           end if
c$

           write (61)ke,ncam,npf,jbound,iprof
c#
           write (61)(rc(i),i=1,ncam)
           write (61)(zc(i),i=1,ncam)
           write (61)(xu(i),i=1,ke)
           write (61)(yu(i),i=1,ke)
c
           write (61)dx,dy,pmag,pbound,p_s,um,vm,ttt
           
           write (61)((psi(i,j),i=1,nr),j=1,nz)
           write (61)(x(i),i=1,nr)
           write (61)(y(i),i=1,nz)
           write (61)(xbound(i),i=1,jbound)
           write (61)(ybound(i),i=1,jbound)
           write (61)(xcur(i),i=1,iprof)
           write (61)(torcur(i),i=1,iprof)
c$
c!!!	write (61)(agraf(i),i=1,iprof)
c#	
c	if(kpr.eq.1)print*,(agraf(i),i=1,iprof)
c	read(*,*)


           close (61)

	else

           if(ntay.le.1)then
              open (unit=61,file='psi_data2',
     *             form='formatted')
           end if

           if(ntay.gt.1)then
              open (unit=61,file='psi_data2',access='append',
     *             form='formatted')
           end if
c           if(ntay.le.1)then
c              open (unit=61,file='psi_data',status='new',
c     *             form='formatted')
c           end if

c           if(ntay.gt.1)then
c              open (unit=61,file='psi_data',status='old',
c     *             form='formatted')
c           end if
c$

           write (61,*)ke,ncam,npf,jbound,iprof
c#    
           write (61,5000)(rc(i),i=1,ncam)
           write (61,5000)(zc(i),i=1,ncam)
           write (61,5000)(xu(i),i=1,ke)
           write (61,5000)(yu(i),i=1,ke)
c     
           write (61,5000)dx,dy,pmag,pbound,p_s,um,vm,ttt
           
           write (61,5000)((psi(i,j),i=1,nr),j=1,nz)
           write (61,5000)(x(i),i=1,nr)
           write (61,5000)(y(i),i=1,nz)
           write (61,5000)(xbound(i),i=1,jbound)
           write (61,5000)(ybound(i),i=1,jbound)
           write (61,5000)(xcur(i),i=1,iprof)
           write (61,5000)(torcur(i),i=1,iprof)
c$
c!!!!	write (61,5000)(agraf(i),i=1,iprof)
c#	
c	if(kpr.eq.1)print*,(agraf(i),i=1,iprof)
c	read(*,*)


           close (61)

	end if
        
        
	return
	end














