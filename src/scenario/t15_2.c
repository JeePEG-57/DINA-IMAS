#if 1 

# define t15_2_initialize t15_2_initialize_
# define t15_2_output t15_2_output_
# define t15_2_terminate t15_2_terminate_

#endif

/*
 * File: t15_2.c
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
RT_MODEL_t15_2 *const t15_2_M = &t15_2_M_;

/* Lookup Binary Search Utility BINARYSEARCH_real_T */
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/* Lookup Utility LookUp_real_T_real_T */
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real_T num;
      real_T den;
      den = pUData[iRght];
      den = den - pUData[iLeft];
      num = u;
      num = num - pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = pYData[iLeft];
      yRghtCast = pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

/* Model step function */
void t15_2_step(void)
{
  real_T y[500];
  real_T u[13];
  real_T tmin;
  int32_T i;
  int32_T i_0;
  real_T u_0;
  real_T u_1;

  /* Gain: '<S4>/1e-3' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_B.e3 = t15_2_P.e3_Gain * t15_2_U.In1[8];

  /* UnitDelay: '<S5>/UD' */
  t15_2_B.Uk1 = t15_2_DWork.UD_DSTATE;

  /* Sum: '<S5>/Diff' */
  t15_2_B.Diff = t15_2_B.e3 - t15_2_B.Uk1;

  /* Gain: '<S2>/Gain' */
  t15_2_B.Gain = t15_2_P.Gain_Gain * t15_2_B.Diff;
  for (i = 0; i < 11; i++) {
    /* Memory: '<S2>/Memory' */
    t15_2_B.Memory[i] = t15_2_DWork.Memory_PreviousInput[i];

    /* Product: '<S2>/Divide' incorporates:
     *  Constant: '<S2>/SimStep'
     */
    t15_2_B.Divide[i] = t15_2_B.Memory[i] * t15_2_P.SimStep_Value / t15_2_B.Diff;

    /* RateLimiter: '<S2>/Rate Limiter' */
    tmin = t15_2_B.Divide[i] - t15_2_DWork.PrevY[i];
    if (tmin > t15_2_P.RateLimiter_RisingLim[i]) {
      t15_2_B.RateLimiter[i] = t15_2_DWork.PrevY[i] +
        t15_2_P.RateLimiter_RisingLim[i];
    } else if (tmin < t15_2_P.RateLimiter_FallingLim[i]) {
      t15_2_B.RateLimiter[i] = t15_2_DWork.PrevY[i] +
        t15_2_P.RateLimiter_FallingLim[i];
    } else {
      t15_2_B.RateLimiter[i] = t15_2_B.Divide[i];
    }

    t15_2_DWork.PrevY[i] = t15_2_B.RateLimiter[i];

    /* End of RateLimiter: '<S2>/Rate Limiter' */

    /* Product: '<S2>/Divide1' */
    t15_2_B.Divide1[i] = t15_2_B.RateLimiter[i] * t15_2_B.Gain;

    /* Saturate: '<S2>/Saturation6' */
    tmin = t15_2_B.Divide1[i];
    u_0 = t15_2_P.Saturation6_LowerSat[i];
    u_1 = t15_2_P.Saturation6_UpperSat[i];
    if (tmin >= u_1) {
      tmin = u_1;
    } else {
      if (tmin <= u_0) {
        tmin = u_0;
      }
    }

    t15_2_B.Saturation6[i] = tmin;

    /* End of Saturate: '<S2>/Saturation6' */

    /* Gain: '<S1>/1//ntur' */
    t15_2_B.ntur[i] = t15_2_P.ntur_Gain_c[i] * t15_2_B.Saturation6[i];
  }

  /* Gain: '<S6>/1e-6' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_B.e6 = t15_2_P.e6_Gain * t15_2_U.In1[3];

  /* RelationalOperator: '<S59>/Compare' incorporates:
   *  Constant: '<S59>/Constant'
   */
  t15_2_B.Compare = (uint8_T)(t15_2_B.e6 < t15_2_P.Constant_Value);

  /* RelationalOperator: '<S60>/Compare' incorporates:
   *  Constant: '<S60>/Constant'
   */
  t15_2_B.Compare_c = (uint8_T)(t15_2_B.e3 > t15_2_P.Constant_Value_k);

  /* Logic: '<S45>/Logical Operator2' */
  t15_2_B.LogicalOperator2 = ((t15_2_B.Compare != 0) && (t15_2_B.Compare_c != 0));

  /* Sum: '<S45>/Subtract4' incorporates:
   *  Constant: '<S45>/1'
   */
  t15_2_B.Subtract4 = t15_2_P._Value_o - t15_2_B.LogicalOperator2;

  /* UniformRandomNumber: '<S47>/Uniform Random Number' */
  t15_2_B.UniformRandomNumber = t15_2_DWork.UniformRandomNumber_NextOutput;

  /* UnitDelay: '<S34>/UD' */
  t15_2_B.Uk1_h = t15_2_DWork.UD_DSTATE_j;

  /* UnitDelay: '<S35>/UD' */
  t15_2_B.Uk1_d = t15_2_DWork.UD_DSTATE_o;

  /* Gain: '<S6>/1e-6   ' incorporates:
   *  Inport: '<Root>/In2'
   */
  for (i = 0; i < 15; i++) {
    t15_2_B.e6_m[i] = t15_2_U.In2[i + 6] * t15_2_P.e6_Gain_k;
  }

  /* End of Gain: '<S6>/1e-6   ' */

  /* Switch: '<S7>/t>t_tran2d' incorporates:
   *  Constant: '<S7>/zeros(2,1)'
   */
  if (t15_2_B.e3 > t15_2_P.tt_tran2d_Threshold) {
    /* Sum: '<S35>/Diff' */
    t15_2_B.Diff_j = t15_2_B.e3 - t15_2_B.Uk1_d;

    /* Sum: '<S34>/Diff' incorporates:
     *  Inport: '<Root>/In1'
     */
    t15_2_B.Diff_l = t15_2_U.In1[0] - t15_2_B.Uk1_h;

    /* Product: '<S14>/Divide' */
    t15_2_B.Divide_l = t15_2_B.Diff_l / t15_2_B.Diff_j;

    /* Sum: '<S47>/Sum2' */
    t15_2_B.Sum2_b = t15_2_B.UniformRandomNumber + t15_2_B.Divide_l;
    t15_2_B.tt_tran2d[0] = t15_2_B.Sum2_b;
    t15_2_B.tt_tran2d[1] = t15_2_B.e6_m[11];
  } else {
    t15_2_B.tt_tran2d[0] = t15_2_P.zeros21_Value[0];
    t15_2_B.tt_tran2d[1] = t15_2_P.zeros21_Value[1];
  }

  /* End of Switch: '<S7>/t>t_tran2d' */

  /* DiscreteStateSpace: '<S41>/VS. contr' */
  {
    {
      static const int_T colCidxRow0[9] = { 0, 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = t15_2_P.VScontr_C;
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *y0 = &t15_2_B.VScontr[0];
      int_T numNonZero = 8;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    t15_2_B.VScontr[0] += (t15_2_P.VScontr_D[0])*t15_2_B.tt_tran2d[0] +
      (t15_2_P.VScontr_D[1])*t15_2_B.tt_tran2d[1];

    {
      static const int_T colCidxRow1[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC9 = &t15_2_P.VScontr_C[9];
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *y1 = &t15_2_B.VScontr[1];
      int_T numNonZero = 8;
      *y1 = (*pC9++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC9++) * xd[*pCidx++];
      }
    }

    t15_2_B.VScontr[1] += (t15_2_P.VScontr_D[2])*t15_2_B.tt_tran2d[0] +
      (t15_2_P.VScontr_D[3])*t15_2_B.tt_tran2d[1];
  }

  /* Memory: '<S12>/Memory2' */
  t15_2_B.Memory2 = t15_2_DWork.Memory2_PreviousInput;

  /* Sum: '<S12>/Add3' */
  t15_2_B.Add3 = t15_2_B.e6_m[2] + t15_2_B.Memory2;

  /* Memory: '<S12>/Memory1' */
  t15_2_B.Memory1 = t15_2_DWork.Memory1_PreviousInput;

  /* Switch: '<S12>/Ics1_eob' */
  if (t15_2_B.Add3 >= t15_2_P.Ics1_eob_Threshold) {
    t15_2_B.Ics1_eob = t15_2_B.e3;
  } else {
    t15_2_B.Ics1_eob = t15_2_B.Memory1;
  }

  /* End of Switch: '<S12>/Ics1_eob' */

  /* Sum: '<S12>/Add2' */
  t15_2_B.Add2 = t15_2_B.Ics1_eob - t15_2_B.e3;

  /* Gain: '<S12>/dtpl_term_l' */
  t15_2_B.dtpl_term_l = t15_2_P.dtpl_term_l_Gain * t15_2_B.Add2;

  /* Sum: '<S12>/Add1' incorporates:
   *  Constant: '<S12>/Constant4'
   */
  t15_2_B.Add1 = t15_2_B.dtpl_term_l + t15_2_P.Constant4_Value;

  /* Saturate: '<S12>/1 0' */
  tmin = t15_2_B.Add1;
  u_0 = t15_2_P.u_LowerSat;
  u_1 = t15_2_P.u_UpperSat;
  if (tmin >= u_1) {
    t15_2_B.u = u_1;
  } else if (tmin <= u_0) {
    t15_2_B.u = u_0;
  } else {
    t15_2_B.u = tmin;
  }

  /* End of Saturate: '<S12>/1 0' */

  /* RelationalOperator: '<S41>/Relational Operator' incorporates:
   *  Constant: '<S41>/c_eob '
   */
  t15_2_B.RelationalOperator = (t15_2_B.u < t15_2_P.c_eob_Value);

  /* Product: '<S41>/Divide4' */
  t15_2_B.Divide4[0] = t15_2_B.RelationalOperator * t15_2_B.tt_tran2d[0];
  t15_2_B.Divide4[1] = t15_2_B.RelationalOperator * t15_2_B.tt_tran2d[1];

  /* DiscreteStateSpace: '<S41>/VS. contr hl' */
  {
    {
      static const int_T colCidxRow0[5] = { 3, 4, 5, 6, 7 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = t15_2_P.VScontrhl_C;
      const real_T *xd = &t15_2_DWork.VScontrhl_DSTATE[0];
      real_T *y0 = &t15_2_B.VScontrhl[0];
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    t15_2_B.VScontrhl[0] += (t15_2_P.VScontrhl_D[0])*t15_2_B.Divide4[0] +
      (t15_2_P.VScontrhl_D[1])*t15_2_B.Divide4[1];
    t15_2_B.VScontrhl[1] = (t15_2_P.VScontrhl_C[5])*
      t15_2_DWork.VScontrhl_DSTATE[0] + (t15_2_P.VScontrhl_C[6])*
      t15_2_DWork.VScontrhl_DSTATE[1]
      + (t15_2_P.VScontrhl_C[7])*t15_2_DWork.VScontrhl_DSTATE[2]
      + (t15_2_P.VScontrhl_C[8])*t15_2_DWork.VScontrhl_DSTATE[7];
    t15_2_B.VScontrhl[1] += (t15_2_P.VScontrhl_D[2])*t15_2_B.Divide4[0] +
      (t15_2_P.VScontrhl_D[3])*t15_2_B.Divide4[1];
  }

  /* Switch: '<S41>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_j) {
    t15_2_B.c_eob[0] = t15_2_B.VScontr[0];
    t15_2_B.c_eob[1] = t15_2_B.VScontr[1];
  } else {
    t15_2_B.c_eob[0] = t15_2_B.VScontrhl[0];
    t15_2_B.c_eob[1] = t15_2_B.VScontrhl[1];
  }

  /* End of Switch: '<S41>/c_eob' */

  /* RelationalOperator: '<S56>/Compare' incorporates:
   *  Constant: '<S56>/Constant'
   */
  t15_2_B.Compare_m = (uint8_T)(t15_2_B.e6 < t15_2_P.Constant_Value_g);

  /* RelationalOperator: '<S57>/Compare' incorporates:
   *  Constant: '<S57>/Constant'
   */
  t15_2_B.Compare_o = (uint8_T)(t15_2_B.e3 > t15_2_P.Constant_Value_f);

  /* RelationalOperator: '<S58>/Compare' incorporates:
   *  Constant: '<S58>/Constant'
   */
  t15_2_B.Compare_g = (uint8_T)(t15_2_B.e6 > t15_2_P.Constant_Value_d);

  /* Logic: '<S40>/Logical Operator1' */
  t15_2_B.LogicalOperator1 = ((t15_2_B.Compare_m != 0) && (t15_2_B.Compare_o !=
    0) && (t15_2_B.Compare_g != 0));

  /* Gain: '<S43>/atpl1//15' */
  t15_2_B.atpl115 = t15_2_P.atpl115_Gain * t15_2_B.e6;

  /* Switch: '<S40>/0.99' incorporates:
   *  Switch: '<S7>/c_eob '
   */
  if (t15_2_B.LogicalOperator1 >= t15_2_P.u9_Threshold) {
    /* Gain: '<S7>/c_a_tpl1_eob//15' */
    t15_2_B.c_a_tpl1_eob15 = t15_2_P.c_a_tpl1_eob15_Gain * t15_2_B.e6;

    /* Saturate: '<S7>/Saturation4' */
    tmin = t15_2_B.c_a_tpl1_eob15;
    u_0 = t15_2_P.Saturation4_LowerSat;
    u_1 = t15_2_P.Saturation4_UpperSat;
    if (tmin >= u_1) {
      t15_2_B.Saturation4 = u_1;
    } else if (tmin <= u_0) {
      t15_2_B.Saturation4 = u_0;
    } else {
      t15_2_B.Saturation4 = tmin;
    }

    /* End of Saturate: '<S7>/Saturation4' */

    /* Product: '<S7>/Divide11' */
    t15_2_B.Divide11[0] = t15_2_B.Saturation4 * t15_2_B.c_eob[0];
    t15_2_B.Divide11[1] = t15_2_B.Saturation4 * t15_2_B.c_eob[1];
    t15_2_B.u9[0] = t15_2_B.Divide11[0];
    t15_2_B.u9[1] = t15_2_B.Divide11[1];
  } else {
    if (t15_2_B.u > t15_2_P.c_eob_Threshold_f) {
      /* Switch: '<S43>/Ip>Ip_div' incorporates:
       *  Switch: '<S7>/c_eob '
       */
      if (t15_2_B.e6 > t15_2_P.IpIp_div_Threshold) {
        /* Saturate: '<S43>/Sat. Div' */
        tmin = t15_2_B.atpl115;
        u_0 = t15_2_P.SatDiv_LowerSat;
        u_1 = t15_2_P.SatDiv_UpperSat;
        if (tmin >= u_1) {
          t15_2_B.SatDiv = u_1;
        } else if (tmin <= u_0) {
          t15_2_B.SatDiv = u_0;
        } else {
          t15_2_B.SatDiv = tmin;
        }

        /* End of Saturate: '<S43>/Sat. Div' */
        t15_2_B.IpIp_div_m = t15_2_B.SatDiv;
      } else {
        /* Saturate: '<S43>/Sat. Lim' */
        tmin = t15_2_B.atpl115;
        u_0 = t15_2_P.SatLim_LowerSat;
        u_1 = t15_2_P.SatLim_UpperSat;
        if (tmin >= u_1) {
          t15_2_B.SatLim = u_1;
        } else if (tmin <= u_0) {
          t15_2_B.SatLim = u_0;
        } else {
          t15_2_B.SatLim = tmin;
        }

        /* End of Saturate: '<S43>/Sat. Lim' */
        t15_2_B.IpIp_div_m = t15_2_B.SatLim;
      }

      /* End of Switch: '<S43>/Ip>Ip_div' */

      /* Product: '<S7>/Divide8' incorporates:
       *  Switch: '<S7>/c_eob '
       */
      t15_2_B.Divide8[0] = t15_2_B.IpIp_div_m * t15_2_B.c_eob[0];
      t15_2_B.Divide8[1] = t15_2_B.IpIp_div_m * t15_2_B.c_eob[1];

      /* Switch: '<S7>/c_eob ' */
      t15_2_B.c_eob_lu[0] = t15_2_B.Divide8[0];
      t15_2_B.c_eob_lu[1] = t15_2_B.Divide8[1];
    } else {
      /* Gain: '<S7>/1//15' incorporates:
       *  Switch: '<S7>/c_eob '
       */
      t15_2_B.u5 = t15_2_P.u5_Gain * t15_2_B.e6;

      /* Saturate: '<S7>/Saturation3' incorporates:
       *  Switch: '<S7>/c_eob '
       */
      tmin = t15_2_B.u5;
      u_0 = t15_2_P.Saturation3_LowerSat;
      u_1 = t15_2_P.Saturation3_UpperSat;
      if (tmin >= u_1) {
        t15_2_B.Saturation3 = u_1;
      } else if (tmin <= u_0) {
        t15_2_B.Saturation3 = u_0;
      } else {
        t15_2_B.Saturation3 = tmin;
      }

      /* End of Saturate: '<S7>/Saturation3' */

      /* Product: '<S7>/Divide9' incorporates:
       *  Switch: '<S7>/c_eob '
       */
      t15_2_B.Divide9[0] = t15_2_B.c_eob[0] * t15_2_B.Saturation3;
      t15_2_B.Divide9[1] = t15_2_B.c_eob[1] * t15_2_B.Saturation3;

      /* Switch: '<S7>/c_eob ' */
      t15_2_B.c_eob_lu[0] = t15_2_B.Divide9[0];
      t15_2_B.c_eob_lu[1] = t15_2_B.Divide9[1];
    }

    t15_2_B.u9[0] = t15_2_B.c_eob_lu[0];
    t15_2_B.u9[1] = t15_2_B.c_eob_lu[1];
  }

  /* End of Switch: '<S40>/0.99' */

  /* Product: '<S7>/Divide10' */
  t15_2_B.Divide10[0] = t15_2_B.Subtract4 * t15_2_B.u9[0];
  t15_2_B.Divide10[1] = t15_2_B.Subtract4 * t15_2_B.u9[1];

  /* Saturate: '<S3>/Saturation VS1' */
  tmin = t15_2_B.Divide10[0];
  u_0 = t15_2_P.SaturationVS1_LowerSat;
  u_1 = t15_2_P.SaturationVS1_UpperSat;
  if (tmin >= u_1) {
    t15_2_B.SaturationVS1 = u_1;
  } else if (tmin <= u_0) {
    t15_2_B.SaturationVS1 = u_0;
  } else {
    t15_2_B.SaturationVS1 = tmin;
  }

  /* End of Saturate: '<S3>/Saturation VS1' */

  /* Saturate: '<S3>/Saturation VS3' */
  tmin = t15_2_B.Divide10[1];
  u_0 = t15_2_P.SaturationVS3_LowerSat;
  u_1 = t15_2_P.SaturationVS3_UpperSat;
  if (tmin >= u_1) {
    t15_2_B.SaturationVS3 = u_1;
  } else if (tmin <= u_0) {
    t15_2_B.SaturationVS3 = u_0;
  } else {
    t15_2_B.SaturationVS3 = tmin;
  }

  /* End of Saturate: '<S3>/Saturation VS3' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtwzInport1' */
  t15_2_B.TmpSignalConversionAtwzInport1[0] = t15_2_B.SaturationVS1;
  t15_2_B.TmpSignalConversionAtwzInport1[1] = t15_2_B.SaturationVS3;

  /* Gain: '<S1>/wz' */
  for (i = 0; i < 12; i++) {
    t15_2_B.wz[i] = 0.0;
    t15_2_B.wz[i] += t15_2_P.wz_Gain[i] *
      t15_2_B.TmpSignalConversionAtwzInport1[0];
    t15_2_B.wz[i] += t15_2_P.wz_Gain[i + 12] *
      t15_2_B.TmpSignalConversionAtwzInport1[1];
  }

  for (i = 0; i < 11; i++) {
    /* Sum: '<S1>/Add1' */
    t15_2_B.Add1_k[i] = t15_2_B.ntur[i] + t15_2_B.wz[i];

    /* SignalConversion: '<S1>/TmpSignal ConversionAtnpf,12Inport1' */
    t15_2_B.TmpSignalConversionAtnpf12Inpor[i] = t15_2_B.Add1_k[i];
  }

  /* End of Gain: '<S1>/wz' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtnpf,12Inport1' */
  t15_2_B.TmpSignalConversionAtnpf12Inpor[11] = t15_2_B.wz[11];
  for (i = 0; i < 15; i++) {
    /* Gain: '<S1>/npf,12' */
    t15_2_B.npf12[i] = 0.0;
    for (i_0 = 0; i_0 < 12; i_0++) {
      t15_2_B.npf12[i] += t15_2_P.npf12_Gain[15 * i_0 + i] *
        t15_2_B.TmpSignalConversionAtnpf12Inpor[i_0];
    }

    /* End of Gain: '<S1>/npf,12' */

    /* Outport: '<Root>/to_DINA' */
    t15_2_Y.to_DINA[i] = t15_2_B.npf12[i];
  }

  /* Outport: '<Root>/to_DINA' */
  memcpy(&t15_2_Y.to_DINA[15], &t15_2_B.ntur[0], 11U * sizeof(real_T));
  memcpy(&t15_2_Y.to_DINA[26], &t15_2_B.wz[0], 12U * sizeof(real_T));

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Tfmc'
   */
  t15_2_B.Add = t15_2_B.Diff + t15_2_P.Tfmc_Value;

  /* RelationalOperator: '<S51>/Compare' incorporates:
   *  Constant: '<S51>/Constant'
   */
  t15_2_B.Compare_p = (uint8_T)(t15_2_B.e6 < t15_2_P.Constant_Value_kb);

  /* RelationalOperator: '<S52>/Compare' incorporates:
   *  Constant: '<S52>/Constant'
   */
  t15_2_B.Compare_e = (uint8_T)(t15_2_B.e3 > t15_2_P.Constant_Value_n);

  /* Logic: '<S37>/Logical Operator2' */
  t15_2_B.LogicalOperator2_g = ((t15_2_B.Compare_p != 0) && (t15_2_B.Compare_e
    != 0));
  for (i = 0; i < 11; i++) {
    /* Memory: '<S37>/Memory1' */
    t15_2_B.Memory1_b[i] = t15_2_DWork.Memory1_PreviousInput_p[i];

    /* Memory: '<S39>/Memory' */
    t15_2_B.Memory_l[i] = t15_2_DWork.Memory_PreviousInput_e[i];
  }

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Constant: '<S53>/Constant'
   */
  t15_2_B.Compare_i = (uint8_T)(t15_2_B.e6 < t15_2_P.Constant_Value_m);

  /* RelationalOperator: '<S54>/Compare' incorporates:
   *  Constant: '<S54>/Constant'
   */
  t15_2_B.Compare_b = (uint8_T)(t15_2_B.e3 > t15_2_P.Constant_Value_a);

  /* RelationalOperator: '<S55>/Compare' incorporates:
   *  Constant: '<S55>/Constant'
   */
  t15_2_B.Compare_d = (uint8_T)(t15_2_B.e6 > t15_2_P.Constant_Value_j);

  /* Logic: '<S39>/Logical Operator1' */
  t15_2_B.LogicalOperator1_b = ((t15_2_B.Compare_i != 0) && (t15_2_B.Compare_b
    != 0) && (t15_2_B.Compare_d != 0));

  /* Memory: '<S48>/Memory3' */
  t15_2_B.Memory3 = t15_2_DWork.Memory3_PreviousInput;

  /* RelationalOperator: '<S63>/Compare' incorporates:
   *  Constant: '<S63>/Constant'
   */
  t15_2_B.Compare_f = (uint8_T)(t15_2_B.e6 > t15_2_P.Constant_Value_l);

  /* RelationalOperator: '<S64>/Compare' incorporates:
   *  Constant: '<S64>/Constant'
   */
  t15_2_B.Compare_n = (uint8_T)(t15_2_B.e3 > t15_2_P.Constant_Value_o);

  /* Logic: '<S48>/Logical Operator1' */
  t15_2_B.LogicalOperator1_e = ((t15_2_B.Compare_f != 0) || (t15_2_B.Compare_n
    != 0));

  /* Switch: '<S48>/0.9999' */
  if (t15_2_B.LogicalOperator1_e > t15_2_P.u999_Threshold) {
    t15_2_B.u999 = t15_2_B.Memory3;
  } else {
    t15_2_B.u999 = t15_2_B.e3;
  }

  /* End of Switch: '<S48>/0.9999' */

  /* Sum: '<S48>/Subtract2' */
  t15_2_B.Subtract2 = t15_2_B.e3 - t15_2_B.u999;

  /* Gain: '<S48>/Gain1' */
  t15_2_B.Gain1 = t15_2_P.Gain1_Gain_l2 * t15_2_B.Subtract2;

  /* Sum: '<S48>/Subtract1' incorporates:
   *  Constant: '<S48>/1'
   */
  t15_2_B.Subtract1 = t15_2_B.Gain1 + t15_2_P._Value_f;

  /* Saturate: '<S48>/Saturation1' */
  tmin = t15_2_B.Subtract1;
  u_0 = t15_2_P.Saturation1_LowerSat;
  u_1 = t15_2_P.Saturation1_UpperSat;
  if (tmin >= u_1) {
    t15_2_B.Saturation1 = u_1;
  } else if (tmin <= u_0) {
    t15_2_B.Saturation1 = u_0;
  } else {
    t15_2_B.Saturation1 = tmin;
  }

  /* End of Saturate: '<S48>/Saturation1' */

  /* Sum: '<S8>/Sum2' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_B.Sum2 = t15_2_U.In1[5] - t15_2_U.In1[7];

  /* Switch: '<S8>/>=0' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (t15_2_B.Sum2 >= t15_2_P.u_Threshold) {
    t15_2_B.u_i = t15_2_U.In1[7];
  } else {
    t15_2_B.u_i = t15_2_U.In1[5];
  }

  /* End of Switch: '<S8>/>=0' */

  /* Gain: '<S11>/1e2' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  t15_2_B.e2[0] = t15_2_P.e2_Gain * t15_2_U.In2[0];
  t15_2_B.e2[1] = t15_2_P.e2_Gain * t15_2_U.In2[1];
  t15_2_B.e2[2] = t15_2_P.e2_Gain * t15_2_U.In1[6];
  t15_2_B.e2[3] = t15_2_P.e2_Gain * t15_2_U.In2[3];
  t15_2_B.e2[4] = t15_2_P.e2_Gain * t15_2_U.In2[4];
  t15_2_B.e2[5] = t15_2_P.e2_Gain * t15_2_B.u_i;

  /* Memory: '<S26>/Memory1' */
  t15_2_B.Memory1_k = t15_2_DWork.Memory1_PreviousInput_c;

  /* Switch: '<S26>/c_eob  ' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_l) {
    t15_2_B.c_eob_l = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_l = t15_2_B.Memory1_k;
  }

  /* End of Switch: '<S26>/c_eob  ' */

  /* Switch: '<S26>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_o) {
    /* Lookup: '<S26>/g1_ref' */
    t15_2_B.g1_ref = rt_Lookup(t15_2_P.g1_ref_XData, 5, t15_2_B.e3,
      t15_2_P.g1_ref_YData);
    t15_2_B.c_eob_n = t15_2_B.g1_ref;
  } else {
    /* Sum: '<S26>/Add2' */
    t15_2_B.Add2_o = t15_2_B.e3 - t15_2_B.c_eob_l;

    /* Lookup: '<S26>/g1_ref_term' */
    t15_2_B.g1_ref_term = rt_Lookup(t15_2_P.g1_ref_term_XData, 2, t15_2_B.Add2_o,
      t15_2_P.g1_ref_term_YData);
    t15_2_B.c_eob_n = t15_2_B.g1_ref_term;
  }

  /* End of Switch: '<S26>/c_eob' */

  /* Sum: '<S11>/Add2' */
  t15_2_B.Add2_m = t15_2_B.e2[0] - t15_2_B.c_eob_n;

  /* Lookup: '<S11>/Lookup Table1' */
  t15_2_B.LookupTable1 = rt_Lookup(t15_2_P.LookupTable1_XData, 4, t15_2_B.e3,
    t15_2_P.LookupTable1_YData);

  /* Product: '<S11>/Divide6' */
  t15_2_B.Divide6 = t15_2_B.Add2_m * t15_2_B.LookupTable1;

  /* Memory: '<S27>/Memory1' */
  t15_2_B.Memory1_m = t15_2_DWork.Memory1_PreviousInput_d;

  /* Switch: '<S27>/c_eob ' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_h) {
    t15_2_B.c_eob_p = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_p = t15_2_B.Memory1_m;
  }

  /* End of Switch: '<S27>/c_eob ' */

  /* Switch: '<S27>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_e) {
    /* Lookup: '<S27>/g2_ref' */
    t15_2_B.g2_ref = rt_Lookup(t15_2_P.g2_ref_XData, 5, t15_2_B.e3,
      t15_2_P.g2_ref_YData);
    t15_2_B.c_eob_o = t15_2_B.g2_ref;
  } else {
    /* Sum: '<S27>/Add2' */
    t15_2_B.Add2_k = t15_2_B.e3 - t15_2_B.c_eob_p;

    /* Lookup: '<S27>/g2_ref_term' */
    t15_2_B.g2_ref_term = rt_Lookup(t15_2_P.g2_ref_term_XData, 3, t15_2_B.Add2_k,
      t15_2_P.g2_ref_term_YData);
    t15_2_B.c_eob_o = t15_2_B.g2_ref_term;
  }

  /* End of Switch: '<S27>/c_eob' */

  /* Sum: '<S11>/Add1' */
  t15_2_B.Add1_o = t15_2_B.e2[1] - t15_2_B.c_eob_o;

  /* Lookup: '<S11>/Lookup Table2' */
  t15_2_B.LookupTable2 = rt_Lookup(t15_2_P.LookupTable2_XData, 4, t15_2_B.e3,
    t15_2_P.LookupTable2_YData);

  /* Product: '<S11>/Divide1' */
  t15_2_B.Divide1_h = t15_2_B.Add1_o * t15_2_B.LookupTable2;

  /* Memory: '<S28>/Memory1' */
  t15_2_B.Memory1_f = t15_2_DWork.Memory1_PreviousInput_i;

  /* Switch: '<S28>/c_eob ' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_fw) {
    t15_2_B.c_eob_p2 = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_p2 = t15_2_B.Memory1_f;
  }

  /* End of Switch: '<S28>/c_eob ' */

  /* Switch: '<S28>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_l5) {
    /* Lookup: '<S28>/g3_ref' */
    t15_2_B.g3_ref = rt_Lookup(t15_2_P.g3_ref_XData, 9, t15_2_B.e3,
      t15_2_P.g3_ref_YData);
    t15_2_B.c_eob_g = t15_2_B.g3_ref;
  } else {
    /* Sum: '<S28>/Add2' */
    t15_2_B.Add2_m5 = t15_2_B.e3 - t15_2_B.c_eob_p2;

    /* Lookup: '<S28>/g3_ref_term' */
    t15_2_B.g3_ref_term = rt_Lookup(t15_2_P.g3_ref_term_XData, 4,
      t15_2_B.Add2_m5, t15_2_P.g3_ref_term_YData);
    t15_2_B.c_eob_g = t15_2_B.g3_ref_term;
  }

  /* End of Switch: '<S28>/c_eob' */

  /* Sum: '<S11>/Add3' */
  t15_2_B.Add3_j = t15_2_B.e2[2] - t15_2_B.c_eob_g;

  /* Memory: '<S29>/Memory1' */
  t15_2_B.Memory1_fr = t15_2_DWork.Memory1_PreviousInput_g;

  /* Switch: '<S29>/c_eob  ' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_b) {
    t15_2_B.c_eob_ln = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_ln = t15_2_B.Memory1_fr;
  }

  /* End of Switch: '<S29>/c_eob  ' */

  /* Switch: '<S29>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_ek) {
    /* Lookup: '<S29>/g4_ref' */
    t15_2_B.g4_ref = rt_Lookup(t15_2_P.g4_ref_XData, 6, t15_2_B.e3,
      t15_2_P.g4_ref_YData);
    t15_2_B.c_eob_pr = t15_2_B.g4_ref;
  } else {
    /* Sum: '<S29>/Add2' */
    t15_2_B.Add2_h = t15_2_B.e3 - t15_2_B.c_eob_ln;

    /* Lookup: '<S29>/g4_ref_term' */
    t15_2_B.g4_ref_term = rt_Lookup(t15_2_P.g4_ref_term_XData, 4, t15_2_B.Add2_h,
      t15_2_P.g4_ref_term_YData);
    t15_2_B.c_eob_pr = t15_2_B.g4_ref_term;
  }

  /* End of Switch: '<S29>/c_eob' */

  /* Sum: '<S11>/Add4' */
  t15_2_B.Add4 = t15_2_B.e2[3] - t15_2_B.c_eob_pr;

  /* Lookup: '<S11>/Lookup Table3' */
  t15_2_B.LookupTable3 = rt_Lookup(t15_2_P.LookupTable3_XData, 4, t15_2_B.e3,
    t15_2_P.LookupTable3_YData);

  /* Product: '<S11>/Divide2' */
  t15_2_B.Divide2 = t15_2_B.Add4 * t15_2_B.LookupTable3;

  /* Memory: '<S30>/Memory1' */
  t15_2_B.Memory1_bc = t15_2_DWork.Memory1_PreviousInput_gg;

  /* Switch: '<S30>/c_eob  ' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_la) {
    t15_2_B.c_eob_j = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_j = t15_2_B.Memory1_bc;
  }

  /* End of Switch: '<S30>/c_eob  ' */

  /* Switch: '<S30>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_i) {
    /* Lookup: '<S30>/g5_ref' */
    t15_2_B.g5_ref = rt_Lookup(t15_2_P.g5_ref_XData, 5, t15_2_B.e3,
      t15_2_P.g5_ref_YData);
    t15_2_B.c_eob_js = t15_2_B.g5_ref;
  } else {
    /* Sum: '<S30>/Add2' */
    t15_2_B.Add2_f = t15_2_B.e3 - t15_2_B.c_eob_j;

    /* Lookup: '<S30>/g5_ref_term' */
    t15_2_B.g5_ref_term = rt_Lookup(t15_2_P.g5_ref_term_XData, 4, t15_2_B.Add2_f,
      t15_2_P.g5_ref_term_YData);
    t15_2_B.c_eob_js = t15_2_B.g5_ref_term;
  }

  /* End of Switch: '<S30>/c_eob' */

  /* Sum: '<S11>/Add5' */
  t15_2_B.Add5 = t15_2_B.e2[4] - t15_2_B.c_eob_js;

  /* Lookup: '<S31>/g6_ref' */
  t15_2_B.g6_ref = rt_Lookup(t15_2_P.g6_ref_XData, 8, t15_2_B.e3,
    t15_2_P.g6_ref_YData);

  /* Memory: '<S31>/Memory2' */
  t15_2_B.Memory2_k = t15_2_DWork.Memory2_PreviousInput_b;

  /* Switch: '<S31>/c_eob  1' */
  if (t15_2_B.u > t15_2_P.c_eob1_Threshold) {
    t15_2_B.c_eob1 = t15_2_B.g6_ref;
  } else {
    t15_2_B.c_eob1 = t15_2_B.Memory2_k;
  }

  /* End of Switch: '<S31>/c_eob  1' */

  /* Memory: '<S31>/Memory1' */
  t15_2_B.Memory1_o = t15_2_DWork.Memory1_PreviousInput_g2;

  /* Switch: '<S31>/c_eob  ' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_hf) {
    t15_2_B.c_eob_b = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_b = t15_2_B.Memory1_o;
  }

  /* End of Switch: '<S31>/c_eob  ' */

  /* Switch: '<S31>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_d) {
    t15_2_B.c_eob_a = t15_2_B.g6_ref;
  } else {
    /* Sum: '<S31>/Add2' */
    t15_2_B.Add2_i = t15_2_B.e3 - t15_2_B.c_eob_b;

    /* Lookup: '<S31>/g6_ref_term' */
    t15_2_B.g6_ref_term = rt_Lookup(t15_2_P.g6_ref_term_XData, 3, t15_2_B.Add2_i,
      t15_2_P.g6_ref_term_YData);

    /* Sum: '<S31>/Add1' */
    t15_2_B.Add1_o1 = t15_2_B.c_eob1 - t15_2_B.g6_ref_term;
    t15_2_B.c_eob_a = t15_2_B.Add1_o1;
  }

  /* End of Switch: '<S31>/c_eob' */

  /* Sum: '<S11>/Add6' */
  t15_2_B.Add6 = t15_2_B.e2[5] - t15_2_B.c_eob_a;

  /* Gain: '<S11>/1e-2' */
  t15_2_B.e2_o[0] = t15_2_P.e2_Gain_k * t15_2_B.Divide6;
  t15_2_B.e2_o[1] = t15_2_P.e2_Gain_k * t15_2_B.Divide1_h;
  t15_2_B.e2_o[2] = t15_2_P.e2_Gain_k * t15_2_B.Add3_j;
  t15_2_B.e2_o[3] = t15_2_P.e2_Gain_k * t15_2_B.Divide2;
  t15_2_B.e2_o[4] = t15_2_P.e2_Gain_k * t15_2_B.Add5;
  t15_2_B.e2_o[5] = t15_2_P.e2_Gain_k * t15_2_B.Add6;

  /* S-Function (pf_lookup3): '<S10>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1[0], &t15_2_P.SFunction1_P1, 1);

  /* Memory: '<S10>/Memory1' */
  t15_2_B.Memory1_l = t15_2_DWork.Memory1_PreviousInput_j;

  /* Switch: '<S10>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_m) {
    /* Gain: '<S10>/Gain2' */
    memcpy(&u[0], &t15_2_P.Gain2_Gain[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain2_j[i] = y[i];
    }

    /* End of Gain: '<S10>/Gain2' */

    /* Gain: '<S10>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_l[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_k[i] = y[i];
    }

    /* End of Gain: '<S10>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S10>/Ipref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.Ipref_c), &t15_2_B.Gain2_j[0], t15_2_B.e3,
                         &t15_2_B.Gain1_k[0], 499U);
    t15_2_B.c_eob_h = t15_2_B.Ipref_c;
  } else {
    t15_2_B.c_eob_h = t15_2_B.Memory1_l;
  }

  /* End of Switch: '<S10>/c_eob' */

  /* Product: '<S10>/Divide6' */
  t15_2_B.Divide6_m = t15_2_B.c_eob_h * t15_2_B.u;

  /* Sum: '<S6>/Add1' */
  t15_2_B.Add1_m = t15_2_B.e6 - t15_2_B.Divide6_m;

  /* S-Function (pf_lookup3): '<S15>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_m[0], &t15_2_P.SFunction1_P1_g,
    1);

  /* Memory: '<S15>/Memory2' */
  t15_2_B.Memory2_l = t15_2_DWork.Memory2_PreviousInput_l;

  /* Switch: '<S15>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_lg) {
    /* Gain: '<S15>/Gain4' */
    memcpy(&u[0], &t15_2_P.Gain4_Gain[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_m[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain4_n[i] = y[i];
    }

    /* End of Gain: '<S15>/Gain4' */

    /* Gain: '<S15>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_m[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_n[i] = y[i];
    }

    /* End of Gain: '<S15>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S15>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1), &t15_2_B.Gain4_n[0], t15_2_B.e3,
                         &t15_2_B.Gain1_n[0], 499U);
    t15_2_B.c_eob_k = t15_2_B.I1;
  } else {
    t15_2_B.c_eob_k = t15_2_B.Memory2_l;
  }

  /* End of Switch: '<S15>/c_eob' */

  /* Product: '<S15>/Divide1' */
  t15_2_B.Divide1_n = t15_2_B.c_eob_k * t15_2_B.u;

  /* Sum: '<S9>/Add3' */
  t15_2_B.Add3_n = t15_2_B.e6_m[0] - t15_2_B.Divide1_n;

  /* S-Function (pf_lookup3): '<S18>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_d[0], &t15_2_P.SFunction1_P1_p,
    1);

  /* Memory: '<S18>/Memory2' */
  t15_2_B.Memory2_l4 = t15_2_DWork.Memory2_PreviousInput_p;

  /* Switch: '<S18>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_k) {
    /* Gain: '<S18>/Gain4' */
    memcpy(&u[0], &t15_2_P.Gain4_Gain_b[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_d[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain4_m[i] = y[i];
    }

    /* End of Gain: '<S18>/Gain4' */

    /* Gain: '<S18>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_m[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_d[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_ag[i] = y[i];
    }

    /* End of Gain: '<S18>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S18>/I2'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I2), &t15_2_B.Gain4_m[0], t15_2_B.e3,
                         &t15_2_B.Gain1_ag[0], 499U);
    t15_2_B.c_eob_i = t15_2_B.I2;
  } else {
    t15_2_B.c_eob_i = t15_2_B.Memory2_l4;
  }

  /* End of Switch: '<S18>/c_eob' */

  /* Product: '<S18>/Divide1' */
  t15_2_B.Divide1_j = t15_2_B.c_eob_i * t15_2_B.u;

  /* Sum: '<S9>/Add1' */
  t15_2_B.Add1_h = t15_2_B.e6_m[1] - t15_2_B.Divide1_j;

  /* S-Function (pf_lookup3): '<S19>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_k[0], &t15_2_P.SFunction1_P1_d,
    1);

  /* Memory: '<S19>/Memory2' */
  t15_2_B.Memory2_h = t15_2_DWork.Memory2_PreviousInput_c;

  /* Switch: '<S19>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_hz) {
    /* Gain: '<S19>/Gain4' */
    memcpy(&u[0], &t15_2_P.Gain4_Gain_l[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_k[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain4_k[i] = y[i];
    }

    /* End of Gain: '<S19>/Gain4' */

    /* Gain: '<S19>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_n[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_k[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_mh[i] = y[i];
    }

    /* End of Gain: '<S19>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S19>/I3'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I3), &t15_2_B.Gain4_k[0], t15_2_B.e3,
                         &t15_2_B.Gain1_mh[0], 499U);
    t15_2_B.c_eob_ls = t15_2_B.I3;
  } else {
    t15_2_B.c_eob_ls = t15_2_B.Memory2_h;
  }

  /* End of Switch: '<S19>/c_eob' */

  /* Product: '<S19>/Divide1' */
  t15_2_B.Divide1_l = t15_2_B.c_eob_ls * t15_2_B.u;

  /* Sum: '<S9>/Add2' */
  t15_2_B.Add2_d = t15_2_B.e6_m[2] - t15_2_B.Divide1_l;

  /* S-Function (pf_lookup3): '<S20>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_l[0], &t15_2_P.SFunction1_P1_c,
    1);

  /* Memory: '<S20>/Memory2' */
  t15_2_B.Memory2_m = t15_2_DWork.Memory2_PreviousInput_bw;

  /* Switch: '<S20>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_g) {
    /* Gain: '<S20>/Gain4' */
    memcpy(&u[0], &t15_2_P.Gain4_Gain_bt[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_l[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain4_j[i] = y[i];
    }

    /* End of Gain: '<S20>/Gain4' */

    /* Gain: '<S20>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_k[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_l[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_m[i] = y[i];
    }

    /* End of Gain: '<S20>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S20>/I4'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I4), &t15_2_B.Gain4_j[0], t15_2_B.e3,
                         &t15_2_B.Gain1_m[0], 499U);
    t15_2_B.c_eob_pk = t15_2_B.I4;
  } else {
    t15_2_B.c_eob_pk = t15_2_B.Memory2_m;
  }

  /* End of Switch: '<S20>/c_eob' */

  /* Product: '<S20>/Divide1' */
  t15_2_B.Divide1_g = t15_2_B.c_eob_pk * t15_2_B.u;

  /* Sum: '<S9>/Add4' */
  t15_2_B.Add4_l = t15_2_B.e6_m[3] - t15_2_B.Divide1_g;

  /* S-Function (pf_lookup3): '<S21>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_g[0],
    &t15_2_P.SFunction1_P1_dp, 1);

  /* Memory: '<S21>/Memory2' */
  t15_2_B.Memory2_ha = t15_2_DWork.Memory2_PreviousInput_m;

  /* Switch: '<S21>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_fx) {
    /* Gain: '<S21>/Gain4' */
    memcpy(&u[0], &t15_2_P.Gain4_Gain_g[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_g[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain4_l[i] = y[i];
    }

    /* End of Gain: '<S21>/Gain4' */

    /* Gain: '<S21>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_o[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_g[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_b[i] = y[i];
    }

    /* End of Gain: '<S21>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S21>/I5'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I5), &t15_2_B.Gain4_l[0], t15_2_B.e3,
                         &t15_2_B.Gain1_b[0], 499U);
    t15_2_B.c_eob_ir = t15_2_B.I5;
  } else {
    t15_2_B.c_eob_ir = t15_2_B.Memory2_ha;
  }

  /* End of Switch: '<S21>/c_eob' */

  /* Product: '<S21>/Divide1' */
  t15_2_B.Divide1_i = t15_2_B.c_eob_ir * t15_2_B.u;

  /* Sum: '<S9>/Add5' */
  t15_2_B.Add5_i = t15_2_B.e6_m[4] - t15_2_B.Divide1_i;

  /* Lookup: '<S9>/Lookup Table1' */
  t15_2_B.LookupTable1_a = rt_Lookup(t15_2_P.LookupTable1_XData_o, 4, t15_2_B.e3,
    t15_2_P.LookupTable1_YData_c);

  /* Product: '<S9>/Divide6' */
  t15_2_B.Divide6_f = t15_2_B.Add5_i * t15_2_B.LookupTable1_a;

  /* S-Function (pf_lookup3): '<S22>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_i[0], &t15_2_P.SFunction1_P1_b,
    1);

  /* Memory: '<S22>/Memory2' */
  t15_2_B.Memory2_c = t15_2_DWork.Memory2_PreviousInput_e;

  /* Switch: '<S22>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_n) {
    /* Gain: '<S22>/Gain4' */
    memcpy(&u[0], &t15_2_P.Gain4_Gain_h[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_i[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain4_a3[i] = y[i];
    }

    /* End of Gain: '<S22>/Gain4' */

    /* Gain: '<S22>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_h[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_i[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_a1[i] = y[i];
    }

    /* End of Gain: '<S22>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S22>/I6'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I6), &t15_2_B.Gain4_a3[0], t15_2_B.e3,
                         &t15_2_B.Gain1_a1[0], 499U);
    t15_2_B.c_eob_hr = t15_2_B.I6;
  } else {
    t15_2_B.c_eob_hr = t15_2_B.Memory2_c;
  }

  /* End of Switch: '<S22>/c_eob' */

  /* Product: '<S22>/Divide1' */
  t15_2_B.Divide1_jl = t15_2_B.c_eob_hr * t15_2_B.u;

  /* Sum: '<S9>/Add6' */
  t15_2_B.Add6_b = t15_2_B.e6_m[5] - t15_2_B.Divide1_jl;

  /* S-Function (pf_lookup3): '<S23>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_ko[0],
    &t15_2_P.SFunction1_P1_n, 1);

  /* Memory: '<S23>/Memory2' */
  t15_2_B.Memory2_f = t15_2_DWork.Memory2_PreviousInput_lu;

  /* Switch: '<S23>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_gu) {
    /* Gain: '<S23>/Gain4' */
    memcpy(&u[0], &t15_2_P.Gain4_Gain_e[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_ko[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain4_a[i] = y[i];
    }

    /* End of Gain: '<S23>/Gain4' */

    /* Gain: '<S23>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_b[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_ko[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_a[i] = y[i];
    }

    /* End of Gain: '<S23>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S23>/I7'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I7), &t15_2_B.Gain4_a[0], t15_2_B.e3,
                         &t15_2_B.Gain1_a[0], 499U);
    t15_2_B.c_eob_ng = t15_2_B.I7;
  } else {
    t15_2_B.c_eob_ng = t15_2_B.Memory2_f;
  }

  /* End of Switch: '<S23>/c_eob' */

  /* Product: '<S23>/Divide1' */
  t15_2_B.Divide1_a = t15_2_B.c_eob_ng * t15_2_B.u;

  /* Sum: '<S9>/Add7' */
  t15_2_B.Add7 = t15_2_B.e6_m[6] - t15_2_B.Divide1_a;

  /* S-Function (pf_lookup3): '<S24>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_lj[0],
    &t15_2_P.SFunction1_P1_nl, 1);

  /* Memory: '<S24>/Memory2' */
  t15_2_B.Memory2_j = t15_2_DWork.Memory2_PreviousInput_h;

  /* Switch: '<S24>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_fg) {
    /* Gain: '<S24>/Gain4' */
    memcpy(&u[0], &t15_2_P.Gain4_Gain_nj[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_lj[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain4_i[i] = y[i];
    }

    /* End of Gain: '<S24>/Gain4' */

    /* Gain: '<S24>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_dt[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_lj[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_jd[i] = y[i];
    }

    /* End of Gain: '<S24>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S24>/I8'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I8), &t15_2_B.Gain4_i[0], t15_2_B.e3,
                         &t15_2_B.Gain1_jd[0], 499U);
    t15_2_B.c_eob_ni = t15_2_B.I8;
  } else {
    t15_2_B.c_eob_ni = t15_2_B.Memory2_j;
  }

  /* End of Switch: '<S24>/c_eob' */

  /* Product: '<S24>/Divide1' */
  t15_2_B.Divide1_p = t15_2_B.c_eob_ni * t15_2_B.u;

  /* Sum: '<S9>/Add8' */
  t15_2_B.Add8 = t15_2_B.e6_m[7] - t15_2_B.Divide1_p;

  /* S-Function (pf_lookup3): '<S25>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_e[0], &t15_2_P.SFunction1_P1_i,
    1);

  /* Memory: '<S25>/Memory2' */
  t15_2_B.Memory2_p = t15_2_DWork.Memory2_PreviousInput_g;

  /* Switch: '<S25>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_g2) {
    /* Gain: '<S25>/Gain4' */
    memcpy(&u[0], &t15_2_P.Gain4_Gain_ge[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_e[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain4[i] = y[i];
    }

    /* End of Gain: '<S25>/Gain4' */

    /* Gain: '<S25>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_dg[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_e[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_h4[i] = y[i];
    }

    /* End of Gain: '<S25>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S25>/I9'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I9), &t15_2_B.Gain4[0], t15_2_B.e3,
                         &t15_2_B.Gain1_h4[0], 499U);
    t15_2_B.c_eob_id = t15_2_B.I9;
  } else {
    t15_2_B.c_eob_id = t15_2_B.Memory2_p;
  }

  /* End of Switch: '<S25>/c_eob' */

  /* Product: '<S25>/Divide1' */
  t15_2_B.Divide1_lm = t15_2_B.c_eob_id * t15_2_B.u;

  /* Sum: '<S9>/Add9' */
  t15_2_B.Add9 = t15_2_B.e6_m[8] - t15_2_B.Divide1_lm;

  /* S-Function (pf_lookup3): '<S16>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_h[0],
    &t15_2_P.SFunction1_P1_bx, 1);

  /* Memory: '<S16>/Memory2' */
  t15_2_B.Memory2_n = t15_2_DWork.Memory2_PreviousInput_f;

  /* Switch: '<S16>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_p) {
    /* Gain: '<S16>/Gain4' */
    memcpy(&u[0], &t15_2_P.Gain4_Gain_n[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_h[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain4_p[i] = y[i];
    }

    /* End of Gain: '<S16>/Gain4' */

    /* Gain: '<S16>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_d[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_h[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_l[i] = y[i];
    }

    /* End of Gain: '<S16>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S16>/I10'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I10), &t15_2_B.Gain4_p[0], t15_2_B.e3,
                         &t15_2_B.Gain1_l[0], 499U);
    t15_2_B.c_eob_jj = t15_2_B.I10;
  } else {
    t15_2_B.c_eob_jj = t15_2_B.Memory2_n;
  }

  /* End of Switch: '<S16>/c_eob' */

  /* Product: '<S16>/Divide1' */
  t15_2_B.Divide1_c = t15_2_B.c_eob_jj * t15_2_B.u;

  /* Sum: '<S9>/Add10' */
  t15_2_B.Add10 = t15_2_B.e6_m[9] - t15_2_B.Divide1_c;

  /* S-Function (pf_lookup3): '<S17>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_g4[0],
    &t15_2_P.SFunction1_P1_a, 1);

  /* Memory: '<S17>/Memory2' */
  t15_2_B.Memory2_kk = t15_2_DWork.Memory2_PreviousInput_d;

  /* Switch: '<S17>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_eb) {
    /* Gain: '<S17>/Gain4' */
    memcpy(&u[0], &t15_2_P.Gain4_Gain_f[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_g4[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain4_k5[i] = y[i];
    }

    /* End of Gain: '<S17>/Gain4' */

    /* Gain: '<S17>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_di[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_g4[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_ma[i] = y[i];
    }

    /* End of Gain: '<S17>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S17>/I11'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I11), &t15_2_B.Gain4_k5[0], t15_2_B.e3,
                         &t15_2_B.Gain1_ma[0], 499U);
    t15_2_B.c_eob_le = t15_2_B.I11;
  } else {
    t15_2_B.c_eob_le = t15_2_B.Memory2_kk;
  }

  /* End of Switch: '<S17>/c_eob' */

  /* Product: '<S17>/Divide1' */
  t15_2_B.Divide1_e = t15_2_B.c_eob_le * t15_2_B.u;

  /* Sum: '<S9>/Add11' */
  t15_2_B.Add11 = t15_2_B.e6_m[10] - t15_2_B.Divide1_e;

  /* RelationalOperator: '<S32>/Compare' incorporates:
   *  Constant: '<S32>/Constant'
   */
  t15_2_B.Compare_pn = (uint8_T)(t15_2_B.e6 > t15_2_P.Constant_Value_nu);

  /* RelationalOperator: '<S33>/Compare' incorporates:
   *  Constant: '<S33>/Constant'
   */
  t15_2_B.Compare_m5 = (uint8_T)(t15_2_B.e3 > t15_2_P.Constant_Value_dp);

  /* Logic: '<S13>/Logical Operator1' */
  t15_2_B.LogicalOperator1_i = ((t15_2_B.Compare_pn != 0) || (t15_2_B.Compare_m5
    != 0));

  /* Switch: '<S13>/0.99' incorporates:
   *  Constant: '<S6>/Constant4'
   */
  if (t15_2_B.LogicalOperator1_i >= t15_2_P.u9_Threshold_n) {
    for (i = 0; i < 6; i++) {
      t15_2_B.u9_g[i] = t15_2_B.e2_o[i];
    }

    t15_2_B.u9_g[6] = t15_2_P.Constant4_Value_f;
    t15_2_B.u9_g[7] = t15_2_B.Add1_m;
    t15_2_B.u9_g[8] = t15_2_B.Add3_n;
    t15_2_B.u9_g[9] = t15_2_B.Add1_h;
    t15_2_B.u9_g[10] = t15_2_B.Add2_d;
    t15_2_B.u9_g[11] = t15_2_B.Add4_l;
    t15_2_B.u9_g[12] = t15_2_B.Divide6_f;
    t15_2_B.u9_g[13] = t15_2_B.Add6_b;
    t15_2_B.u9_g[14] = t15_2_B.Add7;
    t15_2_B.u9_g[15] = t15_2_B.Add8;
    t15_2_B.u9_g[16] = t15_2_B.Add9;
    t15_2_B.u9_g[17] = t15_2_B.Add10;
    t15_2_B.u9_g[18] = t15_2_B.Add11;
    t15_2_B.u9_g[19] = t15_2_P.Constant4_Value_f;
  } else {
    /* Lookup: '<S6>/elong_ref' */
    t15_2_B.elong_ref = rt_Lookup(t15_2_P.elong_ref_XData, 7, t15_2_B.e3,
      t15_2_P.elong_ref_YData);

    /* Sum: '<S6>/Add2' incorporates:
     *  Inport: '<Root>/In1'
     */
    t15_2_B.Add2_a = t15_2_U.In1[2] - t15_2_B.elong_ref;

    /* Gain: '<S6>/k_gaplim' */
    t15_2_B.k_gaplim[0] = t15_2_P.k_gaplim_Gain[0] * t15_2_B.e2_o[2];
    t15_2_B.k_gaplim[1] = t15_2_P.k_gaplim_Gain[1] * t15_2_B.e2_o[3];
    t15_2_B.k_gaplim[2] = t15_2_P.k_gaplim_Gain[2] * t15_2_B.e2_o[4];
    t15_2_B.k_gaplim[3] = t15_2_P.k_gaplim_Gain[3] * t15_2_B.e2_o[5];
    t15_2_B.u9_g[0] = t15_2_B.Add2_a;
    t15_2_B.u9_g[1] = t15_2_P.Constant4_Value_f;
    t15_2_B.u9_g[2] = t15_2_B.k_gaplim[0];
    t15_2_B.u9_g[3] = t15_2_B.k_gaplim[1];
    t15_2_B.u9_g[4] = t15_2_B.k_gaplim[2];
    t15_2_B.u9_g[5] = t15_2_B.k_gaplim[3];
    t15_2_B.u9_g[6] = t15_2_P.Constant4_Value_f;
    t15_2_B.u9_g[7] = t15_2_B.Add1_m;
    t15_2_B.u9_g[8] = t15_2_B.Add3_n;
    t15_2_B.u9_g[9] = t15_2_B.Add1_h;
    t15_2_B.u9_g[10] = t15_2_B.Add2_d;
    t15_2_B.u9_g[11] = t15_2_B.Add4_l;
    t15_2_B.u9_g[12] = t15_2_B.Divide6_f;
    t15_2_B.u9_g[13] = t15_2_B.Add6_b;
    t15_2_B.u9_g[14] = t15_2_B.Add7;
    t15_2_B.u9_g[15] = t15_2_B.Add8;
    t15_2_B.u9_g[16] = t15_2_B.Add9;
    t15_2_B.u9_g[17] = t15_2_B.Add10;
    t15_2_B.u9_g[18] = t15_2_B.Add11;
    t15_2_B.u9_g[19] = t15_2_P.Constant4_Value_f;
  }

  /* End of Switch: '<S13>/0.99' */

  /* Product: '<S7>/Divide2' */
  for (i = 0; i < 20; i++) {
    t15_2_B.Divide2_i[i] = t15_2_B.LogicalOperator1_e * t15_2_B.u9_g[i];
  }

  /* End of Product: '<S7>/Divide2' */

  /* DiscreteStateSpace: '<S7>/Div. contr.' */
  {
    {
      static const int_T colCidxRow0[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = t15_2_P.Divcontr_C;
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
      const real_T *pD0 = t15_2_P.Divcontr_D;
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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

    t15_2_B.Divcontr[4] += (t15_2_P.Divcontr_D[68])*t15_2_B.Divide2_i[12];

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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      static const int_T colDidxRow10[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow10[0];
      const real_T *pD154 = &t15_2_P.Divcontr_D[154];
      const real_T *u = &t15_2_B.Divide2_i[0];
      real_T *y10 = &t15_2_B.Divcontr[10];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y10 += (*pD154++) * u[*pDidx++];
      }
    }
  }

  /* Switch: '<S39>/0.99' */
  if (t15_2_B.LogicalOperator1_b >= t15_2_P.u9_Threshold_g) {
    memcpy(&t15_2_B.u9_n[0], &t15_2_B.Memory_l[0], 11U * sizeof(real_T));
  } else {
    /* Sum: '<S48>/Subtract3' incorporates:
     *  Constant: '<S48>/1'
     */
    t15_2_B.Subtract3_f = t15_2_P._Value_f - t15_2_B.Saturation1;

    /* Product: '<S7>/Divide' */
    for (i = 0; i < 11; i++) {
      t15_2_B.Divide_i[i] = t15_2_B.Subtract3_f * t15_2_B.Divcontr[i];
      t15_2_B.u9_n[i] = t15_2_B.Divide_i[i];
    }

    /* End of Product: '<S7>/Divide' */
  }

  /* End of Switch: '<S39>/0.99' */

  /* Memory: '<S46>/Memory1' */
  t15_2_B.Memory1_e = t15_2_DWork.Memory1_PreviousInput_cn;

  /* RelationalOperator: '<S61>/Compare' incorporates:
   *  Constant: '<S61>/Constant'
   */
  t15_2_B.Compare_h = (uint8_T)(t15_2_B.e6 < t15_2_P.Constant_Value_jk);

  /* RelationalOperator: '<S62>/Compare' incorporates:
   *  Constant: '<S62>/Constant'
   */
  t15_2_B.Compare_j = (uint8_T)(t15_2_B.e3 > t15_2_P.Constant_Value_p);

  /* Logic: '<S46>/Logical Operator1' */
  t15_2_B.LogicalOperator1_n = ((t15_2_B.Compare_h != 0) && (t15_2_B.Compare_j
    != 0));

  /* Switch: '<S46>/0.9999' */
  if (t15_2_B.LogicalOperator1_n > t15_2_P.u999_Threshold_k) {
    t15_2_B.u999_f = t15_2_B.Memory1_e;
  } else {
    t15_2_B.u999_f = t15_2_B.e3;
  }

  /* End of Switch: '<S46>/0.9999' */

  /* Product: '<S7>/Divide13' */
  for (i = 0; i < 20; i++) {
    t15_2_B.Divide13[i] = t15_2_B.Divide2_i[i] * t15_2_B.LogicalOperator1_n;
  }

  /* End of Product: '<S7>/Divide13' */

  /* DiscreteStateSpace: '<S7>/Div_rd contr' */
  {
    {
      static const int_T colCidxRow0[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = t15_2_P.Div_rdcontr_C;
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
      const real_T *pD0 = t15_2_P.Div_rdcontr_D;
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      static const int_T colDidxRow10[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow10[0];
      const real_T *pD180 = &t15_2_P.Div_rdcontr_D[180];
      const real_T *u = &t15_2_B.Divide13[0];
      real_T *y10 = &t15_2_B.Div_rdcontr[10];
      int_T numNonZero = 18;
      while (numNonZero--) {
        *y10 += (*pD180++) * u[*pDidx++];
      }
    }
  }

  /* S-Function (pf_lookup3): '<S44>/S-Function1' */
  pf_lookup3_Outputs_wrapper( &t15_2_B.SFunction1_kc[0],
    &t15_2_P.SFunction1_P1_ph, 1);

  /* Memory: '<S44>/Memory1' */
  t15_2_B.Memory1_f1 = t15_2_DWork.Memory1_PreviousInput_i3;

  /* Switch: '<S44>/c_eob' */
  if (t15_2_B.u > t15_2_P.c_eob_Threshold_l4) {
    /* Gain: '<S44>/Gain2' */
    memcpy(&u[0], &t15_2_P.Gain2_Gain_k[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_kc[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain2[i] = y[i];
    }

    /* End of Gain: '<S44>/Gain2' */

    /* Gain: '<S44>/Gain1' */
    memcpy(&u[0], &t15_2_P.Gain1_Gain_l1[0], 13U * sizeof(real_T));
    memcpy(&t15_2_B.u1[0], &t15_2_B.SFunction1_kc[0], 6500U * sizeof(real_T));
    for (i = 0; i < 500; i++) {
      y[i] = 0.0;
      for (i_0 = 0; i_0 < 13; i_0++) {
        tmin = y[i];
        tmin += t15_2_B.u1[13 * i + i_0] * u[i_0];
        y[i] = tmin;
      }

      t15_2_B.Gain1_h[i] = y[i];
    }

    /* End of Gain: '<S44>/Gain1' */
    /* Dynamic Look-Up Table Block: '<S44>/Ipref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.Ipref), &t15_2_B.Gain2[0], t15_2_B.e3,
                         &t15_2_B.Gain1_h[0], 499U);
    t15_2_B.c_eob_jl = t15_2_B.Ipref;
  } else {
    t15_2_B.c_eob_jl = t15_2_B.Memory1_f1;
  }

  /* End of Switch: '<S44>/c_eob' */

  /* Switch: '<S37>/0.999' */
  if (t15_2_B.LogicalOperator2_g > t15_2_P.u99_Threshold) {
    memcpy(&t15_2_B.u99[0], &t15_2_B.Memory1_b[0], 11U * sizeof(real_T));
  } else {
    /* Sum: '<S46>/Subtract2' */
    t15_2_B.Subtract2_p = t15_2_B.e3 - t15_2_B.u999_f;

    /* Gain: '<S46>/Gain1' */
    t15_2_B.Gain1_i = t15_2_P.Gain1_Gain_c * t15_2_B.Subtract2_p;

    /* Sum: '<S46>/Subtract3' incorporates:
     *  Constant: '<S46>/1'
     */
    t15_2_B.Subtract3_k = t15_2_B.Gain1_i + t15_2_P._Value;

    /* Saturate: '<S46>/Saturation' */
    tmin = t15_2_B.Subtract3_k;
    u_0 = t15_2_P.Saturation_LowerSat_p;
    u_1 = t15_2_P.Saturation_UpperSat_f;
    if (tmin >= u_1) {
      t15_2_B.Saturation_c = u_1;
    } else if (tmin <= u_0) {
      t15_2_B.Saturation_c = u_0;
    } else {
      t15_2_B.Saturation_c = tmin;
    }

    /* End of Saturate: '<S46>/Saturation' */

    /* Sum: '<S46>/Subtract1' incorporates:
     *  Constant: '<S46>/1'
     */
    t15_2_B.Subtract1_h = t15_2_P._Value - t15_2_B.Saturation_c;

    /* Switch: '<S7>/c_eob' */
    if (t15_2_B.u > t15_2_P.c_eob_Threshold) {
      /* Gain: '<S7>/atpl2' */
      t15_2_B.atpl2 = t15_2_P.atpl2_Gain * t15_2_B.e6;

      /* Saturate: '<S7>/Saturation' */
      tmin = t15_2_B.atpl2;
      u_0 = t15_2_P.Saturation_LowerSat;
      u_1 = t15_2_P.Saturation_UpperSat;
      if (tmin >= u_1) {
        t15_2_B.Saturation_h = u_1;
      } else if (tmin <= u_0) {
        t15_2_B.Saturation_h = u_0;
      } else {
        t15_2_B.Saturation_h = tmin;
      }

      /* End of Saturate: '<S7>/Saturation' */
      t15_2_B.c_eob_oo = t15_2_B.Saturation_h;
    } else {
      /* Product: '<S44>/Divide6' */
      t15_2_B.Divide6_b2 = t15_2_B.c_eob_jl * t15_2_B.u;

      /* Sum: '<S44>/Sum' incorporates:
       *  Constant: '<S44>/c1_y0'
       */
      t15_2_B.Sum = t15_2_B.Divide6_b2 - t15_2_P.c1_y0_Value;

      /* Product: '<S44>/Divide2' incorporates:
       *  Constant: '<S44>/(1-y0)//...'
       */
      t15_2_B.Divide2_iq = t15_2_B.Sum * t15_2_P.uy0_Value;

      /* Sum: '<S44>/Sum1' incorporates:
       *  Constant: '<S44>/y0'
       */
      t15_2_B.Sum1_c = t15_2_B.Divide2_iq + t15_2_P.y0_Value;

      /* Saturate: '<S44>/[1 y0]' */
      tmin = t15_2_B.Sum1_c;
      u_0 = t15_2_P.uy0_LowerSat;
      u_1 = t15_2_P.uy0_UpperSat;
      if (tmin >= u_1) {
        t15_2_B.uy0 = u_1;
      } else if (tmin <= u_0) {
        t15_2_B.uy0 = u_0;
      } else {
        t15_2_B.uy0 = tmin;
      }

      /* End of Saturate: '<S44>/[1 y0]' */
      t15_2_B.c_eob_oo = t15_2_B.uy0;
    }

    for (i = 0; i < 11; i++) {
      /* Product: '<S7>/Divide3' */
      t15_2_B.Divide3_o[i] = t15_2_B.Div_rdcontr[i] * t15_2_B.c_eob_oo *
        t15_2_B.Subtract1_h;

      /* Product: '<S7>/Divide1' */
      t15_2_B.Divide1_f[i] = t15_2_B.u9_n[i] * t15_2_B.Saturation_c;

      /* Sum: '<S7>/Sum2' */
      t15_2_B.Sum2_m[i] = t15_2_B.Divide1_f[i] + t15_2_B.Divide3_o[i];
      t15_2_B.u99[i] = t15_2_B.Sum2_m[i];
    }

    /* End of Switch: '<S7>/c_eob' */
  }

  /* End of Switch: '<S37>/0.999' */

  /* Memory: '<S45>/Memory1' */
  t15_2_B.Memory1_l1 = t15_2_DWork.Memory1_PreviousInput_l;

  /* Switch: '<S45>/0.9999' */
  if (t15_2_B.LogicalOperator2 > t15_2_P.u999_Threshold_a) {
    t15_2_B.u999_l = t15_2_B.Memory1_l1;
  } else {
    t15_2_B.u999_l = t15_2_B.e3;
  }

  /* End of Switch: '<S45>/0.9999' */

  /* Sum: '<S45>/Subtract2' */
  t15_2_B.Subtract2_g = t15_2_B.e3 - t15_2_B.u999_l;

  /* Gain: '<S45>/Gain1' */
  t15_2_B.Gain1_j = t15_2_P.Gain1_Gain_g * t15_2_B.Subtract2_g;

  /* Sum: '<S45>/Subtract3' incorporates:
   *  Constant: '<S45>/1'
   */
  t15_2_B.Subtract3 = t15_2_B.Gain1_j + t15_2_P._Value_o;

  /* Saturate: '<S45>/Saturation' */
  tmin = t15_2_B.Subtract3;
  u_0 = t15_2_P.Saturation_LowerSat_f;
  u_1 = t15_2_P.Saturation_UpperSat_j;
  if (tmin >= u_1) {
    t15_2_B.Saturation = u_1;
  } else if (tmin <= u_0) {
    t15_2_B.Saturation = u_0;
  } else {
    t15_2_B.Saturation = tmin;
  }

  /* End of Saturate: '<S45>/Saturation' */

  /* DiscreteStateSpace: '<S7>/Curr. term. contr' */
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

  /* Sum: '<S45>/Subtract1' incorporates:
   *  Constant: '<S45>/1'
   */
  t15_2_B.Subtract1_i = t15_2_P._Value_o - t15_2_B.Saturation;
  for (i = 0; i < 11; i++) {
    /* Product: '<S7>/Divide4' */
    t15_2_B.Divide4_k[i] = t15_2_B.u99[i] * t15_2_B.Saturation;

    /* Product: '<S7>/Divide5' */
    t15_2_B.Divide5[i] = t15_2_B.Currtermcontr[i] * t15_2_B.Subtract1_i;

    /* Memory: '<S38>/Memory2' */
    t15_2_B.Memory2_kj[i] = t15_2_DWork.Memory2_PreviousInput_k[i];
  }

  /* Switch: '<S38>/tcont2 ' incorporates:
   *  Constant: '<S38>/zeros(20,1)'
   */
  for (i = 0; i < 20; i++) {
    if (t15_2_B.e3 > t15_2_P.tcont2_Threshold_b) {
      t15_2_B.tcont2[i] = t15_2_B.u9_g[i];
    } else {
      t15_2_B.tcont2[i] = t15_2_P.zeros201_Value[i];
    }
  }

  /* End of Switch: '<S38>/tcont2 ' */

  /* DiscreteStateSpace: '<S38>/Lim. contr.' */
  {
    {
      static const int_T colCidxRow0[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = t15_2_P.Limcontr_C;
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y0 = &t15_2_B.Limcontr[0];
      int_T numNonZero = 46;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colDidxRow0[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow0[0];
      const real_T *pD0 = t15_2_P.Limcontr_D;
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y0 = &t15_2_B.Limcontr[0];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y0 += (*pD0++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow1[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 };

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
      static const int_T colDidxRow1[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow1[0];
      const real_T *pD17 = &t15_2_P.Limcontr_D[17];
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y1 = &t15_2_B.Limcontr[1];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y1 += (*pD17++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow2[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 };

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
      static const int_T colDidxRow2[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow2[0];
      const real_T *pD34 = &t15_2_P.Limcontr_D[34];
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y2 = &t15_2_B.Limcontr[2];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y2 += (*pD34++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow3[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 };

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
      static const int_T colDidxRow3[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow3[0];
      const real_T *pD51 = &t15_2_P.Limcontr_D[51];
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y3 = &t15_2_B.Limcontr[3];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y3 += (*pD51++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow4[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 };

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
      static const int_T colDidxRow4[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow4[0];
      const real_T *pD68 = &t15_2_P.Limcontr_D[68];
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y4 = &t15_2_B.Limcontr[4];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y4 += (*pD68++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow5[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 };

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
      static const int_T colDidxRow5[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow5[0];
      const real_T *pD85 = &t15_2_P.Limcontr_D[85];
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y5 = &t15_2_B.Limcontr[5];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y5 += (*pD85++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow6[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 };

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
      static const int_T colDidxRow6[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow6[0];
      const real_T *pD102 = &t15_2_P.Limcontr_D[102];
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y6 = &t15_2_B.Limcontr[6];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y6 += (*pD102++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow7[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 };

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
      static const int_T colDidxRow7[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow7[0];
      const real_T *pD119 = &t15_2_P.Limcontr_D[119];
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y7 = &t15_2_B.Limcontr[7];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y7 += (*pD119++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow8[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 };

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
      static const int_T colDidxRow8[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow8[0];
      const real_T *pD136 = &t15_2_P.Limcontr_D[136];
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y8 = &t15_2_B.Limcontr[8];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y8 += (*pD136++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow9[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 };

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
      static const int_T colDidxRow9[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow9[0];
      const real_T *pD153 = &t15_2_P.Limcontr_D[153];
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y9 = &t15_2_B.Limcontr[9];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y9 += (*pD153++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow10[47] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 };

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
      static const int_T colDidxRow10[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow10[0];
      const real_T *pD170 = &t15_2_P.Limcontr_D[170];
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y10 = &t15_2_B.Limcontr[10];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y10 += (*pD170++) * u[*pDidx++];
      }
    }
  }

  /* DiscreteStateSpace: '<S38>/Curr. contr.' */
  {
    {
      static const int_T colCidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = t15_2_P.Currcontr_C;
      const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
      real_T *y0 = &t15_2_B.Currcontr[0];
      int_T numNonZero = 10;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colCidxRow1[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colCidxRow2[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colCidxRow3[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colCidxRow4[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colCidxRow5[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colCidxRow6[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colCidxRow7[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colCidxRow8[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colCidxRow9[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colCidxRow10[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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

  /* Switch: '<S38>/Ip>Ip_div ' incorporates:
   *  Switch: '<S38>/tcont2'
   */
  if (t15_2_B.e6 > t15_2_P.IpIp_div_Threshold_h) {
    memcpy(&t15_2_B.IpIp_div[0], &t15_2_B.Memory2_kj[0], 11U * sizeof(real_T));
  } else {
    if (t15_2_B.e3 > t15_2_P.tcont2_Threshold) {
      /* Lookup: '<S38>/gain_cont2' incorporates:
       *  Switch: '<S38>/tcont2'
       */
      t15_2_B.gain_cont2 = rt_Lookup(t15_2_P.gain_cont2_XData, 4, t15_2_B.e3,
        t15_2_P.gain_cont2_YData);
      for (i = 0; i < 11; i++) {
        /* Product: '<S38>/Divide ' incorporates:
         *  Switch: '<S38>/tcont2'
         */
        t15_2_B.Divide_o[i] = t15_2_B.Limcontr[i] * t15_2_B.gain_cont2;

        /* Switch: '<S38>/tcont2' */
        t15_2_B.tcont2_f[i] = t15_2_B.Divide_o[i];
      }
    } else {
      for (i = 0; i < 11; i++) {
        /* Gain: '<S38>/1//ntur ' incorporates:
         *  Switch: '<S38>/tcont2'
         */
        t15_2_B.ntur_n[i] = t15_2_P.ntur_Gain[i] * t15_2_B.Currcontr[i];

        /* Switch: '<S38>/tcont2' */
        t15_2_B.tcont2_f[i] = t15_2_B.ntur_n[i];
      }
    }

    memcpy(&t15_2_B.IpIp_div[0], &t15_2_B.tcont2_f[0], 11U * sizeof(real_T));
  }

  /* End of Switch: '<S38>/Ip>Ip_div ' */

  /* Lookup: '<S42>/volt1' */
  t15_2_B.volt1 = rt_Lookup(t15_2_P.volt1_XData, 19, t15_2_B.e3,
    t15_2_P.volt1_YData);

  /* Lookup: '<S42>/volt2' */
  t15_2_B.volt2 = rt_Lookup(t15_2_P.volt2_XData, 19, t15_2_B.e3,
    t15_2_P.volt2_YData);

  /* Lookup: '<S42>/volt3' */
  t15_2_B.volt3 = rt_Lookup(t15_2_P.volt3_XData, 19, t15_2_B.e3,
    t15_2_P.volt3_YData);

  /* Lookup: '<S42>/volt4' */
  t15_2_B.volt4 = rt_Lookup(t15_2_P.volt4_XData, 19, t15_2_B.e3,
    t15_2_P.volt4_YData);

  /* Lookup: '<S42>/volt5' */
  t15_2_B.volt5 = rt_Lookup(t15_2_P.volt5_XData, 19, t15_2_B.e3,
    t15_2_P.volt5_YData);

  /* Lookup: '<S42>/volt6' */
  t15_2_B.volt6 = rt_Lookup(t15_2_P.volt6_XData, 19, t15_2_B.e3,
    t15_2_P.volt6_YData);

  /* Lookup: '<S42>/volt7' */
  t15_2_B.volt7 = rt_Lookup(t15_2_P.volt7_XData, 19, t15_2_B.e3,
    t15_2_P.volt7_YData);

  /* Lookup: '<S42>/volt8' */
  t15_2_B.volt8 = rt_Lookup(t15_2_P.volt8_XData, 19, t15_2_B.e3,
    t15_2_P.volt8_YData);

  /* Lookup: '<S42>/volt9' */
  t15_2_B.volt9 = rt_Lookup(t15_2_P.volt9_XData, 19, t15_2_B.e3,
    t15_2_P.volt9_YData);

  /* Lookup: '<S42>/volt10' */
  t15_2_B.volt10 = rt_Lookup(t15_2_P.volt10_XData, 19, t15_2_B.e3,
    t15_2_P.volt10_YData);

  /* Lookup: '<S42>/volt11' */
  t15_2_B.volt11 = rt_Lookup(t15_2_P.volt11_XData, 19, t15_2_B.e3,
    t15_2_P.volt11_YData);

  /* Product: '<S7>/Divide7' */
  t15_2_B.Divide7[0] = t15_2_B.volt1 * t15_2_B.Subtract4;
  t15_2_B.Divide7[1] = t15_2_B.volt2 * t15_2_B.Subtract4;
  t15_2_B.Divide7[2] = t15_2_B.volt3 * t15_2_B.Subtract4;
  t15_2_B.Divide7[3] = t15_2_B.volt4 * t15_2_B.Subtract4;
  t15_2_B.Divide7[4] = t15_2_B.volt5 * t15_2_B.Subtract4;
  t15_2_B.Divide7[5] = t15_2_B.volt6 * t15_2_B.Subtract4;
  t15_2_B.Divide7[6] = t15_2_B.volt7 * t15_2_B.Subtract4;
  t15_2_B.Divide7[7] = t15_2_B.volt8 * t15_2_B.Subtract4;
  t15_2_B.Divide7[8] = t15_2_B.volt9 * t15_2_B.Subtract4;
  t15_2_B.Divide7[9] = t15_2_B.volt10 * t15_2_B.Subtract4;
  t15_2_B.Divide7[10] = t15_2_B.volt11 * t15_2_B.Subtract4;
  for (i = 0; i < 11; i++) {
    /* Product: '<S7>/Divide6' */
    t15_2_B.Divide6_o[i] = t15_2_B.Saturation1 * t15_2_B.IpIp_div[i];

    /* Sum: '<S7>/Sum3' */
    t15_2_B.Sum3[i] = ((t15_2_B.Divide4_k[i] + t15_2_B.Divide5[i]) +
                       t15_2_B.Divide6_o[i]) + t15_2_B.Divide7[i];

    /* Gain: '<S36>/1e3' */
    t15_2_B.e3_m[i] = t15_2_P.e3_Gain_l * t15_2_B.e6_m[i];

    /* Abs: '<S36>/Abs' */
    t15_2_B.Abs[i] = fabs(t15_2_B.e3_m[i]);

    /* Gain: '<S36>/ntur' incorporates:
     *  Constant: '<S7>/Imax'
     */
    t15_2_B.ntur_f[i] = t15_2_P.ntur_Gain_m[i] * t15_2_P.Imax_Value[i];

    /* Sum: '<S36>/Sum2' */
    t15_2_B.Sum2_l[i] = t15_2_B.ntur_f[i] - t15_2_B.Abs[i];

    /* Gain: '<S36>/c_cur_max' */
    t15_2_B.c_cur_max[i] = t15_2_P.c_cur_max_Gain * t15_2_B.ntur_f[i];

    /* Sum: '<S36>/Sum1' */
    t15_2_B.Sum1[i] = t15_2_B.ntur_f[i] - t15_2_B.c_cur_max[i];

    /* Product: '<S36>/Divide4' */
    t15_2_B.Divide4_f[i] = t15_2_B.Sum2_l[i] / t15_2_B.Sum1[i];

    /* Product: '<S36>/Divide1' */
    t15_2_B.Divide1_o[i] = t15_2_B.Divide4_f[i] * t15_2_B.Divide4_f[i] *
      t15_2_B.Divide4_f[i];

    /* Saturate: '<S36>/Saturation' */
    tmin = t15_2_B.Divide1_o[i];
    u_0 = t15_2_P.Saturation_LowerSat_k;
    u_1 = t15_2_P.Saturation_UpperSat_m;
    if (tmin >= u_1) {
      tmin = u_1;
    } else {
      if (tmin <= u_0) {
        tmin = u_0;
      }
    }

    t15_2_B.Saturation_p[i] = tmin;

    /* End of Saturate: '<S36>/Saturation' */

    /* RelationalOperator: '<S49>/Compare' incorporates:
     *  Constant: '<S49>/Constant'
     */
    t15_2_B.Compare_il[i] = (uint8_T)(t15_2_B.Saturation_p[i] <
      t15_2_P.Constant_Value_i);

    /* Product: '<S36>/Divide2' */
    t15_2_B.Divide2_h[i] = t15_2_B.e6_m[i] * t15_2_B.Sum3[i];

    /* RelationalOperator: '<S50>/Compare' incorporates:
     *  Constant: '<S50>/Constant'
     */
    t15_2_B.Compare_dg[i] = (uint8_T)(t15_2_B.Divide2_h[i] <
      t15_2_P.Constant_Value_ay);

    /* Logic: '<S36>/Logical Operator' */
    t15_2_B.LogicalOperator[i] = ((t15_2_B.Compare_il[i] != 0) &&
      (t15_2_B.Compare_dg[i] != 0));

    /* Sum: '<S36>/Sum3' */
    t15_2_B.Sum3_k[i] = t15_2_B.Saturation_p[i] + (real_T)
      t15_2_B.LogicalOperator[i];

    /* Saturate: '<S36>/Saturation1' */
    tmin = t15_2_B.Sum3_k[i];
    u_0 = t15_2_P.Saturation1_LowerSat_m;
    u_1 = t15_2_P.Saturation1_UpperSat_e;
    if (tmin >= u_1) {
      tmin = u_1;
    } else {
      if (tmin <= u_0) {
        tmin = u_0;
      }
    }

    t15_2_B.Saturation1_p[i] = tmin;

    /* End of Saturate: '<S36>/Saturation1' */

    /* Product: '<S36>/Divide6' */
    t15_2_B.Divide6_b[i] = t15_2_B.Sum3[i] * t15_2_B.Saturation1_p[i];

    /* Gain: '<S4>/ntur' */
    t15_2_B.ntur_e[i] = t15_2_P.ntur_Gain_d[i] * t15_2_B.Divide6_b[i];

    /* Product: '<S2>/Divide2' */
    t15_2_B.Divide2_n[i] = t15_2_B.Diff * t15_2_B.ntur_e[i];

    /* Gain: '<S2>/Tfmc ' */
    t15_2_B.Tfmc[i] = t15_2_P.Tfmc_Gain * t15_2_B.Memory[i];

    /* Sum: '<S2>/Add1' */
    t15_2_B.Add1_i[i] = t15_2_B.Divide2_n[i] + t15_2_B.Tfmc[i];

    /* Product: '<S2>/Divide3' */
    t15_2_B.Divide3[i] = t15_2_B.Add1_i[i] / t15_2_B.Add;
  }

  /* Memory: '<S4>/Memory2' */
  t15_2_B.Memory2_g = t15_2_DWork.Memory2_PreviousInput_gi;

  /* Gain: '<S4>/-1' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_B.u_e = t15_2_P.u_Gain * t15_2_U.In1[3];

  /* Switch: '<S4>/Ip<Ip_0 ' */
  if (t15_2_B.u_e > t15_2_P.IpIp_0_Threshold) {
    t15_2_B.IpIp_0 = t15_2_B.Memory2_g;
  } else {
    t15_2_B.IpIp_0 = t15_2_B.e3;
  }

  /* End of Switch: '<S4>/Ip<Ip_0 ' */

  /* Sum: '<S4>/Sum2' incorporates:
   *  Constant: '<S4>/dt_end_sim'
   */
  t15_2_B.Sum2_e = t15_2_B.IpIp_0 + t15_2_P.dt_end_sim_Value;

  /* RelationalOperator: '<S4>/Relational Operator' */
  t15_2_B.RelationalOperator_c = (t15_2_B.e3 >= t15_2_B.Sum2_e);

  /* Stop: '<S4>/Stop Simulation' */
  if (t15_2_B.RelationalOperator_c) {
    rtmSetStopRequested(t15_2_M, 1);
  }

  /* End of Stop: '<S4>/Stop Simulation' */

  /* RelationalOperator: '<S4>/Relational Operator1' incorporates:
   *  Constant: '<S4>/Time_stop'
   */
  t15_2_B.RelationalOperator1 = (t15_2_B.e3 >= t15_2_P.Time_stop_Value);

  /* Stop: '<S4>/Stop Simulation1' */
  if (t15_2_B.RelationalOperator1) {
    rtmSetStopRequested(t15_2_M, 1);
  }

  /* End of Stop: '<S4>/Stop Simulation1' */

  /* Gain: '<S12>/1e6' */
  t15_2_B.e6_e = t15_2_P.e6_Gain_b * t15_2_B.Add2;

  /* Product: '<S7>/Divide12' */
  for (i = 0; i < 20; i++) {
    t15_2_B.Divide12[i] = t15_2_B.Divide2_i[i] * t15_2_B.LogicalOperator2;
  }

  /* End of Product: '<S7>/Divide12' */

  /* Update for UnitDelay: '<S5>/UD' */
  t15_2_DWork.UD_DSTATE = t15_2_B.e3;

  /* Update for UniformRandomNumber: '<S47>/Uniform Random Number' */
  tmin = t15_2_P.UniformRandomNumber_Minimum;
  t15_2_DWork.UniformRandomNumber_NextOutput =
    (t15_2_P.UniformRandomNumber_Maximum - tmin) * rt_urand_Upu32_Yd_f_pw_snf
    (&t15_2_DWork.RandSeed) + tmin;

  /* Update for UnitDelay: '<S34>/UD' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_DWork.UD_DSTATE_j = t15_2_U.In1[0];

  /* Update for UnitDelay: '<S35>/UD' */
  t15_2_DWork.UD_DSTATE_o = t15_2_B.e3;

  /* Update for DiscreteStateSpace: '<S41>/VS. contr' */
  {
    real_T xnew[10];

    {
      static const int_T colAidxRow0[9] = { 0, 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = t15_2_P.VScontr_A;
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 8;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (t15_2_P.VScontr_B[0])*t15_2_B.tt_tran2d[0] + (t15_2_P.VScontr_B
      [1])*t15_2_B.tt_tran2d[1];

    {
      static const int_T colAidxRow1[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA9 = &t15_2_P.VScontr_A[9];
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 8;
      *pxnew1 = (*pA9++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA9++) * xd[*pAidx++];
      }
    }

    xnew[1] += (t15_2_P.VScontr_B[2])*t15_2_B.tt_tran2d[0] + (t15_2_P.VScontr_B
      [3])*t15_2_B.tt_tran2d[1];

    {
      static const int_T colAidxRow2[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA18 = &t15_2_P.VScontr_A[18];
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 7;
      *pxnew2 = (*pA18++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA18++) * xd[*pAidx++];
      }
    }

    xnew[2] += (t15_2_P.VScontr_B[4])*t15_2_B.tt_tran2d[0] + (t15_2_P.VScontr_B
      [5])*t15_2_B.tt_tran2d[1];

    {
      static const int_T colAidxRow3[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA26 = &t15_2_P.VScontr_A[26];
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 7;
      *pxnew3 = (*pA26++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA26++) * xd[*pAidx++];
      }
    }

    xnew[3] += (t15_2_P.VScontr_B[6])*t15_2_B.tt_tran2d[0] + (t15_2_P.VScontr_B
      [7])*t15_2_B.tt_tran2d[1];

    {
      static const int_T colAidxRow4[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA34 = &t15_2_P.VScontr_A[34];
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 7;
      *pxnew4 = (*pA34++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA34++) * xd[*pAidx++];
      }
    }

    xnew[4] += (t15_2_P.VScontr_B[8])*t15_2_B.tt_tran2d[0] + (t15_2_P.VScontr_B
      [9])*t15_2_B.tt_tran2d[1];

    {
      static const int_T colAidxRow5[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA42 = &t15_2_P.VScontr_A[42];
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 7;
      *pxnew5 = (*pA42++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA42++) * xd[*pAidx++];
      }
    }

    xnew[5] += (t15_2_P.VScontr_B[10])*t15_2_B.tt_tran2d[0] +
      (t15_2_P.VScontr_B[11])*t15_2_B.tt_tran2d[1];

    {
      static const int_T colAidxRow6[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA50 = &t15_2_P.VScontr_A[50];
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 7;
      *pxnew6 = (*pA50++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA50++) * xd[*pAidx++];
      }
    }

    xnew[6] += (t15_2_P.VScontr_B[12])*t15_2_B.tt_tran2d[0] +
      (t15_2_P.VScontr_B[13])*t15_2_B.tt_tran2d[1];

    {
      static const int_T colAidxRow7[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA58 = &t15_2_P.VScontr_A[58];
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 7;
      *pxnew7 = (*pA58++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA58++) * xd[*pAidx++];
      }
    }

    xnew[7] += (t15_2_P.VScontr_B[14])*t15_2_B.tt_tran2d[0] +
      (t15_2_P.VScontr_B[15])*t15_2_B.tt_tran2d[1];

    {
      static const int_T colAidxRow8[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA66 = &t15_2_P.VScontr_A[66];
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 7;
      *pxnew8 = (*pA66++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA66++) * xd[*pAidx++];
      }
    }

    xnew[8] += (t15_2_P.VScontr_B[16])*t15_2_B.tt_tran2d[0] +
      (t15_2_P.VScontr_B[17])*t15_2_B.tt_tran2d[1];

    {
      static const int_T colAidxRow9[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA74 = &t15_2_P.VScontr_A[74];
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 7;
      *pxnew9 = (*pA74++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA74++) * xd[*pAidx++];
      }
    }

    xnew[9] += (t15_2_P.VScontr_B[18])*t15_2_B.tt_tran2d[0] +
      (t15_2_P.VScontr_B[19])*t15_2_B.tt_tran2d[1];
    (void) memcpy(&t15_2_DWork.VScontr_DSTATE[0], xnew,
                  sizeof(real_T)*10);
  }

  /* Update for Memory: '<S12>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput = t15_2_B.e6_e;

  /* Update for Memory: '<S12>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput = t15_2_B.Ics1_eob;

  /* Update for DiscreteStateSpace: '<S41>/VS. contr hl' */
  {
    real_T xnew[8];
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
    (void) memcpy(&t15_2_DWork.VScontrhl_DSTATE[0], xnew,
                  sizeof(real_T)*8);
  }

  /* Update for Memory: '<S48>/Memory3' */
  t15_2_DWork.Memory3_PreviousInput = t15_2_B.u999;

  /* Update for Memory: '<S26>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_c = t15_2_B.c_eob_l;

  /* Update for Memory: '<S27>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_d = t15_2_B.c_eob_p;

  /* Update for Memory: '<S28>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_i = t15_2_B.c_eob_p2;

  /* Update for Memory: '<S29>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_g = t15_2_B.c_eob_ln;

  /* Update for Memory: '<S30>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_gg = t15_2_B.c_eob_j;

  /* Update for Memory: '<S31>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_b = t15_2_B.c_eob1;

  /* Update for Memory: '<S31>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_g2 = t15_2_B.c_eob_b;

  /* Update for Memory: '<S10>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_j = t15_2_B.c_eob_h;

  /* Update for Memory: '<S15>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_l = t15_2_B.c_eob_k;

  /* Update for Memory: '<S18>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_p = t15_2_B.c_eob_i;

  /* Update for Memory: '<S19>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_c = t15_2_B.c_eob_ls;

  /* Update for Memory: '<S20>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_bw = t15_2_B.c_eob_pk;

  /* Update for Memory: '<S21>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_m = t15_2_B.c_eob_ir;

  /* Update for Memory: '<S22>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_e = t15_2_B.c_eob_hr;

  /* Update for Memory: '<S23>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_lu = t15_2_B.c_eob_ng;

  /* Update for Memory: '<S24>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_h = t15_2_B.c_eob_ni;

  /* Update for Memory: '<S25>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_g = t15_2_B.c_eob_id;

  /* Update for Memory: '<S16>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_f = t15_2_B.c_eob_jj;

  /* Update for Memory: '<S17>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_d = t15_2_B.c_eob_le;

  /* Update for DiscreteStateSpace: '<S7>/Div. contr.' */
  {
    real_T xnew[50];

    {
      static const int_T colAidxRow0[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 25, 26, 27, 28, 29, 30, 31 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = t15_2_P.Divcontr_A;
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
      const real_T *pB0 = t15_2_P.Divcontr_B;
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      static const int_T colBidxRow10[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow10[0];
      const real_T *pB170 = &t15_2_P.Divcontr_B[170];
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      static const int_T colBidxRow11[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow11[0];
      const real_T *pB187 = &t15_2_P.Divcontr_B[187];
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      static const int_T colBidxRow12[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow12[0];
      const real_T *pB204 = &t15_2_P.Divcontr_B[204];
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      static const int_T colBidxRow13[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow13[0];
      const real_T *pB221 = &t15_2_P.Divcontr_B[221];
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      static const int_T colBidxRow14[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow14[0];
      const real_T *pB238 = &t15_2_P.Divcontr_B[238];
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      static const int_T colBidxRow15[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow15[0];
      const real_T *pB255 = &t15_2_P.Divcontr_B[255];
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      static const int_T colBidxRow16[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow16[0];
      const real_T *pB272 = &t15_2_P.Divcontr_B[272];
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      static const int_T colBidxRow17[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow17[0];
      const real_T *pB289 = &t15_2_P.Divcontr_B[289];
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      static const int_T colBidxRow18[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow18[0];
      const real_T *pB306 = &t15_2_P.Divcontr_B[306];
      const real_T *u = &t15_2_B.Divide2_i[0];
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
      static const int_T colBidxRow19[17] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow19[0];
      const real_T *pB323 = &t15_2_P.Divcontr_B[323];
      const real_T *u = &t15_2_B.Divide2_i[0];
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

    xnew[20] += (t15_2_P.Divcontr_B[340])*t15_2_B.Divide2_i[12];

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

    xnew[21] += (t15_2_P.Divcontr_B[341])*t15_2_B.Divide2_i[12];

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

    xnew[22] += (t15_2_P.Divcontr_B[342])*t15_2_B.Divide2_i[12];

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

    xnew[23] += (t15_2_P.Divcontr_B[343])*t15_2_B.Divide2_i[12];

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

    xnew[24] += (t15_2_P.Divcontr_B[344])*t15_2_B.Divide2_i[12];
    xnew[25] = (t15_2_P.Divcontr_A[565])*t15_2_DWork.Divcontr_DSTATE[25];
    xnew[25] += (t15_2_P.Divcontr_B[345])*t15_2_B.Divide2_i[0];
    xnew[26] = (t15_2_P.Divcontr_A[566])*t15_2_DWork.Divcontr_DSTATE[26];
    xnew[26] += (t15_2_P.Divcontr_B[346])*t15_2_B.Divide2_i[1];
    xnew[27] = (t15_2_P.Divcontr_A[567])*t15_2_DWork.Divcontr_DSTATE[27];
    xnew[27] += (t15_2_P.Divcontr_B[347])*t15_2_B.Divide2_i[2];
    xnew[28] = (t15_2_P.Divcontr_A[568])*t15_2_DWork.Divcontr_DSTATE[28];
    xnew[28] += (t15_2_P.Divcontr_B[348])*t15_2_B.Divide2_i[3];
    xnew[29] = (t15_2_P.Divcontr_A[569])*t15_2_DWork.Divcontr_DSTATE[29];
    xnew[29] += (t15_2_P.Divcontr_B[349])*t15_2_B.Divide2_i[4];
    xnew[30] = (t15_2_P.Divcontr_A[570])*t15_2_DWork.Divcontr_DSTATE[30];
    xnew[30] += (t15_2_P.Divcontr_B[350])*t15_2_B.Divide2_i[5];
    xnew[31] = (t15_2_P.Divcontr_A[571])*t15_2_DWork.Divcontr_DSTATE[31];
    xnew[31] += (t15_2_P.Divcontr_B[351])*t15_2_B.Divide2_i[7];
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
    (void) memcpy(&t15_2_DWork.Divcontr_DSTATE[0], xnew,
                  sizeof(real_T)*50);
  }

  /* Update for Memory: '<S46>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_cn = t15_2_B.u999_f;

  /* Update for DiscreteStateSpace: '<S7>/Div_rd contr' */
  {
    real_T xnew[40];

    {
      static const int_T colAidxRow0[22] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = t15_2_P.Div_rdcontr_A;
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
      const real_T *pB0 = t15_2_P.Div_rdcontr_B;
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      const real_T *u = &t15_2_B.Divide13[0];
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
      static const int_T colBidxRow10[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow10[0];
      const real_T *pB180 = &t15_2_P.Div_rdcontr_B[180];
      const real_T *u = &t15_2_B.Divide13[0];
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
      static const int_T colBidxRow11[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow11[0];
      const real_T *pB198 = &t15_2_P.Div_rdcontr_B[198];
      const real_T *u = &t15_2_B.Divide13[0];
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
      static const int_T colBidxRow12[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow12[0];
      const real_T *pB216 = &t15_2_P.Div_rdcontr_B[216];
      const real_T *u = &t15_2_B.Divide13[0];
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
      static const int_T colBidxRow13[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow13[0];
      const real_T *pB234 = &t15_2_P.Div_rdcontr_B[234];
      const real_T *u = &t15_2_B.Divide13[0];
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
      static const int_T colBidxRow14[18] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow14[0];
      const real_T *pB252 = &t15_2_P.Div_rdcontr_B[252];
      const real_T *u = &t15_2_B.Divide13[0];
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
    (void) memcpy(&t15_2_DWork.Div_rdcontr_DSTATE[0], xnew,
                  sizeof(real_T)*40);
  }

  /* Update for Memory: '<S44>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_i3 = t15_2_B.c_eob_jl;

  /* Update for Memory: '<S45>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_l = t15_2_B.u999_l;

  /* Update for DiscreteStateSpace: '<S7>/Curr. term. contr' */
  {
    real_T xnew[40];

    {
      static const int_T colAidxRow0[12] = { 0, 11, 12, 13, 14, 15, 16, 17, 18,
        19, 20, 21 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = t15_2_P.Currtermcontr_A;
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
      static const int_T colAidxRow10[12] = { 10, 11, 12, 13, 14, 15, 16, 17, 18,
        19, 20, 21 };

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
      static const int_T colAidxRow11[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21 };

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
      const real_T *pB0 = t15_2_P.Currtermcontr_B;
      const real_T *u = &t15_2_B.Divide12[0];
      real_T *pxnew11 = &xnew[11];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew11 += (*pB0++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow12[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21 };

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
      const real_T *u = &t15_2_B.Divide12[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew12 += (*pB11++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow13[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21 };

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
      const real_T *u = &t15_2_B.Divide12[0];
      real_T *pxnew13 = &xnew[13];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew13 += (*pB22++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow14[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21 };

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
      const real_T *u = &t15_2_B.Divide12[0];
      real_T *pxnew14 = &xnew[14];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew14 += (*pB33++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow15[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21 };

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
      const real_T *u = &t15_2_B.Divide12[0];
      real_T *pxnew15 = &xnew[15];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew15 += (*pB44++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow16[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21 };

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
      const real_T *u = &t15_2_B.Divide12[0];
      real_T *pxnew16 = &xnew[16];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew16 += (*pB55++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow17[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21 };

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
      const real_T *u = &t15_2_B.Divide12[0];
      real_T *pxnew17 = &xnew[17];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew17 += (*pB66++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow18[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21 };

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
      const real_T *u = &t15_2_B.Divide12[0];
      real_T *pxnew18 = &xnew[18];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew18 += (*pB77++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow19[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21 };

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
      const real_T *u = &t15_2_B.Divide12[0];
      real_T *pxnew19 = &xnew[19];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew19 += (*pB88++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow20[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21 };

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
      const real_T *u = &t15_2_B.Divide12[0];
      real_T *pxnew20 = &xnew[20];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew20 += (*pB99++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow21[11] = { 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21 };

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
      const real_T *u = &t15_2_B.Divide12[0];
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
    (void) memcpy(&t15_2_DWork.Currtermcontr_DSTATE[0], xnew,
                  sizeof(real_T)*40);
  }

  for (i = 0; i < 11; i++) {
    /* Gain: '<S38>/1//ntur' */
    t15_2_B.ntur_k[i] = t15_2_B.u9_g[i + 8] * t15_2_P.ntur_Gain_o[i];

    /* Update for Memory: '<S2>/Memory' */
    t15_2_DWork.Memory_PreviousInput[i] = t15_2_B.Divide3[i];

    /* Update for Memory: '<S37>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_p[i] = t15_2_B.u99[i];

    /* Update for Memory: '<S39>/Memory' */
    t15_2_DWork.Memory_PreviousInput_e[i] = t15_2_B.u9_n[i];

    /* Update for Memory: '<S38>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_k[i] = t15_2_B.IpIp_div[i];
  }

  /* Update for DiscreteStateSpace: '<S38>/Lim. contr.' */
  {
    real_T xnew[50];

    {
      static const int_T colAidxRow0[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 24, 25, 27 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = t15_2_P.Limcontr_A;
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 24;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow0[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow0[0];
      const real_T *pB0 = t15_2_P.Limcontr_B;
      const real_T *u = &t15_2_B.tcont2[0];
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
      static const int_T colBidxRow1[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow1[0];
      const real_T *pB16 = &t15_2_P.Limcontr_B[16];
      const real_T *u = &t15_2_B.tcont2[0];
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
      static const int_T colBidxRow2[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow2[0];
      const real_T *pB32 = &t15_2_P.Limcontr_B[32];
      const real_T *u = &t15_2_B.tcont2[0];
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
      static const int_T colBidxRow3[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow3[0];
      const real_T *pB48 = &t15_2_P.Limcontr_B[48];
      const real_T *u = &t15_2_B.tcont2[0];
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
      static const int_T colBidxRow4[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow4[0];
      const real_T *pB64 = &t15_2_P.Limcontr_B[64];
      const real_T *u = &t15_2_B.tcont2[0];
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
      static const int_T colBidxRow5[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow5[0];
      const real_T *pB80 = &t15_2_P.Limcontr_B[80];
      const real_T *u = &t15_2_B.tcont2[0];
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
      static const int_T colBidxRow6[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow6[0];
      const real_T *pB96 = &t15_2_P.Limcontr_B[96];
      const real_T *u = &t15_2_B.tcont2[0];
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
      static const int_T colBidxRow7[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow7[0];
      const real_T *pB112 = &t15_2_P.Limcontr_B[112];
      const real_T *u = &t15_2_B.tcont2[0];
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
      static const int_T colBidxRow8[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow8[0];
      const real_T *pB128 = &t15_2_P.Limcontr_B[128];
      const real_T *u = &t15_2_B.tcont2[0];
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
      static const int_T colBidxRow9[16] = { 0, 2, 3, 4, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow9[0];
      const real_T *pB144 = &t15_2_P.Limcontr_B[144];
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      static const int_T colAidxRow28[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow29[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow30[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow31[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow32[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow33[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow34[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow35[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow36[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow37[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow38[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow39[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow40[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow41[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow42[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow43[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow44[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow45[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow46[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
      static const int_T colAidxRow47[20] = { 28, 29, 30, 31, 32, 33, 34, 35, 36,
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };

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
    (void) memcpy(&t15_2_DWork.Limcontr_DSTATE[0], xnew,
                  sizeof(real_T)*50);
  }

  /* Update for DiscreteStateSpace: '<S38>/Curr. contr.' */
  {
    real_T xnew[11];

    {
      static const int_T colAidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = t15_2_P.Currcontr_A;
      const real_T *xd = &t15_2_DWork.Currcontr_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 10;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pBidx = &colBidxRow0[0];
      const real_T *pB0 = t15_2_P.Currcontr_B;
      const real_T *u = &t15_2_B.ntur_k[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew0 += (*pB0++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow1[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colBidxRow1[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pBidx = &colBidxRow1[0];
      const real_T *pB11 = &t15_2_P.Currcontr_B[11];
      const real_T *u = &t15_2_B.ntur_k[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew1 += (*pB11++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow2[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colBidxRow2[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pBidx = &colBidxRow2[0];
      const real_T *pB22 = &t15_2_P.Currcontr_B[22];
      const real_T *u = &t15_2_B.ntur_k[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew2 += (*pB22++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow3[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colBidxRow3[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pBidx = &colBidxRow3[0];
      const real_T *pB33 = &t15_2_P.Currcontr_B[33];
      const real_T *u = &t15_2_B.ntur_k[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew3 += (*pB33++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow4[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colBidxRow4[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pBidx = &colBidxRow4[0];
      const real_T *pB44 = &t15_2_P.Currcontr_B[44];
      const real_T *u = &t15_2_B.ntur_k[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew4 += (*pB44++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow5[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colBidxRow5[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pBidx = &colBidxRow5[0];
      const real_T *pB55 = &t15_2_P.Currcontr_B[55];
      const real_T *u = &t15_2_B.ntur_k[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew5 += (*pB55++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow6[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colBidxRow6[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pBidx = &colBidxRow6[0];
      const real_T *pB66 = &t15_2_P.Currcontr_B[66];
      const real_T *u = &t15_2_B.ntur_k[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew6 += (*pB66++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow7[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colBidxRow7[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pBidx = &colBidxRow7[0];
      const real_T *pB77 = &t15_2_P.Currcontr_B[77];
      const real_T *u = &t15_2_B.ntur_k[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew7 += (*pB77++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow8[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colBidxRow8[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pBidx = &colBidxRow8[0];
      const real_T *pB88 = &t15_2_P.Currcontr_B[88];
      const real_T *u = &t15_2_B.ntur_k[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew8 += (*pB88++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow9[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colBidxRow9[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pBidx = &colBidxRow9[0];
      const real_T *pB99 = &t15_2_P.Currcontr_B[99];
      const real_T *u = &t15_2_B.ntur_k[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew9 += (*pB99++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow10[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
      static const int_T colBidxRow10[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pBidx = &colBidxRow10[0];
      const real_T *pB110 = &t15_2_P.Currcontr_B[110];
      const real_T *u = &t15_2_B.ntur_k[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew10 += (*pB110++) * u[*pBidx++];
      }
    }

    (void) memcpy(&t15_2_DWork.Currcontr_DSTATE[0], xnew,
                  sizeof(real_T)*11);
  }

  /* Update for Memory: '<S4>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_gi = t15_2_B.IpIp_0;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.002, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  t15_2_M->Timing.clockTick0++;
}

/* Model initialize function */
void t15_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)t15_2_M, 0,
                sizeof(RT_MODEL_t15_2));

  /* block I/O */
  (void) memset(((void *) &t15_2_B), 0,
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

    for (i = 0; i < 11; i++) {
      t15_2_B.ntur[i] = 0.0;
    }

    for (i = 0; i < 15; i++) {
      t15_2_B.e6_m[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.wz[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Add1_k[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.TmpSignalConversionAtnpf12Inpor[i] = 0.0;
    }

    for (i = 0; i < 15; i++) {
      t15_2_B.npf12[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory1_b[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory_l[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      t15_2_B.e2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      t15_2_B.e2_o[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_m[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_d[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_k[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_l[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_g[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_i[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_ko[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_lj[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_e[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_h[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_g4[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.u9_g[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide2_i[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u9_n[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide13[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Div_rdcontr[i] = 0.0;
    }

    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1_kc[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u99[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide4_k[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Currtermcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide5[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory2_kj[i] = 0.0;
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
      t15_2_B.Divide6_o[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide7[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum3[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.e3_m[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Abs[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.ntur_f[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum2_l[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.c_cur_max[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum1[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide4_f[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_o[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Saturation_p[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide2_h[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum3_k[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Saturation1_p[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide6_b[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.ntur_e[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide2_n[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Tfmc[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Add1_i[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide3[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide12[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.ntur_k[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain2[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_h[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide_i[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.tcont2_f[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide_o[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.ntur_n[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide3_o[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_f[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum2_m[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain2_j[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_k[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain4[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_h4[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain4_i[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_jd[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain4_a[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_a[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain4_a3[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_a1[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain4_l[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_b[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain4_j[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_m[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain4_k[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_mh[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain4_m[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_ag[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain4_k5[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_ma[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain4_p[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_l[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain4_n[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.Gain1_n[i] = 0.0;
    }

    t15_2_B.e3 = 0.0;
    t15_2_B.Uk1 = 0.0;
    t15_2_B.Diff = 0.0;
    t15_2_B.Gain = 0.0;
    t15_2_B.e6 = 0.0;
    t15_2_B.LogicalOperator2 = 0.0;
    t15_2_B.Subtract4 = 0.0;
    t15_2_B.UniformRandomNumber = 0.0;
    t15_2_B.Uk1_h = 0.0;
    t15_2_B.Uk1_d = 0.0;
    t15_2_B.tt_tran2d[0] = 0.0;
    t15_2_B.tt_tran2d[1] = 0.0;
    t15_2_B.VScontr[0] = 0.0;
    t15_2_B.VScontr[1] = 0.0;
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
    t15_2_B.VScontrhl[0] = 0.0;
    t15_2_B.VScontrhl[1] = 0.0;
    t15_2_B.c_eob[0] = 0.0;
    t15_2_B.c_eob[1] = 0.0;
    t15_2_B.LogicalOperator1 = 0.0;
    t15_2_B.atpl115 = 0.0;
    t15_2_B.u9[0] = 0.0;
    t15_2_B.u9[1] = 0.0;
    t15_2_B.Divide10[0] = 0.0;
    t15_2_B.Divide10[1] = 0.0;
    t15_2_B.SaturationVS1 = 0.0;
    t15_2_B.SaturationVS3 = 0.0;
    t15_2_B.TmpSignalConversionAtwzInport1[0] = 0.0;
    t15_2_B.TmpSignalConversionAtwzInport1[1] = 0.0;
    t15_2_B.Add = 0.0;
    t15_2_B.LogicalOperator2_g = 0.0;
    t15_2_B.LogicalOperator1_b = 0.0;
    t15_2_B.Memory3 = 0.0;
    t15_2_B.LogicalOperator1_e = 0.0;
    t15_2_B.u999 = 0.0;
    t15_2_B.Subtract2 = 0.0;
    t15_2_B.Gain1 = 0.0;
    t15_2_B.Subtract1 = 0.0;
    t15_2_B.Saturation1 = 0.0;
    t15_2_B.Sum2 = 0.0;
    t15_2_B.u_i = 0.0;
    t15_2_B.Memory1_k = 0.0;
    t15_2_B.c_eob_l = 0.0;
    t15_2_B.c_eob_n = 0.0;
    t15_2_B.Add2_m = 0.0;
    t15_2_B.LookupTable1 = 0.0;
    t15_2_B.Divide6 = 0.0;
    t15_2_B.Memory1_m = 0.0;
    t15_2_B.c_eob_p = 0.0;
    t15_2_B.c_eob_o = 0.0;
    t15_2_B.Add1_o = 0.0;
    t15_2_B.LookupTable2 = 0.0;
    t15_2_B.Divide1_h = 0.0;
    t15_2_B.Memory1_f = 0.0;
    t15_2_B.c_eob_p2 = 0.0;
    t15_2_B.c_eob_g = 0.0;
    t15_2_B.Add3_j = 0.0;
    t15_2_B.Memory1_fr = 0.0;
    t15_2_B.c_eob_ln = 0.0;
    t15_2_B.c_eob_pr = 0.0;
    t15_2_B.Add4 = 0.0;
    t15_2_B.LookupTable3 = 0.0;
    t15_2_B.Divide2 = 0.0;
    t15_2_B.Memory1_bc = 0.0;
    t15_2_B.c_eob_j = 0.0;
    t15_2_B.c_eob_js = 0.0;
    t15_2_B.Add5 = 0.0;
    t15_2_B.g6_ref = 0.0;
    t15_2_B.Memory2_k = 0.0;
    t15_2_B.c_eob1 = 0.0;
    t15_2_B.Memory1_o = 0.0;
    t15_2_B.c_eob_b = 0.0;
    t15_2_B.c_eob_a = 0.0;
    t15_2_B.Add6 = 0.0;
    t15_2_B.Memory1_l = 0.0;
    t15_2_B.c_eob_h = 0.0;
    t15_2_B.Divide6_m = 0.0;
    t15_2_B.Add1_m = 0.0;
    t15_2_B.Memory2_l = 0.0;
    t15_2_B.c_eob_k = 0.0;
    t15_2_B.Divide1_n = 0.0;
    t15_2_B.Add3_n = 0.0;
    t15_2_B.Memory2_l4 = 0.0;
    t15_2_B.c_eob_i = 0.0;
    t15_2_B.Divide1_j = 0.0;
    t15_2_B.Add1_h = 0.0;
    t15_2_B.Memory2_h = 0.0;
    t15_2_B.c_eob_ls = 0.0;
    t15_2_B.Divide1_l = 0.0;
    t15_2_B.Add2_d = 0.0;
    t15_2_B.Memory2_m = 0.0;
    t15_2_B.c_eob_pk = 0.0;
    t15_2_B.Divide1_g = 0.0;
    t15_2_B.Add4_l = 0.0;
    t15_2_B.Memory2_ha = 0.0;
    t15_2_B.c_eob_ir = 0.0;
    t15_2_B.Divide1_i = 0.0;
    t15_2_B.Add5_i = 0.0;
    t15_2_B.LookupTable1_a = 0.0;
    t15_2_B.Divide6_f = 0.0;
    t15_2_B.Memory2_c = 0.0;
    t15_2_B.c_eob_hr = 0.0;
    t15_2_B.Divide1_jl = 0.0;
    t15_2_B.Add6_b = 0.0;
    t15_2_B.Memory2_f = 0.0;
    t15_2_B.c_eob_ng = 0.0;
    t15_2_B.Divide1_a = 0.0;
    t15_2_B.Add7 = 0.0;
    t15_2_B.Memory2_j = 0.0;
    t15_2_B.c_eob_ni = 0.0;
    t15_2_B.Divide1_p = 0.0;
    t15_2_B.Add8 = 0.0;
    t15_2_B.Memory2_p = 0.0;
    t15_2_B.c_eob_id = 0.0;
    t15_2_B.Divide1_lm = 0.0;
    t15_2_B.Add9 = 0.0;
    t15_2_B.Memory2_n = 0.0;
    t15_2_B.c_eob_jj = 0.0;
    t15_2_B.Divide1_c = 0.0;
    t15_2_B.Add10 = 0.0;
    t15_2_B.Memory2_kk = 0.0;
    t15_2_B.c_eob_le = 0.0;
    t15_2_B.Divide1_e = 0.0;
    t15_2_B.Add11 = 0.0;
    t15_2_B.LogicalOperator1_i = 0.0;
    t15_2_B.Memory1_e = 0.0;
    t15_2_B.LogicalOperator1_n = 0.0;
    t15_2_B.u999_f = 0.0;
    t15_2_B.Memory1_f1 = 0.0;
    t15_2_B.c_eob_jl = 0.0;
    t15_2_B.Memory1_l1 = 0.0;
    t15_2_B.u999_l = 0.0;
    t15_2_B.Subtract2_g = 0.0;
    t15_2_B.Gain1_j = 0.0;
    t15_2_B.Subtract3 = 0.0;
    t15_2_B.Saturation = 0.0;
    t15_2_B.Subtract1_i = 0.0;
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
    t15_2_B.Memory2_g = 0.0;
    t15_2_B.u_e = 0.0;
    t15_2_B.IpIp_0 = 0.0;
    t15_2_B.Sum2_e = 0.0;
    t15_2_B.e6_e = 0.0;
    t15_2_B.Ipref = 0.0;
    t15_2_B.c_a_tpl1_eob15 = 0.0;
    t15_2_B.Saturation4 = 0.0;
    t15_2_B.Divide11[0] = 0.0;
    t15_2_B.Divide11[1] = 0.0;
    t15_2_B.c_eob_lu[0] = 0.0;
    t15_2_B.c_eob_lu[1] = 0.0;
    t15_2_B.IpIp_div_m = 0.0;
    t15_2_B.Divide8[0] = 0.0;
    t15_2_B.Divide8[1] = 0.0;
    t15_2_B.SatDiv = 0.0;
    t15_2_B.SatLim = 0.0;
    t15_2_B.u5 = 0.0;
    t15_2_B.Saturation3 = 0.0;
    t15_2_B.Divide9[0] = 0.0;
    t15_2_B.Divide9[1] = 0.0;
    t15_2_B.Subtract3_f = 0.0;
    t15_2_B.gain_cont2 = 0.0;
    t15_2_B.Subtract2_p = 0.0;
    t15_2_B.Gain1_i = 0.0;
    t15_2_B.Subtract3_k = 0.0;
    t15_2_B.Saturation_c = 0.0;
    t15_2_B.Subtract1_h = 0.0;
    t15_2_B.c_eob_oo = 0.0;
    t15_2_B.atpl2 = 0.0;
    t15_2_B.Saturation_h = 0.0;
    t15_2_B.Divide6_b2 = 0.0;
    t15_2_B.Sum = 0.0;
    t15_2_B.Divide2_iq = 0.0;
    t15_2_B.Sum1_c = 0.0;
    t15_2_B.uy0 = 0.0;
    t15_2_B.Diff_j = 0.0;
    t15_2_B.Diff_l = 0.0;
    t15_2_B.Divide_l = 0.0;
    t15_2_B.Sum2_b = 0.0;
    t15_2_B.elong_ref = 0.0;
    t15_2_B.Add2_a = 0.0;
    t15_2_B.k_gaplim[0] = 0.0;
    t15_2_B.k_gaplim[1] = 0.0;
    t15_2_B.k_gaplim[2] = 0.0;
    t15_2_B.k_gaplim[3] = 0.0;
    t15_2_B.Add2_i = 0.0;
    t15_2_B.g6_ref_term = 0.0;
    t15_2_B.Add1_o1 = 0.0;
    t15_2_B.g5_ref = 0.0;
    t15_2_B.Add2_f = 0.0;
    t15_2_B.g5_ref_term = 0.0;
    t15_2_B.g4_ref = 0.0;
    t15_2_B.Add2_h = 0.0;
    t15_2_B.g4_ref_term = 0.0;
    t15_2_B.g3_ref = 0.0;
    t15_2_B.Add2_m5 = 0.0;
    t15_2_B.g3_ref_term = 0.0;
    t15_2_B.g2_ref = 0.0;
    t15_2_B.Add2_k = 0.0;
    t15_2_B.g2_ref_term = 0.0;
    t15_2_B.g1_ref = 0.0;
    t15_2_B.Add2_o = 0.0;
    t15_2_B.g1_ref_term = 0.0;
    t15_2_B.Ipref_c = 0.0;
    t15_2_B.I9 = 0.0;
    t15_2_B.I8 = 0.0;
    t15_2_B.I7 = 0.0;
    t15_2_B.I6 = 0.0;
    t15_2_B.I5 = 0.0;
    t15_2_B.I4 = 0.0;
    t15_2_B.I3 = 0.0;
    t15_2_B.I2 = 0.0;
    t15_2_B.I11 = 0.0;
    t15_2_B.I10 = 0.0;
    t15_2_B.I1 = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&t15_2_DWork, 0,
                sizeof(D_Work_t15_2));
  t15_2_DWork.UD_DSTATE = 0.0;
  t15_2_DWork.UD_DSTATE_j = 0.0;
  t15_2_DWork.UD_DSTATE_o = 0.0;

  {
    int_T i;
    for (i = 0; i < 10; i++) {
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

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory1_PreviousInput_p[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory_PreviousInput_e[i] = 0.0;
    }
  }

  t15_2_DWork.Memory3_PreviousInput = 0.0;
  t15_2_DWork.Memory1_PreviousInput_c = 0.0;
  t15_2_DWork.Memory1_PreviousInput_d = 0.0;
  t15_2_DWork.Memory1_PreviousInput_i = 0.0;
  t15_2_DWork.Memory1_PreviousInput_g = 0.0;
  t15_2_DWork.Memory1_PreviousInput_gg = 0.0;
  t15_2_DWork.Memory2_PreviousInput_b = 0.0;
  t15_2_DWork.Memory1_PreviousInput_g2 = 0.0;
  t15_2_DWork.Memory1_PreviousInput_j = 0.0;
  t15_2_DWork.Memory2_PreviousInput_l = 0.0;
  t15_2_DWork.Memory2_PreviousInput_p = 0.0;
  t15_2_DWork.Memory2_PreviousInput_c = 0.0;
  t15_2_DWork.Memory2_PreviousInput_bw = 0.0;
  t15_2_DWork.Memory2_PreviousInput_m = 0.0;
  t15_2_DWork.Memory2_PreviousInput_e = 0.0;
  t15_2_DWork.Memory2_PreviousInput_lu = 0.0;
  t15_2_DWork.Memory2_PreviousInput_h = 0.0;
  t15_2_DWork.Memory2_PreviousInput_g = 0.0;
  t15_2_DWork.Memory2_PreviousInput_f = 0.0;
  t15_2_DWork.Memory2_PreviousInput_d = 0.0;
  t15_2_DWork.Memory1_PreviousInput_cn = 0.0;
  t15_2_DWork.Memory1_PreviousInput_i3 = 0.0;
  t15_2_DWork.Memory1_PreviousInput_l = 0.0;

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory2_PreviousInput_k[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Sum3_DWORK1[i] = 0.0;
    }
  }

  t15_2_DWork.Memory2_PreviousInput_gi = 0.0;

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
      t15_2_Y.to_DINA[i] = 0.0;
    }
  }

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmin;

    /* Start for UniformRandomNumber: '<S47>/Uniform Random Number' */
    tmin = floor(t15_2_P.UniformRandomNumber_Seed);
    if (rtIsNaN(tmin) || rtIsInf(tmin)) {
      tmin = 0.0;
    } else {
      tmin = fmod(tmin, 4.294967296E+9);
    }

    tseed = tmin < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmin : (uint32_T)tmin;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
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
      (t15_2_P.UniformRandomNumber_Maximum - tmin) * rt_urand_Upu32_Yd_f_pw_snf(
      &t15_2_DWork.RandSeed) + tmin;

    /* End of Start for UniformRandomNumber: '<S47>/Uniform Random Number' */
  }

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S5>/UD' */
    t15_2_DWork.UD_DSTATE = t15_2_P.UD_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S34>/UD' */
    t15_2_DWork.UD_DSTATE_j = t15_2_P.UD_InitialCondition_b;

    /* InitializeConditions for UnitDelay: '<S35>/UD' */
    t15_2_DWork.UD_DSTATE_o = t15_2_P.UD_InitialCondition_m;

    /* InitializeConditions for DiscreteStateSpace: '<S41>/VS. contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.VScontr_DSTATE[0];
      for (i1=0; i1 < 10; i1++) {
        dw_DSTATE[i1] = t15_2_P.VScontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S12>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput = t15_2_P.Memory2_X0;

    /* InitializeConditions for Memory: '<S12>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput = t15_2_P.Memory1_X0;

    /* InitializeConditions for DiscreteStateSpace: '<S41>/VS. contr hl' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.VScontrhl_DSTATE[0];
      for (i1=0; i1 < 8; i1++) {
        dw_DSTATE[i1] = t15_2_P.VScontrhl_X0;
      }
    }

    /* InitializeConditions for Memory: '<S48>/Memory3' */
    t15_2_DWork.Memory3_PreviousInput = t15_2_P.Memory3_X0;

    /* InitializeConditions for Memory: '<S26>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_c = t15_2_P.Memory1_X0_f;

    /* InitializeConditions for Memory: '<S27>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_d = t15_2_P.Memory1_X0_c;

    /* InitializeConditions for Memory: '<S28>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_i = t15_2_P.Memory1_X0_p;

    /* InitializeConditions for Memory: '<S29>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_g = t15_2_P.Memory1_X0_n;

    /* InitializeConditions for Memory: '<S30>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_gg = t15_2_P.Memory1_X0_g;

    /* InitializeConditions for Memory: '<S31>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_b = t15_2_P.Memory2_X0_k;

    /* InitializeConditions for Memory: '<S31>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_g2 = t15_2_P.Memory1_X0_e;

    /* InitializeConditions for Memory: '<S10>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_j = t15_2_P.Memory1_X0_m;

    /* InitializeConditions for Memory: '<S15>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_l = t15_2_P.Memory2_X0_b;

    /* InitializeConditions for Memory: '<S18>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_p = t15_2_P.Memory2_X0_c;

    /* InitializeConditions for Memory: '<S19>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_c = t15_2_P.Memory2_X0_n;

    /* InitializeConditions for Memory: '<S20>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_bw = t15_2_P.Memory2_X0_nj;

    /* InitializeConditions for Memory: '<S21>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_m = t15_2_P.Memory2_X0_bm;

    /* InitializeConditions for Memory: '<S22>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_e = t15_2_P.Memory2_X0_g;

    /* InitializeConditions for Memory: '<S23>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_lu = t15_2_P.Memory2_X0_bh;

    /* InitializeConditions for Memory: '<S24>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_h = t15_2_P.Memory2_X0_e;

    /* InitializeConditions for Memory: '<S25>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_g = t15_2_P.Memory2_X0_bc;

    /* InitializeConditions for Memory: '<S16>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_f = t15_2_P.Memory2_X0_f;

    /* InitializeConditions for Memory: '<S17>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_d = t15_2_P.Memory2_X0_i;

    /* InitializeConditions for DiscreteStateSpace: '<S7>/Div. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Divcontr_DSTATE[0];
      for (i1=0; i1 < 50; i1++) {
        dw_DSTATE[i1] = t15_2_P.Divcontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S46>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_cn = t15_2_P.Memory1_X0_a;

    /* InitializeConditions for DiscreteStateSpace: '<S7>/Div_rd contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Div_rdcontr_DSTATE[0];
      for (i1=0; i1 < 40; i1++) {
        dw_DSTATE[i1] = t15_2_P.Div_rdcontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S44>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_i3 = t15_2_P.Memory1_X0_nr;

    /* InitializeConditions for Memory: '<S45>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_l = t15_2_P.Memory1_X0_j;

    /* InitializeConditions for DiscreteStateSpace: '<S7>/Curr. term. contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Currtermcontr_DSTATE[0];
      for (i1=0; i1 < 40; i1++) {
        dw_DSTATE[i1] = t15_2_P.Currtermcontr_X0;
      }
    }

    for (i = 0; i < 11; i++) {
      /* InitializeConditions for Memory: '<S2>/Memory' */
      t15_2_DWork.Memory_PreviousInput[i] = t15_2_P.Memory_X0;

      /* InitializeConditions for RateLimiter: '<S2>/Rate Limiter' */
      t15_2_DWork.PrevY[i] = t15_2_P.RateLimiter_IC;

      /* InitializeConditions for Memory: '<S37>/Memory1' */
      t15_2_DWork.Memory1_PreviousInput_p[i] = t15_2_P.Memory1_X0_k;

      /* InitializeConditions for Memory: '<S39>/Memory' */
      t15_2_DWork.Memory_PreviousInput_e[i] = t15_2_P.Memory_X0_j;

      /* InitializeConditions for Memory: '<S38>/Memory2' */
      t15_2_DWork.Memory2_PreviousInput_k[i] = t15_2_P.Memory2_X0_e1;
    }

    /* InitializeConditions for DiscreteStateSpace: '<S38>/Lim. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Limcontr_DSTATE[0];
      for (i1=0; i1 < 50; i1++) {
        dw_DSTATE[i1] = t15_2_P.Limcontr_X0;
      }
    }

    /* InitializeConditions for DiscreteStateSpace: '<S38>/Curr. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Currcontr_DSTATE[0];
      for (i1=0; i1 < 11; i1++) {
        dw_DSTATE[i1] = t15_2_P.Currcontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_gi = t15_2_P.Memory2_X0_d;
  }
}

/* Model terminate function */
void t15_2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
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


	  printf("---t15_2_step  \n");



  /* external outputs */
  //real_T Out1[15];
  	  k=0;

      for (i = 0; i < 15; i++) 
	  { output[i]=t15_2_Y.to_DINA[i] ;
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
	  { output[i+ki]=t15_2_B.wz[i] ;
	  k=k+1;
      }

	  i=11;
	  output[i+ki]=t15_2_B.wz[i] ;

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
