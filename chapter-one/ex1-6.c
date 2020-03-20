#include <stdio.h>

/*
* Exercise 1-6
*	Verify that the expression getchar() != EOF is 0 or 1.
*/

main() {
	printf("NOT EOF: %d\n", 'A' != EOF);
	printf("EOF: %d\n", EOF != EOF);	
	printf("getchar() != EOF: %d\n", getchar() != EOF);
}
