// conversions.c

// converts temperatures and distances from one unit to another

int main() {
	#include <stdio.h>
	#include <stdbool.h>
	#include <ctype.h>
	#include <string.h>

	char inputSuffix;
	char outputSuffix;
	char conversionType;
	double fahrenheitTemp;
	double celsiusTemp;
	double kelvinTemp;
	double inchesDist;
	double feetDist;
	double yardsDist;
	double milesDist;
	double inputTemp;
	double inputDist;
	double outputTemp;
	double outputDist;
	int numInputs;
	char lastChar;

// returns true if the input has the correct number of characters
// otherwise returns false
// first argument is the number of inputs
// second argument is the number of inputs required to be correct formatting
// third argument is the last character in the input
	bool isValidFormatting(int numInputs, int numInputsNeeded, char lastChar) {
		return numInputs == numInputsNeeded && lastChar == '\n';
	}

// converts fahrenheit to celsius
	double fahrenheitTempToCelsiusTemp(double fahrenheitTemp) {
		celsiusTemp = (fahrenheitTemp - 32.0) * 5.0/9.0;
		return celsiusTemp;
	}

// converts kelvin to celsius
	double kelvinTempToCelsiusTemp(double kelvinTemp) {
		celsiusTemp = kelvinTemp - 273.15;
		return celsiusTemp;
	}

// converts celsius to fahrenheit
	double celsiusTempToFahrenheitTemp(double celsiusTemp) {
		fahrenheitTemp = (celsiusTemp * 9.0/5.0) + 32;
		return fahrenheitTemp;
	}

// converts celsius to kelvin
	double celsiusTempToKelvinTemp(double celsiusTemp) {
		kelvinTemp = celsiusTemp + 273.15;
		return kelvinTemp;
	}

// converts feet to inches
	double feetDistToInchesDist(double feetDist) {
		inchesDist = feetDist * 12;
		return inchesDist;
	}

// converts yards to inches
	double yardsDistToInchesDist(double yardsDist) {
		inchesDist = yardsDist * 36;
		return inchesDist;
	}

// converts miles to inches
	double milesDistToInchesDist(double milesDist) {
		inchesDist = milesDist * 63360;
		return inchesDist;
	}

// converts inches to feet
	double inchesDistToFeetDist(double inchesDist) {
		feetDist = inchesDist / 12.0;
		return feetDist;
	}

// converts inches to yards
	double inchesDistToYardsDist(double inchesDist) {
		yardsDist = inchesDist / 36.0;
		return yardsDist;
	}

// converts inches to miles
	double inchesDistToMilesDist(double inchesDist) {
		milesDist = inchesDist / 63360;
		return milesDist;
	}

// converts temperature values from one unit to another
	int temperatureConversion() {

		// ask for user input
		printf("Enter the temperature followed by its suffix (F, C, or K): ");
		numInputs = scanf(" %lf %c%c", &inputTemp, &inputSuffix, &lastChar);

		// validate length of user input
		if (!isValidFormatting(numInputs, 3, lastChar)) {
			printf("Invalid formatting. Ending program.\n");
			return 0;
		}
		// check that user input is a valid temperature unit
		else if (inputSuffix == 'F' || inputSuffix == 'f') {
			celsiusTemp = fahrenheitTempToCelsiusTemp(inputTemp);
			inputSuffix = 'F';
		}
		else if (inputSuffix == 'C' || inputSuffix == 'c') {
			celsiusTemp = inputTemp;
			inputSuffix = 'C';
		}
		else if (inputSuffix == 'K' || inputSuffix == 'k') {
			celsiusTemp = kelvinTempToCelsiusTemp(inputTemp);
			inputSuffix = 'K';
		}
		// check if user input is a alphabetical character
		else if (isalpha(inputSuffix)) {
			printf("%c is not a valid temperature type. Ending program.\n", inputSuffix);
			return 0;
		}
		// break if format is invalid
		else {
			printf("Invalid formatting. Ending program.\n");
			return 0;
		}

		// accept user input
		printf("Enter the new unit type (F, C, or K): ");
		numInputs = scanf(" %c%c", &outputSuffix, &lastChar);

		// validate length of user input
		if (!isValidFormatting(numInputs, 2, lastChar)) {
			printf("Invalid formatting. Ending program.\n");
			return 0;
		}
		// check that user input is a valid temperature unit
		if (outputSuffix == 'F' || outputSuffix == 'f') {
			outputTemp = celsiusTempToFahrenheitTemp(celsiusTemp);
			outputSuffix = 'F';
		}
		else if (outputSuffix == 'C' || outputSuffix == 'c') {
			outputTemp = celsiusTemp;
			outputSuffix = 'C';
		}
		else if (outputSuffix == 'K' || outputSuffix == 'k') {
			outputTemp = celsiusTempToKelvinTemp(celsiusTemp);
			outputSuffix = 'K';
		}
		// check to see if input is an alphabetical character
		else if (isalpha(outputSuffix)) {
			printf("%c is not a valid temperature type. Ending program.", outputSuffix);
			return 0;
		}
		// break if format is invalid
		else {
			printf("Invalid formatting. Ending program.\n");
			return 0;
		}

		//print converted temperature
		printf("%.2lf%c is %.2lf%c\n", inputTemp, inputSuffix, outputTemp, outputSuffix);
		return 0;
	}

// converts distance values from one unit to another
	int distanceConversion() {

		// accept user input
		printf("Enter the distance followed by its suffix (I,F,Y,M): ");
		numInputs = scanf(" %lf %c%c", &inputDist, &inputSuffix, &lastChar);

		// check to see if length of input is valid
		if (!isValidFormatting(numInputs, 3, lastChar)) {
			printf("Invalid formatting. Ending program.\n");
			return 0;
		}
		// check to see if input is a valid distance unit
		if (inputSuffix == 'I' || inputSuffix == 'i') {
			inchesDist = inputDist;
			inputSuffix = 'I';
		}
		else if (inputSuffix == 'F' || inputSuffix == 'f') {
			inchesDist = feetDistToInchesDist(inputDist);
			inputSuffix = 'F';
		}
		else if (inputSuffix == 'Y' || inputSuffix == 'y') {
			inchesDist = yardsDistToInchesDist(inputDist);
			inputSuffix = 'Y';
		}
		else if (inputSuffix == 'M' || inputSuffix == 'm') {
			inchesDist = milesDistToInchesDist(inputDist);
			inputSuffix = 'M';
		}
		// check to see if input is an alphabetical character - breaks if true
		else if (isalpha(inputSuffix)) {
			printf("%c is not a valid distance type. Ending program.\n", inputSuffix);
			return 0;
		}
		// break if input is invalid
		else {
			printf("Invalid formatting. Ending program.\n");
			return 0;
		}

		// ask for user input
			printf("Enter the new unit type (I,F,Y,M): ");
		numInputs = scanf(" %c%c", &outputSuffix, &lastChar);

		// check that input is the correct number of character
		if (!isValidFormatting(numInputs, 2, lastChar)) {
			printf("Invalid formatting. Ending program.\n");
			return 0;
		}
		// check that input is a valid distance unit
		if (outputSuffix == 'I' || outputSuffix == 'i') {
			outputDist = inchesDist;
			outputSuffix = 'I';
		}
		else if (outputSuffix == 'F' || outputSuffix == 'f') {
			outputDist = inchesDistToFeetDist(inchesDist);
			outputSuffix = 'F';
		}
		else if (outputSuffix == 'Y' || outputSuffix == 'y') {
			outputDist = inchesDistToYardsDist(inchesDist);
			outputSuffix = 'Y';
		}
		else if (outputSuffix == 'M' || outputSuffix == 'm') {
			outputDist = inchesDistToMilesDist(inchesDist);
			outputSuffix = 'M';
		}
		// check that input is an alphabetical character - if so, break
		else if (isalpha(outputSuffix)) {
			printf("%c is not a valid distance type. Ending program.\n", outputSuffix);
			return 0;
		}
		// break if input is invalid
		else {
			printf("Invalid formatting. Ending program.\n");
			return 0;
		}

		// print unit conversions
		printf("%.2lf%c is %.2lf%c\n", inputDist, inputSuffix, outputDist, outputSuffix);
		return 0;
	}

	// ask user whether the conversion is a distance or temperature conversion
	printf("Pick the type of conversion that you would like to do.\nT or t for temperature\nD or d for distance\nEnter your choice: ");
	numInputs = scanf(" %c%c", &conversionType, &lastChar);

	// check that input is the correct number of characters
	if (!isValidFormatting(numInputs, 2, lastChar)) {
			printf("Invalid formatting. Ending program.\n");
			return 0;
		}

	// check that input is a correct conversion type
	if (conversionType == 'T' || conversionType == 't') {
		temperatureConversion();
	}
	else if (conversionType == 'D' || conversionType == 'd') {
		distanceConversion();
	}
	// break if input is an invalid alphabetical character
	else if (isalpha(conversionType)) {
			printf("Unknown conversion type %c chosen. Ending program.", conversionType);
			return 0;
		}
	// break if user input is invalid
	else {
		printf("Invalid formatting. Ending program.");
		return 0;
	}

	return 0;
}
