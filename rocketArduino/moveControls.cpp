#include "globals.h"

void Servos::setThrust(int val) {
  thrust = val;
  Thrust.write(thrust + THRUSTTRIM);
}

void Servos::setRYaw(int val) {
  rYaw = val;
  RYaw.write(rYaw + RYAWTRIM);
}

void Servos::setRPitch(int val) {
  rPitch = val;
  RPitch.write(rPitch + RPITCHTRIM);
}

void Servos::setRollComp(int val) {
  rollComp = val;
  RollComp0.write(rollComp + ROLLCOMP0TRIM);
  RollComp1.write(rollComp + ROLLCOMP1TRIM);
  RollComp2.write(rollComp + ROLLCOMP2TRIM);
  RollComp3.write(rollComp + ROLLCOMP3TRIM);
}

void Servos::setLegFin(int number, int val) {
  legs[number] = val;
  switch (number) {
    case 0:
      LegFin0.write(legs[0] + LEGS0TRIM);
    case 1:
      LegFin1.write(legs[1] + LEGS1TRIM);
    case 2:
      LegFin2.write(legs[2] + LEGS2TRIM);
    case 3:
      LegFin3.write(legs[3] + LEGS3TRIM);
  }
}
