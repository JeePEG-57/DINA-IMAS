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
 * Model version                  : 1.1143
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Mon May 20 13:51:36 2019
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
//extern FILE*f;
FILE*f;
FILE*f1;
FILE*prob;
FILE*f2;

#include <stdlib.h>
#include <string.h>
//#include <Windows.h>


#include "t15_2.h"
#include "t15_2_private.h"

#define nmax 9997
#define kf 15
#define mexPrintf printf

	struct t15_mem1
{
	  double tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref,c_a_tpl1,c_a_tpl1_eob;
      double c_a_tpl2,c_a_tpl_min,y0,t_tran2d,c1_y0,c2_y0,g2_ramp;
};

	  struct t15_mem1 mem1;

	struct t15_mem2
{
int N; double y[500][20];
int k_time; 
};

	  struct t15_mem2 mem2;

struct t15_mem3
{
int N[7];
double y_0[50][2],y1[50][2],y2[50][2],y3[50][2],y4[50][2],y5[50][2],y6[50][2];
};

	  struct t15_mem3 mem3;





struct t15_mem4
{
int N[7];
double y_1[50][2],y_2[50][2],y_3[50][2],y_4[50][2],y_5[50][2],y_6[50][2];
};

struct t15_mem4 mem4;

struct t15_mem5
{
double y[25];
};

	  struct t15_mem5 mem5;

	  struct t15_mem6
{
	int kmax;
	double pf[nmax][kf];
	double t[nmax],tpl[nmax];
};

	  struct t15_mem6 mem6;
struct t15_mem7
{
double y[25];
};

	  struct t15_mem7 mem7;

struct t15_mem8
{
int npf;
double ntur[15];
};

	  struct t15_mem8 mem8;



extern read_general_data(void);
extern void read_tt_kavin2_data(void);

