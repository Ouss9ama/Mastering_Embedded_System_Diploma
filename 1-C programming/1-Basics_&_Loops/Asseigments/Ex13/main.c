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
	int sum=0;
	printf("Enter a number:\n");
	scanf("%d",&x);

	for(i=0;i<(x+1);i++)
	{
		sum+=i;
	}
	printf("sum is %d",sum);
}
