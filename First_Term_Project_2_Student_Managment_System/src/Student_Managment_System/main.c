/*
 * main.c
 *
 *  Created on: Feb 26, 2024
 *      Author: Alfred
 */
#include "database.h"


int main()
{
	setup();
	uint8 tempTXT[40];
	while(1)
	{
		dprintf("\n ================");
		dprintf("\n Choose one of the following");
		dprintf("\n 1) Add student by file");
		dprintf("\n 2) Add student manually");
		dprintf("\n 3) find student by roll");
		dprintf("\n 4) find student by first name");
		dprintf("\n 5) find students enrolled in class");
		dprintf("\n 6) Get students number");
		dprintf("\n 7) delete a student by roll");
		dprintf("\n 8) update student data");
		dprintf("\n 9) show all students");
		dprintf("\n Enter option number: ");
		gets((char_t*)tempTXT);
		switch(atoi((char_t*)tempTXT))
		{
		case 1:
			add_student_file();
			break;
		case 2:
			add_student_manually();
			break;
		case 3:
			find_r();
			break;
		case 4:
			find_fn();
			break;
		case 5:
			find_c();
			break;
		case 6:
			total_s();
			break;
		case 7:
			del_s();
			break;
		case 8:
			up_S();
			break;
		case 9:
			show_s();
			break;
		}
	}
	return 0;
}


