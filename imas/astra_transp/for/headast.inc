C======================================================================|
!	program  astra
!!prescription of plasma boundary: Polevoi 28-NOV-2009
! start of stepon
C----------------------------------------------------------------------|
	implicit double precision (a-h,o-z)
	include	'for/parameter.inc'
	include	'for/const.inc'	
	include	'for/status.inc'
	include	'for/outcmn.inc'
	include	'for/timeoutput.inc'
	include	'tmp/declar.fml'
	include	'tmp/declar.fnc'
	include	'tmp/declar.usr'
	integer getpid,J,IFKEY,IFIPC,JIT,JEX,JDETV,JCALL,ND,ND1,IPART
	integer	IFSBP(NSBMX)
	double precision YWA(NRD),YWB(NRD),YWC(NRD),YWD(NRD),ARRNA1
C	double precision NE1(NRD),TE1(NRD),TI1(NRD)
	double precision YA,YB,YC,YD,YE,YF,YG,YI,YM,YJ,YU,YYD,YCU
	double precision YMF,YHC,YFP0
	data	JEX/1/ JIT/0/ IPART/0/
C----------------------------------------------------------------------|
