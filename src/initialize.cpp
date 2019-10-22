#include "main.h"


Controller master(E_CONTROLLER_MASTER);
Controller partner(E_CONTROLLER_PARTNER);

Motor driveLF(6, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor driveLB(7, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

Motor driveRF(8, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor driveRB(9, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);

Motor lifty(4, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
Motor stacky(5, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);

Motor leftSuck(2, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_ROTATIONS);
Motor rightSuck(10, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_ROTATIONS);

void initialize() {
	//auto liftpid = okapi::AsyncControllerFactory::posIntegrated(4);
	stacky.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	lifty.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	rightSuck.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	leftSuck.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveLF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveLB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveRF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveRB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	pros::lcd::initialize();


	//pros::motor_pid_s_t pid = pros::Motor::convert_pid(KF, KP, KI, KD);
	//intakeTilt.set_pos_pid(pid);

	ADIDigitalIn boistop('a');
	ADIDigitalIn downis('b');
	ADIUltrasonic rightUltra ('g', 'h');
	ADIUltrasonic leftUltra ('e', 'f');
	ADIPotentiometer liftyPent ('c');
	ADIPotentiometer stackyPent ('d');

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
}

void competition_initialize() {
}
