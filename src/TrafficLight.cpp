#include "TrafficLight.h"
#include "Arduino.h"
#include "ArduinoJson.h"
#include "CleanAIRDevice.h"
#include "TrafficLightMessageProducer.h"

namespace CleanAIR {
TrafficLight::TrafficLight(TrafficLightMessageProducer* trafficLightMessageProducer, const int redGpio /*= D1*/,
                           const int greenGpio /*= D2*/)
    : mTrafficLightMessageProducer(trafficLightMessageProducer), mRed(redGpio), mGreen(greenGpio), mState(STATE::OFF) {}

void TrafficLight::Consume(const char* topic, const CleanAIR::MessageJson& message) {
  const char* command = message["command"];

  if (strcmp("GREEN", command) == 0) {
    TurnGreen();
  } else if (strcmp("RED", command) == 0) {
    TurnRed();
  } else if (strcmp("OFF", command) == 0) {
    TurnOff();
  } else {
    Serial.println(F("Unknown command!"));
  }
}

void TrafficLight::Loop() {}

void TrafficLight::TurnRed() {
  mRed.TurnOn();
  mGreen.TurnOff();
  mState = STATE::RED;
  mTrafficLightMessageProducer->SendUpdate(mState);
}

void TrafficLight::TurnGreen() {
  mRed.TurnOff();
  mGreen.TurnOn();
  mState = STATE::GREEN;
  mTrafficLightMessageProducer->SendUpdate(mState);
}

void TrafficLight::TurnOff() {
  mRed.TurnOff();
  mGreen.TurnOff();
  mState = STATE::OFF;
  mTrafficLightMessageProducer->SendUpdate(mState);
}

TrafficLight::STATE TrafficLight::GetState() const { return mState; }
}  // namespace CleanAIR
