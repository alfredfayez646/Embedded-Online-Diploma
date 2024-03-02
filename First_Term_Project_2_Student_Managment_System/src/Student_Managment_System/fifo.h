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
#include "database.h"
// type configuration
// select the element data type (uint8, uint16, uint32, ...)
#define element_type struct sinfo
//create a buffer
#define width 55

//FIFO data types
typedef struct{
	uint32 length;
	uint32 count;
	element_type* base;
	element_type* head;
	element_type* tail;
}Sfifo_t;

typedef enum{
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null,
	roll_used,
	roll_available
}fifo_status;

//FIFO APIs
fifo_status fifo_init(Sfifo_t* fifo, element_type* buf, uint32 length);
fifo_status fifo_enqueue(Sfifo_t* fifo, element_type* item);
fifo_status fifo_dequeue(Sfifo_t* fifo, element_type* item);
fifo_status fifo_is_full(Sfifo_t* fifo);
fifo_status fifo_print(Sfifo_t* fifo);
fifo_status fifo_check_roll(Sfifo_t* fifo, uint32 roll);
element_type* fifo_find_roll(Sfifo_t* fifo, uint32 roll);
element_type* fifo_find_fname(Sfifo_t* fifo, char_t* name);
void fifo_find_class(Sfifo_t* fifo, uint32 ID);
void fifo_delete(Sfifo_t* fifo, element_type* item);

#endif /* FIFO_H_ */
