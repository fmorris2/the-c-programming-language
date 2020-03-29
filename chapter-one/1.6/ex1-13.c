#include <stdio.h>

/*
*	Exercise 1-13
*		Write a program to print a histogram of the lengths
*		of words in its input. It is easy to draw the histogram with
*		the bars horizontal; a vertical orientation is more challenging.
*/

#define MAX_WORD_LENGTH 10

int min(int a, int b) {
	return a <= b ? a : b;
}

int max(int a, int b) {
	return a >= b ? a : b;
}

main() {
	int lengths[MAX_WORD_LENGTH]; //lengths[i - 1] = # occurences of word length i
	int c;
	int currentWordLength = 0;
	int maxFrequency = 0;

	//set initial values of arr to 0
	int index;
	for(index = 0; index < MAX_WORD_LENGTH; index++) {
		lengths[index] = 0;
	}	

	//calculate & store word lengths from input
	while((c = getchar()) != EOF) {
		if(c == '\t' || c == '\n' || c == ' ') {
			if(currentWordLength > 0) {
				currentWordLength = min(MAX_WORD_LENGTH, currentWordLength);
				lengths[currentWordLength - 1]++;
				maxFrequency = max(maxFrequency, lengths[currentWordLength - 1]);
				currentWordLength = 0;
			}
		} else {
			currentWordLength++;
		}
	}

	//print vertical histogram
	//start from top row to bottom, and fill in columns w/ value >= row
	int row, col;
	for(row = maxFrequency; row > 0; row--) {
		for(col = 0; col < MAX_WORD_LENGTH; col++) {
			if(lengths[col] >= row) {
				printf("*");
			}
			printf("\t");
		}
		printf("\n");
	}

	//column labels
	for(col = 1; col <= MAX_WORD_LENGTH; col++) {
		printf("%d\t", col);
	}	

	printf("\n");
}
