/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: IDS2Ain.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Apr-2026 10:42:42
 */

/* Include Files */
#include "IDS2Ain.h"
#include "any.h"
#include "containsNonVect.h"
#include "deblank.h"
#include "find.h"
#include "hybctrl_step_IDS_emxutil.h"
#include "hybctrl_step_IDS_types.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include <string.h>

/* Function Definitions */
/*
 * Ain = IDSAin(magn, pfa, dimm)
 *   Transform the LY structure to the A matrix input
 *  Create Ain input matrix for hybrid controller from IMAS IDSs.
 *  Inputs
 *    magn = struct with fields {time, Bm, Ff}. Data from simplify_IDS.m
 *    pfa = struct with fields {time, Ia, names}. Data from simplify_IDS.m
 *    dimm = vector of strings with name of "MDS nodes"?
 *
 *
 *  Example:
 *  pathToDB = '/NoTivoli/svantner/public/imasdb/tcv/3/66441/13';
 *  idd = imas_open(fullfile('imas:hdf5?path=',pathToDB),40);
 *  magnetics = ids_get(idd,'magnetics');
 *  pf_active = ids_get(idd,'pf_active');
 *  imas_close(idd);
 *  magn = simplify_IDS(magnetics,'magnetics');
 *  pfa = simplify_IDS(pf_active,'pf_active');
 *  [Amat, Gmat, Mmat, ssPID] = get_hybrid(66441);
 *  Ain = IDS2Ain(magn, pfa, Amat.dimin);
 *
 *  Remarks:
 *  Ain indices:
 *  1  :38  Ff
 *  39 :76  Bm
 *  77 :84  E
 *  85 :92  F
 *  93 :94  0H
 *  95 :114 Bm_dot
 *  115     OHD
 *  116     FIR or fringe (fmm) ?
 *  117     G
 *  118     FIR or fringe (fmm) ?
 *  119     Ff_dot
 *  120     TOR
 *
 * Arguments    : const double magn_Bm[38]
 *                double magn_Ff[38]
 *                const double pfa_Ia[29]
 *                const cell_wrap_0 pfa_names[29]
 *                const cell_1 *dimm
 *                double Ain[117]
 * Return Type  : void
 */
