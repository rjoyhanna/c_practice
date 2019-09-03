// quad.c

// solves quadratic equation given a b and c

int main(){
	#include <stdio.h>
	#include <math.h>

	double coefficientA;
	double coefficientB;
	double coefficientC;
	double radical;
	double sqrtVal;
	double solution;
	double firstSolution;
	double secondSolution;

 // prompt user for variables a b and c in the quadratic equation
	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
	printf("Please enter a: ");
	scanf(" %lf", &coefficientA);
	printf("Please enter b: ");
	scanf(" %lf", &coefficientB);
	printf("Please enter c: ");
	scanf(" %lf", &coefficientC);

// computes the value of the radical
	radical = (coefficientB * coefficientB) - (4 * coefficientA * coefficientC);
// computes the square root of the radical
	sqrtVal = sqrt(radical);

// compute one solution to the quadratic equation
// first argument is the first coefficient
// second argument is the second coefficient
// third argument is the value of the square root of the radical
	double findSolution(double coefficientA, double coefficientB, double sqrtVal) { //
		solution = (-coefficientB + sqrtVal) / (2 * coefficientA);
		return solution;
	}

// find one real solution if the value of the radical is equal to zero
	if (radical == 0) {
		firstSolution = findSolution(coefficientA, coefficientB, sqrtVal);
		printf("There is one real solution: %.2lf", firstSolution);
	}

// find two real solutions if the value of the radical is a positive number greater than 0
	else if (radical > 0) {
		firstSolution = findSolution(coefficientA, coefficientB, sqrtVal);
		secondSolution = findSolution(coefficientA, coefficientB, -sqrtVal);
		printf("There are 2 real solutions\n");
		printf("Solution 1: %.2lf\n", firstSolution);
		printf("Solution 2: %.2lf\n", secondSolution);
	}

// print no real solutions if the radical is negative
	else {
		printf("There are no real solutions");
	}

	return 0;
}
