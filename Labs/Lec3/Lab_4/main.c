/*
 * main.c
 *
 *  Created on: Mar 20, 2024
 *      Author: oussama
 */
#include <stdio.h>
//float pi=3.1415926;
float radius;
float circum;
float area;
char character;

int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("Enter the Radius \r\n");

	scanf("%f", &radius);


	printf("Enter your choice (\"a\" to print area or \"c\" to print circumference: )\n ");

	scanf("%c", &character);

	switch (character)
	{
	case 'a':
	case 'A':// putting 2 cases directly means OR choice to execute the following instruction
	{
		area= radius*radius*3.1415926;
		printf("the area is:\r\n %f", area);
	}
	break;

	case 'c':
	case 'C':
	{
		circum= 2*radius*3.1415926;
		printf("the area is:\r\n %f", circum);

	}
	break;

	default:
	{
		printf(" wrong character\r\n");
	}
	}

}

