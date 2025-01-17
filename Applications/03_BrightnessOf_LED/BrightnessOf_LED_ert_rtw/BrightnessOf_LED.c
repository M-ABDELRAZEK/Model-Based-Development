/*
 * File: BrightnessOf_LED.c
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

#include "BrightnessOf_LED.h"
#include "rtwtypes.h"
#include "BrightnessOf_LED_private.h"
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_BrightnessOf_LED_T BrightnessOf_LED_DW;

/* Real-time model */
static RT_MODEL_BrightnessOf_LED_T BrightnessOf_LED_M_;
RT_MODEL_BrightnessOf_LED_T *const BrightnessOf_LED_M = &BrightnessOf_LED_M_;

/* Model step function */
void BrightnessOf_LED_step(void)
{
  real_T u0;
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (BrightnessOf_LED_DW.obj.SampleTime !=
      BrightnessOf_LED_P.AnalogInput_SampleTime) {
    BrightnessOf_LED_DW.obj.SampleTime =
      BrightnessOf_LED_P.AnalogInput_SampleTime;
  }

  BrightnessOf_LED_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (BrightnessOf_LED_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/PWM' */
  BrightnessOf_LED_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Start for MATLABSystem: '<Root>/PWM' incorporates:
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  u0 = (real_T)((uint32_T)BrightnessOf_LED_P.Gain_Gain * b_varargout_1) *
    3.814697265625E-6;
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  /* MATLABSystem: '<Root>/PWM' */
  MW_PWM_SetDutyCycle(BrightnessOf_LED_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, u0);
}

/* Model initialize function */
void BrightnessOf_LED_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  BrightnessOf_LED_DW.obj.matlabCodegenIsDeleted = false;
  BrightnessOf_LED_DW.obj.SampleTime = BrightnessOf_LED_P.AnalogInput_SampleTime;
  BrightnessOf_LED_DW.obj.isInitialized = 1L;
  BrightnessOf_LED_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  BrightnessOf_LED_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  BrightnessOf_LED_DW.obj_l.matlabCodegenIsDeleted = false;
  BrightnessOf_LED_DW.obj_l.isInitialized = 1L;
  BrightnessOf_LED_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0,
    0.0);
  BrightnessOf_LED_DW.obj_l.isSetupComplete = true;
}

/* Model terminate function */
void BrightnessOf_LED_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!BrightnessOf_LED_DW.obj.matlabCodegenIsDeleted) {
    BrightnessOf_LED_DW.obj.matlabCodegenIsDeleted = true;
    if ((BrightnessOf_LED_DW.obj.isInitialized == 1L) &&
        BrightnessOf_LED_DW.obj.isSetupComplete) {
      BrightnessOf_LED_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (BrightnessOf_LED_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!BrightnessOf_LED_DW.obj_l.matlabCodegenIsDeleted) {
    BrightnessOf_LED_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((BrightnessOf_LED_DW.obj_l.isInitialized == 1L) &&
        BrightnessOf_LED_DW.obj_l.isSetupComplete) {
      BrightnessOf_LED_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (5UL);
      MW_PWM_SetDutyCycle(BrightnessOf_LED_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      BrightnessOf_LED_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (5UL);
      MW_PWM_Close(BrightnessOf_LED_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
