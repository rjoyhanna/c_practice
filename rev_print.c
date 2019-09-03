// rev_print.c

// prints out a string in reverse

#include <string.h>
#include <stdio.h>


void rev_print(char* str);

int main(int argc, char* argv[]) {
	printf("The reverse of %s is ", argv[1]); //prints out the original string
	rev_print(argv[1]); //prints out the reverse of the string
	return 0;
}

//iterates through the string printing the last character each time and then setting it to a null character
void rev_print(char* str) {
	if (strlen(str) == 0) return; //exits the function once the string is out of characters

	printf("%c", str[strlen(str) - 1]); //prints the last character in the string
	str[strlen(str) - 1] = '\0'; //sets the last character to a null character
	rev_print(str); //runs the function recursively
}
