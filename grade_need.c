// grade_need.c

// calculates the minimum percent needed on a final to get the desired grade in the class

int main() {
	#include <stdio.h>
	#include <stdbool.h>
	#include <string.h>
	#include <stdlib.h>

	char desiredGrade; 
	double percentGrade;
	double currentPercent = -1;
	double currentWeight;
	double finalWeight = -1;
	double finalPercentNeed;
	int numInputs = -1;
	char lastChar;

// returns true if the input has the correct number of characters
// otherwise returns false
// first argument is the number of inputs
// second argument is the number of inputs required to be correct formatting
// third argument is the last character in the input
	bool isValidFormatting(int numInputs, int numInputsNeeded, char lastChar) {
		return numInputs == numInputsNeeded && lastChar == '\n';
	}

// ask user input
	printf("Enter the grade you want in the class: ");
	numInputs = scanf(" %c%c", &desiredGrade, &lastChar);

// validate length of user input
	if(!isValidFormatting(numInputs, 2, lastChar)){
		printf("Invalid formatting. Ending program.\n");
		exit(0);
	}

// check that input is a valid grade character and assign corresponding percentage
	else if (desiredGrade == 'a' || desiredGrade == 'A') {
		percentGrade = 90.00;
	}
	else if (desiredGrade == 'b' || desiredGrade == 'B') {
		percentGrade = 80.00;
	}
	else if (desiredGrade == 'c' || desiredGrade == 'C') {
		percentGrade = 70.00;
	}
	else if (desiredGrade == 'd' || desiredGrade == 'D') {
		percentGrade = 60.00;
	}
	else if (desiredGrade == 'f' || desiredGrade == 'F') {
		percentGrade = 0.00;
	}
	else {
		printf("Unknown Grade Received: %c. Ending program.\n", desiredGrade);
		return 0;
	}

// prompts user for desired letter grade
	printf("Enter your current percent in the class: ");
	numInputs = scanf(" %lf%c", &currentPercent, &lastChar); // Char); // prompts user for current percent in class ?? FIX MEEEEEEEEEEEEEEEEEEEEEEEEE

// validate length of user input
	if(!isValidFormatting(numInputs, 2, lastChar)){
		printf("Invalid formatting. Ending program.\n");
		exit(0);// quit the program
	}
// check that input percent is a positive value
	else if (currentPercent < 0) {
		printf("The number you last entered should have been positive. Ending program.");
		return 0;
	}

// prompts user for the weight of the final
	printf("Enter the weight of the final: ");
	numInputs = scanf(" %lf%c", &finalWeight, &lastChar); //Char); // prompts user for current percent in class ?? 	FIX MEEEEEEEEEEEEEEEEEEEEEEE

// validate length of user input
	if(!isValidFormatting(numInputs, 2, lastChar)){
		printf("Invalid formatting. Ending program.\n");
		exit(0);// quit the program
	}
// check that input percentage is a positive value
	else if (finalWeight < 0) {
		printf("The number you last entered should have been positive. Ending program.");
		return 0;
	}

// compute the weighting of the current grade compared to the final grade
	currentWeight = 100 - finalWeight;
// compute percent needed on final for desired grade
	finalPercentNeed = (percentGrade -((currentWeight / 100) * currentPercent)) / finalWeight * 100.0;

// warns the student that their grade is too high to fail the class
	if (finalPercentNeed < 0) {
		printf("You cannot score low enough on the final to get a %c in the class.", desiredGrade);
	}
// breaks the sad news to the student if they cannot recover their grade, no matter how well they do on the final
	else if (finalPercentNeed > 100) {
		printf("You cannot get a %c in the class because you would need to score at least %.2lf%% on the final.\n", desiredGrade, finalPercentNeed);
	}
// print required grade
	else {
		printf("You need a grade of at least %.2lf%% on the final to get a %c in the class.\n", finalPercentNeed, desiredGrade);
	}

return 0;
}
