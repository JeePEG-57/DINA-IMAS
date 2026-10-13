/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_hybctrl_step_IDS_api.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 28-Apr-2026 10:26:51
 */

/* Include Files */
#include "_coder_hybctrl_step_IDS_api.h"
#include "_coder_hybctrl_step_IDS_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131626U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "hybctrl_step_IDS",                                   /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                boolean_T y[26]);

static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[5]);

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *b_emlrt_marshallOut(const struct8_T *u);

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId);

static real_T (*bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[26];

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *magn,
                               const char_T *identifier, struct0_T *y);

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct4_T *y);

static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[3042]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T *y);

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[760]);

static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[6]);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[38]);

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, cell_4 *y);

static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[7]);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *t,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const real_T u[19]);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pfa,
                               const char_T *identifier, struct1_T *y);

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, cell_5 *y);

static void fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[8]);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct1_T *y);

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                boolean_T y[19]);

static void gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[9]);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[29]);

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct5_T *y);

static void hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[10]);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               cell_wrap_0 y[29]);

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct6_T *y);

static void ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[14]);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[5]);

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[10]);

static void jc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[13]);

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Arefs,
                                   const char_T *identifier))[26];

static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[5720]);

static void kc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                boolean_T ret[26]);

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[26];

static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                cell_wrap_0 y[22]);

static void lc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[760]);

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *cpar,
                               const char_T *identifier, struct2_T *y);

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                boolean_T y[40]);

static void mc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                boolean_T ret[19]);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct2_T *y);

static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct7_T *y);

static void nc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[10]);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct3_T *y);

static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[10816]);

static void oc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[5720]);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[3042]);

static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[2704]);

static void pc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                boolean_T ret[40]);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_1 *y);

static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[8112]);

static void qc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[10816]);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[6]);

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[2028]);

static void rc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[2704]);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[7]);

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *cstate,
                                const char_T *identifier, struct8_T *y);

static void sc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[8112]);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[8]);

static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct8_T *y);

static void tc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[2028]);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[9]);

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[104]);

static void uc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[104]);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[10]);

static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId);

static void vc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_2 *y);

static real_T wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[14]);

static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[38]);

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[13]);

static void yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[29]);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                boolean_T y[26]
 * Return Type  : void
 */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                boolean_T y[26])
{
  kc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                char_T ret[5]
 * Return Type  : void
 */
static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[5])
{
  static const int32_T dims[2] = {1, 5};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 5);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = wb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const struct8_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const struct8_T *u)
{
  static const int32_T i = 104;
  static const int32_T i1 = 0;
  static const char_T *sv[2] = {"hyb", "ps"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 104; b_i++) {
    pData[b_i] = u->hyb[b_i];
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"hyb", b_y, 0);
  c_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i1, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ps", c_y, 1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId)
{
  int32_T iv[2];
  boolean_T bv[2];
  bv[0] = false;
  iv[0] = 0;
  bv[1] = false;
  iv[1] = 0;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[26]
 */
static real_T (*bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[26]
{
  static const int32_T dims = 26;
  real_T(*ret)[26];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  ret = (real_T(*)[26])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *magn
 *                const char_T *identifier
 *                struct0_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *magn,
                               const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(magn), &thisId, y);
  emlrtDestroyArray(&magn);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct4_T *y
 * Return Type  : void
 */
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct4_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[4] = {"data", "dimin", "dimout", "lhyb"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 4,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "data";
  db_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                     (const char_T *)"data")),
                      &thisId, y->data);
  thisId.fIdentifier = "dimin";
  eb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                     (const char_T *)"dimin")),
                      &thisId, &y->dimin);
  thisId.fIdentifier = "dimout";
  fb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                     (const char_T *)"dimout")),
                      &thisId, &y->dimout);
  thisId.fIdentifier = "lhyb";
  gb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                                     (const char_T *)"lhyb")),
                      &thisId, y->lhyb);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[3042]
 * Return Type  : void
 */
