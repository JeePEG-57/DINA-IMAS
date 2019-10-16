!        include 'tmp/declar.fml'
!        include 'tmp/declar.fnc'               
        double precision	
     1	NE(NRD),NHYDR(NRD),NDEUT(NRD),NTRIT(NRD),NHE3(NRD),
     2	NALF(NRD),NI(NRD),NIZ1(NRD),NIZ2(NRD),NIZ3(NRD),
     3	ZIM1(NRD),ZIM2(NRD),ZIM3(NRD),TE(NRD),TI(NRD),
     4	VR(NRD),SHIF(NRD), SHIV(NRD), ELON(NRD), TRIA(NRD),
     5  AMETR(NRD),RHO(NRD),FP(NRD),MU(NRD),AMAIN(NRD),ZMAIN(NRD),
     6	NIBM(NRD),SNEBM(NRD),SNNBM(NRD),ZEF(NRD),PBEAM(NRD),PFUS(NRD),
     7  F0(NRD),F1(NRD),F2(NRD),F3(NRD),F4(NRD),
     8  F5(NRD),F6(NRD),F7(NRD),F8(NRD),F9(NRD),
     7  F0F(NRD),F1F(NRD),F2F(NRD),F3F(NRD),F4F(NRD),
     8  F5F(NRD),F6F(NRD),F7F(NRD),F8F(NRD),F9F(NRD),
     7  SF0(NRD),SF1(NRD),SF2(NRD),SF3(NRD),SF4(NRD),
     8  SF5(NRD),SF6(NRD),SF7(NRD),SF8(NRD),SF9(NRD),SN(NRD),SNN(NRD),
     7  SF0F(NRD),SF1F(NRD),SF2F(NRD),SF3F(NRD),SF4F(NRD),
     8  SF5F(NRD),SF6F(NRD),SF7F(NRD),SF8F(NRD),SF9F(NRD),
     7  SFF0(NRD),SFF1(NRD),SFF2(NRD),SFF3(NRD),SFF4(NRD),
     8  SFF5(NRD),SFF6(NRD),SFF7(NRD),SFF8(NRD),SFF9(NRD),
     9	NNBM1(NRD),NNBM2(NRD),NNBM3(NRD),NN(NRD),TN(NRD),VOLUM(NRD)
        double precision
     2  NNCL,NNWM,ENCL,ENWM,
     7  F0B,F1B,F2B,F3B,F4B,
     8  F5B,F6B,F7B,F8B,F9B,TEB,TIB,
     3	BTOR,RTOR,ABC,AB,ROC,SHIFT,UPDWN,CNBI4,
     4	HRO,HROA,TAU,AIM1,AIM2,AIM3,AMJ,ZMJ,ABEAM,EBEAM,
     5  ELONG,TRIAN,IPL,TIME,ALBPL,GP
C The length of WORK1 is set accordingly to NEUT
!	double precision	WORK1(NRD,2*NRD+7),WORK(NRD,2*NRD)
	integer NA1,NB1,NAB,NA,NNCX
C Any allowed control parameters can be used below
        common /srs_IMAS/
     1	NE,NHYDR,NDEUT,NTRIT,NHE3,
     2	NALF,NI,NIZ1,NIZ2,NIZ3,
     3	ZIM1,ZIM2,ZIM3,TE,TI,
     4	VR,SHIF, SHIV, ELON, TRIA,
     5  AMETR,RHO,FP,MU,AMAIN,ZMAIN,
     6	NIBM,SNEBM,SNNBM,ZEF,PBEAM,PFUS,
     7  F0,F1,F2,F3,F4,			!F0-F9 = thermal particles densities (in ASTRA)
     8  F5,F6,F7,F8,F9,
     7  F0F,F1F,F2F,F3F,F4F,		!F0F-F9F = fast for F0-F9 particles densities (not in ASTRA)
     8  F5F,F6F,F7F,F8F,F9F,
     7  F0B,F1B,F2B,F3B,F4B,
     8  F5B,F6B,F7B,F8B,F9B,TEB,TIB,
     7  SF0,SF1,SF2,SF3,SF4,		!SF0-SF9 = explicit part of thermal particles sources (in ASTRA)
     8  SF5,SF6,SF7,SF8,SF9,SN,SNN,
     7  SFF0,SFF1,SFF2,SFF3,SFF4,	!SFF0-SFF9 = implicit part of thermal particles sources (in ASTRA)
     8  SFF5,SFF6,SFF7,SFF8,SFF9,
     7  SF0F,SF1F,SF2F,SF3F,SF4F,	!SF0F-SF9F = explicit part of thermal particles sources (not in ASTRA)
     8  SF5F,SF6F,SF7F,SF8F,SF9F,
     9	NNBM1,NNBM2,NNBM3,NN,TN,
     2  NNCL,NNWM,ENCL,ENWM,VOLUM,
     3	BTOR,RTOR,ABC,AB,ROC,SHIFT,UPDWN,CNBI4,
     4	HRO,HROA,TAU,NA1,NB1,AIM1,AIM2,AIM3,AMJ,ZMJ,
     5  ELONG,TRIAN,IPL,ABEAM,EBEAM,GP    


