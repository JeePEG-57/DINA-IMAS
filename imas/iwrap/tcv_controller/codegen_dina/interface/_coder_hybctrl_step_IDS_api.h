/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_hybctrl_step_IDS_api.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 28-Apr-2026 10:26:51
 */

#ifndef _CODER_HYBCTRL_STEP_IDS_API_H
#define _CODER_HYBCTRL_STEP_IDS_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T time;
  real_T Bm[38];
  real_T Ff[38];
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  char_T f1[5];
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T time;
  real_T Ia[29];
  cell_wrap_0 names[29];
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_cell_1
#define typedef_cell_1
typedef struct {
  char_T f1[6];
  char_T f2[7];
  char_T f3[7];
  char_T f4[7];
  char_T f5[7];
  char_T f6[7];
  char_T f7[7];
  char_T f8[7];
  char_T f9[7];
  char_T f10[7];
  char_T f11[7];
  char_T f12[7];
  char_T f13[7];
  char_T f14[7];
  char_T f15[7];
  char_T f16[7];
  char_T f17[7];
  char_T f18[7];
  char_T f19[7];
  char_T f20[7];
  char_T f21[7];
  char_T f22[7];
  char_T f23[7];
  char_T f24[7];
  char_T f25[7];
  char_T f26[7];
  char_T f27[7];
  char_T f28[7];
  char_T f29[7];
  char_T f30[7];
  char_T f31[7];
  char_T f32[7];
  char_T f33[7];
  char_T f34[7];
  char_T f35[7];
  char_T f36[7];
  char_T f37[7];
  char_T f38[7];
  char_T f39[6];
  char_T f40[6];
  char_T f41[6];
  char_T f42[6];
  char_T f43[6];
  char_T f44[6];
  char_T f45[6];
  char_T f46[6];
  char_T f47[6];
  char_T f48[6];
  char_T f49[6];
  char_T f50[6];
  char_T f51[6];
  char_T f52[6];
  char_T f53[6];
  char_T f54[6];
  char_T f55[6];
  char_T f56[6];
  char_T f57[6];
  char_T f58[6];
  char_T f59[6];
  char_T f60[6];
  char_T f61[6];
  char_T f62[6];
  char_T f63[6];
  char_T f64[6];
  char_T f65[6];
  char_T f66[6];
  char_T f67[6];
  char_T f68[6];
  char_T f69[6];
  char_T f70[6];
  char_T f71[6];
  char_T f72[6];
  char_T f73[6];
  char_T f74[6];
  char_T f75[6];
  char_T f76[6];
  char_T f77[8];
  char_T f78[8];
  char_T f79[8];
  char_T f80[8];
  char_T f81[8];
  char_T f82[8];
  char_T f83[8];
  char_T f84[8];
  char_T f85[8];
  char_T f86[8];
  char_T f87[8];
  char_T f88[8];
  char_T f89[8];
  char_T f90[8];
  char_T f91[8];
  char_T f92[8];
  char_T f93[9];
  char_T f94[9];
  char_T f95[6];
  char_T f96[6];
  char_T f97[6];
  char_T f98[6];
  char_T f99[6];
  char_T f100[6];
  char_T f101[6];
  char_T f102[6];
  char_T f103[6];
  char_T f104[6];
  char_T f105[6];
  char_T f106[6];
  char_T f107[6];
  char_T f108[6];
  char_T f109[6];
  char_T f110[6];
  char_T f111[6];
  char_T f112[6];
  char_T f113[6];
  char_T f114[6];
  char_T f115[10];
  char_T f116[8];
  char_T f117[6];
} cell_1;
#endif /* typedef_cell_1 */

#ifndef typedef_cell_2
#define typedef_cell_2
typedef struct {
  char_T f1[5];
  char_T f2[7];
  char_T f3[5];
  char_T f4[7];
  char_T f5[7];
  char_T f6[7];
  char_T f7[7];
  char_T f8[7];
  char_T f9[7];
  char_T f10[7];
  char_T f11[7];
  char_T f12[7];
  char_T f13[7];
  char_T f14[7];
  char_T f15[7];
  char_T f16[7];
  char_T f17[14];
  char_T f18[13];
  char_T f19[8];
  char_T f20[10];
  char_T f21[10];
  char_T f22[6];
  char_T f23[6];
  char_T f24[6];
  char_T f25[7];
  char_T f26[7];
} cell_2;
#endif /* typedef_cell_2 */

