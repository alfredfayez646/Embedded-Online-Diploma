/*
 * frequency_of_char_in_string.c
 *
 *  Created on: Feb 7, 2024
 *      Author: Alfred
 */
#include <stdio.h>
#include <string.h>

int  factorial_num (int a);

int main(void){
	int x,y;
	printf("Enter an positive number: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d", &x);
	y = factorial_num(x);
	printf("factorial of %d is: %d", x ,y);
	return 0;
}

int  factorial_num (int a){
	if(a>=1)
		return a*factorial_num(a-1);
	else
		return 1;
}
