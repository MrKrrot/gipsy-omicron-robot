#pragma once
#include "vex.h"
/*--| MOTORES |--*/
// Motores Izquierda
motor MotorL1 = motor(PORT11, ratio6_1, false);
motor MotorL2 = motor(PORT12, ratio6_1, false);
motor MotorL3 = motor(PORT15, ratio6_1, true);
motor MotorL4 = motor(PORT13, ratio6_1, false);
motor_group MotoresL = motor_group(MotorL1, MotorL2, MotorL3, MotorL4);

// Motores Derecha
motor MotorR1 = motor(PORT20, ratio6_1, true);
motor MotorR2 = motor(PORT19, ratio6_1, true);
motor MotorR3 = motor(PORT16, ratio6_1, false);
motor MotorR4 = motor(PORT18, ratio6_1, true);
motor_group MotoresR = motor_group(MotorR1, MotorR2, MotorR3, MotorR4);

// Motores Brazos
motor Garra = motor(PORT4, ratio36_1, true);
motor BrazoBack = motor(PORT9, ratio36_1, false);
motor BrazoR = motor(PORT7, ratio36_1, false);
motor BrazoL = motor(PORT1, ratio36_1, true);
motor_group Brazo = motor_group(BrazoR, BrazoL);
motor MotorRiel = motor(PORT5, ratio18_1, true);