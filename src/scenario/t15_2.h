/*
 * File: t15_2.h
 *
 * Real-Time Workshop code generated for Simulink model t15_2.
 *
 * Model version                        : 1.1118
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Tue Feb 10 20:20:16 2015
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Tue Feb 10 20:20:17 2015
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
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_SATURATE.h"
#include "rt_look.h"
#include "rt_look1d.h"
#include "rt_rand.h"
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

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T PowerSupply[11];              /* '<S22>/Power Supply' */
  real_T e3;                           /* '<Root>/1e-3' */
  real_T Uk1;                          /* '<S36>/UD' */
  real_T Diff;                         /* '<S36>/Diff' */
  real_T Divide[11];                   /* '<S22>/Divide' */
  real_T RateLimiter[11];              /* '<S22>/Rate Limiter' */
  real_T Gain;                         /* '<S22>/Gain' */
  real_T Divide1[11];                  /* '<S22>/Divide1' */
  real_T Saturation6[11];              /* '<S22>/Saturation6' */
  real_T e6[15];                       /* '<S1>/1e-6   ' */
  real_T e3_l[11];                     /* '<S23>/1e3' */
  real_T Abs[11];                      /* '<S23>/Abs' */
  real_T ntur[11];                     /* '<S23>/ntur' */
  real_T Sum2[11];                     /* '<S23>/Sum2' */
  real_T c_cur_max[11];                /* '<S23>/c_cur_max' */
  real_T Sum1[11];                     /* '<S23>/Sum1' */
  real_T Divide4[11];                  /* '<S23>/Divide4' */
  real_T Divide1_d[11];                /* '<S23>/Divide1' */
  real_T Saturation[11];               /* '<S23>/Saturation' */
  real_T Divide2[11];                  /* '<S23>/Divide2' */
  real_T Sum3[11];                     /* '<S23>/Sum3' */
  real_T Saturation1[11];              /* '<S23>/Saturation1' */
  real_T Divide6[11];                  /* '<S23>/Divide6' */
  real_T e6_c;                         /* '<S1>/1e-6' */
  real_T RelationalOperator;           /* '<S26>/Relational Operator' */
  real_T RelationalOperator_p;         /* '<S32>/Relational Operator' */
  real_T UniformRandomNumber;          /* '<S35>/Uniform Random Number' */
  real_T Uk1_h;                        /* '<S20>/UD' */
  real_T Uk1_a;                        /* '<S21>/UD' */
  real_T Derivative;                   /* '<S7>/Derivative' */
  real_T tt_tran2d[2];                 /* '<S2>/t>t_tran2d' */
  real_T Divide4_l[2];                 /* '<S32>/Divide4' */
  real_T VScontrhl[12];                /* '<S32>/VS. contr hl' */
  real_T VScontr[12];                  /* '<S32>/VS. contr' */
  real_T tt_eobdt_contr_hl[12];        /* '<S32>/t>t_eob-dt_contr_hl' */
  real_T LogicalOperator1;             /* '<S31>/Logical Operator1' */
  real_T u9[12];                       /* '<S31>/0.99' */
  real_T Divide10[12];                 /* '<S2>/Divide10' */
  real_T Saturation5[12];              /* '<S2>/Saturation5' */
  real_T Add1[11];                     /* '<Root>/Add1' */
  real_T TmpSignalConversionAtnpf12Inpor[12];/* 'synthesized block' */
  real_T npf12[15];                    /* '<Root>/npf,12' */
  real_T Ipl_ref;                      /* '<S5>/Ipl_ref' */
  real_T LookupTable1;                 /* '<S5>/Lookup Table1' */
  real_T Divide6_o;                    /* '<S5>/Divide6' */
  real_T Add1_o;                       /* '<S1>/Add1' */
  real_T Memory1;                      /* '<S12>/Memory1' */
  real_T tt_eob;                       /* '<S12>/t>t_eob' */
  real_T Ip0;                          /* '<S12>/Ip>0' */
  real_T Divide6_e;                    /* '<S12>/Divide6' */
  real_T Add1_oq;                      /* '<S4>/Add1' */
  real_T Memory1_d;                    /* '<S10>/Memory1' */
  real_T tt_eob_j;                     /* '<S10>/t>t_eob' */
  real_T Ip0_l;                        /* '<S10>/Ip>0' */
  real_T Divide6_h;                    /* '<S10>/Divide6' */
  real_T Add10;                        /* '<S4>/Add10' */
  real_T Memory1_n;                    /* '<S11>/Memory1' */
  real_T tt_eob_p;                     /* '<S11>/t>t_eob' */
  real_T Ip0_i;                        /* '<S11>/Ip>0' */
  real_T Divide6_f;                    /* '<S11>/Divide6' */
  real_T Add11;                        /* '<S4>/Add11' */
  real_T Memory1_c;                    /* '<S13>/Memory1' */
  real_T tt_eob_m;                     /* '<S13>/t>t_eob' */
  real_T Ip0_b;                        /* '<S13>/Ip>0' */
  real_T Divide6_h5;                   /* '<S13>/Divide6' */
  real_T Add2;                         /* '<S4>/Add2' */
  real_T Memory1_o;                    /* '<S9>/Memory1' */
  real_T tt_eob_g;                     /* '<S9>/t>t_eob' */
  real_T Ip0_j;                        /* '<S9>/Ip>0' */
  real_T Divide6_b;                    /* '<S9>/Divide6' */
  real_T Add3;                         /* '<S4>/Add3' */
  real_T Memory1_l;                    /* '<S14>/Memory1' */
  real_T tt_eob_b;                     /* '<S14>/t>t_eob' */
  real_T Ip0_h;                        /* '<S14>/Ip>0' */
  real_T Divide6_d;                    /* '<S14>/Divide6' */
  real_T Add4;                         /* '<S4>/Add4' */
  real_T Memory1_g;                    /* '<S15>/Memory1' */
  real_T tt_eob_ge;                    /* '<S15>/t>t_eob' */
  real_T Ip0_hc;                       /* '<S15>/Ip>0' */
  real_T Divide6_di;                   /* '<S15>/Divide6' */
  real_T Add5;                         /* '<S4>/Add5' */
  real_T Memory1_k;                    /* '<S16>/Memory1' */
  real_T tt_eob_m1;                    /* '<S16>/t>t_eob' */
  real_T Ip0_jj;                       /* '<S16>/Ip>0' */
  real_T Divide6_a;                    /* '<S16>/Divide6' */
  real_T Add6;                         /* '<S4>/Add6' */
  real_T Memory1_f;                    /* '<S17>/Memory1' */
  real_T tt_eob_a;                     /* '<S17>/t>t_eob' */
  real_T Ip0_ji;                       /* '<S17>/Ip>0' */
  real_T Divide6_i;                    /* '<S17>/Divide6' */
  real_T Add7;                         /* '<S4>/Add7' */
  real_T Memory1_gs;                   /* '<S18>/Memory1' */
  real_T tt_eob_e;                     /* '<S18>/t>t_eob' */
  real_T Ip0_bw;                       /* '<S18>/Ip>0' */
  real_T Divide6_l;                    /* '<S18>/Divide6' */
  real_T Add8;                         /* '<S4>/Add8' */
  real_T Memory1_dr;                   /* '<S19>/Memory1' */
  real_T tt_eob_bz;                    /* '<S19>/t>t_eob' */
  real_T Ip0_k;                        /* '<S19>/Ip>0' */
  real_T Divide6_c;                    /* '<S19>/Divide6' */
  real_T Add9;                         /* '<S4>/Add9' */
  real_T LookupTable1_a;               /* '<S4>/Lookup Table1' */
  real_T Divide6_lh;                   /* '<S4>/Divide6' */
  real_T Sum2_f;                       /* '<S3>/Sum2' */
  real_T u;                            /* '<S3>/>=0' */
  real_T e2[6];                        /* '<S6>/1e2' */
  real_T g1_ref;                       /* '<S6>/g1_ref' */
  real_T Add2_i;                       /* '<S6>/Add2' */
  real_T LookupTable1_b;               /* '<S6>/Lookup Table1' */
  real_T Divide6_id;                   /* '<S6>/Divide6' */
  real_T g2_ref;                       /* '<S6>/g2_ref' */
  real_T Add1_j;                       /* '<S6>/Add1' */
  real_T LookupTable2;                 /* '<S6>/Lookup Table2' */
  real_T Divide1_k;                    /* '<S6>/Divide1' */
  real_T g3_ref;                       /* '<S6>/g3_ref' */
  real_T Add3_b;                       /* '<S6>/Add3' */
  real_T g4_ref;                       /* '<S6>/g4_ref' */
  real_T Add4_j;                       /* '<S6>/Add4' */
  real_T LookupTable3;                 /* '<S6>/Lookup Table3' */
  real_T Divide2_c;                    /* '<S6>/Divide2' */
  real_T g5_ref;                       /* '<S6>/g5_ref' */
  real_T Add5_k;                       /* '<S6>/Add5' */
  real_T g6_ref;                       /* '<S6>/g6_ref' */
  real_T Add6_g;                       /* '<S6>/Add6' */
  real_T e2_g[6];                      /* '<S6>/1e-2' */
  real_T Memory2;                      /* '<S8>/Memory2' */
  real_T Switch;                       /* '<S8>/Switch' */
  real_T RelationalOperator_k;         /* '<S8>/Relational Operator' */
  real_T u9_a[20];                     /* '<S8>/0.99' */
  real_T Currtermcontr[11];            /* '<S2>/Curr. term. contr' */
  real_T Memory2_e;                    /* '<S25>/Memory2' */
  real_T Switch_d;                     /* '<S25>/Switch' */
  real_T RelationalOperator_j;         /* '<S25>/Relational Operator' */
  real_T Divide2_j[20];                /* '<S2>/Divide2' */
  real_T Divcontr[11];                 /* '<S2>/Div. contr.' */
  real_T LogicalOperator1_j;           /* '<S27>/Logical Operator1' */
  real_T Divide13[20];                 /* '<S2>/Divide13' */
  real_T Div_rdcontr[11];              /* '<S2>/Div_rd contr' */
  real_T Uk1_o;                        /* '<S41>/UD' */
  real_T Diff_b;                       /* '<S41>/Diff' */
  real_T Divide_d;                     /* '<S25>/Divide' */
  real_T RateLimiter_m;                /* '<S25>/Rate Limiter' */
  real_T Gain_m;                       /* '<S25>/Gain' */
  real_T Divide1_b;                    /* '<S25>/Divide1' */
  real_T Saturation_f;                 /* '<S25>/Saturation' */
  real_T Divide_e[11];                 /* '<S2>/Divide' */
  real_T Limcontr[11];                 /* '<S2>/Lim. contr.' */
  real_T Memory[11];                   /* '<S30>/Memory' */
  real_T LogicalOperator1_h;           /* '<S30>/Logical Operator1' */
  real_T LogicalOperator1_i;           /* '<S29>/Logical Operator1' */
  real_T Subtract;                     /* '<S29>/Subtract' */
  real_T Uk1_n;                        /* '<S51>/UD' */
  real_T Diff_e;                       /* '<S51>/Diff' */
  real_T Divide_b;                     /* '<S29>/Divide' */
  real_T RateLimiter_g;                /* '<S29>/Rate Limiter' */
  real_T RelationalOperator_g;         /* '<S28>/Relational Operator' */
  real_T Divide12[20];                 /* '<S2>/Divide12' */
  real_T FromWorkspace2;               /* '<S34>/From Workspace2' */
  real_T Uk1_hj;                       /* '<S46>/UD' */
  real_T Diff_k;                       /* '<S46>/Diff' */
  real_T Divide_n;                     /* '<S27>/Divide' */
  real_T RateLimiter_n;                /* '<S27>/Rate Limiter' */
  real_T Memory1_h[11];                /* '<S2>/Memory1' */
  real_T Ip0_bw0[11];                  /* '<S2>/Ip>0' */
  real_T Subtract_b;                   /* '<S26>/Subtract' */
  real_T Uk1_j;                        /* '<S42>/UD' */
  real_T Diff_a;                       /* '<S42>/Diff' */
  real_T Divide_i;                     /* '<S26>/Divide' */
  real_T RateLimiter_ny;               /* '<S26>/Rate Limiter' */
  real_T Gain_j;                       /* '<S26>/Gain' */
  real_T Divide1_c;                    /* '<S26>/Divide1' */
  real_T Subtract1;                    /* '<S26>/Subtract1' */
  real_T Saturation_m;                 /* '<S26>/Saturation' */
  real_T Divide4_a[11];                /* '<S2>/Divide4' */
  real_T Uk1_f;                        /* '<S47>/UD' */
  real_T Diff_d;                       /* '<S47>/Diff' */
  real_T Divide_m;                     /* '<S28>/Divide' */
  real_T RateLimiter_h;                /* '<S28>/Rate Limiter' */
  real_T Gain_n;                       /* '<S28>/Gain' */
  real_T Divide1_j;                    /* '<S28>/Divide1' */
  real_T Saturation_c;                 /* '<S28>/Saturation' */
  real_T Divide5[11];                  /* '<S2>/Divide5' */
  real_T Memory2_o;                    /* '<S24>/Memory2' */
  real_T Switch_m;                     /* '<S24>/Switch' */
  real_T Subtract_h;                   /* '<S24>/Subtract' */
  real_T Uk1_om;                       /* '<S40>/UD' */
  real_T Diff_o;                       /* '<S40>/Diff' */
  real_T Divide_l;                     /* '<S24>/Divide' */
  real_T RateLimiter_k;                /* '<S24>/Rate Limiter' */
  real_T Gain_a;                       /* '<S24>/Gain' */
  real_T Divide1_cl;                   /* '<S24>/Divide1' */
  real_T Subtract1_n;                  /* '<S24>/Subtract1' */
  real_T Saturation_e;                 /* '<S24>/Saturation' */
  real_T Memory2_f[11];                /* '<S2>/Memory2' */
  real_T IpIp_div[11];                 /* '<S2>/Ip>Ip_div ' */
  real_T Divide6_iz[11];               /* '<S2>/Divide6' */
  real_T volt1;                        /* '<S33>/volt1' */
  real_T volt2;                        /* '<S33>/volt2' */
  real_T volt3;                        /* '<S33>/volt3' */
  real_T volt4;                        /* '<S33>/volt4' */
  real_T volt5;                        /* '<S33>/volt5' */
  real_T volt6;                        /* '<S33>/volt6' */
  real_T volt7;                        /* '<S33>/volt7' */
  real_T volt8;                        /* '<S33>/volt8' */
  real_T volt9;                        /* '<S33>/volt9' */
  real_T volt10;                       /* '<S33>/volt10' */
  real_T volt11;                       /* '<S33>/volt11' */
  real_T Divide7[11];                  /* '<S2>/Divide7' */
  real_T Sum3_h[11];                   /* '<S2>/Sum3' */
  real_T c_a_tpl1_eob15;               /* '<S2>/c_a_tpl1_eob//15' */
  real_T Saturation4;                  /* '<S2>/Saturation4' */
  real_T Divide11[12];                 /* '<S2>/Divide11' */
  real_T tt_eob1[12];                  /* '<S2>/t>t_eob1' */
  real_T u5;                           /* '<S2>/1//15' */
  real_T Saturation3;                  /* '<S2>/Saturation3' */
  real_T Divide9[12];                  /* '<S2>/Divide9' */
  real_T IpIp_div_l;                   /* '<S2>/Ip>Ip_div' */
  real_T Saturation2;                  /* '<S2>/Saturation2' */
  real_T Divide8[12];                  /* '<S2>/Divide8' */
  real_T atpl1;                        /* '<S2>/atpl1' */
  real_T c_a_tpl1_eob15_l;             /* '<S2>/c_a_tpl1_eob//15 ' */
  real_T Gain_jx;                      /* '<S27>/Gain' */
  real_T Divide1_o;                    /* '<S27>/Divide1' */
  real_T Saturation_o;                 /* '<S27>/Saturation' */
  real_T tt_eob_e4;                    /* '<S2>/t>t_eob' */
  real_T Divide3[11];                  /* '<S2>/Divide3' */
  real_T Gain_nj;                      /* '<S29>/Gain' */
  real_T Divide1_e;                    /* '<S29>/Divide1' */
  real_T Subtract1_m;                  /* '<S29>/Subtract1' */
  real_T Saturation_l;                 /* '<S29>/Saturation' */
  real_T u9_d[11];                     /* '<S30>/0.99' */
  real_T Divide1_b4[11];               /* '<S2>/Divide1' */
  real_T Sum2_i[11];                   /* '<S2>/Sum2' */
  real_T LookupTable1_bj;              /* '<S34>/Lookup Table1' */
  real_T Divide1_db;                   /* '<S34>/Divide1' */
  real_T Sum;                          /* '<S34>/Sum' */
  real_T Divide2_h;                    /* '<S34>/Divide2' */
  real_T Sum1_m;                       /* '<S34>/Sum1' */
  real_T Saturation1_b;                /* '<S34>/Saturation1' */
  real_T atpl2;                        /* '<S2>/atpl2' */
  real_T Saturation_a;                 /* '<S2>/Saturation' */
  real_T gain_cont2;                   /* '<S2>/gain_cont2' */
  real_T Divide_nh[11];                /* '<S2>/Divide ' */
  real_T EqTime005;                    /* '<S7>/EqTime+0.05' */
  real_T Sum2_d;                       /* '<S35>/Sum2' */
  real_T Diff_g;                       /* '<S21>/Diff' */
  real_T Diff_c;                       /* '<S20>/Diff' */
  real_T Divide_na;                    /* '<S7>/Divide' */
  real_T elong_ref;                    /* '<S1>/elong_ref' */
  real_T Add2_f;                       /* '<S1>/Add2' */
  real_T LookupTable1_o;               /* '<S19>/Lookup Table1' */
  real_T Icoil9_ref;                   /* '<S19>/Icoil9_ref' */
  real_T LookupTable1_g;               /* '<S18>/Lookup Table1' */
  real_T Icoil8_ref;                   /* '<S18>/Icoil8_ref' */
  real_T LookupTable1_on;              /* '<S17>/Lookup Table1' */
  real_T Icoil7_ref;                   /* '<S17>/Icoil7_ref' */
  real_T LookupTable1_h;               /* '<S16>/Lookup Table1' */
  real_T Icoil6_ref;                   /* '<S16>/Icoil6_ref' */
  real_T LookupTable1_m;               /* '<S15>/Lookup Table1' */
  real_T Icoil5_ref;                   /* '<S15>/Icoil5_ref' */
  real_T LookupTable1_c;               /* '<S14>/Lookup Table1' */
  real_T Icoil4_ref;                   /* '<S14>/Icoil4_ref' */
  real_T LookupTable1_gu;              /* '<S13>/Lookup Table1' */
  real_T Icoil3_ref;                   /* '<S13>/Icoil3_ref' */
  real_T LookupTable1_j;               /* '<S12>/Lookup Table1' */
  real_T Icoil2_ref;                   /* '<S12>/Icoil2_ref' */
  real_T LookupTable1_p;               /* '<S11>/Lookup Table1' */
  real_T Icoil11_ref;                  /* '<S11>/Icoil11_ref' */
  real_T LookupTable1_mg;              /* '<S10>/Lookup Table1' */
  real_T Icoil10_ref;                  /* '<S10>/Icoil10_ref' */
  real_T LookupTable1_ma;              /* '<S9>/Lookup Table1' */
  real_T Icoil1_ref;                   /* '<S9>/Icoil1_ref' */
  uint8_T Compare[11];                 /* '<S37>/Compare' */
  uint8_T Compare_j[11];               /* '<S38>/Compare' */
  uint8_T Compare_a;                   /* '<S55>/Compare' */
  uint8_T Compare_e;                   /* '<S56>/Compare' */
  uint8_T Compare_n;                   /* '<S57>/Compare' */
  uint8_T Compare_b;                   /* '<S43>/Compare' */
  uint8_T Compare_m;                   /* '<S44>/Compare' */
  uint8_T Compare_h;                   /* '<S45>/Compare' */
  uint8_T Compare_i;                   /* '<S52>/Compare' */
  uint8_T Compare_iq;                  /* '<S53>/Compare' */
  uint8_T Compare_c;                   /* '<S54>/Compare' */
  uint8_T Compare_jl;                  /* '<S48>/Compare' */
  uint8_T Compare_l;                   /* '<S49>/Compare' */
  uint8_T Compare_at;                  /* '<S50>/Compare' */
  uint8_T Compare_k;                   /* '<S39>/Compare' */
  boolean_T LogicalOperator[11];       /* '<S23>/Logical Operator' */
  boolean_T RelationalOperator_a;      /* '<Root>/Relational Operator' */
} BlockIO_t15_2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T PowerSupply_DSTATE[11];       /* '<S22>/Power Supply' */
  real_T UD_DSTATE;                    /* '<S36>/UD' */
  real_T UD_DSTATE_a;                  /* '<S20>/UD' */
  real_T UD_DSTATE_h;                  /* '<S21>/UD' */
  real_T VScontrhl_DSTATE[8];          /* '<S32>/VS. contr hl' */
  real_T VScontr_DSTATE[9];            /* '<S32>/VS. contr' */
  real_T Currtermcontr_DSTATE[40];     /* '<S2>/Curr. term. contr' */
  real_T Divcontr_DSTATE[50];          /* '<S2>/Div. contr.' */
  real_T Div_rdcontr_DSTATE[40];       /* '<S2>/Div_rd contr' */
  real_T UD_DSTATE_hh;                 /* '<S41>/UD' */
  real_T Limcontr_DSTATE[50];          /* '<S2>/Lim. contr.' */
  real_T UD_DSTATE_l;                  /* '<S51>/UD' */
  real_T UD_DSTATE_ak;                 /* '<S46>/UD' */
  real_T UD_DSTATE_aq;                 /* '<S42>/UD' */
  real_T UD_DSTATE_g;                  /* '<S47>/UD' */
  real_T UD_DSTATE_gc;                 /* '<S40>/UD' */
  real_T PrevY[11];                    /* '<S22>/Rate Limiter' */
  real_T LastMajorTime;                /* '<S22>/Rate Limiter' */
  real_T Sum3_DWORK1[11];              /* '<S23>/Sum3' */
  real_T UniformRandomNumber_NextOutput;/* '<S35>/Uniform Random Number' */
  real_T Memory1_PreviousInput;        /* '<S12>/Memory1' */
  real_T Memory1_PreviousInput_e;      /* '<S10>/Memory1' */
  real_T Memory1_PreviousInput_l;      /* '<S11>/Memory1' */
  real_T Memory1_PreviousInput_b;      /* '<S13>/Memory1' */
  real_T Memory1_PreviousInput_j;      /* '<S9>/Memory1' */
  real_T Memory1_PreviousInput_ei;     /* '<S14>/Memory1' */
  real_T Memory1_PreviousInput_m;      /* '<S15>/Memory1' */
  real_T Memory1_PreviousInput_g;      /* '<S16>/Memory1' */
  real_T Memory1_PreviousInput_o;      /* '<S17>/Memory1' */
  real_T Memory1_PreviousInput_e2;     /* '<S18>/Memory1' */
  real_T Memory1_PreviousInput_be;     /* '<S19>/Memory1' */
  real_T Memory2_PreviousInput;        /* '<S8>/Memory2' */
  real_T Memory2_PreviousInput_j;      /* '<S25>/Memory2' */
  real_T PrevY_e;                      /* '<S25>/Rate Limiter' */
  real_T LastMajorTime_d;              /* '<S25>/Rate Limiter' */
  real_T Memory_PreviousInput[11];     /* '<S30>/Memory' */
  real_T PrevY_h;                      /* '<S29>/Rate Limiter' */
  real_T LastMajorTime_h;              /* '<S29>/Rate Limiter' */
  real_T PrevY_o;                      /* '<S27>/Rate Limiter' */
  real_T LastMajorTime_e;              /* '<S27>/Rate Limiter' */
  real_T Memory1_PreviousInput_lt[11]; /* '<S2>/Memory1' */
  real_T PrevY_i;                      /* '<S26>/Rate Limiter' */
  real_T LastMajorTime_i;              /* '<S26>/Rate Limiter' */
  real_T PrevY_n;                      /* '<S28>/Rate Limiter' */
  real_T LastMajorTime_o;              /* '<S28>/Rate Limiter' */
  real_T Memory2_PreviousInput_l;      /* '<S24>/Memory2' */
  real_T Subtract_DWORK1;              /* '<S24>/Subtract' */
  real_T PrevY_j;                      /* '<S24>/Rate Limiter' */
  real_T LastMajorTime_j;              /* '<S24>/Rate Limiter' */
  real_T Memory2_PreviousInput_jb[11]; /* '<S2>/Memory2' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S7>/Derivative' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace2_PWORK;              /* '<S34>/From Workspace2' */

  uint32_T RandSeed;                   /* '<S35>/Uniform Random Number' */
  struct {
    int_T PrevIndex;
  } FromWorkspace2_IWORK;              /* '<S34>/From Workspace2' */
} D_Work_t15_2;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1[15];                      /* '<Root>/In1' */
  real_T In2[123];                     /* '<Root>/In2' */
} ExternalInputs_t15_2;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1[15];                     /* '<Root>/Out1' */
  real_T Time;                         /* '<Root>/Time' */
} ExternalOutputs_t15_2;

