// anagram.c

// checks if two words are anagrams of each other

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// return true if the two words are equal length
bool IsEqualLength(char firstWordCopy[], char secondWordCopy[]);
// return true if the two words are anagrams of each other
bool IsAnagram(char firstWordCopy[], char secondWordCopy[]);
// create a string of all lowercase letters to make comparison easier
void lowercaseWord(char userWord[]);

int main() {
	char firstWord[21] = "";
	char secondWord[21] = "";
	// copy the two words so that they can be manipulated without losing the initial strings
	char firstWordCopy[21] = "";
	char secondWordCopy[21] = "";

	// accept user input
	printf("Please enter the first word: ");
	scanf("%s", firstWord);

	printf("Please enter the second word: ");
	scanf("%s", secondWord);

	// copy the two words so that they can be manipulated without losing the initial strings
	strcpy(firstWordCopy, firstWord);
	strcpy(secondWordCopy, secondWord);

	// create a string of all lowercase letters to make comparison easier
	lowercaseWord(firstWordCopy);
	lowercaseWord(secondWordCopy);

	// determine if the strings are equal lengths and if they are anagrams of each other
	bool isAnagram = (IsAnagram(firstWordCopy, secondWordCopy) && IsEqualLength(firstWordCopy, secondWordCopy));

	// print statements
	if (isAnagram == true) {
		printf("%s is an anagram of %s", firstWord, secondWord);
	}

	else {
		printf("%s is NOT an anagram of %s", firstWord, secondWord);

	}
	return 0;
}

// return true if the two words are equal length
// arguments are the two words to be compared
bool IsEqualLength(char firstWordCopy[], char secondWordCopy[]) {
	return (strlen(firstWordCopy) == strlen(secondWordCopy));
}

// create a string of all lowercase letters to make comparison easier
// argument is the word to be lowercased
void lowercaseWord(char userWord[]) {
	int wordChar;
	for (wordChar = 0; wordChar < strlen(userWord); wordChar++) {
	userWord[wordChar] = tolower(userWord[wordChar]);
	}
	return;
}

// return true if the two words are anagrams of each other
// arguments are the two words to be compared
bool IsAnagram(char firstWordCopy[], char secondWordCopy[]) {
	bool charFound;
	int wordChar;
	int secondWordChar;
	for (wordChar = 0; wordChar < strlen(firstWordCopy); wordChar++) {
		charFound = false;

		for (secondWordChar = 0; secondWordChar < strlen(firstWordCopy); secondWordChar++) {

			if (firstWordCopy[wordChar] - secondWordCopy[secondWordChar] == 0) {
				secondWordCopy[secondWordChar] = '!';
				charFound = true;
				break;
			}
		}

		if (charFound == false) {
			return false;
		}
	}
	return true;
}
