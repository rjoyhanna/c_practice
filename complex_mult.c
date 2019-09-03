// complex_mult.c

#include <stdio.h>

int main(){

	int firstCoefficient;
	int firstNum;
	int secondCoefficient;
	int secondNum;
	int Fval; // variable names refer to "FOIL", as in the acronym for multiplying out expressions
	int Ival;
	int Oval;
	int Lval;
	int finalNum;
	int finalCoefficient;

	printf("Enter the first complex number in the form ai + b:\n");
	scanf("%d i + %d", &firstCoefficient, &firstNum); // prompts user for first complex number

	printf("Enter the second complex number in the form ai + b:\n");
	scanf("%d i + %d", &secondCoefficient, &secondNum); // prompts user for second complex number

	Fval = firstCoefficient * secondCoefficient; // multiplies coefficients of first terms
	Oval = secondNum * firstCoefficient; // multiples outer terms 
	Ival = firstNum * secondCoefficient; // multiples inner terms
	Lval = firstNum * secondNum; // multiplies last terms
	finalNum = -Fval + Lval; // adds product of first terms and product of last terms
	finalCoefficient = Ival + Oval; // adds product of inner terms and product of outer terms

	printf("(%di + %d) * (%di + %d) = %di + %d\n", firstCoefficient, firstNum, secondCoefficient, secondNum, finalCoefficient, finalNum);

	return 0;
}