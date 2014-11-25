      subroutine fit(k,x1,x2,x3,x4,y1,y2,y3,y4,x,y,yp)
	include 'double_fit.inc'
c       implicit real *8 (a-h,o-z)
c --------------------------------------------
c set k=1 to find y,yp and k=2 to find x,yp
c --------------------------------------------
      iturn=0
      c1=y1/((x1-x2)*(x1-x3)*(x1-x4))
      c2=y2/((x2-x1)*(x2-x3)*(x2-x4))
      c3=y3/((x3-x1)*(x3-x2)*(x3-x4))
      c4=y4/((x4-x1)*(x4-x2)*(x4-x3))

	iter=0

      if(k.eq.2) go to 2
   1  continue
	iter=iter+1
	if(iter.gt.100000)then
	if(kpr.eq.1)print *,'iterations to much',iter
	return
	stop
	end if
c
      d1=x-x1
      d2=x-x2
      d3=x-x3
      d4=x-x4
      d12=d1*d2
      d13=d1*d3
      d14=d1*d4
      d23=d2*d3
      d24=d2*d4
      d34=d3*d4
      f=(c1*d23+c2*d13+c3*d12)*d4+c4*d12*d3
      yp=c1*(d23+d24+d34)+c2*(d13+d14+d34)
     +  +c3*(d12+d14+d24)+c4*(d12+d13+d23)
      if(k.eq.2) go to 3
      y=f
      return
    2 if(y.ge.amin1(y1,y2,y3,y4).and.y.le.amax1(y1,y2,y3,y4)) go to 4
   21 continue
      write(59,11)x1,x2,x3,x4,y1,y2,y3,y4,y
      x=0.
      write(59,500)
  500 format('error in sub fit at label 21')
c      call abort(4hfit1,8)
      return
  11  format(' fit',9e14.5)
   4  crit=(abs(y1)+abs(y2)+abs(y3)+abs(y4))*1.e-05
      i=0
      xa=x1
      xb=x2
      ya=y1
      yb=y2
      if((x-xa)*(x-xb).lt.0.) go to 10
      xa=x2
      xb=x3
      ya=y2
      yb=y3
      if((x-xa)*(x-xb).lt.0.) go to 10
      xa=x3
      xb=x4
      ya=y3
      yb=y4
      if((x-xa)*(x-xb).lt.0.) go to 10
  12  xa=x2
      ya=y2
      xb=x3
      yb=y3
      x=(xa+xb)/2.
      if((y-ya)*(y-yb).lt.0.) go to 1
      xa=x1
      ya=y1
      xb=x2
      yb=y2
      x=(xa+xb)/2.
      if((y-ya)*(y-yb).lt.0.) go to 1
      xa=x3
      ya=y3
      xb=x4
      yb=y4
      x=(xa+xb)/2.
      if((y-ya)*(y-yb).lt.0.) go to 1
      if(y.ne.y1) go to 13
      x=x1
      go to 1
   13 if(y.ne.y2) go to 14
      x=x2
      go to 1
   14 if(y.ne.y3) go to 15
      x=x3
      go to 1
   15 if(y.ne.y4) go to 16
      x=x4
      go to 1
   16 continue
      write(59,11)x,y
      go to 21
3     if(abs(f-y).lt.crit) iturn=1
      if(i.eq.1) go to 7
      dydx=(yb-ya)/(xb-xa)
      if(abs(yp-dydx).lt..2*abs(yp)) go to 7
      if((f-y)*(ya-y).lt.0.) go to 5
      xa=x
      ya=f
      go to 6
   5  xb=x
      yb=f
   6  x=(xa+xb)/2.
      i=1
      go to 1
    7 if((f-y)*(ya-y).lt.0.) go to 8
      xa=x
      ya=f
      go to 9
   8  xb=x
      yb=f
   9  dydx=(yb-ya)/(xb-xa)
      if(abs(yp-dydx).lt..2*abs(yp))dydx=yp
      if(abs(dydx).lt.1.e-8)return
      x=x-(f-y)/dydx
      if(iturn.eq.1) return
      i=0
      go to 1
   10 if((y-ya)*(y-yb).lt.0.) go to 1
      go to 12
      end
      subroutine cubic(p1,p2,p3,p4,p,a,b,c,d)
      include 'double.inc'
      data  zero/1.e-6/
      p1p2=p1-p2
      k12=sign(1.5d0,p1p2)
      if(abs(p1p2).lt.zero) go to 1
      p2p3=p2-p3
      k23=sign(1.5d0,p2p3)
      if(abs(p2p3).lt.zero) go to 2
      p1p3=p1-p3
      if(abs(p1p3).lt.zero) go to 1
      p1p4=p1-p4
      if (abs(p1p4).lt.zero) go to 3
      p2p4=p2-p4
      if (abs(p2p4).lt.zero) go to 4
      p3p4=p3-p4
      k34=sign(1.5d0,p3p4)
      if(abs(p3p4).lt.zero) go to 4
      if (iabs(k12+k23+k34).eq.3)  go to 5
      if (iabs(k23+k34).eq.2) go to 1
      if (iabs(k12+k23).eq.2) go to 4
5     pp1=p-p1
      pp2=p-p2
      pp3=p-p3
      pp4=p-p4
      a=pp2*pp3*pp4/(p1p2*p1p3*p1p4)
      b=-pp1*pp3*pp4/(p1p2*p2p3*p2p4)
      c=pp1*pp2*pp4/(p1p3*p2p3*p3p4)
      d=-pp1*pp2*pp3/(p1p4*p2p4*p3p4)
      return
1     a=0.
c      call parab(p2,p3,p4,p,b,c,d)
      return
2     a=0.
      b=1.
      c=0.
      d=0.
      return
3     if (iabs(k12+k23).eq.2) go to 4
      go to 1
4     d=0.
c      call parab(p1,p2,p3,p,a,b,c)
      return
      end




