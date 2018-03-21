#include "globals.h"

void resetServos() {
  servos.landLight = false;
  servos.mainLight = false;
  servos.rollComp = 80;
  if (phase < 7) {
    for (int i = 0; i < 4; ++i) {
      servos.legs[i] = LegsAsc[i];
    }
  } else {
    for (int i = 0; i < 4; ++i) {
      servos.legs[i] = LegsLand[i];
    }
  }
  message += "reseting servos, ";
  updateControls();
}
