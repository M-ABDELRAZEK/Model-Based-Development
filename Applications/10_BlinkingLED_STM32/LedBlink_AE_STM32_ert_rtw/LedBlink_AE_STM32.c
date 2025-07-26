/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: LedBlink_AE_STM32.c
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

#include "LedBlink_AE_STM32.h"

/* External outputs (root outports fed by signals with default storage) */
ExtY_LedBlink_AE_STM32_T LedBlink_AE_STM32_Y;

/* Real-time model */
static RT_MODEL_LedBlink_AE_STM32_T LedBlink_AE_STM32_M_;
RT_MODEL_LedBlink_AE_STM32_T *const LedBlink_AE_STM32_M = &LedBlink_AE_STM32_M_;

/* Model step function */
void LedBlink_AE_STM32_step(void)
{
  /* Logic: '<S1>/NOT' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  LedBlink_AE_STM32_Y.LedState = !LedBlink_AE_STM32_Y.LedState;
}

/* Model initialize function */
void LedBlink_AE_STM32_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void LedBlink_AE_STM32_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
