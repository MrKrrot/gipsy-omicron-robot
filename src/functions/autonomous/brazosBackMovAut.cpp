#include "devices/hands_motors.h"
#include "devices/sensors.h"

#include "functions/autonomous/brazosBackMovAut.h"

void brazosBackMovAut(bool i) {
  while (1) {
    if (i == 1) {
      if (SensorDeRotL.position(degrees) <= 93) {
        BrazoBack.spin(reverse);
      } else {
        BrazoBack.stop();
        break;
      }
    } else {
      if (SensorDeRotL.position(degrees) >= 50) {
        BrazoBack.spin(forward);
      } else {
        BrazoBack.stop();
        break;
      }
    }
  }
}