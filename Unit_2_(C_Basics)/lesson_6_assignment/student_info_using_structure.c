/*
 * student_info_using_structure.c
 *  Created on: Feb 12, 2024
 *      Author: Alfred
 */
#include <stdio.h>
struct Sinformation{
	char name[50];
	int roll;
	float marks;
};
struct Sinformation get_student_info();
int main(void){
	struct Sinformation student1_info;
	student1_info = get_student_info();
	printf("Name: %s\n", student1_info.name);
	fflush(stdout);
	printf("Roll: %d\n", student1_info.roll);
	fflush(stdout);
	printf("Marks: %0.2fl\n", student1_info.marks);
	return 0;
}
struct Sinformation get_student_info(){
	struct Sinformation student;
	printf("Enter information of student: \n");
	fflush(stdout);
	printf("Enter Name: \n");
	fflush(stdout); fflush(stdin);
	gets(student.name);
	printf("Enter roll number: \n");
	fflush(stdout); fflush(stdin);
	scanf("%d", &student.roll);
	printf("Enter marks: \n");
	fflush(stdout); fflush(stdin);
	scanf("%fl", &student.marks);
	return student;
}
