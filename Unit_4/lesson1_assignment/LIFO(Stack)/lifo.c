/*
 * lifo.c
 *
 *  Created on: Feb 26, 2024
 *      Author: Alfred
 */
#include"lifo.h"
lifo_status lifo_add_item (Slifo_buf_t* lifo_buf, element_type item)
{
	//check lifo is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return lifo_null;
	//check lifo full
	if(lifo_buf->count == lifo_buf->length)
		return lifo_full;
	//add item
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;
	return lifo_no_error;
}
lifo_status lifo_get_item (Slifo_buf_t* lifo_buf, element_type* item)
{
	//check lifo is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return lifo_null;
	//check lifo empty
	if(lifo_buf->count == 0)
		return lifo_empty;
	//get value
	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->count--;
	return lifo_no_error;
}
lifo_status lifo_init (Slifo_buf_t* lifo_buf, element_type* buf, element_type length)
{
	if(lifo_buf == NULL)
		return lifo_null;
	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->count = 0;
	lifo_buf->length = length;
	return lifo_no_error;
}
