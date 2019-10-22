#include "main.h"
//#include "pros/adi.hpp"
using namespace okapi;
//be mindfull of pros namespace

auto driveF = okapi::ChassisControllerFactory::create (
               {6, 7}, {-8, -9}, //Left Ports + Right Ports
               okapi::AbstractMotor::gearset::green, //Motor Gear Ration
               {3_in, 12.75_in} //Wheel Diameter + Base Width
             );

//profileControllerF == motionProfile
auto profileControllerF = AsyncControllerFactory::motionProfile(0.0001, 0.0001, 0, driveF);
//GROUP: intake
//auto intake = okapi::ChassisControllerFactory::create(-1, 2);

//Variables
int moveboi;
int stackValue;
int liftValue;
int RightDrive;
int LeftDrive;
//autonvoid
void autonomous() {

  //Variables
  stacky.get_position() == stackValue;
  lifty.get_position() == liftValue;


  //ADI
  ADIDigitalIn boistop('a');
	ADIDigitalIn downis('b');
  pros::ADIPotentiometer stackyPent('d');
	pros::ADIUltrasonic rightUltra ('g', 'h');
	pros::ADIUltrasonic leftUltra ('e', 'f');
  //Display
  pros::lcd::print(1, "VOID: AUTON");

  //AUTON
//Flipout ver-2

  stacky.move_absolute(stackValue + 700, 100);
  pros::delay(1800);
  stacky.move_absolute(stackValue, -100);
  pros::delay(400);
  lifty.move_absolute(liftValue + 400, 100);
  pros::delay(800);
  lifty.move_absolute(liftValue, -100);
  //pros::delay(400);


   /*//ShitAuto
  driveF.moveDistance(-1_ft);
  pros::delay(1000);
  driveF.moveDistance(0.5_ft);
*/
/*    //red
  leftSuck.move_velocity(100);
  rightSuck.move_velocity(100);
  driveF.moveDistance(-0.1_ft);
  //pros::delay(200);
  //driveF.moveDistance(3_ft);

  driveRF.move_velocity(70);
  driveRB.move_velocity(70);
  driveLB.move_velocity(70);
  driveLF.move_velocity(70);

  pros::delay(3400);
  driveF.stop();
  pros::delay(200);

  driveRF.move_velocity(-200);
  driveRB.move_velocity(-200);
  driveLB.move_velocity(-200);
  driveLF.move_velocity(-200);

  pros::delay(1200);
  leftSuck.move(0);
  rightSuck.move(0);
  driveF.stop();

  driveRF.move_velocity(70);
  driveRB.move_velocity(70);
  driveLB.move_velocity(70);
  driveLF.move_velocity(70);

  pros::delay(750);
  driveF.stop();

  driveRF.move_velocity(-90);
  driveRB.move_velocity(-90);
  driveLB.move_velocity(90);
  driveLF.move_velocity(90);

  pros::delay(930);
  driveF.stop();

  driveRF.move_velocity(50);
  driveRB.move_velocity(50);
  driveLB.move_velocity(50);
  driveLF.move_velocity(50);

  pros::delay(180);
  rightSuck.move_velocity(-55);
  leftSuck.move_velocity(-55);
  pros::delay(720);
  rightSuck.move_velocity(0);
  leftSuck.move_velocity(0);
  driveF.stop();


  stacky.move_absolute(stackValue + 1000, 70);
  pros::delay(1000);
  driveRF.move_velocity(30);
  driveRB.move_velocity(30);
  driveLB.move_velocity(30);
  driveLF.move_velocity(30);
  pros::delay(600);

  driveRF.move_velocity(-20);
  driveRB.move_velocity(-20);
  driveLB.move_velocity(-20);
  driveLF.move_velocity(-20);
*/
   //blue
  leftSuck.move_velocity(1000);
  rightSuck.move_velocity(1000);
  driveF.moveDistance(-0.1_ft);
  //pros::delay(100);
  //driveF.moveDistance(3_ft);

  driveRF.move_velocity(70);
  driveRB.move_velocity(70);
  driveLB.move_velocity(70);
  driveLF.move_velocity(70);

  pros::delay(3400);
  driveF.stop();
  pros::delay(200);

  driveRF.move_velocity(-170);
  driveRB.move_velocity(-170);
  driveLB.move_velocity(-170);
  driveLF.move_velocity(-170);
  pros::delay(200);
  driveRF.move_velocity(-200);
  driveRB.move_velocity(-200);
  driveLB.move_velocity(-200);
  driveLF.move_velocity(-200);

  pros::delay(1000);
  leftSuck.move(0);
  rightSuck.move(0);
  driveF.stop();

  driveRF.move_velocity(150);
  driveRB.move_velocity(150);
  driveLB.move_velocity(150);
  driveLF.move_velocity(150);
  pros::delay(550);
  driveRF.move_velocity(100);
  driveRB.move_velocity(100);
  driveLB.move_velocity(100);
  driveLF.move_velocity(100);
  pros::delay(280);
  driveF.stop();

  driveRF.move_velocity(90);
  driveRB.move_velocity(90);
  driveLB.move_velocity(-90);
  driveLF.move_velocity(-90);

  pros::delay(915);
  driveF.stop();

  driveRF.move_velocity(70);
  driveRB.move_velocity(70);
  driveLB.move_velocity(70);
  driveLF.move_velocity(70);

  //pros::delay(180);
  rightSuck.move_velocity(-60);
  leftSuck.move_velocity(-60);
  pros::delay(730);
  rightSuck.move_velocity(0);
  leftSuck.move_velocity(0);
  driveF.stop();


  stacky.move_absolute(stackValue + 975, 70);
  pros::delay(1200);
  driveRF.move_velocity(30);
  driveRB.move_velocity(30);
  driveLB.move_velocity(30);
  driveLF.move_velocity(30);
  pros::delay(600);

  driveRF.move_velocity(-20);
  driveRB.move_velocity(-20);
  driveLB.move_velocity(-20);
  driveLF.move_velocity(-20);

}
