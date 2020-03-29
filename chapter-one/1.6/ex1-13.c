#include <stdio.h>
#include <stdlib.h>

/*
*	Exercise 1-13
*		Write a program to print a histogram of the lengths
*		of words in its input. It is easy to draw the histogram with
*		the bars horizontal; a vertical orientation is more challenging.
*/

#define MAX_WORD_LENGTH 10

main() {
	int lengths[MAX_WORD_LENGTH]; //lengths[i - 1] = # occurences of word length i
	int c;
	int currentWordLength = 0;
	int maxFrequency = 0;

	//calculate & store word lengths from input
	while((c = getchar()) != EOF) {
		if((currentWordLength > 0) && (c == '\t' || c == '\n' || c == ' ')) {
			currentWordLength = min(MAX_WORD_LENGTH, currentWordLength);
			lengths[currentWordLength - 1]++;
			maxFrequency = max(maxFrequency, lengths[currentWordLength]);
			currentWordLength = 0; 
		} else {
			currentWordLength++;
		}
	}

	//print vertical histogram
	//start from top row to bottom, and fill in columns w/ value >= row
	for(int row = maxFrequency; row > 0; row--) {
		for(int col = 0; col < MAX_WORD_LENGTH; col++) {
			if(lengths[col] >= row) {
				printf("*");
			}
			printf(" ");
		} 
	} 		
}
