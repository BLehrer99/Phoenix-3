#include "globals.h"

void resetServos() {
  digitalWrite(IGNITIONPIN, HIGH);
  servos.setThrust(0);
  servos.setRPitch(SERVORANGE / 2);
  servos.setRYaw(SERVORANGE / 2);
  servos.setRollComp(SERVORANGE / 2);
  if (phase < 7)
    for (int i = 0; i < 4; ++i) {
      servos.setLegFin(i, 30);

    }
  message += "reseting servos, ";
}
