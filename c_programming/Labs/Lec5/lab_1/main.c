/*
 * main.c
 *
 *  Created on: May 22, 2024
 *      Author: oussama
 */

#include<stdio.h>
int factorial(int x);
int main()
{
	int x;

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter the number: \n");
	scanf("%d",&x);
	factorial (x);

	printf("factorial(%d)=%d\n",x,factorial(x));

	return 0;

}

int factorial(int x)
{
	int i;
	int counter = 1;
	for(i=x;i>0;i--)
	{
		counter=counter*i;
	}
	return counter;
}
