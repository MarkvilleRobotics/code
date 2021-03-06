#pragma config(Motor,  port1,           LEFTFRONT,     tmotorVex393_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port2,           LEFTBACK,      tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port3,           ARM,           tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port4,           CLAW,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RIGHTBACK,     tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port10,          RIGHTFRONT,    tmotorVex393_HBridge, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	bool fast = false;
	bool reverse = false;

	//bool fastpress = false;
	bool reversepress = false;

	int left = 0;
	int right = 0;

	int clawspeed = 0;
	int armspeed = 0;

	for (;;){

		/* Toggle control
		if(vexRT[Btn6U] == 1 && !fastpress){
		fast = !fast;
		fastpress = true;
		}
		else if(vexRT[Btn6U] == 0 && fastpress){
		fastpress = false;
		}
		*/

		//hold to go fast
		if(vexRT[Btn6U] == 1){
			fast = true;
		}
		else{
			fast = false;
		}

		// toggle reverse
		if(vexRT[Btn6D] == 1 && !reversepress){
			reverse = !reverse;
			reversepress = true;
		}
		else if(vexRT[Btn6D] == 0 && reversepress){
			reversepress = false;
		}

		//drive motor speed calculations

		//tank - not compatible with arm
		/*
		if(fast) {
		left = vexRT[Ch3];
		right = vexRT[Ch2];
		}
		else{
		left = vexRT[Ch3] / 3;
		right = vexRT[Ch2] / 3 ;
		}
		*/

		//arcade
		int v;
		int h;

		if(fast) {
			h = vexRT[Ch1];
			v = vexRT[Ch2];
		}
		else{
			h = vexRT[Ch1] / 3;
			v = vexRT[Ch2] / 3 ;
		}

		left = v + h;
		right = v - h;

		if(abs(left) < 10){ left = 0;}
		if(abs(right) < 10){ right = 0;}

		if(left > 127){ left = 127;}
		else if(left < -127){ left = -127;}

		if(right > 127){ right = 127;}
		else if(right < -127){ right = -127;}


		// reverse drive
		if(!reverse){
			motor[LEFTFRONT]=-left;
			motor[LEFTBACK]=-left;
			motor[RIGHTFRONT]=right;
			motor[RIGHTBACK]=right;
		}
		else{
			motor[LEFTFRONT]=right;
			motor[LEFTBACK]=right;
			motor[RIGHTFRONT]=-left;
			motor[RIGHTBACK]=-left;
		}

		// claw input

		if(vexRT[Btn5U] == 1 && vexRT[Btn5D] == 0){
			clawspeed = 127;
		}
		else if(vexRT[Btn5U] == 0 && vexRT[Btn5D] == 1){
			clawspeed = -127;
		}
		else{
			clawspeed = 0;
		}

		motor[CLAW] = clawspeed;


		// arm input
		armspeed = vexRT[Ch3];

		motor[ARM] = armspeed;


		delay(50);
	}
}
