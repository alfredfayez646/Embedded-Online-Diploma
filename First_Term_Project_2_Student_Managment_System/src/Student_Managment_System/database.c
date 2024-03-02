/*
 * database.c
 *
 *  Created on: Feb 27, 2024
 *      Author: Alfred
 */

#include "database.h"


Sfifo_t student_fifo;
void setup()
{
	if (fifo_init(&student_fifo, st, 55) == fifo_no_error){
		dprintf("FIFO init -----Done \n");
	}
	else{
		dprintf("[Error] FIFO init -----Failed \n");
	}
}
void add_student_file()
{
	dprintf("\n----------------------\n \n");
	FILE *p = fopen("StudentInfo.txt","r");
	if (p == NULL){
		dprintf("[Error] File can't be opened\n");
	}
	else{
		element_type student;
		while(fscanf(p, "%d %s %s %f %d %d %d %d %d", &student.roll, student.fname, student.lname,
				&student.GPA, &student.c_id[0], &student.c_id[1], &student.c_id[2],
				&student.c_id[3], &student.c_id[4])!= EOF)
		{
			if(fifo_check_roll(&student_fifo, (uint32)student.roll) == roll_available){
				fifo_enqueue(&student_fifo,&student);
				dprintf("[INFO] Roll number %d saved successfully\n", student.roll)
			}
			else{
				dprintf("[Error] roll number: %d is used before \n", student.roll);
			}
		}
		total_s();
	}
	fclose(p);
}
void add_student_manually()
{
	dprintf("\n----------------------\n \n");
	uint8 tempTXT[40],i;
	element_type student;
	fifo_status roll_check;
	dprintf("Enter the Roll number \n");
	do{
		gets((char_t*)tempTXT);
		student.roll = atoi((char_t*)tempTXT);
		//check if roll is used
		if(fifo_check_roll(&student_fifo, (uint32)student.roll) == roll_available)
		{
			roll_check = roll_available;
			//get the rest student info
			dprintf("Enter the first name \n");
			gets((char_t*)student.fname);
			dprintf("Enter the last name \n");
			gets((char_t*)student.lname);
			dprintf("Enter the GPA\n");
			gets((char_t*)tempTXT);
			student.GPA = atof((char_t*)tempTXT);
			//get id of 5 courses
			for(i=0; i<5 ;i++)
			{
				dprintf("Enter the Course ID \n");
				gets((char_t*)tempTXT);
				student.c_id[i] = atoi((char_t*)tempTXT);
			}
			//store the info in fifo
			fifo_enqueue(&student_fifo,&student);
			dprintf("[INFO] Roll number %d saved successfully\n", student.roll)
		}
		else
		{
			//give option to reenter or skip the duplicated roll
			dprintf("[Error] roll number: %d is used before \n", student.roll);
			dprintf("Choose one of the next options\n1)Enter another Roll number \n2)Skip\n");
			gets((char_t*)tempTXT);
			if(atoi((char_t*)tempTXT) == 1)
			{
				dprintf("Enter the Roll number \n");
				roll_check = roll_used;
			}
			else if (atoi((char_t*)tempTXT) == 2)
			{
				dprintf("\n\n-------Skipping------- \n\n");
				roll_check = roll_available;
			}
		}
	}while(roll_check == roll_used);
	total_s();
}

