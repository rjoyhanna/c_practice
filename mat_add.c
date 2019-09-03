// mat_add.c

// asks the user for 2 matrices A, and B, and displays their sum, C

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// ask user for number of rows
int accept_row_input();
// ask user for number of columns
int accept_column_input();
// allocate space for a 2D matrix
int** malloc_space(int numRows, int numCols);
// input values into matrix A and B
void accept_matrix_input(int numRows, int numCols, int** matrixA, int** matrixB);
// scan input into a matrix
void scan_matrix_input(int numRows, int numCols, int** matrix);
// add matrices to create the final values
void make_matrix_C(int numRows, int numCols, int** matrixA, int** matrixB, int** matrixC);
// display matrix  values by row
void display_results(int numRows, int numCols, int** matrixC);
// delete memory
void delete_matrix(int** matrix, int numRows);

int main() {
	int numRows;
	int numCols;

	// ask user for number of rows and columns
	numRows = accept_row_input();
	numCols = accept_column_input();

	// allocate space for 3 2D matrices
	int** matrixA = malloc_space(numRows, numCols);
	int** matrixB = malloc_space(numRows, numCols);
	int** matrixC = malloc_space(numRows, numCols);

	// input values into matrix A and B
	accept_matrix_input(numRows, numCols, matrixA, matrixB);

	// add matrices to create the final values
	make_matrix_C(numRows, numCols, matrixA, matrixB, matrixC);
	// display matrix  values by row
	display_results(numRows, numCols, matrixC);

	// delete memory
	delete_matrix(matrixA, numRows);
	delete_matrix(matrixB, numRows);
	delete_matrix(matrixC, numRows);

	return 0;
}

// ask user for number of rows
int accept_row_input() {
	int numRows;
	printf("Please enter the number of rows: ");
	scanf("%d", &numRows);
	return numRows;
}

// ask user for number of columns
int accept_column_input() {
	int numCols;
	printf("Please enter the number of columns: ");
	scanf("%d", &numCols);
	return numCols;
}

// allocate space for a 2D matrix given numRows number of rows and numCols number of columns
int** malloc_space(int numRows, int numCols) {
	int** matrix = (int**) malloc(numRows * sizeof(int*));
	int row;
	for(row = 0; row < numRows; ++row) {     //make space for the elements in the row
		matrix[row] = (int*)malloc(numCols * sizeof(int));
	}
	return matrix;
}

// input values into matrix A and B with dimensions numRows x numCols
void accept_matrix_input(int numRows, int numCols, int** matrixA, int** matrixB) {
	printf("Enter Matrix A\n");
	scan_matrix_input(numRows, numCols, matrixA);
	printf("Enter Matrix B\n");
	scan_matrix_input(numRows, numCols, matrixB);
	return;
}

// scan input into a matrix
void scan_matrix_input(int numRows, int numCols, int** matrix) {
	int row;
	int col;
	// inputs int into a value in the matrix, each separated by a space
	for (row = 0; row < numRows; row++) {
		for (col = 0; col < numCols; col++) {
			scanf("%d", &matrix[row][col]);
		}
	}
	return;
}

// add matrices to create the final values
void make_matrix_C(int numRows, int numCols, int** matrixA, int** matrixB, int** matrixC) {
	int row;
	int col;
	// add corresponding values in matrices A and B
	for (row = 0; row < numRows; row++) {
		for (col = 0; col < numCols; col++) {
			matrixC[row][col] = matrixA[row][col] + matrixB[row][col];
		}
	}
	return;
}

// display matrix  values by row
void display_results(int numRows, int numCols, int** matrixC) {
	int row;
	int col;
	printf("A + B =\n");
	// print out values in a matrix row by row
	for (row = 0; row < numRows; row++) {
		for (col = 0; col < numCols; col++) {
			printf(" %d", matrixC[row][col]);
		}
		printf("\n");
	}
	return;
}

// delete memory
void delete_matrix(int** matrix, int numRows) {
	int row;
	for(row = 0; row < numRows; ++row) {
		free(matrix[row]);
	}
	free(matrix);
	return;
}