static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[3042])
{
  static const int32_T dims[2] = {26, 117};
  real_T(*r)[3042];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[3042])emlrtMxGetData(src);
  for (i = 0; i < 3042; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct0_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = {"time", "Bm", "Ff"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 3,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "time";
  y->time =
      b_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 0, (const char_T *)"time")),
                         &thisId);
  thisId.fIdentifier = "Bm";
  e_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                    (const char_T *)"Bm")),
                     &thisId, y->Bm);
  thisId.fIdentifier = "Ff";
  e_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                    (const char_T *)"Ff")),
                     &thisId, y->Ff);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[760]
 * Return Type  : void
 */
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[760])
{
  lc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                char_T ret[6]
 * Return Type  : void
 */
static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[6])
{
  static const int32_T dims[2] = {1, 6};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 6);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[38]
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[38])
{
  xb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                cell_4 *y
 * Return Type  : void
 */
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, cell_4 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T i;
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b = false;
  i = 40;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  thisId.fIdentifier = "1";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y->f1);
  thisId.fIdentifier = "2";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, y->f2);
  thisId.fIdentifier = "3";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                     &thisId, y->f3);
  thisId.fIdentifier = "4";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 3)),
                     &thisId, y->f4);
  thisId.fIdentifier = "5";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 4)),
                     &thisId, y->f5);
  thisId.fIdentifier = "6";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 5)),
                     &thisId, y->f6);
  thisId.fIdentifier = "7";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 6)),
                     &thisId, y->f7);
  thisId.fIdentifier = "8";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 7)),
                     &thisId, y->f8);
  thisId.fIdentifier = "9";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 8)),
                     &thisId, y->f9);
  thisId.fIdentifier = "10";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 9)),
                     &thisId, y->f10);
  thisId.fIdentifier = "11";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 10)),
                     &thisId, y->f11);
  thisId.fIdentifier = "12";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 11)),
                     &thisId, y->f12);
  thisId.fIdentifier = "13";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 12)),
                     &thisId, y->f13);
  thisId.fIdentifier = "14";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 13)),
                     &thisId, y->f14);
  thisId.fIdentifier = "15";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 14)),
                     &thisId, y->f15);
  thisId.fIdentifier = "16";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 15)),
                     &thisId, y->f16);
  thisId.fIdentifier = "17";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 16)),
                     &thisId, y->f17);
  thisId.fIdentifier = "18";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 17)),
                     &thisId, y->f18);
  thisId.fIdentifier = "19";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 18)),
                     &thisId, y->f19);
  thisId.fIdentifier = "20";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 19)),
                     &thisId, y->f20);
  thisId.fIdentifier = "21";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 20)),
                     &thisId, y->f21);
  thisId.fIdentifier = "22";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 21)),
                     &thisId, y->f22);
  thisId.fIdentifier = "23";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 22)),
                     &thisId, y->f23);
  thisId.fIdentifier = "24";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 23)),
                     &thisId, y->f24);
  thisId.fIdentifier = "25";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 24)),
                     &thisId, y->f25);
  thisId.fIdentifier = "26";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 25)),
                     &thisId, y->f26);
  thisId.fIdentifier = "27";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 26)),
                     &thisId, y->f27);
  thisId.fIdentifier = "28";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 27)),
                     &thisId, y->f28);
  thisId.fIdentifier = "29";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 28)),
                     &thisId, y->f29);
  thisId.fIdentifier = "30";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 29)),
                     &thisId, y->f30);
  thisId.fIdentifier = "31";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 30)),
                     &thisId, y->f31);
  thisId.fIdentifier = "32";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 31)),
                     &thisId, y->f32);
  thisId.fIdentifier = "33";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 32)),
                     &thisId, y->f33);
  thisId.fIdentifier = "34";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 33)),
                     &thisId, y->f34);
  thisId.fIdentifier = "35";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 34)),
                     &thisId, y->f35);
  thisId.fIdentifier = "36";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 35)),
                     &thisId, y->f36);
  thisId.fIdentifier = "37";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 36)),
                     &thisId, y->f37);
  thisId.fIdentifier = "38";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 37)),
                     &thisId, y->f38);
  thisId.fIdentifier = "39";
  u_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 38)),
                     &thisId, y->f39);
  thisId.fIdentifier = "40";
  u_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 39)),
                     &thisId, y->f40);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                char_T ret[7]
 * Return Type  : void
 */
static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[7])
{
  static const int32_T dims[2] = {1, 7};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 7);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *t
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *t,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(t), &thisId);
  emlrtDestroyArray(&t);
  return y;
}

