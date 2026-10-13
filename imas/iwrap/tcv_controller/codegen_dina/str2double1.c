/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: str2double1.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 28-Apr-2026 10:26:51
 */

/* Include Files */
#include "str2double1.h"
#include "hybctrl_step_IDS_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : char s1[5]
 *                int *idx
 *                const char s[3]
 *                int *k
 *                int n
 *                boolean_T allowpoint
 * Return Type  : boolean_T
 */
boolean_T copydigits(char s1[5], int *idx, const char s[3], int *k, int n,
                     boolean_T allowpoint)
{
  boolean_T exitg1;
  boolean_T haspoint;
  boolean_T success;
  success = (*k <= n);
  haspoint = false;
  exitg1 = false;
  while ((!exitg1) && (success && (*k <= n))) {
    char c;
    c = s[*k - 1];
    if ((c >= '0') && (c <= '9')) {
      s1[*idx - 1] = c;
      (*idx)++;
      (*k)++;
    } else if (c == '.') {
      if (allowpoint && (!haspoint)) {
        success = true;
      } else {
        success = false;
      }
      if (success) {
        s1[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
      }
      (*k)++;
    } else if (c == ',') {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }
  return success;
}

/*
 * Arguments    : char s1[5]
 *                int *idx
 *                const char s[3]
 *                int *k
 *                int n
 * Return Type  : boolean_T
 */
boolean_T copyexponent(char s1[5], int *idx, const char s[3], int *k, int n)
{
  boolean_T success;
  success = true;
  if (*k <= n) {
    char c;
    c = s[*k - 1];
    if ((c == 'E') || (c == 'e')) {
      int kexp;
      boolean_T b_success;
      s1[*idx - 1] = 'e';
      (*idx)++;
      (*k)++;
      while ((*k <= n) && (s[*k - 1] == ',')) {
        (*k)++;
      }
      if (*k <= n) {
        if (s[*k - 1] == '-') {
          s1[*idx - 1] = '-';
          (*idx)++;
          (*k)++;
        } else if (s[*k - 1] == '+') {
          (*k)++;
        }
      }
      kexp = *k;
      b_success = copydigits(s1, idx, s, k, n, false);
      if ((!b_success) || (*k <= kexp)) {
        success = false;
      }
    }
  }
  return success;
}

/*
 * Arguments    : const char s[3]
 *                int k
 *                int n
 * Return Type  : boolean_T
 */
boolean_T isUnitImag(const char s[3], int k, int n)
{
  boolean_T p;
  p = false;
  if (k <= n) {
    char c_idx_0;
    c_idx_0 = s[k - 1];
    if (c_idx_0 == 'j') {
      p = true;
    } else if (c_idx_0 == 'i') {
      if (k >= n - 1) {
        p = true;
      } else {
        int b_k;
        char c_idx_1;
        char c_idx_2;
        b_k = k;
        c_idx_0 = '\x00';
        while ((b_k <= n) && (s[b_k - 1] == ',')) {
          b_k++;
        }
        if (b_k <= n) {
          c_idx_0 = s[b_k - 1];
        }
        b_k++;
        c_idx_1 = '\x00';
        while ((b_k <= n) && (s[b_k - 1] == ',')) {
          b_k++;
        }
        if (b_k <= n) {
          c_idx_1 = s[b_k - 1];
        }
        b_k++;
        c_idx_2 = '\x00';
        while ((b_k <= n) && (s[b_k - 1] == ',')) {
          b_k++;
        }
        if (b_k <= n) {
          c_idx_2 = s[b_k - 1];
        }
        if ((((c_idx_0 != 'I') && (c_idx_0 != 'i')) ||
             ((c_idx_1 != 'N') && (c_idx_1 != 'n')) ||
             ((c_idx_2 != 'F') && (c_idx_2 != 'f'))) &&
            (((c_idx_0 != 'N') && (c_idx_0 != 'n')) ||
             ((c_idx_1 != 'A') && (c_idx_1 != 'a')) ||
             ((c_idx_2 != 'N') && (c_idx_2 != 'n')))) {
          p = true;
        }
      }
    }
  }
  return p;
}

/*
 * Arguments    : const char s[3]
 *                int *k
 *                int n
 *                boolean_T *b_finite
 *                double *fv
 * Return Type  : void
 */
void readNonFinite(const char s[3], int *k, int n, boolean_T *b_finite,
                   double *fv)
{
  int ksaved;
  char c_idx_0;
  char c_idx_1;
  char c_idx_2;
  ksaved = *k;
  c_idx_0 = '\x00';
  while ((*k <= n) && (s[*k - 1] == ',')) {
    (*k)++;
  }
  if (*k <= n) {
    c_idx_0 = s[*k - 1];
  }
  (*k)++;
  c_idx_1 = '\x00';
  while ((*k <= n) && (s[*k - 1] == ',')) {
    (*k)++;
  }
  if (*k <= n) {
    c_idx_1 = s[*k - 1];
  }
  (*k)++;
  c_idx_2 = '\x00';
  while ((*k <= n) && (s[*k - 1] == ',')) {
    (*k)++;
  }
  if (*k <= n) {
    c_idx_2 = s[*k - 1];
  }
  (*k)++;
  if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) &&
      ((c_idx_1 == 'N') || (c_idx_1 == 'n')) &&
      ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
    *b_finite = false;
    *fv = rtInf;
  } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) &&
             ((c_idx_1 == 'A') || (c_idx_1 == 'a')) &&
             ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
    *b_finite = false;
    *fv = rtNaN;
  } else {
    *b_finite = true;
    *fv = 0.0;
    *k = ksaved;
  }
}

