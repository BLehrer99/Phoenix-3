#include "globals.h"

void serialInput() {
  input = Serial.readString();
  if (input == "Thrust") {
    while (!Serial.available());
    input = Serial.readString();
    servos.setThrust(input.toInt());
  } else if (input == "RYaw") {
    while (!Serial.available());
    input = Serial.readString();
    servos.setRYaw(input.toInt());
  } else if (input == "RPitch") {
    while (!Serial.available());
    input = Serial.readString();
    servos.setRPitch(input.toInt());
  } else if (input == "RollComp") {
    while (!Serial.available());
    input = Serial.readString();
    servos.setRollComp(input.toInt());
  } else if (input == "LegFin0") {
    while (!Serial.available());
    input = Serial.readString();
    servos.setLegFin(0, input.toInt());
  } else if (input == "LegFin1") {
    while (!Serial.available());
    input = Serial.readString();
    servos.setLegFin(1, input.toInt());
  } else if (input == "LegFin2") {
    while (!Serial.available());
    input = Serial.readString();
    servos.setLegFin(2, input.toInt());
  } else if (input == "LegFin3") {
    while (!Serial.available());
    input = Serial.readString();
    servos.setLegFin(3, input.toInt());
  } else if (input == "Ignition") {
    while (!Serial.available());
    input = Serial.readString();
    if (input == "on" || input == "On" || input == "ON") {
      digitalWrite(IGNITIONPIN0, LOW);
      digitalWrite(IGNITIONPIN1, HIGH);
    } else if (input == "off" || input == "Off" || input == "OFF") {
      digitalWrite(IGNITIONPIN0, HIGH);
      digitalWrite(IGNITIONPIN1, LOW);
    }
  } else if (input == "Abort" || input == "ABORT" || input == "abort") {
    message += "aborted: abort command serial, ";
    phase = 9;
  }
  input = "";
}
