#pragma once
#include "devices/base.h"

void baseSetup(int v, int t);

void baseSetup(int v, int t) {
  MotoresL.setVelocity(v, percent);
  MotoresL.setMaxTorque(t, percent);
  MotoresL.setStopping(hold);
  MotoresR.setVelocity(v, percent);
  MotoresR.setMaxTorque(t, percent);
  MotoresR.setStopping(hold);
}