/*
 * main.c
 *
 *  Created on: Mar 25, 2024
 *      Author: oussama
 */
//Write C Program to Multiply two Floating Point Numbers
#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float x;
	float y;

	printf("Write two numbers:\r\n");
	scanf("%f %f",&x, &y);

	printf("Product: %f \r\n", x*y);


}
