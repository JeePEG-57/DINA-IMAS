      subroutine f_cs()
      include 'double.inc'
      include 'new_com.inc'
      
      call f_cs_c(
     &     pf,tcam,rc,zc,tpl,ncam,npf,r_cur,z_cur,tt)

      return
      end

      subroutine f_cs_c(
     &     pf_11,tcam,rc,zc,tpl,ncam,npf_11,x_pl,y_pl,tt)
      include 'double.inc'

      include 'parf1'
      include 'parf2'

      common 
     *  /vic_em_data/force_r(kf),force_z(kf) 
     *  /vic_1_em/R(nmax,KF),Z(nmax,KF)
     *  /vic_2_em/nmx(kf),nmy(kf)
     *  /vic_4_em/delr,delz
     *  /vic_5_em/d_R(nmax,KF),d_Z(nmax,KF)
      dimension Fcc_r(kf,kf),Fcc_z(kf,kf),Fcv_r(kf,mu),Fcv_z(kf,mu)
      dimension pf_11(*),tcam(*),rc(*),zc(*)
      dimension pf(kf)

      i_en=i_en+1
      if(i_en.eq.1)then
         call vic_obm() 

         ARG=1.d0
         pi=4.d0*atan(ARG)
         coef=10.d0/(4.d0*pi)
         b_c=0.1d0
         npf=npf_11+1

         call edim1
         
         do j=1,npf
            pnum=(nmx(j)*nmy(j))
c-------------------------------------------
            do jjj=1,npf
               Fcc_r(j,jjj)=0.
               Fcc_z(j,jjj)=0.
            end do
c-----------------------------------
            do  kv=1,ncam
               Fcv_r(j,kv)=0.
               Fcv_z(j,kv)=0.
            end do
          
            do j_r=1,nmx(j)
               do j_z=1,nmy(j)                
                  rr=r(j_r,j)
                  zz=z(j_z,j)
c-------------------------- Other Coils..............
                  do jjj=1,npf
	             pnum1=(nmx(jjj)*nmy(jjj))

                     do jjj_r=1,nmx(jjj)
                        do jjj_z=1,nmy(jjj)
                           
                           rr1=r(jjj_r,jjj)
                           zz1=z(jjj_z,jjj)
                           
                           delr=d_R(jjj_r,jjj)
                           delz=d_Z(jjj_z,jjj)
                           
                           dist_rec=sqrt( delr**2+delz**2)
                           dist=sqrt( (rr-rr1)**2+(zz-zz1)**2 )
                           if(dist.le.dist_rec)then
                              call brz_k(br_pf,bz_pf,rr,rr1,zz,zz1)
                           else
                              call brz(br_pf,bz_pf,rr,rr1,zz,zz1)
                           end if                           
c-------------------------------------------------------
          Fcc_r(j,jjj)=Fcc_r(j,jjj)+bz_pf*b_c/pnum/pnum1*
     *          2.d0*pi*rr*0.01d0*1.d-3
          Fcc_z(j,jjj)=Fcc_z(j,jjj)-br_pf*b_c/pnum/pnum1*
     *          2.d0*pi*rr*0.01d0*1.d-3

                        end do
                     end do
                  end do
c-------------- Vacuum vessel -----------------------------
                  do  kv=1,ncam
                     call brz(br_v,bz_v,rr,rc(kv),zz,zc(kv))
                     Fcv_r(j,kv)=Fcv_r(j,kv)+bz_v*b_c/pnum*
     *                    2.d0*pi*rr*0.01d0*1.d-3
                     Fcv_z(j,kv)=Fcv_z(j,kv)-br_v*b_c/pnum*
     *                    2.d0*pi*rr*0.01d0*1.d-3
                  end do

c *** jjj ***
               end do
            end do
         end do

c*** i_en   end if ********** 
      end if

c*** We convert 11-coils data to 12-coils data ***
        do i=1,npf
           if(i.le.3)pf(i)=pf_11(i)
           if(i.eq.4)pf(i)=pf_11(3)
           if(i.ge.5)pf(i)=pf_11(i-1)
        end do

c        if(kpr.eq.1)print*,(pf(i),i=1,npf)
c        read(*,*)
        
c***
c        do i=1,ncam
c           tcam(i)=0.
c        end do

c        tpl=0.

