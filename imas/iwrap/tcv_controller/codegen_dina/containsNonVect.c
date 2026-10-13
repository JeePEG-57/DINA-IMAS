/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: containsNonVect.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 28-Apr-2026 10:26:51
 */

/* Include Files */
#include "containsNonVect.h"
#include "contains.h"
#include "hybctrl_step_IDS_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void b_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (f_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (g_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (g_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (g_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (g_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (g_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (g_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (g_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (g_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (g_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (g_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (g_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (g_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (g_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (g_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (g_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (g_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (g_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (g_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (g_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (g_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (g_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (g_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (g_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (g_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (g_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (g_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (g_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (g_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (g_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (g_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (g_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (g_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (g_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (g_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (g_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (g_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (g_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (f_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (f_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (f_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (f_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (f_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (f_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (f_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (f_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (f_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (f_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (f_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (f_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (f_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (f_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (f_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (f_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (f_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (f_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (f_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (f_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (f_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (f_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (f_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (f_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (f_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (f_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (f_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (f_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (f_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (f_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (f_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (f_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (f_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (f_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (f_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (f_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (f_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (f_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (h_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (h_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (h_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (h_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (h_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (h_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (h_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (h_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (h_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (h_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (h_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (h_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (h_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (h_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (h_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (h_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (i_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (i_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (f_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (f_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (f_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (f_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (f_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (f_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (f_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (f_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (f_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (f_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (f_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (f_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (f_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (f_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (f_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (f_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (f_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (f_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (f_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (f_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (j_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (h_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (f_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void c_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (k_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (l_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (l_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (l_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (l_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (l_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (l_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (l_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (l_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (l_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (l_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (l_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (l_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (l_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (l_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (l_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (l_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (l_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (l_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (l_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (l_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (l_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (l_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (l_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (l_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (l_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (l_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (l_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (l_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (l_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (l_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (l_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (l_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (l_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (l_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (l_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (l_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (l_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (k_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (k_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (k_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (k_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (k_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (k_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (k_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (k_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (k_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (k_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (k_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (k_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (k_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (k_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (k_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (k_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (k_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (k_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (k_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (k_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (k_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (k_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (k_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (k_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (k_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (k_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (k_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (k_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (k_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (k_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (k_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (k_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (k_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (k_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (k_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (k_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (k_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (k_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (m_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (m_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (m_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (m_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (m_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (m_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (m_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (m_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (m_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (m_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (m_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (m_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (m_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (m_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (m_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (m_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (n_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (n_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (k_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (k_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (k_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (k_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (k_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (k_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (k_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (k_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (k_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (k_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (k_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (k_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (k_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (k_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (k_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (k_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (k_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (k_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (k_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (k_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (o_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (m_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (k_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (contains(dimm->f1)) {
    mask[0] = true;
  }
  if (b_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (b_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (b_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (b_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (b_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (b_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (b_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (b_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (b_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (b_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (b_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (b_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (b_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (b_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (b_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (b_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (b_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (b_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (b_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (b_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (b_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (b_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (b_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (b_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (b_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (b_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (b_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (b_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (b_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (b_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (b_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (b_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (b_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (b_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (b_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (b_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (b_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (contains(dimm->f39)) {
    mask[38] = true;
  }
  if (contains(dimm->f40)) {
    mask[39] = true;
  }
  if (contains(dimm->f41)) {
    mask[40] = true;
  }
  if (contains(dimm->f42)) {
    mask[41] = true;
  }
  if (contains(dimm->f43)) {
    mask[42] = true;
  }
  if (contains(dimm->f44)) {
    mask[43] = true;
  }
  if (contains(dimm->f45)) {
    mask[44] = true;
  }
  if (contains(dimm->f46)) {
    mask[45] = true;
  }
  if (contains(dimm->f47)) {
    mask[46] = true;
  }
  if (contains(dimm->f48)) {
    mask[47] = true;
  }
  if (contains(dimm->f49)) {
    mask[48] = true;
  }
  if (contains(dimm->f50)) {
    mask[49] = true;
  }
  if (contains(dimm->f51)) {
    mask[50] = true;
  }
  if (contains(dimm->f52)) {
    mask[51] = true;
  }
  if (contains(dimm->f53)) {
    mask[52] = true;
  }
  if (contains(dimm->f54)) {
    mask[53] = true;
  }
  if (contains(dimm->f55)) {
    mask[54] = true;
  }
  if (contains(dimm->f56)) {
    mask[55] = true;
  }
  if (contains(dimm->f57)) {
    mask[56] = true;
  }
  if (contains(dimm->f58)) {
    mask[57] = true;
  }
  if (contains(dimm->f59)) {
    mask[58] = true;
  }
  if (contains(dimm->f60)) {
    mask[59] = true;
  }
  if (contains(dimm->f61)) {
    mask[60] = true;
  }
  if (contains(dimm->f62)) {
    mask[61] = true;
  }
  if (contains(dimm->f63)) {
    mask[62] = true;
  }
  if (contains(dimm->f64)) {
    mask[63] = true;
  }
  if (contains(dimm->f65)) {
    mask[64] = true;
  }
  if (contains(dimm->f66)) {
    mask[65] = true;
  }
  if (contains(dimm->f67)) {
    mask[66] = true;
  }
  if (contains(dimm->f68)) {
    mask[67] = true;
  }
  if (contains(dimm->f69)) {
    mask[68] = true;
  }
  if (contains(dimm->f70)) {
    mask[69] = true;
  }
  if (contains(dimm->f71)) {
    mask[70] = true;
  }
  if (contains(dimm->f72)) {
    mask[71] = true;
  }
  if (contains(dimm->f73)) {
    mask[72] = true;
  }
  if (contains(dimm->f74)) {
    mask[73] = true;
  }
  if (contains(dimm->f75)) {
    mask[74] = true;
  }
  if (contains(dimm->f76)) {
    mask[75] = true;
  }
  if (c_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (c_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (c_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (c_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (c_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (c_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (c_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (c_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (c_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (c_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (c_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (c_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (c_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (c_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (c_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (c_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (d_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (d_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (contains(dimm->f95)) {
    mask[94] = true;
  }
  if (contains(dimm->f96)) {
    mask[95] = true;
  }
  if (contains(dimm->f97)) {
    mask[96] = true;
  }
  if (contains(dimm->f98)) {
    mask[97] = true;
  }
  if (contains(dimm->f99)) {
    mask[98] = true;
  }
  if (contains(dimm->f100)) {
    mask[99] = true;
  }
  if (contains(dimm->f101)) {
    mask[100] = true;
  }
  if (contains(dimm->f102)) {
    mask[101] = true;
  }
  if (contains(dimm->f103)) {
    mask[102] = true;
  }
  if (contains(dimm->f104)) {
    mask[103] = true;
  }
  if (contains(dimm->f105)) {
    mask[104] = true;
  }
  if (contains(dimm->f106)) {
    mask[105] = true;
  }
  if (contains(dimm->f107)) {
    mask[106] = true;
  }
  if (contains(dimm->f108)) {
    mask[107] = true;
  }
  if (contains(dimm->f109)) {
    mask[108] = true;
  }
  if (contains(dimm->f110)) {
    mask[109] = true;
  }
  if (contains(dimm->f111)) {
    mask[110] = true;
  }
  if (contains(dimm->f112)) {
    mask[111] = true;
  }
  if (contains(dimm->f113)) {
    mask[112] = true;
  }
  if (contains(dimm->f114)) {
    mask[113] = true;
  }
  if (e_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (c_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void d_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (p_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (q_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (q_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (q_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (q_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (q_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (q_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (q_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (q_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (q_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (q_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (q_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (q_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (q_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (q_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (q_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (q_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (q_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (q_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (q_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (q_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (q_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (q_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (q_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (q_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (q_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (q_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (q_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (q_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (q_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (q_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (q_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (q_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (q_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (q_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (q_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (q_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (q_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (p_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (p_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (p_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (p_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (p_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (p_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (p_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (p_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (p_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (p_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (p_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (p_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (p_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (p_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (p_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (p_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (p_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (p_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (p_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (p_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (p_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (p_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (p_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (p_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (p_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (p_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (p_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (p_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (p_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (p_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (p_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (p_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (p_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (p_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (p_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (p_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (p_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (p_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (r_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (r_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (r_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (r_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (r_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (r_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (r_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (r_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (r_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (r_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (r_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (r_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (r_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (r_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (r_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (r_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (s_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (s_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (p_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (p_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (p_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (p_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (p_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (p_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (p_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (p_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (p_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (p_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (p_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (p_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (p_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (p_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (p_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (p_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (p_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (p_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (p_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (p_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (t_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (r_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (p_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void e_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (u_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (v_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (v_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (v_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (v_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (v_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (v_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (v_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (v_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (v_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (v_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (v_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (v_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (v_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (v_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (v_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (v_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (v_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (v_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (v_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (v_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (v_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (v_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (v_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (v_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (v_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (v_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (v_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (v_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (v_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (v_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (v_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (v_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (v_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (v_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (v_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (v_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (v_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (u_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (u_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (u_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (u_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (u_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (u_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (u_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (u_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (u_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (u_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (u_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (u_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (u_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (u_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (u_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (u_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (u_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (u_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (u_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (u_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (u_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (u_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (u_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (u_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (u_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (u_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (u_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (u_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (u_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (u_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (u_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (u_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (u_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (u_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (u_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (u_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (u_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (u_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (w_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (w_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (w_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (w_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (w_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (w_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (w_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (w_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (w_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (w_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (w_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (w_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (w_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (w_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (w_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (w_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (x_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (x_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (u_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (u_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (u_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (u_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (u_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (u_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (u_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (u_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (u_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (u_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (u_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (u_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (u_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (u_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (u_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (u_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (u_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (u_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (u_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (u_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (y_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (w_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (u_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void f_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (ab_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (bb_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (bb_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (bb_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (bb_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (bb_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (bb_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (bb_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (bb_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (bb_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (bb_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (bb_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (bb_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (bb_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (bb_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (bb_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (bb_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (bb_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (bb_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (bb_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (bb_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (bb_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (bb_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (bb_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (bb_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (bb_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (bb_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (bb_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (bb_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (bb_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (bb_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (bb_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (bb_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (bb_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (bb_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (bb_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (bb_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (bb_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (ab_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (ab_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (ab_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (ab_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (ab_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (ab_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (ab_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (ab_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (ab_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (ab_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (ab_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (ab_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (ab_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (ab_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (ab_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (ab_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (ab_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (ab_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (ab_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (ab_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (ab_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (ab_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (ab_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (ab_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (ab_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (ab_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (ab_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (ab_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (ab_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (ab_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (ab_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (ab_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (ab_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (ab_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (ab_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (ab_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (ab_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (ab_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (cb_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (cb_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (cb_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (cb_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (cb_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (cb_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (cb_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (cb_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (cb_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (cb_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (cb_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (cb_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (cb_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (cb_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (cb_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (cb_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (db_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (db_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (ab_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (ab_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (ab_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (ab_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (ab_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (ab_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (ab_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (ab_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (ab_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (ab_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (ab_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (ab_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (ab_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (ab_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (ab_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (ab_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (ab_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (ab_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (ab_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (ab_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (eb_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (cb_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (ab_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_wrap_0 dimm[29]
 *                boolean_T mask[29]
 * Return Type  : void
 */
void g_containsNonVect(const cell_wrap_0 dimm[29], boolean_T mask[29])
{
  static const char cv[2] = {'E', '_'};
  int i;
  for (i = 0; i < 29; i++) {
    int b_i;
    boolean_T exitg1;
    mask[i] = false;
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i < 4)) {
      int j;
      j = 1;
      while ((j <= 2) && (dimm[i].f1[(b_i + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        mask[i] = true;
        exitg1 = true;
      } else {
        b_i++;
      }
    }
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void h_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (fb_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (gb_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (gb_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (gb_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (gb_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (gb_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (gb_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (gb_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (gb_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (gb_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (gb_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (gb_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (gb_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (gb_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (gb_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (gb_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (gb_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (gb_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (gb_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (gb_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (gb_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (gb_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (gb_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (gb_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (gb_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (gb_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (gb_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (gb_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (gb_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (gb_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (gb_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (gb_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (gb_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (gb_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (gb_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (gb_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (gb_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (gb_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (fb_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (fb_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (fb_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (fb_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (fb_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (fb_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (fb_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (fb_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (fb_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (fb_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (fb_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (fb_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (fb_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (fb_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (fb_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (fb_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (fb_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (fb_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (fb_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (fb_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (fb_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (fb_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (fb_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (fb_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (fb_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (fb_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (fb_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (fb_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (fb_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (fb_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (fb_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (fb_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (fb_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (fb_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (fb_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (fb_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (fb_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (fb_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (hb_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (hb_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (hb_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (hb_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (hb_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (hb_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (hb_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (hb_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (hb_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (hb_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (hb_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (hb_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (hb_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (hb_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (hb_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (hb_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (ib_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (ib_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (fb_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (fb_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (fb_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (fb_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (fb_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (fb_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (fb_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (fb_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (fb_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (fb_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (fb_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (fb_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (fb_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (fb_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (fb_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (fb_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (fb_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (fb_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (fb_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (fb_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (jb_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (hb_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (fb_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_wrap_0 dimm[29]
 *                boolean_T mask[29]
 * Return Type  : void
 */
void i_containsNonVect(const cell_wrap_0 dimm[29], boolean_T mask[29])
{
  static const char cv[2] = {'F', '_'};
  int i;
  for (i = 0; i < 29; i++) {
    int b_i;
    boolean_T exitg1;
    mask[i] = false;
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i < 4)) {
      int j;
      j = 1;
      while ((j <= 2) && (dimm[i].f1[(b_i + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        mask[i] = true;
        exitg1 = true;
      } else {
        b_i++;
      }
    }
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void j_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (kb_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (lb_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (lb_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (lb_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (lb_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (lb_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (lb_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (lb_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (lb_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (lb_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (lb_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (lb_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (lb_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (lb_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (lb_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (lb_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (lb_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (lb_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (lb_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (lb_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (lb_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (lb_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (lb_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (lb_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (lb_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (lb_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (lb_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (lb_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (lb_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (lb_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (lb_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (lb_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (lb_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (lb_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (lb_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (lb_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (lb_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (lb_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (kb_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (kb_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (kb_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (kb_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (kb_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (kb_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (kb_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (kb_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (kb_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (kb_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (kb_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (kb_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (kb_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (kb_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (kb_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (kb_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (kb_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (kb_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (kb_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (kb_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (kb_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (kb_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (kb_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (kb_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (kb_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (kb_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (kb_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (kb_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (kb_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (kb_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (kb_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (kb_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (kb_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (kb_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (kb_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (kb_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (kb_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (kb_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (mb_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (mb_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (mb_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (mb_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (mb_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (mb_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (mb_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (mb_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (mb_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (mb_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (mb_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (mb_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (mb_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (mb_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (mb_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (mb_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (nb_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (nb_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (kb_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (kb_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (kb_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (kb_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (kb_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (kb_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (kb_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (kb_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (kb_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (kb_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (kb_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (kb_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (kb_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (kb_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (kb_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (kb_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (kb_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (kb_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (kb_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (kb_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (ob_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (mb_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (kb_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_wrap_0 dimm[29]
 *                boolean_T mask[29]
 * Return Type  : void
 */
void k_containsNonVect(const cell_wrap_0 dimm[29], boolean_T mask[29])
{
  static const char cv[2] = {'G', '_'};
  int i;
  for (i = 0; i < 29; i++) {
    int b_i;
    boolean_T exitg1;
    mask[i] = false;
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i < 4)) {
      int j;
      j = 1;
      while ((j <= 2) && (dimm[i].f1[(b_i + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        mask[i] = true;
        exitg1 = true;
      } else {
        b_i++;
      }
    }
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void l_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (pb_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (qb_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (qb_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (qb_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (qb_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (qb_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (qb_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (qb_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (qb_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (qb_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (qb_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (qb_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (qb_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (qb_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (qb_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (qb_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (qb_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (qb_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (qb_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (qb_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (qb_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (qb_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (qb_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (qb_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (qb_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (qb_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (qb_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (qb_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (qb_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (qb_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (qb_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (qb_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (qb_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (qb_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (qb_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (qb_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (qb_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (qb_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (pb_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (pb_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (pb_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (pb_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (pb_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (pb_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (pb_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (pb_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (pb_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (pb_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (pb_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (pb_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (pb_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (pb_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (pb_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (pb_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (pb_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (pb_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (pb_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (pb_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (pb_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (pb_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (pb_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (pb_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (pb_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (pb_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (pb_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (pb_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (pb_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (pb_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (pb_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (pb_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (pb_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (pb_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (pb_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (pb_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (pb_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (pb_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (rb_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (rb_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (rb_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (rb_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (rb_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (rb_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (rb_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (rb_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (rb_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (rb_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (rb_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (rb_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (rb_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (rb_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (rb_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (rb_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (sb_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (sb_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (pb_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (pb_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (pb_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (pb_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (pb_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (pb_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (pb_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (pb_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (pb_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (pb_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (pb_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (pb_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (pb_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (pb_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (pb_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (pb_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (pb_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (pb_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (pb_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (pb_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (tb_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (rb_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (pb_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_wrap_0 dimm[29]
 *                boolean_T mask[29]
 * Return Type  : void
 */
void m_containsNonVect(const cell_wrap_0 dimm[29], boolean_T mask[29])
{
  static const char cv[2] = {'A', '_'};
  int i;
  for (i = 0; i < 29; i++) {
    int b_i;
    boolean_T exitg1;
    mask[i] = false;
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i < 4)) {
      int j;
      j = 1;
      while ((j <= 2) && (dimm[i].f1[(b_i + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        mask[i] = true;
        exitg1 = true;
      } else {
        b_i++;
      }
    }
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_wrap_0 dimm[29]
 *                boolean_T mask[29]
 * Return Type  : void
 */
void n_containsNonVect(const cell_wrap_0 dimm[29], boolean_T mask[29])
{
  static const char cv[2] = {'B', '_'};
  int i;
  for (i = 0; i < 29; i++) {
    int b_i;
    boolean_T exitg1;
    mask[i] = false;
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i < 4)) {
      int j;
      j = 1;
      while ((j <= 2) && (dimm[i].f1[(b_i + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        mask[i] = true;
        exitg1 = true;
      } else {
        b_i++;
      }
    }
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void o_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  static const char cv[7] = {'I', 'a', '_', 'D', 'O', 'H', '_'};
  int i;
  boolean_T exitg1;
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (ub_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (ub_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (ub_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (ub_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (ub_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (ub_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (ub_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (ub_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (ub_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (ub_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (ub_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (ub_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (ub_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (ub_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (ub_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (ub_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (ub_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (ub_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (ub_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (ub_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (ub_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (ub_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (ub_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (ub_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (ub_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (ub_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (ub_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (ub_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (ub_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (ub_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (ub_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (ub_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (ub_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (ub_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (ub_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (ub_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (ub_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (vb_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (vb_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (vb_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (vb_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (vb_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (vb_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (vb_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (vb_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (vb_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (vb_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (vb_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (vb_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (vb_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (vb_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (vb_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (vb_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (wb_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (wb_contains(dimm->f94)) {
    mask[93] = true;
  }
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 4)) {
    int j;
    j = 1;
    while ((j <= 7) && (dimm->f115[(i + j) - 1] == cv[j - 1])) {
      j++;
    }
    if (j > 7) {
      mask[114] = true;
      exitg1 = true;
    } else {
      i++;
    }
  }
  if (vb_contains(dimm->f116)) {
    mask[115] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void p_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (xb_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (yb_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (yb_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (yb_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (yb_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (yb_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (yb_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (yb_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (yb_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (yb_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (yb_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (yb_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (yb_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (yb_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (yb_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (yb_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (yb_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (yb_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (yb_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (yb_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (yb_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (yb_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (yb_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (yb_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (yb_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (yb_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (yb_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (yb_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (yb_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (yb_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (yb_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (yb_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (yb_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (yb_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (yb_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (yb_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (yb_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (yb_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (xb_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (xb_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (xb_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (xb_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (xb_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (xb_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (xb_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (xb_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (xb_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (xb_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (xb_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (xb_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (xb_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (xb_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (xb_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (xb_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (xb_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (xb_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (xb_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (xb_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (xb_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (xb_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (xb_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (xb_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (xb_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (xb_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (xb_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (xb_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (xb_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (xb_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (xb_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (xb_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (xb_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (xb_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (xb_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (xb_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (xb_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (xb_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (ac_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (ac_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (ac_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (ac_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (ac_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (ac_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (ac_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (ac_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (ac_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (ac_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (ac_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (ac_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (ac_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (ac_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (ac_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (ac_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (bc_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (bc_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (xb_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (xb_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (xb_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (xb_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (xb_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (xb_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (xb_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (xb_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (xb_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (xb_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (xb_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (xb_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (xb_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (xb_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (xb_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (xb_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (xb_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (xb_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (xb_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (xb_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (cc_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (ac_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (xb_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_wrap_0 dimm[29]
 *                boolean_T mask[29]
 * Return Type  : void
 */
void q_containsNonVect(const cell_wrap_0 dimm[29], boolean_T mask[29])
{
  static const char cv[3] = {'T', 'O', 'R'};
  int i;
  for (i = 0; i < 29; i++) {
    int b_i;
    boolean_T exitg1;
    mask[i] = false;
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i < 3)) {
      int j;
      j = 1;
      while ((j <= 3) && (dimm[i].f1[(b_i + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 3) {
        mask[i] = true;
        exitg1 = true;
      } else {
        b_i++;
      }
    }
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void r_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (dc_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (ec_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (ec_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (ec_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (ec_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (ec_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (ec_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (ec_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (ec_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (ec_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (ec_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (ec_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (ec_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (ec_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (ec_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (ec_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (ec_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (ec_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (ec_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (ec_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (ec_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (ec_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (ec_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (ec_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (ec_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (ec_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (ec_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (ec_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (ec_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (ec_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (ec_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (ec_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (ec_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (ec_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (ec_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (ec_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (ec_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (ec_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (dc_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (dc_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (dc_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (dc_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (dc_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (dc_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (dc_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (dc_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (dc_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (dc_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (dc_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (dc_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (dc_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (dc_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (dc_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (dc_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (dc_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (dc_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (dc_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (dc_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (dc_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (dc_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (dc_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (dc_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (dc_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (dc_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (dc_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (dc_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (dc_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (dc_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (dc_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (dc_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (dc_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (dc_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (dc_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (dc_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (dc_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (dc_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (fc_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (fc_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (fc_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (fc_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (fc_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (fc_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (fc_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (fc_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (fc_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (fc_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (fc_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (fc_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (fc_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (fc_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (fc_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (fc_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (gc_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (gc_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (dc_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (dc_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (dc_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (dc_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (dc_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (dc_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (dc_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (dc_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (dc_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (dc_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (dc_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (dc_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (dc_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (dc_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (dc_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (dc_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (dc_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (dc_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (dc_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (dc_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (hc_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (fc_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (dc_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void s_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (ic_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (jc_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (jc_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (jc_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (jc_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (jc_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (jc_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (jc_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (jc_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (jc_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (jc_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (jc_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (jc_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (jc_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (jc_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (jc_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (jc_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (jc_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (jc_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (jc_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (jc_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (jc_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (jc_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (jc_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (jc_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (jc_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (jc_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (jc_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (jc_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (jc_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (jc_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (jc_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (jc_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (jc_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (jc_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (jc_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (jc_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (jc_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (ic_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (ic_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (ic_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (ic_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (ic_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (ic_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (ic_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (ic_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (ic_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (ic_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (ic_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (ic_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (ic_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (ic_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (ic_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (ic_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (ic_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (ic_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (ic_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (ic_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (ic_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (ic_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (ic_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (ic_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (ic_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (ic_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (ic_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (ic_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (ic_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (ic_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (ic_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (ic_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (ic_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (ic_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (ic_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (ic_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (ic_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (ic_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (kc_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (kc_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (kc_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (kc_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (kc_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (kc_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (kc_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (kc_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (kc_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (kc_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (kc_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (kc_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (kc_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (kc_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (kc_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (kc_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (lc_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (lc_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (ic_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (ic_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (ic_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (ic_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (ic_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (ic_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (ic_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (ic_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (ic_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (ic_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (ic_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (ic_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (ic_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (ic_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (ic_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (ic_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (ic_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (ic_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (ic_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (ic_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (mc_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (kc_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (ic_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * CONTAINSNONVECT Codegen-safe, non-vectorized version of contains function,
 * with array of cells as input. contains function does not work in codgen when
 * input is a cell array or string vector. It does not support vectorization.
 * Solution: explicit for loop. inputs:
 *    -   dimm: cellArray of char vector or string array,
 *    -   pat: char vector of the patern to find.
 *
 *    Note: as the intent use of this function is to be used in code
 *    generation, explicit for loop is not that slow compared to I/O for
 *    arrays of size ~1000 elements.
 *
 *
 * Arguments    : const cell_1 *dimm
 *                boolean_T mask[117]
 * Return Type  : void
 */
void t_containsNonVect(const cell_1 *dimm, boolean_T mask[117])
{
  memset(&mask[0], 0, 117U * sizeof(boolean_T));
  if (nc_contains(dimm->f1)) {
    mask[0] = true;
  }
  if (oc_contains(dimm->f2)) {
    mask[1] = true;
  }
  if (oc_contains(dimm->f3)) {
    mask[2] = true;
  }
  if (oc_contains(dimm->f4)) {
    mask[3] = true;
  }
  if (oc_contains(dimm->f5)) {
    mask[4] = true;
  }
  if (oc_contains(dimm->f6)) {
    mask[5] = true;
  }
  if (oc_contains(dimm->f7)) {
    mask[6] = true;
  }
  if (oc_contains(dimm->f8)) {
    mask[7] = true;
  }
  if (oc_contains(dimm->f9)) {
    mask[8] = true;
  }
  if (oc_contains(dimm->f10)) {
    mask[9] = true;
  }
  if (oc_contains(dimm->f11)) {
    mask[10] = true;
  }
  if (oc_contains(dimm->f12)) {
    mask[11] = true;
  }
  if (oc_contains(dimm->f13)) {
    mask[12] = true;
  }
  if (oc_contains(dimm->f14)) {
    mask[13] = true;
  }
  if (oc_contains(dimm->f15)) {
    mask[14] = true;
  }
  if (oc_contains(dimm->f16)) {
    mask[15] = true;
  }
  if (oc_contains(dimm->f17)) {
    mask[16] = true;
  }
  if (oc_contains(dimm->f18)) {
    mask[17] = true;
  }
  if (oc_contains(dimm->f19)) {
    mask[18] = true;
  }
  if (oc_contains(dimm->f20)) {
    mask[19] = true;
  }
  if (oc_contains(dimm->f21)) {
    mask[20] = true;
  }
  if (oc_contains(dimm->f22)) {
    mask[21] = true;
  }
  if (oc_contains(dimm->f23)) {
    mask[22] = true;
  }
  if (oc_contains(dimm->f24)) {
    mask[23] = true;
  }
  if (oc_contains(dimm->f25)) {
    mask[24] = true;
  }
  if (oc_contains(dimm->f26)) {
    mask[25] = true;
  }
  if (oc_contains(dimm->f27)) {
    mask[26] = true;
  }
  if (oc_contains(dimm->f28)) {
    mask[27] = true;
  }
  if (oc_contains(dimm->f29)) {
    mask[28] = true;
  }
  if (oc_contains(dimm->f30)) {
    mask[29] = true;
  }
  if (oc_contains(dimm->f31)) {
    mask[30] = true;
  }
  if (oc_contains(dimm->f32)) {
    mask[31] = true;
  }
  if (oc_contains(dimm->f33)) {
    mask[32] = true;
  }
  if (oc_contains(dimm->f34)) {
    mask[33] = true;
  }
  if (oc_contains(dimm->f35)) {
    mask[34] = true;
  }
  if (oc_contains(dimm->f36)) {
    mask[35] = true;
  }
  if (oc_contains(dimm->f37)) {
    mask[36] = true;
  }
  if (oc_contains(dimm->f38)) {
    mask[37] = true;
  }
  if (nc_contains(dimm->f39)) {
    mask[38] = true;
  }
  if (nc_contains(dimm->f40)) {
    mask[39] = true;
  }
  if (nc_contains(dimm->f41)) {
    mask[40] = true;
  }
  if (nc_contains(dimm->f42)) {
    mask[41] = true;
  }
  if (nc_contains(dimm->f43)) {
    mask[42] = true;
  }
  if (nc_contains(dimm->f44)) {
    mask[43] = true;
  }
  if (nc_contains(dimm->f45)) {
    mask[44] = true;
  }
  if (nc_contains(dimm->f46)) {
    mask[45] = true;
  }
  if (nc_contains(dimm->f47)) {
    mask[46] = true;
  }
  if (nc_contains(dimm->f48)) {
    mask[47] = true;
  }
  if (nc_contains(dimm->f49)) {
    mask[48] = true;
  }
  if (nc_contains(dimm->f50)) {
    mask[49] = true;
  }
  if (nc_contains(dimm->f51)) {
    mask[50] = true;
  }
  if (nc_contains(dimm->f52)) {
    mask[51] = true;
  }
  if (nc_contains(dimm->f53)) {
    mask[52] = true;
  }
  if (nc_contains(dimm->f54)) {
    mask[53] = true;
  }
  if (nc_contains(dimm->f55)) {
    mask[54] = true;
  }
  if (nc_contains(dimm->f56)) {
    mask[55] = true;
  }
  if (nc_contains(dimm->f57)) {
    mask[56] = true;
  }
  if (nc_contains(dimm->f58)) {
    mask[57] = true;
  }
  if (nc_contains(dimm->f59)) {
    mask[58] = true;
  }
  if (nc_contains(dimm->f60)) {
    mask[59] = true;
  }
  if (nc_contains(dimm->f61)) {
    mask[60] = true;
  }
  if (nc_contains(dimm->f62)) {
    mask[61] = true;
  }
  if (nc_contains(dimm->f63)) {
    mask[62] = true;
  }
  if (nc_contains(dimm->f64)) {
    mask[63] = true;
  }
  if (nc_contains(dimm->f65)) {
    mask[64] = true;
  }
  if (nc_contains(dimm->f66)) {
    mask[65] = true;
  }
  if (nc_contains(dimm->f67)) {
    mask[66] = true;
  }
  if (nc_contains(dimm->f68)) {
    mask[67] = true;
  }
  if (nc_contains(dimm->f69)) {
    mask[68] = true;
  }
  if (nc_contains(dimm->f70)) {
    mask[69] = true;
  }
  if (nc_contains(dimm->f71)) {
    mask[70] = true;
  }
  if (nc_contains(dimm->f72)) {
    mask[71] = true;
  }
  if (nc_contains(dimm->f73)) {
    mask[72] = true;
  }
  if (nc_contains(dimm->f74)) {
    mask[73] = true;
  }
  if (nc_contains(dimm->f75)) {
    mask[74] = true;
  }
  if (nc_contains(dimm->f76)) {
    mask[75] = true;
  }
  if (pc_contains(dimm->f77)) {
    mask[76] = true;
  }
  if (pc_contains(dimm->f78)) {
    mask[77] = true;
  }
  if (pc_contains(dimm->f79)) {
    mask[78] = true;
  }
  if (pc_contains(dimm->f80)) {
    mask[79] = true;
  }
  if (pc_contains(dimm->f81)) {
    mask[80] = true;
  }
  if (pc_contains(dimm->f82)) {
    mask[81] = true;
  }
  if (pc_contains(dimm->f83)) {
    mask[82] = true;
  }
  if (pc_contains(dimm->f84)) {
    mask[83] = true;
  }
  if (pc_contains(dimm->f85)) {
    mask[84] = true;
  }
  if (pc_contains(dimm->f86)) {
    mask[85] = true;
  }
  if (pc_contains(dimm->f87)) {
    mask[86] = true;
  }
  if (pc_contains(dimm->f88)) {
    mask[87] = true;
  }
  if (pc_contains(dimm->f89)) {
    mask[88] = true;
  }
  if (pc_contains(dimm->f90)) {
    mask[89] = true;
  }
  if (pc_contains(dimm->f91)) {
    mask[90] = true;
  }
  if (pc_contains(dimm->f92)) {
    mask[91] = true;
  }
  if (qc_contains(dimm->f93)) {
    mask[92] = true;
  }
  if (qc_contains(dimm->f94)) {
    mask[93] = true;
  }
  if (nc_contains(dimm->f95)) {
    mask[94] = true;
  }
  if (nc_contains(dimm->f96)) {
    mask[95] = true;
  }
  if (nc_contains(dimm->f97)) {
    mask[96] = true;
  }
  if (nc_contains(dimm->f98)) {
    mask[97] = true;
  }
  if (nc_contains(dimm->f99)) {
    mask[98] = true;
  }
  if (nc_contains(dimm->f100)) {
    mask[99] = true;
  }
  if (nc_contains(dimm->f101)) {
    mask[100] = true;
  }
  if (nc_contains(dimm->f102)) {
    mask[101] = true;
  }
  if (nc_contains(dimm->f103)) {
    mask[102] = true;
  }
  if (nc_contains(dimm->f104)) {
    mask[103] = true;
  }
  if (nc_contains(dimm->f105)) {
    mask[104] = true;
  }
  if (nc_contains(dimm->f106)) {
    mask[105] = true;
  }
  if (nc_contains(dimm->f107)) {
    mask[106] = true;
  }
  if (nc_contains(dimm->f108)) {
    mask[107] = true;
  }
  if (nc_contains(dimm->f109)) {
    mask[108] = true;
  }
  if (nc_contains(dimm->f110)) {
    mask[109] = true;
  }
  if (nc_contains(dimm->f111)) {
    mask[110] = true;
  }
  if (nc_contains(dimm->f112)) {
    mask[111] = true;
  }
  if (nc_contains(dimm->f113)) {
    mask[112] = true;
  }
  if (nc_contains(dimm->f114)) {
    mask[113] = true;
  }
  if (rc_contains(dimm->f115)) {
    mask[114] = true;
  }
  if (pc_contains(dimm->f116)) {
    mask[115] = true;
  }
  if (nc_contains(dimm->f117)) {
    mask[116] = true;
  }
}

/*
 * File trailer for containsNonVect.c
 *
 * [EOF]
 */
