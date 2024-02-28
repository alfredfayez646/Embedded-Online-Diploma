/*
 * main.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Alfred
 */
#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	//init drivers
	//init IRQ..
	//init HAL drivers
	//init block
	US_init();
	DC_init();
	//set states pointers to each block
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}
int main()
{
	setup();
	while(1)
	{
		US_state();
		CA_state();
		DC_state();
	}
	return 0;
}
