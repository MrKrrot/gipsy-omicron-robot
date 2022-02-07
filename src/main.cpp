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

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;
brain Brain;
controller Control=controller(primary);

motor MotorL1=motor(PORT11,ratio36_1,false);
motor MotorL2=motor(PORT12,ratio36_1,true);
motor MotorL3=motor(PORT13,ratio36_1,false);
motor_group MotoresL=motor_group(MotorL1,MotorL2,MotorL3);

motor MotorR1=motor(PORT20,ratio36_1,true);
motor MotorR2=motor(PORT19,ratio36_1,false);
motor MotorR3=motor(PORT18,ratio36_1,true);
motor_group MotoresR=motor_group(MotorR1,MotorR2,MotorR3);

inertial SensorInethial=inertial(PORT3);

smartdrive Drivetrain=smartdrive(MotoresL,MotoresR,SensorInethial, 319.19 , 368.3 , 406.4 , mm , 1 );

motor BrazoR=motor(PORT7,ratio36_1,false);
motor BrazoL=motor(PORT1,ratio36_1,true);
motor_group Brazo=motor_group(BrazoR,BrazoL);
motor Garra=motor(PORT4,ratio36_1,true);

motor BrazoBack=motor(PORT9,ratio36_1,false);
rotation SensorDeRotL=rotation(PORT14,true);

distance SensorDeDistancia=distance(PORT8);

pneumatics ValveArm1=pneumatics(Brain.ThreeWirePort.A);
pneumatics ValveArm2=pneumatics(Brain.ThreeWirePort.B);

bumper BumperFrontal=bumper(Brain.ThreeWirePort.H);

motor PXNDX=motor(PORT5,ratio18_1,true);

bool active=false, sentido=false;

void BaseSetUp(int v, int t){
  MotoresL.setVelocity(v, percent);
  MotoresL.setMaxTorque(t,percent);
  MotoresL.setStopping(hold);
  MotoresR.setVelocity(v, percent);
  MotoresR.setMaxTorque(t,percent);
  MotoresR.setStopping(hold);
}

void DriveSetUp(int v, int r){
  Drivetrain.setTurnVelocity(r, percent);
  Drivetrain.setDriveVelocity(v, percent);
  Drivetrain.setStopping(hold);
}

void BrazosSetUp(int v, int t){
  BrazoBack.setVelocity(v, percent);
  BrazoBack.setMaxTorque(t,percent);
  BrazoBack.setStopping(hold);

}

void ManoSetup(int v, int t){
  Brazo.setVelocity(v, percent);
  Brazo.setMaxTorque(t,percent);
  Brazo.setStopping(hold);

  Garra.setVelocity(v, percent);
  Garra.setMaxTorque(t,percent);
  Garra.setStopping(hold);
}

void BandaSetUp(int v, int t){
  PXNDX.setVelocity(v, percent);
  PXNDX.setMaxTorque(t,percent);
  PXNDX.setStopping(hold);
}

void ResetEvery(){
  MotoresL.resetRotation();
  MotoresR.resetRotation();
  SensorDeRotL.resetPosition();
  SensorDeRotL.setPosition(0, degrees);
  Garra.resetRotation();
  Brazo.resetRotation();

}


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  SensorInethial.calibrate();
  ResetEvery();
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

void BrazosBackMovAut(bool i){
  while(1){
    if(i==1){
      if(SensorDeRotL.position(degrees)<=93){
        BrazoBack.spin(reverse);
      }else {
        BrazoBack.stop();
        break;
      }
    }else {
      if(SensorDeRotL.position(degrees)>=50){
        BrazoBack.spin(forward);
      }else {
        BrazoBack.stop();
        break;
      }
    }
  }
}


void PistonesAutom(bool L){
  if(L==0){
    ValveArm1.close();
    ValveArm2.open();
  }else {
    ValveArm1.open();
    ValveArm2.close();
  }
}

void AvanzeDistanciaBase(int i){
  while(SensorDeDistancia.objectDistance(mm)<=i){
    Drivetrain.drive(forward);
  }
  Drivetrain.stop();
}

void RetrocesoDistanciaBase(int i){
  while(SensorDeDistancia.objectDistance(mm)>=i){
    Drivetrain.drive(reverse);
  }
  Drivetrain.stop();
}

void AvanzeBumperLimitAutom(int i){
  PistonesAutom(0);
  while(!BumperFrontal.pressing()&&SensorDeDistancia.objectDistance(mm)<=i){
    Drivetrain.drive(forward);
  }
  Drivetrain.stop(hold);
}

void AvanzeBumperAutom(){
  while(!BumperFrontal.pressing()){
    Drivetrain.drive(forward);
  }
  Drivetrain.stop(hold);
}

