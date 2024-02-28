/*
 * CA.h
 *
 *  Created on: Feb 28, 2024
 *      Author: Alfred
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"


extern void (*CA_state)();
//Define states
enum {
	CA_waiting,
	CA_driving
}CA_state_id;

//declare state functions
STATE_define(CA_waiting);
STATE_define(CA_driving);
uint32 get_distance(uint32 l, uint32 r, uint32 count);
#endif /* CA_H_ */
