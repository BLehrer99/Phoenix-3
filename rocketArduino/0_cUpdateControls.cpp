#include "globals.h"

void updateControls() {
  servos.setRollComp();
  servos.setLegFin();
  servos.lightMain();
  servos.lightLand();
  servos.fireAFTS();
  servos.fairing();
}
