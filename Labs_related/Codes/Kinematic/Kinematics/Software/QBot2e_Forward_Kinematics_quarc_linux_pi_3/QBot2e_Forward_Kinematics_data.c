/*
 * QBot2e_Forward_Kinematics_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QBot2e_Forward_Kinematics".
 *
 * Model version              : 1.957
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue May 23 12:44:53 2023
 *
 * Target selection: quarc_linux_pi_3.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "QBot2e_Forward_Kinematics.h"
#include "QBot2e_Forward_Kinematics_private.h"

/* Block parameters (default storage) */
P_QBot2e_Forward_Kinematics_T QBot2e_Forward_Kinematics_P = {
  /* Mask Parameter: BiasRemoval_end_time
   * Referenced by: '<S24>/Step: end_time'
   */
  4.0,

  /* Mask Parameter: SecondOrderLowPassFilter2_input
   * Referenced by: '<S10>/wn'
   */
  10.0,

  /* Mask Parameter: SecondOrderLowPassFilter2_inp_b
   * Referenced by: '<S8>/wn'
   */
  10.0,

  /* Mask Parameter: SecondOrderLowPassFilter1_input
   * Referenced by: '<S17>/wn'
   */
  60.0,

  /* Mask Parameter: SecondOrderLowPassFilter2_inp_p
   * Referenced by: '<S8>/zt'
   */
  1.0,

  /* Mask Parameter: SecondOrderLowPassFilter2_inp_c
   * Referenced by: '<S10>/zt'
   */
  1.0,

  /* Mask Parameter: SecondOrderLowPassFilter1_inp_p
   * Referenced by: '<S17>/zt'
   */
  1.0,

  /* Mask Parameter: BiasRemoval_start_time
   * Referenced by: '<S24>/Step: start_time'
   */
  3.0,

  /* Mask Parameter: BiasRemoval_switch_id
   * Referenced by: '<S24>/Constant'
   */
  1.0,

  /* Mask Parameter: HILRead1_analog_channels
   * Referenced by: '<S25>/HIL Read1'
   */
  0U,

  /* Mask Parameter: HILRead1_digital_channels
   * Referenced by: '<S25>/HIL Read1'
   */
  { 28U, 29U, 30U },

  /* Mask Parameter: HILRead1_encoder_channels
   * Referenced by: '<S25>/HIL Read1'
   */
  { 0U, 1U },

  /* Mask Parameter: HILRead1_other_channels
   * Referenced by: '<S25>/HIL Read1'
   */
  1002U,

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S25>/HIL Write'
   */
  { 2000U, 2001U },

  /* Expression: 0
   * Referenced by: '<Root>/Disable'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Enable'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S30>/unity'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S30>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S26>/Sum( k=1,n-1, x(k) )'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S27>/zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S27>/Constant'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S28>/Vbiased'
   */
  0.0,

  /* Expression: [0]
   * Referenced by: '<S29>/Vunbiased'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S24>/Step: start_time'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S24>/Step: start_time'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S24>/Step: end_time'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S24>/Step: end_time'
   */
  1.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 0.0, 7.0 },

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 16.5, 3.3, 3.3, 3.3, 3.3, 3.3 },

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  24420.02442002442,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 0.0, 7.0 },

  /* Expression: 0.6
   * Referenced by: '<Root>/Constant2'
   */
  0.6,

  /* Expression: 0.3
   * Referenced by: '<Root>/Constant'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S10>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S21>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Integrator'
   */
  0.0,

  /* Expression: 2*pi/52
   * Referenced by: '<S7>/ticks to encoder rotation'
   */
  0.1208304866765305,

  /* Expression: 1/49.5833
   * Referenced by: '<S7>/ encoder rotation to wheel rotation (gear ratio)'
   */
  0.020168080785264393,

  /* Expression: 35
   * Referenced by: '<S7>/wheel radious (mm)'
   */
  35.0,

  /* Expression: 1/1000
   * Referenced by: '<S7>/mm to m'
   */
  0.001,

  /* Expression: 2
   * Referenced by: '<S8>/Constant'
   */
  2.0,

  /* Expression: input_init
   * Referenced by: '<S8>/x0'
   */
  0.0,

  /* Expression: 2*pi/52
   * Referenced by: '<S9>/ticks to encoder rotation'
   */
  0.1208304866765305,

  /* Expression: 1/49.5833
   * Referenced by: '<S9>/ encoder rotation to wheel rotation (gear ratio)'
   */
  0.020168080785264393,

  /* Expression: 35
   * Referenced by: '<S9>/wheel radious (mm)'
   */
  35.0,

  /* Expression: 1/1000
   * Referenced by: '<S9>/mm to m'
   */
  0.001,

  /* Expression: 2
   * Referenced by: '<S10>/Constant'
   */
  2.0,

  /* Expression: input_init
   * Referenced by: '<S10>/x0'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S17>/Constant'
   */
  2.0,

  /* Expression: input_init
   * Referenced by: '<S17>/x0'
   */
  0.0,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U },

  /* Computed Parameter: HILInitialize_DIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U, 40U, 41U, 42U,
    43U, 44U, 45U, 46U, 47U, 48U, 49U, 50U, 51U, 52U, 53U, 54U, 55U, 56U, 57U,
    58U },

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 28U, 29U, 30U, 31U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_OOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 2000U, 2001U, 14000U, 16000U },

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILRead1_Active
   * Referenced by: '<S25>/HIL Read1'
   */
  1,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S25>/HIL Write'
   */
  1,

  /* Computed Parameter: EnableSwitch_CurrentSetting
   * Referenced by: '<Root>/Enable Switch'
   */
  0U
};
