/*
 * QBot2e_Keyboard_Teleop_Wheel.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QBot2e_Keyboard_Teleop_Wheel".
 *
 * Model version              : 1.232
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue May 23 11:38:07 2023
 *
 * Target selection: quarc_linux_pi_3.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "QBot2e_Keyboard_Teleop_Wheel.h"
#include "QBot2e_Keyboard_Teleop_Wheel_private.h"
#include "QBot2e_Keyboard_Teleop_Wheel_dt.h"

/* Block signals (default storage) */
B_QBot2e_Keyboard_Teleop_Whee_T QBot2e_Keyboard_Teleop_Wheel_B;

/* Continuous states */
X_QBot2e_Keyboard_Teleop_Whee_T QBot2e_Keyboard_Teleop_Wheel_X;

/* Block states (default storage) */
DW_QBot2e_Keyboard_Teleop_Whe_T QBot2e_Keyboard_Teleop_Wheel_DW;

/* Real-time model */
RT_MODEL_QBot2e_Keyboard_Tele_T QBot2e_Keyboard_Teleop_Wheel_M_;
RT_MODEL_QBot2e_Keyboard_Tele_T *const QBot2e_Keyboard_Teleop_Wheel_M =
  &QBot2e_Keyboard_Teleop_Wheel_M_;
static void rate_monotonic_scheduler(void);

/*
 * Send data to the host peripheral (e.g. force feedback game controllers). The packet includes
 * the peripheral identifier so that the host knows to which peripheral to direct the data.
 */
t_error host_send_extmode_packet(void * context, const void * data, t_uint
  data_length)
{
  return extmode_svr_send_custom_action(EXT_MODE_ACTION_HOST_INTERFACE, data,
    data_length);
}

t_error host_extmode_svr_connected_callback(void * context)
{
  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Host Keyboard (host_keyboard_block) */
  {
    if (QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_Enabled) {
      struct __attribute__ ((__packed__)) tag_keyboard_configuration {
        t_host_command_header header;
        char driver[9];
        t_boolean debug_flag;
        t_uint8 num_keys;
        t_uint8 virtual_keys[4];
      } keyboard_configuration = {
        { 0, HOST_COMMAND_LOAD },
        "keyboard",
        false,
        4
      };

      t_error result;
      keyboard_configuration.virtual_keys[0] =
        (QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[0]);
      keyboard_configuration.virtual_keys[1] =
        (QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[1]);
      keyboard_configuration.virtual_keys[2] =
        (QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[2]);
      keyboard_configuration.virtual_keys[3] =
        (QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[3]);
      keyboard_configuration.debug_flag =
        QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_DebugMode;
      result = host_send_extmode_packet(NULL, &keyboard_configuration, sizeof
        (keyboard_configuration));
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
      }
    }
  }

  return 0;
}

t_error host_extmode_svr_disconnected_callback(void * context)
{
  return 0;
}

t_error host_extmode_svr_custom_action_callback(void * context, t_uint action,
  const void * data, t_uint data_length)
{
  if (action == EXT_MODE_ACTION_HOST_INTERFACE) {
    const t_uint32 * packet = (const t_uint32 *) data;
    t_uint32 peripheral_identifier = packet[0];
    t_uint32 buffer_size = packet[1];
    const void * buffer = &packet[2];
    switch (peripheral_identifier) {
     case 0:
      /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Host Keyboard (host_keyboard_block) */
      {
        t_keyboard_state * state = (t_keyboard_state *) (buffer);
        if (buffer_size >= sizeof(t_keyboard_state)) {
          t_error result = qthread_section_lock
            (&QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_Lock);
          if (result == 0) {
            memory_copy
              (&QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_KeyboardState,
               sizeof
               (*&QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_KeyboardState),
               state);
            QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_NewData = true;
            qthread_section_unlock
              (&QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_Lock);
          }
        } else {
          rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M,
                            "A Host Keyboad block has received an invalid packet from the host!");
        }
      }
      break;

     default:
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M,
                        "Invalid peripheral identifier received");
      break;
    }
  }

  return 0;
}

