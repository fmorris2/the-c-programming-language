#include <stdio.h>
#include <stdbool.h>

/*
*	Exercise 1-18
*		Write a program to remove trailing blanks and
*		tabs from each line of input, and to delete
*		entirely blank lines.
*
*	Personal Note:
*		It doesn't seem like taking a purely  "streaming" approach
*		will work with this one. The only way to know if spaces
*		and tabs are trailing is if you've reached the end of
*		the line (new line or EOF). Therefore, if there are
*		a very large number of tabs / spaces at the end of a
*		line, you would need to store them, in order, until
*		the end of the line.
*
*		This would be trivial  with a dynamically-sized data structure,
*		but at this point in the book, they haven't talked about one.
*
*		To stay true with what we've learned thus far, I'm going to impose
*		a constraint on the problem. We will assume that, if there are
*		> MAX_TRAILING_SPACE characters at the end of a string, that the
*		rest will be trailing and we'll ignore everything else until the line
*		ends.
*/

#define MAX_TRAILING_SPACE 100 //max whitespace characters before we ignore the rest of the line

bool isWhitespaceChar(char c);

int main() {
	
	char lineCache[MAX_TRAILING_SPACE]; //cache for whitespace characters
	int numWhitespace = 0;	

	char c;
	while((c = getchar()) != EOF) {
		if(c == '\n') {
			numWhitespace = 0;
			putchar(c);
		} else if(isWhitespaceChar(c)) {
			lineCache[numWhitespace++] = c;
		} else {
			if(numWhitespace > 0) {
				int i;
				for(i = 0; i < numWhitespace; i++) {
					putchar(lineCache[i]);
				}
				numWhitespace = 0;
			}
			putchar(c);
		}
	}	
	return 0;
}

bool isWhitespaceChar(char c) {
	return c == '\t' || c == ' ';
}
