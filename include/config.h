#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#define VFD_PIN 13

#define LCD_CLK 7
#define LCD_DIN 6
#define LCD_DC 5
#define LCD_CS 4
#define LCD_RST 3

#define ENCODER_SW 9
#define ENCODER_CLK 2
#define ENCODER_DT 8

void setupPinModes();

#endif
