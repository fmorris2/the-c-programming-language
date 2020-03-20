#include <stdio.h>

/*
* Exercise 1-8
*	Write a program to count blanks, tabs, and newlines.
*
*/
main() {
	
	int blanks = 0;
	int tabs = 0;
	int newLines = 0;
	int currentChar;

	while((currentChar = getchar()) != EOF) {
		switch(currentChar) {
			case ' ':
				blanks++;
			break;
			case '\t':
				tabs++;
			break;
			case '\n':
				newLines++;
			break;
		}
	}

	printf("Blanks: %d\n", blanks);
	printf("Tabs: %d\n", tabs);
	printf("New Lines: %d\n", newLines);	
}
