/*
 * find_power_using_recursion.c
 *
 *  Created on: Feb 8, 2024
 *      Author: Alfred
 */
#include <stdio.h>

int  power (int a, int b);

int main(void){
	int x,y,p;
	printf("Enter base number: \n");
	fflush(stdout); fflush(stdin);
	scanf("%d", &x);
	printf("Enter power number(positive integer): \n");
	fflush(stdout); fflush(stdin);
	scanf("%d",&y);
	p = power(x,y);
	printf("%d ^ %d = %d\n", x, y, p);
	return 0;
}

int  power (int a, int b){
	if(b>0){
		return a*power(a,b-1);
	}
	return 1;
}
