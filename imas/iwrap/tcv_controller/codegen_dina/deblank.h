/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: deblank.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 28-Apr-2026 10:26:51
 */

#ifndef DEBLANK_H
#define DEBLANK_H

/* Include Files */
#include "hybctrl_step_IDS_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_deblank(const char x[7], emxArray_char_T *y);

void c_deblank(const char x[8], emxArray_char_T *y);

void d_deblank(const char x[9], emxArray_char_T *y);

void deblank(const char x[6], emxArray_char_T *y);

void e_deblank(const char x[10], emxArray_char_T *y);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for deblank.h
 *
 * [EOF]
 */
