/*
 * File: t15_2.h
 *
 * Code generated for Simulink model 't15_2'.
 *
 * Model version                  : 1.1158
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue Jun 01 11:01:52 2021
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
#include "sfcn_bridge.h"
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
  real_T SFunction[17];                /* '<S5>/S-Function' */
  real_T Times;                        /* '<S5>/Time s' */
  real_T Memory2;                      /* '<S5>/Memory2' */
  real_T u;                            /* '<S5>/-1' */
  real_T Ip1e4;                        /* '<S5>/Ip<1e-4 ' */
  real_T DataStoreRead;                /* '<S5>/Data Store Read' */
  real_T Sum2;                         /* '<S5>/Sum2' */
  real_T DataStoreRead1;               /* '<S5>/Data Store Read1' */
  real_T e6;                           /* '<S14>/1e-6' */
  real_T e6_i[15];                     /* '<S14>/1e-6   ' */
  real_T Memory1;                      /* '<S17>/Memory1' */
  real_T DataStoreRead1_k;             /* '<S17>/Data Store Read1' */
  real_T e3;                           /* '<S17>/1e-3' */
  real_T DataStoreRead2;               /* '<S17>/Data Store Read2' */
  real_T Product1;                     /* '<S17>/Product1' */
  real_T RelationalOperator;           /* '<S17>/Relational Operator' */
  real_T Memory;                       /* '<S25>/Memory' */
  real_T LogicalOperator;              /* '<S25>/Logical Operator' */
  real_T switch1;                      /* '<S17>/switch1' */
  real_T Add2;                         /* '<S17>/Add2' */
  real_T DataStoreRead_o;              /* '<S17>/Data Store Read' */
  real_T Product;                      /* '<S17>/Product' */
  real_T Add1;                         /* '<S17>/Add1' */
  real_T u_f;                          /* '<S17>/1 0' */
  real_T Memory1_h;                    /* '<S18>/Memory1' */
  real_T c_eob;                        /* '<S18>/c_eob' */
  real_T Divide6;                      /* '<S18>/Divide6' */
  real_T Add1_l;                       /* '<S14>/Add1' */
  real_T SFunction1_d[100];            /* '<S21>/S-Function1' */
  real_T e2[6];                        /* '<S23>/1e2' */
  real_T SFunction1_m[100];            /* '<S44>/S-Function1' */
  real_T Memory2_l;                    /* '<S44>/Memory2' */
  real_T c_eob1;                       /* '<S44>/c_eob  1' */
  real_T Memory1_f;                    /* '<S44>/Memory1' */
  real_T c_eob_h;                      /* '<S44>/c_eob  ' */
  real_T SFunction1_p[100];            /* '<S50>/S-Function1' */
  real_T c_eob_b;                      /* '<S44>/c_eob' */
  real_T Add2_f;                       /* '<S23>/Add2' */
  real_T SFunction1_c[100];            /* '<S39>/S-Function1' */
  real_T Memory2_k;                    /* '<S39>/Memory2' */
  real_T c_eob1_d;                     /* '<S39>/c_eob  1' */
  real_T Memory1_i;                    /* '<S39>/Memory1' */
  real_T c_eob_a;                      /* '<S39>/c_eob  ' */
  real_T SFunction1_o[100];            /* '<S45>/S-Function1' */
  real_T c_eob_j;                      /* '<S39>/c_eob' */
  real_T Add1_j;                       /* '<S23>/Add1' */
  real_T SFunction1_j[100];            /* '<S40>/S-Function1' */
  real_T Memory2_n;                    /* '<S40>/Memory2' */
  real_T c_eob1_f;                     /* '<S40>/c_eob  1' */
  real_T Memory1_d;                    /* '<S40>/Memory1' */
  real_T c_eob_jz;                     /* '<S40>/c_eob  ' */
  real_T SFunction1_ce[100];           /* '<S46>/S-Function1' */
  real_T c_eob_l;                      /* '<S40>/c_eob' */
  real_T Add3;                         /* '<S23>/Add3' */
  real_T SFunction1_b[100];            /* '<S41>/S-Function1' */
  real_T Memory2_g;                    /* '<S41>/Memory2' */
  real_T c_eob1_c;                     /* '<S41>/c_eob  1' */
  real_T Memory1_k;                    /* '<S41>/Memory1' */
  real_T c_eob_aj;                     /* '<S41>/c_eob  ' */
  real_T SFunction1_os[100];           /* '<S47>/S-Function1' */
  real_T c_eob_bl;                     /* '<S41>/c_eob' */
  real_T Add4;                         /* '<S23>/Add4' */
  real_T DataStoreRead_h;              /* '<S23>/Data Store Read' */
  real_T RelationalOperator1;          /* '<S23>/Relational Operator1' */
  real_T Divide12;                     /* '<S23>/Divide12' */
  real_T SFunction1_cx[100];           /* '<S42>/S-Function1' */
  real_T Memory2_h;                    /* '<S42>/Memory2' */
  real_T c_eob1_g;                     /* '<S42>/c_eob  1' */
  real_T Memory1_g;                    /* '<S42>/Memory1' */
  real_T c_eob_d;                      /* '<S42>/c_eob  ' */
  real_T SFunction1_n[100];            /* '<S48>/S-Function1' */
  real_T c_eob_f;                      /* '<S42>/c_eob' */
  real_T Add5;                         /* '<S23>/Add5' */
  real_T SFunction1_i[100];            /* '<S43>/S-Function1' */
  real_T Memory2_nz;                   /* '<S43>/Memory2' */
  real_T c_eob1_h;                     /* '<S43>/c_eob  1' */
  real_T Memory1_p;                    /* '<S43>/Memory1' */
  real_T c_eob_o;                      /* '<S43>/c_eob  ' */
  real_T SFunction1_h[100];            /* '<S49>/S-Function1' */
  real_T c_eob_fp;                     /* '<S43>/c_eob' */
  real_T Add6;                         /* '<S23>/Add6' */
  real_T e2_f[6];                      /* '<S23>/1e-2' */
  real_T Memory2_ht;                   /* '<S28>/Memory2' */
  real_T c_eob_c;                      /* '<S28>/c_eob' */
  real_T Divide1;                      /* '<S28>/Divide1' */
  real_T Add3_k;                       /* '<S22>/Add3' */
  real_T Memory2_c;                    /* '<S31>/Memory2' */
  real_T c_eob_n;                      /* '<S31>/c_eob' */
  real_T Divide1_a;                    /* '<S31>/Divide1' */
  real_T Add1_g;                       /* '<S22>/Add1' */
  real_T Memory2_kb;                   /* '<S32>/Memory2' */
  real_T c_eob_k;                      /* '<S32>/c_eob' */
  real_T Divide1_b;                    /* '<S32>/Divide1' */
  real_T Add2_d;                       /* '<S22>/Add2' */
  real_T Memory2_b;                    /* '<S33>/Memory2' */
  real_T c_eob_g;                      /* '<S33>/c_eob' */
  real_T Divide1_d;                    /* '<S33>/Divide1' */
  real_T Add4_d;                       /* '<S22>/Add4' */
  real_T Memory2_bc;                   /* '<S34>/Memory2' */
  real_T c_eob_jp;                     /* '<S34>/c_eob' */
  real_T Divide1_i;                    /* '<S34>/Divide1' */
  real_T Add5_j;                       /* '<S22>/Add5' */
  real_T Memory2_p;                    /* '<S35>/Memory2' */
  real_T c_eob_m;                      /* '<S35>/c_eob' */
  real_T Divide1_l;                    /* '<S35>/Divide1' */
  real_T Add6_e;                       /* '<S22>/Add6' */
  real_T Memory2_a;                    /* '<S36>/Memory2' */
  real_T c_eob_cm;                     /* '<S36>/c_eob' */
  real_T Divide1_n;                    /* '<S36>/Divide1' */
  real_T Add7;                         /* '<S22>/Add7' */
  real_T Memory2_i;                    /* '<S37>/Memory2' */
  real_T c_eob_h3;                     /* '<S37>/c_eob' */
  real_T Divide1_dv;                   /* '<S37>/Divide1' */
  real_T Add8;                         /* '<S22>/Add8' */
  real_T Memory2_bl;                   /* '<S38>/Memory2' */
  real_T c_eob_gm;                     /* '<S38>/c_eob' */
  real_T Divide1_m;                    /* '<S38>/Divide1' */
  real_T Add9;                         /* '<S22>/Add9' */
  real_T Memory2_i0;                   /* '<S29>/Memory2' */
  real_T c_eob_cn;                     /* '<S29>/c_eob' */
  real_T Divide1_aa;                   /* '<S29>/Divide1' */
  real_T Add10;                        /* '<S22>/Add10' */
  real_T Memory2_ai;                   /* '<S30>/Memory2' */
  real_T c_eob_cg;                     /* '<S30>/c_eob' */
  real_T Divide1_k;                    /* '<S30>/Divide1' */
  real_T Add11;                        /* '<S22>/Add11' */
  real_T DataStoreRead_a;              /* '<S19>/Data Store Read' */
  real_T RelationalOperator1_e;        /* '<S19>/Relational Operator1' */
  real_T u_i[20];                      /* '<S19>/1' */
  real_T Uk1;                          /* '<S26>/UD' */
  real_T Diff;                         /* '<S26>/Diff' */
  real_T Uk1_n;                        /* '<S27>/UD' */
  real_T Diff_f;                       /* '<S27>/Diff' */
  real_T Divide;                       /* '<S20>/Divide' */
  real_T DataStoreRead_b;              /* '<S51>/Data Store Read' */
  real_T DataStoreRead1_j;             /* '<S51>/Data Store Read1' */
  real_T Memory3;                      /* '<S51>/Memory3' */
  real_T RelationalOperator1_k;        /* '<S51>/Relational Operator1' */
  real_T switch1_i;                    /* '<S51>/switch1 ' */
  real_T Subtract2;                    /* '<S51>/Subtract2' */
  real_T Divide1_mn;                   /* '<S51>/Divide1' */
  real_T Subtract1;                    /* '<S51>/Subtract1' */
  real_T Saturation1;                  /* '<S51>/Saturation1' */
  real_T e3_g[11];                     /* '<S52>/1e3' */
  real_T Abs[11];                      /* '<S52>/Abs' */
  real_T DataStoreRead1_m[11];         /* '<S15>/Data Store Read1' */
  real_T DataStoreRead2_l[11];         /* '<S52>/Data Store Read2' */
  real_T Divide5[11];                  /* '<S52>/Divide5' */
  real_T Sum2_c[11];                   /* '<S52>/Sum2' */
  real_T DataStoreRead1_kn;            /* '<S52>/Data Store Read1' */
  real_T Divide3[11];                  /* '<S52>/Divide3' */
  real_T Sum1[11];                     /* '<S52>/Sum1' */
  real_T Divide4[11];                  /* '<S52>/Divide4' */
  real_T Divide1_mz[11];               /* '<S52>/Divide1' */
  real_T Saturation[11];               /* '<S52>/Saturation' */
  real_T Memory1_ds[11];               /* '<S65>/Memory1' */
  real_T DataStoreRead_k;              /* '<S65>/Data Store Read' */
  real_T Abs_l;                        /* '<S65>/Abs' */
  real_T LogicalOperator2;             /* '<S65>/Logical Operator2' */
  real_T Memory_l[11];                 /* '<S57>/Memory' */
  real_T DataStoreRead_d;              /* '<S57>/Data Store Read' */
  real_T DataStoreRead1_i;             /* '<S57>/Data Store Read1' */
  real_T Abs_j;                        /* '<S57>/Abs' */
  real_T LogicalOperator1;             /* '<S57>/Logical Operator1' */
  real_T Memory1_j;                    /* '<S63>/Memory1' */
  real_T c_eob_i;                      /* '<S63>/c_eob' */
  real_T c_eob_ku;                     /* '<S15>/c_eob' */
  real_T Divide2[20];                  /* '<S15>/Divide2' */
  real_T Divcontr[11];                 /* '<S15>/Div. contr.' */
  real_T u_p[11];                      /* '<S57>/1' */
  real_T Memory1_fj;                   /* '<S61>/Memory1' */
  real_T DataStoreRead_i;              /* '<S61>/Data Store Read' */
  real_T LogicalOperator1_f;           /* '<S61>/Logical Operator1' */
  real_T switch1_g;                    /* '<S61>/switch1' */
  real_T Divide13[20];                 /* '<S15>/Divide13' */
  real_T Div_rdcontr[11];              /* '<S15>/Div_rd contr' */
  real_T u_fs[11];                     /* '<S65>/1' */
  real_T DataStoreRead_iz;             /* '<S53>/Data Store Read' */
  real_T Memory1_n;                    /* '<S53>/Memory1' */
  real_T DataStoreRead_f;              /* '<S70>/Data Store Read' */
  real_T Abs_k;                        /* '<S70>/Abs' */
  real_T LogicalOperator2_i;           /* '<S53>/Logical Operator2' */
  real_T u_j;                          /* '<S53>/1 ' */
  real_T Subtract2_k;                  /* '<S53>/Subtract2' */
  real_T Divide4_d;                    /* '<S53>/Divide4' */
  real_T Subtract3;                    /* '<S53>/Subtract3' */
  real_T Saturation_f;                 /* '<S53>/Saturation' */
  real_T Divide4_da[11];               /* '<S15>/Divide4' */
  real_T Currtermcontr[11];            /* '<S15>/Curr. term. contr' */
  real_T Subtract1_b;                  /* '<S53>/Subtract1' */
  real_T Divide5_n[11];                /* '<S15>/Divide5' */
  real_T Memory2_d[11];                /* '<S73>/Memory2' */
  real_T DataStoreRead1_h;             /* '<S73>/Data Store Read1' */
  real_T RelationalOperator1_d;        /* '<S73>/Relational Operator1' */
  real_T DataStoreRead_j;              /* '<S72>/Data Store Read' */
  real_T RelationalOperator_p;         /* '<S72>/Relational Operator' */
  real_T Divide12_l[20];               /* '<S72>/Divide12' */
  real_T Limcontr[11];                 /* '<S54>/Lim. contr.' */
  real_T Currcontr[11];                /* '<S54>/Curr. contr.' */
  real_T DataStoreRead2_a[11];         /* '<S54>/Data Store Read2' */
  real_T u_g[11];                      /* '<S73>/ 1 ' */
  real_T Divide14[11];                 /* '<S15>/Divide14' */
  real_T DataStoreRead_hz[500];        /* '<S83>/Data Store Read' */
  real_T u01[500];                     /* '<S83>/0.001' */
  real_T DataStoreRead1_p[500];        /* '<S83>/Data Store Read1' */
  real_T volt1;                        /* '<S83>/volt1' */
  real_T DataStoreRead_g[500];         /* '<S86>/Data Store Read' */
  real_T u01_e[500];                   /* '<S86>/0.001' */
  real_T DataStoreRead1_hx[500];       /* '<S86>/Data Store Read1' */
  real_T volt1_h;                      /* '<S86>/volt1' */
  real_T DataStoreRead_e[500];         /* '<S87>/Data Store Read' */
  real_T u01_g[500];                   /* '<S87>/0.001' */
  real_T DataStoreRead1_g[500];        /* '<S87>/Data Store Read1' */
  real_T volt1_g;                      /* '<S87>/volt1' */
  real_T DataStoreRead_i2[500];        /* '<S88>/Data Store Read' */
  real_T u01_d[500];                   /* '<S88>/0.001' */
  real_T DataStoreRead1_e[500];        /* '<S88>/Data Store Read1' */
  real_T volt1_hk;                     /* '<S88>/volt1' */
  real_T DataStoreRead_c[500];         /* '<S89>/Data Store Read' */
  real_T u01_b[500];                   /* '<S89>/0.001' */
  real_T DataStoreRead1_o[500];        /* '<S89>/Data Store Read1' */
  real_T volt1_l;                      /* '<S89>/volt1' */
  real_T DataStoreRead_ea[500];        /* '<S90>/Data Store Read' */
  real_T u01_p[500];                   /* '<S90>/0.001' */
  real_T DataStoreRead1_pg[500];       /* '<S90>/Data Store Read1' */
  real_T volt1_i;                      /* '<S90>/volt1' */
  real_T DataStoreRead_jf[500];        /* '<S91>/Data Store Read' */
  real_T u01_n[500];                   /* '<S91>/0.001' */
  real_T DataStoreRead1_gg[500];       /* '<S91>/Data Store Read1' */
  real_T volt1_n;                      /* '<S91>/volt1' */
  real_T DataStoreRead_f3[500];        /* '<S92>/Data Store Read' */
  real_T u01_h[500];                   /* '<S92>/0.001' */
  real_T DataStoreRead1_l[500];        /* '<S92>/Data Store Read1' */
  real_T volt1_p;                      /* '<S92>/volt1' */
  real_T DataStoreRead_dy[500];        /* '<S93>/Data Store Read' */
  real_T u01_f[500];                   /* '<S93>/0.001' */
  real_T DataStoreRead1_d[500];        /* '<S93>/Data Store Read1' */
  real_T volt1_f;                      /* '<S93>/volt1' */
  real_T DataStoreRead_m[500];         /* '<S84>/Data Store Read' */
  real_T u01_c[500];                   /* '<S84>/0.001' */
  real_T DataStoreRead1_b[500];        /* '<S84>/Data Store Read1' */
  real_T volt1_c;                      /* '<S84>/volt1' */
  real_T DataStoreRead_dl[500];        /* '<S85>/Data Store Read' */
  real_T u01_m[500];                   /* '<S85>/0.001' */
  real_T DataStoreRead1_b3[500];       /* '<S85>/Data Store Read1' */
  real_T volt1_i1;                     /* '<S85>/volt1' */
  real_T Subtract4;                    /* '<S53>/Subtract4' */
  real_T Divide7[11];                  /* '<S15>/Divide7' */
  real_T Sum3[11];                     /* '<S15>/Sum3' */
  real_T Divide2_i[11];                /* '<S52>/Divide2' */
  real_T LogicalOperator_d[11];        /* '<S52>/Logical Operator' */
  real_T Switch[11];                   /* '<S52>/Switch' */
  real_T Divide6_j[11];                /* '<S52>/Divide6' */
  real_T UniformRandomNumber;          /* '<S62>/Uniform Random Number' */
  real_T DataStoreRead_ga;             /* '<S79>/Data Store Read' */
  real_T u5;                           /* '<S79>/1.75' */
  real_T Divide11;                     /* '<S79>/Divide11' */
  real_T Uk1_o;                        /* '<S80>/UD' */
  real_T Diff_b;                       /* '<S80>/Diff' */
  real_T e3_j;                         /* '<S79>/2e3' */
  real_T Sqrt;                         /* '<S79>/Sqrt' */
  real_T Divide1_bm;                   /* '<S79>/Divide1' */
  real_T Sum2_cw;                      /* '<S62>/Sum2' */
  real_T DataStoreRead_kg;             /* '<S64>/Data Store Read' */
  real_T RelationalOperator1_i;        /* '<S64>/Relational Operator1' */
  real_T Divide12_m[2];                /* '<S64>/Divide12' */
  real_T VScontr[2];                   /* '<S59>/VS. contr' */
  real_T Divide4_c[2];                 /* '<S59>/Divide4' */
  real_T VScontrhl[2];                 /* '<S59>/VS. contr hl' */
  real_T c_eob_gx[2];                  /* '<S59>/c_eob' */
  real_T DataStoreRead1_n;             /* '<S58>/Data Store Read1' */
  real_T RelationalOperator2;          /* '<S58>/Relational Operator2' */
  real_T DataStoreRead_ml;             /* '<S58>/Data Store Read' */
  real_T Abs_c;                        /* '<S58>/Abs' */
  real_T RelationalOperator1_o;        /* '<S58>/Relational Operator1' */
  real_T LogicalOperator1_m;           /* '<S58>/Logical Operator1' */
  real_T DataStoreRead_ae;             /* '<S60>/Data Store Read' */
  real_T u5_i;                         /* '<S60>/1//15' */
  real_T Div;                          /* '<S60>/Div' */
  real_T u_d[2];                       /* '<S58>/1' */
  real_T Divide10[2];                  /* '<S15>/Divide10' */
  real_T G_curr_term[20];              /* '<S15>/G_curr_term' */
  real_T Divide12_h[20];               /* '<S15>/Divide12' */
  real_T Divide1_mzp[11];              /* '<S54>/Divide1' */
  real_T e6_j[11];                     /* '<S54>/1e6' */
  real_T DataStoreRead2_f[11];         /* '<S5>/Data Store Read2' */
  real_T Divide4_j[11];                /* '<S5>/Divide4' */
  real_T SFunction_j[44];              /* '<S1>/S-Function' */
  real_T DataStoreRead1_he[11];        /* '<S9>/Data Store Read1' */
  real_T Memory1_l[11];                /* '<S7>/Memory1' */
  real_T DataStoreRead1_i0[11];        /* '<S8>/Data Store Read1' */
  real_T u_gb[11];                     /* '<S8>/2' */
  real_T DataStoreRead3;               /* '<S8>/Data Store Read3' */
  real_T Divide1_ke[11];               /* '<S8>/Divide1' */
  real_T Add1_b[11];                   /* '<S7>/Add1' */
  real_T Uk1_i;                        /* '<S6>/UD' */
  real_T Diff_i;                       /* '<S6>/Diff' */
  real_T Divide_k[11];                 /* '<S7>/Divide' */
  real_T u_jm[11];                     /* '<S8>/-1' */
  real_T Switch_b[11];                 /* '<S10>/Switch' */
  real_T Switch2[11];                  /* '<S10>/Switch2' */
  real_T Divide1_a2[11];               /* '<S7>/Divide1' */
  real_T Add2_d0[11];                  /* '<S7>/Add2' */
  real_T Gain[11];                     /* '<S9>/Gain' */
  real_T Switch_h[11];                 /* '<S11>/Switch' */
  real_T Switch2_j[11];                /* '<S11>/Switch2' */
  real_T DataStoreRead2_g[11];         /* '<S2>/Data Store Read2' */
  real_T Divide3_m[11];                /* '<S2>/Divide3' */
  real_T Divide1_n2[11];               /* '<S2>/Divide1' */
  real_T DataStoreRead1_c;             /* '<S4>/Data Store Read1' */
  real_T Switch2_o;                    /* '<S12>/Switch2' */
  real_T Divide2_k[11];                /* '<S2>/Divide2' */
  real_T Add1_d[11];                   /* '<S2>/Add1' */
  real_T DataStoreRead1_hh;            /* '<S2>/Data Store Read1' */
  real_T Divide4_l;                    /* '<S2>/Divide4' */
  real_T DataStoreRead3_e;             /* '<S4>/Data Store Read3' */
  real_T Switch2_c;                    /* '<S13>/Switch2' */
  real_T Divide5_j;                    /* '<S2>/Divide5' */
  real_T TmpSignalConversionAtnpf12Inpor[12];
  real_T npf12[15];                    /* '<S2>/npf,12' */
  real_T Subtract2_c;                  /* '<S61>/Subtract2' */
  real_T DataStoreRead1_a;             /* '<S61>/Data Store Read1' */
  real_T Divide4_lu;                   /* '<S61>/Divide4' */
  real_T Subtract3_b;                  /* '<S61>/Subtract3' */
  real_T Saturation_p;                 /* '<S61>/Saturation' */
  real_T Subtract1_j;                  /* '<S61>/Subtract1' */
  real_T Divide3_n[11];                /* '<S15>/Divide3' */
  real_T Divide1_h[11];                /* '<S15>/Divide1' */
  real_T Sum2_l[11];                   /* '<S15>/Sum2' */
  real_T DataStoreRead_ji;             /* '<S15>/Data Store Read' */
  real_T u15;                          /* '<S15>/ 1//15' */
  real_T Divide6_m;                    /* '<S15>/Divide6' */
  real_T Switch2_j5;                   /* '<S55>/Switch2' */
  real_T Divide11_p[2];                /* '<S15>/Divide11' */
  real_T DataStoreRead3_h;             /* '<S15>/Data Store Read3' */
  real_T Switch_e;                     /* '<S55>/Switch' */
  real_T c_eob_kr[2];                  /* '<S15>/c_eob ' */
  real_T DataStoreRead1_gq;            /* '<S60>/Data Store Read1' */
  real_T RelationalOperator2_m;        /* '<S60>/Relational Operator2' */
  real_T LimDivtr;                     /* '<S60>/Lim. Div. tr.' */
  real_T Divide8[2];                   /* '<S15>/Divide8' */
  real_T SatDiv;                       /* '<S60>/Sat. Div' */
  real_T DataStoreRead2_c;             /* '<S60>/Data Store Read2' */
  real_T Switch2_f;                    /* '<S77>/Switch2' */
  real_T Switch_g;                     /* '<S77>/Switch' */
  real_T u5_g;                         /* '<S15>/1//15' */
  real_T Switch2_p;                    /* '<S56>/Switch2' */
  real_T Divide_d[2];                  /* '<S15>/Divide ' */
  real_T DataStoreRead4;               /* '<S15>/Data Store Read4' */
  real_T Switch_n;                     /* '<S56>/Switch' */
  real_T Subtract3_i;                  /* '<S51>/Subtract3' */
  real_T Divide_j[11];                 /* '<S15>/Divide' */
  real_T DataStoreRead_p;              /* '<S73>/Data Store Read' */
  real_T RelationalOperator_i;         /* '<S73>/Relational Operator' */
  real_T u_l[11];                      /* '<S73>/1' */
  real_T DataStoreRead1_ko;            /* '<S71>/Data Store Read1' */
  real_T DataStoreRead_md;             /* '<S71>/Data Store Read' */
  real_T Subtract3_e;                  /* '<S71>/Subtract3' */
  real_T Divide2_o;                    /* '<S71>/Divide2' */
  real_T Saturation1_c;                /* '<S71>/Saturation1' */
  real_T Divide_m[11];                 /* '<S54>/Divide ' */
  real_T Divide2_a[11];                /* '<S54>/Divide2' */
  real_T DataStoreRead2_i;             /* '<S15>/Data Store Read2' */
  real_T u15_j;                        /* '<S15>/ 1//15 ' */
  real_T Divide9;                      /* '<S15>/Divide9' */
  real_T Saturation_h;                 /* '<S15>/Saturation' */
  real_T DataStoreRead2_j;             /* '<S63>/Data Store Read2' */
  real_T Sum3_p;                       /* '<S63>/Sum3' */
  real_T DataStoreRead4_h;             /* '<S63>/Data Store Read4' */
  real_T DataStoreRead3_k;             /* '<S63>/Data Store Read3' */
  real_T Sum2_g;                       /* '<S63>/Sum2' */
  real_T Divide1_j;                    /* '<S63>/Divide1' */
  real_T Divide6_f;                    /* '<S63>/Divide6' */
  real_T Sum;                          /* '<S63>/Sum' */
  real_T Divide2_h;                    /* '<S63>/Divide2' */
  real_T Sum1_n;                       /* '<S63>/Sum1' */
  real_T Switch2_h;                    /* '<S81>/Switch2' */
  real_T Switch_d;                     /* '<S81>/Switch' */
  real_T Selector[49];                 /* '<S50>/Selector' */
  real_T TmpSignalConversionAtg1_termref[50];
  real_T DataStoreRead1_en;            /* '<S50>/Data Store Read1' */
  real_T DataStoreRead_n;              /* '<S50>/Data Store Read' */
  real_T Selector1[50];                /* '<S50>/Selector1' */
  real_T Divide6_a[50];                /* '<S50>/Divide6' */
  real_T Add2_h[50];                   /* '<S50>/Add2' */
  real_T g1_termref;                   /* '<S50>/g1_term,ref' */
  real_T Selector_j[50];               /* '<S44>/Selector' */
  real_T Selector1_d[50];              /* '<S44>/Selector1' */
  real_T g1ref;                        /* '<S44>/g1ref' */
  real_T Selector_f[49];               /* '<S49>/Selector' */
  real_T TmpSignalConversionAtg6_termref[50];
  real_T DataStoreRead1_f;             /* '<S49>/Data Store Read1' */
  real_T DataStoreRead_jr;             /* '<S49>/Data Store Read' */
  real_T Selector1_dx[50];             /* '<S49>/Selector1' */
  real_T Divide6_b[50];                /* '<S49>/Divide6' */
  real_T Add2_g[50];                   /* '<S49>/Add2' */
  real_T g6_termref;                   /* '<S49>/g6_term,ref' */
  real_T Selector_i[50];               /* '<S43>/Selector' */
  real_T Selector1_b[50];              /* '<S43>/Selector1' */
  real_T g6ref;                        /* '<S43>/g6ref' */
  real_T Selector_d[49];               /* '<S48>/Selector' */
  real_T TmpSignalConversionAtg5_termref[50];
  real_T DataStoreRead1_am;            /* '<S48>/Data Store Read1' */
  real_T DataStoreRead_jrb;            /* '<S48>/Data Store Read' */
  real_T Selector1_n[50];              /* '<S48>/Selector1' */
  real_T Divide6_g[50];                /* '<S48>/Divide6' */
  real_T Add2_k[50];                   /* '<S48>/Add2' */
  real_T g5_termref;                   /* '<S48>/g5_term,ref' */
  real_T Selector_p[50];               /* '<S42>/Selector' */
  real_T Selector1_m[50];              /* '<S42>/Selector1' */
  real_T g5ref;                        /* '<S42>/g5ref' */
  real_T Selector_py[49];              /* '<S47>/Selector' */
  real_T TmpSignalConversionAtg4_termref[50];
  real_T DataStoreRead1_jh;            /* '<S47>/Data Store Read1' */
  real_T DataStoreRead_bn;             /* '<S47>/Data Store Read' */
  real_T Selector1_h[50];              /* '<S47>/Selector1' */
  real_T Divide6_d[50];                /* '<S47>/Divide6' */
  real_T Add2_a[50];                   /* '<S47>/Add2' */
  real_T g4_termref;                   /* '<S47>/g4_term,ref' */
  real_T Selector_b[50];               /* '<S41>/Selector' */
  real_T Selector1_k[50];              /* '<S41>/Selector1' */
  real_T g4ref;                        /* '<S41>/g4ref' */
  real_T Selector_e[49];               /* '<S46>/Selector' */
  real_T TmpSignalConversionAtg3_termref[50];
  real_T DataStoreRead1_er;            /* '<S46>/Data Store Read1' */
  real_T DataStoreRead_ar;             /* '<S46>/Data Store Read' */
  real_T Selector1_j[50];              /* '<S46>/Selector1' */
  real_T Divide6_p[50];                /* '<S46>/Divide6' */
  real_T Add2_i[50];                   /* '<S46>/Add2' */
  real_T g3_termref;                   /* '<S46>/g3_term,ref' */
  real_T Selector_jj[50];              /* '<S40>/Selector' */
  real_T Selector1_df[50];             /* '<S40>/Selector1' */
  real_T g3ref;                        /* '<S40>/g3ref' */
  real_T Selector_n[49];               /* '<S45>/Selector' */
  real_T TmpSignalConversionAtg2_termref[50];
  real_T DataStoreRead1_hn;            /* '<S45>/Data Store Read1' */
  real_T DataStoreRead_jp;             /* '<S45>/Data Store Read' */
  real_T Selector1_i[50];              /* '<S45>/Selector1' */
  real_T Divide6_h[50];                /* '<S45>/Divide6' */
  real_T Add2_fo[50];                  /* '<S45>/Add2' */
  real_T g2_termref;                   /* '<S45>/g2_term,ref' */
  real_T Selector_o[50];               /* '<S39>/Selector' */
  real_T Selector1_f[50];              /* '<S39>/Selector1' */
  real_T g2ref;                        /* '<S39>/g2ref' */
  real_T DataStoreRead1_gh[500];       /* '<S38>/Data Store Read1' */
  real_T DataStoreRead_jm[500];        /* '<S38>/Data Store Read' */
  real_T I1;                           /* '<S38>/I1' */
  real_T DataStoreRead1_dz[500];       /* '<S37>/Data Store Read1' */
  real_T DataStoreRead_nv[500];        /* '<S37>/Data Store Read' */
  real_T I1_j;                         /* '<S37>/I1' */
  real_T DataStoreRead1_nh[500];       /* '<S36>/Data Store Read1' */
  real_T DataStoreRead_i3[500];        /* '<S36>/Data Store Read' */
  real_T I1_i;                         /* '<S36>/I1' */
  real_T DataStoreRead1_bc[500];       /* '<S35>/Data Store Read1' */
  real_T DataStoreRead_cr[500];        /* '<S35>/Data Store Read' */
  real_T I1_m;                         /* '<S35>/I1' */
  real_T DataStoreRead1_ii[500];       /* '<S34>/Data Store Read1' */
  real_T DataStoreRead_mc[500];        /* '<S34>/Data Store Read' */
  real_T I1_d;                         /* '<S34>/I1' */
  real_T DataStoreRead1_gu[500];       /* '<S33>/Data Store Read1' */
  real_T DataStoreRead_hk[500];        /* '<S33>/Data Store Read' */
  real_T I1_n;                         /* '<S33>/I1' */
  real_T DataStoreRead1_ey[500];       /* '<S32>/Data Store Read1' */
  real_T DataStoreRead_ma[500];        /* '<S32>/Data Store Read' */
  real_T I1_a;                         /* '<S32>/I1' */
  real_T DataStoreRead1_os[500];       /* '<S31>/Data Store Read1' */
  real_T DataStoreRead_dj[500];        /* '<S31>/Data Store Read' */
  real_T I1_p;                         /* '<S31>/I1' */
  real_T DataStoreRead1_pa[500];       /* '<S30>/Data Store Read1' */
  real_T DataStoreRead_e0[500];        /* '<S30>/Data Store Read' */
  real_T I1_e;                         /* '<S30>/I1' */
  real_T DataStoreRead1_li[500];       /* '<S29>/Data Store Read1' */
  real_T DataStoreRead_ay[500];        /* '<S29>/Data Store Read' */
  real_T I1_o;                         /* '<S29>/I1' */
  real_T DataStoreRead1_ph[500];       /* '<S28>/Data Store Read1' */
  real_T DataStoreRead_ho[500];        /* '<S28>/Data Store Read' */
  real_T I1_b;                         /* '<S28>/I1' */
  real_T Selector_h[50];               /* '<S21>/Selector' */
  real_T Selector1_a[50];              /* '<S21>/Selector1' */
  real_T elong;                        /* '<S21>/elong' */
  real_T Add2_gh;                      /* '<S14>/Add2' */
  real_T DataStoreRead1_jm;            /* '<S24>/Data Store Read1' */
  real_T Divide_h[4];                  /* '<S24>/Divide' */
  real_T DataStoreRead1_iq[500];       /* '<S18>/Data Store Read1' */
  real_T DataStoreRead_df[500];        /* '<S18>/Data Store Read' */
  real_T Ipref;                        /* '<S18>/Ipref' */
  real_T Gain1;                        /* '<S4>/Gain1' */
  real_T Switch_l;                     /* '<S13>/Switch' */
  real_T Gain_g;                       /* '<S4>/Gain' */
  real_T Switch_dy;                    /* '<S12>/Switch' */
  uint8_T Compare[11];                 /* '<S67>/Compare' */
  uint8_T Compare_o[11];               /* '<S68>/Compare' */
  boolean_T RelationalOperator_c;      /* '<S5>/Relational Operator' */
  boolean_T RelationalOperator1_h;     /* '<S5>/Relational Operator1' */
  boolean_T RelationalOperator_o;      /* '<S65>/Relational Operator' */
  boolean_T Compare_k;                 /* '<S82>/Compare' */
  boolean_T RelationalOperator1_m;     /* '<S57>/Relational Operator1' */
  boolean_T Compare_e;                 /* '<S74>/Compare' */
  boolean_T RelationalOperator_k;      /* '<S57>/Relational Operator' */
  boolean_T RelationalOperator1_hw;    /* '<S61>/Relational Operator1' */
  boolean_T Compare_m;                 /* '<S78>/Compare' */
  boolean_T RelationalOperator_b;      /* '<S70>/Relational Operator' */
  boolean_T Compare_et;                /* '<S69>/Compare' */
  boolean_T Compare_a;                 /* '<S76>/Compare' */
  boolean_T Compare_j;                 /* '<S75>/Compare' */
  boolean_T LowerRelop1[11];           /* '<S10>/LowerRelop1' */
  boolean_T UpperRelop[11];            /* '<S10>/UpperRelop' */
  boolean_T LowerRelop1_a[11];         /* '<S11>/LowerRelop1' */
  boolean_T UpperRelop_b[11];          /* '<S11>/UpperRelop' */
  boolean_T LowerRelop1_i;             /* '<S12>/LowerRelop1' */
  boolean_T LowerRelop1_o;             /* '<S13>/LowerRelop1' */
  boolean_T LowerRelop1_l;             /* '<S55>/LowerRelop1' */
  boolean_T UpperRelop_i;              /* '<S55>/UpperRelop' */
  boolean_T LowerRelop1_n;             /* '<S77>/LowerRelop1' */
  boolean_T UpperRelop_o;              /* '<S77>/UpperRelop' */
  boolean_T LowerRelop1_k;             /* '<S56>/LowerRelop1' */
  boolean_T UpperRelop_g;              /* '<S56>/UpperRelop' */
  boolean_T LowerRelop1_ah;            /* '<S81>/LowerRelop1' */
  boolean_T UpperRelop_a;              /* '<S81>/UpperRelop' */
  boolean_T UpperRelop_oc;             /* '<S13>/UpperRelop' */
  boolean_T UpperRelop_ae;             /* '<S12>/UpperRelop' */
} BlockIO_t15_2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S26>/UD' */
  real_T UD_DSTATE_c;                  /* '<S27>/UD' */
  real_T Divcontr_DSTATE[32];          /* '<S15>/Div. contr.' */
  real_T Div_rdcontr_DSTATE[22];       /* '<S15>/Div_rd contr' */
  real_T Currtermcontr_DSTATE[22];     /* '<S15>/Curr. term. contr' */
  real_T Limcontr_DSTATE[46];          /* '<S54>/Lim. contr.' */
  real_T Currcontr_DSTATE[11];         /* '<S54>/Curr. contr.' */
  real_T UD_DSTATE_o;                  /* '<S80>/UD' */
  real_T VScontr_DSTATE[9];            /* '<S59>/VS. contr' */
  real_T VScontrhl_DSTATE[8];          /* '<S59>/VS. contr hl' */
  real_T UD_DSTATE_p;                  /* '<S6>/UD' */
  real_T Memory2_PreviousInput;        /* '<S5>/Memory2' */
  real_T Memory1_PreviousInput;        /* '<S17>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S25>/Memory' */
  real_T Memory1_PreviousInput_p;      /* '<S18>/Memory1' */
  real_T Memory2_PreviousInput_h;      /* '<S44>/Memory2' */
  real_T Memory1_PreviousInput_k;      /* '<S44>/Memory1' */
  real_T Memory2_PreviousInput_o;      /* '<S39>/Memory2' */
  real_T Memory1_PreviousInput_d;      /* '<S39>/Memory1' */
  real_T Memory2_PreviousInput_j;      /* '<S40>/Memory2' */
  real_T Memory1_PreviousInput_m;      /* '<S40>/Memory1' */
  real_T Memory2_PreviousInput_e;      /* '<S41>/Memory2' */
  real_T Memory1_PreviousInput_py;     /* '<S41>/Memory1' */
  real_T Memory2_PreviousInput_k;      /* '<S42>/Memory2' */
  real_T Memory1_PreviousInput_h;      /* '<S42>/Memory1' */
  real_T Memory2_PreviousInput_n;      /* '<S43>/Memory2' */
  real_T Memory1_PreviousInput_g;      /* '<S43>/Memory1' */
  real_T Memory2_PreviousInput_b;      /* '<S28>/Memory2' */
  real_T Memory2_PreviousInput_bu;     /* '<S31>/Memory2' */
  real_T Memory2_PreviousInput_op;     /* '<S32>/Memory2' */
  real_T Memory2_PreviousInput_f;      /* '<S33>/Memory2' */
  real_T Memory2_PreviousInput_hg;     /* '<S34>/Memory2' */
  real_T Memory2_PreviousInput_g;      /* '<S35>/Memory2' */
  real_T Memory2_PreviousInput_c;      /* '<S36>/Memory2' */
  real_T Memory2_PreviousInput_jv;     /* '<S37>/Memory2' */
  real_T Memory2_PreviousInput_hu;     /* '<S38>/Memory2' */
  real_T Memory2_PreviousInput_g2;     /* '<S29>/Memory2' */
  real_T Memory2_PreviousInput_b1;     /* '<S30>/Memory2' */
  real_T Memory3_PreviousInput;        /* '<S51>/Memory3' */
  real_T Memory1_PreviousInput_c[11];  /* '<S65>/Memory1' */
  real_T Memory_PreviousInput_j[11];   /* '<S57>/Memory' */
  real_T Memory1_PreviousInput_i;      /* '<S63>/Memory1' */
  real_T Memory1_PreviousInput_ic;     /* '<S61>/Memory1' */
  real_T Memory1_PreviousInput_gz;     /* '<S53>/Memory1' */
  real_T Memory2_PreviousInput_cm[11]; /* '<S73>/Memory2' */
  real_T UniformRandomNumber_NextOutput;/* '<S62>/Uniform Random Number' */
  real_T scr_data[6500];               /* '<S5>/Data Store Memory' */
  real_T volt[10000];                  /* '<S5>/Data Store Memory1' */
  real_T c_a_tpl1_eob;                 /* '<S5>/Data Store Memory10' */
  real_T c_a_tpl2;                     /* '<S5>/Data Store Memory11' */
  real_T c_a_tpl_min;                  /* '<S5>/Data Store Memory12' */
  real_T y0;                           /* '<S5>/Data Store Memory13' */
  real_T c1_y0;                        /* '<S5>/Data Store Memory14' */
  real_T c2_y0;                        /* '<S5>/Data Store Memory15' */
  real_T t_tran2D;                     /* '<S5>/Data Store Memory16' */
  real_T max_VS_lim;                   /* '<S5>/Data Store Memory17' */
  real_T k_g4;                         /* '<S5>/Data Store Memory18' */
  real_T c_a_tpl1;                     /* '<S5>/Data Store Memory2' */
  real_T tcont2;                       /* '<S5>/Data Store Memory3' */
  real_T Ip_div;                       /* '<S5>/Data Store Memory4' */
  real_T ref_ramp;                     /* '<S5>/Data Store Memory5' */
  real_T dtcont2;                      /* '<S5>/Data Store Memory6' */
  real_T Ip_rd;                        /* '<S5>/Data Store Memory7' */
  real_T trd_ref;                      /* '<S5>/Data Store Memory8' */
  real_T Time_stop;                    /* '<S5>/Data Store Memory9' */
  real_T Memory1_PreviousInput_i1[11]; /* '<S7>/Memory1' */
  real_T ntur[12];                     /* '<S1>/Data Store Memory1' */
  real_T RupRd[6];                     /* '<S1>/Data Store Memory2' */
  real_T VS3_up;                       /* '<S1>/Data Store Memory3' */
  real_T Vcspf_up[11];                 /* '<S1>/Data Store Memory4' */
  real_T VS1_up;                       /* '<S1>/Data Store Memory5' */
  real_T Tu;                           /* '<S1>/Data Store Memory7' */
  real_T c_cur_max;                    /* '<S1>/Data Store Memory8' */
  real_T Imax[11];                     /* '<S1>/Data Store Memory9' */
  uint32_T RandSeed;                   /* '<S62>/Uniform Random Number' */
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
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant4'
                                        */
  real_T _Value;                       /* Expression: 1
                                        * Referenced by: '<S63>/2'
                                        */
  real_T _Value_e;                     /* Expression: 1
                                        * Referenced by: '<S63>/1'
                                        */
  real_T u15_Gain;                     /* Expression: 1/15
                                        * Referenced by: '<S15>/ 1//15 '
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S71>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S71>/Saturation1'
                                        */
  real_T _Threshold;                   /* Expression: 1
                                        * Referenced by: '<S73>/1'
                                        */
  real_T u5_Gain;                      /* Expression: 1/15
                                        * Referenced by: '<S15>/1//15'
                                        */
  real_T _Value_k;                     /* Expression: 1
                                        * Referenced by: '<S15>/2'
                                        */
  real_T _Value_l;                     /* Expression: 0
                                        * Referenced by: '<S60>/1'
                                        */
  real_T SatDiv_UpperSat;              /* Expression: 1
                                        * Referenced by: '<S60>/Sat. Div'
                                        */
  real_T SatDiv_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S60>/Sat. Div'
                                        */
  real_T LimDivtr_Threshold;           /* Expression: 1
                                        * Referenced by: '<S60>/Lim. Div. tr.'
                                        */
  real_T c_eob_Threshold;              /* Expression: 1
                                        * Referenced by: '<S15>/c_eob '
                                        */
  real_T u15_Gain_m;                   /* Expression: 1/15
                                        * Referenced by: '<S15>/ 1//15'
                                        */
  real_T _Value_b;                     /* Expression: 1
                                        * Referenced by: '<S15>/1'
                                        */
  real_T _Value_i;                     /* Expression: 1
                                        * Referenced by: '<S61>/1'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: 1
                                        * Referenced by: '<S61>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: 0
                                        * Referenced by: '<S61>/Saturation'
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
  real_T Times_Gain;                   /* Expression: 1e-3
                                        * Referenced by: '<S5>/Time s'
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
  real_T e6_Gain;                      /* Expression: 1e-6
                                        * Referenced by: '<S14>/1e-6'
                                        */
  real_T e6_Gain_h;                    /* Expression: 1e-6
                                        * Referenced by: '<S14>/1e-6   '
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S17>/Memory1'
                                        */
  real_T e3_Gain;                      /* Expression: 1e-3
                                        * Referenced by: '<S17>/1e-3'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S25>/Memory'
                                        */
  real_T switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<S17>/switch1'
                                        */
  real_T Constant4_Value_j;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant4'
                                        */
  real_T u_UpperSat;                   /* Expression: 1
                                        * Referenced by: '<S17>/1 0'
                                        */
  real_T u_LowerSat;                   /* Expression: 0
                                        * Referenced by: '<S17>/1 0'
                                        */
  real_T Memory1_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S18>/Memory1'
                                        */
  real_T c_eob_Threshold_m;            /* Expression: 1
                                        * Referenced by: '<S18>/c_eob'
                                        */
  real_T SFunction1_P1_Size_j[2];      /* Computed Parameter: SFunction1_P1_Size_j
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  real_T SFunction1_P1_l;              /* Expression: 0
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  real_T Constant4_Value_p;            /* Expression: 0
                                        * Referenced by: '<S14>/Constant4'
                                        */
  real_T e2_Gain;                      /* Expression: 1e2
                                        * Referenced by: '<S23>/1e2'
                                        */
  real_T SFunction1_P1_Size_a[2];      /* Computed Parameter: SFunction1_P1_Size_a
                                        * Referenced by: '<S44>/S-Function1'
                                        */
  real_T SFunction1_P1_d;              /* Expression: 1
                                        * Referenced by: '<S44>/S-Function1'
                                        */
  real_T Memory2_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S44>/Memory2'
                                        */
  real_T c_eob1_Threshold;             /* Expression: 1
                                        * Referenced by: '<S44>/c_eob  1'
                                        */
  real_T Memory1_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S44>/Memory1'
                                        */
  real_T c_eob_Threshold_j;            /* Expression: 1
                                        * Referenced by: '<S44>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_g[2];      /* Computed Parameter: SFunction1_P1_Size_g
                                        * Referenced by: '<S50>/S-Function1'
                                        */
  real_T SFunction1_P1_a;              /* Expression: 1
                                        * Referenced by: '<S50>/S-Function1'
                                        */
  real_T c_eob_Threshold_a;            /* Expression: 1
                                        * Referenced by: '<S44>/c_eob'
                                        */
  real_T SFunction1_P1_Size_o[2];      /* Computed Parameter: SFunction1_P1_Size_o
                                        * Referenced by: '<S39>/S-Function1'
                                        */
  real_T SFunction1_P1_o;              /* Expression: 2
                                        * Referenced by: '<S39>/S-Function1'
                                        */
  real_T Memory2_X0_go;                /* Expression: 0
                                        * Referenced by: '<S39>/Memory2'
                                        */
  real_T c_eob1_Threshold_d;           /* Expression: 1
                                        * Referenced by: '<S39>/c_eob  1'
                                        */
  real_T Memory1_X0_fd;                /* Expression: 0
                                        * Referenced by: '<S39>/Memory1'
                                        */
  real_T c_eob_Threshold_o;            /* Expression: 1
                                        * Referenced by: '<S39>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_p[2];      /* Computed Parameter: SFunction1_P1_Size_p
                                        * Referenced by: '<S45>/S-Function1'
                                        */
  real_T SFunction1_P1_ab;             /* Expression: 2
                                        * Referenced by: '<S45>/S-Function1'
                                        */
  real_T c_eob_Threshold_jr;           /* Expression: 1
                                        * Referenced by: '<S39>/c_eob'
                                        */
  real_T SFunction1_P1_Size_c[2];      /* Computed Parameter: SFunction1_P1_Size_c
                                        * Referenced by: '<S40>/S-Function1'
                                        */
  real_T SFunction1_P1_m;              /* Expression: 3
                                        * Referenced by: '<S40>/S-Function1'
                                        */
  real_T Memory2_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S40>/Memory2'
                                        */
  real_T c_eob1_Threshold_m;           /* Expression: 1
                                        * Referenced by: '<S40>/c_eob  1'
                                        */
  real_T Memory1_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S40>/Memory1'
                                        */
  real_T c_eob_Threshold_e;            /* Expression: 1
                                        * Referenced by: '<S40>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_j1[2];     /* Computed Parameter: SFunction1_P1_Size_j1
                                        * Referenced by: '<S46>/S-Function1'
                                        */
  real_T SFunction1_P1_e;              /* Expression: 3
                                        * Referenced by: '<S46>/S-Function1'
                                        */
  real_T c_eob_Threshold_on;           /* Expression: 1
                                        * Referenced by: '<S40>/c_eob'
                                        */
  real_T SFunction1_P1_Size_cj[2];     /* Computed Parameter: SFunction1_P1_Size_cj
                                        * Referenced by: '<S41>/S-Function1'
                                        */
  real_T SFunction1_P1_n;              /* Expression: 4
                                        * Referenced by: '<S41>/S-Function1'
                                        */
  real_T Memory2_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S41>/Memory2'
                                        */
  real_T c_eob1_Threshold_g;           /* Expression: 1
                                        * Referenced by: '<S41>/c_eob  1'
                                        */
  real_T Memory1_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S41>/Memory1'
                                        */
  real_T c_eob_Threshold_c;            /* Expression: 1
                                        * Referenced by: '<S41>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_e[2];      /* Computed Parameter: SFunction1_P1_Size_e
                                        * Referenced by: '<S47>/S-Function1'
                                        */
  real_T SFunction1_P1_ng;             /* Expression: 4
                                        * Referenced by: '<S47>/S-Function1'
                                        */
  real_T c_eob_Threshold_onc;          /* Expression: 1
                                        * Referenced by: '<S41>/c_eob'
                                        */
  real_T SFunction1_P1_Size_m[2];      /* Computed Parameter: SFunction1_P1_Size_m
                                        * Referenced by: '<S42>/S-Function1'
                                        */
  real_T SFunction1_P1_on;             /* Expression: 5
                                        * Referenced by: '<S42>/S-Function1'
                                        */
  real_T Memory2_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S42>/Memory2'
                                        */
  real_T c_eob1_Threshold_k;           /* Expression: 1
                                        * Referenced by: '<S42>/c_eob  1'
                                        */
  real_T Memory1_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S42>/Memory1'
                                        */
  real_T c_eob_Threshold_a5;           /* Expression: 1
                                        * Referenced by: '<S42>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_i[2];      /* Computed Parameter: SFunction1_P1_Size_i
                                        * Referenced by: '<S48>/S-Function1'
                                        */
  real_T SFunction1_P1_ow;             /* Expression: 5
                                        * Referenced by: '<S48>/S-Function1'
                                        */
  real_T c_eob_Threshold_f;            /* Expression: 1
                                        * Referenced by: '<S42>/c_eob'
                                        */
  real_T SFunction1_P1_Size_cq[2];     /* Computed Parameter: SFunction1_P1_Size_cq
                                        * Referenced by: '<S43>/S-Function1'
                                        */
  real_T SFunction1_P1_j;              /* Expression: 6
                                        * Referenced by: '<S43>/S-Function1'
                                        */
  real_T Memory2_X0_hw;                /* Expression: 0
                                        * Referenced by: '<S43>/Memory2'
                                        */
  real_T c_eob1_Threshold_o;           /* Expression: 1
                                        * Referenced by: '<S43>/c_eob  1'
                                        */
  real_T Memory1_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S43>/Memory1'
                                        */
  real_T c_eob_Threshold_d;            /* Expression: 1
                                        * Referenced by: '<S43>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_ca[2];     /* Computed Parameter: SFunction1_P1_Size_ca
                                        * Referenced by: '<S49>/S-Function1'
                                        */
  real_T SFunction1_P1_c;              /* Expression: 6
                                        * Referenced by: '<S49>/S-Function1'
                                        */
  real_T c_eob_Threshold_ci;           /* Expression: 1
                                        * Referenced by: '<S43>/c_eob'
                                        */
  real_T e2_Gain_e;                    /* Expression: 1e-2
                                        * Referenced by: '<S23>/1e-2'
                                        */
  real_T Memory2_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S28>/Memory2'
                                        */
  real_T c_eob_Threshold_jx;           /* Expression: 1
                                        * Referenced by: '<S28>/c_eob'
                                        */
  real_T Memory2_X0_d;                 /* Expression: 0
                                        * Referenced by: '<S31>/Memory2'
                                        */
  real_T c_eob_Threshold_ao;           /* Expression: 1
                                        * Referenced by: '<S31>/c_eob'
                                        */
  real_T Memory2_X0_bb;                /* Expression: 0
                                        * Referenced by: '<S32>/Memory2'
                                        */
  real_T c_eob_Threshold_k;            /* Expression: 1
                                        * Referenced by: '<S32>/c_eob'
                                        */
  real_T Memory2_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S33>/Memory2'
                                        */
  real_T c_eob_Threshold_j5;           /* Expression: 1
                                        * Referenced by: '<S33>/c_eob'
                                        */
  real_T Memory2_X0_fe;                /* Expression: 0
                                        * Referenced by: '<S34>/Memory2'
                                        */
  real_T c_eob_Threshold_h;            /* Expression: 1
                                        * Referenced by: '<S34>/c_eob'
                                        */
  real_T Memory2_X0_bm;                /* Expression: 0
                                        * Referenced by: '<S35>/Memory2'
                                        */
  real_T c_eob_Threshold_jv;           /* Expression: 1
                                        * Referenced by: '<S35>/c_eob'
                                        */
  real_T Memory2_X0_hs;                /* Expression: 0
                                        * Referenced by: '<S36>/Memory2'
                                        */
  real_T c_eob_Threshold_mo;           /* Expression: 1
                                        * Referenced by: '<S36>/c_eob'
                                        */
  real_T Memory2_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S37>/Memory2'
                                        */
  real_T c_eob_Threshold_g;            /* Expression: 1
                                        * Referenced by: '<S37>/c_eob'
                                        */
  real_T Memory2_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S38>/Memory2'
                                        */
  real_T c_eob_Threshold_n;            /* Expression: 1
                                        * Referenced by: '<S38>/c_eob'
                                        */
  real_T Memory2_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S29>/Memory2'
                                        */
  real_T c_eob_Threshold_b;            /* Expression: 1
                                        * Referenced by: '<S29>/c_eob'
                                        */
  real_T Memory2_X0_ev;                /* Expression: 0
                                        * Referenced by: '<S30>/Memory2'
                                        */
  real_T c_eob_Threshold_hc;           /* Expression: 1
                                        * Referenced by: '<S30>/c_eob'
                                        */
  real_T _Threshold_m;                 /* Expression: 1
                                        * Referenced by: '<S19>/1'
                                        */
  real_T UD_InitialCondition;          /* Expression: ICPrevInput
                                        * Referenced by: '<S26>/UD'
                                        */
  real_T UD_InitialCondition_b;        /* Expression: ICPrevInput
                                        * Referenced by: '<S27>/UD'
                                        */
  real_T _Value_h;                     /* Expression: 1
                                        * Referenced by: '<S51>/1'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S51>/Memory3'
                                        */
  real_T switch1_Threshold_j;          /* Expression: 1
                                        * Referenced by: '<S51>/switch1 '
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: 1
                                        * Referenced by: '<S51>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_g;       /* Expression: 0
                                        * Referenced by: '<S51>/Saturation1'
                                        */
  real_T _Value_p;                     /* Expression: 1
                                        * Referenced by: '<S52>/1'
                                        */
  real_T e3_Gain_m;                    /* Expression: 1e3
                                        * Referenced by: '<S52>/1e3'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 1
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: -1
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S67>/Constant'
                                        */
  real_T Memory1_X0_fk;                /* Expression: 0
                                        * Referenced by: '<S65>/Memory1'
                                        */
  real_T Constant_Value_n;             /* Expression: const
                                        * Referenced by: '<S82>/Constant'
                                        */
  real_T Memory_X0_p;                  /* Expression: 0
                                        * Referenced by: '<S57>/Memory'
                                        */
  real_T Constant_Value_n1;            /* Expression: const
                                        * Referenced by: '<S74>/Constant'
                                        */
  real_T Memory1_X0_ef;                /* Expression: 0
                                        * Referenced by: '<S63>/Memory1'
                                        */
  real_T c_eob_Threshold_ah;           /* Expression: 1
                                        * Referenced by: '<S63>/c_eob'
                                        */
  real_T c_eob_Threshold_a1;           /* Expression: 1
                                        * Referenced by: '<S15>/c_eob'
                                        */
  real_T Divcontr_A[572];              /* Computed Parameter: Divcontr_A
                                        * Referenced by: '<S15>/Div. contr.'
                                        */
  real_T Divcontr_B[352];              /* Computed Parameter: Divcontr_B
                                        * Referenced by: '<S15>/Div. contr.'
                                        */
  real_T Divcontr_C[205];              /* Computed Parameter: Divcontr_C
                                        * Referenced by: '<S15>/Div. contr.'
                                        */
  real_T Divcontr_D[171];              /* Computed Parameter: Divcontr_D
                                        * Referenced by: '<S15>/Div. contr.'
                                        */
  real_T Divcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S15>/Div. contr.'
                                        */
  real_T _Threshold_c;                 /* Expression: 1
                                        * Referenced by: '<S57>/1'
                                        */
  real_T Memory1_X0_d;                 /* Expression: 0
                                        * Referenced by: '<S61>/Memory1'
                                        */
  real_T Constant_Value_h;             /* Expression: const
                                        * Referenced by: '<S78>/Constant'
                                        */
  real_T switch1_Threshold_g;          /* Expression: 1
                                        * Referenced by: '<S61>/switch1'
                                        */
  real_T Div_rdcontr_A[337];           /* Computed Parameter: Div_rdcontr_A
                                        * Referenced by: '<S15>/Div_rd contr'
                                        */
  real_T Div_rdcontr_B[277];           /* Computed Parameter: Div_rdcontr_B
                                        * Referenced by: '<S15>/Div_rd contr'
                                        */
  real_T Div_rdcontr_C[165];           /* Computed Parameter: Div_rdcontr_C
                                        * Referenced by: '<S15>/Div_rd contr'
                                        */
  real_T Div_rdcontr_D[198];           /* Computed Parameter: Div_rdcontr_D
                                        * Referenced by: '<S15>/Div_rd contr'
                                        */
  real_T Div_rdcontr_X0;               /* Expression: 0
                                        * Referenced by: '<S15>/Div_rd contr'
                                        */
  real_T _Threshold_n;                 /* Expression: 1
                                        * Referenced by: '<S65>/1'
                                        */
  real_T Memory1_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S53>/Memory1'
                                        */
  real_T Constant_Value_k;             /* Expression: const
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T _Threshold_co;                /* Expression: 1
                                        * Referenced by: '<S53>/1 '
                                        */
  real_T _Value_lw;                    /* Expression: 1
                                        * Referenced by: '<S53>/1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: 0
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T Currtermcontr_A[253];         /* Computed Parameter: Currtermcontr_A
                                        * Referenced by: '<S15>/Curr. term. contr'
                                        */
  real_T Currtermcontr_B[121];         /* Computed Parameter: Currtermcontr_B
                                        * Referenced by: '<S15>/Curr. term. contr'
                                        */
  real_T Currtermcontr_C[11];          /* Computed Parameter: Currtermcontr_C
                                        * Referenced by: '<S15>/Curr. term. contr'
                                        */
  real_T Currtermcontr_X0;             /* Expression: 0
                                        * Referenced by: '<S15>/Curr. term. contr'
                                        */
  real_T Memory2_X0_gp;                /* Expression: 0
                                        * Referenced by: '<S73>/Memory2'
                                        */
  real_T Limcontr_A[2116];             /* Computed Parameter: Limcontr_A
                                        * Referenced by: '<S54>/Lim. contr.'
                                        */
  real_T Limcontr_B[782];              /* Computed Parameter: Limcontr_B
                                        * Referenced by: '<S54>/Lim. contr.'
                                        */
  real_T Limcontr_C[506];              /* Computed Parameter: Limcontr_C
                                        * Referenced by: '<S54>/Lim. contr.'
                                        */
  real_T Limcontr_D[187];              /* Computed Parameter: Limcontr_D
                                        * Referenced by: '<S54>/Lim. contr.'
                                        */
  real_T Limcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S54>/Lim. contr.'
                                        */
  real_T Currcontr_A[121];             /* Computed Parameter: Currcontr_A
                                        * Referenced by: '<S54>/Curr. contr.'
                                        */
  real_T Currcontr_B[121];             /* Computed Parameter: Currcontr_B
                                        * Referenced by: '<S54>/Curr. contr.'
                                        */
  real_T Currcontr_C[121];             /* Computed Parameter: Currcontr_C
                                        * Referenced by: '<S54>/Curr. contr.'
                                        */
  real_T Currcontr_X0;                 /* Expression: 0
                                        * Referenced by: '<S54>/Curr. contr.'
                                        */
  real_T u_Threshold;                  /* Expression: 1
                                        * Referenced by: '<S73>/ 1 '
                                        */
  real_T u01_Gain;                     /* Expression: 1e-3
                                        * Referenced by: '<S83>/0.001'
                                        */
  real_T u01_Gain_d;                   /* Expression: 1e-3
                                        * Referenced by: '<S86>/0.001'
                                        */
  real_T u01_Gain_a;                   /* Expression: 1e-3
                                        * Referenced by: '<S87>/0.001'
                                        */
  real_T u01_Gain_i;                   /* Expression: 1e-3
                                        * Referenced by: '<S88>/0.001'
                                        */
  real_T u01_Gain_f;                   /* Expression: 1e-3
                                        * Referenced by: '<S89>/0.001'
                                        */
  real_T u01_Gain_dl;                  /* Expression: 1e-3
                                        * Referenced by: '<S90>/0.001'
                                        */
  real_T u01_Gain_j;                   /* Expression: 1e-3
                                        * Referenced by: '<S91>/0.001'
                                        */
  real_T u01_Gain_b;                   /* Expression: 1e-3
                                        * Referenced by: '<S92>/0.001'
                                        */
  real_T u01_Gain_h;                   /* Expression: 1e-3
                                        * Referenced by: '<S93>/0.001'
                                        */
  real_T u01_Gain_p;                   /* Expression: 1e-3
                                        * Referenced by: '<S84>/0.001'
                                        */
  real_T u01_Gain_n;                   /* Expression: 1e-3
                                        * Referenced by: '<S85>/0.001'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S52>/Switch'
                                        */
  real_T UniformRandomNumber_Minimum;  /* Expression: -1
                                        * Referenced by: '<S62>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 1
                                        * Referenced by: '<S62>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S62>/Uniform Random Number'
                                        */
  real_T u5_Gain_d;                    /* Expression: 1.75
                                        * Referenced by: '<S79>/1.75'
                                        */
  real_T UD_InitialCondition_g;        /* Expression: ICPrevInput
                                        * Referenced by: '<S80>/UD'
                                        */
  real_T e3_Gain_i;                    /* Expression: 2e3
                                        * Referenced by: '<S79>/2e3'
                                        */
  real_T VScontr_A[34];                /* Computed Parameter: VScontr_A
                                        * Referenced by: '<S59>/VS. contr'
                                        */
  real_T VScontr_B[16];                /* Computed Parameter: VScontr_B
                                        * Referenced by: '<S59>/VS. contr'
                                        */
  real_T VScontr_C[10];                /* Computed Parameter: VScontr_C
                                        * Referenced by: '<S59>/VS. contr'
                                        */
  real_T VScontr_D[4];                 /* Computed Parameter: VScontr_D
                                        * Referenced by: '<S59>/VS. contr'
                                        */
  real_T VScontr_X0;                   /* Expression: 0
                                        * Referenced by: '<S59>/VS. contr'
                                        */
  real_T Constant_Value_i;             /* Expression: const
                                        * Referenced by: '<S76>/Constant'
                                        */
  real_T VScontrhl_A[33];              /* Computed Parameter: VScontrhl_A
                                        * Referenced by: '<S59>/VS. contr hl'
                                        */
  real_T VScontrhl_B[15];              /* Computed Parameter: VScontrhl_B
                                        * Referenced by: '<S59>/VS. contr hl'
                                        */
  real_T VScontrhl_C[9];               /* Computed Parameter: VScontrhl_C
                                        * Referenced by: '<S59>/VS. contr hl'
                                        */
  real_T VScontrhl_D[4];               /* Computed Parameter: VScontrhl_D
                                        * Referenced by: '<S59>/VS. contr hl'
                                        */
  real_T VScontrhl_X0;                 /* Expression: 0
                                        * Referenced by: '<S59>/VS. contr hl'
                                        */
  real_T c_eob_Threshold_o5;           /* Expression: 1
                                        * Referenced by: '<S59>/c_eob'
                                        */
  real_T Constant_Value_e;             /* Expression: const
                                        * Referenced by: '<S75>/Constant'
                                        */
  real_T u5_Gain_m;                    /* Expression: 1/15
                                        * Referenced by: '<S60>/1//15'
                                        */
  real_T _Threshold_k;                 /* Expression: 1
                                        * Referenced by: '<S58>/1'
                                        */
  real_T G_curr_term_Gain[220];        /* Expression: [zeros(8,11); eye(11); zeros(1,11)]
                                        * Referenced by: '<S15>/G_curr_term'
                                        */
  real_T e6_Gain_e;                    /* Expression: 1e6
                                        * Referenced by: '<S54>/1e6'
                                        */
  real_T DataStoreMemory_InitialValue[6500];/* Expression: zeros(13,500)
                                             * Referenced by: '<S5>/Data Store Memory'
                                             */
  real_T DataStoreMemory1_InitialValue[10000];/* Expression: zeros(20,500)
                                               * Referenced by: '<S5>/Data Store Memory1'
                                               */
  real_T DataStoreMemory10_InitialValue;/* Expression: 0
                                         * Referenced by: '<S5>/Data Store Memory10'
                                         */
  real_T DataStoreMemory11_InitialValue;/* Expression: 0
                                         * Referenced by: '<S5>/Data Store Memory11'
                                         */
  real_T DataStoreMemory12_InitialValue;/* Expression: 0
                                         * Referenced by: '<S5>/Data Store Memory12'
                                         */
  real_T DataStoreMemory13_InitialValue;/* Expression: 0
                                         * Referenced by: '<S5>/Data Store Memory13'
                                         */
  real_T DataStoreMemory14_InitialValue;/* Expression: 0
                                         * Referenced by: '<S5>/Data Store Memory14'
                                         */
  real_T DataStoreMemory15_InitialValue;/* Expression: 0
                                         * Referenced by: '<S5>/Data Store Memory15'
                                         */
  real_T DataStoreMemory16_InitialValue;/* Expression: 0
                                         * Referenced by: '<S5>/Data Store Memory16'
                                         */
  real_T DataStoreMemory17_InitialValue;/* Expression: 0
                                         * Referenced by: '<S5>/Data Store Memory17'
                                         */
  real_T DataStoreMemory18_InitialValue;/* Expression: 0
                                         * Referenced by: '<S5>/Data Store Memory18'
                                         */
  real_T DataStoreMemory2_InitialValue;/* Expression: 0
                                        * Referenced by: '<S5>/Data Store Memory2'
                                        */
  real_T DataStoreMemory3_InitialValue;/* Expression: 0
                                        * Referenced by: '<S5>/Data Store Memory3'
                                        */
  real_T DataStoreMemory4_InitialValue;/* Expression: 1e6
                                        * Referenced by: '<S5>/Data Store Memory4'
                                        */
  real_T DataStoreMemory5_InitialValue;/* Expression: 1e-3
                                        * Referenced by: '<S5>/Data Store Memory5'
                                        */
  real_T DataStoreMemory6_InitialValue;/* Expression: 1e-3
                                        * Referenced by: '<S5>/Data Store Memory6'
                                        */
  real_T DataStoreMemory7_InitialValue;/* Expression: 0
                                        * Referenced by: '<S5>/Data Store Memory7'
                                        */
  real_T DataStoreMemory8_InitialValue;/* Expression: 0
                                        * Referenced by: '<S5>/Data Store Memory8'
                                        */
  real_T DataStoreMemory9_InitialValue;/* Expression: 0
                                        * Referenced by: '<S5>/Data Store Memory9'
                                        */
  real_T Memory1_X0_ai;                /* Expression: 0
                                        * Referenced by: '<S7>/Memory1'
                                        */
  real_T _Gain;                        /* Expression: 2
                                        * Referenced by: '<S8>/2'
                                        */
  real_T UD_InitialCondition_p;        /* Expression: ICPrevInput
                                        * Referenced by: '<S6>/UD'
                                        */
  real_T u_Gain_e;                     /* Expression: -1
                                        * Referenced by: '<S8>/-1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: -1
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T wz1_Value[11];                /* Expression: [0 0 0 0 0 0 -1 -1 1 1 0]'
                                        * Referenced by: '<S2>/wz1'
                                        */
  real_T wz2_Value;                    /* Expression: 1
                                        * Referenced by: '<S2>/wz2'
                                        */
  real_T npf12_Gain[180];              /* Expression: eye(15,11+1)
                                        * Referenced by: '<S2>/npf,12'
                                        */
  real_T DataStoreMemory1_InitialValue_n[12];/* Expression: [554,554,554,554,554  248.6 115.2 185.9 169.9 216.8  459.4 1]
                                              * Referenced by: '<S1>/Data Store Memory1'
                                              */
  real_T DataStoreMemory2_InitialValue_i[6];/* Expression: [1; ones(5,1)*1e-6]
                                             * Referenced by: '<S1>/Data Store Memory2'
                                             */
  real_T DataStoreMemory3_InitialValue_d;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory3'
                                          */
  real_T DataStoreMemory4_InitialValue_p[11];/* Expression: zeros(11,1)
                                              * Referenced by: '<S1>/Data Store Memory4'
                                              */
  real_T DataStoreMemory5_InitialValue_m;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory5'
                                          */
  real_T DataStoreMemory7_InitialValue_d;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory7'
                                          */
  real_T DataStoreMemory8_InitialValue_k;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory8'
                                          */
  real_T DataStoreMemory9_InitialValue_j[11];/* Expression: ones(1,11)*1e6
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
    SimStruct childSFunctions[17];
    SimStruct *childSFunctionPtrs[17];
    struct _ssBlkInfo2 blkInfo2[17];
    struct _ssSFcnModelMethods2 methods2[17];
    struct _ssSFcnModelMethods3 methods3[17];
    struct _ssStatesInfo2 statesInfo2[17];
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
      int_T oDims0[2];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn15;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
    } Sfcn16;
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
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Propagation' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/To Workspace' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Data Type Propagation' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Propagation' : Unused code path elimination
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
 * '<S3>'   : 't15_2/Pow. Supply MC 2/Pow. Supply MC 2'
 * '<S4>'   : 't15_2/Pow. Supply MC 2/Pow. Supply VS1,3'
 * '<S5>'   : 't15_2/Pow. Supply MC 2/kavin_contr'
 * '<S6>'   : 't15_2/Pow. Supply MC 2/Pow. Supply MC 2/Difference'
 * '<S7>'   : 't15_2/Pow. Supply MC 2/Pow. Supply MC 2/Pow. Supply MC 1'
 * '<S8>'   : 't15_2/Pow. Supply MC 2/Pow. Supply MC 2/Pow. Supply MC 1/MC rate'
 * '<S9>'   : 't15_2/Pow. Supply MC 2/Pow. Supply MC 2/Pow. Supply MC 1/MC satur.'
 * '<S10>'  : 't15_2/Pow. Supply MC 2/Pow. Supply MC 2/Pow. Supply MC 1/MC rate/Saturation Dynamic'
 * '<S11>'  : 't15_2/Pow. Supply MC 2/Pow. Supply MC 2/Pow. Supply MC 1/MC satur./Saturation Dynamic'
 * '<S12>'  : 't15_2/Pow. Supply MC 2/Pow. Supply VS1,3/Saturation Dynamic'
 * '<S13>'  : 't15_2/Pow. Supply MC 2/Pow. Supply VS1,3/Saturation Dynamic1'
 * '<S14>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1'
 * '<S15>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1'
 * '<S16>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Subsystem'
 * '<S17>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Ics1_end'
 * '<S18>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Ip_ref scr_data.dat'
 * '<S19>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Subsystem4'
 * '<S20>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/dZ//dt'
 * '<S21>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/elong_ref.dat'
 * '<S22>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat'
 * '<S23>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat'
 * '<S24>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g4'
 * '<S25>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Ics1_end/Trigger'
 * '<S26>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/dZ//dt/Difference'
 * '<S27>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/dZ//dt/Difference1'
 * '<S28>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil1 ref'
 * '<S29>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil10 ref'
 * '<S30>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil11 ref'
 * '<S31>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil2 ref'
 * '<S32>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil3 ref'
 * '<S33>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil4 ref'
 * '<S34>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil5 ref'
 * '<S35>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil6 ref'
 * '<S36>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil7 ref'
 * '<S37>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil8 ref'
 * '<S38>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil9 ref'
 * '<S39>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem1'
 * '<S40>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem2'
 * '<S41>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem3'
 * '<S42>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem4'
 * '<S43>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem5'
 * '<S44>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem6'
 * '<S45>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem1/g2_term,ref'
 * '<S46>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem2/g3_term,ref'
 * '<S47>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem3/g4_term,ref'
 * '<S48>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem4/g5_term,ref'
 * '<S49>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem5/g6_term,ref'
 * '<S50>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem6/g1_term,ref'
 * '<S51>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/ tt_kavin2.dat(1)'
 * '<S52>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Curr. satur.1'
 * '<S53>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Ip>cIp_end'
 * '<S54>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1'
 * '<S55>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Saturation Dynamic'
 * '<S56>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Saturation Dynamic1'
 * '<S57>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem7'
 * '<S58>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem8'
 * '<S59>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS VShl contr.'
 * '<S60>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS gain 1'
 * '<S61>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/div_divrd'
 * '<S62>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/dzdt noise1'
 * '<S63>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/scr_data.dat'
 * '<S64>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/t_tran2D'
 * '<S65>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/tt_kavin2.dat(1,4)'
 * '<S66>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat'
 * '<S67>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Curr. satur.1/Compare To Constant'
 * '<S68>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Curr. satur.1/Compare To Zero'
 * '<S69>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Ip>cIp_end/Compare To Constant1'
 * '<S70>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Ip>cIp_end/Ip<cIp_end'
 * '<S71>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1/gain_cont2'
 * '<S72>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1/t_cont2'
 * '<S73>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1/t_cont2_2'
 * '<S74>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem7/Compare To Constant1'
 * '<S75>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem8/Compare To Constant1'
 * '<S76>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS VShl contr./Compare To Constant1'
 * '<S77>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS gain 1/Saturation Dynamic'
 * '<S78>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/div_divrd/Compare To Constant1'
 * '<S79>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/dzdt noise1/Subsystem'
 * '<S80>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/dzdt noise1/Subsystem/Difference'
 * '<S81>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/scr_data.dat/Saturation Dynamic'
 * '<S82>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/tt_kavin2.dat(1,4)/Compare To Constant1'
 * '<S83>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt1'
 * '<S84>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt10'
 * '<S85>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt11'
 * '<S86>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt2'
 * '<S87>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt3'
 * '<S88>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt4'
 * '<S89>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt5'
 * '<S90>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt6'
 * '<S91>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt7'
 * '<S92>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt8'
 * '<S93>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt9'
 */
#endif                                 /* RTW_HEADER_t15_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
