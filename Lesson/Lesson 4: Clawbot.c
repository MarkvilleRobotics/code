#pragma config(Motor,  port1,           left,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port6,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          right,         tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//For joystick control:
task main()
{
	for(;;)
	{
		//Drivetrain
		motor[left] = vexRT[Ch2];
		motor[right] = vexRT[Ch3];
		//Default claw and arm do not move until button pressed.
		motor[claw] = 0; 
		motor[arm] = 0;
		
		//When a Boolean value is in a parameter of any statements, e.g. if, without any operators, when boolean is true statement is ran.
		//E.g, if(vexRT[Btn5U]) will run the statement if Btn5U has value 1.
		
		//When Button pressed, move defined motor. 
		//Claw Functions
		if (vexRT[Btn8L])
		{
			motor[claw] = -20;
		}
		if (vexRT[Btn8R])
		{
			motor[claw] = 20;
		}
		//Arm Functions
		if (vexRT[Btn7U])
		{
			motor[arm] = 50;
		}
		if (vexRT[Btn7D])
		{
			motor[claw] = -50;
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++