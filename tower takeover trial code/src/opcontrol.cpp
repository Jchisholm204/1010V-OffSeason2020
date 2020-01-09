#include "main.h"
//exp drive
int expo (int joyVal, float driveExp, int joyDead, int motorMin) {
		int joySign;
		int joyMax = 127 - joyDead;
		int joyLive = abs(joyVal) - joyDead;
		if (joyVal > 0) {joySign = 1;}
		else if (joyVal < 0) {joySign = -1;}
		else {joySign = 0;}
		int power = joySign * (motorMin + ((100 - motorMin) * pow(joyLive, driveExp) / pow(joyMax, driveExp)));
		return power;
}

//lift poz
int HOLDPOS;
int LOWSTOP = 0;

const int cJoyDead = 8; //Joystick range in which movement is considered accidental
const int cMotorMin = 15; //Minimum drive motor power
const float cDriveExp = 1.5; //Exponent for drive power calculations  (1 = linear, 2 = squared) //1.4
const float cStackExp = 1.5;

void opcontrol() {
	//ADI
	ADIDigitalIn boistop('a');
	ADIDigitalIn downis('b');
	ADIUltrasonic rightUltra('g', 'h');
	ADIUltrasonic leftUltra('e', 'f');
	ADIPotentiometer stackyPent('d');
	stackyPent.calibrate();
	while(true) {
		//all screen stuff doesent work, use consle instead
		//Identify Controller
		partner.print(0, 0, "Brian");
		master.print(0, 0, "Stewie");
		//Print to V5 screen
		pros::lcd::print(1, "VOID: opcontrol");
		pros::lcd::print(2, "RoBoTiS Battery Capacity: %f", battery::get_capacity());
		pros::lcd::print(3, "stackyPent: %d", stackyPent.get_value());
		//lcd::print(4, "rightUltra: %d", rightUltra.get_value());
		//lcd::print(5, "leftUltra: %d", leftUltra.get_value());
		//lcd::print(6, "lifty POS: %d", lifty.get_position());

		//the screen hates me so post to consle
		std::cout << "LiftyPOS:" << lifty.get_position();
		std::cout << "stackyPOS:" << stacky.get_position();
		std::cout << "Battery:" << battery::get_voltage();
		std::cout << "stackPent:" << stackyPent.get_value_calibrated();

		//Map expo to controller Analog
		int Y1 = expo(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y), cDriveExp, cJoyDead, cMotorMin); //Expo Forward-Backwards
		int X1 = expo(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X), cDriveExp, cJoyDead, cMotorMin); //Expo Yaw
		int LIFTEXP = expo((partner.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)), cStackExp, cJoyDead, cMotorMin);
		//int L2 = expstack((master.get_digital(E_CONTROLLER_DIGITAL_L1)), cDriveExp, cJoyDead, cMotorMin);
		//Expo drive outputs
		driveLF.move( Y1 + X1 );  //map LF to left y, right X
		driveLB.move( Y1 + X1 );  //map LB to left y, right X
		driveRF.move( Y1 - X1 );  //map RF to left y, right X
		driveRB.move( Y1 - X1 );  //map RB to left y, right X
		//Arms Lift
		if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
			lifty.move_velocity(100);
		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2) && !boistop.get_value()) {
			lifty.move_velocity(-100);
		}
		else {
			lifty.get_position() == HOLDPOS;
			lifty.move_absolute(HOLDPOS, 0);
		};

		//Intake
		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			leftSuck.move_velocity(100);
			rightSuck.move_velocity(100);
		}
		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			leftSuck.move_velocity(-100);
			rightSuck.move_velocity(-100);
		}
		else if(partner.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			leftSuck.move_velocity(100);
			rightSuck.move_velocity(100);
		}
		else if(partner.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			leftSuck.move_velocity(-100);
			rightSuck.move_velocity(-100);
		}
		else if(master.get_digital(E_CONTROLLER_DIGITAL_B)) {
			leftSuck.move_velocity(-70);
			rightSuck.move_velocity(-70);
		}
		else if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN)) {
			leftSuck.move_velocity(60);
			rightSuck.move_velocity(60);
		}
		else {
			leftSuck.move_velocity(0);
			rightSuck.move_velocity(0);
		};


		if(partner.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) > 0) {
			stacky.move(LIFTEXP);
			LOWSTOP = 0;
		}
		else if(downis.get_value() == true) {
			LOWSTOP = 1;
			stacky.move_velocity(0);
		}
		else if(LOWSTOP == 0) {
			stacky.move(LIFTEXP);
		};
	}
}
