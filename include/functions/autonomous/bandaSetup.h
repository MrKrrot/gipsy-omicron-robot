#pragma once
#include "devices/base.h"

void bandaSetup(int v, int t);

void bandaSetup(int v, int t) {
  MotorRiel.setVelocity(v, percent);
  MotorRiel.setMaxTorque(t, percent);
  MotorRiel.setStopping(hold);
}