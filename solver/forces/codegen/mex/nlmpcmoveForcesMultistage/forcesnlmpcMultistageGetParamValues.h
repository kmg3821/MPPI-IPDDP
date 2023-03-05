/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * forcesnlmpcMultistageGetParamValues.h
 *
 * Code generation for function 'forcesnlmpcMultistageGetParamValues'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void c_forcesnlmpcMultistageGetParam(
    const real_T onlinedata_InitialGuess[253],
    const real_T onlinedata_StageParameter[153],
    const real_T onlinedata_TerminalState[3], const real_T x[3],
    real_T params_xinit[3], real_T params_xfinal[3], real_T params_x0[253],
    real_T params_all_parameters[204], real_T params_lb[100],
    real_T params_ub[100]);

/* End of code generation (forcesnlmpcMultistageGetParamValues.h) */
