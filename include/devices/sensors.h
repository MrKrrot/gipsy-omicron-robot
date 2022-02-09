#pragma once
#include "vex.h"
#include "base_motors.h"
// A global instance of competition
competition Competition;
brain Brain;
controller Control = controller(primary);

/*--| SENSORES |--*/
// Sensores
inertial SensorInethial = inertial(PORT3);
rotation SensorDeRotL = rotation(PORT14, true);
distance SensorDeDistancia = distance(PORT8);

// Otros sensores
bumper BumperFrontal = bumper(Brain.ThreeWirePort.H);
pneumatics ValveArm1 = pneumatics(Brain.ThreeWirePort.A);
pneumatics ValveArm2 = pneumatics(Brain.ThreeWirePort.B);

// Drivetrain
smartdrive Drivetrain = smartdrive(MotoresL, MotoresR, SensorInethial, 319.19 , 368.3 , 406.4 , mm , 1);