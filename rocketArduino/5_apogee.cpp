#include "globals.h"

bool fairingSep = false;

int height(float agl) {
  double height = 1.0 / (8.0 * GRAVITYFREE);

  double num = 2.0 * TIMEBURN1 * GRAVITYFREE;
  num += 2.0 * TIMEBURN2 * GRAVITYFREE;

  double rootFrac = (-8.0) * MASS * agl;
  rootFrac -= 4.0 * MASS  * GRAVITYBURN * pow(TIMEBURN1, 2);
  rootFrac -= 4.0 * MASS * GRAVITYBURN * TIMEBURN1 * TIMEBURN2;
  rootFrac -= 4.0 * MASS * GRAVITYBURN * pow(TIMEBURN2, 2);
  rootFrac -= 4.0 * FORCEBURN2 * pow(TIMEBURN2, 2);
  rootFrac -= 4.0 * TIMEBURN1 * TIMEBURN2 * FORCEBURN1;
  rootFrac -= 4.0 * pow(TIMEBURN1, 2) * FORCEBURN1;
  rootFrac /= MASS * GRAVITYFREE;

  double insideRoot = rootFrac;
  insideRoot += 4.0 * pow(TIMEBURN1, 2);
  insideRoot += 8.0 * TIMEBURN1 * TIMEBURN2;
  insideRoot += 4.0 * pow(TIMEBURN2, 2);

  double root = sqrt(insideRoot);

  num -= GRAVITYFREE * root;
  num = pow(num, 2);
  num += 8.0 * agl * GRAVITYFREE;

  height *= num;

  return int(height);
}

/*
   b_s=\frac{\left(2t_1g_0+2t_2g_0-g_0\sqrt{4t_1^2+8t_1t_2+4t_2^2+\frac{\left(-8mA-4mg_1t_1^2-4mg_1t_1t_2-4mg_1t_2^2-4f_2t_2^2-4t_1t_2f_1-4t_1^2f_1\right)}{mg_0}}\right)^2+8Ag_0}{8g_0}
*/

void apogee() {
  delay(500);
  servos.fairingAttach = false;
  for (int i = 0; i < 4; ++i) {
    servos.legs[i] = LegsStow[i];
  }
  message += "leg-fins stowed, ";

  burnHeight = height(telemetry.agl);

  message += "burn height: " + String(burnHeight) + ", ";
  ++phase;
}

