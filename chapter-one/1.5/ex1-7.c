#include <stdio.h>

/*
* Exercise 1-7
*	Write a program to print the value of EOF.
* 	
*	Personal Note:
*		EOF is a constant defined in stdio.h and is not guaranteed
*		to be the same value across platforms. EOF is simply an integer
*		that is guaranteed not to be the same as any character value.
*/
main() {
	printf("EOF: %d\n", EOF);
}
