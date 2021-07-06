#pragma once
#include "MessageProducer.h"
#include "TrafficLight.h"

namespace CleanAIR {
class TrafficLightMessageProducer : public MessageProducer {
 public:
  void Loop() override;
  void SendUpdate(TrafficLight::STATE state);

 private:
  std::string StateToString(TrafficLight::STATE state);
};
}  // namespace CleanAIR
