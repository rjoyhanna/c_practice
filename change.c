int main(){
	#include <stdio.h>
	int moneyAmount = 0; //types of currency assigned to respective values
	int hundred = 100;
	int fifty = 50;
	int twenty = 20;
	int ten = 10;
	int five = 5;
	int one = 1;

	printf("Please enter the amount of money you wish to withdraw:\n");
	scanf("%d", &moneyAmount); //read user input into moneyAmount
	int hundreds = moneyAmount / hundred; //computes number of hundred dollar bills
	int moneyAmount2 = moneyAmount % hundred; //computes remainder of money
	int fifties = moneyAmount2 / fifty; //computes number of fifty dollar bills
	int moneyAmount3 = moneyAmount2 % fifty; //computes remainder of money
	int twenties = moneyAmount3 / twenty; //computes number of twenty dollar bills
	int moneyAmount4 = moneyAmount3 % twenty; //computes remainder of money
	int tens = moneyAmount4 / ten; //computes number of ten dollar bills
	int moneyAmount5 = moneyAmount4 % ten; //computes remainder of money
	int fives = moneyAmount5 / five; //computes number of five dollar bills
	int moneyAmount6 = moneyAmount5 % five; //computes remainder of money
	int ones = moneyAmount6 / one; //computes number of one dollar bills

	printf("You received %d hundred(s)\n", hundreds);
	printf("You received %d fifty(s)\n", fifties);
	printf("You received %d twenty(s)\n", twenties);
	printf("You received %d ten(s)\n", tens);
	printf("You received %d five(s)\n", fives);
	printf("You received %d one(s)\n", ones);

	return 0;
}
