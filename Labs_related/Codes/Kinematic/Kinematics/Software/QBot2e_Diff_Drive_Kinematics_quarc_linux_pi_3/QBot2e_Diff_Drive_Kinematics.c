/*
 * QBot2e_Diff_Drive_Kinematics.c
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

#include "QBot2e_Diff_Drive_Kinematics.h"
#include "QBot2e_Diff_Drive_Kinematics_private.h"
#include "QBot2e_Diff_Drive_Kinematics_dt.h"

/* Block signals (default storage) */
B_QBot2e_Diff_Drive_Kinematic_T QBot2e_Diff_Drive_Kinematics_B;

/* Continuous states */
X_QBot2e_Diff_Drive_Kinematic_T QBot2e_Diff_Drive_Kinematics_X;

/* Block states (default storage) */
DW_QBot2e_Diff_Drive_Kinemati_T QBot2e_Diff_Drive_Kinematics_DW;

/* Real-time model */
RT_MODEL_QBot2e_Diff_Drive_Ki_T QBot2e_Diff_Drive_Kinematics_M_;
RT_MODEL_QBot2e_Diff_Drive_Ki_T *const QBot2e_Diff_Drive_Kinematics_M =
  &QBot2e_Diff_Drive_Kinematics_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  QBot2e_Diff_Drive_Kinematics_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S4>/Qbot2e_Diff_Drive_Kinematics'
 *    '<S5>/Qbot2e_Diff_Drive_Kinematics'
 */
void QB_Qbot2e_Diff_Drive_Kinematics(real_T rtu_vL, real_T rtu_vR,
  B_Qbot2e_Diff_Drive_Kinematic_T *localB)
{
  /* MATLAB Function 'QBot 2e Diff Drive Kinematics/Qbot2e_Diff_Drive_Kinematics': '<S17>:1' */
  /* '<S17>:1:6' */
  localB->vC = (rtu_vL + rtu_vR) * 0.5;

  /* '<S17>:1:7' */
  localB->Omega = (rtu_vR - rtu_vL) * 4.25531914893617;
}

