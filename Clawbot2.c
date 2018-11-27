#pragma config(Sensor, in1,    potentio,       sensorPotentiometer)
#pragma config(Motor,  port1,           rightf,        tmotorVex393_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port2,           rightb,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           H,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           claw_turn,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           claw_grip,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           leftb,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftf,         tmotorVex393_HBridge, openLoop, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*															- Dual Joystick Control with 4 Motors -																*|
|*																			ROBOTC on VEX 2.0 Cortex																			*|
|*																																																		*|
|*	This program uses both the Left and the Right joysticks to run the robot using "tank control".		*|
|*																																																		*|
|*																				ROBOT CONFIGURATION																					*|
|*		NOTES:																																													*|
|*		1)	Reversing both right-side motors (ports 2 and 3) in the "Motors and Sensors Setup" is				*|
|*				needed with the "VEX Tumbler" model, but may not be needed for all robot configurations.		*|
|*		2)	Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.															*|
|*		3)	Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.															*|
|*																																																		*|
|*		MOTORS & SENSORS:																																								*|
|*		[I/O Port]					[Name]								[Type]								[Description]										*|
|*		Motor Port 2				frontRightMotor				VEX 3-wire module			Right side motor								*|
|*		Motor Port 3				backRightMotor				VEX 3-wire module			Right side motor								*|
|*		Motor Port 4				frontLefttMotor				VEX 3-wire module			Left side motor									*|
|*		Motor Port 5				backLeftMotor					VEX 3-wire module			Left side motor									*|
\*----------------------------------------------------------------

------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
int rightside = 0;
int leftside = 0;
int hwheel;
bool reverse = false;

task main()
{
	for(;;){
		if (vexRT[Btn5U]==1){
			reverse=true;
		}else if (vexRT[Btn5D]==1){
			reverse=false;
		}

		//left side of the robot is controlled by the right joystick, Y-axis
		//rightm] = -vexRT[Ch3];
		//right side of the robot is controlled by the left joystick, Y-axis
		//motor[leftm] = -vexRT[Ch2];

		if(!reverse){
			leftside = vexRT[Ch2];
			rightside = vexRT[Ch3];
			hwheel = -(vexRT[Ch1]+vexRT[Ch4])/2;
		}
		else{
			leftside = -vexRT[Ch3];
			rightside = -vexRT[Ch2];
			hwheel = (vexRT[Ch1]+vexRT[Ch4])/2;
		}

		//Claw buttons
		motor[claw_grip] = 0;
		if (vexRT[Btn8L] == 1)
		{
			motor[claw_grip] = 100;
		}
		if(vexRT[Btn8R] == 1)
		{
			motor[claw_grip] = -100;
		}
	//Claw Turning
		motor[claw_turn] = 0;
		if (vexRT[Btn8U] == 1)
		{
			motor[claw_turn] = 100;
		}
		if(vexRT[Btn8D] == 1)
		{
			motor[claw_turn] = -100;
		}
		motor[rightf] = rightside;
		motor[rightb] = rightside;
		motor[leftf] = leftside;
		motor[leftb] = leftside;
		motor[H] = hwheel;
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++