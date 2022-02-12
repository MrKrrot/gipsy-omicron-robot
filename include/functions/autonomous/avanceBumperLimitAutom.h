#pragma once
#include "devices/sensors.h"
#include "functions/autonomous/pistonesAutom.h"

void avanceBumperLimitAutom(int i);

void avanceBumperLimitAutom(int i) {
  pistonesAutom(0);
  while (!BumperFrontal.pressing() &&
         SensorDeDistancia.objectDistance(mm) <= i) {
    Drivetrain.drive(forward);
  }
  Drivetrain.stop(hold);
}