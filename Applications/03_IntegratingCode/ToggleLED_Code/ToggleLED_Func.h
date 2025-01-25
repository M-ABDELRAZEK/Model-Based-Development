/*
 * File: ToggleLED_Func.h
 *
 * Code generated for Simulink model 'ToggleLED_Func'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jan 23 18:54:48 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ToggleLED_Func_h_
#define RTW_HEADER_ToggleLED_Func_h_
#ifndef ToggleLED_Func_COMMON_INCLUDES_
#define ToggleLED_Func_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ToggleLED_Func_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  boolean_T UnitDelay_DSTATE;          /* '<S1>/Unit Delay' */
} DW;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T LedState;                  /* '<Root>/LedState' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void ToggleLED_Func_initialize(void);
extern void ToggleLED_Func_step(void);

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
 * '<Root>' : 'ToggleLED_Func'
 * '<S1>'   : 'ToggleLED_Func/ToggleLED_Func'
 */
#endif                                 /* RTW_HEADER_ToggleLED_Func_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
