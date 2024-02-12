/*
 * add_feet_using_structure.c
 *  Created on: Feb 12, 2024
 *      Author: Alfred
 */
#include <stdio.h>
struct Sfeet_inch{
	int feet;
	float inch;
};

void add_two_distances();

int main(void){
	add_two_distances();
	return 0;
}
void add_two_distances(){
	struct Sfeet_inch d1;
	struct Sfeet_inch d2;
	struct Sfeet_inch result;
	printf("Enter information of 1st distance: \n");
	fflush(stdout);
	printf("Enter feet: \n");
	fflush(stdout); fflush(stdin);
	scanf("%d", &d1.feet);
	printf("Enter inch: \n");
	fflush(stdout); fflush(stdin);
	scanf("%f", &d1.inch);
	printf("Enter information of 2nd distance: \n");
	fflush(stdout);
	printf("Enter feet: \n");
	fflush(stdout); fflush(stdin);
	scanf("%d", &d2.feet);
	printf("Enter inch: \n");
	fflush(stdout); fflush(stdin);
	scanf("%f", &d2.inch);
	result.feet = d1.feet + d2.feet;
	result.inch = d1.inch + d2.inch;
	while(result.inch >= 12){
		result.inch-=12;
		result.feet++;
	}
	printf("sum of the distances = ");
	fflush(stdout);
	printf("%d\' %0.1f\" \n", result.feet, result.inch);
	fflush(stdout);
}
