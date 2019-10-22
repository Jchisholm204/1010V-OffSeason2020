#include "main.h"

int expDrive (int joyVal, float driveExp, int joyDead, int motorMin) {
		int joySign;
		int joyMax = 127 - joyDead;
		int joyLive = abs(joyVal) - joyDead;
		if (joyVal > 0) {joySign = 1;}
		else if (joyVal < 0) {joySign = -1;}
		else {joySign = 0;}
		int power = joySign * (motorMin + ((100 - motorMin) * pow(joyLive, driveExp) / pow(joyMax, driveExp)));
		return power;
} //END int expDrive


const int cJoyDead = 8; //Joystick range in which movement is considered accidental
const int cMotorMin = 15; //Minimum drive motor power
const float cDriveExp = 1.5; //Exponent for drive power calculations  (1 = linear, 2 = squared) //1.4


void opcontrol() {
	ADIDigitalIn boistop('a');
	ADIDigitalIn downis('b');
	ADIUltrasonic rightUltra ('g', 'h');
	ADIUltrasonic leftUltra ('e', 'f');
	while(true) {
		master.print(0, 0, "Master");
		partner.print(0, 0, "Slave");
		lcd::print(1, "Yeetith Thy Feetuth");
		lcd::print(3, "Master Battery: %ff", master.get_battery_level());
		lcd::print(3, "RoBoTiS Battery Capacity: %ff", battery::get_capacity());
		lcd::print(4, "RoBoTiS Battery mVoltage: %ff", battery::get_voltage());
		int Y1 = expDrive(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y), cDriveExp, cJoyDead, cMotorMin); //Expo Forward-Backwards
		int Z1 = expDrive(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X), cDriveExp, cJoyDead, cMotorMin); //Expo Yaw

		driveLF.move( Y1 + Z1 );  //map LF to left y, right X
		driveLB.move( Y1 + Z1 );  //map LB to left y, right X
		driveRF.move( Y1 - Z1 );  //map RF to left y, right X
		driveRB.move( Y1 - Z1 );  //map RB to left y, right X

		if(master.get_digital(E_CONTROLLER_DIGITAL_L2) && !boistop.get_value()) {
			lifty.move(-127);
		}

		else if (master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
			lifty.move(127);
		}
		else {
			lifty.move(0);
		};
		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			leftSuck.move(127);
			rightSuck.move(127);
		}
		else if(master.get_digital(E_CONTROLLER_DIGITAL_X)) {
			leftSuck.move(-50);
			rightSuck.move(-50);
		}
		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			leftSuck.move(-127);
			rightSuck.move(-127);
		}
		else {
			leftSuck.move(0);
			rightSuck.move(0);
		};
		if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN) && !downis.get_value()) {
			stacky.move(55);
		}
		else if(master.get_digital(E_CONTROLLER_DIGITAL_B)) {
			stacky.move(-55);
		}
		else {
			stacky.move(0);
		};

	 }
 }
