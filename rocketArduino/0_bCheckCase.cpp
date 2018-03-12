#include "globals.h"

/*
   phases
   0: startup, calibration
   1: control surface test
   2: countdown
   3: ignition
   4: accent
   5: apogee
   6: decent
   7: landing
   8: shutoff
   9: powered off
*/

void checkCase() {
  switch (phase) {
    case 0:
      startup();
      break;
    case 1:
      test();
      break;
    case 2:
      countdown();
      break;
    case 3:
      ignition();
      break;
    case 4:
      accent();
      break;
    case 5:
      apogee();
      break;
    case 6:
      decent();
      break;
    case 7:
      landing();
      break;
    case 8:
      shutoff();
      break;
    case 9:
      shutoff();
      break;
    default:
      message += "error: reached end of checkCase, ";
      break;
  }
}
