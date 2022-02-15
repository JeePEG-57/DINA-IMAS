/*
 * File: t15_2.h
 *
 * Code generated for Simulink model 't15_2'.
 *
 * Model version                  : 1.1161
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Fri Jan 14 08:20:53 2022
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
  real_T DataStoreRead1_e;             /* '<S18>/Data Store Read1' */
  real_T e3;                           /* '<S18>/1e-3' */
  real_T DataStoreRead2;               /* '<S18>/Data Store Read2' */
  real_T Product1;                     /* '<S18>/Product1' */
  real_T RelationalOperator;           /* '<S18>/Relational Operator' */
  real_T Memory;                       /* '<S28>/Memory' */
  real_T LogicalOperator;              /* '<S28>/Logical Operator' */
  real_T switch1;                      /* '<S18>/switch1' */
  real_T Add2;                         /* '<S18>/Add2' */
  real_T DataStoreRead_f;              /* '<S18>/Data Store Read' */
  real_T Product;                      /* '<S18>/Product' */
  real_T Add1;                         /* '<S18>/Add1' */
  real_T u_e;                          /* '<S18>/1 0' */
  real_T Memory1_i;                    /* '<S19>/Memory1' */
  real_T c_eob;                        /* '<S19>/c_eob' */
  real_T Divide6;                      /* '<S19>/Divide6' */
  real_T Add1_d;                       /* '<S14>/Add1' */
  real_T SFunction1_o[100];            /* '<S21>/S-Function1' */
  real_T DataStoreRead1_f;             /* '<S17>/Data Store Read1' */
  real_T RelationalOperator_e;         /* '<S17>/Relational Operator' */
  real_T Memory_b;                     /* '<S27>/Memory' */
  real_T LogicalOperator_f;            /* '<S27>/Logical Operator' */
  real_T e2[6];                        /* '<S23>/1e2' */
  real_T SFunction1_f[100];            /* '<S47>/S-Function1' */
  real_T Memory2_b;                    /* '<S47>/Memory2' */
  real_T c_eob1;                       /* '<S47>/c_eob  1' */
  real_T Memory1_b;                    /* '<S47>/Memory1' */
  real_T c_eob_c;                      /* '<S47>/c_eob  ' */
  real_T SFunction1_j[100];            /* '<S53>/S-Function1' */
  real_T c_eob_o;                      /* '<S47>/c_eob' */
  real_T Add2_h;                       /* '<S23>/Add2' */
  real_T SFunction1_c[100];            /* '<S42>/S-Function1' */
  real_T Memory2_l;                    /* '<S42>/Memory2' */
  real_T c_eob1_d;                     /* '<S42>/c_eob  1' */
  real_T Memory1_o;                    /* '<S42>/Memory1' */
  real_T c_eob_m;                      /* '<S42>/c_eob  ' */
  real_T SFunction1_g[100];            /* '<S48>/S-Function1' */
  real_T c_eob_oh;                     /* '<S42>/c_eob' */
  real_T Add1_c;                       /* '<S23>/Add1' */
  real_T SFunction1_of[100];           /* '<S43>/S-Function1' */
  real_T Memory2_o;                    /* '<S43>/Memory2' */
  real_T c_eob1_j;                     /* '<S43>/c_eob  1' */
  real_T Memory1_e;                    /* '<S43>/Memory1' */
  real_T c_eob_n;                      /* '<S43>/c_eob  ' */
  real_T SFunction1_oy[100];           /* '<S49>/S-Function1' */
  real_T c_eob_o3;                     /* '<S43>/c_eob' */
  real_T Add3;                         /* '<S23>/Add3' */
  real_T SFunction1_e[100];            /* '<S44>/S-Function1' */
  real_T Memory2_i;                    /* '<S44>/Memory2' */
  real_T c_eob1_m;                     /* '<S44>/c_eob  1' */
  real_T Memory1_j;                    /* '<S44>/Memory1' */
  real_T c_eob_g;                      /* '<S44>/c_eob  ' */
  real_T SFunction1_fg[100];           /* '<S50>/S-Function1' */
  real_T c_eob_a;                      /* '<S44>/c_eob' */
  real_T Add4;                         /* '<S23>/Add4' */
  real_T DataStoreRead_b;              /* '<S23>/Data Store Read' */
  real_T RelationalOperator1;          /* '<S23>/Relational Operator1' */
  real_T Divide12;                     /* '<S23>/Divide12' */
  real_T SFunction1_n[100];            /* '<S45>/S-Function1' */
  real_T Memory2_g;                    /* '<S45>/Memory2' */
  real_T c_eob1_h;                     /* '<S45>/c_eob  1' */
  real_T Memory1_oq;                   /* '<S45>/Memory1' */
  real_T c_eob_p;                      /* '<S45>/c_eob  ' */
  real_T SFunction1_d[100];            /* '<S51>/S-Function1' */
  real_T c_eob_f;                      /* '<S45>/c_eob' */
  real_T Add5;                         /* '<S23>/Add5' */
  real_T SFunction1_h[100];            /* '<S46>/S-Function1' */
  real_T Memory2_j;                    /* '<S46>/Memory2' */
  real_T c_eob1_g;                     /* '<S46>/c_eob  1' */
  real_T Memory1_p;                    /* '<S46>/Memory1' */
  real_T c_eob_i;                      /* '<S46>/c_eob  ' */
  real_T SFunction1_a[100];            /* '<S52>/S-Function1' */
  real_T c_eob_e;                      /* '<S46>/c_eob' */
  real_T Add6;                         /* '<S23>/Add6' */
  real_T e2_h[6];                      /* '<S23>/1e-2' */
  real_T Memory2_d;                    /* '<S31>/Memory2' */
  real_T c_eob_fn;                     /* '<S31>/c_eob' */
  real_T Divide1;                      /* '<S31>/Divide1' */
  real_T Add3_e;                       /* '<S22>/Add3' */
  real_T Memory2_m;                    /* '<S34>/Memory2' */
  real_T c_eob_l;                      /* '<S34>/c_eob' */
  real_T Divide1_b;                    /* '<S34>/Divide1' */
  real_T Add1_ce;                      /* '<S22>/Add1' */
  real_T Memory2_c;                    /* '<S35>/Memory2' */
  real_T c_eob_j;                      /* '<S35>/c_eob' */
  real_T Divide1_j;                    /* '<S35>/Divide1' */
  real_T Add2_p;                       /* '<S22>/Add2' */
  real_T Memory2_a;                    /* '<S36>/Memory2' */
  real_T c_eob_gf;                     /* '<S36>/c_eob' */
  real_T Divide1_m;                    /* '<S36>/Divide1' */
  real_T Add4_k;                       /* '<S22>/Add4' */
  real_T Memory2_gs;                   /* '<S37>/Memory2' */
  real_T c_eob_k;                      /* '<S37>/c_eob' */
  real_T Divide1_k;                    /* '<S37>/Divide1' */
  real_T Add5_f;                       /* '<S22>/Add5' */
  real_T Memory2_p;                    /* '<S38>/Memory2' */
  real_T c_eob_ib;                     /* '<S38>/c_eob' */
  real_T Divide1_br;                   /* '<S38>/Divide1' */
  real_T Add6_p;                       /* '<S22>/Add6' */
  real_T Memory2_dz;                   /* '<S39>/Memory2' */
  real_T c_eob_l4;                     /* '<S39>/c_eob' */
  real_T Divide1_o;                    /* '<S39>/Divide1' */
  real_T Add7;                         /* '<S22>/Add7' */
  real_T Memory2_e;                    /* '<S40>/Memory2' */
  real_T c_eob_h;                      /* '<S40>/c_eob' */
  real_T Divide1_a;                    /* '<S40>/Divide1' */
  real_T Add8;                         /* '<S22>/Add8' */
  real_T Memory2_ii;                   /* '<S41>/Memory2' */
  real_T c_eob_cs;                     /* '<S41>/c_eob' */
  real_T Divide1_h;                    /* '<S41>/Divide1' */
  real_T Add9;                         /* '<S22>/Add9' */
  real_T Memory2_dg;                   /* '<S32>/Memory2' */
  real_T c_eob_jo;                     /* '<S32>/c_eob' */
  real_T Divide1_p;                    /* '<S32>/Divide1' */
  real_T Add10;                        /* '<S22>/Add10' */
  real_T Memory2_n;                    /* '<S33>/Memory2' */
  real_T c_eob_g4;                     /* '<S33>/c_eob' */
  real_T Divide1_c;                    /* '<S33>/Divide1' */
  real_T Add11;                        /* '<S22>/Add11' */
  real_T u_c[20];                      /* '<S17>/1' */
  real_T Uk1;                          /* '<S29>/UD' */
  real_T Diff;                         /* '<S29>/Diff' */
  real_T Uk1_p;                        /* '<S30>/UD' */
  real_T Diff_i;                       /* '<S30>/Diff' */
  real_T Divide;                       /* '<S20>/Divide' */
  real_T DataStoreRead_i;              /* '<S54>/Data Store Read' */
  real_T DataStoreRead1_fr;            /* '<S54>/Data Store Read1' */
  real_T Memory3;                      /* '<S54>/Memory3' */
  real_T RelationalOperator1_h;        /* '<S54>/Relational Operator1' */
  real_T switch1_i;                    /* '<S54>/switch1 ' */
  real_T Subtract2;                    /* '<S54>/Subtract2' */
  real_T Divide1_av;                   /* '<S54>/Divide1' */
  real_T Subtract1;                    /* '<S54>/Subtract1' */
  real_T Saturation1;                  /* '<S54>/Saturation1' */
  real_T e3_h[11];                     /* '<S55>/1e3' */
  real_T Abs[11];                      /* '<S55>/Abs' */
  real_T DataStoreRead1_n[11];         /* '<S15>/Data Store Read1' */
  real_T DataStoreRead2_a[11];         /* '<S55>/Data Store Read2' */
  real_T Divide5[11];                  /* '<S55>/Divide5' */
  real_T Sum2_a[11];                   /* '<S55>/Sum2' */
  real_T DataStoreRead1_a;             /* '<S55>/Data Store Read1' */
  real_T Divide3[11];                  /* '<S55>/Divide3' */
  real_T Sum1[11];                     /* '<S55>/Sum1' */
  real_T Divide4[11];                  /* '<S55>/Divide4' */
  real_T Divide1_mp[11];               /* '<S55>/Divide1' */
  real_T Saturation[11];               /* '<S55>/Saturation' */
  real_T Memory1_g[11];                /* '<S68>/Memory1' */
  real_T DataStoreRead_l;              /* '<S68>/Data Store Read' */
  real_T Abs_p;                        /* '<S68>/Abs' */
  real_T LogicalOperator2;             /* '<S68>/Logical Operator2' */
  real_T Memory_m;                     /* '<S90>/Memory' */
  real_T LogicalOperator_i;            /* '<S90>/Logical Operator' */
  real_T Memory_c[11];                 /* '<S60>/Memory' */
  real_T DataStoreRead_ii;             /* '<S60>/Data Store Read' */
  real_T DataStoreRead1_b;             /* '<S60>/Data Store Read1' */
  real_T Abs_m;                        /* '<S60>/Abs' */
  real_T LogicalOperator1;             /* '<S60>/Logical Operator1' */
  real_T Memory_k;                     /* '<S79>/Memory' */
  real_T LogicalOperator_h;            /* '<S79>/Logical Operator' */
  real_T Memory1_k;                    /* '<S66>/Memory1' */
  real_T c_eob_d;                      /* '<S66>/c_eob' */
  real_T c_eob_e2;                     /* '<S15>/c_eob' */
  real_T Divide2[20];                  /* '<S15>/Divide2' */
  real_T Divcontr[11];                 /* '<S15>/Div. contr.' */
  real_T u_h[11];                      /* '<S60>/1' */
  real_T Memory1_h;                    /* '<S64>/Memory1' */
  real_T DataStoreRead_k;              /* '<S64>/Data Store Read' */
  real_T LogicalOperator1_l;           /* '<S64>/Logical Operator1' */
  real_T Memory_d;                     /* '<S85>/Memory' */
  real_T LogicalOperator_b;            /* '<S85>/Logical Operator' */
  real_T switch1_j;                    /* '<S64>/switch1' */
  real_T Divide13[20];                 /* '<S15>/Divide13' */
  real_T Div_rdcontr[11];              /* '<S15>/Div_rd contr' */
  real_T u_f[11];                      /* '<S68>/1' */
  real_T DataStoreRead_p;              /* '<S56>/Data Store Read' */
  real_T Memory1_hd;                   /* '<S56>/Memory1' */
  real_T DataStoreRead_k2;             /* '<S73>/Data Store Read' */
  real_T Abs_f;                        /* '<S73>/Abs' */
  real_T LogicalOperator2_d;           /* '<S56>/Logical Operator2' */
  real_T Memory_mo;                    /* '<S74>/Memory' */
  real_T LogicalOperator_l;            /* '<S74>/Logical Operator' */
  real_T u_b;                          /* '<S56>/1 ' */
  real_T Subtract2_g;                  /* '<S56>/Subtract2' */
  real_T Divide4_d;                    /* '<S56>/Divide4' */
  real_T Subtract3;                    /* '<S56>/Subtract3' */
  real_T Saturation_k;                 /* '<S56>/Saturation' */
  real_T Divide4_i[11];                /* '<S15>/Divide4' */
  real_T Currtermcontr[11];            /* '<S15>/Curr. term. contr' */
  real_T Subtract1_m;                  /* '<S56>/Subtract1' */
  real_T Divide5_k[11];                /* '<S15>/Divide5' */
  real_T Memory2_g5[11];               /* '<S77>/Memory2' */
  real_T DataStoreRead1_p;             /* '<S77>/Data Store Read1' */
  real_T RelationalOperator1_p;        /* '<S77>/Relational Operator1' */
  real_T DataStoreRead_a;              /* '<S76>/Data Store Read' */
  real_T RelationalOperator_p;         /* '<S76>/Relational Operator' */
  real_T Divide12_g[20];               /* '<S76>/Divide12' */
  real_T Limcontr[11];                 /* '<S57>/Lim. contr.' */
  real_T Currcontr[11];                /* '<S57>/Curr. contr.' */
  real_T DataStoreRead2_g[11];         /* '<S57>/Data Store Read2' */
  real_T u_o[11];                      /* '<S77>/ 1 ' */
  real_T Divide14[11];                 /* '<S15>/Divide14' */
  real_T DataStoreRead_lx[500];        /* '<S91>/Data Store Read' */
  real_T u01[500];                     /* '<S91>/0.001' */
  real_T DataStoreRead1_g[500];        /* '<S91>/Data Store Read1' */
  real_T volt1;                        /* '<S91>/volt1' */
  real_T DataStoreRead_h[500];         /* '<S94>/Data Store Read' */
  real_T u01_p[500];                   /* '<S94>/0.001' */
  real_T DataStoreRead1_m[500];        /* '<S94>/Data Store Read1' */
  real_T volt1_m;                      /* '<S94>/volt1' */
  real_T DataStoreRead_it[500];        /* '<S95>/Data Store Read' */
  real_T u01_d[500];                   /* '<S95>/0.001' */
  real_T DataStoreRead1_k[500];        /* '<S95>/Data Store Read1' */
  real_T volt1_o;                      /* '<S95>/volt1' */
  real_T DataStoreRead_i0[500];        /* '<S96>/Data Store Read' */
  real_T u01_k[500];                   /* '<S96>/0.001' */
  real_T DataStoreRead1_c[500];        /* '<S96>/Data Store Read1' */
  real_T volt1_d;                      /* '<S96>/volt1' */
  real_T DataStoreRead_e[500];         /* '<S97>/Data Store Read' */
  real_T u01_e[500];                   /* '<S97>/0.001' */
  real_T DataStoreRead1_o[500];        /* '<S97>/Data Store Read1' */
  real_T volt1_j;                      /* '<S97>/volt1' */
  real_T DataStoreRead_c[500];         /* '<S98>/Data Store Read' */
  real_T u01_f[500];                   /* '<S98>/0.001' */
  real_T DataStoreRead1_nc[500];       /* '<S98>/Data Store Read1' */
  real_T volt1_b;                      /* '<S98>/volt1' */
  real_T DataStoreRead_o[500];         /* '<S99>/Data Store Read' */
  real_T u01_k4[500];                  /* '<S99>/0.001' */
  real_T DataStoreRead1_mq[500];       /* '<S99>/Data Store Read1' */
  real_T volt1_p;                      /* '<S99>/volt1' */
  real_T DataStoreRead_ai[500];        /* '<S100>/Data Store Read' */
  real_T u01_j[500];                   /* '<S100>/0.001' */
  real_T DataStoreRead1_b3[500];       /* '<S100>/Data Store Read1' */
  real_T volt1_du;                     /* '<S100>/volt1' */
  real_T DataStoreRead_ee[500];        /* '<S101>/Data Store Read' */
  real_T u01_m[500];                   /* '<S101>/0.001' */
  real_T DataStoreRead1_a1[500];       /* '<S101>/Data Store Read1' */
  real_T volt1_bc;                     /* '<S101>/volt1' */
  real_T DataStoreRead_hr[500];        /* '<S92>/Data Store Read' */
  real_T u01_fe[500];                  /* '<S92>/0.001' */
  real_T DataStoreRead1_ky[500];       /* '<S92>/Data Store Read1' */
  real_T volt1_pz;                     /* '<S92>/volt1' */
  real_T DataStoreRead_av[500];        /* '<S93>/Data Store Read' */
  real_T u01_h[500];                   /* '<S93>/0.001' */
  real_T DataStoreRead1_ab[500];       /* '<S93>/Data Store Read1' */
  real_T volt1_c;                      /* '<S93>/volt1' */
  real_T Subtract4;                    /* '<S56>/Subtract4' */
  real_T Divide7[11];                  /* '<S15>/Divide7' */
  real_T Sum3[11];                     /* '<S15>/Sum3' */
  real_T Divide2_a[11];                /* '<S55>/Divide2' */
  real_T LogicalOperator_ie[11];       /* '<S55>/Logical Operator' */
  real_T Switch[11];                   /* '<S55>/Switch' */
  real_T Divide6_l[11];                /* '<S55>/Divide6' */
  real_T UniformRandomNumber;          /* '<S65>/Uniform Random Number' */
  real_T DataStoreRead_ie;             /* '<S86>/Data Store Read' */
  real_T u5;                           /* '<S86>/1.75' */
  real_T Divide11;                     /* '<S86>/Divide11' */
  real_T Uk1_g;                        /* '<S87>/UD' */
  real_T Diff_p;                       /* '<S87>/Diff' */
  real_T e3_n;                         /* '<S86>/2e3' */
  real_T Sqrt;                         /* '<S86>/Sqrt' */
  real_T Divide1_f;                    /* '<S86>/Divide1' */
  real_T Sum2_j;                       /* '<S65>/Sum2' */
  real_T DataStoreRead_ea;             /* '<S67>/Data Store Read' */
  real_T RelationalOperator1_a;        /* '<S67>/Relational Operator1' */
  real_T Divide12_g2[2];               /* '<S67>/Divide12' */
  real_T VScontr[2];                   /* '<S62>/VS. contr' */
  real_T Divide4_a[2];                 /* '<S62>/Divide4' */
  real_T VScontrhl[2];                 /* '<S62>/VS. contr hl' */
  real_T c_eob_b[2];                   /* '<S62>/c_eob' */
  real_T DataStoreRead1_d;             /* '<S61>/Data Store Read1' */
  real_T RelationalOperator2;          /* '<S61>/Relational Operator2' */
  real_T DataStoreRead_op;             /* '<S61>/Data Store Read' */
  real_T Abs_g;                        /* '<S61>/Abs' */
  real_T RelationalOperator1_b;        /* '<S61>/Relational Operator1' */
  real_T LogicalOperator1_p;           /* '<S61>/Logical Operator1' */
  real_T Memory_p;                     /* '<S81>/Memory' */
  real_T LogicalOperator_h3;           /* '<S81>/Logical Operator' */
  real_T DataStoreRead_a4;             /* '<S63>/Data Store Read' */
  real_T u5_j;                         /* '<S63>/1//15' */
  real_T Div;                          /* '<S63>/Div' */
  real_T u_i[2];                       /* '<S61>/1' */
  real_T Divide10[2];                  /* '<S15>/Divide10' */
  real_T G_curr_term[20];              /* '<S15>/G_curr_term' */
  real_T Divide12_b[20];               /* '<S15>/Divide12' */
  real_T Divide1_m4[11];               /* '<S57>/Divide1' */
  real_T e6_ed[11];                    /* '<S57>/1e6' */
  real_T DataStoreRead2_o[11];         /* '<S5>/Data Store Read2' */
  real_T Divide4_b[11];                /* '<S5>/Divide4' */
  real_T SFunction_n[44];              /* '<S1>/S-Function' */
  real_T DataStoreRead1_nw[11];        /* '<S9>/Data Store Read1' */
  real_T Memory1_bt[11];               /* '<S7>/Memory1' */
  real_T DataStoreRead1_h[11];         /* '<S8>/Data Store Read1' */
  real_T u_hn[11];                     /* '<S8>/2' */
  real_T DataStoreRead3;               /* '<S8>/Data Store Read3' */
  real_T Divide1_ht[11];               /* '<S8>/Divide1' */
  real_T Add1_a[11];                   /* '<S7>/Add1' */
  real_T Uk1_l;                        /* '<S6>/UD' */
  real_T Diff_a;                       /* '<S6>/Diff' */
  real_T Divide_c[11];                 /* '<S7>/Divide' */
  real_T u_f0[11];                     /* '<S8>/-1' */
  real_T Switch_l[11];                 /* '<S10>/Switch' */
  real_T Switch2[11];                  /* '<S10>/Switch2' */
  real_T Divide1_ja[11];               /* '<S7>/Divide1' */
  real_T Add2_a[11];                   /* '<S7>/Add2' */
  real_T Gain[11];                     /* '<S9>/Gain' */
  real_T Switch_b[11];                 /* '<S11>/Switch' */
  real_T Switch2_c[11];                /* '<S11>/Switch2' */
  real_T DataStoreRead2_oo[11];        /* '<S2>/Data Store Read2' */
  real_T Divide3_f[11];                /* '<S2>/Divide3' */
  real_T Divide1_fq[11];               /* '<S2>/Divide1' */
  real_T DataStoreRead1_mv;            /* '<S4>/Data Store Read1' */
  real_T Switch2_l;                    /* '<S12>/Switch2' */
  real_T Divide2_n[11];                /* '<S2>/Divide2' */
  real_T Add1_l[11];                   /* '<S2>/Add1' */
  real_T DataStoreRead1_f0;            /* '<S2>/Data Store Read1' */
  real_T Divide4_ah;                   /* '<S2>/Divide4' */
  real_T DataStoreRead3_g;             /* '<S4>/Data Store Read3' */
  real_T Switch2_p;                    /* '<S13>/Switch2' */
  real_T Divide5_f;                    /* '<S2>/Divide5' */
  real_T TmpSignalConversionAtnpf12Inpor[12];
  real_T npf12[15];                    /* '<S2>/npf,12' */
  real_T Subtract2_l;                  /* '<S64>/Subtract2' */
  real_T DataStoreRead1_az;            /* '<S64>/Data Store Read1' */
  real_T Divide4_o;                    /* '<S64>/Divide4' */
  real_T Subtract3_f;                  /* '<S64>/Subtract3' */
  real_T Saturation_m;                 /* '<S64>/Saturation' */
  real_T Subtract1_mr;                 /* '<S64>/Subtract1' */
  real_T Divide3_d[11];                /* '<S15>/Divide3' */
  real_T Divide1_fj[11];               /* '<S15>/Divide1' */
  real_T Sum2_b[11];                   /* '<S15>/Sum2' */
  real_T DataStoreRead_ok;             /* '<S15>/Data Store Read' */
  real_T u15;                          /* '<S15>/ 1//15' */
  real_T Divide6_k;                    /* '<S15>/Divide6' */
  real_T Switch2_h;                    /* '<S58>/Switch2' */
  real_T Divide11_a[2];                /* '<S15>/Divide11' */
  real_T DataStoreRead3_l;             /* '<S15>/Data Store Read3' */
  real_T Switch_i;                     /* '<S58>/Switch' */
  real_T c_eob_am[2];                  /* '<S15>/c_eob ' */
  real_T DataStoreRead1_l;             /* '<S63>/Data Store Read1' */
  real_T RelationalOperator2_l;        /* '<S63>/Relational Operator2' */
  real_T LimDivtr;                     /* '<S63>/Lim. Div. tr.' */
  real_T Divide8[2];                   /* '<S15>/Divide8' */
  real_T SatDiv;                       /* '<S63>/Sat. Div' */
  real_T DataStoreRead2_h;             /* '<S63>/Data Store Read2' */
  real_T Switch2_a;                    /* '<S83>/Switch2' */
  real_T Switch_d;                     /* '<S83>/Switch' */
  real_T u5_m;                         /* '<S15>/1//15' */
  real_T Switch2_e;                    /* '<S59>/Switch2' */
  real_T Divide_k[2];                  /* '<S15>/Divide ' */
  real_T DataStoreRead4;               /* '<S15>/Data Store Read4' */
  real_T Switch_lv;                    /* '<S59>/Switch' */
  real_T Subtract3_b;                  /* '<S54>/Subtract3' */
  real_T Divide_o[11];                 /* '<S15>/Divide' */
  real_T DataStoreRead_lj;             /* '<S77>/Data Store Read' */
  real_T RelationalOperator_et;        /* '<S77>/Relational Operator' */
  real_T u_p[11];                      /* '<S77>/1' */
  real_T DataStoreRead1_f3;            /* '<S75>/Data Store Read1' */
  real_T DataStoreRead_d;              /* '<S75>/Data Store Read' */
  real_T Subtract3_j;                  /* '<S75>/Subtract3' */
  real_T Divide2_l;                    /* '<S75>/Divide2' */
  real_T Saturation1_o;                /* '<S75>/Saturation1' */
  real_T Divide_m[11];                 /* '<S57>/Divide ' */
  real_T Divide2_n0[11];               /* '<S57>/Divide2' */
  real_T DataStoreRead2_b;             /* '<S15>/Data Store Read2' */
  real_T u15_i;                        /* '<S15>/ 1//15 ' */
  real_T Divide9;                      /* '<S15>/Divide9' */
  real_T Saturation_mu;                /* '<S15>/Saturation' */
  real_T DataStoreRead2_l;             /* '<S66>/Data Store Read2' */
  real_T Sum3_h;                       /* '<S66>/Sum3' */
  real_T DataStoreRead4_o;             /* '<S66>/Data Store Read4' */
  real_T DataStoreRead3_f;             /* '<S66>/Data Store Read3' */
  real_T Sum2_l;                       /* '<S66>/Sum2' */
  real_T Divide1_d;                    /* '<S66>/Divide1' */
  real_T Divide6_a;                    /* '<S66>/Divide6' */
  real_T Sum;                          /* '<S66>/Sum' */
  real_T Divide2_d;                    /* '<S66>/Divide2' */
  real_T Sum1_c;                       /* '<S66>/Sum1' */
  real_T Switch2_o;                    /* '<S88>/Switch2' */
  real_T Switch_lx;                    /* '<S88>/Switch' */
  real_T Selector[49];                 /* '<S53>/Selector' */
  real_T TmpSignalConversionAtg1_termref[50];
  real_T DataStoreRead1_gj;            /* '<S53>/Data Store Read1' */
  real_T DataStoreRead_n;              /* '<S53>/Data Store Read' */
  real_T Selector1[50];                /* '<S53>/Selector1' */
  real_T Divide6_d[50];                /* '<S53>/Divide6' */
  real_T Add2_f[50];                   /* '<S53>/Add2' */
  real_T g1_termref;                   /* '<S53>/g1_term,ref' */
  real_T Selector_m[50];               /* '<S47>/Selector' */
  real_T Selector1_e[50];              /* '<S47>/Selector1' */
  real_T g1ref;                        /* '<S47>/g1ref' */
  real_T Selector_d[49];               /* '<S52>/Selector' */
  real_T TmpSignalConversionAtg6_termref[50];
  real_T DataStoreRead1_kz;            /* '<S52>/Data Store Read1' */
  real_T DataStoreRead_iik;            /* '<S52>/Data Store Read' */
  real_T Selector1_l[50];              /* '<S52>/Selector1' */
  real_T Divide6_au[50];               /* '<S52>/Divide6' */
  real_T Add2_f2[50];                  /* '<S52>/Add2' */
  real_T g6_termref;                   /* '<S52>/g6_term,ref' */
  real_T Selector_mp[50];              /* '<S46>/Selector' */
  real_T Selector1_f[50];              /* '<S46>/Selector1' */
  real_T g6ref;                        /* '<S46>/g6ref' */
  real_T Selector_a[49];               /* '<S51>/Selector' */
  real_T TmpSignalConversionAtg5_termref[50];
  real_T DataStoreRead1_k3;            /* '<S51>/Data Store Read1' */
  real_T DataStoreRead_br;             /* '<S51>/Data Store Read' */
  real_T Selector1_d[50];              /* '<S51>/Selector1' */
  real_T Divide6_f[50];                /* '<S51>/Divide6' */
  real_T Add2_j[50];                   /* '<S51>/Add2' */
  real_T g5_termref;                   /* '<S51>/g5_term,ref' */
  real_T Selector_o[50];               /* '<S45>/Selector' */
  real_T Selector1_p[50];              /* '<S45>/Selector1' */
  real_T g5ref;                        /* '<S45>/g5ref' */
  real_T Selector_n[49];               /* '<S50>/Selector' */
  real_T TmpSignalConversionAtg4_termref[50];
  real_T DataStoreRead1_ap;            /* '<S50>/Data Store Read1' */
  real_T DataStoreRead_f3;             /* '<S50>/Data Store Read' */
  real_T Selector1_h[50];              /* '<S50>/Selector1' */
  real_T Divide6_h[50];                /* '<S50>/Divide6' */
  real_T Add2_k[50];                   /* '<S50>/Add2' */
  real_T g4_termref;                   /* '<S50>/g4_term,ref' */
  real_T Selector_ao[50];              /* '<S44>/Selector' */
  real_T Selector1_fr[50];             /* '<S44>/Selector1' */
  real_T g4ref;                        /* '<S44>/g4ref' */
  real_T Selector_h[49];               /* '<S49>/Selector' */
  real_T TmpSignalConversionAtg3_termref[50];
  real_T DataStoreRead1_d5;            /* '<S49>/Data Store Read1' */
  real_T DataStoreRead_m;              /* '<S49>/Data Store Read' */
  real_T Selector1_ek[50];             /* '<S49>/Selector1' */
  real_T Divide6_af[50];               /* '<S49>/Divide6' */
  real_T Add2_kc[50];                  /* '<S49>/Add2' */
  real_T g3_termref;                   /* '<S49>/g3_term,ref' */
  real_T Selector_ot[50];              /* '<S43>/Selector' */
  real_T Selector1_he[50];             /* '<S43>/Selector1' */
  real_T g3ref;                        /* '<S43>/g3ref' */
  real_T Selector_au[49];              /* '<S48>/Selector' */
  real_T TmpSignalConversionAtg2_termref[50];
  real_T DataStoreRead1_eh;            /* '<S48>/Data Store Read1' */
  real_T DataStoreRead_p4;             /* '<S48>/Data Store Read' */
  real_T Selector1_a[50];              /* '<S48>/Selector1' */
  real_T Divide6_j[50];                /* '<S48>/Divide6' */
  real_T Add2_n[50];                   /* '<S48>/Add2' */
  real_T g2_termref;                   /* '<S48>/g2_term,ref' */
  real_T Selector_m2[50];              /* '<S42>/Selector' */
  real_T Selector1_dx[50];             /* '<S42>/Selector1' */
  real_T g2ref;                        /* '<S42>/g2ref' */
  real_T DataStoreRead1_nh[500];       /* '<S41>/Data Store Read1' */
  real_T DataStoreRead_nt[500];        /* '<S41>/Data Store Read' */
  real_T I1;                           /* '<S41>/I1' */
  real_T DataStoreRead1_bf[500];       /* '<S40>/Data Store Read1' */
  real_T DataStoreRead_py[500];        /* '<S40>/Data Store Read' */
  real_T I1_b;                         /* '<S40>/I1' */
  real_T DataStoreRead1_l5[500];       /* '<S39>/Data Store Read1' */
  real_T DataStoreRead_cu[500];        /* '<S39>/Data Store Read' */
  real_T I1_e;                         /* '<S39>/I1' */
  real_T DataStoreRead1_fl[500];       /* '<S38>/Data Store Read1' */
  real_T DataStoreRead_h5[500];        /* '<S38>/Data Store Read' */
  real_T I1_j;                         /* '<S38>/I1' */
  real_T DataStoreRead1_d2[500];       /* '<S37>/Data Store Read1' */
  real_T DataStoreRead_o0[500];        /* '<S37>/Data Store Read' */
  real_T I1_ju;                        /* '<S37>/I1' */
  real_T DataStoreRead1_ax[500];       /* '<S36>/Data Store Read1' */
  real_T DataStoreRead_de[500];        /* '<S36>/Data Store Read' */
  real_T I1_h;                         /* '<S36>/I1' */
  real_T DataStoreRead1_d2u[500];      /* '<S35>/Data Store Read1' */
  real_T DataStoreRead_e1[500];        /* '<S35>/Data Store Read' */
  real_T I1_o;                         /* '<S35>/I1' */
  real_T DataStoreRead1_fj[500];       /* '<S34>/Data Store Read1' */
  real_T DataStoreRead_az[500];        /* '<S34>/Data Store Read' */
  real_T I1_jk;                        /* '<S34>/I1' */
  real_T DataStoreRead1_i[500];        /* '<S33>/Data Store Read1' */
  real_T DataStoreRead_eq[500];        /* '<S33>/Data Store Read' */
  real_T I1_a;                         /* '<S33>/I1' */
  real_T DataStoreRead1_nd[500];       /* '<S32>/Data Store Read1' */
  real_T DataStoreRead_ne[500];        /* '<S32>/Data Store Read' */
  real_T I1_g;                         /* '<S32>/I1' */
  real_T DataStoreRead1_ft[500];       /* '<S31>/Data Store Read1' */
  real_T DataStoreRead_fx[500];        /* '<S31>/Data Store Read' */
  real_T I1_ot;                        /* '<S31>/I1' */
  real_T DataStoreRead1_pg[500];       /* '<S19>/Data Store Read1' */
  real_T DataStoreRead_cq[500];        /* '<S19>/Data Store Read' */
  real_T Ipref;                        /* '<S19>/Ipref' */
  real_T Add2_i;                       /* '<S26>/Add2' */
  real_T Add2_jd;                      /* '<S25>/Add2' */
  real_T Selector_p[50];               /* '<S21>/Selector' */
  real_T Selector1_j[50];              /* '<S21>/Selector1' */
  real_T elong;                        /* '<S21>/elong' */
  real_T Add2_l;                       /* '<S14>/Add2' */
  real_T DataStoreRead1_aj;            /* '<S24>/Data Store Read1' */
  real_T Divide_n[4];                  /* '<S24>/Divide' */
  real_T Gain1;                        /* '<S4>/Gain1' */
  real_T Switch_m;                     /* '<S13>/Switch' */
  real_T Gain_h;                       /* '<S4>/Gain' */
  real_T Switch_c;                     /* '<S12>/Switch' */
  uint8_T Compare[11];                 /* '<S70>/Compare' */
  uint8_T Compare_e[11];               /* '<S71>/Compare' */
  boolean_T RelationalOperator_b;      /* '<S5>/Relational Operator' */
  boolean_T RelationalOperator1_f;     /* '<S5>/Relational Operator1' */
  boolean_T RelationalOperator_k;      /* '<S68>/Relational Operator' */
  boolean_T Compare_ev;                /* '<S89>/Compare' */
  boolean_T RelationalOperator1_k;     /* '<S60>/Relational Operator1' */
  boolean_T Compare_i;                 /* '<S78>/Compare' */
  boolean_T RelationalOperator_i;      /* '<S60>/Relational Operator' */
  boolean_T RelationalOperator1_p0;    /* '<S64>/Relational Operator1' */
  boolean_T Compare_k;                 /* '<S84>/Compare' */
  boolean_T RelationalOperator_bi;     /* '<S73>/Relational Operator' */
  boolean_T Compare_j;                 /* '<S72>/Compare' */
  boolean_T Compare_l;                 /* '<S82>/Compare' */
  boolean_T Compare_m;                 /* '<S80>/Compare' */
  boolean_T LowerRelop1[11];           /* '<S10>/LowerRelop1' */
  boolean_T UpperRelop[11];            /* '<S10>/UpperRelop' */
  boolean_T LowerRelop1_e[11];         /* '<S11>/LowerRelop1' */
  boolean_T UpperRelop_c[11];          /* '<S11>/UpperRelop' */
  boolean_T LowerRelop1_d;             /* '<S12>/LowerRelop1' */
  boolean_T LowerRelop1_l;             /* '<S13>/LowerRelop1' */
  boolean_T LowerRelop1_p;             /* '<S58>/LowerRelop1' */
  boolean_T UpperRelop_b;              /* '<S58>/UpperRelop' */
  boolean_T LowerRelop1_f;             /* '<S83>/LowerRelop1' */
  boolean_T UpperRelop_h;              /* '<S83>/UpperRelop' */
  boolean_T LowerRelop1_o;             /* '<S59>/LowerRelop1' */
  boolean_T UpperRelop_p;              /* '<S59>/UpperRelop' */
  boolean_T LowerRelop1_n;             /* '<S88>/LowerRelop1' */
  boolean_T UpperRelop_n;              /* '<S88>/UpperRelop' */
  boolean_T UpperRelop_j;              /* '<S13>/UpperRelop' */
  boolean_T UpperRelop_m;              /* '<S12>/UpperRelop' */
} BlockIO_t15_2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S29>/UD' */
  real_T UD_DSTATE_i;                  /* '<S30>/UD' */
  real_T Divcontr_DSTATE[32];          /* '<S15>/Div. contr.' */
  real_T Div_rdcontr_DSTATE[22];       /* '<S15>/Div_rd contr' */
  real_T Currtermcontr_DSTATE[22];     /* '<S15>/Curr. term. contr' */
  real_T Limcontr_DSTATE[46];          /* '<S57>/Lim. contr.' */
  real_T Currcontr_DSTATE[11];         /* '<S57>/Curr. contr.' */
  real_T UD_DSTATE_h;                  /* '<S87>/UD' */
  real_T VScontr_DSTATE[9];            /* '<S62>/VS. contr' */
  real_T VScontrhl_DSTATE[8];          /* '<S62>/VS. contr hl' */
  real_T UD_DSTATE_a;                  /* '<S6>/UD' */
  real_T Memory2_PreviousInput;        /* '<S5>/Memory2' */
  real_T Memory1_PreviousInput;        /* '<S18>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S28>/Memory' */
  real_T Memory1_PreviousInput_m;      /* '<S19>/Memory1' */
  real_T Memory_PreviousInput_p;       /* '<S27>/Memory' */
  real_T Memory2_PreviousInput_l;      /* '<S47>/Memory2' */
  real_T Memory1_PreviousInput_c;      /* '<S47>/Memory1' */
  real_T Memory2_PreviousInput_f;      /* '<S42>/Memory2' */
  real_T Memory1_PreviousInput_mf;     /* '<S42>/Memory1' */
  real_T Memory2_PreviousInput_h;      /* '<S43>/Memory2' */
  real_T Memory1_PreviousInput_n;      /* '<S43>/Memory1' */
  real_T Memory2_PreviousInput_d;      /* '<S44>/Memory2' */
  real_T Memory1_PreviousInput_o;      /* '<S44>/Memory1' */
  real_T Memory2_PreviousInput_o;      /* '<S45>/Memory2' */
  real_T Memory1_PreviousInput_b;      /* '<S45>/Memory1' */
  real_T Memory2_PreviousInput_b;      /* '<S46>/Memory2' */
  real_T Memory1_PreviousInput_d;      /* '<S46>/Memory1' */
  real_T Memory2_PreviousInput_lr;     /* '<S31>/Memory2' */
  real_T Memory2_PreviousInput_c;      /* '<S34>/Memory2' */
  real_T Memory2_PreviousInput_dq;     /* '<S35>/Memory2' */
  real_T Memory2_PreviousInput_j;      /* '<S36>/Memory2' */
  real_T Memory2_PreviousInput_d0;     /* '<S37>/Memory2' */
  real_T Memory2_PreviousInput_f3;     /* '<S38>/Memory2' */
  real_T Memory2_PreviousInput_p;      /* '<S39>/Memory2' */
  real_T Memory2_PreviousInput_i;      /* '<S40>/Memory2' */
  real_T Memory2_PreviousInput_ic;     /* '<S41>/Memory2' */
  real_T Memory2_PreviousInput_hn;     /* '<S32>/Memory2' */
  real_T Memory2_PreviousInput_bh;     /* '<S33>/Memory2' */
  real_T Memory3_PreviousInput;        /* '<S54>/Memory3' */
  real_T Memory1_PreviousInput_e[11];  /* '<S68>/Memory1' */
  real_T Memory_PreviousInput_a;       /* '<S90>/Memory' */
  real_T Memory_PreviousInput_m[11];   /* '<S60>/Memory' */
  real_T Memory_PreviousInput_l;       /* '<S79>/Memory' */
  real_T Memory1_PreviousInput_l;      /* '<S66>/Memory1' */
  real_T Memory1_PreviousInput_p;      /* '<S64>/Memory1' */
  real_T Memory_PreviousInput_o;       /* '<S85>/Memory' */
  real_T Memory1_PreviousInput_ma;     /* '<S56>/Memory1' */
  real_T Memory_PreviousInput_ok;      /* '<S74>/Memory' */
  real_T Memory2_PreviousInput_n[11];  /* '<S77>/Memory2' */
  real_T UniformRandomNumber_NextOutput;/* '<S65>/Uniform Random Number' */
  real_T Memory_PreviousInput_h;       /* '<S81>/Memory' */
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
  real_T tdiv;                         /* '<S5>/Data Store Memory19' */
  real_T c_a_tpl1;                     /* '<S5>/Data Store Memory2' */
  real_T tcont2;                       /* '<S5>/Data Store Memory3' */
  real_T Ip_div;                       /* '<S5>/Data Store Memory4' */
  real_T ref_ramp;                     /* '<S5>/Data Store Memory5' */
  real_T dtcont2;                      /* '<S5>/Data Store Memory6' */
  real_T Ip_rd;                        /* '<S5>/Data Store Memory7' */
  real_T trd_ref;                      /* '<S5>/Data Store Memory8' */
  real_T Time_stop;                    /* '<S5>/Data Store Memory9' */
  real_T Memory1_PreviousInput_bg[11]; /* '<S7>/Memory1' */
  real_T ntur[12];                     /* '<S1>/Data Store Memory1' */
  real_T RupRd[6];                     /* '<S1>/Data Store Memory2' */
  real_T VS3_up;                       /* '<S1>/Data Store Memory3' */
  real_T Vcspf_up[11];                 /* '<S1>/Data Store Memory4' */
  real_T VS1_up;                       /* '<S1>/Data Store Memory5' */
  real_T Tu;                           /* '<S1>/Data Store Memory7' */
  real_T c_cur_max;                    /* '<S1>/Data Store Memory8' */
  real_T Imax[11];                     /* '<S1>/Data Store Memory9' */
  uint32_T RandSeed;                   /* '<S65>/Uniform Random Number' */
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
  real_T Constant4_Value_f;            /* Expression: 1e-5
                                        * Referenced by: '<S25>/Constant4'
                                        */
  real_T Constant4_Value_m;            /* Expression: 1e-5
                                        * Referenced by: '<S26>/Constant4'
                                        */
  real_T _Value;                       /* Expression: 1
                                        * Referenced by: '<S66>/2'
                                        */
  real_T _Value_k;                     /* Expression: 1
                                        * Referenced by: '<S66>/1'
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
                                        * Referenced by: '<S75>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S75>/Saturation1'
                                        */
  real_T _Threshold;                   /* Expression: 1
                                        * Referenced by: '<S77>/1'
                                        */
  real_T u5_Gain;                      /* Expression: 1/15
                                        * Referenced by: '<S15>/1//15'
                                        */
  real_T _Value_kj;                    /* Expression: 1
                                        * Referenced by: '<S15>/2'
                                        */
  real_T _Value_n;                     /* Expression: 0
                                        * Referenced by: '<S63>/1'
                                        */
  real_T SatDiv_UpperSat;              /* Expression: 1
                                        * Referenced by: '<S63>/Sat. Div'
                                        */
  real_T SatDiv_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S63>/Sat. Div'
                                        */
  real_T LimDivtr_Threshold;           /* Expression: 1
                                        * Referenced by: '<S63>/Lim. Div. tr.'
                                        */
  real_T c_eob_Threshold;              /* Expression: 1
                                        * Referenced by: '<S15>/c_eob '
                                        */
  real_T u15_Gain_o;                   /* Expression: 1/15
                                        * Referenced by: '<S15>/ 1//15'
                                        */
  real_T _Value_h;                     /* Expression: 1
                                        * Referenced by: '<S15>/1'
                                        */
  real_T _Value_i;                     /* Expression: 1
                                        * Referenced by: '<S64>/1'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 1
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: 0
                                        * Referenced by: '<S64>/Saturation'
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
  real_T e6_Gain_k;                    /* Expression: 1e-6
                                        * Referenced by: '<S14>/1e-6   '
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S18>/Memory1'
                                        */
  real_T e3_Gain;                      /* Expression: 1e-3
                                        * Referenced by: '<S18>/1e-3'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S28>/Memory'
                                        */
  real_T switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<S18>/switch1'
                                        */
  real_T Constant4_Value_fs;           /* Expression: 1
                                        * Referenced by: '<S18>/Constant4'
                                        */
  real_T u_UpperSat;                   /* Expression: 1
                                        * Referenced by: '<S18>/1 0'
                                        */
  real_T u_LowerSat;                   /* Expression: 0
                                        * Referenced by: '<S18>/1 0'
                                        */
  real_T Memory1_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S19>/Memory1'
                                        */
  real_T c_eob_Threshold_j;            /* Expression: 1
                                        * Referenced by: '<S19>/c_eob'
                                        */
  real_T SFunction1_P1_Size_c[2];      /* Computed Parameter: SFunction1_P1_Size_c
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  real_T SFunction1_P1_a;              /* Expression: 0
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  real_T Constant4_Value_l;            /* Expression: 0
                                        * Referenced by: '<S14>/Constant4'
                                        */
  real_T Memory_X0_j;                  /* Expression: 0
                                        * Referenced by: '<S27>/Memory'
                                        */
  real_T e2_Gain;                      /* Expression: 1e2
                                        * Referenced by: '<S23>/1e2'
                                        */
  real_T SFunction1_P1_Size_a[2];      /* Computed Parameter: SFunction1_P1_Size_a
                                        * Referenced by: '<S47>/S-Function1'
                                        */
  real_T SFunction1_P1_k;              /* Expression: 1
                                        * Referenced by: '<S47>/S-Function1'
                                        */
  real_T Memory2_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S47>/Memory2'
                                        */
  real_T c_eob1_Threshold;             /* Expression: 1
                                        * Referenced by: '<S47>/c_eob  1'
                                        */
  real_T Memory1_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S47>/Memory1'
                                        */
  real_T c_eob_Threshold_d;            /* Expression: 1
                                        * Referenced by: '<S47>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_d[2];      /* Computed Parameter: SFunction1_P1_Size_d
                                        * Referenced by: '<S53>/S-Function1'
                                        */
  real_T SFunction1_P1_p;              /* Expression: 1
                                        * Referenced by: '<S53>/S-Function1'
                                        */
  real_T c_eob_Threshold_c;            /* Expression: 1
                                        * Referenced by: '<S47>/c_eob'
                                        */
  real_T SFunction1_P1_Size_cv[2];     /* Computed Parameter: SFunction1_P1_Size_cv
                                        * Referenced by: '<S42>/S-Function1'
                                        */
  real_T SFunction1_P1_f;              /* Expression: 2
                                        * Referenced by: '<S42>/S-Function1'
                                        */
  real_T Memory2_X0_l;                 /* Expression: 0
                                        * Referenced by: '<S42>/Memory2'
                                        */
  real_T c_eob1_Threshold_a;           /* Expression: 1
                                        * Referenced by: '<S42>/c_eob  1'
                                        */
  real_T Memory1_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S42>/Memory1'
                                        */
  real_T c_eob_Threshold_k;            /* Expression: 1
                                        * Referenced by: '<S42>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_i[2];      /* Computed Parameter: SFunction1_P1_Size_i
                                        * Referenced by: '<S48>/S-Function1'
                                        */
  real_T SFunction1_P1_b;              /* Expression: 2
                                        * Referenced by: '<S48>/S-Function1'
                                        */
  real_T c_eob_Threshold_jg;           /* Expression: 1
                                        * Referenced by: '<S42>/c_eob'
                                        */
  real_T SFunction1_P1_Size_a3[2];     /* Computed Parameter: SFunction1_P1_Size_a3
                                        * Referenced by: '<S43>/S-Function1'
                                        */
  real_T SFunction1_P1_fk;             /* Expression: 3
                                        * Referenced by: '<S43>/S-Function1'
                                        */
  real_T Memory2_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S43>/Memory2'
                                        */
  real_T c_eob1_Threshold_e;           /* Expression: 1
                                        * Referenced by: '<S43>/c_eob  1'
                                        */
  real_T Memory1_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S43>/Memory1'
                                        */
  real_T c_eob_Threshold_e;            /* Expression: 1
                                        * Referenced by: '<S43>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_b[2];      /* Computed Parameter: SFunction1_P1_Size_b
                                        * Referenced by: '<S49>/S-Function1'
                                        */
  real_T SFunction1_P1_j;              /* Expression: 3
                                        * Referenced by: '<S49>/S-Function1'
                                        */
  real_T c_eob_Threshold_m;            /* Expression: 1
                                        * Referenced by: '<S43>/c_eob'
                                        */
  real_T SFunction1_P1_Size_g[2];      /* Computed Parameter: SFunction1_P1_Size_g
                                        * Referenced by: '<S44>/S-Function1'
                                        */
  real_T SFunction1_P1_ag;             /* Expression: 4
                                        * Referenced by: '<S44>/S-Function1'
                                        */
  real_T Memory2_X0_d;                 /* Expression: 0
                                        * Referenced by: '<S44>/Memory2'
                                        */
  real_T c_eob1_Threshold_n;           /* Expression: 1
                                        * Referenced by: '<S44>/c_eob  1'
                                        */
  real_T Memory1_X0_gh;                /* Expression: 0
                                        * Referenced by: '<S44>/Memory1'
                                        */
  real_T c_eob_Threshold_k5;           /* Expression: 1
                                        * Referenced by: '<S44>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_k[2];      /* Computed Parameter: SFunction1_P1_Size_k
                                        * Referenced by: '<S50>/S-Function1'
                                        */
  real_T SFunction1_P1_g;              /* Expression: 4
                                        * Referenced by: '<S50>/S-Function1'
                                        */
  real_T c_eob_Threshold_g;            /* Expression: 1
                                        * Referenced by: '<S44>/c_eob'
                                        */
  real_T SFunction1_P1_Size_dm[2];     /* Computed Parameter: SFunction1_P1_Size_dm
                                        * Referenced by: '<S45>/S-Function1'
                                        */
  real_T SFunction1_P1_a2;             /* Expression: 5
                                        * Referenced by: '<S45>/S-Function1'
                                        */
  real_T Memory2_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S45>/Memory2'
                                        */
  real_T c_eob1_Threshold_au;          /* Expression: 1
                                        * Referenced by: '<S45>/c_eob  1'
                                        */
  real_T Memory1_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S45>/Memory1'
                                        */
  real_T c_eob_Threshold_et;           /* Expression: 1
                                        * Referenced by: '<S45>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_l[2];      /* Computed Parameter: SFunction1_P1_Size_l
                                        * Referenced by: '<S51>/S-Function1'
                                        */
  real_T SFunction1_P1_am;             /* Expression: 5
                                        * Referenced by: '<S51>/S-Function1'
                                        */
  real_T c_eob_Threshold_l;            /* Expression: 1
                                        * Referenced by: '<S45>/c_eob'
                                        */
  real_T SFunction1_P1_Size_o[2];      /* Computed Parameter: SFunction1_P1_Size_o
                                        * Referenced by: '<S46>/S-Function1'
                                        */
  real_T SFunction1_P1_m;              /* Expression: 6
                                        * Referenced by: '<S46>/S-Function1'
                                        */
  real_T Memory2_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S46>/Memory2'
                                        */
  real_T c_eob1_Threshold_l;           /* Expression: 1
                                        * Referenced by: '<S46>/c_eob  1'
                                        */
  real_T Memory1_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S46>/Memory1'
                                        */
  real_T c_eob_Threshold_lm;           /* Expression: 1
                                        * Referenced by: '<S46>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_b0[2];     /* Computed Parameter: SFunction1_P1_Size_b0
                                        * Referenced by: '<S52>/S-Function1'
                                        */
  real_T SFunction1_P1_kr;             /* Expression: 6
                                        * Referenced by: '<S52>/S-Function1'
                                        */
  real_T c_eob_Threshold_le;           /* Expression: 1
                                        * Referenced by: '<S46>/c_eob'
                                        */
  real_T e2_Gain_b;                    /* Expression: 1e-2
                                        * Referenced by: '<S23>/1e-2'
                                        */
  real_T Memory2_X0_ca;                /* Expression: 0
                                        * Referenced by: '<S31>/Memory2'
                                        */
  real_T c_eob_Threshold_f;            /* Expression: 1
                                        * Referenced by: '<S31>/c_eob'
                                        */
  real_T Memory2_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S34>/Memory2'
                                        */
  real_T c_eob_Threshold_lg;           /* Expression: 1
                                        * Referenced by: '<S34>/c_eob'
                                        */
  real_T Memory2_X0_df;                /* Expression: 0
                                        * Referenced by: '<S35>/Memory2'
                                        */
  real_T c_eob_Threshold_jk;           /* Expression: 1
                                        * Referenced by: '<S35>/c_eob'
                                        */
  real_T Memory2_X0_la;                /* Expression: 0
                                        * Referenced by: '<S36>/Memory2'
                                        */
  real_T c_eob_Threshold_jy;           /* Expression: 1
                                        * Referenced by: '<S36>/c_eob'
                                        */
  real_T Memory2_X0_p5;                /* Expression: 0
                                        * Referenced by: '<S37>/Memory2'
                                        */
  real_T c_eob_Threshold_n;            /* Expression: 1
                                        * Referenced by: '<S37>/c_eob'
                                        */
  real_T Memory2_X0_l5;                /* Expression: 0
                                        * Referenced by: '<S38>/Memory2'
                                        */
  real_T c_eob_Threshold_i;            /* Expression: 1
                                        * Referenced by: '<S38>/c_eob'
                                        */
  real_T Memory2_X0_dd;                /* Expression: 0
                                        * Referenced by: '<S39>/Memory2'
                                        */
  real_T c_eob_Threshold_dk;           /* Expression: 1
                                        * Referenced by: '<S39>/c_eob'
                                        */
  real_T Memory2_X0_lz;                /* Expression: 0
                                        * Referenced by: '<S40>/Memory2'
                                        */
  real_T c_eob_Threshold_kh;           /* Expression: 1
                                        * Referenced by: '<S40>/c_eob'
                                        */
  real_T Memory2_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S41>/Memory2'
                                        */
  real_T c_eob_Threshold_f5;           /* Expression: 1
                                        * Referenced by: '<S41>/c_eob'
                                        */
  real_T Memory2_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S32>/Memory2'
                                        */
  real_T c_eob_Threshold_d1;           /* Expression: 1
                                        * Referenced by: '<S32>/c_eob'
                                        */
  real_T Memory2_X0_laf;               /* Expression: 0
                                        * Referenced by: '<S33>/Memory2'
                                        */
  real_T c_eob_Threshold_dy;           /* Expression: 1
                                        * Referenced by: '<S33>/c_eob'
                                        */
  real_T _Threshold_f;                 /* Expression: 1
                                        * Referenced by: '<S17>/1'
                                        */
  real_T UD_InitialCondition;          /* Expression: ICPrevInput
                                        * Referenced by: '<S29>/UD'
                                        */
  real_T UD_InitialCondition_j;        /* Expression: ICPrevInput
                                        * Referenced by: '<S30>/UD'
                                        */
  real_T _Value_c;                     /* Expression: 1
                                        * Referenced by: '<S54>/1'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S54>/Memory3'
                                        */
  real_T switch1_Threshold_f;          /* Expression: 1
                                        * Referenced by: '<S54>/switch1 '
                                        */
  real_T Saturation1_UpperSat_l;       /* Expression: 1
                                        * Referenced by: '<S54>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_m;       /* Expression: 0
                                        * Referenced by: '<S54>/Saturation1'
                                        */
  real_T _Value_d;                     /* Expression: 1
                                        * Referenced by: '<S55>/1'
                                        */
  real_T e3_Gain_a;                    /* Expression: 1e3
                                        * Referenced by: '<S55>/1e3'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1
                                        * Referenced by: '<S55>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: -1
                                        * Referenced by: '<S55>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T Memory1_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S68>/Memory1'
                                        */
  real_T Constant_Value_n;             /* Expression: const
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T Memory_X0_g;                  /* Expression: 0
                                        * Referenced by: '<S90>/Memory'
                                        */
  real_T Memory_X0_d;                  /* Expression: 0
                                        * Referenced by: '<S60>/Memory'
                                        */
  real_T Constant_Value_d;             /* Expression: const
                                        * Referenced by: '<S78>/Constant'
                                        */
  real_T Memory_X0_o;                  /* Expression: 0
                                        * Referenced by: '<S79>/Memory'
                                        */
  real_T Memory1_X0_hj;                /* Expression: 0
                                        * Referenced by: '<S66>/Memory1'
                                        */
  real_T c_eob_Threshold_fg;           /* Expression: 1
                                        * Referenced by: '<S66>/c_eob'
                                        */
  real_T c_eob_Threshold_h;            /* Expression: 1
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
  real_T _Threshold_d;                 /* Expression: 1
                                        * Referenced by: '<S60>/1'
                                        */
  real_T Memory1_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S64>/Memory1'
                                        */
  real_T Constant_Value_n4;            /* Expression: const
                                        * Referenced by: '<S84>/Constant'
                                        */
  real_T Memory_X0_n;                  /* Expression: 0
                                        * Referenced by: '<S85>/Memory'
                                        */
  real_T switch1_Threshold_c;          /* Expression: 1
                                        * Referenced by: '<S64>/switch1'
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
  real_T _Threshold_l;                 /* Expression: 1
                                        * Referenced by: '<S68>/1'
                                        */
  real_T Memory1_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S56>/Memory1'
                                        */
  real_T Constant_Value_p;             /* Expression: const
                                        * Referenced by: '<S72>/Constant'
                                        */
  real_T Memory_X0_oc;                 /* Expression: 0
                                        * Referenced by: '<S74>/Memory'
                                        */
  real_T _Threshold_i;                 /* Expression: 1
                                        * Referenced by: '<S56>/1 '
                                        */
  real_T _Value_if;                    /* Expression: 1
                                        * Referenced by: '<S56>/1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S56>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: 0
                                        * Referenced by: '<S56>/Saturation'
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
  real_T Memory2_X0_l4;                /* Expression: 0
                                        * Referenced by: '<S77>/Memory2'
                                        */
  real_T Limcontr_A[2116];             /* Computed Parameter: Limcontr_A
                                        * Referenced by: '<S57>/Lim. contr.'
                                        */
  real_T Limcontr_B[782];              /* Computed Parameter: Limcontr_B
                                        * Referenced by: '<S57>/Lim. contr.'
                                        */
  real_T Limcontr_C[506];              /* Computed Parameter: Limcontr_C
                                        * Referenced by: '<S57>/Lim. contr.'
                                        */
  real_T Limcontr_D[187];              /* Computed Parameter: Limcontr_D
                                        * Referenced by: '<S57>/Lim. contr.'
                                        */
  real_T Limcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S57>/Lim. contr.'
                                        */
  real_T Currcontr_A[121];             /* Computed Parameter: Currcontr_A
                                        * Referenced by: '<S57>/Curr. contr.'
                                        */
  real_T Currcontr_B[121];             /* Computed Parameter: Currcontr_B
                                        * Referenced by: '<S57>/Curr. contr.'
                                        */
  real_T Currcontr_C[121];             /* Computed Parameter: Currcontr_C
                                        * Referenced by: '<S57>/Curr. contr.'
                                        */
  real_T Currcontr_X0;                 /* Expression: 0
                                        * Referenced by: '<S57>/Curr. contr.'
                                        */
  real_T u_Threshold;                  /* Expression: 1
                                        * Referenced by: '<S77>/ 1 '
                                        */
  real_T u01_Gain;                     /* Expression: 1e-3
                                        * Referenced by: '<S91>/0.001'
                                        */
  real_T u01_Gain_a;                   /* Expression: 1e-3
                                        * Referenced by: '<S94>/0.001'
                                        */
  real_T u01_Gain_f;                   /* Expression: 1e-3
                                        * Referenced by: '<S95>/0.001'
                                        */
  real_T u01_Gain_l;                   /* Expression: 1e-3
                                        * Referenced by: '<S96>/0.001'
                                        */
  real_T u01_Gain_o;                   /* Expression: 1e-3
                                        * Referenced by: '<S97>/0.001'
                                        */
  real_T u01_Gain_fv;                  /* Expression: 1e-3
                                        * Referenced by: '<S98>/0.001'
                                        */
  real_T u01_Gain_d;                   /* Expression: 1e-3
                                        * Referenced by: '<S99>/0.001'
                                        */
  real_T u01_Gain_g;                   /* Expression: 1e-3
                                        * Referenced by: '<S100>/0.001'
                                        */
  real_T u01_Gain_e;                   /* Expression: 1e-3
                                        * Referenced by: '<S101>/0.001'
                                        */
  real_T u01_Gain_n;                   /* Expression: 1e-3
                                        * Referenced by: '<S92>/0.001'
                                        */
  real_T u01_Gain_fl;                  /* Expression: 1e-3
                                        * Referenced by: '<S93>/0.001'
                                        */
  real_T Constant_Value_nf;            /* Expression: 0
                                        * Referenced by: '<S71>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S55>/Switch'
                                        */
  real_T UniformRandomNumber_Minimum;  /* Expression: -1
                                        * Referenced by: '<S65>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 1
                                        * Referenced by: '<S65>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S65>/Uniform Random Number'
                                        */
  real_T u5_Gain_m;                    /* Expression: 1.75
                                        * Referenced by: '<S86>/1.75'
                                        */
  real_T UD_InitialCondition_jj;       /* Expression: ICPrevInput
                                        * Referenced by: '<S87>/UD'
                                        */
  real_T e3_Gain_n;                    /* Expression: 2e3
                                        * Referenced by: '<S86>/2e3'
                                        */
  real_T VScontr_A[34];                /* Computed Parameter: VScontr_A
                                        * Referenced by: '<S62>/VS. contr'
                                        */
  real_T VScontr_B[16];                /* Computed Parameter: VScontr_B
                                        * Referenced by: '<S62>/VS. contr'
                                        */
  real_T VScontr_C[10];                /* Computed Parameter: VScontr_C
                                        * Referenced by: '<S62>/VS. contr'
                                        */
  real_T VScontr_D[4];                 /* Computed Parameter: VScontr_D
                                        * Referenced by: '<S62>/VS. contr'
                                        */
  real_T VScontr_X0;                   /* Expression: 0
                                        * Referenced by: '<S62>/VS. contr'
                                        */
  real_T Constant_Value_o;             /* Expression: const
                                        * Referenced by: '<S82>/Constant'
                                        */
  real_T VScontrhl_A[33];              /* Computed Parameter: VScontrhl_A
                                        * Referenced by: '<S62>/VS. contr hl'
                                        */
  real_T VScontrhl_B[15];              /* Computed Parameter: VScontrhl_B
                                        * Referenced by: '<S62>/VS. contr hl'
                                        */
  real_T VScontrhl_C[9];               /* Computed Parameter: VScontrhl_C
                                        * Referenced by: '<S62>/VS. contr hl'
                                        */
  real_T VScontrhl_D[4];               /* Computed Parameter: VScontrhl_D
                                        * Referenced by: '<S62>/VS. contr hl'
                                        */
  real_T VScontrhl_X0;                 /* Expression: 0
                                        * Referenced by: '<S62>/VS. contr hl'
                                        */
  real_T c_eob_Threshold_c1;           /* Expression: 1
                                        * Referenced by: '<S62>/c_eob'
                                        */
  real_T Constant_Value_c;             /* Expression: const
                                        * Referenced by: '<S80>/Constant'
                                        */
  real_T Memory_X0_c;                  /* Expression: 0
                                        * Referenced by: '<S81>/Memory'
                                        */
  real_T u5_Gain_p;                    /* Expression: 1/15
                                        * Referenced by: '<S63>/1//15'
                                        */
  real_T _Threshold_fi;                /* Expression: 1
                                        * Referenced by: '<S61>/1'
                                        */
  real_T G_curr_term_Gain[220];        /* Expression: [zeros(8,11); eye(11); zeros(1,11)]
                                        * Referenced by: '<S15>/G_curr_term'
                                        */
  real_T e6_Gain_o;                    /* Expression: 1e6
                                        * Referenced by: '<S57>/1e6'
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
  real_T DataStoreMemory19_InitialValue;/* Expression: 1e3
                                         * Referenced by: '<S5>/Data Store Memory19'
                                         */
  real_T DataStoreMemory2_InitialValue;/* Expression: 0
                                        * Referenced by: '<S5>/Data Store Memory2'
                                        */
  real_T DataStoreMemory3_InitialValue;/* Expression: 0
                                        * Referenced by: '<S5>/Data Store Memory3'
                                        */
  real_T DataStoreMemory4_InitialValue;/* Expression: 1e0
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
                                        * Referenced by: '<S7>/Memory1'
                                        */
  real_T _Gain;                        /* Expression: 2
                                        * Referenced by: '<S8>/2'
                                        */
  real_T UD_InitialCondition_e;        /* Expression: ICPrevInput
                                        * Referenced by: '<S6>/UD'
                                        */
  real_T u_Gain_j;                     /* Expression: -1
                                        * Referenced by: '<S8>/-1'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -1
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
  real_T DataStoreMemory1_InitialValue_p[12];/* Expression: [554,554,554,554,554  248.6 115.2 185.9 169.9 216.8  459.4 1]
                                              * Referenced by: '<S1>/Data Store Memory1'
                                              */
  real_T DataStoreMemory2_InitialValue_o[6];/* Expression: [1; ones(3,1)*1e-6; -1e6; 1e-6]
                                             * Referenced by: '<S1>/Data Store Memory2'
                                             */
  real_T DataStoreMemory3_InitialValue_p;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory3'
                                          */
  real_T DataStoreMemory4_InitialValue_c[11];/* Expression: zeros(11,1)
                                              * Referenced by: '<S1>/Data Store Memory4'
                                              */
  real_T DataStoreMemory5_InitialValue_a;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory5'
                                          */
  real_T DataStoreMemory7_InitialValue_h;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory7'
                                          */
  real_T DataStoreMemory8_InitialValue_b;/* Expression: 0
                                          * Referenced by: '<S1>/Data Store Memory8'
                                          */
  real_T DataStoreMemory9_InitialValue_p[11];/* Expression: ones(1,11)*1e6
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
 * Block '<S2>/Memory1' : Unused code path elimination
 * Block '<S2>/Memory2' : Unused code path elimination
 * Block '<S2>/Memory3' : Unused code path elimination
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
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Propagation' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/To Workspace' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Propagation' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Propagation' : Unused code path elimination
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
 * '<S25>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Err./If Action Subsystem'
 * '<S26>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Err./If Action Subsystem1'
 * '<S27>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Err./Trigger'
 * '<S28>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/Ics1_end/Trigger'
 * '<S29>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/dZ//dt/Difference'
 * '<S30>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/dZ//dt/Difference1'
 * '<S31>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil1 ref'
 * '<S32>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil10 ref'
 * '<S33>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil11 ref'
 * '<S34>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil2 ref'
 * '<S35>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil3 ref'
 * '<S36>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil4 ref'
 * '<S37>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil5 ref'
 * '<S38>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil6 ref'
 * '<S39>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil7 ref'
 * '<S40>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil8 ref'
 * '<S41>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/err(Ic) scr_data.dat/Icoil9 ref'
 * '<S42>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem1'
 * '<S43>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem2'
 * '<S44>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem3'
 * '<S45>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem4'
 * '<S46>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem5'
 * '<S47>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem6'
 * '<S48>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem1/g2_term,ref'
 * '<S49>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem2/g3_term,ref'
 * '<S50>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem3/g4_term,ref'
 * '<S51>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem4/g5_term,ref'
 * '<S52>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem5/g6_term,ref'
 * '<S53>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem6/g1_term,ref'
 * '<S54>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/ tt_kavin2.dat(1)'
 * '<S55>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Curr. satur.1'
 * '<S56>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Ip>cIp_end'
 * '<S57>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1'
 * '<S58>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Saturation Dynamic'
 * '<S59>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Saturation Dynamic1'
 * '<S60>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem7'
 * '<S61>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem8'
 * '<S62>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS VShl contr.'
 * '<S63>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS gain 1'
 * '<S64>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/div_divrd'
 * '<S65>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/dzdt noise1'
 * '<S66>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/scr_data.dat'
 * '<S67>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/t_tran2D'
 * '<S68>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/tt_kavin2.dat(1,4)'
 * '<S69>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat'
 * '<S70>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Curr. satur.1/Compare To Constant'
 * '<S71>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Curr. satur.1/Compare To Zero'
 * '<S72>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Ip>cIp_end/Compare To Constant1'
 * '<S73>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Ip>cIp_end/Ip<cIp_end'
 * '<S74>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Ip>cIp_end/Trigger'
 * '<S75>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1/gain_cont2'
 * '<S76>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1/t_cont2'
 * '<S77>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Lim. contr.1/t_cont2_1'
 * '<S78>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem7/Compare To Constant1'
 * '<S79>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem7/Trigger'
 * '<S80>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem8/Compare To Constant1'
 * '<S81>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/Subsystem8/Trigger'
 * '<S82>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS VShl contr./Compare To Constant1'
 * '<S83>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/VS gain 1/Saturation Dynamic'
 * '<S84>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/div_divrd/Compare To Constant1'
 * '<S85>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/div_divrd/Trigger'
 * '<S86>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/dzdt noise1/Subsystem'
 * '<S87>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/dzdt noise1/Subsystem/Difference'
 * '<S88>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/scr_data.dat/Saturation Dynamic'
 * '<S89>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/tt_kavin2.dat(1,4)/Compare To Constant1'
 * '<S90>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/tt_kavin2.dat(1,4)/Trigger'
 * '<S91>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt1'
 * '<S92>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt10'
 * '<S93>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt11'
 * '<S94>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt2'
 * '<S95>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt3'
 * '<S96>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt4'
 * '<S97>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt5'
 * '<S98>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt6'
 * '<S99>'  : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt7'
 * '<S100>' : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt8'
 * '<S101>' : 't15_2/Pow. Supply MC 2/kavin_contr/Control1/volt.dat/volt9'
 */
#endif                                 /* RTW_HEADER_t15_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
