#include "globals.h"

void writeSD() {
  char str[300];
  String plus = tTime >= 0.0 ? "+" : "-";
  snprintf(str, sizeof(str),
           "T%s%07ld, mag: %03d, agl: %03d, ascentRate: %03d, acceleration: %02d, pitch: %03d, yaw: %03d, roll: %03d, main ignition: %01d, landing ignition: %01d, rollComp: %03d, launchPitch: %03d, legs[0]: %03d, legs[1]: %03d, legs[2]: %03d, legs[3]: %03d, message: "
           , plus.c_str(), abs(tTime), (int)telemetry.mag, (int)telemetry.agl, (int)telemetry.ascentRate, (int)telemetry.acceleration, (int)telemetry.pitch, (int)telemetry.yaw, (int)telemetry.roll, servos.mainLight ? 1 : 0, servos.landLight ? 1 : 0, servos.rollComp, servos.launchPitch, servos.legs[0], servos.legs[1], servos.legs[2], servos.legs[3]);
  if (phase <= 3) {
    Serial.print(str);
    Serial.println(message);
  }
  Serial1.print(str);
  Serial1.println(message);
}
