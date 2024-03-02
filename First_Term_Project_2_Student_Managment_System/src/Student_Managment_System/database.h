/*
 * database.h
 *
 *  Created on: Feb 27, 2024
 *      Author: Alfred
 */

#ifndef DATABASE_H_
#define DATABASE_H_


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "platform_Type.h"
#include "fifo.h"

void setup();
void add_student_file();
void add_student_manually();
void find_r();
void find_fn();
void find_c();
void total_s();
uint8 del_s();
void up_S();
void show_s();


#define dprintf(...) 		fflush(stdout); fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout); fflush(stdin);

// Effective data
struct sinfo
{
	uint8 fname[50];
	uint8 lname[50];
	uint32 roll;
	float GPA;
	uint32 c_id[10];
}st[55];


#endif /* DATABASE_H_ */
