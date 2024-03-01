/*
 * state.h
 *
 *  Created on: Feb 29, 2024
 *      Author: Alfred
 */

#ifndef STAE_H_
#define STAE_H_

#include "driver/driver.h"
#include <stdint.h>
#include <stdio.h>
#include "platform_Type.h"

#define STATE_define(_StateFun_) void ST_##_StateFun_()
#define STATE(_StateFun_)  ST_##_StateFun_


#endif /* STATE_H_ */

