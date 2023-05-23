/*
 * QBot2e_Keyboard_Teleop_Wheel.h
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

#ifndef RTW_HEADER_QBot2e_Keyboard_Teleop_Wheel_h_
#define RTW_HEADER_QBot2e_Keyboard_Teleop_Wheel_h_
#include <math.h>
#include <string.h>
#ifndef QBot2e_Keyboard_Teleop_Wheel_COMMON_INCLUDES_
# define QBot2e_Keyboard_Teleop_Wheel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_string.h"
#include "quanser_host.h"
#include "extmode_support.h"
#include "quanser_host_keyboard.h"
#include "quanser_memory.h"
#include "quanser_section.h"
#include "quanser_video3d.h"
#include "quanser_types.h"
#include "quanser_image_processing.h"
#include "quanser_channel.h"
#include "quanser_extern.h"
#endif                       /* QBot2e_Keyboard_Teleop_Wheel_COMMON_INCLUDES_ */

#include "QBot2e_Keyboard_Teleop_Wheel_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
# define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
# define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
# define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
# define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
# define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
# define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
# define rtmGettimingBridge(rtm)       ()
#endif

#ifndef rtmSettimingBridge
# define rtmSettimingBridge(rtm, val)  ()
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define QBot2e_Keyboard_Teleop_Wheel_rtModel RT_MODEL_QBot2e_Keyboard_Tele_T

