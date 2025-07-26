/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: PassiveBalancing_SWC.h
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

#ifndef PassiveBalancing_SWC_h_
#define PassiveBalancing_SWC_h_
#ifndef PassiveBalancing_SWC_COMMON_INCLUDES_
#define PassiveBalancing_SWC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                               /* PassiveBalancing_SWC_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_PassiveBalancing_S;/* '<S1>/PassiveBalancing' */
  uint8_T is_c3_PassiveBalancing_SWC;  /* '<S1>/PassiveBalancing' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T SoC1;                         /* '<Root>/SoC1' */
  real_T SoC2;                         /* '<Root>/SoC2' */
  real_T SoC3;                         /* '<Root>/SoC3' */
  real_T SoC4;                         /* '<Root>/SoC4' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T BalCmd;                       /* '<Root>/BalCmd' */
  real_T SW1;                          /* '<Root>/SW1' */
  real_T SW2;                          /* '<Root>/SW2' */
  real_T SW3;                          /* '<Root>/SW3' */
  real_T SW4;                          /* '<Root>/SW4' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void PassiveBalancing_SWC_initialize(void);
extern void PassiveBalancing_SWC_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'PassiveBalancing_SWC'
 * '<S1>'   : 'PassiveBalancing_SWC/SWC'
 * '<S2>'   : 'PassiveBalancing_SWC/SWC/PassiveBalancing'
 */
#endif                                 /* PassiveBalancing_SWC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
