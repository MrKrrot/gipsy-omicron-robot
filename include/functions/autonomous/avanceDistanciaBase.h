#pragma once
#include "devices/sensors.h"

void avanceDistanciaBase(int i);

void avanceDistanciaBase(int i) {
  while (SensorDeDistancia.objectDistance(mm) <= i) {
    Drivetrain.drive(forward);
  }
  Drivetrain.stop();
}