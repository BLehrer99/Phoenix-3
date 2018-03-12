#include "globals.h"

void shutoff() {
  resetServos();

  myFile.close();
}

