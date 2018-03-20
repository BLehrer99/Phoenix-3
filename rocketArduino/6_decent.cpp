#include "globals.h"

void decent() {
  //guidance

  if (telemetry.agl <= burnHeight + 10) {
    message += "retro burn, ";
    servos.thrust = 100;
    message += "landing, ";
    ++phase;
  }
}

