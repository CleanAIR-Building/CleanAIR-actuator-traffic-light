#include "TrafficLightMessageProducer.h"
#include "ArduinoJson.h"
#include "CleanAIRDevice.h"
#include "JsonDocuments.h"

namespace CleanAIR {
void TrafficLightMessageProducer::Loop() {}

std::string TrafficLightMessageProducer::StateToString(TrafficLight::STATE state) {
  switch (state) {
    case TrafficLight::STATE::GREEN:
      return "GREEN";
    case TrafficLight::STATE::RED:
      return "RED";
    case TrafficLight::STATE::OFF:
      return "OFF";
  }
  return "";
}

void TrafficLightMessageProducer::SendUpdate(TrafficLight::STATE state) {
  CleanAIR::MessageJson message;
  message["sensor"] = CleanAIR::GetConfig().mqttClientName.c_str();
  auto stateString = StateToString(state);
  message["state"] = stateString.c_str();
  Publish(CleanAIR::GetConfig().mqttPublishTopic.c_str(), message, true);
}
}  // namespace CleanAIR