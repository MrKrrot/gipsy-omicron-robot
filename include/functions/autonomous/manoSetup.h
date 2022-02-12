#pragma once
#include "devices/base.h"

void manoSetup(int v, int t);

void manoSetup(int v, int t) {
  Brazo.setVelocity(v, percent);
  Brazo.setMaxTorque(t, percent);
  Brazo.setStopping(hold);

  Garra.setVelocity(v, percent);
  Garra.setMaxTorque(t, percent);
  Garra.setStopping(hold);
}