void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T outBitsLo;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  in0Hi = in0 >> 16U;
  in0Lo = in0 & 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << 16U) + in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1U;
  }

  in0Lo = outBitsLo;
  outBitsLo += productHiLo << 16U;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi)
    + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_T mul_u32_hiSR(uint32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_u32(a, b, &u32_chi, &u32_clo);
  return u32_chi >> aShift;
}

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(QBot2e_Keyboard_Teleop_Wheel_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(QBot2e_Keyboard_Teleop_Wheel_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (QBot2e_Keyboard_Teleop_Wheel_M->Timing.TaskCounters.TID[2])++;
  if ((QBot2e_Keyboard_Teleop_Wheel_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.04s, 0.0s] */
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.TaskCounters.TID[2] = 0;
  }
}

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
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  QBot2e_Keyboard_Teleop_Wheel_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void QBot2e_Keyboard_Teleop_Wheel_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILRead1_o2[2];
  real_T rtb_Add;
  real_T rtb_Add1;
  boolean_T rtb_HILRead1_o3[3];
  boolean_T rtb_HostKeyboard_o2[4];
  real_T rtb_Stepend_time;
  int8_T rtPrevAction;
  int8_T rtAction;
  real_T rtb_Sum_b;
  real_T tmp;
  if (rtmIsMajorTimeStep(QBot2e_Keyboard_Teleop_Wheel_M)) {
    /* set solver stop time */
    if (!(QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
                            ((QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTickH0
        + 1) * QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
                            ((QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTick0
        + 1) * QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize0 +
        QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTickH0 *
        QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(QBot2e_Keyboard_Teleop_Wheel_M)) {
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.t[0] = rtsiGetT
      (&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2e_Keyboard_Teleop_Wheel_DW.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(QBot2e_Keyboard_Teleop_Wheel_M)) {
    /* S-Function (host_initialize_block): '<Root>/Host Initialize' */

    /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Host Initialize (host_initialize_block) */
    {
      QBot2e_Keyboard_Teleop_Wheel_B.HostInitialize_o1 =
        (rtExtModeQuarcIsConnected() ? HOST_STATE_CONNECTED :
         HOST_STATE_NOT_CONNECTED);
    }

    /* S-Function (hil_read_block): '<S12>/HIL Read1' */

    /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/QBot 2e Basic Motor Commands and Sensor Measurement/QBot2e_IO_Basic/HIL Read1 (hil_read_block) */
    {
      t_error result = hil_read
        (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
         &QBot2e_Keyboard_Teleop_Wheel_P.HILRead1_analog_channels, 1U,
         QBot2e_Keyboard_Teleop_Wheel_P.HILRead1_encoder_channels, 2U,
         QBot2e_Keyboard_Teleop_Wheel_P.HILRead1_digital_channels, 3U,
         &QBot2e_Keyboard_Teleop_Wheel_P.HILRead1_other_channels, 1U,
         &QBot2e_Keyboard_Teleop_Wheel_B.HILRead1_o1,
         &QBot2e_Keyboard_Teleop_Wheel_DW.HILRead1_EncoderBuffer[0],
         (t_boolean *)&rtb_HILRead1_o3[0],
         &QBot2e_Keyboard_Teleop_Wheel_B.HILRead1_o4
         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
      } else {
        rtb_HILRead1_o2[0] =
          QBot2e_Keyboard_Teleop_Wheel_DW.HILRead1_EncoderBuffer[0];
        rtb_HILRead1_o2[1] =
          QBot2e_Keyboard_Teleop_Wheel_DW.HILRead1_EncoderBuffer[1];
      }
    }

    /* Outputs for Atomic SubSystem: '<S3>/Bias Removal' */
    /* Step: '<S11>/Step: end_time' incorporates:
     *  Step: '<S11>/Step: start_time'
     */
    tmp = QBot2e_Keyboard_Teleop_Wheel_M->Timing.t[1];
    if (tmp < QBot2e_Keyboard_Teleop_Wheel_P.BiasRemoval_end_time) {
      rtb_Stepend_time = QBot2e_Keyboard_Teleop_Wheel_P.Stepend_time_Y0;
    } else {
      rtb_Stepend_time = QBot2e_Keyboard_Teleop_Wheel_P.Stepend_time_YFinal;
    }

    /* End of Step: '<S11>/Step: end_time' */

    /* Step: '<S11>/Step: start_time' */
    if (tmp < QBot2e_Keyboard_Teleop_Wheel_P.BiasRemoval_start_time) {
      tmp = QBot2e_Keyboard_Teleop_Wheel_P.Stepstart_time_Y0;
    } else {
      tmp = QBot2e_Keyboard_Teleop_Wheel_P.Stepstart_time_YFinal;
    }

    /* Outputs for Enabled SubSystem: '<S11>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    /* Logic: '<S11>/Logical Operator' incorporates:
     *  Logic: '<S11>/Logical Operator1'
     */
    if ((tmp != 0.0) && (!(rtb_Stepend_time != 0.0))) {
      if (!QBot2e_Keyboard_Teleop_Wheel_DW.EnabledMovingAverage_MODE) {
        /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
        QBot2e_Keyboard_Teleop_Wheel_DW.UnitDelay_DSTATE =
          QBot2e_Keyboard_Teleop_Wheel_P.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S13>/Sum( k=1,n-1, x(k) )' */
        QBot2e_Keyboard_Teleop_Wheel_DW.Sumk1n1xk_DSTATE =
          QBot2e_Keyboard_Teleop_Wheel_P.Sumk1n1xk_InitialCondition;
        QBot2e_Keyboard_Teleop_Wheel_DW.EnabledMovingAverage_MODE = true;
      }

      /* Sum: '<S17>/Count' incorporates:
       *  Constant: '<S17>/unity'
       *  UnitDelay: '<S17>/Unit Delay'
       */
      QBot2e_Keyboard_Teleop_Wheel_B.Count =
        QBot2e_Keyboard_Teleop_Wheel_P.unity_Value +
        QBot2e_Keyboard_Teleop_Wheel_DW.UnitDelay_DSTATE;

      /* Sum: '<S13>/Sum' incorporates:
       *  UnitDelay: '<S13>/Sum( k=1,n-1, x(k) )'
       */
      QBot2e_Keyboard_Teleop_Wheel_B.Sum =
        QBot2e_Keyboard_Teleop_Wheel_B.HILRead1_o4 +
        QBot2e_Keyboard_Teleop_Wheel_DW.Sumk1n1xk_DSTATE;

      /* Product: '<S13>/div' */
      QBot2e_Keyboard_Teleop_Wheel_B.div = QBot2e_Keyboard_Teleop_Wheel_B.Sum /
        QBot2e_Keyboard_Teleop_Wheel_B.Count;
      srUpdateBC(QBot2e_Keyboard_Teleop_Wheel_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      QBot2e_Keyboard_Teleop_Wheel_DW.EnabledMovingAverage_MODE = false;
    }

    /* End of Logic: '<S11>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S11>/Enabled Moving Average' */

    /* Sum: '<S11>/Sum' */
    rtb_Sum_b = QBot2e_Keyboard_Teleop_Wheel_B.HILRead1_o4 -
      QBot2e_Keyboard_Teleop_Wheel_B.div;

    /* SwitchCase: '<S11>/Switch Case' incorporates:
     *  Constant: '<S14>/Constant'
     *  Inport: '<S15>/Vin'
     *  Inport: '<S16>/V-Vavg'
     */
    rtPrevAction = QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCase_ActiveSubsystem;
    rtAction = -1;
    if (QBot2e_Keyboard_Teleop_Wheel_P.BiasRemoval_switch_id < 0.0) {
      tmp = ceil(QBot2e_Keyboard_Teleop_Wheel_P.BiasRemoval_switch_id);
    } else {
      tmp = floor(QBot2e_Keyboard_Teleop_Wheel_P.BiasRemoval_switch_id);
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

    QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCase_ActiveSubsystem = rtAction;
    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for Outport: '<S14>/zero' */
        QBot2e_Keyboard_Teleop_Wheel_B.Constant =
          QBot2e_Keyboard_Teleop_Wheel_P.zero_Y0;
        break;

       case 1:
        /* Disable for Outport: '<S15>/Vbiased' */
        QBot2e_Keyboard_Teleop_Wheel_B.Vin =
          QBot2e_Keyboard_Teleop_Wheel_P.Vbiased_Y0;
        break;

       case 2:
        /* Disable for Outport: '<S16>/Vunbiased' */
        QBot2e_Keyboard_Teleop_Wheel_B.VVavg =
          QBot2e_Keyboard_Teleop_Wheel_P.Vunbiased_Y0;
        break;
      }
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S11>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      QBot2e_Keyboard_Teleop_Wheel_B.Constant =
        QBot2e_Keyboard_Teleop_Wheel_P.Constant_Value;
      srUpdateBC(QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem_Subsy);

      /* End of Outputs for SubSystem: '<S11>/Switch Case Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S11>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      QBot2e_Keyboard_Teleop_Wheel_B.Vin =
        QBot2e_Keyboard_Teleop_Wheel_B.HILRead1_o4;
      srUpdateBC(QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem1_Subs);

      /* End of Outputs for SubSystem: '<S11>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S11>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      QBot2e_Keyboard_Teleop_Wheel_B.VVavg = rtb_Sum_b;
      srUpdateBC(QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem2_Subs);

      /* End of Outputs for SubSystem: '<S11>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S11>/Switch Case' */

    /* Switch: '<S11>/Switch' incorporates:
     *  Logic: '<S11>/Logical Operator2'
     *  Sum: '<S11>/Sum1'
     */
    if (!(rtb_Stepend_time != 0.0)) {
      rtb_Sum_b = (QBot2e_Keyboard_Teleop_Wheel_B.Constant +
                   QBot2e_Keyboard_Teleop_Wheel_B.Vin) +
        QBot2e_Keyboard_Teleop_Wheel_B.VVavg;
    }

    /* End of Switch: '<S11>/Switch' */
    /* End of Outputs for SubSystem: '<S3>/Bias Removal' */

    /* Product: '<S3>/Product' */
    QBot2e_Keyboard_Teleop_Wheel_B.Product = rtb_Sum_b * rtb_Stepend_time;
  }

  /* Integrator: '<S4>/Integrator1' */
  QBot2e_Keyboard_Teleop_Wheel_B.Integrator1 =
    QBot2e_Keyboard_Teleop_Wheel_X.Integrator1_CSTATE;

  /* Integrator: '<S4>/Integrator2' */
  QBot2e_Keyboard_Teleop_Wheel_B.Integrator2 =
    QBot2e_Keyboard_Teleop_Wheel_X.Integrator2_CSTATE;

  /* Integrator: '<S4>/Integrator3' */
  QBot2e_Keyboard_Teleop_Wheel_B.Integrator3 =
    QBot2e_Keyboard_Teleop_Wheel_X.Integrator3_CSTATE;
  if (rtmIsMajorTimeStep(QBot2e_Keyboard_Teleop_Wheel_M)) {
    /* S-Function (host_keyboard_block): '<Root>/Host Keyboard' */

    /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Host Keyboard (host_keyboard_block) */
    {
      if (QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_Enabled) {
        t_error result = qthread_section_lock
          (&QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_Lock);
        if (result == 0) {
          t_int offset;
          t_uint mask;
          offset = (QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[0]) >>
            5;
          mask = 1U << ((QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[0])
                        & 31);
          rtb_HostKeyboard_o2[0] =
            ((QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_KeyboardState.keys[offset]
              & mask) != 0);
          offset = (QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[1]) >>
            5;
          mask = 1U << ((QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[1])
                        & 31);
          rtb_HostKeyboard_o2[1] =
            ((QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_KeyboardState.keys[offset]
              & mask) != 0);
          offset = (QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[2]) >>
            5;
          mask = 1U << ((QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[2])
                        & 31);
          rtb_HostKeyboard_o2[2] =
            ((QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_KeyboardState.keys[offset]
              & mask) != 0);
          offset = (QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[3]) >>
            5;
          mask = 1U << ((QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes[3])
                        & 31);
          rtb_HostKeyboard_o2[3] =
            ((QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_KeyboardState.keys[offset]
              & mask) != 0);
          QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_NewData = false;
          qthread_section_unlock
            (&QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_Lock);
        }
      } else {
        rtb_HostKeyboard_o2[0] = false;
        rtb_HostKeyboard_o2[1] = false;
        rtb_HostKeyboard_o2[2] = false;
        rtb_HostKeyboard_o2[3] = false;
      }
    }

    /* Gain: '<Root>/Gain2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     */
    rtb_Add = QBot2e_Keyboard_Teleop_Wheel_P.Gain2_Gain * (real_T)
      rtb_HostKeyboard_o2[0];

    /* Gain: '<Root>/Gain5' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     */
    rtb_Add1 = QBot2e_Keyboard_Teleop_Wheel_P.Gain5_Gain * (real_T)
      rtb_HostKeyboard_o2[1];

    /* Sum: '<Root>/Add' */
    rtb_Add += rtb_Add1;

    /* Gain: '<Root>/Gain6' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     */
    rtb_Add1 = QBot2e_Keyboard_Teleop_Wheel_P.Gain6_Gain * (real_T)
      rtb_HostKeyboard_o2[2];

    /* Sum: '<Root>/Add1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Gain: '<Root>/Gain4'
     */
    rtb_Add1 += QBot2e_Keyboard_Teleop_Wheel_P.Gain4_Gain * (real_T)
      rtb_HostKeyboard_o2[3];

    /* Gain: '<S7>/mm to m' incorporates:
     *  Gain: '<S7>/ encoder rotation to wheel rotation (gear ratio)'
     *  Gain: '<S7>/ticks to encoder rotation'
     *  Gain: '<S7>/wheel radious (mm)'
     */
    QBot2e_Keyboard_Teleop_Wheel_B.mmtom =
      QBot2e_Keyboard_Teleop_Wheel_P.tickstoencoderrotation_Gain *
      rtb_HILRead1_o2[0] *
      QBot2e_Keyboard_Teleop_Wheel_P.encoderrotationtowheelrotationg *
      QBot2e_Keyboard_Teleop_Wheel_P.wheelradiousmm_Gain *
      QBot2e_Keyboard_Teleop_Wheel_P.mmtom_Gain;

    /* Constant: '<S8>/x0' */
    QBot2e_Keyboard_Teleop_Wheel_B.x0 = QBot2e_Keyboard_Teleop_Wheel_P.x0_Value;
  }

  /* Integrator: '<S8>/Integrator1' */
  if (QBot2e_Keyboard_Teleop_Wheel_DW.Integrator1_IWORK != 0) {
    QBot2e_Keyboard_Teleop_Wheel_X.Integrator1_CSTATE_l =
      QBot2e_Keyboard_Teleop_Wheel_B.x0;
  }

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/wn'
   *  Constant: '<S8>/zt'
   *  Integrator: '<S8>/Integrator1'
   *  Integrator: '<S8>/Integrator2'
   *  Product: '<S8>/Product2'
   *  Sum: '<S8>/Sum'
   *  Sum: '<S8>/Sum1'
   */
  QBot2e_Keyboard_Teleop_Wheel_B.Product_f =
    ((QBot2e_Keyboard_Teleop_Wheel_B.mmtom -
      QBot2e_Keyboard_Teleop_Wheel_X.Integrator1_CSTATE_l) -
     QBot2e_Keyboard_Teleop_Wheel_X.Integrator2_CSTATE_m *
     QBot2e_Keyboard_Teleop_Wheel_P.Constant_Value_d *
     QBot2e_Keyboard_Teleop_Wheel_P.SecondOrderLowPassFilter2_inp_j) *
    QBot2e_Keyboard_Teleop_Wheel_P.SecondOrderLowPassFilter2_input;

  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<S8>/wn'
   *  Integrator: '<S8>/Integrator2'
   */
  QBot2e_Keyboard_Teleop_Wheel_B.Product1 =
    QBot2e_Keyboard_Teleop_Wheel_P.SecondOrderLowPassFilter2_input *
    QBot2e_Keyboard_Teleop_Wheel_X.Integrator2_CSTATE_m;
  if (rtmIsMajorTimeStep(QBot2e_Keyboard_Teleop_Wheel_M)) {
    /* Gain: '<S9>/mm to m' incorporates:
     *  Gain: '<S9>/ encoder rotation to wheel rotation (gear ratio)'
     *  Gain: '<S9>/ticks to encoder rotation'
     *  Gain: '<S9>/wheel radious (mm)'
     */
    QBot2e_Keyboard_Teleop_Wheel_B.mmtom_p =
      QBot2e_Keyboard_Teleop_Wheel_P.tickstoencoderrotation_Gain_n *
      rtb_HILRead1_o2[1] *
      QBot2e_Keyboard_Teleop_Wheel_P.encoderrotationtowheelrotatio_d *
      QBot2e_Keyboard_Teleop_Wheel_P.wheelradiousmm_Gain_m *
      QBot2e_Keyboard_Teleop_Wheel_P.mmtom_Gain_n;

    /* Constant: '<S10>/x0' */
    QBot2e_Keyboard_Teleop_Wheel_B.x0_o =
      QBot2e_Keyboard_Teleop_Wheel_P.x0_Value_g;
  }

  /* Integrator: '<S10>/Integrator1' */
  if (QBot2e_Keyboard_Teleop_Wheel_DW.Integrator1_IWORK_o != 0) {
    QBot2e_Keyboard_Teleop_Wheel_X.Integrator1_CSTATE_f =
      QBot2e_Keyboard_Teleop_Wheel_B.x0_o;
  }

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/wn'
   *  Constant: '<S10>/zt'
   *  Integrator: '<S10>/Integrator1'
   *  Integrator: '<S10>/Integrator2'
   *  Product: '<S10>/Product2'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S10>/Sum1'
   */
  QBot2e_Keyboard_Teleop_Wheel_B.Product_d =
    ((QBot2e_Keyboard_Teleop_Wheel_B.mmtom_p -
      QBot2e_Keyboard_Teleop_Wheel_X.Integrator1_CSTATE_f) -
     QBot2e_Keyboard_Teleop_Wheel_X.Integrator2_CSTATE_g *
     QBot2e_Keyboard_Teleop_Wheel_P.Constant_Value_p *
     QBot2e_Keyboard_Teleop_Wheel_P.SecondOrderLowPassFilter2_inp_n) *
    QBot2e_Keyboard_Teleop_Wheel_P.SecondOrderLowPassFilter2_inp_d;

  /* Product: '<S10>/Product1' incorporates:
   *  Constant: '<S10>/wn'
   *  Integrator: '<S10>/Integrator2'
   */
  QBot2e_Keyboard_Teleop_Wheel_B.Product1_n =
    QBot2e_Keyboard_Teleop_Wheel_P.SecondOrderLowPassFilter2_inp_d *
    QBot2e_Keyboard_Teleop_Wheel_X.Integrator2_CSTATE_g;
  if (rtmIsMajorTimeStep(QBot2e_Keyboard_Teleop_Wheel_M)) {
    /* S-Function (hil_write_block): '<S12>/HIL Write' */

    /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/QBot 2e Basic Motor Commands and Sensor Measurement/QBot2e_IO_Basic/HIL Write (hil_write_block) */
    {
      t_error result;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILWrite_OtherBuffer[0] = rtb_Add;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILWrite_OtherBuffer[1] = rtb_Add1;
      result = hil_write(QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         QBot2e_Keyboard_Teleop_Wheel_P.HILWrite_other_channels,
                         2U,
                         NULL,
                         NULL,
                         NULL,
                         &QBot2e_Keyboard_Teleop_Wheel_DW.HILWrite_OtherBuffer[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
      }
    }
  }

  /* MATLAB Function: '<S18>/Qbot2_Diff_Drive_Kinematics' */
  /* MATLAB Function 'QBot 2e Full Kinematics (No Gyro)/Qbot2e_Diff_Drive_Kinematics/Qbot2_Diff_Drive_Kinematics': '<S20>:1' */
  /* '<S20>:1:6' */
  rtb_Stepend_time = (QBot2e_Keyboard_Teleop_Wheel_B.Product1_n +
                      QBot2e_Keyboard_Teleop_Wheel_B.Product1) * 0.5;

  /* '<S20>:1:7' */
  QBot2e_Keyboard_Teleop_Wheel_B.Omega =
    (QBot2e_Keyboard_Teleop_Wheel_B.Product1 -
     QBot2e_Keyboard_Teleop_Wheel_B.Product1_n) * 4.25531914893617;

  /* MATLAB Function: '<S19>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' incorporates:
   *  Integrator: '<S19>/Integrator'
   */
  /* MATLAB Function 'QBot 2e Full Kinematics (No Gyro)/Qbot2e_Kinematics (No Gyro)/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)': '<S21>:1' */
  /* '<S21>:1:5' */
  QBot2e_Keyboard_Teleop_Wheel_B.x_dot = cos
    (QBot2e_Keyboard_Teleop_Wheel_X.Integrator_CSTATE) * rtb_Stepend_time;

  /* '<S21>:1:6' */
  QBot2e_Keyboard_Teleop_Wheel_B.y_dot = sin
    (QBot2e_Keyboard_Teleop_Wheel_X.Integrator_CSTATE) * rtb_Stepend_time;

  /* '<S21>:1:7' */
  QBot2e_Keyboard_Teleop_Wheel_B.psi_dot = QBot2e_Keyboard_Teleop_Wheel_B.Omega;
}

/* Model update function for TID0 */
void QBot2e_Keyboard_Teleop_Wheel_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Atomic SubSystem: '<S3>/Bias Removal' */
  /* Update for Enabled SubSystem: '<S11>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (rtmIsMajorTimeStep(QBot2e_Keyboard_Teleop_Wheel_M) &&
      QBot2e_Keyboard_Teleop_Wheel_DW.EnabledMovingAverage_MODE) {
    /* Update for UnitDelay: '<S17>/Unit Delay' */
    QBot2e_Keyboard_Teleop_Wheel_DW.UnitDelay_DSTATE =
      QBot2e_Keyboard_Teleop_Wheel_B.Count;

    /* Update for UnitDelay: '<S13>/Sum( k=1,n-1, x(k) )' */
    QBot2e_Keyboard_Teleop_Wheel_DW.Sumk1n1xk_DSTATE =
      QBot2e_Keyboard_Teleop_Wheel_B.Sum;
  }

  /* End of Update for SubSystem: '<S11>/Enabled Moving Average' */
  /* End of Update for SubSystem: '<S3>/Bias Removal' */

  /* Update for Integrator: '<S8>/Integrator1' */
  QBot2e_Keyboard_Teleop_Wheel_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S10>/Integrator1' */
  QBot2e_Keyboard_Teleop_Wheel_DW.Integrator1_IWORK_o = 0;
  if (rtmIsMajorTimeStep(QBot2e_Keyboard_Teleop_Wheel_M)) {
    rt_ertODEUpdateContinuousStates(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTick0)) {
    ++QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTickH0;
  }

  QBot2e_Keyboard_Teleop_Wheel_M->Timing.t[0] = rtsiGetSolverStopTime
    (&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTick1)) {
    ++QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTickH1;
  }

  QBot2e_Keyboard_Teleop_Wheel_M->Timing.t[1] =
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTick1 *
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize1 +
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTickH1 *
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void QBot2e_Keyboard_Teleop_Wheel_derivatives(void)
{
  XDot_QBot2e_Keyboard_Teleop_W_T *_rtXdot;
  _rtXdot = ((XDot_QBot2e_Keyboard_Teleop_W_T *)
             QBot2e_Keyboard_Teleop_Wheel_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = QBot2e_Keyboard_Teleop_Wheel_B.psi_dot;

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = QBot2e_Keyboard_Teleop_Wheel_B.x_dot;

  /* Derivatives for Integrator: '<S4>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = QBot2e_Keyboard_Teleop_Wheel_B.y_dot;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_l = QBot2e_Keyboard_Teleop_Wheel_B.Product1;

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_m = QBot2e_Keyboard_Teleop_Wheel_B.Product_f;

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_f = QBot2e_Keyboard_Teleop_Wheel_B.Product1_n;

  /* Derivatives for Integrator: '<S10>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_g = QBot2e_Keyboard_Teleop_Wheel_B.Product_d;

  /* Derivatives for Integrator: '<S19>/Integrator' */
  _rtXdot->Integrator_CSTATE = QBot2e_Keyboard_Teleop_Wheel_B.Omega;
}

/* Model output function for TID2 */
void QBot2e_Keyboard_Teleop_Wheel_output2(void) /* Sample time: [0.04s, 0.0s] */
{
  int32_T i;

  /* S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video3D Initialize (video3d_initialize_block) */
  {
  }

  /* S-Function (video3d_capture_block): '<Root>/Video3D Capture1' */
  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video3D Capture1 (video3d_capture_block) */
  {
    t_video3d_frame frame;
    t_error result;
    result = video3d_stream_get_frame
      (QBot2e_Keyboard_Teleop_Wheel_DW.Video3DCapture1_Stream, &frame);
    if (result >= 0) {
      result = video3d_frame_get_data(frame,
        &QBot2e_Keyboard_Teleop_Wheel_B.Video3DCapture1_o1[0]);

      /* Release the frame to free up its resources */
      video3d_frame_release(frame);
    }

    if (result < 0 && result != -QERR_WOULD_BLOCK) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
    }
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Gain: '<Root>/raw depth to millimeter'
   */
  for (i = 0; i < 307200; i++) {
    QBot2e_Keyboard_Teleop_Wheel_B.Gain[i] = (uint16_T)mul_u32_hiSR
      (QBot2e_Keyboard_Teleop_Wheel_P.Gain_Gain, (uint32_T)
       QBot2e_Keyboard_Teleop_Wheel_P.rawdepthtomillimeter_Gain *
       QBot2e_Keyboard_Teleop_Wheel_B.Video3DCapture1_o1[i], 13U);
  }

  /* End of Gain: '<Root>/Gain' */

  /* S-Function (image_compress_block): '<S5>/Image Compress' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (Depth)/Image Compress (image_compress_block) */
  {
    t_error result = 0;
    size_t image_size = 0;
    result = qjpeg_compress_start
      (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress, true);
    if (result == 0) {
      t_uint8 * image_buffers[8] = {
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[0],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[640],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[1280],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[1920],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[2560],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[3200],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[3840],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[4480]
      };

      uint16_T * data = &QBot2e_Keyboard_Teleop_Wheel_B.Gain[0];
      while (result >= 0 && (t_uint) result < 480) {
        t_uint column;
        if (result <= 480 - 8) {
          /*
           ** Grab eight more rows from the image. Convert from Simulink planar column-major format to
           ** eight uint8 rows for the qjpeg_compress_write function.
           */
          for (column = 0; column < 640; column++) {
            t_uint pixel_offset = result + column * 480;
                        /* RGB tuple index in column major order for Simulink */
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[column] =
              (t_uint8) (data[pixel_offset] >> 8);
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[column + 640]
              = (t_uint8) (data[pixel_offset + 1] >> 8);
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[column + 1280]
              = (t_uint8) (data[pixel_offset + 2] >> 8);
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[column + 1920]
              = (t_uint8) (data[pixel_offset + 3] >> 8);
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[column + 2560]
              = (t_uint8) (data[pixel_offset + 4] >> 8);
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[column + 3200]
              = (t_uint8) (data[pixel_offset + 5] >> 8);
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[column + 3840]
              = (t_uint8) (data[pixel_offset + 6] >> 8);
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[column + 4480]
              = (t_uint8) (data[pixel_offset + 7] >> 8);
          }

          result = qjpeg_compress_write
            (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress,
             image_buffers, 8);
        } else {
          /*
           ** Grab the next row from the image. Convert from Simulink planar column-major format to
           ** a single uint8 row for the qjpeg_compress_write function.
           */
          for (column = 0; column < 640; column++) {
            t_uint pixel_offset = result + column * 480;
                        /* RGB tuple index in column major order for Simulink */
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine[column] =
              (t_uint8) (data[pixel_offset] >> 8);
          }

          result = qjpeg_compress_write
            (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress,
             image_buffers, 1);
        }
      }

      qjpeg_compress_stop(QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress);

      /* Get the final size of the compressed image */
      if (result >= 0) {
        result = qjpeg_compress_get_fixed_memory_destination_size
          (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress, &image_size);
      }
    }

    /* Set the dimensions of the output signal based on the size of the compressed image */
    QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_DIMS1 = (int) image_size;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
    }
  }

  /* S-Function (channel_block): '<S5>/Channel' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (Depth)/Channel (channel_block) */
  {
    struct channel_info {
      t_channel_header header;
    } info;

    size_t width = 1;
    QBot2e_Keyboard_Teleop_Wheel_B.Channel = CHANNEL_0;
    info.header.data_type_id = 3;
    info.header.channel = 0;
    info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
    info.header.num_dimensions = 1;
    width *= QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_DIMS1;
    info.header.dimension[0] =
      QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_DIMS1;
    channel_fifo_add((t_channel_fifo)
                     QBot2e_Keyboard_Teleop_Wheel_DW.Channel_PWORK.Fifo,
                     &info.header,
                     &QBot2e_Keyboard_Teleop_Wheel_B.ImageCompress[0], width *
                     sizeof(uint8_T));
  }

  /* S-Function (video3d_capture_block): '<Root>/Video3D Capture' */
  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video3D Capture (video3d_capture_block) */
  {
    t_video3d_frame frame;
    t_error result;
    result = video3d_stream_get_frame
      (QBot2e_Keyboard_Teleop_Wheel_DW.Video3DCapture_Stream, &frame);
    if (result >= 0) {
      result = video3d_frame_get_data(frame,
        &QBot2e_Keyboard_Teleop_Wheel_B.Video3DCapture_o1[0]);

      /* Release the frame to free up its resources */
      video3d_frame_release(frame);
    }

    if (result < 0 && result != -QERR_WOULD_BLOCK) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
    }
  }

  /* S-Function (image_compress_block): '<S6>/Image Compress' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (RGB)/Image Compress (image_compress_block) */
  {
    t_error result = 0;
    size_t image_size = 0;
    result = qjpeg_compress_start
      (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b, true);
    if (result == 0) {
      t_uint8 * image_buffers[8] = {
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[0],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[1920],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[3840],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[5760],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[7680],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[9600],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[11520],
        &QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[13440]
      };

      uint8_T * r_data;
      uint8_T * g_data;
      uint8_T * b_data;
      r_data = &QBot2e_Keyboard_Teleop_Wheel_B.Video3DCapture_o1[0];
      g_data = r_data + 307200;
      b_data = g_data + 307200;
      while (result >= 0 && (t_uint) result < 480) {
        t_uint column;
        if (result <= 480 - 8) {
          /*
           ** Grab eight more rows from the image. Convert from Simulink planar column-major format to
           ** eight uint8 rows for the qjpeg_compress_write function.
           */
          for (column = 0; column < 640; column++) {
            t_uint pixel_offset = result + column * 480;
                        /* RGB tuple index in column major order for Simulink */
            t_uint scan_offset = column * 3;
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset]
              = r_data[pixel_offset];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 1920] = r_data[pixel_offset + 1];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 3840] = r_data[pixel_offset + 2];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 5760] = r_data[pixel_offset + 3];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 7680] = r_data[pixel_offset + 4];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 9600] = r_data[pixel_offset + 5];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 11520] = r_data[pixel_offset + 6];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 13440] = r_data[pixel_offset + 7];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 1] = g_data[pixel_offset];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 1921] = g_data[pixel_offset + 1];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 3841] = g_data[pixel_offset + 2];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 5761] = g_data[pixel_offset + 3];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 7681] = g_data[pixel_offset + 4];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 9601] = g_data[pixel_offset + 5];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 11521] = g_data[pixel_offset + 6];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 13441] = g_data[pixel_offset + 7];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 2] = b_data[pixel_offset];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 1922] = b_data[pixel_offset + 1];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 3842] = b_data[pixel_offset + 2];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 5762] = b_data[pixel_offset + 3];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 7682] = b_data[pixel_offset + 4];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 9602] = b_data[pixel_offset + 5];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 11522] = b_data[pixel_offset + 6];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 13442] = b_data[pixel_offset + 7];
          }

          result = qjpeg_compress_write
            (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b,
             image_buffers, 8);
        } else {
          /*
           ** Grab the next row from the image. Convert from Simulink planar column-major format to
           ** a single uint8 row for the qjpeg_compress_write function.
           */
          for (column = 0; column < 640; column++) {
            t_uint pixel_offset = result + column * 480;
                        /* RGB tuple index in column major order for Simulink */
            t_uint scan_offset = column * 3;
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset]
              = r_data[pixel_offset];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 1] = g_data[pixel_offset];
            QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c[scan_offset
              + 2] = b_data[pixel_offset];
          }

          result = qjpeg_compress_write
            (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b,
             image_buffers, 1);
        }
      }

      qjpeg_compress_stop
        (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b);

      /* Get the final size of the compressed image */
      if (result >= 0) {
        result = qjpeg_compress_get_fixed_memory_destination_size
          (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b, &image_size);
      }
    }

    /* Set the dimensions of the output signal based on the size of the compressed image */
    QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_DIMS1_g = (int) image_size;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
    }
  }

  /* S-Function (channel_block): '<S6>/Channel' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (RGB)/Channel (channel_block) */
  {
    struct channel_info {
      t_channel_header header;
    } info;

    size_t width = 1;
    QBot2e_Keyboard_Teleop_Wheel_B.Channel_i = CHANNEL_1;
    info.header.data_type_id = 3;
    info.header.channel = 1;
    info.header.flags = CHANNEL_FLAG_VARIABLE_SIZE;
    info.header.num_dimensions = 1;
    width *= QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_DIMS1_g;
    info.header.dimension[0] =
      QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_DIMS1_g;
    channel_fifo_add((t_channel_fifo)
                     QBot2e_Keyboard_Teleop_Wheel_DW.Channel_PWORK_n.Fifo,
                     &info.header,
                     &QBot2e_Keyboard_Teleop_Wheel_B.ImageCompress_b[0], width *
                     sizeof(uint8_T));
  }
}

