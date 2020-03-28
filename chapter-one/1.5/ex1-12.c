#include <stdio.h>
#include <stdbool.h>

/*
*	Exercise 1-12
*		Write a program that prints its input one word per line.
*
*/

main() {
	bool isInWord = false;
	int c;
	while((c = getchar()) != EOF) {
		if(c == '\t' || c == '\n' || c == ' ') {
			if(isInWord) {
				printf("\n");
				isInWord = false;
			}
		} else {
			putchar(c);
			isInWord = true;
		}		
	}
}

