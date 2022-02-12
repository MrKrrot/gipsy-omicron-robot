#pragma once
#include "devices/sensors.h"

void pistonesAutom(bool L);

void pistonesAutom(bool L) {
  if (L == 0) {
    ValveArm1.close();
    ValveArm2.open();
  } else {
    ValveArm1.open();
    ValveArm2.close();
  }
}