#include "globals.h"

void shutoff() {
  resetServos();

  writeSD();

  ++phase;
}

