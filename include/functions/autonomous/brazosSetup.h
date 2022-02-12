#pragma once
#include "devices/base.h"

void brazosSetup(int v, int t);

void brazosSetup(int v, int t) {
  BrazoBack.setVelocity(v, percent);
  BrazoBack.setMaxTorque(t, percent);
  BrazoBack.setStopping(hold);
}