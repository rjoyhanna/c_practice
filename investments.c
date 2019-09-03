// investments.c

// determine if it is better to put as much money as you can
// towards your student loans before saving for retirement
// or if it is better to only pay the minimum payment on your loan and invest the rest

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// return true if number of inputs is correct and retirement age is greater than current age
bool IsValidRetirementInput(int numArgsRead, int numArgsNeeded, int retirementAge, int userAge);
// return true if number of inputs is correct and input is positive
bool IsValidPosInput(int numArgsRead, int numArgsNeeded, double num);
// return true if number of inputs is correct
bool IsValidFormat (int numArgsRead, int numArgsNeeded);
// return true if input is positive
bool IsPositive(double num);
// return true if retirement age is greater than current age
bool ValidRetirementAge(int userAge, int retirementAge);
// compute amount saved for retirement if minimum payments are made to student loans
double InvestRetirementAmount(double moneyPerMonth, double loanAmount, double loanInterestRate, double monthlyLoanPayment, int totalMonths, double monthlyInvestmentReturn);
// compute amount saved for retirement if loans are paid off before investing in retirement
double PayoffRetirementAmount(double moneyPerMonth, double loanAmount, double loanInterestRate, double monthlyLoanPayment, int totalMonths, double monthlyInvestmentReturn);

int main() {

	int numArgsNeeded = 1;
	int numArgsRead;
	double moneyPerMonth;
	double loanAmount;
	double loanInterestRate;
	double monthlyLoanPayment;
	int userAge;
	int retirementAge;
	double annualInvestmentReturn;
	double payoffRetirementAmount = 0;
	double investRetirementAmount = 0;

	// accept user input and validate (see function descriptions for details)
	do {
		printf("Enter how much money you will be putting towards loans/retirement each month: ");
		numArgsRead = scanf("%lf", &moneyPerMonth);
	} while (!IsValidPosInput(numArgsRead, numArgsNeeded, moneyPerMonth));

	do {
		printf("Enter how much you owe in loans: ");
		numArgsRead = scanf("%lf", &loanAmount);
	} while (!IsValidPosInput(numArgsRead, numArgsNeeded, loanAmount));

	do {
		printf("Enter the annual interest rate of the loans: ");
		numArgsRead = scanf("%lf", &loanInterestRate);
	} while (!IsValidPosInput(numArgsRead, numArgsNeeded, loanInterestRate));

	do {
		printf("Enter your minimum monthly loan payment: ");
		numArgsRead = scanf("%lf", &monthlyLoanPayment);
	} while (!IsValidPosInput(numArgsRead, numArgsNeeded, monthlyLoanPayment));

	if (monthlyLoanPayment > moneyPerMonth) {
		printf("You didn't set aside enough money to pay off our loans. Ending program.");
		return 0;
	}

	do {
		printf("Enter your current age: ");
		numArgsRead = scanf("%d", &userAge);
	} while (!IsValidPosInput(numArgsRead, numArgsNeeded, userAge));

	do {
		printf("Enter the age you plan to retire at: ");
		numArgsRead = scanf("%d", &retirementAge);
	} while (!IsValidRetirementInput(numArgsRead, numArgsNeeded, retirementAge, userAge));

	do {
		printf("Enter the annual rate of return you predict for your investments: ");
		numArgsRead = scanf("%lf", &annualInvestmentReturn);
	} while (!IsValidPosInput(numArgsRead, numArgsNeeded, annualInvestmentReturn));

	// compute monthly loan interest rate
	loanInterestRate = loanInterestRate / 12.0;
	// compute monthly investment return
	double monthlyInvestmentReturn = annualInvestmentReturn / 12.0;
	// computes total months between current age and retirement
	int totalMonths = (retirementAge - userAge) * 12;

	// compute amount saved for retirement if minimum payments are made to student loans
	investRetirementAmount = InvestRetirementAmount(moneyPerMonth, loanAmount, loanInterestRate, monthlyLoanPayment, totalMonths, monthlyInvestmentReturn);

	// compute amount saved for retirement if loans are paid off before investing in retirement
	payoffRetirementAmount = PayoffRetirementAmount(moneyPerMonth, loanAmount, loanInterestRate, monthlyLoanPayment, totalMonths, monthlyInvestmentReturn);

	// tell user to pay minimum payments
	if (investRetirementAmount > payoffRetirementAmount) {
		printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
		printf("If you do you will have $%.2lf when you retire as opposed to ", investRetirementAmount);
		printf("$%.2lf if you payed off your loan before investing.", payoffRetirementAmount);
	}

	// tell user to pay full payments
	else {
		printf("You should apply all $%.2lf towards your loan before making any investments.\n", moneyPerMonth);
		printf("If you do you will have $%.2lf when you retire as opposed to ", payoffRetirementAmount);
		printf("$%.2lf if you only made minimum payments.", investRetirementAmount);
	}

	return 0;
}

