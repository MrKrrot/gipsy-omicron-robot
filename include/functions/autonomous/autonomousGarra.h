#pragma once
#include "devices/base.h"
#include "devices/main.h"
#include "devices/sensors.h"
#include "functions/autonomous/driveSetup.h"
#include "vex.h"


void autonomousGarra();

void autonomousGarra() {
  
  while (!BumperFrontal.pressing() && SensorDeDistancia.objectDistance(mm) <= 1600) {
    Drivetrain.drive(forward);
  }

  if (SensorDeDistancia.objectDistance(mm) <= 1700) {
    Garra.spinFor(reverse, 300, degrees); // 150
    Garra.setTimeout(4000, msec);
    Drivetrain.stop();
    Brazo.spinFor(forward, 200, degrees);
    driveSetup(100, 100);
    Drivetrain.driveFor(reverse, 50, inches);
    Brazo.spinFor(reverse, 100, degrees);
    /*********************/
  } else {
    driveSetup(100, 100);
    Drivetrain.driveFor(reverse, 20, inches);
  }
}