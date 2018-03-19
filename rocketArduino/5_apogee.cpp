#include "globals.h"

bool fairingSep = false;

void apogee() {
  delay(500);
  if (digitalRead(FAIRINGPIN) == HIGH) {
    message += "error: fairing not jettisoned, ";
  } else {
    fairingSep = true;
    message += "fairing jettison confirmed, ";
  }
  for (int i = 0; i < 4; ++i) {
    servos.legs[i] = LegsStow[i];
  }
  message += "leg-fins stowed, ";
  ++phase;
}

