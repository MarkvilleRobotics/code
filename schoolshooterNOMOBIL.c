#pragma config(Sensor, dgtl11, loadersense,    sensorQuadEncoder)
#pragma config(Motor,  port1,           turner,        tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           shootr,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           loader,        tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port4,           shootl,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          tilt,          tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	bool shooteron = false;

 	motor[loader] = 0;

	for (;;){
			if (vexRT[Btn7L]){
				motor[turner] = 100;
			}
			else if (vexRT[Btn7R]){
				motor[turner] = -100;
			}
			else{
				motor[turner] = 0;
			}

			if (vexRT[Btn5U]){
				motor[tilt] = 50;
			}
			else if (vexRT[Btn5D]){
				motor[tilt] = -50;
			}
			else{
				motor[tilt] = 0;
			}
  		if(vexRT[Btn8U]){
    		shooteron = true;
  		}
  		if(vexRT[Btn8D]){
    	shooteron = false;
  		}

			if(shooteron){
    	 motor[shootr]=-127;
    	 motor[shootl]=-127;
  		}
  		else{
  			motor[shootr]=0;
    	 	motor[shootl]=0;
  		}
  		if(vexRT[Btn7U]){
    	 motor[loader]=50;
  		}
  		else if(vexRT[Btn7D]){
    	 motor[loader]=-50;
  		}
  		else{
  			motor[loader]=0;
  		}

			delay(50);
	}
}
