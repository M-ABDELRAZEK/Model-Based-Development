#include "Servo.h"
extern "C"{
  #include "SolarPanelTracker.h"
  #include "rtwtypes.h"
}

#define LDR_UR_PIN A0
#define LDR_BR_PIN A1
#define LDR_UL_PIN A2
#define LDR_BL_PIN A3

Servo ServoPlate_PIN;
Servo ServoPanel_PIN;

void setup() {
  pinMode(LDR_UR_PIN, INPUT);
  pinMode(LDR_BR_PIN, INPUT);
  pinMode(LDR_UL_PIN, INPUT);
  pinMode(LDR_BL_PIN, INPUT);
  
  ServoPlate_PIN.attach(6);
  ServoPanel_PIN.attach(5);
  
  SolarPanelTracker_initialize();
}

void loop() {
  rtU.LDR_UR = analogRead(LDR_UR_PIN);
  rtU.LDR_BR = analogRead(LDR_BR_PIN);
  rtU.LDR_UL = analogRead(LDR_UL_PIN);
  rtU.LDR_BL = analogRead(LDR_BL_PIN);
  
  SolarPanelTracker_step();
  
  ServoPlate_PIN.write(rtY.ServoPlateRotation);
  ServoPanel_PIN.write(rtY.ServoPanelRotation);

  delay(100);
}
