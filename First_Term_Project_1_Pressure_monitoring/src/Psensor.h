/*
 * Psensor.h
 *
 *  Created on: Feb 29, 2024
 *      Author: Alfred
 */


#ifndef PSENSOR_H_
#define PSENSOR_H_

#include "state.h"

#define sensor_delay_time 1000
extern void (*Psensor_state)();

enum{
	PSreading,
	PSidle
}Psensor_state_id;

void PS_init();

STATE_define(PSreading);
STATE_define(PSidle);

#endif /*PSENSOR_H_*/
