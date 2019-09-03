// bin_str.c

// this program completes a binary number

#include <stdio.h>
#include <string.h>

void CompleteBinary(char binStr[]);
int HasX(char binStr[]);

int main(int argc, char* argv[]) {
	CompleteBinary(argv[1]);
	return 0;
}

// recursively changes x's to binary characters or prints binary number if there are no x's
void CompleteBinary(char binStr[]) {
	int indexOfX = HasX(binStr);  // index of the first x character in the string
	char binStr2[strlen(binStr)];  // initializes an array of equal size to the string
	strcpy(binStr2, binStr); // copies string to the array

	// statement runs if the array has an x value
	if (indexOfX > -1) {
		// changes first x to a 0 and then runs the program again with a new string
		binStr2[indexOfX] = '0';
		CompleteBinary(binStr2);

		//  changes first x to a 1 and then runs the program again with a new string
		binStr2[indexOfX] = '1';
		CompleteBinary(binStr2);
	}

	//prints string if there are no x's
	else {
		printf("%s\n", binStr2);
	}
}

// returns position of the first x or -1 if there are none
int HasX(char binStr[]) {
	for (int i = 0; i < strlen(binStr); i++) {
		if (binStr[i] == 'x') {
			return i;
		}
	}
	return -1;
}
