#pragma once
#include "vex.h"
#include "devices/base.h"
// Sensores
inertial SensorInethial = inertial(PORT3);
rotation SensorDeRotL = rotation(PORT14, true);
distance SensorDeDistancia = distance(PORT8);

// Otros sensores
bumper BumperFrontal = bumper(Brain.ThreeWirePort.H);
digital_out ValveArm1 = digital_out(Brain.ThreeWirePort.A);
digital_out ValveArm2 = digital_out(Brain.ThreeWirePort.B);
pneumatics Valve1 = pneumatics(Brain.ThreeWirePort.D);

smartdrive Drivetrain = smartdrive(MotoresL, MotoresR, SensorInethial, 319.19 , 368.3 , 406.4 , mm , 1);