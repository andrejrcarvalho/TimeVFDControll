#include <Arduino.h>

#include "config.h"
#include "screen.h"
#include "settings.h"

Settings settings;
Screen screen;

unsigned long targetTime;
unsigned long offTime = 10;
unsigned long onTime = 10;
bool status = true;
String strString = "";


void setup() {
  Serial.begin(9600);

  setupPinModes();

  attachInterrupt(digitalPinToInterrupt(ENCODER_CLK), encoderInterrupt, CHANGE);

  settings.loadFromEEPROM();
  screen.begin(&settings);

  Serial.println("STATING....");
}

void loop() {
  unsigned long curTime = millis();

  if (curTime >= targetTime) {
    if (status) {  // ON TIME -> OFF TIME
      targetTime = curTime + (settings.offTime * 1000);
      digitalWrite(VFD_PIN, HIGH);
      strString = "OFF";
      Serial.println("OFF");
    } else {  // OFF TIM -> ON TIME
      targetTime = curTime + (settings.onTime * 1000);
      digitalWrite(VFD_PIN, LOW);
      strString = "ON";
      Serial.println("ON");
    }
    status = !status;
  }
  screen.tic(&strString);

}
