
#include "config.h"

void setupPinModes(){
  pinMode(VFD_PIN, OUTPUT);
  pinMode(ENCODER_SW, INPUT);
  pinMode(ENCODER_CLK, INPUT);
  pinMode(ENCODER_DT, INPUT);
}