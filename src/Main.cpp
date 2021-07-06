#include "CleanAIRDevice.h"
#include "Definitions.h"
#include "TrafficLight.h"
#include "TrafficLightMessageProducer.h"

CleanAIR::TrafficLightMessageProducer trafficLightMessageProducer;
CleanAIR::TrafficLight trafficLight(&trafficLightMessageProducer, D1, D2);

void setup() {
  Serial.begin(BAUDRATE);
  CleanAIR::SetConsumer(&trafficLight);
  CleanAIR::SetProducer(&trafficLightMessageProducer);
  CleanAIR::LoadConfiguration(CONFIG_FILE);
  CleanAIR::ConnectToWifi();
  CleanAIR::ConnectToMQTT();
  CleanAIR::ConnectToTopic();
  CleanAIR::InitializeHeartBeat(HEARTBEAT);
}

void loop() { CleanAIR::Loop(); }
