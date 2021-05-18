/*
 * File: t15_2.h
 *
 * Code generated for Simulink model 't15_2'.
 *
 * Model version                  : 1.1155
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Sun Apr 11 18:58:01 2021
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
  real_T e6_d[15];                     /* '<S14>/1e-6   ' */
  real_T Memory1;                      /* '<S18>/Memory1' */
  real_T DataStoreRead1_k;             /* '<S18>/Data Store Read1' */
  real_T e3;                           /* '<S18>/1e-3' */
  real_T DataStoreRead2;               /* '<S18>/Data Store Read2' */
  real_T Product1;                     /* '<S18>/Product1' */
  real_T RelationalOperator;           /* '<S18>/Relational Operator' */
  real_T Memory;                       /* '<S26>/Memory' */
  real_T LogicalOperator;              /* '<S26>/Logical Operator' */
  real_T switch0;                      /* '<S18>/switch0' */
  real_T Add2;                         /* '<S18>/Add2' */
  real_T DataStoreRead_e;              /* '<S18>/Data Store Read' */
  real_T Product;                      /* '<S18>/Product' */
  real_T Add1;                         /* '<S18>/Add1' */
  real_T u_d;                          /* '<S18>/1 0' */
  real_T Memory1_i;                    /* '<S19>/Memory1' */
  real_T c_eob;                        /* '<S19>/c_eob' */
  real_T Divide6;                      /* '<S19>/Divide6' */
  real_T Add1_h;                       /* '<S14>/Add1' */
  real_T SFunction1_i[100];            /* '<S21>/S-Function1' */
  real_T e2[6];                        /* '<S23>/1e2' */
  real_T SFunction1_j[100];            /* '<S45>/S-Function1' */
  real_T Memory2_k;                    /* '<S45>/Memory2' */
  real_T c_eob1;                       /* '<S45>/c_eob  1' */
  real_T Memory1_e;                    /* '<S45>/Memory1' */
  real_T c_eob_m;                      /* '<S45>/c_eob  ' */
  real_T SFunction1_i5[100];           /* '<S51>/S-Function1' */
  real_T c_eob_c;                      /* '<S45>/c_eob' */
  real_T Add2_g;                       /* '<S23>/Add2' */
  real_T SFunction1_a[100];            /* '<S40>/S-Function1' */
  real_T Memory2_m;                    /* '<S40>/Memory2' */
  real_T c_eob1_j;                     /* '<S40>/c_eob  1' */
  real_T Memory1_h;                    /* '<S40>/Memory1' */
  real_T c_eob_n;                      /* '<S40>/c_eob  ' */
  real_T SFunction1_h[100];            /* '<S46>/S-Function1' */
  real_T c_eob_b;                      /* '<S40>/c_eob' */
  real_T Add1_a;                       /* '<S23>/Add1' */
  real_T SFunction1_o[100];            /* '<S41>/S-Function1' */
  real_T Memory2_g;                    /* '<S41>/Memory2' */
  real_T c_eob1_i;                     /* '<S41>/c_eob  1' */
  real_T Memory1_a;                    /* '<S41>/Memory1' */
  real_T c_eob_o;                      /* '<S41>/c_eob  ' */
  real_T SFunction1_c[100];            /* '<S47>/S-Function1' */
  real_T c_eob_n0;                     /* '<S41>/c_eob' */
  real_T Add3;                         /* '<S23>/Add3' */
  real_T SFunction1_l[100];            /* '<S42>/S-Function1' */
  real_T Memory2_j;                    /* '<S42>/Memory2' */
  real_T c_eob1_l;                     /* '<S42>/c_eob  1' */
  real_T Memory1_o;                    /* '<S42>/Memory1' */
  real_T c_eob_op;                     /* '<S42>/c_eob  ' */
  real_T SFunction1_a1[100];           /* '<S48>/S-Function1' */
  real_T c_eob_i;                      /* '<S42>/c_eob' */
  real_T Add4;                         /* '<S23>/Add4' */
  real_T SFunction1_h2[100];           /* '<S43>/S-Function1' */
  real_T Memory2_n;                    /* '<S43>/Memory2' */
  real_T c_eob1_e;                     /* '<S43>/c_eob  1' */
  real_T Memory1_b;                    /* '<S43>/Memory1' */
  real_T c_eob_a;                      /* '<S43>/c_eob  ' */
  real_T SFunction1_ob[100];           /* '<S49>/S-Function1' */
  real_T c_eob_h;                      /* '<S43>/c_eob' */
  real_T Add5;                         /* '<S23>/Add5' */
  real_T SFunction1_iq[100];           /* '<S44>/S-Function1' */
  real_T Memory2_l;                    /* '<S44>/Memory2' */
  real_T c_eob1_b;                     /* '<S44>/c_eob  1' */
  real_T Memory1_ix;                   /* '<S44>/Memory1' */
  real_T c_eob_g;                      /* '<S44>/c_eob  ' */
  real_T SFunction1_g[100];            /* '<S50>/S-Function1' */
  real_T c_eob_l;                      /* '<S44>/c_eob' */
  real_T Add6;                         /* '<S23>/Add6' */
  real_T e2_n[6];                      /* '<S23>/1e-2' */
  real_T Memory2_kw;                   /* '<S29>/Memory2' */
  real_T c_eob_d;                      /* '<S29>/c_eob' */
  real_T Divide1;                      /* '<S29>/Divide1' */
  real_T Add3_g;                       /* '<S22>/Add3' */
  real_T Memory2_i;                    /* '<S32>/Memory2' */
  real_T c_eob_bw;                     /* '<S32>/c_eob' */
  real_T Divide1_d;                    /* '<S32>/Divide1' */
  real_T Add1_e;                       /* '<S22>/Add1' */
  real_T Memory2_o;                    /* '<S33>/Memory2' */
  real_T c_eob_lk;                     /* '<S33>/c_eob' */
  real_T Divide1_k;                    /* '<S33>/Divide1' */
  real_T Add2_a;                       /* '<S22>/Add2' */
  real_T Memory2_iw;                   /* '<S34>/Memory2' */
  real_T c_eob_c0;                     /* '<S34>/c_eob' */
  real_T Divide1_k2;                   /* '<S34>/Divide1' */
  real_T Add4_d;                       /* '<S22>/Add4' */
  real_T Memory2_h;                    /* '<S35>/Memory2' */
  real_T c_eob_c0i;                    /* '<S35>/c_eob' */
  real_T Divide1_h;                    /* '<S35>/Divide1' */
  real_T Add5_p;                       /* '<S22>/Add5' */
  real_T Memory2_iz;                   /* '<S36>/Memory2' */
  real_T c_eob_j;                      /* '<S36>/c_eob' */
  real_T Divide1_j;                    /* '<S36>/Divide1' */
  real_T Add6_c;                       /* '<S22>/Add6' */
  real_T Memory2_iq;                   /* '<S37>/Memory2' */
  real_T c_eob_ga;                     /* '<S37>/c_eob' */
  real_T Divide1_jo;                   /* '<S37>/Divide1' */
  real_T Add7;                         /* '<S22>/Add7' */
  real_T Memory2_oi;                   /* '<S38>/Memory2' */
  real_T c_eob_e;                      /* '<S38>/c_eob' */
  real_T Divide1_a;                    /* '<S38>/Divide1' */
  real_T Add8;                         /* '<S22>/Add8' */
  real_T Memory2_it;                   /* '<S39>/Memory2' */
  real_T c_eob_p;                      /* '<S39>/c_eob' */
  real_T Divide1_o;                    /* '<S39>/Divide1' */
  real_T Add9;                         /* '<S22>/Add9' */
  real_T Memory2_kf;                   /* '<S30>/Memory2' */
  real_T c_eob_oe;                     /* '<S30>/c_eob' */
  real_T Divide1_hf;                   /* '<S30>/Divide1' */
  real_T Add10;                        /* '<S22>/Add10' */
  real_T Memory2_hf;                   /* '<S31>/Memory2' */
  real_T c_eob_ox;                     /* '<S31>/c_eob' */
  real_T Divide1_p;                    /* '<S31>/Divide1' */
  real_T Add11;                        /* '<S22>/Add11' */
  real_T DataStoreRead1_o;             /* '<S17>/Data Store Read1' */
  real_T RelationalOperator_c;         /* '<S17>/Relational Operator' */
  real_T Memory_e;                     /* '<S25>/Memory' */
  real_T LogicalOperator_e;            /* '<S25>/Logical Operator' */
  real_T u_b[20];                      /* '<S17>/1' */
  real_T Uk1;                          /* '<S27>/UD' */
  real_T Diff;                         /* '<S27>/Diff' */
  real_T Uk1_j;                        /* '<S28>/UD' */
  real_T Diff_a;                       /* '<S28>/Diff' */
  real_T Divide;                       /* '<S20>/Divide' */
  real_T DataStoreRead_g;              /* '<S15>/Data Store Read' */
  real_T u15;                          /* '<S15>/ 1//15' */
  real_T DataStoreRead_m;              /* '<S52>/Data Store Read' */
  real_T Memory3;                      /* '<S52>/Memory3' */
  real_T DataStoreRead_l;              /* '<S69>/Data Store Read' */
  real_T Abs;                          /* '<S69>/Abs' */
  real_T LogicalOperator1;             /* '<S52>/Logical Operator1' */
  real_T switch1;                      /* '<S52>/switch1 ' */
  real_T Subtract2;                    /* '<S52>/Subtract2' */
  real_T Divide1_ho;                   /* '<S52>/Divide1' */
  real_T Subtract1;                    /* '<S52>/Subtract1' */
  real_T Saturation1;                  /* '<S52>/Saturation1' */
  real_T Memory1_n[11];                /* '<S52>/Memory1' */
  real_T Memory1_bb;                   /* '<S64>/Memory1' */
  real_T c_eob_n2;                     /* '<S64>/c_eob' */
  real_T c_eob_hg;                     /* '<S15>/c_eob' */
  real_T DataStoreRead_p;              /* '<S75>/Data Store Read' */
  real_T Divide12[20];                 /* '<S75>/Divide12' */
  real_T Limcontr[11];                 /* '<S55>/Lim. contr.' */
  real_T Currcontr[11];                /* '<S55>/Curr. contr.' */
  real_T DataStoreRead2_d[11];         /* '<S55>/Data Store Read2' */
  real_T switch1_l[11];                /* '<S52>/switch1' */
  real_T Divide5[11];                  /* '<S52>/Divide5' */
  real_T Subtract3;                    /* '<S52>/Subtract3' */
  real_T e3_o[11];                     /* '<S53>/1e3' */
  real_T Abs_d[11];                    /* '<S53>/Abs' */
  real_T DataStoreRead1_e[11];         /* '<S15>/Data Store Read1' */
  real_T DataStoreRead2_k[11];         /* '<S53>/Data Store Read2' */
  real_T Divide5_h[11];                /* '<S53>/Divide5' */
  real_T Sum2_n[11];                   /* '<S53>/Sum2' */
  real_T DataStoreRead1_kg;            /* '<S53>/Data Store Read1' */
  real_T Divide3[11];                  /* '<S53>/Divide3' */
  real_T Sum1[11];                     /* '<S53>/Sum1' */
  real_T Divide4[11];                  /* '<S53>/Divide4' */
  real_T Divide1_pt[11];               /* '<S53>/Divide1' */
  real_T Saturation[11];               /* '<S53>/Saturation' */
  real_T Memory1_ij[11];               /* '<S66>/Memory1' */
  real_T DataStoreRead_po;             /* '<S66>/Data Store Read' */
  real_T Abs_a;                        /* '<S66>/Abs' */
  real_T LogicalOperator2;             /* '<S66>/Logical Operator2' */
  real_T Memory_i[11];                 /* '<S58>/Memory' */
  real_T DataStoreRead_f;              /* '<S58>/Data Store Read' */
  real_T DataStoreRead1_i;             /* '<S58>/Data Store Read1' */
  real_T Abs_h;                        /* '<S58>/Abs' */
  real_T LogicalOperator1_n;           /* '<S58>/Logical Operator1' */
  real_T Divide2[20];                  /* '<S15>/Divide2' */
  real_T Divcontr[11];                 /* '<S15>/Div. contr.' */
  real_T u_k[11];                      /* '<S58>/0.1' */
  real_T Memory1_nd;                   /* '<S62>/Memory1' */
  real_T DataStoreRead_i;              /* '<S62>/Data Store Read' */
  real_T LogicalOperator1_l;           /* '<S62>/Logical Operator1' */
  real_T switch1_f;                    /* '<S62>/switch1' */
  real_T Divide13[20];                 /* '<S15>/Divide13' */
  real_T Div_rdcontr[11];              /* '<S15>/Div_rd contr' */
  real_T u_o[11];                      /* '<S66>/1' */
  real_T DataStoreRead_py;             /* '<S73>/Data Store Read' */
  real_T Abs_j;                        /* '<S73>/Abs' */
  real_T LogicalOperator2_a;           /* '<S54>/Logical Operator2' */
  real_T Subtract4;                    /* '<S54>/Subtract4' */
  real_T Divide4_i[11];                /* '<S15>/Divide4' */
  real_T Currtermcontr[11];            /* '<S15>/Curr. term. contr' */
  real_T Divide5_c[11];                /* '<S15>/Divide5' */
  real_T DataStoreRead_ia[500];        /* '<S86>/Data Store Read' */
  real_T u01[500];                     /* '<S86>/0.001' */
  real_T DataStoreRead1_b[500];        /* '<S86>/Data Store Read1' */
  real_T volt1;                        /* '<S86>/volt1' */
  real_T DataStoreRead_gc[500];        /* '<S89>/Data Store Read' */
  real_T u01_b[500];                   /* '<S89>/0.001' */
  real_T DataStoreRead1_l[500];        /* '<S89>/Data Store Read1' */
  real_T volt1_i;                      /* '<S89>/volt1' */
  real_T DataStoreRead_c[500];         /* '<S90>/Data Store Read' */
  real_T u01_o[500];                   /* '<S90>/0.001' */
  real_T DataStoreRead1_f[500];        /* '<S90>/Data Store Read1' */
  real_T volt1_j;                      /* '<S90>/volt1' */
  real_T DataStoreRead_j[500];         /* '<S91>/Data Store Read' */
  real_T u01_p[500];                   /* '<S91>/0.001' */
  real_T DataStoreRead1_lo[500];       /* '<S91>/Data Store Read1' */
  real_T volt1_g;                      /* '<S91>/volt1' */
  real_T DataStoreRead_a[500];         /* '<S92>/Data Store Read' */
  real_T u01_i[500];                   /* '<S92>/0.001' */
  real_T DataStoreRead1_j[500];        /* '<S92>/Data Store Read1' */
  real_T volt1_ip;                     /* '<S92>/volt1' */
  real_T DataStoreRead_cm[500];        /* '<S93>/Data Store Read' */
  real_T u01_pb[500];                  /* '<S93>/0.001' */
  real_T DataStoreRead1_ou[500];       /* '<S93>/Data Store Read1' */
  real_T volt1_d;                      /* '<S93>/volt1' */
  real_T DataStoreRead_d[500];         /* '<S94>/Data Store Read' */
  real_T u01_j[500];                   /* '<S94>/0.001' */
  real_T DataStoreRead1_b5[500];       /* '<S94>/Data Store Read1' */
  real_T volt1_l;                      /* '<S94>/volt1' */
  real_T DataStoreRead_ew[500];        /* '<S95>/Data Store Read' */
  real_T u01_a[500];                   /* '<S95>/0.001' */
  real_T DataStoreRead1_h[500];        /* '<S95>/Data Store Read1' */
  real_T volt1_m;                      /* '<S95>/volt1' */
  real_T DataStoreRead_es[500];        /* '<S96>/Data Store Read' */
  real_T u01_ps[500];                  /* '<S96>/0.001' */
  real_T DataStoreRead1_b1[500];       /* '<S96>/Data Store Read1' */
  real_T volt1_n;                      /* '<S96>/volt1' */
  real_T DataStoreRead_fz[500];        /* '<S87>/Data Store Read' */
  real_T u01_e[500];                   /* '<S87>/0.001' */
  real_T DataStoreRead1_n[500];        /* '<S87>/Data Store Read1' */
  real_T volt1_jc;                     /* '<S87>/volt1' */
  real_T DataStoreRead_k[500];         /* '<S88>/Data Store Read' */
  real_T u01_ir[500];                  /* '<S88>/0.001' */
  real_T DataStoreRead1_o0[500];       /* '<S88>/Data Store Read1' */
  real_T volt1_o;                      /* '<S88>/volt1' */
  real_T Sum1_j;                       /* '<S15>/Sum1' */
  real_T Divide7[11];                  /* '<S15>/Divide7' */
  real_T Sum3[11];                     /* '<S15>/Sum3' */
  real_T Divide2_g[11];                /* '<S53>/Divide2' */
  real_T Switch[11];                   /* '<S53>/Switch' */
  real_T Divide6_f[11];                /* '<S53>/Divide6' */
  real_T UniformRandomNumber;          /* '<S63>/Uniform Random Number' */
  real_T DataStoreRead_gs;             /* '<S82>/Data Store Read' */
  real_T u5;                           /* '<S82>/1.75' */
  real_T Divide11;                     /* '<S82>/Divide11' */
  real_T Uk1_i;                        /* '<S83>/UD' */
  real_T Diff_f;                       /* '<S83>/Diff' */
  real_T e3_h;                         /* '<S82>/2e3' */
  real_T Sqrt;                         /* '<S82>/Sqrt' */
  real_T Divide1_n;                    /* '<S82>/Divide1' */
  real_T Sum2_o;                       /* '<S63>/Sum2' */
  real_T DataStoreRead_i2;             /* '<S65>/Data Store Read' */
  real_T RelationalOperator1;          /* '<S65>/Relational Operator1' */
  real_T Divide12_g[2];                /* '<S65>/Divide12' */
  real_T VScontr[2];                   /* '<S60>/VS. contr' */
  real_T Divide4_b[2];                 /* '<S60>/Divide4' */
  real_T VScontrhl[2];                 /* '<S60>/VS. contr hl' */
  real_T c_eob_dy[2];                  /* '<S60>/c_eob' */
  real_T DataStoreRead1_nw;            /* '<S59>/Data Store Read1' */
  real_T RelationalOperator2;          /* '<S59>/Relational Operator2' */
  real_T DataStoreRead_o;              /* '<S59>/Data Store Read' */
  real_T Abs_m;                        /* '<S59>/Abs' */
  real_T RelationalOperator1_j;        /* '<S59>/Relational Operator1' */
  real_T LogicalOperator1_p;           /* '<S59>/Logical Operator1' */
  real_T DataStoreRead_ae;             /* '<S61>/Data Store Read' */
  real_T u5_b;                         /* '<S61>/1//15' */
  real_T Div;                          /* '<S61>/Div' */
  real_T u_p[2];                       /* '<S59>/1' */
  real_T Divide10[2];                  /* '<S15>/Divide10' */
  real_T G_curr_term[20];              /* '<S15>/G_curr_term' */
  real_T Divide12_i[20];               /* '<S15>/Divide12' */
  real_T DataStoreRead_ia0;            /* '<S54>/Data Store Read' */
  real_T Divide1_e[11];                /* '<S55>/Divide1' */
  real_T e6_j[11];                     /* '<S55>/1e6' */
  real_T DataStoreRead2_l[11];         /* '<S5>/Data Store Read2' */
  real_T Divide4_g[11];                /* '<S5>/Divide4' */
  real_T SFunction_o[44];              /* '<S1>/S-Function' */
  real_T Memory1_o5[11];               /* '<S3>/Memory1' */
  real_T DataStoreRead2_kz[11];        /* '<S2>/Data Store Read2' */
  real_T Divide3_g[11];                /* '<S2>/Divide3' */
  real_T Divide1_ah[11];               /* '<S2>/Divide1' */
  real_T Memory1_d;                    /* '<S4>/Memory1' */
  real_T Divide2_gv[11];               /* '<S2>/Divide2' */
  real_T Add1_j[11];                   /* '<S2>/Add1' */
  real_T DataStoreRead1_nr;            /* '<S2>/Data Store Read1' */
  real_T Divide4_f;                    /* '<S2>/Divide4' */
  real_T Memory2_c;                    /* '<S4>/Memory2' */
  real_T Divide5_d;                    /* '<S2>/Divide5' */
  real_T TmpSignalConversionAtnpf12Inpor[12];
  real_T npf12[15];                    /* '<S2>/npf,12' */
  real_T Uk1_o;                        /* '<S6>/UD' */
  real_T Diff_a3;                      /* '<S6>/Diff' */
  real_T Memory1_h3[11];               /* '<S7>/Memory1' */
  real_T Add1_n[11];                   /* '<S7>/Add1' */
  real_T DataStoreRead1_a[11];         /* '<S8>/Data Store Read1' */
  real_T u_c[11];                      /* '<S8>/2' */
  real_T DataStoreRead3;               /* '<S8>/Data Store Read3' */
  real_T Divide1_pz[11];               /* '<S8>/Divide1' */
  real_T Divide_p[11];                 /* '<S7>/Divide' */
  real_T u_h[11];                      /* '<S8>/-1' */
  real_T Switch_k[11];                 /* '<S10>/Switch' */
  real_T Switch2[11];                  /* '<S10>/Switch2' */
  real_T Divide1_df[11];               /* '<S7>/Divide1' */
  real_T Add2_o[11];                   /* '<S7>/Add2' */
  real_T DataStoreRead1_h2[11];        /* '<S9>/Data Store Read1' */
  real_T Gain[11];                     /* '<S9>/Gain' */
  real_T Switch_n[11];                 /* '<S11>/Switch' */
  real_T Switch2_o[11];                /* '<S11>/Switch2' */
  real_T DataStoreRead1_bu;            /* '<S4>/Data Store Read1' */
  real_T Switch2_i;                    /* '<S12>/Switch2' */
  real_T DataStoreRead3_e;             /* '<S4>/Data Store Read3' */
  real_T Switch2_j;                    /* '<S13>/Switch2' */
  real_T Subtract2_d;                  /* '<S62>/Subtract2' */
  real_T DataStoreRead1_aj;            /* '<S62>/Data Store Read1' */
  real_T Divide4_n;                    /* '<S62>/Divide4' */
  real_T Subtract3_g;                  /* '<S62>/Subtract3' */
  real_T Saturation_k;                 /* '<S62>/Saturation' */
  real_T Subtract1_a;                  /* '<S62>/Subtract1' */
  real_T Divide3_k[11];                /* '<S15>/Divide3' */
  real_T Divide1_b[11];                /* '<S15>/Divide1' */
  real_T Sum2_k[11];                   /* '<S15>/Sum2' */
  real_T Divide6_d;                    /* '<S15>/Divide6' */
  real_T Switch2_d;                    /* '<S56>/Switch2' */
  real_T Divide11_i[2];                /* '<S15>/Divide11' */
  real_T DataStoreRead3_m;             /* '<S15>/Data Store Read3' */
  real_T Switch_m;                     /* '<S56>/Switch' */
  real_T c_eob_ml[2];                  /* '<S15>/c_eob ' */
  real_T DataStoreRead1_om;            /* '<S61>/Data Store Read1' */
  real_T RelationalOperator2_p;        /* '<S61>/Relational Operator2' */
  real_T LimDivtr;                     /* '<S61>/Lim. Div. tr.' */
  real_T Divide8[2];                   /* '<S15>/Divide8' */
  real_T SatDiv;                       /* '<S61>/Sat. Div' */
  real_T DataStoreRead2_h;             /* '<S61>/Data Store Read2' */
  real_T Switch2_g;                    /* '<S80>/Switch2' */
  real_T Switch_c;                     /* '<S80>/Switch' */
  real_T Divide15;                     /* '<S15>/Divide15' */
  real_T DataStoreRead4;               /* '<S15>/Data Store Read4' */
  real_T Switch2_k;                    /* '<S57>/Switch2' */
  real_T Divide_d[2];                  /* '<S15>/Divide ' */
  real_T Switch_e;                     /* '<S57>/Switch' */
  real_T Divide_i[11];                 /* '<S15>/Divide' */
  real_T DataStoreRead_gh;             /* '<S76>/Data Store Read' */
  real_T u_d1[11];                     /* '<S76>/1' */
  real_T DataStoreRead1_m;             /* '<S74>/Data Store Read1' */
  real_T DataStoreRead_d4;             /* '<S74>/Data Store Read' */
  real_T Subtract3_p;                  /* '<S74>/Subtract3' */
  real_T Divide2_g0;                   /* '<S74>/Divide2' */
  real_T Saturation1_p;                /* '<S74>/Saturation1' */
  real_T Divide_c[11];                 /* '<S55>/Divide ' */
  real_T Divide2_o[11];                /* '<S55>/Divide2' */
  real_T DataStoreRead2_m;             /* '<S15>/Data Store Read2' */
  real_T u15_d;                        /* '<S15>/ 1//15 ' */
  real_T Divide9;                      /* '<S15>/Divide9' */
  real_T Saturation_f;                 /* '<S15>/Saturation' */
  real_T DataStoreRead2_n;             /* '<S64>/Data Store Read2' */
  real_T Sum3_i;                       /* '<S64>/Sum3' */
  real_T DataStoreRead4_a;             /* '<S64>/Data Store Read4' */
  real_T DataStoreRead3_g;             /* '<S64>/Data Store Read3' */
  real_T Sum2_kg;                      /* '<S64>/Sum2' */
  real_T Divide1_p1;                   /* '<S64>/Divide1' */
  real_T Divide6_o;                    /* '<S64>/Divide6' */
  real_T Sum;                          /* '<S64>/Sum' */
  real_T Divide2_e;                    /* '<S64>/Divide2' */
  real_T Sum1_k;                       /* '<S64>/Sum1' */
  real_T Switch2_b;                    /* '<S84>/Switch2' */
  real_T Switch_ef;                    /* '<S84>/Switch' */
  real_T Selector[49];                 /* '<S51>/Selector' */
  real_T TmpSignalConversionAtg1_termref[50];
  real_T DataStoreRead1_e2;            /* '<S51>/Data Store Read1' */
  real_T DataStoreRead_dc;             /* '<S51>/Data Store Read' */
  real_T Selector1[50];                /* '<S51>/Selector1' */
  real_T Divide6_c[50];                /* '<S51>/Divide6' */
  real_T Add2_k[50];                   /* '<S51>/Add2' */
  real_T g1_termref;                   /* '<S51>/g1_term,ref' */
  real_T Selector_f[50];               /* '<S45>/Selector' */
  real_T Selector1_c[50];              /* '<S45>/Selector1' */
  real_T g1ref;                        /* '<S45>/g1ref' */
  real_T Selector_h[49];               /* '<S50>/Selector' */
  real_T TmpSignalConversionAtg6_termref[50];
  real_T DataStoreRead1_o0y;           /* '<S50>/Data Store Read1' */
  real_T DataStoreRead_lp;             /* '<S50>/Data Store Read' */
  real_T Selector1_p[50];              /* '<S50>/Selector1' */
  real_T Divide6_a[50];                /* '<S50>/Divide6' */
  real_T Add2_d[50];                   /* '<S50>/Add2' */
  real_T g6_termref;                   /* '<S50>/g6_term,ref' */
  real_T Selector_p[50];               /* '<S44>/Selector' */
  real_T Selector1_m[50];              /* '<S44>/Selector1' */
  real_T g6ref;                        /* '<S44>/g6ref' */
  real_T Selector_pj[49];              /* '<S49>/Selector' */
  real_T TmpSignalConversionAtg5_termref[50];
  real_T DataStoreRead1_p;             /* '<S49>/Data Store Read1' */
  real_T DataStoreRead_df;             /* '<S49>/Data Store Read' */
  real_T Selector1_f[50];              /* '<S49>/Selector1' */
  real_T Divide6_cp[50];               /* '<S49>/Divide6' */
  real_T Add2_i[50];                   /* '<S49>/Add2' */
  real_T g5_termref;                   /* '<S49>/g5_term,ref' */
  real_T Selector_n[50];               /* '<S43>/Selector' */
  real_T Selector1_ph[50];             /* '<S43>/Selector1' */
  real_T g5ref;                        /* '<S43>/g5ref' */
  real_T Selector_a[49];               /* '<S48>/Selector' */
  real_T TmpSignalConversionAtg4_termref[50];
  real_T DataStoreRead1_nt;            /* '<S48>/Data Store Read1' */
  real_T DataStoreRead_dk;             /* '<S48>/Data Store Read' */
  real_T Selector1_mh[50];             /* '<S48>/Selector1' */
  real_T Divide6_n[50];                /* '<S48>/Divide6' */
  real_T Add2_o5[50];                  /* '<S48>/Add2' */
  real_T g4_termref;                   /* '<S48>/g4_term,ref' */
  real_T Selector_m[50];               /* '<S42>/Selector' */
  real_T Selector1_a[50];              /* '<S42>/Selector1' */
  real_T g4ref;                        /* '<S42>/g4ref' */
  real_T Selector_o[49];               /* '<S47>/Selector' */
  real_T TmpSignalConversionAtg3_termref[50];
  real_T DataStoreRead1_bz;            /* '<S47>/Data Store Read1' */
  real_T DataStoreRead_h;              /* '<S47>/Data Store Read' */
  real_T Selector1_pz[50];             /* '<S47>/Selector1' */
  real_T Divide6_l[50];                /* '<S47>/Divide6' */
  real_T Add2_b[50];                   /* '<S47>/Add2' */
  real_T g3_termref;                   /* '<S47>/g3_term,ref' */
  real_T Selector_m0[50];              /* '<S41>/Selector' */
  real_T Selector1_h[50];              /* '<S41>/Selector1' */
  real_T g3ref;                        /* '<S41>/g3ref' */
  real_T Selector_fo[49];              /* '<S46>/Selector' */
  real_T TmpSignalConversionAtg2_termref[50];
  real_T DataStoreRead1_np;            /* '<S46>/Data Store Read1' */
  real_T DataStoreRead_jc;             /* '<S46>/Data Store Read' */
  real_T Selector1_cg[50];             /* '<S46>/Selector1' */
  real_T Divide6_le[50];               /* '<S46>/Divide6' */
  real_T Add2_ap[50];                  /* '<S46>/Add2' */
  real_T g2_termref;                   /* '<S46>/g2_term,ref' */
  real_T Selector_l[50];               /* '<S40>/Selector' */
  real_T Selector1_hw[50];             /* '<S40>/Selector1' */
  real_T g2ref;                        /* '<S40>/g2ref' */
  real_T DataStoreRead1_oj[500];       /* '<S39>/Data Store Read1' */
  real_T DataStoreRead_fa[500];        /* '<S39>/Data Store Read' */
  real_T I1;                           /* '<S39>/I1' */
  real_T DataStoreRead1_ah[500];       /* '<S38>/Data Store Read1' */
  real_T DataStoreRead_b[500];         /* '<S38>/Data Store Read' */
  real_T I1_o;                         /* '<S38>/I1' */
  real_T DataStoreRead1_hz[500];       /* '<S37>/Data Store Read1' */
  real_T DataStoreRead_k5[500];        /* '<S37>/Data Store Read' */
  real_T I1_b;                         /* '<S37>/I1' */
  real_T DataStoreRead1_ks[500];       /* '<S36>/Data Store Read1' */
  real_T DataStoreRead_lx[500];        /* '<S36>/Data Store Read' */
  real_T I1_c;                         /* '<S36>/I1' */
  real_T DataStoreRead1_fx[500];       /* '<S35>/Data Store Read1' */
  real_T DataStoreRead_dw[500];        /* '<S35>/Data Store Read' */
  real_T I1_j;                         /* '<S35>/I1' */
  real_T DataStoreRead1_lr[500];       /* '<S34>/Data Store Read1' */
  real_T DataStoreRead_il[500];        /* '<S34>/Data Store Read' */
  real_T I1_e;                         /* '<S34>/I1' */
  real_T DataStoreRead1_he[500];       /* '<S33>/Data Store Read1' */
  real_T DataStoreRead_n[500];         /* '<S33>/Data Store Read' */
  real_T I1_n;                         /* '<S33>/I1' */
  real_T DataStoreRead1_ao[500];       /* '<S32>/Data Store Read1' */
  real_T DataStoreRead_i0[500];        /* '<S32>/Data Store Read' */
  real_T I1_m;                         /* '<S32>/I1' */
  real_T DataStoreRead1_iw[500];       /* '<S31>/Data Store Read1' */
  real_T DataStoreRead_fq[500];        /* '<S31>/Data Store Read' */
  real_T I1_cj;                        /* '<S31>/I1' */
  real_T DataStoreRead1_ir[500];       /* '<S30>/Data Store Read1' */
  real_T DataStoreRead_jc4[500];       /* '<S30>/Data Store Read' */
  real_T I1_h;                         /* '<S30>/I1' */
  real_T DataStoreRead1_oq[500];       /* '<S29>/Data Store Read1' */
  real_T DataStoreRead_i4[500];        /* '<S29>/Data Store Read' */
  real_T I1_f;                         /* '<S29>/I1' */
  real_T DataStoreRead1_f2[500];       /* '<S19>/Data Store Read1' */
  real_T DataStoreRead_eq[500];        /* '<S19>/Data Store Read' */
  real_T Ipref;                        /* '<S19>/Ipref' */
  real_T Selector_j[50];               /* '<S21>/Selector' */
  real_T Selector1_i[50];              /* '<S21>/Selector1' */
  real_T elong;                        /* '<S21>/elong' */
  real_T Add2_l;                       /* '<S14>/Add2' */
  real_T DataStoreRead1_c;             /* '<S24>/Data Store Read1' */
  real_T Divide_e[4];                  /* '<S24>/Divide' */
  real_T Gain1;                        /* '<S4>/Gain1' */
  real_T Switch_f;                     /* '<S13>/Switch' */
  real_T Gain_g;                       /* '<S4>/Gain' */
  real_T Switch_d;                     /* '<S12>/Switch' */
  uint8_T Compare[11];                 /* '<S70>/Compare' */
  uint8_T Compare_m[11];               /* '<S71>/Compare' */
  boolean_T RelationalOperator_b;      /* '<S5>/Relational Operator' */
  boolean_T RelationalOperator1_d;     /* '<S5>/Relational Operator1' */
  boolean_T Compare_me;                /* '<S68>/Compare' */
  boolean_T RelationalOperator_k;      /* '<S69>/Relational Operator' */
  boolean_T RelationalOperator_cv;     /* '<S75>/Relational Operator' */
  boolean_T RelationalOperator_h;      /* '<S66>/Relational Operator' */
  boolean_T Compare_e;                 /* '<S85>/Compare' */
  boolean_T RelationalOperator1_l;     /* '<S58>/Relational Operator1' */
  boolean_T Compare_l;                 /* '<S77>/Compare' */
  boolean_T RelationalOperator_l;      /* '<S58>/Relational Operator' */
  boolean_T RelationalOperator1_dd;    /* '<S62>/Relational Operator1' */
  boolean_T Compare_ef;                /* '<S81>/Compare' */
  boolean_T RelationalOperator_a;      /* '<S73>/Relational Operator' */
  boolean_T Compare_k;                 /* '<S72>/Compare' */
  boolean_T LogicalOperator_d[11];     /* '<S53>/Logical Operator' */
  boolean_T Compare_p;                 /* '<S79>/Compare' */
  boolean_T Compare_b;                 /* '<S78>/Compare' */
  boolean_T LowerRelop1[11];           /* '<S10>/LowerRelop1' */
  boolean_T UpperRelop[11];            /* '<S10>/UpperRelop' */
  boolean_T LowerRelop1_m[11];         /* '<S11>/LowerRelop1' */
  boolean_T UpperRelop_o[11];          /* '<S11>/UpperRelop' */
  boolean_T LowerRelop1_a;             /* '<S12>/LowerRelop1' */
  boolean_T LowerRelop1_e;             /* '<S13>/LowerRelop1' */
  boolean_T LowerRelop1_d;             /* '<S56>/LowerRelop1' */
  boolean_T UpperRelop_j;              /* '<S56>/UpperRelop' */
  boolean_T LowerRelop1_p;             /* '<S80>/LowerRelop1' */
  boolean_T UpperRelop_j5;             /* '<S80>/UpperRelop' */
  boolean_T LowerRelop1_j;             /* '<S57>/LowerRelop1' */
  boolean_T UpperRelop_k;              /* '<S57>/UpperRelop' */
  boolean_T RelationalOperator_hy;     /* '<S76>/Relational Operator' */
  boolean_T LowerRelop1_ai;            /* '<S84>/LowerRelop1' */
  boolean_T UpperRelop_g;              /* '<S84>/UpperRelop' */
  boolean_T UpperRelop_oc;             /* '<S13>/UpperRelop' */
  boolean_T UpperRelop_a;              /* '<S12>/UpperRelop' */
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
  real_T UD_DSTATE_g;                  /* '<S83>/UD' */
  real_T VScontr_DSTATE[9];            /* '<S60>/VS. contr' */
  real_T VScontrhl_DSTATE[8];          /* '<S60>/VS. contr hl' */
  real_T UD_DSTATE_k;                  /* '<S6>/UD' */
  real_T Memory2_PreviousInput;        /* '<S5>/Memory2' */
  real_T Memory1_PreviousInput;        /* '<S18>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S26>/Memory' */
  real_T Memory1_PreviousInput_o;      /* '<S19>/Memory1' */
  real_T Memory2_PreviousInput_n;      /* '<S45>/Memory2' */
  real_T Memory1_PreviousInput_i;      /* '<S45>/Memory1' */
  real_T Memory2_PreviousInput_c;      /* '<S40>/Memory2' */
  real_T Memory1_PreviousInput_a;      /* '<S40>/Memory1' */
  real_T Memory2_PreviousInput_o;      /* '<S41>/Memory2' */
  real_T Memory1_PreviousInput_d;      /* '<S41>/Memory1' */
  real_T Memory2_PreviousInput_b;      /* '<S42>/Memory2' */
  real_T Memory1_PreviousInput_c;      /* '<S42>/Memory1' */
  real_T Memory2_PreviousInput_nf;     /* '<S43>/Memory2' */
  real_T Memory1_PreviousInput_e;      /* '<S43>/Memory1' */
  real_T Memory2_PreviousInput_l;      /* '<S44>/Memory2' */
  real_T Memory1_PreviousInput_et;     /* '<S44>/Memory1' */
  real_T Memory2_PreviousInput_ls;     /* '<S29>/Memory2' */
  real_T Memory2_PreviousInput_a;      /* '<S32>/Memory2' */
  real_T Memory2_PreviousInput_h;      /* '<S33>/Memory2' */
  real_T Memory2_PreviousInput_oz;     /* '<S34>/Memory2' */
  real_T Memory2_PreviousInput_lt;     /* '<S35>/Memory2' */
  real_T Memory2_PreviousInput_os;     /* '<S36>/Memory2' */
  real_T Memory2_PreviousInput_d;      /* '<S37>/Memory2' */
  real_T Memory2_PreviousInput_p;      /* '<S38>/Memory2' */
  real_T Memory2_PreviousInput_m;      /* '<S39>/Memory2' */
  real_T Memory2_PreviousInput_j;      /* '<S30>/Memory2' */
  real_T Memory2_PreviousInput_ce;     /* '<S31>/Memory2' */
  real_T Memory_PreviousInput_l;       /* '<S25>/Memory' */
  real_T Memory3_PreviousInput;        /* '<S52>/Memory3' */
  real_T Memory1_PreviousInput_n[11];  /* '<S52>/Memory1' */
  real_T Memory1_PreviousInput_f;      /* '<S64>/Memory1' */
  real_T Memory1_PreviousInput_g[11];  /* '<S66>/Memory1' */
  real_T Memory_PreviousInput_n[11];   /* '<S58>/Memory' */
  real_T Memory1_PreviousInput_d0;     /* '<S62>/Memory1' */
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
  real_T Memory1_PreviousInput_in[11]; /* '<S3>/Memory1' */
  real_T Memory1_PreviousInput_m;      /* '<S4>/Memory1' */
  real_T Memory2_PreviousInput_de;     /* '<S4>/Memory2' */
  real_T Memory1_PreviousInput_of[11]; /* '<S7>/Memory1' */
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
  real_T _Value_m;                     /* Expression: 1
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
  real_T _Value_l;                     /* Expression: 0
                                        * Referenced by: '<S15>/2'
                                        */
  real_T _Value_p;                     /* Expression: 0
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
  real_T _Value_a;                     /* Expression: 1
                                        * Referenced by: '<S15>/1'
                                        */
  real_T _Value_n;                     /* Expression: 1
                                        * Referenced by: '<S62>/1'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 1
                                        * Referenced by: '<S62>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: 0
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
  real_T e6_Gain_i;                    /* Expression: 1e-6
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
  real_T Constant4_Value_m;            /* Expression: 1
                                        * Referenced by: '<S18>/Constant4'
                                        */
  real_T u_UpperSat;                   /* Expression: 1
                                        * Referenced by: '<S18>/1 0'
                                        */
  real_T u_LowerSat;                   /* Expression: 0
                                        * Referenced by: '<S18>/1 0'
                                        */
  real_T Memory1_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S19>/Memory1'
                                        */
  real_T c_eob_Threshold_g;            /* Expression: 1
                                        * Referenced by: '<S19>/c_eob'
                                        */
  real_T SFunction1_P1_Size_f[2];      /* Computed Parameter: SFunction1_P1_Size_f
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  real_T SFunction1_P1_d;              /* Expression: 0
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  real_T Constant4_Value_c;            /* Expression: 0
                                        * Referenced by: '<S14>/Constant4'
                                        */
  real_T e2_Gain;                      /* Expression: 1e2
                                        * Referenced by: '<S23>/1e2'
                                        */
  real_T SFunction1_P1_Size_h[2];      /* Computed Parameter: SFunction1_P1_Size_h
                                        * Referenced by: '<S45>/S-Function1'
                                        */
  real_T SFunction1_P1_g;              /* Expression: 1
                                        * Referenced by: '<S45>/S-Function1'
                                        */
  real_T Memory2_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S45>/Memory2'
                                        */
  real_T c_eob1_Threshold;             /* Expression: 1
                                        * Referenced by: '<S45>/c_eob  1'
                                        */
  real_T Memory1_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S45>/Memory1'
                                        */
  real_T c_eob_Threshold_o;            /* Expression: 1
                                        * Referenced by: '<S45>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_p[2];      /* Computed Parameter: SFunction1_P1_Size_p
                                        * Referenced by: '<S51>/S-Function1'
                                        */
  real_T SFunction1_P1_j;              /* Expression: 1
                                        * Referenced by: '<S51>/S-Function1'
                                        */
  real_T c_eob_Threshold_k;            /* Expression: 1
                                        * Referenced by: '<S45>/c_eob'
                                        */
  real_T SFunction1_P1_Size_a[2];      /* Computed Parameter: SFunction1_P1_Size_a
                                        * Referenced by: '<S40>/S-Function1'
                                        */
  real_T SFunction1_P1_o;              /* Expression: 2
                                        * Referenced by: '<S40>/S-Function1'
                                        */
  real_T Memory2_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S40>/Memory2'
                                        */
  real_T c_eob1_Threshold_h;           /* Expression: 1
                                        * Referenced by: '<S40>/c_eob  1'
                                        */
  real_T Memory1_X0_cv;                /* Expression: 0
                                        * Referenced by: '<S40>/Memory1'
                                        */
  real_T c_eob_Threshold_c;            /* Expression: 1
                                        * Referenced by: '<S40>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_e[2];      /* Computed Parameter: SFunction1_P1_Size_e
                                        * Referenced by: '<S46>/S-Function1'
                                        */
  real_T SFunction1_P1_b;              /* Expression: 2
                                        * Referenced by: '<S46>/S-Function1'
                                        */
  real_T c_eob_Threshold_e;            /* Expression: 1
                                        * Referenced by: '<S40>/c_eob'
                                        */
  real_T SFunction1_P1_Size_i[2];      /* Computed Parameter: SFunction1_P1_Size_i
                                        * Referenced by: '<S41>/S-Function1'
                                        */
  real_T SFunction1_P1_d3;             /* Expression: 3
                                        * Referenced by: '<S41>/S-Function1'
                                        */
  real_T Memory2_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S41>/Memory2'
                                        */
  real_T c_eob1_Threshold_k;           /* Expression: 1
                                        * Referenced by: '<S41>/c_eob  1'
                                        */
  real_T Memory1_X0_l;                 /* Expression: 0
                                        * Referenced by: '<S41>/Memory1'
                                        */
  real_T c_eob_Threshold_l;            /* Expression: 1
                                        * Referenced by: '<S41>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_d[2];      /* Computed Parameter: SFunction1_P1_Size_d
                                        * Referenced by: '<S47>/S-Function1'
                                        */
  real_T SFunction1_P1_c;              /* Expression: 3
                                        * Referenced by: '<S47>/S-Function1'
                                        */
  real_T c_eob_Threshold_gl;           /* Expression: 1
                                        * Referenced by: '<S41>/c_eob'
                                        */
  real_T SFunction1_P1_Size_b[2];      /* Computed Parameter: SFunction1_P1_Size_b
                                        * Referenced by: '<S42>/S-Function1'
                                        */
  real_T SFunction1_P1_n;              /* Expression: 4
                                        * Referenced by: '<S42>/S-Function1'
                                        */
  real_T Memory2_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S42>/Memory2'
                                        */
  real_T c_eob1_Threshold_j;           /* Expression: 1
                                        * Referenced by: '<S42>/c_eob  1'
                                        */
  real_T Memory1_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S42>/Memory1'
                                        */
  real_T c_eob_Threshold_p;            /* Expression: 1
                                        * Referenced by: '<S42>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_dr[2];     /* Computed Parameter: SFunction1_P1_Size_dr
                                        * Referenced by: '<S48>/S-Function1'
                                        */
  real_T SFunction1_P1_g0;             /* Expression: 4
                                        * Referenced by: '<S48>/S-Function1'
                                        */
  real_T c_eob_Threshold_n;            /* Expression: 1
                                        * Referenced by: '<S42>/c_eob'
                                        */
  real_T SFunction1_P1_Size_if[2];     /* Computed Parameter: SFunction1_P1_Size_if
                                        * Referenced by: '<S43>/S-Function1'
                                        */
  real_T SFunction1_P1_i;              /* Expression: 5
                                        * Referenced by: '<S43>/S-Function1'
                                        */
  real_T Memory2_X0_mw;                /* Expression: 0
                                        * Referenced by: '<S43>/Memory2'
                                        */
  real_T c_eob1_Threshold_b;           /* Expression: 1
                                        * Referenced by: '<S43>/c_eob  1'
                                        */
  real_T Memory1_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S43>/Memory1'
                                        */
  real_T c_eob_Threshold_m;            /* Expression: 1
                                        * Referenced by: '<S43>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_k[2];      /* Computed Parameter: SFunction1_P1_Size_k
                                        * Referenced by: '<S49>/S-Function1'
                                        */
  real_T SFunction1_P1_l;              /* Expression: 5
                                        * Referenced by: '<S49>/S-Function1'
                                        */
  real_T c_eob_Threshold_j;            /* Expression: 1
                                        * Referenced by: '<S43>/c_eob'
                                        */
  real_T SFunction1_P1_Size_g[2];      /* Computed Parameter: SFunction1_P1_Size_g
                                        * Referenced by: '<S44>/S-Function1'
                                        */
  real_T SFunction1_P1_ce;             /* Expression: 6
                                        * Referenced by: '<S44>/S-Function1'
                                        */
  real_T Memory2_X0_i;                 /* Expression: 0
                                        * Referenced by: '<S44>/Memory2'
                                        */
  real_T c_eob1_Threshold_ki;          /* Expression: 1
                                        * Referenced by: '<S44>/c_eob  1'
                                        */
  real_T Memory1_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S44>/Memory1'
                                        */
  real_T c_eob_Threshold_f;            /* Expression: 1
                                        * Referenced by: '<S44>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_f2[2];     /* Computed Parameter: SFunction1_P1_Size_f2
                                        * Referenced by: '<S50>/S-Function1'
                                        */
  real_T SFunction1_P1_e;              /* Expression: 6
                                        * Referenced by: '<S50>/S-Function1'
                                        */
  real_T c_eob_Threshold_a;            /* Expression: 1
                                        * Referenced by: '<S44>/c_eob'
                                        */
  real_T e2_Gain_n;                    /* Expression: 1e-2
                                        * Referenced by: '<S23>/1e-2'
                                        */
  real_T Memory2_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S29>/Memory2'
                                        */
  real_T c_eob_Threshold_kc;           /* Expression: 1
                                        * Referenced by: '<S29>/c_eob'
                                        */
  real_T Memory2_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S32>/Memory2'
                                        */
  real_T c_eob_Threshold_n4;           /* Expression: 1
                                        * Referenced by: '<S32>/c_eob'
                                        */
  real_T Memory2_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S33>/Memory2'
                                        */
  real_T c_eob_Threshold_g0;           /* Expression: 1
                                        * Referenced by: '<S33>/c_eob'
                                        */
  real_T Memory2_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S34>/Memory2'
                                        */
  real_T c_eob_Threshold_h;            /* Expression: 1
                                        * Referenced by: '<S34>/c_eob'
                                        */
  real_T Memory2_X0_h2;                /* Expression: 0
                                        * Referenced by: '<S35>/Memory2'
                                        */
  real_T c_eob_Threshold_p2;           /* Expression: 1
                                        * Referenced by: '<S35>/c_eob'
                                        */
  real_T Memory2_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S36>/Memory2'
                                        */
  real_T c_eob_Threshold_js;           /* Expression: 1
                                        * Referenced by: '<S36>/c_eob'
                                        */
  real_T Memory2_X0_me;                /* Expression: 0
                                        * Referenced by: '<S37>/Memory2'
                                        */
  real_T c_eob_Threshold_aa;           /* Expression: 1
                                        * Referenced by: '<S37>/c_eob'
                                        */
  real_T Memory2_X0_e3;                /* Expression: 0
                                        * Referenced by: '<S38>/Memory2'
                                        */
  real_T c_eob_Threshold_kc2;          /* Expression: 1
                                        * Referenced by: '<S38>/c_eob'
                                        */
  real_T Memory2_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S39>/Memory2'
                                        */
  real_T c_eob_Threshold_kp;           /* Expression: 1
                                        * Referenced by: '<S39>/c_eob'
                                        */
  real_T Memory2_X0_om;                /* Expression: 0
                                        * Referenced by: '<S30>/Memory2'
                                        */
  real_T c_eob_Threshold_c4;           /* Expression: 1
                                        * Referenced by: '<S30>/c_eob'
                                        */
  real_T Memory2_X0_ia;                /* Expression: 0
                                        * Referenced by: '<S31>/Memory2'
                                        */
  real_T c_eob_Threshold_glo;          /* Expression: 1
                                        * Referenced by: '<S31>/c_eob'
                                        */
  real_T Memory_X0_c;                  /* Expression: 0
                                        * Referenced by: '<S25>/Memory'
                                        */
  real_T _Threshold;                   /* Expression: 1
                                        * Referenced by: '<S17>/1'
                                        */
  real_T UD_InitialCondition;          /* Expression: ICPrevInput
                                        * Referenced by: '<S27>/UD'
                                        */
  real_T UD_InitialCondition_p;        /* Expression: ICPrevInput
                                        * Referenced by: '<S28>/UD'
                                        */
  real_T u15_Gain_g;                   /* Expression: 1/15
                                        * Referenced by: '<S15>/ 1//15'
                                        */
  real_T _Value_o;                     /* Expression: 1
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
  real_T Saturation1_LowerSat_f;       /* Expression: 0
                                        * Referenced by: '<S52>/Saturation1'
                                        */
  real_T Memory1_X0_mj;                /* Expression: 0
                                        * Referenced by: '<S52>/Memory1'
                                        */
  real_T Memory1_X0_l4;                /* Expression: 0
                                        * Referenced by: '<S64>/Memory1'
                                        */
  real_T c_eob_Threshold_ao;           /* Expression: 1
                                        * Referenced by: '<S64>/c_eob'
                                        */
  real_T c_eob_Threshold_h4;           /* Expression: 1
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
  real_T switch1_Threshold_l;          /* Expression: 1
                                        * Referenced by: '<S52>/switch1'
                                        */
  real_T _Value_i;                     /* Expression: 1
                                        * Referenced by: '<S15>/1 '
                                        */
  real_T _Value_ij;                    /* Expression: 1
                                        * Referenced by: '<S53>/1'
                                        */
  real_T e3_Gain_j;                    /* Expression: 1e3
                                        * Referenced by: '<S53>/1e3'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: 1
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T Saturation_LowerSat_hx;       /* Expression: -1
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T Constant_Value_h;             /* Expression: const
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T Memory1_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S66>/Memory1'
                                        */
  real_T Constant_Value_n;             /* Expression: const
                                        * Referenced by: '<S85>/Constant'
                                        */
  real_T Memory_X0_m;                  /* Expression: 0
                                        * Referenced by: '<S58>/Memory'
                                        */
  real_T Constant_Value_a;             /* Expression: const
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
  real_T Memory1_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S62>/Memory1'
                                        */
  real_T Constant_Value_o;             /* Expression: const
                                        * Referenced by: '<S81>/Constant'
                                        */
  real_T switch1_Threshold_g;          /* Expression: 1
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
  real_T _Threshold_h;                 /* Expression: 1
                                        * Referenced by: '<S66>/1'
                                        */
  real_T Constant_Value_m;             /* Expression: const
                                        * Referenced by: '<S72>/Constant'
                                        */
  real_T _Value_k;                     /* Expression: 1
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
  real_T u01_Gain_j;                   /* Expression: 1e-3
                                        * Referenced by: '<S89>/0.001'
                                        */
  real_T u01_Gain_jv;                  /* Expression: 1e-3
                                        * Referenced by: '<S90>/0.001'
                                        */
  real_T u01_Gain_i;                   /* Expression: 1e-3
                                        * Referenced by: '<S91>/0.001'
                                        */
  real_T u01_Gain_l;                   /* Expression: 1e-3
                                        * Referenced by: '<S92>/0.001'
                                        */
  real_T u01_Gain_li;                  /* Expression: 1e-3
                                        * Referenced by: '<S93>/0.001'
                                        */
  real_T u01_Gain_d;                   /* Expression: 1e-3
                                        * Referenced by: '<S94>/0.001'
                                        */
  real_T u01_Gain_jx;                  /* Expression: 1e-3
                                        * Referenced by: '<S95>/0.001'
                                        */
  real_T u01_Gain_ix;                  /* Expression: 1e-3
                                        * Referenced by: '<S96>/0.001'
                                        */
  real_T u01_Gain_a;                   /* Expression: 1e-3
                                        * Referenced by: '<S87>/0.001'
                                        */
  real_T u01_Gain_k;                   /* Expression: 1e-3
                                        * Referenced by: '<S88>/0.001'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
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
  real_T UD_InitialCondition_k;        /* Expression: ICPrevInput
                                        * Referenced by: '<S83>/UD'
                                        */
  real_T e3_Gain_o;                    /* Expression: 2e3
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
  real_T Constant_Value_l;             /* Expression: const
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
  real_T c_eob_Threshold_ln;           /* Expression: 1
                                        * Referenced by: '<S60>/c_eob'
                                        */
  real_T Constant_Value_k;             /* Expression: const
                                        * Referenced by: '<S78>/Constant'
                                        */
  real_T u5_Gain_l;                    /* Expression: 1/15
                                        * Referenced by: '<S61>/1//15'
                                        */
  real_T _Threshold_hz;                /* Expression: 1
                                        * Referenced by: '<S59>/1'
                                        */
  real_T G_curr_term_Gain[220];        /* Expression: [zeros(8,11); eye(11); zeros(1,11)]
                                        * Referenced by: '<S15>/G_curr_term'
                                        */
  real_T e6_Gain_e;                    /* Expression: 1e6
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
  real_T Memory1_X0_d;                 /* Expression: 0
                                        * Referenced by: '<S3>/Memory1'
                                        */
  real_T wz1_Value[11];                /* Expression: [0 0 0 0 0 0 -1 -1 1 1 0]'
                                        * Referenced by: '<S2>/wz1'
                                        */
  real_T Memory1_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory1'
                                        */
  real_T wz2_Value;                    /* Expression: 1
                                        * Referenced by: '<S2>/wz2'
                                        */
  real_T Memory2_X0_l;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T npf12_Gain[180];              /* Expression: eye(15,11+1)
                                        * Referenced by: '<S2>/npf,12'
                                        */
  real_T UD_InitialCondition_pn;       /* Expression: ICPrevInput
                                        * Referenced by: '<S6>/UD'
                                        */
  real_T Memory1_X0_i;                 /* Expression: 0
                                        * Referenced by: '<S7>/Memory1'
                                        */
  real_T _Gain;                        /* Expression: 2
                                        * Referenced by: '<S8>/2'
                                        */
  real_T u_Gain_d;                     /* Expression: -1
                                        * Referenced by: '<S8>/-1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T DataStoreMemory1_InitialValue_c[12];/* Expression: [554,554,554,554,554  248.6 115.2 185.9 169.9 216.8  459.4 1]
                                              * Referenced by: '<S1>/Data Store Memory1'
                                              */
  real_T DataStoreMemory2_InitialValue_c[6];/* Expression: [1; ones(5,1)*1e-6]
                                             * Referenced by: '<S1>/Data Store Memory2'
                                             */
  real_T DataStoreMemory3_InitialValue_h;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory3'
                                          */
  real_T DataStoreMemory4_InitialValue_l[11];/* Expression: zeros(11,1)
                                              * Referenced by: '<S1>/Data Store Memory4'
                                              */
  real_T DataStoreMemory5_InitialValue_o;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory5'
                                          */
  real_T DataStoreMemory7_InitialValue_b;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory7'
                                          */
  real_T DataStoreMemory8_InitialValue_f;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory8'
                                          */
  real_T DataStoreMemory9_InitialValue_h[11];/* Expression: ones(1,11)*1e6
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
