#include <stdio.h>

/*
*	Exercise 1-14
*		Write a program to print a histogram of the frequencies
*		of different characters in its input.
*
*	Personal Note
*		The ANSI character set includes the standard ASCII character set
*		(values 0 to 127), plus an extended character set (values 128 to 255).
*		Source: http://ascii-table.com/ansi-codes.php 
*/

#define CHARSET_SIZE 256

main() {

	int frequencies[CHARSET_SIZE]; //index: character code. value: frequency	
	int i;
	
	for(i = 0; i < CHARSET_SIZE; i++) { //initialize frequencies to 0
		frequencies[i] = 0;
	}

	//compute frequencies
	int maxFreq = 0;
	int c;
	while((c = getchar()) != EOF) {
		frequencies[c]++;
		if(frequencies[c] > maxFreq) {
			maxFreq = frequencies[c];		
		}
	}
	
	//draw histogram
	int row, col;
	for(row = maxFreq; row > 0; row--) {
		for(col = 0; col < CHARSET_SIZE; col++) {
			if(frequencies[col] >= row) {
				printf("*\t");					
			} else if(frequencies[col] > 0) {
				printf("\t");
			}
		}
		printf("\n");	
	}

	//column labels
	for(i = 0; i < CHARSET_SIZE; i++) {
		if(frequencies[i] > 0) {
			if(i == '\n') {
				printf("\\n\t");
			} else if(i == '\t') {
				printf("\\t\t");
			} else if(i == ' ') {
				printf("' '\t");
			} else {
				printf("%c\t", i);
			}			
		}
	}
	
	printf("\n");
}
