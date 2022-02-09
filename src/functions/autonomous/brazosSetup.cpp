#include "devices/hands_motors.h"

#include "functions/autonomous/brazosSetup.h"

void brazosSetup(int v, int t) {
  BrazoBack.setVelocity(v, percent);
  BrazoBack.setMaxTorque(t, percent);
  BrazoBack.setStopping(hold);
}