#include "globals.h"

void decent() {
  message += "retro burn, ";
  //decent sequece***************************
  if (telemetry.accentRate <= -15) {
    message += "error: decent rate exceeded -15 m/s, ";
  }
  if (telemetry.agl <= 5) {
    message += "landing, ";
    ++phase;
  }
}

