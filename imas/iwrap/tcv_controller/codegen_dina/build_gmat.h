/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: build_gmat.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 28-Apr-2026 10:26:51
 */

#ifndef BUILD_GMAT_H
#define BUILD_GMAT_H

/* Include Files */
#include "hybctrl_step_IDS_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void build_gmat(const double Gmat_addr_time[10],
                const double Gmat_addr_data[10], const double Gmat_G1I[5720],
                const double Gmat_G2P[5720], const double Gmat_G3D[5720],
                double t, emxArray_real_T *G, emxArray_real_T *iG,
                emxArray_real_T *G2P, emxArray_real_T *G1I,
                emxArray_real_T *G3D);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for build_gmat.h
 *
 * [EOF]
 */
