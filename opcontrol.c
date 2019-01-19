/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

 int motorL=1;
 int motorR=10;
 int motorQ=2;//Arm motor
 int motorS=9;//Servo platform motor
 void grab(){
 	motorSet(motorQ, -25);
 	delay(1000);
 }

 void stoparm(){
 	motorSet(motorQ, 0);
 	delay(1000);
 }

 void resetarm(){
 	motorSet(motorQ, 25);
 	delay(1000);
 }
 void horizontal(){
 	motorSet(motorS,0);
 	delay(1000);
 }
 void release(){
 	motorSet(motorS,0);
 	delay(1000);
 }

 void turnleft(){
 	motorSet(motorL, 30);
 	motorSet(motorR, 30);
 	delay (50);
 	//return 0;
 }
 void turnright(){
	 motorSet(motorL, -30);
	 motorSet(motorR, -30);
 	delay (50);
 	//return 0;
 }

void operatorControl() {
	while (true) {
		motorSet(motorL, 127);
		motorSet(motorR, 127);
		//printf("Hello PROS User!\n");
		delay(2000);
		motorSet(motorL, -127);
		motorSet(motorR, -127);
		delay(2000);
	}
}

//UNFINISHED BELOW
void wallslam(){
	for(;;){
		if (SensorValue[dgtl1] == 0 && SensorValue[dgtl2] == 0){
		motor[motorl] = 50;
		motor[motorr] = -50;
		delay (50);
		}
		else{
		motor[motorl] = 50;
		motor[motorr] = -50;
		delay (100);
		break;
		}
	}
}

void trackline(int ls, int rs){
	//lm=v-k(l-r)
	//rm=v+k(l-r)
	motor[motorl] = 30+0.1*(rs-ls);
	motor[motorr] = -(30-0.1*(rs-ls));
	delay(5);
}

void findline(bool side, int ls, int rs){
	if (side) {
		if (rs>=2450){
			for(;;){
				trackline(SensorValue[in1]-200, SensorValue[in3]);
			}
		}
	}
	if (!side) {
		if (ls>=2450){
			for(;;){
				trackline(SensorValue[in1]-200, SensorValue[in3]);
			}
		}
	}
}

//Next function to add is task main
