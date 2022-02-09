#include "devices/hands_motors.h"

#include "functions/autonomous/bandaSetup.h"

void bandaSetup(int v, int t) {
  MotorRiel.setVelocity(v, percent);
  MotorRiel.setMaxTorque(t, percent);
  MotorRiel.setStopping(hold);
}