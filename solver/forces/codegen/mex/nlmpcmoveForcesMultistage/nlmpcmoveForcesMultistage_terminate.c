/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nlmpcmoveForcesMultistage_terminate.c
 *
 * Code generation for function 'nlmpcmoveForcesMultistage_terminate'
 *
 */

/* Include files */
#include "nlmpcmoveForcesMultistage_terminate.h"
#include "_coder_nlmpcmoveForcesMultistage_mex.h"
#include "nlmpcmoveForcesMultistage_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void nlmpcmoveForcesMultistage_atexit(void)
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void nlmpcmoveForcesMultistage_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (nlmpcmoveForcesMultistage_terminate.c) */
