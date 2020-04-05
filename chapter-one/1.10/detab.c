#include <stdio.h>

/*
*	Exercise 1-20
*		Write a program 'detab' that replaces tabs in the
*		input with the proper number of blanks to space
*		to the next tab stop. Assume a fixed set of tab
*		stops, say every "n" columns. Should n be a variable
*		or a symbolic parameter?
*
*	Personal Note:
*		Tab stops should be a parameter used in the "detab" method.
*		This allows flexibility, as a user inevitably will want to
*		configure the tab stops to be a different length.
*/

#define DEFAULT_TAB_STOP_LENGTH 8

/*
* detab - Sends the appropriate number of spaces
* to the output, given the current column and the
* desired tab stop length.
*
* Returns an integer representing the new current
* column number, after the spaces were sent to the
* output.
*/
int detab(int col, int tsLen);

int main() {

	int c;
	int col = 0;
	while((c = getchar()) != EOF) {
		if(c == '\n') {
			col = 0;
			putchar(c);
		} else if(c == '\t') {
			col = detab(col, DEFAULT_TAB_STOP_LENGTH);
		} else {
			putchar(c);
			col++;
		}
	}	

	return 0;
}

int detab(int col, int tsLen) {
	const int lenToNextTs = col < tsLen ? tsLen - col : tsLen - (col % tsLen);
	int i;
	for(i = 0; i < lenToNextTs; i++) {
		putchar(' ');
	}

	return col += lenToNextTs;	
}
