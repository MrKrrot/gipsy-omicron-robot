#pragma once
#include "devices/sensors.h"

void retrocesoDistanciaBase(int i);

void retrocesoDistanciaBase(int i) {
  while (SensorDeDistancia.objectDistance(mm) >= i) {
    Drivetrain.drive(reverse);
  }
  Drivetrain.stop();
}