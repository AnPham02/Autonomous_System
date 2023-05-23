/*
 * QBot2e_Diff_Drive_Kinematics_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QBot2e_Diff_Drive_Kinematics".
 *
 * Model version              : 1.952
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue May 23 12:32:14 2023
 *
 * Target selection: quarc_linux_pi_3.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_B.HILRead1_o4), 0, 0, 16 },

  { (char_T *)
    (&QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinemati_i.vC), 0, 0,
    2 },

  { (char_T *)
    (&QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinematics.vC), 0, 0,
    2 }
  ,

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_DW.UnitDelay_DSTATE), 0, 0, 14 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_DW.HILRead1_PWORK), 11, 0, 6 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOStates[0]), 6, 0,
    16 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedChans[0]),
    7, 0, 2 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_DW.Integrator1_IWORK), 10, 0, 2 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_DW.SwitchCase_ActiveSubsystem), 2,
    0, 5 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[0]), 8, 0,
    5 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_P.BiasRemoval_end_time), 0, 0, 7 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_P.HILRead1_analog_channels), 7, 0,
    9 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_P.Disable_Value), 0, 0, 56 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIInitial), 6, 0, 5
  },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AIChannels[0]), 7,
    0, 50 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_P.HILInitialize_Active), 8, 0, 37 },

  { (char_T *)(&QBot2e_Diff_Drive_Kinematics_P.EnableSwitch_CurrentSetting), 3,
    0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] QBot2e_Diff_Drive_Kinematics_dt.h */
