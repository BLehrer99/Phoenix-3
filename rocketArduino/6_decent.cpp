#include "globals.h"

void decent() {
  message += "retro burn, ";
  if (telemetry.ascentRate > DECENTRATE + 10) {
    servos.thrust -= 10;
  } else if (telemetry.ascentRate < DECENTRATE - 10) {
    servos.thrust += 10;
  } else if (telemetry.ascentRate > DECENTRATE + 1) {
    servos.thrust -= 5;
  } else if (telemetry.ascentRate < DECENTRATE - 1) {
    servos.thrust += 5;
  }

  if (servos.thrust > 100) {
    servos.thrust = 100;
  }  else if (servos.thrust < 0) {
    servos.thrust = 0;
  }
  servos.setThrust();
  //decent sequece***************************
  if (telemetry.ascentRate <= -20) {
    message += "error: decent rate exceeded -20 m/s, ";
  }
  if (telemetry.agl <= 5) {
    message += "landing, ";
    ++phase;
  }
}

