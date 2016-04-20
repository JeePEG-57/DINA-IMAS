#if 1

# define t15_2_initialize t15_2_initialize_
# define t15_2_output t15_2_output_
# define t15_2_terminate t15_2_terminate_

#endif
/*
 * File: t15_2.c
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
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "t15_2.h"
#include "t15_2_private.h"


int kpr =0;

/* Block signals (auto storage) */
BlockIO_t15_2 t15_2_B;

/* Block states (auto storage) */
D_Work_t15_2 t15_2_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_t15_2 t15_2_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_t15_2 t15_2_Y;

/* Real-time model */
RT_MODEL_t15_2 t15_2_M_;
RT_MODEL_t15_2 *t15_2_M = &t15_2_M_;

/* Model step function */
void t15_2_step(void)
{
  {
    real_T rateLimiterRate[11];
    real_T tmin;
    int32_T i;
    int32_T tmp;

    /* Gain: '<Root>/1e-3' incorporates:
     *  Inport: '<Root>/In1'
     */
    t15_2_Y.Time = t15_2_P.e3_Gain * t15_2_U.In1[8];

    /* UnitDelay: '<S61>/UD' */
    t15_2_B.Uk1 = t15_2_DWork.UD_DSTATE;

    /* Sum: '<S61>/Diff' */
    t15_2_B.Diff = t15_2_Y.Time - t15_2_B.Uk1;

    /* Gain: '<S3>/Gain' */
    t15_2_B.Gain = t15_2_P.Gain_Gain * t15_2_B.Diff;

    /* Saturate: '<S3>/Saturation6' incorporates:
     *  RateLimiter: '<S3>/Rate Limiter'
     */
    for (i = 0; i < 11; i++) {
      /* Memory: '<S3>/Memory' */
      t15_2_B.Memory[i] = t15_2_DWork.Memory_PreviousInput[i];

      /* Product: '<S3>/Divide' incorporates:
       *  Constant: '<S3>/SimStep'
       */
      t15_2_B.Divide[i] = t15_2_B.Memory[i] * t15_2_P.SimStep_Value /
        t15_2_B.Diff;
      rateLimiterRate[i] = t15_2_B.Divide[i] - t15_2_DWork.PrevY[i];
      if (rateLimiterRate[i] > t15_2_P.RateLimiter_RisingLim[i]) {
        t15_2_B.RateLimiter[i] = t15_2_DWork.PrevY[i] +
          t15_2_P.RateLimiter_RisingLim[i];
      } else if (rateLimiterRate[i] < t15_2_P.RateLimiter_FallingLim[i]) {
        t15_2_B.RateLimiter[i] = t15_2_DWork.PrevY[i] +
          t15_2_P.RateLimiter_FallingLim[i];
      } else {
        t15_2_B.RateLimiter[i] = t15_2_B.Divide[i];
      }

      t15_2_DWork.PrevY[i] = t15_2_B.RateLimiter[i];

      /* Product: '<S3>/Divide1' */
      t15_2_B.Divide1[i] = t15_2_B.RateLimiter[i] * t15_2_B.Gain;
      rateLimiterRate[i] = t15_2_B.Divide1[i];
      t15_2_B.Saturation6[i] = rt_SATURATE(rateLimiterRate[i],
        t15_2_P.Saturation6_LowerSat[i], t15_2_P.Saturation6_UpperSat[i]);
    }

    /* Gain: '<S1>/1e-6' incorporates:
     *  Inport: '<Root>/In1'
     */
    t15_2_B.e6 = t15_2_P.e6_Gain * t15_2_U.In1[3];

    /* RelationalOperator: '<S55>/Compare' incorporates:
     *  Constant: '<S55>/Constant'
     */
    t15_2_B.Compare = (t15_2_B.e6 < t15_2_P.Constant_Value);

    /* RelationalOperator: '<S56>/Compare' incorporates:
     *  Constant: '<S56>/Constant'
     */
    t15_2_B.Compare_e = (t15_2_Y.Time > t15_2_P.Constant_Value_f);

    /* Logic: '<S41>/Logical Operator2' */
    t15_2_B.LogicalOperator2 = (real_T)((t15_2_B.Compare != 0) &&
      (t15_2_B.Compare_e != 0));

    /* Logic: '<S41>/Logical Operator1' */
    t15_2_B.LogicalOperator1 = (real_T)!(t15_2_B.LogicalOperator2 != 0.0);

    /* UniformRandomNumber: '<S43>/Uniform Random Number' */
    t15_2_B.UniformRandomNumber = t15_2_DWork.UniformRandomNumber_NextOutput;

    /* UnitDelay: '<S31>/UD' */
    t15_2_B.Uk1_a = t15_2_DWork.UD_DSTATE_n;

    /* UnitDelay: '<S32>/UD' */
    t15_2_B.Uk1_g = t15_2_DWork.UD_DSTATE_h;

    /* Gain: '<S1>/1e-6   ' incorporates:
     *  Inport: '<Root>/In2'
     */
    for (i = 0; i < 15; i++) {
      t15_2_B.e6_l[i] = t15_2_U.In2[i + 6] * t15_2_P.e6_Gain_h;
    }

    /* Switch: '<S2>/t>t_tran2d' incorporates:
     *  Constant: '<S2>/zeros(2,1)'
     */
    if (t15_2_Y.Time > t15_2_P.tt_tran2d_Threshold) {
      /* Sum: '<S32>/Diff' */
      t15_2_B.Diff_b = t15_2_Y.Time - t15_2_B.Uk1_g;

      /* Sum: '<S31>/Diff' incorporates:
       *  Inport: '<Root>/In1'
       */
      t15_2_B.Diff_n = t15_2_U.In1[1] - t15_2_B.Uk1_a;

      /* Product: '<S11>/Divide' */
      t15_2_B.Divide_i = t15_2_B.Diff_n / t15_2_B.Diff_b;

      /* Sum: '<S43>/Sum2' */
      t15_2_B.Sum2_d = t15_2_B.UniformRandomNumber + t15_2_B.Divide_i;
      t15_2_B.tt_tran2d[0] = t15_2_B.Sum2_d;
      t15_2_B.tt_tran2d[1] = t15_2_B.e6_l[11];
    } else {
      t15_2_B.tt_tran2d[0] = t15_2_P.zeros21_Value[0];
      t15_2_B.tt_tran2d[1] = t15_2_P.zeros21_Value[1];
    }

    /* DiscreteStateSpace: '<S38>/VS. contr' */
    {
      t15_2_B.VScontr[0] = 0.0;
      t15_2_B.VScontr[1] = 0.0;
      t15_2_B.VScontr[2] = 0.0;
      t15_2_B.VScontr[3] = 0.0;
      t15_2_B.VScontr[4] = 0.0;
      t15_2_B.VScontr[5] = 0.0;

      {
        static const int_T colCidxRow6[5] = { 3, 4, 5, 6, 7 };

        const int_T *pCidx = &colCidxRow6[0];
        const real_T *pC0 = &t15_2_P.VScontr_C[0];
        const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
        real_T *y6 = &t15_2_B.VScontr[6];
        int_T numNonZero = 4;
        *y6 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y6 += (*pC0++) * xd[*pCidx++];
        }
      }

      t15_2_B.VScontr[6] += (t15_2_P.VScontr_D[0])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_D[1])*t15_2_B.tt_tran2d[1];

      {
        static const int_T colCidxRow7[5] = { 3, 4, 5, 6, 7 };

        const int_T *pCidx = &colCidxRow7[0];
        const real_T *pC5 = &t15_2_P.VScontr_C[5];
        const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
        real_T *y7 = &t15_2_B.VScontr[7];
        int_T numNonZero = 4;
        *y7 = (*pC5++) * xd[*pCidx++];
        while (numNonZero--) {
          *y7 += (*pC5++) * xd[*pCidx++];
        }
      }

      t15_2_B.VScontr[7] += (t15_2_P.VScontr_D[2])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_D[3])*t15_2_B.tt_tran2d[1];

      {
        static const int_T colCidxRow8[5] = { 3, 4, 5, 6, 7 };

        const int_T *pCidx = &colCidxRow8[0];
        const real_T *pC10 = &t15_2_P.VScontr_C[10];
        const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
        real_T *y8 = &t15_2_B.VScontr[8];
        int_T numNonZero = 4;
        *y8 = (*pC10++) * xd[*pCidx++];
        while (numNonZero--) {
          *y8 += (*pC10++) * xd[*pCidx++];
        }
      }

      t15_2_B.VScontr[8] += (t15_2_P.VScontr_D[4])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_D[5])*t15_2_B.tt_tran2d[1];

      {
        static const int_T colCidxRow9[5] = { 3, 4, 5, 6, 7 };

        const int_T *pCidx = &colCidxRow9[0];
        const real_T *pC15 = &t15_2_P.VScontr_C[15];
        const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
        real_T *y9 = &t15_2_B.VScontr[9];
        int_T numNonZero = 4;
        *y9 = (*pC15++) * xd[*pCidx++];
        while (numNonZero--) {
          *y9 += (*pC15++) * xd[*pCidx++];
        }
      }

      t15_2_B.VScontr[9] += (t15_2_P.VScontr_D[6])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_D[7])*t15_2_B.tt_tran2d[1];
      t15_2_B.VScontr[10] = 0.0;

      {
        static const int_T colCidxRow11[5] = { 0, 1, 2, 7, 8 };

        const int_T *pCidx = &colCidxRow11[0];
        const real_T *pC20 = &t15_2_P.VScontr_C[20];
        const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
        real_T *y11 = &t15_2_B.VScontr[11];
        int_T numNonZero = 4;
        *y11 = (*pC20++) * xd[*pCidx++];
        while (numNonZero--) {
          *y11 += (*pC20++) * xd[*pCidx++];
        }
      }

      t15_2_B.VScontr[11] += (t15_2_P.VScontr_D[8])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_D[9])*t15_2_B.tt_tran2d[1];
    }

    /* Memory: '<S9>/Memory2' */
    t15_2_B.Memory2 = t15_2_DWork.Memory2_PreviousInput;

    /* Sum: '<S9>/Add3' */
    t15_2_B.Add3 = t15_2_B.e6_l[2] + t15_2_B.Memory2;

    /* Memory: '<S9>/Memory1' */
    t15_2_B.Memory1 = t15_2_DWork.Memory1_PreviousInput;

    /* Switch: '<S9>/Ics1_eob' */
    if (t15_2_B.Add3 >= t15_2_P.Ics1_eob_Threshold) {
      t15_2_B.Ics1_eob = t15_2_Y.Time;
    } else {
      t15_2_B.Ics1_eob = t15_2_B.Memory1;
    }

    /* Sum: '<S9>/Add2' */
    t15_2_B.Add2 = t15_2_B.Ics1_eob - t15_2_Y.Time;

    /* Gain: '<S9>/dtpl_term_l' */
    t15_2_B.dtpl_term_l = t15_2_P.dtpl_term_l_Gain * t15_2_B.Add2;

    /* Sum: '<S9>/Add1' incorporates:
     *  Constant: '<S9>/Constant4'
     */
    t15_2_B.Add1 = t15_2_B.dtpl_term_l + t15_2_P.Constant4_Value;

    /* Saturate: '<S9>/1 0' */
    tmin = t15_2_B.Add1;
    t15_2_B.u = rt_SATURATE(tmin, t15_2_P.u_LowerSat, t15_2_P.u_UpperSat);

    /* RelationalOperator: '<S38>/Relational Operator' incorporates:
     *  Constant: '<S38>/c_eob '
     */
    t15_2_B.RelationalOperator = (real_T)(t15_2_B.u < t15_2_P.c_eob_Value);

    /* Product: '<S38>/Divide4' */
    t15_2_B.Divide4[0] = t15_2_B.RelationalOperator * t15_2_B.tt_tran2d[0];
    t15_2_B.Divide4[1] = t15_2_B.RelationalOperator * t15_2_B.tt_tran2d[1];

    /* DiscreteStateSpace: '<S38>/VS. contr hl' */
    {
      t15_2_B.VScontrhl[0] = 0.0;
      t15_2_B.VScontrhl[1] = 0.0;
      t15_2_B.VScontrhl[2] = 0.0;
      t15_2_B.VScontrhl[3] = 0.0;
      t15_2_B.VScontrhl[4] = 0.0;
      t15_2_B.VScontrhl[5] = 0.0;

      {
        static const int_T colCidxRow6[5] = { 3, 4, 5, 6, 7 };

        const int_T *pCidx = &colCidxRow6[0];
        const real_T *pC0 = &t15_2_P.VScontrhl_C[0];
        const real_T *xd = &t15_2_DWork.VScontrhl_DSTATE[0];
        real_T *y6 = &t15_2_B.VScontrhl[6];
        int_T numNonZero = 4;
        *y6 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y6 += (*pC0++) * xd[*pCidx++];
        }
      }

      t15_2_B.VScontrhl[6] += (t15_2_P.VScontrhl_D[0])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_D[1])*t15_2_B.Divide4[1];

      {
        static const int_T colCidxRow7[5] = { 3, 4, 5, 6, 7 };

        const int_T *pCidx = &colCidxRow7[0];
        const real_T *pC5 = &t15_2_P.VScontrhl_C[5];
        const real_T *xd = &t15_2_DWork.VScontrhl_DSTATE[0];
        real_T *y7 = &t15_2_B.VScontrhl[7];
        int_T numNonZero = 4;
        *y7 = (*pC5++) * xd[*pCidx++];
        while (numNonZero--) {
          *y7 += (*pC5++) * xd[*pCidx++];
        }
      }

      t15_2_B.VScontrhl[7] += (t15_2_P.VScontrhl_D[2])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_D[3])*t15_2_B.Divide4[1];

      {
        static const int_T colCidxRow8[5] = { 3, 4, 5, 6, 7 };

        const int_T *pCidx = &colCidxRow8[0];
        const real_T *pC10 = &t15_2_P.VScontrhl_C[10];
        const real_T *xd = &t15_2_DWork.VScontrhl_DSTATE[0];
        real_T *y8 = &t15_2_B.VScontrhl[8];
        int_T numNonZero = 4;
        *y8 = (*pC10++) * xd[*pCidx++];
        while (numNonZero--) {
          *y8 += (*pC10++) * xd[*pCidx++];
        }
      }

      t15_2_B.VScontrhl[8] += (t15_2_P.VScontrhl_D[4])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_D[5])*t15_2_B.Divide4[1];

      {
        static const int_T colCidxRow9[5] = { 3, 4, 5, 6, 7 };

        const int_T *pCidx = &colCidxRow9[0];
        const real_T *pC15 = &t15_2_P.VScontrhl_C[15];
        const real_T *xd = &t15_2_DWork.VScontrhl_DSTATE[0];
        real_T *y9 = &t15_2_B.VScontrhl[9];
        int_T numNonZero = 4;
        *y9 = (*pC15++) * xd[*pCidx++];
        while (numNonZero--) {
          *y9 += (*pC15++) * xd[*pCidx++];
        }
      }

      t15_2_B.VScontrhl[9] += (t15_2_P.VScontrhl_D[6])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_D[7])*t15_2_B.Divide4[1];
      t15_2_B.VScontrhl[10] = 0.0;
      t15_2_B.VScontrhl[11] = (t15_2_P.VScontrhl_C[20])*
        t15_2_DWork.VScontrhl_DSTATE[0] + (t15_2_P.VScontrhl_C[21])*
        t15_2_DWork.VScontrhl_DSTATE[1]
        + (t15_2_P.VScontrhl_C[22])*t15_2_DWork.VScontrhl_DSTATE[2]
        + (t15_2_P.VScontrhl_C[23])*t15_2_DWork.VScontrhl_DSTATE[7];
      t15_2_B.VScontrhl[11] += (t15_2_P.VScontrhl_D[8])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_D[9])*t15_2_B.Divide4[1];
    }

    /* Switch: '<S38>/c_eob' */
    for (i = 0; i < 12; i++) {
      if (t15_2_B.u > t15_2_P.c_eob_Threshold) {
        t15_2_B.c_eob[i] = t15_2_B.VScontr[i];
      } else {
        t15_2_B.c_eob[i] = t15_2_B.VScontrhl[i];
      }
    }

    /* RelationalOperator: '<S52>/Compare' incorporates:
     *  Constant: '<S52>/Constant'
     */
    t15_2_B.Compare_a = (t15_2_B.e6 < t15_2_P.Constant_Value_p);

    /* RelationalOperator: '<S53>/Compare' incorporates:
     *  Constant: '<S53>/Constant'
     */
    t15_2_B.Compare_ev = (t15_2_Y.Time > t15_2_P.Constant_Value_h);

    /* RelationalOperator: '<S54>/Compare' incorporates:
     *  Constant: '<S54>/Constant'
     */
    t15_2_B.Compare_n = (t15_2_B.e6 > t15_2_P.Constant_Value_b);

    /* Logic: '<S37>/Logical Operator1' */
    t15_2_B.LogicalOperator1_m = (real_T)((t15_2_B.Compare_a != 0) &&
      (t15_2_B.Compare_ev != 0) && (t15_2_B.Compare_n != 0));

    /* Switch: '<S37>/0.99' */
    if (t15_2_B.LogicalOperator1_m >= t15_2_P.u9_Threshold) {
      /* Gain: '<S2>/c_a_tpl1_eob//15' */
      t15_2_B.c_a_tpl1_eob15 = t15_2_P.c_a_tpl1_eob15_Gain_l * t15_2_B.e6;

      /* Saturate: '<S2>/Saturation4' */
      tmin = t15_2_B.c_a_tpl1_eob15;
      t15_2_B.Saturation4 = rt_SATURATE(tmin, t15_2_P.Saturation4_LowerSat,
        t15_2_P.Saturation4_UpperSat);
      for (i = 0; i < 12; i++) {
        /* Product: '<S2>/Divide11' */
        t15_2_B.Divide11[i] = t15_2_B.Saturation4 * t15_2_B.c_eob[i];
        t15_2_B.u9[i] = t15_2_B.Divide11[i];
      }
    } else {
      /* Switch: '<S2>/c_eob ' */
      if (t15_2_B.u > t15_2_P.c_eob_Threshold_cs) {
        /* Switch: '<S2>/Ip>Ip_div' */
        if (t15_2_B.e6 > t15_2_P.IpIp_div_Threshold_h) {
          /* Gain: '<S2>/atpl1' */
          t15_2_B.atpl1 = t15_2_P.atpl1_Gain * t15_2_B.e6;
          t15_2_B.IpIp_div_l = t15_2_B.atpl1;
        } else {
          /* Gain: '<S2>/c_a_tpl1_eob//15 ' */
          t15_2_B.c_a_tpl1_eob15_l = t15_2_P.c_a_tpl1_eob15_Gain * t15_2_B.e6;
          t15_2_B.IpIp_div_l = t15_2_B.c_a_tpl1_eob15_l;
        }

        /* Saturate: '<S2>/Saturation2' */
        tmin = t15_2_B.IpIp_div_l;
        t15_2_B.Saturation2 = rt_SATURATE(tmin, t15_2_P.Saturation2_LowerSat,
          t15_2_P.Saturation2_UpperSat);
        for (i = 0; i < 12; i++) {
          /* Product: '<S2>/Divide8' */
          t15_2_B.Divide8[i] = t15_2_B.Saturation2 * t15_2_B.c_eob[i];
          t15_2_B.c_eob_pt[i] = t15_2_B.Divide8[i];
        }
      } else {
        /* Gain: '<S2>/1//15' */
        t15_2_B.u5 = t15_2_P.u5_Gain * t15_2_B.e6;

        /* Saturate: '<S2>/Saturation3' */
        tmin = t15_2_B.u5;
        t15_2_B.Saturation3 = rt_SATURATE(tmin, t15_2_P.Saturation3_LowerSat,
          t15_2_P.Saturation3_UpperSat);
        for (i = 0; i < 12; i++) {
          /* Product: '<S2>/Divide9' */
          t15_2_B.Divide9[i] = t15_2_B.c_eob[i] * t15_2_B.Saturation3;
          t15_2_B.c_eob_pt[i] = t15_2_B.Divide9[i];
        }
      }

      memcpy((void *)(&t15_2_B.u9[0]), (void *)(&t15_2_B.c_eob_pt[0]), 12U *
             sizeof(real_T));
    }

    /* Saturate: '<S4>/Saturation VS' */
    for (i = 0; i < 12; i++) {
      /* Product: '<S2>/Divide10' */
      t15_2_B.Divide10[i] = t15_2_B.LogicalOperator1 * t15_2_B.u9[i];
      tmin = t15_2_B.Divide10[i];
      t15_2_B.SaturationVS[i] = rt_SATURATE(tmin,
        t15_2_P.SaturationVS_LowerSat[i], t15_2_P.SaturationVS_UpperSat[i]);
    }

    /* SignalConversion: '<Root>/TmpSignal ConversionAtnpf,12Inport1' */
    for (i = 0; i < 11; i++) {
      /* Sum: '<Root>/Add1' */
      t15_2_B.Add1_b[i] = t15_2_B.Saturation6[i] + t15_2_B.SaturationVS[i];
      t15_2_B.TmpSignalConversionAtnpf12Inpor[i] = t15_2_B.Add1_b[i];
    }

    t15_2_B.TmpSignalConversionAtnpf12Inpor[11] = t15_2_B.SaturationVS[11];

    /* Outport: '<Root>/Out1' */
    for (i = 0; i < 15; i++) {
      /* Gain: '<Root>/npf,12' */
      t15_2_B.npf12[i] = 0.0;
      for (tmp = 0; tmp < 12; tmp++) {
        t15_2_B.npf12[i] = t15_2_P.npf12_Gain[15 * tmp + i] *
          t15_2_B.TmpSignalConversionAtnpf12Inpor[tmp] + t15_2_B.npf12[i];
      }

      t15_2_Y.Out1[i] = t15_2_B.npf12[i];
    }

    memcpy((void *)(&t15_2_Y.Out1[15]), (void *)(&t15_2_B.Saturation6[0]), 11U *
           sizeof(real_T));
    memcpy((void *)(&t15_2_Y.Out1[26]), (void *)(&t15_2_B.SaturationVS[0]), 12U *
           sizeof(real_T));

    /* Memory: '<Root>/Memory2' */
    t15_2_B.Memory2_f = t15_2_DWork.Memory2_PreviousInput_g;

    /* Gain: '<Root>/-1' incorporates:
     *  Inport: '<Root>/In1'
     */
    t15_2_B.u_o = t15_2_P.u_Gain * t15_2_U.In1[3];

    /* Switch: '<Root>/Ip<Ip_0 ' */
    if (t15_2_B.u_o > t15_2_P.IpIp_0_Threshold) {
      t15_2_B.IpIp_0 = t15_2_B.Memory2_f;
    } else {
      t15_2_B.IpIp_0 = t15_2_Y.Time;
    }

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/dt_end_sim'
     */
    t15_2_B.Sum2 = t15_2_B.IpIp_0 + t15_2_P.dt_end_sim_Value;

    /* RelationalOperator: '<Root>/Relational Operator' */
    t15_2_B.RelationalOperator_a = (t15_2_Y.Time >= t15_2_B.Sum2);

    /* Stop: '<Root>/Stop Simulation' */
    if (t15_2_B.RelationalOperator_a) {
      rtmSetStopRequested(t15_2_M, 1);
    }

    /* RelationalOperator: '<Root>/Relational Operator1' incorporates:
     *  Constant: '<Root>/Time_stop'
     */
    t15_2_B.RelationalOperator1 = (t15_2_Y.Time >= t15_2_P.Time_stop_Value);

    /* Stop: '<Root>/Stop Simulation1' */
    if (t15_2_B.RelationalOperator1) {
      rtmSetStopRequested(t15_2_M, 1);
    }

    /* Memory: '<S7>/Memory1' */
    t15_2_B.Memory1_h = t15_2_DWork.Memory1_PreviousInput_n;

    /* Switch: '<S7>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_c) {
      /* Lookup: '<S7>/Ipl_ref' */
      t15_2_B.Ipl_ref_g = rt_Lookup((const real_T *)(&t15_2_P.Ipl_ref_XData[0]),
        78, t15_2_Y.Time, (const real_T *)(&t15_2_P.Ipl_ref_YData[0]));
      t15_2_B.c_eob_f = t15_2_B.Ipl_ref_g;
    } else {
      t15_2_B.c_eob_f = t15_2_B.Memory1_h;
    }

    /* Product: '<S7>/Divide6' */
    t15_2_B.Divide6 = t15_2_B.c_eob_f * t15_2_B.u;

    /* Sum: '<S1>/Add1' */
    t15_2_B.Add1_o = t15_2_B.e6 - t15_2_B.Divide6;

    /* Memory: '<S15>/Memory2' */
    t15_2_B.Memory2_l = t15_2_DWork.Memory2_PreviousInput_b;

    /* Switch: '<S15>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_m) {
      /* Lookup: '<S15>/Icoil2_ref' */
      t15_2_B.Icoil2_ref = rt_Lookup((const real_T *)(&t15_2_P.Icoil2_ref_XData
        [0]), 78, t15_2_Y.Time, (const real_T *)(&t15_2_P.Icoil2_ref_YData[0]));
      t15_2_B.c_eob_c = t15_2_B.Icoil2_ref;
    } else {
      t15_2_B.c_eob_c = t15_2_B.Memory2_l;
    }

    /* Product: '<S15>/Divide1' */
    t15_2_B.Divide1_l = t15_2_B.c_eob_c * t15_2_B.u;

    /* Sum: '<S6>/Add1' */
    t15_2_B.Add1_oq = t15_2_B.e6_l[1] - t15_2_B.Divide1_l;

    /* Memory: '<S13>/Memory2' */
    t15_2_B.Memory2_k = t15_2_DWork.Memory2_PreviousInput_a;

    /* Switch: '<S13>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_o) {
      /* Lookup: '<S13>/Icoil10_ref' */
      t15_2_B.Icoil10_ref = rt_Lookup((const real_T *)
        (&t15_2_P.Icoil10_ref_XData[0]), 78, t15_2_Y.Time, (const real_T *)
        (&t15_2_P.Icoil10_ref_YData[0]));
      t15_2_B.c_eob_p = t15_2_B.Icoil10_ref;
    } else {
      t15_2_B.c_eob_p = t15_2_B.Memory2_k;
    }

    /* Product: '<S13>/Divide1' */
    t15_2_B.Divide1_h = t15_2_B.c_eob_p * t15_2_B.u;

    /* Sum: '<S6>/Add10' */
    t15_2_B.Add10 = t15_2_B.e6_l[9] - t15_2_B.Divide1_h;

    /* Memory: '<S14>/Memory2' */
    t15_2_B.Memory2_e = t15_2_DWork.Memory2_PreviousInput_n;

    /* Switch: '<S14>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_j) {
      /* Lookup: '<S14>/Icoil11_ref' */
      t15_2_B.Icoil11_ref = rt_Lookup((const real_T *)
        (&t15_2_P.Icoil11_ref_XData[0]), 78, t15_2_Y.Time, (const real_T *)
        (&t15_2_P.Icoil11_ref_YData[0]));
      t15_2_B.c_eob_o = t15_2_B.Icoil11_ref;
    } else {
      t15_2_B.c_eob_o = t15_2_B.Memory2_e;
    }

    /* Product: '<S14>/Divide1' */
    t15_2_B.Divide1_i = t15_2_B.c_eob_o * t15_2_B.u;

    /* Sum: '<S6>/Add11' */
    t15_2_B.Add11 = t15_2_B.e6_l[10] - t15_2_B.Divide1_i;

    /* Memory: '<S16>/Memory2' */
    t15_2_B.Memory2_l4 = t15_2_DWork.Memory2_PreviousInput_bt;

    /* Switch: '<S16>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_a) {
      /* Lookup: '<S16>/Icoil3_ref' */
      t15_2_B.Icoil3_ref = rt_Lookup((const real_T *)(&t15_2_P.Icoil3_ref_XData
        [0]), 78, t15_2_Y.Time, (const real_T *)(&t15_2_P.Icoil3_ref_YData[0]));
      t15_2_B.c_eob_k = t15_2_B.Icoil3_ref;
    } else {
      t15_2_B.c_eob_k = t15_2_B.Memory2_l4;
    }

    /* Product: '<S16>/Divide1' */
    t15_2_B.Divide1_e = t15_2_B.c_eob_k * t15_2_B.u;

    /* Sum: '<S6>/Add2' */
    t15_2_B.Add2_d = t15_2_B.e6_l[2] - t15_2_B.Divide1_e;

    /* Memory: '<S12>/Memory2' */
    t15_2_B.Memory2_o = t15_2_DWork.Memory2_PreviousInput_c;

    /* Switch: '<S12>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_n) {
      /* Lookup: '<S12>/Icoil1_ref' */
      t15_2_B.Icoil1_ref_k = rt_Lookup((const real_T *)
        (&t15_2_P.Icoil1_ref_XData[0]), 78, t15_2_Y.Time, (const real_T *)
        (&t15_2_P.Icoil1_ref_YData[0]));
      t15_2_B.c_eob_kq = t15_2_B.Icoil1_ref_k;
    } else {
      t15_2_B.c_eob_kq = t15_2_B.Memory2_o;
    }

    /* Product: '<S12>/Divide1' */
    t15_2_B.Divide1_g = t15_2_B.c_eob_kq * t15_2_B.u;

    /* Sum: '<S6>/Add3' */
    t15_2_B.Add3_a = t15_2_B.e6_l[0] - t15_2_B.Divide1_g;

    /* Memory: '<S17>/Memory2' */
    t15_2_B.Memory2_h = t15_2_DWork.Memory2_PreviousInput_i;

    /* Switch: '<S17>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_jj) {
      /* Lookup: '<S17>/Icoil4_ref' */
      t15_2_B.Icoil4_ref = rt_Lookup((const real_T *)(&t15_2_P.Icoil4_ref_XData
        [0]), 78, t15_2_Y.Time, (const real_T *)(&t15_2_P.Icoil4_ref_YData[0]));
      t15_2_B.c_eob_p1 = t15_2_B.Icoil4_ref;
    } else {
      t15_2_B.c_eob_p1 = t15_2_B.Memory2_h;
    }

    /* Product: '<S17>/Divide1' */
    t15_2_B.Divide1_la = t15_2_B.c_eob_p1 * t15_2_B.u;

    /* Sum: '<S6>/Add4' */
    t15_2_B.Add4 = t15_2_B.e6_l[3] - t15_2_B.Divide1_la;

    /* Memory: '<S18>/Memory2' */
    t15_2_B.Memory2_a = t15_2_DWork.Memory2_PreviousInput_bh;

    /* Switch: '<S18>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_b) {
      /* Lookup: '<S18>/Icoil5_ref' */
      t15_2_B.Icoil5_ref = rt_Lookup((const real_T *)(&t15_2_P.Icoil5_ref_XData
        [0]), 78, t15_2_Y.Time, (const real_T *)(&t15_2_P.Icoil5_ref_YData[0]));
      t15_2_B.c_eob_l = t15_2_B.Icoil5_ref;
    } else {
      t15_2_B.c_eob_l = t15_2_B.Memory2_a;
    }

    /* Product: '<S18>/Divide1' */
    t15_2_B.Divide1_hp = t15_2_B.c_eob_l * t15_2_B.u;

    /* Sum: '<S6>/Add5' */
    t15_2_B.Add5 = t15_2_B.e6_l[4] - t15_2_B.Divide1_hp;

    /* Memory: '<S19>/Memory2' */
    t15_2_B.Memory2_m = t15_2_DWork.Memory2_PreviousInput_m;

    /* Switch: '<S19>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_g) {
      /* Lookup: '<S19>/Icoil6_ref' */
      t15_2_B.Icoil6_ref = rt_Lookup((const real_T *)(&t15_2_P.Icoil6_ref_XData
        [0]), 78, t15_2_Y.Time, (const real_T *)(&t15_2_P.Icoil6_ref_YData[0]));
      t15_2_B.c_eob_b = t15_2_B.Icoil6_ref;
    } else {
      t15_2_B.c_eob_b = t15_2_B.Memory2_m;
    }

    /* Product: '<S19>/Divide1' */
    t15_2_B.Divide1_f = t15_2_B.c_eob_b * t15_2_B.u;

    /* Sum: '<S6>/Add6' */
    t15_2_B.Add6 = t15_2_B.e6_l[5] - t15_2_B.Divide1_f;

    /* Memory: '<S20>/Memory2' */
    t15_2_B.Memory2_o2 = t15_2_DWork.Memory2_PreviousInput_ns;

    /* Switch: '<S20>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_l) {
      /* Lookup: '<S20>/Icoil1_ref' */
      t15_2_B.Icoil1_ref = rt_Lookup((const real_T *)
        (&t15_2_P.Icoil1_ref_XData_j[0]), 78, t15_2_Y.Time, (const real_T *)
        (&t15_2_P.Icoil1_ref_YData_d[0]));
      t15_2_B.c_eob_g = t15_2_B.Icoil1_ref;
    } else {
      t15_2_B.c_eob_g = t15_2_B.Memory2_o2;
    }

    /* Product: '<S20>/Divide1' */
    t15_2_B.Divide1_a = t15_2_B.c_eob_g * t15_2_B.u;

    /* Sum: '<S6>/Add7' */
    t15_2_B.Add7 = t15_2_B.e6_l[6] - t15_2_B.Divide1_a;

    /* Memory: '<S21>/Memory2' */
    t15_2_B.Memory2_b = t15_2_DWork.Memory2_PreviousInput_gb;

    /* Switch: '<S21>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_gv) {
      /* Lookup: '<S21>/Icoil8_ref' */
      t15_2_B.Icoil8_ref = rt_Lookup((const real_T *)(&t15_2_P.Icoil8_ref_XData
        [0]), 78, t15_2_Y.Time, (const real_T *)(&t15_2_P.Icoil8_ref_YData[0]));
      t15_2_B.c_eob_d = t15_2_B.Icoil8_ref;
    } else {
      t15_2_B.c_eob_d = t15_2_B.Memory2_b;
    }

    /* Product: '<S21>/Divide1' */
    t15_2_B.Divide1_fa = t15_2_B.c_eob_d * t15_2_B.u;

    /* Sum: '<S6>/Add8' */
    t15_2_B.Add8 = t15_2_B.e6_l[7] - t15_2_B.Divide1_fa;

    /* Memory: '<S22>/Memory2' */
    t15_2_B.Memory2_o5 = t15_2_DWork.Memory2_PreviousInput_gn;

    /* Switch: '<S22>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_l4) {
      /* Lookup: '<S22>/Icoil9_ref' */
      t15_2_B.Icoil9_ref = rt_Lookup((const real_T *)(&t15_2_P.Icoil9_ref_XData
        [0]), 78, t15_2_Y.Time, (const real_T *)(&t15_2_P.Icoil9_ref_YData[0]));
      t15_2_B.c_eob_fg = t15_2_B.Icoil9_ref;
    } else {
      t15_2_B.c_eob_fg = t15_2_B.Memory2_o5;
    }

    /* Product: '<S22>/Divide1' */
    t15_2_B.Divide1_ap = t15_2_B.c_eob_fg * t15_2_B.u;

    /* Sum: '<S6>/Add9' */
    t15_2_B.Add9 = t15_2_B.e6_l[8] - t15_2_B.Divide1_ap;

    /* Lookup: '<S6>/Lookup Table1' */
    t15_2_B.LookupTable1 = rt_Lookup((const real_T *)
      (&t15_2_P.LookupTable1_XData[0]), 4, t15_2_Y.Time, (const real_T *)
      (&t15_2_P.LookupTable1_YData[0]));

    /* Product: '<S6>/Divide6' */
    t15_2_B.Divide6_l = t15_2_B.Add5 * t15_2_B.LookupTable1;

    /* Sum: '<S5>/Sum2' incorporates:
     *  Inport: '<Root>/In1'
     */
    t15_2_B.Sum2_f = t15_2_U.In1[5] - t15_2_U.In1[7];

    /* Switch: '<S5>/>=0' incorporates:
     *  Inport: '<Root>/In1'
     */
    if (t15_2_B.Sum2_f >= t15_2_P.u_Threshold) {
      t15_2_B.u_a = t15_2_U.In1[7];
    } else {
      t15_2_B.u_a = t15_2_U.In1[5];
    }

    /* Gain: '<S8>/1e2' incorporates:
     *  Inport: '<Root>/In1'
     *  Inport: '<Root>/In2'
     */
    t15_2_B.e2[0] = t15_2_P.e2_Gain * t15_2_U.In2[0];
    t15_2_B.e2[1] = t15_2_P.e2_Gain * t15_2_U.In2[1];
    t15_2_B.e2[2] = t15_2_P.e2_Gain * t15_2_U.In1[6];
    t15_2_B.e2[3] = t15_2_P.e2_Gain * t15_2_U.In2[3];
    t15_2_B.e2[4] = t15_2_P.e2_Gain * t15_2_U.In2[4];
    t15_2_B.e2[5] = t15_2_P.e2_Gain * t15_2_B.u_a;

    /* Memory: '<S23>/Memory1' */
    t15_2_B.Memory1_d = t15_2_DWork.Memory1_PreviousInput_e;

    /* Switch: '<S23>/c_eob  ' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_d) {
      t15_2_B.c_eob_gq = t15_2_Y.Time;
    } else {
      t15_2_B.c_eob_gq = t15_2_B.Memory1_d;
    }

    /* Switch: '<S23>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_k) {
      /* Lookup: '<S23>/g1_ref' */
      t15_2_B.g1_ref = rt_Lookup((const real_T *)(&t15_2_P.g1_ref_XData[0]), 6,
        t15_2_Y.Time, (const real_T *)(&t15_2_P.g1_ref_YData[0]));
      t15_2_B.c_eob_d1 = t15_2_B.g1_ref;
    } else {
      /* Sum: '<S23>/Add2' */
      t15_2_B.Add2_a = t15_2_Y.Time - t15_2_B.c_eob_gq;

      /* Lookup: '<S23>/g1_ref_term' */
      t15_2_B.g1_ref_term = rt_Lookup((const real_T *)
        (&t15_2_P.g1_ref_term_XData[0]), 3, t15_2_B.Add2_a, (const real_T *)
        (&t15_2_P.g1_ref_term_YData[0]));
      t15_2_B.c_eob_d1 = t15_2_B.g1_ref_term;
    }

    /* Sum: '<S8>/Add2' */
    t15_2_B.Add2_i = t15_2_B.e2[0] - t15_2_B.c_eob_d1;

    /* Lookup: '<S8>/Lookup Table1' */
    t15_2_B.LookupTable1_b = rt_Lookup((const real_T *)
      (&t15_2_P.LookupTable1_XData_o[0]), 4, t15_2_Y.Time, (const real_T *)
      (&t15_2_P.LookupTable1_YData_k[0]));

    /* Product: '<S8>/Divide6' */
    t15_2_B.Divide6_i = t15_2_B.Add2_i * t15_2_B.LookupTable1_b;

    /* Memory: '<S24>/Memory1' */
    t15_2_B.Memory1_e = t15_2_DWork.Memory1_PreviousInput_h;

    /* Switch: '<S24>/c_eob ' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_ly) {
      t15_2_B.c_eob_o2 = t15_2_Y.Time;
    } else {
      t15_2_B.c_eob_o2 = t15_2_B.Memory1_e;
    }

    /* Switch: '<S24>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_bf) {
      /* Lookup: '<S24>/g2_ref' */
      t15_2_B.g2_ref = rt_Lookup((const real_T *)(&t15_2_P.g2_ref_XData[0]), 6,
        t15_2_Y.Time, (const real_T *)(&t15_2_P.g2_ref_YData[0]));
      t15_2_B.c_eob_e = t15_2_B.g2_ref;
    } else {
      /* Sum: '<S24>/Add2' */
      t15_2_B.Add2_e = t15_2_Y.Time - t15_2_B.c_eob_o2;

      /* Lookup: '<S24>/g2_ref_term' */
      t15_2_B.g2_ref_term = rt_Lookup((const real_T *)
        (&t15_2_P.g2_ref_term_XData[0]), 3, t15_2_B.Add2_e, (const real_T *)
        (&t15_2_P.g2_ref_term_YData[0]));
      t15_2_B.c_eob_e = t15_2_B.g2_ref_term;
    }

    /* Sum: '<S8>/Add1' */
    t15_2_B.Add1_j = t15_2_B.e2[1] - t15_2_B.c_eob_e;

    /* Lookup: '<S8>/Lookup Table2' */
    t15_2_B.LookupTable2 = rt_Lookup((const real_T *)
      (&t15_2_P.LookupTable2_XData[0]), 4, t15_2_Y.Time, (const real_T *)
      (&t15_2_P.LookupTable2_YData[0]));

    /* Product: '<S8>/Divide1' */
    t15_2_B.Divide1_k = t15_2_B.Add1_j * t15_2_B.LookupTable2;

    /* Memory: '<S25>/Memory1' */
    t15_2_B.Memory1_f = t15_2_DWork.Memory1_PreviousInput_f;

    /* Switch: '<S25>/c_eob ' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_b1) {
      t15_2_B.c_eob_k5 = t15_2_Y.Time;
    } else {
      t15_2_B.c_eob_k5 = t15_2_B.Memory1_f;
    }

    /* Switch: '<S25>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_p) {
      /* Lookup: '<S25>/g3_ref' */
      t15_2_B.g3_ref = rt_Lookup((const real_T *)(&t15_2_P.g3_ref_XData[0]), 10,
        t15_2_Y.Time, (const real_T *)(&t15_2_P.g3_ref_YData[0]));
      t15_2_B.c_eob_kv = t15_2_B.g3_ref;
    } else {
      /* Sum: '<S25>/Add2' */
      t15_2_B.Add2_iv = t15_2_Y.Time - t15_2_B.c_eob_k5;

      /* Lookup: '<S25>/g3_ref_term' */
      t15_2_B.g3_ref_term = rt_Lookup((const real_T *)
        (&t15_2_P.g3_ref_term_XData[0]), 5, t15_2_B.Add2_iv, (const real_T *)
        (&t15_2_P.g3_ref_term_YData[0]));
      t15_2_B.c_eob_kv = t15_2_B.g3_ref_term;
    }

    /* Sum: '<S8>/Add3' */
    t15_2_B.Add3_b = t15_2_B.e2[2] - t15_2_B.c_eob_kv;

    /* Memory: '<S26>/Memory1' */
    t15_2_B.Memory1_dh = t15_2_DWork.Memory1_PreviousInput_p;

    /* Switch: '<S26>/c_eob  ' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_mj) {
      t15_2_B.c_eob_i = t15_2_Y.Time;
    } else {
      t15_2_B.c_eob_i = t15_2_B.Memory1_dh;
    }

    /* Switch: '<S26>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_dc) {
      /* Lookup: '<S26>/g4_ref' */
      t15_2_B.g4_ref = rt_Lookup((const real_T *)(&t15_2_P.g4_ref_XData[0]), 7,
        t15_2_Y.Time, (const real_T *)(&t15_2_P.g4_ref_YData[0]));
      t15_2_B.c_eob_ij = t15_2_B.g4_ref;
    } else {
      /* Sum: '<S26>/Add2' */
      t15_2_B.Add2_o = t15_2_Y.Time - t15_2_B.c_eob_i;

      /* Lookup: '<S26>/g4_ref_term' */
      t15_2_B.g4_ref_term = rt_Lookup((const real_T *)
        (&t15_2_P.g4_ref_term_XData[0]), 6, t15_2_B.Add2_o, (const real_T *)
        (&t15_2_P.g4_ref_term_YData[0]));
      t15_2_B.c_eob_ij = t15_2_B.g4_ref_term;
    }

    /* Sum: '<S8>/Add4' */
    t15_2_B.Add4_j = t15_2_B.e2[3] - t15_2_B.c_eob_ij;

    /* Lookup: '<S8>/Lookup Table3' */
    t15_2_B.LookupTable3 = rt_Lookup((const real_T *)
      (&t15_2_P.LookupTable3_XData[0]), 4, t15_2_Y.Time, (const real_T *)
      (&t15_2_P.LookupTable3_YData[0]));

    /* Product: '<S8>/Divide2' */
    t15_2_B.Divide2 = t15_2_B.Add4_j * t15_2_B.LookupTable3;

    /* Memory: '<S27>/Memory1' */
    t15_2_B.Memory1_g = t15_2_DWork.Memory1_PreviousInput_i;

    /* Switch: '<S27>/c_eob  ' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_ll) {
      t15_2_B.c_eob_e1 = t15_2_Y.Time;
    } else {
      t15_2_B.c_eob_e1 = t15_2_B.Memory1_g;
    }

    /* Switch: '<S27>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_ps) {
      /* Lookup: '<S27>/g5_ref' */
      t15_2_B.g5_ref = rt_Lookup((const real_T *)(&t15_2_P.g5_ref_XData[0]), 7,
        t15_2_Y.Time, (const real_T *)(&t15_2_P.g5_ref_YData[0]));
      t15_2_B.c_eob_bo = t15_2_B.g5_ref;
    } else {
      /* Sum: '<S27>/Add2' */
      t15_2_B.Add2_g = t15_2_Y.Time - t15_2_B.c_eob_e1;

      /* Lookup: '<S27>/g5_ref_term' */
      t15_2_B.g5_ref_term = rt_Lookup((const real_T *)
        (&t15_2_P.g5_ref_term_XData[0]), 5, t15_2_B.Add2_g, (const real_T *)
        (&t15_2_P.g5_ref_term_YData[0]));
      t15_2_B.c_eob_bo = t15_2_B.g5_ref_term;
    }

    /* Sum: '<S8>/Add5' */
    t15_2_B.Add5_k = t15_2_B.e2[4] - t15_2_B.c_eob_bo;

    /* Lookup: '<S28>/g6_ref' */
    t15_2_B.g6_ref = rt_Lookup((const real_T *)(&t15_2_P.g6_ref_XData[0]), 7,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.g6_ref_YData[0]));

    /* Memory: '<S28>/Memory2' */
    t15_2_B.Memory2_m4 = t15_2_DWork.Memory2_PreviousInput_o;

    /* Switch: '<S28>/c_eob  1' */
    if (t15_2_B.u > t15_2_P.c_eob1_Threshold) {
      t15_2_B.c_eob1 = t15_2_B.g6_ref;
    } else {
      t15_2_B.c_eob1 = t15_2_B.Memory2_m4;
    }

    /* Memory: '<S28>/Memory1' */
    t15_2_B.Memory1_dn = t15_2_DWork.Memory1_PreviousInput_c;

    /* Switch: '<S28>/c_eob  ' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_h) {
      t15_2_B.c_eob_lg = t15_2_Y.Time;
    } else {
      t15_2_B.c_eob_lg = t15_2_B.Memory1_dn;
    }

    /* Switch: '<S28>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_jz) {
      t15_2_B.c_eob_fd = t15_2_B.g6_ref;
    } else {
      /* Sum: '<S28>/Add2' */
      t15_2_B.Add2_ft = t15_2_Y.Time - t15_2_B.c_eob_lg;

      /* Lookup: '<S28>/g6_ref_term' */
      t15_2_B.g6_ref_term = rt_Lookup((const real_T *)
        (&t15_2_P.g6_ref_term_XData[0]), 6, t15_2_B.Add2_ft, (const real_T *)
        (&t15_2_P.g6_ref_term_YData[0]));

      /* Sum: '<S28>/Add1' */
      t15_2_B.Add1_f = t15_2_B.c_eob1 - t15_2_B.g6_ref_term;
      t15_2_B.c_eob_fd = t15_2_B.Add1_f;
    }

    /* Sum: '<S8>/Add6' */
    t15_2_B.Add6_g = t15_2_B.e2[5] - t15_2_B.c_eob_fd;

    /* Gain: '<S8>/1e-2' */
    t15_2_B.e2_g[0] = t15_2_P.e2_Gain_h * t15_2_B.Divide6_i;
    t15_2_B.e2_g[1] = t15_2_P.e2_Gain_h * t15_2_B.Divide1_k;
    t15_2_B.e2_g[2] = t15_2_P.e2_Gain_h * t15_2_B.Add3_b;
    t15_2_B.e2_g[3] = t15_2_P.e2_Gain_h * t15_2_B.Divide2;
    t15_2_B.e2_g[4] = t15_2_P.e2_Gain_h * t15_2_B.Add5_k;
    t15_2_B.e2_g[5] = t15_2_P.e2_Gain_h * t15_2_B.Add6_g;

    /* Gain: '<S9>/1e6' */
    t15_2_B.e6_e = t15_2_P.e6_Gain_d * t15_2_B.Add2;

    /* RelationalOperator: '<S29>/Compare' incorporates:
     *  Constant: '<S29>/Constant'
     */
    t15_2_B.Compare_l = (t15_2_B.e6 > t15_2_P.Constant_Value_o);

    /* RelationalOperator: '<S30>/Compare' incorporates:
     *  Constant: '<S30>/Constant'
     */
    t15_2_B.Compare_h = (t15_2_Y.Time > t15_2_P.Constant_Value_e);

    /* Logic: '<S10>/Logical Operator1' */
    t15_2_B.LogicalOperator1_a = (real_T)((t15_2_B.Compare_l != 0) ||
      (t15_2_B.Compare_h != 0));

    /* Switch: '<S10>/0.99' incorporates:
     *  Constant: '<S1>/Constant4'
     */
    if (t15_2_B.LogicalOperator1_a >= t15_2_P.u9_Threshold_k) {
      for (i = 0; i < 6; i++) {
        t15_2_B.u9_a[i] = t15_2_B.e2_g[i];
      }

      t15_2_B.u9_a[6] = t15_2_P.Constant4_Value_h;
      t15_2_B.u9_a[7] = t15_2_B.Add1_o;
      t15_2_B.u9_a[8] = t15_2_B.Add3_a;
      t15_2_B.u9_a[9] = t15_2_B.Add1_oq;
      t15_2_B.u9_a[10] = t15_2_B.Add2_d;
      t15_2_B.u9_a[11] = t15_2_B.Add4;
      t15_2_B.u9_a[12] = t15_2_B.Divide6_l;
      t15_2_B.u9_a[13] = t15_2_B.Add6;
      t15_2_B.u9_a[14] = t15_2_B.Add7;
      t15_2_B.u9_a[15] = t15_2_B.Add8;
      t15_2_B.u9_a[16] = t15_2_B.Add9;
      t15_2_B.u9_a[17] = t15_2_B.Add10;
      t15_2_B.u9_a[18] = t15_2_B.Add11;
      t15_2_B.u9_a[19] = t15_2_P.Constant4_Value_h;
    } else {
      /* Lookup: '<S1>/elong_ref' */
      t15_2_B.elong_ref = rt_Lookup((const real_T *)(&t15_2_P.elong_ref_XData[0]),
        7, t15_2_Y.Time, (const real_T *)(&t15_2_P.elong_ref_YData[0]));

      /* Sum: '<S1>/Add2' incorporates:
       *  Inport: '<Root>/In1'
       */
      t15_2_B.Add2_f = t15_2_U.In1[2] - t15_2_B.elong_ref;
      t15_2_B.u9_a[0] = t15_2_B.Add2_f;
      t15_2_B.u9_a[1] = t15_2_P.Constant4_Value_h;

      /* Gain: '<S1>/k_gaplim' */
      t15_2_B.k_gaplim[0] = t15_2_P.k_gaplim_Gain[0] * t15_2_B.e2_g[2];
      t15_2_B.u9_a[2] = t15_2_B.k_gaplim[0];

      /* Gain: '<S1>/k_gaplim' */
      t15_2_B.k_gaplim[1] = t15_2_P.k_gaplim_Gain[1] * t15_2_B.e2_g[3];
      t15_2_B.u9_a[3] = t15_2_B.k_gaplim[1];

      /* Gain: '<S1>/k_gaplim' */
      t15_2_B.k_gaplim[2] = t15_2_P.k_gaplim_Gain[2] * t15_2_B.e2_g[4];
      t15_2_B.u9_a[4] = t15_2_B.k_gaplim[2];

      /* Gain: '<S1>/k_gaplim' */
      t15_2_B.k_gaplim[3] = t15_2_P.k_gaplim_Gain[3] * t15_2_B.e2_g[5];
      t15_2_B.u9_a[5] = t15_2_B.k_gaplim[3];
      t15_2_B.u9_a[6] = t15_2_P.Constant4_Value_h;
      t15_2_B.u9_a[7] = t15_2_B.Add1_o;
      t15_2_B.u9_a[8] = t15_2_B.Add3_a;
      t15_2_B.u9_a[9] = t15_2_B.Add1_oq;
      t15_2_B.u9_a[10] = t15_2_B.Add2_d;
      t15_2_B.u9_a[11] = t15_2_B.Add4;
      t15_2_B.u9_a[12] = t15_2_B.Divide6_l;
      t15_2_B.u9_a[13] = t15_2_B.Add6;
      t15_2_B.u9_a[14] = t15_2_B.Add7;
      t15_2_B.u9_a[15] = t15_2_B.Add8;
      t15_2_B.u9_a[16] = t15_2_B.Add9;
      t15_2_B.u9_a[17] = t15_2_B.Add10;
      t15_2_B.u9_a[18] = t15_2_B.Add11;
      t15_2_B.u9_a[19] = t15_2_P.Constant4_Value_h;
    }

    /* RelationalOperator: '<S47>/Compare' incorporates:
     *  Constant: '<S47>/Constant'
     */
    t15_2_B.Compare_hj = (t15_2_B.e6 < t15_2_P.Constant_Value_e4);

    /* RelationalOperator: '<S48>/Compare' incorporates:
     *  Constant: '<S48>/Constant'
     */
    t15_2_B.Compare_m = (t15_2_Y.Time > t15_2_P.Constant_Value_hc);

    /* Logic: '<S34>/Logical Operator2' */
    t15_2_B.LogicalOperator2_o = (real_T)((t15_2_B.Compare_hj != 0) &&
      (t15_2_B.Compare_m != 0));
    for (i = 0; i < 11; i++) {
      /* Gain: '<S33>/1e3' */
      t15_2_B.e3_m[i] = t15_2_P.e3_Gain_m * t15_2_B.e6_l[i];

      /* Abs: '<S33>/Abs' */
      t15_2_B.Abs[i] = fabs(t15_2_B.e3_m[i]);

      /* Gain: '<S33>/ntur' incorporates:
       *  Constant: '<S2>/Imax'
       */
      t15_2_B.ntur[i] = t15_2_P.ntur_Gain[i] * t15_2_P.Imax_Value[i];

      /* Sum: '<S33>/Sum2' */
      t15_2_B.Sum2_p[i] = t15_2_B.ntur[i] - t15_2_B.Abs[i];

      /* Gain: '<S33>/c_cur_max' */
      t15_2_B.c_cur_max[i] = t15_2_P.c_cur_max_Gain * t15_2_B.ntur[i];

      /* Sum: '<S33>/Sum1' */
      t15_2_B.Sum1[i] = t15_2_B.ntur[i] - t15_2_B.c_cur_max[i];

      /* Product: '<S33>/Divide4' */
      t15_2_B.Divide4_j[i] = t15_2_B.Sum2_p[i] / t15_2_B.Sum1[i];

      /* Product: '<S33>/Divide1' */
      t15_2_B.Divide1_j[i] = t15_2_B.Divide4_j[i] * t15_2_B.Divide4_j[i] *
        t15_2_B.Divide4_j[i];
      tmin = t15_2_B.Divide1_j[i];
      t15_2_B.Saturation[i] = rt_SATURATE(tmin, t15_2_P.Saturation_LowerSat,
        t15_2_P.Saturation_UpperSat);

      /* RelationalOperator: '<S45>/Compare' incorporates:
       *  Constant: '<S45>/Constant'
       */
      t15_2_B.Compare_lm[i] = (t15_2_B.Saturation[i] < t15_2_P.Constant_Value_m);

      /* Memory: '<S34>/Memory1' */
      t15_2_B.Memory1_eo[i] = t15_2_DWork.Memory1_PreviousInput_er[i];

      /* Memory: '<S36>/Memory' */
      t15_2_B.Memory_m[i] = t15_2_DWork.Memory_PreviousInput_i[i];
    }

    /* RelationalOperator: '<S49>/Compare' incorporates:
     *  Constant: '<S49>/Constant'
     */
    t15_2_B.Compare_i = (t15_2_B.e6 < t15_2_P.Constant_Value_g);

    /* RelationalOperator: '<S50>/Compare' incorporates:
     *  Constant: '<S50>/Constant'
     */
    t15_2_B.Compare_iq = (t15_2_Y.Time > t15_2_P.Constant_Value_eb);

    /* RelationalOperator: '<S51>/Compare' incorporates:
     *  Constant: '<S51>/Constant'
     */
    t15_2_B.Compare_c = (t15_2_B.e6 > t15_2_P.Constant_Value_bi);

    /* Logic: '<S36>/Logical Operator1' */
    t15_2_B.LogicalOperator1_h = (real_T)((t15_2_B.Compare_i != 0) &&
      (t15_2_B.Compare_iq != 0) && (t15_2_B.Compare_c != 0));

    /* Memory: '<S44>/Memory3' */
    t15_2_B.Memory3 = t15_2_DWork.Memory3_PreviousInput;

    /* RelationalOperator: '<S59>/Compare' incorporates:
     *  Constant: '<S59>/Constant'
     */
    t15_2_B.Compare_eq = (t15_2_B.e6 > t15_2_P.Constant_Value_a);

    /* RelationalOperator: '<S60>/Compare' incorporates:
     *  Constant: '<S60>/Constant'
     */
    t15_2_B.Compare_ec = (t15_2_Y.Time > t15_2_P.Constant_Value_od);

    /* Logic: '<S44>/Logical Operator1' */
    t15_2_B.LogicalOperator1_c = (real_T)((t15_2_B.Compare_eq != 0) ||
      (t15_2_B.Compare_ec != 0));

    /* Switch: '<S44>/0.9999' */
    if (t15_2_B.LogicalOperator1_c > t15_2_P.u999_Threshold) {
      t15_2_B.u999 = t15_2_B.Memory3;
    } else {
      t15_2_B.u999 = t15_2_Y.Time;
    }

    /* Sum: '<S44>/Subtract2' */
    t15_2_B.Subtract2 = t15_2_Y.Time - t15_2_B.u999;

    /* Gain: '<S44>/Gain1' */
    t15_2_B.Gain1 = t15_2_P.Gain1_Gain * t15_2_B.Subtract2;

    /* Sum: '<S44>/Subtract1' incorporates:
     *  Constant: '<S44>/1'
     */
    t15_2_B.Subtract1 = t15_2_B.Gain1 + t15_2_P._Value;

    /* Saturate: '<S44>/Saturation1' */
    tmin = t15_2_B.Subtract1;
    t15_2_B.Saturation1 = rt_SATURATE(tmin, t15_2_P.Saturation1_LowerSat,
      t15_2_P.Saturation1_UpperSat);

    /* Product: '<S2>/Divide2' */
    for (i = 0; i < 20; i++) {
      t15_2_B.Divide2_j[i] = t15_2_B.LogicalOperator1_c * t15_2_B.u9_a[i];
    }

    /* DiscreteStateSpace: '<S2>/Div. contr.' */
    {
      {
        static const int_T colCidxRow0[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = &t15_2_P.Divcontr_C[0];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *y0 = &t15_2_B.Divcontr[0];
        int_T numNonZero = 19;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow0[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow0[0];
        const real_T *pD0 = &t15_2_P.Divcontr_D[0];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *y0 = &t15_2_B.Divcontr[0];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y0 += (*pD0++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow1[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19 };

        const int_T *pCidx = &colCidxRow1[0];
        const real_T *pC20 = &t15_2_P.Divcontr_C[20];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *y1 = &t15_2_B.Divcontr[1];
        int_T numNonZero = 19;
        *y1 = (*pC20++) * xd[*pCidx++];
        while (numNonZero--) {
          *y1 += (*pC20++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow1[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow1[0];
        const real_T *pD17 = &t15_2_P.Divcontr_D[17];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *y1 = &t15_2_B.Divcontr[1];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y1 += (*pD17++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow2[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19 };

        const int_T *pCidx = &colCidxRow2[0];
        const real_T *pC40 = &t15_2_P.Divcontr_C[40];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *y2 = &t15_2_B.Divcontr[2];
        int_T numNonZero = 19;
        *y2 = (*pC40++) * xd[*pCidx++];
        while (numNonZero--) {
          *y2 += (*pC40++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow2[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow2[0];
        const real_T *pD34 = &t15_2_P.Divcontr_D[34];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *y2 = &t15_2_B.Divcontr[2];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y2 += (*pD34++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow3[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19 };

        const int_T *pCidx = &colCidxRow3[0];
        const real_T *pC60 = &t15_2_P.Divcontr_C[60];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *y3 = &t15_2_B.Divcontr[3];
        int_T numNonZero = 19;
        *y3 = (*pC60++) * xd[*pCidx++];
        while (numNonZero--) {
          *y3 += (*pC60++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow3[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow3[0];
        const real_T *pD51 = &t15_2_P.Divcontr_D[51];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *y3 = &t15_2_B.Divcontr[3];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y3 += (*pD51++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow4[5] = { 20, 21, 22, 23, 24 };

        const int_T *pCidx = &colCidxRow4[0];
        const real_T *pC80 = &t15_2_P.Divcontr_C[80];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *y4 = &t15_2_B.Divcontr[4];
        int_T numNonZero = 4;
        *y4 = (*pC80++) * xd[*pCidx++];
        while (numNonZero--) {
          *y4 += (*pC80++) * xd[*pCidx++];
        }
      }

      t15_2_B.Divcontr[4] += (t15_2_P.Divcontr_D[68])*t15_2_B.Divide2_j[12];

      {
        static const int_T colCidxRow5[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19 };

        const int_T *pCidx = &colCidxRow5[0];
        const real_T *pC85 = &t15_2_P.Divcontr_C[85];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *y5 = &t15_2_B.Divcontr[5];
        int_T numNonZero = 19;
        *y5 = (*pC85++) * xd[*pCidx++];
        while (numNonZero--) {
          *y5 += (*pC85++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow5[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow5[0];
        const real_T *pD69 = &t15_2_P.Divcontr_D[69];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *y5 = &t15_2_B.Divcontr[5];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y5 += (*pD69++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow6[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19 };

        const int_T *pCidx = &colCidxRow6[0];
        const real_T *pC105 = &t15_2_P.Divcontr_C[105];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *y6 = &t15_2_B.Divcontr[6];
        int_T numNonZero = 19;
        *y6 = (*pC105++) * xd[*pCidx++];
        while (numNonZero--) {
          *y6 += (*pC105++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow6[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow6[0];
        const real_T *pD86 = &t15_2_P.Divcontr_D[86];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *y6 = &t15_2_B.Divcontr[6];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y6 += (*pD86++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow7[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19 };

        const int_T *pCidx = &colCidxRow7[0];
        const real_T *pC125 = &t15_2_P.Divcontr_C[125];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *y7 = &t15_2_B.Divcontr[7];
        int_T numNonZero = 19;
        *y7 = (*pC125++) * xd[*pCidx++];
        while (numNonZero--) {
          *y7 += (*pC125++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow7[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow7[0];
        const real_T *pD103 = &t15_2_P.Divcontr_D[103];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *y7 = &t15_2_B.Divcontr[7];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y7 += (*pD103++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow8[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19 };

        const int_T *pCidx = &colCidxRow8[0];
        const real_T *pC145 = &t15_2_P.Divcontr_C[145];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *y8 = &t15_2_B.Divcontr[8];
        int_T numNonZero = 19;
        *y8 = (*pC145++) * xd[*pCidx++];
        while (numNonZero--) {
          *y8 += (*pC145++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow8[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow8[0];
        const real_T *pD120 = &t15_2_P.Divcontr_D[120];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *y8 = &t15_2_B.Divcontr[8];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y8 += (*pD120++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow9[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19 };

        const int_T *pCidx = &colCidxRow9[0];
        const real_T *pC165 = &t15_2_P.Divcontr_C[165];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *y9 = &t15_2_B.Divcontr[9];
        int_T numNonZero = 19;
        *y9 = (*pC165++) * xd[*pCidx++];
        while (numNonZero--) {
          *y9 += (*pC165++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow9[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow9[0];
        const real_T *pD137 = &t15_2_P.Divcontr_D[137];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *y9 = &t15_2_B.Divcontr[9];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y9 += (*pD137++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow10[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19 };

        const int_T *pCidx = &colCidxRow10[0];
        const real_T *pC185 = &t15_2_P.Divcontr_C[185];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *y10 = &t15_2_B.Divcontr[10];
        int_T numNonZero = 19;
        *y10 = (*pC185++) * xd[*pCidx++];
        while (numNonZero--) {
          *y10 += (*pC185++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow10[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow10[0];
        const real_T *pD154 = &t15_2_P.Divcontr_D[154];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *y10 = &t15_2_B.Divcontr[10];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y10 += (*pD154++) * u[*pDidx++];
        }
      }
    }

    /* Switch: '<S36>/0.99' */
    if (t15_2_B.LogicalOperator1_h >= t15_2_P.u9_Threshold_a) {
      memcpy((void *)(&t15_2_B.u9_d[0]), (void *)(&t15_2_B.Memory_m[0]), 11U *
             sizeof(real_T));
    } else {
      /* Sum: '<S44>/Subtract3' incorporates:
       *  Constant: '<S44>/1 '
       */
      t15_2_B.Subtract3_a = t15_2_P._Value_i - t15_2_B.Saturation1;
      for (i = 0; i < 11; i++) {
        /* Product: '<S2>/Divide' */
        t15_2_B.Divide_e[i] = t15_2_B.Subtract3_a * t15_2_B.Divcontr[i];
        t15_2_B.u9_d[i] = t15_2_B.Divide_e[i];
      }
    }

    /* Memory: '<S42>/Memory1' */
    t15_2_B.Memory1_n = t15_2_DWork.Memory1_PreviousInput_a;

    /* RelationalOperator: '<S57>/Compare' incorporates:
     *  Constant: '<S57>/Constant'
     */
    t15_2_B.Compare_ej = (t15_2_B.e6 < t15_2_P.Constant_Value_i);

    /* RelationalOperator: '<S58>/Compare' incorporates:
     *  Constant: '<S58>/Constant'
     */
    t15_2_B.Compare_in = (t15_2_Y.Time > t15_2_P.Constant_Value_d);

    /* Logic: '<S42>/Logical Operator1' */
    t15_2_B.LogicalOperator1_d = (real_T)((t15_2_B.Compare_ej != 0) &&
      (t15_2_B.Compare_in != 0));

    /* Switch: '<S42>/0.9999' */
    if (t15_2_B.LogicalOperator1_d > t15_2_P.u999_Threshold_a) {
      t15_2_B.u999_b = t15_2_B.Memory1_n;
    } else {
      t15_2_B.u999_b = t15_2_Y.Time;
    }

    /* Product: '<S2>/Divide13' */
    for (i = 0; i < 20; i++) {
      t15_2_B.Divide13[i] = t15_2_B.Divide2_j[i] * t15_2_B.LogicalOperator1_d;
    }

    /* DiscreteStateSpace: '<S2>/Div_rd contr' */
    {
      {
        static const int_T colCidxRow0[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = &t15_2_P.Div_rdcontr_C[0];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *y0 = &t15_2_B.Div_rdcontr[0];
        int_T numNonZero = 14;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow0[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow0[0];
        const real_T *pD0 = &t15_2_P.Div_rdcontr_D[0];
        const real_T *u = t15_2_B.Divide13;
        real_T *y0 = &t15_2_B.Div_rdcontr[0];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *y0 += (*pD0++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow1[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14 };

        const int_T *pCidx = &colCidxRow1[0];
        const real_T *pC15 = &t15_2_P.Div_rdcontr_C[15];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *y1 = &t15_2_B.Div_rdcontr[1];
        int_T numNonZero = 14;
        *y1 = (*pC15++) * xd[*pCidx++];
        while (numNonZero--) {
          *y1 += (*pC15++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow1[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow1[0];
        const real_T *pD18 = &t15_2_P.Div_rdcontr_D[18];
        const real_T *u = t15_2_B.Divide13;
        real_T *y1 = &t15_2_B.Div_rdcontr[1];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *y1 += (*pD18++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow2[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14 };

        const int_T *pCidx = &colCidxRow2[0];
        const real_T *pC30 = &t15_2_P.Div_rdcontr_C[30];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *y2 = &t15_2_B.Div_rdcontr[2];
        int_T numNonZero = 14;
        *y2 = (*pC30++) * xd[*pCidx++];
        while (numNonZero--) {
          *y2 += (*pC30++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow2[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow2[0];
        const real_T *pD36 = &t15_2_P.Div_rdcontr_D[36];
        const real_T *u = t15_2_B.Divide13;
        real_T *y2 = &t15_2_B.Div_rdcontr[2];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *y2 += (*pD36++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow3[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14 };

        const int_T *pCidx = &colCidxRow3[0];
        const real_T *pC45 = &t15_2_P.Div_rdcontr_C[45];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *y3 = &t15_2_B.Div_rdcontr[3];
        int_T numNonZero = 14;
        *y3 = (*pC45++) * xd[*pCidx++];
        while (numNonZero--) {
          *y3 += (*pC45++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow3[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow3[0];
        const real_T *pD54 = &t15_2_P.Div_rdcontr_D[54];
        const real_T *u = t15_2_B.Divide13;
        real_T *y3 = &t15_2_B.Div_rdcontr[3];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *y3 += (*pD54++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow4[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14 };

        const int_T *pCidx = &colCidxRow4[0];
        const real_T *pC60 = &t15_2_P.Div_rdcontr_C[60];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *y4 = &t15_2_B.Div_rdcontr[4];
        int_T numNonZero = 14;
        *y4 = (*pC60++) * xd[*pCidx++];
        while (numNonZero--) {
          *y4 += (*pC60++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow4[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow4[0];
        const real_T *pD72 = &t15_2_P.Div_rdcontr_D[72];
        const real_T *u = t15_2_B.Divide13;
        real_T *y4 = &t15_2_B.Div_rdcontr[4];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *y4 += (*pD72++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow5[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14 };

        const int_T *pCidx = &colCidxRow5[0];
        const real_T *pC75 = &t15_2_P.Div_rdcontr_C[75];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *y5 = &t15_2_B.Div_rdcontr[5];
        int_T numNonZero = 14;
        *y5 = (*pC75++) * xd[*pCidx++];
        while (numNonZero--) {
          *y5 += (*pC75++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow5[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow5[0];
        const real_T *pD90 = &t15_2_P.Div_rdcontr_D[90];
        const real_T *u = t15_2_B.Divide13;
        real_T *y5 = &t15_2_B.Div_rdcontr[5];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *y5 += (*pD90++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow6[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14 };

        const int_T *pCidx = &colCidxRow6[0];
        const real_T *pC90 = &t15_2_P.Div_rdcontr_C[90];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *y6 = &t15_2_B.Div_rdcontr[6];
        int_T numNonZero = 14;
        *y6 = (*pC90++) * xd[*pCidx++];
        while (numNonZero--) {
          *y6 += (*pC90++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow6[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow6[0];
        const real_T *pD108 = &t15_2_P.Div_rdcontr_D[108];
        const real_T *u = t15_2_B.Divide13;
        real_T *y6 = &t15_2_B.Div_rdcontr[6];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *y6 += (*pD108++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow7[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14 };

        const int_T *pCidx = &colCidxRow7[0];
        const real_T *pC105 = &t15_2_P.Div_rdcontr_C[105];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *y7 = &t15_2_B.Div_rdcontr[7];
        int_T numNonZero = 14;
        *y7 = (*pC105++) * xd[*pCidx++];
        while (numNonZero--) {
          *y7 += (*pC105++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow7[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow7[0];
        const real_T *pD126 = &t15_2_P.Div_rdcontr_D[126];
        const real_T *u = t15_2_B.Divide13;
        real_T *y7 = &t15_2_B.Div_rdcontr[7];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *y7 += (*pD126++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow8[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14 };

        const int_T *pCidx = &colCidxRow8[0];
        const real_T *pC120 = &t15_2_P.Div_rdcontr_C[120];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *y8 = &t15_2_B.Div_rdcontr[8];
        int_T numNonZero = 14;
        *y8 = (*pC120++) * xd[*pCidx++];
        while (numNonZero--) {
          *y8 += (*pC120++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow8[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow8[0];
        const real_T *pD144 = &t15_2_P.Div_rdcontr_D[144];
        const real_T *u = t15_2_B.Divide13;
        real_T *y8 = &t15_2_B.Div_rdcontr[8];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *y8 += (*pD144++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow9[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14 };

        const int_T *pCidx = &colCidxRow9[0];
        const real_T *pC135 = &t15_2_P.Div_rdcontr_C[135];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *y9 = &t15_2_B.Div_rdcontr[9];
        int_T numNonZero = 14;
        *y9 = (*pC135++) * xd[*pCidx++];
        while (numNonZero--) {
          *y9 += (*pC135++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow9[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow9[0];
        const real_T *pD162 = &t15_2_P.Div_rdcontr_D[162];
        const real_T *u = t15_2_B.Divide13;
        real_T *y9 = &t15_2_B.Div_rdcontr[9];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *y9 += (*pD162++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow10[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14 };

        const int_T *pCidx = &colCidxRow10[0];
        const real_T *pC150 = &t15_2_P.Div_rdcontr_C[150];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *y10 = &t15_2_B.Div_rdcontr[10];
        int_T numNonZero = 14;
        *y10 = (*pC150++) * xd[*pCidx++];
        while (numNonZero--) {
          *y10 += (*pC150++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow10[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow10[0];
        const real_T *pD180 = &t15_2_P.Div_rdcontr_D[180];
        const real_T *u = t15_2_B.Divide13;
        real_T *y10 = &t15_2_B.Div_rdcontr[10];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *y10 += (*pD180++) * u[*pDidx++];
        }
      }
    }

    /* Memory: '<S40>/Memory1' */
    t15_2_B.Memory1_b = t15_2_DWork.Memory1_PreviousInput_ek;

    /* Switch: '<S40>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_n3) {
      /* Lookup: '<S40>/Ipl_ref' */
      t15_2_B.Ipl_ref = rt_Lookup((const real_T *)(&t15_2_P.Ipl_ref_XData_o[0]),
        78, t15_2_Y.Time, (const real_T *)(&t15_2_P.Ipl_ref_YData_p[0]));
      t15_2_B.c_eob_fp = t15_2_B.Ipl_ref;
    } else {
      t15_2_B.c_eob_fp = t15_2_B.Memory1_b;
    }

    /* Switch: '<S34>/0.999' */
    if (t15_2_B.LogicalOperator2_o > t15_2_P.u99_Threshold) {
      memcpy((void *)(&t15_2_B.u99[0]), (void *)(&t15_2_B.Memory1_eo[0]), 11U *
             sizeof(real_T));
    } else {
      /* Sum: '<S42>/Subtract2' */
      t15_2_B.Subtract2_b = t15_2_Y.Time - t15_2_B.u999_b;

      /* Gain: '<S42>/Gain1' */
      t15_2_B.Gain1_n = t15_2_P.Gain1_Gain_o * t15_2_B.Subtract2_b;

      /* Sum: '<S42>/Subtract3' incorporates:
       *  Constant: '<S42>/1'
       */
      t15_2_B.Subtract3_k = t15_2_B.Gain1_n + t15_2_P._Value_m;

      /* Saturate: '<S42>/Saturation' */
      tmin = t15_2_B.Subtract3_k;
      t15_2_B.Saturation_i = rt_SATURATE(tmin, t15_2_P.Saturation_LowerSat_c,
        t15_2_P.Saturation_UpperSat_g);

      /* Sum: '<S42>/Subtract1' incorporates:
       *  Constant: '<S42>/1 '
       */
      t15_2_B.Subtract1_f = t15_2_P._Value_g - t15_2_B.Saturation_i;

      /* Switch: '<S2>/c_eob' */
      if (t15_2_B.u > t15_2_P.c_eob_Threshold_cl) {
        /* Gain: '<S2>/atpl2' */
        t15_2_B.atpl2 = t15_2_P.atpl2_Gain * t15_2_B.e6;

        /* Saturate: '<S2>/Saturation' */
        tmin = t15_2_B.atpl2;
        t15_2_B.Saturation_a1 = rt_SATURATE(tmin, t15_2_P.Saturation_LowerSat_g,
          t15_2_P.Saturation_UpperSat_n);
        t15_2_B.c_eob_j = t15_2_B.Saturation_a1;
      } else {
        /* Product: '<S40>/Divide6' */
        t15_2_B.Divide6_o = t15_2_B.c_eob_fp * t15_2_B.u;

        /* Sum: '<S40>/Sum' incorporates:
         *  Constant: '<S40>/c1_y0'
         */
        t15_2_B.Sum = t15_2_B.Divide6_o - t15_2_P.c1_y0_Value;

        /* Product: '<S40>/Divide2' incorporates:
         *  Constant: '<S40>/(1-y0)//...'
         */
        t15_2_B.Divide2_h = t15_2_B.Sum * t15_2_P.uy0_Value;

        /* Sum: '<S40>/Sum1' incorporates:
         *  Constant: '<S40>/y0'
         */
        t15_2_B.Sum1_k = t15_2_B.Divide2_h + t15_2_P.y0_Value;

        /* Saturate: '<S40>/[1 y0]' */
        tmin = t15_2_B.Sum1_k;
        t15_2_B.uy0 = rt_SATURATE(tmin, t15_2_P.uy0_LowerSat,
          t15_2_P.uy0_UpperSat);
        t15_2_B.c_eob_j = t15_2_B.uy0;
      }

      for (i = 0; i < 11; i++) {
        /* Product: '<S2>/Divide3' */
        t15_2_B.Divide3_g[i] = t15_2_B.Div_rdcontr[i] * t15_2_B.c_eob_j *
          t15_2_B.Subtract1_f;

        /* Product: '<S2>/Divide1' */
        t15_2_B.Divide1_b[i] = t15_2_B.u9_d[i] * t15_2_B.Saturation_i;

        /* Sum: '<S2>/Sum2' */
        t15_2_B.Sum2_i[i] = t15_2_B.Divide1_b[i] + t15_2_B.Divide3_g[i];
        t15_2_B.u99[i] = t15_2_B.Sum2_i[i];
      }
    }

    /* Memory: '<S41>/Memory1' */
    t15_2_B.Memory1_k = t15_2_DWork.Memory1_PreviousInput_j;

    /* Switch: '<S41>/0.9999' */
    if (t15_2_B.LogicalOperator2 > t15_2_P.u999_Threshold_g) {
      t15_2_B.u999_l = t15_2_B.Memory1_k;
    } else {
      t15_2_B.u999_l = t15_2_Y.Time;
    }

    /* Sum: '<S41>/Subtract2' */
    t15_2_B.Subtract2_k = t15_2_Y.Time - t15_2_B.u999_l;

    /* Gain: '<S41>/Gain1' */
    t15_2_B.Gain1_g = t15_2_P.Gain1_Gain_j * t15_2_B.Subtract2_k;

    /* Sum: '<S41>/Subtract3' incorporates:
     *  Constant: '<S41>/1'
     */
    t15_2_B.Subtract3 = t15_2_B.Gain1_g + t15_2_P._Value_a;

    /* Saturate: '<S41>/Saturation' */
    tmin = t15_2_B.Subtract3;
    t15_2_B.Saturation_a = rt_SATURATE(tmin, t15_2_P.Saturation_LowerSat_a,
      t15_2_P.Saturation_UpperSat_m);

    /* Product: '<S2>/Divide4' */
    for (i = 0; i < 11; i++) {
      t15_2_B.Divide4_a[i] = t15_2_B.u99[i] * t15_2_B.Saturation_a;
    }

    /* DiscreteStateSpace: '<S2>/Curr. term. contr' */
    {
      t15_2_B.Currtermcontr[0] = (t15_2_P.Currtermcontr_C[0])*
        t15_2_DWork.Currtermcontr_DSTATE[0];
      t15_2_B.Currtermcontr[1] = (t15_2_P.Currtermcontr_C[1])*
        t15_2_DWork.Currtermcontr_DSTATE[1];
      t15_2_B.Currtermcontr[2] = (t15_2_P.Currtermcontr_C[2])*
        t15_2_DWork.Currtermcontr_DSTATE[2];
      t15_2_B.Currtermcontr[3] = (t15_2_P.Currtermcontr_C[3])*
        t15_2_DWork.Currtermcontr_DSTATE[3];
      t15_2_B.Currtermcontr[4] = (t15_2_P.Currtermcontr_C[4])*
        t15_2_DWork.Currtermcontr_DSTATE[4];
      t15_2_B.Currtermcontr[5] = (t15_2_P.Currtermcontr_C[5])*
        t15_2_DWork.Currtermcontr_DSTATE[5];
      t15_2_B.Currtermcontr[6] = (t15_2_P.Currtermcontr_C[6])*
        t15_2_DWork.Currtermcontr_DSTATE[6];
      t15_2_B.Currtermcontr[7] = (t15_2_P.Currtermcontr_C[7])*
        t15_2_DWork.Currtermcontr_DSTATE[7];
      t15_2_B.Currtermcontr[8] = (t15_2_P.Currtermcontr_C[8])*
        t15_2_DWork.Currtermcontr_DSTATE[8];
      t15_2_B.Currtermcontr[9] = (t15_2_P.Currtermcontr_C[9])*
        t15_2_DWork.Currtermcontr_DSTATE[9];
      t15_2_B.Currtermcontr[10] = (t15_2_P.Currtermcontr_C[10])*
        t15_2_DWork.Currtermcontr_DSTATE[10];
    }

    /* Gain: '<S41>/Gain2' */
    t15_2_B.Gain2 = t15_2_P.Gain2_Gain * t15_2_B.Saturation_a;

    /* Sum: '<S41>/Subtract1' incorporates:
     *  Constant: '<S41>/2'
     */
    t15_2_B.Subtract1_k = t15_2_P._Value_o + t15_2_B.Gain2;
    for (i = 0; i < 11; i++) {
      /* Product: '<S2>/Divide5' */
      t15_2_B.Divide5[i] = t15_2_B.Currtermcontr[i] * t15_2_B.Subtract1_k;

      /* Memory: '<S2>/Memory2' */
      t15_2_B.Memory2_fo[i] = t15_2_DWork.Memory2_PreviousInput_j[i];
    }

    /* Switch: '<S35>/tcont2 ' incorporates:
     *  Constant: '<S35>/zeros(20,1)'
     */
    for (i = 0; i < 20; i++) {
      if (t15_2_Y.Time > t15_2_P.tcont2_Threshold) {
        t15_2_B.tcont2[i] = t15_2_B.u9_a[i];
      } else {
        t15_2_B.tcont2[i] = t15_2_P.zeros201_Value[i];
      }
    }

    /* DiscreteStateSpace: '<S35>/Lim. contr.' */
    {
      {
        static const int_T colCidxRow0[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
        };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = &t15_2_P.Limcontr_C[0];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *y0 = &t15_2_B.Limcontr[0];
        int_T numNonZero = 46;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow0[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow0[0];
        const real_T *pD0 = &t15_2_P.Limcontr_D[0];
        const real_T *u = t15_2_B.tcont2;
        real_T *y0 = &t15_2_B.Limcontr[0];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y0 += (*pD0++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow1[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
        };

        const int_T *pCidx = &colCidxRow1[0];
        const real_T *pC47 = &t15_2_P.Limcontr_C[47];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *y1 = &t15_2_B.Limcontr[1];
        int_T numNonZero = 46;
        *y1 = (*pC47++) * xd[*pCidx++];
        while (numNonZero--) {
          *y1 += (*pC47++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow1[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow1[0];
        const real_T *pD17 = &t15_2_P.Limcontr_D[17];
        const real_T *u = t15_2_B.tcont2;
        real_T *y1 = &t15_2_B.Limcontr[1];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y1 += (*pD17++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow2[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
        };

        const int_T *pCidx = &colCidxRow2[0];
        const real_T *pC94 = &t15_2_P.Limcontr_C[94];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *y2 = &t15_2_B.Limcontr[2];
        int_T numNonZero = 46;
        *y2 = (*pC94++) * xd[*pCidx++];
        while (numNonZero--) {
          *y2 += (*pC94++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow2[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow2[0];
        const real_T *pD34 = &t15_2_P.Limcontr_D[34];
        const real_T *u = t15_2_B.tcont2;
        real_T *y2 = &t15_2_B.Limcontr[2];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y2 += (*pD34++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow3[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
        };

        const int_T *pCidx = &colCidxRow3[0];
        const real_T *pC141 = &t15_2_P.Limcontr_C[141];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *y3 = &t15_2_B.Limcontr[3];
        int_T numNonZero = 46;
        *y3 = (*pC141++) * xd[*pCidx++];
        while (numNonZero--) {
          *y3 += (*pC141++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow3[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow3[0];
        const real_T *pD51 = &t15_2_P.Limcontr_D[51];
        const real_T *u = t15_2_B.tcont2;
        real_T *y3 = &t15_2_B.Limcontr[3];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y3 += (*pD51++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow4[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
        };

        const int_T *pCidx = &colCidxRow4[0];
        const real_T *pC188 = &t15_2_P.Limcontr_C[188];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *y4 = &t15_2_B.Limcontr[4];
        int_T numNonZero = 46;
        *y4 = (*pC188++) * xd[*pCidx++];
        while (numNonZero--) {
          *y4 += (*pC188++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow4[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow4[0];
        const real_T *pD68 = &t15_2_P.Limcontr_D[68];
        const real_T *u = t15_2_B.tcont2;
        real_T *y4 = &t15_2_B.Limcontr[4];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y4 += (*pD68++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow5[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
        };

        const int_T *pCidx = &colCidxRow5[0];
        const real_T *pC235 = &t15_2_P.Limcontr_C[235];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *y5 = &t15_2_B.Limcontr[5];
        int_T numNonZero = 46;
        *y5 = (*pC235++) * xd[*pCidx++];
        while (numNonZero--) {
          *y5 += (*pC235++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow5[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow5[0];
        const real_T *pD85 = &t15_2_P.Limcontr_D[85];
        const real_T *u = t15_2_B.tcont2;
        real_T *y5 = &t15_2_B.Limcontr[5];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y5 += (*pD85++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow6[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
        };

        const int_T *pCidx = &colCidxRow6[0];
        const real_T *pC282 = &t15_2_P.Limcontr_C[282];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *y6 = &t15_2_B.Limcontr[6];
        int_T numNonZero = 46;
        *y6 = (*pC282++) * xd[*pCidx++];
        while (numNonZero--) {
          *y6 += (*pC282++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow6[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow6[0];
        const real_T *pD102 = &t15_2_P.Limcontr_D[102];
        const real_T *u = t15_2_B.tcont2;
        real_T *y6 = &t15_2_B.Limcontr[6];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y6 += (*pD102++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow7[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
        };

        const int_T *pCidx = &colCidxRow7[0];
        const real_T *pC329 = &t15_2_P.Limcontr_C[329];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *y7 = &t15_2_B.Limcontr[7];
        int_T numNonZero = 46;
        *y7 = (*pC329++) * xd[*pCidx++];
        while (numNonZero--) {
          *y7 += (*pC329++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow7[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow7[0];
        const real_T *pD119 = &t15_2_P.Limcontr_D[119];
        const real_T *u = t15_2_B.tcont2;
        real_T *y7 = &t15_2_B.Limcontr[7];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y7 += (*pD119++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow8[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
        };

        const int_T *pCidx = &colCidxRow8[0];
        const real_T *pC376 = &t15_2_P.Limcontr_C[376];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *y8 = &t15_2_B.Limcontr[8];
        int_T numNonZero = 46;
        *y8 = (*pC376++) * xd[*pCidx++];
        while (numNonZero--) {
          *y8 += (*pC376++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow8[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow8[0];
        const real_T *pD136 = &t15_2_P.Limcontr_D[136];
        const real_T *u = t15_2_B.tcont2;
        real_T *y8 = &t15_2_B.Limcontr[8];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y8 += (*pD136++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow9[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
        };

        const int_T *pCidx = &colCidxRow9[0];
        const real_T *pC423 = &t15_2_P.Limcontr_C[423];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *y9 = &t15_2_B.Limcontr[9];
        int_T numNonZero = 46;
        *y9 = (*pC423++) * xd[*pCidx++];
        while (numNonZero--) {
          *y9 += (*pC423++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow9[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow9[0];
        const real_T *pD153 = &t15_2_P.Limcontr_D[153];
        const real_T *u = t15_2_B.tcont2;
        real_T *y9 = &t15_2_B.Limcontr[9];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y9 += (*pD153++) * u[*pDidx++];
        }
      }

      {
        static const int_T colCidxRow10[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
          31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48
        };

        const int_T *pCidx = &colCidxRow10[0];
        const real_T *pC470 = &t15_2_P.Limcontr_C[470];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *y10 = &t15_2_B.Limcontr[10];
        int_T numNonZero = 46;
        *y10 = (*pC470++) * xd[*pCidx++];
        while (numNonZero--) {
          *y10 += (*pC470++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colDidxRow10[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pDidx = &colDidxRow10[0];
        const real_T *pD170 = &t15_2_P.Limcontr_D[170];
        const real_T *u = t15_2_B.tcont2;
        real_T *y10 = &t15_2_B.Limcontr[10];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *y10 += (*pD170++) * u[*pDidx++];
        }
      }
    }

    /* DiscreteStateSpace: '<S35>/Curr. contr.' */
    {
      {
        static const int_T colCidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = &t15_2_P.Currcontr_C[0];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *y0 = &t15_2_B.Currcontr[0];
        int_T numNonZero = 10;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colCidxRow1[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow1[0];
        const real_T *pC11 = &t15_2_P.Currcontr_C[11];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *y1 = &t15_2_B.Currcontr[1];
        int_T numNonZero = 10;
        *y1 = (*pC11++) * xd[*pCidx++];
        while (numNonZero--) {
          *y1 += (*pC11++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colCidxRow2[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow2[0];
        const real_T *pC22 = &t15_2_P.Currcontr_C[22];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *y2 = &t15_2_B.Currcontr[2];
        int_T numNonZero = 10;
        *y2 = (*pC22++) * xd[*pCidx++];
        while (numNonZero--) {
          *y2 += (*pC22++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colCidxRow3[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow3[0];
        const real_T *pC33 = &t15_2_P.Currcontr_C[33];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *y3 = &t15_2_B.Currcontr[3];
        int_T numNonZero = 10;
        *y3 = (*pC33++) * xd[*pCidx++];
        while (numNonZero--) {
          *y3 += (*pC33++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colCidxRow4[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow4[0];
        const real_T *pC44 = &t15_2_P.Currcontr_C[44];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *y4 = &t15_2_B.Currcontr[4];
        int_T numNonZero = 10;
        *y4 = (*pC44++) * xd[*pCidx++];
        while (numNonZero--) {
          *y4 += (*pC44++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colCidxRow5[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow5[0];
        const real_T *pC55 = &t15_2_P.Currcontr_C[55];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *y5 = &t15_2_B.Currcontr[5];
        int_T numNonZero = 10;
        *y5 = (*pC55++) * xd[*pCidx++];
        while (numNonZero--) {
          *y5 += (*pC55++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colCidxRow6[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow6[0];
        const real_T *pC66 = &t15_2_P.Currcontr_C[66];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *y6 = &t15_2_B.Currcontr[6];
        int_T numNonZero = 10;
        *y6 = (*pC66++) * xd[*pCidx++];
        while (numNonZero--) {
          *y6 += (*pC66++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colCidxRow7[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow7[0];
        const real_T *pC77 = &t15_2_P.Currcontr_C[77];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *y7 = &t15_2_B.Currcontr[7];
        int_T numNonZero = 10;
        *y7 = (*pC77++) * xd[*pCidx++];
        while (numNonZero--) {
          *y7 += (*pC77++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colCidxRow8[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow8[0];
        const real_T *pC88 = &t15_2_P.Currcontr_C[88];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *y8 = &t15_2_B.Currcontr[8];
        int_T numNonZero = 10;
        *y8 = (*pC88++) * xd[*pCidx++];
        while (numNonZero--) {
          *y8 += (*pC88++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colCidxRow9[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow9[0];
        const real_T *pC99 = &t15_2_P.Currcontr_C[99];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *y9 = &t15_2_B.Currcontr[9];
        int_T numNonZero = 10;
        *y9 = (*pC99++) * xd[*pCidx++];
        while (numNonZero--) {
          *y9 += (*pC99++) * xd[*pCidx++];
        }
      }

      {
        static const int_T colCidxRow10[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow10[0];
        const real_T *pC110 = &t15_2_P.Currcontr_C[110];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *y10 = &t15_2_B.Currcontr[10];
        int_T numNonZero = 10;
        *y10 = (*pC110++) * xd[*pCidx++];
        while (numNonZero--) {
          *y10 += (*pC110++) * xd[*pCidx++];
        }
      }
    }

    /* Switch: '<S2>/Ip>Ip_div ' */
    if (t15_2_B.e6 > t15_2_P.IpIp_div_Threshold) {
      memcpy((void *)(&t15_2_B.IpIp_div[0]), (void *)(&t15_2_B.Memory2_fo[0]),
             11U * sizeof(real_T));
    } else {
      /* Switch: '<S35>/tcont2' */
      if (t15_2_Y.Time > t15_2_P.tcont2_Threshold_e) {
        /* Lookup: '<S35>/gain_cont2' */
        t15_2_B.gain_cont2 = rt_Lookup((const real_T *)
          (&t15_2_P.gain_cont2_XData[0]), 4, t15_2_Y.Time, (const real_T *)
          (&t15_2_P.gain_cont2_YData[0]));
        for (i = 0; i < 11; i++) {
          /* Product: '<S35>/Divide ' */
          t15_2_B.Divide_d[i] = t15_2_B.Limcontr[i] * t15_2_B.gain_cont2;
          t15_2_B.tcont2_b[i] = t15_2_B.Divide_d[i];
        }
      } else {
        for (i = 0; i < 11; i++) {
          /* Gain: '<S35>/1//ntur ' */
          t15_2_B.ntur_d[i] = t15_2_P.ntur_Gain_p[i] * t15_2_B.Currcontr[i];
          t15_2_B.tcont2_b[i] = t15_2_B.ntur_d[i];
        }
      }

      memcpy((void *)(&t15_2_B.IpIp_div[0]), (void *)(&t15_2_B.tcont2_b[0]), 11U
             * sizeof(real_T));
    }

    /* Lookup: '<S39>/volt1' */
    t15_2_B.volt1 = rt_Lookup((const real_T *)(&t15_2_P.volt1_XData[0]), 19,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.volt1_YData[0]));

    /* Lookup: '<S39>/volt2' */
    t15_2_B.volt2 = rt_Lookup((const real_T *)(&t15_2_P.volt2_XData[0]), 19,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.volt2_YData[0]));

    /* Lookup: '<S39>/volt3' */
    t15_2_B.volt3 = rt_Lookup((const real_T *)(&t15_2_P.volt3_XData[0]), 19,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.volt3_YData[0]));

    /* Lookup: '<S39>/volt4' */
    t15_2_B.volt4 = rt_Lookup((const real_T *)(&t15_2_P.volt4_XData[0]), 19,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.volt4_YData[0]));

    /* Lookup: '<S39>/volt5' */
    t15_2_B.volt5 = rt_Lookup((const real_T *)(&t15_2_P.volt5_XData[0]), 19,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.volt5_YData[0]));

    /* Lookup: '<S39>/volt6' */
    t15_2_B.volt6 = rt_Lookup((const real_T *)(&t15_2_P.volt6_XData[0]), 19,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.volt6_YData[0]));

    /* Lookup: '<S39>/volt7' */
    t15_2_B.volt7 = rt_Lookup((const real_T *)(&t15_2_P.volt7_XData[0]), 19,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.volt7_YData[0]));

    /* Lookup: '<S39>/volt8' */
    t15_2_B.volt8 = rt_Lookup((const real_T *)(&t15_2_P.volt8_XData[0]), 19,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.volt8_YData[0]));

    /* Lookup: '<S39>/volt9' */
    t15_2_B.volt9 = rt_Lookup((const real_T *)(&t15_2_P.volt9_XData[0]), 19,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.volt9_YData[0]));

    /* Lookup: '<S39>/volt10' */
    t15_2_B.volt10 = rt_Lookup((const real_T *)(&t15_2_P.volt10_XData[0]), 19,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.volt10_YData[0]));

    /* Lookup: '<S39>/volt11' */
    t15_2_B.volt11 = rt_Lookup((const real_T *)(&t15_2_P.volt11_XData[0]), 19,
      t15_2_Y.Time, (const real_T *)(&t15_2_P.volt11_YData[0]));

    /* Product: '<S2>/Divide7' */
    t15_2_B.Divide7[0] = t15_2_B.volt1 * t15_2_B.LogicalOperator1;
    t15_2_B.Divide7[1] = t15_2_B.volt2 * t15_2_B.LogicalOperator1;
    t15_2_B.Divide7[2] = t15_2_B.volt3 * t15_2_B.LogicalOperator1;
    t15_2_B.Divide7[3] = t15_2_B.volt4 * t15_2_B.LogicalOperator1;
    t15_2_B.Divide7[4] = t15_2_B.volt5 * t15_2_B.LogicalOperator1;
    t15_2_B.Divide7[5] = t15_2_B.volt6 * t15_2_B.LogicalOperator1;
    t15_2_B.Divide7[6] = t15_2_B.volt7 * t15_2_B.LogicalOperator1;
    t15_2_B.Divide7[7] = t15_2_B.volt8 * t15_2_B.LogicalOperator1;
    t15_2_B.Divide7[8] = t15_2_B.volt9 * t15_2_B.LogicalOperator1;
    t15_2_B.Divide7[9] = t15_2_B.volt10 * t15_2_B.LogicalOperator1;
    t15_2_B.Divide7[10] = t15_2_B.volt11 * t15_2_B.LogicalOperator1;
    for (i = 0; i < 11; i++) {
      /* Product: '<S2>/Divide6' */
      t15_2_B.Divide6_iz[i] = t15_2_B.Saturation1 * t15_2_B.IpIp_div[i];

      /* Sum: '<S2>/Sum3' */
      t15_2_B.Sum3[i] = ((t15_2_B.Divide4_a[i] + t15_2_B.Divide5[i]) +
                         t15_2_B.Divide6_iz[i]) + t15_2_B.Divide7[i];

      /* Product: '<S33>/Divide2' */
      t15_2_B.Divide2_e[i] = t15_2_B.e6_l[i] * t15_2_B.Sum3[i];

      /* RelationalOperator: '<S46>/Compare' */
      t15_2_B.Compare_k[i] = (t15_2_B.Divide2_e[i] < 0.0);

      /* Logic: '<S33>/Logical Operator' */
      t15_2_B.LogicalOperator[i] = ((t15_2_B.Compare_lm[i] != 0) &&
        (t15_2_B.Compare_k[i] != 0));

      /* Sum: '<S33>/Sum3' */
      t15_2_B.Sum3_f[i] = t15_2_B.Saturation[i] + (real_T)
        t15_2_B.LogicalOperator[i];
      tmin = t15_2_B.Sum3_f[i];
      t15_2_B.Saturation1_m[i] = rt_SATURATE(tmin,
        t15_2_P.Saturation1_LowerSat_g, t15_2_P.Saturation1_UpperSat_i);

      /* Product: '<S33>/Divide6' */
      t15_2_B.Divide6_p[i] = t15_2_B.Sum3[i] * t15_2_B.Saturation1_m[i];
    }

    /* Product: '<S2>/Divide12' */
    for (i = 0; i < 20; i++) {
      t15_2_B.Divide12[i] = t15_2_B.Divide2_j[i] * t15_2_B.LogicalOperator2;
    }

    /* Sum: '<S3>/Add' incorporates:
     *  Constant: '<S3>/Tfmc'
     */
    t15_2_B.Add = t15_2_B.Diff + t15_2_P.Tfmc_Value;
    for (i = 0; i < 11; i++) {
      /* Gain: '<S35>/1//ntur' */
      t15_2_B.ntur_n[i] = t15_2_B.u9_a[i + 8] * t15_2_P.ntur_Gain_c[i];

      /* Product: '<S3>/Divide2' */
      t15_2_B.Divide2_d[i] = t15_2_B.Diff * t15_2_B.Divide6_p[i];

      /* Gain: '<S3>/Tfmc ' */
      t15_2_B.Tfmc[i] = t15_2_P.Tfmc_Gain * t15_2_B.Memory[i];

      /* Sum: '<S3>/Add1' */
      t15_2_B.Add1_e[i] = t15_2_B.Divide2_d[i] + t15_2_B.Tfmc[i];

      /* Product: '<S3>/Divide3' */
      t15_2_B.Divide3[i] = t15_2_B.Add1_e[i] / t15_2_B.Add;

      /* Update for Memory: '<S3>/Memory' */
      t15_2_DWork.Memory_PreviousInput[i] = t15_2_B.Divide3[i];
    }

    /* Update for UnitDelay: '<S61>/UD' */
    t15_2_DWork.UD_DSTATE = t15_2_Y.Time;

    /* Update for UniformRandomNumber: '<S43>/Uniform Random Number' */
    tmin = t15_2_P.UniformRandomNumber_Minimum;
    t15_2_DWork.UniformRandomNumber_NextOutput =
      (t15_2_P.UniformRandomNumber_Maximum - tmin) * rt_Urand
      (&t15_2_DWork.RandSeed) + tmin;

    /* Update for UnitDelay: '<S31>/UD' incorporates:
     *  Update for Inport: '<Root>/In1'
     */
    t15_2_DWork.UD_DSTATE_n = t15_2_U.In1[1];

    /* Update for UnitDelay: '<S32>/UD' */
    t15_2_DWork.UD_DSTATE_h = t15_2_Y.Time;

    /* Update for DiscreteStateSpace: '<S38>/VS. contr' */
    {
      static real_T xnew[9];
      xnew[0] = (t15_2_P.VScontr_A[0])*t15_2_DWork.VScontr_DSTATE[0] +
        (t15_2_P.VScontr_A[1])*t15_2_DWork.VScontr_DSTATE[1]
        + (t15_2_P.VScontr_A[2])*t15_2_DWork.VScontr_DSTATE[2]
        + (t15_2_P.VScontr_A[3])*t15_2_DWork.VScontr_DSTATE[7];
      xnew[0] += (t15_2_P.VScontr_B[0])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_B[1])*t15_2_B.tt_tran2d[1];
      xnew[1] = (t15_2_P.VScontr_A[4])*t15_2_DWork.VScontr_DSTATE[0] +
        (t15_2_P.VScontr_A[5])*t15_2_DWork.VScontr_DSTATE[1]
        + (t15_2_P.VScontr_A[6])*t15_2_DWork.VScontr_DSTATE[2]
        + (t15_2_P.VScontr_A[7])*t15_2_DWork.VScontr_DSTATE[7];
      xnew[1] += (t15_2_P.VScontr_B[2])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_B[3])*t15_2_B.tt_tran2d[1];
      xnew[2] = (t15_2_P.VScontr_A[8])*t15_2_DWork.VScontr_DSTATE[0] +
        (t15_2_P.VScontr_A[9])*t15_2_DWork.VScontr_DSTATE[1]
        + (t15_2_P.VScontr_A[10])*t15_2_DWork.VScontr_DSTATE[2]
        + (t15_2_P.VScontr_A[11])*t15_2_DWork.VScontr_DSTATE[7];
      xnew[2] += (t15_2_P.VScontr_B[4])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_B[5])*t15_2_B.tt_tran2d[1];

      {
        static const int_T colAidxRow3[5] = { 3, 4, 5, 6, 7 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA12 = &t15_2_P.VScontr_A[12];
        const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 4;
        *pxnew3 = (*pA12++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA12++) * xd[*pAidx++];
        }
      }

      xnew[3] += (t15_2_P.VScontr_B[6])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_B[7])*t15_2_B.tt_tran2d[1];

      {
        static const int_T colAidxRow4[5] = { 3, 4, 5, 6, 7 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA17 = &t15_2_P.VScontr_A[17];
        const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 4;
        *pxnew4 = (*pA17++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA17++) * xd[*pAidx++];
        }
      }

      xnew[4] += (t15_2_P.VScontr_B[8])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_B[9])*t15_2_B.tt_tran2d[1];

      {
        static const int_T colAidxRow5[5] = { 3, 4, 5, 6, 7 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA22 = &t15_2_P.VScontr_A[22];
        const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 4;
        *pxnew5 = (*pA22++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA22++) * xd[*pAidx++];
        }
      }

      xnew[5] += (t15_2_P.VScontr_B[10])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_B[11])*t15_2_B.tt_tran2d[1];

      {
        static const int_T colAidxRow6[5] = { 3, 4, 5, 6, 7 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA27 = &t15_2_P.VScontr_A[27];
        const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 4;
        *pxnew6 = (*pA27++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA27++) * xd[*pAidx++];
        }
      }

      xnew[6] += (t15_2_P.VScontr_B[12])*t15_2_B.tt_tran2d[0] +
        (t15_2_P.VScontr_B[13])*t15_2_B.tt_tran2d[1];
      xnew[7] = (t15_2_P.VScontr_A[32])*t15_2_DWork.VScontr_DSTATE[7];
      xnew[7] += (t15_2_P.VScontr_B[14])*t15_2_B.tt_tran2d[0];
      xnew[8] = (t15_2_P.VScontr_A[33])*t15_2_DWork.VScontr_DSTATE[8];
      xnew[8] += (t15_2_P.VScontr_B[15])*t15_2_B.tt_tran2d[1];
      (void) memcpy(&t15_2_DWork.VScontr_DSTATE[0],xnew,
                    sizeof(real_T)*9);
    }

    /* Update for Memory: '<S9>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput = t15_2_B.e6_e;

    /* Update for Memory: '<S9>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput = t15_2_B.Ics1_eob;

    /* Update for DiscreteStateSpace: '<S38>/VS. contr hl' */
    {
      static real_T xnew[8];
      xnew[0] = (t15_2_P.VScontrhl_A[0])*t15_2_DWork.VScontrhl_DSTATE[0] +
        (t15_2_P.VScontrhl_A[1])*t15_2_DWork.VScontrhl_DSTATE[1]
        + (t15_2_P.VScontrhl_A[2])*t15_2_DWork.VScontrhl_DSTATE[2]
        + (t15_2_P.VScontrhl_A[3])*t15_2_DWork.VScontrhl_DSTATE[7];
      xnew[0] += (t15_2_P.VScontrhl_B[0])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_B[1])*t15_2_B.Divide4[1];
      xnew[1] = (t15_2_P.VScontrhl_A[4])*t15_2_DWork.VScontrhl_DSTATE[0] +
        (t15_2_P.VScontrhl_A[5])*t15_2_DWork.VScontrhl_DSTATE[1]
        + (t15_2_P.VScontrhl_A[6])*t15_2_DWork.VScontrhl_DSTATE[2]
        + (t15_2_P.VScontrhl_A[7])*t15_2_DWork.VScontrhl_DSTATE[7];
      xnew[1] += (t15_2_P.VScontrhl_B[2])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_B[3])*t15_2_B.Divide4[1];
      xnew[2] = (t15_2_P.VScontrhl_A[8])*t15_2_DWork.VScontrhl_DSTATE[0] +
        (t15_2_P.VScontrhl_A[9])*t15_2_DWork.VScontrhl_DSTATE[1]
        + (t15_2_P.VScontrhl_A[10])*t15_2_DWork.VScontrhl_DSTATE[2]
        + (t15_2_P.VScontrhl_A[11])*t15_2_DWork.VScontrhl_DSTATE[7];
      xnew[2] += (t15_2_P.VScontrhl_B[4])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_B[5])*t15_2_B.Divide4[1];

      {
        static const int_T colAidxRow3[5] = { 3, 4, 5, 6, 7 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA12 = &t15_2_P.VScontrhl_A[12];
        const real_T *xd = &t15_2_DWork.VScontrhl_DSTATE[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 4;
        *pxnew3 = (*pA12++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA12++) * xd[*pAidx++];
        }
      }

      xnew[3] += (t15_2_P.VScontrhl_B[6])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_B[7])*t15_2_B.Divide4[1];

      {
        static const int_T colAidxRow4[5] = { 3, 4, 5, 6, 7 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA17 = &t15_2_P.VScontrhl_A[17];
        const real_T *xd = &t15_2_DWork.VScontrhl_DSTATE[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 4;
        *pxnew4 = (*pA17++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA17++) * xd[*pAidx++];
        }
      }

      xnew[4] += (t15_2_P.VScontrhl_B[8])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_B[9])*t15_2_B.Divide4[1];

      {
        static const int_T colAidxRow5[5] = { 3, 4, 5, 6, 7 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA22 = &t15_2_P.VScontrhl_A[22];
        const real_T *xd = &t15_2_DWork.VScontrhl_DSTATE[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 4;
        *pxnew5 = (*pA22++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA22++) * xd[*pAidx++];
        }
      }

      xnew[5] += (t15_2_P.VScontrhl_B[10])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_B[11])*t15_2_B.Divide4[1];

      {
        static const int_T colAidxRow6[5] = { 3, 4, 5, 6, 7 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA27 = &t15_2_P.VScontrhl_A[27];
        const real_T *xd = &t15_2_DWork.VScontrhl_DSTATE[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 4;
        *pxnew6 = (*pA27++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA27++) * xd[*pAidx++];
        }
      }

      xnew[6] += (t15_2_P.VScontrhl_B[12])*t15_2_B.Divide4[0] +
        (t15_2_P.VScontrhl_B[13])*t15_2_B.Divide4[1];
      xnew[7] = (t15_2_P.VScontrhl_A[32])*t15_2_DWork.VScontrhl_DSTATE[7];
      xnew[7] += (t15_2_P.VScontrhl_B[14])*t15_2_B.Divide4[0];
      (void) memcpy(&t15_2_DWork.VScontrhl_DSTATE[0],xnew,
                    sizeof(real_T)*8);
    }

    /* Update for Memory: '<Root>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_g = t15_2_B.IpIp_0;

    /* Update for Memory: '<S7>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_n = t15_2_B.c_eob_f;

    /* Update for Memory: '<S15>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_b = t15_2_B.c_eob_c;

    /* Update for Memory: '<S13>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_a = t15_2_B.c_eob_p;

    /* Update for Memory: '<S14>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_n = t15_2_B.c_eob_o;

    /* Update for Memory: '<S16>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_bt = t15_2_B.c_eob_k;

    /* Update for Memory: '<S12>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_c = t15_2_B.c_eob_kq;

    /* Update for Memory: '<S17>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_i = t15_2_B.c_eob_p1;

    /* Update for Memory: '<S18>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_bh = t15_2_B.c_eob_l;

    /* Update for Memory: '<S19>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_m = t15_2_B.c_eob_b;

    /* Update for Memory: '<S20>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_ns = t15_2_B.c_eob_g;

    /* Update for Memory: '<S21>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_gb = t15_2_B.c_eob_d;

    /* Update for Memory: '<S22>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_gn = t15_2_B.c_eob_fg;

    /* Update for Memory: '<S23>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_e = t15_2_B.c_eob_gq;

    /* Update for Memory: '<S24>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_h = t15_2_B.c_eob_o2;

    /* Update for Memory: '<S25>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_f = t15_2_B.c_eob_k5;

    /* Update for Memory: '<S26>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_p = t15_2_B.c_eob_i;

    /* Update for Memory: '<S27>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_i = t15_2_B.c_eob_e1;

    /* Update for Memory: '<S28>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_o = t15_2_B.c_eob1;

    /* Update for Memory: '<S28>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_c = t15_2_B.c_eob_lg;
    for (i = 0; i < 11; i++) {
      /* Update for Memory: '<S34>/Memory1' */
      t15_2_DWork.Memory1_PreviousInput_er[i] = t15_2_B.u99[i];

      /* Update for Memory: '<S36>/Memory' */
      t15_2_DWork.Memory_PreviousInput_i[i] = t15_2_B.u9_d[i];
    }

    /* Update for Memory: '<S44>/Memory3' */
    t15_2_DWork.Memory3_PreviousInput = t15_2_B.u999;

    /* Update for DiscreteStateSpace: '<S2>/Div. contr.' */
    {
      static real_T xnew[50];

      {
        static const int_T colAidxRow0[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = &t15_2_P.Divcontr_A[0];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 26;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow0[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow0[0];
        const real_T *pB0 = &t15_2_P.Divcontr_B[0];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew0 += (*pB0++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow1[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA27 = &t15_2_P.Divcontr_A[27];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 26;
        *pxnew1 = (*pA27++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA27++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow1[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow1[0];
        const real_T *pB17 = &t15_2_P.Divcontr_B[17];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew1 += (*pB17++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow2[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA54 = &t15_2_P.Divcontr_A[54];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 26;
        *pxnew2 = (*pA54++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA54++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow2[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow2[0];
        const real_T *pB34 = &t15_2_P.Divcontr_B[34];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew2 += (*pB34++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow3[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA81 = &t15_2_P.Divcontr_A[81];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 26;
        *pxnew3 = (*pA81++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA81++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow3[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow3[0];
        const real_T *pB51 = &t15_2_P.Divcontr_B[51];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew3 += (*pB51++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow4[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA108 = &t15_2_P.Divcontr_A[108];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 26;
        *pxnew4 = (*pA108++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA108++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow4[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow4[0];
        const real_T *pB68 = &t15_2_P.Divcontr_B[68];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew4 += (*pB68++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow5[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA135 = &t15_2_P.Divcontr_A[135];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 26;
        *pxnew5 = (*pA135++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA135++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow5[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow5[0];
        const real_T *pB85 = &t15_2_P.Divcontr_B[85];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew5 += (*pB85++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow6[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA162 = &t15_2_P.Divcontr_A[162];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 26;
        *pxnew6 = (*pA162++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA162++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow6[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow6[0];
        const real_T *pB102 = &t15_2_P.Divcontr_B[102];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew6 += (*pB102++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow7[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow7[0];
        const real_T *pA189 = &t15_2_P.Divcontr_A[189];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 26;
        *pxnew7 = (*pA189++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA189++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow7[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow7[0];
        const real_T *pB119 = &t15_2_P.Divcontr_B[119];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew7 += (*pB119++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow8[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow8[0];
        const real_T *pA216 = &t15_2_P.Divcontr_A[216];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 26;
        *pxnew8 = (*pA216++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew8 += (*pA216++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow8[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow8[0];
        const real_T *pB136 = &t15_2_P.Divcontr_B[136];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew8 += (*pB136++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow9[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow9[0];
        const real_T *pA243 = &t15_2_P.Divcontr_A[243];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 26;
        *pxnew9 = (*pA243++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA243++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow9[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow9[0];
        const real_T *pB153 = &t15_2_P.Divcontr_B[153];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew9 += (*pB153++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow10[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow10[0];
        const real_T *pA270 = &t15_2_P.Divcontr_A[270];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 26;
        *pxnew10 = (*pA270++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew10 += (*pA270++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow10[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow10[0];
        const real_T *pB170 = &t15_2_P.Divcontr_B[170];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew10 += (*pB170++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow11[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow11[0];
        const real_T *pA297 = &t15_2_P.Divcontr_A[297];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew11 = &xnew[11];
        int_T numNonZero = 26;
        *pxnew11 = (*pA297++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew11 += (*pA297++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow11[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow11[0];
        const real_T *pB187 = &t15_2_P.Divcontr_B[187];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew11 = &xnew[11];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew11 += (*pB187++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow12[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow12[0];
        const real_T *pA324 = &t15_2_P.Divcontr_A[324];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew12 = &xnew[12];
        int_T numNonZero = 26;
        *pxnew12 = (*pA324++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew12 += (*pA324++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow12[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow12[0];
        const real_T *pB204 = &t15_2_P.Divcontr_B[204];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew12 = &xnew[12];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew12 += (*pB204++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow13[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow13[0];
        const real_T *pA351 = &t15_2_P.Divcontr_A[351];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew13 = &xnew[13];
        int_T numNonZero = 26;
        *pxnew13 = (*pA351++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew13 += (*pA351++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow13[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow13[0];
        const real_T *pB221 = &t15_2_P.Divcontr_B[221];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew13 = &xnew[13];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew13 += (*pB221++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow14[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow14[0];
        const real_T *pA378 = &t15_2_P.Divcontr_A[378];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew14 = &xnew[14];
        int_T numNonZero = 26;
        *pxnew14 = (*pA378++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew14 += (*pA378++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow14[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow14[0];
        const real_T *pB238 = &t15_2_P.Divcontr_B[238];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew14 = &xnew[14];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew14 += (*pB238++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow15[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow15[0];
        const real_T *pA405 = &t15_2_P.Divcontr_A[405];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew15 = &xnew[15];
        int_T numNonZero = 26;
        *pxnew15 = (*pA405++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew15 += (*pA405++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow15[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow15[0];
        const real_T *pB255 = &t15_2_P.Divcontr_B[255];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew15 = &xnew[15];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew15 += (*pB255++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow16[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow16[0];
        const real_T *pA432 = &t15_2_P.Divcontr_A[432];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew16 = &xnew[16];
        int_T numNonZero = 26;
        *pxnew16 = (*pA432++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew16 += (*pA432++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow16[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow16[0];
        const real_T *pB272 = &t15_2_P.Divcontr_B[272];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew16 = &xnew[16];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew16 += (*pB272++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow17[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow17[0];
        const real_T *pA459 = &t15_2_P.Divcontr_A[459];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew17 = &xnew[17];
        int_T numNonZero = 26;
        *pxnew17 = (*pA459++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew17 += (*pA459++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow17[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow17[0];
        const real_T *pB289 = &t15_2_P.Divcontr_B[289];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew17 = &xnew[17];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew17 += (*pB289++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow18[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow18[0];
        const real_T *pA486 = &t15_2_P.Divcontr_A[486];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew18 = &xnew[18];
        int_T numNonZero = 26;
        *pxnew18 = (*pA486++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew18 += (*pA486++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow18[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow18[0];
        const real_T *pB306 = &t15_2_P.Divcontr_B[306];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew18 = &xnew[18];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew18 += (*pB306++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow19[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

        const int_T *pAidx = &colAidxRow19[0];
        const real_T *pA513 = &t15_2_P.Divcontr_A[513];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew19 = &xnew[19];
        int_T numNonZero = 26;
        *pxnew19 = (*pA513++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew19 += (*pA513++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow19[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow19[0];
        const real_T *pB323 = &t15_2_P.Divcontr_B[323];
        const real_T *u = t15_2_B.Divide2_j;
        real_T *pxnew19 = &xnew[19];
        int_T numNonZero = 17;
        while (numNonZero--) {
          *pxnew19 += (*pB323++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow20[5] = { 20, 21, 22, 23, 24 };

        const int_T *pAidx = &colAidxRow20[0];
        const real_T *pA540 = &t15_2_P.Divcontr_A[540];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew20 = &xnew[20];
        int_T numNonZero = 4;
        *pxnew20 = (*pA540++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew20 += (*pA540++) * xd[*pAidx++];
        }
      }

      xnew[20] += (t15_2_P.Divcontr_B[340])*t15_2_B.Divide2_j[12];

      {
        static const int_T colAidxRow21[5] = { 20, 21, 22, 23, 24 };

        const int_T *pAidx = &colAidxRow21[0];
        const real_T *pA545 = &t15_2_P.Divcontr_A[545];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew21 = &xnew[21];
        int_T numNonZero = 4;
        *pxnew21 = (*pA545++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew21 += (*pA545++) * xd[*pAidx++];
        }
      }

      xnew[21] += (t15_2_P.Divcontr_B[341])*t15_2_B.Divide2_j[12];

      {
        static const int_T colAidxRow22[5] = { 20, 21, 22, 23, 24 };

        const int_T *pAidx = &colAidxRow22[0];
        const real_T *pA550 = &t15_2_P.Divcontr_A[550];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew22 = &xnew[22];
        int_T numNonZero = 4;
        *pxnew22 = (*pA550++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew22 += (*pA550++) * xd[*pAidx++];
        }
      }

      xnew[22] += (t15_2_P.Divcontr_B[342])*t15_2_B.Divide2_j[12];

      {
        static const int_T colAidxRow23[5] = { 20, 21, 22, 23, 24 };

        const int_T *pAidx = &colAidxRow23[0];
        const real_T *pA555 = &t15_2_P.Divcontr_A[555];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew23 = &xnew[23];
        int_T numNonZero = 4;
        *pxnew23 = (*pA555++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew23 += (*pA555++) * xd[*pAidx++];
        }
      }

      xnew[23] += (t15_2_P.Divcontr_B[343])*t15_2_B.Divide2_j[12];

      {
        static const int_T colAidxRow24[5] = { 20, 21, 22, 23, 24 };

        const int_T *pAidx = &colAidxRow24[0];
        const real_T *pA560 = &t15_2_P.Divcontr_A[560];
        const real_T *xd = &t15_2_DWork.Divcontr_DSTATE[0];
        real_T *pxnew24 = &xnew[24];
        int_T numNonZero = 4;
        *pxnew24 = (*pA560++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew24 += (*pA560++) * xd[*pAidx++];
        }
      }

      xnew[24] += (t15_2_P.Divcontr_B[344])*t15_2_B.Divide2_j[12];
      xnew[25] = (t15_2_P.Divcontr_A[565])*t15_2_DWork.Divcontr_DSTATE[25];
      xnew[25] += (t15_2_P.Divcontr_B[345])*t15_2_B.Divide2_j[0];
      xnew[26] = (t15_2_P.Divcontr_A[566])*t15_2_DWork.Divcontr_DSTATE[26];
      xnew[26] += (t15_2_P.Divcontr_B[346])*t15_2_B.Divide2_j[1];
      xnew[27] = (t15_2_P.Divcontr_A[567])*t15_2_DWork.Divcontr_DSTATE[27];
      xnew[27] += (t15_2_P.Divcontr_B[347])*t15_2_B.Divide2_j[2];
      xnew[28] = (t15_2_P.Divcontr_A[568])*t15_2_DWork.Divcontr_DSTATE[28];
      xnew[28] += (t15_2_P.Divcontr_B[348])*t15_2_B.Divide2_j[3];
      xnew[29] = (t15_2_P.Divcontr_A[569])*t15_2_DWork.Divcontr_DSTATE[29];
      xnew[29] += (t15_2_P.Divcontr_B[349])*t15_2_B.Divide2_j[4];
      xnew[30] = (t15_2_P.Divcontr_A[570])*t15_2_DWork.Divcontr_DSTATE[30];
      xnew[30] += (t15_2_P.Divcontr_B[350])*t15_2_B.Divide2_j[5];
      xnew[31] = (t15_2_P.Divcontr_A[571])*t15_2_DWork.Divcontr_DSTATE[31];
      xnew[31] += (t15_2_P.Divcontr_B[351])*t15_2_B.Divide2_j[7];
      xnew[32] = 0.0;
      xnew[33] = 0.0;
      xnew[34] = 0.0;
      xnew[35] = 0.0;
      xnew[36] = 0.0;
      xnew[37] = 0.0;
      xnew[38] = 0.0;
      xnew[39] = 0.0;
      xnew[40] = 0.0;
      xnew[41] = 0.0;
      xnew[42] = 0.0;
      xnew[43] = 0.0;
      xnew[44] = 0.0;
      xnew[45] = 0.0;
      xnew[46] = 0.0;
      xnew[47] = 0.0;
      xnew[48] = 0.0;
      xnew[49] = 0.0;
      (void) memcpy(&t15_2_DWork.Divcontr_DSTATE[0],xnew,
                    sizeof(real_T)*50);
    }

    /* Update for Memory: '<S42>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_a = t15_2_B.u999_b;

    /* Update for DiscreteStateSpace: '<S2>/Div_rd contr' */
    {
      static real_T xnew[40];

      {
        static const int_T colAidxRow0[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = &t15_2_P.Div_rdcontr_A[0];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 21;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow0[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow0[0];
        const real_T *pB0 = &t15_2_P.Div_rdcontr_B[0];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew0 += (*pB0++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow1[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA22 = &t15_2_P.Div_rdcontr_A[22];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 21;
        *pxnew1 = (*pA22++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA22++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow1[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow1[0];
        const real_T *pB18 = &t15_2_P.Div_rdcontr_B[18];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew1 += (*pB18++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow2[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA44 = &t15_2_P.Div_rdcontr_A[44];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 21;
        *pxnew2 = (*pA44++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA44++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow2[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow2[0];
        const real_T *pB36 = &t15_2_P.Div_rdcontr_B[36];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew2 += (*pB36++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow3[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA66 = &t15_2_P.Div_rdcontr_A[66];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 21;
        *pxnew3 = (*pA66++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA66++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow3[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow3[0];
        const real_T *pB54 = &t15_2_P.Div_rdcontr_B[54];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew3 += (*pB54++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow4[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA88 = &t15_2_P.Div_rdcontr_A[88];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 21;
        *pxnew4 = (*pA88++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA88++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow4[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow4[0];
        const real_T *pB72 = &t15_2_P.Div_rdcontr_B[72];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew4 += (*pB72++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow5[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA110 = &t15_2_P.Div_rdcontr_A[110];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 21;
        *pxnew5 = (*pA110++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA110++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow5[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow5[0];
        const real_T *pB90 = &t15_2_P.Div_rdcontr_B[90];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew5 += (*pB90++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow6[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA132 = &t15_2_P.Div_rdcontr_A[132];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 21;
        *pxnew6 = (*pA132++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA132++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow6[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow6[0];
        const real_T *pB108 = &t15_2_P.Div_rdcontr_B[108];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew6 += (*pB108++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow7[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow7[0];
        const real_T *pA154 = &t15_2_P.Div_rdcontr_A[154];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 21;
        *pxnew7 = (*pA154++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA154++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow7[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow7[0];
        const real_T *pB126 = &t15_2_P.Div_rdcontr_B[126];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew7 += (*pB126++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow8[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow8[0];
        const real_T *pA176 = &t15_2_P.Div_rdcontr_A[176];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 21;
        *pxnew8 = (*pA176++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew8 += (*pA176++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow8[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow8[0];
        const real_T *pB144 = &t15_2_P.Div_rdcontr_B[144];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew8 += (*pB144++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow9[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow9[0];
        const real_T *pA198 = &t15_2_P.Div_rdcontr_A[198];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 21;
        *pxnew9 = (*pA198++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA198++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow9[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
          12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow9[0];
        const real_T *pB162 = &t15_2_P.Div_rdcontr_B[162];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew9 += (*pB162++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow10[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow10[0];
        const real_T *pA220 = &t15_2_P.Div_rdcontr_A[220];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 21;
        *pxnew10 = (*pA220++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew10 += (*pA220++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow10[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow10[0];
        const real_T *pB180 = &t15_2_P.Div_rdcontr_B[180];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew10 += (*pB180++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow11[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow11[0];
        const real_T *pA242 = &t15_2_P.Div_rdcontr_A[242];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew11 = &xnew[11];
        int_T numNonZero = 21;
        *pxnew11 = (*pA242++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew11 += (*pA242++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow11[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow11[0];
        const real_T *pB198 = &t15_2_P.Div_rdcontr_B[198];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew11 = &xnew[11];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew11 += (*pB198++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow12[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow12[0];
        const real_T *pA264 = &t15_2_P.Div_rdcontr_A[264];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew12 = &xnew[12];
        int_T numNonZero = 21;
        *pxnew12 = (*pA264++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew12 += (*pA264++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow12[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow12[0];
        const real_T *pB216 = &t15_2_P.Div_rdcontr_B[216];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew12 = &xnew[12];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew12 += (*pB216++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow13[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow13[0];
        const real_T *pA286 = &t15_2_P.Div_rdcontr_A[286];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew13 = &xnew[13];
        int_T numNonZero = 21;
        *pxnew13 = (*pA286++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew13 += (*pA286++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow13[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow13[0];
        const real_T *pB234 = &t15_2_P.Div_rdcontr_B[234];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew13 = &xnew[13];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew13 += (*pB234++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow14[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow14[0];
        const real_T *pA308 = &t15_2_P.Div_rdcontr_A[308];
        const real_T *xd = &t15_2_DWork.Div_rdcontr_DSTATE[0];
        real_T *pxnew14 = &xnew[14];
        int_T numNonZero = 21;
        *pxnew14 = (*pA308++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew14 += (*pA308++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow14[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow14[0];
        const real_T *pB252 = &t15_2_P.Div_rdcontr_B[252];
        const real_T *u = t15_2_B.Divide13;
        real_T *pxnew14 = &xnew[14];
        int_T numNonZero = 18;
        while (numNonZero--) {
          *pxnew14 += (*pB252++) * u[*pBidx++];
        }
      }

      xnew[15] = (t15_2_P.Div_rdcontr_A[330])*t15_2_DWork.Div_rdcontr_DSTATE[15];
      xnew[15] += (t15_2_P.Div_rdcontr_B[270])*t15_2_B.Divide13[0];
      xnew[16] = (t15_2_P.Div_rdcontr_A[331])*t15_2_DWork.Div_rdcontr_DSTATE[16];
      xnew[16] += (t15_2_P.Div_rdcontr_B[271])*t15_2_B.Divide13[1];
      xnew[17] = (t15_2_P.Div_rdcontr_A[332])*t15_2_DWork.Div_rdcontr_DSTATE[17];
      xnew[17] += (t15_2_P.Div_rdcontr_B[272])*t15_2_B.Divide13[2];
      xnew[18] = (t15_2_P.Div_rdcontr_A[333])*t15_2_DWork.Div_rdcontr_DSTATE[18];
      xnew[18] += (t15_2_P.Div_rdcontr_B[273])*t15_2_B.Divide13[3];
      xnew[19] = (t15_2_P.Div_rdcontr_A[334])*t15_2_DWork.Div_rdcontr_DSTATE[19];
      xnew[19] += (t15_2_P.Div_rdcontr_B[274])*t15_2_B.Divide13[4];
      xnew[20] = (t15_2_P.Div_rdcontr_A[335])*t15_2_DWork.Div_rdcontr_DSTATE[20];
      xnew[20] += (t15_2_P.Div_rdcontr_B[275])*t15_2_B.Divide13[5];
      xnew[21] = (t15_2_P.Div_rdcontr_A[336])*t15_2_DWork.Div_rdcontr_DSTATE[21];
      xnew[21] += (t15_2_P.Div_rdcontr_B[276])*t15_2_B.Divide13[7];
      xnew[22] = 0.0;
      xnew[23] = 0.0;
      xnew[24] = 0.0;
      xnew[25] = 0.0;
      xnew[26] = 0.0;
      xnew[27] = 0.0;
      xnew[28] = 0.0;
      xnew[29] = 0.0;
      xnew[30] = 0.0;
      xnew[31] = 0.0;
      xnew[32] = 0.0;
      xnew[33] = 0.0;
      xnew[34] = 0.0;
      xnew[35] = 0.0;
      xnew[36] = 0.0;
      xnew[37] = 0.0;
      xnew[38] = 0.0;
      xnew[39] = 0.0;
      (void) memcpy(&t15_2_DWork.Div_rdcontr_DSTATE[0],xnew,
                    sizeof(real_T)*40);
    }

    /* Update for Memory: '<S40>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_ek = t15_2_B.c_eob_fp;

    /* Update for Memory: '<S41>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_j = t15_2_B.u999_l;

    /* Update for DiscreteStateSpace: '<S2>/Curr. term. contr' */
    {
      static real_T xnew[40];

      {
        static const int_T colAidxRow0[12] = { 0, 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = &t15_2_P.Currtermcontr_A[0];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 11;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colAidxRow1[12] = { 1, 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA12 = &t15_2_P.Currtermcontr_A[12];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 11;
        *pxnew1 = (*pA12++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA12++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colAidxRow2[12] = { 2, 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA24 = &t15_2_P.Currtermcontr_A[24];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 11;
        *pxnew2 = (*pA24++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA24++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colAidxRow3[12] = { 3, 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA36 = &t15_2_P.Currtermcontr_A[36];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 11;
        *pxnew3 = (*pA36++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA36++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colAidxRow4[12] = { 4, 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA48 = &t15_2_P.Currtermcontr_A[48];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 11;
        *pxnew4 = (*pA48++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA48++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colAidxRow5[12] = { 5, 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA60 = &t15_2_P.Currtermcontr_A[60];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 11;
        *pxnew5 = (*pA60++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA60++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colAidxRow6[12] = { 6, 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA72 = &t15_2_P.Currtermcontr_A[72];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 11;
        *pxnew6 = (*pA72++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA72++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colAidxRow7[12] = { 7, 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow7[0];
        const real_T *pA84 = &t15_2_P.Currtermcontr_A[84];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 11;
        *pxnew7 = (*pA84++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA84++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colAidxRow8[12] = { 8, 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow8[0];
        const real_T *pA96 = &t15_2_P.Currtermcontr_A[96];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 11;
        *pxnew8 = (*pA96++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew8 += (*pA96++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colAidxRow9[12] = { 9, 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow9[0];
        const real_T *pA108 = &t15_2_P.Currtermcontr_A[108];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 11;
        *pxnew9 = (*pA108++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA108++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colAidxRow10[12] = { 10, 11, 12, 13, 14, 15, 16, 17,
          18, 19, 20, 21 };

        const int_T *pAidx = &colAidxRow10[0];
        const real_T *pA120 = &t15_2_P.Currtermcontr_A[120];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 11;
        *pxnew10 = (*pA120++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew10 += (*pA120++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colAidxRow11[11] = { 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow11[0];
        const real_T *pA132 = &t15_2_P.Currtermcontr_A[132];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew11 = &xnew[11];
        int_T numNonZero = 10;
        *pxnew11 = (*pA132++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew11 += (*pA132++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow11[11] = { 8, 9, 10, 11, 12, 13, 14, 15, 16,
          17, 18 };

        const int_T *pBidx = &colBidxRow11[0];
        const real_T *pB0 = &t15_2_P.Currtermcontr_B[0];
        const real_T *u = t15_2_B.Divide12;
        real_T *pxnew11 = &xnew[11];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew11 += (*pB0++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow12[11] = { 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow12[0];
        const real_T *pA143 = &t15_2_P.Currtermcontr_A[143];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew12 = &xnew[12];
        int_T numNonZero = 10;
        *pxnew12 = (*pA143++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew12 += (*pA143++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow12[11] = { 8, 9, 10, 11, 12, 13, 14, 15, 16,
          17, 18 };

        const int_T *pBidx = &colBidxRow12[0];
        const real_T *pB11 = &t15_2_P.Currtermcontr_B[11];
        const real_T *u = t15_2_B.Divide12;
        real_T *pxnew12 = &xnew[12];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew12 += (*pB11++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow13[11] = { 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow13[0];
        const real_T *pA154 = &t15_2_P.Currtermcontr_A[154];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew13 = &xnew[13];
        int_T numNonZero = 10;
        *pxnew13 = (*pA154++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew13 += (*pA154++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow13[11] = { 8, 9, 10, 11, 12, 13, 14, 15, 16,
          17, 18 };

        const int_T *pBidx = &colBidxRow13[0];
        const real_T *pB22 = &t15_2_P.Currtermcontr_B[22];
        const real_T *u = t15_2_B.Divide12;
        real_T *pxnew13 = &xnew[13];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew13 += (*pB22++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow14[11] = { 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow14[0];
        const real_T *pA165 = &t15_2_P.Currtermcontr_A[165];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew14 = &xnew[14];
        int_T numNonZero = 10;
        *pxnew14 = (*pA165++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew14 += (*pA165++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow14[11] = { 8, 9, 10, 11, 12, 13, 14, 15, 16,
          17, 18 };

        const int_T *pBidx = &colBidxRow14[0];
        const real_T *pB33 = &t15_2_P.Currtermcontr_B[33];
        const real_T *u = t15_2_B.Divide12;
        real_T *pxnew14 = &xnew[14];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew14 += (*pB33++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow15[11] = { 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow15[0];
        const real_T *pA176 = &t15_2_P.Currtermcontr_A[176];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew15 = &xnew[15];
        int_T numNonZero = 10;
        *pxnew15 = (*pA176++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew15 += (*pA176++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow15[11] = { 8, 9, 10, 11, 12, 13, 14, 15, 16,
          17, 18 };

        const int_T *pBidx = &colBidxRow15[0];
        const real_T *pB44 = &t15_2_P.Currtermcontr_B[44];
        const real_T *u = t15_2_B.Divide12;
        real_T *pxnew15 = &xnew[15];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew15 += (*pB44++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow16[11] = { 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow16[0];
        const real_T *pA187 = &t15_2_P.Currtermcontr_A[187];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew16 = &xnew[16];
        int_T numNonZero = 10;
        *pxnew16 = (*pA187++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew16 += (*pA187++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow16[11] = { 8, 9, 10, 11, 12, 13, 14, 15, 16,
          17, 18 };

        const int_T *pBidx = &colBidxRow16[0];
        const real_T *pB55 = &t15_2_P.Currtermcontr_B[55];
        const real_T *u = t15_2_B.Divide12;
        real_T *pxnew16 = &xnew[16];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew16 += (*pB55++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow17[11] = { 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow17[0];
        const real_T *pA198 = &t15_2_P.Currtermcontr_A[198];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew17 = &xnew[17];
        int_T numNonZero = 10;
        *pxnew17 = (*pA198++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew17 += (*pA198++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow17[11] = { 8, 9, 10, 11, 12, 13, 14, 15, 16,
          17, 18 };

        const int_T *pBidx = &colBidxRow17[0];
        const real_T *pB66 = &t15_2_P.Currtermcontr_B[66];
        const real_T *u = t15_2_B.Divide12;
        real_T *pxnew17 = &xnew[17];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew17 += (*pB66++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow18[11] = { 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow18[0];
        const real_T *pA209 = &t15_2_P.Currtermcontr_A[209];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew18 = &xnew[18];
        int_T numNonZero = 10;
        *pxnew18 = (*pA209++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew18 += (*pA209++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow18[11] = { 8, 9, 10, 11, 12, 13, 14, 15, 16,
          17, 18 };

        const int_T *pBidx = &colBidxRow18[0];
        const real_T *pB77 = &t15_2_P.Currtermcontr_B[77];
        const real_T *u = t15_2_B.Divide12;
        real_T *pxnew18 = &xnew[18];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew18 += (*pB77++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow19[11] = { 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow19[0];
        const real_T *pA220 = &t15_2_P.Currtermcontr_A[220];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew19 = &xnew[19];
        int_T numNonZero = 10;
        *pxnew19 = (*pA220++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew19 += (*pA220++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow19[11] = { 8, 9, 10, 11, 12, 13, 14, 15, 16,
          17, 18 };

        const int_T *pBidx = &colBidxRow19[0];
        const real_T *pB88 = &t15_2_P.Currtermcontr_B[88];
        const real_T *u = t15_2_B.Divide12;
        real_T *pxnew19 = &xnew[19];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew19 += (*pB88++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow20[11] = { 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow20[0];
        const real_T *pA231 = &t15_2_P.Currtermcontr_A[231];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew20 = &xnew[20];
        int_T numNonZero = 10;
        *pxnew20 = (*pA231++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew20 += (*pA231++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow20[11] = { 8, 9, 10, 11, 12, 13, 14, 15, 16,
          17, 18 };

        const int_T *pBidx = &colBidxRow20[0];
        const real_T *pB99 = &t15_2_P.Currtermcontr_B[99];
        const real_T *u = t15_2_B.Divide12;
        real_T *pxnew20 = &xnew[20];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew20 += (*pB99++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow21[11] = { 11, 12, 13, 14, 15, 16, 17, 18,
          19, 20, 21 };

        const int_T *pAidx = &colAidxRow21[0];
        const real_T *pA242 = &t15_2_P.Currtermcontr_A[242];
        const real_T *xd = &t15_2_DWork.Currtermcontr_DSTATE[0];
        real_T *pxnew21 = &xnew[21];
        int_T numNonZero = 10;
        *pxnew21 = (*pA242++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew21 += (*pA242++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow21[11] = { 8, 9, 10, 11, 12, 13, 14, 15, 16,
          17, 18 };

        const int_T *pBidx = &colBidxRow21[0];
        const real_T *pB110 = &t15_2_P.Currtermcontr_B[110];
        const real_T *u = t15_2_B.Divide12;
        real_T *pxnew21 = &xnew[21];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew21 += (*pB110++) * u[*pBidx++];
        }
      }

      xnew[22] = 0.0;
      xnew[23] = 0.0;
      xnew[24] = 0.0;
      xnew[25] = 0.0;
      xnew[26] = 0.0;
      xnew[27] = 0.0;
      xnew[28] = 0.0;
      xnew[29] = 0.0;
      xnew[30] = 0.0;
      xnew[31] = 0.0;
      xnew[32] = 0.0;
      xnew[33] = 0.0;
      xnew[34] = 0.0;
      xnew[35] = 0.0;
      xnew[36] = 0.0;
      xnew[37] = 0.0;
      xnew[38] = 0.0;
      xnew[39] = 0.0;
      (void) memcpy(&t15_2_DWork.Currtermcontr_DSTATE[0],xnew,
                    sizeof(real_T)*40);
    }

    /* Update for Memory: '<S2>/Memory2' */
    memcpy((void *)(&t15_2_DWork.Memory2_PreviousInput_j[0]), (void *)
           (&t15_2_B.IpIp_div[0]), 11U * sizeof(real_T));

    /* Update for DiscreteStateSpace: '<S35>/Lim. contr.' */
    {
      static real_T xnew[50];

      {
        static const int_T colAidxRow0[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = &t15_2_P.Limcontr_A[0];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 24;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow0[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow0[0];
        const real_T *pB0 = &t15_2_P.Limcontr_B[0];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew0 += (*pB0++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow1[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA25 = &t15_2_P.Limcontr_A[25];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 24;
        *pxnew1 = (*pA25++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA25++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow1[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow1[0];
        const real_T *pB16 = &t15_2_P.Limcontr_B[16];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew1 += (*pB16++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow2[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA50 = &t15_2_P.Limcontr_A[50];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 24;
        *pxnew2 = (*pA50++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA50++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow2[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow2[0];
        const real_T *pB32 = &t15_2_P.Limcontr_B[32];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew2 += (*pB32++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow3[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA75 = &t15_2_P.Limcontr_A[75];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 24;
        *pxnew3 = (*pA75++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA75++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow3[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow3[0];
        const real_T *pB48 = &t15_2_P.Limcontr_B[48];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew3 += (*pB48++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow4[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA100 = &t15_2_P.Limcontr_A[100];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 24;
        *pxnew4 = (*pA100++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA100++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow4[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow4[0];
        const real_T *pB64 = &t15_2_P.Limcontr_B[64];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew4 += (*pB64++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow5[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA125 = &t15_2_P.Limcontr_A[125];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 24;
        *pxnew5 = (*pA125++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA125++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow5[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow5[0];
        const real_T *pB80 = &t15_2_P.Limcontr_B[80];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew5 += (*pB80++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow6[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA150 = &t15_2_P.Limcontr_A[150];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 24;
        *pxnew6 = (*pA150++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA150++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow6[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow6[0];
        const real_T *pB96 = &t15_2_P.Limcontr_B[96];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew6 += (*pB96++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow7[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow7[0];
        const real_T *pA175 = &t15_2_P.Limcontr_A[175];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 24;
        *pxnew7 = (*pA175++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA175++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow7[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow7[0];
        const real_T *pB112 = &t15_2_P.Limcontr_B[112];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew7 += (*pB112++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow8[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow8[0];
        const real_T *pA200 = &t15_2_P.Limcontr_A[200];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 24;
        *pxnew8 = (*pA200++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew8 += (*pA200++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow8[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow8[0];
        const real_T *pB128 = &t15_2_P.Limcontr_B[128];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew8 += (*pB128++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow9[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow9[0];
        const real_T *pA225 = &t15_2_P.Limcontr_A[225];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 24;
        *pxnew9 = (*pA225++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA225++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow9[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow9[0];
        const real_T *pB144 = &t15_2_P.Limcontr_B[144];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew9 += (*pB144++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow10[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow10[0];
        const real_T *pA250 = &t15_2_P.Limcontr_A[250];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 24;
        *pxnew10 = (*pA250++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew10 += (*pA250++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow10[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow10[0];
        const real_T *pB160 = &t15_2_P.Limcontr_B[160];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew10 += (*pB160++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow11[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow11[0];
        const real_T *pA275 = &t15_2_P.Limcontr_A[275];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew11 = &xnew[11];
        int_T numNonZero = 24;
        *pxnew11 = (*pA275++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew11 += (*pA275++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow11[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow11[0];
        const real_T *pB176 = &t15_2_P.Limcontr_B[176];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew11 = &xnew[11];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew11 += (*pB176++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow12[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow12[0];
        const real_T *pA300 = &t15_2_P.Limcontr_A[300];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew12 = &xnew[12];
        int_T numNonZero = 24;
        *pxnew12 = (*pA300++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew12 += (*pA300++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow12[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow12[0];
        const real_T *pB192 = &t15_2_P.Limcontr_B[192];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew12 = &xnew[12];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew12 += (*pB192++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow13[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow13[0];
        const real_T *pA325 = &t15_2_P.Limcontr_A[325];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew13 = &xnew[13];
        int_T numNonZero = 24;
        *pxnew13 = (*pA325++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew13 += (*pA325++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow13[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow13[0];
        const real_T *pB208 = &t15_2_P.Limcontr_B[208];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew13 = &xnew[13];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew13 += (*pB208++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow14[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow14[0];
        const real_T *pA350 = &t15_2_P.Limcontr_A[350];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew14 = &xnew[14];
        int_T numNonZero = 24;
        *pxnew14 = (*pA350++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew14 += (*pA350++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow14[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow14[0];
        const real_T *pB224 = &t15_2_P.Limcontr_B[224];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew14 = &xnew[14];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew14 += (*pB224++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow15[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow15[0];
        const real_T *pA375 = &t15_2_P.Limcontr_A[375];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew15 = &xnew[15];
        int_T numNonZero = 24;
        *pxnew15 = (*pA375++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew15 += (*pA375++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow15[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow15[0];
        const real_T *pB240 = &t15_2_P.Limcontr_B[240];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew15 = &xnew[15];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew15 += (*pB240++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow16[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow16[0];
        const real_T *pA400 = &t15_2_P.Limcontr_A[400];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew16 = &xnew[16];
        int_T numNonZero = 24;
        *pxnew16 = (*pA400++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew16 += (*pA400++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow16[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow16[0];
        const real_T *pB256 = &t15_2_P.Limcontr_B[256];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew16 = &xnew[16];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew16 += (*pB256++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow17[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow17[0];
        const real_T *pA425 = &t15_2_P.Limcontr_A[425];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew17 = &xnew[17];
        int_T numNonZero = 24;
        *pxnew17 = (*pA425++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew17 += (*pA425++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow17[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow17[0];
        const real_T *pB272 = &t15_2_P.Limcontr_B[272];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew17 = &xnew[17];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew17 += (*pB272++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow18[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow18[0];
        const real_T *pA450 = &t15_2_P.Limcontr_A[450];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew18 = &xnew[18];
        int_T numNonZero = 24;
        *pxnew18 = (*pA450++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew18 += (*pA450++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow18[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow18[0];
        const real_T *pB288 = &t15_2_P.Limcontr_B[288];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew18 = &xnew[18];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew18 += (*pB288++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow19[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow19[0];
        const real_T *pA475 = &t15_2_P.Limcontr_A[475];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew19 = &xnew[19];
        int_T numNonZero = 24;
        *pxnew19 = (*pA475++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew19 += (*pA475++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow19[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow19[0];
        const real_T *pB304 = &t15_2_P.Limcontr_B[304];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew19 = &xnew[19];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew19 += (*pB304++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow20[6] = { 20, 21, 23, 24, 25, 27 };

        const int_T *pAidx = &colAidxRow20[0];
        const real_T *pA500 = &t15_2_P.Limcontr_A[500];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew20 = &xnew[20];
        int_T numNonZero = 5;
        *pxnew20 = (*pA500++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew20 += (*pA500++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow20[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12,
          13, 14, 15, 16, 17, 18 };

        const int_T *pBidx = &colBidxRow20[0];
        const real_T *pB320 = &t15_2_P.Limcontr_B[320];
        const real_T *u = t15_2_B.tcont2;
        real_T *pxnew20 = &xnew[20];
        int_T numNonZero = 16;
        while (numNonZero--) {
          *pxnew20 += (*pB320++) * u[*pBidx++];
        }
      }

      xnew[21] = (t15_2_P.Limcontr_A[506])*t15_2_DWork.Limcontr_DSTATE[21];
      xnew[21] += (t15_2_P.Limcontr_B[336])*t15_2_B.tcont2[0];
      xnew[22] = (t15_2_P.Limcontr_A[507])*t15_2_DWork.Limcontr_DSTATE[22];
      xnew[22] += (t15_2_P.Limcontr_B[337])*t15_2_B.tcont2[1];
      xnew[23] = (t15_2_P.Limcontr_A[508])*t15_2_DWork.Limcontr_DSTATE[23];
      xnew[23] += (t15_2_P.Limcontr_B[338])*t15_2_B.tcont2[2];
      xnew[24] = (t15_2_P.Limcontr_A[509])*t15_2_DWork.Limcontr_DSTATE[24];
      xnew[24] += (t15_2_P.Limcontr_B[339])*t15_2_B.tcont2[3];
      xnew[25] = (t15_2_P.Limcontr_A[510])*t15_2_DWork.Limcontr_DSTATE[25];
      xnew[25] += (t15_2_P.Limcontr_B[340])*t15_2_B.tcont2[4];
      xnew[26] = (t15_2_P.Limcontr_A[511])*t15_2_DWork.Limcontr_DSTATE[26];
      xnew[26] += (t15_2_P.Limcontr_B[341])*t15_2_B.tcont2[5];
      xnew[27] = (t15_2_P.Limcontr_A[512])*t15_2_DWork.Limcontr_DSTATE[27];
      xnew[27] += (t15_2_P.Limcontr_B[342])*t15_2_B.tcont2[7];

      {
        static const int_T colAidxRow28[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow28[0];
        const real_T *pA513 = &t15_2_P.Limcontr_A[513];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew28 = &xnew[28];
        int_T numNonZero = 19;
        *pxnew28 = (*pA513++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew28 += (*pA513++) * xd[*pAidx++];
        }
      }

      xnew[28] += (t15_2_P.Limcontr_B[343])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow29[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow29[0];
        const real_T *pA533 = &t15_2_P.Limcontr_A[533];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew29 = &xnew[29];
        int_T numNonZero = 19;
        *pxnew29 = (*pA533++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew29 += (*pA533++) * xd[*pAidx++];
        }
      }

      xnew[29] += (t15_2_P.Limcontr_B[344])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow30[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow30[0];
        const real_T *pA553 = &t15_2_P.Limcontr_A[553];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew30 = &xnew[30];
        int_T numNonZero = 19;
        *pxnew30 = (*pA553++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew30 += (*pA553++) * xd[*pAidx++];
        }
      }

      xnew[30] += (t15_2_P.Limcontr_B[345])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow31[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow31[0];
        const real_T *pA573 = &t15_2_P.Limcontr_A[573];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew31 = &xnew[31];
        int_T numNonZero = 19;
        *pxnew31 = (*pA573++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew31 += (*pA573++) * xd[*pAidx++];
        }
      }

      xnew[31] += (t15_2_P.Limcontr_B[346])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow32[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow32[0];
        const real_T *pA593 = &t15_2_P.Limcontr_A[593];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew32 = &xnew[32];
        int_T numNonZero = 19;
        *pxnew32 = (*pA593++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew32 += (*pA593++) * xd[*pAidx++];
        }
      }

      xnew[32] += (t15_2_P.Limcontr_B[347])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow33[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow33[0];
        const real_T *pA613 = &t15_2_P.Limcontr_A[613];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew33 = &xnew[33];
        int_T numNonZero = 19;
        *pxnew33 = (*pA613++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew33 += (*pA613++) * xd[*pAidx++];
        }
      }

      xnew[33] += (t15_2_P.Limcontr_B[348])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow34[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow34[0];
        const real_T *pA633 = &t15_2_P.Limcontr_A[633];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew34 = &xnew[34];
        int_T numNonZero = 19;
        *pxnew34 = (*pA633++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew34 += (*pA633++) * xd[*pAidx++];
        }
      }

      xnew[34] += (t15_2_P.Limcontr_B[349])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow35[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow35[0];
        const real_T *pA653 = &t15_2_P.Limcontr_A[653];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew35 = &xnew[35];
        int_T numNonZero = 19;
        *pxnew35 = (*pA653++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew35 += (*pA653++) * xd[*pAidx++];
        }
      }

      xnew[35] += (t15_2_P.Limcontr_B[350])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow36[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow36[0];
        const real_T *pA673 = &t15_2_P.Limcontr_A[673];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew36 = &xnew[36];
        int_T numNonZero = 19;
        *pxnew36 = (*pA673++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew36 += (*pA673++) * xd[*pAidx++];
        }
      }

      xnew[36] += (t15_2_P.Limcontr_B[351])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow37[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow37[0];
        const real_T *pA693 = &t15_2_P.Limcontr_A[693];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew37 = &xnew[37];
        int_T numNonZero = 19;
        *pxnew37 = (*pA693++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew37 += (*pA693++) * xd[*pAidx++];
        }
      }

      xnew[37] += (t15_2_P.Limcontr_B[352])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow38[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow38[0];
        const real_T *pA713 = &t15_2_P.Limcontr_A[713];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew38 = &xnew[38];
        int_T numNonZero = 19;
        *pxnew38 = (*pA713++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew38 += (*pA713++) * xd[*pAidx++];
        }
      }

      xnew[38] += (t15_2_P.Limcontr_B[353])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow39[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow39[0];
        const real_T *pA733 = &t15_2_P.Limcontr_A[733];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew39 = &xnew[39];
        int_T numNonZero = 19;
        *pxnew39 = (*pA733++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew39 += (*pA733++) * xd[*pAidx++];
        }
      }

      xnew[39] += (t15_2_P.Limcontr_B[354])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow40[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow40[0];
        const real_T *pA753 = &t15_2_P.Limcontr_A[753];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew40 = &xnew[40];
        int_T numNonZero = 19;
        *pxnew40 = (*pA753++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew40 += (*pA753++) * xd[*pAidx++];
        }
      }

      xnew[40] += (t15_2_P.Limcontr_B[355])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow41[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow41[0];
        const real_T *pA773 = &t15_2_P.Limcontr_A[773];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew41 = &xnew[41];
        int_T numNonZero = 19;
        *pxnew41 = (*pA773++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew41 += (*pA773++) * xd[*pAidx++];
        }
      }

      xnew[41] += (t15_2_P.Limcontr_B[356])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow42[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow42[0];
        const real_T *pA793 = &t15_2_P.Limcontr_A[793];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew42 = &xnew[42];
        int_T numNonZero = 19;
        *pxnew42 = (*pA793++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew42 += (*pA793++) * xd[*pAidx++];
        }
      }

      xnew[42] += (t15_2_P.Limcontr_B[357])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow43[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow43[0];
        const real_T *pA813 = &t15_2_P.Limcontr_A[813];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew43 = &xnew[43];
        int_T numNonZero = 19;
        *pxnew43 = (*pA813++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew43 += (*pA813++) * xd[*pAidx++];
        }
      }

      xnew[43] += (t15_2_P.Limcontr_B[358])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow44[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow44[0];
        const real_T *pA833 = &t15_2_P.Limcontr_A[833];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew44 = &xnew[44];
        int_T numNonZero = 19;
        *pxnew44 = (*pA833++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew44 += (*pA833++) * xd[*pAidx++];
        }
      }

      xnew[44] += (t15_2_P.Limcontr_B[359])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow45[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow45[0];
        const real_T *pA853 = &t15_2_P.Limcontr_A[853];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew45 = &xnew[45];
        int_T numNonZero = 19;
        *pxnew45 = (*pA853++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew45 += (*pA853++) * xd[*pAidx++];
        }
      }

      xnew[45] += (t15_2_P.Limcontr_B[360])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow46[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow46[0];
        const real_T *pA873 = &t15_2_P.Limcontr_A[873];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew46 = &xnew[46];
        int_T numNonZero = 19;
        *pxnew46 = (*pA873++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew46 += (*pA873++) * xd[*pAidx++];
        }
      }

      xnew[46] += (t15_2_P.Limcontr_B[361])*t15_2_B.tcont2[5];

      {
        static const int_T colAidxRow47[20] = { 28, 29, 30, 31, 32, 33, 34, 35,
          36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

        const int_T *pAidx = &colAidxRow47[0];
        const real_T *pA893 = &t15_2_P.Limcontr_A[893];
        const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
        real_T *pxnew47 = &xnew[47];
        int_T numNonZero = 19;
        *pxnew47 = (*pA893++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew47 += (*pA893++) * xd[*pAidx++];
        }
      }

      xnew[47] += (t15_2_P.Limcontr_B[362])*t15_2_B.tcont2[5];
      xnew[48] = (t15_2_P.Limcontr_A[913])*t15_2_DWork.Limcontr_DSTATE[48];
      xnew[48] += (t15_2_P.Limcontr_B[363])*t15_2_B.tcont2[5];
      xnew[49] = 0.0;
      (void) memcpy(&t15_2_DWork.Limcontr_DSTATE[0],xnew,
                    sizeof(real_T)*50);
    }

    /* Update for DiscreteStateSpace: '<S35>/Curr. contr.' */
    {
      static real_T xnew[11];

      {
        static const int_T colAidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow0[0];
        const real_T *pA0 = &t15_2_P.Currcontr_A[0];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 10;
        *pxnew0 = (*pA0++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew0 += (*pA0++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pBidx = &colBidxRow0[0];
        const real_T *pB0 = &t15_2_P.Currcontr_B[0];
        const real_T *u = t15_2_B.ntur_n;
        real_T *pxnew0 = &xnew[0];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew0 += (*pB0++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow1[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA11 = &t15_2_P.Currcontr_A[11];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 10;
        *pxnew1 = (*pA11++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA11++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow1[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pBidx = &colBidxRow1[0];
        const real_T *pB11 = &t15_2_P.Currcontr_B[11];
        const real_T *u = t15_2_B.ntur_n;
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew1 += (*pB11++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow2[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA22 = &t15_2_P.Currcontr_A[22];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 10;
        *pxnew2 = (*pA22++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA22++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow2[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pBidx = &colBidxRow2[0];
        const real_T *pB22 = &t15_2_P.Currcontr_B[22];
        const real_T *u = t15_2_B.ntur_n;
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew2 += (*pB22++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow3[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA33 = &t15_2_P.Currcontr_A[33];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 10;
        *pxnew3 = (*pA33++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA33++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow3[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pBidx = &colBidxRow3[0];
        const real_T *pB33 = &t15_2_P.Currcontr_B[33];
        const real_T *u = t15_2_B.ntur_n;
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew3 += (*pB33++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow4[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA44 = &t15_2_P.Currcontr_A[44];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 10;
        *pxnew4 = (*pA44++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA44++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow4[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pBidx = &colBidxRow4[0];
        const real_T *pB44 = &t15_2_P.Currcontr_B[44];
        const real_T *u = t15_2_B.ntur_n;
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew4 += (*pB44++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow5[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA55 = &t15_2_P.Currcontr_A[55];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 10;
        *pxnew5 = (*pA55++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA55++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow5[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pBidx = &colBidxRow5[0];
        const real_T *pB55 = &t15_2_P.Currcontr_B[55];
        const real_T *u = t15_2_B.ntur_n;
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew5 += (*pB55++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow6[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA66 = &t15_2_P.Currcontr_A[66];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 10;
        *pxnew6 = (*pA66++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA66++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow6[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pBidx = &colBidxRow6[0];
        const real_T *pB66 = &t15_2_P.Currcontr_B[66];
        const real_T *u = t15_2_B.ntur_n;
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew6 += (*pB66++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow7[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow7[0];
        const real_T *pA77 = &t15_2_P.Currcontr_A[77];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 10;
        *pxnew7 = (*pA77++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA77++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow7[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pBidx = &colBidxRow7[0];
        const real_T *pB77 = &t15_2_P.Currcontr_B[77];
        const real_T *u = t15_2_B.ntur_n;
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew7 += (*pB77++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow8[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow8[0];
        const real_T *pA88 = &t15_2_P.Currcontr_A[88];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 10;
        *pxnew8 = (*pA88++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew8 += (*pA88++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow8[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pBidx = &colBidxRow8[0];
        const real_T *pB88 = &t15_2_P.Currcontr_B[88];
        const real_T *u = t15_2_B.ntur_n;
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew8 += (*pB88++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow9[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow9[0];
        const real_T *pA99 = &t15_2_P.Currcontr_A[99];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 10;
        *pxnew9 = (*pA99++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA99++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow9[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pBidx = &colBidxRow9[0];
        const real_T *pB99 = &t15_2_P.Currcontr_B[99];
        const real_T *u = t15_2_B.ntur_n;
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew9 += (*pB99++) * u[*pBidx++];
        }
      }

      {
        static const int_T colAidxRow10[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow10[0];
        const real_T *pA110 = &t15_2_P.Currcontr_A[110];
        const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 10;
        *pxnew10 = (*pA110++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew10 += (*pA110++) * xd[*pAidx++];
        }
      }

      {
        static const int_T colBidxRow10[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pBidx = &colBidxRow10[0];
        const real_T *pB110 = &t15_2_P.Currcontr_B[110];
        const real_T *u = t15_2_B.ntur_n;
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 11;
        while (numNonZero--) {
          *pxnew10 += (*pB110++) * u[*pBidx++];
        }
      }

      (void) memcpy(&t15_2_DWork.Currcontr_DSTATE[0],xnew,
                    sizeof(real_T)*11);
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.002, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  t15_2_M->Timing.clockTick0++;
}

/* Model initialize function */
void t15_2_initialize(boolean_T firstTime)
{
//  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)t15_2_M,0,
                sizeof(RT_MODEL_t15_2));

  /* block I/O */
  (void) memset(((void *) &t15_2_B),0,
                sizeof(BlockIO_t15_2));

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_B.Memory[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.RateLimiter[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Saturation6[i] = 0.0;
    }

    for (i = 0; i < 15; i++) {
      t15_2_B.e6_l[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.VScontr[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.VScontrhl[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.c_eob[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.u9[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.Divide10[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.SaturationVS[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Add1_b[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.TmpSignalConversionAtnpf12Inpor[i] = 0.0;
    }

    for (i = 0; i < 15; i++) {
      t15_2_B.npf12[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      t15_2_B.e2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      t15_2_B.e2_g[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.u9_a[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.e3_m[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Abs[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.ntur[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum2_p[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.c_cur_max[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum1[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide4_j[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_j[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Saturation[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory1_eo[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory_m[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide2_j[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u9_d[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide13[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Div_rdcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u99[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide4_a[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Currtermcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide5[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory2_fo[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.tcont2[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Limcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Currcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.IpIp_div[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide6_iz[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide7[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum3[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide2_e[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum3_f[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Saturation1_m[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide6_p[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide12[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.ntur_n[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide2_d[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Tfmc[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Add1_e[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide3[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.Divide11[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.c_eob_pt[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.Divide8[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.Divide9[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide_e[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide3_g[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_b[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum2_i[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.tcont2_b[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide_d[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.ntur_d[i] = 0.0;
    }

    t15_2_B.Uk1 = 0.0;
    t15_2_B.Diff = 0.0;
    t15_2_B.Gain = 0.0;
    t15_2_B.e6 = 0.0;
    t15_2_B.LogicalOperator2 = 0.0;
    t15_2_B.LogicalOperator1 = 0.0;
    t15_2_B.UniformRandomNumber = 0.0;
    t15_2_B.Uk1_a = 0.0;
    t15_2_B.Uk1_g = 0.0;
    t15_2_B.tt_tran2d[0] = 0.0;
    t15_2_B.tt_tran2d[1] = 0.0;
    t15_2_B.Memory2 = 0.0;
    t15_2_B.Add3 = 0.0;
    t15_2_B.Memory1 = 0.0;
    t15_2_B.Ics1_eob = 0.0;
    t15_2_B.Add2 = 0.0;
    t15_2_B.dtpl_term_l = 0.0;
    t15_2_B.Add1 = 0.0;
    t15_2_B.u = 0.0;
    t15_2_B.RelationalOperator = 0.0;
    t15_2_B.Divide4[0] = 0.0;
    t15_2_B.Divide4[1] = 0.0;
    t15_2_B.LogicalOperator1_m = 0.0;
    t15_2_B.Memory2_f = 0.0;
    t15_2_B.u_o = 0.0;
    t15_2_B.IpIp_0 = 0.0;
    t15_2_B.Sum2 = 0.0;
    t15_2_B.Memory1_h = 0.0;
    t15_2_B.c_eob_f = 0.0;
    t15_2_B.Divide6 = 0.0;
    t15_2_B.Add1_o = 0.0;
    t15_2_B.Memory2_l = 0.0;
    t15_2_B.c_eob_c = 0.0;
    t15_2_B.Divide1_l = 0.0;
    t15_2_B.Add1_oq = 0.0;
    t15_2_B.Memory2_k = 0.0;
    t15_2_B.c_eob_p = 0.0;
    t15_2_B.Divide1_h = 0.0;
    t15_2_B.Add10 = 0.0;
    t15_2_B.Memory2_e = 0.0;
    t15_2_B.c_eob_o = 0.0;
    t15_2_B.Divide1_i = 0.0;
    t15_2_B.Add11 = 0.0;
    t15_2_B.Memory2_l4 = 0.0;
    t15_2_B.c_eob_k = 0.0;
    t15_2_B.Divide1_e = 0.0;
    t15_2_B.Add2_d = 0.0;
    t15_2_B.Memory2_o = 0.0;
    t15_2_B.c_eob_kq = 0.0;
    t15_2_B.Divide1_g = 0.0;
    t15_2_B.Add3_a = 0.0;
    t15_2_B.Memory2_h = 0.0;
    t15_2_B.c_eob_p1 = 0.0;
    t15_2_B.Divide1_la = 0.0;
    t15_2_B.Add4 = 0.0;
    t15_2_B.Memory2_a = 0.0;
    t15_2_B.c_eob_l = 0.0;
    t15_2_B.Divide1_hp = 0.0;
    t15_2_B.Add5 = 0.0;
    t15_2_B.Memory2_m = 0.0;
    t15_2_B.c_eob_b = 0.0;
    t15_2_B.Divide1_f = 0.0;
    t15_2_B.Add6 = 0.0;
    t15_2_B.Memory2_o2 = 0.0;
    t15_2_B.c_eob_g = 0.0;
    t15_2_B.Divide1_a = 0.0;
    t15_2_B.Add7 = 0.0;
    t15_2_B.Memory2_b = 0.0;
    t15_2_B.c_eob_d = 0.0;
    t15_2_B.Divide1_fa = 0.0;
    t15_2_B.Add8 = 0.0;
    t15_2_B.Memory2_o5 = 0.0;
    t15_2_B.c_eob_fg = 0.0;
    t15_2_B.Divide1_ap = 0.0;
    t15_2_B.Add9 = 0.0;
    t15_2_B.LookupTable1 = 0.0;
    t15_2_B.Divide6_l = 0.0;
    t15_2_B.Sum2_f = 0.0;
    t15_2_B.u_a = 0.0;
    t15_2_B.Memory1_d = 0.0;
    t15_2_B.c_eob_gq = 0.0;
    t15_2_B.c_eob_d1 = 0.0;
    t15_2_B.Add2_i = 0.0;
    t15_2_B.LookupTable1_b = 0.0;
    t15_2_B.Divide6_i = 0.0;
    t15_2_B.Memory1_e = 0.0;
    t15_2_B.c_eob_o2 = 0.0;
    t15_2_B.c_eob_e = 0.0;
    t15_2_B.Add1_j = 0.0;
    t15_2_B.LookupTable2 = 0.0;
    t15_2_B.Divide1_k = 0.0;
    t15_2_B.Memory1_f = 0.0;
    t15_2_B.c_eob_k5 = 0.0;
    t15_2_B.c_eob_kv = 0.0;
    t15_2_B.Add3_b = 0.0;
    t15_2_B.Memory1_dh = 0.0;
    t15_2_B.c_eob_i = 0.0;
    t15_2_B.c_eob_ij = 0.0;
    t15_2_B.Add4_j = 0.0;
    t15_2_B.LookupTable3 = 0.0;
    t15_2_B.Divide2 = 0.0;
    t15_2_B.Memory1_g = 0.0;
    t15_2_B.c_eob_e1 = 0.0;
    t15_2_B.c_eob_bo = 0.0;
    t15_2_B.Add5_k = 0.0;
    t15_2_B.g6_ref = 0.0;
    t15_2_B.Memory2_m4 = 0.0;
    t15_2_B.c_eob1 = 0.0;
    t15_2_B.Memory1_dn = 0.0;
    t15_2_B.c_eob_lg = 0.0;
    t15_2_B.c_eob_fd = 0.0;
    t15_2_B.Add6_g = 0.0;
    t15_2_B.e6_e = 0.0;
    t15_2_B.LogicalOperator1_a = 0.0;
    t15_2_B.LogicalOperator2_o = 0.0;
    t15_2_B.LogicalOperator1_h = 0.0;
    t15_2_B.Memory3 = 0.0;
    t15_2_B.LogicalOperator1_c = 0.0;
    t15_2_B.u999 = 0.0;
    t15_2_B.Subtract2 = 0.0;
    t15_2_B.Gain1 = 0.0;
    t15_2_B.Subtract1 = 0.0;
    t15_2_B.Saturation1 = 0.0;
    t15_2_B.Memory1_n = 0.0;
    t15_2_B.LogicalOperator1_d = 0.0;
    t15_2_B.u999_b = 0.0;
    t15_2_B.Memory1_b = 0.0;
    t15_2_B.c_eob_fp = 0.0;
    t15_2_B.Memory1_k = 0.0;
    t15_2_B.u999_l = 0.0;
    t15_2_B.Subtract2_k = 0.0;
    t15_2_B.Gain1_g = 0.0;
    t15_2_B.Subtract3 = 0.0;
    t15_2_B.Saturation_a = 0.0;
    t15_2_B.Gain2 = 0.0;
    t15_2_B.Subtract1_k = 0.0;
    t15_2_B.volt1 = 0.0;
    t15_2_B.volt2 = 0.0;
    t15_2_B.volt3 = 0.0;
    t15_2_B.volt4 = 0.0;
    t15_2_B.volt5 = 0.0;
    t15_2_B.volt6 = 0.0;
    t15_2_B.volt7 = 0.0;
    t15_2_B.volt8 = 0.0;
    t15_2_B.volt9 = 0.0;
    t15_2_B.volt10 = 0.0;
    t15_2_B.volt11 = 0.0;
    t15_2_B.Add = 0.0;
    t15_2_B.Ipl_ref = 0.0;
    t15_2_B.c_a_tpl1_eob15 = 0.0;
    t15_2_B.Saturation4 = 0.0;
    t15_2_B.IpIp_div_l = 0.0;
    t15_2_B.Saturation2 = 0.0;
    t15_2_B.atpl1 = 0.0;
    t15_2_B.c_a_tpl1_eob15_l = 0.0;
    t15_2_B.u5 = 0.0;
    t15_2_B.Saturation3 = 0.0;
    t15_2_B.Subtract3_a = 0.0;
    t15_2_B.Subtract2_b = 0.0;
    t15_2_B.Gain1_n = 0.0;
    t15_2_B.Subtract3_k = 0.0;
    t15_2_B.Saturation_i = 0.0;
    t15_2_B.Subtract1_f = 0.0;
    t15_2_B.c_eob_j = 0.0;
    t15_2_B.atpl2 = 0.0;
    t15_2_B.Saturation_a1 = 0.0;
    t15_2_B.Divide6_o = 0.0;
    t15_2_B.Sum = 0.0;
    t15_2_B.Divide2_h = 0.0;
    t15_2_B.Sum1_k = 0.0;
    t15_2_B.uy0 = 0.0;
    t15_2_B.gain_cont2 = 0.0;
    t15_2_B.Diff_b = 0.0;
    t15_2_B.Diff_n = 0.0;
    t15_2_B.Divide_i = 0.0;
    t15_2_B.Sum2_d = 0.0;
    t15_2_B.elong_ref = 0.0;
    t15_2_B.Add2_f = 0.0;
    t15_2_B.k_gaplim[0] = 0.0;
    t15_2_B.k_gaplim[1] = 0.0;
    t15_2_B.k_gaplim[2] = 0.0;
    t15_2_B.k_gaplim[3] = 0.0;
    t15_2_B.Add2_ft = 0.0;
    t15_2_B.g6_ref_term = 0.0;
    t15_2_B.Add1_f = 0.0;
    t15_2_B.g5_ref = 0.0;
    t15_2_B.Add2_g = 0.0;
    t15_2_B.g5_ref_term = 0.0;
    t15_2_B.g4_ref = 0.0;
    t15_2_B.Add2_o = 0.0;
    t15_2_B.g4_ref_term = 0.0;
    t15_2_B.g3_ref = 0.0;
    t15_2_B.Add2_iv = 0.0;
    t15_2_B.g3_ref_term = 0.0;
    t15_2_B.g2_ref = 0.0;
    t15_2_B.Add2_e = 0.0;
    t15_2_B.g2_ref_term = 0.0;
    t15_2_B.g1_ref = 0.0;
    t15_2_B.Add2_a = 0.0;
    t15_2_B.g1_ref_term = 0.0;
    t15_2_B.Ipl_ref_g = 0.0;
    t15_2_B.Icoil9_ref = 0.0;
    t15_2_B.Icoil8_ref = 0.0;
    t15_2_B.Icoil1_ref = 0.0;
    t15_2_B.Icoil6_ref = 0.0;
    t15_2_B.Icoil5_ref = 0.0;
    t15_2_B.Icoil4_ref = 0.0;
    t15_2_B.Icoil3_ref = 0.0;
    t15_2_B.Icoil2_ref = 0.0;
    t15_2_B.Icoil11_ref = 0.0;
    t15_2_B.Icoil10_ref = 0.0;
    t15_2_B.Icoil1_ref_k = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&t15_2_DWork, 0,
                sizeof(D_Work_t15_2));
  t15_2_DWork.UD_DSTATE = 0.0;
  t15_2_DWork.UD_DSTATE_n = 0.0;
  t15_2_DWork.UD_DSTATE_h = 0.0;

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      t15_2_DWork.VScontr_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      t15_2_DWork.VScontrhl_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 50; i++) {
      t15_2_DWork.Divcontr_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 40; i++) {
      t15_2_DWork.Div_rdcontr_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 40; i++) {
      t15_2_DWork.Currtermcontr_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 50; i++) {
      t15_2_DWork.Limcontr_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Currcontr_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory_PreviousInput[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.PrevY[i] = 0.0;
    }
  }

  t15_2_DWork.UniformRandomNumber_NextOutput = 0.0;
  t15_2_DWork.Memory2_PreviousInput = 0.0;
  t15_2_DWork.Memory1_PreviousInput = 0.0;
  t15_2_DWork.Memory2_PreviousInput_g = 0.0;
  t15_2_DWork.Memory1_PreviousInput_n = 0.0;
  t15_2_DWork.Memory2_PreviousInput_b = 0.0;
  t15_2_DWork.Memory2_PreviousInput_a = 0.0;
  t15_2_DWork.Memory2_PreviousInput_n = 0.0;
  t15_2_DWork.Memory2_PreviousInput_bt = 0.0;
  t15_2_DWork.Memory2_PreviousInput_c = 0.0;
  t15_2_DWork.Memory2_PreviousInput_i = 0.0;
  t15_2_DWork.Memory2_PreviousInput_bh = 0.0;
  t15_2_DWork.Memory2_PreviousInput_m = 0.0;
  t15_2_DWork.Memory2_PreviousInput_ns = 0.0;
  t15_2_DWork.Memory2_PreviousInput_gb = 0.0;
  t15_2_DWork.Memory2_PreviousInput_gn = 0.0;
  t15_2_DWork.Memory1_PreviousInput_e = 0.0;
  t15_2_DWork.Memory1_PreviousInput_h = 0.0;
  t15_2_DWork.Memory1_PreviousInput_f = 0.0;
  t15_2_DWork.Memory1_PreviousInput_p = 0.0;
  t15_2_DWork.Memory1_PreviousInput_i = 0.0;
  t15_2_DWork.Memory2_PreviousInput_o = 0.0;
  t15_2_DWork.Memory1_PreviousInput_c = 0.0;

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory1_PreviousInput_er[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory_PreviousInput_i[i] = 0.0;
    }
  }

  t15_2_DWork.Memory3_PreviousInput = 0.0;
  t15_2_DWork.Memory1_PreviousInput_a = 0.0;
  t15_2_DWork.Memory1_PreviousInput_ek = 0.0;
  t15_2_DWork.Memory1_PreviousInput_j = 0.0;

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory2_PreviousInput_j[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Sum3_DWORK1[i] = 0.0;
    }
  }

  /* external inputs */
  {
    int_T i;
    for (i = 0; i < 15; i++) {
      t15_2_U.In1[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 123; i++) {
      t15_2_U.In2[i] = 0.0;
    }
  }

  /* external outputs */
  {
    int_T i;
    for (i = 0; i < 38; i++) {
      t15_2_Y.Out1[i] = 0.0;
    }
  }

  t15_2_Y.Time = 0.0;

  {
    uint32_T tseed;
    int32_T r;
    uint32_T t;
    real_T tmin;

    /* Start for UniformRandomNumber: '<S43>/Uniform Random Number' */
    tmin = t15_2_P.UniformRandomNumber_Seed;
    if (rtIsNaN(tmin) || rtIsInf(tmin)) {
      tmin = 0.0;
    } else {
      tmin = fmod(floor(tmin), 4.294967296E+009);
    }

    tseed = tmin < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmin))) : (uint32_T)
      tmin;
    r = (int32_T)(tseed >> 16U);
    t = tseed & 32768U;
    tseed = (((tseed - (((uint32_T)r << 16) - t)) << 16U) + t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    t15_2_DWork.RandSeed = tseed;
    tmin = t15_2_P.UniformRandomNumber_Minimum;
    t15_2_DWork.UniformRandomNumber_NextOutput =
      (t15_2_P.UniformRandomNumber_Maximum - tmin) * rt_Urand
      (&t15_2_DWork.RandSeed) + tmin;
  }

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S61>/UD' */
    t15_2_DWork.UD_DSTATE = t15_2_P.UD_X0;
    for (i = 0; i < 11; i++) {
      /* InitializeConditions for Memory: '<S3>/Memory' */
      t15_2_DWork.Memory_PreviousInput[i] = t15_2_P.Memory_X0;

      /* InitializeConditions for RateLimiter: '<S3>/Rate Limiter' */
      t15_2_DWork.PrevY[i] = t15_2_P.RateLimiter_IC;
    }

    /* InitializeConditions for UnitDelay: '<S31>/UD' */
    t15_2_DWork.UD_DSTATE_n = t15_2_P.UD_X0_e;

    /* InitializeConditions for UnitDelay: '<S32>/UD' */
    t15_2_DWork.UD_DSTATE_h = t15_2_P.UD_X0_h;

    /* InitializeConditions for DiscreteStateSpace: '<S38>/VS. contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.VScontr_DSTATE[0];
      for (i1=0; i1 < 9; i1++) {
        dw_DSTATE[i1] = t15_2_P.VScontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S9>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput = t15_2_P.Memory2_X0;

    /* InitializeConditions for Memory: '<S9>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput = t15_2_P.Memory1_X0;

    /* InitializeConditions for DiscreteStateSpace: '<S38>/VS. contr hl' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.VScontrhl_DSTATE[0];
      for (i1=0; i1 < 8; i1++) {
        dw_DSTATE[i1] = t15_2_P.VScontrhl_X0;
      }
    }

    /* InitializeConditions for Memory: '<Root>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_g = t15_2_P.Memory2_X0_k;

    /* InitializeConditions for Memory: '<S7>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_n = t15_2_P.Memory1_X0_f;

    /* InitializeConditions for Memory: '<S15>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_b = t15_2_P.Memory2_X0_o;

    /* InitializeConditions for Memory: '<S13>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_a = t15_2_P.Memory2_X0_n;

    /* InitializeConditions for Memory: '<S14>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_n = t15_2_P.Memory2_X0_g;

    /* InitializeConditions for Memory: '<S16>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_bt = t15_2_P.Memory2_X0_b;

    /* InitializeConditions for Memory: '<S12>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_c = t15_2_P.Memory2_X0_i;

    /* InitializeConditions for Memory: '<S17>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_i = t15_2_P.Memory2_X0_l;

    /* InitializeConditions for Memory: '<S18>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_bh = t15_2_P.Memory2_X0_d;

    /* InitializeConditions for Memory: '<S19>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_m = t15_2_P.Memory2_X0_n4;

    /* InitializeConditions for Memory: '<S20>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_ns = t15_2_P.Memory2_X0_m;

    /* InitializeConditions for Memory: '<S21>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_gb = t15_2_P.Memory2_X0_a;

    /* InitializeConditions for Memory: '<S22>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_gn = t15_2_P.Memory2_X0_dl;

    /* InitializeConditions for Memory: '<S23>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_e = t15_2_P.Memory1_X0_p;

    /* InitializeConditions for Memory: '<S24>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_h = t15_2_P.Memory1_X0_h;

    /* InitializeConditions for Memory: '<S25>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_f = t15_2_P.Memory1_X0_i;

    /* InitializeConditions for Memory: '<S26>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_p = t15_2_P.Memory1_X0_k;

    /* InitializeConditions for Memory: '<S27>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_i = t15_2_P.Memory1_X0_m;

    /* InitializeConditions for Memory: '<S28>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_o = t15_2_P.Memory2_X0_e;

    /* InitializeConditions for Memory: '<S28>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_c = t15_2_P.Memory1_X0_iy;
    for (i = 0; i < 11; i++) {
      /* InitializeConditions for Memory: '<S34>/Memory1' */
      t15_2_DWork.Memory1_PreviousInput_er[i] = t15_2_P.Memory1_X0_d;

      /* InitializeConditions for Memory: '<S36>/Memory' */
      t15_2_DWork.Memory_PreviousInput_i[i] = t15_2_P.Memory_X0_a;
    }

    /* InitializeConditions for Memory: '<S44>/Memory3' */
    t15_2_DWork.Memory3_PreviousInput = t15_2_P.Memory3_X0;

    /* InitializeConditions for DiscreteStateSpace: '<S2>/Div. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Divcontr_DSTATE[0];
      for (i1=0; i1 < 50; i1++) {
        dw_DSTATE[i1] = t15_2_P.Divcontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S42>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_a = t15_2_P.Memory1_X0_e;

    /* InitializeConditions for DiscreteStateSpace: '<S2>/Div_rd contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Div_rdcontr_DSTATE[0];
      for (i1=0; i1 < 40; i1++) {
        dw_DSTATE[i1] = t15_2_P.Div_rdcontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S40>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_ek = t15_2_P.Memory1_X0_kl;

    /* InitializeConditions for Memory: '<S41>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_j = t15_2_P.Memory1_X0_e1;

    /* InitializeConditions for DiscreteStateSpace: '<S2>/Curr. term. contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Currtermcontr_DSTATE[0];
      for (i1=0; i1 < 40; i1++) {
        dw_DSTATE[i1] = t15_2_P.Currtermcontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S2>/Memory2' */
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory2_PreviousInput_j[i] = t15_2_P.Memory2_X0_j;
    }

    /* InitializeConditions for DiscreteStateSpace: '<S35>/Lim. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Limcontr_DSTATE[0];
      for (i1=0; i1 < 50; i1++) {
        dw_DSTATE[i1] = t15_2_P.Limcontr_X0;
      }
    }

    /* InitializeConditions for DiscreteStateSpace: '<S35>/Curr. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Currcontr_DSTATE[0];
      for (i1=0; i1 < 11; i1++) {
        dw_DSTATE[i1] = t15_2_P.Currcontr_X0;
      }
    }
  }
}

/* Model terminate function */
void t15_2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
void t15_2_output(int  nbrInputArgs, double* input,
int *nbrOutputArgs, double* output) 
{
	 int i, k, ki;

	  ki=0;

	  if( kpr == 1){
	  printf("Enter t15_2_output "
         " and ki "
		 " .  %d %d  \n",nbrInputArgs,ki);}

  /* external inputs */
	k=0;
    for (i = 0; i < 15; i++) 
	{ t15_2_U.In1[i] = input[i];
	  k=k+1;
    }
    ki=k;
if( kpr == 1){
	printf("k  ki %d %d  \n",k,ki);}

	
	for (i = 0; i < 123; i++)
	{ t15_2_U.In2[i] = input[i+ki];
	  k=k+1;
    }
    ki=k;

if( kpr == 1){
		  printf("k  ki %d %d  \n",k,ki);

	  printf("nbrInputArgs "
         " and ki "
		 " .  %d %d  \n",nbrInputArgs,ki);}
/*
	  printf("test1_step() "
         "getControllerOutput. "
         " .  %.3f\n",input[0]);
*/

	  t15_2_step();


	 // printf("---t15_2_step  \n");



  /* external outputs */
  //real_T Out1[15];
  	  k=0;

      for (i = 0; i < 15; i++) 
	  { output[i]=t15_2_Y.Out1[i] ;
	  k=k+1;
      }
	  
	  ki=k;

      for (i = 0; i < 11; i++) 
	  { output[i+ki]=t15_2_B.Saturation6[i] ;
	  k=k+1;
      }

//t15_2_B.Saturation6[i] + t15_2_B.SaturationVS[i];

	  ki=k;

      for (i = 0; i < 11; i++) 
	  { output[i+ki]=t15_2_B.SaturationVS[i] ;
	  k=k+1;
      }

	  i=11;
	  output[i+ki]=t15_2_B.SaturationVS[i] ;

	  ki=k;

	  nbrOutputArgs=&ki;

	  if( kpr == 1){
  
	  printf("---nbrOutputArgs "
         " and ki "
		 " .  %d %d  \n",*nbrOutputArgs,ki);
	

      for (i = 0; i < ki; i++) 
	  { 	  printf("output "
         " and i "
         " .  %g %d  \n",output[i],i);
      }
      
	  
	  }

}


