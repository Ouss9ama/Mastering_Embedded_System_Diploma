/*
 * main.c
 *
 *  Created on: Mar 26, 2024
 *      Author: oussama
 */


#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float x;
	float y;
	float z;
	printf("Enter the value of x:\n");
	scanf("%f",&x);

	printf("Enter the value of y:\n");
	scanf("%f",&y);
	z=x;
	x=y;
	y=z;

	printf(" x=%f\n y=%f\n",x ,y);



}
