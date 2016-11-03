c=======================================================================
      SUBROUTINE STRNUM(STR,L,X,IND)
	include 'double.inc'
c---transformation of the string STR of the lenght L into real X
c---with 7 meaninigfull digits and
c---with IND=0 when success and IND=1 when fail
      character STR*80
      integer*4 n
      integer*2 m,ne,ie,i,nf
      
      s=1.
      f=1.
      ie=0
      ne=0
      nf=0
calculation of the sign
      i=0
 1    i=i+1
      if(i.gt.L) go to 10
      IF(STR(i:i).EQ.' ') go to 1
      if(STR(i:i).eq.'-') then
         s=-1.
         i=i+1
         go to 2
      endif
      if(STR(i:i).eq.'+') i=i+1
calculation of the main part
 2    n=-1
 3    if(i.gt.L.or.STR(i:i).eq.' ') go to 8
      if(STR(i:i).eq.'.') go to 4
      if(STR(i:i).eq.'e'.or.STR(i:i).eq.'E') go to 6
      m=ichar(STR(i:i))-48
      if(m.lt.0.or.m.gt.9) go to 10
      if(n.lt.0) n=0
      if(nf.ne.0.or.m.ne.0) nf=nf+1
      if(nf.le.7) then
         n=n*10+m
      else
         f=f*10.
      endif
      i=i+1
      go to 3
calculation of the mantiss
 4    i=i+1
      if(i.gt.L.or.STR(i:i).eq.' ') go to 8
      if(STR(i:i).eq.'e'.or.STR(i:i).eq.'E') go to 6
      m=ichar(STR(i:i))-48
      if(m.lt.0.or.m.gt.9) go to 10
      if(n.lt.0) n=0
      nf=nf+1
      if(nf.le.7) then
         n=n*10+m
         f=f*0.1
      endif
      go to 4
calculation of the order
calculation of the sign of the order
 6    i=i+1
      if(i.gt.L.or.STR(i:i).eq.' ') go to 8
      if(STR(i:i).eq.'-') then
         ie=-1
         i=i+1
         go to 5
      endif
      if(STR(i:i).eq.'+') i=i+1
 5    m=ichar(STR(i:i))-48
      if(m.lt.0.or.m.gt.9) go to 10
      if(ie.eq.0) ie=1
      ne=ne*10+ie*m
      i=i+1
      if(i.le.L.and.STR(i:i).ne.' ') go to 5
 7    if(ie.eq.0) go to 8
      f=f*10.**ne
calculation of X
 8    if(n.lt.0) go to 10
      x=s*n*f
      ind=0
      return
c---emergency exit
 10   ind=1
      end
c=======================================================================
      SUBROUTINE NUMSTR(X,STR,L)
	include 'double.inc'
c---transformationof the real X into the string STR of the lenght L
c---withthe truncation adjusted for L window
      character STR*80,ch*13
      integer*2 ll,k,ne,i,is
      byte ich(13),i5
      equivalence (ich,ch)
      do i=1,L
         str(i:i)=' '
      enddo
      is=0
      if(x.eq.0.) then
         str(L:L)='0'
         return
      endif
      if(x.lt.0.) is=1
      write(ch,'(8pe13.7)')abs(x)
      read(ch(11:13),'(i3)')ne
      str(1:1)=' '
      if(is.eq.1) str(1:1)='-'
c      ll=L-1
      ll=L-is
      if(ll.eq.0) then
         str(L:L)='*'
         return
      endif
calculation of the number k of significant figures
      k=9
 1    k=k-1
      if(ch(k:k).eq.'0'.and.k.gt.1) go to 1
      ne=ne+8-k
      i5=0
      if(k.gt.ll) then
         ne=ne+k-ll
         k=ll
         call iround(ich,k,ne,i5)
      endif
c---test for the integer format
 3    if(ne.ge.0) then
         STR(1+is:L)=ch(1:k)
         if(k+ne.le.ll) then
            if(ne.eq.0) goto 10
            do i=1+k+is,ne+k+is
               str(i:i)='0'
            enddo
            goto 10
c---testfor the e-form for the integer
         else
            i=ne/10+2
            if(k+i.gt.ll) then
               k=k-1
               if(k.eq.0) go to 2
               ne=ne+1
               call iround(ich,k,ne,i5)
               go to 3
            endif
            k=k+is
            if(i.eq.2) str(k+1:k+i)='e'//char(ne+48)
            if(i.eq.3) write(str(k+1:k+i),'(1he,i2)')ne
            goto 10
         endif
      else
c-testfor the f-form for the real with ne<0
         if(ll.ge.1-ne) then
            if(k.eq.ll) then
               k=k-1
               ne=ne+1
               call iround(ich,k,ne,i5)
               go to 3
            endif
            i=k+ne
            if(i.ge.0) then
               if(i.ge.1) str(1+is:i+is)=ch(1:i)
               i=i+1
               ne=i+is
               str(ne:ne)='.'
               str(ne+1:k+is+1)=ch(i:k)
            else
               i=-i
               str(1+is:1+is)='.'
               do ne=2+is,1+is+i
                  str(ne:ne)='0'
               enddo
               ne=1+is+i
               str(ne+1:ne+k)=ch(1:k)
            endif
         else
            i=-ne/10
c---Testfor e-form for real with ne<0
            if(ll.ge.k+i+3) then
               STR(1+is:k+is)=ch(1:k)
               k=k+is+1
               if(i.eq.0)write(STR(k:k+2),'(2he-,i1)')-ne
               if(i.eq.1)write(STR(k:k+3),'(2he-,i2)')-ne
               goto 10
            endif	
            k=k-1
            if(k.eq.0) go to 2
            ne=ne+1
            call iround(ich,k,ne,i5)
            go to 3
         endif
         goto 10
      endif
 2    str(1:1)='*'
 10   continue
      i=L+1
 11   i=i-1
       if(str(i:i).eq.' ') goto 11
      ch(1:i)=str(1:i)
      if(L.gt.i)str(1:L-i)=' '
ccc      if(L.gt.i)str(1:L-i)=' '
      str(L-i+1:L)=ch(1:i)
      end
c=======================================================================
      subroutine IROUND(ICH,K,NE,I5)
	include 'double.inc'
c---rounding the string to the K significant figures
      byte ICH(*),i,I5
      integer*2 K,NE
      i=k
      if(ich(i+1).gt.53+i5) then
         ich(i)=ich(i)+1
         i5=0
         if(ich(i).eq.53) i5=1
      endif
 1    if(ich(i).eq.58) then
         if(i.gt.1) then
            ich(i)=48
            ich(i-1)=ich(i-1)+1
            i5=0
            if(ich(i-1).eq.53) i5=1
         else
            ich(i)=49
            ne=ne+1
            return
         endif
      endif
      if(ich(i).eq.48) then
         k=k-1
         i=i-1
         ne=ne+1
         goto 1
      endif
      end
      


