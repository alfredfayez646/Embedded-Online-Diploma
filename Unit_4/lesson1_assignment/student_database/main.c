/*
 * main.c
 *
 *  Created on: Feb 26, 2024
 *      Author: Alfred
 */
#include "database.h"


int main()
{
	uint8 tempTXT[40];
	while(1)
	{
		dprintf("\n ================");
		dprintf("\n Choose one of the following");
		dprintf("\n 1) Add student");
		dprintf("\n 2) Delete student");
		dprintf("\n 3) View students");
		dprintf("\n 4) Delete all students");
		dprintf("\n 5) View student by index");
		dprintf("\n 6) Get students number");
		dprintf("\n 7) View student by index from end");
		dprintf("\n 8) View the student in the middle of list");
		dprintf("\n 9) Reverse the list");
		dprintf("\n Enter option number: ");
		gets((char_t*)tempTXT);
		switch(atoi((char_t*)tempTXT))
		{
		case 1:
			AddStudent();
			break;
		case 2:
			DeleteStudent();
			break;
		case 3:
			viewStudents();
			break;
		case 4:
			deleteAll();
			break;
		case 5:
			getIndex();
			break;
		case 6:
			listLength();
			break;
		case 7:
			revIndex();
			break;
		case 8:
			middle();
			break;
		case 9:
			reverse();
			break;
		}
	}
	return 0;
}

