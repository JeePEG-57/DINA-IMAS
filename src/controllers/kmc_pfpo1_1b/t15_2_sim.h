/*
 * File: t15_2.h
 *
 * Code generated for Simulink model 't15_2'.
 *
 * Model version                  : 1.1146
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue May 21 20:17:37 2019
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_t15_2_h_
#define RTW_HEADER_t15_2_h_
#ifndef t15_2_COMMON_INCLUDES_
# define t15_2_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* t15_2_COMMON_INCLUDES_ */

#include "t15_2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T SFunction1[6500];             /* '<S5>/S-Function1' */
  real_T SFunction2[10000];            /* '<S5>/S-Function2' */
  real_T e3;                           /* '<S5>/1e-3' */
  real_T Memory2;                      /* '<S5>/Memory2' */
  real_T u;                            /* '<S5>/-1' */
  real_T Ip1e4;                        /* '<S5>/Ip<1e-4 ' */
  real_T DataStoreRead;                /* '<S5>/Data Store Read' */
  real_T Sum2;                         /* '<S5>/Sum2' */
  real_T e6;                           /* '<S14>/1e-6' */
  real_T e6_m[15];                     /* '<S14>/1e-6   ' */
  real_T Memory2_k;                    /* '<S23>/Memory2' */
  real_T Add3;                         /* '<S23>/Add3' */
  real_T DataStoreRead1;               /* '<S23>/Data Store Read1' */
  real_T e3_k;                         /* '<S23>/1e-3' */
  real_T Product1;                     /* '<S23>/Product1' */
  real_T RelationalOperator;           /* '<S23>/Relational Operator' */
  real_T Memory1;                      /* '<S23>/Memory1' */
  real_T u99;                          /* '<S23>/0.999' */
  real_T Add2;                         /* '<S23>/Add2' */
  real_T DataStoreRead_o;              /* '<S23>/Data Store Read' */
  real_T Product;                      /* '<S23>/Product' */
  real_T Add1;                         /* '<S23>/Add1' */
  real_T u_n;                          /* '<S23>/1 0' */
  real_T Memory1_j;                    /* '<S17>/Memory1' */
  real_T c_eob;                        /* '<S17>/c_eob' */
  real_T Divide6;                      /* '<S17>/Divide6' */
  real_T Add1_i;                       /* '<S14>/Add1' */
  real_T SFunction1_i[100];            /* '<S19>/S-Function1' */
  real_T Uk1;                          /* '<S24>/UD' */
  real_T Uk1_d;                        /* '<S25>/UD' */
  real_T Memory2_f;                    /* '<S29>/Memory2' */
  real_T c_eob_b;                      /* '<S29>/c_eob' */
  real_T Divide1;                      /* '<S29>/Divide1' */
  real_T Add1_g;                       /* '<S20>/Add1' */
  real_T Memory2_k5;                   /* '<S27>/Memory2' */
  real_T c_eob_c;                      /* '<S27>/c_eob' */
  real_T Divide1_o;                    /* '<S27>/Divide1' */
  real_T Add10;                        /* '<S20>/Add10' */
  real_T Memory2_kw;                   /* '<S28>/Memory2' */
  real_T c_eob_h;                      /* '<S28>/c_eob' */
  real_T Divide1_n;                    /* '<S28>/Divide1' */
  real_T Add11;                        /* '<S20>/Add11' */
  real_T Memory2_o;                    /* '<S30>/Memory2' */
  real_T c_eob_e;                      /* '<S30>/c_eob' */
  real_T Divide1_h;                    /* '<S30>/Divide1' */
  real_T Add2_o;                       /* '<S20>/Add2' */
  real_T Memory2_b;                    /* '<S26>/Memory2' */
  real_T c_eob_cj;                     /* '<S26>/c_eob' */
  real_T Divide1_nq;                   /* '<S26>/Divide1' */
  real_T Add3_c;                       /* '<S20>/Add3' */
  real_T Memory2_d;                    /* '<S31>/Memory2' */
  real_T c_eob_k;                      /* '<S31>/c_eob' */
  real_T Divide1_p;                    /* '<S31>/Divide1' */
  real_T Add4;                         /* '<S20>/Add4' */
  real_T Memory2_p;                    /* '<S32>/Memory2' */
  real_T c_eob_g;                      /* '<S32>/c_eob' */
  real_T Divide1_l;                    /* '<S32>/Divide1' */
  real_T Add5;                         /* '<S20>/Add5' */
  real_T Memory2_dq;                   /* '<S33>/Memory2' */
  real_T c_eob_l;                      /* '<S33>/c_eob' */
  real_T Divide1_e;                    /* '<S33>/Divide1' */
  real_T Add6;                         /* '<S20>/Add6' */
  real_T Memory2_e;                    /* '<S34>/Memory2' */
  real_T c_eob_g0;                     /* '<S34>/c_eob' */
  real_T Divide1_f;                    /* '<S34>/Divide1' */
  real_T Add7;                         /* '<S20>/Add7' */
  real_T Memory2_j;                    /* '<S35>/Memory2' */
  real_T c_eob_bz;                     /* '<S35>/c_eob' */
  real_T Divide1_hq;                   /* '<S35>/Divide1' */
  real_T Add8;                         /* '<S20>/Add8' */
  real_T Memory2_a;                    /* '<S36>/Memory2' */
  real_T c_eob_j;                      /* '<S36>/c_eob' */
  real_T Divide1_d;                    /* '<S36>/Divide1' */
  real_T Add9;                         /* '<S20>/Add9' */
  real_T Sum2_b;                       /* '<S16>/Sum2' */
  real_T u_p;                          /* '<S16>/>=0' */
  real_T e2[6];                        /* '<S21>/1e2' */
  real_T SFunction1_o[100];            /* '<S42>/S-Function1' */
  real_T Memory2_da;                   /* '<S42>/Memory2' */
  real_T c_eob1;                       /* '<S42>/c_eob  1' */
  real_T Memory1_i;                    /* '<S42>/Memory1' */
  real_T c_eob_ej;                     /* '<S42>/c_eob  ' */
  real_T SFunction1_p[100];            /* '<S48>/S-Function1' */
  real_T c_eob_jd;                     /* '<S42>/c_eob' */
  real_T Add2_b;                       /* '<S21>/Add2' */
  real_T LookupTable1;                 /* '<S21>/Lookup Table1' */
  real_T Divide6_d;                    /* '<S21>/Divide6' */
  real_T SFunction1_f[100];            /* '<S37>/S-Function1' */
  real_T Memory2_i;                    /* '<S37>/Memory2' */
  real_T c_eob1_b;                     /* '<S37>/c_eob  1' */
  real_T Memory1_g;                    /* '<S37>/Memory1' */
  real_T c_eob_n;                      /* '<S37>/c_eob  ' */
  real_T SFunction1_f2[100];           /* '<S43>/S-Function1' */
  real_T c_eob_kt;                     /* '<S37>/c_eob' */
  real_T Add1_ia;                      /* '<S21>/Add1' */
  real_T LookupTable2;                 /* '<S21>/Lookup Table2' */
  real_T Divide1_a;                    /* '<S21>/Divide1' */
  real_T SFunction1_e[100];            /* '<S38>/S-Function1' */
  real_T Memory2_n;                    /* '<S38>/Memory2' */
  real_T c_eob1_i;                     /* '<S38>/c_eob  1' */
  real_T Memory1_jo;                   /* '<S38>/Memory1' */
  real_T c_eob_lg;                     /* '<S38>/c_eob  ' */
  real_T SFunction1_h[100];            /* '<S44>/S-Function1' */
  real_T c_eob_lu;                     /* '<S38>/c_eob' */
  real_T Add3_a;                       /* '<S21>/Add3' */
  real_T SFunction1_fd[100];           /* '<S39>/S-Function1' */
  real_T Memory2_l;                    /* '<S39>/Memory2' */
  real_T c_eob1_d;                     /* '<S39>/c_eob  1' */
  real_T Memory1_e;                    /* '<S39>/Memory1' */
  real_T c_eob_c2;                     /* '<S39>/c_eob  ' */
  real_T SFunction1_o5[100];           /* '<S45>/S-Function1' */
  real_T c_eob_p;                      /* '<S39>/c_eob' */
  real_T Add4_i;                       /* '<S21>/Add4' */
  real_T LookupTable3;                 /* '<S21>/Lookup Table3' */
  real_T Divide2;                      /* '<S21>/Divide2' */
  real_T SFunction1_n[100];            /* '<S40>/S-Function1' */
  real_T Memory2_m;                    /* '<S40>/Memory2' */
  real_T c_eob1_c;                     /* '<S40>/c_eob  1' */
  real_T Memory1_b;                    /* '<S40>/Memory1' */
  real_T c_eob_nk;                     /* '<S40>/c_eob  ' */
  real_T SFunction1_a[100];            /* '<S46>/S-Function1' */
  real_T c_eob_cy;                     /* '<S40>/c_eob' */
  real_T Add5_n;                       /* '<S21>/Add5' */
  real_T SFunction1_p1[100];           /* '<S41>/S-Function1' */
  real_T Memory2_j1;                   /* '<S41>/Memory2' */
  real_T c_eob1_g;                     /* '<S41>/c_eob  1' */
  real_T Memory1_g3;                   /* '<S41>/Memory1' */
  real_T c_eob_be;                     /* '<S41>/c_eob  ' */
  real_T SFunction1_c[100];            /* '<S47>/S-Function1' */
  real_T c_eob_c3;                     /* '<S41>/c_eob' */
  real_T Add6_b;                       /* '<S21>/Add6' */
  real_T e2_n[6];                      /* '<S21>/1e-2' */
  real_T DataStoreRead_or;             /* '<S22>/Data Store Read' */
  real_T LogicalOperator1;             /* '<S22>/Logical Operator1' */
  real_T u9[20];                       /* '<S22>/0.99' */
  real_T e6_i;                         /* '<S23>/1e6' */
  real_T Memory3;                      /* '<S50>/Memory3' */
  real_T DataStoreRead_f;              /* '<S67>/Data Store Read' */
  real_T LogicalOperator1_h;           /* '<S50>/Logical Operator1' */
  real_T u999;                         /* '<S50>/0.9999' */
  real_T Subtract2;                    /* '<S50>/Subtract2' */
  real_T Gain1;                        /* '<S50>/Gain1' */
  real_T Subtract1;                    /* '<S50>/Subtract1' */
  real_T Saturation1;                  /* '<S50>/Saturation1' */
  real_T Memory1_a;                    /* '<S51>/Memory1' */
  real_T DataStoreRead_l;              /* '<S68>/Data Store Read' */
  real_T Abs;                          /* '<S68>/Abs' */
  real_T DataStoreRead_i;              /* '<S69>/Data Store Read' */
  real_T LogicalOperator2;             /* '<S51>/Logical Operator2' */
  real_T u999_d;                       /* '<S51>/0.9999' */
  real_T Subtract2_h;                  /* '<S51>/Subtract2' */
  real_T Gain1_j;                      /* '<S51>/Gain1' */
  real_T Subtract3;                    /* '<S51>/Subtract3' */
  real_T Saturation;                   /* '<S51>/Saturation' */
  real_T Subtract1_k;                  /* '<S51>/Subtract1' */
  real_T Subtract4;                    /* '<S51>/Subtract4' */
  real_T e3_h[11];                     /* '<S52>/1e3' */
  real_T Abs_a[11];                    /* '<S52>/Abs' */
  real_T DataStoreRead1_k[11];         /* '<S15>/Data Store Read1' */
  real_T Divide5[11];                  /* '<S52>/Divide5' */
  real_T Sum2_k[11];                   /* '<S52>/Sum2' */
  real_T DataStoreRead1_kb;            /* '<S52>/Data Store Read1' */
  real_T Divide3[11];                  /* '<S52>/Divide3' */
  real_T Sum1[11];                     /* '<S52>/Sum1' */
  real_T Divide4[11];                  /* '<S52>/Divide4' */
  real_T Divide1_ps[11];               /* '<S52>/Divide1' */
  real_T Saturation_k[11];             /* '<S52>/Saturation' */
  real_T Memory1_k[11];                /* '<S60>/Memory1' */
  real_T DataStoreRead_ln;             /* '<S60>/Data Store Read' */
  real_T Abs_c;                        /* '<S60>/Abs' */
  real_T DataStoreRead1_f;             /* '<S60>/Data Store Read1' */
  real_T LogicalOperator2_g;           /* '<S60>/Logical Operator2' */
  real_T Memory[11];                   /* '<S63>/Memory' */
  real_T DataStoreRead_j;              /* '<S77>/Data Store Read' */
  real_T DataStoreRead1_p;             /* '<S63>/Data Store Read1' */
  real_T Abs_e;                        /* '<S63>/Abs' */
  real_T LogicalOperator1_i;           /* '<S63>/Logical Operator1' */
  real_T Divide2_b[20];                /* '<S15>/Divide2' */
  real_T Divcontr[11];                 /* '<S54>/Div. contr.' */
  real_T u9_b[11];                     /* '<S63>/0.99' */
  real_T Memory1_ec;                   /* '<S62>/Memory1' */
  real_T DataStoreRead_p;              /* '<S75>/Data Store Read' */
  real_T LogicalOperator1_a;           /* '<S62>/Logical Operator1' */
  real_T u999_b;                       /* '<S62>/0.9999' */
  real_T Divide13[20];                 /* '<S15>/Divide13' */
  real_T Div_rdcontr[11];              /* '<S55>/Div_rd contr' */
  real_T Memory1_l;                    /* '<S59>/Memory1' */
  real_T c_eob_e3;                     /* '<S59>/c_eob' */
  real_T u99_i[11];                    /* '<S60>/0.999' */
  real_T Divide4_p[11];                /* '<S15>/Divide4' */
  real_T Currtermcontr[11];            /* '<S53>/Curr. term. contr' */
  real_T Divide5_p[11];                /* '<S15>/Divide5' */
  real_T Memory2_kr[11];               /* '<S56>/Memory2' */
  real_T tcont2[20];                   /* '<S56>/tcont2 ' */
  real_T Limcontr[11];                 /* '<S56>/Lim. contr.' */
  real_T Currcontr[11];                /* '<S56>/Curr. contr.' */
  real_T IpIp_div[11];                 /* '<S56>/Ip>Ip_div ' */
  real_T Divide6_l[11];                /* '<S15>/Divide6' */
  real_T DataStoreRead_p1[500];        /* '<S80>/Data Store Read' */
  real_T u01[500];                     /* '<S80>/0.001' */
  real_T DataStoreRead1_d[500];        /* '<S80>/Data Store Read1' */
  real_T volt1;                        /* '<S80>/volt1' */
  real_T DataStoreRead_a[500];         /* '<S83>/Data Store Read' */
  real_T u01_o[500];                   /* '<S83>/0.001' */
  real_T DataStoreRead1_c[500];        /* '<S83>/Data Store Read1' */
  real_T volt1_b;                      /* '<S83>/volt1' */
  real_T DataStoreRead_i1[500];        /* '<S84>/Data Store Read' */
  real_T u01_g[500];                   /* '<S84>/0.001' */
  real_T DataStoreRead1_b[500];        /* '<S84>/Data Store Read1' */
  real_T volt1_i;                      /* '<S84>/volt1' */
  real_T DataStoreRead_i2[500];        /* '<S85>/Data Store Read' */
  real_T u01_b[500];                   /* '<S85>/0.001' */
  real_T DataStoreRead1_e[500];        /* '<S85>/Data Store Read1' */
  real_T volt1_o;                      /* '<S85>/volt1' */
  real_T DataStoreRead_n[500];         /* '<S86>/Data Store Read' */
  real_T u01_h[500];                   /* '<S86>/0.001' */
  real_T DataStoreRead1_pd[500];       /* '<S86>/Data Store Read1' */
  real_T volt1_d;                      /* '<S86>/volt1' */
  real_T DataStoreRead_oy[500];        /* '<S87>/Data Store Read' */
  real_T u01_f[500];                   /* '<S87>/0.001' */
  real_T DataStoreRead1_m[500];        /* '<S87>/Data Store Read1' */
  real_T volt1_m;                      /* '<S87>/volt1' */
  real_T DataStoreRead_e[500];         /* '<S88>/Data Store Read' */
  real_T u01_b3[500];                  /* '<S88>/0.001' */
  real_T DataStoreRead1_ee[500];       /* '<S88>/Data Store Read1' */
  real_T volt1_j;                      /* '<S88>/volt1' */
  real_T DataStoreRead_g[500];         /* '<S89>/Data Store Read' */
  real_T u01_bc[500];                  /* '<S89>/0.001' */
  real_T DataStoreRead1_cn[500];       /* '<S89>/Data Store Read1' */
  real_T volt1_b2;                     /* '<S89>/volt1' */
  real_T DataStoreRead_f3[500];        /* '<S90>/Data Store Read' */
  real_T u01_l[500];                   /* '<S90>/0.001' */
  real_T DataStoreRead1_fq[500];       /* '<S90>/Data Store Read1' */
  real_T volt1_ia;                     /* '<S90>/volt1' */
  real_T DataStoreRead_ou[500];        /* '<S81>/Data Store Read' */
  real_T u01_e[500];                   /* '<S81>/0.001' */
  real_T DataStoreRead1_dy[500];       /* '<S81>/Data Store Read1' */
  real_T volt1_a;                      /* '<S81>/volt1' */
  real_T DataStoreRead_fr[500];        /* '<S82>/Data Store Read' */
  real_T u01_f1[500];                  /* '<S82>/0.001' */
  real_T DataStoreRead1_n[500];        /* '<S82>/Data Store Read1' */
  real_T volt1_e;                      /* '<S82>/volt1' */
  real_T Divide7[11];                  /* '<S15>/Divide7' */
  real_T Sum3[11];                     /* '<S15>/Sum3' */
  real_T Divide2_j[11];                /* '<S52>/Divide2' */
  real_T Sum3_b[11];                   /* '<S52>/Sum3' */
  real_T Saturation1_g[11];            /* '<S52>/Saturation1' */
  real_T Divide6_f[11];                /* '<S52>/Divide6' */
  real_T UniformRandomNumber;          /* '<S61>/Uniform Random Number' */
  real_T Uk1_m;                        /* '<S73>/UD' */
  real_T tt_tran2d[2];                 /* '<S15>/t>t_tran2d' */
  real_T VScontr[2];                   /* '<S57>/VS. contr' */
  real_T RelationalOperator_g;         /* '<S57>/Relational Operator' */
  real_T Divide4_j[2];                 /* '<S57>/Divide4' */
  real_T VScontrhl[2];                 /* '<S57>/VS. contr hl' */
  real_T c_eob_ku[2];                  /* '<S57>/c_eob' */
  real_T DataStoreRead_gb;             /* '<S79>/Data Store Read' */
  real_T DataStoreRead_b;              /* '<S64>/Data Store Read' */
  real_T Abs_l;                        /* '<S64>/Abs' */
  real_T LogicalOperator1_k;           /* '<S64>/Logical Operator1' */
  real_T atpl115;                      /* '<S58>/atpl1//15' */
  real_T u9_o[2];                      /* '<S64>/0.99' */
  real_T Divide10[2];                  /* '<S15>/Divide10' */
  real_T Divide12[20];                 /* '<S15>/Divide12' */
  real_T Divide1_j[11];                /* '<S56>/Divide 1' */
  real_T Divide4_f[11];                /* '<S5>/Divide4' */
  real_T SFunction[32];                /* '<S1>/S-Function' */
  real_T DataStoreRead1_kx[11];        /* '<S9>/Data Store Read1' */
  real_T Memory1_ek[11];               /* '<S7>/Memory1' */
  real_T DataStoreRead1_o[11];         /* '<S8>/Data Store Read1' */
  real_T u_j[11];                      /* '<S8>/2' */
  real_T DataStoreRead3;               /* '<S8>/Data Store Read3' */
  real_T Divide1_o5[11];               /* '<S8>/Divide1' */
  real_T Add1_gy[11];                  /* '<S7>/Add1' */
  real_T Uk1_l;                        /* '<S6>/UD' */
  real_T Diff;                         /* '<S6>/Diff' */
  real_T Divide[11];                   /* '<S7>/Divide' */
  real_T u_e[11];                      /* '<S8>/-1' */
  real_T Switch[11];                   /* '<S10>/Switch' */
  real_T Switch2[11];                  /* '<S10>/Switch2' */
  real_T Divide1_k[11];                /* '<S7>/Divide1' */
  real_T Add2_n[11];                   /* '<S7>/Add2' */
  real_T Gain[11];                     /* '<S9>/Gain' */
  real_T Switch_l[11];                 /* '<S11>/Switch' */
  real_T Switch2_c[11];                /* '<S11>/Switch2' */
  real_T ntur[11];                     /* '<S2>/1//ntur' */
  real_T DataStoreRead1_j;             /* '<S4>/Data Store Read1' */
  real_T Switch2_h;                    /* '<S12>/Switch2' */
  real_T DataStoreRead3_a;             /* '<S4>/Data Store Read3' */
  real_T Switch2_f;                    /* '<S13>/Switch2' */
  real_T TmpSignalConversionAtwzInport1[2];
  real_T wz[12];                       /* '<S2>/wz' */
  real_T Add1_k[11];                   /* '<S2>/Add1' */
  real_T TmpSignalConversionAtnpf12Inpor[12];
  real_T npf12[15];                    /* '<S2>/npf,12' */
  real_T VSgain3;                      /* '<S15>/VS gain 3' */
  real_T Saturation4;                  /* '<S15>/Saturation4' */
  real_T Divide11[2];                  /* '<S15>/Divide11' */
  real_T c_eob_b4[2];                  /* '<S15>/c_eob ' */
  real_T IpIp_div_b;                   /* '<S58>/Ip>Ip_div' */
  real_T Divide8[2];                   /* '<S15>/Divide8' */
  real_T SatDiv;                       /* '<S58>/Sat. Div' */
  real_T SatLim;                       /* '<S58>/Sat. Lim' */
  real_T VSgain2;                      /* '<S15>/VS gain 2' */
  real_T Saturation3;                  /* '<S15>/Saturation3' */
  real_T Divide_g[2];                  /* '<S15>/Divide ' */
  real_T Subtract3_h;                  /* '<S50>/Subtract3' */
  real_T Divide_e[11];                 /* '<S15>/Divide' */
  real_T Subtract2_b;                  /* '<S62>/Subtract2' */
  real_T Gain1_l;                      /* '<S62>/Gain1' */
  real_T Subtract3_l;                  /* '<S62>/Subtract3' */
  real_T Saturation_i;                 /* '<S62>/Saturation' */
  real_T Subtract1_l;                  /* '<S62>/Subtract1' */
  real_T c_eob_bc;                     /* '<S15>/c_eob' */
  real_T Divide3_p[11];                /* '<S15>/Divide3' */
  real_T Divide1_jp[11];               /* '<S15>/Divide1' */
  real_T Sum2_h[11];                   /* '<S15>/Sum2' */
  real_T limgain;                      /* '<S15>/lim. gain' */
  real_T Saturation_b;                 /* '<S15>/Saturation' */
  real_T Divide6_c;                    /* '<S59>/Divide6' */
  real_T Sum;                          /* '<S59>/Sum' */
  real_T Divide2_n;                    /* '<S59>/Divide2' */
  real_T Sum1_a;                       /* '<S59>/Sum1' */
  real_T uy0;                          /* '<S59>/[1 y0]' */
  real_T DataStoreRead1_ph[500];       /* '<S59>/Data Store Read1' */
  real_T DataStoreRead_h[500];         /* '<S59>/Data Store Read' */
  real_T Ipref;                        /* '<S59>/Ipref' */
  real_T tcont2_a[11];                 /* '<S56>/tcont2' */
  real_T gain_cont2;                   /* '<S56>/gain_cont2' */
  real_T Divide_f[11];                 /* '<S56>/Divide ' */
  real_T Divide2_a[11];                /* '<S56>/Divide 2' */
  real_T Diff_f;                       /* '<S73>/Diff' */
  real_T e3_i;                         /* '<S72>/2e3' */
  real_T Sqrt;                         /* '<S72>/Sqrt' */
  real_T DataStoreRead_nz;             /* '<S72>/Data Store Read' */
  real_T u5;                           /* '<S72>/1.75' */
  real_T Divide11_d;                   /* '<S72>/Divide11' */
  real_T Divide1_g;                    /* '<S72>/Divide1' */
  real_T Diff_o;                       /* '<S25>/Diff' */
  real_T Diff_n;                       /* '<S24>/Diff' */
  real_T Divide_c;                     /* '<S18>/Divide' */
  real_T Sum2_e;                       /* '<S61>/Sum2' */
  real_T Selector[50];                 /* '<S19>/Selector' */
  real_T Selector1[50];                /* '<S19>/Selector1' */
  real_T elong;                        /* '<S19>/elong' */
  real_T Add2_m;                       /* '<S14>/Add2' */
  real_T k_gaplim[4];                  /* '<S14>/k_gaplim' */
  real_T Selector_k[49];               /* '<S48>/Selector' */
  real_T TmpSignalConversionAtg1_termref[50];
  real_T DataStoreRead_bi;             /* '<S48>/Data Store Read' */
  real_T Selector1_p[50];              /* '<S48>/Selector1' */
  real_T Divide6_f0[50];               /* '<S48>/Divide6' */
  real_T Add2_i[50];                   /* '<S48>/Add2' */
  real_T g1_termref;                   /* '<S48>/g1_term,ref' */
  real_T Selector_j[50];               /* '<S42>/Selector' */
  real_T Selector1_n[50];              /* '<S42>/Selector1' */
  real_T g1ref;                        /* '<S42>/g1ref' */
  real_T Selector_n[49];               /* '<S47>/Selector' */
  real_T TmpSignalConversionAtg6_termref[50];
  real_T DataStoreRead_ag;             /* '<S47>/Data Store Read' */
  real_T Selector1_no[50];             /* '<S47>/Selector1' */
  real_T Divide6_fz[50];               /* '<S47>/Divide6' */
  real_T Add2_no[50];                  /* '<S47>/Add2' */
  real_T g6_termref;                   /* '<S47>/g6_term,ref' */
  real_T Selector_j2[50];              /* '<S41>/Selector' */
  real_T Selector1_f[50];              /* '<S41>/Selector1' */
  real_T g6ref;                        /* '<S41>/g6ref' */
  real_T Selector_l[49];               /* '<S46>/Selector' */
  real_T TmpSignalConversionAtg5_termref[50];
  real_T DataStoreRead_c;              /* '<S46>/Data Store Read' */
  real_T Selector1_o[50];              /* '<S46>/Selector1' */
  real_T Divide6_i[50];                /* '<S46>/Divide6' */
  real_T Add2_bd[50];                  /* '<S46>/Add2' */
  real_T g5_termref;                   /* '<S46>/g5_term,ref' */
  real_T Selector_f[50];               /* '<S40>/Selector' */
  real_T Selector1_a[50];              /* '<S40>/Selector1' */
  real_T g5ref;                        /* '<S40>/g5ref' */
  real_T Selector_ns[49];              /* '<S45>/Selector' */
  real_T TmpSignalConversionAtg4_termref[50];
  real_T DataStoreRead_cj;             /* '<S45>/Data Store Read' */
  real_T Selector1_pz[50];             /* '<S45>/Selector1' */
  real_T Divide6_h[50];                /* '<S45>/Divide6' */
  real_T Add2_bw[50];                  /* '<S45>/Add2' */
  real_T g4_termref;                   /* '<S45>/g4_term,ref' */
  real_T Selector_d[50];               /* '<S39>/Selector' */
  real_T Selector1_ou[50];             /* '<S39>/Selector1' */
  real_T g4ref;                        /* '<S39>/g4ref' */
  real_T Selector_e[49];               /* '<S44>/Selector' */
  real_T TmpSignalConversionAtg3_termref[50];
  real_T DataStoreRead_n2;             /* '<S44>/Data Store Read' */
  real_T Selector1_c[50];              /* '<S44>/Selector1' */
  real_T Divide6_p[50];                /* '<S44>/Divide6' */
  real_T Add2_oa[50];                  /* '<S44>/Add2' */
  real_T g3_termref;                   /* '<S44>/g3_term,ref' */
  real_T Selector_g[50];               /* '<S38>/Selector' */
  real_T Selector1_nf[50];             /* '<S38>/Selector1' */
  real_T g3ref;                        /* '<S38>/g3ref' */
  real_T Selector_k4[49];              /* '<S43>/Selector' */
  real_T TmpSignalConversionAtg2_termref[50];
  real_T DataStoreRead_m;              /* '<S43>/Data Store Read' */
  real_T Selector1_d[50];              /* '<S43>/Selector1' */
  real_T Divide6_n[50];                /* '<S43>/Divide6' */
  real_T Add2_p[50];                   /* '<S43>/Add2' */
  real_T g2_termref;                   /* '<S43>/g2_term,ref' */
  real_T Selector_lh[50];              /* '<S37>/Selector' */
  real_T Selector1_ad[50];             /* '<S37>/Selector1' */
  real_T g2ref;                        /* '<S37>/g2ref' */
  real_T DataStoreRead1_cq[500];       /* '<S36>/Data Store Read1' */
  real_T DataStoreRead_cq[500];        /* '<S36>/Data Store Read' */
  real_T I1;                           /* '<S36>/I1' */
  real_T DataStoreRead1_g[500];        /* '<S35>/Data Store Read1' */
  real_T DataStoreRead_ef[500];        /* '<S35>/Data Store Read' */
  real_T I1_g;                         /* '<S35>/I1' */
  real_T DataStoreRead1_fi[500];       /* '<S34>/Data Store Read1' */
  real_T DataStoreRead_jd[500];        /* '<S34>/Data Store Read' */
  real_T I1_k;                         /* '<S34>/I1' */
  real_T DataStoreRead1_kd[500];       /* '<S33>/Data Store Read1' */
  real_T DataStoreRead_d[500];         /* '<S33>/Data Store Read' */
  real_T I1_j;                         /* '<S33>/I1' */
  real_T DataStoreRead1_mj[500];       /* '<S32>/Data Store Read1' */
  real_T DataStoreRead_gy[500];        /* '<S32>/Data Store Read' */
  real_T I1_c;                         /* '<S32>/I1' */
  real_T DataStoreRead1_h[500];        /* '<S31>/Data Store Read1' */
  real_T DataStoreRead_i4[500];        /* '<S31>/Data Store Read' */
  real_T I1_i;                         /* '<S31>/I1' */
  real_T DataStoreRead1_a[500];        /* '<S30>/Data Store Read1' */
  real_T DataStoreRead_lz[500];        /* '<S30>/Data Store Read' */
  real_T I1_e;                         /* '<S30>/I1' */
  real_T DataStoreRead1_c3[500];       /* '<S29>/Data Store Read1' */
  real_T DataStoreRead_nu[500];        /* '<S29>/Data Store Read' */
  real_T I1_ib;                        /* '<S29>/I1' */
  real_T DataStoreRead1_nq[500];       /* '<S28>/Data Store Read1' */
  real_T DataStoreRead_eq[500];        /* '<S28>/Data Store Read' */
  real_T I1_jq;                        /* '<S28>/I1' */
  real_T DataStoreRead1_pde[500];      /* '<S27>/Data Store Read1' */
  real_T DataStoreRead_ld[500];        /* '<S27>/Data Store Read' */
  real_T I1_d;                         /* '<S27>/I1' */
  real_T DataStoreRead1_dg[500];       /* '<S26>/Data Store Read1' */
  real_T DataStoreRead_ft[500];        /* '<S26>/Data Store Read' */
  real_T I1_o;                         /* '<S26>/I1' */
  real_T DataStoreRead1_d5[500];       /* '<S17>/Data Store Read1' */
  real_T DataStoreRead_h4[500];        /* '<S17>/Data Store Read' */
  real_T Ipref_h;                      /* '<S17>/Ipref' */
  real_T Gain1_h;                      /* '<S4>/Gain1' */
  real_T Switch_c;                     /* '<S13>/Switch' */
  real_T Gain_l;                       /* '<S4>/Gain' */
  real_T Switch_k;                     /* '<S12>/Switch' */
  uint8_T Compare;                     /* '<S49>/Compare' */
  uint8_T Compare_p;                   /* '<S66>/Compare' */
  uint8_T Compare_i[11];               /* '<S70>/Compare' */
  uint8_T Compare_l;                   /* '<S76>/Compare' */
  uint8_T Compare_o;                   /* '<S74>/Compare' */
  uint8_T Compare_p3[11];              /* '<S71>/Compare' */
  uint8_T Compare_d;                   /* '<S78>/Compare' */
  boolean_T RelationalOperator_n;      /* '<S5>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S5>/Relational Operator1' */
  boolean_T RelationalOperator_p;      /* '<S22>/Relational Operator' */
  boolean_T RelationalOperator_d;      /* '<S67>/Relational Operator' */
  boolean_T RelationalOperator_f;      /* '<S68>/Relational Operator' */
  boolean_T RelationalOperator_d5;     /* '<S69>/Relational Operator' */
  boolean_T RelationalOperator_nb;     /* '<S60>/Relational Operator' */
  boolean_T RelationalOperator1_f;     /* '<S60>/Relational Operator1' */
  boolean_T RelationalOperator_g4;     /* '<S77>/Relational Operator' */
  boolean_T RelationalOperator_pi;     /* '<S63>/Relational Operator' */
  boolean_T RelationalOperator_m;      /* '<S75>/Relational Operator' */
  boolean_T LogicalOperator[11];       /* '<S52>/Logical Operator' */
  boolean_T RelationalOperator_o;      /* '<S79>/Relational Operator' */
  boolean_T RelationalOperator_c;      /* '<S64>/Relational Operator' */
  boolean_T LowerRelop1[11];           /* '<S10>/LowerRelop1' */
  boolean_T UpperRelop[11];            /* '<S10>/UpperRelop' */
  boolean_T LowerRelop1_g[11];         /* '<S11>/LowerRelop1' */
  boolean_T UpperRelop_c[11];          /* '<S11>/UpperRelop' */
  boolean_T LowerRelop1_j;             /* '<S12>/LowerRelop1' */
  boolean_T LowerRelop1_j5;            /* '<S13>/LowerRelop1' */
  boolean_T UpperRelop_d;              /* '<S13>/UpperRelop' */
  boolean_T UpperRelop_m;              /* '<S12>/UpperRelop' */
} BlockIO_t15_2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S24>/UD' */
  real_T UD_DSTATE_j;                  /* '<S25>/UD' */
  real_T Divcontr_DSTATE[32];          /* '<S54>/Div. contr.' */
  real_T Div_rdcontr_DSTATE[22];       /* '<S55>/Div_rd contr' */
  real_T Currtermcontr_DSTATE[22];     /* '<S53>/Curr. term. contr' */
  real_T Limcontr_DSTATE[46];          /* '<S56>/Lim. contr.' */
  real_T Currcontr_DSTATE[11];         /* '<S56>/Curr. contr.' */
  real_T UD_DSTATE_c;                  /* '<S73>/UD' */
  real_T VScontr_DSTATE[9];            /* '<S57>/VS. contr' */
  real_T VScontrhl_DSTATE[8];          /* '<S57>/VS. contr hl' */
  real_T UD_DSTATE_i;                  /* '<S6>/UD' */
  real_T Memory2_PreviousInput;        /* '<S5>/Memory2' */
  real_T Memory2_PreviousInput_k;      /* '<S23>/Memory2' */
  real_T Memory1_PreviousInput;        /* '<S23>/Memory1' */
  real_T Memory1_PreviousInput_c;      /* '<S17>/Memory1' */
  real_T Memory2_PreviousInput_m;      /* '<S29>/Memory2' */
  real_T Memory2_PreviousInput_b;      /* '<S27>/Memory2' */
  real_T Memory2_PreviousInput_a;      /* '<S28>/Memory2' */
  real_T Memory2_PreviousInput_d;      /* '<S30>/Memory2' */
  real_T Memory2_PreviousInput_c;      /* '<S26>/Memory2' */
  real_T Memory2_PreviousInput_e;      /* '<S31>/Memory2' */
  real_T Memory2_PreviousInput_o;      /* '<S32>/Memory2' */
  real_T Memory2_PreviousInput_eq;     /* '<S33>/Memory2' */
  real_T Memory2_PreviousInput_bf;     /* '<S34>/Memory2' */
  real_T Memory2_PreviousInput_l;      /* '<S35>/Memory2' */
  real_T Memory2_PreviousInput_j;      /* '<S36>/Memory2' */
  real_T Memory2_PreviousInput_o4;     /* '<S42>/Memory2' */
  real_T Memory1_PreviousInput_g;      /* '<S42>/Memory1' */
  real_T Memory2_PreviousInput_mw;     /* '<S37>/Memory2' */
  real_T Memory1_PreviousInput_d;      /* '<S37>/Memory1' */
  real_T Memory2_PreviousInput_h;      /* '<S38>/Memory2' */
  real_T Memory1_PreviousInput_p;      /* '<S38>/Memory1' */
  real_T Memory2_PreviousInput_g;      /* '<S39>/Memory2' */
  real_T Memory1_PreviousInput_h;      /* '<S39>/Memory1' */
  real_T Memory2_PreviousInput_oh;     /* '<S40>/Memory2' */
  real_T Memory1_PreviousInput_gk;     /* '<S40>/Memory1' */
  real_T Memory2_PreviousInput_ef;     /* '<S41>/Memory2' */
  real_T Memory1_PreviousInput_j;      /* '<S41>/Memory1' */
  real_T Memory3_PreviousInput;        /* '<S50>/Memory3' */
  real_T Memory1_PreviousInput_l;      /* '<S51>/Memory1' */
  real_T Memory1_PreviousInput_b[11];  /* '<S60>/Memory1' */
  real_T Memory_PreviousInput[11];     /* '<S63>/Memory' */
  real_T Memory1_PreviousInput_o;      /* '<S62>/Memory1' */
  real_T Memory1_PreviousInput_f;      /* '<S59>/Memory1' */
  real_T Memory2_PreviousInput_dn[11]; /* '<S56>/Memory2' */
  real_T Sum3_DWORK1[11];              /* '<S52>/Sum3' */
  real_T UniformRandomNumber_NextOutput;/* '<S61>/Uniform Random Number' */
  real_T scr_data[6500];               /* '<S5>/Data Store Memory' */
  real_T volt[10000];                  /* '<S5>/Data Store Memory1' */
  real_T Memory1_PreviousInput_p2[11]; /* '<S7>/Memory1' */
  real_T RupRd[6];                     /* '<S1>/Data Store Memory2' */
  real_T VS3_up;                       /* '<S1>/Data Store Memory3' */
  real_T Vcspf_up[11];                 /* '<S1>/Data Store Memory4' */
  real_T VS1_up;                       /* '<S1>/Data Store Memory5' */
  real_T Tu;                           /* '<S1>/Data Store Memory7' */
  real_T c_cur_max;                    /* '<S1>/Data Store Memory8' */
  real_T Imax[11];                     /* '<S1>/Data Store Memory9' */
  uint32_T RandSeed;                   /* '<S61>/Uniform Random Number' */
} D_Work_t15_2;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1[15];                      /* '<Root>/In1' */
  real_T In2[123];                     /* '<Root>/In2' */
} ExternalInputs_t15_2;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T to_DINA[38];                  /* '<Root>/to_DINA' */
} ExternalOutputs_t15_2;

