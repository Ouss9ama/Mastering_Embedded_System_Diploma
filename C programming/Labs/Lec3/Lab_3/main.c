/*
 * main.c
 *
 *  Created on: Mar 20, 2024
 *      Author: oussama
 */
// a code that give the minimum of 2 given values

#include <stdio.h>


int main()
{
	int x;
	int y;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
     printf("Enter first number\r\n");
     scanf("%i", &x);
     printf("Enter second number\r\n");
     scanf("%i", &y);

     printf("the minimum value is %i ", (x > y)?x:y);

}
