/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nlmpcmoveForcesMultistage.c
 *
 * Code generation for function 'nlmpcmoveForcesMultistage'
 *
 */

/* Include files */
#include "nlmpcmoveForcesMultistage.h"
#include "forcesnlmpcMultistageGetParamValues.h"
#include "nlmpcmoveForcesMultistage_types.h"
#include "rt_nonfinite.h"
#include "myForcesNLPSolver.h"
#include "myForcesNLPSolver_casadi2forces.h"
#include <string.h>

/* Function Definitions */
void nlmpcmoveForcesMultistage(const real_T x[3], const real_T lastMV[2],
                               struct1_T *onlinedata, real_T mv[2],
                               struct2_T *info)
{
  myForcesNLPSolver_info infoForces;
  myForcesNLPSolver_output output;
  myForcesNLPSolver_params params;
  real_T d;
  int32_T b_i;
  int32_T exitflag;
  int32_T i;
  /*  C interface is defined in the header file */
  /*  define solver input information (params, file and casadi) */
  c_forcesnlmpcMultistageGetParam(
      onlinedata->InitialGuess, onlinedata->StageParameter,
      onlinedata->TerminalState, x, params.xinit, params.xfinal, params.x0,
      params.all_parameters, params.lb, params.ub);
  /*  need define extern void solvername_casadi2forces(haomin_float *x,
   * haomin_float *y, haomin_float *l, haomin_float *p, haomin_float *f,
   * haomin_float *nabla_f, haomin_float *c, haomin_float *nabla_c, haomin_float
   * *h, haomin_float *nabla_h, haomin_float *hess, solver_int32_default stage,
   * solver_int32_default iteration); */
  /*  define solver output information (output, exitflag, info) */
  memset(&output.MVopt[0], 0, 100U * sizeof(real_T));
  memset(&output.Xopt[0], 0, 153U * sizeof(real_T));
  memset(&output.z[0], 0, 253U * sizeof(real_T));
  infoForces.it = 0;
  infoForces.it2opt = 0;
  infoForces.res_eq = 0.0;
  infoForces.res_ineq = 0.0;
  infoForces.rsnorm = 0.0;
  infoForces.rcompnorm = 0.0;
  infoForces.pobj = 0.0;
  infoForces.mu = 0.0;
  infoForces.solvetime = 0.0;
  infoForces.fevalstime = 0.0;
  /*  generate code with solver DLL/LIB */
  exitflag = myForcesNLPSolver_solve(&params, &output, &infoForces, NULL,
                                     &myForcesNLPSolver_casadi2forces);
  if (exitflag <= 0) {
    mv[0] = lastMV[0];
    mv[1] = lastMV[1];
  } else {
    mv[0] = output.MVopt[0];
    mv[1] = output.MVopt[1];
  }
  memset(&onlinedata->InitialGuess[0], 0, 253U * sizeof(real_T));
  onlinedata->InitialGuess[0] = output.z[5];
  onlinedata->InitialGuess[5] = output.z[10];
  onlinedata->InitialGuess[10] = output.z[15];
  onlinedata->InitialGuess[15] = output.z[20];
  onlinedata->InitialGuess[20] = output.z[25];
  onlinedata->InitialGuess[25] = output.z[30];
  onlinedata->InitialGuess[30] = output.z[35];
  onlinedata->InitialGuess[35] = output.z[40];
  onlinedata->InitialGuess[40] = output.z[45];
  onlinedata->InitialGuess[45] = output.z[50];
  onlinedata->InitialGuess[50] = output.z[55];
  onlinedata->InitialGuess[55] = output.z[60];
  onlinedata->InitialGuess[60] = output.z[65];
  onlinedata->InitialGuess[65] = output.z[70];
  onlinedata->InitialGuess[70] = output.z[75];
  onlinedata->InitialGuess[75] = output.z[80];
  onlinedata->InitialGuess[80] = output.z[85];
  onlinedata->InitialGuess[85] = output.z[90];
  onlinedata->InitialGuess[90] = output.z[95];
  onlinedata->InitialGuess[95] = output.z[100];
  onlinedata->InitialGuess[100] = output.z[105];
  onlinedata->InitialGuess[105] = output.z[110];
  onlinedata->InitialGuess[110] = output.z[115];
  onlinedata->InitialGuess[115] = output.z[120];
  onlinedata->InitialGuess[120] = output.z[125];
  onlinedata->InitialGuess[125] = output.z[130];
  onlinedata->InitialGuess[130] = output.z[135];
  onlinedata->InitialGuess[135] = output.z[140];
  onlinedata->InitialGuess[140] = output.z[145];
  onlinedata->InitialGuess[145] = output.z[150];
  onlinedata->InitialGuess[150] = output.z[155];
  onlinedata->InitialGuess[155] = output.z[160];
  onlinedata->InitialGuess[160] = output.z[165];
  onlinedata->InitialGuess[165] = output.z[170];
  onlinedata->InitialGuess[170] = output.z[175];
  onlinedata->InitialGuess[175] = output.z[180];
  onlinedata->InitialGuess[180] = output.z[185];
  onlinedata->InitialGuess[185] = output.z[190];
  onlinedata->InitialGuess[190] = output.z[195];
  onlinedata->InitialGuess[195] = output.z[200];
  onlinedata->InitialGuess[200] = output.z[205];
  onlinedata->InitialGuess[205] = output.z[210];
  onlinedata->InitialGuess[210] = output.z[215];
  onlinedata->InitialGuess[215] = output.z[220];
  onlinedata->InitialGuess[220] = output.z[225];
  onlinedata->InitialGuess[225] = output.z[230];
  onlinedata->InitialGuess[230] = output.z[235];
  onlinedata->InitialGuess[235] = output.z[240];
  onlinedata->InitialGuess[240] = output.z[245];
  onlinedata->InitialGuess[245] = output.z[250];
  onlinedata->InitialGuess[250] = output.z[250];
  onlinedata->InitialGuess[1] = output.z[6];
  onlinedata->InitialGuess[6] = output.z[11];
  onlinedata->InitialGuess[11] = output.z[16];
  onlinedata->InitialGuess[16] = output.z[21];
  onlinedata->InitialGuess[21] = output.z[26];
  onlinedata->InitialGuess[26] = output.z[31];
  onlinedata->InitialGuess[31] = output.z[36];
  onlinedata->InitialGuess[36] = output.z[41];
  onlinedata->InitialGuess[41] = output.z[46];
  onlinedata->InitialGuess[46] = output.z[51];
  onlinedata->InitialGuess[51] = output.z[56];
  onlinedata->InitialGuess[56] = output.z[61];
  onlinedata->InitialGuess[61] = output.z[66];
  onlinedata->InitialGuess[66] = output.z[71];
  onlinedata->InitialGuess[71] = output.z[76];
  onlinedata->InitialGuess[76] = output.z[81];
  onlinedata->InitialGuess[81] = output.z[86];
  onlinedata->InitialGuess[86] = output.z[91];
  onlinedata->InitialGuess[91] = output.z[96];
  onlinedata->InitialGuess[96] = output.z[101];
  onlinedata->InitialGuess[101] = output.z[106];
  onlinedata->InitialGuess[106] = output.z[111];
  onlinedata->InitialGuess[111] = output.z[116];
  onlinedata->InitialGuess[116] = output.z[121];
  onlinedata->InitialGuess[121] = output.z[126];
  onlinedata->InitialGuess[126] = output.z[131];
  onlinedata->InitialGuess[131] = output.z[136];
  onlinedata->InitialGuess[136] = output.z[141];
  onlinedata->InitialGuess[141] = output.z[146];
  onlinedata->InitialGuess[146] = output.z[151];
  onlinedata->InitialGuess[151] = output.z[156];
  onlinedata->InitialGuess[156] = output.z[161];
  onlinedata->InitialGuess[161] = output.z[166];
  onlinedata->InitialGuess[166] = output.z[171];
  onlinedata->InitialGuess[171] = output.z[176];
  onlinedata->InitialGuess[176] = output.z[181];
  onlinedata->InitialGuess[181] = output.z[186];
  onlinedata->InitialGuess[186] = output.z[191];
  onlinedata->InitialGuess[191] = output.z[196];
  onlinedata->InitialGuess[196] = output.z[201];
  onlinedata->InitialGuess[201] = output.z[206];
  onlinedata->InitialGuess[206] = output.z[211];
  onlinedata->InitialGuess[211] = output.z[216];
  onlinedata->InitialGuess[216] = output.z[221];
  onlinedata->InitialGuess[221] = output.z[226];
  onlinedata->InitialGuess[226] = output.z[231];
  onlinedata->InitialGuess[231] = output.z[236];
  onlinedata->InitialGuess[236] = output.z[241];
  onlinedata->InitialGuess[241] = output.z[246];
  onlinedata->InitialGuess[246] = output.z[251];
  onlinedata->InitialGuess[251] = output.z[251];
  onlinedata->InitialGuess[2] = output.z[7];
  onlinedata->InitialGuess[7] = output.z[12];
  onlinedata->InitialGuess[12] = output.z[17];
  onlinedata->InitialGuess[17] = output.z[22];
  onlinedata->InitialGuess[22] = output.z[27];
  onlinedata->InitialGuess[27] = output.z[32];
  onlinedata->InitialGuess[32] = output.z[37];
  onlinedata->InitialGuess[37] = output.z[42];
  onlinedata->InitialGuess[42] = output.z[47];
  onlinedata->InitialGuess[47] = output.z[52];
  onlinedata->InitialGuess[52] = output.z[57];
  onlinedata->InitialGuess[57] = output.z[62];
  onlinedata->InitialGuess[62] = output.z[67];
  onlinedata->InitialGuess[67] = output.z[72];
  onlinedata->InitialGuess[72] = output.z[77];
  onlinedata->InitialGuess[77] = output.z[82];
  onlinedata->InitialGuess[82] = output.z[87];
  onlinedata->InitialGuess[87] = output.z[92];
  onlinedata->InitialGuess[92] = output.z[97];
  onlinedata->InitialGuess[97] = output.z[102];
  onlinedata->InitialGuess[102] = output.z[107];
  onlinedata->InitialGuess[107] = output.z[112];
  onlinedata->InitialGuess[112] = output.z[117];
  onlinedata->InitialGuess[117] = output.z[122];
  onlinedata->InitialGuess[122] = output.z[127];
  onlinedata->InitialGuess[127] = output.z[132];
  onlinedata->InitialGuess[132] = output.z[137];
  onlinedata->InitialGuess[137] = output.z[142];
  onlinedata->InitialGuess[142] = output.z[147];
  onlinedata->InitialGuess[147] = output.z[152];
  onlinedata->InitialGuess[152] = output.z[157];
  onlinedata->InitialGuess[157] = output.z[162];
  onlinedata->InitialGuess[162] = output.z[167];
  onlinedata->InitialGuess[167] = output.z[172];
  onlinedata->InitialGuess[172] = output.z[177];
  onlinedata->InitialGuess[177] = output.z[182];
  onlinedata->InitialGuess[182] = output.z[187];
  onlinedata->InitialGuess[187] = output.z[192];
  onlinedata->InitialGuess[192] = output.z[197];
  onlinedata->InitialGuess[197] = output.z[202];
  onlinedata->InitialGuess[202] = output.z[207];
  onlinedata->InitialGuess[207] = output.z[212];
  onlinedata->InitialGuess[212] = output.z[217];
  onlinedata->InitialGuess[217] = output.z[222];
  onlinedata->InitialGuess[222] = output.z[227];
  onlinedata->InitialGuess[227] = output.z[232];
  onlinedata->InitialGuess[232] = output.z[237];
  onlinedata->InitialGuess[237] = output.z[242];
  onlinedata->InitialGuess[242] = output.z[247];
  onlinedata->InitialGuess[247] = output.z[252];
  onlinedata->InitialGuess[252] = output.z[252];
  for (i = 0; i < 2; i++) {
    onlinedata->InitialGuess[i + 3] = output.z[i + 8];
    onlinedata->InitialGuess[i + 8] = output.z[i + 13];
    onlinedata->InitialGuess[i + 13] = output.z[i + 18];
    onlinedata->InitialGuess[i + 18] = output.z[i + 23];
    onlinedata->InitialGuess[i + 23] = output.z[i + 28];
    onlinedata->InitialGuess[i + 28] = output.z[i + 33];
    onlinedata->InitialGuess[i + 33] = output.z[i + 38];
    onlinedata->InitialGuess[i + 38] = output.z[i + 43];
    onlinedata->InitialGuess[i + 43] = output.z[i + 48];
    onlinedata->InitialGuess[i + 48] = output.z[i + 53];
    onlinedata->InitialGuess[i + 53] = output.z[i + 58];
    onlinedata->InitialGuess[i + 58] = output.z[i + 63];
    onlinedata->InitialGuess[i + 63] = output.z[i + 68];
    onlinedata->InitialGuess[i + 68] = output.z[i + 73];
    onlinedata->InitialGuess[i + 73] = output.z[i + 78];
    onlinedata->InitialGuess[i + 78] = output.z[i + 83];
    onlinedata->InitialGuess[i + 83] = output.z[i + 88];
    onlinedata->InitialGuess[i + 88] = output.z[i + 93];
    onlinedata->InitialGuess[i + 93] = output.z[i + 98];
    onlinedata->InitialGuess[i + 98] = output.z[i + 103];
    onlinedata->InitialGuess[i + 103] = output.z[i + 108];
    onlinedata->InitialGuess[i + 108] = output.z[i + 113];
    onlinedata->InitialGuess[i + 113] = output.z[i + 118];
    onlinedata->InitialGuess[i + 118] = output.z[i + 123];
    onlinedata->InitialGuess[i + 123] = output.z[i + 128];
    onlinedata->InitialGuess[i + 128] = output.z[i + 133];
    onlinedata->InitialGuess[i + 133] = output.z[i + 138];
    onlinedata->InitialGuess[i + 138] = output.z[i + 143];
    onlinedata->InitialGuess[i + 143] = output.z[i + 148];
    onlinedata->InitialGuess[i + 148] = output.z[i + 153];
    onlinedata->InitialGuess[i + 153] = output.z[i + 158];
    onlinedata->InitialGuess[i + 158] = output.z[i + 163];
    onlinedata->InitialGuess[i + 163] = output.z[i + 168];
    onlinedata->InitialGuess[i + 168] = output.z[i + 173];
    onlinedata->InitialGuess[i + 173] = output.z[i + 178];
    onlinedata->InitialGuess[i + 178] = output.z[i + 183];
    onlinedata->InitialGuess[i + 183] = output.z[i + 188];
    onlinedata->InitialGuess[i + 188] = output.z[i + 193];
    onlinedata->InitialGuess[i + 193] = output.z[i + 198];
    onlinedata->InitialGuess[i + 198] = output.z[i + 203];
    onlinedata->InitialGuess[i + 203] = output.z[i + 208];
    onlinedata->InitialGuess[i + 208] = output.z[i + 213];
    onlinedata->InitialGuess[i + 213] = output.z[i + 218];
    onlinedata->InitialGuess[i + 218] = output.z[i + 223];
    onlinedata->InitialGuess[i + 223] = output.z[i + 228];
    onlinedata->InitialGuess[i + 228] = output.z[i + 233];
    onlinedata->InitialGuess[i + 233] = output.z[i + 238];
    onlinedata->InitialGuess[i + 238] = output.z[i + 243];
    d = output.z[i + 248];
    onlinedata->InitialGuess[i + 243] = d;
    onlinedata->InitialGuess[i + 248] = d;
    for (b_i = 0; b_i < 50; b_i++) {
      info->MVopt[b_i + 51 * i] = output.MVopt[i + (b_i << 1)];
    }
    info->MVopt[51 * i + 50] = 0.0;
  }
  for (b_i = 0; b_i < 3; b_i++) {
    for (i = 0; i < 51; i++) {
      info->Xopt[i + 51 * b_i] = output.Xopt[b_i + 3 * i];
    }
  }
  for (b_i = 0; b_i < 51; b_i++) {
    info->Topt[b_i] = 0.1 * (real_T)b_i;
  }
  info->ExitFlag = exitflag;
  info->Iterations = infoForces.it;
  info->Cost = infoForces.pobj;
  info->EqualityResidual = infoForces.res_eq;
  info->InequalityResidual = infoForces.res_ineq;
  info->SolveTime = infoForces.solvetime;
  info->FcnEvalTime = infoForces.fevalstime;
}

/* End of code generation (nlmpcmoveForcesMultistage.c) */
