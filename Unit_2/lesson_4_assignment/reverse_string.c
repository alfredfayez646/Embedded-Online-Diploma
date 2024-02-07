/*
 * frequency_of_char_in_string.c
 *
 *  Created on: Feb 7, 2024
 *      Author: Alfred
 */
#include <stdio.h>
#include <string.h>


int main(){
	char x[100];
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(x);
	int i;
	printf("the string reversed is: ");
	fflush(stdout);
	for(i=strlen(x); i>0; i--){
		printf("%c", x[i-1]);
		fflush(stdout);
	}
	return 0;
}
