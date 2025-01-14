/*
 * File: IrrigationControlSystem.h
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

#ifndef RTW_HEADER_IrrigationControlSystem_h_
#define RTW_HEADER_IrrigationControlSystem_h_
#ifndef IrrigationControlSystem_COMMON_INCLUDES_
#define IrrigationControlSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                            /* IrrigationControlSystem_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  boolean_T Memory_PreviousInput;      /* '<S3>/Memory' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S3>/Logic'
   */
  boolean_T Logic_table[16];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Moisture_Sensor;              /* '<Root>/Moisture_Sensor' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T SW_Pump1;                  /* '<Root>/SW_Pump1' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void IrrigationControlSystem_initialize(void);
extern void IrrigationControlSystem_step(void);

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
 * '<Root>' : 'IrrigationControlSystem'
 * '<S1>'   : 'IrrigationControlSystem/Compare To Constant2'
 * '<S2>'   : 'IrrigationControlSystem/Compare To Constant3'
 * '<S3>'   : 'IrrigationControlSystem/S-R Flip-Flop'
 */
#endif                               /* RTW_HEADER_IrrigationControlSystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