int kpr =1;


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

  /* Gain: '<S5>/1e-3' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_B.e3 = t15_2_P.e3_Gain_p * t15_2_U.In1[8];

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
    t15_2_B.Ip1e4 = t15_2_B.e3;
  }

  /* End of Switch: '<S5>/Ip<1e-4 ' */

  /* DataStoreRead: '<S5>/Data Store Read' */
  t15_2_B.DataStoreRead = t15_2_DWork.RupRd[3];

  /* Sum: '<S5>/Sum2' */
  t15_2_B.Sum2 = t15_2_B.Ip1e4 + t15_2_B.DataStoreRead;

  /* RelationalOperator: '<S5>/Relational Operator' */
  t15_2_B.RelationalOperator_n = (t15_2_B.e3 >= t15_2_B.Sum2);

  /* Stop: '<S5>/Stop Simulation' */
  if (t15_2_B.RelationalOperator_n) {
    rtmSetStopRequested(t15_2_M, 1);
  }

  /* End of Stop: '<S5>/Stop Simulation' */

  /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
   *  Constant: '<S5>/Time_stop'
   */
  t15_2_B.RelationalOperator1 = (t15_2_B.e3 >= t15_2_P.Time_stop_Value);

  /* Stop: '<S5>/Stop Simulation1' */
  if (t15_2_B.RelationalOperator1) {
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
    t15_2_B.e6_m[i] = t15_2_U.In2[i + 6] * t15_2_P.e6_Gain_c;
  }

  /* End of Gain: '<S14>/1e-6   ' */

  /* Memory: '<S23>/Memory2' */
  t15_2_B.Memory2_k = t15_2_DWork.Memory2_PreviousInput_k;

  /* Sum: '<S23>/Add3' */
  t15_2_B.Add3 = t15_2_B.e6_m[2] + t15_2_B.Memory2_k;

  /* DataStoreRead: '<S23>/Data Store Read1' */
  t15_2_B.DataStoreRead1 = t15_2_DWork.RupRd[4];

  /* Gain: '<S23>/1e-3' */
  t15_2_B.e3_k = t15_2_P.e3_Gain_m * t15_2_B.DataStoreRead1;

  /* Product: '<S23>/Product1' incorporates:
   *  Constant: '<S23>/ntur(3)'
   */
  t15_2_B.Product1 = t15_2_B.e3_k * t15_2_P.ntur3_Value;

  /* RelationalOperator: '<S23>/Relational Operator' */
  t15_2_B.RelationalOperator = (t15_2_B.Add3 > t15_2_B.Product1);

  /* Memory: '<S23>/Memory1' */
  t15_2_B.Memory1 = t15_2_DWork.Memory1_PreviousInput;

  /* Switch: '<S23>/0.999' */
  if (t15_2_B.RelationalOperator >= t15_2_P.u99_Threshold) {
    t15_2_B.u99 = t15_2_B.e3;
  } else {
    t15_2_B.u99 = t15_2_B.Memory1;
  }

  /* End of Switch: '<S23>/0.999' */

  /* Sum: '<S23>/Add2' */
  t15_2_B.Add2 = t15_2_B.u99 - t15_2_B.e3;

  /* DataStoreRead: '<S23>/Data Store Read' */
  t15_2_B.DataStoreRead_o = t15_2_DWork.RupRd[1];

  /* Product: '<S23>/Product' */
  t15_2_B.Product = t15_2_B.Add2 / t15_2_B.DataStoreRead_o;

  /* Sum: '<S23>/Add1' incorporates:
   *  Constant: '<S23>/Constant4'
   */
  t15_2_B.Add1 = t15_2_B.Product + t15_2_P.Constant4_Value;

  /* Saturate: '<S23>/1 0' */
  tmin = t15_2_B.Add1;
  u = t15_2_P.u_LowerSat;
  u_0 = t15_2_P.u_UpperSat;
  if (tmin >= u_0) {
    t15_2_B.u_n = u_0;
  } else if (tmin <= u) {
    t15_2_B.u_n = u;
  } else {
    t15_2_B.u_n = tmin;
  }

  /* End of Saturate: '<S23>/1 0' */

  /* Memory: '<S17>/Memory1' */
  t15_2_B.Memory1_j = t15_2_DWork.Memory1_PreviousInput_c;

  /* Switch: '<S17>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_g) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S17>/Data Store Read1' */
      t15_2_B.DataStoreRead1_d5[i] = t15_2_DWork.scr_data[13 * i + 1];

      /* DataStoreRead: '<S17>/Data Store Read' */
      t15_2_B.DataStoreRead_h4[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S17>/Ipref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.Ipref_h), &t15_2_B.DataStoreRead1_d5[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_h4[0], 499U);
    t15_2_B.c_eob = t15_2_B.Ipref_h;
  } else {
    t15_2_B.c_eob = t15_2_B.Memory1_j;
  }

  /* End of Switch: '<S17>/c_eob' */

  /* Product: '<S17>/Divide6' */
  t15_2_B.Divide6 = t15_2_B.c_eob * t15_2_B.u_n;

  /* Sum: '<S14>/Add1' */
  t15_2_B.Add1_i = t15_2_B.e6 - t15_2_B.Divide6;

  /* Level2 S-Function Block: '<S19>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* UnitDelay: '<S24>/UD' */
  t15_2_B.Uk1 = t15_2_DWork.UD_DSTATE;

  /* UnitDelay: '<S25>/UD' */
  t15_2_B.Uk1_d = t15_2_DWork.UD_DSTATE_j;

  /* Memory: '<S29>/Memory2' */
  t15_2_B.Memory2_f = t15_2_DWork.Memory2_PreviousInput_m;

  /* Switch: '<S29>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_ix) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S29>/Data Store Read1' */
      t15_2_B.DataStoreRead1_c3[i] = t15_2_DWork.scr_data[13 * i + 3];

      /* DataStoreRead: '<S29>/Data Store Read' */
      t15_2_B.DataStoreRead_nu[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S29>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_ib), &t15_2_B.DataStoreRead1_c3[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_nu[0], 499U);
    t15_2_B.c_eob_b = t15_2_B.I1_ib;
  } else {
    t15_2_B.c_eob_b = t15_2_B.Memory2_f;
  }

  /* End of Switch: '<S29>/c_eob' */

  /* Product: '<S29>/Divide1' */
  t15_2_B.Divide1 = t15_2_B.c_eob_b * t15_2_B.u_n;

  /* Sum: '<S20>/Add1' */
  t15_2_B.Add1_g = t15_2_B.e6_m[1] - t15_2_B.Divide1;

  /* Memory: '<S27>/Memory2' */
  t15_2_B.Memory2_k5 = t15_2_DWork.Memory2_PreviousInput_b;

  /* Switch: '<S27>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_o) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S27>/Data Store Read1' */
      t15_2_B.DataStoreRead1_pde[i] = t15_2_DWork.scr_data[13 * i + 11];

      /* DataStoreRead: '<S27>/Data Store Read' */
      t15_2_B.DataStoreRead_ld[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S27>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_d), &t15_2_B.DataStoreRead1_pde[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_ld[0], 499U);
    t15_2_B.c_eob_c = t15_2_B.I1_d;
  } else {
    t15_2_B.c_eob_c = t15_2_B.Memory2_k5;
  }

  /* End of Switch: '<S27>/c_eob' */

  /* Product: '<S27>/Divide1' */
  t15_2_B.Divide1_o = t15_2_B.c_eob_c * t15_2_B.u_n;

  /* Sum: '<S20>/Add10' */
  t15_2_B.Add10 = t15_2_B.e6_m[9] - t15_2_B.Divide1_o;

  /* Memory: '<S28>/Memory2' */
  t15_2_B.Memory2_kw = t15_2_DWork.Memory2_PreviousInput_a;

  /* Switch: '<S28>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_e) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S28>/Data Store Read1' */
      t15_2_B.DataStoreRead1_nq[i] = t15_2_DWork.scr_data[13 * i + 12];

      /* DataStoreRead: '<S28>/Data Store Read' */
      t15_2_B.DataStoreRead_eq[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S28>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_jq), &t15_2_B.DataStoreRead1_nq[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_eq[0], 499U);
    t15_2_B.c_eob_h = t15_2_B.I1_jq;
  } else {
    t15_2_B.c_eob_h = t15_2_B.Memory2_kw;
  }

  /* End of Switch: '<S28>/c_eob' */

  /* Product: '<S28>/Divide1' */
  t15_2_B.Divide1_n = t15_2_B.c_eob_h * t15_2_B.u_n;

  /* Sum: '<S20>/Add11' */
  t15_2_B.Add11 = t15_2_B.e6_m[10] - t15_2_B.Divide1_n;

  /* Memory: '<S30>/Memory2' */
  t15_2_B.Memory2_o = t15_2_DWork.Memory2_PreviousInput_d;

  /* Switch: '<S30>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_o0) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S30>/Data Store Read1' */
      t15_2_B.DataStoreRead1_a[i] = t15_2_DWork.scr_data[13 * i + 4];

      /* DataStoreRead: '<S30>/Data Store Read' */
      t15_2_B.DataStoreRead_lz[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S30>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_e), &t15_2_B.DataStoreRead1_a[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_lz[0], 499U);
    t15_2_B.c_eob_e = t15_2_B.I1_e;
  } else {
    t15_2_B.c_eob_e = t15_2_B.Memory2_o;
  }

  /* End of Switch: '<S30>/c_eob' */

  /* Product: '<S30>/Divide1' */
  t15_2_B.Divide1_h = t15_2_B.c_eob_e * t15_2_B.u_n;

  /* Sum: '<S20>/Add2' */
  t15_2_B.Add2_o = t15_2_B.e6_m[2] - t15_2_B.Divide1_h;

  /* Memory: '<S26>/Memory2' */
  t15_2_B.Memory2_b = t15_2_DWork.Memory2_PreviousInput_c;

  /* Switch: '<S26>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_e2) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S26>/Data Store Read1' */
      t15_2_B.DataStoreRead1_dg[i] = t15_2_DWork.scr_data[13 * i + 2];

      /* DataStoreRead: '<S26>/Data Store Read' */
      t15_2_B.DataStoreRead_ft[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S26>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_o), &t15_2_B.DataStoreRead1_dg[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_ft[0], 499U);
    t15_2_B.c_eob_cj = t15_2_B.I1_o;
  } else {
    t15_2_B.c_eob_cj = t15_2_B.Memory2_b;
  }

  /* End of Switch: '<S26>/c_eob' */

  /* Product: '<S26>/Divide1' */
  t15_2_B.Divide1_nq = t15_2_B.c_eob_cj * t15_2_B.u_n;

  /* Sum: '<S20>/Add3' */
  t15_2_B.Add3_c = t15_2_B.e6_m[0] - t15_2_B.Divide1_nq;

  /* Memory: '<S31>/Memory2' */
  t15_2_B.Memory2_d = t15_2_DWork.Memory2_PreviousInput_e;

  /* Switch: '<S31>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_h) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S31>/Data Store Read1' */
      t15_2_B.DataStoreRead1_h[i] = t15_2_DWork.scr_data[13 * i + 5];

      /* DataStoreRead: '<S31>/Data Store Read' */
      t15_2_B.DataStoreRead_i4[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S31>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_i), &t15_2_B.DataStoreRead1_h[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_i4[0], 499U);
    t15_2_B.c_eob_k = t15_2_B.I1_i;
  } else {
    t15_2_B.c_eob_k = t15_2_B.Memory2_d;
  }

  /* End of Switch: '<S31>/c_eob' */

  /* Product: '<S31>/Divide1' */
  t15_2_B.Divide1_p = t15_2_B.c_eob_k * t15_2_B.u_n;

  /* Sum: '<S20>/Add4' */
  t15_2_B.Add4 = t15_2_B.e6_m[3] - t15_2_B.Divide1_p;

  /* Memory: '<S32>/Memory2' */
  t15_2_B.Memory2_p = t15_2_DWork.Memory2_PreviousInput_o;

  /* Switch: '<S32>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_on) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S32>/Data Store Read1' */
      t15_2_B.DataStoreRead1_mj[i] = t15_2_DWork.scr_data[13 * i + 6];

      /* DataStoreRead: '<S32>/Data Store Read' */
      t15_2_B.DataStoreRead_gy[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S32>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_c), &t15_2_B.DataStoreRead1_mj[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_gy[0], 499U);
    t15_2_B.c_eob_g = t15_2_B.I1_c;
  } else {
    t15_2_B.c_eob_g = t15_2_B.Memory2_p;
  }

  /* End of Switch: '<S32>/c_eob' */

  /* Product: '<S32>/Divide1' */
  t15_2_B.Divide1_l = t15_2_B.c_eob_g * t15_2_B.u_n;

  /* Sum: '<S20>/Add5' */
  t15_2_B.Add5 = t15_2_B.e6_m[4] - t15_2_B.Divide1_l;

  /* Memory: '<S33>/Memory2' */
  t15_2_B.Memory2_dq = t15_2_DWork.Memory2_PreviousInput_eq;

  /* Switch: '<S33>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_j) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S33>/Data Store Read1' */
      t15_2_B.DataStoreRead1_kd[i] = t15_2_DWork.scr_data[13 * i + 7];

      /* DataStoreRead: '<S33>/Data Store Read' */
      t15_2_B.DataStoreRead_d[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S33>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_j), &t15_2_B.DataStoreRead1_kd[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_d[0], 499U);
    t15_2_B.c_eob_l = t15_2_B.I1_j;
  } else {
    t15_2_B.c_eob_l = t15_2_B.Memory2_dq;
  }

  /* End of Switch: '<S33>/c_eob' */

  /* Product: '<S33>/Divide1' */
  t15_2_B.Divide1_e = t15_2_B.c_eob_l * t15_2_B.u_n;

  /* Sum: '<S20>/Add6' */
  t15_2_B.Add6 = t15_2_B.e6_m[5] - t15_2_B.Divide1_e;

  /* Memory: '<S34>/Memory2' */
  t15_2_B.Memory2_e = t15_2_DWork.Memory2_PreviousInput_bf;

  /* Switch: '<S34>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_n) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S34>/Data Store Read1' */
      t15_2_B.DataStoreRead1_fi[i] = t15_2_DWork.scr_data[13 * i + 8];

      /* DataStoreRead: '<S34>/Data Store Read' */
      t15_2_B.DataStoreRead_jd[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S34>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_k), &t15_2_B.DataStoreRead1_fi[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_jd[0], 499U);
    t15_2_B.c_eob_g0 = t15_2_B.I1_k;
  } else {
    t15_2_B.c_eob_g0 = t15_2_B.Memory2_e;
  }

  /* End of Switch: '<S34>/c_eob' */

  /* Product: '<S34>/Divide1' */
  t15_2_B.Divide1_f = t15_2_B.c_eob_g0 * t15_2_B.u_n;

  /* Sum: '<S20>/Add7' */
  t15_2_B.Add7 = t15_2_B.e6_m[6] - t15_2_B.Divide1_f;

  /* Memory: '<S35>/Memory2' */
  t15_2_B.Memory2_j = t15_2_DWork.Memory2_PreviousInput_l;

  /* Switch: '<S35>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_hg) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S35>/Data Store Read1' */
      t15_2_B.DataStoreRead1_g[i] = t15_2_DWork.scr_data[13 * i + 9];

      /* DataStoreRead: '<S35>/Data Store Read' */
      t15_2_B.DataStoreRead_ef[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S35>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1_g), &t15_2_B.DataStoreRead1_g[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_ef[0], 499U);
    t15_2_B.c_eob_bz = t15_2_B.I1_g;
  } else {
    t15_2_B.c_eob_bz = t15_2_B.Memory2_j;
  }

  /* End of Switch: '<S35>/c_eob' */

  /* Product: '<S35>/Divide1' */
  t15_2_B.Divide1_hq = t15_2_B.c_eob_bz * t15_2_B.u_n;

  /* Sum: '<S20>/Add8' */
  t15_2_B.Add8 = t15_2_B.e6_m[7] - t15_2_B.Divide1_hq;

  /* Memory: '<S36>/Memory2' */
  t15_2_B.Memory2_a = t15_2_DWork.Memory2_PreviousInput_j;

  /* Switch: '<S36>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_m) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S36>/Data Store Read1' */
      t15_2_B.DataStoreRead1_cq[i] = t15_2_DWork.scr_data[13 * i + 10];

      /* DataStoreRead: '<S36>/Data Store Read' */
      t15_2_B.DataStoreRead_cq[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S36>/I1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.I1), &t15_2_B.DataStoreRead1_cq[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_cq[0], 499U);
    t15_2_B.c_eob_j = t15_2_B.I1;
  } else {
    t15_2_B.c_eob_j = t15_2_B.Memory2_a;
  }

  /* End of Switch: '<S36>/c_eob' */

  /* Product: '<S36>/Divide1' */
  t15_2_B.Divide1_d = t15_2_B.c_eob_j * t15_2_B.u_n;

  /* Sum: '<S20>/Add9' */
  t15_2_B.Add9 = t15_2_B.e6_m[8] - t15_2_B.Divide1_d;

  /* Sum: '<S16>/Sum2' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_B.Sum2_b = t15_2_U.In1[5] - t15_2_U.In1[7];

  /* Switch: '<S16>/>=0' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (t15_2_B.Sum2_b >= t15_2_P.u_Threshold) {
    t15_2_B.u_p = t15_2_U.In1[7];
  } else {
    t15_2_B.u_p = t15_2_U.In1[5];
  }

  /* End of Switch: '<S16>/>=0' */

  /* Gain: '<S21>/1e2' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  t15_2_B.e2[0] = t15_2_P.e2_Gain * t15_2_U.In2[0];
  t15_2_B.e2[1] = t15_2_P.e2_Gain * t15_2_U.In2[1];
  t15_2_B.e2[2] = t15_2_P.e2_Gain * t15_2_U.In1[6];
  t15_2_B.e2[3] = t15_2_P.e2_Gain * t15_2_U.In2[3];
  t15_2_B.e2[4] = t15_2_P.e2_Gain * t15_2_U.In2[4];
  t15_2_B.e2[5] = t15_2_P.e2_Gain * t15_2_B.u_p;

  /* Level2 S-Function Block: '<S42>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S42>/Memory2' */
  t15_2_B.Memory2_da = t15_2_DWork.Memory2_PreviousInput_o4;

  /* Switch: '<S42>/c_eob  1' */
  if (t15_2_B.u_n > t15_2_P.c_eob1_Threshold) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S42>/Selector' */
      t15_2_B.Selector_j[i] = t15_2_B.SFunction1_o[(i << 1) + 1];

      /* Selector: '<S42>/Selector1' */
      t15_2_B.Selector1_n[i] = t15_2_B.SFunction1_o[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S42>/g1ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g1ref), &t15_2_B.Selector_j[0], t15_2_B.e3,
                         &t15_2_B.Selector1_n[0], 49U);
    t15_2_B.c_eob1 = t15_2_B.g1ref;
  } else {
    t15_2_B.c_eob1 = t15_2_B.Memory2_da;
  }

  /* End of Switch: '<S42>/c_eob  1' */

  /* Memory: '<S42>/Memory1' */
  t15_2_B.Memory1_i = t15_2_DWork.Memory1_PreviousInput_g;

  /* Switch: '<S42>/c_eob  ' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_k) {
    t15_2_B.c_eob_ej = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_ej = t15_2_B.Memory1_i;
  }

  /* End of Switch: '<S42>/c_eob  ' */

  /* Level2 S-Function Block: '<S48>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S42>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_hx) {
    t15_2_B.c_eob_jd = t15_2_B.c_eob1;
  } else {
    /* SignalConversion: '<S48>/TmpSignal ConversionAtg1_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg1_termref[0] = t15_2_B.c_eob1;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S48>/Selector' */
      t15_2_B.Selector_k[i] = t15_2_B.SFunction1_p[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg1_termref[i + 1] = t15_2_B.Selector_k[i];
    }

    /* End of SignalConversion: '<S48>/TmpSignal ConversionAtg1_term,refInport3' */

    /* DataStoreRead: '<S48>/Data Store Read' */
    t15_2_B.DataStoreRead_bi = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S48>/Selector1' */
      t15_2_B.Selector1_p[i] = t15_2_B.SFunction1_p[i << 1];

      /* Product: '<S48>/Divide6' incorporates:
       *  Constant: '<S48>/Constant'
       */
      t15_2_B.Divide6_f0[i] = t15_2_B.Selector1_p[i] * t15_2_B.DataStoreRead_bi /
        t15_2_P.Constant_Value_ow;

      /* Sum: '<S48>/Add2' */
      t15_2_B.Add2_i[i] = t15_2_B.c_eob_ej + t15_2_B.Divide6_f0[i];
    }

    /* Dynamic Look-Up Table Block: '<S48>/g1_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g1_termref),
                         &t15_2_B.TmpSignalConversionAtg1_termref[0], t15_2_B.e3,
                         &t15_2_B.Add2_i[0], 49U);
    t15_2_B.c_eob_jd = t15_2_B.g1_termref;
  }

  /* End of Switch: '<S42>/c_eob' */

  /* Sum: '<S21>/Add2' */
  t15_2_B.Add2_b = t15_2_B.e2[0] - t15_2_B.c_eob_jd;

  /* Lookup: '<S21>/Lookup Table1'
   * About '<S21>/Lookup Table1':
   * Input0  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_real_T_real_T( &(t15_2_B.LookupTable1), t15_2_P.LookupTable1_YData,
                       t15_2_B.e3, t15_2_P.LookupTable1_XData, 3U);

  /* Product: '<S21>/Divide6' */
  t15_2_B.Divide6_d = t15_2_B.Add2_b * t15_2_B.LookupTable1;

  /* Level2 S-Function Block: '<S37>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[5];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S37>/Memory2' */
  t15_2_B.Memory2_i = t15_2_DWork.Memory2_PreviousInput_mw;

  /* Switch: '<S37>/c_eob  1' */
  if (t15_2_B.u_n > t15_2_P.c_eob1_Threshold_o) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S37>/Selector' */
      t15_2_B.Selector_lh[i] = t15_2_B.SFunction1_f[(i << 1) + 1];

      /* Selector: '<S37>/Selector1' */
      t15_2_B.Selector1_ad[i] = t15_2_B.SFunction1_f[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S37>/g2ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g2ref), &t15_2_B.Selector_lh[0], t15_2_B.e3,
                         &t15_2_B.Selector1_ad[0], 49U);
    t15_2_B.c_eob1_b = t15_2_B.g2ref;
  } else {
    t15_2_B.c_eob1_b = t15_2_B.Memory2_i;
  }

  /* End of Switch: '<S37>/c_eob  1' */

  /* Memory: '<S37>/Memory1' */
  t15_2_B.Memory1_g = t15_2_DWork.Memory1_PreviousInput_d;

  /* Switch: '<S37>/c_eob  ' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_j0) {
    t15_2_B.c_eob_n = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_n = t15_2_B.Memory1_g;
  }

  /* End of Switch: '<S37>/c_eob  ' */

  /* Level2 S-Function Block: '<S43>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[6];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S37>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_l) {
    t15_2_B.c_eob_kt = t15_2_B.c_eob1_b;
  } else {
    /* SignalConversion: '<S43>/TmpSignal ConversionAtg2_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg2_termref[0] = t15_2_B.c_eob1_b;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S43>/Selector' */
      t15_2_B.Selector_k4[i] = t15_2_B.SFunction1_f2[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg2_termref[i + 1] = t15_2_B.Selector_k4[i];
    }

    /* End of SignalConversion: '<S43>/TmpSignal ConversionAtg2_term,refInport3' */

    /* DataStoreRead: '<S43>/Data Store Read' */
    t15_2_B.DataStoreRead_m = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S43>/Selector1' */
      t15_2_B.Selector1_d[i] = t15_2_B.SFunction1_f2[i << 1];

      /* Product: '<S43>/Divide6' incorporates:
       *  Constant: '<S43>/Constant'
       */
      t15_2_B.Divide6_n[i] = t15_2_B.Selector1_d[i] * t15_2_B.DataStoreRead_m /
        t15_2_P.Constant_Value;

      /* Sum: '<S43>/Add2' */
      t15_2_B.Add2_p[i] = t15_2_B.c_eob_n + t15_2_B.Divide6_n[i];
    }

    /* Dynamic Look-Up Table Block: '<S43>/g2_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g2_termref),
                         &t15_2_B.TmpSignalConversionAtg2_termref[0], t15_2_B.e3,
                         &t15_2_B.Add2_p[0], 49U);
    t15_2_B.c_eob_kt = t15_2_B.g2_termref;
  }

  /* End of Switch: '<S37>/c_eob' */

  /* Sum: '<S21>/Add1' */
  t15_2_B.Add1_ia = t15_2_B.e2[1] - t15_2_B.c_eob_kt;

  /* Lookup: '<S21>/Lookup Table2'
   * About '<S21>/Lookup Table2':
   * Input0  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_real_T_real_T( &(t15_2_B.LookupTable2), t15_2_P.LookupTable2_YData,
                       t15_2_B.e3, t15_2_P.LookupTable2_XData, 3U);

  /* Product: '<S21>/Divide1' */
  t15_2_B.Divide1_a = t15_2_B.Add1_ia * t15_2_B.LookupTable2;

  /* Level2 S-Function Block: '<S38>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[7];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S38>/Memory2' */
  t15_2_B.Memory2_n = t15_2_DWork.Memory2_PreviousInput_h;

  /* Switch: '<S38>/c_eob  1' */
  if (t15_2_B.u_n > t15_2_P.c_eob1_Threshold_l) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S38>/Selector' */
      t15_2_B.Selector_g[i] = t15_2_B.SFunction1_e[(i << 1) + 1];

      /* Selector: '<S38>/Selector1' */
      t15_2_B.Selector1_nf[i] = t15_2_B.SFunction1_e[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S38>/g3ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g3ref), &t15_2_B.Selector_g[0], t15_2_B.e3,
                         &t15_2_B.Selector1_nf[0], 49U);
    t15_2_B.c_eob1_i = t15_2_B.g3ref;
  } else {
    t15_2_B.c_eob1_i = t15_2_B.Memory2_n;
  }

  /* End of Switch: '<S38>/c_eob  1' */

  /* Memory: '<S38>/Memory1' */
  t15_2_B.Memory1_jo = t15_2_DWork.Memory1_PreviousInput_p;

  /* Switch: '<S38>/c_eob  ' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_jk) {
    t15_2_B.c_eob_lg = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_lg = t15_2_B.Memory1_jo;
  }

  /* End of Switch: '<S38>/c_eob  ' */

  /* Level2 S-Function Block: '<S44>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[8];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S38>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_g2) {
    t15_2_B.c_eob_lu = t15_2_B.c_eob1_i;
  } else {
    /* SignalConversion: '<S44>/TmpSignal ConversionAtg3_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg3_termref[0] = t15_2_B.c_eob1_i;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S44>/Selector' */
      t15_2_B.Selector_e[i] = t15_2_B.SFunction1_h[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg3_termref[i + 1] = t15_2_B.Selector_e[i];
    }

    /* End of SignalConversion: '<S44>/TmpSignal ConversionAtg3_term,refInport3' */

    /* DataStoreRead: '<S44>/Data Store Read' */
    t15_2_B.DataStoreRead_n2 = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S44>/Selector1' */
      t15_2_B.Selector1_c[i] = t15_2_B.SFunction1_h[i << 1];

      /* Product: '<S44>/Divide6' incorporates:
       *  Constant: '<S44>/Constant'
       */
      t15_2_B.Divide6_p[i] = t15_2_B.Selector1_c[i] * t15_2_B.DataStoreRead_n2 /
        t15_2_P.Constant_Value_j;

      /* Sum: '<S44>/Add2' */
      t15_2_B.Add2_oa[i] = t15_2_B.c_eob_lg + t15_2_B.Divide6_p[i];
    }

    /* Dynamic Look-Up Table Block: '<S44>/g3_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g3_termref),
                         &t15_2_B.TmpSignalConversionAtg3_termref[0], t15_2_B.e3,
                         &t15_2_B.Add2_oa[0], 49U);
    t15_2_B.c_eob_lu = t15_2_B.g3_termref;
  }

  /* End of Switch: '<S38>/c_eob' */

  /* Sum: '<S21>/Add3' */
  t15_2_B.Add3_a = t15_2_B.e2[2] - t15_2_B.c_eob_lu;

  /* Level2 S-Function Block: '<S39>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[9];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S39>/Memory2' */
  t15_2_B.Memory2_l = t15_2_DWork.Memory2_PreviousInput_g;

  /* Switch: '<S39>/c_eob  1' */
  if (t15_2_B.u_n > t15_2_P.c_eob1_Threshold_lw) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S39>/Selector' */
      t15_2_B.Selector_d[i] = t15_2_B.SFunction1_fd[(i << 1) + 1];

      /* Selector: '<S39>/Selector1' */
      t15_2_B.Selector1_ou[i] = t15_2_B.SFunction1_fd[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S39>/g4ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g4ref), &t15_2_B.Selector_d[0], t15_2_B.e3,
                         &t15_2_B.Selector1_ou[0], 49U);
    t15_2_B.c_eob1_d = t15_2_B.g4ref;
  } else {
    t15_2_B.c_eob1_d = t15_2_B.Memory2_l;
  }

  /* End of Switch: '<S39>/c_eob  1' */

  /* Memory: '<S39>/Memory1' */
  t15_2_B.Memory1_e = t15_2_DWork.Memory1_PreviousInput_h;

  /* Switch: '<S39>/c_eob  ' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_b) {
    t15_2_B.c_eob_c2 = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_c2 = t15_2_B.Memory1_e;
  }

  /* End of Switch: '<S39>/c_eob  ' */

  /* Level2 S-Function Block: '<S45>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[10];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S39>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_d) {
    t15_2_B.c_eob_p = t15_2_B.c_eob1_d;
  } else {
    /* SignalConversion: '<S45>/TmpSignal ConversionAtg4_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg4_termref[0] = t15_2_B.c_eob1_d;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S45>/Selector' */
      t15_2_B.Selector_ns[i] = t15_2_B.SFunction1_o5[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg4_termref[i + 1] = t15_2_B.Selector_ns[i];
    }

    /* End of SignalConversion: '<S45>/TmpSignal ConversionAtg4_term,refInport3' */

    /* DataStoreRead: '<S45>/Data Store Read' */
    t15_2_B.DataStoreRead_cj = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S45>/Selector1' */
      t15_2_B.Selector1_pz[i] = t15_2_B.SFunction1_o5[i << 1];

      /* Product: '<S45>/Divide6' incorporates:
       *  Constant: '<S45>/Constant'
       */
      t15_2_B.Divide6_h[i] = t15_2_B.Selector1_pz[i] * t15_2_B.DataStoreRead_cj /
        t15_2_P.Constant_Value_i;

      /* Sum: '<S45>/Add2' */
      t15_2_B.Add2_bw[i] = t15_2_B.c_eob_c2 + t15_2_B.Divide6_h[i];
    }

    /* Dynamic Look-Up Table Block: '<S45>/g4_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g4_termref),
                         &t15_2_B.TmpSignalConversionAtg4_termref[0], t15_2_B.e3,
                         &t15_2_B.Add2_bw[0], 49U);
    t15_2_B.c_eob_p = t15_2_B.g4_termref;
  }

  /* End of Switch: '<S39>/c_eob' */

  /* Sum: '<S21>/Add4' */
  t15_2_B.Add4_i = t15_2_B.e2[3] - t15_2_B.c_eob_p;

  /* Lookup: '<S21>/Lookup Table3'
   * About '<S21>/Lookup Table3':
   * Input0  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_real_T_real_T( &(t15_2_B.LookupTable3), t15_2_P.LookupTable3_YData,
                       t15_2_B.e3, t15_2_P.LookupTable3_XData, 3U);

  /* Product: '<S21>/Divide2' */
  t15_2_B.Divide2 = t15_2_B.Add4_i * t15_2_B.LookupTable3;

  /* Level2 S-Function Block: '<S40>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[11];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S40>/Memory2' */
  t15_2_B.Memory2_m = t15_2_DWork.Memory2_PreviousInput_oh;

  /* Switch: '<S40>/c_eob  1' */
  if (t15_2_B.u_n > t15_2_P.c_eob1_Threshold_h) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S40>/Selector' */
      t15_2_B.Selector_f[i] = t15_2_B.SFunction1_n[(i << 1) + 1];

      /* Selector: '<S40>/Selector1' */
      t15_2_B.Selector1_a[i] = t15_2_B.SFunction1_n[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S40>/g5ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g5ref), &t15_2_B.Selector_f[0], t15_2_B.e3,
                         &t15_2_B.Selector1_a[0], 49U);
    t15_2_B.c_eob1_c = t15_2_B.g5ref;
  } else {
    t15_2_B.c_eob1_c = t15_2_B.Memory2_m;
  }

  /* End of Switch: '<S40>/c_eob  1' */

  /* Memory: '<S40>/Memory1' */
  t15_2_B.Memory1_b = t15_2_DWork.Memory1_PreviousInput_gk;

  /* Switch: '<S40>/c_eob  ' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_nn) {
    t15_2_B.c_eob_nk = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_nk = t15_2_B.Memory1_b;
  }

  /* End of Switch: '<S40>/c_eob  ' */

  /* Level2 S-Function Block: '<S46>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[12];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S40>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_a) {
    t15_2_B.c_eob_cy = t15_2_B.c_eob1_c;
  } else {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtg5_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg5_termref[0] = t15_2_B.c_eob1_c;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S46>/Selector' */
      t15_2_B.Selector_l[i] = t15_2_B.SFunction1_a[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg5_termref[i + 1] = t15_2_B.Selector_l[i];
    }

    /* End of SignalConversion: '<S46>/TmpSignal ConversionAtg5_term,refInport3' */

    /* DataStoreRead: '<S46>/Data Store Read' */
    t15_2_B.DataStoreRead_c = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S46>/Selector1' */
      t15_2_B.Selector1_o[i] = t15_2_B.SFunction1_a[i << 1];

      /* Product: '<S46>/Divide6' incorporates:
       *  Constant: '<S46>/Constant'
       */
      t15_2_B.Divide6_i[i] = t15_2_B.Selector1_o[i] * t15_2_B.DataStoreRead_c /
        t15_2_P.Constant_Value_o;

      /* Sum: '<S46>/Add2' */
      t15_2_B.Add2_bd[i] = t15_2_B.c_eob_nk + t15_2_B.Divide6_i[i];
    }

    /* Dynamic Look-Up Table Block: '<S46>/g5_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g5_termref),
                         &t15_2_B.TmpSignalConversionAtg5_termref[0], t15_2_B.e3,
                         &t15_2_B.Add2_bd[0], 49U);
    t15_2_B.c_eob_cy = t15_2_B.g5_termref;
  }

  /* End of Switch: '<S40>/c_eob' */

  /* Sum: '<S21>/Add5' */
  t15_2_B.Add5_n = t15_2_B.e2[4] - t15_2_B.c_eob_cy;

  /* Level2 S-Function Block: '<S41>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[13];
    sfcnOutputs(rts, 0);
  }

  /* Memory: '<S41>/Memory2' */
  t15_2_B.Memory2_j1 = t15_2_DWork.Memory2_PreviousInput_ef;

  /* Switch: '<S41>/c_eob  1' */
  if (t15_2_B.u_n > t15_2_P.c_eob1_Threshold_m) {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S41>/Selector' */
      t15_2_B.Selector_j2[i] = t15_2_B.SFunction1_p1[(i << 1) + 1];

      /* Selector: '<S41>/Selector1' */
      t15_2_B.Selector1_f[i] = t15_2_B.SFunction1_p1[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S41>/g6ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g6ref), &t15_2_B.Selector_j2[0], t15_2_B.e3,
                         &t15_2_B.Selector1_f[0], 49U);
    t15_2_B.c_eob1_g = t15_2_B.g6ref;
  } else {
    t15_2_B.c_eob1_g = t15_2_B.Memory2_j1;
  }

  /* End of Switch: '<S41>/c_eob  1' */

  /* Memory: '<S41>/Memory1' */
  t15_2_B.Memory1_g3 = t15_2_DWork.Memory1_PreviousInput_j;

  /* Switch: '<S41>/c_eob  ' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_mb) {
    t15_2_B.c_eob_be = t15_2_B.e3;
  } else {
    t15_2_B.c_eob_be = t15_2_B.Memory1_g3;
  }

  /* End of Switch: '<S41>/c_eob  ' */

  /* Level2 S-Function Block: '<S47>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[14];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S41>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_ge) {
    t15_2_B.c_eob_c3 = t15_2_B.c_eob1_g;
  } else {
    /* SignalConversion: '<S47>/TmpSignal ConversionAtg6_term,refInport3' */
    t15_2_B.TmpSignalConversionAtg6_termref[0] = t15_2_B.c_eob1_g;
    for (i = 0; i < 49; i++) {
      /* Selector: '<S47>/Selector' */
      t15_2_B.Selector_n[i] = t15_2_B.SFunction1_c[((1 + i) << 1) + 1];
      t15_2_B.TmpSignalConversionAtg6_termref[i + 1] = t15_2_B.Selector_n[i];
    }

    /* End of SignalConversion: '<S47>/TmpSignal ConversionAtg6_term,refInport3' */

    /* DataStoreRead: '<S47>/Data Store Read' */
    t15_2_B.DataStoreRead_ag = t15_2_DWork.RupRd[1];
    for (i = 0; i < 50; i++) {
      /* Selector: '<S47>/Selector1' */
      t15_2_B.Selector1_no[i] = t15_2_B.SFunction1_c[i << 1];

      /* Product: '<S47>/Divide6' incorporates:
       *  Constant: '<S47>/Constant'
       */
      t15_2_B.Divide6_fz[i] = t15_2_B.Selector1_no[i] * t15_2_B.DataStoreRead_ag
        / t15_2_P.Constant_Value_n;

      /* Sum: '<S47>/Add2' */
      t15_2_B.Add2_no[i] = t15_2_B.c_eob_be + t15_2_B.Divide6_fz[i];
    }

    /* Dynamic Look-Up Table Block: '<S47>/g6_term,ref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.g6_termref),
                         &t15_2_B.TmpSignalConversionAtg6_termref[0], t15_2_B.e3,
                         &t15_2_B.Add2_no[0], 49U);
    t15_2_B.c_eob_c3 = t15_2_B.g6_termref;
  }

  /* End of Switch: '<S41>/c_eob' */

  /* Sum: '<S21>/Add6' */
  t15_2_B.Add6_b = t15_2_B.e2[5] - t15_2_B.c_eob_c3;

  /* Gain: '<S21>/1e-2' */
  t15_2_B.e2_n[0] = t15_2_P.e2_Gain_j * t15_2_B.Divide6_d;
  t15_2_B.e2_n[1] = t15_2_P.e2_Gain_j * t15_2_B.Divide1_a;
  t15_2_B.e2_n[2] = t15_2_P.e2_Gain_j * t15_2_B.Add3_a;
  t15_2_B.e2_n[3] = t15_2_P.e2_Gain_j * t15_2_B.Divide2;
  t15_2_B.e2_n[4] = t15_2_P.e2_Gain_j * t15_2_B.Add5_n;
  t15_2_B.e2_n[5] = t15_2_P.e2_Gain_j * t15_2_B.Add6_b;

  /* RelationalOperator: '<S49>/Compare' incorporates:
   *  Constant: '<S49>/Constant'
   */
  t15_2_B.Compare = (uint8_T)(t15_2_B.e6 > t15_2_P.Constant_Value_if);

  /* DataStoreRead: '<S22>/Data Store Read' */
  t15_2_B.DataStoreRead_or = t15_2_DWork.RupRd[0];

  /* RelationalOperator: '<S22>/Relational Operator' */
  t15_2_B.RelationalOperator_p = (t15_2_B.e3 > t15_2_B.DataStoreRead_or);

  /* Logic: '<S22>/Logical Operator1' */
  t15_2_B.LogicalOperator1 = ((t15_2_B.Compare != 0) ||
    t15_2_B.RelationalOperator_p);

  /* Switch: '<S22>/0.99' incorporates:
   *  Constant: '<S14>/Constant4'
   */
  if (t15_2_B.LogicalOperator1 >= t15_2_P.u9_Threshold) {
    for (i = 0; i < 6; i++) {
      t15_2_B.u9[i] = t15_2_B.e2_n[i];
    }

    t15_2_B.u9[6] = t15_2_P.Constant4_Value_l;
    t15_2_B.u9[7] = t15_2_B.Add1_i;
    t15_2_B.u9[8] = t15_2_B.Add3_c;
    t15_2_B.u9[9] = t15_2_B.Add1_g;
    t15_2_B.u9[10] = t15_2_B.Add2_o;
    t15_2_B.u9[11] = t15_2_B.Add4;
    t15_2_B.u9[12] = t15_2_B.Add5;
    t15_2_B.u9[13] = t15_2_B.Add6;
    t15_2_B.u9[14] = t15_2_B.Add7;
    t15_2_B.u9[15] = t15_2_B.Add8;
    t15_2_B.u9[16] = t15_2_B.Add9;
    t15_2_B.u9[17] = t15_2_B.Add10;
    t15_2_B.u9[18] = t15_2_B.Add11;
    t15_2_B.u9[19] = t15_2_P.Constant4_Value_l;
  } else {
    for (i = 0; i < 50; i++) {
      /* Selector: '<S19>/Selector' */
      t15_2_B.Selector[i] = t15_2_B.SFunction1_i[(i << 1) + 1];

      /* Selector: '<S19>/Selector1' */
      t15_2_B.Selector1[i] = t15_2_B.SFunction1_i[i << 1];
    }

    /* Dynamic Look-Up Table Block: '<S19>/elong'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.elong), &t15_2_B.Selector[0], t15_2_B.e3,
                         &t15_2_B.Selector1[0], 49U);

    /* Sum: '<S14>/Add2' incorporates:
     *  Inport: '<Root>/In1'
     */
    t15_2_B.Add2_m = t15_2_U.In1[2] - t15_2_B.elong;

    /* Gain: '<S14>/k_gaplim' */
    t15_2_B.k_gaplim[0] = t15_2_P.k_gaplim_Gain[0] * t15_2_B.e2_n[2];
    t15_2_B.k_gaplim[1] = t15_2_P.k_gaplim_Gain[1] * t15_2_B.e2_n[3];
    t15_2_B.k_gaplim[2] = t15_2_P.k_gaplim_Gain[2] * t15_2_B.e2_n[4];
    t15_2_B.k_gaplim[3] = t15_2_P.k_gaplim_Gain[3] * t15_2_B.e2_n[5];
    t15_2_B.u9[0] = t15_2_B.Add2_m;
    t15_2_B.u9[1] = t15_2_P.Constant4_Value_l;
    t15_2_B.u9[2] = t15_2_B.k_gaplim[0];
    t15_2_B.u9[3] = t15_2_B.k_gaplim[1];
    t15_2_B.u9[4] = t15_2_B.k_gaplim[2];
    t15_2_B.u9[5] = t15_2_B.k_gaplim[3];
    t15_2_B.u9[6] = t15_2_P.Constant4_Value_l;
    t15_2_B.u9[7] = t15_2_B.Add1_i;
    t15_2_B.u9[8] = t15_2_B.Add3_c;
    t15_2_B.u9[9] = t15_2_B.Add1_g;
    t15_2_B.u9[10] = t15_2_B.Add2_o;
    t15_2_B.u9[11] = t15_2_B.Add4;
    t15_2_B.u9[12] = t15_2_B.Add5;
    t15_2_B.u9[13] = t15_2_B.Add6;
    t15_2_B.u9[14] = t15_2_B.Add7;
    t15_2_B.u9[15] = t15_2_B.Add8;
    t15_2_B.u9[16] = t15_2_B.Add9;
    t15_2_B.u9[17] = t15_2_B.Add10;
    t15_2_B.u9[18] = t15_2_B.Add11;
    t15_2_B.u9[19] = t15_2_P.Constant4_Value_l;
  }

  /* End of Switch: '<S22>/0.99' */

  /* Gain: '<S23>/1e6' */
  t15_2_B.e6_i = t15_2_P.e6_Gain_m * t15_2_B.Add2;

  /* Memory: '<S50>/Memory3' */
  t15_2_B.Memory3 = t15_2_DWork.Memory3_PreviousInput;

  /* RelationalOperator: '<S66>/Compare' incorporates:
   *  Constant: '<S66>/Constant'
   */
  t15_2_B.Compare_p = (uint8_T)(t15_2_B.e6 > t15_2_P.Constant_Value_e);

  /* DataStoreRead: '<S67>/Data Store Read' */
  t15_2_B.DataStoreRead_f = t15_2_DWork.RupRd[0];

  /* RelationalOperator: '<S67>/Relational Operator' */
  t15_2_B.RelationalOperator_d = (t15_2_B.e3 > t15_2_B.DataStoreRead_f);

  /* Logic: '<S50>/Logical Operator1' */
  t15_2_B.LogicalOperator1_h = ((t15_2_B.Compare_p != 0) ||
    t15_2_B.RelationalOperator_d);

  /* Switch: '<S50>/0.9999' */
  if (t15_2_B.LogicalOperator1_h > t15_2_P.u999_Threshold) {
    t15_2_B.u999 = t15_2_B.Memory3;
  } else {
    t15_2_B.u999 = t15_2_B.e3;
  }

  /* End of Switch: '<S50>/0.9999' */

  /* Sum: '<S50>/Subtract2' */
  t15_2_B.Subtract2 = t15_2_B.e3 - t15_2_B.u999;

  /* Gain: '<S50>/Gain1' */
  t15_2_B.Gain1 = t15_2_P.Gain1_Gain_j * t15_2_B.Subtract2;

  /* Sum: '<S50>/Subtract1' incorporates:
   *  Constant: '<S50>/1'
   */
  t15_2_B.Subtract1 = t15_2_B.Gain1 + t15_2_P._Value_n;

  /* Saturate: '<S50>/Saturation1' */
  tmin = t15_2_B.Subtract1;
  u = t15_2_P.Saturation1_LowerSat;
  u_0 = t15_2_P.Saturation1_UpperSat;
  if (tmin >= u_0) {
    t15_2_B.Saturation1 = u_0;
  } else if (tmin <= u) {
    t15_2_B.Saturation1 = u;
  } else {
    t15_2_B.Saturation1 = tmin;
  }

  /* End of Saturate: '<S50>/Saturation1' */

  /* Memory: '<S51>/Memory1' */
  t15_2_B.Memory1_a = t15_2_DWork.Memory1_PreviousInput_l;

  /* DataStoreRead: '<S68>/Data Store Read' */
  t15_2_B.DataStoreRead_l = t15_2_DWork.RupRd[2];

  /* Abs: '<S68>/Abs' */
  t15_2_B.Abs = fabs(t15_2_B.DataStoreRead_l);

  /* RelationalOperator: '<S68>/Relational Operator' */
  t15_2_B.RelationalOperator_f = (t15_2_B.e6 < t15_2_B.Abs);

  /* DataStoreRead: '<S69>/Data Store Read' */
  t15_2_B.DataStoreRead_i = t15_2_DWork.RupRd[0];

  /* RelationalOperator: '<S69>/Relational Operator' */
  t15_2_B.RelationalOperator_d5 = (t15_2_B.e3 > t15_2_B.DataStoreRead_i);

  /* Logic: '<S51>/Logical Operator2' */
  t15_2_B.LogicalOperator2 = (t15_2_B.RelationalOperator_f &&
    t15_2_B.RelationalOperator_d5);

  /* Switch: '<S51>/0.9999' */
  if (t15_2_B.LogicalOperator2 > t15_2_P.u999_Threshold_f) {
    t15_2_B.u999_d = t15_2_B.Memory1_a;
  } else {
    t15_2_B.u999_d = t15_2_B.e3;
  }

  /* End of Switch: '<S51>/0.9999' */

  /* Sum: '<S51>/Subtract2' */
  t15_2_B.Subtract2_h = t15_2_B.e3 - t15_2_B.u999_d;

  /* Gain: '<S51>/Gain1' */
  t15_2_B.Gain1_j = t15_2_P.Gain1_Gain_j0 * t15_2_B.Subtract2_h;

  /* Sum: '<S51>/Subtract3' incorporates:
   *  Constant: '<S51>/1'
   */
  t15_2_B.Subtract3 = t15_2_B.Gain1_j + t15_2_P._Value_f;

  /* Saturate: '<S51>/Saturation' */
  tmin = t15_2_B.Subtract3;
  u = t15_2_P.Saturation_LowerSat_d;
  u_0 = t15_2_P.Saturation_UpperSat_o;
  if (tmin >= u_0) {
    t15_2_B.Saturation = u_0;
  } else if (tmin <= u) {
    t15_2_B.Saturation = u;
  } else {
    t15_2_B.Saturation = tmin;
  }

  /* End of Saturate: '<S51>/Saturation' */

  /* Sum: '<S51>/Subtract1' incorporates:
   *  Constant: '<S51>/1'
   */
  t15_2_B.Subtract1_k = t15_2_P._Value_f - t15_2_B.Saturation;

  /* Sum: '<S51>/Subtract4' incorporates:
   *  Constant: '<S51>/1'
   */
  t15_2_B.Subtract4 = t15_2_P._Value_f - t15_2_B.LogicalOperator2;

  /* DataStoreRead: '<S52>/Data Store Read1' */
  t15_2_B.DataStoreRead1_kb = t15_2_DWork.c_cur_max;

  /* DataStoreRead: '<S60>/Data Store Read' */
  t15_2_B.DataStoreRead_ln = t15_2_DWork.RupRd[2];

  /* Abs: '<S60>/Abs' */
  t15_2_B.Abs_c = fabs(t15_2_B.DataStoreRead_ln);

  /* RelationalOperator: '<S60>/Relational Operator' */
  t15_2_B.RelationalOperator_nb = (t15_2_B.e6 < t15_2_B.Abs_c);

  /* DataStoreRead: '<S60>/Data Store Read1' */
  t15_2_B.DataStoreRead1_f = t15_2_DWork.RupRd[0];

  /* RelationalOperator: '<S60>/Relational Operator1' */
  t15_2_B.RelationalOperator1_f = (t15_2_B.e3 > t15_2_B.DataStoreRead1_f);

  /* Logic: '<S60>/Logical Operator2' */
  t15_2_B.LogicalOperator2_g = (t15_2_B.RelationalOperator_nb &&
    t15_2_B.RelationalOperator1_f);
  for (i = 0; i < 11; i++) {
    /* Gain: '<S52>/1e3' */
    t15_2_B.e3_h[i] = t15_2_P.e3_Gain_f * t15_2_B.e6_m[i];

    /* Abs: '<S52>/Abs' */
    t15_2_B.Abs_a[i] = fabs(t15_2_B.e3_h[i]);

    /* DataStoreRead: '<S15>/Data Store Read1' */
    t15_2_B.DataStoreRead1_k[i] = t15_2_DWork.Imax[i];

    /* Product: '<S52>/Divide5' incorporates:
     *  Constant: '<S52>/ntur(1:11)'
     */
    t15_2_B.Divide5[i] = t15_2_B.DataStoreRead1_k[i] * t15_2_P.ntur111_Value[i];

    /* Sum: '<S52>/Sum2' */
    t15_2_B.Sum2_k[i] = t15_2_B.Divide5[i] - t15_2_B.Abs_a[i];

    /* Product: '<S52>/Divide3' */
    t15_2_B.Divide3[i] = t15_2_B.Divide5[i] * t15_2_B.DataStoreRead1_kb;

    /* Sum: '<S52>/Sum1' */
    t15_2_B.Sum1[i] = t15_2_B.Divide5[i] - t15_2_B.Divide3[i];

    /* Product: '<S52>/Divide4' */
    t15_2_B.Divide4[i] = t15_2_B.Sum2_k[i] / t15_2_B.Sum1[i];

    /* Product: '<S52>/Divide1' */
    t15_2_B.Divide1_ps[i] = t15_2_B.Divide4[i] * t15_2_B.Divide4[i] *
      t15_2_B.Divide4[i];

    /* Saturate: '<S52>/Saturation' */
    tmin = t15_2_B.Divide1_ps[i];
    u = t15_2_P.Saturation_LowerSat_p;
    u_0 = t15_2_P.Saturation_UpperSat_cy;
    if (tmin >= u_0) {
      tmin = u_0;
    } else {
      if (tmin <= u) {
        tmin = u;
      }
    }

    t15_2_B.Saturation_k[i] = tmin;

    /* End of Saturate: '<S52>/Saturation' */

    /* RelationalOperator: '<S70>/Compare' incorporates:
     *  Constant: '<S70>/Constant'
     */
    t15_2_B.Compare_i[i] = (uint8_T)(t15_2_B.Saturation_k[i] <
      t15_2_P.Constant_Value_c);

    /* Memory: '<S60>/Memory1' */
    t15_2_B.Memory1_k[i] = t15_2_DWork.Memory1_PreviousInput_b[i];

    /* Memory: '<S63>/Memory' */
    t15_2_B.Memory[i] = t15_2_DWork.Memory_PreviousInput[i];
  }

  /* RelationalOperator: '<S76>/Compare' incorporates:
   *  Constant: '<S76>/Constant'
   */
  t15_2_B.Compare_l = (uint8_T)(t15_2_B.e6 < t15_2_P.Constant_Value_a);

  /* DataStoreRead: '<S77>/Data Store Read' */
  t15_2_B.DataStoreRead_j = t15_2_DWork.RupRd[0];

  /* RelationalOperator: '<S77>/Relational Operator' */
  t15_2_B.RelationalOperator_g4 = (t15_2_B.e3 > t15_2_B.DataStoreRead_j);

  /* DataStoreRead: '<S63>/Data Store Read1' */
  t15_2_B.DataStoreRead1_p = t15_2_DWork.RupRd[2];

  /* Abs: '<S63>/Abs' */
  t15_2_B.Abs_e = fabs(t15_2_B.DataStoreRead1_p);

  /* RelationalOperator: '<S63>/Relational Operator' */
  t15_2_B.RelationalOperator_pi = (t15_2_B.e6 > t15_2_B.Abs_e);

  /* Logic: '<S63>/Logical Operator1' */
  t15_2_B.LogicalOperator1_i = ((t15_2_B.Compare_l != 0) &&
    t15_2_B.RelationalOperator_g4 && t15_2_B.RelationalOperator_pi);

  /* Product: '<S15>/Divide2' */
  for (i = 0; i < 20; i++) {
    t15_2_B.Divide2_b[i] = t15_2_B.LogicalOperator1_h * t15_2_B.u9[i];
  }

  /* End of Product: '<S15>/Divide2' */

  /* DiscreteStateSpace: '<S54>/Div. contr.' */
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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

    t15_2_B.Divcontr[4] += (t15_2_P.Divcontr_D[68])*t15_2_B.Divide2_b[12];

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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
      real_T *y10 = &t15_2_B.Divcontr[10];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y10 += (*pD154++) * u[*pDidx++];
      }
    }
  }

  /* Switch: '<S63>/0.99' */
  if (t15_2_B.LogicalOperator1_i >= t15_2_P.u9_Threshold_k) {
    memcpy(&t15_2_B.u9_b[0], &t15_2_B.Memory[0], 11U * sizeof(real_T));
  } else {
    /* Sum: '<S50>/Subtract3' incorporates:
     *  Constant: '<S50>/1'
     */
    t15_2_B.Subtract3_h = t15_2_P._Value_n - t15_2_B.Saturation1;

    /* Product: '<S15>/Divide' */
    for (i = 0; i < 11; i++) {
      t15_2_B.Divide_e[i] = t15_2_B.Subtract3_h * t15_2_B.Divcontr[i];
      t15_2_B.u9_b[i] = t15_2_B.Divide_e[i];
    }

    /* End of Product: '<S15>/Divide' */
  }

  /* End of Switch: '<S63>/0.99' */

  /* Memory: '<S62>/Memory1' */
  t15_2_B.Memory1_ec = t15_2_DWork.Memory1_PreviousInput_o;

  /* RelationalOperator: '<S74>/Compare' incorporates:
   *  Constant: '<S74>/Constant'
   */
  t15_2_B.Compare_o = (uint8_T)(t15_2_B.e6 < t15_2_P.Constant_Value_b);

  /* DataStoreRead: '<S75>/Data Store Read' */
  t15_2_B.DataStoreRead_p = t15_2_DWork.RupRd[0];

  /* RelationalOperator: '<S75>/Relational Operator' */
  t15_2_B.RelationalOperator_m = (t15_2_B.e3 > t15_2_B.DataStoreRead_p);

  /* Logic: '<S62>/Logical Operator1' */
  t15_2_B.LogicalOperator1_a = ((t15_2_B.Compare_o != 0) &&
    t15_2_B.RelationalOperator_m);

  /* Switch: '<S62>/0.9999' */
  if (t15_2_B.LogicalOperator1_a > t15_2_P.u999_Threshold_i) {
    t15_2_B.u999_b = t15_2_B.Memory1_ec;
  } else {
    t15_2_B.u999_b = t15_2_B.e3;
  }

  /* End of Switch: '<S62>/0.9999' */

  /* Product: '<S15>/Divide13' */
  for (i = 0; i < 20; i++) {
    t15_2_B.Divide13[i] = t15_2_B.Divide2_b[i] * t15_2_B.LogicalOperator1_a;
  }

  /* End of Product: '<S15>/Divide13' */

  /* DiscreteStateSpace: '<S55>/Div_rd contr' */
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

  /* Memory: '<S59>/Memory1' */
  t15_2_B.Memory1_l = t15_2_DWork.Memory1_PreviousInput_f;

  /* Switch: '<S59>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_p) {
    for (i = 0; i < 500; i++) {
      /* DataStoreRead: '<S59>/Data Store Read1' */
      t15_2_B.DataStoreRead1_ph[i] = t15_2_DWork.scr_data[13 * i + 1];

      /* DataStoreRead: '<S59>/Data Store Read' */
      t15_2_B.DataStoreRead_h[i] = t15_2_DWork.scr_data[13 * i];
    }

    /* Dynamic Look-Up Table Block: '<S59>/Ipref'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(t15_2_B.Ipref), &t15_2_B.DataStoreRead1_ph[0],
                         t15_2_B.e3, &t15_2_B.DataStoreRead_h[0], 499U);
    t15_2_B.c_eob_e3 = t15_2_B.Ipref;
  } else {
    t15_2_B.c_eob_e3 = t15_2_B.Memory1_l;
  }

  /* End of Switch: '<S59>/c_eob' */

  /* Switch: '<S60>/0.999' */
  if (t15_2_B.LogicalOperator2_g > t15_2_P.u99_Threshold_c) {
    memcpy(&t15_2_B.u99_i[0], &t15_2_B.Memory1_k[0], 11U * sizeof(real_T));
  } else {
    /* Sum: '<S62>/Subtract2' */
    t15_2_B.Subtract2_b = t15_2_B.e3 - t15_2_B.u999_b;

    /* Gain: '<S62>/Gain1' */
    t15_2_B.Gain1_l = t15_2_P.Gain1_Gain_h * t15_2_B.Subtract2_b;

    /* Sum: '<S62>/Subtract3' incorporates:
     *  Constant: '<S62>/1'
     */
    t15_2_B.Subtract3_l = t15_2_B.Gain1_l + t15_2_P._Value;

    /* Saturate: '<S62>/Saturation' */
    tmin = t15_2_B.Subtract3_l;
    u = t15_2_P.Saturation_LowerSat_c;
    u_0 = t15_2_P.Saturation_UpperSat_c;
    if (tmin >= u_0) {
      t15_2_B.Saturation_i = u_0;
    } else if (tmin <= u) {
      t15_2_B.Saturation_i = u;
    } else {
      t15_2_B.Saturation_i = tmin;
    }

    /* End of Saturate: '<S62>/Saturation' */

    /* Sum: '<S62>/Subtract1' incorporates:
     *  Constant: '<S62>/1'
     */
    t15_2_B.Subtract1_l = t15_2_P._Value - t15_2_B.Saturation_i;

    /* Switch: '<S15>/c_eob' */
    if (t15_2_B.u_n > t15_2_P.c_eob_Threshold) {
      /* Gain: '<S15>/lim. gain' */
      t15_2_B.limgain = t15_2_P.limgain_Gain * t15_2_B.e6;

      /* Saturate: '<S15>/Saturation' */
      tmin = t15_2_B.limgain;
      u = t15_2_P.Saturation_LowerSat;
      u_0 = t15_2_P.Saturation_UpperSat;
      if (tmin >= u_0) {
        t15_2_B.Saturation_b = u_0;
      } else if (tmin <= u) {
        t15_2_B.Saturation_b = u;
      } else {
        t15_2_B.Saturation_b = tmin;
      }

      /* End of Saturate: '<S15>/Saturation' */
      t15_2_B.c_eob_bc = t15_2_B.Saturation_b;
    } else {
      /* Product: '<S59>/Divide6' */
      t15_2_B.Divide6_c = t15_2_B.c_eob_e3 * t15_2_B.u_n;

      /* Sum: '<S59>/Sum' incorporates:
       *  Constant: '<S59>/c1_y0'
       */
      t15_2_B.Sum = t15_2_B.Divide6_c - t15_2_P.c1_y0_Value;

      /* Product: '<S59>/Divide2' incorporates:
       *  Constant: '<S59>/(1-y0)//...'
       */
      t15_2_B.Divide2_n = t15_2_B.Sum * t15_2_P.uy0_Value;

      /* Sum: '<S59>/Sum1' incorporates:
       *  Constant: '<S59>/y0'
       */
      t15_2_B.Sum1_a = t15_2_B.Divide2_n + t15_2_P.y0_Value;

      /* Saturate: '<S59>/[1 y0]' */
      tmin = t15_2_B.Sum1_a;
      u = t15_2_P.uy0_LowerSat;
      u_0 = t15_2_P.uy0_UpperSat;
      if (tmin >= u_0) {
        t15_2_B.uy0 = u_0;
      } else if (tmin <= u) {
        t15_2_B.uy0 = u;
      } else {
        t15_2_B.uy0 = tmin;
      }

      /* End of Saturate: '<S59>/[1 y0]' */
      t15_2_B.c_eob_bc = t15_2_B.uy0;
    }

    for (i = 0; i < 11; i++) {
      /* Product: '<S15>/Divide3' */
      t15_2_B.Divide3_p[i] = t15_2_B.Div_rdcontr[i] * t15_2_B.c_eob_bc *
        t15_2_B.Subtract1_l;

      /* Product: '<S15>/Divide1' */
      t15_2_B.Divide1_jp[i] = t15_2_B.u9_b[i] * t15_2_B.Saturation_i;

      /* Sum: '<S15>/Sum2' */
      t15_2_B.Sum2_h[i] = t15_2_B.Divide1_jp[i] + t15_2_B.Divide3_p[i];
      t15_2_B.u99_i[i] = t15_2_B.Sum2_h[i];
    }

    /* End of Switch: '<S15>/c_eob' */
  }

  /* End of Switch: '<S60>/0.999' */

  /* DiscreteStateSpace: '<S53>/Curr. term. contr' */
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

  for (i = 0; i < 11; i++) {
    /* Product: '<S15>/Divide4' */
    t15_2_B.Divide4_p[i] = t15_2_B.u99_i[i] * t15_2_B.Saturation;

    /* Product: '<S15>/Divide5' */
    t15_2_B.Divide5_p[i] = t15_2_B.Currtermcontr[i] * t15_2_B.Subtract1_k;

    /* Memory: '<S56>/Memory2' */
    t15_2_B.Memory2_kr[i] = t15_2_DWork.Memory2_PreviousInput_dn[i];
  }

  /* Switch: '<S56>/tcont2 ' incorporates:
   *  Constant: '<S56>/zeros(20,1)'
   */
  for (i = 0; i < 20; i++) {
    if (t15_2_B.e3 > t15_2_P.tcont2_Threshold_f) {
      t15_2_B.tcont2[i] = t15_2_B.u9[i];
    } else {
      t15_2_B.tcont2[i] = t15_2_P.zeros201_Value[i];
    }
  }

  /* End of Switch: '<S56>/tcont2 ' */

  /* DiscreteStateSpace: '<S56>/Lim. contr.' */
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *y10 = &t15_2_B.Limcontr[10];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *y10 += (*pD170++) * u[*pDidx++];
      }
    }
  }

  /* DiscreteStateSpace: '<S56>/Curr. contr.' */
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

  /* Switch: '<S56>/Ip>Ip_div ' incorporates:
   *  Switch: '<S56>/tcont2'
   */
  if (t15_2_B.e6 > t15_2_P.IpIp_div_Threshold_l) {
    memcpy(&t15_2_B.IpIp_div[0], &t15_2_B.Memory2_kr[0], 11U * sizeof(real_T));
  } else {
    if (t15_2_B.e3 > t15_2_P.tcont2_Threshold) {
      /* Lookup: '<S56>/gain_cont2'
       * About '<S56>/gain_cont2':
       * Input0  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_real_T_real_T( &(t15_2_B.gain_cont2), t15_2_P.gain_cont2_YData,
                           t15_2_B.e3, t15_2_P.gain_cont2_XData, 3U);
      for (i = 0; i < 11; i++) {
        /* Product: '<S56>/Divide ' */
        t15_2_B.Divide_f[i] = t15_2_B.Limcontr[i] * t15_2_B.gain_cont2;
        t15_2_B.tcont2_a[i] = t15_2_B.Divide_f[i];
      }
    } else {
      for (i = 0; i < 11; i++) {
        /* Product: '<S56>/Divide 2' incorporates:
         *  Constant: '<S56>/ntur(1:11)'
         *  Switch: '<S56>/tcont2'
         */
        t15_2_B.Divide2_a[i] = t15_2_B.Currcontr[i] / t15_2_P.ntur111_Value_c[i];

        /* Switch: '<S56>/tcont2' */
        t15_2_B.tcont2_a[i] = t15_2_B.Divide2_a[i];
      }
    }

    memcpy(&t15_2_B.IpIp_div[0], &t15_2_B.tcont2_a[0], 11U * sizeof(real_T));
  }

  /* End of Switch: '<S56>/Ip>Ip_div ' */

  /* Product: '<S15>/Divide6' */
  for (i = 0; i < 11; i++) {
    t15_2_B.Divide6_l[i] = t15_2_B.Saturation1 * t15_2_B.IpIp_div[i];
  }

  for (i = 0; i < 500; i++) {
    /* DataStoreRead: '<S80>/Data Store Read' */
    t15_2_B.DataStoreRead_p1[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S80>/0.001' */
    t15_2_B.u01[i] = t15_2_P.u01_Gain * t15_2_B.DataStoreRead_p1[i];

    /* DataStoreRead: '<S80>/Data Store Read1' */
    t15_2_B.DataStoreRead1_d[i] = t15_2_DWork.volt[20 * i + 1];

    /* DataStoreRead: '<S83>/Data Store Read' */
    t15_2_B.DataStoreRead_a[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S83>/0.001' */
    t15_2_B.u01_o[i] = t15_2_P.u01_Gain_o * t15_2_B.DataStoreRead_a[i];

    /* DataStoreRead: '<S83>/Data Store Read1' */
    t15_2_B.DataStoreRead1_c[i] = t15_2_DWork.volt[20 * i + 2];

    /* DataStoreRead: '<S84>/Data Store Read' */
    t15_2_B.DataStoreRead_i1[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S84>/0.001' */
    t15_2_B.u01_g[i] = t15_2_P.u01_Gain_ox * t15_2_B.DataStoreRead_i1[i];

    /* DataStoreRead: '<S84>/Data Store Read1' */
    t15_2_B.DataStoreRead1_b[i] = t15_2_DWork.volt[20 * i + 3];

    /* DataStoreRead: '<S85>/Data Store Read' */
    t15_2_B.DataStoreRead_i2[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S85>/0.001' */
    t15_2_B.u01_b[i] = t15_2_P.u01_Gain_f * t15_2_B.DataStoreRead_i2[i];

    /* DataStoreRead: '<S85>/Data Store Read1' */
    t15_2_B.DataStoreRead1_e[i] = t15_2_DWork.volt[20 * i + 4];

    /* DataStoreRead: '<S86>/Data Store Read' */
    t15_2_B.DataStoreRead_n[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S86>/0.001' */
    t15_2_B.u01_h[i] = t15_2_P.u01_Gain_b * t15_2_B.DataStoreRead_n[i];

    /* DataStoreRead: '<S86>/Data Store Read1' */
    t15_2_B.DataStoreRead1_pd[i] = t15_2_DWork.volt[20 * i + 5];

    /* DataStoreRead: '<S87>/Data Store Read' */
    t15_2_B.DataStoreRead_oy[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S87>/0.001' */
    t15_2_B.u01_f[i] = t15_2_P.u01_Gain_e * t15_2_B.DataStoreRead_oy[i];

    /* DataStoreRead: '<S87>/Data Store Read1' */
    t15_2_B.DataStoreRead1_m[i] = t15_2_DWork.volt[20 * i + 6];

    /* DataStoreRead: '<S88>/Data Store Read' */
    t15_2_B.DataStoreRead_e[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S88>/0.001' */
    t15_2_B.u01_b3[i] = t15_2_P.u01_Gain_k * t15_2_B.DataStoreRead_e[i];

    /* DataStoreRead: '<S88>/Data Store Read1' */
    t15_2_B.DataStoreRead1_ee[i] = t15_2_DWork.volt[20 * i + 7];

    /* DataStoreRead: '<S89>/Data Store Read' */
    t15_2_B.DataStoreRead_g[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S89>/0.001' */
    t15_2_B.u01_bc[i] = t15_2_P.u01_Gain_d * t15_2_B.DataStoreRead_g[i];

    /* DataStoreRead: '<S89>/Data Store Read1' */
    t15_2_B.DataStoreRead1_cn[i] = t15_2_DWork.volt[20 * i + 8];

    /* DataStoreRead: '<S90>/Data Store Read' */
    t15_2_B.DataStoreRead_f3[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S90>/0.001' */
    t15_2_B.u01_l[i] = t15_2_P.u01_Gain_fh * t15_2_B.DataStoreRead_f3[i];

    /* DataStoreRead: '<S90>/Data Store Read1' */
    t15_2_B.DataStoreRead1_fq[i] = t15_2_DWork.volt[20 * i + 9];

    /* DataStoreRead: '<S81>/Data Store Read' */
    t15_2_B.DataStoreRead_ou[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S81>/0.001' */
    t15_2_B.u01_e[i] = t15_2_P.u01_Gain_l * t15_2_B.DataStoreRead_ou[i];

    /* DataStoreRead: '<S81>/Data Store Read1' */
    t15_2_B.DataStoreRead1_dy[i] = t15_2_DWork.volt[20 * i + 10];

    /* DataStoreRead: '<S82>/Data Store Read' */
    t15_2_B.DataStoreRead_fr[i] = t15_2_DWork.volt[20 * i];

    /* Gain: '<S82>/0.001' */
    t15_2_B.u01_f1[i] = t15_2_P.u01_Gain_ey * t15_2_B.DataStoreRead_fr[i];

    /* DataStoreRead: '<S82>/Data Store Read1' */
    t15_2_B.DataStoreRead1_n[i] = t15_2_DWork.volt[20 * i + 11];
  }

  /* End of Product: '<S15>/Divide6' */
  /* Dynamic Look-Up Table Block: '<S80>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1), &t15_2_B.DataStoreRead1_d[0],
                       t15_2_B.e3, &t15_2_B.u01[0], 499U);

  /* Dynamic Look-Up Table Block: '<S83>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_b), &t15_2_B.DataStoreRead1_c[0],
                       t15_2_B.e3, &t15_2_B.u01_o[0], 499U);

  /* Dynamic Look-Up Table Block: '<S84>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_i), &t15_2_B.DataStoreRead1_b[0],
                       t15_2_B.e3, &t15_2_B.u01_g[0], 499U);

  /* Dynamic Look-Up Table Block: '<S85>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_o), &t15_2_B.DataStoreRead1_e[0],
                       t15_2_B.e3, &t15_2_B.u01_b[0], 499U);

  /* Dynamic Look-Up Table Block: '<S86>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_d), &t15_2_B.DataStoreRead1_pd[0],
                       t15_2_B.e3, &t15_2_B.u01_h[0], 499U);

  /* Dynamic Look-Up Table Block: '<S87>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_m), &t15_2_B.DataStoreRead1_m[0],
                       t15_2_B.e3, &t15_2_B.u01_f[0], 499U);

  /* Dynamic Look-Up Table Block: '<S88>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_j), &t15_2_B.DataStoreRead1_ee[0],
                       t15_2_B.e3, &t15_2_B.u01_b3[0], 499U);

  /* Dynamic Look-Up Table Block: '<S89>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_b2), &t15_2_B.DataStoreRead1_cn[0],
                       t15_2_B.e3, &t15_2_B.u01_bc[0], 499U);

  /* Dynamic Look-Up Table Block: '<S90>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_ia), &t15_2_B.DataStoreRead1_fq[0],
                       t15_2_B.e3, &t15_2_B.u01_l[0], 499U);

  /* Dynamic Look-Up Table Block: '<S81>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_a), &t15_2_B.DataStoreRead1_dy[0],
                       t15_2_B.e3, &t15_2_B.u01_e[0], 499U);

  /* Dynamic Look-Up Table Block: '<S82>/volt1'
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Input2  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_T_real_T( &(t15_2_B.volt1_e), &t15_2_B.DataStoreRead1_n[0],
                       t15_2_B.e3, &t15_2_B.u01_f1[0], 499U);

  /* Product: '<S15>/Divide7' */
  t15_2_B.Divide7[0] = t15_2_B.volt1 * t15_2_B.Subtract4;
  t15_2_B.Divide7[1] = t15_2_B.volt1_b * t15_2_B.Subtract4;
  t15_2_B.Divide7[2] = t15_2_B.volt1_i * t15_2_B.Subtract4;
  t15_2_B.Divide7[3] = t15_2_B.volt1_o * t15_2_B.Subtract4;
  t15_2_B.Divide7[4] = t15_2_B.volt1_d * t15_2_B.Subtract4;
  t15_2_B.Divide7[5] = t15_2_B.volt1_m * t15_2_B.Subtract4;
  t15_2_B.Divide7[6] = t15_2_B.volt1_j * t15_2_B.Subtract4;
  t15_2_B.Divide7[7] = t15_2_B.volt1_b2 * t15_2_B.Subtract4;
  t15_2_B.Divide7[8] = t15_2_B.volt1_ia * t15_2_B.Subtract4;
  t15_2_B.Divide7[9] = t15_2_B.volt1_a * t15_2_B.Subtract4;
  t15_2_B.Divide7[10] = t15_2_B.volt1_e * t15_2_B.Subtract4;
  for (i = 0; i < 11; i++) {
    /* Sum: '<S15>/Sum3' */
    t15_2_B.Sum3[i] = ((t15_2_B.Divide4_p[i] + t15_2_B.Divide5_p[i]) +
                       t15_2_B.Divide6_l[i]) + t15_2_B.Divide7[i];

    /* Product: '<S52>/Divide2' */
    t15_2_B.Divide2_j[i] = t15_2_B.e6_m[i] * t15_2_B.Sum3[i];

    /* RelationalOperator: '<S71>/Compare' incorporates:
     *  Constant: '<S71>/Constant'
     */
    t15_2_B.Compare_p3[i] = (uint8_T)(t15_2_B.Divide2_j[i] <
      t15_2_P.Constant_Value_bp);

    /* Logic: '<S52>/Logical Operator' */
    t15_2_B.LogicalOperator[i] = ((t15_2_B.Compare_i[i] != 0) &&
      (t15_2_B.Compare_p3[i] != 0));

    /* Sum: '<S52>/Sum3' */
    t15_2_B.Sum3_b[i] = t15_2_B.Saturation_k[i] + (real_T)
      t15_2_B.LogicalOperator[i];

    /* Saturate: '<S52>/Saturation1' */
    tmin = t15_2_B.Sum3_b[i];
    u = t15_2_P.Saturation1_LowerSat_n;
    u_0 = t15_2_P.Saturation1_UpperSat_o;
    if (tmin >= u_0) {
      tmin = u_0;
    } else {
      if (tmin <= u) {
        tmin = u;
      }
    }

    t15_2_B.Saturation1_g[i] = tmin;

    /* End of Saturate: '<S52>/Saturation1' */

    /* Product: '<S52>/Divide6' */
    t15_2_B.Divide6_f[i] = t15_2_B.Sum3[i] * t15_2_B.Saturation1_g[i];
  }

  /* UniformRandomNumber: '<S61>/Uniform Random Number' */
  t15_2_B.UniformRandomNumber = t15_2_DWork.UniformRandomNumber_NextOutput;

  /* UnitDelay: '<S73>/UD' */
  t15_2_B.Uk1_m = t15_2_DWork.UD_DSTATE_c;

  /* Switch: '<S15>/t>t_tran2d' incorporates:
   *  Constant: '<S15>/zeros(2,1)'
   */
  if (t15_2_B.e3 > t15_2_P.tt_tran2d_Threshold) {
    /* Sum: '<S73>/Diff' */
    t15_2_B.Diff_f = t15_2_B.e3 - t15_2_B.Uk1_m;

    /* Gain: '<S72>/2e3' */
    t15_2_B.e3_i = t15_2_P.e3_Gain * t15_2_B.Diff_f;

    /* Sqrt: '<S72>/Sqrt' */
    t15_2_B.Sqrt = sqrt(t15_2_B.e3_i);

    /* DataStoreRead: '<S72>/Data Store Read' */
    t15_2_B.DataStoreRead_nz = t15_2_DWork.RupRd[5];

    /* Gain: '<S72>/1.75' */
    t15_2_B.u5 = t15_2_P.u5_Gain * t15_2_B.DataStoreRead_nz;

    /* Product: '<S72>/Divide11' */
    t15_2_B.Divide11_d = t15_2_B.UniformRandomNumber * t15_2_B.u5;

    /* Product: '<S72>/Divide1' */
    t15_2_B.Divide1_g = t15_2_B.Divide11_d / t15_2_B.Sqrt;

    /* Sum: '<S25>/Diff' */
    t15_2_B.Diff_o = t15_2_B.e3 - t15_2_B.Uk1_d;

    /* Sum: '<S24>/Diff' incorporates:
     *  Inport: '<Root>/In1'
     */
    t15_2_B.Diff_n = t15_2_U.In1[0] - t15_2_B.Uk1;

    /* Product: '<S18>/Divide' */
    t15_2_B.Divide_c = t15_2_B.Diff_n / t15_2_B.Diff_o;

    /* Sum: '<S61>/Sum2' */
    t15_2_B.Sum2_e = t15_2_B.Divide1_g + t15_2_B.Divide_c;
    t15_2_B.tt_tran2d[0] = t15_2_B.Sum2_e;
    t15_2_B.tt_tran2d[1] = t15_2_B.e6_m[11];
  } else {
    t15_2_B.tt_tran2d[0] = t15_2_P.zeros21_Value[0];
    t15_2_B.tt_tran2d[1] = t15_2_P.zeros21_Value[1];
  }

  /* End of Switch: '<S15>/t>t_tran2d' */

  /* DiscreteStateSpace: '<S57>/VS. contr' */
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

    t15_2_B.VScontr[0] += (t15_2_P.VScontr_D[0])*t15_2_B.tt_tran2d[0] +
      (t15_2_P.VScontr_D[1])*t15_2_B.tt_tran2d[1];

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

    t15_2_B.VScontr[1] += (t15_2_P.VScontr_D[2])*t15_2_B.tt_tran2d[0] +
      (t15_2_P.VScontr_D[3])*t15_2_B.tt_tran2d[1];
  }

  /* RelationalOperator: '<S57>/Relational Operator' incorporates:
   *  Constant: '<S57>/c_eob '
   */
  t15_2_B.RelationalOperator_g = (t15_2_B.u_n < t15_2_P.c_eob_Value);

  /* Product: '<S57>/Divide4' */
  t15_2_B.Divide4_j[0] = t15_2_B.RelationalOperator_g * t15_2_B.tt_tran2d[0];
  t15_2_B.Divide4_j[1] = t15_2_B.RelationalOperator_g * t15_2_B.tt_tran2d[1];

  /* DiscreteStateSpace: '<S57>/VS. contr hl' */
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

    t15_2_B.VScontrhl[0] += (t15_2_P.VScontrhl_D[0])*t15_2_B.Divide4_j[0] +
      (t15_2_P.VScontrhl_D[1])*t15_2_B.Divide4_j[1];
    t15_2_B.VScontrhl[1] = (t15_2_P.VScontrhl_C[5])*
      t15_2_DWork.VScontrhl_DSTATE[0] + (t15_2_P.VScontrhl_C[6])*
      t15_2_DWork.VScontrhl_DSTATE[1]
      + (t15_2_P.VScontrhl_C[7])*t15_2_DWork.VScontrhl_DSTATE[2]
      + (t15_2_P.VScontrhl_C[8])*t15_2_DWork.VScontrhl_DSTATE[7];
    t15_2_B.VScontrhl[1] += (t15_2_P.VScontrhl_D[2])*t15_2_B.Divide4_j[0] +
      (t15_2_P.VScontrhl_D[3])*t15_2_B.Divide4_j[1];
  }

  /* Switch: '<S57>/c_eob' */
  if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_lk) {
    t15_2_B.c_eob_ku[0] = t15_2_B.VScontr[0];
    t15_2_B.c_eob_ku[1] = t15_2_B.VScontr[1];
  } else {
    t15_2_B.c_eob_ku[0] = t15_2_B.VScontrhl[0];
    t15_2_B.c_eob_ku[1] = t15_2_B.VScontrhl[1];
  }

  /* End of Switch: '<S57>/c_eob' */

  /* RelationalOperator: '<S78>/Compare' incorporates:
   *  Constant: '<S78>/Constant'
   */
  t15_2_B.Compare_d = (uint8_T)(t15_2_B.e6 < t15_2_P.Constant_Value_k);

  /* DataStoreRead: '<S79>/Data Store Read' */
  t15_2_B.DataStoreRead_gb = t15_2_DWork.RupRd[0];

  /* RelationalOperator: '<S79>/Relational Operator' */
  t15_2_B.RelationalOperator_o = (t15_2_B.e3 > t15_2_B.DataStoreRead_gb);

  /* DataStoreRead: '<S64>/Data Store Read' */
  t15_2_B.DataStoreRead_b = t15_2_DWork.RupRd[2];

  /* Abs: '<S64>/Abs' */
  t15_2_B.Abs_l = fabs(t15_2_B.DataStoreRead_b);

  /* RelationalOperator: '<S64>/Relational Operator' */
  t15_2_B.RelationalOperator_c = (t15_2_B.e6 > t15_2_B.Abs_l);

  /* Logic: '<S64>/Logical Operator1' */
  t15_2_B.LogicalOperator1_k = ((t15_2_B.Compare_d != 0) &&
    t15_2_B.RelationalOperator_o && t15_2_B.RelationalOperator_c);

  /* Gain: '<S58>/atpl1//15' */
  t15_2_B.atpl115 = t15_2_P.atpl115_Gain * t15_2_B.e6;

  /* Switch: '<S64>/0.99' incorporates:
   *  Switch: '<S15>/c_eob '
   */
  if (t15_2_B.LogicalOperator1_k >= t15_2_P.u9_Threshold_n) {
    /* Gain: '<S15>/VS gain 3' */
    t15_2_B.VSgain3 = t15_2_P.VSgain3_Gain * t15_2_B.e6;

    /* Saturate: '<S15>/Saturation4' */
    tmin = t15_2_B.VSgain3;
    u = t15_2_P.Saturation4_LowerSat;
    u_0 = t15_2_P.Saturation4_UpperSat;
    if (tmin >= u_0) {
      t15_2_B.Saturation4 = u_0;
    } else if (tmin <= u) {
      t15_2_B.Saturation4 = u;
    } else {
      t15_2_B.Saturation4 = tmin;
    }

    /* End of Saturate: '<S15>/Saturation4' */

    /* Product: '<S15>/Divide11' */
    t15_2_B.Divide11[0] = t15_2_B.Saturation4 * t15_2_B.c_eob_ku[0];
    t15_2_B.Divide11[1] = t15_2_B.Saturation4 * t15_2_B.c_eob_ku[1];
    t15_2_B.u9_o[0] = t15_2_B.Divide11[0];
    t15_2_B.u9_o[1] = t15_2_B.Divide11[1];
  } else {
    if (t15_2_B.u_n > t15_2_P.c_eob_Threshold_i) {
      /* Switch: '<S58>/Ip>Ip_div' incorporates:
       *  Switch: '<S15>/c_eob '
       */
      if (t15_2_B.e6 > t15_2_P.IpIp_div_Threshold) {
        /* Saturate: '<S58>/Sat. Div' */
        tmin = t15_2_B.atpl115;
        u = t15_2_P.SatDiv_LowerSat;
        u_0 = t15_2_P.SatDiv_UpperSat;
        if (tmin >= u_0) {
          t15_2_B.SatDiv = u_0;
        } else if (tmin <= u) {
          t15_2_B.SatDiv = u;
        } else {
          t15_2_B.SatDiv = tmin;
        }

        /* End of Saturate: '<S58>/Sat. Div' */
        t15_2_B.IpIp_div_b = t15_2_B.SatDiv;
      } else {
        /* Saturate: '<S58>/Sat. Lim' */
        tmin = t15_2_B.atpl115;
        u = t15_2_P.SatLim_LowerSat;
        u_0 = t15_2_P.SatLim_UpperSat;
        if (tmin >= u_0) {
          t15_2_B.SatLim = u_0;
        } else if (tmin <= u) {
          t15_2_B.SatLim = u;
        } else {
          t15_2_B.SatLim = tmin;
        }

        /* End of Saturate: '<S58>/Sat. Lim' */
        t15_2_B.IpIp_div_b = t15_2_B.SatLim;
      }

      /* End of Switch: '<S58>/Ip>Ip_div' */

      /* Product: '<S15>/Divide8' incorporates:
       *  Switch: '<S15>/c_eob '
       */
      t15_2_B.Divide8[0] = t15_2_B.IpIp_div_b * t15_2_B.c_eob_ku[0];
      t15_2_B.Divide8[1] = t15_2_B.IpIp_div_b * t15_2_B.c_eob_ku[1];

      /* Switch: '<S15>/c_eob ' */
      t15_2_B.c_eob_b4[0] = t15_2_B.Divide8[0];
      t15_2_B.c_eob_b4[1] = t15_2_B.Divide8[1];
    } else {
      /* Gain: '<S15>/VS gain 2' incorporates:
       *  Switch: '<S15>/c_eob '
       */
      t15_2_B.VSgain2 = t15_2_P.VSgain2_Gain * t15_2_B.e6;

      /* Saturate: '<S15>/Saturation3' incorporates:
       *  Switch: '<S15>/c_eob '
       */
      tmin = t15_2_B.VSgain2;
      u = t15_2_P.Saturation3_LowerSat;
      u_0 = t15_2_P.Saturation3_UpperSat;
      if (tmin >= u_0) {
        t15_2_B.Saturation3 = u_0;
      } else if (tmin <= u) {
        t15_2_B.Saturation3 = u;
      } else {
        t15_2_B.Saturation3 = tmin;
      }

      /* End of Saturate: '<S15>/Saturation3' */

      /* Product: '<S15>/Divide ' incorporates:
       *  Switch: '<S15>/c_eob '
       */
      t15_2_B.Divide_g[0] = t15_2_B.c_eob_ku[0] * t15_2_B.Saturation3;
      t15_2_B.Divide_g[1] = t15_2_B.c_eob_ku[1] * t15_2_B.Saturation3;

      /* Switch: '<S15>/c_eob ' */
      t15_2_B.c_eob_b4[0] = t15_2_B.Divide_g[0];
      t15_2_B.c_eob_b4[1] = t15_2_B.Divide_g[1];
    }

    t15_2_B.u9_o[0] = t15_2_B.c_eob_b4[0];
    t15_2_B.u9_o[1] = t15_2_B.c_eob_b4[1];
  }

  /* End of Switch: '<S64>/0.99' */

  /* Product: '<S15>/Divide10' */
  t15_2_B.Divide10[0] = t15_2_B.Subtract4 * t15_2_B.u9_o[0];
  t15_2_B.Divide10[1] = t15_2_B.Subtract4 * t15_2_B.u9_o[1];

  /* Product: '<S15>/Divide12' */
  for (i = 0; i < 20; i++) {
    t15_2_B.Divide12[i] = t15_2_B.Divide2_b[i] * t15_2_B.LogicalOperator2;
  }

  for (i = 0; i < 11; i++) {
    /* Product: '<S56>/Divide 1' incorporates:
     *  Constant: '<S56>/ntur(1:11)'
     */
    t15_2_B.Divide1_j[i] = t15_2_B.u9[i + 8] / t15_2_P.ntur111_Value_c[i];

    /* Product: '<S5>/Divide4' incorporates:
     *  Constant: '<S5>/ntur(1:11)'
     */
    t15_2_B.Divide4_f[i] = t15_2_P.ntur111_Value_a[i] * t15_2_B.Divide6_f[i];
  }

  /* End of Product: '<S15>/Divide12' */

  /* Level2 S-Function Block: '<S1>/S-Function' (read_tt_kavin2) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[15];
    sfcnOutputs(rts, 0);
  }

  /* DataStoreWrite: '<S1>/Data Store Write2' */
  for (i = 0; i < 6; i++) {
    t15_2_DWork.RupRd[i] = t15_2_B.SFunction[i];
  }

  /* End of DataStoreWrite: '<S1>/Data Store Write2' */

  /* DataStoreWrite: '<S1>/Data Store Write3' */
  t15_2_DWork.VS3_up = t15_2_B.SFunction[7];

  /* DataStoreWrite: '<S1>/Data Store Write5' */
  t15_2_DWork.VS1_up = t15_2_B.SFunction[6];

  /* DataStoreWrite: '<S1>/Data Store Write7' */
  t15_2_DWork.Tu = t15_2_B.SFunction[19];

  /* DataStoreWrite: '<S1>/Data Store Write8' */
  t15_2_DWork.c_cur_max = t15_2_B.SFunction[20];

  /* DataStoreRead: '<S8>/Data Store Read3' */
  t15_2_B.DataStoreRead3 = t15_2_DWork.Tu;

  /* UnitDelay: '<S6>/UD' */
  t15_2_B.Uk1_l = t15_2_DWork.UD_DSTATE_i;

  /* Sum: '<S6>/Diff' */
  t15_2_B.Diff = t15_2_B.e3 - t15_2_B.Uk1_l;
  for (i = 0; i < 11; i++) {
    /* DataStoreWrite: '<S1>/Data Store Write4' */
    t15_2_DWork.Vcspf_up[i] = t15_2_B.SFunction[i + 8];

    /* DataStoreWrite: '<S1>/Data Store Write9' */
    t15_2_DWork.Imax[i] = t15_2_B.SFunction[i + 21];

    /* DataStoreRead: '<S9>/Data Store Read1' */
    t15_2_B.DataStoreRead1_kx[i] = t15_2_DWork.Vcspf_up[i];

    /* Memory: '<S7>/Memory1' */
    t15_2_B.Memory1_ek[i] = t15_2_DWork.Memory1_PreviousInput_p2[i];

    /* DataStoreRead: '<S8>/Data Store Read1' */
    t15_2_B.DataStoreRead1_o[i] = t15_2_DWork.Vcspf_up[i];

    /* Gain: '<S8>/2' */
    t15_2_B.u_j[i] = t15_2_P._Gain * t15_2_B.DataStoreRead1_o[i];

    /* Product: '<S8>/Divide1' */
    t15_2_B.Divide1_o5[i] = t15_2_B.u_j[i] / t15_2_B.DataStoreRead3;

    /* Sum: '<S7>/Add1' */
    t15_2_B.Add1_gy[i] = t15_2_B.Divide4_f[i] - t15_2_B.Memory1_ek[i];

    /* Product: '<S7>/Divide' */
    t15_2_B.Divide[i] = t15_2_B.Add1_gy[i] / t15_2_B.Diff;

    /* RelationalOperator: '<S10>/LowerRelop1' */
    t15_2_B.LowerRelop1[i] = (t15_2_B.Divide[i] > t15_2_B.Divide1_o5[i]);

    /* Gain: '<S8>/-1' */
    t15_2_B.u_e[i] = t15_2_P.u_Gain_e * t15_2_B.Divide1_o5[i];

    /* RelationalOperator: '<S10>/UpperRelop' */
    t15_2_B.UpperRelop[i] = (t15_2_B.Divide[i] < t15_2_B.u_e[i]);

    /* Switch: '<S10>/Switch' */
    if (t15_2_B.UpperRelop[i]) {
      t15_2_B.Switch[i] = t15_2_B.u_e[i];
    } else {
      t15_2_B.Switch[i] = t15_2_B.Divide[i];
    }

    /* End of Switch: '<S10>/Switch' */

    /* Switch: '<S10>/Switch2' */
    if (t15_2_B.LowerRelop1[i]) {
      t15_2_B.Switch2[i] = t15_2_B.Divide1_o5[i];
    } else {
      t15_2_B.Switch2[i] = t15_2_B.Switch[i];
    }

    /* End of Switch: '<S10>/Switch2' */

    /* Product: '<S7>/Divide1' */
    t15_2_B.Divide1_k[i] = t15_2_B.Switch2[i] * t15_2_B.Diff;

    /* Sum: '<S7>/Add2' */
    t15_2_B.Add2_n[i] = t15_2_B.Memory1_ek[i] + t15_2_B.Divide1_k[i];

    /* RelationalOperator: '<S11>/LowerRelop1' */
    t15_2_B.LowerRelop1_g[i] = (t15_2_B.Add2_n[i] > t15_2_B.DataStoreRead1_kx[i]);

    /* Gain: '<S9>/Gain' */
    t15_2_B.Gain[i] = t15_2_P.Gain_Gain_f * t15_2_B.DataStoreRead1_kx[i];

    /* RelationalOperator: '<S11>/UpperRelop' */
    t15_2_B.UpperRelop_c[i] = (t15_2_B.Add2_n[i] < t15_2_B.Gain[i]);

    /* Switch: '<S11>/Switch' */
    if (t15_2_B.UpperRelop_c[i]) {
      t15_2_B.Switch_l[i] = t15_2_B.Gain[i];
    } else {
      t15_2_B.Switch_l[i] = t15_2_B.Add2_n[i];
    }

    /* End of Switch: '<S11>/Switch' */

    /* Switch: '<S11>/Switch2' */
    if (t15_2_B.LowerRelop1_g[i]) {
      t15_2_B.Switch2_c[i] = t15_2_B.DataStoreRead1_kx[i];
    } else {
      t15_2_B.Switch2_c[i] = t15_2_B.Switch_l[i];
    }

    /* End of Switch: '<S11>/Switch2' */

    /* Gain: '<S2>/1//ntur' */
    t15_2_B.ntur[i] = t15_2_P.ntur_Gain[i] * t15_2_B.Switch2_c[i];
  }

  /* DataStoreRead: '<S4>/Data Store Read1' */
  t15_2_B.DataStoreRead1_j = t15_2_DWork.VS1_up;

  /* RelationalOperator: '<S12>/LowerRelop1' */
  t15_2_B.LowerRelop1_j = (t15_2_B.Divide10[0] > t15_2_B.DataStoreRead1_j);

  /* Switch: '<S12>/Switch2' */
  if (t15_2_B.LowerRelop1_j) {
    t15_2_B.Switch2_h = t15_2_B.DataStoreRead1_j;
  } else {
    /* Gain: '<S4>/Gain' */
    t15_2_B.Gain_l = t15_2_P.Gain_Gain * t15_2_B.DataStoreRead1_j;

    /* RelationalOperator: '<S12>/UpperRelop' */
    t15_2_B.UpperRelop_m = (t15_2_B.Divide10[0] < t15_2_B.Gain_l);

    /* Switch: '<S12>/Switch' */
    if (t15_2_B.UpperRelop_m) {
      t15_2_B.Switch_k = t15_2_B.Gain_l;
    } else {
      t15_2_B.Switch_k = t15_2_B.Divide10[0];
    }

    /* End of Switch: '<S12>/Switch' */
    t15_2_B.Switch2_h = t15_2_B.Switch_k;
  }

  /* End of Switch: '<S12>/Switch2' */

  /* DataStoreRead: '<S4>/Data Store Read3' */
  t15_2_B.DataStoreRead3_a = t15_2_DWork.VS3_up;

  /* RelationalOperator: '<S13>/LowerRelop1' */
  t15_2_B.LowerRelop1_j5 = (t15_2_B.Divide10[1] > t15_2_B.DataStoreRead3_a);

  /* Switch: '<S13>/Switch2' */
  if (t15_2_B.LowerRelop1_j5) {
    t15_2_B.Switch2_f = t15_2_B.DataStoreRead3_a;
  } else {
    /* Gain: '<S4>/Gain1' */
    t15_2_B.Gain1_h = t15_2_P.Gain1_Gain * t15_2_B.DataStoreRead3_a;

    /* RelationalOperator: '<S13>/UpperRelop' */
    t15_2_B.UpperRelop_d = (t15_2_B.Divide10[1] < t15_2_B.Gain1_h);

    /* Switch: '<S13>/Switch' */
    if (t15_2_B.UpperRelop_d) {
      t15_2_B.Switch_c = t15_2_B.Gain1_h;
    } else {
      t15_2_B.Switch_c = t15_2_B.Divide10[1];
    }

    /* End of Switch: '<S13>/Switch' */
    t15_2_B.Switch2_f = t15_2_B.Switch_c;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* SignalConversion: '<S2>/TmpSignal ConversionAtwzInport1' */
  t15_2_B.TmpSignalConversionAtwzInport1[0] = t15_2_B.Switch2_h;
  t15_2_B.TmpSignalConversionAtwzInport1[1] = t15_2_B.Switch2_f;

  /* Gain: '<S2>/wz' */
  for (i = 0; i < 12; i++) {
    t15_2_B.wz[i] = 0.0;
    t15_2_B.wz[i] += t15_2_P.wz_Gain[i] *
      t15_2_B.TmpSignalConversionAtwzInport1[0];
    t15_2_B.wz[i] += t15_2_P.wz_Gain[i + 12] *
      t15_2_B.TmpSignalConversionAtwzInport1[1];
  }

  for (i = 0; i < 11; i++) {
    /* Sum: '<S2>/Add1' */
    t15_2_B.Add1_k[i] = t15_2_B.ntur[i] + t15_2_B.wz[i];

    /* SignalConversion: '<S2>/TmpSignal ConversionAtnpf,12Inport1' */
    t15_2_B.TmpSignalConversionAtnpf12Inpor[i] = t15_2_B.Add1_k[i];
  }

  /* End of Gain: '<S2>/wz' */

  /* SignalConversion: '<S2>/TmpSignal ConversionAtnpf,12Inport1' */
  t15_2_B.TmpSignalConversionAtnpf12Inpor[11] = t15_2_B.wz[11];
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
  memcpy(&t15_2_Y.to_DINA[15], &t15_2_B.ntur[0], 11U * sizeof(real_T));
  memcpy(&t15_2_Y.to_DINA[26], &t15_2_B.wz[0], 12U * sizeof(real_T));

  /* Update for Memory: '<S5>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput = t15_2_B.Ip1e4;

  /* Update for Memory: '<S23>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_k = t15_2_B.e6_i;

  /* Update for Memory: '<S23>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput = t15_2_B.u99;

  /* Update for Memory: '<S17>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_c = t15_2_B.c_eob;

  /* Update for UnitDelay: '<S24>/UD' incorporates:
   *  Inport: '<Root>/In1'
   */
  t15_2_DWork.UD_DSTATE = t15_2_U.In1[0];

  /* Update for UnitDelay: '<S25>/UD' */
  t15_2_DWork.UD_DSTATE_j = t15_2_B.e3;

  /* Update for Memory: '<S29>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_m = t15_2_B.c_eob_b;

  /* Update for Memory: '<S27>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_b = t15_2_B.c_eob_c;

  /* Update for Memory: '<S28>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_a = t15_2_B.c_eob_h;

  /* Update for Memory: '<S30>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_d = t15_2_B.c_eob_e;

  /* Update for Memory: '<S26>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_c = t15_2_B.c_eob_cj;

  /* Update for Memory: '<S31>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_e = t15_2_B.c_eob_k;

  /* Update for Memory: '<S32>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_o = t15_2_B.c_eob_g;

  /* Update for Memory: '<S33>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_eq = t15_2_B.c_eob_l;

  /* Update for Memory: '<S34>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_bf = t15_2_B.c_eob_g0;

  /* Update for Memory: '<S35>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_l = t15_2_B.c_eob_bz;

  /* Update for Memory: '<S36>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_j = t15_2_B.c_eob_j;

  /* Update for Memory: '<S42>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_o4 = t15_2_B.c_eob1;

  /* Update for Memory: '<S42>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_g = t15_2_B.c_eob_ej;

  /* Update for Memory: '<S37>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_mw = t15_2_B.c_eob1_b;

  /* Update for Memory: '<S37>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_d = t15_2_B.c_eob_n;

  /* Update for Memory: '<S38>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_h = t15_2_B.c_eob1_i;

  /* Update for Memory: '<S38>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_p = t15_2_B.c_eob_lg;

  /* Update for Memory: '<S39>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_g = t15_2_B.c_eob1_d;

  /* Update for Memory: '<S39>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_h = t15_2_B.c_eob_c2;

  /* Update for Memory: '<S40>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_oh = t15_2_B.c_eob1_c;

  /* Update for Memory: '<S40>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_gk = t15_2_B.c_eob_nk;

  /* Update for Memory: '<S41>/Memory2' */
  t15_2_DWork.Memory2_PreviousInput_ef = t15_2_B.c_eob1_g;

  /* Update for Memory: '<S41>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_j = t15_2_B.c_eob_be;

  /* Update for Memory: '<S50>/Memory3' */
  t15_2_DWork.Memory3_PreviousInput = t15_2_B.u999;

  /* Update for Memory: '<S51>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_l = t15_2_B.u999_d;

  /* Update for DiscreteStateSpace: '<S54>/Div. contr.' */
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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
      const real_T *u = &t15_2_B.Divide2_b[0];
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

    xnew[20] += (t15_2_P.Divcontr_B[340])*t15_2_B.Divide2_b[12];

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

    xnew[21] += (t15_2_P.Divcontr_B[341])*t15_2_B.Divide2_b[12];

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

    xnew[22] += (t15_2_P.Divcontr_B[342])*t15_2_B.Divide2_b[12];

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

    xnew[23] += (t15_2_P.Divcontr_B[343])*t15_2_B.Divide2_b[12];

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

    xnew[24] += (t15_2_P.Divcontr_B[344])*t15_2_B.Divide2_b[12];
    xnew[25] = (t15_2_P.Divcontr_A[565])*t15_2_DWork.Divcontr_DSTATE[25];
    xnew[25] += (t15_2_P.Divcontr_B[345])*t15_2_B.Divide2_b[0];
    xnew[26] = (t15_2_P.Divcontr_A[566])*t15_2_DWork.Divcontr_DSTATE[26];
    xnew[26] += (t15_2_P.Divcontr_B[346])*t15_2_B.Divide2_b[1];
    xnew[27] = (t15_2_P.Divcontr_A[567])*t15_2_DWork.Divcontr_DSTATE[27];
    xnew[27] += (t15_2_P.Divcontr_B[347])*t15_2_B.Divide2_b[2];
    xnew[28] = (t15_2_P.Divcontr_A[568])*t15_2_DWork.Divcontr_DSTATE[28];
    xnew[28] += (t15_2_P.Divcontr_B[348])*t15_2_B.Divide2_b[3];
    xnew[29] = (t15_2_P.Divcontr_A[569])*t15_2_DWork.Divcontr_DSTATE[29];
    xnew[29] += (t15_2_P.Divcontr_B[349])*t15_2_B.Divide2_b[4];
    xnew[30] = (t15_2_P.Divcontr_A[570])*t15_2_DWork.Divcontr_DSTATE[30];
    xnew[30] += (t15_2_P.Divcontr_B[350])*t15_2_B.Divide2_b[5];
    xnew[31] = (t15_2_P.Divcontr_A[571])*t15_2_DWork.Divcontr_DSTATE[31];
    xnew[31] += (t15_2_P.Divcontr_B[351])*t15_2_B.Divide2_b[7];
    (void) memcpy(&t15_2_DWork.Divcontr_DSTATE[0], xnew,
                  sizeof(real_T)*32);
  }

  /* Update for Memory: '<S62>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_o = t15_2_B.u999_b;

  /* Update for DiscreteStateSpace: '<S55>/Div_rd contr' */
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

  /* Update for Memory: '<S59>/Memory1' */
  t15_2_DWork.Memory1_PreviousInput_f = t15_2_B.c_eob_e3;

  /* Update for DiscreteStateSpace: '<S53>/Curr. term. contr' */
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

    (void) memcpy(&t15_2_DWork.Currtermcontr_DSTATE[0], xnew,
                  sizeof(real_T)*22);
  }

  /* Update for DiscreteStateSpace: '<S56>/Lim. contr.' */
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
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
      const real_T *u = &t15_2_B.tcont2[0];
      real_T *pxnew45 = &xnew[45];
      int_T numNonZero = 17;
      while (numNonZero--) {
        *pxnew45 += (*pB765++) * u[*pBidx++];
      }
    }

    (void) memcpy(&t15_2_DWork.Limcontr_DSTATE[0], xnew,
                  sizeof(real_T)*46);
  }

  /* Update for DiscreteStateSpace: '<S56>/Curr. contr.' */
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
      const real_T *u = &t15_2_B.Divide1_j[0];
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
      const real_T *u = &t15_2_B.Divide1_j[0];
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
      const real_T *u = &t15_2_B.Divide1_j[0];
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
      const real_T *u = &t15_2_B.Divide1_j[0];
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
      const real_T *u = &t15_2_B.Divide1_j[0];
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
      const real_T *u = &t15_2_B.Divide1_j[0];
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
      const real_T *u = &t15_2_B.Divide1_j[0];
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
      const real_T *u = &t15_2_B.Divide1_j[0];
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
      const real_T *u = &t15_2_B.Divide1_j[0];
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
      const real_T *u = &t15_2_B.Divide1_j[0];
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
      const real_T *u = &t15_2_B.Divide1_j[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 11;
      while (numNonZero--) {
        *pxnew10 += (*pB110++) * u[*pBidx++];
      }
    }

    (void) memcpy(&t15_2_DWork.Currcontr_DSTATE[0], xnew,
                  sizeof(real_T)*11);
  }

  /* Update for UniformRandomNumber: '<S61>/Uniform Random Number' */
  tmin = t15_2_P.UniformRandomNumber_Minimum;
  t15_2_DWork.UniformRandomNumber_NextOutput =
    (t15_2_P.UniformRandomNumber_Maximum - tmin) * rt_urand_Upu32_Yd_f_pw_snf
    (&t15_2_DWork.RandSeed) + tmin;

  /* Update for UnitDelay: '<S73>/UD' */
  t15_2_DWork.UD_DSTATE_c = t15_2_B.e3;

  /* Update for DiscreteStateSpace: '<S57>/VS. contr' */
  {
    real_T xnew[9];
    xnew[0] = (t15_2_P.VScontr_A[0])*t15_2_DWork.VScontr_DSTATE[0] +
      (t15_2_P.VScontr_A[1])*t15_2_DWork.VScontr_DSTATE[1]
      + (t15_2_P.VScontr_A[2])*t15_2_DWork.VScontr_DSTATE[2]
      + (t15_2_P.VScontr_A[3])*t15_2_DWork.VScontr_DSTATE[7];
    xnew[0] += (t15_2_P.VScontr_B[0])*t15_2_B.tt_tran2d[0] + (t15_2_P.VScontr_B
      [1])*t15_2_B.tt_tran2d[1];
    xnew[1] = (t15_2_P.VScontr_A[4])*t15_2_DWork.VScontr_DSTATE[0] +
      (t15_2_P.VScontr_A[5])*t15_2_DWork.VScontr_DSTATE[1]
      + (t15_2_P.VScontr_A[6])*t15_2_DWork.VScontr_DSTATE[2]
      + (t15_2_P.VScontr_A[7])*t15_2_DWork.VScontr_DSTATE[7];
    xnew[1] += (t15_2_P.VScontr_B[2])*t15_2_B.tt_tran2d[0] + (t15_2_P.VScontr_B
      [3])*t15_2_B.tt_tran2d[1];
    xnew[2] = (t15_2_P.VScontr_A[8])*t15_2_DWork.VScontr_DSTATE[0] +
      (t15_2_P.VScontr_A[9])*t15_2_DWork.VScontr_DSTATE[1]
      + (t15_2_P.VScontr_A[10])*t15_2_DWork.VScontr_DSTATE[2]
      + (t15_2_P.VScontr_A[11])*t15_2_DWork.VScontr_DSTATE[7];
    xnew[2] += (t15_2_P.VScontr_B[4])*t15_2_B.tt_tran2d[0] + (t15_2_P.VScontr_B
      [5])*t15_2_B.tt_tran2d[1];

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

    xnew[3] += (t15_2_P.VScontr_B[6])*t15_2_B.tt_tran2d[0] + (t15_2_P.VScontr_B
      [7])*t15_2_B.tt_tran2d[1];

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

    xnew[4] += (t15_2_P.VScontr_B[8])*t15_2_B.tt_tran2d[0] + (t15_2_P.VScontr_B
      [9])*t15_2_B.tt_tran2d[1];

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
    (void) memcpy(&t15_2_DWork.VScontr_DSTATE[0], xnew,
                  sizeof(real_T)*9);
  }

  /* Update for DiscreteStateSpace: '<S57>/VS. contr hl' */
  {
    real_T xnew[8];
    xnew[0] = (t15_2_P.VScontrhl_A[0])*t15_2_DWork.VScontrhl_DSTATE[0] +
      (t15_2_P.VScontrhl_A[1])*t15_2_DWork.VScontrhl_DSTATE[1]
      + (t15_2_P.VScontrhl_A[2])*t15_2_DWork.VScontrhl_DSTATE[2]
      + (t15_2_P.VScontrhl_A[3])*t15_2_DWork.VScontrhl_DSTATE[7];
    xnew[0] += (t15_2_P.VScontrhl_B[0])*t15_2_B.Divide4_j[0] +
      (t15_2_P.VScontrhl_B[1])*t15_2_B.Divide4_j[1];
    xnew[1] = (t15_2_P.VScontrhl_A[4])*t15_2_DWork.VScontrhl_DSTATE[0] +
      (t15_2_P.VScontrhl_A[5])*t15_2_DWork.VScontrhl_DSTATE[1]
      + (t15_2_P.VScontrhl_A[6])*t15_2_DWork.VScontrhl_DSTATE[2]
      + (t15_2_P.VScontrhl_A[7])*t15_2_DWork.VScontrhl_DSTATE[7];
    xnew[1] += (t15_2_P.VScontrhl_B[2])*t15_2_B.Divide4_j[0] +
      (t15_2_P.VScontrhl_B[3])*t15_2_B.Divide4_j[1];
    xnew[2] = (t15_2_P.VScontrhl_A[8])*t15_2_DWork.VScontrhl_DSTATE[0] +
      (t15_2_P.VScontrhl_A[9])*t15_2_DWork.VScontrhl_DSTATE[1]
      + (t15_2_P.VScontrhl_A[10])*t15_2_DWork.VScontrhl_DSTATE[2]
      + (t15_2_P.VScontrhl_A[11])*t15_2_DWork.VScontrhl_DSTATE[7];
    xnew[2] += (t15_2_P.VScontrhl_B[4])*t15_2_B.Divide4_j[0] +
      (t15_2_P.VScontrhl_B[5])*t15_2_B.Divide4_j[1];

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

    xnew[3] += (t15_2_P.VScontrhl_B[6])*t15_2_B.Divide4_j[0] +
      (t15_2_P.VScontrhl_B[7])*t15_2_B.Divide4_j[1];

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

    xnew[4] += (t15_2_P.VScontrhl_B[8])*t15_2_B.Divide4_j[0] +
      (t15_2_P.VScontrhl_B[9])*t15_2_B.Divide4_j[1];

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

    xnew[5] += (t15_2_P.VScontrhl_B[10])*t15_2_B.Divide4_j[0] +
      (t15_2_P.VScontrhl_B[11])*t15_2_B.Divide4_j[1];

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

    xnew[6] += (t15_2_P.VScontrhl_B[12])*t15_2_B.Divide4_j[0] +
      (t15_2_P.VScontrhl_B[13])*t15_2_B.Divide4_j[1];
    xnew[7] = (t15_2_P.VScontrhl_A[32])*t15_2_DWork.VScontrhl_DSTATE[7];
    xnew[7] += (t15_2_P.VScontrhl_B[14])*t15_2_B.Divide4_j[0];
    (void) memcpy(&t15_2_DWork.VScontrhl_DSTATE[0], xnew,
                  sizeof(real_T)*8);
  }

  for (i = 0; i < 11; i++) {
    /* Update for Memory: '<S60>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_b[i] = t15_2_B.u99_i[i];

    /* Update for Memory: '<S63>/Memory' */
    t15_2_DWork.Memory_PreviousInput[i] = t15_2_B.u9_b[i];

    /* Update for Memory: '<S56>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_dn[i] = t15_2_B.IpIp_div[i];

    /* Update for Memory: '<S7>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_p2[i] = t15_2_B.Switch2_c[i];
  }

  /* Update for UnitDelay: '<S6>/UD' */
  t15_2_DWork.UD_DSTATE_i = t15_2_B.e3;

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
//	FILE *prob1, *f;
	char b[256];

      int i,j,ii,jj,kk;
	  double tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref,c_a_tpl1,c_a_tpl1_eob;
      double c_a_tpl2,c_a_tpl_min,y0,t_tran2d,c1_y0,c2_y0,g2_ramp;

	  if( kpr == 1){
  
	  printf("---t15_2_initialize \n");

	  control_data_read();

	  printf("+++control_data2.dat \n");

tcont2=mem1.tcont2;
Ip_div=mem1.Ip_div;
ref_ramp=mem1.ref_ramp;
Ip_rd=mem1.Ip_rd;
trd_ref=mem1.trd_ref;

	  printf("  tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref \n");
  	  printf("%g   %g   %g  %g   %g \n ",tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref);



c_a_tpl1=mem1.c_a_tpl1;
c_a_tpl1_eob=mem1.c_a_tpl1_eob;
c_a_tpl2=mem1.c_a_tpl2;
c_a_tpl_min=mem1.c_a_tpl_min;
y0=mem1.y0;
c1_y0=mem1.c1_y0;
c2_y0=mem1.c2_y0;

	  printf("  c_a_tpl1,c_a_tpl1_eob,c_a_tpl2,c_a_tpl_min \n");
  	  printf("%g   %g   %g  %g \n ",c_a_tpl1,c_a_tpl1_eob,c_a_tpl2,c_a_tpl_min);

	  printf("  y0,c1_y0,c2_y0 \n");
  	  printf("%g   %g   %g  \n ",y0,c1_y0,c2_y0);


//fclose(f);



	   printf("  tcont2_Threshold  tcont2_Threshold_f\n");
  	  printf("%g   %g   \n",t15_2_P.tcont2_Threshold, 
		  t15_2_P.tcont2_Threshold_f);
	  printf("\n");

	t15_2_P.tcont2_Threshold=tcont2;
	t15_2_P.tcont2_Threshold_f=tcont2;

	   printf("  tcont2_Threshold  tcont2_Threshold_f\n");
  	  printf("%g   %g   \n",t15_2_P.tcont2_Threshold, 
		  t15_2_P.tcont2_Threshold_f);
	  printf("\n");


	  printf("  t15_2_P.gain_cont2_XData\n");
	  ii=4;
	  for (i = 0; i < ii; i++) {
		printf("%g ",t15_2_P.gain_cont2_XData[i]);
	  } 
	  printf("\n");
	
//tgain_cont2=[0  tcont2 tcont2+0.3   1e6];
t15_2_P.gain_cont2_XData[1]=tcont2;
t15_2_P.gain_cont2_XData[2]=tcont2+0.3;

	  printf("  t15_2_P.gain_cont2_XData\n");
	  ii=4;
	  for (i = 0; i < ii; i++) {
		printf("%g ",t15_2_P.gain_cont2_XData[i]);
	  } 
	  printf("\n");

	  printf("  IpIp_div_Threshold  IpIp_div_Threshold_l \n");
  	  printf("%g   %g  ",t15_2_P.IpIp_div_Threshold, 
		  t15_2_P.IpIp_div_Threshold_l);
	  printf("\n");
	
	  t15_2_P.IpIp_div_Threshold=Ip_div;
	  t15_2_P.IpIp_div_Threshold_l=Ip_div;

	   printf("  IpIp_div_Threshold  IpIp_div_Threshold_l \n");
  	  printf("%g   %g  ",t15_2_P.IpIp_div_Threshold, 
		  t15_2_P.IpIp_div_Threshold_l);
	  printf("\n");

	   printf("  t15_2_P.Gain1_Gain_h \n");
  	  printf("%g   ",t15_2_P.Gain1_Gain_h);
	  printf("\n");

	  t15_2_P.Gain1_Gain_h=-1./ref_ramp;

	  printf("  t15_2_P.Gain1_Gain_h \n");
  	  printf("%g   ",t15_2_P.Gain1_Gain_h);
	  printf("\n");

	   printf("  t15_2_P.Gain1_Gain_j0 \n");
  	  printf("%g   ",t15_2_P.Gain1_Gain_j0);
	  printf("\n");
	  t15_2_P.Gain1_Gain_j0=-1./ref_ramp;
	   printf("  t15_2_P.Gain1_Gain_j0 \n");
  	  printf("%g   ",t15_2_P.Gain1_Gain_j0);
	  printf("\n");

	   printf("  t15_2_P.Gain1_Gain_j \n");
  	  printf("%g   ",t15_2_P.Gain1_Gain_j);
	  printf("\n");
	  t15_2_P.Gain1_Gain_j=-1./ref_ramp;
	   printf("  t15_2_P.Gain1_Gain_j \n");
  	  printf("%g   ",t15_2_P.Gain1_Gain_j);
	  printf("\n");


	  printf("  t15_2_P.Constant_Value_b \n");
  	  printf("%g   ",t15_2_P.Constant_Value_b);
	  printf("\n");

	  t15_2_P.Constant_Value_b=Ip_rd;

	  printf("  t15_2_P.Constant_Value_b \n");
  	  printf("%g   ",t15_2_P.Constant_Value_b);
	  printf("\n");


//	  t15_2_P.LookupTable1_XData[4]
//Expression: [0 t_tran2D t_tran2D+ref_ramp 1e6]
	  t_tran2d=t15_2_P.tt_tran2d_Threshold;

	  printf("  LookupTable1_XData[2] LookupTable2_XData[2] LookupTable3_XData[2] \n");
  	  printf("%g %g %g   ",t15_2_P.LookupTable1_XData[2],t15_2_P.LookupTable2_XData[2],
		  t15_2_P.LookupTable3_XData[2]);
	  printf("\n");
	  t15_2_P.LookupTable1_XData[2]=t_tran2d+ref_ramp;
	  t15_2_P.LookupTable2_XData[2]=t_tran2d+ref_ramp;
	  t15_2_P.LookupTable3_XData[2]=t_tran2d+ref_ramp;

	  printf("  LookupTable1_XData[2] LookupTable2_XData[2] LookupTable3_XData[2] \n");
  	  printf("%g  %g %g ",t15_2_P.LookupTable1_XData[2],t15_2_P.LookupTable2_XData[2],
		  t15_2_P.LookupTable3_XData[2]);
	  printf("\n");


	   printf("  Constant_Value  Constant_Value_j Constant_Value_i\n");
  	  printf("%g   %g   %g \n",t15_2_P.Constant_Value, 
		  t15_2_P.Constant_Value_j,t15_2_P.Constant_Value_i);
	   printf("  Constant_Value_g  Constant_Value_h Constant_Value_mf\n");
  	  printf("%g   %g   %g \n",t15_2_P.Constant_Value_o, 
		  t15_2_P.Constant_Value_n,t15_2_P.Constant_Value_ow);
	  printf("\n");

	 t15_2_P.Constant_Value=trd_ref;
	 t15_2_P.Constant_Value_j=trd_ref;
	 t15_2_P.Constant_Value_i=trd_ref;
	 t15_2_P.Constant_Value_o=trd_ref;
	 t15_2_P.Constant_Value_n=trd_ref;
	 t15_2_P.Constant_Value_ow=trd_ref;

	   printf("  Constant_Value  Constant_Value_j Constant_Value_i\n");
  	  printf("%g   %g   %g \n",t15_2_P.Constant_Value, 
		  t15_2_P.Constant_Value_j,t15_2_P.Constant_Value_i);
	   printf("  Constant_Value_g  Constant_Value_h Constant_Value_mf\n");
  	  printf("%g   %g   %g \n",t15_2_P.Constant_Value_o, 
		  t15_2_P.Constant_Value_n,t15_2_P.Constant_Value_ow);
	  printf("\n");


	   printf("  Constant_Value_e  Ip_div\n");
  	  printf("%g   %g  \n",t15_2_P.Constant_Value_e, 
		  Ip_div);
	  
	  t15_2_P.Constant_Value_e=Ip_div;

	   printf("  Constant_Value_a  Ip_rd\n");
  	  printf("%g   %g  \n",t15_2_P.Constant_Value_a, 
		  Ip_rd);
	  
	  t15_2_P.Constant_Value_a=Ip_rd;

	  printf("  Constant_Value_b  Ip_rd\n");
  	  printf("%g   %g  \n",t15_2_P.Constant_Value_b, 
		  Ip_rd);
	  
	  t15_2_P.Constant_Value_b=Ip_rd;

	  printf("  Constant_Value_k  Ip_rd\n");
  	  printf("%g   %g  \n",t15_2_P.Constant_Value_k, 
		  Ip_rd);
	  
	  t15_2_P.Constant_Value_k=Ip_rd;


	  printf("  t15_2_P.VSgain3_Gain \n");
  	  printf("%g   ",t15_2_P.VSgain3_Gain);
	  printf("\n");

	  t15_2_P.VSgain3_Gain=c_a_tpl1_eob/15.;

	  printf("  t15_2_P.VSgain3_Gain \n");
  	  printf("%g   ",t15_2_P.VSgain3_Gain);
	  printf("\n");

	  printf("  t15_2_P.atpl115_Gain \n");
  	  printf("%g   ",t15_2_P.atpl115_Gain);
	  printf("\n");

	  t15_2_P.atpl115_Gain=c_a_tpl1/15.;

	  printf("  t15_2_P.atpl115_Gain \n");
  	  printf("%g   ",t15_2_P.atpl115_Gain);
	  printf("\n");

	  printf("  t15_2_P.limgain_Gain \n");
  	  printf("%g   ",t15_2_P.limgain_Gain);
	  printf("\n");
	  t15_2_P.limgain_Gain=c_a_tpl2/15.;

	  printf("  t15_2_P.limgain_Gain \n");
  	  printf("%g   ",t15_2_P.limgain_Gain);
	  printf("\n");

	  printf("  t15_2_P.Saturation3_LowerSat t15_2_P.Saturation4_LowerSat \n");
  	  printf("%g %g  ",t15_2_P.Saturation3_LowerSat,t15_2_P.Saturation4_LowerSat);
	  printf("\n");
	t15_2_P.Saturation3_LowerSat=c_a_tpl_min;
	t15_2_P.Saturation4_LowerSat=c_a_tpl_min;
	  printf("  t15_2_P.Saturation3_LowerSat t15_2_P.Saturation4_LowerSat \n");
  	  printf("%g %g   ",t15_2_P.Saturation3_LowerSat,t15_2_P.Saturation4_LowerSat);
	  printf("\n");

	   printf("  t15_2_P.y0_Value  t15_2_P.uy0_Value t15_2_P.uy0_LowerSat\n");
  	  printf("%g   %g   %g \n",t15_2_P.y0_Value, 
		  t15_2_P.uy0_Value,t15_2_P.uy0_LowerSat);


	  t15_2_P.y0_Value=y0;
//Expression: (1-y0)/(c2_y0-c1_y0)
	  printf("  y0 t15_2_P.c1_y0_Value c2_y0\n");
  	  printf("%g %g  %g   ",y0,t15_2_P.c1_y0_Value,c2_y0);
	  printf("\n");

	  t15_2_P.c1_y0_Value=c1_y0;
	  t15_2_P.uy0_Value=(1.-y0)/(c2_y0-c1_y0);

	  t15_2_P.uy0_LowerSat=y0;

	  printf("  y0 t15_2_P.c1_y0_Value c2_y0\n");
  	  printf("%g %g  %g   ",y0,t15_2_P.c1_y0_Value,c2_y0);
	  printf("\n");

	   printf("  t15_2_P.y0_Value  t15_2_P.uy0_Value t15_2_P.uy0_LowerSat\n");
  	  printf("%g   %g   %g \n",t15_2_P.y0_Value, 
		  t15_2_P.uy0_Value,t15_2_P.uy0_LowerSat);

	
	   printf("  Constant_Value_if Ip_div\n");
  	  printf("%g   %g  \n",t15_2_P.Constant_Value_if, 
		  Ip_div);
	
	  t15_2_P.Constant_Value_if=Ip_div;


printf("  t15_2_P.ntur111_Value\n");
  	  for(i=0;i<11;i++)printf("%g   ",t15_2_P.ntur111_Value[i]);

	  printf("  t15_2_P.ntur111_Value\n");
	  for(i=0;i<11;i++){
		  t15_2_P.ntur111_Value[i]=mem8.ntur[i];
		  printf("%g   ",t15_2_P.ntur111_Value[i]);}

	  printf("\n");


printf("  t15_2_P.ntur111_Value_c\n");
  	  for(i=0;i<11;i++)printf("%g   ",t15_2_P.ntur111_Value_c[i]);

	  printf("  t15_2_P.ntur111_Value_c\n");
	  for(i=0;i<11;i++){
		  t15_2_P.ntur111_Value_c[i]=mem8.ntur[i];
		  printf("%g   ",t15_2_P.ntur111_Value_c[i]);}

	  printf("\n");

	  printf("  t15_2_P.ntur111_Value_a\n");
  	  for(i=0;i<11;i++)printf("%g   ",t15_2_P.ntur111_Value_a[i]);

	  printf("  t15_2_P.ntur111_Value_a\n");
	  for(i=0;i<11;i++){
		  t15_2_P.ntur111_Value_a[i]=mem8.ntur[i];
		  printf("%g   ",t15_2_P.ntur111_Value_a[i]);}

	  printf("\n");

	  printf("  t15_2_P.ntur_Gain\n");
  	  for(i=0;i<11;i++)printf("%g   ",t15_2_P.ntur_Gain[i]);

	  printf("  t15_2_P.ntur_Gain\n");
	  for(i=0;i<11;i++){
			  t15_2_P.ntur_Gain[i]=1./mem8.ntur[i];

	  printf("%g   ",t15_2_P.ntur_Gain[i]);}

	  printf("\n");

	  printf("  t15_2_P.ntur3_Value\n");
  	  printf("%g   ",t15_2_P.ntur3_Value);

	  printf("  t15_2_P.ntur3_Value\n");
	  t15_2_P.ntur3_Value=mem8.ntur[2];
	  printf("%g   ",t15_2_P.ntur3_Value);

	  printf("\n");


//ntur111_Value[11];            /* Expression: ntur(1:11)*/
//ntur111_Value_c[11];          /* Expression: ntur(1:11)*/
//ntur111_Value_a[11];          /* Expression: ntur(1:11)*/
//ntur_Gain[11];                /* Expression: 1./ntur(1:n_mc)*/
//ntur3_Value;                  /* Expression: ntur(3)*/


	  } 



	sleep(10);
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

    for (i = 0; i < 15; i++) {
      t15_2_B.e6_m[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_i[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      t15_2_B.e2[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_o[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_p[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_f[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_f2[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_e[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_h[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_fd[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_o5[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_n[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_a[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_p1[i] = 0.0;
    }

    for (i = 0; i < 100; i++) {
      t15_2_B.SFunction1_c[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      t15_2_B.e2_n[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.u9[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.e3_h[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Abs_a[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.DataStoreRead1_k[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide5[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum2_k[i] = 0.0;
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
      t15_2_B.Divide1_ps[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Saturation_k[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory1_k[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide2_b[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u9_b[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide13[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Div_rdcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u99_i[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide4_p[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Currtermcontr[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide5_p[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory2_kr[i] = 0.0;
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
      t15_2_B.Divide6_l[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_p1[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_d[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_a[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_o[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_c[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_i1[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_g[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_b[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_i2[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_b[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_e[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_n[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_h[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_pd[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_oy[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_f[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_m[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_e[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_b3[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_ee[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_g[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_bc[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_cn[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_f3[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_l[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_fq[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_ou[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_e[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_dy[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_fr[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.u01_f1[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_n[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide7[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum3[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide2_j[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum3_b[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Saturation1_g[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide6_f[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      t15_2_B.Divide12[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_j[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide4_f[i] = 0.0;
    }

    for (i = 0; i < 32; i++) {
      t15_2_B.SFunction[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.DataStoreRead1_kx[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Memory1_ek[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.DataStoreRead1_o[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u_j[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_o5[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Add1_gy[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.u_e[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Switch2[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_k[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Add2_n[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Gain[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Switch_l[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Switch2_c[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.ntur[i] = 0.0;
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
      t15_2_B.Divide_e[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide3_p[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide1_jp[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Sum2_h[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_ph[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_h[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.tcont2_a[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide_f[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      t15_2_B.Divide2_a[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector_k[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg1_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_p[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_f0[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_i[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_j[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_n[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector_n[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg6_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_no[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_fz[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_no[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_j2[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_f[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector_l[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg5_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_o[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_i[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_bd[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_f[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_a[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector_ns[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg4_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_pz[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_h[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_bw[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_d[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_ou[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector_e[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg3_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_c[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_p[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_oa[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_g[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_nf[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      t15_2_B.Selector_k4[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.TmpSignalConversionAtg2_termref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_d[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Divide6_n[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Add2_p[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector_lh[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      t15_2_B.Selector1_ad[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_cq[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_cq[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_g[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_ef[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_fi[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_jd[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_kd[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_d[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_mj[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_gy[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_h[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_i4[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_a[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_lz[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_c3[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_nu[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_nq[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_eq[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_pde[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_ld[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_dg[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_ft[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead1_d5[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      t15_2_B.DataStoreRead_h4[i] = 0.0;
    }

    t15_2_B.e3 = 0.0;
    t15_2_B.Memory2 = 0.0;
    t15_2_B.u = 0.0;
    t15_2_B.Ip1e4 = 0.0;
    t15_2_B.DataStoreRead = 0.0;
    t15_2_B.Sum2 = 0.0;
    t15_2_B.e6 = 0.0;
    t15_2_B.Memory2_k = 0.0;
    t15_2_B.Add3 = 0.0;
    t15_2_B.DataStoreRead1 = 0.0;
    t15_2_B.e3_k = 0.0;
    t15_2_B.Product1 = 0.0;
    t15_2_B.RelationalOperator = 0.0;
    t15_2_B.Memory1 = 0.0;
    t15_2_B.u99 = 0.0;
    t15_2_B.Add2 = 0.0;
    t15_2_B.DataStoreRead_o = 0.0;
    t15_2_B.Product = 0.0;
    t15_2_B.Add1 = 0.0;
    t15_2_B.u_n = 0.0;
    t15_2_B.Memory1_j = 0.0;
    t15_2_B.c_eob = 0.0;
    t15_2_B.Divide6 = 0.0;
    t15_2_B.Add1_i = 0.0;
    t15_2_B.Uk1 = 0.0;
    t15_2_B.Uk1_d = 0.0;
    t15_2_B.Memory2_f = 0.0;
    t15_2_B.c_eob_b = 0.0;
    t15_2_B.Divide1 = 0.0;
    t15_2_B.Add1_g = 0.0;
    t15_2_B.Memory2_k5 = 0.0;
    t15_2_B.c_eob_c = 0.0;
    t15_2_B.Divide1_o = 0.0;
    t15_2_B.Add10 = 0.0;
    t15_2_B.Memory2_kw = 0.0;
    t15_2_B.c_eob_h = 0.0;
    t15_2_B.Divide1_n = 0.0;
    t15_2_B.Add11 = 0.0;
    t15_2_B.Memory2_o = 0.0;
    t15_2_B.c_eob_e = 0.0;
    t15_2_B.Divide1_h = 0.0;
    t15_2_B.Add2_o = 0.0;
    t15_2_B.Memory2_b = 0.0;
    t15_2_B.c_eob_cj = 0.0;
    t15_2_B.Divide1_nq = 0.0;
    t15_2_B.Add3_c = 0.0;
    t15_2_B.Memory2_d = 0.0;
    t15_2_B.c_eob_k = 0.0;
    t15_2_B.Divide1_p = 0.0;
    t15_2_B.Add4 = 0.0;
    t15_2_B.Memory2_p = 0.0;
    t15_2_B.c_eob_g = 0.0;
    t15_2_B.Divide1_l = 0.0;
    t15_2_B.Add5 = 0.0;
    t15_2_B.Memory2_dq = 0.0;
    t15_2_B.c_eob_l = 0.0;
    t15_2_B.Divide1_e = 0.0;
    t15_2_B.Add6 = 0.0;
    t15_2_B.Memory2_e = 0.0;
    t15_2_B.c_eob_g0 = 0.0;
    t15_2_B.Divide1_f = 0.0;
    t15_2_B.Add7 = 0.0;
    t15_2_B.Memory2_j = 0.0;
    t15_2_B.c_eob_bz = 0.0;
    t15_2_B.Divide1_hq = 0.0;
    t15_2_B.Add8 = 0.0;
    t15_2_B.Memory2_a = 0.0;
    t15_2_B.c_eob_j = 0.0;
    t15_2_B.Divide1_d = 0.0;
    t15_2_B.Add9 = 0.0;
    t15_2_B.Sum2_b = 0.0;
    t15_2_B.u_p = 0.0;
    t15_2_B.Memory2_da = 0.0;
    t15_2_B.c_eob1 = 0.0;
    t15_2_B.Memory1_i = 0.0;
    t15_2_B.c_eob_ej = 0.0;
    t15_2_B.c_eob_jd = 0.0;
    t15_2_B.Add2_b = 0.0;
    t15_2_B.LookupTable1 = 0.0;
    t15_2_B.Divide6_d = 0.0;
    t15_2_B.Memory2_i = 0.0;
    t15_2_B.c_eob1_b = 0.0;
    t15_2_B.Memory1_g = 0.0;
    t15_2_B.c_eob_n = 0.0;
    t15_2_B.c_eob_kt = 0.0;
    t15_2_B.Add1_ia = 0.0;
    t15_2_B.LookupTable2 = 0.0;
    t15_2_B.Divide1_a = 0.0;
    t15_2_B.Memory2_n = 0.0;
    t15_2_B.c_eob1_i = 0.0;
    t15_2_B.Memory1_jo = 0.0;
    t15_2_B.c_eob_lg = 0.0;
    t15_2_B.c_eob_lu = 0.0;
    t15_2_B.Add3_a = 0.0;
    t15_2_B.Memory2_l = 0.0;
    t15_2_B.c_eob1_d = 0.0;
    t15_2_B.Memory1_e = 0.0;
    t15_2_B.c_eob_c2 = 0.0;
    t15_2_B.c_eob_p = 0.0;
    t15_2_B.Add4_i = 0.0;
    t15_2_B.LookupTable3 = 0.0;
    t15_2_B.Divide2 = 0.0;
    t15_2_B.Memory2_m = 0.0;
    t15_2_B.c_eob1_c = 0.0;
    t15_2_B.Memory1_b = 0.0;
    t15_2_B.c_eob_nk = 0.0;
    t15_2_B.c_eob_cy = 0.0;
    t15_2_B.Add5_n = 0.0;
    t15_2_B.Memory2_j1 = 0.0;
    t15_2_B.c_eob1_g = 0.0;
    t15_2_B.Memory1_g3 = 0.0;
    t15_2_B.c_eob_be = 0.0;
    t15_2_B.c_eob_c3 = 0.0;
    t15_2_B.Add6_b = 0.0;
    t15_2_B.DataStoreRead_or = 0.0;
    t15_2_B.LogicalOperator1 = 0.0;
    t15_2_B.e6_i = 0.0;
    t15_2_B.Memory3 = 0.0;
    t15_2_B.DataStoreRead_f = 0.0;
    t15_2_B.LogicalOperator1_h = 0.0;
    t15_2_B.u999 = 0.0;
    t15_2_B.Subtract2 = 0.0;
    t15_2_B.Gain1 = 0.0;
    t15_2_B.Subtract1 = 0.0;
    t15_2_B.Saturation1 = 0.0;
    t15_2_B.Memory1_a = 0.0;
    t15_2_B.DataStoreRead_l = 0.0;
    t15_2_B.Abs = 0.0;
    t15_2_B.DataStoreRead_i = 0.0;
    t15_2_B.LogicalOperator2 = 0.0;
    t15_2_B.u999_d = 0.0;
    t15_2_B.Subtract2_h = 0.0;
    t15_2_B.Gain1_j = 0.0;
    t15_2_B.Subtract3 = 0.0;
    t15_2_B.Saturation = 0.0;
    t15_2_B.Subtract1_k = 0.0;
    t15_2_B.Subtract4 = 0.0;
    t15_2_B.DataStoreRead1_kb = 0.0;
    t15_2_B.DataStoreRead_ln = 0.0;
    t15_2_B.Abs_c = 0.0;
    t15_2_B.DataStoreRead1_f = 0.0;
    t15_2_B.LogicalOperator2_g = 0.0;
    t15_2_B.DataStoreRead_j = 0.0;
    t15_2_B.DataStoreRead1_p = 0.0;
    t15_2_B.Abs_e = 0.0;
    t15_2_B.LogicalOperator1_i = 0.0;
    t15_2_B.Memory1_ec = 0.0;
    t15_2_B.DataStoreRead_p = 0.0;
    t15_2_B.LogicalOperator1_a = 0.0;
    t15_2_B.u999_b = 0.0;
    t15_2_B.Memory1_l = 0.0;
    t15_2_B.c_eob_e3 = 0.0;
    t15_2_B.volt1 = 0.0;
    t15_2_B.volt1_b = 0.0;
    t15_2_B.volt1_i = 0.0;
    t15_2_B.volt1_o = 0.0;
    t15_2_B.volt1_d = 0.0;
    t15_2_B.volt1_m = 0.0;
    t15_2_B.volt1_j = 0.0;
    t15_2_B.volt1_b2 = 0.0;
    t15_2_B.volt1_ia = 0.0;
    t15_2_B.volt1_a = 0.0;
    t15_2_B.volt1_e = 0.0;
    t15_2_B.UniformRandomNumber = 0.0;
    t15_2_B.Uk1_m = 0.0;
    t15_2_B.tt_tran2d[0] = 0.0;
    t15_2_B.tt_tran2d[1] = 0.0;
    t15_2_B.VScontr[0] = 0.0;
    t15_2_B.VScontr[1] = 0.0;
    t15_2_B.RelationalOperator_g = 0.0;
    t15_2_B.Divide4_j[0] = 0.0;
    t15_2_B.Divide4_j[1] = 0.0;
    t15_2_B.VScontrhl[0] = 0.0;
    t15_2_B.VScontrhl[1] = 0.0;
    t15_2_B.c_eob_ku[0] = 0.0;
    t15_2_B.c_eob_ku[1] = 0.0;
    t15_2_B.DataStoreRead_gb = 0.0;
    t15_2_B.DataStoreRead_b = 0.0;
    t15_2_B.Abs_l = 0.0;
    t15_2_B.LogicalOperator1_k = 0.0;
    t15_2_B.atpl115 = 0.0;
    t15_2_B.u9_o[0] = 0.0;
    t15_2_B.u9_o[1] = 0.0;
    t15_2_B.Divide10[0] = 0.0;
    t15_2_B.Divide10[1] = 0.0;
    t15_2_B.DataStoreRead3 = 0.0;
    t15_2_B.Uk1_l = 0.0;
    t15_2_B.Diff = 0.0;
    t15_2_B.DataStoreRead1_j = 0.0;
    t15_2_B.Switch2_h = 0.0;
    t15_2_B.DataStoreRead3_a = 0.0;
    t15_2_B.Switch2_f = 0.0;
    t15_2_B.TmpSignalConversionAtwzInport1[0] = 0.0;
    t15_2_B.TmpSignalConversionAtwzInport1[1] = 0.0;
    t15_2_B.VSgain3 = 0.0;
    t15_2_B.Saturation4 = 0.0;
    t15_2_B.Divide11[0] = 0.0;
    t15_2_B.Divide11[1] = 0.0;
    t15_2_B.c_eob_b4[0] = 0.0;
    t15_2_B.c_eob_b4[1] = 0.0;
    t15_2_B.IpIp_div_b = 0.0;
    t15_2_B.Divide8[0] = 0.0;
    t15_2_B.Divide8[1] = 0.0;
    t15_2_B.SatDiv = 0.0;
    t15_2_B.SatLim = 0.0;
    t15_2_B.VSgain2 = 0.0;
    t15_2_B.Saturation3 = 0.0;
    t15_2_B.Divide_g[0] = 0.0;
    t15_2_B.Divide_g[1] = 0.0;
    t15_2_B.Subtract3_h = 0.0;
    t15_2_B.Subtract2_b = 0.0;
    t15_2_B.Gain1_l = 0.0;
    t15_2_B.Subtract3_l = 0.0;
    t15_2_B.Saturation_i = 0.0;
    t15_2_B.Subtract1_l = 0.0;
    t15_2_B.c_eob_bc = 0.0;
    t15_2_B.limgain = 0.0;
    t15_2_B.Saturation_b = 0.0;
    t15_2_B.Divide6_c = 0.0;
    t15_2_B.Sum = 0.0;
    t15_2_B.Divide2_n = 0.0;
    t15_2_B.Sum1_a = 0.0;
    t15_2_B.uy0 = 0.0;
    t15_2_B.Ipref = 0.0;
    t15_2_B.gain_cont2 = 0.0;
    t15_2_B.Diff_f = 0.0;
    t15_2_B.e3_i = 0.0;
    t15_2_B.Sqrt = 0.0;
    t15_2_B.DataStoreRead_nz = 0.0;
    t15_2_B.u5 = 0.0;
    t15_2_B.Divide11_d = 0.0;
    t15_2_B.Divide1_g = 0.0;
    t15_2_B.Diff_o = 0.0;
    t15_2_B.Diff_n = 0.0;
    t15_2_B.Divide_c = 0.0;
    t15_2_B.Sum2_e = 0.0;
    t15_2_B.elong = 0.0;
    t15_2_B.Add2_m = 0.0;
    t15_2_B.k_gaplim[0] = 0.0;
    t15_2_B.k_gaplim[1] = 0.0;
    t15_2_B.k_gaplim[2] = 0.0;
    t15_2_B.k_gaplim[3] = 0.0;
    t15_2_B.DataStoreRead_bi = 0.0;
    t15_2_B.g1_termref = 0.0;
    t15_2_B.g1ref = 0.0;
    t15_2_B.DataStoreRead_ag = 0.0;
    t15_2_B.g6_termref = 0.0;
    t15_2_B.g6ref = 0.0;
    t15_2_B.DataStoreRead_c = 0.0;
    t15_2_B.g5_termref = 0.0;
    t15_2_B.g5ref = 0.0;
    t15_2_B.DataStoreRead_cj = 0.0;
    t15_2_B.g4_termref = 0.0;
    t15_2_B.g4ref = 0.0;
    t15_2_B.DataStoreRead_n2 = 0.0;
    t15_2_B.g3_termref = 0.0;
    t15_2_B.g3ref = 0.0;
    t15_2_B.DataStoreRead_m = 0.0;
    t15_2_B.g2_termref = 0.0;
    t15_2_B.g2ref = 0.0;
    t15_2_B.I1 = 0.0;
    t15_2_B.I1_g = 0.0;
    t15_2_B.I1_k = 0.0;
    t15_2_B.I1_j = 0.0;
    t15_2_B.I1_c = 0.0;
    t15_2_B.I1_i = 0.0;
    t15_2_B.I1_e = 0.0;
    t15_2_B.I1_ib = 0.0;
    t15_2_B.I1_jq = 0.0;
    t15_2_B.I1_d = 0.0;
    t15_2_B.I1_o = 0.0;
    t15_2_B.Ipref_h = 0.0;
    t15_2_B.Gain1_h = 0.0;
    t15_2_B.Switch_c = 0.0;
    t15_2_B.Gain_l = 0.0;
    t15_2_B.Switch_k = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&t15_2_DWork, 0,
                sizeof(D_Work_t15_2));
  t15_2_DWork.UD_DSTATE = 0.0;
  t15_2_DWork.UD_DSTATE_j = 0.0;

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

  t15_2_DWork.UD_DSTATE_c = 0.0;

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

  t15_2_DWork.UD_DSTATE_i = 0.0;
  t15_2_DWork.Memory2_PreviousInput = 0.0;
  t15_2_DWork.Memory2_PreviousInput_k = 0.0;
  t15_2_DWork.Memory1_PreviousInput = 0.0;
  t15_2_DWork.Memory1_PreviousInput_c = 0.0;
  t15_2_DWork.Memory2_PreviousInput_m = 0.0;
  t15_2_DWork.Memory2_PreviousInput_b = 0.0;
  t15_2_DWork.Memory2_PreviousInput_a = 0.0;
  t15_2_DWork.Memory2_PreviousInput_d = 0.0;
  t15_2_DWork.Memory2_PreviousInput_c = 0.0;
  t15_2_DWork.Memory2_PreviousInput_e = 0.0;
  t15_2_DWork.Memory2_PreviousInput_o = 0.0;
  t15_2_DWork.Memory2_PreviousInput_eq = 0.0;
  t15_2_DWork.Memory2_PreviousInput_bf = 0.0;
  t15_2_DWork.Memory2_PreviousInput_l = 0.0;
  t15_2_DWork.Memory2_PreviousInput_j = 0.0;
  t15_2_DWork.Memory2_PreviousInput_o4 = 0.0;
  t15_2_DWork.Memory1_PreviousInput_g = 0.0;
  t15_2_DWork.Memory2_PreviousInput_mw = 0.0;
  t15_2_DWork.Memory1_PreviousInput_d = 0.0;
  t15_2_DWork.Memory2_PreviousInput_h = 0.0;
  t15_2_DWork.Memory1_PreviousInput_p = 0.0;
  t15_2_DWork.Memory2_PreviousInput_g = 0.0;
  t15_2_DWork.Memory1_PreviousInput_h = 0.0;
  t15_2_DWork.Memory2_PreviousInput_oh = 0.0;
  t15_2_DWork.Memory1_PreviousInput_gk = 0.0;
  t15_2_DWork.Memory2_PreviousInput_ef = 0.0;
  t15_2_DWork.Memory1_PreviousInput_j = 0.0;
  t15_2_DWork.Memory3_PreviousInput = 0.0;
  t15_2_DWork.Memory1_PreviousInput_l = 0.0;

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory1_PreviousInput_b[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory_PreviousInput[i] = 0.0;
    }
  }

  t15_2_DWork.Memory1_PreviousInput_o = 0.0;
  t15_2_DWork.Memory1_PreviousInput_f = 0.0;

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory2_PreviousInput_dn[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Sum3_DWORK1[i] = 0.0;
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

  {
    int_T i;
    for (i = 0; i < 11; i++) {
      t15_2_DWork.Memory1_PreviousInput_p2[i] = 0.0;
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

  t15_2_M->Sizes.numSFcns = (16);

  /* register each child */
  {
    (void) memset((void *)&t15_2_M->NonInlinedSFcns.childSFunctions[0], 0,
                  16*sizeof(SimStruct));
    t15_2_M->childSfunctions = (&t15_2_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 16; i++) {
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

    /* Level2 S-Function Block: t15_2/<S19>/S-Function1 (read_gaps) */
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
          int_T *dimensions = (int_T *) &t15_2_M->NonInlinedSFcns.Sfcn2.oDims0;
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
                "t15_2/Pow. Supply MC 2/kavin_contr/Control inputs 1/elong_ref.dat/S-Function1");
      ssSetRTModel(rts,t15_2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &t15_2_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_l);
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

    /* Level2 S-Function Block: t15_2/<S42>/S-Function1 (read_gaps) */
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_o));
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
          &t15_2_M->NonInlinedSFcns.Sfcn3.params;
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
          &t15_2_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_f);
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

    /* Level2 S-Function Block: t15_2/<S37>/S-Function1 (read_gaps) */
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_f));
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
          &t15_2_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_n);
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

    /* Level2 S-Function Block: t15_2/<S43>/S-Function1 (read_gaps_term) */
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_f2));
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
          &t15_2_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_mz);
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

    /* Level2 S-Function Block: t15_2/<S38>/S-Function1 (read_gaps) */
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_e));
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
          &t15_2_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_b);
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

    /* Level2 S-Function Block: t15_2/<S44>/S-Function1 (read_gaps_term) */
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_h));
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
          &t15_2_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_o);
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_fd));
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
          &t15_2_M->NonInlinedSFcns.Sfcn9.params;
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

    /* Level2 S-Function Block: t15_2/<S45>/S-Function1 (read_gaps_term) */
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_o5));
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
          &t15_2_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_bi);
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_n));
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
          &t15_2_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_e);
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_a));
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
          &t15_2_M->NonInlinedSFcns.Sfcn12.params;
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

    /* Level2 S-Function Block: t15_2/<S41>/S-Function1 (read_gaps) */
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_p1));
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
          &t15_2_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_bq);
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction1_c));
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
          &t15_2_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)t15_2_P.SFunction1_P1_Size_a);
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
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 32);
          ssSetOutputPortSignal(rts, 0, ((real_T *) t15_2_B.SFunction));
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

    /* Start for UniformRandomNumber: '<S61>/Uniform Random Number' */
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

    /* End of Start for UniformRandomNumber: '<S61>/Uniform Random Number' */

    /* Start for DataStoreMemory: '<S5>/Data Store Memory' */
    memcpy(&t15_2_DWork.scr_data[0], &t15_2_P.DataStoreMemory_InitialValue[0],
           6500U * sizeof(real_T));

    /* Start for DataStoreMemory: '<S5>/Data Store Memory1' */
    memcpy(&t15_2_DWork.volt[0], &t15_2_P.DataStoreMemory1_InitialValue[0],
           10000U * sizeof(real_T));

    /* Start for DataStoreMemory: '<S1>/Data Store Memory2' */
    for (r = 0; r < 6; r++) {
      t15_2_DWork.RupRd[r] = t15_2_P.DataStoreMemory2_InitialValue[r];
    }

    /* End of Start for DataStoreMemory: '<S1>/Data Store Memory2' */

    /* Start for DataStoreMemory: '<S1>/Data Store Memory3' */
    t15_2_DWork.VS3_up = t15_2_P.DataStoreMemory3_InitialValue;

    /* Start for DataStoreMemory: '<S1>/Data Store Memory5' */
    t15_2_DWork.VS1_up = t15_2_P.DataStoreMemory5_InitialValue;

    /* Start for DataStoreMemory: '<S1>/Data Store Memory7' */
    t15_2_DWork.Tu = t15_2_P.DataStoreMemory7_InitialValue;

    /* Start for DataStoreMemory: '<S1>/Data Store Memory8' */
    t15_2_DWork.c_cur_max = t15_2_P.DataStoreMemory8_InitialValue;
    for (r = 0; r < 11; r++) {
      /* Start for DataStoreMemory: '<S1>/Data Store Memory4' */
      t15_2_DWork.Vcspf_up[r] = t15_2_P.DataStoreMemory4_InitialValue[r];

      /* Start for DataStoreMemory: '<S1>/Data Store Memory9' */
      t15_2_DWork.Imax[r] = t15_2_P.DataStoreMemory9_InitialValue[r];
    }
  }

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S5>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput = t15_2_P.Memory2_X0;

    /* InitializeConditions for Memory: '<S23>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_k = t15_2_P.Memory2_X0_f;

    /* InitializeConditions for Memory: '<S23>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput = t15_2_P.Memory1_X0;

    /* InitializeConditions for Memory: '<S17>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_c = t15_2_P.Memory1_X0_b;

    /* InitializeConditions for UnitDelay: '<S24>/UD' */
    t15_2_DWork.UD_DSTATE = t15_2_P.UD_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S25>/UD' */
    t15_2_DWork.UD_DSTATE_j = t15_2_P.UD_InitialCondition_b;

    /* InitializeConditions for Memory: '<S29>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_m = t15_2_P.Memory2_X0_h;

    /* InitializeConditions for Memory: '<S27>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_b = t15_2_P.Memory2_X0_d;

    /* InitializeConditions for Memory: '<S28>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_a = t15_2_P.Memory2_X0_a;

    /* InitializeConditions for Memory: '<S30>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_d = t15_2_P.Memory2_X0_n;

    /* InitializeConditions for Memory: '<S26>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_c = t15_2_P.Memory2_X0_e;

    /* InitializeConditions for Memory: '<S31>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_e = t15_2_P.Memory2_X0_b;

    /* InitializeConditions for Memory: '<S32>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_o = t15_2_P.Memory2_X0_hi;

    /* InitializeConditions for Memory: '<S33>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_eq = t15_2_P.Memory2_X0_dv;

    /* InitializeConditions for Memory: '<S34>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_bf = t15_2_P.Memory2_X0_k;

    /* InitializeConditions for Memory: '<S35>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_l = t15_2_P.Memory2_X0_bq;

    /* InitializeConditions for Memory: '<S36>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_j = t15_2_P.Memory2_X0_p;

    /* InitializeConditions for Memory: '<S42>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_o4 = t15_2_P.Memory2_X0_o;

    /* InitializeConditions for Memory: '<S42>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_g = t15_2_P.Memory1_X0_f;

    /* InitializeConditions for Memory: '<S37>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_mw = t15_2_P.Memory2_X0_oh;

    /* InitializeConditions for Memory: '<S37>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_d = t15_2_P.Memory1_X0_h;

    /* InitializeConditions for Memory: '<S38>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_h = t15_2_P.Memory2_X0_kw;

    /* InitializeConditions for Memory: '<S38>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_p = t15_2_P.Memory1_X0_n;

    /* InitializeConditions for Memory: '<S39>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_g = t15_2_P.Memory2_X0_nw;

    /* InitializeConditions for Memory: '<S39>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_h = t15_2_P.Memory1_X0_g;

    /* InitializeConditions for Memory: '<S40>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_oh = t15_2_P.Memory2_X0_nr;

    /* InitializeConditions for Memory: '<S40>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_gk = t15_2_P.Memory1_X0_m;

    /* InitializeConditions for Memory: '<S41>/Memory2' */
    t15_2_DWork.Memory2_PreviousInput_ef = t15_2_P.Memory2_X0_c;

    /* InitializeConditions for Memory: '<S41>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_j = t15_2_P.Memory1_X0_j;

    /* InitializeConditions for Memory: '<S50>/Memory3' */
    t15_2_DWork.Memory3_PreviousInput = t15_2_P.Memory3_X0;

    /* InitializeConditions for Memory: '<S51>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_l = t15_2_P.Memory1_X0_fe;

    /* InitializeConditions for DiscreteStateSpace: '<S54>/Div. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Divcontr_DSTATE[0];
      for (i1=0; i1 < 32; i1++) {
        dw_DSTATE[i1] = t15_2_P.Divcontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S62>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_o = t15_2_P.Memory1_X0_fo;

    /* InitializeConditions for DiscreteStateSpace: '<S55>/Div_rd contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Div_rdcontr_DSTATE[0];
      for (i1=0; i1 < 22; i1++) {
        dw_DSTATE[i1] = t15_2_P.Div_rdcontr_X0;
      }
    }

    /* InitializeConditions for Memory: '<S59>/Memory1' */
    t15_2_DWork.Memory1_PreviousInput_f = t15_2_P.Memory1_X0_c;

    /* InitializeConditions for DiscreteStateSpace: '<S53>/Curr. term. contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Currtermcontr_DSTATE[0];
      for (i1=0; i1 < 22; i1++) {
        dw_DSTATE[i1] = t15_2_P.Currtermcontr_X0;
      }
    }

    /* InitializeConditions for DiscreteStateSpace: '<S56>/Lim. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Limcontr_DSTATE[0];
      for (i1=0; i1 < 46; i1++) {
        dw_DSTATE[i1] = t15_2_P.Limcontr_X0;
      }
    }

    /* InitializeConditions for DiscreteStateSpace: '<S56>/Curr. contr.' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.Currcontr_DSTATE[0];
      for (i1=0; i1 < 11; i1++) {
        dw_DSTATE[i1] = t15_2_P.Currcontr_X0;
      }
    }

    /* InitializeConditions for UnitDelay: '<S73>/UD' */
    t15_2_DWork.UD_DSTATE_c = t15_2_P.UD_InitialCondition_e;

    /* InitializeConditions for DiscreteStateSpace: '<S57>/VS. contr' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.VScontr_DSTATE[0];
      for (i1=0; i1 < 9; i1++) {
        dw_DSTATE[i1] = t15_2_P.VScontr_X0;
      }
    }

    /* InitializeConditions for DiscreteStateSpace: '<S57>/VS. contr hl' */
    {
      int_T i1;
      real_T *dw_DSTATE = &t15_2_DWork.VScontrhl_DSTATE[0];
      for (i1=0; i1 < 8; i1++) {
        dw_DSTATE[i1] = t15_2_P.VScontrhl_X0;
      }
    }

    for (i = 0; i < 11; i++) {
      /* InitializeConditions for Memory: '<S60>/Memory1' */
      t15_2_DWork.Memory1_PreviousInput_b[i] = t15_2_P.Memory1_X0_h2;

      /* InitializeConditions for Memory: '<S63>/Memory' */
      t15_2_DWork.Memory_PreviousInput[i] = t15_2_P.Memory_X0;

      /* InitializeConditions for Memory: '<S56>/Memory2' */
      t15_2_DWork.Memory2_PreviousInput_dn[i] = t15_2_P.Memory2_X0_ai;

      /* InitializeConditions for Memory: '<S7>/Memory1' */
      t15_2_DWork.Memory1_PreviousInput_p2[i] = t15_2_P.Memory1_X0_fq;
    }

    /* InitializeConditions for UnitDelay: '<S6>/UD' */
    t15_2_DWork.UD_DSTATE_i = t15_2_P.UD_InitialCondition_m;
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

  /* Level2 S-Function Block: '<S19>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S42>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S48>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S37>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S43>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S38>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S44>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S39>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S45>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S40>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S46>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S41>/S-Function1' (read_gaps) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S47>/S-Function1' (read_gaps_term) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[14];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/S-Function' (read_tt_kavin2) */
  {
    SimStruct *rts = t15_2_M->childSfunctions[15];
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
	  { output[i+ki]=t15_2_DWork.Vcspf_up[i] ;

//	  { output[i+ki]=0.0 ;
	  k=k+1;
      }

//t15_2_B.Saturation6[i] + t15_2_B.SaturationVS[i];

	  ki=k;

      for (i = 0; i < 11; i++) 
	  { output[i+ki]=t15_2_B.wz[i] ;
//	  { output[i+ki]=0.0 ;
	  k=k+1;
      }

	  i=11;
	  output[i+ki]=t15_2_B.wz[i] ;
//	  output[i+ki]=0.0 ;

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
	void control_data_read(void)
{
//	FILE *prob1, *f;
	char b[256];


      int i,j,ii,jj,kk;
	  double tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref,c_a_tpl1,c_a_tpl1_eob;
      double c_a_tpl2,c_a_tpl_min,y0,t_tran2d,c1_y0,c2_y0,g2_ramp;

int k,N; double y[500][20];
int k_time; double y2,yy[500][20]; 


	  if( kpr == 1){
  
	  printf("---t15_2_initialize \n");

	  printf("---control_data2.dat \n");

//f=fopen("control_data2.dat","r");
f=fopen("control_init.dat","r");
f1=f;

fgets(b,255,f);
	fscanf(f,"%lf",&tcont2);
	fscanf(f,"%lf",&Ip_div);
	fscanf(f,"%lf",&ref_ramp);
	fscanf(f,"%lf ",&Ip_rd);
	fscanf(f,"%lf \n",&trd_ref);
	  printf("  tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref \n");
  	  printf("%g   %g   %g  %g   %g \n ",tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref);

mem1.tcont2=tcont2;
mem1.Ip_div=Ip_div;
mem1.ref_ramp=ref_ramp;
mem1.Ip_rd=Ip_rd;
mem1.trd_ref=trd_ref;


fgets(b,255,f);

fscanf(f,"%lf",&c_a_tpl1);
fscanf(f,"%lf",&c_a_tpl1_eob);
fscanf(f,"%lf",&c_a_tpl2);
fscanf(f,"%lf",&c_a_tpl_min);
fscanf(f,"%lf",&y0);
fscanf(f,"%lf \n",&c1_y0);
fscanf(f,"%lf \n",&c2_y0);

	  printf("  c_a_tpl1,c_a_tpl1_eob,c_a_tpl2,c_a_tpl_min \n");
  	  printf("%g   %g   %g  %g \n ",c_a_tpl1,c_a_tpl1_eob,c_a_tpl2,c_a_tpl_min);

	  printf("  y0,c1_y0,c2_y0 \n");
  	  printf("%g   %g   %g  \n ",y0,c1_y0,c2_y0);

mem1.c_a_tpl1=c_a_tpl1;
mem1.c_a_tpl1_eob=c_a_tpl1_eob;
mem1.c_a_tpl2=c_a_tpl2;
mem1.c_a_tpl_min=c_a_tpl_min;
mem1.y0=y0;
mem1.c1_y0=c1_y0;
mem1.c2_y0=c2_y0;

//return;

printf("---volt.dat \n");
//N=*n_mc; /*mexPrintf(" N %d\n",N);*/

N=12;

fgets(b,255,f);
	fscanf(f,"%d \n",&k_time);
printf("---k_time N volt.dat  %d %d\n",k_time,N);

fgets(b,255,f);

printf("      %s \n",b);

for(k=0;k<k_time;k++){
i=k;
fscanf(f,"%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
yy[i],yy[i]+1,yy[i]+2,yy[i]+3,yy[i]+4,yy[i]+5,yy[i]+6,yy[i]+7,
yy[i]+8,yy[i]+9,yy[i]+10,yy[i]+11);
//y[i],y[i]+1,y[i]+2,y[i]+3,y[i]+4,y[i]+5,y[i]+6,y[i]+7,y[i]+8,y[i]+9,y[i]+10,y[i]+11);
	
	for(ii=0;ii<N;ii++){
//	fscanf(f,"%lf ",&yy[ii]);
//printf("---k ii yy  %d %d %g\n",k,ii,yy[ii]);
	y[k][ii]=yy[k][ii];}
}
fscanf(f, "\n");

	mem2.N=N; /*mexPrintf(" N %d\n",N);*/
	mem2.k_time=k_time;

for(k=0;k<k_time;k++){
//	printf("---+-k==   %d\n",k);
for(ii=0;ii<N;ii++){
	mem2.y[k][ii]=y[k][ii];
 //   printf(" -+ y==  %g  ",y[k][ii]);
}
}


//fclose(f);
	} 

for (ii=0;ii<7;ii++){
read_gaps_data(ii);
read_gaps_term_data(ii);
}

read_general_data();
read_tt_kavin2_data();
read_control_data();

read_ntur_data();




}
void read_gaps_data(int n_gaps)
{

int N,i,j,k,N_g; static int kl0,kl1,kl2,kl3,kl4,kl5,kl6;
static double y_0[50][2],y1[50][2],y2[50][2],y3[50][2],y4[50][2],y5[50][2],y6[50][2];
//FILE*f;
char b[256];
char b1[1024];

int i2;


N_g=n_gaps; /*mexPrintf(" N_g %d\n",N_g);*/

//N_g=6; /*mexPrintf(" N_g %d\n",N_g);*/

//	printf("---READ_GAPS N_g %d \n",N_g);

if(N_g==0){
if(kl0==0){

	printf("---elong_ref.dat \n");

//f=fopen("elong_ref.dat","r");

//fgets(b,255,f1);

//fscanf(f1," %s ",b);
//printf ("     %s",b);

fgets(b1,1023,f1);
printf ("%s",b1);

fscanf(f1,"%d \n",&N); fgets(b,255,f1);

printf("---elong_ref.dat  N=   %d  \n",N);

for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y_0[i],y_0[i]+1);
//fclose(f);
/*for(k=0;k<N;k++)for(j=i;j<50;j++)y_0[j][k]=0;*/

mem3.N[N_g]=N;

for(j=i;j<50;j++){y_0[j][0]=y_0[j-1][0]+1; y_0[j][1]=y_0[j-1][1];}
//for(k=0;k<2;k++)for(j=0;j<50;j++)y0[k+j*2]=y_0[j][k];
for(k=0;k<2;k++)for(j=0;j<50;j++)mem3.y_0[j][k]=y_0[j][k];

j=1;
printf("---elong_ref.dat N y_01 y_02=  %d %g %g \n",N,y_0[j-1][0],y_0[j-1][1]);
j=N-1;
printf("---elong_ref.dat j-1 y_01 y_02=  %d %g %g \n",j-1,y_0[j-1][0],y_0[j-1][1]);
printf("---elong_ref.dat j y_01 y_02=  %d %g %g \n",j,y_0[j][0],y_0[j][1]);

kl0=1;}
//printf("---READ_GAPS N_g kl0 y0  %d %d %g %g %g \n",N_g,kl0,y0[0],y0[1],y0[2]);
}

if(N_g==1){
if(kl1==0){

	printf("---g1.dat \n");

//f=fopen("g1.dat","r");

//	fscanf(f1," %s ",b);
//printf ("     %s",b);

fgets(b1,1023,f1);
printf ("     %s",b1);


fscanf(f1,"%d \n",&N); 
printf("---g1.dat N=  %d  \n",N);

fgets(b,255,f1);
printf ("     %s",b);

mem3.N[N_g]=N;

for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y1[i],y1[i]+1);
//fclose(f);
/*for(k=0;k<N;k++)for(j=i;j<50;j++)y1[j][k]=0;*/
for(j=i;j<50;j++){y1[j][0]=y1[j-1][0]+1; y1[j][1]=y1[j-1][1];}
//for(k=0;k<2;k++)for(j=0;j<50;j++)y0[k+j*2]=y1[j][k];
for(k=0;k<2;k++)for(j=0;j<50;j++)mem3.y1[j][k]=y1[j][k];

j=1;
printf("---g1.dat N y_01 y_02=  %d %g %g \n",N,y1[j-1][0],y1[j-1][1]);
j=N-1;
printf("---g1.dat j-1 y_01 y_02=  %d %g %g \n",j-1,y1[j-1][0],y1[j-1][1]);
printf("---g1.dat j y_01 y_02=  %d %g %g \n",j,y1[j][0],y1[j][1]);

printf("---g1.dat end \n");

//stop:

kl1=1;}}

if(N_g==2){
if(kl2==0){

	printf("---g2.dat \n");

//f=fopen("g2.dat","r");
//	fscanf(f1," %s ",b);
//printf ("     %s",b);
fgets(b,255,f1);
printf ("     %s",b);
fscanf(f1,"%d \n",&N); fgets(b,255,f1);

printf("---g2.dat N=   %d  \n",N);

for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y2[i],y2[i]+1);
//fclose(f);

mem3.N[N_g]=N;


/*for(k=0;k<N;k++)for(j=i;j<50;j++)y2[j][k]=0;*/
for(j=i;j<50;j++){y2[j][0]=y2[j-1][0]+1; y2[j][1]=y2[j-1][1];}
//for(k=0;k<2;k++)for(j=0;j<50;j++)y0[k+j*2]=y2[j][k];
for(k=0;k<2;k++)for(j=0;j<50;j++)mem3.y2[j][k]=y2[j][k];

j=1;
printf("---g2.dat N y_01 y_02=  %d %g %g \n",N,y2[j-1][0],y2[j-1][1]);
j=N-1;
printf("---g2.dat j-1 y_01 y_02=  %d %g %g \n",j-1,y2[j-1][0],y2[j-1][1]);
printf("---g2.dat j y_01 y_02=  %d %g %g \n",j,y2[j][0],y2[j][1]);

printf("---g2.dat end \n");

kl2=1;}}

if(N_g==3){
if(kl3==0){

	printf("---g3.dat \n");

//f=fopen("g3.dat","r");
//fscanf(f1," %s ",b);
fgets(b,255,f1);
fscanf(f1,"%d \n",&N); fgets(b,255,f1);

printf("---g3.dat N=   %d  \n",N);


for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y3[i],y3[i]+1);
//fclose(f);

printf("---g3.dat end \n");

mem3.N[N_g]=N;

/*for(k=0;k<N;k++)for(j=i;j<50;j++)y3[j][k]=0;*/
for(j=i;j<50;j++){y3[j][0]=y3[j-1][0]+1; y3[j][1]=y3[j-1][1];}
//for(k=0;k<2;k++)for(j=0;j<50;j++)y0[k+j*2]=y3[j][k];
for(k=0;k<2;k++)for(j=0;j<50;j++)mem3.y3[j][k]=y3[j][k];

j=1;
printf("---g3.dat N y_01 y_02=   %d %g %g \n",N,y3[j-1][0],y3[j-1][1]);
j=N-1;
printf("---g3.dat j-1 y_01 y_02=  %d %g %g \n",j-1,y3[j-1][0],y3[j-1][1]);
printf("---g3.dat j y_01 y_02=  %d %g %g \n",j,y3[j][0],y3[j][1]);


kl3=1;}
//printf("---READ_GAPS N_g kl3 y0  %d %d %g %g %g \n",N_g,kl3,y0[0],y0[1],y0[2]);
}

if(N_g==4){
if(kl4==0){

	printf("---g4.dat \n");

//	f=fopen("g4.dat","r");
//	fscanf(f1," %s ",b);
fgets(b,255,f1);
fscanf(f1,"%d \n",&N); fgets(b,255,f1);

printf("---g4.dat N=   %d  \n",N);

for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y4[i],y4[i]+1);
//fclose(f);

mem3.N[N_g]=N;


/*for(k=0;k<N;k++)for(j=i;j<50;j++)y4[j][k]=0;*/
for(j=i;j<50;j++){y4[j][0]=y4[j-1][0]+1; y4[j][1]=y4[j-1][1];}
//for(k=0;k<2;k++)for(j=0;j<50;j++)y0[k+j*2]=y4[j][k];
for(k=0;k<2;k++)for(j=0;j<50;j++)mem3.y4[j][k]=y4[j][k];

j=1;
printf("---g4.dat N y_01 y_02=   %d %g %g \n",N,y4[j-1][0],y4[j-1][1]);
j=N-1;
printf("---g4.dat j-1 y_01 y_02=   %d %g %g \n",j-1,y4[j-1][0],y4[j-1][1]);
printf("---g4.dat j y_01 y_02=   %d %g %g \n",j,y4[j][0],y4[j][1]);

printf("---g4.dat end \n");

kl4=1;}}

if(N_g==5){
if(kl5==0){

	printf("---g5.dat \n");

//f=fopen("g5.dat","r");
//fscanf(f1," %s ",b);
fgets(b,255,f1);
fscanf(f1,"%d \n",&N); fgets(b,255,f1);

printf("---g5.dat N=   %d  \n",N);

for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y5[i],y5[i]+1);
//fclose(f);
mem3.N[N_g]=N;

/*for(k=0;k<N;k++)for(j=i;j<50;j++)y5[j][k]=0;*/
for(j=i;j<50;j++){y5[j][0]=y5[j-1][0]+1; y5[j][1]=y5[j-1][1];}
//for(k=0;k<2;k++)for(j=0;j<50;j++)y0[k+j*2]=y5[j][k];
for(k=0;k<2;k++)for(j=0;j<50;j++)mem3.y5[j][k]=y5[j][k];

j=1;
printf("---g5.dat N y_01 y_02=   %d %g %g \n",N,y5[j-1][0],y5[j-1][1]);
j=N-1;
printf("---g5.dat j-1 y_01 y_02=  %d %g %g \n",j-1,y5[j-1][0],y5[j-1][1]);
printf("---g5.dat j y_01 y_02=  %d %g %g \n",j,y5[j][0],y5[j][1]);

printf("---g5.dat end \n");
kl5=1;}}

if(N_g==6){
if(kl6==0){

	printf("---g6.dat \n");

//f=fopen("g6.dat","r");
//fscanf(f1," %s ",b);
fgets(b,255,f1);
fscanf(f1,"%d \n",&N); fgets(b,255,f1);

printf("---g6.dat N=   %d  \n",N);

for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y6[i],y6[i]+1);
//fclose(f);

mem3.N[N_g]=N;

/*for(k=0;k<N;k++)for(j=i;j<50;j++)y6[j][k]=0;*/
for(j=i;j<50;j++){y6[j][0]=y6[j-1][0]+1; y6[j][1]=y6[j-1][1];}
//for(k=0;k<2;k++)for(j=0;j<50;j++)y0[k+j*2]=y6[j][k];
for(k=0;k<2;k++)for(j=0;j<50;j++)mem3.y6[j][k]=y6[j][k];
j=1;
printf("---g6.dat N y_01 y_02=  %d %g %g \n",N,y6[j-1][0],y6[j-1][1]);
j=N-1;
printf("---g6.dat j-1 y_01 y_02=  %d %g %g \n",j-1,y6[j-1][0],y6[j-1][1]);
printf("---g6.dat j y_01 y_02=  %d %g %g \n",j,y6[j][0],y6[j][1]);

printf("---g6.dat end \n");
kl6=1;}}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */


}

void read_gaps_term_data(n_gaps)
{
int N,i,j,k,N_g; static int k1,k2,k3,k4,k5,k6;
double y_1[50][2],y_2[50][2],y_3[50][2],y_4[50][2],y_5[50][2],y_6[50][2];
//FILE*f;
char b[256];
int i2;


N_g=n_gaps; /*mexPrintf(" N_g %d\n",N_g);*/

//N_g=6; 



if(N_g==1){
if(k1==0){

	printf("---g1_term.dat \n");

//f=fopen("g1_term.dat","r");
//	fscanf(f1," %s ",b);
//printf ("     %s",b);

fgets(b,255,f1);
printf ("     %s",b);


fscanf(f1,"%d \n",&N); 
printf("---g1_term.dat N  %d  \n",N);

fgets(b,255,f1);
printf ("     %s",b);

mem4.N[N_g]=N;

for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y_1[i],y_1[i]+1);
//fclose(f);
/*for(k=0;k<N;k++)for(j=i;j<50;j++)y_1[j][k]=0;
for(j=i;j<50;j++)y_1[j][0]=y_1[j-1][0]+1;*/
for(j=i;j<50;j++){y_1[j][0]=y_1[j-1][0]+1; y_1[j][1]=y_1[j-1][1];}
for(k=0;k<2;k++)for(j=0;j<50;j++)mem4.y_1[j][k]=y_1[j][k];

j=1;
printf("---g1_term.dat N y_01 y_02 %d %g %g \n",N,y_1[j-1][0],y_1[j-1][1]);
j=N-1;
printf("---g1_term.dat j-1 y_01 y_02 %d %g %g \n",j-1,y_1[j-1][0],y_1[j-1][1]);
printf("---g1_term.dat j y_01 y_02 %d %g %g \n",j,y_1[j][0],y_1[j][1]);

printf("---g1_term-- end.dat \n");

//scanf("%d", &i2);


k1=1;}}

if(N_g==2){
if(k2==0){

	printf("---g2_term.dat \n");

//f=fopen("g2_term.dat","r");
//	fscanf(f1," %s ",b);
//printf ("     %s",b);
fgets(b,255,f1);
fscanf(f1,"%d \n",&N); 
printf("---g2_term.dat N  %d  \n",N);

fgets(b,255,f1);

mem4.N[N_g]=N;


for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y_2[i],y_2[i]+1);
//fclose(f);
/*for(k=0;k<N;k++)for(j=i;j<50;j++)y_2[j][k]=0;
for(j=i;j<50;j++)y_2[j][0]=y_2[j-1][0]+1;*/
for(j=i;j<50;j++){y_2[j][0]=y_2[j-1][0]+1; y_2[j][1]=y_2[j-1][1];}
for(k=0;k<2;k++)for(j=0;j<50;j++)mem4.y_2[j][k]=y_2[j][k];

j=1;
printf("---g2_term.dat N y_01 y_02 %d %g %g \n",N,y_2[j-1][0],y_2[j-1][1]);
j=N-1;
printf("---g2_term.dat j-1 y_01 y_02 %d %g %g \n",j-1,y_2[j-1][0],y_2[j-1][1]);
printf("---g2_term.dat j y_01 y_02 %d %g %g \n",j,y_2[j][0],y_2[j][1]);

printf("---g2_term-- end.dat \n");


k2=1;}}

if(N_g==3){
if(k3==0){

	printf("---g3_term.dat \n");

//f=fopen("g3_term.dat","r");
//fscanf(f1," %s ",b);
fgets(b,255,f1);
fscanf(f1,"%d \n",&N); 

printf("---g3_term.dat N  %d  \n",N);

fgets(b,255,f1);

mem4.N[N_g]=N;


for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y_3[i],y_3[i]+1);
//fclose(f);
/*for(k=0;k<N;k++)for(j=i;j<50;j++)y_3[j][k]=0;
for(j=i;j<50;j++)y_3[j][0]=y_3[j-1][0]+1;*/
for(j=i;j<50;j++){y_3[j][0]=y_3[j-1][0]+1; y_3[j][1]=y_3[j-1][1];}
for(k=0;k<2;k++)for(j=0;j<50;j++)mem4.y_3[j][k]=y_3[j][k];
j=1;
printf("---g3_term.dat N y_01 y_02 %d %g %g \n",N,y_3[j-1][0],y_3[j-1][1]);
j=N-1;
printf("---g3_term.dat j-1 y_01 y_02 %d %g %g \n",j-1,y_3[j-1][0],y_3[j-1][1]);
printf("---g3_term.dat j y_01 y_02 %d %g %g \n",j,y_3[j][0],y_3[j][1]);

printf("---g3_term-- end.dat \n");
k3=1;}}

if(N_g==4){
if(k4==0){

	printf("---g4_term.dat \n");

//f=fopen("g4_term.dat","r");
//fscanf(f1," %s ",b);
fgets(b,255,f1);



fscanf(f1,"%d \n",&N); 
printf("---g4_term.dat N  %d  \n",N);

fgets(b,255,f1);

mem4.N[N_g]=N;


for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y_4[i],y_4[i]+1);
//fclose(f);
/*for(k=0;k<N;k++)for(j=i;j<50;j++)y_4[j][k]=0;
for(j=i;j<50;j++)y_4[j][0]=y_4[j-1][0]+1;*/
for(j=i;j<50;j++){y_4[j][0]=y_4[j-1][0]+1; y_4[j][1]=y_4[j-1][1];}
for(k=0;k<2;k++)for(j=0;j<50;j++)mem4.y_4[j][k]=y_4[j][k];
j=1;
printf("---g4_term.dat N y_01 y_02 %d %g %g \n",N,y_4[j-1][0],y_4[j-1][1]);
j=N-1;
printf("---g4_term.dat j-1 y_01 y_02 %d %g %g \n",j-1,y_4[j-1][0],y_4[j-1][1]);
printf("---g4_term.dat j y_01 y_02 %d %g %g \n",j,y_4[j][0],y_4[j][1]);

printf("---g4_term-- end.dat \n");
k4=1;}}

if(N_g==5){
if(k5==0){

	printf("---g5_term.dat \n");

//f=fopen("g5_term.dat","r");
//fscanf(f1," %s ",b);
fgets(b,255,f1);
fscanf(f1,"%d \n",&N); 
printf("---g5_term.dat N  %d  \n",N);

fgets(b,255,f1);

mem4.N[N_g]=N;


for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y_5[i],y_5[i]+1);
//fclose(f);
/*for(k=0;k<N;k++)for(j=i;j<50;j++)y_5[j][k]=0;
for(j=i;j<50;j++)y_5[j][0]=y_5[j-1][0]+1;*/
for(j=i;j<50;j++){y_5[j][0]=y_5[j-1][0]+1; y_5[j][1]=y_5[j-1][1];}
for(k=0;k<2;k++)for(j=0;j<50;j++)mem4.y_5[j][k]=y_5[j][k];
j=1;
printf("---g5_term.dat N y_01 y_02 %d %g %g \n",N,y_5[j-1][0],y_5[j-1][1]);
j=N-1;
printf("---g5_term.dat j-1 y_01 y_02 %d %g %g \n",j-1,y_5[j-1][0],y_5[j-1][1]);
printf("---g5_term.dat j y_01 y_02 %d %g %g \n",j,y_5[j][0],y_5[j][1]);

printf("---g5_term-- end.dat \n");
k5=1;}}

if(N_g==6){
if(k6==0){

	printf("---g6_term.dat \n");

//f=fopen("g6_term.dat","r");
//fscanf(f1," %s ",b);
fgets(b,255,f1);
fscanf(f1,"%d \n",&N); 

printf("---g5_term.dat N  %d  \n",N);

fgets(b,255,f1);

mem4.N[N_g]=N;


for(i=0;i<N;i++) fscanf(f1,"%lf %lf \n",y_6[i],y_6[i]+1);
//fclose(f);
/*for(k=0;k<N;k++)for(j=i;j<50;j++)y_6[j][k]=0;
for(j=i;j<50;j++)y_6[j][0]=y_6[j-1][0]+1;*/
for(j=i;j<50;j++){y_6[j][0]=y_6[j-1][0]+1; y_6[j][1]=y_6[j-1][1];}
for(k=0;k<2;k++)for(j=0;j<50;j++)mem4.y_6[j][k]=y_6[j][k];
j=1;
printf("---g6_term.dat N y_01 y_02 %d %g %g \n",N,y_6[j-1][0],y_6[j-1][1]);
j=N-1;
printf("---g6_term.dat j-1 y_01 y_02 %d %g %g \n",j-1,y_6[j-1][0],y_6[j-1][1]);
printf("---g6_term.dat j y_01 y_02 %d %g %g \n",j,y_6[j][0],y_6[j][1]);

printf("---g6_term-- end.dat \n");
k6=1;}}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


void read_control_data(void)
{

int i,k,kk; static int kl;
double y[26],dd;
char b[256];


kk=5;

printf("---control_data.dat \n");
//f=fopen("control_data.dat","r");
fgets(b,255,f);
printf (" 1) %s",b);
for(i=0; i<=14; i++) fscanf(f,"%lf",&y[i]);

fscanf(f, "\n");

fgets(b,255,f);
printf (" 2) %s",b);
//fscanf(f,"%s",&b);
//mexPrintf("%s\n",b);
for(i=14; i<=25; i++) fscanf(f,"%lf",&y[i]);

fscanf(f, "\n");

for(i=0;i<=25;i++) {
	kk=kk+1;
//	y0[kk]=y[i];
	mem5.y[i]=y[i];
}
kk=kk+1;

printf("---control_data-- end.dat \n");

}

/* Subroutine */ read_ntur_data(void)
{
    int i, j, ii, nmax1;
    char s_ncam[50];

	double ss;

	static int kmax;
	double ntur[kf];
	int i_en, npf;
	char b[1256];

	i_en=0;
	
	npf=11;

	mexPrintf(" i_en  %d  \n ",i_en);
		
	printf("---control_data.dat ntur \n");
 
	fgets(b,1255,f);

	printf("%s  ",b);

	for (j = 0; j < npf; ++j) {
	fscanf(f, "%lf",&ss);
	ntur[j]=ss;
		mexPrintf("%g ",ntur[j]);
     }

    	for (j = 0; j < npf; ++j) {
		mem8.ntur[j]=ntur[j];}
	

	mem8.npf=npf;

} /* scen_read */

/* Subroutine */ read_general_data(void)
{
    int i, j, ii, nmax1;
    char s_ncam[50];

	float ss;

	static int kmax;
	static double pf[nmax][kf];
	static double t[nmax],tpl[nmax];
	int res;
	int i_en, npf;
	char b[1256];

	i_en=0;
	
	npf=11;

	if(i_en > 1){goto l2;}

	mexPrintf(" i_en  %d  \n ",i_en);
	
	prob=fopen("general_data.dat","r");
	f2=prob;

	printf("---general_data.dat \n");

//	fscanf(prob, "%s ", &s_ncam);
 
	fgets(b,1255,prob);

	printf("%s  ",b);

    fscanf(prob, "%d ",&nmax1);

	fgets(b,1255,prob);
	printf("%s  ",b);

	printf(" nmax1===  %d \n ",nmax1);

	for (i = 1; i <= nmax1; ++i) {

	res=fscanf(prob, " \n %f",&ss);

	kmax=i;

	t[i]=ss;

	mexPrintf(" i res t %d %d %f \n",i,res,t[i]);

    //printf(" i %d \n ",i);
    //printf(" rc %g  ",rc[i]);
	fscanf(prob, "%f",&ss);
	tpl[i]=ss;
	mexPrintf(" i t tpl  %d %f %f \n ",i,t[i],tpl[i]);
    //printf(" zc %g  ",zc[i]);
	for (j = 1; j <= npf; ++j) {
	fscanf(prob, "%f",&ss);
	pf[i][j]=ss;
		mexPrintf("%f ",pf[i][j]);
     }
    	
	    fscanf(prob, "\n");

		mexPrintf(" \n   ");

						 
								 }

l1:

/* close (41) */

	mexPrintf(" l1 final  i res %d %d \n   ",i,res);

//	fclose(f);

//	return 0;


	kmax=kmax+1;
	i=kmax;
	t[i]=10000.;
	tpl[i]=tpl[i-1];
	for (j = 1; j <= npf; ++j) {
	pf[i][j]=pf[i-1][j];}

//	goto l2;


	i=0;
	t[i]=-1.e-5;
	tpl[i]=tpl[i+1];
	for (j = 1; j <= npf; ++j) {
	pf[i][j]=pf[i+1][j];}

l2:


	for (i = 0; i <= kmax; ++i) {
		mem6.t[i]=t[i];
		mem6.tpl[i]=tpl[i];
    	for (j = 1; j <= npf; ++j) {
		mem6.pf[i][j]=pf[i][j];}
	}

	mem6.kmax=kmax;

} /* scen_read */
void read_tt_kavin2_data(void)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
int i,k,kk; static int kl;
double y[26],y0[26],dd;
char b[256];

kk=0;
	printf("---tt_kavin2.dat \n");
//f=fopen("tt_kavin2.dat","r");
fgets(b,255,f2);
printf (" 1) %s",b);

fscanf(f2,"%lf \n ",&y[0]);
y[0]=y[0]*1e-3; 

printf("---y[0]  %g \n",y[0]);

fgets(b,255,f2);
printf (" 2) %s",b);

for(i=1;i<4;i++) fscanf(f2,"%lf %lf %lf \n",&y[i],&y[i]+1,&y[i]+2);
y0[0]=y[0];y0[1]=y[2];y0[2]=y[3];y0[3]=y[1]; 

printf("---y[1] y[2] y[3]  %g %g %g \n",y[1],y[2],y[3]);

fgets(b,255,f2);
printf (" 3)%s",b);

fscanf(f2,"%lf %lf  \n",&y[4],&y[5]);
y0[4]=y[4];y0[5]=y[5];

printf("---y4 y5  %g %g  \n",y[4],y[5]);

fclose(f2);

for(i=0;i<6;i++){
	mem7.y[i]=y[i];}

printf("---tt_kavin2-- end.dat \n");
}

