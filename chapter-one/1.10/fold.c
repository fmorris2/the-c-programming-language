#include <stdio.h>

/*
*	Exercise 1-22
*		Write a program to "fold" long input lines into two
*		or more shorter lines after the last non-blank character
*		that occurs before the n-th column of input. Make sure your
*		program does something intelligent with very long lines, and
*		if there are no blanks or tabs before the specified column.
*/
   	
#define COLUMN_THRESHOLD 40 //threshold to fold lines
#define TS_LEN 8

int main() {
	const int colThresh = COLUMN_THRESHOLD;
	
	int c;
	int col = 0;
	while((c = getchar()) != EOF) {
		if(col < colThresh) {
			if(c == '\t') {
				int lenToNextTs = TS_LEN - (col % TS_LEN);
				if(col + lenToNextTs >= colThresh) {
					putchar('\n');
					putchar('\t');
					col = TS_LEN;
				} else {
					putchar('\t');
					col += lenToNextTs;
				} 
			} else if(c == '\n') {
				putchar(c);
				col = 0;
			} else {	
				putchar(c);
				col++;
			}
		} else { //we're at the threshold
			putchar('\n');
			col = 0;
			if(c != '\n') {
				putchar(c);
				col++;
			}
		}
	}	

	return 0;
}
