//! t15_2.c is the main subroutine to read the input 
//! control_init.dat file

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
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <Windows.h>

#include "t15_2.h"
#include "t15_2_private.h"
int kpr1=0, kpr =0;

//kpr1=0;

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
  real_T tmin;
  int32_T i;
  int32_T i_0;
  real_T u;
  real_T u_0;

  /* Level2 S-Function Block: '<S5>/S-Function1' (pf_lookup3) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* DataStoreWrite: '<S5>/Data Store Write' */
  memcpy(&t15_2_DWork.scr_data[0], &t15_2_B.SFunction1[0], 6500U * sizeof(real_T));

  /* Level2 S-Function Block: '<S5>/S-Function2' (read_volt) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* DataStoreWrite: '<S5>/Data Store Write1' */
  memcpy(&t15_2_DWork.volt[0], &t15_2_B.SFunction2[0], 10000U * sizeof(real_T));

  /* Level2 S-Function Block: '<S5>/S-Function' (read_control_data2) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* DataStoreWrite: '<S5>/Data Store Write10' */
  t15_2_DWork.c_a_tpl1_eob = t15_2_B.SFunction[10];

  /* DataStoreWrite: '<S5>/Data Store Write11' */
  t15_2_DWork.c_a_tpl2 = t15_2_B.SFunction[11];

  /* DataStoreWrite: '<S5>/Data Store Write12' */
  t15_2_DWork.c_a_tpl_min = t15_2_B.SFunction[12];

  /* DataStoreWrite: '<S5>/Data Store Write13' */
  t15_2_DWork.y0 = t15_2_B.SFunction[13];

  /* DataStoreWrite: '<S5>/Data Store Write14' */
  t15_2_DWork.c1_y0 = t15_2_B.SFunction[14];

  /* DataStoreWrite: '<S5>/Data Store Write15' */
  t15_2_DWork.c2_y0 = t15_2_B.SFunction[15];

  /* DataStoreWrite: '<S5>/Data Store Write16' */
  t15_2_DWork.t_tran2D = t15_2_B.SFunction[16];

  /* DataStoreWrite: '<S5>/Data Store Write17' */
  t15_2_DWork.max_VS_lim = t15_2_B.SFunction[6];

  /* DataStoreWrite: '<S5>/Data Store Write18' */
  t15_2_DWork.k_g4 = t15_2_B.SFunction[7];

  /* DataStoreWrite: '<S5>/Data Store Write2' */
  t15_2_DWork.c_a_tpl1 = t15_2_B.SFunction[9];

  /* DataStoreWrite: '<S5>/Data Store Write3' */
  t15_2_DWork.tcont2 = t15_2_B.SFunction[0];

  /* DataStoreWrite: '<S5>/Data Store Write4' */
  t15_2_DWork.Ip_div = t15_2_B.SFunction[2];

  /* DataStoreWrite: '<S5>/Data Store Write5' */
  t15_2_DWork.ref_ramp = t15_2_B.SFunction[3];

  /* DataStoreWrite: '<S5>/Data Store Write6' */
  t15_2_DWork.dtcont2 = t15_2_B.SFunction[1];

  /* DataStoreWrite: '<S5>/Data Store Write7' */
  t15_2_DWork.Ip_rd = t15_2_B.SFunction[4];

  /* DataStoreWrite: '<S5>/Data Store Write8' */
  t15_2_DWork.trd_ref = t15_2_B.SFunction[5];

  /* DataStoreWrite: '<S5>/Data Store Write9' */
  t15_2_DWork.Time_stop = t15_2_B.SFunction[8];

  /* Gain: '<S5>/Time s' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_B.Times = t15_2_P.Times_Gain * t15_2_U.In1[8];

  /* Memory: '<S5>/Memory2' */
  t15_2_B.Memory2 = t15_2_DWork.Memory2_PreviousInput;

  /* Gain: '<S5>/-1' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_B.u = t15_2_P.u_Gain * t15_2_U.In1[3];

  /* Switch: '<S5>/Ip<1e-4 ' */
  if (t15_2_B.u > t15_2_P.Ip1e4_Threshold) {
    t15_2_B.Ip1e4 = t15_2_B.Memory2;
  } else {
    t15_2_B.Ip1e4 = t15_2_B.Times;
  }

  /* End of Switch: '<S5>/Ip<1e-4 ' */

  /* DataStoreRead: '<S5>/Data Store Read' */
  t15_2_B.DataStoreRead = t15_2_DWork.RupRd[3];

  /* Sum: '<S5>/Sum2' */
  t15_2_B.Sum2 = t15_2_B.Ip1e4 + t15_2_B.DataStoreRead;

  /* RelationalOperator: '<S5>/Relational Operator' */
  t15_2_B.RelationalOperator_c = (t15_2_B.Times >= t15_2_B.Sum2);

  /* Stop: '<S5>/Stop Simulation' */
  if (t15_2_B.RelationalOperator_c) {
    rtmSetStopRequested(t15_2_M, 1);
  }

  /* End of Stop: '<S5>/Stop Simulation' */

  /* DataStoreRead: '<S5>/Data Store Read1' */
  t15_2_B.DataStoreRead1 = t15_2_DWork.Time_stop;

  /* RelationalOperator: '<S5>/Relational Operator1' */
  t15_2_B.RelationalOperator1_h = (t15_2_B.Times >= t15_2_B.DataStoreRead1);

  /* Stop: '<S5>/Stop Simulation1' */
  if (t15_2_B.RelationalOperator1_h) {
    rtmSetStopRequested(t15_2_M, 1);
  }

  /* End of Stop: '<S5>/Stop Simulation1' */

  /* Gain: '<S14>/1e-6' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_B.e6 = t15_2_P.e6_Gain * t15_2_U.In1[3];

  /* Gain: '<S14>/1e-6   ' incorporates:
   *  Inport: '<Root>/In2'
   */
  for (i = 0; i < 15; i++) {
    t15_2_B.e6_i[i] = t15_2_U.In2[i + 6] * t15_2_P.e6_Gain_h;
  }

  /* End of Gain: '<S14>/1e-6   ' */

  /* Memory: '<S17>/Memory1' */
  t15_2_B.Memory1 = t15_2_DWork.Memory1_PreviousInput;

  /* DataStoreRead: '<S17>/Data Store Read1' */
  t15_2_B.DataStoreRead1_k = t15_2_DWork.RupRd[4];

  /* Gain: '<S17>/1e-3' */
  t15_2_B.e3 = t15_2_P.e3_Gain * t15_2_B.DataStoreRead1_k;

  /* DataStoreRead: '<S17>/Data Store Read2' */
  t15_2_B.DataStoreRead2 = t15_2_DWork.ntur[2];

  /* Product: '<S17>/Product1' */
  t15_2_B.Product1 = t15_2_B.e3 * t15_2_B.DataStoreRead2;

  /* RelationalOperator: '<S17>/Relational Operator' */
  t15_2_B.RelationalOperator = (t15_2_B.e6_i[2] < t15_2_B.Product1);

  /* Memory: '<S25>/Memory' */
  t15_2_B.Memory = t15_2_DWork.Memory_PreviousInput;

  /* Logic: '<S25>/Logical Operator' */
  t15_2_B.LogicalOperator = ((t15_2_B.RelationalOperator != 0.0) ||
    (t15_2_B.Memory != 0.0));

  /* Switch: '<S17>/switch1' */
  if (t15_2_B.LogicalOperator >= t15_2_P.switch1_Threshold) {
    t15_2_B.switch1 = t15_2_B.Memory1;
  } else {
    t15_2_B.switch1 = t15_2_B.Times;
  }

  /* End of Switch: '<S17>/switch1' */

  /* Sum: '<S17>/Add2' */
  t15_2_B.Add2 = t15_2_B.switch1 - t15_2_B.Times;

  /* DataStoreRead: '<S17>/Data Store Read' */
  t15_2_B.DataStoreRead_o = t15_2_DWork.RupRd[1];

  /* Product: '<S17>/Product' */
  t15_2_B.Product = t15_2_B.Add2 / t15_2_B.DataStoreRead_o;

  /* Sum: '<S17>/Add1' incorporates:
   *  Constant: '<S17>/Constant4'
   */
  t15_2_B.Add1 = t15_2_B.Product + t15_2_P.Constant4_Value_j;

  /* Saturate: '<S17>/1 0' */
  tmin = t15_2_B.Add1;
  u = t15_2_P.u_LowerSat;
  u_0 = t15_2_P.u_UpperSat;
  if (tmin >= u_0) {
    t15_2_B.u_f = u_0;
  } else if (tmin <= u) {
    t15_2_B.u_f = u;
  } else {
    t15_2_B.u_f = tmin;
  }

  /* End of Saturate: '<S17>/1 0' */

  /* Memory: '<S18>/Memory1' */
  t15_2_B.Memory1_h = t15_2_DWork.Memory1_PreviousInput_p;

  /* Switch: '<S18>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_m) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S18>/Data Store Read1' */
      t15_2_B.DataStoreRead1_iq[i] = t15_2_DWork.scr_data[13 * i + 1];

      /* DataStoreRead: '<S18>/Data Store Read' */
      t15_2_B.DataStoreRead_df[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S18>/Ipref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.Ipref), &t15_2_B.DataStoreRead1_iq[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_df[0], 499U);
    t15_2_B.c_eob = t15_2_B.Ipref;
  } else {
    t15_2_B.c_eob = t15_2_B.Memory1_h;
  }

  /* End of Switch: '<S18>/c_eob' */

  /* Product: '<S18>/Divide6' */
  t15_2_B.Divide6 = t15_2_B.c_eob * t15_2_B.u_f;

  /* Sum: '<S14>/Add1' */
  t15_2_B.Add1_l = t15_2_B.e6 - t15_2_B.Divide6;

  /* Level2 S-Function Block: '<S21>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<S23>/1e2' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  t15_2_B.e2[0] = t15_2_P.e2_Gain * t15_2_U.In2[0];
  t15_2_B.e2[1] = t15_2_P.e2_Gain * t15_2_U.In2[1];
  t15_2_B.e2[2] = t15_2_P.e2_Gain * t15_2_U.In1[6];
  t15_2_B.e2[3] = t15_2_P.e2_Gain * t15_2_U.In2[3];
  t15_2_B.e2[4] = t15_2_P.e2_Gain * t15_2_U.In2[4];
  t15_2_B.e2[5] = t15_2_P.e2_Gain * t15_2_U.In1[5];

  /* Level2 S-Function Block: '<S44>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S44>/Memory2' */
  t15_2_B.Memory2_l = t15_2_DWork.Memory2_PreviousInput_h;

  /* Switch: '<S44>/c_eob  1' */
  if (t15_2_B.u_f >= t15_2_P.c_eob1_Threshold) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S44>/Selector' */
      t15_2_B.Selector_j[i] = t15_2_B.SFunction1_m[(i << 1) + 1];

      /* Selector: '<S44>/Selector1' */
      t15_2_B.Selector1_d[i] = t15_2_B.SFunction1_m[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S44>/g1ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g1ref), &t15_2_B.Selector_j[0],
                         t15_2_B.Times, &t15_2_B.Selector1_d[0], 49U);
    t15_2_B.c_eob1 = t15_2_B.g1ref;
  } else {
    t15_2_B.c_eob1 = t15_2_B.Memory2_l;
  }

  /* End of Switch: '<S44>/c_eob  1' */

  /* Memory: '<S44>/Memory1' */
  t15_2_B.Memory1_f = t15_2_DWork.Memory1_PreviousInput_k;

  /* Switch: '<S44>/c_eob  ' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_j) {
    t15_2_B.c_eob_h = t15_2_B.Times;
  } else {
    t15_2_B.c_eob_h = t15_2_B.Memory1_f;
  }

  /* End of Switch: '<S44>/c_eob  ' */

  /* Level2 S-Function Block: '<S50>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[5];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S44>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_a) {
    t15_2_B.c_eob_b = t15_2_B.c_eob1;
  } else {
    /* SignalConversion: '<S50>/TmpSignal ConversionAtg1_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg1_termref[0] = t15_2_B.c_eob1;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S50>/Selector' */
      t15_2_B.Selector[i] = t15_2_B.SFunction1_p[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg1_termref[i + 1] = t15_2_B.Selector[i];
    }

    /* End of SignalConversion: '<S50>/TmpSignal ConversionAtg1_term,refInport3' */

    /* DataStoreRead: '<S50>/Data Store Read1' */
    t15_2_B.DataStoreRead1_en = t15_2_DWork.trd_ref;

    /* DataStoreRead: '<S50>/Data Store Read' */
    t15_2_B.DataStoreRead_n = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S50>/Selector1' */
      t15_2_B.Selector1[i] = t15_2_B.SFunction1_p[i << 1];

      /* Product: '<S50>/Divide6' */
      t15_2_B.Divide6_a[i] = t15_2_B.Selector1[i] * t15_2_B.DataStoreRead_n /
        t15_2_B.DataStoreRead1_en;

      /* Sum: '<S50>/Add2' */
      t15_2_B.Add2_h[i] = t15_2_B.c_eob_h + t15_2_B.Divide6_a[i];
    }

    /* Dynamic Look-Up Table Block: '<S50>/g1_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g1_termref),
                         &t15_2_B.TmpSignalConversionAtg1_termref[0],
                         t15_2_B.Times, &t15_2_B.Add2_h[0], 49U);
    t15_2_B.c_eob_b = t15_2_B.g1_termref;
  }

  /* End of Switch: '<S44>/c_eob' */

  /* Sum: '<S23>/Add2' */
  t15_2_B.Add2_f = t15_2_B.e2[0] - t15_2_B.c_eob_b;

  /* Level2 S-Function Block: '<S39>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[6];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S39>/Memory2' */
  t15_2_B.Memory2_k = t15_2_DWork.Memory2_PreviousInput_o;

  /* Switch: '<S39>/c_eob  1' */
  if (t15_2_B.u_f >= t15_2_P.c_eob1_Threshold_d) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S39>/Selector' */
      t15_2_B.Selector_o[i] = t15_2_B.SFunction1_c[(i << 1) + 1];

      /* Selector: '<S39>/Selector1' */
      t15_2_B.Selector1_f[i] = t15_2_B.SFunction1_c[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S39>/g2ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g2ref), &t15_2_B.Selector_o[0],
                         t15_2_B.Times, &t15_2_B.Selector1_f[0], 49U);
    t15_2_B.c_eob1_d = t15_2_B.g2ref;
  } else {
    t15_2_B.c_eob1_d = t15_2_B.Memory2_k;
  }

  /* End of Switch: '<S39>/c_eob  1' */

  /* Memory: '<S39>/Memory1' */
  t15_2_B.Memory1_i = t15_2_DWork.Memory1_PreviousInput_d;

  /* Switch: '<S39>/c_eob  ' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_o) {
    t15_2_B.c_eob_a = t15_2_B.Times;
  } else {
    t15_2_B.c_eob_a = t15_2_B.Memory1_i;
  }

  /* End of Switch: '<S39>/c_eob  ' */

  /* Level2 S-Function Block: '<S45>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[7];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S39>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_jr) {
    t15_2_B.c_eob_j = t15_2_B.c_eob1_d;
  } else {
    /* SignalConversion: '<S45>/TmpSignal ConversionAtg2_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg2_termref[0] = t15_2_B.c_eob1_d;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S45>/Selector' */
      t15_2_B.Selector_n[i] = t15_2_B.SFunction1_o[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg2_termref[i + 1] = t15_2_B.Selector_n[i];
    }

    /* End of SignalConversion: '<S45>/TmpSignal ConversionAtg2_term,refInport3' */

    /* DataStoreRead: '<S45>/Data Store Read1' */
    t15_2_B.DataStoreRead1_hn = t15_2_DWork.trd_ref;

    /* DataStoreRead: '<S45>/Data Store Read' */
    t15_2_B.DataStoreRead_jp = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S45>/Selector1' */
      t15_2_B.Selector1_i[i] = t15_2_B.SFunction1_o[i << 1];

      /* Product: '<S45>/Divide6' */
      t15_2_B.Divide6_h[i] = t15_2_B.Selector1_i[i] * t15_2_B.DataStoreRead_jp /
        t15_2_B.DataStoreRead1_hn;

      /* Sum: '<S45>/Add2' */
      t15_2_B.Add2_fo[i] = t15_2_B.c_eob_a + t15_2_B.Divide6_h[i];
    }

    /* Dynamic Look-Up Table Block: '<S45>/g2_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g2_termref),
                         &t15_2_B.TmpSignalConversionAtg2_termref[0],
                         t15_2_B.Times, &t15_2_B.Add2_fo[0], 49U);
    t15_2_B.c_eob_j = t15_2_B.g2_termref;
  }

  /* End of Switch: '<S39>/c_eob' */

  /* Sum: '<S23>/Add1' */
  t15_2_B.Add1_j = t15_2_B.e2[1] - t15_2_B.c_eob_j;

  /* Level2 S-Function Block: '<S40>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[8];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S40>/Memory2' */
  t15_2_B.Memory2_n = t15_2_DWork.Memory2_PreviousInput_j;

  /* Switch: '<S40>/c_eob  1' */
  if (t15_2_B.u_f >= t15_2_P.c_eob1_Threshold_m) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S40>/Selector' */
      t15_2_B.Selector_jj[i] = t15_2_B.SFunction1_j[(i << 1) + 1];

      /* Selector: '<S40>/Selector1' */
      t15_2_B.Selector1_df[i] = t15_2_B.SFunction1_j[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S40>/g3ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g3ref), &t15_2_B.Selector_jj[0],
                         t15_2_B.Times, &t15_2_B.Selector1_df[0], 49U);
    t15_2_B.c_eob1_f = t15_2_B.g3ref;
  } else {
    t15_2_B.c_eob1_f = t15_2_B.Memory2_n;
  }

  /* End of Switch: '<S40>/c_eob  1' */

  /* Memory: '<S40>/Memory1' */
  t15_2_B.Memory1_d = t15_2_DWork.Memory1_PreviousInput_m;

  /* Switch: '<S40>/c_eob  ' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_e) {
    t15_2_B.c_eob_jz = t15_2_B.Times;
  } else {
    t15_2_B.c_eob_jz = t15_2_B.Memory1_d;
  }

  /* End of Switch: '<S40>/c_eob  ' */

  /* Level2 S-Function Block: '<S46>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[9];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S40>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_on) {
    t15_2_B.c_eob_l = t15_2_B.c_eob1_f;
  } else {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtg3_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg3_termref[0] = t15_2_B.c_eob1_f;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S46>/Selector' */
      t15_2_B.Selector_e[i] = t15_2_B.SFunction1_ce[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg3_termref[i + 1] = t15_2_B.Selector_e[i];
    }

    /* End of SignalConversion: '<S46>/TmpSignal ConversionAtg3_term,refInport3' */

    /* DataStoreRead: '<S46>/Data Store Read1' */
    t15_2_B.DataStoreRead1_er = t15_2_DWork.trd_ref;

    /* DataStoreRead: '<S46>/Data Store Read' */
    t15_2_B.DataStoreRead_ar = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S46>/Selector1' */
      t15_2_B.Selector1_j[i] = t15_2_B.SFunction1_ce[i << 1];

      /* Product: '<S46>/Divide6' */
      t15_2_B.Divide6_p[i] = t15_2_B.Selector1_j[i] * t15_2_B.DataStoreRead_ar /
        t15_2_B.DataStoreRead1_er;

      /* Sum: '<S46>/Add2' */
      t15_2_B.Add2_i[i] = t15_2_B.c_eob_jz + t15_2_B.Divide6_p[i];
    }

    /* Dynamic Look-Up Table Block: '<S46>/g3_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g3_termref),
                         &t15_2_B.TmpSignalConversionAtg3_termref[0],
                         t15_2_B.Times, &t15_2_B.Add2_i[0], 49U);
    t15_2_B.c_eob_l = t15_2_B.g3_termref;
  }

  /* End of Switch: '<S40>/c_eob' */

  /* Sum: '<S23>/Add3' */
  t15_2_B.Add3 = t15_2_B.e2[2] - t15_2_B.c_eob_l;

  /* Level2 S-Function Block: '<S41>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[10];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S41>/Memory2' */
  t15_2_B.Memory2_g = t15_2_DWork.Memory2_PreviousInput_e;

  /* Switch: '<S41>/c_eob  1' */
  if (t15_2_B.u_f >= t15_2_P.c_eob1_Threshold_g) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S41>/Selector' */
      t15_2_B.Selector_b[i] = t15_2_B.SFunction1_b[(i << 1) + 1];

      /* Selector: '<S41>/Selector1' */
      t15_2_B.Selector1_k[i] = t15_2_B.SFunction1_b[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S41>/g4ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g4ref), &t15_2_B.Selector_b[0],
                         t15_2_B.Times, &t15_2_B.Selector1_k[0], 49U);
    t15_2_B.c_eob1_c = t15_2_B.g4ref;
  } else {
    t15_2_B.c_eob1_c = t15_2_B.Memory2_g;
  }

  /* End of Switch: '<S41>/c_eob  1' */

  /* Memory: '<S41>/Memory1' */
  t15_2_B.Memory1_k = t15_2_DWork.Memory1_PreviousInput_py;

  /* Switch: '<S41>/c_eob  ' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_c) {
    t15_2_B.c_eob_aj = t15_2_B.Times;
  } else {
    t15_2_B.c_eob_aj = t15_2_B.Memory1_k;
  }

  /* End of Switch: '<S41>/c_eob  ' */

  /* Level2 S-Function Block: '<S47>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[11];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S41>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_onc) {
    t15_2_B.c_eob_bl = t15_2_B.c_eob1_c;
  } else {
    /* SignalConversion: '<S47>/TmpSignal ConversionAtg4_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg4_termref[0] = t15_2_B.c_eob1_c;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S47>/Selector' */
      t15_2_B.Selector_py[i] = t15_2_B.SFunction1_os[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg4_termref[i + 1] = t15_2_B.Selector_py[i];
    }

    /* End of SignalConversion: '<S47>/TmpSignal ConversionAtg4_term,refInport3' */

    /* DataStoreRead: '<S47>/Data Store Read1' */
    t15_2_B.DataStoreRead1_jh = t15_2_DWork.trd_ref;

    /* DataStoreRead: '<S47>/Data Store Read' */
    t15_2_B.DataStoreRead_bn = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S47>/Selector1' */
      t15_2_B.Selector1_h[i] = t15_2_B.SFunction1_os[i << 1];

      /* Product: '<S47>/Divide6' */
      t15_2_B.Divide6_d[i] = t15_2_B.Selector1_h[i] * t15_2_B.DataStoreRead_bn /
        t15_2_B.DataStoreRead1_jh;

      /* Sum: '<S47>/Add2' */
      t15_2_B.Add2_a[i] = t15_2_B.c_eob_aj + t15_2_B.Divide6_d[i];
    }

    /* Dynamic Look-Up Table Block: '<S47>/g4_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g4_termref),
                         &t15_2_B.TmpSignalConversionAtg4_termref[0],
                         t15_2_B.Times, &t15_2_B.Add2_a[0], 49U);
    t15_2_B.c_eob_bl = t15_2_B.g4_termref;
  }

  /* End of Switch: '<S41>/c_eob' */

  /* Sum: '<S23>/Add4' */
  t15_2_B.Add4 = t15_2_B.e2[3] - t15_2_B.c_eob_bl;

  /* DataStoreRead: '<S23>/Data Store Read' */
  t15_2_B.DataStoreRead_h = t15_2_DWork.t_tran2D;

  /* RelationalOperator: '<S23>/Relational Operator1' */
  t15_2_B.RelationalOperator1 = (t15_2_B.Times > t15_2_B.DataStoreRead_h);

  /* Product: '<S23>/Divide12' */
  t15_2_B.Divide12 = t15_2_B.Add4 * t15_2_B.RelationalOperator1;

  /* Level2 S-Function Block: '<S42>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[12];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S42>/Memory2' */
  t15_2_B.Memory2_h = t15_2_DWork.Memory2_PreviousInput_k;

  /* Switch: '<S42>/c_eob  1' */
  if (t15_2_B.u_f >= t15_2_P.c_eob1_Threshold_k) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S42>/Selector' */
      t15_2_B.Selector_p[i] = t15_2_B.SFunction1_cx[(i << 1) + 1];

      /* Selector: '<S42>/Selector1' */
      t15_2_B.Selector1_m[i] = t15_2_B.SFunction1_cx[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S42>/g5ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g5ref), &t15_2_B.Selector_p[0],
                         t15_2_B.Times, &t15_2_B.Selector1_m[0], 49U);
    t15_2_B.c_eob1_g = t15_2_B.g5ref;
  } else {
    t15_2_B.c_eob1_g = t15_2_B.Memory2_h;
  }

  /* End of Switch: '<S42>/c_eob  1' */

  /* Memory: '<S42>/Memory1' */
  t15_2_B.Memory1_g = t15_2_DWork.Memory1_PreviousInput_h;

  /* Switch: '<S42>/c_eob  ' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_a5) {
    t15_2_B.c_eob_d = t15_2_B.Times;
  } else {
    t15_2_B.c_eob_d = t15_2_B.Memory1_g;
  }

  /* End of Switch: '<S42>/c_eob  ' */

  /* Level2 S-Function Block: '<S48>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[13];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S42>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_f) {
    t15_2_B.c_eob_f = t15_2_B.c_eob1_g;
  } else {
    /* SignalConversion: '<S48>/TmpSignal ConversionAtg5_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg5_termref[0] = t15_2_B.c_eob1_g;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S48>/Selector' */
      t15_2_B.Selector_d[i] = t15_2_B.SFunction1_n[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg5_termref[i + 1] = t15_2_B.Selector_d[i];
    }

    /* End of SignalConversion: '<S48>/TmpSignal ConversionAtg5_term,refInport3' */

    /* DataStoreRead: '<S48>/Data Store Read1' */
    t15_2_B.DataStoreRead1_am = t15_2_DWork.trd_ref;

    /* DataStoreRead: '<S48>/Data Store Read' */
    t15_2_B.DataStoreRead_jrb = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S48>/Selector1' */
      t15_2_B.Selector1_n[i] = t15_2_B.SFunction1_n[i << 1];

      /* Product: '<S48>/Divide6' */
      t15_2_B.Divide6_g[i] = t15_2_B.Selector1_n[i] * t15_2_B.DataStoreRead_jrb /
        t15_2_B.DataStoreRead1_am;

      /* Sum: '<S48>/Add2' */
      t15_2_B.Add2_k[i] = t15_2_B.c_eob_d + t15_2_B.Divide6_g[i];
    }

    /* Dynamic Look-Up Table Block: '<S48>/g5_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g5_termref),
                         &t15_2_B.TmpSignalConversionAtg5_termref[0],
                         t15_2_B.Times, &t15_2_B.Add2_k[0], 49U);
    t15_2_B.c_eob_f = t15_2_B.g5_termref;
  }

  /* End of Switch: '<S42>/c_eob' */

  /* Sum: '<S23>/Add5' */
  t15_2_B.Add5 = t15_2_B.e2[4] - t15_2_B.c_eob_f;

  /* Level2 S-Function Block: '<S43>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[14];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S43>/Memory2' */
  t15_2_B.Memory2_nz = t15_2_DWork.Memory2_PreviousInput_n;

  /* Switch: '<S43>/c_eob  1' */
  if (t15_2_B.u_f >= t15_2_P.c_eob1_Threshold_o) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S43>/Selector' */
      t15_2_B.Selector_i[i] = t15_2_B.SFunction1_i[(i << 1) + 1];

      /* Selector: '<S43>/Selector1' */
      t15_2_B.Selector1_b[i] = t15_2_B.SFunction1_i[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S43>/g6ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g6ref), &t15_2_B.Selector_i[0],
                         t15_2_B.Times, &t15_2_B.Selector1_b[0], 49U);
    t15_2_B.c_eob1_h = t15_2_B.g6ref;
  } else {
    t15_2_B.c_eob1_h = t15_2_B.Memory2_nz;
  }

  /* End of Switch: '<S43>/c_eob  1' */

  /* Memory: '<S43>/Memory1' */
  t15_2_B.Memory1_p = t15_2_DWork.Memory1_PreviousInput_g;

  /* Switch: '<S43>/c_eob  ' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_d) {
    t15_2_B.c_eob_o = t15_2_B.Times;
  } else {
    t15_2_B.c_eob_o = t15_2_B.Memory1_p;
  }

  /* End of Switch: '<S43>/c_eob  ' */

  /* Level2 S-Function Block: '<S49>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[15];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S43>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_ci) {
    t15_2_B.c_eob_fp = t15_2_B.c_eob1_h;
  } else {
    /* SignalConversion: '<S49>/TmpSignal ConversionAtg6_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg6_termref[0] = t15_2_B.c_eob1_h;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S49>/Selector' */
      t15_2_B.Selector_f[i] = t15_2_B.SFunction1_h[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg6_termref[i + 1] = t15_2_B.Selector_f[i];
    }

    /* End of SignalConversion: '<S49>/TmpSignal ConversionAtg6_term,refInport3' */

    /* DataStoreRead: '<S49>/Data Store Read1' */
    t15_2_B.DataStoreRead1_f = t15_2_DWork.trd_ref;

    /* DataStoreRead: '<S49>/Data Store Read' */
    t15_2_B.DataStoreRead_jr = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S49>/Selector1' */
      t15_2_B.Selector1_dx[i] = t15_2_B.SFunction1_h[i << 1];

      /* Product: '<S49>/Divide6' */
      t15_2_B.Divide6_b[i] = t15_2_B.Selector1_dx[i] * t15_2_B.DataStoreRead_jr /
        t15_2_B.DataStoreRead1_f;

      /* Sum: '<S49>/Add2' */
      t15_2_B.Add2_g[i] = t15_2_B.c_eob_o + t15_2_B.Divide6_b[i];
    }

    /* Dynamic Look-Up Table Block: '<S49>/g6_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g6_termref),
                         &t15_2_B.TmpSignalConversionAtg6_termref[0],
                         t15_2_B.Times, &t15_2_B.Add2_g[0], 49U);
    t15_2_B.c_eob_fp = t15_2_B.g6_termref;
  }

  /* End of Switch: '<S43>/c_eob' */

  /* Sum: '<S23>/Add6' */
  t15_2_B.Add6 = t15_2_B.e2[5] - t15_2_B.c_eob_fp;

  /* Gain: '<S23>/1e-2' */
  t15_2_B.e2_f[0] = t15_2_P.e2_Gain_e * t15_2_B.Add2_f;
  t15_2_B.e2_f[1] = t15_2_P.e2_Gain_e * t15_2_B.Add1_j;
  t15_2_B.e2_f[2] = t15_2_P.e2_Gain_e * t15_2_B.Add3;
  t15_2_B.e2_f[3] = t15_2_P.e2_Gain_e * t15_2_B.Divide12;
  t15_2_B.e2_f[4] = t15_2_P.e2_Gain_e * t15_2_B.Add5;
  t15_2_B.e2_f[5] = t15_2_P.e2_Gain_e * t15_2_B.Add6;

  /* Memory: '<S28>/Memory2' */
  t15_2_B.Memory2_ht = t15_2_DWork.Memory2_PreviousInput_b;

  /* Switch: '<S28>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_jx) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S28>/Data Store Read1' */
      t15_2_B.DataStoreRead1_ph[i] = t15_2_DWork.scr_data[13 * i + 2];

      /* DataStoreRead: '<S28>/Data Store Read' */
      t15_2_B.DataStoreRead_ho[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S28>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_b), &t15_2_B.DataStoreRead1_ph[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_ho[0], 499U);
    t15_2_B.c_eob_c = t15_2_B.I1_b;
  } else {
    t15_2_B.c_eob_c = t15_2_B.Memory2_ht;
  }

  /* End of Switch: '<S28>/c_eob' */

  /* Product: '<S28>/Divide1' */
  t15_2_B.Divide1 = t15_2_B.c_eob_c * t15_2_B.u_f;

  /* Sum: '<S22>/Add3' */
  t15_2_B.Add3_k = t15_2_B.e6_i[0] - t15_2_B.Divide1;

  /* Memory: '<S31>/Memory2' */
  t15_2_B.Memory2_c = t15_2_DWork.Memory2_PreviousInput_bu;

  /* Switch: '<S31>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_ao) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S31>/Data Store Read1' */
      t15_2_B.DataStoreRead1_os[i] = t15_2_DWork.scr_data[13 * i + 3];

      /* DataStoreRead: '<S31>/Data Store Read' */
      t15_2_B.DataStoreRead_dj[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S31>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_p), &t15_2_B.DataStoreRead1_os[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_dj[0], 499U);
    t15_2_B.c_eob_n = t15_2_B.I1_p;
  } else {
    t15_2_B.c_eob_n = t15_2_B.Memory2_c;
  }

  /* End of Switch: '<S31>/c_eob' */

  /* Product: '<S31>/Divide1' */
  t15_2_B.Divide1_a = t15_2_B.c_eob_n * t15_2_B.u_f;

  /* Sum: '<S22>/Add1' */
  t15_2_B.Add1_g = t15_2_B.e6_i[1] - t15_2_B.Divide1_a;

  /* Memory: '<S32>/Memory2' */
  t15_2_B.Memory2_kb = t15_2_DWork.Memory2_PreviousInput_op;

  /* Switch: '<S32>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_k) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S32>/Data Store Read1' */
      t15_2_B.DataStoreRead1_ey[i] = t15_2_DWork.scr_data[13 * i + 4];

      /* DataStoreRead: '<S32>/Data Store Read' */
      t15_2_B.DataStoreRead_ma[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S32>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_a), &t15_2_B.DataStoreRead1_ey[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_ma[0], 499U);
    t15_2_B.c_eob_k = t15_2_B.I1_a;
  } else {
    t15_2_B.c_eob_k = t15_2_B.Memory2_kb;
  }

  /* End of Switch: '<S32>/c_eob' */

  /* Product: '<S32>/Divide1' */
  t15_2_B.Divide1_b = t15_2_B.c_eob_k * t15_2_B.u_f;

  /* Sum: '<S22>/Add2' */
  t15_2_B.Add2_d = t15_2_B.e6_i[2] - t15_2_B.Divide1_b;

  /* Memory: '<S33>/Memory2' */
  t15_2_B.Memory2_b = t15_2_DWork.Memory2_PreviousInput_f;

  /* Switch: '<S33>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_j5) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S33>/Data Store Read1' */
      t15_2_B.DataStoreRead1_gu[i] = t15_2_DWork.scr_data[13 * i + 5];

      /* DataStoreRead: '<S33>/Data Store Read' */
      t15_2_B.DataStoreRead_hk[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S33>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_n), &t15_2_B.DataStoreRead1_gu[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_hk[0], 499U);
    t15_2_B.c_eob_g = t15_2_B.I1_n;
  } else {
    t15_2_B.c_eob_g = t15_2_B.Memory2_b;
  }

  /* End of Switch: '<S33>/c_eob' */

  /* Product: '<S33>/Divide1' */
  t15_2_B.Divide1_d = t15_2_B.c_eob_g * t15_2_B.u_f;

  /* Sum: '<S22>/Add4' */
  t15_2_B.Add4_d = t15_2_B.e6_i[3] - t15_2_B.Divide1_d;

  /* Memory: '<S34>/Memory2' */
  t15_2_B.Memory2_bc = t15_2_DWork.Memory2_PreviousInput_hg;

  /* Switch: '<S34>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_h) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S34>/Data Store Read1' */
      t15_2_B.DataStoreRead1_ii[i] = t15_2_DWork.scr_data[13 * i + 6];

      /* DataStoreRead: '<S34>/Data Store Read' */
      t15_2_B.DataStoreRead_mc[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S34>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_d), &t15_2_B.DataStoreRead1_ii[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_mc[0], 499U);
    t15_2_B.c_eob_jp = t15_2_B.I1_d;
  } else {
    t15_2_B.c_eob_jp = t15_2_B.Memory2_bc;
  }

  /* End of Switch: '<S34>/c_eob' */

  /* Product: '<S34>/Divide1' */
  t15_2_B.Divide1_i = t15_2_B.c_eob_jp * t15_2_B.u_f;

  /* Sum: '<S22>/Add5' */
  t15_2_B.Add5_j = t15_2_B.e6_i[4] - t15_2_B.Divide1_i;

  /* Memory: '<S35>/Memory2' */
  t15_2_B.Memory2_p = t15_2_DWork.Memory2_PreviousInput_g;

  /* Switch: '<S35>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_jv) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S35>/Data Store Read1' */
      t15_2_B.DataStoreRead1_bc[i] = t15_2_DWork.scr_data[13 * i + 7];

      /* DataStoreRead: '<S35>/Data Store Read' */
      t15_2_B.DataStoreRead_cr[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S35>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_m), &t15_2_B.DataStoreRead1_bc[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_cr[0], 499U);
    t15_2_B.c_eob_m = t15_2_B.I1_m;
  } else {
    t15_2_B.c_eob_m = t15_2_B.Memory2_p;
  }

  /* End of Switch: '<S35>/c_eob' */

  /* Product: '<S35>/Divide1' */
  t15_2_B.Divide1_l = t15_2_B.c_eob_m * t15_2_B.u_f;

  /* Sum: '<S22>/Add6' */
  t15_2_B.Add6_e = t15_2_B.e6_i[5] - t15_2_B.Divide1_l;

  /* Memory: '<S36>/Memory2' */
  t15_2_B.Memory2_a = t15_2_DWork.Memory2_PreviousInput_c;

  /* Switch: '<S36>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_mo) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S36>/Data Store Read1' */
      t15_2_B.DataStoreRead1_nh[i] = t15_2_DWork.scr_data[13 * i + 8];

      /* DataStoreRead: '<S36>/Data Store Read' */
      t15_2_B.DataStoreRead_i3[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S36>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_i), &t15_2_B.DataStoreRead1_nh[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_i3[0], 499U);
    t15_2_B.c_eob_cm = t15_2_B.I1_i;
  } else {
    t15_2_B.c_eob_cm = t15_2_B.Memory2_a;
  }

  /* End of Switch: '<S36>/c_eob' */

  /* Product: '<S36>/Divide1' */
  t15_2_B.Divide1_n = t15_2_B.c_eob_cm * t15_2_B.u_f;

  /* Sum: '<S22>/Add7' */
  t15_2_B.Add7 = t15_2_B.e6_i[6] - t15_2_B.Divide1_n;

  /* Memory: '<S37>/Memory2' */
  t15_2_B.Memory2_i = t15_2_DWork.Memory2_PreviousInput_jv;

  /* Switch: '<S37>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_g) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S37>/Data Store Read1' */
      t15_2_B.DataStoreRead1_dz[i] = t15_2_DWork.scr_data[13 * i + 9];

      /* DataStoreRead: '<S37>/Data Store Read' */
      t15_2_B.DataStoreRead_nv[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S37>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_j), &t15_2_B.DataStoreRead1_dz[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_nv[0], 499U);
    t15_2_B.c_eob_h3 = t15_2_B.I1_j;
  } else {
    t15_2_B.c_eob_h3 = t15_2_B.Memory2_i;
  }

  /* End of Switch: '<S37>/c_eob' */

  /* Product: '<S37>/Divide1' */
  t15_2_B.Divide1_dv = t15_2_B.c_eob_h3 * t15_2_B.u_f;

  /* Sum: '<S22>/Add8' */
  t15_2_B.Add8 = t15_2_B.e6_i[7] - t15_2_B.Divide1_dv;

  /* Memory: '<S38>/Memory2' */
  t15_2_B.Memory2_bl = t15_2_DWork.Memory2_PreviousInput_hu;

  /* Switch: '<S38>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_n) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S38>/Data Store Read1' */
      t15_2_B.DataStoreRead1_gh[i] = t15_2_DWork.scr_data[13 * i + 10];

      /* DataStoreRead: '<S38>/Data Store Read' */
      t15_2_B.DataStoreRead_jm[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S38>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1), &t15_2_B.DataStoreRead1_gh[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_jm[0], 499U);
    t15_2_B.c_eob_gm = t15_2_B.I1;
  } else {
    t15_2_B.c_eob_gm = t15_2_B.Memory2_bl;
  }

  /* End of Switch: '<S38>/c_eob' */

  /* Product: '<S38>/Divide1' */
  t15_2_B.Divide1_m = t15_2_B.c_eob_gm * t15_2_B.u_f;

  /* Sum: '<S22>/Add9' */
  t15_2_B.Add9 = t15_2_B.e6_i[8] - t15_2_B.Divide1_m;

  /* Memory: '<S29>/Memory2' */
  t15_2_B.Memory2_i0 = t15_2_DWork.Memory2_PreviousInput_g2;

  /* Switch: '<S29>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_b) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S29>/Data Store Read1' */
      t15_2_B.DataStoreRead1_li[i] = t15_2_DWork.scr_data[13 * i + 11];

      /* DataStoreRead: '<S29>/Data Store Read' */
      t15_2_B.DataStoreRead_ay[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S29>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_o), &t15_2_B.DataStoreRead1_li[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_ay[0], 499U);
    t15_2_B.c_eob_cn = t15_2_B.I1_o;
  } else {
    t15_2_B.c_eob_cn = t15_2_B.Memory2_i0;
  }

  /* End of Switch: '<S29>/c_eob' */

  /* Product: '<S29>/Divide1' */
  t15_2_B.Divide1_aa = t15_2_B.c_eob_cn * t15_2_B.u_f;

  /* Sum: '<S22>/Add10' */
  t15_2_B.Add10 = t15_2_B.e6_i[9] - t15_2_B.Divide1_aa;

  /* Memory: '<S30>/Memory2' */
  t15_2_B.Memory2_ai = t15_2_DWork.Memory2_PreviousInput_b1;

  /* Switch: '<S30>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_hc) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S30>/Data Store Read1' */
      t15_2_B.DataStoreRead1_pa[i] = t15_2_DWork.scr_data[13 * i + 12];

      /* DataStoreRead: '<S30>/Data Store Read' */
      t15_2_B.DataStoreRead_e0[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S30>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_e), &t15_2_B.DataStoreRead1_pa[0],
                         t15_2_B.Times, &t15_2_B.DataStoreRead_e0[0], 499U);
    t15_2_B.c_eob_cg = t15_2_B.I1_e;
  } else {
    t15_2_B.c_eob_cg = t15_2_B.Memory2_ai;
  }

  /* End of Switch: '<S30>/c_eob' */

  /* Product: '<S30>/Divide1' */
  t15_2_B.Divide1_k = t15_2_B.c_eob_cg * t15_2_B.u_f;

  /* Sum: '<S22>/Add11' */
  t15_2_B.Add11 = t15_2_B.e6_i[10] - t15_2_B.Divide1_k;

  /* DataStoreRead: '<S19>/Data Store Read' */
  t15_2_B.DataStoreRead_a = t15_2_DWork.Ip_div;

  /* RelationalOperator: '<S19>/Relational Operator1' */
  t15_2_B.RelationalOperator1_e = (t15_2_B.Times > t15_2_B.DataStoreRead_a);

  /* Switch: '<S19>/1' incorporates:
   *  Constant: '<S14>/Constant4'
   */
  if (t15_2_B.RelationalOperator1_e >= t15_2_P._Threshold_m) {
    for (i = 0; i < 6; i++) {
      t15_2_B.u_i[i] = t15_2_B.e2_f[i];
    }

    t15_2_B.u_i[6] = t15_2_P.Constant4_Value_p;
    t15_2_B.u_i[7] = t15_2_B.Add1_l;
    t15_2_B.u_i[8] = t15_2_B.Add3_k;
    t15_2_B.u_i[9] = t15_2_B.Add1_g;
    t15_2_B.u_i[10] = t15_2_B.Add2_d;
    t15_2_B.u_i[11] = t15_2_B.Add4_d;
    t15_2_B.u_i[12] = t15_2_B.Add5_j;
    t15_2_B.u_i[13] = t15_2_B.Add6_e;
    t15_2_B.u_i[14] = t15_2_B.Add7;
    t15_2_B.u_i[15] = t15_2_B.Add8;
    t15_2_B.u_i[16] = t15_2_B.Add9;
    t15_2_B.u_i[17] = t15_2_B.Add10;
    t15_2_B.u_i[18] = t15_2_B.Add11;
    t15_2_B.u_i[19] = t15_2_P.Constant4_Value_p;
  } else {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S21>/Selector' */
      t15_2_B.Selector_h[i] = t15_2_B.SFunction1_d[(i << 1) + 1];

      /* Selector: '<S21>/Selector1' */
      t15_2_B.Selector1_a[i] = t15_2_B.SFunction1_d[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S21>/elong'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.elong), &t15_2_B.Selector_h[0],
                         t15_2_B.Times, &t15_2_B.Selector1_a[0], 49U);

    /* Sum: '<S14>/Add2' incorporates:
     *  Inport: '<Root>/In1'
     */
    t15_2_B.Add2_gh = t15_2_U.In1[2] - t15_2_B.elong;

    /* DataStoreRead: '<S24>/Data Store Read1' */
    t15_2_B.DataStoreRead1_jm = t15_2_DWork.k_g4;

    /* Product: '<S24>/Divide' incorporates:
     *  Constant: '<S24>/Constant1'
     *  Constant: '<S24>/Constant2'
     *  Constant: '<S24>/Constant4'
     */
    t15_2_B.Divide_h[0] = t15_2_B.e2_f[2] * t15_2_P.Constant4_Value;
    t15_2_B.Divide_h[1] = t15_2_B.e2_f[3] * t15_2_B.DataStoreRead1_jm;
    t15_2_B.Divide_h[2] = t15_2_B.e2_f[4] * t15_2_P.Constant1_Value;
    t15_2_B.Divide_h[3] = t15_2_B.e2_f[5] * t15_2_P.Constant2_Value;
    t15_2_B.u_i[0] = t15_2_B.Add2_gh;
    t15_2_B.u_i[1] = t15_2_P.Constant4_Value_p;
    t15_2_B.u_i[2] = t15_2_B.Divide_h[0];
    t15_2_B.u_i[3] = t15_2_B.Divide_h[1];
    t15_2_B.u_i[4] = t15_2_B.Divide_h[2];
    t15_2_B.u_i[5] = t15_2_B.Divide_h[3];
    t15_2_B.u_i[6] = t15_2_P.Constant4_Value_p;
    t15_2_B.u_i[7] = t15_2_B.Add1_l;
    t15_2_B.u_i[8] = t15_2_B.Add3_k;
    t15_2_B.u_i[9] = t15_2_B.Add1_g;
    t15_2_B.u_i[10] = t15_2_B.Add2_d;
    t15_2_B.u_i[11] = t15_2_B.Add4_d;
    t15_2_B.u_i[12] = t15_2_B.Add5_j;
    t15_2_B.u_i[13] = t15_2_B.Add6_e;
    t15_2_B.u_i[14] = t15_2_B.Add7;
    t15_2_B.u_i[15] = t15_2_B.Add8;
    t15_2_B.u_i[16] = t15_2_B.Add9;
    t15_2_B.u_i[17] = t15_2_B.Add10;
    t15_2_B.u_i[18] = t15_2_B.Add11;
    t15_2_B.u_i[19] = t15_2_P.Constant4_Value_p;
  }

  /* End of Switch: '<S19>/1' */

  /* UnitDelay: '<S26>/UD' */
  t15_2_B.Uk1 = t15_2_DWork.UD_DSTATE;

  /* Sum: '<S26>/Diff' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_B.Diff = t15_2_U.In1[0] - t15_2_B.Uk1;

  /* UnitDelay: '<S27>/UD' */
  t15_2_B.Uk1_n = t15_2_DWork.UD_DSTATE_c;

  /* Sum: '<S27>/Diff' */
  t15_2_B.Diff_f = t15_2_B.Times - t15_2_B.Uk1_n;

  /* Product: '<S20>/Divide' */
  t15_2_B.Divide = t15_2_B.Diff / t15_2_B.Diff_f;

  /* DataStoreRead: '<S51>/Data Store Read' */
  t15_2_B.DataStoreRead_b = t15_2_DWork.ref_ramp;

  /* DataStoreRead: '<S51>/Data Store Read1' */
  t15_2_B.DataStoreRead1_j = t15_2_DWork.Ip_div;

  /* Memory: '<S51>/Memory3' */
  t15_2_B.Memory3 = t15_2_DWork.Memory3_PreviousInput;

  /* RelationalOperator: '<S51>/Relational Operator1' */
  t15_2_B.RelationalOperator1_k = (t15_2_B.Times > t15_2_B.DataStoreRead1_j);

  /* Switch: '<S51>/switch1 ' */
  if (t15_2_B.RelationalOperator1_k >= t15_2_P.switch1_Threshold_j) {
    t15_2_B.switch1_i = t15_2_B.Memory3;
  } else {
    t15_2_B.switch1_i = t15_2_B.Times;
  }

  /* End of Switch: '<S51>/switch1 ' */

  /* Sum: '<S51>/Subtract2' */
  t15_2_B.Subtract2 = t15_2_B.switch1_i - t15_2_B.Times;

  /* Product: '<S51>/Divide1' */
  t15_2_B.Divide1_mn = 1.0 / t15_2_B.DataStoreRead_b * t15_2_B.Subtract2;

  /* Sum: '<S51>/Subtract1' incorporates:
   *  Constant: '<S51>/1'
   */
  t15_2_B.Subtract1 = t15_2_B.Divide1_mn + t15_2_P._Value_h;

  /* Saturate: '<S51>/Saturation1' */
  tmin = t15_2_B.Subtract1;
  u = t15_2_P.Saturation1_LowerSat_g;
  u_0 = t15_2_P.Saturation1_UpperSat_o;
  if (tmin >= u_0) {
    t15_2_B.Saturation1 = u_0;
  } else if (tmin <= u) {
    t15_2_B.Saturation1 = u;
  } else {
    t15_2_B.Saturation1 = tmin;
  }

  /* End of Saturate: '<S51>/Saturation1' */

  /* DataStoreRead: '<S52>/Data Store Read1' */
  t15_2_B.DataStoreRead1_kn = t15_2_DWork.c_cur_max;

  /* DataStoreRead: '<S65>/Data Store Read' */
  t15_2_B.DataStoreRead_k = t15_2_DWork.RupRd[2];

  /* Abs: '<S65>/Abs' */
  t15_2_B.Abs_l = fabs(t15_2_B.DataStoreRead_k);

  /* RelationalOperator: '<S65>/Relational Operator' */
  t15_2_B.RelationalOperator_o = (t15_2_B.e6 < t15_2_B.Abs_l);

  /* RelationalOperator: '<S82>/Compare' incorporates:
   *  Constant: '<S82>/Constant'
   */
  t15_2_B.Compare_k = (t15_2_B.u_f < t15_2_P.Constant_Value_n);

  /* Logic: '<S65>/Logical Operator2' */
  t15_2_B.LogicalOperator2 = (t15_2_B.RelationalOperator_o && t15_2_B.Compare_k);
  for (i = 0; i < 11; i++) {
    /* Gain: '<S52>/1e3' */
    t15_2_B.e3_g[i] = t15_2_P.e3_Gain_m * t15_2_B.e6_i[i];

    /* Abs: '<S52>/Abs' */
    t15_2_B.Abs[i] = fabs(t15_2_B.e3_g[i]);

    /* DataStoreRead: '<S15>/Data Store Read1' */
    t15_2_B.DataStoreRead1_m[i] = t15_2_DWork.Imax[i];

    /* DataStoreRead: '<S52>/Data Store Read2' */
    t15_2_B.DataStoreRead2_l[i] = t15_2_DWork.ntur[i];

    /* Product: '<S52>/Divide5' */
    t15_2_B.Divide5[i] = t15_2_B.DataStoreRead1_m[i] *
      t15_2_B.DataStoreRead2_l[i];

    /* Sum: '<S52>/Sum2' */
    t15_2_B.Sum2_c[i] = t15_2_B.Divide5[i] - t15_2_B.Abs[i];

    /* Product: '<S52>/Divide3' */
    t15_2_B.Divide3[i] = t15_2_B.Divide5[i] * t15_2_B.DataStoreRead1_kn;

    /* Sum: '<S52>/Sum1' */
    t15_2_B.Sum1[i] = t15_2_B.Divide5[i] - t15_2_B.Divide3[i];

    /* Product: '<S52>/Divide4' */
    t15_2_B.Divide4[i] = t15_2_B.Sum2_c[i] / t15_2_B.Sum1[i];

    /* Product: '<S52>/Divide1' */
    t15_2_B.Divide1_mz[i] = t15_2_B.Divide4[i] * t15_2_B.Divide4[i] *
      t15_2_B.Divide4[i];

    /* Saturate: '<S52>/Saturation' */
    tmin = t15_2_B.Divide1_mz[i];
    u = t15_2_P.Saturation_LowerSat_f;
    u_0 = t15_2_P.Saturation_UpperSat_i;
    if (tmin >= u_0) {
      tmin = u_0;
    } else {
      if (tmin <= u) {
        tmin = u;
      }
    }

    t15_2_B.Saturation[i] = tmin;

    /* End of Saturate: '<S52>/Saturation' */

    /* RelationalOperator: '<S67>/Compare' incorporates:
     *  Constant: '<S67>/Constant'
     */
    t15_2_B.Compare[i] = (uint8_T)(t15_2_B.Saturation[i] <
      t15_2_P.Constant_Value);

    /* Memory: '<S65>/Memory1' */
    t15_2_B.Memory1_ds[i] = t15_2_DWork.Memory1_PreviousInput_c[i];

    /* Memory: '<S57>/Memory' */
    t15_2_B.Memory_l[i] = t15_2_DWork.Memory_PreviousInput_j[i];
  }

  /* DataStoreRead: '<S57>/Data Store Read' */
  t15_2_B.DataStoreRead_d = t15_2_DWork.Ip_rd;

  /* RelationalOperator: '<S57>/Relational Operator1' */
  t15_2_B.RelationalOperator1_m = (t15_2_B.e6 < t15_2_B.DataStoreRead_d);

  /* RelationalOperator: '<S74>/Compare' incorporates:
   *  Constant: '<S74>/Constant'
   */
  t15_2_B.Compare_e = (t15_2_B.u_f < t15_2_P.Constant_Value_n1);

  /* DataStoreRead: '<S57>/Data Store Read1' */
  t15_2_B.DataStoreRead1_i = t15_2_DWork.RupRd[2];

  /* Abs: '<S57>/Abs' */
  t15_2_B.Abs_j = fabs(t15_2_B.DataStoreRead1_i);

  /* RelationalOperator: '<S57>/Relational Operator' */
  t15_2_B.RelationalOperator_k = (t15_2_B.e6 > t15_2_B.Abs_j);

  /* Logic: '<S57>/Logical Operator1' */
  t15_2_B.LogicalOperator1 = (t15_2_B.RelationalOperator1_m && t15_2_B.Compare_e
    && t15_2_B.RelationalOperator_k);

  /* Memory: '<S63>/Memory1' */
  t15_2_B.Memory1_j = t15_2_DWork.Memory1_PreviousInput_i;

  /* Switch: '<S63>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_ah) {
    t15_2_B.c_eob_i = t15_2_B.e6;
  } else {
    t15_2_B.c_eob_i = t15_2_B.Memory1_j;
  }

  /* End of Switch: '<S63>/c_eob' */

  /* Switch: '<S15>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_a1) {
    /* DataStoreRead: '<S15>/Data Store Read2' */
    t15_2_B.DataStoreRead2_i = t15_2_DWork.c_a_tpl2;

    /* Gain: '<S15>/ 1//15 ' */
    t15_2_B.u15_j = t15_2_P.u15_Gain * t15_2_B.DataStoreRead2_i;

    /* Product: '<S15>/Divide9' */
    t15_2_B.Divide9 = t15_2_B.e6 * t15_2_B.u15_j;

    /* Saturate: '<S15>/Saturation' */
    tmin = t15_2_B.Divide9;
    u = t15_2_P.Saturation_LowerSat;
    u_0 = t15_2_P.Saturation_UpperSat;
    if (tmin >= u_0) {
      t15_2_B.Saturation_h = u_0;
    } else if (tmin <= u) {
      t15_2_B.Saturation_h = u;
    } else {
      t15_2_B.Saturation_h = tmin;
    }

    /* End of Saturate: '<S15>/Saturation' */
    t15_2_B.c_eob_ku = t15_2_B.Saturation_h;
  } else {
    /* DataStoreRead: '<S63>/Data Store Read2' */
    t15_2_B.DataStoreRead2_j = t15_2_DWork.y0;

    /* Sum: '<S63>/Sum3' incorporates:
     *  Constant: '<S63>/2'
     */
    t15_2_B.Sum3_p = t15_2_P._Value - t15_2_B.DataStoreRead2_j;

    /* DataStoreRead: '<S63>/Data Store Read4' */
    t15_2_B.DataStoreRead4_h = t15_2_DWork.c2_y0;

    /* DataStoreRead: '<S63>/Data Store Read3' */
    t15_2_B.DataStoreRead3_k = t15_2_DWork.c1_y0;

    /* Sum: '<S63>/Sum2' */
    t15_2_B.Sum2_g = t15_2_B.DataStoreRead4_h - t15_2_B.DataStoreRead3_k;

    /* Product: '<S63>/Divide1' */
    t15_2_B.Divide1_j = 1.0 / t15_2_B.Sum2_g * t15_2_B.Sum3_p;

    /* Product: '<S63>/Divide6' */
    t15_2_B.Divide6_f = t15_2_B.c_eob_i * t15_2_B.u_f;

    /* Sum: '<S63>/Sum' */
    t15_2_B.Sum = t15_2_B.Divide6_f - t15_2_B.DataStoreRead3_k;

    /* Product: '<S63>/Divide2' */
    t15_2_B.Divide2_h = t15_2_B.Sum * t15_2_B.Divide1_j;

    /* Sum: '<S63>/Sum1' */
    t15_2_B.Sum1_n = t15_2_B.Divide2_h + t15_2_B.DataStoreRead2_j;

    /* RelationalOperator: '<S81>/LowerRelop1' incorporates:
     *  Constant: '<S63>/1'
     */
    t15_2_B.LowerRelop1_ah = (t15_2_B.Sum1_n > t15_2_P._Value_e);

    /* Switch: '<S81>/Switch2' incorporates:
     *  Constant: '<S63>/1'
     */
    if (t15_2_B.LowerRelop1_ah) {
      t15_2_B.Switch2_h = t15_2_P._Value_e;
    } else {
      /* RelationalOperator: '<S81>/UpperRelop' */
      t15_2_B.UpperRelop_a = (t15_2_B.Sum1_n < t15_2_B.DataStoreRead2_j);

      /* Switch: '<S81>/Switch' */
      if (t15_2_B.UpperRelop_a) {
        t15_2_B.Switch_d = t15_2_B.DataStoreRead2_j;
      } else {
        t15_2_B.Switch_d = t15_2_B.Sum1_n;
      }

      /* End of Switch: '<S81>/Switch' */
      t15_2_B.Switch2_h = t15_2_B.Switch_d;
    }

    /* End of Switch: '<S81>/Switch2' */
    t15_2_B.c_eob_ku = t15_2_B.Switch2_h;
  }

  /* End of Switch: '<S15>/c_eob' */

  /* Product: '<S15>/Divide2' */
  for (i = 0; i < 20; i++) {
    t15_2_B.Divide2[i] = t15_2_B.RelationalOperator1_k * t15_2_B.u_i[i];
  }

  /* End of Product: '<S15>/Divide2' */

  /* DiscreteStateSpace: '<S15>/Div. contr.' */
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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

    t15_2_B.Divcontr[4] += (t15_2_P.Divcontr_D[68])*t15_2_B.Divide2[12];

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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
      real_T *y10 = &t15_2_B.Divcontr[10];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y10 += (*pD154++) * u[*pDidx++];
      }
    }
  }

  /* Switch: '<S57>/1' */
  if (t15_2_B.LogicalOperator1 >= t15_2_P._Threshold_c) {
    memcpy(&t15_2_B.u_p[0], &t15_2_B.Memory_l[0], 11U * sizeof(real_T));
  } else {
    /* Sum: '<S51>/Subtract3' incorporates:
     *  Constant: '<S51>/1'
     */
    t15_2_B.Subtract3_i = t15_2_P._Value_h - t15_2_B.Saturation1;

    /* Product: '<S15>/Divide' */
    for (i = 0; i < 11; i++) {
      t15_2_B.Divide_j[i] = t15_2_B.c_eob_ku * t15_2_B.Divcontr[i] *
        t15_2_B.Subtract3_i;
      t15_2_B.u_p[i] = t15_2_B.Divide_j[i];
    }

    /* End of Product: '<S15>/Divide' */
  }

  /* End of Switch: '<S57>/1' */

  /* Memory: '<S61>/Memory1' */
  t15_2_B.Memory1_fj = t15_2_DWork.Memory1_PreviousInput_ic;

  /* DataStoreRead: '<S61>/Data Store Read' */
  t15_2_B.DataStoreRead_i = t15_2_DWork.Ip_rd;

  /* RelationalOperator: '<S61>/Relational Operator1' */
  t15_2_B.RelationalOperator1_hw = (t15_2_B.e6 < t15_2_B.DataStoreRead_i);

  /* RelationalOperator: '<S78>/Compare' incorporates:
   *  Constant: '<S78>/Constant'
   */
  t15_2_B.Compare_m = (t15_2_B.u_f < t15_2_P.Constant_Value_h);

  /* Logic: '<S61>/Logical Operator1' */
  t15_2_B.LogicalOperator1_f = (t15_2_B.RelationalOperator1_hw &&
    t15_2_B.Compare_m);

  /* Switch: '<S61>/switch1' */
  if (t15_2_B.LogicalOperator1_f >= t15_2_P.switch1_Threshold_g) {
    t15_2_B.switch1_g = t15_2_B.Memory1_fj;
  } else {
    t15_2_B.switch1_g = t15_2_B.Times;
  }

  /* End of Switch: '<S61>/switch1' */

  /* Product: '<S15>/Divide13' */
  for (i = 0; i < 20; i++) {
    t15_2_B.Divide13[i] = t15_2_B.Divide2[i] * t15_2_B.LogicalOperator1_f;
  }

  /* End of Product: '<S15>/Divide13' */

  /* DiscreteStateSpace: '<S15>/Div_rd contr' */
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

  /* Switch: '<S65>/1' */
  if (t15_2_B.LogicalOperator2 >= t15_2_P._Threshold_n) {
    memcpy(&t15_2_B.u_fs[0], &t15_2_B.Memory1_ds[0], 11U * sizeof(real_T));
  } else {
    /* Sum: '<S61>/Subtract2' */
    t15_2_B.Subtract2_c = t15_2_B.switch1_g - t15_2_B.Times;

    /* DataStoreRead: '<S61>/Data Store Read1' */
    t15_2_B.DataStoreRead1_a = t15_2_DWork.ref_ramp;

    /* Product: '<S61>/Divide4' */
    t15_2_B.Divide4_lu = 1.0 / t15_2_B.DataStoreRead1_a * t15_2_B.Subtract2_c;

    /* Sum: '<S61>/Subtract3' incorporates:
     *  Constant: '<S61>/1'
     */
    t15_2_B.Subtract3_b = t15_2_B.Divide4_lu + t15_2_P._Value_i;

    /* Saturate: '<S61>/Saturation' */
    tmin = t15_2_B.Subtract3_b;
    u = t15_2_P.Saturation_LowerSat_k;
    u_0 = t15_2_P.Saturation_UpperSat_b;
    if (tmin >= u_0) {
      t15_2_B.Saturation_p = u_0;
    } else if (tmin <= u) {
      t15_2_B.Saturation_p = u;
    } else {
      t15_2_B.Saturation_p = tmin;
    }

    /* End of Saturate: '<S61>/Saturation' */

    /* Sum: '<S61>/Subtract1' incorporates:
     *  Constant: '<S61>/1'
     */
    t15_2_B.Subtract1_j = t15_2_P._Value_i - t15_2_B.Saturation_p;
    for (i = 0; i < 11; i++) {
      /* Product: '<S15>/Divide3' */
      t15_2_B.Divide3_n[i] = t15_2_B.Div_rdcontr[i] * t15_2_B.c_eob_ku *
        t15_2_B.Subtract1_j;

      /* Product: '<S15>/Divide1' */
      t15_2_B.Divide1_h[i] = t15_2_B.u_p[i] * t15_2_B.Saturation_p;

      /* Sum: '<S15>/Sum2' */
      t15_2_B.Sum2_l[i] = t15_2_B.Divide1_h[i] + t15_2_B.Divide3_n[i];
      t15_2_B.u_fs[i] = t15_2_B.Sum2_l[i];
    }
  }

  /* End of Switch: '<S65>/1' */

  /* DataStoreRead: '<S53>/Data Store Read' */
  t15_2_B.DataStoreRead_iz = t15_2_DWork.ref_ramp;

  /* Memory: '<S53>/Memory1' */
  t15_2_B.Memory1_n = t15_2_DWork.Memory1_PreviousInput_gz;

  /* DataStoreRead: '<S70>/Data Store Read' */
  t15_2_B.DataStoreRead_f = t15_2_DWork.RupRd[2];

  /* Abs: '<S70>/Abs' */
  t15_2_B.Abs_k = fabs(t15_2_B.DataStoreRead_f);

  /* RelationalOperator: '<S70>/Relational Operator' */
  t15_2_B.RelationalOperator_b = (t15_2_B.e6 < t15_2_B.Abs_k);

  /* RelationalOperator: '<S69>/Compare' incorporates:
   *  Constant: '<S69>/Constant'
   */
  t15_2_B.Compare_et = (t15_2_B.u_f < t15_2_P.Constant_Value_k);

  /* Logic: '<S53>/Logical Operator2' */
  t15_2_B.LogicalOperator2_i = (t15_2_B.RelationalOperator_b &&
    t15_2_B.Compare_et);

  /* Switch: '<S53>/1 ' */
  if (t15_2_B.LogicalOperator2_i >= t15_2_P._Threshold_co) {
    t15_2_B.u_j = t15_2_B.Memory1_n;
  } else {
    t15_2_B.u_j = t15_2_B.Times;
  }

  /* End of Switch: '<S53>/1 ' */

  /* Sum: '<S53>/Subtract2' */
  t15_2_B.Subtract2_k = t15_2_B.u_j - t15_2_B.Times;

  /* Product: '<S53>/Divide4' */
  t15_2_B.Divide4_d = 1.0 / t15_2_B.DataStoreRead_iz * t15_2_B.Subtract2_k;

  /* Sum: '<S53>/Subtract3' incorporates:
   *  Constant: '<S53>/1'
   */
  t15_2_B.Subtract3 = t15_2_B.Divide4_d + t15_2_P._Value_lw;

  /* Saturate: '<S53>/Saturation' */
  tmin = t15_2_B.Subtract3;
  u = t15_2_P.Saturation_LowerSat_e;
  u_0 = t15_2_P.Saturation_UpperSat_d;
  if (tmin >= u_0) {
    t15_2_B.Saturation_f = u_0;
  } else if (tmin <= u) {
    t15_2_B.Saturation_f = u;
  } else {
    t15_2_B.Saturation_f = tmin;
  }

  /* End of Saturate: '<S53>/Saturation' */

  /* DiscreteStateSpace: '<S15>/Curr. term. contr' */
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

  /* Sum: '<S53>/Subtract1' incorporates:
   *  Constant: '<S53>/1'
   */
  t15_2_B.Subtract1_b = t15_2_P._Value_lw - t15_2_B.Saturation_f;
  for (i = 0; i < 11; i++) {
    /* Product: '<S15>/Divide4' */
    t15_2_B.Divide4_da[i] = t15_2_B.u_fs[i] * t15_2_B.Saturation_f;

    /* Product: '<S15>/Divide5' */
    t15_2_B.Divide5_n[i] = t15_2_B.Currtermcontr[i] * t15_2_B.Subtract1_b;

    /* Memory: '<S73>/Memory2' */
    t15_2_B.Memory2_d[i] = t15_2_DWork.Memory2_PreviousInput_cm[i];
  }

  /* DataStoreRead: '<S73>/Data Store Read1' */
  t15_2_B.DataStoreRead1_h = t15_2_DWork.Ip_div;

  /* RelationalOperator: '<S73>/Relational Operator1' */
  t15_2_B.RelationalOperator1_d = (t15_2_B.Times > t15_2_B.DataStoreRead1_h);

  /* DataStoreRead: '<S72>/Data Store Read' */
  t15_2_B.DataStoreRead_j = t15_2_DWork.tcont2;

  /* RelationalOperator: '<S72>/Relational Operator' */
  t15_2_B.RelationalOperator_p = (t15_2_B.Times > t15_2_B.DataStoreRead_j);

  /* Product: '<S72>/Divide12' */
  for (i = 0; i < 20; i++) {
    t15_2_B.Divide12_l[i] = t15_2_B.u_i[i] * t15_2_B.RelationalOperator_p;
  }

  /* End of Product: '<S72>/Divide12' */

  /* DiscreteStateSpace: '<S54>/Lim. contr.' */
  {
    {
      static const int_T colCidxRow0[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = t15_2_P.Limcontr_C;
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y0 = &t15_2_B.Limcontr[0];
      int_T numNonZero = 45;
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
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *y0 = &t15_2_B.Limcontr[0];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y0 += (*pD0++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow1[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC46 = &t15_2_P.Limcontr_C[46];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y1 = &t15_2_B.Limcontr[1];
      int_T numNonZero = 45;
      *y1 = (*pC46++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC46++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colDidxRow1[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow1[0];
      const real_T *pD17 = &t15_2_P.Limcontr_D[17];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *y1 = &t15_2_B.Limcontr[1];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y1 += (*pD17++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow2[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pCidx = &colCidxRow2[0];
      const real_T *pC92 = &t15_2_P.Limcontr_C[92];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y2 = &t15_2_B.Limcontr[2];
      int_T numNonZero = 45;
      *y2 = (*pC92++) * xd[*pCidx++];
      while (numNonZero--) {
        *y2 += (*pC92++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colDidxRow2[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow2[0];
      const real_T *pD34 = &t15_2_P.Limcontr_D[34];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *y2 = &t15_2_B.Limcontr[2];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y2 += (*pD34++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow3[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pCidx = &colCidxRow3[0];
      const real_T *pC138 = &t15_2_P.Limcontr_C[138];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y3 = &t15_2_B.Limcontr[3];
      int_T numNonZero = 45;
      *y3 = (*pC138++) * xd[*pCidx++];
      while (numNonZero--) {
        *y3 += (*pC138++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colDidxRow3[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow3[0];
      const real_T *pD51 = &t15_2_P.Limcontr_D[51];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *y3 = &t15_2_B.Limcontr[3];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y3 += (*pD51++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow4[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pCidx = &colCidxRow4[0];
      const real_T *pC184 = &t15_2_P.Limcontr_C[184];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y4 = &t15_2_B.Limcontr[4];
      int_T numNonZero = 45;
      *y4 = (*pC184++) * xd[*pCidx++];
      while (numNonZero--) {
        *y4 += (*pC184++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colDidxRow4[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow4[0];
      const real_T *pD68 = &t15_2_P.Limcontr_D[68];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *y4 = &t15_2_B.Limcontr[4];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y4 += (*pD68++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow5[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pCidx = &colCidxRow5[0];
      const real_T *pC230 = &t15_2_P.Limcontr_C[230];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y5 = &t15_2_B.Limcontr[5];
      int_T numNonZero = 45;
      *y5 = (*pC230++) * xd[*pCidx++];
      while (numNonZero--) {
        *y5 += (*pC230++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colDidxRow5[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow5[0];
      const real_T *pD85 = &t15_2_P.Limcontr_D[85];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *y5 = &t15_2_B.Limcontr[5];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y5 += (*pD85++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow6[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pCidx = &colCidxRow6[0];
      const real_T *pC276 = &t15_2_P.Limcontr_C[276];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y6 = &t15_2_B.Limcontr[6];
      int_T numNonZero = 45;
      *y6 = (*pC276++) * xd[*pCidx++];
      while (numNonZero--) {
        *y6 += (*pC276++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colDidxRow6[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow6[0];
      const real_T *pD102 = &t15_2_P.Limcontr_D[102];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *y6 = &t15_2_B.Limcontr[6];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y6 += (*pD102++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow7[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pCidx = &colCidxRow7[0];
      const real_T *pC322 = &t15_2_P.Limcontr_C[322];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y7 = &t15_2_B.Limcontr[7];
      int_T numNonZero = 45;
      *y7 = (*pC322++) * xd[*pCidx++];
      while (numNonZero--) {
        *y7 += (*pC322++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colDidxRow7[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow7[0];
      const real_T *pD119 = &t15_2_P.Limcontr_D[119];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *y7 = &t15_2_B.Limcontr[7];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y7 += (*pD119++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow8[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pCidx = &colCidxRow8[0];
      const real_T *pC368 = &t15_2_P.Limcontr_C[368];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y8 = &t15_2_B.Limcontr[8];
      int_T numNonZero = 45;
      *y8 = (*pC368++) * xd[*pCidx++];
      while (numNonZero--) {
        *y8 += (*pC368++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colDidxRow8[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow8[0];
      const real_T *pD136 = &t15_2_P.Limcontr_D[136];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *y8 = &t15_2_B.Limcontr[8];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y8 += (*pD136++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow9[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pCidx = &colCidxRow9[0];
      const real_T *pC414 = &t15_2_P.Limcontr_C[414];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y9 = &t15_2_B.Limcontr[9];
      int_T numNonZero = 45;
      *y9 = (*pC414++) * xd[*pCidx++];
      while (numNonZero--) {
        *y9 += (*pC414++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colDidxRow9[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow9[0];
      const real_T *pD153 = &t15_2_P.Limcontr_D[153];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *y9 = &t15_2_B.Limcontr[9];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y9 += (*pD153++) * u[*pDidx++];
      }
    }

    {
      static const int_T colCidxRow10[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pCidx = &colCidxRow10[0];
      const real_T *pC460 = &t15_2_P.Limcontr_C[460];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *y10 = &t15_2_B.Limcontr[10];
      int_T numNonZero = 45;
      *y10 = (*pC460++) * xd[*pCidx++];
      while (numNonZero--) {
        *y10 += (*pC460++) * xd[*pCidx++];
      }
    }

    {
      static const int_T colDidxRow10[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pDidx = &colDidxRow10[0];
      const real_T *pD170 = &t15_2_P.Limcontr_D[170];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *y10 = &t15_2_B.Limcontr[10];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y10 += (*pD170++) * u[*pDidx++];
      }
    }
  }

  /* DiscreteStateSpace: '<S54>/Curr. contr.' */
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

  /* DataStoreRead: '<S54>/Data Store Read2' */
  memcpy(&t15_2_B.DataStoreRead2_a[0], &t15_2_DWork.ntur[0], 11U * sizeof(real_T));

  /* Switch: '<S73>/ 1 ' */
  if (t15_2_B.RelationalOperator1_d >= t15_2_P.u_Threshold) {
    memcpy(&t15_2_B.u_g[0], &t15_2_B.Memory2_d[0], 11U * sizeof(real_T));
  } else {
    /* DataStoreRead: '<S73>/Data Store Read' */
    t15_2_B.DataStoreRead_p = t15_2_DWork.tcont2;

    /* RelationalOperator: '<S73>/Relational Operator' */
    t15_2_B.RelationalOperator_i = (t15_2_B.Times > t15_2_B.DataStoreRead_p);

    /* Switch: '<S73>/1' */
    if (t15_2_B.RelationalOperator_i >= t15_2_P._Threshold) {
      /* DataStoreRead: '<S71>/Data Store Read1' */
      t15_2_B.DataStoreRead1_ko = t15_2_DWork.dtcont2;

      /* DataStoreRead: '<S71>/Data Store Read' */
      t15_2_B.DataStoreRead_md = t15_2_DWork.tcont2;

      /* Sum: '<S71>/Subtract3' */
      t15_2_B.Subtract3_e = t15_2_B.Times - t15_2_B.DataStoreRead_md;

      /* Product: '<S71>/Divide2' */
      t15_2_B.Divide2_o = t15_2_B.Subtract3_e / t15_2_B.DataStoreRead1_ko;

      /* Saturate: '<S71>/Saturation1' */
      tmin = t15_2_B.Divide2_o;
      u = t15_2_P.Saturation1_LowerSat;
      u_0 = t15_2_P.Saturation1_UpperSat;
      if (tmin >= u_0) {
        t15_2_B.Saturation1_c = u_0;
      } else if (tmin <= u) {
        t15_2_B.Saturation1_c = u;
      } else {
        t15_2_B.Saturation1_c = tmin;
      }

      /* End of Saturate: '<S71>/Saturation1' */

      /* Product: '<S54>/Divide ' */
      for (i = 0; i < 11; i++) {
        t15_2_B.Divide_m[i] = t15_2_B.Limcontr[i] * t15_2_B.Saturation1_c;
        t15_2_B.u_l[i] = t15_2_B.Divide_m[i];
      }

      /* End of Product: '<S54>/Divide ' */
    } else {
      /* Product: '<S54>/Divide2' */
      for (i = 0; i < 11; i++) {
        t15_2_B.Divide2_a[i] = t15_2_B.Currcontr[i] / t15_2_B.DataStoreRead2_a[i];
        t15_2_B.u_l[i] = t15_2_B.Divide2_a[i];
      }

      /* End of Product: '<S54>/Divide2' */
    }

    /* End of Switch: '<S73>/1' */
    memcpy(&t15_2_B.u_g[0], &t15_2_B.u_l[0], 11U * sizeof(real_T));
  }

  /* End of Switch: '<S73>/ 1 ' */

  /* Product: '<S15>/Divide14' */
  for (i = 0; i < 11; i++) {
    t15_2_B.Divide14[i] = t15_2_B.Saturation1 * t15_2_B.u_g[i];
  }

  for (i = 0; i < 500; i++) {
    /* DataStoreRead: '<S83>/Data Store Read' */
    t15_2_B.DataStoreRead_hz[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S83>/0.001' */
    t15_2_B.u01[i] = t15_2_P.u01_Gain * t15_2_B.DataStoreRead_hz[i];

    /* DataStoreRead: '<S83>/Data Store Read1' */
    t15_2_B.DataStoreRead1_p[i] = t15_2_DWork.volt[20 * i + 1];

    /* DataStoreRead: '<S86>/Data Store Read' */
    t15_2_B.DataStoreRead_g[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S86>/0.001' */
    t15_2_B.u01_e[i] = t15_2_P.u01_Gain_d * t15_2_B.DataStoreRead_g[i];

    /* DataStoreRead: '<S86>/Data Store Read1' */
    t15_2_B.DataStoreRead1_hx[i] = t15_2_DWork.volt[20 * i + 2];

    /* DataStoreRead: '<S87>/Data Store Read' */
    t15_2_B.DataStoreRead_e[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S87>/0.001' */
    t15_2_B.u01_g[i] = t15_2_P.u01_Gain_a * t15_2_B.DataStoreRead_e[i];

    /* DataStoreRead: '<S87>/Data Store Read1' */
    t15_2_B.DataStoreRead1_g[i] = t15_2_DWork.volt[20 * i + 3];

    /* DataStoreRead: '<S88>/Data Store Read' */
    t15_2_B.DataStoreRead_i2[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S88>/0.001' */
    t15_2_B.u01_d[i] = t15_2_P.u01_Gain_i * t15_2_B.DataStoreRead_i2[i];

    /* DataStoreRead: '<S88>/Data Store Read1' */
    t15_2_B.DataStoreRead1_e[i] = t15_2_DWork.volt[20 * i + 4];

    /* DataStoreRead: '<S89>/Data Store Read' */
    t15_2_B.DataStoreRead_c[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S89>/0.001' */
    t15_2_B.u01_b[i] = t15_2_P.u01_Gain_f * t15_2_B.DataStoreRead_c[i];

    /* DataStoreRead: '<S89>/Data Store Read1' */
    t15_2_B.DataStoreRead1_o[i] = t15_2_DWork.volt[20 * i + 5];

    /* DataStoreRead: '<S90>/Data Store Read' */
    t15_2_B.DataStoreRead_ea[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S90>/0.001' */
    t15_2_B.u01_p[i] = t15_2_P.u01_Gain_dl * t15_2_B.DataStoreRead_ea[i];

    /* DataStoreRead: '<S90>/Data Store Read1' */
    t15_2_B.DataStoreRead1_pg[i] = t15_2_DWork.volt[20 * i + 6];

    /* DataStoreRead: '<S91>/Data Store Read' */
    t15_2_B.DataStoreRead_jf[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S91>/0.001' */
    t15_2_B.u01_n[i] = t15_2_P.u01_Gain_j * t15_2_B.DataStoreRead_jf[i];

    /* DataStoreRead: '<S91>/Data Store Read1' */
    t15_2_B.DataStoreRead1_gg[i] = t15_2_DWork.volt[20 * i + 7];

    /* DataStoreRead: '<S92>/Data Store Read' */
    t15_2_B.DataStoreRead_f3[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S92>/0.001' */
    t15_2_B.u01_h[i] = t15_2_P.u01_Gain_b * t15_2_B.DataStoreRead_f3[i];

    /* DataStoreRead: '<S92>/Data Store Read1' */
    t15_2_B.DataStoreRead1_l[i] = t15_2_DWork.volt[20 * i + 8];

    /* DataStoreRead: '<S93>/Data Store Read' */
    t15_2_B.DataStoreRead_dy[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S93>/0.001' */
    t15_2_B.u01_f[i] = t15_2_P.u01_Gain_h * t15_2_B.DataStoreRead_dy[i];

    /* DataStoreRead: '<S93>/Data Store Read1' */
    t15_2_B.DataStoreRead1_d[i] = t15_2_DWork.volt[20 * i + 9];

    /* DataStoreRead: '<S84>/Data Store Read' */
    t15_2_B.DataStoreRead_m[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S84>/0.001' */
    t15_2_B.u01_c[i] = t15_2_P.u01_Gain_p * t15_2_B.DataStoreRead_m[i];

    /* DataStoreRead: '<S84>/Data Store Read1' */
    t15_2_B.DataStoreRead1_b[i] = t15_2_DWork.volt[20 * i + 10];

    /* DataStoreRead: '<S85>/Data Store Read' */
    t15_2_B.DataStoreRead_dl[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S85>/0.001' */
    t15_2_B.u01_m[i] = t15_2_P.u01_Gain_n * t15_2_B.DataStoreRead_dl[i];

    /* DataStoreRead: '<S85>/Data Store Read1' */
    t15_2_B.DataStoreRead1_b3[i] = t15_2_DWork.volt[20 * i + 11];
  }

  /* End of Product: '<S15>/Divide14' */
  /* Dynamic Look-Up Table Block: '<S83>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1), &t15_2_B.DataStoreRead1_p[0],
                       t15_2_B.Times, &t15_2_B.u01[0], 499U);

  /* Dynamic Look-Up Table Block: '<S86>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_h), &t15_2_B.DataStoreRead1_hx[0],
                       t15_2_B.Times, &t15_2_B.u01_e[0], 499U);

  /* Dynamic Look-Up Table Block: '<S87>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_g), &t15_2_B.DataStoreRead1_g[0],
                       t15_2_B.Times, &t15_2_B.u01_g[0], 499U);

  /* Dynamic Look-Up Table Block: '<S88>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_hk), &t15_2_B.DataStoreRead1_e[0],
                       t15_2_B.Times, &t15_2_B.u01_d[0], 499U);

  /* Dynamic Look-Up Table Block: '<S89>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_l), &t15_2_B.DataStoreRead1_o[0],
                       t15_2_B.Times, &t15_2_B.u01_b[0], 499U);

  /* Dynamic Look-Up Table Block: '<S90>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_i), &t15_2_B.DataStoreRead1_pg[0],
                       t15_2_B.Times, &t15_2_B.u01_p[0], 499U);

  /* Dynamic Look-Up Table Block: '<S91>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_n), &t15_2_B.DataStoreRead1_gg[0],
                       t15_2_B.Times, &t15_2_B.u01_n[0], 499U);

  /* Dynamic Look-Up Table Block: '<S92>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_p), &t15_2_B.DataStoreRead1_l[0],
                       t15_2_B.Times, &t15_2_B.u01_h[0], 499U);

  /* Dynamic Look-Up Table Block: '<S93>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_f), &t15_2_B.DataStoreRead1_d[0],
                       t15_2_B.Times, &t15_2_B.u01_f[0], 499U);

  /* Dynamic Look-Up Table Block: '<S84>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_c), &t15_2_B.DataStoreRead1_b[0],
                       t15_2_B.Times, &t15_2_B.u01_c[0], 499U);

  /* Dynamic Look-Up Table Block: '<S85>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_i1), &t15_2_B.DataStoreRead1_b3[0],
                       t15_2_B.Times, &t15_2_B.u01_m[0], 499U);

  /* Sum: '<S53>/Subtract4' incorporates:
   *  Constant: '<S53>/1'
   */
  t15_2_B.Subtract4 = t15_2_P._Value_lw - t15_2_B.LogicalOperator2_i;

  /* Product: '<S15>/Divide7' */
  t15_2_B.Divide7[0] = t15_2_B.volt1 * t15_2_B.Subtract4;
  t15_2_B.Divide7[1] = t15_2_B.volt1_h * t15_2_B.Subtract4;
  t15_2_B.Divide7[2] = t15_2_B.volt1_g * t15_2_B.Subtract4;
  t15_2_B.Divide7[3] = t15_2_B.volt1_hk * t15_2_B.Subtract4;
  t15_2_B.Divide7[4] = t15_2_B.volt1_l * t15_2_B.Subtract4;
  t15_2_B.Divide7[5] = t15_2_B.volt1_i * t15_2_B.Subtract4;
  t15_2_B.Divide7[6] = t15_2_B.volt1_n * t15_2_B.Subtract4;
  t15_2_B.Divide7[7] = t15_2_B.volt1_p * t15_2_B.Subtract4;
  t15_2_B.Divide7[8] = t15_2_B.volt1_f * t15_2_B.Subtract4;
  t15_2_B.Divide7[9] = t15_2_B.volt1_c * t15_2_B.Subtract4;
  t15_2_B.Divide7[10] = t15_2_B.volt1_i1 * t15_2_B.Subtract4;
  for (i = 0; i < 11; i++) {
    /* Sum: '<S15>/Sum3' */
    t15_2_B.Sum3[i] = ((t15_2_B.Divide4_da[i] + t15_2_B.Divide5_n[i]) +
                       t15_2_B.Divide14[i]) + t15_2_B.Divide7[i];

    /* Product: '<S52>/Divide2' */
    t15_2_B.Divide2_i[i] = t15_2_B.e6_i[i] * t15_2_B.Sum3[i];

    /* RelationalOperator: '<S68>/Compare' incorporates:
     *  Constant: '<S68>/Constant'
     */
    t15_2_B.Compare_o[i] = (uint8_T)(t15_2_B.Divide2_i[i] <
      t15_2_P.Constant_Value_d);

    /* Logic: '<S52>/Logical Operator' */
    t15_2_B.LogicalOperator_d[i] = ((t15_2_B.Compare[i] != 0) &&
      (t15_2_B.Compare_o[i] != 0));

    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S52>/1'
     */
    if (t15_2_B.LogicalOperator_d[i] >= t15_2_P.Switch_Threshold) {
      t15_2_B.Switch[i] = t15_2_P._Value_p;
    } else {
      t15_2_B.Switch[i] = t15_2_B.Saturation[i];
    }

    /* End of Switch: '<S52>/Switch' */

    /* Product: '<S52>/Divide6' */
    t15_2_B.Divide6_j[i] = t15_2_B.Sum3[i] * t15_2_B.Switch[i];
  }

  /* UniformRandomNumber: '<S62>/Uniform Random Number' */
  t15_2_B.UniformRandomNumber = t15_2_DWork.UniformRandomNumber_NextOutput;

  /* DataStoreRead: '<S79>/Data Store Read' */
  t15_2_B.DataStoreRead_ga = t15_2_DWork.RupRd[5];

  /* Gain: '<S79>/1.75' */
  t15_2_B.u5 = t15_2_P.u5_Gain_d * t15_2_B.DataStoreRead_ga;

  /* Product: '<S79>/Divide11' */
  t15_2_B.Divide11 = t15_2_B.UniformRandomNumber * t15_2_B.u5;

  /* UnitDelay: '<S80>/UD' */
  t15_2_B.Uk1_o = t15_2_DWork.UD_DSTATE_o;

  /* Sum: '<S80>/Diff' */
  t15_2_B.Diff_b = t15_2_B.Times - t15_2_B.Uk1_o;

  /* Gain: '<S79>/2e3' */
  t15_2_B.e3_j = t15_2_P.e3_Gain_i * t15_2_B.Diff_b;

  /* Sqrt: '<S79>/Sqrt' */
  t15_2_B.Sqrt = sqrt(t15_2_B.e3_j);

  /* Product: '<S79>/Divide1' */
  t15_2_B.Divide1_bm = t15_2_B.Divide11 / t15_2_B.Sqrt;

  /* Sum: '<S62>/Sum2' */
  t15_2_B.Sum2_cw = t15_2_B.Divide1_bm + t15_2_B.Divide;

  /* DataStoreRead: '<S64>/Data Store Read' */
  t15_2_B.DataStoreRead_kg = t15_2_DWork.t_tran2D;

  /* RelationalOperator: '<S64>/Relational Operator1' */
  t15_2_B.RelationalOperator1_i = (t15_2_B.Times > t15_2_B.DataStoreRead_kg);

  /* Product: '<S64>/Divide12' */
  t15_2_B.Divide12_m[0] = t15_2_B.Sum2_cw * t15_2_B.RelationalOperator1_i;
  t15_2_B.Divide12_m[1] = t15_2_B.e6_i[11] * t15_2_B.RelationalOperator1_i;

  /* DiscreteStateSpace: '<S59>/VS. contr' */
  {
    {
      static const int_T colCidxRow0[5] = { 3, 4, 5, 6, 7 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = t15_2_P.VScontr_C;
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *y0 = &t15_2_B.VScontr[0];
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    t15_2_B.VScontr[0] += (t15_2_P.VScontr_D[0])*t15_2_B.Divide12_m[0] +
      (t15_2_P.VScontr_D[1])*t15_2_B.Divide12_m[1];

    {
      static const int_T colCidxRow1[5] = { 0, 1, 2, 7, 8 };

      const int_T *pCidx = &colCidxRow1[0];
      const real_T *pC5 = &t15_2_P.VScontr_C[5];
      const real_T *xd = &t15_2_DWork.VScontr_DSTATE[0];
      real_T *y1 = &t15_2_B.VScontr[1];
      int_T numNonZero = 4;
      *y1 = (*pC5++) * xd[*pCidx++];
      while (numNonZero--) {
        *y1 += (*pC5++) * xd[*pCidx++];
      }
    }

    t15_2_B.VScontr[1] += (t15_2_P.VScontr_D[2])*t15_2_B.Divide12_m[0] +
      (t15_2_P.VScontr_D[3])*t15_2_B.Divide12_m[1];
  }

  /* RelationalOperator: '<S76>/Compare' incorporates:
   *  Constant: '<S76>/Constant'
   */
  t15_2_B.Compare_a = (t15_2_B.u_f < t15_2_P.Constant_Value_i);

  /* Product: '<S59>/Divide4' */
  t15_2_B.Divide4_c[0] = (real_T)t15_2_B.Compare_a * t15_2_B.Divide12_m[0];
  t15_2_B.Divide4_c[1] = (real_T)t15_2_B.Compare_a * t15_2_B.Divide12_m[1];

  /* DiscreteStateSpace: '<S59>/VS. contr hl' */
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

    t15_2_B.VScontrhl[0] += (t15_2_P.VScontrhl_D[0])*t15_2_B.Divide4_c[0] +
      (t15_2_P.VScontrhl_D[1])*t15_2_B.Divide4_c[1];
    t15_2_B.VScontrhl[1] = (t15_2_P.VScontrhl_C[5])*
      t15_2_DWork.VScontrhl_DSTATE[0] + (t15_2_P.VScontrhl_C[6])*
      t15_2_DWork.VScontrhl_DSTATE[1]
      + (t15_2_P.VScontrhl_C[7])*t15_2_DWork.VScontrhl_DSTATE[2]
      + (t15_2_P.VScontrhl_C[8])*t15_2_DWork.VScontrhl_DSTATE[7];
    t15_2_B.VScontrhl[1] += (t15_2_P.VScontrhl_D[2])*t15_2_B.Divide4_c[0] +
      (t15_2_P.VScontrhl_D[3])*t15_2_B.Divide4_c[1];
  }

  /* Switch: '<S59>/c_eob' */
  if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold_o5) {
    t15_2_B.c_eob_gx[0] = t15_2_B.VScontr[0];
    t15_2_B.c_eob_gx[1] = t15_2_B.VScontr[1];
  } else {
    t15_2_B.c_eob_gx[0] = t15_2_B.VScontrhl[0];
    t15_2_B.c_eob_gx[1] = t15_2_B.VScontrhl[1];
  }

  /* End of Switch: '<S59>/c_eob' */

  /* DataStoreRead: '<S58>/Data Store Read1' */
  t15_2_B.DataStoreRead1_n = t15_2_DWork.Ip_rd;

  /* RelationalOperator: '<S58>/Relational Operator2' */
  t15_2_B.RelationalOperator2 = (t15_2_B.e6 < t15_2_B.DataStoreRead1_n);

  /* DataStoreRead: '<S58>/Data Store Read' */
  t15_2_B.DataStoreRead_ml = t15_2_DWork.RupRd[2];

  /* Abs: '<S58>/Abs' */
  t15_2_B.Abs_c = fabs(t15_2_B.DataStoreRead_ml);

  /* RelationalOperator: '<S58>/Relational Operator1' */
  t15_2_B.RelationalOperator1_o = (t15_2_B.e6 > t15_2_B.Abs_c);

  /* RelationalOperator: '<S75>/Compare' incorporates:
   *  Constant: '<S75>/Constant'
   */
  t15_2_B.Compare_j = (t15_2_B.u_f < t15_2_P.Constant_Value_e);

  /* Logic: '<S58>/Logical Operator1' */
  t15_2_B.LogicalOperator1_m = ((t15_2_B.RelationalOperator2 != 0.0) &&
    (t15_2_B.RelationalOperator1_o != 0.0) && t15_2_B.Compare_j);

  /* DataStoreRead: '<S60>/Data Store Read' */
  t15_2_B.DataStoreRead_ae = t15_2_DWork.c_a_tpl1;

  /* Gain: '<S60>/1//15' */
  t15_2_B.u5_i = t15_2_P.u5_Gain_m * t15_2_B.DataStoreRead_ae;

  /* Product: '<S60>/Div' */
  t15_2_B.Div = t15_2_B.e6 * t15_2_B.u5_i;

  /* Switch: '<S58>/1' incorporates:
   *  Switch: '<S15>/c_eob '
   */
  if (t15_2_B.LogicalOperator1_m >= t15_2_P._Threshold_k) {
    /* DataStoreRead: '<S15>/Data Store Read' */
    t15_2_B.DataStoreRead_ji = t15_2_DWork.c_a_tpl1_eob;

    /* Gain: '<S15>/ 1//15' */
    t15_2_B.u15 = t15_2_P.u15_Gain_m * t15_2_B.DataStoreRead_ji;

    /* Product: '<S15>/Divide6' */
    t15_2_B.Divide6_m = t15_2_B.u15 * t15_2_B.e6;

    /* RelationalOperator: '<S55>/LowerRelop1' incorporates:
     *  Constant: '<S15>/1'
     */
    t15_2_B.LowerRelop1_l = (t15_2_B.Divide6_m > t15_2_P._Value_b);

    /* Switch: '<S55>/Switch2' incorporates:
     *  Constant: '<S15>/1'
     */
    if (t15_2_B.LowerRelop1_l) {
      t15_2_B.Switch2_j5 = t15_2_P._Value_b;
    } else {
      /* DataStoreRead: '<S15>/Data Store Read3' */
      t15_2_B.DataStoreRead3_h = t15_2_DWork.c_a_tpl_min;

      /* RelationalOperator: '<S55>/UpperRelop' */
      t15_2_B.UpperRelop_i = (t15_2_B.Divide6_m < t15_2_B.DataStoreRead3_h);

      /* Switch: '<S55>/Switch' */
      if (t15_2_B.UpperRelop_i) {
        t15_2_B.Switch_e = t15_2_B.DataStoreRead3_h;
      } else {
        t15_2_B.Switch_e = t15_2_B.Divide6_m;
      }

      /* End of Switch: '<S55>/Switch' */
      t15_2_B.Switch2_j5 = t15_2_B.Switch_e;
    }

    /* End of Switch: '<S55>/Switch2' */

    /* Product: '<S15>/Divide11' */
    t15_2_B.Divide11_p[0] = t15_2_B.Switch2_j5 * t15_2_B.c_eob_gx[0];
    t15_2_B.Divide11_p[1] = t15_2_B.Switch2_j5 * t15_2_B.c_eob_gx[1];
    t15_2_B.u_d[0] = t15_2_B.Divide11_p[0];
    t15_2_B.u_d[1] = t15_2_B.Divide11_p[1];
  } else {
    if (t15_2_B.u_f >= t15_2_P.c_eob_Threshold) {
      /* DataStoreRead: '<S60>/Data Store Read1' incorporates:
       *  Switch: '<S15>/c_eob '
       */
      t15_2_B.DataStoreRead1_gq = t15_2_DWork.Ip_div;

      /* RelationalOperator: '<S60>/Relational Operator2' incorporates:
       *  Switch: '<S15>/c_eob '
       */
      t15_2_B.RelationalOperator2_m = (t15_2_B.Times > t15_2_B.DataStoreRead1_gq);

      /* Switch: '<S60>/Lim. Div. tr.' incorporates:
       *  Switch: '<S15>/c_eob '
       */
      if (t15_2_B.RelationalOperator2_m >= t15_2_P.LimDivtr_Threshold) {
        /* Saturate: '<S60>/Sat. Div' */
        tmin = t15_2_B.Div;
        u = t15_2_P.SatDiv_LowerSat;
        u_0 = t15_2_P.SatDiv_UpperSat;
        if (tmin >= u_0) {
          t15_2_B.SatDiv = u_0;
        } else if (tmin <= u) {
          t15_2_B.SatDiv = u;
        } else {
          t15_2_B.SatDiv = tmin;
        }

        /* End of Saturate: '<S60>/Sat. Div' */
        t15_2_B.LimDivtr = t15_2_B.SatDiv;
      } else {
        /* DataStoreRead: '<S60>/Data Store Read2' */
        t15_2_B.DataStoreRead2_c = t15_2_DWork.max_VS_lim;

        /* RelationalOperator: '<S77>/LowerRelop1' */
        t15_2_B.LowerRelop1_n = (t15_2_B.Div > t15_2_B.DataStoreRead2_c);

        /* Switch: '<S77>/Switch2' */
        if (t15_2_B.LowerRelop1_n) {
          t15_2_B.Switch2_f = t15_2_B.DataStoreRead2_c;
        } else {
          /* RelationalOperator: '<S77>/UpperRelop' incorporates:
           *  Constant: '<S60>/1'
           */
          t15_2_B.UpperRelop_o = (t15_2_B.Div < t15_2_P._Value_l);

          /* Switch: '<S77>/Switch' incorporates:
           *  Constant: '<S60>/1'
           */
          if (t15_2_B.UpperRelop_o) {
            t15_2_B.Switch_g = t15_2_P._Value_l;
          } else {
            t15_2_B.Switch_g = t15_2_B.Div;
          }

          /* End of Switch: '<S77>/Switch' */
          t15_2_B.Switch2_f = t15_2_B.Switch_g;
        }

        /* End of Switch: '<S77>/Switch2' */
        t15_2_B.LimDivtr = t15_2_B.Switch2_f;
      }

      /* End of Switch: '<S60>/Lim. Div. tr.' */

      /* Product: '<S15>/Divide8' incorporates:
       *  Switch: '<S15>/c_eob '
       */
      t15_2_B.Divide8[0] = t15_2_B.LimDivtr * t15_2_B.c_eob_gx[0];
      t15_2_B.Divide8[1] = t15_2_B.LimDivtr * t15_2_B.c_eob_gx[1];

      /* Switch: '<S15>/c_eob ' */
      t15_2_B.c_eob_kr[0] = t15_2_B.Divide8[0];
      t15_2_B.c_eob_kr[1] = t15_2_B.Divide8[1];
    } else {
      /* Gain: '<S15>/1//15' incorporates:
       *  Switch: '<S15>/c_eob '
       */
      t15_2_B.u5_g = t15_2_P.u5_Gain * t15_2_B.e6;

      /* RelationalOperator: '<S56>/LowerRelop1' incorporates:
       *  Constant: '<S15>/2'
       *  Switch: '<S15>/c_eob '
       */
      t15_2_B.LowerRelop1_k = (t15_2_B.u5_g > t15_2_P._Value_k);

      /* Switch: '<S56>/Switch2' incorporates:
       *  Constant: '<S15>/2'
       *  Switch: '<S15>/c_eob '
       */
      if (t15_2_B.LowerRelop1_k) {
        t15_2_B.Switch2_p = t15_2_P._Value_k;
      } else {
        /* DataStoreRead: '<S15>/Data Store Read4' */
        t15_2_B.DataStoreRead4 = t15_2_DWork.c_a_tpl_min;

        /* RelationalOperator: '<S56>/UpperRelop' */
        t15_2_B.UpperRelop_g = (t15_2_B.u5_g < t15_2_B.DataStoreRead4);

        /* Switch: '<S56>/Switch' */
        if (t15_2_B.UpperRelop_g) {
          t15_2_B.Switch_n = t15_2_B.DataStoreRead4;
        } else {
          t15_2_B.Switch_n = t15_2_B.u5_g;
        }

        /* End of Switch: '<S56>/Switch' */
        t15_2_B.Switch2_p = t15_2_B.Switch_n;
      }

      /* End of Switch: '<S56>/Switch2' */

      /* Product: '<S15>/Divide ' incorporates:
       *  Switch: '<S15>/c_eob '
       */
      t15_2_B.Divide_d[0] = t15_2_B.c_eob_gx[0] * t15_2_B.Switch2_p;
      t15_2_B.Divide_d[1] = t15_2_B.c_eob_gx[1] * t15_2_B.Switch2_p;

      /* Switch: '<S15>/c_eob ' */
      t15_2_B.c_eob_kr[0] = t15_2_B.Divide_d[0];
      t15_2_B.c_eob_kr[1] = t15_2_B.Divide_d[1];
    }

    t15_2_B.u_d[0] = t15_2_B.c_eob_kr[0];
    t15_2_B.u_d[1] = t15_2_B.c_eob_kr[1];
  }

  /* End of Switch: '<S58>/1' */

  /* Product: '<S15>/Divide10' */
  t15_2_B.Divide10[0] = t15_2_B.Subtract4 * t15_2_B.u_d[0];
  t15_2_B.Divide10[1] = t15_2_B.Subtract4 * t15_2_B.u_d[1];
  for (i = 0; i < 20; i++) {
    /* Gain: '<S15>/G_curr_term' */
    t15_2_B.G_curr_term[i] = 0.0;
    for (i_0 = 0; i_0 < 11; i_0++) {
      t15_2_B.G_curr_term[i] += t15_2_P.G_curr_term_Gain[20 * i_0 + i] *
        t15_2_B.e6_i[i_0];
    }

    /* End of Gain: '<S15>/G_curr_term' */

    /* Product: '<S15>/Divide12' */
    t15_2_B.Divide12_h[i] = t15_2_B.G_curr_term[i] * t15_2_B.LogicalOperator2_i;
  }

  for (i = 0; i < 11; i++) {
    /* Product: '<S54>/Divide1' */
    t15_2_B.Divide1_mzp[i] = t15_2_B.u_i[i + 8] / t15_2_B.DataStoreRead2_a[i];

    /* Gain: '<S54>/1e6' */
    t15_2_B.e6_j[i] = t15_2_P.e6_Gain_e * t15_2_B.Divide1_mzp[i];

    /* DataStoreRead: '<S5>/Data Store Read2' */
    t15_2_B.DataStoreRead2_f[i] = t15_2_DWork.ntur[i];

    /* Product: '<S5>/Divide4' */
    t15_2_B.Divide4_j[i] = t15_2_B.DataStoreRead2_f[i] * t15_2_B.Divide6_j[i];
  }

  /* Level2 S-Function Block: '<S1>/S-Function' (read_tt_kavin2) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[16];
    sfcnOutputs(rts, 0);
  }

  /* DataStoreWrite: '<S1>/Data Store Write1' */
  memcpy(&t15_2_DWork.ntur[0], &t15_2_B.SFunction_j[32], 12U * sizeof(real_T));

  /* DataStoreWrite: '<S1>/Data Store Write2' */
  for (i = 0; i < 6; i++) {
    t15_2_DWork.RupRd[i] = t15_2_B.SFunction_j[i];
  }

  /* End of DataStoreWrite: '<S1>/Data Store Write2' */

  /* DataStoreWrite: '<S1>/Data Store Write3' */
  t15_2_DWork.VS3_up = t15_2_B.SFunction_j[7];

  /* DataStoreWrite: '<S1>/Data Store Write5' */
  t15_2_DWork.VS1_up = t15_2_B.SFunction_j[6];

  /* DataStoreWrite: '<S1>/Data Store Write7' */
  t15_2_DWork.Tu = t15_2_B.SFunction_j[19];

  /* DataStoreWrite: '<S1>/Data Store Write8' */
  t15_2_DWork.c_cur_max = t15_2_B.SFunction_j[20];

  /* DataStoreRead: '<S8>/Data Store Read3' */
  t15_2_B.DataStoreRead3 = t15_2_DWork.Tu;

  /* UnitDelay: '<S6>/UD' */
  t15_2_B.Uk1_i = t15_2_DWork.UD_DSTATE_p;

  /* Sum: '<S6>/Diff' */
  t15_2_B.Diff_i = t15_2_B.Times - t15_2_B.Uk1_i;
  for (i = 0; i < 11; i++) {
    /* DataStoreWrite: '<S1>/Data Store Write4' */
    t15_2_DWork.Vcspf_up[i] = t15_2_B.SFunction_j[i + 8];

    /* DataStoreWrite: '<S1>/Data Store Write9' */
    t15_2_DWork.Imax[i] = t15_2_B.SFunction_j[i + 21];

    /* DataStoreRead: '<S9>/Data Store Read1' */
    t15_2_B.DataStoreRead1_he[i] = t15_2_DWork.Vcspf_up[i];

    /* Memory: '<S7>/Memory1' */
    t15_2_B.Memory1_l[i] = t15_2_DWork.Memory1_PreviousInput_i1[i];

    /* DataStoreRead: '<S8>/Data Store Read1' */
    t15_2_B.DataStoreRead1_i0[i] = t15_2_DWork.Vcspf_up[i];

    /* Gain: '<S8>/2' */
    t15_2_B.u_gb[i] = t15_2_P._Gain * t15_2_B.DataStoreRead1_i0[i];

    /* Product: '<S8>/Divide1' */
    t15_2_B.Divide1_ke[i] = t15_2_B.u_gb[i] / t15_2_B.DataStoreRead3;

    /* Sum: '<S7>/Add1' */
    t15_2_B.Add1_b[i] = t15_2_B.Divide4_j[i] - t15_2_B.Memory1_l[i];

    /* Product: '<S7>/Divide' */
    t15_2_B.Divide_k[i] = t15_2_B.Add1_b[i] / t15_2_B.Diff_i;

    /* RelationalOperator: '<S10>/LowerRelop1' */
    t15_2_B.LowerRelop1[i] = (t15_2_B.Divide_k[i] > t15_2_B.Divide1_ke[i]);

    /* Gain: '<S8>/-1' */
    t15_2_B.u_jm[i] = t15_2_P.u_Gain_e * t15_2_B.Divide1_ke[i];

    /* RelationalOperator: '<S10>/UpperRelop' */
    t15_2_B.UpperRelop[i] = (t15_2_B.Divide_k[i] < t15_2_B.u_jm[i]);

    /* Switch: '<S10>/Switch' */
    if (t15_2_B.UpperRelop[i]) {
      t15_2_B.Switch_b[i] = t15_2_B.u_jm[i];
    } else {
      t15_2_B.Switch_b[i] = t15_2_B.Divide_k[i];
    }

    /* End of Switch: '<S10>/Switch' */

    /* Switch: '<S10>/Switch2' */
    if (t15_2_B.LowerRelop1[i]) {
      t15_2_B.Switch2[i] = t15_2_B.Divide1_ke[i];
    } else {
      t15_2_B.Switch2[i] = t15_2_B.Switch_b[i];
    }

    /* End of Switch: '<S10>/Switch2' */

    /* Product: '<S7>/Divide1' */
    t15_2_B.Divide1_a2[i] = t15_2_B.Switch2[i] * t15_2_B.Diff_i;

    /* Sum: '<S7>/Add2' */
    t15_2_B.Add2_d0[i] = t15_2_B.Memory1_l[i] + t15_2_B.Divide1_a2[i];

    /* RelationalOperator: '<S11>/LowerRelop1' */
    t15_2_B.LowerRelop1_a[i] = (t15_2_B.Add2_d0[i] > t15_2_B.DataStoreRead1_he[i]);

    /* Gain: '<S9>/Gain' */
    t15_2_B.Gain[i] = t15_2_P.Gain_Gain_k * t15_2_B.DataStoreRead1_he[i];

    /* RelationalOperator: '<S11>/UpperRelop' */
    t15_2_B.UpperRelop_b[i] = (t15_2_B.Add2_d0[i] < t15_2_B.Gain[i]);

    /* Switch: '<S11>/Switch' */
    if (t15_2_B.UpperRelop_b[i]) {
      t15_2_B.Switch_h[i] = t15_2_B.Gain[i];
    } else {
      t15_2_B.Switch_h[i] = t15_2_B.Add2_d0[i];
    }

    /* End of Switch: '<S11>/Switch' */

    /* Switch: '<S11>/Switch2' */
    if (t15_2_B.LowerRelop1_a[i]) {
      t15_2_B.Switch2_j[i] = t15_2_B.DataStoreRead1_he[i];
    } else {
      t15_2_B.Switch2_j[i] = t15_2_B.Switch_h[i];
    }

    /* End of Switch: '<S11>/Switch2' */

    /* DataStoreRead: '<S2>/Data Store Read2' */
    t15_2_B.DataStoreRead2_g[i] = t15_2_DWork.ntur[i];

    /* Product: '<S2>/Divide3' */
    t15_2_B.Divide3_m[i] = t15_2_B.Switch2_j[i] / t15_2_B.DataStoreRead2_g[i];

    /* Product: '<S2>/Divide1' incorporates:
     *  Constant: '<S2>/wz1'
     */
    t15_2_B.Divide1_n2[i] = t15_2_P.wz1_Value[i] / t15_2_B.DataStoreRead2_g[i];
  }

  /* DataStoreRead: '<S4>/Data Store Read1' */
  t15_2_B.DataStoreRead1_c = t15_2_DWork.VS1_up;

  /* RelationalOperator: '<S12>/LowerRelop1' */
  t15_2_B.LowerRelop1_i = (t15_2_B.Divide10[0] > t15_2_B.DataStoreRead1_c);

  /* Switch: '<S12>/Switch2' */
  if (t15_2_B.LowerRelop1_i) {
    t15_2_B.Switch2_o = t15_2_B.DataStoreRead1_c;
  } else {
    /* Gain: '<S4>/Gain' */
    t15_2_B.Gain_g = t15_2_P.Gain_Gain * t15_2_B.DataStoreRead1_c;

    /* RelationalOperator: '<S12>/UpperRelop' */
    t15_2_B.UpperRelop_ae = (t15_2_B.Divide10[0] < t15_2_B.Gain_g);

    /* Switch: '<S12>/Switch' */
    if (t15_2_B.UpperRelop_ae) {
      t15_2_B.Switch_dy = t15_2_B.Gain_g;
    } else {
      t15_2_B.Switch_dy = t15_2_B.Divide10[0];
    }

    /* End of Switch: '<S12>/Switch' */
    t15_2_B.Switch2_o = t15_2_B.Switch_dy;
  }

  for (i = 0; i < 11; i++) {
    /* Product: '<S2>/Divide2' */
    t15_2_B.Divide2_k[i] = t15_2_B.Divide1_n2[i] * t15_2_B.Switch2_o;

    /* Sum: '<S2>/Add1' */
    t15_2_B.Add1_d[i] = t15_2_B.Divide3_m[i] + t15_2_B.Divide2_k[i];
  }

  /* End of Switch: '<S12>/Switch2' */

  /* DataStoreRead: '<S2>/Data Store Read1' */
  t15_2_B.DataStoreRead1_hh = t15_2_DWork.ntur[11];

  /* Product: '<S2>/Divide4' incorporates:
   *  Constant: '<S2>/wz2'
   */
  t15_2_B.Divide4_l = t15_2_P.wz2_Value / t15_2_B.DataStoreRead1_hh;

  /* DataStoreRead: '<S4>/Data Store Read3' */
  t15_2_B.DataStoreRead3_e = t15_2_DWork.VS3_up;

  /* RelationalOperator: '<S13>/LowerRelop1' */
  t15_2_B.LowerRelop1_o = (t15_2_B.Divide10[1] > t15_2_B.DataStoreRead3_e);

  /* Switch: '<S13>/Switch2' */
  if (t15_2_B.LowerRelop1_o) {
    t15_2_B.Switch2_c = t15_2_B.DataStoreRead3_e;
  } else {
    /* Gain: '<S4>/Gain1' */
    t15_2_B.Gain1 = t15_2_P.Gain1_Gain * t15_2_B.DataStoreRead3_e;

    /* RelationalOperator: '<S13>/UpperRelop' */
    t15_2_B.UpperRelop_oc = (t15_2_B.Divide10[1] < t15_2_B.Gain1);

    /* Switch: '<S13>/Switch' */
    if (t15_2_B.UpperRelop_oc) {
      t15_2_B.Switch_l = t15_2_B.Gain1;
    } else {
      t15_2_B.Switch_l = t15_2_B.Divide10[1];
    }

    /* End of Switch: '<S13>/Switch' */
    t15_2_B.Switch2_c = t15_2_B.Switch_l;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* Product: '<S2>/Divide5' */
  t15_2_B.Divide5_j = t15_2_B.Divide4_l * t15_2_B.Switch2_c;

  /* SignalConversion: '<S2>/TmpSignal ConversionAtnpf,12Inport1' */
  memcpy(&t15_2_B.TmpSignalConversionAtnpf12Inpor[0], &t15_2_B.Add1_d[0], 11U *
         sizeof(real_T));
  t15_2_B.TmpSignalConversionAtnpf12Inpor[11] = t15_2_B.Divide5_j;
  for (i = 0; i < 15; i++) {
    /* Gain: '<S2>/npf,12' */
    t15_2_B.npf12[i] = 0.0;
    for (i_0 = 0; i_0 < 12; i_0++) {
      t15_2_B.npf12[i] += t15_2_P.npf12_Gain[15 * i_0 + i] *
        t15_2_B.TmpSignalConversionAtnpf12Inpor[i_0];
    }

    /* End of Gain: '<S2>/npf,12' */

    /* Outport: '<Root>/to_DINA' */
    t15_2_Y.to_DINA[i] = t15_2_B.npf12[i];
  }

  /* Outport: '<Root>/to_DINA' */
  memcpy(&t15_2_Y.to_DINA[15], &t15_2_B.Divide3_m[0], 11U * sizeof(real_T));
  for (i = 0; i < 11; i++) {
    /* Outport: '<Root>/to_DINA' */
    t15_2_Y.to_DINA[i + 26] = t15_2_B.Divide2_k[i];

    /* Update for Memory: '<S65>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_c[i] = t15_2_B.u_fs[i];

    /* Update for Memory: '<S57>/Memory' */
    t15_2_DWork.Memory_PreviousInput_j[i] = t15_2_B.u_p[i];

    /* Update for Memory: '<S73>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_cm[i] = t15_2_B.u_g[i];

    /* Update for Memory: '<S7>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_i1[i] = t15_2_B.Switch2_j[i];
  }

  /* Outport: '<Root>/to_DINA' */
  t15_2_Y.to_DINA[37] = t15_2_B.Divide5_j;

  /* Update for Memory: '<S5>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput = t15_2_B.Ip1e4;

  /* Update for Memory: '<S17>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput = t15_2_B.switch1;

  /* Update for Memory: '<S25>/Memory' */
  t15_2_DWork.Memory_PreviousInput = t15_2_B.LogicalOperator;

  /* Update for Memory: '<S18>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_p = t15_2_B.c_eob;

  /* Update for Memory: '<S44>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_h = t15_2_B.c_eob1;

  /* Update for Memory: '<S44>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_k = t15_2_B.c_eob_h;

  /* Update for Memory: '<S39>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_o = t15_2_B.c_eob1_d;

  /* Update for Memory: '<S39>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_d = t15_2_B.c_eob_a;

  /* Update for Memory: '<S40>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_j = t15_2_B.c_eob1_f;

  /* Update for Memory: '<S40>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_m = t15_2_B.c_eob_jz;

  /* Update for Memory: '<S41>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_e = t15_2_B.c_eob1_c;

  /* Update for Memory: '<S41>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_py = t15_2_B.c_eob_aj;

  /* Update for Memory: '<S42>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_k = t15_2_B.c_eob1_g;

  /* Update for Memory: '<S42>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_h = t15_2_B.c_eob_d;

  /* Update for Memory: '<S43>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_n = t15_2_B.c_eob1_h;

  /* Update for Memory: '<S43>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_g = t15_2_B.c_eob_o;

  /* Update for Memory: '<S28>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_b = t15_2_B.c_eob_c;

  /* Update for Memory: '<S31>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_bu = t15_2_B.c_eob_n;

  /* Update for Memory: '<S32>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_op = t15_2_B.c_eob_k;

  /* Update for Memory: '<S33>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_f = t15_2_B.c_eob_g;

  /* Update for Memory: '<S34>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_hg = t15_2_B.c_eob_jp;

  /* Update for Memory: '<S35>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_g = t15_2_B.c_eob_m;

  /* Update for Memory: '<S36>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_c = t15_2_B.c_eob_cm;

  /* Update for Memory: '<S37>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_jv = t15_2_B.c_eob_h3;

  /* Update for Memory: '<S38>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_hu = t15_2_B.c_eob_gm;

  /* Update for Memory: '<S29>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_g2 = t15_2_B.c_eob_cn;

  /* Update for Memory: '<S30>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_b1 = t15_2_B.c_eob_cg;

  /* Update for UnitDelay: '<S26>/UD' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_DWork.UD_DSTATE = t15_2_U.In1[0];

  /* Update for UnitDelay: '<S27>/UD' */
  t15_2_DWork.UD_DSTATE_c = t15_2_B.Times;

  /* Update for Memory: '<S51>/Memory3' */
  t15_2_DWork.Memory3_PreviousInput = t15_2_B.switch1_i;

  /* Update for Memory: '<S63>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_i = t15_2_B.c_eob_i;

  /* Update for DiscreteStateSpace: '<S15>/Div. contr.' */
  {
    real_T xnew[32];

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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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
      const real_T *u = &t15_2_B.Divide2[0];
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

    xnew[20] += (t15_2_P.Divcontr_B[340])*t15_2_B.Divide2[12];

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

    xnew[21] += (t15_2_P.Divcontr_B[341])*t15_2_B.Divide2[12];

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

    xnew[22] += (t15_2_P.Divcontr_B[342])*t15_2_B.Divide2[12];

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

    xnew[23] += (t15_2_P.Divcontr_B[343])*t15_2_B.Divide2[12];

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

    xnew[24] += (t15_2_P.Divcontr_B[344])*t15_2_B.Divide2[12];
    xnew[25] = (t15_2_P.Divcontr_A[565])*t15_2_DWork.Divcontr_DSTATE[25];
    xnew[25] += (t15_2_P.Divcontr_B[345])*t15_2_B.Divide2[0];
    xnew[26] = (t15_2_P.Divcontr_A[566])*t15_2_DWork.Divcontr_DSTATE[26];
    xnew[26] += (t15_2_P.Divcontr_B[346])*t15_2_B.Divide2[1];
    xnew[27] = (t15_2_P.Divcontr_A[567])*t15_2_DWork.Divcontr_DSTATE[27];
    xnew[27] += (t15_2_P.Divcontr_B[347])*t15_2_B.Divide2[2];
    xnew[28] = (t15_2_P.Divcontr_A[568])*t15_2_DWork.Divcontr_DSTATE[28];
    xnew[28] += (t15_2_P.Divcontr_B[348])*t15_2_B.Divide2[3];
    xnew[29] = (t15_2_P.Divcontr_A[569])*t15_2_DWork.Divcontr_DSTATE[29];
    xnew[29] += (t15_2_P.Divcontr_B[349])*t15_2_B.Divide2[4];
    xnew[30] = (t15_2_P.Divcontr_A[570])*t15_2_DWork.Divcontr_DSTATE[30];
    xnew[30] += (t15_2_P.Divcontr_B[350])*t15_2_B.Divide2[5];
    xnew[31] = (t15_2_P.Divcontr_A[571])*t15_2_DWork.Divcontr_DSTATE[31];
    xnew[31] += (t15_2_P.Divcontr_B[351])*t15_2_B.Divide2[7];
    (void) memcpy(&t15_2_DWork.Divcontr_DSTATE[0], xnew,
                  sizeof(real_T)*32);
  }

  /* Update for Memory: '<S61>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_ic = t15_2_B.switch1_g;

  /* Update for DiscreteStateSpace: '<S15>/Div_rd contr' */
  {
    real_T xnew[22];

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
    (void) memcpy(&t15_2_DWork.Div_rdcontr_DSTATE[0], xnew,
                  sizeof(real_T)*22);
  }

  /* Update for Memory: '<S53>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_gz = t15_2_B.u_j;

  /* Update for DiscreteStateSpace: '<S15>/Curr. term. contr' */
  {
    real_T xnew[22];

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
      const real_T *u = &t15_2_B.Divide12_h[0];
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
      const real_T *u = &t15_2_B.Divide12_h[0];
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
      const real_T *u = &t15_2_B.Divide12_h[0];
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
      const real_T *u = &t15_2_B.Divide12_h[0];
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
      const real_T *u = &t15_2_B.Divide12_h[0];
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
      const real_T *u = &t15_2_B.Divide12_h[0];
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
      const real_T *u = &t15_2_B.Divide12_h[0];
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
      const real_T *u = &t15_2_B.Divide12_h[0];
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
      const real_T *u = &t15_2_B.Divide12_h[0];
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
      const real_T *u = &t15_2_B.Divide12_h[0];
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
      const real_T *u = &t15_2_B.Divide12_h[0];
      real_T *pxnew21 = &xnew[21];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew21 += (*pB110++) * u[*pBidx++];
      }
    }

    (void) memcpy(&t15_2_DWork.Currtermcontr_DSTATE[0], xnew,
                  sizeof(real_T)*22);
  }

  /* Update for DiscreteStateSpace: '<S54>/Lim. contr.' */
  {
    real_T xnew[46];

    {
      static const int_T colAidxRow0[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = t15_2_P.Limcontr_A;
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 45;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow0[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow0[0];
      const real_T *pB0 = t15_2_P.Limcontr_B;
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew0 += (*pB0++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow1[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA46 = &t15_2_P.Limcontr_A[46];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 45;
      *pxnew1 = (*pA46++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA46++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow1[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow1[0];
      const real_T *pB17 = &t15_2_P.Limcontr_B[17];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew1 += (*pB17++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow2[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA92 = &t15_2_P.Limcontr_A[92];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 45;
      *pxnew2 = (*pA92++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA92++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow2[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow2[0];
      const real_T *pB34 = &t15_2_P.Limcontr_B[34];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew2 += (*pB34++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow3[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA138 = &t15_2_P.Limcontr_A[138];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 45;
      *pxnew3 = (*pA138++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA138++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow3[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow3[0];
      const real_T *pB51 = &t15_2_P.Limcontr_B[51];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew3 += (*pB51++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow4[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA184 = &t15_2_P.Limcontr_A[184];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 45;
      *pxnew4 = (*pA184++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA184++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow4[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow4[0];
      const real_T *pB68 = &t15_2_P.Limcontr_B[68];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew4 += (*pB68++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow5[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA230 = &t15_2_P.Limcontr_A[230];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 45;
      *pxnew5 = (*pA230++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA230++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow5[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow5[0];
      const real_T *pB85 = &t15_2_P.Limcontr_B[85];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew5 += (*pB85++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow6[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA276 = &t15_2_P.Limcontr_A[276];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 45;
      *pxnew6 = (*pA276++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA276++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow6[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow6[0];
      const real_T *pB102 = &t15_2_P.Limcontr_B[102];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew6 += (*pB102++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow7[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA322 = &t15_2_P.Limcontr_A[322];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 45;
      *pxnew7 = (*pA322++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA322++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow7[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow7[0];
      const real_T *pB119 = &t15_2_P.Limcontr_B[119];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew7 += (*pB119++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow8[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA368 = &t15_2_P.Limcontr_A[368];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 45;
      *pxnew8 = (*pA368++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA368++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow8[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow8[0];
      const real_T *pB136 = &t15_2_P.Limcontr_B[136];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew8 += (*pB136++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow9[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA414 = &t15_2_P.Limcontr_A[414];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 45;
      *pxnew9 = (*pA414++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA414++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow9[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow9[0];
      const real_T *pB153 = &t15_2_P.Limcontr_B[153];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew9 += (*pB153++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow10[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA460 = &t15_2_P.Limcontr_A[460];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 45;
      *pxnew10 = (*pA460++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA460++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow10[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow10[0];
      const real_T *pB170 = &t15_2_P.Limcontr_B[170];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew10 += (*pB170++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow11[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow11[0];
      const real_T *pA506 = &t15_2_P.Limcontr_A[506];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew11 = &xnew[11];
      int_T numNonZero = 45;
      *pxnew11 = (*pA506++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew11 += (*pA506++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow11[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow11[0];
      const real_T *pB187 = &t15_2_P.Limcontr_B[187];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew11 = &xnew[11];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew11 += (*pB187++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow12[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow12[0];
      const real_T *pA552 = &t15_2_P.Limcontr_A[552];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 45;
      *pxnew12 = (*pA552++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew12 += (*pA552++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow12[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow12[0];
      const real_T *pB204 = &t15_2_P.Limcontr_B[204];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew12 += (*pB204++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow13[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow13[0];
      const real_T *pA598 = &t15_2_P.Limcontr_A[598];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew13 = &xnew[13];
      int_T numNonZero = 45;
      *pxnew13 = (*pA598++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew13 += (*pA598++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow13[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow13[0];
      const real_T *pB221 = &t15_2_P.Limcontr_B[221];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew13 = &xnew[13];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew13 += (*pB221++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow14[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow14[0];
      const real_T *pA644 = &t15_2_P.Limcontr_A[644];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew14 = &xnew[14];
      int_T numNonZero = 45;
      *pxnew14 = (*pA644++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew14 += (*pA644++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow14[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow14[0];
      const real_T *pB238 = &t15_2_P.Limcontr_B[238];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew14 = &xnew[14];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew14 += (*pB238++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow15[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow15[0];
      const real_T *pA690 = &t15_2_P.Limcontr_A[690];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew15 = &xnew[15];
      int_T numNonZero = 45;
      *pxnew15 = (*pA690++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew15 += (*pA690++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow15[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow15[0];
      const real_T *pB255 = &t15_2_P.Limcontr_B[255];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew15 = &xnew[15];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew15 += (*pB255++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow16[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow16[0];
      const real_T *pA736 = &t15_2_P.Limcontr_A[736];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew16 = &xnew[16];
      int_T numNonZero = 45;
      *pxnew16 = (*pA736++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew16 += (*pA736++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow16[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow16[0];
      const real_T *pB272 = &t15_2_P.Limcontr_B[272];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew16 = &xnew[16];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew16 += (*pB272++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow17[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow17[0];
      const real_T *pA782 = &t15_2_P.Limcontr_A[782];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew17 = &xnew[17];
      int_T numNonZero = 45;
      *pxnew17 = (*pA782++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew17 += (*pA782++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow17[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow17[0];
      const real_T *pB289 = &t15_2_P.Limcontr_B[289];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew17 = &xnew[17];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew17 += (*pB289++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow18[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow18[0];
      const real_T *pA828 = &t15_2_P.Limcontr_A[828];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew18 = &xnew[18];
      int_T numNonZero = 45;
      *pxnew18 = (*pA828++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew18 += (*pA828++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow18[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow18[0];
      const real_T *pB306 = &t15_2_P.Limcontr_B[306];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew18 = &xnew[18];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew18 += (*pB306++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow19[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow19[0];
      const real_T *pA874 = &t15_2_P.Limcontr_A[874];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew19 = &xnew[19];
      int_T numNonZero = 45;
      *pxnew19 = (*pA874++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew19 += (*pA874++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow19[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow19[0];
      const real_T *pB323 = &t15_2_P.Limcontr_B[323];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew19 = &xnew[19];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew19 += (*pB323++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow20[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow20[0];
      const real_T *pA920 = &t15_2_P.Limcontr_A[920];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew20 = &xnew[20];
      int_T numNonZero = 45;
      *pxnew20 = (*pA920++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew20 += (*pA920++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow20[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow20[0];
      const real_T *pB340 = &t15_2_P.Limcontr_B[340];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew20 = &xnew[20];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew20 += (*pB340++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow21[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow21[0];
      const real_T *pA966 = &t15_2_P.Limcontr_A[966];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew21 = &xnew[21];
      int_T numNonZero = 45;
      *pxnew21 = (*pA966++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew21 += (*pA966++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow21[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow21[0];
      const real_T *pB357 = &t15_2_P.Limcontr_B[357];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew21 = &xnew[21];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew21 += (*pB357++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow22[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow22[0];
      const real_T *pA1012 = &t15_2_P.Limcontr_A[1012];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew22 = &xnew[22];
      int_T numNonZero = 45;
      *pxnew22 = (*pA1012++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew22 += (*pA1012++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow22[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow22[0];
      const real_T *pB374 = &t15_2_P.Limcontr_B[374];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew22 = &xnew[22];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew22 += (*pB374++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow23[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow23[0];
      const real_T *pA1058 = &t15_2_P.Limcontr_A[1058];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew23 = &xnew[23];
      int_T numNonZero = 45;
      *pxnew23 = (*pA1058++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew23 += (*pA1058++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow23[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow23[0];
      const real_T *pB391 = &t15_2_P.Limcontr_B[391];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew23 = &xnew[23];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew23 += (*pB391++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow24[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow24[0];
      const real_T *pA1104 = &t15_2_P.Limcontr_A[1104];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew24 = &xnew[24];
      int_T numNonZero = 45;
      *pxnew24 = (*pA1104++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew24 += (*pA1104++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow24[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow24[0];
      const real_T *pB408 = &t15_2_P.Limcontr_B[408];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew24 = &xnew[24];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew24 += (*pB408++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow25[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow25[0];
      const real_T *pA1150 = &t15_2_P.Limcontr_A[1150];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew25 = &xnew[25];
      int_T numNonZero = 45;
      *pxnew25 = (*pA1150++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew25 += (*pA1150++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow25[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow25[0];
      const real_T *pB425 = &t15_2_P.Limcontr_B[425];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew25 = &xnew[25];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew25 += (*pB425++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow26[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow26[0];
      const real_T *pA1196 = &t15_2_P.Limcontr_A[1196];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew26 = &xnew[26];
      int_T numNonZero = 45;
      *pxnew26 = (*pA1196++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew26 += (*pA1196++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow26[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow26[0];
      const real_T *pB442 = &t15_2_P.Limcontr_B[442];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew26 = &xnew[26];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew26 += (*pB442++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow27[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow27[0];
      const real_T *pA1242 = &t15_2_P.Limcontr_A[1242];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew27 = &xnew[27];
      int_T numNonZero = 45;
      *pxnew27 = (*pA1242++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew27 += (*pA1242++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow27[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow27[0];
      const real_T *pB459 = &t15_2_P.Limcontr_B[459];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew27 = &xnew[27];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew27 += (*pB459++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow28[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow28[0];
      const real_T *pA1288 = &t15_2_P.Limcontr_A[1288];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew28 = &xnew[28];
      int_T numNonZero = 45;
      *pxnew28 = (*pA1288++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew28 += (*pA1288++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow28[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow28[0];
      const real_T *pB476 = &t15_2_P.Limcontr_B[476];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew28 = &xnew[28];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew28 += (*pB476++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow29[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow29[0];
      const real_T *pA1334 = &t15_2_P.Limcontr_A[1334];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew29 = &xnew[29];
      int_T numNonZero = 45;
      *pxnew29 = (*pA1334++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew29 += (*pA1334++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow29[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow29[0];
      const real_T *pB493 = &t15_2_P.Limcontr_B[493];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew29 = &xnew[29];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew29 += (*pB493++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow30[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow30[0];
      const real_T *pA1380 = &t15_2_P.Limcontr_A[1380];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew30 = &xnew[30];
      int_T numNonZero = 45;
      *pxnew30 = (*pA1380++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew30 += (*pA1380++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow30[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow30[0];
      const real_T *pB510 = &t15_2_P.Limcontr_B[510];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew30 = &xnew[30];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew30 += (*pB510++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow31[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow31[0];
      const real_T *pA1426 = &t15_2_P.Limcontr_A[1426];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew31 = &xnew[31];
      int_T numNonZero = 45;
      *pxnew31 = (*pA1426++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew31 += (*pA1426++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow31[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow31[0];
      const real_T *pB527 = &t15_2_P.Limcontr_B[527];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew31 = &xnew[31];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew31 += (*pB527++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow32[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow32[0];
      const real_T *pA1472 = &t15_2_P.Limcontr_A[1472];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew32 = &xnew[32];
      int_T numNonZero = 45;
      *pxnew32 = (*pA1472++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew32 += (*pA1472++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow32[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow32[0];
      const real_T *pB544 = &t15_2_P.Limcontr_B[544];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew32 = &xnew[32];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew32 += (*pB544++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow33[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow33[0];
      const real_T *pA1518 = &t15_2_P.Limcontr_A[1518];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew33 = &xnew[33];
      int_T numNonZero = 45;
      *pxnew33 = (*pA1518++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew33 += (*pA1518++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow33[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow33[0];
      const real_T *pB561 = &t15_2_P.Limcontr_B[561];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew33 = &xnew[33];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew33 += (*pB561++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow34[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow34[0];
      const real_T *pA1564 = &t15_2_P.Limcontr_A[1564];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew34 = &xnew[34];
      int_T numNonZero = 45;
      *pxnew34 = (*pA1564++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew34 += (*pA1564++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow34[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow34[0];
      const real_T *pB578 = &t15_2_P.Limcontr_B[578];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew34 = &xnew[34];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew34 += (*pB578++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow35[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow35[0];
      const real_T *pA1610 = &t15_2_P.Limcontr_A[1610];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew35 = &xnew[35];
      int_T numNonZero = 45;
      *pxnew35 = (*pA1610++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew35 += (*pA1610++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow35[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow35[0];
      const real_T *pB595 = &t15_2_P.Limcontr_B[595];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew35 = &xnew[35];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew35 += (*pB595++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow36[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow36[0];
      const real_T *pA1656 = &t15_2_P.Limcontr_A[1656];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew36 = &xnew[36];
      int_T numNonZero = 45;
      *pxnew36 = (*pA1656++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew36 += (*pA1656++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow36[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow36[0];
      const real_T *pB612 = &t15_2_P.Limcontr_B[612];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew36 = &xnew[36];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew36 += (*pB612++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow37[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow37[0];
      const real_T *pA1702 = &t15_2_P.Limcontr_A[1702];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew37 = &xnew[37];
      int_T numNonZero = 45;
      *pxnew37 = (*pA1702++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew37 += (*pA1702++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow37[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow37[0];
      const real_T *pB629 = &t15_2_P.Limcontr_B[629];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew37 = &xnew[37];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew37 += (*pB629++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow38[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow38[0];
      const real_T *pA1748 = &t15_2_P.Limcontr_A[1748];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew38 = &xnew[38];
      int_T numNonZero = 45;
      *pxnew38 = (*pA1748++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew38 += (*pA1748++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow38[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow38[0];
      const real_T *pB646 = &t15_2_P.Limcontr_B[646];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew38 = &xnew[38];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew38 += (*pB646++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow39[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow39[0];
      const real_T *pA1794 = &t15_2_P.Limcontr_A[1794];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew39 = &xnew[39];
      int_T numNonZero = 45;
      *pxnew39 = (*pA1794++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew39 += (*pA1794++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow39[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow39[0];
      const real_T *pB663 = &t15_2_P.Limcontr_B[663];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew39 = &xnew[39];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew39 += (*pB663++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow40[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow40[0];
      const real_T *pA1840 = &t15_2_P.Limcontr_A[1840];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew40 = &xnew[40];
      int_T numNonZero = 45;
      *pxnew40 = (*pA1840++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew40 += (*pA1840++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow40[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow40[0];
      const real_T *pB680 = &t15_2_P.Limcontr_B[680];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew40 = &xnew[40];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew40 += (*pB680++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow41[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow41[0];
      const real_T *pA1886 = &t15_2_P.Limcontr_A[1886];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew41 = &xnew[41];
      int_T numNonZero = 45;
      *pxnew41 = (*pA1886++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew41 += (*pA1886++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow41[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow41[0];
      const real_T *pB697 = &t15_2_P.Limcontr_B[697];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew41 = &xnew[41];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew41 += (*pB697++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow42[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow42[0];
      const real_T *pA1932 = &t15_2_P.Limcontr_A[1932];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew42 = &xnew[42];
      int_T numNonZero = 45;
      *pxnew42 = (*pA1932++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew42 += (*pA1932++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow42[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow42[0];
      const real_T *pB714 = &t15_2_P.Limcontr_B[714];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew42 = &xnew[42];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew42 += (*pB714++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow43[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow43[0];
      const real_T *pA1978 = &t15_2_P.Limcontr_A[1978];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew43 = &xnew[43];
      int_T numNonZero = 45;
      *pxnew43 = (*pA1978++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew43 += (*pA1978++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow43[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow43[0];
      const real_T *pB731 = &t15_2_P.Limcontr_B[731];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew43 = &xnew[43];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew43 += (*pB731++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow44[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow44[0];
      const real_T *pA2024 = &t15_2_P.Limcontr_A[2024];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew44 = &xnew[44];
      int_T numNonZero = 45;
      *pxnew44 = (*pA2024++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew44 += (*pA2024++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow44[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow44[0];
      const real_T *pB748 = &t15_2_P.Limcontr_B[748];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew44 = &xnew[44];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew44 += (*pB748++) * u[*pBidx++];
      }
    }

    {
      static const int_T colAidxRow45[46] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 };

      const int_T *pAidx = &colAidxRow45[0];
      const real_T *pA2070 = &t15_2_P.Limcontr_A[2070];
      const real_T *xd = &t15_2_DWork.Limcontr_DSTATE[0];
      real_T *pxnew45 = &xnew[45];
      int_T numNonZero = 45;
      *pxnew45 = (*pA2070++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew45 += (*pA2070++) * xd[*pAidx++];
      }
    }

    {
      static const int_T colBidxRow45[17] = { 0, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18 };

      const int_T *pBidx = &colBidxRow45[0];
      const real_T *pB765 = &t15_2_P.Limcontr_B[765];
      const real_T *u = &t15_2_B.Divide12_l[0];
      real_T *pxnew45 = &xnew[45];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew45 += (*pB765++) * u[*pBidx++];
      }
    }

    (void) memcpy(&t15_2_DWork.Limcontr_DSTATE[0], xnew,
                  sizeof(real_T)*46);
  }

  /* Update for DiscreteStateSpace: '<S54>/Curr. contr.' */
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
      const real_T *u = &t15_2_B.e6_j[0];
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
      const real_T *u = &t15_2_B.e6_j[0];
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
      const real_T *u = &t15_2_B.e6_j[0];
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
      const real_T *u = &t15_2_B.e6_j[0];
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
      const real_T *u = &t15_2_B.e6_j[0];
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
      const real_T *u = &t15_2_B.e6_j[0];
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
      const real_T *u = &t15_2_B.e6_j[0];
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
      const real_T *u = &t15_2_B.e6_j[0];
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
      const real_T *u = &t15_2_B.e6_j[0];
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
      const real_T *u = &t15_2_B.e6_j[0];
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
      const real_T *u = &t15_2_B.e6_j[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew10 += (*pB110++) * u[*pBidx++];
      }
    }

    (void) memcpy(&t15_2_DWork.Currcontr_DSTATE[0], xnew,
                  sizeof(real_T)*11);
  }

  /* Update for UniformRandomNumber: '<S62>/Uniform Random Number' */
  tmin = t15_2_P.UniformRandomNumber_Minimum;
  t15_2_DWork.UniformRandomNumber_NextOutput =
    (t15_2_P.UniformRandomNumber_Maximum - tmin) * rt_urand_Upu32_Yd_f_pw_snf
    (&t15_2_DWork.RandSeed) + tmin;

  /* Update for UnitDelay: '<S80>/UD' */
  t15_2_DWork.UD_DSTATE_o = t15_2_B.Times;

  /* Update for DiscreteStateSpace: '<S59>/VS. contr' */
  {
    real_T xnew[9];
    xnew[0] = (t15_2_P.VScontr_A[0])*t15_2_DWork.VScontr_DSTATE[0] +
      (t15_2_P.VScontr_A[1])*t15_2_DWork.VScontr_DSTATE[1]
      + (t15_2_P.VScontr_A[2])*t15_2_DWork.VScontr_DSTATE[2]
      + (t15_2_P.VScontr_A[3])*t15_2_DWork.VScontr_DSTATE[7];
    xnew[0] += (t15_2_P.VScontr_B[0])*t15_2_B.Divide12_m[0] +
      (t15_2_P.VScontr_B[1])*t15_2_B.Divide12_m[1];
    xnew[1] = (t15_2_P.VScontr_A[4])*t15_2_DWork.VScontr_DSTATE[0] +
      (t15_2_P.VScontr_A[5])*t15_2_DWork.VScontr_DSTATE[1]
      + (t15_2_P.VScontr_A[6])*t15_2_DWork.VScontr_DSTATE[2]
      + (t15_2_P.VScontr_A[7])*t15_2_DWork.VScontr_DSTATE[7];
    xnew[1] += (t15_2_P.VScontr_B[2])*t15_2_B.Divide12_m[0] +
      (t15_2_P.VScontr_B[3])*t15_2_B.Divide12_m[1];
    xnew[2] = (t15_2_P.VScontr_A[8])*t15_2_DWork.VScontr_DSTATE[0] +
      (t15_2_P.VScontr_A[9])*t15_2_DWork.VScontr_DSTATE[1]
      + (t15_2_P.VScontr_A[10])*t15_2_DWork.VScontr_DSTATE[2]
      + (t15_2_P.VScontr_A[11])*t15_2_DWork.VScontr_DSTATE[7];
    xnew[2] += (t15_2_P.VScontr_B[4])*t15_2_B.Divide12_m[0] +
      (t15_2_P.VScontr_B[5])*t15_2_B.Divide12_m[1];

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

    xnew[3] += (t15_2_P.VScontr_B[6])*t15_2_B.Divide12_m[0] +
      (t15_2_P.VScontr_B[7])*t15_2_B.Divide12_m[1];

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

    xnew[4] += (t15_2_P.VScontr_B[8])*t15_2_B.Divide12_m[0] +
      (t15_2_P.VScontr_B[9])*t15_2_B.Divide12_m[1];

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

    xnew[5] += (t15_2_P.VScontr_B[10])*t15_2_B.Divide12_m[0] +
      (t15_2_P.VScontr_B[11])*t15_2_B.Divide12_m[1];

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

    xnew[6] += (t15_2_P.VScontr_B[12])*t15_2_B.Divide12_m[0] +
      (t15_2_P.VScontr_B[13])*t15_2_B.Divide12_m[1];
    xnew[7] = (t15_2_P.VScontr_A[32])*t15_2_DWork.VScontr_DSTATE[7];
    xnew[7] += (t15_2_P.VScontr_B[14])*t15_2_B.Divide12_m[0];
    xnew[8] = (t15_2_P.VScontr_A[33])*t15_2_DWork.VScontr_DSTATE[8];
    xnew[8] += (t15_2_P.VScontr_B[15])*t15_2_B.Divide12_m[1];
    (void) memcpy(&t15_2_DWork.VScontr_DSTATE[0], xnew,
                  sizeof(real_T)*9);
  }

  /* Update for DiscreteStateSpace: '<S59>/VS. contr hl' */
  {
    real_T xnew[8];
    xnew[0] = (t15_2_P.VScontrhl_A[0])*t15_2_DWork.VScontrhl_DSTATE[0] +
      (t15_2_P.VScontrhl_A[1])*t15_2_DWork.VScontrhl_DSTATE[1]
      + (t15_2_P.VScontrhl_A[2])*t15_2_DWork.VScontrhl_DSTATE[2]
      + (t15_2_P.VScontrhl_A[3])*t15_2_DWork.VScontrhl_DSTATE[7];
    xnew[0] += (t15_2_P.VScontrhl_B[0])*t15_2_B.Divide4_c[0] +
      (t15_2_P.VScontrhl_B[1])*t15_2_B.Divide4_c[1];
    xnew[1] = (t15_2_P.VScontrhl_A[4])*t15_2_DWork.VScontrhl_DSTATE[0] +
      (t15_2_P.VScontrhl_A[5])*t15_2_DWork.VScontrhl_DSTATE[1]
      + (t15_2_P.VScontrhl_A[6])*t15_2_DWork.VScontrhl_DSTATE[2]
      + (t15_2_P.VScontrhl_A[7])*t15_2_DWork.VScontrhl_DSTATE[7];
    xnew[1] += (t15_2_P.VScontrhl_B[2])*t15_2_B.Divide4_c[0] +
      (t15_2_P.VScontrhl_B[3])*t15_2_B.Divide4_c[1];
    xnew[2] = (t15_2_P.VScontrhl_A[8])*t15_2_DWork.VScontrhl_DSTATE[0] +
      (t15_2_P.VScontrhl_A[9])*t15_2_DWork.VScontrhl_DSTATE[1]
      + (t15_2_P.VScontrhl_A[10])*t15_2_DWork.VScontrhl_DSTATE[2]
      + (t15_2_P.VScontrhl_A[11])*t15_2_DWork.VScontrhl_DSTATE[7];
    xnew[2] += (t15_2_P.VScontrhl_B[4])*t15_2_B.Divide4_c[0] +
      (t15_2_P.VScontrhl_B[5])*t15_2_B.Divide4_c[1];

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

    xnew[3] += (t15_2_P.VScontrhl_B[6])*t15_2_B.Divide4_c[0] +
      (t15_2_P.VScontrhl_B[7])*t15_2_B.Divide4_c[1];

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

    xnew[4] += (t15_2_P.VScontrhl_B[8])*t15_2_B.Divide4_c[0] +
      (t15_2_P.VScontrhl_B[9])*t15_2_B.Divide4_c[1];

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

    xnew[5] += (t15_2_P.VScontrhl_B[10])*t15_2_B.Divide4_c[0] +
      (t15_2_P.VScontrhl_B[11])*t15_2_B.Divide4_c[1];

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

    xnew[6] += (t15_2_P.VScontrhl_B[12])*t15_2_B.Divide4_c[0] +
      (t15_2_P.VScontrhl_B[13])*t15_2_B.Divide4_c[1];
    xnew[7] = (t15_2_P.VScontrhl_A[32])*t15_2_DWork.VScontrhl_DSTATE[7];
    xnew[7] += (t15_2_P.VScontrhl_B[14])*t15_2_B.Divide4_c[0];
    (void) memcpy(&t15_2_DWork.VScontrhl_DSTATE[0], xnew,
                  sizeof(real_T)*8);
  }

  /* Update for UnitDelay: '<S6>/UD' */
  t15_2_DWork.UD_DSTATE_p = t15_2_B.Times;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  t15_2_M->Timing.t[0] =
    (++t15_2_M->Timing.clockTick0) * t15_2_M->Timing.stepSize0;
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
  rtsiSetSolverName(&t15_2_M->solverInfo,"FixedStepDiscrete");
  t15_2_M->solverInfoPtr = (&t15_2_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = t15_2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    t15_2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    t15_2_M->Timing.sampleTimes = (&t15_2_M->Timing.sampleTimesArray[0]);
    t15_2_M->Timing.offsetTimes = (&t15_2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    t15_2_M->Timing.sampleTimes[0] = (0.002);

    /* task offsets */
    t15_2_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(t15_2_M, &t15_2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = t15_2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    t15_2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(t15_2_M, -1);
  t15_2_M->Timing.stepSize0 = 0.002;
  t15_2_M->solverInfoPtr = (&t15_2_M->solverInfo);
  t15_2_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&t15_2_M->solverInfo, 0.002);
  rtsiSetSolverMode(&t15_2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &t15_2_B), 0,
                sizeof(BlockIO_t15_2));

  {
    int_T i;
    for (i = 0; i < 6500; i++) {
      t15_2_B.SFunction1[i] = 0.0;
    }

    for (i = 0; i < 10000; i++) {
      t15_2_B.SFunction2[i] = 0.0;
    }

    for (i = 0; i < 17; i++) {
      t15_2_B.SFunction[i] = 0.0;
    }

    for (i = 0; i < 15; i++) {
      t15_2_B.e6_i[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_d[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      t15_2_B.e2[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_m[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_p[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_c[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_o[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_j[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_ce[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_b[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_os[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_cx[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_n[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_i[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_h[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      t15_2_B.e2_f[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.u_i[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.e3_g[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Abs[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.DataStoreRead1_m[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.DataStoreRead2_l[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide5[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum2_c[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide3[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum1[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide4[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_mz[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Saturation[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory1_ds[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory_l[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide2[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u_p[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide13[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Div_rdcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u_fs[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide4_da[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Currtermcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide5_n[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory2_d[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide12_l[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Limcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Currcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.DataStoreRead2_a[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u_g[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide14[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_hz[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_p[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_g[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_e[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_hx[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_e[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_g[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_g[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_i2[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_d[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_e[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_c[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_b[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_o[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_ea[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_p[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_pg[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_jf[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_n[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_gg[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_f3[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_h[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_l[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_dy[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_f[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_d[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_m[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_c[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_b[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_dl[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_m[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_b3[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide7[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum3[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide2_i[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.LogicalOperator_d[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide6_j[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.G_curr_term[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide12_h[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_mzp[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.e6_j[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.DataStoreRead2_f[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide4_j[i] = 0.0;
    }

    for (i = 0; i < 44; i++) {
      t15_2_B.SFunction_j[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.DataStoreRead1_he[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory1_l[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.DataStoreRead1_i0[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u_gb[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_ke[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Add1_b[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide_k[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u_jm[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Switch_b[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Switch2[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_a2[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Add2_d0[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Gain[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Switch_h[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Switch2_j[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.DataStoreRead2_g[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide3_m[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_n2[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide2_k[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Add1_d[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      t15_2_B.TmpSignalConversionAtnpf12Inpor[i] = 0.0;
    }

    for (i = 0; i < 15; i++) {
      t15_2_B.npf12[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide3_n[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_h[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum2_l[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide_j[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u_l[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide_m[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide2_a[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg1_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_a[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_h[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_j[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_d[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector_f[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg6_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_dx[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_b[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_g[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_i[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_b[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector_d[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg5_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_n[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_g[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_k[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_p[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_m[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector_py[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg4_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_h[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_d[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_a[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_b[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_k[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector_e[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg3_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_j[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_p[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_i[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_jj[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_df[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector_n[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg2_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_i[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_h[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_fo[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_o[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_f[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_gh[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_jm[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_dz[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_nv[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_nh[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_i3[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_bc[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_cr[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_ii[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_mc[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_gu[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_hk[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_ey[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_ma[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_os[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_dj[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_pa[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_e0[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_li[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_ay[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_ph[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_ho[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_h[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_a[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_iq[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_df[i] = 0.0;
    }

    t15_2_B.Times = 0.0;
    t15_2_B.Memory2 = 0.0;
    t15_2_B.u = 0.0;
    t15_2_B.Ip1e4 = 0.0;
    t15_2_B.DataStoreRead = 0.0;
    t15_2_B.Sum2 = 0.0;
    t15_2_B.DataStoreRead1 = 0.0;
    t15_2_B.e6 = 0.0;
    t15_2_B.Memory1 = 0.0;
    t15_2_B.DataStoreRead1_k = 0.0;
    t15_2_B.e3 = 0.0;
    t15_2_B.DataStoreRead2 = 0.0;
    t15_2_B.Product1 = 0.0;
    t15_2_B.RelationalOperator = 0.0;
    t15_2_B.Memory = 0.0;
    t15_2_B.LogicalOperator = 0.0;
    t15_2_B.switch1 = 0.0;
    t15_2_B.Add2 = 0.0;
    t15_2_B.DataStoreRead_o = 0.0;
    t15_2_B.Product = 0.0;
    t15_2_B.Add1 = 0.0;
    t15_2_B.u_f = 0.0;
    t15_2_B.Memory1_h = 0.0;
    t15_2_B.c_eob = 0.0;
    t15_2_B.Divide6 = 0.0;
    t15_2_B.Add1_l = 0.0;
    t15_2_B.Memory2_l = 0.0;
    t15_2_B.c_eob1 = 0.0;
    t15_2_B.Memory1_f = 0.0;
    t15_2_B.c_eob_h = 0.0;
    t15_2_B.c_eob_b = 0.0;
    t15_2_B.Add2_f = 0.0;
    t15_2_B.Memory2_k = 0.0;
    t15_2_B.c_eob1_d = 0.0;
    t15_2_B.Memory1_i = 0.0;
    t15_2_B.c_eob_a = 0.0;
    t15_2_B.c_eob_j = 0.0;
    t15_2_B.Add1_j = 0.0;
    t15_2_B.Memory2_n = 0.0;
    t15_2_B.c_eob1_f = 0.0;
    t15_2_B.Memory1_d = 0.0;
    t15_2_B.c_eob_jz = 0.0;
    t15_2_B.c_eob_l = 0.0;
    t15_2_B.Add3 = 0.0;
    t15_2_B.Memory2_g = 0.0;
    t15_2_B.c_eob1_c = 0.0;
    t15_2_B.Memory1_k = 0.0;
    t15_2_B.c_eob_aj = 0.0;
    t15_2_B.c_eob_bl = 0.0;
    t15_2_B.Add4 = 0.0;
    t15_2_B.DataStoreRead_h = 0.0;
    t15_2_B.RelationalOperator1 = 0.0;
    t15_2_B.Divide12 = 0.0;
    t15_2_B.Memory2_h = 0.0;
    t15_2_B.c_eob1_g = 0.0;
    t15_2_B.Memory1_g = 0.0;
    t15_2_B.c_eob_d = 0.0;
    t15_2_B.c_eob_f = 0.0;
    t15_2_B.Add5 = 0.0;
    t15_2_B.Memory2_nz = 0.0;
    t15_2_B.c_eob1_h = 0.0;
    t15_2_B.Memory1_p = 0.0;
    t15_2_B.c_eob_o = 0.0;
    t15_2_B.c_eob_fp = 0.0;
    t15_2_B.Add6 = 0.0;
    t15_2_B.Memory2_ht = 0.0;
    t15_2_B.c_eob_c = 0.0;
    t15_2_B.Divide1 = 0.0;
    t15_2_B.Add3_k = 0.0;
    t15_2_B.Memory2_c = 0.0;
    t15_2_B.c_eob_n = 0.0;
    t15_2_B.Divide1_a = 0.0;
    t15_2_B.Add1_g = 0.0;
    t15_2_B.Memory2_kb = 0.0;
    t15_2_B.c_eob_k = 0.0;
    t15_2_B.Divide1_b = 0.0;
    t15_2_B.Add2_d = 0.0;
    t15_2_B.Memory2_b = 0.0;
    t15_2_B.c_eob_g = 0.0;
    t15_2_B.Divide1_d = 0.0;
    t15_2_B.Add4_d = 0.0;
    t15_2_B.Memory2_bc = 0.0;
    t15_2_B.c_eob_jp = 0.0;
    t15_2_B.Divide1_i = 0.0;
    t15_2_B.Add5_j = 0.0;
    t15_2_B.Memory2_p = 0.0;
    t15_2_B.c_eob_m = 0.0;
    t15_2_B.Divide1_l = 0.0;
    t15_2_B.Add6_e = 0.0;
    t15_2_B.Memory2_a = 0.0;
    t15_2_B.c_eob_cm = 0.0;
    t15_2_B.Divide1_n = 0.0;
    t15_2_B.Add7 = 0.0;
    t15_2_B.Memory2_i = 0.0;
    t15_2_B.c_eob_h3 = 0.0;
    t15_2_B.Divide1_dv = 0.0;
    t15_2_B.Add8 = 0.0;
    t15_2_B.Memory2_bl = 0.0;
    t15_2_B.c_eob_gm = 0.0;
    t15_2_B.Divide1_m = 0.0;
    t15_2_B.Add9 = 0.0;
    t15_2_B.Memory2_i0 = 0.0;
    t15_2_B.c_eob_cn = 0.0;
    t15_2_B.Divide1_aa = 0.0;
    t15_2_B.Add10 = 0.0;
    t15_2_B.Memory2_ai = 0.0;
    t15_2_B.c_eob_cg = 0.0;
    t15_2_B.Divide1_k = 0.0;
    t15_2_B.Add11 = 0.0;
    t15_2_B.DataStoreRead_a = 0.0;
    t15_2_B.RelationalOperator1_e = 0.0;
    t15_2_B.Uk1 = 0.0;
    t15_2_B.Diff = 0.0;
    t15_2_B.Uk1_n = 0.0;
    t15_2_B.Diff_f = 0.0;
    t15_2_B.Divide = 0.0;
    t15_2_B.DataStoreRead_b = 0.0;
    t15_2_B.DataStoreRead1_j = 0.0;
    t15_2_B.Memory3 = 0.0;
    t15_2_B.RelationalOperator1_k = 0.0;
    t15_2_B.switch1_i = 0.0;
    t15_2_B.Subtract2 = 0.0;
    t15_2_B.Divide1_mn = 0.0;
    t15_2_B.Subtract1 = 0.0;
    t15_2_B.Saturation1 = 0.0;
    t15_2_B.DataStoreRead1_kn = 0.0;
    t15_2_B.DataStoreRead_k = 0.0;
    t15_2_B.Abs_l = 0.0;
    t15_2_B.LogicalOperator2 = 0.0;
    t15_2_B.DataStoreRead_d = 0.0;
    t15_2_B.DataStoreRead1_i = 0.0;
    t15_2_B.Abs_j = 0.0;
    t15_2_B.LogicalOperator1 = 0.0;
    t15_2_B.Memory1_j = 0.0;
    t15_2_B.c_eob_i = 0.0;
    t15_2_B.c_eob_ku = 0.0;
    t15_2_B.Memory1_fj = 0.0;
    t15_2_B.DataStoreRead_i = 0.0;
    t15_2_B.LogicalOperator1_f = 0.0;
    t15_2_B.switch1_g = 0.0;
    t15_2_B.DataStoreRead_iz = 0.0;
    t15_2_B.Memory1_n = 0.0;
    t15_2_B.DataStoreRead_f = 0.0;
    t15_2_B.Abs_k = 0.0;
    t15_2_B.LogicalOperator2_i = 0.0;
    t15_2_B.u_j = 0.0;
    t15_2_B.Subtract2_k = 0.0;
    t15_2_B.Divide4_d = 0.0;
    t15_2_B.Subtract3 = 0.0;
    t15_2_B.Saturation_f = 0.0;
    t15_2_B.Subtract1_b = 0.0;
    t15_2_B.DataStoreRead1_h = 0.0;
    t15_2_B.RelationalOperator1_d = 0.0;
    t15_2_B.DataStoreRead_j = 0.0;
    t15_2_B.RelationalOperator_p = 0.0;
    t15_2_B.volt1 = 0.0;
    t15_2_B.volt1_h = 0.0;
    t15_2_B.volt1_g = 0.0;
    t15_2_B.volt1_hk = 0.0;
    t15_2_B.volt1_l = 0.0;
    t15_2_B.volt1_i = 0.0;
    t15_2_B.volt1_n = 0.0;
    t15_2_B.volt1_p = 0.0;
    t15_2_B.volt1_f = 0.0;
    t15_2_B.volt1_c = 0.0;
    t15_2_B.volt1_i1 = 0.0;
    t15_2_B.Subtract4 = 0.0;
    t15_2_B.UniformRandomNumber = 0.0;
    t15_2_B.DataStoreRead_ga = 0.0;
    t15_2_B.u5 = 0.0;
    t15_2_B.Divide11 = 0.0;
    t15_2_B.Uk1_o = 0.0;
    t15_2_B.Diff_b = 0.0;
    t15_2_B.e3_j = 0.0;
    t15_2_B.Sqrt = 0.0;
    t15_2_B.Divide1_bm = 0.0;
    t15_2_B.Sum2_cw = 0.0;
    t15_2_B.DataStoreRead_kg = 0.0;
    t15_2_B.RelationalOperator1_i = 0.0;
    t15_2_B.Divide12_m[0] = 0.0;
    t15_2_B.Divide12_m[1] = 0.0;
    t15_2_B.VScontr[0] = 0.0;
    t15_2_B.VScontr[1] = 0.0;
    t15_2_B.Divide4_c[0] = 0.0;
    t15_2_B.Divide4_c[1] = 0.0;
    t15_2_B.VScontrhl[0] = 0.0;
    t15_2_B.VScontrhl[1] = 0.0;
    t15_2_B.c_eob_gx[0] = 0.0;
    t15_2_B.c_eob_gx[1] = 0.0;
    t15_2_B.DataStoreRead1_n = 0.0;
    t15_2_B.RelationalOperator2 = 0.0;
    t15_2_B.DataStoreRead_ml = 0.0;
    t15_2_B.Abs_c = 0.0;
    t15_2_B.RelationalOperator1_o = 0.0;
    t15_2_B.LogicalOperator1_m = 0.0;
    t15_2_B.DataStoreRead_ae = 0.0;
    t15_2_B.u5_i = 0.0;
    t15_2_B.Div = 0.0;
    t15_2_B.u_d[0] = 0.0;
    t15_2_B.u_d[1] = 0.0;
    t15_2_B.Divide10[0] = 0.0;
    t15_2_B.Divide10[1] = 0.0;
    t15_2_B.DataStoreRead3 = 0.0;
    t15_2_B.Uk1_i = 0.0;
    t15_2_B.Diff_i = 0.0;
    t15_2_B.DataStoreRead1_c = 0.0;
    t15_2_B.Switch2_o = 0.0;
    t15_2_B.DataStoreRead1_hh = 0.0;
    t15_2_B.Divide4_l = 0.0;
    t15_2_B.DataStoreRead3_e = 0.0;
    t15_2_B.Switch2_c = 0.0;
    t15_2_B.Divide5_j = 0.0;
    t15_2_B.Subtract2_c = 0.0;
    t15_2_B.DataStoreRead1_a = 0.0;
    t15_2_B.Divide4_lu = 0.0;
    t15_2_B.Subtract3_b = 0.0;
    t15_2_B.Saturation_p = 0.0;
    t15_2_B.Subtract1_j = 0.0;
    t15_2_B.DataStoreRead_ji = 0.0;
    t15_2_B.u15 = 0.0;
    t15_2_B.Divide6_m = 0.0;
    t15_2_B.Switch2_j5 = 0.0;
    t15_2_B.Divide11_p[0] = 0.0;
    t15_2_B.Divide11_p[1] = 0.0;
    t15_2_B.DataStoreRead3_h = 0.0;
    t15_2_B.Switch_e = 0.0;
    t15_2_B.c_eob_kr[0] = 0.0;
    t15_2_B.c_eob_kr[1] = 0.0;
    t15_2_B.DataStoreRead1_gq = 0.0;
    t15_2_B.RelationalOperator2_m = 0.0;
    t15_2_B.LimDivtr = 0.0;
    t15_2_B.Divide8[0] = 0.0;
    t15_2_B.Divide8[1] = 0.0;
    t15_2_B.SatDiv = 0.0;
    t15_2_B.DataStoreRead2_c = 0.0;
    t15_2_B.Switch2_f = 0.0;
    t15_2_B.Switch_g = 0.0;
    t15_2_B.u5_g = 0.0;
    t15_2_B.Switch2_p = 0.0;
    t15_2_B.Divide_d[0] = 0.0;
    t15_2_B.Divide_d[1] = 0.0;
    t15_2_B.DataStoreRead4 = 0.0;
    t15_2_B.Switch_n = 0.0;
    t15_2_B.Subtract3_i = 0.0;
    t15_2_B.DataStoreRead_p = 0.0;
    t15_2_B.RelationalOperator_i = 0.0;
    t15_2_B.DataStoreRead1_ko = 0.0;
    t15_2_B.DataStoreRead_md = 0.0;
    t15_2_B.Subtract3_e = 0.0;
    t15_2_B.Divide2_o = 0.0;
    t15_2_B.Saturation1_c = 0.0;
    t15_2_B.DataStoreRead2_i = 0.0;
    t15_2_B.u15_j = 0.0;
    t15_2_B.Divide9 = 0.0;
    t15_2_B.Saturation_h = 0.0;
    t15_2_B.DataStoreRead2_j = 0.0;
    t15_2_B.Sum3_p = 0.0;
    t15_2_B.DataStoreRead4_h = 0.0;
    t15_2_B.DataStoreRead3_k = 0.0;
    t15_2_B.Sum2_g = 0.0;
    t15_2_B.Divide1_j = 0.0;
    t15_2_B.Divide6_f = 0.0;
    t15_2_B.Sum = 0.0;
    t15_2_B.Divide2_h = 0.0;
    t15_2_B.Sum1_n = 0.0;
    t15_2_B.Switch2_h = 0.0;
    t15_2_B.Switch_d = 0.0;
    t15_2_B.DataStoreRead1_en = 0.0;
    t15_2_B.DataStoreRead_n = 0.0;
    t15_2_B.g1_termref = 0.0;
    t15_2_B.g1ref = 0.0;
    t15_2_B.DataStoreRead1_f = 0.0;
    t15_2_B.DataStoreRead_jr = 0.0;
    t15_2_B.g6_termref = 0.0;
    t15_2_B.g6ref = 0.0;
    t15_2_B.DataStoreRead1_am = 0.0;
    t15_2_B.DataStoreRead_jrb = 0.0;
    t15_2_B.g5_termref = 0.0;
    t15_2_B.g5ref = 0.0;
    t15_2_B.DataStoreRead1_jh = 0.0;
    t15_2_B.DataStoreRead_bn = 0.0;
    t15_2_B.g4_termref = 0.0;
    t15_2_B.g4ref = 0.0;
    t15_2_B.DataStoreRead1_er = 0.0;
    t15_2_B.DataStoreRead_ar = 0.0;
    t15_2_B.g3_termref = 0.0;
    t15_2_B.g3ref = 0.0;
    t15_2_B.DataStoreRead1_hn = 0.0;
    t15_2_B.DataStoreRead_jp = 0.0;
    t15_2_B.g2_termref = 0.0;
    t15_2_B.g2ref = 0.0;
    t15_2_B.I1 = 0.0;
    t15_2_B.I1_j = 0.0;
    t15_2_B.I1_i = 0.0;
    t15_2_B.I1_m = 0.0;
    t15_2_B.I1_d = 0.0;
    t15_2_B.I1_n = 0.0;
    t15_2_B.I1_a = 0.0;
    t15_2_B.I1_p = 0.0;
    t15_2_B.I1_e = 0.0;
    t15_2_B.I1_o = 0.0;
    t15_2_B.I1_b = 0.0;
    t15_2_B.elong = 0.0;
    t15_2_B.Add2_gh = 0.0;
    t15_2_B.DataStoreRead1_jm = 0.0;
    t15_2_B.Divide_h[0] = 0.0;
    t15_2_B.Divide_h[1] = 0.0;
    t15_2_B.Divide_h[2] = 0.0;
    t15_2_B.Divide_h[3] = 0.0;
    t15_2_B.Ipref = 0.0;
    t15_2_B.Gain1 = 0.0;
    t15_2_B.Switch_l = 0.0;
    t15_2_B.Gain_g = 0.0;
    t15_2_B.Switch_dy = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&t15_2_DWork, 0,
                sizeof(D_Work_t15_2));
  t15_2_DWork.UD_DSTATE = 0.0;
  t15_2_DWork.UD_DSTATE_c = 0.0;

  {
    int_T i;
    for (i = 0; i < 32; i++) {
      t15_2_DWork.Divcontr_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 22; i++) {
      t15_2_DWork.Div_rdcontr_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 22; i++) {
      t15_2_DWork.Currtermcontr_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 46; i++) {
      t15_2_DWork.Limcontr_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Currcontr_DSTATE[i] = 0.0;
    }
  }

  t15_2_DWork.UD_DSTATE_o = 0.0;

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

  t15_2_DWork.UD_DSTATE_p = 0.0;
  t15_2_DWork.Memory2_PreviousInput = 0.0;
  t15_2_DWork.Memory1_PreviousInput = 0.0;
  t15_2_DWork.Memory_PreviousInput = 0.0;
  t15_2_DWork.Memory1_PreviousInput_p = 0.0;
  t15_2_DWork.Memory2_PreviousInput_h = 0.0;
  t15_2_DWork.Memory1_PreviousInput_k = 0.0;
  t15_2_DWork.Memory2_PreviousInput_o = 0.0;
  t15_2_DWork.Memory1_PreviousInput_d = 0.0;
  t15_2_DWork.Memory2_PreviousInput_j = 0.0;
  t15_2_DWork.Memory1_PreviousInput_m = 0.0;
  t15_2_DWork.Memory2_PreviousInput_e = 0.0;
  t15_2_DWork.Memory1_PreviousInput_py = 0.0;
  t15_2_DWork.Memory2_PreviousInput_k = 0.0;
  t15_2_DWork.Memory1_PreviousInput_h = 0.0;
  t15_2_DWork.Memory2_PreviousInput_n = 0.0;
  t15_2_DWork.Memory1_PreviousInput_g = 0.0;
  t15_2_DWork.Memory2_PreviousInput_b = 0.0;
  t15_2_DWork.Memory2_PreviousInput_bu = 0.0;
  t15_2_DWork.Memory2_PreviousInput_op = 0.0;
  t15_2_DWork.Memory2_PreviousInput_f = 0.0;
  t15_2_DWork.Memory2_PreviousInput_hg = 0.0;
  t15_2_DWork.Memory2_PreviousInput_g = 0.0;
  t15_2_DWork.Memory2_PreviousInput_c = 0.0;
  t15_2_DWork.Memory2_PreviousInput_jv = 0.0;
  t15_2_DWork.Memory2_PreviousInput_hu = 0.0;
  t15_2_DWork.Memory2_PreviousInput_g2 = 0.0;
  t15_2_DWork.Memory2_PreviousInput_b1 = 0.0;
  t15_2_DWork.Memory3_PreviousInput = 0.0;

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory1_PreviousInput_c[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory_PreviousInput_j[i] = 0.0;
    }
  }

  t15_2_DWork.Memory1_PreviousInput_i = 0.0;
  t15_2_DWork.Memory1_PreviousInput_ic = 0.0;
  t15_2_DWork.Memory1_PreviousInput_gz = 0.0;

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory2_PreviousInput_cm[i] = 0.0;
    }
  }

  t15_2_DWork.UniformRandomNumber_NextOutput = 0.0;

  {
    int_T i;
    for (i = 0; i < 6500; i++) {
      t15_2_DWork.scr_data[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10000; i++) {
      t15_2_DWork.volt[i] = 0.0;
    }
  }

  t15_2_DWork.c_a_tpl1_eob = 0.0;
  t15_2_DWork.c_a_tpl2 = 0.0;
  t15_2_DWork.c_a_tpl_min = 0.0;
  t15_2_DWork.y0 = 0.0;
  t15_2_DWork.c1_y0 = 0.0;
  t15_2_DWork.c2_y0 = 0.0;
  t15_2_DWork.t_tran2D = 0.0;
  t15_2_DWork.max_VS_lim = 0.0;
  t15_2_DWork.k_g4 = 0.0;
  t15_2_DWork.c_a_tpl1 = 0.0;
  t15_2_DWork.tcont2 = 0.0;
  t15_2_DWork.Ip_div = 0.0;
  t15_2_DWork.ref_ramp = 0.0;
  t15_2_DWork.dtcont2 = 0.0;
  t15_2_DWork.Ip_rd = 0.0;
  t15_2_DWork.trd_ref = 0.0;
  t15_2_DWork.Time_stop = 0.0;

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory1_PreviousInput_i1[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 12; i++) {
      t15_2_DWork.ntur[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      t15_2_DWork.RupRd[i] = 0.0;
    }
  }

  t15_2_DWork.VS3_up = 0.0;

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Vcspf_up[i] = 0.0;
    }
  }

  t15_2_DWork.VS1_up = 0.0;
  t15_2_DWork.Tu = 0.0;
  t15_2_DWork.c_cur_max = 0.0;

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Imax[i] = 0.0;
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
      t15_2_Y.to_DINA[i] = 0.0;
    }
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &t15_2_M->NonInlinedSFcns.sfcnInfo;
    t15_2_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, ((const char_T **)(&rtmGetErrorStatus
      (t15_2_M))));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &t15_2_M->Sizes.numSampTimes);
    t15_2_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(t15_2_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,t15_2_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(t15_2_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(t15_2_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(t15_2_M));
    rtssSetStepSizePtr(sfcnInfo, &t15_2_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(t15_2_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &t15_2_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &t15_2_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &t15_2_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &t15_2_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &t15_2_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &t15_2_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &t15_2_M->solverInfoPtr);
  }

  t15_2_M->Sizes.numSFcns = (17);

  /* register each child */
  {
    (void) memset((void *)&t15_2_M->NonInlinedSFcns.childSFunctions[0], 0,
                  17*sizeof(SimStruct));
    t15_2_M->childSfunctions = (&t15_2_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 17; i++) {
        t15_2_M->childSfunctions[i] = (&t15_2_M->
          NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: t15_2/<S5>/S-Function1 (pf_lookup3) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn0.oDims0;
          dimensions[0] = 13;
          dimensions[1] = 500;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 6500);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts, "t15_2/Pow. Supply MC 2/kavin_contr/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size);
      }

      /* registration */
      pf_lookup3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S5>/S-Function2 (read_volt) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn1.oDims0;
          dimensions[0] = 20;
          dimensions[1] = 500;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 10000);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction2));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function2");
      ssSetPath(rts, "t15_2/Pow. Supply MC 2/kavin_contr/S-Function2");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction2_P1_Size);
      }

      /* registration */
      read_volt(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S5>/S-Function (read_control_data2) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 17);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "t15_2/Pow. Supply MC 2/kavin_contr/S-Function");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      read_control_data2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S21>/S-Function1 (read_gaps) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn3.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_d));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/elong_ref.dat/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_j);
      }

      /* registration */
      read_gaps(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S44>/S-Function1 (read_gaps) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn4.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_m));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem6/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_a);
      }

      /* registration */
      read_gaps(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S50>/S-Function1 (read_gaps_term) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn5.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_p));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem6/g1_term,ref/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_g);
      }

      /* registration */
      read_gaps_term(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S39>/S-Function1 (read_gaps) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn6.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_c));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem1/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_o);
      }

      /* registration */
      read_gaps(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S45>/S-Function1 (read_gaps_term) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn7.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_o));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem1/g2_term,ref/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_p);
      }

      /* registration */
      read_gaps_term(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S40>/S-Function1 (read_gaps) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn8.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_j));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem2/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_c);
      }

      /* registration */
      read_gaps(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S46>/S-Function1 (read_gaps_term) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[9]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn9.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_ce));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem2/g3_term,ref/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_j1);
      }

      /* registration */
      read_gaps_term(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S41>/S-Function1 (read_gaps) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[10]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[10]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[10]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn10.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_b));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem3/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_cj);
      }

      /* registration */
      read_gaps(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S47>/S-Function1 (read_gaps_term) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[11]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[11]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[11]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn11.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_os));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem3/g4_term,ref/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_e);
      }

      /* registration */
      read_gaps_term(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S42>/S-Function1 (read_gaps) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[12]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[12]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[12]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn12.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn12.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_cx));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem4/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_m);
      }

      /* registration */
      read_gaps(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S48>/S-Function1 (read_gaps_term) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[13]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[13]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[13]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[13]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn13.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn13.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_n));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem4/g5_term,ref/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_i);
      }

      /* registration */
      read_gaps_term(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S43>/S-Function1 (read_gaps) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[14];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn14.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn14.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn14.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[14]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[14]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[14]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[14]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn14.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn14.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_i));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem5/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_cq);
      }

      /* registration */
      read_gaps(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S49>/S-Function1 (read_gaps_term) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[15];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn15.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn15.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn15.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[15]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[15]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[15]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[15]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn15.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn15.oDims0;
          dimensions[0] = 2;
          dimensions[1] = 50;
          _ssSetOutputPortDimensionsPtr(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidth(rts, 0, 100);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_h));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/g1-g6.dat,g1_term-g6_term.dat/Subsystem5/g6_term,ref/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn15.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_ca);
      }

      /* registration */
      read_gaps_term(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: t15_2/<S1>/S-Function (read_tt_kavin2) */
    {
      SimStruct *rts = t15_2_M->childSfunctions[16];

      /* timing info */
      time_T *sfcnPeriod = t15_2_M->NonInlinedSFcns.Sfcn16.sfcnPeriod;
      time_T *sfcnOffset = t15_2_M->NonInlinedSFcns.Sfcn16.sfcnOffset;
      int_T *sfcnTsMap = t15_2_M->NonInlinedSFcns.Sfcn16.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &t15_2_M->NonInlinedSFcns.blkInfo2[16]);
      }

      ssSetRTWSfcnInfo(rts, t15_2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &t15_2_M->NonInlinedSFcns.methods2[16]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &t15_2_M->NonInlinedSFcns.methods3[16]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &t15_2_M->NonInlinedSFcns.statesInfo2[16]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &t15_2_M->NonInlinedSFcns.Sfcn16.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 44);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction_j));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "t15_2/Pow. Supply MC 2/S-Function");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      read_tt_kavin2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmin;

    /* Start for UniformRandomNumber: '<S62>/Uniform Random Number' */
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

    /* End of Start for UniformRandomNumber: '<S62>/Uniform Random Number' */

    /* Start for DataStoreMemory: '<S5>/Data Store Memory' */
    memcpy(&t15_2_DWork.scr_data[0], &t15_2_P.DataStoreMemory_InitialValue[0],
           6500U * sizeof(real_T));

    /* Start for DataStoreMemory: '<S5>/Data Store Memory1' */
    memcpy(&t15_2_DWork.volt[0], &t15_2_P.DataStoreMemory1_InitialValue[0],
           10000U * sizeof(real_T));

    /* Start for DataStoreMemory: '<S5>/Data Store Memory10' */
    t15_2_DWork.c_a_tpl1_eob = t15_2_P.DataStoreMemory10_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory11' */
    t15_2_DWork.c_a_tpl2 = t15_2_P.DataStoreMemory11_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory12' */
    t15_2_DWork.c_a_tpl_min = t15_2_P.DataStoreMemory12_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory13' */
    t15_2_DWork.y0 = t15_2_P.DataStoreMemory13_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory14' */
    t15_2_DWork.c1_y0 = t15_2_P.DataStoreMemory14_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory15' */
    t15_2_DWork.c2_y0 = t15_2_P.DataStoreMemory15_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory16' */
    t15_2_DWork.t_tran2D = t15_2_P.DataStoreMemory16_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory17' */
    t15_2_DWork.max_VS_lim = t15_2_P.DataStoreMemory17_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory18' */
    t15_2_DWork.k_g4 = t15_2_P.DataStoreMemory18_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory2' */
    t15_2_DWork.c_a_tpl1 = t15_2_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory3' */
    t15_2_DWork.tcont2 = t15_2_P.DataStoreMemory3_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory4' */
    t15_2_DWork.Ip_div = t15_2_P.DataStoreMemory4_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory5' */
    t15_2_DWork.ref_ramp = t15_2_P.DataStoreMemory5_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory6' */
    t15_2_DWork.dtcont2 = t15_2_P.DataStoreMemory6_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory7' */
    t15_2_DWork.Ip_rd = t15_2_P.DataStoreMemory7_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory8' */
    t15_2_DWork.trd_ref = t15_2_P.DataStoreMemory8_InitialValue;

    /* Start for DataStoreMemory: '<S5>/Data Store Memory9' */
    t15_2_DWork.Time_stop = t15_2_P.DataStoreMemory9_InitialValue;

    /* Start for DataStoreMemory: '<S1>/Data Store Memory1' */
    memcpy(&t15_2_DWork.ntur[0], &t15_2_P.DataStoreMemory1_InitialValue_n[0],
           12U * sizeof(real_T));

    /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
    for (r = 0; r < 6; r++) {
      t15_2_DWork.RupRd[r] = t15_2_P.DataStoreMemory2_InitialValue_i[r];
    }

    /* End of Start for DataStoreMemory: '<S1>/Data Store Memory2' */

    /* Start for DataStoreMemory: '<S1>/Data Store Memory3' */
    t15_2_DWork.VS3_up = t15_2_P.DataStoreMemory3_InitialValue_d;

    /* Start for DataStoreMemory: '<S1>/Data Store Memory5' */
    t15_2_DWork.VS1_up = t15_2_P.DataStoreMemory5_InitialValue_m;

    /* Start for DataStoreMemory: '<S1>/Data Store Memory7' */
    t15_2_DWork.Tu = t15_2_P.DataStoreMemory7_InitialValue_d;

    /* Start for DataStoreMemory: '<S1>/Data Store Memory8' */
    t15_2_DWork.c_cur_max = t15_2_P.DataStoreMemory8_InitialValue_k;
    for (r = 0; r < 11; r++) {
      /* Start for DataStoreMemory: '<S1>/Data Store Memory4' */
      t15_2_DWork.Vcspf_up[r] = t15_2_P.DataStoreMemory4_InitialValue_p[r];

      /* Start for DataStoreMemory: '<S1>/Data Store Memory9' */
      t15_2_DWork.Imax[r] = t15_2_P.DataStoreMemory9_InitialValue_j[r];
    }
  }

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S5>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput = t15_2_P.Memory2_X0;

    /* InitializeConditions for Memory: '<S17>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput = t15_2_P.Memory1_X0;

    /* InitializeConditions for Memory: '<S25>/Memory' */
    t15_2_DWork.Memory_PreviousInput = t15_2_P.Memory_X0;

    /* InitializeConditions for Memory: '<S18>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_p = t15_2_P.Memory1_X0_f;

    /* InitializeConditions for Memory: '<S44>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_h = t15_2_P.Memory2_X0_g;

    /* InitializeConditions for Memory: '<S44>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_k = t15_2_P.Memory1_X0_h;

    /* InitializeConditions for Memory: '<S39>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_o = t15_2_P.Memory2_X0_go;

    /* InitializeConditions for Memory: '<S39>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_d = t15_2_P.Memory1_X0_fd;

    /* InitializeConditions for Memory: '<S40>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_j = t15_2_P.Memory2_X0_b;

    /* InitializeConditions for Memory: '<S40>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_m = t15_2_P.Memory1_X0_k;

    /* InitializeConditions for Memory: '<S41>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_e = t15_2_P.Memory2_X0_j;

    /* InitializeConditions for Memory: '<S41>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_py = t15_2_P.Memory1_X0_e;

    /* InitializeConditions for Memory: '<S42>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_k = t15_2_P.Memory2_X0_h;

    /* InitializeConditions for Memory: '<S42>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_h = t15_2_P.Memory1_X0_c;

    /* InitializeConditions for Memory: '<S43>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_n = t15_2_P.Memory2_X0_hw;

    /* InitializeConditions for Memory: '<S43>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_g = t15_2_P.Memory1_X0_n;

    /* InitializeConditions for Memory: '<S28>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_b = t15_2_P.Memory2_X0_c;

    /* InitializeConditions for Memory: '<S31>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_bu = t15_2_P.Memory2_X0_d;

    /* InitializeConditions for Memory: '<S32>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_op = t15_2_P.Memory2_X0_bb;

    /* InitializeConditions for Memory: '<S33>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_f = t15_2_P.Memory2_X0_f;

    /* InitializeConditions for Memory: '<S34>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_hg = t15_2_P.Memory2_X0_fe;

    /* InitializeConditions for Memory: '<S35>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_g = t15_2_P.Memory2_X0_bm;

    /* InitializeConditions for Memory: '<S36>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_c = t15_2_P.Memory2_X0_hs;

    /* InitializeConditions for Memory: '<S37>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_jv = t15_2_P.Memory2_X0_n;

    /* InitializeConditions for Memory: '<S38>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_hu = t15_2_P.Memory2_X0_a;

    /* InitializeConditions for Memory: '<S29>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_g2 = t15_2_P.Memory2_X0_e;

    /* InitializeConditions for Memory: '<S30>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_b1 = t15_2_P.Memory2_X0_ev;

    /* InitializeConditions for UnitDelay: '<S26>/UD' */
    t15_2_DWork.UD_DSTATE = t15_2_P.UD_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S27>/UD' */
    t15_2_DWork.UD_DSTATE_c = t15_2_P.UD_InitialCondition_b;

    /* InitializeConditions for Memory: '<S51>/Memory3' */
    t15_2_DWork.Memory3_PreviousInput = t15_2_P.Memory3_X0;

    /* InitializeConditions for Memory: '<S63>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_i = t15_2_P.Memory1_X0_ef;

    /* InitializeConditions for DiscreteStateSpace: '<S15>/Div. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Divcontr_DSTATE[0];
      for (i1=0; i1 < 32; i1++) {
        dw_DSTATE[i1] = t15_2_P.Divcontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S61>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_ic = t15_2_P.Memory1_X0_d;

    /* InitializeConditions for DiscreteStateSpace: '<S15>/Div_rd contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Div_rdcontr_DSTATE[0];
      for (i1=0; i1 < 22; i1++) {
        dw_DSTATE[i1] = t15_2_P.Div_rdcontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S53>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_gz = t15_2_P.Memory1_X0_a;

    /* InitializeConditions for DiscreteStateSpace: '<S15>/Curr. term. contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Currtermcontr_DSTATE[0];
      for (i1=0; i1 < 22; i1++) {
        dw_DSTATE[i1] = t15_2_P.Currtermcontr_X0;
      }
    }

    /* InitializeConditions for DiscreteStateSpace: '<S54>/Lim. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Limcontr_DSTATE[0];
      for (i1=0; i1 < 46; i1++) {
        dw_DSTATE[i1] = t15_2_P.Limcontr_X0;
      }
    }

    /* InitializeConditions for DiscreteStateSpace: '<S54>/Curr. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Currcontr_DSTATE[0];
      for (i1=0; i1 < 11; i1++) {
        dw_DSTATE[i1] = t15_2_P.Currcontr_X0;
      }
    }

    /* InitializeConditions for UnitDelay: '<S80>/UD' */
    t15_2_DWork.UD_DSTATE_o = t15_2_P.UD_InitialCondition_g;

    /* InitializeConditions for DiscreteStateSpace: '<S59>/VS. contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.VScontr_DSTATE[0];
      for (i1=0; i1 < 9; i1++) {
        dw_DSTATE[i1] = t15_2_P.VScontr_X0;
      }
    }

    /* InitializeConditions for DiscreteStateSpace: '<S59>/VS. contr hl' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.VScontrhl_DSTATE[0];
      for (i1=0; i1 < 8; i1++) {
        dw_DSTATE[i1] = t15_2_P.VScontrhl_X0;
      }
    }

    for (i = 0; i < 11; i++) {
      /* InitializeConditions for Memory: '<S65>/Memory1' */
      t15_2_DWork.Memory1_PreviousInput_c[i] = t15_2_P.Memory1_X0_fk;

      /* InitializeConditions for Memory: '<S57>/Memory' */
      t15_2_DWork.Memory_PreviousInput_j[i] = t15_2_P.Memory_X0_p;

      /* InitializeConditions for Memory: '<S73>/Memory2' */
      t15_2_DWork.Memory2_PreviousInput_cm[i] = t15_2_P.Memory2_X0_gp;

      /* InitializeConditions for Memory: '<S7>/Memory1' */
      t15_2_DWork.Memory1_PreviousInput_i1[i] = t15_2_P.Memory1_X0_ai;
    }

    /* InitializeConditions for UnitDelay: '<S6>/UD' */
    t15_2_DWork.UD_DSTATE_p = t15_2_P.UD_InitialCondition_p;
  }
}

/* Model terminate function */
void t15_2_terminate(void)
{
  /* Level2 S-Function Block: '<S5>/S-Function1' (pf_lookup3) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/S-Function2' (read_volt) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/S-Function' (read_control_data2) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S21>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S44>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S50>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S39>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S45>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S40>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S46>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S41>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S47>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S42>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S48>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S43>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[14];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S49>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[15];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/S-Function' (read_tt_kavin2) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[16];
    sfcnTerminate(rts);
  }
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
if( kpr == -1){
	printf("k  ki %d %d  \n",k,ki);}

	
	for (i = 0; i < 123; i++)
	{ t15_2_U.In2[i] = input[i+ki];
	  k=k+1;
    }
    ki=k;

if( kpr ==- 1){
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


//	  printf("---t15_2_step  \n");



  /* external outputs */
  //real_T Out1[15];
  	  k=0;

      for (i = 0; i < 15; i++) 
	  { output[i]=t15_2_Y.to_DINA[i] ;
	  k=k+1;
      }
	  
	  ki=k;

      for (i = 0; i < 11; i++) 
//	  { output[i+ki]=t15_2_B.Saturation[i] ;
//	  { output[i+ki]=t15_2_DWork.Vcspf_up[i] ;

	  { output[i+ki]=0.0 ;
	  k=k+1;
      }

//t15_2_B.Saturation6[i] + t15_2_B.SaturationVS[i];

	  ki=k;

      for (i = 0; i < 11; i++) 
//	  { output[i+ki]=t15_2_B.wz[i] ;
	  { output[i+ki]=0.0 ;
	  k=k+1;
      }

	  i=11;
//	  output[i+ki]=t15_2_B.wz[i] ;
	  output[i+ki]=0.0 ;

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
