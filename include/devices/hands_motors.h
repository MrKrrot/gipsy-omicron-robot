#pragma once
#include "vex.h"

// Motores Brazos
motor BrazoR = motor(PORT7, ratio36_1, false);
motor BrazoL = motor(PORT1, ratio36_1, true);
motor_group Brazo = motor_group(BrazoR, BrazoL);
motor BrazoBack = motor(PORT9, ratio36_1, false);
motor Garra = motor(PORT4, ratio36_1, true);
motor MotorRiel = motor(PORT5, ratio18_1, true);