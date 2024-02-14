/*
 * print_alphabets_using_pointers.c
 *  Created on: Feb 14, 2024
 *      Author: Alfred
 */
#include <stdio.h>


int main(void){
	char a = 'A';
	char* Pa = &a;
	printf("The Alphabets are : \n");
	fflush(stdout);
	int i=0;
	for(;i<26;i++){
		printf("%c  ", *Pa+i);
		fflush(stdout);
	}
	return 0;
}
