/*
 * File: t15_2_private.h
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

#ifndef RTW_HEADER_t15_2_private_h_
#define RTW_HEADER_t15_2_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void pf_lookup3_Outputs_wrapper(real_T *y0,
  const real_T *n_pf, const int_T p_width0);
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi);
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi);

#endif                                 /* RTW_HEADER_t15_2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