/* Block signals (default storage) */
typedef struct {
  uint8_T ImageCompress_b[921600];     /* '<S6>/Image Compress' */
  uint16_T Gain[307200];               /* '<Root>/Gain' */
  uint8_T ImageCompress[307200];       /* '<S5>/Image Compress' */
  t_uint64 Video3DCapture1_o2;         /* '<Root>/Video3D Capture1' */
  t_uint64 Video3DCapture_o2;          /* '<Root>/Video3D Capture' */
  real_T HILRead1_o1;                  /* '<S12>/HIL Read1' */
  real_T HILRead1_o4;                  /* '<S12>/HIL Read1' */
  real_T Product;                      /* '<S3>/Product' */
  real_T Integrator1;                  /* '<S4>/Integrator1' */
  real_T Integrator2;                  /* '<S4>/Integrator2' */
  real_T Integrator3;                  /* '<S4>/Integrator3' */
  real_T mmtom;                        /* '<S7>/mm to m' */
  real_T x0;                           /* '<S8>/x0' */
  real_T Product_f;                    /* '<S8>/Product' */
  real_T Product1;                     /* '<S8>/Product1' */
  real_T mmtom_p;                      /* '<S9>/mm to m' */
  real_T x0_o;                         /* '<S10>/x0' */
  real_T Product_d;                    /* '<S10>/Product' */
  real_T Product1_n;                   /* '<S10>/Product1' */
  real_T Video3DCapture1_o3;           /* '<Root>/Video3D Capture1' */
  real_T Video3DCapture_o3;            /* '<Root>/Video3D Capture' */
  real_T x_dot; /* '<S19>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T y_dot; /* '<S19>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T psi_dot;
                /* '<S19>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T Omega;                        /* '<S18>/Qbot2_Diff_Drive_Kinematics' */
  real_T VVavg;                        /* '<S16>/V-Vavg' */
  real_T Vin;                          /* '<S15>/Vin' */
  real_T Constant;                     /* '<S14>/Constant' */
  real_T Count;                        /* '<S17>/Count' */
  real_T Sum;                          /* '<S13>/Sum' */
  real_T div;                          /* '<S13>/div' */
  t_channel Channel;                   /* '<S5>/Channel' */
  t_channel Channel_i;                 /* '<S6>/Channel' */
  int32_T HostInitialize_o2;           /* '<Root>/Host Initialize' */
  uint16_T Video3DCapture1_o1[307200]; /* '<Root>/Video3D Capture1' */
  uint8_T HostInitialize_o1;           /* '<Root>/Host Initialize' */
  uint8_T Video3DCapture_o1[921600];   /* '<Root>/Video3D Capture' */
} B_QBot2e_Keyboard_Teleop_Whee_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  qthread_section_t HostKeyboard_Lock; /* '<Root>/Host Keyboard' */
  t_keyboard_state HostKeyboard_KeyboardState;/* '<Root>/Host Keyboard' */
  real_T UnitDelay_DSTATE;             /* '<S17>/Unit Delay' */
  real_T Sumk1n1xk_DSTATE;             /* '<S13>/Sum( k=1,n-1, x(k) )' */
  real_T HILInitialize_FilterFrequency[2];/* '<Root>/HIL Initialize' */
  real_T HILInitialize_POSortedFreqs[2];/* '<Root>/HIL Initialize' */
  real_T HILInitialize_POValues[2];    /* '<Root>/HIL Initialize' */
  real_T HILInitialize_OOValues[4];    /* '<Root>/HIL Initialize' */
  real_T XYFigure_XBuffer[1000];       /* '<Root>/XY Figure' */
  real_T XYFigure_YBuffer[1000];       /* '<Root>/XY Figure' */
  real_T HILWrite_OtherBuffer[2];      /* '<S12>/HIL Write' */
  t_extmode_svr_connected_handle HostInitialize_ConnectedHandle;/* '<Root>/Host Initialize' */
  t_jpeg_compress ImageCompress_Compress;/* '<S5>/Image Compress' */
  t_jpeg_compress ImageCompress_Compress_b;/* '<S6>/Image Compress' */
  t_video3d Video3DInitialize_Video3D; /* '<Root>/Video3D Initialize' */
  t_video3d Video3DCapture1_Video3D;   /* '<Root>/Video3D Capture1' */
  t_video3d Video3DCapture_Video3D;    /* '<Root>/Video3D Capture' */
  t_video3d_stream Video3DCapture1_Stream;/* '<Root>/Video3D Capture1' */
  t_video3d_stream Video3DCapture_Stream;/* '<Root>/Video3D Capture' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  void *HILRead1_PWORK;                /* '<S12>/HIL Read1' */
  void *HILWrite_PWORK;                /* '<S12>/HIL Write' */
  struct {
    void *Fifo;
  } Channel_PWORK;                     /* '<S5>/Channel' */

  struct {
    void *Fifo;
  } Channel_PWORK_n;                   /* '<S6>/Channel' */

  int32_T HILInitialize_DOStates[4];   /* '<Root>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[2];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[2];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POModeValues[2];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POAlignValues[2];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POPolarityVals[2];/* '<Root>/HIL Initialize' */
  int32_T HILRead1_EncoderBuffer[2];   /* '<S12>/HIL Read1' */
  int32_T ImageCompress_DIMS1;         /* '<S5>/Image Compress' */
  int32_T ImageCompress_DIMS1_g;       /* '<S6>/Image Compress' */
  uint32_T HILInitialize_POSortedChans[2];/* '<Root>/HIL Initialize' */
  int_T XYFigure_IWORK[2];             /* '<Root>/XY Figure' */
  int_T Integrator1_IWORK;             /* '<S8>/Integrator1' */
  int_T Integrator1_IWORK_o;           /* '<S10>/Integrator1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S11>/Switch Case' */
  int8_T SwitchCaseActionSubsystem2_Subs;
                                     /* '<S11>/Switch Case Action Subsystem2' */
  int8_T SwitchCaseActionSubsystem1_Subs;
                                     /* '<S11>/Switch Case Action Subsystem1' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                      /* '<S11>/Switch Case Action Subsystem' */
  int8_T EnabledMovingAverage_SubsysRanB;/* '<S11>/Enabled Moving Average' */
  uint8_T ImageCompress_ScanLine[5120];/* '<S5>/Image Compress' */
  uint8_T ImageCompress_ScanLine_c[15360];/* '<S6>/Image Compress' */
  boolean_T HILInitialize_DOBits[4];   /* '<Root>/HIL Initialize' */
  boolean_T XYFigure_IsFull;           /* '<Root>/XY Figure' */
  boolean_T HostKeyboard_NewData;      /* '<Root>/Host Keyboard' */
  boolean_T EnabledMovingAverage_MODE; /* '<S11>/Enabled Moving Average' */
} DW_QBot2e_Keyboard_Teleop_Whe_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S4>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<S4>/Integrator3' */
  real_T Integrator1_CSTATE_l;         /* '<S8>/Integrator1' */
  real_T Integrator2_CSTATE_m;         /* '<S8>/Integrator2' */
  real_T Integrator1_CSTATE_f;         /* '<S10>/Integrator1' */
  real_T Integrator2_CSTATE_g;         /* '<S10>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S19>/Integrator' */
} X_QBot2e_Keyboard_Teleop_Whee_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S4>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<S4>/Integrator3' */
  real_T Integrator1_CSTATE_l;         /* '<S8>/Integrator1' */
  real_T Integrator2_CSTATE_m;         /* '<S8>/Integrator2' */
  real_T Integrator1_CSTATE_f;         /* '<S10>/Integrator1' */
  real_T Integrator2_CSTATE_g;         /* '<S10>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S19>/Integrator' */
} XDot_QBot2e_Keyboard_Teleop_W_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S4>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S4>/Integrator2' */
  boolean_T Integrator3_CSTATE;        /* '<S4>/Integrator3' */
  boolean_T Integrator1_CSTATE_l;      /* '<S8>/Integrator1' */
  boolean_T Integrator2_CSTATE_m;      /* '<S8>/Integrator2' */
  boolean_T Integrator1_CSTATE_f;      /* '<S10>/Integrator1' */
  boolean_T Integrator2_CSTATE_g;      /* '<S10>/Integrator2' */
  boolean_T Integrator_CSTATE;         /* '<S19>/Integrator' */
} XDis_QBot2e_Keyboard_Teleop_W_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            QBot2e_Keyboard_Teleop_Wheel_B
#define BlockIO                        B_QBot2e_Keyboard_Teleop_Whee_T
#define rtX                            QBot2e_Keyboard_Teleop_Wheel_X
#define ContinuousStates               X_QBot2e_Keyboard_Teleop_Whee_T
#define rtXdot                         QBot2e_Keyboard_Teleop_Whe_XDot
#define StateDerivatives               XDot_QBot2e_Keyboard_Teleop_W_T
#define tXdis                          QBot2e_Keyboard_Teleop_Whe_XDis
#define StateDisabled                  XDis_QBot2e_Keyboard_Teleop_W_T
#define rtP                            QBot2e_Keyboard_Teleop_Wheel_P
#define Parameters                     P_QBot2e_Keyboard_Teleop_Whee_T
#define rtDWork                        QBot2e_Keyboard_Teleop_Wheel_DW
#define D_Work                         DW_QBot2e_Keyboard_Teleop_Whe_T

