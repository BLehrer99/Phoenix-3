#include "globals.h"

void updateControls() {
  servos.setThrust();
  servos.setRYaw();
  servos.setRPitch();
  servos.setRollComp();
  servos.setLegFin();
  if (servos.ignition == true) {
    digitalWrite(IGNITIONPIN0, LOW);
    digitalWrite(IGNITIONPIN1, HIGH);
  } else {
    digitalWrite(IGNITIONPIN0, LOW);
    digitalWrite(IGNITIONPIN1, HIGH);
  }
}
