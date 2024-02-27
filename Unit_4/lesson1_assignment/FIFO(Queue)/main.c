/*
 * main.c
 *
 *  Created on: Feb 26, 2024
 *      Author: Alfred
 */
#include "fifo.h"

int main()
{
	Sfifo_t uart_fifo;
	element_type i, temp=0;
	if (fifo_init(&uart_fifo, uart_buffer, 5) == fifo_no_error)
		printf("FIFO init -----Done");
	else
		printf("FIFO init -----Failed");

	for(i=0;i<width+2;i++){
		printf("FIFO enqueue (%x) \n", i);
		if (fifo_enqueue(&uart_fifo, i) == fifo_no_error)
			printf("\t FIFO enqueue -----Done \n");
		else
			printf("\t FIFO enqueue -----Failed \n");
	}
	fifo_print(&uart_fifo);
	if (fifo_dequeue(&uart_fifo, &temp) == fifo_no_error)
		printf("FIFO dequeue (%x) -----Done \n", temp);
	else
		printf("FIFO dequeue (%x) -----Failed \n", temp);
	if (fifo_dequeue(&uart_fifo, &temp) == fifo_no_error)
		printf("FIFO dequeue (%x) -----Done \n", temp);
	else
		printf("FIFO dequeue (%x) -----Failed \n", temp);
	fifo_print(&uart_fifo);


	return 0;
}

