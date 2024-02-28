/*
 * US.h
 *
 *  Created on: Feb 28, 2024
 *      Author: Alfred
 */

#ifndef US_H_
#define US_H_

#include "state.h"


extern void (*US_state)();
//Define states
enum {
	US_busy
}US_state_id;

//declare state functions
STATE_define(US_busy);

uint32 get_distance(uint32 l, uint32 r, uint32 count);

void US_init();

#endif /* US_H_ */
