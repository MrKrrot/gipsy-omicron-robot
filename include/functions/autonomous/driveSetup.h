#pragma once
#include "devices/sensors.h"

void driveSetup(int v, int r);

void driveSetup(int v, int r) {
  Drivetrain.setTurnVelocity(r, percent);
  Drivetrain.setDriveVelocity(v, percent);
  Drivetrain.setStopping(hold);
}