void IDS2Ain(const double magn_Bm[38], double magn_Ff[38],
             const double pfa_Ia[29], const cell_wrap_0 pfa_names[29],
             const cell_1 *dimm, double Ain[117])
{
  emxArray_char_T *tmpkk;
  emxArray_int32_T *pfa_id;
  emxArray_int32_T *r;
  emxArray_int8_T *r10;
  emxArray_int8_T *r11;
  emxArray_int8_T *r12;
  emxArray_int8_T *r13;
  emxArray_int8_T *r2;
  emxArray_int8_T *r4;
  emxArray_int8_T *r5;
  emxArray_int8_T *r6;
  emxArray_int8_T *r7;
  emxArray_int8_T *r8;
  emxArray_int8_T *r9;
  emxArray_real_T *Ia;
  double Ain_tmp;
  double *Ia_data;
  int i;
  int nz_tmp;
  int trueCount;
  int *pfa_id_data;
  int *r1;
  char b_tmpkk_data[3];
  signed char *r14;
  signed char *r3;
  char *tmpkk_data;
  boolean_T b_bv[117];
  boolean_T x[117];
  boolean_T b_pfa_id[29];
  /*  Pre-allocation */
  memset(&Ain[0], 0, 117U * sizeof(double));
  /*  Vloop */
  containsNonVect(dimm, x);
  b_containsNonVect(dimm, b_bv);
  for (i = 0; i < 38; i++) {
    magn_Ff[i] = -magn_Ff[i];
  }
  /* minus sign for COCOS (IMASdef vs TCV_data)  */
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      trueCount++;
    }
  }
  emxInit_int32_T(&r);
  i = r->size[0];
  r->size[0] = trueCount;
  emxEnsureCapacity_int32_T(r, i);
  r1 = r->data;
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      r1[trueCount] = i + 1;
      trueCount++;
    }
  }
  trueCount = r->size[0];
  for (i = 0; i < trueCount; i++) {
    Ain[r1[i] - 1] = magn_Ff[0];
  }
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (b_bv[i]) {
      trueCount++;
    }
  }
  emxInit_int8_T(&r2, 1);
  i = r2->size[0];
  r2->size[0] = trueCount;
  emxEnsureCapacity_int8_T(r2, i);
  r3 = r2->data;
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (b_bv[i]) {
      r3[trueCount] = (signed char)(i + 1);
      trueCount++;
    }
  }
  trueCount = r2->size[0];
  for (i = 0; i < trueCount; i++) {
    Ain[r3[i] - 1] = magn_Ff[i + 1] - magn_Ff[0];
  }
  emxFree_int8_T(&r2);
  /*  Non-integrated Vloop */
  c_containsNonVect(dimm, x);
  nz_tmp = x[0];
  for (trueCount = 0; trueCount < 116; trueCount++) {
    nz_tmp += x[trueCount + 1];
  }
  emxInit_char_T(&tmpkk);
  if (x[0]) {
    deblank(dimm->f1, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[1]) {
    b_deblank(dimm->f2, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[2]) {
    b_deblank(dimm->f3, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[3]) {
    b_deblank(dimm->f4, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[4]) {
    b_deblank(dimm->f5, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[5]) {
    b_deblank(dimm->f6, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[6]) {
    b_deblank(dimm->f7, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[7]) {
    b_deblank(dimm->f8, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[8]) {
    b_deblank(dimm->f9, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[9]) {
    b_deblank(dimm->f10, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[10]) {
    b_deblank(dimm->f11, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[11]) {
    b_deblank(dimm->f12, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[12]) {
    b_deblank(dimm->f13, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[13]) {
    b_deblank(dimm->f14, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[14]) {
    b_deblank(dimm->f15, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[15]) {
    b_deblank(dimm->f16, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[16]) {
    b_deblank(dimm->f17, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[17]) {
    b_deblank(dimm->f18, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[18]) {
    b_deblank(dimm->f19, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[19]) {
    b_deblank(dimm->f20, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[20]) {
    b_deblank(dimm->f21, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[21]) {
    b_deblank(dimm->f22, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[22]) {
    b_deblank(dimm->f23, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[23]) {
    b_deblank(dimm->f24, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[24]) {
    b_deblank(dimm->f25, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[25]) {
    b_deblank(dimm->f26, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[26]) {
    b_deblank(dimm->f27, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[27]) {
    b_deblank(dimm->f28, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[28]) {
    b_deblank(dimm->f29, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[29]) {
    b_deblank(dimm->f30, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[30]) {
    b_deblank(dimm->f31, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[31]) {
    b_deblank(dimm->f32, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[32]) {
    b_deblank(dimm->f33, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[33]) {
    b_deblank(dimm->f34, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[34]) {
    b_deblank(dimm->f35, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[35]) {
    b_deblank(dimm->f36, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[36]) {
    b_deblank(dimm->f37, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[37]) {
    b_deblank(dimm->f38, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[38]) {
    deblank(dimm->f39, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[39]) {
    deblank(dimm->f40, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[40]) {
    deblank(dimm->f41, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[41]) {
    deblank(dimm->f42, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[42]) {
    deblank(dimm->f43, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[43]) {
    deblank(dimm->f44, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[44]) {
    deblank(dimm->f45, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[45]) {
    deblank(dimm->f46, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[46]) {
    deblank(dimm->f47, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[47]) {
    deblank(dimm->f48, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[48]) {
    deblank(dimm->f49, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[49]) {
    deblank(dimm->f50, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[50]) {
    deblank(dimm->f51, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[51]) {
    deblank(dimm->f52, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[52]) {
    deblank(dimm->f53, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[53]) {
    deblank(dimm->f54, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[54]) {
    deblank(dimm->f55, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[55]) {
    deblank(dimm->f56, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[56]) {
    deblank(dimm->f57, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[57]) {
    deblank(dimm->f58, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[58]) {
    deblank(dimm->f59, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[59]) {
    deblank(dimm->f60, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[60]) {
    deblank(dimm->f61, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[61]) {
    deblank(dimm->f62, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[62]) {
    deblank(dimm->f63, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[63]) {
    deblank(dimm->f64, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[64]) {
    deblank(dimm->f65, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[65]) {
    deblank(dimm->f66, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[66]) {
    deblank(dimm->f67, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[67]) {
    deblank(dimm->f68, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[68]) {
    deblank(dimm->f69, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[69]) {
    deblank(dimm->f70, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[70]) {
    deblank(dimm->f71, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[71]) {
    deblank(dimm->f72, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[72]) {
    deblank(dimm->f73, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[73]) {
    deblank(dimm->f74, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[74]) {
    deblank(dimm->f75, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[75]) {
    deblank(dimm->f76, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[76]) {
    c_deblank(dimm->f77, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[77]) {
    c_deblank(dimm->f78, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[78]) {
    c_deblank(dimm->f79, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[79]) {
    c_deblank(dimm->f80, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[80]) {
    c_deblank(dimm->f81, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[81]) {
    c_deblank(dimm->f82, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[82]) {
    c_deblank(dimm->f83, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[83]) {
    c_deblank(dimm->f84, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[84]) {
    c_deblank(dimm->f85, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[85]) {
    c_deblank(dimm->f86, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[86]) {
    c_deblank(dimm->f87, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[87]) {
    c_deblank(dimm->f88, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[88]) {
    c_deblank(dimm->f89, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[89]) {
    c_deblank(dimm->f90, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[90]) {
    c_deblank(dimm->f91, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[91]) {
    c_deblank(dimm->f92, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[92]) {
    d_deblank(dimm->f93, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[93]) {
    d_deblank(dimm->f94, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[94]) {
    deblank(dimm->f95, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[95]) {
    deblank(dimm->f96, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[96]) {
    deblank(dimm->f97, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[97]) {
    deblank(dimm->f98, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[98]) {
    deblank(dimm->f99, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[99]) {
    deblank(dimm->f100, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[100]) {
    deblank(dimm->f101, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[101]) {
    deblank(dimm->f102, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[102]) {
    deblank(dimm->f103, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[103]) {
    deblank(dimm->f104, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[104]) {
    deblank(dimm->f105, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[105]) {
    deblank(dimm->f106, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[106]) {
    deblank(dimm->f107, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[107]) {
    deblank(dimm->f108, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[108]) {
    deblank(dimm->f109, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[109]) {
    deblank(dimm->f110, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[110]) {
    deblank(dimm->f111, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[111]) {
    deblank(dimm->f112, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[112]) {
    deblank(dimm->f113, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[113]) {
    deblank(dimm->f114, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[114]) {
    e_deblank(dimm->f115, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[115]) {
    c_deblank(dimm->f116, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[116]) {
    deblank(dimm->f117, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  /*  Derivative by finite difference */
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      trueCount++;
    }
  }
  emxInit_int8_T(&r4, 1);
  i = r4->size[0];
  r4->size[0] = trueCount;
  emxEnsureCapacity_int8_T(r4, i);
  r3 = r4->data;
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      r3[trueCount] = (signed char)(i + 1);
      trueCount++;
    }
  }
  for (i = 0; i < nz_tmp; i++) {
    Ain[r3[i] - 1] = 0.0;
  }
  emxFree_int8_T(&r4);
  /*  zero at first instant */
  /*  Bpol */
  d_containsNonVect(dimm, x);
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      trueCount++;
    }
  }
  emxInit_int8_T(&r5, 1);
  i = r5->size[0];
  r5->size[0] = trueCount;
  emxEnsureCapacity_int8_T(r5, i);
  r3 = r5->data;
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      r3[trueCount] = (signed char)(i + 1);
      trueCount++;
    }
  }
  trueCount = r5->size[0];
  for (i = 0; i < trueCount; i++) {
    Ain[r3[i] - 1] = magn_Bm[i];
  }
  emxFree_int8_T(&r5);
  /*  Non-integrated Bpol */
  e_containsNonVect(dimm, x);
  nz_tmp = x[0];
  for (trueCount = 0; trueCount < 116; trueCount++) {
    nz_tmp += x[trueCount + 1];
  }
  if (x[0]) {
    deblank(dimm->f1, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[1]) {
    b_deblank(dimm->f2, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[2]) {
    b_deblank(dimm->f3, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[3]) {
    b_deblank(dimm->f4, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[4]) {
    b_deblank(dimm->f5, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[5]) {
    b_deblank(dimm->f6, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[6]) {
    b_deblank(dimm->f7, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[7]) {
    b_deblank(dimm->f8, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[8]) {
    b_deblank(dimm->f9, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[9]) {
    b_deblank(dimm->f10, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[10]) {
    b_deblank(dimm->f11, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[11]) {
    b_deblank(dimm->f12, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[12]) {
    b_deblank(dimm->f13, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[13]) {
    b_deblank(dimm->f14, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[14]) {
    b_deblank(dimm->f15, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[15]) {
    b_deblank(dimm->f16, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[16]) {
    b_deblank(dimm->f17, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[17]) {
    b_deblank(dimm->f18, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[18]) {
    b_deblank(dimm->f19, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[19]) {
    b_deblank(dimm->f20, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[20]) {
    b_deblank(dimm->f21, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[21]) {
    b_deblank(dimm->f22, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[22]) {
    b_deblank(dimm->f23, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[23]) {
    b_deblank(dimm->f24, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[24]) {
    b_deblank(dimm->f25, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[25]) {
    b_deblank(dimm->f26, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[26]) {
    b_deblank(dimm->f27, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[27]) {
    b_deblank(dimm->f28, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[28]) {
    b_deblank(dimm->f29, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[29]) {
    b_deblank(dimm->f30, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[30]) {
    b_deblank(dimm->f31, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[31]) {
    b_deblank(dimm->f32, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[32]) {
    b_deblank(dimm->f33, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[33]) {
    b_deblank(dimm->f34, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[34]) {
    b_deblank(dimm->f35, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[35]) {
    b_deblank(dimm->f36, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[36]) {
    b_deblank(dimm->f37, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[37]) {
    b_deblank(dimm->f38, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[38]) {
    deblank(dimm->f39, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[39]) {
    deblank(dimm->f40, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[40]) {
    deblank(dimm->f41, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[41]) {
    deblank(dimm->f42, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[42]) {
    deblank(dimm->f43, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[43]) {
    deblank(dimm->f44, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[44]) {
    deblank(dimm->f45, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[45]) {
    deblank(dimm->f46, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[46]) {
    deblank(dimm->f47, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[47]) {
    deblank(dimm->f48, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[48]) {
    deblank(dimm->f49, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[49]) {
    deblank(dimm->f50, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[50]) {
    deblank(dimm->f51, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[51]) {
    deblank(dimm->f52, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[52]) {
    deblank(dimm->f53, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[53]) {
    deblank(dimm->f54, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[54]) {
    deblank(dimm->f55, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[55]) {
    deblank(dimm->f56, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[56]) {
    deblank(dimm->f57, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[57]) {
    deblank(dimm->f58, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[58]) {
    deblank(dimm->f59, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[59]) {
    deblank(dimm->f60, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[60]) {
    deblank(dimm->f61, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[61]) {
    deblank(dimm->f62, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[62]) {
    deblank(dimm->f63, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[63]) {
    deblank(dimm->f64, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[64]) {
    deblank(dimm->f65, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[65]) {
    deblank(dimm->f66, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[66]) {
    deblank(dimm->f67, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[67]) {
    deblank(dimm->f68, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[68]) {
    deblank(dimm->f69, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[69]) {
    deblank(dimm->f70, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[70]) {
    deblank(dimm->f71, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[71]) {
    deblank(dimm->f72, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[72]) {
    deblank(dimm->f73, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[73]) {
    deblank(dimm->f74, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[74]) {
    deblank(dimm->f75, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[75]) {
    deblank(dimm->f76, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[76]) {
    c_deblank(dimm->f77, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[77]) {
    c_deblank(dimm->f78, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[78]) {
    c_deblank(dimm->f79, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[79]) {
    c_deblank(dimm->f80, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[80]) {
    c_deblank(dimm->f81, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[81]) {
    c_deblank(dimm->f82, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[82]) {
    c_deblank(dimm->f83, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[83]) {
    c_deblank(dimm->f84, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[84]) {
    c_deblank(dimm->f85, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[85]) {
    c_deblank(dimm->f86, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[86]) {
    c_deblank(dimm->f87, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[87]) {
    c_deblank(dimm->f88, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[88]) {
    c_deblank(dimm->f89, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[89]) {
    c_deblank(dimm->f90, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[90]) {
    c_deblank(dimm->f91, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[91]) {
    c_deblank(dimm->f92, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[92]) {
    d_deblank(dimm->f93, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[93]) {
    d_deblank(dimm->f94, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[94]) {
    deblank(dimm->f95, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[95]) {
    deblank(dimm->f96, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[96]) {
    deblank(dimm->f97, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[97]) {
    deblank(dimm->f98, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[98]) {
    deblank(dimm->f99, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[99]) {
    deblank(dimm->f100, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[100]) {
    deblank(dimm->f101, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[101]) {
    deblank(dimm->f102, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[102]) {
    deblank(dimm->f103, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[103]) {
    deblank(dimm->f104, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[104]) {
    deblank(dimm->f105, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[105]) {
    deblank(dimm->f106, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[106]) {
    deblank(dimm->f107, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[107]) {
    deblank(dimm->f108, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[108]) {
    deblank(dimm->f109, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[109]) {
    deblank(dimm->f110, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[110]) {
    deblank(dimm->f111, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[111]) {
    deblank(dimm->f112, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[112]) {
    deblank(dimm->f113, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[113]) {
    deblank(dimm->f114, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[114]) {
    e_deblank(dimm->f115, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[115]) {
    c_deblank(dimm->f116, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  if (x[116]) {
    deblank(dimm->f117, tmpkk);
    tmpkk_data = tmpkk->data;
    b_tmpkk_data[0] = tmpkk_data[tmpkk->size[1] - 3];
    b_tmpkk_data[1] = tmpkk_data[tmpkk->size[1] - 2];
    b_tmpkk_data[2] = tmpkk_data[tmpkk->size[1] - 1];
    str2double(b_tmpkk_data);
  }
  emxFree_char_T(&tmpkk);
  /*  Derivative by finite difference */
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      trueCount++;
    }
  }
  emxInit_int8_T(&r6, 1);
  i = r6->size[0];
  r6->size[0] = trueCount;
  emxEnsureCapacity_int8_T(r6, i);
  r3 = r6->data;
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      r3[trueCount] = (signed char)(i + 1);
      trueCount++;
    }
  }
  for (i = 0; i < nz_tmp; i++) {
    Ain[r3[i] - 1] = 0.0;
  }
  emxFree_int8_T(&r6);
  emxInit_int32_T(&pfa_id);
  /*  zero at first instant */
  /*  E coils */
  f_containsNonVect(dimm, x);
  g_containsNonVect(pfa_names, b_pfa_id);
  eml_find(b_pfa_id, r);
  r1 = r->data;
  i = pfa_id->size[0];
  pfa_id->size[0] = r->size[0];
  emxEnsureCapacity_int32_T(pfa_id, i);
  pfa_id_data = pfa_id->data;
  trueCount = r->size[0];
  for (i = 0; i < trueCount; i++) {
    pfa_id_data[i] = r1[i];
  }
  emxInit_real_T(&Ia, 1);
  i = Ia->size[0];
  Ia->size[0] = pfa_id->size[0];
  emxEnsureCapacity_real_T(Ia, i);
  Ia_data = Ia->data;
  trueCount = pfa_id->size[0];
  for (i = 0; i < trueCount; i++) {
    Ia_data[i] = 0.0;
  }
  i = pfa_id->size[0];
  for (trueCount = 0; trueCount < i; trueCount++) {
    Ia_data[trueCount] = pfa_Ia[pfa_id_data[trueCount] - 1];
  }
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      trueCount++;
    }
  }
  emxInit_int8_T(&r7, 1);
  i = r7->size[0];
  r7->size[0] = trueCount;
  emxEnsureCapacity_int8_T(r7, i);
  r3 = r7->data;
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      r3[trueCount] = (signed char)(i + 1);
      trueCount++;
    }
  }
  trueCount = Ia->size[0];
  for (i = 0; i < trueCount; i++) {
    Ain[r3[i] - 1] = Ia_data[i];
  }
  emxFree_int8_T(&r7);
  /*  F coils */
  h_containsNonVect(dimm, x);
  i_containsNonVect(pfa_names, b_pfa_id);
  eml_find(b_pfa_id, r);
  r1 = r->data;
  i = pfa_id->size[0];
  pfa_id->size[0] = r->size[0];
  emxEnsureCapacity_int32_T(pfa_id, i);
  pfa_id_data = pfa_id->data;
  trueCount = r->size[0];
  for (i = 0; i < trueCount; i++) {
    pfa_id_data[i] = r1[i];
  }
  i = Ia->size[0];
  Ia->size[0] = pfa_id->size[0];
  emxEnsureCapacity_real_T(Ia, i);
  Ia_data = Ia->data;
  trueCount = pfa_id->size[0];
  for (i = 0; i < trueCount; i++) {
    Ia_data[i] = 0.0;
  }
  i = pfa_id->size[0];
  for (trueCount = 0; trueCount < i; trueCount++) {
    Ia_data[trueCount] = pfa_Ia[pfa_id_data[trueCount] - 1];
  }
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      trueCount++;
    }
  }
  emxInit_int8_T(&r8, 1);
  i = r8->size[0];
  r8->size[0] = trueCount;
  emxEnsureCapacity_int8_T(r8, i);
  r3 = r8->data;
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      r3[trueCount] = (signed char)(i + 1);
      trueCount++;
    }
  }
  trueCount = Ia->size[0];
  for (i = 0; i < trueCount; i++) {
    Ain[r3[i] - 1] = Ia_data[i];
  }
  emxFree_int8_T(&r8);
  /*  G coils */
  j_containsNonVect(dimm, x);
  k_containsNonVect(pfa_names, b_pfa_id);
  eml_find(b_pfa_id, r);
  r1 = r->data;
  i = pfa_id->size[0];
  pfa_id->size[0] = r->size[0];
  emxEnsureCapacity_int32_T(pfa_id, i);
  pfa_id_data = pfa_id->data;
  trueCount = r->size[0];
  for (i = 0; i < trueCount; i++) {
    pfa_id_data[i] = r1[i];
  }
  /* G coils in series, so first current enough */
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      trueCount++;
    }
  }
  emxInit_int8_T(&r9, 1);
  i = r9->size[0];
  r9->size[0] = trueCount;
  emxEnsureCapacity_int8_T(r9, i);
  r3 = r9->data;
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      r3[trueCount] = (signed char)(i + 1);
      trueCount++;
    }
  }
  trueCount = r9->size[0];
  for (i = 0; i < trueCount; i++) {
    Ain[r3[i] - 1] = pfa_Ia[pfa_id_data[0] - 1];
  }
  emxFree_int8_T(&r9);
  /*  OH coils */
  l_containsNonVect(dimm, x);
  m_containsNonVect(pfa_names, b_pfa_id);
  eml_find(b_pfa_id, r);
  r1 = r->data;
  i = pfa_id->size[0];
  pfa_id->size[0] = r->size[0];
  emxEnsureCapacity_int32_T(pfa_id, i);
  pfa_id_data = pfa_id->data;
  trueCount = r->size[0];
  for (i = 0; i < trueCount; i++) {
    pfa_id_data[i] = r1[i];
  }
  n_containsNonVect(pfa_names, b_pfa_id);
  eml_find(b_pfa_id, r);
  r1 = r->data;
  i = Ia->size[0];
  Ia->size[0] = r->size[0];
  emxEnsureCapacity_real_T(Ia, i);
  Ia_data = Ia->data;
  trueCount = r->size[0];
  for (i = 0; i < trueCount; i++) {
    Ia_data[i] = r1[i];
  }
  emxFree_int32_T(&r);
  /* B,C,D coils in series. */
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      trueCount++;
    }
  }
  emxInit_int8_T(&r10, 1);
  i = r10->size[0];
  r10->size[0] = trueCount;
  emxEnsureCapacity_int8_T(r10, i);
  r3 = r10->data;
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      r3[trueCount] = (signed char)(i + 1);
      trueCount++;
    }
  }
  trueCount = pfa_id->size[0];
  for (i = 0; i < trueCount; i++) {
    Ain[r3[i] - 1] = pfa_Ia[pfa_id_data[i] - 1];
  }
  Ain_tmp = pfa_Ia[(int)Ia_data[0] - 1];
  Ain[r3[pfa_id->size[0]] - 1] = Ain_tmp;
  o_containsNonVect(dimm, x);
  trueCount = 0;
  emxFree_int8_T(&r10);
  emxFree_real_T(&Ia);
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      trueCount++;
    }
  }
  emxInit_int8_T(&r11, 1);
  i = r11->size[0];
  r11->size[0] = trueCount;
  emxEnsureCapacity_int8_T(r11, i);
  r3 = r11->data;
  trueCount = 0;
  for (i = 0; i < 117; i++) {
    if (x[i]) {
      r3[trueCount] = (signed char)(i + 1);
      trueCount++;
    }
  }
  trueCount = pfa_id->size[0];
  for (i = 0; i < trueCount; i++) {
    Ain[r3[i] - 1] = pfa_Ia[pfa_id_data[i] - 1] - Ain_tmp;
  }
  emxFree_int8_T(&r11);
  emxFree_int32_T(&pfa_id);
  /*  TOR coils */
  p_containsNonVect(dimm, x);
  q_containsNonVect(pfa_names, b_pfa_id);
  if (any(b_pfa_id)) {
    trueCount = 0;
    for (i = 0; i < 117; i++) {
      if (x[i]) {
        trueCount++;
      }
    }
    emxInit_int8_T(&r12, 1);
    i = r12->size[0];
    r12->size[0] = trueCount;
    emxEnsureCapacity_int8_T(r12, i);
    r3 = r12->data;
    trueCount = 0;
    for (i = 0; i < 117; i++) {
      if (x[i]) {
        r3[trueCount] = (signed char)(i + 1);
        trueCount++;
      }
    }
    trueCount = 0;
    for (i = 0; i < 29; i++) {
      if (b_pfa_id[i]) {
        trueCount++;
      }
    }
    emxInit_int8_T(&r13, 1);
    i = r13->size[0];
    r13->size[0] = trueCount;
    emxEnsureCapacity_int8_T(r13, i);
    r14 = r13->data;
    trueCount = 0;
    for (i = 0; i < 29; i++) {
      if (b_pfa_id[i]) {
        r14[trueCount] = (signed char)(i + 1);
        trueCount++;
      }
    }
    trueCount = r13->size[0];
    for (i = 0; i < trueCount; i++) {
      Ain[r3[i] - 1] = pfa_Ia[r14[i] - 1];
    }
    emxFree_int8_T(&r13);
    emxFree_int8_T(&r12);
  }
}

/*
 * File trailer for IDS2Ain.c
 *
 * [EOF]
 */
