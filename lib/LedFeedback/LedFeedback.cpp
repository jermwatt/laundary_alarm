#include "LedFeedback.h"

LedFeedback::LedFeedback(int ledPin) {
  _ledPin = ledPin;
  pinMode(_ledPin, OUTPUT);
}

void LedFeedback::flashLedSuccess() {
  flashLed(2, 500);
}

void LedFeedback::flashLedFailure() {
  flashLed(5, 100);
}

void LedFeedback::flashLed(int count, int duration) {
  for (int i = 0; i < count; i++) {
    digitalWrite(_ledPin, HIGH);
    delay(duration);
    digitalWrite(_ledPin, LOW);
    delay(duration);
  }
  digitalWrite(_ledPin, LOW);
}