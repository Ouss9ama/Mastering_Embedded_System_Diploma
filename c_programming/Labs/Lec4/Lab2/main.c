/*
 * main.c
 *
 *  Created on: Apr 19, 2024
 *      Author: oussama
 */
//calculate an equation

#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float x[5];
	float y[5];
	int i;
	for(i=0;i<5;i++)
	{
		printf("enter %d value:\n",i+1);
		scanf("%f",&x[i]);
	}

	for(i=0;i<5;i++)
	{
		y[i]= 5*x[i]*x[i]+3*x[i]+2;
		printf("y(%.2f)=%.2f\n",x[i],y[i]);
	}

}
