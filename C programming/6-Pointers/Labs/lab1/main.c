/*
 * main.c
 *
 *  Created on: Oct 20, 2024
 *      Author: oussa
 */


#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int sum=0;
	int x[5];
	int*x_ptr = x;
	printf("Enter the weights:\n");

	for(int i=0;i<5;i++)
	{
		scanf("%d",x_ptr++);
	}

	printf("the weights entered are:\n");

	x_ptr=x;
	for(int i=0;i<5;i++)
	{
		printf("%d\n",*x_ptr++);//x_ptr++=x_ptr+1(*4)
	}

	x_ptr=x;
	for(int i=0;i<5;i++)
	{
		sum+=*x_ptr++;
	}
	printf("the sum is:%d\n",sum);
}



