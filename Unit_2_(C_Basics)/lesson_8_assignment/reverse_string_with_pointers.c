/*
 * reverse_string_using_pointers.c
 *  Created on: Feb 14, 2024
 *      Author: Alfred
 */
#include <stdio.h>
#include <string.h>

int main(void){
	char a[100] = {'\0'};
	printf("Enter a string : \n");
	fflush(stdout);
	gets(a);
	int s = strlen(a)-1;
	char* Pa = a;
	int i=s;
	printf("reverse of the string is: \n");
	fflush(stdout);
	for(;i>=0;i--){
		printf("%c", *(Pa+i));
		fflush(stdout);
	}
	return 0;
}
