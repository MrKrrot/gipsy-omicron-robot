#include "devices/base_motors.h"
#include "devices/hands_motors.h"
#include "devices/sensors.h"

#include "functions/autonomous/resetEvery.h"

void resetEvery() {
  MotoresL.resetRotation();
  MotoresR.resetRotation();
  SensorDeRotL.resetPosition();
  SensorDeRotL.setPosition(0, degrees);
  Garra.resetRotation();
  Brazo.resetRotation();
}