#pragma config(Sensor, dgtl1,  touch,          sensorTouch)
#pragma config(Motor,  port1,           motor1,         tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code only works autonomously under USB-Only Mode!
task main()
{
	for(;;){
	untilBump(dgtl1);
	motor[motor1] = 127;
	wait(0.5);
	//wait (100000000);
	untilBump(dgtl1);
	motor[motor1] = 0;
	wait(0.5);
	}
}