/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * forcesnlmpcMultistageGetParamValues.c
 *
 * Code generation for function 'forcesnlmpcMultistageGetParamValues'
 *
 */

/* Include files */
#include "forcesnlmpcMultistageGetParamValues.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void c_forcesnlmpcMultistageGetParam(
    const real_T onlinedata_InitialGuess[253],
    const real_T onlinedata_StageParameter[153],
    const real_T onlinedata_TerminalState[3], const real_T x[3],
    real_T params_xinit[3], real_T params_xfinal[3], real_T params_x0[253],
    real_T params_all_parameters[204], real_T params_lb[100],
    real_T params_ub[100])
{
  static const int8_T b_x[51] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0};
  real_T stage_parameters_offset[52];
  real_T varargin_2[51];
  int32_T k;
  params_xinit[0] = x[0];
  params_xfinal[0] = onlinedata_TerminalState[0];
  params_xinit[1] = x[1];
  params_xfinal[1] = onlinedata_TerminalState[1];
  params_xinit[2] = x[2];
  params_xfinal[2] = onlinedata_TerminalState[2];
  memcpy(&params_x0[0], &onlinedata_InitialGuess[0], 253U * sizeof(real_T));
  for (k = 0; k < 51; k++) {
    varargin_2[k] = 3.0;
  }
  for (k = 0; k < 50; k++) {
    varargin_2[k + 1] += varargin_2[k];
  }
  stage_parameters_offset[0] = 0.0;
  memcpy(&stage_parameters_offset[1], &varargin_2[0], 51U * sizeof(real_T));
  params_all_parameters[0] = 1.0;
  params_all_parameters[1] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[0] + 1.0) -
                                1];
  params_all_parameters[2] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[0] + 2.0) -
                                1];
  params_all_parameters[3] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[0] + 3.0) -
                                1];
  params_all_parameters[4] = 2.0;
  params_all_parameters[5] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[1] + 1.0) -
                                1];
  params_all_parameters[6] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[1] + 2.0) -
                                1];
  params_all_parameters[7] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[1] + 3.0) -
                                1];
  params_all_parameters[8] = 3.0;
  params_all_parameters[9] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[2] + 1.0) -
                                1];
  params_all_parameters[10] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[2] + 2.0) -
                                1];
  params_all_parameters[11] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[2] + 3.0) -
                                1];
  params_all_parameters[12] = 4.0;
  params_all_parameters[13] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[3] + 1.0) -
                                1];
  params_all_parameters[14] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[3] + 2.0) -
                                1];
  params_all_parameters[15] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[3] + 3.0) -
                                1];
  params_all_parameters[16] = 5.0;
  params_all_parameters[17] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[4] + 1.0) -
                                1];
  params_all_parameters[18] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[4] + 2.0) -
                                1];
  params_all_parameters[19] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[4] + 3.0) -
                                1];
  params_all_parameters[20] = 6.0;
  params_all_parameters[21] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[5] + 1.0) -
                                1];
  params_all_parameters[22] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[5] + 2.0) -
                                1];
  params_all_parameters[23] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[5] + 3.0) -
                                1];
  params_all_parameters[24] = 7.0;
  params_all_parameters[25] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[6] + 1.0) -
                                1];
  params_all_parameters[26] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[6] + 2.0) -
                                1];
  params_all_parameters[27] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[6] + 3.0) -
                                1];
  params_all_parameters[28] = 8.0;
  params_all_parameters[29] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[7] + 1.0) -
                                1];
  params_all_parameters[30] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[7] + 2.0) -
                                1];
  params_all_parameters[31] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[7] + 3.0) -
                                1];
  params_all_parameters[32] = 9.0;
  params_all_parameters[33] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[8] + 1.0) -
                                1];
  params_all_parameters[34] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[8] + 2.0) -
                                1];
  params_all_parameters[35] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[8] + 3.0) -
                                1];
  params_all_parameters[36] = 10.0;
  params_all_parameters[37] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[9] + 1.0) -
                                1];
  params_all_parameters[38] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[9] + 2.0) -
                                1];
  params_all_parameters[39] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[9] + 3.0) -
                                1];
  params_all_parameters[40] = 11.0;
  params_all_parameters[41] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[10] + 1.0) -
                                1];
  params_all_parameters[42] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[10] + 2.0) -
                                1];
  params_all_parameters[43] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[10] + 3.0) -
                                1];
  params_all_parameters[44] = 12.0;
  params_all_parameters[45] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[11] + 1.0) -
                                1];
  params_all_parameters[46] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[11] + 2.0) -
                                1];
  params_all_parameters[47] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[11] + 3.0) -
                                1];
  params_all_parameters[48] = 13.0;
  params_all_parameters[49] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[12] + 1.0) -
                                1];
  params_all_parameters[50] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[12] + 2.0) -
                                1];
  params_all_parameters[51] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[12] + 3.0) -
                                1];
  params_all_parameters[52] = 14.0;
  params_all_parameters[53] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[13] + 1.0) -
                                1];
  params_all_parameters[54] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[13] + 2.0) -
                                1];
  params_all_parameters[55] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[13] + 3.0) -
                                1];
  params_all_parameters[56] = 15.0;
  params_all_parameters[57] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[14] + 1.0) -
                                1];
  params_all_parameters[58] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[14] + 2.0) -
                                1];
  params_all_parameters[59] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[14] + 3.0) -
                                1];
  params_all_parameters[60] = 16.0;
  params_all_parameters[61] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[15] + 1.0) -
                                1];
  params_all_parameters[62] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[15] + 2.0) -
                                1];
  params_all_parameters[63] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[15] + 3.0) -
                                1];
  params_all_parameters[64] = 17.0;
  params_all_parameters[65] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[16] + 1.0) -
                                1];
  params_all_parameters[66] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[16] + 2.0) -
                                1];
  params_all_parameters[67] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[16] + 3.0) -
                                1];
  params_all_parameters[68] = 18.0;
  params_all_parameters[69] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[17] + 1.0) -
                                1];
  params_all_parameters[70] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[17] + 2.0) -
                                1];
  params_all_parameters[71] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[17] + 3.0) -
                                1];
  params_all_parameters[72] = 19.0;
  params_all_parameters[73] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[18] + 1.0) -
                                1];
  params_all_parameters[74] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[18] + 2.0) -
                                1];
  params_all_parameters[75] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[18] + 3.0) -
                                1];
  params_all_parameters[76] = 20.0;
  params_all_parameters[77] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[19] + 1.0) -
                                1];
  params_all_parameters[78] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[19] + 2.0) -
                                1];
  params_all_parameters[79] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[19] + 3.0) -
                                1];
  params_all_parameters[80] = 21.0;
  params_all_parameters[81] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[20] + 1.0) -
                                1];
  params_all_parameters[82] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[20] + 2.0) -
                                1];
  params_all_parameters[83] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[20] + 3.0) -
                                1];
  params_all_parameters[84] = 22.0;
  params_all_parameters[85] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[21] + 1.0) -
                                1];
  params_all_parameters[86] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[21] + 2.0) -
                                1];
  params_all_parameters[87] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[21] + 3.0) -
                                1];
  params_all_parameters[88] = 23.0;
  params_all_parameters[89] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[22] + 1.0) -
                                1];
  params_all_parameters[90] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[22] + 2.0) -
                                1];
  params_all_parameters[91] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[22] + 3.0) -
                                1];
  params_all_parameters[92] = 24.0;
  params_all_parameters[93] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[23] + 1.0) -
                                1];
  params_all_parameters[94] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[23] + 2.0) -
                                1];
  params_all_parameters[95] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[23] + 3.0) -
                                1];
  params_all_parameters[96] = 25.0;
  params_all_parameters[97] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[24] + 1.0) -
                                1];
  params_all_parameters[98] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[24] + 2.0) -
                                1];
  params_all_parameters[99] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[24] + 3.0) -
                                1];
  params_all_parameters[100] = 26.0;
  params_all_parameters[101] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[25] + 1.0) -
                                1];
  params_all_parameters[102] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[25] + 2.0) -
                                1];
  params_all_parameters[103] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[25] + 3.0) -
                                1];
  params_all_parameters[104] = 27.0;
  params_all_parameters[105] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[26] + 1.0) -
                                1];
  params_all_parameters[106] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[26] + 2.0) -
                                1];
  params_all_parameters[107] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[26] + 3.0) -
                                1];
  params_all_parameters[108] = 28.0;
  params_all_parameters[109] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[27] + 1.0) -
                                1];
  params_all_parameters[110] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[27] + 2.0) -
                                1];
  params_all_parameters[111] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[27] + 3.0) -
                                1];
  params_all_parameters[112] = 29.0;
  params_all_parameters[113] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[28] + 1.0) -
                                1];
  params_all_parameters[114] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[28] + 2.0) -
                                1];
  params_all_parameters[115] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[28] + 3.0) -
                                1];
  params_all_parameters[116] = 30.0;
  params_all_parameters[117] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[29] + 1.0) -
                                1];
  params_all_parameters[118] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[29] + 2.0) -
                                1];
  params_all_parameters[119] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[29] + 3.0) -
                                1];
  params_all_parameters[120] = 31.0;
  params_all_parameters[121] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[30] + 1.0) -
                                1];
  params_all_parameters[122] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[30] + 2.0) -
                                1];
  params_all_parameters[123] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[30] + 3.0) -
                                1];
  params_all_parameters[124] = 32.0;
  params_all_parameters[125] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[31] + 1.0) -
                                1];
  params_all_parameters[126] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[31] + 2.0) -
                                1];
  params_all_parameters[127] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[31] + 3.0) -
                                1];
  params_all_parameters[128] = 33.0;
  params_all_parameters[129] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[32] + 1.0) -
                                1];
  params_all_parameters[130] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[32] + 2.0) -
                                1];
  params_all_parameters[131] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[32] + 3.0) -
                                1];
  params_all_parameters[132] = 34.0;
  params_all_parameters[133] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[33] + 1.0) -
                                1];
  params_all_parameters[134] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[33] + 2.0) -
                                1];
  params_all_parameters[135] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[33] + 3.0) -
                                1];
  params_all_parameters[136] = 35.0;
  params_all_parameters[137] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[34] + 1.0) -
                                1];
  params_all_parameters[138] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[34] + 2.0) -
                                1];
  params_all_parameters[139] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[34] + 3.0) -
                                1];
  params_all_parameters[140] = 36.0;
  params_all_parameters[141] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[35] + 1.0) -
                                1];
  params_all_parameters[142] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[35] + 2.0) -
                                1];
  params_all_parameters[143] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[35] + 3.0) -
                                1];
  params_all_parameters[144] = 37.0;
  params_all_parameters[145] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[36] + 1.0) -
                                1];
  params_all_parameters[146] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[36] + 2.0) -
                                1];
  params_all_parameters[147] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[36] + 3.0) -
                                1];
  params_all_parameters[148] = 38.0;
  params_all_parameters[149] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[37] + 1.0) -
                                1];
  params_all_parameters[150] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[37] + 2.0) -
                                1];
  params_all_parameters[151] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[37] + 3.0) -
                                1];
  params_all_parameters[152] = 39.0;
  params_all_parameters[153] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[38] + 1.0) -
                                1];
  params_all_parameters[154] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[38] + 2.0) -
                                1];
  params_all_parameters[155] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[38] + 3.0) -
                                1];
  params_all_parameters[156] = 40.0;
  params_all_parameters[157] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[39] + 1.0) -
                                1];
  params_all_parameters[158] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[39] + 2.0) -
                                1];
  params_all_parameters[159] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[39] + 3.0) -
                                1];
  params_all_parameters[160] = 41.0;
  params_all_parameters[161] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[40] + 1.0) -
                                1];
  params_all_parameters[162] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[40] + 2.0) -
                                1];
  params_all_parameters[163] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[40] + 3.0) -
                                1];
  params_all_parameters[164] = 42.0;
  params_all_parameters[165] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[41] + 1.0) -
                                1];
  params_all_parameters[166] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[41] + 2.0) -
                                1];
  params_all_parameters[167] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[41] + 3.0) -
                                1];
  params_all_parameters[168] = 43.0;
  params_all_parameters[169] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[42] + 1.0) -
                                1];
  params_all_parameters[170] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[42] + 2.0) -
                                1];
  params_all_parameters[171] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[42] + 3.0) -
                                1];
  params_all_parameters[172] = 44.0;
  params_all_parameters[173] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[43] + 1.0) -
                                1];
  params_all_parameters[174] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[43] + 2.0) -
                                1];
  params_all_parameters[175] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[43] + 3.0) -
                                1];
  params_all_parameters[176] = 45.0;
  params_all_parameters[177] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[44] + 1.0) -
                                1];
  params_all_parameters[178] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[44] + 2.0) -
                                1];
  params_all_parameters[179] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[44] + 3.0) -
                                1];
  params_all_parameters[180] = 46.0;
  params_all_parameters[181] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[45] + 1.0) -
                                1];
  params_all_parameters[182] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[45] + 2.0) -
                                1];
  params_all_parameters[183] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[45] + 3.0) -
                                1];
  params_all_parameters[184] = 47.0;
  params_all_parameters[185] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[46] + 1.0) -
                                1];
  params_all_parameters[186] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[46] + 2.0) -
                                1];
  params_all_parameters[187] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[46] + 3.0) -
                                1];
  params_all_parameters[188] = 48.0;
  params_all_parameters[189] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[47] + 1.0) -
                                1];
  params_all_parameters[190] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[47] + 2.0) -
                                1];
  params_all_parameters[191] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[47] + 3.0) -
                                1];
  params_all_parameters[192] = 49.0;
  params_all_parameters[193] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[48] + 1.0) -
                                1];
  params_all_parameters[194] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[48] + 2.0) -
                                1];
  params_all_parameters[195] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[48] + 3.0) -
                                1];
  params_all_parameters[196] = 50.0;
  params_all_parameters[197] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[49] + 1.0) -
                                1];
  params_all_parameters[198] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[49] + 2.0) -
                                1];
  params_all_parameters[199] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[49] + 3.0) -
                                1];
  params_all_parameters[200] = 51.0;
  params_all_parameters[201] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[50] + 1.0) -
                                1];
  params_all_parameters[202] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[50] + 2.0) -
                                1];
  params_all_parameters[203] =
      onlinedata_StageParameter[(int32_T)(stage_parameters_offset[50] + 3.0) -
                                1];
  memset(&params_lb[0], 0, 100U * sizeof(real_T));
  for (k = 0; k < 51; k++) {
    varargin_2[k] = b_x[k];
  }
  for (k = 0; k < 50; k++) {
    varargin_2[k + 1] += varargin_2[k];
  }
  stage_parameters_offset[0] = 0.0;
  memcpy(&stage_parameters_offset[1], &varargin_2[0], 51U * sizeof(real_T));
  params_lb[(int32_T)(stage_parameters_offset[0] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[0] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[1] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[1] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[2] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[2] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[3] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[3] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[4] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[4] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[5] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[5] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[6] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[6] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[7] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[7] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[8] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[8] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[9] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[9] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[10] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[10] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[11] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[11] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[12] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[12] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[13] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[13] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[14] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[14] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[15] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[15] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[16] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[16] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[17] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[17] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[18] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[18] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[19] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[19] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[20] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[20] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[21] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[21] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[22] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[22] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[23] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[23] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[24] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[24] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[25] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[25] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[26] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[26] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[27] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[27] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[28] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[28] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[29] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[29] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[30] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[30] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[31] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[31] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[32] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[32] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[33] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[33] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[34] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[34] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[35] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[35] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[36] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[36] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[37] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[37] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[38] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[38] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[39] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[39] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[40] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[40] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[41] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[41] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[42] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[42] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[43] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[43] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[44] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[44] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[45] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[45] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[46] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[46] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[47] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[47] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[48] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[48] + 2.0) - 1] = -1.2;
  params_lb[(int32_T)(stage_parameters_offset[49] + 1.0) - 1] = -0.0;
  params_lb[(int32_T)(stage_parameters_offset[49] + 2.0) - 1] = -1.2;
  memset(&params_ub[0], 0, 100U * sizeof(real_T));
  params_ub[(int32_T)(stage_parameters_offset[0] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[0] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[1] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[1] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[2] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[2] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[3] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[3] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[4] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[4] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[5] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[5] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[6] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[6] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[7] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[7] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[8] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[8] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[9] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[9] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[10] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[10] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[11] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[11] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[12] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[12] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[13] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[13] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[14] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[14] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[15] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[15] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[16] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[16] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[17] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[17] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[18] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[18] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[19] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[19] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[20] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[20] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[21] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[21] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[22] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[22] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[23] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[23] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[24] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[24] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[25] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[25] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[26] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[26] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[27] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[27] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[28] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[28] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[29] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[29] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[30] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[30] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[31] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[31] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[32] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[32] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[33] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[33] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[34] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[34] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[35] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[35] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[36] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[36] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[37] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[37] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[38] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[38] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[39] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[39] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[40] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[40] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[41] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[41] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[42] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[42] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[43] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[43] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[44] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[44] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[45] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[45] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[46] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[46] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[47] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[47] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[48] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[48] + 2.0) - 1] = 1.2;
  params_ub[(int32_T)(stage_parameters_offset[49] + 1.0) - 1] = 0.5;
  params_ub[(int32_T)(stage_parameters_offset[49] + 2.0) - 1] = 1.2;
}

/* End of code generation (forcesnlmpcMultistageGetParamValues.c) */
