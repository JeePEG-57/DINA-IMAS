/*
 * File: t15_2.h
 *
 * Code generated for Simulink model 't15_2'.
 *
 * Model version                  : 1.1142
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Sun Jan 13 20:01:06 2019
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
  real_T SFunction1[6500];             /* '<S4>/S-Function1' */
  real_T SFunction2[10000];            /* '<S4>/S-Function2' */
  real_T SFunction[6];                 /* '<S4>/S-Function' */
  real_T e3;                           /* '<S4>/1e-3' */
  real_T Memory2;                      /* '<S4>/Memory2' */
  real_T u;                            /* '<S4>/-1' */
  real_T Ip1e4;                        /* '<S4>/Ip<1e-4 ' */
  real_T DataStoreRead;                /* '<S4>/Data Store Read' */
  real_T Sum2;                         /* '<S4>/Sum2' */
  real_T e6;                           /* '<S7>/1e-6' */
  real_T e6_i[15];                     /* '<S7>/1e-6   ' */
  real_T Memory2_c;                    /* '<S13>/Memory2' */
  real_T Add3;                         /* '<S13>/Add3' */
  real_T DataStoreRead1;               /* '<S13>/Data Store Read1' */
  real_T nturn_CS1;                    /* '<S13>/nturn_CS1' */
  real_T RelationalOperator;           /* '<S13>/Relational Operator' */
  real_T Memory1;                      /* '<S13>/Memory1' */
  real_T u99;                          /* '<S13>/0.999' */
  real_T Add2;                         /* '<S13>/Add2' */
  real_T DataStoreRead_j;              /* '<S13>/Data Store Read' */
  real_T Product;                      /* '<S13>/Product' */
  real_T Add1;                         /* '<S13>/Add1' */
  real_T u_n;                          /* '<S13>/1 0' */
  real_T Memory1_k;                    /* '<S11>/Memory1' */
  real_T c_eob;                        /* '<S11>/c_eob' */
  real_T Divide6;                      /* '<S11>/Divide6' */
  real_T Add1_f;                       /* '<S7>/Add1' */
  real_T SFunction1_j[100];            /* '<S16>/S-Function1' */
  real_T Memory2_o;                    /* '<S20>/Memory2' */
  real_T c_eob_m;                      /* '<S20>/c_eob' */
  real_T Divide1;                      /* '<S20>/Divide1' */
  real_T Add1_l;                       /* '<S10>/Add1' */
  real_T Memory2_k;                    /* '<S18>/Memory2' */
  real_T c_eob_a;                      /* '<S18>/c_eob' */
  real_T Divide1_i;                    /* '<S18>/Divide1' */
  real_T Add10;                        /* '<S10>/Add10' */
  real_T Memory2_d;                    /* '<S19>/Memory2' */
  real_T c_eob_o;                      /* '<S19>/c_eob' */
  real_T Divide1_l;                    /* '<S19>/Divide1' */
  real_T Add11;                        /* '<S10>/Add11' */
  real_T Memory2_i;                    /* '<S21>/Memory2' */
  real_T c_eob_h;                      /* '<S21>/c_eob' */
  real_T Divide1_e;                    /* '<S21>/Divide1' */
  real_T Add2_o;                       /* '<S10>/Add2' */
  real_T Memory2_f;                    /* '<S17>/Memory2' */
  real_T c_eob_g;                      /* '<S17>/c_eob' */
  real_T Divide1_ev;                   /* '<S17>/Divide1' */
  real_T Add3_a;                       /* '<S10>/Add3' */
  real_T Memory2_a;                    /* '<S22>/Memory2' */
  real_T c_eob_c;                      /* '<S22>/c_eob' */
  real_T Divide1_p;                    /* '<S22>/Divide1' */
  real_T Add4;                         /* '<S10>/Add4' */
  real_T Memory2_h;                    /* '<S23>/Memory2' */
  real_T c_eob_d;                      /* '<S23>/c_eob' */
  real_T Divide1_k;                    /* '<S23>/Divide1' */
  real_T Add5;                         /* '<S10>/Add5' */
  real_T Memory2_ik;                   /* '<S24>/Memory2' */
  real_T c_eob_n;                      /* '<S24>/c_eob' */
  real_T Divide1_f;                    /* '<S24>/Divide1' */
  real_T Add6;                         /* '<S10>/Add6' */
  real_T Memory2_oe;                   /* '<S25>/Memory2' */
  real_T c_eob_j;                      /* '<S25>/c_eob' */
  real_T Divide1_kg;                   /* '<S25>/Divide1' */
  real_T Add7;                         /* '<S10>/Add7' */
  real_T Memory2_e;                    /* '<S26>/Memory2' */
  real_T c_eob_e;                      /* '<S26>/c_eob' */
  real_T Divide1_o;                    /* '<S26>/Divide1' */
  real_T Add8;                         /* '<S10>/Add8' */
  real_T Memory2_c1;                   /* '<S27>/Memory2' */
  real_T c_eob_e0;                     /* '<S27>/c_eob' */
  real_T Divide1_n;                    /* '<S27>/Divide1' */
  real_T Add9;                         /* '<S10>/Add9' */
  real_T Sum2_c;                       /* '<S9>/Sum2' */
  real_T u_f;                          /* '<S9>/>=0' */
  real_T e2[6];                        /* '<S12>/1e2' */
  real_T SFunction1_k[100];            /* '<S33>/S-Function1' */
  real_T Memory2_l;                    /* '<S33>/Memory2' */
  real_T c_eob1;                       /* '<S33>/c_eob  1' */
  real_T Memory1_d;                    /* '<S33>/Memory1' */
  real_T c_eob_k;                      /* '<S33>/c_eob  ' */
  real_T SFunction1_g[100];            /* '<S39>/S-Function1' */
  real_T c_eob_f;                      /* '<S33>/c_eob' */
  real_T Add2_f;                       /* '<S12>/Add2' */
  real_T LookupTable1;                 /* '<S12>/Lookup Table1' */
  real_T Divide6_o;                    /* '<S12>/Divide6' */
  real_T SFunction1_m[100];            /* '<S28>/S-Function1' */
  real_T Memory2_aw;                   /* '<S28>/Memory2' */
  real_T c_eob1_n;                     /* '<S28>/c_eob  1' */
  real_T Memory1_n;                    /* '<S28>/Memory1' */
  real_T c_eob_b;                      /* '<S28>/c_eob  ' */
  real_T SFunction1_c[100];            /* '<S34>/S-Function1' */
  real_T c_eob_i;                      /* '<S28>/c_eob' */
  real_T Add1_d;                       /* '<S12>/Add1' */
  real_T LookupTable2;                 /* '<S12>/Lookup Table2' */
  real_T Divide1_kx;                   /* '<S12>/Divide1' */
  real_T SFunction1_o[100];            /* '<S29>/S-Function1' */
  real_T Memory2_n;                    /* '<S29>/Memory2' */
  real_T c_eob1_j;                     /* '<S29>/c_eob  1' */
  real_T Memory1_i;                    /* '<S29>/Memory1' */
  real_T c_eob_l;                      /* '<S29>/c_eob  ' */
  real_T SFunction1_gm[100];           /* '<S35>/S-Function1' */
  real_T c_eob_jr;                     /* '<S29>/c_eob' */
  real_T Add3_i;                       /* '<S12>/Add3' */
  real_T SFunction1_co[100];           /* '<S30>/S-Function1' */
  real_T Memory2_de;                   /* '<S30>/Memory2' */
  real_T c_eob1_p;                     /* '<S30>/c_eob  1' */
  real_T Memory1_c;                    /* '<S30>/Memory1' */
  real_T c_eob_mw;                     /* '<S30>/c_eob  ' */
  real_T SFunction1_jw[100];           /* '<S36>/S-Function1' */
  real_T c_eob_js;                     /* '<S30>/c_eob' */
  real_T Add4_g;                       /* '<S12>/Add4' */
  real_T LookupTable3;                 /* '<S12>/Lookup Table3' */
  real_T Divide2;                      /* '<S12>/Divide2' */
  real_T SFunction1_kj[100];           /* '<S31>/S-Function1' */
  real_T Memory2_o4;                   /* '<S31>/Memory2' */
  real_T c_eob1_k;                     /* '<S31>/c_eob  1' */
  real_T Memory1_p;                    /* '<S31>/Memory1' */
  real_T c_eob_fy;                     /* '<S31>/c_eob  ' */
  real_T SFunction1_l[100];            /* '<S37>/S-Function1' */
  real_T c_eob_f4;                     /* '<S31>/c_eob' */
  real_T Add5_i;                       /* '<S12>/Add5' */
  real_T SFunction1_f[100];            /* '<S32>/S-Function1' */
  real_T Memory2_p;                    /* '<S32>/Memory2' */
  real_T c_eob1_o;                     /* '<S32>/c_eob  1' */
  real_T Memory1_da;                   /* '<S32>/Memory1' */
  real_T c_eob_e2;                     /* '<S32>/c_eob  ' */
  real_T SFunction1_gc[100];           /* '<S38>/S-Function1' */
  real_T c_eob_lc;                     /* '<S32>/c_eob' */
  real_T Add6_d;                       /* '<S12>/Add6' */
  real_T e2_i[6];                      /* '<S12>/1e-2' */
  real_T e6_c;                         /* '<S13>/1e6' */
  real_T DataStoreRead_n;              /* '<S14>/Data Store Read' */
  real_T LogicalOperator1;             /* '<S14>/Logical Operator1' */
  real_T u9[20];                       /* '<S14>/0.99' */
  real_T Uk1;                          /* '<S41>/UD' */
  real_T Uk1_h;                        /* '<S42>/UD' */
  real_T e3_d[11];                     /* '<S43>/1e3' */
  real_T Abs[11];                      /* '<S43>/Abs' */
  real_T ntur[11];                     /* '<S43>/ntur' */
  real_T Sum2_i[11];                   /* '<S43>/Sum2' */
  real_T c_cur_max[11];                /* '<S43>/c_cur_max' */
  real_T Sum1[11];                     /* '<S43>/Sum1' */
  real_T Divide4[11];                  /* '<S43>/Divide4' */
  real_T Divide1_nw[11];               /* '<S43>/Divide1' */
  real_T Saturation[11];               /* '<S43>/Saturation' */
  real_T Memory1_g[11];                /* '<S44>/Memory1' */
  real_T DataStoreRead_i;              /* '<S44>/Data Store Read' */
  real_T Abs_j;                        /* '<S44>/Abs' */
  real_T DataStoreRead1_l;             /* '<S44>/Data Store Read1' */
  real_T LogicalOperator2;             /* '<S44>/Logical Operator2' */
  real_T Memory[11];                   /* '<S46>/Memory' */
  real_T DataStoreRead_m;              /* '<S59>/Data Store Read' */
  real_T DataStoreRead1_g;             /* '<S46>/Data Store Read1' */
  real_T Abs_a;                        /* '<S46>/Abs' */
  real_T LogicalOperator1_o;           /* '<S46>/Logical Operator1' */
  real_T Memory3;                      /* '<S55>/Memory3' */
  real_T DataStoreRead_o;              /* '<S80>/Data Store Read' */
  real_T LogicalOperator1_h;           /* '<S55>/Logical Operator1' */
  real_T u999;                         /* '<S55>/0.9999' */
  real_T Subtract2;                    /* '<S55>/Subtract2' */
  real_T Gain1;                        /* '<S55>/Gain1' */
  real_T Subtract1;                    /* '<S55>/Subtract1' */
  real_T Saturation1;                  /* '<S55>/Saturation1' */
  real_T Divide2_d[20];                /* '<S8>/Divide2' */
  real_T Divcontr[11];                 /* '<S8>/Div. contr.' */
  real_T u9_a[11];                     /* '<S46>/0.99' */
  real_T Memory1_h;                    /* '<S53>/Memory1' */
  real_T DataStoreRead_e;              /* '<S76>/Data Store Read' */
  real_T LogicalOperator1_k;           /* '<S53>/Logical Operator1' */
  real_T u999_g;                       /* '<S53>/0.9999' */
  real_T Divide13[20];                 /* '<S8>/Divide13' */
  real_T Div_rdcontr[11];              /* '<S8>/Div_rd contr' */
  real_T Memory1_c1;                   /* '<S51>/Memory1' */
  real_T c_eob_oo;                     /* '<S51>/c_eob' */
  real_T u99_g[11];                    /* '<S44>/0.999' */
  real_T Memory1_o;                    /* '<S52>/Memory1' */
  real_T DataStoreRead_ez;             /* '<S73>/Data Store Read' */
  real_T Abs_e;                        /* '<S73>/Abs' */
  real_T DataStoreRead_h;              /* '<S74>/Data Store Read' */
  real_T LogicalOperator2_a;           /* '<S52>/Logical Operator2' */
  real_T u999_f;                       /* '<S52>/0.9999' */
  real_T Subtract2_b;                  /* '<S52>/Subtract2' */
  real_T Gain1_n;                      /* '<S52>/Gain1' */
  real_T Subtract3;                    /* '<S52>/Subtract3' */
  real_T Saturation_g;                 /* '<S52>/Saturation' */
  real_T Divide4_n[11];                /* '<S8>/Divide4' */
  real_T Currtermcontr[11];            /* '<S8>/Curr. term. contr' */
  real_T Subtract1_h;                  /* '<S52>/Subtract1' */
  real_T Divide5[11];                  /* '<S8>/Divide5' */
  real_T Memory2_fq[11];               /* '<S45>/Memory2' */
  real_T tcont2[20];                   /* '<S45>/tcont2 ' */
  real_T Limcontr[11];                 /* '<S45>/Lim. contr.' */
  real_T Currcontr[11];                /* '<S45>/Curr. contr.' */
  real_T IpIp_div[11];                 /* '<S45>/Ip>Ip_div ' */
  real_T Divide6_a[11];                /* '<S8>/Divide6' */
  real_T DataStoreRead_iq[500];        /* '<S62>/Data Store Read' */
  real_T u01[500];                     /* '<S62>/0.001' */
  real_T DataStoreRead1_f[500];        /* '<S62>/Data Store Read1' */
  real_T volt1;                        /* '<S62>/volt1' */
  real_T DataStoreRead_iqf[500];       /* '<S65>/Data Store Read' */
  real_T u01_b[500];                   /* '<S65>/0.001' */
  real_T DataStoreRead1_i[500];        /* '<S65>/Data Store Read1' */
  real_T volt1_f;                      /* '<S65>/volt1' */
  real_T DataStoreRead_l[500];         /* '<S66>/Data Store Read' */
  real_T u01_f[500];                   /* '<S66>/0.001' */
  real_T DataStoreRead1_k[500];        /* '<S66>/Data Store Read1' */
  real_T volt1_l;                      /* '<S66>/volt1' */
  real_T DataStoreRead_c[500];         /* '<S67>/Data Store Read' */
  real_T u01_i[500];                   /* '<S67>/0.001' */
  real_T DataStoreRead1_j[500];        /* '<S67>/Data Store Read1' */
  real_T volt1_h;                      /* '<S67>/volt1' */
  real_T DataStoreRead_ml[500];        /* '<S68>/Data Store Read' */
  real_T u01_e[500];                   /* '<S68>/0.001' */
  real_T DataStoreRead1_c[500];        /* '<S68>/Data Store Read1' */
  real_T volt1_j;                      /* '<S68>/volt1' */
  real_T DataStoreRead_b[500];         /* '<S69>/Data Store Read' */
  real_T u01_j[500];                   /* '<S69>/0.001' */
  real_T DataStoreRead1_p[500];        /* '<S69>/Data Store Read1' */
  real_T volt1_n;                      /* '<S69>/volt1' */
  real_T DataStoreRead_js[500];        /* '<S70>/Data Store Read' */
  real_T u01_n[500];                   /* '<S70>/0.001' */
  real_T DataStoreRead1_e[500];        /* '<S70>/Data Store Read1' */
  real_T volt1_a;                      /* '<S70>/volt1' */
  real_T DataStoreRead_ew[500];        /* '<S71>/Data Store Read' */
  real_T u01_a[500];                   /* '<S71>/0.001' */
  real_T DataStoreRead1_c5[500];       /* '<S71>/Data Store Read1' */
  real_T volt1_m;                      /* '<S71>/volt1' */
  real_T DataStoreRead_o0[500];        /* '<S72>/Data Store Read' */
  real_T u01_fc[500];                  /* '<S72>/0.001' */
  real_T DataStoreRead1_iz[500];       /* '<S72>/Data Store Read1' */
  real_T volt1_mg;                     /* '<S72>/volt1' */
  real_T DataStoreRead_d[500];         /* '<S63>/Data Store Read' */
  real_T u01_n0[500];                  /* '<S63>/0.001' */
  real_T DataStoreRead1_m[500];        /* '<S63>/Data Store Read1' */
  real_T volt1_fm;                     /* '<S63>/volt1' */
  real_T DataStoreRead_dt[500];        /* '<S64>/Data Store Read' */
  real_T u01_fy[500];                  /* '<S64>/0.001' */
  real_T DataStoreRead1_a[500];        /* '<S64>/Data Store Read1' */
  real_T volt1_hq;                     /* '<S64>/volt1' */
  real_T Subtract4;                    /* '<S52>/Subtract4' */
  real_T Divide7[11];                  /* '<S8>/Divide7' */
  real_T Sum3[11];                     /* '<S8>/Sum3' */
  real_T Divide2_b[11];                /* '<S43>/Divide2' */
  real_T Sum3_h[11];                   /* '<S43>/Sum3' */
  real_T Saturation1_k[11];            /* '<S43>/Saturation1' */
  real_T Divide6_p[11];                /* '<S43>/Divide6' */
  real_T UniformRandomNumber;          /* '<S54>/Uniform Random Number' */
  real_T Uk1_i;                        /* '<S78>/UD' */
  real_T tt_tran2d[2];                 /* '<S8>/t>t_tran2d' */
  real_T VScontr[2];                   /* '<S48>/VS. contr' */
  real_T RelationalOperator_h;         /* '<S48>/Relational Operator' */
  real_T Divide4_f[2];                 /* '<S48>/Divide4' */
  real_T VScontrhl[2];                 /* '<S48>/VS. contr hl' */
  real_T c_eob_nn[2];                  /* '<S48>/c_eob' */
  real_T DataStoreRead_ie;             /* '<S61>/Data Store Read' */
  real_T DataStoreRead_iw;             /* '<S47>/Data Store Read' */
  real_T Abs_k;                        /* '<S47>/Abs' */
  real_T LogicalOperator1_g;           /* '<S47>/Logical Operator1' */
  real_T atpl115;                      /* '<S50>/atpl1//15' */
  real_T u9_i[2];                      /* '<S47>/0.99' */
  real_T Divide10[2];                  /* '<S8>/Divide10' */
  real_T Divide12[20];                 /* '<S8>/Divide12' */
  real_T ntur_k[11];                   /* '<S45>/1//ntur' */
  real_T ntur_e[11];                   /* '<S4>/ntur' */
  real_T Memory1_a[11];                /* '<S6>/Memory1' */
  real_T Uk1_l;                        /* '<S5>/UD' */
  real_T Diff;                         /* '<S5>/Diff' */
  real_T Gain1_h[20];                  /* '<S2>/Gain1' */
  real_T SFunction_b[20];              /* '<S2>/S-Function' */
  real_T Gain2[11];                    /* '<S2>/Gain2' */
  real_T Add1_o[11];                   /* '<S6>/Add1' */
  real_T Divide[11];                   /* '<S6>/Divide' */
  real_T Ratemc[11];                   /* '<S6>/Ratemc' */
  real_T Divide1_a[11];                /* '<S6>/Divide1' */
  real_T Add2_c[11];                   /* '<S6>/Add2' */
  real_T Vmc_sat[11];                  /* '<S6>/Vmc_sat' */
  real_T ntur_kh[11];                  /* '<S1>/1//ntur' */
  real_T SaturationVS1;                /* '<S3>/Saturation VS1' */
  real_T SaturationVS3;                /* '<S3>/Saturation VS3' */
  real_T TmpSignalConversionAtwzInport1[2];
  real_T wz[12];                       /* '<S1>/wz' */
  real_T Add1_g[11];                   /* '<S1>/Add1' */
  real_T TmpSignalConversionAtnpf12Inpor[12];
  real_T npf12[15];                    /* '<S1>/npf,12' */
  real_T DataStoreRead1_l1[500];       /* '<S51>/Data Store Read1' */
  real_T DataStoreRead_mv[500];        /* '<S51>/Data Store Read' */
  real_T Ipref;                        /* '<S51>/Ipref' */
  real_T c_a_tpl1_eob15;               /* '<S8>/c_a_tpl1_eob//15' */
  real_T Saturation4;                  /* '<S8>/Saturation4' */
  real_T Divide11[2];                  /* '<S8>/Divide11' */
  real_T c_eob_lq[2];                  /* '<S8>/c_eob ' */
  real_T IpIp_div_b;                   /* '<S50>/Ip>Ip_div' */
  real_T Divide8[2];                   /* '<S8>/Divide8' */
  real_T SatDiv;                       /* '<S50>/Sat. Div' */
  real_T SatLim;                       /* '<S50>/Sat. Lim' */
  real_T u5;                           /* '<S8>/1//15' */
  real_T Saturation3;                  /* '<S8>/Saturation3' */
  real_T Divide9[2];                   /* '<S8>/Divide9' */
  real_T Subtract3_c;                  /* '<S55>/Subtract3' */
  real_T Divide_d[11];                 /* '<S8>/Divide' */
  real_T tcont2_h[11];                 /* '<S45>/tcont2' */
  real_T gain_cont2;                   /* '<S45>/gain_cont2' */
  real_T Divide_c[11];                 /* '<S45>/Divide ' */
  real_T ntur_o[11];                   /* '<S45>/1//ntur ' */
  real_T Subtract2_g;                  /* '<S53>/Subtract2' */
  real_T Gain1_na;                     /* '<S53>/Gain1' */
  real_T Subtract3_cf;                 /* '<S53>/Subtract3' */
  real_T Saturation_f;                 /* '<S53>/Saturation' */
  real_T Subtract1_g;                  /* '<S53>/Subtract1' */
  real_T c_eob_a0;                     /* '<S8>/c_eob' */
  real_T Divide3[11];                  /* '<S8>/Divide3' */
  real_T Divide1_is[11];               /* '<S8>/Divide1' */
  real_T Sum2_m[11];                   /* '<S8>/Sum2' */
  real_T atpl2;                        /* '<S8>/atpl2' */
  real_T Saturation_n;                 /* '<S8>/Saturation' */
  real_T Divide6_pn;                   /* '<S51>/Divide6' */
  real_T Sum;                          /* '<S51>/Sum' */
  real_T Divide2_k;                    /* '<S51>/Divide2' */
  real_T Sum1_e;                       /* '<S51>/Sum1' */
  real_T uy0;                          /* '<S51>/[1 y0]' */
  real_T Diff_d;                       /* '<S78>/Diff' */
  real_T e3_i;                         /* '<S77>/2e3' */
  real_T Sqrt;                         /* '<S77>/Sqrt' */
  real_T DataStoreRead_bx;             /* '<S77>/Data Store Read' */
  real_T u5_p;                         /* '<S77>/1.75' */
  real_T Divide11_m;                   /* '<S77>/Divide11' */
  real_T Divide1_c;                    /* '<S77>/Divide1' */
  real_T Diff_g;                       /* '<S42>/Diff' */
  real_T Diff_p;                       /* '<S41>/Diff' */
  real_T Divide_o;                     /* '<S15>/Divide' */
  real_T Sum2_g;                       /* '<S54>/Sum2' */
  real_T Selector[50];                 /* '<S16>/Selector' */
  real_T Selector1[50];                /* '<S16>/Selector1' */
  real_T elong;                        /* '<S16>/elong' */
  real_T Add2_k;                       /* '<S7>/Add2' */
  real_T k_gaplim[4];                  /* '<S7>/k_gaplim' */
  real_T Selector_l[49];               /* '<S39>/Selector' */
  real_T TmpSignalConversionAtg1_termref[50];
  real_T DataStoreRead_oy;             /* '<S39>/Data Store Read' */
  real_T Selector1_f[50];              /* '<S39>/Selector1' */
  real_T Divide6_e[50];                /* '<S39>/Divide6' */
  real_T Add2_e[50];                   /* '<S39>/Add2' */
  real_T g1_termref;                   /* '<S39>/g1_term,ref' */
  real_T Selector_c[50];               /* '<S33>/Selector' */
  real_T Selector1_fr[50];             /* '<S33>/Selector1' */
  real_T g1ref;                        /* '<S33>/g1ref' */
  real_T Selector_ca[49];              /* '<S38>/Selector' */
  real_T TmpSignalConversionAtg6_termref[50];
  real_T DataStoreRead_o1;             /* '<S38>/Data Store Read' */
  real_T Selector1_h[50];              /* '<S38>/Selector1' */
  real_T Divide6_pa[50];               /* '<S38>/Divide6' */
  real_T Add2_p[50];                   /* '<S38>/Add2' */
  real_T g6_termref;                   /* '<S38>/g6_term,ref' */
  real_T Selector_p[50];               /* '<S32>/Selector' */
  real_T Selector1_hn[50];             /* '<S32>/Selector1' */
  real_T g6ref;                        /* '<S32>/g6ref' */
  real_T Selector_n[49];               /* '<S37>/Selector' */
  real_T TmpSignalConversionAtg5_termref[50];
  real_T DataStoreRead_p;              /* '<S37>/Data Store Read' */
  real_T Selector1_o[50];              /* '<S37>/Selector1' */
  real_T Divide6_i[50];                /* '<S37>/Divide6' */
  real_T Add2_d[50];                   /* '<S37>/Add2' */
  real_T g5_termref;                   /* '<S37>/g5_term,ref' */
  real_T Selector_m[50];               /* '<S31>/Selector' */
  real_T Selector1_d[50];              /* '<S31>/Selector1' */
  real_T g5ref;                        /* '<S31>/g5ref' */
  real_T Selector_d[49];               /* '<S36>/Selector' */
  real_T TmpSignalConversionAtg4_termref[50];
  real_T DataStoreRead_nw;             /* '<S36>/Data Store Read' */
  real_T Selector1_i[50];              /* '<S36>/Selector1' */
  real_T Divide6_o1[50];               /* '<S36>/Divide6' */
  real_T Add2_a[50];                   /* '<S36>/Add2' */
  real_T g4_termref;                   /* '<S36>/g4_term,ref' */
  real_T Selector_f[50];               /* '<S30>/Selector' */
  real_T Selector1_g[50];              /* '<S30>/Selector1' */
  real_T g4ref;                        /* '<S30>/g4ref' */
  real_T Selector_k[49];               /* '<S35>/Selector' */
  real_T TmpSignalConversionAtg3_termref[50];
  real_T DataStoreRead_lk;             /* '<S35>/Data Store Read' */
  real_T Selector1_n[50];              /* '<S35>/Selector1' */
  real_T Divide6_ih[50];               /* '<S35>/Divide6' */
  real_T Add2_g[50];                   /* '<S35>/Add2' */
  real_T g3_termref;                   /* '<S35>/g3_term,ref' */
  real_T Selector_fm[50];              /* '<S29>/Selector' */
  real_T Selector1_oh[50];             /* '<S29>/Selector1' */
  real_T g3ref;                        /* '<S29>/g3ref' */
  real_T Selector_g[49];               /* '<S34>/Selector' */
  real_T TmpSignalConversionAtg2_termref[50];
  real_T DataStoreRead_cy;             /* '<S34>/Data Store Read' */
  real_T Selector1_gs[50];             /* '<S34>/Selector1' */
  real_T Divide6_em[50];               /* '<S34>/Divide6' */
  real_T Add2_ei[50];                  /* '<S34>/Add2' */
  real_T g2_termref;                   /* '<S34>/g2_term,ref' */
  real_T Selector_h[50];               /* '<S28>/Selector' */
  real_T Selector1_l[50];              /* '<S28>/Selector1' */
  real_T g2ref;                        /* '<S28>/g2ref' */
  real_T DataStoreRead1_b[500];        /* '<S11>/Data Store Read1' */
  real_T DataStoreRead_g[500];         /* '<S11>/Data Store Read' */
  real_T Ipref_a;                      /* '<S11>/Ipref' */
  real_T DataStoreRead1_o[500];        /* '<S27>/Data Store Read1' */
  real_T DataStoreRead_pc[500];        /* '<S27>/Data Store Read' */
  real_T I1;                           /* '<S27>/I1' */
  real_T DataStoreRead1_lt[500];       /* '<S26>/Data Store Read1' */
  real_T DataStoreRead_cm[500];        /* '<S26>/Data Store Read' */
  real_T I1_p;                         /* '<S26>/I1' */
  real_T DataStoreRead1_lo[500];       /* '<S25>/Data Store Read1' */
  real_T DataStoreRead_k[500];         /* '<S25>/Data Store Read' */
  real_T I1_n;                         /* '<S25>/I1' */
  real_T DataStoreRead1_au[500];       /* '<S24>/Data Store Read1' */
  real_T DataStoreRead_i5[500];        /* '<S24>/Data Store Read' */
  real_T I1_l;                         /* '<S24>/I1' */
  real_T DataStoreRead1_n[500];        /* '<S23>/Data Store Read1' */
  real_T DataStoreRead_hu[500];        /* '<S23>/Data Store Read' */
  real_T I1_h;                         /* '<S23>/I1' */
  real_T DataStoreRead1_nk[500];       /* '<S22>/Data Store Read1' */
  real_T DataStoreRead_me[500];        /* '<S22>/Data Store Read' */
  real_T I1_g;                         /* '<S22>/I1' */
  real_T DataStoreRead1_ml[500];       /* '<S21>/Data Store Read1' */
  real_T DataStoreRead_a[500];         /* '<S21>/Data Store Read' */
  real_T I1_k;                         /* '<S21>/I1' */
  real_T DataStoreRead1_jb[500];       /* '<S20>/Data Store Read1' */
  real_T DataStoreRead_mq[500];        /* '<S20>/Data Store Read' */
  real_T I1_m;                         /* '<S20>/I1' */
  real_T DataStoreRead1_gx[500];       /* '<S19>/Data Store Read1' */
  real_T DataStoreRead_ib[500];        /* '<S19>/Data Store Read' */
  real_T I1_f;                         /* '<S19>/I1' */
  real_T DataStoreRead1_kh[500];       /* '<S18>/Data Store Read1' */
  real_T DataStoreRead_iv[500];        /* '<S18>/Data Store Read' */
  real_T I1_a;                         /* '<S18>/I1' */
  real_T DataStoreRead1_fq[500];       /* '<S17>/Data Store Read1' */
  real_T DataStoreRead_ne[500];        /* '<S17>/Data Store Read' */
  real_T I1_ku;                        /* '<S17>/I1' */
  uint8_T Compare;                     /* '<S40>/Compare' */
  uint8_T Compare_g[11];               /* '<S56>/Compare' */
  uint8_T Compare_n;                   /* '<S58>/Compare' */
  uint8_T Compare_f;                   /* '<S79>/Compare' */
  uint8_T Compare_i;                   /* '<S75>/Compare' */
  uint8_T Compare_gb[11];              /* '<S57>/Compare' */
  uint8_T Compare_j;                   /* '<S60>/Compare' */
  boolean_T RelationalOperator_a;      /* '<S4>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S4>/Relational Operator1' */
  boolean_T RelationalOperator_f;      /* '<S14>/Relational Operator' */
  boolean_T RelationalOperator_ar;     /* '<S44>/Relational Operator' */
  boolean_T RelationalOperator1_h;     /* '<S44>/Relational Operator1' */
  boolean_T RelationalOperator_b;      /* '<S59>/Relational Operator' */
  boolean_T RelationalOperator_l;      /* '<S46>/Relational Operator' */
  boolean_T RelationalOperator_n;      /* '<S80>/Relational Operator' */
  boolean_T RelationalOperator_k;      /* '<S76>/Relational Operator' */
  boolean_T RelationalOperator_hq;     /* '<S73>/Relational Operator' */
  boolean_T RelationalOperator_e;      /* '<S74>/Relational Operator' */
  boolean_T LogicalOperator[11];       /* '<S43>/Logical Operator' */
  boolean_T RelationalOperator_c;      /* '<S61>/Relational Operator' */
  boolean_T RelationalOperator_k1;     /* '<S47>/Relational Operator' */
} BlockIO_t15_2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S41>/UD' */
  real_T UD_DSTATE_d;                  /* '<S42>/UD' */
  real_T Divcontr_DSTATE[32];          /* '<S8>/Div. contr.' */
  real_T Div_rdcontr_DSTATE[22];       /* '<S8>/Div_rd contr' */
  real_T Currtermcontr_DSTATE[22];     /* '<S8>/Curr. term. contr' */
  real_T Limcontr_DSTATE[46];          /* '<S45>/Lim. contr.' */
  real_T Currcontr_DSTATE[11];         /* '<S45>/Curr. contr.' */
  real_T UD_DSTATE_c;                  /* '<S78>/UD' */
  real_T VScontr_DSTATE[9];            /* '<S48>/VS. contr' */
  real_T VScontrhl_DSTATE[8];          /* '<S48>/VS. contr hl' */
  real_T UD_DSTATE_g;                  /* '<S5>/UD' */
  real_T SFunction_DSTATE[20];         /* '<S2>/S-Function' */
  real_T Memory2_PreviousInput;        /* '<S4>/Memory2' */
  real_T Memory2_PreviousInput_n;      /* '<S13>/Memory2' */
  real_T Memory1_PreviousInput;        /* '<S13>/Memory1' */
  real_T Memory1_PreviousInput_k;      /* '<S11>/Memory1' */
  real_T Memory2_PreviousInput_j;      /* '<S20>/Memory2' */
  real_T Memory2_PreviousInput_a;      /* '<S18>/Memory2' */
  real_T Memory2_PreviousInput_p;      /* '<S19>/Memory2' */
  real_T Memory2_PreviousInput_f;      /* '<S21>/Memory2' */
  real_T Memory2_PreviousInput_m;      /* '<S17>/Memory2' */
  real_T Memory2_PreviousInput_l;      /* '<S22>/Memory2' */
  real_T Memory2_PreviousInput_ai;     /* '<S23>/Memory2' */
  real_T Memory2_PreviousInput_h;      /* '<S24>/Memory2' */
  real_T Memory2_PreviousInput_fw;     /* '<S25>/Memory2' */
  real_T Memory2_PreviousInput_c;      /* '<S26>/Memory2' */
  real_T Memory2_PreviousInput_b;      /* '<S27>/Memory2' */
  real_T Memory2_PreviousInput_i;      /* '<S33>/Memory2' */
  real_T Memory1_PreviousInput_j;      /* '<S33>/Memory1' */
  real_T Memory2_PreviousInput_g;      /* '<S28>/Memory2' */
  real_T Memory1_PreviousInput_e;      /* '<S28>/Memory1' */
  real_T Memory2_PreviousInput_hx;     /* '<S29>/Memory2' */
  real_T Memory1_PreviousInput_b;      /* '<S29>/Memory1' */
  real_T Memory2_PreviousInput_mc;     /* '<S30>/Memory2' */
  real_T Memory1_PreviousInput_c;      /* '<S30>/Memory1' */
  real_T Memory2_PreviousInput_gn;     /* '<S31>/Memory2' */
  real_T Memory1_PreviousInput_p;      /* '<S31>/Memory1' */
  real_T Memory2_PreviousInput_hxw;    /* '<S32>/Memory2' */
  real_T Memory1_PreviousInput_eu;     /* '<S32>/Memory1' */
  real_T Memory1_PreviousInput_a[11];  /* '<S44>/Memory1' */
  real_T Memory_PreviousInput[11];     /* '<S46>/Memory' */
  real_T Memory3_PreviousInput;        /* '<S55>/Memory3' */
  real_T Memory1_PreviousInput_g;      /* '<S53>/Memory1' */
  real_T Memory1_PreviousInput_m;      /* '<S51>/Memory1' */
  real_T Memory1_PreviousInput_jm;     /* '<S52>/Memory1' */
  real_T Memory2_PreviousInput_la[11]; /* '<S45>/Memory2' */
  real_T Sum3_DWORK1[11];              /* '<S43>/Sum3' */
  real_T UniformRandomNumber_NextOutput;/* '<S54>/Uniform Random Number' */
  real_T scr_data[6500];               /* '<S4>/Data Store Memory' */
  real_T volt[10000];                  /* '<S4>/Data Store Memory1' */
  real_T RupRd[6];                     /* '<S4>/Data Store Memory2' */
  real_T Memory1_PreviousInput_jb[11]; /* '<S6>/Memory1' */
  uint32_T RandSeed;                   /* '<S54>/Uniform Random Number' */
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
  real_T Constant_Value;               /* Expression: trd_ref
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: trd_ref
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: trd_ref
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: trd_ref
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant_Value_at;            /* Expression: trd_ref
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Constant_Value_hm;            /* Expression: trd_ref
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T k_gaplim_Gain[4];             /* Expression: k_gaplim
                                        * Referenced by: '<S7>/k_gaplim'
                                        */
  real_T zeros21_Value[2];             /* Expression: zeros(2,1)
                                        * Referenced by: '<S8>/zeros(2,1)'
                                        */
  real_T e3_Gain;                      /* Expression: 2e3
                                        * Referenced by: '<S77>/2e3'
                                        */
  real_T u5_Gain;                      /* Expression: 1.75
                                        * Referenced by: '<S77>/1.75'
                                        */
  real_T y0_Value;                     /* Expression: y0
                                        * Referenced by: '<S51>/y0'
                                        */
  real_T uy0_Value;                    /* Expression: (1-y0)/(c2_y0-c1_y0)
                                        * Referenced by: '<S51>/(1-y0)//...'
                                        */
  real_T c1_y0_Value;                  /* Expression: c1_y0
                                        * Referenced by: '<S51>/c1_y0'
                                        */
  real_T uy0_UpperSat;                 /* Expression: 1
                                        * Referenced by: '<S51>/[1 y0]'
                                        */
  real_T uy0_LowerSat;                 /* Expression: y0
                                        * Referenced by: '<S51>/[1 y0]'
                                        */
  real_T atpl2_Gain;                   /* Expression: c_a_tpl2/15
                                        * Referenced by: '<S8>/atpl2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T _Value;                       /* Expression: 1
                                        * Referenced by: '<S53>/1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1/ref_ramp
                                        * Referenced by: '<S53>/Gain1'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 1
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: 0
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T c_eob_Threshold;              /* Expression: 0.9999
                                        * Referenced by: '<S8>/c_eob'
                                        */
  real_T zeros201_Value[20];           /* Expression: zeros(20,1)
                                        * Referenced by: '<S45>/zeros(20,1)'
                                        */
  real_T ntur_Gain[11];                /* Expression: 1./ntur(1:n_mc)
                                        * Referenced by: '<S45>/1//ntur '
                                        */
  real_T gain_cont2_XData[4];          /* Expression: tgain_cont2
                                        * Referenced by: '<S45>/gain_cont2'
                                        */
  real_T gain_cont2_YData[4];          /* Expression: gain_cont2
                                        * Referenced by: '<S45>/gain_cont2'
                                        */
  real_T tcont2_Threshold;             /* Expression: tcont2
                                        * Referenced by: '<S45>/tcont2'
                                        */
  real_T u5_Gain_k;                    /* Expression: 1/15
                                        * Referenced by: '<S8>/1//15'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S8>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: c_a_tpl_min
                                        * Referenced by: '<S8>/Saturation3'
                                        */
  real_T SatLim_UpperSat;              /* Expression: max_a_tpl1_lim
                                        * Referenced by: '<S50>/Sat. Lim'
                                        */
  real_T SatLim_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S50>/Sat. Lim'
                                        */
  real_T SatDiv_UpperSat;              /* Expression: max_a_tpl1_div
                                        * Referenced by: '<S50>/Sat. Div'
                                        */
  real_T SatDiv_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S50>/Sat. Div'
                                        */
  real_T IpIp_div_Threshold;           /* Expression: Ip_div
                                        * Referenced by: '<S50>/Ip>Ip_div'
                                        */
  real_T c_eob_Threshold_f;            /* Expression: 0.9999
                                        * Referenced by: '<S8>/c_eob '
                                        */
  real_T c_a_tpl1_eob15_Gain;          /* Expression: c_a_tpl1_eob/15
                                        * Referenced by: '<S8>/c_a_tpl1_eob//15'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S8>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: c_a_tpl_min
                                        * Referenced by: '<S8>/Saturation4'
                                        */
  real_T SFunction1_P1_Size[2];        /* Computed Parameter: SFunction1_P1_Size
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  real_T SFunction1_P1;                /* Expression: 1
                                        * Referenced by: '<S4>/S-Function1'
                                        */
  real_T SFunction2_P1_Size[2];        /* Computed Parameter: SFunction2_P1_Size
                                        * Referenced by: '<S4>/S-Function2'
                                        */
  real_T SFunction2_P1;                /* Expression: 12
                                        * Referenced by: '<S4>/S-Function2'
                                        */
  real_T e3_Gain_d;                    /* Expression: 1e-3
                                        * Referenced by: '<S4>/1e-3'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T u_Gain;                       /* Expression: -1
                                        * Referenced by: '<S4>/-1'
                                        */
  real_T Ip1e4_Threshold;              /* Expression: -1e-4
                                        * Referenced by: '<S4>/Ip<1e-4 '
                                        */
  real_T Time_stop_Value;              /* Expression: Time_stop
                                        * Referenced by: '<S4>/Time_stop'
                                        */
  real_T e6_Gain;                      /* Expression: 1e-6
                                        * Referenced by: '<S7>/1e-6'
                                        */
  real_T e6_Gain_m;                    /* Expression: 1e-6
                                        * Referenced by: '<S7>/1e-6   '
                                        */
  real_T Memory2_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S13>/Memory2'
                                        */
  real_T nturn_CS1_Gain;               /* Expression: ntur(3)*1e-3
                                        * Referenced by: '<S13>/nturn_CS1'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S13>/Memory1'
                                        */
  real_T u99_Threshold;                /* Expression: 0.999
                                        * Referenced by: '<S13>/0.999'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S13>/Constant4'
                                        */
  real_T u_UpperSat;                   /* Expression: 1
                                        * Referenced by: '<S13>/1 0'
                                        */
  real_T u_LowerSat;                   /* Expression: 0
                                        * Referenced by: '<S13>/1 0'
                                        */
  real_T Memory1_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S11>/Memory1'
                                        */
  real_T c_eob_Threshold_fd;           /* Expression: 0.9999
                                        * Referenced by: '<S11>/c_eob'
                                        */
  real_T SFunction1_P1_Size_h[2];      /* Computed Parameter: SFunction1_P1_Size_h
                                        * Referenced by: '<S16>/S-Function1'
                                        */
  real_T SFunction1_P1_i;              /* Expression: 0
                                        * Referenced by: '<S16>/S-Function1'
                                        */
  real_T Constant4_Value_o;            /* Expression: 0
                                        * Referenced by: '<S7>/Constant4'
                                        */
  real_T Memory2_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S20>/Memory2'
                                        */
  real_T c_eob_Threshold_l;            /* Expression: 0.9999
                                        * Referenced by: '<S20>/c_eob'
                                        */
  real_T Memory2_X0_l;                 /* Expression: 0
                                        * Referenced by: '<S18>/Memory2'
                                        */
  real_T c_eob_Threshold_b;            /* Expression: 0.9999
                                        * Referenced by: '<S18>/c_eob'
                                        */
  real_T Memory2_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S19>/Memory2'
                                        */
  real_T c_eob_Threshold_h;            /* Expression: 0.9999
                                        * Referenced by: '<S19>/c_eob'
                                        */
  real_T Memory2_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S21>/Memory2'
                                        */
  real_T c_eob_Threshold_e;            /* Expression: 0.9999
                                        * Referenced by: '<S21>/c_eob'
                                        */
  real_T Memory2_X0_gg;                /* Expression: 0
                                        * Referenced by: '<S17>/Memory2'
                                        */
  real_T c_eob_Threshold_m;            /* Expression: 0.9999
                                        * Referenced by: '<S17>/c_eob'
                                        */
  real_T Memory2_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S22>/Memory2'
                                        */
  real_T c_eob_Threshold_i;            /* Expression: 0.9999
                                        * Referenced by: '<S22>/c_eob'
                                        */
  real_T Memory2_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S23>/Memory2'
                                        */
  real_T c_eob_Threshold_hk;           /* Expression: 0.9999
                                        * Referenced by: '<S23>/c_eob'
                                        */
  real_T Memory2_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S24>/Memory2'
                                        */
  real_T c_eob_Threshold_j;            /* Expression: 0.9999
                                        * Referenced by: '<S24>/c_eob'
                                        */
  real_T Memory2_X0_bq;                /* Expression: 0
                                        * Referenced by: '<S25>/Memory2'
                                        */
  real_T c_eob_Threshold_a;            /* Expression: 0.9999
                                        * Referenced by: '<S25>/c_eob'
                                        */
  real_T Memory2_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S26>/Memory2'
                                        */
  real_T c_eob_Threshold_d;            /* Expression: 0.9999
                                        * Referenced by: '<S26>/c_eob'
                                        */
  real_T Memory2_X0_ll;                /* Expression: 0
                                        * Referenced by: '<S27>/Memory2'
                                        */
  real_T c_eob_Threshold_p;            /* Expression: 0.9999
                                        * Referenced by: '<S27>/c_eob'
                                        */
  real_T u_Threshold;                  /* Expression: 0
                                        * Referenced by: '<S9>/>=0'
                                        */
  real_T e2_Gain;                      /* Expression: 1e2
                                        * Referenced by: '<S12>/1e2'
                                        */
  real_T SFunction1_P1_Size_b[2];      /* Computed Parameter: SFunction1_P1_Size_b
                                        * Referenced by: '<S33>/S-Function1'
                                        */
  real_T SFunction1_P1_g;              /* Expression: 1
                                        * Referenced by: '<S33>/S-Function1'
                                        */
  real_T Memory2_X0_pl;                /* Expression: 0
                                        * Referenced by: '<S33>/Memory2'
                                        */
  real_T c_eob1_Threshold;             /* Expression: 0.9999
                                        * Referenced by: '<S33>/c_eob  1'
                                        */
  real_T Memory1_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S33>/Memory1'
                                        */
  real_T c_eob_Threshold_a1;           /* Expression: 0.9999
                                        * Referenced by: '<S33>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_f[2];      /* Computed Parameter: SFunction1_P1_Size_f
                                        * Referenced by: '<S39>/S-Function1'
                                        */
  real_T SFunction1_P1_go;             /* Expression: 1
                                        * Referenced by: '<S39>/S-Function1'
                                        */
  real_T c_eob_Threshold_ji;           /* Expression: 0.9999
                                        * Referenced by: '<S33>/c_eob'
                                        */
  real_T LookupTable1_XData[4];        /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S12>/Lookup Table1'
                                        */
  real_T LookupTable1_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S12>/Lookup Table1'
                                        */
  real_T SFunction1_P1_Size_g[2];      /* Computed Parameter: SFunction1_P1_Size_g
                                        * Referenced by: '<S28>/S-Function1'
                                        */
  real_T SFunction1_P1_e;              /* Expression: 2
                                        * Referenced by: '<S28>/S-Function1'
                                        */
  real_T Memory2_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S28>/Memory2'
                                        */
  real_T c_eob1_Threshold_c;           /* Expression: 0.9999
                                        * Referenced by: '<S28>/c_eob  1'
                                        */
  real_T Memory1_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S28>/Memory1'
                                        */
  real_T c_eob_Threshold_k;            /* Expression: 0.9999
                                        * Referenced by: '<S28>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_i[2];      /* Computed Parameter: SFunction1_P1_Size_i
                                        * Referenced by: '<S34>/S-Function1'
                                        */
  real_T SFunction1_P1_a;              /* Expression: 2
                                        * Referenced by: '<S34>/S-Function1'
                                        */
  real_T c_eob_Threshold_c;            /* Expression: 0.9999
                                        * Referenced by: '<S28>/c_eob'
                                        */
  real_T LookupTable2_XData[4];        /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S12>/Lookup Table2'
                                        */
  real_T LookupTable2_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S12>/Lookup Table2'
                                        */
  real_T SFunction1_P1_Size_b0[2];     /* Computed Parameter: SFunction1_P1_Size_b0
                                        * Referenced by: '<S29>/S-Function1'
                                        */
  real_T SFunction1_P1_a5;             /* Expression: 3
                                        * Referenced by: '<S29>/S-Function1'
                                        */
  real_T Memory2_X0_a5;                /* Expression: 0
                                        * Referenced by: '<S29>/Memory2'
                                        */
  real_T c_eob1_Threshold_p;           /* Expression: 0.9999
                                        * Referenced by: '<S29>/c_eob  1'
                                        */
  real_T Memory1_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S29>/Memory1'
                                        */
  real_T c_eob_Threshold_lp;           /* Expression: 0.9999
                                        * Referenced by: '<S29>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_e[2];      /* Computed Parameter: SFunction1_P1_Size_e
                                        * Referenced by: '<S35>/S-Function1'
                                        */
  real_T SFunction1_P1_o;              /* Expression: 3
                                        * Referenced by: '<S35>/S-Function1'
                                        */
  real_T c_eob_Threshold_io;           /* Expression: 0.9999
                                        * Referenced by: '<S29>/c_eob'
                                        */
  real_T SFunction1_P1_Size_bz[2];     /* Computed Parameter: SFunction1_P1_Size_bz
                                        * Referenced by: '<S30>/S-Function1'
                                        */
  real_T SFunction1_P1_oj;             /* Expression: 4
                                        * Referenced by: '<S30>/S-Function1'
                                        */
  real_T Memory2_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S30>/Memory2'
                                        */
  real_T c_eob1_Threshold_d;           /* Expression: 0.9999
                                        * Referenced by: '<S30>/c_eob  1'
                                        */
  real_T Memory1_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S30>/Memory1'
                                        */
  real_T c_eob_Threshold_h3;           /* Expression: 0.9999
                                        * Referenced by: '<S30>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_k[2];      /* Computed Parameter: SFunction1_P1_Size_k
                                        * Referenced by: '<S36>/S-Function1'
                                        */
  real_T SFunction1_P1_k;              /* Expression: 4
                                        * Referenced by: '<S36>/S-Function1'
                                        */
  real_T c_eob_Threshold_iy;           /* Expression: 0.9999
                                        * Referenced by: '<S30>/c_eob'
                                        */
  real_T LookupTable3_XData[4];        /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S12>/Lookup Table3'
                                        */
  real_T LookupTable3_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S12>/Lookup Table3'
                                        */
  real_T SFunction1_P1_Size_c[2];      /* Computed Parameter: SFunction1_P1_Size_c
                                        * Referenced by: '<S31>/S-Function1'
                                        */
  real_T SFunction1_P1_l;              /* Expression: 5
                                        * Referenced by: '<S31>/S-Function1'
                                        */
  real_T Memory2_X0_er;                /* Expression: 0
                                        * Referenced by: '<S31>/Memory2'
                                        */
  real_T c_eob1_Threshold_e;           /* Expression: 0.9999
                                        * Referenced by: '<S31>/c_eob  1'
                                        */
  real_T Memory1_X0_nj;                /* Expression: 0
                                        * Referenced by: '<S31>/Memory1'
                                        */
  real_T c_eob_Threshold_o;            /* Expression: 0.9999
                                        * Referenced by: '<S31>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_cg[2];     /* Computed Parameter: SFunction1_P1_Size_cg
                                        * Referenced by: '<S37>/S-Function1'
                                        */
  real_T SFunction1_P1_j;              /* Expression: 5
                                        * Referenced by: '<S37>/S-Function1'
                                        */
  real_T c_eob_Threshold_e4;           /* Expression: 0.9999
                                        * Referenced by: '<S31>/c_eob'
                                        */
  real_T SFunction1_P1_Size_cc[2];     /* Computed Parameter: SFunction1_P1_Size_cc
                                        * Referenced by: '<S32>/S-Function1'
                                        */
  real_T SFunction1_P1_m;              /* Expression: 6
                                        * Referenced by: '<S32>/S-Function1'
                                        */
  real_T Memory2_X0_bw;                /* Expression: 0
                                        * Referenced by: '<S32>/Memory2'
                                        */
  real_T c_eob1_Threshold_h;           /* Expression: 0.9999
                                        * Referenced by: '<S32>/c_eob  1'
                                        */
  real_T Memory1_X0_jd;                /* Expression: 0
                                        * Referenced by: '<S32>/Memory1'
                                        */
  real_T c_eob_Threshold_ey;           /* Expression: 0.9999
                                        * Referenced by: '<S32>/c_eob  '
                                        */
  real_T SFunction1_P1_Size_e2[2];     /* Computed Parameter: SFunction1_P1_Size_e2
                                        * Referenced by: '<S38>/S-Function1'
                                        */
  real_T SFunction1_P1_b;              /* Expression: 6
                                        * Referenced by: '<S38>/S-Function1'
                                        */
  real_T c_eob_Threshold_eg;           /* Expression: 0.9999
                                        * Referenced by: '<S32>/c_eob'
                                        */
  real_T e2_Gain_h;                    /* Expression: 1e-2
                                        * Referenced by: '<S12>/1e-2'
                                        */
  real_T e6_Gain_d;                    /* Expression: 1e6
                                        * Referenced by: '<S13>/1e6'
                                        */
  real_T Constant_Value_hp;            /* Expression: const
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T u9_Threshold;                 /* Expression: 0.99
                                        * Referenced by: '<S14>/0.99'
                                        */
  real_T UD_InitialCondition;          /* Expression: ICPrevInput
                                        * Referenced by: '<S41>/UD'
                                        */
  real_T UD_InitialCondition_h;        /* Expression: ICPrevInput
                                        * Referenced by: '<S42>/UD'
                                        */
  real_T e3_Gain_o;                    /* Expression: 1e3
                                        * Referenced by: '<S43>/1e3'
                                        */
  real_T Imax_Value[11];               /* Expression: Imax
                                        * Referenced by: '<S8>/Imax'
                                        */
  real_T ntur_Gain_e[11];              /* Expression: ntur(1:n_mc)
                                        * Referenced by: '<S43>/ntur'
                                        */
  real_T c_cur_max_Gain;               /* Expression: c_cur_max
                                        * Referenced by: '<S43>/c_cur_max'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: 1
                                        * Referenced by: '<S43>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: -1
                                        * Referenced by: '<S43>/Saturation'
                                        */
  real_T Constant_Value_m;             /* Expression: const
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T Memory1_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S44>/Memory1'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S46>/Memory'
                                        */
  real_T Constant_Value_e;             /* Expression: const
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T _Value_d;                     /* Expression: 1
                                        * Referenced by: '<S55>/1'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S55>/Memory3'
                                        */
  real_T Constant_Value_as;            /* Expression: const
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T u999_Threshold;               /* Expression: 0.9999
                                        * Referenced by: '<S55>/0.9999'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: -1/ref_ramp
                                        * Referenced by: '<S55>/Gain1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S55>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S55>/Saturation1'
                                        */
  real_T Divcontr_A[572];              /* Computed Parameter: Divcontr_A
                                        * Referenced by: '<S8>/Div. contr.'
                                        */
  real_T Divcontr_B[352];              /* Computed Parameter: Divcontr_B
                                        * Referenced by: '<S8>/Div. contr.'
                                        */
  real_T Divcontr_C[205];              /* Computed Parameter: Divcontr_C
                                        * Referenced by: '<S8>/Div. contr.'
                                        */
  real_T Divcontr_D[171];              /* Computed Parameter: Divcontr_D
                                        * Referenced by: '<S8>/Div. contr.'
                                        */
  real_T Divcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S8>/Div. contr.'
                                        */
  real_T u9_Threshold_m;               /* Expression: 0.99
                                        * Referenced by: '<S46>/0.99'
                                        */
  real_T Memory1_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S53>/Memory1'
                                        */
  real_T Constant_Value_dz;            /* Expression: const
                                        * Referenced by: '<S75>/Constant'
                                        */
  real_T u999_Threshold_k;             /* Expression: 0.9999
                                        * Referenced by: '<S53>/0.9999'
                                        */
  real_T Div_rdcontr_A[337];           /* Computed Parameter: Div_rdcontr_A
                                        * Referenced by: '<S8>/Div_rd contr'
                                        */
  real_T Div_rdcontr_B[277];           /* Computed Parameter: Div_rdcontr_B
                                        * Referenced by: '<S8>/Div_rd contr'
                                        */
  real_T Div_rdcontr_C[165];           /* Computed Parameter: Div_rdcontr_C
                                        * Referenced by: '<S8>/Div_rd contr'
                                        */
  real_T Div_rdcontr_D[198];           /* Computed Parameter: Div_rdcontr_D
                                        * Referenced by: '<S8>/Div_rd contr'
                                        */
  real_T Div_rdcontr_X0;               /* Expression: 0
                                        * Referenced by: '<S8>/Div_rd contr'
                                        */
  real_T Memory1_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S51>/Memory1'
                                        */
  real_T c_eob_Threshold_dx;           /* Expression: 0.9999
                                        * Referenced by: '<S51>/c_eob'
                                        */
  real_T u99_Threshold_b;              /* Expression: 0.999
                                        * Referenced by: '<S44>/0.999'
                                        */
  real_T Memory1_X0_g3;                /* Expression: 0
                                        * Referenced by: '<S52>/Memory1'
                                        */
  real_T u999_Threshold_o;             /* Expression: 0.9999
                                        * Referenced by: '<S52>/0.9999'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: -1/ref_ramp
                                        * Referenced by: '<S52>/Gain1'
                                        */
  real_T _Value_e;                     /* Expression: 1
                                        * Referenced by: '<S52>/1'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 1
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: 0
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real_T Currtermcontr_A[253];         /* Computed Parameter: Currtermcontr_A
                                        * Referenced by: '<S8>/Curr. term. contr'
                                        */
  real_T Currtermcontr_B[121];         /* Computed Parameter: Currtermcontr_B
                                        * Referenced by: '<S8>/Curr. term. contr'
                                        */
  real_T Currtermcontr_C[11];          /* Computed Parameter: Currtermcontr_C
                                        * Referenced by: '<S8>/Curr. term. contr'
                                        */
  real_T Currtermcontr_X0;             /* Expression: 0
                                        * Referenced by: '<S8>/Curr. term. contr'
                                        */
  real_T Memory2_X0_n3;                /* Expression: 0
                                        * Referenced by: '<S45>/Memory2'
                                        */
  real_T tcont2_Threshold_k;           /* Expression: tcont2
                                        * Referenced by: '<S45>/tcont2 '
                                        */
  real_T Limcontr_A[2116];             /* Computed Parameter: Limcontr_A
                                        * Referenced by: '<S45>/Lim. contr.'
                                        */
  real_T Limcontr_B[782];              /* Computed Parameter: Limcontr_B
                                        * Referenced by: '<S45>/Lim. contr.'
                                        */
  real_T Limcontr_C[506];              /* Computed Parameter: Limcontr_C
                                        * Referenced by: '<S45>/Lim. contr.'
                                        */
  real_T Limcontr_D[187];              /* Computed Parameter: Limcontr_D
                                        * Referenced by: '<S45>/Lim. contr.'
                                        */
  real_T Limcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S45>/Lim. contr.'
                                        */
  real_T Currcontr_A[121];             /* Computed Parameter: Currcontr_A
                                        * Referenced by: '<S45>/Curr. contr.'
                                        */
  real_T Currcontr_B[121];             /* Computed Parameter: Currcontr_B
                                        * Referenced by: '<S45>/Curr. contr.'
                                        */
  real_T Currcontr_C[121];             /* Computed Parameter: Currcontr_C
                                        * Referenced by: '<S45>/Curr. contr.'
                                        */
  real_T Currcontr_X0;                 /* Expression: 0
                                        * Referenced by: '<S45>/Curr. contr.'
                                        */
  real_T IpIp_div_Threshold_m;         /* Expression: Ip_div
                                        * Referenced by: '<S45>/Ip>Ip_div '
                                        */
  real_T u01_Gain;                     /* Expression: 1e-3
                                        * Referenced by: '<S62>/0.001'
                                        */
  real_T u01_Gain_d;                   /* Expression: 1e-3
                                        * Referenced by: '<S65>/0.001'
                                        */
  real_T u01_Gain_h;                   /* Expression: 1e-3
                                        * Referenced by: '<S66>/0.001'
                                        */
  real_T u01_Gain_c;                   /* Expression: 1e-3
                                        * Referenced by: '<S67>/0.001'
                                        */
  real_T u01_Gain_n;                   /* Expression: 1e-3
                                        * Referenced by: '<S68>/0.001'
                                        */
  real_T u01_Gain_j;                   /* Expression: 1e-3
                                        * Referenced by: '<S69>/0.001'
                                        */
  real_T u01_Gain_m;                   /* Expression: 1e-3
                                        * Referenced by: '<S70>/0.001'
                                        */
  real_T u01_Gain_b;                   /* Expression: 1e-3
                                        * Referenced by: '<S71>/0.001'
                                        */
  real_T u01_Gain_o;                   /* Expression: 1e-3
                                        * Referenced by: '<S72>/0.001'
                                        */
  real_T u01_Gain_mx;                  /* Expression: 1e-3
                                        * Referenced by: '<S63>/0.001'
                                        */
  real_T u01_Gain_du;                  /* Expression: 1e-3
                                        * Referenced by: '<S64>/0.001'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T Saturation1_UpperSat_p;       /* Expression: 1
                                        * Referenced by: '<S43>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_g;       /* Expression: -1
                                        * Referenced by: '<S43>/Saturation1'
                                        */
  real_T UniformRandomNumber_Minimum;  /* Expression: -1
                                        * Referenced by: '<S54>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 1
                                        * Referenced by: '<S54>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S54>/Uniform Random Number'
                                        */
  real_T UD_InitialCondition_o;        /* Expression: ICPrevInput
                                        * Referenced by: '<S78>/UD'
                                        */
  real_T tt_tran2d_Threshold;          /* Expression: t_tran2D
                                        * Referenced by: '<S8>/t>t_tran2d'
                                        */
  real_T VScontr_A[34];                /* Computed Parameter: VScontr_A
                                        * Referenced by: '<S48>/VS. contr'
                                        */
  real_T VScontr_B[16];                /* Computed Parameter: VScontr_B
                                        * Referenced by: '<S48>/VS. contr'
                                        */
  real_T VScontr_C[10];                /* Computed Parameter: VScontr_C
                                        * Referenced by: '<S48>/VS. contr'
                                        */
  real_T VScontr_D[4];                 /* Computed Parameter: VScontr_D
                                        * Referenced by: '<S48>/VS. contr'
                                        */
  real_T VScontr_X0;                   /* Expression: 0
                                        * Referenced by: '<S48>/VS. contr'
                                        */
  real_T c_eob_Value;                  /* Expression: 0.9999
                                        * Referenced by: '<S48>/c_eob '
                                        */
  real_T VScontrhl_A[33];              /* Computed Parameter: VScontrhl_A
                                        * Referenced by: '<S48>/VS. contr hl'
                                        */
  real_T VScontrhl_B[15];              /* Computed Parameter: VScontrhl_B
                                        * Referenced by: '<S48>/VS. contr hl'
                                        */
  real_T VScontrhl_C[9];               /* Computed Parameter: VScontrhl_C
                                        * Referenced by: '<S48>/VS. contr hl'
                                        */
  real_T VScontrhl_D[4];               /* Computed Parameter: VScontrhl_D
                                        * Referenced by: '<S48>/VS. contr hl'
                                        */
  real_T VScontrhl_X0;                 /* Expression: 0
                                        * Referenced by: '<S48>/VS. contr hl'
                                        */
  real_T c_eob_Threshold_jn;           /* Expression: 0.9999
                                        * Referenced by: '<S48>/c_eob'
                                        */
  real_T Constant_Value_o;             /* Expression: const
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T atpl115_Gain;                 /* Expression: c_a_tpl1/15
                                        * Referenced by: '<S50>/atpl1//15'
                                        */
  real_T u9_Threshold_mz;              /* Expression: 0.99
                                        * Referenced by: '<S47>/0.99'
                                        */
  real_T ntur_Gain_d[11];              /* Expression: 1./ntur(1:n_mc)*1e6
                                        * Referenced by: '<S45>/1//ntur'
                                        */
  real_T ntur_Gain_e4[11];             /* Expression: ntur(1:n_mc)
                                        * Referenced by: '<S4>/ntur'
                                        */
  real_T DataStoreMemory_InitialValue[6500];/* Expression: zeros(13,500)
                                             * Referenced by: '<S4>/Data Store Memory'
                                             */
  real_T DataStoreMemory1_InitialValue[10000];/* Expression: zeros(20,500)
                                               * Referenced by: '<S4>/Data Store Memory1'
                                               */
  real_T DataStoreMemory2_InitialValue[6];/* Expression: zeros(6,1)
                                           * Referenced by: '<S4>/Data Store Memory2'
                                           */
  real_T Memory1_X0_ja;                /* Expression: 0
                                        * Referenced by: '<S6>/Memory1'
                                        */
  real_T UD_InitialCondition_d;        /* Expression: ICPrevInput
                                        * Referenced by: '<S5>/UD'
                                        */
  real_T Gain1_Gain_k[220];            /* Expression: eye(20,n_mc)
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T SFunction_P1;                 /* Expression: n_mc
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T SFunction_P2[20];             /* Expression: Tf
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T Gain2_Gain[220];              /* Expression: eye(n_mc,20)
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Ratemc_UpperSat[11];          /* Expression: Ratemc_up
                                        * Referenced by: '<S6>/Ratemc'
                                        */
  real_T Ratemc_LowerSat[11];          /* Expression: Ratemc_low
                                        * Referenced by: '<S6>/Ratemc'
                                        */
  real_T Vmc_sat_UpperSat[11];         /* Expression: Vmc_up
                                        * Referenced by: '<S6>/Vmc_sat'
                                        */
  real_T Vmc_sat_LowerSat[11];         /* Expression: Vmc_low
                                        * Referenced by: '<S6>/Vmc_sat'
                                        */
  real_T ntur_Gain_n[11];              /* Expression: 1./ntur(1:n_mc)
                                        * Referenced by: '<S1>/1//ntur'
                                        */
  real_T SaturationVS1_UpperSat;       /* Expression: VS1_up
                                        * Referenced by: '<S3>/Saturation VS1'
                                        */
  real_T SaturationVS1_LowerSat;       /* Expression: VS1_low
                                        * Referenced by: '<S3>/Saturation VS1'
                                        */
  real_T SaturationVS3_UpperSat;       /* Expression: VS3_up
                                        * Referenced by: '<S3>/Saturation VS3'
                                        */
  real_T SaturationVS3_LowerSat;       /* Expression: VS3_low
                                        * Referenced by: '<S3>/Saturation VS3'
                                        */
  real_T wz_Gain[24];                  /* Expression: wz
                                        * Referenced by: '<S1>/wz'
                                        */
  real_T npf12_Gain[180];              /* Expression: eye(npf,n_mc+1)
                                        * Referenced by: '<S1>/npf,12'
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
      struct _ssPortInputs inputPortInfo[2];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
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
 * Block '<S1>/To Workspace1' : Unused code path elimination
 * Block '<S1>/To Workspace2' : Unused code path elimination
 * Block '<S1>/To Workspace3' : Unused code path elimination
 * Block '<Root>/Time' : Unused code path elimination
 * Block '<S4>/A' : Unused code path elimination
 * Block '<S4>/A  ' : Unused code path elimination
 * Block '<S7>/To Workspace1' : Unused code path elimination
 * Block '<S7>/To Workspace2' : Unused code path elimination
 * Block '<S7>/To Workspace3' : Unused code path elimination
 * Block '<S8>/To Workspace' : Unused code path elimination
 * Block '<S4>/To Workspace21' : Unused code path elimination
 * Block '<S4>/To Workspace5' : Unused code path elimination
 * Block '<S4>/To Workspace7' : Unused code path elimination
 * Block '<S4>/klim' : Unused code path elimination
 * Block '<S4>/m' : Unused code path elimination
 * Block '<S4>/m  ' : Unused code path elimination
 * Block '<S4>/m   ' : Unused code path elimination
 * Block '<S4>/rsep' : Unused code path elimination
 * Block '<S4>/rsep1' : Unused code path elimination
 * Block '<S4>/xleft' : Unused code path elimination
 * Block '<S4>/xright' : Unused code path elimination
 * Block '<S4>/zsep' : Unused code path elimination
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
 * '<S1>'   : 't15_2/Commutation for Dina'
 * '<S2>'   : 't15_2/Pow. Supply MC 1'
 * '<S3>'   : 't15_2/Pow. Supply VS1,3'
 * '<S4>'   : 't15_2/kavin_contr'
 * '<S5>'   : 't15_2/Pow. Supply MC 1/Difference'
 * '<S6>'   : 't15_2/Pow. Supply MC 1/Pow. Supply MC 1'
 * '<S7>'   : 't15_2/kavin_contr/Control inputs 1'
 * '<S8>'   : 't15_2/kavin_contr/Control2'
 * '<S9>'   : 't15_2/kavin_contr/Subsystem'
 * '<S10>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref'
 * '<S11>'  : 't15_2/kavin_contr/Control inputs 1/Ipl ref'
 * '<S12>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem'
 * '<S13>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem1'
 * '<S14>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem4'
 * '<S15>'  : 't15_2/kavin_contr/Control inputs 1/dZ//dt'
 * '<S16>'  : 't15_2/kavin_contr/Control inputs 1/elong_ref'
 * '<S17>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil1 ref'
 * '<S18>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil10 ref'
 * '<S19>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil11 ref'
 * '<S20>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil2 ref'
 * '<S21>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil3 ref'
 * '<S22>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil4 ref'
 * '<S23>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil5 ref'
 * '<S24>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil6 ref'
 * '<S25>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil7 ref'
 * '<S26>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil8 ref'
 * '<S27>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil9 ref'
 * '<S28>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem1'
 * '<S29>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem2'
 * '<S30>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem3'
 * '<S31>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem4'
 * '<S32>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem5'
 * '<S33>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem6'
 * '<S34>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem1/g2_term,ref'
 * '<S35>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem2/g3_term,ref'
 * '<S36>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem3/g4_term,ref'
 * '<S37>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem4/g5_term,ref'
 * '<S38>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem5/g6_term,ref'
 * '<S39>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem6/g1_term,ref'
 * '<S40>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem4/Compare To Constant'
 * '<S41>'  : 't15_2/kavin_contr/Control inputs 1/dZ//dt/Difference'
 * '<S42>'  : 't15_2/kavin_contr/Control inputs 1/dZ//dt/Difference1'
 * '<S43>'  : 't15_2/kavin_contr/Control2/Curr. satur.'
 * '<S44>'  : 't15_2/kavin_contr/Control2/Subsystem'
 * '<S45>'  : 't15_2/kavin_contr/Control2/Subsystem10'
 * '<S46>'  : 't15_2/kavin_contr/Control2/Subsystem7'
 * '<S47>'  : 't15_2/kavin_contr/Control2/Subsystem8'
 * '<S48>'  : 't15_2/kavin_contr/Control2/Subsystem9'
 * '<S49>'  : 't15_2/kavin_contr/Control2/Volt'
 * '<S50>'  : 't15_2/kavin_contr/Control2/atpl'
 * '<S51>'  : 't15_2/kavin_contr/Control2/atpl2 eob1'
 * '<S52>'  : 't15_2/kavin_contr/Control2/div_curr'
 * '<S53>'  : 't15_2/kavin_contr/Control2/div_divrd'
 * '<S54>'  : 't15_2/kavin_contr/Control2/dzdt noise'
 * '<S55>'  : 't15_2/kavin_contr/Control2/lim_div_tr'
 * '<S56>'  : 't15_2/kavin_contr/Control2/Curr. satur./Compare To Constant'
 * '<S57>'  : 't15_2/kavin_contr/Control2/Curr. satur./Compare To Zero'
 * '<S58>'  : 't15_2/kavin_contr/Control2/Subsystem7/Compare To Constant'
 * '<S59>'  : 't15_2/kavin_contr/Control2/Subsystem7/Subsystem'
 * '<S60>'  : 't15_2/kavin_contr/Control2/Subsystem8/Compare To Constant'
 * '<S61>'  : 't15_2/kavin_contr/Control2/Subsystem8/Subsystem'
 * '<S62>'  : 't15_2/kavin_contr/Control2/Volt/volt1'
 * '<S63>'  : 't15_2/kavin_contr/Control2/Volt/volt10'
 * '<S64>'  : 't15_2/kavin_contr/Control2/Volt/volt11'
 * '<S65>'  : 't15_2/kavin_contr/Control2/Volt/volt2'
 * '<S66>'  : 't15_2/kavin_contr/Control2/Volt/volt3'
 * '<S67>'  : 't15_2/kavin_contr/Control2/Volt/volt4'
 * '<S68>'  : 't15_2/kavin_contr/Control2/Volt/volt5'
 * '<S69>'  : 't15_2/kavin_contr/Control2/Volt/volt6'
 * '<S70>'  : 't15_2/kavin_contr/Control2/Volt/volt7'
 * '<S71>'  : 't15_2/kavin_contr/Control2/Volt/volt8'
 * '<S72>'  : 't15_2/kavin_contr/Control2/Volt/volt9'
 * '<S73>'  : 't15_2/kavin_contr/Control2/div_curr/Subsystem'
 * '<S74>'  : 't15_2/kavin_contr/Control2/div_curr/Subsystem1'
 * '<S75>'  : 't15_2/kavin_contr/Control2/div_divrd/Compare To Constant'
 * '<S76>'  : 't15_2/kavin_contr/Control2/div_divrd/Subsystem'
 * '<S77>'  : 't15_2/kavin_contr/Control2/dzdt noise/Subsystem'
 * '<S78>'  : 't15_2/kavin_contr/Control2/dzdt noise/Subsystem/Difference'
 * '<S79>'  : 't15_2/kavin_contr/Control2/lim_div_tr/Compare To Constant'
 * '<S80>'  : 't15_2/kavin_contr/Control2/lim_div_tr/Subsystem'
 */
#endif                                 /* RTW_HEADER_t15_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
