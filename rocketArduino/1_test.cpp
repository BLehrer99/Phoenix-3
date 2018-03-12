#include "globals.h"

void test() {
  if (digitalRead(ABORTPIN) == HIGH) {
    message += "aborted: abort switch, ";
    phase = 9;
    return;
  }
  //run test sequence*********************
  message += "testing systems, ";
  countdownStart = millis();
}

