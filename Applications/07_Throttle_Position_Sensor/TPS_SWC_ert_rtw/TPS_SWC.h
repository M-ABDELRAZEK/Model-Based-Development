/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: TPS_SWC.h
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

#ifndef TPS_SWC_h_
#define TPS_SWC_h_
#ifndef TPS_SWC_COMMON_INCLUDES_
#define TPS_SWC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TPS_SWC_COMMON_INCLUDES_ */

#ifndef DEFINED_TYPEDEF_FOR_TPS_Modes_
#define DEFINED_TYPEDEF_FOR_TPS_Modes_

typedef enum {
  Normal_Mode = 0,                     /* Default value */
  Downgraded_Mode_Sen_1,
  Downgraded_Mode_Sen_2,
  Failure_Mode
} TPS_Modes;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T TPS_vSensor1;               /* '<Root>/TPS_vSensor1' */
  real32_T TPS_vSensor2;               /* '<Root>/TPS_vSensor2' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  TPS_Modes TPS_stOperationMode;       /* '<Root>/TPS_stOperationMode' */
} ExtY;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void TPS_SWC_initialize(void);
extern void TPS_SWC_step(void);

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
 * '<Root>' : 'TPS_SWC'
 * '<S1>'   : 'TPS_SWC/TPS_SWC'
 * '<S2>'   : 'TPS_SWC/TPS_SWC/TPS_FailureDetector'
 * '<S3>'   : 'TPS_SWC/TPS_SWC/TPS_ModeDetector'
 */
#endif                                 /* TPS_SWC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
