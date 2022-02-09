#include "functions/autonomous/autonomousGarra.h"
#include "devices/base_motors.h"
#include "devices/hands_motors.h"
#include "devices/sensors.h"
#include "vex.h"


#include "functions/autonomous/brazosBackMovAut.h"
#include "functions/autonomous/driveSetup.h"
#include "functions/autonomous/pistonesAutom.h"


void autonomousGarra() {
  while (!BumperFrontal.pressing() &&
         SensorDeDistancia.objectDistance(mm) <= 1600) {
    Drivetrain.drive(forward);
    if (MotoresL.rotation(degrees) > 650) {
      driveSetup(40, 100);
    }
  }
  Control.Screen.print(SensorDeDistancia.objectDistance(mm));
  Control.Screen.print("-");
  Control.Screen.print(MotoresL.rotation(deg));
  Drivetrain.stop(hold);
  if (SensorDeDistancia.objectDistance(mm) <= 1800) {
    Garra.setTimeout(1000, msec);
    Garra.spinFor(reverse, 300, degrees); // 150
    Garra.spin(reverse);
    Brazo.spinFor(forward, 200, degrees);
    Drivetrain.stop();
    driveSetup(100, 100);
    Garra.stop();
    Drivetrain.driveFor(reverse, 5, inches);
    Brazo.spinFor(reverse, 100, degrees);
    Drivetrain.setTurnVelocity(5, percent);
    Drivetrain.turnFor(left, 45, degrees);
    Drivetrain.turnToHeading(315, degrees);
    pistonesAutom(0);
    brazosBackMovAut(1);
    Drivetrain.driveFor(reverse, 7, inches);
    wait(1, sec);
    pistonesAutom(1);
    brazosBackMovAut(0);

    Drivetrain.turnFor(right, 45, degrees);
    Drivetrain.turnToHeading(0, degrees);
    Drivetrain.driveFor(reverse, 15, inches);
    /*********************/
  } else {
    driveSetup(100, 100);
    Drivetrain.driveFor(reverse, 20, inches);
  }
}