void AutonomoGarra(){
  while(!BumperFrontal.pressing()&&SensorDeDistancia.objectDistance(mm)<=1600){
    Drivetrain.drive(forward);
    if(MotoresL.rotation(degrees)>650){
      DriveSetUp(40, 100);
    }
  }
  Control.Screen.print(SensorDeDistancia.objectDistance(mm));
  Control.Screen.print("-");
  Control.Screen.print(MotoresL.rotation(deg));
  Drivetrain.stop(hold);
  if(SensorDeDistancia.objectDistance(mm)<=1800){
    Garra.setTimeout(1000, msec);
    Garra.spinFor(reverse, 300, degrees);//150
    Garra.spin(reverse);
    Brazo.spinFor(forward,200,degrees);
    Drivetrain.stop();
    DriveSetUp(100, 100);
    Garra.stop();
    Drivetrain.driveFor(reverse,5,inches);
    Brazo.spinFor(reverse,100,degrees);
    Drivetrain.setTurnVelocity(5, percent);
    Drivetrain.turnFor(left,45,degrees);
    Drivetrain.turnToHeading(315, degrees);
    PistonesAutom(0);
    BrazosBackMovAut(1);
    Drivetrain.driveFor(reverse, 7, inches);
    wait(1, sec);
    PistonesAutom(1);
    BrazosBackMovAut(0);

    Drivetrain.turnFor(right,45,degrees);
    Drivetrain.turnToHeading(0, degrees);
    Drivetrain.driveFor(reverse,15,inches);
    /*********************/
  }else {
    DriveSetUp(100, 100);
    Drivetrain.driveFor(reverse,20,inches);
  }
}

void Autonomo(){

}


void Skills(){


}

void Skills2(){
  
}

void autonomous(void) {
  DriveSetUp(100, 10);
  ManoSetup(100, 100);
  BrazosSetUp(100, 100);
  ResetEvery();
  AutonomoGarra();
  //AutonomoGarraCenter();
  //Skills2();
}


void MovL(){
  //MotoresL.spin(forward,Control.Axis3.value(),percent);

  if(Control.Axis3.value()>10){
    MotoresL.spin(forward,Control.Axis3.value(),percent);
  }else if(Control.Axis3.value()<0){
    MotoresL.spin(forward,Control.Axis3.value(),percent);
  }else {
    MotoresL.stop();
  }

}

void MovR(){
  //MotoresR.spin(forward,Control.Axis2.value(),percent);
  if(Control.Axis2.value()>10){
    MotoresR.spin(forward,Control.Axis2.value(),percent);
  }else if(Control.Axis2.value()<0){
    MotoresR.spin(forward,Control.Axis2.value(),percent);
  }else {
    MotoresR.stop();
  }

}

void BrazoBackMov(){
  if(Control.ButtonL1.pressing()){
    BrazoBack.spin(forward);
  }else if(Control.ButtonL2.pressing()){
    BrazoBack.spin(reverse);
  }else{
    BrazoBack.stop();
  }
}

void ManoMov(){
  if(Control.ButtonR1.pressing()){
    Brazo.spin(forward);
  }else if(Control.ButtonR2.pressing()){
    Brazo.spin(reverse);
  }else{
    Brazo.stop();
  }
}

void GarraMov(){
  if(Control.ButtonX.pressing()){
    Garra.spin(forward);
  }else if(Control.ButtonB.pressing()){
    Garra.spin(reverse);
  }else{
    Garra.stop();
  }
}

void GanchosCerrojo(){
  if(Control.ButtonY.pressing()){
    ValveArm1.set(true);
    ValveArm2.set(false);

    wait(800, msec);
  }if(Control.ButtonA.pressing()){
      ValveArm1.set(false);
      ValveArm2.set(true);
      wait(800, msec);
  }
}

void BandaMov(){

  if(active==true){
      if(sentido==true){
        PXNDX.spin(forward);
      }else{
        PXNDX.spin(reverse);
      }
  }else {
    PXNDX.stop();
  }

  if(Control.ButtonUp.pressing()){
    sentido=true;
    Control.rumble(".");
    wait(300, msec);
  }else if (Control.ButtonDown.pressing()) {
    sentido=false;
    Control.rumble(".");
    wait(300, msec);
  }

  if(Control.ButtonLeft.pressing()){
    active=true;
    Control.rumble(".");
    wait(300, msec);
  }else if (Control.ButtonRight.pressing()) {
    active=false;
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
    BaseSetUp(80, 100);
    BrazosSetUp(100, 100);
    ManoSetup(100, 100);
    BandaSetUp(80, 100);
    
    MovL();
    MovR();
    BrazoBackMov();
    GanchosCerrojo();
    ManoMov();
    GarraMov();
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
