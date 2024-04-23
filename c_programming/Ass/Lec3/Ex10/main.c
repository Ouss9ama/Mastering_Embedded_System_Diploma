/*
 * main.c
 *
 *  Created on: Mar 27, 2024
 *      Author: oussama
 */

#include<stdio.h>

int main()
{
	float x;
	float y;
	float z;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter 3 numbers:\n");
	scanf("%f %f %f", &x, &y, &z);
	if((x > y)&&(x > z))
	{
		printf("Largest number = %.2f \n",x);
	}
	else if ((y > x)&&(y > z))
			{
		printf("Largest number = %.2f \n",y);
			}
	else
	{
		printf("Largest number = %.2f \n",z);
	}
}
