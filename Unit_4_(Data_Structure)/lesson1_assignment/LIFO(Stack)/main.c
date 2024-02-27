/*
 * main.c
 *
 *  Created on: Feb 26, 2024
 *      Author: Alfred
 */
#include "lifo.h"

int main(){
	element_type i, temp =0;
	Slifo_buf_t uart_lifo;
	if(lifo_init(&uart_lifo, buffer1, 5)==lifo_no_error)
		printf("lifo init -----Done\n");
	else
		printf("lifo init -----Failed\n");

	for(i=0;i<width+1;i++){
		if(lifo_add_item(&uart_lifo, i) == lifo_no_error)
			printf("uart_lifo add: %d \n", i);
		else
			printf("lifo add -----Failed\n");
	}
	for(i=0;i<width+1;i++){
		if(lifo_get_item(&uart_lifo, &temp) == lifo_no_error)
			printf("uart_lifo get: %d \n", temp);
		else
			printf("lifo get -----Failed\n");
	}
	return 0;
}
