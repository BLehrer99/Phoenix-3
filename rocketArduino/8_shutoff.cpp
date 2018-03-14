#include "globals.h"

void shutoff() {
  resetServos();

  writeSD();

  myFile.close();

  ++phase;
}

