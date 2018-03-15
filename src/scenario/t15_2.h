/*
 * File: t15_2.h
 *
 * Code generated for Simulink model 't15_2'.
 *
 * Model version                  : 1.1137
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Wed Feb 28 17:00:10 2018
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
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_look.h"
#include "rt_look1d.h"
#include "rt_nonfinite.h"
#endif                                 /* t15_2_COMMON_INCLUDES_ */

#include "t15_2_types.h"

/* Macros for accessing real-time model data structure */
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

/* Block signals (auto storage) */
typedef struct {
  real_T u1[6500];
  real_T Memory[11];                   /* '<S2>/Memory' */
  real_T e3;                           /* '<S4>/1e-3' */
  real_T Uk1;                          /* '<S5>/UD' */
  real_T Diff;                         /* '<S5>/Diff' */
  real_T Divide[11];                   /* '<S2>/Divide' */
  real_T RateLimiter[11];              /* '<S2>/Rate Limiter' */
  real_T Gain;                         /* '<S2>/Gain' */
  real_T Divide1[11];                  /* '<S2>/Divide1' */
  real_T Saturation6[11];              /* '<S2>/Saturation6' */
  real_T ntur[11];                     /* '<S1>/1//ntur' */
  real_T e6;                           /* '<S6>/1e-6' */
  real_T LogicalOperator2;             /* '<S45>/Logical Operator2' */
  real_T Subtract4;                    /* '<S45>/Subtract4' */
  real_T UniformRandomNumber;          /* '<S47>/Uniform Random Number' */
  real_T Uk1_h;                        /* '<S34>/UD' */
  real_T Uk1_d;                        /* '<S35>/UD' */
  real_T e6_m[15];                     /* '<S6>/1e-6   ' */
  real_T tt_tran2d[2];                 /* '<S7>/t>t_tran2d' */
  real_T VScontr[2];                   /* '<S41>/VS. contr' */
  real_T Memory2;                      /* '<S12>/Memory2' */
  real_T Add3;                         /* '<S12>/Add3' */
  real_T Memory1;                      /* '<S12>/Memory1' */
  real_T Ics1_eob;                     /* '<S12>/Ics1_eob' */
  real_T Add2;                         /* '<S12>/Add2' */
  real_T dtpl_term_l;                  /* '<S12>/dtpl_term_l' */
  real_T Add1;                         /* '<S12>/Add1' */
  real_T u;                            /* '<S12>/1 0' */
  real_T RelationalOperator;           /* '<S41>/Relational Operator' */
  real_T Divide4[2];                   /* '<S41>/Divide4' */
  real_T VScontrhl[2];                 /* '<S41>/VS. contr hl' */
  real_T c_eob[2];                     /* '<S41>/c_eob' */
  real_T LogicalOperator1;             /* '<S40>/Logical Operator1' */
  real_T atpl115;                      /* '<S43>/atpl1//15' */
  real_T u9[2];                        /* '<S40>/0.99' */
  real_T Divide10[2];                  /* '<S7>/Divide10' */
  real_T SaturationVS1;                /* '<S3>/Saturation VS1' */
  real_T SaturationVS3;                /* '<S3>/Saturation VS3' */
  real_T TmpSignalConversionAtwzInport1[2];
  real_T wz[12];                       /* '<S1>/wz' */
  real_T Add1_k[11];                   /* '<S1>/Add1' */
  real_T TmpSignalConversionAtnpf12Inpor[12];
  real_T npf12[15];                    /* '<S1>/npf,12' */
  real_T Add;                          /* '<S2>/Add' */
  real_T Memory1_b[11];                /* '<S37>/Memory1' */
  real_T LogicalOperator2_g;           /* '<S37>/Logical Operator2' */
  real_T Memory_l[11];                 /* '<S39>/Memory' */
  real_T LogicalOperator1_b;           /* '<S39>/Logical Operator1' */
  real_T Memory3;                      /* '<S48>/Memory3' */
  real_T LogicalOperator1_e;           /* '<S48>/Logical Operator1' */
  real_T u999;                         /* '<S48>/0.9999' */
  real_T Subtract2;                    /* '<S48>/Subtract2' */
  real_T Gain1;                        /* '<S48>/Gain1' */
  real_T Subtract1;                    /* '<S48>/Subtract1' */
  real_T Saturation1;                  /* '<S48>/Saturation1' */
  real_T Sum2;                         /* '<S8>/Sum2' */
  real_T u_i;                          /* '<S8>/>=0' */
  real_T e2[6];                        /* '<S11>/1e2' */
  real_T Memory1_k;                    /* '<S26>/Memory1' */
  real_T c_eob_l;                      /* '<S26>/c_eob  ' */
  real_T c_eob_n;                      /* '<S26>/c_eob' */
  real_T Add2_m;                       /* '<S11>/Add2' */
  real_T LookupTable1;                 /* '<S11>/Lookup Table1' */
  real_T Divide6;                      /* '<S11>/Divide6' */
  real_T Memory1_m;                    /* '<S27>/Memory1' */
  real_T c_eob_p;                      /* '<S27>/c_eob ' */
  real_T c_eob_o;                      /* '<S27>/c_eob' */
  real_T Add1_o;                       /* '<S11>/Add1' */
  real_T LookupTable2;                 /* '<S11>/Lookup Table2' */
  real_T Divide1_h;                    /* '<S11>/Divide1' */
  real_T Memory1_f;                    /* '<S28>/Memory1' */
  real_T c_eob_p2;                     /* '<S28>/c_eob ' */
  real_T c_eob_g;                      /* '<S28>/c_eob' */
  real_T Add3_j;                       /* '<S11>/Add3' */
  real_T Memory1_fr;                   /* '<S29>/Memory1' */
  real_T c_eob_ln;                     /* '<S29>/c_eob  ' */
  real_T c_eob_pr;                     /* '<S29>/c_eob' */
  real_T Add4;                         /* '<S11>/Add4' */
  real_T LookupTable3;                 /* '<S11>/Lookup Table3' */
  real_T Divide2;                      /* '<S11>/Divide2' */
  real_T Memory1_bc;                   /* '<S30>/Memory1' */
  real_T c_eob_j;                      /* '<S30>/c_eob  ' */
  real_T c_eob_js;                     /* '<S30>/c_eob' */
  real_T Add5;                         /* '<S11>/Add5' */
  real_T g6_ref;                       /* '<S31>/g6_ref' */
  real_T Memory2_k;                    /* '<S31>/Memory2' */
  real_T c_eob1;                       /* '<S31>/c_eob  1' */
  real_T Memory1_o;                    /* '<S31>/Memory1' */
  real_T c_eob_b;                      /* '<S31>/c_eob  ' */
  real_T c_eob_a;                      /* '<S31>/c_eob' */
  real_T Add6;                         /* '<S11>/Add6' */
  real_T e2_o[6];                      /* '<S11>/1e-2' */
  real_T SFunction1[6500];             /* '<S10>/S-Function1' */
  real_T Memory1_l;                    /* '<S10>/Memory1' */
  real_T c_eob_h;                      /* '<S10>/c_eob' */
  real_T Divide6_m;                    /* '<S10>/Divide6' */
  real_T Add1_m;                       /* '<S6>/Add1' */
  real_T SFunction1_m[6500];           /* '<S15>/S-Function1' */
  real_T Memory2_l;                    /* '<S15>/Memory2' */
  real_T c_eob_k;                      /* '<S15>/c_eob' */
  real_T Divide1_n;                    /* '<S15>/Divide1' */
  real_T Add3_n;                       /* '<S9>/Add3' */
  real_T SFunction1_d[6500];           /* '<S18>/S-Function1' */
  real_T Memory2_l4;                   /* '<S18>/Memory2' */
  real_T c_eob_i;                      /* '<S18>/c_eob' */
  real_T Divide1_j;                    /* '<S18>/Divide1' */
  real_T Add1_h;                       /* '<S9>/Add1' */
  real_T SFunction1_k[6500];           /* '<S19>/S-Function1' */
  real_T Memory2_h;                    /* '<S19>/Memory2' */
  real_T c_eob_ls;                     /* '<S19>/c_eob' */
  real_T Divide1_l;                    /* '<S19>/Divide1' */
  real_T Add2_d;                       /* '<S9>/Add2' */
  real_T SFunction1_l[6500];           /* '<S20>/S-Function1' */
  real_T Memory2_m;                    /* '<S20>/Memory2' */
  real_T c_eob_pk;                     /* '<S20>/c_eob' */
  real_T Divide1_g;                    /* '<S20>/Divide1' */
  real_T Add4_l;                       /* '<S9>/Add4' */
  real_T SFunction1_g[6500];           /* '<S21>/S-Function1' */
  real_T Memory2_ha;                   /* '<S21>/Memory2' */
  real_T c_eob_ir;                     /* '<S21>/c_eob' */
  real_T Divide1_i;                    /* '<S21>/Divide1' */
  real_T Add5_i;                       /* '<S9>/Add5' */
  real_T LookupTable1_a;               /* '<S9>/Lookup Table1' */
  real_T Divide6_f;                    /* '<S9>/Divide6' */
  real_T SFunction1_i[6500];           /* '<S22>/S-Function1' */
  real_T Memory2_c;                    /* '<S22>/Memory2' */
  real_T c_eob_hr;                     /* '<S22>/c_eob' */
  real_T Divide1_jl;                   /* '<S22>/Divide1' */
  real_T Add6_b;                       /* '<S9>/Add6' */
  real_T SFunction1_ko[6500];          /* '<S23>/S-Function1' */
  real_T Memory2_f;                    /* '<S23>/Memory2' */
  real_T c_eob_ng;                     /* '<S23>/c_eob' */
  real_T Divide1_a;                    /* '<S23>/Divide1' */
  real_T Add7;                         /* '<S9>/Add7' */
  real_T SFunction1_lj[6500];          /* '<S24>/S-Function1' */
  real_T Memory2_j;                    /* '<S24>/Memory2' */
  real_T c_eob_ni;                     /* '<S24>/c_eob' */
  real_T Divide1_p;                    /* '<S24>/Divide1' */
  real_T Add8;                         /* '<S9>/Add8' */
  real_T SFunction1_e[6500];           /* '<S25>/S-Function1' */
  real_T Memory2_p;                    /* '<S25>/Memory2' */
  real_T c_eob_id;                     /* '<S25>/c_eob' */
  real_T Divide1_lm;                   /* '<S25>/Divide1' */
  real_T Add9;                         /* '<S9>/Add9' */
  real_T SFunction1_h[6500];           /* '<S16>/S-Function1' */
  real_T Memory2_n;                    /* '<S16>/Memory2' */
  real_T c_eob_jj;                     /* '<S16>/c_eob' */
  real_T Divide1_c;                    /* '<S16>/Divide1' */
  real_T Add10;                        /* '<S9>/Add10' */
  real_T SFunction1_g4[6500];          /* '<S17>/S-Function1' */
  real_T Memory2_kk;                   /* '<S17>/Memory2' */
  real_T c_eob_le;                     /* '<S17>/c_eob' */
  real_T Divide1_e;                    /* '<S17>/Divide1' */
  real_T Add11;                        /* '<S9>/Add11' */
  real_T LogicalOperator1_i;           /* '<S13>/Logical Operator1' */
  real_T u9_g[20];                     /* '<S13>/0.99' */
  real_T Divide2_i[20];                /* '<S7>/Divide2' */
  real_T Divcontr[11];                 /* '<S7>/Div. contr.' */
  real_T u9_n[11];                     /* '<S39>/0.99' */
  real_T Memory1_e;                    /* '<S46>/Memory1' */
  real_T LogicalOperator1_n;           /* '<S46>/Logical Operator1' */
  real_T u999_f;                       /* '<S46>/0.9999' */
  real_T Divide13[20];                 /* '<S7>/Divide13' */
  real_T Div_rdcontr[11];              /* '<S7>/Div_rd contr' */
  real_T SFunction1_kc[6500];          /* '<S44>/S-Function1' */
  real_T Memory1_f1;                   /* '<S44>/Memory1' */
  real_T c_eob_jl;                     /* '<S44>/c_eob' */
  real_T u99[11];                      /* '<S37>/0.999' */
  real_T Memory1_l1;                   /* '<S45>/Memory1' */
  real_T u999_l;                       /* '<S45>/0.9999' */
  real_T Subtract2_g;                  /* '<S45>/Subtract2' */
  real_T Gain1_j;                      /* '<S45>/Gain1' */
  real_T Subtract3;                    /* '<S45>/Subtract3' */
  real_T Saturation;                   /* '<S45>/Saturation' */
  real_T Divide4_k[11];                /* '<S7>/Divide4' */
  real_T Currtermcontr[11];            /* '<S7>/Curr. term. contr' */
  real_T Subtract1_i;                  /* '<S45>/Subtract1' */
  real_T Divide5[11];                  /* '<S7>/Divide5' */
  real_T Memory2_kj[11];               /* '<S38>/Memory2' */
  real_T tcont2[20];                   /* '<S38>/tcont2 ' */
  real_T Limcontr[11];                 /* '<S38>/Lim. contr.' */
  real_T Currcontr[11];                /* '<S38>/Curr. contr.' */
  real_T IpIp_div[11];                 /* '<S38>/Ip>Ip_div ' */
  real_T Divide6_o[11];                /* '<S7>/Divide6' */
  real_T volt1;                        /* '<S42>/volt1' */
  real_T volt2;                        /* '<S42>/volt2' */
  real_T volt3;                        /* '<S42>/volt3' */
  real_T volt4;                        /* '<S42>/volt4' */
  real_T volt5;                        /* '<S42>/volt5' */
  real_T volt6;                        /* '<S42>/volt6' */
  real_T volt7;                        /* '<S42>/volt7' */
  real_T volt8;                        /* '<S42>/volt8' */
  real_T volt9;                        /* '<S42>/volt9' */
  real_T volt10;                       /* '<S42>/volt10' */
  real_T volt11;                       /* '<S42>/volt11' */
  real_T Divide7[11];                  /* '<S7>/Divide7' */
  real_T Sum3[11];                     /* '<S7>/Sum3' */
  real_T e3_m[11];                     /* '<S36>/1e3' */
  real_T Abs[11];                      /* '<S36>/Abs' */
  real_T ntur_f[11];                   /* '<S36>/ntur' */
  real_T Sum2_l[11];                   /* '<S36>/Sum2' */
  real_T c_cur_max[11];                /* '<S36>/c_cur_max' */
  real_T Sum1[11];                     /* '<S36>/Sum1' */
  real_T Divide4_f[11];                /* '<S36>/Divide4' */
  real_T Divide1_o[11];                /* '<S36>/Divide1' */
  real_T Saturation_p[11];             /* '<S36>/Saturation' */
  real_T Divide2_h[11];                /* '<S36>/Divide2' */
  real_T Sum3_k[11];                   /* '<S36>/Sum3' */
  real_T Saturation1_p[11];            /* '<S36>/Saturation1' */
  real_T Divide6_b[11];                /* '<S36>/Divide6' */
  real_T ntur_e[11];                   /* '<S4>/ntur' */
  real_T Divide2_n[11];                /* '<S2>/Divide2' */
  real_T Tfmc[11];                     /* '<S2>/Tfmc ' */
  real_T Add1_i[11];                   /* '<S2>/Add1' */
  real_T Divide3[11];                  /* '<S2>/Divide3' */
  real_T Memory2_g;                    /* '<S4>/Memory2' */
  real_T u_e;                          /* '<S4>/-1' */
  real_T IpIp_0;                       /* '<S4>/Ip<Ip_0 ' */
  real_T Sum2_e;                       /* '<S4>/Sum2' */
  real_T e6_e;                         /* '<S12>/1e6' */
  real_T Divide12[20];                 /* '<S7>/Divide12' */
  real_T ntur_k[11];                   /* '<S38>/1//ntur' */
  real_T Gain2[500];                   /* '<S44>/Gain2' */
  real_T Gain1_h[500];                 /* '<S44>/Gain1' */
  real_T Ipref;                        /* '<S44>/Ipref' */
  real_T c_a_tpl1_eob15;               /* '<S7>/c_a_tpl1_eob//15' */
  real_T Saturation4;                  /* '<S7>/Saturation4' */
  real_T Divide11[2];                  /* '<S7>/Divide11' */
  real_T c_eob_lu[2];                  /* '<S7>/c_eob ' */
  real_T IpIp_div_m;                   /* '<S43>/Ip>Ip_div' */
  real_T Divide8[2];                   /* '<S7>/Divide8' */
  real_T SatDiv;                       /* '<S43>/Sat. Div' */
  real_T SatLim;                       /* '<S43>/Sat. Lim' */
  real_T u5;                           /* '<S7>/1//15' */
  real_T Saturation3;                  /* '<S7>/Saturation3' */
  real_T Divide9[2];                   /* '<S7>/Divide9' */
  real_T Subtract3_f;                  /* '<S48>/Subtract3' */
  real_T Divide_i[11];                 /* '<S7>/Divide' */
  real_T tcont2_f[11];                 /* '<S38>/tcont2' */
  real_T gain_cont2;                   /* '<S38>/gain_cont2' */
  real_T Divide_o[11];                 /* '<S38>/Divide ' */
  real_T ntur_n[11];                   /* '<S38>/1//ntur ' */
  real_T Subtract2_p;                  /* '<S46>/Subtract2' */
  real_T Gain1_i;                      /* '<S46>/Gain1' */
  real_T Subtract3_k;                  /* '<S46>/Subtract3' */
  real_T Saturation_c;                 /* '<S46>/Saturation' */
  real_T Subtract1_h;                  /* '<S46>/Subtract1' */
  real_T c_eob_oo;                     /* '<S7>/c_eob' */
  real_T Divide3_o[11];                /* '<S7>/Divide3' */
  real_T Divide1_f[11];                /* '<S7>/Divide1' */
  real_T Sum2_m[11];                   /* '<S7>/Sum2' */
  real_T atpl2;                        /* '<S7>/atpl2' */
  real_T Saturation_h;                 /* '<S7>/Saturation' */
  real_T Divide6_b2;                   /* '<S44>/Divide6' */
  real_T Sum;                          /* '<S44>/Sum' */
  real_T Divide2_iq;                   /* '<S44>/Divide2' */
  real_T Sum1_c;                       /* '<S44>/Sum1' */
  real_T uy0;                          /* '<S44>/[1 y0]' */
  real_T Diff_j;                       /* '<S35>/Diff' */
  real_T Diff_l;                       /* '<S34>/Diff' */
  real_T Divide_l;                     /* '<S14>/Divide' */
  real_T Sum2_b;                       /* '<S47>/Sum2' */
  real_T elong_ref;                    /* '<S6>/elong_ref' */
  real_T Add2_a;                       /* '<S6>/Add2' */
  real_T k_gaplim[4];                  /* '<S6>/k_gaplim' */
  real_T Add2_i;                       /* '<S31>/Add2' */
  real_T g6_ref_term;                  /* '<S31>/g6_ref_term' */
  real_T Add1_o1;                      /* '<S31>/Add1' */
  real_T g5_ref;                       /* '<S30>/g5_ref' */
  real_T Add2_f;                       /* '<S30>/Add2' */
  real_T g5_ref_term;                  /* '<S30>/g5_ref_term' */
  real_T g4_ref;                       /* '<S29>/g4_ref' */
  real_T Add2_h;                       /* '<S29>/Add2' */
  real_T g4_ref_term;                  /* '<S29>/g4_ref_term' */
  real_T g3_ref;                       /* '<S28>/g3_ref' */
  real_T Add2_m5;                      /* '<S28>/Add2' */
  real_T g3_ref_term;                  /* '<S28>/g3_ref_term' */
  real_T g2_ref;                       /* '<S27>/g2_ref' */
  real_T Add2_k;                       /* '<S27>/Add2' */
  real_T g2_ref_term;                  /* '<S27>/g2_ref_term' */
  real_T g1_ref;                       /* '<S26>/g1_ref' */
  real_T Add2_o;                       /* '<S26>/Add2' */
  real_T g1_ref_term;                  /* '<S26>/g1_ref_term' */
  real_T Gain2_j[500];                 /* '<S10>/Gain2' */
  real_T Gain1_k[500];                 /* '<S10>/Gain1' */
  real_T Ipref_c;                      /* '<S10>/Ipref' */
  real_T Gain4[500];                   /* '<S25>/Gain4' */
  real_T Gain1_h4[500];                /* '<S25>/Gain1' */
  real_T I9;                           /* '<S25>/I9' */
  real_T Gain4_i[500];                 /* '<S24>/Gain4' */
  real_T Gain1_jd[500];                /* '<S24>/Gain1' */
  real_T I8;                           /* '<S24>/I8' */
  real_T Gain4_a[500];                 /* '<S23>/Gain4' */
  real_T Gain1_a[500];                 /* '<S23>/Gain1' */
  real_T I7;                           /* '<S23>/I7' */
  real_T Gain4_a3[500];                /* '<S22>/Gain4' */
  real_T Gain1_a1[500];                /* '<S22>/Gain1' */
  real_T I6;                           /* '<S22>/I6' */
  real_T Gain4_l[500];                 /* '<S21>/Gain4' */
  real_T Gain1_b[500];                 /* '<S21>/Gain1' */
  real_T I5;                           /* '<S21>/I5' */
  real_T Gain4_j[500];                 /* '<S20>/Gain4' */
  real_T Gain1_m[500];                 /* '<S20>/Gain1' */
  real_T I4;                           /* '<S20>/I4' */
  real_T Gain4_k[500];                 /* '<S19>/Gain4' */
  real_T Gain1_mh[500];                /* '<S19>/Gain1' */
  real_T I3;                           /* '<S19>/I3' */
  real_T Gain4_m[500];                 /* '<S18>/Gain4' */
  real_T Gain1_ag[500];                /* '<S18>/Gain1' */
  real_T I2;                           /* '<S18>/I2' */
  real_T Gain4_k5[500];                /* '<S17>/Gain4' */
  real_T Gain1_ma[500];                /* '<S17>/Gain1' */
  real_T I11;                          /* '<S17>/I11' */
  real_T Gain4_p[500];                 /* '<S16>/Gain4' */
  real_T Gain1_l[500];                 /* '<S16>/Gain1' */
  real_T I10;                          /* '<S16>/I10' */
  real_T Gain4_n[500];                 /* '<S15>/Gain4' */
  real_T Gain1_n[500];                 /* '<S15>/Gain1' */
  real_T I1;                           /* '<S15>/I1' */
  uint8_T Compare;                     /* '<S59>/Compare' */
  uint8_T Compare_c;                   /* '<S60>/Compare' */
  uint8_T Compare_m;                   /* '<S56>/Compare' */
  uint8_T Compare_o;                   /* '<S57>/Compare' */
  uint8_T Compare_g;                   /* '<S58>/Compare' */
  uint8_T Compare_p;                   /* '<S51>/Compare' */
  uint8_T Compare_e;                   /* '<S52>/Compare' */
  uint8_T Compare_i;                   /* '<S53>/Compare' */
  uint8_T Compare_b;                   /* '<S54>/Compare' */
  uint8_T Compare_d;                   /* '<S55>/Compare' */
  uint8_T Compare_f;                   /* '<S63>/Compare' */
  uint8_T Compare_n;                   /* '<S64>/Compare' */
  uint8_T Compare_pn;                  /* '<S32>/Compare' */
  uint8_T Compare_m5;                  /* '<S33>/Compare' */
  uint8_T Compare_h;                   /* '<S61>/Compare' */
  uint8_T Compare_j;                   /* '<S62>/Compare' */
  uint8_T Compare_il[11];              /* '<S49>/Compare' */
  uint8_T Compare_dg[11];              /* '<S50>/Compare' */
  boolean_T LogicalOperator[11];       /* '<S36>/Logical Operator' */
  boolean_T RelationalOperator_c;      /* '<S4>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S4>/Relational Operator1' */
} BlockIO_t15_2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S5>/UD' */
  real_T UD_DSTATE_j;                  /* '<S34>/UD' */
  real_T UD_DSTATE_o;                  /* '<S35>/UD' */
  real_T VScontr_DSTATE[10];           /* '<S41>/VS. contr' */
  real_T VScontrhl_DSTATE[8];          /* '<S41>/VS. contr hl' */
  real_T Divcontr_DSTATE[50];          /* '<S7>/Div. contr.' */
  real_T Div_rdcontr_DSTATE[40];       /* '<S7>/Div_rd contr' */
  real_T Currtermcontr_DSTATE[40];     /* '<S7>/Curr. term. contr' */
  real_T Limcontr_DSTATE[50];          /* '<S38>/Lim. contr.' */
  real_T Currcontr_DSTATE[11];         /* '<S38>/Curr. contr.' */
  real_T Memory_PreviousInput[11];     /* '<S2>/Memory' */
  real_T PrevY[11];                    /* '<S2>/Rate Limiter' */
  real_T UniformRandomNumber_NextOutput;/* '<S47>/Uniform Random Number' */
  real_T Memory2_PreviousInput;        /* '<S12>/Memory2' */
  real_T Memory1_PreviousInput;        /* '<S12>/Memory1' */
  real_T Memory1_PreviousInput_p[11];  /* '<S37>/Memory1' */
  real_T Memory_PreviousInput_e[11];   /* '<S39>/Memory' */
  real_T Memory3_PreviousInput;        /* '<S48>/Memory3' */
  real_T Memory1_PreviousInput_c;      /* '<S26>/Memory1' */
  real_T Memory1_PreviousInput_d;      /* '<S27>/Memory1' */
  real_T Memory1_PreviousInput_i;      /* '<S28>/Memory1' */
  real_T Memory1_PreviousInput_g;      /* '<S29>/Memory1' */
  real_T Memory1_PreviousInput_gg;     /* '<S30>/Memory1' */
  real_T Memory2_PreviousInput_b;      /* '<S31>/Memory2' */
  real_T Memory1_PreviousInput_g2;     /* '<S31>/Memory1' */
  real_T Memory1_PreviousInput_j;      /* '<S10>/Memory1' */
  real_T Memory2_PreviousInput_l;      /* '<S15>/Memory2' */
  real_T Memory2_PreviousInput_p;      /* '<S18>/Memory2' */
  real_T Memory2_PreviousInput_c;      /* '<S19>/Memory2' */
  real_T Memory2_PreviousInput_bw;     /* '<S20>/Memory2' */
  real_T Memory2_PreviousInput_m;      /* '<S21>/Memory2' */
  real_T Memory2_PreviousInput_e;      /* '<S22>/Memory2' */
  real_T Memory2_PreviousInput_lu;     /* '<S23>/Memory2' */
  real_T Memory2_PreviousInput_h;      /* '<S24>/Memory2' */
  real_T Memory2_PreviousInput_g;      /* '<S25>/Memory2' */
  real_T Memory2_PreviousInput_f;      /* '<S16>/Memory2' */
  real_T Memory2_PreviousInput_d;      /* '<S17>/Memory2' */
  real_T Memory1_PreviousInput_cn;     /* '<S46>/Memory1' */
  real_T Memory1_PreviousInput_i3;     /* '<S44>/Memory1' */
  real_T Memory1_PreviousInput_l;      /* '<S45>/Memory1' */
  real_T Memory2_PreviousInput_k[11];  /* '<S38>/Memory2' */
  real_T Sum3_DWORK1[11];              /* '<S36>/Sum3' */
  real_T Memory2_PreviousInput_gi;     /* '<S4>/Memory2' */
  uint32_T RandSeed;                   /* '<S47>/Uniform Random Number' */
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
  real_T Gain4_Gain[13];               /* Expression: M_scr(3,:)
                                        * Referenced by: '<S15>/Gain4'
                                        */
  real_T Gain1_Gain[13];               /* Expression: M_scr(1,:)
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T Gain4_Gain_n[13];             /* Expression: M_scr(12,:)
                                        * Referenced by: '<S16>/Gain4'
                                        */
  real_T Gain1_Gain_d[13];             /* Expression: M_scr(1,:)
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Gain4_Gain_f[13];             /* Expression: M_scr(13,:)
                                        * Referenced by: '<S17>/Gain4'
                                        */
  real_T Gain1_Gain_di[13];            /* Expression: M_scr(1,:)
                                        * Referenced by: '<S17>/Gain1'
                                        */
  real_T Gain4_Gain_b[13];             /* Expression: M_scr(4,:)
                                        * Referenced by: '<S18>/Gain4'
                                        */
  real_T Gain1_Gain_m[13];             /* Expression: M_scr(1,:)
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T Gain4_Gain_l[13];             /* Expression: M_scr(5,:)
                                        * Referenced by: '<S19>/Gain4'
                                        */
  real_T Gain1_Gain_n[13];             /* Expression: M_scr(1,:)
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real_T Gain4_Gain_bt[13];            /* Expression: M_scr(6,:)
                                        * Referenced by: '<S20>/Gain4'
                                        */
  real_T Gain1_Gain_k[13];             /* Expression: M_scr(1,:)
                                        * Referenced by: '<S20>/Gain1'
                                        */
  real_T Gain4_Gain_g[13];             /* Expression: M_scr(7,:)
                                        * Referenced by: '<S21>/Gain4'
                                        */
  real_T Gain1_Gain_o[13];             /* Expression: M_scr(1,:)
                                        * Referenced by: '<S21>/Gain1'
                                        */
  real_T Gain4_Gain_h[13];             /* Expression: M_scr(8,:)
                                        * Referenced by: '<S22>/Gain4'
                                        */
  real_T Gain1_Gain_h[13];             /* Expression: M_scr(1,:)
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real_T Gain4_Gain_e[13];             /* Expression: M_scr(9,:)
                                        * Referenced by: '<S23>/Gain4'
                                        */
  real_T Gain1_Gain_b[13];             /* Expression: M_scr(1,:)
                                        * Referenced by: '<S23>/Gain1'
                                        */
  real_T Gain4_Gain_nj[13];            /* Expression: M_scr(10,:)
                                        * Referenced by: '<S24>/Gain4'
                                        */
  real_T Gain1_Gain_dt[13];            /* Expression: M_scr(1,:)
                                        * Referenced by: '<S24>/Gain1'
                                        */
  real_T Gain4_Gain_ge[13];            /* Expression: M_scr(11,:)
                                        * Referenced by: '<S25>/Gain4'
                                        */
  real_T Gain1_Gain_dg[13];            /* Expression: M_scr(1,:)
                                        * Referenced by: '<S25>/Gain1'
                                        */
  real_T Gain2_Gain[13];               /* Expression: M_scr(2,:)
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T Gain1_Gain_l[13];             /* Expression: M_scr(1,:)
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T g1_ref_term_XData[2];         /* Expression: g1_ref_term(:,1)
                                        * Referenced by: '<S26>/g1_ref_term'
                                        */
  real_T g1_ref_term_YData[2];         /* Expression: g1_ref_term(:,2)
                                        * Referenced by: '<S26>/g1_ref_term'
                                        */
  real_T g1_ref_XData[5];              /* Expression: g1_ref(:,1)
                                        * Referenced by: '<S26>/g1_ref'
                                        */
  real_T g1_ref_YData[5];              /* Expression: g1_ref(:,2)
                                        * Referenced by: '<S26>/g1_ref'
                                        */
  real_T g2_ref_term_XData[3];         /* Expression: g2_ref_term(:,1)
                                        * Referenced by: '<S27>/g2_ref_term'
                                        */
  real_T g2_ref_term_YData[3];         /* Expression: g2_ref_term(:,2)
                                        * Referenced by: '<S27>/g2_ref_term'
                                        */
  real_T g2_ref_XData[5];              /* Expression: g2_ref(:,1)
                                        * Referenced by: '<S27>/g2_ref'
                                        */
  real_T g2_ref_YData[5];              /* Expression: g2_ref(:,2)
                                        * Referenced by: '<S27>/g2_ref'
                                        */
  real_T g3_ref_term_XData[4];         /* Expression: g3_ref_term(:,1)
                                        * Referenced by: '<S28>/g3_ref_term'
                                        */
  real_T g3_ref_term_YData[4];         /* Expression: g3_ref_term(:,2)
                                        * Referenced by: '<S28>/g3_ref_term'
                                        */
  real_T g3_ref_XData[9];              /* Expression: g3_ref(:,1)
                                        * Referenced by: '<S28>/g3_ref'
                                        */
  real_T g3_ref_YData[9];              /* Expression: g3_ref(:,2)
                                        * Referenced by: '<S28>/g3_ref'
                                        */
  real_T g4_ref_term_XData[4];         /* Expression: g4_ref_term(:,1)
                                        * Referenced by: '<S29>/g4_ref_term'
                                        */
  real_T g4_ref_term_YData[4];         /* Expression: g4_ref_term(:,2)
                                        * Referenced by: '<S29>/g4_ref_term'
                                        */
  real_T g4_ref_XData[6];              /* Expression: g4_ref(:,1)
                                        * Referenced by: '<S29>/g4_ref'
                                        */
  real_T g4_ref_YData[6];              /* Expression: g4_ref(:,2)
                                        * Referenced by: '<S29>/g4_ref'
                                        */
  real_T g5_ref_term_XData[4];         /* Expression: g5_ref_term(:,1)
                                        * Referenced by: '<S30>/g5_ref_term'
                                        */
  real_T g5_ref_term_YData[4];         /* Expression: g5_ref_term(:,2)
                                        * Referenced by: '<S30>/g5_ref_term'
                                        */
  real_T g5_ref_XData[5];              /* Expression: g5_ref(:,1)
                                        * Referenced by: '<S30>/g5_ref'
                                        */
  real_T g5_ref_YData[5];              /* Expression: g5_ref(:,2)
                                        * Referenced by: '<S30>/g5_ref'
                                        */
  real_T g6_ref_term_XData[3];         /* Expression: g6_ref_term(:,1)
                                        * Referenced by: '<S31>/g6_ref_term'
                                        */
  real_T g6_ref_term_YData[3];         /* Expression: g6_ref_term(:,2)
                                        * Referenced by: '<S31>/g6_ref_term'
                                        */
  real_T elong_ref_XData[7];           /* Expression: elong_ref(:,1)
                                        * Referenced by: '<S6>/elong_ref'
                                        */
  real_T elong_ref_YData[7];           /* Expression: elong_ref(:,2)
                                        * Referenced by: '<S6>/elong_ref'
                                        */
  real_T k_gaplim_Gain[4];             /* Expression: k_gaplim
                                        * Referenced by: '<S6>/k_gaplim'
                                        */
  real_T zeros21_Value[2];             /* Expression: zeros(2,1)
                                        * Referenced by: '<S7>/zeros(2,1)'
                                        */
  real_T y0_Value;                     /* Expression: y0
                                        * Referenced by: '<S44>/y0'
                                        */
  real_T uy0_Value;                    /* Expression: (1-y0)/(c2_y0-c1_y0)
                                        * Referenced by: '<S44>/(1-y0)//...'
                                        */
  real_T c1_y0_Value;                  /* Expression: c1_y0
                                        * Referenced by: '<S44>/c1_y0'
                                        */
  real_T uy0_UpperSat;                 /* Expression: 1
                                        * Referenced by: '<S44>/[1 y0]'
                                        */
  real_T uy0_LowerSat;                 /* Expression: y0
                                        * Referenced by: '<S44>/[1 y0]'
                                        */
  real_T atpl2_Gain;                   /* Expression: c_a_tpl2/15
                                        * Referenced by: '<S7>/atpl2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T _Value;                       /* Expression: 1
                                        * Referenced by: '<S46>/1'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: -1/ref_ramp
                                        * Referenced by: '<S46>/Gain1'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: 1
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: 0
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real_T c_eob_Threshold;              /* Expression: c_eob
                                        * Referenced by: '<S7>/c_eob'
                                        */
  real_T zeros201_Value[20];           /* Expression: zeros(20,1)
                                        * Referenced by: '<S38>/zeros(20,1)'
                                        */
  real_T ntur_Gain[11];                /* Expression: 1./ntur(1:n_mc)
                                        * Referenced by: '<S38>/1//ntur '
                                        */
  real_T gain_cont2_XData[4];          /* Expression: tgain_cont2
                                        * Referenced by: '<S38>/gain_cont2'
                                        */
  real_T gain_cont2_YData[4];          /* Expression: gain_cont2
                                        * Referenced by: '<S38>/gain_cont2'
                                        */
  real_T tcont2_Threshold;             /* Expression: tcont2
                                        * Referenced by: '<S38>/tcont2'
                                        */
  real_T u5_Gain;                      /* Expression: 1/15
                                        * Referenced by: '<S7>/1//15'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S7>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: c_a_tpl_min
                                        * Referenced by: '<S7>/Saturation3'
                                        */
  real_T SatLim_UpperSat;              /* Expression: max_a_tpl1_lim
                                        * Referenced by: '<S43>/Sat. Lim'
                                        */
  real_T SatLim_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S43>/Sat. Lim'
                                        */
  real_T SatDiv_UpperSat;              /* Expression: max_a_tpl1_div
                                        * Referenced by: '<S43>/Sat. Div'
                                        */
  real_T SatDiv_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S43>/Sat. Div'
                                        */
  real_T IpIp_div_Threshold;           /* Expression: Ip_div
                                        * Referenced by: '<S43>/Ip>Ip_div'
                                        */
  real_T c_eob_Threshold_f;            /* Expression: c_eob
                                        * Referenced by: '<S7>/c_eob '
                                        */
  real_T c_a_tpl1_eob15_Gain;          /* Expression: c_a_tpl1_eob/15
                                        * Referenced by: '<S7>/c_a_tpl1_eob//15'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S7>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: c_a_tpl_min
                                        * Referenced by: '<S7>/Saturation4'
                                        */
  real_T Gain2_Gain_k[13];             /* Expression: M_scr(2,:)
                                        * Referenced by: '<S44>/Gain2'
                                        */
  real_T Gain1_Gain_l1[13];            /* Expression: M_scr(1,:)
                                        * Referenced by: '<S44>/Gain1'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T SimStep_Value;                /* Expression: SimStep
                                        * Referenced by: '<S2>/SimStep'
                                        */
  real_T e3_Gain;                      /* Expression: 1e-3
                                        * Referenced by: '<S4>/1e-3'
                                        */
  real_T UD_InitialCondition;          /* Expression: ICPrevInput
                                        * Referenced by: '<S5>/UD'
                                        */
  real_T RateLimiter_RisingLim[11];    /* Computed Parameter: RateLimiter_RisingLim
                                        * Referenced by: '<S2>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim[11];   /* Computed Parameter: RateLimiter_FallingLim
                                        * Referenced by: '<S2>/Rate Limiter'
                                        */
  real_T RateLimiter_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Rate Limiter'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/SimStep
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Saturation6_UpperSat[11];     /* Expression: Vmc_up
                                        * Referenced by: '<S2>/Saturation6'
                                        */
  real_T Saturation6_LowerSat[11];     /* Expression: Vmc_low
                                        * Referenced by: '<S2>/Saturation6'
                                        */
  real_T ntur_Gain_c[11];              /* Expression: 1./ntur(1:n_mc)
                                        * Referenced by: '<S1>/1//ntur'
                                        */
  real_T e6_Gain;                      /* Expression: 1e-6
                                        * Referenced by: '<S6>/1e-6'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: const
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T _Value_o;                     /* Expression: 1
                                        * Referenced by: '<S45>/1'
                                        */
  real_T UniformRandomNumber_Minimum;  /* Expression: -amp_noise
                                        * Referenced by: '<S47>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: amp_noise
                                        * Referenced by: '<S47>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S47>/Uniform Random Number'
                                        */
  real_T UD_InitialCondition_b;        /* Expression: ICPrevInput
                                        * Referenced by: '<S34>/UD'
                                        */
  real_T UD_InitialCondition_m;        /* Expression: ICPrevInput
                                        * Referenced by: '<S35>/UD'
                                        */
  real_T e6_Gain_k;                    /* Expression: 1e-6
                                        * Referenced by: '<S6>/1e-6   '
                                        */
  real_T tt_tran2d_Threshold;          /* Expression: t_tran2D
                                        * Referenced by: '<S7>/t>t_tran2d'
                                        */
  real_T VScontr_A[82];                /* Computed Parameter: VScontr_A
                                        * Referenced by: '<S41>/VS. contr'
                                        */
  real_T VScontr_B[20];                /* Computed Parameter: VScontr_B
                                        * Referenced by: '<S41>/VS. contr'
                                        */
  real_T VScontr_C[18];                /* Computed Parameter: VScontr_C
                                        * Referenced by: '<S41>/VS. contr'
                                        */
  real_T VScontr_D[4];                 /* Computed Parameter: VScontr_D
                                        * Referenced by: '<S41>/VS. contr'
                                        */
  real_T VScontr_X0;                   /* Expression: 0
                                        * Referenced by: '<S41>/VS. contr'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S12>/Memory2'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S12>/Memory1'
                                        */
  real_T Ics1_eob_Threshold;           /* Expression: Ics1_eob
                                        * Referenced by: '<S12>/Ics1_eob'
                                        */
  real_T dtpl_term_l_Gain;             /* Expression: 1/dtpl_term_l
                                        * Referenced by: '<S12>/dtpl_term_l'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S12>/Constant4'
                                        */
  real_T u_UpperSat;                   /* Expression: 1
                                        * Referenced by: '<S12>/1 0'
                                        */
  real_T u_LowerSat;                   /* Expression: 0
                                        * Referenced by: '<S12>/1 0'
                                        */
  real_T c_eob_Value;                  /* Expression: c_eob
                                        * Referenced by: '<S41>/c_eob '
                                        */
  real_T VScontrhl_A[33];              /* Computed Parameter: VScontrhl_A
                                        * Referenced by: '<S41>/VS. contr hl'
                                        */
  real_T VScontrhl_B[15];              /* Computed Parameter: VScontrhl_B
                                        * Referenced by: '<S41>/VS. contr hl'
                                        */
  real_T VScontrhl_C[9];               /* Computed Parameter: VScontrhl_C
                                        * Referenced by: '<S41>/VS. contr hl'
                                        */
  real_T VScontrhl_D[4];               /* Computed Parameter: VScontrhl_D
                                        * Referenced by: '<S41>/VS. contr hl'
                                        */
  real_T VScontrhl_X0;                 /* Expression: 0
                                        * Referenced by: '<S41>/VS. contr hl'
                                        */
  real_T c_eob_Threshold_j;            /* Expression: c_eob
                                        * Referenced by: '<S41>/c_eob'
                                        */
  real_T Constant_Value_g;             /* Expression: const
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: const
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: const
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T atpl115_Gain;                 /* Expression: c_a_tpl1/15
                                        * Referenced by: '<S43>/atpl1//15'
                                        */
  real_T u9_Threshold;                 /* Expression: 0.99
                                        * Referenced by: '<S40>/0.99'
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
  real_T Tfmc_Value;                   /* Expression: Tfmc
                                        * Referenced by: '<S2>/Tfmc'
                                        */
  real_T Memory1_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S37>/Memory1'
                                        */
  real_T Constant_Value_kb;            /* Expression: const
                                        * Referenced by: '<S51>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: const
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Memory_X0_j;                  /* Expression: 0
                                        * Referenced by: '<S39>/Memory'
                                        */
  real_T Constant_Value_m;             /* Expression: const
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: const
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: const
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T _Value_f;                     /* Expression: 1
                                        * Referenced by: '<S48>/1'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S48>/Memory3'
                                        */
  real_T Constant_Value_l;             /* Expression: const
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: const
                                        * Referenced by: '<S64>/Constant'
                                        */
  real_T u999_Threshold;               /* Expression: 0.9999
                                        * Referenced by: '<S48>/0.9999'
                                        */
  real_T Gain1_Gain_l2;                /* Expression: -1/ref_ramp
                                        * Referenced by: '<S48>/Gain1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S48>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S48>/Saturation1'
                                        */
  real_T u_Threshold;                  /* Expression: 0
                                        * Referenced by: '<S8>/>=0'
                                        */
  real_T e2_Gain;                      /* Expression: 1e2
                                        * Referenced by: '<S11>/1e2'
                                        */
  real_T Memory1_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S26>/Memory1'
                                        */
  real_T c_eob_Threshold_l;            /* Expression: c_eob
                                        * Referenced by: '<S26>/c_eob  '
                                        */
  real_T c_eob_Threshold_o;            /* Expression: c_eob
                                        * Referenced by: '<S26>/c_eob'
                                        */
  real_T LookupTable1_XData[4];        /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S11>/Lookup Table1'
                                        */
  real_T LookupTable1_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S11>/Lookup Table1'
                                        */
  real_T Memory1_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S27>/Memory1'
                                        */
  real_T c_eob_Threshold_h;            /* Expression: c_eob
                                        * Referenced by: '<S27>/c_eob '
                                        */
  real_T c_eob_Threshold_e;            /* Expression: c_eob
                                        * Referenced by: '<S27>/c_eob'
                                        */
  real_T LookupTable2_XData[4];        /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S11>/Lookup Table2'
                                        */
  real_T LookupTable2_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S11>/Lookup Table2'
                                        */
  real_T Memory1_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S28>/Memory1'
                                        */
  real_T c_eob_Threshold_fw;           /* Expression: c_eob
                                        * Referenced by: '<S28>/c_eob '
                                        */
  real_T c_eob_Threshold_l5;           /* Expression: c_eob
                                        * Referenced by: '<S28>/c_eob'
                                        */
  real_T Memory1_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S29>/Memory1'
                                        */
  real_T c_eob_Threshold_b;            /* Expression: c_eob
                                        * Referenced by: '<S29>/c_eob  '
                                        */
  real_T c_eob_Threshold_ek;           /* Expression: c_eob
                                        * Referenced by: '<S29>/c_eob'
                                        */
  real_T LookupTable3_XData[4];        /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S11>/Lookup Table3'
                                        */
  real_T LookupTable3_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S11>/Lookup Table3'
                                        */
  real_T Memory1_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S30>/Memory1'
                                        */
  real_T c_eob_Threshold_la;           /* Expression: c_eob
                                        * Referenced by: '<S30>/c_eob  '
                                        */
  real_T c_eob_Threshold_i;            /* Expression: c_eob
                                        * Referenced by: '<S30>/c_eob'
                                        */
  real_T g6_ref_XData[8];              /* Expression: g6_ref(:,1)
                                        * Referenced by: '<S31>/g6_ref'
                                        */
  real_T g6_ref_YData[8];              /* Expression: g6_ref(:,2)
                                        * Referenced by: '<S31>/g6_ref'
                                        */
  real_T Memory2_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S31>/Memory2'
                                        */
  real_T c_eob1_Threshold;             /* Expression: c_eob
                                        * Referenced by: '<S31>/c_eob  1'
                                        */
  real_T Memory1_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S31>/Memory1'
                                        */
  real_T c_eob_Threshold_hf;           /* Expression: c_eob
                                        * Referenced by: '<S31>/c_eob  '
                                        */
  real_T c_eob_Threshold_d;            /* Expression: c_eob
                                        * Referenced by: '<S31>/c_eob'
                                        */
  real_T e2_Gain_k;                    /* Expression: 1e-2
                                        * Referenced by: '<S11>/1e-2'
                                        */
  real_T Constant4_Value_f;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant4'
                                        */
  real_T SFunction1_P1;                /* Expression: 1
                                        * Referenced by: '<S10>/S-Function1'
                                        */
  real_T Memory1_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S10>/Memory1'
                                        */
  real_T c_eob_Threshold_m;            /* Expression: c_eob
                                        * Referenced by: '<S10>/c_eob'
                                        */
  real_T SFunction1_P1_g;              /* Expression: 1
                                        * Referenced by: '<S15>/S-Function1'
                                        */
  real_T Memory2_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S15>/Memory2'
                                        */
  real_T c_eob_Threshold_lg;           /* Expression: c_eob
                                        * Referenced by: '<S15>/c_eob'
                                        */
  real_T SFunction1_P1_p;              /* Expression: 1
                                        * Referenced by: '<S18>/S-Function1'
                                        */
  real_T Memory2_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S18>/Memory2'
                                        */
  real_T c_eob_Threshold_k;            /* Expression: c_eob
                                        * Referenced by: '<S18>/c_eob'
                                        */
  real_T SFunction1_P1_d;              /* Expression: 1
                                        * Referenced by: '<S19>/S-Function1'
                                        */
  real_T Memory2_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S19>/Memory2'
                                        */
  real_T c_eob_Threshold_hz;           /* Expression: c_eob
                                        * Referenced by: '<S19>/c_eob'
                                        */
  real_T SFunction1_P1_c;              /* Expression: 1
                                        * Referenced by: '<S20>/S-Function1'
                                        */
  real_T Memory2_X0_nj;                /* Expression: 0
                                        * Referenced by: '<S20>/Memory2'
                                        */
  real_T c_eob_Threshold_g;            /* Expression: c_eob
                                        * Referenced by: '<S20>/c_eob'
                                        */
  real_T SFunction1_P1_dp;             /* Expression: 1
                                        * Referenced by: '<S21>/S-Function1'
                                        */
  real_T Memory2_X0_bm;                /* Expression: 0
                                        * Referenced by: '<S21>/Memory2'
                                        */
  real_T c_eob_Threshold_fx;           /* Expression: c_eob
                                        * Referenced by: '<S21>/c_eob'
                                        */
  real_T LookupTable1_XData_o[4];      /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S9>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_c[4];      /* Expression: [1 1 1 1]
                                        * Referenced by: '<S9>/Lookup Table1'
                                        */
  real_T SFunction1_P1_b;              /* Expression: 1
                                        * Referenced by: '<S22>/S-Function1'
                                        */
  real_T Memory2_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S22>/Memory2'
                                        */
  real_T c_eob_Threshold_n;            /* Expression: c_eob
                                        * Referenced by: '<S22>/c_eob'
                                        */
  real_T SFunction1_P1_n;              /* Expression: 1
                                        * Referenced by: '<S23>/S-Function1'
                                        */
  real_T Memory2_X0_bh;                /* Expression: 0
                                        * Referenced by: '<S23>/Memory2'
                                        */
  real_T c_eob_Threshold_gu;           /* Expression: c_eob
                                        * Referenced by: '<S23>/c_eob'
                                        */
  real_T SFunction1_P1_nl;             /* Expression: 1
                                        * Referenced by: '<S24>/S-Function1'
                                        */
  real_T Memory2_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S24>/Memory2'
                                        */
  real_T c_eob_Threshold_fg;           /* Expression: c_eob
                                        * Referenced by: '<S24>/c_eob'
                                        */
  real_T SFunction1_P1_i;              /* Expression: 1
                                        * Referenced by: '<S25>/S-Function1'
                                        */
  real_T Memory2_X0_bc;                /* Expression: 0
                                        * Referenced by: '<S25>/Memory2'
                                        */
  real_T c_eob_Threshold_g2;           /* Expression: c_eob
                                        * Referenced by: '<S25>/c_eob'
                                        */
  real_T SFunction1_P1_bx;             /* Expression: 1
                                        * Referenced by: '<S16>/S-Function1'
                                        */
  real_T Memory2_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S16>/Memory2'
                                        */
  real_T c_eob_Threshold_p;            /* Expression: c_eob
                                        * Referenced by: '<S16>/c_eob'
                                        */
  real_T SFunction1_P1_a;              /* Expression: 1
                                        * Referenced by: '<S17>/S-Function1'
                                        */
  real_T Memory2_X0_i;                 /* Expression: 0
                                        * Referenced by: '<S17>/Memory2'
                                        */
  real_T c_eob_Threshold_eb;           /* Expression: c_eob
                                        * Referenced by: '<S17>/c_eob'
                                        */
  real_T Constant_Value_nu;            /* Expression: const
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T Constant_Value_dp;            /* Expression: const
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T u9_Threshold_n;               /* Expression: 0.99
                                        * Referenced by: '<S13>/0.99'
                                        */
  real_T Divcontr_A[572];              /* Computed Parameter: Divcontr_A
                                        * Referenced by: '<S7>/Div. contr.'
                                        */
  real_T Divcontr_B[352];              /* Computed Parameter: Divcontr_B
                                        * Referenced by: '<S7>/Div. contr.'
                                        */
  real_T Divcontr_C[205];              /* Computed Parameter: Divcontr_C
                                        * Referenced by: '<S7>/Div. contr.'
                                        */
  real_T Divcontr_D[171];              /* Computed Parameter: Divcontr_D
                                        * Referenced by: '<S7>/Div. contr.'
                                        */
  real_T Divcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S7>/Div. contr.'
                                        */
  real_T u9_Threshold_g;               /* Expression: 0.99
                                        * Referenced by: '<S39>/0.99'
                                        */
  real_T Memory1_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S46>/Memory1'
                                        */
  real_T Constant_Value_jk;            /* Expression: const
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: const
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T u999_Threshold_k;             /* Expression: 0.9999
                                        * Referenced by: '<S46>/0.9999'
                                        */
  real_T Div_rdcontr_A[337];           /* Computed Parameter: Div_rdcontr_A
                                        * Referenced by: '<S7>/Div_rd contr'
                                        */
  real_T Div_rdcontr_B[277];           /* Computed Parameter: Div_rdcontr_B
                                        * Referenced by: '<S7>/Div_rd contr'
                                        */
  real_T Div_rdcontr_C[165];           /* Computed Parameter: Div_rdcontr_C
                                        * Referenced by: '<S7>/Div_rd contr'
                                        */
  real_T Div_rdcontr_D[198];           /* Computed Parameter: Div_rdcontr_D
                                        * Referenced by: '<S7>/Div_rd contr'
                                        */
  real_T Div_rdcontr_X0;               /* Expression: 0
                                        * Referenced by: '<S7>/Div_rd contr'
                                        */
  real_T SFunction1_P1_ph;             /* Expression: 1
                                        * Referenced by: '<S44>/S-Function1'
                                        */
  real_T Memory1_X0_nr;                /* Expression: 0
                                        * Referenced by: '<S44>/Memory1'
                                        */
  real_T c_eob_Threshold_l4;           /* Expression: c_eob
                                        * Referenced by: '<S44>/c_eob'
                                        */
  real_T u99_Threshold;                /* Expression: 0.999
                                        * Referenced by: '<S37>/0.999'
                                        */
  real_T Memory1_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S45>/Memory1'
                                        */
  real_T u999_Threshold_a;             /* Expression: 0.9999
                                        * Referenced by: '<S45>/0.9999'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: -1/ref_ramp
                                        * Referenced by: '<S45>/Gain1'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 1
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: 0
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real_T Currtermcontr_A[253];         /* Computed Parameter: Currtermcontr_A
                                        * Referenced by: '<S7>/Curr. term. contr'
                                        */
  real_T Currtermcontr_B[121];         /* Computed Parameter: Currtermcontr_B
                                        * Referenced by: '<S7>/Curr. term. contr'
                                        */
  real_T Currtermcontr_C[11];          /* Computed Parameter: Currtermcontr_C
                                        * Referenced by: '<S7>/Curr. term. contr'
                                        */
  real_T Currtermcontr_X0;             /* Expression: 0
                                        * Referenced by: '<S7>/Curr. term. contr'
                                        */
  real_T Memory2_X0_e1;                /* Expression: 0
                                        * Referenced by: '<S38>/Memory2'
                                        */
  real_T tcont2_Threshold_b;           /* Expression: tcont2
                                        * Referenced by: '<S38>/tcont2 '
                                        */
  real_T Limcontr_A[914];              /* Computed Parameter: Limcontr_A
                                        * Referenced by: '<S38>/Lim. contr.'
                                        */
  real_T Limcontr_B[364];              /* Computed Parameter: Limcontr_B
                                        * Referenced by: '<S38>/Lim. contr.'
                                        */
  real_T Limcontr_C[517];              /* Computed Parameter: Limcontr_C
                                        * Referenced by: '<S38>/Lim. contr.'
                                        */
  real_T Limcontr_D[187];              /* Computed Parameter: Limcontr_D
                                        * Referenced by: '<S38>/Lim. contr.'
                                        */
  real_T Limcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S38>/Lim. contr.'
                                        */
  real_T Currcontr_A[121];             /* Computed Parameter: Currcontr_A
                                        * Referenced by: '<S38>/Curr. contr.'
                                        */
  real_T Currcontr_B[121];             /* Computed Parameter: Currcontr_B
                                        * Referenced by: '<S38>/Curr. contr.'
                                        */
  real_T Currcontr_C[121];             /* Computed Parameter: Currcontr_C
                                        * Referenced by: '<S38>/Curr. contr.'
                                        */
  real_T Currcontr_X0;                 /* Expression: 0
                                        * Referenced by: '<S38>/Curr. contr.'
                                        */
  real_T IpIp_div_Threshold_h;         /* Expression: Ip_div
                                        * Referenced by: '<S38>/Ip>Ip_div '
                                        */
  real_T volt1_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S42>/volt1'
                                        */
  real_T volt1_YData[19];              /* Expression: volt(:,2)
                                        * Referenced by: '<S42>/volt1'
                                        */
  real_T volt2_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S42>/volt2'
                                        */
  real_T volt2_YData[19];              /* Expression: volt(:,3)
                                        * Referenced by: '<S42>/volt2'
                                        */
  real_T volt3_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S42>/volt3'
                                        */
  real_T volt3_YData[19];              /* Expression: volt(:,4)
                                        * Referenced by: '<S42>/volt3'
                                        */
  real_T volt4_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S42>/volt4'
                                        */
  real_T volt4_YData[19];              /* Expression: volt(:,5)
                                        * Referenced by: '<S42>/volt4'
                                        */
  real_T volt5_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S42>/volt5'
                                        */
  real_T volt5_YData[19];              /* Expression: volt(:,6)
                                        * Referenced by: '<S42>/volt5'
                                        */
  real_T volt6_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S42>/volt6'
                                        */
  real_T volt6_YData[19];              /* Expression: volt(:,7)
                                        * Referenced by: '<S42>/volt6'
                                        */
  real_T volt7_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S42>/volt7'
                                        */
  real_T volt7_YData[19];              /* Expression: volt(:,8)
                                        * Referenced by: '<S42>/volt7'
                                        */
  real_T volt8_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S42>/volt8'
                                        */
  real_T volt8_YData[19];              /* Expression: volt(:,9)
                                        * Referenced by: '<S42>/volt8'
                                        */
  real_T volt9_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S42>/volt9'
                                        */
  real_T volt9_YData[19];              /* Expression: volt(:,10)
                                        * Referenced by: '<S42>/volt9'
                                        */
  real_T volt10_XData[19];             /* Expression: volt(:,1)
                                        * Referenced by: '<S42>/volt10'
                                        */
  real_T volt10_YData[19];             /* Expression: volt(:,11)
                                        * Referenced by: '<S42>/volt10'
                                        */
  real_T volt11_XData[19];             /* Expression: volt(:,1)
                                        * Referenced by: '<S42>/volt11'
                                        */
  real_T volt11_YData[19];             /* Expression: volt(:,12)
                                        * Referenced by: '<S42>/volt11'
                                        */
  real_T e3_Gain_l;                    /* Expression: 1e3
                                        * Referenced by: '<S36>/1e3'
                                        */
  real_T Imax_Value[11];               /* Expression: Imax
                                        * Referenced by: '<S7>/Imax'
                                        */
  real_T ntur_Gain_m[11];              /* Expression: ntur(1:n_mc)
                                        * Referenced by: '<S36>/ntur'
                                        */
  real_T c_cur_max_Gain;               /* Expression: c_cur_max
                                        * Referenced by: '<S36>/c_cur_max'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: 1
                                        * Referenced by: '<S36>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -1
                                        * Referenced by: '<S36>/Saturation'
                                        */
  real_T Constant_Value_i;             /* Expression: const
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T Constant_Value_ay;            /* Expression: 0
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T Saturation1_UpperSat_e;       /* Expression: 1
                                        * Referenced by: '<S36>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_m;       /* Expression: -1
                                        * Referenced by: '<S36>/Saturation1'
                                        */
  real_T ntur_Gain_d[11];              /* Expression: ntur(1:n_mc)
                                        * Referenced by: '<S4>/ntur'
                                        */
  real_T Tfmc_Gain;                    /* Expression: Tfmc
                                        * Referenced by: '<S2>/Tfmc '
                                        */
  real_T Memory2_X0_d;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T u_Gain;                       /* Expression: -1
                                        * Referenced by: '<S4>/-1'
                                        */
  real_T IpIp_0_Threshold;             /* Expression: -Ip_0
                                        * Referenced by: '<S4>/Ip<Ip_0 '
                                        */
  real_T dt_end_sim_Value;             /* Expression: dt_end_sim
                                        * Referenced by: '<S4>/dt_end_sim'
                                        */
  real_T Time_stop_Value;              /* Expression: Time_stop
                                        * Referenced by: '<S4>/Time_stop'
                                        */
  real_T e6_Gain_b;                    /* Expression: 1e6
                                        * Referenced by: '<S12>/1e6'
                                        */
  real_T ntur_Gain_o[11];              /* Expression: 1./ntur(1:n_mc)*1e6
                                        * Referenced by: '<S38>/1//ntur'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_t15_2 {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    boolean_T stopRequestedFlag;
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
 * Block '<S6>/To Workspace1' : Unused code path elimination
 * Block '<S6>/To Workspace2' : Unused code path elimination
 * Block '<S6>/To Workspace3' : Unused code path elimination
 * Block '<S7>/To Workspace' : Unused code path elimination
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
 * '<S2>'   : 't15_2/Pow. Supply MC '
 * '<S3>'   : 't15_2/Pow. Supply VS1,3'
 * '<S4>'   : 't15_2/kavin_contr'
 * '<S5>'   : 't15_2/Pow. Supply MC /Difference'
 * '<S6>'   : 't15_2/kavin_contr/Control inputs 1'
 * '<S7>'   : 't15_2/kavin_contr/Control2'
 * '<S8>'   : 't15_2/kavin_contr/Subsystem'
 * '<S9>'   : 't15_2/kavin_contr/Control inputs 1/Icoils ref'
 * '<S10>'  : 't15_2/kavin_contr/Control inputs 1/Ipl ref'
 * '<S11>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem'
 * '<S12>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem1'
 * '<S13>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem4'
 * '<S14>'  : 't15_2/kavin_contr/Control inputs 1/dZ//dt'
 * '<S15>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil1 ref'
 * '<S16>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil10 ref'
 * '<S17>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil11 ref'
 * '<S18>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil2 ref'
 * '<S19>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil3 ref'
 * '<S20>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil4 ref'
 * '<S21>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil5 ref'
 * '<S22>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil6 ref'
 * '<S23>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil7 ref'
 * '<S24>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil8 ref'
 * '<S25>'  : 't15_2/kavin_contr/Control inputs 1/Icoils ref/Icoil9 ref'
 * '<S26>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem'
 * '<S27>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem1'
 * '<S28>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem2'
 * '<S29>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem3'
 * '<S30>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem4'
 * '<S31>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem/Subsystem5'
 * '<S32>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem4/Compare To Constant'
 * '<S33>'  : 't15_2/kavin_contr/Control inputs 1/Subsystem4/Compare To Constant1'
 * '<S34>'  : 't15_2/kavin_contr/Control inputs 1/dZ//dt/Difference'
 * '<S35>'  : 't15_2/kavin_contr/Control inputs 1/dZ//dt/Difference1'
 * '<S36>'  : 't15_2/kavin_contr/Control2/Curr. satur.'
 * '<S37>'  : 't15_2/kavin_contr/Control2/Subsystem'
 * '<S38>'  : 't15_2/kavin_contr/Control2/Subsystem10'
 * '<S39>'  : 't15_2/kavin_contr/Control2/Subsystem7'
 * '<S40>'  : 't15_2/kavin_contr/Control2/Subsystem8'
 * '<S41>'  : 't15_2/kavin_contr/Control2/Subsystem9'
 * '<S42>'  : 't15_2/kavin_contr/Control2/Volt'
 * '<S43>'  : 't15_2/kavin_contr/Control2/atpl'
 * '<S44>'  : 't15_2/kavin_contr/Control2/atpl2 eob1'
 * '<S45>'  : 't15_2/kavin_contr/Control2/div_curr'
 * '<S46>'  : 't15_2/kavin_contr/Control2/div_divrd'
 * '<S47>'  : 't15_2/kavin_contr/Control2/dzdt noise'
 * '<S48>'  : 't15_2/kavin_contr/Control2/lim_div_tr'
 * '<S49>'  : 't15_2/kavin_contr/Control2/Curr. satur./Compare To Constant'
 * '<S50>'  : 't15_2/kavin_contr/Control2/Curr. satur./Compare To Zero'
 * '<S51>'  : 't15_2/kavin_contr/Control2/Subsystem/Compare To Constant'
 * '<S52>'  : 't15_2/kavin_contr/Control2/Subsystem/Compare To Constant1'
 * '<S53>'  : 't15_2/kavin_contr/Control2/Subsystem7/Compare To Constant'
 * '<S54>'  : 't15_2/kavin_contr/Control2/Subsystem7/Compare To Constant1'
 * '<S55>'  : 't15_2/kavin_contr/Control2/Subsystem7/Compare To Constant2'
 * '<S56>'  : 't15_2/kavin_contr/Control2/Subsystem8/Compare To Constant'
 * '<S57>'  : 't15_2/kavin_contr/Control2/Subsystem8/Compare To Constant1'
 * '<S58>'  : 't15_2/kavin_contr/Control2/Subsystem8/Compare To Constant2'
 * '<S59>'  : 't15_2/kavin_contr/Control2/div_curr/Compare To Constant'
 * '<S60>'  : 't15_2/kavin_contr/Control2/div_curr/Compare To Constant1'
 * '<S61>'  : 't15_2/kavin_contr/Control2/div_divrd/Compare To Constant'
 * '<S62>'  : 't15_2/kavin_contr/Control2/div_divrd/Compare To Constant1'
 * '<S63>'  : 't15_2/kavin_contr/Control2/lim_div_tr/Compare To Constant'
 * '<S64>'  : 't15_2/kavin_contr/Control2/lim_div_tr/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_t15_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
