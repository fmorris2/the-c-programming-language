#include <stdio.h>
#include <stdbool.h>

/*
* This program contains the solution to the following exercises:
*	Exercise 1-3
*		Modify the temperature conversion program to print a heading above
*		the table.
*	Exercise 1-4
*		Write a program to print the corresponding Celsius to Fahrenheit table.
*	Exercise 1-5
*		Modify the temperature conversion program to print the table in reverse
*		order.
*/

float convertFahrenheitToCelsius(float fahr) {
	return (5.0 / 9.0) * (fahr - 32.0);
}

float convertCelsiusToFahrenheit(float cels) {
	return ((9.0 / 5.0) * cels) + 32.0;
}

bool validateBounds(float startTemp, float endTemp, float stepSize) {
	
	if(stepSize == 0) {
		return false;
	}	

	if(startTemp < endTemp && stepSize < 0) {
		return false;
	}

	if(startTemp > endTemp && stepSize > 0) {
		return false;
	}

	return true;
}

void printConversionTable(char* title, char fromUnit, char toUnit,
float (*conversionFunc)(float), float startTemp, float endTemp,
float stepSize) {
	
	if(!validateBounds(startTemp, endTemp, stepSize)) {
		printf("Your start, end, and step parameters must allow natural termination of the loop.");
		return;
	}
	
	//header
	printf("%50s\n", title);
	printf("%50s\n\n", "---------------------------------------");
	printf("%18c\t%18c\n", fromUnit, toUnit);

	//table contents
	float currentTemp = startTemp;
	bool shouldIterate;
 	while((shouldIterate = stepSize < 0 ? currentTemp >= endTemp : currentTemp <= endTemp) == true) {
		float convertedTemp = (*conversionFunc)(currentTemp);
		printf("%20.1f\t%20.1f\n", currentTemp, convertedTemp);
		currentTemp += stepSize;
	}
}

void printFahrToCelsConversionTable(float startTemp, float endTemp,
	float stepSize) {
	
	char* title = "Fahrenheit to Celsius Conversion Table";
	char fromUnit = 'F';
	char toUnit = 'C';

	printConversionTable(title, fromUnit, toUnit, &convertFahrenheitToCelsius,
		startTemp, endTemp, stepSize); 		
}

void printCelsToFahrConversionTable(float startTemp, float endTemp,
	float stepSize) {
	
	char* title = "Celsius to Fahrenheit Conversion Table";
	char fromUnit = 'C';
	char toUnit = 'F';

	printConversionTable(title, fromUnit, toUnit, &convertCelsiusToFahrenheit,
		startTemp, endTemp, stepSize); 		
}

/*
* Modify the temperature conversion program to print a heading above the table.
*/
main() {
	printFahrToCelsConversionTable(0,200,20);
	printf("\n");
	printCelsToFahrConversionTable(0,200,20);
	printf("\n");
	printCelsToFahrConversionTable(200,0,-20);
}
