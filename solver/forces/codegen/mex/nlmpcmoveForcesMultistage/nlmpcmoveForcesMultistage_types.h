/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nlmpcmoveForcesMultistage_types.h
 *
 * Code generation for function 'nlmpcmoveForcesMultistage'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T InitialGuess[253];
  real_T StageParameter[153];
  real_T TerminalState[3];
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  real_T MVopt[102];
  real_T Xopt[153];
  real_T Topt[51];
  real_T ExitFlag;
  real_T Iterations;
  real_T Cost;
  real_T EqualityResidual;
  real_T InequalityResidual;
  real_T SolveTime;
  real_T FcnEvalTime;
} struct2_T;
#endif /* typedef_struct2_T */

/* End of code generation (nlmpcmoveForcesMultistage_types.h) */
