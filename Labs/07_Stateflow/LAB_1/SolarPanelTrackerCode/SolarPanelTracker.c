/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: SolarPanelTracker.c
 *
 * Code generated for Simulink model 'SolarPanelTracker'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Jun 30 19:04:16 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "SolarPanelTracker.h"
#include <math.h>
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void SolarPanelTracker_step(void)
{
  real_T rtb_Add;
  real_T rtb_Add3;
  real_T rtb_Gain;
  real_T rtb_Gain2;
  real_T rtb_Gain3;

  /* Outputs for Atomic SubSystem: '<Root>/SolarPanelTracker' */
  /* Outputs for Atomic SubSystem: '<S1>/VoltageConversion' */
  /* Gain: '<S3>/Gain' incorporates:
   *  Inport: '<Root>/LDR_UR'
   */
  rtb_Gain = 0.0048875855327468231 * rtU.LDR_UR;

  /* Gain: '<S3>/Gain1' incorporates:
   *  Inport: '<Root>/LDR_BR'
   */
  rtb_Gain2 = 0.0048875855327468231 * rtU.LDR_BR;

  /* Sum: '<S3>/Add' */
  rtb_Add = rtb_Gain + rtb_Gain2;

  /* Gain: '<S3>/Gain3' incorporates:
   *  Inport: '<Root>/LDR_BL'
   */
  rtb_Gain3 = 0.0048875855327468231 * rtU.LDR_BL;

  /* Sum: '<S3>/Add3' */
  rtb_Add3 = rtb_Gain2 + rtb_Gain3;

  /* Gain: '<S3>/Gain2' incorporates:
   *  Inport: '<Root>/LDR_UL'
   */
  rtb_Gain2 = 0.0048875855327468231 * rtU.LDR_UL;

  /* Sum: '<S3>/Add1' */
  rtb_Gain3 += rtb_Gain2;

  /* Sum: '<S3>/Add2' */
  rtb_Gain += rtb_Gain2;

  /* End of Outputs for SubSystem: '<S1>/VoltageConversion' */

  /* Chart: '<S1>/ServoTrackerSystem' */
  if (rtDW.is_active_c3_SolarPanelTracker == 0) {
    rtDW.is_active_c3_SolarPanelTracker = 1U;
    if (fabs(rtb_Add - rtb_Gain3) <= 0.5) {
      /* Outport: '<Root>/ServoPanelRotation' */
      rtY.ServoPanelRotation = 0.0;
    } else if (rtb_Add > rtb_Gain3) {
      /* Outport: '<Root>/ServoPanelRotation' */
      rtY.ServoPanelRotation = rtb_Add / 2.0 * 255.0 / 5.0 * rtDW.ServoStepAngle;
    } else {
      /* Outport: '<Root>/ServoPanelRotation' */
      rtY.ServoPanelRotation = rtb_Gain3 / 2.0 * 255.0 / 5.0 *
        rtDW.ServoStepAngle;
    }

    if (fabs(rtb_Gain - rtb_Add3) <= 0.5) {
      /* Outport: '<Root>/ServoPlateRotation' */
      rtY.ServoPlateRotation = 0.0;
    } else if (rtb_Gain > rtb_Add3) {
      /* Outport: '<Root>/ServoPlateRotation' */
      rtY.ServoPlateRotation = rtb_Gain / 2.0 * 255.0 / 5.0 *
        rtDW.ServoStepAngle;
    } else {
      /* Outport: '<Root>/ServoPlateRotation' */
      rtY.ServoPlateRotation = rtb_Add3 / 2.0 * 255.0 / 5.0 *
        rtDW.ServoStepAngle;
    }
  } else {
    if (fabs(rtb_Add - rtb_Gain3) <= 0.5) {
      /* Outport: '<Root>/ServoPanelRotation' */
      rtY.ServoPanelRotation = 0.0;
    } else if (rtb_Add > rtb_Gain3) {
      /* Outport: '<Root>/ServoPanelRotation' */
      rtY.ServoPanelRotation = rtb_Add / 2.0 * 255.0 / 5.0 * rtDW.ServoStepAngle;
    } else {
      /* Outport: '<Root>/ServoPanelRotation' */
      rtY.ServoPanelRotation = rtb_Gain3 / 2.0 * 255.0 / 5.0 *
        rtDW.ServoStepAngle;
    }

    if (fabs(rtb_Gain - rtb_Add3) <= 0.5) {
      /* Outport: '<Root>/ServoPlateRotation' */
      rtY.ServoPlateRotation = 0.0;
    } else if (rtb_Gain > rtb_Add3) {
      /* Outport: '<Root>/ServoPlateRotation' */
      rtY.ServoPlateRotation = rtb_Gain / 2.0 * 255.0 / 5.0 *
        rtDW.ServoStepAngle;
    } else {
      /* Outport: '<Root>/ServoPlateRotation' */
      rtY.ServoPlateRotation = rtb_Add3 / 2.0 * 255.0 / 5.0 *
        rtDW.ServoStepAngle;
    }
  }

  /* End of Chart: '<S1>/ServoTrackerSystem' */
  /* End of Outputs for SubSystem: '<Root>/SolarPanelTracker' */
}

/* Model initialize function */
void SolarPanelTracker_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/SolarPanelTracker' */
  /* SystemInitialize for Chart: '<S1>/ServoTrackerSystem' */
  rtDW.ServoStepAngle = 0.70588235294117652;

  /* End of SystemInitialize for SubSystem: '<Root>/SolarPanelTracker' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