/* Model update function for TID2 */
void QBot2e_Keyboard_Teleop_Wheel_update2(void) /* Sample time: [0.04s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTick2)) {
    ++QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTickH2;
  }

  QBot2e_Keyboard_Teleop_Wheel_M->Timing.t[2] =
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTick2 *
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize2 +
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.clockTickH2 *
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void QBot2e_Keyboard_Teleop_Wheel_output(int_T tid)
{
  switch (tid) {
   case 0 :
    QBot2e_Keyboard_Teleop_Wheel_output0();
    break;

   case 2 :
    QBot2e_Keyboard_Teleop_Wheel_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void QBot2e_Keyboard_Teleop_Wheel_update(int_T tid)
{
  switch (tid) {
   case 0 :
    QBot2e_Keyboard_Teleop_Wheel_update0();
    break;

   case 2 :
    QBot2e_Keyboard_Teleop_Wheel_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void QBot2e_Keyboard_Teleop_Wheel_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qbot2e", "0",
                      &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
       "pwm0_en=1;pwm0_pin=12;pwm1_en=1;pwm1_pin=13;", 45);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
      return;
    }

    if ((QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AIPStart && !is_switching)
        || (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AIPEnter &&
            is_switching)) {
      result = hil_set_analog_input_ranges
        (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AIChannels, 6U,
         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AILow,
         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
       QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DIChannels, 31U,
       QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOChannels, 4U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
      return;
    }

    if ((QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOStart && !is_switching) ||
        (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOEnter && is_switching))
    {
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits[0] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOInitial;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits[1] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOInitial;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits[2] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOInitial;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits[3] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOInitial;
      result = hil_write_digital
        (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOChannels, 4U, (t_boolean
          *) &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
        return;
      }
    }

    if ((QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIPStart && !is_switching)
        || (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIPEnter &&
            is_switching)) {
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_QuadratureModes[0] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIQuadrature;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_QuadratureModes[1] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
        return;
      }
    }

    if ((QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIStart && !is_switching) ||
        (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIEnter && is_switching))
    {
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_InitialEICounts[0] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIInitial;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_InitialEICounts[1] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIChannels, 2U,
         &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
        return;
      }
    }

    if ((QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POPStart && !is_switching)
        || (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POPEnter &&
            is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[0] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POModes;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[1] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POModes;
      result = hil_set_pwm_mode
        (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POChannels, 2U,
         (t_pwm_mode *)
         &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
        return;
      }

      if (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[0] ==
          PWM_DUTY_CYCLE_MODE ||
          QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[0] ==
          PWM_ONE_SHOT_MODE ||
          QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[0] ==
          PWM_TIME_MODE ||
          QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[0] ==
          PWM_RAW_MODE) {
        QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
          = (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POChannels[0]);
        QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
          = QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POFrequency;
        num_duty_cycle_modes++;
      } else {
        QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedChans[1U -
          num_frequency_modes] =
          (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POChannels[0]);
        QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedFreqs[1U -
          num_frequency_modes] =
          QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POFrequency;
        num_frequency_modes++;
      }

      if (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[1] ==
          PWM_DUTY_CYCLE_MODE ||
          QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[1] ==
          PWM_ONE_SHOT_MODE ||
          QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[1] ==
          PWM_TIME_MODE ||
          QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[1] ==
          PWM_RAW_MODE) {
        QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
          = (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POChannels[1]);
        QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
          = QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POFrequency;
        num_duty_cycle_modes++;
      } else {
        QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedChans[1U -
          num_frequency_modes] =
          (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POChannels[1]);
        QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedFreqs[1U -
          num_frequency_modes] =
          QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POFrequency;
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
           &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
           &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
          return;
        }
      }

      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[0] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POConfiguration;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[1] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POConfiguration;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POAlignValues[0] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POAlignment;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POAlignValues[1] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POAlignment;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POPolarityVals[0] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POPolarity;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POPolarityVals[1] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POPolarity;
      result = hil_set_pwm_configuration
        (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POChannels, 2U,
         (t_pwm_configuration *)
         &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
        return;
      }
    }

    if ((QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POStart && !is_switching) ||
        (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POEnter && is_switching))
    {
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POValues[0] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POInitial;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POValues[1] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POInitial;
      result = hil_write_pwm(QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POChannels, 2U,
        &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
        return;
      }
    }

    if ((QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOStart && !is_switching) ||
        (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOEnter && is_switching))
    {
      result = hil_write_other
        (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOChannels, 4U,
         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (host_initialize_block): '<Root>/Host Initialize' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Host Keyboard (host_keyboard_block) */
  {
    qthread_section_init(&QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_Lock,
                         NULL);
  }

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Host Initialize (host_initialize_block) */
  {
    t_error result;
    QBot2e_Keyboard_Teleop_Wheel_B.HostInitialize_o1 = HOST_STATE_NOT_LISTENING;
    result = extmode_svr_register_connected_callback
      (host_extmode_svr_connected_callback,
       host_extmode_svr_disconnected_callback, NULL,
       &QBot2e_Keyboard_Teleop_Wheel_DW.HostInitialize_ConnectedHandle);
    if (result == 0) {
      result = extmode_svr_register_custom_action(EXT_MODE_ACTION_HOST_INTERFACE,
        host_extmode_svr_custom_action_callback, NULL);
    }

    QBot2e_Keyboard_Teleop_Wheel_B.HostInitialize_o2 = result;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
    }

    if (rtExtModeQuarcIsConnected()) {
      /* Invoke connected callbacks explicitly since Simulink was already connected when MdlStart called */
      host_extmode_svr_connected_callback(NULL);
    }
  }

  /* Start for Atomic SubSystem: '<S3>/Bias Removal' */
  /* Start for Enabled SubSystem: '<S11>/Enabled Moving Average' */
  QBot2e_Keyboard_Teleop_Wheel_DW.EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S11>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S11>/Switch Case' */
  QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S3>/Bias Removal' */

  /* Start for Constant: '<S8>/x0' */
  QBot2e_Keyboard_Teleop_Wheel_B.x0 = QBot2e_Keyboard_Teleop_Wheel_P.x0_Value;

  /* Start for Constant: '<S10>/x0' */
  QBot2e_Keyboard_Teleop_Wheel_B.x0_o =
    QBot2e_Keyboard_Teleop_Wheel_P.x0_Value_g;

  /* Start for S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video3D Initialize (video3d_initialize_block) */
  {
    t_error result;
    result = video3d_open("0",
                          &QBot2e_Keyboard_Teleop_Wheel_DW.Video3DInitialize_Video3D);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (video3d_capture_block): '<Root>/Video3D Capture1' */
  {
    t_error result;
    result = video3d_stream_open
      (QBot2e_Keyboard_Teleop_Wheel_DW.Video3DInitialize_Video3D,
       VIDEO3D_STREAM_DEPTH,
       QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_stream_index, 25.0, 640,
       480,
       IMAGE_FORMAT_COL_MAJOR_GREYSCALE, IMAGE_DATA_TYPE_UINT16,
       &QBot2e_Keyboard_Teleop_Wheel_DW.Video3DCapture1_Stream);
    if (result >= 0) {
      t_video3d_property config_properties[4];
      t_double config_values[4];
      t_uint num_config_properties = 0;
      if (QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Preset != 21) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_VISUAL_PRESET;
        config_values[num_config_properties] = (t_video3d_visual_preset)
          (QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Preset - 1);
        num_config_properties++;
      }

      if (QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Emitter != 3) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_ENABLE_EMITTER;
        config_values[num_config_properties] =
          (QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Emitter == 1) ? 1.0 :
          0.0;
        num_config_properties++;
      }

      config_properties[num_config_properties] =
        VIDEO3D_PROPERTY_ENABLE_AUTO_WHITE_BALANCE;
      config_values[num_config_properties] = 1.0;
      num_config_properties++;
      config_properties[num_config_properties] =
        VIDEO3D_PROPERTY_ENABLE_AUTO_EXPOSURE;
      config_values[num_config_properties] = 1.0;
      num_config_properties++;
      if (num_config_properties > 0) {
        video3d_stream_set_properties
          (QBot2e_Keyboard_Teleop_Wheel_DW.Video3DCapture1_Stream,
           config_properties, num_config_properties, config_values);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_compress_block): '<S5>/Image Compress' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (Depth)/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress, 640, 480,
           COLOR_SPACE_GRAYSCALE);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress,
           QBot2e_Keyboard_Teleop_Wheel_P.ImageCompress_Quality);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress,
           &QBot2e_Keyboard_Teleop_Wheel_B.ImageCompress[0], 307200);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close
          (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S5>/Channel' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (Depth)/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(0, sizeof(uint8_T), 1, 307200, 1,
      (t_channel_fifo *) &QBot2e_Keyboard_Teleop_Wheel_DW.Channel_PWORK.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
    }
  }

  /* Start for S-Function (video3d_capture_block): '<Root>/Video3D Capture' */
  {
    t_error result;
    result = video3d_stream_open
      (QBot2e_Keyboard_Teleop_Wheel_DW.Video3DInitialize_Video3D,
       VIDEO3D_STREAM_COLOR,
       QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_stream_index, 25.0, 640,
       480,
       IMAGE_FORMAT_COL_MAJOR_PLANAR_RGB, IMAGE_DATA_TYPE_UINT8,
       &QBot2e_Keyboard_Teleop_Wheel_DW.Video3DCapture_Stream);
    if (result >= 0) {
      t_video3d_property config_properties[4];
      t_double config_values[4];
      t_uint num_config_properties = 0;
      if (QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Preset != 21) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_VISUAL_PRESET;
        config_values[num_config_properties] = (t_video3d_visual_preset)
          (QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Preset - 1);
        num_config_properties++;
      }

      if (QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Emitter != 3) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_ENABLE_EMITTER;
        config_values[num_config_properties] =
          (QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Emitter == 1) ? 1.0 :
          0.0;
        num_config_properties++;
      }

      config_properties[num_config_properties] =
        VIDEO3D_PROPERTY_ENABLE_AUTO_WHITE_BALANCE;
      config_values[num_config_properties] = 1.0;
      num_config_properties++;
      config_properties[num_config_properties] =
        VIDEO3D_PROPERTY_ENABLE_AUTO_EXPOSURE;
      config_values[num_config_properties] = 1.0;
      num_config_properties++;
      if (num_config_properties > 0) {
        video3d_stream_set_properties
          (QBot2e_Keyboard_Teleop_Wheel_DW.Video3DCapture_Stream,
           config_properties, num_config_properties, config_values);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
    }
  }

  /* Start for S-Function (image_compress_block): '<S6>/Image Compress' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (RGB)/Image Compress (image_compress_block) */
  {
    t_error result = qjpeg_compress_open
      (&QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b);
    if (result == 0) {
      do {
        result = qjpeg_compress_set_image_properties
          (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b, 640, 480,
           COLOR_SPACE_RGB);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_quality
          (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b,
           QBot2e_Keyboard_Teleop_Wheel_P.ImageCompress_Quality_e);
        if (result < 0) {
          break;
        }

        result = qjpeg_compress_set_fixed_memory_destination
          (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b,
           &QBot2e_Keyboard_Teleop_Wheel_B.ImageCompress_b[0], 921600);
        if (result < 0) {
          break;
        }
      } while (false);

      if (result < 0) {
        qjpeg_compress_close
          (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
    }
  }

  /* Start for S-Function (channel_block): '<S6>/Channel' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (RGB)/Channel (channel_block) */
  {
    t_error result;
    result = channel_fifo_create(1, sizeof(uint8_T), 1, 921600, 1,
      (t_channel_fifo *) &QBot2e_Keyboard_Teleop_Wheel_DW.Channel_PWORK_n.Fifo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
    }
  }

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  QBot2e_Keyboard_Teleop_Wheel_X.Integrator1_CSTATE =
    QBot2e_Keyboard_Teleop_Wheel_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator2' */
  QBot2e_Keyboard_Teleop_Wheel_X.Integrator2_CSTATE =
    QBot2e_Keyboard_Teleop_Wheel_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator3' */
  QBot2e_Keyboard_Teleop_Wheel_X.Integrator3_CSTATE =
    QBot2e_Keyboard_Teleop_Wheel_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' incorporates:
   *  Integrator: '<S10>/Integrator1'
   */
  if (rtmIsFirstInitCond(QBot2e_Keyboard_Teleop_Wheel_M)) {
    QBot2e_Keyboard_Teleop_Wheel_X.Integrator1_CSTATE_l = 0.0;
    QBot2e_Keyboard_Teleop_Wheel_X.Integrator1_CSTATE_f = 0.0;
  }

  QBot2e_Keyboard_Teleop_Wheel_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S8>/Integrator1' */

  /* InitializeConditions for Integrator: '<S8>/Integrator2' */
  QBot2e_Keyboard_Teleop_Wheel_X.Integrator2_CSTATE_m =
    QBot2e_Keyboard_Teleop_Wheel_P.Integrator2_IC_j;

  /* InitializeConditions for Integrator: '<S10>/Integrator1' */
  QBot2e_Keyboard_Teleop_Wheel_DW.Integrator1_IWORK_o = 1;

  /* InitializeConditions for Integrator: '<S10>/Integrator2' */
  QBot2e_Keyboard_Teleop_Wheel_X.Integrator2_CSTATE_g =
    QBot2e_Keyboard_Teleop_Wheel_P.Integrator2_IC_jb;

  /* InitializeConditions for Integrator: '<S19>/Integrator' */
  QBot2e_Keyboard_Teleop_Wheel_X.Integrator_CSTATE =
    QBot2e_Keyboard_Teleop_Wheel_P.Integrator_IC;

  /* InitializeConditions for S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video3D Initialize (video3d_initialize_block) */
  {
    if (rtmIsFirstInitCond(QBot2e_Keyboard_Teleop_Wheel_M)) {
      t_error result = video3d_start_streaming
        (QBot2e_Keyboard_Teleop_Wheel_DW.Video3DInitialize_Video3D);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
        return;
      }
    }
  }

  /* SystemInitialize for Atomic SubSystem: '<S3>/Bias Removal' */
  /* SystemInitialize for Enabled SubSystem: '<S11>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  QBot2e_Keyboard_Teleop_Wheel_DW.UnitDelay_DSTATE =
    QBot2e_Keyboard_Teleop_Wheel_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S13>/Sum( k=1,n-1, x(k) )' */
  QBot2e_Keyboard_Teleop_Wheel_DW.Sumk1n1xk_DSTATE =
    QBot2e_Keyboard_Teleop_Wheel_P.Sumk1n1xk_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S11>/Enabled Moving Average' */

  /* SystemInitialize for IfAction SubSystem: '<S11>/Switch Case Action Subsystem' */
  /* SystemInitialize for Outport: '<S14>/zero' */
  QBot2e_Keyboard_Teleop_Wheel_B.Constant =
    QBot2e_Keyboard_Teleop_Wheel_P.zero_Y0;

  /* End of SystemInitialize for SubSystem: '<S11>/Switch Case Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S11>/Switch Case Action Subsystem1' */
  /* SystemInitialize for Outport: '<S15>/Vbiased' */
  QBot2e_Keyboard_Teleop_Wheel_B.Vin = QBot2e_Keyboard_Teleop_Wheel_P.Vbiased_Y0;

  /* End of SystemInitialize for SubSystem: '<S11>/Switch Case Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S11>/Switch Case Action Subsystem2' */
  /* SystemInitialize for Outport: '<S16>/Vunbiased' */
  QBot2e_Keyboard_Teleop_Wheel_B.VVavg =
    QBot2e_Keyboard_Teleop_Wheel_P.Vunbiased_Y0;

  /* End of SystemInitialize for SubSystem: '<S11>/Switch Case Action Subsystem2' */
  /* End of SystemInitialize for SubSystem: '<S3>/Bias Removal' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(QBot2e_Keyboard_Teleop_Wheel_M)) {
    rtmSetFirstInitCond(QBot2e_Keyboard_Teleop_Wheel_M, 0);
  }
}

/* Model terminate function */
void QBot2e_Keyboard_Teleop_Wheel_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card);
    hil_monitor_stop_all(QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card);
    is_switching = false;
    if ((QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOTerminate &&
         !is_switching) || (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOExit &&
         is_switching)) {
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits[0] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOFinal;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits[1] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOFinal;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits[2] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOFinal;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits[3] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOFinal;
      num_final_digital_outputs = 4U;
    }

    if ((QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POTerminate &&
         !is_switching) || (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POExit &&
         is_switching)) {
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POValues[0] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POFinal;
      QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POValues[1] =
        QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POFinal;
      num_final_pwm_outputs = 2U;
    }

    if ((QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOTerminate &&
         !is_switching) || (QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOExit &&
         is_switching)) {
      num_final_other_outputs = 4U;
    }

    if (0
        || num_final_pwm_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card
                         , NULL, 0
                         ,
                         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         ,
                         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         ,
                         QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , NULL
                         ,
                         &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POValues[
                         0]
                         , (t_boolean *)
                         &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits[0]
                         , QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
             QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POChannels,
             num_final_pwm_outputs,
             &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
             QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card,
             QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOChannels,
             num_final_other_outputs,
             QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card);
    hil_monitor_delete_all(QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card);
    hil_close(QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card);
    QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (host_initialize_block): '<Root>/Host Initialize' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Host Initialize (host_initialize_block) */
  {
    extmode_svr_unregister_custom_action(EXT_MODE_ACTION_HOST_INTERFACE);
    extmode_svr_unregister_connected_callback
      (QBot2e_Keyboard_Teleop_Wheel_DW.HostInitialize_ConnectedHandle);
  }

  /* Terminate for S-Function (host_keyboard_block): '<Root>/Host Keyboard' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Host Keyboard (host_keyboard_block) */
  {
    qthread_section_destroy(&QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_Lock);
  }

  /* Terminate for S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video3D Initialize (video3d_initialize_block) */
  {
    video3d_stop_streaming
      (QBot2e_Keyboard_Teleop_Wheel_DW.Video3DInitialize_Video3D);
    video3d_close(QBot2e_Keyboard_Teleop_Wheel_DW.Video3DInitialize_Video3D);
  }

  /* Terminate for S-Function (image_compress_block): '<S5>/Image Compress' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (Depth)/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close(QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress);
    QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S5>/Channel' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (Depth)/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo)
                         QBot2e_Keyboard_Teleop_Wheel_DW.Channel_PWORK.Fifo);
    QBot2e_Keyboard_Teleop_Wheel_DW.Channel_PWORK.Fifo = NULL;
  }

  /* Terminate for S-Function (image_compress_block): '<S6>/Image Compress' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (RGB)/Image Compress (image_compress_block) */
  {
    qjpeg_compress_close
      (QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b);
    QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b = NULL;
  }

  /* Terminate for S-Function (channel_block): '<S6>/Channel' */

  /* S-Function Block: QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (RGB)/Channel (channel_block) */
  {
    channel_fifo_destroy((t_channel_fifo)
                         QBot2e_Keyboard_Teleop_Wheel_DW.Channel_PWORK_n.Fifo);
    QBot2e_Keyboard_Teleop_Wheel_DW.Channel_PWORK_n.Fifo = NULL;
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
  if (tid == 1)
    tid = 0;
  QBot2e_Keyboard_Teleop_Wheel_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  QBot2e_Keyboard_Teleop_Wheel_update(tid);
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
  QBot2e_Keyboard_Teleop_Wheel_initialize();
}

