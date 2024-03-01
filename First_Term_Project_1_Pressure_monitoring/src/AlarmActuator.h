/*
 * AlarmActuator.h
 *
 *  Created on: Feb 28, 2024
 *      Author: Alfred
 */

#ifndef ALARMACTUATOR_H_
#define ALARMACTUATOR_H_

#include "state.h"

extern void (*alarm_actuator_state)();

enum{
	alarm_actuator_waiting,
	alarmActuatorOn,
	alarmActuatorOff
}alarm_actuator_state_id;

void alarm_actuator_init();

STATE_define(alarmActuatorOff);
STATE_define(alarmActuatorOn);
STATE_define(alarm_actuator_waiting);

void startAlarm();
void stopAlarm();

#endif /*ALARMACTUATOR_H_*/
