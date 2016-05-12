/*
 * File: t15_2.h
 *
 * Real-Time Workshop code generated for Simulink model t15_2.
 *
 * Model version                        : 1.1128
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Thu Mar 24 12:39:33 2016
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Thu Mar 24 12:39:34 2016
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
#include "rt_SATURATE.h"
#include "rt_look.h"
#include "rt_look1d.h"
#include "rt_nonfinite.h"
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

/* Block signals (auto storage) */
typedef struct {
  real_T Memory[11];                   /* '<S3>/Memory' */
  real_T Uk1;                          /* '<S61>/UD' */
  real_T Diff;                         /* '<S61>/Diff' */
  real_T Divide[11];                   /* '<S3>/Divide' */
  real_T RateLimiter[11];              /* '<S3>/Rate Limiter' */
  real_T Gain;                         /* '<S3>/Gain' */
  real_T Divide1[11];                  /* '<S3>/Divide1' */
  real_T Saturation6[11];              /* '<S3>/Saturation6' */
  real_T e6;                           /* '<S1>/1e-6' */
  real_T LogicalOperator2;             /* '<S41>/Logical Operator2' */
  real_T LogicalOperator1;             /* '<S41>/Logical Operator1' */
  real_T UniformRandomNumber;          /* '<S43>/Uniform Random Number' */
  real_T Uk1_a;                        /* '<S31>/UD' */
  real_T Uk1_g;                        /* '<S32>/UD' */
  real_T e6_l[15];                     /* '<S1>/1e-6   ' */
  real_T tt_tran2d[2];                 /* '<S2>/t>t_tran2d' */
  real_T VScontr[12];                  /* '<S38>/VS. contr' */
  real_T Memory2;                      /* '<S9>/Memory2' */
  real_T Add3;                         /* '<S9>/Add3' */
  real_T Memory1;                      /* '<S9>/Memory1' */
  real_T Ics1_eob;                     /* '<S9>/Ics1_eob' */
  real_T Add2;                         /* '<S9>/Add2' */
  real_T dtpl_term_l;                  /* '<S9>/dtpl_term_l' */
  real_T Add1;                         /* '<S9>/Add1' */
  real_T u;                            /* '<S9>/1 0' */
  real_T RelationalOperator;           /* '<S38>/Relational Operator' */
  real_T Divide4[2];                   /* '<S38>/Divide4' */
  real_T VScontrhl[12];                /* '<S38>/VS. contr hl' */
  real_T c_eob[12];                    /* '<S38>/c_eob' */
  real_T LogicalOperator1_m;           /* '<S37>/Logical Operator1' */
  real_T u9[12];                       /* '<S37>/0.99' */
  real_T Divide10[12];                 /* '<S2>/Divide10' */
  real_T SaturationVS[12];             /* '<S4>/Saturation VS' */
  real_T Add1_b[11];                   /* '<Root>/Add1' */
  real_T TmpSignalConversionAtnpf12Inpor[12];/* 'synthesized block' */
  real_T npf12[15];                    /* '<Root>/npf,12' */
  real_T Memory2_f;                    /* '<Root>/Memory2' */
  real_T u_o;                          /* '<Root>/-1' */
  real_T IpIp_0;                       /* '<Root>/Ip<Ip_0 ' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Memory1_h;                    /* '<S7>/Memory1' */
  real_T c_eob_f;                      /* '<S7>/c_eob' */
  real_T Divide6;                      /* '<S7>/Divide6' */
  real_T Add1_o;                       /* '<S1>/Add1' */
  real_T Memory2_l;                    /* '<S15>/Memory2' */
  real_T c_eob_c;                      /* '<S15>/c_eob' */
  real_T Divide1_l;                    /* '<S15>/Divide1' */
  real_T Add1_oq;                      /* '<S6>/Add1' */
  real_T Memory2_k;                    /* '<S13>/Memory2' */
  real_T c_eob_p;                      /* '<S13>/c_eob' */
  real_T Divide1_h;                    /* '<S13>/Divide1' */
  real_T Add10;                        /* '<S6>/Add10' */
  real_T Memory2_e;                    /* '<S14>/Memory2' */
  real_T c_eob_o;                      /* '<S14>/c_eob' */
  real_T Divide1_i;                    /* '<S14>/Divide1' */
  real_T Add11;                        /* '<S6>/Add11' */
  real_T Memory2_l4;                   /* '<S16>/Memory2' */
  real_T c_eob_k;                      /* '<S16>/c_eob' */
  real_T Divide1_e;                    /* '<S16>/Divide1' */
  real_T Add2_d;                       /* '<S6>/Add2' */
  real_T Memory2_o;                    /* '<S12>/Memory2' */
  real_T c_eob_kq;                     /* '<S12>/c_eob' */
  real_T Divide1_g;                    /* '<S12>/Divide1' */
  real_T Add3_a;                       /* '<S6>/Add3' */
  real_T Memory2_h;                    /* '<S17>/Memory2' */
  real_T c_eob_p1;                     /* '<S17>/c_eob' */
  real_T Divide1_la;                   /* '<S17>/Divide1' */
  real_T Add4;                         /* '<S6>/Add4' */
  real_T Memory2_a;                    /* '<S18>/Memory2' */
  real_T c_eob_l;                      /* '<S18>/c_eob' */
  real_T Divide1_hp;                   /* '<S18>/Divide1' */
  real_T Add5;                         /* '<S6>/Add5' */
  real_T Memory2_m;                    /* '<S19>/Memory2' */
  real_T c_eob_b;                      /* '<S19>/c_eob' */
  real_T Divide1_f;                    /* '<S19>/Divide1' */
  real_T Add6;                         /* '<S6>/Add6' */
  real_T Memory2_o2;                   /* '<S20>/Memory2' */
  real_T c_eob_g;                      /* '<S20>/c_eob' */
  real_T Divide1_a;                    /* '<S20>/Divide1' */
  real_T Add7;                         /* '<S6>/Add7' */
  real_T Memory2_b;                    /* '<S21>/Memory2' */
  real_T c_eob_d;                      /* '<S21>/c_eob' */
  real_T Divide1_fa;                   /* '<S21>/Divide1' */
  real_T Add8;                         /* '<S6>/Add8' */
  real_T Memory2_o5;                   /* '<S22>/Memory2' */
  real_T c_eob_fg;                     /* '<S22>/c_eob' */
  real_T Divide1_ap;                   /* '<S22>/Divide1' */
  real_T Add9;                         /* '<S6>/Add9' */
  real_T LookupTable1;                 /* '<S6>/Lookup Table1' */
  real_T Divide6_l;                    /* '<S6>/Divide6' */
  real_T Sum2_f;                       /* '<S5>/Sum2' */
  real_T u_a;                          /* '<S5>/>=0' */
  real_T e2[6];                        /* '<S8>/1e2' */
  real_T Memory1_d;                    /* '<S23>/Memory1' */
  real_T c_eob_gq;                     /* '<S23>/c_eob  ' */
  real_T c_eob_d1;                     /* '<S23>/c_eob' */
  real_T Add2_i;                       /* '<S8>/Add2' */
  real_T LookupTable1_b;               /* '<S8>/Lookup Table1' */
  real_T Divide6_i;                    /* '<S8>/Divide6' */
  real_T Memory1_e;                    /* '<S24>/Memory1' */
  real_T c_eob_o2;                     /* '<S24>/c_eob ' */
  real_T c_eob_e;                      /* '<S24>/c_eob' */
  real_T Add1_j;                       /* '<S8>/Add1' */
  real_T LookupTable2;                 /* '<S8>/Lookup Table2' */
  real_T Divide1_k;                    /* '<S8>/Divide1' */
  real_T Memory1_f;                    /* '<S25>/Memory1' */
  real_T c_eob_k5;                     /* '<S25>/c_eob ' */
  real_T c_eob_kv;                     /* '<S25>/c_eob' */
  real_T Add3_b;                       /* '<S8>/Add3' */
  real_T Memory1_dh;                   /* '<S26>/Memory1' */
  real_T c_eob_i;                      /* '<S26>/c_eob  ' */
  real_T c_eob_ij;                     /* '<S26>/c_eob' */
  real_T Add4_j;                       /* '<S8>/Add4' */
  real_T LookupTable3;                 /* '<S8>/Lookup Table3' */
  real_T Divide2;                      /* '<S8>/Divide2' */
  real_T Memory1_g;                    /* '<S27>/Memory1' */
  real_T c_eob_e1;                     /* '<S27>/c_eob  ' */
  real_T c_eob_bo;                     /* '<S27>/c_eob' */
  real_T Add5_k;                       /* '<S8>/Add5' */
  real_T g6_ref;                       /* '<S28>/g6_ref' */
  real_T Memory2_m4;                   /* '<S28>/Memory2' */
  real_T c_eob1;                       /* '<S28>/c_eob  1' */
  real_T Memory1_dn;                   /* '<S28>/Memory1' */
  real_T c_eob_lg;                     /* '<S28>/c_eob  ' */
  real_T c_eob_fd;                     /* '<S28>/c_eob' */
  real_T Add6_g;                       /* '<S8>/Add6' */
  real_T e2_g[6];                      /* '<S8>/1e-2' */
  real_T e6_e;                         /* '<S9>/1e6' */
  real_T LogicalOperator1_a;           /* '<S10>/Logical Operator1' */
  real_T u9_a[20];                     /* '<S10>/0.99' */
  real_T e3_m[11];                     /* '<S33>/1e3' */
  real_T Abs[11];                      /* '<S33>/Abs' */
  real_T ntur[11];                     /* '<S33>/ntur' */
  real_T Sum2_p[11];                   /* '<S33>/Sum2' */
  real_T c_cur_max[11];                /* '<S33>/c_cur_max' */
  real_T Sum1[11];                     /* '<S33>/Sum1' */
  real_T Divide4_j[11];                /* '<S33>/Divide4' */
  real_T Divide1_j[11];                /* '<S33>/Divide1' */
  real_T Saturation[11];               /* '<S33>/Saturation' */
  real_T Memory1_eo[11];               /* '<S34>/Memory1' */
  real_T LogicalOperator2_o;           /* '<S34>/Logical Operator2' */
  real_T Memory_m[11];                 /* '<S36>/Memory' */
  real_T LogicalOperator1_h;           /* '<S36>/Logical Operator1' */
  real_T Memory3;                      /* '<S44>/Memory3' */
  real_T LogicalOperator1_c;           /* '<S44>/Logical Operator1' */
  real_T u999;                         /* '<S44>/0.9999' */
  real_T Subtract2;                    /* '<S44>/Subtract2' */
  real_T Gain1;                        /* '<S44>/Gain1' */
  real_T Subtract1;                    /* '<S44>/Subtract1' */
  real_T Saturation1;                  /* '<S44>/Saturation1' */
  real_T Divide2_j[20];                /* '<S2>/Divide2' */
  real_T Divcontr[11];                 /* '<S2>/Div. contr.' */
  real_T u9_d[11];                     /* '<S36>/0.99' */
  real_T Memory1_n;                    /* '<S42>/Memory1' */
  real_T LogicalOperator1_d;           /* '<S42>/Logical Operator1' */
  real_T u999_b;                       /* '<S42>/0.9999' */
  real_T Divide13[20];                 /* '<S2>/Divide13' */
  real_T Div_rdcontr[11];              /* '<S2>/Div_rd contr' */
  real_T Memory1_b;                    /* '<S40>/Memory1' */
  real_T c_eob_fp;                     /* '<S40>/c_eob' */
  real_T u99[11];                      /* '<S34>/0.999' */
  real_T Memory1_k;                    /* '<S41>/Memory1' */
  real_T u999_l;                       /* '<S41>/0.9999' */
  real_T Subtract2_k;                  /* '<S41>/Subtract2' */
  real_T Gain1_g;                      /* '<S41>/Gain1' */
  real_T Subtract3;                    /* '<S41>/Subtract3' */
  real_T Saturation_a;                 /* '<S41>/Saturation' */
  real_T Divide4_a[11];                /* '<S2>/Divide4' */
  real_T Currtermcontr[11];            /* '<S2>/Curr. term. contr' */
  real_T Gain2;                        /* '<S41>/Gain2' */
  real_T Subtract1_k;                  /* '<S41>/Subtract1' */
  real_T Divide5[11];                  /* '<S2>/Divide5' */
  real_T Memory2_fo[11];               /* '<S2>/Memory2' */
  real_T tcont2[20];                   /* '<S35>/tcont2 ' */
  real_T Limcontr[11];                 /* '<S35>/Lim. contr.' */
  real_T Currcontr[11];                /* '<S35>/Curr. contr.' */
  real_T IpIp_div[11];                 /* '<S2>/Ip>Ip_div ' */
  real_T Divide6_iz[11];               /* '<S2>/Divide6' */
  real_T volt1;                        /* '<S39>/volt1' */
  real_T volt2;                        /* '<S39>/volt2' */
  real_T volt3;                        /* '<S39>/volt3' */
  real_T volt4;                        /* '<S39>/volt4' */
  real_T volt5;                        /* '<S39>/volt5' */
  real_T volt6;                        /* '<S39>/volt6' */
  real_T volt7;                        /* '<S39>/volt7' */
  real_T volt8;                        /* '<S39>/volt8' */
  real_T volt9;                        /* '<S39>/volt9' */
  real_T volt10;                       /* '<S39>/volt10' */
  real_T volt11;                       /* '<S39>/volt11' */
  real_T Divide7[11];                  /* '<S2>/Divide7' */
  real_T Sum3[11];                     /* '<S2>/Sum3' */
  real_T Divide2_e[11];                /* '<S33>/Divide2' */
  real_T Sum3_f[11];                   /* '<S33>/Sum3' */
  real_T Saturation1_m[11];            /* '<S33>/Saturation1' */
  real_T Divide6_p[11];                /* '<S33>/Divide6' */
  real_T Divide12[20];                 /* '<S2>/Divide12' */
  real_T ntur_n[11];                   /* '<S35>/1//ntur' */
  real_T Add;                          /* '<S3>/Add' */
  real_T Divide2_d[11];                /* '<S3>/Divide2' */
  real_T Tfmc[11];                     /* '<S3>/Tfmc ' */
  real_T Add1_e[11];                   /* '<S3>/Add1' */
  real_T Divide3[11];                  /* '<S3>/Divide3' */
  real_T Ipl_ref;                      /* '<S40>/Ipl_ref' */
  real_T c_a_tpl1_eob15;               /* '<S2>/c_a_tpl1_eob//15' */
  real_T Saturation4;                  /* '<S2>/Saturation4' */
  real_T Divide11[12];                 /* '<S2>/Divide11' */
  real_T c_eob_pt[12];                 /* '<S2>/c_eob ' */
  real_T IpIp_div_l;                   /* '<S2>/Ip>Ip_div' */
  real_T Saturation2;                  /* '<S2>/Saturation2' */
  real_T Divide8[12];                  /* '<S2>/Divide8' */
  real_T atpl1;                        /* '<S2>/atpl1' */
  real_T c_a_tpl1_eob15_l;             /* '<S2>/c_a_tpl1_eob//15 ' */
  real_T u5;                           /* '<S2>/1//15' */
  real_T Saturation3;                  /* '<S2>/Saturation3' */
  real_T Divide9[12];                  /* '<S2>/Divide9' */
  real_T Subtract3_a;                  /* '<S44>/Subtract3' */
  real_T Divide_e[11];                 /* '<S2>/Divide' */
  real_T Subtract2_b;                  /* '<S42>/Subtract2' */
  real_T Gain1_n;                      /* '<S42>/Gain1' */
  real_T Subtract3_k;                  /* '<S42>/Subtract3' */
  real_T Saturation_i;                 /* '<S42>/Saturation' */
  real_T Subtract1_f;                  /* '<S42>/Subtract1' */
  real_T c_eob_j;                      /* '<S2>/c_eob' */
  real_T Divide3_g[11];                /* '<S2>/Divide3' */
  real_T Divide1_b[11];                /* '<S2>/Divide1' */
  real_T Sum2_i[11];                   /* '<S2>/Sum2' */
  real_T atpl2;                        /* '<S2>/atpl2' */
  real_T Saturation_a1;                /* '<S2>/Saturation' */
  real_T Divide6_o;                    /* '<S40>/Divide6' */
  real_T Sum;                          /* '<S40>/Sum' */
  real_T Divide2_h;                    /* '<S40>/Divide2' */
  real_T Sum1_k;                       /* '<S40>/Sum1' */
  real_T uy0;                          /* '<S40>/[1 y0]' */
  real_T tcont2_b[11];                 /* '<S35>/tcont2' */
  real_T gain_cont2;                   /* '<S35>/gain_cont2' */
  real_T Divide_d[11];                 /* '<S35>/Divide ' */
  real_T ntur_d[11];                   /* '<S35>/1//ntur ' */
  real_T Diff_b;                       /* '<S32>/Diff' */
  real_T Diff_n;                       /* '<S31>/Diff' */
  real_T Divide_i;                     /* '<S11>/Divide' */
  real_T Sum2_d;                       /* '<S43>/Sum2' */
  real_T elong_ref;                    /* '<S1>/elong_ref' */
  real_T Add2_f;                       /* '<S1>/Add2' */
  real_T k_gaplim[4];                  /* '<S1>/k_gaplim' */
  real_T Add2_ft;                      /* '<S28>/Add2' */
  real_T g6_ref_term;                  /* '<S28>/g6_ref_term' */
  real_T Add1_f;                       /* '<S28>/Add1' */
  real_T g5_ref;                       /* '<S27>/g5_ref' */
  real_T Add2_g;                       /* '<S27>/Add2' */
  real_T g5_ref_term;                  /* '<S27>/g5_ref_term' */
  real_T g4_ref;                       /* '<S26>/g4_ref' */
  real_T Add2_o;                       /* '<S26>/Add2' */
  real_T g4_ref_term;                  /* '<S26>/g4_ref_term' */
  real_T g3_ref;                       /* '<S25>/g3_ref' */
  real_T Add2_iv;                      /* '<S25>/Add2' */
  real_T g3_ref_term;                  /* '<S25>/g3_ref_term' */
  real_T g2_ref;                       /* '<S24>/g2_ref' */
  real_T Add2_e;                       /* '<S24>/Add2' */
  real_T g2_ref_term;                  /* '<S24>/g2_ref_term' */
  real_T g1_ref;                       /* '<S23>/g1_ref' */
  real_T Add2_a;                       /* '<S23>/Add2' */
  real_T g1_ref_term;                  /* '<S23>/g1_ref_term' */
  real_T Ipl_ref_g;                    /* '<S7>/Ipl_ref' */
  real_T Icoil9_ref;                   /* '<S22>/Icoil9_ref' */
  real_T Icoil8_ref;                   /* '<S21>/Icoil8_ref' */
  real_T Icoil1_ref;                   /* '<S20>/Icoil1_ref' */
  real_T Icoil6_ref;                   /* '<S19>/Icoil6_ref' */
  real_T Icoil5_ref;                   /* '<S18>/Icoil5_ref' */
  real_T Icoil4_ref;                   /* '<S17>/Icoil4_ref' */
  real_T Icoil3_ref;                   /* '<S16>/Icoil3_ref' */
  real_T Icoil2_ref;                   /* '<S15>/Icoil2_ref' */
  real_T Icoil11_ref;                  /* '<S14>/Icoil11_ref' */
  real_T Icoil10_ref;                  /* '<S13>/Icoil10_ref' */
  real_T Icoil1_ref_k;                 /* '<S12>/Icoil1_ref' */
  uint8_T Compare;                     /* '<S55>/Compare' */
  uint8_T Compare_e;                   /* '<S56>/Compare' */
  uint8_T Compare_a;                   /* '<S52>/Compare' */
  uint8_T Compare_ev;                  /* '<S53>/Compare' */
  uint8_T Compare_n;                   /* '<S54>/Compare' */
  uint8_T Compare_l;                   /* '<S29>/Compare' */
  uint8_T Compare_h;                   /* '<S30>/Compare' */
  uint8_T Compare_lm[11];              /* '<S45>/Compare' */
  uint8_T Compare_hj;                  /* '<S47>/Compare' */
  uint8_T Compare_m;                   /* '<S48>/Compare' */
  uint8_T Compare_i;                   /* '<S49>/Compare' */
  uint8_T Compare_iq;                  /* '<S50>/Compare' */
  uint8_T Compare_c;                   /* '<S51>/Compare' */
  uint8_T Compare_eq;                  /* '<S59>/Compare' */
  uint8_T Compare_ec;                  /* '<S60>/Compare' */
  uint8_T Compare_ej;                  /* '<S57>/Compare' */
  uint8_T Compare_in;                  /* '<S58>/Compare' */
  uint8_T Compare_k[11];               /* '<S46>/Compare' */
  boolean_T RelationalOperator_a;      /* '<Root>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<Root>/Relational Operator1' */
  boolean_T LogicalOperator[11];       /* '<S33>/Logical Operator' */
} BlockIO_t15_2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S61>/UD' */
  real_T UD_DSTATE_n;                  /* '<S31>/UD' */
  real_T UD_DSTATE_h;                  /* '<S32>/UD' */
  real_T VScontr_DSTATE[9];            /* '<S38>/VS. contr' */
  real_T VScontrhl_DSTATE[8];          /* '<S38>/VS. contr hl' */
  real_T Divcontr_DSTATE[50];          /* '<S2>/Div. contr.' */
  real_T Div_rdcontr_DSTATE[40];       /* '<S2>/Div_rd contr' */
  real_T Currtermcontr_DSTATE[40];     /* '<S2>/Curr. term. contr' */
  real_T Limcontr_DSTATE[50];          /* '<S35>/Lim. contr.' */
  real_T Currcontr_DSTATE[11];         /* '<S35>/Curr. contr.' */
  real_T Memory_PreviousInput[11];     /* '<S3>/Memory' */
  real_T PrevY[11];                    /* '<S3>/Rate Limiter' */
  real_T UniformRandomNumber_NextOutput;/* '<S43>/Uniform Random Number' */
  real_T Memory2_PreviousInput;        /* '<S9>/Memory2' */
  real_T Memory1_PreviousInput;        /* '<S9>/Memory1' */
  real_T Memory2_PreviousInput_g;      /* '<Root>/Memory2' */
  real_T Memory1_PreviousInput_n;      /* '<S7>/Memory1' */
  real_T Memory2_PreviousInput_b;      /* '<S15>/Memory2' */
  real_T Memory2_PreviousInput_a;      /* '<S13>/Memory2' */
  real_T Memory2_PreviousInput_n;      /* '<S14>/Memory2' */
  real_T Memory2_PreviousInput_bt;     /* '<S16>/Memory2' */
  real_T Memory2_PreviousInput_c;      /* '<S12>/Memory2' */
  real_T Memory2_PreviousInput_i;      /* '<S17>/Memory2' */
  real_T Memory2_PreviousInput_bh;     /* '<S18>/Memory2' */
  real_T Memory2_PreviousInput_m;      /* '<S19>/Memory2' */
  real_T Memory2_PreviousInput_ns;     /* '<S20>/Memory2' */
  real_T Memory2_PreviousInput_gb;     /* '<S21>/Memory2' */
  real_T Memory2_PreviousInput_gn;     /* '<S22>/Memory2' */
  real_T Memory1_PreviousInput_e;      /* '<S23>/Memory1' */
  real_T Memory1_PreviousInput_h;      /* '<S24>/Memory1' */
  real_T Memory1_PreviousInput_f;      /* '<S25>/Memory1' */
  real_T Memory1_PreviousInput_p;      /* '<S26>/Memory1' */
  real_T Memory1_PreviousInput_i;      /* '<S27>/Memory1' */
  real_T Memory2_PreviousInput_o;      /* '<S28>/Memory2' */
  real_T Memory1_PreviousInput_c;      /* '<S28>/Memory1' */
  real_T Memory1_PreviousInput_er[11]; /* '<S34>/Memory1' */
  real_T Memory_PreviousInput_i[11];   /* '<S36>/Memory' */
  real_T Memory3_PreviousInput;        /* '<S44>/Memory3' */
  real_T Memory1_PreviousInput_a;      /* '<S42>/Memory1' */
  real_T Memory1_PreviousInput_ek;     /* '<S40>/Memory1' */
  real_T Memory1_PreviousInput_j;      /* '<S41>/Memory1' */
  real_T Memory2_PreviousInput_j[11];  /* '<S2>/Memory2' */
  real_T Sum3_DWORK1[11];              /* '<S33>/Sum3' */
  uint32_T RandSeed;                   /* '<S43>/Uniform Random Number' */
} D_Work_t15_2;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1[15];                      /* '<Root>/In1' */
  real_T In2[123];                     /* '<Root>/In2' */
} ExternalInputs_t15_2;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1[38];                     /* '<Root>/Out1' */
  real_T Time;                         /* '<Root>/Time' */
} ExternalOutputs_t15_2;

