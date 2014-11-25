!****************************************************************************
c*** Program to change a scale with multiplate the each time slice in ch_k times!!!
        program change_t

        tst=50.
        ch_k=0.7
        call sub_change_t(tst,ch_k)

        end 
        
        subroutine sub_change_t(tst,ch_k)
        
        common/p1/ Upr(1000,20)
        
        dimension t_volt(1000),t1_volt(1000),t2_volt(1000),volt(1000,20)
        dimension volt1(1000,20),volt2(1000,20),volt_int(20),t2_ch(1000)
        character*100 a
        character*50 a2,a3
        
        data ncoil/12/
        data a/'Time(s),Ip,I(CSU3),I(CSU2),I(CSU1),I(CSL1),I(CSL2),
     *  I(CSL3),I(PF1),I(PF2),I(PF3),I(PF4),I(PF5),I(PF6)'/
        
        open(1,file='volt.dat')
        read(1,*)
        k=0
	    do while(.TRUE.)
        k=k+1
        read(1,*,err=10,end=10) t_volt(k),(volt(k,i),i=1,ncoil)
	    enddo
10      continue
        close(1)
        nt_volt=k-1
        
        k1=0
        k2=1
        t2_volt(1)=tst
        do i=1,nt_volt
        t_volt(i)=t_volt(i)*1e-3
        if(t_volt(i) .gt. tst-1e-6) then
        k2=k2+1
        t2_volt(k2)=t_volt(i)
        do j=1,ncoil
        volt2(k2,j)=volt(i,j)
        enddo
        else
        k1=k1+1
        t1_volt(k1)=t_volt(i)
        do j=1,ncoil
        volt1(k1,j)=volt(i,j)
        enddo
        endif
        enddo
        
        do i=1,nt_volt
        do j=1,ncoil
        Upr(i,j)=volt(i,j)
        enddo
        enddo
        call linvolt(nt_volt,ncoil,t_volt,tst,volt_int)
        do j=1,ncoil
        volt2(1,j)=volt_int(j)
        enddo
        
        do i=1,k2
        if(i .eq. 1) then
        t2_ch(i)=t2_volt(1)
        else
        t2_ch(i)=(t2_volt(i)-tst)*ch_k+tst
        endif
        enddo
        
!        write(*,*) 't2_ch,ch_k',(t2_ch(i),i=1,k2),ch_k
!        write(*,*) (t_volt(i),i=1,nt_volt)
!        pause

        open(1,file='volt_chf.dat')
        write(1,*) '!!!!!!!!!!!!!!!'
        do i=1,k1
        write(1,'(1p15e14.6)') t1_volt(i)*1e3,(volt1(i,j),j=1,ncoil)
        enddo
        do i=1,k2
        write(1,'(1p15e14.6)') t2_ch(i)*1e3,(volt2(i,j),j=1,ncoil)
        enddo
        close(1)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!2!!!!!!!!!!!!!!!!!!!!!!!!!
        open(1,file='scr_data')
        read(1,*)
        k=0
	    do while(.TRUE.)
        k=k+1
        read(1,*,err=20,end=20) t_volt(k),(volt(k,i),i=1,ncoil+1)
	    enddo
