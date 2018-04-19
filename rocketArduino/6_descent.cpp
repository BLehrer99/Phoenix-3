#include "globals.h"

double burnoutAlt(float agl, float rate) {
  float alt = agl;
  alt += TIMEBURN1 * rate;
  alt += (pow(TIMEBURN1, 2) * ((FORCEBURN1 / MASS) + GRAVITYBURN)) / 2.0;
  alt += TIMEBURN2 * rate;
  alt += TIMEBURN1 * TIMEBURN2 * ((FORCEBURN1 / MASS) + GRAVITYBURN) / 2.0;
  alt += (pow(TIMEBURN2, 2) * ((FORCEBURN2 / MASS) + GRAVITYBURN)) / 2.0;

  return alt;
}

/*
   v_l\left(x\right)=\left\{p\left(x\right)\ge-1:-\sqrt{\left(-\sqrt{2g_0\left(x-A\right)}+t_1\left(\frac{f_1}{m}+g_1\right)+t_2\left(\frac{f_2}{m}+g_1\right)\right)^2+2g_0\left(-p\left(x\right)\right)}\right\}

   p\left(x\right)=x-t_1\sqrt{2g_0\left(x-A\right)}+\frac{t_1^2\left(\frac{f_1}{m}+g_1\right)}{2}-t_2\sqrt{2g_0\left(x-A\right)}+\frac{t_1t_2\left(\frac{f_1}{m}+g_1\right)}{2}+\frac{t_2^2\left(\frac{f_2}{m}+g_1\right)}{2}
*/

void decGuide() {

}

void descent() {
  decGuide();
  if (telemetry.agl <= burnHeight + 10 || burnoutAlt(telemetry.agl, telemetry.ascentRate) <= 10) {
    servos.fairingLight = false;
    message += "landing burn, ";
    servos.landLight = true;
  }
  if (telemetry.agl <= 10) {
    servos.landLight = false;
    message += "landing, ";
    ++phase;
  }
}