/* Parameters (auto storage) */
struct Parameters_t15_2_ {
  real_T PowerSupply_A[11];            /* Computed Parameter: PowerSupply_A
                                        * Referenced by: '<S22>/Power Supply'
                                        */
  real_T PowerSupply_B[11];            /* Computed Parameter: PowerSupply_B
                                        * Referenced by: '<S22>/Power Supply'
                                        */
  real_T PowerSupply_C[11];            /* Computed Parameter: PowerSupply_C
                                        * Referenced by: '<S22>/Power Supply'
                                        */
  real_T PowerSupply_X0;               /* Expression: 0
                                        * Referenced by: '<S22>/Power Supply'
                                        */
  real_T SimStep_Value;                /* Expression: SimStep
                                        * Referenced by: '<S22>/SimStep'
                                        */
  real_T e3_Gain;                      /* Expression: 1e-3
                                        * Referenced by: '<Root>/1e-3'
                                        */
  real_T UD_X0;                        /* Expression: ICPrevInput
                                        * Referenced by: '<S36>/UD'
                                        */
  real_T RateLimiter_RisingLim[11];    /* Expression: Ratemc_up
                                        * Referenced by: '<S22>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim[11];   /* Expression: Ratemc_low
                                        * Referenced by: '<S22>/Rate Limiter'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/SimStep
                                        * Referenced by: '<S22>/Gain'
                                        */
  real_T Saturation6_UpperSat[11];     /* Expression: Vmc_up
                                        * Referenced by: '<S22>/Saturation6'
                                        */
  real_T Saturation6_LowerSat[11];     /* Expression: Vmc_low
                                        * Referenced by: '<S22>/Saturation6'
                                        */
  real_T e6_Gain;                      /* Expression: 1e-6
                                        * Referenced by: '<S1>/1e-6   '
                                        */
  real_T e3_Gain_g;                    /* Expression: 1e3
                                        * Referenced by: '<S23>/1e3'
                                        */
  real_T Imax_Value[11];               /* Expression: Imax
                                        * Referenced by: '<S2>/Imax'
                                        */
  real_T ntur_Gain[11];                /* Expression: ntur(1:n_mc)
                                        * Referenced by: '<S23>/ntur'
                                        */
  real_T c_cur_max_Gain;               /* Expression: c_cur_max
                                        * Referenced by: '<S23>/c_cur_max'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S23>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S23>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S23>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S23>/Saturation1'
                                        */
  real_T e6_Gain_c;                    /* Expression: 1e-6
                                        * Referenced by: '<S1>/1e-6'
                                        */
  real_T _Value;                       /* Expression: Ip_0
                                        * Referenced by: '<S26>/0'
                                        */
  real_T t_eobdt_contr_hl_Value;       /* Expression: t_eob-dt_contr_hl
                                        * Referenced by: '<S32>/t_eob-dt_contr_hl'
                                        */
  real_T UniformRandomNumber_Minimum;  /* Expression: -amp_noise
                                        * Referenced by: '<S35>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: amp_noise
                                        * Referenced by: '<S35>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S35>/Uniform Random Number'
                                        */
  real_T UD_X0_c;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S20>/UD'
                                        */
  real_T UD_X0_e;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S21>/UD'
                                        */
  real_T zeros21_Value[2];             /* Expression: zeros(2,1)
                                        * Referenced by: '<S2>/zeros(2,1)'
                                        */
  real_T tt_tran2d_Threshold;          /* Expression: t_tran2D
                                        * Referenced by: '<S2>/t>t_tran2d'
                                        */
  real_T VScontrhl_A[33];              /* Computed Parameter: VScontrhl_A
                                        * Referenced by: '<S32>/VS. contr hl'
                                        */
  real_T VScontrhl_B[15];              /* Computed Parameter: VScontrhl_B
                                        * Referenced by: '<S32>/VS. contr hl'
                                        */
  real_T VScontrhl_C[24];              /* Computed Parameter: VScontrhl_C
                                        * Referenced by: '<S32>/VS. contr hl'
                                        */
  real_T VScontrhl_D[10];              /* Computed Parameter: VScontrhl_D
                                        * Referenced by: '<S32>/VS. contr hl'
                                        */
  real_T VScontrhl_X0;                 /* Expression: 0
                                        * Referenced by: '<S32>/VS. contr hl'
                                        */
  real_T VScontr_A[34];                /* Computed Parameter: VScontr_A
                                        * Referenced by: '<S32>/VS. contr'
                                        */
  real_T VScontr_B[16];                /* Computed Parameter: VScontr_B
                                        * Referenced by: '<S32>/VS. contr'
                                        */
  real_T VScontr_C[25];                /* Computed Parameter: VScontr_C
                                        * Referenced by: '<S32>/VS. contr'
                                        */
  real_T VScontr_D[10];                /* Computed Parameter: VScontr_D
                                        * Referenced by: '<S32>/VS. contr'
                                        */
  real_T VScontr_X0;                   /* Expression: 0
                                        * Referenced by: '<S32>/VS. contr'
                                        */
  real_T tt_eobdt_contr_hl_Threshold;  /* Expression: t_eob-dt_contr_hl
                                        * Referenced by: '<S32>/t>t_eob-dt_contr_hl'
                                        */
  real_T Constant_Value_p;             /* Expression: const
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: const
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: const
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T u9_Threshold;                 /* Expression: 0.99
                                        * Referenced by: '<S31>/0.99'
                                        */
  real_T Saturation5_UpperSat[12];     /* Expression: VS_up
                                        * Referenced by: '<S2>/Saturation5'
                                        */
  real_T Saturation5_LowerSat[12];     /* Expression: VS_low
                                        * Referenced by: '<S2>/Saturation5'
                                        */
  real_T npf12_Gain[180];              /* Expression: eye(npf,n_mc+1)
                                        * Referenced by: '<Root>/npf,12'
                                        */
  real_T Time_stop_Value;              /* Expression: Time_stop
                                        * Referenced by: '<Root>/Time_stop'
                                        */
  real_T Ipl_ref_XData[11];            /* Expression: scr_data(:,1)
                                        * Referenced by: '<S5>/Ipl_ref'
                                        */
  real_T Ipl_ref_YData[11];            /* Expression: scr_data(:,2)
                                        * Referenced by: '<S5>/Ipl_ref'
                                        */
  real_T LookupTable1_XData[4];        /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S5>/Lookup Table1'
                                        */
  real_T LookupTable1_YData[4];        /* Expression: [1 1 0 0]
                                        * Referenced by: '<S5>/Lookup Table1'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S12>/Memory1'
                                        */
  real_T tt_eob_Threshold;             /* Expression: t_eob
                                        * Referenced by: '<S12>/t>t_eob'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Ip0_Threshold;                /* Expression: Ip_0
                                        * Referenced by: '<S12>/Ip>0'
                                        */
  real_T Memory1_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S10>/Memory1'
                                        */
  real_T tt_eob_Threshold_e;           /* Expression: t_eob
                                        * Referenced by: '<S10>/t>t_eob'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Ip0_Threshold_g;              /* Expression: Ip_0
                                        * Referenced by: '<S10>/Ip>0'
                                        */
  real_T Memory1_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S11>/Memory1'
                                        */
  real_T tt_eob_Threshold_n;           /* Expression: t_eob
                                        * Referenced by: '<S11>/t>t_eob'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Ip0_Threshold_f;              /* Expression: Ip_0
                                        * Referenced by: '<S11>/Ip>0'
                                        */
  real_T Memory1_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S13>/Memory1'
                                        */
  real_T tt_eob_Threshold_b;           /* Expression: t_eob
                                        * Referenced by: '<S13>/t>t_eob'
                                        */
  real_T Constant_Value_ne;            /* Expression: 0
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Ip0_Threshold_a;              /* Expression: Ip_0
                                        * Referenced by: '<S13>/Ip>0'
                                        */
  real_T Memory1_X0_od;                /* Expression: 0
                                        * Referenced by: '<S9>/Memory1'
                                        */
  real_T tt_eob_Threshold_k;           /* Expression: t_eob
                                        * Referenced by: '<S9>/t>t_eob'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Ip0_Threshold_b;              /* Expression: Ip_0
                                        * Referenced by: '<S9>/Ip>0'
                                        */
  real_T Memory1_X0_l;                 /* Expression: 0
                                        * Referenced by: '<S14>/Memory1'
                                        */
  real_T tt_eob_Threshold_m;           /* Expression: t_eob
                                        * Referenced by: '<S14>/t>t_eob'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Ip0_Threshold_n;              /* Expression: Ip_0
                                        * Referenced by: '<S14>/Ip>0'
                                        */
  real_T Memory1_X0_i;                 /* Expression: 0
                                        * Referenced by: '<S15>/Memory1'
                                        */
  real_T tt_eob_Threshold_i;           /* Expression: t_eob
                                        * Referenced by: '<S15>/t>t_eob'
                                        */
  real_T Constant_Value_je;            /* Expression: 0
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Ip0_Threshold_ga;             /* Expression: Ip_0
                                        * Referenced by: '<S15>/Ip>0'
                                        */
  real_T Memory1_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S16>/Memory1'
                                        */
  real_T tt_eob_Threshold_p;           /* Expression: t_eob
                                        * Referenced by: '<S16>/t>t_eob'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Ip0_Threshold_m;              /* Expression: Ip_0
                                        * Referenced by: '<S16>/Ip>0'
                                        */
  real_T Memory1_X0_jl;                /* Expression: 0
                                        * Referenced by: '<S17>/Memory1'
                                        */
  real_T tt_eob_Threshold_o;           /* Expression: t_eob
                                        * Referenced by: '<S17>/t>t_eob'
                                        */
  real_T Constant_Value_nq;            /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Ip0_Threshold_e;              /* Expression: Ip_0
                                        * Referenced by: '<S17>/Ip>0'
                                        */
  real_T Memory1_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S18>/Memory1'
                                        */
  real_T tt_eob_Threshold_pi;          /* Expression: t_eob
                                        * Referenced by: '<S18>/t>t_eob'
                                        */
  real_T Constant_Value_o2;            /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Ip0_Threshold_o;              /* Expression: Ip_0
                                        * Referenced by: '<S18>/Ip>0'
                                        */
  real_T Memory1_X0_lr;                /* Expression: 0
                                        * Referenced by: '<S19>/Memory1'
                                        */
  real_T tt_eob_Threshold_kf;          /* Expression: t_eob
                                        * Referenced by: '<S19>/t>t_eob'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Ip0_Threshold_l;              /* Expression: Ip_0
                                        * Referenced by: '<S19>/Ip>0'
                                        */
  real_T LookupTable1_XData_j[4];      /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S4>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_j[4];      /* Expression: [0 0 1 1]
                                        * Referenced by: '<S4>/Lookup Table1'
                                        */
  real_T u_Threshold;                  /* Expression: 0
                                        * Referenced by: '<S3>/>=0'
                                        */
  real_T e2_Gain;                      /* Expression: 1e2
                                        * Referenced by: '<S6>/1e2'
                                        */
  real_T g1_ref_XData[7];              /* Expression: g1_ref(:,1)
                                        * Referenced by: '<S6>/g1_ref'
                                        */
  real_T g1_ref_YData[7];              /* Expression: g1_ref(:,2)
                                        * Referenced by: '<S6>/g1_ref'
                                        */
  real_T LookupTable1_XData_o[4];      /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S6>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_k[4];      /* Expression: [0 0 1 1]
                                        * Referenced by: '<S6>/Lookup Table1'
                                        */
  real_T g2_ref_XData[7];              /* Expression: g2_ref(:,1)
                                        * Referenced by: '<S6>/g2_ref'
                                        */
  real_T g2_ref_YData[7];              /* Expression: g2_ref(:,2)
                                        * Referenced by: '<S6>/g2_ref'
                                        */
  real_T LookupTable2_XData[4];        /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S6>/Lookup Table2'
                                        */
  real_T LookupTable2_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S6>/Lookup Table2'
                                        */
  real_T g3_ref_XData[12];             /* Expression: g3_ref(:,1)
                                        * Referenced by: '<S6>/g3_ref'
                                        */
  real_T g3_ref_YData[12];             /* Expression: g3_ref(:,2)
                                        * Referenced by: '<S6>/g3_ref'
                                        */
  real_T g4_ref_XData[9];              /* Expression: g4_ref(:,1)
                                        * Referenced by: '<S6>/g4_ref'
                                        */
  real_T g4_ref_YData[9];              /* Expression: g4_ref(:,2)
                                        * Referenced by: '<S6>/g4_ref'
                                        */
  real_T LookupTable3_XData[4];        /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S6>/Lookup Table3'
                                        */
  real_T LookupTable3_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S6>/Lookup Table3'
                                        */
  real_T g5_ref_XData[8];              /* Expression: g5_ref(:,1)
                                        * Referenced by: '<S6>/g5_ref'
                                        */
  real_T g5_ref_YData[8];              /* Expression: g5_ref(:,2)
                                        * Referenced by: '<S6>/g5_ref'
                                        */
  real_T g6_ref_XData[10];             /* Expression: g6_ref(:,1)
                                        * Referenced by: '<S6>/g6_ref'
                                        */
  real_T g6_ref_YData[10];             /* Expression: g6_ref(:,2)
                                        * Referenced by: '<S6>/g6_ref'
                                        */
  real_T e2_Gain_h;                    /* Expression: 1e-2
                                        * Referenced by: '<S6>/1e-2'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S8>/Memory2'
                                        */
  real_T Switch_Threshold;             /* Expression: Ip_div
                                        * Referenced by: '<S8>/Switch'
                                        */
  real_T e6_Value;                     /* Expression: 1e-6
                                        * Referenced by: '<S8>/1e-6'
                                        */
  real_T u9_Threshold_k;               /* Expression: 0.99
                                        * Referenced by: '<S8>/0.99'
                                        */
  real_T Currtermcontr_A[253];         /* Computed Parameter: Currtermcontr_A
                                        * Referenced by: '<S2>/Curr. term. contr'
                                        */
  real_T Currtermcontr_B[121];         /* Computed Parameter: Currtermcontr_B
                                        * Referenced by: '<S2>/Curr. term. contr'
                                        */
  real_T Currtermcontr_C[11];          /* Computed Parameter: Currtermcontr_C
                                        * Referenced by: '<S2>/Curr. term. contr'
                                        */
  real_T Currtermcontr_X0;             /* Expression: 0
                                        * Referenced by: '<S2>/Curr. term. contr'
                                        */
  real_T Memory2_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S25>/Memory2'
                                        */
  real_T Switch_Threshold_p;           /* Expression: Ip_div
                                        * Referenced by: '<S25>/Switch'
                                        */
  real_T e6_Value_j;                   /* Expression: 1e-6
                                        * Referenced by: '<S25>/1e-6'
                                        */
  real_T Divcontr_A[572];              /* Computed Parameter: Divcontr_A
                                        * Referenced by: '<S2>/Div. contr.'
                                        */
  real_T Divcontr_B[352];              /* Computed Parameter: Divcontr_B
                                        * Referenced by: '<S2>/Div. contr.'
                                        */
  real_T Divcontr_C[205];              /* Computed Parameter: Divcontr_C
                                        * Referenced by: '<S2>/Div. contr.'
                                        */
  real_T Divcontr_D[171];              /* Computed Parameter: Divcontr_D
                                        * Referenced by: '<S2>/Div. contr.'
                                        */
  real_T Divcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S2>/Div. contr.'
                                        */
  real_T Constant_Value_ou;            /* Expression: const
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T Constant_Value_bv;            /* Expression: const
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Constant_Value_p5;            /* Expression: const
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Div_rdcontr_A[337];           /* Computed Parameter: Div_rdcontr_A
                                        * Referenced by: '<S2>/Div_rd contr'
                                        */
  real_T Div_rdcontr_B[277];           /* Computed Parameter: Div_rdcontr_B
                                        * Referenced by: '<S2>/Div_rd contr'
                                        */
  real_T Div_rdcontr_C[165];           /* Computed Parameter: Div_rdcontr_C
                                        * Referenced by: '<S2>/Div_rd contr'
                                        */
  real_T Div_rdcontr_D[198];           /* Computed Parameter: Div_rdcontr_D
                                        * Referenced by: '<S2>/Div_rd contr'
                                        */
  real_T Div_rdcontr_X0;               /* Expression: 0
                                        * Referenced by: '<S2>/Div_rd contr'
                                        */
  real_T SimStep_Value_a;              /* Expression: SimStep
                                        * Referenced by: '<S25>/SimStep'
                                        */
  real_T UD_X0_m;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S41>/UD'
                                        */
  real_T RateLimiter_RisingLim_p;      /* Expression: 1/ref_ramp
                                        * Referenced by: '<S25>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_p;     /* Expression: -1/ref_ramp
                                        * Referenced by: '<S25>/Rate Limiter'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 1/SimStep
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: 1
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: 0
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Limcontr_A[914];              /* Computed Parameter: Limcontr_A
                                        * Referenced by: '<S2>/Lim. contr.'
                                        */
  real_T Limcontr_B[364];              /* Computed Parameter: Limcontr_B
                                        * Referenced by: '<S2>/Lim. contr.'
                                        */
  real_T Limcontr_C[517];              /* Computed Parameter: Limcontr_C
                                        * Referenced by: '<S2>/Lim. contr.'
                                        */
  real_T Limcontr_D[187];              /* Computed Parameter: Limcontr_D
                                        * Referenced by: '<S2>/Lim. contr.'
                                        */
  real_T Limcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S2>/Lim. contr.'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S30>/Memory'
                                        */
  real_T Constant_Value_g4;            /* Expression: const
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: const
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Constant_Value_bi;            /* Expression: const
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Constant_Value_ak;            /* Expression: const
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T Constant_Value_ex;            /* Expression: const
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T Constant_Value_nx;            /* Expression: const
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T _Value_g;                     /* Expression: 1
                                        * Referenced by: '<S29>/1'
                                        */
  real_T SimStep_Value_i;              /* Expression: SimStep
                                        * Referenced by: '<S29>/SimStep'
                                        */
  real_T UD_X0_b;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S51>/UD'
                                        */
  real_T RateLimiter_RisingLim_a;      /* Expression: 1/ref_ramp
                                        * Referenced by: '<S29>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_c;     /* Expression: -1/ref_ramp
                                        * Referenced by: '<S29>/Rate Limiter'
                                        */
  real_T _Value_m;                     /* Expression: Ip_0
                                        * Referenced by: '<S28>/2'
                                        */
  real_T c1_y0_Value;                  /* Expression: c1_y0
                                        * Referenced by: '<S34>/c1_y0'
                                        */
  real_T uy0_Value;                    /* Expression: (1-y0)/(c2_y0-c1_y0)
                                        * Referenced by: '<S34>/(1-y0)//...'
                                        */
  real_T y0_Value;                     /* Expression: y0
                                        * Referenced by: '<S34>/y0'
                                        */
  real_T SimStep_Value_j;              /* Expression: SimStep
                                        * Referenced by: '<S27>/SimStep'
                                        */
  real_T UD_X0_l;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S46>/UD'
                                        */
  real_T RateLimiter_RisingLim_j;      /* Expression: 1/ref_ramp
                                        * Referenced by: '<S27>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_l;     /* Expression: -1/ref_ramp
                                        * Referenced by: '<S27>/Rate Limiter'
                                        */
  real_T Memory1_X0_av;                /* Expression: 0
                                        * Referenced by: '<S2>/Memory1'
                                        */
  real_T Ip0_Threshold_gz;             /* Expression: Ip_0
                                        * Referenced by: '<S2>/Ip>0'
                                        */
  real_T _Value_mg;                    /* Expression: 1
                                        * Referenced by: '<S26>/1'
                                        */
  real_T SimStep_Value_e;              /* Expression: SimStep
                                        * Referenced by: '<S26>/SimStep'
                                        */
  real_T UD_X0_a;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S42>/UD'
                                        */
  real_T RateLimiter_RisingLim_k;      /* Expression: 1/ref_ramp
                                        * Referenced by: '<S26>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_o;     /* Expression: -1/ref_ramp
                                        * Referenced by: '<S26>/Rate Limiter'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 1/SimStep
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 1
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: 0
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real_T SimStep_Value_c;              /* Expression: SimStep
                                        * Referenced by: '<S28>/SimStep'
                                        */
  real_T UD_X0_f;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S47>/UD'
                                        */
  real_T RateLimiter_RisingLim_j2;     /* Expression: 1/ref_ramp
                                        * Referenced by: '<S28>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_e;     /* Expression: -1/ref_ramp
                                        * Referenced by: '<S28>/Rate Limiter'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1/SimStep
                                        * Referenced by: '<S28>/Gain'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 1
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Saturation_LowerSat_hy;       /* Expression: 0
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Memory2_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S24>/Memory2'
                                        */
  real_T Switch_Threshold_g;           /* Expression: Ip_div
                                        * Referenced by: '<S24>/Switch'
                                        */
  real_T Constant_Value_k;             /* Expression: const
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T _Value_a;                     /* Expression: 1
                                        * Referenced by: '<S24>/1'
                                        */
  real_T SimStep_Value_l;              /* Expression: SimStep
                                        * Referenced by: '<S24>/SimStep'
                                        */
  real_T UD_X0_am;                     /* Expression: ICPrevInput
                                        * Referenced by: '<S40>/UD'
                                        */
  real_T RateLimiter_RisingLim_f;      /* Expression: 1/ref_ramp
                                        * Referenced by: '<S24>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_oi;    /* Expression: -1/ref_ramp
                                        * Referenced by: '<S24>/Rate Limiter'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 1/SimStep
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 1
                                        * Referenced by: '<S24>/Saturation'
                                        */
  real_T Saturation_LowerSat_hf;       /* Expression: 0
                                        * Referenced by: '<S24>/Saturation'
                                        */
  real_T Memory2_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory2'
                                        */
  real_T IpIp_div_Threshold;           /* Expression: Ip_div
                                        * Referenced by: '<S2>/Ip>Ip_div '
                                        */
  real_T volt1_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S33>/volt1'
                                        */
  real_T volt1_YData[19];              /* Expression: volt(:,2)
                                        * Referenced by: '<S33>/volt1'
                                        */
  real_T volt2_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S33>/volt2'
                                        */
  real_T volt2_YData[19];              /* Expression: volt(:,3)
                                        * Referenced by: '<S33>/volt2'
                                        */
  real_T volt3_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S33>/volt3'
                                        */
  real_T volt3_YData[19];              /* Expression: volt(:,4)
                                        * Referenced by: '<S33>/volt3'
                                        */
  real_T volt4_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S33>/volt4'
                                        */
  real_T volt4_YData[19];              /* Expression: volt(:,5)
                                        * Referenced by: '<S33>/volt4'
                                        */
  real_T volt5_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S33>/volt5'
                                        */
  real_T volt5_YData[19];              /* Expression: volt(:,6)
                                        * Referenced by: '<S33>/volt5'
                                        */
  real_T volt6_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S33>/volt6'
                                        */
  real_T volt6_YData[19];              /* Expression: volt(:,7)
                                        * Referenced by: '<S33>/volt6'
                                        */
  real_T volt7_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S33>/volt7'
                                        */
  real_T volt7_YData[19];              /* Expression: volt(:,8)
                                        * Referenced by: '<S33>/volt7'
                                        */
  real_T volt8_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S33>/volt8'
                                        */
  real_T volt8_YData[19];              /* Expression: volt(:,9)
                                        * Referenced by: '<S33>/volt8'
                                        */
  real_T volt9_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S33>/volt9'
                                        */
  real_T volt9_YData[19];              /* Expression: volt(:,10)
                                        * Referenced by: '<S33>/volt9'
                                        */
  real_T volt10_XData[19];             /* Expression: volt(:,1)
                                        * Referenced by: '<S33>/volt10'
                                        */
  real_T volt10_YData[19];             /* Expression: volt(:,11)
                                        * Referenced by: '<S33>/volt10'
                                        */
  real_T volt11_XData[19];             /* Expression: volt(:,1)
                                        * Referenced by: '<S33>/volt11'
                                        */
  real_T volt11_YData[19];             /* Expression: volt(:,12)
                                        * Referenced by: '<S33>/volt11'
                                        */
  real_T Icoil1_ref_XData[11];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S9>/Icoil1_ref'
                                        */
  real_T Icoil1_ref_YData[11];         /* Expression: scr_PF(:,2)
                                        * Referenced by: '<S9>/Icoil1_ref'
                                        */
  real_T LookupTable1_XData_g[4];      /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S9>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_jv[4];     /* Expression: [1 1 0 0]
                                        * Referenced by: '<S9>/Lookup Table1'
                                        */
  real_T Icoil10_ref_XData[11];        /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S10>/Icoil10_ref'
                                        */
  real_T Icoil10_ref_YData[11];        /* Expression: scr_PF(:,11)
                                        * Referenced by: '<S10>/Icoil10_ref'
                                        */
  real_T LookupTable1_XData_l[4];      /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S10>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_o[4];      /* Expression: [1 1 0 0]
                                        * Referenced by: '<S10>/Lookup Table1'
                                        */
  real_T Icoil11_ref_XData[11];        /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S11>/Icoil11_ref'
                                        */
  real_T Icoil11_ref_YData[11];        /* Expression: scr_PF(:,12)
                                        * Referenced by: '<S11>/Icoil11_ref'
                                        */
  real_T LookupTable1_XData_gm[4];     /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S11>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_f[4];      /* Expression: [1 1 0 0]
                                        * Referenced by: '<S11>/Lookup Table1'
                                        */
  real_T Icoil2_ref_XData[11];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S12>/Icoil2_ref'
                                        */
  real_T Icoil2_ref_YData[11];         /* Expression: scr_PF(:,3)
                                        * Referenced by: '<S12>/Icoil2_ref'
                                        */
  real_T LookupTable1_XData_jx[4];     /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S12>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_g[4];      /* Expression: [1 1 0 0]
                                        * Referenced by: '<S12>/Lookup Table1'
                                        */
  real_T Icoil3_ref_XData[11];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S13>/Icoil3_ref'
                                        */
  real_T Icoil3_ref_YData[11];         /* Expression: scr_PF(:,4)
                                        * Referenced by: '<S13>/Icoil3_ref'
                                        */
  real_T LookupTable1_XData_f[4];      /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S13>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_h[4];      /* Expression: [1 1 0 0]
                                        * Referenced by: '<S13>/Lookup Table1'
                                        */
  real_T Icoil4_ref_XData[11];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S14>/Icoil4_ref'
                                        */
  real_T Icoil4_ref_YData[11];         /* Expression: scr_PF(:,5)
                                        * Referenced by: '<S14>/Icoil4_ref'
                                        */
  real_T LookupTable1_XData_jt[4];     /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S14>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_gb[4];     /* Expression: [1 1 0 0]
                                        * Referenced by: '<S14>/Lookup Table1'
                                        */
  real_T Icoil5_ref_XData[11];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S15>/Icoil5_ref'
                                        */
  real_T Icoil5_ref_YData[11];         /* Expression: scr_PF(:,6)
                                        * Referenced by: '<S15>/Icoil5_ref'
                                        */
  real_T LookupTable1_XData_g3[4];     /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S15>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_gu[4];     /* Expression: [1 1 0 0]
                                        * Referenced by: '<S15>/Lookup Table1'
                                        */
  real_T Icoil6_ref_XData[11];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S16>/Icoil6_ref'
                                        */
  real_T Icoil6_ref_YData[11];         /* Expression: scr_PF(:,7)
                                        * Referenced by: '<S16>/Icoil6_ref'
                                        */
  real_T LookupTable1_XData_e[4];      /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S16>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_kz[4];     /* Expression: [1 1 0 0]
                                        * Referenced by: '<S16>/Lookup Table1'
                                        */
  real_T Icoil7_ref_XData[11];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S17>/Icoil7_ref'
                                        */
  real_T Icoil7_ref_YData[11];         /* Expression: scr_PF(:,8)
                                        * Referenced by: '<S17>/Icoil7_ref'
                                        */
  real_T LookupTable1_XData_h[4];      /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S17>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_n[4];      /* Expression: [1 1 0 0]
                                        * Referenced by: '<S17>/Lookup Table1'
                                        */
  real_T Icoil8_ref_XData[11];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S18>/Icoil8_ref'
                                        */
  real_T Icoil8_ref_YData[11];         /* Expression: scr_PF(:,9)
                                        * Referenced by: '<S18>/Icoil8_ref'
                                        */
  real_T LookupTable1_XData_i[4];      /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S18>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_a[4];      /* Expression: [1 1 0 0]
                                        * Referenced by: '<S18>/Lookup Table1'
                                        */
  real_T Icoil9_ref_XData[11];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S19>/Icoil9_ref'
                                        */
  real_T Icoil9_ref_YData[11];         /* Expression: scr_PF(:,10)
                                        * Referenced by: '<S19>/Icoil9_ref'
                                        */
  real_T LookupTable1_XData_m[4];      /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S19>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_nz[4];     /* Expression: [1 1 0 0]
                                        * Referenced by: '<S19>/Lookup Table1'
                                        */
  real_T elong_ref_XData[7];           /* Expression: elong_ref(:,1)
                                        * Referenced by: '<S1>/elong_ref'
                                        */
  real_T elong_ref_YData[7];           /* Expression: elong_ref(:,2)
                                        * Referenced by: '<S1>/elong_ref'
                                        */
  real_T EqTime005_Threshold;          /* Expression: EqTime+0.05
                                        * Referenced by: '<S7>/EqTime+0.05'
                                        */
  real_T gain_cont2_XData[4];          /* Expression: tgain_cont2
                                        * Referenced by: '<S2>/gain_cont2'
                                        */
  real_T gain_cont2_YData[4];          /* Expression: gain_cont2
                                        * Referenced by: '<S2>/gain_cont2'
                                        */
  real_T atpl2_Gain;                   /* Expression: c_a_tpl2/15
                                        * Referenced by: '<S2>/atpl2'
                                        */
  real_T Saturation_UpperSat_n;        /* Expression: 1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: 0
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T LookupTable1_XData_c[4];      /* Expression: [0 t_eob t_eob+dtpl_term_l 1e6]
                                        * Referenced by: '<S34>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_i[4];      /* Expression: [1 1 0 0]
                                        * Referenced by: '<S34>/Lookup Table1'
                                        */
  real_T Saturation1_UpperSat_g;       /* Expression: 1
                                        * Referenced by: '<S34>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_j;       /* Expression: y0
                                        * Referenced by: '<S34>/Saturation1'
                                        */
  real_T Gain_Gain_k1;                 /* Expression: 1/SimStep
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: 1
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T tt_eob_Threshold_c;           /* Expression: t_eob
                                        * Referenced by: '<S2>/t>t_eob'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 1/SimStep
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T Saturation_UpperSat_pf;       /* Expression: 1
                                        * Referenced by: '<S29>/Saturation'
                                        */
  real_T Saturation_LowerSat_gl;       /* Expression: 0
                                        * Referenced by: '<S29>/Saturation'
                                        */
  real_T u9_Threshold_a;               /* Expression: 0.99
                                        * Referenced by: '<S30>/0.99'
                                        */
  real_T c_a_tpl1_eob15_Gain;          /* Expression: c_a_tpl1_eob/15
                                        * Referenced by: '<S2>/c_a_tpl1_eob//15 '
                                        */
  real_T atpl1_Gain;                   /* Expression: c_a_tpl1/15
                                        * Referenced by: '<S2>/atpl1'
                                        */
  real_T IpIp_div_Threshold_h;         /* Expression: Ip_div
                                        * Referenced by: '<S2>/Ip>Ip_div'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S2>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S2>/Saturation2'
                                        */
  real_T u5_Gain;                      /* Expression: 1/15
                                        * Referenced by: '<S2>/1//15'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S2>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: c_a_tpl_min
                                        * Referenced by: '<S2>/Saturation3'
                                        */
  real_T tt_eob1_Threshold;            /* Expression: t_eob
                                        * Referenced by: '<S2>/t>t_eob1'
                                        */
  real_T c_a_tpl1_eob15_Gain_l;        /* Expression: c_a_tpl1_eob/15
                                        * Referenced by: '<S2>/c_a_tpl1_eob//15'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S2>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: c_a_tpl_min
                                        * Referenced by: '<S2>/Saturation4'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_t15_2 {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
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
extern void t15_2_initialize(boolean_T firstTime);
extern void t15_2_step(void);
extern void t15_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_t15_2 *t15_2_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/A' : Unused code path elimination
 * Block '<Root>/A  ' : Unused code path elimination
 * Block '<S1>/To Workspace1' : Unused code path elimination
 * Block '<S1>/To Workspace2' : Unused code path elimination
 * Block '<S1>/To Workspace3' : Unused code path elimination
 * Block '<S2>/To Workspace' : Unused code path elimination
 * Block '<Root>/To Workspace1' : Unused code path elimination
 * Block '<Root>/To Workspace2' : Unused code path elimination
 * Block '<Root>/To Workspace21' : Unused code path elimination
 * Block '<Root>/To Workspace3' : Unused code path elimination
 * Block '<Root>/To Workspace5' : Unused code path elimination
 * Block '<Root>/To Workspace7' : Unused code path elimination
 * Block '<Root>/klim' : Unused code path elimination
 * Block '<Root>/m' : Unused code path elimination
 * Block '<Root>/m  ' : Unused code path elimination
 * Block '<Root>/m   ' : Unused code path elimination
 * Block '<Root>/rsep' : Unused code path elimination
 * Block '<Root>/rsep1' : Unused code path elimination
 * Block '<Root>/xleft' : Unused code path elimination
 * Block '<Root>/xright' : Unused code path elimination
 * Block '<Root>/zsep' : Unused code path elimination
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
 * '<Root>' : t15_2
 * '<S1>'   : t15_2/Control inputs 1
 * '<S2>'   : t15_2/Control2
 * '<S3>'   : t15_2/Subsystem
 * '<S4>'   : t15_2/Control inputs 1/Icoils ref
 * '<S5>'   : t15_2/Control inputs 1/Ipl ref
 * '<S6>'   : t15_2/Control inputs 1/Subsystem
 * '<S7>'   : t15_2/Control inputs 1/Subsystem1
 * '<S8>'   : t15_2/Control inputs 1/Subsystem4
 * '<S9>'   : t15_2/Control inputs 1/Icoils ref/Icoil1 ref
 * '<S10>'  : t15_2/Control inputs 1/Icoils ref/Icoil10 ref
 * '<S11>'  : t15_2/Control inputs 1/Icoils ref/Icoil11 ref
 * '<S12>'  : t15_2/Control inputs 1/Icoils ref/Icoil2 ref
 * '<S13>'  : t15_2/Control inputs 1/Icoils ref/Icoil3 ref
 * '<S14>'  : t15_2/Control inputs 1/Icoils ref/Icoil4 ref
 * '<S15>'  : t15_2/Control inputs 1/Icoils ref/Icoil5 ref
 * '<S16>'  : t15_2/Control inputs 1/Icoils ref/Icoil6 ref
 * '<S17>'  : t15_2/Control inputs 1/Icoils ref/Icoil7 ref
 * '<S18>'  : t15_2/Control inputs 1/Icoils ref/Icoil8 ref
 * '<S19>'  : t15_2/Control inputs 1/Icoils ref/Icoil9 ref
 * '<S20>'  : t15_2/Control inputs 1/Subsystem1/Difference
 * '<S21>'  : t15_2/Control inputs 1/Subsystem1/Difference1
 * '<S22>'  : t15_2/Control2/Pow. Supply
 * '<S23>'  : t15_2/Control2/Subsystem
 * '<S24>'  : t15_2/Control2/Subsystem1
 * '<S25>'  : t15_2/Control2/Subsystem2
 * '<S26>'  : t15_2/Control2/Subsystem3
 * '<S27>'  : t15_2/Control2/Subsystem4
 * '<S28>'  : t15_2/Control2/Subsystem5
 * '<S29>'  : t15_2/Control2/Subsystem6
 * '<S30>'  : t15_2/Control2/Subsystem7
 * '<S31>'  : t15_2/Control2/Subsystem8
 * '<S32>'  : t15_2/Control2/Subsystem9
 * '<S33>'  : t15_2/Control2/Volt
 * '<S34>'  : t15_2/Control2/atpl2 eob
 * '<S35>'  : t15_2/Control2/dzdt noise
 * '<S36>'  : t15_2/Control2/Pow. Supply /Difference
 * '<S37>'  : t15_2/Control2/Subsystem/Compare To Constant
 * '<S38>'  : t15_2/Control2/Subsystem/Compare To Zero
 * '<S39>'  : t15_2/Control2/Subsystem1/Compare To Constant
 * '<S40>'  : t15_2/Control2/Subsystem1/Difference
 * '<S41>'  : t15_2/Control2/Subsystem2/Difference
 * '<S42>'  : t15_2/Control2/Subsystem3/Difference
 * '<S43>'  : t15_2/Control2/Subsystem4/Compare To Constant
 * '<S44>'  : t15_2/Control2/Subsystem4/Compare To Constant1
 * '<S45>'  : t15_2/Control2/Subsystem4/Compare To Constant2
 * '<S46>'  : t15_2/Control2/Subsystem4/Difference
 * '<S47>'  : t15_2/Control2/Subsystem5/Difference
 * '<S48>'  : t15_2/Control2/Subsystem6/Compare To Constant
 * '<S49>'  : t15_2/Control2/Subsystem6/Compare To Constant1
 * '<S50>'  : t15_2/Control2/Subsystem6/Compare To Constant2
 * '<S51>'  : t15_2/Control2/Subsystem6/Difference
 * '<S52>'  : t15_2/Control2/Subsystem7/Compare To Constant
 * '<S53>'  : t15_2/Control2/Subsystem7/Compare To Constant1
 * '<S54>'  : t15_2/Control2/Subsystem7/Compare To Constant2
 * '<S55>'  : t15_2/Control2/Subsystem8/Compare To Constant
 * '<S56>'  : t15_2/Control2/Subsystem8/Compare To Constant1
 * '<S57>'  : t15_2/Control2/Subsystem8/Compare To Constant2
 */
#endif                                 /* RTW_HEADER_t15_2_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
