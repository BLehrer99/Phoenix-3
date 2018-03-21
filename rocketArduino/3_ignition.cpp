#include "globals.h"

void ignition() {
  servos.mainLight = true;
  message += "ignition, ";
  if (telemetry.agl >= 1) {
    message += "liftoff, ";
    ++phase;
  }
}

