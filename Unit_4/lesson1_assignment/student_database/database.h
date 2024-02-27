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
#include "conio.h"
#include "platform_Type.h"
void AddStudent();
uint8 DeleteStudent();
void viewStudents();
void deleteAll();
void getIndex();
void listLength();
void revIndex();
void middle();
void reverse();

#define dprintf(...) 		fflush(stdout); fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout); fflush(stdin);

// Effective data
struct Sdata
{
	uint32 id;
	uint8 name[40];
	float height;
};
struct Sstudent
{
	struct Sdata student;
	struct Sstudent* PNextStudent;
};



#endif /* DATABASE_H_ */
