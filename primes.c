// primes.c

// finding all of the prime numbers between 2 and N (inclusive)

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// asks user for int value
int accept_user_input();
// finds number of primes from 2 to user input (userNum)
int find_num_primes(int userNum);
// allocates space for userNum number of integers in an array
int* allocate_space(int numPrimes);
// adds numPrimes number of prime values into array
void create_prime_array(int userNum, int* prime_array);
// returns true if a value is prime
bool is_prime(int testInt);
// returns true if input is an integer greater than 1
bool is_valid_input(int userNum);
// prints out array values one line at a time
void display_results(int* prime_array, int userNum, int numPrimes);
// deletes space for array
void delete_array(int* prime_array);

int main() {
	// asks user for int value
	int userNum = accept_user_input();
	// finds number of primes from 2 to user input (userNum)
	int numPrimes = find_num_primes(userNum);
	// allocates space for userNum number of integers in an array
	int* prime_array = allocate_space(numPrimes);
	// adds numPrimes number of prime values into array
	create_prime_array(userNum, prime_array);
	// prints out array values one line at a time
	display_results(prime_array, userNum, numPrimes);
	// deletes space for array
	delete_array(prime_array);
	return 0;
}

// asks user for int value
int accept_user_input() {
	int userNum = 0;
	do {
		printf("Enter a number greater than 1: ");
		scanf(" %d", &userNum);
	} while (!is_valid_input(userNum));
	return userNum;
}

// finds number of primes from 2 to user input (userNum)
int find_num_primes(int userNum) {
	int testInt;
	int arrayVal = 0;
	for (testInt = 2; testInt <= userNum; testInt++) {
		if (is_prime(testInt)) {
			arrayVal++;
		}
	}
	return arrayVal;
}

// allocates space for numPrimes number of integers in an array
int* allocate_space(int numPrimes) {
	int* prime_array = (int*) malloc(numPrimes * sizeof(int));
	// display_results(prime_array, numPrimes, numPrimes);
	return prime_array;
}

// adds numPrimes number of prime values into array
void create_prime_array(int userNum, int* prime_array) {
	int testInt;
	int arrayVal = 0;
	for (testInt = 2; testInt <= userNum; testInt++) {
		if (is_prime(testInt)) {
			prime_array[arrayVal] = testInt;
			arrayVal++;
		}
	}
	return;
}

// returns true if a value is prime
bool is_prime(int testInt) {
	int testFactor;
	// tests if value is divisible by any value from 2 to the integer in question
	for (testFactor = 2; testFactor < testInt; testFactor++) {
		if (testInt % testFactor == 0) {
			return false;
		}
	}
	return true;
}

// returns true if input is an integer greater than 1
bool is_valid_input(int userNum) {
	char extraChar;
	bool isValid = true;
	// eating up all unused characters in invalid input
	do {
		scanf("%c", &extraChar);
		if (!isspace(extraChar)) {
			isValid = false;
		}
	} while (extraChar != '\n');
	return (userNum > 1) && isValid;
}

// prints out array values one line at a time
void display_results(int* prime_array, int userNum, int numPrimes) {
	int num;
	printf("The primes between 2 and %d are:\n", userNum);
	for (num = 0; num < numPrimes; num++) {
		printf("%d\n", prime_array[num]);
	}
	return;
}

// deletes space for array
void delete_array(int* prime_array) {
	free(prime_array);
	return;
}
