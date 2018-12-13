#pragma config(Sensor, in1,    potentio,       sensorPotentiometer)
#pragma config(Motor,  port1,           leftm,         tmotorVex393_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port6,           claw_turn,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           claw_grip,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightm,        tmotorVex393_HBridge, openLoop, driveRight)

void moveArm(int signal){
	while (fabs(signal - SensorValue(potentio)) > 25){
		int error = 0.5 * (signal - SensorValue(potentio));
		if (fabs(error) > 127){
			error = 127 * fabs(error)/error;
		}
		motor[claw_turn] = error;
	}
	motor[claw_turn]=0;
	if (SensorValue(potentio)<=4050&&SensorValue(potentio)>=4000){
		motor[claw_grip]=-100;
		wait(0.7);
	}
	return;
}

task main()
{
	for(;;){
		//left side of the robot is controlled by the right joystick, Y-axis
		motor[rightm] = -vexRT[Ch3];
		//right side of the robot is controlled by the left joystick, Y-axis
		motor[leftm] = -vexRT[Ch2];
		//Claw buttons
		if (vexRT[Btn7L] == 1)
			motor[claw_grip] = 100;
		else if(vexRT[Btn7R] == 1)
			motor[claw_grip] = -100;
		else
			motor[claw_grip] = 0;
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
		const int signal = 4050;
		//Experimental: Automated Grabbing from ground
		//if (vexRT[Btn5D]==1){

		if(vexRT[Btn5D]==1){
			moveArm(signal);
		}
		//}
		//Experimental: Automated Release
		if (vexRT[Btn5U]==1){
			for (;;){
				while (SensorValue(potentio)<3400){
					motor[claw_turn] = -20;
					wait(1);
				}
				while (SensorValue(potentio)>3500){
					motor[claw_turn] = +20;
					wait(1);
				}
				if (SensorValue(potentio)<=3500&&SensorValue(potentio)>=3400){
					motor[claw_turn]=0;
					motor[claw_grip]=100;
					wait(0.7);
					break;
				}
			}
		}
	}
}
