#include "devices/sensors.h"

#include "functions/autonomous/pistonesAutom.h"

void PistonesAutom(bool L) {
  if (L == 0) {
    ValveArm1.close();
    ValveArm2.open();
  } else {
    ValveArm1.open();
    ValveArm2.close();
  }
}