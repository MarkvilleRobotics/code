#pragma config(Motor,  port2,           left1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           left2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           right1,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           right2,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           arm_rotate,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           claw_invup,    tmotorVex393_MC29, openLoop, reversed)//This claw is inverted due to the motor strength needed to push the arm up
#pragma config(Motor,  port8,           claw_up,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           claw_grip,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#pragma config(Motor,	 port10,					 ,						 tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard							 !!*//

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
\*----------------------------------------------------------------------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	while(true)
	{
		//left side of the robot is controlled by the right joystick, Y-axis
		motor[left1] = vexRT[Ch3];
		motor[left2] = vexRT[Ch3];
		//righ side of the robot is controlled by the left joystick, Y-axis
		motor[right1] = vexRT[Ch2];
		motor[right2] = vexRT[Ch2];
		//Claw
		motor[claw_up] = vexRT[Ch1];
		motor[claw_invup] = vexRT[Ch1];
		motor[arm_rotate] = vexRT[Ch4];



		if (vexRT[Btn8R])//Buttons on right
		{
			motor[claw_grip] = -1;
		}
		else if (vexRT[Btn8D])
		{
			motor[claw_grip] = 1;
		}
		else
		{
			motor[claw_grip] = 0;
		}


	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++