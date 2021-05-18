/*
 * File: t15_2.h
 *
 * Code generated for Simulink model 't15_2'.
 *
 * Model version                  : 1.1156
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue May 11 11:08:30 2021
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
  real_T e6_e[15];                     /* '<S14>/1e-6   ' */
  real_T Memory1;                      /* '<S18>/Memory1' */
  real_T DataStoreRead1_m;             /* '<S18>/Data Store Read1' */
  real_T e3;                           /* '<S18>/1e-3' */
  real_T DataStoreRead2;               /* '<S18>/Data Store Read2' */
  real_T Product1;                     /* '<S18>/Product1' */
  real_T RelationalOperator;           /* '<S18>/Relational Operator' */
  real_T Memory;                       /* '<S26>/Memory' */
  real_T LogicalOperator;              /* '<S26>/Logical Operator' */
  real_T switch0;                      /* '<S18>/switch0' */
  real_T Add2;                         /* '<S18>/Add2' */
  real_T DataStoreRead_o;              /* '<S18>/Data Store Read' */
  real_T Product;                      /* '<S18>/Product' */
  real_T Add1;                         /* '<S18>/Add1' */
  real_T u_a;                          /* '<S18>/1 0' */
  real_T Memory1_j;                    /* '<S19>/Memory1' */
  real_T c_eob;                        /* '<S19>/c_eob' */
  real_T Divide6;                      /* '<S19>/Divide6' */
  real_T Add1_l;                       /* '<S14>/Add1' */
  real_T SFunction1_f[100];            /* '<S21>/S-Function1' */
  real_T e2[6];                        /* '<S23>/1e2' */
  real_T SFunction1_a[100];            /* '<S45>/S-Function1' */
  real_T Memory2_g;                    /* '<S45>/Memory2' */
  real_T c_eob1;                       /* '<S45>/c_eob  1' */
  real_T Memory1_c;                    /* '<S45>/Memory1' */
  real_T c_eob_a;                      /* '<S45>/c_eob  ' */
  real_T SFunction1_o[100];            /* '<S51>/S-Function1' */
  real_T c_eob_d;                      /* '<S45>/c_eob' */
  real_T Add2_p;                       /* '<S23>/Add2' */
  real_T SFunction1_b[100];            /* '<S40>/S-Function1' */
  real_T Memory2_c;                    /* '<S40>/Memory2' */
  real_T c_eob1_p;                     /* '<S40>/c_eob  1' */
  real_T Memory1_i;                    /* '<S40>/Memory1' */
  real_T c_eob_k;                      /* '<S40>/c_eob  ' */
  real_T SFunction1_h[100];            /* '<S46>/S-Function1' */
  real_T c_eob_c;                      /* '<S40>/c_eob' */
  real_T Add1_d;                       /* '<S23>/Add1' */
  real_T SFunction1_k[100];            /* '<S41>/S-Function1' */
  real_T Memory2_m;                    /* '<S41>/Memory2' */
  real_T c_eob1_l;                     /* '<S41>/c_eob  1' */
  real_T Memory1_cm;                   /* '<S41>/Memory1' */
  real_T c_eob_i;                      /* '<S41>/c_eob  ' */
  real_T SFunction1_ov[100];           /* '<S47>/S-Function1' */
  real_T c_eob_a0;                     /* '<S41>/c_eob' */
  real_T Add3;                         /* '<S23>/Add3' */
  real_T SFunction1_ob[100];           /* '<S42>/S-Function1' */
  real_T Memory2_a;                    /* '<S42>/Memory2' */
  real_T c_eob1_d;                     /* '<S42>/c_eob  1' */
  real_T Memory1_o;                    /* '<S42>/Memory1' */
  real_T c_eob_e;                      /* '<S42>/c_eob  ' */
  real_T SFunction1_kp[100];           /* '<S48>/S-Function1' */
  real_T c_eob_kv;                     /* '<S42>/c_eob' */
  real_T Add4;                         /* '<S23>/Add4' */
  real_T DataStoreRead_l;              /* '<S23>/Data Store Read' */
  real_T RelationalOperator1;          /* '<S23>/Relational Operator1' */
  real_T Divide12;                     /* '<S23>/Divide12' */
  real_T SFunction1_j[100];            /* '<S43>/S-Function1' */
  real_T Memory2_n;                    /* '<S43>/Memory2' */
  real_T c_eob1_l5;                    /* '<S43>/c_eob  1' */
  real_T Memory1_ii;                   /* '<S43>/Memory1' */
  real_T c_eob_kr;                     /* '<S43>/c_eob  ' */
  real_T SFunction1_m[100];            /* '<S49>/S-Function1' */
  real_T c_eob_b;                      /* '<S43>/c_eob' */
  real_T Add5;                         /* '<S23>/Add5' */
  real_T SFunction1_e[100];            /* '<S44>/S-Function1' */
  real_T Memory2_i;                    /* '<S44>/Memory2' */
  real_T c_eob1_pv;                    /* '<S44>/c_eob  1' */
  real_T Memory1_e;                    /* '<S44>/Memory1' */
  real_T c_eob_j;                      /* '<S44>/c_eob  ' */
  real_T SFunction1_e2[100];           /* '<S50>/S-Function1' */
  real_T c_eob_di;                     /* '<S44>/c_eob' */
  real_T Add6;                         /* '<S23>/Add6' */
  real_T e2_f[6];                      /* '<S23>/1e-2' */
  real_T Memory2_k;                    /* '<S29>/Memory2' */
  real_T c_eob_f;                      /* '<S29>/c_eob' */
  real_T Divide1;                      /* '<S29>/Divide1' */
  real_T Add3_p;                       /* '<S22>/Add3' */
  real_T Memory2_b;                    /* '<S32>/Memory2' */
  real_T c_eob_p;                      /* '<S32>/c_eob' */
  real_T Divide1_o;                    /* '<S32>/Divide1' */
  real_T Add1_f;                       /* '<S22>/Add1' */
  real_T Memory2_gk;                   /* '<S33>/Memory2' */
  real_T c_eob_n;                      /* '<S33>/c_eob' */
  real_T Divide1_a;                    /* '<S33>/Divide1' */
  real_T Add2_g;                       /* '<S22>/Add2' */
  real_T Memory2_ko;                   /* '<S34>/Memory2' */
  real_T c_eob_o;                      /* '<S34>/c_eob' */
  real_T Divide1_k;                    /* '<S34>/Divide1' */
  real_T Add4_m;                       /* '<S22>/Add4' */
  real_T Memory2_nn;                   /* '<S35>/Memory2' */
  real_T c_eob_m;                      /* '<S35>/c_eob' */
  real_T Divide1_j;                    /* '<S35>/Divide1' */
  real_T Add5_c;                       /* '<S22>/Add5' */
  real_T Memory2_l;                    /* '<S36>/Memory2' */
  real_T c_eob_pa;                     /* '<S36>/c_eob' */
  real_T Divide1_p;                    /* '<S36>/Divide1' */
  real_T Add6_p;                       /* '<S22>/Add6' */
  real_T Memory2_d;                    /* '<S37>/Memory2' */
  real_T c_eob_cb;                     /* '<S37>/c_eob' */
  real_T Divide1_oe;                   /* '<S37>/Divide1' */
  real_T Add7;                         /* '<S22>/Add7' */
  real_T Memory2_nx;                   /* '<S38>/Memory2' */
  real_T c_eob_jb;                     /* '<S38>/c_eob' */
  real_T Divide1_f;                    /* '<S38>/Divide1' */
  real_T Add8;                         /* '<S22>/Add8' */
  real_T Memory2_dj;                   /* '<S39>/Memory2' */
  real_T c_eob_id;                     /* '<S39>/c_eob' */
  real_T Divide1_g;                    /* '<S39>/Divide1' */
  real_T Add9;                         /* '<S22>/Add9' */
  real_T Memory2_mw;                   /* '<S30>/Memory2' */
  real_T c_eob_l;                      /* '<S30>/c_eob' */
  real_T Divide1_gk;                   /* '<S30>/Divide1' */
  real_T Add10;                        /* '<S22>/Add10' */
  real_T Memory2_o;                    /* '<S31>/Memory2' */
  real_T c_eob_cv;                     /* '<S31>/c_eob' */
  real_T Divide1_e;                    /* '<S31>/Divide1' */
  real_T Add11;                        /* '<S22>/Add11' */
  real_T DataStoreRead1_d;             /* '<S17>/Data Store Read1' */
  real_T RelationalOperator_m;         /* '<S17>/Relational Operator' */
  real_T Memory_c;                     /* '<S25>/Memory' */
  real_T LogicalOperator_n;            /* '<S25>/Logical Operator' */
  real_T u_j[20];                      /* '<S17>/1' */
  real_T Uk1;                          /* '<S27>/UD' */
  real_T Diff;                         /* '<S27>/Diff' */
  real_T Uk1_f;                        /* '<S28>/UD' */
  real_T Diff_l;                       /* '<S28>/Diff' */
  real_T Divide;                       /* '<S20>/Divide' */
  real_T DataStoreRead_ox;             /* '<S15>/Data Store Read' */
  real_T u15;                          /* '<S15>/ 1//15' */
  real_T DataStoreRead_c;              /* '<S52>/Data Store Read' */
  real_T Memory3;                      /* '<S52>/Memory3' */
  real_T DataStoreRead_ck;             /* '<S69>/Data Store Read' */
  real_T Abs;                          /* '<S69>/Abs' */
  real_T LogicalOperator1;             /* '<S52>/Logical Operator1' */
  real_T switch1;                      /* '<S52>/switch1 ' */
  real_T Subtract2;                    /* '<S52>/Subtract2' */
  real_T Divide1_jh;                   /* '<S52>/Divide1' */
  real_T Subtract1;                    /* '<S52>/Subtract1' */
  real_T Saturation1;                  /* '<S52>/Saturation1' */
  real_T Memory1_k[11];                /* '<S52>/Memory1' */
  real_T Memory1_f;                    /* '<S64>/Memory1' */
  real_T c_eob_ji;                     /* '<S64>/c_eob' */
  real_T c_eob_mp;                     /* '<S15>/c_eob' */
  real_T DataStoreRead_m;              /* '<S75>/Data Store Read' */
  real_T Divide12_b[20];               /* '<S75>/Divide12' */
  real_T Limcontr[11];                 /* '<S55>/Lim. contr.' */
  real_T Currcontr[11];                /* '<S55>/Curr. contr.' */
  real_T DataStoreRead2_n[11];         /* '<S55>/Data Store Read2' */
  real_T switch1_f[11];                /* '<S52>/switch1' */
  real_T Divide5[11];                  /* '<S52>/Divide5' */
  real_T Subtract3;                    /* '<S52>/Subtract3' */
  real_T e3_j[11];                     /* '<S53>/1e3' */
  real_T Abs_o[11];                    /* '<S53>/Abs' */
  real_T DataStoreRead1_g[11];         /* '<S15>/Data Store Read1' */
  real_T DataStoreRead2_j[11];         /* '<S53>/Data Store Read2' */
  real_T Divide5_a[11];                /* '<S53>/Divide5' */
  real_T Sum2_a[11];                   /* '<S53>/Sum2' */
  real_T DataStoreRead1_h;             /* '<S53>/Data Store Read1' */
  real_T Divide3[11];                  /* '<S53>/Divide3' */
  real_T Sum1[11];                     /* '<S53>/Sum1' */
  real_T Divide4[11];                  /* '<S53>/Divide4' */
  real_T Divide1_m[11];                /* '<S53>/Divide1' */
  real_T Saturation[11];               /* '<S53>/Saturation' */
  real_T Memory1_kx[11];               /* '<S66>/Memory1' */
  real_T DataStoreRead_h;              /* '<S66>/Data Store Read' */
  real_T Abs_p;                        /* '<S66>/Abs' */
  real_T LogicalOperator2;             /* '<S66>/Logical Operator2' */
  real_T Memory_k[11];                 /* '<S58>/Memory' */
  real_T DataStoreRead_d;              /* '<S58>/Data Store Read' */
  real_T DataStoreRead1_o;             /* '<S58>/Data Store Read1' */
  real_T Abs_m;                        /* '<S58>/Abs' */
  real_T LogicalOperator1_l;           /* '<S58>/Logical Operator1' */
  real_T Divide2[20];                  /* '<S15>/Divide2' */
  real_T Divcontr[11];                 /* '<S15>/Div. contr.' */
  real_T u_aw[11];                     /* '<S58>/0.1' */
  real_T Memory1_l;                    /* '<S62>/Memory1' */
  real_T DataStoreRead_hn;             /* '<S62>/Data Store Read' */
  real_T LogicalOperator1_o;           /* '<S62>/Logical Operator1' */
  real_T switch1_k;                    /* '<S62>/switch1' */
  real_T Divide13[20];                 /* '<S15>/Divide13' */
  real_T Div_rdcontr[11];              /* '<S15>/Div_rd contr' */
  real_T u_i[11];                      /* '<S66>/1' */
  real_T DataStoreRead_f;              /* '<S73>/Data Store Read' */
  real_T Abs_c;                        /* '<S73>/Abs' */
  real_T LogicalOperator2_a;           /* '<S54>/Logical Operator2' */
  real_T Subtract4;                    /* '<S54>/Subtract4' */
  real_T Divide4_k[11];                /* '<S15>/Divide4' */
  real_T Currtermcontr[11];            /* '<S15>/Curr. term. contr' */
  real_T Divide5_n[11];                /* '<S15>/Divide5' */
  real_T DataStoreRead_n[500];         /* '<S86>/Data Store Read' */
  real_T u01[500];                     /* '<S86>/0.001' */
  real_T DataStoreRead1_dr[500];       /* '<S86>/Data Store Read1' */
  real_T volt1;                        /* '<S86>/volt1' */
  real_T DataStoreRead_k[500];         /* '<S89>/Data Store Read' */
  real_T u01_h[500];                   /* '<S89>/0.001' */
  real_T DataStoreRead1_i[500];        /* '<S89>/Data Store Read1' */
  real_T volt1_p;                      /* '<S89>/volt1' */
  real_T DataStoreRead_hd[500];        /* '<S90>/Data Store Read' */
  real_T u01_e[500];                   /* '<S90>/0.001' */
  real_T DataStoreRead1_dq[500];       /* '<S90>/Data Store Read1' */
  real_T volt1_m;                      /* '<S90>/volt1' */
  real_T DataStoreRead_g[500];         /* '<S91>/Data Store Read' */
  real_T u01_i[500];                   /* '<S91>/0.001' */
  real_T DataStoreRead1_c[500];        /* '<S91>/Data Store Read1' */
  real_T volt1_c;                      /* '<S91>/volt1' */
  real_T DataStoreRead_p[500];         /* '<S92>/Data Store Read' */
  real_T u01_d[500];                   /* '<S92>/0.001' */
  real_T DataStoreRead1_e[500];        /* '<S92>/Data Store Read1' */
  real_T volt1_mx;                     /* '<S92>/volt1' */
  real_T DataStoreRead_h3[500];        /* '<S93>/Data Store Read' */
  real_T u01_o[500];                   /* '<S93>/0.001' */
  real_T DataStoreRead1_p[500];        /* '<S93>/Data Store Read1' */
  real_T volt1_j;                      /* '<S93>/volt1' */
  real_T DataStoreRead_l1[500];        /* '<S94>/Data Store Read' */
  real_T u01_f[500];                   /* '<S94>/0.001' */
  real_T DataStoreRead1_ib[500];       /* '<S94>/Data Store Read1' */
  real_T volt1_a;                      /* '<S94>/volt1' */
  real_T DataStoreRead_e[500];         /* '<S95>/Data Store Read' */
  real_T u01_j[500];                   /* '<S95>/0.001' */
  real_T DataStoreRead1_oz[500];       /* '<S95>/Data Store Read1' */
  real_T volt1_b;                      /* '<S95>/volt1' */
  real_T DataStoreRead_nv[500];        /* '<S96>/Data Store Read' */
  real_T u01_od[500];                  /* '<S96>/0.001' */
  real_T DataStoreRead1_oe[500];       /* '<S96>/Data Store Read1' */
  real_T volt1_p4;                     /* '<S96>/volt1' */
  real_T DataStoreRead_hx[500];        /* '<S87>/Data Store Read' */
  real_T u01_js[500];                  /* '<S87>/0.001' */
  real_T DataStoreRead1_f[500];        /* '<S87>/Data Store Read1' */
  real_T volt1_cq;                     /* '<S87>/volt1' */
  real_T DataStoreRead_cf[500];        /* '<S88>/Data Store Read' */
  real_T u01_c[500];                   /* '<S88>/0.001' */
  real_T DataStoreRead1_dp[500];       /* '<S88>/Data Store Read1' */
  real_T volt1_k;                      /* '<S88>/volt1' */
  real_T Sum1_f;                       /* '<S15>/Sum1' */
  real_T Divide7[11];                  /* '<S15>/Divide7' */
  real_T Sum3[11];                     /* '<S15>/Sum3' */
  real_T Divide2_b[11];                /* '<S53>/Divide2' */
  real_T Switch[11];                   /* '<S53>/Switch' */
  real_T Divide6_e[11];                /* '<S53>/Divide6' */
  real_T UniformRandomNumber;          /* '<S63>/Uniform Random Number' */
  real_T DataStoreRead_ok;             /* '<S82>/Data Store Read' */
  real_T u5;                           /* '<S82>/1.75' */
  real_T Divide11;                     /* '<S82>/Divide11' */
  real_T Uk1_fy;                       /* '<S83>/UD' */
  real_T Diff_h;                       /* '<S83>/Diff' */
  real_T e3_o;                         /* '<S82>/2e3' */
  real_T Sqrt;                         /* '<S82>/Sqrt' */
  real_T Divide1_b;                    /* '<S82>/Divide1' */
  real_T Sum2_d;                       /* '<S63>/Sum2' */
  real_T DataStoreRead_nf;             /* '<S65>/Data Store Read' */
  real_T RelationalOperator1_j;        /* '<S65>/Relational Operator1' */
  real_T Divide12_d[2];                /* '<S65>/Divide12' */
  real_T VScontr[2];                   /* '<S60>/VS. contr' */
  real_T Divide4_f[2];                 /* '<S60>/Divide4' */
  real_T VScontrhl[2];                 /* '<S60>/VS. contr hl' */
  real_T c_eob_bg[2];                  /* '<S60>/c_eob' */
  real_T DataStoreRead1_m5;            /* '<S59>/Data Store Read1' */
  real_T RelationalOperator2;          /* '<S59>/Relational Operator2' */
  real_T DataStoreRead_pk;             /* '<S59>/Data Store Read' */
  real_T Abs_ml;                       /* '<S59>/Abs' */
  real_T RelationalOperator1_c;        /* '<S59>/Relational Operator1' */
  real_T LogicalOperator1_j;           /* '<S59>/Logical Operator1' */
  real_T DataStoreRead_o4;             /* '<S61>/Data Store Read' */
  real_T u5_k;                         /* '<S61>/1//15' */
  real_T Div;                          /* '<S61>/Div' */
  real_T u_f[2];                       /* '<S59>/1' */
  real_T Divide10[2];                  /* '<S15>/Divide10' */
  real_T G_curr_term[20];              /* '<S15>/G_curr_term' */
  real_T Divide12_o[20];               /* '<S15>/Divide12' */
  real_T DataStoreRead_gy;             /* '<S54>/Data Store Read' */
  real_T Divide1_i[11];                /* '<S55>/Divide1' */
  real_T e6_f[11];                     /* '<S55>/1e6' */
  real_T DataStoreRead2_jy[11];        /* '<S5>/Data Store Read2' */
  real_T Divide4_g[11];                /* '<S5>/Divide4' */
  real_T SFunction_c[44];              /* '<S1>/S-Function' */
  real_T Memory1_g[11];                /* '<S3>/Memory1' */
  real_T DataStoreRead2_n3[11];        /* '<S2>/Data Store Read2' */
  real_T Divide3_b[11];                /* '<S2>/Divide3' */
  real_T Divide1_l[11];                /* '<S2>/Divide1' */
  real_T Memory1_oe;                   /* '<S4>/Memory1' */
  real_T Divide2_m[11];                /* '<S2>/Divide2' */
  real_T Add1_k[11];                   /* '<S2>/Add1' */
  real_T DataStoreRead1_pu;            /* '<S2>/Data Store Read1' */
  real_T Divide4_gn;                   /* '<S2>/Divide4' */
  real_T Memory2_mi;                   /* '<S4>/Memory2' */
  real_T Divide5_p;                    /* '<S2>/Divide5' */
  real_T TmpSignalConversionAtnpf12Inpor[12];
  real_T npf12[15];                    /* '<S2>/npf,12' */
  real_T Uk1_e;                        /* '<S6>/UD' */
  real_T Diff_o;                       /* '<S6>/Diff' */
  real_T Memory1_ld[11];               /* '<S7>/Memory1' */
  real_T Add1_k3[11];                  /* '<S7>/Add1' */
  real_T DataStoreRead1_l[11];         /* '<S8>/Data Store Read1' */
  real_T u_iv[11];                     /* '<S8>/2' */
  real_T DataStoreRead3;               /* '<S8>/Data Store Read3' */
  real_T Divide1_fw[11];               /* '<S8>/Divide1' */
  real_T Divide_d[11];                 /* '<S7>/Divide' */
  real_T u_am[11];                     /* '<S8>/-1' */
  real_T Switch_e[11];                 /* '<S10>/Switch' */
  real_T Switch2[11];                  /* '<S10>/Switch2' */
  real_T Divide1_bp[11];               /* '<S7>/Divide1' */
  real_T Add2_b[11];                   /* '<S7>/Add2' */
  real_T DataStoreRead1_do[11];        /* '<S9>/Data Store Read1' */
  real_T Gain[11];                     /* '<S9>/Gain' */
  real_T Switch_a[11];                 /* '<S11>/Switch' */
  real_T Switch2_j[11];                /* '<S11>/Switch2' */
  real_T DataStoreRead1_n;             /* '<S4>/Data Store Read1' */
  real_T Switch2_a;                    /* '<S12>/Switch2' */
  real_T DataStoreRead3_f;             /* '<S4>/Data Store Read3' */
  real_T Switch2_ap;                   /* '<S13>/Switch2' */
  real_T Subtract2_m;                  /* '<S62>/Subtract2' */
  real_T DataStoreRead1_gj;            /* '<S62>/Data Store Read1' */
  real_T Divide4_b;                    /* '<S62>/Divide4' */
  real_T Subtract3_n;                  /* '<S62>/Subtract3' */
  real_T Saturation_l;                 /* '<S62>/Saturation' */
  real_T Subtract1_i;                  /* '<S62>/Subtract1' */
  real_T Divide3_e[11];                /* '<S15>/Divide3' */
  real_T Divide1_bd[11];               /* '<S15>/Divide1' */
  real_T Sum2_f[11];                   /* '<S15>/Sum2' */
  real_T Divide6_e4;                   /* '<S15>/Divide6' */
  real_T Switch2_h;                    /* '<S56>/Switch2' */
  real_T Divide11_j[2];                /* '<S15>/Divide11' */
  real_T DataStoreRead3_p;             /* '<S15>/Data Store Read3' */
  real_T Switch_j;                     /* '<S56>/Switch' */
  real_T c_eob_lo[2];                  /* '<S15>/c_eob ' */
  real_T DataStoreRead1_fl;            /* '<S61>/Data Store Read1' */
  real_T RelationalOperator2_j;        /* '<S61>/Relational Operator2' */
  real_T LimDivtr;                     /* '<S61>/Lim. Div. tr.' */
  real_T Divide8[2];                   /* '<S15>/Divide8' */
  real_T SatDiv;                       /* '<S61>/Sat. Div' */
  real_T DataStoreRead2_i;             /* '<S61>/Data Store Read2' */
  real_T Switch2_o;                    /* '<S80>/Switch2' */
  real_T Switch_c;                     /* '<S80>/Switch' */
  real_T Divide15;                     /* '<S15>/Divide15' */
  real_T DataStoreRead4;               /* '<S15>/Data Store Read4' */
  real_T Switch2_i;                    /* '<S57>/Switch2' */
  real_T Divide_k[2];                  /* '<S15>/Divide ' */
  real_T Switch_f;                     /* '<S57>/Switch' */
  real_T Divide_dl[11];                /* '<S15>/Divide' */
  real_T DataStoreRead_j;              /* '<S76>/Data Store Read' */
  real_T u_l[11];                      /* '<S76>/1' */
  real_T DataStoreRead1_fc;            /* '<S74>/Data Store Read1' */
  real_T DataStoreRead_fp;             /* '<S74>/Data Store Read' */
  real_T Subtract3_d;                  /* '<S74>/Subtract3' */
  real_T Divide2_c;                    /* '<S74>/Divide2' */
  real_T Saturation1_a;                /* '<S74>/Saturation1' */
  real_T Divide_o[11];                 /* '<S55>/Divide ' */
  real_T Divide2_j[11];                /* '<S55>/Divide2' */
  real_T DataStoreRead2_m;             /* '<S15>/Data Store Read2' */
  real_T u15_o;                        /* '<S15>/ 1//15 ' */
  real_T Divide9;                      /* '<S15>/Divide9' */
  real_T Saturation_d;                 /* '<S15>/Saturation' */
  real_T DataStoreRead2_b;             /* '<S64>/Data Store Read2' */
  real_T Sum3_i;                       /* '<S64>/Sum3' */
  real_T DataStoreRead4_m;             /* '<S64>/Data Store Read4' */
  real_T DataStoreRead3_e;             /* '<S64>/Data Store Read3' */
  real_T Sum2_p;                       /* '<S64>/Sum2' */
  real_T Divide1_jhy;                  /* '<S64>/Divide1' */
  real_T Divide6_d;                    /* '<S64>/Divide6' */
  real_T Sum;                          /* '<S64>/Sum' */
  real_T Divide2_k;                    /* '<S64>/Divide2' */
  real_T Sum1_c;                       /* '<S64>/Sum1' */
  real_T Switch2_e;                    /* '<S84>/Switch2' */
  real_T Switch_i;                     /* '<S84>/Switch' */
  real_T Selector[49];                 /* '<S51>/Selector' */
  real_T TmpSignalConversionAtg1_termref[50];
  real_T DataStoreRead1_it;            /* '<S51>/Data Store Read1' */
  real_T DataStoreRead_eg;             /* '<S51>/Data Store Read' */
  real_T Selector1[50];                /* '<S51>/Selector1' */
  real_T Divide6_e4r[50];              /* '<S51>/Divide6' */
  real_T Add2_c[50];                   /* '<S51>/Add2' */
  real_T g1_termref;                   /* '<S51>/g1_term,ref' */
  real_T Selector_h[50];               /* '<S45>/Selector' */
  real_T Selector1_b[50];              /* '<S45>/Selector1' */
  real_T g1ref;                        /* '<S45>/g1ref' */
  real_T Selector_m[49];               /* '<S50>/Selector' */
  real_T TmpSignalConversionAtg6_termref[50];
  real_T DataStoreRead1_nu;            /* '<S50>/Data Store Read1' */
  real_T DataStoreRead_gv;             /* '<S50>/Data Store Read' */
  real_T Selector1_a[50];              /* '<S50>/Selector1' */
  real_T Divide6_n[50];                /* '<S50>/Divide6' */
  real_T Add2_m[50];                   /* '<S50>/Add2' */
  real_T g6_termref;                   /* '<S50>/g6_term,ref' */
  real_T Selector_k[50];               /* '<S44>/Selector' */
  real_T Selector1_i[50];              /* '<S44>/Selector1' */
  real_T g6ref;                        /* '<S44>/g6ref' */
  real_T Selector_l[49];               /* '<S49>/Selector' */
  real_T TmpSignalConversionAtg5_termref[50];
  real_T DataStoreRead1_dv;            /* '<S49>/Data Store Read1' */
  real_T DataStoreRead_cy;             /* '<S49>/Data Store Read' */
  real_T Selector1_ba[50];             /* '<S49>/Selector1' */
  real_T Divide6_b[50];                /* '<S49>/Divide6' */
  real_T Add2_b5[50];                  /* '<S49>/Add2' */
  real_T g5_termref;                   /* '<S49>/g5_term,ref' */
  real_T Selector_e[50];               /* '<S43>/Selector' */
  real_T Selector1_m[50];              /* '<S43>/Selector1' */
  real_T g5ref;                        /* '<S43>/g5ref' */
  real_T Selector_hy[49];              /* '<S48>/Selector' */
  real_T TmpSignalConversionAtg4_termref[50];
  real_T DataStoreRead1_lx;            /* '<S48>/Data Store Read1' */
  real_T DataStoreRead_o0;             /* '<S48>/Data Store Read' */
  real_T Selector1_iu[50];             /* '<S48>/Selector1' */
  real_T Divide6_j[50];                /* '<S48>/Divide6' */
  real_T Add2_a[50];                   /* '<S48>/Add2' */
  real_T g4_termref;                   /* '<S48>/g4_term,ref' */
  real_T Selector_d[50];               /* '<S42>/Selector' */
  real_T Selector1_av[50];             /* '<S42>/Selector1' */
  real_T g4ref;                        /* '<S42>/g4ref' */
  real_T Selector_n[49];               /* '<S47>/Selector' */
  real_T TmpSignalConversionAtg3_termref[50];
  real_T DataStoreRead1_lh;            /* '<S47>/Data Store Read1' */
  real_T DataStoreRead_mb;             /* '<S47>/Data Store Read' */
  real_T Selector1_k[50];              /* '<S47>/Selector1' */
  real_T Divide6_m[50];                /* '<S47>/Divide6' */
  real_T Add2_l[50];                   /* '<S47>/Add2' */
  real_T g3_termref;                   /* '<S47>/g3_term,ref' */
  real_T Selector_ez[50];              /* '<S41>/Selector' */
  real_T Selector1_kl[50];             /* '<S41>/Selector1' */
  real_T g3ref;                        /* '<S41>/g3ref' */
  real_T Selector_c[49];               /* '<S46>/Selector' */
  real_T TmpSignalConversionAtg2_termref[50];
  real_T DataStoreRead1_oc;            /* '<S46>/Data Store Read1' */
  real_T DataStoreRead_fk;             /* '<S46>/Data Store Read' */
  real_T Selector1_f[50];              /* '<S46>/Selector1' */
  real_T Divide6_h[50];                /* '<S46>/Divide6' */
  real_T Add2_j[50];                   /* '<S46>/Add2' */
  real_T g2_termref;                   /* '<S46>/g2_term,ref' */
  real_T Selector_a[50];               /* '<S40>/Selector' */
  real_T Selector1_fu[50];             /* '<S40>/Selector1' */
  real_T g2ref;                        /* '<S40>/g2ref' */
  real_T DataStoreRead1_a[500];        /* '<S39>/Data Store Read1' */
  real_T DataStoreRead_cw[500];        /* '<S39>/Data Store Read' */
  real_T I1;                           /* '<S39>/I1' */
  real_T DataStoreRead1_ac[500];       /* '<S38>/Data Store Read1' */
  real_T DataStoreRead_m1[500];        /* '<S38>/Data Store Read' */
  real_T I1_i;                         /* '<S38>/I1' */
  real_T DataStoreRead1_m3[500];       /* '<S37>/Data Store Read1' */
  real_T DataStoreRead_p5[500];        /* '<S37>/Data Store Read' */
  real_T I1_e;                         /* '<S37>/I1' */
  real_T DataStoreRead1_h5[500];       /* '<S36>/Data Store Read1' */
  real_T DataStoreRead_ec[500];        /* '<S36>/Data Store Read' */
  real_T I1_g;                         /* '<S36>/I1' */
  real_T DataStoreRead1_fz[500];       /* '<S35>/Data Store Read1' */
  real_T DataStoreRead_kq[500];        /* '<S35>/Data Store Read' */
  real_T I1_gs;                        /* '<S35>/I1' */
  real_T DataStoreRead1_ah[500];       /* '<S34>/Data Store Read1' */
  real_T DataStoreRead_ml[500];        /* '<S34>/Data Store Read' */
  real_T I1_o;                         /* '<S34>/I1' */
  real_T DataStoreRead1_ph[500];       /* '<S33>/Data Store Read1' */
  real_T DataStoreRead_i[500];         /* '<S33>/Data Store Read' */
  real_T I1_a;                         /* '<S33>/I1' */
  real_T DataStoreRead1_f5[500];       /* '<S32>/Data Store Read1' */
  real_T DataStoreRead_lz[500];        /* '<S32>/Data Store Read' */
  real_T I1_n;                         /* '<S32>/I1' */
  real_T DataStoreRead1_ek[500];       /* '<S31>/Data Store Read1' */
  real_T DataStoreRead_m5[500];        /* '<S31>/Data Store Read' */
  real_T I1_f;                         /* '<S31>/I1' */
  real_T DataStoreRead1_az[500];       /* '<S30>/Data Store Read1' */
  real_T DataStoreRead_lb[500];        /* '<S30>/Data Store Read' */
  real_T I1_if;                        /* '<S30>/I1' */
  real_T DataStoreRead1_k[500];        /* '<S29>/Data Store Read1' */
  real_T DataStoreRead_a[500];         /* '<S29>/Data Store Read' */
  real_T I1_b;                         /* '<S29>/I1' */
  real_T DataStoreRead1_fv[500];       /* '<S19>/Data Store Read1' */
  real_T DataStoreRead_dl[500];        /* '<S19>/Data Store Read' */
  real_T Ipref;                        /* '<S19>/Ipref' */
  real_T Selector_f[50];               /* '<S21>/Selector' */
  real_T Selector1_l[50];              /* '<S21>/Selector1' */
  real_T elong;                        /* '<S21>/elong' */
  real_T Add2_o;                       /* '<S14>/Add2' */
  real_T DataStoreRead1_ma;            /* '<S24>/Data Store Read1' */
  real_T Divide_e[4];                  /* '<S24>/Divide' */
  real_T Gain1;                        /* '<S4>/Gain1' */
  real_T Switch_iz;                    /* '<S13>/Switch' */
  real_T Gain_j;                       /* '<S4>/Gain' */
  real_T Switch_l;                     /* '<S12>/Switch' */
  uint8_T Compare[11];                 /* '<S70>/Compare' */
  uint8_T Compare_k[11];               /* '<S71>/Compare' */
  boolean_T RelationalOperator_l;      /* '<S5>/Relational Operator' */
  boolean_T RelationalOperator1_l;     /* '<S5>/Relational Operator1' */
  boolean_T Compare_p;                 /* '<S68>/Compare' */
  boolean_T RelationalOperator_b;      /* '<S69>/Relational Operator' */
  boolean_T RelationalOperator_a;      /* '<S75>/Relational Operator' */
  boolean_T RelationalOperator_h;      /* '<S66>/Relational Operator' */
  boolean_T Compare_l;                 /* '<S85>/Compare' */
  boolean_T RelationalOperator1_a;     /* '<S58>/Relational Operator1' */
  boolean_T Compare_g;                 /* '<S77>/Compare' */
  boolean_T RelationalOperator_a5;     /* '<S58>/Relational Operator' */
  boolean_T RelationalOperator1_p;     /* '<S62>/Relational Operator1' */
  boolean_T Compare_e;                 /* '<S81>/Compare' */
  boolean_T RelationalOperator_e;      /* '<S73>/Relational Operator' */
  boolean_T Compare_kb;                /* '<S72>/Compare' */
  boolean_T LogicalOperator_i[11];     /* '<S53>/Logical Operator' */
  boolean_T Compare_i;                 /* '<S79>/Compare' */
  boolean_T Compare_a;                 /* '<S78>/Compare' */
  boolean_T LowerRelop1[11];           /* '<S10>/LowerRelop1' */
  boolean_T UpperRelop[11];            /* '<S10>/UpperRelop' */
  boolean_T LowerRelop1_c[11];         /* '<S11>/LowerRelop1' */
  boolean_T UpperRelop_n[11];          /* '<S11>/UpperRelop' */
  boolean_T LowerRelop1_l;             /* '<S12>/LowerRelop1' */
  boolean_T LowerRelop1_a;             /* '<S13>/LowerRelop1' */
  boolean_T LowerRelop1_i;             /* '<S56>/LowerRelop1' */
  boolean_T UpperRelop_i;              /* '<S56>/UpperRelop' */
  boolean_T LowerRelop1_f;             /* '<S80>/LowerRelop1' */
  boolean_T UpperRelop_g;              /* '<S80>/UpperRelop' */
  boolean_T LowerRelop1_f0;            /* '<S57>/LowerRelop1' */
  boolean_T UpperRelop_a;              /* '<S57>/UpperRelop' */
  boolean_T RelationalOperator_eg;     /* '<S76>/Relational Operator' */
  boolean_T LowerRelop1_j;             /* '<S84>/LowerRelop1' */
  boolean_T UpperRelop_al;             /* '<S84>/UpperRelop' */
  boolean_T UpperRelop_b;              /* '<S13>/UpperRelop' */
  boolean_T UpperRelop_bc;             /* '<S12>/UpperRelop' */
} BlockIO_t15_2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S27>/UD' */
  real_T UD_DSTATE_p;                  /* '<S28>/UD' */
  real_T Limcontr_DSTATE[46];          /* '<S55>/Lim. contr.' */
  real_T Currcontr_DSTATE[11];         /* '<S55>/Curr. contr.' */
  real_T Divcontr_DSTATE[32];          /* '<S15>/Div. contr.' */
  real_T Div_rdcontr_DSTATE[22];       /* '<S15>/Div_rd contr' */
  real_T Currtermcontr_DSTATE[22];     /* '<S15>/Curr. term. contr' */
  real_T UD_DSTATE_k;                  /* '<S83>/UD' */
  real_T VScontr_DSTATE[9];            /* '<S60>/VS. contr' */
  real_T VScontrhl_DSTATE[8];          /* '<S60>/VS. contr hl' */
  real_T UD_DSTATE_n;                  /* '<S6>/UD' */
  real_T Memory2_PreviousInput;        /* '<S5>/Memory2' */
  real_T Memory1_PreviousInput;        /* '<S18>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S26>/Memory' */
  real_T Memory1_PreviousInput_k;      /* '<S19>/Memory1' */
  real_T Memory2_PreviousInput_m;      /* '<S45>/Memory2' */
  real_T Memory1_PreviousInput_d;      /* '<S45>/Memory1' */
  real_T Memory2_PreviousInput_j;      /* '<S40>/Memory2' */
  real_T Memory1_PreviousInput_i;      /* '<S40>/Memory1' */
  real_T Memory2_PreviousInput_l;      /* '<S41>/Memory2' */
  real_T Memory1_PreviousInput_h;      /* '<S41>/Memory1' */
  real_T Memory2_PreviousInput_a;      /* '<S42>/Memory2' */
  real_T Memory1_PreviousInput_da;     /* '<S42>/Memory1' */
  real_T Memory2_PreviousInput_a0;     /* '<S43>/Memory2' */
  real_T Memory1_PreviousInput_m;      /* '<S43>/Memory1' */
  real_T Memory2_PreviousInput_h;      /* '<S44>/Memory2' */
  real_T Memory1_PreviousInput_o;      /* '<S44>/Memory1' */
  real_T Memory2_PreviousInput_g;      /* '<S29>/Memory2' */
  real_T Memory2_PreviousInput_gi;     /* '<S32>/Memory2' */
  real_T Memory2_PreviousInput_jn;     /* '<S33>/Memory2' */
  real_T Memory2_PreviousInput_i;      /* '<S34>/Memory2' */
  real_T Memory2_PreviousInput_jj;     /* '<S35>/Memory2' */
  real_T Memory2_PreviousInput_k;      /* '<S36>/Memory2' */
  real_T Memory2_PreviousInput_in;     /* '<S37>/Memory2' */
  real_T Memory2_PreviousInput_af;     /* '<S38>/Memory2' */
  real_T Memory2_PreviousInput_gb;     /* '<S39>/Memory2' */
  real_T Memory2_PreviousInput_jo;     /* '<S30>/Memory2' */
  real_T Memory2_PreviousInput_hr;     /* '<S31>/Memory2' */
  real_T Memory_PreviousInput_n;       /* '<S25>/Memory' */
  real_T Memory3_PreviousInput;        /* '<S52>/Memory3' */
  real_T Memory1_PreviousInput_l[11];  /* '<S52>/Memory1' */
  real_T Memory1_PreviousInput_de;     /* '<S64>/Memory1' */
  real_T Memory1_PreviousInput_m4[11]; /* '<S66>/Memory1' */
  real_T Memory_PreviousInput_e[11];   /* '<S58>/Memory' */
  real_T Memory1_PreviousInput_c;      /* '<S62>/Memory1' */
  real_T UniformRandomNumber_NextOutput;/* '<S63>/Uniform Random Number' */
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
  real_T Memory1_PreviousInput_e[11];  /* '<S3>/Memory1' */
  real_T Memory1_PreviousInput_g;      /* '<S4>/Memory1' */
  real_T Memory2_PreviousInput_j4;     /* '<S4>/Memory2' */
  real_T Memory1_PreviousInput_kd[11]; /* '<S7>/Memory1' */
  real_T ntur[12];                     /* '<S1>/Data Store Memory1' */
  real_T RupRd[6];                     /* '<S1>/Data Store Memory2' */
  real_T VS3_up;                       /* '<S1>/Data Store Memory3' */
  real_T Vcspf_up[11];                 /* '<S1>/Data Store Memory4' */
  real_T VS1_up;                       /* '<S1>/Data Store Memory5' */
  real_T Tu;                           /* '<S1>/Data Store Memory7' */
  real_T c_cur_max;                    /* '<S1>/Data Store Memory8' */
  real_T Imax[11];                     /* '<S1>/Data Store Memory9' */
  uint32_T RandSeed;                   /* '<S63>/Uniform Random Number' */
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
                                        * Referenced by: '<S64>/2'
                                        */
  real_T _Value_i;                     /* Expression: 1
                                        * Referenced by: '<S64>/1'
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
                                        * Referenced by: '<S74>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S74>/Saturation1'
                                        */
  real_T _Value_g;                     /* Expression: 0.1
                                        * Referenced by: '<S15>/2'
                                        */
  real_T _Value_b;                     /* Expression: 0
                                        * Referenced by: '<S61>/1'
                                        */
  real_T SatDiv_UpperSat;              /* Expression: 1
                                        * Referenced by: '<S61>/Sat. Div'
                                        */
  real_T SatDiv_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S61>/Sat. Div'
                                        */
  real_T LimDivtr_Threshold;           /* Expression: 1
                                        * Referenced by: '<S61>/Lim. Div. tr.'
                                        */
  real_T c_eob_Threshold;              /* Expression: 1
                                        * Referenced by: '<S15>/c_eob '
                                        */
  real_T _Value_c;                     /* Expression: 1
                                        * Referenced by: '<S15>/1'
                                        */
  real_T _Value_k;                     /* Expression: 1
                                        * Referenced by: '<S62>/1'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 1
                                        * Referenced by: '<S62>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: 0
                                        * Referenced by: '<S62>/Saturation'
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
  real_T e6_Gain_n;                    /* Expression: 1e-6
                                        * Referenced by: '<S14>/1e-6   '
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S18>/Memory1'
                                        */
  real_T e3_Gain;                      /* Expression: 1e-3
                                        * Referenced by: '<S18>/1e-3'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S26>/Memory'
                                        */
  real_T switch0_Threshold;            /* Expression: 0
                                        * Referenced by: '<S18>/switch0'
                                        */
  real_T Constant4_Value_c;            /* Expression: 1
                                        * Referenced by: '<S18>/Constant4'
                                        */
  real_T u_UpperSat;                   /* Expression: 1
                                        * Referenced by: '<S18>/1 0'
                                        */
  real_T u_LowerSat;                   /* Expression: 0
                                        * Referenced by: '<S18>/1 0'
                                        */
  real_T Memory1_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S19>/Memory1'
                                        */
  real_T c_eob_Threshold_f;            /* Expression: 1
                                        * Referenced by: '<S19>/c_eob'
                                        */
  real_T SFunction1_P1_Size_m[2];      /* Computed Parameter: SFunction1_P1_Size_m
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  real_T SFunction1_P1_g;              /* Expression: 0
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  real_T Constant4_Value_k;            /* Expression: 0
                                        * Referenced by: '<S14>/Constant4'
                                        */
  real_T e2_Gain;                      /* Expression: 1e2
                                        * Referenced by: '<S23>/1e2'
                                        */
  real_T SFunction1_P1_Size_c[2];      /* Computed Parameter: SFunction1_P1_Size_c
                                        * Referenced by: '<S45>/S-Function1'
                                        */
  real_T SFunction1_P1_j;              /* Expression: 1
                                        * Referenced by: '<S45>/S-Function1'
                                        */
  real_T Memory2_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S45>/Memory2'
                                        */
  real_T c_eob1_Threshold;             /* Expression: 1
                                        * Referenced by: '<S45>/c_eob  1'
                                        */
  real_T Memory1_X0_i;                 /* Expression: 0
                                        * Referenced by: '<S45>/Memory1'
                                        */
  real_T c_eob_Threshold_n;            /* Expression: 1
                                        * Referenced by: '<S45>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_g[2];      /* Computed Parameter: SFunction1_P1_Size_g
                                        * Referenced by: '<S51>/S-Function1'
                                        */
  real_T SFunction1_P1_f;              /* Expression: 1
                                        * Referenced by: '<S51>/S-Function1'
                                        */
  real_T c_eob_Threshold_o;            /* Expression: 1
                                        * Referenced by: '<S45>/c_eob'
                                        */
  real_T SFunction1_P1_Size_a[2];      /* Computed Parameter: SFunction1_P1_Size_a
                                        * Referenced by: '<S40>/S-Function1'
                                        */
  real_T SFunction1_P1_fa;             /* Expression: 2
                                        * Referenced by: '<S40>/S-Function1'
                                        */
  real_T Memory2_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S40>/Memory2'
                                        */
  real_T c_eob1_Threshold_m;           /* Expression: 1
                                        * Referenced by: '<S40>/c_eob  1'
                                        */
  real_T Memory1_X0_d;                 /* Expression: 0
                                        * Referenced by: '<S40>/Memory1'
                                        */
  real_T c_eob_Threshold_c;            /* Expression: 1
                                        * Referenced by: '<S40>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_h[2];      /* Computed Parameter: SFunction1_P1_Size_h
                                        * Referenced by: '<S46>/S-Function1'
                                        */
  real_T SFunction1_P1_a;              /* Expression: 2
                                        * Referenced by: '<S46>/S-Function1'
                                        */
  real_T c_eob_Threshold_m;            /* Expression: 1
                                        * Referenced by: '<S40>/c_eob'
                                        */
  real_T SFunction1_P1_Size_he[2];     /* Computed Parameter: SFunction1_P1_Size_he
                                        * Referenced by: '<S41>/S-Function1'
                                        */
  real_T SFunction1_P1_m;              /* Expression: 3
                                        * Referenced by: '<S41>/S-Function1'
                                        */
  real_T Memory2_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S41>/Memory2'
                                        */
  real_T c_eob1_Threshold_f;           /* Expression: 1
                                        * Referenced by: '<S41>/c_eob  1'
                                        */
  real_T Memory1_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S41>/Memory1'
                                        */
  real_T c_eob_Threshold_e;            /* Expression: 1
                                        * Referenced by: '<S41>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_f[2];      /* Computed Parameter: SFunction1_P1_Size_f
                                        * Referenced by: '<S47>/S-Function1'
                                        */
  real_T SFunction1_P1_fi;             /* Expression: 3
                                        * Referenced by: '<S47>/S-Function1'
                                        */
  real_T c_eob_Threshold_j;            /* Expression: 1
                                        * Referenced by: '<S41>/c_eob'
                                        */
  real_T SFunction1_P1_Size_p[2];      /* Computed Parameter: SFunction1_P1_Size_p
                                        * Referenced by: '<S42>/S-Function1'
                                        */
  real_T SFunction1_P1_p;              /* Expression: 4
                                        * Referenced by: '<S42>/S-Function1'
                                        */
  real_T Memory2_X0_l;                 /* Expression: 0
                                        * Referenced by: '<S42>/Memory2'
                                        */
  real_T c_eob1_Threshold_j;           /* Expression: 1
                                        * Referenced by: '<S42>/c_eob  1'
                                        */
  real_T Memory1_X0_l;                 /* Expression: 0
                                        * Referenced by: '<S42>/Memory1'
                                        */
  real_T c_eob_Threshold_i;            /* Expression: 1
                                        * Referenced by: '<S42>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_b[2];      /* Computed Parameter: SFunction1_P1_Size_b
                                        * Referenced by: '<S48>/S-Function1'
                                        */
  real_T SFunction1_P1_n;              /* Expression: 4
                                        * Referenced by: '<S48>/S-Function1'
                                        */
  real_T c_eob_Threshold_h;            /* Expression: 1
                                        * Referenced by: '<S42>/c_eob'
                                        */
  real_T SFunction1_P1_Size_l[2];      /* Computed Parameter: SFunction1_P1_Size_l
                                        * Referenced by: '<S43>/S-Function1'
                                        */
  real_T SFunction1_P1_i;              /* Expression: 5
                                        * Referenced by: '<S43>/S-Function1'
                                        */
  real_T Memory2_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S43>/Memory2'
                                        */
  real_T c_eob1_Threshold_mp;          /* Expression: 1
                                        * Referenced by: '<S43>/c_eob  1'
                                        */
  real_T Memory1_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S43>/Memory1'
                                        */
  real_T c_eob_Threshold_b;            /* Expression: 1
                                        * Referenced by: '<S43>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_e[2];      /* Computed Parameter: SFunction1_P1_Size_e
                                        * Referenced by: '<S49>/S-Function1'
                                        */
  real_T SFunction1_P1_d;              /* Expression: 5
                                        * Referenced by: '<S49>/S-Function1'
                                        */
  real_T c_eob_Threshold_iu;           /* Expression: 1
                                        * Referenced by: '<S43>/c_eob'
                                        */
  real_T SFunction1_P1_Size_o[2];      /* Computed Parameter: SFunction1_P1_Size_o
                                        * Referenced by: '<S44>/S-Function1'
                                        */
  real_T SFunction1_P1_gx;             /* Expression: 6
                                        * Referenced by: '<S44>/S-Function1'
                                        */
  real_T Memory2_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S44>/Memory2'
                                        */
  real_T c_eob1_Threshold_b;           /* Expression: 1
                                        * Referenced by: '<S44>/c_eob  1'
                                        */
  real_T Memory1_X0_dy;                /* Expression: 0
                                        * Referenced by: '<S44>/Memory1'
                                        */
  real_T c_eob_Threshold_m1;           /* Expression: 1
                                        * Referenced by: '<S44>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_i[2];      /* Computed Parameter: SFunction1_P1_Size_i
                                        * Referenced by: '<S50>/S-Function1'
                                        */
  real_T SFunction1_P1_b;              /* Expression: 6
                                        * Referenced by: '<S50>/S-Function1'
                                        */
  real_T c_eob_Threshold_ov;           /* Expression: 1
                                        * Referenced by: '<S44>/c_eob'
                                        */
  real_T e2_Gain_g;                    /* Expression: 1e-2
                                        * Referenced by: '<S23>/1e-2'
                                        */
  real_T Memory2_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S29>/Memory2'
                                        */
  real_T c_eob_Threshold_cx;           /* Expression: 1
                                        * Referenced by: '<S29>/c_eob'
                                        */
  real_T Memory2_X0_oe;                /* Expression: 0
                                        * Referenced by: '<S32>/Memory2'
                                        */
  real_T c_eob_Threshold_eb;           /* Expression: 1
                                        * Referenced by: '<S32>/c_eob'
                                        */
  real_T Memory2_X0_jq;                /* Expression: 0
                                        * Referenced by: '<S33>/Memory2'
                                        */
  real_T c_eob_Threshold_jq;           /* Expression: 1
                                        * Referenced by: '<S33>/c_eob'
                                        */
  real_T Memory2_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S34>/Memory2'
                                        */
  real_T c_eob_Threshold_g;            /* Expression: 1
                                        * Referenced by: '<S34>/c_eob'
                                        */
  real_T Memory2_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S35>/Memory2'
                                        */
  real_T c_eob_Threshold_gt;           /* Expression: 1
                                        * Referenced by: '<S35>/c_eob'
                                        */
  real_T Memory2_X0_kk;                /* Expression: 0
                                        * Referenced by: '<S36>/Memory2'
                                        */
  real_T c_eob_Threshold_l;            /* Expression: 1
                                        * Referenced by: '<S36>/c_eob'
                                        */
  real_T Memory2_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S37>/Memory2'
                                        */
  real_T c_eob_Threshold_og;           /* Expression: 1
                                        * Referenced by: '<S37>/c_eob'
                                        */
  real_T Memory2_X0_cm;                /* Expression: 0
                                        * Referenced by: '<S38>/Memory2'
                                        */
  real_T c_eob_Threshold_fz;           /* Expression: 1
                                        * Referenced by: '<S38>/c_eob'
                                        */
  real_T Memory2_X0_l0;                /* Expression: 0
                                        * Referenced by: '<S39>/Memory2'
                                        */
  real_T c_eob_Threshold_p;            /* Expression: 1
                                        * Referenced by: '<S39>/c_eob'
                                        */
  real_T Memory2_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S30>/Memory2'
                                        */
  real_T c_eob_Threshold_mg;           /* Expression: 1
                                        * Referenced by: '<S30>/c_eob'
                                        */
  real_T Memory2_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S31>/Memory2'
                                        */
  real_T c_eob_Threshold_d;            /* Expression: 1
                                        * Referenced by: '<S31>/c_eob'
                                        */
  real_T Memory_X0_h;                  /* Expression: 0
                                        * Referenced by: '<S25>/Memory'
                                        */
  real_T _Threshold;                   /* Expression: 1
                                        * Referenced by: '<S17>/1'
                                        */
  real_T UD_InitialCondition;          /* Expression: ICPrevInput
                                        * Referenced by: '<S27>/UD'
                                        */
  real_T UD_InitialCondition_c;        /* Expression: ICPrevInput
                                        * Referenced by: '<S28>/UD'
                                        */
  real_T u15_Gain_b;                   /* Expression: 1/15
                                        * Referenced by: '<S15>/ 1//15'
                                        */
  real_T _Value_j;                     /* Expression: 1
                                        * Referenced by: '<S52>/1'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S52>/Memory3'
                                        */
  real_T switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<S52>/switch1 '
                                        */
  real_T Saturation1_UpperSat_h;       /* Expression: 1
                                        * Referenced by: '<S52>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_p;       /* Expression: 0
                                        * Referenced by: '<S52>/Saturation1'
                                        */
  real_T Memory1_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S52>/Memory1'
                                        */
  real_T Memory1_X0_po;                /* Expression: 0
                                        * Referenced by: '<S64>/Memory1'
                                        */
  real_T c_eob_Threshold_ll;           /* Expression: 1
                                        * Referenced by: '<S64>/c_eob'
                                        */
  real_T c_eob_Threshold_k;            /* Expression: 1
                                        * Referenced by: '<S15>/c_eob'
                                        */
  real_T Limcontr_A[2116];             /* Computed Parameter: Limcontr_A
                                        * Referenced by: '<S55>/Lim. contr.'
                                        */
  real_T Limcontr_B[782];              /* Computed Parameter: Limcontr_B
                                        * Referenced by: '<S55>/Lim. contr.'
                                        */
  real_T Limcontr_C[506];              /* Computed Parameter: Limcontr_C
                                        * Referenced by: '<S55>/Lim. contr.'
                                        */
  real_T Limcontr_D[187];              /* Computed Parameter: Limcontr_D
                                        * Referenced by: '<S55>/Lim. contr.'
                                        */
  real_T Limcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S55>/Lim. contr.'
                                        */
  real_T Currcontr_A[121];             /* Computed Parameter: Currcontr_A
                                        * Referenced by: '<S55>/Curr. contr.'
                                        */
  real_T Currcontr_B[121];             /* Computed Parameter: Currcontr_B
                                        * Referenced by: '<S55>/Curr. contr.'
                                        */
  real_T Currcontr_C[121];             /* Computed Parameter: Currcontr_C
                                        * Referenced by: '<S55>/Curr. contr.'
                                        */
  real_T Currcontr_X0;                 /* Expression: 0
                                        * Referenced by: '<S55>/Curr. contr.'
                                        */
  real_T switch1_Threshold_p;          /* Expression: 1
                                        * Referenced by: '<S52>/switch1'
                                        */
  real_T _Value_l;                     /* Expression: 1
                                        * Referenced by: '<S15>/1 '
                                        */
  real_T _Value_ja;                    /* Expression: 1
                                        * Referenced by: '<S53>/1'
                                        */
  real_T e3_Gain_i;                    /* Expression: 1e3
                                        * Referenced by: '<S53>/1e3'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 1
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -1
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T Constant_Value_a;             /* Expression: const
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T Memory1_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S66>/Memory1'
                                        */
  real_T Constant_Value_d;             /* Expression: const
                                        * Referenced by: '<S85>/Constant'
                                        */
  real_T Memory_X0_l;                  /* Expression: 0
                                        * Referenced by: '<S58>/Memory'
                                        */
  real_T Constant_Value_k;             /* Expression: const
                                        * Referenced by: '<S77>/Constant'
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
  real_T u_Threshold;                  /* Expression: 0.1
                                        * Referenced by: '<S58>/0.1'
                                        */
  real_T Memory1_X0_m4;                /* Expression: 0
                                        * Referenced by: '<S62>/Memory1'
                                        */
  real_T Constant_Value_f;             /* Expression: const
                                        * Referenced by: '<S81>/Constant'
                                        */
  real_T switch1_Threshold_a;          /* Expression: 1
                                        * Referenced by: '<S62>/switch1'
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
  real_T _Threshold_b;                 /* Expression: 1
                                        * Referenced by: '<S66>/1'
                                        */
  real_T Constant_Value_kq;            /* Expression: const
                                        * Referenced by: '<S72>/Constant'
                                        */
  real_T _Value_gi;                    /* Expression: 1
                                        * Referenced by: '<S54>/1'
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
  real_T u01_Gain;                     /* Expression: 1e-3
                                        * Referenced by: '<S86>/0.001'
                                        */
  real_T u01_Gain_f;                   /* Expression: 1e-3
                                        * Referenced by: '<S89>/0.001'
                                        */
  real_T u01_Gain_c;                   /* Expression: 1e-3
                                        * Referenced by: '<S90>/0.001'
                                        */
  real_T u01_Gain_fp;                  /* Expression: 1e-3
                                        * Referenced by: '<S91>/0.001'
                                        */
  real_T u01_Gain_n;                   /* Expression: 1e-3
                                        * Referenced by: '<S92>/0.001'
                                        */
  real_T u01_Gain_b;                   /* Expression: 1e-3
                                        * Referenced by: '<S93>/0.001'
                                        */
  real_T u01_Gain_p;                   /* Expression: 1e-3
                                        * Referenced by: '<S94>/0.001'
                                        */
  real_T u01_Gain_l;                   /* Expression: 1e-3
                                        * Referenced by: '<S95>/0.001'
                                        */
  real_T u01_Gain_pg;                  /* Expression: 1e-3
                                        * Referenced by: '<S96>/0.001'
                                        */
  real_T u01_Gain_o;                   /* Expression: 1e-3
                                        * Referenced by: '<S87>/0.001'
                                        */
  real_T u01_Gain_bh;                  /* Expression: 1e-3
                                        * Referenced by: '<S88>/0.001'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S71>/Constant'
                                        */
  real_T UniformRandomNumber_Minimum;  /* Expression: -1
                                        * Referenced by: '<S63>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 1
                                        * Referenced by: '<S63>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S63>/Uniform Random Number'
                                        */
  real_T u5_Gain;                      /* Expression: 1.75
                                        * Referenced by: '<S82>/1.75'
                                        */
  real_T UD_InitialCondition_o;        /* Expression: ICPrevInput
                                        * Referenced by: '<S83>/UD'
                                        */
  real_T e3_Gain_k;                    /* Expression: 2e3
                                        * Referenced by: '<S82>/2e3'
                                        */
  real_T VScontr_A[34];                /* Computed Parameter: VScontr_A
                                        * Referenced by: '<S60>/VS. contr'
                                        */
  real_T VScontr_B[16];                /* Computed Parameter: VScontr_B
                                        * Referenced by: '<S60>/VS. contr'
                                        */
  real_T VScontr_C[10];                /* Computed Parameter: VScontr_C
                                        * Referenced by: '<S60>/VS. contr'
                                        */
  real_T VScontr_D[4];                 /* Computed Parameter: VScontr_D
                                        * Referenced by: '<S60>/VS. contr'
                                        */
  real_T VScontr_X0;                   /* Expression: 0
                                        * Referenced by: '<S60>/VS. contr'
                                        */
  real_T Constant_Value_ao;            /* Expression: const
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T VScontrhl_A[33];              /* Computed Parameter: VScontrhl_A
                                        * Referenced by: '<S60>/VS. contr hl'
                                        */
  real_T VScontrhl_B[15];              /* Computed Parameter: VScontrhl_B
                                        * Referenced by: '<S60>/VS. contr hl'
                                        */
  real_T VScontrhl_C[9];               /* Computed Parameter: VScontrhl_C
                                        * Referenced by: '<S60>/VS. contr hl'
                                        */
  real_T VScontrhl_D[4];               /* Computed Parameter: VScontrhl_D
                                        * Referenced by: '<S60>/VS. contr hl'
                                        */
  real_T VScontrhl_X0;                 /* Expression: 0
                                        * Referenced by: '<S60>/VS. contr hl'
                                        */
  real_T c_eob_Threshold_ou;           /* Expression: 1
                                        * Referenced by: '<S60>/c_eob'
                                        */
  real_T Constant_Value_l;             /* Expression: const
                                        * Referenced by: '<S78>/Constant'
                                        */
  real_T u5_Gain_a;                    /* Expression: 1/15
                                        * Referenced by: '<S61>/1//15'
                                        */
  real_T _Threshold_e;                 /* Expression: 1
                                        * Referenced by: '<S59>/1'
                                        */
  real_T G_curr_term_Gain[220];        /* Expression: [zeros(8,11); eye(11); zeros(1,11)]
                                        * Referenced by: '<S15>/G_curr_term'
                                        */
  real_T e6_Gain_g;                    /* Expression: 1e6
                                        * Referenced by: '<S55>/1e6'
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
  real_T DataStoreMemory4_InitialValue;/* Expression: 0.1
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
  real_T Memory1_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S3>/Memory1'
                                        */
  real_T wz1_Value[11];                /* Expression: [0 0 0 0 0 0 -1 -1 1 1 0]'
                                        * Referenced by: '<S2>/wz1'
                                        */
  real_T Memory1_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory1'
                                        */
  real_T wz2_Value;                    /* Expression: 1
                                        * Referenced by: '<S2>/wz2'
                                        */
  real_T Memory2_X0_ci;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T npf12_Gain[180];              /* Expression: eye(15,11+1)
                                        * Referenced by: '<S2>/npf,12'
                                        */
  real_T UD_InitialCondition_e;        /* Expression: ICPrevInput
                                        * Referenced by: '<S6>/UD'
                                        */
  real_T Memory1_X0_hm;                /* Expression: 0
                                        * Referenced by: '<S7>/Memory1'
                                        */
  real_T _Gain;                        /* Expression: 2
                                        * Referenced by: '<S8>/2'
                                        */
  real_T u_Gain_e;                     /* Expression: -1
                                        * Referenced by: '<S8>/-1'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T DataStoreMemory1_InitialValue_m[12];/* Expression: [554,554,554,554,554  248.6 115.2 185.9 169.9 216.8  459.4 1]
                                              * Referenced by: '<S1>/Data Store Memory1'
                                              */
  real_T DataStoreMemory2_InitialValue_j[6];/* Expression: [1; ones(5,1)*1e-6]
                                             * Referenced by: '<S1>/Data Store Memory2'
                                             */
  real_T DataStoreMemory3_InitialValue_i;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory3'
                                          */
  real_T DataStoreMemory4_InitialValue_i[11];/* Expression: zeros(11,1)
                                              * Referenced by: '<S1>/Data Store Memory4'
                                              */
  real_T DataStoreMemory5_InitialValue_h;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory5'
                                          */
  real_T DataStoreMemory7_InitialValue_b;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory7'
                                          */
  real_T DataStoreMemory8_InitialValue_e;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory8'
                                          */
  real_T DataStoreMemory9_InitialValue_e[11];/* Expression: ones(1,11)*1e6
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
 * Block '<S54>/1 ' : Unused code path elimination
 * Block '<S54>/Divide4' : Unused code path elimination
 * Block '<S54>/Memory1' : Unused code path elimination
 * Block '<S54>/Saturation' : Unused code path elimination
 * Block '<S54>/Subtract1' : Unused code path elimination
 * Block '<S54>/Subtract2' : Unused code path elimination
 * Block '<S54>/Subtract3' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Propagation' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/To Workspace' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Propagation' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Propagation' : Unused code path elimination
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
 * '<S17>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Err.'
 * '<S18>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Ics1_end'
 * '<S19>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Ip_ref scr_data.dat'
 * '<S20>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/dZ//dt'
 * '<S21>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/elong_ref.dat'
 * '<S22>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat'
 * '<S23>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat'
 * '<S24>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g4'
 * '<S25>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Err./Trigger'
 * '<S26>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Ics1_end/Trigger'
 * '<S27>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/dZ//dt/Difference'
 * '<S28>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/dZ//dt/Difference1'
 * '<S29>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil1 ref'
 * '<S30>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil10 ref'
 * '<S31>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil11 ref'
 * '<S32>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil2 ref'
 * '<S33>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil3 ref'
 * '<S34>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil4 ref'
 * '<S35>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil5 ref'
 * '<S36>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil6 ref'
 * '<S37>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil7 ref'
 * '<S38>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil8 ref'
 * '<S39>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil9 ref'
 * '<S40>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem1'
 * '<S41>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem2'
 * '<S42>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem3'
 * '<S43>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem4'
 * '<S44>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem5'
 * '<S45>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem6'
 * '<S46>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem1/g2_term,ref'
 * '<S47>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem2/g3_term,ref'
 * '<S48>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem3/g4_term,ref'
 * '<S49>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem4/g5_term,ref'
 * '<S50>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem5/g6_term,ref'
 * '<S51>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem6/g1_term,ref'
 * '<S52>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/ tt_kavin2.dat(1)'
 * '<S53>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Curr. satur.1'
 * '<S54>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Ip>cIp_end'
 * '<S55>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1'
 * '<S56>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Saturation Dynamic'
 * '<S57>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Saturation Dynamic1'
 * '<S58>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem7'
 * '<S59>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem8'
 * '<S60>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS VShl contr.'
 * '<S61>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS gain 1'
 * '<S62>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/div_divrd'
 * '<S63>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/dzdt noise1'
 * '<S64>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/scr_data.dat'
 * '<S65>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/t_tran2D'
 * '<S66>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/tt_kavin2.dat(1,4)'
 * '<S67>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat'
 * '<S68>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/ tt_kavin2.dat(1)/Compare To Constant'
 * '<S69>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/ tt_kavin2.dat(1)/Ip<|cIp_end|'
 * '<S70>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Curr. satur.1/Compare To Constant'
 * '<S71>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Curr. satur.1/Compare To Zero'
 * '<S72>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Ip>cIp_end/Compare To Constant1'
 * '<S73>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Ip>cIp_end/Ip<cIp_end'
 * '<S74>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1/gain_cont2'
 * '<S75>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1/t_cont2'
 * '<S76>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1/t_cont2_2'
 * '<S77>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem7/Compare To Constant1'
 * '<S78>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem8/Compare To Constant1'
 * '<S79>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS VShl contr./Compare To Constant1'
 * '<S80>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS gain 1/Saturation Dynamic'
 * '<S81>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/div_divrd/Compare To Constant1'
 * '<S82>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/dzdt noise1/Subsystem'
 * '<S83>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/dzdt noise1/Subsystem/Difference'
 * '<S84>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/scr_data.dat/Saturation Dynamic'
 * '<S85>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/tt_kavin2.dat(1,4)/Compare To Constant1'
 * '<S86>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt1'
 * '<S87>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt10'
 * '<S88>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt11'
 * '<S89>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt2'
 * '<S90>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt3'
 * '<S91>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt4'
 * '<S92>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt5'
 * '<S93>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt6'
 * '<S94>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt7'
 * '<S95>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt8'
 * '<S96>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt9'
 */
#endif                                 /* RTW_HEADER_t15_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
