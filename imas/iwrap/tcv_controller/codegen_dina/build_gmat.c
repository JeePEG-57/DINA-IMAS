/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: build_gmat.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Apr-2026 10:42:42
 */

/* Include Files */
#include "build_gmat.h"
#include "hybctrl_step_IDS_emxutil.h"
#include "hybctrl_step_IDS_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * [G,iG,G2P,G1I,G3D] = build_gmat(Gmat,t)
 *    Build output matrix G from mdsplus Gmat matrix, extracting the components
 *    at time t and assembling them into a single matrix.
 *
 * Arguments    : const double Gmat_addr_time[10]
 *                const double Gmat_addr_data[10]
 *                const double Gmat_G1I[5720]
 *                const double Gmat_G2P[5720]
 *                const double Gmat_G3D[5720]
 *                double t
 *                emxArray_real_T *G
 *                emxArray_real_T *iG
 *                emxArray_real_T *G2P
 *                emxArray_real_T *G1I
 *                emxArray_real_T *G3D
 * Return Type  : void
 */
void build_gmat(const double Gmat_addr_time[10],
                const double Gmat_addr_data[10], const double Gmat_G1I[5720],
                const double Gmat_G2P[5720], const double Gmat_G3D[5720],
                double t, emxArray_real_T *G, emxArray_real_T *iG,
                emxArray_real_T *G2P, emxArray_real_T *G1I,
                emxArray_real_T *G3D)
{
  emxArray_int8_T *ii;
  emxArray_real_T *G2P_tmp;
  emxArray_real_T *a;
  emxArray_real_T *b_a;
  emxArray_real_T *c_a;
  double *G2P_data;
  double *G2P_tmp_data;
  double *a_data;
  double *b_a_data;
  double *iG_data;
  int b_ii;
  int i;
  int i1;
  int i2;
  int idx;
  signed char b_szb_idx_2;
  signed char szb_idx_2;
  signed char *ii_data;
  boolean_T x[10];
  boolean_T exitg1;
  for (i = 0; i < 10; i++) {
    x[i] = (Gmat_addr_time[i] <= t + 2.2204460492503131E-16);
  }
  emxInit_int8_T(&ii, 2);
  idx = 0;
  i = ii->size[0] * ii->size[1];
  ii->size[0] = 1;
  ii->size[1] = 1;
  emxEnsureCapacity_int8_T(ii, i);
  ii_data = ii->data;
  b_ii = 10;
  exitg1 = false;
  while ((!exitg1) && (b_ii > 0)) {
    if (x[b_ii - 1]) {
      idx = 1;
      ii_data[0] = (signed char)b_ii;
      exitg1 = true;
    } else {
      b_ii--;
    }
  }
  if (idx == 0) {
    ii->size[0] = 1;
    ii->size[1] = 0;
  }
  i = iG->size[0] * iG->size[1];
  iG->size[0] = 1;
  iG->size[1] = ii->size[1];
  emxEnsureCapacity_real_T(iG, i);
  iG_data = iG->data;
  b_ii = ii->size[1];
  for (i = 0; i < b_ii; i++) {
    iG_data[0] = Gmat_addr_data[ii_data[0] - 1] + 1.0;
  }
  emxInit_real_T(&G2P_tmp, 1);
  i = G2P_tmp->size[0];
  G2P_tmp->size[0] = ii->size[1];
  emxEnsureCapacity_real_T(G2P_tmp, i);
  G2P_tmp_data = G2P_tmp->data;
  b_ii = ii->size[1];
  for (i = 0; i < b_ii; i++) {
    G2P_tmp_data[0] = iG_data[0];
  }
  emxInit_real_T(&a, 3);
  i = a->size[0] * a->size[1] * a->size[2];
  a->size[0] = 22;
  a->size[1] = 26;
  a->size[2] = ii->size[1];
  emxEnsureCapacity_real_T(a, i);
  a_data = a->data;
  b_ii = ii->size[1];
  for (i = 0; i < b_ii; i++) {
    for (i1 = 0; i1 < 26; i1++) {
      for (i2 = 0; i2 < 22; i2++) {
        idx = i2 + 22 * i1;
        a_data[idx] = Gmat_G2P[idx + 572 * ((int)G2P_tmp_data[0] - 1)];
      }
    }
  }
  szb_idx_2 = 1;
  if (ii->size[1] != 1) {
    szb_idx_2 = 0;
  }
  i = G2P->size[0] * G2P->size[1] * G2P->size[2];
  G2P->size[0] = 22;
  G2P->size[1] = 26;
  G2P->size[2] = szb_idx_2;
  emxEnsureCapacity_real_T(G2P, i);
  G2P_data = G2P->data;
  b_ii = 572 * szb_idx_2;
  for (i = 0; i < b_ii; i++) {
    G2P_data[i] = a_data[i];
  }
  emxInit_real_T(&b_a, 3);
  i = b_a->size[0] * b_a->size[1] * b_a->size[2];
  b_a->size[0] = 22;
  b_a->size[1] = 26;
  b_a->size[2] = ii->size[1];
  emxEnsureCapacity_real_T(b_a, i);
  b_a_data = b_a->data;
  b_ii = ii->size[1];
  for (i = 0; i < b_ii; i++) {
    for (i1 = 0; i1 < 26; i1++) {
      for (i2 = 0; i2 < 22; i2++) {
        idx = i2 + 22 * i1;
        b_a_data[idx] = Gmat_G1I[idx + 572 * ((int)G2P_tmp_data[0] - 1)];
      }
    }
  }
  emxFree_real_T(&G2P_tmp);
  b_szb_idx_2 = 1;
  if (ii->size[1] != 1) {
    b_szb_idx_2 = 0;
  }
  i = G1I->size[0] * G1I->size[1] * G1I->size[2];
  G1I->size[0] = 22;
  G1I->size[1] = 26;
  G1I->size[2] = b_szb_idx_2;
  emxEnsureCapacity_real_T(G1I, i);
  G2P_data = G1I->data;
  b_ii = 572 * b_szb_idx_2;
  for (i = 0; i < b_ii; i++) {
    G2P_data[i] = b_a_data[i];
  }
  emxInit_real_T(&c_a, 3);
  i = c_a->size[0] * c_a->size[1] * c_a->size[2];
  c_a->size[0] = 22;
  c_a->size[1] = 26;
  c_a->size[2] = ii->size[1];
  emxEnsureCapacity_real_T(c_a, i);
  G2P_tmp_data = c_a->data;
  b_ii = ii->size[1];
  for (i = 0; i < b_ii; i++) {
    for (i1 = 0; i1 < 26; i1++) {
      for (i2 = 0; i2 < 22; i2++) {
        idx = i2 + 22 * i1;
        G2P_tmp_data[idx] = Gmat_G3D[idx + 572 * ((int)iG_data[0] - 1)];
      }
    }
  }
  b_szb_idx_2 = 1;
  if (ii->size[1] != 1) {
    b_szb_idx_2 = 0;
  }
  emxFree_int8_T(&ii);
  i = G3D->size[0] * G3D->size[1] * G3D->size[2];
  G3D->size[0] = 22;
  G3D->size[1] = 26;
  G3D->size[2] = b_szb_idx_2;
  emxEnsureCapacity_real_T(G3D, i);
  G2P_data = G3D->data;
  b_ii = 572 * b_szb_idx_2;
  for (i = 0; i < b_ii; i++) {
    G2P_data[i] = G2P_tmp_data[i];
  }
  i = G->size[0] * G->size[1] * G->size[2];
  G->size[0] = 22;
  G->size[1] = 78;
  G->size[2] = szb_idx_2;
  emxEnsureCapacity_real_T(G, i);
  G2P_data = G->data;
  b_ii = szb_idx_2;
  for (i = 0; i < b_ii; i++) {
    for (i1 = 0; i1 < 26; i1++) {
      for (i2 = 0; i2 < 22; i2++) {
        G2P_data[i2 + G->size[0] * i1] = a_data[i2 + 22 * i1];
      }
    }
  }
  emxFree_real_T(&a);
  b_ii = szb_idx_2;
  for (i = 0; i < b_ii; i++) {
    for (i1 = 0; i1 < 26; i1++) {
      for (i2 = 0; i2 < 22; i2++) {
        G2P_data[i2 + G->size[0] * (i1 + 26)] = b_a_data[i2 + 22 * i1];
      }
    }
  }
  emxFree_real_T(&b_a);
  b_ii = szb_idx_2;
  for (i = 0; i < b_ii; i++) {
    for (i1 = 0; i1 < 26; i1++) {
      for (i2 = 0; i2 < 22; i2++) {
        G2P_data[i2 + G->size[0] * (i1 + 52)] = G2P_tmp_data[i2 + 22 * i1];
      }
    }
  }
  emxFree_real_T(&c_a);
}

/*
 * File trailer for build_gmat.c
 *
 * [EOF]
 */