/* Parameters (auto storage) */
struct Parameters_t15_2_ {
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: trd_ref
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: trd_ref
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: trd_ref
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: trd_ref
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: trd_ref
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T Constant_Value_ow;            /* Expression: trd_ref
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T k_gaplim_Gain[4];             /* Expression: k_gaplim
                                        * Referenced by: '<S14>/k_gaplim'
                                        */
  real_T zeros21_Value[2];             /* Expression: zeros(2,1)
                                        * Referenced by: '<S15>/zeros(2,1)'
                                        */
  real_T e3_Gain;                      /* Expression: 2e3
                                        * Referenced by: '<S72>/2e3'
                                        */
  real_T u5_Gain;                      /* Expression: 1.75
                                        * Referenced by: '<S72>/1.75'
                                        */
  real_T zeros201_Value[20];           /* Expression: zeros(20,1)
                                        * Referenced by: '<S56>/zeros(20,1)'
                                        */
  real_T gain_cont2_XData[4];          /* Expression: tgain_cont2
                                        * Referenced by: '<S56>/gain_cont2'
                                        */
  real_T gain_cont2_YData[4];          /* Expression: gain_cont2
                                        * Referenced by: '<S56>/gain_cont2'
                                        */
  real_T tcont2_Threshold;             /* Expression: tcont2
                                        * Referenced by: '<S56>/tcont2'
                                        */
  real_T y0_Value;                     /* Expression: y0
                                        * Referenced by: '<S59>/y0'
                                        */
  real_T uy0_Value;                    /* Expression: (1-y0)/(c2_y0-c1_y0)
                                        * Referenced by: '<S59>/(1-y0)//...'
                                        */
  real_T c1_y0_Value;                  /* Expression: c1_y0
                                        * Referenced by: '<S59>/c1_y0'
                                        */
  real_T uy0_UpperSat;                 /* Expression: 1
                                        * Referenced by: '<S59>/[1 y0]'
                                        */
  real_T uy0_LowerSat;                 /* Expression: y0
                                        * Referenced by: '<S59>/[1 y0]'
                                        */
  real_T limgain_Gain;                 /* Expression: c_a_tpl2/15
                                        * Referenced by: '<S15>/lim. gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T _Value;                       /* Expression: 1
                                        * Referenced by: '<S62>/1'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: g1_ramp
                                        * Referenced by: '<S62>/Gain1'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 1
                                        * Referenced by: '<S62>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S62>/Saturation'
                                        */
  real_T c_eob_Threshold;              /* Expression: 0.9999
                                        * Referenced by: '<S15>/c_eob'
                                        */
  real_T VSgain2_Gain;                 /* Expression: 1/15
                                        * Referenced by: '<S15>/VS gain 2'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S15>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: c_a_tpl_min
                                        * Referenced by: '<S15>/Saturation3'
                                        */
  real_T SatLim_UpperSat;              /* Expression: max_a_tpl1_lim
                                        * Referenced by: '<S58>/Sat. Lim'
                                        */
  real_T SatLim_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S58>/Sat. Lim'
                                        */
  real_T SatDiv_UpperSat;              /* Expression: max_a_tpl1_div
                                        * Referenced by: '<S58>/Sat. Div'
                                        */
  real_T SatDiv_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S58>/Sat. Div'
                                        */
  real_T IpIp_div_Threshold;           /* Expression: Ip_div
                                        * Referenced by: '<S58>/Ip>Ip_div'
                                        */
  real_T c_eob_Threshold_i;            /* Expression: 0.9999
                                        * Referenced by: '<S15>/c_eob '
                                        */
  real_T VSgain3_Gain;                 /* Expression: c_a_tpl1_eob/15
                                        * Referenced by: '<S15>/VS gain 3'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S15>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: c_a_tpl_min
                                        * Referenced by: '<S15>/Saturation4'
                                        */
  real_T SFunction1_P1_Size[2];        /* Computed Parameter: SFunction1_P1_Size
                                        * Referenced by: '<S5>/S-Function1'
                                        */
  real_T SFunction1_P1;                /* Expression: 1
                                        * Referenced by: '<S5>/S-Function1'
                                        */
  real_T SFunction2_P1_Size[2];        /* Computed Parameter: SFunction2_P1_Size
                                        * Referenced by: '<S5>/S-Function2'
                                        */
  real_T SFunction2_P1;                /* Expression: 12
                                        * Referenced by: '<S5>/S-Function2'
                                        */
  real_T e3_Gain_p;                    /* Expression: 1e-3
                                        * Referenced by: '<S5>/1e-3'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S5>/Memory2'
                                        */
  real_T u_Gain;                       /* Expression: -1
                                        * Referenced by: '<S5>/-1'
                                        */
  real_T Ip1e4_Threshold;              /* Expression: -1e-4
                                        * Referenced by: '<S5>/Ip<1e-4 '
                                        */
  real_T Time_stop_Value;              /* Expression: Time_stop
                                        * Referenced by: '<S5>/Time_stop'
                                        */
  real_T e6_Gain;                      /* Expression: 1e-6
                                        * Referenced by: '<S14>/1e-6'
                                        */
  real_T e6_Gain_c;                    /* Expression: 1e-6
                                        * Referenced by: '<S14>/1e-6   '
                                        */
  real_T Memory2_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S23>/Memory2'
                                        */
  real_T e3_Gain_m;                    /* Expression: 1e-3
                                        * Referenced by: '<S23>/1e-3'
                                        */
  real_T ntur3_Value;                  /* Expression: ntur(3)
                                        * Referenced by: '<S23>/ntur(3)'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S23>/Memory1'
                                        */
  real_T u99_Threshold;                /* Expression: 0.999
                                        * Referenced by: '<S23>/0.999'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S23>/Constant4'
                                        */
  real_T u_UpperSat;                   /* Expression: 1
                                        * Referenced by: '<S23>/1 0'
                                        */
  real_T u_LowerSat;                   /* Expression: 0
                                        * Referenced by: '<S23>/1 0'
                                        */
  real_T Memory1_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S17>/Memory1'
                                        */
  real_T c_eob_Threshold_g;            /* Expression: 0.9999
                                        * Referenced by: '<S17>/c_eob'
                                        */
  real_T SFunction1_P1_Size_l[2];      /* Computed Parameter: SFunction1_P1_Size_l
                                        * Referenced by: '<S19>/S-Function1'
                                        */
  real_T SFunction1_P1_f;              /* Expression: 0
                                        * Referenced by: '<S19>/S-Function1'
                                        */
  real_T Constant4_Value_l;            /* Expression: 0
                                        * Referenced by: '<S14>/Constant4'
                                        */
  real_T UD_InitialCondition;          /* Expression: ICPrevInput
                                        * Referenced by: '<S24>/UD'
                                        */
  real_T UD_InitialCondition_b;        /* Expression: ICPrevInput
                                        * Referenced by: '<S25>/UD'
                                        */
  real_T Memory2_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S29>/Memory2'
                                        */
  real_T c_eob_Threshold_ix;           /* Expression: 0.9999
                                        * Referenced by: '<S29>/c_eob'
                                        */
  real_T Memory2_X0_d;                 /* Expression: 0
                                        * Referenced by: '<S27>/Memory2'
                                        */
  real_T c_eob_Threshold_o;            /* Expression: 0.9999
                                        * Referenced by: '<S27>/c_eob'
                                        */
  real_T Memory2_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S28>/Memory2'
                                        */
  real_T c_eob_Threshold_e;            /* Expression: 0.9999
                                        * Referenced by: '<S28>/c_eob'
                                        */
  real_T Memory2_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S30>/Memory2'
                                        */
  real_T c_eob_Threshold_o0;           /* Expression: 0.9999
                                        * Referenced by: '<S30>/c_eob'
                                        */
  real_T Memory2_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S26>/Memory2'
                                        */
  real_T c_eob_Threshold_e2;           /* Expression: 0.9999
                                        * Referenced by: '<S26>/c_eob'
                                        */
  real_T Memory2_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S31>/Memory2'
                                        */
  real_T c_eob_Threshold_h;            /* Expression: 0.9999
                                        * Referenced by: '<S31>/c_eob'
                                        */
  real_T Memory2_X0_hi;                /* Expression: 0
                                        * Referenced by: '<S32>/Memory2'
                                        */
  real_T c_eob_Threshold_on;           /* Expression: 0.9999
                                        * Referenced by: '<S32>/c_eob'
                                        */
  real_T Memory2_X0_dv;                /* Expression: 0
                                        * Referenced by: '<S33>/Memory2'
                                        */
  real_T c_eob_Threshold_j;            /* Expression: 0.9999
                                        * Referenced by: '<S33>/c_eob'
                                        */
  real_T Memory2_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S34>/Memory2'
                                        */
  real_T c_eob_Threshold_n;            /* Expression: 0.9999
                                        * Referenced by: '<S34>/c_eob'
                                        */
  real_T Memory2_X0_bq;                /* Expression: 0
                                        * Referenced by: '<S35>/Memory2'
                                        */
  real_T c_eob_Threshold_hg;           /* Expression: 0.9999
                                        * Referenced by: '<S35>/c_eob'
                                        */
  real_T Memory2_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S36>/Memory2'
                                        */
  real_T c_eob_Threshold_m;            /* Expression: 0.9999
                                        * Referenced by: '<S36>/c_eob'
                                        */
  real_T u_Threshold;                  /* Expression: 0
                                        * Referenced by: '<S16>/>=0'
                                        */
  real_T e2_Gain;                      /* Expression: 1e2
                                        * Referenced by: '<S21>/1e2'
                                        */
  real_T SFunction1_P1_Size_m[2];      /* Computed Parameter: SFunction1_P1_Size_m
                                        * Referenced by: '<S42>/S-Function1'
                                        */
  real_T SFunction1_P1_n;              /* Expression: 1
                                        * Referenced by: '<S42>/S-Function1'
                                        */
  real_T Memory2_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S42>/Memory2'
                                        */
  real_T c_eob1_Threshold;             /* Expression: 0.9999
                                        * Referenced by: '<S42>/c_eob  1'
                                        */
  real_T Memory1_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S42>/Memory1'
                                        */
  real_T c_eob_Threshold_k;            /* Expression: 0.9999
                                        * Referenced by: '<S42>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_f[2];      /* Computed Parameter: SFunction1_P1_Size_f
                                        * Referenced by: '<S48>/S-Function1'
                                        */
  real_T SFunction1_P1_p;              /* Expression: 1
                                        * Referenced by: '<S48>/S-Function1'
                                        */
  real_T c_eob_Threshold_hx;           /* Expression: 0.9999
                                        * Referenced by: '<S42>/c_eob'
                                        */
  real_T LookupTable1_XData[4];        /* Expression: [0 t_tran2D g2_ramp 1e6]
                                        * Referenced by: '<S21>/Lookup Table1'
                                        */
  real_T LookupTable1_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S21>/Lookup Table1'
                                        */
  real_T SFunction1_P1_Size_n[2];      /* Computed Parameter: SFunction1_P1_Size_n
                                        * Referenced by: '<S37>/S-Function1'
                                        */
  real_T SFunction1_P1_j;              /* Expression: 2
                                        * Referenced by: '<S37>/S-Function1'
                                        */
  real_T Memory2_X0_oh;                /* Expression: 0
                                        * Referenced by: '<S37>/Memory2'
                                        */
  real_T c_eob1_Threshold_o;           /* Expression: 0.9999
                                        * Referenced by: '<S37>/c_eob  1'
                                        */
  real_T Memory1_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S37>/Memory1'
                                        */
  real_T c_eob_Threshold_j0;           /* Expression: 0.9999
                                        * Referenced by: '<S37>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_mz[2];     /* Computed Parameter: SFunction1_P1_Size_mz
                                        * Referenced by: '<S43>/S-Function1'
                                        */
  real_T SFunction1_P1_g;              /* Expression: 2
                                        * Referenced by: '<S43>/S-Function1'
                                        */
  real_T c_eob_Threshold_l;            /* Expression: 0.9999
                                        * Referenced by: '<S37>/c_eob'
                                        */
  real_T LookupTable2_XData[4];        /* Expression: [0 t_tran2D g2_ramp 1e6]
                                        * Referenced by: '<S21>/Lookup Table2'
                                        */
  real_T LookupTable2_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S21>/Lookup Table2'
                                        */
  real_T SFunction1_P1_Size_b[2];      /* Computed Parameter: SFunction1_P1_Size_b
                                        * Referenced by: '<S38>/S-Function1'
                                        */
  real_T SFunction1_P1_fs;             /* Expression: 3
                                        * Referenced by: '<S38>/S-Function1'
                                        */
  real_T Memory2_X0_kw;                /* Expression: 0
                                        * Referenced by: '<S38>/Memory2'
                                        */
  real_T c_eob1_Threshold_l;           /* Expression: 0.9999
                                        * Referenced by: '<S38>/c_eob  1'
                                        */
  real_T Memory1_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S38>/Memory1'
                                        */
  real_T c_eob_Threshold_jk;           /* Expression: 0.9999
                                        * Referenced by: '<S38>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_o[2];      /* Computed Parameter: SFunction1_P1_Size_o
                                        * Referenced by: '<S44>/S-Function1'
                                        */
  real_T SFunction1_P1_b;              /* Expression: 3
                                        * Referenced by: '<S44>/S-Function1'
                                        */
  real_T c_eob_Threshold_g2;           /* Expression: 0.9999
                                        * Referenced by: '<S38>/c_eob'
                                        */
  real_T SFunction1_P1_Size_c[2];      /* Computed Parameter: SFunction1_P1_Size_c
                                        * Referenced by: '<S39>/S-Function1'
                                        */
  real_T SFunction1_P1_l;              /* Expression: 4
                                        * Referenced by: '<S39>/S-Function1'
                                        */
  real_T Memory2_X0_nw;                /* Expression: 0
                                        * Referenced by: '<S39>/Memory2'
                                        */
  real_T c_eob1_Threshold_lw;          /* Expression: 0.9999
                                        * Referenced by: '<S39>/c_eob  1'
                                        */
  real_T Memory1_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S39>/Memory1'
                                        */
  real_T c_eob_Threshold_b;            /* Expression: 0.9999
                                        * Referenced by: '<S39>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_bi[2];     /* Computed Parameter: SFunction1_P1_Size_bi
                                        * Referenced by: '<S45>/S-Function1'
                                        */
  real_T SFunction1_P1_c;              /* Expression: 4
                                        * Referenced by: '<S45>/S-Function1'
                                        */
  real_T c_eob_Threshold_d;            /* Expression: 0.9999
                                        * Referenced by: '<S39>/c_eob'
                                        */
  real_T LookupTable3_XData[4];        /* Expression: [0 t_tran2D g2_ramp 1e6]
                                        * Referenced by: '<S21>/Lookup Table3'
                                        */
  real_T LookupTable3_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S21>/Lookup Table3'
                                        */
  real_T SFunction1_P1_Size_e[2];      /* Computed Parameter: SFunction1_P1_Size_e
                                        * Referenced by: '<S40>/S-Function1'
                                        */
  real_T SFunction1_P1_ca;             /* Expression: 5
                                        * Referenced by: '<S40>/S-Function1'
                                        */
  real_T Memory2_X0_nr;                /* Expression: 0
                                        * Referenced by: '<S40>/Memory2'
                                        */
  real_T c_eob1_Threshold_h;           /* Expression: 0.9999
                                        * Referenced by: '<S40>/c_eob  1'
                                        */
  real_T Memory1_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S40>/Memory1'
                                        */
  real_T c_eob_Threshold_nn;           /* Expression: 0.9999
                                        * Referenced by: '<S40>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_p[2];      /* Computed Parameter: SFunction1_P1_Size_p
                                        * Referenced by: '<S46>/S-Function1'
                                        */
  real_T SFunction1_P1_o;              /* Expression: 5
                                        * Referenced by: '<S46>/S-Function1'
                                        */
  real_T c_eob_Threshold_a;            /* Expression: 0.9999
                                        * Referenced by: '<S40>/c_eob'
                                        */
  real_T SFunction1_P1_Size_bq[2];     /* Computed Parameter: SFunction1_P1_Size_bq
                                        * Referenced by: '<S41>/S-Function1'
                                        */
  real_T SFunction1_P1_gf;             /* Expression: 6
                                        * Referenced by: '<S41>/S-Function1'
                                        */
  real_T Memory2_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S41>/Memory2'
                                        */
  real_T c_eob1_Threshold_m;           /* Expression: 0.9999
                                        * Referenced by: '<S41>/c_eob  1'
                                        */
  real_T Memory1_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S41>/Memory1'
                                        */
  real_T c_eob_Threshold_mb;           /* Expression: 0.9999
                                        * Referenced by: '<S41>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_a[2];      /* Computed Parameter: SFunction1_P1_Size_a
                                        * Referenced by: '<S47>/S-Function1'
                                        */
  real_T SFunction1_P1_g3;             /* Expression: 6
                                        * Referenced by: '<S47>/S-Function1'
                                        */
  real_T c_eob_Threshold_ge;           /* Expression: 0.9999
                                        * Referenced by: '<S41>/c_eob'
                                        */
  real_T e2_Gain_j;                    /* Expression: 1e-2
                                        * Referenced by: '<S21>/1e-2'
                                        */
  real_T Constant_Value_if;            /* Expression: const
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T u9_Threshold;                 /* Expression: 0.99
                                        * Referenced by: '<S22>/0.99'
                                        */
  real_T e6_Gain_m;                    /* Expression: 1e6
                                        * Referenced by: '<S23>/1e6'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S50>/Memory3'
                                        */
  real_T Constant_Value_e;             /* Expression: const
                                        * Referenced by: '<S66>/Constant'
                                        */
  real_T u999_Threshold;               /* Expression: 0.9999
                                        * Referenced by: '<S50>/0.9999'
                                        */
  real_T _Value_n;                     /* Expression: 1
                                        * Referenced by: '<S50>/1'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: g1_ramp
                                        * Referenced by: '<S50>/Gain1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S50>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S50>/Saturation1'
                                        */
  real_T Memory1_X0_fe;                /* Expression: 0
                                        * Referenced by: '<S51>/Memory1'
                                        */
  real_T u999_Threshold_f;             /* Expression: 0.9999
                                        * Referenced by: '<S51>/0.9999'
                                        */
  real_T _Value_f;                     /* Expression: 1
                                        * Referenced by: '<S51>/1'
                                        */
  real_T Gain1_Gain_j0;                /* Expression: g1_ramp
                                        * Referenced by: '<S51>/Gain1'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 1
                                        * Referenced by: '<S51>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: 0
                                        * Referenced by: '<S51>/Saturation'
                                        */
  real_T e3_Gain_f;                    /* Expression: 1e3
                                        * Referenced by: '<S52>/1e3'
                                        */
  real_T ntur111_Value[11];            /* Expression: ntur(1:11)
                                        * Referenced by: '<S52>/ntur(1:11)'
                                        */
  real_T Saturation_UpperSat_cy;       /* Expression: 1
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -1
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real_T Constant_Value_c;             /* Expression: const
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T Memory1_X0_h2;                /* Expression: 0
                                        * Referenced by: '<S60>/Memory1'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S63>/Memory'
                                        */
  real_T Constant_Value_a;             /* Expression: const
                                        * Referenced by: '<S76>/Constant'
                                        */
  real_T Divcontr_A[572];              /* Computed Parameter: Divcontr_A
                                        * Referenced by: '<S54>/Div. contr.'
                                        */
  real_T Divcontr_B[352];              /* Computed Parameter: Divcontr_B
                                        * Referenced by: '<S54>/Div. contr.'
                                        */
  real_T Divcontr_C[205];              /* Computed Parameter: Divcontr_C
                                        * Referenced by: '<S54>/Div. contr.'
                                        */
  real_T Divcontr_D[171];              /* Computed Parameter: Divcontr_D
                                        * Referenced by: '<S54>/Div. contr.'
                                        */
  real_T Divcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S54>/Div. contr.'
                                        */
  real_T u9_Threshold_k;               /* Expression: 0.99
                                        * Referenced by: '<S63>/0.99'
                                        */
  real_T Memory1_X0_fo;                /* Expression: 0
                                        * Referenced by: '<S62>/Memory1'
                                        */
  real_T Constant_Value_b;             /* Expression: const
                                        * Referenced by: '<S74>/Constant'
                                        */
  real_T u999_Threshold_i;             /* Expression: 0.9999
                                        * Referenced by: '<S62>/0.9999'
                                        */
  real_T Div_rdcontr_A[337];           /* Computed Parameter: Div_rdcontr_A
                                        * Referenced by: '<S55>/Div_rd contr'
                                        */
  real_T Div_rdcontr_B[277];           /* Computed Parameter: Div_rdcontr_B
                                        * Referenced by: '<S55>/Div_rd contr'
                                        */
  real_T Div_rdcontr_C[165];           /* Computed Parameter: Div_rdcontr_C
                                        * Referenced by: '<S55>/Div_rd contr'
                                        */
  real_T Div_rdcontr_D[198];           /* Computed Parameter: Div_rdcontr_D
                                        * Referenced by: '<S55>/Div_rd contr'
                                        */
  real_T Div_rdcontr_X0;               /* Expression: 0
                                        * Referenced by: '<S55>/Div_rd contr'
                                        */
  real_T Memory1_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S59>/Memory1'
                                        */
  real_T c_eob_Threshold_p;            /* Expression: 0.9999
                                        * Referenced by: '<S59>/c_eob'
                                        */
  real_T u99_Threshold_c;              /* Expression: 0.999
                                        * Referenced by: '<S60>/0.999'
                                        */
  real_T Currtermcontr_A[253];         /* Computed Parameter: Currtermcontr_A
                                        * Referenced by: '<S53>/Curr. term. contr'
                                        */
  real_T Currtermcontr_B[121];         /* Computed Parameter: Currtermcontr_B
                                        * Referenced by: '<S53>/Curr. term. contr'
                                        */
  real_T Currtermcontr_C[11];          /* Computed Parameter: Currtermcontr_C
                                        * Referenced by: '<S53>/Curr. term. contr'
                                        */
  real_T Currtermcontr_X0;             /* Expression: 0
                                        * Referenced by: '<S53>/Curr. term. contr'
                                        */
  real_T Memory2_X0_ai;                /* Expression: 0
                                        * Referenced by: '<S56>/Memory2'
                                        */
  real_T tcont2_Threshold_f;           /* Expression: tcont2
                                        * Referenced by: '<S56>/tcont2 '
                                        */
  real_T Limcontr_A[2116];             /* Computed Parameter: Limcontr_A
                                        * Referenced by: '<S56>/Lim. contr.'
                                        */
  real_T Limcontr_B[782];              /* Computed Parameter: Limcontr_B
                                        * Referenced by: '<S56>/Lim. contr.'
                                        */
  real_T Limcontr_C[506];              /* Computed Parameter: Limcontr_C
                                        * Referenced by: '<S56>/Lim. contr.'
                                        */
  real_T Limcontr_D[187];              /* Computed Parameter: Limcontr_D
                                        * Referenced by: '<S56>/Lim. contr.'
                                        */
  real_T Limcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S56>/Lim. contr.'
                                        */
  real_T Currcontr_A[121];             /* Computed Parameter: Currcontr_A
                                        * Referenced by: '<S56>/Curr. contr.'
                                        */
  real_T Currcontr_B[121];             /* Computed Parameter: Currcontr_B
                                        * Referenced by: '<S56>/Curr. contr.'
                                        */
  real_T Currcontr_C[121];             /* Computed Parameter: Currcontr_C
                                        * Referenced by: '<S56>/Curr. contr.'
                                        */
  real_T Currcontr_X0;                 /* Expression: 0
                                        * Referenced by: '<S56>/Curr. contr.'
                                        */
  real_T ntur111_Value_c[11];          /* Expression: ntur(1:11)
                                        * Referenced by: '<S56>/ntur(1:11)'
                                        */
  real_T IpIp_div_Threshold_l;         /* Expression: Ip_div
                                        * Referenced by: '<S56>/Ip>Ip_div '
                                        */
  real_T u01_Gain;                     /* Expression: 1e-3
                                        * Referenced by: '<S80>/0.001'
                                        */
  real_T u01_Gain_o;                   /* Expression: 1e-3
                                        * Referenced by: '<S83>/0.001'
                                        */
  real_T u01_Gain_ox;                  /* Expression: 1e-3
                                        * Referenced by: '<S84>/0.001'
                                        */
  real_T u01_Gain_f;                   /* Expression: 1e-3
                                        * Referenced by: '<S85>/0.001'
                                        */
  real_T u01_Gain_b;                   /* Expression: 1e-3
                                        * Referenced by: '<S86>/0.001'
                                        */
  real_T u01_Gain_e;                   /* Expression: 1e-3
                                        * Referenced by: '<S87>/0.001'
                                        */
  real_T u01_Gain_k;                   /* Expression: 1e-3
                                        * Referenced by: '<S88>/0.001'
                                        */
  real_T u01_Gain_d;                   /* Expression: 1e-3
                                        * Referenced by: '<S89>/0.001'
                                        */
  real_T u01_Gain_fh;                  /* Expression: 1e-3
                                        * Referenced by: '<S90>/0.001'
                                        */
  real_T u01_Gain_l;                   /* Expression: 1e-3
                                        * Referenced by: '<S81>/0.001'
                                        */
  real_T u01_Gain_ey;                  /* Expression: 1e-3
                                        * Referenced by: '<S82>/0.001'
                                        */
  real_T Constant_Value_bp;            /* Expression: 0
                                        * Referenced by: '<S71>/Constant'
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: 1
                                        * Referenced by: '<S52>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -1
                                        * Referenced by: '<S52>/Saturation1'
                                        */
  real_T UniformRandomNumber_Minimum;  /* Expression: -1
                                        * Referenced by: '<S61>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 1
                                        * Referenced by: '<S61>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S61>/Uniform Random Number'
                                        */
  real_T UD_InitialCondition_e;        /* Expression: ICPrevInput
                                        * Referenced by: '<S73>/UD'
                                        */
  real_T tt_tran2d_Threshold;          /* Expression: t_tran2D
                                        * Referenced by: '<S15>/t>t_tran2d'
                                        */
  real_T VScontr_A[34];                /* Computed Parameter: VScontr_A
                                        * Referenced by: '<S57>/VS. contr'
                                        */
  real_T VScontr_B[16];                /* Computed Parameter: VScontr_B
                                        * Referenced by: '<S57>/VS. contr'
                                        */
  real_T VScontr_C[10];                /* Computed Parameter: VScontr_C
                                        * Referenced by: '<S57>/VS. contr'
                                        */
  real_T VScontr_D[4];                 /* Computed Parameter: VScontr_D
                                        * Referenced by: '<S57>/VS. contr'
                                        */
  real_T VScontr_X0;                   /* Expression: 0
                                        * Referenced by: '<S57>/VS. contr'
                                        */
  real_T c_eob_Value;                  /* Expression: 0.9999
                                        * Referenced by: '<S57>/c_eob '
                                        */
  real_T VScontrhl_A[33];              /* Computed Parameter: VScontrhl_A
                                        * Referenced by: '<S57>/VS. contr hl'
                                        */
  real_T VScontrhl_B[15];              /* Computed Parameter: VScontrhl_B
                                        * Referenced by: '<S57>/VS. contr hl'
                                        */
  real_T VScontrhl_C[9];               /* Computed Parameter: VScontrhl_C
                                        * Referenced by: '<S57>/VS. contr hl'
                                        */
  real_T VScontrhl_D[4];               /* Computed Parameter: VScontrhl_D
                                        * Referenced by: '<S57>/VS. contr hl'
                                        */
  real_T VScontrhl_X0;                 /* Expression: 0
                                        * Referenced by: '<S57>/VS. contr hl'
                                        */
  real_T c_eob_Threshold_lk;           /* Expression: 0.9999
                                        * Referenced by: '<S57>/c_eob'
                                        */
  real_T Constant_Value_k;             /* Expression: const
                                        * Referenced by: '<S78>/Constant'
                                        */
  real_T atpl115_Gain;                 /* Expression: c_a_tpl1/15
                                        * Referenced by: '<S58>/atpl1//15'
                                        */
  real_T u9_Threshold_n;               /* Expression: 0.99
                                        * Referenced by: '<S64>/0.99'
                                        */
  real_T ntur111_Value_a[11];          /* Expression: ntur(1:11)
                                        * Referenced by: '<S5>/ntur(1:11)'
                                        */
  real_T DataStoreMemory_InitialValue[6500];/* Expression: zeros(13,500)
                                             * Referenced by: '<S5>/Data Store Memory'
                                             */
  real_T DataStoreMemory1_InitialValue[10000];/* Expression: zeros(20,500)
                                               * Referenced by: '<S5>/Data Store Memory1'
                                               */
  real_T Memory1_X0_fq;                /* Expression: 0
                                        * Referenced by: '<S7>/Memory1'
                                        */
  real_T _Gain;                        /* Expression: 2
                                        * Referenced by: '<S8>/2'
                                        */
  real_T UD_InitialCondition_m;        /* Expression: ICPrevInput
                                        * Referenced by: '<S6>/UD'
                                        */
  real_T u_Gain_e;                     /* Expression: -1
                                        * Referenced by: '<S8>/-1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T ntur_Gain[11];                /* Expression: 1./ntur(1:n_mc)
                                        * Referenced by: '<S2>/1//ntur'
                                        */
  real_T wz_Gain[24];                  /* Expression: wz
                                        * Referenced by: '<S2>/wz'
                                        */
  real_T npf12_Gain[180];              /* Expression: eye(npf,n_mc+1)
                                        * Referenced by: '<S2>/npf,12'
                                        */
  real_T DataStoreMemory2_InitialValue[6];/* Expression: ones(6,1)*1e-6
                                           * Referenced by: '<S1>/Data Store Memory2'
                                           */
  real_T DataStoreMemory3_InitialValue;/* Expression: 0
                                        * Referenced by: '<S1>/Data Store Memory3'
                                        */
  real_T DataStoreMemory4_InitialValue[11];/* Expression: zeros(11,1)
                                            * Referenced by: '<S1>/Data Store Memory4'
                                            */
  real_T DataStoreMemory5_InitialValue;/* Expression: 0
                                        * Referenced by: '<S1>/Data Store Memory5'
                                        */
  real_T DataStoreMemory7_InitialValue;/* Expression: 0
                                        * Referenced by: '<S1>/Data Store Memory7'
                                        */
  real_T DataStoreMemory8_InitialValue;/* Expression: 0
                                        * Referenced by: '<S1>/Data Store Memory8'
                                        */
  real_T DataStoreMemory9_InitialValue[11];/* Expression: zeros(11,1)
                                            * Referenced by: '<S1>/Data Store Memory9'
                                            */
};