/* Model output function */
void QBot2e_Diff_Drive_Kinematics_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILRead1_o1;
  real_T rtb_Product2;
  real_T rtb_Product1;
  real_T rtb_HILRead1_o2[2];
  boolean_T rtb_HILRead1_o3[3];
  real_T rtb_Stepend_time;
  int8_T rtPrevAction;
  int8_T rtAction;
  real_T rtb_Sum_d;
  real_T tmp;
  if (rtmIsMajorTimeStep(QBot2e_Diff_Drive_Kinematics_M)) {
    /* set solver stop time */
    if (!(QBot2e_Diff_Drive_Kinematics_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
                            ((QBot2e_Diff_Drive_Kinematics_M->Timing.clockTickH0
        + 1) * QBot2e_Diff_Drive_Kinematics_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
                            ((QBot2e_Diff_Drive_Kinematics_M->Timing.clockTick0
        + 1) * QBot2e_Diff_Drive_Kinematics_M->Timing.stepSize0 +
        QBot2e_Diff_Drive_Kinematics_M->Timing.clockTickH0 *
        QBot2e_Diff_Drive_Kinematics_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(QBot2e_Diff_Drive_Kinematics_M)) {
    QBot2e_Diff_Drive_Kinematics_M->Timing.t[0] = rtsiGetT
      (&QBot2e_Diff_Drive_Kinematics_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2e_Diff_Drive_Kinematics_DW.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(QBot2e_Diff_Drive_Kinematics_M)) {
    /* S-Function (hil_read_block): '<S11>/HIL Read1' */

    /* S-Function Block: QBot2e_Diff_Drive_Kinematics/QBot 2e Basic Motor Commands and Sensor Measurement/QBot2e_IO_Basic/HIL Read1 (hil_read_block) */
    {
      t_error result = hil_read
        (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
         &QBot2e_Diff_Drive_Kinematics_P.HILRead1_analog_channels, 1U,
         QBot2e_Diff_Drive_Kinematics_P.HILRead1_encoder_channels, 2U,
         QBot2e_Diff_Drive_Kinematics_P.HILRead1_digital_channels, 3U,
         &QBot2e_Diff_Drive_Kinematics_P.HILRead1_other_channels, 1U,
         &rtb_HILRead1_o1,
         &QBot2e_Diff_Drive_Kinematics_DW.HILRead1_EncoderBuffer[0],
         (t_boolean *)&rtb_HILRead1_o3[0],
         &QBot2e_Diff_Drive_Kinematics_B.HILRead1_o4
         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
      } else {
        rtb_HILRead1_o2[0] =
          QBot2e_Diff_Drive_Kinematics_DW.HILRead1_EncoderBuffer[0];
        rtb_HILRead1_o2[1] =
          QBot2e_Diff_Drive_Kinematics_DW.HILRead1_EncoderBuffer[1];
      }
    }

    /* Outputs for Atomic SubSystem: '<S3>/Bias Removal' */
    /* Step: '<S10>/Step: end_time' incorporates:
     *  Step: '<S10>/Step: start_time'
     */
    tmp = QBot2e_Diff_Drive_Kinematics_M->Timing.t[1];
    if (tmp < QBot2e_Diff_Drive_Kinematics_P.BiasRemoval_end_time) {
      rtb_Stepend_time = QBot2e_Diff_Drive_Kinematics_P.Stepend_time_Y0;
    } else {
      rtb_Stepend_time = QBot2e_Diff_Drive_Kinematics_P.Stepend_time_YFinal;
    }

    /* End of Step: '<S10>/Step: end_time' */

    /* Step: '<S10>/Step: start_time' */
    if (tmp < QBot2e_Diff_Drive_Kinematics_P.BiasRemoval_start_time) {
      tmp = QBot2e_Diff_Drive_Kinematics_P.Stepstart_time_Y0;
    } else {
      tmp = QBot2e_Diff_Drive_Kinematics_P.Stepstart_time_YFinal;
    }

    /* Outputs for Enabled SubSystem: '<S10>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S12>/Enable'
     */
    /* Logic: '<S10>/Logical Operator' incorporates:
     *  Logic: '<S10>/Logical Operator1'
     */
    if ((tmp != 0.0) && (!(rtb_Stepend_time != 0.0))) {
      if (!QBot2e_Diff_Drive_Kinematics_DW.EnabledMovingAverage_MODE) {
        /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
        QBot2e_Diff_Drive_Kinematics_DW.UnitDelay_DSTATE =
          QBot2e_Diff_Drive_Kinematics_P.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S12>/Sum( k=1,n-1, x(k) )' */
        QBot2e_Diff_Drive_Kinematics_DW.Sumk1n1xk_DSTATE =
          QBot2e_Diff_Drive_Kinematics_P.Sumk1n1xk_InitialCondition;
        QBot2e_Diff_Drive_Kinematics_DW.EnabledMovingAverage_MODE = true;
      }

      /* Sum: '<S16>/Count' incorporates:
       *  Constant: '<S16>/unity'
       *  UnitDelay: '<S16>/Unit Delay'
       */
      QBot2e_Diff_Drive_Kinematics_B.Count =
        QBot2e_Diff_Drive_Kinematics_P.unity_Value +
        QBot2e_Diff_Drive_Kinematics_DW.UnitDelay_DSTATE;

      /* Sum: '<S12>/Sum' incorporates:
       *  UnitDelay: '<S12>/Sum( k=1,n-1, x(k) )'
       */
      QBot2e_Diff_Drive_Kinematics_B.Sum =
        QBot2e_Diff_Drive_Kinematics_B.HILRead1_o4 +
        QBot2e_Diff_Drive_Kinematics_DW.Sumk1n1xk_DSTATE;

      /* Product: '<S12>/div' */
      QBot2e_Diff_Drive_Kinematics_B.div = QBot2e_Diff_Drive_Kinematics_B.Sum /
        QBot2e_Diff_Drive_Kinematics_B.Count;
      srUpdateBC(QBot2e_Diff_Drive_Kinematics_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      QBot2e_Diff_Drive_Kinematics_DW.EnabledMovingAverage_MODE = false;
    }

    /* End of Logic: '<S10>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S10>/Enabled Moving Average' */

    /* Sum: '<S10>/Sum' */
    rtb_Sum_d = QBot2e_Diff_Drive_Kinematics_B.HILRead1_o4 -
      QBot2e_Diff_Drive_Kinematics_B.div;

    /* SwitchCase: '<S10>/Switch Case' incorporates:
     *  Constant: '<S13>/Constant'
     *  Inport: '<S14>/Vin'
     *  Inport: '<S15>/V-Vavg'
     */
    rtPrevAction = QBot2e_Diff_Drive_Kinematics_DW.SwitchCase_ActiveSubsystem;
    rtAction = -1;
    if (QBot2e_Diff_Drive_Kinematics_P.BiasRemoval_switch_id < 0.0) {
      tmp = ceil(QBot2e_Diff_Drive_Kinematics_P.BiasRemoval_switch_id);
    } else {
      tmp = floor(QBot2e_Diff_Drive_Kinematics_P.BiasRemoval_switch_id);
    }

    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
     case 1:
      rtAction = 0;
      break;

     case 2:
      rtAction = 1;
      break;

     case 3:
      rtAction = 2;
      break;
    }

    QBot2e_Diff_Drive_Kinematics_DW.SwitchCase_ActiveSubsystem = rtAction;
    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for Outport: '<S13>/zero' */
        QBot2e_Diff_Drive_Kinematics_B.Constant =
          QBot2e_Diff_Drive_Kinematics_P.zero_Y0;
        break;

       case 1:
        /* Disable for Outport: '<S14>/Vbiased' */
        QBot2e_Diff_Drive_Kinematics_B.Vin =
          QBot2e_Diff_Drive_Kinematics_P.Vbiased_Y0;
        break;

       case 2:
        /* Disable for Outport: '<S15>/Vunbiased' */
        QBot2e_Diff_Drive_Kinematics_B.VVavg =
          QBot2e_Diff_Drive_Kinematics_P.Vunbiased_Y0;
        break;
      }
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S10>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      QBot2e_Diff_Drive_Kinematics_B.Constant =
        QBot2e_Diff_Drive_Kinematics_P.Constant_Value;
      srUpdateBC(QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem_Subsy);

      /* End of Outputs for SubSystem: '<S10>/Switch Case Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S10>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      QBot2e_Diff_Drive_Kinematics_B.Vin =
        QBot2e_Diff_Drive_Kinematics_B.HILRead1_o4;
      srUpdateBC(QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem1_Subs);

      /* End of Outputs for SubSystem: '<S10>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S10>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      QBot2e_Diff_Drive_Kinematics_B.VVavg = rtb_Sum_d;
      srUpdateBC(QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem2_Subs);

      /* End of Outputs for SubSystem: '<S10>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S10>/Switch Case' */

    /* Switch: '<S10>/Switch' incorporates:
     *  Logic: '<S10>/Logical Operator2'
     *  Sum: '<S10>/Sum1'
     */
    if (!(rtb_Stepend_time != 0.0)) {
      rtb_Sum_d = (QBot2e_Diff_Drive_Kinematics_B.Constant +
                   QBot2e_Diff_Drive_Kinematics_B.Vin) +
        QBot2e_Diff_Drive_Kinematics_B.VVavg;
    }

    /* End of Switch: '<S10>/Switch' */
    /* End of Outputs for SubSystem: '<S3>/Bias Removal' */

    /* Product: '<S3>/Product' */
    QBot2e_Diff_Drive_Kinematics_B.Product = rtb_Sum_d * rtb_Stepend_time;
  }

  /* Product: '<S9>/Product1' incorporates:
   *  Constant: '<S9>/wn'
   *  Integrator: '<S9>/Integrator2'
   */
  QBot2e_Diff_Drive_Kinematics_B.Product1 =
    QBot2e_Diff_Drive_Kinematics_P.SecondOrderLowPassFilter2_input *
    QBot2e_Diff_Drive_Kinematics_X.Integrator2_CSTATE;

  /* Product: '<S7>/Product1' incorporates:
   *  Constant: '<S7>/wn'
   *  Integrator: '<S7>/Integrator2'
   */
  QBot2e_Diff_Drive_Kinematics_B.Product1_k =
    QBot2e_Diff_Drive_Kinematics_P.SecondOrderLowPassFilter2_inp_b *
    QBot2e_Diff_Drive_Kinematics_X.Integrator2_CSTATE_h;

  /* MATLAB Function: '<S4>/Qbot2e_Diff_Drive_Kinematics' */
  QB_Qbot2e_Diff_Drive_Kinematics(QBot2e_Diff_Drive_Kinematics_B.Product1,
    QBot2e_Diff_Drive_Kinematics_B.Product1_k,
    &QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinematics);
  if (rtmIsMajorTimeStep(QBot2e_Diff_Drive_Kinematics_M)) {
    /* ManualSwitch: '<Root>/Enable Switch' incorporates:
     *  Constant: '<Root>/Disable'
     *  Constant: '<Root>/Enable'
     */
    if (QBot2e_Diff_Drive_Kinematics_P.EnableSwitch_CurrentSetting == 1) {
      rtb_Stepend_time = QBot2e_Diff_Drive_Kinematics_P.Enable_Value;
    } else {
      rtb_Stepend_time = QBot2e_Diff_Drive_Kinematics_P.Disable_Value;
    }

    /* End of ManualSwitch: '<Root>/Enable Switch' */

    /* Product: '<Root>/Product2' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    rtb_Product2 = QBot2e_Diff_Drive_Kinematics_P.Constant2_Value *
      rtb_Stepend_time;

    /* Product: '<Root>/Product1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    rtb_Product1 = QBot2e_Diff_Drive_Kinematics_P.Constant_Value_l *
      rtb_Stepend_time;

    /* MATLAB Function: '<S5>/Qbot2e_Diff_Drive_Kinematics' */
    QB_Qbot2e_Diff_Drive_Kinematics(rtb_Product2, rtb_Product1,
      &QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinemati_i);

    /* Gain: '<S6>/mm to m' incorporates:
     *  Gain: '<S6>/ encoder rotation to wheel rotation (gear ratio)'
     *  Gain: '<S6>/ticks to encoder rotation'
     *  Gain: '<S6>/wheel radious (mm)'
     */
    QBot2e_Diff_Drive_Kinematics_B.mmtom =
      QBot2e_Diff_Drive_Kinematics_P.tickstoencoderrotation_Gain *
      rtb_HILRead1_o2[0] *
      QBot2e_Diff_Drive_Kinematics_P.encoderrotationtowheelrotationg *
      QBot2e_Diff_Drive_Kinematics_P.wheelradiousmm_Gain *
      QBot2e_Diff_Drive_Kinematics_P.mmtom_Gain;

    /* Constant: '<S7>/x0' */
    QBot2e_Diff_Drive_Kinematics_B.x0 = QBot2e_Diff_Drive_Kinematics_P.x0_Value;
  }

  /* Integrator: '<S7>/Integrator1' */
  if (QBot2e_Diff_Drive_Kinematics_DW.Integrator1_IWORK != 0) {
    QBot2e_Diff_Drive_Kinematics_X.Integrator1_CSTATE =
      QBot2e_Diff_Drive_Kinematics_B.x0;
  }

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/wn'
   *  Constant: '<S7>/zt'
   *  Integrator: '<S7>/Integrator1'
   *  Integrator: '<S7>/Integrator2'
   *  Product: '<S7>/Product2'
   *  Sum: '<S7>/Sum'
   *  Sum: '<S7>/Sum1'
   */
  QBot2e_Diff_Drive_Kinematics_B.Product_a =
    ((QBot2e_Diff_Drive_Kinematics_B.mmtom -
      QBot2e_Diff_Drive_Kinematics_X.Integrator1_CSTATE) -
     QBot2e_Diff_Drive_Kinematics_X.Integrator2_CSTATE_h *
     QBot2e_Diff_Drive_Kinematics_P.Constant_Value_f *
     QBot2e_Diff_Drive_Kinematics_P.SecondOrderLowPassFilter2_inp_c) *
    QBot2e_Diff_Drive_Kinematics_P.SecondOrderLowPassFilter2_inp_b;
  if (rtmIsMajorTimeStep(QBot2e_Diff_Drive_Kinematics_M)) {
    /* Gain: '<S8>/mm to m' incorporates:
     *  Gain: '<S8>/ encoder rotation to wheel rotation (gear ratio)'
     *  Gain: '<S8>/ticks to encoder rotation'
     *  Gain: '<S8>/wheel radious (mm)'
     */
    QBot2e_Diff_Drive_Kinematics_B.mmtom_e =
      QBot2e_Diff_Drive_Kinematics_P.tickstoencoderrotation_Gain_a *
      rtb_HILRead1_o2[1] *
      QBot2e_Diff_Drive_Kinematics_P.encoderrotationtowheelrotatio_m *
      QBot2e_Diff_Drive_Kinematics_P.wheelradiousmm_Gain_b *
      QBot2e_Diff_Drive_Kinematics_P.mmtom_Gain_n;

    /* Constant: '<S9>/x0' */
    QBot2e_Diff_Drive_Kinematics_B.x0_n =
      QBot2e_Diff_Drive_Kinematics_P.x0_Value_b;
  }

  /* Integrator: '<S9>/Integrator1' */
  if (QBot2e_Diff_Drive_Kinematics_DW.Integrator1_IWORK_k != 0) {
    QBot2e_Diff_Drive_Kinematics_X.Integrator1_CSTATE_c =
      QBot2e_Diff_Drive_Kinematics_B.x0_n;
  }

  /* Product: '<S9>/Product' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/wn'
   *  Constant: '<S9>/zt'
   *  Integrator: '<S9>/Integrator1'
   *  Integrator: '<S9>/Integrator2'
   *  Product: '<S9>/Product2'
   *  Sum: '<S9>/Sum'
   *  Sum: '<S9>/Sum1'
   */
  QBot2e_Diff_Drive_Kinematics_B.Product_i =
    ((QBot2e_Diff_Drive_Kinematics_B.mmtom_e -
      QBot2e_Diff_Drive_Kinematics_X.Integrator1_CSTATE_c) -
     QBot2e_Diff_Drive_Kinematics_X.Integrator2_CSTATE *
     QBot2e_Diff_Drive_Kinematics_P.Constant_Value_o *
     QBot2e_Diff_Drive_Kinematics_P.SecondOrderLowPassFilter2_inp_e) *
    QBot2e_Diff_Drive_Kinematics_P.SecondOrderLowPassFilter2_input;
  if (rtmIsMajorTimeStep(QBot2e_Diff_Drive_Kinematics_M)) {
    /* S-Function (hil_write_block): '<S11>/HIL Write' */

    /* S-Function Block: QBot2e_Diff_Drive_Kinematics/QBot 2e Basic Motor Commands and Sensor Measurement/QBot2e_IO_Basic/HIL Write (hil_write_block) */
    {
      t_error result;
      QBot2e_Diff_Drive_Kinematics_DW.HILWrite_OtherBuffer[0] = rtb_Product1;
      QBot2e_Diff_Drive_Kinematics_DW.HILWrite_OtherBuffer[1] = rtb_Product2;
      result = hil_write(QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         QBot2e_Diff_Drive_Kinematics_P.HILWrite_other_channels,
                         2U,
                         NULL,
                         NULL,
                         NULL,
                         &QBot2e_Diff_Drive_Kinematics_DW.HILWrite_OtherBuffer[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void QBot2e_Diff_Drive_Kinematics_update(void)
{
  /* Update for Atomic SubSystem: '<S3>/Bias Removal' */
  /* Update for Enabled SubSystem: '<S10>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (rtmIsMajorTimeStep(QBot2e_Diff_Drive_Kinematics_M) &&
      QBot2e_Diff_Drive_Kinematics_DW.EnabledMovingAverage_MODE) {
    /* Update for UnitDelay: '<S16>/Unit Delay' */
    QBot2e_Diff_Drive_Kinematics_DW.UnitDelay_DSTATE =
      QBot2e_Diff_Drive_Kinematics_B.Count;

    /* Update for UnitDelay: '<S12>/Sum( k=1,n-1, x(k) )' */
    QBot2e_Diff_Drive_Kinematics_DW.Sumk1n1xk_DSTATE =
      QBot2e_Diff_Drive_Kinematics_B.Sum;
  }

  /* End of Update for SubSystem: '<S10>/Enabled Moving Average' */
  /* End of Update for SubSystem: '<S3>/Bias Removal' */

  /* Update for Integrator: '<S7>/Integrator1' */
  QBot2e_Diff_Drive_Kinematics_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S9>/Integrator1' */
  QBot2e_Diff_Drive_Kinematics_DW.Integrator1_IWORK_k = 0;
  if (rtmIsMajorTimeStep(QBot2e_Diff_Drive_Kinematics_M)) {
    rt_ertODEUpdateContinuousStates(&QBot2e_Diff_Drive_Kinematics_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QBot2e_Diff_Drive_Kinematics_M->Timing.clockTick0)) {
    ++QBot2e_Diff_Drive_Kinematics_M->Timing.clockTickH0;
  }

  QBot2e_Diff_Drive_Kinematics_M->Timing.t[0] = rtsiGetSolverStopTime
    (&QBot2e_Diff_Drive_Kinematics_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++QBot2e_Diff_Drive_Kinematics_M->Timing.clockTick1)) {
      ++QBot2e_Diff_Drive_Kinematics_M->Timing.clockTickH1;
    }

    QBot2e_Diff_Drive_Kinematics_M->Timing.t[1] =
      QBot2e_Diff_Drive_Kinematics_M->Timing.clockTick1 *
      QBot2e_Diff_Drive_Kinematics_M->Timing.stepSize1 +
      QBot2e_Diff_Drive_Kinematics_M->Timing.clockTickH1 *
      QBot2e_Diff_Drive_Kinematics_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void QBot2e_Diff_Drive_Kinematics_derivatives(void)
{
  XDot_QBot2e_Diff_Drive_Kinema_T *_rtXdot;
  _rtXdot = ((XDot_QBot2e_Diff_Drive_Kinema_T *)
             QBot2e_Diff_Drive_Kinematics_M->derivs);

  /* Derivatives for Integrator: '<S9>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = QBot2e_Diff_Drive_Kinematics_B.Product_i;

  /* Derivatives for Integrator: '<S7>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_h = QBot2e_Diff_Drive_Kinematics_B.Product_a;

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = QBot2e_Diff_Drive_Kinematics_B.Product1_k;

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_c = QBot2e_Diff_Drive_Kinematics_B.Product1;
}

/* Model initialize function */
void QBot2e_Diff_Drive_Kinematics_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: QBot2e_Diff_Drive_Kinematics/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qbot2e", "0",
                      &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
       "pwm0_en=1;pwm0_pin=12;pwm1_en=1;pwm1_pin=13;", 45);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
      return;
    }

    if ((QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AIPStart && !is_switching)
        || (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AIPEnter &&
            is_switching)) {
      result = hil_set_analog_input_ranges
        (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AIChannels, 6U,
         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AILow,
         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
       QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DIChannels, 31U,
       QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOChannels, 4U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
      return;
    }

    if ((QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOStart && !is_switching) ||
        (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOEnter && is_switching))
    {
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[0] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOInitial;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[1] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOInitial;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[2] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOInitial;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[3] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOInitial;
      result = hil_write_digital
        (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOChannels, 4U, (t_boolean
          *) &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
        return;
      }
    }

    if ((QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIPStart && !is_switching)
        || (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIPEnter &&
            is_switching)) {
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_QuadratureModes[0] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIQuadrature;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_QuadratureModes[1] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
        return;
      }
    }

    if ((QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIStart && !is_switching) ||
        (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIEnter && is_switching))
    {
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_InitialEICounts[0] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIInitial;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_InitialEICounts[1] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIChannels, 2U,
         &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
        return;
      }
    }

    if ((QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POPStart && !is_switching)
        || (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POPEnter &&
            is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[0] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POModes;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[1] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POModes;
      result = hil_set_pwm_mode
        (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POChannels, 2U,
         (t_pwm_mode *)
         &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
        return;
      }

      if (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[0] ==
          PWM_DUTY_CYCLE_MODE ||
          QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[0] ==
          PWM_ONE_SHOT_MODE ||
          QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[0] ==
          PWM_TIME_MODE ||
          QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[0] ==
          PWM_RAW_MODE) {
        QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
          = (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POChannels[0]);
        QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
          = QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POFrequency;
        num_duty_cycle_modes++;
      } else {
        QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedChans[1U -
          num_frequency_modes] =
          (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POChannels[0]);
        QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedFreqs[1U -
          num_frequency_modes] =
          QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POFrequency;
        num_frequency_modes++;
      }

      if (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[1] ==
          PWM_DUTY_CYCLE_MODE ||
          QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[1] ==
          PWM_ONE_SHOT_MODE ||
          QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[1] ==
          PWM_TIME_MODE ||
          QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[1] ==
          PWM_RAW_MODE) {
        QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
          = (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POChannels[1]);
        QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
          = QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POFrequency;
        num_duty_cycle_modes++;
      } else {
        QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedChans[1U -
          num_frequency_modes] =
          (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POChannels[1]);
        QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedFreqs[1U -
          num_frequency_modes] =
          QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POFrequency;
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
           &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
           &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
          return;
        }
      }

      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[0] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POConfiguration;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[1] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POConfiguration;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POAlignValues[0] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POAlignment;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POAlignValues[1] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POAlignment;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POPolarityVals[0] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POPolarity;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POPolarityVals[1] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POPolarity;
      result = hil_set_pwm_configuration
        (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POChannels, 2U,
         (t_pwm_configuration *)
         &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
        return;
      }
    }

    if ((QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POStart && !is_switching) ||
        (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POEnter && is_switching))
    {
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POValues[0] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POInitial;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POValues[1] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POInitial;
      result = hil_write_pwm(QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POChannels, 2U,
        &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
        return;
      }
    }

    if ((QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOStart && !is_switching) ||
        (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOEnter && is_switching))
    {
      result = hil_write_other
        (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOChannels, 4U,
         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for Atomic SubSystem: '<S3>/Bias Removal' */
  /* Start for Enabled SubSystem: '<S10>/Enabled Moving Average' */
  QBot2e_Diff_Drive_Kinematics_DW.EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S10>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S10>/Switch Case' */
  QBot2e_Diff_Drive_Kinematics_DW.SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S3>/Bias Removal' */

  /* Start for Constant: '<S7>/x0' */
  QBot2e_Diff_Drive_Kinematics_B.x0 = QBot2e_Diff_Drive_Kinematics_P.x0_Value;

  /* Start for Constant: '<S9>/x0' */
  QBot2e_Diff_Drive_Kinematics_B.x0_n =
    QBot2e_Diff_Drive_Kinematics_P.x0_Value_b;

  /* InitializeConditions for Integrator: '<S9>/Integrator2' */
  QBot2e_Diff_Drive_Kinematics_X.Integrator2_CSTATE =
    QBot2e_Diff_Drive_Kinematics_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S7>/Integrator2' */
  QBot2e_Diff_Drive_Kinematics_X.Integrator2_CSTATE_h =
    QBot2e_Diff_Drive_Kinematics_P.Integrator2_IC_f;

  /* InitializeConditions for Integrator: '<S7>/Integrator1' incorporates:
   *  Integrator: '<S9>/Integrator1'
   */
  if (rtmIsFirstInitCond(QBot2e_Diff_Drive_Kinematics_M)) {
    QBot2e_Diff_Drive_Kinematics_X.Integrator1_CSTATE = 0.0;
    QBot2e_Diff_Drive_Kinematics_X.Integrator1_CSTATE_c = 0.0;
  }

  QBot2e_Diff_Drive_Kinematics_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S7>/Integrator1' */

  /* InitializeConditions for Integrator: '<S9>/Integrator1' */
  QBot2e_Diff_Drive_Kinematics_DW.Integrator1_IWORK_k = 1;

  /* SystemInitialize for Atomic SubSystem: '<S3>/Bias Removal' */
  /* SystemInitialize for Enabled SubSystem: '<S10>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
  QBot2e_Diff_Drive_Kinematics_DW.UnitDelay_DSTATE =
    QBot2e_Diff_Drive_Kinematics_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S12>/Sum( k=1,n-1, x(k) )' */
  QBot2e_Diff_Drive_Kinematics_DW.Sumk1n1xk_DSTATE =
    QBot2e_Diff_Drive_Kinematics_P.Sumk1n1xk_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S10>/Enabled Moving Average' */

  /* SystemInitialize for IfAction SubSystem: '<S10>/Switch Case Action Subsystem' */
  /* SystemInitialize for Outport: '<S13>/zero' */
  QBot2e_Diff_Drive_Kinematics_B.Constant =
    QBot2e_Diff_Drive_Kinematics_P.zero_Y0;

  /* End of SystemInitialize for SubSystem: '<S10>/Switch Case Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S10>/Switch Case Action Subsystem1' */
  /* SystemInitialize for Outport: '<S14>/Vbiased' */
  QBot2e_Diff_Drive_Kinematics_B.Vin = QBot2e_Diff_Drive_Kinematics_P.Vbiased_Y0;

  /* End of SystemInitialize for SubSystem: '<S10>/Switch Case Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S10>/Switch Case Action Subsystem2' */
  /* SystemInitialize for Outport: '<S15>/Vunbiased' */
  QBot2e_Diff_Drive_Kinematics_B.VVavg =
    QBot2e_Diff_Drive_Kinematics_P.Vunbiased_Y0;

  /* End of SystemInitialize for SubSystem: '<S10>/Switch Case Action Subsystem2' */
  /* End of SystemInitialize for SubSystem: '<S3>/Bias Removal' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(QBot2e_Diff_Drive_Kinematics_M)) {
    rtmSetFirstInitCond(QBot2e_Diff_Drive_Kinematics_M, 0);
  }
}

/* Model terminate function */
void QBot2e_Diff_Drive_Kinematics_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: QBot2e_Diff_Drive_Kinematics/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card);
    hil_monitor_stop_all(QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card);
    is_switching = false;
    if ((QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOTerminate &&
         !is_switching) || (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOExit &&
         is_switching)) {
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[0] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOFinal;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[1] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOFinal;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[2] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOFinal;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[3] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOFinal;
      num_final_digital_outputs = 4U;
    }

    if ((QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POTerminate &&
         !is_switching) || (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POExit &&
         is_switching)) {
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POValues[0] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POFinal;
      QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POValues[1] =
        QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POFinal;
      num_final_pwm_outputs = 2U;
    }

    if ((QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOTerminate &&
         !is_switching) || (QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOExit &&
         is_switching)) {
      num_final_other_outputs = 4U;
    }

    if (0
        || num_final_pwm_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card
                         , NULL, 0
                         ,
                         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         ,
                         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         ,
                         QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , NULL
                         ,
                         &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POValues[
                         0]
                         , (t_boolean *)
                         &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[0]
                         , QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
             QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POChannels,
             num_final_pwm_outputs,
             &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
             QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card,
             QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOChannels,
             num_final_other_outputs,
             QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2e_Diff_Drive_Kinematics_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card);
    hil_monitor_delete_all(QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card);
    hil_close(QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card);
    QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  QBot2e_Diff_Drive_Kinematics_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  QBot2e_Diff_Drive_Kinematics_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  QBot2e_Diff_Drive_Kinematics_initialize();
}

void MdlTerminate(void)
{
  QBot2e_Diff_Drive_Kinematics_terminate();
}

/* Registration function */
RT_MODEL_QBot2e_Diff_Drive_Ki_T *QBot2e_Diff_Drive_Kinematics(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)QBot2e_Diff_Drive_Kinematics_M, 0,
                sizeof(RT_MODEL_QBot2e_Diff_Drive_Ki_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
                          &QBot2e_Diff_Drive_Kinematics_M->Timing.simTimeStep);
    rtsiSetTPtr(&QBot2e_Diff_Drive_Kinematics_M->solverInfo, &rtmGetTPtr
                (QBot2e_Diff_Drive_Kinematics_M));
    rtsiSetStepSizePtr(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
                       &QBot2e_Diff_Drive_Kinematics_M->Timing.stepSize0);
    rtsiSetdXPtr(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
                 &QBot2e_Diff_Drive_Kinematics_M->derivs);
    rtsiSetContStatesPtr(&QBot2e_Diff_Drive_Kinematics_M->solverInfo, (real_T **)
                         &QBot2e_Diff_Drive_Kinematics_M->contStates);
    rtsiSetNumContStatesPtr(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
      &QBot2e_Diff_Drive_Kinematics_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
      &QBot2e_Diff_Drive_Kinematics_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
       &QBot2e_Diff_Drive_Kinematics_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
       &QBot2e_Diff_Drive_Kinematics_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
                          (&rtmGetErrorStatus(QBot2e_Diff_Drive_Kinematics_M)));
    rtsiSetRTModelPtr(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
                      QBot2e_Diff_Drive_Kinematics_M);
  }

  rtsiSetSimTimeStep(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
                     MAJOR_TIME_STEP);
  QBot2e_Diff_Drive_Kinematics_M->intgData.f[0] =
    QBot2e_Diff_Drive_Kinematics_M->odeF[0];
  QBot2e_Diff_Drive_Kinematics_M->contStates = ((real_T *)
    &QBot2e_Diff_Drive_Kinematics_X);
  rtsiSetSolverData(&QBot2e_Diff_Drive_Kinematics_M->solverInfo, (void *)
                    &QBot2e_Diff_Drive_Kinematics_M->intgData);
  rtsiSetSolverName(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      QBot2e_Diff_Drive_Kinematics_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    QBot2e_Diff_Drive_Kinematics_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    QBot2e_Diff_Drive_Kinematics_M->Timing.sampleTimes =
      (&QBot2e_Diff_Drive_Kinematics_M->Timing.sampleTimesArray[0]);
    QBot2e_Diff_Drive_Kinematics_M->Timing.offsetTimes =
      (&QBot2e_Diff_Drive_Kinematics_M->Timing.offsetTimesArray[0]);

    /* task periods */
    QBot2e_Diff_Drive_Kinematics_M->Timing.sampleTimes[0] = (0.0);
    QBot2e_Diff_Drive_Kinematics_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    QBot2e_Diff_Drive_Kinematics_M->Timing.offsetTimes[0] = (0.0);
    QBot2e_Diff_Drive_Kinematics_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(QBot2e_Diff_Drive_Kinematics_M,
             &QBot2e_Diff_Drive_Kinematics_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = QBot2e_Diff_Drive_Kinematics_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    QBot2e_Diff_Drive_Kinematics_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(QBot2e_Diff_Drive_Kinematics_M, -1);
  QBot2e_Diff_Drive_Kinematics_M->Timing.stepSize0 = 0.005;
  QBot2e_Diff_Drive_Kinematics_M->Timing.stepSize1 = 0.005;
  rtmSetFirstInitCond(QBot2e_Diff_Drive_Kinematics_M, 1);

  /* External mode info */
  QBot2e_Diff_Drive_Kinematics_M->Sizes.checksums[0] = (1805651504U);
  QBot2e_Diff_Drive_Kinematics_M->Sizes.checksums[1] = (2439541167U);
  QBot2e_Diff_Drive_Kinematics_M->Sizes.checksums[2] = (3586757282U);
  QBot2e_Diff_Drive_Kinematics_M->Sizes.checksums[3] = (334487058U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    QBot2e_Diff_Drive_Kinematics_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &QBot2e_Diff_Drive_Kinematics_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[4] = (sysRanDType *)
      &QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem_Subsy;
    systemRan[5] = (sysRanDType *)
      &QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[6] = (sysRanDType *)
      &QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(QBot2e_Diff_Drive_Kinematics_M->extModeInfo,
      &QBot2e_Diff_Drive_Kinematics_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(QBot2e_Diff_Drive_Kinematics_M->extModeInfo,
                        QBot2e_Diff_Drive_Kinematics_M->Sizes.checksums);
    rteiSetTPtr(QBot2e_Diff_Drive_Kinematics_M->extModeInfo, rtmGetTPtr
                (QBot2e_Diff_Drive_Kinematics_M));
  }

  QBot2e_Diff_Drive_Kinematics_M->solverInfoPtr =
    (&QBot2e_Diff_Drive_Kinematics_M->solverInfo);
  QBot2e_Diff_Drive_Kinematics_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&QBot2e_Diff_Drive_Kinematics_M->solverInfo, 0.005);
  rtsiSetSolverMode(&QBot2e_Diff_Drive_Kinematics_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  QBot2e_Diff_Drive_Kinematics_M->blockIO = ((void *)
    &QBot2e_Diff_Drive_Kinematics_B);

  {
    QBot2e_Diff_Drive_Kinematics_B.HILRead1_o4 = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.Product = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.Product1 = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.Product1_k = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.mmtom = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.x0 = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.Product_a = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.mmtom_e = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.x0_n = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.Product_i = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.VVavg = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.Vin = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.Constant = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.Count = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.Sum = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.div = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinemati_i.vC = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinemati_i.Omega = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinematics.vC = 0.0;
    QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinematics.Omega = 0.0;
  }

  /* parameters */
  QBot2e_Diff_Drive_Kinematics_M->defaultParam = ((real_T *)
    &QBot2e_Diff_Drive_Kinematics_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &QBot2e_Diff_Drive_Kinematics_X;
    QBot2e_Diff_Drive_Kinematics_M->contStates = (x);
    (void) memset((void *)&QBot2e_Diff_Drive_Kinematics_X, 0,
                  sizeof(X_QBot2e_Diff_Drive_Kinematic_T));
  }

  /* states (dwork) */
  QBot2e_Diff_Drive_Kinematics_M->dwork = ((void *)
    &QBot2e_Diff_Drive_Kinematics_DW);
  (void) memset((void *)&QBot2e_Diff_Drive_Kinematics_DW, 0,
                sizeof(DW_QBot2e_Diff_Drive_Kinemati_T));
  QBot2e_Diff_Drive_Kinematics_DW.UnitDelay_DSTATE = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.Sumk1n1xk_DSTATE = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_FilterFrequency[0] = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_FilterFrequency[1] = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedFreqs[0] = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedFreqs[1] = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POValues[0] = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POValues[1] = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_OOValues[0] = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_OOValues[1] = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_OOValues[2] = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_OOValues[3] = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILWrite_OtherBuffer[0] = 0.0;
  QBot2e_Diff_Drive_Kinematics_DW.HILWrite_OtherBuffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    QBot2e_Diff_Drive_Kinematics_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  QBot2e_Diff_Drive_Kinematics_M->Sizes.numContStates = (4);/* Number of continuous states */
  QBot2e_Diff_Drive_Kinematics_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  QBot2e_Diff_Drive_Kinematics_M->Sizes.numY = (0);/* Number of model outputs */
  QBot2e_Diff_Drive_Kinematics_M->Sizes.numU = (0);/* Number of model inputs */
  QBot2e_Diff_Drive_Kinematics_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  QBot2e_Diff_Drive_Kinematics_M->Sizes.numSampTimes = (2);/* Number of sample times */
  QBot2e_Diff_Drive_Kinematics_M->Sizes.numBlocks = (78);/* Number of blocks */
  QBot2e_Diff_Drive_Kinematics_M->Sizes.numBlockIO = (21);/* Number of block outputs */
  QBot2e_Diff_Drive_Kinematics_M->Sizes.numBlockPrms = (165);/* Sum of parameter "widths" */
  return QBot2e_Diff_Drive_Kinematics_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
