#pragma once
#include "devices/base.h"
#include "devices/sensors.h"

void brazosBackMovAut(bool i);

void brazosBackMovAut(bool i) {
  while (1) {
    if (i == 1) {
      if (SensorDeRotL.position(degrees) <= 93) {
        BrazoBack.spin(forward);
      } else {
        BrazoBack.stop();
        break;
      }
    } else {
      if (SensorDeRotL.position(degrees) >= 50) {
        BrazoBack.spin(reverse);
      } else {
        BrazoBack.stop();
        break;
      }
    }
  }
}