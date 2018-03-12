#include "globals.h"

void ignition() {
  digitalWrite(IGNITIONPIN, LOW);
  message += "ignition, ";
  if (telemetry.agl >= 1) {
    message += "liftoff, ";
    ++phase;
  }
}

