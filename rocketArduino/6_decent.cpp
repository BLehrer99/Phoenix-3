#include "globals.h"

void decent() {
  message += "retro burn, ";
  if (telemetry.ascentRate > 0) {
    telemetry.thrust -= 10;
    if (telemetry.thrust < MOTORMIN) {
      telemetry.thrust = MOTORMIN;
    }
  } else if (telemetry.ascentRate < -20) {
    telemetry.thrust += 10;
    if (telemetry.thrust > MOTORMAX) {
      telemetry.thrust = MOTORMAX;
    }
  } else if (telemetry.ascentRate > -9) {
    telemetry.thrust -= 5;
    if (telemetry.thrust < MOTORMIN) {
      telemetry.thrust = MOTORMIN;
    }
  } else if (telemetry.ascentRate < -11) {
    telemetry.thrust += 5;
    if (telemetry.thrust > MOTORMAX) {
      telemetry.thrust = MOTORMAX;
    }
  }
  setThrust(telemetry.thrust);
  //decent sequece***************************
  if (telemetry.ascentRate <= -20) {
    message += "error: decent rate exceeded -20 m/s, ";
  }
  if (telemetry.agl <= 5) {
    message += "landing, ";
    ++phase;
  }
}