/*
 * Arguments    : const real_T u[19]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u[19])
{
  static const int32_T i = 0;
  static const int32_T i1 = 19;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *pfa
 *                const char_T *identifier
 *                struct1_T *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pfa,
                               const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  g_emlrt_marshallIn(sp, emlrtAlias(pfa), &thisId, y);
  emlrtDestroyArray(&pfa);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                cell_5 *y
 * Return Type  : void
 */
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, cell_5 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T i;
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b = false;
  i = 19;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  thisId.fIdentifier = "1";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y->f1);
  thisId.fIdentifier = "2";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, y->f2);
  thisId.fIdentifier = "3";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                     &thisId, y->f3);
  thisId.fIdentifier = "4";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 3)),
                     &thisId, y->f4);
  thisId.fIdentifier = "5";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 4)),
                     &thisId, y->f5);
  thisId.fIdentifier = "6";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 5)),
                     &thisId, y->f6);
  thisId.fIdentifier = "7";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 6)),
                     &thisId, y->f7);
  thisId.fIdentifier = "8";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 7)),
                     &thisId, y->f8);
  thisId.fIdentifier = "9";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 8)),
                     &thisId, y->f9);
  thisId.fIdentifier = "10";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 9)),
                     &thisId, y->f10);
  thisId.fIdentifier = "11";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 10)),
                     &thisId, y->f11);
  thisId.fIdentifier = "12";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 11)),
                     &thisId, y->f12);
  thisId.fIdentifier = "13";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 12)),
                     &thisId, y->f13);
  thisId.fIdentifier = "14";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 13)),
                     &thisId, y->f14);
  thisId.fIdentifier = "15";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 14)),
                     &thisId, y->f15);
  thisId.fIdentifier = "16";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 15)),
                     &thisId, y->f16);
  thisId.fIdentifier = "17";
  u_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 16)),
                     &thisId, y->f17);
  thisId.fIdentifier = "18";
  u_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 17)),
                     &thisId, y->f18);
  thisId.fIdentifier = "19";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 18)),
                     &thisId, y->f19);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                char_T ret[8]
 * Return Type  : void
 */
static void fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[8])
{
  static const int32_T dims[2] = {1, 8};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 8);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct1_T *y
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = {"time", "Ia", "names"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 3,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "time";
  y->time =
      b_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 0, (const char_T *)"time")),
                         &thisId);
  thisId.fIdentifier = "Ia";
  h_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                    (const char_T *)"Ia")),
                     &thisId, y->Ia);
  thisId.fIdentifier = "names";
  i_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                    (const char_T *)"names")),
                     &thisId, y->names);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                boolean_T y[19]
 * Return Type  : void
 */
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                boolean_T y[19])
{
  mc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                char_T ret[9]
 * Return Type  : void
 */
static void gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[9])
{
  static const int32_T dims[2] = {1, 9};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 9);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[29]
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[29])
{
  yb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct5_T *y
 * Return Type  : void
 */
static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct5_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[6] = {"addr", "G1I",   "G2P",
                                        "G3D",  "dimin", "dimout"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 6,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "addr";
  ib_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                     (const char_T *)"addr")),
                      &thisId, &y->addr);
  thisId.fIdentifier = "G1I";
  kb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                     (const char_T *)"G1I")),
                      &thisId, y->G1I);
  thisId.fIdentifier = "G2P";
  kb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                     (const char_T *)"G2P")),
                      &thisId, y->G2P);
  thisId.fIdentifier = "G3D";
  kb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                                     (const char_T *)"G3D")),
                      &thisId, y->G3D);
  thisId.fIdentifier = "dimin";
  w_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                                    (const char_T *)"dimin")),
                     &thisId, &y->dimin);
  thisId.fIdentifier = "dimout";
  lb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                                     (const char_T *)"dimout")),
                      &thisId, y->dimout);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                char_T ret[10]
 * Return Type  : void
 */
static void hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[10])
{
  static const int32_T dims[2] = {1, 10};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 10);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                cell_wrap_0 y[29]
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               cell_wrap_0 y[29])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T i;
  char_T str[11];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  bv[0] = false;
  iv[0] = 1;
  bv[1] = false;
  iv[1] = 29;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  for (i = 0; i < 29; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    j_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, y[i].f1);
  }
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct6_T *y
 * Return Type  : void
 */
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct6_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[2] = {"time", "data"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 2,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "time";
  jb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                     (const char_T *)"time")),
                      &thisId, y->time);
  thisId.fIdentifier = "data";
  jb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                     (const char_T *)"data")),
                      &thisId, y->data);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                char_T ret[14]
 * Return Type  : void
 */
