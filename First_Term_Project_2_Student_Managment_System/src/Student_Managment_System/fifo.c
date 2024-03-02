/*
 * fifo.c
 *
 *  Created on: Feb 26, 2024
 *      Author: Alfred
 */
#include "fifo.h"

fifo_status fifo_init(Sfifo_t* fifo, struct sinfo* buf, uint32 length)
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
fifo_status fifo_enqueue(Sfifo_t* fifo, element_type* item)
{
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;

	//check fifo is full
	if (fifo_is_full(fifo) == fifo_full)
		return fifo_full;
	*(fifo->head) = *item;
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
	element_type *temp;
	uint32 i,j;
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;
	//check fifo is empty
	if (fifo->count == 0)
		return fifo_empty;
	else {
		temp = fifo->tail;
		printf("\n\n ======The student's details are======\n\n");
		for (i=0;i<fifo->count;i++){
			dprintf("%d): \n", i+1);
			dprintf("The first name: %s\n", temp->fname);
			dprintf("The last name: %s\n", temp->lname);
			dprintf("The Roll number: %d\n", temp->roll);
			dprintf("The student's GPA: %0.2f\n", temp->GPA);
			dprintf("Student's courses: \n");
			for (j =0 ; j < 5; j++){
				dprintf("Course %d ID: %d\n", i+1, temp->c_id[i]);
			}
			dprintf("--------------------------------\n");
			temp++;
		}
	}
	return fifo_no_error;
}
fifo_status fifo_check_roll(Sfifo_t* fifo, uint32 roll)
{
	uint32 i;
	element_type *temp;
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;


	//check fifo is full
	if(fifo->count == 55)
		return fifo_full;

	else {
		temp = fifo->tail;
		for (i=0;i<fifo->count;i++){
			if(roll == temp->roll)
				return roll_used;
			temp++;
		}
	}
	return roll_available;
}

element_type* fifo_find_roll(Sfifo_t* fifo, uint32 roll)
{
	uint32 i;
	element_type *temp;
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return (element_type*)NULL;

	//check fifo is empty
	if(fifo->count == 0)
		return (element_type*)NULL;

	else {
		temp = fifo->tail;
		for (i=0;i<fifo->count;i++){
			if(roll == temp->roll)
				return temp;
			temp++;
		}
	}
	return 0;
}

element_type* fifo_find_fname(Sfifo_t* fifo, char_t* name)
{
	uint32 i;
	element_type *temp;
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return (element_type*)NULL;

	//check fifo is empty
	if(fifo->count == 0)
		return (element_type*)NULL;

	else {
		temp = fifo->tail;
		for (i=0;i<fifo->count;i++){
			if(stricmp(name,(char_t*)temp->fname) == 0)
				return temp;
			temp++;
		}
	}
	return temp;
}

void fifo_find_class(Sfifo_t* fifo, uint32 ID)
{
	uint32 i,j,k=1,flag=0;
	element_type *temp;
	//check fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
	{
		dprintf("[Error] The FIFO is invalid: \n");
	}
	//check fifo is empty
	if(fifo->count == 0){
		dprintf("The list is empty: \n");
	}
	else
	{
		temp = fifo->tail;
		for (i=0;i<fifo->count;i++){
			for(j=0;j<5;j++)
			{
				if(ID == temp->c_id[j])
				{
					dprintf("%d): \n", k++);
					dprintf("The first name: %s\n", temp->fname);
					dprintf("The last name: %s\n", temp->lname);
					dprintf("The Roll number: %d\n", temp->roll);
					dprintf("The student's GPA: %0.2f\n", temp->GPA);
					dprintf("--------------------------------\n");
					flag=1;
				}
			}
			temp++;
		}
		if(flag == 0)
		{
			dprintf("No one is enrolled in class: %d \n", ID);
		}
	}
}

void fifo_delete(Sfifo_t* fifo, element_type* item)
{
	uint32 roll = item->roll;
	element_type* p = item;
	while(p<fifo->head)
	{
		p++;
		*item = *p;
		item=p;
	}
	dprintf("Roll number %d is removed successfully\n", roll);
	fifo->head--;
	fifo->count--;
}
