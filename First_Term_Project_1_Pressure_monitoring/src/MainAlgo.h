/*
 * MainAlgo.h
 *
 *  Created on: Feb 29, 2024
 *      Author: Alfred
 */


#ifndef MAINALGO_H_
#define MAINALGO_H_

#include "state.h"

extern void (*MainAlgo_state)();

enum{
	waitingPVal
}MainAlgo_state_id;

STATE_define(waitingPVal);

#endif /*MAINALGO_H_*/

