/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: str2double1.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 28-Apr-2026 10:26:51
 */

#ifndef STR2DOUBLE1_H
#define STR2DOUBLE1_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
boolean_T copydigits(char s1[5], int *idx, const char s[3], int *k, int n,
                     boolean_T allowpoint);

boolean_T copyexponent(char s1[5], int *idx, const char s[3], int *k, int n);

boolean_T isUnitImag(const char s[3], int k, int n);

void readNonFinite(const char s[3], int *k, int n, boolean_T *b_finite,
                   double *fv);

void readfloat(char s1[5], int *idx, const char s[3], int *k, int n,
               boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
               double *nfv, boolean_T *foundsign, boolean_T *success);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for str2double1.h
 *
 * [EOF]
 */
