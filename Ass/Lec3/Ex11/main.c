/*
 * main.c
 *
 *  Created on: Mar 27, 2024
 *      Author: oussama
 */

#include<stdio.h>

int main()

{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float x;

	printf("Enter a number: \n");
	scanf("%f",&x);

	if(x>=0)
	{
		printf("%.2f is positive\n",x);
	}
	else
	{
		printf("%.2f is negative\n",x);
	}
}

