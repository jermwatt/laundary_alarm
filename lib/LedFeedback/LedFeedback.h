#ifndef LedFeedback_h
#define LedFeedback_h

#include <Arduino.h>

class LedFeedback {
  public:
    LedFeedback(int ledPin);
    void flashLedSuccess();
    void flashLedFailure();
  private:
    int _ledPin;
    void flashLed(int count, int duration);
};

#endif