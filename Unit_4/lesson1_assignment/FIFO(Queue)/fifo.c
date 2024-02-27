/*
 * fifo.c
 *
 *  Created on: Feb 26, 2024
 *      Author: Alfred
 */
#include "fifo.h"

fifo_status fifo_init(Sfifo_t* fifo, element_type* buf, element_type length)
{
	// check buffer is valid
	if (buf == NULL)
		return fifo_null;
	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->count = 0;
	fifo->length = length;
	return fifo_no_error;
}
fifo_status fifo_enqueue(Sfifo_t* fifo, element_type item)
{
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;

	//check fifo is full
	if (fifo_is_full(fifo) == fifo_full)
		return fifo_full;
	*(fifo->head) = item;
	fifo->count++;
	if (fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head = fifo->base;
	else
		fifo->head++;
	return fifo_no_error;
}
fifo_status fifo_dequeue(Sfifo_t* fifo, element_type* item)
{
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;
	//check fifo is empty
	if (fifo->count == 0)
		return fifo_empty;
	*item = *(fifo->tail);
	fifo->count--;
	//circular fifo
	if (fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail = fifo->base;
	else
		fifo->tail++;
	return fifo_no_error;
}
fifo_status fifo_is_full(Sfifo_t* fifo)
{
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;
	//check fifo is full
	if (fifo->count == fifo->length)
		return fifo_full;
	return fifo_no_error;
}
fifo_status fifo_print(Sfifo_t* fifo)
{
	element_type *temp, i;
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;
	//check fifo is empty
	if (fifo->count == 0)
		return fifo_empty;
	else {
		temp = fifo->tail;
		printf("\n ======fifo_print======\n");
		for (i=0;i<fifo->count;i++){
			printf("\t %x \n", *temp++);
		}
	}
	return fifo_no_error;
}
