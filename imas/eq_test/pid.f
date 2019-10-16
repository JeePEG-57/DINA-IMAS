      subroutine pid()

	include 'double.inc'
      include 'new_com.inc'

       call pid_c(
     * tt,tay,tau_p,tau_i,tau_d,
     * ECOIL_GP,ECOIL_GD,ECOIL_GI,
     * E_inp,P_out)
       
       return
       end

       subroutine pid_c(
     * tt,tay,tau_p,tau_i,tau_d,
     * g_p,g_d,g_i,
     * E,P)

	include 'double.inc'

c	PID calculation
c	--------------- 

c   	This calculation operates on the error vector computed in the
c   	PCS. 
c   	The result is stored in the "P-vector" for further processing.
c	In certain   cases, the only further processing is to send 
c	these values to the D/A.

c  	Parameters defining calculation:  
c   	G_p = proportional error gain
c   	G_d = derivative error gain
c	G_i = integral error gain
c	tau_p = proportional error time constant
c	tau_d = derivative error time constant
c	tau_i = integral error time constant

c     Algorithm:
c     The input error vector value is referred to here as E.
c     The results from the previous cycle are also used as input.
c     These values are referred to here as E1, V1, D1, and I1. 
c------------
      real L1,L2
      real L3,L4
      real L5,L6
      real I1,I
c--------------

c  dt is the time delay since the last data sample.
      dt=tay

      if(kpr.eq.1)print *,' tt tt1 dt',tt,tt1,dt

      i_en=i_en+1
      if(tt.gt.tt1+tay*0.1.or.i_en.eq.1)then

c     E1=E(t-dt)
c     V1=V(t-dt)
c     D1=D(t-dt)
c     I1=I(t-dt)
         if(kpr.eq.1)print *,' New Entrance...'
         if(kpr.eq.1)print *,' tt tt1 dt',tt,tt1,dt

         E1=E
         V1=V
         D1=D
         I1=I
         tt1=tt
         if(kpr.eq.1)print *,' e1 v1 d1 i1 tt1',e1,v1,d1,i1,tt1
      end if



      if(tau_p.gt.1.e-6)then

      qqp= dt/(2.*tau_p)
      L1=qqp/(qqp+1.)
      L2=(qqp-1.)/(qqp+1.)

c     tau_p is the time constant for the low pass filter.

      end if

      if(tau_d.gt.1.e-6)then

      qqd=dt/(2*tau_d)
      L3=1./(qqd+1.)
      L4=(qqd-1.)/(qqd+1.)

      end if

c     tau_d is the time constant for the differentiation..

      if(tau_i.gt.1.e-6)then

      qqi=dt/(2.*tau_i)
      L5=qqi/(qqi+1.)
      L6=(qqi-1.)/(qqi+1.)

      end if

c     tau_i is the time constant for the integration.



c     NOTE that the effective derivative gain is actually G_d*tau_d and the
c     effective integral gain is G_i/tau_i.

c     ECOIL_GP    = proportional error gain
c     ECOIL_GD/GP = derivative error gain divided by proportional error gain
c     ECOIL_GI/GP = integral error gain divided by proportional error gain



c     The following calculation is done:

c      V(t) = L1 * E(t) + L1 * E(t-dt) - L2 * V(t-dt)
c      D(t) = L3 * V(t) - (L3 * V(t-dt) + L4 * D(t-dt))
c      I(t) = L5 * V(t) + L5 * V(t-dt) - L6 * I(t-dt)
c      P = G_p * V(t) + G_d * D(t) + G_i * I(t) is stored in the P-vector.


      V = L1 * E + L1 * E1 - L2 * V1
      D = L3 * V - (L3 * V1 + L4 * D1)
      I = L5 * V + L5 * V1 - L6 * I1
      P = G_p* V + G_d * D + G_i * I

c-- convert to Volts
      p=20./4096*p

      return
      end
      




