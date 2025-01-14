/*
 * File: IrrigationControlSystem.c
 *
 * Code generated for Simulink model 'IrrigationControlSystem'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jan 14 18:03:55 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "IrrigationControlSystem.h"
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void IrrigationControlSystem_step(void)
{
  real_T rtb_Gain1;
  boolean_T rtb_Logic_idx_0;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Inport: '<Root>/Moisture_Sensor'
   */
  rtb_Gain1 = 0.0196078431372549 * rtU.Moisture_Sensor;

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  Memory: '<S3>/Memory'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   */
  rtb_Logic_idx_0 = rtConstP.Logic_table[((((uint32_T)(rtb_Gain1 <= 2.0) << 1) +
    (uint32_T)(rtb_Gain1 >= 4.0)) << 1) + rtDW.Memory_PreviousInput];

  /* Outport: '<Root>/SW_Pump1' */
  rtY.SW_Pump1 = rtb_Logic_idx_0;

  /* Update for Memory: '<S3>/Memory' */
  rtDW.Memory_PreviousInput = rtb_Logic_idx_0;
}

/* Model initialize function */
void IrrigationControlSystem_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
