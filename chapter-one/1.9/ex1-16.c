#include <stdio.h>

/*
*	Exercise 1-16
*		Revise the main routine of the longest-line program so
*		it will correctly print the length of arbitrarily long
*		input lines, and as much as possible of the text.
*/

#define MAXLINE 10 //maximum input line size

int getAndStoreLine(char line[], int maxline);
void copy(char to[], char from[]);

//print the longest input line
int main() {
	int len; //current line length
	int max; //maximum length seen so far
	char line[MAXLINE]; //current input line
	char longest[MAXLINE]; //longest line saved here

	max = 0;
	while((len = getAndStoreLine(line, MAXLINE)) > 0) {
		if(len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if(max > 0) { //there was a line
		printf("Actual length: %d, As much of text: %s", max,longest);
	}

	return 0;
}

//getAndStoreLine: read a line into s, return length
int getAndStoreLine(char s[], int lim) {
	int c, boundedIndex, unboundedIndex;
	
	for(boundedIndex = unboundedIndex = 0; (c = getchar()) != EOF && c != '\n'; unboundedIndex++) {
		if(boundedIndex < lim - 1) {
			s[boundedIndex] = c;
			boundedIndex++;
		}
	}
	
	if(c == '\n' && boundedIndex <= lim - 1) {
		s[boundedIndex] = c;
		boundedIndex++;
	}

	s[boundedIndex] = '\0';
	return unboundedIndex;
}

//copy: copy 'from' into 'to': assume to is big enough
void copy(char to[], char from[]) {
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0') {
		i++;
	}
}
