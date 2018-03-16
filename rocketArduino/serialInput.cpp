#include "globals.h"

void serialInput() {
  input = Serial.readString();
  if (input == "Thrust") {
    while (!Serial.available());
    input = Serial.readString();
    servos.thrust = input.toInt();
  } else if (input == "RYaw") {
    while (!Serial.available());
    input = Serial.readString();
    servos.rYaw = input.toInt();
  } else if (input == "RPitch") {
    while (!Serial.available());
    input = Serial.readString();
    servos.rPitch = input.toInt();
  } else if (input == "RollComp") {
    while (!Serial.available());
    input = Serial.readString();
    servos.rollComp = input.toInt();
  } else if (input == "LegFin0") {
    while (!Serial.available());
    input = Serial.readString();
    servos.legs[0] = input.toInt();
  } else if (input == "LegFin1") {
    while (!Serial.available());
    input = Serial.readString();
    servos.legs[1] = input.toInt();
  } else if (input == "LegFin2") {
    while (!Serial.available());
    input = Serial.readString();
    servos.legs[2] = input.toInt();
  } else if (input == "LegFin3") {
    while (!Serial.available());
    input = Serial.readString();
    servos.legs[3] = input.toInt();
  } else if (input == "Ignition") {
    while (!Serial.available());
    input = Serial.readString();
    if (input == "on" || input == "On" || input == "ON") {
      servos.ignition = true;
    } else if (input == "off" || input == "Off" || input == "OFF") {
      servos.ignition = false;
    }
  } else if (input == "Abort" || input == "ABORT" || input == "abort") {
    message += "aborted: abort command serial, ";
    phase = 9;
  }
  input = "";
}