20      continue
        close(1)
        nt_volt=k-1
        
        k1=0
        k2=1
        t2_volt(1)=tst
        do i=1,nt_volt
        t_volt(i)=t_volt(i)*1e0
        if(t_volt(i) .gt. tst-1e-6) then
        k2=k2+1
        t2_volt(k2)=t_volt(i)
        do j=1,ncoil+1
        volt2(k2,j)=volt(i,j)
        enddo
        else
        k1=k1+1
        t1_volt(k1)=t_volt(i)
        do j=1,ncoil+1
        volt1(k1,j)=volt(i,j)
        enddo
        endif
        enddo
        
        do i=1,nt_volt
        do j=1,ncoil+1
        Upr(i,j)=volt(i,j)
        enddo
        enddo
        call linvolt(nt_volt,ncoil+1,t_volt,tst,volt_int)
        do j=1,ncoil+1
        volt2(1,j)=volt_int(j)
        enddo
        
        do i=1,k2
        if(i .eq. 1) then
        t2_ch(i)=t2_volt(1)
        else
        t2_ch(i)=(t2_volt(i)-tst)*ch_k+tst
        endif
        enddo
        
        open(1,file='scr_data_chf.dat')
        write(1,'(a50)') a
        do i=1,k1
        write(1,'(1p15e14.6)') t1_volt(i),(volt1(i,j),j=1,ncoil+1)
        enddo
        do i=1,k2
        write(1,'(1p15e14.6)') t2_ch(i),(volt2(i,j),j=1,ncoil+1)
        enddo
        close(1)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        open(1,file='g1.dat')
        read(1,*) a2
        read(1,*) k
        read(1,*) a3
        do i=1,k
        read(1,*) t_volt(i),volt(i,1)
        enddo
        close(1)
        nt_volt=k
        
        k1=0
        k2=1
        t2_volt(1)=tst
        do i=1,nt_volt
        t_volt(i)=t_volt(i)*1e0
        if(t_volt(i) .gt. tst-1e-6) then
        k2=k2+1
        t2_volt(k2)=t_volt(i)
        do j=1,1
        volt2(k2,j)=volt(i,j)
        enddo
        else
        k1=k1+1
        t1_volt(k1)=t_volt(i)
        do j=1,1
        volt1(k1,j)=volt(i,j)
        enddo
        endif
        enddo
        
        do i=1,nt_volt
        do j=1,1
        Upr(i,j)=volt(i,j)
        enddo
        enddo
        call linvolt(nt_volt,1,t_volt,tst,volt_int)
        do j=1,1
        volt2(1,j)=volt_int(j)
        enddo
        
        do i=1,k2
        if(i .eq. 1) then
        t2_ch(i)=t2_volt(1)
        else
        t2_ch(i)=(t2_volt(i)-tst)*ch_k+tst
        endif
        enddo
        
        open(1,file='g1_chf.dat')
        write(1,'(a50)') a2
        write(1,*) k+1
        write(1,'(a50)') a3
        do i=1,k1
        write(1,'(1p15e14.6)') t1_volt(i),(volt1(i,j),j=1,1)
        enddo
        do i=1,k2
        write(1,'(1p15e14.6)') t2_ch(i),(volt2(i,j),j=1,1)
        enddo
        close(1)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        open(1,file='g2.dat')
        read(1,*) a2
        read(1,*) k
        read(1,*) a3
        do i=1,k
        read(1,*) t_volt(i),volt(i,1)
        enddo
        close(1)
        nt_volt=k
        
        k1=0
        k2=1
        t2_volt(1)=tst
        do i=1,nt_volt
        t_volt(i)=t_volt(i)*1e0
        if(t_volt(i) .gt. tst-1e-6) then
        k2=k2+1
        t2_volt(k2)=t_volt(i)
        do j=1,1
        volt2(k2,j)=volt(i,j)
        enddo
        else
        k1=k1+1
        t1_volt(k1)=t_volt(i)
        do j=1,1
        volt1(k1,j)=volt(i,j)
        enddo
        endif
        enddo
        
        do i=1,nt_volt
        do j=1,1
        Upr(i,j)=volt(i,j)
        enddo
        enddo
        call linvolt(nt_volt,1,t_volt,tst,volt_int)
        do j=1,1
        volt2(1,j)=volt_int(j)
        enddo
        
        do i=1,k2
        if(i .eq. 1) then
        t2_ch(i)=t2_volt(1)
        else
        t2_ch(i)=(t2_volt(i)-tst)*ch_k+tst
        endif
        enddo
        
        open(1,file='g2_chf.dat')
        write(1,'(a50)') a2
        write(1,*) k+1
        write(1,'(a50)') a3
        do i=1,k1
        write(1,'(1p15e14.6)') t1_volt(i),(volt1(i,j),j=1,1)
        enddo
        do i=1,k2
        write(1,'(1p15e14.6)') t2_ch(i),(volt2(i,j),j=1,1)
        enddo
        close(1)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        open(1,file='g3.dat')
        read(1,*) a2
        read(1,*) k
        read(1,*) a3
        do i=1,k
        read(1,*) t_volt(i),volt(i,1)
        enddo
        close(1)
        nt_volt=k
        
        k1=0
        k2=1
        t2_volt(1)=tst
        do i=1,nt_volt
        t_volt(i)=t_volt(i)*1e0
        if(t_volt(i) .gt. tst-1e-6) then
        k2=k2+1
        t2_volt(k2)=t_volt(i)
        do j=1,1
        volt2(k2,j)=volt(i,j)
        enddo
        else
        k1=k1+1
        t1_volt(k1)=t_volt(i)
        do j=1,1
        volt1(k1,j)=volt(i,j)
        enddo
        endif
        enddo
        
        do i=1,nt_volt
        do j=1,1
        Upr(i,j)=volt(i,j)
        enddo
        enddo
        call linvolt(nt_volt,1,t_volt,tst,volt_int)
        do j=1,1
        volt2(1,j)=volt_int(j)
        enddo
        
        do i=1,k2
        if(i .eq. 1) then
        t2_ch(i)=t2_volt(1)
        else
        t2_ch(i)=(t2_volt(i)-tst)*ch_k+tst
        endif
        enddo
        
        open(1,file='g3_chf.dat')
        write(1,'(a50)') a2
        write(1,*) k+1
        write(1,'(a50)') a3
        do i=1,k1
        write(1,'(1p15e14.6)') t1_volt(i),(volt1(i,j),j=1,1)
        enddo
        do i=1,k2
        write(1,'(1p15e14.6)') t2_ch(i),(volt2(i,j),j=1,1)
        enddo
        close(1)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        open(1,file='g4.dat')
        read(1,*) a2
        read(1,*) k
        read(1,*) a3
        do i=1,k
        read(1,*) t_volt(i),volt(i,1)
        enddo
        close(1)
        nt_volt=k
        
        k1=0
        k2=1
        t2_volt(1)=tst
        do i=1,nt_volt
        t_volt(i)=t_volt(i)*1e0
        if(t_volt(i) .gt. tst-1e-6) then
        k2=k2+1
        t2_volt(k2)=t_volt(i)
        do j=1,1
        volt2(k2,j)=volt(i,j)
        enddo
        else
        k1=k1+1
        t1_volt(k1)=t_volt(i)
        do j=1,1
        volt1(k1,j)=volt(i,j)
        enddo
        endif
        enddo
        
        do i=1,nt_volt
        do j=1,1
        Upr(i,j)=volt(i,j)
        enddo
        enddo
        call linvolt(nt_volt,1,t_volt,tst,volt_int)
        do j=1,1
        volt2(1,j)=volt_int(j)
        enddo
        
        do i=1,k2
        if(i .eq. 1) then
        t2_ch(i)=t2_volt(1)
        else
        t2_ch(i)=(t2_volt(i)-tst)*ch_k+tst
        endif
        enddo
        
        open(1,file='g4_chf.dat')
        write(1,'(a50)') a2
        write(1,*) k+1
        write(1,'(a50)') a3
        do i=1,k1
        write(1,'(1p15e14.6)') t1_volt(i),(volt1(i,j),j=1,1)
        enddo
        do i=1,k2
        write(1,'(1p15e14.6)') t2_ch(i),(volt2(i,j),j=1,1)
        enddo
        close(1)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        open(1,file='g5.dat')
        read(1,*) a2
        read(1,*) k
        read(1,*) a3
        do i=1,k
        read(1,*) t_volt(i),volt(i,1)
        enddo
        close(1)
        nt_volt=k
        
        k1=0
        k2=1
        t2_volt(1)=tst
        do i=1,nt_volt
        t_volt(i)=t_volt(i)*1e0
        if(t_volt(i) .gt. tst-1e-6) then
        k2=k2+1
        t2_volt(k2)=t_volt(i)
        do j=1,1
        volt2(k2,j)=volt(i,j)
        enddo
        else
        k1=k1+1
        t1_volt(k1)=t_volt(i)
        do j=1,1
        volt1(k1,j)=volt(i,j)
        enddo
        endif
        enddo
        
        do i=1,nt_volt
        do j=1,1
        Upr(i,j)=volt(i,j)
        enddo
        enddo
        call linvolt(nt_volt,1,t_volt,tst,volt_int)
        do j=1,1
        volt2(1,j)=volt_int(j)
        enddo
        
        do i=1,k2
        if(i .eq. 1) then
        t2_ch(i)=t2_volt(1)
        else
        t2_ch(i)=(t2_volt(i)-tst)*ch_k+tst
        endif
        enddo
        
        open(1,file='g5_chf.dat')
        write(1,'(a50)') a2
        write(1,*) k+1
        write(1,'(a50)') a3
        do i=1,k1
        write(1,'(1p15e14.6)') t1_volt(i),(volt1(i,j),j=1,1)
        enddo
        do i=1,k2
        write(1,'(1p15e14.6)') t2_ch(i),(volt2(i,j),j=1,1)
        enddo
        close(1)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        open(1,file='g6.dat')
        read(1,*) a2
        read(1,*) k
        read(1,*) a3
        do i=1,k
        read(1,*) t_volt(i),volt(i,1)
        enddo
        close(1)
        nt_volt=k
        
        k1=0
        k2=1
        t2_volt(1)=tst
        do i=1,nt_volt
        t_volt(i)=t_volt(i)*1e0
        if(t_volt(i) .gt. tst-1e-6) then
        k2=k2+1
        t2_volt(k2)=t_volt(i)
        do j=1,1
        volt2(k2,j)=volt(i,j)
        enddo
        else
        k1=k1+1
        t1_volt(k1)=t_volt(i)
        do j=1,1
        volt1(k1,j)=volt(i,j)
        enddo
        endif
        enddo
        
        do i=1,nt_volt
        do j=1,1
        Upr(i,j)=volt(i,j)
        enddo
        enddo
        call linvolt(nt_volt,1,t_volt,tst,volt_int)
        do j=1,1
        volt2(1,j)=volt_int(j)
        enddo
        
        do i=1,k2
        if(i .eq. 1) then
        t2_ch(i)=t2_volt(1)
        else
        t2_ch(i)=(t2_volt(i)-tst)*ch_k+tst
        endif
        enddo
        
        open(1,file='g6_chf.dat')
        write(1,'(a50)') a2
        write(1,*) k+1
        write(1,'(a50)') a3
        do i=1,k1
        write(1,'(1p15e14.6)') t1_volt(i),(volt1(i,j),j=1,1)
        enddo
        do i=1,k2
        write(1,'(1p15e14.6)') t2_ch(i),(volt2(i,j),j=1,1)
        enddo
        close(1)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        open(1,file='dens.dat')
        read(1,*) a2
        read(1,*) k
        read(1,*) a3
        do i=1,k
        read(1,*) t_volt(i),volt(i,1)
        enddo
        close(1)
        nt_volt=k
        
        k1=0
        k2=1
        t2_volt(1)=tst
        do i=1,nt_volt
        t_volt(i)=t_volt(i)*1e0
        if(t_volt(i) .gt. tst-1e-6) then
        k2=k2+1
        t2_volt(k2)=t_volt(i)
        do j=1,1
        volt2(k2,j)=volt(i,j)
        enddo
        else
        k1=k1+1
        t1_volt(k1)=t_volt(i)
        do j=1,1
        volt1(k1,j)=volt(i,j)
        enddo
        endif
        enddo
        
        do i=1,nt_volt
        do j=1,1
        Upr(i,j)=volt(i,j)
        enddo
        enddo
        call linvolt(nt_volt,1,t_volt,tst,volt_int)
        do j=1,1
        volt2(1,j)=volt_int(j)
        enddo
        
        do i=1,k2
        if(i .eq. 1) then
        t2_ch(i)=t2_volt(1)
        else
        t2_ch(i)=(t2_volt(i)-tst)*ch_k+tst
        endif
        enddo
        
        open(1,file='dens_chf.dat')
        write(1,'(a50)') a2
        write(1,*) k+1
        write(1,'(a50)') a3
        do i=1,k1
        write(1,'(1p15e14.6)') t1_volt(i),(volt1(i,j),j=1,1)
        enddo
        do i=1,k2
        write(1,'(1p15e14.6)') t2_ch(i),(volt2(i,j),j=1,1)
        enddo
        close(1)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        end

       SUBROUTINE  linvolt( ntu,nUpr,tu, TIMEV, PFVOL2)
       common/p1/ Upr(1000,20)

       DIMENSION  tu(ntu), PFVOL2(nUpr)

    	do i=1,ntu
    	if(timev .lt. tu(i)) exit
    	enddo
    	if(i .eq. 1) then
    	do j=1,nUpr
    	PFVOL2(j)=Upr(1,j)+(Upr(2,j)-Upr(1,j))*(timev-tu(1))/(tu(2)-tu(1))
    	enddo
    	else
    	if(i .gt. ntu) i=i-1
    	do j=1,nUpr
    	PFVOL2(j)=Upr(i-1,j)+(Upr(i,j)-Upr(i-1,j))*
     *  (timev-tu(i-1))/(tu(i)-tu(i-1))
    	enddo
	    endif
          RETURN
          END
!**********************************************************
