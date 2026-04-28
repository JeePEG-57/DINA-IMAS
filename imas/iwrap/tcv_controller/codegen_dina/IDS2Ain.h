/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: IDS2Ain.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 28-Apr-2026 10:26:51
 */

#ifndef IDS2AIN_H
#define IDS2AIN_H

/* Include Files */
#include "hybctrl_step_IDS_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void IDS2Ain(const double magn_Bm[38], double magn_Ff[38],
             const double pfa_Ia[29], const cell_wrap_0 pfa_names[29],
             const cell_1 *dimm, double Ain[117]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for IDS2Ain.h
 *
 * [EOF]
 */
