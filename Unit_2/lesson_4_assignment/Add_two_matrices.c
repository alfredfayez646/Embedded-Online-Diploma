/*
 * main.c
 *
 *  Created on: Feb 2, 2024
 *      Author: Alfred
 */

#include "stdio.h"

void matrix_sum();

float x[2][2];
float y[2][2];

void main() {
	int i, j;
	printf("enter the elements of the 1st matrix \n");
	fflush(stdin); fflush(stdout);
	for (i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("enter a%d%d \n",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &x[i][j]);
		}
	}

	printf("enter the elements of the 2nd matrix \n");
	fflush(stdin); fflush(stdout);
	for (i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("enter b%d%d \n",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &y[i][j]);
		}
	}
	matrix_sum();

	printf("the summation of the 2 matrices is :\n");
	fflush(stdin); fflush(stdout);
	for (i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%.1f  ",x[i][j]);
			fflush(stdin); fflush(stdout);
		}
		printf("\n");
	}
	return 0;
}
void matrix_sum(){
	/*summation of the 2 matrices*/
	int i,j;
	for (i=0;i<2;i++){
		for(j=0;j<2;j++){
			x[i][j] += y[i][j];
		}
	}
	return 0;
}
