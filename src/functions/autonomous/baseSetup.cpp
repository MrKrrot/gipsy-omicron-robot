#include "devices/base_motors.h"

#include "functions/autonomous/baseSetup.h"

void baseSetup(int v, int t) {
  MotoresL.setVelocity(v, percent);
  MotoresL.setMaxTorque(t, percent);
  MotoresL.setStopping(hold);
  MotoresR.setVelocity(v, percent);
  MotoresR.setMaxTorque(t, percent);
  MotoresR.setStopping(hold);
}