/*
 * main.c
 *
 *  Created on: Mar 27, 2024
 *      Author: oussama
 */
#include<stdio.h>


int main()
{
	int x;


	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("Enter the number you want to check: \n");
	scanf("%d",&x);

	if((x % 2)==0)
	{
		printf("%d is even",x);
	}
	else
	{
		printf("%d is odd",x);
	}

}

