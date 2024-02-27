/*
 * students_info_using_structure.c
 *  Created on: Feb 12, 2024
 *      Author: Alfred
 */
#include <stdio.h>
struct Sinformation{
	int roll;
	char name[50];
	float marks;
};
void get_student_info();
int main(void){
	get_student_info();
	return 0;
}
void get_student_info(){
	struct Sinformation student[10];
	printf("Enter information of student: \n");
	fflush(stdout);
	int i=0;
	for(;i<2;i++){	/*only get 2 to save time*/
		printf("Enter roll number: \n");
		fflush(stdout); fflush(stdin);
		scanf("%d", &student[i].roll);
		printf("Enter Name: \n");
		fflush(stdout); fflush(stdin);
		gets(student[i].name);
		printf("Enter marks: \n");
		fflush(stdout); fflush(stdin);
		scanf("%fl", &student[i].marks);
	}
	for(i=0;i<2;i++){   /*only get 2 to save time*/
		printf("Roll: %d\n", student[i].roll);
		fflush(stdout);
		printf("Name: %s\n", student[i].name);
		fflush(stdout);
		printf("Marks: %0.2f\n", student[i].marks);
	}
}
