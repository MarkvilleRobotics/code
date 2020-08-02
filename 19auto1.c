#pragma config(Sensor, in1,    lfleft,         sensorLineFollower)
#pragma config(Sensor, in2,    lfcent,         sensorLineFollower)
#pragma config(Sensor, in3,    lfright,        sensorLineFollower)
#pragma config(Sensor, in4,    lightr,         sensorReflection)
#pragma config(Sensor, in5,    lightb,         sensorReflection)
#pragma config(Sensor, in6,    lighty,         sensorReflection)
#pragma config(Sensor, in7,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  sonarL,         sensorSONAR_mm)
#pragma config(Sensor, dgtl3,  sonarR,         sensorSONAR_mm)
#pragma config(Sensor, dgtl5,  snfr,           sensorNone)
#pragma config(Sensor, dgtl7,  snbk,           sensorNone)
#pragma config(Sensor, dgtl9,  en1,            sensorQuadEncoder)
#pragma config(Sensor, dgtl11, en2,            sensorQuadEncoder)
#pragma config(Motor,  port1,           motorl,        tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port10,          motorr,        tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*void grab(){
	motor[port6] = 60;
	delay (1000);
}*/
void halt(){
	motor[motorl] = 0;
	motor[motorr] = 0;
}
int fast = 50;
int slow = 12;
void turnleft(){
		while (SensorValue[in2]>500){
			motor[motorl] = -30;
			motor[motorr] = 30;
		}
	}
void turnright(){
		while (SensorValue[in2]>500){
			motor[motorl] = 30;
			motor[motorr] = -30;
		}
	}
void trackline(int ls, int rs, int cs, int speed){
		if (cs > 500){
			if (ls>rs){
				motor[motorl] = 50;
				motor[motorr] = -50;
			}
			else{
				motor[motorl] = -50;
				motor[motorr] = 50;
			}
		}
		else{
			motor[motorl] = speed;
			motor[motorr] = speed;
		}
		delay(2);
}
task main()
{
	/*for(;;){
 	motor[port5] = 100;
	}
	*/
	for (;;){
		trackline(SensorValue[in1], SensorValue[in3], SensorValue[in2], fast);
			//if (SensorValue[dgtl1]>500)
			//turnleft();
		if (SensorValue[dgtl1]>500){
			for (int i=0; i<500; i++)
				trackline(SensorValue[in1], SensorValue[in3], SensorValue[in2], fast);
			while (SensorValue[in3] <= 500 || SensorValue[in2] <= 500){
				trackline(SensorValue[in1], SensorValue[in3], SensorValue[in2], 15);
			}
			turnright();
			for (int i=0; i<1000; i++)
				trackline(SensorValue[in1], SensorValue[in3], SensorValue[in2], fast);
		}
		if (SensorValue[in1]<300 && SensorValue[in2]<300 && SensorValue[in3]<300){
			halt();
			wait (10000000);
		}
	}
		/*motor[motorl] = 0;
		motor[motorr] = 0;
			while (SensorValue[in5] <= 850){
			motor[motorl] = 30;
			motor[motorr] = -30;
			delay(1);
			}
		if (SensorValue[in1] > 2000 && SensorValue[in2] > 2000){

		}
		else if(SensorValue[in3] > 2000){

		}
		//while (SensorValue[in5] > 980){
		//motor[motorl] = 127;
		//motor[motorr] = -127;
		//delay(1);
		//}
		*/
}
