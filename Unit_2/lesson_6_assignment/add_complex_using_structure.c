/*
 * add_complex_using_structure.c
 *  Created on: Feb 12, 2024
 *      Author: Alfred
 */
#include <stdio.h>
struct Scomplex{
	float r;
	float i;
};

void add_two_complex(struct Scomplex x1, struct Scomplex x2);

int main(void){
	struct Scomplex d1;
	struct Scomplex d2;
	printf("for the 1st complex number \n");
	printf("Enter real and imaginary respectively: \n");
	fflush(stdout); fflush(stdin);
	scanf("%f %f", &d1.r, &d1.i);
	printf("for the 2nd complex number \n");
	printf("Enter real and imaginary respectively: \n");
	fflush(stdout); fflush(stdin);
	scanf("%f %f", &d2.r, &d2.i);
	add_two_complex(d1, d2);
	return 0;
}
void add_two_complex(struct Scomplex x1, struct Scomplex x2){

	struct Scomplex result;

	result.r = x1.r + x2.r;
	result.i = x1.i + x2.i;

	printf("sum of the numbers = ");
	fflush(stdout);
	printf("%0.1f+%0.1fi \n", result.r, result.i);
	fflush(stdout);
}
