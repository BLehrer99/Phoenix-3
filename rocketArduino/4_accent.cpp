#include "globals.h"

bool meco = false;
int mecoTime;

void accent() {
  //guidence**************************

  if (telemetry.acceleration <= 0 && !meco) {
    meco = true;
    mecoTime = millis();
    message += "MECO, ";
  } else if (millis() - mecoTime >= ENGINEDELAY + 250) {
    message += "apogee, fairing jettison, ";
    ++phase;
    return;
  }
  if (meco) {
    message += "coast, ";
  } else {
    message += "burn, ";
  }
}

