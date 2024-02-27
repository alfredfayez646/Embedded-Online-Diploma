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
	int i, counter =0;
	for(i=0; x[i]!='\0'; i++){
			counter++;
	}
	printf("lenght of string is: %d", counter);

	return 0;
}
