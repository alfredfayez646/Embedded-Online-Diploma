/*
 * fifo.h
 *
 *  Created on: Feb 26, 2024
 *      Author: Alfred
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "platform_Type.h"
#include "stdio.h"
// type configuration
// select the element data type (uint8, uint16, uint32, ...)
#define element_type uint8
//create a buffer
#define width 5
element_type uart_buffer[width];

//FIFO data types
typedef struct{
	element_type length;
	element_type count;
	element_type* base;
	element_type* head;
	element_type* tail;
}Sfifo_t;

typedef enum{
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null
}fifo_status;

//FIFO APIs
fifo_status fifo_init(Sfifo_t* fifo, element_type* buf, element_type length);
fifo_status fifo_enqueue(Sfifo_t* fifo, element_type item);
fifo_status fifo_dequeue(Sfifo_t* fifo, element_type* item);
fifo_status fifo_is_full(Sfifo_t* fifo);
fifo_status fifo_print(Sfifo_t* fifo);


#endif /* FIFO_H_ */