void find_r()
{
	uint8 tempTXT[40],i;
	dprintf("\n----------------------\n \n");
	dprintf("Enter the Roll number \n");
	gets((char_t*)tempTXT);
	element_type* student = fifo_find_roll(&student_fifo, atoi((char_t*)tempTXT));
	if(student == NULL)
	{
		dprintf("Cannot find the student \n");
	}
	else
	{
		dprintf("The student's details are: \n");
		dprintf("The first name: %s\n", student->fname);
		dprintf("The last name: %s\n", student->lname);
		dprintf("The student's GPA: %0.2f\n", student->GPA);
		dprintf("Student's courses: \n");
		for (i =0 ; i < 5; i++){
			dprintf("Course %d ID: %d\n", i+1, student->c_id[i]);
		}
		dprintf("--------------------------------\n");
	}
}
void find_fn()
{
	uint8 tempTXT[40],i;
	dprintf("\n----------------------\n \n");
	dprintf("Enter the first name \n");
	gets((char_t*)tempTXT);
	element_type* student = fifo_find_fname(&student_fifo, (char_t*)tempTXT);
	if(student == NULL)
	{
		dprintf("Cannot find the student \n");
	}
	else
	{
		dprintf("The student's details are: \n");
		dprintf("The first name: %s\n", student->fname);
		dprintf("The last name: %s\n", student->lname);
		dprintf("The Roll number: %d\n", student->roll);
		dprintf("The student's GPA: %0.2f\n", student->GPA);
		dprintf("Student's courses: \n");
		for (i =0 ; i < 5; i++){
			dprintf("Course %d ID: %d\n", i+1, student->c_id[i]);
		}
		dprintf("--------------------------------\n");
	}
}
void find_c()
{
	uint8 tempTXT[40];
	dprintf("\n----------------------\n \n");
	dprintf("Enter the class ID \n");
	gets((char_t*)tempTXT);
	fifo_find_class(&student_fifo, atoi((char_t*)tempTXT));
}
void total_s()
{
	dprintf("\n\n-----------------------------------\n\n");
	dprintf("The total number of students: %d\n", student_fifo.count);
	dprintf("You can add up to %d students\n", student_fifo.length);
	dprintf("You can add %d more students\n", student_fifo.length - student_fifo.count);
	dprintf("\n------------------------------------------------\n");
}
uint8 del_s()
{
	uint8 tempTXT[40];
	dprintf("\n----------------------\n \n");
	dprintf("Enter the Roll number \n");
	gets((char_t*)tempTXT);
	element_type* student = fifo_find_roll(&student_fifo, atoi((char_t*)tempTXT));
	if(student == 0){
		dprintf("can't find roll number %d \n", atoi((char_t*)tempTXT));
	}
	else{
	fifo_delete(&student_fifo, student);
	}
	return 0;
}
void up_S()
{
	uint8 tempTXT[40];
	dprintf("\n----------------------\n \n");
	dprintf("Enter the Roll number \n");
	gets((char_t*)tempTXT);
	element_type* student = fifo_find_roll(&student_fifo, atoi((char_t*)tempTXT));
	if(student == NULL)
	{
		dprintf("Cannot find the student \n");
	}
	else
	{
		dprintf("Enter the value you want to change: \n");
		dprintf("1. First name\n");
		dprintf("2. Last name\n");
		dprintf("3. Roll NO. \n");
		dprintf("4. GPA \n");
		dprintf("5. Courses\n");
		gets((char_t*)tempTXT);

		switch(atoi((char_t*)tempTXT))
		{
		case 1:
			dprintf("Enter the new first name: ");
			scanf("%s", student->fname);
			break;
		case 2:
			dprintf("Enter the new last name: ");
			scanf("%s", student->lname);
			break;
		case 3:
			dprintf("Enter the new roll number: ");
			scanf("%d", &student->roll);
			break;
		case 4:
			dprintf("Enter the new GPA: ");
			scanf("%f", &student->GPA);
			break;
		case 5:
			dprintf("Enter the course number you want to update: ");
			uint32 course;
			scanf("%d", &course);
			dprintf("Enter the new course id: ");
			scanf("%d", &student->c_id[course-1]);
			break;
		default:
			dprintf("INVALID OPTION!!!!\n");

		}
		dprintf("Student's details updated successfully\n");
	}
	dprintf("--------------------------------\n");
}

void show_s()
{
	fifo_print(&student_fifo);
	total_s();
}

