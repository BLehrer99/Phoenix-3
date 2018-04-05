#include "globals.h"

int AFTSCount = 0;

void checkAFTS() {
  if (AFTSCount >= 2) {
    servos.triggerAFTS = true;
    message += "AFTS triggered, ";
    phase = 9;
    return;
  }
  if (telemetry.yaw >= 60 && telemetry.yaw <= 300) {
    ++AFTSCount;
    return;
  }
  if (telemetry.roll >= 60 && telemetry.roll <= 300) {
    ++AFTSCount;
    return;
  }
  AFTSCount = 0;
}

