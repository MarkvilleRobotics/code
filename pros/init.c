/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
  pinMode(BUMPER_1, 1);
  pinMode(BUMPER_2, 2);
  pinMode(BUMPER_E, 12);
}

/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */
void initialize() 
  analogCalibrate(LINE_TRACKER_PORT_L);
  analogCalibrate(LINE_TRACKER_PORT_C);
  analogCalibrate(LINE_TRACKER_PORT_R);
  analogCalibrate(LIGHT_TRACKER_PORT_R);
  analogCalibrate(LIGHT_TRACKER_PORT_B);
  analogCalibrate(LIGHT_TRACKER_PORT_Y);
  sonarl = ultrasonicInit(6,5);
  sonarr = ultrasonicInit(8,7);
  
  //Wake up the gyro
   const int wakey = 0;
   uint8_t * pp = & wakey; 
   i2cWrite(0x6B, wakey, 1);
   
  //Read from Gyro
   uint8_t data[6];
   i2cRead(0x41, data, 1);  //GyX 
   i2cRead(0x42, data+1, 1);
   i2cRead(0x43, data+2, 1);  //GyY
   i2cRead(0x44, data+3, 1);
   i2cRead(0x45, data+4, 1);  //GyZ
   i2cRead(0x46, data+5, 1);
  
   
}
