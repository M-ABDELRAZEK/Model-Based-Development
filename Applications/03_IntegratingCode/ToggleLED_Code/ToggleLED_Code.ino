extern "C" {
#include "ToggleLED_Func.h"
#include "rtwtypes.h"
}

void setup() {
  pinMode(12, OUTPUT);
}

void loop() {
  ToggleLED_Func_step();
  digitalWrite(12, rtY.LedState);
  delay(1000);
}
