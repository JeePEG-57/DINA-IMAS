/*
 * File: rt_SATURATE.h
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

#ifndef RTW_HEADER_rt_SATURATE_h_
#define RTW_HEADER_rt_SATURATE_h_
#define rt_SATURATE(sig,ll,ul)         (((sig) >= (ul)) ? (ul) : (((sig) <= (ll)) ? (ll) : (sig)) )
#endif                                 /* RTW_HEADER_rt_SATURATE_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
