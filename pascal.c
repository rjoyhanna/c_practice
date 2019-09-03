// pascal.c

// prints out Pascal's Triangle to a certain number of rows

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// creates pascals triangle in an array
void createArray(unsigned long long pascalArr[], unsigned long long numLevels);
// prints pascals triangle to a certain number of rows
void printArray(unsigned long long pascalArr[], unsigned long long numLevels);

int main() {
	unsigned long long pascalArr[280][280];
	unsigned long long numLevels;
	pascalArr[0][1] = 1;

	// accept user input
	printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
	scanf("%llu", &numLevels);

	// creates pascals triangle in an array
	createArray(pascalArr, numLevels);

	// prints pascals triangle to a certain number of rows
	printArray(pascalArr, numLevels);

	return 0;
}

// creates pascals triangle in an array
// pascalArr is a 28x28 array containing integers
// numLevels is the number of levels of the triangle that the user wants to print
void createArray(unsigned long long pascalArr[], unsigned long long numLevels) {
	unsigned long long i;
	unsigned long long j;
	for (i = 1; i < numLevels; i++) {
		for (j = 1; j <= numLevels; j++) {
			pascalArr[i][j] = (pascalArr[i - 1][j - 1] + pascalArr[i - 1][j]);
		}
	}
	return;
}

// prints pascals triangle to a certain number of rows
// pascalArr is a 28x28 array containing integers
// numLevels is the number of levels of the triangle that the user wants to print
void printArray(unsigned long long pascalArr[], unsigned long long numLevels) {
	unsigned long long i;
	unsigned long long j;
	for (i = 0; i <= numLevels; i++) {
		for (j = 1; j <= numLevels; j++) {
			if (!(pascalArr[i][j] == 0)) {
				printf("%llu ", pascalArr[i][j]);
			}
		}
		printf("\n");
	}
	return;
}
