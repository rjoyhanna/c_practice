// loan_cost.c

int main(){
	#include <stdio.h>
	#include <math.h>

	double borrowedAmount;
	double AnnualInterestRate;
	int numberOfPayments;
	double totalPayment;
	double loanCost;
	double monthlyPayment;

	printf("Please enter the amount of money you borrowed: \n$");
	scanf("%lf", &borrowedAmount); // prompts user for the loan amount

	printf("Please enter the annual interest rate:\n");
	scanf("%lf", &AnnualInterestRate); // prompts user for annual interest rate

	printf("Please enter the number of payments to be made:\n");
	scanf("%d", &numberOfPayments); // prompts user for number of payments


	monthlyPayment = (AnnualInterestRate / 12) * borrowedAmount / (1.0 - pow(1.0 + (AnnualInterestRate / 12), -numberOfPayments)); //computes monthly payment
	totalPayment = monthlyPayment * numberOfPayments; // computes total payment
	loanCost = totalPayment - borrowedAmount; // computes the cost of the loan

	printf("A loan of $%.2lf with an annual interest of %.2lf payed off over %d months will have monthly payments of $%.2lf.\n", borrowedAmount, AnnualInterestRate, numberOfPayments, monthlyPayment);
	printf("In total you will pay $%.2lf, making the cost of your loan $%.2lf.\n", totalPayment, loanCost);

	return 0;
}
