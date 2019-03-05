
c----------------------- TEST---------------------
c********************************************************
	i=2
	pf(i)=0.01
	   pf(i)=pf(i)+0.25
	   do kk=1,5
	      pf(i)=pf(i)-0.25
	      print *,' kk pf',kk,pf(i)
	      fcom(i)=-8.-2.
	      do k=1,9
		 fcom(i)=fcom(i)+2.

	CALL PULLc(V01,KCHOP(I),PF(I),NCHOP(I),
     *  fcom(i),VPS(i))

	VCHOPPER(I)=KSIGN(I)*v01
c


		 print *,' k  fcom  vch ',
	1	      k,fcom(i),vchopper(i)
		 print *,' '
	      end do
	   end do

	   stop

c-----------------------TEST---------------------
c********************************************************