static void ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = {1, 14};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                char_T y[5]
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[5])
{
  ac_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[10]
 * Return Type  : void
 */
static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[10])
{
  nc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                char_T ret[13]
 * Return Type  : void
 */
static void jc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[13])
{
  static const int32_T dims[2] = {1, 13};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 13);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Arefs
 *                const char_T *identifier
 * Return Type  : real_T (*)[26]
 */
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Arefs,
                                   const char_T *identifier))[26]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[26];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(Arefs), &thisId);
  emlrtDestroyArray(&Arefs);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[5720]
 * Return Type  : void
 */
static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[5720])
{
  oc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                boolean_T ret[26]
 * Return Type  : void
 */
static void kc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                boolean_T ret[26])
{
  static const int32_T dims = 26;
  int32_T i;
  boolean_T(*r)[26];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"logical",
                          false, 1U, (void *)&dims);
  r = (boolean_T(*)[26])emlrtMxGetLogicals(src);
  for (i = 0; i < 26; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[26]
 */
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[26]
{
  real_T(*y)[26];
  y = bc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                cell_wrap_0 y[22]
 * Return Type  : void
 */
static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                cell_wrap_0 y[22])
{
  emlrtMsgIdentifier thisId;
  int32_T i;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b = false;
  i = 22;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  for (i = 0; i < 22; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    j_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, y[i].f1);
  }
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[760]
 * Return Type  : void
 */
static void lc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[760])
{
  static const int32_T dims[2] = {19, 40};
  real_T(*r)[760];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[760])emlrtMxGetData(src);
  for (i = 0; i < 760; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *cpar
 *                const char_T *identifier
 *                struct2_T *y
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *cpar,
                               const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(sp, emlrtAlias(cpar), &thisId, y);
  emlrtDestroyArray(&cpar);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                boolean_T y[40]
 * Return Type  : void
 */
static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                boolean_T y[40])
{
  pc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                boolean_T ret[19]
 * Return Type  : void
 */
static void mc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                boolean_T ret[19])
{
  static const int32_T dims = 19;
  int32_T i;
  boolean_T(*r)[19];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"logical",
                          false, 1U, (void *)&dims);
  r = (boolean_T(*)[19])emlrtMxGetLogicals(src);
  for (i = 0; i < 19; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct2_T *y
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct2_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[8] = {"Amat", "Mmat",  "Gmat",  "iEin",
                                        "iFin", "iOHin", "iGOin", "ssPIDd"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 8,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "Amat";
  o_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                    (const char_T *)"Amat")),
                     &thisId, &y->Amat);
  thisId.fIdentifier = "Mmat";
  cb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                     (const char_T *)"Mmat")),
                      &thisId, &y->Mmat);
  thisId.fIdentifier = "Gmat";
  hb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                     (const char_T *)"Gmat")),
                      &thisId, &y->Gmat);
  thisId.fIdentifier = "iEin";
  mb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                                     (const char_T *)"iEin")),
                      &thisId, y->iEin);
  thisId.fIdentifier = "iFin";
  mb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                                     (const char_T *)"iFin")),
                      &thisId, y->iFin);
  thisId.fIdentifier = "iOHin";
  mb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                                     (const char_T *)"iOHin")),
                      &thisId, y->iOHin);
  thisId.fIdentifier = "iGOin";
  mb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 6,
                                                     (const char_T *)"iGOin")),
                      &thisId, y->iGOin);
  thisId.fIdentifier = "ssPIDd";
  nb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 7,
                                                     (const char_T *)"ssPIDd")),
                      &thisId, &y->ssPIDd);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct7_T *y
 * Return Type  : void
 */
static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct7_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[4] = {"a", "b", "c", "d"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 4,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "a";
  ob_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                     (const char_T *)"a")),
                      &thisId, y->a);
  thisId.fIdentifier = "b";
  pb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                     (const char_T *)"b")),
                      &thisId, y->b);
  thisId.fIdentifier = "c";
  qb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                     (const char_T *)"c")),
                      &thisId, y->c);
  thisId.fIdentifier = "d";
  rb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                                     (const char_T *)"d")),
                      &thisId, y->d);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[10]
 * Return Type  : void
 */
static void nc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[10])
{
  static const int32_T dims[2] = {1, 10};
  real_T(*r)[10];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[10])emlrtMxGetData(src);
  for (i = 0; i < 10; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct3_T *y
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct3_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[5] = {"data", "dimin", "dimout", "lhyb",
                                        "dimhyb"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 5,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "data";
  p_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                    (const char_T *)"data")),
                     &thisId, y->data);
  thisId.fIdentifier = "dimin";
  q_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                    (const char_T *)"dimin")),
                     &thisId, &y->dimin);
  thisId.fIdentifier = "dimout";
  w_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                    (const char_T *)"dimout")),
                     &thisId, &y->dimout);
  thisId.fIdentifier = "lhyb";
  ab_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                                     (const char_T *)"lhyb")),
                      &thisId, y->lhyb);
  thisId.fIdentifier = "dimhyb";
  bb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                                     (const char_T *)"dimhyb")),
                      &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[10816]
 * Return Type  : void
 */
