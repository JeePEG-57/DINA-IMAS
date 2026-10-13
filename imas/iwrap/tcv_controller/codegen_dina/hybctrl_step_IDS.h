/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: hybctrl_step_IDS.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 28-Apr-2026 10:26:51
 */

#ifndef HYBCTRL_STEP_IDS_H
#define HYBCTRL_STEP_IDS_H

/* Include Files */
#include "hybctrl_step_IDS_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void hybctrl_step_IDS(double t, const struct0_T *magn,
                             const struct1_T *pfa, const double Arefs[26],
                             const struct2_T *cpar, struct8_T *cstate,
                             double cout[19]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for hybctrl_step_IDS.h
 *
 * [EOF]
 */
