#pragma config(Motor,  port1,           left,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port5,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          right,         tmotorVex393_HBridge, openLoop, reversed)

void move_arm()
{
		motor[left]=127;
		motor[right]=127;
		wait(10);
		motor[left]=0;
		motor[right]=0;
		motor[arm]=20;
		wait(5);
		motor[arm]=0;
		motor[left]=127;
		motor[right]=127;
		wait(2);
		motor[left]=0;
		motor[right]=0;
		motor[claw]=24;
		wait(2);
}


task main()
{
	while(true)
	{
		//left side of the robot is controlled by the right joystick, Y-axis
		motor[left] = vexRT[Ch3];
		//righ side of the robot is controlled by the left joystick, Y-axis
		motor[right] = vexRT[Ch2];
		//Claw buttons
		if (vexRT[Btn6U])
		{
			motor[claw] = -10;
		}
		else if (vexRT[Btn6D])
		{
			motor[claw] = 10;
		}
		else
		{
			motor[claw] = 0;
		}

		//Claw turning

		if (vexRT[Btn5U])
		{
			motor[arm] = -10;
		}
		else if (vexRT[Btn5D])
		{
			motor[arm] = 10;
		}
		else
		{
			motor[arm] = 0;
		}
		if (vexRT[Btn8D])
		{
			move_arm();
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
