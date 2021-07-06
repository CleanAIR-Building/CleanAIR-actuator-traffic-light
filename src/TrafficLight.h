#pragma once
#include "Led.h"
#include "MessageConsumer.h"

namespace CleanAIR {
class TrafficLightMessageProducer;
class TrafficLight : public CleanAIR::MessageConsumer {
 public:
  enum class STATE { RED, GREEN, OFF };

  TrafficLight(TrafficLightMessageProducer* trafficLightMessageProducer, const int redGpio = 5 /*D1*/,
               const int greenGpio = 4 /*D2*/);
  void Consume(const char* topic, const CleanAIR::MessageJson& message) override;
  virtual void Loop() override;

  void TurnRed();
  void TurnGreen();
  void TurnOff();
  STATE GetState() const;

 private:
  TrafficLightMessageProducer* mTrafficLightMessageProducer;
  Led mRed;
  Led mGreen;
  STATE mState;
};
}  // namespace CleanAIR
