/*
 * reverse_array_using_pointers.c
 *  Created on: Feb 14, 2024
 *      Author: Alfred
 */
#include <stdio.h>
#include <string.h>

int main(void){
	int a[15] = {0}, n, *pa;
	printf("Input the number of elements to store in the array (max 15) \n");
	fflush(stdout); fflush(stdin);
	scanf("%d", &n);
	pa = (a);
	printf("Input 5 number of elements in the array : \n");
	fflush(stdout);
	int i=0;
	for(;i<n;i++){
		printf("element - %d :\n", i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d", &a[i]);
	}
	printf("The elements of array in reverse order are : \n");
	fflush(stdout);
	for(i=n-1;i>=0;i--){
		printf("element - %d : ", i+1);
		fflush(stdout); fflush(stdin);
		printf("%d\n", *(pa+i));
	}
	return 0;
}
