/*
 * alarm_monitor.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Alfred
 */
#include "alarm_monitor.h"

void (*alarm_monitor_state)();

void highPressure()
{
	alarm_monitor_state = STATE(alarmOn);
}

STATE_define(alarmOn)
{	
	//state name
	alarm_monitor_state_id = alarmOn;
	startAlarm();
	Delay(alarm_delay);
	alarm_monitor_state = STATE(alarmOff);
}
STATE_define(alarmOff)
{	
	//state name
	alarm_monitor_state_id = alarmOff;
	stopAlarm();	
	alarm_monitor_state = STATE(alarmOff);
}
STATE_define(alarmMonitorWaiting)
{
	//state name
	alarm_monitor_state_id = alarmMonitorWaiting;
	alarm_monitor_state = STATE(alarmOff);
}