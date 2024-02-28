/*
 * state.h
 *
 *  Created on: Feb 28, 2024
 *      Author: Alfred
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"
#include "platform_Type.h"

//state function generator
#define STATE_define(_StateFun_) void ST_##_StateFun_()
#define STATE(_StateFun_) ST_##_StateFun_

//state connection
void US_set_distance(uint32 d);
void DC_motor(uint32 s);
#endif /* STATE_H_ */
