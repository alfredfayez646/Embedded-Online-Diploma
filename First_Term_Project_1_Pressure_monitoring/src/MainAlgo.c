/*
 * MainAlgo.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Alfred
 */

#include "MainAlgo.h"
uint32 MA_PVal = 0;
uint32 threshold = 20;

//state pointer

void (*MainAlgo_state)();

uint32 setP(uint32 PVal)
{
	MA_PVal = PVal; 
}

STATE_define(waitingPVal)
{
	//state name
	MainAlgo_state_id = waitingPVal;

	//check on PVal
	if (MA_PVal > threshold){
		highPressure();
	}

	MainAlgo_state = STATE(waitingPVal);
}