static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[10816])
{
  qc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[5720]
 * Return Type  : void
 */
static void oc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[5720])
{
  static const int32_T dims[3] = {22, 26, 10};
  real_T(*r)[5720];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 3U, (void *)&dims[0]);
  r = (real_T(*)[5720])emlrtMxGetData(src);
  for (i = 0; i < 5720; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[3042]
 * Return Type  : void
 */
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[3042])
{
  cc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[2704]
 * Return Type  : void
 */
static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[2704])
{
  rc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                boolean_T ret[40]
 * Return Type  : void
 */
static void pc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                boolean_T ret[40])
{
  static const int32_T dims = 40;
  int32_T i;
  boolean_T(*r)[40];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"logical",
                          false, 1U, (void *)&dims);
  r = (boolean_T(*)[40])emlrtMxGetLogicals(src);
  for (i = 0; i < 40; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                cell_1 *y
 * Return Type  : void
 */
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_1 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T i;
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b = false;
  i = 117;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  thisId.fIdentifier = "1";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y->f1);
  thisId.fIdentifier = "2";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, y->f2);
  thisId.fIdentifier = "3";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                     &thisId, y->f3);
  thisId.fIdentifier = "4";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 3)),
                     &thisId, y->f4);
  thisId.fIdentifier = "5";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 4)),
                     &thisId, y->f5);
  thisId.fIdentifier = "6";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 5)),
                     &thisId, y->f6);
  thisId.fIdentifier = "7";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 6)),
                     &thisId, y->f7);
  thisId.fIdentifier = "8";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 7)),
                     &thisId, y->f8);
  thisId.fIdentifier = "9";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 8)),
                     &thisId, y->f9);
  thisId.fIdentifier = "10";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 9)),
                     &thisId, y->f10);
  thisId.fIdentifier = "11";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 10)),
                     &thisId, y->f11);
  thisId.fIdentifier = "12";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 11)),
                     &thisId, y->f12);
  thisId.fIdentifier = "13";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 12)),
                     &thisId, y->f13);
  thisId.fIdentifier = "14";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 13)),
                     &thisId, y->f14);
  thisId.fIdentifier = "15";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 14)),
                     &thisId, y->f15);
  thisId.fIdentifier = "16";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 15)),
                     &thisId, y->f16);
  thisId.fIdentifier = "17";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 16)),
                     &thisId, y->f17);
  thisId.fIdentifier = "18";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 17)),
                     &thisId, y->f18);
  thisId.fIdentifier = "19";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 18)),
                     &thisId, y->f19);
  thisId.fIdentifier = "20";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 19)),
                     &thisId, y->f20);
  thisId.fIdentifier = "21";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 20)),
                     &thisId, y->f21);
  thisId.fIdentifier = "22";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 21)),
                     &thisId, y->f22);
  thisId.fIdentifier = "23";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 22)),
                     &thisId, y->f23);
  thisId.fIdentifier = "24";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 23)),
                     &thisId, y->f24);
  thisId.fIdentifier = "25";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 24)),
                     &thisId, y->f25);
  thisId.fIdentifier = "26";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 25)),
                     &thisId, y->f26);
  thisId.fIdentifier = "27";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 26)),
                     &thisId, y->f27);
  thisId.fIdentifier = "28";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 27)),
                     &thisId, y->f28);
  thisId.fIdentifier = "29";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 28)),
                     &thisId, y->f29);
  thisId.fIdentifier = "30";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 29)),
                     &thisId, y->f30);
  thisId.fIdentifier = "31";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 30)),
                     &thisId, y->f31);
  thisId.fIdentifier = "32";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 31)),
                     &thisId, y->f32);
  thisId.fIdentifier = "33";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 32)),
                     &thisId, y->f33);
  thisId.fIdentifier = "34";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 33)),
                     &thisId, y->f34);
  thisId.fIdentifier = "35";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 34)),
                     &thisId, y->f35);
  thisId.fIdentifier = "36";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 35)),
                     &thisId, y->f36);
  thisId.fIdentifier = "37";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 36)),
                     &thisId, y->f37);
  thisId.fIdentifier = "38";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 37)),
                     &thisId, y->f38);
  thisId.fIdentifier = "39";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 38)),
                     &thisId, y->f39);
  thisId.fIdentifier = "40";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 39)),
                     &thisId, y->f40);
  thisId.fIdentifier = "41";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 40)),
                     &thisId, y->f41);
  thisId.fIdentifier = "42";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 41)),
                     &thisId, y->f42);
  thisId.fIdentifier = "43";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 42)),
                     &thisId, y->f43);
  thisId.fIdentifier = "44";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 43)),
                     &thisId, y->f44);
  thisId.fIdentifier = "45";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 44)),
                     &thisId, y->f45);
  thisId.fIdentifier = "46";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 45)),
                     &thisId, y->f46);
  thisId.fIdentifier = "47";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 46)),
                     &thisId, y->f47);
  thisId.fIdentifier = "48";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 47)),
                     &thisId, y->f48);
  thisId.fIdentifier = "49";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 48)),
                     &thisId, y->f49);
  thisId.fIdentifier = "50";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 49)),
                     &thisId, y->f50);
  thisId.fIdentifier = "51";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 50)),
                     &thisId, y->f51);
  thisId.fIdentifier = "52";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 51)),
                     &thisId, y->f52);
  thisId.fIdentifier = "53";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 52)),
                     &thisId, y->f53);
  thisId.fIdentifier = "54";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 53)),
                     &thisId, y->f54);
  thisId.fIdentifier = "55";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 54)),
                     &thisId, y->f55);
  thisId.fIdentifier = "56";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 55)),
                     &thisId, y->f56);
  thisId.fIdentifier = "57";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 56)),
                     &thisId, y->f57);
  thisId.fIdentifier = "58";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 57)),
                     &thisId, y->f58);
  thisId.fIdentifier = "59";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 58)),
                     &thisId, y->f59);
  thisId.fIdentifier = "60";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 59)),
                     &thisId, y->f60);
  thisId.fIdentifier = "61";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 60)),
                     &thisId, y->f61);
  thisId.fIdentifier = "62";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 61)),
                     &thisId, y->f62);
  thisId.fIdentifier = "63";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 62)),
                     &thisId, y->f63);
  thisId.fIdentifier = "64";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 63)),
                     &thisId, y->f64);
  thisId.fIdentifier = "65";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 64)),
                     &thisId, y->f65);
  thisId.fIdentifier = "66";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 65)),
                     &thisId, y->f66);
  thisId.fIdentifier = "67";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 66)),
                     &thisId, y->f67);
  thisId.fIdentifier = "68";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 67)),
                     &thisId, y->f68);
  thisId.fIdentifier = "69";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 68)),
                     &thisId, y->f69);
  thisId.fIdentifier = "70";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 69)),
                     &thisId, y->f70);
  thisId.fIdentifier = "71";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 70)),
                     &thisId, y->f71);
  thisId.fIdentifier = "72";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 71)),
                     &thisId, y->f72);
  thisId.fIdentifier = "73";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 72)),
                     &thisId, y->f73);
  thisId.fIdentifier = "74";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 73)),
                     &thisId, y->f74);
  thisId.fIdentifier = "75";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 74)),
                     &thisId, y->f75);
  thisId.fIdentifier = "76";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 75)),
                     &thisId, y->f76);
  thisId.fIdentifier = "77";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 76)),
                     &thisId, y->f77);
  thisId.fIdentifier = "78";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 77)),
                     &thisId, y->f78);
  thisId.fIdentifier = "79";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 78)),
                     &thisId, y->f79);
  thisId.fIdentifier = "80";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 79)),
                     &thisId, y->f80);
  thisId.fIdentifier = "81";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 80)),
                     &thisId, y->f81);
  thisId.fIdentifier = "82";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 81)),
                     &thisId, y->f82);
  thisId.fIdentifier = "83";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 82)),
                     &thisId, y->f83);
  thisId.fIdentifier = "84";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 83)),
                     &thisId, y->f84);
  thisId.fIdentifier = "85";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 84)),
                     &thisId, y->f85);
  thisId.fIdentifier = "86";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 85)),
                     &thisId, y->f86);
  thisId.fIdentifier = "87";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 86)),
                     &thisId, y->f87);
  thisId.fIdentifier = "88";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 87)),
                     &thisId, y->f88);
  thisId.fIdentifier = "89";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 88)),
                     &thisId, y->f89);
  thisId.fIdentifier = "90";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 89)),
                     &thisId, y->f90);
  thisId.fIdentifier = "91";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 90)),
                     &thisId, y->f91);
  thisId.fIdentifier = "92";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 91)),
                     &thisId, y->f92);
  thisId.fIdentifier = "93";
  u_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 92)),
                     &thisId, y->f93);
  thisId.fIdentifier = "94";
  u_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 93)),
                     &thisId, y->f94);
  thisId.fIdentifier = "95";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 94)),
                     &thisId, y->f95);
  thisId.fIdentifier = "96";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 95)),
                     &thisId, y->f96);
  thisId.fIdentifier = "97";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 96)),
                     &thisId, y->f97);
  thisId.fIdentifier = "98";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 97)),
                     &thisId, y->f98);
  thisId.fIdentifier = "99";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 98)),
                     &thisId, y->f99);
  thisId.fIdentifier = "100";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 99)),
                     &thisId, y->f100);
  thisId.fIdentifier = "101";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 100)),
                     &thisId, y->f101);
  thisId.fIdentifier = "102";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 101)),
                     &thisId, y->f102);
  thisId.fIdentifier = "103";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 102)),
                     &thisId, y->f103);
  thisId.fIdentifier = "104";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 103)),
                     &thisId, y->f104);
  thisId.fIdentifier = "105";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 104)),
                     &thisId, y->f105);
  thisId.fIdentifier = "106";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 105)),
                     &thisId, y->f106);
  thisId.fIdentifier = "107";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 106)),
                     &thisId, y->f107);
  thisId.fIdentifier = "108";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 107)),
                     &thisId, y->f108);
  thisId.fIdentifier = "109";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 108)),
                     &thisId, y->f109);
  thisId.fIdentifier = "110";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 109)),
                     &thisId, y->f110);
  thisId.fIdentifier = "111";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 110)),
                     &thisId, y->f111);
  thisId.fIdentifier = "112";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 111)),
                     &thisId, y->f112);
  thisId.fIdentifier = "113";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 112)),
                     &thisId, y->f113);
  thisId.fIdentifier = "114";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 113)),
                     &thisId, y->f114);
  thisId.fIdentifier = "115";
  v_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 114)),
                     &thisId, y->f115);
  thisId.fIdentifier = "116";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 115)),
                     &thisId, y->f116);
  thisId.fIdentifier = "117";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 116)),
                     &thisId, y->f117);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[8112]
 * Return Type  : void
 */
