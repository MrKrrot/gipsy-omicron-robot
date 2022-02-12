#pragma once
#include "devices/sensors.h"

void avanceBumperAutom();

void avanceBumperAutom() {
  while (!BumperFrontal.pressing()) {
    Drivetrain.drive(forward);
  }
  Drivetrain.stop(hold);
}