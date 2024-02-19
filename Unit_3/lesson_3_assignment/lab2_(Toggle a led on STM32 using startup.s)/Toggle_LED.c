/*
 * Toggle_LED.c
 *
 *  Created on: Feb 16, 2024
 *      Author: Alfred
 */
#include <stdio.h>
#include "platform_Type.h"
/*Register address*/
#define RCC_BASE			0x40021000
#define GPIOA_BASE			0x40010800
#define RCC_APB2ENR			*(vuint32_t*)(RCC_BASE   + 0X18)
#define GPIOA_CRH			*(vuint32_t*)(GPIOA_BASE + 0x04)
#define GPIOA_ODR			*(vuint32_t*)(GPIOA_BASE + 0x0c)

/*Define ODR register with bit fields*/
typedef union {
	vuint32_t all_pins;
	struct{
		vuint32_t reserved:13;
		vuint32_t p_13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0c);

int main(){
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH 	&= 0xFF0FFFFF;
	GPIOA_CRH 	|= 0x00200000;
	uint32 i;
	while(1){
		/*	GPIOA_ODR ^= 1<13;
		for(;i<5000;i++);*/ 	/*First method*/
		R_ODR->pin.p_13 = 1;	/*second method*/
		for(i=0;i<5000;i++);
		R_ODR->pin.p_13 = 0;
		for(i=0;i<5000;i++);
	}
	return 0;
}
