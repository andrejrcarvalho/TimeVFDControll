#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdint.h>

#define MODE_TIME_PULSE 0
#define MODE_PULSE 1

class Settings {
 public:
  uint8_t onTime = 0;
  uint8_t offTime = 0;
  
  void loadFromEEPROM();
};

#endif