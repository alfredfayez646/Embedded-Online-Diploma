/*
 * Psensor.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Alfred
 */

#include "Psensor.h"
uint32 PVal = 0;

void (*Psensor_state)();

void PS_init()
{
	//init sensor drivers
	Psensor_state = STATE(PSreading);
}

STATE_define(PSreading)
{
	//state name
	Psensor_state_id = PSreading;

	PVal = getPressureVal();
	setP(PVal);

	Psensor_state = STATE(PSidle);
}
STATE_define(PSidle)
{
	//state name
	Psensor_state_id = PSidle;

	Delay(sensor_delay_time);

	Psensor_state = STATE(PSreading);
}