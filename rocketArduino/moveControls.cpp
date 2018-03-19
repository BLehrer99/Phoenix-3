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

void Servos::setRollComp() {
  RollComp0.write(rollComp + fins[0] + ROLLCOMP0TRIM);
  RollComp1.write(rollComp + fins[1] + ROLLCOMP1TRIM);
  RollComp2.write(rollComp + fins[2] + ROLLCOMP2TRIM);
  RollComp3.write(rollComp + fins[3] + ROLLCOMP3TRIM);
}

void Servos::setLegFin() {
  LegFin0.write(legs[0]);
  LegFin1.write(legs[1]);
  LegFin2.write(legs[2]);
  LegFin3.write(legs[3]);
}
