/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: PassiveBalancing_SWC.c
 *
 * Code generated for Simulink model 'PassiveBalancing_SWC'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Jul  8 02:59:05 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "PassiveBalancing_SWC.h"
#include "rtwtypes.h"
#include <math.h>

/* Named constants for Chart: '<S1>/PassiveBalancing' */
#define IN_BalancingOFF                ((uint8_T)1U)
#define IN_BalancingON                 ((uint8_T)2U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static real_T BalOFF(real_T SoC1, real_T SoC2, real_T SoC3, real_T SoC4);
static real_T Min_SoC(real_T SoC1, real_T SoC2, real_T SoC3, real_T SoC4);
static real_T ControlSW(real_T SoC, real_T Low);

/* Function for Chart: '<S1>/PassiveBalancing' */
static real_T BalOFF(real_T SoC1, real_T SoC2, real_T SoC3, real_T SoC4)
{
  real_T out;
  if (fabs(SoC1 - SoC2) > 0.001) {
    if (fabs(SoC1 - SoC3) > 0.001) {
      out = (fabs(SoC1 - SoC4) > 0.001);
    } else {
      out = 0.0;
    }
  } else {
    out = 0.0;
  }

  return out;
}

/* Function for Chart: '<S1>/PassiveBalancing' */
static real_T Min_SoC(real_T SoC1, real_T SoC2, real_T SoC3, real_T SoC4)
{
  return fmin(SoC1, fmin(SoC2, fmin(SoC3, SoC4)));
}

/* Function for Chart: '<S1>/PassiveBalancing' */
static real_T ControlSW(real_T SoC, real_T Low)
{
  return fabs(SoC - Low) > 0.01;
}

/* Model step function */
void PassiveBalancing_SWC_step(void)
{
  real_T Lowest;

  /* Chart: '<S1>/PassiveBalancing' incorporates:
   *  Inport: '<Root>/SoC1'
   *  Inport: '<Root>/SoC2'
   *  Inport: '<Root>/SoC3'
   *  Inport: '<Root>/SoC4'
   */
  if (rtDW.is_active_c3_PassiveBalancing_S == 0) {
    rtDW.is_active_c3_PassiveBalancing_S = 1U;
    rtDW.is_c3_PassiveBalancing_SWC = IN_BalancingON;

    /* Outport: '<Root>/BalCmd' */
    rtY.BalCmd = 1.0;
    Lowest = Min_SoC(rtU.SoC1, rtU.SoC2, rtU.SoC3, rtU.SoC4);

    /* Outport: '<Root>/SW1' incorporates:
     *  Inport: '<Root>/SoC1'
     *  Inport: '<Root>/SoC2'
     *  Inport: '<Root>/SoC3'
     *  Inport: '<Root>/SoC4'
     */
    rtY.SW1 = ControlSW(rtU.SoC1, Lowest);

    /* Outport: '<Root>/SW2' incorporates:
     *  Inport: '<Root>/SoC2'
     */
    rtY.SW2 = ControlSW(rtU.SoC2, Lowest);

    /* Outport: '<Root>/SW3' incorporates:
     *  Inport: '<Root>/SoC3'
     */
    rtY.SW3 = ControlSW(rtU.SoC3, Lowest);

    /* Outport: '<Root>/SW4' incorporates:
     *  Inport: '<Root>/SoC4'
     */
    rtY.SW4 = ControlSW(rtU.SoC4, Lowest);
  } else if (rtDW.is_c3_PassiveBalancing_SWC == IN_BalancingOFF) {
    if (!(BalOFF(rtU.SoC1, rtU.SoC2, rtU.SoC3, rtU.SoC4) != 0.0)) {
      rtDW.is_c3_PassiveBalancing_SWC = IN_BalancingON;

      /* Outport: '<Root>/BalCmd' */
      rtY.BalCmd = 1.0;
      Lowest = Min_SoC(rtU.SoC1, rtU.SoC2, rtU.SoC3, rtU.SoC4);

      /* Outport: '<Root>/SW1' */
      rtY.SW1 = ControlSW(rtU.SoC1, Lowest);

      /* Outport: '<Root>/SW2' */
      rtY.SW2 = ControlSW(rtU.SoC2, Lowest);

      /* Outport: '<Root>/SW3' */
      rtY.SW3 = ControlSW(rtU.SoC3, Lowest);

      /* Outport: '<Root>/SW4' */
      rtY.SW4 = ControlSW(rtU.SoC4, Lowest);
    }

    /* case IN_BalancingON: */
  } else if (BalOFF(rtU.SoC1, rtU.SoC2, rtU.SoC3, rtU.SoC4) != 0.0) {
    rtDW.is_c3_PassiveBalancing_SWC = IN_BalancingOFF;

    /* Outport: '<Root>/BalCmd' */
    rtY.BalCmd = 0.0;
  } else {
    /* Outport: '<Root>/BalCmd' */
    rtY.BalCmd = 1.0;
    Lowest = Min_SoC(rtU.SoC1, rtU.SoC2, rtU.SoC3, rtU.SoC4);

    /* Outport: '<Root>/SW1' */
    rtY.SW1 = ControlSW(rtU.SoC1, Lowest);

    /* Outport: '<Root>/SW2' */
    rtY.SW2 = ControlSW(rtU.SoC2, Lowest);

    /* Outport: '<Root>/SW3' */
    rtY.SW3 = ControlSW(rtU.SoC3, Lowest);

    /* Outport: '<Root>/SW4' */
    rtY.SW4 = ControlSW(rtU.SoC4, Lowest);
  }

  /* End of Chart: '<S1>/PassiveBalancing' */
}

/* Model initialize function */
void PassiveBalancing_SWC_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
