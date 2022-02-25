/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Francisco De Jesus Orta Ramirez                           */
/*    Created:      25 De Octubre 2021                                        */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "devices/base.h"
#include "vex.h"
#include "functions/autonomous/autonomousGarra.h"
#include "functions/autonomous/bandaSetup.h"
#include "functions/autonomous/baseSetup.h"
#include "functions/autonomous/brazosSetup.h"
#include "functions/autonomous/driveSetup.h"
#include "functions/autonomous/manoSetup.h"
#include "functions/autonomous/resetEvery.h"

bool active = false, sentido = false;


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  SensorInethial.calibrate();
  resetEvery();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  Drivetrain.driveFor(forward, 49, inches);
  Valve1.set(0);
  Drivetrain.driveFor(reverse, 40, inches);
  Drivetrain.setTurnVelocity(20, percent);
  Drivetrain.turnToRotation(-90, degrees);
  Drivetrain.driveFor(reverse, 10, inches);
  ValveArm1.set(0);
  /* manoSetup(100, 100);
  brazosSetup(100, 100);
  resetEvery();
  autonomousGarra(); */
}

void changeValvula() {
  if(Control.ButtonX.pressing()) {
    ValveArm1.set(true);
  } else if(Control.ButtonB.pressing()) {
    ValveArm1.set(false);
  }
}

void MovL() {

  if (Control.Axis3.value() > 10) {
    MotoresL.spin(forward, Control.Axis3.value(), percent);
  } else if (Control.Axis3.value() < 0) {
    MotoresL.spin(forward, Control.Axis3.value(), percent);
  } else {
    MotoresL.stop();
  }
}

void MovR() {
  // MotoresR.spin(forward,Control.Axis2.value(),percent);
  if (Control.Axis2.value() > 10) {
    MotoresR.spin(forward, Control.Axis2.value(), percent);
  } else if (Control.Axis2.value() < 0) {
    MotoresR.spin(forward, Control.Axis2.value(), percent);
  } else {
    MotoresR.stop();
  }
}

void BrazoBackMov() {
  if (Control.ButtonL1.pressing()) {
    BrazoBack.spin(reverse);
  } else if (Control.ButtonL2.pressing()) {
    BrazoBack.spin(forward);
  } else {
    BrazoBack.stop();
  }
}

void ManoMov() {
  if (Control.ButtonR1.pressing()) {
    Brazo.spin(forward);
  } else if (Control.ButtonR2.pressing()) {
    Brazo.spin(reverse);
  } else {
    Brazo.stop();
  }
}

void GanchosCerrojo() {
  if (Control.ButtonUp.pressing()) {
    Valve1.set(true);
    wait(800, msec);
  }
  if (Control.ButtonDown.pressing()) {
    Valve1.set(false);
    wait(800, msec);
  }
}

void OtraValvula() {
  if (Control.ButtonY.pressing()) {
    ValveArm2.set(true);
    wait(800, msec);
  }
  if (Control.ButtonA.pressing()) {
    ValveArm2.set(false);
    wait(800, msec);
  }
}

void BandaMov() {

  if (active == true) {
    if (sentido == true) {
      MotorRiel.spin(forward);
    } else {
      MotorRiel.spin(reverse);
    }
  } else {
    MotorRiel.stop();
  }

  if (Control.ButtonUp.pressing()) {
    sentido = true;
    Control.rumble(".");
    wait(300, msec);
  } else if (Control.ButtonDown.pressing()) {
    sentido = false;
    Control.rumble(".");
    wait(300, msec);
  }

  if (Control.ButtonLeft.pressing()) {
    active = true;
    Control.rumble(".");
    wait(300, msec);
  } else if (Control.ButtonRight.pressing()) {
    active = false;
    Control.rumble(".");
    wait(300, msec);
  }
}

void usercontrol(void) {
  MotoresL.setStopping(hold);
  MotoresL.stop(hold);
  // User control code here, inside the loop
  while (1) {                                                                                                                    
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    baseSetup(100, 100);
    brazosSetup(100, 100);
    manoSetup(100, 100);
    bandaSetup(100, 100);
    changeValvula();
    MovL();
    MovR();
    BrazoBackMov();
    GanchosCerrojo();
    OtraValvula();
    ManoMov();
    BandaMov();
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