/* Parameters (auto storage) */
struct Parameters_t15_2_ {
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T SimStep_Value;                /* Expression: SimStep
                                        * Referenced by: '<S3>/SimStep'
                                        */
  real_T e3_Gain;                      /* Expression: 1e-3
                                        * Referenced by: '<Root>/1e-3'
                                        */
  real_T UD_X0;                        /* Expression: ICPrevInput
                                        * Referenced by: '<S61>/UD'
                                        */
  real_T RateLimiter_RisingLim[11];    /* Computed Parameter: RateLimiter_RisingLim
                                        * Referenced by: '<S3>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim[11];   /* Computed Parameter: RateLimiter_FallingLim
                                        * Referenced by: '<S3>/Rate Limiter'
                                        */
  real_T RateLimiter_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Rate Limiter'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/SimStep
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Saturation6_UpperSat[11];     /* Expression: Vmc_up
                                        * Referenced by: '<S3>/Saturation6'
                                        */
  real_T Saturation6_LowerSat[11];     /* Expression: Vmc_low
                                        * Referenced by: '<S3>/Saturation6'
                                        */
  real_T e6_Gain;                      /* Expression: 1e-6
                                        * Referenced by: '<S1>/1e-6'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: const
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T UniformRandomNumber_Minimum;  /* Expression: -amp_noise
                                        * Referenced by: '<S43>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: amp_noise
                                        * Referenced by: '<S43>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S43>/Uniform Random Number'
                                        */
  real_T UD_X0_e;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S31>/UD'
                                        */
  real_T UD_X0_h;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S32>/UD'
                                        */
  real_T e6_Gain_h;                    /* Expression: 1e-6
                                        * Referenced by: '<S1>/1e-6   '
                                        */
  real_T tt_tran2d_Threshold;          /* Expression: t_tran2D
                                        * Referenced by: '<S2>/t>t_tran2d'
                                        */
  real_T VScontr_A[34];                /* Computed Parameter: VScontr_A
                                        * Referenced by: '<S38>/VS. contr'
                                        */
  real_T VScontr_B[16];                /* Computed Parameter: VScontr_B
                                        * Referenced by: '<S38>/VS. contr'
                                        */
  real_T VScontr_C[25];                /* Computed Parameter: VScontr_C
                                        * Referenced by: '<S38>/VS. contr'
                                        */
  real_T VScontr_D[10];                /* Computed Parameter: VScontr_D
                                        * Referenced by: '<S38>/VS. contr'
                                        */
  real_T VScontr_X0;                   /* Expression: 0
                                        * Referenced by: '<S38>/VS. contr'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S9>/Memory2'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S9>/Memory1'
                                        */
  real_T Ics1_eob_Threshold;           /* Expression: Ics1_eob
                                        * Referenced by: '<S9>/Ics1_eob'
                                        */
  real_T dtpl_term_l_Gain;             /* Expression: 1/dtpl_term_l
                                        * Referenced by: '<S9>/dtpl_term_l'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S9>/Constant4'
                                        */
  real_T u_UpperSat;                   /* Expression: 1
                                        * Referenced by: '<S9>/1 0'
                                        */
  real_T u_LowerSat;                   /* Expression: 0
                                        * Referenced by: '<S9>/1 0'
                                        */
  real_T c_eob_Value;                  /* Expression: c_eob
                                        * Referenced by: '<S38>/c_eob '
                                        */
  real_T VScontrhl_A[33];              /* Computed Parameter: VScontrhl_A
                                        * Referenced by: '<S38>/VS. contr hl'
                                        */
  real_T VScontrhl_B[15];              /* Computed Parameter: VScontrhl_B
                                        * Referenced by: '<S38>/VS. contr hl'
                                        */
  real_T VScontrhl_C[24];              /* Computed Parameter: VScontrhl_C
                                        * Referenced by: '<S38>/VS. contr hl'
                                        */
  real_T VScontrhl_D[10];              /* Computed Parameter: VScontrhl_D
                                        * Referenced by: '<S38>/VS. contr hl'
                                        */
  real_T VScontrhl_X0;                 /* Expression: 0
                                        * Referenced by: '<S38>/VS. contr hl'
                                        */
  real_T c_eob_Threshold;              /* Expression: c_eob
                                        * Referenced by: '<S38>/c_eob'
                                        */
  real_T Constant_Value_p;             /* Expression: const
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: const
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: const
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T u9_Threshold;                 /* Expression: 0.99
                                        * Referenced by: '<S37>/0.99'
                                        */
  real_T SaturationVS_UpperSat[12];    /* Expression: VS_up
                                        * Referenced by: '<S4>/Saturation VS'
                                        */
  real_T SaturationVS_LowerSat[12];    /* Expression: VS_low
                                        * Referenced by: '<S4>/Saturation VS'
                                        */
  real_T npf12_Gain[180];              /* Expression: eye(npf,n_mc+1)
                                        * Referenced by: '<Root>/npf,12'
                                        */
  real_T Memory2_X0_k;                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory2'
                                        */
  real_T u_Gain;                       /* Expression: -1
                                        * Referenced by: '<Root>/-1'
                                        */
  real_T IpIp_0_Threshold;             /* Expression: -Ip_0
                                        * Referenced by: '<Root>/Ip<Ip_0 '
                                        */
  real_T dt_end_sim_Value;             /* Expression: dt_end_sim
                                        * Referenced by: '<Root>/dt_end_sim'
                                        */
  real_T Time_stop_Value;              /* Expression: Time_stop
                                        * Referenced by: '<Root>/Time_stop'
                                        */
  real_T Memory1_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S7>/Memory1'
                                        */
  real_T c_eob_Threshold_c;            /* Expression: c_eob
                                        * Referenced by: '<S7>/c_eob'
                                        */
  real_T Constant4_Value_h;            /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Memory2_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S15>/Memory2'
                                        */
  real_T c_eob_Threshold_m;            /* Expression: c_eob
                                        * Referenced by: '<S15>/c_eob'
                                        */
  real_T Memory2_X0_n;                 /* Expression: 0
                                        * Referenced by: '<S13>/Memory2'
                                        */
  real_T c_eob_Threshold_o;            /* Expression: c_eob
                                        * Referenced by: '<S13>/c_eob'
                                        */
  real_T Memory2_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S14>/Memory2'
                                        */
  real_T c_eob_Threshold_j;            /* Expression: c_eob
                                        * Referenced by: '<S14>/c_eob'
                                        */
  real_T Memory2_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S16>/Memory2'
                                        */
  real_T c_eob_Threshold_a;            /* Expression: c_eob
                                        * Referenced by: '<S16>/c_eob'
                                        */
  real_T Memory2_X0_i;                 /* Expression: 0
                                        * Referenced by: '<S12>/Memory2'
                                        */
  real_T c_eob_Threshold_n;            /* Expression: c_eob
                                        * Referenced by: '<S12>/c_eob'
                                        */
  real_T Memory2_X0_l;                 /* Expression: 0
                                        * Referenced by: '<S17>/Memory2'
                                        */
  real_T c_eob_Threshold_jj;           /* Expression: c_eob
                                        * Referenced by: '<S17>/c_eob'
                                        */
  real_T Memory2_X0_d;                 /* Expression: 0
                                        * Referenced by: '<S18>/Memory2'
                                        */
  real_T c_eob_Threshold_b;            /* Expression: c_eob
                                        * Referenced by: '<S18>/c_eob'
                                        */
  real_T Memory2_X0_n4;                /* Expression: 0
                                        * Referenced by: '<S19>/Memory2'
                                        */
  real_T c_eob_Threshold_g;            /* Expression: c_eob
                                        * Referenced by: '<S19>/c_eob'
                                        */
  real_T Memory2_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S20>/Memory2'
                                        */
  real_T c_eob_Threshold_l;            /* Expression: c_eob
                                        * Referenced by: '<S20>/c_eob'
                                        */
  real_T Memory2_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S21>/Memory2'
                                        */
  real_T c_eob_Threshold_gv;           /* Expression: c_eob
                                        * Referenced by: '<S21>/c_eob'
                                        */
  real_T Memory2_X0_dl;                /* Expression: 0
                                        * Referenced by: '<S22>/Memory2'
                                        */
  real_T c_eob_Threshold_l4;           /* Expression: c_eob
                                        * Referenced by: '<S22>/c_eob'
                                        */
  real_T LookupTable1_XData[4];        /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S6>/Lookup Table1'
                                        */
  real_T LookupTable1_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S6>/Lookup Table1'
                                        */
  real_T u_Threshold;                  /* Expression: 0
                                        * Referenced by: '<S5>/>=0'
                                        */
  real_T e2_Gain;                      /* Expression: 1e2
                                        * Referenced by: '<S8>/1e2'
                                        */
  real_T Memory1_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S23>/Memory1'
                                        */
  real_T c_eob_Threshold_d;            /* Expression: c_eob
                                        * Referenced by: '<S23>/c_eob  '
                                        */
  real_T c_eob_Threshold_k;            /* Expression: c_eob
                                        * Referenced by: '<S23>/c_eob'
                                        */
  real_T LookupTable1_XData_o[4];      /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S8>/Lookup Table1'
                                        */
  real_T LookupTable1_YData_k[4];      /* Expression: [0 0 1 1]
                                        * Referenced by: '<S8>/Lookup Table1'
                                        */
  real_T Memory1_X0_h;                 /* Expression: 0
                                        * Referenced by: '<S24>/Memory1'
                                        */
  real_T c_eob_Threshold_ly;           /* Expression: c_eob
                                        * Referenced by: '<S24>/c_eob '
                                        */
  real_T c_eob_Threshold_bf;           /* Expression: c_eob
                                        * Referenced by: '<S24>/c_eob'
                                        */
  real_T LookupTable2_XData[4];        /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S8>/Lookup Table2'
                                        */
  real_T LookupTable2_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S8>/Lookup Table2'
                                        */
  real_T Memory1_X0_i;                 /* Expression: 0
                                        * Referenced by: '<S25>/Memory1'
                                        */
  real_T c_eob_Threshold_b1;           /* Expression: c_eob
                                        * Referenced by: '<S25>/c_eob '
                                        */
  real_T c_eob_Threshold_p;            /* Expression: c_eob
                                        * Referenced by: '<S25>/c_eob'
                                        */
  real_T Memory1_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S26>/Memory1'
                                        */
  real_T c_eob_Threshold_mj;           /* Expression: c_eob
                                        * Referenced by: '<S26>/c_eob  '
                                        */
  real_T c_eob_Threshold_dc;           /* Expression: c_eob
                                        * Referenced by: '<S26>/c_eob'
                                        */
  real_T LookupTable3_XData[4];        /* Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
                                        * Referenced by: '<S8>/Lookup Table3'
                                        */
  real_T LookupTable3_YData[4];        /* Expression: [0 0 1 1]
                                        * Referenced by: '<S8>/Lookup Table3'
                                        */
  real_T Memory1_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S27>/Memory1'
                                        */
  real_T c_eob_Threshold_ll;           /* Expression: c_eob
                                        * Referenced by: '<S27>/c_eob  '
                                        */
  real_T c_eob_Threshold_ps;           /* Expression: c_eob
                                        * Referenced by: '<S27>/c_eob'
                                        */
  real_T g6_ref_XData[7];              /* Expression: g6_ref(:,1)
                                        * Referenced by: '<S28>/g6_ref'
                                        */
  real_T g6_ref_YData[7];              /* Expression: g6_ref(:,2)
                                        * Referenced by: '<S28>/g6_ref'
                                        */
  real_T Memory2_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S28>/Memory2'
                                        */
  real_T c_eob1_Threshold;             /* Expression: c_eob
                                        * Referenced by: '<S28>/c_eob  1'
                                        */
  real_T Memory1_X0_iy;                /* Expression: 0
                                        * Referenced by: '<S28>/Memory1'
                                        */
  real_T c_eob_Threshold_h;            /* Expression: c_eob
                                        * Referenced by: '<S28>/c_eob  '
                                        */
  real_T c_eob_Threshold_jz;           /* Expression: c_eob
                                        * Referenced by: '<S28>/c_eob'
                                        */
  real_T e2_Gain_h;                    /* Expression: 1e-2
                                        * Referenced by: '<S8>/1e-2'
                                        */
  real_T e6_Gain_d;                    /* Expression: 1e6
                                        * Referenced by: '<S9>/1e6'
                                        */
  real_T Constant_Value_o;             /* Expression: const
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: const
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T u9_Threshold_k;               /* Expression: 0.99
                                        * Referenced by: '<S10>/0.99'
                                        */
  real_T e3_Gain_m;                    /* Expression: 1e3
                                        * Referenced by: '<S33>/1e3'
                                        */
  real_T Imax_Value[11];               /* Expression: Imax
                                        * Referenced by: '<S2>/Imax'
                                        */
  real_T ntur_Gain[11];                /* Expression: ntur(1:n_mc)
                                        * Referenced by: '<S33>/ntur'
                                        */
  real_T c_cur_max_Gain;               /* Expression: c_cur_max
                                        * Referenced by: '<S33>/c_cur_max'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S33>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S33>/Saturation'
                                        */
  real_T Constant_Value_m;             /* Expression: const
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Memory1_X0_d;                 /* Expression: 0
                                        * Referenced by: '<S34>/Memory1'
                                        */
  real_T Constant_Value_e4;            /* Expression: const
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T Constant_Value_hc;            /* Expression: const
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T Memory_X0_a;                  /* Expression: 0
                                        * Referenced by: '<S36>/Memory'
                                        */
  real_T Constant_Value_g;             /* Expression: const
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T Constant_Value_eb;            /* Expression: const
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T Constant_Value_bi;            /* Expression: const
                                        * Referenced by: '<S51>/Constant'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S44>/Memory3'
                                        */
  real_T Constant_Value_a;             /* Expression: const
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T Constant_Value_od;            /* Expression: const
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T u999_Threshold;               /* Expression: 0.9999
                                        * Referenced by: '<S44>/0.9999'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1/ref_ramp
                                        * Referenced by: '<S44>/Gain1'
                                        */
  real_T _Value;                       /* Expression: 1
                                        * Referenced by: '<S44>/1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S44>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S44>/Saturation1'
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
  real_T u9_Threshold_a;               /* Expression: 0.99
                                        * Referenced by: '<S36>/0.99'
                                        */
  real_T Memory1_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S42>/Memory1'
                                        */
  real_T Constant_Value_i;             /* Expression: const
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: const
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T u999_Threshold_a;             /* Expression: 0.9999
                                        * Referenced by: '<S42>/0.9999'
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
  real_T Memory1_X0_kl;                /* Expression: 0
                                        * Referenced by: '<S40>/Memory1'
                                        */
  real_T c_eob_Threshold_n3;           /* Expression: c_eob
                                        * Referenced by: '<S40>/c_eob'
                                        */
  real_T u99_Threshold;                /* Expression: 0.999
                                        * Referenced by: '<S34>/0.999'
                                        */
  real_T Memory1_X0_e1;                /* Expression: 0
                                        * Referenced by: '<S41>/Memory1'
                                        */
  real_T u999_Threshold_g;             /* Expression: 0.9999
                                        * Referenced by: '<S41>/0.9999'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: -1/ref_ramp
                                        * Referenced by: '<S41>/Gain1'
                                        */
  real_T _Value_a;                     /* Expression: 1
                                        * Referenced by: '<S41>/1'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: 1
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: 0
                                        * Referenced by: '<S41>/Saturation'
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
  real_T _Value_o;                     /* Expression: 1
                                        * Referenced by: '<S41>/2'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S41>/Gain2'
                                        */
  real_T Memory2_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory2'
                                        */
  real_T tcont2_Threshold;             /* Expression: tcont2
                                        * Referenced by: '<S35>/tcont2 '
                                        */
  real_T Limcontr_A[914];              /* Computed Parameter: Limcontr_A
                                        * Referenced by: '<S35>/Lim. contr.'
                                        */
  real_T Limcontr_B[364];              /* Computed Parameter: Limcontr_B
                                        * Referenced by: '<S35>/Lim. contr.'
                                        */
  real_T Limcontr_C[517];              /* Computed Parameter: Limcontr_C
                                        * Referenced by: '<S35>/Lim. contr.'
                                        */
  real_T Limcontr_D[187];              /* Computed Parameter: Limcontr_D
                                        * Referenced by: '<S35>/Lim. contr.'
                                        */
  real_T Limcontr_X0;                  /* Expression: 0
                                        * Referenced by: '<S35>/Lim. contr.'
                                        */
  real_T Currcontr_A[121];             /* Computed Parameter: Currcontr_A
                                        * Referenced by: '<S35>/Curr. contr.'
                                        */
  real_T Currcontr_B[121];             /* Computed Parameter: Currcontr_B
                                        * Referenced by: '<S35>/Curr. contr.'
                                        */
  real_T Currcontr_C[121];             /* Computed Parameter: Currcontr_C
                                        * Referenced by: '<S35>/Curr. contr.'
                                        */
  real_T Currcontr_X0;                 /* Expression: 0
                                        * Referenced by: '<S35>/Curr. contr.'
                                        */
  real_T IpIp_div_Threshold;           /* Expression: Ip_div
                                        * Referenced by: '<S2>/Ip>Ip_div '
                                        */
  real_T volt1_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S39>/volt1'
                                        */
  real_T volt1_YData[19];              /* Expression: volt(:,2)
                                        * Referenced by: '<S39>/volt1'
                                        */
  real_T volt2_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S39>/volt2'
                                        */
  real_T volt2_YData[19];              /* Expression: volt(:,3)
                                        * Referenced by: '<S39>/volt2'
                                        */
  real_T volt3_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S39>/volt3'
                                        */
  real_T volt3_YData[19];              /* Expression: volt(:,4)
                                        * Referenced by: '<S39>/volt3'
                                        */
  real_T volt4_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S39>/volt4'
                                        */
  real_T volt4_YData[19];              /* Expression: volt(:,5)
                                        * Referenced by: '<S39>/volt4'
                                        */
  real_T volt5_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S39>/volt5'
                                        */
  real_T volt5_YData[19];              /* Expression: volt(:,6)
                                        * Referenced by: '<S39>/volt5'
                                        */
  real_T volt6_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S39>/volt6'
                                        */
  real_T volt6_YData[19];              /* Expression: volt(:,7)
                                        * Referenced by: '<S39>/volt6'
                                        */
  real_T volt7_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S39>/volt7'
                                        */
  real_T volt7_YData[19];              /* Expression: volt(:,8)
                                        * Referenced by: '<S39>/volt7'
                                        */
  real_T volt8_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S39>/volt8'
                                        */
  real_T volt8_YData[19];              /* Expression: volt(:,9)
                                        * Referenced by: '<S39>/volt8'
                                        */
  real_T volt9_XData[19];              /* Expression: volt(:,1)
                                        * Referenced by: '<S39>/volt9'
                                        */
  real_T volt9_YData[19];              /* Expression: volt(:,10)
                                        * Referenced by: '<S39>/volt9'
                                        */
  real_T volt10_XData[19];             /* Expression: volt(:,1)
                                        * Referenced by: '<S39>/volt10'
                                        */
  real_T volt10_YData[19];             /* Expression: volt(:,11)
                                        * Referenced by: '<S39>/volt10'
                                        */
  real_T volt11_XData[19];             /* Expression: volt(:,1)
                                        * Referenced by: '<S39>/volt11'
                                        */
  real_T volt11_YData[19];             /* Expression: volt(:,12)
                                        * Referenced by: '<S39>/volt11'
                                        */
  real_T Saturation1_UpperSat_i;       /* Expression: 1
                                        * Referenced by: '<S33>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_g;       /* Expression: -1
                                        * Referenced by: '<S33>/Saturation1'
                                        */
  real_T ntur_Gain_c[11];              /* Expression: 1./ntur(1:n_mc)*1e6
                                        * Referenced by: '<S35>/1//ntur'
                                        */
  real_T Tfmc_Value;                   /* Expression: Tfmc
                                        * Referenced by: '<S3>/Tfmc'
                                        */
  real_T Tfmc_Gain;                    /* Expression: Tfmc
                                        * Referenced by: '<S3>/Tfmc '
                                        */
  real_T Icoil1_ref_XData[78];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S12>/Icoil1_ref'
                                        */
  real_T Icoil1_ref_YData[78];         /* Expression: scr_PF(:,2)
                                        * Referenced by: '<S12>/Icoil1_ref'
                                        */
  real_T Icoil10_ref_XData[78];        /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S13>/Icoil10_ref'
                                        */
  real_T Icoil10_ref_YData[78];        /* Expression: scr_PF(:,11)
                                        * Referenced by: '<S13>/Icoil10_ref'
                                        */
  real_T Icoil11_ref_XData[78];        /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S14>/Icoil11_ref'
                                        */
  real_T Icoil11_ref_YData[78];        /* Expression: scr_PF(:,12)
                                        * Referenced by: '<S14>/Icoil11_ref'
                                        */
  real_T Icoil2_ref_XData[78];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S15>/Icoil2_ref'
                                        */
  real_T Icoil2_ref_YData[78];         /* Expression: scr_PF(:,3)
                                        * Referenced by: '<S15>/Icoil2_ref'
                                        */
  real_T Icoil3_ref_XData[78];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S16>/Icoil3_ref'
                                        */
  real_T Icoil3_ref_YData[78];         /* Expression: scr_PF(:,4)
                                        * Referenced by: '<S16>/Icoil3_ref'
                                        */
  real_T Icoil4_ref_XData[78];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S17>/Icoil4_ref'
                                        */
  real_T Icoil4_ref_YData[78];         /* Expression: scr_PF(:,5)
                                        * Referenced by: '<S17>/Icoil4_ref'
                                        */
  real_T Icoil5_ref_XData[78];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S18>/Icoil5_ref'
                                        */
  real_T Icoil5_ref_YData[78];         /* Expression: scr_PF(:,6)
                                        * Referenced by: '<S18>/Icoil5_ref'
                                        */
  real_T Icoil6_ref_XData[78];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S19>/Icoil6_ref'
                                        */
  real_T Icoil6_ref_YData[78];         /* Expression: scr_PF(:,7)
                                        * Referenced by: '<S19>/Icoil6_ref'
                                        */
  real_T Icoil1_ref_XData_j[78];       /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S20>/Icoil1_ref'
                                        */
  real_T Icoil1_ref_YData_d[78];       /* Expression: scr_PF(:,8)
                                        * Referenced by: '<S20>/Icoil1_ref'
                                        */
  real_T Icoil8_ref_XData[78];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S21>/Icoil8_ref'
                                        */
  real_T Icoil8_ref_YData[78];         /* Expression: scr_PF(:,9)
                                        * Referenced by: '<S21>/Icoil8_ref'
                                        */
  real_T Icoil9_ref_XData[78];         /* Expression: scr_PF(:,1)
                                        * Referenced by: '<S22>/Icoil9_ref'
                                        */
  real_T Icoil9_ref_YData[78];         /* Expression: scr_PF(:,10)
                                        * Referenced by: '<S22>/Icoil9_ref'
                                        */
  real_T Ipl_ref_XData[78];            /* Expression: scr_data(:,1)
                                        * Referenced by: '<S7>/Ipl_ref'
                                        */
  real_T Ipl_ref_YData[78];            /* Expression: scr_data(:,2)
                                        * Referenced by: '<S7>/Ipl_ref'
                                        */
  real_T g1_ref_term_XData[3];         /* Expression: g1_ref_term(:,1)
                                        * Referenced by: '<S23>/g1_ref_term'
                                        */
  real_T g1_ref_term_YData[3];         /* Expression: g1_ref_term(:,2)
                                        * Referenced by: '<S23>/g1_ref_term'
                                        */
  real_T g1_ref_XData[6];              /* Expression: g1_ref(:,1)
                                        * Referenced by: '<S23>/g1_ref'
                                        */
  real_T g1_ref_YData[6];              /* Expression: g1_ref(:,2)
                                        * Referenced by: '<S23>/g1_ref'
                                        */
  real_T g2_ref_term_XData[3];         /* Expression: g2_ref_term(:,1)
                                        * Referenced by: '<S24>/g2_ref_term'
                                        */
  real_T g2_ref_term_YData[3];         /* Expression: g2_ref_term(:,2)
                                        * Referenced by: '<S24>/g2_ref_term'
                                        */
  real_T g2_ref_XData[6];              /* Expression: g2_ref(:,1)
                                        * Referenced by: '<S24>/g2_ref'
                                        */
  real_T g2_ref_YData[6];              /* Expression: g2_ref(:,2)
                                        * Referenced by: '<S24>/g2_ref'
                                        */
  real_T g3_ref_term_XData[5];         /* Expression: g3_ref_term(:,1)
                                        * Referenced by: '<S25>/g3_ref_term'
                                        */
  real_T g3_ref_term_YData[5];         /* Expression: g3_ref_term(:,2)
                                        * Referenced by: '<S25>/g3_ref_term'
                                        */
  real_T g3_ref_XData[10];             /* Expression: g3_ref(:,1)
                                        * Referenced by: '<S25>/g3_ref'
                                        */
  real_T g3_ref_YData[10];             /* Expression: g3_ref(:,2)
                                        * Referenced by: '<S25>/g3_ref'
                                        */
  real_T g4_ref_term_XData[6];         /* Expression: g4_ref_term(:,1)
                                        * Referenced by: '<S26>/g4_ref_term'
                                        */
  real_T g4_ref_term_YData[6];         /* Expression: g4_ref_term(:,2)
                                        * Referenced by: '<S26>/g4_ref_term'
                                        */
  real_T g4_ref_XData[7];              /* Expression: g4_ref(:,1)
                                        * Referenced by: '<S26>/g4_ref'
                                        */
  real_T g4_ref_YData[7];              /* Expression: g4_ref(:,2)
                                        * Referenced by: '<S26>/g4_ref'
                                        */
  real_T g5_ref_term_XData[5];         /* Expression: g5_ref_term(:,1)
                                        * Referenced by: '<S27>/g5_ref_term'
                                        */
  real_T g5_ref_term_YData[5];         /* Expression: g5_ref_term(:,2)
                                        * Referenced by: '<S27>/g5_ref_term'
                                        */
  real_T g5_ref_XData[7];              /* Expression: g5_ref(:,1)
                                        * Referenced by: '<S27>/g5_ref'
                                        */
  real_T g5_ref_YData[7];              /* Expression: g5_ref(:,2)
                                        * Referenced by: '<S27>/g5_ref'
                                        */
  real_T g6_ref_term_XData[6];         /* Expression: g6_ref_term(:,1)
                                        * Referenced by: '<S28>/g6_ref_term'
                                        */
  real_T g6_ref_term_YData[6];         /* Expression: g6_ref_term(:,2)
                                        * Referenced by: '<S28>/g6_ref_term'
                                        */
  real_T elong_ref_XData[7];           /* Expression: elong_ref(:,1)
                                        * Referenced by: '<S1>/elong_ref'
                                        */
  real_T elong_ref_YData[7];           /* Expression: elong_ref(:,2)
                                        * Referenced by: '<S1>/elong_ref'
                                        */
  real_T k_gaplim_Gain[4];             /* Expression: k_gaplim
                                        * Referenced by: '<S1>/k_gaplim'
                                        */
  real_T zeros21_Value[2];             /* Expression: zeros(2,1)
                                        * Referenced by: '<S2>/zeros(2,1)'
                                        */
  real_T ntur_Gain_p[11];              /* Expression: 1./ntur(1:n_mc)
                                        * Referenced by: '<S35>/1//ntur '
                                        */
  real_T gain_cont2_XData[4];          /* Expression: tgain_cont2
                                        * Referenced by: '<S35>/gain_cont2'
                                        */
  real_T gain_cont2_YData[4];          /* Expression: gain_cont2
                                        * Referenced by: '<S35>/gain_cont2'
                                        */
  real_T tcont2_Threshold_e;           /* Expression: tcont2
                                        * Referenced by: '<S35>/tcont2'
                                        */
  real_T y0_Value;                     /* Expression: y0
                                        * Referenced by: '<S40>/y0'
                                        */
  real_T uy0_Value;                    /* Expression: (1-y0)/(c2_y0-c1_y0)
                                        * Referenced by: '<S40>/(1-y0)//...'
                                        */
  real_T c1_y0_Value;                  /* Expression: c1_y0
                                        * Referenced by: '<S40>/c1_y0'
                                        */
  real_T uy0_UpperSat;                 /* Expression: 1
                                        * Referenced by: '<S40>/[1 y0]'
                                        */
  real_T uy0_LowerSat;                 /* Expression: y0
                                        * Referenced by: '<S40>/[1 y0]'
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
  real_T _Value_g;                     /* Expression: 1
                                        * Referenced by: '<S42>/1 '
                                        */
  real_T _Value_m;                     /* Expression: 1
                                        * Referenced by: '<S42>/1'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: -1/ref_ramp
                                        * Referenced by: '<S42>/Gain1'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 1
                                        * Referenced by: '<S42>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S42>/Saturation'
                                        */
  real_T c_eob_Threshold_cl;           /* Expression: c_eob
                                        * Referenced by: '<S2>/c_eob'
                                        */
  real_T zeros201_Value[20];           /* Expression: zeros(20,1)
                                        * Referenced by: '<S35>/zeros(20,1)'
                                        */
  real_T _Value_i;                     /* Expression: 1
                                        * Referenced by: '<S44>/1 '
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
  real_T c_eob_Threshold_cs;           /* Expression: c_eob
                                        * Referenced by: '<S2>/c_eob '
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
  real_T Ipl_ref_XData_o[78];          /* Expression: scr_data(:,1)
                                        * Referenced by: '<S40>/Ipl_ref'
                                        */
  real_T Ipl_ref_YData_p[78];          /* Expression: scr_data(:,2)
                                        * Referenced by: '<S40>/Ipl_ref'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_t15_2 {
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
 * '<S3>'   : t15_2/Pow. Supply MC
 * '<S4>'   : t15_2/Pow. Supply VS
 * '<S5>'   : t15_2/Subsystem
 * '<S6>'   : t15_2/Control inputs 1/Icoils ref
 * '<S7>'   : t15_2/Control inputs 1/Ipl ref
 * '<S8>'   : t15_2/Control inputs 1/Subsystem
 * '<S9>'   : t15_2/Control inputs 1/Subsystem1
 * '<S10>'  : t15_2/Control inputs 1/Subsystem4
 * '<S11>'  : t15_2/Control inputs 1/dZ//dt
 * '<S12>'  : t15_2/Control inputs 1/Icoils ref/Icoil1 ref
 * '<S13>'  : t15_2/Control inputs 1/Icoils ref/Icoil10 ref
 * '<S14>'  : t15_2/Control inputs 1/Icoils ref/Icoil11 ref
 * '<S15>'  : t15_2/Control inputs 1/Icoils ref/Icoil2 ref
 * '<S16>'  : t15_2/Control inputs 1/Icoils ref/Icoil3 ref
 * '<S17>'  : t15_2/Control inputs 1/Icoils ref/Icoil4 ref
 * '<S18>'  : t15_2/Control inputs 1/Icoils ref/Icoil5 ref
 * '<S19>'  : t15_2/Control inputs 1/Icoils ref/Icoil6 ref
 * '<S20>'  : t15_2/Control inputs 1/Icoils ref/Icoil7 ref
 * '<S21>'  : t15_2/Control inputs 1/Icoils ref/Icoil8 ref
 * '<S22>'  : t15_2/Control inputs 1/Icoils ref/Icoil9 ref
 * '<S23>'  : t15_2/Control inputs 1/Subsystem/Subsystem
 * '<S24>'  : t15_2/Control inputs 1/Subsystem/Subsystem1
 * '<S25>'  : t15_2/Control inputs 1/Subsystem/Subsystem2
 * '<S26>'  : t15_2/Control inputs 1/Subsystem/Subsystem3
 * '<S27>'  : t15_2/Control inputs 1/Subsystem/Subsystem4
 * '<S28>'  : t15_2/Control inputs 1/Subsystem/Subsystem5
 * '<S29>'  : t15_2/Control inputs 1/Subsystem4/Compare To Constant
 * '<S30>'  : t15_2/Control inputs 1/Subsystem4/Compare To Constant1
 * '<S31>'  : t15_2/Control inputs 1/dZ//dt/Difference
 * '<S32>'  : t15_2/Control inputs 1/dZ//dt/Difference1
 * '<S33>'  : t15_2/Control2/Curr. satur.
 * '<S34>'  : t15_2/Control2/Subsystem
 * '<S35>'  : t15_2/Control2/Subsystem10
 * '<S36>'  : t15_2/Control2/Subsystem7
 * '<S37>'  : t15_2/Control2/Subsystem8
 * '<S38>'  : t15_2/Control2/Subsystem9
 * '<S39>'  : t15_2/Control2/Volt
 * '<S40>'  : t15_2/Control2/atpl2 eob1
 * '<S41>'  : t15_2/Control2/div_curr
 * '<S42>'  : t15_2/Control2/div_divrd
 * '<S43>'  : t15_2/Control2/dzdt noise
 * '<S44>'  : t15_2/Control2/lim_div_tr
 * '<S45>'  : t15_2/Control2/Curr. satur./Compare To Constant
 * '<S46>'  : t15_2/Control2/Curr. satur./Compare To Zero
 * '<S47>'  : t15_2/Control2/Subsystem/Compare To Constant
 * '<S48>'  : t15_2/Control2/Subsystem/Compare To Constant1
 * '<S49>'  : t15_2/Control2/Subsystem7/Compare To Constant
 * '<S50>'  : t15_2/Control2/Subsystem7/Compare To Constant1
 * '<S51>'  : t15_2/Control2/Subsystem7/Compare To Constant2
 * '<S52>'  : t15_2/Control2/Subsystem8/Compare To Constant
 * '<S53>'  : t15_2/Control2/Subsystem8/Compare To Constant1
 * '<S54>'  : t15_2/Control2/Subsystem8/Compare To Constant2
 * '<S55>'  : t15_2/Control2/div_curr/Compare To Constant
 * '<S56>'  : t15_2/Control2/div_curr/Compare To Constant1
 * '<S57>'  : t15_2/Control2/div_divrd/Compare To Constant
 * '<S58>'  : t15_2/Control2/div_divrd/Compare To Constant1
 * '<S59>'  : t15_2/Control2/lim_div_tr/Compare To Constant
 * '<S60>'  : t15_2/Control2/lim_div_tr/Compare To Constant1
 * '<S61>'  : t15_2/Pow. Supply MC /Difference
 */
#endif                                 /* RTW_HEADER_t15_2_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
