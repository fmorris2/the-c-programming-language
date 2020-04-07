#include <stdio.h>

/*
*	Exercise 1-21
*		Write a program "entab" that replaces strings of blanks by
*		the minimum number of tabs and blanks to achieve the same
*		spacing. Use the same tab stops as for "detab". When either
*		a tab or a single blank would suffice to reach a tab stop,
*		which should be given preference?
*
*	Personal Note
*		When either a tab or a single blank would suffice to reach
*		a tab stop, a tab should be given preference. The reason for
*		this is so that the code remains consistent in intent. We're
*		"encoding" the input with tabs, so we should remain consistent
*		in that mission.
*/

#define DEFAULT_TAB_STOP_LENGTH 8

int main() {
	
	const int tsLen = DEFAULT_TAB_STOP_LENGTH;

	int c;
	int col = 0;
	int spaces = 0;

	while((c = getchar()) != EOF) {
		
		if(col % tsLen == 0) { //at tab stop
			for(; spaces > 0; spaces -= tsLen) {
				putchar('\t');
			}
			spaces = 0;
		}

		if(c == '\t') {
			putchar('\t');
			spaces = 0;
			col += tsLen - (col % tsLen); //advance col to next tab stop
		} else if(c == ' ') {
			spaces++;
			col++;
		} else { //neither tab nor space
			for(; spaces > 0; spaces--) {
				putchar(' ');
			}
			putchar(c);
			col = c == '\n' ? 0 : col + 1;
		}
		
	}
		
	return 0;
}
