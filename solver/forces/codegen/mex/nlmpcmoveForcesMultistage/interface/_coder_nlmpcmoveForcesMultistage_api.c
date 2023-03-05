/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_nlmpcmoveForcesMultistage_api.c
 *
 * Code generation for function '_coder_nlmpcmoveForcesMultistage_api'
 *
 */

/* Include files */
#include "_coder_nlmpcmoveForcesMultistage_api.h"
#include "nlmpcmoveForcesMultistage.h"
#include "nlmpcmoveForcesMultistage_data.h"
#include "nlmpcmoveForcesMultistage_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static const mxArray *b_emlrt_marshallOut(const struct1_T *u);

static real_T (*c_emlrt_marshallIn(const mxArray *lastMV,
                                   const char_T *identifier))[2];

static const mxArray *c_emlrt_marshallOut(const struct2_T *u);

static real_T (*d_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static void e_emlrt_marshallIn(const mxArray *onlinedata,
                               const char_T *identifier, struct1_T *y);

static real_T (*emlrt_marshallIn(const mxArray *x,
                                 const char_T *identifier))[3];

static const mxArray *emlrt_marshallOut(const real_T u[2]);

static void f_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct1_T *y);

static void g_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[253]);

static void h_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[153]);

static void i_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static real_T (*j_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static real_T (*k_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static void l_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[253]);

static void m_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[153]);

static void n_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[3]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = j_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const struct1_T *u)
{
  static const int32_T i = 253;
  static const int32_T i1 = 153;
  static const int32_T i2 = 3;
  static const char_T *sv[3] = {"InitialGuess", "StageParameter",
                                "TerminalState"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 253; b_i++) {
    pData[b_i] = u->InitialGuess[b_i];
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"InitialGuess", b_y, 0);
  c_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i1, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 153; b_i++) {
    pData[b_i] = u->StageParameter[b_i];
  }
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"StageParameter", c_y, 1);
  d_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i2, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->TerminalState[0];
  pData[1] = u->TerminalState[1];
  pData[2] = u->TerminalState[2];
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"TerminalState", d_y, 2);
  return y;
}

static real_T (*c_emlrt_marshallIn(const mxArray *lastMV,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(emlrtAlias(lastMV), &thisId);
  emlrtDestroyArray(&lastMV);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const struct2_T *u)
{
  static const int32_T iv[2] = {51, 2};
  static const int32_T iv1[2] = {51, 3};
  static const int32_T i1 = 51;
  static const char_T *sv[10] = {"MVopt",
                                 "Xopt",
                                 "Topt",
                                 "ExitFlag",
                                 "Iterations",
                                 "Cost",
                                 "EqualityResidual",
                                 "InequalityResidual",
                                 "SolveTime",
                                 "FcnEvalTime"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 10, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 2; b_i++) {
    for (c_i = 0; c_i < 51; c_i++) {
      pData[i + c_i] = u->MVopt[c_i + 51 * b_i];
    }
    i += 51;
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"MVopt", b_y, 0);
  c_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 3; b_i++) {
    for (c_i = 0; c_i < 51; c_i++) {
      pData[i + c_i] = u->Xopt[c_i + 51 * b_i];
    }
    i += 51;
  }
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Xopt", c_y, 1);
  d_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i1, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 51; b_i++) {
    pData[b_i] = u->Topt[b_i];
  }
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Topt", d_y, 2);
  e_y = NULL;
  m = emlrtCreateDoubleScalar(u->ExitFlag);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ExitFlag", e_y, 3);
  f_y = NULL;
  m = emlrtCreateDoubleScalar(u->Iterations);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Iterations", f_y, 4);
  g_y = NULL;
  m = emlrtCreateDoubleScalar(u->Cost);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Cost", g_y, 5);
  h_y = NULL;
  m = emlrtCreateDoubleScalar(u->EqualityResidual);
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"EqualityResidual", h_y, 6);
  i_y = NULL;
  m = emlrtCreateDoubleScalar(u->InequalityResidual);
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"InequalityResidual", i_y, 7);
  j_y = NULL;
  m = emlrtCreateDoubleScalar(u->SolveTime);
  emlrtAssign(&j_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"SolveTime", j_y, 8);
  k_y = NULL;
  m = emlrtCreateDoubleScalar(u->FcnEvalTime);
  emlrtAssign(&k_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"FcnEvalTime", k_y, 9);
  return y;
}

static real_T (*d_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = k_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const mxArray *onlinedata,
                               const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(emlrtAlias(onlinedata), &thisId, y);
  emlrtDestroyArray(&onlinedata);
}

static real_T (*emlrt_marshallIn(const mxArray *x, const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(emlrtAlias(x), &thisId);
  emlrtDestroyArray(&x);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[2])
{
  static const int32_T i = 0;
  static const int32_T i1 = 2;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = {"InitialGuess", "StageParameter",
                                        "TerminalState"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 3,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "InitialGuess";
  g_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
                                     (const char_T *)"InitialGuess")),
      &thisId, y->InitialGuess);
  thisId.fIdentifier = "StageParameter";
  h_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
                                     (const char_T *)"StageParameter")),
      &thisId, y->StageParameter);
  thisId.fIdentifier = "TerminalState";
  i_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
                                     (const char_T *)"TerminalState")),
      &thisId, y->TerminalState);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[253])
{
  l_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[153])
{
  m_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3])
{
  n_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*j_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims = 3;
  real_T(*ret)[3];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 1U, (void *)&dims);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*k_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims = 2;
  real_T(*ret)[2];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 1U, (void *)&dims);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void l_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[253])
{
  static const int32_T dims = 253;
  real_T(*r)[253];
  int32_T i;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 1U, (void *)&dims);
  r = (real_T(*)[253])emlrtMxGetData(src);
  for (i = 0; i < 253; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[153])
{
  static const int32_T dims = 153;
  real_T(*r)[153];
  int32_T i;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 1U, (void *)&dims);
  r = (real_T(*)[153])emlrtMxGetData(src);
  for (i = 0; i < 153; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims = 3;
  real_T(*r)[3];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 1U, (void *)&dims);
  r = (real_T(*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

void nlmpcmoveForcesMultistage_api(const mxArray *const prhs[3], int32_T nlhs,
                                   const mxArray *plhs[3])
{
  struct1_T onlinedata;
  struct2_T info;
  real_T(*x)[3];
  real_T(*lastMV)[2];
  real_T(*mv)[2];
  mv = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  /* Marshall function inputs */
  x = emlrt_marshallIn(emlrtAlias(prhs[0]), "x");
  lastMV = c_emlrt_marshallIn(emlrtAlias(prhs[1]), "lastMV");
  e_emlrt_marshallIn(emlrtAliasP(prhs[2]), "onlinedata", &onlinedata);
  /* Invoke the target function */
  nlmpcmoveForcesMultistage(*x, *lastMV, &onlinedata, *mv, &info);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*mv);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(&onlinedata);
  }
  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(&info);
  }
}

/* End of code generation (_coder_nlmpcmoveForcesMultistage_api.c) */
