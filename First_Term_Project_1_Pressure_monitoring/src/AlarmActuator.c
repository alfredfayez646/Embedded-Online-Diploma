/*
 * AlarmActuator.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Alfred
 */
#include "AlarmActuator.h"
void alarm_actuator_init()
{
	//initiate alarm driver
}

void (*alarm_actuator_state)();



STATE_define(alarmActuatorOff)
{
	//state name
	alarm_actuator_state_id = alarmActuatorOff;

	//turn off the alarm
	Set_Alarm_actuator(1); //Active LOW
	alarm_actuator_state = STATE(alarm_actuator_waiting);
}
STATE_define(alarmActuatorOn)
{
	//state name
	alarm_actuator_state_id = alarmActuatorOn;

	//turn on the alarm
	Set_Alarm_actuator(0); //Active LOW
	alarm_actuator_state = STATE(alarm_actuator_waiting);
}
STATE_define(alarm_actuator_waiting)
{
	//state name
	alarm_actuator_state_id = alarm_actuator_waiting;
}

void startAlarm()
{
	alarm_actuator_state = STATE(alarmActuatorOn);
}
void stopAlarm()
{
	alarm_actuator_state = STATE(alarmActuatorOff);
}