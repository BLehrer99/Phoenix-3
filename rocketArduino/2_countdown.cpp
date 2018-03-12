#include "globals.h"

void countdown() {
  if (digitalRead(ABORTPIN) == HIGH) {
    message += "aborted: abort switch, ";
    phase = 9;
    return;
  }
  message += "go for launch, ";
  if (tTime / 1000 >= -1) {
    ++phase;
  }
}

