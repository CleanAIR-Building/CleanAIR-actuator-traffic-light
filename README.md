# Traffic light

This repository contains the code for the traffic light.
## Setup
![traffic-light](https://raw.githubusercontent.com/CleanAIR-Building/Report/main/diagrams/Wiring_Traffic-Light.png?token=AH5OOFIWL3CPZ4BUJE6XTJ3A45KAS)

The resistors have a resistance of 470Ω.

Create a file called `data/Config.json`. It should look like this:

```json
{
  "ssid": "the ssid",
  "password": "the psk",
  "mqttAddress": "the ip",
  "mqttPort": 1883,
  "mqttUser": "the user",
  "mqttPassword": "the users password",
  "mqttPublishTopic": "the topic you want to publish to",
  "mqttSubscribeTopic": "the topic you want to subscribe to",
  "mqttClientName": "The client name",
  "deviceType": "The device type"
}
```

To upload your config file run `Upload Filesystem Image` from VScode or 
```json
pio run -e debug -t uploadfs
```
or
```json
pio run -e release -t uploadfs
```
depending on the environment you used.

## Messaging
Messages have the form:
```json
{ "command": "RED" }
```
or
```json
{ "command": "GREEN" }
```
or
```json
{ "command": "OFF" }
```