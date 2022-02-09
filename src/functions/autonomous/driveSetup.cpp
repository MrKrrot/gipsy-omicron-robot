#include "devices/sensors.h"

#include "functions/autonomous/driveSetup.h"

void driveSetup(int v, int r) {
  Drivetrain.setTurnVelocity(r, percent);
  Drivetrain.setDriveVelocity(v, percent);
  Drivetrain.setStopping(hold);
}