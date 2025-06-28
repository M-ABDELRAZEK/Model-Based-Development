/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: SolarPanelTracker.h
 *
 * Code generated for Simulink model 'SolarPanelTracker'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Jun 27 18:07:19 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef SolarPanelTracker_h_
#define SolarPanelTracker_h_
#ifndef SolarPanelTracker_COMMON_INCLUDES_
#define SolarPanelTracker_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SolarPanelTracker_COMMON_INCLUDES_ */

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
  real_T ServoStepAngle;               /* '<S1>/ServoTrackerSystem' */
  uint8_T is_active_c3_SolarPanelTracker;/* '<S1>/ServoTrackerSystem' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T LDR_UR;                       /* '<Root>/LDR_UR' */
  real_T LDR_BR;                       /* '<Root>/LDR_BR' */
  real_T LDR_UL;                       /* '<Root>/LDR_UL' */
  real_T LDR_BL;                       /* '<Root>/LDR_BL' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T ServoPlateRotation;           /* '<Root>/ServoPlateRotation' */
  real_T ServoPanelRotation;           /* '<Root>/ServoPanelRotation' */
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
extern void SolarPanelTracker_initialize(void);
extern void SolarPanelTracker_step(void);

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
 * '<Root>' : 'SolarPanelTracker'
 * '<S1>'   : 'SolarPanelTracker/SolarPanelTracker'
 * '<S2>'   : 'SolarPanelTracker/SolarPanelTracker/ServoTrackerSystem'
 * '<S3>'   : 'SolarPanelTracker/SolarPanelTracker/VoltageConversion'
 */
#endif                                 /* SolarPanelTracker_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
