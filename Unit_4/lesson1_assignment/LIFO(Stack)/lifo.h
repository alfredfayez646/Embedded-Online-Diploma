/*
 * lifo.h
 *
 *  Created on: Feb 26, 2024
 *      Author: Alfred
 */

#include "platform_Type.h"
#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
//type configuration
//select element type (uint8, uint16, element_type,...)
#define element_type uint32

//create buffer and select the width
#define width 5
element_type buffer1[width];

//type definitions
typedef struct{
	element_type length;
	element_type count;
	element_type* base;
	element_type* head;
}Slifo_buf_t;

typedef enum {
	lifo_no_error,
	lifo_full,
	lifo_empty,
	lifo_null
}lifo_status;

//APIs
lifo_status lifo_add_item (Slifo_buf_t* lifo_buf, element_type item);
lifo_status lifo_get_item (Slifo_buf_t* lifo_buf, element_type* item);
lifo_status lifo_init (Slifo_buf_t* lifo_buf, element_type* buf, element_type length);

#endif /* LIFO_H_ */
