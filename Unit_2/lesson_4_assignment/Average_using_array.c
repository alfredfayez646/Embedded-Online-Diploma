/*
 * Average_using_array.c
 *
 *  Created on: Feb 7, 2024
 *      Author: Alfred
 */
#include <stdio.h>


int main(){
	float x[101];
	x[100] = 0;
	int y;

	do{
		printf("Enter the numbers of data: \n");
		fflush(stdin); fflush(stdout);
		scanf("%d", &y);
	}while (y <= 0 || y > 100);
	int i;
	for (i=0; i<y; i++){
		printf("Enter number: \n");
		fflush(stdin); fflush(stdout);
		scanf("%f", &x[i]);
		x[100] += x[i];
	}
	printf("Average = %0.2f", x[100]/y);


	return 0;
}
