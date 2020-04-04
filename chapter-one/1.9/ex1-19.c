#include <stdio.h>

/*
*	Exercise 1-19
*		Write a function reverse(s) that reverses the
*		character string s. Use it to write a program
*		that reverses its input a line at a time.
*/

#define MAX_LINE_LENGTH 1000

int getLine();
void reverse(char* str, int len);

int main() {
	char line[MAX_LINE_LENGTH];
	int lineLength;
	int i;

	while((lineLength = getLine(line)) > 0) {
		reverse(line, lineLength);
		for(i = 0; i < lineLength; i++) {
			putchar(line[i]);
		}
		putchar('\n');
	}
					
	return 0;
}

/*
* Grab the next full line from the input,
* and store it in the provided character array.
*
* Return the length of the line.
*/
int getLine(char* line) {
	int c;
	int i = 0;
	while((c = getchar()) != EOF && c != '\n' && i < MAX_LINE_LENGTH) {
		line[i++] = c;
	}
	
	return i;	
}

/*
* Reverse the string in-place.
*/
void reverse(char* str, int len) {
	int midPoint = len % 2 == 0 ? len / 2 : (len / 2) + 1;
	int backIndex;
	for(backIndex = len; backIndex > midPoint; backIndex--) {
		int frontIndex = len - backIndex;
		int temp = str[frontIndex];
		str[frontIndex] = str[backIndex - 1];
		str[backIndex - 1] = temp;		
	}
}
