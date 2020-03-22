#include <stdio.h>

/*
* Exercise 1-11
*	How would you test the word count program (below)? What kinds of input are
* 	most likely to uncover bugs if there are any?
*
*	My answer:
*		I would test the word count program by piping a file as the stream of input.
*		
*		Input that would be most likely to uncover bugs, is any input that may lie near the boundaries of the expected input domain. For example:
*			-Empty file
*			-File consisting exclusively of new lines
*			-File consisting exclusively of tabs
*/

#define IN  1 	/* inside a word */
#define OUT 0	/* outside a word */

/* count lines, words, and characters in input */
main() {
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF) {
		++nc;
		if(c == '\n') {
			++nl;
		}

		if(c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		} else if(state == OUT) {
			state = IN;
			++nw;	
		}
	}

	printf("%d %d %d\n", nl, nw, nc);
}
