// plural.c

// asks the user for a noun and prints out its plural form

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// if word ends in ch, sh, s, x, or z, return true
bool EndsWithCH_SH_S_X_Z(char lastChar, char secondToLastChar);

// if word ends in a vowel folowed by y, return true
bool EndsWithVowelAndY(char lastChar, char secondToLastChar);

// if word ends with a consonant and y, return true
bool EndsWithConsonantAndY(char lastChar, char secondToLastChar);

// if word ends in f, return true
bool EndsWithF(char lastChar, char secondToLastChar);

// if word ends in fe, return true
bool EndsWithFE(char lastChar, char secondToLastChar);

int main() {
	char userString[21] = "";
	char finalString[21] = "";
	char lastChar;
	char secondToLastChar;

	// accept user input
	printf("Please enter a word: ");
	scanf("%s", userString);

	// determine the last character and second to last character in the word
	lastChar = userString[strlen(userString) - 1];
	secondToLastChar = userString[strlen(userString) - 2];
	// copy the word to a new string
	strcpy(finalString, userString);

	// if word ends in ch, sh, s, x, or z, add es
	if (EndsWithCH_SH_S_X_Z(lastChar, secondToLastChar)) {
		finalString[strlen(userString)] = 'e';
		finalString[strlen(userString) + 1] = 's';
		finalString[strlen(userString) + 2] = '\0';
	}

	// if word ends in a vowel folowed by y, add s
	else if (EndsWithVowelAndY(lastChar, secondToLastChar)) {
		finalString[strlen(userString)] = 's';
		finalString[strlen(userString) + 1] = '\0';
	}

	// if word ends with a consonant and y, y becomes ies
	else if (EndsWithConsonantAndY(lastChar, secondToLastChar)) {
		finalString[strlen(userString) - 1] = 'i';
		finalString[strlen(userString)] = 'e';
		finalString[strlen(userString) + 1] = 's';
		finalString[strlen(userString) + 2] = '\0';
	}

	// if word ends in f, f becomes ves
	else if (EndsWithF(lastChar, secondToLastChar)) {
		finalString[strlen(userString) - 1] = 'v';
		finalString[strlen(userString)] = 'e';
		finalString[strlen(userString) + 1] = 's';
		finalString[strlen(userString) + 2] = '\0';
	}

	// if word ends in fe, fe becomes ves
	else if (EndsWithFE(lastChar, secondToLastChar)) {
		finalString[strlen(userString) - 2] = 'v';
		finalString[strlen(userString) - 1] = 'e';
		finalString[strlen(userString)] = 's';
		finalString[strlen(userString) + 1] = '\0';
	}

	// or else, add s
	else {
		finalString[strlen(userString)] = 's';
		finalString[strlen(userString) + 1] = '\0';
	}

	// print statement
	printf("The plural form of %s is %s.", userString, finalString);
	return 0;
}

// if word ends in ch, sh, s, x, or z, return true
// lastChar is the last character in the word
// secondToLastChar is the second to last character in the word
bool EndsWithCH_SH_S_X_Z(char lastChar, char secondToLastChar) {
	bool matchingEnding;
	lastChar = toupper(lastChar);
	secondToLastChar = toupper(secondToLastChar);
	matchingEnding = (lastChar == 'S' || lastChar == 'X' || lastChar == 'Z');
	if (lastChar == 'H' && (secondToLastChar == 'C' || secondToLastChar == 'S')) {
		matchingEnding = true;
	}
	return matchingEnding;
}

// if word ends in a vowel folowed by y, return true
// lastChar is the last character in the word
// secondToLastChar is the second to last character in the word
bool EndsWithVowelAndY(char lastChar, char secondToLastChar) {
	bool matchingEnding = false;
	lastChar = toupper(lastChar);
	secondToLastChar = toupper(secondToLastChar);
	if (lastChar == 'Y' && (secondToLastChar == 'A' || secondToLastChar == 'E' || secondToLastChar == 'I' || secondToLastChar == 'O' || secondToLastChar == 'U')) {
		matchingEnding = true;
	}
	return matchingEnding;
}

// if word ends with a consonant and y, return true
// lastChar is the last character in the word
// secondToLastChar is the second to last character in the word
bool EndsWithConsonantAndY(char lastChar, char secondToLastChar) {
	bool matchingEnding = false;
	lastChar = toupper(lastChar);
	secondToLastChar = toupper(secondToLastChar);
	if (lastChar == 'Y' && !(secondToLastChar == 'A' || secondToLastChar == 'E' || secondToLastChar == 'I' || secondToLastChar == 'O' || secondToLastChar == 'U')) {
		matchingEnding = true;
	}
	return matchingEnding;
}

// if word ends in f, return true
// lastChar is the last character in the word
// secondToLastChar is the second to last character in the word
bool EndsWithF(char lastChar, char secondToLastChar) {
	bool matchingEnding;
	lastChar = toupper(lastChar);
	secondToLastChar = toupper(secondToLastChar);
	matchingEnding = (lastChar == 'F');
	return matchingEnding;
}

// if word ends in fe, return true
// lastChar is the last character in the word
// secondToLastChar is the second to last character in the word
bool EndsWithFE(char lastChar, char secondToLastChar) {
	bool matchingEnding;
	lastChar = toupper(lastChar);
	secondToLastChar = toupper(secondToLastChar);
	matchingEnding = (lastChar == 'S' || lastChar == 'X' || lastChar == 'Z');
	if (lastChar == 'E' && secondToLastChar == 'F') {
		matchingEnding = true;
	}
	return matchingEnding;
}