static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[8112])
{
  sc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[10816]
 * Return Type  : void
 */
static void qc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[10816])
{
  static const int32_T dims[2] = {104, 104};
  real_T(*r)[10816];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[10816])emlrtMxGetData(src);
  for (i = 0; i < 10816; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                char_T y[6]
 * Return Type  : void
 */
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[6])
{
  dc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[2028]
 * Return Type  : void
 */
static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[2028])
{
  tc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[2704]
 * Return Type  : void
 */
static void rc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[2704])
{
  static const int32_T dims[2] = {104, 26};
  real_T(*r)[2704];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[2704])emlrtMxGetData(src);
  for (i = 0; i < 2704; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                char_T y[7]
 * Return Type  : void
 */
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[7])
{
  ec_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *cstate
 *                const char_T *identifier
 *                struct8_T *y
 * Return Type  : void
 */
static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *cstate,
                                const char_T *identifier, struct8_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  tb_emlrt_marshallIn(sp, emlrtAlias(cstate), &thisId, y);
  emlrtDestroyArray(&cstate);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[8112]
 * Return Type  : void
 */
static void sc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[8112])
{
  static const int32_T dims[2] = {78, 104};
  real_T(*r)[8112];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[8112])emlrtMxGetData(src);
  for (i = 0; i < 8112; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                char_T y[8]
 * Return Type  : void
 */
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[8])
{
  fc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct8_T *y
 * Return Type  : void
 */
static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct8_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[2] = {"hyb", "ps"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 2,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "hyb";
  ub_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                     (const char_T *)"hyb")),
                      &thisId, y->hyb);
  thisId.fIdentifier = "ps";
  vb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                     (const char_T *)"ps")),
                      &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[2028]
 * Return Type  : void
 */
