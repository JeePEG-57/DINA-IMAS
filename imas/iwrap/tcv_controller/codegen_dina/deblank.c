/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: deblank.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 28-Apr-2026 10:26:51
 */

/* Include Files */
#include "deblank.h"
#include "hybctrl_step_IDS_data.h"
#include "hybctrl_step_IDS_emxutil.h"
#include "hybctrl_step_IDS_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const char x[7]
 *                emxArray_char_T *y
 * Return Type  : void
 */
void b_deblank(const char x[7], emxArray_char_T *y)
{
  int i;
  int ncols;
  char *y_data;
  boolean_T exitg1;
  ncols = 6;
  exitg1 = false;
  while ((!exitg1) && (ncols + 1 > 0)) {
    i = (unsigned char)x[ncols];
    if ((i != 0) && (!bv[i & 127])) {
      exitg1 = true;
    } else {
      ncols--;
    }
  }
  if (ncols + 1 < 1) {
    ncols = -1;
  }
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ncols + 1;
  emxEnsureCapacity_char_T(y, i);
  y_data = y->data;
  for (i = 0; i <= ncols; i++) {
    y_data[i] = x[i];
  }
}

/*
 * Arguments    : const char x[8]
 *                emxArray_char_T *y
 * Return Type  : void
 */
void c_deblank(const char x[8], emxArray_char_T *y)
{
  int i;
  int ncols;
  char *y_data;
  boolean_T exitg1;
  ncols = 7;
  exitg1 = false;
  while ((!exitg1) && (ncols + 1 > 0)) {
    i = (unsigned char)x[ncols];
    if ((i != 0) && (!bv[i & 127])) {
      exitg1 = true;
    } else {
      ncols--;
    }
  }
  if (ncols + 1 < 1) {
    ncols = -1;
  }
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ncols + 1;
  emxEnsureCapacity_char_T(y, i);
  y_data = y->data;
  for (i = 0; i <= ncols; i++) {
    y_data[i] = x[i];
  }
}

/*
 * Arguments    : const char x[9]
 *                emxArray_char_T *y
 * Return Type  : void
 */
void d_deblank(const char x[9], emxArray_char_T *y)
{
  int i;
  int ncols;
  char *y_data;
  boolean_T exitg1;
  ncols = 8;
  exitg1 = false;
  while ((!exitg1) && (ncols + 1 > 0)) {
    i = (unsigned char)x[ncols];
    if ((i != 0) && (!bv[i & 127])) {
      exitg1 = true;
    } else {
      ncols--;
    }
  }
  if (ncols + 1 < 1) {
    ncols = -1;
  }
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ncols + 1;
  emxEnsureCapacity_char_T(y, i);
  y_data = y->data;
  for (i = 0; i <= ncols; i++) {
    y_data[i] = x[i];
  }
}

/*
 * Arguments    : const char x[6]
 *                emxArray_char_T *y
 * Return Type  : void
 */
void deblank(const char x[6], emxArray_char_T *y)
{
  int i;
  int ncols;
  char *y_data;
  boolean_T exitg1;
  ncols = 5;
  exitg1 = false;
  while ((!exitg1) && (ncols + 1 > 0)) {
    i = (unsigned char)x[ncols];
    if ((i != 0) && (!bv[i & 127])) {
      exitg1 = true;
    } else {
      ncols--;
    }
  }
  if (ncols + 1 < 1) {
    ncols = -1;
  }
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ncols + 1;
  emxEnsureCapacity_char_T(y, i);
  y_data = y->data;
  for (i = 0; i <= ncols; i++) {
    y_data[i] = x[i];
  }
}

/*
 * Arguments    : const char x[10]
 *                emxArray_char_T *y
 * Return Type  : void
 */
void e_deblank(const char x[10], emxArray_char_T *y)
{
  int i;
  int ncols;
  char *y_data;
  boolean_T exitg1;
  ncols = 9;
  exitg1 = false;
  while ((!exitg1) && (ncols + 1 > 0)) {
    i = (unsigned char)x[ncols];
    if ((i != 0) && (!bv[i & 127])) {
      exitg1 = true;
    } else {
      ncols--;
    }
  }
  if (ncols + 1 < 1) {
    ncols = -1;
  }
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ncols + 1;
  emxEnsureCapacity_char_T(y, i);
  y_data = y->data;
  for (i = 0; i <= ncols; i++) {
    y_data[i] = x[i];
  }
}

/*
 * File trailer for deblank.c
 *
 * [EOF]
 */
