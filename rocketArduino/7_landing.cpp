#include "globals.h"

bool landingStarted = false;

void landing() {
  message += "landing, ";
  if (!landingStarted) {
    landingStarted = true;
    message += "landing legs deploy, ";
    for (int i = 0; i < 4; ++i) {
      servos.setLegFin(i, 100);
    }
  }
  //landing routine************************
  if (telemetry.agl <= 1) {
    message += "landed, shutoff, ";
    ++phase;
  }
}

