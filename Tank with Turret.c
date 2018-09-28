#pragma config(Motor,  port1,           left1,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           right1,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rotate,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           left2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          right2,        tmotorVex393_HBridge, openLoop, reversed)

task main()
{
	while(true)
	{
		motor[left1] = vexRT[Ch3];
		motor[left2] = vexRT[Ch3];
		motor[right1] = vexRT[Ch2];
		motor[right2] = vexRT[Ch2];
		if (vexRT[Btn6U]==1)
		{
			motor[rotate] = -32;
		}
		else if (vexRT[Btn5U]==1)
		{
			motor[rotate] = 32;
		}
		else
		{
			motor[rotate] = 0;
		}

	}
}
