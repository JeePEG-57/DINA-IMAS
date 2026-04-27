/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: hybctrl_step_IDS.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Apr-2026 10:42:42
 */

/* Include Files */
#include "hybctrl_step_IDS.h"
#include "IDS2Ain.h"
#include "build_gmat.h"
#include "containsNonVect.h"
#include "hybctrl_step_IDS_emxutil.h"
#include "hybctrl_step_IDS_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * [cout, cstate] = hybctrl_step_IDS(t, magn, pfa, Arefs, cpar, cstate)
 *   Hybrid controller step using IMAS IDS as input.
 *
 *   Inputs:
 *    .t:     current time
 *    .magn   simplified magnetics IDS from IMAS, 1 time slice
 *    .pfa:   simplified pf_active IDS from IMAS, 1 time slice
 *    .Arefs: references
 *    .cpar:  control parameters + signals structure
 *    .cstate: controller state struct (containing field .hyb)
 *
 *   To init the cpar and cstate structures, see hybctrl.m.
 *
 *   Outputs:
 *    .cout: control actions to be applied to the coils. These should be
 *      summed to the feedforwards and passed to the Power Supplies stepper.
 *    .cstate: cstate structure with the updated controller state
 *      (in cstate.hyb).
 *
 * Arguments    : double t
 *                const struct0_T *magn
 *                const struct1_T *pfa
 *                const double Arefs[26]
 *                const struct2_T *cpar
 *                struct8_T *cstate
 *                double cout[19]
 * Return Type  : void
 */
