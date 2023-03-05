/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nlmpcmoveForcesMultistage_initialize.c
 *
 * Code generation for function 'nlmpcmoveForcesMultistage_initialize'
 *
 */

/* Include files */
#include "nlmpcmoveForcesMultistage_initialize.h"
#include "_coder_nlmpcmoveForcesMultistage_mex.h"
#include "nlmpcmoveForcesMultistage_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void nlmpcmoveForcesMultistage_initialize(void)
{
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, NULL);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (nlmpcmoveForcesMultistage_initialize.c) */
