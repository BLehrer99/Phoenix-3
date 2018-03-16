#include "globals.h"

void resetServos() {
  digitalWrite(IGNITIONPIN0, HIGH);
  digitalWrite(IGNITIONPIN1, LOW);
  servos.thrust = 0;
  servos.rPitch = SERVORANGE / 2;
  servos.rYaw = SERVORANGE / 2;
  servos.rollComp = SERVORANGE / 2;
  if (phase < 7)
    for (int i = 0; i < 4; ++i) {
      servos.legs[i] = 30;

    }
  message += "reseting servos, ";
  updateControls();
}
