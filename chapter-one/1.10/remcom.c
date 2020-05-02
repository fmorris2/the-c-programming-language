#include <stdio.h>

/*
*	Exercise 1-23
*		Write a program to remove all comments from a C program.
*		Don't forget to handle quoted strings and character constants
*		properly. C comments do not nest.
*
*	Private Note
*		C comments can be a single line (//) or multi line block (/ *).
*	 	We know if a comment is starting if the following holds true:
*			We are not in a string literal
*			We are not already in a comment
*/

void handleSingleLineComment();
void handleMultiLineComment();
void handleString();

int c;
int lc = '\0'; //last character
int main() {
	while((c = getchar()) != EOF) {
		if(c == '/') {
			if((c = getchar()) == '/') {
				handleSingleLineComment();
			} else if(c == '*') {
				handleMultiLineComment();
			} else {
				putchar('/');
				putchar(c);
			}
		} else if(c == '"' && lc != '\'') {
			handleString();
		} else {
			putchar(c);
		}
		
		lc = c;
	}
	
	return 0;
}

void handleSingleLineComment() {
	while((c = getchar()) != '\n') {
		//ignore everything
	}
	putchar(c); 
}

void handleMultiLineComment() {
	lc = '\0';
	while((c = getchar()) != '/' || lc != '*') {
		lc = c;
	}
	if((c = getchar()) != '\n') {
		putchar(c);
	}
}

void handleString() {
	putchar(c); //initial quote
	lc = c;
	while((c = getchar()) != '"' || lc == '\\') {
		putchar(c);
		lc = c;
	}
	putchar(c); //ending quote
}
