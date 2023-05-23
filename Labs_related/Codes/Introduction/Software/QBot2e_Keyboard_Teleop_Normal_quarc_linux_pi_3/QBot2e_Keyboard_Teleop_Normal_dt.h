/*
 * QBot2e_Keyboard_Teleop_Normal_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QBot2e_Keyboard_Teleop_Normal".
 *
 * Model version              : 1.247
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue May 23 12:02:36 2023
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
  sizeof(t_channel),
  sizeof(t_extmode_svr_connected_handle),
  sizeof(qthread_section_t),
  sizeof(t_keyboard_state),
  sizeof(t_jpeg_compress),
  sizeof(t_video3d),
  sizeof(t_video3d_stream),
  sizeof(t_int64),
  sizeof(t_uint64),
  sizeof(uint16_T),
  sizeof(uint32_T),
  sizeof(uint32_T),
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
  "t_channel",
  "t_extmode_svr_connected_handle",
  "qthread_section_t",
  "t_keyboard_state",
  "t_jpeg_compress",
  "t_video3d",
  "t_video3d_stream",
  "t_int64",
  "t_uint64",
  "uint16_T",
  "uint32_T",
  "uint32_T",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_B.Video3DCapture1_o2), 22, 0, 2 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_B.HILRead1_o1), 0, 0, 26 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_B.Channel), 14, 0, 2 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_B.HostInitialize_o2), 6, 0, 1 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_B.Video3DCapture1_o1[0]), 5, 0,
    307200 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_B.HostInitialize_o1), 3, 0, 921601
  }
  ,

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.HostKeyboard_Lock), 16, 0, 1 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.HostKeyboard_KeyboardState), 17,
    0, 1 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.UnitDelay_DSTATE), 0, 0, 2014 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.HostInitialize_ConnectedHandle),
    15, 0, 1 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.ImageCompress_Compress), 18, 0,
    2 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.Video3DInitialize_Video3D), 19,
    0, 3 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.Video3DCapture1_Stream), 20, 0,
    2 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.HILInitialize_Card), 26, 0, 1 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.HILRead1_PWORK), 11, 0, 4 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.HILInitialize_DOStates[0]), 6, 0,
    18 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.HILInitialize_POSortedChans[0]),
    7, 0, 2 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.XYFigure_IWORK[0]), 10, 0, 4 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.SwitchCase_ActiveSubsystem), 2,
    0, 5 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.ImageCompress_ScanLine[0]), 3, 0,
    20480 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Norma_DW.HILInitialize_DOBits[0]), 8, 0,
    7 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  21U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_P.BiasRemoval_end_time), 0, 0, 11
  },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_P.XYFigure_update_rate), 6, 0, 1 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_P.HILRead1_analog_channels), 7, 0,
    11 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_P.Video3DInitialize_active), 8, 0,
    1 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_P.unity_Value), 0, 0, 84 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_P.HILInitialize_EIInitial), 6, 0,
    8 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_P.Gain7_Gain), 25, 0, 55 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_P.rawdepthtomillimeter_Gain), 23,
    0, 1 },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_P.HILInitialize_Active), 8, 0, 44
  },

  { (char_T *)(&QBot2e_Keyboard_Teleop_Normal_P.HostInitialize_URI), 3, 0, 6 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  10U,
  rtPTransitions
};

/* [EOF] QBot2e_Keyboard_Teleop_Normal_dt.h */
