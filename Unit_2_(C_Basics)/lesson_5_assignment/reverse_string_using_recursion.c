/*
 * reverse_string_using_recursion.c
 *
 *  Created on: Feb 8, 2024
 *      Author: Alfred
 */
#include <stdio.h>

void  reverse (char *c);

int main(void){
	char s[100]={'\0'};
	printf("Enter a sentence: \n");
	fflush(stdout); fflush(stdin);
	gets(s);
	reverse(s);
	return 0;
}

void  reverse (char *c){
	if(*c){
		reverse (c +1);
		printf("%c", *c);
	}
}
