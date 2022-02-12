#pragma once
#include "devices/base.h"
#include "devices/sensors.h"

void resetEvery();

void resetEvery() {
  MotoresL.resetRotation();
  MotoresR.resetRotation();
  SensorDeRotL.resetPosition();
  SensorDeRotL.setPosition(0, degrees);
  Garra.resetRotation();
  Brazo.resetRotation();
}