#include <stdio.h>

/*
*	Exercise 1-17
*		Write a program to print all input lines that are
*		longer than 80 characters.
*		
*	Personal Note:
*		The instructions say 80 characters. I chose 5 for ease of
*		testing. To adhere to the instructions, simply change the
*		constant defined below.
*/

#define INPUT_LINE_LENGTH_THRESHOLD  5 //print all input lines > this length

void printBuffer(int buffer[], int length);

int main() {
	
	int buffer[INPUT_LINE_LENGTH_THRESHOLD];
	int currentChar;
	int currentLineLength = 0;
	
	while((currentChar = getchar()) != EOF) {
		if(currentChar == '\n') {
			if(currentLineLength > INPUT_LINE_LENGTH_THRESHOLD) {
				putchar(currentChar);
			}
			currentLineLength = 0;
		} else if(currentLineLength < INPUT_LINE_LENGTH_THRESHOLD) {
			buffer[currentLineLength] = currentChar;
			currentLineLength++;
		} else if(currentLineLength == INPUT_LINE_LENGTH_THRESHOLD) {
			printBuffer(buffer, currentLineLength);
			putchar(currentChar);
			currentLineLength++;;
		} else {
			putchar(currentChar);
		}
	}	
	
	return 0;
}

void printBuffer(int buffer[], int length) {
	int i;
	for(i = 0; i < length; i++) {
		putchar(buffer[i]);	
	}
}