/*
 * Arguments    : char s1[5]
 *                int *idx
 *                const char s[3]
 *                int *k
 *                int n
 *                boolean_T allowimag
 *                boolean_T *isimag
 *                boolean_T *b_finite
 *                double *nfv
 *                boolean_T *foundsign
 *                boolean_T *success
 * Return Type  : void
 */
void readfloat(char s1[5], int *idx, const char s[3], int *k, int n,
               boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
               double *nfv, boolean_T *foundsign, boolean_T *success)
{
  int b_idx;
  char c;
  boolean_T a__3;
  boolean_T exitg1;
  boolean_T isneg;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_idx = *idx;
  isneg = false;
  *foundsign = false;
  exitg1 = false;
  while ((!exitg1) && (*k <= n)) {
    c = s[*k - 1];
    if (c == '-') {
      isneg = !isneg;
      *foundsign = true;
      (*k)++;
    } else if (c == ',') {
      (*k)++;
    } else if (c == '+') {
      *foundsign = true;
      (*k)++;
    } else if (!bv[(unsigned char)c & 127]) {
      exitg1 = true;
    } else {
      (*k)++;
    }
  }
  *success = (*k <= n);
  if ((*success) && isneg) {
    if ((*idx >= 2) && (s1[*idx - 2] == '-')) {
      s1[*idx - 2] = ' ';
    } else {
      s1[*idx - 1] = '-';
      b_idx = *idx + 1;
    }
  }
  *idx = b_idx;
  if (*success) {
    if (isUnitImag(s, *k, n)) {
      if (allowimag) {
        *isimag = true;
        (*k)++;
        exitg1 = false;
        while ((!exitg1) && (*k <= n)) {
          c = s[*k - 1];
          if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
            (*k)++;
          } else {
            exitg1 = true;
          }
        }
        if ((*k <= n) && (s[*k - 1] == '*')) {
          (*k)++;
          readfloat(s1, idx, s, k, n, false, &isneg, b_finite, nfv, &a__3,
                    success);
        } else {
          s1[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      readNonFinite(s, k, n, b_finite, nfv);
      if (*b_finite) {
        *success = copydigits(s1, idx, s, k, n, true);
        if (*success) {
          *success = copyexponent(s1, idx, s, k, n);
        }
      } else if ((b_idx >= 2) && (s1[b_idx - 2] == '-')) {
        *idx = b_idx - 1;
        s1[b_idx - 2] = ' ';
        *nfv = -*nfv;
      }
      exitg1 = false;
      while ((!exitg1) && (*k <= n)) {
        if (bv[(unsigned char)s[*k - 1] & 127]) {
          (*k)++;
        } else {
          c = s[*k - 1];
          if ((c == '\x00') || (c == ',')) {
            (*k)++;
          } else {
            exitg1 = true;
          }
        }
      }
      if ((*k <= n) && (s[*k - 1] == '*')) {
        (*k)++;
        while ((*k <= n) && (bv[(unsigned char)s[*k - 1] & 127] ||
                             (s[*k - 1] == '\x00') || (s[*k - 1] == ','))) {
          (*k)++;
        }
      }
      if (*k <= n) {
        c = s[*k - 1];
        if ((c == 'i') || (c == 'j')) {
          (*k)++;
          *isimag = true;
        }
      }
    }
    exitg1 = false;
    while ((!exitg1) && (*k <= n)) {
      c = s[*k - 1];
      if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
        (*k)++;
      } else {
        exitg1 = true;
      }
    }
  }
}

/*
 * File trailer for str2double1.c
 *
 * [EOF]
 */
