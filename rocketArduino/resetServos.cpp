#include "globals.h"

void resetServos() {
  digitalWrite(IGNITIONPIN0, HIGH);
  digitalWrite(IGNITIONPIN1, LOW);
  servos.thrust = 0;
  servos.rollComp = SERVORANGE / 2;
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
