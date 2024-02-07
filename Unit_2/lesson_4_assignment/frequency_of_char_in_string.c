/*
 * frequency_of_char_in_string.c
 *
 *  Created on: Feb 7, 2024
 *      Author: Alfred
 */
#include <stdio.h>
#include <string.h>


int main(){
	char x[100], y;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(x);
	printf("Enter a character to find its frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &y);
	int i, counter =0;
	for(i=0; x[i]!='\0'; i++){
		if(y == x[i]){
			counter++;
		}
	}
	printf("frequency of %c is: %d", y, counter);

	return 0;
}
