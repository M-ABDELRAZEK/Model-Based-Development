/*
 * File: BrightnessOf_LED.h
 *
 * Code generated for Simulink model 'BrightnessOf_LED'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Jan 17 03:15:44 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BrightnessOf_LED_h_
#define RTW_HEADER_BrightnessOf_LED_h_
#ifndef BrightnessOf_LED_COMMON_INCLUDES_
#define BrightnessOf_LED_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#endif                                 /* BrightnessOf_LED_COMMON_INCLUDES_ */

#include "BrightnessOf_LED_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_int_h_T obj_l;/* '<Root>/PWM' */
} DW_BrightnessOf_LED_T;

/* Parameters (default storage) */
struct P_BrightnessOf_LED_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_BrightnessOf_LED_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_BrightnessOf_LED_T BrightnessOf_LED_P;

/* Block states (default storage) */
extern DW_BrightnessOf_LED_T BrightnessOf_LED_DW;

/* Model entry point functions */
extern void BrightnessOf_LED_initialize(void);
extern void BrightnessOf_LED_step(void);
extern void BrightnessOf_LED_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BrightnessOf_LED_T *const BrightnessOf_LED_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'BrightnessOf_LED'
 */
#endif                                 /* RTW_HEADER_BrightnessOf_LED_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
