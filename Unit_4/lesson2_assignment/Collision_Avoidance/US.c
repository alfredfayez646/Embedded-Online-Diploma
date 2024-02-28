/*
 * US.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Alfred
 */
#include "US.h"
static uint32 US_distance = 0;

// State pointer to function

void (*US_state)();

void US_init()
{
	//init US Driver
	printf("US_init \n");
}

STATE_define(US_busy)
{
	//state name
	US_state_id = US_busy;

	//state action
	US_distance = get_distance(45,55,1);

	printf("US_busy state: distance = %d \n", US_distance);

	US_set_distance(US_distance);

	US_state = STATE(US_busy);
}

uint32 get_distance(uint32 l, uint32 r, uint32 count)
{
	uint32 i=0,rand_num=0;
	for (; i<count; i++)
	{
		rand_num = (rand() % (r-l+1)) + l;
	}
	return rand_num;
}

