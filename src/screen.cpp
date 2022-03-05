#include "screen.h"

void Screen::begin(Settings* settings) {
  _settings = settings;
  _display.begin();
  _display.setContrast(0);
  _display.clearDisplay();
  _display.setContrast(15);
  bootScreen();
}

void Screen::bootScreen() {
  _display.setTextSize(1);
  _display.setTextColor(BLACK, WHITE);
  _display.setCursor(10, 10);
  _display.print("Starting...");
  _display.display();
  _display.clearDisplay();
  delay(1000);
}

void Screen::tic(String* status) { mainScreen(status); }
uint8_t selected = 0;
void Screen::mainScreen(String* status) {
  long pressedTime = readButtonPressTime();

  if (pressedTime > 50) {
    if (selected >= 2)
      selected = 0;
    else
      selected++;
    Serial.println("Selected: " + String(selected));
  }

  uint8_t* value;
  if (selected == 1) {
    value = &_settings->onTime;
  } else if (selected == 2) {
    value = &_settings->offTime;
  }

  if (selected != 0) {
    short step = readEncoder(1);
    if (*value + step <= 600 && *value + step >= 0) *value += step;
  }

  _display.clearDisplay();
  _display.setTextSize(1);
  _display.setTextColor(BLACK, WHITE);
  _display.setCursor(3, 0);
  _display.print("Status:" + *status);

  _display.drawLine(0, 8, 84, 8, BLACK);

  _display.setCursor(10, 15);
  _display.setTextColor(BLACK, WHITE);
  _display.print("ON");
  if (selected == 1) {
    _display.setTextColor(WHITE, BLACK);
  }
  _display.setCursor(13, 25);
  _display.print(String(_settings->onTime) + "s");

  _display.setCursor(50, 15);
  _display.setTextColor(BLACK, WHITE);
  _display.print("OFF");
  if (selected == 2) {
    _display.setTextColor(WHITE, BLACK);
  }
  _display.setCursor(50, 25);
  _display.print(String(_settings->offTime) + "s");
  _display.display();
}

void Screen::printCentered(uint16_t y, String text) {
  uint8_t center = _display.width() / 2;
  uint16_t fontWidth = 0;
  _display.getTextBounds(text, 0, 0, 0, 0, &fontWidth, 0);

  _display.setCursor(center - (fontWidth / 2), y);
  _display.print(text);
}