void MdlTerminate(void)
{
  QBot2e_Keyboard_Teleop_Wheel_terminate();
}

/* Registration function */
RT_MODEL_QBot2e_Keyboard_Tele_T *QBot2e_Keyboard_Teleop_Wheel(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)QBot2e_Keyboard_Teleop_Wheel_M, 0,
                sizeof(RT_MODEL_QBot2e_Keyboard_Tele_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
                          &QBot2e_Keyboard_Teleop_Wheel_M->Timing.simTimeStep);
    rtsiSetTPtr(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo, &rtmGetTPtr
                (QBot2e_Keyboard_Teleop_Wheel_M));
    rtsiSetStepSizePtr(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
                       &QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize0);
    rtsiSetdXPtr(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
                 &QBot2e_Keyboard_Teleop_Wheel_M->derivs);
    rtsiSetContStatesPtr(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo, (real_T **)
                         &QBot2e_Keyboard_Teleop_Wheel_M->contStates);
    rtsiSetNumContStatesPtr(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
      &QBot2e_Keyboard_Teleop_Wheel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
      &QBot2e_Keyboard_Teleop_Wheel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
       &QBot2e_Keyboard_Teleop_Wheel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
       &QBot2e_Keyboard_Teleop_Wheel_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
                          (&rtmGetErrorStatus(QBot2e_Keyboard_Teleop_Wheel_M)));
    rtsiSetRTModelPtr(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
                      QBot2e_Keyboard_Teleop_Wheel_M);
  }

  rtsiSetSimTimeStep(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
                     MAJOR_TIME_STEP);
  QBot2e_Keyboard_Teleop_Wheel_M->intgData.f[0] =
    QBot2e_Keyboard_Teleop_Wheel_M->odeF[0];
  QBot2e_Keyboard_Teleop_Wheel_M->contStates = ((real_T *)
    &QBot2e_Keyboard_Teleop_Wheel_X);
  rtsiSetSolverData(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo, (void *)
                    &QBot2e_Keyboard_Teleop_Wheel_M->intgData);
  rtsiSetSolverName(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      QBot2e_Keyboard_Teleop_Wheel_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.sampleTimes =
      (&QBot2e_Keyboard_Teleop_Wheel_M->Timing.sampleTimesArray[0]);
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.offsetTimes =
      (&QBot2e_Keyboard_Teleop_Wheel_M->Timing.offsetTimesArray[0]);

    /* task periods */
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.sampleTimes[0] = (0.0);
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.sampleTimes[1] = (0.01);
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.sampleTimes[2] = (0.04);

    /* task offsets */
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.offsetTimes[0] = (0.0);
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.offsetTimes[1] = (0.0);
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(QBot2e_Keyboard_Teleop_Wheel_M,
             &QBot2e_Keyboard_Teleop_Wheel_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = QBot2e_Keyboard_Teleop_Wheel_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      QBot2e_Keyboard_Teleop_Wheel_M->Timing.perTaskSampleHitsArray;
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    QBot2e_Keyboard_Teleop_Wheel_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(QBot2e_Keyboard_Teleop_Wheel_M, -1);
  QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize0 = 0.01;
  QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize1 = 0.01;
  QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize2 = 0.04;
  rtmSetFirstInitCond(QBot2e_Keyboard_Teleop_Wheel_M, 1);

  /* External mode info */
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.checksums[0] = (1827389757U);
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.checksums[1] = (924461286U);
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.checksums[2] = (3403631129U);
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.checksums[3] = (4275206613U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    QBot2e_Keyboard_Teleop_Wheel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &QBot2e_Keyboard_Teleop_Wheel_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[2] = (sysRanDType *)
      &QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem_Subsy;
    systemRan[3] = (sysRanDType *)
      &QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[4] = (sysRanDType *)
      &QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(QBot2e_Keyboard_Teleop_Wheel_M->extModeInfo,
      &QBot2e_Keyboard_Teleop_Wheel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(QBot2e_Keyboard_Teleop_Wheel_M->extModeInfo,
                        QBot2e_Keyboard_Teleop_Wheel_M->Sizes.checksums);
    rteiSetTPtr(QBot2e_Keyboard_Teleop_Wheel_M->extModeInfo, rtmGetTPtr
                (QBot2e_Keyboard_Teleop_Wheel_M));
  }

  QBot2e_Keyboard_Teleop_Wheel_M->solverInfoPtr =
    (&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo);
  QBot2e_Keyboard_Teleop_Wheel_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo, 0.01);
  rtsiSetSolverMode(&QBot2e_Keyboard_Teleop_Wheel_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  QBot2e_Keyboard_Teleop_Wheel_M->blockIO = ((void *)
    &QBot2e_Keyboard_Teleop_Wheel_B);
  (void) memset(((void *) &QBot2e_Keyboard_Teleop_Wheel_B), 0,
                sizeof(B_QBot2e_Keyboard_Teleop_Whee_T));

  {
    QBot2e_Keyboard_Teleop_Wheel_B.Channel = CHANNEL_0;
    QBot2e_Keyboard_Teleop_Wheel_B.Channel_i = CHANNEL_0;
  }

  /* parameters */
  QBot2e_Keyboard_Teleop_Wheel_M->defaultParam = ((real_T *)
    &QBot2e_Keyboard_Teleop_Wheel_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &QBot2e_Keyboard_Teleop_Wheel_X;
    QBot2e_Keyboard_Teleop_Wheel_M->contStates = (x);
    (void) memset((void *)&QBot2e_Keyboard_Teleop_Wheel_X, 0,
                  sizeof(X_QBot2e_Keyboard_Teleop_Whee_T));
  }

  /* states (dwork) */
  QBot2e_Keyboard_Teleop_Wheel_M->dwork = ((void *)
    &QBot2e_Keyboard_Teleop_Wheel_DW);
  (void) memset((void *)&QBot2e_Keyboard_Teleop_Wheel_DW, 0,
                sizeof(DW_QBot2e_Keyboard_Teleop_Whe_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    QBot2e_Keyboard_Teleop_Wheel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 27;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.numContStates = (8);/* Number of continuous states */
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.numY = (0);/* Number of model outputs */
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.numU = (0);/* Number of model inputs */
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.numSampTimes = (3);/* Number of sample times */
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.numBlocks = (90);/* Number of blocks */
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.numBlockIO = (35);/* Number of block outputs */
  QBot2e_Keyboard_Teleop_Wheel_M->Sizes.numBlockPrms = (220);/* Sum of parameter "widths" */
  return QBot2e_Keyboard_Teleop_Wheel_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
