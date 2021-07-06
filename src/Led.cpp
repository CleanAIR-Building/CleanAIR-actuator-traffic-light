#include "Led.h"
#include "Arduino.h"

namespace CleanAIR {
Led::Led(const int gpio /* = D1*/) : mGpio(gpio), mState(STATE::OFF) { pinMode(mGpio, OUTPUT); }

void Led::TurnOn() {
  digitalWrite(mGpio, HIGH);
  mState = STATE::ON;
}

void Led::TurnOff() {
  digitalWrite(mGpio, LOW);
  mState = STATE::OFF;
}

Led::STATE Led::GetState() const { return mState; }
}  // namespace CleanAIR
