/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_nlmpcmoveForcesMultistage_mex.c
 *
 * Code generation for function '_coder_nlmpcmoveForcesMultistage_mex'
 *
 */

/* Include files */
#include "_coder_nlmpcmoveForcesMultistage_mex.h"
#include "_coder_nlmpcmoveForcesMultistage_api.h"
#include "nlmpcmoveForcesMultistage_data.h"
#include "nlmpcmoveForcesMultistage_initialize.h"
#include "nlmpcmoveForcesMultistage_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&nlmpcmoveForcesMultistage_atexit);
  /* Module initialization. */
  nlmpcmoveForcesMultistage_initialize();
  /* Dispatch the entry-point. */
  unsafe_nlmpcmoveForcesMultistage_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  nlmpcmoveForcesMultistage_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

void unsafe_nlmpcmoveForcesMultistage_mexFunction(int32_T nlhs,
                                                  mxArray *plhs[3],
                                                  int32_T nrhs,
                                                  const mxArray *prhs[3])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  /* Check for proper number of arguments. */
  if (nrhs > 3) {
    emlrtErrMsgIdAndTxt(
        emlrtRootTLSGlobal, "EMLRT:runTime:TooManyInputsConstants", 6, 4, 25,
        "nlmpcmoveForcesMultistage", 4, 25, "nlmpcmoveForcesMultistage");
  }
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 3, 4, 25, "nlmpcmoveForcesMultistage");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 25,
                        "nlmpcmoveForcesMultistage");
  }
  /* Call the function. */
  nlmpcmoveForcesMultistage_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_nlmpcmoveForcesMultistage_mex.c) */