static void tc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[2028])
{
  static const int32_T dims[2] = {78, 26};
  real_T(*r)[2028];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[2028])emlrtMxGetData(src);
  for (i = 0; i < 2028; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                char_T y[9]
 * Return Type  : void
 */
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[9])
{
  gc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[104]
 * Return Type  : void
 */
static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[104])
{
  uc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[104]
 * Return Type  : void
 */
static void uc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[104])
{
  static const int32_T dims = 104;
  real_T(*r)[104];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  r = (real_T(*)[104])emlrtMxGetData(src);
  for (i = 0; i < 104; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                char_T y[10]
 * Return Type  : void
 */
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[10])
{
  hc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId)
{
  vc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : void
 */
static void vc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                cell_2 *y
 * Return Type  : void
 */
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_2 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T i;
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b = false;
  i = 26;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  thisId.fIdentifier = "1";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y->f1);
  thisId.fIdentifier = "2";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, y->f2);
  thisId.fIdentifier = "3";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                     &thisId, y->f3);
  thisId.fIdentifier = "4";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 3)),
                     &thisId, y->f4);
  thisId.fIdentifier = "5";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 4)),
                     &thisId, y->f5);
  thisId.fIdentifier = "6";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 5)),
                     &thisId, y->f6);
  thisId.fIdentifier = "7";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 6)),
                     &thisId, y->f7);
  thisId.fIdentifier = "8";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 7)),
                     &thisId, y->f8);
  thisId.fIdentifier = "9";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 8)),
                     &thisId, y->f9);
  thisId.fIdentifier = "10";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 9)),
                     &thisId, y->f10);
  thisId.fIdentifier = "11";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 10)),
                     &thisId, y->f11);
  thisId.fIdentifier = "12";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 11)),
                     &thisId, y->f12);
  thisId.fIdentifier = "13";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 12)),
                     &thisId, y->f13);
  thisId.fIdentifier = "14";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 13)),
                     &thisId, y->f14);
  thisId.fIdentifier = "15";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 14)),
                     &thisId, y->f15);
  thisId.fIdentifier = "16";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 15)),
                     &thisId, y->f16);
  thisId.fIdentifier = "17";
  x_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 16)),
                     &thisId, y->f17);
  thisId.fIdentifier = "18";
  y_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 17)),
                     &thisId, y->f18);
  thisId.fIdentifier = "19";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 18)),
                     &thisId, y->f19);
  thisId.fIdentifier = "20";
  v_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 19)),
                     &thisId, y->f20);
  thisId.fIdentifier = "21";
  v_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 20)),
                     &thisId, y->f21);
  thisId.fIdentifier = "22";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 21)),
                     &thisId, y->f22);
  thisId.fIdentifier = "23";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 22)),
                     &thisId, y->f23);
  thisId.fIdentifier = "24";
  r_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 23)),
                     &thisId, y->f24);
  thisId.fIdentifier = "25";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 24)),
                     &thisId, y->f25);
  thisId.fIdentifier = "26";
  s_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 25)),
                     &thisId, y->f26);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                char_T y[14]
 * Return Type  : void
 */
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[14])
{
  ic_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[38]
 * Return Type  : void
 */
static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[38])
{
  static const int32_T dims = 38;
  real_T(*r)[38];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  r = (real_T(*)[38])emlrtMxGetData(src);
  for (i = 0; i < 38; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                char_T y[13]
 * Return Type  : void
 */
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[13])
{
  jc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[29]
 * Return Type  : void
 */
static void yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[29])
{
  static const int32_T dims = 29;
  real_T(*r)[29];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  r = (real_T(*)[29])emlrtMxGetData(src);
  for (i = 0; i < 29; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray * const prhs[6]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void hybctrl_step_IDS_api(const mxArray *const prhs[6], int32_T nlhs,
                          const mxArray *plhs[2])
{
  static struct2_T cpar;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  struct0_T magn;
  struct1_T pfa;
  struct8_T cstate;
  real_T(*Arefs)[26];
  real_T(*cout)[19];
  real_T t;
  st.tls = emlrtRootTLSGlobal;
  cout = (real_T(*)[19])mxMalloc(sizeof(real_T[19]));
  /* Marshall function inputs */
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "magn", &magn);
  f_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "pfa", &pfa);
  Arefs = k_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Arefs");
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "cpar", &cpar);
  sb_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "cstate", &cstate);
  /* Invoke the target function */
  hybctrl_step_IDS(t, &magn, &pfa, *Arefs, &cpar, &cstate, *cout);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*cout);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(&cstate);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void hybctrl_step_IDS_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  hybctrl_step_IDS_xil_terminate();
  hybctrl_step_IDS_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void hybctrl_step_IDS_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void hybctrl_step_IDS_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_hybctrl_step_IDS_api.c
 *
 * [EOF]
 */
