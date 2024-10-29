/*
 * main.c
 *
 *  Created on: Mar 17, 2024
 *      Author: oussama
 */

// a code that order 3 given numbers using if, if else functions
#include <stdio.h>

int x;
int y;
int z;

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);//to clean the buffer of printf function
	printf("Enter 3 values:\r\n\n\n");
	scanf("%i %i %i",&x, &y, &z);

	if(x > y && x > z)
	{
		printf("The largest value is %i \n", x);
	}
	else if (y > x && y > z)
	{
		printf("The largest value is %i \n", y);

	}
	else if (z > x && z > y)
	{
		printf("The largest value is %i \n", x);

	}
}

