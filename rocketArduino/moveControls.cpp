#include "globals.h"

void Servos::lightMain() {
  if (mainLight) {
    digitalWrite(MAINIGNITIONPIN, HIGH);
  } else {
    digitalWrite(MAINIGNITIONPIN, LOW);
  }
}

void Servos::lightLand() {
  if (landLight) {
    digitalWrite(LANDIGNITIONPIN, HIGH);
  } else {
    digitalWrite(LANDIGNITIONPIN, LOW);
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

void Servos::fireAFTS() {
  triggerAFTS ? AFTS.write(AFTSON) : AFTS.write(AFTSOFF);
}

