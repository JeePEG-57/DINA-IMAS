/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: str2double.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Apr-2026 10:42:42
 */

/* Include Files */
#include "str2double.h"
#include "hybctrl_step_IDS_data.h"
#include "rt_nonfinite.h"
#include "str2double1.h"
#include <stdio.h>

/* Function Definitions */
/*
 * Arguments    : const char s[3]
 * Return Type  : creal_T
 */
creal_T str2double(const char s[3])
{
  creal_T x;
  double scanned1;
  double scanned2;
  int i;
  int idx;
  int k;
  int ntoread;
  char s1[5];
  char c;
  boolean_T a__3;
  boolean_T b_finite;
  boolean_T exitg1;
  boolean_T foundsign;
  boolean_T isimag1;
  boolean_T isneg;
  boolean_T success;
  x.re = rtNaN;
  x.im = 0.0;
  ntoread = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k <= 3)) {
    c = s[k - 1];
    if (bv[(unsigned char)c & 127] || (c == '\x00')) {
      k++;
    } else {
      exitg1 = true;
    }
  }
  isimag1 = false;
  b_finite = true;
  scanned1 = 0.0;
  idx = 1;
  for (i = 0; i < 5; i++) {
    s1[i] = '\x00';
  }
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (k <= 3)) {
    c = s[k - 1];
    if (c == '-') {
      isneg = !isneg;
      k++;
    } else if ((c == ',') || (c == '+') || bv[(unsigned char)c & 127]) {
      k++;
    } else {
      exitg1 = true;
    }
  }
  success = (k <= 3);
  if (success && isneg) {
    s1[0] = '-';
    idx = 2;
  }
  if (success) {
    if (isUnitImag(s, k, 3)) {
      isimag1 = true;
      k++;
      exitg1 = false;
      while ((!exitg1) && (k <= 3)) {
        c = s[k - 1];
        if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
          k++;
        } else {
          exitg1 = true;
        }
      }
      if ((k <= 3) && (s[k - 1] == '*')) {
        k++;
        readfloat(s1, &idx, s, &k, 3, false, &isneg, &b_finite, &scanned1,
                  &a__3, &success);
      } else {
        s1[idx - 1] = '1';
        idx++;
      }
    } else {
      readNonFinite(s, &k, 3, &b_finite, &scanned1);
      if (b_finite) {
        success = copydigits(s1, &idx, s, &k, 3, true);
        if (success) {
          success = copyexponent(s1, &idx, s, &k, 3);
        }
      } else if ((idx >= 2) && (s1[0] == '-')) {
        idx = 1;
        s1[0] = ' ';
        scanned1 = -scanned1;
      }
      exitg1 = false;
      while ((!exitg1) && (k <= 3)) {
        c = s[k - 1];
        if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
          k++;
        } else {
          exitg1 = true;
        }
      }
      if ((k <= 3) && (s[k - 1] == '*')) {
        k++;
        exitg1 = false;
        while ((!exitg1) && (k <= 3)) {
          c = s[k - 1];
          if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
            k++;
          } else {
            exitg1 = true;
          }
        }
      }
      if (k <= 3) {
        c = s[k - 1];
        if ((c == 'i') || (c == 'j')) {
          k++;
          isimag1 = true;
        }
      }
    }
    exitg1 = false;
    while ((!exitg1) && (k <= 3)) {
      c = s[k - 1];
      if (bv[(unsigned char)c & 127] || (c == '\x00') || (c == ',')) {
        k++;
      } else {
        exitg1 = true;
      }
    }
  }
  if (b_finite) {
    ntoread = 1;
  }
  if (success && (k <= 3)) {
    s1[idx - 1] = ' ';
    idx++;
    readfloat(s1, &idx, s, &k, 3, true, &isneg, &a__3, &scanned2, &foundsign,
              &success);
    if (a__3) {
      ntoread++;
    }
    if (success && (k > 3) && ((boolean_T)(isimag1 ^ isneg)) && foundsign) {
      success = true;
    } else {
      success = false;
    }
  } else {
    scanned2 = 0.0;
  }
  if (success) {
    s1[idx - 1] = '\x00';
    if (ntoread == 2) {
      ntoread = sscanf(&s1[0], "%lf %lf", &scanned1, &scanned2);
      if (ntoread != 2) {
        scanned1 = rtNaN;
        scanned2 = rtNaN;
      }
    } else if (ntoread == 1) {
      double b_scanned1;
      ntoread = sscanf(&s1[0], "%lf", &b_scanned1);
      if (ntoread != 1) {
        b_scanned1 = rtNaN;
      }
      if (b_finite) {
        scanned1 = b_scanned1;
      } else {
        scanned2 = b_scanned1;
      }
    }
    if (isimag1) {
      x.re = scanned2;
      x.im = scanned1;
    } else {
      x.re = scanned1;
      x.im = scanned2;
    }
  }
  return x;
}

/*
 * File trailer for str2double.c
 *
 * [EOF]
 */
