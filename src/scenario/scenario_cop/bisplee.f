	subroutine boxde_1(urr,vrr,c00,c10,c01,c11,ij,i1j,ij1,i1j1)
	include 'double.inc'
	include 'parf2'
	include 'parf2e'
        common
     *  /ge5/kpr
	common
     *	/fluxc10/x1,y1,dx1,dy1

c Locate the grid square, zero-based.
	ri= (URR-x1)*dx1
	zj= (VRR-y1)*dy1
c Get t and u
	ii=aint(ri)
	jj=aint(zj)
	tt=ri-ii
	uu=zj-jj
c	type *,'i,j,t,u',i,j,t,u
c Convert to 1-base arrays
	ii=ii+1
	jj=jj+1
c Calculate the 4 coefficients.
c	c00=(1.-tt)*(1.-uu)=1.-tt-uu+tt*uu
c	c10=tt*(1.-uu)=tt-tt*uu
c	c01=(1.-tt)*uu=uu-tt*uu
c	c11=tt*uu
c------------------------
	c11=tt*uu
	c00=(1.-tt-uu+c11)
	c10=tt-c11
	c01=uu-c11

c Loop through the coils.
c---------------------
c---
c	fint=c00*psi(ii,jj) + c10*psi(ii+1,jj) +
c     *  c01*psi(ii,jj+1)+ c11*psi(ii+1,jj+1)

	ij=(ii-1)*nze+jj
	i1j=ij+nze
	ij1=ij+1
	i1j1=i1j+1


	if(i1j.gt.nwnhe)i1j=nwnhe
	if(ij1.gt.nwnhe)ij1=nwnhe
	if(i1j1.gt.nwnhe)i1j1=nwnhe

	return
	end


