#include "globals.h"

bool landingStarted = false;
int landingStartTime;

void landing() {
  message += "landing, ";
  if (!landingStarted) {
    landingStarted = true;
    landingStartTime = millis();
    message += "landing legs deploy, ";
    for (int i = 0; i < 4; ++i) {
      servos.legs[i] = LegsLand[i];
    }
  }
  if (telemetry.agl <= 1 || millis() - landingStartTime >= 1000) {
    message += "landed, shutoff, ";
    ++phase;
  }
}

