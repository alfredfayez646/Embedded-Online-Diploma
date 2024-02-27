/*
 * pointer_to_array_of_pointers_to_structure.c
 *  Created on: Feb 14, 2024
 *      Author: Alfred
 */
#include <stdio.h>

struct Semployees {
	char name[50];
	int id;
};
int main(void){
	struct Semployees employee = {"Alex", 1002};
	struct Semployees (*a[]) = {&employee};
	struct Semployees (*(*ptr)[]) = {&a};

	printf("Employee name: %s\n", (*(*ptr))->name);
	fflush(stdout);
	printf("Employee ID: %d\n", (*(*ptr))->id);

	return 0;
}
