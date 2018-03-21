#include "globals.h"

void decent() {
  //guidance
  float finalVel = -pow(telemetry.ascentRate, 2) + (2 * ((LANDINGFORCE / MASS) - 9.81) * telemetry.agl);
  if (telemetry.agl <= burnHeight + 10 || finalVel <= 10) {
    message += "landing burn, ";
    servos.landLight = true;
  }
  if (telemetry.agl <= 10) {
    message += "landing, ";
    ++phase;
  }
}

