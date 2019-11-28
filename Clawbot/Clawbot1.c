#pragma config(Motor,  port1,           right,         tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          left,          tmotorVex393_HBridge, openLoop, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){

	for(;;){

		//control motors with joysticks
		motor[leftm] = vexRT[Ch3];
		motor[rightm] = vexRT[Ch2];

		//Arm
		if (vexRT[Btn8D] == 1) motor[arm] = 100;
		else if(vexRT[Btn8U] == 1) motor[arm] = -100;
		else motor[claw_grip] = -10;

		//Claw
		if (vexRT[Btn7D] == 1) motor[claw] = 100;
		else if(vexRT[Btn7U] == 1) motor[claw] = -100;
		else motor[claw_turn] = 0;

	}

}
