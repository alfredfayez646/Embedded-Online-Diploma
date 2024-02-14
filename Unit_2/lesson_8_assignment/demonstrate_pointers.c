/*
 * demostrate_pointers.c
 *  Created on: Feb 14, 2024
 *      Author: Alfred
 */
#include <stdio.h>


int main(void){
	int m = 29;
	printf("Address of m is:0x%x \n", &m);
	fflush(stdout);
	printf("Value of m is: %d \n", m);
	fflush(stdout);
	int* ab = &m;
	printf("Now ab is assigned with the address of m.");
	fflush(stdout);
	printf("Address of pointer ab is : 0x%x \n", ab);
	fflush(stdout);
	printf("content of pointer ab is: %d \n", *ab);
	fflush(stdout);
	m = 34;
	printf("The value of m assigned to 34 now.");
	fflush(stdout);
	printf("Address of pointer ab is : 0x%x \n", ab);
	fflush(stdout);
	printf("content of pointer ab is: %d \n", *ab);
	fflush(stdout);
	*ab = 7;
	printf("The pointer variable ab is assigned with the value 7 now.");
	fflush(stdout);
	printf("Address of m is:0x%x \n", &m);
	fflush(stdout);
	printf("Value of m is: %d \n", m);
	return 0;
}
