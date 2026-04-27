/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: find.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Apr-2026 10:42:42
 */

/* Include Files */
#include "find.h"
#include "hybctrl_step_IDS_emxutil.h"
#include "hybctrl_step_IDS_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const boolean_T x[29]
 *                emxArray_int32_T *i
 * Return Type  : void
 */
void eml_find(const boolean_T x[29], emxArray_int32_T *i)
{
  int idx;
  int ii;
  int *i_data;
  boolean_T exitg1;
  idx = 0;
  ii = i->size[0];
  i->size[0] = 29;
  emxEnsureCapacity_int32_T(i, ii);
  i_data = i->data;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 29)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 29) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  ii = i->size[0];
  if (idx < 1) {
    i->size[0] = 0;
  } else {
    i->size[0] = idx;
  }
  emxEnsureCapacity_int32_T(i, ii);
}

/*
 * File trailer for find.c
 *
 * [EOF]
 */
