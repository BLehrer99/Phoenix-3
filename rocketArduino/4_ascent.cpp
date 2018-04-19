#include "globals.h"

bool meco = false;
long mecoTime;

void ascGuide() {

}

void ascent() {
  ascGuide();
  servos.mainLight = false;
  if (telemetry.acceleration <= 0 || tTime >= (BURNTIME + 0.1) * 1000.0 && !meco) {
    meco = true;
    mecoTime = millis();
    message += "MECO, ";
  } else if (telemetry.acceleration <= -8 || millis() - mecoTime >= ENGINEDELAY + 250) {
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
