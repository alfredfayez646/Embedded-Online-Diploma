/*
 * database.c
 *
 *  Created on: Feb 27, 2024
 *      Author: Alfred
 */

#include "database.h"

struct Sstudent* gpFirstStudent = NULL;

void AddStudent()
{
	uint8 tempTXT[40];
	struct Sstudent* pNewStudent = NULL;
	struct Sstudent* pLastStudent = NULL;
	//check if list is empty
	if(gpFirstStudent == NULL)
	{
		//create new record
		pNewStudent = (struct Sstudent*) malloc(sizeof(struct Sstudent));
		//assign it to gpFirstStudent
		gpFirstStudent = pNewStudent;
	}
	else //list have records
	{
		//Navigate till last student
		pLastStudent = gpFirstStudent;
		while(pLastStudent->PNextStudent)
			pLastStudent = pLastStudent->PNextStudent;
		//create new record
		pNewStudent = (struct Sstudent*) malloc(sizeof(struct Sstudent));
		pLastStudent->PNextStudent = pNewStudent;
	}

	//fill new record
	dprintf("Enter ID \n");
	gets((char_t*)tempTXT);
	pNewStudent->student.id = atoi((char_t*)tempTXT);

	dprintf("Enter Name: \n");
	gets((char_t*)pNewStudent->student.name);

	dprintf("Enter height \n");
	gets((char_t*)tempTXT);
	pNewStudent->student.height = atof((char_t*)tempTXT);

	//set new student to NULL
	pNewStudent->PNextStudent = NULL;
}

uint8 DeleteStudent()
{
	uint8 tempTXT[40];
	uint16 selectedID;
	// get the selected ID
	dprintf("Enter ID to be deleted \n");
	gets((char_t*)tempTXT);
	selectedID = atoi((char_t*)tempTXT);

	//check list isn't empty
	if(gpFirstStudent)
	{
		struct Sstudent* pSelectedStudent = gpFirstStudent;
		struct Sstudent* pPreviousStudent = NULL;

		//find the selected id
		while(pSelectedStudent)
		{
			if (pSelectedStudent->student.id == selectedID)
			{
				if(pPreviousStudent)	//not the first student
				{
					//probably useless
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;
				}
				else //wanna delete the first student
				{
					gpFirstStudent = pSelectedStudent->PNextStudent;
				}
				free(pSelectedStudent);
				return 1;
			}
			//increment the loop
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}
		//didn't fin the id
		dprintf("Can't find the student");
		return 0;
	}
	//Empty list
	dprintf("------The list is Empty------");
	return 0;
}

void viewStudents()
{
	uint32 count = 1;
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	//check empty list
	if (gpFirstStudent == NULL){
		dprintf("------The list is Empty------");
	}
	else
	{
		while(pCurrentStudent)
		{
			dprintf("\n record number %d ", count++);
			dprintf("\n \t ID: %d", pCurrentStudent->student.id);
			dprintf("\n \t Name: %s", pCurrentStudent->student.name);
			dprintf("\n \t Height: %0.1f", pCurrentStudent->student.height);
			pCurrentStudent = pCurrentStudent->PNextStudent;
		}
	}
}

void deleteAll()
{
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	//check empty list
	if (gpFirstStudent == NULL){
		dprintf("------The list is Empty------");
	}
	else
	{
		while(pCurrentStudent)
		{
			struct Sstudent* pTempStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->PNextStudent;
			free(pTempStudent);
		}
		gpFirstStudent = NULL;
	}
}

void getIndex()
{
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	uint8 tempTXT[40],i;
	//check empty list
	if (gpFirstStudent == NULL){
		dprintf("------The list is Empty------");
	}
	else
	{
		dprintf("\n Enter the index ");
		gets((char_t*)tempTXT);
		if(pCurrentStudent)
		{
			for(i=1;i<atoi((char_t*)tempTXT);i++)
				pCurrentStudent = pCurrentStudent->PNextStudent;
		}
		dprintf("\n index number %d is: ", i);
		dprintf("\n \t ID: %d", pCurrentStudent->student.id);
		dprintf("\n \t Name: %s", pCurrentStudent->student.name);
		dprintf("\n \t Height: %0.1f", pCurrentStudent->student.height);
	}
}

void listLength()
{
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	uint8 i=0;
	//check empty list
	if (gpFirstStudent == NULL){
		dprintf("------The list is Empty------");
	}
	else
	{
		while(pCurrentStudent)
		{
			pCurrentStudent = pCurrentStudent->PNextStudent;
			i++;
		}
		dprintf("\n Number of students is: %d ", i);
	}
}

void revIndex()
{
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	struct Sstudent* pIndexStudent = gpFirstStudent;
	uint8 tempTXT[40],i;
	//check empty list
	if (gpFirstStudent == NULL){
		dprintf("------The list is Empty------");
	}
	else
	{
		dprintf("\n Enter the index from the End: ");
		gets((char_t*)tempTXT);
		for(i=0;i<atoi((char_t*)tempTXT);i++)
		{
			pCurrentStudent = pCurrentStudent->PNextStudent;
		}
		while(pCurrentStudent)
		{
			pCurrentStudent = pCurrentStudent->PNextStudent;
			pIndexStudent = pIndexStudent->PNextStudent;
		}
		dprintf("\n index number %d is: ", i);
		dprintf("\n \t ID: %d", pIndexStudent->student.id);
		dprintf("\n \t Name: %s", pIndexStudent->student.name);
		dprintf("\n \t Height: %0.1f", pIndexStudent->student.height);
	}
}

void middle()
{
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	struct Sstudent* pIndexStudent = gpFirstStudent;
	uint8 i=0;
	//check empty list
	if (gpFirstStudent == NULL){
		dprintf("------The list is Empty------");
	}
	else
	{
		while(pCurrentStudent->PNextStudent)
		{
			pCurrentStudent = pCurrentStudent->PNextStudent;
			if (pCurrentStudent->PNextStudent)
				pCurrentStudent = pCurrentStudent->PNextStudent;
			pIndexStudent = pIndexStudent->PNextStudent;
			i++;
		}
		dprintf("\n The middle index of the list is %d: ", i);
		dprintf("\n \t ID: %d", pIndexStudent->student.id);
		dprintf("\n \t Name: %s", pIndexStudent->student.name);
		dprintf("\n \t Height: %0.1f", pIndexStudent->student.height);
	}
}

void reverse()
{
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	struct Sstudent* pNextStudent = NULL;
	struct Sstudent* pPrevStudent = NULL;
	//check empty list
	if (gpFirstStudent == NULL){
		dprintf("------The list is Empty------");
	}
	else
	{//get the pointers to their places

		while(pCurrentStudent)
		{
			pNextStudent = pCurrentStudent->PNextStudent;
			pCurrentStudent->PNextStudent = pPrevStudent;

			pPrevStudent = pCurrentStudent;
			pCurrentStudent = pNextStudent;
		}
		gpFirstStudent = pPrevStudent;
	}
	dprintf("\n Viewing list after reversing: ")
	uint32 count = 1;
	struct Sstudent* pviewStudent = gpFirstStudent;

	while(pviewStudent)
	{
		dprintf("\n record number %d ", count++);
		dprintf("\n \t ID: %d", pviewStudent->student.id);
		dprintf("\n \t Name: %s", pviewStudent->student.name);
		dprintf("\n \t Height: %0.1f", pviewStudent->student.height);
		pviewStudent = pviewStudent->PNextStudent;
	}
}