c%%%===== Calculation of forces in MN ******************
        do j=1,npf
           force_r(j)=0.
           force_z(j)=0.

           do jjj=1,npf
              force_r(j)=force_r(j)+Fcc_r(j,jjj)*pf(jjj)
              force_z(j)=force_z(j)+Fcc_z(j,jjj)*pf(jjj)
           end do
           
           tokc=0.
           do  kv=1,ncam
              tokc=tokc+tcam(kv)
              force_r(j)=force_r(j)+Fcv_r(j,kv)*tcam(kv)
              force_z(j)=force_z(j)+Fcv_z(j,kv)*tcam(kv)
           end do
           
           pnum=(nmx(j)*nmy(j))
           do j_r=1,nmx(j)
              do j_z=1,nmy(j)
                 rr=r(j_r,j)
                 zz=z(j_z,j)
                 
                 call brz(br_p,bz_p,rr,x_pl,zz,y_pl)
                 br_pl=br_p*b_c*tpl
                 bz_pl=bz_p*b_c*tpl
             
                 force_r(j)=force_r(j)+bz_pl/pnum*2.d0*pi*rr*
     &                0.01d0*1.d-3     
                 force_z(j)=force_z(j)-br_pl/pnum*2.d0*pi*rr*
     &                0.01d0*1.d-3     

              end do
           end do

           force_r(j)=force_r(j)*pf(j)
           force_z(j)=force_z(j)*pf(j)
       
        end do

        if(kpr.eq.1)print*,'From forces for control'
        if(kpr.eq.1)print*,'tt tokc tpl',tt,tokc,tpl
        if(kpr.eq.1)print*,'Force_r'
        if(kpr.eq.1)print*,(force_r(j),j=1,npf)
        if(kpr.eq.1)print*,'Force_z'
        if(kpr.eq.1)print*,(force_z(j),j=1,npf)
c        read(*,*)

        return
        end

c*********************************************
      subroutine vic_obm()
      
      include 'double.inc'
      include 'parf1'

      COMMON
     *  /vic_1_em/R(nmax,KF),Z(nmax,KF)
     *  /vic_2_em/nmx(kf),nmy(kf)
     *  /vic_4_em/delr,delz
     *  /vic_5_em/d_R(nmax,KF),d_Z(nmax,KF)

      dimension r_c(kf),z_c(kf),dr(kf),dz(kf),turn(kf)

      open(unit=41,status='old',file='koor_pf',form='formatted')
      read(41,*)
      read(41,*)npf,cnmx,kl_pf
      if(kpr.eq.1)print *,'npf cnmx',npf,cnmx,kl_pf
      do I=1,npf
         read(41,*)
         read(41,*)nmx(i),nmy(i),turn(i)
         nmx(i)=nmx(i)*cnmx
         if(nmx(i).gt.nmax)stop
         nmy(i)=nmy(i)*cnmx
         if(nmy(i).gt.nmax)stop
c     
         IF(KPR.EQ.1)PRINT*,'i NMX NMY turn',i,NMX(I),nmy(i),turn(i)
         read(41,*)R_c(I),Z_c(I),dr(i),dz(i)
         IF(KPR.EQ.1)PRINT *,'r_c z_c dr dz ',r_c(i),z_c(i),dr(i),dz(i)
      END DO
      close(41)

c      read(*,*)

c!!! Each division is less then del!!!
      del=10.
ccc      del=5.

      do i=1,npf
         nmx(i)=dr(i)/del+1
         nmy(i)=dz(i)/del+1

c         if(kpr.eq.1)print*,'i nmx(i) nmy(i)',i,nmx(i),nmy(i)
c         read(*,*)

         r1=r_c(i)-0.5*dr(i)
         r2=r_c(i)+0.5*dr(i)
         z1=z_c(i)-0.5*dz(i)
         z2=z_c(i)+0.5*dz(i)
         do j=1,nmx(i)
            d_r(j,i)=(r2-r1)/nmx(i)
            r(j,i)=r1+(j-0.5)*(r2-r1)/nmx(i)
c            if(i.eq.1)print *,'i j r',i,j,r(j,i)
         end do
         do j=1,nmy(i)
            z(j,i)=z1+(j-0.5)*(z2-z1)/nmy(i)
            d_z(j,i)=(z2-z1)/nmy(i)
c            if(i.eq.1)print *,'i j z',i,j,z(j,i)
         end do

      end do

      return
      end

c******************************************************
      SUBROUTINE BRZ_K(br_pf,bz_pf,rr,rr1,zz,zz1)
	include 'double.inc'

        common
     *  /vic_4_em/delr,delz
        
	dr=delr
	dz=delz

	rr1_s=rr1*1.d-2
	zz1_s=zz1*1.d-2
	rr_s=rr*1.d-2
	zz_s=zz*1.d-2
	dr_s=dr*1.d-2
	dz_s=dz*1.d-2

	     call bpol3(rr1_s,zz1_s,dr_s,dz_s,
     *  rr_s,zz_s,brs,bzs)

	brs=brs*1.d4
	bzs=bzs*1.d4
	
	br_pf=brs
	bz_pf=bzs

	return
	end