void hybctrl_step_IDS(double t, const struct0_T *magn, const struct1_T *pfa,
                      const double Arefs[26], const struct2_T *cpar,
                      struct8_T *cstate, double cout[19])
{
  emxArray_real_T *G;
  emxArray_real_T *G1I;
  emxArray_real_T *G2P;
  emxArray_real_T *G3D;
  emxArray_real_T *a__2;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *r2;
  emxArray_real_T *r3;
  double Ain[117];
  double b_cpar[104];
  double c_cpar[104];
  double b_y[78];
  double y[78];
  double Min[40];
  double b_magn[38];
  double Aerrs[26];
  double d;
  double *G1I_data;
  double *G2P_data;
  double *G3D_data;
  double *G_data;
  int b_input_sizes_idx_1;
  int b_result;
  int i;
  int i1;
  int i2;
  int input_sizes_idx_1;
  int result;
  int sizes_idx_1;
  boolean_T b_bv[117];
  boolean_T empty_non_axis_sizes;
  memcpy(&b_magn[0], &magn->Ff[0], 38U * sizeof(double));
  IDS2Ain(magn->Bm, b_magn, pfa->Ia, pfa->names, &cpar->Amat.dimin, Ain);
  /*  Compute errors for hybrid controller */
  for (i = 0; i < 26; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 117; i1++) {
      d += cpar->Amat.data[i + 26 * i1] * Ain[i1];
    }
    Aerrs[i] = Arefs[i] - d;
  }
  emxInit_real_T(&a__2, 2);
  emxInit_real_T(&G, 3);
  emxInit_real_T(&G2P, 3);
  emxInit_real_T(&G1I, 3);
  emxInit_real_T(&G3D, 3);
  /*  Get correct G-matrix at LY.t */
  build_gmat(cpar->Gmat.addr.time, cpar->Gmat.addr.data, cpar->Gmat.G1I,
             cpar->Gmat.G2P, cpar->Gmat.G3D, t, G, a__2, G2P, G1I, G3D);
  G3D_data = G3D->data;
  G1I_data = G1I->data;
  G2P_data = G2P->data;
  emxFree_real_T(&a__2);
  if ((G2P->size[0] != 0) || (G2P->size[1] != 0) || (G2P->size[2] != 1)) {
    result = G2P->size[0];
  } else if ((G1I->size[0] != 0) || (G1I->size[1] != 0) ||
             (G1I->size[2] != 1)) {
    result = G1I->size[0];
  } else if ((G3D->size[0] != 0) || (G3D->size[1] != 0) ||
             (G3D->size[2] != 1)) {
    result = G3D->size[0];
  } else {
    result = G2P->size[0];
    if (G1I->size[0] > G2P->size[0]) {
      result = G1I->size[0];
    }
    if (G3D->size[0] > result) {
      result = G3D->size[0];
    }
  }
  if ((G2P->size[0] != 0) || (G2P->size[1] != 0) || (G2P->size[2] != 1)) {
    b_result = G2P->size[2];
  } else if ((G1I->size[0] != 0) || (G1I->size[1] != 0) ||
             (G1I->size[2] != 1)) {
    b_result = G1I->size[2];
  } else if ((G3D->size[0] != 0) || (G3D->size[1] != 0) ||
             (G3D->size[2] != 1)) {
    b_result = G3D->size[2];
  } else {
    b_result = G2P->size[2];
    if (G1I->size[2] > G2P->size[2]) {
      b_result = G1I->size[2];
    }
    if (G3D->size[2] > b_result) {
      b_result = G3D->size[2];
    }
  }
  if (result == 0) {
    empty_non_axis_sizes = true;
    input_sizes_idx_1 = G2P->size[1];
  } else if (b_result == 0) {
    empty_non_axis_sizes = true;
    input_sizes_idx_1 = G2P->size[1];
  } else {
    empty_non_axis_sizes = false;
    if ((G2P->size[0] != 0) || (G2P->size[1] != 0) || (G2P->size[2] != 1)) {
      input_sizes_idx_1 = G2P->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }
  }
  if (empty_non_axis_sizes || (G1I->size[0] != 0) || (G1I->size[1] != 0) ||
      (G1I->size[2] != 1)) {
    b_input_sizes_idx_1 = G1I->size[1];
  } else {
    b_input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || (G3D->size[0] != 0) || (G3D->size[1] != 0) ||
      (G3D->size[2] != 1)) {
    sizes_idx_1 = G3D->size[1];
  } else {
    sizes_idx_1 = 0;
  }
  i = G->size[0] * G->size[1] * G->size[2];
  G->size[0] = result;
  G->size[1] = (input_sizes_idx_1 + b_input_sizes_idx_1) + sizes_idx_1;
  G->size[2] = b_result;
  emxEnsureCapacity_real_T(G, i);
  G_data = G->data;
  for (i = 0; i < b_result; i++) {
    for (i1 = 0; i1 < input_sizes_idx_1; i1++) {
      for (i2 = 0; i2 < result; i2++) {
        G_data[(i2 + G->size[0] * i1) + G->size[0] * G->size[1] * i] =
            G2P_data[(i2 + result * i1) + result * input_sizes_idx_1 * i];
      }
    }
  }
  emxFree_real_T(&G2P);
  for (i = 0; i < b_result; i++) {
    for (i1 = 0; i1 < b_input_sizes_idx_1; i1++) {
      for (i2 = 0; i2 < result; i2++) {
        G_data[(i2 + G->size[0] * (i1 + input_sizes_idx_1)) +
               G->size[0] * G->size[1] * i] =
            G1I_data[(i2 + result * i1) + result * b_input_sizes_idx_1 * i];
      }
    }
  }
  emxFree_real_T(&G1I);
  for (i = 0; i < b_result; i++) {
    for (i1 = 0; i1 < sizes_idx_1; i1++) {
      for (i2 = 0; i2 < result; i2++) {
        G_data[(i2 +
                G->size[0] * ((i1 + input_sizes_idx_1) + b_input_sizes_idx_1)) +
               G->size[0] * G->size[1] * i] =
            G3D_data[(i2 + result * i1) + result * sizes_idx_1 * i];
      }
    }
  }
  emxFree_real_T(&G3D);
  /*  Hybrid PID controller step */
  for (i = 0; i < 78; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 104; i1++) {
      d += cpar->ssPIDd.c[i + 78 * i1] * cstate->hyb[i1];
    }
    y[i] = d;
  }
  for (i = 0; i < 104; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 104; i1++) {
      d += cpar->ssPIDd.a[i + 104 * i1] * cstate->hyb[i1];
    }
    b_cpar[i] = d;
    d = 0.0;
    for (i1 = 0; i1 < 26; i1++) {
      d += cpar->ssPIDd.b[i + 104 * i1] * Aerrs[i1];
    }
    c_cpar[i] = d;
  }
  for (i = 0; i < 104; i++) {
    cstate->hyb[i] = b_cpar[i] + c_cpar[i];
  }
  /*  Compute input signal to M matrix block */
  memset(&Min[0], 0, 40U * sizeof(double));
  result = G->size[0];
  for (i = 0; i < 78; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 26; i1++) {
      d += cpar->ssPIDd.d[i + 78 * i1] * Aerrs[i1];
    }
    b_y[i] = y[i] + d;
  }
  emxInit_real_T(&r, 1);
  i = r->size[0];
  r->size[0] = G->size[0];
  emxEnsureCapacity_real_T(r, i);
  G3D_data = r->data;
  b_result = G->size[0];
  for (i = 0; i < b_result; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 78; i1++) {
      d += G_data[i + result * i1] * b_y[i1];
    }
    G3D_data[i] = d;
  }
  emxFree_real_T(&G);
  result = 0;
  for (b_result = 0; b_result < 40; b_result++) {
    if (cpar->iGOin[b_result]) {
      Min[b_result] = G3D_data[result];
      result++;
    }
  }
  emxFree_real_T(&r);
  /*  Get currents for resistive compensation */
  r_containsNonVect(&cpar->Amat.dimin, b_bv);
  result = 0;
  for (b_result = 0; b_result < 117; b_result++) {
    if (b_bv[b_result]) {
      result++;
    }
  }
  emxInit_real_T(&r1, 1);
  i = r1->size[0];
  r1->size[0] = result;
  emxEnsureCapacity_real_T(r1, i);
  G3D_data = r1->data;
  result = 0;
  for (b_result = 0; b_result < 117; b_result++) {
    if (b_bv[b_result]) {
      G3D_data[result] = Ain[b_result];
      result++;
    }
  }
  result = 0;
  for (b_result = 0; b_result < 40; b_result++) {
    if (cpar->iEin[b_result]) {
      Min[b_result] = G3D_data[result];
      result++;
    }
  }
  emxFree_real_T(&r1);
  s_containsNonVect(&cpar->Amat.dimin, b_bv);
  result = 0;
  for (b_result = 0; b_result < 117; b_result++) {
    if (b_bv[b_result]) {
      result++;
    }
  }
  emxInit_real_T(&r2, 1);
  i = r2->size[0];
  r2->size[0] = result;
  emxEnsureCapacity_real_T(r2, i);
  G3D_data = r2->data;
  result = 0;
  for (b_result = 0; b_result < 117; b_result++) {
    if (b_bv[b_result]) {
      G3D_data[result] = Ain[b_result];
      result++;
    }
  }
  result = 0;
  for (b_result = 0; b_result < 40; b_result++) {
    if (cpar->iFin[b_result]) {
      Min[b_result] = G3D_data[result];
      result++;
    }
  }
  emxFree_real_T(&r2);
  t_containsNonVect(&cpar->Amat.dimin, b_bv);
  result = 0;
  for (b_result = 0; b_result < 117; b_result++) {
    if (b_bv[b_result]) {
      result++;
    }
  }
  emxInit_real_T(&r3, 1);
  i = r3->size[0];
  r3->size[0] = result;
  emxEnsureCapacity_real_T(r3, i);
  G3D_data = r3->data;
  result = 0;
  for (b_result = 0; b_result < 117; b_result++) {
    if (b_bv[b_result]) {
      G3D_data[result] = Ain[b_result];
      result++;
    }
  }
  result = 0;
  for (b_result = 0; b_result < 40; b_result++) {
    if (cpar->iOHin[b_result]) {
      Min[b_result] = G3D_data[result];
      result++;
    }
  }
  emxFree_real_T(&r3);
  /*  Compute hybrid controller output */
  for (i = 0; i < 19; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 40; i1++) {
      d += cpar->Mmat.data[i + 19 * i1] * Min[i1];
    }
    cout[i] = d;
  }
  /*  ffs + PS. Not implemented for the moment... */
  /*   */
  /*     % get voltage feedforwards */
  /*      ffs = cpar.ffs.data(:,it); */
  /*       */
  /*      % get PS current references */
  /*      psrefs = zeros(numel(cpar.Mmat.lhyb),1); */
  /*      psrefs(~contains(cpar.Mmat.dimout,{'G_001','GAS'})) =
   * cpar.iarefs.data(:,it); */
  /*       */
  /*      % get references for hybrid loop */
  /*      Arefs = cpar.refs.data(:,it); */
  /*       */
  /*      % hybrid controller step */
  /*      if (LY.t >= cpar.ton) && (LY.t <= cpar.toff) */
  /*        [hybout,cstate] = hybctrl_step(L,LY,Arefs,cpar,cstate,cpar.ssPIDd);
   */
  /*      else */
  /*        hybout = zeros(numel(ffs),1); */
  /*      end */
  /*       */
  /*      % add feedforwards */
  /*      hybout = hybout+ffs; */
  /*       */
  /*      % power supplies internal controller step */
  /*      [cout,cstate.ps] =
   * hybrid_ps_step(LY.Ia,psrefs,hybout,cstate.ps,cpar.ssPSd,cpar.Mmat.lhyb); */
}

/*
 * File trailer for hybctrl_step_IDS.c
 *
 * [EOF]
 */
