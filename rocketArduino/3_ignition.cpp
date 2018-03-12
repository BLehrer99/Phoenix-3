#include "globals.h"

void ignition() {
  digitalWrite(IGNITIONPIN0, LOW);
  digitalWrite(IGNITIONPIN1, HIGH);
  message += "ignition, ";
  if (telemetry.agl >= 1) {
    message += "liftoff, ";
    ++phase;
  }
}

