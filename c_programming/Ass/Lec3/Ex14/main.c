/*
 * main.c
 *
 *  Created on: Mar 28, 2024
 *      Author: oussama
 */
#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int x;
	int i;
	unsigned long int fact=1;
	printf("Enter an integer:\n");
	scanf("%d",&x);


	if(x > 0)
	{
		for(i=1;i<(x+1);i++)
	{
		fact*=i;
	}
		printf("Factorial: %ld",fact);
	}

	else
	{
		printf("ERROR!!! Factorial of negative number doesn't exist");
	}
}

