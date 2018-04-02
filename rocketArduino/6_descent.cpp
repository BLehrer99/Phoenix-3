#include "globals.h"

void descent() {
  //guidance
  float finalVel = telemetry.ascentRate + ((TIMEBURN1 * ((FORCEBURN1 / MASS) + GRAVITY)) + (TIMEBURN2 * ((FORCEBURN2 / MASS) + GRAVITY)));
  if (telemetry.agl <= burnHeight + 10 || finalVel >= -2) {
    message += "landing burn, ";
    servos.landLight = true;
  }
  if (telemetry.agl <= 10) {
    message += "landing, ";
    ++phase;
  }
}

