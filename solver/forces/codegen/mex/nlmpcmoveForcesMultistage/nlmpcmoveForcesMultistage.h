/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nlmpcmoveForcesMultistage.h
 *
 * Code generation for function 'nlmpcmoveForcesMultistage'
 *
 */

#pragma once

/* Include files */
#include "nlmpcmoveForcesMultistage_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void nlmpcmoveForcesMultistage(const real_T x[3], const real_T lastMV[2],
                               struct1_T *onlinedata, real_T mv[2],
                               struct2_T *info);

/* End of code generation (nlmpcmoveForcesMultistage.h) */
