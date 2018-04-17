#include "globals.h"

void writeSD() {
  char str[300];
  String plus = tTime >= 0.0 ? "+" : "-";
  String AFTSMes;
  if (phase >= 4 && phase <= 6) {
    AFTSMes = servos.triggerAFTS ? "triggered" : "armed";
  } else {
    AFTSMes = "disarmed";
  }
  snprintf(str, sizeof(str),
           "T%s%07ld, mag: %03d, agl: %04.1f, ascentRate: %04.1f, acceleration: %04.1f, pitch: %03d, yaw: %03d, roll: %03d, main ignition: %s, landing ignition: %s, fairing: %s, rollComp: %03d, launchPitch: %03d, legs[0]: %03d, legs[1]: %03d, legs[2]: %03d, legs[3]: %03d, AFTS: %s, message: "
           , plus.c_str(), abs(tTime), (int)telemetry.mag, telemetry.agl, telemetry.ascentRate, telemetry.acceleration, (int)telemetry.pitch, (int)telemetry.yaw, (int)telemetry.roll, servos.mainLight ? String("on").c_str() : String("off").c_str(), servos.landLight ? String("on").c_str() : String("off").c_str(), servos.fairingLight ? String("on").c_str() : String("off").c_str(), servos.rollComp, servos.launchPitch, servos.legs[0], servos.legs[1], servos.legs[2], servos.legs[3], AFTSMes.c_str());
  if (phase <= 3) {
    Serial.print(str);
    Serial.println(message);
  }
  myFile.print(str);
  myFile.println(message);
}