/* Real-time Model Data Structure */
struct tag_RTM_t15_2 {
  struct SimStruct_tag * *childSfunctions;
  const char_T * volatile errorStatus;
  SS_SimMode simMode;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[16];
    SimStruct *childSFunctionPtrs[16];
    struct _ssBlkInfo2 blkInfo2[16];
    struct _ssSFcnModelMethods2 methods2[16];
    struct _ssSFcnModelMethods3 methods3[16];
    struct _ssStatesInfo2 statesInfo2[16];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn14;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
    } Sfcn15;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_t15_2 t15_2_P;

/* Block signals (auto storage) */
extern BlockIO_t15_2 t15_2_B;

/* Block states (auto storage) */
extern D_Work_t15_2 t15_2_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_t15_2 t15_2_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_t15_2 t15_2_Y;

/* Model entry point functions */
extern void t15_2_initialize(void);
extern void t15_2_step(void);
extern void t15_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_t15_2 *const t15_2_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/To Workspace1' : Unused code path elimination
 * Block '<S2>/To Workspace2' : Unused code path elimination
 * Block '<S2>/To Workspace3' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Propagation' : Unused code path elimination
 * Block '<S1>/Time' : Unused code path elimination
 * Block '<S5>/A' : Unused code path elimination
 * Block '<S5>/A  ' : Unused code path elimination
 * Block '<S14>/To Workspace1' : Unused code path elimination
 * Block '<S14>/To Workspace2' : Unused code path elimination
 * Block '<S14>/To Workspace3' : Unused code path elimination
 * Block '<S15>/To Workspace' : Unused code path elimination
 * Block '<S5>/To Workspace21' : Unused code path elimination
 * Block '<S5>/To Workspace5' : Unused code path elimination
 * Block '<S5>/To Workspace7' : Unused code path elimination
 * Block '<S5>/klim' : Unused code path elimination
 * Block '<S5>/m' : Unused code path elimination
 * Block '<S5>/m  ' : Unused code path elimination
 * Block '<S5>/m   ' : Unused code path elimination
 * Block '<S5>/rsep' : Unused code path elimination
 * Block '<S5>/rsep1' : Unused code path elimination
 * Block '<S5>/xleft' : Unused code path elimination
 * Block '<S5>/xright' : Unused code path elimination
 * Block '<S5>/zsep' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 't15_2'
 * '<S1>'   : 't15_2/Pow. Supply MC 2'
 * '<S2>'   : 't15_2/Pow. Supply MC 2/Commutation for Dina'
 * '<S3>'   : 't15_2/Pow. Supply MC 2/Pow. Supply MC 1'
 * '<S4>'   : 't15_2/Pow. Supply MC 2/Pow. Supply VS1,3'
 * '<S5>'   : 't15_2/Pow. Supply MC 2/kavin_contr'
 * '<S6>'   : 't15_2/Pow. Supply MC 2/Pow. Supply MC 1/Difference'
 * '<S7>'   : 't15_2/Pow. Supply MC 2/Pow. Supply MC 1/Pow. Supply MC 1'
 * '<S8>'   : 't15_2/Pow. Supply MC 2/Pow. Supply MC 1/Pow. Supply MC 1/MC rate'
 * '<S9>'   : 't15_2/Pow. Supply MC 2/Pow. Supply MC 1/Pow. Supply MC 1/MC satur.'
 * '<S10>'  : 't15_2/Pow. Supply MC 2/Pow. Supply MC 1/Pow. Supply MC 1/MC rate/Saturation Dynamic'
 * '<S11>'  : 't15_2/Pow. Supply MC 2/Pow. Supply MC 1/Pow. Supply MC 1/MC satur./Saturation Dynamic'
 * '<S12>'  : 't15_2/Pow. Supply MC 2/Pow. Supply VS1,3/Saturation Dynamic'
 * '<S13>'  : 't15_2/Pow. Supply MC 2/Pow. Supply VS1,3/Saturation Dynamic1'
 * '<S14>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1'
 * '<S15>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2'
 * '<S16>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Subsystem'
 * '<S17>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Ip_ref scr_data.dat'
 * '<S18>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/dZ//dt'
 * '<S19>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/elong_ref.dat'
 * '<S20>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat'
 * '<S21>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat'
 * '<S22>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/tt_kavin2.dat(1)'
 * '<S23>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/tt_kavin2.dat(3,5)'
 * '<S24>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/dZ//dt/Difference'
 * '<S25>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/dZ//dt/Difference1'
 * '<S26>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil1 ref'
 * '<S27>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil10 ref'
 * '<S28>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil11 ref'
 * '<S29>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil2 ref'
 * '<S30>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil3 ref'
 * '<S31>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil4 ref'
 * '<S32>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil5 ref'
 * '<S33>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil6 ref'
 * '<S34>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil7 ref'
 * '<S35>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil8 ref'
 * '<S36>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil9 ref'
 * '<S37>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem1'
 * '<S38>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem2'
 * '<S39>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem3'
 * '<S40>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem4'
 * '<S41>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem5'
 * '<S42>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem6'
 * '<S43>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem1/g2_term,ref'
 * '<S44>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem2/g3_term,ref'
 * '<S45>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem3/g4_term,ref'
 * '<S46>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem4/g5_term,ref'
 * '<S47>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem5/g6_term,ref'
 * '<S48>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem6/g1_term,ref'
 * '<S49>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/tt_kavin2.dat(1)/Compare To Constant'
 * '<S50>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/ tt_kavin2.dat2(1)'
 * '<S51>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/ tt_kavin2.dat2(4,1)'
 * '<S52>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/Curr. satur.'
 * '<S53>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/Curr. term. contr'
 * '<S54>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/Div. contr.'
 * '<S55>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/Div_rd contr.'
 * '<S56>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/Lim. contr.'
 * '<S57>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/VS contr.'
 * '<S58>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/VS gain 1'
 * '<S59>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/scr_data.dat'
 * '<S60>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat(1,4)'
 * '<S61>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat(6)'
 * '<S62>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat1(1)'
 * '<S63>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat1(4,1)'
 * '<S64>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat3(4,1) '
 * '<S65>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat'
 * '<S66>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/ tt_kavin2.dat2(1)/Compare To Constant'
 * '<S67>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/ tt_kavin2.dat2(1)/Subsystem'
 * '<S68>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/ tt_kavin2.dat2(4,1)/Subsystem'
 * '<S69>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/ tt_kavin2.dat2(4,1)/Subsystem1'
 * '<S70>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/Curr. satur./Compare To Constant'
 * '<S71>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/Curr. satur./Compare To Zero'
 * '<S72>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat(6)/Subsystem'
 * '<S73>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat(6)/Subsystem/Difference'
 * '<S74>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat1(1)/Compare To Constant'
 * '<S75>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat1(1)/Subsystem'
 * '<S76>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat1(4,1)/Compare To Constant'
 * '<S77>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat1(4,1)/Subsystem'
 * '<S78>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat3(4,1) /Compare To Constant'
 * '<S79>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/tt_kavin2.dat3(4,1) /Subsystem'
 * '<S80>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat/volt1'
 * '<S81>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat/volt10'
 * '<S82>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat/volt11'
 * '<S83>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat/volt2'
 * '<S84>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat/volt3'
 * '<S85>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat/volt4'
 * '<S86>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat/volt5'
 * '<S87>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat/volt6'
 * '<S88>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat/volt7'
 * '<S89>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat/volt8'
 * '<S90>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control2/volt.dat/volt9'
 */
#endif                                 /* RTW_HEADER_t15_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
