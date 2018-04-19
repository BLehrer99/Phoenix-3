#include "globals.h"

void Servos::lightMain() {
  if (mainLight) {
    digitalWrite(MAINIGNITIONPIN, LOW);
  } else {
    digitalWrite(MAINIGNITIONPIN, HIGH);
  }
}

void Servos::lightLand() {
  if (landLight) {
    digitalWrite(LANDIGNITIONPIN, LOW);
  } else {
    digitalWrite(LANDIGNITIONPIN, HIGH);
  }
}

void Servos::setRollComp() {
  RollComp0.write(rollComp + fins[0] + ROLLCOMP0TRIM);
  RollComp1.write(rollComp + fins[1] + ROLLCOMP1TRIM);
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

void Servos::lightFairing() {
  if (fairingLight) {
    digitalWrite(FAIRINGPIN, LOW);
  } else {
    digitalWrite(FAIRINGPIN, HIGH);
  }
}

