/*
 * CA.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Alfred
 */

#include "CA.h"
static uint32 CA_speed = 0;
static uint32 CA_distance = 0;
static uint32 CA_threshhold = 50;

// State pointer to function

void (*CA_state)();

void US_set_distance(uint32 d)
{
	CA_distance = d;
	CA_state = (CA_distance <= CA_threshhold)? (STATE(CA_waiting)) : (STATE(CA_driving));
	printf("US-----distance: %d---->CA \n", CA_distance);
}

STATE_define(CA_waiting)
{
	//state name
	CA_state_id = CA_waiting;

	//state action
	CA_speed = 0;
	printf("CA_waiting state: distance = %d  speed = %d \n", CA_distance, CA_speed);

	//motor(CA_speed)
	DC_motor(CA_speed);
}
STATE_define(CA_driving)
{
	//state name
	CA_state_id = CA_driving;

	//state action
	CA_speed = 30;

	printf("CA_driving state: distance = %d  speed = %d \n", CA_distance, CA_speed);
	//motor(CA_speed)
	DC_motor(CA_speed);

}

