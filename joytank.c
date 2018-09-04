#pragma config(Motor,  port2,           left1,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           left2,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           right1,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           right2,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                - Clawbot Single Joystick Control -                                 *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses a single joystick, either right or left to drive the robot. Use notes below     *|
|*  to reconfigure which joystick is used. The joystick buttons are used to raise and lower the arm.	*|
|*  The joystick buttons are used to open and close the claw.																					*|
|*																																																		*|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)	Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)	Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*		3)	Button 5U and 5L are on the front left side of the joystick.																*|
|*		3)	Button 6U and 6L are on the front right side of the joystick.																*|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]        [Name]          [Type]                               [Description]            *|
|*    Motor - Port 2   right1    VEX 393 Motor                         Right drive motor          *|
|*    Motor - Port 6   clawMotor     VEX 393 Motor w/ Motor Controler 29   Claw motor                 *|
|*    Motor - Port 7   right2      VEX 393 Motor w/ Motor Controler 29   Arm motor                  *|
|*    Motor - Port 10  left1     VEX 393 Motor                         Left drive motor           *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

		/*motor[left1]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
		motor[right2] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2

// Raise, lower or do not move arm
		if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
		{
			motor[right2] = 127;    	//...raise the arm.
		}
		else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
		{
			motor[right2] = -127;   	//...lower the arm.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[right2] = 0;      	//...stop the arm.
		}

// Open, close or do not more claw
		if(vexRT[Btn6U] == 1)       	//If Button 6U is pressed...
		{
			motor[clawMotor] = 127;  		//...close the gripper.
		}
		else if(vexRT[Btn6D] == 1)  	//Else, if button 6D is pressed...
		{
			motor[clawMotor] = -127; 		//...open the gripper.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[clawMotor] = 0;    		//...stop the gripper.
		}
		*/
task main ()
{

	while(true)
	{
		motor[left1]  = (vexRT[Ch2]);  // (y + x)/2
		motor[left2] = (vexRT[Ch2]);  // (y - x)/2
		motor[right1]  = (vexRT[Ch3]);  // (y + x)/2
		motor[right2] = (vexRT[Ch3]

		);  // (y - x)/2
}
}
