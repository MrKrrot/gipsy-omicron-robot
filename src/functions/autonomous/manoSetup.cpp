#include "devices/hands_motors.h"

#include "functions/autonomous/manoSetup.h"

void manoSetup(int v, int t) {
  Brazo.setVelocity(v, percent);
  Brazo.setMaxTorque(t, percent);
  Brazo.setStopping(hold);

  Garra.setVelocity(v, percent);
  Garra.setMaxTorque(t, percent);
  Garra.setStopping(hold);
}