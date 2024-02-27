/*
 * transpose_of_matrix.c
 *
 *  Created on: Feb 7, 2024
 *      Author: Alfred
 */

#include <stdio.h>


int main(){
	int x[100][100], y[100][100], r, c;
	printf("Enter rows and column of matrix: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &r,&c);
	int i, j;
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			printf("Enter element a[%d][%d]: ", i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d", &x[i][j]);
			y[j][i] = x[i][j];
		}
	}
	printf("Entered matrix: \n");
	fflush(stdout);
	for(i=0; i<r; i++){
			for(j=0; j<c; j++){
				printf("%d ", x[i][j]);
				fflush(stdout);
			}
			printf("\n");
		}
	printf("Transpose of the matrix: \n");
		fflush(stdout);
	for(i=0; i<c; i++){
		for(j=0; j<r; j++){
			printf("%d ", y[i][j]);
			fflush(stdout);
		}
		printf("\n");
	}

	return 0;
}
