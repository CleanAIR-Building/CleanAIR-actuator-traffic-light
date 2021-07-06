#pragma once

namespace CleanAIR {
class Led {
 public:
  enum class STATE { ON, OFF };

  Led(const int gpio = 5 /*D1*/);
  void TurnOn();
  void TurnOff();
  STATE GetState() const;

 private:
  const int mGpio;
  STATE mState;
};
}  // namespace CleanAIR
