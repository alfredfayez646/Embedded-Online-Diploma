/*
 * Toggle_LED.c
 *
 *  Created on: Feb 20, 2024
 *      Author: Alfred
 */
#include <stdio.h>
#include "platform_Type.h"
/*Register address*/

#define SYSCTL_RCGC2_R		(*((vuint32_t*)0x400FE108))
#define GPIO_PORTF_DIR_R	(*((vuint32_t*)0x40025400))
#define GPIO_PORTF_DEN_R	(*((vuint32_t*)0x4002551C))
#define GPIO_PORTF_DATA_R	(*((vuint32_t*)0x400253FC))

int main()
{
	SYSCTL_RCGC2_R  |= 0x00000020;
	vuint32_t i;
	for(i=0;i<200;i++);
	GPIO_PORTF_DIR_R  |=(1<<3);
	GPIO_PORTF_DEN_R  |=(1<<3);
	while(1)
	{
		GPIO_PORTF_DATA_R ^= (1<<3);
		for(i=0;i<20000;i++);
	}
return 0;
}