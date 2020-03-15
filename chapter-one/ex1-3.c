#include <stdio.h>

float convertFahrenheitToCelsius(float fahr) {
	return (5.0 / 9.0) * (fahr - 32.0);
}

void printFahrToCelsConversionTable(float minTemp, float maxTemp,
	float stepSize) {
	
	//header
	printf("%50s\n", "Fahrenheit --> Celsius Conversion Table");
	printf("%50s\n\n", "---------------------------------------");
	printf("%18s\t%18s\n", "F", "C");

	//table contents
	float currentTemp = minTemp;
	for(; currentTemp <= maxTemp; currentTemp += stepSize) {
		float celsius = convertFahrenheitToCelsius(currentTemp);
		printf("%20.1f\t%20.1f\n", currentTemp, celsius);
	}	
}

/*
* Modify the temperature conversion program to print a heading above the table.
*/
main() {
	printFahrToCelsConversionTable(0,200,20);
}
