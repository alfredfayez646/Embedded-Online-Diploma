/*
 * DC.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Alfred
 */

#include "DC.h"

static uint32 DC_speed = 0;


// State pointer to function

void (*DC_state)();

void DC_init()
{
	//PWM init
	printf("DC init");
}

void DC_motor(uint32 s)
{
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("CA-----SPEED: %d---->DC \n", DC_speed);
}

STATE_define(DC_idle)
{
	//state name
	DC_state_id = DC_idle;
	printf("DC_idle state: speed = %d \n", DC_speed);

	//state action
	//set the motor speed
}
STATE_define(DC_busy)
{
	//state name
	DC_state_id = DC_busy;
	printf("DC_busy state: speed = %d \n", DC_speed);

	//state action
	//set the motors
	DC_state = STATE(DC_idle);

}

