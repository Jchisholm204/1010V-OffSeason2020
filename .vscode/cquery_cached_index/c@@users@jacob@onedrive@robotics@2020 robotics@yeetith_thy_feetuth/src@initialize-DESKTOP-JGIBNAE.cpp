#include "main.h"
/*
#define KF 0
#define KP 1.0f
#define KI 0.001f
#define KD 0.1f
*/
#define KF 0
#define KP 1.0f
#define KI 0.001f
#define KD 0.1f
#define FILTER 1.0f
#define LIMIT 1.0f
#define THRESHOLD 1.0f
#define LOOPSPEED 10

Controller master(E_CONTROLLER_MASTER);
Controller partner(E_CONTROLLER_PARTNER);

Motor driveLF(6, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor driveLB(7, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

Motor driveRF(8, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor driveRB(9, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);

Motor lifty(4, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
Motor stacky(5, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);

Motor leftSuck(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_ROTATIONS);
Motor rightSuck(1, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_ROTATIONS);

void initialize() {
	lcd::initialize();

	motor_pid_full_s_t pid = Motor::convert_pid_full(KF, KP, KI, KD, FILTER, LIMIT, THRESHOLD, LOOPSPEED);
	motor_pid_s_t suck = Motor::convert_pid(KF, KP, KI, KD);
//set brake modes

	lifty.set_pos_pid_full(pid);
	stacky.set_pos_pid_full(pid);
	stacky.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	lifty.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	rightSuck.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	leftSuck.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	driveLF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveLB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveRF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveRB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);


	//pros::motor_pid_s_t pid = pros::Motor::convert_pid(KF, KP, KI, KD);
	//intakeTilt.set_pos_pid(pid);
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
