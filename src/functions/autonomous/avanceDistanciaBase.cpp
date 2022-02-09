#include "devices/sensors.h"

#include "functions/autonomous/avanceDistanciaBase.h"

void avanceDistanciaBase(int i) {
  while (SensorDeDistancia.objectDistance(mm) <= i) {
    Drivetrain.drive(forward);
  }
  Drivetrain.stop();
}