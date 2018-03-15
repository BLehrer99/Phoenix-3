#include "globals.h"

bool landingStarted = false;
int landingStartTime;

void landing() {
  //full decel --------------------------------------
  message += "landing, ";
  if (!landingStarted && telemetry.agl <= 4) {
    landingStarted = true;
    landingStartTime = millis();
    message += "landing legs deploy, ";
    for (int i = 0; i < 4; ++i) {
      servos.setLegFin(i, 100);
    }
  }
  if (telemetry.agl <= 1 && millis() - landingStartTime >= 1000) {
    message += "landed, shutoff, ";
    ++phase;
  }
}

