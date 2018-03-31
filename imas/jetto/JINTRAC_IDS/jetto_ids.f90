

	subroutine prof_write(filename, tt, rr, x)

	real(8),dimension(:) :: tt, rr
	real(8),dimension(:,:) :: x
	integer :: nn, it
	character(len=100) :: filename

        open (unit=41,file=filename,form='formatted') 

	nn = size(rr,1)
        write (41,*) nn, (rr(ir),ir=1,nn)

        nt = size(tt,1)
        do it = 1,nt
          write (41,*) tt(it), (x(it,ir),ir=1,nn)
	enddo

        close (41)


	return
	end




	subroutine prof_read(filename, tt, rr, x)

	real(8),dimension(:),allocatable :: tt, rr
	real(8),dimension(:,:),allocatable :: x
	integer :: nr, it, nt, ir
	character(len=100) :: filename
	real(8) temp
        INTEGER*4  access, status

print *, filename

    
        status = access ( filename, ' ' )    ! blank mode
        if ( status .ne. 0 ) then 
          write(*,*) 'no file, status =', status
          return
        end if

        open (unit=41,file=filename,form='formatted') 

        read (41,*)nr
print*, 'nr = ', nr
        if(allocated(rr)) deallocate(rr)
        allocate(rr(nr))
	rewind(41)
        read (41,*)temp, (rr(ir),ir=1,nr)

!print*, 'rr=', rr

        nt = 0
        do
          read (41,*,err=2000,end=2000) (temp,ir=1,nr+1)
 	nt = nt + 1
	enddo
2000	continue

	rewind(41)
        read (41,*)temp

        if(allocated(tt)) deallocate(tt)
        allocate(tt(nt))
        if(allocated(x)) deallocate(x)
        allocate(x(nt,nr))

        do it = 1,nt
          read (41,*) tt(it), (x(it,ir),ir=1,nr)
	enddo

        close (41)

	return
	end

