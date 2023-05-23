/*
 * QBot2e_Inverse_Kinematics_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QBot2e_Inverse_Kinematics".
 *
 * Model version              : 1.954
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue May 23 12:57:35 2023
 *
 * Target selection: quarc_linux_pi_3.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_QBot2e_Inverse_Kinematics_private_h_
#define RTW_HEADER_QBot2e_Inverse_Kinematics_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "QBot2e_Inverse_Kinematics.h"

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern void QBo_Qbot2_Diff_Drive_Kinematics(real_T rtu_vL, real_T rtu_vR,
  B_Qbot2_Diff_Drive_Kinematics_T *localB);
extern void Qbot2_KinematicsVfWtox_doty_dot(real_T rtu_vC, real_T rtu_Omega,
  real_T rtu_psi, B_Qbot2_KinematicsVfWtox_doty_T *localB);

/* private model entry point functions */
extern void QBot2e_Inverse_Kinematics_derivatives(void);

#endif                     /* RTW_HEADER_QBot2e_Inverse_Kinematics_private_h_ */