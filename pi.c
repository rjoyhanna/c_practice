// pi.c

// implements Monte Carlo method for estimating the value of PI

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// return true if valid input
bool isValidInput(int numArgsRead, int numArgsNeeded, int num);
// return true if the correct number of inputs is read
bool isValidFormat (int numArgsRead, int numArgsNeeded);
// return true if input is positive
bool intConstraintsMet(int num);
// computes distance from point to center (0,0) to return true if point is in circel, else return false
bool IsInCircle(double xVal, double yVal);
// generate random value between (-1,1)
double GenerateCoordinate(int seedNum);

int main() {

	int seedNum;
	int numIterations;
	double probInCircle;
	int numInCircle = 0;
	double piValue;
	int simNum;
	double xVal;
	double yVal;
	int numArgsRead;
	int numArgsNeeded = 1;

	// accept user input and validate that the correct number of arguments was passed
	do {
		printf("Enter the seed for the random number generator: ");
		numArgsRead = scanf("%d", &seedNum);
	} while (!isValidFormat(numArgsRead, numArgsNeeded));

	// accept user input and validate that the correct number of arguments was passed and the argument was positive
	do {
		printf("Enter the number of iterations to run: ");
		numArgsRead = scanf("%d", &numIterations);

	} while (!isValidInput(numArgsRead, numArgsNeeded, numIterations));

	// using seed in the random number generator
	srand(seedNum);

	// generate coordinate pair for each iteration
	// check if coordinate is within the circle for each iteration
	for (simNum = 1; simNum <= numIterations; simNum++) {
		xVal = GenerateCoordinate(seedNum);
		yVal = GenerateCoordinate(seedNum);
		if (IsInCircle(xVal, yVal)) {
			numInCircle++;
		}
	}

	// dividing number of points in circle by total points to produce probability within circle
	probInCircle = (double) numInCircle / (double) numIterations;
	// compute value of PI
	piValue = probInCircle * 4;

	printf("The value of pi is %.5lf.", piValue);

	return 0;
	}

// return true if valid input
// numArgsRead is number of inputs
// numArgsNeeded is number of inputs desired
// num is value being tested
bool isValidInput(int numArgsRead, int numArgsNeeded, int num) {
	return isValidFormat(numArgsRead, numArgsNeeded) && intConstraintsMet(num);
}

// return true if the correct number of inputs is read
// numArgsRead is number of inputs
// numArgsNeeded is number of inputs desired
bool isValidFormat (int numArgsRead, int numArgsNeeded) {
	bool isValid = numArgsRead == numArgsNeeded;
	char lastChar;

	do{
		scanf("%c", &lastChar);
		if (!isspace(lastChar)){
			isValid = false;
		}
	} while (lastChar !=  '\n');
	return isValid;
}

// return true if input is positive
// num is value being tested
bool intConstraintsMet(int num) {
	return num > 0;
}

// computes distance from point to center (0,0) to return true if point is in circel, else return false
// xVal is the x value in the coordinate pair
// yVal is the y value in the coordinate pair
bool IsInCircle(double xVal, double yVal) {
	bool isInCircle = false;
	double distFromCenter = sqrt((xVal * xVal) + (yVal * yVal));
	if (distFromCenter <= 1) {
		isInCircle = true;
	}
	return isInCircle;
}

// generate random value between (-1,1)
// seedNum is the seed for the random number generator
double GenerateCoordinate(int seedNum) {
	double coordinateNum = -1 + ((double) (rand()) /(((double) RAND_MAX)/(2)));
	return coordinateNum;
}