// return true if number of inputs is correct and retirement age is greater than current age
// numArgsRead is number of inputs
// numArgsNeeded is number of inputs desired
// retirementAge is expected age of retirement
// userAge is current age of user
bool IsValidRetirementInput(int numArgsRead, int numArgsNeeded, int retirementAge, int userAge) {
	return IsValidFormat(numArgsRead, numArgsNeeded) && ValidRetirementAge(userAge, retirementAge);
}

// return true if number of inputs is correct and input is positive
// numArgsRead is number of inputs
// numArgsNeeded is number of inputs desired
// num is input
bool IsValidPosInput(int numArgsRead, int numArgsNeeded, double num) {
	return IsValidFormat(numArgsRead, numArgsNeeded) && IsPositive(num);
}

// return true if number of inputs is correct
// numArgsRead is number of inputs
// numArgsNeeded is number of inputs desired
bool IsValidFormat (int numArgsRead, int numArgsNeeded) {
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
// num is user input
bool IsPositive(double num) {
	return num > 0;
}

// return true if retirement age is greater than current age
// userAge is current age of user
// retirementAge is expected age of retirement
bool ValidRetirementAge(int userAge, int retirementAge) {
	return retirementAge > userAge;
}

// compute amount saved for retirement if minimum payments are made to student loans
// moneyPerMonth is money set aside for investing/paying off loans
// loanAmount is amount stilled owed in loans
// loanInterestRate is monthly interest rate of loan
// monthlyLoanPayment is minimum loan payment
// totalMonths is months until retirement
// monthlyInvestmentReturn is return on investment per month
double InvestRetirementAmount(double moneyPerMonth, double loanAmount, double loanInterestRate, double monthlyLoanPayment, int totalMonths, double monthlyInvestmentReturn) {
	double monthlyRetirementContribution = moneyPerMonth - monthlyLoanPayment;
	double retirement = 0;
	int currentMonth;

// calculate months it takes to pay off debt with minimum payments and retirement
	int monthsOfPayments = 0;
	for (currentMonth = 0; currentMonth < totalMonths; currentMonth++) {
		loanAmount = loanAmount + (loanAmount * loanInterestRate);
		retirement = retirement + (retirement * monthlyInvestmentReturn);
		if (loanAmount < monthlyLoanPayment) {
			retirement = retirement + (moneyPerMonth - loanAmount);
			loanAmount = 0;
			monthsOfPayments++;
			break;
		}
		monthsOfPayments++;
		loanAmount = loanAmount - monthlyLoanPayment;
		retirement = retirement + monthlyRetirementContribution;
		if (currentMonth == (totalMonths - 1) && loanAmount > monthlyLoanPayment) {
			printf("Warning! After you retire you will still have $%.2lf in loans left.\n", loanAmount);
		}
	}

// calculate total retirement during months after loan payment
	for (currentMonth = monthsOfPayments; currentMonth < totalMonths; currentMonth++) {
		retirement = retirement + (retirement * monthlyInvestmentReturn);
		retirement = retirement + moneyPerMonth;
	}

	//retirement = retirement + (retirement * monthlyInvestmentReturn);

	return retirement;
}

// compute amount saved for retirement if loans are paid off before investing in retirement
// moneyPerMonth is money set aside for investing/paying off loans
// loanAmount is amount stilled owed in loans
// loanInterestRate is monthly interest rate of loan
// monthlyLoanPayment is minimum loan payment
// totalMonths is months until retirement
// monthlyInvestmentReturn is return on investment per month
double PayoffRetirementAmount(double moneyPerMonth, double loanAmount, double loanInterestRate, double monthlyLoanPayment, int totalMonths, double monthlyInvestmentReturn) {
	double retirement = 0;
	int currentMonth;

// calculate months it takes to pay off debt with full payments
	int monthsOfPayments = 0;
	for (currentMonth = 0; currentMonth < totalMonths; currentMonth++) {
		loanAmount = loanAmount + (loanAmount * loanInterestRate);
		monthsOfPayments++;
		if (loanAmount < moneyPerMonth) {
			retirement = retirement + (moneyPerMonth - loanAmount);
			loanAmount = 0;
			break;
		}
		loanAmount = loanAmount - moneyPerMonth;
		if (currentMonth == totalMonths && loanAmount > monthlyLoanPayment) {
			printf("Warning! After you retire you will still have $%.2lf in loans left.", loanAmount);
		}
	}

// calculate total retirement during months after loan payment
	for (currentMonth = monthsOfPayments; currentMonth < totalMonths; currentMonth++) {
		retirement = retirement + (retirement * monthlyInvestmentReturn);
		retirement = retirement + moneyPerMonth;
	}

	return retirement;
}