#ifndef typedef_cell_4
#define typedef_cell_4
typedef struct {
  char_T f1[5];
  char_T f2[5];
  char_T f3[5];
  char_T f4[5];
  char_T f5[5];
  char_T f6[5];
  char_T f7[5];
  char_T f8[5];
  char_T f9[5];
  char_T f10[5];
  char_T f11[5];
  char_T f12[5];
  char_T f13[5];
  char_T f14[5];
  char_T f15[5];
  char_T f16[5];
  char_T f17[5];
  char_T f18[5];
  char_T f19[5];
  char_T f20[5];
  char_T f21[5];
  char_T f22[5];
  char_T f23[8];
  char_T f24[8];
  char_T f25[8];
  char_T f26[8];
  char_T f27[8];
  char_T f28[8];
  char_T f29[8];
  char_T f30[8];
  char_T f31[8];
  char_T f32[8];
  char_T f33[8];
  char_T f34[8];
  char_T f35[8];
  char_T f36[8];
  char_T f37[8];
  char_T f38[8];
  char_T f39[9];
  char_T f40[9];
} cell_4;
#endif /* typedef_cell_4 */

#ifndef typedef_cell_5
#define typedef_cell_5
typedef struct {
  char_T f1[8];
  char_T f2[8];
  char_T f3[8];
  char_T f4[8];
  char_T f5[8];
  char_T f6[8];
  char_T f7[8];
  char_T f8[8];
  char_T f9[8];
  char_T f10[8];
  char_T f11[8];
  char_T f12[8];
  char_T f13[8];
  char_T f14[8];
  char_T f15[8];
  char_T f16[8];
  char_T f17[9];
  char_T f18[9];
  char_T f19[8];
} cell_5;
#endif /* typedef_cell_5 */

#ifndef typedef_struct4_T
#define typedef_struct4_T
typedef struct {
  real_T data[760];
  cell_4 dimin;
  cell_5 dimout;
  boolean_T lhyb[19];
} struct4_T;
#endif /* typedef_struct4_T */

#ifndef typedef_struct6_T
#define typedef_struct6_T
typedef struct {
  real_T time[10];
  real_T data[10];
} struct6_T;
#endif /* typedef_struct6_T */

#ifndef typedef_struct5_T
#define typedef_struct5_T
typedef struct {
  struct6_T addr;
  real_T G1I[5720];
  real_T G2P[5720];
  real_T G3D[5720];
  cell_2 dimin;
  cell_wrap_0 dimout[22];
} struct5_T;
#endif /* typedef_struct5_T */

#ifndef typedef_struct7_T
#define typedef_struct7_T
typedef struct {
  real_T a[10816];
  real_T b[2704];
  real_T c[8112];
  real_T d[2028];
} struct7_T;
#endif /* typedef_struct7_T */

#ifndef typedef_struct3_T
#define typedef_struct3_T
typedef struct {
  real_T data[3042];
  cell_1 dimin;
  cell_2 dimout;
  boolean_T lhyb[26];
} struct3_T;
#endif /* typedef_struct3_T */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  struct3_T Amat;
  struct4_T Mmat;
  struct5_T Gmat;
  boolean_T iEin[40];
  boolean_T iFin[40];
  boolean_T iOHin[40];
  boolean_T iGOin[40];
  struct7_T ssPIDd;
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef typedef_struct8_T
#define typedef_struct8_T
typedef struct {
  real_T hyb[104];
} struct8_T;
#endif /* typedef_struct8_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void hybctrl_step_IDS(real_T t, struct0_T *magn, struct1_T *pfa,
                      real_T Arefs[26], struct2_T *cpar, struct8_T *cstate,
                      real_T cout[19]);

void hybctrl_step_IDS_api(const mxArray *const prhs[6], int32_T nlhs,
                          const mxArray *plhs[2]);

void hybctrl_step_IDS_atexit(void);

void hybctrl_step_IDS_initialize(void);

void hybctrl_step_IDS_terminate(void);

void hybctrl_step_IDS_xil_shutdown(void);

void hybctrl_step_IDS_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_hybctrl_step_IDS_api.h
 *
 * [EOF]
 */
