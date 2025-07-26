/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: LedBlink_AE_STM32.h
 *
 * Code generated for Simulink model 'LedBlink_AE_STM32'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sat Jul 26 18:17:53 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef LedBlink_AE_STM32_h_
#define LedBlink_AE_STM32_h_
#ifndef LedBlink_AE_STM32_COMMON_INCLUDES_
#define LedBlink_AE_STM32_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LedBlink_AE_STM32_COMMON_INCLUDES_ */

#include "LedBlink_AE_STM32_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T LedState;                  /* '<Root>/LedState' */
} ExtY_LedBlink_AE_STM32_T;

/* Real-time Model Data Structure */
struct tag_RTM_LedBlink_AE_STM32_T {
  const char_T * volatile errorStatus;
};

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_LedBlink_AE_STM32_T LedBlink_AE_STM32_Y;

/* Model entry point functions */
extern void LedBlink_AE_STM32_initialize(void);
extern void LedBlink_AE_STM32_step(void);
extern void LedBlink_AE_STM32_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LedBlink_AE_STM32_T *const LedBlink_AE_STM32_M;

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
 * '<Root>' : 'LedBlink_AE_STM32'
 * '<S1>'   : 'LedBlink_AE_STM32/LedBlink_AE_STM32'
 */
#endif                                 /* LedBlink_AE_STM32_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
