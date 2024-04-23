/*
 * Lab_1.c
 *
 *  Created on: Mar 17, 2024
 *      Author: oussama
 */
// a code that calculate the radius or circumference
#include <stdio.h>
#include <math.h>
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

	if (character=='a')

	{
		area= radius*radius*3.1415926;
		printf("the area is:\r\n %f", area);

	}

	else if (character=='c')
	{
		circum= 2*radius*3.1415926;
		printf("the area is:\r\n %f", circum);

	}
	else
	{
		printf(" wrong character\r\n");
	}


}
