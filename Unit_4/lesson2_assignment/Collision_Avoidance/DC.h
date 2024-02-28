/*
 * DC.h
 *
 *  Created on: Feb 28, 2024
 *      Author: Alfred
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"


extern void (*DC_state)();
//Define states
enum {
	DC_idle,
	DC_busy
}DC_state_id;

//declare state functions
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

#endif /* DC_H_ */
