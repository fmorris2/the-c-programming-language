#include <stdio.h>

/*
* This program contains the solution to the following exercises:
*	Exercise 1-3
*		Modify the temperature conversion program to print a heading above
*		the table.
*	Exercise 1-4
*		Write a program to print the corresponding Celsius to Fahrenheit table.
*/


float convertFahrenheitToCelsius(float fahr) {
	return (5.0 / 9.0) * (fahr - 32.0);
}

float convertCelsiusToFahrenheit(float cels) {
	return ((9.0 / 5.0) * cels) + 32.0;
}

void printConversionTable(char* title, char fromUnit, char toUnit,
float (*conversionFunc)(float),  float minTemp, float maxTemp,
float stepSize) {
	//header
	printf("%50s\n", title);
	printf("%50s\n\n", "---------------------------------------");
	printf("%18c\t%18c\n", fromUnit, toUnit);

	//table contents
	float currentTemp = minTemp;
	for(; currentTemp <= maxTemp; currentTemp += stepSize) {
		float convertedTemp = (*conversionFunc)(currentTemp);
		printf("%20.1f\t%20.1f\n", currentTemp, convertedTemp);
	}
}

void printFahrToCelsConversionTable(float minTemp, float maxTemp,
	float stepSize) {
	
	char* title = "Fahrenheit to Celsius Conversion Table";
	char fromUnit = 'F';
	char toUnit = 'C';

	printConversionTable(title, fromUnit, toUnit, &convertFahrenheitToCelsius,
		minTemp, maxTemp, stepSize); 		
}

void printCelsToFahrConversionTable(float minTemp, float maxTemp,
	float stepSize) {
	
	char* title = "Celsius to Fahrenheit Conversion Table";
	char fromUnit = 'C';
	char toUnit = 'F';

	printConversionTable(title, fromUnit, toUnit, &convertCelsiusToFahrenheit,
		minTemp, maxTemp, stepSize); 		
}

/*
* Modify the temperature conversion program to print a heading above the table.
*/
main() {
	printFahrToCelsConversionTable(0,200,20);
	printCelsToFahrConversionTable(0,200,20);
}