/* Parameters (default storage) */
struct P_QBot2e_Keyboard_Teleop_Whee_T_ {
  real_T BiasRemoval_end_time;         /* Mask Parameter: BiasRemoval_end_time
                                        * Referenced by: '<S11>/Step: end_time'
                                        */
  real_T SecondOrderLowPassFilter2_input;
                              /* Mask Parameter: SecondOrderLowPassFilter2_input
                               * Referenced by: '<S8>/wn'
                               */
  real_T SecondOrderLowPassFilter2_inp_d;
                              /* Mask Parameter: SecondOrderLowPassFilter2_inp_d
                               * Referenced by: '<S10>/wn'
                               */
  real_T SecondOrderLowPassFilter2_inp_j;
                              /* Mask Parameter: SecondOrderLowPassFilter2_inp_j
                               * Referenced by: '<S8>/zt'
                               */
  real_T SecondOrderLowPassFilter2_inp_n;
                              /* Mask Parameter: SecondOrderLowPassFilter2_inp_n
                               * Referenced by: '<S10>/zt'
                               */
  real_T XYFigure_maximum_x;           /* Mask Parameter: XYFigure_maximum_x
                                        * Referenced by: '<Root>/XY Figure'
                                        */
  real_T XYFigure_maximum_y;           /* Mask Parameter: XYFigure_maximum_y
                                        * Referenced by: '<Root>/XY Figure'
                                        */
  real_T XYFigure_minimum_x;           /* Mask Parameter: XYFigure_minimum_x
                                        * Referenced by: '<Root>/XY Figure'
                                        */
  real_T XYFigure_minimum_y;           /* Mask Parameter: XYFigure_minimum_y
                                        * Referenced by: '<Root>/XY Figure'
                                        */
  real_T BiasRemoval_start_time;       /* Mask Parameter: BiasRemoval_start_time
                                        * Referenced by: '<S11>/Step: start_time'
                                        */
  real_T BiasRemoval_switch_id;        /* Mask Parameter: BiasRemoval_switch_id
                                        * Referenced by: '<S11>/Constant'
                                        */
  int32_T XYFigure_update_rate;        /* Mask Parameter: XYFigure_update_rate
                                        * Referenced by: '<Root>/XY Figure'
                                        */
  uint32_T HILRead1_analog_channels; /* Mask Parameter: HILRead1_analog_channels
                                      * Referenced by: '<S12>/HIL Read1'
                                      */
  uint32_T HILRead1_digital_channels[3];
                                    /* Mask Parameter: HILRead1_digital_channels
                                     * Referenced by: '<S12>/HIL Read1'
                                     */
  uint32_T HILRead1_encoder_channels[2];
                                    /* Mask Parameter: HILRead1_encoder_channels
                                     * Referenced by: '<S12>/HIL Read1'
                                     */
  uint32_T HILRead1_other_channels;   /* Mask Parameter: HILRead1_other_channels
                                       * Referenced by: '<S12>/HIL Read1'
                                       */
  uint32_T HILWrite_other_channels[2];/* Mask Parameter: HILWrite_other_channels
                                       * Referenced by: '<S12>/HIL Write'
                                       */
  uint32_T Video3DCapture1_stream_index;
                                 /* Mask Parameter: Video3DCapture1_stream_index
                                  * Referenced by: '<Root>/Video3D Capture1'
                                  */
  uint32_T Video3DCapture_stream_index;
                                  /* Mask Parameter: Video3DCapture_stream_index
                                   * Referenced by: '<Root>/Video3D Capture'
                                   */
  boolean_T Video3DInitialize_active;/* Mask Parameter: Video3DInitialize_active
                                      * Referenced by: '<Root>/Video3D Initialize'
                                      */
  real_T unity_Value;                  /* Expression: 1
                                        * Referenced by: '<S17>/unity'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S17>/Unit Delay'
                                        */
  real_T Sumk1n1xk_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S13>/Sum( k=1,n-1, x(k) )'
                                        */
  real_T zero_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S14>/zero'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Vbiased_Y0;                   /* Expression: [0]
                                        * Referenced by: '<S15>/Vbiased'
                                        */
  real_T Vunbiased_Y0;                 /* Expression: [0]
                                        * Referenced by: '<S16>/Vunbiased'
                                        */
  real_T Stepstart_time_Y0;            /* Expression: 0
                                        * Referenced by: '<S11>/Step: start_time'
                                        */
  real_T Stepstart_time_YFinal;        /* Expression: 1
                                        * Referenced by: '<S11>/Step: start_time'
                                        */
  real_T Stepend_time_Y0;              /* Expression: 0
                                        * Referenced by: '<S11>/Step: end_time'
                                        */
  real_T Stepend_time_YFinal;          /* Expression: 1
                                        * Referenced by: '<S11>/Step: end_time'
                                        */
  real_T HILInitialize_OOTerminate;/* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  real_T HILInitialize_OOExit;    /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<Root>/HIL Initialize'
                                   */
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;    /* Expression: set_other_outputs_at_switch_in
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_OOFinal[4];     /* Expression: final_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh[6];      /* Expression: analog_input_maximums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow[6];       /* Expression: analog_input_minimums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency;    /* Expression: pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial;      /* Expression: initial_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_OOInitial[4];   /* Expression: initial_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator3'
                                        */
  real_T Gain2_Gain;                   /* Expression: -.3
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain5_Gain;                   /* Expression: .3
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Gain6_Gain;                   /* Expression: -.3
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Gain4_Gain;                   /* Expression: .3
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T tickstoencoderrotation_Gain;  /* Expression: 2*pi/52
                                        * Referenced by: '<S7>/ticks to encoder rotation'
                                        */
  real_T encoderrotationtowheelrotationg;/* Expression: 1/49.5833
                                          * Referenced by: '<S7>/ encoder rotation to wheel rotation (gear ratio)'
                                          */
  real_T wheelradiousmm_Gain;          /* Expression: 35
                                        * Referenced by: '<S7>/wheel radious (mm)'
                                        */
  real_T mmtom_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S7>/mm to m'
                                        */
  real_T Constant_Value_d;             /* Expression: 2
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S8>/x0'
                                        */
  real_T Integrator2_IC_j;             /* Expression: 0
                                        * Referenced by: '<S8>/Integrator2'
                                        */
  real_T tickstoencoderrotation_Gain_n;/* Expression: 2*pi/52
                                        * Referenced by: '<S9>/ticks to encoder rotation'
                                        */
  real_T encoderrotationtowheelrotatio_d;/* Expression: 1/49.5833
                                          * Referenced by: '<S9>/ encoder rotation to wheel rotation (gear ratio)'
                                          */
  real_T wheelradiousmm_Gain_m;        /* Expression: 35
                                        * Referenced by: '<S9>/wheel radious (mm)'
                                        */
  real_T mmtom_Gain_n;                 /* Expression: 1/1000
                                        * Referenced by: '<S9>/mm to m'
                                        */
  real_T Constant_Value_p;             /* Expression: 2
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T x0_Value_g;                   /* Expression: input_init
                                        * Referenced by: '<S10>/x0'
                                        */
  real_T Integrator2_IC_jb;            /* Expression: 0
                                        * Referenced by: '<S10>/Integrator2'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S19>/Integrator'
                                        */
  real_T Video3DCapture1_Brightness;   /* Expression: d_brightness
                                        * Referenced by: '<Root>/Video3D Capture1'
                                        */
  real_T Video3DCapture1_Contrast;     /* Expression: d_contrast
                                        * Referenced by: '<Root>/Video3D Capture1'
                                        */
  real_T Video3DCapture1_Hue;          /* Expression: d_hue
                                        * Referenced by: '<Root>/Video3D Capture1'
                                        */
  real_T Video3DCapture1_Saturation;   /* Expression: d_saturation
                                        * Referenced by: '<Root>/Video3D Capture1'
                                        */
  real_T Video3DCapture1_Sharpness;    /* Expression: d_sharpness
                                        * Referenced by: '<Root>/Video3D Capture1'
                                        */
  real_T Video3DCapture1_Gamma;        /* Expression: d_gamma
                                        * Referenced by: '<Root>/Video3D Capture1'
                                        */
  real_T Video3DCapture1_WhiteBalance; /* Expression: d_whitebalance
                                        * Referenced by: '<Root>/Video3D Capture1'
                                        */
  real_T Video3DCapture1_BacklightCompen;/* Expression: d_backlightcompensation
                                          * Referenced by: '<Root>/Video3D Capture1'
                                          */
  real_T Video3DCapture1_Gain;         /* Expression: d_gain
                                        * Referenced by: '<Root>/Video3D Capture1'
                                        */
  real_T Video3DCapture1_Exposure;     /* Expression: d_exposure
                                        * Referenced by: '<Root>/Video3D Capture1'
                                        */
  real_T Video3DCapture1_Emitter;      /* Expression: emitter
                                        * Referenced by: '<Root>/Video3D Capture1'
                                        */
  real_T Video3DCapture_Brightness;    /* Expression: d_brightness
                                        * Referenced by: '<Root>/Video3D Capture'
                                        */
  real_T Video3DCapture_Contrast;      /* Expression: d_contrast
                                        * Referenced by: '<Root>/Video3D Capture'
                                        */
  real_T Video3DCapture_Hue;           /* Expression: d_hue
                                        * Referenced by: '<Root>/Video3D Capture'
                                        */
  real_T Video3DCapture_Saturation;    /* Expression: d_saturation
                                        * Referenced by: '<Root>/Video3D Capture'
                                        */
  real_T Video3DCapture_Sharpness;     /* Expression: d_sharpness
                                        * Referenced by: '<Root>/Video3D Capture'
                                        */
  real_T Video3DCapture_Gamma;         /* Expression: d_gamma
                                        * Referenced by: '<Root>/Video3D Capture'
                                        */
  real_T Video3DCapture_WhiteBalance;  /* Expression: d_whitebalance
                                        * Referenced by: '<Root>/Video3D Capture'
                                        */
  real_T Video3DCapture_BacklightCompens;/* Expression: d_backlightcompensation
                                          * Referenced by: '<Root>/Video3D Capture'
                                          */
  real_T Video3DCapture_Gain;          /* Expression: d_gain
                                        * Referenced by: '<Root>/Video3D Capture'
                                        */
  real_T Video3DCapture_Exposure;      /* Expression: d_exposure
                                        * Referenced by: '<Root>/Video3D Capture'
                                        */
  real_T Video3DCapture_Emitter;       /* Expression: emitter
                                        * Referenced by: '<Root>/Video3D Capture'
                                        */
  int32_T HILInitialize_EIInitial;/* Computed Parameter: HILInitialize_EIInitial
                                   * Referenced by: '<Root>/HIL Initialize'
                                   */
  int32_T HILInitialize_POModes;    /* Computed Parameter: HILInitialize_POModes
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  int32_T HILInitialize_POConfiguration;
                            /* Computed Parameter: HILInitialize_POConfiguration
                             * Referenced by: '<Root>/HIL Initialize'
                             */
  int32_T HILInitialize_POAlignment;
                                /* Computed Parameter: HILInitialize_POAlignment
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  int32_T HILInitialize_POPolarity;
                                 /* Computed Parameter: HILInitialize_POPolarity
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  int32_T HostInitialize_SendBufferSize;
                            /* Computed Parameter: HostInitialize_SendBufferSize
                             * Referenced by: '<Root>/Host Initialize'
                             */
  int32_T HostInitialize_ReceiveBufferSiz;
                          /* Computed Parameter: HostInitialize_ReceiveBufferSiz
                           * Referenced by: '<Root>/Host Initialize'
                           */
  int32_T HostInitialize_ThreadPriority;
                            /* Computed Parameter: HostInitialize_ThreadPriority
                             * Referenced by: '<Root>/Host Initialize'
                             */
  uint32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint32_T HILInitialize_AIChannels[6];
                                 /* Computed Parameter: HILInitialize_AIChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  uint32_T HILInitialize_DIChannels[31];
                                 /* Computed Parameter: HILInitialize_DIChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  uint32_T HILInitialize_DOChannels[4];
                                 /* Computed Parameter: HILInitialize_DOChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIChannels[2];
                                 /* Computed Parameter: HILInitialize_EIChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIQuadrature;
                               /* Computed Parameter: HILInitialize_EIQuadrature
                                * Referenced by: '<Root>/HIL Initialize'
                                */
  uint32_T HILInitialize_POChannels[2];
                                 /* Computed Parameter: HILInitialize_POChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  uint32_T HILInitialize_OOChannels[4];
                                 /* Computed Parameter: HILInitialize_OOChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  uint32_T Video3DCapture1_Preset; /* Computed Parameter: Video3DCapture1_Preset
                                    * Referenced by: '<Root>/Video3D Capture1'
                                    */
  uint32_T ImageCompress_Quality;   /* Computed Parameter: ImageCompress_Quality
                                     * Referenced by: '<S5>/Image Compress'
                                     */
  uint32_T Video3DCapture_Preset;   /* Computed Parameter: Video3DCapture_Preset
                                     * Referenced by: '<Root>/Video3D Capture'
                                     */
  uint32_T ImageCompress_Quality_e;
                                  /* Computed Parameter: ImageCompress_Quality_e
                                   * Referenced by: '<S6>/Image Compress'
                                   */
  uint16_T rawdepthtomillimeter_Gain;
                                /* Computed Parameter: rawdepthtomillimeter_Gain
                                 * Referenced by: '<Root>/raw depth to millimeter'
                                 */
  boolean_T HILInitialize_Active;    /* Computed Parameter: HILInitialize_Active
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_AOTerminate;
                                /* Computed Parameter: HILInitialize_AOTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_AOExit;    /* Computed Parameter: HILInitialize_AOExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_DOTerminate;
                                /* Computed Parameter: HILInitialize_DOTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_DOExit;    /* Computed Parameter: HILInitialize_DOExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_POTerminate;
                                /* Computed Parameter: HILInitialize_POTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_POExit;    /* Computed Parameter: HILInitialize_POExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_CKPStart;/* Computed Parameter: HILInitialize_CKPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKPEnter;/* Computed Parameter: HILInitialize_CKPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKStart;  /* Computed Parameter: HILInitialize_CKStart
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_CKEnter;  /* Computed Parameter: HILInitialize_CKEnter
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AIPStart;/* Computed Parameter: HILInitialize_AIPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AIPEnter;/* Computed Parameter: HILInitialize_AIPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPStart;/* Computed Parameter: HILInitialize_AOPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPEnter;/* Computed Parameter: HILInitialize_AOPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOStart;  /* Computed Parameter: HILInitialize_AOStart
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOEnter;  /* Computed Parameter: HILInitialize_AOEnter
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOReset;  /* Computed Parameter: HILInitialize_AOReset
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOPStart;/* Computed Parameter: HILInitialize_DOPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOPEnter;/* Computed Parameter: HILInitialize_DOPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOStart;  /* Computed Parameter: HILInitialize_DOStart
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOEnter;  /* Computed Parameter: HILInitialize_DOEnter
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOReset;  /* Computed Parameter: HILInitialize_DOReset
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIPStart;/* Computed Parameter: HILInitialize_EIPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIPEnter;/* Computed Parameter: HILInitialize_EIPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIStart;  /* Computed Parameter: HILInitialize_EIStart
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIEnter;  /* Computed Parameter: HILInitialize_EIEnter
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POPStart;/* Computed Parameter: HILInitialize_POPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POPEnter;/* Computed Parameter: HILInitialize_POPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POStart;  /* Computed Parameter: HILInitialize_POStart
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POEnter;  /* Computed Parameter: HILInitialize_POEnter
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POReset;  /* Computed Parameter: HILInitialize_POReset
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_OOReset;  /* Computed Parameter: HILInitialize_OOReset
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOFinal;  /* Computed Parameter: HILInitialize_DOFinal
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOInitial;
                                  /* Computed Parameter: HILInitialize_DOInitial
                                   * Referenced by: '<Root>/HIL Initialize'
                                   */
  boolean_T HostInitialize_RunClient;
                                 /* Computed Parameter: HostInitialize_RunClient
                                  * Referenced by: '<Root>/Host Initialize'
                                  */
  boolean_T HostInitialize_UseWindow;
                                 /* Computed Parameter: HostInitialize_UseWindow
                                  * Referenced by: '<Root>/Host Initialize'
                                  */
  boolean_T HostInitialize_Active;  /* Computed Parameter: HostInitialize_Active
                                     * Referenced by: '<Root>/Host Initialize'
                                     */
  boolean_T HILRead1_Active;           /* Computed Parameter: HILRead1_Active
                                        * Referenced by: '<S12>/HIL Read1'
                                        */
  boolean_T HostKeyboard_Enabled;    /* Computed Parameter: HostKeyboard_Enabled
                                      * Referenced by: '<Root>/Host Keyboard'
                                      */
  boolean_T HostKeyboard_DebugMode;/* Computed Parameter: HostKeyboard_DebugMode
                                    * Referenced by: '<Root>/Host Keyboard'
                                    */
  boolean_T HILWrite_Active;           /* Computed Parameter: HILWrite_Active
                                        * Referenced by: '<S12>/HIL Write'
                                        */
  boolean_T VideoDisplay_UseHardware;
                                 /* Computed Parameter: VideoDisplay_UseHardware
                                  * Referenced by: '<S5>/Video Display'
                                  */
  boolean_T VideoDisplay_UseHardware_c;
                               /* Computed Parameter: VideoDisplay_UseHardware_c
                                * Referenced by: '<S6>/Video Display'
                                */
  uint8_T HostInitialize_URI;          /* Expression: uri_argument
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  uint8_T XYFigure_Mode;               /* Computed Parameter: XYFigure_Mode
                                        * Referenced by: '<Root>/XY Figure'
                                        */
  uint8_T HostKeyboard_ScanCodes[4];
                                   /* Computed Parameter: HostKeyboard_ScanCodes
                                    * Referenced by: '<Root>/Host Keyboard'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_QBot2e_Keyboard_Teleo_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][8];
  ODE1_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_QBot2e_Keyboard_Teleop_Whee_T QBot2e_Keyboard_Teleop_Wheel_P;

/* Block signals (default storage) */
extern B_QBot2e_Keyboard_Teleop_Whee_T QBot2e_Keyboard_Teleop_Wheel_B;

/* Continuous states (default storage) */
extern X_QBot2e_Keyboard_Teleop_Whee_T QBot2e_Keyboard_Teleop_Wheel_X;

/* Block states (default storage) */
extern DW_QBot2e_Keyboard_Teleop_Whe_T QBot2e_Keyboard_Teleop_Wheel_DW;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void QBot2e_Keyboard_Teleop_Wheel_initialize(void);
extern void QBot2e_Keyboard_Teleop_Wheel_output0(void);
extern void QBot2e_Keyboard_Teleop_Wheel_update0(void);
extern void QBot2e_Keyboard_Teleop_Wheel_output(int_T tid);
extern void QBot2e_Keyboard_Teleop_Wheel_update(int_T tid);
extern void QBot2e_Keyboard_Teleop_Wheel_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern QBot2e_Keyboard_Teleop_Wheel_rtModel *QBot2e_Keyboard_Teleop_Wheel(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_QBot2e_Keyboard_Tele_T *const QBot2e_Keyboard_Teleop_Wheel_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'QBot2e_Keyboard_Teleop_Wheel'
 * '<S1>'   : 'QBot2e_Keyboard_Teleop_Wheel/Encoder_to_Velocity1'
 * '<S2>'   : 'QBot2e_Keyboard_Teleop_Wheel/Encoder_to_Velocity2'
 * '<S3>'   : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Basic Motor Commands and Sensor Measurement'
 * '<S4>'   : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Full Kinematics (No Gyro)'
 * '<S5>'   : 'QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (Depth)'
 * '<S6>'   : 'QBot2e_Keyboard_Teleop_Wheel/Video Compressed Display (RGB)'
 * '<S7>'   : 'QBot2e_Keyboard_Teleop_Wheel/Encoder_to_Velocity1/Encoder to Distance'
 * '<S8>'   : 'QBot2e_Keyboard_Teleop_Wheel/Encoder_to_Velocity1/Second-Order Low-Pass Filter2'
 * '<S9>'   : 'QBot2e_Keyboard_Teleop_Wheel/Encoder_to_Velocity2/Encoder to Distance'
 * '<S10>'  : 'QBot2e_Keyboard_Teleop_Wheel/Encoder_to_Velocity2/Second-Order Low-Pass Filter2'
 * '<S11>'  : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Basic Motor Commands and Sensor Measurement/Bias Removal'
 * '<S12>'  : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Basic Motor Commands and Sensor Measurement/QBot2e_IO_Basic'
 * '<S13>'  : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Basic Motor Commands and Sensor Measurement/Bias Removal/Enabled Moving Average'
 * '<S14>'  : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Basic Motor Commands and Sensor Measurement/Bias Removal/Switch Case Action Subsystem'
 * '<S15>'  : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Basic Motor Commands and Sensor Measurement/Bias Removal/Switch Case Action Subsystem1'
 * '<S16>'  : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Basic Motor Commands and Sensor Measurement/Bias Removal/Switch Case Action Subsystem2'
 * '<S17>'  : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Basic Motor Commands and Sensor Measurement/Bias Removal/Enabled Moving Average/Increment'
 * '<S18>'  : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Full Kinematics (No Gyro)/Qbot2e_Diff_Drive_Kinematics'
 * '<S19>'  : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Full Kinematics (No Gyro)/Qbot2e_Kinematics (No Gyro)'
 * '<S20>'  : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Full Kinematics (No Gyro)/Qbot2e_Diff_Drive_Kinematics/Qbot2_Diff_Drive_Kinematics'
 * '<S21>'  : 'QBot2e_Keyboard_Teleop_Wheel/QBot 2e Full Kinematics (No Gyro)/Qbot2e_Kinematics (No Gyro)/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)'
 */
#endif                          /* RTW_HEADER_QBot2e_Keyboard_Teleop_Wheel_h_ */
