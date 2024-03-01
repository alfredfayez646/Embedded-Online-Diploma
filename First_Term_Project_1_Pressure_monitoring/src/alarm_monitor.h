/*
 * alarm_monitor.h
 *
 *  Created on: Feb 28, 2024
 *      Author: Alfred
 */


#ifndef ALARMMONITOR_H_
#define ALARMMONITOR_H_
#define alarm_delay 6000

#include "state.h"

extern void startAlarm();
extern void stopAlarm();

extern void (*alarm_monitor_state)();

enum{
	alarmOff,
	alarmOn,
	alarmMonitorWaiting
}alarm_monitor_state_id;

STATE_define(alarmOff);
STATE_define(alarmOn);
STATE_define(alarmMonitorWaiting);

void highPressure();

#endif /*ALARMMONITOR_H_*/

