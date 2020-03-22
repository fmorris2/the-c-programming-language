#include <stdio.h>

/*
* Exercise 1-9
*	Write a program to copy its input to its output, replacing
*	each string of one or more blanks by a single blank.
*/
#define BLANK ' '
main() {
	int previousChar = EOF;
	int currentChar;
	while((currentChar = getchar()) != EOF) {
		if(currentChar != BLANK || previousChar != BLANK) {
			putchar(currentChar);
			previousChar = currentChar;
		}
	}	
}
