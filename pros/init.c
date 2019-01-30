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

   // Note the address of the first register of the buffer is first in the message
    /*uint8_t params[5] = {I2C_SLAVE_BUF_PARAMS, 0x50, 0x52, 0x79, 0x53};

    // Send the slave some parameters
    if (i2cWrite(I2C_SLAVE_ADDR, params, 5)) {
        printf("Parameters sent successfully!\n");
    }
    else {
        printf("ERROR: Failed to send parameters to I2C slave!\n");
    }

    // And then enable the device
    if (i2cWriteRegister(I2C_SLAVE_ADDR, I2C_I2C_SLAVE_REG_ENABLE, 0x01)) {
        printf("I2C slave enabled!\n");
    }
    else {
        printf("ERROR: Failed to enable the I2C slave!\n");
    }
    */

    //MPU6050_write_reg (MPU6050_PWR_MGMT_1, 0);
    //Wire.write(0x6B);  // PWR_MGMT_1 register
    //Wire.write(0);     // set to zero (wakes up the MPU-6050)

    /*uint8_t dataIn[6];
    int32_t reading = -1;

    while (1) {
        if (i2cReadRegister(I2C_SLAVE_ADDR, I2C_SLAVE_BUF_DATA, data_in, 6)) {
            // Combine the 8-bit incoming values by extending them and bitwise-oring them together
            //
            // NOTE: Extension to 32-bits is done using uint32_t even though reading is int32_t
            //       This is done to prevent "sign extension," a common problem in these scenarios
            //
            // NOTE: This implementation assumes incoming data is big-endian with the order (0, 1, 2, 3)
            //       If your I2C slave emits data as little-endian, the order needs to be reversed
            reading = (((uint32_t)dataIn[0]) << 24) |
                      (((uint32_t)dataIn[1]) << 16) |
                      (((uint32_t)dataIn[2]) <<  8) |
                      (((uint32_t)dataIn[3]));

            printf("Read in a value of %d from slave.\n", reading);
        }
        else {
            reading = -1;
            printf("ERROR: Failed to read sensor data from slave!\n");
        }

        // Use the sensor value in some way here

        delay(20);
    }*/
}
