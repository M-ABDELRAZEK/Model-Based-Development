/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: TPS_SWC.c
 *
 * Code generated for Simulink model 'TPS_SWC'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Apr 10 15:59:45 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "TPS_SWC.h"
#include "rtwtypes.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void TPS_SWC_step(void)
{
  boolean_T rtb_OR;
  boolean_T rtb_OR1;

  /* Outputs for Atomic SubSystem: '<Root>/TPS_SWC' */
  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Inport: '<Root>/TPS_vSensor1'
   *  Inport: '<Root>/TPS_vSensor2'
   *  RelationalOperator: '<S2>/Relational Operator4'
   *  Sum: '<S2>/Add'
   */
  if (rtU.TPS_vSensor1 + rtU.TPS_vSensor2 != 5.0F) {
    /* Logic: '<S2>/OR1' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant3'
     *  RelationalOperator: '<S2>/Relational Operator2'
     *  RelationalOperator: '<S2>/Relational Operator3'
     */
    rtb_OR1 = ((rtU.TPS_vSensor2 > 4.5F) || (rtU.TPS_vSensor2 < 0.5F));

    /* Logic: '<S2>/OR' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  RelationalOperator: '<S2>/Relational Operator'
     *  RelationalOperator: '<S2>/Relational Operator1'
     */
    rtb_OR = ((rtU.TPS_vSensor1 > 4.5F) || (rtU.TPS_vSensor1 < 0.5F));

    /* Switch: '<S3>/Switch1' incorporates:
     *  Logic: '<S3>/AND'
     *  Logic: '<S3>/AND1'
     *  Logic: '<S3>/NOT'
     *  Logic: '<S3>/NOT1'
     *  Switch: '<S3>/Switch2'
     */
    if ((!rtb_OR) && rtb_OR1) {
      /* Outport: '<Root>/TPS_stOperationMode' incorporates:
       *  Constant: '<S3>/Downgraded_Mode_Sen_1'
       */
      rtY.TPS_stOperationMode = Downgraded_Mode_Sen_1;
    } else if (rtb_OR && (!rtb_OR1)) {
      /* Switch: '<S3>/Switch2' incorporates:
       *  Constant: '<S3>/Downgraded_Mode_Sen_2'
       *  Outport: '<Root>/TPS_stOperationMode'
       */
      rtY.TPS_stOperationMode = Downgraded_Mode_Sen_2;
    } else {
      /* Outport: '<Root>/TPS_stOperationMode' incorporates:
       *  Constant: '<S3>/Failure_Mode'
       *  Switch: '<S3>/Switch2'
       */
      rtY.TPS_stOperationMode = Failure_Mode;
    }

    /* End of Switch: '<S3>/Switch1' */
  } else {
    /* Outport: '<Root>/TPS_stOperationMode' incorporates:
     *  Constant: '<S3>/Normal_Mode'
     */
    rtY.TPS_stOperationMode = Normal_Mode;
  }

  /* End of Switch: '<S3>/Switch' */
  /* End of Outputs for SubSystem: '<Root>/TPS_SWC' */
}

/* Model initialize function */
void TPS_SWC_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
