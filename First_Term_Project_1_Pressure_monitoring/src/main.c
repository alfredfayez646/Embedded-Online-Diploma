/*
 * main.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Alfred
 */
#include "driver.h"
#include "MainAlgo.h"
#include "alarm_monitor.h"
#include "AlarmActuator.h"
#include "Psensor.h"

void setup()
{
	//init drivers
	GPIO_INITIALIZATION();
	//init IRQ..
	//init HAL drivers
	//init block
	alarm_actuator_init();
	PS_init();
	//set states pointers to each block
	Psensor_state = STATE(PSreading);
	MainAlgo_state = STATE(waitingPVal);
	alarm_monitor_state = STATE(alarmOff);
	alarm_actuator_state = STATE(alarm_actuator_waiting);
}

int main (){
	setup();
	while (1)
	{
		//Implement your Design
		 Psensor_state();
		 MainAlgo_state();
		 alarm_monitor_state();
		 alarm_actuator_state();
	}
	return 0;
}

