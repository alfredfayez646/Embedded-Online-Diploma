/*
 * frequency_of_char_in_string.c
 *
 *  Created on: Feb 7, 2024
 *      Author: Alfred
 */
#include <stdio.h>
#include <string.h>

int * prime_num (int a, int b);

int main(void){
	int x,y,k;
	int *j;
	printf("Enter two numbers(intervals): ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &x,&y);
	j = prime_num (x, y);
	printf("prime numbers between %d and %d are: ", x,y);
	fflush(stdin); fflush(stdout);
	for(k=0;*(j+k)!=0;k++){
		printf("%d ",*(j+k));
	}
	return 0;
}

int * prime_num (int a, int b){
	static int i[100];
	int x,y,c=0;
	for(x=a+1;x<=b;x++){
		i[99]=1;
		for (y=2;y<x;y++){
			if(x % y == 0)
				i[99]=0;
		}
		if(i[99]==1){
			i[c]= x;
			c++;
		}
	}
	i[c]=0;
	return i;
}
