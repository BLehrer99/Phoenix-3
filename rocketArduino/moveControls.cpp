#include "globals.h"

void Servos::setThrust() {
  if (thrust == 0) {
    Thrust.write(MOTORRESET);
  } else {
    int val = (MOTORMAX - MOTORMIN) * thrust;
    val += MOTORMIN;
    Thrust.write(val + THRUSTTRIM);
  }
}

void Servos::setRYaw() {
  RYaw.write(rYaw + RYAWTRIM);
}

void Servos::setRPitch() {
  RPitch.write(rPitch + RPITCHTRIM);
}

void Servos::setRollComp() {
  RollComp0.write(rollComp + ROLLCOMP0TRIM);
  RollComp1.write(rollComp + ROLLCOMP1TRIM);
  RollComp2.write(rollComp + ROLLCOMP2TRIM);
  RollComp3.write(rollComp + ROLLCOMP3TRIM);
}

void Servos::setLegFin() {
  LegFin0.write(legs[0] + LEGS0TRIM);
  LegFin1.write(legs[1] + LEGS1TRIM);
  LegFin2.write(legs[2] + LEGS2TRIM);
  LegFin3.write(legs[3] + LEGS3TRIM);
}
